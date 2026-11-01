//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\stubs.ppp
//PPL Source File Name : W:\\3g_ps\\dps\\src\\stubs.c
typedef unsigned char BOOL ;
typedef unsigned char UINT8 ;
typedef unsigned short UINT16 ;
typedef unsigned long UINT32 ;
typedef char CHAR ;
typedef signed char INT8 ;
typedef signed short INT16 ;
typedef signed long INT32 ;
typedef unsigned char Bool ;
typedef UINT8 BYTE ;
typedef UINT8 UBYTE ;
typedef UINT16 UWORD ;
typedef UINT16 WORD ;
typedef INT16 SWORD ;
typedef UINT32 DWORD ;
typedef unsigned long long UINT64 ;
typedef void* VOID_PTR ;
typedef volatile UINT8 *V_UINT8_PTR ;
typedef volatile UINT16 *V_UINT16_PTR ;
typedef volatile UINT32 *V_UINT32_PTR ;
typedef unsigned int U32Bits ;
typedef BOOL BOOLEAN ;
typedef const char * SwVersion ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 aplpQDepth ;	 
 UINT32 aplpStackSize ;	 
 UINT32 aplpTaskPriority ;	 
 UINT32 aplpHighQDepth ;	 
 UINT32 aplpHighStackSize ;	 
 UINT32 aplpHighTaskPriority ;	 
 } aplpConfigParams_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 DISABLE_L1C_FEATURE = 0 ,	 
 ENABLE_L1C_FEATURE = 1	 
 } l1FeatureEnable_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 l1FeatureEnable_ts enableSleep ;	 
 l1FeatureEnable_ts SleepAlike ;	 
 l1FeatureEnable_ts enableExtendedTracing ;	 
 l1FeatureEnable_ts periodicDetected ;	 
 } featuresParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 l1FeatureEnable_ts RESERVED1 ;	 
 l1FeatureEnable_ts RESERVED2 ;	 
 l1FeatureEnable_ts AnritsuSetup ;	 
 l1FeatureEnable_ts RESERVED4 ;	 
 l1FeatureEnable_ts frameToDiag ;	 
 l1FeatureEnable_ts RESERVED6 ;	 
 l1FeatureEnable_ts RESERVED7 ;	 
 l1FeatureEnable_ts RESERVED8 ;	 
 } featuresUnderDevelopment_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 long dpchMaxInitPower [ 5 ] ;	 
 long dpchMinInitPower ;	 
 long dpchMaxPowerLevel [ 5 ] ;	 
 long prachMaxInitPower [ 5 ] ;	 
 long prachMinInitPower ;	 
 long prachMaxPowerLevel [ 5 ] ;	 
 UINT32 numFramesToWakePccpchSkip ;	 
 } MS_configParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 Qin ;	 
 UINT16 Qout ;	 
 } dataPkg_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 maxPccpchShifts ;	 
 UINT8 maxTmUpdtB4DummyTracker ;	 
 UINT8 tccInterrupt0Offset ;	 
 UINT8 tccInterrupt1Offset ;	 
 } tccTmPkg_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 NORMAL_MODE = 0 , // handle COM_WARNING as warnings , COM_ERROR and DSP_EXCEPTION as errors	 
 ALL_ERRORS = 1 , // handle all as errors	 
 ALL_WARNINGS = 2 , // handle all as warnings	 
 LISTEN_TO_DSP= 3 , // handle according to DSP message ( bit indicating treatment way )	 
 TRACE_N_CONTINUE = 4 // send trace to ICAT and do nothing	 
 } L1ErrHandleMode_e;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 L1ErrHandleMode_e plpErrHandleMode ;	 
 L1ErrHandleMode_e aplpErrHandleMode ;	 
 l1FeatureEnable_ts enablePlwErrIndToPs ;	 
 UINT8 pad ;	 
 } L1_ErrorHandlerConfig_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 aplpConfigParams_ts aplpConfigParams ;	 
 featuresParams_ts featuresParams ;	 
 MS_configParams_ts MS_configParams ;	 
 dataPkg_ts dataPackageParams ;	 
 tccTmPkg_ts tccTmPkgParams ;	 
 featuresUnderDevelopment_ts developmentSwitch ;	 
 L1_ErrorHandlerConfig_ts l1ErrHandler ;	 
 } l1cNvm_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 rxDataFormat [ 2 ] ;	 
 } dlDataReportFormat_ts;

typedef UINT8 processValidity_te ;
//ICAT EXPORTED ENUM 
 enum processValidity_values 
 {	 
 PARAS_AND_DATA_ARE_INVALID = 0x00 , // Init state or state after L1 reset	 
 PARAS_IS_VALID = 0x01 , // Indicate UMAC has finished parameters calculate ( like Etfci etc )	 
 PARAS_AND_DATA_IS_VALID = 0x02 // Indicate UMAC has finished E-TFCI selection and DTC data transfer	 
 };

typedef UINT8 processState_te ;
//ICAT EXPORTED ENUM 
 enum processState_values 
 {	 
 DTX = 0x00 ,	 
 INITIAL_TRANSMISSION = 0x01 ,	 
 RETRANSMISSION = 0x02 ,	 
 CLEAR= 0xFF	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8* txDataPtr ; // Pointer to the data to be transmitted	 
 UINT16 trBkSize ; // 0 means that there are no bits to be transmitted	 
 processValidity_te processValidity ; // Invalid , Valid	 
 UINT8 cfn ; // 0 ..255	 
 UINT8 subFrame ; // 0 ..4 , N / A in TTI 10 ms	 
 processState_te processState ;	 
 UINT8 rsn ;	 
 UINT8 happyBit ;	 
 UINT8 deltaHarq ; // 0 ..6 , denotes power offset from the HARQ profile of the relevant MAC-d flow	 
 UINT8 etfci ; // 0 ..127	 
 // CPC parameters	 
 UINT8 startLongPreamble ; // 0 - FALSE , 1 - TRUE	 
 UINT8 preambleEndCfn ; // 0 , 1 ...255	 
 UINT8 preambleEndSf ; // 0 , 1 ...4	 
 UINT8 includesScheduledDataTransmission ; // 0 - FALSE , 1 - TRUE	 
 UINT8 MONITOR_GRANTS ; // 0 - FALSE , 1 - TRUE	 
	 
	 
	 
	 
	 
 } plwPhyEdchTtiInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 macePduTrBkMem2ms ;	 
 UINT8 pad [ 3 ] ;	 
 } macePduTrBkMem2ms_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 macePduTrBkMem10ms ;	 
 UINT8 pad [ 3 ] ;	 
 } macePduTrBkMem10ms_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 etfcRestrictionResult [ ( 7 ) ] ;	 
 UINT8 pad ;	 
 } etfcRestrictionDspResults;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 initialCfn ; // This address will contain the CFN that the current MAC-e interrupt is synchronizing.	 
 // It is used by MAC to synchronize it ' s internal CFN to the DSP CFN.	 
 UINT8 UPH ; // UE Power Headroom	 
 UINT8 etfcRestrictionControl ;	 
 // CPC parameters	 
 UINT8 MAC_DTX_Enabled ; // 0 - Disabled , 1 - Enabled	 
 UINT8 DTX_CYCLE1_2 ; // bit0 ( LSB ) : 0 - Cycle1 , 1 - Cycle2	 
 // bit1: Validity on bit0	 
 UINT8 Reset_MAC_Timers ; // 0 - FALSE , 1 - TRUE	 
 UINT8 CPC_MACE_TX_MISS_INDICATION ; // 0 - Mac-e did not miss 1 ms thereshold , 1 - Mac-e missed 1 ms threshold	 
 } edchSharedMemGeneralParameters_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 // stores the results of Leref , m* ( Bed , m ) ^2	 
 UINT32 leRefMultBedSquare [ ( 8 ) ] ; // ( With Q0 )	 
 // for extrapolation stores the results of Keref , m / ( Leref , m* ( Bed , m ) ^2 )	 
 // for interpolation stores the results of ( Keref , m+1 - Keref , m ) / ( Leref , m+1* ( Bed , m+1 ) ^2 - Leref , m* ( Bed , m ) ^2 )	 
 UINT32 ratioValue [ ( 8 ) ] ;	 
 UINT8 ratioQ [ ( 8 ) ] ;	 
 UINT8 maxValidEtfci [ 8 ] ;	 
 } etfcRestrictionControl_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 plwPhyEdchTtiInfo_ts * edchTtiTxParametersAddr ; // TX data for this TTI	 
 dlDataReportFormat_ts * edch2msTtiRxParametersAddr [ ( 8 ) ] ; // RX data per Process	 
 dlDataReportFormat_ts * edch10msTtiRxParametersAddr [ ( 4 ) ] ; // RX data per Process	 
 UINT8 * tti2msMacEPduAddr [ ( 8 ) ] ; // address of the MAC-e PDUs for TTI 2 ms configuration	 
 UINT8 * tti10msMacEPduAddr [ ( 4 ) ] ; // address of the MAC-e PDUs for TTI 10 ms configuration	 
 etfcRestrictionControl_ts * edchEtfcRestrictionControlAddr ;	 
 etfcRestrictionDspResults * etfcRestrictionResultsAddr ; // ETFC restriction results	 
 edchSharedMemGeneralParameters_ts * edchSharedMemGeneralParametersAddr ; // Pointer to structure containing general paramets	 
 } edchSharedMemAddrInd_ts;

