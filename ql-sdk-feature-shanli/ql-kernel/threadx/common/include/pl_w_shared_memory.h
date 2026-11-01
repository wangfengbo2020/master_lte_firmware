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

/************************************************************************************************
 * Filename: pl_w_shared_memory.h
 *
 * Description: Defines addresses of the Grayback shared memory used between L1 and MAC for HSUPA.   
 *	
 ************************************************************************************************/

#ifndef PL_W_SHARED_MEMORY_H
#define PL_W_SHARED_MEMORY_H

#include "cmmn_dfs.h"


//====================================================================
//   Definitions for sizes
//====================================================================
#if defined (L1_UPGRADE_R8)
#define MAX_MACE_PDU_BITLEN             (40000)//CQ00080888 enlarge max mace pdu bitlength for FB.
#else
#define MAX_MACE_PDU_BITLEN 						(20000)//total size of mace pdu
#endif

#define MAX_MACE_PDU_BYTELEN            (MAX_MACE_PDU_BITLEN>>3)
#define NUM_OF_PROCESS_2MS				(8)
#define NUM_OF_PROCESS_10MS				(4)
#define MAX_NUM_OF_POWER_OFFSETS        (7)

#ifndef MAX_REFERENCE_ETFCI_LENGTH  // other declerarion in cmac_sig.h
#define MAX_REFERENCE_ETFCI_LENGTH (8)
#endif


//====================================================================
//Description of RX share memory
//====================================================================
//HICH, RGCH, AGCH RX data structure
//based on 5.2.3.5	DL Data Report Format ( in HSUPA_System_HLD.doc )
//First long word
#define DATA_INVALID 0
#define DATA_VALID   1
#define DATA_IGNORE 2
#define DATA_IGNORE_COMMAND    3

//Validity of the AGCH parameters 0-1
#define AGCH_VALIDITY_POS 0  
#define AGCH_VALIDITY_LEN 2
#define AGCH_VALIDITY_MASK      0x3
#define AGCH_VALIDITY_RXWORD    0

//Validity of the RGCH parameters for Serving RLS 2-3
#define RGCH_SRLS_VALIDITY_POS 2
#define RGCH_SRLS_VALIDITY_LEN 2
#define RGCH_SRLS_VALIDITY_MASK     0xC
#define RGCH_SRLS_VALIDITY_RXWORD   0

//Validity of the RGCH parameters for None Serving RLS 4-5
#define RGCH_NSRLS_VALIDITY_POS 4
#define RGCH_NSRLS_VALIDITY_LEN 2
#define RGCH_NSRLS_VALIDITY_MASK    0x30
#define RGCH_NSRLS_VALIDITY_RXWORD  0

//HICH VALIDITY  6-7
#define RGCH_HICH_VALIDITY_POS 6
#define RGCH_HICH_VALIDITY_LEN 2
#define RGCH_HICH_VALIDITY_MASK     0xC0
#define RGCH_HICH_VALIDITY_RXWORD   0

//CRC
#define CRC_ERROR 0
#define CRC_OK 1

#define ERNTI_PRIMARY_CRC_POS 8
#define ERNTI_PRIMARY_CRC_LEN 1
#define ERNTI_PRIMARY_CRC_MASK      0x100
#define ERNTI_PRIMARY_CRC_RXWORD    0

#define ERNTI_SECONDARY_CRC_POS 9
#define ERNTI_SECONDARY_CRC_LEN 1
#define ERNTI_SECONDARY_CRC_MASK    0x200
#define ERNTI_SECONDARY_CRC_RXWORD  0
// Absolute Grant Scope (as received from AGCH) 10
// Valid only if ERNTI Primary CRC or ERNTI Secondary CRC = 1.
#define AGS_POS 10
#define AGS_LEN 1
#define AGS_MASK    0x400
#define AGS_RXWORD  0
#define AGS_ALL_PROCESSES 0   //according to 212 4.10.1a.2
#define AGS_CURRENT_PROCESS 1

