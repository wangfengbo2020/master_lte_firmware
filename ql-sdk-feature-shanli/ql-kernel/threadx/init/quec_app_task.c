/**
 ******************************************************************************
 * @file    quec_app_task.c
 * @author  Chavis.Chen
 * @version V1.0.0
 * @date    26-Sep-2018
 * @brief   This file contains the quec_app_task
 *			throughout the project.
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2014 QUECTEL Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 */

/*=================================================================

						EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN			  WHO		  WHAT, WHERE, WHY
------------	 -------	 -------------------------------------------------------------------------------
11/02/2018		  Jensen	  to call hal init
=================================================================*/

#include "quec_include.h"
#include "quec_urc.h"
#include "quec_sockets.h"
#include "quec_apptcpip_main.h"
#ifdef QUEC_FTP_SUPPORT
#include "quec_ftp_main.h"
#endif
#ifdef QUECTEL_IOT_RPT_SUPPORT
#include "quec_iot_main.h"
#endif
#include "quec_fota_feed_task.h"
#include "quec_cust_feature.h"
#include "quec_ppp.h"
#include "quec_net.h"
#include "quec_recovery_task.h"
#include "quec_fota_update_task.h"
#include "quec_cmux.h"
#include "quec_mqtt_main.h"
#include "quectel_tts_taskmgr.h"
#include "quec_nc_kalive_app.h"
#include "quec_temp_task.h"
#include "quec_gpio.h"
#include "quec_led_task.h"
#ifdef QUEC_TCIOT_SUPPORT
#include "quec_tencent_iot_atcmd.h"
#endif
#ifdef QUEC_SMTP_SUPPORT
#include "quec_smtp_main.h"
#endif
#ifdef QUEC_AT_SOCKET_SUPPORT
#include "quec_at_socket_app.h"
#endif
#include "ningbo.h"
#include "quec_atcmd_para_init.h"

#ifndef MIN_SYS

#ifdef QUEC_CUST_XIPING_SUPPORT
#include "quec_atcmd_cust_xiping.h"
#endif

#define app_log(msg, ...)	custom_log("APP", msg, ##__VA_ARGS__)

static quec_sem_t	quec_app_rdy_sem = NULL;
char quec_cust_task_init_done = 0;
#ifdef FEATURE_QUECTEL_LOCATOR_APP
extern QuecOSStatus quec_locator_main(void);/*QUECcodeflag20190803*/
extern int  quec_tcpudp_app_main(void);
#endif
extern bool quec_init_done;
uint8_t quec_audio_init_done = 0;
#if QUEC_CALL_OPTIMIZE_CLIP_COLP
extern void quec_clip_colp_init(void);
#endif
#ifdef QUEC_CUSTOM_LAST_GASP_FEATURE
extern void quec_gasp_init(void);
#endif
#ifdef QUEC_GPIO_CTRL_SUPPORT
extern void quec_gpioctrl_init(void);
#endif
#ifdef QUEC_HEART_BEAT_LPC_FEATURE
extern int quec_heartbeat_param_init(void);
#endif

#if defined(__QUEC_OEM_VER_DM__)
extern void quec_dmhttp_client_init(void);
#endif

