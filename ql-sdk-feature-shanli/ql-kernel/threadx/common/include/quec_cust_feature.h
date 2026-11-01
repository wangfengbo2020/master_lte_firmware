/**  @file
  quec_cust_feature.h

  @brief
  This file is used to define feature for different Quectel Project.

*/

/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
09/28/2018        Jensen     Init version
04/09/2020		  domingo	 add feature to fix when pdp is actived,qicsgp qury error
04/09/2020		  domingo	 add feature to support PAP_OR_CHAP in qicsgp command
04/15/2020 		  Harold     mod qicsgp user name and password support up to 128 bytes each
04/22/2020		  Luffy		 add quecthing function 
04/30/2020        Isaac      Fix the definition of PDP context, AT + CGDCONT? 
								 Query return parameter format is incorrect  
05/25/2020		  Harold	 mod the total length of AT commond is 32 bytes,get an extra \n output
06/04/2020        domingo    deactive all active pdp when recv deattch indcation
=================================================================*/


#ifndef QUEC_CUST_FEATURE_H
#define QUEC_CUST_FEATURE_H
#include "QuecPrjName.h"
#include "quec_cust_patch.h"

#define QUECTEL_PROJECT_CUST 1
#if !defined(MIN_SYS)
//1606 4+4 支持IMS,不需要XLAT功能
#ifndef QUEC_4MFLASH_SUPPORT_IMS
#define QUEC_XLAT_SUPPORT   1
#endif
#endif

#if defined QUECTEL_PROJECT_CUST

///Chaim 202.11.21 minisystem modify
#define QUEC_MINI_SYSTEM_SUPPORT 

/************************************************ customer specific function*************************************************/
#ifdef QUEC_CUST_FOR_IPC_SUPPORT
////////////IPC 行业定制功能
// Ford 20200312 add for ipc function
#define QUECTEL_IPC_ENTERSLEEP_SUPPORT
//harry 2021/10/18 add heartbeat
#define QUEC_HEART_BEAT_LPC_FEATURE

//用于IPC行业获取休眠唤醒的原因
#define QUEC_SLEEP_INFO_SUPPORT

#endif

/* Support TAU type. Set "QUEC_TAU_TYPE_PERIODIC_UPDATING" as deault. See quec_tau_type_cfg. */
#define QUEC_ASR_ATCMD_TAU_TYPE_SUPPORT

#if defined (__QUEC_OEM_VER_WB__) || defined (__QUEC_OEM_VER_XXCD__)
//add wanbangdehe star charge custom function 万帮德和*星星充电客户定制功能         harold.wang 202001105 
#define QUEC_STAR_CHARGE_CUSTOM_WANBANGDH_FEATURE  
//destin 2020.09.24 add for "AT+QCFG="csqgpiodisp",(0-1) only for WB now
#define QUEC_CSQ_GPIO_DISPLAY_ENABLE (1)
#endif

#if defined (__QUEC_OEM_VER_CT__)
//carson.liu add Ctwing function
#define QUECTEL_CTWing_SUPPORT
#endif

#if defined (__QUEC_OEM_VER_XF__)
//add xianfeng先锋 custom function 先锋客户定制功能          ,解决客户串口波特率过低,服务器已经关闭,缓存buf数据还没有输出完harold.wang 20210517 
#define QUEC_XF_PIONEER_FTPCACHE_CUSTOM_FEATURE  
#endif

#if defined (__QUEC_OEM_VER_DO__)
#define QUEC_DO_VERSION_EXPLAN_RO_SECTION
#endif

/************************************************ platform/bsp/rtos function*************************************************/

#if defined(__QUECTEL_PROJECT_EC800NCN_LA__) || (defined __QUEC_OEM_VER_GENUS__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_LA__) || defined (__QUECTEL_PROJECT_EC800MCN_LE__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_LC__) || defined (__QUECTEL_PROJECT_EC800MCN_LF__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_MC__) || defined (__QUEC_OEM_VER_ALLIED__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_GA__) || defined (__QUECTEL_PROJECT_EC800MCN_GC__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_GM__) || defined (__QUECTEL_PROJECT_EG810MCN_GA__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_CC__) || defined (__QUECTEL_PROJECT_EC800MCN_NC__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_GD__) || defined (__QUECTEL_PROJECT_EG810MCN_LA__) \
	|| defined (__QUECTEL_PROJECT_EC600NCN_AC__) || defined (__QUECTEL_PROJECT_EC800KCN_CC__) \
	|| defined (__QUECTEL_PROJECT_EG800KCN_GC__) || defined (__QUECTEL_PROJECT_EG800KEU_CC__) \
	|| defined (__QUECTEL_PROJECT_EC800KCN_CZ__) || defined (__QUECTEL_PROJECT_EC800MCN_GB__) \
	|| defined (__QUECTEL_PROJECT_EG810MEU_LA__) || defined (__QUECTEL_PROJECT_EC800KCN_LC__)\
	|| defined (__QUECTEL_PROJECT_EG810MCN_GB__) || defined (__QUECTEL_PROJECT_EG800PCN_00LA__)\
	|| defined (__QUECTEL_PROJECT_EG810MCN_LC__) || defined (__QUECTEL_PROJECT_EC800KCN_MC__) \
	|| defined (__QUECTEL_PROJECT_EG810MEU_LC__) || defined (__QUECTEL_PROJECT_EG810MLA_LC__)\
	|| defined (__QUECTEL_PROJECT_EG800KLA_CC__) || defined (__QUECTEL_PROJECT_EC800KCN_MD__)\
	|| defined (__QUECTEL_PROJECT_EG800KLA_LC__) || defined (__QUECTEL_PROJECT_EG800KEU_LC__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_CK__) || defined (__QUECTEL_PROJECT_EC800KCN_LK__)
	
//evin 20210809 EC800NCNLA not support APREADY&air plane ctrl
//Fias.fan 20220421 EC800MCNLA&EC800MCNLC not support APREADY&air plane  not support APREADY&air plane 
#else
#ifndef QUECTEL_OPEN_CPU
#ifndef LTEONLY_THIN_SINGLE_SIM 
#define QUEC_SLEEP_AP_READY
#define QUEC_AIR_PLANE_CTRL_ENABLE
#endif
#endif
#endif

#ifndef QUECTEL_OPEN_CPU
//1606 4+4 支持IMS,不需要网络灯相关的功能
#ifndef QUEC_4MFLASH_SUPPORT_IMS

#if !(defined (__QUECTEL_PROJECT_EC800KCN_CC__) || defined (__QUECTEL_PROJECT_EG800KCN_GC__)\
	||defined (__QUECTEL_PROJECT_EG800KEU_CC__) || defined (__QUECTEL_PROJECT_EC800KCN_CZ__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_LC__)) || defined (__QUECTEL_PROJECT_EG800PCN_00LA__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_MC__) || defined (__QUECTEL_PROJECT_EG800KLA_CC__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_MD__)|| defined (__QUECTEL_PROJECT_EG800KLA_LC__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_CK__) || defined (__QUECTEL_PROJECT_EC800KCN_LK__)\
	|| defined (__QUECTEL_PROJECT_EG800KEU_LC__)
//destin ASR 1603 sleep ind software ctrl,1603 hardware not support sleep pads
#define QUEC_QSLEEP_IND_CTL (1)  //用于GPIO指示休眠与唤醒状态的
#endif

#define QUEC_LED_NET_STATUS_CFG_SUPPORT //用于指示网络运行状态
#define QUEC_LED_NET_MODE_SUPPORT  //用于指示网络注册状态
//fitz.xu 20191114: Add led_task support
#define QUEC_LED_TASK_SUPPORT

#if defined(__QUECTEL_PROJECT_EG915NEU_AG__) || defined(__QUECTEL_PROJECT_EC600KCN_CC__) || defined (__QUECTEL_PROJECT_EC600KCN_LC__)|| defined(__QUECTEL_PROJECT_EC600KCN_MC__)|| defined (__QUECTEL_PROJECT_EC600KCN_CK__) || defined (__QUECTEL_PROJECT_EC600KCN_LK__) //Realize the function of simulating pwm status light with gpio
#define QUEC_LED_GPIO_TO_PWM  //注意此处添加项目后还需要再quec_led_task.c中添加net_status引脚和对应gpio func
#endif

#ifndef LTEONLY_THIN_SINGLE_SIM 
//Fitz.xu 20210607: NET_MDOE compatible with L610
#define QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610  (1)

#endif

#endif
#endif

//jensen.fang 20181105 add the macro to enable/disbale PWM module
#define QUEC_PWM_ENBALE
//Fitz.xu 20210311: Optimize PWM output
#define QUEC_OPTIMIZE_PWM_OUTPUT  (1)

/*/evin  2020.11.11 add at+qcfg="urc/ri/pin",("uart_ri","uart_dcd") 
//将dcd和wakeup的引脚输出RI引脚的功能 FAE-4345é????—AE-4542*/
#define QUEC_URC_RI_DCD_SUPPORT

//Fitz.xu 20200309: add urc ri type support
#define QUEC_URC_RI_TYPE_SUPPORT
//eckard 20220726 add at+qcfg="precheck"
#define QUEC_PRECHECK_SUPPORT

//fitz.xu 20190605: Add ADC enable or disable macro.
#define QUEC_ADC_SUPPORT
//支持获取Vbatt电池电压
#define QUEC_VBATT_ADC_SUPPORT

//chaim 2018.11.16 quec gpio enable macro
#define QUEC_GPIO_ENABLE
#ifndef LTEONLY_THIN_SINGLE_SIM 
//kevin.wang 20200603 add AT cmd to control PA
#define QUEC_AT_GPIO_SUPPORT
//harry 20211008 添加 at+gpioctrl 配置gpio在指定时间段输出高低电平
#define QUEC_GPIO_CTRL_SUPPORT
#endif

#ifdef BT_SUPPORT
#define QUEC_BT_SUPPORT
#endif

#ifdef QUECTEL_OPEN_CPU
//add 20230530 解决gpio干扰导致频繁触发中断导致dump问题 默认关闭此宏
#define QUEC_GPIO_DISTURB (0)
#endif

/********************************************* QSPI INTERNAL_NORFLASH********************************************/
#ifndef LTEONLY_THIN_SINGLE_SIM 
//Egan 2020.03.04 nor flash Power down compensation
//记录Flash擦除是否完成,此功能需要使用ease_rd分区,2M的项目不支持此功能
#define QUEC_NORFLASH_ERASE_OPTIMIZE
#endif

#define QUEC_LIMIT_FLASH_ERASE 1

//add by amos 2020.10.16 for diable or enable flash erase count
#define QUEC_AT_FLASH_ERASE_COUNT_CMD

/*/brent.qiu 20200312: Add test flash/fs,
//用于内部ST测试内置Flash的性能测试*/
//默认8兆版本打开flash性能测试功能
#if defined(__QUEC_OEM_VER_FST__) || defined(CRANEL_8MRAM)
  #define QUEC_ADD_FALSH_TEST_SUPPORT
#endif

//Amos 2021.01.04 add DS flash config,20220915、1606平台不支持复旦微的Flash 支持
//#define QUEC_NORFLASH_COMPATIBLE

#ifdef QUECTEL_OPEN_CPU
#define QUEC_FS_WEAR_BALANCE_VERIFY
#endif 

//jensen.fang 20181114: to enable/disable quectel Nand/Nor flash config.
#define QUEC_FLASH_CONFIG
#if defined QUEC_FLASH_CONFIG
//	!!!if enable/disable the macro QUEC_FLASH_CONFIG_NAND/QUEC_FLASH_CONFIG_NOR!!!
//	!!!please note that the correspondent blf file is different!!!
#define QUEC_FLASH_CONFIG_NAND
#define QUEC_FLASH_CONFIG_NOR
#endif

#ifndef LTEONLY_THIN_SINGLE_SIM 
//jensen.fang 20181218: add configuration for different production or customer requirement
//利用Flash,quec_cfg分区保存一些重要的参数,主要Flash layput中必须要有quec_cfg，才能使用此功能
#define QUEC_PRODUCTION_CFG_SUPPORT (1)

//Amos.yao 2021.4.21 add for startup time
//#define QUEC_STARTUP_OPTIMIZATION //开机加速,缩短开机时间
#endif
#ifdef VOLTE_ENABLE
//Volte 版本需要保存XML文件
//jensen.fang 20181218: add configuration for different production or customer requirement
//利用Flash,quec_cfg分区保存一些重要的参数,主要Flash layput中必须要有quec_cfg，才能使用此功能
#define QUEC_PRODUCTION_CFG_SUPPORT (1)
#endif


/********************************************* FS (UFS)********************************************/
//文件的接口
#define QUEC_FILE_API

/*Sharon.li@20230823 
1606L 2M Flash 和 1602 2M FLASH 都不支持UFS相关的AT
但是8M 和 4M Flash的项目都支持
*/
#ifndef LTEONLY_THIN_SINGLE_SIM_2MFLASH 
//west.wang 20181203 add the macro to control the at command about file
//文件UFS相关的AT
#define QUEC_AT_FILE_CMD
#endif

#ifndef QUEC_MINSYS_THIN
#ifndef NO_MBEDTLS
/*<add by [asa.wang] 2017/11/06 for support security fs to Certificate security storage>*/
#define QUECTEL_SFS_FILE    
#endif
#endif

#ifdef QUEC_AT_FILE_CMD
//add by carson.liu for UFS file system support MD5 checksum.
#define QUEC_AT_MD5_CKECKSUM_SUPPORT

//add by wayne 2020.09.27 for support AT+QFTCMD
#define QUEC_AT_SD_CHECK_SUPPORT

//add by wayne 2020.04.10 for support file open by fatIO_CREATE|fatIO_RDWR.
#define QUEC_FILE_OPEN_MODE_SUPPORT

//Fitz.xu 20190819 Add for ASR file read
#define QUEC_ASR_FILE_READ_SUPPORT
#endif
/********************************************* GPS********************************************/

#if defined (__QUECTEL_PROJECT_EC800MCN_GA__) || defined (__QUECTEL_PROJECT_EC800MCN_GC__) \
	|| defined (__QUECTEL_PROJECT_EC600MCN_GC__) || defined (__QUECTEL_PROJECT_EC800MCN_GM__) \
	|| defined (__QUECTEL_PROJECT_EG810MCN_GA__) || defined(__QUECTEL_PROJECT_EC200MCN_GB__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_GD__) || defined (__QUECTEL_PROJECT_EC800MCN_GB__)\
	|| defined (__QUECTEL_PROJECT_EG810MCN_GB__) || defined (__QUECTEL_PROJECT_EG800PCN_00LA__)\
	|| defined (__QUECTEL_PROJECT_EG800KCN_GC__)
#define QL_GNSS /*open gps 功能宏 方便open客户裁剪gps代码*/
#define QUEC_GNSS_NTP
#endif


//chaim 2018.10.24 package msg macro
#define QUEC_MSG_PACKAGE_ENABLE

//chaim 2018.11.16 not delete this macro, otherwise will cause compile error
#define QUEC_REDEFINE_DBG_ERR_MSG  1

//chaim 2018.10.30 quec sio enable flag
#define QUEC_SIO_MODULE_ENABLE

// Chavis.Chen@20181123 QUEC_RDY_ENABLE
#define QUEC_RDY_ENABLE		1

/**************************************** Factory AT******************************************/

//fitz.xu 20190801: Add MAC address set support
#define QUEC_WSETMAC_SUPPORT

//amos.yao 2021.04.06: add IMEI2
#define QUEC_ADD_IMEI2_CONFIG

//jensen.fang 20181203: added the macro to enable/disable modification of CPPCheck result.
//QUEC_CODECHECK_MODIFICATION_ASR is defined at inc_project.mak first!
#ifndef QUEC_CODECHECK_MODIFICATION_ASR
#define QUEC_CODECHECK_MODIFICATION_ASR
#endif

//#define QUEC_POWER_BACKOFF_SUPPORT //add by wayne 2020/07/31 for support 2G/4G power backoff function

/************************************************** FOTA function***********************************************************/

//jensen.fang 20181218: to enable quec fota model
//#define QUEC_FOTA_SUPPORT

//#define QUECTEL_QUECFOTA_SUPPORT //harold.wang 20200923 add quecFota 2.0 function 
#define QUECTEL_FOTA_UPDATER_PARTITION

//fitz.xu 20190704: Fota auto test support, default is disable
//#define QUEC_FOTA_AUTO_TEST_ENABLE

//fitz.xu 20190515: to enable quec ftp fota
//#define QUEC_FTP_FOTA_SUPPORT

//larson.li 20190115 add the fota data interface feed function
//#define QUEC_FOTA_FEED_SUPPORT


//fitz.xu 20190701: Enable http fota retry.
#define QUEC_FOTA_HTTP_RETRY_SUPPORT

//fitz.xu 20190725: Enable URC report when FOTA download.
#define QUEC_FOTA_DOWNLOAD_URC_SUPPORT

//Ramos.zhang-20190921 add the file fota 
#define QUEC_PROTOCOL_DOWNLOAD_FILE_FOTA

//jensen.fang 20190226: add recovery of image(cp/msa/rf) support
//#define QUEC_RECOVERY_SUPPORT

//fitz.xu 20190517: Add fat test support, DISABLE by default.
//#define QUEC_FAT_TEST_SUPPORT

//Larson.li 20181228 add the key power off time optimize
//#define QUEC_KEY_POWER_OFF_OPTIMIZE

//Fitz.xu 20201118: Optimize memory HEAP size,
//此宏裁剪内存
#define QUEC_MEMORY_OPTIMIZE  (1)

#define QUEC_1601_PSM_EXTEND_2K 

//Fitz.xu 20211118: To fix Coverity code scan error.
#define QUEC_FIX_COVERITY_SCAN_SUPPORT_421929  (1)

//Fitz.xu 20211125: To fix Coverity code scan error.
#define QUEC_FIX_COVERITY_SCAN_SUPPORT_421743  (1)

//evin.zhu 20220510 to fix timer 0x17 no assert
#define QUEC_TIMER_REACTIVE_NOASSERT 1

/********************************************** AT COMMAND function******************************************************/
//jensen fang 20181011: to enable the quectel AT command definition.
#define QUECTEL_AT_COMMAND

//west wang 20181016  add commom at cmds
#define __QUECTEL_COMMOM_AT_SUPPORT

//west 2018.10.25 at&W at&v support
#define QUEC_AT_AMPW_V_SUPPORT
//west 2018.10.25 urc support
#define QUEC_AT_URC_SUPPORT
//west 2018.10.25 cmee support
#define QUEC_AT_CMEE_SUPPORT
//west 2018.11.01 add AT+CVERSION support
#define QUEC_AT_CVERSION_CSUB_SUPPORT
//west 2018.11.02 add AT&F support
#define QUEC_AT_AMPF_SUPPORT
//west 2018.11.02 add ATZ support
#define QUEC_AT_Z_SUPPORT
//west 20181108 add urc flush when exec atcmd end
#define QUEC_AT_URC_FLUSH_SUPPORT
//west 20181112 at case not sensitive support
#define QUEC_AT_CASE_SENSITIVE_SUPPORT
//west 20181112 at+gsn/at+cgsn cmds support
#define QUEC_AT_CGSN_SUPPORT
//west 20181115 atx cmd modified
#define QUEC_AT_X_SUPPORT
//west 20181116 at+cfun cmd support
#define QUEC_AT_CFUN_SUPPORT
//west 20181117 ate cmd modified
#define QUEC_AT_E_MODIFIED
//west 20181119 add at+iccid cmd support
#define QUEC_AT_ICCID_SUPPORT
//west 20181119 add serial cmds support(such as : ati+csub)
//#define QUEC_AT_MULTI_CMD_SUPPORT

//west 20181123 modified multi_cmd support
//#define QUEC_AT_MULTI_CMD_MODIFIED

#define QUECTEL_AT_QCFG_SUPPORT  //connor wu  20181019
//connor.wu 2018.11.23 add the macro control URC indication
#define QUECTEL_AT_QINDCFG_SUPPORT


#ifndef LTEONLY_THIN_SINGLE_SIM  //单卡的2M Flash项目不支持
#define QUEC_AT_CIND_SUPPORT  //Chaim 20200312,打电话相关的指令

#define QUECTEL_AT_QCFG_ACQDB_OPT_SUPPORT  //connor wu  20190227
//sawyer 20221018 add AT+QLWPINGCFG to control wan access
#define QUEC_LWIP_WAN_PING_FLAG_CFG_SUPPORT

//Isaac 20201228 support at+qcfg="roamserviceex"
#define QUECTEL_AT_QCFG_ROAMSERVICEEX

#endif

//evin 20221210 support ue statue check
//显示版本禁止r和i注网的版本状态
#define QUEC_UESTAT_SUPPORT 1

//jensen.fang 20181101 add the macro to control the at command about production
#define QUEC_AT_PRODUCTION

//jensen.fang 20190726: add for filter the AT cmd received characters and echo
#define QUEC_AT_CMD_FILTER

//jensen.fang 20190731: add internal at channel to send AT cmd
#define QUECTEL_AT_COMMAND_INTERNAL
//jensen.fang 20190903: at timeout debug code
#define AT_TIMEOUT_DBG 0

//Fitz.xu 20200403: used for at flag
#define QUEC_SEND_AT_SUPPORT

//Fitz.xu 20210130: To avoid conflict between hard and soft switch for QT+QDSIM
#ifdef __QUECTEL_PROJECT_EG912YEM_AA__
//kevin.wang 20200715 add using pin 119 to control sim 
//通过Pin脚进行切卡
//#define QUEC_SIM_PIN_CTRL_FUNC 1
#endif


//2021.04.06 destin set ASR SVN with QUEC svn though at ind
#define QUEC_QSVN_INIT_SET_FEATURE (1) 


#define QUECT_AT_URC_ADD_SIO_WM_CB_FEATURE //add at urc sio wm high/low callback  harold.wang@2020.11.2

// destin 2021.3.19 remove CEREG response add '/r/n' in head ,this will make strncmp() work worng in SendATCMDWaitResp() junction 
#define QUEC_CEREG_REMOVE_INVALID_FEATURE (1)
// destin 2021.3.19 internal at respose not cheak resp len to memcpy
#define QUEC_INTERNAL_AT_FEATURE_FIX (1)
// destin 20210810 fix AT+COPS=? interrupt by call err_code isn't correct.
#define QUEC_COPS_CANCEL_ERR_CODE_FIX (1)

#define QUEC_SLEEP_DTR_HIGH_FREQ_FEATURE (1)


//2023/07/25 add testflag cmd
#define QUEC_CUST_TESTFLAG_SUPPORT

//Davison.du 20201026 Add OOS phase period
#define QUEC_OPER_OOS_PHASE_PERIOD

/********************************************** Debug Info  function******************************************************/
//Egan.li 20200421: used for debug onff flag
#define QUEC_DEBUG_LOG_SWITCH 1

#define QUEC_AT_QDEBUGCFG_SUPPORT

#ifndef LTEONLY_THIN_SINGLE_SIM 
//chaim 2018.10.24 atcmd log enable
#define QUEC_ATCMD_LOG

#define QUEC_NETCARD_LOG_SUPPORT
#endif
/***************************************************** UART function*********************************************************/

//chaim 2018.10.30 quec uart enable macro
#define QUEC_UART_ENABLE

//chaim 2018.12.13 quec uart enable macro
#define QUEC_UART1_ENABLE

//UART1的硬件流控功能
#define QUEC_UART1_HARDWARE_FLOWERCTRL

#define QUEC_USB_HARDWARE_FLOWERCTRL

//chaim 2018.03.20 控制流控功能，UART流控和USB 流控
#define QUEC_HALF_HARDWARE_FLOWERCTRL    1


#ifndef QUECTEL_OPEN_CPU
#ifndef LTEONLY_THIN_SINGLE_SIM 
//chaim 2018.12.12 quec minor uart enable macro,this macor support at/log switch in minor_uart
//Sharon.li 此宏用于DEbug UART是否支持发送AT和上报URC功能，2M的FLASH 不支持双串口功能
#define QUEC_UART2_ENABLE

#endif
#endif


//Egan.li 2020.08.24 enable 1M 
#define QUECTEL_UART_HIGH_SPEED_FEATURE (1)


#ifdef  QUEC_UART_DMA_TX_ENABLE
#define QUEC_DEBUG_UART_DMA_TX_ENABLE
#define QUEC_MAIN_UART_DMA_TX_ENABLE
#ifndef LTEONLY_THIN_SINGLE_SIM  //单卡的2M Flash项目不支持
#ifndef QUEC_BT_UART_DMA_TX_ENABLE
#define QUEC_BT_UART_DMA_TX_ENABLE
#endif
#define QUEC_U4_UART_DMA_TX_ENABLE
#endif
#endif

#ifdef  QUEC_UART_DMA_RX_ENABLE 
#define QUEC_DEBUG_UART_DMA_RX_ENABLE
#define QUEC_MAIN_UART_DMA_RX_ENABLE
#ifndef LTEONLY_THIN_SINGLE_SIM  //单卡的2M Flash项目不支持
#ifndef QUEC_BT_UART_DMA_RX_ENABLE
#define QUEC_BT_UART_DMA_RX_ENABLE
#endif
#define QUEC_U4_UART_DMA_RX_ENABLE
#endif
#endif

#ifndef __CMUX_DISABLE
//#define QUEC_CMUX_ENABLE
//evin 2020.12.15
//#define QUECTEL_CMUX_SUPPORT
#endif

//Quectel ADD ：FAE-126264 单独开启R06下所有8M标准项目的CMUX宏
#ifdef CMUX_ENABLE
#ifndef  QUECTEL_OPEN_CPU
#define QUEC_CMUX_ENABLE
#define QUECTEL_CMUX_SUPPORT
#endif
#endif

/*chaim 2018.12.9  minor uart support at and debug,just for development and testing
this macro only eccect at QUEC_MINOR_UART_AT_ENABLE is 1,and if this macro is 1, open in system init
so not allow to send atcmd in before RDY send,

*/

#ifdef QUEC_UART1_ENABLE

//Chaim.qian 2018.11.12 add the macro to add at cmd ipr baudrate num
#define QUEC_ASR_IPR_BAU_ADD

//jensen.fang 20181105 add the macro to cancel the baudrate auto adption of ASR
#define QUEC_CANCEL_ASR_BAUDRATE_AUTO

#endif 

#define QUEC_MINOR_UART_LOG_FOR_TEST   0


//Chaim.qian20190701 add pax macro
#ifdef __QUEC_OEM_VER_PAX__
    #define QUEC_TTYUSB3_ENABLE
	#define QUEC_QIACT_ANP_CHECK (1)
#elif defined (QUECTEL_OPEN_CPU) 
	#define QUEC_QIACT_ANP_CHECK (1)
#endif

#if defined (__QUEC_OEM_VER_FC__)
//Egan 20210308 mapping 2,2 to 1,2 is used to solve the problem that short frequency RTS cannot be identified
#define QUEC_HARDFLOWER_CTRL_OEM

//luffy.liu 20200714  add jiedian fota function
#define QUEC_JIEDIAN_PROJECT
#endif

/************************************************** USB function***************************************************/

// Chavis.Chen@20190312
#define QUEC_USB_SEND_MEM_EXHAUSTED_BUG_FIX

//chaim 2018.10.30 quec usb enable macro
#define QUEC_USB_ENABLE

#ifdef QUEC_USB_ENABLE
//jensen.fang 20181107 add the macro to enable/disbale usb device configuration
#define QUEC_USB_DEVICE_ENBALE
//Chaim.qian 2018.11.14 switch net type after system init
#define QUEC_CANCEL_USB_NET_TYPE
//#ifdef EXT_AT_MODEM_SUPPORT
#define QUEC_USBAT_PORT_SUPPORT
//#endif

//Chaim.qian 2021.1.2 auto detect whether windows or linux
#define QUEC_USB_AUTO_SUPPORT

#endif

//destin 20210527:fix usb AT channel data abort
#define QUEC_USB_ATP_DUMP_FIX                     (1)
//desin.zhang 20210518 fix RNDIS init msg response failed
#define QUEC_RNDIS_INIT_FAILED_FIX                (1)
//desin.zhang 20210518 fix RNDIS indicate msg response queue data pending
#define QUEC_RNDIS_INDICATE_QUEUE_MSG_PENDING     (1)

//Brent.qiu 20200430: Add AT+QREMOTEWAKE cmd.
#define QUEC_USB_REMOTEWAKEUP_SUPPORT

#ifndef LTEONLY_THIN_SINGLE_SIM  

#ifdef QUEC_PRODUCTION_CFG_SUPPORT
//destin.zhang 20210802 fix in minisys modified USB pid vid invaild
//小系统代码获取quec_cfg里USB的配置
#define QUEC_MINISYS_USB_PID_VID_FEATURE_FIX  (1)
#endif
#endif

