#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "broad.h"
#include "e02t_config.h"
#include "e02t_gps.h"
#include "e02t_uart_mcu.h"
#include "e02t_board_cfg.h"
#include "inet6.h"
#include "lte_tcpudp_heartbeat.h"
#include "netdb.h"
#include "ql_application.h"
#include "ql_audio.h"
#include "ql_data_call.h"
#include "ql_dev.h"
#include "ql_gpio.h"
#include "ql_log.h"
#include "ql_nw.h"
#include "ql_rtos.h"
#include "ql_sim.h"
#include "ql_tts.h"
#include "ql_uart.h"
#include "sl_log.h"
#include "sockets.h"
#include "tts_gbk.h"
#include "version.h"
#include "interface/log/inc/ql_log.h" // 提供 ql_log_mask_set

#define CUSTOMER_APP_VERSION "APP_V0.0.2"
/* TCP/UDP diagnostic build: restore to 1 to resume Broad application login.
 * The prebuilt Broad kernel, audio and UART remain initialized. */
#ifndef POC_INTERCOM_LOGIN_ENABLE
#define POC_INTERCOM_LOGIN_ENABLE 0
#endif
// =========================================================================
// 【登录账号配置】
// 定义 POC_ACCOUNT 则使用固定账号，不定义则自动读取设备 IMEI 作为账号
// =========================================================================
// #define POC_ACCOUNT "868781080005487"

#ifndef POC_PASSWORD
#define POC_PASSWORD "1"
#endif

// =========================================================================
// 【TTS 语音文案配置】直接写中文，tts_play_cn() 会自动转 GBK
// =========================================================================
#define TTS_LOGIN_OK "登录成功"
#define TTS_LOGIN_FAIL "登录失败"

#define POC_PROFILE_IDX LTE_HEARTBEAT_PROFILE_IDX

// =========================================================================
// 全局状态变量 (线程安全，volatile)
// =========================================================================
volatile int g_login_ok = 0;
volatile int g_in_group = 0;

extern int cell_locator_init(void);
char g_poc_account[32] = {0}; // 登录账号（IMEI或手动指定）
volatile bnd_gid_t g_current_gid = 0;
static volatile int g_is_speaking = 0;
static volatile int g_is_listening = 0; // 接收对讲状态

// =========================================================================
// POC 登录失败原因码
// =========================================================================
enum
{
    POC_FAIL_NONE = 0,
    POC_FAIL_SIM,           // 1 — SIM 卡未就绪
    POC_FAIL_NETWORK,       // 2 — 搜网/驻网失败
    POC_FAIL_DATA_CALL,     // 3 — 数据拨号失败
    POC_FAIL_BROAD_INIT,    // 4 — Broad SDK 未初始化
    POC_FAIL_SERVER_REJECT, // 5 — 服务器拒绝
    POC_FAIL_TIMEOUT,       // 6 — 20s 超时原因不明
};
static volatile int g_poc_fail_reason = POC_FAIL_NONE;
static char g_poc_fail_detail[64] = {0};

char ip_addr_str[64] = {0};
uint8_t data_call_success = 0; // 导出给fota_test.c使用
ql_flag_t ptt_key_event_flag = NULL;

static u8 ptt_is_pressed = 0;
extern volatile int g_is_gps_open;
extern volatile int g_gps_report_rate;
extern void *uart_event_flag;
#define QL_GPS_CTRL_FLAG (0x01 << 2)

// =========================================================================
// 音频状态字符串 (调试用)
// =========================================================================
static const char *get_audio_state_str(AUDIO_STATE state)
{
    switch (state)
    {
    case AUDIO_IDLE:
        return "AUDIO_IDLE";
    case BND_SPEAK_START:
        return "BND_SPEAK_START";
    case BND_SPEAKING:
        return "BND_SPEAKING";
    case BND_SPEAK_STOP:
        return "BND_SPEAK_STOP";
    case BND_LISTEN_START:
        return "BND_LISTEN_START";
    case BND_LISTENING:
        return "BND_LISTENING";
    case BND_LISTEN_STOP:
        return "BND_LISTEN_STOP";
    case BND_TTS_START:
        return "BND_TTS_START";
    case BND_TTS_STOP:
        return "BND_TTS_STOP";
    case BND_TONE_START:
        return "BND_TONE_START";
    case BND_TONE_STOP:
        return "BND_TONE_STOP";
    case BND_REC_PLAY_START:
        return "BND_REC_PLAY_START";
    case BND_REC_PLAY_STOP:
        return "BND_REC_PLAY_STOP";
    default:
        return "UNKNOWN_STATE";
    }
}

// =========================================================================
// TTS 回调
// =========================================================================
void tts_cb(QL_TTS_ENVENT_E event, char *str)
{
    SL_LOG("TTS", "cb event=%d, str=%s", event, str);
}

