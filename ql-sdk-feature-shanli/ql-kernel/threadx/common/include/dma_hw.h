/*--------------------------------------------------------------------------------------------------------------------
(C) Copyright 2006, 2007 Marvell DSPC Ltd. All Rights Reserved.
-------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
*                      M O D U L E     B O D Y                       *
**********************************************************************
* Title: Direct Memory Access - DMA                                  *
*                                                                    *
* Filename: dma_hw.h                                             *
*                                                                    *
* Target, platform: Arbel Platform, Tavor                            *
*                                                                    *
* Author: Olga Fomenko                                               *
*                                                                    *
* Description: This is the HARDWARE file header for the DMA pacakge  *
*              in contains all the hardware definitions for DMA and  *
*              internal type definitions                             *
* Notes:                                                             *
**********************************************************************
*/

#ifndef _DMA_HW_H_
#define _DMA_HW_H_

#include "global_types.h"

#define DMA_HW_BASE_ADDRESS                     0xFFD01000

//#define CDMA1_MUX_REGISTER  0xFFA04010   // used by MSA only

#ifdef PHS_SW_DEMO_TTC
#define CDMA2_MUX_REGISTER  0xF0240004
#else
#define CDMA2_MUX_REGISTER  0xF0204004

#define CDMA3_MUX_REGISTER  0xF0204008
#endif

#define DMA_HW_CHANNELS_PER_CONTROLLER          8       // number of channels supported by each controller

#ifdef PHS_SW_DEMO_TTC
#define DMA_NUMBER_OF_DMA_HW_CONTROLLERS        2       // DMA C1 - 0xFFD01000, DMA C2 - 0xFFD02000
#else
#define DMA_NUMBER_OF_DMA_HW_CONTROLLERS        3       // DMA C1 - 0xFFD01000, DMA C2 - 0xFFD02000, & DMA C3 - 0xFFD03000
#endif
#define DMA_TOTAL_NUMBER_OF_CHANNELS            (DMA_HW_CHANNELS_PER_CONTROLLER * DMA_NUMBER_OF_DMA_HW_CONTROLLERS)

#define DMA_TIMEOUT_STOP_COUNT                  5000   // number of times "wait loop" in stopChannel service run

#define DMA_SIZE_OF_RESERVED_MEMORY_BLOCK       0xF70   // 0x2000-0x1090

#define DMA_MAX_NUMBER_OF_PACKETS               1023

typedef struct
{
    UINT32      DCSAR;  // DMA Channel Source Address Register         R/W
    UINT32      DCDAR;  // DMA Channel Destination Address Register    R/W
    UINT32      DCBCR;  // DMA Channel Byte Count Register             R/W
    UINT32      DCCR;   // DMA Channel Control Register                R/W
} DMA_ChannelHWRegistersS;


typedef struct
{
    UINT32                      DCR; // DMA C1 Control Register        R/W1
    UINT32                      Reserved1;       //
    UINT32                      DESR; // DMA C1 Error Source Register  R/W1
    UINT32                      Reserved2;
    DMA_ChannelHWRegistersS     ChannelRegister[DMA_HW_CHANNELS_PER_CONTROLLER];
    UINT8                       Reserved[DMA_SIZE_OF_RESERVED_MEMORY_BLOCK];
}DMA_ControllerRegistersS;

typedef struct
{
    //DMA_ControllerRegisters       controller[DMA_NUMBER_OF_DMA_HW_CONTROLLERS];
    DMA_ControllerRegistersS      controller[DMA_NUMBER_OF_DMA_HW_CONTROLLERS];

}DMA_HardwareRegistersS;

#define DmaHwRegisters      (*(volatile DMA_HardwareRegistersS *)DMA_HW_BASE_ADDRESS)



// DMAC MUX register
#define DMA_MUX_REGISTER_CHANNEL_SHIFT(logicalChannel)      (logicalChannel*2)

#define DMA_MUX_REGISTER_CHANNEL_MASK(logicalChannel)        (0x00000003 << DMA_MUX_REGISTER_CHANNEL_SHIFT(logicalChannel))

//------------------ DMA Error Source Register masks ----------------------
// setting this mask clear DESR register for all channel - initialization
#define DMA_DESR_CLEAR_MASK                   0xFFFF00FF
// this mask purpose is clearing error bits of only one channel (by default-0).
// to setting this mask to channel X => do shift rigth X of thos mask
#define DMA_DESR_CHANNEL0_MASK                0x80800080


//------------------ DMA Control Register ----------------------------------
// setting this bit starts the channel
// points to channel "0" start bit, do bitwise shift right for other channels
#define DMA_CHANNEL_START_BIT                  0x80000000
// setting this bitterminates channel execution
// points to channel "0" terminate bit, do bitwise shift right for other channels
#define DMA_CHANNEL_TERMINATE_BIT              0x00800000


//------------------ DMA Control Channel Register masks ---------------------
// Go Enable bit: 1-go-enable mode transaction; 0-one-shot mode transaction
#define DMA_CCR_GE_BIT_MASK                    0x80000000
// Interrupt Enable bit
#define DMA_CCR_IE_BIT_MASK                    0x20000000
// Transfer size bits
#define DMA_CCR_TSZ_MASK                       0x00C00000
        #define DMA_CCR_TSZ_BYTE_MASK          0x00000000   // transfer in 8-bit units
        #define DMA_CCR_TSZ_WORD_MASK          0x00400000   // transfer in 16-bit units
        #define DMA_CCR_TSZ_DWORD_MASK         0x00800000   // transfer in 32-bit units
        #define DMA_CCR_TSZ_QWORD_MASK         0x00C00000   // transfer in 64-bit units

// Source Addr Post modifier  bits
#define DMA_CCR_SAPM_MASK                      0x00300000
        #define DMA_CCR_SAPM_SHIFT             20           // 00=>inc; 01=>dec; 10=>no change; 11=>reserved

// Destination Addr Post modifier  bits
#define DMA_CCR_DAPM_MASK                      0x000C0000   // 00=>inc; 01=>dec; 10=>no change; 11=>reserved
        #define DMA_CCR_DAPM_SHIFT             18

// Transfer direction bit
#define DMA_CCR_TD_BIT_MASK                    0x00010000
      //  #define DMA_A2B                        0            // transfer from port A to port B
       // #define DMA_B2A                        1            // transfer from port B to port A

// Request to Channel Mapping
#define DMA_CCR_RTCM_MASK                      0x00007000   // 000-DMA_REQ[0]...111-DMA_REQ[7]
        #define DMA_CCR_RTCM_SHIFT             12

// DMA Byte Count Register
#define DMA_PLEN_MASK                          0x3FFF0000    // Packet Length (set in the TSZ)
	#define DMA_PLEN_SHIFT                 16
#define DMA_PCNT_MASK                          0x000003FF    // Packet Count
#define DMA_EWD_MASK			       0x00008000
#define DMA_EWOD_MASK                          0x00004000

/////////////////////////////////////////////////////////////////////
// basic MACROS - In-Line functions
/////////////////////////////////////////////////////////////////////

#define DMA_CHANNEL_SET_GO_ENABLE(channel)            ( (DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].ChannelRegister[DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)].DCCR) |= \
                                                                            DMA_CCR_GE_BIT_MASK )

#define DMA_CHANNEL_CLEAR_GO_ENABLE(channel)          ( (DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].ChannelRegister[DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)].DCCR) &= \
                                                                            (~DMA_CCR_GE_BIT_MASK) )

#define DMA_CHANNEL_SET_INTERRUPT_ENABLE(channel)     ( (DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].ChannelRegister[DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)].DCCR) |= \
                                                                             DMA_CCR_IE_BIT_MASK )

#define DMA_CHANNEL_CLEAR_INTERRUPT_ENABLE(channel)   ( (DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].ChannelRegister[DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)].DCCR) &= \
                                                                            (~DMA_CCR_IE_BIT_MASK) )

#define DMA_CLEAR_DCCR(channel)                       { DMA_CHANNEL_SET_GO_ENABLE(channel); \
                                                             DMA_CHANNEL_SET_INTERRUPT_ENABLE(channel);}

#define DMA_GET_CONTROLLER_NUMBER(channel)            (channel>>3)     // channle/DMA_HW_CHANNELS_PER_CONTROLLER)

#define DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)      (channel & 0x07L) //(channel%DMA_HW_CHANNELS_PER_CONTROLLER )

#define DMA_CLEAR_DESR(channel)                       { DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].DESR |= \
                                                                              DMA_DESR_CLEAR_MASK ;}

