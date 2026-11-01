/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ql_application.h"
#include "ql_uart.h"
#include "ql_rtos.h"
#include "ql_nw.h"
#include "ql_sim.h"
#include "ql_data_call.h"
#include "ql_dev.h"
#include "ql_ping.h"
#include "fs/ql_fs.h"
#include "lwipv4v6/netdb.h"
#include "lwipv4v6/inet6.h"
#include "production_test.h"
#include "e02t_uart_mcu.h"
#include "e02t_board_cfg.h"
#include "gps_test.h"
#include "ql_audio.h"
#include "interface/log/inc/ql_log.h"
#include "ql_gpio.h"
#include "version.h"
#define PROD_LOG(fmt, args...) printf("[PROD] " fmt "\r\n", ##args)
static void prod_log_data(const char *tag, const char *data)
{
    char buf[128];
    int i = 0, j = 0;
    int prev_was_sep = 0;
    while (data[i] && j < (int)sizeof(buf) - 4)
    {
        if (data[i] == '\r' || data[i] == '\n')
        {
            if (!prev_was_sep && j > 0)
            {
                buf[j++] = ' ';
                buf[j++] = '|';
                buf[j++] = ' ';
                prev_was_sep = 1;
            }
            i++;
            continue;
        }
        buf[j++] = data[i++];
        prev_was_sep = 0;
    }
    while (j > 0 && (buf[j - 1] == ' ' || buf[j - 1] == '|'))
    {
        j--;
    }
    buf[j] = '\0';
    printf("[PROD] %s [%s]\r\n", tag, buf);
}
#define PROFILE_IDX 1
#define CONFIG_TMP_PATH "U:/config.tmp"
#define CONFIG_FILE_PATH "U:/config.ini"
#define CONFIG_BACKUP_PATH "U:/config.bak"
#define USB_RX_BUF_SIZE 2048
#define USB_TX_BUF_SIZE 2048
#define USB_LINE_BUF_SIZE 256
#define MCU_RX_BUF_SIZE 256
#define VALUE_BUF_SIZE 128
#define PING_TIMEOUT_MS 4000
#define MCU_TIMEOUT_MS 3000
static ql_mutex_t g_prod_mutex;
static ql_mutex_t g_tx_mutex;
static ql_sem_t ping_sem;
static ql_queue_t prod_cmd_queue = NULL;
static ql_queue_t prod_key_queue = NULL;
#define PROD_KEY_QUEUE_DEPTH 16
static char usb_rx_buffer[USB_RX_BUF_SIZE];
static char usb_line_buffer[USB_LINE_BUF_SIZE];
static int usb_line_len = 0;
#define PROD_CMD_MAX_SIZE 60
typedef struct
{
    int len;
    char data[PROD_CMD_MAX_SIZE];
} prod_cmd_msg_t;
static char mcu_rx_buffer[MCU_RX_BUF_SIZE];
static int mcu_rx_len = 0;
static volatile int g_mcu_waiting_response = 0;
static volatile int g_key_test_active = 0;
static prod_mode_t g_prod_mode = PROD_MODE_DISABLED;
static int g_cfg_session_active = 0;
static int g_usb_initialized = 0;
static ql_ping_stat_t g_ping_stat;
static int g_ping_result = -1;
static int g_ping_finished = 0;
static void send_to_pc(const char *text)
{
    if (text == NULL)
    {
        return;
    }
    prod_log_data("4G->PC ", text);
    ql_rtos_mutex_lock(g_tx_mutex, QL_WAIT_FOREVER);
    ql_uart_write(QL_USB_CDC_PORT, (unsigned char *)text, strlen(text));
    ql_rtos_mutex_unlock(g_tx_mutex);
}
static void send_to_pc_fmt(const char *fmt, ...)
{
    char buf[USB_TX_BUF_SIZE];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    prod_log_data("4G->PC ", buf);
    ql_rtos_mutex_lock(g_tx_mutex, QL_WAIT_FOREVER);
    ql_uart_write(QL_USB_CDC_PORT, (unsigned char *)buf, strlen(buf));
    ql_rtos_mutex_unlock(g_tx_mutex);
}
static void reply_ok(const char *tag)
{
    send_to_pc_fmt("+%s:OK\r\nOK\r\n", tag);
}
static void reply_err(const char *tag, const char *reason)
{
    send_to_pc_fmt("+%s:ERR,%s\r\nERROR\r\n", tag, reason);
}
static void trim_line_end(char *text)
{
    int len;
    if (text == NULL)
    {
        return;
    }
    len = strlen(text);
    while (len > 0 && (text[len - 1] == '\r' || text[len - 1] == '\n' || text[len - 1] == ' ' || text[len - 1] == '\t'))
    {
        text[len - 1] = '\0';
        len--;
    }
}
static int extract_quoted_value(const char *cmd, char *out, int out_len)
{
    const char *start;
    const char *end;
    int len;
    start = strchr(cmd, '"');
    if (start == NULL)
    {
        return -1;
    }
    start++;
    end = strrchr(start, '"');
    if (end == NULL || end < start)
    {
        return -1;
    }
    len = end - start;
    if (len >= out_len)
    {
        len = out_len - 1;
    }
    memcpy(out, start, len);
    out[len] = '\0';
    return 0;
}
static const char *rat_to_str(QL_NW_ACCESS_TECHNOLOGY rat)
{
    switch (rat)
    {
    case QL_NW_ACCESS_TECH_GSM:
    case QL_NW_ACCESS_TECH_GSM_COMPACT:
    case QL_NW_ACCESS_TECH_GSM_wEGPRS:
        return "GSM";
    case QL_NW_ACCESS_TECH_UTRAN:
    case QL_NW_ACCESS_TECH_UTRAN_wHSDPA:
    case QL_NW_ACCESS_TECH_UTRAN_wHSUPA:
    case QL_NW_ACCESS_TECH_UTRAN_wHSDPA_HSUPA:
    case QL_NW_ACCESS_TECH_UTRAN_HSPAP:
        return "WCDMA";
    case QL_NW_ACCESS_TECH_E_UTRAN:
    case QL_NW_ACCESS_TECH_E_UTRAN_CA:
        return "LTE";
    default:
        return "UNK";
    }
}
void production_enter_mode(void)
{
    ql_rtos_mutex_lock(g_prod_mutex, QL_WAIT_FOREVER);
    g_prod_mode = PROD_MODE_ENABLED;
    ql_rtos_mutex_unlock(g_prod_mutex);
}
void production_exit_mode(void)
{
    ql_rtos_mutex_lock(g_prod_mutex, QL_WAIT_FOREVER);
    g_prod_mode = PROD_MODE_DISABLED;
    ql_rtos_mutex_unlock(g_prod_mutex);
}
int production_is_enabled(void)
{
    int enabled;
    ql_rtos_mutex_lock(g_prod_mutex, QL_WAIT_FOREVER);
    enabled = (g_prod_mode == PROD_MODE_ENABLED);
    ql_rtos_mutex_unlock(g_prod_mutex);
    return enabled;
}
static int ensure_data_call(char *ip_buf, int ip_buf_len)
{
    struct ql_data_call_info info = {0};
    if (ql_network_register_wait(120) != 0)
    {
        return -1;
    }
    ql_wan_start(NULL);
    ql_set_auto_connect(PROFILE_IDX, TRUE);
    if (ql_start_data_call(PROFILE_IDX, 0, NULL, NULL, NULL, 0) != 0)
    {
        return -1;
    }
    if (ql_get_data_call_info(PROFILE_IDX, 0, &info) != 0)
    {
        return -1;
    }
    if (ip_buf != NULL && ip_buf_len > 0)
    {
        inet_ntop(AF_INET, &info.v4.addr.ip, ip_buf, ip_buf_len);
    }
    return info.v4.state == 1 ? 0 : -1;
}
static void ping_callback(ql_ping_state_e state, int err, ql_ping_stat_t *statistic)
{
    if (state == QL_PING_FINISHED)
    {
        if (statistic != NULL)
        {
            memcpy(&g_ping_stat, statistic, sizeof(g_ping_stat));
        }
        g_ping_result = err;
        g_ping_finished = 1;
        ql_rtos_semaphore_release(ping_sem);
    }
}
static int run_ping_test(const char *host, int count, ql_ping_stat_t *stat)
{
    ql_ping_ctx_t *ctx;
    ql_ping_cfg_t cfg;
    /* Drain any leftover semaphore signals from previous ping */
    while (ql_rtos_semaphore_wait(ping_sem, 0) == 0)
    {
    }
    memset(&cfg, 0, sizeof(cfg));
    memset(&g_ping_stat, 0, sizeof(g_ping_stat));
    g_ping_result = -1;
    g_ping_finished = 0;
    cfg.pdpCid = PROFILE_IDX;
    cfg.host = (char *)host;
    cfg.timeout = PING_TIMEOUT_MS;
    cfg.dataSize = 32;
    cfg.pingNum = count;
    cfg.thoughWiFi = 0;
    ctx = ql_ping_init(cfg, ping_callback);
    if (ctx == NULL)
    {
        return -1;
    }
    if (ql_ping(ctx) != 0)
    {
        ql_ping_deinit(ctx);
        return -1;
    }
    int wait_ms = 5000 + (PING_TIMEOUT_MS + 1000) * count;
    if (ql_rtos_semaphore_wait(ping_sem, wait_ms) != 0)
    {
        ql_ping_deinit(ctx);
        return -1;
    }
    if (stat != NULL)
    {
        memcpy(stat, &g_ping_stat, sizeof(*stat));
    }
    ql_ping_deinit(ctx);
    return g_ping_result;
}
static int read_operator_name(char *buf, int len)
{
    QL_NW_OPERATOR_INFO_T oper;
    memset(&oper, 0, sizeof(oper));
    if (ql_nw_get_operator_name(&oper) != 0)
    {
        return -1;
    }
    if (oper.long_eons[0] != '\0')
    {
        snprintf(buf, len, "%s", oper.long_eons);
    }
    else if (oper.short_eons[0] != '\0')
    {
        snprintf(buf, len, "%s", oper.short_eons);
    }
    else
    {
        snprintf(buf, len, "%s%s", oper.mcc, oper.mnc);
    }
    return 0;
}
static int test_4g_signal(module_info_t *info)
{
    QL_NW_SIGNAL_STRENGTH_INFO_T sig;
    memset(&sig, 0, sizeof(sig));
    if (ql_nw_get_signal_strength(&sig) != 0)
    {
        return -1;
    }
    info->signal_rssi = sig.LTE_SignalStrength.rssi;
    info->signal_rsrp = sig.LTE_SignalStrength.rsrp;
    info->signal_rsrq = sig.LTE_SignalStrength.rsrq;
    info->signal_sinr = sig.LTE_SignalStrength.sinr;
    return 0;
}
static int test_4g_sim(char *sim_status, int len)
{
    int sim_state;
    if (ql_sim_get_card_status(&sim_state) != 0)
    {
        snprintf(sim_status, len, "ERR");
        return -1;
    }
    switch (sim_state)
    {
    case QL_SIM_STATUS_READY:
        snprintf(sim_status, len, "READY");
        return 0;
    case QL_SIM_STATUS_NOT_INSERTED:
        snprintf(sim_status, len, "NOSIM");
        return -1;
    default:
        snprintf(sim_status, len, "UNK");
        return -1;
    }
}
static int test_4g_network(QL_NW_REG_STATUS_INFO_T *reg_info)
{
    memset(reg_info, 0, sizeof(*reg_info));
    if (ql_nw_get_reg_status(reg_info) != 0)
    {
        return -1;
    }
    if (reg_info->data_reg.state == QL_NW_REG_STATE_HOME_NETWORK ||
        reg_info->data_reg.state == QL_NW_REG_STATE_ROAMING)
    {
        return 0;
    }
    return -1;
}
static int get_4g_module_info(module_info_t *info)
{
    memset(info, 0, sizeof(*info));
    if (ql_dev_get_imei(info->imei, sizeof(info->imei)) != 0)
    {
        return -1;
    }
    if (ql_sim_get_iccid(info->iccid, sizeof(info->iccid)) != 0)
    {
        snprintf(info->iccid, sizeof(info->iccid), "N/A");
    }
    if (ql_sim_get_imsi(info->imsi, sizeof(info->imsi)) != 0)
    {
        snprintf(info->imsi, sizeof(info->imsi), "N/A");
    }
    if (ql_dev_get_firmware_version(info->fw_version, sizeof(info->fw_version)) != 0)
    {
        snprintf(info->fw_version, sizeof(info->fw_version), "UNK");
    }
    return 0;
}
static int validate_config_file(void)
{
    QFILE *fp;
    char line[VALUE_BUF_SIZE];
    char *trim;
    fp = ql_fopen(CONFIG_TMP_PATH, "r");
    if (fp == NULL)
    {
        return -1;
    }
    while (ql_fgets(line, sizeof(line), fp) != NULL)
    {
        trim = line;
        while (*trim == ' ' || *trim == '\t')
        {
            trim++;
        }
        trim_line_end(trim);
        if (*trim == '\0' || *trim == '#')
        {
            continue;
        }
        if (strchr(trim, '=') == NULL)
        {
            ql_fclose(fp);
            return -1;
        }
    }
    ql_fclose(fp);
    return 0;
}
static int start_config_session(void)
{
    QFILE *fp;
    ql_remove(CONFIG_TMP_PATH);
    fp = ql_fopen(CONFIG_TMP_PATH, "w+");
    if (fp == NULL)
    {
        return -1;
    }
    ql_fclose(fp);
    g_cfg_session_active = 1;
    return 0;
}
static int append_config_line(const char *line)
{
    QFILE *fp;
    if (!g_cfg_session_active)
    {
        return -1;
    }
    fp = ql_fopen(CONFIG_TMP_PATH, "a+");
    if (fp == NULL)
    {
        return -1;
    }
    if (ql_fputs(line, fp) < 0 || ql_fputc('\n', fp) < 0)
    {
        ql_fclose(fp);
        return -1;
    }
    ql_fclose(fp);
    return 0;
}
static int save_config_session(void)
{
    g_cfg_session_active = 0;
    if (validate_config_file() != 0)
    {
        return -1;
    }
    ql_remove(CONFIG_BACKUP_PATH);
    if (ql_access(CONFIG_FILE_PATH, 0) == 0)
    {
        ql_rename(CONFIG_FILE_PATH, CONFIG_BACKUP_PATH);
    }
    if (ql_rename(CONFIG_TMP_PATH, CONFIG_FILE_PATH) != 0)
    {
        return -1;
    }
    return 0;
}
static int read_config_lines(void)
{
    QFILE *fp;
    char line[VALUE_BUF_SIZE];
    fp = ql_fopen(CONFIG_FILE_PATH, "r");
    if (fp == NULL)
    {
        return -1;
    }
    while (ql_fgets(line, sizeof(line), fp) != NULL)
    {
        trim_line_end(line);
        send_to_pc_fmt("+CFGREAD:%s\r\n", line);
    }
    ql_fclose(fp);
    send_to_pc("OK\r\n");
    return 0;
}
static int send_config_info(void)
{
    QFILE *fp;
    char line[VALUE_BUF_SIZE];
    int size = 0;
    char version[64] = "UNKNOWN";
    if (ql_access(CONFIG_FILE_PATH, 0) != 0)
    {
        send_to_pc("+CFGINFO:EXIST=0,SIZE=0,VERSION=UNKNOWN\r\nOK\r\n");
        return 0;
    }
    fp = ql_fopen(CONFIG_FILE_PATH, "r");
    if (fp == NULL)
    {
        return -1;
    }
    size = ql_fsize(fp);
    ql_frewind(fp);
    while (ql_fgets(line, sizeof(line), fp) != NULL)
    {
        if (strncmp(line, "version=", 8) == 0)
        {
            trim_line_end(line);
            snprintf(version, sizeof(version), "%s", line + 8);
            break;
        }
    }
    ql_fclose(fp);
    send_to_pc_fmt("+CFGINFO:EXIST=1,SIZE=%d,VERSION=%s\r\nOK\r\n", size, version);
    return 0;
}
static int mcu_send_and_wait(const char *cmd, char *response, int resp_len, int timeout_ms)
{
    int wait_ms = 0;
    if (!e02t_uart_mcu_is_ready())
    {
        PROD_LOG("MCU UART not ready, skip: %s", cmd);
        return -1;
    }
    mcu_rx_len = 0;
    mcu_rx_buffer[0] = '\0';
    g_mcu_waiting_response = 1;
    prod_log_data("4G->MCU", cmd);
    e02t_uart_send_to_mcu(cmd);
    while (wait_ms < timeout_ms)
    {
        if (mcu_rx_len > 0)
        {
            int copy_len = (mcu_rx_len < resp_len - 1) ? mcu_rx_len : (resp_len - 1);
            memcpy(response, mcu_rx_buffer, copy_len);
            response[copy_len] = '\0';
            trim_line_end(response);
            mcu_rx_len = 0;
            mcu_rx_buffer[0] = '\0';
            g_mcu_waiting_response = 0;
            prod_log_data("MCU->4G", response);
            return copy_len;
        }
        ql_rtos_task_sleep_ms(20);
        wait_ms += 20;
    }
    g_mcu_waiting_response = 0;
    PROD_LOG("MCU->4G timeout (%dms)", timeout_ms);
    return -2;
}
static int production_mcu_line_handler(const char *line)
{
    int len;
    if (line == NULL)
    {
        return 0;
    }
    len = strlen(line);
    if (len <= 0)
    {
        return 0;
    }
    if (g_key_test_active && strncmp(line, "!KEY:", 5) == 0)
    {
        prod_cmd_msg_t msg;
        int copy_len = len;
        if (copy_len >= (int)sizeof(msg.data))
        {
            copy_len = sizeof(msg.data) - 1;
        }
        memcpy(msg.data, line, copy_len);
        msg.data[copy_len] = '\0';
        msg.len = copy_len;
        ql_rtos_queue_release(prod_key_queue, sizeof(msg), (u8 *)&msg, QL_NO_WAIT);
        return 1;
    }
    if (!g_mcu_waiting_response)
    {
        return 0;
    }
    if (mcu_rx_len > 0)
    {
        return 1;
    }
    if (len >= MCU_RX_BUF_SIZE)
    {
        len = MCU_RX_BUF_SIZE - 1;
    }
    memcpy(mcu_rx_buffer, line, len);
    mcu_rx_buffer[len] = '\0';
    mcu_rx_len = len;
    return 1;
}
static void bridge_mcu_cmd(const char *tag, const char *mcu_cmd)
{
    char response[MCU_RX_BUF_SIZE];
    int ret;
    ret = mcu_send_and_wait(mcu_cmd, response, sizeof(response), MCU_TIMEOUT_MS);
    if (ret == -2)
    {
        reply_err(tag, "TIMEOUT");
        return;
    }
    if (ret < 0)
    {
        reply_err(tag, "IO");
        return;
    }
    if (strncmp(response, "+", 1) == 0)
    {
        char *colon = strchr(response, ':');
        if (colon != NULL)
        {
            send_to_pc_fmt("+%s:%s\r\nOK\r\n", tag, colon + 1);
            return;
        }
    }
    if (strcmp(response, "OK") == 0)
    {
        reply_ok(tag);
        return;
    }
    reply_err(tag, "FMT");
}
static void handle_modem_info(void)
{
    module_info_t info;
    if (get_4g_module_info(&info) != 0)
    {
        reply_err("MDINFO", "FAIL");
        return;
    }
    send_to_pc_fmt("+MDINFO:IMEI=%s\r\n", info.imei);
    send_to_pc_fmt("+MDINFO:ICCID=%s\r\n", info.iccid);
    send_to_pc_fmt("+MDINFO:IMSI=%s\r\n", info.imsi);
    send_to_pc_fmt("+MDINFO:FW=%s\r\n", info.fw_version);
    send_to_pc("OK\r\n");
}
static void handle_modem_sim(void)
{
    char status[32];
    if (test_4g_sim(status, sizeof(status)) == 0)
    {
        send_to_pc_fmt("+MDSIM:%s\r\nOK\r\n", status);
    }
    else
    {
        send_to_pc_fmt("+MDSIM:ERR,%s\r\nERROR\r\n", status);
    }
}
static void handle_modem_reg(void)
{
    QL_NW_REG_STATUS_INFO_T reg_info;
    char oper[64] = "UNK";
    if (test_4g_network(&reg_info) != 0)
    {
        reply_err("MDREG", "NET");
        return;
    }
    read_operator_name(oper, sizeof(oper));
    send_to_pc_fmt("+MDREG:CREG=%d,CGREG=%d,COPS=%s,RAT=%s\r\nOK\r\n",
                   reg_info.voice_reg.state,
                   reg_info.data_reg.state,
                   oper,
                   rat_to_str(reg_info.data_reg.rat));
}
static void handle_modem_sig(void)
{
    module_info_t info;
    memset(&info, 0, sizeof(info));
    if (test_4g_signal(&info) != 0)
    {
        reply_err("MDSIG", "FAIL");
        return;
    }
    send_to_pc_fmt("+MDSIG:CSQ=%d,RSRP=%d,RSRQ=%d,SINR=%d\r\nOK\r\n",
                   info.signal_rssi,
                   info.signal_rsrp,
                   info.signal_rsrq,
                   info.signal_sinr);
}
static void handle_modem_data(void)
{
    char ip[32] = {0};
    if (ensure_data_call(ip, sizeof(ip)) != 0)
    {
        reply_err("MDDATA", "NET");
        return;
    }
    send_to_pc_fmt("+MDDATA:STATE=UP,IP=%s\r\nOK\r\n", ip);
}
static void handle_modem_dns(const char *cmd)
{
    struct hostent *host;
    char host_name[128];
    char ip[32];
    struct in_addr addr;

    if (extract_quoted_value(cmd, host_name, sizeof(host_name)) != 0)
    {
        reply_err("MDDNS", "ARG");
        return;
    }

    if (ensure_data_call(NULL, 0) != 0)
    {
        reply_err("MDDNS", "NET");
        return;
    }

    host = gethostbyname(host_name);
    if (host == NULL || host->h_addr_list == NULL || host->h_addr_list[0] == NULL)
    {
        reply_err("MDDNS", "DNS");
        return;
    }

    memcpy(&addr, host->h_addr_list[0], sizeof(addr));
    inet_ntop(AF_INET, &addr, ip, sizeof(ip));
    send_to_pc_fmt("+MDDNS:HOST=%s,IP=%s\r\nOK\r\n", host_name, ip);
}

