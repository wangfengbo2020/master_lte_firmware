/**
 ******************************************************************************
 * @file    quec_uart.h
 * @author  Chavis.Chen
 * @version V1.0.0
 * @date    26-Sep-2018
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

/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/*=================================================================

						EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN			  WHO		  WHAT, WHERE, WHY
------------	 -------	 -------------------------------------------------------------------------------
10/15/2018		  Chaim	     Init version
=================================================================*/

#ifndef _QUEC_UART_AT_H
#define _QUEC_UART_AT_H

#include "teldef.h"
#include "UART.h"
#include "quec_cust_feature.h"  
#include "quec_common.h"
#include "quec_driver_common.h"
#include "quec_atcmd_general.h"
/*unkonw reason must include this .h file in this file
can not use quec_include.h file contain this .h file
*/
 

#ifdef __cplusplus
extern "C" {
#endif


//chaim 2018.10.24 sio log enable
#define QUEC_UART_LOG_ENABLE

typedef union
{
    char *filename;
    __QUEC_CONFIG_ENUM config_num;
}quec_baudrate_info_u;

typedef enum 
{
    QUEC_BAUD_FROM_FAT = 0,
    QUEC_BAUD_CURRENT_CONFIG   //from at&v
}quec_baud_src_e;

typedef struct
{
    quec_baud_src_e baud_src;
    quec_baudrate_info_u info;  
}quec_baud_info_s;

typedef struct
{
    TelAtParserID atp_index;
    OSATimerRef timer_ref;
    void (*timerout_handler)(void);
   // char *filename;
    quec_baud_info_s baud_info;
    UART_BaudRates current_baudrate;
    UART_BaudRates set_baudrate;
    bool baud_selfadapt_state;    //true--current is self adaption state,false---not in self adaption,use for at+ipr?
}quec_ipr_set_s;

typedef struct
{
    TelAtParserID atp_index;
    UART_BaudRates baudrate;
}quec_ipr_msg_s;

typedef enum 
{
    QUEC_BAUD_SELF_ADAPTION_FALSE =0,
    QUEC_BAUD_SELF_ADAPTION_TRUE
}quec_baudration_self_adaption_flag_e;
    
//chaim 2018.11.24
typedef struct
{
    uint8 rts_control;
    uint8 cts_control;
}quec_ifc_value_s;    

extern quec_baudration_self_adaption_flag_e g_quec_baud_self_adaption;
extern quec_ifc_value_s g_uart_ifc_value;
extern quec_ifc_value_s g_uart_temp_ifc_value;


typedef enum 
{
    QUEC_CMUX_LOG_NONE =0,
    QUEC_CMUX_LOG_NORMAL,
    QUEC_CMUX_LOG_FRAME,    

    QUEC_CMUX_LOG_MAX
}quec_cmux_log_level_e;

extern QuecOSStatus quec_uart_init(TelAtParserID atp_index);


extern QuecOSStatus quec_uart1_ioctl(TelAtParserID atp_index, quec_ioctl_cmd_type_e cmd, quec_ioctl_param *param);

extern QuecOSStatus quec_uart_ipr_timer_start(TelAtParserID atp_index);

extern QuecOSStatus quec_uart_get_current_baudrate(TelAtParserID atp_index, UART_BaudRates *baudrate);
extern QuecOSStatus quec_uart_reset_baudrate(TelAtParserID atp_index,UART_BaudRates baudrate);

extern QuecOSStatus quec_uart1_send(TelAtParserID atp_index,uint8 *data,uint32 len);

extern QuecOSStatus quec_uart1_open_cts_interrupt(void);
extern QuecOSStatus quec_uart1_close_cts_interrupt(void);

extern  QuecOSStatus quec_uart_ipr_set_baudrate(TelAtParserID atp_index, UART_BaudRates baudrate);
extern QuecOSStatus quec_uart_set_cmux_log(uint8 log);
extern BOOL quec_uart_get_cmux_log(void);
extern QuecOSStatus quec_set_uart_selfadapt(UART_BaudRates baudRate);
extern UART_BaudRates quec_get_uart_selfadapt(void);
extern QuecOSStatus quec_uart2_mode_change_timer_start(uint32 diagport);
extern QuecOSStatus quec_uart1_ifc_msg_process(void);
extern QuecOSStatus quec_uart1_ifc_timer_start(void);
extern void quec_read_uart2_baudrate_to_sdk(void);
//chaim 2018.12.12 QDIAGPORT value
#define QUEC_QDIAGPORT_CMD_VAL_MIN        0
#define QUEC_QDIAGPORT_CMD_VAL_MAX        1
#define QUEC_QDIAGPORT_CMD_VAL_DEFAULT    0


#define    UART_BAUD_SELF_ADAPTION_0    0


#ifdef QUEC_UART2_ENABLE

extern QuecOSStatus quec_uart2_init(void);
extern QuecOSStatus quec_uart2_ioctl(TelAtParserID atp_index, quec_ioctl_cmd_type_e cmd, quec_ioctl_param *param);
extern QuecOSStatus quec_uart2_send(TelAtParserID atp_index, uint8 *data, uint32 len);
extern quec_uart2_mode_e  quec_uart2_get_mode(void);
#endif

#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)

typedef enum 
{
    QUEC_FIBO_DCD_DELAY_MIN =10,
    QUEC_FIBO_DCD_DELAY_DEFAULT =60,
    QUEC_FIBO_DCD_DELAY_MAX =10000,
}quec_fibo_dcd_delay_e;

typedef enum 
{
    QUEC_FIBO_GPRSREACT_MIN =0,
    QUEC_FIBO_GPRSREACT_DEFAULT =1,
    QUEC_FIBO_GPRSREACT_MAX =1,
}quec_fibo_gprsreact_e;
extern uint8 quec_fibo_get_gprsreact_value(void);

extern uint8 quec_fibo_get_atk_value(void);
extern QuecOSStatus quec_fibo_atcmd_set_atk_value(TelAtParserID atp_index, uint8 atk_value);

extern uint16 quec_fibo_get_dcd_value(void);
extern QuecOSStatus quec_fibo_set_dcd_value(uint16 dcd_delay);
//extern QuecOSStatus quec_fibo_dcd_delay_timer_start(quec_pin_level_value_e level);
extern QuecOSStatus quec_fibo_dcd_delay_timer_stop(void);


extern uint8 quec_fibo_get_lpmmode_value(void);

extern void quec_fibo_set_lpmmode_value(uint8 lpmmode);
#endif

#if  QUEC_HALF_HARDWARE_FLOWERCTRL
extern QuecOSStatus quec_cts_hardware_init(void);
extern QuecOSStatus quec_cts_rts_hardware_init(void);
void quec_uart_cts_rts_pin_init(quec_ifc_value_s *ifc_value);
extern bool quec_get_uart_hardware_rts_flag_value(void);
extern void quec_set_uart_hardware_rts_flag_value(bool status);
#endif

QuecOSStatus quec_get_uart_ipr_pointer(TelAtParserID atp_index, quec_ipr_set_s **pipr_set);
QuecOSStatus quec_uart_check_baudrate(uint32 baudrate);
QuecOSStatus quec_uart_selfadatpt_baudrate_set_back(TelAtParserID atp_index);

#ifdef __cplusplus
} /*"C" */
#endif

#endif