//destin.zhang 20210827 fix UsbtreeViwer Scan String Descriptor dump
#define QUEC_USB_SCAN_STRING_DESCRIPTOR_FIX   (1)
//destin.zhang 2021.10.07 quec customer USB iManufacturer
#define QUEC_MANUFACTURER_FEATURE_SUPPORT     (1)
//destin.zhang 2021.10.07 quec customer USB Version force set to 1.1
#ifndef MIN_SYS
#define QUEC_USB_VERSION_FORCE_V11_SUPPORT    (1)
#endif
#define QUEC_USBINFO_DBG_QUERY_FEATURE        (1)

//isaac 20210120 add at+qcfg="usb/nema",<enable> add NAME interface 
#ifndef QUECTEL_OPEN_CPU
#ifndef LTEONLY_THIN_SINGLE_SIM_2MFLASH  //单卡的2M Flash项目不支持
#if defined (__QUECTEL_PROJECT_EC200NCN_GB__)||defined (__QUECTEL_PROJECT_EC800MCN_GA__) \
	||defined (__QUECTEL_PROJECT_EC200MCN_LA__)||defined (__QUECTEL_PROJECT_EC800MCN_GC__) \
	||defined (__QUECTEL_PROJECT_EC800MCN_GM__)|| defined (__QUECTEL_PROJECT_EC200MCN_GB__) \
	|| defined (__QUECTEL_PROJECT_EG810MCN_GA__)||defined (__QUECTEL_PROJECT_EC800MCN_GD__)\
	|| defined (__QUECTEL_PROJECT_EC200MCN_LE__) || defined (__QUECTEL_PROJECT_EG800KCN_GC__)\
	|| defined (__QUECTEL_PROJECT_EC800MCN_GB__) || defined (__QUECTEL_PROJECT_EG810MCN_GB__) \
	|| defined (__QUECTEL_PROJECT_EG800PCN_00LA__)

#if !(defined(QUEC_TTYUSB3_ENABLE)||defined(QUEC_USB_CDC_SUPPORT)||defined(UAC_SUPPORT))
#define QUEC_AT_QCFG_USB_NEMA
#endif

#endif
#endif
#endif

//ford.zhang@2020.07.21  add for command "AT+QCFG="usbnetmac"
#ifndef MV_USB2_NO_USBNET
#define QUEC_ASR_ATCMD_USB_NET_MAC_SUPPORT
#endif

/************************************************** PPP function***********************************************************/

#define QUEC_MODEM_ROUTERE_NO_STORE_OPTIMIZE  //Chaim 20191116 modem router optimiza

#ifdef QUEC_PPP_ENABLE
//chaim 2018.11.5 AT port add ppp suport
#define QUEC_PPP_OVER_USB_AT_ENABLE

//chaim 2018.11.6 pppTerminateTimeoutTimer will acquire semphore
#define QUEC_PPP_ESCAPE_WAIT_DEACT_SEMA

//chaim 2018.11.6 QUEC PPP +++ process
#define QUEC_PPP_ESCAPE_PROCESS

//chaim 2018.11.1 ppp send at cmd to get ip dns,supplement analysis return result
#define QUEC_PPP_AT_ANALYSIS_SUPPLEMENT_ENABLE

//chaim 2018.10.19 ppp speed test malloc control
#define QUEC_PPP_MAX_MALLOC_CTRL
//#define QUEC_PPP_FRAME_CHECK_FIRST_FRAME  //Chaim 20191116 check first frame flag 
//Chaim 20191119 ppp check first flag
//Chaim.qian 2018.11.26 assign profile to ppp dial
#define QUEC_PPP_ASSIGN_CID_ENABLE

#define QUEC_PPP_FRAME_MALLOC_FREE_OPTIMIZE  //Chaim 20191116 free ppp malloc

//destin 2021.02.05 fix ppp auth none
#define QUEC_PPP_AUTH_NONE_TEMINATE_FIX	(1)
//destin 2021.04.19 fix usb host not receive ctrl ep data make ppp fail
#define QUEC_PPP_USB_CTRL_EP_FREE (1)

#define QUEC_PPP_INTERNAL_CHANNEL_HANDLE_AT_RESP //Chaim 20191118 use internal channel to handle at resp

//evin 20211221 fix ppp crc error,then DTR cancel ppp mode,BUFF free twice dump.
#define QUEC_PPP_CRC_ERROR 1

#endif  //end QUEC_PPP_ENABLE

/************************************************* POWER_MANAGER function***************************************************/
#define QUEC_POWER_MANAGER_ENABLE

#ifdef QUEC_POWER_MANAGER_ENABLE

//Chaim.qian 2018.11.19 low power enable
#define QUEC_SLEEP_ENABLE

#define QUEC_QSCLKEX_ENABLE
#endif

//Fitz.xu 20220412: To optimize soft power down
//在软件关机的时候,等待Flash擦除完成
#define QUEC_OPTIMIZE_SOFT_POWER_DOWN  (1)

#define QUEC_UPDATER_BOOT

/****************************************************** NETWORK function*******************************************************/
#define QUECTEL_NETWORK_SUPPORT  //connor wu  20181025

#define QUEC_NETWORK_GET_ECNO  

#define QUECTEL_AT_RFTEST_SUPPORT //add by wayne 2020.07.01 for support FTM test

#define QUEC_GRIP_PARAM_SAVE_SUPPORT //add by wayne 2020.11.17 for save param of at*grip

//connor.wu, 20190326 support auth username/password save to psm
#define QUECTEL_AUTH_PARAM_SAVE_SUPPORT

//chaim 2018.11.30 net card
#define QUEC_NETWORK_CARD_ENABLE

//chavis.chen @20190114, the switch of reporting network info
#define	QUEC_NETINFO_REPORT_ENABLE	1

//jensen.fang 20181217, using DHCP address defined in set_default_dhcp
#define QUEC_DISABLE_ASR_DHCP_LIMIT

//alwyn network reject urc
#define QUECTEL_NETWORK_REJECT_URC_SUPPORT (1)

#ifndef LTEONLY_THIN_SINGLE_SIM  
//isaac 20210819 add at+qnetdualchcfg
#define QUEC_NETDUALCH_CFG
//20200414-isaac Jamming Detection 
//干扰检测功能
#define QUECTEL_JAMDET_FEATURE
//isaac 20211224 support black cell
#define QUEC_BLACK_CELL_SUPPORT
//sawyer.he 20240304 for autoapn
#define QUEC_AUTOAPN_ADJUST_SUPPORT

#elif defined(__QUEC_OEM_VER_BAS__)
//isaac 20211224 support black cell
#define QUEC_BLACK_CELL_SUPPORT
//sawyer.he 20240304 for autoapn
#define QUEC_AUTOAPN_ADJUST_SUPPORT
//alwyn network reject urc
#define QUECTEL_NETWORK_REJECT_URC_SUPPORT (1)
#else
//sawyer.he 2024/02/02 1602 2M project space is insufficient, using cropping scheme (only including scene one)
#define QUEC_THIN_BLACK_CELL_SUPPORT
#endif

#ifdef ENABLE_WIFI_SCAN
//Brent.qiu 20200628: Add WIFISCAN operation.支持wifiscan
#define QUEC_USB_QWIFISCAN_SUPPORT
#endif

//Alwyn.ye 20240116 Add instructions to get CQI MCS
#define QUEC_QNWCFG_SUPPORT

//connor.wu 2018/12/10 add the macro to contol band support
#if defined (__QUECTEL_PROJECT_EC100YCN_SA__) || defined (__QUECTEL_PROJECT_EC200SCN_AA__) \
	|| defined (__QUECTEL_PROJECT_EG912YEU_AA__) || defined (__QUECTEL_PROJECT_EG912YCN_AA__) \
	|| defined (__QUECTEL_PROJECT_EG912YEM_AA__) || defined (__QUECTEL_PROJECT_EC200SEU_AA__) \
	|| defined (__QUECTEL_PROJECT_EC600SCN_AA__) || defined (__QUECTEL_PROJECT_EC200SCN_GB__) \
	|| defined (__QUECTEL_PROJECT_EC200SCN_AB__) || defined (__QUECTEL_PROJECT_EC600SCN_AC__)\
	|| defined (__QUECTEL_PROJECT_EG912YEU_AC__) || defined (__QUECTEL_PROJECT_EG912YCN_AB__)\
	|| defined (__QUECTEL_PROJECT_EC200NCN_AA__) || defined (__QUECTEL_PROJECT_EG912YEU_AD__) \
	|| defined (__QUECTEL_PROJECT_EC200NCN_AB__) || defined (__QUECTEL_PROJECT_EC600NCN_AA__) \
	|| defined (__QUECTEL_PROJECT_EC600NCN_AC__)
#define QUEC_BAND_LTE_TDD_SUPPORT
#define QUEC_BAND_LTE_FDD_SUPPORT
#define QUEC_BAND_GSM_SUPPORT

#elif defined (__QUECTEL_PROJECT_EC200SCN_MA__) 
#define QUEC_BAND_LTE_TDD_SUPPORT
#define QUEC_BAND_GSM_SUPPORT