// =========================================================================
// SIM 卡检测 (保留自 corget 版本，已验证)
// =========================================================================
static int check_sim_state(void)
{
    int ret = 0, card_status = -1, retry_num = 0;
RETRY_CHECK:
    ret = ql_sim_get_card_status(&card_status);
    SL_LOG("SIM", "state: %d", card_status);
    if (ret == 0)
    {
        switch (card_status)
        {
        case QL_SIM_STATUS_READY:
            return 0;
        default:
            if (retry_num < 60)
            {
                retry_num++;
                if ((card_status == QL_SIM_STATUS_NOT_INSERTED) && (retry_num == 30))
                {
                    ql_dev_set_modem_fun(QL_DEV_MODEM_MIN_FUN, 0);
                    ql_rtos_task_sleep_s(3);
                    ql_dev_set_modem_fun(QL_DEV_MODEM_FULL_FUN, 0);
                    ql_rtos_task_sleep_s(2);
                }
                ql_rtos_task_sleep_s(1);
                goto RETRY_CHECK;
            }
            break;
        }
    }
    g_poc_fail_reason = POC_FAIL_SIM;
    return -1;
}

static int wait_network_register(int time)
{
    int ret = 0, retry_num = 0;
    QL_NW_REG_STATUS_INFO_T reg_status;
RETRY_CHECK:
    ret = ql_nw_get_reg_status(&reg_status);
    SL_LOG("NW", "state: %d", reg_status.data_reg.state);
    if (ret == 0)
    {
        switch (reg_status.data_reg.state)
        {
        case QL_NW_REG_STATE_HOME_NETWORK:
        case QL_NW_REG_STATE_ROAMING:
            return 0;
        default:
            ql_rtos_task_sleep_s(1);
            if (retry_num < time)
            {
                retry_num++;
                goto RETRY_CHECK;
            }
            break;
        }
    }
    g_poc_fail_reason = POC_FAIL_NETWORK;
    return -1;
}

// =========================================================================
// 网络状态回调与拨号 (保留自 corget 版本，已验证)
// =========================================================================
static void ql_nw_status_callback(int profile_idx, int nw_status)
{
    struct ql_data_call_info info = {0};
    int info_ret;
    SL_LOG("NW", "profile(%d) status: %d", profile_idx, nw_status);
    if (profile_idx != POC_PROFILE_IDX)
        return;

    if (nw_status)
    {
        info_ret = ql_get_data_call_info(profile_idx, 0, &info);
        if (info_ret != 0 || info.profile_idx != POC_PROFILE_IDX ||
            !info.v4.state || info.v4.addr.ip.s_addr == 0 ||
            info.v4.addr.ip.s_addr == INADDR_NONE)
        {
            data_call_success = 0;
            SL_LOG("NW", "UP but IPv4 not ready: query_ret=%d profile=%d state=%d; polling",
                   info_ret, info.profile_idx, info.v4.state);
            lte_tcpudp_heartbeat_network_changed(profile_idx, 0);
            return;
        }
        SL_LOG("NW", "profile_idx: %d", info.profile_idx);
        SL_LOG("NW", "ip_version: %d", info.ip_version);

        if (info.ip_version)
        {
            inet_ntop(AF_INET6, &info.v6.addr.ip, ip_addr_str, sizeof(ip_addr_str));
            SL_LOG("NW", "v6 ip: %s", ip_addr_str);
        }
        else
        {
            inet_ntop(AF_INET, &info.v4.addr.ip, ip_addr_str, sizeof(ip_addr_str));
            SL_LOG("NW", "v4 ip: %s", ip_addr_str);
        }
        data_call_success = 1;
        lte_tcpudp_heartbeat_network_changed(profile_idx, 1);
    }
    else
    {
        data_call_success = 0;
        lte_tcpudp_heartbeat_network_changed(profile_idx, 0);
        SL_LOG("NW", "Data call failed! profile_idx:%d", profile_idx);
    }
}

static void datacall_start(void)
{
    SL_LOG("NW", "wait for network register");

    if (ql_network_register_wait(120) != 0)
    {
        SL_LOG("NW", "*** network register fail ***");
    }
    else
    {
        SL_LOG("NW", "doing network activing ...");
        ql_wan_start(ql_nw_status_callback);
        ql_set_data_call_asyn_mode(1, ql_nw_status_callback);
        ql_set_auto_connect(POC_PROFILE_IDX, TRUE);
        int dial_ret = ql_start_data_call(POC_PROFILE_IDX, 0, NULL, NULL, NULL, 0);
        SL_LOG("NW", "start data call profile=%d ret=%d", POC_PROFILE_IDX, dial_ret);
    }
}

// =========================================================================
// PA 功放控制 (保留 PTT 优先级逻辑 + 接收对讲保护)
// =========================================================================
static int g_pa_level = -1; // -1 未知, 0 关闭, 1 打开，避免重复通知 MCU

static void pa_set_level(int is_on)
{
    if (g_pa_level == is_on)
    {
        return; // 状态未变化，跳过（避免重复发送 URC 给 MCU）
    }

    if (is_on)
    {
        // 打开4G PA → 延迟 50ms → 通知 MCU
        ql_gpio_set_level(AUDIO_PA_CONTRL_PIN, PIN_LEVEL_HIGH);
        g_pa_level = 1;
        if (e02t_uart_mcu_is_ready())
        { // 通知 MCU 打开 外接PA
            e02t_uart_send_to_mcu("AT+PA=OPEN\r\n");
        }
    }
    else
    {
        // 通知 MCU → 延迟 50ms → 关闭4G PA
        if (e02t_uart_mcu_is_ready())
        { // 通知 MCU 可以关闭 外接PA
            e02t_uart_send_to_mcu("AT+PA=CLOSE\r\n");
            ql_rtos_task_sleep_ms(50);
        }
        ql_gpio_set_level(AUDIO_PA_CONTRL_PIN, PIN_LEVEL_LOW);
        g_pa_level = 0;
    }
}

static void shanli_audio_pa_contrl(int is_on)
{
    if (ptt_is_pressed)
    {
        SL_LOG("PA", "is_on=%d ignored, PTT active, forcing HIGH", is_on);
        pa_set_level(1);
    }
    else if (g_is_listening && is_on == 0)
    {
        // 接收对讲期间，拒绝关闭 PA（防止 TONE_STOP 导致的音频残留）
        SL_LOG("PA", "is_on=0 ignored, listening active, keeping HIGH");
        pa_set_level(1);
    }
    else
    {
        SL_LOG("PA", "set=%d", is_on);
        pa_set_level(is_on);
    }
}

// =========================================================================
// 音频增益配置 (保留自 corget 版本，已调优)
// =========================================================================
static void ql_set_audio_gain(void)
{
    ql_set_volume(6);
    ql_set_dtmf_volume(8);
    ql_set_txdspgain(6);
    ql_set_txcodecgain(2);
    ql_rtos_task_sleep_ms(100);
}

// =========================================================================
// 音频子系统初始化 (保留自 corget 版本，已验证)
// =========================================================================
static int ql_audio_init(void)
{
    while (!ql_get_audio_state())
    {
        ql_rtos_task_sleep_ms(50);
    }

    ql_codec_choose(AUD_INTERNAL_CODEC, NULL);
    ql_set_audio_gain();
    ql_tts_init(tts_cb);

    ql_set_denoise_flag(1);
    ql_set_volume(8); // 系统主音量：11 最大。接收对讲语音走主音量（BND_VOICE 对其无效），降到 8

    ql_tts_set_volume(-17000); // TTS 音量：范围 -32768~32767，0=默认(满响)，负值=衰减。0/5 都≈满响，必须用负值才变小

    ql_set_audio_path_receiver();

    return 0;
}

// =========================================================================
// 网络初始化 (保留自 corget 版本，已验证)
// =========================================================================
static int ql_network_init(void)
{
    int ret;

retry:
    ret = check_sim_state();
    if (ret != 0)
    {
        goto retry;
    }

    ret = wait_network_register(120);
    SL_LOG("NW", "network register ret: %d", ret);
    if (ret != 0)
    {
        goto retry;
    }

    datacall_start();

    int wait_num = 60;
    while (wait_num--)
    {
        struct ql_data_call_info info = {0};
        int info_ret = ql_get_data_call_info(POC_PROFILE_IDX, 0, &info);
        if (info_ret == 0 && info.profile_idx == POC_PROFILE_IDX && info.v4.state &&
            info.v4.addr.ip.s_addr != 0 && info.v4.addr.ip.s_addr != INADDR_NONE)
        {
            data_call_success = 1;
            return 0;
        }
        data_call_success = 0;
        ql_rtos_task_sleep_s(1);
    }

    g_poc_fail_reason = POC_FAIL_DATA_CALL;
    return -1;
}

// =========================================================================
// Shanli Broad SDK 回调函数
// =========================================================================

/**
 * @brief 登录状态回调
 */
static void ui_login_status(int online)
{
#if !POC_INTERCOM_LOGIN_ENABLE
    g_login_ok = 0;
    g_in_group = 0;
    SL_LOG("POC", "Login callback ignored in TCP/UDP test mode: status=%d", online);
    return;
#endif
    SL_LOG("POC", "Login status: %s", online == USER_ONLINE ? "ONLINE" : "OFFLINE");

    if (online == USER_ONLINE)
    {
        g_login_ok = 1;
        SL_LOG("POC", "Login success! Account: %s", g_poc_account);
        tts_play_cn(TTS_LOGIN_OK);

        ql_rtos_task_sleep_s(1);

        ql_rtos_task_sleep_s(5);

        int group_count = broad_get_groupcount();
        SL_LOG("POC", "Group count: %d", group_count);

        if (group_count > 0)
        {
            bnd_group_t group;
            memset(&group, 0, sizeof(group));
            if (broad_group_getbyindex(0, &group) == 0)
            {
                SL_LOG("POC", "Found first group: name=%s, gid=%u", group.name, group.gid);
                int ret = broad_joingroup(group.gid);
                SL_LOG("POC", "Join group request ret=%d", ret);
            }
            else
            {
                SL_LOG("POC", "Failed to get group info");
            }
        }
        else
        {
            SL_LOG("POC", "No groups available!");
        }
    }
    else
    {
        g_login_ok = 0;
        g_in_group = 0;
    }
}

