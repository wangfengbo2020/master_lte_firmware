/**
 ******************************************************************************
 * @file    quec_event_def.h
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


#ifndef _QUEC_EVENT_DEF_H
#define _QUEC_EVENT_DEF_H

typedef enum {

	EVENT_NONE = -1,

	/*========================================================================
	 *	OS Event Definitions
	 *========================================================================*/

	EVENT_OS_TASK_DELETE,

	/*========================================================================
	 *	Network Event Definitions
	 *========================================================================*/

	EVENT_NET_REGISTER,
	EVENT_NET_PDP_ACT,
	EVENT_NET_NIC_BIND,
	
	/*========================================================================
	 *	Socket Event Definitions
	 *========================================================================*/


	/*========================================================================
	 *	SIO WM Event Definitions
	 *========================================================================*/

	EVENT_SIO_TX_WM_LOW,
	EVENT_SIO_TX_WM_HIGH,
	EVENT_SIO_TX_WM_EMPTY,
	EVENT_SIO_RX_WM_LOW,
	EVENT_SIO_RX_WM_HIGH,
	EVENT_SIO_RX_WM_EMPTY,

	/*========================================================================
	 *	URC Event Definitions
	 *========================================================================*/


	/*========================================================================
	 *	FOTA WM Event Definitions
	 *========================================================================*/
	 
    EVENT_FOTA_RX_WM_LOW,
    EVENT_FOTA_RX_WM_HIGH,

	/*========================================================================
	 *	default pdp active success event definitions
	 *========================================================================*/
	EVENT_PDP_DEFAULT_ACT,


	EVENT_URC_SEND,

	EVENT_QUECTHING_AUTO_REGISTER, //重新注网之后quecthing自启动
	EVENT_PWR_DOWN,
	EVENT_PWR_RESET,
	EVENT_CHECK_URC_REPORT,
	EVENT_MAX	/* the max number of the event to be registered */
} quec_event_t;

#define REGISTER_MAX_NUM_FOR_EACH_EVENT	20	/* the max number that is allowed to be registered of every single event */


#endif

