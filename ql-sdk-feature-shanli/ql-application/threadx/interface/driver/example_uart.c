
/*==========================================================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
===========================================================================================================*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ql_rtos.h"
#include "ql_application.h"
#include "ql_log.h"
#include "ql_uart.h"
#include "type.h"
#include "ql_gpio.h"
#include "broad.h"
#include "e02t_board_cfg.h"
#include "gps_test.h"

#define test_log(fmt, args...) printf(fmt, ##args)

#define QL_GPS_FLAG 		(0x01<<0)
#define QL_TIMER_FLAG 		(0x01<<1)
#define QL_GPS_CTRL_FLAG 	(0x01<<2)
#define QL_GPS_MASK_FLAG 	(QL_GPS_FLAG|QL_TIMER_FLAG|QL_GPS_CTRL_FLAG)
#define POC_GPS_TIMER  			(240 * 1000)
#define GPS_DEFAULT_INTERVAL	(30)
#define CHR_NUM  		1024
char r_data[CHR_NUM];
NMEA_Data gps_data;
NMEA_Data *g_nmea_data =&gps_data;
void *uart_event_flag = NULL;
ql_timer_t poc_timer_handle;
static int gps_gpio_status =0;
extern volatile int g_login_ok;
extern int cell_locator_query(float *lng, float *lat);
volatile int g_is_gps_open = 0;
volatile int g_gps_report_rate = GPS_DEFAULT_INTERVAL;
volatile int g_gps_test_active = 0;             /* 产测 GPS 模式标志 */
static volatile u32 g_gps_last_nmea_tick = 0;   /* 最近一次收到 NMEA 的 systick */

#define GPS_MIN_SLEEP_S      30

/* ===== GPS 省电：失败退避 + GPS/LBS 解耦 =====
 * 场景1(网好 GPS 好): 每轮 冷启动定位→上传→睡 max(上报周期,30s)，行为不变。
 * 场景2(网好 GPS 差): 室内/地库连续定不到位——
 *   一级退避(失败1~2次): 每轮仍开 GNSS 120s，失败后 LBS 兜底，睡 60s；
 *   LBS 模式(失败≥3次) : GNSS 不再每轮空烧，只每 GPS_PROBE_EVERY 轮探测一次，
 *     LBS 独立按 ~2 分钟上报一次；LBS 坐标明显变化(设备在移动，很可能正开出
 *     地库)时立即触发 GNSS 探测，加快恢复。
 * 场景3(未登录): GNSS 断电，每 30s 重判登录；登录恢复后退避清零，从头开始。
 * 定位成功 fail_cnt 立即清零，回到场景1 的正常节奏。
 * 注: 本产品 GNSS 每次上电都是冷启动(星历失效)，单次开电至少留 120s；
 *     每 GPS_FULL_RETRY_EVERY 次失败额外给一次满额 240s，冷启动再慢也能自愈。
 */
#define GPS_FAIL_STAGE1_CNT   1               /* 连续失败达此数 → 一级退避 */
#define GPS_FAIL_STAGE2_CNT   3               /* 连续失败达此数 → LBS 模式 */
#define GPS_TIMEOUT_STAGE1_MS (120 * 1000)
#define GPS_TIMEOUT_STAGE2_MS (120 * 1000)    /* 冷启动下限，不能再短 */
#define GPS_SLEEP_STAGE1_S    60              /* 一级退避：休眠 60s */
#define GPS_LBS_INTERVAL_S   120              /* LBS 模式：独立上报间隔 ~2 分钟 */
#define GPS_PROBE_EVERY      5                /* LBS 模式：每 N 轮探测一次 GNSS */
#define GPS_LBS_MOVE_DEG     0.005f           /* LBS 坐标变化>此值(约500m)=在移动 */
#define GPS_OFFLINE_POLL_S    30              /* 未登录时的重判间隔 */
#define GPS_FULL_RETRY_EVERY  5               /* 每 N 次失败给一次满额 240s 兜底 */

static int g_gps_fail_cnt = 0;                /* 连续 GNSS 失败次数(成功即清零) */
static int g_lbs_cycle_cnt = 0;               /* LBS 模式轮数计数(控制探测节奏) */
static int g_lbs_cell_changed = 0;            /* LBS 坐标明显变化=在移动→触发探测 */
static float g_lbs_last_lng = 0.0f;           /* 上次 LBS 坐标(移动检测基准) */
static float g_lbs_last_lat = 0.0f;
static int g_lbs_have_last = 0;               /* 是否已有 LBS 历史坐标 */

