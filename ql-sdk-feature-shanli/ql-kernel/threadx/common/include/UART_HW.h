/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*****************************************************************************************************************************
*              MODULE IMPLEMENTATION FILE
*******************************************************************************************************************************
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
*  Title:	UART Package Hardware Access
*
*  Filename:	HW_Access.h
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
*******************************************************************************************************************************/


#ifndef _HW_ACCESS_D_H_
#define _HW_ACCESS_D_H_

#include "UART_config.h"


#if defined (UART_SINGLE_PORT)

	//for tavor - only port number 2 (UART_PORT_STUART)
	#define HW_UART_WAKEUP(uartAddress)  UARTWakeUp(UART_PORT_STUART);
#else
#define HW_UART_WAKEUP(uartAddress)  \
	UARTWakeUp((((uartAddress) >> 20) & 0x03) - 1 );

#endif

/***************************   Register Addresses          **********************************************************/
#define MULT_BY_NUM         4L

#define UART_RHR_ADD        (0x0*MULT_BY_NUM)     /* Receiver Holding Register offset */
#define UART_THR_ADD        (0x0*MULT_BY_NUM)     /* Transmiter Holding Register offset */
#define UART_IER_ADD        (0x1*MULT_BY_NUM)     /* Interrupt Enable Register offset */
#define UART_IIR_ADD        (0x2*MULT_BY_NUM)     /* Interrupt Identification Register offset */
#define UART_FCR_ADD        (0x2*MULT_BY_NUM)     /* FIFO Control Register offset */
#define UART_LCR_ADD        (0x3*MULT_BY_NUM)     /* Line Control Register offset */
#define UART_MCR_ADD        (0x4*MULT_BY_NUM)     /* Modem Control Register offset */
#define UART_LSR_ADD        (0x5*MULT_BY_NUM)     /* Line Status Register offset */
#define UART_MSR_ADD        (0x6*MULT_BY_NUM)     /* Modem Status Register offset*/
#define UART_SPR_ADD        (0x7*MULT_BY_NUM)     /* Scratch Pad Register offset */
#define UART_ISR_ADD		(0x8*MULT_BY_NUM)	  /* Infrared Selection Register offset */
#define UART_FOR_ADD		(0x9*MULT_BY_NUM)	  /* Receive FIFO Occupancy Register offset */

#define UART_DLL_ADD        (0x0*MULT_BY_NUM)     /* LSB divisor latch register offset */
#define UART_DLM_ADD        (0x1*MULT_BY_NUM)     /* MSB divisor latch register offset */
#define UART_ABR_ADD        (0x28)                /* Auto-Baud Control Register offset for crane */
#define UART_ACR_ADD        (0x2C)                /* Auto-Baud Control Register offset for crane */

/* bit affects the selection of some UART register */
#define UART_AB_MCR_ADD     (0x8*MULT_BY_NUM)     /* Mode Control Register */

/***************************   Register Bit Definitions    *****************************************************************/
/*****	IER  ******/
#define IER_RCV_DATA_AVAILABLE              0x01L /* Enable Received Data Available interrupt (in FIFO mode) */
#define IER_TRN_HOLDING_EMPTY               0x02L /* Enable Transmit Data Request Interrupt   */
#define IER_RCV_LINE_STATUS                 0x04L /* Enable Receiver Line Status interrupt    */
#define IER_MODEM_STATUS                    0x08L /* Enable Modem interrupt    */
#define IER_TIME_OUT                        0x10L /* Enable Receive Time Out Interupt         */
#define IER_NRZE                            0x20L /* Enable NRZ */
#define IER_UART_UNIT                       0x40L /* Enable UART Unit                         */
#define IER_DMA                             0x80L /* Enable DMA requests */

