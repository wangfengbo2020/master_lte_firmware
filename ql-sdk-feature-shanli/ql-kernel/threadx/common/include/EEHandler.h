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

/*******************************************************************************
*               MODULE HEADER FILE
********************************************************************************
* Title: Error Handler header
*
* Filename: EEHandler.h
*
* Target, platform: Manitoba
*
* Authors: Yossi Hanin
*
* Description: Error handler component header file
*
* Last Updated:
*
* Notes:
*******************************************************************************/

#ifndef _ERROR_HANDLER_H_
    #define _ERROR_HANDLER_H_


/*----------- Local include files --------------------------------------------*/
#include "global_types.h"
#include "rtc.h"
#include "utils.h"
#include "pmu.h"



/******************************************************************************************/
/*                                 GENERAL                                                */
/******************************************************************************************/

//ICAT EXPORTED ENUM
typedef enum
{
	//enumerated
    EE_SYS_RESET_EN,
    EE_ASSERT_EN,
    EE_EXCEPTION_EN,
    EE_WARNING_EN,
	EE_NUM_ENTRY_TYPES,
	// Codes
    EE_SYS_RESET = 300,
    EE_ASSERT = 350,
    EE_EXCEPTION = 450,
    EE_WARNING = 550
} EE_entry_t;



//ICAT EXPORTED ENUM
typedef enum
{
  EEE_DataAbort,
  EEE_PrefetchAbort,
  EEE_FatalError,
  EEE_SWInterrupt,
  EEE_UndefInst,
  EEE_ReservedInt
} EE_ExceptionType_t;


//ICAT EXPORTED ENUM
typedef enum
{
    EE_NO_RESET_SOURCE,
    EE_POWER_ON_RESET = PMU_POR,
    EE_EXT_MASTER_RESET,
    EE_WDT_RESET =(PMU_EMR+2)
} EE_PMU_t;

/* secondary exception types */
typedef enum
{
    VERTICAL = 0,
    ALIGNMENT_1 = 1,
    TERMINAL = 2,
    ALIGNMENT_2 = 3,
    EXTERNAL_ABORT_ON_TRANSLATION = 12,
    EXTERNAL_ABORT_ON_TRANSLATION_2 = 14,
    TRANSLATION = 5,
    TRANSLATION_2 = 7,
    EE_DOMAIN = 9,
    EE_DOMAIN_2 = 11,
    PERMISSION = 13,
    PERMISSION_2 = 15,
    IMPRECISE_EXTERNAL_DATA_ABORT = 6,
    LOCK_ABORT = 4,
    DATA_CACHE_PARITY_ERROR = 8,
    INSTRUCTION_MMU = 0 ,
    EXTERNAL_INSTRUCTION_ERROR = 6,
    INSTRUCTION_CACHE_PARITY_ERROR = 8
} EXCEPTION_TYPE;

/******************************************************************************************/
/*                            CPU register context format                                 */
/******************************************************************************************/

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT32              r0;    /* register r0 contents */
    UINT32              r1;    /* register r1 contents */
    UINT32              r2;    /* register r2 contents */
    UINT32              r3;    /* register r3 contents */
    UINT32              r4;    /* register r4 contents */
    UINT32              r5;    /* register r5 contents */
    UINT32              r6;    /* register r6 contents */
    UINT32              r7;    /* register r7 contents */
    UINT32              r8;    /* register r8 contents */
    UINT32              r9;    /* register r9 contents */
    UINT32              r10;   /* register r10 contents */
    UINT32              r11;   /* register r11 contents */
    UINT32              r12;   /* register r12 contents */
    UINT32              SP;   /* register r13 contents */
    UINT32              LR;   /* register r14 contents (excepted mode)*/
	UINT32              PC;   /* PC - excepted instruction */
    UINT32              cpsr;  /* saved program status register contents */
    UINT32              FSR;   /* Fault status register */
    UINT32              FAR_R; /* Fault address register */
    EE_PMU_t            PMU_reg;  /* saved reset cause - should be last */

   // UINT32              PESR;  /* Extension */
   // UINT32              XESR;
   // UINT32              PEAR;
   // UINT32              FEAR;
   // UINT32              SEAR;
   // UINT32              GEAR;
} EE_RegInfo_Data_t;

//
// Context types: the two enumerations below must be synchronized
//

//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ EE context types to be saved in the context buffer*/
   EE_CT_None,      /* @ENUM_VAL_DESC@ Save no context*/
   EE_CT_ExecTrace, /* @ENUM_VAL_DESC@ Save Trace buffer*/
   EE_CT_StackDump  /* @ENUM_VAL_DESC@ Save Stack Dump*/
}EE_ContextType_t;        // This enumerates configureable types of contents to be saved in the context buffer

//ICAT EXPORTED ENUM
typedef enum
{
   EE_CDT_None,
   EE_CDT_ExecTrace,
   EE_CDT_StackDump,
   EE_CDT_UserDefined=0x10
}EE_ContextDataType_t;    // This enumerates possible types of contents of the context buffer in the log

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT32 _PESR;
	UINT32 _XESR;
	UINT32 _PEAR;
	UINT32 _FEAR;
	UINT32 _SEAR;
	UINT32 _GEAR;
} EE_XscGasketRegs;

/******************************************************************************************/
/*                            LOG ENTRY FORMAT                                            */
/******************************************************************************************/
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16                  fileWriteOffset; //DO NOT REMOVE OR CHANGE TYPE!!!(for cyclic file)
    EE_entry_t              type;
    RTC_CalendarTime        dateAndTime;
    char                    desc[100];  /* Description string size =ERROR_HANDLER_MAX_DESC_SIZE*/
    EE_RegInfo_Data_t       RegInfo;
	EE_ContextDataType_t    contextBufferType;
	UINT8                  contextBuffer[512];
	UINT32                  CHKPT0;
	UINT32                  CHKPT1;
	char                    taskName[10];
	UINT32                  taskStackStart;
	UINT32                  taskStackEnd;
	//UP TO HERE 0x1e4 bytes (out of 0x200 allocated by linker control file INT_RAM_EE segment)
	EE_XscGasketRegs        xscaleGasketRegs;
	UINT32                  warningCntr;   //reserved[1];
#ifndef LWIP_IPNETBUF_SUPPORT
	char					cp_version[128];
	char					cp_date[128];
#endif
} EE_Entry_t;


typedef struct
{
    char                   *desc;
    char                   *file;
    int                     line;
    UINT8                  *data;
    UINT32                  dataLen;
    EE_entry_t              type;
} EE_ParaInfo_t;


/*
 * Actions the EEHandler may take depending on the event specifics
 */
typedef enum
{
   eehActionFatal,
   eehActionLog,
   eehActionIgnore
}EEHandlerAction;

/******************************************************************************************/
/*            PRIMARY EXCEPTION HANDLERS (ENTRIES CALLED BY LOW LEVEL HANDLERS            */
/*            RETURN CODES LISTED                                                         */
/******************************************************************************************/

#define     EE_EXC_STOP    0
#define     EE_EXC_RETURN  1

UINT32      BranchZeroIntHandler( void );
UINT32      DataAbortHandler    ( void );
UINT32      PrefetchAbortHandler( void );
UINT32      FatalErrorHandler   ( void );
UINT32      SWInterruptHandler  ( void );
UINT32      UndefInstHandler    ( void );
UINT32      ReservedIntHandler  ( void );


/******************************************************************************************/
/*                                MAINTENANCE                                             */
/******************************************************************************************/

//for configuration and initiliazation
void  eeHandlerPhase1Init(void);
void  eeHandlerPhase2Init(void);
void  eeHandlerPhase3Init(void);

void  errHandlerSaveToFDIPeriodic( void );

void  EeHandlerReadFile( void );
void  EeHandlerTestDataAbortExcep( void );
void  TriggerWatchdogTimeout(void);
void  eeh_set_stack(void);


/******************************************************************************************/
/*                             ERROR ENTRIES (API)                                        */
/******************************************************************************************/
/* Error string only */
void eeHandlerSaveDescAssert(const char* desc);

/* Error string and user context data */
void eeHandlerSaveDescAssertData(const char* desc, const UINT8* data, UINT32 dataLen);

/* Error string, file name and line number */
void eeHandlerSaveDescFileLineAssert(const char* desc,const char *file,UINT16 line);
void eeWarning                      (const char *file, int line, int warningMask);

/* Error string, file name and line number, and register context */
void eeHandlerSaveDescFileLineAssertRegs(const char* desc,const char *file,UINT16 line,const EE_RegInfo_Data_t* regs);


//for Warning without a reset
char eeHandlerSaveDescWarning(const char *errorDescription);
char eeHandlerSaveDescFileLineWarning(const char *desc,const char *file,UINT16 line);
char eeHandlerSaveDescFileLineParamWarning(const char*,const char*,UINT16,UINT32,UINT32,UINT32);

//for Warning with DSP reset only
void eeHandlerSaveDescDspResetWarning(const char *desc,char DSPresetOn);

/******************************************************************************************/
/*                       EXTENDED HANDING: ACTION BINDING API                             */
/******************************************************************************************/

