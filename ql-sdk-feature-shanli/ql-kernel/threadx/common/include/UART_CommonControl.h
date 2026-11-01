/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/****************************************************************************************************************************
*              MODULE IMPLEMENTATION FILE
*****************************************************************************************************************************
*  COPYRIGHT (C) 2001 Intel Corporation.
*
*  This file and the software in it is furnished under
*  license and may only be used or copied in accordance with the terms of the
*  license. The information in this file is furnished for informational use
*  only, is subject to change without notice, and should not be construed as
*  a commitment by Intel Corporation. Intel Corporation assumes no
*  responsibility or liability for any errors or inaccuracies that may appear
*  in this document or any software that may be provided in association with
*  this document.
*  Except as permitted by such license, no part of this document may be
*  reproduced, stored in a retrieval system, or transmitted in any form or by
*  any means without the express written consent of Intel Corporation.
*
*  Title:   UART Package Common Control
*
*  Filename:    Uart_CommonControl.h
*
*  Target, subsystem: Common Platform, HAL
*
*  Authors:	ILANA BEN-ARIE
*
*  Description:
*
*  Last Modified: <Initial> <date>
*
*  Notes:
*****************************************************************************************************************************/


#ifndef _UART_COMMONCONTROL_H_
#define _UART_COMMONCONTROL_H_

#include "UART.h"
#include "UART_HW.h"
#include "global_types.h"
#include "utils.h"

/*-- Macros definitions (#define) ---------------------------------------------------------------*/
/* This Macro check the valid of the port number  */
#if defined (COMMON_PLATFORM_DEBUG)
    #if defined(UART_SINGLE_PORT)
        #define CHECK_PORT_NUM_VALID(pn) ASSERT(pn==UART_PORT_STUART)
    #else
        #define CHECK_PORT_NUM_VALID(pn) if(pn >= NUMBER_OF_SUPPORT_PORTS) return UART_RC_PORT_NUM_ERROR
    #endif
#else //!COMMON_PLATFORM_DEBUG
    #define CHECK_PORT_NUM_VALID(pn)
#endif

/* This Macro Enable any UART INT  */
#define ENABLE_UART_INT(p,b)        {UINT32 v,cpsr;\
                                     cpsr = disableInterrupts();\
                                     HW_UART_READ_IER(_UARTHwAddresses[(p)], (v));\
                                     HW_UART_WRITE_IER(_UARTHwAddresses[(p)],((v) | (b)));\
                                     restoreInterrupts(cpsr);}

 /* This Macro Disable any UART INT  */
#define DISABLE_UART_INT(p,b)       {UINT32 t,cpsr;\
                                     cpsr = disableInterrupts();\
                                     HW_UART_READ_IER(_UARTHwAddresses[(p)], (t));\
                                     HW_UART_WRITE_IER(_UARTHwAddresses[(p)], ((t) & ~(b)));\
                                     restoreInterrupts(cpsr);}

 /* This Macro increment the put in the Cycle Buffer for the RX Message */
#define INCREMENT_PTR(p,u,b)        ((((p)+1) > (u)) ? (b) : ((p)+1))  // p= ptr (put or curGet), u=upper, b=base

/* This Macro increment number of bytes in the Cycle Rx Buffer */
#define INCREMENT_NUMBER_TO_PTR(p,n,u,b)   ( (((p)+(n)) > u) ?  (/*(UINT8 *)*/((p)-(u)+(n)-1 + (b))) : ((p)+(n)) )  // p= ptr (put or curGet), u=upper, b=base


              //output
#define GPIO_PIN_DCD                GPIO_PIN_55
#define GPIO_PIN_RI                 GPIO_PIN_27
#define GPIO_PIN_CTS                GPIO_PIN_57
#define GPIO_PIN_DSR                GPIO_PIN_53
#define GPIO_PIN_TX                 GPIO_PIN_33
             //input
#define GPIO_PIN_RTS                GPIO_PIN_56
#define GPIO_PIN_DTR                GPIO_PIN_52

#define FIFO_SIZE                   64
#define HALF_FIFO_SIZE              (FIFO_SIZE/2)
#define NO_FIFO_FREE_SPACE          0   // Tx FIFO is FUll

typedef struct
{
	BOOL				available;
}UARTLocalInfo;

typedef struct
{
	UARTConfiguration			config;
	UARTLocalInfo				localInfo;
}UARTInternalDataConfig;

typedef struct
{
    UART_Port   portNumber;
    UARTNotifyInterrupt callbackFunNotifyModemInterrupt;
    UARTNotifyInterrupt callbackFunNotifyTxInterrupt;
    UARTNotifyInterrupt callbackFunNotifyRxInterrupt;
    UARTNotifyInterrupt callbackFunNotifyErrInterrupt;
}UART_ISRBind;   /* 3 callback fun. for Rx, Tx and Error Interrut - for manitoba */



/*------------------------------------------------------------------------------------------------*/

/*-- Constants definitions (C/D type) -------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------*/
#ifdef UART_COMMON_CONTROL_FILE
    #define EXTERN
#else
    #define EXTERN      extern
#endif




EXTERN  UART_ISRBind                    _BindISR[NUMBER_OF_SUPPORT_PORTS];
EXTERN  UINT32                          _UARTHwAddresses[NUMBER_OF_SUPPORT_PORTS];
EXTERN  UARTInternalDataConfig          _UARTPorts[NUMBER_OF_SUPPORT_PORTS];


#endif /*  _UART_COMMONCONTROL_H_  */


