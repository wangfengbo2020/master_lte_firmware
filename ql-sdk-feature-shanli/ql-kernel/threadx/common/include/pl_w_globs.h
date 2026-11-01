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

/**********************************************************************
 *
 * Filename: pl_w_globs.h
 *
 *
 * Description: define data structures to support L1 WCDMA API
 *
 *  Caution:
 *      Alignmet rules:
 *             1. Size of structure devides 4
 *             2. Structure start addrees allight 4
 *             3. UINT16 starts at even address
 *             4. UINT32 starts at 4 address
 *
 ***************************************************************************************************/
#ifndef PL_W_GLOBS_H
#define PL_W_GLOBS_H

//Added by wangl for debug Macro definition 20120827

#ifndef TURN_ON_RAT_DEBUG
#define TURN_ON_RAT_DEBUG
#endif

#ifndef FG_FREQ_SCAN_TASK_DEBUG
#define FG_FREQ_SCAN_TASK_DEBUG
#endif

#ifndef CELL_ACQ_TASK_DEBUG
#define CELL_ACQ_TASK_DEBUG
#endif

#ifndef NO_SLEP_NO_PER_DET_TASK_DEBUG
#define NO_SLEP_NO_PER_DET_TASK_DEBUG
#endif

#ifndef CELL_SRCH_TASK_DEBUG
#define CELL_SRCH_TASK_DEBUG
#endif

#ifndef INTRA_BCH_DEBUG
#define INTRA_BCH_DEBUG
#endif

#ifndef INTRA_BCH_DEF
#define INTRA_BCH_DEF
#endif

#ifndef STTD_MODIFY_TASK_DEBUG
#define STTD_MODIFY_TASK_DEBUG
#endif

//Added end


#include "cmmn_dfs.h"
#ifndef GPLC_ONLY
#include "aplp_config.h"
#endif

#if defined(FULL_SYSTEM)
#include "wb_modem_features.h"
#else
#include "pl_w_modem_features.h"
#endif

#include "pl_w_shared_memory.h"

#include "WbCapability.h"



/* L1-L3 status functions */
#define MAX_INTRA_FREQ_MONITORED_CELLS  42//10 for internal detected + 32 /* 25.133: 4.2.2.8, 8.1.2.1 */
#define MAX_INTER_FREQ_MONITORED_CELLS  32
#define MAX_FOUND_CELLS                 32
#define RF_SCAN_MAX_FREQS               32
#define RF_SCAN_IND_MAX_FREQS			352


#define	MAX_TRBK_SIZE 					2 //for ECF
#define MAX_HSSCCH_LESS_TRBK 			4 //for hsScchLessInformation


#define	MAX_INTRA_CELLS_ON_RACH  		7 //serving +6 intra cells
#define	MAX_INTER_CELLS_ON_RACH			2

#define MAX_MEAS_EVENT                  8
#define MAX_NUM_LAST_MEAS               4
#define MAX_NUM_OF_QUAL_MEASUREMENTS    16 /* RRC can assign up to 2
         measurement requests per transport channel (25.133: 8.3.2), and
              maximal number of transport channels is 8 (in class 384) */
#define MAX_NUM_OF_RADIO_LINKS          6
#ifndef	L1_WB_R99_ONLY
#define MAX_NUM_TFC   128
#define MAX_NUM_DL_TFC	128
#define MAX_NUM_UL_TFC    64
#else
#if 0 
#define MAX_NUM_TFC   48
#define MAX_NUM_DL_TFC	48
#define MAX_NUM_UL_TFC    32
#endif
#define MAX_NUM_TFC   128
#define MAX_NUM_DL_TFC	128
#define MAX_NUM_UL_TFC    64

#endif
#define MAX_NUMBER_OF_THRSHOLDS         4
#define NUM_OF_SLOTS                    15

//maximum HS-DSCH buffer TB blocks
#define MAX_PRE_ALLOC_DPA_DATA_BLOCKS	24 

//max DL DATA buffer data blocks for DCH/FACH/PCH
#define MAX_PRE_ALLOC_DL_DATA_BLOCKS	8

#define MAX_UL_TRCH_NUM_IN_ONE_TTI		8

#define MAX_HSDPA_DATA_BLOCK_NUM		2

#define MAX_CBS_RX_PERIODS              256

#define NUM_OF_PATTERN_INFO             2

#ifndef Earfcn
typedef UINT32 Earfcn;
#endif
typedef UINT8  plActionType_te;

//ICAT EXPORTED ENUM
enum plActionType_values
{
  ACTION_TYPE_START               = 0x00,
  ACTION_TYPE_STOP                = 0x01
};

typedef UINT8 plFreqScanType_te;
//ICAT EXPORTED ENUM
enum plFreqScanType_values
{
  RF_SCAN_LIST                    = 0x00,
  RF_SCAN_RANGE 				  = 0x01,
  RF_SCAN_FFT					  = 0x02
};

typedef UINT8 sttdInd_te;
//ICAT EXPORTED ENUM
enum sttdInd_values
{
  STTD_OFF                        = 0x00,
  STTD_ON                         = 0x01
};

typedef UINT8 sfnMeasAction_te;

//ICAT EXPORTED ENUM
enum sfnMeasAction_values
{
  NO_MEASUREMENTS                 = 0x00,
  SFN_SFN_MEAS_TYPE1              = 0x01,
  SFN_SFN_MEAS_TYPE2              = 0x02,
  SFN_CFN_MEASUREMENT             = 0x03
};

typedef UINT8 plCctrchId_te;
//ICAT EXPORTED ENUM
enum plCctrchId_values
{
  CCTRCH_ID_DPCH                  = 0x00,
  CCTRCH_ID_PDSCH                 = 0x01
};

typedef UINT8  plFreqScanMode_te;
//ICAT EXPORTED ENUM
enum plFreqScanMode_values
{
  FG_FREQ_SCAN                    = 0x00,
  BG_FREQ_SCAN                	  = 0x01
};

typedef UINT8  plIntraMeasOnRachReportType_te;
//ICAT EXPORTED ENUM
enum plIntraMeasOnRachReport_values
{
  REPORT_IMMEDIATLY               = 0x00,
  REPORT_SERVING               	  = 0x01,
  SERVING_1_BEST_NEIGHBOUR		  = 0x02,
  SERVING_2_BEST_NEIGHBOUR		  = 0x03,
  SERVING_3_BEST_NEIGHBOUR		  = 0x04,
  SERVING_4_BEST_NEIGHBOUR		  = 0x05,
  SERVING_5_BEST_NEIGHBOUR		  = 0x06,
  SERVING_6_BEST_NEIGHBOUR		  = 0x07
};

typedef UINT8 measReportingMethod_te;
//ICAT EXPORTED ENUM
enum measReportingMethod_values
{
  PERIODICAL_REPORTING            = 0x00,
  EVENT_TRIGGERED_REPORTING       = 0x01
};


typedef UINT8 plBlerChReqNum_te;
//ICAT EXPORTED ENUM
enum plBlerChReqNum_values
{
	TRCH_BLER_FIRST_REQ          = 0x00,
	TRCH_BLER_SECOND_REQ		 = 0x01
};



enum
{
  QUAL_NSERV_RELEVANT             = 0x00,
  QUAL_NSERV_IRRELEVANT           = 0x01,
  RXLEV_NSERV_RELEVANT            = 0x02,
  RXLEV_NSERV_IRRELEVANT          = 0x03
};


typedef UINT8 gsmCellMeasIndTypes_te;
//ICAT EXPORTED ENUM
enum gsmCellMeasIndTypes_values
{
  RSSI_ONLY                     = 0x00,
  RSSI_AND_TIME_DIFF            = 0x01
};

typedef UINT8 refTimeDiffToCellAccuracy_te;
//ICAT EXPORTED ENUM
enum refTimeDiffToCellAccuracy_values
{
  TIME_DIFF_ACCURACY_40         = 0x00,
  TIME_DIFF_ACCURACY_256        = 0x01,
  TIME_DIFF_ACCURACY_2560       = 0x02
};


typedef UINT8 txSlotStatus_te;
//ICAT EXPORTED ENUM
enum txSlotStatus_values
{
  TRANSMITTER_OPEN					= 0x01,
  TRANSMITTER_CLOSED_CM				= 0x02,
  TRANSMITTER_CLOSED_OUT_OF_SYNC	= 0x03, 
  TRANSMITTER_OPEN_AT_MIN_PWR		= 0x04,
  TRANSMITTER_OPEN_AT_MAX_PWR		= 0x05
};

/* utraFreqRxLevel */
//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16 uarfcn; /* (0?6383) RF channel number */
  INT8 rssiInd; /* (-120?) dBm measured RSSI */
  BYTE	pad1;
  INT16 scoreInd;
  BYTE	pad2[2];
} utraFreqRxLevel_ts;

typedef UINT8 freqScanErrCode_te;
//ICAT EXPORTED ENUM
enum freqScanErrCode_values
{
  FREQ_SCAN_OK = 0x00,
  FREQ_SCAN_FG_WRONG_MODE = 0x01,
  FREQ_SCAN_BG_WRONG_MODE = 0x02,
  FREQ_SCAN_UNDEFINED_MODE = 0x03
};

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16 numOfFreqs;
  BYTE pad;
  freqScanErrCode_te refusalCode;
  utraFreqRxLevel_ts freqList[RF_SCAN_IND_MAX_FREQS];
}freqScanInd_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  plActionType_te         startStopInd;
  plFreqScanType_te       actionType;
  UINT8                   numOfFreqs;
  plFreqScanMode_te       freqScanMode;
  Bool                    runInFastMode;
  UINT8                   pad[3];
  UINT16                  freqList[RF_SCAN_MAX_FREQS];
}freqScanList_ts;


typedef UINT8 cellMeasIndTypes_te;
//ICAT EXPORTED ENUM
enum cellMeasIndTypes_values
{
  ENERGY_ONLY                     = 0x01,
  ENERGY_SFN_SFN                  = 0x03,
  ENERGY_SFN_CFN                  = 0x05,
  ENERGY_DETECTED_CELL            = 0x08,
  PENDING_MEASUREMENT             = 0x09,
  CELL_NOT_FOUND                  = 0x0A,
  INTRA_DETECTED_CELL			  = 0x0D,	
#if (L1_FEATURE_INTRA_TM_CELLS_INDICATION)
  INTRA_TM_CELL 				  = 0x0E,   
#endif
  INDICATION_TYPE_MASK            = 0x0F
};

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16                  dlPriScramblingCode;
  INT16                   cpichEcNo;
  INT16                   cpichRscp;
  INT16                   utraRssi;
  UINT16                  sfnMeas;
  UINT16                  sfnOrCfnServ;
  UINT16                  chipOffset;
  Bool                    frameInfoPresent;
  UINT8                   clientBitmap;
  cellMeasIndTypes_te     indicationTypes;
  BYTE                    pad[3]; //will be used for debug pad[1] = dbCellIndex; pad[2] = PathInfoIndex; pad[3] = XfnSfnInfoIndex
}monCellInd_ts;



