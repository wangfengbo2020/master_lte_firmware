/**  @file
  quec_cust_patch.h

  @brief
  This file is used to define macro of patch for different Quectel Project.

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
11/30/2018        Jensen     Init version
=================================================================*/

/*=============================================================================================================================

                        Patch List

This section contains comments describing patch list to the module.
Notice that changes are listed in reverse order.

NO.  PATCH NO.      RELEASE TIME  MERGE TIME   WHO        LIB   CODE MACRO                             WHAT, WHERE, WHY
---  ----------     ------------  -----------  ---------  ---   -----------     		---------------------------------------
63	Bug #84955      20230720       20230724   Sawyer	  N      QUEC_PATCH_SIM_PINSTATE_84955    将定时180s更新路由表修改为 1024 个存满后，在路由表中从头覆盖旧的路由
62	Bug #44045      20210910       20210927   Gipsy	      N      QUEC_PATCH_NAT_FOEVER_44045      将定时180s更新路由表修改为 1024 个存满后，在路由表中从头覆盖旧的路由
61	Bug#44158(1802) 20210912	   20210913   harold      N      N                                Frequent update of lwip flash problem, flash life risk
60  Bug#39346 		20210714       20210714   Fitz        N      QUEC_SMS_CHARACTER_CONVERT_PATCH_39346 Fix sms receiver lost character.
59	Bug #37259		20210611	   20210630   harold      N      N                                Mod lwip source code problem, tcp_write_checks, Write overflow
58  Bug#31180       20210222       20210602   Fitz        N      QUEC_ME_SMS_SAVE_OPTIMIZE		  Optimize sms saved in ME when no free space in nvm.	
57	Bug #35811		20210528	   20210528   harold      N      N                                Mod lwip source code problem, tcp_receive, assert(pcb->rcv_wnd > tcplen)
56	BUG#32758		20210310	   20210420   evin        N      QUEC_MSTK_SUPPORT                support MSTK function
55   BUG#32240      20210322       20210324   EGAN        N      QUEC_PATCH_BUG_32240             add mpu product when erase or write flash  
54  BUG #31755      20210303       20210305   amos        N      QUEC_PATCH_SHIELD_LOG_BUG_31755  fix flash xip suspend/resume log,influence diag message
53  Bug #30788      20210203       20210208   evin        N      QUEC_PATCH_NAL_ON_SIM_BUG_30788  fix NAL connect the internet,Can not find SIM.
52  Bug#29580		20210114	   20210127   Fitz        N      QUEC_PATCH_1802S_USSD_29580      Fix long ussd issue
51  Bug#29297       20200120       20200121   Chaim       N      QUEC_1603_CFUN0_CURRENT_HIGH_29297   1603 cfun0 current high
50  Bug#26790       20200112       20200114   Chaim       N      QUEC_MULTICAST_FILTER_26790      support ipad send multicast filter
49  Feature #27827  20201216       20201216   Chaim       N      QUEC_1603_PM803_SUPPORT          PM803 SUPPORT
48   Bug#27262      20201215       20201215   Chaim       N      QUEC_1601_PM802_FPWM_ENABLE      打开fpwm,修复未知dump
47   Bug#27432      20201210       20201210   Chaim       Y      N								  repair expand_band need reset valid
46   Bug#25678      20201204       20201204   evin        Y      QUEC_PATCH_BUG_26578             010?虹嚎 STASR1601-2208 姒?????oos涔????ㄥ??dum
45	 Bug#26489       20201203      20201204   Chaim	      N     #define QUEC_3601_PDPDEACT_NETCARD_FAIL_26489  修复反激活后usb 网卡被解绑导致ping不通的问题
44	 Bug#26892      20201202      20201204    Chaim       N     QUEC_3601_SD_DUMP_FAIL_26892        修复010基线无法抓取dump log问题
43	 Bug#26256      20201123	  20201124    Chaim       Y     N									修复sim卡定时器超时不准的问题
42   Bug#17721      20200826      20200914     Chaim      N     QUEC_PATCH_USB_STATE_17721			??clear feature?? ????usb??,??remotewakup????,??????????
41   Bug#20031		20200816	  20200819	  Bryce		  N     QUEC_3601_MUTEX_20031				???????mutex
40   Bug#20001      20200818      20200818    domingo     Y     N                                    30Q?????,cfun 4,1 ????????????,
39   Bug#19161      20200814      20200818    Bryce       Y     QUEC_PATCH_CASE_19161_DUMP  ??quec_rtos_task_create???dump
38   Bug#18717      20200805      20200805    Bryce       N     QUEC_PPP_PATCH_18717_PREFETCH_ABORT  ppp ftp??,??prefetchabort dump
37   Bug#17721      20200805      20200805    Luffy       N     QUEC_PATCH_17721_fix_DIAGEXT_watchdog_dump  usb hang??? watchdog dump
36   Bug#19184      20200803      20200805    Bryce       N     QUEC_PATCH_PRODUCT_19184            ???????????ppp??dump???
35   Bug#19025      20200730      20207030    Chaim       N     USB2_VBUS_DETECT              			?????usb???????
34   Bug17168       20200709      20200717     Chaim      N     QUEC_PATCH_USB_RESUME_FAIL_17168        ????phy clock?resume???????
33   Bug#17241      20200713      20200722    Fitz        N     QUEC_PATCH_1601_FIX_MODEMLWIP_L605_17241 ??PC????dump??
32   16417/13225/15059/15540/15956/16925/16416/16618/16628/16666/16351/14430/15890/17337			  ??028Q??
31   Bug #16581     20200715      20200715     Luffy      N     QUEC_PATCH_1601_USB_POWDOWN_PRO       ??usb???? 
30   Support#16429  20200703      20200617     Egan       N     QUEC_PATCH_1601_AMR_SUPORT_16429      support amr paly
29   Support#13225  20200603      20200701     wayne      N     Y                                     support FTM gsm??
28   Bug#14960      20200527      20200527     Egan       N     Y                                     fixed the function of crc sysfile cause the dump when update 
27   Bug#14266      20200508      20200521     Larson     Y     N                                      ??????LTE???GSM?????dump??
26   Bug#14122      20200506      20200518     Egan       N     N                                     fixed the modem disable open,when comcfg.scv error
25   Bug#13452      20200422      20200520     Brent      Y     N                                     asr give lib but already have,so not update lib.
24   Bug#13759      20200430      20200514     Chaim      N     Y									   ?patch??021q??????
23   Bug13624       20200426      20200508     Harold     Y     N                                      QIDNSGIP????????,getaddrinfo_with_pcid???????
22   Bug#14187      20200508      20200509     Fitz       Y     N                                      ????AT+CPMS=ME,ME,ME??
21   Bug13851       20200426      20200506     Jensen     Y     N                                      camp?????????assert
20   Bug#12808      20200420	  20200426     Harold	  N     QUEC_PATCH_1802S_AUTHREQ_SIZE128_12808 AT*AUTHREQ???????????128??,??18Q????PASS
19   Bug#12808      20200412	  20200415     Harold	  Y     QUEC_PATCH_1802S_AUTHREQ_SIZE128_12808 AT*AUTHREQ???????????128??
18   Bug12738       20200410      20200410     Harold     Y		QUEC_3601_LWIP_FLOW_12738            integrated flow interface function from ASR patch  
17   Bug11210       20200403      20200403     Chaim      N		QUEC_3601_USB_SUSPEND_RESUME_11210     ??suspend/resume  
16   Support12738   20200401      20200401     Jensen     Y     N                                      ??????,mifi/dongle??,??????
15   Bug12651       20200327      20200328     Ramos      N     QUEC_3601_PMIC_PWRKEY_12651            support poweroff by powerkey
14   Bug12138       20200321      20200324     Jensen     Y     QUEC_CP_IMAGE_SIZE_12138               ??????
13 	 Bug#12352      20200324	  20200324     Chaim      N     QUEC_CID_INFO_CFUN0_CLEAR_RESUME_12352 solve cfun0 clear apn context 
12   Bug#12201      20200318	  20200319     Chaim	  N     QUEC_CPOL_MODE_SUPPORT_12201           solve cpol format
11	 Bug#11601      2020/02/27    2020/03/11   Chaim      N     QUEC_3601_RO_RW_HEAP_11601             add ro rw heap show 
10   Feature#11510  2020/02/24    2020/03/04   Jensen     N     QUEC_3601_DUMP_ERRLOG_11510            Add err log bin for dump
9	 Support#11190  2020/02/06	  2020/02/08   Egan       N     N								       add file: open Rd Related codes  
8    Bug#11201      2020/02/08    2020/0208    Chaim	  Y     N									   solve dhcp fail
7    Support#9797   2019/12/06    2019/12/07   Chavis     N     QUEC_3601_FS_SUPPORT_9797              add file sytem API: FDI_Access
6	 Bug#9179	    2019/11/29	  2019/12/03   Ramos	  Y     N                                      SD card support; open Cgpio/Qspi/littlefs/ci*.h code
5	 Bug#9567	    2019/11/30	  2019/11/30   Chaim	  Y     N                                      ppp lwip library bug
4	 Bug#9165	    2019/11/26	  2019/11/27   Jensen	  Y     QUEC_3601_AT_9165                      at echo length protect
3    Bug#9374       2019/11/20    2019/11/23   Ramos      N     QUEC_3601_PMIC_PWRKEY_9374             support powerkey poweronoff
2	 Bug#9181	    2019/11/18	  2019/11/22   Chaim  	  N     QUEC_3601_USB_ECM_SUPPORT_9181         support usb and ecm				
1	 Bug#8838	    2019/11/06	  2019/11/06   Chaim  	  Y     AT_OVER_UART                           support uart1 driver	  	
=============================================================================================================================*/


#ifndef QUEC_CUST_PATCH_H
#define QUEC_CUST_PATCH_H

#ifdef __cplusplus
extern "C" {
#endif

/**************************** platform/bsp/rtos patch**************************/
#define QUEC_3601_DUMP_ERRLOG_11510 1
#define QUEC_3601_RO_RW_HEAP_11601
#define QUEC_1603_PM803_SUPPORT
#define QUEC_PATCH_RTC_38906

//20200819
#define	QUEC_3601_MUTEX_20031
//Ford.zhang 20201102: to fix Timer abnormal by 32K Crystal oscillator
#define QUEC_3601_PATCH_PMIC_24275

#define QUEC_3601_SD_DUMP_FAIL_26892
#define QUEC_1601_PM802_FPWM_ENABLE

//amos.yao add 20210305:fix flash xip suspend/resume log
#define QUEC_PATCH_SHIELD_LOG_BUG_31755
/**************************** AT COMMAND patch*********************************/
#define QUEC_3601_AT_9165 1
#define QUEC_CP_IMAGE_SIZE_12138 1



/******************************** UART patch*********************************/
//luffy.liu add usb patch usb baohu
#define QUEC_PATCH_1601_USB_POWDOWN_PRO



/******************************** USB patch*********************************/
#define QUEC_3601_USB_ECM_SUPPORT_9181

#define QUEC_3601_USB_SUSPEND_RESUME_11210

//Brent.qiu 20200428: net remote wakeup 
#define QUEC_PATCH_1802S_USBNET_REMOTE_WAKEUP_13795
#define QUEC_PATCH_USB_RESUME_FAIL_17168

//0805fix diagext watchdog dump
#define QUEC_PATCH_17721_fix_DIAGEXT_watchdog_dump

//20200818
#define	QUEC_PATCH_CASE_19161_DUMP

#define QUEC_PATCH_USB_STATE_17721
// destin 20201218 
#define QUEC_PATCH_USB_CTRL_EP_27626

/* destin fix ecm netif up free failed dump */
#define QUEC_ECM_PATCH_26586

#define QUEC_MULTICAST_FILTER_26790
#define QUEC_NETCARD_DTD_CHECK_36902

/******************************** PPP patch*********************************/

#define	QUEC_PPP_PATCH_18717_PREFETCH_ABORT	//20200811


//20200805
#define QUEC_PATCH_PRODUCT_19184

#define QUEC_PATCH_BUG_26578
#define QUEC_PATCH_BUG_32240

/***************************** POWER_MANAGER patch******************************/

#define QUEC_3601_PMIC_PWRKEY_9374

#define QUEC_3601_PMIC_PWRKEY_12651

#define QUEC_1603_CFUN0_CURRENT_HIGH_29297

/******************************** NETWORK patch*********************************/

#define QUEC_CPOL_MODE_SUPPORT_12201
#define QUEC_CID_INFO_CFUN0_CLEAR_RESUME_12352

#define QUEC_PATCH_3601_FTM_GSM_SUPPORT_13225  //add by wayne 2020.07.01
#define QUEC_PATCH_3601_WIFISCAN_BUG_18654  //add by ford 2020.08.03

//ford.zhang @2020.0918 fix ipv6 Time Exceeded Before Last Fragments Arrive fail of 20423
#define QUEC_PATCH_1802S_UG89_TIME_EXCEED_20423

#define QUEC_PSM_CHANGE_IDENTIFY_40970

//ford.zhang@20221206 add for refusing plmn access the network
//Sharon.li@20230823 Cancel
//#define QUEC_PATCH_1803S_FPLMN_66302

/******************** SMS/PHB/CALL/STK/BIP/USSD/(U)SIM patch********************/

/*
Fitz.xu 20200324: merge from 1802S

Aaron.Li 2019.03.15
ADD ASR_PATCH FORMAT
QUEC_PATCH_1802S_FEATURE_PATCHNUM
function:
1.Unable NO CARRIER and RING escalation related issues patch
*/
#define QUEC_PATCH_1802S_CALL_BUG_3170

/*
Fitz.xu 2020.05.16
ADD ASR_PATCH FORMAT
QUEC_PATCH_1802S_FEATURE_PATCHNUM
function:
1. fix AT+CMGL=0 consume too much time when storage is ME
*/
#define QUEC_PATCCH_1802S_ADD_OPT_CMGL_MSG_ON_ME_13380  (1)

//Fitz.xu 20200721: To fix PC ppp dump 
#define QUEC_PATCH_1601_FIX_MODEMLWIP_L605_17241  (1)

/*Fitz.xu 20210115: Fix long ussd issue */
#define QUEC_PATCH_1802S_USSD_29580 (1)

//evin.zhu 20210208 :fix NAL connect the internet,Can not find SIM.
#define QUEC_PATCH_NAL_ON_SIM_BUG_30788

//evin.zhu 20210414 support MSTK
#define QUEC_MSTK_SUPPORT

//Fitz.xu 20210602: Optimize sms saved in ME when no free space in nvm.
#define QUEC_ME_SMS_SAVE_OPTIMIZE  (1)

//Gipsy.gao  20211021 添加路由表的更新机制
#define QUEC_PATCH_NAT_FOEVER_44045

//Fitz.xu 20210715: Fix sms receiver lost character.
#define QUEC_SMS_CHARACTER_CONVERT_PATCH_39346  (1)

//Fitz.xu 20211021: To config ims cid
#define QUEC_SET_IMS_CID_PATCH_45607  (1)

//Sawyer.he 20230724: 84955 libDisplayPinState_handling
#define QUEC_PATCH_SIM_PINSTATE_84955
/******************************** TCPIP patch*********************************/
#define QUEC_3601_LWIP_FLOW_12738 //harold.wang@2020.04.10: integrated flow interface function from ASR patch
#define QUEC_PATCH_1802S_AUTHREQ_SIZE128_12808 //harold.wang 20200407 modified AT*AUTHREQ configuration user name password support up to 128 bytes
#define QUEC_3601_PDPDEACT_NETCARD_FAIL_26489
/******************************** FS patch*********************************/
#define QUEC_3601_FS_SUPPORT_9797

/******************************** AUDIO PATCH *****************************/
#define QUEC_PATCH_1601_AMR_SUPORT_16429 1


#ifdef __cplusplus
} /*"C" */ 
#endif

#endif

