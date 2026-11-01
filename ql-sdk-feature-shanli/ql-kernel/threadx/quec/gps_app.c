/*============================================================================================
	Copyright(c) 2018 Quectel Wierless Solution,Co.,Ltd. All Rights Reserved.
	Quectel Wireless Solution Proprietary and Confidential.
============================================================================*/

#include "gps_app.h"
#include <string.h>
#include "fat32_file_opt.h"
#include "gps_debug.h"
#include "quec_hx_agps.h"
#include "quec_nmea_parse.h"
#include "quec_cust_feature.h"
#include "quec_siolib.h"
#include "quec_hx_apflash.h"
#include "quec_urc.h"
#include "gps_channel.h"

#define NMEA_DATA_LEN 512
quec_gnss_nmea_data_t gnss_nmea;
quec_gps_handle quec_gps_config_param={
	.quec_agps_cfg.profile_inx = 1,\
	.quec_agps_cfg.agpsvendorID=QUEC_AGPS_VENDORID_STR,\
	.quec_agps_cfg.agps_url=QUEC_AGPS_URL_STR,\
	.quec_agps_cfg.agpsmodelID=QUEC_AGPS_MODELID_STR,\
	.quec_agps_cfg.agpspassWord=QUEC_AGPS_PASSWORD_STR,\
	.ntp_url=NTP_SERVER_DOMAIN,\
};

nmea_mode_t nmea_mode = 0;
quec_gnss_monitor_struct_t quec_gnss_monitor;
char quec_gnss_open_flag = 0;

#ifdef QUEC_AT_GPS_ENABLE/*std*/
nmeasrc_sentences nmea_data;
#else /*open*/
#include "ql_gnss.h"
gnss_callback ql_gnss_nmea_data_cb = NULL;
#endif

#ifdef  QUEC_GPS_SUPPORT
#include "gps_api.h"
#include "gps.h"
#include "gps_atcmd.h"
char asr_init_flag = 0;
#ifdef QUEC_AT_GPS_ENABLE
char asr_urc_flag = 0;
#endif
void asr_nmea_callback(GpsUtcTime timestamp, const char* nmea, int length);
void asr_update_location(GpsLocation* location);

GpsCallbacks quec_asr_gps_callbacks = {
	sizeof(GpsCallbacks),
	asr_update_location,
	NULL,
	NULL,
	asr_nmea_callback,
};

#elif defined(HX_GNSS_SUPPORT)
#include "quec_hx_gps.h"
#include "quec_hx_agps.h"
char hx_init_flag = 0;
void hx_location_update   (hx_locationg_t *gps_data);
void hx_at_nmea_callback(struct tm *time,char* nmea, int length);
void hx_nmea_packet_cb(char* packet, int length);
extern int quec_gnss_type_check(void);
#ifdef QUEC_AT_GPS_ENABLE
//20230725 和芯原厂debug log输出控制
int hx_debug_ctrl = 0;
#endif
#endif 

static struct tm *gmtime_r(const time_t *tloc, struct tm *result) {
    struct tm *tm;
    /* Bug Fix.
   * Return Value of gmtime() is NULL On CranePlatform.
   * SO local_time() is replaced here.By JoshuaWang.@0205/2021.
   */
   
    tm = localtime(tloc);
    if(tm)
        return memcpy(result, tm, sizeof(struct tm));

    return NULL;
}

 quec_gnss_monitor_struct_t *quec_get_monitor_param(void)
 {
     return &quec_gnss_monitor;
 }


#ifdef  QUEC_GPS_SUPPORT
	void quec_asr_gps_user_callback(USER_CB_STATE_T event, void *data, int daya_len)
   {
#ifdef QUEC_AT_GPS_ENABLE 
	   quec_gps_handle * gnss_urc_cfg = &quec_gps_config_param;
	   char ccIndBuf[128] = {0};
	   if(gnss_urc_cfg->urc_enable & GNSS_URC_FIRM_ENABLE)
	   {
		  if(event == ASR_GPS_INITIAL_SUCCESS)
		  {
			  snprintf(ccIndBuf, sizeof("+QGPS: \"firmware\",0,0"), "+QGPS: \"firmware\",0,%d", GNSS_URC_FIRM_OK);
			  at_urc_send(NUM_OF_TEL_ATP, (uint8 *)ccIndBuf, strlen("+QGPS: \"firmware\",0,0"), FALSE, URC_OUT_METHOD_UNICAST, NULL);
			  GPS_LOGI("%s",ccIndBuf);
		  }
		  else if(event == ASR_GPS_INITIAL_FAILED)
		  {
			  snprintf(ccIndBuf, sizeof("+QGPS: \"firmware\",0,0"), "+QGPS: \"firmware\",0,%d", GNSS_URC_FIRM_ERROR);
			  at_urc_send(NUM_OF_TEL_ATP, (uint8 *)ccIndBuf, strlen("+QGPS: \"firmware\",0,0"), FALSE, URC_OUT_METHOD_UNICAST, NULL);
			  GPS_LOGI("%s",ccIndBuf);
		  }
   
	   }
	   if(gnss_urc_cfg->urc_enable & GNSS_URC_AGPS_ENABLE)
	   {
		  if(event == ASR_GPS_SEND_DATA_SUCCESS)
		  {
			  snprintf(ccIndBuf, sizeof("+QGPS: \"agps\",0,0"), "+QGPS: \"agps\",0,%d", GNSS_URC_AGPS_OK);
			  at_urc_send(NUM_OF_TEL_ATP, (uint8 *)ccIndBuf, strlen("+QGPS: \"agps\",0,0"), FALSE, URC_OUT_METHOD_UNICAST, NULL);
			  GPS_LOGI("%s",ccIndBuf);
		  }
		  else if(event == ASR_GPS_DOWNLOAD_FAIL)
		  {
			  snprintf(ccIndBuf, sizeof("+QGPS: \"agps\",0,0"), "+QGPS: \"agps\",0,%d", GNSS_URC_AGPS_HTTP_ERROR);
			  at_urc_send(NUM_OF_TEL_ATP, (uint8 *)ccIndBuf, strlen("+QGPS: \"agps\",0,0"), FALSE, URC_OUT_METHOD_UNICAST, NULL);
			  GPS_LOGI("%s",ccIndBuf);
		  }
		  else if(event == ASR_GPS_PDP_FAIL)
		  {
			  snprintf(ccIndBuf, sizeof("+QGPS: \"agps\",0,0"), "+QGPS: \"agps\",0,%d", GNSS_URC_AGPS_PDP_ERROR);
			  at_urc_send(NUM_OF_TEL_ATP, (uint8 *)ccIndBuf, strlen("+QGPS: \"agps\",0,0"), FALSE, URC_OUT_METHOD_UNICAST, NULL);
			  GPS_LOGI("%s",ccIndBuf);
		  }
   
	   }
   
#endif
	}
 
