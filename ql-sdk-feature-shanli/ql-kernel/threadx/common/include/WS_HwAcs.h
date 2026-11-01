/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/


/************************************************************************/
/*                                                                      */
/* Title: IPC Comm. pacakge header file                                 */
/*                                                                      */
/* Filename:  HwAcs.h                                                   */
/*                                                                      */
/* Authors: Adi Dayan                                                   */
/*                                                                      */
/* Target, subsystem: Common Platform, HAL								*/
/*																		*/
/* Notes: Addresses and definitions according to the document:			*/
/*        " Inter Processor Communication (IPC) HW definition,			*/
/*			WBCDMA EVB, 28-Jun-00, D-Core FPGA IPC Description "		*/
/************************************************************************/
#ifndef _WS_HwAcs_H_

  #define _WS_HwAcs_H_

/*----------------------------------------------------------------------*/
#include <gbl_config.h> //For DSP_ROM_MASK definition

#include "global_types.h"

/*----------------------------------------------------------------------*/

/************ IPC Registers Addresses ****************************/
//same for TTC,Nevo,Wukong,Wujing, segual family CP

#define IPC_CONTROL_REGISTERS_BASE_ADD	 0xD401d000/* base address of the IPC module (APB) */

#define IPC_CMD_MSG_BUFFER_BASE_ADD 	 BsramBaseAddr
#define BSRAM_MEMORY_SIZE       0x8000 //32KB

/************ Cyclic Buffers Parameters ****************************/
#define TX_CMD_BUFFER_START 	(IPC_CMD_MSG_BUFFER_BASE_ADD + 0x0000)
#define TX_CMD_BUFFER_END		(IPC_CMD_MSG_BUFFER_BASE_ADD + 0x07fc)	// buffer size 0x280 byte
					
#define RX_MSG_BUFFER_START 	(IPC_CMD_MSG_BUFFER_BASE_ADD + 0x0800)
#define RX_MSG_BUFFER_END		(IPC_CMD_MSG_BUFFER_BASE_ADD + 0x0ffc)	// buffer size 0x280 byte

/*----------------------------------------------------------------------*/
#define TX_CMD_BUFFER_BYTE_SIZE ( (TX_CMD_BUFFER_END+4) - TX_CMD_BUFFER_START )
#define RX_MSG_BUFFER_BYTE_SIZE ( (RX_MSG_BUFFER_END+4) - RX_MSG_BUFFER_START )



/************ Control Registers *********************************/
#define PLP_INT_SET             (IPC_CONTROL_REGISTERS_BASE_ADD + 0x0008)      /* offset-address of the PLP_INT_SET register */
#define ACP_INT_CLR             (IPC_CONTROL_REGISTERS_BASE_ADD + 0x000C)      /* offset-address of the ACP_INT_CLR register */
#define ACP_DATA_ACK_INT_VEC    (IPC_CONTROL_REGISTERS_BASE_ADD + 0x0010)      /* offset-address of the ACP_DATA_ACK_INT_VEC register */

// Poll-values (tail indexes) in DSP memory
#define CPU2DSP_POLL_REG        (IPC_CONTROL_REGISTERS_BASE_ADD + 0x0004)      /* offset-address of the POLL_REG    register */
#define DSP2CPU_POLL_REG        (IPC_CONTROL_REGISTERS_BASE_ADD + 0x0014)      /* offset-address of the POLL_REG    register */



/************ Interrupts Definitions ***************************/

    /** NOTE: the required value to be put in one of the control registers - SET / CLEAR **/

