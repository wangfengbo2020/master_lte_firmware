/**
 ******************************************************************************
 * @file    quec_usb.h
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


#ifndef _QUEC_USB_H
#define _QUEC_USB_H


#include "teldef.h"
#include "quec_include.h"
#include "quec_msg_process.h"

#ifdef __cplusplus
extern "C" {
#endif


#define QUEC_USB_LOG_ENABLE


#define USB_MODEM3_PPP_PORT    4     //atp_0 PORT
#define USB_MODEM2_AT_PORT     3      //atp_ttyusb PORT

#define QUEC_USB_IFC_NAME "usb_ifc_config"

#ifdef  QUEC_USB_ENABLE

#define QUEC_USB_MODEM_PORT_INDEX  1    //TEL_AT_CMD_ATP_0
#define QUEC_USB_AT_PORT_INDEX     3    //TEL_AT_CMD_ATP_TTYUSB2
#define QUEC_USB_TTYUSB3_PORT_INDEX    4

typedef enum 
{
	QUEC_USB_PORT_DISABLE =0,
	QUEC_USB_PORT_ENABLE,	
}quec_usb_port_state_e;


#endif


typedef enum
{
    QUEC_USB_DTR_SHIFT =0,
    QUEC_USB_CTS_SHIFT =1
}quec_usb_pin_detect_shift_e;
    
typedef enum
{
    PCIE_USB_DETACH = 0,
    PCIE_USB_ATTACH
}quec_pcie_usb_vbus_attache_e;

typedef enum 
{
	QUEC_USBNET_MIFI_MODE = 0,  //Chaim 20191017,default usb netcard is mifi mode
	QUEC_USBNET_DONGLE_MODE =1,
	QUEC_USBNET_MAX_MODE,
}quec_nat_flag_e;
    

typedef struct
{
    uint8 rts_control;
    uint8 cts_control;
}quec_usb_ifc_value_s;   

extern quec_nat_flag_e g_quec_nat_flag;

extern QuecOSStatus quec_mvusb_send_data(TelAtParserID atp_index,uint8 *pdata,uint32 len);
extern QuecOSStatus quec_mvusb_ioctl(TelAtParserID atp_index, quec_ioctl_cmd_type_e cmd, quec_ioctl_param *param);
extern void quec_mvusb_init(void);
extern QuecOSStatus quec_usb_ifc_value_isinvalid(TelAtParserID atp_index);
extern QuecOSStatus quec_read_nat_flag(void);
extern void quec_usb_debug_log_space_init(void);
extern void quec_usb_debug_log_space_output(quec_msg_process_s *pusblog);
extern QuecOSStatus quec_usb_ifc_timer_start(void);
extern QuecOSStatus quec_usb_ifc_msg_process(void);
extern QuecOSStatus quec_set_usb_ifc_value( quec_usb_ifc_value_s ifc_value);
#ifdef  QUEC_USB_CDC_SUPPORT
void quec_sulog_set_status(unsigned char value);
unsigned char quec_sulog_get_status(void);
int quec_usbcdc_open(void);
int quec_usbcdc_close(void);
int quec_uartcdc_write(char *data,int len);
int quec_usbcdc_read(unsigned char *data, int len);
void quec_usbcdc_register_cb(void* uart_cb);
void quec_usbcdc_register_cb_ex(void* uart_cb, void *priavte);
#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif

