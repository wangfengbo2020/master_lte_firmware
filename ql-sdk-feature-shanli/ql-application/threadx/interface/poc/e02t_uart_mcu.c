#include "e02t_uart_mcu.h"

#include <stdlib.h>
#include <string.h>

#include "broad.h"
#include "ql_audio.h"
#include "ql_rtos.h"
#include "ql_uart.h"
#include "sl_log.h"
#include "tts_gbk.h"

// 引入 POC 主任务的事件标志和状态（由 example_poc.c 定义）
// 这样我们从串口解析出指令后，就能直接发 Flag 触发对讲
extern ql_flag_t ptt_key_event_flag;
extern volatile int g_login_ok;
extern volatile int g_in_group;
extern volatile bnd_gid_t g_current_gid;
extern char g_poc_account[]; // IMEI string (15 digits)
extern int change_group(void);

// =========================================================
// 宏定义与数据结构 (RingBuffer + 接收队列)
// =========================================================
#define UART_RX_QUEUE_SIZE 20
#define UART_RX_MAX_SIZE 60

// 消息队列实体
static ql_queue_t uart_rx_queue = NULL;
static e02t_uart_line_handler_t g_line_handler = NULL;
static volatile int g_mcu_uart_ready = 0;

// =========================================================
// 同步查询机制 (供 e02t_uart_query_mcu 使用)
// =========================================================
#define MCU_SYNC_BUF_SIZE 64
#define MCU_SYNC_TIMEOUT_MS 2000
static char g_sync_rx_buf[MCU_SYNC_BUF_SIZE];
static volatile int g_sync_rx_len = 0;
static volatile int g_sync_waiting = 0;

// =========================================================
// 异步电量查询 (供 e02t_uart_query_battery_async 使用)
// 主任务只负责发起，解析线程匹配 +SOC 回复后缓存结果
// =========================================================
static volatile int g_battery_value = -1; // 最近一次有效电量 1~100, -1 无

// =========================================================
// BLE 群组功能：异步状态 & 定时器
// =========================================================
#if E02T_BLE_GROUP_ENABLE
#define BLE_TERMINAL_NAME "E02T0001"
#define BLE_COMPANY_ID_H 0x0A
#define BLE_COMPANY_ID_L 0x0B
#define BLE_GROUP_TIMEOUT_MS 10000

static volatile int g_addgroup_pending = 0;
static volatile int g_joingroup_pending = 0;
static volatile int g_invite_code_pending = 0;

// 自动切组：发起进组请求前的群组列表快照
// 固定数组而非 malloc，避免 listupdate/HTTP 回调与串口线程之间的指针生命周期问题
#define AUTO_JOIN_SNAPSHOT_MAX 32
static unsigned int g_auto_join_snapshot[AUTO_JOIN_SNAPSHOT_MAX];
static unsigned int g_auto_join_snapshot_size = 0;
static volatile int g_auto_join_armed = 0;
static unsigned int g_auto_join_done_gid = 0; // 最近一次自动切入的 gid（防重复进组）
static ql_timer_t g_addgroup_timer = NULL;
static ql_timer_t g_joingroup_timer = NULL;
static int g_addgroup_gid = 0;
#endif /* E02T_BLE_GROUP_ENABLE */

typedef struct
{
    char data[UART_RX_MAX_SIZE];
    int len;
} uart_rx_msg_t;

// =========================================================
// 1. 底层：硬件中断回调 (只做搬运，绝不解析)
// =========================================================
static void quec_uart_mcu_callback(QL_UART_PORT_NUMBER_E port, void *para)
{
    uart_rx_msg_t msg;
    memset(&msg, 0, sizeof(msg));

    // 一口气把串口堆积的数据读出来
    msg.len = ql_uart_read(port, msg.data, sizeof(msg.data) - 1);

    // 将数据压入消息队列，通知解析线程（非阻塞发送）
    if (msg.len > 0 && uart_rx_queue != NULL)
    {
        // 如果队列满，丢弃旧数据，优先保证系统不卡死
        ql_rtos_queue_release(uart_rx_queue, sizeof(msg), (u8 *)&msg, QL_NO_WAIT);
    }
}

// =========================================================
// BLE 协议组包 (PocStar Sport 私有协议)
// =========================================================
#if E02T_BLE_GROUP_ENABLE
static void imei_to_bcd(const char *imei, unsigned char *bcd, int bcd_len)
{
    int i;
    int imei_len = strlen(imei);
    int total_digits = bcd_len * 2;
    int pad_count = total_digits - imei_len;

    memset(bcd, 0x00, bcd_len);
    if (pad_count < 0)
        pad_count = 0;

    for (i = 0; i < total_digits && (i / 2) < bcd_len; i++)
    {
        unsigned char digit;
        if (i < pad_count)
        {
            digit = 0;
        }
        else
        {
            digit = imei[i - pad_count] - '0';
        }
        if (i % 2 == 0)
        {
            bcd[i / 2] = (digit << 4);
        }
        else
        {
            bcd[i / 2] |= digit;
        }
    }
}

