/**  @file
  quec_led_cfg_tbl.h

  @brief
  This file is used to process net led config table.

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

#ifndef QUEC_LED_CFG_TBL_H
#define QUEC_LED_CFG_TBL_H


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
typedef enum
{
    NET_TYPE_NOT_REGISTERED,
    NET_TYPE_2G,
    NET_TYPE_3G,
    NET_TYPE_4G,
    NET_TYPE_USER_DEF,
    NET_TYPE_MAX,
}quec_led_pwm_type_t;

typedef struct 
{
    uint16 cycle;  /* pwm cycle level time */
    uint8 ratio;   /* pwm high level time */
}quec_led_net_type_t;

typedef struct 
{
	uint8 gpio_num;  /* number of gpio net led use*/
	uint8 pwm_num;	 /* number of pwm dev net led use */
	uint8 priority;  /* save net led status priority */
	quec_led_net_type_t net_type[NET_TYPE_MAX]; /* save diffirent config for 2G,3G,4G or user defined */
}quec_led_cfg_t;

typedef enum
{
	SIM_NOT_INSERT = 0,
	SIM_INITIALIZING,
	SIM_PIN_LOCK,
	SIM_CPIN_READY,    
	SEARCHING,
	CAMP_ON_CELL = 5,
	REGISTERING,
	STANDBY,
	PDP_ACTIVING,
	PDP_ACTIVED,
	SOCKET_SET_UP = 10,
	DATA_TRANSMIT,
	PDP_DEACTIVING,
	DIALING,
	NET_LED_STATUS_MAX,
}quec_module_status; 

/*===========================================================================
 * Global Variable
 ===========================================================================*/


/*===========================================================================
 * extern
 ===========================================================================*/
extern quec_led_cfg_t quec_led_cfg_tbl[NET_LED_STATUS_MAX];

extern int quec_led_cfg_tbl_set(uint8 index, uint8 gpio_num, uint8 pwm_num, uint8 priority, uint8 network_type, uint16 cycle, uint8 ratio);
extern int quec_led_cfg_tbl_get(void);

#endif
#endif