/* 本轮定位应使用的超时(毫秒) */
static int gps_fix_timeout_ms(void)
{
	if (g_gps_fail_cnt >= GPS_FAIL_STAGE2_CNT)
	{
		/* 退避到最短档后，每 GPS_FULL_RETRY_EVERY 次失败给一次满额机会，
		 * 防止冷启动较慢导致环境已恢复却永远定不到位 */
		if ((g_gps_fail_cnt % GPS_FULL_RETRY_EVERY) == 0)
			return POC_GPS_TIMER;
		return GPS_TIMEOUT_STAGE2_MS;
	}
	if (g_gps_fail_cnt >= GPS_FAIL_STAGE1_CNT)
		return GPS_TIMEOUT_STAGE1_MS;
	return POC_GPS_TIMER;
}

/* 本轮之后的休眠秒数(不小于平台要求的上报周期) */
static int gps_sleep_s(void)
{
	int base = g_gps_report_rate > GPS_MIN_SLEEP_S ? g_gps_report_rate : GPS_MIN_SLEEP_S;

	if (g_gps_fail_cnt >= GPS_FAIL_STAGE2_CNT)
		return base > GPS_LBS_INTERVAL_S ? base : GPS_LBS_INTERVAL_S;
	if (g_gps_fail_cnt >= GPS_FAIL_STAGE1_CNT)
		return base > GPS_SLEEP_STAGE1_S ? base : GPS_SLEEP_STAGE1_S;
	return base;
}
double str_to_double(const char *str)
{    
	double res = 0.0; 
	double sign = 1.0;
	double div = 1.0;  

	if(!str) 
		return 0.0;  
	if(*str == '-') 
	{ 
		sign = -1.0; 
		str++; 
	}    

	while(*str >= '0' && *str <= '9') 
	{        
		res = res * 10.0 + (double)(*str - '0');        
		str++;    
	}    

	if(*str == '.') 
	{        
		str++;        
		while(*str >= '0' && *str <= '9') 
		{            
			div *= 10.0;            
			res += (double)(*str - '0') / div;            
			str++;        
		}    
	}    
	return sign * res;
}
double nmea_to_wgs84(const char *nmea_str, char dir) 
{    
	double dmm = str_to_double(nmea_str); //  
	double degrees, minutes;    
	if (dir == 'N' || dir == 'S') 
	{        
		degrees = (int)(dmm / 100);        
		minutes = dmm - degrees * 100;    
	}    
	else {        
		degrees = (int)(dmm / 100);        
		minutes = dmm - degrees * 100;    
	}    
	double wgs84 = degrees + minutes / 60.0;    
	if (dir == 'S' || dir == 'W') 
	{        
		wgs84 = -wgs84;    
	}    
	return wgs84;
}
void parse_gnrmc(char *gnrmc_str)
{
	char *saveptr1;
	int field = 0;
    char *token = strtok_r(gnrmc_str, ",",&saveptr1);
	char buf_lat[32] = {0};
	char buf_log[32] = {0};
	
    while (token != NULL) {
        switch (field) {
              case 2: {
			g_nmea_data->rmc_status = token[0]; 
			break;
              	}		
		case 3:{
			strcpy(buf_lat,token);  
			//g_nmea_data->latitude =str_to_double(token); 
			break;
			}
		case 4:{
			g_nmea_data->lati_dir = token[0]; 
			g_nmea_data->latitude =nmea_to_wgs84(buf_lat,g_nmea_data->lati_dir);
			break;
			}
		case 5:{
			strcpy(buf_log,token); 
			//g_nmea_data->longitude = str_to_double(token); 
			break;
	     		}
		case 6:{
			g_nmea_data->longi_dir = token[0]; 
			g_nmea_data->longitude =nmea_to_wgs84(buf_log,g_nmea_data->longi_dir);
			break;
			}
            case 7:{ 
			float speed=(float)str_to_double(token);
			g_nmea_data->speed_knot = speed;
			g_nmea_data->speed_kmh = speed * 1.852f;			
			break; 
            	}
            case 8:{ 
			g_nmea_data->course = (float)str_to_double(token); 
			break; 
            	}
            case 9:{ 
			strncpy(g_nmea_data->rmc_date, token,7); 
			break; 
            	}
            case 13:{ 
			strncpy(g_nmea_data->rmc_mode, token, 3); 
			break;
            	}
            default: 
			break;
        }
        token = strtok_r(NULL, ",",&saveptr1);
        field++;   		
    }
    
}

void parse_gngga(char *gngga_str)
{
	char *saveptr2;
	int field = 0;

    	char *token = strtok_r(gngga_str, ",",&saveptr2);
     
    while (token != NULL) {			
        switch (field) {
            case 1: 
			strncpy(g_nmea_data->gga_time, token, 15); 
			break;		
            case 3: 
			g_nmea_data->lati_dir = token[0]; 
			break;
            case 5: 
			g_nmea_data->longi_dir = token[0]; 
			break;		
            case 6: 
			g_nmea_data->fix_quality = atoi(token); 
			break;
            case 7: 
			g_nmea_data->sat_count = atoi(token); 
			break;
            case 8: 
			g_nmea_data->hdop = str_to_double(token); 
			break;
            case 9: 
			g_nmea_data->altitude = str_to_double(token); 
			break;
            case 11: 
			g_nmea_data->geo_sep = str_to_double(token); 
			break;
            default: 
			break;
        }
        token = strtok_r(NULL, ",",&saveptr2);
        field++;
    }

}