static void handle_modem_ping(const char *cmd)
{
    char value[128];
    char *comma;
    char host[128];
    int count;
    ql_ping_stat_t stat;

    if (extract_quoted_value(cmd, value, sizeof(value)) != 0)
    {
        reply_err("MDPING", "ARG");
        return;
    }

    snprintf(host, sizeof(host), "%s", value);
    comma = strrchr(cmd, ',');
    count = 4;
    if (comma != NULL)
    {
        count = atoi(comma + 1);
        if (count <= 0)
        {
            count = 4;
        }
    }

    if (ensure_data_call(NULL, 0) != 0)
    {
        reply_err("MDPING", "NET");
        return;
    }

    memset(&stat, 0, sizeof(stat));
    if (run_ping_test(host, count, &stat) != 0)
    {
        reply_err("MDPING", "PING");
        return;
    }

    send_to_pc_fmt("+MDPING:SENT=%d,RCV=%d,LOSS=%d,AVG=%d\r\nOK\r\n",
                   stat.sentNum,
                   stat.rcvdNum,
                   stat.lostNum,
                   stat.avgRtt);
}

static void handle_modem_all(void)
{
    char sim_status[32];
    QL_NW_REG_STATUS_INFO_T reg_info;
    char ip[32] = {0};

    test_4g_sim(sim_status, sizeof(sim_status));
    test_4g_network(&reg_info);
    ensure_data_call(ip, sizeof(ip));

    send_to_pc_fmt("+MDALL:SIM=%s,REG=%s,SIG=%s,DATA=%s,PING=SKIP\r\nOK\r\n",
                   strcmp(sim_status, "READY") == 0 ? "OK" : "FAIL",
                   (reg_info.data_reg.state == QL_NW_REG_STATE_HOME_NETWORK || reg_info.data_reg.state == QL_NW_REG_STATE_ROAMING) ? "OK" : "FAIL",
                   "OK",
                   ip[0] != '\0' ? "OK" : "FAIL");
}