// Absolute Grant Value (as received from AGCH) 11
// Valid only if ERNTI Primary CRC or ERNTI Secondary CRC = 1.
#define AGV_POS 11
#define AGV_LEN 5
#define AGV_MASK    0xF800
#define AGV_RXWORD  0
//
//
#define TX_RGCH_NO_RECEPTION 0 //No Reception is reported in case there was no RGCH received.
#define TX_RGCH_DOWN 1 //because is MSB prior to LSB -  01 - DOWN
#define TX_RGCH_HOLD 2 //because is MSB prior to LSB 10 - HOLD
#define TX_RGCH_UP   3 //11 ?UP

// Combined result for all serving RLS RCGH channels transmitting RGCH  
// bit 16-MSB 17-LSB
#define SERVING_RLS_RGCH_POS 16
#define SERVING_RLS_RGCH_LEN 2
#define SERVING_RLS_RGCH_MASK   0x30000
#define SERVING_RLS_RGCH_RXWORD 0

//RCGH result for all non Serving E-DCH cells ?
//If any non serving E-DCH cells transmitting RGCH indicates DOWN, L1 reports DOWN otherwise HOLD. 
//No Reception is reported in case there was no RGCH received or 
// in case RGCH is not transmitted in this TTI (valid for 2ms only).
// (bit 18 MSB, bit 19 LSB)
#define NONE_SERVING_RLS_RGCH_POS 18
#define NONE_SERVING_RLS_RGCH_LEN 2
#define NONE_SERVING_RLS_RGCH_MASK      0xC0000
#define NONE_SERVING_RLS_RGCH_RXWORD    0

#define HICH_NORECEPTION 0
#define HICH_NACK_ALL 1
#define HICH_ACK_NACK_SERV_RLS 2
#define HICH_ACK_ACK_SERV_RLS 3

#define HICH_STATUS_POS 20
#define HICH_STATUS_LEN 2
#define HICH_STATUS_MASK    0x300000
#define HICH_STATUS_RXWORD  0

#define RESERVE1_POS 22
#define RESERVE1_LEN 10
#define RESERVE1_MASK   0xFFC00000
#define RESERVE1_RXWORD 0
//Second long word

//SUB FRAME The sub-frame that this data configures 
//(not the sub-frame that this data was received on.) 
//invalid for 10ms
//valid values (0..4) bits 0..2
#define SUBFRAME_POS 0
#define SUBFRAME_LEN 3
#define SUBFRAME_MASK   0x7
#define SUBFRAME_RXWORD 1

#define RESERVE2_POS 3
#define RESERVE2_LEN 1
#define RESERVE2_MASK   0x8
#define RESERVE2_RXWORD 1
//CFN
//The CFN that this subframe configures (not the sub-frame that this data was received on.)
//bits 4..11
#define  CFN_POS 4
#define  CFN_LEN 8
#define  CFN_MASK   0xFF0
#define  CFN_RXWORD 1

#define RESERVE3_POS 30
#define RESERVE3_LEN 2
#define RESERVE3_MASK   0xC000
#define RESERVE3_RXWORD 1

#define REFERENCE_ETPR_POS 12
#define REFERENCE_ETPR_LEN 18
#define REFERENCE_ETPR_MASK     0x3FFFF000
#define REFERENCE_ETPR_RXWORD   1

#define MAX_VALID_ETFCI_SIZE 8

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT32		rxDataFormat[2];
} dlDataReportFormat_ts;


// use to extract the data from rxDataFormat according to MASK and POS, for input take: xxx.rxDataFormat[..._RXWORD]
// example: cfn = DL_DATA_GET_VAL(UINT8, xxx.rxDataFormat[CFN_RXWORD], CFN_MASK, CFN_POS);
#define DL_DATA_GET_VAL(casting, input, mask, pos)  ((casting)(((input)&(mask))>>(pos)))



//====================================================================
//Definitions for UL data configuration 
//====================================================================

typedef UINT8   processValidity_te;
//ICAT EXPORTED ENUM
enum processValidity_values
{
	PARAS_AND_DATA_ARE_INVALID = 0x00,		// Init state or state after L1 reset
	PARAS_IS_VALID			   = 0x01,		// Indicate UMAC has finished parameters calculate(like Etfci etc)		
	PARAS_AND_DATA_IS_VALID    = 0x02		// Indicate UMAC has finished E-TFCI selection and DTC data transfer	
};