#define CLR_ACP_RD_INT				0x00000100			/* clears a RD_INT from the DSP */
#define CLR_ACP_ACK_INT 			0x00000200			/* clears an ACK_INT from the DSP */
#define CLR_ACP_GP_INT				0x00000400			/* clears an GP_INT from the DSP */
#define CLR_ACP_DATA_ACK_CH_0_INT	0x00000001			/* clears a DATA_ACK_INT on channel 0 from the DSP */
#define CLR_ACP_DATA_ACK_CH_1_INT	0x00000002			/* clears a DATA_ACK_INT on channel 1 from the DSP */
#define CLR_ACP_DATA_ACK_CH_2_INT	0x00000004			/* clears a DATA_ACK_INT on channel 2 from the DSP */
#define CLR_ACP_DATA_ACK_CH_3_INT	0x00000008			/* clears a DATA_ACK_INT on channel 3 from the DSP */
#define CLR_ACP_DATA_ACK_CH_4_INT	0x00000010			/* clears a DATA_ACK_INT on channel 4 from the DSP */
#define CLR_ACP_DATA_ACK_CH_5_INT	0x00000020			/* clears a DATA_ACK_INT on channel 5 from the DSP */
#define CLR_ACP_DATA_ACK_CH_6_INT	0x00000040			/* clears a DATA_ACK_INT on channel 6 from the DSP */
#define CLR_ACP_DATA_ACK_CH_7_INT	0x00000080			/* clears a DATA_ACK_INT on channel 7 from the DSP */


#define SET_PLP_RD_INT				0x00000100			/* issues a RD_INT to the DSP */
#define SET_PLP_ACK_INT 			0x00000200			/* issues an ACK_INT to the DSP */
#define SET_PLP_GP_INT				0x00000400			/* issues an GP_INT to the DSP */
#define SET_PLP_DATA_ACK_CH_0_INT	0x00000001			/* issues a DATA_ACK_INT on channel 0 to the DSP */
#define SET_PLP_DATA_ACK_CH_1_INT	0x00000002			/* issues a DATA_ACK_INT on channel 1 to the DSP */
#define SET_PLP_DATA_ACK_CH_2_INT	0x00000004			/* issues a DATA_ACK_INT on channel 2 to the DSP */
#define SET_PLP_DATA_ACK_CH_3_INT	0x00000008			/* issues a DATA_ACK_INT on channel 3 to the DSP */
#define SET_PLP_DATA_ACK_CH_4_INT	0x00000010			/* issues a DATA_ACK_INT on channel 4 to the DSP */
#define SET_PLP_DATA_ACK_CH_5_INT	0x00000020			/* issues a DATA_ACK_INT on channel 5 to the DSP */
#define SET_PLP_DATA_ACK_CH_6_INT	0x00000040			/* issues a DATA_ACK_INT on channel 6 to the DSP */
#define SET_PLP_DATA_ACK_CH_7_INT	0x00000080			/* issues a DATA_ACK_INT on channel 7 to the DSP */



/************ Interrupts Sources**** ************/
typedef enum
{
 RD_INT_SRC,
 ACK_INT_SRC,
 DATA_ACK_INT_SRC,
 GP_INT_SRC,
 MAX_IPC_INT_SRC
} IpcIntSources;

#define INTSRC(x) ((INTC_InterruptSources)(_IPCommInterruptSource[x]))

/************ Control Registers Initiation (clear) Definition ************************/
#define CLEAR_IPC_REGISTER      0x0000
#define SET_IPC_REGISTER        0xFFFF

/*----------------------------------------------------------------------*/

/******************** Command ********************/

#define hwAcs_IPC_32bits_WRITE(a) \
         {   (  *( (volatile UINT32*)(_CPU2DSPBufferCurrentPtr) ) = (a)  );  \
             if ( _CPU2DSPBufferCurrentPtr == TX_CMD_BUFFER_END ) \
             { \
                 _CPU2DSPBufferCurrentPtr = TX_CMD_BUFFER_START; \
             } \
             else \
             { \
                _CPU2DSPBufferCurrentPtr += 4; \
             } \
         }


#define hwAcs_IPC_32bits_CMD_HEADER_WRITE(op,ln) \
        hwAcs_IPC_32bits_WRITE( ( (UINT32)(((ln) << 16) | (op)) ) )


#define hwAcs_IPC_32bits_DATA_CMD_HEADER_WRITE(dh) \
        { hwAcs_IPC_32bits_WRITE(*dh); \
          hwAcs_IPC_32bits_WRITE(*(++dh)); \
        }


