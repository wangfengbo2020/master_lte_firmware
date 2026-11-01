/**  @file
  quec_at_common.h

  @brief
  This file is used to define the common definition of AT for different Quectel Project.

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
11/09/2018        Jensen     Init version
=================================================================*/


#ifndef _QUEC_AT_COMMON_H
#define _QUEC_AT_COMMON_H

/*> include header files here*/

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "teldef.h"

#include "quec_cust_feature.h"

#ifdef __cplusplus
extern "C" {
#endif


/*========================================================================
 *  Type Definition
 *========================================================================*/


/*========================================================================
 *  Enumeration Definition
 *========================================================================*/
 

/*========================================================================
 *  Macro Definition
 *========================================================================*/



#define QCFG_MAX_TEST_CMD_LEN 100
/*20210306 reduce QIACT(CGACT) exec time, also modify the default timeout time of all AT cmd*/
#define QUEC_MAX_AT_ASYNC_TIME 150 //second

#define QUEC_PDP_CONTEX_INDEX_MAX 16   //Chaim 20200529  follow 1802s max pdp context num


/*AT CHANNEL DEFINE----start */
#define QUEC_USBMODEM_CHANNEL   AT_MODEM_CHANNLE   //Chaim 20191107 usb modem corresponding atpindex

#define QUEC_UART1_CHANNEL  	TEL_AT_CMD_ATP_UART    //Chaim 20191107 main uart corresponding atpindex
#define QUEC_CMUX_CHANNEL_0		TEL_AT_CMD_ATP_30
#define QUEC_CMUX_CHANNEL_1		TEL_AT_CMD_ATP_31
#define QUEC_CMUX_CHANNEL_2		TEL_AT_CMD_ATP_32
#define QUEC_CMUX_CHANNEL_3		TEL_AT_CMD_ATP_33
#define QUEC_CMUX_CHANNEL_4		TEL_AT_CMD_ATP_34
#define QUEC_CMUX_CHANNEL_5		TEL_AT_CMD_ATP_35


#if QUEC_DUAL_SIM_SUPPORT
extern BOOL isMasterSim0(void);
extern UINT32 quec_get_modem_atp(void);
#define TEL_AT_CMD_ATP_APPTCPIP     (isMasterSim0() ? (TEL_AT_CMD_ATP_21) : (TEL_AT_CMD_ATP_21 + QUEC_ATP_OFFSET_36))
#define TEL_AT_CMD_ATP_APPTCPIP_SIM1	(TEL_AT_CMD_ATP_21)
#define TEL_AT_CMD_ATP_APPTCPIP_SIM2	(TEL_AT_CMD_ATP_21 + QUEC_ATP_OFFSET_36)
#else
#define TEL_AT_CMD_ATP_APPTCPIP  TEL_AT_CMD_ATP_21
#endif

#ifdef QUEC_PPP_INTERNAL_CHANNEL_HANDLE_AT_RESP
#if QUEC_DUAL_SIM_SUPPORT
#ifndef MIN_SYS
#define TEL_AT_CMD_ATP_PPP_INTERNAL  quec_get_modem_atp()
#else
#define TEL_AT_CMD_ATP_PPP_INTERNAL  TEL_AT_CMD_ATP_22
#endif
#else
#define TEL_AT_CMD_ATP_PPP_INTERNAL  TEL_AT_CMD_ATP_22
#endif
#define TEL_AT_CMD_ATP_PPP_INTERNAL_SIM1	(TEL_AT_CMD_ATP_22)
#define TEL_AT_CMD_ATP_PPP_INTERNAL_SIM2	(TEL_AT_CMD_ATP_22 + QUEC_ATP_OFFSET_36)
#endif

#ifdef EXT_AT_MODEM_SUPPORT
#define QUEC_USBAT_CHANNEL      EXT_AT_MODEM_CHANNLE  //Chaim 20191108 for same with 1802s
#else
#define QUEC_USBAT_CHANNEL      (TEL_AT_CMD_ATP_20)  //Chaim 20191108 for same with 1802s
#endif
    
#define TEL_AT_CMD_ATP_UART2  	TEL_AT_CMD_ATP_19
#define QUEC_UART2_CHANNEL		TEL_AT_CMD_ATP_UART2 //Chaim 20191113 invalid value,for compile


#ifdef QUEC_MINISYS_PROJECT_CUST
#define MINI_AT_CMD_ATP_QUEC_INTERNAL  TEL_AT_CMD_ATP_14//mini sys internal atp channel for quectel to send at cmd 20201208
#endif

#ifdef QUECTEL_AT_COMMAND_INTERNAL
	#if QUEC_DUAL_SIM_SUPPORT
		#define TEL_AT_CMD_ATP_QUEC_INTERNAL  		(isMasterSim0() ? (TEL_AT_CMD_ATP_18) : (TEL_AT_CMD_ATP_18 + QUEC_ATP_OFFSET_36))
	#else
		#define TEL_AT_CMD_ATP_QUEC_INTERNAL  TEL_AT_CMD_ATP_18//internal atp channel for quectel to send at cmd
	#endif
#define TEL_AT_CMD_ATP_QUEC_INTERNAL_SIM1	(TEL_AT_CMD_ATP_18)
#define TEL_AT_CMD_ATP_QUEC_INTERNAL_SIM2	(TEL_AT_CMD_ATP_18 + QUEC_ATP_OFFSET_36)
#endif

#if defined (QUEC_BLACK_CELL_SUPPORT) || defined(QUEC_THIN_BLACK_CELL_SUPPORT)
#define TEL_AT_CMD_ATP_BLACKCELL	(TEL_AT_CMD_ATP_3)
#endif

#if QUEC_DUAL_SIM_SUPPORT
#define QUEC_USBMODEM_CHANNEL_SIM2			(QUEC_USBMODEM_CHANNEL + QUEC_ATP_OFFSET_36)   
#define QUEC_UART1_CHANNEL_SIM2				(QUEC_UART1_CHANNEL + QUEC_ATP_OFFSET_36)    
#define QUEC_CMUX_CHANNEL_0_SIM2			(QUEC_CMUX_CHANNEL_0 + QUEC_ATP_OFFSET_36)	
#define QUEC_CMUX_CHANNEL_1_SIM2			(QUEC_CMUX_CHANNEL_1 + QUEC_ATP_OFFSET_36)
#define QUEC_CMUX_CHANNEL_2_SIM2			(QUEC_CMUX_CHANNEL_2 + QUEC_ATP_OFFSET_36)
#define QUEC_CMUX_CHANNEL_3_SIM2			(QUEC_CMUX_CHANNEL_3 + QUEC_ATP_OFFSET_36)
#define QUEC_CMUX_CHANNEL_4_SIM2			(QUEC_CMUX_CHANNEL_4 + QUEC_ATP_OFFSET_36)
#define QUEC_CMUX_CHANNEL_5_SIM2			(QUEC_CMUX_CHANNEL_5 + QUEC_ATP_OFFSET_36)
#define TEL_AT_CMD_ATP_PPP_INTERNAL_SIM2	(TEL_AT_CMD_ATP_22 + QUEC_ATP_OFFSET_36)
#define QUEC_USBAT_CHANNEL_SIM2      		(QUEC_USBAT_CHANNEL + QUEC_ATP_OFFSET_36)
#define QUEC_UART2_CHANNEL_SIM2  			(QUEC_UART2_CHANNEL + QUEC_ATP_OFFSET_36)
#define TEL_AT_CMD_ATP_APPTCPIP_SIM2		(TEL_AT_CMD_ATP_21 + QUEC_ATP_OFFSET_36)
#define MINI_AT_CMD_ATP_QUEC_INTERNAL_SIM2	(MINI_AT_CMD_ATP_QUEC_INTERNAL + QUEC_ATP_OFFSET_36)
#endif


#ifdef QUECTEL_OPEN_CPU
//Sharon.li@20220407 为QuecOpen APP 增加两个通道，用于发送AT
//For SIM1
#define AT_CMD_CHANNEL (TEL_AT_CMD_ATP_28)
//For SIM2
#define AT_CMD_CHANNEL_1 (TEL_AT_CMD_ATP_28+QUEC_ATP_OFFSET_36)
//用于open项目，异步AT发送通道ql_atcmd_send_async
#define AT_CMD_CHANNEL2 TEL_AT_CMD_ATP_29
#endif

/*AT CHANNEL DEFINE----end*/

#if QUEC_DUAL_SIM_SUPPORT
#define QUEC_IS_UART1_CMUX_ATP(ATP) 	((QUEC_UART1_CHANNEL == (ATP)) || \
										((QUEC_CMUX_CHANNEL_0 <= (ATP)) && ((ATP) <= QUEC_CMUX_CHANNEL_5 )) || \
										((QUEC_UART1_CHANNEL + QUEC_ATP_OFFSET_36) == (ATP)) || \
										(((QUEC_CMUX_CHANNEL_0 + QUEC_ATP_OFFSET_36) <= (ATP)) && ((ATP) <= (QUEC_CMUX_CHANNEL_5 + QUEC_ATP_OFFSET_36))))
#else
#define QUEC_IS_UART1_CMUX_ATP(ATP) 	((QUEC_UART1_CHANNEL == (ATP)) || \
										((QUEC_CMUX_CHANNEL_0 <= (ATP))&&((ATP) <= QUEC_CMUX_CHANNEL_5 )))
#endif

#ifdef QUEC_UART2_ENABLE
	#ifdef QUEC_TTYUSB3_ENABLE //pax 定制
		#if QUEC_DUAL_SIM_SUPPORT
			#define QUEC_IS_VALID_ATP(ATP) 	((QUEC_USBMODEM_CHANNEL == (ATP)) || \
									(TEL_AT_CMD_ATP_TTYUSB3 == (ATP)) || \
									(QUEC_USBAT_CHANNEL == (ATP)) || \
									(TEL_AT_CMD_ATP_UART2 == (ATP)) || QUEC_IS_UART1_CMUX_ATP(ATP) || \
									(QUEC_USBMODEM_CHANNEL + QUEC_ATP_OFFSET_36 == (ATP)) || \
									(TEL_AT_CMD_ATP_TTYUSB3 + QUEC_ATP_OFFSET_36 == (ATP)) || \
									(QUEC_USBAT_CHANNEL + QUEC_ATP_OFFSET_36 == (ATP))|| \
									(TEL_AT_CMD_ATP_UART2 + QUEC_ATP_OFFSET_36 == (ATP)))
		#else
			#define QUEC_IS_VALID_ATP(ATP) 	((QUEC_USBMODEM_CHANNEL == (ATP)) || \
									(TEL_AT_CMD_ATP_TTYUSB3 == (ATP)) || \
									(QUEC_USBAT_CHANNEL == (ATP)) || \
									(TEL_AT_CMD_ATP_UART2 == (ATP)) || QUEC_IS_UART1_CMUX_ATP(ATP))
		#endif
	#else
		#if QUEC_DUAL_SIM_SUPPORT
				#define QUEC_IS_VALID_ATP(ATP)	((QUEC_USBMODEM_CHANNEL == (ATP)) || \
									(QUEC_USBAT_CHANNEL == (ATP)) || \
									(TEL_AT_CMD_ATP_UART2 == (ATP)) ||QUEC_IS_UART1_CMUX_ATP(ATP) || \
									(QUEC_USBMODEM_CHANNEL + 36 == (ATP)) || \
									(QUEC_USBAT_CHANNEL + 36 == (ATP))|| \
									(TEL_AT_CMD_ATP_UART2 + 36 == (ATP)))
		#else
			#define QUEC_IS_VALID_ATP(ATP) 	((QUEC_USBMODEM_CHANNEL == (ATP)) || \
									(QUEC_USBAT_CHANNEL == (ATP))|| \
									(TEL_AT_CMD_ATP_UART2 == (ATP)) || QUEC_IS_UART1_CMUX_ATP(ATP))
		#endif
	#endif
#else
#ifdef QUEC_TTYUSB3_ENABLE
#if QUEC_DUAL_SIM_SUPPORT
#define QUEC_IS_VALID_ATP(ATP) 	((QUEC_USBMODEM_CHANNEL == (ATP)) || \
								(TEL_AT_CMD_ATP_TTYUSB3 == (ATP))|| \
								(QUEC_USBAT_CHANNEL == (ATP)) ||\
								(QUEC_USBMODEM_CHANNEL+36 == (ATP)) || \
								(TEL_AT_CMD_ATP_TTYUSB3+36 == (ATP))|| \
								(QUEC_USBAT_CHANNEL+36 == (ATP)))
#else
#define QUEC_IS_VALID_ATP(ATP) 	((QUEC_USBMODEM_CHANNEL == (ATP)) || \
								(TEL_AT_CMD_ATP_TTYUSB3 == (ATP)) || \
								(QUEC_USBAT_CHANNEL == (ATP)))
#endif
#else
#if QUEC_DUAL_SIM_SUPPORT
    #ifdef QUECTEL_OPEN_CPU //Open 新增两个ATP，用QuecOpen APP 发送AT
        #define QUEC_IS_VALID_ATP(ATP)  ((QUEC_USBMODEM_CHANNEL == (ATP)) || \
                                (QUEC_USBAT_CHANNEL == (ATP)) || \
                                (QUEC_IS_UART1_CMUX_ATP(ATP)) || \
                                (QUEC_USBMODEM_CHANNEL + 36 == (ATP)) || \
                                (QUEC_USBAT_CHANNEL + 36 == (ATP))|| \
                                (AT_CMD_CHANNEL  == (ATP))||\
                                (AT_CMD_CHANNEL_1  == (ATP))||\
                                (AT_CMD_CHANNEL2  == (ATP)))
                                
        #define QUEC_IS_APP_ATP(ATP) ((AT_CMD_CHANNEL  == (ATP))||\
                                (AT_CMD_CHANNEL_1  == (ATP))||\
                                (AT_CMD_CHANNEL2  == (ATP)))
    #else
        #define QUEC_IS_VALID_ATP(ATP) 	((QUEC_USBMODEM_CHANNEL == (ATP)) || \
    								(QUEC_UART1_CHANNEL == (ATP)) || \
    								(QUEC_USBAT_CHANNEL == (ATP)) || \
    								(QUEC_USBMODEM_CHANNEL+36 == (ATP)) || \
    								(QUEC_UART1_CHANNEL+36 == (ATP)) || \
    								(QUEC_USBAT_CHANNEL+36 == (ATP)))
    #endif
#else
#define QUEC_IS_VALID_ATP(ATP) 	((QUEC_USBMODEM_CHANNEL == (ATP)) || \
								(QUEC_UART1_CHANNEL == (ATP)) || \
								(QUEC_USBAT_CHANNEL == (ATP)))
#endif
#endif
#endif


#ifdef QUEC_MINISYS_PROJECT_CUST
#define MINI_AT_CMD_ATP_QUEC_INTERNAL  TEL_AT_CMD_ATP_14//mini sys internal atp channel for quectel to send at cmd 20201208
#endif


UINT8 quec_get_at_param_num(const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters);

#ifdef __cplusplus
} /*"C" */
#endif

#endif