typedef UINT32 Earfcn ;
typedef UINT8 plActionType_te ;
//ICAT EXPORTED ENUM 
 enum plActionType_values 
 {	 
 ACTION_TYPE_START = 0x00 ,	 
 ACTION_TYPE_STOP = 0x01	 
 };

typedef UINT8 plFreqScanType_te ;
//ICAT EXPORTED ENUM 
 enum plFreqScanType_values 
 {	 
 RF_SCAN_LIST = 0x00 ,	 
 RF_SCAN_RANGE = 0x01 ,	 
 RF_SCAN_FFT = 0x02	 
 };

typedef UINT8 sttdInd_te ;
//ICAT EXPORTED ENUM 
 enum sttdInd_values 
 {	 
 STTD_OFF = 0x00 ,	 
 STTD_ON = 0x01	 
 };

typedef UINT8 sfnMeasAction_te ;
//ICAT EXPORTED ENUM 
 enum sfnMeasAction_values 
 {	 
 NO_MEASUREMENTS = 0x00 ,	 
 SFN_SFN_MEAS_TYPE1 = 0x01 ,	 
 SFN_SFN_MEAS_TYPE2 = 0x02 ,	 
 SFN_CFN_MEASUREMENT = 0x03	 
 };

typedef UINT8 plCctrchId_te ;
//ICAT EXPORTED ENUM 
 enum plCctrchId_values 
 {	 
 CCTRCH_ID_DPCH = 0x00 ,	 
 CCTRCH_ID_PDSCH = 0x01	 
 };

typedef UINT8 plFreqScanMode_te ;
//ICAT EXPORTED ENUM 
 enum plFreqScanMode_values 
 {	 
 FG_FREQ_SCAN = 0x00 ,	 
 BG_FREQ_SCAN = 0x01	 
 };

typedef UINT8 plIntraMeasOnRachReportType_te ;
//ICAT EXPORTED ENUM 
 enum plIntraMeasOnRachReport_values 
 {	 
 REPORT_IMMEDIATLY = 0x00 ,	 
 REPORT_SERVING = 0x01 ,	 
 SERVING_1_BEST_NEIGHBOUR = 0x02 ,	 
 SERVING_2_BEST_NEIGHBOUR = 0x03 ,	 
 SERVING_3_BEST_NEIGHBOUR = 0x04 ,	 
 SERVING_4_BEST_NEIGHBOUR = 0x05 ,	 
 SERVING_5_BEST_NEIGHBOUR = 0x06 ,	 
 SERVING_6_BEST_NEIGHBOUR = 0x07	 
 };

typedef UINT8 measReportingMethod_te ;
//ICAT EXPORTED ENUM 
 enum measReportingMethod_values 
 {	 
 PERIODICAL_REPORTING = 0x00 ,	 
 EVENT_TRIGGERED_REPORTING = 0x01	 
 };

typedef UINT8 plBlerChReqNum_te ;
//ICAT EXPORTED ENUM 
 enum plBlerChReqNum_values 
 {	 
 TRCH_BLER_FIRST_REQ = 0x00 ,	 
 TRCH_BLER_SECOND_REQ = 0x01	 
 };

typedef UINT8 gsmCellMeasIndTypes_te ;
//ICAT EXPORTED ENUM 
 enum gsmCellMeasIndTypes_values 
 {	 
 RSSI_ONLY = 0x00 ,	 
 RSSI_AND_TIME_DIFF = 0x01	 
 };

typedef UINT8 refTimeDiffToCellAccuracy_te ;
//ICAT EXPORTED ENUM 
 enum refTimeDiffToCellAccuracy_values 
 {	 
 TIME_DIFF_ACCURACY_40 = 0x00 ,	 
 TIME_DIFF_ACCURACY_256 = 0x01 ,	 
 TIME_DIFF_ACCURACY_2560 = 0x02	 
 };

typedef UINT8 txSlotStatus_te ;
//ICAT EXPORTED ENUM 
 enum txSlotStatus_values 
 {	 
 TRANSMITTER_OPEN = 0x01 ,	 
 TRANSMITTER_CLOSED_CM = 0x02 ,	 
 TRANSMITTER_CLOSED_OUT_OF_SYNC = 0x03 ,	 
 TRANSMITTER_OPEN_AT_MIN_PWR = 0x04 ,	 
 TRANSMITTER_OPEN_AT_MAX_PWR = 0x05	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 uarfcn ; /* ( 0 ?6383 ) RF channel number */	 
 INT8 rssiInd ; /* ( -120? ) dBm measured RSSI */	 
 BYTE pad1 ;	 
 INT16 scoreInd ;	 
 BYTE pad2 [ 2 ] ;	 
 } utraFreqRxLevel_ts;

typedef UINT8 freqScanErrCode_te ;
//ICAT EXPORTED ENUM 
 enum freqScanErrCode_values 
 {	 
 FREQ_SCAN_OK = 0x00 ,	 
 FREQ_SCAN_FG_WRONG_MODE = 0x01 ,	 
 FREQ_SCAN_BG_WRONG_MODE = 0x02 ,	 
 FREQ_SCAN_UNDEFINED_MODE = 0x03	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 numOfFreqs ;	 
 BYTE pad ;	 
 freqScanErrCode_te refusalCode ;	 
 utraFreqRxLevel_ts freqList [ 352 ] ;	 
 } freqScanInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 plActionType_te startStopInd ;	 
 plFreqScanType_te actionType ;	 
 UINT8 numOfFreqs ;	 
 plFreqScanMode_te freqScanMode ;	 
 Bool runInFastMode ;	 
 UINT8 pad [ 3 ] ;	 
 UINT16 freqList [ 32 ] ;	 
 } freqScanList_ts;

typedef UINT8 cellMeasIndTypes_te ;
//ICAT EXPORTED ENUM 
 enum cellMeasIndTypes_values 
 {	 
 ENERGY_ONLY = 0x01 ,	 
 ENERGY_SFN_SFN = 0x03 ,	 
 ENERGY_SFN_CFN = 0x05 ,	 
 ENERGY_DETECTED_CELL = 0x08 ,	 
 PENDING_MEASUREMENT = 0x09 ,	 
 CELL_NOT_FOUND = 0x0A ,	 
 INTRA_DETECTED_CELL = 0x0D ,	 
	 
 INTRA_TM_CELL = 0x0E ,	 
	 
 INDICATION_TYPE_MASK = 0x0F	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 dlPriScramblingCode ;	 
 INT16 cpichEcNo ;	 
 INT16 cpichRscp ;	 
 INT16 utraRssi ;	 
 UINT16 sfnMeas ;	 
 UINT16 sfnOrCfnServ ;	 
 UINT16 chipOffset ;	 
 Bool frameInfoPresent ;	 
 UINT8 clientBitmap ;	 
 cellMeasIndTypes_te indicationTypes ;	 
 BYTE pad [ 3 ] ; // will be used for debug pad [ 1 ] = dbCellIndex ; pad [ 2 ] = PathInfoIndex ; pad [ 3 ] = XfnSfnInfoIndex	 
 } monCellInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 dlUarfcn ;	 
 UINT8 numOfCells ;	 
 UINT8 numOfPendingCells ;	 
 UINT8 numOfCellsNotFound ;	 
 BYTE pad [ 3 ] ;	 
 monCellInd_ts cellList [ 32 ] ;	 
 } interFreqCellMeasInd_ts;

