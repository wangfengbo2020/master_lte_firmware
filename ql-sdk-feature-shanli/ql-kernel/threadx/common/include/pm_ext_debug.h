/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/************************************************************************/
/*  COPYRIGHT (C) 2002 Intel Corporation.                               */
/*                                                                      */
/*  This file and the software in it is furnished under                 */
/*  license and may only be used or copied in accordance with the terms */
/*  of the license. The information in this file is furnished for       */
/*  informational use only, is subject to change without notice, and    */
/*  should not be construed as a commitment by Intel Corporation.       */
/*  Intel Corporation assumes no responsibility or liability for any    */
/*  errors or inaccuracies that may appear in this document or any      */
/*  software that may be provided in association with this document.    */
/*  Except as permitted by such license, no part of this document may   */
/*  be reproduced, stored in a retrieval system, or transmitted in any  */
/*  form or by any means without the express written consent of Intel   */
/*  Corporation.                                                        */
/*                                                                      */
/* Title: Power Management external debug Header File                   */
/*                                                                      */
/* Filename: pm_ext_debug.h                                             */
/*                                                                      */
/* Author:   Raviv Levi                                                 */
/*                                                                      */
/* Project, Target, subsystem: Tavor, Arbel, HOP     			*/
/*									*/
/* Remarks: -                                                           */
/*    									*/
/* Created: 5/2/2006                                                    */
/*                                                                      */
/* Modified: Jan 2007 - move to be general PM log			*/
/*	(file moved from hop/pm/inc !!)					*/
/*									*/
/************************************************************************/


#if !defined _PM_EXT_DEBUG_H_
    #define _PM_EXT_DEBUG_H_

	// definition of the PM-log struct, enum
    #include "pm_dbg_types.h"

    // Current internal logger.    
    void PMLog(PM_EventTypeE event, UINT32 eventData);
	void PMICATLogSend(void);
	void pmLogInit(void);
	void PMLogStop(void);

	// Internal logger definition.
	//#define PM_INT_LOGGER_LOG(EVENTid,EVENTdATA) PMLog(EVENTid,EVENTdATA)
#if !defined (EDEN_1928) && !defined (NEZHA3_1826)
    //#if defined PM_DEBUG_MODE_ENABLED
	#if 0
        // Choose event logger.
        #if defined PM_EXT_DBG_XDA
            // Check that XDA's compilation flag is defined.
            #if !defined(MIPS_TEST)
                #error the MIPS_TEST flag must be defined to allow XDA use
            #endif //MIPS_TEST
            // XDA API that outputs the event.
            #define PM_EXT_DBG_EVENT_SEND(EVENTid,EVENTdATA) WriteMIPStest(EVENTid)
        #else
            #if defined PM_EXT_DBG_ISPT
                #error ISPT not supported yet !
                // ISPT function that outputs the event.
                #define PM_EXT_DBG_EVENT_SEND(EVENTid,EVENTdATA) (EVENTid)
            #else
                #define PM_EXT_DBG_EVENT_SEND(EVENTid,EVENTdATA) PMLog(EVENTid,EVENTdATA) 
            #endif //PM_EXT_DBG_ISPT    
        #endif //PM_EXT_DBG_XDA
	#else
	#define PM_EXT_DBG_EVENT_SEND(EVENTid,EVENTdATA) 
    #endif //PM_DEBUG_MODE_ENABLED
#else
    #define PM_EXT_DBG_EVENT_SEND(EVENTid,EVENTdATA)
#endif
#endif  /* _PM_EXT_DEBUG_H_ */
