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
 * Filename: pl_d_globs.h
 *
 * Description: APLP / GPLC interface for dual RAT features
 **********************************************************************/
#ifndef PL_D_GLOBS_H
#define PL_D_GLOBS_H

#include "cmmn_dfs.h"
#ifdef QUEC_XXXXX
#ifndef GPLC_ONLY
#include "aplp_config.h"
#endif
#endif

#if defined(FULL_SYSTEM)
#include "wb_modem_features.h"
#else
#include "pl_w_modem_features.h"
#endif

#include "pl_w_globs.h"
#define   MAX_GSM_RSSI_MEAS_CELLS         32

#define	PLW_NUM_GSM_CELLS						32
#define	PLW_GSM_UNSUPPORTED_BAND_IND			0xFF
#define	MAX_NUM_OF_BCCH_CELLS					8
#define	GSM_RSSI_SCAN_ARFCN_BMP_SIZE_IN_BITS	1024
#define	GSM_RSSI_SCAN_ARFCN_BMP_SIZE_IN_BYTES	128
#define	PLW_GSM_RSSI_SCAN_ARFCN_BMP_SIZE		128
#define	PLW_GSM_RSSI_SCAN_NUM_REPORTED_CELLS	40
#define	PLW_GSM_MULTI_BCCH_DECODE_NUM_OF_CELLS	40
#define PLW_GSM_BSIC_FAIL_NO_GAP        		0xFE
#define PLW_GSM_INVALID_BSIC            		0xFF
#define PS_STOP_GSM_BCCH_DECODE_CODE            0
#define GSM_BCCH_DECODE_WILD_CARD_ARFCN         0xFFFF
#ifndef WB_BAND_19_SUPPORT
#define PLW_MAX_WB_BANDS_NUMBER					16 //this is for power class number in L1 Capabilities report strcuture
#else
#define PLW_MAX_WB_BANDS_NUMBER					32
#endif
#define PLW_BCCH_DATA_LEN						23//this structure for Bcch decode Ind in WB Idle mode
#define MAX_FDD_UARFCN							3
#define MAX_MEAS_FDD_CELLS						64
#define MAX_REQ_FDD_CELLS						32
#if defined (UPGRADE_PLMS_L1) //CQ70623
#define PLW_PLMS_MAX_NUM_OF_FREQ_IN_LIST    	 32	/**< Maximum number of frequences in RSSI scan list */	
#endif

/* CQ00025629 Upgrade to LTE+WCDMA feature : begin */
#if defined (UPGRADE_LTE)
#define PLW_MAX_FDD_LTE_BANDS_PER_FIND_CELL 	    32
#define PLW_MAX_FDD_LTE_FREQUENCIES_PER_FIND_CELL  9
#define PLW_MAX_LTE_FREQS_IN_PLMN                  16
#define PLW_MAX_LTE_CELLS_PER_FREQ_IN_PLMN         4
#define PLW_BCH_DECODE_DATA_LEN                    32
#define PLW_MAX_FDD_UTRA_FREQ_NUM	    16 // 3 // number of wb frequency allowd to measure while we are LTE
#define PLW_MAX_FDD_UTRA_CELL_NUM	    32
#endif
/* CQ00025629 Upgrade to LTE+WCDMA feature : end */

#ifndef Earfcn
typedef UINT32 Earfcn;
#endif
//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16      arfcn;
  Bool        bandIndicator;
  UINT8       clientBitmap;
}GsmCell_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8       numCells;
  UINT8        pad[3];
  GsmCell_ts cellInfo[PLW_NUM_GSM_CELLS];
}plwGsmCellInfo_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16      arfcn;
  Bool        bandIndicator;
  UINT8       clientBitmap;
  Bool        bsicInfoExist;
  UINT8       expectedBsic;
  UINT8       pad[2];
}GsmBsicCell_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8       numCells;
  UINT8       pad[3];
  GsmBsicCell_ts cellInfo[PLW_NUM_GSM_CELLS];
}plwGsmBsicCellInfo_ts;



