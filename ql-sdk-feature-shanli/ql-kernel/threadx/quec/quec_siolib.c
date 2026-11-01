/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/**
 ******************************************************************************
 * @file    quec_sio.c
 * @author  Chaim.Qian
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

/*=================================================================

						EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN			  WHO		  WHAT, WHERE, WHY
------------	 -------	 -------------------------------------------------------------------------------
10/15/2018		  Chaim	     Init version
=================================================================*/
#include "modem_platform.h"
#include "quec_drivers.h"
#include "quec_sio.h"
#include "quec_siolib.h"
#include "quec_include.h"
#include "quec_cust_feature.h"
#include "quec_gpio.h"
#include "quec_ppp.h"
#include "quec_board_common.h"

#ifdef QUEC_AT_AMPW_V_SUPPORT
#include  "quec_atcmd_general.h"
#endif
#include "watermark.h"
#ifdef QUEC_SIO_MODULE_ENABLE

#ifndef MIN_SYS


#ifdef QUEC_SIOLIB_LOG_ENABLE

	#define siolib_log(msg,...)  custom_log("SIOLIB",msg,##__VA_ARGS__)
#else
	#define siolib_log(msg,...)
#endif

typedef struct
{
    uint8 dcd_at_value;
    uint8 dtr_at_value;
}quec_sio_pin_func_s;

extern quec_ifc_value_s g_usb_ifc_value;
quec_sio_pin_func_s quec_sio_at_value={
    QUEC_SIO_IO_CONF_VALUE_0,
    QUEC_SIO_IO_CONF_VALUE_0
};

#ifdef QUEC_AT_GPS_ENABLE
#define QUEC_SIOLIB_ATP_STATE_NUM      8
#else
#define QUEC_SIOLIB_ATP_STATE_NUM      7
#endif

static quec_siolib_state  ql_sio_state[QUEC_SIOLIB_ATP_STATE_NUM] = {
	{QUEC_USBMODEM_CHANNEL, QUEC_CMD_MODE, QUEC_SIOLIB_PORT_FOR_MIN,NULL},
	{QUEC_UART1_CHANNEL, QUEC_CMD_MODE, QUEC_SIOLIB_PORT_FOR_MIN, NULL},
	{QUEC_USBAT_CHANNEL, QUEC_CMD_MODE,QUEC_SIOLIB_PORT_FOR_MIN, NULL},
    {QUEC_CMUX_CHANNEL_1, QUEC_CMD_MODE,QUEC_SIOLIB_PORT_FOR_MIN, NULL},
    {QUEC_CMUX_CHANNEL_2, QUEC_CMD_MODE,QUEC_SIOLIB_PORT_FOR_MIN, NULL},
    {QUEC_CMUX_CHANNEL_3, QUEC_CMD_MODE,QUEC_SIOLIB_PORT_FOR_MIN, NULL},
    {QUEC_CMUX_CHANNEL_4, QUEC_CMD_MODE,QUEC_SIOLIB_PORT_FOR_MIN, NULL},
#ifdef QUEC_AT_GPS_ENABLE
    {TEL_AT_CMD_ATP_UART2, QUEC_CMD_MODE, QUEC_SIOLIB_PORT_FOR_MIN, NULL},
#endif
};

quec_siolib_state *quec_siolib_port_get_state(TelAtParserID atp_index)
{
	int i = 0;

#if QUEC_DUAL_SIM_SUPPORT
	if (atp_index > QUEC_ATP_OFFSET_36)
	{
		atp_index = atp_index - QUEC_ATP_OFFSET_36;
	}
#endif

	for(i = 0;  i< QUEC_SIOLIB_ATP_STATE_NUM; i++)
	{
		if(ql_sio_state[i].atp_index == atp_index)
		{
			return &ql_sio_state[i];
		}
	}

	return NULL;
}