#endif


#ifdef QUEC_AT_GPS_ENABLE /*STD*/
int quec_gps_handle_set(void)
{
    int fat_ret = QUEC_FAT_FAILED;
    
    fat_ret = quectel_nv_fat_write(QUEC_NV_GPS_CFG, &quec_gps_config_param, sizeof(quec_gps_handle));
    if (QUEC_FAT_SUCCESS != fat_ret)
    {
        GPS_LOGE("quec_qdai_set err=%d", fat_ret);
		fat_ret = quectel_nv_fat_write(QUEC_NV_GPS_CFG, &quec_gps_config_param, sizeof(quec_gps_handle));
	    if (QUEC_FAT_SUCCESS != fat_ret)
	    {
	        GPS_LOGE("quec_qdai_set err=%d", fat_ret);    
	    }
    }
    return fat_ret;
}
int quec_gps_handle_get(void)
{
    int fat_ret = QUEC_FAT_FAILED;
    fat_ret = quectel_nv_fat_read(QUEC_NV_GPS_CFG, &quec_gps_config_param, sizeof(quec_gps_handle));
    if (QUEC_FAT_SUCCESS != fat_ret)
    {
        GPS_LOGE("quec_qdai_get err=%d", fat_ret); 
    }

    return fat_ret; 
}

void quec_gnss_auto_start(void)
{
	//20230724 初始化urc_enable 为1，防止非全新模块固件更新查询urc_enable参数异常
	quec_gps_config_param.urc_enable = 0x1;
	quec_gps_config_param.quec_agps_cfg.profile_inx = 1;
	memcpy(quec_gps_config_param.quec_agps_cfg.agpsvendorID,QUEC_AGPS_VENDORID_STR,strlen(QUEC_AGPS_VENDORID_STR)+1);
    memcpy(quec_gps_config_param.quec_agps_cfg.agps_url,QUEC_AGPS_URL_STR,strlen(QUEC_AGPS_URL_STR)+1);
    memcpy(quec_gps_config_param.quec_agps_cfg.agpsmodelID,QUEC_AGPS_MODELID_STR,strlen(QUEC_AGPS_MODELID_STR)+1);
    memcpy(quec_gps_config_param.quec_agps_cfg.agpspassWord,QUEC_AGPS_PASSWORD_STR,strlen(QUEC_AGPS_PASSWORD_STR)+1);
	memcpy(quec_gps_config_param.ntp_url,NTP_SERVER_DOMAIN,strlen(NTP_SERVER_DOMAIN)+1);
    if(quec_gps_handle_get())
	{
		/*标准要求nmeasrc默认值为1*/
        quec_gps_config_param.nmeasrc_enable = 1;
		//20230617 标准要求gnss urc上报默认使能firmware urc上报
		quec_gps_config_param.urc_enable = 0x1;
		
		/*标准要求gpsnmeatype在未设置时默认值为31*/
		if((quec_gps_config_param.nmea_handle_cfg.mdflag&GNSS_SYSCONFGE_ENABLE)==0){
            #ifdef  HX_GNSS_SUPPORT
			quec_gps_config_param.nmea_handle_cfg.gnss_sys_type = GPS_BEIDOU_GALILEO_SYS;
            #else
            #ifdef QUEC_BD_GNSS_SUPPORT//定制需求,默认单北斗
			quec_gps_config_param.nmea_handle_cfg.gnss_sys_type = BEIDOU_SYS;
			#else
			quec_gps_config_param.nmea_handle_cfg.gnss_sys_type = GPS_BEIDOU_SYS;
			#endif
            #endif
		}
		
		/*设置GNSS nmea语句种类 //默认打开GGA/RMC/GSA/GSV/VTG */
		if((quec_gps_config_param.nmea_handle_cfg.mdflag&GNSS_NMEATYPE_ENABLE)==0){	
			quec_gps_config_param.nmea_handle_cfg.gps_nmea_type = 
	            GGA_EN|RMC_EN|GSV_EN|GSA_EN|VTG_EN;
		}
		quec_gps_config_param.apflash = 1;//@20221102 标准要求apflash默认值为1

		quec_gps_config_param.outport.outport_en=TRUE;
        quec_gps_config_param.outport.out_channel=TEL_AT_CMD_ATP_NEMA;
        quec_gps_config_param.outport.type=PORT_USBNMEA;
		quec_gps_config_param.quec_agps_cfg.profile_inx = 1;
		memcpy(quec_gps_config_param.quec_agps_cfg.agpsvendorID,QUEC_AGPS_VENDORID_STR,strlen(QUEC_AGPS_VENDORID_STR)+1);
	    memcpy(quec_gps_config_param.quec_agps_cfg.agps_url,QUEC_AGPS_URL_STR,strlen(QUEC_AGPS_URL_STR)+1);
        memcpy(quec_gps_config_param.quec_agps_cfg.agpsmodelID,QUEC_AGPS_MODELID_STR,strlen(QUEC_AGPS_MODELID_STR)+1);
        memcpy(quec_gps_config_param.quec_agps_cfg.agpspassWord,QUEC_AGPS_PASSWORD_STR,strlen(QUEC_AGPS_PASSWORD_STR)+1);
		memcpy(quec_gps_config_param.ntp_url,NTP_SERVER_DOMAIN,strlen(NTP_SERVER_DOMAIN)+1);
        quec_gps_handle_set();
    }
	
	/*初始化gnss pin脚，不打开gnss时，把gnss uart配置为输入下拉*/
    quec_gnss_uart_low_power();
	#ifdef QUEC_GPS_SUPPORT
	#ifndef CRANELS_SUPPORT
	//20230720 初始化5311 gnss相关引脚
	quec_asr_gnss_pin_init();
	#endif
	#endif
    if(quec_gps_config_param.autogps == 1){
		quec_gnss_onff_set(1); //@20221117 当使能autogps功能时，qgps状态设置为开
        quec_gnss_open();
    }
	
	
}


