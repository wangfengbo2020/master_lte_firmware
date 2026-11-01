/*--------------------------------------------------------------------------------------------------------------------
(C) Copyright 2006, 2007 Marvell DSPC Ltd. All Rights Reserved.
-------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
*                      M O D U L E     B O D Y                       *
**********************************************************************
* Title: Direct Memory Access - DMA                                  *
*                                                                    *
* Filename: dma.h                                                    *
*                                                                    *
* Target, platform: Tavor project, Arbel platform                    *
*                                                                    *
* Author: Olga Fomenko                                               *
*                                                                    *
* Description: This is the header file of DMA SW packet, includes    *
*              all API and user definitions                          *
* Notes:                                                             *
**********************************************************************/
#ifndef _DMA_HW_
#define _DMA_HW_

#include "dma_hw.h"
#include "dma_hw_connectivity.h"


// to compile this module for release version - comment this define
//#define DMA_DEBUG

#define DMA_CHANNEL_ICAT_RX   DMA_CHANNEL_14
#define DMA_CHANNEL_ICAT_TX   DMA_CHANNEL_21

#define DMA_CHANNEL_HSDPA     DMA_CHANNEL_8



typedef enum
{
    DMA_BYTE_TSZ = 1,
    DMA_WORD_TSZ = 2,
    DMA_DWORD_TSZ = 4,
    DMA_QWORD_TSZ = 8
}DMA_TransferSizeE;

typedef enum
{
    DMA_INC_BY_TSZ = 0,
    DMA_DEC_BY_TSZ = 1,
    DMA_NO_CHANGE = 2
}DMA_AddrPostModifierE;

typedef enum
{
    DMA_A2B = 0,
    DMA_B2A
}DMA_PortDirectionConnectionE;

typedef struct
{
    UINT32                        packetLength;
    DMA_TransferSizeE             transferSize;
    UINT8                         interruptsEnableBits;
    DMA_AddrPostModifierE         srcPostMod;
    DMA_AddrPostModifierE         dstPostMod;
    DMA_PortDirectionConnectionE  portConnection;
}DMA_SingleDescriptorS;

typedef struct
{
	UINT32                        packetLength;
	DMA_TransferSizeE             transferSize;
	//UINT8                         interruptsEnableBits;
	DMA_AddrPostModifierE         srcPostMod;
	DMA_AddrPostModifierE         dstPostMod;
	DMA_PortDirectionConnectionE  portConnection;
	void*                         srcAddr;
	void*                         dstAddr;
	UINT32                        numberOfPackets;
}DMA_ChainElementDescriptorS;

typedef enum 
{
	DMA_CHAIN_CYCLIC_MEM2MEM = 0,
	DMA_CHAIN_CYCLIC_MEM2PER,
	DMA_FINITE_CHAIN_MEM2MEM,
	DMA_FINITE_CHAIN_MEM2PER
}DMA_ChainTypeE;

#define DMA_IS_MEMORY_ONLY_TRANSACTION(type)        ((type==DMA_CHAIN_CYCLIC_MEM2MEM)|| \
														(type==DMA_FINITE_CHAIN_MEM2MEM))

typedef struct 
{
	DMA_ChainElementDescriptorS*  pChainDescArray;
	UINT32                        numDescs;
	UINT32                        currentDesc;
	DMA_ChainTypeE                chainType;
}DMA_ChainDescriptorS;


typedef enum
{
	DMA_GSSP1_Rx = 0,
	DMA_GSSP1_Tx,
	DMA_GSSP2_Rx,
	DMA_GSSP2_Tx,
	DMA_DSSP3_Rx,
	DMA_DSSP3_Tx
}DMA_PeripheralsE;



//--------- Notification Functions
typedef void (*DMATransferErrorNotifyFn)(UINT32 channel, UINT32 callbackCookie);
typedef void (*DMATransferEndedNotifyFn)(UINT32 channel, UINT32 callbackCookie);
typedef void (*DMATransferStoppedNotifyFn)(UINT32 channel, UINT32 callbackCookie);