static void bytes_to_hex(const unsigned char *src, int src_len, char *hex_out)
{
    int i;
    for (i = 0; i < src_len; i++)
    {
        sprintf(hex_out + i * 2, "%02X", src[i]);
    }
    hex_out[src_len * 2] = '\0';
}

static int e02t_make_ble_protocol(const char *imei, int func_type, const char *token, char *hex_out)
{
    unsigned char buf[32];
    int idx = 0;
    int total_len;

    if (imei == NULL || strlen(imei) < 15)
    {
        return -1;
    }

    if (func_type == 0x01)
    {
        total_len = 22;
        buf[idx++] = 0x15;
    }
    else if (func_type == 0x02)
    {
        if (token == NULL || strlen(token) < 6)
        {
            return -1;
        }
        total_len = 28;
        buf[idx++] = 0x1B;
    }
    else
    {
        return -1;
    }

    buf[idx++] = BLE_COMPANY_ID_H;
    buf[idx++] = BLE_COMPANY_ID_L;

    buf[idx++] = 0x08;
    memcpy(buf + idx, BLE_TERMINAL_NAME, 8);
    idx += 8;

    buf[idx++] = 0x08;
    imei_to_bcd(imei, buf + idx, 8);
    idx += 8;

    buf[idx++] = (unsigned char)func_type;

    if (func_type == 0x02)
    {
        memcpy(buf + idx, token, 6);
        idx += 6;
    }

    bytes_to_hex(buf, total_len, hex_out);
    return total_len;
}

// =========================================================
// BLE 群组超时定时器回调
// =========================================================
static void addgroup_timeout_cb(u32 arg)
{
    printf("[BLE] addgroup_timeout_cb fired, pending=%d invite_pending=%d\r\n",
           g_addgroup_pending, g_invite_code_pending);
    if (g_addgroup_pending || g_invite_code_pending)
    {
        g_addgroup_pending = 0;
        g_invite_code_pending = 0;
        e02t_auto_join_disarm(); // 建群超时放弃自动切组（未 arm 时无副作用）
        printf("[BLE] ADDGROUP timeout, sending ERR\r\n");
        e02t_uart_send_to_mcu("+ADDGROUP_ERR:TIMEOUT\r\n");
    }
}

static void joingroup_timeout_cb(u32 arg)
{
    printf("[BLE] joingroup_timeout_cb fired, pending=%d\r\n", g_joingroup_pending);
    if (g_joingroup_pending)
    {
        g_joingroup_pending = 0;
        e02t_auto_join_disarm(); // 超时放弃自动切组
        printf("[BLE] JOINGROUP timeout, sending ERR\r\n");
        e02t_uart_send_to_mcu("+JOINGROUP_ERR:TIMEOUT\r\n");
    }
}
#endif /* E02T_BLE_GROUP_ENABLE */

// =========================================================
// 2. 解析层：AT 指令字符串解析业务
// =========================================================
static void e02t_parse_at_command(const char *cmd_line)
{
    if (g_line_handler != NULL && g_line_handler(cmd_line))
    {
        return;
    }

    // 电量查询回复：+SOC:xx —— 只匹配这一种，缓存到异步变量
    if (strstr(cmd_line, "+SOC") != NULL)
    {
        char *colon = strchr(cmd_line, ':');
        int bat = (colon != NULL) ? atoi(colon + 1) : -1;
        if (bat < 1)
            bat = 1;
        if (bat > 100)
            bat = 100;
        g_battery_value = bat;
        SL_LOG("BAT", "parsed battery=%d (raw='%s')", bat, colon ? colon + 1 : "");

        // 若同步查询(AT+SOC)正在等待，也把原始行喂给 sync buf
        if (g_sync_waiting && g_sync_rx_len == 0)
        {
            int len = strlen(cmd_line);
            if (len >= MCU_SYNC_BUF_SIZE)
                len = MCU_SYNC_BUF_SIZE - 1;
            memcpy(g_sync_rx_buf, cmd_line, len);
            g_sync_rx_buf[len] = '\0';
            g_sync_rx_len = len;
        }
        return;
    }

    if (g_sync_waiting && g_sync_rx_len == 0)
    {
        int len = strlen(cmd_line);
        if (len >= MCU_SYNC_BUF_SIZE)
            len = MCU_SYNC_BUF_SIZE - 1;
        memcpy(g_sync_rx_buf, cmd_line, len);
        g_sync_rx_buf[len] = '\0';
        g_sync_rx_len = len;
        return;
    }

    // 调试打印：显示收到的完整指令
    SL_LOG("UART", "Parsing CMD: %s", cmd_line);

    // 防抖状态时间戳 (1 tick = 5ms，见 kernel TICK_PER_MS 定义)
    // PRESS 和 RELEASE 各自独立防抖，避免快速 1→0→1 时第二个 PRESS 被误吞
    static u32 last_ptt_press_tick = 0;
    static u32 last_ptt_release_tick = 0;
    static u32 last_vol_tick = 0;
    u32 current_tick = ql_rtos_get_systicks();

#define DEBOUNCE_MS 150
#define MS_PER_TICK 5
#define DEBOUNCE_TICKS (DEBOUNCE_MS / MS_PER_TICK) // 30 ticks = 150ms

    // [1] 处理 PTT 按下：AT+PTT=1
    if (strstr(cmd_line, "AT+PTT=1") != NULL)
    {
        if (current_tick - last_ptt_press_tick < DEBOUNCE_TICKS)
        {
            SL_LOG("UART", "PTT=1 ignored (debouncing)");

            return;
        }
        last_ptt_press_tick = current_tick;

        if (!g_login_ok || !g_in_group)
        {
            SL_LOG("UART", "PTT=1 ignored (not logged in or not in group)");
            e02t_uart_send_to_mcu("+URC: PTT,NOT_READY\r\n");
            return;
        }

        SL_LOG("UART", "AT+PTT=1 -> PRESS Flag sent");
        if (ptt_key_event_flag)
        {
            ql_rtos_flag_release(ptt_key_event_flag, QL_PTTKEY_PRESS_FLAG, QL_FLAG_OR);
            e02t_uart_send_to_mcu("+URC: PTT,PRESS_OK\r\n");
        }
    }
    // [2] 处理 PTT 松开：AT+PTT=0
    else if (strstr(cmd_line, "AT+PTT=0") != NULL)
    {
        if (current_tick - last_ptt_release_tick < DEBOUNCE_TICKS)
        {
            SL_LOG("UART", "PTT=0 ignored (debouncing)");
            return;
        }
        last_ptt_release_tick = current_tick;

        SL_LOG("UART", "AT+PTT=0 -> RELEASE Flag sent");
        if (ptt_key_event_flag)
        {
            ql_rtos_flag_release(ptt_key_event_flag, QL_PTTKEY_RELEASE_FLAG, QL_FLAG_OR);
            e02t_uart_send_to_mcu("+URC: PTT,RELEASE_OK\r\n");
        }
    }
    // [3] 处理音量增加：AT+VOL=UP
    else if (strstr(cmd_line, "AT+VOL=UP") != NULL)
    {
        if (current_tick - last_vol_tick < DEBOUNCE_TICKS)
        {
            SL_LOG("UART", "VOL=UP ignored (debouncing)");
            return;
        }
        last_vol_tick = current_tick;

        SL_LOG("UART", "AT+VOL=UP");
        int current_vol = ql_get_volume();
        if (current_vol < AUDIOHAL_SPK_VOL_11)
        {
            current_vol++;
            ql_set_volume((AUDIOHAL_SPK_LEVEL_T)current_vol);
        }
        char rsp[64];
        snprintf(rsp, sizeof(rsp), "+URC: VOL,%d\r\n", current_vol);
        e02t_uart_send_to_mcu(rsp);
    }
    // [4] 处理音量减少：AT+VOL=DOWN
    else if (strstr(cmd_line, "AT+VOL=DOWN") != NULL)
    {
        if (current_tick - last_vol_tick < DEBOUNCE_TICKS)
        {
            SL_LOG("UART", "VOL=DOWN ignored (debouncing)");
            return;
        }
        last_vol_tick = current_tick;

        SL_LOG("UART", "AT+VOL=DOWN");
        int current_vol = ql_get_volume();
        if (current_vol > AUDIOHAL_SPK_MUTE)
        {
            current_vol--;
            ql_set_volume((AUDIOHAL_SPK_LEVEL_T)current_vol);
        }
        char rsp[64];
        snprintf(rsp, sizeof(rsp), "+URC: VOL,%d\r\n", current_vol);
        e02t_uart_send_to_mcu(rsp);
    }
    else if (strstr(cmd_line, "AT+NOISE=1") != NULL)
    {
        int vol_noise = 1;
        char rsp[64];
        ql_set_denoise_flag(1);
        SL_LOG("UART", "AT+NOISE=1");
        snprintf(rsp, sizeof(rsp), "+URC: NOISE,%d\r\n", vol_noise);
        e02t_uart_send_to_mcu(rsp);
    }
    else if (strstr(cmd_line, "AT+NOISE=0") != NULL)
    {
        int vol_noise = 0;
        char rsp[64];
        ql_set_denoise_flag(0);
        SL_LOG("UART", "AT+NOISE=0");
        snprintf(rsp, sizeof(rsp), "+URC: NOISE,%d\r\n", vol_noise);
        e02t_uart_send_to_mcu(rsp);
    }
#if E02T_BLE_GROUP_ENABLE
    // [7] BLE 绑定广播数据生成：AT+BIND
    else if (strstr(cmd_line, "AT+BIND") != NULL)
    {
        printf("[BLE] AT+BIND received, g_login_ok=%d, imei=%s\r\n", g_login_ok, g_poc_account);
        if (!g_login_ok)
        {
            printf("[BLE] BIND rejected: not logged in\r\n");
            e02t_uart_send_to_mcu("+BIND_ERR:NOT_LOGIN\r\n");
            return;
        }
        char hex_buf[64];
        int ret = e02t_make_ble_protocol(g_poc_account, 0x01, NULL, hex_buf);
        printf("[BLE] BIND make_protocol ret=%d\r\n", ret);
        if (ret < 0)
        {
            printf("[BLE] BIND pack failed, imei len=%d\r\n", (int)strlen(g_poc_account));
            e02t_uart_send_to_mcu("+BIND_ERR:PACK_FAIL\r\n");
            return;
        }
        char rsp[80];
        snprintf(rsp, sizeof(rsp), "+BIND_DATA:%s\r\n", hex_buf);
        printf("[BLE] BIND success, data_len=%d hex=%s\r\n", ret, hex_buf);
        e02t_uart_send_to_mcu(rsp);
    }
    // [8] BLE 加组广播数据生成：AT+ADDGROUP
    else if (strstr(cmd_line, "AT+ADDGROUP") != NULL)
    {
        printf("[BLE] AT+ADDGROUP received, g_login_ok=%d, g_in_group=%d, gid=%u\r\n",
               g_login_ok, g_in_group, g_current_gid);
        if (!g_login_ok)
        {
            printf("[BLE] ADDGROUP rejected: not logged in\r\n");
            e02t_uart_send_to_mcu("+ADDGROUP_ERR:NOT_LOGIN\r\n");
            return;
        }
        if (g_addgroup_pending)
        {
            printf("[BLE] ADDGROUP already pending, ignored\r\n");
            return;
        }
        g_addgroup_pending = 1;
        g_invite_code_pending = 0;
        g_addgroup_gid = 0;
        if (g_addgroup_timer)
        {
            ql_rtos_timer_start(g_addgroup_timer, BLE_GROUP_TIMEOUT_MS, 0, addgroup_timeout_cb, 0);
        }

        if (g_in_group && g_current_gid != 0)
        {
            // 已在组：直接获取当前群组邀请码
            bnd_member_t self;
            memset(&self, 0, sizeof(self));
            broad_member_getbyid(0, &self);
            printf("[BLE] ADDGROUP already in group, get invite code: uid=%u gid=%u\r\n",
                   self.uid, g_current_gid);
            g_invite_code_pending = 1;
            g_addgroup_gid = (int)g_current_gid;
            int ret = broad_http_get_invitation_code_group((int)self.uid, (int)g_current_gid);
            printf("[BLE] ADDGROUP get_invitation_code ret=%d\r\n", ret);
            if (ret == -1)
            {
                g_addgroup_pending = 0;
                g_invite_code_pending = 0;
                if (g_addgroup_timer)
                    ql_rtos_timer_stop(g_addgroup_timer);
                printf("[BLE] ADDGROUP get invite code request failed\r\n");
                e02t_uart_send_to_mcu("+ADDGROUP_ERR:HTTP_FAIL\r\n");
            }
            else
            {
                printf("[BLE] ADDGROUP waiting for invite code callback (timeout=%dms)...\r\n", BLE_GROUP_TIMEOUT_MS);
            }
        }
        else
        {
            // 未在组：创建新群组，把本设备 uid 作为初始成员传入
            bnd_member_t self;
            memset(&self, 0, sizeof(self));
            broad_member_getbyid(0, &self);
            int self_uid = (int)self.uid;
            printf("[BLE] ADDGROUP not in group, calling broad_http_add_group(uid=%d)...\r\n", self_uid);
            // 建群成功后同样自动切入新群组：先快照当前列表
            e02t_auto_join_arm();
            int ret = broad_http_add_group(&self_uid, 1);
            printf("[BLE] ADDGROUP broad_http_add_group ret=%d\r\n", ret);
            if (ret == -1)
            {
                g_addgroup_pending = 0;
                e02t_auto_join_disarm();
                if (g_addgroup_timer)
                    ql_rtos_timer_stop(g_addgroup_timer);
                printf("[BLE] ADDGROUP HTTP request failed\r\n");
                e02t_uart_send_to_mcu("+ADDGROUP_ERR:HTTP_FAIL\r\n");
            }
            else
            {
                printf("[BLE] ADDGROUP waiting for async callback (timeout=%dms)...\r\n", BLE_GROUP_TIMEOUT_MS);
            }
        }
    }
    // [9] BLE 扫描加组：AT+JOINGROUP=<token>
    else if (strstr(cmd_line, "AT+JOINGROUP=") != NULL)
    {
        const char *eq = strstr(cmd_line, "AT+JOINGROUP=");
        const char *token_str = eq + 13;
        char token[16] = {0};
        int i;
        for (i = 0; i < 15 && token_str[i] != '\0' && token_str[i] != '\r' && token_str[i] != '\n'; i++)
        {
            token[i] = token_str[i];
        }
        token[i] = '\0';
        printf("[BLE] AT+JOINGROUP received, token=%s, g_login_ok=%d\r\n", token, g_login_ok);

        if (!g_login_ok)
        {
            printf("[BLE] JOINGROUP rejected: not logged in\r\n");
            e02t_uart_send_to_mcu("+JOINGROUP_ERR:NOT_LOGIN\r\n");
            return;
        }
        if (g_joingroup_pending)
        {
            printf("[BLE] JOINGROUP already pending, ignored\r\n");
            return;
        }
        bnd_member_t self;
        memset(&self, 0, sizeof(self));
        int get_ret = broad_member_getbyid(0, &self);
        printf("[BLE] JOINGROUP broad_member_getbyid ret=%d uid=%u\r\n", get_ret, self.uid);
        if (get_ret != 0 || self.uid == 0)
        {
            printf("[BLE] JOINGROUP cannot get uid\r\n");
            e02t_uart_send_to_mcu("+JOINGROUP_ERR:NOT_LOGIN\r\n");
            return;
        }
        g_joingroup_pending = 1;
        // 先快照进组前的群组列表：进组成功后用它 diff 出新群组并自动切入
        // （listupdate 与 HTTP 回调先后顺序不确定，两边都会触发检查）
        e02t_auto_join_arm();
        if (g_joingroup_timer)
        {
            ql_rtos_timer_start(g_joingroup_timer, BLE_GROUP_TIMEOUT_MS, 0, joingroup_timeout_cb, 0);
        }
        printf("[BLE] JOINGROUP calling broad_http_join_group(uid=%u, token=%s)...\r\n", self.uid, token);
        int ret = broad_http_join_group((int)self.uid, token);
        printf("[BLE] JOINGROUP broad_http_join_group ret=%d\r\n", ret);
        if (ret == -1)
        {
            g_joingroup_pending = 0;
            e02t_auto_join_disarm();
            if (g_joingroup_timer)
                ql_rtos_timer_stop(g_joingroup_timer);
            printf("[BLE] JOINGROUP HTTP request failed\r\n");
            e02t_uart_send_to_mcu("+JOINGROUP_ERR:HTTP_FAIL\r\n");
        }
        else
        {
            printf("[BLE] JOINGROUP waiting for async callback (timeout=%dms)...\r\n", BLE_GROUP_TIMEOUT_MS);
        }
    }
    // [10] 切组：AT+SWITCHGROUP
    else if (strstr(cmd_line, "AT+SWITCHGROUP") != NULL)
    {
        SL_LOG("UART", "AT+SWITCHGROUP received");
        if (!g_login_ok)
        {
            printf("[SWITCH] rejected: not logged in\r\n");
            tts_play_cn("未登录");
            e02t_uart_send_to_mcu("ERROR\r\n");
            return;
        }
        printf("[SWITCH] calling change_group, g_in_group=%d, gid=%u\r\n", g_in_group, g_current_gid);
        int ret = change_group();
        printf("[SWITCH] change_group ret=%d\r\n", ret);
        if (ret == 0)
        {
            e02t_uart_send_to_mcu("OK\r\n");
        }
        else if (ret == -1)
        {
            printf("[SWITCH] only one group or no different group available\r\n");
            tts_play_cn("当前仅一个组");
            e02t_uart_send_to_mcu("ERROR\r\n");
        }
        else
        {
            printf("[SWITCH] broad_joingroup failed (ret=%d)\r\n", ret);
            tts_play_cn("无法切组");
            e02t_uart_send_to_mcu("ERROR\r\n");
        }
    }
#endif /* E02T_BLE_GROUP_ENABLE */
    else
    {
        SL_LOG("UART", "Unknown command");
        e02t_uart_send_to_mcu("ERROR\r\n");
    }
}

// =========================================================
// 3. 中间层：独立 RTOS Task 专门负责接收和拼包
// =========================================================
static void e02t_uart_rx_thread(void *arg)
{
    uart_rx_msg_t msg;
    char line_buffer[UART_RX_MAX_SIZE] = {0};
    int line_idx = 0;

    SL_LOG("UART", "Parser thread started");

    while (1)
    {
        // 死等硬件中断把数据通过 Queue 发过来
        if (ql_rtos_queue_wait(uart_rx_queue, &msg, sizeof(msg), QL_WAIT_FOREVER) == 0)
        {
            // SL_LOG("UART", "RX chunk len=%d", msg.len);
            // 逐个字符拼装
            for (int i = 0; i < msg.len; i++)
            {
                char c = msg.data[i];

                // 防溢出保护
                if (line_idx >= (UART_RX_MAX_SIZE - 2))
                {
                    line_idx = 0;
                    memset(line_buffer, 0, sizeof(line_buffer));
                }

                line_buffer[line_idx++] = c;

                // 判断是否是一包结尾 (以 '\n' 为界)
                if (c == '\n')
                {
                    line_buffer[line_idx] = '\0'; // 字符串封尾

                    // 扔给解析函数
                    e02t_parse_at_command(line_buffer);

                    // 清空 Buffer，准备接收下一条指令
                    line_idx = 0;
                    memset(line_buffer, 0, sizeof(line_buffer));
                }
            }
        }
    }
}

// =========================================================
// 对外接口
// =========================================================
void e02t_uart_send_to_mcu(const char *str)
{
    if (str != NULL)
    {
        SL_LOG("MCU TX", "%s", str);
        ql_uart_write_sync(E02T_MCU_UART_PORT, (unsigned char *)str, strlen(str));
    }
}

void e02t_uart_register_line_handler(e02t_uart_line_handler_t handler)
{
    g_line_handler = handler;
}

int e02t_uart_mcu_init(void)
{
    int ret;
    ql_uart_config_t dcb;
    void *task_ref = NULL;

    // 1. 创建用于串口接收的消息队列
    ret = ql_rtos_queue_create(
        (ql_queue_t *)&uart_rx_queue, sizeof(uart_rx_msg_t), UART_RX_QUEUE_SIZE);
    if (ret != 0)
    {
        SL_LOG("UART", "Failed to create rx queue, err: %d", ret);
        return -1;
    }

    // 2. 初始化底层硬件串口
    ret = ql_uart_open(E02T_MCU_UART_PORT, E02T_MCU_UART_BAUD, QL_FC_NONE);
    if (ret)
    {
        SL_LOG("UART", "Failed to open UART %d, err: %d", E02T_MCU_UART_PORT, ret);
        return -1;
    }

    // 强制刷新一次 DCB 确保波特率正确
    ql_uart_get_dcbconfig(E02T_MCU_UART_PORT, &dcb);
    dcb.baudrate = E02T_MCU_UART_BAUD;
    ql_uart_set_dcbconfig(E02T_MCU_UART_PORT, &dcb);

    // 注册硬件中断回调 (只搬运数据)
    ql_uart_register_cb(E02T_MCU_UART_PORT, quec_uart_mcu_callback);

    // 3. 创建解析线程
    ret = ql_rtos_task_create(&task_ref, 4096, 50, "uart_parse_task", e02t_uart_rx_thread, NULL);
    if (ret != 0)
    {
        SL_LOG("UART", "Failed to create parser task, err: %d", ret);
        return -1;
    }

    SL_LOG("UART", "init success, port=%d", E02T_MCU_UART_PORT);
    g_mcu_uart_ready = 1;

    // 预热：尽早查一次电量，让首次心跳就能读到缓存值
    e02t_uart_query_battery_async();
    return 0;
}