uint8 quec_siolib_port_is_in_raw_data_mode(TelAtParserID atp_index)
{
	quec_siolib_state *sio_state;

	sio_state = quec_siolib_port_get_state(atp_index);
#ifdef QUEC_PPP_ENABLE
	if(modem_if.modem_state == ACM_DATA_MODE && atp_index == modem_if.atp_index){
		 siolib_log("atp_index=%d in ppp modem", atp_index);
		// CPUartLogPrint("ppp mode");
		return TRUE;
	}else 
#endif
	if(sio_state != NULL && sio_state->atp_mode == QUEC_DATA_MODE){
		 siolib_log("atp_index=%d in quec raw modem", atp_index);
		// CPUartLogPrint("quec raw mode");
		return TRUE;
	}else{
		siolib_log("atp_index=%d,in cmd mode",atp_index);
	//	CPUartLogPrint("cmd mode");
		return FALSE;
	}
}


uint8 quec_siolib_port_enter_raw_mode(TelAtParserID atp_index, uint8 atp_owner, quec_siolib_func_tbl *fun_tbl)
{
	quec_siolib_state *sio_state;

    quec_clear_esc_count();
	sio_state = quec_siolib_port_get_state(atp_index);

	if(sio_state == NULL)
		return FALSE;

	if(sio_state->atp_mode == QUEC_DATA_MODE)
		return FALSE;
#ifdef QUEC_PPP_ENABLE
	//maybe PPP has been enter in data mode
	if(modem_if.modem_state == ACM_DATA_MODE && atp_index == modem_if.atp_index)
		return FALSE;
#endif
	sio_state->atp_mode = QUEC_DATA_MODE;
	sio_state->atp_owner = atp_owner;
	sio_state->atp_fun_tbl = fun_tbl;

	return TRUE;
}

uint8 quec_siolib_port_exit_raw_mode(TelAtParserID atp_index, uint8 allow_ato)
{
	quec_siolib_state *sio_state;

	sio_state = quec_siolib_port_get_state(atp_index);

    //退出透传模式时，如果当前流控在disable，则需要设置为enable
	if(quec_sio_wm_get_read_status(atp_index, SIO_RX) == QUEC_DISABLE)
	{
		quec_sio_wm_set_read_status(atp_index,SIO_RX, QUEC_ENABLE);
	}

	if(sio_state == NULL)
		return FALSE;

	if(sio_state->atp_mode == QUEC_CMD_MODE || sio_state->atp_mode == QUEC_CMD_DATA_MODE)
		return FALSE;

	if(allow_ato == TRUE){
		sio_state->atp_mode = QUEC_CMD_DATA_MODE;
	}else{
		sio_state->atp_mode = QUEC_CMD_MODE;
		sio_state->atp_fun_tbl = NULL;
	}

	at_urc_flush();/*Refresh URC not reported during DATA_MODE*/
    quec_clear_esc_count();
    quec_event_notify_report(EVENT_CHECK_URC_REPORT, NULL);
	return TRUE;
}

void quec_siolib_port_process_rx_msg(TelAtParserID atp_index, void *data_ptr, UINT32 data_len)
{
	quec_siolib_state *sio_state;

	sio_state = quec_siolib_port_get_state(atp_index);

	if(sio_state != NULL
	   && sio_state->atp_mode == QUEC_DATA_MODE
	   && sio_state->atp_fun_tbl != NULL
	   && sio_state->atp_fun_tbl->receive_handler != NULL){
	   	sio_state->atp_fun_tbl->receive_handler(atp_index, data_ptr, data_len);
	}
}
void quec_siolib_port_process_escape_msg(TelAtParserID atp_index)
{
	quec_siolib_state *sio_state;

	sio_state = quec_siolib_port_get_state(atp_index);

	if(sio_state != NULL
	   && sio_state->atp_mode == QUEC_DATA_MODE
	   && sio_state->atp_fun_tbl != NULL
	   && sio_state->atp_fun_tbl->at_escape_sequence_handler != NULL){
	   	sio_state->atp_fun_tbl->at_escape_sequence_handler(atp_index);
	}
}