typedef enum
{
    DMA_RC_CHANNEL_IS_BUSY=-5,
    DMA_RC_OK = 1,
    DMA_RC_CHANNAL_INVALID ,
    DMA_RC_CHANNEL_NOT_CLOSED,
    DMA_RC_CHANNEL_NOT_OPEN,
    DMA_RC_ADDRESS_NOT_ALIGNED,
    DMA_RC_ILLEGAL_ADDRESS,
    DMA_RC_SIZE_ERROR,
    DMA_RC_CHANNEL_NOT_AVAILABLE ,
    DMA_RC_CHANNEL_NOT_STOPPED,
    DMA_RC_INTC_BIND_ERROR,
    DMA_RC_INTC_INTERRUPT_ERROR,
    DMA_RC_MUX_CONNECTION_ILLEGAL,
    DMA_RC_CHANNEL_MATRIXED_VALUE_ERROR,
    DMA_RC_CHANNEL_DATA_ERROR,
    DMA_RC_CHANNEL_OVERFLOW_ERROR,
	DMA_RC_MAPPING_INVALID,
	DMA_RC_ILLEGAL_PARAMETERS,
	DMA_RC_BUFFER_ERROR,
	DMA_RC_RM_ERROR
}DMA_ReturnCode;


///////////////////////////////////////////////////////////////////////////////////
// API - DMA SW package 1 function declaration
///////////////////////////////////////////////////////////////////////////////////

//--------- System Control Services -----------------------------------------------
void                           DMAPhase1Init              (void);

DMA_ReturnCode                 DMAPhase2Init              (void);

//--------- Channel Control Services ----------------------------------------------
DMA_ReturnCode                 DMAChannelOpen             (DMA_ChannelE channel);

DMA_ReturnCode                 DMAChannelRegister         (DMA_ChannelE channel,
                                                           DMATransferEndedNotifyFn endNotifyFn,
                                                           DMATransferStoppedNotifyFn stopNotifyFn,
                                                           DMATransferErrorNotifyFn errorNotifyFn,
                                                           UINT32 callbackCookie);

DMA_ReturnCode                 DMAChannelConfigure        (DMA_ChannelE channel,
                                                           DMA_DREQConnectionE dreqConnection,
                                                           DMA_MUXConnectionE muxConnection);

//#define                        DMAChannelStart(channel)   {DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].DCR |= ( DMA_CHANNEL_START_BIT >> DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel) );}
void                           DMAChannelStart            (DMA_ChannelE channel);

//#define                        DMAChannelTerminate(channel){DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].DCR |= ( DMA_CHANNEL_TERMINATE_BIT >> DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel) );}
void                           DMAChannelTerminate		  (DMA_ChannelE channel);

DMA_ReturnCode                 DMAChannelClose            (DMA_ChannelE channel);

void                           DMAChannelStop             (DMA_ChannelE channel, BOOL waitForStop);

#define                        DMAIsChannelRunning(channel)(DmaHwRegisters.controller[DMA_GET_CONTROLLER_NUMBER(channel)].DCR & (DMA_CHANNEL_START_BIT>>DMA_GET_CHANNEL_PHYSICAL_NUMBER(channel)) ) // TBD - check out :idle -?




//--------- Single Transfer Setup Services
DMA_ReturnCode                 DMAMemory2MemorySetup      (DMA_ChannelE channel,
                                                           void *srcAddr,
                                                           void *dstAddr,
                                                           UINT32 length,
                                                           DMA_SingleDescriptorS *pSingleDescriptor);

DMA_ReturnCode                 DMAPeripheral2MemorySetup  (DMA_ChannelE channel,
                                                           void *srcAddr,
                                                           void *dstAddr,
                                                           UINT32 length,
                                                           DMA_SingleDescriptorS *pSingleDescriptor);

DMA_ReturnCode                 DMAPeripheral2AlignedMemorySetup  (DMA_ChannelE channel,
                                                           void *srcAddr,
                                                           void *dstAddr,
                                                           UINT32 length,
                                                           const DMA_SingleDescriptorS *pSingleDescriptor);

DMA_ReturnCode                 DMAMemory2PeripheralSetup  (DMA_ChannelE channel,
														   void *srcAddr,
														   void *dstAddr,
														   UINT32 length,
														   DMA_SingleDescriptorS *pSingleDescriptor,
														   void* pChainManagerPool,
														   UINT32 sizeOfChainManagerPool);

DMA_ReturnCode                 DMAAlignedMemory2PeripheralSetup  (DMA_ChannelE channel,
														   void *srcAddr,
														   void *dstAddr,
														   UINT32 length,
														   const DMA_SingleDescriptorS *pSingleDescriptor,
														   void* pChainManagerPool,
														   UINT32 sizeOfChainManagerPool);

DMA_ReturnCode					DMASingleDescriptorSetup  (DMA_ChannelE				channel,
															DMA_SingleDescriptorS	*pSingleDesc,
															UINT8                   descNumber,
															UINT32                  numberOfPackets,
															void                   *srcAddr,                   
															void                    *dstAddr);
															