/* =========================================================================
 * Module MIC test (mode B: MIC -> speaker loopback)
 *
 * Records PCM from the module's on-board codec MIC and writes it straight
 * back to the audio track (speaker via 4G PA), so an operator can speak into
 * the mic and hear it from the speaker -- validates the whole mic+codec+PA
 * audio path without a PC-side judge.
 *
 * Runs in its own task because the loopback blocks; the worker task must stay
 * free to receive AT+MDMIC=0 (stop). Shared by the AT command and the boot
 * self-test below.
 * ========================================================================= */

#define MIC_LOOP_RATE 16000
#define MIC_LOOP_CHANNELS 2
#define MIC_LOOP_FRAME_MS 20
#define MIC_LOOP_VOLUME 7 /* 回环专用音量(正常对讲=11), 太高会啸叫 */
#define MIC_LOOP_TRACK_OPT 0x100
#define SELFTEST_MIC_LOOP_MS 16000

static volatile int g_mic_loop_stop = 0;
static volatile int g_mic_loop_running = 0;

static void prod_pa_set(int on)
{
    /* Mirror POC pa_set_level(): the audible speaker amp on E02T is the
     * external PA behind the MCU, so toggling only the 4G GPIO is not enough.
     * MCU notify is best-effort -- if the MCU UART is not up yet (e.g. during
     * the early boot self-test) we still drive the 4G PA pin. */
    if (on)
    {
        ql_gpio_set_level(AUDIO_PA_CONTRL_PIN, PIN_LEVEL_HIGH);
        if (e02t_uart_mcu_is_ready())
        {
            e02t_uart_send_to_mcu("AT+PA=OPEN\r\n");
            printf("[PROD] PA ON: 4G GPIO high + sent AT+PA=OPEN to MCU\r\n");
        }
        else
        {
            printf("[PROD] PA ON: 4G GPIO high only (MCU not ready, AT+PA=OPEN skipped)\r\n");
        }
    }
    else
    {
        if (e02t_uart_mcu_is_ready())
        {
            e02t_uart_send_to_mcu("AT+PA=CLOSE\r\n");
            printf("[PROD] PA OFF: sent AT+PA=CLOSE to MCU + 4G GPIO low\r\n");
            ql_rtos_task_sleep_ms(50);
        }
        else
        {
            printf("[PROD] PA OFF: 4G GPIO low only (MCU not ready, AT+PA=CLOSE skipped)\r\n");
        }
        ql_gpio_set_level(AUDIO_PA_CONTRL_PIN, PIN_LEVEL_LOW);
    }
}

/* Run the MIC->speaker loopback. duration_ms<=0 runs until g_mic_loop_stop
 * is set (AT-triggered); duration_ms>0 runs for that long (boot self-test). */
static void mic_loopback_core(int duration_ms)
{
    audio_track_handle track_hd;
    audio_record_handle record_hd;
    char *buf;
    unsigned int frame_len;
    unsigned int bytes_per_sec;
    unsigned long long target_bytes = 0;
    unsigned long long done_bytes = 0;
    u32 start_tick;
    u32 max_ticks = 0;
    if (g_mic_loop_running)
    {
        return;
    }
    while (!ql_get_audio_state())
    {
        ql_rtos_task_sleep_ms(50);
    }
    frame_len = (MIC_LOOP_CHANNELS * MIC_LOOP_RATE * 2 * MIC_LOOP_FRAME_MS) / 1000;
    buf = malloc(frame_len);
    if (buf == NULL)
    {
        printf("[PROD] MIC loopback: malloc(%u) failed\r\n", frame_len);
        return;
    }
    g_mic_loop_running = 1;
    ql_codec_choose(AUD_INTERNAL_CODEC, NULL);
    {
        int saved_vol = ql_get_volume();
        ql_set_volume(MIC_LOOP_VOLUME);
        ql_set_audio_path_receiver();
        /* PA GPIO 已由 POC example_eint_test 初始化，不复调 init/direction */
        prod_pa_set(1);
        track_hd = ql_audio_track_open(MIC_LOOP_RATE, MIC_LOOP_CHANNELS, MIC_LOOP_TRACK_OPT, NULL);
        record_hd = ql_audio_record_open(MIC_LOOP_RATE, MIC_LOOP_CHANNELS, 0, NULL);
        printf("[PROD] MIC loopback: running (dur=%dms)\r\n", duration_ms);
        /* Duration is measured by the amount of audio actually pushed to the
         * speaker (bytes written), not by loop-iteration count -- a read that
         * returns empty/short must not shorten the audible time. Guarantees
         * duration_ms worth of PCM reaches the track. */
        bytes_per_sec = MIC_LOOP_RATE * MIC_LOOP_CHANNELS * 2;
        if (duration_ms > 0)
        {
            target_bytes = (unsigned long long)duration_ms * bytes_per_sec / 1000;
            /* Safety backstop ~2x duration (~5ms/tick, approximate; only guards a
             * dead capture path, precision does not matter). */
            max_ticks = (u32)((unsigned long long)duration_ms * 2 / 5);
        }
        start_tick = ql_rtos_get_systicks();
        while (!g_mic_loop_stop)
        {
            unsigned int read_len = frame_len;
            if (ql_audio_record_read(record_hd, buf, &read_len) == 0 && read_len > 0)
            {
                ql_audio_track_write(track_hd, buf, read_len);
                done_bytes += read_len;
            }
            else
            {
                ql_rtos_task_sleep_ms(5);
            }
            if (duration_ms > 0)
            {
                if (done_bytes >= target_bytes)
                {
                    break;
                }
                if (max_ticks && (ql_rtos_get_systicks() - start_tick) >= max_ticks)
                {
                    printf("[PROD] MIC loopback: safety timeout, played ~%u ms\r\n",
                           (unsigned)(done_bytes * 1000 / bytes_per_sec));
                    break;
                }
            }
        }
        ql_set_volume(saved_vol);
    }
    prod_pa_set(0);
    ql_audio_track_close(track_hd, 0);
    ql_audio_record_close(record_hd, 0);
    free(buf);
    g_mic_loop_stop = 0;
    g_mic_loop_running = 0;
    printf("[PROD] MIC loopback: stopped\r\n");
}
static void mic_loopback_task(void *argv)
{
    (void)argv;
    mic_loopback_core(0);
    ql_rtos_task_delete(NULL);
}
static void handle_mic_loop(const char *cmd)
{
    void *task_ref = NULL;
    if (strcmp(cmd, "AT+MDMIC=1") == 0)
    {
        if (g_mic_loop_running)
        {
            reply_err("MDMIC", "BUSY");
            return;
        }
        g_mic_loop_stop = 0;
        ql_rtos_task_create(&task_ref, 4096, 50, "prod_mic", mic_loopback_task, NULL);
        reply_ok("MDMIC");
    }
    else if (strcmp(cmd, "AT+MDMIC=0") == 0)
    {
        g_mic_loop_stop = 1;
        reply_ok("MDMIC");
    }
    else
    {
        reply_err("MDMIC", "ARG");
    }
}
/* =========================================================================
 * Module PTT test (AT+MDPTT)
 *
 * The PTT button connects directly to the 4G module GPIO. During production
 * test we only verify the physical press/release action, not the intercom
 * flow (login is disabled). A dedicated task polls the GPIO with software
 * debounce and reports state changes as URC (+MDPTT:PRESS / RELEASE).
 * ========================================================================= */
#define PTT_POLL_MS 20
#define PTT_DEBOUNCE_MS 150
static volatile int g_ptt_test_active = 0;
static void ptt_test_task(void *argv)
{
    PIN_LEVEL_E last_stable = PIN_LEVEL_HIGH; /* default: released (pull-up) */
    int debounce_cnt = 0;
    (void)argv;
    printf("[PROD] PTT test: monitoring GPIO\r\n");
    while (g_ptt_test_active)
    {
        PIN_LEVEL_E level;
        ql_rtos_task_sleep_ms(PTT_POLL_MS);
        ql_gpio_get_level(CORGET_POC_PTT_PIN, &level);
        if (level == last_stable)
        {
            debounce_cnt = 0;
            continue;
        }
        debounce_cnt++;
        if (debounce_cnt * PTT_POLL_MS >= PTT_DEBOUNCE_MS)
        {
            last_stable = level;
            debounce_cnt = 0;
            if (level == PIN_LEVEL_LOW)
            {
                send_to_pc("+MDPTT:PRESS\r\n");
                printf("[PROD] PTT: PRESS\r\n");
            }
            else
            {
                send_to_pc("+MDPTT:RELEASE\r\n");
                printf("[PROD] PTT: RELEASE\r\n");
            }
        }
    }
    printf("[PROD] PTT test: stopped\r\n");
    ql_rtos_task_delete(NULL);
}
static void handle_modem_ptt(const char *cmd)
{
    void *task_ref = NULL;
    if (strcmp(cmd, "AT+MDPTT=1") == 0)
    {
        if (g_ptt_test_active)
        {
            reply_err("MDPTT", "BUSY");
            return;
        }
        g_ptt_test_active = 1;
        ql_rtos_task_create(&task_ref, 2048, 50, "prod_ptt", ptt_test_task, NULL);
        reply_ok("MDPTT");
    }
    else if (strcmp(cmd, "AT+MDPTT=0") == 0)
    {
        g_ptt_test_active = 0;
        reply_ok("MDPTT");
    }
    else
    {
        reply_err("MDPTT", "ARG");
    }
}
/* =========================================================================
 * Module GPS test (AT+MDGPS)
 *
 * The external GNSS chip on QL_U4_UART_PORT is owned by the driver's
 * quec_uart_gps task; production does not open that UART. Instead it drives
 * the task via the gps_test_* API (see gps_test.h): AT+MDGPS=1 powers GPS on
 * and keeps it streaming, AT+MDGPS? returns a live snapshot for PC polling,
 * AT+MDGPS=0 powers it off. Pass/fail (satellites/SNR/fix vs threshold and
 * timeout) is judged PC-side.
 * ========================================================================= */