void quec_siolib_port_process_dtr_change_msg(TelAtParserID atp_index)
{
	quec_siolib_state *sio_state;
    quec_sio_io_configure_state value;
    bool ip_dns_has_update = 0;
    int ret = 0;

    ret = quec_siolib_get_dtr_response_mode(&value);
    if(ret != QUEC_SUCCESS)
    {
        return kGeneralErr;
    }
    
    if(QUEC_SIO_IO_CONF_VALUE_1 == value)
    {
       	sio_state = quec_siolib_port_get_state(atp_index);

    	if(sio_state != NULL
    	   && sio_state->atp_mode == QUEC_DATA_MODE
    	   && sio_state->atp_fun_tbl != NULL
    	   && sio_state->atp_fun_tbl->dtr_change_handler != NULL){
    	   	sio_state->atp_fun_tbl->dtr_change_handler(atp_index);
    	}
    }
}

uint8 quec_siolib_port_process_ato_msg(UINT32 atHandle)
{
	quec_siolib_state *sio_state;

	sio_state = quec_siolib_port_get_state(GET_ATP_INDEX(atHandle));

	if(sio_state == NULL)
		return FALSE;

	if(sio_state->atp_mode != QUEC_CMD_DATA_MODE)
		return FALSE;

	if(sio_state->atp_fun_tbl != NULL && sio_state->atp_fun_tbl->ato_func != NULL){
		if(sio_state->atp_fun_tbl->ato_func(atHandle) == TRUE)
			return TRUE;
	}

	return FALSE;
}

/*
Chaim 2018.12.5
if set ifc_value after interrupt happen, no interrupt will be cause ifc fail
so add this function to solve this problem
enable --TRUE means AT+IFC=2,2 effect  --FALSE means AT+IFC=0,0 effect
*/

QuecOSStatus quec_ifc_value_effect(TelAtParserID atp_index, bool enable)
{
    QuecOSStatus ret = kGeneralErr;
    uint8 i=0;
    quec_pin_level_value_e level = QUEC_PIN_LEVEL_HIGH;
    uint8 atp_ind[]={QUEC_USBMODEM_CHANNEL,QUEC_UART1_CHANNEL,QUEC_USBAT_CHANNEL};
    
    for(i = 0; i< sizeof(atp_ind)/sizeof(uint8); i++)
    {
        if(atp_index == atp_ind[i])
        {
            if(enable == TRUE)
            {
                ret = quec_siolib_get_cts_level(atp_ind[i],&level); 
                if(ret != QUEC_SUCCESS)
                {
                    siolib_log("atp_index=%d get cts level fail", atp_ind[i]);
                    return ret;
                }
                else
                {
                    siolib_log("atp_index=%d cts level=%d", atp_ind[i],level);
                    if(level == QUEC_PIN_LEVEL_HIGH)  //not allow to send
                    {
                        quec_sio_flowctl_set_send_status(atp_ind[i], FALSE);               
                    }
                    else
                    {
                        quec_sio_flowctl_set_send_status(atp_ind[i], TRUE); 
                    }
                }            
            }
            else
            {
				 siolib_log("atp_index=%d,cts not effect,allow send", atp_ind[i]);
                 quec_sio_flowctl_set_send_status(atp_ind[i], TRUE);
                 
            }
            return QUEC_SUCCESS;
        }
        
    }
    siolib_log("atp_index=%d,cts not find", atp_index);
    return QUEC_SUCCESS;

}

static void quec_siolib_variable_init(void)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    
#if QUEC_HALF_HARDWARE_FLOWERCTRL  
    ret = quectel_current_config_value_get(AT_IFC_RTS,&g_uart_ifc_value.rts_control);
    if(ret != utlSUCCESS)
    {
       quec_debug_print_uart("uart get ifc value fail rts_control=%d,cts_control=%d",\
         g_uart_ifc_value.rts_control, g_uart_ifc_value.cts_control);   
    }

    ret = quectel_current_config_value_get(AT_IFC_CTS,&g_uart_ifc_value.cts_control);
    if(ret != utlSUCCESS)
    {
       quec_debug_print_uart("uart get ifc value fail rts_control=%d,cts_control=%d",\
         g_uart_ifc_value.rts_control, g_uart_ifc_value.cts_control);   
    }
	
	memcpy(&g_uart_temp_ifc_value, &g_uart_ifc_value, sizeof(g_uart_ifc_value));
	
    #ifdef __QUEC_OEM_VER_NL__
    if(g_uart_ifc_value.rts_control == g_uart_ifc_value.cts_control) //Chaim 20190827 self flow control not consideration in NL
    {
        if(0 == g_uart_ifc_value.rts_control)
        {
            quec_fibo_update_atk_value(0);
        }
        else
        {
            quec_fibo_update_atk_value(3);    //Chaim 20190827 NL use 3,this may also be 6 ????
        }
    }

    #endif

    ret = quectel_nv_fat_read(QUEC_USB_IFC_NAME,&g_usb_ifc_value,sizeof(g_usb_ifc_value));
    if(ret != QUEC_FAT_SUCCESS)
    {
       quec_debug_print_uart("usb get ifc value fail rts_control=%d,cts_control=%d",\
         g_usb_ifc_value.rts_control, g_usb_ifc_value.cts_control);  
    }
#endif
#ifdef QUEC_PPP_ENABLE
    ret = quec_read_ppp_remoteip();
    if(ret != QUEC_FAT_SUCCESS)
    {
       quec_debug_print_uart("remoteip read fail");  
    }
#endif
}

#if  QUEC_HALF_HARDWARE_FLOWERCTRL
extern QuecOSStatus quec_cts_hardware_init(void);
extern QuecOSStatus quec_cts_rts_hardware_init(void);

static void quec_siolib_ifc_effect(void)
{
    QuecOSStatus status = QUEC_SUCCESS;
   
#if  QUEC_HALF_HARDWARE_FLOWERCTRL
    if(g_uart_ifc_value.cts_control == QUEC_AT_IFC_CMD_VAL_MAX)
    {
    	if(QUEC_AT_IFC_CMD_VAL_SOF == g_uart_ifc_value.rts_control )
    	{
    		quec_cts_hardware_init();
    	}
		else if(QUEC_AT_IFC_CMD_VAL_MAX == g_uart_ifc_value.rts_control )
		{
			quec_cts_rts_hardware_init();
		}
    }
	else if(g_uart_ifc_value.cts_control == QUEC_AT_IFC_CMD_VAL_SOF)
	{
		quec_ifc_value_effect(QUEC_UART1_CHANNEL,TRUE);     
    }
    else
#endif        
    {
        quec_ifc_value_effect(QUEC_UART1_CHANNEL,FALSE);    
    }  

    if((g_usb_ifc_value.rts_control == QUEC_AT_IFC_CMD_VAL_MAX)
		#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL
		&&(g_usb_ifc_value.rts_control == g_uart_ifc_value.cts_control)
		#endif
		)
    {
        quec_ifc_value_effect(QUEC_USBMODEM_CHANNEL,TRUE);      
        quec_ifc_value_effect(QUEC_USBAT_CHANNEL,TRUE);  
    }
    else
    {
        quec_ifc_value_effect(QUEC_USBMODEM_CHANNEL,FALSE);  
        quec_ifc_value_effect(QUEC_USBAT_CHANNEL,FALSE);  
    }  
}
#endif

//sio module init
void quec_siolib_init(void)
{
    quec_siolib_variable_init();
    quec_sio_init();
#if  QUEC_HALF_HARDWARE_FLOWERCTRL
    quec_siolib_ifc_effect();
#endif
    
    siolib_log("sio module init done");

}

QuecOSStatus quec_siolib_get_ri_level(TelAtParserID atp_index, quec_pin_level_value_e *plevel)
{
    QuecOSStatus status = QUEC_SUCCESS;

    quec_sio_device_interafce *device_ptr = quec_get_sio_device_if_ptr(atp_index);
    if(device_ptr->driver_avaliable != SIO_DRIVER_AVALIABLE)
    {
        siolib_log("atp_index=%d device unavaliable", atp_index);
	    return kGeneralErr;
    }

    status = device_ptr->driver_interface.HW_ioctl(atp_index, IOCTL_READ_RI_CMD, plevel);

    return status;
}

