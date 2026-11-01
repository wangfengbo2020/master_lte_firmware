/*--------------------------------------------------------------------------------------------------------------------
(C) Copyright 2006, 2007 Marvell DSPC Ltd. All Rights Reserved.
-------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code (“Material? are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel’s prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/

/************************************************************************/
/*                                                                      */
/* Title: ripc package configuration file                                */
/*                                                                      */
/* Filename:  ripc.h                                              */
/*                                                                      */
/* Authors: Adi Dayan                                                   */
/*                                                                      */
/* Target, subsystem: Common Platform, HAL                              */
/************************************************************************/

#ifndef _RIPC_H_
#define _RIPC_H_


#define RIPC_SUCEESS 0
#define RIPC_FAILURE -1


// The RIPC registers offset
#define RIPC_STATUS_REG                 0x0000  // Status Register
#define RIPC_AP_INT_REQ                 0x0004  // AP INT REQ Register
#define RIPC_CP_INT_REQ                 0x0008  // CP INT REQ Register
#define RIPC_MSA_INT_REQ                0x000C  // MSA INT REQ Register


#define RIPC_REGISTER_BASE_ADDRESS_0   	0xD403D000
#define RIPC_REGISTER_BASE_ADDRESS_1   	0xD403D100
#define RIPC_REGISTER_BASE_ADDRESS_2   	0xD403D200
#define RIPC_REGISTER_BASE_ADDRESS_3   	0xD403D300




#define RIPC_MAX_NUM 4

#define RIPC_INT_SRC        			INTC_IPC_SRV0_CP

#define RIPC_REG_WRITE(ripc_no,reg,wval) \
        ( (* ( (volatile UINT32*)(RIPC_REGISTER_BASE_ADDRESS_0 + (ripc_no)*0x100 +(reg)) ) ) = wval);

#define RIPC_REG_READ(ripc_no,reg,rval) \
        rval = (* ( (volatile UINT32*)(RIPC_REGISTER_BASE_ADDRESS_0 + (ripc_no)*0x100 + (reg)) ) );

extern UINT32 ripc_read_status(int ripc_no);

extern void Release_RIPC(int ripc_no);

extern void ripc_interrupt_set(int ripc_no);

extern void ripc_interrupt_clear(int ripc_no);

extern int Get_RIPC(int ripc_no,int timeout);
extern void Release_RIPC_ustica(int ripc_no);
extern int Get_RIPC_ustica(int ripc_no,int timeout);




#endif

