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

/***************************************************************************
*               MODULE IMPLEMENTATION FILE
****************************************************************************
* Title: Initialing code
*
* Filename: cinit2.c
*
* Target, platform: Manitoba, Hermon
*
* Authors: Gideon Yuval
*
* Description:
* 	Final Stack Init
*
******************************************************************************/

/*----------- External include files -----------------------------------------*/
#if defined(__arm)
#include <locale.h>
#endif
#include <string.h>
#include "global_types.h"
#include "utils.h"
#include "bsp_config.h"

#ifdef PLAT_USE_THREADX
#include <tx_port.h>
#include <tx_thread.h>
#include <tx_timer.h>
#include <tx_initialize.h>
#endif
#include "UART.h"

#define AGGRESSIVE_STACK_REUSE
#define REUSE_HISR_STACK_FOR_TIMERS


/*----------- Local include files --------------------------------------------*/
extern VOID   INC_Initialize(VOID *first_available_memory);

/*
 *  NOTE:       Beware to chose right stack sizes.
 *              Improper stack sizes may cause severe SW failures !!!
 */
/* Larger Sytem stack and HISR stack set mainly due to /softutil/transport stack consumption - reduce later */
#define STACK_ALIGNMENT             8 /*Bytes*/
#define SYSTEM_STACK_SIZE           (1024*4)                /* Number of bytes in System stack */
#if defined(PLAT_USE_THREADX) || defined(PLAT_USE_ALIOS)
#define SYSTEM_TIMER_STACK_SIZE      (1024*4)
#endif
#if !defined(REUSE_HISR_STACK_FOR_TIMERS)
#define SYSTEM_HISR_STACK_SIZE      (1024*4)                /* Number of bytes in System HISR stack */
#endif
#define IRQ_STACK_SIZE              (1024*2)                    /* Number of bytes in IRQ stack */

#if defined (AGGRESSIVE_STACK_REUSE)
#define COMMON_STACK_SIZE           0x200
#else
#define FIQ_STACK_SIZE              1024                    /* Number of bytes in FIQ stack */
#define DATA_ABORT_STACK_SIZE       0x200                   /* Number of bytes data abort stack */
#define UNDEFINED_STACK_SIZE        0x200                   /* Number of bytes UNDEFINED_MODE stack */
#endif

#if defined(PLAT_USE_THREADX) || defined(PLAT_USE_ALIOS)
static UINT32 __align(STACK_ALIGNMENT)  __System_Timer_Stack[SYSTEM_TIMER_STACK_SIZE/sizeof(UINT32)];
#endif

static UINT32 __align(STACK_ALIGNMENT) __System_Stack[SYSTEM_STACK_SIZE/sizeof(UINT32)];


#if defined(PLAT_USE_ALIOS)
UINT32 sys_stack_top;
#endif



#if !defined(REUSE_HISR_STACK_FOR_TIMERS)
/*
 * System HISR Stack is used by Nucleus timer HISR
 */
static UINT32 __align(STACK_ALIGNMENT) __System_HISR_Stack[SYSTEM_HISR_STACK_SIZE/sizeof(UINT32)];
#else
#if 0//NOT NU_OS
extern UINT32 __align(STACK_ALIGNMENT) hisrStack[HISR_PRIORITY_LEVELS][HISR_STACK_SIZE/sizeof(UINT32)];
#endif
#endif


/*
 * System IRQ Stack is used by Nucleus IRQ interrupt handler
 */
static UINT32 __align(STACK_ALIGNMENT) __IRQ_Stack[IRQ_STACK_SIZE/sizeof(UINT32)];


#if defined (AGGRESSIVE_STACK_REUSE)
/* Reuse one same System Stack for Nucleus FIQ interrupt handler, DataAbortHandler and UNDEFINED mode Handler */
static UINT32 __align(STACK_ALIGNMENT) __Common_Stack[COMMON_STACK_SIZE/sizeof(UINT32)];
#define __FIQ_Stack                    __Common_Stack
#define __ABORT_Stack                  __Common_Stack
#define __UNDEFINED_Stack              __Common_Stack
#else
static UINT32 __align(STACK_ALIGNMENT) __FIQ_Stack[FIQ_STACK_SIZE/sizeof(UINT32)];
static UINT32 __align(STACK_ALIGNMENT) __ABORT_Stack[DATA_ABORT_STACK_SIZE/sizeof(UINT32)];
static UINT32 __align(STACK_ALIGNMENT) __UNDEFINED_Stack[UNDEFINED_STACK_SIZE/sizeof(UINT32)];
#endif