QuecOSStatus quec_siolib_set_ri_level(TelAtParserID atp_index, quec_pin_level_value_e level)
{
    QuecOSStatus status = QUEC_SUCCESS;
    quec_pin_level_value_e setlevel = level;
    quec_sio_device_interafce *device_ptr = quec_get_sio_device_if_ptr(atp_index);

    if((QUEC_PIN_LEVEL_LOW != level)&&(QUEC_PIN_LEVEL_HIGH != level))
    {
        siolib_log("atp_index=%d,level=%d invalid", atp_index,level);
	    return kGeneralErr; 
    }
    
    if(device_ptr->driver_avaliable != SIO_DRIVER_AVALIABLE)
    {
        siolib_log("atp_index=%d device unavaliable", atp_index);
	    return kGeneralErr;
    }
    status = device_ptr->driver_interface.HW_ioctl(atp_index, IOCTL_WRITE_RI_CMD, &setlevel);

    return status;
}

QuecOSStatus quec_siolib_set_rts_level(TelAtParserID atp_index, quec_pin_level_value_e level)
{
    QuecOSStatus status = QUEC_SUCCESS;
    quec_pin_level_value_e setlevel = level;
    quec_sio_device_interafce *device_ptr = quec_get_sio_device_if_ptr(atp_index);

    if((QUEC_PIN_LEVEL_LOW != level)&&(QUEC_PIN_LEVEL_HIGH != level))
    {
        siolib_log("atp_index=%d,level=%d invalid", atp_index,level);
	    return kGeneralErr; 
    }
    
    if(device_ptr->driver_avaliable != SIO_DRIVER_AVALIABLE)
    {
        siolib_log("atp_index=%d device unavaliable", atp_index);
	    return kGeneralErr;
    }
    status = device_ptr->driver_interface.HW_ioctl(atp_index, IOCTL_WRITE_RTS_CMD, &setlevel);

    return status;
}

QuecOSStatus quec_siolib_get_cts_level(TelAtParserID atp_index, quec_pin_level_value_e *plevel)
{
    QuecOSStatus status = QUEC_SUCCESS;

    quec_sio_device_interafce *device_ptr = quec_get_sio_device_if_ptr(atp_index);
    if(device_ptr->driver_avaliable != SIO_DRIVER_AVALIABLE)
    {
        siolib_log("atp_index=%d device unavaliable", atp_index);
	    return kGeneralErr;
    }

    status = device_ptr->driver_interface.HW_ioctl(atp_index, IOCTL_READ_CTS_CMD, plevel);

    return status;
}

QuecOSStatus quec_siolib_get_rts_level(TelAtParserID atp_index, quec_pin_level_value_e *plevel)
{
    QuecOSStatus status = QUEC_SUCCESS;

    quec_sio_device_interafce *device_ptr = quec_get_sio_device_if_ptr(atp_index);
    if(device_ptr->driver_avaliable != SIO_DRIVER_AVALIABLE)
    {
        siolib_log("atp_index=%d device unavaliable", atp_index);
	    return kGeneralErr;
    }

    status = device_ptr->driver_interface.HW_ioctl(atp_index, IOCTL_READ_RTS_CMD, plevel);

    return status;
}