static void handle_modem_gps(const char *cmd)
{
    if (strcmp(cmd, "AT+MDGPS=1") == 0)
    {
        gps_test_start();
        reply_ok("MDGPS");
    }
    else if (strcmp(cmd, "AT+MDGPS=0") == 0)
    {
        gps_test_stop();
        reply_ok("MDGPS");
    }
    else if (strcmp(cmd, "AT+MDGPS?") == 0)
    {
        gps_test_snapshot_t s;
        int i;
        gps_test_get(&s);
        /* 摘要行：定位状态 + 参与定位星数 + 精度 + 坐标 */
        send_to_pc_fmt("+MDGPS:FIX=%d,USED=%d,HDOP=%.1f,LAT=%.6f,LON=%.6f\r\n",
                       s.fix, s.used, s.hdop, s.lat, s.lon);
        /* 逐星行：每颗可见星一条 +MDGPSSAT:PRN,SNR */
        for (i = 0; i < s.sat_count && i < GPS_MAX_SATS; i++)
        {
            if (s.sats[i].snr >= 0)
            {
                send_to_pc_fmt("+MDGPSSAT:%d,%d\r\n",
                               s.sats[i].prn, s.sats[i].snr);
            }
        }
        send_to_pc("OK\r\n");
    }
    else
    {
        reply_err("MDGPS", "ARG");
    }
}
static void handle_command(const char *cmd)
{
    char line[VALUE_BUF_SIZE];
    if (strcmp(cmd, "AT+PROD=1") == 0)
    {
        char response[MCU_RX_BUF_SIZE];
        int ret;
        production_enter_mode();
        ret = mcu_send_and_wait("AT+PROD=1\r\n", response, sizeof(response), MCU_TIMEOUT_MS);
        if (ret >= 0)
        {
            send_to_pc("+PROD:OK,MCU=OK\r\nOK\r\n");
        }
        else
        {
            send_to_pc("+PROD:OK,MCU=TIMEOUT\r\nOK\r\n");
        }
    }
    else if (strcmp(cmd, "AT+PROD=0") == 0)
    {
        char response[MCU_RX_BUF_SIZE];
        int ret;
        if (g_key_test_active)
        {
            g_key_test_active = 0;
            mcu_send_and_wait("AT+KEY=0\r\n", response, sizeof(response), MCU_TIMEOUT_MS);
        }
        gps_test_stop();
        if (g_ptt_test_active)
        {
            g_ptt_test_active = 0;
        }
        g_mic_loop_stop = 1;
        production_exit_mode();
        ret = mcu_send_and_wait("AT+PROD=0\r\n", response, sizeof(response), MCU_TIMEOUT_MS);
        if (ret >= 0)
        {
            send_to_pc("+PROD:OK,MCU=OK\r\nOK\r\n");
        }
        else
        {
            send_to_pc("+PROD:OK,MCU=TIMEOUT\r\nOK\r\n");
        }
    }
    else if (strcmp(cmd, "AT+CAP?") == 0)
    {
        send_to_pc("+CAP:PRODUCT=E02T,CONFIG=1,PRODUCTION=1,MCU=1\r\nOK\r\n");
    }
    else if (strcmp(cmd, "AT+VER?") == 0)
    {
        send_to_pc_fmt("+VER:APP=%s,DATE=%s,BRANCH=%s\r\nOK\r\n",
                       GIT_VERSION, GIT_COMMIT_DATE, GIT_BRANCH);
    }
    else if (strcmp(cmd, "AT+DEV?") == 0)
    {
        send_to_pc("+DEV:MODEL=EC800MCN_LE\r\nOK\r\n");
    }
    else if (strcmp(cmd, "AT+CFGINFO?") == 0)
    {
        if (send_config_info() != 0)
        {
            reply_err("CFGINFO", "FS");
        }
    }
    else if (strcmp(cmd, "AT+CFGSTART") == 0)
    {
        if (start_config_session() != 0)
        {
            reply_err("CFGSTART", "FS");
        }
        else
        {
            reply_ok("CFGSTART");
        }
    }
    else if (strncmp(cmd, "AT+CFGSET=", 10) == 0)
    {
        if (extract_quoted_value(cmd, line, sizeof(line)) != 0)
        {
            reply_err("CFGSET", "ARG");
        }
        else if (append_config_line(line) != 0)
        {
            reply_err("CFGSET", "IO");
        }
        else
        {
            reply_ok("CFGSET");
        }
    }
    else if (strcmp(cmd, "AT+CFGSAVE") == 0)
    {
        if (save_config_session() != 0)
        {
            reply_err("CFGSAVE", "FMT");
        }
        else
        {
            reply_ok("CFGSAVE");
        }
    }
    else if (strcmp(cmd, "AT+CFGREAD?") == 0)
    {
        if (read_config_lines() != 0)
        {
            reply_err("CFGREAD", "FS");
        }
    }
    else if (strcmp(cmd, "AT+CFGDEF") == 0)
    {
        ql_remove(CONFIG_FILE_PATH);
        ql_remove(CONFIG_TMP_PATH);
        ql_remove(CONFIG_BACKUP_PATH);
        reply_ok("CFGDEF");
    }
    else if (strcmp(cmd, "AT+MDINFO?") == 0)
    {
        handle_modem_info();
    }
    else if (strcmp(cmd, "AT+MDSIM?") == 0)
    {
        handle_modem_sim();
    }
    else if (strcmp(cmd, "AT+MDREG?") == 0)
    {
        handle_modem_reg();
    }
    else if (strcmp(cmd, "AT+MDSIG?") == 0)
    {
        handle_modem_sig();
    }
    else if (strcmp(cmd, "AT+MDDATA?") == 0)
    {
        handle_modem_data();
    }
    else if (strncmp(cmd, "AT+MDDNS=", 9) == 0)
    {
        handle_modem_dns(cmd);
    }
    else if (strncmp(cmd, "AT+MDPING=", 10) == 0)
    {
        handle_modem_ping(cmd);
    }
    else if (strcmp(cmd, "AT+MDALL?") == 0)
    {
        handle_modem_all();
    }
    else if (strncmp(cmd, "AT+MDMIC=", 9) == 0)
    {
        handle_mic_loop(cmd);
    }
    else if (strncmp(cmd, "AT+MDGPS", 8) == 0)
    {
        handle_modem_gps(cmd);
    }
    else if (strncmp(cmd, "AT+MDPTT=", 9) == 0)
    {
        handle_modem_ptt(cmd);
    }
    else if (strcmp(cmd, "AT+MCURST") == 0)
    {
        bridge_mcu_cmd("MCURST", "AT+RST\r\n");
    }
    else if (strcmp(cmd, "AT+MCUBVER?") == 0)
    {
        bridge_mcu_cmd("MCUBVER", "AT+BVER?\r\n");
    }
    else if (strcmp(cmd, "AT+MCULED=1") == 0)
    {
        bridge_mcu_cmd("MCULED", "AT+LED=1\r\n");
    }
    else if (strcmp(cmd, "AT+MCULED=0") == 0)
    {
        bridge_mcu_cmd("MCULED", "AT+LED=0\r\n");
    }
    else if (strcmp(cmd, "AT+MCUMAC?") == 0)
    {
        bridge_mcu_cmd("MCUMAC", "AT+MAC?\r\n");
    }
    else if (strcmp(cmd, "AT+MCUCHG?") == 0)
    {
        bridge_mcu_cmd("MCUCHG", "AT+CHG?\r\n");
    }
    else if (strcmp(cmd, "AT+MCUVBAT?") == 0)
    {
        bridge_mcu_cmd("MCUVBAT", "AT+VBAT?\r\n");
    }
    else if (strcmp(cmd, "AT+MCUFBMIC=1") == 0)
    {
        bridge_mcu_cmd("MCUFBMIC", "AT+FBMIC=1\r\n");
    }
    else if (strcmp(cmd, "AT+MCUFBMIC=0") == 0)
    {
        bridge_mcu_cmd("MCUFBMIC", "AT+FBMIC=0\r\n");
    }
    else if (strcmp(cmd, "AT+MCUPMIC=1") == 0)
    {
        bridge_mcu_cmd("MCUPMIC", "AT+PMIC=1\r\n");
    }
    else if (strcmp(cmd, "AT+MCUPMIC=0") == 0)
    {
        bridge_mcu_cmd("MCUPMIC", "AT+PMIC=0\r\n");
    }
    else if (strcmp(cmd, "AT+MCUKEY=1") == 0)
    {
        bridge_mcu_cmd("MCUKEY", "AT+KEY=1\r\n");
        g_key_test_active = 1;
    }
    else if (strcmp(cmd, "AT+MCUKEY=0") == 0)
    {
        g_key_test_active = 0;
        bridge_mcu_cmd("MCUKEY", "AT+KEY=0\r\n");
    }
    else if (strcmp(cmd, "AT+MCUGAUGE") == 0)
    {
        bridge_mcu_cmd("MCUGAUGE", "AT+GAUGE\r\n");
    }
    else if (strncmp(cmd, "AT+MCUTIME=", 11) == 0)
    {
        char time_value[64];
        char mcu_cmd[96];
        if (extract_quoted_value(cmd, time_value, sizeof(time_value)) != 0)
        {
            reply_err("MCUTIME", "ARG");
        }
        else
        {
            snprintf(mcu_cmd, sizeof(mcu_cmd), "AT+TIME=\"%s\"\r\n", time_value);
            bridge_mcu_cmd("MCUTIME", mcu_cmd);
        }
    }
    else if (strncmp(cmd, "AT+MCURAW=", 10) == 0)
    {
        char raw[128];
        char mcu_cmd[160];
        if (extract_quoted_value(cmd, raw, sizeof(raw)) != 0)
        {
            reply_err("MCURAW", "ARG");
        }
        else
        {
            snprintf(mcu_cmd, sizeof(mcu_cmd), "%s\r\n", raw);
            bridge_mcu_cmd("MCURAW", mcu_cmd);
        }
    }
    else
    {
        reply_err("CMD", "UNSUP");
    }
}
static int is_always_allowed(const char *cmd)
{
    return strcmp(cmd, "AT+CAP?") == 0 ||
           strcmp(cmd, "AT+VER?") == 0 ||
           strcmp(cmd, "AT+DEV?") == 0 ||
           strcmp(cmd, "AT+PROD=1") == 0 ||
           strcmp(cmd, "AT+PROD=0") == 0;
}
static void production_worker_task(void *argv)
{
    prod_cmd_msg_t msg;
    while (1)
    {
        if (ql_rtos_queue_wait(prod_cmd_queue, (u8 *)&msg, sizeof(msg), QL_WAIT_FOREVER) == 0)
        {
            if (msg.len < 0)
            {
                PROD_LOG("PC->4G  [<over-length, rejected>]");
                reply_err("CMD", "TOOLONG");
                continue;
            }
            msg.data[sizeof(msg.data) - 1] = '\0';
            PROD_LOG("PC->4G  [%s]", msg.data);
            if (is_always_allowed(msg.data) || production_is_enabled())
            {
                handle_command(msg.data);
            }
            else
            {
                reply_err("CMD", "MODE");
            }
        }
    }
}
static void production_key_task(void *argv)
{
    prod_cmd_msg_t msg;
    while (1)
    {
        if (ql_rtos_queue_wait(prod_key_queue, (u8 *)&msg, sizeof(msg), QL_WAIT_FOREVER) == 0)
        {
            msg.data[sizeof(msg.data) - 1] = '\0';
            if (strncmp(msg.data, "!KEY:", 5) == 0 && g_key_test_active)
            {
                char *payload = msg.data + 5;
                char *comma = strchr(payload, ',');
                if (comma != NULL)
                {
                    *comma = '\0';
                    send_to_pc_fmt("+MCUKEY:KEY=%s,STATE=%s\r\n", payload, comma + 1);
                }
            }
        }
    }
}
static void usb_cdc_rx_callback(QL_UART_PORT_NUMBER_E port, void *para)
{
    int len;
    int i;
    len = ql_uart_read(port, (unsigned char *)usb_rx_buffer, sizeof(usb_rx_buffer) - 1);
    if (len <= 0)
    {
        return;
    }
    for (i = 0; i < len; ++i)
    {
        char ch = usb_rx_buffer[i];
        if (ch == '\r' || ch == '\n')
        {
            if (usb_line_len > 0)
            {
                usb_line_buffer[usb_line_len] = '\0';
                /* Only accept "AT" command lines. Echoed responses
                 * (+XXX/OK/ERROR) and stray bytes do not start with AT, so
                 * they are ignored here -- this breaks the USB CDC echo loop
                 * without a send-time window that would drop legitimate
                 * back-to-back commands from the PC tool. */
                if ((usb_line_buffer[0] == 'A' || usb_line_buffer[0] == 'a') &&
                    (usb_line_buffer[1] == 'T' || usb_line_buffer[1] == 't'))
                {
                    prod_cmd_msg_t msg;
                    memset(&msg, 0, sizeof(msg));
                    if (usb_line_len >= PROD_CMD_MAX_SIZE)
                    {
                        /* Line does not fit the queue message; reject it
                         * explicitly (len < 0 sentinel) instead of silently
                         * truncating and forwarding a corrupt command. */
                        msg.len = -1;
                    }
                    else
                    {
                        msg.len = usb_line_len;
                        snprintf(msg.data, sizeof(msg.data), "%s", usb_line_buffer);
                    }
                    ql_rtos_queue_release(prod_cmd_queue, sizeof(msg), (u8 *)&msg, QL_NO_WAIT);
                }
            }
            usb_line_len = 0;
            continue;
        }
        if (usb_line_len < USB_LINE_BUF_SIZE - 1)
        {
            usb_line_buffer[usb_line_len++] = ch;
        }
    }
}
void production_test_init(void)
{
    void *task_ref = NULL;
    int ret;
    if (g_usb_initialized)
    {
        return;
    }
    ql_log_mask_set(QL_LOG_APP_MASK, QL_LOG_PORT_USB);
    printf("[PROD] step1: create sync primitives\r\n");
    ql_rtos_mutex_create(&g_prod_mutex);
    ql_rtos_mutex_create(&g_tx_mutex);
    ql_rtos_semaphore_create(&ping_sem, 0);
    printf("[PROD] step2: open USB CDC\r\n");
    ret = ql_uart_open(QL_USB_CDC_PORT, QL_UART_BAUD_115200, QL_FC_NONE);
    printf("[PROD] step2: USB CDC open ret=%d\r\n", ret);
    printf("[PROD] step3: create queue, elem_size=%d\r\n", (int)sizeof(prod_cmd_msg_t));
    ret = ql_rtos_queue_create(&prod_cmd_queue, sizeof(prod_cmd_msg_t), 8);
    printf("[PROD] step3: queue create ret=%d, ptr=%p\r\n", ret, (void *)prod_cmd_queue);
    if (ret != 0 || prod_cmd_queue == NULL)
    {
        printf("[PROD] queue create FAILED\r\n");
        g_usb_initialized = 1;
        return;
    }
    printf("[PROD] step3b: create key queue, depth=%d\r\n", PROD_KEY_QUEUE_DEPTH);
    ret = ql_rtos_queue_create(&prod_key_queue, sizeof(prod_cmd_msg_t), PROD_KEY_QUEUE_DEPTH);
    printf("[PROD] step3b: key queue create ret=%d, ptr=%p\r\n", ret, (void *)prod_key_queue);
    if (ret != 0 || prod_key_queue == NULL)
    {
        printf("[PROD] key queue create FAILED\r\n");
        g_usb_initialized = 1;
        return;
    }
    printf("[PROD] step4: register callbacks\r\n");
    ql_uart_register_cb(QL_USB_CDC_PORT, usb_cdc_rx_callback);
    e02t_uart_register_line_handler(production_mcu_line_handler);
    printf("[PROD] step5: create worker tasks\r\n");
    ql_rtos_task_create(&task_ref, 4096, 50, "prod_worker", production_worker_task, NULL);
    ql_rtos_task_create(&task_ref, 4096, 50, "prod_key", production_key_task, NULL);
    g_usb_initialized = 1;
    printf("[PROD] init complete, ready\r\n");
}
void production_test_task(void *argv)
{
    (void)argv;
    printf("[PROD] task entry\r\n");
    production_test_init();
    printf("[PROD] init done\r\n");
    ql_rtos_task_delete(NULL);
}
application_init(production_test_task, "prod_test", 4, 10);
/* =========================================================================
 * Boot self-test
 *
 * Runs once at power-up, independent of the PC / production-mode gate, so the
 * device audio path can be sanity-checked on the bench without any PC tool.
 * Currently exercises the module MIC -> speaker loopback for a fixed window;
 * add further self-checks here as needed.
 *
 * Set PROD_SELFTEST_ON_BOOT to 0 to disable in field builds.
 * ========================================================================= */
