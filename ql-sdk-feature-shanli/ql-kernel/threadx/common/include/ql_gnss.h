/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#ifndef _QL_GNSS_H_
#define _QL_GNSS_H_

#ifdef __cplusplus
	 extern "C" {
#endif

#include "quec_hx_gps.h"
#define QL_GSV_MAX_SATS  (10)

#define QL_GNSS_OK  0
#define QL_GNSS_ERR -1
#define QL_GNSS_ERR_NOT_OPENED	1

typedef enum
{
    AGPS_GNSS_DISABLE,
    AGPS_GNSS_ENABLE
}ql_AGPSGnssSW;
typedef enum
{
    APFLASH_GNSS_DISABLE,
    APFLASH_GNSS_ENABLE
}ql_APFLASHGnssSW;

typedef enum{
	QGPS_RESET_COLD,
	QGPS_RESET_HOT,
	QGPS_RESET_WARM
}ql_GPS_RESET_t;
    

typedef struct ql_gnss_location_struct {

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
    unsigned int cnrs[QL_GSV_MAX_SATS];
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
}ql_gnss_location_t;

typedef struct{
	//配置号，1~7
	unsigned char profile_inx;
	//agps服务器地址
	char agps_url[128];
	//经销商账号
	char agpsvendorID[50];
	//用户账号
	char agpsmodelID[25];
	//密码
	char agpspassWord[50];
}quec_agps_param_t;


typedef void (*gnss_callback)(char *data, int len);

/***********************************************************************
 *
 * Name:   ql_gnss_open    
 *
 * Description: 打开gnss
 *
 * Parameters:  cb:gnss nmea回调函数
 *             
 * Returns:     0：打开成功
 *              
 * Notes:
 *
 ***********************************************************************/
int ql_gnss_open(gnss_callback cb);
/***********************************************************************
 *
 * Name:   ql_gnss_close    
 *
 * Description: 关闭gnss
 *
 * Parameters:  none
 *             
 * Returns:     0：关闭成功
 *              other: faile
 * Notes:
 *
 ***********************************************************************/
int ql_gnss_close(void);
/***********************************************************************
 *
 * Name:   ql_gnss_cfgsys_set    
 *
 * Description: 设置gnss系统，在调用ql_gnss_open之前设置生效
 *
 * Parameters:	sys_type:
 *						 0	 GPS
 *						 1	 GPS + BeiDou
 *						 3	 GPS + GLONASS + Galileo
 *						 4	 GPS + GLONASS
 *						 5	 GPS + BeiDou + Galileo
 *						 6	 GPS + Galileo
 *						 7	 BeiDou			   
 * Returns: 	 0 ：设置成功
 *				非0：设置失败
 * Notes:
 *
 ***********************************************************************/
int ql_gnss_cfgsys_set(int sys_type);

/***********************************************************************
 *
 * Name:   ql_gnss_cfgmsg_set	
 *
 * Description: 设置gnss吐出的nmea语句类型，在调用ql_gnss_open之前设置生效，在ql_gnss_cfgsys_set之后设置，原因：系统切换，nmea语句恢复默认值
 *
 * Parameters:	nmea_type		   
 *						 0	 禁止输出NMEA语句
 *						 1	 GGA
 *						 2	 RMC
 *						 4	 GSV
 *						 8	 GSA
 *						 16  VTG
 *						 32  GLL
 *						 63  输出以上所有类型的语句
 * Returns: 	 0 ：设置成功
 *				非0：设置失败
 * Notes:
 *
 ***********************************************************************/
int ql_gnss_cfgmsg_set(int nmea_type);

/***********************************************************************
 *
 * Name:   ql_gnss_agps_cfg	
 *
 * Description: 设置agps功能，在调用ql_gnss_open之前设置生效
 *
 * Parameters:	gnssagpsflag		   
 *						AGPS_GNSS_DISABLE,
 *   					AGPS_GNSS_ENABLE
 * Returns: 	 0 ：设置成功
 *				非0：设置失败
 * Notes:
 *
 ***********************************************************************/
int ql_gnss_agps_cfg(ql_AGPSGnssSW gnssagpsflag,char agps_type);

/***********************************************************************
 *
 * Name:   ql_gnss_apflash_cfg	
 *
 * Description: 设置apflash功能，在调用ql_gnss_open之前设置生效
 *
 * Parameters:	gnssapflashflag		   
 *						APFLASH_GNSS_DISABLE,
 *   					APFLASH_GNSS_ENABLE
 * Returns: 	 0 ：设置成功
 *				非0：设置失败
 * Notes:
 *
 ***********************************************************************/
int ql_gnss_apflash_cfg(ql_APFLASHGnssSW gnssapflashflag);
int ql_gnss_reset_type_set(ql_GPS_RESET_t type);
int ql_gnss_get_location(ql_gnss_location_t **lolcation);


/***********************************************************************
 *
 * Name:   ql_gnss_reset_type_set	
 *
 * Description: 设置gnss芯片冷热温启动，在gnss定位成功后设置生效
 *
 * Parameters:	type		   
 *						QGPS_RESET_COLD,
 *						QGPS_RESET_HOT,
 *						QGPS_RESET_WARM
 * Returns: 	 0 ：设置成功
 *				非0：设置失败
 * Notes:
 *
 ***********************************************************************/
int ql_gnss_reset_type_set(ql_GPS_RESET_t type);

void ql_get_agps_sate_num( gnss_ephemeris_info cb);
int ql_set_agps_file(void);
int ql_send_agps_to_gps(char *data,int len);
int ql_set_gnss_nmea_mode(char mode);
void ql_monitor_param_print(void);
int ql_hx_bckp_set(int value);

/***********************************************************************
 *
 * Name:   ql_gnss_agps_param_cfg
 *
 * Description: 用于agps服务器接入参数的配置
 *              注：此接口必须在打开gnss前进行配置，否则不生效，重启则恢复默认配置。
 * Parameters:	agps_param
 *					见quec_agps_param_t类型定义
 *		
 * Returns: 	 0：set success
 *				 1：fail
 * Notes:
 *
 ***********************************************************************/
int ql_gnss_agps_param_cfg(quec_agps_param_t *agps_param);

/***********************************************************************
 *
 * Name:   ql_gnss_ntp_url_cfg
 *
 * Description: 用于配置ntp服务器的地址
 *              注：此接口必须在打开gnss前进行配置，否则不生效，重启则恢复默认配置。
 * Parameters:	ntp_url
 *					ntp服务器的url地址
 *		
 * Returns: 	 0：set success
 *				 1：fail
 * Notes:
 *
 ***********************************************************************/
int ql_gnss_ntp_url_cfg(const char * ntp_url);

#ifdef __cplusplus
	} /*"C" */
#endif

#endif /* _QL_GNSS_H_ */