#elif defined (__QUECTEL_PROJECT_EC200SCN_LB__) || defined (__QUECTEL_PROJECT_EC600SCN_LA__) \
    || defined (__QUECTEL_PROJECT_EC600NCN_LA__) || defined (__QUECTEL_PROJECT_EC600SCN_LB__)\
    || defined (__QUECTEL_PROJECT_EC600SCN_LC__) || defined (__QUECTEL_PROJECT_EC600SCN_LD__)\
    || defined (__QUECTEL_PROJECT_EC200NCN_LA__) || defined (__QUECTEL_PROJECT_EC600NCN_LC__) \
    || defined (__QUECTEL_PROJECT_EC200NCN_GB__) || defined (__QUECTEL_PROJECT_EC800NCN_LA__) \
    || defined (__QUECTEL_PROJECT_EC600NCN_LF__) || defined (__QUECTEL_PROJECT_EC600NCN_LE__) \
    || defined (__QUECTEL_PROJECT_EC600MCN_LC__) || defined (__QUECTEL_PROJECT_EC600MCN_LA__) \
    || defined (__QUECTEL_PROJECT_EC600MCN_LF__) || defined (__QUECTEL_PROJECT_EC600MCN_LE__)\
    || defined (__QUECTEL_PROJECT_EC800MCN_LA__) || defined (__QUECTEL_PROJECT_EC800MCN_LE__)\
    || defined (__QUECTEL_PROJECT_EC800MCN_LC__) || defined (__QUECTEL_PROJECT_EC800MCN_LF__) \
    || defined (__QUECTEL_PROJECT_EC800MCN_MC__) || defined (__QUECTEL_PROJECT_EC800MCN_GA__) \
    || defined (__QUECTEL_PROJECT_EC800MCN_GC__) || defined (__QUECTEL_PROJECT_EG810MCN_GA__)\
	|| defined (__QUECTEL_PROJECT_EC200MCN_LA__) || defined (__QUECTEL_PROJECT_EC200MCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EC200MCN_LE__) || defined (__QUECTEL_PROJECT_EC200MCN_LF__) \
	|| defined (__QUECTEL_PROJECT_EC200MCN_GB__) || defined (__QUECTEL_PROJECT_EC600MCN_MC__) \
	|| defined (__QUECTEL_PROJECT_EC600MCN_CC__) || defined (__QUECTEL_PROJECT_EC600MCN_GC__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_CC__) || defined (__QUECTEL_PROJECT_EC100MCN_LA__) \
    || defined (__QUECTEL_PROJECT_EC800MCN_GD__) || defined (__QUECTEL_PROJECT_EG810MCN_LA__) \
    || defined (__QUECTEL_PROJECT_EC600KCN_CC__) || defined (__QUECTEL_PROJECT_EC800KCN_CC__) \
    || defined (__QUECTEL_PROJECT_EG800KCN_GC__) || defined (__QUECTEL_PROJECT_EC600MEU_LA__) \
    || defined (__QUECTEL_PROJECT_EC800KCN_CZ__) || defined (__QUECTEL_PROJECT_EC800MCN_GB__) \
    || defined (__QUECTEL_PROJECT_EC800KCN_LC__) || defined (__QUECTEL_PROJECT_EG810MCN_GB__) \
 	|| defined (__QUECTEL_PROJECT_EC600KCN_LC__) || defined (__QUECTEL_PROJECT_EG800PCN_00LA__)\
 	|| defined (__QUECTEL_PROJECT_EG810MCN_LC__) || defined (__QUECTEL_PROJECT_EG810MCN_LC__) \
 	|| defined (__QUECTEL_PROJECT_EC800KCN_MC__) || defined (__QUECTEL_PROJECT_EC600KCN_MC__)\
	|| defined (__QUECTEL_PROJECT_EC600KCN_CK__) || defined (__QUECTEL_PROJECT_EC600KCN_LK__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_CK__) || defined (__QUECTEL_PROJECT_EC800KCN_LK__)\
 	|| defined (__QUECTEL_PROJECT_EC800KCN_MD__)
#define QUEC_BAND_LTE_TDD_SUPPORT
#define QUEC_BAND_LTE_FDD_SUPPORT

#elif defined(__QUECTEL_PROJECT_EC800MCN_GM__)  || defined (__QUECTEL_PROJECT_EC800MCN_NC__) \
	|| defined (__QUECTEL_PROJECT_EC600MCN_NC__)

#define QUEC_BAND_LTE_TDD_SUPPORT

#elif defined (__QUECTEL_PROJECT_EC200SEN_AA__)
#define QUEC_BAND_LTE_FDD_SUPPORT
#define QUEC_BAND_GSM_SUPPORT
#define QUEC_BAND_LTE_EXT_SUPPORT 1

#elif defined (__QUECTEL_PROJECT_EC200SCN_TA__) ||defined (__QUECTEL_PROJECT_EG800KEU_CC__) || defined (__QUECTEL_PROJECT_EG810MEU_LA__)\
	|| defined (__QUECTEL_PROJECT_EG810MEU_LC__)||defined (__QUECTEL_PROJECT_EG800KEU_LC__)
#define QUEC_BAND_LTE_FDD_SUPPORT

#elif defined (__QUECTEL_PROJECT_EG810MLA_LC__) || defined (__QUECTEL_PROJECT_EG800KLA_CC__) || defined (__QUECTEL_PROJECT_EG800KLA_LC__)|| defined (__QUECTEL_PROJECT_EC600MLA_LA__)
#define QUEC_BAND_LTE_FDD_SUPPORT
#define QUEC_BAND_LTE_EXT_SUPPORT 1

#elif defined (__QUECTEL_PROJECT_EC200SAU_AA__)
#define QUEC_BAND_LTE_TDD_SUPPORT
#define QUEC_BAND_LTE_FDD_SUPPORT
#define QUEC_BAND_GSM_SUPPORT
#define QUEC_BAND_LTE_EXT_SUPPORT 1
#else
	//QUEC_BAND_UMTS_SUPPORT //3G的band支持
	#error "Please configure the project"
#endif


#if defined (QUEC_BAND_LTE_TDD_SUPPORT) || defined (QUEC_BAND_LTE_FDD_SUPPORT)
#define QUEC_LTE_SUPPORT 1
#else
#define QUEC_LTE_SUPPORT 0
#endif

//Chaim 20200710 ??????,??????
#define QUEC_ENGINEER_OUTPUT

//evin 20210616 DISABLE enlarge paging cycle.
#define QUEC_ENLARGE_PAGING_CYCLE_DISABLE

//evin 20210809 when rejrcted,at+cops?,should report +cops:mode;
#define QUEC_COPS_REJRCT_REPORT_FORM 1

#ifdef __QUEC_OEM_VER_BPC__
//sawyer 20230206 add AT+CCED function
#define QUEC_CCED_SUPPORT
// carson add tcp function for YUSONG requirement
#define QUEC_CIP_TCP_SUPPORT
#endif

//fei 20220302 add xnping cust cfun support
#if defined (__QUEC_OEM_VER_XP__)
#define QUEC_CUST_XIPING_SUPPORT			(1)
#endif
//destin netif_ppp & netif_pc ip domain name white list feature support.
#ifdef QUEC_CUST_XIPING_SUPPORT	
#define QUEC_PPP_NETIF_IP_DN_WLIST_FEATURE	(1)
#endif

//marvin.ning 2024.8
#define QUEC_CEER_ESM_REJECT_CAUSE_SUPPORT 1

/******************************************* SMS/PHB/CALL/STK/BIP/USSD/(U)SIM function**************************************************************/
#ifdef QUEC_ASR_SMS_ENABLE
#define QUEC_ASR_SMS_INPUT_PRINT
#define QUEC_ASR_SMS_SEND
#define QUEC_ASR_SMS_MSG_PRINT
//evin 20210729 fix intergrate from 1802s wrong spelling,keep same name function.
#define QUEC_ASR_SMS_ENBALE
//Fitz.xu 20200509: simplify msg log
#define QUEC_SIMPLIFY_SMS_LOG (1)
//Fitz.xu 20200521: To fix no +CMTI and sms not saved when AT+CSDH=1
#define QUEC_SMS_CSDH_OPTIMIZE  (1)
/* Fitz.xu 20200528: To fix convert GSM to UCS2 failed because buffer is not enough.
 * Jira: STASR1601-500
 */
#define QUEC_SMS_GSM_TO_UCS2_OPTIMIZE  (1)
//Fitz.xu 20200611: To save AT+CPMS config
#define QUEC_SMS_CPMS_SAVE_SUPPORT  (1)
//Fitz.xu 20200809: Add at+qcsmp support
#define QUEC_SMS_QCSMP_SUPPORT  (1)
//Fitz.xu 20200926: UCS2 max size optimize for sms
#define QUEC_SMS_UCS2_MAX_SIZE_OPTIMIZE  (1)
//Fitz.xu 20201028: Optimize AT+CNMI
#define QUEC_SMS_CNMI_OPTIMIZE  (1)
//Fitz.xu 20201029: Optimize for UCS2 ims sms
#define QUEC_SMS_IMS_UCS2_OPTIMIZE  (1)
//Fitz.xu 20201124: to fix STASR1601-2113
#define QUEC_SMS_CMGW_OPTIMIZE  (0)
//Fitz.xu 20201130: to fix read sms status error, fix STASR1601-2239
#define QUEC_SMS_CMRSS_CMGSS_OPTIMIZE  (1)
//Fitz.xu 20201209: To fix AT+CMGD=0,4 failed after power reset 
#define QUEC_SMS_ME_DELETE_ALL_OPTIMIZE  (1)

//Fitz.xu 20201223: Enable BIP
#ifdef BIP_FUNC_SUPPORT
#define QUEC_BIP_SUPPORT  (1)
#endif
//Fitz.xu 20201201: ASR ims stack supports 162*5-1 byte
#define QUEC_SMS_MAX_SIZE_OPTIMIZE  (1)
//Fitz.xu 20211028: Optimize at+cmgl for ME sms.
#define QUEC_SMS_OPTIMIZE_ME_CMGL  (1)
//Fitz.xu 20210717: Fix at+cmgw failed in PDU mode
#define QUEC_SMS_CMGW_CMGS_OPTIMIZE  (1)

//Fitz.xu 20210427: To optimize sms output arrow, 
//See https://knowledge.quectel.com/pages/viewpage.action?pageId=61114339
#define QUEC_SMS_SEND_ARROW_OPTIMIZE  (1)