// secondaryAPI

UINT8                           DMAGetInterruptVector     (BOOL         error_,
                                                           BOOL         ended,
                                                           BOOL         stop);

UINT32							DMAGetRequiredSizeOfBuffer(UINT32 numberOfDescInChain);

UINT32							DMAGetRemainder(DMA_ChannelE channel);

///////////////////////////////////////////////////////////////////////////////////
// API supports chaining mode
///////////////////////////////////////////////////////////////////////////////////
// Fill up the descriptors list - "automatic"
DMA_ReturnCode  DMADescriptorsChainSetup(DMA_ChannelE			channel, 
										 void					*srcBaseAddr, 
										 void					*dstBaseAddr,
										 UINT32                 entireLength,
										 DMA_SingleDescriptorS	*pSingleDesc);
										 
DMA_ReturnCode DMAOneDescInChainSetup(DMA_ChannelE            channel,
									  DMA_SingleDescriptorS*  pSingleDesc,
									  UINT32                  descIndex,
									  void*                   srcAddr,
									  void*                   dstAddr,
									  UINT32                  singleTransactionLength);

// Prepare a "link-list" (chaining) of descriptors
DMA_ReturnCode  DMADescriptorsChainPrepare(DMA_ChannelE channel, 
										   UINT32 numDescriptors,
										   void *descBuffer, 
										   UINT32 descBufferSize,
										   DMA_ChainTypeE chainType);


///////////////////////////////////////////////////////////////////////////////////
// this definition is temporary - only for first stage integration with SSP
///////////////////////////////////////////////////////////////////////////////////
#if 1
typedef enum
{
    DMA_CSSP0_TX , DMA_CSSP0_RX  ,
     DMA_CSSP1_TX , DMA_CSSP1_RX
}DMA_Peripherals;

typedef enum
{
    DMA_ADDRESS_INCREMENT_NONE = 0,
    DMA_ADDRESS_INCREMENT_SOURCE,
    DMA_ADDRESS_INCREMENT_TARGET,
    DMA_ADDRESS_INCREMENT_BOTH
}DMA_AddressIncrement;

typedef struct
{
    UINT16                      packetSize;
    DMA_AddressIncrement        bufferIncrement;
    UINT32                      totalLength;
    BOOL                        stopInterruptEnable;
}DMA_ChainConfig;

typedef enum
{
    DMA_FLOW_CONTROL_NONE = 0,
    DMA_FLOW_CONTROL_SOURCE,
    DMA_FLOW_CONTROL_TARGET
}DMA_FlowControl;

typedef enum
{
    DMA_LITTLE_ENDIAN = 0, /* the usually used */
    DMA_BIG_ENDIAN
}DMA_ByteOrdering;

typedef enum
{
    DMA_BURST_INVALID = 0,
    DMA_BURST_8_BYTES,
    DMA_BURST_16_BYTES,
    DMA_BURST_32_BYTES
}DMA_BurstSize;

typedef enum
{
    DMA_MEMORY_WIDTH = 0,
    DMA_DATA_WIDTH_ONE_BYTE,
    DMA_DATA_WIDTH_TWO_BYTES,
    DMA_DATA_WIDTH_FOUR_BYTES
}DMA_DataWidth;

typedef struct
{
    UINT32                      interruptsEnableBits;
    DMA_AddressIncrement        addressIncrement;
    DMA_FlowControl             flowControl;
    DMA_ByteOrdering            byteOrdering;
    DMA_BurstSize               burstSize;
    DMA_DataWidth               dataWidth;
}DMA_DescriptorsHWConfig;

typedef struct
{
    UINT32                      interruptsEnableBits;
    BOOL                        peripheralAddrIncrement; // Increment address of peripheral
    BOOL                        peripheralFlow;     // Peripheral Flow Control TRUE/FALSE
    DMA_ByteOrdering            byteOrdering;
    DMA_BurstSize               burstSize;
    DMA_DataWidth               dataWidth;
}DMA_SingleHWConfig;


#define DMA_INTERRUPT_NONE                  0x00L
#define DMA_INTERRUPT_TRANSFER_STARTED      0x01L
#define DMA_INTERRUPT_TRANSFER_ENDED        0x02L
#define DMA_INTERRUPT_TRANSFER_STOPPED      0x04L

#endif /*if 1*/


/*
 *
 *	THE BASE ADDRESSES
 *
 */
