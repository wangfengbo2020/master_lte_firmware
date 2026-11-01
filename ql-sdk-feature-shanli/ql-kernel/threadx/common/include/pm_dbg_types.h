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
/* Title: Power Management types Header File                            */
/*                                                                      */
/* Filename: pm_dbg_types.h                                             */
/*                                                                      */
/* Author:   Raviv Levi                                                 */
/*                                                                      */
/* Project, Target, subsystem: Tavor, Arbel, HOP     			*/
/*									*/
/* Remarks: This file contains types used by the entire communication   */
/*          power management system                                     */
/*    									*/
/* Created: 1/1/2006                                                    */
/*                                                                      */
/* Modified:  Jan 2007 - make it pm_dbg_types.h and include debug data  */
/*			  for all PM platforms				*/
/*	(file moved from hop/pm/inc !!)					*/
/*									*/
/************************************************************************/


#ifndef _PM_DBG_TYPES_H_
#define _PM_DBG_TYPES_H_

//#include "pm_config.h"
#include "powerManagement.h"

// Should be replaced by TimeIn32KhzUnit after TM integration.
typedef UINT32 PM_TimeIn32KHzUnitsT;

// The PM internal log size (event logging).
#define PM_EVENT_LOG_SIZE 256


// Log events definitions (currently numbers 100-150 are free for XDA).
//ICAT EXPORTED ENUM
typedef enum {
	PM_EXT_DBG_EVENT_EMPTY			= 0,
	PM_EXT_DBG_EVENT_GENERAL_PURPOSE = 99,	// for debug purposes, general event to
											// track something while debug (not to be left in code permanently)!
    PM_EXT_DBG_EVENT_D2_EXIT		=100, //100
	PM_EXT_DBG_EVENT_C1_EXIT			, //101
	PM_EXT_DBG_EVENT_C1_GATED_EXIT		, //102
    PM_EXT_DBG_EVENT_TM_GET_NEAREST     , //103
    PM_EXT_DBG_EVENT_TM_SUSPEND         , //104
    PM_EXT_DBG_EVENT_TM_SYNCH_AFTER     , //105
    PM_EXT_DBG_EVENT_TM_NU_TICK         , //106
    PM_EXT_DBG_EVENT_TM_EXT_TICK        , //107
    PM_EXT_DBG_EVENT_TM_SKIP_OS_TICK    , //108
    PM_EXT_DBG_EVENT_TM_SUSPEND_ENABLE  , //109
    PM_EXT_DBG_EVENT_TM_SUSPEND_DISABLE , //110
    PM_EXT_DBG_EVENT_TM_TRIGGER_ERROR   , //111
    PM_EXT_DBG_EVENT_TICK_FROM_SYNCH    , //112
    PM_EXT_DBG_EVENT_TICK_FROM_TRIGGER  , //113
    PM_EXT_DBG_EVENT_TM_HW_TIMER_SET    , //114
    PM_EXT_DBG_EVENT_OS_TIMER_EXPIRE    , //115
    PM_EXT_DBG_EVENT_TM_TICK_SUSPENDED  , //116
    PM_EXT_DBG_EVENT_ACTIVATE_NU_HISR   , //117
    PM_EXT_DBG_EVENT_ACTIVATE_GKI_HISR  , //118
    PM_EXT_DBG_EVENT_TIMER_DEACTIVATE   , //119
    PM_EXT_DBG_EVENT_TIMER_CONFIGURE    , //120
    PM_EXT_DBG_EVENT_TIMER_ACTIVATE     , //121
    PM_EXT_DBG_EVENT_TIMER_STATUS_CLEAR , //122
    PM_EXT_DBG_EVENT_TIMER_TCMR_SET     , //123
    PM_EXT_DBG_EVENT_TIMER_STATUS_READ  , //124
    PM_EXT_DBG_EVENT_TIMER_TIER_CLEAR   , //125
    PM_EXT_DBG_EVENT_TIMER_TMR_SET      , //126
    PM_EXT_DBG_EVENT_TIMER_TCCR_SET     , //127
    PM_EXT_DBG_EVENT_TIMER_TIER_SET     , //128
    PM_EXT_DBG_EVENT_RM_PREVENT_D2      , //129
    PM_EXT_DBG_EVENT_AAM_PREVENT_D2     , //130
    PM_EXT_DBG_EVENT_GP_FLAG_1          , //131
    PM_EXT_DBG_EVENT_AAM_D2_TIMER_WAKEUP, //132
	PM_EXT_DBG_EVENT_AAM_D2_OWN_WAKEUP  , //133
	PM_EXT_DBG_EVENT_AAM_MANAGE_BUSY    , //134
	PM_EXT_DBG_EVENT_AAM_MANAGE_FREE    , //135
	PM_EXT_DBG_EVENT_AAM_ALLOW_D2       , //136
	PM_EXT_DBG_EVENT_AAM_AA_FORBID_D2   , //137
	PM_EXT_DBG_EVENT_AAM_TM_FORBID_D2   , //138
	PM_EXT_DBG_EVENT_AAM_APP_TM_D2		, //139
	PM_EXT_DBG_EVENT_AAM_OST_TM_D2		, //140
	PM_EXT_DBG_EVENT_RM_TCU_ALLOC       , //141
	PM_EXT_DBG_EVENT_RM_TCU_FREE        , //142
	PM_EXT_DBG_EVENT_RM_SCK_ALLOC       , //143
	PM_EXT_DBG_EVENT_RM_SCK_FREE        , //144
	PM_EXT_DBG_EVENT_RM_ALLOW_D2        , //145
	PM_EXT_DBG_EVENT_RM_FORBID_D2       , //146
	PM_EXT_DBG_EVENT_RM_ALLOW_C1_GATED  , //147
	PM_EXT_DBG_EVENT_TCU_D2_PREPARE     , //148
	PM_EXT_DBG_EVENT_TCU_D2_RECOVER     , //149
	PM_EXT_DBG_EVENT_CPA_D2_PREPARE     , //150
	PM_EXT_DBG_EVENT_CPA_D2_RECOVER     , //151
	PM_EXT_DBG_EVENT_CPA_D2_WAKEUP	    , //152
	PM_EXT_DBG_EVENT_D2_WAKEUP_TIMER	, //153
	PM_EXT_DBG_EVENT_GSM_WAKEUP_SWI		, //154
	PM_EXT_DBG_EVENT_GSM_SLEEP_SWI		,// 155
	//////////////////////////////////////////////DDR
	PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_HIGH_FREQ_ACK_WHILE_RELINQUISH_HIGH_IS_PENDING,
	PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_REQUEST_ACK,
	PM_EXT_DBG_EVENT_CHANGED_TO_SYSTEM_IN_REG_RUNNING_MODE_AND_SEND_REQ,
	PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_REQUEST_ACK_WHILE_HIGH_IS_PENDING,
	PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_HIGH_FREQ_ACK,
	PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_HIGH_FREQ_ACK_AND_SEND_REQ,
	PM_EXT_DBG_EVENT_CHANGED_TO_SYSTEM_IN_REG_RUNNING_MODE,
	PM_EXT_DBG_EVENT_AC_IPC_INTERRUPT_HANDLER,
	PM_EXT_DBG_EVENT_260_REL_ACK,
	PM_EXT_DBG_EVENT_CHANGED_SYSTEM_IN_HIGH_FREQ_MODE,
	PM_EXT_DBG_EVENT_DDR_REG_REQ,
	PM_EXT_DBG_EVENT_DDR_REG_RELINQUISH,
	PM_EXT_DBG_EVENT_DDR_REG_REQ_AND_RELINQUISH,
	PM_EXT_DBG_EVENT_DDR_HF_REQ,
	PM_EXT_DBG_EVENT_DDR_HF_RELINQUISH,
	PM_EXT_DBG_EVENT_DDR_HF_REQ_AND_RELINQUISH,

	PM_EXT_DBG_EVENT_DDR_STATUS_FORBID_D2,
	//////////////////////////////////////////////DDR

	PM_EXT_DBG_EVENT_RM_ALLOC       ,
	PM_EXT_DBG_EVENT_RM_FREE        ,

	PM_EXT_DBG_EVENT_D2_ENTRY,
	PM_EXT_DBG_EVENT_C1_ENTRY,
	PM_EXT_DBG_EVENT_C1_GATED_ENTRY,
	PM_EXT_DBG_EVENT_D0CS_ENTRY,
	PM_EXT_DBG_EVENT_D0CS_EXIT,
	// BRN
	PM_EXT_DBG_EVENT_VCTCXO_RELINQUISH,
	PM_EXT_DBG_EVENT_VCTCXO_REQUEST,
	PM_EXT_DBG_EVENT_DDR_LPM_DONE,
	PM_EXT_DBG_EVENT_POUT_DISABLE,
	PM_EXT_DBG_EVENT_POUT_ENABLE,
	PM_EXT_DBG_EVENT_FREQ_CHANGE_HIGH,
	PM_EXT_DBG_EVENT_FREQ_CHANGE_LOW,
	PM_EXT_DBG_EVENT_FREQ_CHANGE_USER,
	PM_EXT_DBG_EVENT_FREQ_CHANGE_START,
	PM_EXT_DBG_EVENT_FREQ_CHANGE_DONE,
	PM_EXT_DBG_EVENT_FREQ_CHANGE_GET_FREQ,
	PM_EXT_DBG_EVENT_DVFM_TABLE_UPDATE,
	PM_EXT_DBG_EVENT_LPM_DECISION,
	PM_EXT_DBG_EVENT_SRAM_MEMORY_ERRORS_COUNT,
	PM_EXT_DBG_WAKEUP_SRC,
	PM_EXT_DBG_WAKEUP_SRC_NOTREGISTER,
	PM_EXT_DBG_EVENT_NO_DATA	   = 1500, /* indicates that no data is send with the event
												(and forces the enum to be treated as UINT32) */
	PM_EXT_DBG_DATA_FAKE_D2		   =0x2000000		, //
    PM_EXT_DBG_DATA_REAL_D2		   =0x4000000		  // we add to this bit hte wakeup event register
														// - relevant bits are 0-19
}PM_EventTypeE;