typedef UINT8 detectedReportingMode_te ;
//ICAT EXPORTED ENUM 
 enum detectedReportingMode_values 
 {	 
 ONE_SHOT = 0x00 , // not used	 
 PERIODIC_REPORT = 0x01 , // pyin detect@Dch , APLP will change DetectedDb.DetectedMeasModeState to DETECTED_MEAS_MODE_IN_PERIODIC	 
 STOP_FIRST_FOUND = 0x02 , // pyin BG / FG PLMN search , APLP will set DetectedDb.bRunUntilFound	 
 REPORT_MORE_CELLS = 0x03 // not used	 
 };

typedef UINT8 setWbMode_te ;
//ICAT EXPORTED ENUM 
 enum setWbMode_values 
 {	 
 WB_INIT = 0x00 ,	 
 SET_WB_TO_PCCPCH = 0x01 ,	 
 SET_WB_TO_DCH = 0x02 ,	 
 SET_WB_TO_DETECTED = 0x03 ,	 
 SET_WB_TRANSITION_FAILURE = 0x04	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 clientBitmap ;	 
 Bool initialMode ;	 
 UINT8 numOfDlUarfcns ;	 
 detectedReportingMode_te reportMode ;	 
 UINT16 dlUarfcn [ 100 ] ;	 
 Bool shortAcquisition ; // pyin not used	 
 Bool includeRRCRequestedCells ;	 
	 
 Bool longBgSearch ; // pyin not used	 
 BYTE pad [ 1 ] ;	 
	 
	 
	 
 } plDetectedCellMeas_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 refTimeDiffToCellAccuracy_te refTimeDiffToCellAccuracy ;	 
 BYTE pad ;	 
 UINT16 refTimeDiff ;	 
 } refTimeDiffToServCell_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 clientBitmap ;	 
 sttdInd_te sttdInd ;	 
 UINT16 dlPriScramblingCode ;	 
 sfnMeasAction_te sfnTimeDiffMeasAction ;	 
 Bool sfnDecodedByL1 ;	 
 Bool refTimeDiffToServCellUsed ;	 
 BYTE pad ;	 
 refTimeDiffToServCell_ts refTimeDiffToServCell ;	 
 } plMonCellInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 dlUarfcn ;	 
 sttdInd_te sttdInd ;	 
 Bool refTimeDiffToServCellUsed ;	 
 UINT16 dlPriScramblingCode ;	 
 BYTE pad2 [ 2 ] ;	 
 refTimeDiffToServCell_ts refTimeDiffToServCell ;	 
 } cellInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfCells ;	 
 BYTE pad [ 3 ] ;	 
 cellInfo_ts cellList [ 42 ] ;	 
 } cellinfoList_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfCells ;	 
 Bool sfnSfnMeasInDrxDisable ;	 
 UINT16 dlUarfcn ;	 
 UINT8 detectedCellsClientBitmap ;	 
	 
 Bool reportTmCells ;	 
 UINT8 pad [ 1 ] ;	 
	 
	 
	 
 Bool renewMode ;	 
 plMonCellInfo_ts cellList [ 42 ] ;	 
 } plIntraFreqCellMeas_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfCells ;	 
	 
	 
	 
 BYTE pad ;	 
	 
 UINT16 dlUarfcn ;	 
 plMonCellInfo_ts cellList [ 32 ] ;	 
 } plInterFreqCellMeas_ts;

typedef UINT8 cellLockRat_te ;
//ICAT EXPORTED ENUM 
 enum cellLockRat_values 
 {	 
 CELL_LOCK_ON_WB_RAT = 0x00 ,	 
 CELL_LOCK_ON_GSM_RAT = 0x01 ,	 
 CELL_LOCK_ON_LTE_RAT = 0x02 ,	 
 CELL_LOCK_ON_NR_RAT = 0x03	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Bool enableCellLock ;	 
 UINT8 band ;	 
 cellLockRat_te cellLockRat ;	 
 UINT8 pad ;	 
 Earfcn ARFCN ;	 
 UINT16 scrCode ;	 
 } plCellLockMeas_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 plActionType_te actionType ;	 
 UINT8 trchID ; /* 0 ...31 */	 
 plBlerChReqNum_te trchRequestNum ; /* TRCH_BLER_FIRST_REQ or TRCH_BLER_SECOND_REQ */	 
 plCctrchId_te cctrchId ;	 
 measReportingMethod_te reportingMethod ;	 
 BYTE pad [ 3 ] ;	 
 UINT16 numOfTotalCrc ; /* 1 ...512 */	 
 UINT16 numOfBadCrc ; /* 1 ...512 */	 
 UINT16 pendingAfterTrigger ; /* 1 ...512 */	 
 UINT16 timePeriod ; /* 10 ...64000 */	 
 } qualMeas_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfElements ;	 
 BYTE pad [ 3 ] ;	 
 qualMeas_ts qualMeas [ 16 ] ;	 
 } plTrchBlerMeas_ts;

typedef UINT8 reportContent_te ;
//ICAT EXPORTED ENUM 
 enum reportContent_values 
 {	 
 NON_DRX_IND = 0 ,	 
 ALL_MEASURED_CELLS = 1 ,	 
 SERVING_CELL_ONLY = 2	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfCells ;	 
 UINT8 numOfPendingCells ;	 
 UINT8 numOfCellsNotFound ;	 
	 
 reportContent_te reportContent ;	 
	 
	 
	 
 monCellInd_ts cellList [ 42 ] ;	 
 UINT8 slotFormat ;	 
 INT8 tx_power ;	 
 UINT16 padding ;	 
	 
 } intraFreqCellMeasInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfCells ;	 
 BYTE pad1 [ 3 ] ;	 
 UINT16 dlUarfcn [ 7 ] ;	 
 BYTE pad2 [ 2 ] ;	 
 monCellInd_ts cellList [ 7 ] ;	 
 } uarfcnMeasOnRachIntra_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfCells ;	 
 BYTE pad [ 3 ] ;	 
 UINT16 dlUarfcn [ 2 ] ;	 
 monCellInd_ts cellList [ 2 ] ;	 
 } uarfcnMeasOnRachInter_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 uarfcnMeasOnRachIntra_ts intraCellsOnRach ;	 
 uarfcnMeasOnRachInter_ts interCellsOnRach ;	 
 } cellMeasIndOnRach_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 dlUarfcn ;	 
 UINT16 dlPriScramblingCode ;	 
 } measuredCellInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfCells ;	 
 BYTE pad [ 3 ] ;	 
 measuredCellInfo_ts cellList [ 32 ] ;	 
 } measuredCellsInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 BOOL LastInDrx ;	 
 UINT32 TimeForNextLteInd ;	 
 } endOfDrxMeasurementInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 trchId ;	 
 plBlerChReqNum_te trchRequestNum ; /* TRCH_BLER_FIRST_REQ or TRCH_BLER_SECOND_REQ */	 
 plCctrchId_te cctrchId ;	 
 measReportingMethod_te reportingMethod ;	 
 INT8 blerLogInd ;	 
 BYTE pad [ 3 ] ;	 
 UINT16 numOfTotalCrc ;	 
 UINT16 numOfBadCrc ;	 
 } qualMeasList_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfElements ;	 
 BYTE pad [ 3 ] ;	 
 qualMeasList_ts qualMeasList [ 16 ] ;	 
 } trchBlerInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 txPower [ 15 ] ;	 
 UINT16 txMaxPower [ 15 ] ;	 
 BYTE pad1 ;	 
 txSlotStatus_te slotStatus [ 15 ] ;	 
 BYTE pad2 ;	 
 } txPowInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 scramblingCode ;	 
 UINT16 rlRxTxTimeDiff ;	 
 } rlRxTxDiff_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfRls ;	 
 BYTE pad [ 3 ] ;	 
 rlRxTxDiff_ts rlRxTxDiff [ 6 ] ;	 
 } ueRxTxTimeDiffInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Bool immediateActivation ;	 
 BYTE pad ;	 
 UINT16 activationTimeNum ;	 
 } activationTime_ts;

typedef UINT8 trChType_te ;
//ICAT EXPORTED ENUM 
 enum trChType_values 
 {	 
 TRCH_TYPE_BCH = 0x00 ,	 
 TRCH_TYPE_PCH = 0x01 ,	 
 RESERVED_TRCH_TYPE = 0x02 ,	 
 TRCH_TYPE_FACH = 0x03 ,	 
 TRCH_TYPE_DSCH = 0x04 ,	 
 TRCH_TYPE_RACH = 0x05 ,	 
 TRCH_TYPE_DCH_UL = 0x06 ,	 
 TRCH_TYPE_DCH_DL = 0x07 ,	 
 TRCH_TYPE_FACH_FOR_CBS = 0x08 ,	 
 TRCH_TYPE_HSDSCH = 0x09	 
	 
 };

typedef UINT8 tti_te ;
//ICAT EXPORTED ENUM 
 enum tti_values 
 {	 
 TTI_2 = 2 ,	 
	 
 TTI_10 = 10 ,	 
 TTI_20 = 20 ,	 
 TTI_40 = 40 ,	 
 TTI_80 = 80	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfTrCh ;	 
 UINT8 trChId [ 16 ] ;	 
 trChType_te trChType [ 16 ] ;	 
 BYTE pad [ 3 ] ;	 
 } trChList_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfTfc ;	 
 UINT8 numOfTrch ;	 
 BYTE pad [ 2 ] ;	 
 UINT8 *tfcsTable ;	 
 } tfcs_ts;

typedef UINT8 signalledFactors_te ;
//ICAT EXPORTED ENUM 
 enum signalledFactors_values 
 {	 
 SIGNALLED = 0x00 ,	 
 REF_AND_SIGNALLED = 0x01 ,	 
 REFERENCE = 0x02	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 signalledFactors_te signalledFactors ;	 
 UINT8 betaC ;	 
 UINT8 betaD ;	 
 UINT8 refId ;	 
 INT8 deltaPpm ;	 
 BYTE pad [ 3 ] ;	 
 } powerOffsetParams_ts;

typedef UINT8 typeOfChCoding_te ;
//ICAT EXPORTED ENUM 
 enum typeOfChCoding_values 
 {	 
 CONVOLUTIONAL_CODING = 0x00 ,	 
 TURBO_CODING = 0x01 ,	 
 NO_CODING = 0x02	 
 };

typedef UINT8 codingRate_te ;
//ICAT EXPORTED ENUM 
 enum codingRate_values 
 {	 
 CODING_RATE_HALF = 0x00 ,	 
 CODING_RATE_ONE_THIRD = 0x01	 
 };

typedef UINT8 crcSize_te ;
//ICAT EXPORTED ENUM 
 enum crcSize_values 
 {	 
 NO_CRC = 0x00 ,	 
 CRC_SIZE_8 = 0x01 ,	 
 CRC_SIZE_12 = 0x02 ,	 
 CRC_SIZE_16 = 0x03 ,	 
 CRC_SIZE_24 = 0x04	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 tti_te trChTti ;	 
 typeOfChCoding_te typeOFChannelCoding ;	 
 codingRate_te codingRate ;	 
 BYTE pad ;	 
 UINT16 rateMatchingAttribute ;	 
 crcSize_te crcSize ;	 
 INT8 dchBlerQualTarget ;	 
 } trChSemiStatic_ts;

typedef UINT8 rachMsgLength_te ;
//ICAT EXPORTED ENUM 
 enum rachMsgLength_values 
 {	 
 RACH_MSG_LENGTH_10_MS = 10 ,	 
 RACH_MSG_LENGTH_20_MS = 20	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 transportBlockSize ;	 
 UINT8 numOfTransportBlocks ;	 
 rachMsgLength_te rachMsgLength ;	 
 } trChDynamic_ts;

typedef UINT8 trChActionType_te ;
//ICAT EXPORTED ENUM 
 enum trChActionType_values 
 {	 
 TRCH_ADD = 0x01 ,	 
 TRCH_ACTION_RESERVED1 = 0x02 ,	 
 TRCH_ACTION_RESERVED2 = 0x03	 
 };

typedef UINT8 reconfFlag_te ;
//ICAT EXPORTED ENUM 
 enum reconfFlag_values 
 {	 
 TRCH_NO_RECONFIG = 0x00 ,	 
 RECONFIG_WO_SYNC_PROC_A = 0x01	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 trChId ;	 
 trChType_te trChType ;	 
 Bool reportFlag ;	 
 trChActionType_te actionType ;	 
 UINT8 numOfDynamic ;	 
 BYTE pad [ 3 ] ;	 
 trChDynamic_ts dynamicPart [ 64 ] ;	 
 trChSemiStatic_ts semiStaticPart ;	 
 } trChDescription_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
	 
	 
	 
 tfcs_ts dlTfcs ;	 
 tfcs_ts ulTfcs ;	 
 powerOffsetParams_ts *powerOffTab ;	 
 UINT8 numOfTrch ;	 
 reconfFlag_te reconfInd ;	 
 BYTE pad [ 2 ] ;	 
 trChDescription_ts *trCh [ 16 ] ;	 
	 
	 
 Bool trchCfgExistence ;	 
 BYTE pad2 [ 3 ] ;	 
	 
 } trchConfigDescription_ts;

typedef UINT8 phyChType_te ;
//ICAT EXPORTED ENUM 
 enum phyChType_values 
 {	 
 PHY_CH_P_CCPCH = 0x00 , // Must be the first	 
 PHY_CH_S_CCPCH = 0x01 ,	 
 PHY_CH_AICH_PRACH = 0x02 ,	 
 PHY_CH_PICH_S_CCPCH = 0x03 ,	 
 PHY_CH_CBS_S_CCPCH = 0x04 ,	 
 PHY_CH_DPCH = 0x05 ,	 
	 
 PHY_CH_ALL = 0x08 ,	 
	 
	 
	 
	 
	 
 PHY_CH_NONE = 0x0F	 
 };

typedef UINT8 fixFlexPosition_te ;
//ICAT EXPORTED ENUM 
 enum fixFlexPosition_values 
 {	 
 FFP_FIXED = 0x00 ,	 
 FFP_FLEXIBLE = 0x01	 
 };

typedef UINT8 pccpchMode_te ;
//ICAT EXPORTED ENUM 
 enum pccpchMode_values 
 {	 
 RESERVED_PCCPCH_MODE = 0x00 ,	 
 SERVING_CELL_WOUT_SFN_UPDATE = 0x01 ,	 
 SERVING_CELL_W_SFN_UPDATE = 0x02 ,	 
 MONITORING_NEIGHBOR_CELL = 0x03 ,	 
 MONITORING_FOR_BETTER_PLMN_SEARCH = 0x04 ,	 
 MONITORING_LOW_PRIOPRITY_INDCH = 0x05	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 activationTime_ts activationTime ;	 
 pccpchMode_te pccpchMode ;	 
 BYTE pad1 ;	 
 UINT16 dlUarfcn ;	 
 UINT16 ulUarfcn ;	 
 sttdInd_te sttdInd ;	 
 BYTE pad2 ;	 
 UINT16 dlPriScramblingCode ;	 
 BYTE pad3 [ 2 ] ;	 
 } pccpchDescription_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 scramblingCode ;	 
 sttdInd_te sttdInd ;	 
 BYTE pad1 ;	 
 UINT16 spreadingFactor ;	 
 UINT8 chanCodeNum ;	 
 Bool pilotSymbolExistence ;	 
 Bool tfciExistence ;	 
 fixFlexPosition_te fixFlexPosition ;	 
 UINT16 timingOffset ;	 
 } sccpchPhyParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 activationTime_ts activationTime ;	 
 tti_te maxTtiOverThePhyCh ;	 
 BYTE pad [ 3 ] ;	 
 sccpchPhyParams_ts sccpchPhyParams ;	 
	 
 trchConfigDescription_ts trchDescription ;	 
	 
 } sccpchDescription_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 plActionType_te actionType ;	 
 UINT8 fachMeasurementCycle ;	 
 UINT16 fachMeasOccasionCrnti ;	 
 tti_te maxTti ;	 
 BYTE pad [ 3 ] ;	 
 } fachOccasionInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 cbsFrameOffset ;	 
 BYTE pad1 ;	 
 UINT16 cbsOccasionPeriod ;	 
 UINT16 cbsSmOccasionPeriod ;	 
 UINT16 pad2 ;	 
 } ctchOccasionInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 sccpchPhyParams_ts sccpchPhyParams ;	 
 ctchOccasionInfo_ts ctchOccasionInfo ;	 
	 
 trchConfigDescription_ts trchDescription ;	 
	 
	 
 } sccpchCbsDescription_ts;