#ifdef NEZHA3_1826
#define	DMA_BASE	0xD0200000      //CP DMA Base
#else
#define	DMA_BASE	0xD4000000      //AP DMA Base
#endif

/*
 *
 *	THE REGISTER DEFINES
 *
 */
#define	DMA_CSR031		(DMA_BASE+0x0000)	/* DMA Channel Control/Status
											 *			Registers 0-31 Start
											 */
#define	DMA_ALGN		(DMA_BASE+0x00A0)	/* 32 bit	DMA Alignment Register */
#define	DMA_PCSR		(DMA_BASE+0x00A4)	/* 32 bit	DMA Programmed I/O
											 *			Control Status
											 *			Register
											 */
#define	DMA_RQSR0		(DMA_BASE+0x00E0)	/* 32 bit	DREQ Status Register 0 */
#define	DMA_INT			(DMA_BASE+0x00F0)	/* 32 bit	DMA Interrupt Register */
#define	DMA_RCMRX		(DMA_BASE+0x0100)	/* DMA Request to Channel Map
											 *			Registers 0-63 and
											 *			64-99 Start
											 */
#define	DMA_DADRX		(DMA_BASE+0x0200)	/* DMA Descriptor Address Registers Start */
#define	DMA_SADRX		(DMA_BASE+0x0204)	/* DMA Source Address Registers 0-31
											 *			Start
											 */
#define	DMA_TADRX		(DMA_BASE+0x0208)	/* DMA Target Address Registers 0-31
											 *			Start
											 */
#define	DMA_CMDX		(DMA_BASE+0x020C)	/* DMA Command Registers 0-31 Start */
//#define	DUMMY_REGISTER	(DMA_BASE+0x0000)	/* 32 bit	This is a Dummy Register */

/*
 *
 *	THE BIT DEFINES
 *
 */
/*	DMA_CSR031		0x0000	DMA Channel Control/Status Registers 0-31 */
#define	DMA_CSR031_RUN					BIT_31			/* Run */
#define	DMA_CSR031_NODESCFETCH			BIT_30			/* No-Descriptor Fetch */
#define	DMA_CSR031_STOPIRQEN			BIT_29			/* Stop interrupt enabled */
/* Setting the End-of-Receive interrupt enable */
#define	DMA_CSR031_EORIRQEN				BIT_28			
/* Jump to the next descriptor on EOR */
#define	DMA_CSR031_EORJMPEN				BIT_27			
#define	DMA_CSR031_EORSTOPEN			BIT_26			/* Stop channel on EOR */
/* Set descriptor compare status */
#define	DMA_CSR031_SETCMPST				BIT_25			
/* Clear descriptor compare status */
#define	DMA_CSR031_CLRCMPST				BIT_24			
/* Request after channel stopped interrupt enable */
#define	DMA_CSR031_RASIRQEN				BIT_23			
#define	DMA_CSR031_MASKRUN				BIT_22			/* MASKRUN */
/*		Bit(s) DMA_CSR031_RSRV_21_11 reserved */
/* Descriptor compare status */
#define	DMA_CSR031_CMPST				BIT_10			
#define	DMA_CSR031_EORINT				BIT_9			/* End of Receive Interrupt */
#define	DMA_CSR031_REQPEND				BIT_8			/* Request pending */
/*		Bit(s) DMA_CSR031_RSRV_7_5 reserved */
/* Request after channel stopped */
#define	DMA_CSR031_RASINTR				BIT_4			
#define	DMA_CSR031_STOPINTR				BIT_3			/* Stop interrupt */
#define	DMA_CSR031_ENDINTR				BIT_2			/* End interrupt */
#define	DMA_CSR031_STARTINTR			BIT_1			/* Start interrupt */
#define	DMA_CSR031_BUSERRINTR			BIT_0			/* Bus error interrupt */

/*	DMA_ALGN		0x00A0	DMA Alignment Register */
/* Alignment control for channel x */
#define	DMA_ALGN_DALGNX_MSK			SHIFT0(0xffffffff)	
#define	DMA_ALGN_DALGNX_BASE		0

/*	DMA_PCSR		0x00A4	DMA Programmed I/O Control Status Register */
/* Activate posted writes and split reads */
#define	DMA_PCSR_BRGSPLIT			BIT_31				
/*		Bit(s) DMA_PCSR_RSRV_30_1 reserved */
#define	DMA_PCSR_BRGBUSY			BIT_0				/* Bridge busy status */