/*
enum processValidity_values
{
	PROCESS_IS_INVALID			= 0x00,
	PROCESS_IS_VALID			= 0x01
};
*/
typedef UINT8   processState_te;
//ICAT EXPORTED ENUM
enum processState_values
{
    DTX						   = 0x00,
    INITIAL_TRANSMISSION       = 0x01,
    RETRANSMISSION             = 0x02,
	CLEAR= 0xFF
};

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8* 				 	 txDataPtr; 		//Pointer to the data to be transmitted 	
	UINT16					 trBkSize;			//0 means that there are no bits to be transmitted
	processValidity_te		 processValidity; 	// Invalid, Valid
    UINT8				 	 cfn;		    	//0..255
    UINT8                    subFrame;			//0..4, N/A in TTI 10ms
    processState_te          processState;
	UINT8				 	 rsn;
	UINT8					 happyBit;
	UINT8					 deltaHarq;		//0..6,denotes power offset from the HARQ profile of the relevant MAC-d flow  
	UINT8					 etfci;			//0..127
	// CPC parameters
	UINT8 					 startLongPreamble; // 0 - FALSE, 1 - TRUE
	UINT8                    preambleEndCfn;    // 0, 1...255
	UINT8                    preambleEndSf;     // 0, 1...4
	UINT8                    includesScheduledDataTransmission; // 0 - FALSE, 1 - TRUE
	UINT8                    MONITOR_GRANTS;    // 0 - FALSE, 1 - TRUE

#if defined (L1_UPGRADE_R8)  
	UINT8                    collisionResolved; // 1 - resolved
	UINT8                    releaseCommonEdchResource; 
#endif
} plwPhyEdchTtiInfo_ts;


//====================================================================
//Definitions for UL data payload (MAC-e PDU) 
//====================================================================
// The MAC-e PDU is transfered from MAC to L1 using shared memory.  This memory is in the ownership 
// of L1-DSP.  The addresses are fixed in memory and are passed from L1C to PS at HSUPA initialization.  
// During HSUPA session setup, pointers to these addresses are passed to MAC (via L1C).  
// DSP holds fixed buffers per process. The MAC writes the MAC-e PDU to the appropriate buffer depending 
// on the process number and TTI configuration. All buffers must be aligned to 64bit
//ICAT EXPORTED STRUCT
typedef struct 
{
	UINT8	macePduTrBkMem2ms;
	UINT8	pad[3];
} macePduTrBkMem2ms_ts;

//ICAT EXPORTED STRUCT
typedef struct 
{
	UINT8	macePduTrBkMem10ms; 
	UINT8	pad[3];
} macePduTrBkMem10ms_ts;

//====================================================================
//Definitions for ETFC restriction Memory 
//====================================================================
//This memory contains the ETFC restriction results for the coming TTI, 
//the MAC reads the results at the same time it reads the results for 
//the DL channels (AGCH,RGCH,HICH). Altogether required memory 7 byte
//====================================================================
#define ETFCI_RESTRICTION_INVALID 0xFF
#define ETFCI_RESTRICTION_READ_BY_MACE    0xFE
#define ETFCI_RESTRICTION_READ_BY_MACE_UINT32    0xFEFEFEFE
#define MAX_ETCFCI_RESTRICTIONS (7)

//ICAT EXPORTED STRUCT
typedef struct  
{
	UINT8	etfcRestrictionResult [MAX_ETCFCI_RESTRICTIONS];
	UINT8	pad;
} etfcRestrictionDspResults;


//====================================================================
//Definitions for Edch Shared Memory General Parameters
//====================================================================

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16		initialCfn; // This address will contain the CFN that the current MAC-e interrupt is synchronizing.
							// It is used by MAC to synchronize it's internal CFN to the DSP CFN.
	UINT8		UPH;		//UE Power Headroom
	UINT8		etfcRestrictionControl;
	// CPC parameters 
	UINT8   	MAC_DTX_Enabled;  // 0 - Disabled, 1 - Enabled
    UINT8   	DTX_CYCLE1_2;     //bit0(LSB): 0 - Cycle1, 1 - Cycle2
    							  //bit1: Validity on bit0
	UINT8   	Reset_MAC_Timers; // 0 - FALSE, 1 - TRUE
	UINT8 		CPC_MACE_TX_MISS_INDICATION; //0 - Mac-e did not miss 1ms thereshold, 1 - Mac-e missed 1ms threshold
} edchSharedMemGeneralParameters_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
    //stores the results of Leref,m*(Bed,m)^2
    UINT32      leRefMultBedSquare[MAX_REFERENCE_ETFCI_LENGTH]; // (With Q0)
    //for extrapolation stores the results of Keref,m/(Leref,m*(Bed,m)^2)
    //for interpolation stores the results of (Keref,m+1 - Keref,m)/(Leref,m+1*(Bed,m+1)^2 - Leref,m*(Bed,m)^2)
    UINT32      ratioValue [MAX_REFERENCE_ETFCI_LENGTH];
    UINT8       ratioQ [MAX_REFERENCE_ETFCI_LENGTH];
	UINT8 		maxValidEtfci[MAX_VALID_ETFCI_SIZE];
} etfcRestrictionControl_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
    plwPhyEdchTtiInfo_ts  *	    edchTtiTxParametersAddr;						  //TX data for this TTI
    dlDataReportFormat_ts *     edch2msTtiRxParametersAddr[NUM_OF_PROCESS_2MS];	  //RX data per Process
    dlDataReportFormat_ts *	    edch10msTtiRxParametersAddr[NUM_OF_PROCESS_10MS]; //RX data per Process
    UINT8 *     				tti2msMacEPduAddr[NUM_OF_PROCESS_2MS];//address of the MAC-e PDUs for TTI 2ms configuration			  
    UINT8 *     				tti10msMacEPduAddr[NUM_OF_PROCESS_10MS];//address of the MAC-e PDUs for TTI 10ms configuration
	etfcRestrictionControl_ts * edchEtfcRestrictionControlAddr;
	etfcRestrictionDspResults *	etfcRestrictionResultsAddr;					  //ETFC restriction results
	edchSharedMemGeneralParameters_ts *		edchSharedMemGeneralParametersAddr;//Pointer to structure containing general paramets	 
} edchSharedMemAddrInd_ts;

// These definisions are for the share memory read and write
//Extract bits
#define BITS_EXTRACT(v,p,l) (v>>p)&~(-1<<l)    
#define GET_AGCS_Validity(add)       BITS_EXTRACT(add[0], AGCH_VALIDITY_POS, AGCH_VALIDITY_LEN)				//bits 0-1
#define GET_RGCH_SRLS_Validity(add)  BITS_EXTRACT(add[0], RGCH_SRLS_VALIDITY_POS, RGCH_SRLS_VALIDITY_LEN)	//bits 2-3
#define GET_RGCH_NSRLS_Validity(add) BITS_EXTRACT(add[0],RGCH_NSRLS_VALIDITY_POS, RGCH_NSRLS_VALIDITY_LEN)	//bits 4-5
#define GET_HICH_Validity(add)       BITS_EXTRACT(add[0],RGCH_HICH_VALIDITY_POS, RGCH_HICH_VALIDITY_LEN)	//bits 6-7
//#define GET_ERNTI_Primary_CRC(add)   BITS_EXTRACT(add[0],ERNTI_PRIMARY_CRC_POS, ERNTI_PRIMARY_CRC_LEN)	    //bit 8
//#define GET_ERNTI_Secondary_CRC(add) BITS_EXTRACT(add[0],ERNTI_SECONDARY_CRC_POS, ERNTI_SECONDARY_CRC_LEN)	//bit 9
#define GET_ERNTI_CRC(add) BITS_EXTRACT(add[0],ERNTI_PRIMARY_CRC_POS, 2)	//bits 8+9
#define GET_AGScope(add)            BITS_EXTRACT(add[0],AGS_POS, AGS_LEN)								    //bit 10
#define GET_AGValue(add)             BITS_EXTRACT(add[0],AGV_POS, AGV_LEN)								    //bits 11-15
#define GET_Serving_RLS_RGCH(add)    BITS_EXTRACT(add[0],SERVING_RLS_RGCH_POS, SERVING_RLS_RGCH_LEN)		//bits 16-17
#define GET_NonServing_RLS_RGCH(add) BITS_EXTRACT(add[0],NONE_SERVING_RLS_RGCH_POS, NONE_SERVING_RLS_RGCH_LEN)//bits 18-19
#define GET_HICH_status(add)         BITS_EXTRACT(add[0],HICH_STATUS_POS ,HICH_STATUS_LEN)					//bits 20-21
//Reserved1  bits 22-31
//msb long word
#define GET_Sub_Frame(add) BITS_EXTRACT(add[1],SUBFRAME_POS, SUBFRAME_LEN)					//bits 0-2
//Reserve2 bit 3
#define GET_CFN(add) BITS_EXTRACT(add[1],CFN_POS, CFN_LEN)									//bits 4-11
//Reserve3 bits 12-13
#define GET_reference_ETPR(add) BITS_EXTRACT(add[1],REFERENCE_ETPR_POS, REFERENCE_ETPR_LEN)	//bits 14-31 (multiply by 225 )

