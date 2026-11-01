/**  @file
  quec_vsim_include.h

  @brief
  This file is used to define the vsim handler for different Quectel Project.

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
------------     -------     -------------------------------------------------------------------------------
10/12/2019        Jensen     Init version
=================================================================*/


#ifndef _QUEC_VSIM_INCLUDE_H
#define _QUEC_VSIM_INCLUDE_H

/*> include header files here*/

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifdef __cplusplus
extern "C" {
#endif

#if QUEC_VSIM_ENABLE

/*========================================================================
 *  Macro Definition
 *========================================================================*/



/*========================================================================
 *  Enumeration Definition
 *========================================================================*/
 


/*========================================================================
 *  Type Definition
 *========================================================================*/



/*========================================================================
 *  function declaration
 *========================================================================*/
/*========================================================================
* FUNCTION quec_get_vsim_profile_flash_addr
*
* DESCRIPTION
*   This function return the vsim profile address of flash based on byte
*
* DEPENDENCIES
*   None
*
* PARAMETERS
*	<partition_property>: 0 is main partition, 1 is backup partition
*
* RETURN VALUE
*   the flash address of the specified partition, return 0 if <partition_property> is invalid
*	
* SIDE EFFECTS
*   None
==========================================================================*/
unsigned int quec_vsim_get_profile_flash_addr(unsigned char partition_property);

/*========================================================================
* FUNCTION quec_vsim_get_flash_blk_size
*
* DESCRIPTION
*   This function return the block size of flash based on byte
*
* DEPENDENCIES
*   None
*
* PARAMETERS
*   None
*
* RETURN VALUE
*   the block size of flash based on byte
*	
* SIDE EFFECTS
*   None
==========================================================================*/
unsigned int quec_vsim_get_flash_blk_size(void);

/*========================================================================
* FUNCTION quec_vsim_get_flow_rate
*
* DESCRIPTION
*   This function return the floa rate of sent and received
*
* DEPENDENCIES
*   None
*
* PARAMETERS
*	<rx_bytes>: to read the received bytes
*	<tx_bytes>: to read the sent bytes
*
* RETURN VALUE
*   None
*	
* SIDE EFFECTS
*   None
==========================================================================*/
void quec_vsim_get_flow_rate(unsigned long long *rx_bytes, unsigned long long *tx_bytes);

extern unsigned short int simcardStatus(void);
extern unsigned short int setVsimOrUsim(unsigned short int simType);

#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif

