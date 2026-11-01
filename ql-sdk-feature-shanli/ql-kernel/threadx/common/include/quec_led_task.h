/**  @file
  quec_led_task.h

  @brief
  This file is used to process led status.

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
------------     -------     --------------------------------------------------
14/11/2019        Fitz   	 Init version
=================================================================*/

#ifndef QUEC_LED_TASK_H
#define QUEC_LED_TASK_H



/*===========================================================================
 * include files
 ===========================================================================*/
#include "quec_include.h"

#if defined(QUEC_LED_TASK_SUPPORT)

/*===========================================================================
 * Macro Definition
 ===========================================================================*/


/*===========================================================================
 * struct,enum definition
 ===========================================================================*/
#if defined(__QUEC_OEM_VER_ALLIED__)
enum quec_allied_net_mode_status
{
	QUEC_ALLIED_NET_MODE_STATUS_PWR_ON = 0x01,
	QUEC_ALLIED_NET_MODE_STATUS_RECV_AT_WITHIN_10S = 0x02,
	QUEC_ALLIED_NET_MODE_STATUS_NOT_RECV_AT_AFTER_10S = 0x03,
	QUEC_ALLIED_NET_MODE_STATUS_TCP_FTP_TRANSMIT = 0x04,
	QUEC_ALLIED_NET_MODE_STATUS_NORMAL_HIGH = 0x05,
};
#endif

/*===========================================================================
 * Global Variable
 ===========================================================================*/


/*===========================================================================
 * extern
 ===========================================================================*/
extern QuecOSStatus quec_led_task_init(void);
extern void quec_led_reset_status(void);

extern void quec_led_task_run(void);
extern void quec_led_task_stop(void);

#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610
char quec_read_qpwmcfg_mode(void);
void quec_set_qpwmcfg_mode(char mode);
void quec_netmode_init(void);
#endif

#if defined(__QUEC_OEM_VER_ALLIED__)
QuecOSStatus quec_allied_netmode_queue_release(uint8 netmode_msg);
QuecOSStatus quec_allied_net_mode_task_init(void);
#endif


#endif

#endif