//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16                  dlUarfcn;
  UINT8                   numOfCells;
  UINT8                   numOfPendingCells;
  UINT8                   numOfCellsNotFound;
  BYTE                    pad[3];
  monCellInd_ts           cellList [MAX_INTER_FREQ_MONITORED_CELLS] ;
}interFreqCellMeasInd_ts;

typedef UINT8 detectedReportingMode_te;
//ICAT EXPORTED ENUM
enum detectedReportingMode_values
{
  ONE_SHOT                 = 0x00,//not used
  PERIODIC_REPORT          = 0x01,//pyin detect@Dch,APLP will change DetectedDb.DetectedMeasModeState to DETECTED_MEAS_MODE_IN_PERIODIC
  STOP_FIRST_FOUND         = 0x02,//pyin BG/FG PLMN search, APLP will set DetectedDb.bRunUntilFound
  REPORT_MORE_CELLS       = 0x03//not used
};

typedef UINT8 setWbMode_te;
//ICAT EXPORTED ENUM
enum setWbMode_values
{  
  WB_INIT					= 0x00,
  SET_WB_TO_PCCPCH			= 0x01,
  SET_WB_TO_DCH				= 0x02,  
  SET_WB_TO_DETECTED		= 0x03,
  SET_WB_TRANSITION_FAILURE = 0x04
};


#define MAX_DL_UARFCN_IN_DETECTED_REQ           100 
//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                   	clientBitmap;
  Bool                    	initialMode;
  UINT8                   	numOfDlUarfcns;
  detectedReportingMode_te	reportMode;
  UINT16                  	dlUarfcn[MAX_DL_UARFCN_IN_DETECTED_REQ];
  Bool						shortAcquisition;//pyin not used
  Bool						includeRRCRequestedCells;
 #if (L1_FEATURE_DETECTED_LONG_BG)
   Bool						longBgSearch;//pyin not used
   BYTE						pad[1]; 
 #else  
  BYTE						pad[2]; 
 #endif //L1_FEATURE_DETECTED_LONG_BG
}plDetectedCellMeas_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
  refTimeDiffToCellAccuracy_te  refTimeDiffToCellAccuracy;
  BYTE                          pad;
  UINT16                        refTimeDiff;
}refTimeDiffToServCell_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                     clientBitmap;
  sttdInd_te                sttdInd;
  UINT16                    dlPriScramblingCode;
  sfnMeasAction_te          sfnTimeDiffMeasAction;
  Bool                      sfnDecodedByL1;
  Bool                      refTimeDiffToServCellUsed;
  BYTE                      pad;
  refTimeDiffToServCell_ts  refTimeDiffToServCell;
}plMonCellInfo_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16                    dlUarfcn;
  sttdInd_te                sttdInd;
  Bool                      refTimeDiffToServCellUsed;
  UINT16                    dlPriScramblingCode;
  BYTE                      pad2[2];
  refTimeDiffToServCell_ts  refTimeDiffToServCell;
}cellInfo_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                     numOfCells;
  BYTE                      pad[3];
  cellInfo_ts               cellList[MAX_INTRA_FREQ_MONITORED_CELLS];
}cellinfoList_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8				numOfCells;
  Bool				sfnSfnMeasInDrxDisable;
  UINT16			dlUarfcn;
  UINT8				detectedCellsClientBitmap;
#if(L1_FEATURE_INTRA_TM_CELLS_INDICATION)
  Bool				reportTmCells;
  UINT8				pad[1];
#else
  UINT8				pad[2];
#endif
  Bool				renewMode;
  plMonCellInfo_ts	cellList[MAX_INTRA_FREQ_MONITORED_CELLS];
}plIntraFreqCellMeas_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                   numOfCells;
  #if defined (L1_UPGRADE_R8)
  Bool					  secondaryFrequencyIndexConfigured;  
  #else
  BYTE                    pad;
  #endif
  UINT16                  dlUarfcn;
  plMonCellInfo_ts        cellList[MAX_INTER_FREQ_MONITORED_CELLS];
}plInterFreqCellMeas_ts;


typedef UINT8 cellLockRat_te;
//ICAT EXPORTED ENUM
enum cellLockRat_values
{  
  CELL_LOCK_ON_WB_RAT		= 0x00,
  CELL_LOCK_ON_GSM_RAT		= 0x01,
  CELL_LOCK_ON_LTE_RAT		= 0x02,
  CELL_LOCK_ON_NR_RAT		= 0x03
};

//ICAT EXPORTED STRUCT
typedef struct
{
  Bool         enableCellLock;
  UINT8	       band;
  cellLockRat_te cellLockRat;
  UINT8			pad;
  Earfcn      ARFCN;
  UINT16      scrCode;	
} plCellLockMeas_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
  plActionType_te         actionType;
  UINT8                   trchID;               /* 0...31 */
  plBlerChReqNum_te		  trchRequestNum;       /* TRCH_BLER_FIRST_REQ or TRCH_BLER_SECOND_REQ */
  plCctrchId_te           cctrchId;
  measReportingMethod_te  reportingMethod;
  BYTE					  pad[3];
  UINT16                  numOfTotalCrc;        /* 1...512 */
  UINT16                  numOfBadCrc;          /* 1...512 */
  UINT16                  pendingAfterTrigger;  /* 1...512 */
  UINT16                  timePeriod;           /* 10...64000 */
}qualMeas_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                   numOfElements;
  BYTE                    pad[3];
  qualMeas_ts             qualMeas[MAX_NUM_OF_QUAL_MEASUREMENTS];
}plTrchBlerMeas_ts;

// Measurement Indications
#if (L1_FEATURE_INTRA_MEAS_IND_SERVING_ONLY)

typedef UINT8 reportContent_te;
//ICAT EXPORTED ENUM
enum reportContent_values
{
	NON_DRX_IND			= 0,
	ALL_MEASURED_CELLS	= 1,
	SERVING_CELL_ONLY	= 2	
};
#endif

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                   numOfCells;
  UINT8                   numOfPendingCells;
  UINT8                   numOfCellsNotFound;
#if (L1_FEATURE_INTRA_MEAS_IND_SERVING_ONLY)
  reportContent_te		  reportContent;
#else
  BYTE                    pad[1];
#endif  
 monCellInd_ts           cellList[MAX_INTRA_FREQ_MONITORED_CELLS];
 UINT8					 slotFormat;
 INT8					 tx_power;
 UINT16 				 padding;

}intraFreqCellMeasInd_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                   numOfCells;
  BYTE                    pad1[3];
  UINT16                  dlUarfcn[MAX_INTRA_CELLS_ON_RACH];
  BYTE                    pad2[2];  
  monCellInd_ts           cellList [MAX_INTRA_CELLS_ON_RACH];
}uarfcnMeasOnRachIntra_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                   numOfCells;
  BYTE                    pad[3];
  UINT16                  dlUarfcn[MAX_INTER_CELLS_ON_RACH];
  monCellInd_ts           cellList [MAX_INTER_CELLS_ON_RACH];
}uarfcnMeasOnRachInter_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
  uarfcnMeasOnRachIntra_ts              intraCellsOnRach;
  uarfcnMeasOnRachInter_ts              interCellsOnRach;
}cellMeasIndOnRach_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16                  dlUarfcn;
  UINT16                  dlPriScramblingCode;
}measuredCellInfo_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                   numOfCells;
  BYTE                    pad[3];
  measuredCellInfo_ts     cellList [MAX_FOUND_CELLS];
}measuredCellsInd_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  BOOL 					   LastInDrx;
  UINT32                   TimeForNextLteInd;
}endOfDrxMeasurementInd_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                   trchId;
  plBlerChReqNum_te		  trchRequestNum;       /* TRCH_BLER_FIRST_REQ or TRCH_BLER_SECOND_REQ */
  plCctrchId_te           cctrchId;
  measReportingMethod_te  reportingMethod;
  INT8                    blerLogInd;
  BYTE                    pad[3];
  UINT16                  numOfTotalCrc;
  UINT16                  numOfBadCrc;
}qualMeasList_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                   numOfElements;
  BYTE                    pad[3];
  qualMeasList_ts         qualMeasList[MAX_NUM_OF_QUAL_MEASUREMENTS];
}trchBlerInd_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16			txPower[NUM_OF_SLOTS];
  UINT16			txMaxPower[NUM_OF_SLOTS];
  BYTE				pad1;
  txSlotStatus_te	slotStatus[NUM_OF_SLOTS];
  BYTE				pad2;
}txPowInd_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16                  scramblingCode;
  UINT16                  rlRxTxTimeDiff;
}rlRxTxDiff_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                   numOfRls;
  BYTE                    pad[3];
  rlRxTxDiff_ts           rlRxTxDiff[MAX_NUM_OF_RADIO_LINKS];
}ueRxTxTimeDiffInd_ts;
//WB: because WB does not compile need to mark duplicate definitions between pl_d_globs.h and pl_w_globs.h


/***********************************************************************
 * L3 <-> L1 interface data strucures
 ***********************************************************************/

/***********************************************************************
 * common definitions for L3 <-> L1 interface
 ***********************************************************************/
//ICAT EXPORTED STRUCT
typedef struct
{
	Bool	immediateActivation;
	BYTE	pad;
	UINT16	activationTimeNum;
} activationTime_ts;

#define MAX_NUM_TRCH		16
#define MAX_NUM_DL_TRCH		8
#define MAX_NUM_UL_TRCH		8

typedef UINT8   trChType_te;
//ICAT EXPORTED ENUM
enum trChType_values
{
    TRCH_TYPE_BCH           = 0x00,
    TRCH_TYPE_PCH           = 0x01,
	RESERVED_TRCH_TYPE		= 0x02,
    TRCH_TYPE_FACH          = 0x03,
    TRCH_TYPE_DSCH          = 0x04,
    TRCH_TYPE_RACH          = 0x05,
    TRCH_TYPE_DCH_UL        = 0x06,
    TRCH_TYPE_DCH_DL        = 0x07,
    TRCH_TYPE_FACH_FOR_CBS  = 0x08,
   TRCH_TYPE_HSDSCH		= 0x09

};

typedef UINT8 tti_te;
//ICAT EXPORTED ENUM
enum tti_values
{
    TTI_2                        = 2,

    TTI_10                       = 10,
    TTI_20                       = 20,
    TTI_40                       = 40,
    TTI_80                       = 80
};


//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8       numOfTrCh;
    UINT8       trChId[MAX_NUM_TRCH];
    trChType_te trChType[MAX_NUM_TRCH];
    BYTE        pad[3];
}trChList_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8   numOfTfc;
    UINT8   numOfTrch;
    BYTE    pad[2];
    UINT8   *tfcsTable;
}tfcs_ts;