#define IER_ALL_BITS                        0xFFL /* Enable all the IER bits                  */
#define IER_ALL_BITS_EXCEPT_DMA             (IER_RCV_DATA_AVAILABLE | IER_TRN_HOLDING_EMPTY| IER_TIME_OUT | IER_RCV_LINE_STATUS  | IER_MODEM_STATUS /* | IER_NRZE */| IER_UART_UNIT ) /* Enable the 4 -LSB except trensmit */
#define IER_ALL_BITS_EXCEPT_TRANS_AND_MODEM_AND_DMA (IER_RCV_DATA_AVAILABLE | IER_TIME_OUT | IER_RCV_LINE_STATUS/* | IER_MODEM_STATUS*/ )
#define IER_ALL_BITS_EXCEPT_TRANS           (IER_RCV_DATA_AVAILABLE | IER_TIME_OUT | IER_RCV_LINE_STATUS | IER_MODEM_STATUS )
#define IER_ALL_BITS_EXCEPT_MODEM           (IER_RCV_DATA_AVAILABLE | IER_TRN_HOLDING_EMPTY| IER_TIME_OUT | IER_RCV_LINE_STATUS )
#define IER_ALL_BITS_EXCEPT_TRANS_AND_MODEM_AND_TMIE      (IER_RCV_DATA_AVAILABLE | IER_RCV_LINE_STATUS)
#define IER_ALL_BITS_EXCEPT_TRANS_AND_RCV_AND_MODEM       (IER_TIME_OUT | IER_RCV_LINE_STATUS | IER_UART_UNIT | IER_DMA) /* Enable the 4 -LSB except trensmit */
#define IER_ALL_BITS_EXCEPT_TRANS_AND_RCV       (IER_TIME_OUT | IER_RCV_LINE_STATUS | IER_UART_UNIT | IER_DMA | IER_MODEM_STATUS )
#define IER_ALL_BITS_EXCEPT_TRANS_AND_MODEM (IER_RCV_DATA_AVAILABLE | IER_TIME_OUT | IER_RCV_LINE_STATUS | IER_UART_UNIT | IER_DMA) /* Enable the 4 -LSB except trensmit */
#define IER_ALL_BITS_EXCEPT_TRANS_AND_DMA   (IER_RCV_DATA_AVAILABLE | IER_TIME_OUT | IER_RCV_LINE_STATUS | IER_MODEM_STATUS )

/*****	IIR  ******/
/*   Possible interrupt values   */
#define IIR_NO_PENDING_INT          0x01L  /* Interrupt pending              */
#define IIR_MODEM_STATUS            0x00L  /* modem status                   */
#define IIR_TRANS_FIFO_REQ          0x02L  /* transmit fifo request data     */
#define IIR_REC_DATA                0x04L  /* Reveived Data Available        */
#define IIR_REC_ERROR               0x06L  /* Received error framing         */
#define IIR_TIME_OUT                0x0cL  /* Time-out Interrupt pending (on FIFI mode) */
#define IIR_AUTO_BAUD_LOCK          0x10L  /* Auto-baud Lock */

#define IIR_SOURCE_MASKED           0x06L

/*   Possible FIFO section values   */
#define IIR_NON_FIFO        0x00L   /* non-FIFO mode selection  */
#define IIR_FIFO_ENABLED    0xc0L   /* FIFO enabled selection    */

#define IIR_FIFO_UNUSABLE 0x80L    /* FIFO enabled but unusable       */

#define IIR_INT_MASK    0x06L   /* data concerning interrupt (not FIFO)    */
#define IIR_FIFO_MASK   0xC0L   /* data concerning FIFO (not interrupt)    */

/*****		FCR 	******/
#define FCR_DISABLE_FIFO    0x00L   /* Disable FIFO's */
#define FCR_ENABLE_FIFO     0x01L   /* Enable FIFO's */
#define FCR_CLEAR_RCV       0x02L   /* Clear Receive FIFO */
#define FCR_CLEAR_TRANS     0x04L   /* Clear Transmit FIFO */

/* TX Interrupt trigger level definitions	*/
#define FCR_TX_ZERO_INT     0x08L   /* Interrupt when TX FIFO empty */
#define FCR_TX_HALF_INT     0x00L   /* Interrupt when TX FIFO at least half empty */

#define FCR_TRAIL_INT       0x00L   /* Rx trailing bytes read by Processor */
#define FCR_TRAIL_DMA       0x10L   /* Rx trailing bytes read by DMA engine */

#define FCR_BUS_8BIT        0x00L   /* 8bit bus interface (default) */
#define FCR_BUS_32BIT       0x20L   /* 32bit bus interface */

/* RX Interrupt trigger level definitions	*/
#define FCR_INT_TRIGGER_L0   0x00L   /* set Int Trigger Level 1           */
#define FCR_INT_TRIGGER_L8   0x40L   /* -"-"-"-"-"-"-"-"-"-"-"8           */
#define FCR_INT_TRIGGER_L16  0x80L   /* -"-"-"-"-"-"-"-"-"-"-"16          */
#define FCR_INT_TRIGGER_L32  0xC0L   /* -"-"-"-"-"-"-"-"-"-"-"32          */

/*****		LCR 	******/
#define LCR_WORD_LEN_5      0x00L   /* set Word Lengto to 5 Bits      */
#define LCR_WORD_LEN_6      0x01L   /* set Word Lengto to 6 Bits      */
#define LCR_WORD_LEN_7      0x02L   /* set Word Lengto to 7 Bits      */
#define LCR_WORD_LEN_8      0x03L   /* set Word Lengto to 8 Bits      */

#define LCR_ONE_STOP_BIT    0x00L   /* set One Stop Bit               */
#define LCR_TWO_STOP_BITS   0x04L   /* Two Stop bits when words of length  6,7 or 8 bits, */
                                   /* 1.5 Stop Bits when words of length 5 bits */

#define LCR_NO_PARITY       0x00L    /* No Parity   */
#define LCR_ODD_PARITY      0x08L    /* Odd Parity  */
#define LCR_EVEN_PARITY     0x18L    /* Even Parity */

#define LCR_STICKY_PARITY_LOW       0x38L    /* Low Parity (Sticky) */
#define LCR_STICKY_PARITY_HIGH      0x28L    /* High Parity (Sticky) */

#define LCR_BREAK_DISABLE   0xBFL    /* Clear Break Enable                */
#define LCR_BREAK_ENABLE    0x40L    /* Set Break Enable                  */

#define LCR_DLAB_SET        0x80L    /* Divisor Latch Access Bit          */
#define LCR_DLAB_UNSET      0x00L    /* Access BRB,THR, IER               */


/*****		MCR 	******/
#define MCR_FORCE_DTR       0x00L    /* Force Data Terminal Ready         */
#define MCR_FORCE_RTS       0x02L    /* Force Request to Send             */
#define MCR_ENABLE_INTS     0x08L    /* Aux Output 2  -Ring Indication    */

#define MCR_AFE             0x20L    /* Auto Flow Control  */

#define MCR_CLEAR_FORCE_RTS_MASK   0xfffffffdL  /* Request To send  */
#define MCR_CLEAR_FORCE_DTR_MASK   0xfffffffeL  /* Data Terminal Ready */

/*****		LSR 	******/
#define LSR_DATA_READY      0x01L  /* Data ready in the RX FIFO             */
#define LSR_OVRRUN_ERR      0x02L  /* Framing Error                         */
#define LSR_PARITY_ERR      0x04L  /* Parity error detected                 */
#define LSR_FRAMING_ERR     0x08L  /* Framing error detected                */

#define LSR_BREAK_INT       0x10L  /* break Interrupt                       */
#define LSR_EMP_TREG        0x20L  /* Empty Transmitter Holding Register - more then 32 byte inthe fIFO are free */
#define LSR_EMP_DATA        0x40L  /* Empty Data Holding Registers - 64 byte in the FIFO are free        */
#define LSR_FIFO_ERR        0x80L  /* Error in Received FIFO                */

#define LSR_FIFO_EMPTY      0x60L  /* Both TREG & DATA are empty -> FIFO empty on FIFO mode */
#define LSR_ERROR_MASK      0x0EL  /* masking error bits out of LSR       */



/*****		MSR 	******/
#define MSR_DELTA_CTS       0x01L    /* Delta Clear to Send          */
#define MSR_DELTA_DSR       0x02L    /* Delta Data Set Ready         */
#define MSR_TRAILING_RI     0x04L    /* Trailing Edge Ring Indicator */
#define MSR_DELTA_DATA_CD   0x08L  /* Delta Data Carrier Detect  */
#define MSR_CTS             0x10L    /* Clear To Send                */
#define MSR_DSR             0x20L    /* Data Set Ready               */
#define MSR_RI              0x40L    /* Ring Indicator               */
#define MSR_CD              0x80L    /* Carrier Detect               */


/*****		IrDa 	******/
#define	UART_ISR_RXPL					0x10	/* SIR decoder takes negative pulses as zeros */
#define	UART_ISR_TXPL					0x08	/* SIR encoder takes negative pulses as zeros */
#define	UART_ISR_XMODE					0x04	/* Transmit 1.6 microsec width pulses */
#define	UART_ISR_RCVEIR					0x02	/* Receiver input is in infrared mode */
#define	UART_ISR_XMITIR					0x01	/* Transmitter output is in infrared mode */
#define	UART_ISR_ALL_ZERO_UART_DEFUALT	0		/* postive pulses as zeros, normal pulse, UART input/output mode */