#define QUEC_SMS_QCMGSP_SUPPORT 1
//Evin  20210105 解决AT+CMGS发送短信,导致AT+CMGW写入短信UNSENT变为SENT状态问题
#define QUEC_MSM_CMGW_STATUS_BUG

//west 20181116 at+cscs cmd support
#define QUEC_AT_CSCS_SUPPORT

//isaac 20210304: support sms white feature
#define QUEC_SMS_WHITE_SUPPORT

#endif

//Fitz.xu 20201223: Enable BIP
#ifndef LTEONLY_THIN_SINGLE_SIM  //单卡的2M Flash项目不支持双卡
#ifndef __QUEC_OEM_VER_PAX__
#define QUEC_BIP_SUPPORT  (1)
#endif
#endif

//Tery.shi 20181126 add the SIM to enable/disbale
#define QUEC_ASR_SIM_ENBALE

//jensen.fang 20191014: to support vsim
#define QUEC_VSIM_ENABLE 1
//evin 20210720  fix AT+CSIM choose channel 1,return +CGLA error form.should be +CSIM;
#define QUEC_CSIM_RETURN_FORM      1

//Fitz.xu 20200510: add PINCNT 
#define QUEC_SIM_PINCNT_SUPPORT (1)

//2023.06.12 single and dual sim both use asr sim detect process.
//2023.06.25 全部使用ASR的SIM卡检测逻辑,此宏控制移远的SIM卡热插拔代码
#define QUEC_ASR_SIM_HOT_PLUG_SUPPORT    (1)

//usim detect此宏是使用移远自己的SIM卡热插拔代码逻辑
//#define QUEC_USIM_PRESENCE_INTERRUPT_ENABLE  1


#ifndef LTEONLY_THIN_SINGLE_SIM  //单卡的2M Flash项目不支持双卡
//Fitz.xu 20210616: Add dual sim support
#ifndef LG_THIN
#define QUEC_DUAL_SIM_SUPPORT  (1)
#define QUEC_ATP_OFFSET_36     (36)
#define QUEC_DUAL_SIM_DATA_SERVICE_SUPPORT (1)
#endif
#endif

//Tery.shi 20181207 add the at cmd pata init to enable/disbale
#define QUEC_ASR_ATCMD_PARA_INIT_ENBALE

#ifndef REMOVE_PB
//Tery.shi 20181130 add the PHB to enable/disbale
#define QUEC_ASR_PHB_ENBALE
//Fitz.xu 20201228: To limit phonebook num to 10
#define QUEC_PHONEBOOK_LIMIT_TO_10  (1)
#endif

#ifdef VOLTE_ENABLE
/*Tery.shi 20181228 add the CALL to enable/disable */
#define QUEC_ASR_CALL_ENABLE
/*Aaron.Li 2019/05/14-ASR1802S00003-P01 add call related AT command macro */
#define QUEC_ASR_AT_CALL_SUPPORT
//Fitz.xu 20190824: To enable call status check
#define QUEC_CALL_STATUS_SUPPORT
//Fitz.xu 20200307: to support CLIP
#define QUEC_CLIP_SUPPORT  (1)
//Fitz.xu 20200414: add AT^DSCI
#define QUEC_CALL_DSCI_SUPPORT
//Fitz.xu 20210521: To fix multi calls ^DSCI report issue
#define QUEC_CALL_MULTI_CALL_DSCI_REPORT_SUPPORT  (1)
//Fitz.xu 20201030: Optimize NO CARRIER report, STASR1601-1634
#define QUEC_CALL_NO_CARRIER_REPORT_OPTIMIZE  (1)
//Fitz.xu 20201105: Optimize report +CLIP and +COLP
#define QUEC_CALL_OPTIMIZE_CLIP_COLP  (1)
//Fitz.xu 20201123: 1> ims call will auto answer the call immediately
//                  2> when reset, auto answer function will be invalid 
//Fix FAE-4813, FAE-5056
#define QUEC_CALL_IMS_AUTO_ANSWER_OPTIMIZE  (1)
//Fitz.xu 20210319: Add AT+QCFG="ims"
#define QUEC_QCFG_IMS_SUPPORT  (1)
//Fitz.xu 20200710: To support IMS
#define QUEC_IMS_SUPPORT  (1)
//Fitz.xu 20200722: To support IMS XML
#define QUEC_IMS_XML_SUPPORT  (1)
//Fitz.xu 20020601: add +COLP output
#define QUEC_CALL_COLP_OPTIMIZE  (1)
//evin 202210629 fix mulit call,MASTER ATH,URC REPORT NO CARRIER
#define QUEC_FIX_MULIT_ALL_NOCARRIER  (1)
#endif



//Fitz.xu 20200610: Optimize CUSD output
#define QUEC_CUSD_OPTIMIZE  (1)

//Fitz.xu 20200506: optimize delete msg
#define QUEC_DELETE_MSG_OPTIMIZE (1)

//Fitz.xu 20200508: optimize receive msg
#define QUEC_RECV_MSG_OPTIMIZE (1)

//Fitz.xu 20200509: optimize re-send received msg
#define QUEC_SEND_MSG_OPTIMIZE (1)


//Fitz.xu 20200713: to optimize +CPBR
#define QUEC_CPBR_CPBF_OPTIMIZE  (1)


//Fitz.xu 20211229: Add dual IMEI support
#define QUEC_DUAL_IMEI_SUPPORT  (1)


//evin 20210313 fix minisys report NWINFO problem
#define QUEC_AUTO_MINISYS_NW_REPORT  (1)

/* destin.zhang  */
#define QEUC_FIX_AT_CMD_FORMAT_ISSUE (1)

#define QUEC_STARTREPORT_OPTIMIZE

/************************************************************ TCPIP function*****************************************************/
#ifndef NO_MBEDTLS
#ifndef QUEC_MINSYS_THIN
#define QUEC_SSL_SUPPORT_BOTH_SYS
#define QUEC_SSL_SUPPORT
#endif
#ifdef QUEC_SSL_SUPPORT
#define QUECTEL_MBEDTLS_SUPPORT
//#define QUEC_WOLFSSL_SUPPORT
#define QUEC_SSL_CACERT_EX_SUPPORT  //添加cacertex宏 
#define QUECTEL_SSL_CFG_CLOSE_TIME_MODE
#define QUECTEL_SSL_CFG_IGNORE_MULTICERTCHAIN_VERIFY_AND_INVALIDCERTSIGN
//domingo.deng@2019.10.15:add ssl cfg IGNORE_EXPIRATION
#define QUECTEL_SSL_CFG_IGNORE_EXPIRATION_VERIFY
#define QUEC_WOLFSSL_LOG_DEBUG//Control closed ssl log printf
#define QUECTEL_SSL_SESSION_CACHE_FEATURE //domingo.deng@2019.11.12: optimize the ssl session cache process
#define QUECTEL_SSL_CFG_SESSION_CACHE_ENABLE   //domingo.deng@2019.12.10, add cmd to configure whether to use ssl session cache
#define QUEC_SSL_ALPN_FEATURE
#ifndef LTEONLY_THIN_SINGLE_SIM
#define QUECTEL_DTLS_FEATURE
#endif
#define QUEC_SSL_RENEGOTIATION_FEATURE
#define MBEDTLS_SSL_VERSION_ALL_HIGH_FIRST
#ifndef __QUEC_OEM_VER_CUD__
#define	QUEC_SSL_PSK_FEATURE
#endif
#endif
#endif
#ifdef QUECTEL_MBEDTLS_SUPPORT
#define QUECTEL_MULTI_PLEXING_FEATURE //larson 20210115 ,fix multi plexing ssl config cause dump
#endif


#ifndef MIN_SYS
#define QUEC_SOCKET_SUPPORT
#define QUEC_APPTCPIP_SUPPORT
#define QUEC_DEFAULT_AUTH_CHECK_SUPPORT 1