/* A limited number of independent handlers can be bound */
typedef void FatalEventAction_fn(const char* errorString,               //mandatory, event description string
								 const char* file,                      //optional, may appear as NULL
								 int line,                              //optional, may appear as 0
		                         EE_entry_t type,                       //mandatory, event type (enum)
		                         const EE_RegInfo_Data_t* regContext,   //register context
								 RTC_CalendarTime* calendarTime);       //RTC time

//------- generic "global" function pointer --------
typedef void voidPFuncVoid(void);


typedef enum
{
	EE_ActionAlways         =0,
	EE_ActionSkipBeforeReset=1,         // don't run this action when immediate final action is reset
	EE_ActionDefer          =2,         // defer this action if possible and applicable
	EE_ActionDeferredOnly   =4,         // run this action only when deferred (won't be done with EE ASSISTANCE)
	EE_ActionDeferredOnlyNotFile =12    // run this action only when deferred and only if handling has no file operations
}EE_ActionCondition;
BOOL                 EEHandlerFatalErrorActionBind(FatalEventAction_fn* pFunc, UINT32 mode);

FatalEventAction_fn* EEHandlerExternalFinalActionBind(FatalEventAction_fn* pFunc);

BOOL                 EELOG_RegisterForLogstream(voidPFuncVoid* pF);


/******************************************************************************************/
/*                       SECONDARY EXCEPTION HANDLERS API                                 */
/******************************************************************************************/

typedef void (* ExceptionHendler) (EE_RegInfo_Data_t*);

void        ExceptionDataHandlerReplace     (EXCEPTION_TYPE,ExceptionHendler);
void        ExceptionDataHandlerRestore      (EXCEPTION_TYPE,ExceptionHendler);
void        ExceptionPrefetchHandlerReplace (EXCEPTION_TYPE,ExceptionHendler);
void        ExceptionPrefetchHandlerRestore (EXCEPTION_TYPE,ExceptionHendler);

// Binds an external handler to track all exceptions
typedef EEHandlerAction (* ExceptionHendlerExt) (EE_ExceptionType_t type, EE_RegInfo_Data_t*);
ExceptionHendlerExt eeExtExceptionHandlerBind(ExceptionHendlerExt newHandler);

// Returns the offset from excepted instruction to the PC saved on exception (positive)
int eeGetPcOffset(EE_ExceptionType_t et, const EE_RegInfo_Data_t* regContext);
int eeGetPcStep(const EE_RegInfo_Data_t* regContext);


EEHandlerAction eehCallSecondaryHandler(UINT8 index, EE_RegInfo_Data_t* pSaved_Registers);


/******************************************************************************************/
/*   Extention EE Handler with WDT management                                             */
/******************************************************************************************/
typedef enum
{
 EE_WDT_MGR_MODE_NORMAL,
 EE_WDT_MGR_MODE_LONG  ,
 EE_WDT_MGR_MODE_HUGE  ,
 EE_WDT_MGR_MODE_NOWDT ,
 EE_WDT_MGR_MODE_MAX,
 EE_WDT_MGR_MODE_UINT16 = 0x00010000,
 EE_WDT_MGR_MODE_UINT32 = 0x1FFFFFFF  //force to UINT32
} EeWdtMgrModes;

//#if defined(_TAVOR_HARBELL_) || defined(SILICON_TTC) || defined(SILICON_PV2)
#if defined(SILICON_TTC) || defined(SILICON_PV2)
#if defined(EE_HANDLER_ENABLE)
#define EE_WDT_MGR_ENABLE
#endif
#endif
#if defined(EE_WDT_MGR_ENABLE)
void    eeDbgWatchdogKick (UINT32 tsT32k);
void    eeWdtMgrCfg (EeWdtMgrModes mode);
void    eeWdtMgrInit (void);
#else
#define eeDbgWatchdogKick(X)  /* */
#define eeWdtMgrCfg(X,Y)      /* */
#define eeWdtMgrInit()        /* */
#endif

#if 0
/* Added by Daniel for HOT RESET 20171012, begin */
#define MAX_HOT_RESET_RETRY         3

typedef enum SystemResetOptionTag
{
    SYSTEM_HOT_RESET,
    SYSTEM_SILENT_RESET,
    NUM_RESET_OPTION
}SystemResetOption;

typedef struct ValidMmContextTag
{
    UINT8 mmContext[10];
}ValidMmContext;

typedef struct ValidContextTag
{
    ValidMmContext validMmContext;
}ValidContext;
/* Added by Daniel for HOT RESET 20171012, end */
#endif
#endif//end of _ERROR_HANDLER_H_

