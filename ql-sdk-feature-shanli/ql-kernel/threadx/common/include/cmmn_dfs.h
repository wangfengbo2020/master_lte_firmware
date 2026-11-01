/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code ("Material") are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel's prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/

/**********************************************************************
 *
 * Filename: cmmn_dfs.h
 *
 * Programmers: Kiril Serebnik (ska)
 *
 * Description: Temprorary file that contains system-wide definition.
 *				Must be replaced in the future with the real definitions file.
 *
 * --------------------------------------------------------------------
 * Revision History
 *
 * Date         Who        Version           Description
 * --------------------------------------------------------------------
 * 14-Jan-2001  ska        0.01               File Created
 **********************************************************************/
#ifndef CMMN_DFS_H
#define CMMN_DFS_H

#include "global_types.h"
#if defined(HL_LTG)
#include "pl_drat_nvm.h"
#else
#include "pl_am_nvm.h"

#endif
#define VOID_PTR    void*
#define DOUBLE      double
//#ifdef MAX_VALUE
//#define MAX_VALUE(a,b)     ((a>=b)?a:b)
//#endif
#define   FOREVER   1

#if !defined (HL_LTG)

// Any diag traces that appears between the IF_EXT_TRACING_ENABLED() and the 
// END_IF_EXT_TRACING_ENABLED() macros will be sent only if the APLP_ENABLE_EXTENDED_TRACING 
// compilation flag is enabled AND the plwAmIsExtendedTracingEnabled() function returns true.  

#ifdef APLP_ENABLE_EXTENDED_TRACING
    #define IF_EXT_TRACING_ENABLED()      if((plwAmIsExtendedTracingEnabled())) {  
#else
    #define IF_EXT_TRACING_ENABLED()      if(0) {   // this is equivalent to #if 0 - since the optimizer removes this code.   
#endif //APLP_ENABLE_EXTENDED_TRACING   

#define     END_IF_EXT_TRACING_ENABLED()    }

#endif

#endif /* CMMN_DFS_H */

