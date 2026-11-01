/*============================================================================================
	Copyright(c) 2018 Quectel Wierless Solution,Co.,Ltd. All Rights Reserved.
	Quectel Wireless Solution Proprietary and Confidential.
============================================================================*/
#ifndef __QUEC_GPS_H__
#define __QUEC_GPS_H__


#ifdef __cplusplus
extern "C" {
#endif

#include "quec_nmea_parse.h"
#include "gps_app.h"
#define HX_GSV_MAX_SATS 10

#define QUEC_GPS_CLOSE 0
#define QUEC_GPS_OPEN  1
#define QUEC_GPS_OUTPT_NMEA 2

#define QUEC_GPS_OPEN_EVENT (1<<0)
#define QUEC_GPS_CLOSE_EVENT (1<<1)
#define QUEC_GPS_NMEA_PARSE_EVENT (1<<2)
#define QUEC_AGPS_DATA_REQ_EVENT (1<<3)
#define QUEC_APFLSH_REQ_EVENT (1<<4)
#define QUEC_GPS_APFLASH_EVENT (1<<5)
#define QUEC_GPS_DOWNLOAD_FIRM (1<<6)
#define QUEC_GPS_RESTART (1<<7)

#define QUEC_GPS_EVENT_MASK  (QUEC_GPS_OPEN_EVENT | QUEC_GPS_CLOSE_EVENT | QUEC_GPS_NMEA_PARSE_EVENT \
|QUEC_AGPS_DATA_REQ_EVENT |QUEC_APFLSH_REQ_EVENT| QUEC_GPS_APFLASH_EVENT | QUEC_GPS_RESTART)

#define QUEC_GPS_INIT_STATE   0
#define QUEC_NMEA_PASRE_STATE (1<<0)
#define QUEC_GPS_RESET_STATE (1<<1)
#define QUEC_APFLASH_REQED (1<<2) /*开机第一次请求apflash数据已经完成*/

#define QUEC_POWER_ON   1
#define QUEC_POWER_OFF  0

#define NMEA_CLOSE 0
#define GGA_EN (1<<0)
#define RMC_EN (1<<1)
#define GSV_EN (1<<2)
#define GSA_EN (1<<3)
#define VTG_EN (1<<4)
#define GLL_EN (1<<5)
#define GST_EN (1<<6)

enum {
GPS_SYS =0,
GPS_BEIDOU_SYS,
GPS_GLONASS_GALILEO_SYS = 3,
GPS_GLONASS_SYS,
GPS_BEIDOU_GALILEO_SYS,
GPS_GALILEO_SYS,
BEIDOU_SYS,
};

enum 
{
    QUEC_GPS_NO_ERROR = 0,
    QUEC_GPS_NOT_OPEN_ERROR,
    QUEC_GPS_ALREADY_CLOSED_ERROR,
    QUEC_GPS_NOT_EXIST_ERROR,
    QUEC_GPS_RESP_MSG_ERROR,
    QUEC_GPS_CMD_MSG_ERROR,
    QUEC_GPS_ERROR,
    
};

#define HX_GPS_MODULE   0xBDE33982 /*和芯星通制造商*/

typedef enum
{
	GPS_UNKNOW,
	GPS_OK_CMD=0x01,
	GPS_FAIL_CMD,
	GPS_AIDINFO_RESP ,
	GPS_CFGGEOID_RESP,
	GPS_PDTINFO_RESP
}quec_gnss_cmd_resp;
/**************************GNSS  CMD***************************/
typedef enum
{
	QUEC_GNSS_UNKNOW_TYPE,
	QUEC_GNSS_BAUD_SET,
	QUEC_GNSS_PDTINFO_CMD,
	QUEC_GNSS_NMEA_TYPE,
	QUEC_GNSS_CFGSYS,
	QUEC_GNSS_HOT_RESET,
	QUEC_GNSS_WARM_RESET,
	QUEC_GNSS_COLD_RESET,
	QUEC_GNSS_AGPS_AIDINFO_REQ,
	QUEC_GNSS_CFG_GEOID_REQ,
	QUEC_GNSS_CFG_GEOID_SET,
	QUEC_GNSS_AIDPOS_SET,
	QUEC_GNSS_AIDTIME_SET,
	QUEC_GNSS_MAX_CMD,
}quec_gnss_cmd;


typedef struct hx_locate_struct {

    /*是否有效定位*/
    unsigned char valid;
    /*经度*/
    double longitude;
    /*经度E(东经)或W(西经)*/
    unsigned char longitude_cardinal;
    /*纬度*/
    double latitude;
    /*纬度N(北纬)或S(南纬)*/
    unsigned char latitude_cardinal;
    /*hdop精度*/
    float  hdop;
    /*phop精度*/
    float pdop;
    /*航向 0-360*/
    float heading;
    /*速度 km/h*/
    float gps_speed;
    /*信号强度,max=5, data from avg_snr*/
    unsigned char gps_signal;
    /*最大信号?? db*/
    unsigned int max_cnr;
    unsigned int max_cnr2;
    /*最小信号?? db*/
    unsigned int min_cnr;
    /*平均信号?? db*/
    unsigned int avg_cnr;
    /*信号值数??*/
    unsigned int cnrs[HX_GSV_MAX_SATS];
    unsigned int cnrs_index;
    /*定位卫星数量*/
    unsigned int satellites_num;
    /*海拔高度*/
    float altitude;
    /*FWVER*/
    char fwver[32];
    struct tm time;
    unsigned char quality;
    unsigned char navmode;
     /*定位模式*/
    unsigned char fix_mode;
    /*VTG：地面速率 单位：节*/
    double sog;
    /*VTG：地面速率 单位：km/h*/
    double kph;
    /*VTG：地面航向*/
    double cogt;
}hx_locationg_t;

typedef struct {
    char             gps_sate_num;
    char             gps_sate_vaild_num;
    char             bds_sate_num;
    char             bds_sate_vaild_num;
    char             gal_sate_num;
    char             gal_sate_vaild_num;
    char             glo_sate_num;
    char             glo_sate_vaild_num;
	int 			 agps_status;

}quec_gnss_sate_num_t;

typedef struct quec_gnps_msg
{
    unsigned short cmd_id;
	int len;
    char *data;
}quec_gps_msg_t;
typedef void (*nmea_str_put)      (struct tm *time ,char *nmea ,int length); 
typedef void (*location_update)   (hx_locationg_t *gps_data); 
typedef void (*gps_open_success)   (int status_code);         /*打开gps成功回调*/
typedef void (*gnss_ephemeris_info)(quec_gnss_sate_num_t * gnss_sate_num);
typedef void (*gps_packet_put)      (char *packet ,int length); 


typedef struct {
    int  (*q_gps_open)              (void);         /*打开gps模块*/
    int  (*q_gps_close)             (void);         /*关闭gps模块*/
    int  (*q_gps_reset)             (int type);     /*重启gps模块*/
    void (*q_reg_nmea_str_cb)       (nmea_str_put cb);
    void (*q_reg_location_update_cb) (location_update cb);
    void (*q_reg_open_gps_success_cb) (gps_open_success cb);
    void (*q_reg_agps_sate_num_cb)  (gnss_ephemeris_info cb);
    void (*q_reg_nmea_packet_cb)       (gps_packet_put cb);
}QUEC_GPS_OPS;

typedef struct
{
  gps_open_success open_gps_success_cb;
  nmea_str_put nmea_str_cb;   /*nmea 解析回调，用于上层去获取单条nmea语句*/
  location_update loaction_update_cb; /*位置更新回调，用于将解析后的位置信息更新到上层*/ 
  gnss_ephemeris_info  gnss_ephemeris_info_cb; /*星历检查是否有效回调*/
  gps_packet_put nmea_packets_cb;
}QUEC_NMEA_CB;

typedef struct quec_gps_dev
{
    unsigned int gps_manufacturer;  /*gps模组制造商*/
    char power_state;               /*GPS上电状态*/
    int  worke_state;               /*GPS工作状态*/
    void *gps_event_flag_ref;
    void *gps_task_ref;
    void *gps_keep_alive_timer;
    QUEC_GPS_OPS *ops;
    QUEC_NMEA_CB *nmea_cb;
}QUEC_GPS_DEV_T;

typedef struct quec_gnss_quick_start
{
    char reset_flag;
    hx_locationg_t data;
}quec_gnss_quick_start_t;


QUEC_GPS_DEV_T *quec_get_gps_dev(void);
int quec_gps_open(void);
int quec_gps_close(void);
hx_locationg_t * hx_location_data_get(void);
int quec_gnss_cmd_send(quec_gps_msg_t *rcv);
int quec_gnss_resp_process(quec_gps_msg_t *rcv);
void quec_apflash_req_flag_set(void);
void quec_gps_init(void);
int quec_hx_gnss_sys_set(int sys_type);
int quec_hx_gnss_nmea_set(char value);





#ifdef __cplusplus
            }
#endif

#endif