// Log entry
//ICAT EXPORTED STRUCT
typedef struct  {
    PM_TimeIn32KHzUnitsT timeStamp;
    PM_EventTypeE        event;
    UINT32               data;
}PM_TimeStampLogEnteryS;

// Log structure (holds the log and log related variables)
//ICAT EXPORTED STRUCT
typedef struct {
	UINT32                  nextEntryIndex;
    PM_TimeStampLogEnteryS  eventLog[PM_EVENT_LOG_SIZE];
    BOOL                    logEnabled;
    BOOL                    cyclic;
}PM_EventLogS;

#if defined(PM_TCM_TEST_ENABLED)
	typedef enum {
		PM_TCM_TEST_MODE_IND			= 0,
		PM_TCM_TEST_USER_VALUE_IND		= 1,
		PM_TCM_TEST_ITCM_START_ADDR_IND,
		PM_TCM_TEST_ITCM_TEST_SIZE_IND,
		PM_TCM_TEST_DTCM_START_ADDR_IND,
		PM_TCM_TEST_DTCM_TEST_SIZE_IND
	}PMTCMTest_InputIndicesE;

	typedef enum {
		PM_TCM_TEST_ITCM_IND = 0,
		PM_TCM_TEST_DTCM_IND = 1
	}PM_TCMTest_ResultIndicesE;
#endif

    // This structure comprises of general PM global run time variables.
//#if defined(PM_DEBUG_MODE_ENABLED)
#if 0
    typedef struct  {
            PM_EventLogS log;
		#if defined(PM_TCM_TEST_ENABLED)
					struct {
						UINT32 testVal;				/* The value to be written to the TCMs	  */
						void*  result[2];			/* The result of each TCM				  */
						BOOL   isTestEnabled;
						BOOL   isTestDone;
						UINT32 testMode;			/* The test mode as requested by the user */
						BYTE*  itcmStartAddr;
						UINT32 itcmTestSize;
						BYTE*  dtcmStartAddr;
						UINT32 dtcmTestSize;
						UINT32 numberOfTests;		/* The # of times the TCM memory test was done */
						UINT32 numberOfFaultsITCM;	/* The # of times the ITCM failed              */
						UINT32 numberOfFaultsDTCM;	/* The # of times the DTCM failed              */
					} tcmTest;
		#endif //PM_TCM_TEST_ENABLED
    }PM_GlobalsS;
    
extern PM_GlobalsS _pmGlobals;

#endif /*PM_DEBUG_MDOE_ENABLED*/

#endif  /* _PM_DBG_TYPES_H_ */
