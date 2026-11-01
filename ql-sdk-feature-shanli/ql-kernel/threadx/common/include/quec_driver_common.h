/**
 ******************************************************************************
 * @file    quec_driver_common.h
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


#ifndef _QUEC_DRIVER_COMMON_H
#define _QUEC_DRIVER_COMMON_H


#ifdef __cplusplus
extern "C" {
#endif



typedef enum
{
    QUEC_DRIVER_MUTEX_DCD=0,
    QUEC_DRIVER_MUTEX_RI,
    QUEC_DRIVER_MUTEX_SEND,
        
}quec_driver_mutex_type_e;
  
typedef enum
{
    IOCTL_NONE_CMD=-1,
        
	IOCTL_WRITE_DCD_CMD=0,		  	//assert dcd---(active)
	IOCTL_READ_DCD_CMD,				//get dcd state
	
	IOCTL_WRITE_RI_CMD,             //set ri assert RI
	IOCTL_READ_RI_CMD,			    //get ri state

    IOCTL_UPDATE_DTR_CMD,            //cmux used
	IOCTL_READ_DTR_CMD,			    //get dtr state
	
	IOCTL_WRITE_RTS_CMD,
	IOCTL_READ_RTS_CMD,

    IOCTL_UPDATE_CTS_CMD,           //cmux used      
	IOCTL_READ_CTS_CMD,
	
    //todo
    
	IOCTL_CMD_MAX,                    //invalid ioctl cmd
}quec_ioctl_cmd_type_e;

//typedef  int   quec_ioctl_default_type;  //default io_ctl param
typedef enum 
{
    QUEC_PIN_LEVEL_LOW=0,
    QUEC_PIN_LEVEL_HIGH
}quec_pin_level_value_e;
typedef union 
{
	//quec_ioctl_default_type pin_state;  //dcd,ri state	
	quec_pin_level_value_e  pin_level;
}quec_ioctl_param;

typedef enum 
{
    
    QUEC_PIN_FALLING_EDGE=0,
    QUEC_PIN_RISING_EDGE
}quec_pin_edge_direction_e;
    
typedef enum 
{
    QUEC_USB_NET_NONE=-1,
    QUEC_USB_NET_RMNET=0,
    QUEC_USB_NET_ECM,
    QUEC_USB_NET_MBIM,
    QUEC_USB_NET_RNDIS,
    QUEC_USB_NET_MAX
}quec_usb_net_type_e;

#ifdef QUEC_ASR_ATCMD_TAU_TYPE_SUPPORT
typedef enum 
{
    QUEC_TAU_TYPE_MIN,
    QUEC_TAU_TYPE_COMBINED_TA_LA_UPDATING,                   //medcr 75=0
    QUEC_TAU_TYPE_COMBINED_TA_LA_UPDATING_WITH_IMSI_ATTACH,  //medcr 75=2
    QUEC_TAU_TYPE_PERIODIC_UPDATING,                         //medcr 75=3
    QUEC_TAU_TYPE_MAX
}quec_tau_type_e;
#endif
#define QUEC_GPIO_GROUP_NUM  32

#ifdef __cplusplus
} /*"C" */
#endif

#endif