/**
 * @brief 进组回调
 */
static void ui_join_group(const char *groupname, bnd_gid_t gid)
{
    SL_LOG("POC", "Join group: name=%s, gid=%u", groupname ? groupname : "NULL", gid);

    if (gid != 0)
    {
        g_in_group = 1;
        g_current_gid = gid;
        SL_LOG("POC", "Joined group successfully! Ready for POC.");
        char tts_buf[64];
        snprintf(tts_buf, sizeof(tts_buf), "当前群组%s", groupname ? groupname : "");
        // 改用 tts_play_cn（ql_tts_play），与「登录成功」共用 ql_tts_set_volume 音量，
        // 避免 broad_play_tts 走 broad SDK 独立音量（BND_TTS）不受 ql_tts_set_volume 控制
        tts_play_cn(tts_buf);
    }
    else
    {
        g_in_group = 0;
        g_current_gid = 0;
        g_is_speaking = 0;
        SL_LOG("POC", "Left group");
    }
}

/**
 * @brief 音频状态回调
 */
static void ui_audio_state(AUDIO_STATE state, bnd_uid_t uid, const char *name, int flag,
                           bnd_gid_t gid, const char *g_name)
{
    if (state == BND_LISTEN_START || state == BND_LISTENING || state == BND_LISTEN_STOP)
    {
        SL_LOG("AUD",
               "%s uid:%u, name:%s, flag:%d, gid:%u",
               get_audio_state_str(state),
               uid,
               name ? name : "NULL",
               flag,
               gid);
    }
    else
    {
        SL_LOG("AUD", "%s", get_audio_state_str(state));
    }

    if (state == BND_SPEAK_START)
    {
        g_is_speaking = 1;
    }
    else if (state == BND_SPEAK_STOP)
    {
        g_is_speaking = 0;
    }
    else if (state == BND_LISTEN_START)
    {
        // 开始接收对讲：设置接收状态，重新设置音频路径
        g_is_listening = 1;
        ql_set_audio_path_receiver();
    }
    else if (state == BND_LISTEN_STOP)
    {
        // 接收对讲结束：清除接收状态，重新设置音频路径
        g_is_listening = 0;
        ql_set_audio_path_receiver();
    }
}

/**
 * @brief AT 透传回调
 */
static void ui_poc_at(char *at)
{
    if (at)
    {
        SL_LOG("POC", "AT: %s", at);
    }
}

/**
 * @brief 错误回调
 */
static void ui_error(const char *info)
{
    if (info)
    {
        SL_LOG("POC", "Error: %s", info);
        g_poc_fail_reason = POC_FAIL_SERVER_REJECT;
        strncpy(g_poc_fail_detail, info, sizeof(g_poc_fail_detail) - 1);

        if (strstr(info, "Account Logged in Elsewhere") != NULL ||
            strstr(info, "帐号已在其他位置登录") != NULL)
        {
            tts_play_cn("帐号已在其他位置登录");
        }
    }
}

void ui_request_location_change(int location_switch, int report_rate)
{
    printf("[POC] Location change: switch=%d, rate=%d\r\n", location_switch, report_rate);
    ql_app_log("[LOC] platform request: GPS %s, report_rate=%d",
               location_switch ? "ENABLE" : "DISABLE", report_rate);
    g_is_gps_open = location_switch ? 1 : 0;
    if (report_rate > 0)
    {
        g_gps_report_rate = report_rate;
    }
    if (uart_event_flag)
    {
        ql_rtos_flag_release(uart_event_flag, QL_GPS_CTRL_FLAG, QL_FLAG_OR);
    }
}

static void login_timeout_task(void *arg)
{
    ql_rtos_task_sleep_s(6);
    if (!g_login_ok)
    {
        if (g_poc_fail_reason == POC_FAIL_NONE)
        {
            g_poc_fail_reason = POC_FAIL_TIMEOUT;
        }
        char cmd[128];
        snprintf(cmd, sizeof(cmd), "AT+POCFAIL=%d,%s\r\n",
                 g_poc_fail_reason,
                 g_poc_fail_detail[0] ? g_poc_fail_detail : "UNKNOWN");
        SL_LOG("POC", "Login timeout: %s", cmd);
        e02t_uart_send_to_mcu(cmd);
    }
    ql_rtos_task_delete(NULL);
}

// 切组 变量
static unsigned int *group_id_array = NULL;
static unsigned int group_id_array_size = 0;
static unsigned int change_group_index = 0;
// 切组 变量

// 切组回调函数注册
static void listupdate_cb_fun(int flag)
{
    int i = 0;
    if (flag == 1)
    {

        int g_cnt = broad_get_groupcount();
        if (g_cnt <= 0)
        {
            if (group_id_array)
            {
                free(group_id_array);
                group_id_array = NULL;
            }
            group_id_array_size = 0;
            change_group_index = 0;
            g_in_group = 0;
            g_current_gid = 0;
            e02t_auto_join_disarm();
            return;
        }
        if (g_cnt == (int)group_id_array_size && !e02t_auto_join_armed())
            return;

        unsigned int *old_array = group_id_array;
        unsigned int old_size = group_id_array_size;
        group_id_array = NULL;
        group_id_array_size = 0;

        group_id_array = (unsigned int *)malloc(sizeof(unsigned int) * g_cnt);
        if (group_id_array == NULL)
        {
            if (old_array)
                free(old_array);
            e02t_auto_join_disarm();
            return;
        }

        int valid = 0;
        for (i = 0; i < g_cnt; i++)
        {
            bnd_group_t grp;
            memset(&grp, 0, sizeof(grp));
            if (broad_group_getbyindex(i, &grp) == 0 && grp.gid != 0)
            {
                printf("[GRPLIST] index=%d gid=%u name=%s\r\n", i, grp.gid, grp.name);
                group_id_array[valid] = grp.gid;
                valid++;
            }
        }
        group_id_array_size = valid;
        printf("[GRPLIST] valid group count:%d (old_size=%u)\r\n", valid, old_size);

        if (valid == 0)
        {
            free(group_id_array);
            group_id_array = NULL;
        }

        // 自动切组：diff 逻辑移到 e02t 模块（对比发起进组请求前的列表快照）。
        // HTTP 成功回调到达时已自查过一次；这里是列表刷新后的兜底触发，
        // 覆盖 "listupdate 先于 HTTP 回调到达" 的时序（旧实现该时序会漏切组）
        e02t_auto_join_check();

        // 平台侧新增群组（本机未发起请求，如手机端建群拉入）：同样自动切入。
        // 首次填充列表（old 为空）不算"新增"，避免与登录自动进组逻辑打架
        if (old_array != NULL && old_size > 0)
        {
            unsigned int j;
            for (i = 0; i < valid; i++)
            {
                int found = 0;
                for (j = 0; j < old_size; j++)
                {
                    if (group_id_array[i] == old_array[j])
                    {
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    e02t_auto_join_notify_new(group_id_array[i]);
                    break;
                }
            }
        }

        if (old_array)
            free(old_array);
    }
}
// 切组回调函数注册

// 切组函数
//  返回: 0=成功, -1=只有一个组或无组, -2=joingroup调用失败
int change_group(void)
{
    printf("[SWITCH] change_group enter: array=%p size=%u index=%u current_gid=%u\r\n",
           group_id_array, group_id_array_size, change_group_index, (unsigned int)g_current_gid);

    if (group_id_array == NULL || group_id_array_size <= 1)
    {
        printf("[SWITCH] abort: array=%p size=%u\r\n", group_id_array, group_id_array_size);
        return -1;
    }

    unsigned int i;
    for (i = 0; i < group_id_array_size; i++)
    {
        printf("[SWITCH] group_id_array[%u]=%u\r\n", i, group_id_array[i]);
    }

    unsigned int start = change_group_index;
    do
    {
        change_group_index++;
        if (change_group_index >= group_id_array_size)
        {
            change_group_index = 0;
        }
        if (group_id_array[change_group_index] != (unsigned int)g_current_gid)
        {
            break;
        }
    } while (change_group_index != start);

    int next_gid = group_id_array[change_group_index];
    printf("[SWITCH] selected: index=%u next_gid=%u current_gid=%u\r\n",
           change_group_index, next_gid, (unsigned int)g_current_gid);

    if (next_gid == (int)g_current_gid)
        return -1;

    printf("[GRPLIST] change_group_index:%d next_gid:%u\r\n", change_group_index, next_gid);
    int ret = broad_joingroup(next_gid);
    printf("[SWITCH] broad_joingroup ret=%d\r\n", ret);
    return (ret == 0) ? 0 : -2;
}
// 切组函数

/**
 * @brief 配置平台参数、注册回调、登录
 * 注意：不再作为 broad_init() 的回调，而是手动调用（和同事 demo 一致）
 * 必须在 broad_get_init_status() 返回非0 之后调用
 */
/* 【测试开关】对讲登录：1=正常登录进组对讲；0=禁用登录（用于 MIC/自测等，
 * 平台配置与回调仍注册，仅跳过 broad_login_by_saved 及登录超时上报） */

static void ui_init(void)
{
    char buf[128];
    broad_get_version(buf);
    SL_LOG("POC", "SDK version: %s", buf);

    // 关闭 broad 内部 UART 设备（我们用自己的 e02t_uart_mcu）
    broad_set_poc_uart_device(0);

    // 平台配置
#define USE_TEST_DNS 1 // 测试开关：1=善理APP端环境，0=调度台环境
#if USE_TEST_DNS
    broad_write_custom(CHANGE_PLATFORM_DNS, "sporttest.shanliptt.com:10200");
    broad_write_custom(CHANGE_PLATFORM_CONTEXT, "sports");
    broad_write_custom(SET_TOC_PLATFROM, "1");
    //broad_write_custom(CHANGE_PLATFORM_DNS, "toc.dns.shanliptt.com:20200");
    //broad_write_custom(CHANGE_PLATFORM_CONTEXT, "sports");
#else

    broad_write_custom(CHANGE_PLATFORM_CONTEXT, "show");
#endif
    broad_write_custom(SET_IS_BROAD, "0");
    broad_write_custom(SET_IS_ABROAD, "0");
    broad_set_notify_mode(1);
    broad_set_solution("HECSION");
    broad_set_solution_version("1.0.0-20260130");
    broad_set_productInfo("E02");
    broad_set_manufacturer("HECSION");
    broad_set_call_end_timeptr(30);
    broad_set_call_auto_leave_temp_group(1);

    // 注册回调
    broad_register_audio_cb(ui_audio_state);
    broad_register_join_group_cb(ui_join_group);
    broad_register_poc_at_cb(ui_poc_at);
    broad_register_error_cb(ui_error);
    broad_register_pa_cb(shanli_audio_pa_contrl);
    broad_register_location_change_cb(ui_request_location_change);

    // BLE 群组相关 HTTP 回调
    broad_register_recv_http_add_group_cb(e02t_addgroup_cb);
    broad_register_recv_http_get_invitation_code_cb(e02t_get_invite_code_cb);
    broad_register_recv_http_join_group_cb(e02t_joingroup_cb);
    broad_register_listupdate_cb(listupdate_cb_fun);

    // 设置账号：优先使用手动定义，否则自动读取 IMEI
#ifdef POC_ACCOUNT
    strncpy(g_poc_account, POC_ACCOUNT, sizeof(g_poc_account) - 1);
#else
    if (ql_dev_get_imei(g_poc_account, sizeof(g_poc_account)) != 0)
    {
        SL_LOG("POC", "Failed to get IMEI, cannot login");
        return;
    }
#endif
    int set_ret = broad_change_logininfo(g_poc_account, POC_PASSWORD);
    SL_LOG("POC", "Account set: %s (ret=%d)", g_poc_account, set_ret);

    // 登录
#if POC_INTERCOM_LOGIN_ENABLE
    int login_ret = broad_login_by_saved(ui_login_status);
    SL_LOG("POC", "Login request sent, ret=%d", login_ret);
#else
    (void)ui_login_status; /* referenced to avoid unused-function warning */
    SL_LOG("POC", "Login paused for TCP/UDP test; Broad kernel remains initialized");
#endif
}

// =========================================================================
// PTT 话权控制
// =========================================================================
static int poc_start_speak(void)
{
    if (!g_login_ok)
    {
        SL_LOG("POC", "Cannot speak: not logged in");
        return -1;
    }
    if (!g_in_group)
    {
        SL_LOG("POC", "Cannot speak: not in group");
        return -1;
    }
    if (g_is_speaking)
    {
        SL_LOG("POC", "Already speaking, ignoring");
        return -1;
    }

    // 检查当前是否有人在说话（收听状态），有人说话时不抢麦
    AUDIO_STATE cur_state = broad_get_audiostate();
    if (cur_state == BND_LISTEN_START || cur_state == BND_LISTENING)
    {
        SL_LOG("POC", "Someone is speaking, skip broad_speak(1) to keep listening");
        return -1;
    }

    SL_LOG("POC", ">>> START SPEAKING <<<");
    int ret = broad_speak(1);
    if (ret != 0)
    {
        SL_LOG("POC", "Failed to start speak, ret=%d", ret);
    }
    return ret;
}

static int poc_stop_speak(void)
{
    if (!g_is_speaking)
    {
        // 没有获得话权（抢麦失败），不调 broad_speak(0)
        // 否则 SDK 会触发 pa_cb(0) 关闭功放，导致正在收听的音频中断
        SL_LOG("POC", "Not speaking, skip broad_speak(0) to keep listening");
        return 0;
    }

    SL_LOG("POC", "<<< STOP SPEAKING >>>");
    int ret = broad_speak(0);
    g_is_speaking = 0;
    if (ret != 0)
    {
        SL_LOG("POC", "Failed to stop speak, ret=%d", ret);
    }
    return ret;
}

// =========================================================================
// PTT 按键中断 (保留自 corget 版本，已验证的防抖方案)
// =========================================================================
static void ptt_key_irq_handler(void)
{
    ql_rtos_flag_release(ptt_key_event_flag, QL_PTTKEY_CHANGE_FLAG, QL_FLAG_OR);
    ql_eint_enable(CORGET_POC_PTT_PIN, PIN_BOTH_EDGE);
}

// =========================================================================
// 信号等级：CSQ(0-31) → 1-5 级
// =========================================================================
static int get_signal_level(void)
{
    int csq = 0;
    if (ql_nw_get_csq(&csq) != 0 || csq == 99)
        return 1;
    if (csq <= 6)
        return 1;
    if (csq <= 12)
        return 2;
    if (csq <= 18)
        return 3;
    if (csq <= 24)
        return 4;
    return 5;
}

// =========================================================================
// 功耗：心跳与终端信息上报频率
// =========================================================================
// 心跳是 POC 平台保活必需，但每次上行都要拉起射频收发，是设备在线时最主要的
// 持续耗电点。原 20s 一次太密，改为 40s 一次，上行次数降到 1/2。
#define POC_HEARTBEAT_MS    (40 * 1000)

// 电量/信号是慢变量，没必要跟着心跳走：每 POC_TERM_INFO_EVERY 次心跳上报一次
// (40s x 3 = 2 分钟)。顺带把 CSQ 查询和 MCU 的 AT+SOC 查询也降到同一频率——
// ql_nw_get_csq() 是同步查询，每 20s 查一次会反复把 modem 从低功耗态拉起来。
#define POC_TERM_INFO_EVERY 3

// =========================================================================
// POC 核心主任务
// =========================================================================
static void shanli_poc_main_task(void *arg)
{
    int heartbeat_cnt = 0;
    uint32_t event;
    // 打印版本信息
    SL_LOG("VER", "Firmware: %s", VERSION_STRING);
    SL_LOG("VER", "Branch: %s", GIT_BRANCH);
    SL_LOG("VER", "Build: %s", BUILD_DATE);
    SL_LOG("TCPUDP", "test build %s; Broad application login=%d",
           LTE_HEARTBEAT_TEST_VERSION, POC_INTERCOM_LOGIN_ENABLE);

    // 系统刚启动，等底层驱动初始化完成
    ql_rtos_task_sleep_s(5);

    // 读取 U:/config.ini 配置文件
    e02t_config_load();

    // 创建 PTT 事件标志 (与 MCU UART 模块共享)
    ql_rtos_flag_create(&ptt_key_event_flag);
    if (!ptt_key_event_flag)
        SL_LOG("POC", "ptt_key_event_flag create failed!");

    // 网络初始化 (SIM检测 → 驻网 → 拨号)
    int heartbeat_ret = lte_tcpudp_heartbeat_start();
    int network_ret = ql_network_init();
    SL_LOG("NW", "init ret=%d heartbeat_task_ret=%d", network_ret, heartbeat_ret);

    // 等待 Broad SDK 初始化完成（由 shanli kernel 的 broad_kernel_init 自动完成）
    int wait_count = 0;
    while (!broad_get_init_status())
    {
        wait_count++;
        if (wait_count > 120)
        {
            SL_LOG("POC", "ERROR: Broad init timeout (%d seconds)", wait_count);
            g_poc_fail_reason = POC_FAIL_BROAD_INIT;
        }
        if (wait_count % 10 == 0)
        {
            SL_LOG("POC", "Waiting for Broad SDK init... (%d s)", wait_count);
        }
        ql_rtos_task_sleep_s(1);
    }
    SL_LOG("POC", "Broad SDK initialized");

    // 音频子系统初始化
    ql_audio_init();

    // 配置 Broad SDK 并登录（网络 + Broad SDK 都就绪）
    ui_init();

    // 音量设为最大 (broad SDK 音量范围 0~10)
    broad_set_vol(BND_VOICE, 0); // 接收对讲语音音量（听别人说话），10 过响降到 6
    broad_set_vol(BND_TTS, 2);   // broad TTS 提示音（当前群组/未登录等）音量调低，5 仍偏响继续降到 2
    broad_set_vol(BND_TONE, 10);

    // 初始化 MCU 串口通信模块
    e02t_uart_mcu_init();

#if E02T_BLE_GROUP_ENABLE
    // 初始化 BLE 群组功能（超时定时器）
    e02t_ble_group_init();
#endif

#if POC_INTERCOM_LOGIN_ENABLE
    { // 启动 6s 登录超时检测任务（若未登录则向 MCU 上报失败原因）
        void *timeout_task = NULL;
        ql_rtos_task_create(&timeout_task, 2048, 50, "login_timeout", login_timeout_task, NULL);
    }
#else
    (void)login_timeout_task; /* referenced to avoid unused-function warning */
#endif

    // 初始化基站定位模块（GPS 任务 LBS 回退需要）
    // TODO: 暂时关闭 LBS，测试验证 GPS 是否正常
    printf("[POC] calling cell_locator_init()...\r\n");
    int cell_ret = cell_locator_init();
    printf("[POC] cell_locator_init() returned %d\r\n", cell_ret);
    // printf("[POC] LBS disabled for GPS testing\r\n");
    // ql_app_log("[LOC][LBS] DISABLED for GPS testing");

    // ======= 事件驱动主循环 =======
    // 与 corget 版本完全一致的防抖 + 统一事件处理逻辑
    while (1)
    {
        event = 0;
        int ret = ql_rtos_flag_wait(
            ptt_key_event_flag, QL_PTTKEY_MASK_FLAG, QL_FLAG_OR_CLEAR, &event, POC_HEARTBEAT_MS);

#if !POC_INTERCOM_LOGIN_ENABLE
        if (event)
        {
            SL_LOG("PTT", "ignored in TCP/UDP test mode");
            event = 0; /* Do not enable the PA for a paused intercom session. */
        }
#endif

        // 逻辑A: 物理引脚触发 (机械按键防抖)
        if (event & QL_PTTKEY_CHANGE_FLAG)
        {
            ql_rtos_task_sleep_ms(20);

            PIN_LEVEL_E value;
            ql_gpio_get_level(CORGET_POC_PTT_PIN, &value);

            SL_LOG("PTT",
                   "SETTLED GPIO=%s state=%d",
                   (value == PIN_LEVEL_LOW) ? "LOW(pressed)" : "HIGH(released)",
                   ptt_is_pressed);

            if (value == PIN_LEVEL_LOW)
            {
                event |= QL_PTTKEY_PRESS_FLAG;
            }
            else if (value == PIN_LEVEL_HIGH)
            {
                event |= QL_PTTKEY_RELEASE_FLAG;
            }
        }

        // 逻辑B: 统一处理 PTT 按下 (GPIO 或 UART)
        if ((event & QL_PTTKEY_PRESS_FLAG) && ptt_is_pressed == 0)
        {
            ptt_is_pressed = 1;
            pa_set_level(1);

            SL_LOG("PTT", ">>> PRESS (Event 0x%lx)", (unsigned long)event);
            poc_start_speak();
        }
        // 逻辑C: 统一处理 PTT 松开 (GPIO 或 UART)
        else if ((event & QL_PTTKEY_RELEASE_FLAG) && ptt_is_pressed == 1)
        {
            ptt_is_pressed = 0;
            SL_LOG("PTT", ">>> RELEASE (Event 0x%lx)", (unsigned long)event);
            poc_stop_speak();
            // 不手动拉低 PA，让 SDK 的 pa_cb 回调来控制
            // 手动拉低会中断正在收听的音频
        }

        // 超时无事件时发送心跳
        if (POC_INTERCOM_LOGIN_ENABLE && ret != 0 && g_login_ok)
        {
            // 电量/信号每 POC_TERM_INFO_EVERY 次心跳才查一次并上报
            if (++heartbeat_cnt >= POC_TERM_INFO_EVERY)
            {
                heartbeat_cnt = 0;

                e02t_uart_query_battery_async();   // 发起查询（非阻塞）
                int bat = e02t_uart_get_battery(); // 读取上次缓存结果
                int sig = get_signal_level();
                if (bat > 0)
                {
                    SL_LOG("PING", "battery=%d signal=%d, reporting", bat, sig);
                    broad_set_terminal_info(bat, sig);
                }
                else
                {
                    SL_LOG("PING", "battery cache empty (%d), skip report", bat);
                }
            }

            // 保活心跳保持每个周期都发，平台靠它判断终端在线
            broad_send_ping();
        }
    }

    ql_rtos_task_delete(NULL);
}

application_init(shanli_poc_main_task, "shanliPocMain", 8, 201);

// =========================================================================
// 硬件引脚初始化任务 (保留自 corget 版本，已验证)
// =========================================================================
static void example_eint_test(void *argv)
{
    int ret = -1;

    // PA 使能引脚，默认拉低
    ql_gpio_init(AUDIO_PA_CONTRL_PIN, 1, 0, 0);
    ql_gpio_set_direction(AUDIO_PA_CONTRL_PIN, 1);
    ql_gpio_set_level(AUDIO_PA_CONTRL_PIN, 0);

    // PTT 按键引脚，输入 + 内部上拉
    ql_gpio_init(CORGET_POC_PTT_PIN, 0, 1, 1);
    ql_gpio_set_direction(CORGET_POC_PTT_PIN, 0);
    ql_gpio_set_pull(CORGET_POC_PTT_PIN, 1);
    ql_gpio_set_level(CORGET_POC_PTT_PIN, 1);

    // 注册 PTT 按键中断 (双边沿)
    ret =
        ql_eint_register(CORGET_POC_PTT_PIN, PIN_BOTH_EDGE, PIN_PULL_PU, ptt_key_irq_handler, NULL);
    ql_eint_enable(CORGET_POC_PTT_PIN, PIN_BOTH_EDGE);
}

application_init(example_eint_test, "example_eint_test", 2, 0);
