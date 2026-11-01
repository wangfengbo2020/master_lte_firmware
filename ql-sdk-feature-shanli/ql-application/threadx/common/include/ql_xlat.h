/**  
  @file
  quec_nw.h

  @brief
  This file provides the definitions for nw, and declares the 
  API functions.

*/
/*============================================================================
  Copyright (c) 2017 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
 =============================================================================*/
/*===========================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.


WHEN        WHO            WHAT, WHERE, WHY
----------  ------------   ----------------------------------------------------
01/09/2020  Nebula.li      create
=============================================================================*/

#ifndef __QL_XLAT_H__
#define __QL_XLAT_H__
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "ip6_addr.h"

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************
 * Function: ql_set_clat
 *
 * Description: enable clat and config clat ipv6 prefix.
 *
 * Parameters:
 * enable        [BOOL]         1:enable clat 
 *                              0:disable clat
 *
 * *ip6_addr       [ip6_addr_t]   clat ipv6 prefix addr
 *                                 Big-Endian
 *
 * prefix_len      [char]         prefix length:0/32/40/56/64/96,length must keep with the clat profix addr
 *
 * Return:
 *  0           success
 *  other       error code
 *
 example:
 ip6_addr_t  ip6_addr_set={0x64ff9b00,0,0,0};
 ql_set_clat(1, &ip6_addr_set, 96);
 *****************************************************************/

int ql_set_clat(BOOL enable,ip6_addr_t *ip6_addr,char prefix_len);

/*****************************************************************
 * Function: ql_get_clat_prefix_len
 *
 * Description: get the ipv6 prefix length of clat configuration.
 *
 * Parameters:
 * NULL
 *
 * Return:
 *  0/32/40/56/64/96    success
 *  other               error code
 *
 *****************************************************************/
int ql_get_clat_prefix_len(void);

/*****************************************************************
 * Function: ql_get_clat_prefix_addr
 *
 * Description: get the ipv6 prefix address of clat configuration.
 *
 * Parameters:
 * *ip6_predix_addr      [ip6_addr_t]     get the value of the ipv6 prefix address of clat configuration.
 *                                        Little-Endian
 * Return:
 *  0           success
 *  other       error code
 *
 *****************************************************************/
int ql_get_clat_prefix_addr(ip6_addr_t * ip6_predix_addr);

/*****************************************************************
 * Function: ql_clat_is_enable
 *
 * Description: get clat status.
 *
 * Parameters:
 * NULL
 * Return:
 *  0           clat disable
 *  1           clat enable
 *  other       error code
 *
 *****************************************************************/
BOOL ql_clat_is_enable(void);


#ifdef __cplusplus
}
#endif


#endif