QuecOSStatus quec_siolib_transmit_to_atp(TelAtParserID atp_index, uint8 *buf, uint32 len, uint32 * pActualTransLen)
{
    QuecOSStatus 				err = kNoErr;
	quec_sio_device_interafce 	* pdevice_ptr = NULL;

#if QUEC_DUAL_SIM_SUPPORT
#ifdef QUEC_AT_QCFG_USB_NEMA
if(atp_index!=TEL_AT_CMD_ATP_NEMA)
#endif
	if (atp_index > QUEC_ATP_OFFSET_36)
	{
		atp_index = atp_index - QUEC_ATP_OFFSET_36;
	}
#endif

	require_action(buf && len, exit, err = kParamErr);
  
    pdevice_ptr = quec_get_sio_device_if_ptr(atp_index);

	require_action(pdevice_ptr, exit, err = kNotInitializedErr);

	err = quec_sio_wm_write(atp_index, SIO_TX, buf, len, pActualTransLen);
	require_noerr(err, exit);

exit:
    return err;
}


//set at&d0 or at&d1 at&d2 value
QuecOSStatus quec_siolib_set_dcd_func_mode(uint8 value)
{
    QuecOSStatus status = QUEC_SUCCESS;

	if((value != QUEC_SIO_IO_CONF_VALUE_0) && \
		(value != QUEC_SIO_IO_CONF_VALUE_1))
	{
		siolib_log("value=%d invalid", value);
		return kGeneralErr;
	}

    quec_sio_at_value.dcd_at_value = value;

	#ifdef QUEC_AT_AMPW_V_SUPPORT
	quectel_current_config_value_set(AT_AMP_C, value);
 	#endif

	return status;
}

QuecOSStatus quec_siolib_get_dtr_level(TelAtParserID atp_index, quec_pin_level_value_e *plevel)
{
    QuecOSStatus status = QUEC_SUCCESS;

    quec_sio_device_interafce *device_ptr = quec_get_sio_device_if_ptr(atp_index);

    if(device_ptr->driver_avaliable != SIO_DRIVER_AVALIABLE)
    {
        siolib_log("atp_index=%d device unavaliable", atp_index);
	    return kGeneralErr;
    }

    status = device_ptr->driver_interface.HW_ioctl(atp_index, IOCTL_READ_DTR_CMD, plevel);

    return status;
}


QuecOSStatus quec_siolib_get_dcd_level(TelAtParserID atp_index, quec_pin_level_value_e *plevel)
{
    QuecOSStatus status = QUEC_SUCCESS;

    quec_sio_device_interafce *device_ptr = quec_get_sio_device_if_ptr(atp_index);

    if(device_ptr->driver_avaliable != SIO_DRIVER_AVALIABLE)
    {
        siolib_log("atp_index=%d device unavaliable", atp_index);
	    return kGeneralErr;
    }

    status = device_ptr->driver_interface.HW_ioctl(atp_index, IOCTL_READ_DCD_CMD, plevel);

    return status;
}

QuecOSStatus quec_siolib_set_dcd_level(TelAtParserID atp_index, quec_pin_level_value_e level)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    quec_pin_level_value_e setlevel = level;

    #ifdef __QUEC_OEM_VER_NL__

    if( 100 == quec_fibo_get_atc_value())
    {
        siolib_log("not new land customer cmd,return.");
        return QUEC_SUCCESS;
    }

    #endif
    
    if((QUEC_PIN_LEVEL_LOW != level)&&(QUEC_PIN_LEVEL_HIGH != level))
    {
        siolib_log("atp_index=%d,level=%d invalid", atp_index,level);
	    return kGeneralErr; 
    }
    
    quec_sio_device_interafce *device_ptr = quec_get_sio_device_if_ptr(atp_index);

    if(device_ptr->driver_avaliable != SIO_DRIVER_AVALIABLE)
    {
        siolib_log("atp_index=%d device unavaliable", atp_index);
	    return kGeneralErr;
    }
    
    ret = device_ptr->driver_interface.HW_ioctl(atp_index, IOCTL_WRITE_DCD_CMD, &setlevel);

    return ret;

}

#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
//Chaim 20190829 new land only use uart1,in mipcall dcd low,other is high.
QuecOSStatus quec_siolib_fibo_set_dcd_level(quec_pin_level_value_e level)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    quec_pin_level_value_e setlevel = level;
    siolib_log("set fibo dcd level=%d", level);
    if((QUEC_PIN_LEVEL_LOW != level)&&(QUEC_PIN_LEVEL_HIGH != level))
    {
        siolib_log("atp_index=%d,level=%d invalid", QUEC_UART1_CHANNEL,level);
	    return kGeneralErr; 
    }
    
    quec_sio_device_interafce *device_ptr = quec_get_sio_device_if_ptr(QUEC_UART1_CHANNEL);

    if(device_ptr->driver_avaliable != SIO_DRIVER_AVALIABLE)
    {
        siolib_log("atp_index=%d device unavaliable", QUEC_UART1_CHANNEL);
	    return kGeneralErr;
    }
    if(100 != quec_fibo_get_atc_value())
    {
        siolib_log("g_fibo_atc_value=%d,not set dcd level", quec_fibo_get_atc_value());    
    }
    siolib_log("set dcd value=%d",level); 
    
    ret = device_ptr->driver_interface.HW_ioctl(QUEC_UART1_CHANNEL, IOCTL_WRITE_DCD_CMD, &setlevel);

    return ret;

}
#endif

void quec_sio_dtr_status_change(TelAtParserID atp_index, quec_pin_edge_direction_e edge)
{

    siolib_log("atp_index=%d dtr status change edge=%d", atp_index, edge);
    quec_siolib_dtr_exe_cb(atp_index, edge);
}



//set at&d0 or at&d1 at&d2 value
QuecOSStatus quec_siolib_set_dtr_response_mode(uint8 value)
{
    QuecOSStatus status = QUEC_SUCCESS;

	if((value  != QUEC_SIO_IO_CONF_VALUE_0) &&\
		(value != QUEC_SIO_IO_CONF_VALUE_1) &&\
		(value != QUEC_SIO_IO_CONF_VALUE_2))
	{
		siolib_log("value=%d invalid", value);
		return kGeneralErr;
	}

    quec_sio_at_value.dtr_at_value = value;
	#ifdef QUEC_AT_AMPW_V_SUPPORT
	quectel_current_config_value_set(AT_AMP_D, value);
 	#endif

	return status;
}



QuecOSStatus quec_siolib_get_dtr_response_mode(quec_sio_io_configure_state *pvalue)
{
    if(pvalue == NULL)
    {
        siolib_log("pvalue is a null pointer");
		return kGeneralErr;
    }
	#ifdef QUEC_AT_AMPW_V_SUPPORT
	int value;
	quectel_current_config_value_get(AT_AMP_D, &value);
	*pvalue = value;
	#else
    *pvalue = quec_sio_at_value.dtr_at_value;
	#endif
    return QUEC_SUCCESS;
}

QuecOSStatus quec_siolib_register_dtr_func_cb(TelAtParserID atp_index, sio_dtr_func_ptr_type dtr_change_cb)
{
    QuecOSStatus status = QUEC_SUCCESS;

    if(dtr_change_cb == NULL)
    {
       siolib_log("atp_index=%d register dtr call back fail", atp_index);
	   return kGeneralErr;
    }

    quec_sio_device_interafce *device_ptr = quec_get_sio_device_if_ptr(atp_index);

    if(device_ptr->driver_avaliable != SIO_DRIVER_AVALIABLE)
    {
        siolib_log("atp_index=%d device unavaliable", atp_index);
	    return kGeneralErr;
    }
    device_ptr->dtr_func = dtr_change_cb;

    return status;
}