//Set bits
//should nullify before using these macros
//keep field legnth but not nullify the field
//#define BITS_SET(o,v,p,l) o|= ((v &~(-1<<l)) << p)
//Bits set after clear field
#define BITS_SET(o,v,p,l) o&=~(~(-1<<l)<<p);o|= ((v &~(-1<<l)) << p)


#define SET_AGCS_Validity(add, val)		  BITS_SET(add[0], val, AGCH_VALIDITY_POS,AGCH_VALIDITY_LEN)		//bits 0-1
#define SET_RGCH_SRLS_Validity(add, val)  BITS_SET(add[0], val, RGCH_SRLS_VALIDITY_POS,RGCH_SRLS_VALIDITY_LEN)	//bits 2-3
#define SET_RGCH_NSRLS_Validity(add, val) BITS_SET(add[0], val, RGCH_NSRLS_VALIDITY_POS,RGCH_NSRLS_VALIDITY_LEN)	//bits 4-5
#define SET_HICH_Validity(add, val)		  BITS_SET(add[0], val, RGCH_HICH_VALIDITY_POS,RGCH_HICH_VALIDITY_LEN)	//bits 6-7
#define SET_ERNTI_CRC(add,val)            BITS_SET(add[0],val,ERNTI_PRIMARY_CRC_POS, 2)	//bits 8+9
#define SET_ERNTI_Primary_CRC(add,val)    BITS_SET(add[0],val,ERNTI_PRIMARY_CRC_POS, ERNTI_PRIMARY_CRC_LEN)
#define SET_ERNTI_Secondary_CRC(add,val)  BITS_SET(add[0],val,ERNTI_SECONDARY_CRC_POS, ERNTI_SECONDARY_CRC_LEN)
#define SET_AGScope(add,val)             BITS_SET(add[0],val,AGS_POS, AGS_LEN)								    //bit 10
#define SET_AGValue(add,val)              BITS_SET(add[0],val,AGV_POS, AGV_LEN)								    //bits 11-15
#define SET_Serving_RLS_RGCH(add,val)     BITS_SET(add[0],val,SERVING_RLS_RGCH_POS, SERVING_RLS_RGCH_LEN)		//bits 16-17
#define SET_NonServing_RLS_RGCH(add,val)  BITS_SET(add[0],val,NONE_SERVING_RLS_RGCH_POS, NONE_SERVING_RLS_RGCH_LEN)//bits 18-19
#define SET_HICH_status(add,val)          BITS_SET(add[0],val,HICH_STATUS_POS ,HICH_STATUS_LEN)					//bits 20-21
//Reserved1  bits 22-31
//msb long word
#define SET_Sub_Frame(add,val) BITS_SET(add[1],val,SUBFRAME_POS, SUBFRAME_LEN)					//bits 0-2
//Reserve2 bit 3
#define SET_CFN(add,val) BITS_SET(add[1],val,CFN_POS, CFN_LEN)									//bits 4-11
//Reserve3 bits 12-13
#define SET_reference_ETPR(add,val) BITS_SET(add[1],val,REFERENCE_ETPR_POS, REFERENCE_ETPR_LEN)	//bits 14-31 (multiply by 225 )

#endif /* _PL_W_SHARED_MEMORY_H_ */
