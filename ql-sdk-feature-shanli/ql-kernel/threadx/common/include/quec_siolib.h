/**
 ******************************************************************************
 * @file    quec_siolib.h
 * @author  Chaim.Qian
 * @version V1.0.0
 * @date    26-Oct-2018
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

#ifndef _QUEC_SIOLIB_H_
#define _QUEC_SIOLIB_H_

#include "quec_include.h"
#include "quec_sio.h"


//chaim 2018.10.24 siolib log enable
#define QUEC_SIOLIB_LOG_ENABLE
typedef enum{
	QUEC_SIOLIB_PORT_FOR_MIN = 0,
	QUEC_SIOLIB_PORT_FOR_TCPIP,
	#ifdef QUEC_FTP_SUPPORT
	QUEC_SIOLIB_PORT_FOR_FTP,
	#endif
	QUEC_SIOLIB_PORT_FOR_HTTP,
	QUEC_SIOLIB_PORT_FOR_FILE,
#ifdef QUECTEL_MQTT_TRANSPARENT
    QUEC_SIOLIB_PORT_FOR_MQTT,
#endif
#ifdef QUEC_AT_GPS_ENABLE
	QUEC_SIOLIB_PORT_FOR_GPS,
#endif
	QUEC_SIOLIB_PORT_FOR_MAX
}quec_siolib_port_owner;


typedef struct{
	 void (*dtr_change_handler)(TelAtParserID atp_index);
	 void (*at_escape_sequence_handler)(TelAtParserID atp_index);
	 UINT32 (*receive_handler)(TelAtParserID atp_index, void *data_ptr, UINT32  data_len);
	 uint8 (*ato_func)(UINT32 atHandle);
}quec_siolib_func_tbl;

typedef struct{
	TelAtParserID           atp_index;
	quec_atp_modem_state_e  atp_mode;
	uint8                   atp_owner;
	quec_siolib_func_tbl   *atp_fun_tbl;
}quec_siolib_state;



    
    //chaim 2018.11.24 at+ifc value
#define QUEC_AT_IFC_CMD_VAL_MIN						0
#if  QUEC_HALF_HARDWARE_FLOWERCTRL
#define QUEC_AT_IFC_CMD_VAL_SOF						1  //Egan 2020.09.03 hard and soft flowerctrl 
#endif
#define QUEC_AT_IFC_CMD_VAL_MAX						2
#define QUEC_AT_IFC_CMD_VAL_DEFAULT					0

extern uint8 quec_siolib_port_is_in_raw_data_mode(TelAtParserID atp_index);

extern uint8 quec_siolib_port_enter_raw_mode(TelAtParserID atp_index, uint8 atp_owner, quec_siolib_func_tbl *fun_tbl);

extern uint8 quec_siolib_port_exit_raw_mode(TelAtParserID atp_index, uint8 allow_ato);

extern void quec_siolib_port_process_rx_msg(TelAtParserID atp_index, void *data_ptr, UINT32 data_len);

extern void quec_siolib_port_process_escape_msg(TelAtParserID atp_index);

extern void quec_siolib_port_process_dtr_change_msg(TelAtParserID atp_index);

extern uint8 quec_siolib_port_process_ato_msg(UINT32 atHandle);

extern QuecOSStatus quec_get_ifc_value(TelAtParserID atp_index, quec_ifc_value_s *ifc_value);
extern QuecOSStatus quec_set_majoruart_ifc_value(TelAtParserID atp_index, quec_ifc_value_s ifc_value);
/*-----------------------------------------------------------------------------------------
 * Function: Serial input/output device init,contain part of uart and usb device.
 *
 * Parameter:
 *    NULL
 *
 * Return:
 *    NULL:
-----------------------------------------------------------------------------------------*/
extern void quec_siolib_init(void);



/*-----------------------------------------------------------------------------------------
 * Function: Serial input/output device set dcd when receive at&d[value] cmd.
 *
 * Parameter:
 *    <value>: 	[IN] the same with receive at&d[value].
 *
 * Return:
 *    QUEC_SUCCESS: receive value is 0 or 1 or 2.
 *    kGeneralErr:	other value received.
 *
-----------------------------------------------------------------------------------------*/
extern QuecOSStatus quec_siolib_set_dtr_response_mode(uint8 value);


