/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/


/************************************************************************/
/*                                                                      */
/* Title: IPC Comm. pacakge header file                                 */
/*                                                                      */
/* Filename:  IPCCommConfig.h                                           */
/*                                                                      */
/* Authors: Adi Dayan                                                   */
/*                                                                      */
/* Target, subsystem: Common Platform, HAL                              */
/************************************************************************/
#ifndef _WS_IPCCommConfig_H_

  #define _WS_IPCCommConfig_H_
/*----------------------------------------------------------------------*/


/****************** IPCComm Package Global Compilation Flags ********************/
//#define MANITOBA_PROTO
//#define THELON
//#define HERMON_PROTO
//#define IPC_DEBUG
//#define IPC_AAAP_MODE
//#define ARM7
//#define IPC_TEST

/*----------------------------------------------------------------------*/


typedef UINT8 ApplicationID;

/*----------------------------------------------------------------------*/


#define HS_MAX_NUM_OF_SUB_OPCODE 64       /* was 10 */
#define HS_MAX_NUM_OF_SET_ID 16           /* was 3 */

/*----------------------------------------------------------------------*/

#define MAX_NUM_OF_APPLICATIONS 256       /* 8 bits of application ID */

#define IPC_MAX_DATA_CH_NUM     8    //max up to 8

#define MAX_NUM_OF_REGISTERS    5

#define MAX_NUM_OF_MSGS_TO_POLL 10

#define DMA_TRANSFER_MINIMAL_DATA_SIZE  30000  // in bytes - the minimal size of a data packet to be transfered using DMA

#define DATA_CMD_MAXIMAL_LENGTH         30  // in bytes - the maximal size of a command attached to data transfer to the DSP

#define DATA_PACKET_MAX_SIZE_FOR_AAAP_ALLOCATION    8 //was 500  // in bytes - for DSP2CPU 'copy to unknown' - Get Pointer allocation response buffer

/*----------------------------------------------------------------------*/
/* include the global definition file (ipc_gbl_config.h), so these values could be overridden */

#ifdef _IPC_GBL_CONFIG_H_
#undef _IPC_GBL_CONFIG_H_
#endif
#include "IPC_gbl_config.h"


// Temp System Parameters Definition

#define IPCCommAppID 0xFE
#define AAAPAppID    0xFF

/*** IPC related set-ID's ***/
#define SYSTEM_SET_ID   0x0

/*** IPC related sub-opcodes ***/
// commands (CPU to DSP)
#define IPC_CMD_SUBOPCODE_ECHO                              0x00
#define IPC_CMD_SUBOPCODE_ECHO_RESPONSE                     0x01
#define IPC_CMD_SUBOPCODE_BUFFER_FREE_ACK                   0x0A
#define IPC_CMD_SUBOPCODE_DATA_LOCATION_POINTER_REQUEST     0x0B


// messages (DSP to CPU)
#define IPC_MSG_SUBOPCODE_ECHO                              0x00
#define IPC_MSG_SUBOPCODE_ECHO_RESPONSE                     0x01
#define IPC_MSG_SUBOPCODE_DATA_LOCATION_POINTER_RESPONSE    0x05

/*----------------------------------------------------------------------*/
/****** opcode field definitions and macros ******/

#define SUB_OPCODE_SHIFT    0
#define SUB_OPCODE_MASK     0x003F

#define SET_ID_SHIFT        6
#define SET_ID_MASK         0x03C0

#define DATA_BIT_SHIFT      13
#define DATA_BIT_MASK       0x2000

#define URGENT_BIT_SHIFT    14
#define URGENT_BIT_MASK     0x4000


#define CREATE_OPCODE_FIELD(o,so,si,d,u) \
    { \
        (o) = (o) | ( ((so) << SUB_OPCODE_SHIFT) | ((si) << SET_ID_SHIFT) | ((d) << DATA_BIT_SHIFT) | ((u) << URGENT_BIT_SHIFT) ); \
    }

#define EXTRACT_SUB_OPCODE(o)   ( ((o) & SUB_OPCODE_MASK) >> SUB_OPCODE_SHIFT )  // extracting the sub-opcode out of a given full op-code field
#define EXTRACT_SET_ID(o)       ( ((o) & SET_ID_MASK) >> SET_ID_SHIFT )          // extracting the SET ID out of a given full op-code field
#define EXTRACT_DATA_BIT(o)     ( ((o) & DATA_BIT_MASK) >> DATA_BIT_SHIFT )      // extracting the Data bit out of the opcode field
#define EXTRACT_URGENT_BIT(o)   ( ((o) & URGENT_BIT_MASK) >> URGENT_BIT_SHIFT )  // extracting the Urgent bit out of the opcode field

#define FRAGMENT_OPCODE_FIELD(o,so,si,d,u) \
    { \
        so = EXTRACT_SUB_OPCODE(o); \
        si = EXTRACT_SET_ID(o); \
        d = EXTRACT_DATA_BIT(o); \
        u = EXTRACT_URGENT_BIT(o); \
    }





/*----------------------------------------------------------------------*/


#endif  /* _WS_IPCCommConfig_H_ */