nmeasrc_sentences *at_get_nmea_cache(void)
{
    return &nmea_data;
}

/*和芯的接口才支持星历查询接口*/
#ifdef  HX_GNSS_SUPPORT
void quec_hx_agps_sate(quec_gnss_sate_num_t* sate)
{
	quec_gps_handle * gnss_urc_cfg = &quec_gps_config_param;
   	if(gnss_urc_cfg->urc_enable & GNSS_URC_AGPS_ENABLE)
	{
		char ccIndBuf[128] = {0};
		snprintf(ccIndBuf, sizeof("+QGPS: \"agps\",0,0"), "+QGPS: \"agps\",0,%d", sate->agps_status);		
		at_urc_send(NUM_OF_TEL_ATP, (uint8 *)ccIndBuf, strlen("+QGPS: \"agps\",0,0"), FALSE, URC_OUT_METHOD_UNICAST, NULL);
		GPS_LOGI("%s",ccIndBuf);
	}

}

#endif 
#endif

/*和芯开机成功回调*/
void quec_gnss_open_success_cb(int status_code)
{
#ifdef QUEC_AT_GPS_ENABLE 
			quec_gps_handle * gnss_urc_cfg = &quec_gps_config_param;
		//20230725 兼容老客户，针对某些出货项目保留原URC上报，新增新URC
#if defined (__QUECTEL_PROJECT_EC200MCN_GB__) || defined(__QUECTEL_PROJECT_EC800MCN_GA__)\
		|| defined(__QUECTEL_PROJECT_EC800MCN_GB__) || defined(__QUECTEL_PROJECT_EC800MCN_GC__)\
		|| defined(__QUECTEL_PROJECT_EC800MCN_GD__)|| defined(__QUECTEL_PROJECT_EG810MCN_GA__) \
		|| defined (__QUECTEL_PROJECT_EG810MCN_GB__)
			uint8 * ccIndBuf1= "GNSS Update successed!!!!";
			at_urc_send(NUM_OF_TEL_ATP, (uint8 *)ccIndBuf1, strlen(ccIndBuf1), FALSE, URC_OUT_METHOD_UNICAST, NULL);
			GPS_LOGI("GNSS Update successed!!!!");
#endif
			if(gnss_urc_cfg->urc_enable & GNSS_URC_FIRM_ENABLE)
			{
				char ccIndBuf[128] = {0};
				snprintf(ccIndBuf, sizeof("+QGPS: \"firmware\",0,0"), "+QGPS: \"firmware\",0,%d", status_code);
				at_urc_send(NUM_OF_TEL_ATP, (uint8 *)ccIndBuf, strlen("+QGPS: \"firmware\",0,0"), FALSE, URC_OUT_METHOD_UNICAST, NULL);
				GPS_LOGI("%s",ccIndBuf);
			}
#endif

}


void * quec_get_location_para(void)
{
    return &gnss_nmea;
}
quec_gps_handle *quec_gnss_config_para_get(void)
{
    return &quec_gps_config_param;
}

int quec_set_gnss_nmea_mode(nmea_mode_t mode)
{
    nmea_mode = mode;
    return 0;
}

#ifdef YS_GNSS_SUPPORT
quec_gps_handle*  quec_ys_cfg_param_get(void)
{
	return &quec_gps_config_param; 
}
#endif

int quec_agps_param_cfg(quec_agps_cfg_t *quec_agps_cfg)
{
	if(!quec_agps_cfg){
		RTI_LOG("invalid param");
		return -1;
	}
	if((quec_agps_cfg->profile_inx <1) || (quec_agps_cfg->profile_inx >7)){
		RTI_LOG("profile_inx is invalid");
		return -1;
	}
	if(strlen(quec_agps_cfg->agps_url)<=0 || strlen(quec_agps_cfg->agps_url)>128){
		RTI_LOG("agps_url set is invalid");
		return -1;
	}
	if(strlen(quec_agps_cfg->agpsvendorID)<=0 || strlen(quec_agps_cfg->agpsvendorID)>50){
		RTI_LOG("agpsvendorID is invalid");
		return -1;
	}
	if(strlen(quec_agps_cfg->agpsmodelID)<=0 || strlen(quec_agps_cfg->agpsmodelID)>25){
		RTI_LOG("agpsmodelID is invalid");
		return -1;
	}
	if(strlen(quec_agps_cfg->agpspassWord)<=0 || strlen(quec_agps_cfg->agpspassWord)>50){
		RTI_LOG("agpspassWord is invalid");
		return -1;
	}

	int agps_param_ok = 0;
	if(quec_agps_cfg->profile_inx != quec_gps_config_param.quec_agps_cfg.profile_inx)
	{
		quec_gps_config_param.quec_agps_cfg.profile_inx = quec_agps_cfg->profile_inx;
		agps_param_ok++;
	}
	if(strcmp(quec_agps_cfg->agps_url,(const char *)quec_gps_config_param.quec_agps_cfg.agps_url)!=0)
	{
		strncpy(quec_gps_config_param.quec_agps_cfg.agps_url,quec_agps_cfg->agps_url,strlen(quec_agps_cfg->agps_url)+1);
		agps_param_ok++;
	}
	if(strcmp(quec_agps_cfg->agpsvendorID,(const char *)quec_gps_config_param.quec_agps_cfg.agpsvendorID)!=0)
	{
		strncpy(quec_gps_config_param.quec_agps_cfg.agpsvendorID,quec_agps_cfg->agpsvendorID,strlen(quec_agps_cfg->agpsvendorID)+1);
		agps_param_ok++;
	}
	if(strcmp(quec_agps_cfg->agpsmodelID,(const char *)quec_gps_config_param.quec_agps_cfg.agpsmodelID)!=0)
	{
		strncpy(quec_gps_config_param.quec_agps_cfg.agpsmodelID,quec_agps_cfg->agpsmodelID,strlen(quec_agps_cfg->agpsmodelID)+1);
		agps_param_ok++;
	}

	if(strcmp(quec_agps_cfg->agpspassWord,(const char *)quec_gps_config_param.quec_agps_cfg.agpspassWord)!=0)
	{
		strncpy(quec_gps_config_param.quec_agps_cfg.agpspassWord,quec_agps_cfg->agpspassWord,strlen(quec_agps_cfg->agpspassWord)+1);
		agps_param_ok++;
	}
	RTI_LOG("agps_param_ok:%d",agps_param_ok);
#ifdef QUEC_AT_GPS_ENABLE
	if(agps_param_ok != 0)
	{
		if(quec_gps_handle_set()>0)
		{
			return -2;
		}
	}
#endif
	return 0;
}