extern int broad_kernel_init(void);
//����ģʽ�µ�task��ʼ��
QuecOSStatus quec_cust_task_init(void)
{
	QuecOSStatus err = kNoErr;

	if (quec_cust_task_init_done > 1)
	{
		return err;
	}
	if (0 == InProduction_Mode())
	{
#if defined(QUEC_XLAT_SUPPORT)
	    extern BOOL quec_xlat_init(void);
	    quec_xlat_init();
#endif
		quec_sockets_init();
#ifdef QUEC_HTTP_SUPPORT
		err = quec_http_at_init();
		if (err != kNoErr)
		{
			CPUartLogPrint("http failed!", FALSE);
		}
#endif
		quec_apptcpip_main();

#ifdef QUEC_MMS_SUPPORT
	    quec_mms_main();
#endif

#ifdef QUEC_AT_FILE_CMD
		err = quec_file_task_init();
		if (err != kNoErr)
		{
			CPUartLogPrint("file failed!", FALSE);
		}
#endif

#ifdef QUEC_FTP_SUPPORT
		quec_ftp_main();
#endif

#ifdef QUECTEL_IOT_RPT_SUPPORT
		quec_iot_main();
#endif

#ifdef QUEC_FOTA_FEED_SUPPORT
		//to read fota upgrade result
		//quec_fota_upgrade_result_urc_report();
#endif
#ifdef QUEC_MQTT_SUPPORT
	    quec_mqtt_main();
#endif

#ifdef QUEC_NETWORK_CARD_ENABLE //Chaim2019.02.28 netcard task
        quec_netdevctl_task_init();
#endif
    
#ifdef QUEC_CMUX_ENABLE  //Chaim2018.12.17 need get dtr level,init after siolib
        quec_cmux_task_init();
#endif

#ifdef QUEC_TCP_SERVER_NC_KALIVE_CTRL_ENABLE
		quec_no_connection_keepalive_init();
#endif

#ifdef QUEC_LWM2M_SUPPORT
        quec_lwm2m_main();
#endif

#ifdef FEATURE_QUECTEL_LOCATOR_APP
        quec_locator_main();/*QUECcodeflag20190803*/
#endif

#ifdef QUEC_MSG_PROCESS_LOG_ENABLE  
    quec_msg_handle_task_init();//Chaim 20191011 add msg handle task
#endif

#if defined(QUEC_LED_TASK_SUPPORT)
        quec_led_task_init();
#endif

#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610
	quec_netmode_init();
#endif
	
#ifdef QUEC_TCIOT_SUPPORT
    quec_tciot_context_init(); //evan.li-2020/09/18: add tencent iot cmd support.
#endif

#ifdef QUEC_AT_SOCKET_SUPPORT
	quec_at_socket_task_init();
#endif

    quec_tcpudp_app_main();

#ifdef QUEC_SMTP_SUPPORT
	quec_smtp_main();
#endif

#ifdef QUECTEL_QUECFOTA_SUPPORT
	quec_quecfota_init();
#endif
	
#ifdef QUEC_CUSTOM_LAST_GASP_FEATURE
	quec_gasp_init();
#endif

#ifdef QUEC_GPIO_CTRL_SUPPORT
	quec_gpioctrl_init();
#endif

#ifdef QUEC_HEART_BEAT_LPC_FEATURE
	quec_heartbeat_param_init();
#endif

#ifdef QUECTEL_OPEN_CPU  //at present only open use this function
	ql_ntp_init();
#endif

#ifdef QUEC_MQTT_UNIFY_SUPPORT
	quec_mqtt_uniot_main();
#endif
	broad_kernel_init();
	}
	
	quec_cust_task_init_done = 2;

exit:
	return err;
}

extern UINT8 ATCmdSvrRdy;
#if defined(QUEC_SEND_AT_SUPPORT)
extern BOOL booting_done;
extern UINT32 gServiceRegStatus;
#endif
#ifdef QUEC_POWER_BACKOFF_SUPPORT
extern quec_check_nv_enable_rf3g_pwrbackoff(void);
#endif	

#if (defined(QUEC_NTP_SUPPORT) && defined(__QUEC_OEM_VER_OA__))
#include "quec_ntp_app.h"
extern UINT32  quectel_ntp_client_sync_time(quectel_ntp_sync_param  *sync_params);
void quec_syn_ntp_time(void * argv)
{
	quectel_ntp_sync_param ntp_req = {0};
	
	while(1){
		if(quec_get_regstatus(1)==1  || 1 == InProduction_Mode())
			break;
		OSATaskSleep(10);
	}
	
	ntp_req.pdp_cid = 1;
	ntp_req.atHandle = 0;
	ntp_req.host_port = 123;
	ntp_req.auto_sync_local_time = 1;
	ntp_req.local_port = 0;
	sprintf(ntp_req.host_name, "ntp.aliyun.com");

	if(quectel_ntp_client_sync_time(&ntp_req) != QUEC_APPTCPIP_OK)
	{
		app_log("ntp fail");
	}
	quec_rtos_task_delete_ex(NULL);
}
#endif