/* GSV 逐星累加器，每次 parse_nmea 起始清零 */
static gps_sat_snr_t s_raw_sats[GPS_MAX_SATS];
static int s_raw_sat_cnt = 0;
static int s_raw_sat_seen = 0;       /* 本次是否收到过 $GxGSV 句 */
static int s_raw_sat_cur_prn = 0;    /* 当前正在组装的那颗星的 PRN */

/* 解析一条 $GxGSV：每颗星占 4 字段(prn,elev,azim,snr)，从 field 4 起。
 * 同组中 PRN 在 field 4/8/12/16，SNR 在 field 7/11/15/19。
 * 只有 SNR 非空(>='0')的星才收入累加器。
 *
 * NMEA GSV 允许任意字段为空（如 SNR 空串 ",,"），strtok_r 会把连续
 * 分隔符合并处理导致字段序号错位。这里用逐字符遍历：每遇到一个','就
 * 切换字段号，空字段正常计数，序号保持绝对正确。 */
void parse_gsv(char *gsv_str)
{
    char *s = gsv_str;
    int field = 0;

    s_raw_sat_cur_prn = 0;  /* 每条 GSV 起始清零，防止跨星座 PRN 污染 */

    while (*s) {
        char *tok;
        char saved;

        /* 跳过行尾字符（来自 buf 拷贝的残余） */
        if (*s == '\r' || *s == '\n') { s++; continue; }

        tok = s;
        while (*s && *s != ',' && *s != '*' && *s != '\r' && *s != '\n') s++;

        saved = *s;
        *s = '\0';   /* 临时断尾，让 atoi 可用 */

        if (field >= 4) {
            int pos = (field - 4) % 4;
            if (pos == 0 && *tok) {
                s_raw_sat_cur_prn = atoi(tok);
            } else if (pos == 3) {
                /* SNR 字段：非空、首字符数字、且前面捕获到有效 PRN 才收入 */
                if (*tok >= '0' && *tok <= '9' && s_raw_sat_cur_prn > 0 && s_raw_sat_cnt < GPS_MAX_SATS) {
                    s_raw_sats[s_raw_sat_cnt].prn = s_raw_sat_cur_prn;
                    s_raw_sats[s_raw_sat_cnt].snr = atoi(tok);
                    s_raw_sat_cnt++;
                }
            }
        }

        field++;

        if (saved == ',') {
            *s = ',';  /* 复原，让调用者看到的字符串不变 */
            s++;
        } else {
            /* '*' checksum / '\0' 结束 / 行尾 → 停 */
            break;
        }
    }
}