/*	DMA_RQSR0		0x00E0	DREQ Status Register 0 */
/*		Bit(s) DMA_RQSR0_RSRV_31_9 reserved */
/* Clearing pending request */
#define	DMA_RQSR0_CLR					BIT_8				
/*		Bit(s) DMA_RQSR0_RSRV_7_5 reserved */
#define	DMA_RQSR0_REQPEND_MSK			SHIFT0(0x1f)		/* Request pending */
#define	DMA_RQSR0_REQPEND_BASE			0

/*	DMA_INT			0x00F0	DMA Interrupt Register */
#define	DMA_INT_CHLINTRX_MSK		SHIFT0(0xffffffff)	/* Channel interrupt */
#define	DMA_INT_CHLINTRX_BASE		0

/*	DMA_RCMRx		0x0100	DMA Request to Channel Map Registers 0-63 and 64-99 */
/*		Bit(s) DMA_RCMRX_RSRV_31_8 reserved */
#define	DMA_RCMRX_MAPVLD				BIT_7				/* Map valid channel */
/*		Bit(s) DMA_RCMRX_RSRV_6_5 reserved */
#define	DMA_RCMRX_CHLNUM_MSK			SHIFT0(0x1f)		/* Channel number */
#define	DMA_RCMRX_CHLNUM_BASE			0

/*	DMA_DADRx		0x0200	DMA Descriptor Address Registers */
/* Descriptor address */
#define	DMA_DADRX_DESCRIPTOR_ADDRESS_MSK		SHIFT4(0xfffffff)	
#define	DMA_DADRX_DESCRIPTOR_ADDRESS_BASE		4
/*		Bit(s) DMA_DADRX_RSRV_3_2 reserved */
/* Enable Descriptor Branch */
#define	DMA_DADRX_BREN							BIT_1				
#define	DMA_DADRX_STOP							BIT_0				/* Stop */

/*	DMA_SADRx		0x0204	DMA Source Address Registers 0-31 */
#define	DMA_SADRX_SRCADDR_MSK		SHIFT3(0x1fffffff)	/* Source address */
#define	DMA_SADRX_SRCADDR_BASE		3
#define	DMA_SADRX_SRCADDR2			BIT_2				/* SRCADDR2 */
#define	DMA_SADRX_SRCADDR0_MSK		SHIFT0(0x3)			/* SRCADDR0 */
#define	DMA_SADRX_SRCADDR0_BASE		0

/*	DMA_TADRx		0x0208	DMA Target Address Registers 0-31 */
#define	DMA_TADRX_TRGADDR_MSK		SHIFT3(0x1fffffff)	/* Target address */
#define	DMA_TADRX_TRGADDR_BASE		3
#define	DMA_TADRX_TRGADDR2			BIT_2				/* TRGADDR2 */
#define	DMA_TADRX_TRGADDR0_MSK		SHIFT0(0x3)			/* TRGADDR0 */
#define	DMA_TADRX_TRGADDR0_BASE		0

/*	DMA_CMDx		0x020C	DMA Command Registers 0-31 */
#define	DMA_CMDX_INCSRCADDR				BIT_31			/* Source address increment */
#define	DMA_CMDX_INCTRGADDR				BIT_30			/* Target address increment */
#define	DMA_CMDX_FLOWSRC				BIT_29			/* Source flow control */
#define	DMA_CMDX_FLOWTRG				BIT_28			/* Target flow control */
/*		Bit(s) DMA_CMDX_RSRV_27_26 reserved */
/* Descriptor compare enable */
#define	DMA_CMDX_CMPEN					BIT_25			
/*		Bit(s) DMA_CMDX_RSRV_24 reserved */
#define	DMA_CMDX_ADDRMODE				BIT_23			/* ADDRMODE */
#define	DMA_CMDX_STARTIRQEN				BIT_22			/* STARTIRQEN */
#define	DMA_CMDX_ENDIRQEN				BIT_21			/* End interrupt enable */
/*		Bit(s) DMA_CMDX_RSRV_20_18 reserved */
#define	DMA_CMDX_SIZE_MSK				SHIFT16(0x3)	/* Maximum burst size */
#define	DMA_CMDX_SIZE_BASE				16
#define	DMA_CMDX_WIDTH_MSK				SHIFT14(0x3)	/* WIDTH */
#define	DMA_CMDX_WIDTH_BASE				14
/*		Bit(s) DMA_CMDX_RSRV_13 reserved */
/* Length of the transfer in bytes */
#define	DMA_CMDX_LEN_MSK				SHIFT0(0x1fff)	
#define	DMA_CMDX_LEN_BASE				0

