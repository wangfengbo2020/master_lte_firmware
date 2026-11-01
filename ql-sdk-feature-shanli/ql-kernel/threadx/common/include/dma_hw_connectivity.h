/*--------------------------------------------------------------------------------------------------------------------
(C) Copyright 2006, 2007 Marvell DSPC Ltd. All Rights Reserved.
-------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
*                      M O D U L E     B O D Y                       *
**********************************************************************
* Title: Direct Memory Access - DMA                                  *
*                                                                    *
* Filename: dma_hw_connectivity.h                                    *
*                                                                    *
* Target, platform: Arbel Platform, Tavor                            *
*                                                                    *
* Author: Olga Fomenko                                               *
*                                                                    *
* Description: This is the HARDWARE file header for the DMA pacakge. *
*              It contains connectivity tables - system definitions. *
* Notes:  CURRENT STATUS - TBD !!!!                                  *
**********************************************************************
*/
#ifndef _DMA_HW_CONNECTIVITY_H_
#define _DMA_HW_CONNECTIVITY_H_

 #include "intc_list.h"
 #include "global_types.h"

typedef enum
{
  // DMAC1
    DMA_CHANNEL_0            = 0x00,
    DMA_CHANNEL_1            = 0x01,
    DMA_CHANNEL_2            = 0x02,
    DMA_CHANNEL_3            = 0x03,
    DMA_CHANNEL_4            = 0x04,
    DMA_CHANNEL_5            = 0x05,
    DMA_CHANNEL_6            = 0x06,
    DMA_CHANNEL_7            = 0x07,
    DMA_CHANNEL_8            = 0x08,
  // DMAC2
    DMA_CHANNEL_9            = 0x09,
    DMA_CHANNEL_10           = 0x0A,
    DMA_CHANNEL_11           = 0x0B,
    DMA_CHANNEL_12           = 0x0C,
    DMA_CHANNEL_13           = 0x0D,
    DMA_CHANNEL_14           = 0x0E,
    DMA_CHANNEL_15           = 0x0F,
//#ifndef PHS_SW_DEMO_TTC
  // DMAC3
    DMA_CHANNEL_16           = 0x10,
    DMA_CHANNEL_17           = 0x11,          // disable  tbd
    DMA_CHANNEL_18           = 0x12,
    DMA_CHANNEL_19           = 0x13,
    DMA_CHANNEL_20           = 0x14,
    DMA_CHANNEL_21           = 0x15,
    DMA_CHANNEL_22           = 0x16,
    DMA_CHANNEL_23           = 0x17
//#endif    
}DMA_ChannelE;


typedef enum
{
    DMA_DREQCHANNEL0 = 0,
    DMA_DREQCHANNEL1,
    DMA_DREQCHANNEL2,
    DMA_DREQCHANNEL3,
    DMA_DREQCHANNEL4,
    DMA_DREQCHANNEL5,
    DMA_DREQCHANNEL6,
    DMA_DREQCHANNEL7,
    DMA_DREQDEFAULT = 0xFF
}DMA_DREQConnectionE;

typedef enum
{
    DMA_MUXCONNECTION_0 = 0x00,
    DMA_MUXCONNECTION_1 = 0x01,
    DMA_MUXCONNECTION_2 = 0x02,
    DMA_MUXCONNECTION_3 = 0x03,
    DMA_MUXDEFAULT      = 0xFF
}DMA_MUXConnectionE;

typedef struct
{
    BOOL                      isChannelAvailable;
    INTC_InterruptSources     interruptConnection;
    DMA_DREQConnectionE       dreqConnection;
}DMA_ConnectivityS;

#define DMA_NUMBER_OF_DEVICES      8

#define DMA_CHANNEL_DTCM_2_DTCM    DMA_CHANNEL_16
#define DMA_CHANNEL_DTCM_2_DDR     DMA_CHANNEL_18

//#define DMA_CDMA1_MUX_REGISTER_INIT_VALUE = 0x0   // configured by MSA
#ifdef PHS_SW_DEMO_TTC
#define DMA_CDMA2_MUX_REGISTER_INIT_VALUE  0x5004	  // shared reg (Arbel and MSA), configured by Arbel driver
#else
#define DMA_CDMA2_MUX_REGISTER_INIT_VALUE  0x2000     // shared reg (Arbel and MSA), configured by Arbel driver
#define DMA_CDMA3_MUX_REGISTER_INIT_VALUE  0x0880     // Belongs to Arbel only
#endif

extern INTC_InterruptSources           _dmaInterruptConnectivityTable[];
extern DMA_DREQConnectionE             _dmaDREQConnection[];
extern BOOL                            _dmaIsChannelAvailableTable[];
extern UINT8                           _dmaConnectExternalMuxDREQLegality[];
extern UINT8                           _dmaPortDirection[][DMA_NUMBER_OF_DEVICES];
extern UINT8                           _dmaExternalMuxConnection[];




#endif //_DMA_HW_CONNECTIVITY_H_