//domingo.deng@2020.12.01 fix sim remove not report pdp deact urc when tcpip in datamode 
#define QUEC_TCPIP_DATAMODE_NETDOWN_URC_FIX
//Luffy.liu 20191029 add tcpip qiaccept support!
#define QUEC_TCPIP_QIACCEPT_SUPPORT
//Harold.wang 20200221 add:AT+QICFG="send/buffersize",(1460-10240) ,????qisend ???????????
#define QUEC_TCPIP_SEND_BUFFER_SIZE_SUPPORT
//larson.li 20200622 Add QUECTEL_QISEND_AUTO_BYTIME and QUECTEL_QIRECV_IGNORE_MSG for +QICFG&"send/auto"&"recv/ignore".
#define QUECTEL_QISEND_AUTO_BYTIME
//carson.liu 20210113 Add QUEC_TCPIP_QISEND_BACK_MODE for AT+QICFG="send/Changeformat",make the return from 0D0A> to output 0D0A>0D0A
#define QUEC_TCPIP_QISEND_CHANGE_FORMAT
#define QUEC_TCPIP_PUSH_AT_PARSER_32BYTE_MULTIPLE_0A//the total length of AT commond is 32 bytes,get an extra \n output
#define QUEC_TCPIP_TRANSPARENT_PRIORTIY_FLOW_FEATURE //High baud rate TCP transparent transmission flow control 20211204
//Larson.li 20190819 add g_CM_Context variable mutex
#define QUEC_PDP_CONTEXT_MUTEX_SUPPORT
#define QUEC_TCP_EDIT_SENDMODE_TIMEOUT_FEATURE  //harold.wang 20200721 add edit mode timeout exit function(for ">" not receive.)
#define QUEC_TCP_QISEND_TIMEOUT_FEATURE  //harold.wang 20210130 add edit mode timeout exit function(for ">" not receive.) same function as QUEC_TCP_EDIT_SENDMODE_TIMEOUT_FEATURE
#define QUEC_TCP_QISEND_SENDINFO_FEATURE //carson.liu 20210413 add enable or disable display and execution in URC form AT+QISEND return information
#define QUEC_TCPIP_SEND_DIRECT_PUSH_DATA_FEATURE//harold.wang 20201028 add Add TCP to send data directly  by AT cmd
#define QUEC_TCPIP_UDP_RECV_ZEROBYTE_REPORT_URC_FEATURE//add UDP also outputs URC when it receives 0 bytes   harold.wang 20201028 
#define QUEC_TCPIP_SENDCRC_SUPPORT //carson.liu 20201202 add AT cmd : AT+QISENDCRC
#define QUEC_TCPIP_QICFG_LPC_FEATURE //harold.wang 20211210 adjust qicfg heartbeat LPC function
#define QUEC_TCPIP_WAKEUP_DATA_FEATURE //fawei.zhou 20210805 add AT+QICFG="wakeup/data",<connectID>,<wakeup_data>
#define QUEC_TCPIP_WINDOW_SCALE_FEATURE // carson.liu 20230522 add AT+QICFG="window/scale" function.
#define QUEC_TCPIP_QICLOSE_ASYNC_FEATURE //harold.wang 20200130 add qiclose Asynchronous mode
#define QUEC_TCPIP_SWITCH_MULTIPLE_MODE_FEATURE //carson.liu 20230404 Customized by ZHOUMING, switch multiple connections at the same time
#ifdef 	__QUEC_OEM_VER_XDL__
#define	QUEC_TCPIP_SENDMODE_XDL//carson.liu 20201110 Support output 0D0A>0D0A
#endif
#define QUEC_TCP_NETCONN_EVT_SENDACKED_FEATURE  //harold.wang 20200910 Modify QISEND to report SEND OK after receiving server answer ack
//#define QUEC_CUSTOM_LAST_GASP_FEATURE  //add UKRAINE custom function   harold.wang 20210316 
#define QUEC_TCP_DNS_TIMEOUT_CONFIG_FEATURE //Caican.lin 20200510 Add QICFG:dns/timeout to set dns BOTH timeout and retries.
#define QUECTEL_TCPUDP_SAFE_DATA_FREE 			//domingo.deng@2019.11.15 free the tcp data before free the linklist
//Adwin.wang 20190610:quec tcp client ctrl enable macro
#define QUEC_TCP_CLIENT_CTRL_ENABLE
//Adwin.wang 20190610:quec tcp server no connection keepalive ctrl enable macro
#define QUEC_TCP_SERVER_NC_KALIVE_CTRL_ENABLE
//domingo.deng@2020.06.04  tcpip connect force lwip select quit once
//#define	QUECTEL_TCPIP_LWIP_FORCE_QUIT

#define QUEC_HTTP_CFGEX_MULT_FILE_POST //harold.wang 20221018 QHTTPSEND Multiple file upload

#ifdef QUECTEL_OPEN_CPU
#define QUEC_ADD_CHECK_CUSTOMER_FS_BLOCK
#endif

#ifdef QUEC_HTTP_SUPPORT
#define QUEC_HTTP_ATRESP_REPORT_FORMAT //harold.wang 20200508 mod http report format, change cme error to name code
#define QUEC_HTTP_MULTI_REPLY_OUT_FIRST_CONTENT  //harold.wang 20200624 mod http multiple replies to output only the first content
/*IMPROVE 010 ram, < 500K, FOTA easy dump*/
//#define QUEC_HTTP_IMPROVE_FILE_WRITE_EFFICIENT //harold.wang 20200909 mod http improve write efficiency and reduce write time
#define QUEC_HTTP_DELETE_DEFAULT_PORT // carson.liu 20210728 delete the default port in the HOST field of HTTP,80 or 443
#endif

//evan.li-2020/09/18: add tencent iot cmd support.
#ifdef __QUEC_OEM_VER_TENCENTIOT__
#define QUEC_TCIOT_SUPPORT
#define QUECTEL_SSL_CA_BUF	//添加ssl 配置CA证书字符串 harry@2021.7.15

//larson.li 20190115 add the fota data interface feed function
#define QUEC_FOTA_FEED_SUPPORT

//jensen.fang 20181218: to enable quec fota model
#define QUEC_FOTA_SUPPORT

//fitz.xu 20190515: to enable quec ftp fota
#define QUEC_FTP_FOTA_SUPPORT

//jensen.fang 20190226: add recovery of image(cp/msa/rf) support
#define QUEC_RECOVERY_SUPPORT

#endif

#ifndef QUECTEL_OPEN_CPU
//#ifndef LTEONLY_THIN_SINGLE_SIM_2MFLASH
//fitz.xu 20190617: Add certification support
#define QUEC_CERT_SUPPORT
#if defined (__QUEC_OEM_VER_CT__)
#ifdef QUEC_CERT_SUPPORT
#define QUECTEL_IOT_RPT_SUPPORT
#endif
#endif
#endif

#define QUEC_QNVFD_DEL_NV_FEATURE /*Delete the nv file and restore the default value 20211207 harold.wang*/

//Adwin.wang 20190528 add ntp cmd support
#define QUEC_NTP_SUPPORT

#ifdef QUEC_FTP_SUPPORT
#define QUECTEL_FTP_FLOW_CONTROL // haroldcodeflag20190708
#define QUECTEL_FTP_MOD_EXPLICIT_MULTIPLE_REPLIES //Modify FTPS explicitly ,add FTP multiple response process  harold.wang@2020.3.2
#define QUECTEL_FTP_CFG_CACHE_TYPE //Modify 609 caused by high performance server pushing large amount of data  harold.wang@2020.9.15
#define QUECTEL_FTP_MOD_SPLIT_DOWNLOAD_FEATURE //Split download to solve the problem of server base station window mismatch and ACK error  harold.wang@2020.10.12
#endif


#ifdef QUEC_MQTT_SUPPORT
#define QUECTEL_MQTT_TRANSPARENT
#define QUEC_QMTCFG_CHECK_MQTT_PROTOCOL_STANDARD //add the command to enable or disable checking the standard of mqtt protocol
#if defined (__QUEC_OEM_VER_ALIOT__)
#define QUECT_ALIOT_FEATURE_SUPPORT
#endif

#if defined (__QUEC_OEM_VER_DMP__)
#define QUEC_MQTT_UNIFY_SUPPORT
#endif

#define QUEC_MQTT_ADJUST_RECV_RECURSIVE_STACK_OVERFLOW //Modify MQTT to receive data recursively, stack overflow harold.wang@2020.11.16
#define QUEC_MQTT_EDIT_SENDMODE_TIMEOUT_FEATURE //luffy.liu 20201113 add edit mode timeout exit function
//[20240715][caden.zhang][FAE-125296]Added the function for MQTT specific topics to trigger RI changes when sleeping
#define QUEC_MQTT_WAKEUP_TOPIC_SUPPORT
#endif
/*********************************************** SMTP function***********************************************/

#ifdef QUEC_SMTP_SUPPORT
#define QUECTEL_SMTP_MOD_MULMSG_MULTIPLE_REPLIES //Modify smtp multiple response on multiple messages  harold.wang@2020.8.3
#define QUECTEL_SMTP_SUPPORT
#endif

/******************************************* LOCATOR_APP function********************************************/
#ifdef FEATURE_QUECTEL_LOCATOR_APP
#define FEATURE_QUECTEL_LOCATOR_ENHANCE
#define	FEATURE_QUECTEL_LOCATOR_QLBS
#define	FEATURE_QUECTEL_LOCATOR_QLBS_EXT
#define FEATURE_QUECTEL_LOCATOR_HTTP
#define MOD_QUECTEL_LOCATOR_RESULT_REPORT//harold.wang@2020.04.10 mod connect timeout report urc
#endif/* FEATURE_QUECTEL_LOCATOR_APP */

/*********************************************** MMS function***********************************************/

//Gipsy.gao 20191204 add mms suport
#ifdef QUEC_MMS_SUPPORT
#define QUEC_MMS_ADD_SEND_MAX_PKTLEN //harold.wang 20200224 add mms ,Socket sends the maximum length each time 
#endif

//AT控制GPIO开启和关闭PA
#define QUEC_AT_QGPIOEXT_SUPPORT 1
//AT控制GPIO拉高拉低功能

/******************************************** Audio function*************************************************/
//grady.quan 20181122 add audio cmd support
#ifndef QUEC_NOAUDIO

#ifndef QUECTEL_OPEN_CPU
#define QUEC_AT_CMD_AUDIO_SUPPORT
#define QUEC_AUDIO_CFG_SUPPORT
#define QUEC_AUDIO_PCM_API_SUPPORT  (1)
#else

#ifdef QUEC_OEM_CAC /*------------------------CAC定制*/
#define QUEC_AT_CMD_AUDIO_SUPPORT
#define QUEC_AUDIO_CFG_SUPPORT
#define QUEC_AUDIO_PCM_API_SUPPORT  (1)
#else/*-------------------------------------OPEN公版*/
#define QUEC_PCM_FUNC
#define QUEC_WAV_FUNC
#define QUEC_MP3_FUNC
//#define QUEC_AMR_FUNC