/*	DUMMY_REGISTER	0x0000	This is a Dummy Register */
#define	DUMMY_REGISTER_DUMMY_MSK		SHIFT0(0xffffffff)	/* Ignore this register */
#define	DUMMY_REGISTER_DUMMY_BASE		0

typedef enum{
    DMA_REQ_CLK = 1,
    
    DMA_REQ_GSSP_RX = 3,
    DMA_REQ_UART2_RX = 4,
    DMA_REQ_UART2_TX = 5,

    DMA_REQ_USIM1_RX = 8,
    DMA_REQ_USIM1_TX = 9,
    DMA_REQ_USIM2_RX = 10,
    DMA_REQ_USIM2_TX = 11,
    
    DMA_REQ_APB_E_Cipher = 12,

    DMA_REQ_UART1_RX = 21,
    DMA_REQ_UART1_TX = 22,
    DMA_REQ_UART3_RX = 23,
    DMA_REQ_UART3_TX = 24,
    DMA_REQ_I2C0_TX = 25,
    DMA_REQ_I2C0_RX = 26,
    DMA_REQ_I2C1_TX = 27,
    DMA_REQ_I2C1_RX = 28,

    DMA_REQ_PWR_I2C_TX = 30,
    DMA_REQ_PWR_I2C_RX = 31,
    DMA_REQ_I2C2_TX  = 32,
    DMA_REQ_I2C2_RX = 33,

    
    DMA_REQ_UART4_RX = 36,
    DMA_REQ_UART4_TX = 37,

	DMA_REQ_SSP0_RX = 52,
	DMA_REQ_SSP0_TX = 53,

	DMA_REQ_SSP1_RX = 54,
	DMA_REQ_SSP1_TX = 55,	

	DMA_REQ_SSP2_RX = 60,
	DMA_REQ_SSP2_TX = 61,

	DMA_REQ_AEU_READ_CHANNEL = 68,
	DMA_REQ_AUE_WRITE_CHANNEL = 69,

	DMA_REQ_QSPI_RX = 97,
	DMA_REQ_QSPI_TX = 99,

	DMA_REQ_MEM2MEM_MOVE = 255  // RESERVED for Memory to Memory moves
}DMA_MAP_DEVICE;



typedef enum
{
	DMAC_GSSP_RX = DMA_REQ_GSSP_RX,//3,
//	DMAC_GSSP_TX = DMA_REQ_UART2_RX,//4,

	DMAC_UART2_RX = DMA_REQ_UART2_RX,//4,
	DMAC_UART2_TX = DMA_REQ_UART2_TX,//5,

	DMAC_USIM1_RX = DMA_REQ_USIM1_RX,//8,
	DMAC_USIM1_TX = DMA_REQ_USIM1_TX,//9,
	DMAC_USIM2_RX = DMA_REQ_USIM2_RX,//10,
	DMAC_USIM2_TX = DMA_REQ_USIM2_TX,//11,

	DMAC_APB_E_Cipher = DMA_REQ_APB_E_Cipher,//12,


    DMAC_UART1_RX = DMA_REQ_UART1_RX,//21,
    DMAC_UART1_TX = DMA_REQ_UART1_TX,//22,
	DMAC_UART3_RX = DMA_REQ_UART3_RX,//23,
	DMAC_UART3_TX = DMA_REQ_UART3_TX,//24,

    DMAC_UART4_RX = DMA_REQ_UART4_RX,//36,
    DMAC_UART4_TX = DMA_REQ_UART4_TX,//37,

	DMAC_SSP_0_RX = DMA_REQ_SSP0_RX,//52,
	DMAC_SSP_0_TX = DMA_REQ_SSP0_TX,//53,

	DMAC_SSP_1_RX = DMA_REQ_SSP1_RX,//54,
	DMAC_SSP_1_TX = DMA_REQ_SSP1_TX,//55,	

	DMAC_SSP_2_RX = DMA_REQ_SSP2_RX,//60,
	DMAC_SSP_2_TX = DMA_REQ_SSP2_TX,//61,

	DMAC_NAND_DATA = DMA_REQ_QSPI_RX,//97,
	DMAC_NAND_CMD  = DMA_REQ_QSPI_TX,//99,

	DMAC_MEM2MEM_MOVE = DMA_REQ_MEM2MEM_MOVE //255  // RESERVED for Memory to Memory moves
}DMAC_DRCMR_T, DMAC_DEVICE_T;

/* -------------------- */


#endif //_DMA_HW_
