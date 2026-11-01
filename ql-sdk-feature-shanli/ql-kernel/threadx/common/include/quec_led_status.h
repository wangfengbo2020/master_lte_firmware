/**  @file
  quec_led_stauts.h

  @brief
  This file is used to get module status for net led.

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

#ifndef QUEC_LED_STAUTS_H
#define QUEC_LED_STATUS_H


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
    NOT_REGISTERED,
    REGOSTERED_ON_2G,
    REGOSTERED_ON_3G,
    REGOSTERED_ON_4G,
}quec_led_network_type;

/*===========================================================================
 * Global Variable
 ===========================================================================*/


/*===========================================================================
 * extern
 ===========================================================================*/
bool quec_led_get_sim_insert_status(void);
bool quec_led_get_sim_initializing_status(void);
bool quec_led_get_pin_lock_status(void);
bool quec_led_get_cpin_ready_status(void);
bool quec_led_get_searching_status(void);
bool quec_led_get_camp_on_cell_status(void);
bool quec_led_get_registering_status(void);
uint8 quec_led_get_registered_status(void);
bool quec_led_get_call_status(void);
void quec_led_set_call_status(bool call_status);
bool quec_led_get_data_transmit_status(void);
bool quec_led_get_socket_create_status(void);
bool quec_led_get_socket_connect_status(void);
bool quec_led_get_pdp_activing_status(void);
bool quec_led_get_pdp_deactiving_status(void);
bool quec_led_get_pdp_status(void);
bool quec_led_get_netdev_status(void);
bool quec_led_get_ppp_status(void);
bool quec_led_get_netif_status(void);


#endif

#endif


