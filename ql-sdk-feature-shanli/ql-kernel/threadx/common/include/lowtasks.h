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


#ifndef LOWTASKS_MODULE_H
#define LOWTASKS_MODULE_H

typedef UINT32 lowTaskEventHandler_t; /* will give the possebility to switch to 64 bits for 64 event instead of 32 in needed.*/
typedef void (*LowEventFuncPtr)(lowTaskEventHandler_t);/*the bind function return the event for the user use*/

#define  NUM_OF_HANDLER_EVENTS (sizeof(lowTaskEventHandler_t) * 8 )
#define  LOWEST_EVENT_PRIORITY 0xFF   /* 0x00 -Highest priority , 0xFF - lowest priority*/

void init_lowEventHandleTask(void);
/* NOTE: Pay attention , the bineded function should be short with less as possible
 *        calls to function out side the binded function - mind that the bineded function
 *        is being called in the context of the lowEventHandleTaskEntry
 *        with LOW_EVENT_HANDLE_TASK_STACK_SIZE*/
lowTaskEventHandler_t LowEventBind(LowEventFuncPtr functionEntry,UINT8 priority);
/**********************************************************************************/
void LowEventUnBind(lowTaskEventHandler_t event);
void LowEventActivate(lowTaskEventHandler_t event);

#endif // LOWTASKS_MODULE_H