int e02t_uart_mcu_is_ready(void)
{
    return g_mcu_uart_ready;
}

int e02t_uart_query_mcu(const char *cmd, char *response, int resp_len, int timeout_ms)
{
    int wait_ms = 0;
    if (!g_mcu_uart_ready)
        return -1;

    g_sync_rx_len = 0;
    g_sync_rx_buf[0] = '\0';
    g_sync_waiting = 1;

    e02t_uart_send_to_mcu(cmd);

    while (wait_ms < timeout_ms)
    {
        if (g_sync_rx_len > 0)
        {
            int copy_len = (g_sync_rx_len < resp_len - 1) ? g_sync_rx_len : (resp_len - 1);
            memcpy(response, g_sync_rx_buf, copy_len);
            response[copy_len] = '\0';
            while (copy_len > 0 && (response[copy_len - 1] == '\r' || response[copy_len - 1] == '\n'))
            {
                response[--copy_len] = '\0';
            }
            g_sync_rx_len = 0;
            g_sync_waiting = 0;
            return copy_len;
        }
        ql_rtos_task_sleep_ms(20);
        wait_ms += 20;
    }

    g_sync_waiting = 0;
    return -2;
}

int e02t_uart_query_battery_async(void)
{
    if (!g_mcu_uart_ready)
    {
        SL_LOG("BAT", "async query failed: uart not ready");
        return -1;
    }
    e02t_uart_send_to_mcu("AT+SOC\r\n");
    SL_LOG("BAT", "async query: sent AT+SOC");
    return 0;
}

int e02t_uart_get_battery(void)
{
    return g_battery_value;
}

// =========================================================
// 自动切组：加组成功后自动切换到新群组
// 覆盖两类来源：
// 1. 本机发起（AT+JOINGROUP/AT+ADDGROUP）：请求前快照列表，HTTP 回调
//    或 listupdate 到达时 diff 快照，谁先看到新 gid 谁触发；
// 2. 平台侧拉入（如手机端建群拉入，本机无感知）：listupdate 新旧列表
//    diff 发现新 gid 时直接切入。
// =========================================================