QuecOSStatus quec_siolib_dtr_exe_cb(TelAtParserID atp_index, quec_pin_edge_direction_e edge)
{
    sio_dtr_func_ptr_type pdtr_callback = quec_sio_get_dtr_func_cb(atp_index);
    if(pdtr_callback == NULL)
    {
       siolib_log("atp_index=%d register dtr call back is not found", atp_index);
	   return kGeneralErr;
    }
    pdtr_callback(atp_index, edge);

    return QUEC_SUCCESS;
}
#ifdef QUEC_HALF_HARDWARE_FLOWERCTRL
QuecOSStatus quec_get_ifc_value(TelAtParserID atp_index, quec_ifc_value_s *ifc_value)
{
    QuecOSStatus ret = QUEC_SUCCESS;

    if(ifc_value == NULL)
    {
        siolib_log("ifc_value is a null pointer"); 
        return kGeneralErr;
    }
    switch (atp_index)
    {
		#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL
        case QUEC_UART1_CHANNEL:
            ifc_value->rts_control = g_uart_ifc_value.rts_control;
            ifc_value->cts_control = g_uart_ifc_value.cts_control;
            
        break;
		#endif
        case QUEC_USBMODEM_CHANNEL:
        case QUEC_USBAT_CHANNEL:
             ifc_value->rts_control = g_usb_ifc_value.rts_control;
             ifc_value->cts_control = g_usb_ifc_value.cts_control;
        break;

        default:
           ret =  kGeneralErr;
           siolib_log("atp_index is invalid", atp_index); 
        break;
    }
    
    return ret;
}
#endif
/*Chaim 20190821

设置主串口的流控功能
*/
#if  QUEC_HALF_HARDWARE_FLOWERCTRL

QuecOSStatus quec_set_majoruart_ifc_value(TelAtParserID atp_index, quec_ifc_value_s ifc_value)
{
    QuecOSStatus ret = kGeneralErr;
    if(QUEC_UART1_CHANNEL !=atp_index)
    {
        siolib_log("set ifc value atp_index=%d is not uart,return ok directly",atp_index); 
        return QUEC_SUCCESS;    
    }
#if  QUEC_HALF_HARDWARE_FLOWERCTRL     
//	if((ifc_value.rts_control < QUEC_AT_IFC_CMD_VAL_MIN) || (ifc_value.rts_control > QUEC_AT_IFC_CMD_VAL_MAX)) 
	if((ifc_value.rts_control > QUEC_AT_IFC_CMD_VAL_MAX)) 
#else     
    if((ifc_value.rts_control != QUEC_AT_IFC_CMD_VAL_MIN)&& (ifc_value.rts_control != QUEC_AT_IFC_CMD_VAL_MAX))
#endif
    {
        siolib_log("set ifc rts value=%d is invalid", ifc_value.rts_control); 
        return ret;
    }
#if  QUEC_HALF_HARDWARE_FLOWERCTRL
//	if((ifc_value.rts_control < QUEC_AT_IFC_CMD_VAL_MIN) || (ifc_value.rts_control > QUEC_AT_IFC_CMD_VAL_MAX))	 
	if((ifc_value.rts_control > QUEC_AT_IFC_CMD_VAL_MAX))
#else
    if((ifc_value.cts_control != QUEC_AT_IFC_CMD_VAL_MIN)&& (ifc_value.cts_control != QUEC_AT_IFC_CMD_VAL_MAX))
#endif
    {
        siolib_log("set ifc cts value=%d is invalid", ifc_value.cts_control); 
        return ret;
    }
 
    if((ifc_value.rts_control == g_uart_ifc_value.rts_control)&&(ifc_value.cts_control == g_uart_ifc_value.cts_control))
    {
        siolib_log("set ifc_value=%d is same with system,not reset,return ok ", g_uart_ifc_value.rts_control); 
        return QUEC_SUCCESS;
    }

    //Chaim 20190826 copy at cmd value
    memcpy(&g_uart_temp_ifc_value,&ifc_value,sizeof(ifc_value));
    siolib_log("start ifc timer,rts=%d,cts=%d ", g_uart_temp_ifc_value.rts_control, g_uart_temp_ifc_value.cts_control); 
	quectel_current_config_value_set(AT_IFC_RTS, g_uart_temp_ifc_value.rts_control); //add by wayne 2020.08.28 for reslove at+ifc;&w not save bug.
	quectel_current_config_value_set(AT_IFC_CTS, g_uart_temp_ifc_value.cts_control); 
	quec_uart1_ifc_timer_start();
    return QUEC_SUCCESS;

}
#endif
#endif



#endif /*MIN_SYS*/




