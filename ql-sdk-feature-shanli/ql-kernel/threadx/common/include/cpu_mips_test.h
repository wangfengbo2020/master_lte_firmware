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

#if !defined (CPU_MIPS_TEST_H)
# define      CPU_MIPS_TEST_H

/*********************************************************************
* There may be next debug tools (and their combinations):
* - MIPS logger into RAM      MIPS_TEST_RAM
* - XDA   external logger     MIPS_TEST
* - ISPT  external logger     DATA_COLLECTOR_IMPL
* Some combination may be chosen by compile switches only, some by run-time.
*
* Let's "describe" next macro for every one or no-loggers case:
*     CPU_MIPS_TEST
*     CPU_MIPS_TEST_S
*     MIPS_MIN_LISR_ID
*     MIPS_MIN_TASK_ID
*********************************************************************/

#if  !defined (MIPS_TEST) && !defined (MIPS_TEST_RAM) && !defined (DATA_COLLECTOR_IMPL)
// No Logger required
  #define CPU_MIPS_TEST_SYNC32K(dATA_OUT)
  #define CPU_MIPS_TEST(dATA_OUT)
  #define CPU_MIPS_TEST_S(dATA_OUT)
#endif


#if defined (MIPS_TEST_RAM)
// Dynamic switching of the "MIPS" monitoring modes: MIPS_RAM, XDA, EXT, etc.
  typedef enum
  {
	mipsRamModeNormal,
	mipsRamModeXDA,
	mipsRamModeExt,
	mipsRamModeMax
  }MipsRamMode;

  //include list of user defined event IDs
  #include "cpu_mips_evntList.h"

  extern MipsRamMode mipsRamModeSet(MipsRamMode mode);
  extern void        mipsRamSwitchSubTaskID(UINT32 modifier);
  extern void        mipsRamHook(UINT32 value);
  extern UINT32      mipsRamSync32kEvent(UINT32 value);  //Unprotected! Returns the T32K free running timer as APDC=13MHZ

  // Profiling of specific tasks:
  // Trace a sub-task ID (16-bit) and set the current sub-task ID (0 indicates no sub-task, i.e. main task is active)
  #define MIPSRAM_SUB_TASK_ID_MOD_MASK   0xFFFF0000
  #define CPU_MIPS_TEST_S(dATA_OUT)  mipsRamSwitchSubTaskID((dATA_OUT)<<16)

  #if !defined SEND_PM_TRACE_TO_LOGGER_SYNC32K
	   #define SEND_PM_TRACE_TO_LOGGER_SYNC32K(mSG_TYPE)      mipsRamSync32kEvent(mSG_TYPE) /*CPU_MIPS_TEST_SYNC32K(mSG_TYPE)*/
  #endif

  #if !defined SEND_PM_TRACE_TO_LOGGER
	   #define SEND_PM_TRACE_TO_LOGGER(mSG_TYPE)              CPU_MIPS_TEST(mSG_TYPE);
  #endif

  #if !defined SEND_PM_TRACE_DATA_TO_LOGGER
  	   #define SEND_PM_TRACE_DATA_TO_LOGGER(mSG_TYPE, dATA)   CPU_MIPS_TEST(mSG_TYPE | dATA);
  #endif


#if defined (DATA_COLLECTOR_IMPL) //Amit&Alex - in Tavor ISPT,XDA and MIPS_RAM all use the same hook
    extern void        _DC_INTC_Hook(UINT32 value);

#if defined (EDEN_1928) || defined (NEZHA3_1826)
  	#define CPU_MIPS_TEST(dATA_OUT) 	
#else
	#define CPU_MIPS_TEST(dATA_OUT)    _DC_INTC_Hook(dATA_OUT);
#endif
#else //Amit&Alex - else, in Hermon use original MIPS_RAM hook
	//#define CPU_MIPS_TEST_SYNC32K(dATA_OUT)    mipsRamSync32kEvent(dATA_OUT)
#if defined (EDEN_1928) || defined (NEZHA3_1826)
	#define CPU_MIPS_TEST(dATA_OUT)           
#else
    #define CPU_MIPS_TEST(dATA_OUT)             mipsRamHook((UINT32)(dATA_OUT))
#endif
#endif
#endif //(MIPS_TEST_RAM)
//-------------------------------------------------------------------------------------------------------------------
#if defined (DATA_COLLECTOR_IMPL) && !defined (MIPS_TEST_RAM)
	#define CPU_MIPS_TEST(dATA_OUT) 	_DC_INTC_Hook(dATA_OUT);
	#define CPU_MIPS_TEST_S(dATA_OUT)
	#define SEND_PM_TRACE_TO_LOGGER_SYNC32K(mSG_TYPE)      mipsRamSync32kEvent(mSG_TYPE)
#else
#if defined (MIPS_TEST)&& !defined (SILICON_PV2) && !defined (MIPS_TEST_RAM) //_TAVOR_HARBELL_
	#define CPU_MIPS_TEST(dATA_OUT)  *((volatile UINT16 *) 0x0c600000) = dATA_OUT
	#define CPU_MIPS_TEST_S(dATA_OUT)
#endif//#if defined (MIPS_TEST)&& !defined (_TAVOR_HARBELL_) && !defined (MIPS_TEST_RAM)
#endif//#if defined (DATA_COLLECTOR_IMPL) && !defined (MIPS_TEST_RAM)
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
#if !defined(MIPS_MIN_TASK_ID)
#if defined(MIPS_TEST_RAM)
#define MIPS_MIN_TASK_ID        0x100
#else
#define MIPS_MIN_TASK_ID        0
#endif
#endif



#if defined (MIPS_TEST)
#define START_MIPS_TEST_FUNC_1   *((volatile UINT16 *) 0x0c600000) = 224
#define STOP_MIPS_TEST_FUNC_1    *((volatile UINT16 *) 0x0c600000) = 225
#define START_MIPS_TEST_FUNC_2   *((volatile UINT16 *) 0x0c600000) = 226
#define STOP_MIPS_TEST_FUNC_2    *((volatile UINT16 *) 0x0c600000) = 227
#define START_MIPS_TEST_FUNC_3   *((volatile UINT16 *) 0x0c600000) = 228
#define STOP_MIPS_TEST_FUNC_3    *((volatile UINT16 *) 0x0c600000) = 229
#define START_MIPS_TEST_FUNC_4   *((volatile UINT16 *) 0x0c600000) = 230
#define STOP_MIPS_TEST_FUNC_4    *((volatile UINT16 *) 0x0c600000) = 231
#define START_MIPS_TEST_FUNC_5   *((volatile UINT16 *) 0x0c600000) = 232
#define STOP_MIPS_TEST_FUNC_5    *((volatile UINT16 *) 0x0c600000) = 233
#define START_MIPS_TEST_FUNC_6   *((volatile UINT16 *) 0x0c600000) = 234
#define STOP_MIPS_TEST_FUNC_6    *((volatile UINT16 *) 0x0c600000) = 235
#define START_MIPS_TEST_FUNC_7   *((volatile UINT16 *) 0x0c600000) = 236
#define STOP_MIPS_TEST_FUNC_7    *((volatile UINT16 *) 0x0c600000) = 237
#define START_MIPS_TEST_FUNC_8   *((volatile UINT16 *) 0x0c600000) = 238
#define STOP_MIPS_TEST_FUNC_8    *((volatile UINT16 *) 0x0c600000) = 239
#endif	// End of Mips test


/************************************************************************
* Non-Automatic (non-NUCLEUS) events used by CPU_MIPS_TEST()
*/
#define CPU_MIPS_EVENT_BASE_CUSTOMER      0
#define CPU_MIPS_EVENT_BASE_SYSRESERVE    0x80
#define CPU_MIPS_EVENT_BASE_PM            0xE0 /*depends also from ISPT */

#endif //CPU_MIPS_TEST_H - EOF