#define hwAcs_IPC_32bits_CMD_DATA_WRITE(dt,ln) \
        {   UINT32 x; \
            UINT16 rln = ln; \
            UINT8 *pArr = dt; \
            while (rln >= 4) \
            { \
                x = ( *(pArr) | (((UINT32)(*(pArr+1)))<<8) | (((UINT32)(*(pArr+2)))<<16) | (((UINT32)(*(pArr+3)))<<24) ); \
                pArr += 4;  \
                hwAcs_IPC_32bits_WRITE(x); \
                rln -= 4; \
            }; \
            if (rln == 3) \
            { \
               x = ( *(pArr) | (((UINT32)(*(pArr+1)))<<8) | (((UINT32)(*(pArr+2)))<<16) ); \
               hwAcs_IPC_32bits_WRITE(x); \
            } \
            else if (rln == 2) \
            { \
               x = ( *(pArr) | (((UINT32)(*(pArr+1)))<<8) ); \
               hwAcs_IPC_32bits_WRITE(x); \
            } \
            else if (rln == 1) \
            { \
               x = *(pArr); \
               hwAcs_IPC_32bits_WRITE(x); \
            }; \
        }

/******************** Message ********************/

#define MOVE_DSP2CPU_BUFFER_NEXT_PTR(ln)

#define hwAcs_IPC_32bits_READ(a) \
        {  ( (a) = *( (volatile UINT32*)(_DSP2CPUBufferCurrentPtr) )  );  \
            if ( _DSP2CPUBufferCurrentPtr == RX_MSG_BUFFER_END ) _DSP2CPUBufferCurrentPtr = RX_MSG_BUFFER_START; \
            else                                                 _DSP2CPUBufferCurrentPtr += 4; \
        }

// Read message from DSP with length in bytes - in fragments of 8 bits
#define hwAcs_IPC_32bits_MSG_HEADER_READ(op,ln) \
        {   UINT32 hd; \
            hwAcs_IPC_32bits_READ(hd);  \
            op = (UINT16)(hd); \
            ln = (UINT16)(hd >> 16); \
        }


/******************** Data ********************/
#define DATA_TMP_ADD 0x12345678
#define TMP_DATA_BUFF_SIZE 0x1234

typedef UINT32 DataBuff[TMP_DATA_BUFF_SIZE];

#define hwAcs_IPC_DATA_WRITE \
   (*((volatile DataBuff*)(DATA_TMP_ADD)))

#define hwAcs_IPC_DATA_READ \
   (*((volatile DataBuff*)(DATA_TMP_ADD)))


/************ Writing to the IPC Control Register ***************************/
#define hwAcs_IPC_CONTROL_WRITE(IPCCtrlReg,interrupt) \
(*((volatile UINT32 *)(IPCCtrlReg)) = (interrupt))

/************ Writing to the Poll Register ***************************/
#define hwAcs_IPC_POLL_WRITE(val) \
(*((volatile UINT32 *)(CPU2DSP_POLL_REG)) = (val))

/************ Reading a Register ***************************/
UINT32 hwAcs_IPC_REG_READ(UINT32 reg);

#ifndef IPC_POLL_SOFT_REG
#ifndef IPC_SAFE_POLL_READ
#define hwAcs_IPC_POLL_READ       hwAcs_IPC_REG_READ(DSP2CPU_POLL_REG)
#else //PROTO: h/w problem, read value may be corrupted if DSP writes to POLL at the same moment
UINT32 hwAcs_SafePollRead(void);
#define hwAcs_IPC_POLL_READ hwAcs_SafePollRead()
#endif
#else
#define hwAcs_IPC_POLL_READ (*(volatile UINT32*)DSP2CPU_POLL_REG)
#endif


#define hwAcs_IPC_CONTROL_READ    hwAcs_IPC_REG_READ
/*----------------------------------------------------------------------*/

/********************** Prototypes ****************************/

void hwAcsBindLISRToINTC(void);
void hwAcsUnBindLISRToINTC(void);
void hwAcsEnableInterrupts(void);
void hwAcsDisableInterrupts(void);
void hwAcsLISRAckInt(UINT32 sourceNum);
void hwAcsLISRRdInt(UINT32 sourceNum);
void hwAcsLISRDataAckInt(UINT32 sourceNum);
void hwAcsLISRTTPInt(UINT32 sourceNum);
void hwAcsConfigureInterrupts(void);

#define IPC_POLL_IN_ACK

#endif  /* _WS_HwAcs_H_ */