static QuecOSStatus quec_init(void)
{
	QuecOSStatus err = kNoErr;
    int ret = kNoErr;
#ifdef QUEC_STARTUP_OPTIMIZATION
	extern UINT32 gPowerupSaveTimeFlag;
	if(gPowerupSaveTimeFlag == 0x5a5a5a5a){
		err = at_urc_init();
		if (err != kNoErr)
		{
			CPUartLogPrint("urc failed!", FALSE);
		}

		err = quec_rdy_report();
		if (err != kNoErr)
		{
			CPUartLogPrint("rdy report failed!", FALSE);
		}
	}
#endif

	quec_at_config_init_from_nv();  //Chaim2019.1.4,init before uart_reinit,need get baudrate here
	
#ifdef QUEC_PPP_ENABLE
	quec_ppp_read_terminateframe_flag();
#endif
	/* ###### Add your functions' corresponding initialization here: ###### */
#ifndef QUECTEL_OPEN_CPU
#ifdef QUEC_FGM842D_WIFI_SUPPORT
    extern void quec_wifi_init(void);
    quec_wifi_init();
#endif
#endif

	/* ======= Add quectel hardware's initialization below: ====== */
	err = quec_hal_init();
	if (err != kNoErr)
	{
		CPUartLogPrint("hal failed!", FALSE);
	}
	#ifdef QUEC_SLAS_SUPPORT
		//20230921 slas��Ȩϵͳ��ʼ��
		extern void quec_slas_init(void);
		quec_slas_init();
	#endif
	/* ======= End of quectel hardware's initialization ====== */

	/* ======= Add quectel software's initialization below: ====== */
	
#ifdef QUEC_STARTUP_OPTIMIZATION
	if(gPowerupSaveTimeFlag != 0x5a5a5a5a){
		err = at_urc_init();
		if (err != kNoErr)
		{
			CPUartLogPrint("urc failed!", FALSE);
		}
	}
#else
	err = at_urc_init();
	if (err != kNoErr)
	{
		CPUartLogPrint("urc failed!", FALSE);
	}
#endif

#if defined(QUEC_SEND_AT_SUPPORT)
		/* Fitz.xu 20200403: wait CI ready, then we can do quec_at_fetch_config */
		//evin 20210511  fix open Power on speed optimized,result Ci canot ready in time,gServiceRegStatus can represent ci status, chang booting_done with gServiceRegStatus
		while(!gServiceRegStatus)	
#else
		while(!ATCmdSvrRdy)
#endif
		{
			OSATaskSleep(2);
		}
#ifdef QUEC_POWER_MANAGER_ENABLE  //Chaim2018.12.17 need get dtr level,init after siolib
    quec_pm_task_init();//��ʼ�������߳�
#endif

#ifdef QUEC_STARTUP_OPTIMIZATION
	if(gPowerupSaveTimeFlag != 0x5a5a5a5a){
		err = quec_rdy_report();	//jensne.fang 20190107: move [quec_rdy_report] here to reduce the time of power on
		if (err != kNoErr)
		{
			CPUartLogPrint("rdy report failed!", FALSE);
		}
	}
#else
#if QUEC_RDY_ENABLE
	err = quec_rdy_report();	//jensne.fang 20190107: move [quec_rdy_report] here to reduce the time of power on
	if (err != kNoErr)
	{
		CPUartLogPrint("rdy report failed!", FALSE);
	}
#endif
#endif

#if QUEC_DEBUG_LOG_SWITCH
	{
		extern int cp_log_flag;
		cp_log_flag=1;
	}	
#endif

#ifdef QUEC_ASR_SIM_ENBALE
    /*Tery 2019-02-22 add simdet urc*/
	/*����or�����Ƿ�Ҫ�ϱ�SIM���ļ��״̬*/
	quec_simdet_report();
#endif

	//Fitz.xu 20210415: Move here to fix FAE-12141
	//Fitz.xu 20210421: Add for FAE-10441
#if defined(__QUEC_OEM_VER_LT__)
	quec_LT_check_at_timeout_start();
#endif

	//Fitz.xu 20210819: Add for allied net_mode led
#if defined(__QUEC_OEM_VER_ALLIED__)
	quec_allied_net_mode_task_init();
#endif

	err = quec_cust_task_init();
    if (err != kNoErr)
	{
		CPUartLogPrint("quec_cust_task_init failed!", FALSE);
	}

    quec_at_fetch_config();
    quec_transmission_rate_config();
	
	CPUartLogPrint("quec_transmission_rate_config!!!",FALSE);
//	lwip_set_log_lv(QUEC_LWIP_LOG_LEVEL_ERROR_API);
	
#ifdef QUEC_AUDIO_SUPPORT
	CPUartLogPrint("audio_init!!!",FALSE);
	#ifdef QUEC_AT_CMD_AUDIO_SUPPORT
	quec_audio_init();
	#endif
    #ifdef QUEC_AT_CMD_AUDIO_SUPPORT
    #ifdef QUECTEL_TTS_FEATURE
    #ifdef QUEC_TTS_TASK_XIP_SUPPORT
    quec_tts_task_init();
    #else
	tts_task_startup();
    #endif
    #endif
	quec_atcmd_audio_task_init();
	quec_audio_init_done = 1;    //20200624 kevin.wang   avoid playing tts before initializing done , which will cause dump.
    #endif
#endif

//	quec_fota_update_task_init(1);

#if QUEC_CUSD_OPTIMIZE
    quec_nv_cusdcvt_flag_init();
#endif
#ifdef QUEC_POWER_BACKOFF_SUPPORT
	quec_check_nv_enable_rf3g_pwrbackoff();
#endif	

#ifdef QUEC_GRIP_PARAM_SAVE_SUPPORT
	quec_grip_param_cfg_s quec_grip_cfg={0};
	extern CiReturnCode DEV_SetPowerBackOffReq(UINT32 atHandle, UINT8 option,UINT8 value, UINT8 nwMode, UINT8 band);
	ret = quectel_nv_fat_read(QUEC_AT_GPIP_PARAM_VALUE, &quec_grip_cfg, sizeof(quec_grip_cfg));
	if (QUEC_FAT_SUCCESS == ret)
	{
		err = DEV_SetPowerBackOffReq(IND_REQ_HANDLE, quec_grip_cfg.option,quec_grip_cfg.value,quec_grip_cfg.networkMode,quec_grip_cfg.band);
		app_log("[wayne]DEV_SetPowerBackOffReq err:%d;cfg:%d,%d,%d,%d\n",err,quec_grip_cfg.option,quec_grip_cfg.value,quec_grip_cfg.networkMode,quec_grip_cfg.band);
		CPUartLogPrint("[wayne]DEV_SetPowerBackOffReq success\n",FALSE);
	}			
#endif

	if (1 == InProduction_Mode())
	{
		at_urc_send(NUM_OF_TEL_ATP, "PRODUCTION MODE\r\n", strlen("PRODUCTION MODE\r\n"), 0, URC_OUT_METHOD_BROADCAST, NULL);
		quec_debug_log_port = LOG_PORT_NONE;
		urc_context.config.enable = QUEC_DISABLE;
	}

#if !(defined(ASR_PLATFORM_CRANEL)||defined(ASR_PLATFORM_CRANEM)||defined(ASR_PLATFORM_CRANELR)||defined(ASR_PLATFORM_CRANELS) )
    pm813_shutdown_charger_under_production_mode(); //added to shutdown charger default
#endif

/* Fitz.xu 20201116: to set clip and colp flag status */
#if QUEC_CALL_OPTIMIZE_CLIP_COLP
    quec_clip_colp_init();
#endif

/* destin 2021.0406 init qsvn */
#if QUEC_QSVN_INIT_SET_FEATURE 
	quec_qsvn_init();
#endif

    //2021.9.4 Chaim for explain RO section,for mini_1 diff no space to save
#ifdef QUEC_DO_VERSION_EXPLAN_RO_SECTION
    extern unsigned char RO_section_array[300*1024];
    unsigned char ro_sec[10]={'D','O','\0','\0','\0','\0'};
    ro_sec[2]= RO_section_array[0];
    CPUartLogPrint(&ro_sec[0], FALSE);
    
#endif
	
#ifdef QUEC_CUST_XIPING_SUPPORT
	g_quec_cust_xiping_atcmd_valid_flag = QUECTEL_CUST_XPCFUN_ATCMD_ENABLE;
	err = quec_set_cfun0();
	if (err != kNoErr){
		CPUartLogPrint("set cfun0 failed!",FALSE);		
	}
	g_quec_cust_xiping_atcmd_valid_flag = QUECTEL_CUST_XPCFUN_ATCMD_DISABLE;
#endif

#if QUEC_PPP_NETIF_IP_DN_WLIST_FEATURE
	quec_dns_sniffer_task_init();
#endif
#if (defined(QUEC_NTP_SUPPORT) && defined(__QUEC_OEM_VER_OA__))
	quec_task_t ntp_task = NULL;
	err = quec_rtos_task_create(&ntp_task, 1024, QUEC_APP_TASK_PRIORITY, "quec_syn_ntp_time", quec_syn_ntp_time, NULL);
#endif
#ifdef QUEC_ASR_ATCMD_PARA_INIT_ENBALE  /*Tery 20181207 add the at cmd pata init*/
	if(TRUE == gServiceRegStatus)
	{
		quec_atcmd_para_init();
	}
#endif	
#if defined(__QUEC_OEM_VER_DM__)

		CPUartLogPrint(" quec_dmhttp_client_init", FALSE);
		quec_dmhttp_client_init();
#endif

#if QUEC_CEER_ESM_REJECT_CAUSE_SUPPORT
	quec_set_clear_err_cause();
#endif

	/* ======= End of quectel software's initialization ====== */
	quec_init_done = TRUE;
exit:
	return err;
}