void quec_gnss_open(void)
{
	    
    /*STEP 1: gps通讯总线初始化*/
    gps_channel_init();
    GPS_NW_ACT();

	quec_gps_handle * gps_at_cfg_para = &quec_gps_config_param; 
   /*NMEA数据输出口*/
#ifdef QUEC_AT_GPS_ENABLE
    if((gps_at_cfg_para->outport.outport_en != PORT_NONE)&& gps_at_cfg_para->outport.out_channel != PORT_USBNMEA){
		//20231025 配置debug口输出nmea语句，需要配置uart2为ATCMD模式
		if(g_uart2_mode != QUEC_UART2_MODE_TO_ATCMD){
			extern QuecOSStatus quec_uart2_mode_set(quec_uart2_mode_e mode);
			quec_uart2_mode_set(QUEC_UART2_MODE_TO_ATCMD);
		}
		if (quec_siolib_port_is_in_raw_data_mode((TelAtParserID)gps_at_cfg_para->outport.out_channel)){
			GPS_LOGI("atpindex(%d) is in raw data mode!!!", gps_at_cfg_para->outport.out_channel);
		}
		else{
			if (!quec_siolib_port_enter_raw_mode((TelAtParserID)gps_at_cfg_para->outport.out_channel, QUEC_SIOLIB_PORT_FOR_GPS, NULL)){
				GPS_LOGI("enter_raw_mode failed %d",gps_at_cfg_para->outport.out_channel);
			}
			GPS_LOGI("enter_raw_mode success out_channel=%d",gps_at_cfg_para->outport.out_channel);
		}
	}
#endif
#ifdef  QUEC_GPS_SUPPORT
	RTI_LOG("ASR GPS OPEN!!!!");
    if(asr_init_flag == 0)
    {   
        asr_gnss_open(&quec_asr_gps_callbacks);
        asr_init_flag = 1;
    }
#ifdef QUEC_AT_GPS_ENABLE
	else 
	{
		asr_urc_flag = 1;
	}
#endif
    /*step1:是否需要打开agps功能*/
    if(gps_at_cfg_para->agps_cfg.agps_en) {
        quec_asr_agps_enable(1);
    }else{
        quec_asr_agps_enable(0);
    }
    asr_gnss_reg_user_cb(quec_asr_gps_user_callback);
	//20230617 因5311gnss仅在首次上电打开时会加载固件，后续关闭（休眠gnss）,打开（唤醒gnss）
	//不会进行固件加载，且agps会两小时更新一次也不会上报，为了ST兼容，针对后续打开gnss做假实现上报URC
#ifdef QUEC_AT_GPS_ENABLE
	if(asr_urc_flag)
	{
		//20230625 校验星历数据是否有效，有效则直接上报agps ok
		if(!is_agps_needed())
		{
			quec_asr_gps_user_callback(ASR_GPS_SEND_DATA_SUCCESS,NULL,0);
		}
		else 
		{
			//若星历数据失效，则check网络状态
			if(!GPS_GET_NETIF_STATUS())
			{
				quec_asr_gps_user_callback(ASR_GPS_PDP_FAIL,NULL,0);
			}
		}
		//固件加载urc上报
		quec_asr_gps_user_callback(ASR_GPS_INITIAL_SUCCESS,NULL,0);
	}
#endif
    asr_gnss_set_workmode(1);
    GnssLocationProvider_start();
#elif  defined(HX_GNSS_SUPPORT)
    char gnss_type = 0;
	int gnss_rom_type = quec_gnss_type_check();
	int gnss_vbckp_select = quec_hx_bckp_get();
	if((2==gnss_rom_type)&&(0 == gnss_vbckp_select)){
		gnss_rom_type = 3;//20231011 add type 3:ROM2不接备电
	} 
    quec_agps_ref_t * agps_ref = quec_agps_ref_get();
	quec_gnss_apflash_struct_t *gnss_apflash = get_hx_apflash_req_status();
    	
    /*step1:是否需要打开agps功能*/
    if(gps_at_cfg_para->agps_cfg.agps_en) {
        agps_ref->agps_en = 1;
    }else{
        agps_ref->agps_en = 0;
    }
    /*step2:请求agps数据类型*/
    gnss_type = gps_at_cfg_para->agps_cfg.agps_type;
    if(gnss_type&EPH_GP || gnss_type&EPH_BD ||
     gnss_type&EPH_GL || gnss_type&EPH_GA || gnss_type&EPH_QZ){
        agps_ref->agps_type = gnss_type;
     }else{
        agps_ref->agps_type = EPH_GP|EPH_BD|EPH_GA;
    }
     
	if((1 == gnss_rom_type) ||(3 == gnss_rom_type))
	{
		/*step3:是否请求agflash数据*/
		if(gps_at_cfg_para->apflash){
			gnss_apflash->en=1;
		}
		else{
			gnss_apflash->en=0;
		}
	}
  
    if(hx_init_flag == 0){
        quec_gps_init();
        hx_init_flag = 1;
    }
    QUEC_GPS_DEV_T * HX_GPS_DEV;
    HX_GPS_DEV = quec_get_gps_dev();
    if(HX_GPS_DEV->ops)
    {
        HX_GPS_DEV->ops->q_reg_open_gps_success_cb(quec_gnss_open_success_cb);
        HX_GPS_DEV->ops->q_gps_open();
        HX_GPS_DEV->ops->q_reg_location_update_cb(hx_location_update);
        if(nmea_mode == STR_MODE){
        HX_GPS_DEV->ops->q_reg_nmea_str_cb(hx_at_nmea_callback);
        }else{
        HX_GPS_DEV->ops->q_reg_nmea_packet_cb(hx_nmea_packet_cb);
        }
        #ifdef QUEC_AT_GPS_ENABLE /*标准agps成功的urc上报*/
        HX_GPS_DEV->ops->q_reg_agps_sate_num_cb(quec_hx_agps_sate);
        #endif
    }
	/*felix.liu @20230128 宇松定制需求,打开gps时，gpio5拉高，使能外部ldo*/
#ifdef YS_GNSS_SUPPORT
	GPS_GPIO_Set_Level(YS_GNSS_LDO_PIN_NUM,1);
#endif
#else
    #error "No Define GPS"
#endif
	quec_gnss_open_flag = 1;
}