/*****		Auto-Baud 	******/
#define	UART_ABR_ABT					0x08	/* Formula used to calculate baud rates */
#define	UART_ABR_ABUP					0x04	/* Programs Divisor Latch registers */
#define	UART_ABR_ABLIE					0x02	/* Auto-baud-lock interrupt, 0-disabled, 1-enabled */
#define	UART_ABR_ABE					0x01	/* Auto-baud enable*/

/***************    WRITE to UART registers  - inline functions     **********************************************************/

//TBD these macro's used from outside UART as well as from inside it.
#define UARTWakeUp(port) UARTOn((UART_Port)(port),UART_ACTIVITY_EXT)
#define	HW_UART_WRITE_THR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_THR_ADD)) = (val));\
}

#define	HW_UART_WRITE_DLL(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_DLL_ADD)) = (val));\
}


#define	HW_UART_WRITE_DLM(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_DLM_ADD)) = (val));\
}


#define	HW_UART_WRITE_IER(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_IER_ADD)) = (val));\
}

#define	HW_UART_IER_DISABLE_INT(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((*((volatile UINT32 *)((uart) + UART_IER_ADD))) &= (~(val)));\
}

#define	HW_UART_IER_ENABLE_INT(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((*((volatile UINT32 *)((uart) + UART_IER_ADD))) |= (val));\
}

#define	HW_UART_WRITE_FCR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_FCR_ADD)) = (val));\
}


#define	HW_UART_WRITE_IIR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_IIR_ADD)) = (val));\
}


#define	HW_UART_WRITE_LCR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_LCR_ADD)) = (val));\
}


#define	HW_UART_WRITE_MCR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_MCR_ADD)) = (val));\
}


#define	HW_UART_WRITE_LSR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_LSR_ADD)) = (val));\
}


#define	HW_UART_WRITE_SPR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_SPR_ADD)) = (val)); \
}


#define	HW_UART_WRITE_ISR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_ISR_ADD)) = (val)); \
}


#define HW_UART_WRITE_AB_MCR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_AB_MCR_ADD)) = (val)); \
}


#define HW_UART_WRITE_ABR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    (*((volatile UINT32 *)((uart) + UART_ABR_ADD)) = (val)); \
}


/***************    READ from UART registers  - inline functions    *********************************************************/
#define	HW_UART_READ_RHR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((val) = (BYTE)(*((volatile UINT32 *)((uart) + UART_RHR_ADD)))); \
}


#define	HW_UART_READ_DLL(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((val) = *((volatile UINT32 *)((uart) + UART_DLL_ADD))); \
}


#define	HW_UART_READ_DLM(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((val) = *((volatile UINT32 *)((uart) + UART_DLM_ADD))); \
}


#define	HW_UART_READ_IER(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((val) = *((volatile UINT32 *)((uart) + UART_IER_ADD))); \
}


#define	HW_UART_READ_IIR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((val) = *((volatile UINT32 *)((uart) + UART_IIR_ADD))); \
}


#define	HW_UART_READ_LCR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((val) = *((volatile UINT32 *)((uart) + UART_LCR_ADD))); \
}


#define	HW_UART_READ_MCR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((val) = *((volatile UINT32 *)((uart) + UART_MCR_ADD))); \
}


#define	HW_UART_READ_LSR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((val) = *((volatile UINT32 *)((uart) + UART_LSR_ADD))); \
}


#define	HW_UART_READ_MSR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((val) = *((volatile UINT32 *)((uart) + UART_MSR_ADD))); \
}


#define	HW_UART_READ_SPR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((val) = *((volatile UINT32 *)((uart) + UART_SPR_ADD))); \
}


#define	HW_UART_READ_ISR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((val) = *((volatile UINT32 *)((uart) + UART_ISR_ADD))); \
}

#define	HW_UART_READ_FOR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
    ((val) = *((volatile UINT32 *)((uart) + UART_FOR_ADD))); \
}


#define	HW_UART_READ_FCR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
	((val) = *((volatile UINT32 *)((uart) + UART_FCR_ADD))); \
}

#define	HW_UART_READ_ABR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
	((val) = *((volatile UINT32 *)((uart) + UART_ABR_ADD))); \
}

#define	HW_UART_READ_ACR(uart,val)  \
{									 \
	HW_UART_WAKEUP(uart);			 \
	((val) = *((volatile UINT32 *)((uart) + UART_ACR_ADD))); \
}

#define SET_DLAB_BIT (*((volatile UINT32*)0xd40a000c) |= 0x80)
#define RESET_DLAB_BIT (*((volatile UINT32*)0xd40a000c) &= 0xFFFFFF7F)
#endif			/* __HW_ACCESS_D_H__ */