QuecOSStatus quec_app_rdy_sem_create(void)
{
	QuecOSStatus err = kNotInitializedErr;
	
	err = quec_rtos_semaphore_create(&quec_app_rdy_sem, 0);
	if (err != kNoErr)
	{
		CPUartLogPrint("rdy sem create failed!", FALSE);
	}
	return err;
}

static QuecOSStatus quec_app_rdy_sem_send(void)
{
	QuecOSStatus err = kNotInitializedErr;

	if (NULL != quec_app_rdy_sem)
	{
		err = quec_rtos_semaphore_release(quec_app_rdy_sem);
	}
	if (err != kNoErr)
	{
		CPUartLogPrint("rdy sem send failed!", FALSE);
	}
		
	return err;
}

static QuecOSStatus quec_rdy_report(void)
{
	QuecOSStatus err = kNoErr;
#ifndef QUECTEL_OPEN_CPU
#if defined(__QUEC_OEM_VER_NL__) || defined(__QUEC_OEM_VER_XGD__)
    err = at_urc_send(NUM_OF_TEL_ATP, "AT command ready\r\n", strlen("AT command ready\r\n"), 1, URC_OUT_METHOD_BROADCAST, NULL);
#else
	err = at_urc_send(NUM_OF_TEL_ATP, "RDY\r\n", strlen("RDY\r\n"), 1, URC_OUT_METHOD_BROADCAST, NULL);	
#endif
    at_urc_flush();// at_urc_send  check quec_cust_task_init_done stat, need flush to out rdy
    require_noerr(err, exit);

	err = quec_app_rdy_sem_send();
	require_noerr(err, exit);
#endif
exit:
	quec_cust_task_init_done = 1;
	return err;
}