typedef UINT8 cbsL2ActionType_te ;
//ICAT EXPORTED ENUM 
 enum plCbsL2ActionTyp_values 
 {	 
 CBS_L2_ACTION_TYPE_STOP = 0x00 ,	 
 CBS_L2_ACTION_TYPE_START = 0x01 ,	 
 CBS_L2_ACTION_TYPE_MODIFY = 0x02	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 periodId ;	 
	 
	 
	 
	 
 UINT8 pad [ 3 ] ;	 
	 
 UINT8 rxPeriodOffset [ 256 ] ;	 
 UINT16 numOfRxPeriods ;	 
 UINT16 NumOfBSInSchedulingPeriod ;	 
 UINT16 referenceSfn ;	 
 UINT16 NextPeriodOffset ;	 
 } cbsLevel2Scheduling_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 drxCycleLengthCoeff ;	 
 UINT8 drxCycleLengthCoeff2 ;	 
 BYTE pad [ 3 ] ;	 
 UINT8 pagingInd ;	 
 UINT16 pagingOccasion ;	 
 UINT16 pagingOccasion2 ; // CQ52043	 
 } pagingInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 scramblingCode ;	 
 UINT8 channelizationCode ;	 
 sttdInd_te sttdInd ;	 
 INT8 pichPowerOff ;	 
 UINT8 numOfPiPerFrame ;	 
 BYTE pad [ 2 ] ;	 
 pagingInfo_ts pagingInfo ;	 
 } pichPhyParams_ts;

typedef UINT8 rrcStateIndicator_te ;
//ICAT EXPORTED ENUM 
 enum rrcStateIndicator_values 
 {	 
 RRC_IDLE = 0x00 ,	 
 CELL_PCH = 0x01 ,	 
 URA_PCH = 0x02 ,	 
 CELL_FACH = 0x03 ,	 
 CELL_DCH = 0x04	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 pichPhyParams_ts pichPhyParams ;	 
 sccpchPhyParams_ts sccpchPhyParams ;	 
	 
 trchConfigDescription_ts trchDescription ;	 
	 
 } pichAndSccpchDescription_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 scramblingCode ;	 
 UINT16 spreadingFactor ;	 
 UINT8 puncturingLimit ;	 
 INT16 txInitPower ;	 
 UINT8 powerRampStep ;	 
 UINT8 preambMaxRetransNum ;	 
 UINT8 numOfAsc ;	 
 UINT16 availableSignature [ 8 ] ;	 
 UINT16 availableSubChannelNum [ 8 ] ;	 
 INT8 maxUlTxPower ;	 
	 
	 
	 
	 
	 
 UINT16 pad1 ;	 
 UINT8 pad [ 3 ] ;	 
	 
	 
 } prachPhyParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 scramblingCode ;	 
 UINT8 channelizationCode ;	 
 sttdInd_te sttdInd ;	 
 UINT8 aichTxTiming ;	 
 INT8 aichPowerOffset ;	 
 BYTE pad [ 2 ] ;	 
	 
	 
	 
	 
	 
 Bool pad2 ;	 
 UINT8 pad3 [ 3 ] ;	 
	 
	 
 } aichPhyParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 prachPhyParams_ts prachPhyParams ;	 
 aichPhyParams_ts aichPhyParams ;	 
	 
 trchConfigDescription_ts trchDescription ;	 
	 
	 
	 
	 
	 
	 
	 
 UINT8 pad2 ;	 
 UINT8 pad3 [ 3 ] ;	 
	 
	 
	 
 } prachAichDescription_ts;

typedef UINT8 ssdtCodeWordSet_te ;
//ICAT EXPORTED ENUM 
 enum ssdtCodeWordSet_values 
 {	 
 SSDT_LONG = 0x00 ,	 
 SSDT_MEDIUM = 0x01 ,	 
 SSDT_SHORT = 0x02 ,	 
 SSDT_OFF = 0x03	 
 };

typedef UINT8 ssdtCellIdentity_te ;
//ICAT EXPORTED ENUM 
 enum ssdtCellIdentity_values 
 {	 
 SSDT_CELL_ID_LABEL_A = 0x00 ,	 
 SSDT_CELL_ID_LABEL_B = 0x01 ,	 
 SSDT_CELL_ID_LABEL_C = 0x02 ,	 
 SSDT_CELL_ID_LABEL_D = 0x03 ,	 
 SSDT_CELL_ID_LABEL_E = 0x04 ,	 
 SSDT_CELL_ID_LABEL_F = 0x05 ,	 
 SSDT_CELL_ID_LABEL_G = 0x06 ,	 
 SSDT_CELL_ID_LABEL_H = 0x07 ,	 
 SSDT_OMITTED = 0x08	 
 };

typedef UINT8 txDiversityMode_te ;
//ICAT EXPORTED ENUM 
 enum txDiversityMode_values 
 {	 
 TX_DM_NO_DIVERSITY = 0x00 ,	 
 TX_DM_STTD = 0x01 ,	 
 TX_DM_CLOSED_LOOP_MODE1 = 0x02 ,	 
 TX_DM_CLOSED_LOOP_MODE_2 = 0x03 ,	 
 TX_DM_INVALID_DIVERSITY = 0xff	 
 };

typedef UINT8 pcAlgorithm_te ;
//ICAT EXPORTED ENUM 
 enum plAlgorithm_values 
 {	 
 PCA_ALGORITHM_1 = 0x00 ,	 
 PCA_ALGORITHM_2 = 0x01	 
 };

typedef UINT8 dpchTimingInd_te ;
//ICAT EXPORTED ENUM 
 enum dpchTimingInd_values 
 {	 
 TI_INITIALIZE = 0x00 ,	 
 TI_MAINTAIN = 0x01 ,	 
 TI_DPCH_ESTABLISHMENT = 0x02 ,	 
 TI_SHO = 0x03 ,	 
 TI_RECONFIGURATION = 0x04 ,	 
 TI_INTER_RAT_HHO = 0x05 ,	 
 TI_3G_HHO_FAILURE = 0x06 ,	 
 TI_DPCH_EST_DIFF_CELL = 0x07 ,	 
 TI_RECONFIGURATION_FAILURE = 0x08	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 INT8 maxUlTxPower ;	 
 BYTE pad1 ;	 
 INT16 dpcchPowerOffset ;	 
 UINT8 pcPreambles ;	 
 UINT8 pcAlgorithm ;	 
 UINT8 tpcStepSize ;	 
 BYTE pad2 ;	 
	 
 } dpchUlPowerControl_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 dpchUlPowerControl_ts dpchUlPowerControl ;	 
 UINT32 dpchUlScrCode ;	 
 UINT16 ulSpreadingFactor ; // min SF used in DCH 25.331000 10.300000 .6.88	 
 Bool tfciExist ;	 
 UINT8 numOfFbiBits ;	 
 UINT8 puncturingLimit ;	 
 UINT8 numOfDpdch ;	 
 UINT8 numOfTpcBits ;	 
 BYTE pad ;	 
	 
 } dpchUlRlParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 dpchDlChanCode ;	 
 Bool alternateScrCode ;	 
 UINT16 dpchDlScrCode ;	 
 } dpchMultiCode_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 plActionType_te actionType ;	 
 BYTE pad1 ;	 
 UINT16 rlId ;	 
 UINT16 phaseRefScrCode ;	 
 UINT8 phaseRefChanCode ;	 
 BYTE pad2 ;	 
 UINT16 dpchFrameOffset ;	 
 UINT8 numOfDlChanCodes ;	 
 UINT8 pad4 ;	 
 dpchMultiCode_ts dpchMultiCode [ 3 ] ;	 
 UINT8 tpcCombinationIndex ; // RLs with same index have same TPC and E-HICH value , range [ 0 , 5 ] . Among these RLs , TPC or HICH can be combined	 
	 
 ssdtCellIdentity_te ssdtCellIdentity ;	 
	 
	 
	 
 txDiversityMode_te txDiversityMode ;	 
 Bool tfci2TransmitInd ; // always false	 
 BYTE pad5 ;	 
	 
 Bool usedForPdsch ;	 
	 
	 
	 
 UINT8 closedLoopTimingAdjMode ;	 
 UINT8 fdpchSlotFormat ; // should always be 0 for RELEASE 6 // FDPCH symbol index 0 ~9 fdpchSymbIdx = fdpchSlotFormat == 9 ? 0 : fdpchSlotFormat + 1 ;	 
	 
 } dpchDlRlParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 dpchTimingInd_te timingInd ;	 
 UINT8 dpcMode ;	 
 UINT16 spreadingFactor ;	 
 UINT8 numOfPilotBits ;	 
 fixFlexPosition_te fixFlexPosition ;	 
 Bool tfciExist ;	 
 UINT8 sField ;	 
 Bool postVerificationPeriod ;	 
 UINT8 powerOffsetPpilotDpdch ;	 
 UINT8 tpcCommandErrRateTarget ; // ( 1 ..10 ) Real Range: 0.010000 ..0.1 by steps of 0.010000	 
 Bool TimingMaintainedSynchronizationIndicator ;	 
 UINT32 defaultDPCHOffsetValue ;	 
 } dpchCommonDlParams_ts;