//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16	arfcn;
	UINT16	nCellBcchControl; // 0  means stop the bsic/bcch decoding
	Bool	bandIndicator;
	UINT8	pad[3];
}plwGsmMultiArfcnList_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8					numOfArfcns;
	Bool					reportList;
	UINT8					pad[2];
	plwGsmMultiArfcnList_ts	list[PLW_GSM_MULTI_BCCH_DECODE_NUM_OF_CELLS];	
}plwGsmMultiBcchDecodeReq_ts;


// The following structures are used for sending the GSM
// rssi measurement results via binding functions (APLP -> P.S):
//---------------------------------------------------------------

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16      arfcn;
  Bool        bandIndicator;
  UINT8       rxLev;
  UINT8       clientBitmap;
}gsmRssiInfo;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8       numCells;
  UINT8		  pad[3];
  gsmRssiInfo rssiInfo[PLW_NUM_GSM_CELLS];
}plwGsmRssiMeasInd_ts;


// The following structures hold the
// GSM rssi scanning request from the (P.S -> APLP):
//--------------------------------------------------

#define		GSM_RSSI_SCAN_ARFCN_BMP_SIZE_IN_BITS	1024
#define		GSM_RSSI_SCAN_ARFCN_BMP_SIZE_IN_BYTES	128

//For api use:
#define		PLW_GSM_RSSI_SCAN_ARFCN_BMP_SIZE		128

#define		PLW_GSM_RSSI_SCAN_NUM_REPORTED_CELLS	40

typedef		UINT16					plwGsmBandMode_te;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8 list[PLW_GSM_RSSI_SCAN_ARFCN_BMP_SIZE];
}plwGsmArfcnList_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	plwGsmArfcnList_ts   arfcnList;
	plwGsmBandMode_te	  bandMode;
}plwGsmRssiScanReq_ts;


// The following structures are used for sending the GSM
// rssi scanning results via binding functions (APLP -> P.S):
//---------------------------------------------------------------
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16 arfcn;
	INT16 rssi;
}
allCellsMeas_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
	   UINT8   numMeas;
	   UINT8	pad;
	   UINT16  numMeasInAllCells;
       UINT16  arfcn[PLW_GSM_RSSI_SCAN_NUM_REPORTED_CELLS];
       plwGsmBandMode_te  bandMode;
       UINT8   level[PLW_GSM_RSSI_SCAN_NUM_REPORTED_CELLS];
	   allCellsMeas_ts allCellsMeas[PLW_GSM_RSSI_SCAN_ARFCN_BMP_SIZE*8];
}plwGsmRssiScanInd_ts;

// The following structures are used for GSM
// Bsic decoding measurement requests (P.S -> APLP):
//--------------------------------------------------

#define         PLW_GSM_BSIC_FAIL_NO_GAP        0xFE
#define         PLW_GSM_INVALID_BSIC            0xFF

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8       bsic;
  UINT16      arfcn;
  Bool		  bandIndicator;
  UINT8		  clientBitmap;
}plwGsmBsicDecodeInd_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16  arfcn;
	Bool	bandIndicator;
	UINT8	pad;
	UINT16  nCellBcchControl; // if = 0 - means stop the bcch decoding
}plwGsmBcchDecodeReq_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16  arfcn;
	Bool	bandIndicator;
	UINT8	pad;
}plwGsmArfcnInfo_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8				numOfArfcns;
	UINT8				pad[3];
	plwGsmArfcnInfo_ts	arfcnList[PLW_GSM_MULTI_BCCH_DECODE_NUM_OF_CELLS];
}plwGsmMultiBcchDecodeInd_ts;

#if defined (UPGRADE_PLMS_L1) //CQ70623
//ICAT EXPORTED STRUCT
typedef struct
{
	Bool  			   gsmScoreReq;    /**< GSM Scores Request. When TRUE, the RSSI Scan procedure report GSM RSSI on all requested frequencys. */
	Bool 			   wbScoreReq;	   /**< WB Scores Request. When TRUE, the RSSI Scan procedure report WB scores on all requested frequencys. */
	UINT8				   lteScoreReq; 	/**< lteScoreReq[0] - When TRUE, scanning of LTE with BW = 1.4MHz is required.
 
													* If FALSE, scanning is not required. lteScoreReq[5] - When TRUE, scanning of LTE with BW = 20MHz
													   * is required. If FALSE, scanning is not required. */
	UINT8	bandNum;		/**<  Band number, as defined 36.101.
										 *	  In "List Mode" it is per frequency.
										 *	  In "Range Mode" only first entry is used for the entire range. */
	UINT16				frequency;		/**< Frequency represented as 10 x Frequency in MHz. In "Range Mode" - first entry is the start
										 * frequency in MHz and the second entry is the stop frequency in MHz. The start frequency represents
										 * the first frequency for reporting its score in the narrowest scanned BW as requested by lteScoreReq
										 * field. The stop frequency represents the first frequency for reporting it's score in the narrowest
										 * scanned BW as requested by lteScoreReq field.
										 * In "List Mode" - each entry represent the frequency in MHz to be search for */
} plwPlmsRssiScanFreqList_ts;

//ICAT EXPORTED STRUCT
typedef enum
{
	PLW_PLMS_GSM_RAT_PLMS = 0,
	PLW_PLMS_UMTS_RAT,
	PLW_PLMS_EUTRA_RAT,
} plwPlmsRssiScanRat_te_enum;
typedef UINT8 plwPlmsRssiScanRat_te;  

#pragma pack(push, 1)
//ICAT EXPORTED STRUCT
typedef struct PlwLteResultsTableElementTag
{
	UINT16					lteBestScore;		/*Best Score of the Earfcn*/
} PlwLteResultsTableElement_ts;
#pragma pack(pop)

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8 simId;
    UINT8 reserved0;
    UINT8 reserved1;
    UINT8 reserved2;
	plwPlmsRssiScanRat_te  		rat;	/* indicate which RAT request the RssiScanReq */      /*CQ00071284 */
	Bool                       bgInd;													/*Indicates if the RSSI Scan is BG or FG operation.*/
	Bool  			   listIndication; /**< frequency list indication. When TRUE, the frequencys that are need to be scanned are in given by
										 * the list in earfcnList field. When FALSE, the frequencys to be scanned are indicated by startfrq
										 * and endfrq fields. */
	UINT8 				pad1;
	UINT16				numOfFreqs;   /**< In "Range Mode" this number is always 2.
											 In "List Mode" the number represents the number of EARFCNs in the list. Maximum number of EARFCNs is 32.*/
	plwPlmsRssiScanFreqList_ts	   freqList[PLW_PLMS_MAX_NUM_OF_FREQ_IN_LIST];	/** <  In "Range Mode" - first entry is the start frequency in MHz and the second
										 * entry is the stop frequency in MHz. In "List Mode" - each entry represent the frequency in MHz to be search for*/

	PlwLteResultsTableElement_ts	*lteResult_p;		 /**< Lte Pointer to the results in the shared memory  */
	UINT16				*wbResult_p;		 /**< WB Pointer to the results in the shared memory */
	UINT16				*gsmResult_p;	 /**< GSM Pointer to the results in the shared memory */
} plwPlmsRssiScanReq_ts;


//ICAT EXPORTED ENUM
typedef enum
{
	PLW_PLMS_RSSI_SCAN_CNF_NO_ERRORS = 0,
	PLW_PLMS_RSSI_SCAN_CNF_UL1_TIMER_EXPIRED,
	PLW_PLMS_RSSI_SCAN_CNF_INVALID_REQUEST_PARAMS,
	PLW_PLMS_RSSI_SCAN_CNF_INVALID_L1_CONFIGURATION,
	PLW_PLMS_RSSI_SCAN_CNF_AUTO_ABORT_BY_HOST_L1,
} plwRssiScanCnfCompleteStatus_te_enum;
typedef UINT8 plwRssiScanCnfCompleteStatus_te;

