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

#ifndef _FDI_CFG_
#define _FDI_CFG_

#include "mmap.h"
/* this file is a default fdi_cfg.h - in case doesnt exist in target\inc    */

/******************************** FDI Flags *********************************/

/* FDI flash width (16/32) - when undefined, assumes 16 bit wide */
/* DISABLE THIS SWITCH TO WORK WITH MCP1 */
#if !defined(FDI_INTERNAL_FLASH) && !defined (BSP_ZOARMONV1) && !defined (BSP_MATHISV1) 
#define FDI_USES_32BIT_FLASH  // paired flash
#endif

/* Flash internal write buffer - for better write performance
 * represented in bytes, must be a power of 2
 * flash with no internal write buffer should be set to 0 */
#if !defined(FDI_INTERNAL_FLASH)
#define FLASH_DATA_BUFFER_SIZE 64
#else
#define FLASH_DATA_BUFFER_SIZE 0 /*Internal flash*/
#endif

#ifdef FDI_USES_32BIT_FLASH
#define FDI_BUFFER_SIZE    (FLASH_DATA_BUFFER_SIZE<<1) // paired flash
#else
#define FDI_BUFFER_SIZE    FLASH_DATA_BUFFER_SIZE
#endif // FDI_USES_32BIT_FLASH

/* when FDI init failes, user might want to stop and save the memory dump
 * before the FDI formats itself automatically */
//#define STOP_ON_FDI_INIT_FAIL

//#define UPGRADE_HERMON_FDI_NVRAM

/* FAT12 file system */
#define NUM_8_PARMS_FDI_CFG ((7 * 2048) + 251)   /* approx 7.1 MB -1024*/

// No DAV capabilities are needed, do not allocate the DAV volume, eliminate the DAV support code
#define FDI_NO_DAV_VOLUME

#endif // _FDI_CFG_