typedef UINT8 plwPhyChConfigValidity_te ;
//ICAT EXPORTED ENUM 
 enum plwPhyChConfigValidity_values 
 {	 
 PLW_DPCH_DATA_EXISTENCE_BIT = 0x01 ,	 
 PLW_HSDPA_DATA_EXISTENCE_BIT = 0x02 ,	 
 PLW_HSUPA_DATA_EXISTENCE_BIT = 0x04 ,	 
 PLW_CPC_DATA_EXISTENCE_BIT = 0x08	 
	 
	 
	 
	 
 };

typedef UINT8 edchActionType_te ;
//ICAT EXPORTED ENUM 
 enum edchActionType_values 
 {	 
 SETUP_EDCH ,	 
 RECONFIGURATION ,	 
 ACTIVE_SET_UPDATE	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 referenceEtfci ;	 
 UINT8 referenceEtfciPowerOffset ;	 
 UINT8 pad [ 2 ] ;	 
 } referenceEtfci_ts;

typedef UINT8 harqRvConfiguration_te ;
//ICAT EXPORTED ENUM 
 enum harqRvConfiguration_values 
 {	 
 RV0 ,	 
 RVTABLE	 
 };

typedef UINT8 maxChanCodes_te ;
//ICAT EXPORTED ENUM 
 enum maxChanCodes_values 
 {	 
 SF256 ,	 
 SF128 ,	 
 SF64 ,	 
 SF32 ,	 
 SF16 ,	 
 SF8 ,	 
 SF4 ,	 
 TWO_SF4 ,	 
 TWO_SF2 ,	 
 TWO_SF2_AND_TWO_SF4	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 etfciBoost ;	 
 UINT8 deltaT2TP ;	 
 UINT8 pad [ 2 ] ;	 
 } etfcBoostInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfRefEtfci ;	 
 referenceEtfci_ts referenceEtfci [ 8 ] ;	 
	 
 UINT8 pad [ 1 ] ;	 
 Bool etfciTableIndex ;	 
 UINT8 macdFlowPowerOffsets ;	 
 harqRvConfiguration_te harqRvConfig ;	 
 maxChanCodes_te maximumChannelisationCodes ;	 
 UINT8 plNonMax ;	 
 UINT8 edpcchDpcchPowerOffset ;	 
	 
	 
 etfcBoostInfo_ts etfcBoostInfo ;	 
 Bool edpdchPowerInterpolation ;	 
 UINT8 pad2 [ 2 ] ;	 
	 
	 
	 
 Bool is16QAMConfigured ;	 
 UINT8 pad3 [ 3 ] ;	 
	 
	 
	 
 } edchUlParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 pad [ 3 ] ;	 
 UINT8 agchChannelisationCode ;	 
 } agchParameters_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 pad [ 2 ] ;	 
 UINT8 channelisationCode ;	 
 UINT8 signatureSequence ;	 
 } hichParameters_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 pad [ 2 ] ;	 
 UINT8 signatureSequence ;	 
 UINT8 combinationIndex ;	 
 } rgchParameters_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Bool servingRadioLinkIndicator ;	 
 UINT8 tpcCombinationIndex ;	 
 UINT16 dlScramblingCode ;	 
 hichParameters_ts hich ;	 
 UINT8 pad [ 3 ] ;	 
 Bool rgchActivatedOnThisRl ;	 
 rgchParameters_ts rgch ;	 
 txDiversityMode_te txDiversityMode ;	 
 UINT16 dpchFrameOffset ;	 
 } edchDlParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 activationTime_ts activationTime ;	 
 UINT8 pad1 [ 3 ] ;	 
 edchActionType_te edchActionType ;	 
 edchUlParams_ts edchUlRlParams ;	 
 agchParameters_ts agch ;	 
 UINT8 pad2 [ 1 ] ;	 
 UINT8 numOfDpdch ;	 
 UINT8 ttiSize ;	 
 UINT8 numOfDlRl ;	 
 edchDlParams_ts edchDlRlParams [ 4 ] ;	 
 UINT16 erntiPrimary ;	 
 UINT16 erntiSecondary ;	 
	 
 } edchDescription_ts;

typedef UINT8 OutOfSyncCause_te ;
//ICAT EXPORTED ENUM 
 enum OutOfSyncCause_values 
 {	 
 /** OutOfSync because of failure to establish physical channels. */	 
 PLW_PHYS_CHAN_ESTABLISH_FAILURE = 0 ,	 
	 
 /** OutOfSync because of Radio Link failure. */	 
 PLW_RADIO_LINK_FAILURE = 1	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /** Constant used in CELL_DCH channel establishment. */	 
 INT16 n_312 ;	 
 /** Constant used in determining a Radio Link failure. */	 
 UINT8 n_313 ;	 
 /** Constant used in determining a Radio Link failure. */	 
 INT16 n_315 ;	 
 /** Timer used in CELL_DCH channel establishment. */	 
 INT8 t_312 ;	 
 /** Timer used in determining a Radio Link failure. */	 
 INT8 t_313 ;	 
 BYTE pad ;	 
 } 
 SyncParameters_ts;

//ICAT EXPORTED STRUCT 
 typedef struct SyncParametersConnectedTag 
 {	 
 /** Constant used in CELL_DCH channel establishment. */	 
 INT16 n_312 ;	 
 /** Timer used in CELL_DCH channel establishment. */	 
 INT8 t_312 ;	 
 BYTE pad ;	 
 } 
 SyncParamsConnected_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 activationTime_ts activationTime ;	 
 tti_te maxTtiOverThePhyCh ;	 
 Bool enableLegacySyncInd ;	 
 UINT16 dlUarfcn ;	 
 UINT16 ulUarfcn ;	 
 BYTE pad2 [ 2 ] ;	 
 dpchCommonDlParams_ts dpchDlCommonParams ;	 
 UINT8 numOfRL ;	 
 Bool onlyOneCsRb ; // CQ96577	 
 BYTE pad3 [ 2 ] ;	 
 dpchDlRlParams_ts dpchDlRlParams [ 12 ] ;	 
 dpchUlRlParams_ts dpchUlRlParams ;	 
 UINT8 pad4 [ 2 ] ;	 
 Bool fdpchEnabled ;	 
 plwPhyChConfigValidity_te phyChConfigValidity ;	 
	 
 SyncParameters_ts SyncParams ;	 
 SyncParamsConnected_ts SyncParamsConnected ;	 
	 
	 
	 
	 
	 
 UINT8 pad6 [ 4 ] ;	 
	 
	 
 trchConfigDescription_ts trchDescription ;	 
	 
	 
 } dpchDescription_ts;