/*-----------------------------------------------------------------------------------------
 * Function: Serial input/output device set dcd level.
 *
 * Parameter:
 *    <atp_index>: 	[IN] 	the at cmd channel index.
 *    <level>:	    [IN]	the value is 0 or 1.
 *
 * Return:
 *    QUEC_SUCCESS: set the corresponding of atp_index dcd ok .
 *    kGeneralErr:	fail to set the corresponding of atp_index dcd value.
 *
 * Note:
 *    1. the result condition of this functiong execulate according to the value of cmd at&c[VALUE] contain.
 *    2. if the VALUE is 0,the dcd is always high and you can not set this value low
 *    3. if the VALUE is 1,you can only when go to pass-through state,
 *       set dcd high and leave this state let dcd low.
-----------------------------------------------------------------------------------------*/
extern QuecOSStatus quec_siolib_set_dcd_level(TelAtParserID atp_index,quec_pin_level_value_e level);

/*-----------------------------------------------------------------------------------------
 * Function: Serial input/output device set ri level.
 *
 * Parameter:
 *    <atp_index>: 	[IN] 	the at cmd channel index.
 *    <level>:	    [IN]	the value is 0 or 1.
 *
 * Return:
 *    QUEC_SUCCESS: set the corresponding of atp_index ri ok .
 *    kGeneralErr:	fail to set the corresponding of atp_index ri value.
 *
-----------------------------------------------------------------------------------------*/
extern QuecOSStatus quec_siolib_set_ri_level(TelAtParserID atp_index,quec_pin_level_value_e level);

/*-----------------------------------------------------------------------------------------
 * Function: Serial input/output device get dtr level change to response.
 *
 * Parameter:
 *    <pvalue>:	    [IN]	the pointer to store the dtr change response.
 *
 * Return:
 *    QUEC_SUCCESS: get the dtr response value ok .
 *    kGeneralErr:	fail to get the dtr response value.
 *
-----------------------------------------------------------------------------------------*/
extern QuecOSStatus quec_siolib_get_dtr_response_mode(quec_sio_io_configure_state *pvalue);

/*-----------------------------------------------------------------------------------------
 * Function: tansmit data to atp_index.
 *
 * Parameter:
 *    <atp_index>:	[IN]	the data to send channel.
 *    <buf>:	    [IN]	the data buffer to send.
 *    <len>:	    [IN]	the data len to send.
 *
 * Return:
 *    QUEC_SUCCESS: send data success.
 *    kGeneralErr:	send data fail.
 *
-----------------------------------------------------------------------------------------*/
extern QuecOSStatus quec_siolib_transmit_to_atp(TelAtParserID atp_index,uint8 *buf,uint32 len, uint32 * pActualTransLen);

extern QuecOSStatus quec_siolib_set_dcd_func_mode(uint8 value);

/*-----------------------------------------------------------------------------------------
 * Function: Serial input/output device set rts level.
 *
 * Parameter:
 *    <atp_index>: 	[IN] 	the at cmd channel index.
 *    <level>:	    [IN]	the value is 0 or 1.
 *
 * Return:
 *    QUEC_SUCCESS: set the corresponding of atp_index cts ok .
 *    kGeneralErr:	fail to set the corresponding of atp_index cts value.
 *
-----------------------------------------------------------------------------------------*/
extern  QuecOSStatus quec_siolib_set_rts_level(TelAtParserID atp_index, quec_pin_level_value_e level);

/*-----------------------------------------------------------------------------------------
 * Function: Serial input/output device set rts level.
 *
 * Parameter:
 *    <atp_index>: 	[IN] 	the at cmd channel index.
 *    <plevel>:	    [OUT]   pointer to get the cts value.
 *
 * Return:
 *    QUEC_SUCCESS: set the corresponding of atp_index cts ok .
 *    kGeneralErr:	fail to get the corresponding of atp_index cts value.
 *
-----------------------------------------------------------------------------------------*/

extern QuecOSStatus quec_siolib_get_cts_level(TelAtParserID atp_index, quec_pin_level_value_e *plevel);

/*-----------------------------------------------------------------------------------------
 * Function: Serial input/output device set rts level.
 *
 * Parameter:
 *    <atp_index>: 	[IN] 	the at cmd channel index.
 *    <plevel>:	    [OUT]   pointer to get the rts value.
 *
 * Return:
 *    QUEC_SUCCESS: set the corresponding of atp_index rts ok .
 *    kGeneralErr:	fail to get the corresponding of atp_index rts value.
 *
-----------------------------------------------------------------------------------------*/

extern QuecOSStatus quec_siolib_get_rts_level(TelAtParserID atp_index, quec_pin_level_value_e *plevel);

#endif