int quec_gnss_close(void)
{
    if(quec_gnss_open_flag == 0)
    {
        return QUEC_GPS_NOT_OPEN_ERROR;
    }
    
    if(GPS_NW_DEACT) {
        GPS_NW_DEACT();
    }
	//20230516 每次关闭gnss时清除AT+QGPSLOC、AT+QGPSGNMEA语句缓存buff，
	//防止出现打开gps后并未等出现GNSS Update successed!!!!立即发送AT+QGPSGNMEA指令或是AT+QGPSLOC指令返回上一次定位的信息
	memset(&gnss_nmea,0,sizeof(gnss_nmea));
#ifdef QUEC_AT_GPS_ENABLE/*std*/
	memset(&nmea_data,0,sizeof(nmea_data));
#endif
#ifdef  QUEC_GPS_SUPPORT
    asr_aboot_dl_thread_delete();
    asr_gnss_set_workmode(0);
    GnssLocationProvider_stop();
#elif  defined(HX_GNSS_SUPPORT)
    QUEC_GPS_DEV_T * HX_GPS_DEV;
    HX_GPS_DEV = quec_get_gps_dev();
    if(HX_GPS_DEV->ops)
    {
        if(HX_GPS_DEV->ops->q_gps_close() == QUEC_GPS_NOT_OPEN_ERROR)
		{
			return QUEC_GPS_NOT_OPEN_ERROR;
		}
        HX_GPS_DEV->ops->q_reg_location_update_cb(NULL);
        HX_GPS_DEV->ops->q_reg_nmea_str_cb(NULL);
        HX_GPS_DEV->ops->q_reg_nmea_packet_cb(NULL);
    }
/*felix.liu @20230128 宇松定制需求,关闭gps时，gpio5拉低，失能外部ldo*/
#ifdef YS_GNSS_SUPPORT
	GPS_GPIO_Set_Level(YS_GNSS_LDO_PIN_NUM,0);
#endif
#else
    #error "No Define GPS"
#endif
	quec_gnss_open_flag = 0;
	return QUEC_GPS_NO_ERROR;
}

int hx_v_bckp_select = 1;//@20231009 用于判断客户rom2 oc硬件是否连接备电引脚 默认连接备电引脚
void quec_hx_bckp_set(int value)
{
	hx_v_bckp_select = value;
}

int quec_hx_bckp_get(void)
{
	return hx_v_bckp_select;
}


#ifdef HX_GNSS_SUPPORT
#ifdef QUEC_AT_GPS_ENABLE
//20230706 车网定制需求 获取GPS 以及BDS cn值最强前三组卫星
gsv_param_filter_t gsv_param_filter[2] ={0};
gsv_sentences_t *gsv_sentences = NULL;
int quec_gsv_filter_process(sat_info_t * sat_info)
{
	int i,j,k;
	char *values[20];
	char *value;
	int value_index;
	int value_num ;
	char *sentences_tmp = NULL;
	char *token = NULL;
	if(!gsv_sentences)
	{
		//为gps bds gsv语句申请内存
		gsv_sentences = malloc(sizeof(gsv_sentences_t)*2) ;
		
		if(!gsv_sentences)
		{
			GPS_LOGE("gsv filter err 1");
			return -1;
		}
	}

	memset(gsv_sentences,0,sizeof(gsv_sentences_t)*2);
	memset(gsv_param_filter,0,sizeof(gsv_param_filter_t)*2);
	//Copy the first gsv statement of GPS BDS to obtain the total number of gsv statements and the total number of visual satellites
	if(strlen(nmea_data.gsv_sentences[QUEC_GPS].gp_gsv_sent[0]))
	{
		memcpy(gsv_sentences->gsv_nmeas[0],nmea_data.gsv_sentences[QUEC_GPS].gp_gsv_sent[0],128);
	}
	if(strlen(nmea_data.gsv_sentences[QUEC_BDS].gp_gsv_sent[0]))
	{
		memcpy((gsv_sentences+1)->gsv_nmeas[0],nmea_data.gsv_sentences[QUEC_BDS].gp_gsv_sent[0],128);
	}

	//get gsv total_msgs and total_sats
	for(i=0;i<2;i++)
	{
		sentences_tmp = (gsv_sentences+i)->gsv_nmeas[0];
		token = strtok(sentences_tmp,",");
		if(!token)
		{
			GPS_LOGE("gsv filter err 2");
			goto error;
		}
		if (NULL == memchr(token, '$', 6)){
			GPS_LOGE("gsv filter err 3");
			goto error;
		}
		token = strtok(NULL, ",");
		gsv_param_filter[i].total_msgs = atoi(token);
	    token = strtok(NULL, ",");
        token = strtok(NULL, ",");
		gsv_param_filter[i].total_sats = atoi(token);
		memset((gsv_sentences+i)->gsv_nmeas[0],0,128);
	}

	//copy nmea_data to gsv_sentences
	for(i=0;i < GSV_NUM ;i++)
	{
		if(strlen(nmea_data.gsv_sentences[QUEC_GPS].gp_gsv_sent[i]))
		{
			memcpy(gsv_sentences->gsv_nmeas[i],nmea_data.gsv_sentences[QUEC_GPS].gp_gsv_sent[i],128);
		}
		if(strlen(nmea_data.gsv_sentences[QUEC_BDS].gp_gsv_sent[i]))
		{
			memcpy((gsv_sentences+1)->gsv_nmeas[i],nmea_data.gsv_sentences[QUEC_BDS].gp_gsv_sent[i],128);
		}
	}
	//Save gps and bds sat_values,cn_value
	for(i=0;i<2;i++)
	{
		for(j=0;j < gsv_param_filter[i].total_msgs;j++)
		{
			sentences_tmp = (gsv_sentences+i)->gsv_nmeas[j];
		    value_num = _split_string_by_comma(sentences_tmp+7, values, ARRAY_LENGTH(values));
		    for(value_index=0;value_index < value_num -1;value_index++)
		    {
				value = values[value_index];
				if (NULL == value || '\0' == *value)
				{
					continue;
				}

				switch (value_index)
				{				
					case NMEA_GPGSV_SAT_INFO_NR1:
					case NMEA_GPGSV_SAT_INFO_NR2:
					case NMEA_GPGSV_SAT_INFO_NR3:
					case NMEA_GPGSV_SAT_INFO_NR4:
						gsv_param_filter[i].sat[gsv_param_filter[i].sat_index++] = atoi(value);
						break;
					case NMEA_GPGSV_SAT_INFO_SNR1:
					case NMEA_GPGSV_SAT_INFO_SNR2:
					case NMEA_GPGSV_SAT_INFO_SNR3:
					case NMEA_GPGSV_SAT_INFO_SNR4:
						gsv_param_filter[i].cn[gsv_param_filter[i].cn_index++] = atoi(value);
						break;
					default:
						break;
				}
			}
			
		}
		//Find the top three groups with the strongest gps and bds cn values and the recorded locations

		for(j=0;j<3;j++)
		{
			for(k=0;k<gsv_param_filter[i].total_sats;k++)
			{
				if(gsv_param_filter[i].cn_max[j]<gsv_param_filter[i].cn[k])
				{
					gsv_param_filter[i].cn_max[j]=gsv_param_filter[i].cn[k];
					gsv_param_filter[i].cn_item[j] = k ;
				}
			}
			gsv_param_filter[i].cn[gsv_param_filter[i].cn_item[j]] = 0;
			gsv_param_filter[i].sat_max[j] = gsv_param_filter[i].sat[gsv_param_filter[i].cn_item[j]];
		}
		
	}
	
	for(i=0;i<3;i++)
	{
		sat_info->gps_cn[i] = gsv_param_filter[0].cn_max[i];
		sat_info->gps_sat[i] = gsv_param_filter[0].sat_max[i];
		sat_info->bds_cn[i] = gsv_param_filter[1].cn_max[i];
		sat_info->bds_sat[i] = gsv_param_filter[1].sat_max[i];
	}
	return 0;
error :
	if(gsv_sentences)
	{
		free(gsv_sentences);
		gsv_sentences = NULL;
	}
	return -1;
	
}