void parse_nmea(const char *nmea_str) {

	char *saveptr;
    char buffer[2048] = {0};   /* 多星座满星 GSV 可达 1200B+ */
    char buf_gmc[256] = {0};
    char buf_gma[256] = {0};

    g_nmea_data->is_valid = 0;

    memset(s_raw_sats, 0, sizeof(s_raw_sats));
    s_raw_sat_cnt = 0;
    s_raw_sat_seen = 0;
    s_raw_sat_cur_prn = 0;

    strncpy(buffer, nmea_str, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    char *line = strtok_r(buffer, "\n",&saveptr);
    while (line != NULL) {
        line[strcspn(line, "\r\n")] = 0;
	if(*line == 0)
	{
		line = strtok_r(NULL, "\n",&saveptr);
		continue;
	}
        if (strncmp(line, "$GNRMC",6) == 0) {
		strncpy(buf_gmc, line, sizeof(buf_gmc) - 1);
		buf_gmc[sizeof(buf_gmc) - 1] = '\0';
            parse_gnrmc(buf_gmc);
        } else if (strncmp(line, "$GNGGA",6) == 0) {
		strncpy(buf_gma, line, sizeof(buf_gma) - 1);
		buf_gma[sizeof(buf_gma) - 1] = '\0';
            parse_gngga(buf_gma);
        } else if (strlen(line) >= 6 && line[0] == '$' && strncmp(line + 3, "GSV", 3) == 0) {
            char buf_gsv[256] = {0};
            s_raw_sat_seen = 1;
            ql_app_log("[GPS] GSV: %s", line);
            strncpy(buf_gsv, line, sizeof(buf_gsv) - 1);
            buf_gsv[sizeof(buf_gsv) - 1] = '\0';
            parse_gsv(buf_gsv);
        }

        line = strtok_r(NULL, "\n",&saveptr);
    }

    /* 收到 GSV 才更新逐星数据；无 GSV 分包则保留旧值。 */
    if (s_raw_sat_seen) {
        int i;
        g_nmea_data->raw_sat_count = s_raw_sat_cnt;
        for (i = 0; i < GPS_MAX_SATS; i++) {
            if (i < s_raw_sat_cnt) {
                g_nmea_data->raw_sats[i] = s_raw_sats[i];
            } else {
                g_nmea_data->raw_sats[i].prn = 0;
                g_nmea_data->raw_sats[i].snr = -1;
            }
        }
    }

    if (g_nmea_data->rmc_status == 'A' && g_nmea_data->fix_quality >= 1) {
        g_nmea_data->is_valid = 1;
    }else{
		// printf("hecsion invalid gps data\r\n");
	}


}
static void poc_handle_timer_callback(void *ctx)
{
	ql_rtos_flag_release(uart_event_flag, QL_TIMER_FLAG, QL_FLAG_OR);
	
	return;
}
static void gps_power_en(bool b_en)
{
	gps_gpio_status=b_en;
	if(b_en)
	{
		ql_app_log("[LOC][GPS] power ON");
		ql_gpio_init(GNSS_RSTN_PIN,1, 2, 1);
		ql_gpio_set_level(GNSS_RSTN_PIN,1);

		ql_rtos_task_sleep_ms(1);
		ql_gpio_init(GNSS_PWR_PIN,1, 2, 1);
		ql_gpio_set_level(GNSS_PWR_PIN,1);
	}
	else
	{
		ql_app_log("[LOC][GPS] power OFF");
		ql_gpio_init(GNSS_RSTN_PIN,1, 2, 1);
		ql_gpio_set_level(GNSS_RSTN_PIN,0);

		ql_rtos_task_sleep_ms(1);
		ql_gpio_init(GNSS_PWR_PIN,1, 2, 1);
		ql_gpio_set_level(GNSS_PWR_PIN,0);
	}
}
int gps_power_status()
{
	return gps_gpio_status;
}

/* ===== 产测 GPS 接口（见 gps_test.h），驱动 quec_uart_gps 任务 ===== */
int gps_test_start(void)
{
    g_gps_test_active = 1;
    /* 唤醒待机中的 GPS 任务去上电采集 */
    if (uart_event_flag) {
        ql_rtos_flag_release(uart_event_flag, QL_GPS_CTRL_FLAG, QL_FLAG_OR);
    }
    return 0;
}

int gps_test_stop(void)
{
    g_gps_test_active = 0;
    /* 唤醒任务重判标志并退出产测循环、断电 */
    if (uart_event_flag) {
        ql_rtos_flag_release(uart_event_flag, QL_GPS_CTRL_FLAG, QL_FLAG_OR);
    }
    return 0;
}

void gps_test_get(gps_test_snapshot_t *out)
{
    if (out == NULL) {
        return;
    }

    out->fix = g_nmea_data->is_valid;
    out->used = g_nmea_data->sat_count;
    out->hdop = g_nmea_data->hdop;
    out->lat = g_nmea_data->latitude;
    out->lon = g_nmea_data->longitude;
    out->sat_count = g_nmea_data->raw_sat_count;
    memcpy(out->sats, g_nmea_data->raw_sats, sizeof(out->sats));
}

static void poc_sys_init()
{
	int ret = 0;

	ql_gpio_init(GNSS_RSTN_PIN,1, 2, 1);	
	ql_gpio_set_level(GNSS_RSTN_PIN,0);

ql_rtos_task_sleep_ms(1);
	ql_gpio_init(GNSS_PWR_PIN,1, 2, 1);	
	ql_gpio_set_level(GNSS_PWR_PIN,0);	
 ql_rtos_task_sleep_ms(1);
 	
	ret = ql_rtos_flag_create(&uart_event_flag);
	if(ret != kNoErr){
		printf("ql_rtos_flag_create failed ret:%d\r\n",ret);
		return;
	}
	
	ret = ql_rtos_timer_create(&poc_timer_handle);
	if (ret != kNoErr){
		printf("create poc timer failed ret: %d\r\n", ret);
		return;		
	}
	
}

static void poc_timer_start(int timeout_ms)
{
	int ret = 0;

	ret = ql_rtos_timer_start(poc_timer_handle, timeout_ms, 0, poc_handle_timer_callback, NULL);
	if (ret != kNoErr)
	{
		printf("poc_timer start failed\r\n");
		return;
	}
}
void gps_uart_callback(QL_UART_PORT_NUMBER_E port, void* para) {
    int read_len = 0;

    memset(r_data, 0, CHR_NUM);
    read_len = ql_uart_read(port, (unsigned char *)r_data, sizeof(r_data) - 1);
    r_data[read_len > 0 ? read_len : 0] = '\0';
    if (read_len > 0) {
        g_gps_last_nmea_tick = ql_rtos_get_systicks();
    }
    ql_rtos_flag_release(uart_event_flag, QL_GPS_FLAG, QL_FLAG_OR);
}

static void quec_uart_gps(void* argv) {
    int ret = -1;
    uint32_t event;
    ql_uart_config_t dcb;
    char nmea_buf[CHR_NUM];
    int got_fix = 0;
    int fix_timeout_ms = POC_GPS_TIMER;

    poc_sys_init();
    ql_log_mask_set(QL_LOG_APP_MASK, QL_LOG_PORT_USB);

    ret = ql_uart_open(QL_U4_UART_PORT, QL_UART_BAUD_115200, QL_FC_NONE);
    if (ret) {
        test_log("open uart[%d] failed! %d \n", QL_U4_UART_PORT, ret);
        return;
    }

    ql_uart_get_dcbconfig(QL_U4_UART_PORT, &dcb);
    dcb.baudrate = QL_UART_BAUD_115200;
    ql_uart_set_dcbconfig(QL_U4_UART_PORT, &dcb);

    ql_uart_register_cb(QL_U4_UART_PORT, gps_uart_callback);

    while (1) {
        if (!g_is_gps_open && !g_gps_test_active) {
            g_gps_fail_cnt = 0;   /* 未启用定位，清空退避档位，下次启用时从正常参数开始 */
            g_lbs_cycle_cnt = 0;
            g_lbs_cell_changed = 0;
            g_lbs_have_last = 0;
#if !E02T_GPS_KEEP_ON
            gps_power_en(0);
#endif
            ql_app_log("[LOC] standby: GPS disabled, LBS inactive, waiting for platform enable");
            printf("[GPS] standby, waiting for platform enable...\r\n");
            ql_rtos_flag_wait(uart_event_flag, QL_GPS_CTRL_FLAG, QL_FLAG_OR_CLEAR, &event, QL_WAIT_FOREVER);
            continue;
        }

        /* 产测 GPS 模式：GPS 常开、持续刷新 g_nmea_data，不上传平台、不走 LBS、
         * 不因超时断电，直到 gps_test_stop() 清除 g_gps_test_active。 */
        if (g_gps_test_active) {
            gps_power_en(1);
            g_nmea_data->is_valid = 0;
            ql_app_log("[GPS] TEST mode: powered, streaming NMEA");
            while (g_gps_test_active) {
                event = 0;
                ql_rtos_flag_wait(uart_event_flag, QL_GPS_MASK_FLAG, QL_FLAG_OR_CLEAR, &event, QL_WAIT_FOREVER);
                if (event & QL_GPS_FLAG) {
                    memcpy(nmea_buf, r_data, CHR_NUM);
                    nmea_buf[CHR_NUM - 1] = '\0';
                    ql_app_log("[GPS] TEST uart4 raw data:\n%s", nmea_buf);
                    parse_nmea(nmea_buf);
                    ql_app_log("[GPS] TEST: FIX=%d USED=%d SATS=%d HDOP=%d.%d",
                               g_nmea_data->is_valid,
                               g_nmea_data->sat_count, g_nmea_data->raw_sat_count,
                               (int)g_nmea_data->hdop, (int)(g_nmea_data->hdop * 10) % 10);
                }
                /* QL_GPS_CTRL_FLAG 仅用于唤醒重判 g_gps_test_active；超时忽略 */
            }
#if !E02T_GPS_KEEP_ON
            gps_power_en(0);
#endif
            ql_app_log("[GPS] TEST mode: stopped");
            continue;
        }

        /* 未登录(无网/未上线)时定位结果也传不出去，直接断电回待机省电。
         * 用有限等待轮询而不是 QL_WAIT_FOREVER，登录成功后即可自动恢复定位。
         * 掉线期间环境/会话大概率已变化：清空退避与 LBS 状态，
         * 登录恢复后从场景1 的正常参数重新开始，不带地库里的失败历史。 */
        if (!g_login_ok) {
            g_gps_fail_cnt = 0;
            g_lbs_cycle_cnt = 0;
            g_lbs_cell_changed = 0;
            g_lbs_have_last = 0;
#if !E02T_GPS_KEEP_ON
            gps_power_en(0);
#endif
            ql_app_log("[LOC][GPS] offline (not logged in), skip fix cycle");
            printf("[GPS] not logged in, skip fix cycle, recheck in %ds\r\n", GPS_OFFLINE_POLL_S);
            ql_rtos_flag_wait(uart_event_flag, QL_GPS_CTRL_FLAG, QL_FLAG_OR_CLEAR,
                              &event, GPS_OFFLINE_POLL_S * 1000);
            continue;
        }

        /* 本轮是否开 GNSS。LBS 模式(连续失败≥GPS_FAIL_STAGE2_CNT)下 GNSS 不再
         * 每轮空烧：每 GPS_PROBE_EVERY 轮探测一次；LBS 检测到坐标明显变化
         * (设备在移动，可能正离开地库)时立即探测。其余轮跳过 GNSS 只跑 LBS。 */
        int open_gps = 1;
        if (g_gps_fail_cnt >= GPS_FAIL_STAGE2_CNT) {
            open_gps = 0;
            if (g_lbs_cell_changed) {
                open_gps = 1;              /* 移动触发：立即探测 */
                g_lbs_cell_changed = 0;
                printf("[GPS] LBS move detected, probing GNSS immediately\r\n");
            } else if (g_lbs_cycle_cnt % GPS_PROBE_EVERY == 0) {
                open_gps = 1;              /* 周期性探测 */
            }
            g_lbs_cycle_cnt++;
        }

        got_fix = 0;
        if (open_gps) {
            fix_timeout_ms = gps_fix_timeout_ms();
            gps_power_en(1);
            poc_timer_start(fix_timeout_ms);
            g_nmea_data->is_valid = 0;
            ql_app_log("[LOC][GPS] fix cycle start: timeout=%dms, rate=%ds, fail_cnt=%d",
                       fix_timeout_ms, g_gps_report_rate, g_gps_fail_cnt);
            printf("[GPS] power on, timeout=%dms, waiting for fix (rate=%ds, fail_cnt=%d)...\r\n",
                   fix_timeout_ms, g_gps_report_rate, g_gps_fail_cnt);

        while (1) {
            event = 0;
            ql_rtos_flag_wait(uart_event_flag, QL_GPS_MASK_FLAG, QL_FLAG_OR_CLEAR, &event, QL_WAIT_FOREVER);

            if (event & QL_GPS_CTRL_FLAG) {
                if (!g_is_gps_open) {
                    printf("[GPS] platform disabled mid-fix, powering off\r\n");
                    break;
                }
            }

            if (event & QL_GPS_FLAG) {
                memcpy(nmea_buf, r_data, CHR_NUM);
                nmea_buf[CHR_NUM - 1] = '\0';
                // printf("[GPS] uart4 raw data:\r\n%s\r\n", nmea_buf);
                parse_nmea(nmea_buf);
                    // printf("[GPS] TEST: FIX=%d USED=%d SATS=%d HDOP=%d.%d",
                    //        g_nmea_data->is_valid,
                    //        g_nmea_data->sat_count, g_nmea_data->raw_sat_count,
                    //        (int)g_nmea_data->hdop, (int)(g_nmea_data->hdop * 10) % 10);
                if (g_nmea_data->is_valid) {
                    printf("[GPS] valid fix, uploading...\r\n");
                    got_fix = 1;
                    if (g_login_ok) {
                        bnd_time_t gps_now;
                        broad_current_zone_time(&gps_now, 0);
                        ql_app_log("[LOC][GPS] upload: lon=%.6f, lat=%.6f, alt=%.1f, spd=%.1f, crs=%.1f",
                                   g_nmea_data->longitude, g_nmea_data->latitude,
                                   g_nmea_data->altitude, g_nmea_data->speed_knot, g_nmea_data->course);
                        broad_send_gpsinfo(
                            g_nmea_data->longitude,
                            g_nmea_data->latitude,
                            gps_now,
                            g_nmea_data->altitude,
                            g_nmea_data->speed_knot,
                            g_nmea_data->course);
                        printf("[GPS] upload done\r\n");
                    }
                    break;
                }
            }

            if (event & QL_TIMER_FLAG) {
                ql_app_log("[LOC][GPS] timeout (%dms), no valid fix", fix_timeout_ms);
                printf("[GPS] timeout (%dms), no valid fix\r\n", fix_timeout_ms);
                break;
            }
        }

            ql_rtos_timer_stop(poc_timer_handle);
        } else {
            /* LBS 模式下的纯 LBS 轮：GNSS 保持断电，直接走下面的 LBS 上报 */
            printf("[GPS] LBS mode: skip GNSS this round (cycle=%d), LBS only\r\n", g_lbs_cycle_cnt);
            ql_app_log("[LOC][GPS] LBS mode round, GNSS skipped");
        }
#if !E02T_GPS_KEEP_ON
        gps_power_en(0);
#endif

        if (!g_is_gps_open) {
            printf("[GPS] disabled, back to standby\r\n");
            continue;
        }

        printf("[GPS] power off done. got_fix=%d, g_login_ok=%d, g_is_gps_open=%d\r\n",
               got_fix, g_login_ok, g_is_gps_open);
        ql_app_log("[LOC] cycle done: source=%s, got_fix=%d, login=%d, gps_open=%d",
                   got_fix ? "GPS" : "NONE", got_fix, g_login_ok, g_is_gps_open);

        if (got_fix) {
            g_gps_fail_cnt = 0;   /* 定位成功 → 复位退避参数，退出 LBS 模式 */
            g_lbs_cycle_cnt = 0;
            printf("[GPS] fix OK\r\n");
        } else {
            if (open_gps) {
                if (g_gps_fail_cnt < 10000) {
                    g_gps_fail_cnt++;   /* 只有真正开过 GNSS 的失败才计数 */
                }
                ql_app_log("[LOC][GPS] no fix, fail_cnt=%d, attempting LBS fallback", g_gps_fail_cnt);
                printf("[GPS] no fix, fail_cnt=%d, attempting LBS fallback...\r\n", g_gps_fail_cnt);
            }

            if (g_login_ok) {
                printf("[LBS] g_login_ok=1, calling cell_locator_query()...\r\n");
                ql_app_log("[LOC][LBS] query start");
                float lbs_lng = 0.0f, lbs_lat = 0.0f;
                int lbs_ret = cell_locator_query(&lbs_lng, &lbs_lat);
                printf("[LBS] cell_locator_query returned %d, lng=%.6f, lat=%.6f\r\n",
                       lbs_ret, lbs_lng, lbs_lat);
                if (lbs_ret == 0 && lbs_lng != 0.0f && lbs_lat != 0.0f) {
                    printf("[LBS] success, uploading to platform...\r\n");
                    ql_app_log("[LOC][LBS] upload: lon=%.6f, lat=%.6f", (double)lbs_lng, (double)lbs_lat);
                    bnd_time_t lbs_now;
                    broad_current_zone_time(&lbs_now, 0);
                    broad_send_gpsinfo(
                        (double)lbs_lng,
                        (double)lbs_lat,
                        lbs_now,
                        0.0, 0.0, 0.0);
                    printf("[LBS] upload done\r\n");

                    /* 穷人版运动检测：LBS 坐标(基站中心)明显变化 = 设备在移动，
                     * 很可能正离开地库/室内 → 触发下一轮立即开 GNSS 探测 */
                    if (g_lbs_have_last) {
                        float dlng = lbs_lng - g_lbs_last_lng;
                        float dlat = lbs_lat - g_lbs_last_lat;
                        if (dlng < 0) dlng = -dlng;
                        if (dlat < 0) dlat = -dlat;
                        if (dlng > GPS_LBS_MOVE_DEG || dlat > GPS_LBS_MOVE_DEG) {
                            g_lbs_cell_changed = 1;
                            printf("[LBS] move detected, will probe GNSS next round\r\n");
                            ql_app_log("[LOC][LBS] movement detected, GNSS probe triggered");
                        }
                    }
                    g_lbs_last_lng = lbs_lng;
                    g_lbs_last_lat = lbs_lat;
                    g_lbs_have_last = 1;
                } else {
                    ql_app_log("[LOC][LBS] query failed: ret=%d, lng=%.6f, lat=%.6f", lbs_ret, lbs_lng, lbs_lat);
                    printf("[LBS] query failed or zero coords (ret=%d)\r\n", lbs_ret);
                }
            } else {
                printf("[LBS] SKIPPED: g_login_ok=%d, cannot query LBS\r\n", g_login_ok);
            }
        }

        int sleep_s = gps_sleep_s();
        printf("[GPS] sleep %ds (fail_cnt=%d)\r\n", sleep_s, g_gps_fail_cnt);
        ql_rtos_task_sleep_ms(sleep_s * 1000);
    }
}

void quec_usbcdc_callback(QL_UART_PORT_NUMBER_E port, void* para) {
    int read_len = 0;
    char r_data[1024] = {0};
    read_len = ql_uart_read(port, r_data, sizeof(r_data));
    test_log("uart[%d] callback read data, data:%s, read_len:%d \n", port, r_data, read_len);
}

static void quec_usbcdc_test(void* argv) {
    int ret = -1;
    char r_data[128] = {0};
    int write_bytes = 0;
    unsigned char data[] = "hello, this is uart test!!!, abcdefghijklmnopqrstuvwxyz, 1234567890\n";
    ql_uart_config_t dcb;

    ql_uart_open(QL_USB_CDC_PORT, QL_UART_BAUD_115200, QL_FC_NONE);

    ql_uart_register_cb(QL_USB_CDC_PORT, quec_usbcdc_callback);  // use callback to read uart data

    while (1) {
        test_log("I still alive...%s\r\n", r_data);
        ql_uart_open(QL_USB_CDC_PORT, QL_UART_BAUD_115200, QL_FC_NONE);
        ret = ql_uart_write(QL_USB_CDC_PORT, data, sizeof(data));
        ql_rtos_task_sleep_s(5);
        ql_uart_close(QL_USB_CDC_PORT);
    }
}

void quec_uart_callback(QL_UART_PORT_NUMBER_E port, void* para) {
    int read_len = 0;
    int i = 0;
    char r_data[1024] = {0};
    read_len = ql_uart_read(port, (unsigned char *)r_data, sizeof(r_data));
    printf("[UART4 RX] %d bytes: %s\r\n", read_len, r_data);
    printf("[UART4 RX HEX] ");
    for (i = 0; i < read_len && i < 64; i++) {
        printf("%02X ", (unsigned char)r_data[i]);
    }
    printf("\r\n");
}

static void ql_test_baudrate(void* argv) {
    int ret = -1;
    char r_data[128] = {0};
    int write_bytes = 0;
    unsigned char data[] = "hello, this is uart test!!!, abcdefghijklmnopqrstuvwxyz, 1234567890\n";
    ql_uart_config_t dcb;
    ql_log_mask_set(QL_LOG_APP_MASK, QL_LOG_PORT_UART);
    ret = ql_uart_open(QL_MAIN_UART_PORT, QL_UART_BAUD_256000, QL_FC_NONE);
    if (ret) {
        test_log("open uart[%d] failed! %d \n", QL_MAIN_UART_PORT, ret);
        return;
    }

    /*****************************************/
    ql_uart_get_dcbconfig(QL_MAIN_UART_PORT, &dcb);
    test_log("[%s][%d]baudrate:%d, data_bit:%d, stop_bit:%d, parity_bit:%d, flow_ctrl:%d \r\n",
             __func__,
             __LINE__,
             dcb.baudrate,
             dcb.data_bit,
             dcb.stop_bit,
             dcb.parity_bit,
             dcb.flow_ctrl);
    dcb.baudrate = QL_UART_BAUD_256000;
    ql_uart_set_dcbconfig(QL_MAIN_UART_PORT, &dcb);
    /*****************************************/

    ql_uart_register_cb(QL_MAIN_UART_PORT, quec_uart_callback);  // use callback to read uart data

    while (1) {
        test_log("I still alive...%s\r\n", r_data);
        ret = ql_uart_write(QL_MAIN_UART_PORT, data, sizeof(data));
        if (ret == QL_UART_CTS_HIGH) {
            test_log("CTS_HIGH");
        }
        ql_rtos_task_sleep_s(2);
    }
}

static void quec_uart4_test(void * argv)
{
    int ret = -1;
    char r_data[128] = {0};
	int write_bytes = 0;
	unsigned char data[] = "hello, this is main uart test!!!\n";
	ql_uart_config_t dcb;
    ql_log_mask_set(QL_LOG_APP_MASK, QL_LOG_PORT_UART);

    printf("[UART4 TEST] powering on GPS module...\r\n");
    gps_power_en(1);
    ql_rtos_task_sleep_ms(2000);

    ret = ql_uart_open(QL_U4_UART_PORT, QL_UART_BAUD_115200, QL_FC_NONE);
	if (ret) {
		test_log("open uart[%d] failed! %d \n", QL_U4_UART_PORT,ret);
		return;
	}

	/*****************************************/
	ql_uart_get_dcbconfig(QL_U4_UART_PORT, &dcb);
	test_log("[%s][%d]baudrate:%d, data_bit:%d, stop_bit:%d, parity_bit:%d, flow_ctrl:%d \r\n", __func__, __LINE__, dcb.baudrate, dcb.data_bit, dcb.stop_bit, dcb.parity_bit, dcb.flow_ctrl);
	dcb.baudrate = QL_UART_BAUD_115200;
	ql_uart_set_dcbconfig(QL_U4_UART_PORT, &dcb);
	/*****************************************/

    ql_uart_register_cb(QL_U4_UART_PORT, quec_uart_callback);	//use callback to read uart data
    
	while (1)
	{
        ret = ql_uart_write(QL_U4_UART_PORT, data, sizeof(data));
        printf("[UART4 TX] %d bytes: %s", ret, data);
        if(ret == QL_UART_CTS_HIGH)
        {
           test_log("CTS_HIGH");
        }
		ql_rtos_task_sleep_s(5);

	}    
}

/*流控休眠唤醒测试方法：模块休眠的时候，串口工具发数据给模块，利用其它唤醒源唤醒模块，看模块收到uart数据是否完整*/
// 关闭移远默认的测试业务，防止它也抢占被我们使用的 UART 端口
application_init(quec_uart_gps, "quec_uart_gps", 20, 0);
//  application_init(quec_uart4_test, "quec_uart4_test", 20, 0);
// application_init(quec_usbcdc_test, "quec_usb", 10, 0);
// application_init(ql_test_baudrate, "ql_test_baudrate", 10, 0);