#define PROD_SELFTEST_ON_BOOT 0
#if PROD_SELFTEST_ON_BOOT
#define SELFTEST_MCU_WAIT_MS 60000
static void production_selftest_task(void *argv)
{
    int wait = 0;
    (void)argv;
    printf("[PROD] ================================================\r\n");
    printf("[PROD] ===== SELFTEST TASK STARTED (MIC loopback) =====\r\n");
    printf("[PROD] ================================================\r\n");
    /* The audible amp is the MCU-side external PA, opened via AT+PA=OPEN.
     * e02t_uart_mcu_init() only runs late in the POC boot flow (after network
     * + Broad init), so wait (bounded) for the MCU UART to come up first --
     * otherwise prod_pa_set() would skip the AT+PA notify and the loopback
     * would be silent. If the MCU never comes up we still run best-effort. */
    printf("[PROD] selftest: waiting for MCU UART ready (max %dms)...\r\n", SELFTEST_MCU_WAIT_MS);
    while (!e02t_uart_mcu_is_ready() && wait < SELFTEST_MCU_WAIT_MS)
    {
        ql_rtos_task_sleep_ms(200);
        wait += 200;
        if (wait % 5000 == 0)
        {
            printf("[PROD] selftest: still waiting for MCU... (%dms)\r\n", wait);
        }
    }
    printf("[PROD] selftest: mcu_ready=%d after %dms\r\n",
           e02t_uart_mcu_is_ready(), wait);
    printf("[PROD] selftest: MIC loopback start (%dms), speak into mic now\r\n", SELFTEST_MIC_LOOP_MS);
    g_mic_loop_stop = 0;
    mic_loopback_core(SELFTEST_MIC_LOOP_MS);
    printf("[PROD] ===== SELFTEST DONE (MIC loopback) =====\r\n");
    ql_rtos_task_delete(NULL);
}
application_init(production_selftest_task, "prod_selftest", 4, 10);
#endif