void quec_hx_debug_ctrl_set(int debug_ctrl)
{
	hx_debug_ctrl = debug_ctrl;
	if(1 == hx_debug_ctrl)
	{
		nmea_mode = PACKET_MODE;
	}
	else 
	{
		nmea_mode = STR_MODE;
	}
}

int quec_hx_debug_ctrl_get(void)
{
	return hx_debug_ctrl;
}

#endif 
#endif
int quec_gnss_reset(int type)
{
    if(quec_gnss_open_flag == 0)
    {
        return -1;
    }
#ifdef  QUEC_GPS_SUPPORT
    asr_gps_reset(type);
    return 0;
#elif  defined(HX_GNSS_SUPPORT)
    QUEC_GPS_DEV_T * HX_GPS_DEV;
    HX_GPS_DEV = quec_get_gps_dev();
    if(HX_GPS_DEV->ops)
    {
        return  HX_GPS_DEV->ops->q_gps_reset(type);
    }
	else
	{
    	return -1;
	}
#else
    #error "No Define GPS"
#endif 
}

int quec_set_agps_file(void)
{
#ifdef  QUEC_GPS_SUPPORT
    return 0;
#elif  defined(HX_GNSS_SUPPORT)
    return quec_hx_apgs_cust_send();
#endif
}

int quec_send_agps_to_gps(char *data,int len)
{
#ifdef  QUEC_GPS_SUPPORT
#ifdef QUEC_ASR_GNSS_SUPPORT
    extern int quec_send_agps_data_asr(char *data,int len);
	return quec_send_agps_data_asr(data,len);
#else 
	return 0;
#endif
#elif  defined(HX_GNSS_SUPPORT)
    return quec_send_agps_data(data,len);
#endif
}

int quec_gnss_sys_set(int sys_type)
{
#ifdef  QUEC_GPS_SUPPORT 
   return quec_asr_set_gnss_sys(sys_type);
#elif  defined(HX_GNSS_SUPPORT)
   return quec_hx_gnss_sys_set(sys_type);
#else
   #error "No Define GPS"
#endif
}

int quec_gnss_nmea_set(int value)
{
#ifdef  QUEC_GPS_SUPPORT 
   return quec_asr_set_gnss_nmea(value);
#elif  defined(HX_GNSS_SUPPORT)
   return quec_hx_gnss_nmea_set(value);
#else
   #error "No Define GPS"
#endif
}

void quec_get_agps_sate_num(gnss_ephemeris_info cb)
{
#ifdef  QUEC_GPS_SUPPORT 
#elif  defined(HX_GNSS_SUPPORT)
    QUEC_GPS_DEV_T * HX_GPS_DEV;
    HX_GPS_DEV = quec_get_gps_dev();
    if(HX_GPS_DEV->ops)
    {
        HX_GPS_DEV->ops->q_reg_agps_sate_num_cb(cb);
    }
#else
    #error "No Define GPS"
#endif
}