/* Timer HISR priority (values from 0 to 2, where 0 is highest) */
#define TIMER_PRIORITY   2

extern UINT32 OsaTaskStackMagic(void);
INT32 task_stack_magic = 0;

/*----------- Global function definition -------------------------------------*/

/******************************************************************************
* Function     : Cinit2
*******************************************************************************
*
* Description  :
*
******************************************************************************/
void Cinit2 (void)
{
#ifdef PLAT_USE_THREADX

	UINT32 SystemStack, SystemLimit;


	extern volatile ULONG  _tx_thread_system_state;

	CPUartLogPrintf("Cinit 2");

	_tx_thread_system_state =  TX_INITIALIZE_IN_PROGRESS;

	task_stack_magic = OsaTaskStackMagic();

	/*Init final stacks*/
	//ToDo - except the system stack, v7 isn't initialized as it was done for the temp stacks - fix this
    /* Fill in basic stacks in order to detect overlow */
	memset((void*)__System_Stack, 0xA5, sizeof(__System_Stack));
	memset((void*)__System_Timer_Stack, 0xA5, sizeof(__System_Timer_Stack));
#if !defined(REUSE_HISR_STACK_FOR_TIMERS)
	memset((void*)__System_HISR_Stack, 0xA5, sizeof(__System_HISR_Stack));
#else
#if 0//NOT NU_OS
    memset((void*)hisrStack, 0xA5, sizeof(hisrStack));
#endif
#endif
    memset((void*)__IRQ_Stack, 0xA5, sizeof(__IRQ_Stack));
    memset((void*)__FIQ_Stack, 0xA5, sizeof(__FIQ_Stack));
    memset((void*)__ABORT_Stack, 0xA5, sizeof(__ABORT_Stack));
    memset((void*)__UNDEFINED_Stack, 0xA5, sizeof(__UNDEFINED_Stack));

	// Setup mode stacks
	SetMode_R13(CPSR_MODE_FIQ,((UINT32)__FIQ_Stack)+sizeof(__FIQ_Stack));
	SetMode_R13(CPSR_MODE_IRQ,((UINT32)__IRQ_Stack)+sizeof(__IRQ_Stack));
	SetMode_R13(CPSR_MODE_ABT,((UINT32)__ABORT_Stack)+sizeof(__ABORT_Stack));
	SetMode_R13(CPSR_MODE_UND,((UINT32)__UNDEFINED_Stack)+sizeof(__UNDEFINED_Stack));

#if defined(__arm)
	/* Ensure proper functionality of some C library functions */
    setlocale(LC_ALL, "C");
#endif

	SystemLimit= (UINT32)__System_Stack;
	SystemStack = SystemLimit + sizeof(__System_Stack);

	_tx_thread_system_stack_ptr = (void*)__System_Stack;
	_tx_timer_stack_start = (void*)__System_Timer_Stack;
	_tx_timer_stack_size = SYSTEM_TIMER_STACK_SIZE;
	_tx_timer_priority = 0;

	SetSystemStack(SystemStack, SystemLimit);

	tx_kernel_enter();

#elif defined(PLAT_USE_ALIOS)

    UINT32 SystemStack, SystemLimit;

	task_stack_magic = OsaTaskStackMagic();

    /*Init final stacks*/
    //ToDo - except the system stack, v7 isn't initialized as it was done for the temp stacks - fix this
    /* Fill in basic stacks in order to detect overlow */
    memset((void*)__System_Stack, 0xA5, sizeof(__System_Stack));
    memset((void*)__System_Timer_Stack, 0xA5, sizeof(__System_Timer_Stack));
#if !defined(REUSE_HISR_STACK_FOR_TIMERS)
    memset((void*)__System_HISR_Stack, 0xA5, sizeof(__System_HISR_Stack));
#else
#if 0//NOT NU_OS
    memset((void*)hisrStack, 0xA5, sizeof(hisrStack));
#endif
#endif
    memset((void*)__IRQ_Stack, 0xA5, sizeof(__IRQ_Stack));
    memset((void*)__FIQ_Stack, 0xA5, sizeof(__FIQ_Stack));
    memset((void*)__ABORT_Stack, 0xA5, sizeof(__ABORT_Stack));
    memset((void*)__UNDEFINED_Stack, 0xA5, sizeof(__UNDEFINED_Stack));

    // Setup mode stacks
    SetMode_R13(CPSR_MODE_FIQ,((UINT32)__FIQ_Stack)+sizeof(__FIQ_Stack));
    SetMode_R13(CPSR_MODE_IRQ,((UINT32)__IRQ_Stack)+sizeof(__IRQ_Stack));
    SetMode_R13(CPSR_MODE_ABT,((UINT32)__ABORT_Stack)+sizeof(__ABORT_Stack));
    SetMode_R13(CPSR_MODE_UND,((UINT32)__UNDEFINED_Stack)+sizeof(__UNDEFINED_Stack));

#if defined(__arm)
    /* Ensure proper functionality of some C library functions */
    setlocale(LC_ALL, "C");
#endif

    SystemLimit= (UINT32)__System_Stack;
    SystemStack = SystemLimit + sizeof(__System_Stack);
    sys_stack_top = SystemStack;

    SetSystemStack(SystemStack, SystemLimit);


    extern void start_aos_kernel(void);
    start_aos_kernel();

#else

	/* Nucleus variables to setup before INC_Initiaize call */
	extern UINT32 TCD_System_Stack, TCT_System_Limit, TMD_HISR_Stack_Ptr, TMD_HISR_Stack_Size, TMD_HISR_Priority;

	/*Init final stacks*/
	//ToDo - except the system stack, v7 isn't initialized as it was done for the temp stacks - fix this
    /* Fill in basic stacks in order to detect overlow */
	memset((void*)__System_Stack, 0xA5, sizeof(__System_Stack));
#if !defined(REUSE_HISR_STACK_FOR_TIMERS)
	memset((void*)__System_HISR_Stack, 0xA5, sizeof(__System_HISR_Stack));
#else
#if 0//NOT NU_OS
    memset((void*)hisrStack, 0xA5, sizeof(hisrStack));
#endif
#endif
    memset((void*)__IRQ_Stack, 0xA5, sizeof(__IRQ_Stack));
    memset((void*)__FIQ_Stack, 0xA5, sizeof(__FIQ_Stack));
    memset((void*)__ABORT_Stack, 0xA5, sizeof(__ABORT_Stack));
    memset((void*)__UNDEFINED_Stack, 0xA5, sizeof(__UNDEFINED_Stack));

	// Setup mode stacks
	SetMode_R13(CPSR_MODE_FIQ,((UINT32)__FIQ_Stack)+sizeof(__FIQ_Stack));
	SetMode_R13(CPSR_MODE_IRQ,((UINT32)__IRQ_Stack)+sizeof(__IRQ_Stack));
	SetMode_R13(CPSR_MODE_ABT,((UINT32)__ABORT_Stack)+sizeof(__ABORT_Stack));
	SetMode_R13(CPSR_MODE_UND,((UINT32)__UNDEFINED_Stack)+sizeof(__UNDEFINED_Stack));

#if !defined(REUSE_HISR_STACK_FOR_TIMERS)
	TMD_HISR_Stack_Size=sizeof(__System_HISR_Stack);
	TMD_HISR_Stack_Ptr=(UINT32)__System_HISR_Stack;
#else
#if 0//NOT NU_OS
	TMD_HISR_Stack_Size=HISR_STACK_SIZE;
	TMD_HISR_Stack_Ptr=(UINT32)hisrStack[TIMER_PRIORITY];
#endif
#endif
	TMD_HISR_Priority=TIMER_PRIORITY;

	TCT_System_Limit=(UINT32)__System_Stack;
	TCD_System_Stack=TCT_System_Limit+sizeof(__System_Stack);
	SetSystemStack(TCD_System_Stack,TCT_System_Limit);


#if defined(__arm)
	/* Ensure proper functionality of some C library functions */
    setlocale(LC_ALL, "C");
#endif

	/*Init Nucleus*/
	INC_Initialize (/*(VOID*)&top_of_heap_chk*/0); // The parameter "first_available_memory" must be present
                                                   // is not used by Nucleus, but is passed to Application_Initialize (also does not use it)
#endif

}