/* =========================================================================
 * GPS boot quick-test
 *
 * Set PROD_SELFTEST_GPS_ON_BOOT to 1 to power on GPS at boot and print raw
 * NMEA + parsed summary via ql_app_log continuously. Purely for bench
 * verification — not for production line use. GPS stays on for the fixed
 * duration then auto-stops.
 * ========================================================================= */
#define PROD_SELFTEST_GPS_ON_BOOT 0
#define SELFTEST_GPS_DURATION_MS 300000 /* GPS 自测持续 5 分钟 */

#if PROD_SELFTEST_GPS_ON_BOOT
static void production_selftest_gps_task(void *argv)
{
    gps_test_snapshot_t s;
    int elapsed = 0;

    (void)argv;

    /* Let the GPS task (priority 20) finish poc_sys_init() */
    ql_rtos_task_sleep_ms(2000);

    printf("[PROD] selftest GPS: starting (%dms)\r\n", SELFTEST_GPS_DURATION_MS);
    gps_test_start();

    /* Just let it stream — GPS task prints raw NMEA + summary via ql_app_log.
     * Poll once per second and print a heartbeat. */
    while (elapsed < SELFTEST_GPS_DURATION_MS)
    {
        ql_rtos_task_sleep_ms(5000);
        elapsed += 5000;
        gps_test_get(&s);
        printf("[PROD] selftest GPS: FIX=%d SATS=%d (elapsed %ds)\r\n",
               s.fix, s.sat_count, elapsed / 1000);
    }

    gps_test_stop();
    printf("[PROD] selftest GPS: done\r\n");
    ql_rtos_task_delete(NULL);
}

application_init(production_selftest_gps_task, "prod_gps_test", 4, 10);
#endif