typedef UINT8 phyChReleaseReason_te ;
//ICAT EXPORTED ENUM 
 enum phyChReleaseReason_values 
 {	 
 CH_RR_INTER_FR_HHO = 0x00 ,	 
 CH_RR_INTRA_FR_HHO = 0x01 ,	 
 CH_RR_INTER_RAT_HHO = 0x02 ,	 
 CH_RR_INTER_FR_RESELECT = 0x03 ,	 
 CH_RR_INTRA_FR_RESELECT = 0x04 ,	 
 CH_RR_NORMAL = 0x05 ,	 
 CH_RR_RESERVED = 0x06 ,	 
 CH_RR_INTER_RAT_RESELECTION = 0x07 ,	 
 CH_RR_HSDSCH_SERVING_CELL_CHANGE = 0x08	 
	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 activationTime_ts activationTime ;	 
 phyChType_te phyChType ;	 
 phyChReleaseReason_te releaseReason ;	 
 plwPhyChConfigValidity_te phyChConfigValidity ;	 
 BYTE padding ;	 
 } rlReleaseDescription_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 dpchUlPowerControl_ts dpchUlPowerControl ;	 
 UINT32 dpchUlScrCode ;	 
 UINT16 ulSpreadingFactor ;	 
 Bool tfciExist ;	 
 UINT8 numOfFbiBits ;	 
 UINT8 puncturingLimit ;	 
 UINT8 numOfDpdch ;	 
 UINT8 numOfTpcBits ;	 
 BYTE pad ;	 
 } dpchModifyUlParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 rlID ;	 
 UINT16 phaseRefScrCode ;	 
 UINT8 numOfDlChanCodes ;	 
 UINT8 phaseRefChanCode ;	 
 UINT16 dpchFrameOffset ;	 
	 
 UINT8 tpcCombinationIndex ;	 
	 
 ssdtCellIdentity_te ssdtCellIdentity ;	 
	 
	 
	 
 dpchMultiCode_ts dpchMultiCode [ 3 ] ;	 
 txDiversityMode_te txDiversityMode ;	 
 Bool tfci2TransmitInd ;	 
 UINT8 closedLoopTimingAdjMode ;	 
 UINT8 fdpchSlotFormat ; // should always be 0 for RELEASE 6	 
	 
 } dpchModifyDlParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 dpcMode ;	 
 BYTE pad1 ;	 
 UINT16 spreadingFactor ;	 
 UINT8 numOfPilotBits ;	 
 fixFlexPosition_te fixFlexPosition ;	 
 Bool tfciExist ;	 
 UINT8 sField ;	 
	 
 ssdtCodeWordSet_te ssdtCodeWordSet ;	 
	 
	 
	 
 UINT8 powerOffsetPpilotDpdch ;	 
 UINT8 tpcCommandErrRateTarget ; // ( 1 ..10 ) Real Range: 0.010000 ..0.1 by steps of 0.010000	 
 UINT8 pad3 [ 1 ] ;	 
	 
 } dpchModifyCommonDlParams_ts;

typedef UINT8 dpchModifyControl_te ;
//ICAT EXPORTED ENUM 
 enum dpchModifyControl_values 
 {	 
 DL_DPCH_MODIFY = 0x00 ,	 
 UL_DPCH_MODIFY = 0x01 ,	 
 UL_AND_DL_DPCH_MODIFY = 0x02	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 activationTime_ts activationTime ;	 
 dpchModifyCommonDlParams_ts dpchCommonParams ;	 
 dpchModifyControl_te dpchModifyControl ;	 
 UINT8 numOfRL ;	 
 Bool onlyOneCsRb ; // CQ96577	 
 BYTE pad1 [ 1 ] ;	 
 dpchModifyDlParams_ts dpchDlParams [ 6 ] ;	 
 dpchModifyUlParams_ts dpchUlParams ;	 
 Bool fdpchEnabled ;	 
 UINT8 pad2 [ 2 ] ;	 
 plwPhyChConfigValidity_te phyChConfigValidity ;	 
	 
 SyncParamsConnected_ts SyncParamsConnected ;	 
	 
 trchConfigDescription_ts trchDescription ;	 
	 
 } dpchModifyDescription_ts;

typedef UINT8 statusInd_te ;
//ICAT EXPORTED ENUM 
 enum statusInd_values 
 {	 
 L1_IND_SUCCESS = 0x00 ,	 
 L1_IND_FAILURE = 0x01	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 phyChType_te phyChType ;	 
 statusInd_te statusInd ;	 
 BYTE pad [ 2 ] ;	 
 INT16 cpichEcNo ;	 
 INT16 cpichRscp ;	 
 } rlSetupCnf_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 phyChType_te phyChType ;	 
 BYTE pad [ 3 ] ;	 
 } rlReleaseCnf_ts;

typedef UINT8 randomAccessStatus_te ;
//ICAT EXPORTED ENUM 
 enum randomAccessStatus_values 
 {	 
 ACK = 0x00 ,	 
 NO_ACK = 0x01 ,	 
 NACK = 0x02	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 cfn ;	 
 Bool readyToSend ;	 
 INT16 powerLeft [ 15 ] ; // change from INT8	 
 // BYTE pad [ 3 ] ;	 
 } plUlDataSync_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 // TRCH ID 1 ..32	 
 UINT8 trchId ;	 
 // TFI 1 ..64	 
 UINT8 tfi ;	 
 UINT8 pad [ 2 ] ;	 
 } ulPduDataInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 // give the start address of UL data block in this TTI to allow L1 get the data by DMA way	 
 UINT32 ulDataStartAddr ;	 
 // TFCI value 0 ..64	 
 UINT8 tfciValue ;	 
 // TRCH type: DCH or RACH	 
 trChType_te trChType ;	 
	 
 UINT8 pad ;	 
 // number of TRCH 0 ..8	 
 UINT8 trchNum ;	 
 // TRCH data info , only the items indicated by trchNum are available	 
 ulPduDataInfo_ts trchDataInfo [ 8 ] ;	 
 } plDataReqHeader_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 tbAddr ;	 
 UINT8 trChId ;	 
 trChType_te trChType ;	 
 UINT16 frameNum ;	 
 // UINT16 dataSize ;	 
 UINT8 transpFormatId ;	 
 BYTE pad [ 3 ] ;	 
 UINT32 crcCheckResult ;	 
 } plDataIndHeader_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 // The address of each Mac-hs / ehs PDU	 
 UINT32 dataBlockStartAddr ;	 
 // the bit length of Mac-hs or Mac-ehs PDU size	 
 UINT16 bitlength ;	 
 // Used for Umahs to align Mac-d data part to 8 bits , Always set to 0 in Mac-ehs , Range 0 ..7	 
 UINT8 byteAlignOffset ;	 
 // Flag to indicate this PDU is PCH or BCH as LogCH Id equal to 15 , 1 : BCH , 0 PCH	 
 UINT8 hrntiReceivedInd ;	 
 // transmission numbers	 
 UINT8 numOfTransmission ;	 
 // TB received from primary cell or secondary cell: 0 : primary cell , 1 : secondary cell.	 
 UINT8 receivedFromCell ;	 
	 
 UINT16 reserved ;	 
 } HsTbInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 // index of the subframe or frame whose data is ready for reading	 
 UINT16 sfn ;	 
 // subframe sequence number	 
 UINT8 subframe ;	 
 // Indicate if this PDU is Mac-hs or Mac-ehs type , 0 : Mac-hs , 1 : Mac-ehs	 
 UINT8 macType ;	 
	 
 UINT8 reserved [ 3 ] ;	 
 // max 2 block per TTI	 
 UINT8 dataBlockNum ;	 
	 
 HsTbInfo_ts HsTbInfo [ 2 ] ;	 
 } plHsDataIndHeader_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numBlockAlloc ;	 
	 
 UINT8 reserved [ 3 ] ;	 
	 
 UINT32 dpaDataAddrArray [ 24 ] ;	 
	 
 } plHsPointerReqHeader_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numBlockAlloc ;	 
	 
 UINT8 reserved [ 3 ] ;	 
	 
 UINT32 dlDataAddrArray [ 8 ] ;	 
	 
 } plDlPointerReqHeader_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 trChId ;	 
 trChType_te trChType ;	 
 BYTE pad [ 2 ] ;	 
 } dataTransferEnd_ts;