QuecOSStatus quecWaitForAppRdy(void)
{
	QuecOSStatus err = kGeneralErr;

	if (NULL != quec_app_rdy_sem)
	{
		err = quec_rtos_semaphore_wait(quec_app_rdy_sem, QUEC_WAIT_FOREVER);
	}
	if(err == kNoErr)
	{
		err = quec_rtos_semaphore_delete(quec_app_rdy_sem);
	}
	if (err != kNoErr)
	{
		CPUartLogPrint("rdy sem wait failed!", FALSE);
	}
	
	return err;
}

#ifdef QUECTEL_OPEN_CPU 
#include "download.h"
extern BOOL IsFullfota_app(void);
extern void ql_power_reset(void);
#endif
void quecApplicationStart(void * argv)
{
	QuecOSStatus err = kNoErr;

	app_log(" Application Start...");
	CPUartLogPrint(" Application Start...", FALSE);


	app_log(" ATCmdSvrRdy");
	CPUartLogPrint(" ATCmdSvrRdy", FALSE);

	err = quec_init();
	require_noerr_string(err, exit, "quec_init error");
	
#ifdef QUECTEL_OPEN_CPU
	if(IsFullfota_app() == 1){
		quec_fullfota_app_work();
		ql_power_reset();
	}
 
	quec_task_t customer_application_task = NULL;
	extern void ql_main(void * argv);//�����̣߳�����QUECAPP ��ͻ��������߳�
	err = quec_rtos_task_create(&customer_application_task, 4096, QUEC_APP_TASK_PRIORITY, (char *)quec_task_name[QUEC_OPEN_MAIN], ql_main, NULL);
	require_noerr_string(err, exit, "Customer Application Start FAIL !!!");
#endif

exit:
	if(err != kNoErr)
	{
		//QUEC_ASSERT(0);
		CPUartLogPrint("quec_init failed!", FALSE);
	}
	
	app_log("quecApplicationStart task will be deleted for resource saving");
	quec_rtos_task_delete_ex(NULL);
	return ;
}

#endif /*MIN_SYS*/

