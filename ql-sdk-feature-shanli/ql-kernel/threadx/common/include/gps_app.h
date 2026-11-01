/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#ifndef _GPS_APP_H_
#define _GPS_APP_H_
#ifdef __cplusplus 
extern "C" {
#endif
#include <time.h>
#include "quec_cust_feature.h"
#include "gps_channel.h"
#define QUEC_GSV_MAX_SATS  (10)
#define QUEC_NV_GPS_CFG  "quec_nv_gps_cfg"

enum{
 GGA,
 RMC,
 GSV,
 GSA,
 VTG,
 GLL,
 GST,
 NMEA_MAX
};
 
#ifdef QUEC_AT_GPS_ENABLE
#define GNSS_URC_FIRM_ENABLE    (0X01 << 0)
#define GNSS_URC_APFLASH_ENABLE    (0X01 << 1) //暂不支持
#define GNSS_URC_AGPS_ENABLE    (0X01 << 2)
#define GNSS_URC_COLDHOT_ENABLE    (0X01 << 3) //暂不支持
#endif

typedef enum{
	GNSS_URC_FIRM_OK,
	GNSS_URC_FIRM_ERROR,
	GNSS_URC_AGPS_OK = 0,
	GNSS_URC_AGPS_PDP_ERROR = 5,
	GNSS_URC_AGPS_HTTP_ERROR,
}gnss_urc_status_e;
	
#ifdef QUEC_AT_GPS_ENABLE
typedef enum{
    QUEC_GPS,    //GP
    QUEC_GLONASS,//GL
    QUEC_GALILEO,
    QUEC_BDS,    //GB
    QUEC_MULTISYS,   //GN
    QUEC_GT_MAX
}quec_gps_type;
#endif
typedef struct quec_gnss_data_struct {

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
    unsigned int cnrs[QUEC_GSV_MAX_SATS];
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
}quec_gnss_nmea_data_t;
typedef struct {
	  int 		   				          mdflag;
	  unsigned int                        gnss_sys_type;        
	  unsigned int                        gps_nmea_type;
} nmeasrc_sentences_cfg;

typedef struct{
   char agps_type;
   char agps_en;
}agps_cnf_t;

typedef enum{
   STR_MODE,
   PACKET_MODE,
}nmea_mode_t;

#ifdef QUEC_AT_GPS_ENABLE
typedef enum {
    PORT_NONE,
	PORT_USBNMEA,
	PORT_UARTDEBUG,
	PORT_MAX,
} nmea_outport_row;
    
typedef struct
{
	char  outport_en;
	nmea_outport_row type;
	unsigned char out_channel;
}quec_gps_outport_config;
#endif

#ifdef HX_GNSS_SUPPORT
#define QUEC_AGPS_URL_STR              "http://quectel-api1.rx-networks.cn/rxn-api/locationApi/rtcm\0"
#define QUEC_AGPS_VENDORID_STR         "wLgWwv6JQt\0"
#define QUEC_AGPS_MODELID_STR          "Quectel\0"
#define QUEC_AGPS_PASSWORD_STR         "aFltUERDZzZxeTY5cEp2eA==\0"
#else 
#define QUEC_AGPS_URL_STR				"http://agnss.asrmicro.com/asr-filedownload/filedown/allstar"
#define QUEC_AGPS_VENDORID_STR			"Quectel"
#define QUEC_AGPS_MODELID_STR			"Quectel"
#define QUEC_AGPS_PASSWORD_STR			"9w68sauaFh000"
#endif

typedef struct{
	unsigned char profile_inx;
	char agps_url[128];
	char agpsvendorID[50];
	char agpsmodelID[25];
	char agpspassWord[50];
}quec_agps_cfg_t;



typedef struct
{
	nmeasrc_sentences_cfg nmea_handle_cfg;
#ifdef QUEC_AT_GPS_ENABLE
	quec_gps_outport_config outport;                         /*nmea语句输出口*/
#endif
	char autogps;	                                        /*gps开机自启动*/
	char apflash;                                           /*快速冷启动*/
    agps_cnf_t agps_cfg;                                    /*星历快速定位*/
	int  nmeasrc_enable;   
#ifdef QUEC_AT_GPS_ENABLE
	int urc_enable;                                         /*urc上报使能*/
#endif
	quec_agps_cfg_t quec_agps_cfg;                          /*agps server配置*/
	char ntp_url[32];                                       /*ntp server*/
}quec_gps_handle;

#ifdef QUEC_AT_GPS_ENABLE
typedef enum {
	QGPS_PROTO_NMEA_SRC_GGA,		/* GPGGA */
	QGPS_PROTO_NMEA_SRC_GLL,		/* GPGGA */
	QGPS_PROTO_NMEA_SRC_GSA,		/* GPGSA GNGSA PQGSA */
	QGPS_PROTO_NMEA_SRC_GSV,		/* GPGSV GLGSV GAGSV PQGSV */
	QGPS_PROTO_NMEA_SRC_RMC,		/* GPRMC */
	QGPS_PROTO_NMEA_SRC_VTG,		/* GPVTG */
	QGPS_PROTO_NMEA_SRC_ZDA,		/* GPZDA */
	QGPS_PROTO_NMEA_SRC_GST,		/* GPGST */
	QGPS_PROTO_NMEA_SRC_MAX,
} qgps_proto_nmea_src_e_type;

#define  GSV_NUM 8
#define  GSA_NUM 8


typedef struct {
	struct
	{
		char gp_gga_nmea_len;		/* GPGGA */
		char gp_gga_sent[128];
	}gga_sentences;  /* gpgsv glgsv gagsv pqgsv */
	
	struct
	{
		char gp_rmc_nmea_len;		/* GPRMC */
		char gp_rmc_sent[128];
	}rmc_sentences;  /* gpgsv glgsv gagsv pqgsv */
	
	struct 
	{
		char	nmea_sentences_len;
		char	gp_gsv_sent[GSV_NUM][128];		/* one grp gsv most have 8 line*/	
    }gsv_sentences[QUEC_GT_MAX];	/* gpgsv glgsv gagsv pqgsv */
	
	struct
	{
		char gp_gsa_nmea_len;		/* GPGSA */
		char gp_gsa_sent[GSA_NUM][128];
	}gsa_sentences;  /* gpgsv glgsv gagsv pqgsv */

	struct
	{
		char gp_vtg_nmea_len;		/* GPVTG */
		char gp_vtg_sent[128];
	}vtg_sentences;	/* gpgsv glgsv gagsv pqgsv */
	

	struct
	{
		char gp_gll_nmea_len;		/* GAGNS */
		char gp_gll_sent[128];
	}gll_sentences;	/* gpgsv glgsv gagsv pqgsv */

	struct
	{
		char gp_gst_nmea_len;		/* GAGNS */
		char gp_gst_sent[128];
	}gst_sentences;	/* gpgsv glgsv gagsv pqgsv */
    
} nmeasrc_sentences;

typedef struct 
{
	char gsv_nmeas[GSV_NUM][128];
}gsv_sentences_t;

typedef struct
{
    unsigned char gps_sat[3];                /*卫星号*/
    unsigned char gps_cn[3];                /*信噪比*/ 
    unsigned char bds_sat[3];                /*卫星号*/
    unsigned char bds_cn[3];                /*信噪比*/ 
}sat_info_t;

typedef struct {
	unsigned char cn_index;
	unsigned char sat_index;
	unsigned char total_msgs;         /*各星系GSV消息总数*/
	unsigned char total_sats;         /*本系统可见卫星总数*/
	unsigned char cn_item[3];         /*cn值最大卫星位置记录*/
	unsigned char cn_max[3];          /*cn值最大前三组*/
	unsigned char sat_max[3];         /*cn值最大前三组卫星号*/
	unsigned char cn[32];             /*gsv语句可视卫星cn值存储*/
	unsigned char sat[32]; 			  /*gsv语句可视卫星卫星号存储*/
}gsv_param_filter_t;

int quec_gsv_filter_process(sat_info_t * sat_info);

#endif

quec_gps_handle *quec_gnss_config_para_get(void);
void quec_gnss_auto_start(void);
int quec_gnss_sys_set(int sys_type);
int quec_gnss_nmea_set(int value);
void * quec_get_location_para(void);
int quec_gnss_reset(int type);
int quec_set_agps_file(void);
quec_gnss_monitor_struct_t *quec_get_monitor_param(void);

#ifdef QUEC_AT_GPS_ENABLE
void quec_hx_debug_ctrl_set(int debug_ctrl);
int quec_hx_debug_ctrl_get(void);
#endif

void quec_hx_bckp_set(int value);
int quec_hx_bckp_get(void);

int quec_agps_param_cfg(quec_agps_cfg_t *quec_agps_cfg);



#ifdef __cplusplus 
}
#endif

#endif 
