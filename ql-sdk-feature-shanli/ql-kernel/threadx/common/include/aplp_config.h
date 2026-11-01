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
* Filename: aplp_config.h
*
* Programmers:  Kiril Serebnik (ska), Yoel Lavi (yoell)
*
* Description:  Configures the APLP package
**********************************************************************/
#ifndef APLP_CONFIG_H
#define APLP_CONFIG_H


/**********************************************************************
*    When defined, MSR debug functions will be enabled
**********************************************************************/

/**********************************************************************
*    When defined, MSR functionality will be tuned to LAB work,
* otherwise to APLP standalone validation
**********************************************************************/
#define RUNNING_WITH_PLP


// Dual mode rf is defined for new configuration change
#define SILICON_VERSION_B0
// This switch is intended to send synth params when not in SA variant.
// Need to be checked in the lab before removing

/*********************************************************************
* For Yarden build in Rel 6...modifications in setup complete ack
*********************************************************************/




/*********************************************************************
* If cillision error is supported by msa during CM patterns report
*********************************************************************/
#define COLLISION_ERR_SUPPORTED

/*********************************************************************
*  This patch fixed detected request while P-CCPCH for SFN-CFN is still
*  active (transient state after releasing DPCH)
*********************************************************************/


/*-------- Necessary automatic settings updating ----*/
#ifndef APLP_DEBUG
#define APLP_DEBUG
#endif

/*********************************************************************
* If define than fill plUlDataSync_ts.powerLeft[all cells] with 30.
*********************************************************************/
//#define POWER_LEFT_DEFUALT_VALUE  - not used anymore. Moved to plAmGetDevSwitch_2.
// When development switch 2 is enabled, default values are filled in

#endif  /* APLP_CONFIG_H */