/*nmea callback*/
#ifdef  QUEC_GPS_SUPPORT
void asr_nmea_callback(GpsUtcTime timestamp, const char* nmea, int length)
{
#ifdef QUEC_AT_GPS_ENABLE  /*STD*/
    quec_gps_type quec_gps;
    int i;
    int err = 0;
    unsigned int port_channel;
	quec_rtc_time_t tm;
	static unsigned int last_time=0;
	
	/*解决可生产测试单系统单颗星获取CN值有误*/
	QUEC_RTC_GetTime(&tm);

    if(last_time != (unsigned int)tm.quec_tm_sec){
        memset(nmea_data.gsv_sentences,0,sizeof(nmea_data.gsv_sentences));
		memset(&nmea_data.gsa_sentences,0,sizeof(nmea_data.gsa_sentences));
        last_time = (unsigned int)tm.quec_tm_sec;
    }
    if (strncmp(nmea + 1, "GP", 2) == 0){
        quec_gps = QUEC_GPS;
	}
    else if (strncmp(nmea + 1, "BD", 2) == 0){
        quec_gps = QUEC_BDS;
	}
    else if (strncmp(nmea + 1, "GN", 2) == 0){
        quec_gps = QUEC_MULTISYS;
	}
	else if (strncmp(nmea + 1, "GL", 2) == 0){
        quec_gps = QUEC_GLONASS;
	}
	else if (strncmp(nmea + 1, "GA", 2) == 0){
        quec_gps = QUEC_GALILEO;
	}
    else 
    {
        err = 1;
    }

    if(!err){
		//20231226 屏蔽非nmea类型语句输出
		if(quec_get_outport(&port_channel)){
			quec_siolib_transmit_to_atp((TelAtParserID)port_channel,(uint8 *)nmea,length,NULL);	
		}
        if (strncmp(nmea + 3, "RMC", 3) == 0){
		   memset(nmea_data.rmc_sentences.gp_rmc_sent,0,128);
           memcpy(nmea_data.rmc_sentences.gp_rmc_sent,nmea,length);
    	}
        else if (strncmp(nmea + 3, "GGA", 3) == 0){
			memset(nmea_data.gga_sentences.gp_gga_sent,0,128);
			memcpy(nmea_data.gga_sentences.gp_gga_sent,nmea,length);
    	}
        else if (strncmp(nmea + 3, "GSA", 3) == 0){
		    for(i=0;i<GSA_NUM;i++)
	        {
	            if(strlen(nmea_data.gsa_sentences.gp_gsa_sent[i]) == 0)
	            {
	                memcpy(nmea_data.gsa_sentences.gp_gsa_sent[i],nmea,length);
	                break;
	            }
	        }
    	}
        else if (strncmp(nmea + 3, "GSV", 3) == 0){
            for(i=0;i<GSV_NUM;i++){
                if(strlen(nmea_data.gsv_sentences[quec_gps].gp_gsv_sent[i]) == 0){
                    memcpy(nmea_data.gsv_sentences[quec_gps].gp_gsv_sent[i],nmea,length);
                    break;
                }
            }
    	}
    	else if (strncmp(nmea + 3, "VTG", 3) == 0){
			memset(nmea_data.vtg_sentences.gp_vtg_sent,0,128);
    		memcpy(nmea_data.vtg_sentences.gp_vtg_sent,nmea,length);
    	}
		else if (strncmp(nmea + 3, "GLL", 3) == 0){
			memset(nmea_data.gll_sentences.gp_gll_sent,0,128);
    		memcpy(nmea_data.gll_sentences.gp_gll_sent,nmea,length);
    	}
		else if (strncmp(nmea + 3, "GST", 3) == 0){
			memset(nmea_data.gst_sentences.gp_gst_sent,0,128);
    		memcpy(nmea_data.gst_sentences.gp_gst_sent,nmea,length);
    	}
    }
#else /*OPENCPU*/
    if(ql_gnss_nmea_data_cb)
        ql_gnss_nmea_data_cb(nmea,length);
#endif

}

void asr_update_location(GpsLocation* location)
{
    unsigned int timestamp = 0;
    struct tm time;
    if(location->flags != 0){
        gnss_nmea.valid = 1;
    }else{
        gnss_nmea.valid = 0;
    }
    gnss_nmea.latitude = location->latitude;
    if(location->latitude < 0){
        gnss_nmea.latitude_cardinal = 'S';
		gnss_nmea.latitude = -location->latitude;
    }else{
        gnss_nmea.latitude_cardinal = 'N';
    }
    gnss_nmea.longitude = location->longitude;
    if(location->longitude < 0) {
        gnss_nmea.longitude_cardinal = 'W'; 
		gnss_nmea.longitude = -location->longitude;
    }else{
        gnss_nmea.longitude_cardinal = 'E'; 
    }
    gnss_nmea.heading = location->bearing;
    gnss_nmea.gps_speed = location->speed;
    gnss_nmea.fix_mode = location->mode;
    timestamp = (unsigned int)(location->timestamp);
    gmtime_r(&timestamp,&time);
    gnss_nmea.time.tm_hour = time.tm_hour;
    gnss_nmea.time.tm_sec =  time.tm_sec;
    gnss_nmea.time.tm_min =  time.tm_min;
    gnss_nmea.time.tm_mday = time.tm_mday;
    gnss_nmea.time.tm_mon = time.tm_mon+1;
    gnss_nmea.time.tm_year = time.tm_year+1900-2000;
    gnss_nmea.altitude = location->altitude;
    gnss_nmea.hdop = location->accuracy;
    gnss_nmea.pdop = location->accuracy;
	#ifdef QUEC_ASR_GNSS_SUPPORT
	gnss_nmea.satellites_num = location->svs_num;
	#endif
}

#elif  defined(HX_GNSS_SUPPORT)

#ifdef QUEC_AT_GPS_ENABLE /*STD*/
qgps_proto_nmea_src_e_type hx_2_quec_nmea_type(nmea_type type)
{
    qgps_proto_nmea_src_e_type ret = QGPS_PROTO_NMEA_SRC_MAX;
    switch(type)
	{
		case NMEA_GGA:
            ret = QGPS_PROTO_NMEA_SRC_GGA;
		break;
		case NMEA_GSA:
		    ret = QGPS_PROTO_NMEA_SRC_GSA;
		break;
		case NMEA_GSV:
		    ret = QGPS_PROTO_NMEA_SRC_GSV;
		break;
		case NMEA_RMC:
		    ret = QGPS_PROTO_NMEA_SRC_RMC;
		break;
		case NMEA_VTG:
		    ret = QGPS_PROTO_NMEA_SRC_VTG;
		break;
		case NMEA_GLL:
		    ret = QGPS_PROTO_NMEA_SRC_GLL;
		break;
		case NMEA_GST:
		    ret = QGPS_PROTO_NMEA_SRC_GST;
		break;
		default:
			break;
    }
    return ret;
}
quec_gps_type hx_2_quec_gps_type(satellite_type sat_type)
{
    quec_gps_type ret = QUEC_GT_MAX;
    switch(sat_type)
	{
		case SAT_GPS:
            ret = QUEC_GPS;
		break;
		case SAT_GLONASS:
		    ret = QUEC_GLONASS;
		break;
		case SAT_GALILEO:
		    ret = QUEC_GALILEO;
		break;
		case SAT_BDS:
		    ret = QUEC_BDS;
		break;
		case SAT_MULTISYS:
		    ret = QUEC_MULTISYS;
		break;
		default:
			break;
    }
    return ret;
}
#endif

void hx_at_nmea_callback(struct tm *time,char* nmea, int length)
{
 #ifdef QUEC_AT_GPS_ENABLE/*STD*/ 	
    nmea_type type;
    qgps_proto_nmea_src_e_type type2;
    satellite_type sat_type;
    quec_gps_type quec_gps;
    int i;
    unsigned int port_channel;
	quec_rtc_time_t tm;
	static unsigned int last_time=0;
	
	if(quec_get_outport(&port_channel)){
		quec_siolib_transmit_to_atp((TelAtParserID)port_channel,(uint8 *)nmea,length,NULL);	
	}
	
	/*解决可生产测试单系统单颗星获取CN值有误*/
	QUEC_RTC_GetTime(&tm);
	
    if(last_time != tm.quec_tm_sec)
    {
        memset(nmea_data.gsv_sentences,0,sizeof(nmea_data.gsv_sentences));
		memset(&nmea_data.gsa_sentences,0,sizeof(nmea_data.gsa_sentences));
		last_time = tm.quec_tm_sec;
    }
	
	if (NMEA_UNKNOWN == (type=nmea_get_type(nmea))){
		GPS_LOGE("nmea get type unknown! \r\n");
		return ;
	}
    if (SAT_UNKNOWN == (sat_type = nmea_satellite_check(nmea))){
		GPS_LOGE("nmea get sat_type unknown! \r\n");
		return;
	}
    type2 = hx_2_quec_nmea_type(type);
    quec_gps = hx_2_quec_gps_type(sat_type);
    switch(type2)
	{
		case QGPS_PROTO_NMEA_SRC_GGA:
		{
			memset(nmea_data.gga_sentences.gp_gga_sent,0,128);
            memcpy(nmea_data.gga_sentences.gp_gga_sent,nmea,length);
		}
		break;
		case QGPS_PROTO_NMEA_SRC_GSA:
		{
			for(i=0;i<GSA_NUM;i++)
            {
                if(strlen(nmea_data.gsa_sentences.gp_gsa_sent[i]) == 0)
                {
                    memcpy(nmea_data.gsa_sentences.gp_gsa_sent[i],nmea,length);
                    break;
                }
            }
		}
		break;
		case QGPS_PROTO_NMEA_SRC_GSV:
		{
            for(i=0;i<GSV_NUM;i++)
            {
                if(strlen(nmea_data.gsv_sentences[quec_gps].gp_gsv_sent[i]) == 0)
                {
                    memcpy(nmea_data.gsv_sentences[quec_gps].gp_gsv_sent[i],nmea,length);
                    break;
                }
            }
		}
		break;
		case QGPS_PROTO_NMEA_SRC_RMC:
		{
			memset(nmea_data.rmc_sentences.gp_rmc_sent,0,128);
            memcpy(nmea_data.rmc_sentences.gp_rmc_sent,nmea,length);
		}
		break;
		case QGPS_PROTO_NMEA_SRC_VTG:
		{
			memset(nmea_data.vtg_sentences.gp_vtg_sent,0,128);
            memcpy(nmea_data.vtg_sentences.gp_vtg_sent,nmea,length);
		}
		break;
		case QGPS_PROTO_NMEA_SRC_GLL:
		{
			memset(nmea_data.gll_sentences.gp_gll_sent,0,128);
            memcpy(nmea_data.gll_sentences.gp_gll_sent,nmea,length);
		}
		break;
		case QGPS_PROTO_NMEA_SRC_GST:
		{
			memset(nmea_data.gst_sentences.gp_gst_sent,0,128);
            memcpy(nmea_data.gst_sentences.gp_gst_sent,nmea,length);
		}
		break;
		default:
			break;
    }
#else/*OPENCPU*/
    if(ql_gnss_nmea_data_cb)
        ql_gnss_nmea_data_cb(nmea,length);
#endif
}

void hx_nmea_packet_cb(char* packet, int length)
{
    #ifndef QUEC_AT_GPS_ENABLE  /*OPEN*/
    if(ql_gnss_nmea_data_cb)
    ql_gnss_nmea_data_cb(packet,length);
	#else
	unsigned int port_channel;
	if(quec_get_outport(&port_channel)){
		quec_siolib_transmit_to_atp((TelAtParserID)port_channel,(uint8 *)packet,length,NULL);	
	}
    #endif
}

void hx_location_update   (hx_locationg_t *gps_data)
{
    gnss_nmea.valid = gps_data->valid;
    gnss_nmea.latitude=  gps_data->latitude;
    gnss_nmea.latitude_cardinal = gps_data->latitude_cardinal;
    gnss_nmea.longitude = gps_data->longitude;
    gnss_nmea.longitude_cardinal = gps_data->longitude_cardinal;
    gnss_nmea.heading = gps_data->heading;
    gnss_nmea.gps_speed = gps_data->gps_speed;
    gnss_nmea.time = gps_data->time;
    gnss_nmea.hdop = gps_data->hdop;
    gnss_nmea.pdop = gps_data->pdop;
    gnss_nmea.cogt = gps_data->cogt;
    gnss_nmea.kph  = gps_data->kph;
    gnss_nmea.sog  = gps_data->sog;
    gnss_nmea.satellites_num = gps_data->satellites_num;
    gnss_nmea.fix_mode = gps_data->fix_mode;
    gnss_nmea.altitude = gps_data->altitude;

}
#else
#error "No Define GPS"
#endif


