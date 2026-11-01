/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/**
 ******************************************************************************
 * @file    quec_msg_process.h
 * @author  Chaim.Qian
 * @version V1.0.0
 * @date    25-Oct-2018
 * @brief   This file contains the common definitions, macros and functions to
 *          be shared throughout the project.
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
10/25/2018		  Chaim	     Init version
=================================================================*/

#include "quec_cust_feature.h"
#include "quec_common.h"
#include "teldef.h"
#include "quec_driver_common.h"

#ifndef __QUEC_THREAD_MSG_H_
#define __QUEC_THREAD_MSG_H_

//chaim 2018.10.24 msg process log enable
#define QUEC_MSG_PROCESS_LOG_ENABLE



//msg magic num to avoid unknow source
#define QUEC_MSG_MAGIC_NUM  0x5a6a7a8a
#define QUEC_MSG_LEN_NONE   0

typedef enum
{
    QUEC_NONE_MSG=-1,
    QUEC_ORIGIN_ASR_DATA_MSG=0,
    QUEC_DTR_CHANGE_MSG,
    QUEC_CTS_CHANGE_MSG,
    QUEC_DCD_FUNC_MSG,  //at&c[value] notify modem_route task
    QUEC_PPP_ESCAPE_MSG,   //ppp terminal msg
    QUEC_PPP_CHAP_TIMEOUT_MSG,

    QUEC_IPR_SET_MSG,   //AT+IPR TIMER_OUT msg

    QUEC_USIM_PRESENCE_MSG,  //7

#ifdef QUECTEL_NETWORK_SUPPORT
	QUEC_QGDCNT_AUTOSAVE_MSG,
  #ifdef QUECTEL_AT_QCFG_ACQDB_OPT_SUPPORT
	QUEC_AUTO_UPDATE_EARFCN_MSG,
  #endif	
#endif

#ifdef QUEC_AIR_PLANE_CTRL_ENABLE
    QUEC_AIR_PLANE_CTRL_MSG,         
#endif

    QUEC_DATATRANSFORM_POLLING_MSG,
    QUEC_PPP_EXIT_DATA_TO_CMD_MSG,
    QUEC_ESCAPE_SEQUENCE_TO_CMD_MSG,  //Chaim 2019.06.23 receive +++ temporary form data to cmd state
    QUEC_UART2_MODE_CHANG_MSG,
    QUEC_UART1_IFC_TIMEROUT_MSG,
    QUEC_USB_IFC_TIMEROUT_MSG,
    #if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
    QUEC_FIBO_DCD_DELAY_MSG,
    #endif
	QUEC_USB_DEBUG_LOG_OUT,  //Chaim 20191202,read ram log
#if defined QUECTEL_JAMDET_FEATURE
	QUEC_JAM_DET_PERIOD_MSG, //Isaac 20200416 jamming detection
#endif
#ifdef QUEC_QSCLKEX_ENABLE
	//QUEC_QSCLKEX_CLEAR_FEATURE,
	QUEC_QSCLKEX_CLEAR_PUNISHTIME,
#endif

#ifdef QUEC_USB_QWIFISCAN_SUPPORT
	QUEC_WIFISCAN_MSG,	//Brent 20200628
#endif
//Fitz.xu 20201028: set AT+CNMI after cfun 0/1
#if QUEC_SMS_CNMI_OPTIMIZE
    QUEC_SMS_SET_CNMI,
#endif
#if QUEC_CALL_OPTIMIZE_CLIP_COLP
    QUEC_SMS_SET_CLIP_COLP,
#endif

#if QUEC_CALL_IMS_AUTO_ANSWER_OPTIMIZE
    QUEC_CALL_IMS_AUTO_ANSWER_OPTIMIZE_MSG,
#endif
   QUEC_3601_SOFT_RESET,
#if defined(__QUEC_OEM_VER_LT__)
    QUEC_AVGRSSI_PROCESS_MSG,
#endif
#ifdef QUEC_CUSTOM_LAST_GASP_FEATURE
	QUEC_LAST_GASP_TIRGGER_MSG,		 
#endif
#ifdef QUEC_CDMA_IMSI_SUPPORT
    QUEC_CDMA_IMSI_MSG,
#endif
#ifdef QUEC_USB_QWIFISCAN_SUPPORT
    QUEC_WIFISCAN_TRAFFIC_STATICS_MSG,
#endif
#if defined(QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
    QUEC_GWL_BLACKCELL_PROCESS_MSG,
#endif
//Fitz.xu 20220105: To report +CFUN status when power on
#if QUEC_DUAL_SIM_SUPPORT
	QUEC_REPORT_CFUN_STATUS_MSG,
	QUEC_DUAL_SET_DEFAULT_APN_MSG,
#endif
        //Fitz.xu 20210426:
#if QUEC_SMS_SEND_ARROW_OPTIMIZE
        QUEC_SMS_SEND_ARROW,
#endif
#ifdef QUEC_BLACK_CELL_SUPPORT
	QUEC_ELECTRIC_FENCE_EVENT_MSG,
	QUEC_ELECTRIC_FENCE_PREVENT_MSG,
	QUEC_ELECTRIC_FENCE_BLACKLWIP_MSG,
#endif
#if QUEC_IMS_XML_SUPPORT
    QUEC_IMSXML_UPDATE_JUDGE_MSG,
#endif
#ifdef QUEC_AUTOAPN_ADJUST_SUPPORT
	QUEC_AUTO_APN_EVENT_MSG,
#endif
#ifdef QUEC_NETDUALCH_CFG
	QUEC_NETDUALCH_NETIF_CONFIG_MSG,
#endif
    MSG_IND_MAX
}quec_msg_control_type_e;

typedef struct
{
    int magic_num;
    quec_msg_control_type_e msg_type;
    int reserve;   						//add this int tye, the sizeof of this struct shoud equal with modem_msg_t
    char *param;
}quec_package_msg_s;


typedef struct
{
    TelAtParserID atp_index;
    quec_pin_level_value_e level;
}quec_msg_io_conf_value_s;


extern QuecOSStatus  quec_send_dtr_change_msg(quec_msg_io_conf_value_s *pdtr_change);
extern QuecOSStatus  quec_send_dcd_func_msg(quec_msg_io_conf_value_s *pdcd_func);
extern QuecOSStatus quec_send_msg_to_handle_task(quec_msg_control_type_e msg_type,char *pdata,uint32 len);
extern QuecOSStatus quec_msg_handle_task_init(void);

typedef struct
{
	quec_msg_control_type_e type;
	uint8 data_len;
	uint8 *pdata;  				//msg_handle task process actual data
}quec_msg_process_s;

void quec_clear_esc_count(void);

#if defined(QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
void quec_gwl_blackcell_msg_handle(quec_msg_process_s *pGWLCell);

#endif

#endif