typedef UINT8 dlFrameType_te ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 TYPE_A = 0x00 ,	 
 TYPE_B = 0x01 ,	 
	 
 CM_DL_FRAME_TYPE_MAX_VAL = 0x01 // must be EQUAL to the highest value in enum!	 
 } dlFrameType_values;

typedef UINT8 CompModeMethod_te ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PUNCTURING = 0x00 , // Used only in DL	 
 SF_BY_TWO = 0x01 ,	 
 HIGHER_LAYER_SCHEDULING = 0x02 ,	 
	 
 CM_METHOD_MAX_VAL = 0x02 // must be EQUAL to the highest value in enum!	 
 } CompModeMethod_values;

typedef UINT8 ulDlMode_te ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 DL_ONLY = 0x00 ,	 
 UL_ONLY = 0x01 ,	 
 DL_AND_UL = 0x02 ,	 
	 
 CM_UL_DL_MODE_MAX_VAL = 0x02 // must be EQUAL to the highest value in enum!	 
 } ulDlMode_values;

typedef UINT8 itpMode_te ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 L1_ITP_MODE_0 = 0x00 ,	 
 L1_ITP_MODE_1 = 0x01 ,	 
	 
 CM_ITP_MODE_MAX_VAL = 0x01 // must be EQUAL to the highest value in enum!	 
 } itpMode_values;

typedef UINT8 rppMode_te ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 L1_RPP_MODE_0 = 0x00 ,	 
 L1_RPP_MODE_1 = 0x01 ,	 
	 
 CM_RPP_MODE_MAX_VAL = 0x01 // must be EQUAL to the highest value in enum!	 
	 
 } rppMode_values;

typedef UINT8 l1Tgmp_te ;
//ICAT EXPORTED ENUM 
 enum l1Tgmp_values 
 {	 
 RESERVED2 = 0x00 ,	 
 FDD_MEAS = 0x01 ,	 
 GSM_CARRIER_RSSI_MEAS = 0x02 ,	 
 GSM_INIT_BSIC_IDENTIFICATION = 0x03 ,	 
 GSM_BSIC_RECONFIRM = 0x04 ,	 
	 
 E_UTRA_MEAS = 0x05 ,	 
 CM_PS_TGMP_MAX_VAL = 0x06	 
	 
	 
	 
 };

typedef UINT8 tgpsStatusFlag_te ;
//ICAT EXPORTED ENUM 
 enum tgpsStatusFlag_values 
 {	 
 TGPS_ACTIVE ,	 
 TGPS_INACTIVE ,	 
 TGPS_MODIFY ,	 
 TGPS_CONTINUE ,	 
	 
 CM_PS_TGPS_STATUS_MAX_VAL = TGPS_CONTINUE // must be EQUAL to the highest value in enum!	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 l1Tgmp_te l1Tgmp ;	 
 BYTE pad1 ;	 
 UINT16 l1Tgprc ;	 
 UINT8 l1Tgsn ;	 
 UINT8 l1Tgl1 ;	 
 UINT8 l1Tgl2 ;	 
 BYTE pad2 ;	 
 UINT16 l1Tgd ;	 
 UINT8 l1Tgpl1 ;	 
 UINT8 l1Tgpl2 ;	 
 rppMode_te l1Rpp ;	 
 itpMode_te l1Itp ;	 
 ulDlMode_te l1UIDI ;	 
 CompModeMethod_te dlCompModeMethod ;	 
 CompModeMethod_te ulCompModeMethod ;	 
 dlFrameType_te dlFrameType ;	 
 UINT8 deltaSir1 ;	 
 UINT8 deltaSirafter1 ;	 
 UINT8 deltaSir2 ;	 
 UINT8 deltaSirafter2 ;	 
 UINT8 nldentifyAbort ;	 
 UINT8 tReconfirmAbort ;	 
 } tgpsConfig_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 tgpsIdentifier ;	 
 tgpsStatusFlag_te tgpsStatusFlag ;	 
 UINT8 I1Tgcfn ;	 
 BYTE pad ;	 
 activationTime_ts activationTime ;	 
 tgpsConfig_ts tgpsConfig ;	 
 } dpchTgpsParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfTpgs ;	 
 BYTE pad [ 3 ] ;	 
 dpchTgpsParams_ts dpchTgpsParam [ 6 ] ;	 
 } dpchCompressModeParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfSlotGaps ;	 
 CompModeMethod_te compModeMethod ;	 
 BYTE pad [ 2 ] ;	 
 UINT16 CompressedSlotsBitmap ;	 
 } frameCmInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 collisionCfn ;	 
 UINT8 tgpsIdentifier ;	 
 l1Tgmp_te l1Tgmp ;	 
 BYTE pad ;	 
 } errTgpsParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfTgps ;	 
 BYTE pad [ 3 ] ;	 
 errTgpsParams_ts errTgpsParams [ 4 ] ;	 
 } cmErrorInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfTgps ;	 
 UINT8 pad [ 3 ] ;	 
 UINT8 tgpsIdentifier [ 6 ] ;	 
 UINT8 lastCfnOfTgps [ 6 ] ;	 
 } cmPatternEndedInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfFrames ;	 
 UINT8 FirstCfn ;	 
 BYTE pad [ 2 ] ;	 
 frameCmInfo_ts frameCmInfo [ 8 ] ;	 
 } plTtiInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 activationTime_ts activationTime ;	 
 plActionType_te actionType ;	 
 UINT8 trChId ;	 
 trChType_te trChType ;	 
 } lbTrCh_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfTrCh ;	 
 UINT8 simID ;	 
 lbTrCh_ts lbTrCh [ 8 ] ;	 
 } lbMode2params_ts;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 statusInd_te restoreStatus ;	 
 phyChType_te restoredChannelType ;	 
 UINT16 dlUarfcn ;	 
 UINT16 dlPriScramblingCode ;	 
 INT16 cpichEcNo ;	 
 INT16 cpichRscp ;	 
 } restoreWcdmaCnf_ts;

typedef UINT8 macType_te ;
//ICAT EXPORTED ENUM 
 enum macType_values 
 {	 
 MAC_HS = 0x00 ,	 
 MAC_EHS = 0x01	 
 };

typedef UINT8 TrBkSizeTableIndex_te ;
//ICAT EXPORTED ENUM 
 enum TrBkSizeTableIndex_values 
 {	 
 BIT_ALIGNED = 0x00 ,	 
 OCTET_ALIGNED = 0x01	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 transportBlockSizeIndex ;	 
 Bool hspdschSecondCodeSupport ;	 
 UINT8 pad [ 2 ] ;	 
 } transportBlockSizeList_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ERR_IND_NO_REPORT = 0 ,	 
 ERR_IND_CANT_COPY_RX_DATA ,	 
 ERR_IND_INVALID_OOS_REQ ,	 
 ERR_IND_INVALID_REQ_PARAMS , // received request with invalid parameters	 
 ERR_IND_INVALID_REQ_STATE , // received request at wrong state	 
 ERR_IND_INVALID_SET_CM_PARAMS , // in valid parameters received from the set Compressed Mode Command	 
 ERR_IND_NUM_OF_MEAS_FREQ_OVERFLOW , // in cases where the PS requests to measure to many frequencies	 
 ERR_IND_FATAL_ERROR ,	 
 ERR_IND_LOW_PRIORITY_WARNING ,	 
 ERR_INVALID_RAT_TERMINATION ,	 
 ERR_WRONG_PLP_STATE ,	 
 ERR_IND_INVALID_PHY_CH_SETUP_REQ ,	 
 ERR_IND_INVALID_RL_RELEASE_REQ	 
 } plwErrInd_e;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 plActionType_te actionType ;	 
 UINT8 pad ;	 
 UINT16 T319 ;	 
 } t319Config_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Bool flag ;	 
 Bool dueToPch ;	 
 } resumeCnf_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Bool flag ;	 
 } dsPagingFailureInd_ts;