//ICAT EXPORTED STRUCT
typedef UINT8 plwPlmsRssiScanAbortCnf_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	//#if defined (UPGRADE_DSDSWB)
	INT8 simId;
    INT8 reserved0;
    INT8 reserved1;
    INT8 reserved2;
	//#endif
    plwRssiScanCnfCompleteStatus_te        completeStatus; /**< RSSI Scan completion status. When TRUE, the RSSI Scan completed successfully. When FASLE, the RSSI Scan failed */
    UINT16		numOfEarfcns;  /**< Number of reported EARFCNs. */
    UINT16		numOfUarfcns;  /**< Number of reported UARFCNs. */
    UINT16		numOfArfcns;  /**< Number of reported ARFCNs. */
} plwPlmsRssiScanCnf_ts;

#endif

/* CQ00025629 jpingma: Upgrade to LTE+WCDMA feature : begin */
#if defined (UPGRADE_LTE)
typedef Earfcn LteARFCN;
typedef struct
{
    /* start of frequency in this band */
    LteARFCN                             minFreqInBand;

    /* end of frequency in this band */
    LteARFCN                             maxFreqInBand;
}
LteBand_ts;

typedef struct 
{
    /* Specifies the number of Cell search with discrete frequency */
    UINT16                               numOfFrequencyCell;

    /** Specifies the downlink frequency on which to find and
      * camp on the cell. */
    LteARFCN                             freqCellList[PLW_MAX_FDD_LTE_FREQUENCIES_PER_FIND_CELL];

    /** Specifies the number of Cell search with frequency Bands.
      */
    UINT16                               numOfBand;

    /** Specifies an array of primary scrambling codes to be used in synchronisation process.
      */
    LteBand_ts                               bandlist[PLW_MAX_FDD_LTE_BANDS_PER_FIND_CELL];
}
plwCphyDrxFindLteCellReq_ts;
typedef UINT8 IratGapOrderType_te;
//ICAT EXPORTED ENUM
enum IratGapOrderType_values
{
  LTE_NCELL_BCH = 0x00,
};

typedef struct
{
   IratGapOrderType_te gapOrder;
}
plwCphyIratGapReq_ts;
typedef struct
{
   Bool   gapReady;
   UINT16 gapTimer;
}
plwCphyIratGapInd_ts;

typedef struct
{
	UINT16   reserved;
}
plwCphyIratGapStopReq_ts;


typedef struct
{
	Bool   requestGap;/*TRUE: request gap agian; FALSE: need not gap*/
}
plwCphyIratGapStopCnf_ts;


typedef UINT16 Lte_PhysicalCellIdentity;

//ICAT EXPORTED STRUCT
typedef struct
{
    Lte_PhysicalCellIdentity         physicalCellIdentity;

    /** 1 dB steps from 0(-141dBm) to 97(-44 dBm).    */
    UINT16                                rSRP;

    /** 1/2 dB steps from 0(-20dB) to 34(-3 dB).    */
    UINT16                                rSRQ;
    //Added by xqshi to align
    UINT8                                  padding[2];
	//Added end
}
plwULteCellReport_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
    LteARFCN                             earfcn;

    UINT16                               numberOfCells;
	//added by xqshi to 32bit align

    UINT8                                padding[2];
	//Added by xqshi to 32bit align  end

    plwULteCellReport_ts                 detectCellResult[PLW_MAX_LTE_CELLS_PER_FREQ_IN_PLMN];
}
plwULteFreqCellList_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
    /** Indicates if the physical layer has detected one or more cells on the
     * requested frequency.
     */
    Bool                                cellDetected;

    UINT8                                numOfFrequencies;
		//added by xqshi to 32bit align

    UINT8                                padding[2];
	//Added by xqshi to 32bit align


    plwULteFreqCellList_ts               freqCellList[PLW_MAX_LTE_FREQS_IN_PLMN];
}
plwCphyDrxFindLteCellCnf_ts;

typedef struct
{
	//The SFN number when the BCH is received
    UINT16    sfn;
    UINT16    scramblingcode;
    //Frequency
    UINT16    utraArfcn;
    //CRC result, value range: TRUE: OK, FALSE:NOK
    Bool  crcResult;
    //True means that L1 fails to read this bch in the allocated GAP
    Bool  gapEnd;
    //Length of the BCH payload
    UINT16    length;
    //Pointer to the BCH payload
    UINT8     data[PLW_BCH_DECODE_DATA_LEN]; 
} plwEwiUtranBchDecodeInd_ts;


/* EcphyUtranCellParams_ts */
//ICAT EXPORTED STRUCT
typedef struct 
{
	UINT16     ScramblingCode;  /* Primary scrambling code */
} EcphyUtranCellParams_ts;


/* EcphyUtranUarfcnParams_ts */
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16 Uarfcn;
	UINT16 numPrimaryScramblingCodes;  /* Max 32.  If numOfCells is 0, only RSSI will be reported for each frequency in uarfcnList */
	EcphyUtranCellParams_ts utraCellParams[PLW_MAX_FDD_UTRA_CELL_NUM]; /*LTE_MAX_FDD_UTRA_CELL_NUM is 32 */
} EcphyUtranUarfcnParams_ts;

/* EcphyUtranCellMeasReq_ts */
//ICAT EXPORTED STRUCT
typedef struct 
{
	UINT8 measSyncId; 
	UINT8 numOfUarfcn; /* Number of frequencies in uarfcnList array. If numOfUarfcn is 0, L1 will stop measurements reports */
	UINT8 highPriorityBitmap[2];
	EcphyUtranUarfcnParams_ts utraFddElement[PLW_MAX_FDD_UTRA_FREQ_NUM]; /* LTE_MAX_FDD_UTRA_FREQ_NUM  is 3 */
} plwEwiMonitorFddUtraCellReq_ts;

typedef struct
{
   	UINT16 uarfcn;
	UINT16 scramblingCode; 
	UINT8  sttdInd;//harde code 0
}plwEwiStartBch_ts;
#endif
/* CQ00025639 htfeng : Upgrade to LTE+WCDMA feature : begin */
#if defined (UPGRADE_LTE)

//ICAT EXPORTED STRUCT
typedef struct
{
  Earfcn      earfcn;

  /* From RRC ASN definition: UEUTRA_MeasurementBandwidth
     *  0 - MeasurementBandwidth_mbw6,
     *  1 - MeasurementBandwidth_mbw15,
     *  2 - MeasurementBandwidth_mbw25,
     *  3 - MeasurementBandwidth_mbw50,
     *  4 - MeasurementBandwidth_mbw75,
     *  5 - MeasurementBandwidth_mbw100
     */
  UINT8       measBandwidth;
  UINT8       pad[3];
}LteFreq_ts;

#define PLW_NUM_LTE_FREQS 8 //Same as maxNumEUTRAFreqs in CphyLteCellInfoReq
//ICAT EXPORTED STRUCT
typedef struct
{
  /** Indicates uniquely the identifier of this measurement request and is
   * only an internal reference used by RRC to tie up measurement requests
   * with measurement reports.
   * This is NOT the same as the measurement identity that is used on the
   * air interface.
   */
  UINT8        measurementIdentity;

  /** Indicates a bit mask to define the RSCP measurement required
   * for the corresponding freqs.
   */
  UINT8        Rsrp;
  /** Indicates a bit mask to define the RSCQ measurement required
   * for the corresponding freqs.
   */
  UINT8        Rsrq;
  /** high Priority or not for the freq in bitmask Rsrp||Rsrq */
  Bool         isHighPrioLayers;
  UINT8        numberOfFreqs;
  UINT8        pad[3];
  LteFreq_ts   lteFreq[PLW_NUM_LTE_FREQS];
}plwCphyMonitorLteCellReq_ts;

#define PLW_NUM_LTE_CELLS 8 //Same as maxEUTRACellPerFreq in CphyMonitorLteCellInd

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16        physicalCellIdentity;

    /** 1 dB steps from 0(-141dBm) to 97(-44 dBm).    */
    INT16         rSRP;

    /** 1/2 dB steps from 0(-20dB) to 34(-3 dB).    */
    INT16         rSRQ;
	//added by xqshi to align

    UINT8                                padding[2];
	//Added by xqshi to align
}
LteCellReport;

//ICAT EXPORTED STRUCT
typedef struct
{
  Earfcn          earfcn; //HTFENG_TBD
  Bool		      rSRPPresent;
  Bool		      rSRQPresent;

  UINT16          numberOfCells;
  //Modified by xqshi to align 32bit
  //UINT8		      pad[2];
  //modified end
  LteCellReport   lteCellMeasdata[PLW_NUM_LTE_CELLS];
}LteFreqReport;



//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8          measureIdentity; //HTFENG_TBD
  UINT8          numberOfFreqs;
  UINT8		     pad[2];

  LteFreqReport  lteFreqReport[PLW_NUM_LTE_FREQS];
}plwCphyMonitorLteCellInd_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  Earfcn          earfcn;
  UINT16          numberOfCells;
   //Added by xqshi to align 
  UINT8    padding[2];
  //Added end 
  LteCellReport   lteCellMeasdata[PLW_NUM_LTE_CELLS];
}LteFreqResultReport;


//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8     simID;
  UINT8		numberOfFreqs;
  UINT8		measType;
  //Added by xqshi to align 
  UINT8    padding;
  //Added end 

  LteFreqResultReport  LteFreqResultReport[PLW_NUM_LTE_FREQS];
}LteMeasPlmnResult_ts;


#endif /* #if defined (UPGRADE_LTE)  */
/* CQ00025629 Upgrade to LTE+WCDMA feature : end */



//-------------------------------------------------------------
// The following structure is used for L1 Capabilities report
//-------------------------------------------------------------
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT32					   supportedRfBands;                // a bitmap of the supported RF bands
	UINT8                      powerClass[PLW_MAX_WB_BANDS_NUMBER];	// UE Power Class per Band
	UINT8                      numOfBandCom;
	UINT8                      Reserved;     
	UINT8                      bandComList[16];
} l1WcdmaCapabilityReportInd_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
  	UINT16   arfcn;
  	Bool  bandIndicator;
	UINT8	 frame[PLW_BCCH_DATA_LEN];
	UINT16	 subChannel;
	Bool 	 crcCheckResult;
	#if defined (ENABLE_NETWORK_SCAN_REPORT)     // CQ131828 by wpan
    UINT8    bsic;
	#endif
} plwGsmBcchDecodeInd_ts;

typedef UINT8 GsmBcchDecodeErrCode_te; 
//ICAT EXPORTED ENUM 
enum GsmBcchDecodeErrCode_values 
{ 
  GSM_BCCH_DECODE_FAILED = 0x00, 
  GSM_BCCH_SHORT_DRX_CYCLE = 0x01, 
  GSM_BCCH_REACHED_MAX_TRIALS = 0x02 
}; 

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16   arfcn;
    Bool     bandIndicator;
	GsmBcchDecodeErrCode_te errorCode; 
} plwGsmBcchDecodeErrorInd_ts;


/* plgUtranCellParams */

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16 ScramblingCode;  /* Primary scrambling code */
	sttdInd_te sttdInd;	/* STTD indicator TS: 25.331: 10.3.6.78 */
} plgUtranCellParams_ts;


/* plgUtranUarfcnParams */
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16 Uarfcn;
	UINT16 numPrimaryScramblingCodes;  /* Max 32.  If numOfCells is 0, only RSSI will be reported for each frequency in uarfcnList */
	plgUtranCellParams_ts utraCellParams[MAX_REQ_FDD_CELLS]; /*MAX_REQ_FDD_CELLS is 32 */
} plgUtranUarfcnParams_ts;


/* plgUtranCellMeasReq */
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8 measurementId;  /*  Integer that will be reported with the measurement indication (0255) */
	UINT8 numOfUarfcn; /* Number of frequencies in uarfcnList array. If numOfUarfcn is 0, L1 will stop measurements reports (03) */
	Bool fddCellsHavePriority;/* Not supported */
	plgUtranUarfcnParams_ts utraFddElement [MAX_FDD_UARFCN]; /* MAX_FDD_UARFCN is 3 */
} plgUtranCellMeasReq_ts;


/* plgUtranCellMeasIndParams_ts */
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8 dlUarfcnIndex; /*  Index to uarfcnList entry representing the downlink UARFCN i.e. index to the fddRxLev array 0..2*/
	UINT16 scramblingCode; /*  Primary scrambling code */
	INT16 cpichEcNo;  /* In 1/8 dB units(-320  0)  */
	INT16 cpichRscp; /* In 1/8 dBm units. (-1336  0) */
} plgUtranCellMeasIndParams_ts;


/* plgUtranRxLev_ts */
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT16 uarfcn;   // (016383) RF channel number
	INT16  rssiInd;  // (-1016  0)  In 1/8 dBm units
} plgUtranRxLev_ts;


/* plgUtranCellMeasInd */
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8 measurementId; /* Integer that will be reported with the measurement indication. Zero is reserved for internal use. (0255) */
	UINT8 numOfCells; /* Number of cells in utraCellParams array. (064) */
	UINT8 numOfUarfcn; /* Number of frequencies in uarfcnList array(, 13) */
	plgUtranRxLev_ts fddRxLev[MAX_FDD_UARFCN]; /* MAX_FDD_UARFCN is 3, See ?4.3.21.2 */
	plgUtranCellMeasIndParams_ts fddCellMeas[MAX_MEAS_FDD_CELLS]; /* MAX_MEAS_FDD_CELLS is 64, See ?4.6.12.2 */
} plgUtranCellMeasInd_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8                   numOfFreqs;
  BYTE                    pad[3];
  plgUtranRxLev_ts        freqList[RF_SCAN_MAX_FREQS];
}plgUtranRssiMeasInd_ts;


/*
** SIGNAL plgUtranRssiScanReq_ts
**
** This signal is recieved during GSM for UTRAN rssi scan request
*/

//ICAT EXPORTED STRUCT
typedef  struct
{
  UINT8         startStopInd;
  UINT8         actionType;
  UINT8         numOfFreqs;
  UINT8         freqScanMode;
  Bool			runInFastMode;
  UINT8 		pad[3];
  UINT16        freqList[RF_SCAN_MAX_FREQS];
}plgUtranRssiScanReq_ts;

/*
** SIGNAL UmphRssiScanReq
**
** This signal is recieved during GSM for UTRAN rssi scan measure
*/
typedef plgUtranRssiScanReq_ts UmphRssiScanReq;

/** SIGNAL plgUtranRssiScanInd_ts
**
** This signal is sent during GSM for UTRAN rssi scan measure
*/
typedef freqScanInd_ts plgUtranRssiScanInd_ts;


/** SIGNAL UmphRssiScanInd
**
** This signal is sent during GSM for UTRAN rssi scan measure
*/
typedef plgUtranRssiScanInd_ts UmphRssiScanInd;


/*
** SIGNAL plgUtranRssiMeasReq_ts
**
** This signal is recieved during GSM for UTRAN rssi meas request
*/
//ICAT EXPORTED STRUCT
typedef  struct
{
  UINT8         startStopInd;
  UINT8         actionType;
  UINT8         numOfFreqs;
  UINT8         freqScanMode;
  Bool			runInFastMode;
  UINT8 		pad[3];
  UINT16        freqList[RF_SCAN_MAX_FREQS];
}plgUtranRssiMeasReq_ts;