// 统一的自动进组动作：同一 gid 只自动进一次（防 listupdate 与回调双触发
// 导致重复进组），动作完成后取消 armed。返回 0 表示本次检查已收尾。
static int e02t_auto_join_do_join(unsigned int gid, const char *src)
{
    if (gid != 0 && gid != g_auto_join_done_gid)
    {
        g_auto_join_done_gid = gid;
        printf("[BLE] auto-join: %s gid=%u, joining\r\n", src, gid);
        broad_joingroup((bnd_gid_t)gid);
    }
    else
    {
        printf("[BLE] auto-join: %s gid=%u skipped (already auto-joined)\r\n", src, gid);
    }
    e02t_auto_join_disarm();
    return 0;
}

int e02t_auto_join_arm(void)
{
    int g_cnt = broad_get_groupcount();
    if (g_cnt > AUTO_JOIN_SNAPSHOT_MAX)
    {
        // 群组数超出快照容量：放弃自动切组（手动切组不受影响）
        printf("[BLE] auto-join arm failed: group count %d > %d\r\n", g_cnt, AUTO_JOIN_SNAPSHOT_MAX);
        g_auto_join_armed = 0;
        g_auto_join_snapshot_size = 0;
        return -1;
    }

    unsigned int n = 0;
    int i;
    for (i = 0; i < g_cnt; i++)
    {
        bnd_group_t grp;
        memset(&grp, 0, sizeof(grp));
        if (broad_group_getbyindex(i, &grp) == 0 && grp.gid != 0)
        {
            g_auto_join_snapshot[n++] = (unsigned int)grp.gid;
        }
    }
    // 先填快照再置标记，保证看到 armed=1 时快照内容完整
    g_auto_join_snapshot_size = n;
    g_auto_join_armed = 1;
    g_auto_join_done_gid = 0; // 新一轮请求：允许重新触发同一个 gid
    printf("[BLE] auto-join armed: snapshot %u groups\r\n", n);
    return 0;
}

void e02t_auto_join_disarm(void)
{
    g_auto_join_armed = 0;
    g_auto_join_snapshot_size = 0;
}

int e02t_auto_join_armed(void)
{
    return g_auto_join_armed;
}