typedef UINT8   signalledFactors_te;
//ICAT EXPORTED ENUM
enum signalledFactors_values
{
    SIGNALLED           = 0x00,
    REF_AND_SIGNALLED   = 0x01,
    REFERENCE           = 0x02
};

//ICAT EXPORTED STRUCT
typedef struct
{
    signalledFactors_te signalledFactors;
    UINT8               betaC;
    UINT8               betaD;
    UINT8               refId;
    INT8                deltaPpm;
    BYTE                pad[3];
}powerOffsetParams_ts;

typedef UINT8   typeOfChCoding_te;
//ICAT EXPORTED ENUM
enum typeOfChCoding_values
{
    CONVOLUTIONAL_CODING    = 0x00,
    TURBO_CODING            = 0x01,
    NO_CODING               = 0x02
};

typedef UINT8   codingRate_te;
//ICAT EXPORTED ENUM
enum codingRate_values
{
    CODING_RATE_HALF        = 0x00,
    CODING_RATE_ONE_THIRD   = 0x01
};

typedef UINT8   crcSize_te;
//ICAT EXPORTED ENUM
enum crcSize_values
{
    NO_CRC      = 0x00,
    CRC_SIZE_8  = 0x01,
    CRC_SIZE_12 = 0x02,
    CRC_SIZE_16 = 0x03,
    CRC_SIZE_24 = 0x04
};

//ICAT EXPORTED STRUCT
typedef struct
{
    tti_te              trChTti;
    typeOfChCoding_te   typeOFChannelCoding;
    codingRate_te       codingRate;
    BYTE                pad;
    UINT16              rateMatchingAttribute;
    crcSize_te          crcSize;
    INT8                dchBlerQualTarget;
}trChSemiStatic_ts;

typedef UINT8   rachMsgLength_te;
//ICAT EXPORTED ENUM
enum rachMsgLength_values
{
    RACH_MSG_LENGTH_10_MS    = 10,
    RACH_MSG_LENGTH_20_MS    = 20
};

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16              transportBlockSize;
    UINT8               numOfTransportBlocks;
    rachMsgLength_te    rachMsgLength;
}trChDynamic_ts;

typedef UINT8   trChActionType_te;
//ICAT EXPORTED ENUM
enum trChActionType_values
{
    TRCH_ADD        = 0x01,
    TRCH_ACTION_RESERVED1 = 0x02,
    TRCH_ACTION_RESERVED2 = 0x03
};

typedef UINT8	reconfFlag_te;
//ICAT EXPORTED ENUM
enum reconfFlag_values
{
	TRCH_NO_RECONFIG		= 0x00,
	RECONFIG_WO_SYNC_PROC_A = 0x01
};

#define MAX_NUM_TFS 64
#define MAX_NUM_DL_TFS 64
#define MAX_NUM_UL_TFS 32
#define UL_MAC_DATA_NOT_READY 0xFF

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8               trChId;
    trChType_te         trChType;
    Bool                reportFlag;
    trChActionType_te   actionType;
    UINT8               numOfDynamic;
    BYTE                pad[3];
    trChDynamic_ts      dynamicPart[MAX_NUM_TFS];
    trChSemiStatic_ts   semiStaticPart;
}trChDescription_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
#if !(L1_FEATURE_COMB_TR_AND_PHY_CH)
    activationTime_ts       activationTime;
#endif
    tfcs_ts                 dlTfcs;
    tfcs_ts                 ulTfcs;
    powerOffsetParams_ts    *powerOffTab;
    UINT8                   numOfTrch;
    reconfFlag_te           reconfInd;
	BYTE                    pad[2];
    trChDescription_ts      *trCh[MAX_NUM_TRCH];

#if (L1_FEATURE_COMB_TR_AND_PHY_CH)
	Bool 					trchCfgExistence;
	BYTE					pad2[3];
#endif
}trchConfigDescription_ts;


typedef UINT8   phyChType_te;
//ICAT EXPORTED ENUM
enum phyChType_values
{
    PHY_CH_P_CCPCH         = 0x00,      // Must be the first
    PHY_CH_S_CCPCH         = 0x01,
    PHY_CH_AICH_PRACH      = 0x02,
    PHY_CH_PICH_S_CCPCH    = 0x03,
    PHY_CH_CBS_S_CCPCH     = 0x04,
    PHY_CH_DPCH            = 0x05,
 #ifndef L1_WB_R99_ONLY
	PHY_CH_HSPDSCH		   = 0x06,
	PHY_CH_EDCH		   		   = 0x07,
	#endif
#if defined (L1_UPGRADE_R8)
	PHY_CH_TC_HSSCCH            = 0x08,
	PHY_CH_ALL			   	    = 0x09,
	PHY_CH_HSPA			        = 0x0A,
	PHY_CH_PICH_HSDPA		    = 0x0B,
#else
	PHY_CH_ALL			   	    = 0x08,
    #ifndef L1_WB_R99_ONLY
	PHY_CH_HSPA			        = 0x09,
	PHY_CH_PICH_HSDPA		    = 0x0A,
	#endif
#endif
    PHY_CH_NONE                = 0x0F
};





typedef UINT8 fixFlexPosition_te;
//ICAT EXPORTED ENUM
enum fixFlexPosition_values
{
    FFP_FIXED                       = 0x00,
    FFP_FLEXIBLE                    = 0x01
};


/***********************************************************************
 * definitions for plwCphyPccpchSetupReq
 ***********************************************************************/
typedef UINT8 pccpchMode_te;
//ICAT EXPORTED ENUM
enum pccpchMode_values
{
    RESERVED_PCCPCH_MODE            = 0x00,
    SERVING_CELL_WOUT_SFN_UPDATE    = 0x01,
    SERVING_CELL_W_SFN_UPDATE       = 0x02,
    MONITORING_NEIGHBOR_CELL        = 0x03,
	MONITORING_FOR_BETTER_PLMN_SEARCH 	= 0x04,
	MONITORING_LOW_PRIOPRITY_INDCH  = 0x05       
};

//ICAT EXPORTED STRUCT
typedef struct
{
    activationTime_ts   activationTime;
    pccpchMode_te	    pccpchMode;
    BYTE                pad1;
    UINT16              dlUarfcn;
    UINT16              ulUarfcn;
    sttdInd_te          sttdInd;
    BYTE                pad2;
    UINT16              dlPriScramblingCode;
    BYTE                pad3[2];
} pccpchDescription_ts;

/***********************************************************************
 * definitions for plwCphySccpchSetupReq
 ***********************************************************************/
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16              scramblingCode;
    sttdInd_te          sttdInd;
    BYTE                pad1;
    UINT16              spreadingFactor;
    UINT8               chanCodeNum;
    Bool                pilotSymbolExistence;
    Bool                tfciExistence;
    fixFlexPosition_te  fixFlexPosition;
    UINT16              timingOffset;
} sccpchPhyParams_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
    activationTime_ts   activationTime;
    tti_te              maxTtiOverThePhyCh;
    BYTE                pad[3];
    sccpchPhyParams_ts  sccpchPhyParams;
#if (L1_FEATURE_COMB_TR_AND_PHY_CH)
	trchConfigDescription_ts trchDescription;
#endif
} sccpchDescription_ts;

/***********************************************************************
 * definitions for plwCphySetFachOccasionParamsReq
 ***********************************************************************/
//ICAT EXPORTED STRUCT
typedef struct
{
  plActionType_te     actionType;
  UINT8               fachMeasurementCycle;
  UINT16              fachMeasOccasionCrnti;
  tti_te              maxTti;
  BYTE                pad[3];
} fachOccasionInfo_ts;

/******************************************************
* Definitions for CBS scheduling
*****************************************************/
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8       cbsFrameOffset;
    BYTE        pad1;
    UINT16      cbsOccasionPeriod;
	UINT16 		cbsSmOccasionPeriod;
	UINT16		pad2;
} ctchOccasionInfo_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
    sccpchPhyParams_ts      sccpchPhyParams;
    ctchOccasionInfo_ts     ctchOccasionInfo;
#if (L1_FEATURE_COMB_TR_AND_PHY_CH)
	trchConfigDescription_ts trchDescription;
#endif

} sccpchCbsDescription_ts;

typedef UINT8 cbsL2ActionType_te;
//ICAT EXPORTED ENUM
enum plCbsL2ActionTyp_values
{
  CBS_L2_ACTION_TYPE_STOP          = 0x00,
  CBS_L2_ACTION_TYPE_START         = 0x01,
  CBS_L2_ACTION_TYPE_MODIFY         = 0x02
};


//ICAT EXPORTED STRUCT
typedef struct
{
   UINT8      periodId;
#if (L1_FEATURE_CBS_L2_SUPPORT_START_STOP)
   cbsL2ActionType_te       cbsL2ActionType; 
   UINT8	  pad[2];
#else
	UINT8	   pad[3];
#endif
   UINT8      rxPeriodOffset[MAX_CBS_RX_PERIODS];
   UINT16     numOfRxPeriods;
   UINT16     NumOfBSInSchedulingPeriod ;
   UINT16     referenceSfn;
   UINT16	  NextPeriodOffset;
} cbsLevel2Scheduling_ts;



/***********************************************************************
 * definitions for plwCphyPichAndSccpchSetupReq
 ***********************************************************************/
//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8               drxCycleLengthCoeff;
  UINT8				  drxCycleLengthCoeff2;
  BYTE			      pad[3];
  UINT8               pagingInd;
  UINT16              pagingOccasion;
  UINT16              pagingOccasion2;//CQ52043
} pagingInfo_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16              scramblingCode;
  UINT8               channelizationCode;
  sttdInd_te          sttdInd;
  INT8                pichPowerOff;
  UINT8               numOfPiPerFrame;
  BYTE                pad[2];
  pagingInfo_ts       pagingInfo;
} pichPhyParams_ts;
typedef UINT8 rrcStateIndicator_te;
//ICAT EXPORTED ENUM
enum rrcStateIndicator_values
{
	RRC_IDLE	=	0x00,
	CELL_PCH	=	0x01,
	URA_PCH		=	0x02,
	CELL_FACH	=	0x03,
	CELL_DCH	=	0x04
};
//ICAT EXPORTED STRUCT
typedef struct
{
  pichPhyParams_ts      pichPhyParams;
  sccpchPhyParams_ts    sccpchPhyParams;
#if (L1_FEATURE_COMB_TR_AND_PHY_CH)
	trchConfigDescription_ts trchDescription;
#endif
} pichAndSccpchDescription_ts;



/***********************************************************************
 * definitions for plwCphyPrachAichSetupReq
 ***********************************************************************/