#define QUEC_FAST_DECODE
#endif
//#define QUEC_POC_SUPPORT
#endif
#define QUEC_AUDIO_SUPPORT (1)
//Fitz.xu 20200402: add headset support
#define QUEC_AUDIO_VOICE_PATH_HEADSET_SUPPORT
//Egan.Li 20200606: add codec switch support
#define QUEC_AUDIO_CODEC_SW_SUPPORT  (1)
#define QUEC_AUDIO_HSDet_SUPPORT  (1)
//Egan.li acdb support
#define QUEC_AUDIO_ACDB_SUPPORT  (1)
//Egan.li add LDTMF support
#define QUEC_LDTMF_SUPPORT        (1)
//Egan.li add WDTMF support
#define QUEC_WDTMF_SUPPORT        (1)
//Egan.li Add DTMF detection support
#define QUEC_DTMF_DETECT_SUPPORT  (1)
#define QUEC_DTMF_LOCTED_SUPPORT  (1)
//Egan.li Add LTONE support
#define QUEC_LTONE_SUPPORT        (1)


//Egan.li 20200616: add tone incoming support
#define QUEC_AUDIO_TONE_INCOMING_SUPPORT (1)


#ifndef  QUEC_TTS_NOT_SUPPORT

#ifdef QUECTEL_OPEN_CPU

#ifdef QUEC_OEM_CAC /*---------------------------CAC定制*/
#define QUECTEL_TTS_FEATURE
//Fitz.xu 20200401: add tts task XIP support
#define QUEC_TTS_TASK_XIP_SUPPORT
//Egan.li add WTTS support
#define QUEC_QWTTS_SUPPORT (1)
//Egan.li add 16K TTS support
#define QUEC_TTS_SUPPORT_IFK  (1)
#else/*----------------------------------------OPEN公版*/
#define QUEC_AUDIO_TTS_SUPPORT (1)
#endif

#else
#define QUECTEL_TTS_FEATURE
//Fitz.xu 20200401: add tts task XIP support
#define QUEC_TTS_TASK_XIP_SUPPORT
//Egan.li add WTTS support
#define QUEC_QWTTS_SUPPORT (1)
//Egan.li add 16K TTS support
#define QUEC_TTS_SUPPORT_IFK  (1)
#endif
#endif

#ifndef QUEC_AMR_NOT_SUPPORT
//Egan.li amr support
#define QUEC_AUDIO_AMR_SUPPORT    (1)
#endif

#ifdef MP3_DECODE
//Egan.li mp3 support
#define QUEC_AUDIO_MP3_SUPPORT    (1)
#define QUEC_QPSND_SUPPORT (1)
#endif

#ifdef UAC_SUPPORT
//Egan.li uac support
#define QUEC_AUDIO_UAC_SUPPORT    (1)

#endif

#endif

/********************************************nand文件系统功能宏*************************************************/
//#define QL_NAND_YAFFS

/******************************************** Camera function***************************************************/

#ifdef 	QUEC_CAMERA_SUPPORT

//#define QL_CAMERA //This macro is the control of camera code crop    (OPEN_Project) 
#define QUEC_SLAS_SUPPORT //@20230925 使用移远自研解码库需要打开此宏，默认关闭
#ifndef QUECTEL_OPEN_CPU
    #define QUEC_AT_CMD_CAMERA_SUPPORT       (1)	//This macro is the control of camera code crop    (STD_Project) 
    #define __QUEC_CAMERA_DEBUG__	//Camera 调试相关的代码 使用时必须先打开QL_CAMERA
    #define __QUEC_QR_CODE__         //@20230110 解码库相关接口宏控 标准项目默认打开
#else
    #ifdef QL_CAMERA 
    #define __QUEC_CAMERA_DEBUG__					//open
    #define __QUEC_QR_CODE__                     //@20230110 open项目默认关闭，方便裁剪，若使用camera,须将此宏打开
    #endif
#endif
#define __QUEC_CAMERA__                  (1)	//修复camera bug宏
#define QUEC_CAMMERA_DECODE_AUTHORIZATION 		//Camera 解码库授权相关的代码
							
#endif

/************************************************** keypad function****************************************/

#ifdef QUEC_KEYPAD_SUPPORT

#define QL_KEYPAD

#endif
/************************************************** LCD function***************************************************/

#ifdef QUEC_LCD_SUPPORT

//#define QL_LCD

#endif



//20200201,harley,巴西IPV6认证引入的IPV6地址获取RS RA行为控制的AT命令
#define QUEC_IPV6_CONFIG


//domingo.deng@2020.02.27 when pdp ip type is IPV4V6,support connect ipv4 address and ipv6 address at the same time
//notice:tcpip local ip type is decided by remote ip type when connect the remote ip

#define QUEC_PDP_IPV4V6_SUPPORT

//domingo.deng@2020.04.09 when pdp is actived,qicsgp qury error 
#define QUEC_PDP_PROFILE_MIRROR_SUPPORT

//domingo.deng@2020.04.09 qicsgp support PAP_OR_CHAP
#define QUEC_PAP_OR_CHAP_AUTH_SUPPORT
#define QUEC_QICSGP_AUTH_USERPWD_128BYTE //harodl.wang@2020.04.13 qicsgp support user/password 128 byte save

//Fitz.xu 20200409: Add fseek fwrite optimize
#define QUEC_FSEEK_FWRITE_OPTIMIZE

#endif /*MIN_SYS*/
/******************************************************************************************
isaac.shi@quectel.com-2020/04/29:Description....
Refer to [Issue-Depot].[IS0001183][Submitter:2020-04-29,Date:2020-04-29]
******************************************************************************************/
#define QUECTEL_PDP_CONTEXT_RETURN_FORMAT_ERROR_FIX


//domingo.deng@2020.06.04  deactive all active pdp when recv deattch indcation
#define QUEC_DEACT_PDP_FROM_DEATTCH

//20200529,CCLK????????
#define	QUECTEL_CCLK_MEMORY_LEAK_REPAIR


//20200703
/*
STASR1802S-1493
*/
#define	QUEC_APN_COMMA_BUG

//luffy 20200925 add qicsgp save auth_type parameter to json file
//#define QUEC_QICSGP_SAVE_TO_JSON

//isaac 20200602: add at+qcfg="csqtype",<val> to calculate csq by rssi(val is 0) or rsrp(val is 1)
#define QUECTEL_CSQ_TYPE

//isaac 20200225: add at+qcellselectcfg
#define QUECTEL_CELL_SELECT_CFG


//domingo.deng 两路pdp相同apn 激活后,只存在一路pdp,修改发起激活的pdp与默认attach apn 相同就会产生remap，避免后续激活抢占pdp 
#define	QUECTEL_FIX_INCORRECT_PDP_INIT_TYPE

//isaac 20200708: add at+qsimpollcfg sim???????
#define QUECTEL_SIM_POLL_CFG

//isaac 20200804 add at+qncell ??????cellid,?at+qeng="neighbourcell" ???cellid
#define QUECTEL_CELL

//ford 202008011 add for AT+QSCLK=2,X
#define QUECTEL_QSCLK2_SUPPORT


//isaac 20201107 add at+rsrp
#define QUEC_RSRP_SUPPORT

/********************************start MINI OS Related macro definition*********************************/
/*Quectel macro definition*/
#define QUEC_FOTA_BREAK_POINT_DOWN_LOAD_CACHE_FEATURE  //Breakpoint downloads feature macros 
#define QUEC_MINISYS_PROJECT_CUST  //MINI OS quectel macro definition
//#define QUEC_MINISYS_JUDGE_FOTA_FILE_EXIST //determine the validity of the server firmware package file
#define QUEC_MINISYS_USEFOR_APN_ACTIVATE  //Save APN for activating and setting network card under non-default bearer (2G)


#define QUEC_FOTA_DOWN_LOAD_WM_CACHE_FEATURE  //watermark ringbuffer feature macros 

#define  QUECTEL_MINIFOTA_SUPPORT

#define QUEC_MINISYS_FOTA_DOWNLOAD_URC  //mini fota download urc report
//Determine whether the file exists, otherwise it will not enter the MINI OS
#define QUEC_JUDGE_FOTA_FILE_EXIST //determine the validity of the server firmware package file
#define QUEC_MINISYS_FOTA_FTP_IPV6_FEATURE  //MINI OS FOTA FTP IPV6 macro definition

/********************************end MINI OS Related macro definition*********************************/



//evin  20210427 fix at+cgatt=0;+CGEV: ME DETACH report twice.
#define QUECTEL_CGEV_NOT_SHOW


// Ford 20200524 add for paging update function
#define QUEC_ASR_ATCMD_PAGING_UPDATE_SUPPORT

//isaac 20210708 add at+qcellinfo 
#define QUEC_QCELLINFO_SUPPORT


//evin.zhu 20210823 fix minisys default enable sleep problem,Change:Disable sleep.
#define QUEC_MINISYS_DISABLE_SLEEP 1

//isaac 20211001 not support pdp type: PPP
#define QUEC_PDP_TYPE_PPP_FIX

//isaac 20211001 fix urc reverse order issue
#define QUEC_URC_ORDER_FIX
//isaac 20220107 disbale ASR pseudo base station 
#define QUEC_DISABLE_PSEUDO_BS

//isaac 20211101 fix csq issue
#define QUEC_CSQ_FIX


//Ford 20211230 add for ci debug support
#define QUEC_AT_CIVER_SUPPORT

//evin.zhu 20210119 fix psm ';' check problem
#define QUEC_PSM_CHECK_SPECIAL_CHARACTER

//destin.zhang 20230530 serail wifi sta support for open. 
#ifdef QUECTEL_OPEN_CPU
#ifdef QUEC_OEM_CAC /*----------------华宝定制*/

#else/*-------------------------------OPEN公版*/
#define QUEC_FC41D_WIFI_SUPPORT (1)

//marvin.ning 2024.09 R06分支只有8M的open版本,公版就需要支持. 标准版本需要通过OEM控制生成该宏.
#define QUEC_FGM842D_WIFI_SUPPORT (1) 
#endif
#endif



/*END OF FIEL*/

#endif/* QUECTEL_PROJECT_CUST */
#endif /* QUEC_CUST_FEATURE_H */
