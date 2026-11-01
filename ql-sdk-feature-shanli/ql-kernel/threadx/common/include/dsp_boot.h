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

#ifndef _DSP_BOOT_H_
#define _DSP_BOOT_H_
#include "bsp_config.h"
/* DSP boot defines/macros*/
#if defined(MSA_INIT)
#if  defined(TTC_DSP_INIT)

/* DSP start address for TTC is configurable through COEL_APB_MSA_BOOT */
#define DSP_BOOT_ADDRESS_REG  0xD4070000
#define DSP_L2_SRAM_ADDRESS   0xd1e00000
//#define msaCode
/* DSP DDR address reference */
#define DSP_DDR_ADDRESS 0xd0000000
/* reserved start DDR address for DSP scatter file*/
extern void Image$$DDR_DSP_RO$$Base;/* Exec Address of DSP RO region			*/
extern void Image$$DDR_DSP_RO$$ZI$$Limit;/* Exec Address of DSP RO region			*/

#if defined (DSP_BOOT_FROM_DDR)
#define DSP_START_ADDRESS ((UINT32)&Image$$DDR_DSP_RO$$Base) | DSP_DDR_ADDRESS
#else
#define DSP_DDR_IMAGE_DSP_INIT_SIZE 0x50000 /* 320K */
#define DSP_DDR_IMAGE_START_ADDR  (UINT32)&Image$$DDR_DSP_RO$$Base
#define DSP_DDR_IMAGE_END_ADDR    (DSP_DDR_IMAGE_START_ADDR + DSP_DDR_IMAGE_DSP_INIT_SIZE)
#define DSP_START_ADDRESS 0xd1e4c400 // was 0xd1e44c00
#endif
#else /*Hermon*/
#define DSP_START_ADDRESS (bspMsaRunFromExternal()? XSCALE_SRAM : MSA_FLASH_BASE)
#define DSP_BOOT_ADDRESS_REG  0x42900078
#endif /* TTC_DSP_INIT */


#else /* APPS / Arbel */
#undef DSP_BOOT_ADDRESS_REG
#endif /*MSA_INIT*/

/*DSP boot API function*/
void MSAPhase1Init(void);


#endif /*_DSP_BOOT_H_*/