#define MAX_NUM_ASC 8

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16              scramblingCode;
  UINT16              spreadingFactor;
  UINT8               puncturingLimit;
  INT16               txInitPower;
  UINT8               powerRampStep;
  UINT8               preambMaxRetransNum;
  UINT8               numOfAsc;
  UINT16              availableSignature[MAX_NUM_ASC];
  UINT16              availableSubChannelNum[MAX_NUM_ASC];
  INT8                maxUlTxPower;
#if defined (L1_UPGRADE_R8)  
  UINT16              commonEdchAvailableSignature;  
  UINT8               pad[3];
#else
  #if defined (L1_WB_R99_ONLY)
  UINT16			  pad1; 
  UINT8				  pad[3];
  #endif
#endif  
}prachPhyParams_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16              scramblingCode;
  UINT8               channelizationCode;
  sttdInd_te          sttdInd;
  UINT8               aichTxTiming;
  INT8                aichPowerOffset;
  BYTE                pad[2];
#if defined (L1_UPGRADE_R8)  
  Bool                eaiIndication;
  UINT8               pad1[3];
#endif  
#if defined (L1_WB_R99_ONLY)
  Bool                pad2;
  UINT8               pad3[3];
#endif

}aichPhyParams_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	prachPhyParams_ts   prachPhyParams;
	aichPhyParams_ts    aichPhyParams;
#if (L1_FEATURE_COMB_TR_AND_PHY_CH)
	trchConfigDescription_ts trchDescription;
#endif

#if defined (L1_UPGRADE_R8)
    UINT8                ecfUlPowerOffsetPpe;
    UINT8			     pad[3];
#endif    
#if defined (L1_WB_R99_ONLY)
    UINT8                pad2;
    UINT8			     pad3[3];
#endif   


}prachAichDescription_ts;

/***********************************************************************
 * definitions for plwCphyDpchSetupReq
 ***********************************************************************/

#define MAX_NUM_DL_RLS              12
#define MAX_DPCH_DL_CHAN_CODES      3

#if !defined (REL5_CLEANUP_FEATURE)
typedef UINT8   ssdtCodeWordSet_te;
//ICAT EXPORTED ENUM
enum ssdtCodeWordSet_values
{
  SSDT_LONG        = 0x00,
  SSDT_MEDIUM      = 0x01,
  SSDT_SHORT       = 0x02,
  SSDT_OFF         = 0x03
};

typedef UINT8   ssdtCellIdentity_te;
//ICAT EXPORTED ENUM
enum ssdtCellIdentity_values
{
  SSDT_CELL_ID_LABEL_A    = 0x00,
  SSDT_CELL_ID_LABEL_B    = 0x01,
  SSDT_CELL_ID_LABEL_C    = 0x02,
  SSDT_CELL_ID_LABEL_D    = 0x03,
  SSDT_CELL_ID_LABEL_E    = 0x04,
  SSDT_CELL_ID_LABEL_F    = 0x05,
  SSDT_CELL_ID_LABEL_G    = 0x06,
  SSDT_CELL_ID_LABEL_H    = 0x07,
  SSDT_OMITTED            = 0x08
};
#endif

typedef UINT8   txDiversityMode_te;
//ICAT EXPORTED ENUM
enum txDiversityMode_values
{
    TX_DM_NO_DIVERSITY        = 0x00,
    TX_DM_STTD                = 0x01,
    TX_DM_CLOSED_LOOP_MODE1   = 0x02,
    TX_DM_CLOSED_LOOP_MODE_2  = 0x03,
	TX_DM_INVALID_DIVERSITY   = 0xff
};

typedef UINT8 pcAlgorithm_te;
//ICAT EXPORTED ENUM
enum plAlgorithm_values
{
    PCA_ALGORITHM_1 = 0x00,
    PCA_ALGORITHM_2 = 0x01
};

typedef UINT8   dpchTimingInd_te;
//ICAT EXPORTED ENUM
enum dpchTimingInd_values
{
    TI_INITIALIZE               = 0x00,
    TI_MAINTAIN                 = 0x01,
    TI_DPCH_ESTABLISHMENT       = 0x02,
    TI_SHO                      = 0x03,
    TI_RECONFIGURATION          = 0x04,
    TI_INTER_RAT_HHO            = 0x05,
    TI_3G_HHO_FAILURE           = 0x06,
    TI_DPCH_EST_DIFF_CELL       = 0x07,
    TI_RECONFIGURATION_FAILURE  = 0x08
};

//ICAT EXPORTED STRUCT
typedef struct
{
    INT8    maxUlTxPower;
    BYTE    pad1;
    INT16   dpcchPowerOffset;
	UINT8   pcPreambles;
    UINT8   pcAlgorithm;
    UINT8   tpcStepSize;
    BYTE    pad2;

} dpchUlPowerControl_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
    dpchUlPowerControl_ts   dpchUlPowerControl;
    UINT32                  dpchUlScrCode;
    UINT16                  ulSpreadingFactor;//min SF used in DCH	25.331 10.3.6.88
    Bool                    tfciExist;
    UINT8                   numOfFbiBits;
    UINT8                   puncturingLimit;
	UINT8					numOfDpdch;
	UINT8					numOfTpcBits;
	BYTE					pad;

} dpchUlRlParams_ts;




//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8				dpchDlChanCode;
    Bool                alternateScrCode;
	UINT16				dpchDlScrCode;
}dpchMultiCode_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
    plActionType_te     actionType;
    BYTE                pad1;
    UINT16              rlId;
    UINT16              phaseRefScrCode;
    UINT8               phaseRefChanCode;
    BYTE                pad2;
    UINT16              dpchFrameOffset;
    UINT8               numOfDlChanCodes;
    UINT8               pad4;
    dpchMultiCode_ts	dpchMultiCode[MAX_DPCH_DL_CHAN_CODES];
    UINT8               tpcCombinationIndex;//RLs with same index have same TPC and E-HICH value, range[0,5]. Among these RLs, TPC or HICH can be combined
#if !defined (REL5_CLEANUP_FEATURE)
	ssdtCellIdentity_te ssdtCellIdentity;
#else
	UINT8 				pad6;
#endif
    txDiversityMode_te  txDiversityMode;
    Bool                tfci2TransmitInd;//always false
    BYTE                pad5;
#if !defined (REL5_CLEANUP_FEATURE)
    Bool                usedForPdsch;
#else
    Bool                pad7;
#endif
	UINT8				closedLoopTimingAdjMode;
	UINT8				fdpchSlotFormat;  // should always be 0 for RELEASE 6//FDPCH symbol index 0~9 fdpchSymbIdx = fdpchSlotFormat == 9 ? 0 : fdpchSlotFormat + 1;

} dpchDlRlParams_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
    dpchTimingInd_te    timingInd;
    UINT8               dpcMode;
    UINT16              spreadingFactor;
    UINT8               numOfPilotBits;
    fixFlexPosition_te  fixFlexPosition;
    Bool                tfciExist;
    UINT8               sField;
	Bool			    postVerificationPeriod;
	UINT8			    powerOffsetPpilotDpdch;
	UINT8			    tpcCommandErrRateTarget;  //(1..10) Real Range: 0.01..0.1 by steps of 0.01	
	Bool 			    TimingMaintainedSynchronizationIndicator;
    UINT32              defaultDPCHOffsetValue;
} dpchCommonDlParams_ts;


typedef UINT8 plwPhyChConfigValidity_te;
//ICAT EXPORTED ENUM
enum  plwPhyChConfigValidity_values
{
	PLW_DPCH_DATA_EXISTENCE_BIT = 0x01,
	PLW_HSDPA_DATA_EXISTENCE_BIT = 0x02,
	PLW_HSUPA_DATA_EXISTENCE_BIT = 0x04,
	PLW_CPC_DATA_EXISTENCE_BIT = 0x08
    #if defined (L1_UPGRADE_R8)
	,
	PLW_AICH_DATA_EXISTENCE_BIT = 0x10
	#endif
};

#define MAX_NUM_EDCH_RL                 4
#define MAX_REF_ETFCI					8

typedef		UINT8       edchActionType_te;
//ICAT EXPORTED ENUM
enum  edchActionType_values
{
    SETUP_EDCH,
    RECONFIGURATION,
    ACTIVE_SET_UPDATE
};

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                   referenceEtfci;
    UINT8                   referenceEtfciPowerOffset;
	UINT8					pad[2];
}referenceEtfci_ts;

typedef		UINT8       harqRvConfiguration_te;
//ICAT EXPORTED ENUM
enum  harqRvConfiguration_values
{
    RV0,
	RVTABLE
};

typedef		UINT8       maxChanCodes_te;
//ICAT EXPORTED ENUM
enum  maxChanCodes_values
{
    SF256,
	SF128,
	SF64,
	SF32,
	SF16,
	SF8,
	SF4,
	TWO_SF4,
	TWO_SF2,
	TWO_SF2_AND_TWO_SF4
};

#if (L1_FEATURE_BEC_BOOST_THRESHOLD)
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                   etfciBoost;
    UINT8                   deltaT2TP;
	UINT8					pad[2];
}etfcBoostInfo_ts;
#endif
#if defined (L1_UPGRADE_R8)

typedef		UINT8       minimumReducedEdpdchGainFactor_te;
//ICAT EXPORTED ENUM
enum  minimumReducedEdpdchGainFactor_values
{

    M8_15,
    M11_15,
    M15_15,
    M21_15,
    M30_15,
    M42_15,
    M60_15,
    M84_15
};
#endif

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                   numOfRefEtfci;    
    referenceEtfci_ts		referenceEtfci[MAX_REF_ETFCI];    

	UINT8					pad[1];    
	Bool					etfciTableIndex;    
	UINT8					macdFlowPowerOffsets;
    harqRvConfiguration_te  harqRvConfig;
	maxChanCodes_te    	    maximumChannelisationCodes;    
	UINT8         		    plNonMax;    
	UINT8 					edpcchDpcchPowerOffset;

#if (L1_FEATURE_BEC_BOOST_THRESHOLD)
    etfcBoostInfo_ts        etfcBoostInfo;
    Bool                    edpdchPowerInterpolation;
    UINT8					pad2[2];    
#endif    

#if (L1_UPGRADE_UL16QAM)  //CQ00067582
	Bool								is16QAMConfigured;
	UINT8					pad3[3];

#endif

}edchUlParams_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8					pad[3];
	UINT8                   agchChannelisationCode;
}agchParameters_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8					pad[2];
	UINT8                   channelisationCode;
	UINT8                   signatureSequence;
}hichParameters_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8					pad[2];
	UINT8                   signatureSequence;
	UINT8                   combinationIndex;
}rgchParameters_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
    Bool                    servingRadioLinkIndicator;
	UINT8                   tpcCombinationIndex;
	UINT16                  dlScramblingCode;
	hichParameters_ts       hich;
	UINT8					pad[3];
	Bool          		    rgchActivatedOnThisRl;
	rgchParameters_ts       rgch;
	txDiversityMode_te		txDiversityMode;
	UINT16					dpchFrameOffset;
}edchDlParams_ts;


/***********************************************************************
 * definitions for plwCphyEdchSetupReq
 ***********************************************************************/
#if defined (L1_UPGRADE_R8)

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                   sOffset;
    UINT8                   fdpchDlChanCode;  
    UINT8					pad[2];    
	UINT32                  dpchUlScrCode;    
	rgchParameters_ts       rgchParams;
	hichParameters_ts       hichParams;
}edchResource_ts;

#define MAX_NUM_COMMON_EDCH_RESOURCES   32

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                   relativeAmplitudeWeightingFactor;
    UINT8                   numOfCommonEdchResources;
    UINT8					pad[2];    
	edchResource_ts         CommonEdchResource[MAX_NUM_COMMON_EDCH_RESOURCES];
}commonEdchResources_ts;


#endif

//ICAT EXPORTED STRUCT
typedef struct
{
    activationTime_ts       activationTime;
	UINT8					pad1[3];
	edchActionType_te       edchActionType;
	edchUlParams_ts         edchUlRlParams;
	agchParameters_ts  	    agch;
	UINT8					pad2[1];
	UINT8					numOfDpdch;
	UINT8                   ttiSize;
	UINT8					numOfDlRl;
	edchDlParams_ts         edchDlRlParams[MAX_NUM_EDCH_RL];
	UINT16                  erntiPrimary;
	UINT16                  erntiSecondary;
#if defined (L1_UPGRADE_R8)
    commonEdchResources_ts  commonEdchResources;
	rrcStateIndicator_te    rrcStateIndicator;
    minimumReducedEdpdchGainFactor_te minimumReducedEdpdchGainFactor;
    UINT8				    pad[2];
#endif    
} edchDescription_ts;



typedef UINT8   OutOfSyncCause_te;
//ICAT EXPORTED ENUM
enum OutOfSyncCause_values
{
	/** OutOfSync because of failure to establish physical channels. */
    PLW_PHYS_CHAN_ESTABLISH_FAILURE = 0,
	
		/** OutOfSync because of Radio Link failure. */
    PLW_RADIO_LINK_FAILURE = 1
};

/** Defines the constants and timers used during CELL_DCH channel
 * synchronisation.
 * The diagram below illustrates the usage of these parameters.
 *
 * \image html prd3gphychsync.png "Fig: Physical Channel Synchronisation"
 * \image latex prd3gphychsync.eps "Physical Channel Synchronisation" width=12cm
 */


//ICAT EXPORTED STRUCT
typedef struct 
{
    /** Constant used in CELL_DCH channel establishment. */
    INT16   n_312;
    /** Constant used in determining a Radio Link failure. */
    UINT8   n_313;
    /** Constant used in determining a Radio Link failure. */
    INT16   n_315;
    /** Timer used in CELL_DCH channel establishment. */
    INT8    t_312;
    /** Timer used in determining a Radio Link failure. */
    INT8    t_313;
	BYTE 	pad;
}
SyncParameters_ts;

//ICAT EXPORTED STRUCT
typedef struct SyncParametersConnectedTag
{
    /** Constant used in CELL_DCH channel establishment. */
    INT16                               n_312;
    /** Timer used in CELL_DCH channel establishment. */
    INT8                              t_312;
	BYTE 	pad;
}
SyncParamsConnected_ts;



//ICAT EXPORTED STRUCT
typedef struct
{
    activationTime_ts      	activationTime;
    tti_te                 	maxTtiOverThePhyCh;
    Bool                   	enableLegacySyncInd;
    UINT16                 	dlUarfcn;
    UINT16                 	ulUarfcn;
    BYTE                   	pad2[2];
    dpchCommonDlParams_ts  	dpchDlCommonParams;
    UINT8                  	numOfRL;
    Bool                       onlyOneCsRb;//CQ96577
    BYTE                   	pad3[2];
    dpchDlRlParams_ts      	dpchDlRlParams[MAX_NUM_DL_RLS];
    dpchUlRlParams_ts      	dpchUlRlParams;
    UINT8					pad4[2];
    Bool					fdpchEnabled;
    plwPhyChConfigValidity_te phyChConfigValidity;

	SyncParameters_ts		SyncParams;
	SyncParamsConnected_ts	SyncParamsConnected;
#if defined (L1_UPGRADE_R8)
	rrcStateIndicator_te	rrcStateIndicator;
    UINT8					pad5[3];
#endif   
#if defined (L1_WB_R99_ONLY)
     UINT8				   pad6[4];
#endif
#if (L1_FEATURE_COMB_TR_AND_PHY_CH)
	trchConfigDescription_ts trchDescription;
#endif

} dpchDescription_ts;
#if defined (L1_UPGRADE_R8)
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16		        hRnti;
    UINT16              dlScramblingCode;
    txDiversityMode_te  txDiversityMode;
    UINT8               channelizationCode;
    UINT8               pad[2];
}tcHsScchSetup_ts;
#endif

/***********************************************************************
 * definitions for plwCphyRlReleaseReq
 ***********************************************************************/
typedef UINT8 phyChReleaseReason_te;
//ICAT EXPORTED ENUM
enum phyChReleaseReason_values
{
    CH_RR_INTER_FR_HHO          = 0x00,
    CH_RR_INTRA_FR_HHO          = 0x01,
    CH_RR_INTER_RAT_HHO         = 0x02,
    CH_RR_INTER_FR_RESELECT     = 0x03,
    CH_RR_INTRA_FR_RESELECT     = 0x04,
    CH_RR_NORMAL                = 0x05,
	CH_RR_RESERVED              = 0x06,
	CH_RR_INTER_RAT_RESELECTION = 0x07,
    CH_RR_HSDSCH_SERVING_CELL_CHANGE = 0x08

};

//ICAT EXPORTED STRUCT
typedef struct
{
    activationTime_ts       activationTime;
    phyChType_te            phyChType;
    phyChReleaseReason_te   releaseReason;
    plwPhyChConfigValidity_te phyChConfigValidity;
	BYTE					padding;
} rlReleaseDescription_ts;

/***********************************************************************
 * definitions for plwCphyModifyDpchReq
 ***********************************************************************/
#define MAX_NUM_MODIFY_DL_RLS 6

//ICAT EXPORTED STRUCT
typedef struct
{
    dpchUlPowerControl_ts   dpchUlPowerControl;
    UINT32      dpchUlScrCode;
    UINT16      ulSpreadingFactor;
    Bool        tfciExist;
    UINT8       numOfFbiBits;
    UINT8       puncturingLimit;
	UINT8		numOfDpdch;
	UINT8		numOfTpcBits;
	BYTE		pad;
} dpchModifyUlParams_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16                  rlID;
    UINT16                  phaseRefScrCode;
    UINT8                   numOfDlChanCodes;
    UINT8                   phaseRefChanCode;
	UINT16					dpchFrameOffset;

    UINT8                   tpcCombinationIndex;
#if !defined (REL5_CLEANUP_FEATURE)
    ssdtCellIdentity_te     ssdtCellIdentity;
#else
	UINT8 					pad1;
#endif
    dpchMultiCode_ts	    dpchMultiCode[MAX_DPCH_DL_CHAN_CODES];
    txDiversityMode_te      txDiversityMode;
    Bool                    tfci2TransmitInd;
	UINT8					closedLoopTimingAdjMode;
	UINT8					fdpchSlotFormat;  // should always be 0 for RELEASE 6

} dpchModifyDlParams_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8               dpcMode;
    BYTE                pad1;
    UINT16              spreadingFactor;
    UINT8               numOfPilotBits;
    fixFlexPosition_te  fixFlexPosition;
    Bool                tfciExist;
    UINT8               sField;
#if !defined (REL5_CLEANUP_FEATURE)
    ssdtCodeWordSet_te  ssdtCodeWordSet;
#else
	UINT8 				pad2;
#endif
	UINT8				powerOffsetPpilotDpdch;
	UINT8				tpcCommandErrRateTarget; // (1..10) Real Range: 0.01..0.1 by steps of 0.01
	UINT8               pad3[1];

} dpchModifyCommonDlParams_ts;

typedef UINT8  dpchModifyControl_te;
//ICAT EXPORTED ENUM
enum dpchModifyControl_values
{
    DL_DPCH_MODIFY          = 0x00,
    UL_DPCH_MODIFY          = 0x01,
    UL_AND_DL_DPCH_MODIFY   = 0x02
};

//ICAT EXPORTED STRUCT
typedef struct
{
    activationTime_ts               activationTime;
    dpchModifyCommonDlParams_ts     dpchCommonParams;
    dpchModifyControl_te            dpchModifyControl;
    UINT8                           numOfRL;
    Bool                             onlyOneCsRb;//CQ96577
    BYTE                            pad1[1];
    dpchModifyDlParams_ts           dpchDlParams[MAX_NUM_MODIFY_DL_RLS];
    dpchModifyUlParams_ts           dpchUlParams;
	Bool							fdpchEnabled;
    UINT8                           pad2[2];
    plwPhyChConfigValidity_te    phyChConfigValidity;

	SyncParamsConnected_ts	   SyncParamsConnected;
#if (L1_FEATURE_COMB_TR_AND_PHY_CH)
	trchConfigDescription_ts trchDescription;
#endif
} dpchModifyDescription_ts;

#if (L1_FEATURE_CBS_L2_SUPPORT_START_STOP)
typedef UINT8   L2StatusInd_te;
//ICAT EXPORTED ENUM
enum L2StatusInd_values
{
    L2_IND_SUCCESS     = 0x00,
    L2_IND_FAILURE_WRONG_ID     = 0x01
};

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8 periodId;
	L2StatusInd_te	  statusInd;
	BYTE			pad[2];
} level2Cnf_ts;
#endif

/***********************************************************************
 * definitions for plwCphyRlSetupCnf
 ***********************************************************************/
typedef UINT8   statusInd_te;
//ICAT EXPORTED ENUM
enum statusInd_values
{
    L1_IND_SUCCESS     = 0x00,
    L1_IND_FAILURE     = 0x01
};

//ICAT EXPORTED STRUCT
typedef struct
{
    phyChType_te    phyChType;
    statusInd_te    statusInd;
    BYTE            pad[2];
    INT16           cpichEcNo;
    INT16           cpichRscp;
} rlSetupCnf_ts;

/***********************************************************************
 * definitions for plwCphyRlReleaseCnf
 ***********************************************************************/
//ICAT EXPORTED STRUCT
typedef struct
{
    phyChType_te    phyChType;
    BYTE            pad[3];
} rlReleaseCnf_ts;

/***********************************************************************
 * definitions for plwPhyAccessCnf
 ***********************************************************************/
typedef UINT8   randomAccessStatus_te;
//ICAT EXPORTED ENUM
enum randomAccessStatus_values
{
    ACK     = 0x00,
    NO_ACK  = 0x01,
    NACK    = 0x02
};


//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8	cfn;
	Bool	readyToSend;
    INT16    powerLeft[NUM_OF_SLOTS];//change from INT8
 // BYTE    pad[3];
}plUlDataSync_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	//TRCH ID 1..32
    UINT8       trchId;
	//TFI 1..64
	UINT8		tfi;
	UINT8		pad[2];
}ulPduDataInfo_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	//give the start address of UL data block in this TTI to allow L1 get the data by DMA way
    UINT32       		ulDataStartAddr;
	//TFCI value 0..64
	UINT8				tfciValue;
	//TRCH type: DCH or RACH
	trChType_te     	trChType;
	
	UINT8				pad;
	//number of TRCH 0..8
	UINT8				trchNum;
	//TRCH data info, only the items indicated by trchNum are available
	ulPduDataInfo_ts	trchDataInfo[MAX_UL_TRCH_NUM_IN_ONE_TTI];
}plDataReqHeader_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT32		tbAddr;
    UINT8       trChId;
    trChType_te trChType;
    UINT16      frameNum;
//    UINT16      dataSize;
    UINT8       transpFormatId;
    BYTE        pad[3];
    UINT32      crcCheckResult;
}plDataIndHeader_ts;

/*
typedef struct 
{ 
	 //index of the subframe or frame whose data is ready for reading 
	 UINT16 		  sfn; 
	 //max 4 block per TTI 
	 UINT8			 dataBlockNum; 
	 UINT8 			 pad1; 
	 //The address of each Mac-hs/ehs PDU 
	 UINT32 		  dataBlockStartAddr[MAX_HSDPA_DATA_BLOCK_NUM]; 
	 //Used for Umahs to align Mac-d data part to 8bits, Always set to 0 in Mac-ehs, Range 0..7 
	 UINT8			 byteAlignOffset[MAX_HSDPA_DATA_BLOCK_NUM]; 
	 //the bit length of Mac-hs or Mac-ehs PDU size 
	 UINT16 		  bitlength[MAX_HSDPA_DATA_BLOCK_NUM]; 
	 // Flag to indicate this PDU is PCH or BCH as LogCH Id equal to 15, 1: BCH, 0 PCH 
	 UINT8			 hrntiReceivedInd[MAX_HSDPA_DATA_BLOCK_NUM]; 
	 // Indicate if this PDU is Mac-hs or Mac-ehs type,0 : Mac-hs, 1: Mac-ehs 
	 UINT8			 macType[MAX_HSDPA_DATA_BLOCK_NUM]; 
}plHsDataIndHeader_ts;
*/
//ICAT EXPORTED STRUCT
typedef struct
{
	//The address of each Mac-hs/ehs PDU 
	UINT32			dataBlockStartAddr;
	//the bit length of Mac-hs or Mac-ehs PDU size 
	UINT16			bitlength;
	//Used for Umahs to align Mac-d data part to 8bits, Always set to 0 in Mac-ehs, Range 0..7 
	UINT8 			byteAlignOffset;
	// Flag to indicate this PDU is PCH or BCH as LogCH Id equal to 15, 1: BCH, 0 PCH 
	UINT8 			hrntiReceivedInd;
	//transmission numbers
	UINT8 			numOfTransmission;
	//TB received from primary cell or secondary cell: 0: primary cell, 1: secondary cell.
	UINT8			receivedFromCell;
	
	UINT16			reserved;
}HsTbInfo_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	//index of the subframe or frame whose data is ready for reading 
    UINT16          sfn;
	//subframe sequence number
	UINT8           subframe;
	// Indicate if this PDU is Mac-hs or Mac-ehs type,0 : Mac-hs, 1: Mac-ehs 
  	UINT8           macType;
	
	UINT8			reserved[3];
	//max 2 block per TTI 
   	UINT8           dataBlockNum;

    HsTbInfo_ts     HsTbInfo[MAX_HSDPA_DATA_BLOCK_NUM];
} plHsDataIndHeader_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8	numBlockAlloc;

	UINT8	reserved[3];
	
	UINT32	dpaDataAddrArray[MAX_PRE_ALLOC_DPA_DATA_BLOCKS];
	
}plHsPointerReqHeader_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8	numBlockAlloc;

	UINT8	reserved[3];
	
	UINT32	dlDataAddrArray[MAX_PRE_ALLOC_DL_DATA_BLOCKS];
	
}plDlPointerReqHeader_ts;

/***********************************************************************
 * definitions for plwPhyUplinkDataTransferEnd plwPhyDownlinkDataTransferEnd
 ***********************************************************************/
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8       trChId;
    trChType_te trChType;
    BYTE        pad[2];
}dataTransferEnd_ts;

/***********************************************************************
 * definitions for plwCphySetCompressedModeParams
 ***********************************************************************/
#ifdef UPGRADE_LTE
#define     MAX_NUM_OF_TGPS                     6
#define     CM_TGPS_ID_MAX_VAL                  6
#else
#define     MAX_NUM_OF_TGPS                     5
#define     CM_TGPS_ID_MAX_VAL                  5
#endif
#define     CM_TGPS_ID_MIN_VAL					1
#define     CM_TGPRC_MAX_VAL                    511
#define     CM_TGSN_MAX_VAL                     14
#define     CM_TGL_MAX_VAL                      14
#define     CM_TGD_MAX_VAL                      269
#define     CM_TGPL_MAX_VAL                     144
#define     CM_DELTA_SIR_MAX_VAL                30
#define     CM_DELTA_SIR_AFTER_MAX_VAL          30
#define     CM_N_BSIC_IDENTIFY_ABORT_MAX_VAL    128
#define     CM_N_BSIC_RECONFIRM_ABORT_MAX_VAL   20


typedef UINT8   dlFrameType_te;
//ICAT EXPORTED ENUM
typedef enum
{
    TYPE_A                  = 0x00,
    TYPE_B                  = 0x01,

    CM_DL_FRAME_TYPE_MAX_VAL = 0x01 // must be EQUAL to the highest value in enum!
}dlFrameType_values;

typedef UINT8   CompModeMethod_te;
//ICAT EXPORTED ENUM
typedef enum
{
    PUNCTURING                  = 0x00, // Used only in DL
    SF_BY_TWO                   = 0x01,
    HIGHER_LAYER_SCHEDULING     = 0x02,

    CM_METHOD_MAX_VAL           = 0x02 // must be EQUAL to the highest value in enum!
}CompModeMethod_values;

typedef UINT8   ulDlMode_te;
//ICAT EXPORTED ENUM
typedef enum
{
    DL_ONLY                     = 0x00,
    UL_ONLY                     = 0x01,
    DL_AND_UL                   = 0x02,

    CM_UL_DL_MODE_MAX_VAL       = 0x02 // must be EQUAL to the highest value in enum!
}ulDlMode_values;

typedef UINT8   itpMode_te;
//ICAT EXPORTED ENUM
typedef enum
{
    L1_ITP_MODE_0                  = 0x00,
    L1_ITP_MODE_1                  = 0x01,

    CM_ITP_MODE_MAX_VAL            = 0x01 // must be EQUAL to the highest value in enum!
}itpMode_values;

typedef UINT8   rppMode_te;
//ICAT EXPORTED ENUM
typedef enum
{
    L1_RPP_MODE_0                  = 0x00,
    L1_RPP_MODE_1                  = 0x01,

    CM_RPP_MODE_MAX_VAL            = 0x01 // must be EQUAL to the highest value in enum!

}rppMode_values;

typedef UINT8   l1Tgmp_te;
//ICAT EXPORTED ENUM
enum  l1Tgmp_values
{
    RESERVED2                    = 0x00,
    FDD_MEAS                     = 0x01,
    GSM_CARRIER_RSSI_MEAS        = 0x02,
    GSM_INIT_BSIC_IDENTIFICATION = 0x03,
    GSM_BSIC_RECONFIRM           = 0x04,
#ifdef UPGRADE_LTE
    E_UTRA_MEAS                  = 0x05,
    CM_PS_TGMP_MAX_VAL           = 0x06
#else
    CM_PS_TGMP_MAX_VAL           = 0x05
#endif
};

typedef UINT8   tgpsStatusFlag_te;
//ICAT EXPORTED ENUM
enum tgpsStatusFlag_values
{
    TGPS_ACTIVE ,
    TGPS_INACTIVE,
    TGPS_MODIFY,
    TGPS_CONTINUE,

    CM_PS_TGPS_STATUS_MAX_VAL   = TGPS_CONTINUE // must be EQUAL to the highest value in enum!
};

//ICAT EXPORTED STRUCT
typedef struct
{
    l1Tgmp_te               l1Tgmp;
    BYTE                    pad1;
    UINT16                  l1Tgprc;
    UINT8                   l1Tgsn;
    UINT8                   l1Tgl1;
    UINT8                   l1Tgl2;
    BYTE                    pad2;
    UINT16                  l1Tgd;
    UINT8                   l1Tgpl1;
    UINT8                   l1Tgpl2;
    rppMode_te              l1Rpp;
    itpMode_te              l1Itp;
    ulDlMode_te             l1UIDI;
    CompModeMethod_te       dlCompModeMethod;
    CompModeMethod_te       ulCompModeMethod;
    dlFrameType_te          dlFrameType;
    UINT8                   deltaSir1;
    UINT8                   deltaSirafter1;
    UINT8                   deltaSir2;
    UINT8                   deltaSirafter2;
    UINT8                   nldentifyAbort;
    UINT8                   tReconfirmAbort;
}tgpsConfig_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                   tgpsIdentifier;
    tgpsStatusFlag_te       tgpsStatusFlag;
    UINT8                   I1Tgcfn;
    BYTE                    pad;
    activationTime_ts       activationTime;
    tgpsConfig_ts           tgpsConfig;
}dpchTgpsParams_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                   numOfTpgs;
    BYTE                    pad[3];
    dpchTgpsParams_ts       dpchTgpsParam[MAX_NUM_OF_TGPS];
}dpchCompressModeParams_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8               numOfSlotGaps;
  CompModeMethod_te   compModeMethod;
  BYTE                pad[2];
  UINT16			  CompressedSlotsBitmap;
}frameCmInfo_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8             collisionCfn;
  UINT8             tgpsIdentifier;
  l1Tgmp_te         l1Tgmp;
  BYTE              pad;
}errTgpsParams_ts;

#define MAX_NUM_ERR_TGPS 4

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8             numOfTgps;
  BYTE              pad[3];
  errTgpsParams_ts  errTgpsParams[MAX_NUM_ERR_TGPS];
}cmErrorInd_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8             numOfTgps;
  UINT8				pad[3];
  UINT8				tgpsIdentifier[MAX_NUM_OF_TGPS];
  UINT8 			lastCfnOfTgps[MAX_NUM_OF_TGPS];
}cmPatternEndedInd_ts;


#define MAX_TTI_LENGTH	8

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8           numOfFrames;
  UINT8				  FirstCfn;
  BYTE            pad[2];
  frameCmInfo_ts  frameCmInfo[MAX_TTI_LENGTH];
}plTtiInfo_ts;

#define MAX_NUM_LOOPBACK_TRCH 8

//ICAT EXPORTED STRUCT
typedef struct
{
	activationTime_ts	activationTime;
	plActionType_te		actionType;
	UINT8				trChId;
	trChType_te			trChType;
}lbTrCh_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8       numOfTrCh;
  UINT8 	  simID;
	lbTrCh_ts		lbTrCh[MAX_NUM_LOOPBACK_TRCH];
}lbMode2params_ts;
//ICAT EXPORTED STRUCT
typedef struct{
  statusInd_te restoreStatus;
  phyChType_te restoredChannelType;
  UINT16       dlUarfcn;
  UINT16       dlPriScramblingCode;
  INT16        cpichEcNo;
  INT16        cpichRscp;
}restoreWcdmaCnf_ts;


#define BITS_PER_UINT8        	8
#define BITS_PER_UINT16        	16

#define BITS_TO_UINT8(bits)   	(((bits) + BITS_PER_UINT8 - 1)/BITS_PER_UINT8)


//////////////HSDPA types and enums
#define MAX_H_PROCESS	8
#define MAX_H_SSCCH_HS	4


typedef UINT8	macType_te;
//ICAT EXPORTED ENUM
enum macType_values
{
	MAC_HS		= 0x00,
	MAC_EHS 	= 0x01
};

typedef UINT8 TrBkSizeTableIndex_te;
//ICAT EXPORTED ENUM
enum TrBkSizeTableIndex_values
{
	BIT_ALIGNED		=	0x00,
	OCTET_ALIGNED	=	0x01
};

#ifndef L1_WB_R99_ONLY

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8				    hsdschTrChIdentity;
	Bool				    macHsReset;
	UINT8				    numberOfProcesses;
	TrBkSizeTableIndex_te	trBkSizeTableIndex;
	macType_te				macType;
	UINT8					pad[3];
	UINT32			        explicitHarqInfo[MAX_H_PROCESS];
} hsDschDescription_ts;

#endif
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8	transportBlockSizeIndex;
	Bool	hspdschSecondCodeSupport;
	UINT8	pad[2];
}transportBlockSizeList_ts;
#ifndef L1_WB_R99_ONLY

typedef UINT8 hsLessOperation_te;
//ICAT EXPORTED ENUM
enum hsLessOperation_values
{
	HS_SCCH_LESS_DISABLED		=	0x00,
	HS_SCCH_LESS_NEW			=	0x01,
	HS_SCCH_LESS_CONTINUE 		= 	0x02
};


//ICAT EXPORTED STRUCT
typedef struct
{
	hsLessOperation_te 			hsLessOperation;
	UINT8 						hspdschCodeIndex;
	UINT8						numOfTransportBlockSizes;
	UINT8						pad;
	transportBlockSizeList_ts 	transportBlockSizeList[MAX_HSSCCH_LESS_TRBK];

} hsScchLessInformation_ts;




typedef UINT8 cqiFeedbackCycle_te;
//ICAT EXPORTED ENUM
enum cqiFeedbackCycle_values
{
	FEEDBACK_CYCLE_0	= 0x00,
	FEEDBACK_CYCLE_2	= 0x01,
	FEEDBACK_CYCLE_4	= 0x02,
	FEEDBACK_CYCLE_8	= 0x03,
	FEEDBACK_CYCLE_10	= 0x04,
	FEEDBACK_CYCLE_16	= 0x05,
	FEEDBACK_CYCLE_20	= 0x06,
	FEEDBACK_CYCLE_32	= 0x07,
	FEEDBACK_CYCLE_40	= 0x08,
	FEEDBACK_CYCLE_64	= 0x09,
	FEEDBACK_CYCLE_80	= 0x0a,
	FEEDBACK_CYCLE_160	= 0x0b
};


//ICAT EXPORTED STRUCT
typedef struct
{
	INT8	measurementPowerOffset;
	cqiFeedbackCycle_te	cqiFeedbackCycle;
	UINT8	cqiRepetitionFactor;
	UINT8	deltaCqi;
} measurementFeedbackInfo_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16	n;
	BYTE	pad[2];
	UINT8	Data[MAX_H_SSCCH_HS];
} hsScchChannelisationCodeInfo_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16								dlScramblingCode;
	Bool								dlScramblingCodePresent;
	txDiversityMode_te 					txDiversityMode;
	UINT8								numOfDpdch;
	UINT16								dpchFrameOffset;	
	UINT8								closedLoopTimingAdjMode;
	UINT8								pad1[2];
	UINT8								pad2;

	hsScchChannelisationCodeInfo_ts 	hsSCCHChannelisationCodeInfo;
} hsScchConfig_ts;



typedef UINT8 hRntiType_te;
//ICAT EXPORTED ENUM
enum hRntiType_values
{
	COMMON		=	0x00,
	DEDICATED 	=	0x01,
	NO_HRNTI	=	0x02
};

#if defined (L1_UPGRADE_R8)
#if defined (HSDPA_DUAL_CELL)

typedef UINT8 secondaryCellActionType_te;
//ICAT EXPORTED ENUM
enum secondaryCellActionType_values
{
	NO_SC_CONFIGURED = 0x00,
	SETUP_SC		 = 0x01,
	SCC_SC 			 = 0x02,
	RECONFIG_SC		 = 0x03,
	RELEASE_SC		 = 0x04
};
#endif
#endif
#endif
#ifndef	L1_WB_R99_ONLY

//ICAT EXPORTED STRUCT
typedef struct
{
					
	UINT8			maxNumberOfPcchTransmissions;
	UINT8			numberOfTrBkSize;
	UINT8			trBkSizeIndex[MAX_TRBK_SIZE];
	hRntiType_te	hRntiType;
	Bool			bcchSpecificHrntiExists;
	BYTE			pad2[2];
	UINT16			hsPdschChannelisationCode;
	UINT16			bcchSpecificHrnti;
			
} ecfParameters_ts;



//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8 							refChannelizationCode;
	UINT8							deltaAck;
	UINT8 							deltaNack;
	UINT8							ackNackRepetitionFactor;
	UINT8							harqPreambleMode;
	Bool							isServingCellChange;	
	rrcStateIndicator_te			rrcStateIndicator;
	Bool							is64QAMConfigured;
	UINT16							hRnti;
	UINT16							refScramblingCode;
	hsScchConfig_ts 				ScchConfig;
	measurementFeedbackInfo_ts		measurementFeedback;
	ecfParameters_ts				ecfParameters;
#if defined (L1_UPGRADE_R8)
    Bool                            ackNackSupportOnHsDpcch; 
	UINT8							pad3[3];
#endif //(L1_UPGRADE_R8)
} hsScchDescription_ts;

#endif
#if defined (L1_UPGRADE_R8)
typedef UINT8 t321_te;

//ICAT EXPORTED ENUM
typedef enum
{
  T321_100 = 0,
  T321_200,
  T321_400,
  T321_800
}t321_values;

typedef UINT8 cellFachDrxCycle_te;

//ICAT EXPORTED ENUM
typedef enum
{
  ECF_DRX_CYC_4 = 0,
  ECF_DRX_CYC_8,
  ECF_DRX_CYC_16,
  ECF_DRX_CYC_32
}cellFachDrxCycle_values;

typedef UINT8 cellFachDrxBurstLength_te;

//ICAT EXPORTED ENUM
typedef enum
{
  ECF_DRX_BURST_LEN_1 = 0,
  ECF_DRX_BURST_LEN_2,
  ECF_DRX_BURST_LEN_4,
  ECF_DRX_BURST_LEN_8,
  ECF_DRX_BURST_LEN_16
}cellFachDrxBurstLength_values;

//ICAT EXPORTED STRUCT
typedef struct
{
	Bool						isCellFachDrxConfigured;
    t321_te                     t321;
    cellFachDrxCycle_te         cellFachDrxCycle;
    cellFachDrxBurstLength_te   cellFachDrxBurstLength;
	Bool						drxInterruptionByHsdschData;
	UINT8						pad[3];
} cellFachDrxInfo_ts;
#if defined (HSDPA_DUAL_CELL)
//ICAT EXPORTED STRUCT
typedef struct
{
	hsScchChannelisationCodeInfo_ts 	hsScchChannelisationCodeInfo;
	UINT16 								dlUarfcn;	
	UINT16								hRnti;	
	UINT16								cpichScramblingCode;
	UINT16								dlScramblingCode;
	Bool								is64QAMConfigured;
	INT8								measurementPowerOffset;
	txDiversityMode_te					txDiversityMode;
	TrBkSizeTableIndex_te				trBkSizeTableIndex;
	secondaryCellActionType_te			secondaryCellActionType;
	UINT8								pad[3];
} secondaryCellInfo_ts;
#endif
#endif

#ifndef GPLC_ONLY

//ICAT EXPORTED ENUM
typedef enum
{
  ERR_IND_NO_REPORT = 0,
  ERR_IND_CANT_COPY_RX_DATA,
  ERR_IND_INVALID_OOS_REQ,
  ERR_IND_INVALID_REQ_PARAMS, //received request with invalid parameters
  ERR_IND_INVALID_REQ_STATE,  //received request at wrong state
  ERR_IND_INVALID_SET_CM_PARAMS, // in valid parameters received from the set Compressed Mode Command
  ERR_IND_NUM_OF_MEAS_FREQ_OVERFLOW, // in cases where the PS requests to measure to many frequencies
  ERR_IND_FATAL_ERROR,
  ERR_IND_LOW_PRIORITY_WARNING,
  ERR_INVALID_RAT_TERMINATION,
  ERR_WRONG_PLP_STATE,
  ERR_IND_INVALID_PHY_CH_SETUP_REQ,
  ERR_IND_INVALID_RL_RELEASE_REQ
}plwErrInd_e;

#endif

/***********************************************************************
 * definitions for plwCphyPichHsdpaSetupReq
 ***********************************************************************/
#ifndef L1_WB_R99_ONLY

//ICAT EXPORTED STRUCT
typedef struct
{
  hsScchDescription_ts 		hsScchDescription;
  hsDschDescription_ts 		hsDschDescription;
  pichPhyParams_ts			pichPhyParams;	
} pichHsdpaDescription_ts;



/***********************************************************************
 * definitions for plwCphyHsdpaSetupReq
 ***********************************************************************/
//ICAT EXPORTED STRUCT
typedef struct
{
   	activationTime_ts   		activationTime;
	hsScchDescription_ts 		hsScchConfig;
	hsDschDescription_ts		hsDschDescription;
	hsScchLessInformation_ts 	hsScchLessInformation;
#if defined (L1_UPGRADE_R8)
#if defined (HSDPA_DUAL_CELL)
 	secondaryCellInfo_ts		secondaryCellInfo;
#endif
    cellFachDrxInfo_ts          cellFachDrxInfo;
#endif
} 	hsdpaSetupDescription_ts;

/***********************************************************************
 * definitions for plwCphyCpcConfigRequest
 ***********************************************************************/
typedef UINT8 ueDtxCycle1_te;
//ICAT EXPORTED ENUM
enum ueDtxCycle1_values
{
  DTX_CYCLE1_1_SUB_FRAME = 0,
  DTX_CYCLE1_4_SUB_FRAME,
  DTX_CYCLE1_5_SUB_FRAME,
  DTX_CYCLE1_8_SUB_FRAME,
  DTX_CYCLE1_10_SUB_FRAME,
  DTX_CYCLE1_16_SUB_FRAME,
  DTX_CYCLE1_20_SUB_FRAME
};

typedef UINT8 ueDtxCycle2_te;
//ICAT EXPORTED ENUM
enum ueDtxCycle2_values
{
  DTX_CYCLE2_4_SUB_FRAME = 0,
  DTX_CYCLE2_5_SUB_FRAME,
  DTX_CYCLE2_8_SUB_FRAME,
  DTX_CYCLE2_10_SUB_FRAME,
  DTX_CYCLE2_16_SUB_FRAME,
  DTX_CYCLE2_20_SUB_FRAME,
  DTX_CYCLE2_32_SUB_FRAME,
  DTX_CYCLE2_40_SUB_FRAME,
  DTX_CYCLE2_64_SUB_FRAME,
  DTX_CYCLE2_80_SUB_FRAME,
  DTX_CYCLE2_128_SUB_FRAME,
  DTX_CYCLE2_160_SUB_FRAME
};

typedef UINT8 inactivityThresholdForUeDrxCycle_te;
//ICAT EXPORTED ENUM
enum inactivityThresholdForUeDrxCycle_values
{
  INACTIVITY_THRESHOLD_FOR_UE_DRX_CYC_0 = 0,
  INACTIVITY_THRESHOLD_FOR_UE_DRX_CYC_1,
  INACTIVITY_THRESHOLD_FOR_UE_DRX_CYC_2,
  INACTIVITY_THRESHOLD_FOR_UE_DRX_CYC_4,
  INACTIVITY_THRESHOLD_FOR_UE_DRX_CYC_8,
  INACTIVITY_THRESHOLD_FOR_UE_DRX_CYC_16,
  INACTIVITY_THRESHOLD_FOR_UE_DRX_CYC_32,
  INACTIVITY_THRESHOLD_FOR_UE_DRX_CYC_64,
  INACTIVITY_THRESHOLD_FOR_UE_DRX_CYC_128,
  INACTIVITY_THRESHOLD_FOR_UE_DRX_CYC_256,
  INACTIVITY_THRESHOLD_FOR_UE_DRX_CYC_512
};

typedef UINT8 InactivityThresholdForUeDtxcycle2_te;
//ICAT EXPORTED ENUM
enum inactivityThresholdForUeDtxCycle2_values

{
  INACTIVITY_THRESHOLD_FOR_UE_DTX_CYC2_1 = 0,
  INACTIVITY_THRESHOLD_FOR_UE_DTX_CYC2_4,
  INACTIVITY_THRESHOLD_FOR_UE_DTX_CYC2_8,
  INACTIVITY_THRESHOLD_FOR_UE_DTX_CYC2_16,
  INACTIVITY_THRESHOLD_FOR_UE_DTX_CYC2_32,
  INACTIVITY_THRESHOLD_FOR_UE_DTX_CYC2_64,
  INACTIVITY_THRESHOLD_FOR_UE_DTX_CYC2_128,
  INACTIVITY_THRESHOLD_FOR_UE_DTX_CYC2_256
};

typedef UINT8 ueDtxLongPreambleLength_te;
//ICAT EXPORTED ENUM
enum ueDtxLongPreambleLength_values
{
  UE_DTX_LOG_PREAMBLE_LENGTH_THRESHOLD_2 = 0,
  UE_DTX_LOG_PREAMBLE_LENGTH_THRESHOLD_4,
  UE_DTX_LOG_PREAMBLE_LENGTH_THRESHOLD_15
};

typedef UINT8 cqiDtxTimer_te;
//ICAT EXPORTED ENUM
enum cqiDtxTimer_values
{
  CQI_DTX_TIMER_0_SUBFRAMES = 0,
  CQI_DTX_TIMER_1_SUBFRAMES,
  CQI_DTX_TIMER_2_SUBFRAMES,
  CQI_DTX_TIMER_4_SUBFRAMES,
  CQI_DTX_TIMER_8_SUBFRAMES,
  CQI_DTX_TIMER_16_SUBFRAMES,
  CQI_DTX_TIMER_32_SUBFRAMES,
  CQI_DTX_TIMER_64_SUBFRAMES,
  CQI_DTX_TIMER_128_SUBFRAMES,
  CQI_DTX_TIMER_256_SUBFRAMES,
  CQI_DTX_TIMER_512_SUBFRAMES,
  CQI_DTX_TIMER_INFINITY,  
};

typedef UINT8 ueDpcchBurst_te;
//ICAT EXPORTED ENUM
enum ueDpcchBurst_values
{
  DPCCH_BURST_1_SUBFRAME = 0,
  DPCCH_BURST_2_SUBFRAME,
  DPCCH_BURST_5_SUBFRAME
};

typedef UINT8 ueDrxCycle_te;
//ICAT EXPORTED ENUM
enum ueDrxCycle_values
{
  DRX_CYCLE_4 = 0,
  DRX_CYCLE_5,
  DRX_CYCLE_8,
  DRX_CYCLE_10,
  DRX_CYCLE_16,
  DRX_CYCLE_20
};


typedef UINT8 uplinkDpcchSlotFormat_te;
//ICAT EXPORTED ENUM
enum uplinkDpcchSlotFormat_values
{
  SLOT_FORMAT1 = 0,
  SLOT_FORMAT4
};

typedef UINT8 enablingDelay_te;
//ICAT EXPORTED ENUM
enum enablingDelay_values
{
  ENABLING_DELAY0 = 0,
  ENABLING_DELAY1,
  ENABLING_DELAY2,
  ENABLING_DELAY4,
  ENABLING_DELAY8,
  ENABLING_DELAY16,
  ENABLING_DELAY32,
  ENABLING_DELAY64,  
  ENABLING_DELAY128
};

typedef		UINT8       cpcActionType_te;
//ICAT EXPORTED ENUM
enum  cpcActionType_values
{
    CPC_SETUP,
    CPC_RECONFIGURATION,
    CPC_RELEASE
};


//ICAT EXPORTED STRUCT
typedef struct
{

	enablingDelay_te	EnablingDelay;
	UINT8	ueDtxDrxOffset;
} dtxDrxTimingInformation_ts;

//ICAT EXPORTED STRUCT
typedef struct
{

//	UINT8			ttiLength;
	ueDtxCycle1_te	ueDtxCycle1;
	ueDtxCycle2_te	ueDtxCycle2;
	InactivityThresholdForUeDtxcycle2_te	InactivityThresholdForUeDtxcycle2;
//	UINT8	defaultSgInDtxCycle2;
	ueDtxLongPreambleLength_te	ueDtxLongPreambleLength;
	cqiDtxTimer_te	cqiDtxTimer;
	ueDpcchBurst_te	ueDpcchBurst1;
	ueDpcchBurst_te	ueDpcchBurst2;
#ifdef L1_FEATURE_CPC_CRX
	Bool isDrxConfigured;
#endif //#if (L1_FEATURE_CPC_CRX)
	ueDrxCycle_te	ueDrxCycle;
	inactivityThresholdForUeDrxCycle_te	inactivityThresholdForUeDrxCycle;
	Bool	ueDrxGrantMonitoring;
	uplinkDpcchSlotFormat_te	uplinkDpcchSlotFormatInformation;
} dtxDrxInformation_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
   	activationTime_ts   		activationTime;
	cpcActionType_te       cpcActionType;
	dtxDrxInformation_ts 		dtxDrxInformation;
	dtxDrxTimingInformation_ts		dtxDrxTimingInformation;
} cpcParameters_ts;

#endif

//ICAT EXPORTED STRUCT
typedef struct
{
   	plActionType_te     	actionType;
	UINT8 pad;
	UINT16					T319;
} t319Config_ts;
#if	defined (L1_UPGRADE_R8)
typedef struct
{
	UINT8	*macHsData_p;
	Bool	PrimarySecondaryCellInd;// 0 - received on the primary cell,  1 - received on the secondary cell
} hsPointerAssign_ts;
typedef UINT8 Rf64T313StatusType_te;
//ICAT EXPORTED ENUM
enum Rf64T313StatusType_values
{
	RF64_T313_STATUS_STOPPED = 0,		// The T313 timer for the RLS is stopped (the radio link has been restored)
	RF64_T313_STATUS_RUNNING = 1,		// The T313 timer for the RLS has been started
	RF64_T313_STATUS_EXPIRED = 2,		// The T313 timer for the RLS has expired (the radio link has failed)
	RF64_T313_STATUS_UNKNOWN = 0xFF		// The T313 timer is status is invalid or unknown, or this field is not applicable
};

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16					ScramblingCode;		// The scrambling code associated with this radio link
	UINT8					tpcCombinationIndex;// The TPC combination index associated with this radio link. This is used to identify the Radio Link Set (RLS)
	Rf64T313StatusType_te	t313Status;			// The status of the T313 timer associated with this radio link
}Rf64SyncStatusType_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8					numRlSyncStatus;	// Number of radio link sync status structures.  Range: 1 to MAX_NUM_OF_RADIO_LINKS
	UINT8 					pad[3];
	Rf64SyncStatusType_ts	Rf64SyncStatusType[MAX_NUM_OF_RADIO_LINKS];
}Rf64HspaRadioLinkSyncStatusEng_L1_ts;

#endif //#if	defined (L1_UPGRADE_R8)

//add by Qingsong Wang for DualSim, 2010-04-27
//ICAT EXPORTED STRUCT
typedef struct
{
  Bool		  flag;
  Bool        dueToPch;
}resumeCnf_ts;

/*add by jpingma for CQ00017971, 2012-04-16	*/
//ICAT EXPORTED STRUCT
typedef struct
{
  Bool        flag;
}dsPagingFailureInd_ts;

/*add by jpingma for CQ18687, 2012-05-08	*/
typedef struct
{
  Bool        flag;
}dsSuspendInd_ts;
#endif /* PL_W_GLOBS_H */