#define DMA_SET_SOURCE_ADDR(channel, addr)            {DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].ChannelRegister[DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)].DCSAR = \
                                                                             (UINT32)addr;}

#define DMA_SET_DEST_ADDR(channel, addr)              {DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].ChannelRegister[DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)].DCDAR = \
                                                                              (UINT32)addr;}

#define DMA_CLEAR_DESR_CHANNEL_BITS(channel)          {DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].DESR |= \
                                                                               ( DMA_DESR_CHANNEL0_MASK >> DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel) );}

#define DMA_SET_DIRECTION_A2B(channel)                {DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].ChannelRegister[DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)].DCCR &= \
                                                                               (~DMA_CCR_TD_BIT_MASK);}

#define DMA_SET_DIRECTION_B2A(channel)                {DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].ChannelRegister[DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)].DCCR \
                                                                               |= DMA_CCR_TD_BIT_MASK;}

#define DMA_SET_PACKET_LEN(channel, packetLength)     { DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].ChannelRegister[DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)].DCBCR &= (~DMA_PLEN_MASK);\
                                                            DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].ChannelRegister[DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)].DCBCR |= \
                                                                              (packetLength <<16);}

#define DMA_SET_PACKET_COUNT(channel, packetCount)    { DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].ChannelRegister[DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)].DCBCR &= (~DMA_PCNT_MASK);\
                                                            DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].ChannelRegister[DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)].DCBCR |= packetCount;}

#define DMA_IS_CHANNEL_ERROR(channel)                 ( DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].DESR & \
                                                                            (DMA_DESR_CHANNEL0_MASK>>DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel) ))

//TBD
#define DMA_IS_CHANNEL_ENDED(channel)                (TRUE)


#ifdef DMA_DEBUG
#define DEBUG_GPO0_SET (*(UINT32 *)0xD4060208 = 0x1) 
#define DEBUG_GPO0_CLEAR (*(UINT32 *)0xD406020C = 0x1) 
#define DEBUG_GPO1_SET (*(UINT32 *)0xD4060208 = 0x2) 
#define DEBUG_GPO1_CLEAR (*(UINT32 *)0xD406020C = 0x2) 
#endif //DMA_DEBUG

// these registers exist only in A0
#define DMAC_EOCINH_WR_BASE         0xF0260000    
		//#define DMAC1_EOCINH_WR_OFFSET      0x0    
		//#define DMAC2_EOCINH_WR_OFFSET      0x4
		//#define DMAC3_EOCINH_WR_OFFSET      0x8
#define DMAC_EOCINH_EOIC_BIT_MASK     0x1

#ifdef PHS_SW_DEMO_TTC
#define DMA_ENABLE_EOC(controller, channel)    ( (controller==0)?(*(UINT32*)0xFFB00018):(*(UINT32*)0xF0240008)) = ((channel<<1)|DMAC_EOCINH_EOIC_BIT_MASK) )
#else
#define DMA_ENABLE_EOC(controller, channel)    ( *(UINT32*)(DMAC_EOCINH_WR_BASE+4*(controller)) = ((channel<<1)|DMAC_EOCINH_EOIC_BIT_MASK) )
#endif

#if 0
#ifdef PHS_SW_DEMO_TTC
#define DMA_ENABLE_EOC(controller, channel)    ( (controller==0)?(*(UINT32*)0xFFB00018):(*(UINT32*)0xF0240008)) = ((channel<<1)|DMAC_EOCINH_EOIC_BIT_MASK) )
#else
#define DMA_DISABLE_EOC(controller, channel)    ( *(UINT32*)(DMAC_EOCINH_WR_BASE+4*(controller)) = (channel<<1) )
#endif
#else
#ifdef PHS_SW_DEMO_TTC
//#define DMA_DISABLE_EOC(controller, channel)    ( (controller==0)?(*(UINT32*)0xFFB00018):(*(UINT32*)0xF0240008)) = (channel<<1)
#define DMA_DISABLE_EOC(controller, channel)    \
    if(controller==0)                           \
        *(UINT32*)0xFFB00018 = (channel<<1);    \
    else                                        \
        *(UINT32*)0xF0240008 = (channel<<1);
#else
#define DMA_DISABLE_EOC(controller, channel)    ( *(UINT32*)(DMAC_EOCINH_WR_BASE+4*(controller)) = (channel<<1) )
#endif

#endif

#endif //  _DMA_HW_H_