int e02t_auto_join_check(void)
{
    if (!g_auto_join_armed)
    {
        return -1;
    }

    int g_cnt = broad_get_groupcount();
    int i, j;
    for (i = 0; i < g_cnt; i++)
    {
        bnd_group_t grp;
        memset(&grp, 0, sizeof(grp));
        if (broad_group_getbyindex(i, &grp) != 0 || grp.gid == 0)
        {
            continue;
        }

        int found = 0;
        for (j = 0; j < (int)g_auto_join_snapshot_size; j++)
        {
            if ((unsigned int)grp.gid == g_auto_join_snapshot[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            return e02t_auto_join_do_join((unsigned int)grp.gid, "snapshot diff");
        }
    }
    // 列表里还没出现新组：保持 armed，等下一次 listupdate 再检查
    printf("[BLE] auto-join: no new group visible yet\r\n");
    return -1;
}

int e02t_auto_join_notify_new(unsigned int gid)
{
    // 平台侧新出现的群组（本机未发起请求，如手机端建群拉入）
    if (gid == 0 || gid == (unsigned int)g_current_gid)
    {
        return -1;
    }
    return e02t_auto_join_do_join(gid, "remote new group");
}

// =========================================================
// BLE 群组 HTTP 回调实现
// =========================================================
#if E02T_BLE_GROUP_ENABLE
void e02t_addgroup_cb(int status, int gid, char *group_name, char *invite_code)
{
    printf("[BLE] addgroup_cb: status=%d gid=%d group_name=%s invite_code=%s\r\n",
           status, gid, group_name ? group_name : "NULL", invite_code ? invite_code : "NULL");
    printf("[BLE] addgroup_cb: pending=%d invite_pending=%d\r\n", g_addgroup_pending, g_invite_code_pending);

    if (!g_addgroup_pending)
    {
        printf("[BLE] addgroup_cb: not pending (timed out), ignored\r\n");
        return;
    }

    if (status != 0)
    {
        g_addgroup_pending = 0;
        if (g_addgroup_timer)
            ql_rtos_timer_stop(g_addgroup_timer);
        printf("[BLE] addgroup_cb: server rejected (status=%d)\r\n", status);
        e02t_uart_send_to_mcu("+ADDGROUP_ERR:CREATE_FAIL\r\n");
        return;
    }

    // 建群成功：尝试切入新群组（"已在组取邀请码"流程未 arm，这里无副作用）
    e02t_auto_join_check();

    if (invite_code == NULL || strlen(invite_code) == 0)
    {
        g_addgroup_gid = gid;
        g_invite_code_pending = 1;
        bnd_member_t self;
        memset(&self, 0, sizeof(self));
        broad_member_getbyid(0, &self);
        printf("[BLE] addgroup_cb: no invite_code, requesting via uid=%u gid=%d\r\n", self.uid, gid);
        int ret = broad_http_get_invitation_code_group((int)self.uid, gid);
        printf("[BLE] addgroup_cb: get_invitation_code ret=%d\r\n", ret);
        if (ret == -1)
        {
            g_addgroup_pending = 0;
            g_invite_code_pending = 0;
            if (g_addgroup_timer)
                ql_rtos_timer_stop(g_addgroup_timer);
            printf("[BLE] addgroup_cb: get_invitation_code request failed\r\n");
            e02t_uart_send_to_mcu("+ADDGROUP_ERR:NO_INVITE\r\n");
        }
        return;
    }

    g_addgroup_pending = 0;
    if (g_addgroup_timer)
        ql_rtos_timer_stop(g_addgroup_timer);

    printf("[BLE] addgroup_cb: packing protocol with invite_code=%s\r\n", invite_code);
    char hex_buf[64];
    int ret = e02t_make_ble_protocol(g_poc_account, 0x02, invite_code, hex_buf);
    printf("[BLE] addgroup_cb: make_protocol ret=%d\r\n", ret);
    if (ret < 0)
    {
        printf("[BLE] addgroup_cb: pack failed\r\n");
        e02t_uart_send_to_mcu("+ADDGROUP_ERR:PACK_FAIL\r\n");
        return;
    }
    char rsp[80];
    snprintf(rsp, sizeof(rsp), "+GROUP_DATA:%s\r\n", hex_buf);
    printf("[BLE] addgroup_cb: success, hex=%s\r\n", hex_buf);
    e02t_uart_send_to_mcu(rsp);
}

void e02t_get_invite_code_cb(int status, char *invitation_code)
{
    printf("[BLE] get_invite_code_cb: status=%d code=%s\r\n",
           status, invitation_code ? invitation_code : "NULL");
    printf("[BLE] get_invite_code_cb: invite_pending=%d addgroup_pending=%d\r\n",
           g_invite_code_pending, g_addgroup_pending);

    if (!g_invite_code_pending)
    {
        printf("[BLE] get_invite_code_cb: not pending, ignored\r\n");
        return;
    }
    g_addgroup_pending = 0;
    g_invite_code_pending = 0;
    if (g_addgroup_timer)
        ql_rtos_timer_stop(g_addgroup_timer);

    if (status != 0 || invitation_code == NULL || strlen(invitation_code) == 0)
    {
        printf("[BLE] get_invite_code_cb: failed or empty code\r\n");
        e02t_uart_send_to_mcu("+ADDGROUP_ERR:NO_INVITE\r\n");
        return;
    }

    printf("[BLE] get_invite_code_cb: packing protocol with code=%s\r\n", invitation_code);
    char hex_buf[64];
    int ret = e02t_make_ble_protocol(g_poc_account, 0x02, invitation_code, hex_buf);
    printf("[BLE] get_invite_code_cb: make_protocol ret=%d\r\n", ret);
    if (ret < 0)
    {
        printf("[BLE] get_invite_code_cb: pack failed\r\n");
        e02t_uart_send_to_mcu("+ADDGROUP_ERR:PACK_FAIL\r\n");
        return;
    }
    char rsp[80];
    snprintf(rsp, sizeof(rsp), "+GROUP_DATA:%s\r\n", hex_buf);
    printf("[BLE] get_invite_code_cb: success, hex=%s\r\n", hex_buf);
    e02t_uart_send_to_mcu(rsp);
}

void e02t_joingroup_cb(int status)
{
    printf("[BLE] joingroup_cb: status=%d pending=%d\r\n", status, g_joingroup_pending);

    if (!g_joingroup_pending)
    {
        printf("[BLE] joingroup_cb: not pending (timed out), ignored\r\n");
        return;
    }
    g_joingroup_pending = 0;
    if (g_joingroup_timer)
        ql_rtos_timer_stop(g_joingroup_timer);

    if (status == 0)
    {
        printf("[BLE] joingroup_cb: join success!\r\n");
        // 平台可能已先推送过 listupdate（新组已在列表里），这里立即尝试切组；
        // 若列表还没刷新，check 保持 armed，由 listupdate 回调到达时再触发
        e02t_auto_join_check();
        e02t_uart_send_to_mcu("+GROUP_OK\r\n");
    }
    else
    {
        printf("[BLE] joingroup_cb: join failed (status=%d)\r\n", status);
        e02t_auto_join_disarm();
        e02t_uart_send_to_mcu("+JOINGROUP_ERR:JOIN_FAIL\r\n");
    }
}

// =========================================================
// BLE 群组功能初始化
// =========================================================
void e02t_ble_group_init(void)
{
    int ret;
    ret = ql_rtos_timer_create(&g_addgroup_timer);
    if (ret != 0)
    {
        printf("[BLE] Failed to create addgroup timer, err=%d\r\n", ret);
    }
    ret = ql_rtos_timer_create(&g_joingroup_timer);
    if (ret != 0)
    {
        printf("[BLE] Failed to create joingroup timer, err=%d\r\n", ret);
    }
    printf("[BLE] BLE group init done, addgroup_timer=%p joingroup_timer=%p\r\n",
           g_addgroup_timer, g_joingroup_timer);
}
#endif /* E02T_BLE_GROUP_ENABLE */
