/**
 ******************************************************************************
 * @file    quec_sio.h
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


#ifndef _QUEC_SIO_H
#define _QUEC_SIO_H

#include "quec_debug.h"
#include "teldef.h"
#include "quec_uart_at.h"
#include "quec_drivers.h"
#include "quec_cust_feature.h"
#include "modem_platform.h"
#include "quec_usb.h"
#include "watermark.h"


#ifdef __cplusplus
extern "C" {
#endif


#define QUEC_SIO_WM_SIZE		(10*1024)
#define QUEC_SIO_WM_LOW_BNDRY	(2*1024)
#define QUEC_SIO_WM_HIGH_BNDRY	(8*1024)


#define	USB_TOTAL_DTD_CNT_HIGH_THRESHOLD_DFT		56//32
#define	USB_TOTAL_DTD_CNT_LOW_THRESHOLD_DFT			32//16
#define	USB_APP_PORT_TX_DTD_CNT_HIGH_THRESHOLD_DFT	32//16
#define	USB_APP_PORT_TX_DTD_CNT_LOW_THRESHOLD_DFT	10//6

#define	USB_DTD_CNT_HIGH_THRESHOLD_MAX				64
#define	USB_DTD_CNT_HIGH_THRESHOLD_MIN				0

#define	USB_DTD_CNT_LOW_THRESHOLD_MAX				64
#define	USB_DTD_CNT_LOW_THRESHOLD_MIN				0

typedef enum
{
	USB_DTD_TYPE_TOTAL = 0,
	USB_DTD_TYPE_APP_TX
} usb_dtd_type_e;

typedef enum
{
	SIO_RX,
	SIO_TX
} sio_transfer_dir_e;

typedef struct
{
	TelAtParserID 		atpIndex;
	sio_transfer_dir_e	dir;
} sio_transfer_t;

typedef enum
{
    QUEC_CMD_MODE=0,
    QUEC_DATA_MODE,
    QUEC_CMD_DATA_MODE,
}quec_atp_modem_state_e;


typedef enum
{
	SIO_DRIVER_UNAVALIABLE=0,
	SIO_DRIVER_AVALIABLE,
}quec_driver_avaliable_status;

typedef enum
{
    SIO_USB_PORT=0,
    SIO_UART_PORT,
}quec_usb_uart_port_e;

//typedef int32 sio_ioctl_default_param_type

typedef struct
{
    uint8 *data;
    int32 len;
}quec_sio_ioctl_transmit_type;

#ifdef QUEC_SLEEP_AP_READY
typedef struct
{
    uint8  apready_action_level;
    bool   b_sendPktFlag;
    bool   b_sendUrcFlag;
    bool   b_apready_pin_init_flag;
    uint8  apready_enbale_flag;
    uint32 apready_timeout;
} quec_apready_cfg_t;
#endif

typedef struct
{

	QuecOSStatus (*HW_init)(TelAtParserID atp_index); //atp_index just for null print
	//int (*HW_open)(TelAtParserID atp_index);
    //int (*HW_close)(TelAtParserID atp_index);
	QuecOSStatus (*HW_read)( TelAtParserID atp_index, uint8 *data, uint32 len);
	QuecOSStatus (*HW_write)(TelAtParserID atp_index, uint8 *data, uint32 len);
	QuecOSStatus (*HW_ioctl)( TelAtParserID atp_index,quec_ioctl_cmd_type_e cmd_type,quec_ioctl_param *param);
	QuecOSStatus (*HW_notify)(TelAtParserID atp_index);//tbd

}quec_sio_driver_interface;

typedef struct
{
	uint8 * start;
	uint8 * ptr;
	uint32 len;
} unWritenData_t;

typedef struct
{
	wm_handle_t 	handle;
	TelAtParserID	atpIndex;
	unWritenData_t	unWritenData;
	bool			readEn;
	quec_mutex_t	mutex;
} wm_mgr_t;

typedef QuecOSStatus (*sio_dtr_func_ptr_type)(TelAtParserID atp_index,quec_pin_edge_direction_e edge);
typedef struct
{
    TelAtParserID 					atp_index;        	// atp_index
    quec_driver_avaliable_status    driver_avaliable;   // Non zero = No driver available
    sio_dtr_func_ptr_type   		dtr_func;			// dtr function execution entry
    quec_sio_driver_interface 		driver_interface;   // driver_interface structure
}quec_sio_device_interafce;

typedef QuecOSStatus (*quec_sio_register_device_driver_cb_type)(quec_sio_device_interafce *device_iface_ptr);
typedef QuecOSStatus (*quec_sio_driver_init_func_type)(quec_sio_register_device_driver_cb_type register_driver_cb_fn);

typedef struct
{
	quec_sio_driver_init_func_type	sio_driver_init_list;
	quec_sio_device_interafce       sio_device_list;
	wm_mgr_t						tx_wm_mgr;
	wm_mgr_t						rx_wm_mgr;
	volatile bool					flowctl_send_en;
	bool							isInitialized;
} sio_driver_context_t;


//the highest four bit indication dtr state value,the lowest four bit indication dcd state value
extern uint8 quec_sio_io_config_state;

typedef enum
{
	QUEC_SIO_IO_CONF_VALUE_0=0,
	QUEC_SIO_IO_CONF_VALUE_1,
	QUEC_SIO_IO_CONF_VALUE_2,
}quec_sio_io_configure_state;

extern QuecOSStatus						quec_sio_init(void);
extern void 							quec_sio_usb_phy_set_total_dtd_cnt_threshold(uint8 high_threshold, uint8 low_threshold);
extern void 							quec_sio_usb_phy_get_total_dtd_cnt_threshold(uint8 * high_threshold_ptr, uint8 * low_threshold_ptr);
extern void 							quec_sio_usb_phy_set_app_port_tx_dtd_cnt_threshold(uint8 high_threshold, uint8 low_threshold);
extern void 							quec_sio_usb_phy_get_app_port_tx_dtd_cnt_threshold(uint8 * high_threshold_ptr, uint8 * low_threshold_ptr);
extern void								quec_sio_usb_phy_send_data_accum_get_cnt(uint8 * totalDtdCntPtr, uint8 * appPortTxDtdCntPtr);
extern void 							quec_sio_usb_phy_send_data_accum_set_high(bool setHigh);
extern bool 							quec_sio_usb_phy_send_data_accum_is_high(void);
extern quec_sio_device_interafce * 		quec_get_sio_device_if_ptr(TelAtParserID atp_index);
extern sio_dtr_func_ptr_type  			quec_sio_get_dtr_func_cb(TelAtParserID atp_index);
extern QuecOSStatus 					quec_sio_wm_write(TelAtParserID atpIndex, sio_transfer_dir_e sio_transfer_dir, uint8* buffer, uint32 len, uint32 * pActualWriteLen);
extern bool 							quec_sio_wm_is_empty(TelAtParserID atpIndex, sio_transfer_dir_e sio_transfer_dir);
extern void 							quec_sio_wm_set_read_status(TelAtParserID atpIndex, sio_transfer_dir_e sio_transfer_dir, bool enable);
extern bool 							quec_sio_wm_get_read_status(TelAtParserID atpIndex, sio_transfer_dir_e sio_transfer_dir);
extern QuecOSStatus 					quec_sio_wm_send_msg_to_dds(TelAtParserID atpIndex, sio_transfer_dir_e sio_transfer_dir,uint16 time_out);
extern void 							quec_sio_flowctl_set_send_status(TelAtParserID atpIndex, bool enable);
extern bool 							quec_sio_flowctl_get_send_status(TelAtParserID atpIndex);
extern void 							quec_sio_flowctl_set_recv_status(TelAtParserID atpIndex, bool enable);
extern bool 							quec_sio_flowctl_get_recv_status(TelAtParserID atpIndex);
extern sio_driver_context_t *			quec_sio_driver_context_get(void);

extern  QuecOSStatus quec_sio_get_port_data_show_flag(TelAtParserID atpIndex,quec_debug_port_data_show_s **pdata_show);

extern  QuecOSStatus quec_sio_set_port_data_show_flag(TelAtParserID atpIndex,uint8 tx_flag,uint8 rx_flag);

#if  QUEC_HALF_HARDWARE_FLOWERCTRL
extern  QuecOSStatus quec_sio_unfinished_data_write(TelAtParserID atpIndex,uint32 DataLength,uint8 *buff);
#endif

extern  QuecOSStatus quec_sio_wm_clear(TelAtParserID    	 atpIndex, sio_transfer_dir_e transfer_dir,uint32 *wn_cnt);
#ifdef __cplusplus
} /*"C" */
#endif

#endif


