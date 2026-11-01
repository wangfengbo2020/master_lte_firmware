 /**  @file
  quec_atcmd_para_init.h

  @brief
  This file is used to define the short message at command handler for different Quectel Project.

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
12/03/2018        Tery         Init version
=================================================================*/

#ifndef __QUEC_ATCMD_PARA_INIT_H__
#define __QUEC_ATCMD_PARA_INIT_H__

#include "quec_include.h"

void quec_atcmd_para_init(void);
#if QUEC_DUAL_SIM_SUPPORT
extern void quec_get_sim_cfun_status(char simid);
#endif

#endif  //#ifndef __QUEC_ATCMD_PARA_INIT_H__