/*
** SIGNAL UmphRssiMeasReq
**
** This signal is recieved during GSM for UTRAN rssi scan measure
*/
typedef plgUtranRssiMeasReq_ts UmphRssiMeasReq;
/** SIGNAL UmphRssiMeasInd
**
** This signal is sent during GSM for UTRAN rssi scan measure
*/
typedef plgUtranRssiMeasInd_ts UmphRssiMeasInd;

/*
** SIGNAL UmphCellMeasReq
**
** This signal is recieved during GSM for UTRAN cell search
*/
typedef plgUtranCellMeasReq_ts UmphCellMeasReq;
/** SIGNAL UmphCellMeasInd
**
** This signal is sent during GSM for UTRAN cell search
*/
typedef plgUtranCellMeasInd_ts UmphCellMeasInd;



/** SIGNAL UmphDetectedCellMeasInd
**
** This signal is sent during GSM for UTRAN cell search
*/
typedef interFreqCellMeasInd_ts UmphDetectedCellMeasInd;



/*
** SIGNAL UmphCellMeasReq
**
** This signal is recieved during GSM for UTRAN cell search
*/
typedef plDetectedCellMeas_ts UmphDetectedCellMeasReq;

#ifdef L1_WIFI_LOCATION
//Definition for WIFI location feature

#define MAX_BSSID_NUM_TOTAL        30
#define SIZE_MAC_ADDRESS          6
#define MAX_BSSID_NUM_TOTAL_BK     MAX_BSSID_NUM_TOTAL*MAX_SCAN_CNT_CMD
#define MAX_SCAN_CNT_CMD           3
////CQ00143839
#define ALLOW_WIFI_FAILURE_REPORT     (1)


//ICAT EXPORTED ENUM
typedef enum  {
	reason_stop =0,
	reason_start
}ScanReqReason_te;

#if 0
//ICAT EXPORTED STRUCT
typedef struct{
    ScanReqReason_te reason;
}fgiWifiScanCnf_ts;
#endif

//ICAT EXPORTED STRUCT
typedef struct{
  UINT8 bssid[SIZE_MAC_ADDRESS];
  UINT8 padding[2];
  INT32 rssi;
  UINT32 channel_number; //
}channelCellInfo_ts;
////CQ00143839
#ifdef ALLOW_WIFI_FAILURE_REPORT
//ICAT EXPORTED STRUCT
typedef enum
{
  NULL_FAILURE =0,
  FAILURE_DUAL_SIM_CAMP =1,
  FAILURE_SERVICE_ONGOING =2,
  FAILURE_SERVICE_ONGOING_NOT_ENTER_IDLE =6,
  FAILURE_NOT_ENTER_IDLE =4,
  FAILURE_DSP_NOT_SUPPORT = 8,
}wifi_failure_cause_te;
#endif

//ICAT EXPORTED STRUCT
typedef struct{
	
    UINT8              bssid_number;
    channelCellInfo_ts channelCellList[MAX_BSSID_NUM_TOTAL];
	//////CQ00143839
    #ifdef ALLOW_WIFI_FAILURE_REPORT
    wifi_failure_cause_te  wifi_failure_cause;
    UINT8   pad1[3];
    #endif
}WFScanInd_ts;
//CQ00143530
//ICAT EXPORTED STRUCT
typedef struct{
	
    UINT8              bssid_number;
    channelCellInfo_ts channelCellList[MAX_BSSID_NUM_TOTAL];

}WFScanIndPLP_ts;


//ICAT EXPORTED STRUCT
typedef struct{
	
    UINT8              bssid_number;
    channelCellInfo_ts channelCellList[MAX_BSSID_NUM_TOTAL_BK];
    //scanRestult_te scanRestult;
     UINT32  WifiScanReportTime;
}WFScanIndBk_ts;





#endif




//Definition for WIFI location feature end



#endif /* PL_D_GLOBS_H */
