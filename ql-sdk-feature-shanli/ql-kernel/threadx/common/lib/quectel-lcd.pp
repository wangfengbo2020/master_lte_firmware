//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\rtp_drv.ppp
//PPL Source File Name : \\quectel\\lcd\\rtp_controller\\rtp_drv.c
typedef unsigned int size_t ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 OSA_TASK_READY ,	 
 OSA_TASK_COMPLETED ,	 
 OSA_TASK_TERMINATED ,	 
 OSA_TASK_SUSPENDED ,	 
 OSA_TASK_SLEEP ,	 
 OSA_TASK_QUEUE_SUSP ,	 
 OSA_TASK_SEMAPHORE_SUSP ,	 
 OSA_TASK_EVENT_FLAG ,	 
 OSA_TASK_BLOCK_MEMORY ,	 
 OSA_TASK_MUTEX_SUSP ,	 
 OSA_TASK_STATE_UNKNOWN ,	 
 } OSA_TASK_STATE;

//ICAT EXPORTED STRUCT 
 typedef struct OSA_TASK_STRUCT 
 {	 
 char *task_name ; /* Pointer to thread ' s name */	 
 unsigned int task_priority ; /* Priority of thread ( 0 -255 ) */	 
 unsigned long task_stack_def_val ; /* default vaule of thread */	 
 OSA_TASK_STATE task_state ; /* Thread ' s execution state */	 
 unsigned long task_stack_ptr ; /* Thread ' s stack pointer */	 
 unsigned long task_stack_start ; /* Stack starting address */	 
 unsigned long task_stack_end ; /* Stack ending address */	 
 unsigned long task_stack_size ; /* Stack size */	 
 unsigned long task_run_count ; /* Thread ' s run counter */	 
	 
 } OSA_TASK;

typedef void *OsaRefT ;
typedef UINT8 OSA_STATUS ;
typedef UINT8 OS_STATUS ;
typedef void* OS_HISR ;
typedef void* OSATaskRef ;
typedef void* OSAHISRRef ;
typedef void* OSASemaRef ;
typedef void* OSAMutexRef ;
typedef void* OSAMsgQRef ;
typedef void* OSAMailboxQRef ;
typedef void* OSAPoolRef ;
typedef void* OSATimerRef ;
typedef void* OSAFlagRef ;
typedef void* OSAPartitionPoolRef ;
typedef void* OSTaskRef ;
typedef void* OSSemaRef ;
typedef void* OSMutexRef ;
typedef void* OSMsgQRef ;
typedef void* OSMailboxQRef ;
typedef void* OSPoolRef ;
typedef void* OSTimerRef ;
typedef void* OSFlagRef ;
typedef UINT8 OS_STATUS ;
typedef OsaTimerStatusParamsT OSATimerStatus ;
typedef void* OSATaskRef ;
typedef void* OSAHISRRef ;
typedef void* OSAMsgQRef ;
typedef void* OSAMailboxQRef ;
typedef void* OSAPartitionPoolRef ;
typedef UINT8 OS_STATUS ;
typedef unsigned long UNSIGNED ;
typedef long SIGNED ;
typedef unsigned char DATA_ELEMENT ;
typedef DATA_ELEMENT OPTION ;
typedef DATA_ELEMENT BOOLEAN ;
typedef int STATUS ;
typedef unsigned char UNSIGNED_CHAR ;
typedef unsigned int UNSIGNED_INT ;
typedef int INT ;
typedef unsigned long * UNSIGNED_PTR ;
typedef unsigned char * BYTE_PTR ;
typedef va_list __gnuc_va_list ;
typedef signed char int8_t ;
typedef signed short int int16_t ;
typedef signed int int32_t ;
typedef signed __int64 int64_t ;
typedef unsigned char uint8_t ;
typedef unsigned short int uint16_t ;
typedef unsigned int uint32_t ;
typedef unsigned __int64 uint64_t ;
typedef signed char int_least8_t ;
typedef signed short int int_least16_t ;
typedef signed int int_least32_t ;
typedef signed __int64 int_least64_t ;
typedef unsigned char uint_least8_t ;
typedef unsigned short int uint_least16_t ;
typedef unsigned int uint_least32_t ;
typedef unsigned __int64 uint_least64_t ;
typedef signed int int_fast8_t ;
typedef signed int int_fast16_t ;
typedef signed int int_fast32_t ;
typedef signed __int64 int_fast64_t ;
typedef unsigned int uint_fast8_t ;
typedef unsigned int uint_fast16_t ;
typedef unsigned int uint_fast32_t ;
typedef unsigned __int64 uint_fast64_t ;
typedef signed int intptr_t ;
typedef unsigned int uintptr_t ;
typedef signed long long intmax_t ;
typedef unsigned long long uintmax_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef unsigned char uint8 ;
typedef signed char int8 ;
typedef unsigned short int uint16 ;
typedef signed short int int16 ;
typedef unsigned int uint32 ;
typedef signed int int32 ;
typedef unsigned long long uint64 ;
typedef signed long long int64 ;
typedef int QuecOSStatus ;
typedef unsigned char uint8_t ;
typedef unsigned short uint16_t ;
typedef unsigned int uint32_t ;
typedef unsigned long long uint64_t ;
typedef unsigned int uint_t ;
typedef unsigned char uint_8 ;
typedef unsigned short uint_16 ;
typedef unsigned int uint_32 ;
typedef unsigned long long uint_64 ;
typedef signed int int_32 ;
typedef signed int int32_t ;
typedef unsigned char u8 ;
typedef unsigned short u16 ;
typedef unsigned int u32 ;
typedef uint8 data_t ;
typedef uint32 datasize_t ;
typedef uint32 node_cnt_t ;
typedef int32 linklist_id_t ;
typedef linklist_t * linklist_handler_t ;
typedef uint32 quec_tcb_id_t ;
typedef linklist_handler_t QuecTCBLinklist_t ;
typedef OSTaskRef quec_task_t ;
typedef OSSemaRef quec_sem_t ;
typedef OSMutexRef quec_mutex_t ;
typedef OSMsgQRef quec_queue_t ;
typedef OSMailboxQRef quec_mailbox_t ;
typedef OSFlagRef quec_flag_t ;
typedef OSTimerRef quec_timer_t ;
typedef OSATimerStatus quec_timer_status_t ;
typedef void ( * task_delete_work_cb_t ) ( task_delete_result_t * task_delete_result ) ;
typedef void ( *touch_panel_down_cb ) ( unsigned int x , unsigned int y ) ;
typedef unsigned char BOOL ;
typedef unsigned char UINT8 ;
typedef unsigned short UINT16 ;
typedef signed char INT8 ;
typedef signed short INT16 ;
typedef unsigned short WORD ;
typedef int HANDLE ;
typedef HANDLE* LPHANDLE ;
typedef unsigned char* PUINT8 ;
typedef long LONG ;
typedef char* LPCTSTR ;
typedef char* LPTSTR ;
typedef void* LPVOID ;
typedef unsigned int* LPDWORD ;
typedef unsigned int* PDWORD ;
typedef unsigned int* PUINT32 ;
typedef unsigned int UINT ;
typedef INT16 *PINT16 ;
typedef UINT16 *PUINT16 ;
typedef INT8 *PINT8 ;
typedef UINT8 *PUINT8 ;
typedef int utlReturnCode_T , *utlReturnCode_P ;
typedef const utlReturnCode_T *utlReturnCode_P2c ;
typedef unsigned int utlDataId_T , *utlDataId_P ;
typedef unsigned int size_t , ssize_t ;
typedef const utlDataId_T *utlDataId_P2c ;
typedef const utlLinkedListNode_T *utlLinkedListNode_P2c ;
typedef unsigned int utlNodeCount_T ;
typedef const utlLinkedList_T *utlLinkedList_P2c ;
typedef int utlSecond_T ;
typedef int utlNanosecond_T ;
typedef const utlRelativeTime_T *utlRelativeTime_P2c ;
typedef const utlAbsoluteTime_T *utlAbsoluteTime_P2c ;
typedef const utlVString_T *utlVString_P2c ;
typedef signed long utlTimerId_T ;
typedef unsigned long utlTimeOutCount_T , *utlTimeOutCount_P ;
typedef utlReturnCode_T ( *utlTimerFunction_P ) ( const utlTimerId_T id ,
 const utlTimeOutCount_T time_out_count ,
 void *arg_p ,
 const utlAbsoluteTime_P2c curr_time_p ) ;
typedef unsigned int utlMutexAttributes_T , *utlMutexAttributes_P ;
typedef unsigned int utlSemaphoreAttributes_T , *utlSemaphoreAttributes_P ;
typedef int utlStateMachineStateId_T , *utlStateMachineStateId_P ;
typedef int utlStateMachineEventId_T , *utlStateMachineEventId_P ;
typedef utlReturnCode_T ( *utlStateMachineStateFunction_P ) ( const utlStateMachine_P state_machine_p ,
 const utlStateMachineStateId_T state ,
 const utlAbsoluteTime_P2c curr_time_p ,
 void *arg_p ) ;
typedef utlReturnCode_T ( *utlStateMachineEventFunction_P ) ( const utlStateMachine_P state_machine_p ,
 const utlStateMachineStateId_T state ,
 const utlStateMachineEventId_T event ,
 const utlAbsoluteTime_P2c curr_time_p ,
 void *arg_p ,
 va_list va_arg_p ) ;
typedef const utlStateMachineEvent_T *utlStateMachineEvent_P2c ;
typedef const utlStateMachineState_T *utlStateMachineState_P2c ;
typedef unsigned int utlStateMachineFlags_T ;
typedef const utlStateMachine_T *utlStateMachine_P2c ;
typedef volatile UINT8 *V_UINT8_PTR ;
typedef volatile UINT16 *V_UINT16_PTR ;
typedef volatile UINT32 *V_UINT32_PTR ;
typedef unsigned int U32Bits ;
typedef BOOL BOOLEAN ;
typedef const char * SwVersion ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_E ,	 
 MAT_I ,	 
 MAT_L ,	 
 MAT_M ,	 
 MAT_O ,	 
 MAT_P ,	 
 MAT_Q ,	 
 MAT_T ,	 
 MAT_V ,	 
 MAT_X ,	 
 MAT_Z ,	 
 MAT_ampC ,	 
 MAT_ampD ,	 
 MAT_ampF ,	 
 MAT_ampS ,	 
 MAT_ampZ ,	 
 MAT_ampM ,	 
 MAT_ampV ,	 
 MAT_CGMI ,	 
 MAT_CGMM ,	 
 MAT_CGMR ,	 
 MAT_CGSN ,	 
 MAT_CSCS ,	 
 MAT_CIMI ,	 
 MAT_ASTO ,	 
 MAT_GMI ,	 
 MAT_GMM ,	 
 MAT_GMR ,	 
 MAT_GSN ,	 
 MAT_GOI ,	 
 MAT_GCAP ,	 
 MAT_GCI ,	 
 MAT_IPR ,	 
 MAT_ICF ,	 
 MAT_IFC ,	 
 MAT_IDSR ,	 
 MAT_EXAMPLE ,	 
 MAT_RawAT ,	 
 MAT_A ,	 
 MAT_D ,	 
 MAT_H ,	 
 MAT_CSTA ,	 
 MAT_CMOD ,	 
 MAT_CVMOD ,	 
 MAT_CHUP ,	 
 MAT_CBST ,	 
 MAT_CVHU ,	 
 MAT_CRLP ,	 
 MAT_CEER ,	 
 MAT_CMUT ,	 
 MAT_ECHUPVT ,	 
	 
 MAT_CREG ,	 
 MAT_CIND ,	 
 MAT_COPS ,	 
 MAT_CPOL ,	 
 MAT_CLCK ,	 
 MAT_CPWD ,	 
 MAT_CLIP ,	 
 MAT_CLIR ,	 
 MAT_COLP ,	 
 MAT_COLR ,	 
 MAT_CNAP ,	 
 MAT_CCFC ,	 
 MAT_CCWA ,	 
 MAT_CHLD ,	 
 MAT_CAOC ,	 
 MAT_VTS ,	 
 MAT_VTD ,	 
 MAT_CSSN ,	 
 MAT_CLCC ,	 
 MAT_FCLASS ,	 
 MAT_starCISCC ,	 
 MAT_dollarVTS ,	 
 MAT_starDIALE ,	 
	 
 MAT_CUSD ,	 
 MAT_PEER ,	 
 MAT_CSQ ,	 
 MAT_starREJCUSE ,	 
 MAT_CMUX ,	 
	 
 MAT_NETDMSG ,	 
 MAT_CSQEX ,	 
	 
 MAT_CPAS ,	 
 MAT_CFUN ,	 
 MAT_starCFUN ,	 
	 
 MAT_MINI_START ,	 
 MAT_MINI_END ,	 
	 
 MAT_CPIN ,	 
 MAT_CPIN2 ,	 
 MAT_EPIN ,	 
 MAT_CPINR ,	 
 MAT_starSIMDETEC ,	 
 MAT_CPOFF ,	 
 MAT_CTZR ,	 
 MAT_CTZU ,	 
 MAT_starCTZR ,	 
 MAT_CPBS ,	 
 MAT_CPBR ,	 
 MAT_CPBW ,	 
 MAT_CPBF ,	 
 MAT_CSIM ,	 
 MAT_CRSM ,	 
 MAT_CGLA ,	 
 MAT_CRLA ,	 
 MAT_CCHO ,	 
 MAT_CCHC ,	 
 MAT_MSTK ,	 
 MAT_starEUICC ,	 
 MAT_CACM ,	 
 MAT_CAMM ,	 
 MAT_CCWE ,	 
 MAT_ADMINDATA ,	 
 MAT_CGREG ,	 
 MAT_starREGOPT ,	 
 MAT_CGATT ,	 
	 
 MAT_CGATTEX ,	 
	 
 MAT_CGACT ,	 
 MAT_CGDATA ,	 
 MAT_CGDCONT ,	 
 MAT_CGDSCONT ,	 
 MAT_CGQMIN ,	 
 MAT_CGQREQ ,	 
 MAT_CGEQREQ ,	 
 MAT_CGEQMIN ,	 
 MAT_GETIP ,	 
 MAT_starTGSINK ,	 
 MAT_CGSEND ,	 
 MAT_starICSSINK ,	 
 MAT_starAUTHReq ,	 
	 
 MAT_starCHAPAUTH ,	 
	 
 MAT_CMGF ,	 
 MAT_starCMGF ,	 
 MAT_CMSS ,	 
 MAT_CMGS ,	 
 MAT_CMGR ,	 
 MAT_CMGW ,	 
 MAT_CSCA ,	 
 MAT_CSCB ,	 
 MAT_CNMI ,	 
 MAT_CGSMS ,	 
 MAT_CMMS ,	 
 MAT_CMGD ,	 
 MAT_CMGL ,	 
 MAT_CSMS ,	 
 MAT_CPMS ,	 
 MAT_CNMA ,	 
 MAT_CSMP ,	 
 MAT_CSDH ,	 
 MAT_CSAS ,	 
 MAT_CRES ,	 
 MAT_CPNER ,	 
 MAT_CGCI ,	 
 MAT_CGOI ,	 
 MAT_VDUMP ,	 
 MAT_VPDUS ,	 
 MAT_VHDL ,	 
 MAT_VECHO ,	 
 MAT_ATDB ,	 
 MAT_starCCIREG ,	 
 MAT_CPUC ,	 
 MAT_CRC ,	 
 MAT_CMEE ,	 
 MAT_CDIP ,	 
 MAT_CPLS ,	 
 MAT_CGCMOD ,	 
 MAT_CNUM ,	 
 MAT_DS ,	 
 MAT_CGTFT ,	 
 MAT_starBAND ,	 
 MAT_starBANDIND ,	 
 MAT_starCLCK ,	 
 MAT_starMEPCG ,	 
 MAT_starENVSIM ,	 
 MAT_starCNMA ,	 
 MAT_starRSTMEMFULL ,	 
 MAT_starPOWERIND ,	 
 MAT_starFASTDORM ,	 
 MAT_starCellLock ,	 
 MAT_EEMOPT ,	 
 MAT_EEMGINFO ,	 
 MAT_ERGA ,	 
 MAT_ERTCA ,	 
 MAT_LPNWUL ,	 
 MAT_LPLOCVR ,	 
 MAT_starSYSSLEEP ,	 
 MAT_starCam_I2C ,	 
 MAT_starISP_REG ,	 
 MAT_starCam_rawdump ,	 
 MAT_starFILETEST ,	 
 MAT_starMRD_CDF ,	 
 MAT_starMRD_IMEI ,	 
 MAT_starMRD_MEP ,	 
 MAT_starMRD_CalInfo ,	 
 MAT_starMRD_MEPPLMN ,	 
 MAT_starMRD_SN ,	 
 MAT_starMRD_ITEM ,	 
 MAT_starMRD_ADC ,	 
 MAT_starMRD_RTPADC ,	 
 // #ifdef AT_PRODUCTION_CMNDS	 
 MAT_starGSMTR ,	 
 // #endif	 
 MAT_OFF ,	 
 MAT_starCGSN ,	 
 MAT_starMODEMTYPE ,	 
 MAT_starHTCCTO ,	 
 MAT_CMEMFULL ,	 
 MAT_starEHSDPA ,	 
	 
	 
	 
	 
 MAT_starFDY ,	 
 MAT_xorSYSINFO ,	 
 MAT_starCPBC ,	 
 MAT_starFDNBYPASS ,	 
 MAT_starCSCB ,	 
 MAT_starCBMCS ,	 
 MAT_starNASCHK ,	 
 MAT_CGEQOS ,	 
 MAT_CEREG ,	 
 MAT_CGCONTRDP ,	 
 MAT_CGSCONTRDP ,	 
 MAT_CGTFTRDP ,	 
 MAT_CGEQOSRDP ,	 
 MAT_CGEREP ,	 
 MAT_CEMODE ,	 
 MAT_CGPADDR ,	 
 MAT_xorCACAP ,	 
 MAT_CGCLASS ,	 
 MAT_CESQ ,	 
 MAT_BGLTEPLMN ,	 
 MAT_STARCGDFAUTH ,	 
 MAT_dollarMYMINISYS ,	 
 MAT_dollarMYFOTA ,	 
 MAT_VZWRSRP ,	 
 MAT_VZWRSRQ ,	 
 MAT_starCGDFLT ,	 
	 
 MAT_STARNETACT ,	 
 MAT_STARNETREF ,	 
 MAT_STARNETDNS ,	 
 MAT_STARNETIF ,	 
 MAT_STARNETIFCM ,	 
 MAT_STARMPSAPN ,	 
	 
	 
 MAT_starMODEMRESET ,	 
	 
 MAT_starVZWTESTAPP ,	 
 MAT_VZWAPNE ,	 
 MAT_COPN ,	 
 MAT_starGATR ,	 
 MAT_starGRIP ,	 
 MAT_playMP3 ,	 
 MAT_starCGMR ,	 
 MAT_starCOMCFG ,	 
 MAT_starRFTEMP ,	 
 MAT_startRFTEMPEX ,	 
	 
 MAT_starSOCTEMP ,	 
	 
 MAT_TEMPTEST ,	 
 MAT_BANSELCT ,	 
 MAT_SYSSLEEP ,	 
 MAT_PSSDC ,	 
 MAT_starCGATT ,	 
 MAT_CGPIAF ,	 
 MAT_CIREG ,	 
 MAT_starUSBT ,	 
 MAT_starLTECOEX ,	 
 MAT_LTEPOWER ,	 
 MAT_LTETR ,	 
 MAT_starCSQ ,	 
 MAT_MAXPOWER ,	 
 MAT_SIMDETEC ,	 
 MAT_APPPIN ,	 
 MAT_CPLMNS ,	 
 MAT_starMOBILEDATA ,	 
 MAT_MCCMNCCC ,	 
 MAT_WS46 ,	 
 MAT_starCELL ,	 
 MAT_CISRVCC ,	 
 MAT_CEVDP ,	 
 MAT_CEUS ,	 
 /* add for BT SAP */	 
 MAT_BTSCNCT ,	 
 MAT_BTSDISSCNCT ,	 
 MAT_BTSTAPDU ,	 
 MAT_BTSTATR ,	 
 MAT_BTSCTRL ,	 
 MAT_BTSCRSTAT ,	 
 MAT_BTSTP ,	 
 MAT_starWBAMR ,	 
 MAT_CNMPSD ,	 
 MAT_starREGMODE ,	 
 MAT_starIMLCONFIG ,	 
 MAT_CCLK ,	 
 MAT_starURSLCT ,	 
 MAT_starCBRAT ,	 
 MAT_starSECCAP ,	 
 MAT_starLTEBAND ,	 
 MAT_starPSTHRESHOLD ,	 
 MAT_CACL ,	 
 MAT_LPECID ,	 
 MAT_LPOTDOAABORT ,	 
 MAT_LPOTDOAREQ ,	 
 MAT_L1DEBUG ,	 
 MAT_CSC ,	 
 MAT_OPERCFG ,	 
 MAT_starPSDC ,	 
 MAT_CEN ,	 
 MAT_CNEM ,	 
 MAT_CMMIVT ,	 
 MAT_CPSMS ,	 
 MAT_CEDRXS ,	 
 MAT_CEDRXRDP ,	 
 MAT_CCIOTOPT ,	 
 MAT_CRCES ,	 
 MAT_CSCON ,	 
 MAT_CIPCA ,	 
 MAT_CABTSR ,	 
 MAT_CABTRDP ,	 
 MAT_CGAPNRC ,	 
 MAT_MPBK ,	 
 MAT_CSODCP ,	 
 MAT_CRTDCP ,	 
	 
 MAT_LOG ,	 
 MAT_starDIALMODE ,	 
 MAT_starAPNMODE ,	 
 MAT_starAGDCONT ,	 
 MAT_starAGACT ,	 
 MAT_starLWIPCTRL ,	 
 MAT_starNTP ,	 
 MAT_starCGDCONT ,	 
 MAT_starMTU ,	 
 MAT_plusSWITCHSIM ,	 
 MAT_plusDUALSIM ,	 
 MAT_plusBINDSIM ,	 
	 
	 
	 
 MAT_Q_QDSIM ,	 
	 
 MAT_Q_QDSTYPE ,	 
 MAT_Q_QDSBIND ,	 
 MAT_Q_QDSIMI ,	 
 MAT_Q_QDSCCID ,	 
 MAT_Q_QDSPIN ,	 
 MAT_Q_QDSREG ,	 
 MAT_Q_QDSGREG ,	 
 MAT_Q_QDSEREG ,	 
 MAT_Q_QDSQ ,	 
 MAT_Q_QDSOPS ,	 
 MAT_Q_QDSLOCK ,	 
 MAT_Q_QDSRELEASE ,	 
	 
 // MAT_plusCWRITESIM ,	 
 // #ifdef BT_TEST_SUPPORT 20201214 @xiaokeweng force enable as BT / WIFI could be enable / disable in SDK build	 
 MAT_BTTEST ,	 
 // #endif	 
 MAT_startECCLIST ,	 
	 
	 
	 
	 
	 
 MAT_TRUSTNUM ,	 
	 
 /* STASR1606-2810: CHKTRUSTNUM can not be shielded because the cloesd source IMS will use it for checking the trust number. */	 
 MAT_CHKTRUSTNUM ,	 
	 
 MAT_starISIMAID ,	 
 MAT_CSSAC ,	 
 MAT_MEDCR ,	 
	 
 MAT_Q_QFOTADL ,	 
	 
	 
 MAT_STARREADVER ,	 
 MAT_RESET ,	 
 MAT_RSTSET ,	 
	 
 MAT_DNS ,	 
 MAT_dollarMYPOWEROFF ,	 
 MAT_dollarMYSOCKETLED ,	 
 MAT_dollarMYGMR ,	 
 MAT_dollarMYCCID ,	 
 MAT_dollarMYNETURC ,	 
 MAT_dollarMYTYPE ,	 
 MAT_dollarMYNETCON ,	 
 MAT_dollarMYNETACT ,	 
 MAT_dollarMYIPFILTER ,	 
 MAT_dollarMYNETSRV ,	 
 MAT_dollarMYNETOPEN ,	 
 MAT_dollarMYNETREAD ,	 
 MAT_dollarMYNETWRITE ,	 
 MAT_dollarMYNETCLOSE ,	 
 MAT_dollarMYNETACK ,	 
 MAT_dollarMYNETACCEPT ,	 
 MAT_dollarMYNETCREATE ,	 
 MAT_dollarMYFTPOPEN ,	 
 MAT_dollarMYFTPCLOSE ,	 
 MAT_dollarMYFTPSIZE ,	 
 MAT_dollarMYFTPGET ,	 
 MAT_dollarMYFTPPUT ,	 
 MAT_dollarMYBCCH ,	 
 MAT_dollarMYBAND ,	 
 MAT_dollarMYTIMEUPDATE ,	 
 MAT_dollarMYLACID ,	 
 MAT_dollarMYGPSPOS ,	 
 MAT_dollarMYGETKEY ,	 
 MAT_dollarMYSETINFO ,	 
 MAT_dollarMYSYSINFO ,	 
 MAT_dollarMYSYSINFOURC ,	 
 MAT_QICSGP ,	 
 MAT_QIACT ,	 
 MAT_QIDEACT ,	 
 MAT_QIOPEN ,	 
 MAT_QICLOSE ,	 
 MAT_QISTATE ,	 
 MAT_QISEND ,	 
 MAT_QIRD ,	 
 MAT_QISENDEX ,	 
 MAT_QISWTMD ,	 
 MAT_QIGETERROR ,	 
 MAT_QISDE ,	 
 MAT_QICFG ,	 
 MAT_QFTPCFG ,	 
 MAT_QFTPOPEN ,	 
 MAT_QFTPCLOSE ,	 
 MAT_QFTPCWD ,	 
 MAT_QFTPPWD ,	 
 MAT_QFTPPUT ,	 
 MAT_QFTPGET ,	 
 MAT_QFTPSIZE ,	 
 MAT_QFTPDEL ,	 
 MAT_QFTPMKDIR ,	 
 MAT_QFTPRMDIR ,	 
 MAT_QFTPMDTM ,	 
 MAT_QFTPRENAME ,	 
 MAT_QFTPLIST ,	 
 MAT_QFTPNLST ,	 
 MAT_QFTPMLSD ,	 
 MAT_QFTPLEN ,	 
 MAT_QFTPSTAT ,	 
 MAT_TCPKEEPALIVE ,	 
	 
 MAT_dollarMYDOWNLOAD ,	 
	 
	 
 MAT_xorHVER ,	 
 MAT_CDU ,	 
 MAT_starPROD ,	 
 MAT_NVMFLUSH ,	 
 MAT_starSLT ,	 
 MAT_starPMICREG ,	 
 MAT_starREGRW ,	 
 MAT_ZDON ,	 
 MAT_starASRCOPS ,	 
 MAT_starICCID ,	 
 MAT_CEN1 ,	 
 MAT_CEN2 ,	 
 MAT_starSULOGCFG ,	 
	 
 MAT_starWIFICTRL ,	 
	 
 MAT_starSIMPOLL ,	 
 MAT_cellinfo ,	 
 MAT_starEPIN ,	 
 MAT_starVER ,	 
 // #ifdef WIFI_FUNCTION_SUPPOR 20201214 @xiaokeweng force enable as BT / WIFI could be enable / disable in SDK build	 
 MAT_WIFI_CMD ,	 
 // #endif	 
 MAT_Audio_CMD ,	 
 MAT_starMRDBACKUP ,	 
 MAT_starMRDWIFIMAC ,	 
 MAT_starMRDBTID ,	 
 MAT_starAUDNVM ,	 
 MAT_starSPN ,	 
 MAT_CMRSS ,	 
 MAT_CMGSS ,	 
 MAT_CMSMS ,	 
 MAT_CMGMS ,	 
 MAT_PACSP ,	 
 MAT_ENVCFG ,	 
 MAT_CUAD ,	 
	 
 MAT_STARGETIP ,	 
 MAT_CR ,	 
 MAT_PROPERTY ,	 
 MAT_UNKNOWN ,	 
 MAT_CMD_UNKNOWN = MAT_UNKNOWN ,	 
	 
 /* response type for MAT */	 
 MAT_RSP_UNKNOWN = 1000 ,	 
 MAT_RSP_OK ,	 
 MAT_RSP_ERROR ,	 
 MAT_RSP_CME_ERROR ,	 
 MAT_RSP_CMS_ERROR ,	 
 MAT_RSP_BUSY ,	 
	 
 /* indication type for MAT */	 
 MAT_IND_CONNECT ,	 
 MAT_IND_NO_CARRIER ,	 
 MAT_IND_RING ,	 
 MAT_IND_NO_ANSWER ,	 
 MAT_IND_NO_DIALTONE ,	 
	 
 /* CC Indication */	 
 MAT_IND_CRING ,	 
 MAT_IND_CCCM ,	 
 MAT_IND_CSSU ,	 
 MAT_IND_CSSI ,	 
 MAT_IND_CR ,	 
 MAT_IND_CEI ,	 
	 
 /* DEV Indication */	 
 MAT_IND_SYSCONFIG ,	 
 MAT_IND_EEMGINFOBASIC ,	 
 MAT_IND_EEMGINFOSVC ,	 
 MAT_IND_EEMGINFOPS ,	 
 MAT_IND_EEMGINFONC ,	 
 MAT_IND_EEMGINBFTM ,	 
 MAT_IND_EEMUMTSSVC ,	 
 MAT_IND_EEMUMTSINTRA ,	 
 MAT_IND_EEMUMTSINTER ,	 
 MAT_IND_EEMUMTSINTERRAT ,	 
 MAT_IND_EEMLTESVC ,	 
 MAT_IND_EEMLTEINTRA ,	 
 MAT_IND_EEMLTEINTER ,	 
 MAT_IND_EEMLTEINTERRAT ,	 
 MAT_IND_SNETIND ,	 
 MAT_IND_LPNWDL ,	 
 MAT_IND_LPSTATE ,	 
 MAT_IND_LPMEAST ,	 
 MAT_IND_LPRESET ,	 
 MAT_IND_DIP ,	 
 MAT_IND_LPOTDOAMEAS ,	 
 /* MM Indication */	 
 MAT_IND_CACAP ,	 
 MAT_IND_MODE ,	 
 MAT_IND_COPN ,	 
 MAT_IND_NITZ ,	 
 MAT_IND_MSRI ,	 
 MAT_IND_HOME_ZONE ,	 
	 
 /* MSG Indication */	 
 MAT_IND_MMSG ,	 
 MAT_IND_CMTI ,	 
 MAT_IND_CBM ,	 
 MAT_IND_CDS ,	 
 MAT_IND_CMT ,	 
	 
 /* PB Indication */	 
 MAT_IND_SCPBR ,	 
 MAT_IND_MPBK ,	 
	 
 /* PS Indication */	 
 MAT_IND_CGEQNEG ,	 
 MAT_IND_CGEV ,	 
	 
 /* SIM Indication */	 
 MAT_IND_COTA ,	 
 MAT_IND_REFRESH ,	 
 MAT_IND_SIM_RESET ,	 
 MAT_IND_CARDMODE ,	 
 MAT_IND_SPN ,	 
	 
 /* SS Indication */	 
 MAT_IND_LPLOC ,	 
 MAT_IND_SSRC ,	 
	 
 /* DAT Indication */	 
 MAT_IND_PSSDC ,	 
	 
 /* the change of sim / usim availability status report */	 
 MAT_IND_BTSSTAT ,	 
	 
 MAT_IND_DSAC ,	 
 MAT_IND_ADMINDATA ,	 
 MAT_IND_CIMI ,	 
 MAT_IND_PSLOAD ,	 
 MAT_IND_RBLOOP ,	 
 MAT_IND_CELL ,	 
 MAT_IND_CIREPI ,	 
 MAT_IND_CIREPH ,	 
 MAT_IND_DATASTATUS ,	 
 MAT_IND_CEDRXP ,	 
 MAT_IND_CCIOTOPTI ,	 
 MAT_IND_CABTSRI ,	 
 MAT_IND_CIREGU ,	 
 MAT_IND_AMRCODEC ,	 
 MAT_IND_CNEC_ESM ,	 
 MAT_IND_ATREADY ,	 
 MAT_IND_PLMNLIST ,	 
 MAT_IND_WIFICELLINFO ,	 
	 
	 
	 
	 
	 
 MAT_CWRITESIM ,	 
	 
 MAT_Q_QPOWD ,	 
	 
	 
	 
 MAT_Q_I ,	 
 MAT_Q_E ,	 
 MAT_Q_Z ,	 
	 
 MAT_Q_IPR ,	 
 MAT_Q_CBAUD ,	 
 MAT_Q_IFC ,	 
 MAT_Q_QSCLK ,	 
	 
 MAT_Q_QNETDEVCTL ,	 
 MAT_Q_QDBGCFG ,	 
	 
 MAT_Q_QENGINFO ,	 
	 
	 
 MAT_Q_EGMR ,	 
 MAT_Q_QGMR ,	 
	 
	 
	 
	 
	 
 MAT_Q_CUSTOMERAREA ,	 
 MAT_Q_CVERSION ,	 
 MAT_Q_CSUB ,	 
 MAT_Q_QINF ,	 
 MAT_Q_QURCCFG ,	 
 MAT_Q_AMP_V ,	 
 MAT_Q_AMP_W ,	 
 MAT_Q_CMEE ,	 
 MAT_Q_CFUN ,	 
 MAT_Q_CSCS ,	 
 MAT_Q_CGMI ,	 
 MAT_Q_CGMM ,	 
 MAT_Q_CGMR ,	 
 MAT_Q_CGSN ,	 
 MAT_Q_GSN ,	 
 MAT_Q_QGSN ,	 
 MAT_Q_QCCID ,	 
 MAT_Q_CCID ,	 
 MAT_Q_ICCID ,	 
 MAT_Q_GMI ,	 
 MAT_Q_GMM ,	 
 MAT_Q_GMR ,	 
 MAT_Q_QCFG ,	 
 MAT_Q_QINDCFG ,	 
 MAT_Q_QNWINFO ,	 
 MAT_Q_CSQ ,	 
 MAT_Q_QCSQ ,	 
 MAT_Q_CGREG ,	 
 MAT_Q_CEREG ,	 
 MAT_Q_CREG ,	 
 MAT_Q_CGEREP ,	 
 MAT_Q_CTZR ,	 
 MAT_Q_QENG ,	 
 MAT_Q_QLTS ,	 
 MAT_Q_QGDCNT ,	 
 MAT_Q_QAUGDCNT ,	 
 MAT_Q_QOEM ,	 
 MAT_Q_SMONC ,	 
 MAT_Q_QGPAPN ,	 
 MAT_Q_QRFTESTMODE ,	 
 MAT_Q_QRFTEST ,	 
 MAT_Q_QRXFTM ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MAT_Q_QICSGP ,	 
 MAT_Q_QIACT ,	 
 MAT_Q_QIACTEX ,	 
 MAT_Q_QIDEACT ,	 
 MAT_Q_QIDEACTEX ,	 
 MAT_Q_QIDNSCFG ,	 
 MAT_Q_QIDNSGIP ,	 
 MAT_Q_QICFG ,	 
 MAT_Q_QIOPEN ,	 
 MAT_Q_QIRD ,	 
 MAT_Q_QISEND ,	 
 MAT_Q_QISENDEX ,	 
 MAT_Q_QISWTMD ,	 
 MAT_Q_QISTATE ,	 
 MAT_Q_QICLOSE ,	 
 MAT_Q_QISDE ,	 
 MAT_Q_QPING ,	 
	 
 MAT_Q_QIACCEPT ,	 
	 
 MAT_Q_QISWCMD ,	 
	 
 MAT_Q_QNTP ,	 
 MAT_Q_QIGETERROR ,	 
	 
 MAT_Q_QSSLCFG ,	 
 MAT_Q_QSSLOPEN ,	 
 MAT_Q_QSSLRECV ,	 
 MAT_Q_QSSLSEND ,	 
 MAT_Q_QSSLCLOSE ,	 
 MAT_Q_QSSLSTATE ,	 
	 
 MAT_Q_QDMCFG ,	 
 MAT_Q_QDMCFGEX ,	 
 MAT_Q_QDMSTART ,	 
 MAT_Q_QDMSTOP ,	 
 MAT_Q_QDMSTAT ,	 
 MAT_Q_QMTCFG ,	 
 MAT_Q_QMTOPEN ,	 
 MAT_Q_QMTCLOSE ,	 
 MAT_Q_QMTCONN ,	 
 MAT_Q_QMTDISC ,	 
 MAT_Q_QMTSUB ,	 
 MAT_Q_QMTUNS ,	 
 MAT_Q_QMTPUB ,	 
 MAT_Q_QMTPUBEX ,	 
 MAT_Q_QMTRECV ,	 
	 
 MAT_Q_QFTPCFG ,	 
 MAT_Q_QFTPOPEN ,	 
 MAT_Q_QFTPCLOSE ,	 
 MAT_Q_QFTPCWD ,	 
 MAT_Q_QFTPPWD ,	 
 MAT_Q_QFTPSIZE ,	 
 MAT_Q_QFTPDEL ,	 
 MAT_Q_QFTPMKDIR ,	 
 MAT_Q_QFTPRMDIR ,	 
 MAT_Q_QFTPRENAME ,	 
 MAT_Q_QFTPSTAT ,	 
 MAT_Q_QFTPMDTM ,	 
 MAT_Q_QFTPPUT ,	 
 MAT_Q_QFTPGET ,	 
 MAT_Q_QFTPLIST ,	 
 MAT_Q_QFTPNLST ,	 
 MAT_Q_QFTPMLSD ,	 
 MAT_Q_QFTPLEN ,	 
 MAT_Q_QHTTPCFG ,	 
 MAT_Q_QHTTPURL ,	 
 MAT_Q_QHTTPURLEX ,	 
 MAT_Q_QHTTPGET ,	 
 MAT_Q_QHTTPGETEX ,	 
 MAT_Q_QHTTPPOST ,	 
 MAT_Q_QHTTPPOSTFILE ,	 
 MAT_Q_QHTTPPUT ,	 
 MAT_Q_QHTTPPUTFILE ,	 
 MAT_Q_QHTTPREAD ,	 
 MAT_Q_QHTTPREADFILE ,	 
 MAT_Q_QHTTPSTOP ,	 
 MAT_Q_QLBS ,	 
 MAT_Q_QLBSCFG ,	 
	 
 MAT_Q_QHTTPCFGEX ,	 
 MAT_Q_QHTTPSEND ,	 
	 
 MAT_Q_QLBSDEBUG ,	 
 MAT_Q_QCERT ,	 
 MAT_Q_QSVN ,	 
 MAT_Q_QIOTRPT ,	 
 MAT_Q_QIOTRPTCFG ,	 
 MAT_Q_QGPIOS ,	 
 MAT_Q_QGPIOR ,	 
 MAT_Q_QGPIOW ,	 
 MAT_Q_MRDBACKUP ,	 
 MAT_Q_QCMGR ,	 
 MAT_Q_QCMGS ,	 
	 
 MAT_Q_QINISTAT ,	 
 MAT_Q_QPINC ,	 
 MAT_Q_QSIMDET ,	 
 MAT_Q_QSIMSTAT ,	 
 MAT_Q_QAUDLOOP ,	 
 MAT_Q_QAUDPLAYSPL ,	 
	 
 MAT_Q_QAUDSW ,	 
	 
	 
	 
	 
	 
 MAT_Q_QAUTHCODE ,	 
 MAT_Q_UID ,	 
	 
 MAT_Q_QLICENSE ,	 
 MAT_Q_QLICENSEINFO ,	 
	 
	 
	 
 MAT_Q_QAUDHSDET ,	 
	 
	 
 MAT_Q_QPSND ,	 
	 
	 
	 
	 
 MAT_Q_QTTS ,	 
	 
	 
	 
	 
 MAT_Q_QAUDPLAY ,	 
 MAT_Q_QAUDSTOP ,	 
 MAT_Q_QAUDRD ,	 
 MAT_Q_QSIDET ,	 
 MAT_Q_QMIC ,	 
 MAT_Q_CLVL ,	 
 MAT_Q_QRXGAIN ,	 
 MAT_Q_QAUDMUT ,	 
	 
 MAT_Q_CLEVLE ,	 
 MAT_Q_AUDUPDATE ,	 
 MAT_Q_QEEC ,	 
 MAT_Q_QCODECTABLE ,	 
 MAT_Q_QEQTABLE ,	 
 MAT_Q_QTXCODECTABLE ,	 
 MAT_Q_QTXDSPGAIN ,	 
 MAT_Q_QDSPTABLE ,	 
	 
 MAT_Q_QAUDINIT ,	 
 MAT_Q_QAUDMOD ,	 
 MAT_Q_QIIC ,	 
 MAT_Q_QTTSETUP ,	 
 MAT_Q_QTTSMODE ,	 
 MAT_Q_QDAI ,	 
 MAT_Q_QFLDS ,	 
	 
 MAT_Q_QDTMFVOL ,	 
 MAT_Q_QLDTMF ,	 
	 
	 
 MAT_Q_QWDTMF ,	 
	 
	 
 MAT_Q_QTONEDET ,	 
	 
	 
 MAT_Q_QLTONE ,	 
	 
 MAT_Q_QFLST ,	 
 MAT_Q_QFDEL ,	 
 MAT_Q_QFOPEN ,	 
 MAT_Q_QFREAD ,	 
 MAT_Q_QFWRITE ,	 
 MAT_Q_QFSEEK ,	 
	 
	 
 MAT_Q_QFREADDELYSET ,	 
	 
 MAT_Q_QPTABLEVSTART ,	 
 MAT_Q_QFPOSITION ,	 
 MAT_Q_QFTUCAT ,	 
	 
	 
	 
 MAT_Q_QFCLOSE ,	 
	 
 MAT_Q_QFUPL ,	 
 MAT_Q_QFDWL ,	 
 MAT_Q_QFRENAME ,	 
	 
 MAT_Q_QFTCMD ,	 
	 
	 
 MAT_Q_QFMD5 ,	 
	 
 MAT_Q_QFSIZE ,	 
 // MAT_Q_QFOTADL ,	 
	 
	 
	 
	 
 MAT_Q_QDUMPCFG ,	 
 MAT_Q_QFLASH ,	 
 MAT_Q_QVOLCFG ,	 
 MAT_Q_QPMICCFG ,	 
 MAT_Q_QGPIOCFG ,	 
 MAT_Q_QFOTAUPDATE ,	 
 MAT_Q_QFATTEST ,	 
 MAT_Q_QLEDSTAT ,	 
 MAT_Q_QLEDCFG ,	 
	 
	 
	 
 MAT_Q_QADC ,	 
 MAT_Q_QWSETMAC ,	 
 MAT_Q_QTEMP ,	 
 MAT_Q_FLASH_TEST ,	 
 MAT_Q_FALSH_TEST ,	 
 MAT_Q_QVSIM ,	 
 MAT_Q_QMMSCFG ,	 
 MAT_Q_QMMSEDIT ,	 
 MAT_Q_QMMSEND ,	 
	 
	 
	 
 MAT_Q_CINDCFG ,	 
	 
 MAT_Q_QGPIOEXT ,	 
	 
	 
	 
	 
	 
	 
	 
 MAT_Q_QCUSDCVT ,	 
	 
	 
 MAT_Q_REMOTEWAKE ,	 
	 
	 
 MAT_Q_CWLAPOPT ,	 
 MAT_Q_CWLAP ,	 
 MAT_Q_CWMODE ,	 
	 
	 
 MAT_Q_QCELLSELECTCFG ,	 
	 
 MAT_Q_SIMPOLLCFG ,	 
	 
	 
 MAT_Q_CELL ,	 
 MAT_Q_CELLEX ,	 
	 
 MAT_Q_QIPV6CONFIG ,	 
	 
	 
 MAT_Q_QERASECOUNT ,	 
	 
	 
 MAT_Q_QISENDX ,	 
	 
	 
 MAT_Q_QISENDCRC ,	 
	 
 MAT_Q_RSRP ,	 
	 
	 
 MAT_Q_JAMDET_ENABLE ,	 
 MAT_Q_JAMDET_CFG ,	 
	 
	 
 MAT_Q_SAWCFG ,	 
	 
 MAT_Q_QPAGUPDATE ,	 
	 
	 
 MAT_Q_QCELLINFOEX ,	 
 MAT_Q_QCELLINFO ,	 
	 
 MAT_Q_GPIOCTRL ,	 
	 
	 
 MAT_Q_QNVFD ,	 
	 
	 
 MAT_Q_BLACKCELL ,	 
 MAT_Q_BLACKCELLCFG ,	 
	 
	 
 MAT_Q_QLWPINGCFG ,	 
	 
	 
	 
	 
 MAT_Q_QIMSXML ,	 
	 
 MAT_Q_QSCLKEX ,	 
 MAT_Q_QSCLKEXCFG ,	 
	 
	 
 MAT_Q_QUESTAT ,	 
	 
	 
	 
 MAT_Q_BLACKCELLEX ,	 
 MAT_Q_BLACKCELLCFGEX ,	 
 MAT_Q_BLACKCELLWEIGHT ,	 
 MAT_Q_BLACKLWIPCFG ,	 
	 
	 
 MAT_Q_BLACKEXTAND ,	 
	 
	 
	 
	 
	 
 MAT_Q_QTESTFLAG ,	 
	 
	 
 MAT_Q_QNWCFG ,	 
	 
	 
 MAT_Q_QNETWORKSTATUS ,	 
	 
 MAT_Q_QNWLOCK ,	 
	 
 MAT_Q_QAUTOAPN ,	 
 MAT_Q_QAUTOAPNURC ,	 
	 
	 
	 
	 
	 
 MAT_Q_NETDUALCHCFG ,	 
	 
 MAT_Q_QMNCLK ,	 
	 
 MAT_Q_QCEER ,	 
	 
 MAT_Q_COOSPPT ,	 
	 
 NUM_OF_MAT_CMD	 
 } MATCmdType , MATRspType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_SVC_0 ,	 
 MAT_SVC_1 ,	 
 MAT_SVC_2 ,	 
 MAT_SVC_3 ,	 
 MAT_SVC_4 ,	 
 MAT_SVC_5 ,	 
 MAT_SVC_6 ,	 
 MAT_SVC_7 ,	 
 MAT_SVC_8 ,	 
 MAT_SVC_9 ,	 
 MAT_SVC_10 ,	 
 MAT_SVC_11 ,	 
 MAT_SVC_12 ,	 
 MAT_SVC_13 ,	 
 MAT_SVC_14 ,	 
 MAT_SVC_15 ,	 
 MAT_SVC_16 ,	 
 MAT_SVC_17 ,	 
 MAT_SVC_18 ,	 
 MAT_SVC_19 ,	 
 MAT_SVC_20 ,	 
 MAT_SVC_21 ,	 
 MAT_SVC_22 ,	 
 MAT_SVC_23 ,	 
 MAT_SVC_24 ,	 
 MAT_SVC_25 ,	 
 MAT_SVC_26 ,	 
 MAT_SVC_27 ,	 
 MAT_SVC_28 ,	 
 MAT_SVC_29 ,	 
 MAT_SVC_30 ,	 
 MAT_SVC_31 ,	 
 MAT_SVC_32 ,	 
 MAT_SVC_33 ,	 
 MAT_SVC_34 ,	 
 MAT_SVC_35 ,	 
 MAT_SVC_36 ,	 
 MAT_SVC_37 ,	 
 MAT_SVC_38 ,	 
 MAT_SVC_39 ,	 
 MAT_SVC_40 ,	 
 MAT_SVC_41 ,	 
 MAT_SVC_42 ,	 
 MAT_SVC_43 ,	 
 MAT_SVC_44 ,	 
 MAT_SVC_45 ,	 
 MAT_SVC_46 ,	 
 MAT_SVC_47 ,	 
 MAT_SVC_48 ,	 
 MAT_SVC_49 ,	 
 MAT_SVC_50 ,	 
 MAT_SVC_51 ,	 
 MAT_SVC_52 ,	 
 MAT_SVC_53 ,	 
 MAT_SVC_54 ,	 
 MAT_SVC_55 ,	 
 MAT_SVC_56 ,	 
 MAT_SVC_57 ,	 
 MAT_SVC_58 ,	 
 MAT_SVC_59 ,	 
 MAT_SVC_60 ,	 
 MAT_SVC_61 ,	 
 MAT_SVC_62 ,	 
 MAT_SVC_63 ,	 
 NUM_OF_MAT_SVC	 
 } MATSvcId;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_SIM_0 ,	 
 MAT_SIM_1 ,	 
 NUM_OF_MAT_SIM	 
 } MATSimId;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 MAT_DATA_TYPE_DECIMAL ,	 
 MAT_DATA_TYPE_STRING ,	 
 MAT_DATA_TYPE_SET ,	 
 MAT_DATA_TYPE_RANGE ,	 
 } MATDataType;

//ICAT EXPORTED STRUCT 
 struct MATParameterRange 
 {	 
 int min ;	 
 int max ;	 
 };

//ICAT EXPORTED STRUCT 
 struct MATParameterItem_T ; 
 // ICAT EXPORTED STRUCT 
 typedef union MATDataValue_U {	 
 unsigned int decimal ;	 
 char *string_p ;	 
 struct MATParameterItem_T *set_p ;	 
 struct MATParameterRange range ;	 
 } MATDataValue;

//ICAT EXPORTED STRUCT 
 typedef struct MATParameter_T 
 {	 
 MATDataType type ;	 
 BOOL is_default ;	 
 MATDataValue value ;	 
 } MATParameter;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_RC_NULL ,	 
 MAT_RC_OK , // OK will be sent	 
 MAT_RC_ERROR , // ERROR will be sent	 
 MAT_RC_CME_ERROR , // CME ERROR will be sent	 
 MAT_RC_CMS_ERROR , // CMS ERROR will be sent	 
 MAT_RC_RESERVED	 
 } MATResultCode;

//ICAT EXPORTED STRUCT 
 typedef struct MATParameterItem_T 
 {	 
 UINT16 max_para_number ;	 
 UINT16 num_Retparameters ;	 
 MATParameter* RetPara ;	 
 } MATParameterItem , MATParameterSet;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_RET_CONFIRM ,	 
 MAT_RET_INDICATION	 
 } MATRetType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_PAR_RESULT_CODE_OK ,	 
 MAT_PAR_RESULT_CODE_ERROR	 
 } MATParseResultCode;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_RET_SUCCESS ,	 
 MAT_RET_TOO_MANY_PARAMETERS ,	 
 MAT_RET_CURRENT_CH_HAS_CMD_PROCESSING ,	 
 MAT_RET_PARA_TYPE_UNSUPPORT ,	 
 MAT_RET_NULL_CLINET_TAG_POINTER ,	 
 MAT_RET_NUM_PARA_ERROR ,	 
 MAT_RET_PARA_TYPE_ERROR ,	 
 MAT_RET_HANDLER_FAILURE ,	 
 MAT_RET_FIND_FREE_CHANNEL_ERROR	 
 } MATRecvRetType;

//ICAT EXPORTED STRUCT 
 typedef struct MATReturnPara_T 
 {	 
 MATResultCode resultCode ;	 
 UINT16 numItems ;	 
 MATParameterItem* RetParaItems ;	 
 MATRspType cmd_type ;	 
 } MATReturnPara;

typedef union utlAtDataValue_U {
 unsigned int decimal ;
 unsigned int hexadecimal ;
 unsigned int binary ;
 char *string_p ;
 char *qstring_p ;
 char *dial_string_p ;
 } utlAtDataValue_T , *utlAtDataValue_P ;
typedef const utlAtParameterValue_T *utlAtParameterValue_P2c ;
typedef const utlAtParameter_T *utlAtParameter_P2c ;
typedef const utlAtDceIoConfig_T *utlAtDceIoConfig_P2c ;
typedef const utlAtSoundConfig_T *utlAtSoundConfig_P2c ;
typedef utlReturnCode_T ( *utlAtGetParameterFunction_P ) ( const utlAtParameterOp_T op , const char *command_name_p , const utlAtParameterValue_P2c parameter_values_p , const size_t num_parameters , const char *info_text_p , unsigned int *xid_p , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtSetParameterFunction_P ) ( const utlAtParameterOp_T op , const char *command_name_p , const utlAtParameterValue_P2c parameter_values_p , const size_t num_parameters , const char *info_text_p , unsigned int *xid_p , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtDceIoConfigFunction_P ) ( const utlAtDceIoConfig_P2c dce_io_config_p , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtSoundConfigFunction_P ) ( const utlAtSoundConfig_P2c sound_config_p , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtSParameterFunction_P ) ( const unsigned int parameter_num , const unsigned int parameter_value , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtSaveDialStringFunction_P ) ( const char *location_name_p , const char *dial_string_p , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtRetrieveDialStringFunction_P ) ( const char **location_name_pp , const char **dial_string_pp , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtReplyFunction_P ) ( const char *string_p , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtTxLineDataFunction_P ) ( const unsigned char *octets_p , const size_t n , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtDriverRequestFunction_P ) ( const utlAtParser_P parser_p , const utlAtDriverRequest_T request , void *arg_p , ... ) ;
typedef utlReturnCode_T ( *utlAtCommandSyntaxFunction_P ) ( const utlAtParameterOp_T op , const char *command_name_p , const utlAtParameterValue_P2c parameter_values_p , const size_t num_parameters , const char *info_text_p , unsigned int *xid_p , void *arg_p ) ;
typedef unsigned int ( *utlAtGetAtcmdTimeoutValueFunction_P ) ( const utlAtCommand_P2c cmd_p , const utlAtAsyncOp_T op ) ;
typedef int ( *utlAtcmdTimeoutErrorFunction_P ) ( unsigned int atHandle ) ;
typedef void ( *utlAtcmdContinuousTimeoutFunction_P ) ( void ) ;
typedef int ( *utlAtParserTriggerFunction_P ) ( const utlAtParser_P parser_p ) ;
typedef void ( *utlSetAutoAnswerDelay_P ) ( void *arg_p , unsigned int delay_seconds ) ;
typedef void ( *utlGetAutoAnswerDelay_P ) ( void *arg_p , unsigned short *delay_seconds ) ;
typedef utlReturnCode_T ( *utlSendToProxy_P ) ( const char *command_name_p , const utlAtParameterOp_T op , const char *parameters_string_p , unsigned int *xid_p , void *arg_p ) ;
typedef unsigned int ( *utlIsProxyReq_P ) ( const char *cmdName , utlAtParameterOp_T cmdOp , unsigned int parserId ) ;
typedef void ( *utlIncProxyTOCounter_P ) ( unsigned int incValue ) ;
typedef const utlAtCommand_T *utlAtCommand_P2c ;
typedef const utlAtDialStringOptions_T *utlAtDialStringOptions_P2c ;
typedef const utlAtAsyncResponse_T *utlAtAsyncResponse_P2c ;
typedef const utlAtAsyncResponses_T *utlAtAsyncResponses_P2c ;
typedef const utlAtParser_T *utlAtParser_P2c ;
typedef void ( *CommandAddress ) ( void ) ;
typedef char* CommandProto ;
typedef const char * DiagDBVersion ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PROTOCOL_TYPE_0 = 0 ,	 
 MAX_PROTOCOL_TYPES	 
 } ProtocolType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 BOOL bEnabled ; // enable / disable the trace logging feature	 
 ProtocolType eProtocolType ; // protocol type for communication with ICAT , currently only protocol type 0 is supported	 
 UINT16 nMaxDataPerTrace ; // for each trace , what is the maximum data length to accompany the trace , in protocol type 0 , this is relevant only to DSP messages	 
 } DiagLoggerDefs;

typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef unsigned long long UINT64 ;
typedef unsigned long TimeIn32KhzUnit ;
typedef void ( *TickCallbackPtr ) ( UINT32 ) ;
typedef TimeIn32KhzUnit ( *SuspendCallbackPtr ) ( void ) ;
typedef void ( *PrepareTimeCallbackPtr ) ( void ) ;
typedef void ( *GPIOCallback ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_PIN_NOT_ASSIGNED = -1 ,	 
	 
 GPIO_PIN_0=0 , GPIO_PIN_1 , GPIO_PIN_2 , GPIO_PIN_3 , GPIO_PIN_4 , GPIO_PIN_5 , GPIO_PIN_6 , GPIO_PIN_7 ,	 
 GPIO_PIN_8 , GPIO_PIN_9 , GPIO_PIN_10 , GPIO_PIN_11 , GPIO_PIN_12 , GPIO_PIN_13 , GPIO_PIN_14 , GPIO_PIN_15 ,	 
 GPIO_PIN_16 , GPIO_PIN_17 , GPIO_PIN_18 , GPIO_PIN_19 , GPIO_PIN_20 , GPIO_PIN_21 , GPIO_PIN_22 , GPIO_PIN_23 ,	 
 GPIO_PIN_24 , GPIO_PIN_25 , GPIO_PIN_26 , GPIO_PIN_27 , GPIO_PIN_28 , GPIO_PIN_29 , GPIO_PIN_30 , GPIO_PIN_31 ,	 
 GPIO_PIN_32 ,	 
 // #ifndef SILICON_PV2	 
 GPIO_PIN_33 , GPIO_PIN_34 , GPIO_PIN_35 , GPIO_PIN_36 , GPIO_PIN_37 , GPIO_PIN_38 , GPIO_PIN_39 ,	 
 GPIO_PIN_40 , GPIO_PIN_41 , GPIO_PIN_42 , GPIO_PIN_43 , GPIO_PIN_44 , GPIO_PIN_45 , GPIO_PIN_46 , GPIO_PIN_47 ,	 
 GPIO_PIN_48 , GPIO_PIN_49 , GPIO_PIN_50 , GPIO_PIN_51 , GPIO_PIN_52 , GPIO_PIN_53 , GPIO_PIN_54 , GPIO_PIN_55 ,	 
 GPIO_PIN_56 , GPIO_PIN_57 , GPIO_PIN_58 , GPIO_PIN_59 , GPIO_PIN_60 , GPIO_PIN_61 , GPIO_PIN_62 , GPIO_PIN_63 ,	 
 // #endif // _TAVOR_HARBELL_	 
	 
 // #if 1 // quectel define for build defined ( GPIO_128_ENTRIES )	 
 GPIO_PIN_64 , GPIO_PIN_65 , GPIO_PIN_66 , GPIO_PIN_67 , GPIO_PIN_68 , GPIO_PIN_69 , GPIO_PIN_70 , GPIO_PIN_71 ,	 
 GPIO_PIN_72 , GPIO_PIN_73 , GPIO_PIN_74 , GPIO_PIN_75 , GPIO_PIN_76 , GPIO_PIN_77 , GPIO_PIN_78 , GPIO_PIN_79 ,	 
 GPIO_PIN_80 , GPIO_PIN_81 , GPIO_PIN_82 , GPIO_PIN_83 , GPIO_PIN_84 , GPIO_PIN_85 , GPIO_PIN_86 , GPIO_PIN_87 ,	 
 GPIO_PIN_88 , GPIO_PIN_89 , GPIO_PIN_90 , GPIO_PIN_91 , GPIO_PIN_92 , GPIO_PIN_93 , GPIO_PIN_94 , GPIO_PIN_95 ,	 
 GPIO_PIN_96 , GPIO_PIN_97 , GPIO_PIN_98 , GPIO_PIN_99 , GPIO_PIN_100 , GPIO_PIN_101 , GPIO_PIN_102 , GPIO_PIN_103 ,	 
 GPIO_PIN_104 , GPIO_PIN_105 , GPIO_PIN_106 , GPIO_PIN_107 , GPIO_PIN_108 , GPIO_PIN_109 , GPIO_PIN_110 , GPIO_PIN_111 ,	 
 GPIO_PIN_112 , GPIO_PIN_113 , GPIO_PIN_114 , GPIO_PIN_115 , GPIO_PIN_116 , GPIO_PIN_117 , GPIO_PIN_118 , GPIO_PIN_119 ,	 
 GPIO_PIN_120 , GPIO_PIN_121 , GPIO_PIN_122 , GPIO_PIN_123 , GPIO_PIN_124 , GPIO_PIN_125 , GPIO_PIN_126 , GPIO_PIN_127 ,	 
 // #endif // INTEL_2CHIP_PLAT_BVD	 
 GPIO_MAX_AMOUNT_OF_PINS	 
	 
	 
	 
 } GPIO_PinNumbers;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_RC_OK = 1 ,	 
	 
 GPIO_RC_INVALID_PORT_HANDLE = -100 ,	 
 GPIO_RC_NOT_OUTPUT_PORT ,	 
 GPIO_RC_NO_TIMER ,	 
 GPIO_RC_NO_FREE_HANDLE ,	 
 GPIO_RC_AMOUNT_OUT_OF_RANGE ,	 
 GPIO_RC_INCORRECT_PORT_SIZE ,	 
 GPIO_RC_PORT_NOT_ON_ONE_REG ,	 
 GPIO_RC_INVALID_PIN_NUM ,	 
 GPIO_RC_PIN_USED_IN_PORT ,	 
 GPIO_RC_PIN_NOT_FREE ,	 
 GPIO_RC_PIN_NOT_LOCKED ,	 
 GPIO_RC_NULL_POINTER ,	 
 GPIO_RC_PULLED_AND_OUTPUT ,	 
 GPIO_RC_INCORRECT_PORT_TYPE ,	 
 GPIO_RC_INCORRECT_TRANSITION_TYPE ,	 
 GPIO_RC_INCORRECT_DEBOUNCE ,	 
 GPIO_RC_INCORRECT_DIRECTION ,	 
 GPIO_RC_INCORRECT_INIT_VALUE ,	 
 GPIO_RC_INTC_ERROR ,	 
 GPIO_RC_PRM_ERROR ,	 
 GPIO_RC_PIN_LOCKED ,	 
 } GPIO_ReturnCode;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_PIN_FREE_FOR_USE = 0 ,	 
 GPIO_PIN_USE_IN_PORT ,	 
 GPIO_PIN_USE_IN_INTERRUPT ,	 
 GPIO_PIN_USE_IN_PORT_WITH_INTERRUPT ,	 
 GPIO_PIN_LOCKED	 
 } GPIO_PinUsage;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 GPIO_PinUsage pinUsage ;	 
 GPIOPinDirection direction ;	 
 } GPIO_PinStatus;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_INITIAL_VALUE_NO_CHANGE = 0 ,	 
 GPIO_INITIAL_VALUE_LOW=0 ,	 
 GPIO_INITIAL_VALUE_HIGH	 
 } GPIO_BitInitialValue;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_PULL_UP_DOWN_DISABLE = 0 ,	 
 GPIO_PULL_UP_ENABLE ,	 
 GPIO_PULL_DOWN_ENABLE	 
 } GPIO_PullUpDown;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 GPIO_PinNumbers pinNumber ;	 
 GPIOPinDirection direction ;	 
 GPIOTransitionType transitionType ;	 
 GPIO_Debounce debounce ;	 
 GPIOPullUpDown pullUpDown ;	 
 GPIO_BitInitialValue initialValue ;	 
 } GPIO_PinConfiguration;

typedef void ( *GPIO_ISR ) ( void ) ;
typedef UINT32 INTC_InterruptPriorityTable [ MAX_INTERRUPT_CONTROLLER_SOURCES ] ;
typedef UINT32 INTC_InterruptInfo ;
typedef void ( *INTC_ISR ) ( INTC_InterruptInfo interruptInfo ) ;
typedef void ( *PMCNotifyEventFunc ) ( UINT64 eventRegs ) ;
typedef void ( *PMCGetStatusNotifyFunc ) ( UINT16 status ) ;
typedef void ( *PMCReadCallback ) ( UINT8 *dataBuffPtr , UINT16 dataSize , UINT16 userId ) ;
typedef void ( *PMCWriteCallback ) ( UINT16 dataBuffPtr ) ;
typedef void ( *PMCGetGPADCValueNotifyFunc ) ( PMC_adc_reg_t reg , UINT16 value ) ;
typedef void ( * ReadingCallback ) ( int ) ;
typedef void ( * LTETempReadingCallback ) ( unsigned short , unsigned short ) ;
typedef void ( * ReadingCallbackBoth ) ( BOOL , int , int ) ;
typedef union
 {
 UINT8 autoControl ;
 UINT8 autoControl2 ;
 UINT8 manControl ;
 } adcModeCntrl_t ;
typedef union
 {
 UINT64 all ;
 Registers_ts regs ;
 } PMCEvents ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 SHD_POWER_DOWN ,	 
 SHD_RESET ,	 
 SHD_GHOST ,	 
 SHD_SW_ERROR /* EEHandler triggered the reset */	 
 } ShutDownType_te;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 RR_NORMAL_POWER_ON = 0x00 , // default , not combined with others	 
 RR_WATCH_DOG_TIMEOUT = 0x01 ,	 
 RR_SOFTWARE_GENERATED = 0x02 ,	 
 RR_CHARGING_BATTERY = 0x04 ,	 
 RR_LOW_BATTERY = 0x08 ,	 
 RR_ALARM_POWER_ON = 0x10 ,	 
 RR_EXT_POWER_ON = 0x20	 
 } 
 StartupReason_te;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 RE_RTC_ALARM = 0x01	 
 } StartupExtInd_te;

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PMU_POR = 1 ,	 
 PMU_EMR ,	 
 PMU_WDTR = ( PMU_EMR+2 )	 
 } PMU_LastResetStatus;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_INT_IFC ,	 
 DIAG_EXT_IFC	 
 } DIAG_IF_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_DEV_USB ,	 
 DIAG_DEV_SD ,	 
 DIAG_DEV_FS ,	 
 DIAG_DEV_UART ,	 
 DIAG_DEV_SPI ,	 
 DIAG_DEV_NONE	 
 } DIAG_DEV_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 SULOG_DEV_USB ,	 
 SULOG_DEV_SD	 
 } SULOG_DEV_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 EEH_DUMP_DEV_USB_SD ,	 
 EEH_DUMP_DEV_SPI	 
 } EEH_DUMP_DEV_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_START_PS_OFF ,	 
 DIAG_START_PS_ON	 
 } DIAG_START_PS_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_UART_SPEED_115200 ,	 
 DIAG_UART_SPEED_460800 ,	 
 DIAG_UART_SPEED_921600 ,	 
 DIAG_UART_DISABLE	 
 } DIAG_UART_SPEED_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 DIAG_IF_TYPE useIntIf ; /* use internal interface or external interface */	 
 DIAG_UART_SPEED_TYPE useHighSpeedUART ; /* high speed UART ( 460800 ) or low speed UART ( 115200 ) */	 
 // DIAG_MEM_SWITCH diagMemSwitch ;	 
 BOOL GLFeatureFlag ;	 
 DIAG_START_PS_TYPE diagStartPS ;	 
 DIAG_DEV_TYPE diagDevType ;	 
 SULOG_DEV_TYPE sulogDevType ;	 
 EEH_DUMP_DEV_TYPE eehDumpDevType ;	 
 // DIAG_MEM_SWITCH diagMemSwitch ;	 
 BOOL usbUserMode ;	 
 } diagCfgDataS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 dbID ;	 
 UINT32 filterBitLength ;	 
 UINT32 reserved [ 6 ] ;	 
 } DIAG_Nvm_Filter_File_Header_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 LOG_DISABLE = 0x0 ,	 
 UART_LOG_ENABLE = 0x1 ,	 
 ACAT_LOG_ENABLE = 0x2	 
 } Log_ConfigE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MSG_DISABLE = 0x0 ,	 
 ACAT_MSG_ENABLE = 0x1	 
 } Msg_ConfigE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 RTI_LOG_DISABLE = 0x0 ,	 
 RTI_DUMP_ENABLE = 0x1 ,	 
 RTI_TASK_ENABLE = 0x2 ,	 
 RTI_MIPS_ENABLE = 0x3	 
 } RTI_ConfigE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 Log_ConfigE log_cfg ;	 
 Msg_ConfigE msg_cfg ;	 
 RTI_ConfigE rti_cfg ;	 
 } Log_ConfigS;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 YMODEM_DISABLE = 0x0 ,	 
 YMODEM_ENABLE = 0x1	 
 } Ymodem_Dump_config;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 Ymodem_Dump_config config ;	 
 } Ymodem_Dump_type;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* MIFI driver*/	 
 USB_GENERIC_MIFI_DRIVER = 0x0 ,	 
 USB_MARVELL_MIFI_DRIVER = 0x1 ,	 
 USB_ASR_MIFI_DRIVER = 0x2 ,	 
 USB_GENERIC_MOD_DRIVER = 0x10 ,	 
 USB_GENERIC_MOD_ECM_DRIVER = 0x12 ,	 
	 
 USB_CDC_ACM_ONLY_DRIVER = 0x13 ,	 
	 
 USB_DIAG_UAC_DRIVER = 0x14 ,	 
	 
 /* MBIM driver*/	 
 USB_MBIM_ONLY_DRIVER = 0x40 ,	 
 USB_MBIM_GENERIC_DRIVER = 0x41 ,	 
 USB_MBIM_MAX_DRIVER = 0x4F ,	 
	 
 /* Other driver*/	 
 USB_CDROM_ONLY_DRIVER = 0x91 ,	 
 USB_CDROM_DIAG_DRIVER = 0x92 ,	 
 USB_DIAG_ONLY_DRIVER = 0x93 ,	 
 USB_MODEM_ONLY_DRIVER = 0x94 ,	 
 USB_MODEM_DIAG_DRIVER = 0x95 ,	 
	 
 USB_MAX_DRIVER = 0xFF	 
 } Usb_driver_typeE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MASS_STORAGE_DISABLE = 0x0 ,	 
 MASS_STORAGE_ENABLE = 0x1	 
 } MassStorage_ConfigE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 USB_AUTO_INSTALL_DISABLE = 0x0 ,	 
 USB_AUTO_INSTALL_ENABLE = 0x1	 
 } Usb_auto_install_type;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 USB_OS_DETECT_DISABLE = 0x0 ,	 
 USB_OS_DETECT_ENABLE = 0x1	 
 } Usb_OS_detect_type;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 Usb_driver_typeE usb_driver ;	 
 MassStorage_ConfigE mass_storage ;	 
 Usb_auto_install_type auto_install ;	 
 Usb_OS_detect_type os_detect ;	 
 } Usb_DriverS;

typedef UINT8 UART_Activity ;
//ICAT EXPORTED STRUCT 
 typedef struct /* This is structure of the UART Configuration */ 
 {	 
 UART_OpMode opMode ; /* fifo mode , non fifo mode or DMA for basic interface*/	 
 UART_TriggerLevel triggerLevel ; /* the trigger level interrupt on 1 , 8 , 16 , 32 */	 
 UART_BaudRates baudRate ; /* the rate of the transmit and the receive up to 111520 ( default - 9600 ) .*/	 
 UART_WordLen numDataBits ; /* 5 , 6 , 7 , or 8 number of data bits in the UART data frame ( default - 8 ) . */	 
 UART_StopBits stopBits ; /* 1 , 1.500000 or 2 stop bits in the UART data frame ( default - 1 ) . */	 
 UART_ParityTBits parityBitType ; /* Even , Odd or no-parity bit type in the UART data frame ( default - Non ) . */	 
 UART_InterfaceType interfaceType ; /* number of interface that the UART driver supplies ( default - UART_IF_TYPE_L2 ) */	 
 BOOL modemSignal ; /* enable operate modem - TRUE , disable modem - FALSE */	 
 BOOL flowControl ; /* enable Auto flow Control - TRUE , disable Auto flow Control - FALSE */	 
 UINT8 sleepMode ; /* enable sleep mode - TRUE , more fine control - see UARTSleepMode enum */	 
 BOOL auto_baud ; /* enable auto_baud , auto-baud-rate detection within the UART ( default - FALSE ) */	 
 UART_SIRConfigure sirIrDA ;	 
 } UARTConfiguration;

//ICAT EXPORTED ENUM 
 typedef enum // change the order -1 to + 
 {	 
 UART_RC_OK = 1 , /* 1 - no errors */	 
	 
 UART_RC_PORT_NUM_ERROR = -100 , /* -100 - Error in the UART port number */	 
 UART_RC_NO_DATA_TO_READ , /* -99 - Eror no data to read from the FIFO UART */	 
 UART_RC_ILLEGAL_BAUD_RATE , /* -98 - Error in the UART Bayd Rate */	 
 UART_RC_UART_PARITY_BITS_ERROR , /* -97 - Error in parity bit */	 
 UART_RC_UART_ONE_STOP_BIT_ERROR , /* -96 - Error in one stop bit */	 
 UART_RC_ONE_HALF_OR_TWO_STOP_BIT_ERROR , /* -95 - Error in two stop bit */	 
 UART_RC_BAD_INTERFACE_TYPE , /* -94 - Error in the Interface Type */	 
 UART_RC_UART_NOT_AVAILABLE , /* -93 - Error in try to open UART that is open */	 
 UART_RC_NO_DATA_TO_WRITE , /* -92 - Error No data to writ the len = 0 */	 
 UART_RC_NOT_ALL_BYTE_WRITTEN , /* -91 - Error Not all the Byte write to the UART FIFO */	 
 UART_RC_ISR_ALREADY_BIND , /* -90 - Error try to bind ISR for Basic Interface */	 
 UART_RC_WRONG_ISR_UNBIND , /* -89 - Error in the UnBind ISR for Basic Interface */	 
 UART_RC_FIFO_NOT_EMPTY , /* -88 - Error , the UART FIFO not empty */	 
 UART_RC_UART_OPEN , /* -87 - Error try chance the configurr when the UART open */	 
 UART_RC_GPIO_ERR , /* -86 - Error in the Configure of the GPIO */	 
 UART_RC_IRDA_CONFIG_ERR , /* -85 - Illegal IrDA configuration */	 
 UART_RC_TX_DMA_ERR /* -84 - DMA TX Error */	 
 } UART_ReturnCode;

typedef void ( *UARTNotifyInterrupt ) ( UART_Port ) ;
typedef void ( *UsbLogPrint_t ) ( const char * , ... ) ;
typedef void ( *StateChangedCb ) ( UINT8 , INT32 , void * ) ;
//ICAT EXPORTED ENUM 
 enum 
 {	 
 SIM_0 ,	 
 SIM_1 ,	 
 NUM_OF_SIM	 
 };

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 CHANNEL_MMI ,	 
 CHANNEL_IMS ,	 
 NUM_OF_CHANNEL_TYPE	 
 } AT_CHANNEL_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct _TelAtpCtrl 
 {	 
 void *taskRef ;	 
 UINT32 iFd ;	 
 char *path ;	 
 UINT32 index ;	 
 TelMsgDataMode smsDataEntryMode ;	 
 BOOL bEnable ;	 
 BOOL bIsSinkMode ;	 
	 
 TelAtpPdpCtx pdpCtx ;	 
 TelAtpTftCtx tftCtx ;	 
	 
 UINT32 reqHandle ;	 
 UINT32 cnmaReply ; /* used in +CNMA */	 
 UINT32 smsOverNas ;	 
 UINT32 cnmaFlag ; // 0 -- AT+CNMA , 1 -- AT*CNMA	 
	 
 Quec_TelAtpDataEntry pTelAtpDataEntry ;	 
 void ( *cb ) ( void *obj , void* arg ) ;	 
	 
 } TelAtpCtrl;

typedef union
 {
 / / quec_ioctl_default_type pin_state ; / / dcd , ri state
 quec_pin_level_value_e pin_level ;
 } quec_ioctl_param ;
typedef void ( *USBDeviceTransactionCompletedNotifyFn ) ( USBDevice_EndpointE ,
 UINT8 * ,
 UINT32 ,
 BOOL ) ;
typedef void ( *USBDeviceStatusNotifyFn ) ( USBDevice_StatusE ) ;
typedef void ( *USBDeviceVendorClassRequestNotifyFn ) ( USB_SetupCmdS * ) ;
typedef void ( *USBDeviceEndpointZeroNotifyFn ) ( USB_SetupCmdS * ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointMultiTransmit ) ( USBDevice_EndpointE endpoint ,
 UINT32 numOfBuffers ,
 USBDevice_MultiTransmitListS *pMultiList ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointTransmit ) ( USBDevice_EndpointE endpoint ,
 UINT8 *pTxBuffer ,
 UINT32 txLength ,
 BOOL autoZLP ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointCancelTransmit ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointCancelReceive ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointReceiveCompleted ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointReceiveCompletedExt ) ( USBDevice_EndpointE endpoint ,
 UINT8 *pRxBuffer ,
 UINT32 next_packet_expected_length ,
 BOOL expect_zlp ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointReceive ) ( USBDevice_EndpointE endpoint ,
 UINT8 *pRxBuffer ,
 UINT32 length ,
 BOOL expect_zlp ) ;
typedef void ( *fpUSBDeviceVendorClassResponse ) ( UINT8 *pBuffer ,
 UINT16 bufferLength ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointAbort ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointClose ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointOpen ) ( USBDevice_EndpointE endpoint ,
 USBDevice_UsageTypeE usageType ,
 UINT8 dmaChannel ,
 UINT8 *pDescBuffer ,
 UINT16 descBufferLength ,
 USBDeviceTransactionCompletedNotifyFn transactionCompletedNotifyFn ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointStall ) ( USBDevice_EndpointE endpoint ) ;
typedef void ( *fpUSBDevicePhase2Init ) ( void ) ;
typedef BOOL ( *fpUSBDeviceIsControllerEnabled ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum CISGID {	 
 CI_SG_ID_FIRST=1 ,	 
 CI_SG_ID_CC = CI_SG_ID_FIRST ,	 
 CI_SG_ID_SS ,	 
 CI_SG_ID_MM ,	 
 CI_SG_ID_PB ,	 
 CI_SG_ID_SIM ,	 
 CI_SG_ID_MSG ,	 
 CI_SG_ID_PS ,	 
 CI_SG_ID_DAT ,	 
 CI_SG_ID_DEV ,	 
 CI_SG_ID_HSCSD ,	 
 CI_SG_ID_DEB ,	 
 CI_SG_ID_ATPI ,	 
 CI_SG_ID_PL ,	 
 CI_SG_ID_OAM ,	 
 CI_SG_ID_NEXTAVAIL /* This must always be the last entry in the list */	 
 } _CiServiceGroupId;

//ICAT EXPORTED ENUM 
 typedef enum CIRC {	 
 CIRC_SUCCESS=0 ,	 
 CIRC_FAIL ,	 
 CIRC_INTERLINK_FAIL , /* the link between application subsystem and communication subsystem is broken */	 
 CIRC_SH_NULL_CONFIRM_CB ,	 
 CIRC_SH_NULL_FREEREQMEM_CB ,	 
 CIRC_SH_INVALID_HANDLE ,	 
 CIRC_SH_INVALID_OPER ,	 
 CIRC_SH_NULL_REQPARAS ,	 
 CIRC_SG_INVALID_HANDLE ,	 
 CIRC_SG_RESERVED_PRIMID ,	 
 CIRC_SG_NULL_REQPARAS ,	 
 CIRC_SG_NULL_RSPPARAS ,	 
 CIRC_NUM_RESCODES	 
 } _CiReturnCode;

typedef UINT16 CiReturnCode ;
//ICAT EXPORTED ENUM 
 typedef enum CISHOPER {	 
 CI_SH_OPER_REGISTERSH = 0 ,	 
 CI_SH_OPER_DEREGISTERSH ,	 
 CI_SH_OPER_GETVERSION ,	 
 CI_SH_OPER_REGISTERSG ,	 
 CI_SH_OPER_DEREGISTERSG ,	 
 CI_SH_OPER_REGISTERDEFSG ,	 
 CI_SH_OPER_DEREGISTERDEFSG ,	 
 CI_SH_QUERYEXTENDED ,	 
 CI_SH_QUERYEXTENDEDSERVICEPRIM ,	 
 CI_SH_QUERYEXTENDEDSERVICEGROUP ,	 
 CI_SH_OPER_CIVERSION_NEGO_REQ ,	 
 CI_SH_OPER_CIVERSION_NEGO_CNF ,	 
 CI_SH_NUMOPERS	 
 } CiShOper;

typedef UINT8 CiBoolean ;
typedef unsigned char Boolean ;
typedef UINT8 CiServiceGroupID ;
typedef UINT16 CiPrimitiveID ;
typedef UINT32 CiServiceHandle ;
typedef UINT32 CiRequestHandle ;
typedef UINT32 CiIndicationHandle ;
typedef UINT32 CiShHandle ;
typedef UINT32 CiShOpaqueHandle ;
typedef UINT32 CiShRequestHandle ;
typedef UINT32 CiSgOpaqueHandle ;
typedef void ( *CiShConfirm ) ( CiShOpaqueHandle opShHandle , CiShOper oper , void* cnfParas , CiShRequestHandle opHandle ) ;
typedef void ( *CiConfirm ) ( CiSgOpaqueHandle opSgOpaqueHandle , CiServiceGroupID id , CiPrimitiveID primId , CiRequestHandle reqHandle , void* paras ) ;
typedef void ( *CiIndicate ) ( CiSgOpaqueHandle opSgOpaqueHandle , CiServiceGroupID id , CiPrimitiveID primId , CiIndicationHandle indHandle , void* paras ) ;
typedef void ( *CiShFreeReqMem ) ( CiShOpaqueHandle opShFreeHandle , CiShOper oper , void* reqParas ) ;
typedef void ( *CiShFreeCnfMem ) ( CiShOpaqueHandle opShFreeHandle , CiShOper oper , void* cnfParas ) ;
typedef void ( *CiSgFreeReqMem ) ( CiSgOpaqueHandle opSgFreeHandle , CiServiceGroupID id , CiPrimitiveID primId , void* reqParas ) ;
typedef void ( *CiSgFreeRspMem ) ( CiSgOpaqueHandle opSgFreeHandle , CiServiceGroupID id , CiPrimitiveID primId , void* rspParas ) ;
typedef void ( *CiSgFreeCnfMem ) ( CiSgOpaqueHandle opSgFreeHandle , CiServiceGroupID id , CiPrimitiveID primId , void* cnfParas ) ;
typedef void ( *CiSgFreeIndMem ) ( CiSgOpaqueHandle opSgFreeHandle , CiServiceGroupID id , CiPrimitiveID primId , void* indParas ) ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPrimList_struct {	 
 UINT16 size ; /* actual number of primitive IDs that are held in the pList */	 
 CiPrimitiveID primId [ 156 ] ;	 
 } CiPrimitiveList;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperRegisterShCnf_struct {	 
 CiReturnCode rc ;	 
 CiShHandle handle ;	 
 CiShOpaqueHandle opShFreeHandle ;	 
 CiShFreeCnfMem ciShFreeCnfMem ;	 
 } CiShOperRegisterShCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperDeregisterShCnf_struct {	 
 CiReturnCode rc ;	 
 } CiShOperDeregisterShCnf;

//ICAT EXPORTED STRUCTURE 
 typedef struct CiShOperGetVersionReq_struct {	 
 CiServiceGroupID id ;	 
 } CiShOperGetVersionReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperGetVersionCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceGroupID id ;	 
 UINT8 major ;	 
 UINT8 minor ;	 
 } CiShOperGetVersionCnf;

//ICAT EXPORTED STRUCTURE 
 typedef struct CiShOperRegisterDefaultSgReq_struct {	 
 CiSgOpaqueHandle opSgDefCnfHandle ;	 
 CiConfirm ciCnfDef ;	 
 CiIndicate ciIndDef ;	 
 CiSgOpaqueHandle opSgDefIndHandle ;	 
 } CiShOperRegisterDefaultSgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperRegisterDefaultSgCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceHandle defHandle ;	 
 CiSgOpaqueHandle opSgFreeDefCnfHandle ;	 
 CiSgFreeCnfMem ciSgFreeDefCnfMem ;	 
 CiSgOpaqueHandle opSgFreeDefIndHandle ;	 
 CiSgFreeIndMem ciSgFreeDefIndMem ;	 
 } CiShOperRegisterDefaultSgCnf;

//ICAT EXPORTED STRUCTURE 
 typedef struct CiShOperDeregisterDefaultSgReq_struct {	 
 CiServiceHandle defHandle ;	 
 } CiShOperDeregisterDefaultSgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperDeregisterDefaultSgCnf_struct {	 
 CiReturnCode rc ;	 
 } CiShOperDeregisterDefaultSgCnf;

//ICAT EXPORTED STRUCTURE 
 typedef struct CiShOperRegisterSgReq_struct {	 
 CiServiceGroupID id ;	 
 CiSgOpaqueHandle opSgCnfHandle ;	 
 CiConfirm ciConfirm ;	 
 CiSgOpaqueHandle opSgIndHandle ;	 
 CiIndicate ciIndicate ;	 
 CiSgOpaqueHandle opSgFreeReqHandle ;	 
 CiSgFreeReqMem ciSgFreeReqMem ;	 
 CiSgOpaqueHandle opSgFreeRspHandle ;	 
 CiSgFreeRspMem ciSgFreeRspMem ;	 
 } CiShOperRegisterSgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperRegisterSgCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceGroupID id ;	 
 CiServiceHandle handle ;	 
 CiSgOpaqueHandle opSgFreeCnfHandle ;	 
 CiSgFreeCnfMem ciSgFreeCnfMem ;	 
 CiSgOpaqueHandle opSgFreeIndHandle ;	 
 CiSgFreeIndMem ciSgFreeIndMem ;	 
 } CiShOperRegisterSgCnf;

//ICAT EXPORTED STRUCTURE 
 typedef struct CiShOperDeregisterSgReq_struct {	 
 CiServiceHandle handle ;	 
 } CiShOperDeregisterSgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperDeregisterSgCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceGroupID id ;	 
 } CiShOperDeregisterSgCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiShQueryExtendedReq_struct {	 
 CiServiceGroupID id ;	 
 } CiShQueryExtendedReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShQueryExtendedCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceGroupID id ;	 
 UINT16 mSize ;	 
 CiPrimitiveList ciPrimList ;	 
 } CiShQueryExtendedCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiShQueryExtendedServicePrimReq_struct {	 
 CiServiceGroupID id ;	 
 CiPrimitiveID primId ;	 
 } CiShQueryExtendedServicePrimReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShQueryExtendedServicePrimCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceGroupID id ;	 
 CiPrimitiveID primId ;	 
 CiBoolean supported ;	 
 } CiShQueryExtendedServicePrimCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiShQueryExtendedServiceGroupReq_struct {	 
 CiServiceGroupID id ;	 
 } CiShQueryExtendedServiceGroupReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShQueryExtendedServiceGroupCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceGroupID id ;	 
 CiBoolean supported ;	 
 } CiShQueryExtendedServiceGroupCnf;

typedef UINT16 CiVersion ;
//ICAT EXPORTED STRUCT 
 typedef struct CiShOperCIVersionNegoReq_struct 
 {	 
 UINT8 ccSuppVerNum ;	 
 UINT8 ssSuppVerNum ;	 
 UINT8 mmSuppVerNum ;	 
 UINT8 pbSuppVerNum ;	 
 UINT8 simSuppVerNum ;	 
 UINT8 msgSuppVerNum ;	 
 UINT8 psSuppVerNum ;	 
 UINT8 datSuppVerNum ;	 
 UINT8 devSuppVerNum ;	 
 UINT8 hscsdSuppVerNum ;	 
 UINT8 debSuppVerNum ;	 
 UINT8 atpiSuppVerNum ;	 
 UINT8 plSuppVerNum ;	 
 UINT8 oamSuppVerNum ;	 
 CiVersion ccSuppVer [ 10 ] ;	 
 CiVersion ssSuppVer [ 10 ] ;	 
 CiVersion mmSuppVer [ 10 ] ;	 
 CiVersion pbSuppVer [ 10 ] ;	 
 CiVersion simSuppVer [ 10 ] ;	 
 CiVersion msgSuppVer [ 10 ] ;	 
 CiVersion psSuppVer [ 10 ] ;	 
 CiVersion datSuppVer [ 10 ] ;	 
 CiVersion devSuppVer [ 10 ] ;	 
 CiVersion hscsdSuppVer [ 10 ] ;	 
 CiVersion debSuppVer [ 10 ] ;	 
 CiVersion atpiSuppVer [ 10 ] ;	 
 CiVersion plSuppVer [ 10 ] ;	 
 CiVersion oamSuppVer [ 10 ] ;	 
 } CiShOperCIVersionNegoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperCIVersionNegoCnf_struct 
 {	 
 CiReturnCode rc ;	 
 CiVersion ccVer ;	 
 CiVersion ssVer ;	 
 CiVersion mmVer ;	 
 CiVersion pbVer ;	 
 CiVersion simVer ;	 
 CiVersion msgVer ;	 
 CiVersion psVer ;	 
 CiVersion datVer ;	 
 CiVersion devVer ;	 
 CiVersion hscsdVer ;	 
 CiVersion debVer ;	 
 CiVersion atpiVer ;	 
 CiVersion plVer ;	 
 CiVersion oamVer ;	 
 } CiShOperCIVersionNegoCnf;

//ICAT EXPORTED ENUM 
 typedef enum CI_ADDR_NUMTYPE {	 
 CI_NUMTYPE_UNKNOWN = 0x00 , /* Unknown */	 
 CI_NUMTYPE_INTERNATIONAL= 0x01 , /* International Number */	 
 CI_NUMTYPE_NATIONAL = 0x02 , /* National Number */	 
 CI_NUMTYPE_NETWORK = 0x03 , /* Network Specific ( e.g. Operator Access ) */	 
 CI_NUMTYPE_DEDICATED = 0x04 , /* Dedicated Access Number , Short Code */	 
 CI_NUMTYPE_EXTENSION = 0x07 /* Reserved for Extension */	 
 /* << All other codes are reserved >> */	 
 } _CiAddrNumType;

typedef UINT8 CiAddrNumType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_ADDR_NUMPLAN {	 
 CI_NUMPLAN_UNKNOWN = 0x00 , /* Unknown */	 
 CI_NUMPLAN_E164_E163 = 0x01 , /* ISDN / Telephony ( E.164 / E.163 ) */	 
 CI_NUMPLAN_DATA_X121 = 0x03 , /* Data Numbering Plan ( X.121 ) */	 
 CI_NUMPLAN_TELEX_F69 = 0x04 , /* Telex Numbering Plan ( F.69 ) */	 
 CI_NUMPLAN_NATIONAL = 0x08 , /* National Numbering Plan */	 
 CI_NUMPLAN_PRIVATE = 0x09 , /* Private Numbering Plan */	 
 CI_NUMPLAN_RSVD_CTS = 0x0b , /* Reserved for CTS */	 
 CI_NUMPLAN_EXTENSION = 0x0f /* Reserved for Extension */	 
 /* << All other codes are reserved >> */	 
 } _CiAddrNumPlan;

typedef UINT8 CiAddrNumPlan ;
//ICAT EXPORTED STRUCT 
 typedef struct CiAddressType_struct {	 
 CiAddrNumType NumType ; /* TON: Type of Number */	 
 CiAddrNumPlan NumPlan ; /* NPI: Numbering Plan Identification */	 
 } CiAddressType;

//ICAT EXPORTED STRUCT 
 typedef struct CiAddressInfo_struct {	 
 CiAddressType AddrType ; /* Address Type Information */	 
 UINT8 Length ; /* Address Length in digits */	 
 UINT8 Digits [ 40 ] ; /* Address Digits */	 
	 
 } CiAddressInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiOptAddressInfo_struct {	 
 CiBoolean Present ; /* Address Info present? */	 
 CiAddressInfo AddressInfo ; /* Address Info */	 
 } CiOptAddressInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiSubaddrInfo_struct {	 
 CiBoolean Present ; /* Subaddress Info present? */	 
 UINT8 Type ; /* Subaddress Type */	 
 UINT8 Length ; /* Subaddress Length in characters */	 
 UINT8 Digits [ 40 ] ; /* Subaddress Digits */	 
 } CiSubaddrInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiNameInfo_struct {	 
 /*Added by cherryli@02.02.2015 for CQ84004 begin.*/	 
	 
	 
	 
 /*Added by cherryli@02.02.2015 for CQ84004 end.*/	 
 UINT8 Length ; /* Name Length in characters */	 
 UINT8 Name [ 40 ] ; /* Alphanumeric Name */	 
 } CiNameInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiOptNameInfo_struct {	 
 CiBoolean Present ; /* Name Info present? */	 
 CiNameInfo NameInfo ; /* Name Info */	 
 } CiOptNameInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiCallerInfo_struct {	 
 CiOptAddressInfo OptCallerNumber ; /* Optional Caller Phone Number */	 
 CiSubaddrInfo OptCallerSubaddr ; /* Optional Caller Subaddress */	 
 CiOptNameInfo OptCallerName ; /* Optional Caller Name ( Alpha Tag ) */	 
 } CiCallerInfo;

//ICAT EXPORTED ENUM 
 typedef enum SSI_CALL_STATUS {	 
 SSI_CS_CFU_ACTIVE = 0 , /* Unconditional Call Forwarding active */	 
 SSI_CS_CCF_ACTIVE , /* Conditional CF trigger ( s ) active */	 
 SSI_CS_FORWARDED , /* Call has been forwarded */	 
 SSI_CS_WAITING , /* Call is waiting */	 
 SSI_CS_CUG_CALL , /* Outgoing CUG call ( Index also present ) */	 
 SSI_CS_MO_BARRED , /* Outgoing ( MO ) calls are barred */	 
 SSI_CS_MT_BARRED , /* Incoming ( MT ) calls are barred */	 
 SSI_CS_CLIR_REJECTED , /* CLIR suppression rejected */	 
 SSI_CS_DEFLECTED , /* Call has been deflected */	 
 /* This one must always be last in the list! */	 
 SSI_NUM_CS /* Number of SSI Call Status values */	 
 } _CiSsiCallStatus;

typedef UINT8 CiSsiCallStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSsiNotifyInfo_struct {	 
 CiSsiCallStatus Status ; /* Call Status indicator */	 
 UINT8 CugIndex ; /* CUG Index ( if applicable ) */	 
 } CiSsiNotifyInfo;

//ICAT EXPORTED ENUM 
 typedef enum SSU_CALL_STATUS {	 
 SSU_CS_FORWARDED = 0 , /* Call has been forwarded */	 
 SSU_CS_CUG_CALL , /* Incoming CUG call ( Index also present ) */	 
 SSU_CS_HELD , /* Call held ( Voice Call ) */	 
 SSU_CS_UNHELD , /* Call retrieved ( Voice Call ) */	 
 SSU_CS_ENTERED_MPTY , /* Multiparty call entered ( Voice call ) */	 
 SSU_CS_RELEASED_HELD , /* Held call released ( Voice call ) */	 
 SSU_CS_FORWARD_CHECK , /* Forward Check SS message received */	 
 SSU_CS_ECT_ALERTING , /* Connecting with remote party in ECT */	 
 SSU_CS_ECT_CONNECTED , /* Connected with remote party in ECT */	 
 /* ( Caller Information may also be present ) */	 
 SSU_CS_DEFLECTED , /* Call has been deflected */	 
 SSU_CS_INCOMING_FORWARDED , /* Additional incoming call forwarded */	 
 /* This one must always be last in the list! */	 
 SSU_NUM_CS /* Number of SSU Call Status values */	 
 } _CiSsuCallStatus;

typedef UINT8 CiSsuCallStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSsuNotifyInfo_struct {	 
 CiSsuCallStatus Status ; /* Call Status indicator */	 
 UINT8 CugIndex ; /* CUG Index ( if applicable ) */	 
 CiCallerInfo CallerInfo ; /* Optional Caller Information */	 
 /* ( Caller Name info is never present ) */	 
 } CiSsuNotifyInfo;

//ICAT EXPORTED ENUM 
 typedef enum CI_BSTYPE_SPEED {	 
 CI_BSTYPE_SPEED_AUTOBAUD = 0 , /* Autobauding for 3.100000 kHz Non-Transparent */	 
	 
 /* 3.100000 kHz Audio definitions */	 
 CI_BSTYPE_SPEED_300_V21 , /* 300 bps ( V.21 ) */	 
 CI_BSTYPE_SPEED_1200_V22 , /* 1200 bps ( V.22 ) */	 
 CI_BSTYPE_SPEED_1200_75_V23 , /* 1200 / 75 bps ( V.23 ) */	 
 CI_BSTYPE_SPEED_2400_V22BIS , /* 2400 bps ( V.22bis ) */	 
 CI_BSTYPE_SPEED_2400_V26TER , /* 2400 bps ( V.26ter ) */	 
 CI_BSTYPE_SPEED_4800_V32 , /* 4800 bps ( V.32 ) */	 
 CI_BSTYPE_SPEED_9600_V32 , /* 9600 bps ( V.32 ) */	 
	 
 /* V.34 definitions */	 
 CI_BSTYPE_SPEED_9600_V34 , /* 9600 bps */	 
 CI_BSTYPE_SPEED_14400_V34 , /* 14400 bps */	 
 CI_BSTYPE_SPEED_19200_V34 , /* 19200 bps */	 
 CI_BSTYPE_SPEED_28800_V34 , /* 28800 bps */	 
 CI_BSTYPE_SPEED_33600_V34 , /* 33600 bps */	 
	 
 /* V.34 definitions */	 
 CI_BSTYPE_SPEED_1200_V120 , /* 1200 bps */	 
 CI_BSTYPE_SPEED_2400_V120 , /* 2400 bps */	 
 CI_BSTYPE_SPEED_4800_V120 , /* 4800 bps */	 
 CI_BSTYPE_SPEED_9600_V120 , /* 9600 bps */	 
 CI_BSTYPE_SPEED_14400_V120 , /* 14.400000 kbps */	 
 CI_BSTYPE_SPEED_19200_V120 , /* 19.200000 kbps */	 
 CI_BSTYPE_SPEED_28800_V120 , /* 28.800000 kbps */	 
 CI_BSTYPE_SPEED_38400_V120 , /* 38.400000 kbps */	 
 CI_BSTYPE_SPEED_48000_V120 , /* 48.000000 kbps */	 
 CI_BSTYPE_SPEED_56000_V120 , /* 56.000000 kbps */	 
	 
 /* V.110 or X.31 Flag Stuffing UDI definitions */	 
 CI_BSTYPE_SPEED_300_V110 , /* 300 bps */	 
 CI_BSTYPE_SPEED_1200_V110 , /* 1200 bps */	 
 CI_BSTYPE_SPEED_2400_V110_X31 , /* 2400 bps */	 
 CI_BSTYPE_SPEED_4800_V110_X31 , /* 4800 bps */	 
 CI_BSTYPE_SPEED_9600_V110_X31 , /* 9600 bps */	 
 CI_BSTYPE_SPEED_14400_V110_X31 , /* 14.400000 kbps */	 
 CI_BSTYPE_SPEED_19200_V110_X31 , /* 19.200000 kbps */	 
 CI_BSTYPE_SPEED_28800_V110_X31 , /* 28.800000 kbps */	 
 CI_BSTYPE_SPEED_38400_V110_X31 , /* 38.400000 kbps */	 
 CI_BSTYPE_SPEED_48000_V110_X31 , /* 48.000000 kbps */	 
 CI_BSTYPE_SPEED_56000_V110_X31 , /* 56.000000 kbps ( can also get FTM ) */	 
 CI_BSTYPE_SPEED_64000_X31 , /* 64.000000 kbps ( can also get FTM ) */	 
	 
 /* Bit Transparent Mode definitions */	 
 CI_BSTYPE_SPEED_56000_BTM , /* 56 kbps */	 
 CI_BSTYPE_SPEED_64000_BTM , /* 64 kbps */	 
	 
 /* PIAFS ( Personal Internet Access Forum Standard ) definitions */	 
 CI_BSTYPE_SPEED_32000_PIAFS , /* 56.000000 kbps ( PIAFS32k ) */	 
 CI_BSTYPE_SPEED_64000_PIAFS , /* 64.000000 kbps ( PIAFS64k ) */	 
	 
 /* Multimedia Call definitions */	 
 CI_BSTYPE_SPEED_28800_MM , /* 28.800000 kbps */	 
 CI_BSTYPE_SPEED_32000_MM , /* 32.000000 kbps */	 
 CI_BSTYPE_SPEED_33600_MM , /* 33.600000 kbps */	 
 CI_BSTYPE_SPEED_56000_MM , /* 56 kbps */	 
 CI_BSTYPE_SPEED_64000_MM , /* 64 kbps */	 
	 
 /* This one must always be last in the list! */	 
 CI_NUM_BSTYPE_SPEEDS /* Number of Bearer Service Speeds defined */	 
 } _CiBsTypeSpeed;

typedef UINT8 CiBsTypeSpeed ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPassword_struct {	 
 UINT8 len ; /* length of the password , [ CI_MIN_PASSWORD_LENGTH - CI_MAX_PASSWORD_LENGTH ] */	 
 UINT8 data [ 16 ] ;	 
 } CiPassword;

//ICAT EXPORTED STRUCT 
 typedef struct CiString_struct {	 
 UINT16 len ;	 
 CHAR valStr [ 100 ] ;	 
 } CiString;

//ICAT EXPORTED STRUCT 
 typedef struct CiStringExt_struct {	 
 UINT16 len ;	 
 CHAR valStr [ 200 ] ;	 
 } CiStringExt;

//ICAT EXPORTED STRUCT 
 typedef struct CiNumericRange_struct {	 
 UINT32 min ; /* lower limit */	 
 UINT32 max ; /* upper limit */	 
 } CiNumericRange;

typedef UINT32 CiBitRange ;
//ICAT EXPORTED STRUCT 
 typedef struct CiNumericList_struct {	 
 CiBoolean hasRange ; /* range of numbers are included */	 
 CiBoolean hasIndvNums ; /* individual numbers are included */	 
 UINT16 rangeLstSize ; /* actual number of CiNumericRange structures held in the range list ,	 
 ignored if hasRange is FALSE */	 
 CiNumericRange rangeLst [ 20 ] ;	 
 UINT16 indvLstSize ; /* actual number of numbers held in the individual number list ,	 
 ignored if hasIndNums is FALSE */	 
 UINT32 indvList [ 50 ] ;	 
 } CiNumericList;

//ICAT EXPORTED ENUM 
 typedef enum CIERRACCTYPE {	 
 CIERR_ACC_TYPE_CHV1 , /* CHV1 password */	 
 CIERR_ACC_TYPE_CHV2 , /* CHV2 password */	 
 CIERR_ACC_TYPE_UNBLOCK_CHV1 , /* Unblock CHV1 password */	 
 CIERR_ACC_TYPE_UNBLOCK_CHV2 , /* Unblock CHV2 password */	 
 CIERR_ACC_TYPE_ADMIN , /* Administrate access right */	 
 CIERR_ACC_TYPE_CB , /* call barring password */	 
 CIERR_ACC_TYPE_INTERNAL /* internal access type */	 
 } _CiErrAccType;

typedef UINT8 CiErrAccType ;
//ICAT EXPORTED ENUM 
 typedef enum CIERRACCCAUSE {	 
 CIERR_ACC_PRIV_REQUIRED , /* access privilege ( e.g. password ) is required to gain access right */	 
 CIERR_ACC_PW_NOT_INIT , /* password is not initialized or registered */	 
 CIERR_ACC_PW_BLOCKED , /* password was blocked because of a series of unsuccessful verification attempts */	 
 CIERR_ACC_RES_UNAVAIL , /* required resource is unavailable */	 
 CIERR_ACC_UNKNOWN /* unknown error access cause */	 
 } _CiErrAccCause;

typedef UINT8 CiErrAccCause ;
//ICAT EXPORTED ENUM 
 typedef enum CIERRINPUTCODE {	 
 /* wrong inputs */	 
 CIRC_ERR_WRONG_PASSWORD=0xF000 , /* wrong password */	 
 CIRC_ERR_BAD_PARAMETER , /* parameter invalid or out of range */	 
 CIRC_ERR_WRONG_INDEX , /* invalid index */	 
 CIRC_ERR_LONG_STR , /* string too long */	 
 CIRC_ERR_WRONG_CHAR , /* invalid characters in text string */	 
 CIRC_ERR_LONG_DIALSTR /* dial string too long */	 
 } _CiErrInputCode;

typedef UINT16 CiErrInputCode ;
//ICAT EXPORTED ENUM 
 typedef enum CIERRINTERLINKCAUSE {	 
 CIERR_INTERLINK_DOWN , /* interlink broken , receiver ' s action TBD */	 
 CIERR_INTERLINK_MEM_OVERFLOW /* memory overflow in the link , receiver ' s action TBD */	 
 } _CiErrInterLinkCause;

typedef UINT8 CiErrInterLinkCause ;
typedef UINT8 CiEmptyPrim ;
//ICAT EXPORTED STRUCT 
 typedef struct CiLongAdrInfo_tag {	 
 UINT8 Length ; /* Name Length in characters */	 
 UINT8 Name [ 50 ] ; /* Alphanumeric Name */	 
 } CiLongAdrInfo;

//ICAT EXPORTED ENUM 
 typedef enum CI_EDIT_CMD_ACTION {	 
 CIED_ADD=0 ,	 
 CIED_DELETE=1 ,	 
 CIED_REPLACE=2 ,	 
 } _CiEditCmdType;

typedef UINT8 CiEditCmdType ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_EMLPP_CALL_PRIORITY {	 
 CICC_EMLPP_CALL_PRIORITY_NONE = 0x00 ,	 
 CICC_EMLPP_CALL_PRIORITY_4 = 0x01 ,	 
 CICC_EMLPP_CALL_PRIORITY_3 = 0x02 ,	 
 CICC_EMLPP_CALL_PRIORITY_2 = 0x03 ,	 
 CICC_EMLPP_CALL_PRIORITY_1 = 0x04 ,	 
 CICC_EMLPP_CALL_PRIORITY_0 = 0x05 ,	 
 CICC_EMLPP_CALL_PRIORITY_B = 0x06 ,	 
 CICC_EMLPP_CALL_PRIORITY_A = 0x07 ,	 
 CICC_EMLPP_NUM_OF_PRIORITIES = 0x07	 
 } _CiCcEmlppCallPriority;

typedef UINT8 CiCcEmlppCallPriority ;
//ICAT EXPORTED ENUM 
 typedef enum CI_ERR_PRIM {	 
 CI_ERR_PRIM_HASNOSUPPORT_CNF = 0xF000 ,	 
 CI_ERR_PRIM_HASINVALIDPARAS_CNF ,	 
 CI_ERR_PRIM_ISINVALIDREQUEST_CNF ,	 
 CI_ERR_PRIM_SIMNOTREADY_CNF ,	 
 CI_ERR_PRIM_ACCESSDENIED_CNF ,	 
 CI_ERR_PRIM_INTERLINKDOWN_IND ,	 
 CI_ERR_PRIM_INTERLINKDOWN_RSP ,	 
 CI_ERR_PRIM_INTERLINKUP_IND ,	 
	 
 /* This should always be the last enum entry */	 
 CI_ERR_PRIM_NEXTAVAIL	 
 } _CiErrPrim;

typedef UINT16 CiErrPrim ;
typedef CiEmptyPrim CiErrPrimHasNoSupportCnf ;
//ICAT EXPORTED STRUCT 
 typedef struct CiErrPrimHasInvalidParasCnf_struct {	 
 CiErrInputCode err ;	 
 } CiErrPrimHasInvalidParasCnf;

typedef CiEmptyPrim CiErrPrimIsInvalidRequestCnf ;
typedef CiEmptyPrim CiErrPrimSimNotReadyCnf ;
//ICAT EXPORTED STRUCT 
 typedef struct CiErrPrimAccessDeniedCnf_struct {	 
 CiErrAccType type ;	 
 CiErrAccCause cause ;	 
 } CiErrPrimAccessDeniedCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiErrPrimInterlinkDownInd_struct {	 
 CiErrInterLinkCause cause ;	 
 } CiErrPrimInterlinkDownInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiErrPrimInterlinkDownRsp_struct {	 
 CiErrInterLinkCause cause ;	 
 } CiErrPrimInterlinkDownRsp;

typedef CiEmptyPrim CiErrPrimInterlinkUpInd ;
typedef UINT16 CiDevRc ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_MSG_CLASS_TYPE 
 {	 
 CI_DEV_LTE_RRC_MSG_CLASS_BCCH_BCH = 0 , /* BCCH-BCH massage */	 
 CI_DEV_LTE_RRC_MSG_CLASS_BCCH_DL_SCH , /* BCCH-DL-SCH message */	 
 CI_DEV_LTE_RRC_MSG_CLASS_PCCH , /* PCCH message */	 
 CI_DEV_LTE_RRC_MSG_CLASS_DL_CCCH , /* DL_CCCH message */	 
 CI_DEV_LTE_RRC_MSG_CLASS_DL_DCCH , /* DL_DCCH message */	 
 CI_DEV_LTE_RRC_MSG_CLASS_UL_CCCH , /* UL_CCCH message */	 
 CI_DEV_LTE_RRC_MSG_CLASS_UL_DCCH /* UL_DCCH message */	 
 } _CiDevLteRrcMsgClass;

typedef UINT8 CiDevLteRrcMsgClass ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_BCCH_BCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_BCCH_BCH_MSG_MASTR_INFO_BLK = 0 /* BCCH-BCH master information block massage */	 
 } _CiDevLteRrcBcchBchMsgType;

typedef UINT8 CiDevLteRrcBcchBchMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_BCCH_DL_SCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_BCCH_DL_SCH_MSG_SYS_INFO = 0 , /* BCCH-DL-SCH massage */	 
 CI_DEV_LTE_RRC_BCCH_DL_SCH_MSG_SYS_INFO_BLK_TYPE1 /* BCCH-DL-SCH System Information Block Type 1 message */	 
 } _CiDevLteRrcBcchDlSchMsgType;

typedef UINT8 CiDevLteRrcBcchDlSchMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_PCCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_PCCH_MSG_PAGING = 0 /* PCCH Paging massage */	 
 } _CiDevLteRrcPcchMsgType;

typedef UINT8 CiDevLteRrcPcchMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_DL_CCCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_DL_CCCH_MSG_RRC_CONN_REEST = 0 , /* DL-CCCH RRC Connection Reestablishment massage */	 
 CI_DEV_LTE_RRC_DL_CCCH_MSG_RRC_CONN_REEST_REJ , /* DL-CCCH RRC Connection Reestablishment Reject massage */	 
 CI_DEV_LTE_RRC_DL_CCCH_MSG_RRC_CONN_REJ , /* DL-CCCH RRC Connection Reject massage */	 
 CI_DEV_LTE_RRC_DL_CCCH_MSG_RRC_CONN_SETUP /* DL-CCCH RRC Connection Setup massage */	 
 } _CiDevLteRrcDlCcchMsgType;

typedef UINT8 CiDevLteRrcDlCcchMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_DL_DCCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_CSFB_PARAM_RESP = 0 , /* DL-DCCH CSFB Parameters Response */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_DL_INFO_TRANSFER , /* DL-DCCH DL Information Transfer message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_HO_FROM_EUTRA_REQ , /* DL-DCCH Handover From EUTRA Preparation Request message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_MOB_FROM_EUTRA_CMD , /* DL-DCCH Mobility From EUTRA Command message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_RRC_CONN_RECFG , /* DL-DCCH RRC Connection Reconfiguration message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_RRC_CONN_REL , /* DL-DCCH RRC Connection Release message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_SECUR_MODE_CMD , /* DL-DCCH Security Mode Command message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_UE_CAP_ENQ , /* DL-DCCH UE Capability Enquiry message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_CNTR_CHECK /* DL-DCCH Counter Check message */	 
 } _CiDevLteRrcDlDcchMsgType;

typedef UINT8 CiDevLteRrcDlDcchMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_UL_CCCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_UL_CCCH_MSG_RRC_CONN_REEST_REQ = 0 , /* UL-CCCH RRC Connection Reestablishment Request massage */	 
 CI_DEV_LTE_RRC_UL_CCCH_MSG_RRC_CONN_REQ /* UL-CCCH RRC Connection Request massage */	 
 } _CiDevLteRrcUlCcchMsgType;

typedef UINT8 CiDevLteRrcUlCcchMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_UL_DCCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_CSFB_PARAM_REQ = 0 , /* UL-DCCH CSFB Parameters Request message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_MEAS_REPORT , /* UL-DCCH Measurement Report message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_RRC_CONN_RECFG_CMP , /* UL-DCCH RRC Connection Reconfiguration Complete message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_RRC_CONN_REEST_CMP , /* UL-DCCH RRC Connection Reestablishment Complete message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_RRC_CONN_SETUP_CMP , /* UL-DCCH RRC Connection Setup Complete message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_SECUR_MODE_CMP , /* UL-DCCH Security Mode Complete message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_SECURE_MODE_FAIL , /* UL-DCCH Security Mode Failure message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_UE_CAP_INFO , /* UL-DCCH UE Capability Information message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_HO_PREP_TXR , /* UL-DCCH UL Handover Preparation Transfer message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_INFO_TXR , /* UL-DCCH UL Information Transfer message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_CNTR_CHK_RESP /* UL-DCCH Counter Check Response message */	 
 } _CiDevLteRrcUlDcchMsgType;

typedef UINT8 CiDevLteRrcUlDcchMsgType ;
//ICAT EXPORTED UNION : _CiDevLteRrcMsgClass 
 typedef union CiDevLteRrcMsgType_Tag 
 {	 
 CiDevLteRrcBcchBchMsgType bch ;	 
 CiDevLteRrcBcchDlSchMsgType dl_sch ;	 
 CiDevLteRrcPcchMsgType pcch ;	 
 CiDevLteRrcDlCcchMsgType dl_ccch ;	 
 CiDevLteRrcDlDcchMsgType dl_dcch ;	 
 CiDevLteRrcUlCcchMsgType ul_ccch ;	 
 CiDevLteRrcUlDcchMsgType ul_dcch ;	 
 } CiDevLteRrcMsgType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevLteRrcMsgClass msgClass ;	 
 CiDevLteRrcMsgType msgType ;	 
 UINT16 msgLength ;	 
	 
 // Important Note: Due to dynamic signal payload allocation , the " msg " field must be last!	 
 CHAR msg [ 256 ] ;	 
 } CiDevLteEng_RRC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiBoolean direction ; /* TRUE - Uplink NAS message transmitted. FALSE - Downlink NAS message received */	 
 UINT16 msgLength ;	 
 CHAR msg [ 400 ] ; /* hex encoded NAS message ( unciphered ) */	 
 } CiDevLteEng_NAS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 earfcn ; /* The EARFCN of the neighbor cell */	 
 UINT16 phyCellId ; /* The physical cell ID of the neighbor cell */	 
 UINT8 rsrp ; /* The average RSRP of the neighbor cell over last measurement period */	 
 UINT8 rsrq ; /* The average RSRQ of the neighbor cell over last measurement period */	 
 } CiDevLteEng_EutraMeas;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 mcc ; /* The MCC of the serving cell */	 
 UINT16 mnc ; /* The MNC of the serving cell */	 
 UINT32 cellId ; /* The cell identity of the serving cell */	 
 UINT32 tac ; /* The tracking area code of the serving cell */	 
 UINT16 servEarfcn ; /* The EARFCN of the serving cell */	 
 UINT16 servPhyCellId ; /* The physical cell ID of the serving cell */	 
 UINT8 servRsrp ; /* The average RSRP of the serving cell over last measurement period */	 
 UINT8 servRsrq ; /* The average RSRQ of the serving cell over last measurement period */	 
 UINT8 servRssnr ; /* The average RSSNR of the serving cell over last measurement period in decibels */	 
 UINT8 FreqBandInd ; /* The operating band of the serving cell , see 3 GPP TS 36.101000 / Table 5.500000 -1. */	 
 UINT8 dlBandwidth ; /* The transmission bandwidth configuration of the serving cell on the downlink , see 3 GPP TS 36.101000 / Table 5.600000 -1. Value n6 corresponds to 6 resource blocks , n15 to 15 resource blocks and so on. */	 
 UINT8 ulBandwidth ; /* The transmission bandwidth configuration of the serving cell on the uplink , see 3 GPP TS 36.101000 / Table 5.600000 -1. Value n6 corresponds to 6 resource blocks , n15 to 15 resource blocks and so on. */	 
 UINT8 numMeas ; /* The number of E-UTRA neighbor cell measurements included in the current instance of this metric */	 
 CiDevLteEng_EutraMeas meas [ 32 ] ; /* An array of structures with a length of numMeas */	 
 } CiDevLteEng_MSR;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 uarfcn ; /* The UARFCN of the neighbor cell */	 
 UINT16 sc ; /* The neighbor cell primary scrambling code */	 
 UINT8 rscp ; /* The neighbor cell CPICH RSCP. */	 
 UINT8 ecno ; /* The neighbor cell CPICH Ec / N0. */	 
 } CiDevLteEng_UtraMeas;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ; /* The neighbor cell ARFCN. */	 
 UINT8 bsic ; /* The neighbor cell base station identity code. */	 
 UINT8 rssi ; /* The neighbor cell BCCH RSSI. */	 
 } CiDevLteEng_MeasGeran;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numMeasUtra ; /* The number of UTRA inter-RAT neighbor cell measurements included in this instance of this metric */	 
 UINT8 numMeasGeran ; /* The number of inter-RAT neighbor cell measurements included in this instance of this metric */	 
 CiDevLteEng_UtraMeas utraMeas [ 32 ] ; /* An array of structures with a length of numMeasUtra */	 
 CiDevLteEng_MeasGeran geranMeas [ 32 ] ; /* An array of structures with a length of numMeasGeran */	 
 } CiDevLteEng_InterMsr;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 earfcn ; /* The neighbor cell EARFCN. */	 
 UINT16 phyCellId ; /* The neighbor cell physical layer cell identity. */	 
 } CiDevLteEng_NeighbEutra;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 uarfcn ; /* The neighbor cell UARFCN. */	 
 UINT16 sc ; /* The neighbor cell primary scrambling code */	 
 } CiDevLteEng_NeighbUtra;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ; /* The neighbor cell ARFCN. */	 
 } CiDevLteEng_NeighbGeran;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 numNeighbEutra ; /* The number of E-UTRA neighbor cells */	 
 UINT16 numNeighbUtra ; /* The number of UTRA neighbor cells */	 
 UINT16 numNeighbGeran ; /* The number of neighbor cells */	 
 CiDevLteEng_NeighbEutra neighbEutra [ 32 ] ; /* An array of structures with a length of numNeighbEutra */	 
 CiDevLteEng_NeighbUtra neighbUtra [ 32 ] ; /* An array of structures with a length of numNeighbUtra */	 
 CiDevLteEng_NeighbGeran neighbGeran [ 32 ] ; /* An array of structures with a length of numNeighbGeran */	 
 } CiDevLteEng_NeighborList;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_STATE 
 {	 
 CI_DEV_LTE_RRC_STATE_NULL = 0 , /* The E-UTRA RRC state is not applicable. */	 
 CI_DEV_LTE_RRC_STATE_IDLE_ , /* The E-UTRA RRC state is RRC_IDLE */	 
 CI_DEV_LTE_RRC_STATE_ATMPT_CONNECTION , /* Attempting to establish an RRC connection and enter E-UTRA RRC_CONNECTED state. */	 
 CI_DEV_LTE_RRC_STATE_CONNECTED_ , /* The E-UTRA RRC state is RRC_CONNECTED */	 
 CI_DEV_LTE_RRC_STATE_ENDING , /* Leaving E-UTRA RRC_CONNECTED state. */	 
 CI_DEV_LTE_RRC_STATE_ATMPT_OUTBND_MOBILITY , /* Attempting to leave E-UTRA , i.e. , via handover , cell change order , or cell reselection */	 
 CI_DEV_LTE_RRC_STATE_ATMPT_INBND_MOBILITY /* Attempting to enter E-UTRA , i.e. , via handover , cell change order , or cell reselection */	 
 } _CiDevLteRrcStateExt;

typedef UINT8 CiDevLteRrcStateExt ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_CAUSE 
 {	 
 CI_DEV_LTE_RRC_CAUSE_EST_EMERGENCY = 0 , /* The RRC establishment cause is ¡®Emergency¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_HIGH_PRIO_ACC , /* The RRC establishment cause is ¡®High priority access¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_MT_ACC , /* The RRC establishment cause is ¡®MT access¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_MO_SIGNAL , /* The RRC establishment cause is ¡®MO signaling¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_MO_DATA , /* The RRC establishment cause is ¡®MO data¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_REEST_RECFG_FAIL , /* The RRC reestablishment cause is ¡®Reconfiguration failure¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_REEST_HO_FAIL , /* The RRC reestablishment cause is ¡®Handover failure¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_REEST_OTHER_FAIL , /* The RRC reestablishment cause is ¡®Other failure¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_OTHER_RECFG_FAIL , /* RRC connection reconfiguration failed Ref. 3 GPP TS 36.331000 , section 5.300000 .5.5 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_IRAT_RES , /* EL Inter-RAT cell reselection occurred during RRC connection reestablishment Ref. 3 GPP TS 36.331000 , section 5.300000 .7.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_T311_EXP , /* RRC connection reestablishment failed due to T311 expiry Ref. 3 GPP TS 36.331000 , section 5.300000 .7.6 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_CELL_NOT_SUIT , /* RRC connection reestablishment failed due to T301 expiry or because the cell is no longer suitable Ref. 3 GPP TS 36.331000 , section 5.300000 .7.7 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_REEST_REJ , /* RRC connection reestablishment failed due to reestablishment rejection Ref. 3 GPP TS 36.331000 , section 5.300000 .7.8 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_LOAD_BAL_TAU_REQD , /* The RRC connection was released with cause ¡®Load balancing TAU required¡¯ Ref. 3 GPP TS 36.331000 , section 5.300000 .8.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_OTHER , /* The RRC connection was released with cause ¡®Other¡¯ Ref. 3 GPP TS 36.331000 , section 5.300000 .8.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_T310_EXP , /* A radio link failure due to T310 expiry ( loss of physical layer synchronization ) has been detected Ref. 3 GPP TS 36.331000 , section 5.300000 .11.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_RND_ACC , /* A radio link failure due to a random access problem has been detected Ref. 3 GPP TS 36.331000 , section 5.300000 .11.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_MAX_RLC_RETRANS , /* A radio link failure due to the maximum number of RLC retransmissions being reached has been detected Ref. 3 GPP TS 36.331000 , section 5.300000 .11.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_SUCC_MOB_FROM_EUTRAN , /* Outbound mobility away from E-UTRAN was successful Ref. 3 GPP TS 36.331000 , section 5.400000 .3.4 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_FAIL_NO_RESP_FROM_CELL , /* The RRC connection establishment procedure failed due to T300 expiry ( no response from cell ) Ref. 3 GPP TS 36.331000 , section 7.300000 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_FAIL_REJ , /* The RRC connection was rejected by the cell Ref. 3 GPP TS 36.331000 , section 7.300000 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_FAIL_CELL_RESEL , /* The RRC connection establishment procedure failed due to cell reselection after the RRC Connection Request message was sent Ref. 3 GPP TS 36.331000 , section 7.300000 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_FAIL_ABORTED , /* The RRC connection was aborted by the UE Ref. 3 GPP TS 36.331000 , section 7.300000 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_FAIL_CELL_BARRED , /* The RRC connection establishment procedure failed because the cell is temporarily barred ( T302 , T303 , or T305 is running ) Ref. 3 GPP TS 36.331000 , section 7.300000 */	 
 CI_DEV_LTE_RRC_CAUSE_NO_SERVICE = 254 , /* The UE went to no service state either from idle or connected mode */	 
 CI_DEV_LTE_RRC_CAUSE_NA = 255 /* RRC cause is not applicable to this state */	 
 } _CiDevLteRrcCause;

typedef UINT8 CiDevLteRrcCause ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevLteRrcStateExt rrcState ; /* The E-UTRA RRC state */	 
 CiDevLteRrcCause rrcCause ; /* The E-UTRA RRC cause */	 
 } CiDevLteEng_RrcState;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 bufsize0 ; /* 0 -63 ; Buffer size for logical channel group #0 */	 
 UINT8 bufsize1 ; /* 0 -63 ; Buffer size for logical channel group #1 */	 
 UINT8 bufsize2 ; /* 0 -63 ; Buffer size for logical channel group #2 */	 
 UINT8 bufsize3 ; /* 0 -63 ; Buffer size for logical channel group #3 */	 
 UINT16 crnti ; /* C-RNTI */	 
 UINT8 ta ; /* 0 -63 ; Timing Advance command */	 
 UINT8 powerHroom ; /* 0 -63 ; Power Headroom */	 
 } CiDevLteEng_MAC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 earfcn ; /* The accessed cels EARFCN */	 
 UINT16 phyCellId ; /* The accessed cells physical cell identity */	 
 UINT16 raRnti ; /* 1 -60 ; RA-RNTI */	 
 UINT8 preambleCount ; /* 1 -200 ; Total number of preamble transmitted */	 
 UINT8 lastTxPower ; /* 0 -63 ; Transmit power headroom upon transmission of the last preamble */	 
 UINT32 ulGrant ; /* UL grant indicated in the Random Access Response */	 
 UINT16 raTempCrnti ; /* The temporary C-RNTI indicated in the random Access Response */	 
 UINT16 ta ; /* 0 -1282 ; Timing Advance indicated in the Random Access Response */	 
 UINT8 raRespSucc ; /* 0 - Random Access Response reception was not successful 1 - Random Access Response reception was successful */	 
 } CiDevLteEng_MAC_RACH;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RLC_MODE 
 {	 
 CI_DEV_LTE_RLC_MODE_TM = 0 , /* RLC Transparent Mode */	 
 CI_DEV_LTE_RLC_MODE_UM , /* RLC Unacknowledged Mode */	 
 CI_DEV_LTE_RLC_MODE_AM /* RLC Acknowledged Mode */	 
 } _CiDevLteRlcMode;

typedef UINT8 CiDevLteRlcMode ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 drbId ; /* ( 1 -32 ) DRB Id */	 
 UINT8 epsBearerId ; /* ( 0 , 5 -15 ) EPS Bearer Id */	 
 UINT8 logicalChId ; /* ( 3 -10 ) DTCH Logical Channel Id */	 
 CiDevLteRlcMode rlcMode ; /* TM , UM , AM RLC transfer mode */	 
 UINT32 rxSduCount ; /* Number of RLC SDUs received successfully on this DRB */	 
 UINT32 rxByteCount ; /* Number of RLC SDU bytes received successfully on this DRB */	 
 UINT32 rxPduCount ; /* Number of RLC PDUs received on this DTCH */	 
 UINT32 reRxPduCount ; /* Number of RLC PDUs requested for retransmission on this DTCH */	 
 } CiDevLteEng_drbDl;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 drbId ; /* ( 1 -32 ) DRB Id */	 
 UINT8 epsBearerId ; /* ( 0 , 5 -15 ) EPS Bearer Id */	 
 UINT8 logicalChId ; /* ( 3 -10 ) DTCH Logical Channel Id */	 
 CiDevLteRlcMode rlcMode ; /* TM , UM , AM RLC transfer mode */	 
 UINT32 txSduCount ; /* Number of RLC SDUs submitted via the RLC SAP for transmission on this DRB */	 
 UINT32 txByteCount ; /* Number of RLC SDU bytes submitted via the RLC SAP for transmission on this DRB */	 
 UINT32 txPduCount ; /* Number of RLC PDUs transmitted on this DTCH */	 
 UINT32 reTxPduCount ; /* Number of retransmitted RLC PDUs on this DTCH */	 
 } CiDevLteEng_drbUl;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 srbId ; /* ( 1 -2 ) The SRB Identity */	 
 UINT16 rxSduCount ; /* Number of RLC SDU ' s received successfully on this SRB */	 
 UINT16 rxByteCount ; /* Number of RLC SDU bytes received successfully on this SRB */	 
 UINT16 rxPduCount ; /* Number of RLC PDUs received on this DCCH */	 
 UINT16 reRxPduCount ; /* Number of RLC PDUs requested for retransmission on this DCCH */	 
 } CiDevLteEng_srbDl;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 srbId ; /* ( 1 -2 ) The SRB Identity */	 
 UINT16 txSduCount ; /* Number of RLC SDUs submitted via the RLC SAP for transmission on this SRB */	 
 UINT16 txByteCount ; /* Number of RLC SDU bytes submitted via the RLC SAP for transmission on this SRB */	 
 UINT16 txPduCount ; /* Number of RLC PDUs transmitted on this DCCH */	 
 UINT16 reTxPduCount ; /* Number of retransmitted RLC PDUs on this DCCH */	 
 } CiDevLteEng_srbUl;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 rlcUlDuration ; /* In our implementation it is always 960 RLC uplink measurement period to which this metric pertains in milliseconds */	 
 UINT16 rlcDlDuration ; /* In our implementation it is always 960 RLC downlink measurement period to which this metric pertains in milliseconds */	 
 UINT8 numSrbUl ; /* ( 1 -2 ) The number of uplink signaling radio bearers represented in this metric */	 
 UINT8 numSrbDl ; /* ( 1 -2 ) The number of downlink signaling radio bearers represented in this metric */	 
 UINT8 numDrbUl ; /* ( 0 -11 ) The number of uplink data radio bearers represented in this metric */	 
 UINT8 numDrbDl ; /* ( 0 -11 ) The number of downlink data radio bearers represented in this metric */	 
 CiDevLteEng_srbUl srbUl [ 2 ] ; /* An array of structures with a length of numSrbUl */	 
 CiDevLteEng_srbDl srbDl [ 2 ] ; /* An array of structures with a length of numSrbDl */	 
 CiDevLteEng_drbUl drbUl [ 12 ] ; /* An array of structures with a length of numDrbUl */	 
 CiDevLteEng_drbDl drbDl [ 12 ] ; /* An array of structures with a length of numDrbDl */	 
 } CiDevLteEng_RLC;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_EPS_BEARER_TYPE 
 {	 
 CI_DEV_LTE_EPS_DEFAULT_BEARER = 0 , /* Default EPS Bearer */	 
 CI_DEV_LTE_EPS_DEDICATED_BEARER /* Dedicated EPS Bearer */	 
 } _CiDevLteEpsBearerType;

typedef UINT8 CiDevLteEpsBearerType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_EPS_BEARER_CONTEXT_STATE 
 {	 
 CI_DEV_LTE_EPS_BEARER_INACTIVE = 0 , /* The EPS bearer Context does not exist */	 
 CI_DEV_LTE_EPS_BEARER_ACTIVE , /* The EPS bearer Context is active */	 
 CI_DEV_LTE_EPS_BEARER_ACTIVE_PENDING , /* The EPS bearer Context exist but not active */	 
 CI_DEV_LTE_EPS_BEARER_MODIFY /* The EPS bearer Context is in a process of being modified */	 
 } _CiDevLteEpsBearereContextState;

typedef UINT8 CiDevLteEpsBearereContextState ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 pdnConnectionId ; /* PDN connection id */	 
 UINT8 epsBearerId ; /* EPS bearer Id */	 
 CiDevLteEpsBearerType epsBearerType ; /* EPS bearer type ( default or dedicated ) */	 
 CiDevLteEpsBearereContextState epsBearerNewState ; /* The new EPS bearer context state ( see 3 GPP TS 24.301000 , 6.100000 .3.2 ) */	 
 } CiDevLteEng_EPS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 qci ; /* QoS Class Identifier */	 
 UINT8 maxBitRateUl ; /* Maximum bit rate for uplink */	 
 UINT8 maxBitRateDl ; /* Maximum bit rate for downlink */	 
 UINT8 gbrUl ; /* Guaranteed bit rate for uplink */	 
 UINT8 gbrDl ; /* Guaranteed bit rate for downlink */	 
 UINT8 maxBitRateUlEx ; /* Maximum bit rate for uplink ( extended ) */	 
 UINT8 maxBitRateDlEx ; /* Maximum bit rate for downlink ( extended ) */	 
 UINT8 gbrUlEx ; /* Guaranteed bit rate for uplink ( extended ) */	 
 UINT8 gbrDlEx ; /* Guaranteed bit rate for downlink ( extended ) */	 
 } CiDevLteEng_EpsQos;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 pdnConnectionId ; /* PDN connection id */	 
 UINT8 epsBearerId ; /* EPS bearer Id linked */	 
 UINT8 EpsBearerId ; /* The Linked EPS bearer Id when the QoS of a dedicated EPS bearer s assigned or changed */	 
 CiDevLteEng_EpsQos epsQos ; /* the EPS QoS */	 
 } CiDevLteEng_EPS_QoS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 totalPuschTxPower ; /* -112 - 23 ; Total UE transmit power for PUSCH transmission ( dBm ) */	 
 UINT8 puschTxPowerPerRb ; /* -10 - 23 ; UE transmit power for PUSCH transmission per resource block ( dBm ) */	 
 CiBoolean wbReportPresent ; /* Indication if cqiWbDist is valid. TRUE- CQI is present. */	 
 UINT8 numSubBandReport ; /* 1 -4 ; Number of sub bands for the CQI */	 
 UINT8 cqiWbDist [ 16 ] ; /* CQI distribution over all sub-bands */	 
 UINT8 cqSubBandDist [ 4 ] ; /* CQI distribution for each sub-band */	 
 UINT16 randIndDist [ 5 ] ; /* Rank Indicator ( RI ) distribution. */	 
 UINT16 pmiDist [ 16 ] ; /* Precoding matrix Indicator ( PMI ) distribution */	 
 } CiDevLteEng_PUSCH;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_T310_STATUS 
 {	 
 CI_DEV_LTE_T310_STATUS_STOPPED = 0 , /* T310 timer has been stopped. Radio link restored */	 
 CI_DEV_LTE_T310_STATUS_STARTED , /* T310 timer has been started. Physical layer problems detected */	 
 CI_DEV_LTE_T310_STATUS_EXPIRED , /* T310 timer has expired. Radio link has failed */	 
 CI_DEV_LTE_T310_STATUS_UNKNOWN /* T310 timer status is invalid */	 
 } _CiDevLteT310Status;

typedef UINT8 CiDevLteT310Status ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevLteT310Status t310Status ; /* The status of T310 timer associated with this radio link */	 
 } CiDevLteEng_RadioLink;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 pdpContextId ;	 
 UINT32 localIpAddress ;	 
 UINT32 ipAddrPrimaryDns ;	 
 UINT32 ipAddrSecondaryDns ;	 
 UINT8 localIpv6Address [ 16 ] ;	 
 UINT8 strIpV6Dns1 [ 16 ] ;	 
 UINT8 strIpV6Dns2 [ 16 ] ;	 
 } CiDevGsmUmtsComnPdpCActEng_SM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_SM_CAUSE_TYPE 
 {	 
 CI_DEV_SM_CAUSE_NO_NET_RESPONSE = 0 ,	 
 CI_DEV_SM_CAUSE_OP_DET_BARRING = 8 ,	 
 CI_DEV_SM_CAUSE_LLC_SNDCP_FAILURE = 25 ,	 
 CI_DEV_SM_CAUSE_INSUFF_RESOURCES = 26 ,	 
 CI_DEV_SM_CAUSE_UNKN_MISS_APN = 27 ,	 
 CI_DEV_SM_CAUSE_UNKN_PDP_ADDR_TYPE = 28 ,	 
 CI_DEV_SM_CAUSE_USER_AUTH_FAILED = 29 ,	 
 CI_DEV_SM_CAUSE_ACT_REJ_BY_GGSN = 30 ,	 
 CI_DEV_SM_CAUSE_ACT_REJ_UNSPEC = 31 ,	 
 CI_DEV_SM_CAUSE_SERV_OPT_NOT_SUPP = 32 ,	 
 CI_DEV_SM_CAUSE_SERV_OPT_NOT_SUBS = 33 ,	 
 CI_DEV_SM_CAUSE_SERV_OPT_TEMP_OUT_OF_ORDER = 34 ,	 
 CI_DEV_SM_CAUSE_NSAPI_ALREADY_USED = 35 ,	 
 CI_DEV_SM_CAUSE_REG_PDP_CONT_DEACT = 36 ,	 
 CI_DEV_SM_CAUSE_QOS_NOT_ACCEPTED = 37 ,	 
 CI_DEV_SM_CAUSE_NETWORK_FAILURE = 38 ,	 
 CI_DEV_SM_CAUSE_REACTIVATION_REQUESTED = 39 ,	 
 CI_DEV_SM_CAUSE_FEAT_NOT_SUPP = 40 ,	 
 CI_DEV_SM_CAUSE_SEM_ERR_TFT_OP = 41 ,	 
 CI_DEV_SM_CAUSE_SYN_ERR_TFT_OP = 42 ,	 
 CI_DEV_SM_CAUSE_UNKN_PDP_CONTEXT = 43 ,	 
 CI_DEV_SM_CAUSE_SEM_ERR_PKT_FILTER = 44 ,	 
 CI_DEV_SM_CAUSE_SYN_ERR_PKT_FILTER = 45 ,	 
 CI_DEV_SM_CAUSE_PDP_CXT_WOUT_TFT_ACT = 46 ,	 
 CI_DEV_SM_CAUSE_MULTICAST_GRP_TIMEOUT = 47 ,	 
 CI_DEV_SM_CAUSE_ACTIVATION_REJ_BCM_VIOLATION = 48 ,	 
 CI_DEV_SM_CAUSE_IPV4_ONLY = 50 ,	 
 CI_DEV_SM_CAUSE_IPV6_ONLY = 51 ,	 
 CI_DEV_SM_CAUSE_SINGLE_ADDR_ONLY = 52 ,	 
 CI_DEV_SM_CAUSE_COLLISION = 56 ,	 
 CI_DEV_SM_CAUSE_INVALID_TRANS_ID_VALUE = 81 ,	 
 CI_DEV_SM_CAUSE_SEM_INCORRECT_MESSAGE = 95 ,	 
 CI_DEV_SM_CAUSE_INVALID_MANDATORY_INFO = 96 ,	 
 CI_DEV_SM_CAUSE_NONEXISTENT_MESSAGE_TYPE = 97 ,	 
 CI_DEV_SM_CAUSE_INCOMPATIBLE_MESSAGE_TYPE = 98 ,	 
 CI_DEV_SM_CAUSE_NONEXISTENT_INFO_ELEMENT = 99 ,	 
 CI_DEV_SM_CAUSE_CONDITIONAL_IE_ERROR = 100 ,	 
 CI_DEV_SM_CAUSE_INCOMPATIBLE_MESSAGE = 101 ,	 
 CI_DEV_SM_CAUSE_PROTOCOL_ERROR_UNSPEC = 111 ,	 
 CI_DEV_SM_CAUSE_INCOMPATIBLE_APN_RESTR_VALUE = 112	 
 } _CiDevSmCauseType;

typedef UINT8 CiDevSmCauseType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_SM_PDP_INITIATOR_TYPE 
 {	 
 CI_DEV_SM_NETWORK_INITIATED = 0 ,	 
 CI_DEV_SM_UE_INITIATED	 
 } _CiDevSmPdpInitiatorType;

typedef UINT8 CiDevSmPdpInitiatorType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 pdpContextId ;	 
 CiDevSmCauseType termCode ;	 
 CiDevSmPdpInitiatorType pdpInitiator ;	 
 } CiDevGsmUmtsComnPdpCEndEng_SM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_SM_ORDINAL_TYPE 
 {	 
 CI_DEV_SM_PRIMARY_PDP_CONTEXT = 0 ,	 
 CI_DEV_SM_SECONDARY_PDP_CONTEXT	 
 } _CiDevSmOrdinalType;

typedef UINT8 CiDevSmOrdinalType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 pdpContextId ;	 
 UINT32 assocContextId ;	 
 CiDevSmOrdinalType ordinal ;	 
 CiDevSmPdpInitiatorType pdpInitiator ;	 
 UINT8 nsapi ;	 
 UINT8 sapi ;	 
 UINT8 apn [ 100 ] ;	 
 } CiDevGsmUmtsComnPdpCReqEng_SM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_ATTACH_TYPE 
 {	 
 CI_DEV_MM_GPRS_ATTACH = 0 ,	 
 CI_DEV_MM_GPRS_ATTACH_WHILE_IMSI_ATTACHED ,	 
 CI_DEV_MM_COMB_GPRS_ATTACH_IMSI_ATTACH ,	 
 CI_DEV_MM_IMSI_ATTACH	 
 } _CiDevMmAttachType;

typedef UINT8 CiDevMmAttachType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_IDENTITY_TYPE 
 {	 
 CI_DEV_MM_NO_IDENTITY = 0 ,	 
 CI_DEV_MM_IMSI ,	 
 CI_DEV_MM_IMEI ,	 
 CI_DEV_MM_IMEISV ,	 
 CI_DEV_MM_TMSI_PTMSI	 
 } _CiDevMmIdentityType;

typedef UINT8 CiDevMmIdentityType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevMmAttachType attachType ;	 
 CiDevMmIdentityType identityType ;	 
 UINT8 strIdentity [ 16 ] ;	 
 } CiDevGsmUmtsComnAttachBeginEng_MM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_ATTACH_MSG_TYPE 
 {	 
 CI_DEV_MM_ATTACH_ACCEPT = 0 ,	 
 CI_DEV_MM_ATTACH_COMPLETE ,	 
 CI_DEV_MM_ATTACH_REJECT ,	 
 CI_DEV_MM_LOC_UPDATE_ACCEPT ,	 
 CI_DEV_MM_LOC_UPDATE_REJECT	 
 } _CiDevMmAttachMsgType;

typedef UINT8 CiDevMmAttachMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_ATTACH_RESULT_TYPE 
 {	 
 CI_DEV_MM_GPRS_ONLY_ATTACHED = 0 ,	 
 CI_DEV_MM_COMB_GPRS_IMSI_ATTACHED ,	 
 CI_DEV_MM_IMSI_ATTACHED	 
 } _CiDevMmAttachResultType;

typedef UINT8 CiDevMmAttachResultType ;
typedef UINT8 CiDevMmGmmCauseType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 Identity ;	 
 CiDevMmAttachMsgType attachMsgType ;	 
 CiDevMmGmmCauseType gmmCause ;	 
 CiDevMmAttachResultType attachResult ;	 
 } CiDevGsmUmtsComnAttachEndEng_MM;

typedef UINT8 CiDevGsmUmtsComnDetachAcceptEng_MM ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_AREA_UPDATE_RESULT_TYPE 
 {	 
 CI_DEV_MM_AREA_UPDATE_RESULT_RA_UPDATED = 0 ,	 
 CI_DEV_MM_AREA_UPDATE_RESULT_COMB_RA_LA_UPDATED = 1	 
 } _CiDevMmAreaUpdateResultType;

typedef UINT8 CiDevMmAreaUpdateResultType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 Identity ;	 
 UINT16 newLAC ;	 
 UINT8 newRAC ;	 
 CiDevMmGmmCauseType gmmCause ;	 
 CiDevMmAreaUpdateResultType raUpdateRes ;	 
 } CiDevGsmUmtsComnRAUEng_MM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_ACCESS_TECH_TYPE 
 {	 
 CI_DEV_MM_ACCESS_TECH_UNKNOWN = 0 ,	 
 CI_DEV_MM_ACCESS_TECH_GERAN = 1 ,	 
 CI_DEV_MM_ACCESS_TECH_UTRAN = 2 ,	 
 CI_DEV_MM_ACCESS_TECH_NONE = 255	 
 } _CiDevMmAccessTechType;

typedef UINT8 CiDevMmAccessTechType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_FREQ_BAND_TYPE 
 {	 
 CI_DEV_MM_BAND_INFO_T_GSM_380 ,	 
 CI_DEV_MM_BAND_INFO_T_GSM_410 ,	 
 CI_DEV_MM_BAND_INFO_GSM_450 ,	 
 CI_DEV_MM_BAND_INFO_GSM_480 ,	 
 CI_DEV_MM_BAND_INFO_GSM_710 ,	 
 CI_DEV_MM_BAND_INFO_GSM_750 ,	 
 CI_DEV_MM_BAND_INFO_T_GSM_810 ,	 
 CI_DEV_MM_BAND_INFO_GSM_850 ,	 
 CI_DEV_MM_BAND_INFO_P_GSM_900 ,	 
 CI_DEV_MM_BAND_INFO_E_GSM_900 ,	 
 CI_DEV_MM_BAND_INFO_R_GSM_900 ,	 
 CI_DEV_MM_BAND_INFO_T_GSM_900 ,	 
 CI_DEV_MM_BAND_INFO_DCS_1800 ,	 
 CI_DEV_MM_BAND_INFO_PCS_1800 ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_I ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_II ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_III ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_IV ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_V ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_VI ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_VII ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_VIII ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_IX ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_X ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_XI ,	 
 CI_DEV_MM_BAND_INFO_NOT_AVAILABLE = 255	 
 } _CiDevMmFreqBandType;

typedef UINT8 CiDevMmFreqBandType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 fieldValidity ;	 
 UINT8 rac ;	 
 CiDevMmAccessTechType accessTech ;	 
 CiDevMmFreqBandType freqBand ;	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 UINT16 lac ;	 
 UINT32 cellId ;	 
 UINT16 rncID ;	 
 } CiDevGsmUmtsComnNetInfoEng_MM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_RADIO_SVC_STATE_TYPE 
 {	 
 CI_DEV_MM_RADIO_SERV_STATE_UNKNOWN = 0 ,	 
 CI_DEV_MM_RADIO_SERV_STATE_OFF ,	 
 CI_DEV_MM_RADIO_SERV_STATE_SEARCHING ,	 
 CI_DEV_MM_RADIO_SERV_STATE_NO_SERVICE ,	 
 CI_DEV_MM_RADIO_SERV_STATE_2G ,	 
 CI_DEV_MM_RADIO_SERV_STATE_3G ,	 
 CI_DEV_MM_RADIO_SERV_STATE_4G	 
 } _CiDevMmRadioSvcStateType;

typedef UINT8 CiDevMmRadioSvcStateType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_NETWORK_SVC_STATE_TYPE 
 {	 
 CI_DEV_MM_NETW_SERV_STATE_NONE = 0 ,	 
 CI_DEV_MM_NETW_SERV_STATE_EMERGENCY ,	 
 CI_DEV_MM_NETW_SERV_STATE_HOME ,	 
 CI_DEV_MM_NETW_SERV_STATE_HOME_EQUIV ,	 
 CI_DEV_MM_NETW_SERV_STATE_ROAM	 
 } _CiDevMmNetworkSvcStateType;

typedef UINT8 CiDevMmNetworkSvcStateType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevMmRadioSvcStateType radioSvcState ;	 
 CiDevMmNetworkSvcStateType networkSvcState ;	 
 } CiDevGsmUmtsComnServcStateEng_MM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_RADIO_MODE_TYPE 
 {	 
 CI_DEV_MM_RADIO_MODE_NONE = 0 ,	 
 CI_DEV_MM_RADIO_MODE_GSM ,	 
 CI_DEV_MM_RADIO_MODE_GPRS ,	 
 CI_DEV_MM_RADIO_MODE_EDGE ,	 
 CI_DEV_MM_RADIO_MODE_WCDMA ,	 
 CI_DEV_MM_RADIO_MODE_HSDPA ,	 
 CI_DEV_MM_RADIO_MODE_HSUPA ,	 
 CI_DEV_MM_RADIO_MODE_HSPA ,	 
 CI_DEV_MM_RADIO_MODE_HSPA_PLUS ,	 
 CI_DEV_MM_RADIO_MODE_LTE ,	 
 CI_DEV_MM_RADIO_MODE_RTT ,	 
 CI_DEV_MM_RADIO_MODE_EVDO ,	 
 CI_DEV_MM_RADIO_MODE_WIFI	 
 } _CiDevMmRadioModeType;

typedef UINT8 CiDevMmRadioModeType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevMmRadioModeType radioMode ;	 
 } CiDevGsmUmtsComnRadioModeEng_MM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_PROTOCOL_DICRIMINATOR_TYPE 
 {	 
 CI_DEV_RR_DISCR_GROUP_CALL_CONTROL = 0 , /* Group call control */	 
 CI_DEV_RR_DISCR_BC_CALL_CONTROL = 1 , /* Broadcast call control */	 
 CI_DEV_RR_DISCR_RESERVED1 = 2 , /* Reserved */	 
 CI_DEV_RR_DISCR_CALL_CONTROL = 3 , /* Call control ; call related SS messages */	 
 CI_DEV_RR_DISCR_GTTP = 4 , /* GPRS transparent transport protocol ( GTTP ) */	 
 CI_DEV_RR_DISCR_MM = 5 , /* Mobility management messages */	 
 CI_DEV_RR_DISCR_RR = 6 , /* Radio resources management messages */	 
 CI_DEV_RR_DISCR_GMM = 8 , /* GPRS mobility management messages */	 
 CI_DEV_RR_DISCR_SMS = 9 , /* SMS messages */	 
 CI_DEV_RR_DISCR_SM = 10 , /* GPRS session management messages */	 
 CI_DEV_RR_DISCR_SS = 11 , /* Non call related SS messages */	 
 CI_DEV_RR_DISCR_LCS = 12 , /* Location services */	 
 CI_DEV_RR_DISCR_RESERVED2 = 14 , /* Reserved */	 
 CI_DEV_RR_DISCR_RESERVED3 = 15 /* Reserved */	 
 } _CiDevRrProtocolDicriminatorType;

typedef UINT8 CiDevRrProtocolDicriminatorType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_LOGICAL_CHANNEL_TYPE 
 {	 
 CI_DEV_RR_CHANNEL_BCCH = 0 , /* GSM Broadcast Control Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_PCH , /* GSM Paging Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_RACH , /* GSM Random Access Channel ( Uplink only ) */	 
 CI_DEV_RR_CHANNEL_AGCH , /* GSM Access Grant Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_NCH , /* GSM Notification Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_SACCH , /* GSM Slow Associated Control Channel */	 
 CI_DEV_RR_CHANNEL_FACCH , /* GSM Fast Associated Control Channel */	 
 CI_DEV_RR_CHANNEL_SDCCH , /* GSM Standalone Dedicated Control Channel */	 
 CI_DEV_RR_CHANNEL_PBCCH , /* GPRS Packet Broadcast Control Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_PPCH , /* GPRS Packet Paging Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_PRACH , /* GPRS Packet Random Access Channel ( Uplink only ) */	 
 CI_DEV_RR_CHANNEL_PAGCH , /* GPRS Packet Access Grant Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_PACCH , /* GPRS Packet Associated Control Channel */	 
 CI_DEV_RR_CHANNEL_CCCH_RACH , /* UMTS Common Control Channel over Random Access Channel ( Uplink only ) */	 
 CI_DEV_RR_CHANNEL_DCCH_RACH , /* UMTS Dedicated Control Channel over Random Access Channel ( Uplink only ) */	 
 CI_DEV_RR_CHANNEL_DCCH_DCH , /* UMTS Dedicated Control Channel over Random Access Channel ( Uplink only ) */	 
 CI_DEV_RR_CHANNEL_DCCH_EDCH , /* UMTS Dedicated Control Channel over Enhanced Dedicated Channel ( Uplink only ) */	 
 CI_DEV_RR_CHANNEL_BCCH_BCH , /* UMTS Broadcast Control Channel over Broadcast Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_BCCH_FACH , /* UMTS Broadcast Control Channel over Forward Access Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_BCCH_HSDSCH , /* UMTS Broadcast Control Channel over High-speed Downlink Shared Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_PCCH_PCH , /* UMTS Paging Control Channel over Paging Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_PCCH_HSDSCH , /* UMTS Paging Control Channel over High-speed Downlink Shared Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_CCCH_FACH , /* UMTS Common Control Channel over Forward Access Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_CCCH_HSDSCH , /* UMTS Common Control Channel over High-speed Downlink Shared Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_DCCH_FACH , /* UMTS Dedicated Control Channel over Forward Access Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_DCCH_HSDSCH , /* UMTS Dedicated Control Channel over High-speed Downlink Shared Channel ( Downlink only ) */	 
 CI_DEV_CHANNEL_NOT_APPLICABLE = 255 /* Not applicable for this L3 protocol */	 
 } _CiDevRrLogicalChannelType;

typedef UINT8 CiDevRrLogicalChannelType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 transactionId ;	 
 CiDevRrProtocolDicriminatorType protDiscr ;	 
 UINT8 msgType ;	 
 CiDevRrLogicalChannelType logicalChannelType ;	 
 UINT8 msg [ 251 ] ;	 
 } CiDevGsmLayer3DwnlnkMsgEng_GRR;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 transactionId ;	 
 CiDevRrProtocolDicriminatorType protDiscr ;	 
 UINT8 sendSeqNum ;	 
 UINT8 msgType ;	 
 CiDevRrLogicalChannelType logicalChannelType ;	 
 UINT8 msg [ 251 ] ;	 
 } CiDevGsmLayer3UplnkMsgEng_GRR;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 bcchArfcn ;	 
 UINT8 rxLev ;	 
 UINT8 bsic ;	 
 BOOL bandInd ;	 
 } CiDevGsmRfServingCellInfoEng_GRR;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 UINT8 bsic ;	 
 UINT8 rxLev ;	 
 } CiDevRrGsmNcellMeasType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 uarfcn ;	 
 UINT16 scramblingCode ;	 
 UINT8 rssi ;	 
 UINT8 ecNo ;	 
 UINT8 rscp ;	 
 } CiDevRrInterRatMeasType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numGsmMeas ;	 
 BOOL numInterRatMeas ;	 
 CiDevRrGsmNcellMeasType gsmMeas [ 32 ] ;	 
 CiDevRrInterRatMeasType interRatMeas [ 32 ] ;	 
 } CiDevGsmNeighbrMeasEng_GRR;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_CELL_CHANGE_ORDER_TYPE 
 {	 
 CI_DEV_RR_CCO_MSG_RR_CELL_CHANGE_ORDER = 0 , /* RR-Cell Change Order */	 
 CI_DEV_RR_CCO_MSG_PACKET_CELL_CHANGE_ORDER , /* Packet Cell Change Order */	 
 CI_DEV_RR_CCO_MSG_CELL_CHANGE_ORDER_FROM_UTRAN , /* Cell Change Order From UTRAN */	 
 CI_DEV_RR_CCO_MSG_PS_HANDOVER_COMMAND , /* PS Handover Command */	 
 } _CiDevRrCellCngOrdMsgType;

typedef UINT8 CiDevRrCellCngOrdMsgType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrCellCngOrdMsgType cellChangeMsg ; /* Cell change message type */	 
 UINT8 targetBsic ; /* GERAN Target cell: BSIC ( 0xFF if not applicable ) */	 
 UINT16 targetArfcn ; /* Bit 15 : ARFCN is DCS ( 0 ) or PCS ( 1 ) ; Bits 0 -14: GERAN Target cell: ARFCN ( 0x7FFF if not applicable ) */	 
 UINT16 targetUarfcn ; /* UTRAN Target cell: UARFCN ( 0xFFFF if not applicable ) */	 
 UINT16 targetSc ; /* UTRAN Target cell: Primary Scrambling code ( 0xFFFF if not applicable ) */	 
 } CiDevGsmWbCellChngBginEng_RR;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_RESULT_TYPE 
 {	 
 CI_DEV_RR_RESULT_SUCCESS = 0 , /* The procedure was successful */	 
 CI_DEV_RR_RESULT_FAILURE , /* The procedure was unsuccessful */	 
 CI_DEV_RR_RESULT_UNKNOWN = 255 /* The result of the procedure is invalid or unknown , or this field is not applicable */	 
 } _CiDevRrResultType;

typedef UINT8 CiDevRrResultType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_IRAT_CH_CAUSE_TYPE 
 {	 
 CI_DEV_RR_RAT_CH_CAUSE_CONFIGURATION_UNACCEPTABLE = 0 , /* Configuration unacceptable */	 
 CI_DEV_RR_IRAT_CH_CAUSE_PHYSICAL_CHAN_FAILURE , /* Physical Channel Failure */	 
 CI_DEV_RR_RAT_CH_CAUSE_PROTOCOL_ERROR , /* Protocol Error */	 
 CI_DEV_RR_IRAT_CH_CAUSE_UNSPECIFIED /* Unspecified */	 
 } _CiDevRrIratChCauseType;

typedef UINT8 CiDevRrIratChCauseType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_PROTOCOL_ERROR_CAUSE_TYPE 
 {	 
 CI_DEV_RR_PROT_ERR_CAUSE_ASN_VIOL_ENC_ERR = 0 , /* ASN.1 violation or encoding error */	 
 CI_DEV_RR_PROT_ERR_CAUSE_MSG_TYPE_NON_EXIST , /* Message type non-existent or not implemented */	 
 CI_DEV_RR_PROT_ERR_CAUSE_MSG_NOT_COMPATIBLE , /* Message not compatible with receiver state */	 
 CI_DEV_RR_PROT_ERR_CAUSE_IE_VALUE_NOT_COMPREHENDED , /* Information element value not comprehended */	 
 CI_DEV_RR_PROT_ERR_CAUSE_IE_MISSING , /* Information element missing */	 
 CI_DEV_RR_PROT_ERR_CAUSE_MSG_EXT_NOT_COMPREHENDED , /* Message extension not comprehended */	 
 CI_DEV_RR_PROT_ERR_CAUSE_UNKNOWN = 255 /* Error cause is not known or cannot be supplied */	 
 } _CiDevRrProtErrCauseType;

typedef UINT8 CiDevRrProtErrCauseType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_CELL_CHANGE_FAIL_TYPE 
 {	 
 CI_DEV_RR_CELL_CH_FAIL_FREQ_NOT_IMPLEMENTED = 0 , /* Frequency not implemented */	 
 CI_DEV_RR_CELL_CH_FAIL_NO_RESP_ON_TARGET_CELL , /* No response on target cell */	 
 CI_DEV_RR_CELL_CH_FAIL_IMMED_ASS_PACCESS_REJ , /* Immediate Assign Reject or Packet Access Reject on target cell */	 
 CI_DEV_RR_CELL_CH_FAIL_ON_GOING_CS_CONN , /* On going CS connection */	 
 CI_DEV_RR_CELL_CH_FAIL_MS_IN_GMM_STANDBY , /* MS in GMM Standby state */	 
 CI_DEV_RR_CELL_CH_FAIL_FORCED_TO_STANDBY , /* Forced to the Standby state */	 
 CI_DEV_RR_CELL_CH_FAIL_RESERVED /* Reserved */	 
 } _CiDevRrCellChngFailType;

typedef UINT8 CiDevRrCellChngFailType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrResultType Result ; /* Result of the cell change procedure */	 
 CiDevRrIratChCauseType irFailure ; /* Inter-RAT Cell Change failure */	 
 CiDevRrProtErrCauseType irProtCause ; /* Protocol error cause , only valid if IrFailure = RR_CH_CAUSE_PROTOCOL_ERROR */	 
 CiDevRrCellChngFailType cellChCause ; /* Packet Cell Change Failure */	 
 } CiDevGsmWbCellChngEndEng_RR;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_HANDOVER_TYPE 
 {	 
 CI_DEV_RR_HANDOVER_TYPE_GSM_NON_SYNCHRONIZED = 0 , /* non-synchronized ( GSM ) */	 
 CI_DEV_RR_HANDOVER_TYPE_GSM_SYNCHRONIZED , /* synchronized ( GSM ) */	 
 CI_DEV_RR_HANDOVER_TYPE_GSM_PRE_SYNCHRONIZED , /* pre-synchronized ( GSM ) */	 
 CI_DEV_RR_HANDOVER_TYPE_GSM_PSEUDO_SYNCHRONIZED , /* pseudo-synchronized ( GSM ) */	 
 CI_DEV_RR_HANDOVER_TYPE_WCDMA_INTRA_FREQUENCY , /* intra-frequency ( WCDMA ) */	 
 CI_DEV_RR_HANDOVER_TYPE_WCDMA_INTER_FREQUENCY , /* inter-frequency ( WCDMA ) */	 
 CI_DEV_RR_HANDOVER_TYPE_INTER_RAT_GSM_TO_WCDMA , /* inter-RAT ( GSM to WCDMA ) */	 
 CI_DEV_RR_HANDOVER_TYPE_INTER_RAT_WCDMA_TO_GSM /* inter-RAT ( WCDMA to GSM ) */	 
 } _CiDevRrhandoverType;

typedef UINT8 CiDevRrhandoverType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrhandoverType handoverType ; /* Type of handover to be performed */	 
 UINT8 targetBsic ; /* GERAN Target cell: BSIC ( 0xFF if not applicable ) */	 
 UINT16 targetArfcn ; /* Bit 15 : ARFCN is DCS ( 0 ) or PCS ( 1 ) Bits 0 -14: GERAN Target cell: ARFCN ( 0x7FFF if not applicable ) */	 
 UINT16 targetUarfcn ; /* UTRAN Target cell: UARFCN ( 0xFFFF if not applicable ) */	 
 UINT16 targetSc ; /* UTRAN Target cell: Primary Scrambling code ( 0xFFFF if not applicable ) */	 
 } CiDevGsmWbHandoverBgnEng_RR;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_HANDOVER_END_TYPE 
 {	 
 CI_DEV_RR_HANDOVER_END_COMPLETE = 0 , /* HANDOVER COMPLETE */	 
 CI_DEV_RR_HANDOVER_END_FAILURE , /* HANDOVER FAILURE */	 
 CI_DEV_RR_HANDOVER_END_TO_UTRAN_COMPLETE , /* HANDOVER TO UTRAN COMPLETE */	 
 CI_DEV_RR_HANDOVER_END_FROM_UTRAN_FAILURE , /* HANDOVER FROM UTRAN FAILURE */	 
 CI_DEV_RR_HANDOVER_END_WCDMA_INTER_FREQ_COMPLETE , /* RADIO BEARER SETUP COMPLETE... */	 
 CI_DEV_RR_HANDOVER_END_WCDMA_INTER_FREQ_FAILURE /* RADIO BEARER SETUP FAILURE... */	 
 } _CiDevRrhandoverEndType;

typedef UINT8 CiDevRrhandoverEndType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_CAUSE_TYPE 
 {	 
 CI_DEV_RR_CAUSE_NORMAL_EVENT = 0 , /* Normal event */	 
 CI_DEV_RR_CAUSE_ABNORMAL_REL_UNSPECIFIED = 1 , /* Abnormal release , unspecified */	 
 CI_DEV_RR_CAUSE_ABNORMAL_REL_CHAN_UNACCEPTABLE = 2 , /* Abnormal release , channel unacceptable */	 
 CI_DEV_RR_CAUSE_ABNORMAL_REL_TIMER_EXPIRED = 3 , /* Abnormal release , timer expired */	 
 CI_DEV_RR_CAUSE_ABNORMAL_REL_NO_ACT_ON_RADIO_PATH = 4 , /* Abnormal release , no activity on the radio path */	 
 CI_DEV_RR_CAUSE_PREEMPTIVE_RELEASE = 5 , /* Preemptive release */	 
 CI_DEV_RR_CAUSE_UTRAN_CONFIG_UNKNOWN = 6 , /* UTRAN configuration unknown */	 
 CI_DEV_RR_CAUSE_HO_IMPOSSIBLE_TA_OOR = 8 , /* Handover impossible , timing advance out of range */	 
 CI_DEV_RR_CAUSE_CHANNEL_MODE_UNACCEPTABLE = 9 , /* Channel mode unacceptable */	 
 CI_DEV_RR_CAUSE_FREQ_NOT_IMPLEMENTED = 10 , /* Frequency not implemented */	 
 CI_DEV_RR_CAUSE_ORIG_TALKER_LEAVING_GROUP_AREA = 11 , /* Originator or talker leaving group call area */	 
 CI_DEV_RR_CAUSE_LOWER_LAYER_FAILURE = 12 , /* Lower layer failure */	 
 CI_DEV_RR_CAUSE_CALL_ALREADY_CLEARED = 65 , /* Call already cleared */	 
 CI_DEV_RR_CAUSE_SEMAN_INCORRECT_MESSAGE = 95 , /* Semantically incorrect message */	 
 CI_DEV_RR_CAUSE_INVALID_MAND_INFO = 96 , /* Invalid mandatory information */	 
 CI_DEV_RR_CAUSE_MESSAGE_TYPE_NON_EXISTENT = 97 , /* Message type non-existent or not implemented */	 
 CI_DEV_RR_CAUSE_MESSAGE_TYPE_NOT_COMPATIBLE = 98 , /* Message type not compatible with protocol state */	 
 CI_DEV_RR_CAUSE_CONDITIONAL_IE_ERROR = 100 , /* Conditional IE error */	 
 CI_DEV_RR_CAUSE_NO_CELL_ALLOC_AVAILABLE = 101 , /* No cell allocation available */	 
 CI_DEV_RR_CAUSE_PROTOCOL_ERR_UNSPECIFIED = 111 /* Protocol error unspecified */	 
 } _CiDevRrCauseType;

typedef UINT8 CiDevRrCauseType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_IRAT_HANDOVER_FAILURE_TYPE 
 {	 
 CI_DEV_RR_IRAT_HO_CAUSE_CONFIGURATION_UNACCEPTABLE , /* Configuration unacceptable */	 
 CI_DEV_RR_IRAT_HO_CAUSE_PHYSICAL_CHAN_FAILURE , /* Physical Channel Failure */	 
 CI_DEV_RR_IRAT_HO_CAUSE_PROTOCOL_ERROR , /* Protocol Error */	 
 CI_DEV_RR_IRAT_HO_CAUSE_INTER_RAT_PROTOCOL_ERROR , /* Inter-Rat protocol error */	 
 CI_DEV_RR_IRAT_HO_CAUSE_UNSPECIFIED /* Unspecified */	 
 } _CiDevRrIrHandoverFailureType;

typedef UINT8 CiDevRrIrHandoverFailureType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_RRC_HANDOVER_FAILURE_TYPE 
 {	 
 CI_DEV_RR_FAILURE_CAUSE_CONFIGURATION_UNSUPPORTED = 0 , /* Configuration unsupported */	 
 CI_DEV_RR_FAILURE_CAUSE_PHYSICAL_CHANNEL_FAILURE , /* Physical Channel Failure */	 
 CI_DEV_RR_FAILURE_CAUSE_INCOMPAT_SIM_RECONFIGURATION , /* Incompatible Simultaneous Reconfiguration */	 
 CI_DEV_RR_FAILURE_CAUSE_COMPRESSED_MODE_RT_ERROR , /* Compressed Mode Runtime Error */	 
 CI_DEV_RR_FAILURE_CAUSE_PROTOCOL_ERROR , /* Protocol Error */	 
 CI_DEV_RR_FAILURE_CAUSE_CELL_UPDATE_OCCURRED , /* Cell Update Occurred */	 
 CI_DEV_RR_FAILURE_CAUSE_INVALID_CONFIGURATION , /* Invalid Configuration */	 
 CI_DEV_RR_FAILURE_CAUSE_CONFIGURATION_INCOMPLETE , /* Configuration Incomplete */	 
 CI_DEV_RR_FAILURE_CAUSE_UNSUPPORTED_MEASUREMENT , /* Unsupported Measurement */	 
 CI_DEV_RR_FAILURE_CAUSE_UNKNOWN = 255 /* Unknown or successful configuration */	 
 } _CiDevRrcHandoverFailureType;

typedef UINT8 CiDevRrcHandoverFailureType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrhandoverEndType handoverMsg ; /* Type of handover message sent */	 
 CiDevRrCauseType rrCause ; /* RR Cause IE from HANDOVER COMPLETE & HANDOVER FAILURE messages. The values are derived directly from 3 GPP TS 44.018000 section 10.500000 .2.31 , RR Cause */	 
 CiDevRrIrHandoverFailureType irHandoverFailure ; /* Inter-RAT handover failure cause for normal handovers */	 
 CiDevRrcHandoverFailureType rrcHandoverFailure ; /* RRC failure cause for UMTS hard handovers */	 
 CiDevRrProtErrCauseType iRProtCause ; /* Protocol error cause , only valid if ucIRFailure = IQ_IRAT_CAUSE_INTER_RAT_PROTOCOL_ERROR or IQ_FAILURE_CAUSE_PROTOCOL_ERROR */	 
 } CiDevGsmWbHandoverEndEng_RR;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RLC_UL_MODE_TYPE 
 {	 
 CI_DEV_RLC_MODE_UNKNOWN = 0 , /* Mode could not be determined */	 
 CI_DEV_RLC_MODE_UNACKNOWLEDGED , /* Unacknowledged mode */	 
 CI_DEV_RLC_MODE_ACKNOWLEDGED , /* Acknowledged mode */	 
 CI_DEV_RLC_MODE_TRANSPARENT , /* Transparent mode */	 
 CI_DEV_RLC_MODE_FLEXIBLELAYERONE /* FLO mode ( GPRS / EDGE only ) */	 
 } _CiDevRlcUlModeType;

typedef UINT8 CiDevRlcUlModeType ;
typedef CiDevRlcUlModeType CiDevRlcDlModeType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RLC_MCS_TYPE 
 {	 
 CI_DEV_RLC_MCS_TYPE_CS1 = 0 , /* GPRS Coding Scheme 1 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_CS2 , /* GPRS Coding Scheme 2 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_CS3 , /* GPRS Coding Scheme 3 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_CS4 , /* GPRS Coding Scheme 4 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS1 , /* EDGE Modulation Coding Scheme 1 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS2 , /* EDGE Modulation Coding Scheme 2 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS3 , /* EDGE Modulation Coding Scheme 3 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS4 , /* EDGE Modulation Coding Scheme 4 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS5 , /* EDGE Modulation Coding Scheme 5 ( 8 PSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS6 , /* EDGE Modulation Coding Scheme 6 ( 8 PSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS7 , /* EDGE Modulation Coding Scheme 7 ( 8 PSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS8 , /* EDGE Modulation Coding Scheme 8 ( 8 PSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS9 , /* EDGE Modulation Coding Scheme 9 ( 8 PSK ) */	 
 CI_DEV_RLC_MCS_TYPE_NOT_APPLICABLE = 255 /* The modulation and coding scheme is not applicable , e.g. , in the case of UMTS */	 
 } _CiDevRlcMcsType;

typedef UINT8 CiDevRlcMcsType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 rlcUlDuration ;	 
 UINT32 rlcUlByteCnt ;	 
 UINT32 rlcUlBlkCnt ;	 
 UINT32 rlcUlRetrBlkCnt ;	 
 UINT32 rlcDlDuration ;	 
 UINT32 rlcDlByteCnt ;	 
 UINT32 rlcDlBlkCnt ;	 
 UINT32 rlcDlMissingBlkCnt ;	 
 CiDevRlcUlModeType rlcUlMode ;	 
 CiDevRlcDlModeType rlcDlMode ;	 
 CiDevRlcMcsType ulCodingScheme ;	 
 CiDevRlcMcsType dlCodingScheme ;	 
 } CiDevGsmGprsEdgeRlcStatisticsEng_RLC;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_L1_CODEC_TYPE 
 {	 
 CI_DEV_L1_CODEC_TYPE_GSM_FR = 0 , /* GSM Full Rate ( 13.000000 kBit / s ) */	 
 CI_DEV_L1_CODEC_TYPE_GSM_HR , /* GSM Half Rate ( 5.600000 kBit / s ) */	 
 CI_DEV_L1_CODEC_TYPE_GSM_EFR , /* GSM Enhanced Full Rate ( 12.200000 kBit / s ) */	 
 CI_DEV_L1_CODEC_TYPE_FR_AMR , /* Full Rate Adaptive Multi-Rate */	 
 CI_DEV_L1_CODEC_TYPE_HR_AMR , /* Half Rate Adaptive Multi-Rate */	 
 CI_DEV_L1_CODEC_TYPE_UMTS_AMR , /* UMTS Adaptive Multi-Rate */	 
 CI_DEV_L1_CODEC_TYPE_UMTS_AMR2 , /* UMTS Adaptive Multi-Rate 2 */	 
 CI_DEV_L1_CODEC_TYPE_TDMA_EFR , /* TDMA Enhanced Full Rate ( 7.400000 kBit / s ) */	 
 CI_DEV_L1_CODEC_TYPE_PDC_EFR , /* PDC Enhanced Full Rate ( 6.700000 kBit / s ) */	 
 CI_DEV_L1_CODEC_TYPE_FR_AMR_WB , /* Full Rate Adaptive Multi-Rate WideBand */	 
 CI_DEV_L1_CODEC_TYPE_UMTS_AMR_WB , /* UMTS Adaptive Multi-Rate WideBand */	 
 CI_DEV_L1_CODEC_TYPE_OHR_AMR , /* 8 PSK Half Rate Adaptive Multi-Rate */	 
 CI_DEV_L1_CODEC_TYPE_OFR_AMR_WB , /* 8 PSK Full Rate Adaptive Multi-Rate WideBand */	 
 CI_DEV_L1_CODEC_TYPE_OHR_AMR_WB , /* 8 PSK Half Rate Adaptive Multi-Rate WideBand */	 
 CI_DEV_L1_CODEC_TYPE_NOT_APPLICABLE = 99 /* Speech codec not in use */	 
 } _CiDevL1CodecType;

typedef UINT8 CiDevL1CodecType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 dedArfcn ;	 
 UINT8 Maio ;	 
 UINT8 hsn ;	 
 UINT8 timeslot ;	 
 UINT8 rxLevelFull ;	 
 UINT8 rxLevelSub ;	 
 UINT8 rxQualFul ;	 
 UINT8 rxQualSub ;	 
 UINT8 ferFull ;	 
 UINT8 ferSub ;	 
 CiDevL1CodecType codec ;	 
 UINT8 timingAdv ;	 
 UINT8 powerLevel ;	 
 UINT8 dedConfig ;	 
 BOOL bandInd ;	 
 } CiDevGsmSrvCellInfoEng_L1;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 fer ;	 
 UINT8 ber ;	 
 UINT8 c2i ;	 
 UINT8 iLevel ;	 
 } CiDevL1GprsPdchType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevL1GprsPdchType pdch [ 8 ] ;	 
 UINT8 cValue ;	 
 UINT8 rxQual ;	 
 UINT8 meanBep ;	 
 UINT8 cvBep ;	 
 UINT8 signalVar ;	 
 } CiDevGsmGprsEdgeLinkQualityEng_L1;

typedef _CiDevRrProtocolDicriminatorType _CiDevRrNasProtDiscrType ;
typedef UINT8 CiDevRrNasProtDiscrType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrLogicalChannelType logicalTransportChannelType ;	 
 UINT8 rrcMessageType ;	 
 UINT8 rrcTransactionId ;	 
 CiDevRrNasProtDiscrType nasProtocolDiscriminator ;	 
 UINT8 nasMessageType ;	 
 UINT8 nasTransactionId ;	 
 UINT8 Msg [ 1520 ] ;	 
 } CiDevWbLayer3DwnlnkMsgEng_RRC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrLogicalChannelType logicalTransportChannelType ;	 
 UINT8 rrcMessageType ;	 
 UINT8 rrcTransactionId ;	 
 CiDevRrNasProtDiscrType nasProtocolDiscriminator ;	 
 UINT8 nasMessageType ;	 
 UINT8 nasTransactionId ;	 
 UINT8 Msg [ 1520 ] ;	 
 } CiDevWbLayer3UplnkMsgEng_RRC;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_RRC_STATE_TYPE 
 {	 
 CI_DEV_RRC_STATE_TYPE_IDLE = 0 , /* IDLE */	 
 CI_DEV_RRC_STATE_TYPE_URA_PCH , /* URA_PCH */	 
 CI_DEV_RRC_STATE_TYPE_CELL_PCH , /* CELL_PCH */	 
 CI_DEV_RRC_STATE_TYPE_CELL_FACH , /* CELL_FACH */	 
 CI_DEV_RRC_STATE_TYPE_CELL_DC /* CELL_DCH */	 
 } _CiDevRrRrcStateType;

typedef UINT8 CiDevRrRrcStateType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrRrcStateType rrcState ;	 
 } CiDevWbRrcStateEng_RRC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 tgpsId ;	 
 UINT8 tgpsStatus ;	 
 } CiDevRrCmInfoType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numCmInfo ;	 
 CiDevRrCmInfoType cmInfo [ 6 ] ;	 
 } CiDevWbCompressModeStateEng_RRC;

typedef CiDevRrInterRatMeasType CiDevRrCellsListType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numActive ;	 
 UINT8 numMonitored ;	 
 UINT8 numDetected ;	 
 CiDevRrCellsListType cells [ 32 + 32 ] ;	 
 } CiDevWbActiveAndMonitoredSetInfoEng_RRC;

typedef CiDevRrGsmNcellMeasType CiDevRrNeighMeasCellsListType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numMeas ;	 
 BOOL bandInd ;	 
 CiDevRrNeighMeasCellsListType measCells [ 32 ] ;	 
 } CiDevWbInterRatNeighborMeasEng_RRC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 Uarfcn ;	 
 UINT16 scellScramblingCode ;	 
 UINT8 scellRssi ;	 
 UINT8 scellEcN0 ;	 
 UINT8 scellRscp ;	 
 UINT8 txPower ;	 
 } CiDevWBRfInfoEng_RRC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 contextId ; /* The identity of PDP context associated with the referenced PS radio bearer */	 
 UINT8 rabId ; /* The identity of the PS radio access bearer ( RAB ) to which this structure pertains */	 
 UINT8 nsapi ; /* The NSAPI associated with the referenced PS RAB */	 
 UINT8 radioBearerId ; /* The identity of radio bearer currently associated with the referenced PS RAB */	 
 } CiDevRlcPsRbInfoType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 rabId ; /* The identity of the PS radio access bearer ( RAB ) to which this structure pertains */	 
 UINT8 radioBearerId ; /* The identity of radio bearer currently associated with the referenced CS RAB */	 
 } CiDevRlcCsRbInfoType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 radioBearerId ; /* The identity of the signaling radio bearer */	 
 } CiDevRlcSrbInfoType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numPsRb ; /* The number of PS RBs and PDP context IDs about which this metric contains information */	 
 UINT8 numCsRb ; /* The number of CS RBs about which this metric contains information */	 
 UINT8 numSrb ; /* The number of SRBs about which this metric contains information */	 
 CiDevRlcPsRbInfoType psRbInfo [ 11 ] ; /* An array of structures of type CiRlcPsRbInfoType */	 
 CiDevRlcCsRbInfoType csRbInfo [ 3 ] ; /* An array of structures of type CiRlcCsRbInfoType */	 
 CiDevRlcSrbInfoType srbRbInfo [ 8 ] ; /* An array of structures of type CiRlcSrbInfoType */	 
 } CiDevWBMultiRabStateEng_RLC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 userRBId ; /* The ID of the user radio bearer to which this structure pertains */	 
 CiDevRlcUlModeType rlcMode ; /* The RLC mode of operation for this radio bearer this metric pertains in milliseconds */	 
 UINT32 rlcByteCnt ; /* Number of new RLC data ( payload ) bytes received ( UL ) or transmitted ( DL ) on this radio bearer */	 
 UINT32 rlcBlkCnt ; /* Number of new RLC PDUs received or transmitted on this radio bearer */	 
 UINT32 rlcRetrBlkCnt ; /* Number retransmitted PDUs ( UL ) or number of PDUs requested for retransmission ( DL ) on this radio bearer */	 
 } CiDevRlcUlStatsType;

typedef CiDevRlcUlStatsType CiDevRlcDlStatsType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 unsigned long rlcUlDuration ; /* RLC uplink measurement period to which this metric pertains in milliseconds */	 
 unsigned long rlcDlDuration ; /* RLC downlink measurement period to which this metric pertains in milliseconds */	 
 unsigned char numUlUserRB ; /* Number of uplink user radio bearers to which this metric pertains ( The deprecated name of this field was ucNumUlTrCh ) */	 
 unsigned char numDlUserRB ; /* Number of user radio bearers to which this metric pertains ( The deprecated name of this field was ucNumDlTrCh ) */	 
 CiDevRlcUlStatsType rlcUlStats [ 11 ] ; /* An array of structure type iq_rb_rlc_stats_t whose length is numUlUserRB ( The deprecated name of this field was iq_trch_rlc_stats_t ) */	 
 CiDevRlcDlStatsType rlcDlStats [ 11 ] ; /* An array of structure type iq_rb_rlc_stats_t whose length is numDlUserRB ( The deprecated name of this field was iq_trch_rlc_stats_t ) */	 
 } CiDevWBUmtsHspaRlcStatisticsEng_RLC;

//ICAT EXPORTED ENUM 
 typedef enum UrlcEngModeResetPduTypeTag 
 {	 
 URLC_ENG_MODE_RESET_PDU = 1 ,	 
 URLC_ENG_MODE_RESET_ACK_PDU = 2	 
 } UrlcEngModeResetPduType;

//ICAT EXPORTED ENUM 
 typedef enum UrlcEngModeDirectionTypeTag 
 {	 
 URLC_ENG_MODE_DL_DIRECTION = 0 , /* The PDU was received by the UE */	 
 URLC_ENG_MODE_UL_DIRECTION = 1 /* The PDU was transmitted by the UE */	 
 } UrlcEngModeDirectionType;

//ICAT EXPORTED ENUM 
 typedef enum UrlcEngModeMaxResetTag 
 {	 
 URLC_ENG_MODE_MAX_RESET_NOT_REACHED = 0 , /* MaxRST has not yet been reached for this AM-RLC entity */	 
 URLC_ENG_MODE_MAX_RESET_REACHED = 1 /* MaxRST has been reached ( i.e. , transmission of this PDU is prohibited ) All other values are reserved */	 
 } UrlcEngModeMaxReset;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 radioBearerId ;	 
 UINT8 direction ; /* 0 : The PDU was received by the UE	 
 * 1 : The PDU was transmitted by the UE	 
 * All other values are reserved */	 
 UINT8 pduType ; /* The type of PDU to which this metric pertains:	 
 * 1 : RESET PDU	 
 * 2 : RESET ACK PDU	 
 * All other values are reserved	 
 * NOTE: This field corresponds to PDU Type as defined in 3 GPP TS 25.322000 / 9.200000 .2.2 */	 
	 
 UINT8 resetSeqNum ; /* The sequence number of the reset transaction to which this metric pertains.	 
 * Shall be set to 255 if the Reset sequence , Number is not available	 
 * NOTE: This field corresponds to Reset Sequence Number as defined in 3 GPP TS 25.322000 / 9.200000 .2.13 */	 
	 
 UINT8 maxRst ; /* 0 : MaxRST has not yet been reached for this AM-RLC entity	 
 * 1 : MaxRST has been reached ( i.e. , transmission of this PDU is prohibited )	 
 * All other values are reserved */	 
 } CiDevWBRlcResetEng_RLC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 txDuration ; /* Duration of measurement period in milliseconds */	 
 UINT32 octetCnt ; /* Total number of octets transmitted in the measurement period , including retransmissions */	 
 UINT16 ackBlkCnt ; /* Positive acknowledgment ( ACK ) block count , indicating the number of blocks transmitted	 
 by the UE and successfully received by the Node B */	 
	 
 UINT16 nackBlkCnt ; /* Negative acknowledgment ( NACK ) block count , indicating the number of blocks transmitted	 
 by the UE but not successfully decoded / received by the Node B */	 
	 
 UINT8 servingGrant [ 32 ] ;	 
 /* Uplink Serving Grant contains distribution count of E-AGCH	 
 Absolute Grant Value Indexes observed during that metric reporting period */	 
	 
 UINT16 servingCell ; /* From PHY yyyy metric , HSUPA Serving Cell */	 
	 
	 
 UINT16 happyCnt ; /* The happy bit count is the number of sampled happy bits during the measurement period */	 
	 
	 
 UINT16 unhappyCnt ; /* The unhappy bit count is the number of sampled unhappy bits during the measurement period */	 
	 
 UINT16 etfciSampleCnt ; /* Number of E-TFCI samples in the array ETFCI */	 
	 
 UINT8 etfci [ 128 ] ;	 
 /* Array of uplink E-DCH transport format combination indicator ( E-TFCI )	 
 samples in the range ( 0 ..127 ) , used to identify the transport block size on E-DCH */	 
	 
	 
 UINT16 bpskBlkCnt ; /* From PHY yyyy metric , number of transport blocks transmitted using BSPK modulation */	 
	 
	 
 UINT16 qam16BlkCnt ; /* From PHY yyyy metric , number of transport blocks transmitted using 16 QAM modulation */	 
 } CiDevWBHsupaStatisticsEng_Phy;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 ack ;	 
 UINT16 nack ;	 
 UINT16 dtx ;	 
 } CiDevPhycCqiDistType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 qpskBlkCnt ;	 
 UINT16 qam16BlkCnt ;	 
 UINT16 Qam64BlkCnt ;	 
 UINT16 decodeAttemptCnt ;	 
 UINT16 decodeValidCnt ;	 
 UINT16 hsScchLessCnt ;	 
 CiDevPhycCqiDistType cqiDistPrimary [ 31 ] ;	 
 UINT16 numCodesAlloc [ 16 ] ;	 
 UINT16 mimoCqiReporting ;	 
 UINT16 trBlkSizePrSampleCnt ;	 
 UINT16 trBlkSizeSecSampleCnt ; /* Not in use */	 
 UINT16 numPciAlloc [ 4 ] ;	 
 CiDevPhycCqiDistType cqiDistSecondary [ 31 ] ;	 
 UINT16 trBlkSizePrimary [ 100 ] ; /* Size is max of trBlkSizePrSampleCnt */	 
 } CiDevPhycHsDschStatsType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 rcvByteCnt ;	 
 UINT16 hsDschCellCnt ;	 
 CiDevPhycHsDschStatsType hsDschCelStats [ 2 ] ;	 
 } CiDevWBHsdpaEvolvedStatisticsEng_Phy;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_PHYC_TRANSPORT_CH_TYPE 
 {	 
 CI_DEV_PHYC_TR_CH_TYPE_DL_DCH = 0 , /* Downlink dedicated transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_UL_DCH , /* Uplink dedicated transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_EDCH , /* Enhanced ( uplink ) dedicated transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_BCH , /* Broadcast common transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_FACH , /* Forward access common transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_PCH , /* Paging common transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_RACH , /* Random access common transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_HSDSCH , /* High speed downlink shared transport channel */	 
 CI_DEV_TR_CH_TYPE_UNKNOWN = 255 /* The transport channel type is unknown */	 
 } _CiDevPhycTransportChType;

typedef UINT8 CiDevPhycTransportChType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 trChId ;	 
 CiDevPhycTransportChType trChType ;	 
 UINT16 numTrBlocks ;	 
 UINT16 numErrTrBlocks ;	 
 } CiDevL1TransportChType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numTrCh ;	 
 CiDevL1TransportChType trCh [ 25 ] ;	 
 } CiDevWBUmtsHspaTransportChannelInfoEng_L1;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_L1_T313_STATUS_TYPE 
 {	 
 CI_DEV_L1_T313_STATUS_STOPPED = 0 , /* The T313 timer for the RLS is stopped ( the radio link has been restored ) */	 
 CI_DEV_L1_T313_STATUS_RUNNING , /* The T313 timer for the RLS has been started */	 
 CI_DEV_L1_T313_STATUS_EXPIRED , /* The T313 timer for the RLS has expired ( the radio link has failed ) */	 
 CI_DEV_L1_T313_STATUS_UNKNOWN = 255 /* The T313 timer is status is invalid or unknown , or this field is not applicable */	 
 } _CiDevL1T313StatusType;

typedef UINT8 CiDevL1T313StatusType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 ScramblingCode ;	 
 UINT8 tpcCombinationIndex ;	 
 CiDevL1T313StatusType t313Status ;	 
 } CiDevL1SyncStatusType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numRlSyncStatus ;	 
 CiDevL1SyncStatusType RlSyncStatus [ 6 ] ;	 
 } CiDevWBUmtsHspaRadioLinkSyncStatusEng_L1;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_COMMON_ENGMODE_INFO_TAG 
 {	 
 CI_DEV_LT01_ERRC_MSG = 0 , /* E-UTRA RRC Message */	 
 CI_DEV_LT02_NAS_MSG , /* E-UTRA NAS Message */	 
 CI_DEV_LT03_LTE_MSR_MSG , /* E-UTRA Measurement Report */	 
 CI_DEV_LT04_LTE_INTER_MSR_MSG , /* E-UTRA Inter-RAT Measurement Report */	 
 CI_DEV_LT05_LTE_NEIGHBOR_LIST_MSG , /* E-UTRA Neighbor List */	 
 CI_DEV_LT06_LTE_ERRC_STATE_MSG , /* E-UTRA RRC State */	 
 CI_DEV_LT07_LTE_MAC_CONTROL_MSG , /* E-UTRA MAC Control State */	 
 CI_DEV_LT08_LTE_MAC_RACH_MSG , /* E-UTRA MAC Random Access Attempt */	 
 CI_DEV_LT17_LTE_RLC_MSG , /* E-UTRA RLC Data Transfer Report */	 
 CI_DEV_LT10_LTE_EPS_MSG , /* E-UTRA EPS Bearer Context Status */	 
 CI_DEV_LT11_LTE_EPS_QOS_MSG , /* E-UTRA EPS Bearer QoS */	 
 CI_DEV_LT12_LTE_PUSCH_STATUS_MSG , /* E-UTRA PUSCH Transmission Status */	 
 CI_DEV_LT13_LTE_RADIO_LINK_MSG , /* E-UTRA Radio Link Sync Status */	 
 CI_DEV_GS15_SM_PDP_CONTECXT_ACTIVATION , /* GSM / UMTS PDP Context Activation SM Message */	 
 CI_DEV_GS18_SM_PDP_CONTEXT_END , /* GSM / UMTS PDP Context End SM Message */	 
 CI_DEV_GS19_SM_PDP_CONTEXT_REQUEST , /* GSM / UMTS PDP Context Request SM Message */	 
 CI_DEV_GS40_MM_ATTACH_BEGIN , /* GSM / UMTS Attach Begin MM Message */	 
 CI_DEV_GS41_MM_ATTACH_END , /* GSM / UMTS Attach End MM Message */	 
 CI_DEV_GS42_MM_DETACH_END , /* GSM / UMTS Detach Accept MM Message */	 
 CI_DEV_GS43_MM_ROUTING_AREA_UPDATE , /* GSM / UMTS Routing Area Update MM Message */	 
 CI_DEV_GS46_MM_NETWORK_INFO , /* GSM / GPRS / UMTS Network Info MM Message */	 
 CI_DEV_GS47_MM_SERVICE_STATE , /* GSM / GPRS / UMTS Service State MM Message */	 
 CI_DEV_GS6E_MM_RADIO_MODE , /* GSM / GPRS / UMTS Radio Mode MM Message */	 
 CI_DEV_GS30_GRR_LAYER_3_DOWNLINK_MSG , /* GSM / GPRS / EDGE Layer 3 Downlink Message GRR Message */	 
 CI_DEV_GS31_GRR_LAYER_3_UPLINK_MSG , /* GSM / GPRS / EDGE Layer 3 Uplink Message GRR Message */	 
 CI_DEV_RF51_GRR_GSM_GPRS_EDGE_RF_SERVING_CELL_INFO , /* GSM Serving Cell Info GRR Message */	 
 CI_DEV_RF53_GRR_NEIGHBOR_MEASUERMENT_MSG , /* GSM Neighbor Measurement GRR Message */	 
 CI_DEV_GS57_RR_CELL_CHANGE_BEGIN_MSG , /* GSM and WB Cell Change Begin RR Message */	 
 CI_DEV_GS58_RR_CELL_CHANGE_END_MSG , /* GSM and WB Cell Change End RR Message */	 
 CI_DEV_GS54_RR_HANDOVER_BEGIN_MSG , /* GSM and WB Handover Begin RR Message */	 
 CI_DEV_GS55_RR_HANDOVER_END_MSG , /* GSM and WB Handover End RR Message */	 
 CI_DEV_GS81_RLC_GPRS_EDGE_RLC_STATISTICS , /* GPRS / EDGE RLC Statistics RLC Message */	 
 CI_DEV_RF52_L1_GSM_SERVING_CELL_INFO_MSG , /* GSM Serving Cell Info L1 Message */	 
 CI_DEV_RF54_L1_GPRS_EDGE_LINK_QUALITY_MSG , /* GSM Gprs Edge Link Quality L1 Message */	 
 CI_DEV_GS34_RRC_UMTS_HSPA_LAYER3_DOWNLINK_MSG , /* WB UMTS / HSPA Layer 3 Downlink RRC Message */	 
 CI_DEV_GS35_RRC_UMTS_HSPA_LAYER3_UPLINK_MSG , /* WB UMTS / HSPA Layer 3 Uplink RRC Message */	 
 CI_DEV_GS67_RRC_STATE_MSG , /* WB RRC State RRC Message */	 
 CI_DEV_GS6F_RRC_COMPRESS_MODE_STATE_MSG , /* WB CompressModeState RRC Message */	 
 CI_DEV_RF61_RRC_UMTS_HSPA_ACTIVE_AND_MONITORED_SET_INFO_MSG , /* WB UMTS / HSPA Active and Monitored Set Info RRC Message */	 
 CI_DEV_RF62_RRC_INTER_NEIGHBOR_MEAS_MSG , /* WB Inter Neighbor Measurement RRC Message */	 
 CI_DEV_RF60_RRC_RF_SERVING_CELL_INFO_MSG , /* WB RF and Serving Cell Info RRC Message */	 
 CI_DEV_GS6D_RLC_WB_MULTI_RAB_STATE_MSG , /* WB Multi-RAB State RLC Message */	 
 CI_DEV_GS84_RLC_UMTS_HSPA_RLC_STATISTICS_MSG , /* WB UMTS / HSPA RLC Statistics RLC Message */	 
 CI_DEV_GS86_RLC_RESET_MSG , /* WB RLC Reset RLC Message */	 
 CI_DEV_GS83_PHY_HSUPA_STATISTICS_MSG , /* WB HSUPA Statistics PHY Message */	 
 CI_DEV_GS88_PHY_HSDPA_EVOLVED_STATISTIC_MSG , /* WB HSDPA Evolved Statistics PHY Message */	 
 CI_DEV_RF63_L1_UMTS_HSPA_TRANSPORT_CHANNEL_INFO_MSG , /* WB UMTS / HSPA Transport Channel Info L1 Message */	 
 CI_DEV_RF64_L1_UMTS_HSPA_RADIO_LINK_SYNC_STATUS_MSG , /* WB UMTS / HSPA Radio Link Sync Status L1 Message */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_INFO_TYPES	 
 } _CiDevCommonEngmodeInfoType;

typedef UINT8 CiDevCommonEngmodeInfoType ;
//ICAT EXPORTED UNION : _CiDevCommonEngmodeInfoType 
 typedef union CiDevCommonEngmodeInfo_struct 
 {	 
 CiDevLteEng_RRC LT01 ; /* E-UTRA RRC Message */	 
 CiDevLteEng_NAS LT02 ; /* E-UTRA NAS Message */	 
 CiDevLteEng_MSR LT03 ; /* E-UTRA Measurement Report */	 
 CiDevLteEng_InterMsr LT04 ; /* E-UTRA Inter-RAT Measurement Report */	 
 CiDevLteEng_NeighborList LT05 ; /* E-UTRA Neighbor List */	 
 CiDevLteEng_RrcState LT06 ; /* E-UTRA RRC State */	 
 CiDevLteEng_MAC LT07 ; /* E-UTRA MAC Control State */	 
 CiDevLteEng_MAC_RACH LT08 ; /* E-UTRA MAC Random Access Attempt */	 
 CiDevLteEng_RLC LT17 ; /* E-UTRA RLC Data Transfer Report */	 
 CiDevLteEng_EPS LT10 ; /* E-UTRA EPS Bearer Context Status */	 
 CiDevLteEng_EPS_QoS LT11 ; /* E-UTRA EPS Bearer QoS */	 
 CiDevLteEng_PUSCH LT12 ; /* E-UTRA PUSCH Transmission Status */	 
 CiDevLteEng_RadioLink LT13 ; /* E-UTRA Radio Link Sync Status */	 
 CiDevGsmUmtsComnPdpCActEng_SM GS15 ; /* PDP Context Activation GSM / UMTS PDP Context Activation SM Message */	 
 CiDevGsmUmtsComnPdpCEndEng_SM GS18 ; /* PDP Context End GSM / UMTS PDP Context End SM Message */	 
 CiDevGsmUmtsComnPdpCReqEng_SM GS19 ; /* PDP Context Request GSM / UMTS PDP Context Request SM Message */	 
 CiDevGsmUmtsComnAttachBeginEng_MM GS40 ; /* Attach Begin GSM / UMTS Attach Begin MM Message */	 
 CiDevGsmUmtsComnAttachEndEng_MM GS41 ; /* Attach End GSM / UMTS Attach End MM Message */	 
 CiDevGsmUmtsComnDetachAcceptEng_MM GS42 ; /* Detach Accept GSM / UMTS Detach Accept MM Message */	 
 CiDevGsmUmtsComnRAUEng_MM GS43 ; /* Routing Area Update GSM / UMTS Routing Area Update MM Message */	 
 CiDevGsmUmtsComnNetInfoEng_MM GS46 ; /* GSM / GPRS / UMTS Network Info GSM / GPRS / UMTS Network Info MM Message */	 
 CiDevGsmUmtsComnServcStateEng_MM GS47 ; /* Service State GSM / GPRS / UMTS Service State MM Message */	 
 CiDevGsmUmtsComnRadioModeEng_MM GS6E ; /* Radio Mode GSM / GPRS / UMTS Radio Mode MM Message */	 
 CiDevGsmLayer3DwnlnkMsgEng_GRR GS30 ; /* GSM / GPRS / EDGE Layer 3 Downlink Message GSM / GPRS / EDGE Layer 3 Downlink Message GRR Message */	 
 CiDevGsmLayer3UplnkMsgEng_GRR GS31 ; /* GSM / GPRS / EDGE Layer 3 Uplink Message GSM / GPRS / EDGE Layer 3 Uplink Message GRR Message */	 
 CiDevGsmRfServingCellInfoEng_GRR RF51 ; /* GSM / GPRS / EDGE RF Serving Cell Info GSM Serving Cell Info GRR Message */	 
 CiDevGsmNeighbrMeasEng_GRR RF53 ; /* GSM Neighbor Measurements GSM Neighbor Measurement GRR Message */	 
 CiDevGsmWbCellChngBginEng_RR GS57 ; /* Cell Change Begin GSM and WB Cell Change Begin RR Message */	 
 CiDevGsmWbCellChngEndEng_RR GS58 ; /* Cell Change End GSM and WB Cell Change End RR Message */	 
 CiDevGsmWbHandoverBgnEng_RR GS54 ; /* Handover Begin GSM and WB Handover Begin RR Message */	 
 CiDevGsmWbHandoverEndEng_RR GS55 ; /* Handover End GSM and WB Handover End RR Message */	 
 CiDevGsmGprsEdgeRlcStatisticsEng_RLC GS81 ; /* GPRS / EDGE RLC Statistics GPRS / EDGE RLC Statistics RLC Message */	 
 CiDevGsmSrvCellInfoEng_L1 RF52 ; /* GSM RF Dedicated Set Info GSM Serving Cell Info L1 Message */	 
 CiDevGsmGprsEdgeLinkQualityEng_L1 RF54 ; /* GPRS / EDGE Link Quality Info GSM Gprs Edge Link Quality L1 Message */	 
 CiDevWbLayer3DwnlnkMsgEng_RRC GS34 ; /* UMTS / HSPA Layer 3 Downlink Message WB UMTS / HSPA Layer 3 Downlink RRC Message */	 
 CiDevWbLayer3UplnkMsgEng_RRC GS35 ; /* UMTS / HSPA Layer 3 UPLINK Message WB UMTS / HSPA Layer 3 Uplink RRC Message */	 
 CiDevWbRrcStateEng_RRC GS67 ; /* RRC State WB RRC State RRC Message */	 
 CiDevWbCompressModeStateEng_RRC GS6F ; /* Compress Mode State WB CompressModeState RRC Message */	 
 CiDevWbActiveAndMonitoredSetInfoEng_RRC RF61 ; /* UMTS / HSPA Active and Monitored Set Info WB UMTS / HSPA Active and Monitored Set Info RRC Message */	 
 CiDevWbInterRatNeighborMeasEng_RRC RF62 ; /* UMTS / HSPA Inter RAT Neighbor Measurements WB Inter Neighbor Measurement RRC Message */	 
 CiDevWBRfInfoEng_RRC RF60 ; /* UMTS / HSPA RF Info WB RF and Serving Cell Info RRC Message */	 
 CiDevWBMultiRabStateEng_RLC GS6D ; /* Multi-RAB State WB Multi-RAB State RLC Message */	 
 CiDevWBUmtsHspaRlcStatisticsEng_RLC GS84 ; /* UMTS / HSPA RLC Statistics WB UMTS / HSPA RLC Statistics RLC Message */	 
 CiDevWBRlcResetEng_RLC GS86 ; /* RLC Reset WB RLC Reset RLC Message */	 
 CiDevWBHsupaStatisticsEng_Phy GS83 ; /* HSUPA Statistics WB HSUPA Statistics PHY Message */	 
 CiDevWBHsdpaEvolvedStatisticsEng_Phy GS88 ; /* HSDPA Evolved Statistics WB HSDPA Evolved Statistics PHY Message */	 
 CiDevWBUmtsHspaTransportChannelInfoEng_L1 RF63 ; /* UMTS / HSPA Transport Channel Info WB UMTS / HSPA Transport Channel Info L1 Message */	 
 CiDevWBUmtsHspaRadioLinkSyncStatusEng_L1 RF64 ; /* UMTS / HSPA Radio Link Sync Status WB UMTS / HSPA Radio Link Sync Status L1 Message */	 
 } CiDevCommonEngmodeInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonEngmodeInfoInd_struct 
 {	 
 CiDevCommonEngmodeInfoType type ;	 
 CiDevCommonEngmodeInfo info ;	 
 } CiDevCommonEngmodeInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonEngmodeDB_struct 
 {	 
 CiDevLteEng_RRC LT01 ; /* E-UTRA RRC Message */	 
 CiDevLteEng_NAS LT02 ; /* E-UTRA NAS Message */	 
 CiDevLteEng_MSR LT03 ; /* E-UTRA Measurement Report */	 
 CiDevLteEng_InterMsr LT04 ; /* E-UTRA Inter-RAT Measurement Report */	 
 CiDevLteEng_NeighborList LT05 ; /* E-UTRA Neighbor List */	 
 CiDevLteEng_RrcState LT06 ; /* E-UTRA RRC State */	 
 CiDevLteEng_MAC LT07 ; /* E-UTRA MAC Control State */	 
 CiDevLteEng_MAC_RACH LT08 ; /* E-UTRA MAC Random Access Attempt */	 
 CiDevLteEng_RLC LT17 ; /* E-UTRA RLC Data Transfer Report */	 
 CiDevLteEng_EPS LT10 ; /* E-UTRA EPS Bearer Context Status */	 
 CiDevLteEng_EPS_QoS LT11 ; /* E-UTRA EPS Bearer QoS */	 
 CiDevLteEng_PUSCH LT12 ; /* E-UTRA PUSCH Transmission Status */	 
 CiDevLteEng_RadioLink LT13 ; /* E-UTRA Radio Link Sync Status */	 
 } CiDevCommonEngmodeDB;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_EXT_ENGMODE_REPORTOPTION_TAG 
 {	 
 CI_DEV_EM_OPTION_TURN_OFF , /**< Engineering mode report delivery: Turn off */	 
 CI_DEV_EM_OPTION_START /**< Engineering mode report delivery: Turn On */	 
 } _CiDevExtEngModeReportOption;

typedef UINT8 CiDevExtEngModeReportOption ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetExtEngmodeRepOptReq_struct 
 {	 
 CiDevExtEngModeReportOption reportOption ; /* Start / Stop Eng Info report */	 
 UINT32 reporting [ 2 ] ;	 
 } CiDevPrimSetExtEngmodeRepOptReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetExtEngmodeRepOptCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ;	 
 } CiDevPrimSetExtEngmodeRepOptCnf;

typedef CiEmptyPrim CiDevPrimGetExtEngmodeInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetExtEngmodeInfoCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 } CiDevPrimGetExtEngmodeInfoCnf;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_PRIM {	 
 CI_DEV_PRIM_STATUS_IND = 1 , /**< \brief Indicates that the device status has changed \details The client should not begin its initialization process before receiving CI_DEV_PRIM_STATUS_IND ( CI_DEV_STATUS_READY ) . This indication cannot be disabled. */	 
 CI_DEV_PRIM_GET_MANU_ID_REQ , /**< \brief Requests the manufacturer ID \details */	 
 CI_DEV_PRIM_GET_MANU_ID_CNF , /**< \brief Confirms a request and returns the manufacturer ID \details */	 
 CI_DEV_PRIM_GET_MODEL_ID_REQ , /**< \brief Requests the model ID \details */	 
 CI_DEV_PRIM_GET_MODEL_ID_CNF , /**< \brief Confirms a request and returns the model ID \details */	 
 CI_DEV_PRIM_GET_REVISION_ID_REQ , /**< \brief Requests the revision ID \details */	 
 CI_DEV_PRIM_GET_REVISION_ID_CNF , /**< \brief Confirms a request and returns the revision ID \details */	 
 CI_DEV_PRIM_GET_SERIALNUM_ID_REQ , /**< \brief Requests the serial number ID ( IMEI ) \details */	 
 CI_DEV_PRIM_GET_SERIALNUM_ID_CNF , /**< \brief Confirms a request and returns the serial number ID \details */	 
 CI_DEV_PRIM_SET_FUNC_REQ = 10 , /**< \brief Requests to set the level of functionality in the cellular subsystem \details */	 
 CI_DEV_PRIM_SET_FUNC_CNF , /**< \brief Confirms a request and sets the level of functionality in the cellular subsystem \details */	 
 CI_DEV_PRIM_GET_FUNC_REQ , /**< \brief Requests to get the level of functionality in the cellular subsystem \details */	 
 CI_DEV_PRIM_GET_FUNC_CNF , /**< \brief Confirms a request and returns the level of functionality in the cellular subsystem \details */	 
 CI_DEV_PRIM_GET_FUNC_CAP_REQ , /**< \brief Requests to get the level of functional capability in the cellular subsystem \details */	 
 CI_DEV_PRIM_GET_FUNC_CAP_CNF , /**< \brief Confirms a request and returns the level of functional capability in the cellular subsystem \details */	 
 CI_DEV_PRIM_SET_GSM_POWER_CLASS_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_SET_GSM_POWER_CLASS_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_GET_GSM_POWER_CLASS_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_GET_GSM_POWER_CLASS_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_GET_GSM_POWER_CLASS_CAP_REQ = 20 , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_GET_GSM_POWER_CLASS_CAP_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
	 
 CI_DEV_PRIM_PM_POWER_DOWN_REQ , /**< \brief Requests to perform power down for the current device \details */	 
 CI_DEV_PRIM_PM_POWER_DOWN_CNF , /**< \brief Confirms a request and powers down the current device \details */	 
	 
 CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_REQ , /**< \brief Requests to set the option for reporting engineering mode information \details If the Periodic option is selected: \n-	 
 * - For GSM , CCI sends a periodic CI_DEV_PRIM_GSM_ENGMODE_INFO_IND indication containing the current engineering mode information. For UMTS , the following periodic messages are sent: \n	 
 * CI_DEV_PRIM_UMTS_ENGMODE_SVCCELL_INFO_IND \n	 
 * CI_DEV_PRIM_UMTS_ENGMODE_INTERFREQ_INFO_IND \n	 
 * CI_DEV_PRIM_UMTS_ENGMODE_INTRAFREQ_INFO_IND \n	 
 * CI_DEV_PRIM_UMTS_ENGMODE_INTERRAT_INFO_IND \n	 
 * The report interval is received as the parameter interval of the CiDevPrimSetEngmodeRepOptReq structure.	 
 * If the request option is selected , the application requests current engineering mode information using the CI_DEV_PRIM_GET_ENGMODE_INFO_REQ request.	 
 * The default option is on request. */	 
 CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_CNF , /**< \brief Confirms a request and sets the option for reporting engineering mode information \details */	 
 CI_DEV_PRIM_GET_ENGMODE_INFO_REQ , /**< \brief Requests current engineering mode information \details Use this request when the engineering mode report option is set to on request.	 
 * Engineering mode information is currently available for GSM as well as for UMTS. */	 
 CI_DEV_PRIM_GET_ENGMODE_INFO_CNF , /**< \brief Confirms a request and returns current engineering mode information \details Engineering mode information is currently available for GSM as well as UMTS. */	 
 CI_DEV_PRIM_ENGMODE_INFO_IND , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
	 
 CI_DEV_PRIM_GSM_ENGMODE_INFO_IND , /**< \brief Indicates current GSM engineering mode information \details */	 
 CI_DEV_PRIM_UMTS_ENGMODE_SVCCELL_INFO_IND = 30 , /**< \brief Indicates UMTS engineering mode serving cell information \details */	 
 CI_DEV_PRIM_UMTS_ENGMODE_INTRAFREQ_INFO_IND , /**< \brief Indicates UMTS engineering mode intra-frequency measurements information \details */	 
 CI_DEV_PRIM_UMTS_ENGMODE_INTERFREQ_INFO_IND , /**< \brief Indicates UMTS engineering mode inter-frequency measurements information \details */	 
 CI_DEV_PRIM_UMTS_ENGMODE_INTERRAT_INFO_IND , /**< \brief Indicates UMTS engineering mode inter-rat measurements information \details */	 
 CI_DEV_PRIM_DO_SELF_TEST_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_DO_SELF_TEST_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_DO_SELF_TEST_IND , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_SET_RFS_REQ , /**< \brief Requests to change the current reset factory settings \details */	 
 CI_DEV_PRIM_SET_RFS_CNF , /**< \brief Confirms a request and changes the current reset factory setting \details */	 
 CI_DEV_PRIM_GET_RFS_REQ , /**< \brief Requests to obtain the current reset factory settings \details */	 
 CI_DEV_PRIM_GET_RFS_CNF = 40 , /**< \brief Confirms a request and obtains the current reset factory settings \details */	 
 CI_DEV_PRIM_UMTS_ENGMODE_ACTIVE_SET_INFO_IND , /**< \brief Indicates UMTS engineering mode active set information \details */	 
 CI_DEV_PRIM_ACTIVE_PDP_CONTEXT_ENGMODE_IND , /**< \brief Indicates engineering mode active PDP context information \details */	 
 CI_DEV_PRIM_NETWORK_MONITOR_INFO_IND , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_LP_NWUL_MSG_REQ , /**< \brief Requests the PS to deliver a location position message to the network	 
 * \details The message can contain the location results , location error , or protocol error. */	 
 CI_DEV_PRIM_LP_NWUL_MSG_CNF , /**< \brief Confirms a request and delivers a location position message to the network \details */	 
 CI_DEV_PRIM_LP_NWDL_MSG_IND , /**< \brief Indicates a request from the network to provide location position information , for example , assistance data , location request , or a combination of the two	 
 * \details */	 
 CI_DEV_PRIM_LP_RRC_STATE_IND , /**< \brief Indicates a change in the RRC state \details It should be called by ABPS whenever the RRC state changes while a positioning session is active. */	 
 CI_DEV_PRIM_LP_MEAS_TERMINATE_IND , /**< \brief Indicates that the PS terminated the current location session \details A location session is terminated when PS changes RAT or enters out of service. */	 
 CI_DEV_PRIM_LP_RESET_STORED_UE_POS_IND , /**< \brief Indicates a request from the network to reset all stored assistance data	 
 * \details This is a test I / F message ( TIM ) ; therefore , it is not sent by a real network. */	 
 /*Michal Bukai - Silent Reset support - START*/	 
 CI_DEV_PRIM_COMM_ASSERT_REQ = 50 , /**< \brief Requests the communication subsystem to assert \details There is no confirmation for this primitive. This primitive is used for testing. */	 
 /*Michal Bukai - Silent Reset support - END*/	 
 /*Michal Bukai *BAND support - START*/	 
 CI_DEV_PRIM_SET_BAND_MODE_REQ , /**< \brief Requests the PS to set band and RAT mode	 
 * \details The communication subsystem performs a SW reset after sending the confirmation for updating RAT and band.	 
 * If the requested RAT is dual mode , the communication subsystem resets to default band parameters. */	 
	 
 CI_DEV_PRIM_SET_BAND_MODE_CNF , /**< \brief Confirms a request and sets band and RAT mode parameters	 
 * \details The communication subsystem performs a SW reset after sending the confirmation for updating RAT and band.*/	 
 CI_DEV_PRIM_GET_BAND_MODE_REQ , /**< \brief Requests to read the current band and RAT mode setting */	 
 CI_DEV_PRIM_GET_BAND_MODE_CNF , /**< \brief Confirms the request and returns the current band and RAT mode setting */	 
 CI_DEV_PRIM_GET_SUPPORTED_BAND_MODE_REQ , /**< \brief Requests the supported bands and supported RAT modes */	 
 CI_DEV_PRIM_GET_SUPPORTED_BAND_MODE_CNF , /**< \brief Confirms the request and returns the supported bands and supported RAT modes */	 
	 
 /*Michal Bukai *BAND support - END*/	 
 /*Michal Bukai - IMEI support - START*/	 
 CI_DEV_PRIM_SET_SV_REQ , /**< \brief Requests to update the SV digits in IMEISV. \details The default value of the SV digits is the value set during production. */	 
 CI_DEV_PRIM_SET_SV_CNF , /**< \brief Confirms a request to set SV digits in IMEISV. \details */	 
 CI_DEV_PRIM_GET_SV_REQ , /**< \brief Requests to get the SV digits in IMEISV. \details */	 
 CI_DEV_PRIM_GET_SV_CNF = 60 , /**< \brief Confirms a request and returns the SV digits in IMEISV. \details The full IMEISV can be read using the primitive CI_DEV_PRIM_GET_SERIALNUM_ID_REQ to read IMEI and this primitive to get SV digits. */	 
 /*Michal Bukai - IMEI support - END*/	 
	 
 CI_DEV_PRIM_AP_POWER_NOTIFY_REQ ,	 
 CI_DEV_PRIM_AP_POWER_NOTIFY_CNF ,	 
	 
 CI_DEV_PRIM_SET_TD_MODE_TX_RX_REQ , /**< \brief Requests to set Tx or Rx on TD for radio testing. */	 
 CI_DEV_PRIM_SET_TD_MODE_TX_RX_CNF , /**< \brief Confirms the TD Tx / Rx mode request. */	 
 CI_DEV_PRIM_SET_TD_MODE_LOOPBACK_REQ , /**< \brief Requests to set loopback mode on TD for radio testing. */	 
 CI_DEV_PRIM_SET_TD_MODE_LOOPBACK_CNF , /**< \brief Confirms to set loopback mode on TD for radio testing. */	 
	 
 CI_DEV_PRIM_SET_GSM_MODE_TX_RX_REQ , /**< \brief Requests to set Tx / Rx on GSM for radio testing. */	 
 CI_DEV_PRIM_SET_GSM_MODE_TX_RX_CNF , /**< \brief Confirms the GSM Tx / Rx mode request. */	 
 CI_DEV_PRIM_SET_GSM_CONTROL_INTERFACE_REQ , /**< \brief Requests to set GSM for control interface. */	 
 CI_DEV_PRIM_SET_GSM_CONTROL_INTERFACE_CNF = 70 , /**< \brief Confirms to set option on GSM for control interface testing. */	 
 CI_DEV_PRIM_ENABLE_HSDPA_REQ ,	 
 CI_DEV_PRIM_ENABLE_HSDPA_CNF ,	 
 CI_DEV_PRIM_GET_HSDPA_STATUS_REQ ,	 
 CI_DEV_PRIM_GET_HSDPA_STATUS_CNF ,	 
	 
 CI_DEV_PRIM_READ_RF_TEMPERATURE_REQ , /**< \brief Requests to read temperature from RF chip. */	 
 CI_DEV_PRIM_READ_RF_TEMPERATURE_CNF , /**< \brief Confirms to read temperature from RF chip. */	 
	 
 /*Mason CMCC Smart Network Monitor support - START*/	 
 /* AT^DCTS */	 
 CI_DEV_PRIM_SET_NETWORK_MONITOR_OPTION_REQ ,	 
 CI_DEV_PRIM_SET_NETWORK_MONITOR_OPTION_CNF ,	 
 CI_DEV_PRIM_GET_NETWORK_MONITOR_OPTION_REQ ,	 
 CI_DEV_PRIM_GET_NETWORK_MONITOR_OPTION_CNF = 80 ,	 
	 
 /* AT^DEELS */	 
 CI_DEV_PRIM_SET_PROTOCOL_STATUS_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_PROTOCOL_STATUS_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_PROTOCOL_STATUS_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_PROTOCOL_STATUS_CONFIG_CNF ,	 
 CI_DEV_PRIM_PROTOCOL_STATUS_CHANGED_IND ,	 
	 
 /* AT^DEVEI */	 
 CI_DEV_PRIM_SET_EVENT_IND_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_EVENT_IND_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_EVENT_IND_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_EVENT_IND_CONFIG_CNF ,	 
 CI_DEV_PRIM_EVENT_REPORT_IND = 90 ,	 
	 
 /* AT^DNPR */	 
 CI_DEV_PRIM_SET_WIRELESS_PARAM_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_WIRELESS_PARAM_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_WIRELESS_PARAM_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_WIRELESS_PARAM_CONFIG_CNF ,	 
 CI_DEV_PRIM_WIRELESS_PARAM_IND ,	 
	 
 /* AT^DUSR */	 
 CI_DEV_PRIM_SET_SIGNALING_REPORT_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_SIGNALING_REPORT_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_SIGNALING_REPORT_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_SIGNALING_REPORT_CONFIG_CNF ,	 
 CI_DEV_PRIM_SIGNALING_REPORT_IND = 100 ,	 
 /*Mason CMCC Smart Network Monitor support -- END*/	 
	 
 /*Alan DIP Channel support -- START*/	 
 CI_DEV_PRIM_DIP_CHANNEL_CHANGE_IND ,	 
 /*Alan DIP Channel support -- END*/	 
	 
 /*Add by Alan for LteEngModeInfoInd 12192012 -- Start*/	 
 CI_DEV_PRIM_LTE_ENGMODE_INFO_IND ,	 
 /*Add by Alan for LteEngModeInfoInd 12192012 -- End*/	 
	 
 CI_DEV_PRIM_CURRENT_AMR_CODEC_IND ,	 
	 
 /*Add by Alan for Power BackOff 4082013 , begin*/	 
 CI_DEV_PRIM_SET_POWER_BACK_OFF_REQ , /**< \brief Requests to set feature calibration of Grip Sensor TX power. */	 
 CI_DEV_PRIM_SET_POWER_BACK_OFF_CNF , /**< \brief Confirms to set feature calibration of Grip Sensor TX power. */	 
 /*Add by Alan for Power BackOff 4082013 , end*/	 
	 
 CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_REQ , /**< \brief Requests the internal revision ID and build time \details */	 
 CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_CNF , /**< \brief Confirms a request and returns the internal revision ID and build time \details */	 
	 
 CI_DEV_PRIM_SET_COM_CONFIG_REQ , /**< \brief Set a com related configuration.	 
 * \details Sending this CI overrides the value configured through the com config NVM file on the com side. It does not update the com config NVM file. */	 
 CI_DEV_PRIM_SET_COM_CONFIG_CNF , /**< \brief Confirms the request to set a com related configuration \details */	 
 CI_DEV_PRIM_GET_COM_CONFIG_REQ = 110 , /**< \brief Request to get a com configuration token \details */	 
 CI_DEV_PRIM_GET_COM_CONFIG_CNF , /**< \brief Confirmation and get com config token \details */	 
	 
 /*Add by Alan for WCDMA Radio test 5292013 , begin*/	 
 CI_DEV_PRIM_SET_WCDMA_MODE_TX_RX_REQ , /**< \brief Requests to set Tx or Rx on WCDMA for radio testing. */	 
 CI_DEV_PRIM_SET_WCDMA_MODE_TX_RX_CNF , /**< \brief Confirms the WCDMA Tx / Rx mode request. */	 
	 
 /*Michal Bukai - Security Configuration - Samsung - START*/	 
 CI_DEV_PRIM_SET_SECURITY_PARAMS_REQ , /**< \brief Requests to enable / disable ciphering and integrity protection. \details The setting will affect	 
 * the ciphering and integrity UE capabilities reported to the NW .	 
 * In case ciphering or integrity protection is enabled , the reported capabilities will be derived from NVM setting.	 
 * In case ciphering or integrity protection is disabled , all algorithms will be reported as unsupported ,	 
 * This command will not affect NVM setting.*/	 
 CI_DEV_PRIM_SET_SECURITY_PARAMS_CNF , /**< \brief Confirms a request to enable / disable ciphering and integrity protection \details */	 
 CI_DEV_PRIM_GET_SECURITY_PARAMS_REQ , /**< \brief Requests to read ciphering and integrity protection status \details */	 
 CI_DEV_PRIM_GET_SECURITY_PARAMS_CNF , /**< \brief Confirms the request and returns the ciphering and integrity protection status \details */	 
 /*Michal Bukai - Security Configuration - Samsung - END*/	 
 CI_DEV_PRIM_RESET_REQUEST_IND , /**< \brief Indication to request the apps to perform com reset */	 
 CI_DEV_PRIM_SET_USER_TEST_REPORT_OPTION_REQ , /**< \brief Requests to set the option for reporting user testing information */	 
 CI_DEV_PRIM_SET_USER_TEST_REPORT_OPTION_CNF = 120 , /**< \brief Confirms a request for reporting user testing information */	 
 CI_DEV_PRIM_USER_TEST_VALUABLE_EVENT_REPORT_IND , /**< \brief Reports a user testing valuable event */	 
 CI_DEV_PRIM_SET_PARK_MODE_REQ , /**< \brief Request to set the modem to enter or exit park mode */	 
 CI_DEV_PRIM_SET_PARK_MODE_CNF , /**< \brief Confirm the request to set the park mode. */	 
 CI_DEV_PRIM_GET_PARK_MODE_REQ , /**< \brief Request to get current status of park mode. */	 
 CI_DEV_PRIM_GET_PARK_MODE_CNF , /**< \brief Confirmation for the request to get the current park mode setting */	 
	 
 CI_DEV_PRIM_LP_ECID_MEAS_REQ ,	 
 CI_DEV_PRIM_LP_ECID_MEAS_CNF ,	 
	 
 CI_DEV_PRIM_SET_LP_UE_AREA_INFO_IND_REQ ,	 
 CI_DEV_PRIM_SET_LP_UE_AREA_INFO_IND_CNF ,	 
 CI_DEV_PRIM_LP_UE_AREA_INFO_IND = 130 ,	 
 CI_DEV_PRIM_SET_IMS_MEDIA_REQ , /**< \brief Request to set IMS Media configuration parameters */	 
 CI_DEV_PRIM_SET_IMS_MEDIA_CNF , /**< \brief Confirmation to the setting of the IMS media */	 
 CI_DEV_PRIM_IMS_MEDIA_IND , /**< \brief Indication from the IMS media on the com side */	 
	 
 /* Lilei VZWRSRP&VZWRSRQ support -- Start */	 
 CI_DEV_PRIM_GET_LTE_MEAS_REQ , /**< \brief Request to get lte rsrp&rsrq measurement info. */	 
 CI_DEV_PRIM_GET_LTE_MEAS_CNF , /**< \brief Confirm the request to get lte rsrp&rsrq measurement info. */	 
 /* Lilei VZWRSRP&VZWRSRQ support -- End */	 
	 
 /* Lilei LTE&WIFI coexist support 20131022 -- Start */	 
 CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_REQ ,	 
 CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_CNF ,	 
 CI_DEV_PRIM_GET_LTE_COEX_INFO_REQ ,	 
 CI_DEV_PRIM_GET_LTE_COEX_INFO_CNF ,	 
 CI_DEV_PRIM_LTE_COEX_INFO_IND = 140 ,	 
 /* Lilei LTE&WIFI coexist support 20131022 -- End */	 
	 
 /*Added by Lilei for neighbor cell info report on 1082014 , begin*/	 
 // #if defined ( SS_IPC_SUPPORT )	 
 CI_DEV_PRIM_SET_ENGMODE_NCELL_REPORT_OPTION_REQ , /**< \brief Requests to enable / disable the report of neighbor cell information \details If it ' s enabled , \n	 
 * CCI sends a periodic CI_DEV_PRIM_ENGMODE_NCELL_INFO_IND indication containing the current neighbor cell information. \n	 
 * The report interval is received as the parameter interval of the CiDevPrimSetEngmodeNcellRepOptReq structure , or set a defualt value. */	 
 CI_DEV_PRIM_SET_ENGMODE_NCELL_REPORT_OPTION_CNF , /**< \brief Confirms a request of enable / disable the report of neighbor cell information \details */	 
 CI_DEV_PRIM_GET_ENGMODE_NCELL_INFO_REQ , /**< \brief Requests current neighbor cell information \details */	 
 CI_DEV_PRIM_GET_ENGMODE_NCELL_INFO_CNF , /**< \brief Confirms a request and returns current neighbor cell information \details */	 
 CI_DEV_PRIM_ENGMODE_NCELL_INFO_IND , /**< \brief Indicates current neighbor cell information \details */	 
 // #endif	 
 /*Added by Lilei for neighbor cell info report on 1082014 , end*/	 
	 
 /*Added by Lilei for LTE Radio test on 1232014 , begin*/	 
 CI_DEV_PRIM_SET_LTE_MODE_TX_RX_REQ , /**< \brief Requests to set Tx or Rx on LTE for radio testing. */	 
 CI_DEV_PRIM_SET_LTE_MODE_TX_RX_CNF , /**< \brief Confirms the LTE Tx / Rx mode request. */	 
 /*Added by Lilei for LTE Radio test on 1232014 , end*/	 
	 
 /* Merged from UMTS7_Rel by Lilei 2182014 , begin */	 
 /*Add by Alan for L2RandomFillBitsEnabled on 2082014 , CQ54160 , begin*/	 
 CI_DEV_PRIM_SET_L2_RAND_FILL_ENABLED_REQ , /**< \brief Requests to set L2RandomFillBitsEnabled. */	 
 CI_DEV_PRIM_SET_L2_RAND_FILL_ENABLED_CNF , /**< \brief Confirms to set L2RandomFillBitsEnabled request. */	 
 CI_DEV_PRIM_GET_L2_RAND_FILL_ENABLED_REQ = 150 , /**< \brief Requests to get L2RandomFillBitsEnabled. */	 
 CI_DEV_PRIM_GET_L2_RAND_FILL_ENABLED_CNF , /**< \brief Confirms to get L2RandomFillBitsEnabled request. */	 
 /*Add by Alan for L2RandomFillBitsEnabled on 2082014 , CQ54160 , end*/	 
	 
 /*Add by Alan for reporting T323 on 2082014 , CQ54159 , begin*/	 
 CI_DEV_PRIM_T323_IND ,	 
 /*Add by Alan for reporting T323 on 2082014 , CQ54159 , end*/	 
 /* Merged from UMTS7_Rel by Lilei 2182014 , end */	 
	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 CI_DEV_PRIM_LTE_ENGMODE_SVCCELL_INFO_IND , /**< \brief Indicates LTE engineering mode serving cell information \details */	 
 CI_DEV_PRIM_LTE_ENGMODE_INTRAFREQ_INFO_IND , /**< \brief Indicates LTE engineering mode intra-frequency measurements information \details */	 
 CI_DEV_PRIM_LTE_ENGMODE_INTERFREQ_INFO_IND , /**< \brief Indicates LTE engineering mode inter-frequency measurements information \details */	 
 CI_DEV_PRIM_LTE_ENGMODE_INTERRAT_INFO_IND , /**< \brief Indicates LTE engineering mode inter-rat measurements information \details */	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
	 
 /*Add by Alan for MCC , MNC and CC on 3102014 , CQ54159 , begin*/	 
 CI_DEV_PRIM_SET_MCC_MNC_CC_REQ , /**< \brief Requests to set MCC_MNC_CC. */	 
 CI_DEV_PRIM_SET_MCC_MNC_CC_CNF , /**< \brief Confirms to set MCC_MNC_CC request. */	 
 CI_DEV_PRIM_GET_MCC_MNC_CC_REQ , /**< \brief Requests to get MCC_MNC_CC. */	 
 CI_DEV_PRIM_GET_MCC_MNC_CC_CNF = 160 , /**< \brief Confirms to get MCC_MNC_CC request. */	 
 /*Add by Alan for MCC , MNC and CC on 3102014 , CQ54159 , end*/	 
	 
 /*Added by Lilei for AT*L1DEBUG CQ60995 on 5162014 , begin*/	 
 CI_DEV_PRIM_SET_L1DEBUG_REQ , /**< \brief Requests to set L1 debug data. */	 
 CI_DEV_PRIM_SET_L1DEBUG_CNF , /**< \brief Confirms to set L1 debug data. */	 
 CI_DEV_PRIM_L1DEBUG_INFO_IND , /**< \brief Indicates L1 debug info. */	 
 /*Added by Lilei for AT*L1DEBUG CQ60995 on 5162014 , end*/	 
	 
 /*Added by Lilei for LTE positioning support , begin*/	 
 CI_DEV_PRIM_LP_OTDOA_MEAS_REQ ,	 
 CI_DEV_PRIM_LP_OTDOA_MEAS_CNF ,	 
 CI_DEV_PRIM_LP_OTDOA_MEAS_IND ,	 
 CI_DEV_PRIM_LP_OTDOA_MEAS_ABORT_REQ ,	 
 CI_DEV_PRIM_LP_OTDOA_MEAS_ABORT_CNF ,	 
 CI_DEV_PRIM_RETRIEVE_LOCATION_IND ,	 
 CI_DEV_PRIM_RETRIEVE_LOCATION_RSP = 170 ,	 
 /*Added by Lilei for LTE positioning support , end*/	 
	 
 /* Added by lalon CIQ Eng mode begin */	 
 CI_DEV_PRIM_COMMON_ENGMODE_INFO_IND ,	 
 CI_DEV_PRIM_SET_EXT_ENGMODE_REPORT_OPTION_REQ ,	 
 CI_DEV_PRIM_SET_EXT_ENGMODE_REPORT_OPTION_CNF ,	 
 CI_DEV_PRIM_GET_EXT_ENGMODE_REPORT_OPTION_REQ ,	 
 CI_DEV_PRIM_GET_EXT_ENGMODE_REPORT_OPTION_CNF ,	 
 /* Added by lalon CIQ Eng mode end */	 
 /*Added by arthurr for FRAT feature begin*/	 
 CI_DEV_PRIM_SET_IGNITION_STATE_REQ ,	 
 CI_DEV_PRIM_SET_IGNITION_STATE_CNF ,	 
 CI_DEV_PRIM_GET_IGNITION_STATE_REQ ,	 
 CI_DEV_PRIM_GET_IGNITION_STATE_CNF ,	 
 /*Added by arthurr for FRAT feature end*/	 
	 
	 
 /*Lilei , CQ00079390 , 20141217 , begin*/	 
 CI_DEV_PRIM_SET_IMLCONFIG_REQ = 180 ,	 
 CI_DEV_PRIM_SET_IMLCONFIG_CNF ,	 
 CI_DEV_PRIM_GET_IMLCONFIG_REQ ,	 
 CI_DEV_PRIM_GET_IMLCONFIG_CNF ,	 
 /*Lilei , CQ00079390 , 20141217 , end*/	 
	 
 /*Lilei , CQ00080629 , 20150104 , begin*/	 
 CI_DEV_PRIM_RB_TEST_MODE_IND , /**< \brief Indicates RB Test Loopback Mode status. */	 
 /*Lilei , CQ00080629 , 20150104 , end*/	 
	 
 /*Lilei , CQ00085118 , 20150202 , begin*/	 
 CI_DEV_PRIM_SET_LTE_BAND_ORDER_REQ , /**< \brief Requests to set LTE band scan order. */	 
 CI_DEV_PRIM_SET_LTE_BAND_ORDER_CNF , /**< \brief Confirms to set LTE band scan order. */	 
 CI_DEV_PRIM_GET_LTE_BAND_ORDER_REQ , /**< \brief Requests to get LTE band scan order. */	 
 CI_DEV_PRIM_GET_LTE_BAND_ORDER_CNF , /**< \brief Confirms to get LTE band scan order. */	 
 /*Lilei , CQ00085118 , 20150202 , end*/	 
	 
	 
 /*Lilei , CQ00087682 , 20150304 , begin*/	 
 CI_DEV_PRIM_SET_SALES_CODE_REQ ,	 
 CI_DEV_PRIM_SET_SALES_CODE_CNF = 190 ,	 
 CI_DEV_PRIM_GET_SALES_CODE_REQ ,	 
 CI_DEV_PRIM_GET_SALES_CODE_CNF ,	 
 CI_DEV_PRIM_SET_OPER_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_OPER_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_OPER_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_OPER_CONFIG_CNF ,	 
 /*Lilei , CQ00087682 , 20150304 , end*/	 
 CI_DEV_PRIM_MRD_CONFIG_REQ , // don ' t distinguish read / write / del operation , just transfer to platform	 
 CI_DEV_PRIM_MRD_CONFIG_CNF , // don ' t distinguish read / write / del operation , just transfer to platform	 
 CI_DEV_PRIM_GET_STATUS_REQ , // added by taow 20170524	 
 CI_DEV_PRIM_GET_STATUS_CNF = 200 ,	 
	 
 /*Lilei , CQ00108730 , 20171225 , begin*/	 
 CI_DEV_PRIM_FACTORY_RESET_REQ ,	 
 CI_DEV_PRIM_FACTORY_RESET_CNF ,	 
 /*Lilei , CQ00108730 , 20171225 , end*/	 
	 
 /*Lilei , CQ00112021 , 20180903 , begin*/	 
 CI_DEV_PRIM_GET_IMS_UL_STATISTIC_REQ ,	 
 CI_DEV_PRIM_GET_IMS_UL_STATISTIC_CNF ,	 
 /*Lilei , CQ00112021 , 20180903 , end*/	 
	 
 /*add by taow 20180525 CQ00110536 begin*/	 
 CI_DEV_PRIM_SET_MEDATA_RESERVER_REQ , /**< \brief Requests to set MEDATA COMM RESERVER . */	 
 CI_DEV_PRIM_SET_MEDATA_RESERVER_CNF , /**< \brief Requests to set MEDATA COMM RESERVER . */	 
 CI_DEV_PRIM_GET_MEDATA_RESERVER_REQ , /**< \brief Requests to get MEDATA COMM RESERVER . */	 
 CI_DEV_PRIM_GET_MEDATA_RESERVER_CNF , /**< \brief Requests to get MEDATA COMM RESERVER . */	 
 /*add by taow 20180525 CQ00110536 end*/	 
	 
 /*Lilei , CQ00115548 , 20190719 , begin*/	 
 CI_DEV_PRIM_SET_CELL_SELECT_CFG_REQ , /**< \brief Requests to set cell select config. */	 
 CI_DEV_PRIM_SET_CELL_SELECT_CFG_CNF = 210 , /**< \brief Requests to set cell selectr config. */	 
 CI_DEV_PRIM_GET_CELL_SELECT_CFG_REQ , /**< \brief Requests to get cell select config. */	 
 CI_DEV_PRIM_GET_CELL_SELECT_CFG_CNF , /**< \brief Requests to get cell select config. */	 
 /*Lilei , CQ00115548 , 20190719 , end*/	 
	 
 CI_DEV_PRIM_COMMON_REPORT_IND , /**< \brief Indicates common reports. */	 
 /*20190819 CQ00116678 add by taow begin*/	 
 CI_DEV_PRIM_SET_ROAMING_FORBIDEN_PLMN_REQ ,	 
 CI_DEV_PRIM_SET_ROAMING_FORBIDEN_PLMN_CNF ,	 
 CI_DEV_PRIM_GET_ROAMING_FORBIDEN_PLMN_REQ ,	 
 CI_DEV_PRIM_GET_ROAMING_FORBIDEN_PLMN_CNF ,	 
 CI_DEV_PRIM_SET_BLACK_CELL_REQ ,	 
 CI_DEV_PRIM_SET_BLACK_CELL_CNF ,	 
 CI_DEV_PRIM_GET_BLACK_CELL_REQ = 220 ,	 
 CI_DEV_PRIM_GET_BLACK_CELL_CNF ,	 
 /*20190819 CQ00116678 add by taow end*/	 
	 
 /*Lilei , CQ00113795 , 20190215 , begin*/	 
 CI_DEV_PRIM_SET_FEATURE_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_FEATURE_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_FEATURE_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_FEATURE_CONFIG_CNF ,	 
 CI_DEV_PRIM_SET_ROAM_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_ROAM_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_ROAM_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_ROAM_CONFIG_CNF ,	 
 /*Lilei , CQ00113795 , 20190215 , end*/	 
	 
 /*Lilei , CQ00119368 , 20200331 , begin*/	 
 CI_DEV_PRIM_CELLS_INFO_IND = 230 , /**< \brief Report cells info. */	 
 /*Lilei , CQ00119368 , 20200331 , end*/	 
	 
 /* ============== Added for REL13 ====================================================*/	 
 CI_DEV_PRIM_CONFIG_HW_PSM_PROFILE_REQ , /**< \brief Requests to set hardware PSM configuration . */	 
 CI_DEV_PRIM_CONFIG_HW_PSM_PROFILE_CNF , /**< \brief Confirms to set hardware PSM configuration . */	 
 CI_DEV_PRIM_GET_HW_PSM_PROFILE_REQ , /**< \brief Requests to get hardware PSM configuration . */	 
 CI_DEV_PRIM_GET_HW_PSM_PROFILE_CNF , /**< \brief Confirms to get hardware PSM configuration . */	 
	 
 /*Lilei , CQ00126499 , 20201207 , begin*/	 
 CI_DEV_PRIM_SET_DRX_DYNAMIC_ADJUST_REQ , /**< \brief Requests to set DRX dynamic adjust params. */	 
 CI_DEV_PRIM_SET_DRX_DYNAMIC_ADJUST_CNF , /**< \brief Confirms to set DRX dynamic adjust params. */	 
 /*Lilei , CQ00126499 , 20201207 , end*/	 
	 
 /*Lilei , CQ00127745 , 20210119 , begin*/	 
 CI_DEV_PRIM_SET_ANTENNA_TUNER_PARAM_REQ , /**< \brief Requests to set antenna tuner param. */	 
 CI_DEV_PRIM_SET_ANTENNA_TUNER_PARAM_CNF , /**< \brief Confirms to set antenna tuner param. */	 
 /*Lilei , CQ00127745 , 20210119 , end*/	 
	 
 /*Lilei , CQ00131521 , 20210706 , begin*/	 
 CI_DEV_PRIM_PAGING_FAILURE_IND , /**< \brief Report paging failure ind. */	 
 /*Lilei , CQ00131521 , 20210706 , end*/	 
 /* add by taow 20211214 CQ00134561 begin*/	 
 CI_DEV_PRIM_SET_COMMON_FEATURE_REQ = 240 ,	 
 CI_DEV_PRIM_SET_COMMON_FEATURE_CNF ,	 
	 
 CI_DEV_PRIM_GET_COMMON_FEATURE_REQ ,	 
 CI_DEV_PRIM_GET_COMMON_FEATURE_CNF ,	 
 /* add by taow 20211214 CQ00134561 end*/	 
 /*add by lilei 20220119 CQ00135497 begin */	 
 CI_DEV_PRIM_SET_NST_TX_RX_REQ , /**< \brief Requests to set NST Tx or Rx for radio testing. */	 
 CI_DEV_PRIM_SET_NST_TX_RX_CNF , /**< \brief Confirms the NST Tx / Rx mode request. */	 
 /*add by lilei 20220119 CQ00135497 end */	 
	 
 CI_DEV_PRIM_SET_SIM_SLOT_REQ ,	 
 CI_DEV_PRIM_SET_SIM_SLOT_CNF ,	 
 CI_DEV_PRIM_GET_SIM_SLOT_REQ ,	 
 CI_DEV_PRIM_GET_SIM_SLOT_CNF ,	 
	 
 /* ADD NEW COMMON PRIMITIVES HERE , BEFORE ' CI_DEV_PRIM_LAST_COMMON_PRIM ' */	 
 /* END OF COMMON PRIMITIVES LIST */	 
 CI_DEV_PRIM_LAST_COMMON_PRIM	 
	 
 /* The customer specific extension primitives must be added starting from	 
 * CI_DEV_PRIM_firstCustPrim = CI_DEV_PRIM_LAST_COMMON_PRIM as the first identifier.	 
 * The actual primitive names and IDs are defined in the associated	 
 * ' ci_dev_cust_xxx.h ' file.	 
 */	 
	 
 /* DO NOT ADD ANY MORE PRIMITIVES HERE */	 
	 
 } _CiDevPrim;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_AMR_CODEC_TYPE_TAG {	 
 CI_DEV_CODEC_WB_AMR = 0 ,	 
 CI_DEV_CODEC_NB_AMR = 1 ,	 
 CI_DEV_CODEC_OTHERS = 2 ,	 
	 
 CI_DEV_NUM_OF_CODEC_TYPES	 
 } _CiDevAmrCodecType;

typedef UINT8 CiDevAmrCodecType ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_CURRENT_AMR_CODEC_IND " > */ 
 typedef struct CiDevPrimCurrentAmrCodecInd_struct 
 {	 
 CiDevAmrCodecType codecType ;	 
 UINT32 speechCodecRate ; // added by taow 20141106	 
 } CiDevPrimCurrentAmrCodecInd;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_CELL_PRIORITY_TYPE_TAG {	 
 CI_DEV_CELL_PRIORITY_NORMAL =0 , /**< Normal cell priority */	 
 CI_DEV_CELL_PRIORITY_BARRED , /**< Barred cell priority */	 
 CI_DEV_CELL_PRIORITY_LOW , /**< Low cell priority */	 
 CI_DEV_NUM_CELL_PRIORITY	 
 } _CiDevCellPrioriytType;

typedef UINT8 CiDevCellPrioriytType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevHoppingGroup_struct 
 {	 
 UINT8 length ; /**< Length of the arfcn list. Range is 0 -64.0 - means list is not available */	 
 UINT16 Arfcns [ 64 ] ; /**< Absolute radio frequency channel number */	 
 } CiDevHoppingGroup;

//ICAT EXPORTED ENUM 
 typedef enum CIDEVSTATUS_TAG {	 
 CI_DEV_STATUS_READY = 0 , /**< Device is ready to handle requests */	 
 CI_DEV_STATUS_UNAVAILABLE , /**< Device cannot handle requests */	 
 CI_DEV_STATUS_UNKNOWN , /**< Device status unknown */	 
 CI_DEV_STATUS_RINGING , /**< Device is ringing */	 
 CI_DEV_STATUS_CALLINPROG , /**< Device has a call in progress */	 
 CI_DEV_STATUS_ASLEEP , /**< Device is in a low functionality state */	 
 CI_DEV_STATUS_CALLACTIVE , /**< Device has a call in active */	 
	 
 CI_DEV_NUM_STATUSES	 
 } _CiDevStatus;

typedef UINT8 CiDevStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CIRCDEV_TAG {	 
 CIRC_DEV_SUCCESS = 0 , /**< Request completed successfully */	 
 CIRC_DEV_FAILURE , /**< Phone failure */	 
 CIRC_DEV_NO_CONNECTION , /**< No connection to phone */	 
 CIRC_DEV_UNKNOWN , /**< Unknown error */	 
 CIRC_DEV_INVALID_PARAMETER , /**< Generic error - the requested service primitive has invalid parameters */	 
 CIRC_DEV_INVALID_REQ , /**< Generic error - the requested service primitive can not be handled at current state */	 
 CIRC_DEV_SIM_NOT_READY , /**< Generic error - the requested service primitive fails because SIM is not ready */	 
 CIRC_DEV_ACCESS_DENIED , /**< Generic error - the requested service primitive fails because access is denied */	 
	 
	 
	 
	 
 CIRC_DEV_BUSY_WITH_OTHER_PROCESS , /**< Generic error - the requested service primitive fails because other process is ongoing */	 
	 
 CIRC_DEV_NUM_RESCODES	 
 } _CiDevRc;

typedef UINT16 CiDevRc ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVFUNC_TAG {	 
 CI_DEV_FUNC_MIN = 0 , /**< Minimum functionality ( lowest power level ) */	 
 CI_DEV_FUNC_FULL , /**< Full functionality ( highest power level ) */	 
 CI_DEV_FUNC_DISABLE_TX_RF , /**< Disable phone transmit RF circuits only */	 
 CI_DEV_FUNC_DISABLE_RX_RF , /**< Disable phone receive RF circuits only */	 
 CI_DEV_FUNC_DISABLE_BOTH_RF , /**< Disable both phone transmit and receive RF circuits */	 
 CI_DEV_FUNC_UPDATE_NVM_MIN , /**< Update NVM file with minimum functionality mode */	 
 CI_DEV_FUNC_UPDATE_NVM_FULL , /**< Update NVM file with full functionality mode */	 
 CI_DEV_FUNC_MIN_NO_IMSI_DETACH , /**< minimum functionality but without IMSI detach */	 
 CI_DEV_FUNC_DISABLE_SIM , /**< disable SIM */	 
 CI_DEV_FUNC_UPDATE_NVM_DISABLE_BOTH_RF = 9 , /**< Update NVM file with both transmit and receive RF circuits disable mode */	 
 CI_DEV_FUNC_FULL_SECONDARY_RX_OFF = 10 , /**< full functionality for primary RF , secondary RX is OFF */	 
	 
 /*Lilei , CQ00085158 , 20150128 , begin*/	 
 CI_DEV_FUNC_INIT_RF_3G , /**< Init 3 G RF setting. Only used for 3 G RF test */	 
 CI_DEV_FUNC_PRI_ONLY_RF_3G , /**< Enable only primary RF ( Pri TX + Pri RX ) . Only used for 3 G RF test */	 
 CI_DEV_FUNC_SEC_ONLY_RF_3G , /**< Enable only secondary RF ( Pri TX + Sec RX ) . Only used for 3 G RF test */	 
 CI_DEV_FUNC_PRI_SEC_RF_3G , /**< Enable both primary and secondary RF ( Pri TX + Pri RX + Sec RX ) . Only used for 3 G RF test */	 
 /*Lilei , CQ00085158 , 20150128 , end*/	 
	 
 CI_DEV_NUM_FUNCS	 
 } _CiDevFunc;

typedef UINT8 CiDevFunc ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVCOMMFEATURECONFIG_TAG {	 
 CI_DEV_CSD = 1 , /**< CSD is supported */	 
 CI_DEV_FAX , /**< FAX is supported */	 
 CI_DEV_PRODUCTION , /**< Production Mode is in use*/	 
 CI_DEV_CONVENTIONAL_GPS , /**< Conventional GPS is supported */	 
 CI_DEV_MS_BASED_GPS , /**< Ms-Based A-GPS is supported */	 
 CI_DEV_MS_ASSISTED_GPS , /**< Ms-Assisted A-GPS is supported */	 
	 
 CI_DEV_NUM_COMM_FEATURE_CONFIG	 
 } _CommFeatureConfig;

//ICAT EXPORTED ENUM 
 typedef enum CIDEVBAND_TAG {	 
 CI_DEV_BAND_GSM_900 = 0 , /**< GSM_900 band */	 
 CI_DEV_BAND_GSM_1800 , /**< GSM_1800 band */	 
 CI_DEV_BAND_GSM_1900 , /**< GSM_1900 band */	 
 CI_DEV_BAND_GSM_400 , /**< GSM_400 band */	 
	 
 CI_DEV_NUM_BANDS	 
 } _CiDevBand;

typedef UINT8 CiDevBand ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVPWCLS_TAG {	 
 CI_DEV_PWCLS_DEFAULT = 0 , /**< Default power class */	 
 CI_DEV_PWCLS_1 , /**< Power class 1 */	 
 CI_DEV_PWCLS_2 , /**< Power class 2 */	 
 CI_DEV_PWCLS_3 , /**< Power class 3 */	 
 CI_DEV_PWCLS_4 , /**< Power class 4 */	 
 CI_DEV_PWCLS_5 , /**< Power class 5 */	 
	 
 CI_DEV_NUM_PWCLSES	 
 } _CiDevPwCls;

typedef UINT8 CiDevPwCls ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_REPORTOPTION_TAG 
 {	 
 CI_DEV_EM_OPTION_NONE = 0 , /**< Engineering mode report delivery: Turn off */	 
 CI_DEV_EM_OPTION_REQUEST , /**< Engineering mode report delivery: On request */	 
 CI_DEV_EM_OPTION_PERIODIC , /**< Engineering mode report delivery: Periodic */	 
 /*Lilei , CQ00091516 , 20150423 , begin*/	 
 CI_DEV_EM_OPTION_INTERNAL_CALL_END , /**< Engineering mode opened for internal purpose: call end statistic */	 
 /*Lilei , CQ00091516 , 20150423 , end*/	 
 CI_DEV_NUM_EM_REPORT_OPTIONS	 
 } _CiDevEngModeReportOption;

typedef UINT8 CiDevEngModeReportOption ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_STATE_TAG 
 {	 
 CI_DEV_EM_GSM_IDLE_STATE = 0 , /**< Mode is GSM in idle */	 
 CI_DEV_EM_GSM_DEDICATED_STATE , /**< Mode is GSM in dedicated */	 
 CI_DEV_EM_GPRS_EGPRS_PTM_STATE , /**< Mode is GSM and at least one PDP context is activated*/	 
 CI_DEV_EM_INVALID_STATE ,	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_EM_STATES	 
 } _CiDevEngModeState;

typedef UINT8 CiDevEngModeState ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_NETWORK_TAG 
 {	 
 CI_DEV_EM_NETWORK_GSM = 0 , /**< GSM network */	 
 CI_DEV_EM_NETWORK_UMTS , /**< UMTS network */	 
 CI_DEV_EM_NETWORK_LTE , /**< LTE Network */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_EM_NETWORKS	 
 } _CiDevEngModeNetwork;

typedef UINT8 CiDevEngModeNetwork ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_UERRC_STATE_TAG 
 {	 
 CI_DEV_EM_UERRC_DEACTIVATED = 0 , /**< ( UE ) RRC state DEACTIVATED RRC state */	 
 CI_DEV_EM_UERRC_SUSPENDED , /**< ( UE ) RRC state SUSPENDED RRC state */	 
 CI_DEV_EM_UERRC_IDLE , /**< ( UE ) RRC state IDLE RRC state */	 
 CI_DEV_EM_UERRC_CONN_URA_PCH , /**< ( UE ) RRC state CONN_URA_PCH RRC state */	 
 CI_DEV_EM_UERRC_CONN_CELL_PCH , /**< ( UE ) RRC state CONN_CELL_PCH RRC state */	 
 CI_DEV_EM_UERRC_CONN_CELL_FACH , /**< ( UE ) RRC state DEACTIVATED RRC state */	 
 CI_DEV_EM_UERRC_CONN_CELL_DCH , /**< ( UE ) RRC state CONN_CELL_FACH RRC state */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_EM_UERRC_STATES	 
 } _CiDevEngModeUeRrcState;

typedef UINT8 CiDevEngModeUeRrcState ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_NETWORKMONITOR_MODE_TAG 
 {	 
 CI_DEV_NM_IDLE_MODE = 0 , /**< Current GSM mode - idle */	 
 CI_DEV_NM_DEDICATED_MODE , /**< Current GSM mode - dedicated */	 
 CI_DEV_NM_GPRS_MODE , /**< Current GSM mode - during GPRS */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_NM_MODES	 
 } _CiDevNetworkMonitorMode;

typedef UINT8 CiDevNetworkMonitorMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_BEPCVMEAN_STATUS_TAG {	 
 CI_DEV_BEP_NONE =0 ,	 
 CI_DEV_BEP_GMSK ,	 
 CI_DEV_BEP_EIGHT_PSK ,	 
 CI_DEV_BEP_GMSK_AND_EIGHT_PSK ,	 
 CI_DEV_NUM_BEP_STATUS	 
 } _CiDevBepCvMeanStatus;

typedef UINT32 CiDevBepCvMeanStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_CHANNEL_TYPE_TAG 
 {	 
 CI_DEV_TCH_F_PLUS_ACCH = 1 ,	 
 CI_DEV_TCH_H_PLUS_ACCH = 2 ,	 
 CI_DEV_SDCCH_4 = 4 ,	 
 CI_DEV_SDCCH_8 = 8 ,	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_CHANNEL_TYPE	 
 } _CiDevChannelType;

typedef UINT8 CiDevChannelType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_MODULATION_SCHEME_TAG 
 {	 
 CI_DEV_MS_GMSK = 0 , /**< GMSK */	 
 CI_DEV_MS_8PSK = 1 , /**< 8 PSK */	 
 CI_DEV_MS_INVALID = 0xff , /**< Invalid value */	 
 CI_DEV_NUM_MS /**< Must be the last entry */	 
 } _CiDevModulationScheme;

typedef UINT8 CiDevModulationScheme ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_CODE_SCHEME_TAG 
 {	 
 CI_DEV_CS_CS_1 = 0 ,	 
 CI_DEV_CS_CS_2 ,	 
 CI_DEV_CS_CS_3 ,	 
 CI_DEV_CS_CS_4 ,	 
 CI_DEV_CS_CS_RACH_8 ,	 
 CI_DEV_CS_CS_RACH_11 ,	 
 CI_DEV_CS_MCS_1 ,	 
 CI_DEV_CS_MCS_2 ,	 
 CI_DEV_CS_MCS_3 ,	 
 CI_DEV_CS_MCS_4 ,	 
 CI_DEV_CS_MCS_5 ,	 
 CI_DEV_CS_MCS_6 ,	 
 CI_DEV_CS_MCS_7 ,	 
 CI_DEV_CS_MCS_8 ,	 
 CI_DEV_CS_MCS_9 ,	 
 CI_DEV_CS_MCS_5_7 ,	 
 CI_DEV_CS_MCS_6_9 ,	 
 CI_DEV_CS_INVALID = 0xff ,	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_CS	 
 } _CiDevCodeScheme;

typedef UINT8 CiDevCodeScheme ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_PACKET_IDLE_TYPE_TAG 
 {	 
 CI_DEV_PACKET_IDLE_NONE = 0 , /**< Not attached to packet domain */	 
 CI_DEV_PACKET_IDLE_GPRS , /**< Packet domain supports GPRS */	 
 CI_DEV_PACKET_IDLE_EDGE , /**< Packet domain supports GPRS and EDGE */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_PACKET_IDLE	 
 } _CiDevPacketIdleType;

typedef UINT8 CiDevPacketIdleType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GPRS_SERVICE_TYPE_TAG 
 {	 
 CI_DEV_GPRS_SERVICE_TYPE_GRPS = 0 , /**< Packet domain support GPRS */	 
 CI_DEV_GPRS_SERVICE_TYPE_EDGE , /**< Packet domain support GPRS and EDGE */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_SERVICE_TYPE	 
 } _CiDevGprsServiceType;

typedef UINT8 CiDevGprsServiceType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevEgprsBepCvMeanInfo_struct 
 {	 
 CiDevBepCvMeanStatus status ;	 
	 
 UINT8 gmskMeanBep ;	 
 UINT8 gmskCvBep ;	 
 UINT8 eightPskMeanBep ;	 
 UINT8 eightPskCvBep ;	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 } CiDevEgprsBepCvMeanInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevNetworkMonitorNcellInfo_struct 
 {	 
 UINT8 bsic ; /* Base transceiver station identity code */	 
 UINT8 rxSigLevel ; /* Receive signal level - BCCH */	 
	 
 UINT16 arfcn ; /* Absolute radio frequency channel number */	 
 INT16 C1 ; /* Path loss criterion parameter #1 */	 
 INT16 C2 ; /* Path loss criterion parameter #2 */	 
 } CiDevNetworkMonitorNcellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevNetworkMonitorIdleInfo_struct 
 {	 
 UINT16 arfcn ; /* Absolute radio frequency channel number */	 
 INT16 C1 ; /* Path loss criterion parameter #1 */	 
 INT16 C2 ; /* Path loss criterion parameter #2 */	 
	 
 UINT8 bsic ; /* Base transceiver station identity code */	 
 UINT8 rxSigLevel ; /* Receive signal level - BCCH */	 
	 
 CiDevPacketIdleType isInPacketIdle ;	 
 UINT8 txPower ; /* Transmit power - TBD: phase 2 */	 
 UINT8 res1U8 [ 2 ] ; /* ( padding ) */	 
 } CiDevNetworkMonitorIdleInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevNetworkMonitorDedicatedInfo_struct 
 {	 
 UINT16 arfcn ; /* Absolute radio frequency channel number */	 
 INT16 C1 ; /* Path loss criterion parameter #1 */	 
	 
 UINT8 bsic ; /* Base transceiver station identity code */	 
 UINT8 rxSigLevelFull ; /* Receive signal level accessed over all TDMA frames */	 
 UINT8 rxSigLevelSub ; /* Receive signal level accessed over subset of TDMA frames*/	 
 UINT8 rxQualityFull ; /* Receive quality accessed over all TDMA frames */	 
 UINT8 rxQualitySub ; /* Receive quality accessed over subset of TDMA frames */	 
 UINT8 timingAdv ; /* Initial timing advance or timing advance in SACCH block */	 
	 
 CiBoolean isChannelHopping ; /* Channeling is hopping*/	 
 CiDevChannelType channelType ; /* Channel type*/	 
 UINT16 arfcnTch ; /* ARFCN for traffic channel*/	 
	 
 UINT8 timeSlot ; /* Server time slot */	 
 UINT8 txPower ; /* Transmit Power - TBD: phase 2 */	 
 } CiDevNetworkMonitorDedicatedInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevNetworkMonitorGprsInfo_struct 
 {	 
 UINT16 arfcn ; /* Absolute radio frequency channel number */	 
 INT16 C1 ; /* Path loss criterion parameter #1 */	 
 INT16 C2 ; /* Path loss criterion parameter #2 */	 
	 
 UINT8 bsic ; /* Base transceiver station identity code */	 
 UINT8 rxSigLevelFull ; /* Receive signal level accessed over all TDMA frames */	 
 UINT8 rxSigLevelSub ; /* Receive signal level accessed over subset of TDMA frames*/	 
 UINT8 rxQualityFull ; /* Receive quality accessed over all TDMA frames */	 
 UINT8 rxQualitySub ; /* Receive quality accessed over subset of TDMA frames */	 
 UINT8 cValue ; /* C Value */	 
 UINT8 txPower ; /* Transmit power - TBD: phase 2 */	 
 UINT8 ulTimeSlot ; /* Uplink time slot - TBD: phase 2 */	 
 UINT8 dlTimeSlot ; /* Downlink time slot - TBD: phase 2 */	 
	 
 CiDevGprsServiceType gprsServiceType ; /* GPRS service type - TBD: phase 2 */	 
 CiDevCodeScheme ulCs ; /* Uplink code scheme - TBD: phase 2 */	 
 CiDevCodeScheme dlCs ; /* Downlink code scheme - TBD: phase 2 */	 
 CiDevModulationScheme ulMod ; /* Uplink modulation - TBD: phase 2 */	 
 CiDevModulationScheme dlMod ; /* Downlink modulation - TBD: phase 2 */	 
 CiDevEgprsBepCvMeanInfo egprsBep ; /* TBD: phase 2 */	 
 } CiDevNetworkMonitorGprsInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevNetworkMonitorData_struct 
 {	 
 CiDevNetworkMonitorMode mode ; /* Current mode ( idle / dedicated / GPRS ) */	 
 UINT8 res1U8 [ 3 ] ; /* ( padding ) */	 
	 
 /* Serving Cell information */	 
 union	 
 {		 
 CiDevNetworkMonitorIdleInfo IdleData ;		 
 CiDevNetworkMonitorDedicatedInfo DedicatedData ;		 
 CiDevNetworkMonitorGprsInfo GprsData ;		 
 } svcCellInfo ;	 
	 
 /* Neighboring Cell information */	 
 UINT8 numNCells ; /* 0 ..CI_DEV_MAX_GSM_NEIGHBORING_CELLS */	 
 UINT8 res2U8 [ 3 ] ; /* ( padding ) */	 
 CiDevNetworkMonitorNcellInfo nbCellInfo [ 6 ] ;	 
 } CiDevNetworkMonitorData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimNetworkMonitorInfoInd_struct 
 {	 
 CiDevNetworkMonitorData info ;	 
 } CiDevPrimNetworkMonitorInfoInd;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_CHANNEL_TYPE_TAG 
 {	 
 CI_DEV_EM_TCH_F = 1 ,	 
 CI_DEV_EM_TCH_H = 2 ,	 
 CI_DEV_EM_SDCCH_4 = 4 ,	 
 CI_DEV_EM_SDCCH_8 = 8	 
 } _CiDevEngChannelType;

typedef UINT8 CiDevEngChannelType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_SERVICE_TYPE_TAG 
 {	 
 CI_DEV_CIRCUIT_SWITCHED_SERVICE = 0 ,	 
 CI_DEV_GPRS_SERVICE = 1 ,	 
 CI_DEV_COMBINED_SERVICE = 2 ,	 
 CI_DEV_NO_SERVICES_AVAILABLE = 3 ,	 
	 
 CI_DEV_NUM_OF_SERVICE_TYPES	 
 } _CiDevServiceType;

typedef UINT8 CiDevServiceType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmServingCellInfo_struct 
 {	 
 UINT8 rxSigLevel ; /**< Receive signal level [ range: 0 h-3Fh ] */	 
 UINT8 rxSigLevelFull ; /**< Receive signal level accessed over all TDMA frames [ range: 0 h-3Fh ] */	 
 UINT8 rxSigLevelSub ; /**< Receive signal level accessed over subset of TDMA frames [ range: 0 h-3Fh ] */	 
 UINT8 rxQualityFull ; /**< Receive quality accessed over all TDMA frames [ range: 0 -7 ] */	 
 UINT8 rxQualitySub ; /**< Receive quality accessed over subset of TDMA frames [ range: 0 -7 ] */	 
 UINT8 rac ; /**< Routing area code [ range: 0 -1 ( 1 bit ) ] */	 
 UINT8 bsic ; /**< Base transceiver station identity code [ range: 0 h-3Fh ( 6 bits ) ] */	 
 UINT8 nom ; /**< Network operation mode [ range: MODE_1= 0 / MODE_2= 1 / MODE_3= 2 ] */	 
 UINT8 nco ; /**< Network control order [ range: NC_0=0 / NC_1=1 / NC_2=2 / NC_RESET=3 ] */	 
 UINT8 bs_pa_mfrms ; /**< Number of multiframes between paging messages sent [ range: 0 -7 ] */	 
	 
 UINT16 mcc ; /**< Mobile country code [ range: 0 -999 ( 3 digits ) ] */	 
 UINT16 mnc ; /**< Mobile network code [ range: 0 -99 ( 2 digits ) ] */	 
 UINT16 lac ; /**< Location area code [ range: 0 h-FFFFh ( 2 octets ) ] */	 
 UINT16 ci ; /**< Cell identity [ range: 0 h-FFFFh ( 2 octets ) ] */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number [ range: 0 -1023 ] */	 
	 
 INT16 C1 ; /**< Path loss criterion parameter #1 */	 
	 
 INT16 C2 ; /**< Path loss criterion parameter #2 */	 
	 
 INT16 C31 ; /**< GPRS signal level threshold criterion parameter*/	 
	 
 INT16 C32 ; /**< GPRS cell ranking criterion parameter */	 
	 
	 
 UINT16 t3212 ; /**< Periodic LA update timer ( T3212 ) in minutes */	 
 UINT16 t3312 ; /**< Periodic RA update timer ( T3312 ) in minutes */	 
	 
 CiBoolean pbcchSupport ; /**< Support of PBCCH \sa CCI API Ref Manual */	 
 UINT8 TxPowerLevel ; /**< Tx power level [ range: 0 h-3Fh ] */	 
 UINT8 timingAdv ; /**< Timing advance [ range 0 -63 ] */	 
 CiBoolean hoppingChannel ; /**< Hopping channel */	 
 CiBoolean EGPRSSupport ; /**< EGPRS support capability */	 
 CiDevEngChannelType ChType ; /**< Values are TCH_F = 1 , TCH_H = 2 , SDCCH_4 = 4 , SDCCH_8 = 8 \sa CIDEV_ENGMODE_CHANNEL_TYPE */	 
 CiBoolean nccPermitted ; /**< The NCC permitted parameter sets the NCCs ( network color codes ) that the mobile station is permitted to report. \sa CCI API Ref Manual */	 
 UINT8 RadioLinkTimeout ; /**< Radio link timeout [ range: value >=0 ] */	 
 UINT16 hoCount ; /**< Handovers counter [ range: value>=0 ] */	 
 UINT16 hoSuccessCount ; /**< Success handovers counter [ range: value>=0 ] */	 
 UINT16 chanAssCount ; /**< Channel assignment counter [ range: value>=0 ] */	 
 UINT16 chanAssSuccessCount ; /**< Success channel assignment counter [ range: value>=0 ] */	 
	 
 UINT16 arfcnTch ; /**< ARFCN for traffic channel , only valid for dedicated state [ range: 0 -1023 ] */	 
 UINT8 timeSlot ; /**< Time slot , only valid for dedicated state*/	 
 CiDevPacketIdleType isInPacketIdle ; /**< Only valid for idle state \sa CiDevPacketIdleType */	 
 /*Michal Bukai - I-Mate Addition. Start:*/	 
 CiBoolean IsForbiddenLA ; /**< Indicates if cell belongs to forbidden location area. FALSE: Cell is not in forbidden LA or forbidden status is unknown ; TRUE: Cell is in forbidden LA. \sa CCI API Ref Manual */	 
 CiDevCellPrioriytType CellPriority ; /**< Cell priority for cell selection or reselection. Cell priority can be normal , low or barred. \sa CiDevCellPrioriytType */	 
 UINT8 HSN ; /**< Hopping sequence number. Value 0 means cyclic hopping is done*/	 
 CiDevHoppingGroup HoppingGroup ; /**< List of ARFCNs assigned for frequency hopping . \sa CiDevHoppingGroup */	 
 /*Michal Bukai - I-Mate Addition. End*/	 
 /*Added by Lilei for Network Info CQ56702 , begin*/	 
 UINT8 gsmBand ; /**< 0 :PGSM_900 ; 1 :DCS_GSM_1800 ; 2 :PCS_GSM_1900 ; 3 :EGSM_900 ; 4 :GSM_450 ; 5 :GSM_480 ; 6 :GSM_850 */	 
 UINT8 channelMode ; /**< Mode of a dedicated channel , used during dedicated channel setup to specify channel mode ( signaling-only , speech or data ) , mode version and data rate. */	 
 /*Added by Lilei for Network Info CQ56702 , end*/	 
 /*Lilei , CQ00092855 , 20150427 , begin*/	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 /*Lilei , CQ00092855 , 20150427 , end*/	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiDevAmrCodecType codecType ; /*wCdma*/	 
 UINT32 speechCodecRate ; /*wCdma*/	 
 INT16 RLA ; // rxlevAccessMin ;	 
 INT8 DRX ; // drxTimerMax	 
 INT8 maio ;	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00115868 , 20190815 , begin*/	 
 UINT32 succeededGsmIratReselectionCount ; // gsm irat 4 g to 2 g count	 
 UINT32 succeededGsmHandoverCount ; // gsm cs irat handover count	 
 /*Lilei , CQ00115868 , 20190815 , end*/	 
 } CiDevGsmServingCellInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_MM_REJECTCAUSE_CODE_TYPE {	 
 CI_DEV_EM_MM_REJ_CAUSE_IMSI_UNKNOWN_IN_HLR = 2 , /**< MS identification cause */	 
 CI_DEV_EM_MM_REJ_CAUSE_ILLEGAL_MS=3 , /**< MS identification cause */	 
 CI_DEV_EM_MM_REJ_CAUSE_IMSI_UNKNOWN_IN_VLR =4 , /**< MS identification cause */	 
 CI_DEV_EM_MM_REJ_CAUSE_IMEI_NOT_ACCEPTED =5 , /**< MS identification cause */	 
 CI_DEV_EM_MM_REJ_CAUSE_ILLEGAL_ME =6 , /**< MS identification cause */	 
 CI_DEV_EM_MM_REJ_CAUSE_PLMN_NOT_ALLOWED =11 , /**< Subscription options */	 
 CI_DEV_EM_MM_REJ_CAUSE_LOCATION_AREA_NOT_ALLOWED =12 , /**< Subscription options */	 
 CI_DEV_EM_MM_REJ_CAUSE_ROAMING_NOT_ALLOWED_IN_THIS_LOCATION_AREA =13 , /**< Subscription options */	 
 CI_DEV_EM_MM_REJ_CAUSE_NO_SUITABLE_CELLS_IN_LOCATION_AREA =15 , /**< Subscription options */	 
 CI_DEV_EM_MM_REJ_CAUSE_NETWORK_FAILURE=17 , /**< PLMN specific network failures and congestion / authentication failures */	 
 CI_DEV_EM_MM_REJ_CAUSE_MAC_FAILURE=20 , /**< PLMN specific network failures and congestion / authentication failures*/	 
 CI_DEV_EM_MM_REJ_CAUSE_SYNC_FAILURE=21 , /**< PLMN specific network failures and congestion / authentication failures*/	 
 CI_DEV_EM_MM_REJ_CAUSE_CONGESTION=22 , /**< PLMN specific network failures and congestion / authentication failures*/	 
 CI_DEV_EM_MM_REJ_CAUSE_GSM_AUTHENTICATION_UNACCEPTABLE=23 , /**< PLMN specific network failures and congestion / authentication failures */	 
 CI_DEV_EM_MM_REJ_CAUSE_SERVICE_OPTION_NOT_SUPPORTED=32 , /**< Nature of request */	 
 CI_DEV_EM_MM_REJ_CAUSE_REQUEST_SERVICE_OPTION_NOT_SUBSCRIBED=33 , /**< Nature of request */	 
 CI_DEV_EM_MM_REJ_CAUSE_SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER=34 , /**< Nature of request */	 
 CI_DEV_EM_MM_REJ_CAUSE_CALL_CANNOT_BE_IDENTIFIED=38 , /**< Nature of request */	 
 CI_DEV_EM_MM_REJ_CAUSE_SEMANTICALLY_INCORRECT_MESSAGE=95 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_INVALID_MANDATORY_INFORMATION=96 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_MESSAGE_TYPE_NONEXISTENT_OR_NOT_IMPLEMENTED=97 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE=98 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_INFORMATION_ELEMENT_NONEXISTENT_OR_NOT_IMPLEMENTED=99 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_CONDITIONAL_IE_ERROR=100 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_PROTOCOL_ERROR_UNSPECIFIED=111 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_CI_DEV_ALIGN_32_BIT=0XFFFFFFF /**< Used for alignment */	 
	 
 } _CiDevEngMMRejectCauseCodeType;

typedef UINT32 CiDevEngMMRejectCauseCodeType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_BAND_MODE_TYPE {	 
 CI_DEV_EM_BAND_MODE_PGSM_MODE=0 , /**< Standard or primary GSM 900 ( PGSM ) band supported */	 
 CI_DEV_EM_BAND_MODE_EGSM_MODE , /**< Extended GSM 900 band supported */	 
 CI_DEV_EM_BAND_MODE_DCS_MODE , /**< DCS 1800 band supported */	 
 CI_DEV_EM_BAND_MODE_PCS_MODE , /**< PCS 1900 band supported */	 
 CI_DEV_EM_BAND_MODE_GSM850_MODE , /**< GSM 850 band supported */	 
 CI_DEV_EM_BAND_MODE_PGSM_DCS_MODE , /**< PGSM band and DCS 1800 band supported */	 
 CI_DEV_EM_BAND_MODE_EGSM_DCS_MODE , /**< Extended GSM 900 band and DCS 1800 band supported */	 
 CI_DEV_EM_BAND_MODE_PGSM_PCS_MODE , /**< PGSM band and PCS 1900 band supported */	 
 CI_DEV_EM_BAND_MODE_EGSM_PCS_MODE , /**< Extended GSM 900 band and PCS 1900 band supported */	 
 CI_DEV_EM_BAND_MODE_GSM850_DCS_MODE , /**< GSM 850 band and DCS 1800 band supported */	 
 CI_DEV_EM_BAND_MODE_GSM850_PCS_MODE , /**< GSM 850 band and PCS 1900 band supported */	 
 CI_DEV_EM_BAND_MODE_EGSM_MODE_LOCK , /**< Lock the MS to Extended GSM 900 band mode. Autoband DISABLED. For use in testing only. */	 
 CI_DEV_EM_BAND_MODE_DCS_MODE_LOCK , /**< Lock the MS to DCS 1800 band mode. Autoband DISABLED. For use in testing only. */	 
 CI_DEV_EM_BAND_MODE_PCS_MODE_LOCK , /**< Lock the MS to Extended GSM 900 band or PCS 1900 band mode. Autoband DISABLED. For use in testing and 900 / 1900 countries only. */	 
 CI_DEV_EM_BAND_MODE_GSM850_MODE_LOCK , /**< Lock the MS to GSM 850 band mode. Autoband DISABLED. For use in testing only. */	 
 CI_DEV_EM_BAND_MODE_PGSM_PCS_MODE_LOCK , /**< Lock the MS to PGSM band or PCS 1900 band mode. Autoband DISABLED. For use in testing and 900 / 1900 countries only. */	 
 CI_DEV_EM_BAND_MODE_EGSM_PCS_MODE_LOCK , /**< Lock the MS to Extended GSM 900 band or PCS 1900 band mode. Autoband DISABLED. For use in testing and 900 / 1900 countries only. */	 
 CI_DEV_EM_BAND_MODE_EGSM_DCS_MODE_LOCK , /**< Lock the MS to Extended GSM 900 band or DCS 1800 band mode. Autoband DISABLED. For use in testing and 900 / 1800 countries only. */	 
 CI_DEV_EM_BAND_MODE_GSM850_DCS_MODE_LOCK , /**< Lock the MS to GSM 850 band or DCS 1800 band mode. Autoband DISABLED. For use in testing and 850 / 1800 countries only. */	 
 CI_DEV_EM_BAND_MODE_INVALID_BAND_MODE , /**< Invalid band */	 
 CI_DEV_EM_BAND_MODE_CI_DEV_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngBandModeType;

typedef UINT32 CiDevEngBandmodeType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmGMMInfo_struct 
 {	 
 UINT16 MccLastRegisteredNetwork ; /**< Mcc of last registered network */	 
 UINT16 MncLastRegisteredNetwork ; /**< Mnc of last registered network */	 
 UINT32 TMSI ; /**< TMSI */	 
 UINT32 PTMSI ; /**< PTMSI */	 
 CiBoolean IsSingleMmRejectCause ; /**< TRUE - only one MM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 CiDevEngMMRejectCauseCodeType MMRejectCause ; /**< The one that was reported during the last engineering information period. Reject cause ( 10.500000 .3.6 ) sent in CM Service Reject , Abort , MM-Status , and Location Updating Reject messages to MM from the network. \sa CiDevEngMMRejectCauseCodeType */	 
 CiDevEngBandmodeType currentBandMode ; /**< Band mode \sa CiDevEngBandModeType */	 
 UINT8 mmState ; /**< MM state refer to 3 GPP 24.008000 section 4.100000 .2 */ /* see enum MmState in Mm_comm.h. */	 
 UINT8 gmmState ; /**< GMM state refer to 3 GPP 24.008000 section 4.100000 .3 */ /* see enum GmmState in Gmm_comm.h */	 
 UINT8 gprsReadyState ; /**< 0 - IDLE_STATE / 1 - STANDBY_STATE / 2 - READY_STATE. */ /*For details , see enum GprsReadyState in grrmrtyp.h. */	 
 UINT16 readyTimerValueInSecs ; /**< MM ready timer value in seconds [ value >0 ] . Value of 0xffff indicates the timer is not running */	 
 /*Added by Lilei for Network Info CQ56702 , begin*/	 
 UINT8 serviceStatus ; /**< Service status */ /* see enum ServiceStatus in Mmr_sig.h. */	 
 UINT8 LAU_status ; /**<Current update status of the UE */ /* see enum LocationUpdateStatus in Mmr_sig.h. */	 
 UINT16 LAU_count ; /**<LAU attempt counter as held by UE ; number of consecutive LAU failures in current LAU procedure attempt */	 
 /*Added by Lilei for Network Info CQ56702 , end*/	 
 /*Lilei , CQ00082362 , 20150116 , begin*/	 
 UINT8 RAU_status ; /**<RAU status of the UE */ /* see enum GprsUpdateStatus in Mmr_sig.h. */	 
 UINT16 RAU_count ; /**<RAU attempt counter as held by UE ; number of consecutive RAU failures in current RAU procedure attempt*/	 
 /*Lilei , CQ00082362 , 20150116 , end*/	 
 } CiDevGsmGMMInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_AMR_CHANNEL_MODE_TYPE {	 
 CI_DEV_EM_AMR_CH_MODE_AMR_FR = 0 , /**< CHM_SPEECH_FULL_RATE_VER3 channel mode */	 
 CI_DEV_EM_AMR_CH_MODE_AMR_HR , /**< CHM_SPEECH_HALF_RATE_VER3 channel mode */	 
 CI_DEV_EM_AMR_CH_MODE_EFR , /**< CHM_SPEECH_FULL_RATE_VER2 / CHM_SPEECH_HALF_RATE_VER2 channel modes */	 
 CI_DEV_EM_AMR_CH_MODE_FR , /**< CHM_SPEECH_FULL_RATE channel mode */	 
 CI_DEV_EM_AMR_CH_MODE_HR , /**< CHM_SPEECH_HALF_RATE channel mode */	 
 CI_DEV_EM_AMR_CH_MODE_ALIGN_32_BIT=0XFFFFFFF /**< For alignment */	 
 } _CiDevEngAMRChannelModeType;

typedef UINT32 CiDevEngAMRChannelModeType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_AMR_CODE_TYPE {	 
 CI_DEV_EM_AMR_CODE_TYPE_4_75_KBPS = 1 , /**< AMR codec rate enumeration for 4.750000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_5_15_KBPS , /**< AMR codec rate enumeration for 5.150000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_5_9_KBPS , /**< AMR codec rate enumeration for 5.900000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_6_7_KBPS , /**< AMR codec rate enumeration for 6.700000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_7_4_KBPS , /**< AMR codec rate enumeration for 7.400000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_7_95_KPBS , /**< AMR codec rate enumeration for 7.950000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_10_2_KPBS , /**< AMR codec rate enumeration for 10.200000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_12_2_KBPS , /**< AMR codec rate enumeration for 12.200000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngAMRCodeType;

typedef UINT32 CiDevEngAMRCodeType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngAMRActiveCodeSetType_struct 
 {	 
 UINT8 AcsSize ; /**< Number of codes in AMR AS - up to 4 */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
	 
 CiDevEngAMRCodeType Acs [ 4 ] ; /**< AMR code type \sa CiDevEngAMRCodeType */	 
 } CiDevEngAMRActiveCodeSetType;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAMRInfo_struct 
 {	 
 CiDevEngAMRChannelModeType ULChannelMode ; /**< Current uplink channel mode { AMR FR , AMR HR , EFR , FR , HR } \sa CiDevEngAMRChannelModeType */	 
 CiDevEngAMRChannelModeType DLChannelMode ; /**< Current downlink channel mode { AMR FR , AMR HR , EFR , FR , HR } \sa CiDevEngAMRChannelModeType */	 
 CiDevEngAMRActiveCodeSetType ActiveCodeSet ; /**< Active code set ( ACS ) \sa CiDevEngAMRActiveCodeSetType_struct */	 
 CiBoolean DTXUl ; /**< DTX UL on / off \sa CCI API Ref Manual */	 
 CiBoolean DTXDl ; /**< If at least one DTX during DL has happened , then DTXDI =TRUE , otherwise = FALSE. \sa CCI API Ref Manual */	 
 INT16 DlCi ; /**< L1 calculates average of confidence measure for frequency offset for all the bursts of the multiframe. [ Ratio linear value 0 -500 ] . */	 
 UINT8 RxQualSub ; /**< Used when DTX is on , range is 0 -7 */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 } CiDevAMRInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_GPRS_ATTACH_TYPE {	 
 CI_DEV_EM_GPRS_ATTACH_TYPE_GPRS_ONLY_ATTACH=0 , /**< GPRS only */	 
 CI_DEV_EM_GPRS_ATTACH_TYPE_GPRS_ATTACH_WHILE_IMSI_ATTACHED , /**< GPRS attach while IMSI attached */	 
 CI_DEV_EM_GPRS_ATTACH_TYPE_COMBINED_IMSI_ATTACH , /**< Combined GPRS attach */	 
 CI_DEV_EM_GPRS_ATTACH_TYPE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngGPRSAttachType;

typedef UINT32 CiDevEngGPRSAttachType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_MACMODE_TYPE {	 
 CI_DEV_EM_MACMODE_TYPE_MAC_DYNAMIC_ALLOC =0 , /**< Dynamic allocation ( DA ) */	 
 CI_DEV_EM_MACMODE_TYPE_MAC_EXTENDED_DYNAMIC_ALLOC , /**< Extended dynamic allocation ( EDA ) */	 
 CI_DEV_EM_MACMODE_TYPE_MAC_FIXED_ALLOC_NOT_HALF_DUPLEX , /**< Fixed not half duplex allocation */	 
 CI_DEV_EM_MACMODE_TYPE_MAC_FIXED_ALLOC_HALF_DUPLEX , /**< Fixed half duplex allocation */	 
 CI_DEV_EM_MACMODE_TYPE_MAC_UNKNOWN_ALLOC_MODE , /**< Unknown allocation */	 
 CI_DEV_EM_MACMODE_TYPE_CI_DEV_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngMacModeType;

typedef UINT32 CiDevEngMacModeType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_NETWORK_CTRL_TYPE {	 
 CI_DEV_EM_NW_CTRL_NC_0 =0 ,	 
 CI_DEV_EM_NW_CTRL_NC_1 ,	 
 CI_DEV_EM_NW_CTRL_NC_2 ,	 
 CI_DEV_EM_NW_CTRL_NC_RESERVED ,	 
 CI_DEV_EM_NW_CTRL_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngNetworkControlType;

typedef UINT32 CiDevEngNetworkControlType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_NW_MODE_TYPE {	 
 CI_DEV_EM_NW_MODE_TYPE_NOM1 =0 , /**< NW provides simultaneous CS and PS */	 
 CI_DEV_EM_NW_MODE_TYPE_NOM2 , /**< UE remains attached to PS while receiving CS */	 
 CI_DEV_EM_NW_MODE_TYPE_NOM3 , /**< UE can be connected to CS or PS */	 
 CI_DEV_EM_NW_MODE_TYPE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngNetworkModeType;

typedef UINT32 CiDevEngNetworkModeType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_CODINGSCHEME_TYPE {	 
 CI_DEV_EM_CS_1 =0 , /**< CS1 */	 
 CI_DEV_EM_CS_2 , /**< CS2 */	 
 CI_DEV_EM_CS_3 , /**< CS3 */	 
 CI_DEV_EM_CS_4 , /**< CS4 */	 
 CI_DEV_EM_MCS_1 , /**< MCS1 */	 
 CI_DEV_EM_MCS_2 , /**< MCS2 */	 
 CI_DEV_EM_MCS_3 , /**< MCS3 */	 
 CI_DEV_EM_MCS_4 , /**< MCS4 */	 
 CI_DEV_EM_MCS_5 , /**< MCS5 */	 
 CI_DEV_EM_MCS_6 , /**< MCS6 */	 
 CI_DEV_EM_MCS_7 , /**< MCS7 */	 
 CI_DEV_EM_MCS_8 , /**< MCS8 */	 
 CI_DEV_EM_MCS_9 , /**< MCS9 */	 
 CI_DEV_EM_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngCodingSchemeType;

typedef UINT32 CiDevEngCodingSchemeType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_EGPR_SLQ_MEAS_MODE_TYPE {	 
 CI_DEV_EM_NO_LINK_QUAL_MEASUREMENTS =0 , /**< No report */	 
 CI_DEV_EM_LINK_QUAL_INT_MEAS_ONLY , /**< Report interference measurements */	 
 CI_DEV_EM_LINK_QUAL_BEP_MEAS_ONLY , /**< Report mean BEP measurements */	 
 CI_DEV_EM_LINK_QUAL_INT_AND_BEP_MEAS , /**< Report both interference and BEP measurements */	 
 CI_DEV_EM_EGPR_SLQ_MEAS_MODE_TYPE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngEGPRSLQMeasModeType;

typedef UINT32 CiDevEngEGPRSLQMeasModeType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_GMM_REJ_CAUSE_CODE_TYPE {	 
 CI_DEV_EM_GMM_REJ_CAUSE_GPRS_SERVICE_NOT_ALLOWED=7 , /**< GPRS services not allowed */	 
 CI_DEV_EM_GMM_REJ_CAUSE_GPRS_SERVICE_AND_NON_GPRS_SERVICE_NOT_ALLOWED=8 , /**< GPRS services and non-GPRS services not allowed */	 
 CI_DEV_EM_GMM_REJ_CAUSE_MS_IDENTITY_CANNOT_BE_DERIVED_BY_NW=9 , /**< MS identity cannot be derived by the network */	 
 CI_DEV_EM_GMM_REJ_CAUSE_IMPLICITLY_DETACHED=10 , /**< Implicitly detached */	 
 CI_DEV_EM_GMM_REJ_CAUSE_GPRS_SERVICES_NOT_ALLOWED_IN_PLMN=14 , /**< GPRS services not allowed in this PLMN */	 
 CI_DEV_EM_GMM_REJ_CAUSE_MSC_TEMPORARILY_NOT_REACHABLE=16 , /**< MSC temporarily not reachable */	 
 CI_DEV_EM_GMM_REJ_CAUSE_NO_PDP_CONTEXT_ACTIVATED=40 , /**< No PDP context activated */	 
 CI_DEV_EM_GMM_REJ_CAUSE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngGMMRejectCauseCodeType;

typedef UINT32 CiDevEngGMMRejectCauseCodeType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngIPAddressType_struct 
 {	 
 UINT8 len ; /**< Length of the address field */	 
 UINT8 address [ 16 ] ; /**< Address field */	 
 } CiDevEngIPAddressType;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_DELAY_CLASS_TYPE {	 
 CI_DEV_EM_GPRS_DELAY_CLASS_SUBSCRIBED =0 , /**< Subscribed delay class */	 
 CI_DEV_EM_GPRS_DELAY_CLASS_1 , /**< Delay class 1 */	 
 CI_DEV_EM_GPRS_DELAY_CLASS_PACKET_CELL_CHANGE_ORDER2 , /**< Delay class 2 */	 
 CI_DEV_EM_GPRS_DELAY_CLASS_3 , /**< Delay class 3 */	 
 CI_DEV_EM_GPRS_DELAY_CLASS_4 , /**< Delay class 4 ( best effort ) */	 
 CI_DEV_EM_GPRS_DELAY_CLASS_RESERVED = 7 , /**< Reserved */	 
 CI_DEV_EM_DELAY_CLASS_TYPE_ALIGN_32_BIT=0XFFFFFFF /**< Alignment */	 
 } _CiDevEngDelayClassType;

typedef UINT32 CiDevEngDelayClassType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_RELIABILITY_CLASS_TYPE {	 
 CI_DEV_EM_GPRS_RELIAB_CLASS_SUBSCRIBED =0 , /**< Subscribed reliability class */	 
 CI_DEV_EM_GPRS_RELIAB_CLASS_1 , /**< Unused. If received , it is interpreted as ' 10 ' . */	 
 CI_DEV_EM_GPRS_RELIAB_CLASS_2 , /**< Unacknowledged GTP ; acknowledged LLC and RLC , protected data */	 
 CI_DEV_EM_GPRS_RELIAB_CLASS_3 , /**< Unacknowledged GTP and LLC ; acknowledged RLC , protected data */	 
 CI_DEV_EM_GPRS_RELIAB_CLASS_4 , /**< Unacknowledged GTP , LLC , and RLC , protected data */	 
 CI_DEV_EM_GPRS_RELIAB_CLASS_5 , /**< Unacknowledged GTP , LLC , and RLC , unprotected data */	 
 CI_DEV_EM_RELIABILITY_CLASS_TYPE_ALIGN_32_BIT=0XFFFFFFF /**< Alignment */	 
 } _CiDevEngReliabilityClassType;

typedef UINT32 CiDevEngReliabilityClassType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_PEAK_THR_TYPE {	 
 CI_DEV_EM_GPRS_PEAK_THRPT_SUBSCRIBED =0 , /**< Subscribed peak throughput */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_1KOCT , /**< Up to 1 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_2KOCT , /**< Up to 2 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_4KOCT , /**< Up to 4 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_8KOCT , /**< Up to 8 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_16KOCT , /**< Up to 16 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_32KOCT , /**< Up to 32 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_64KOCT , /**< Up to 64 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_128KOCT , /**< Up to 128 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_256KOCT , /**< Up to 256 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_RESERVED = 0x0f , /**< Reserved */	 
 CI_DEV_EM_PEAK_THR_TYPE_ALIGN_32_BIT=0XFFFFFFF /**< Alignment */	 
 } _CiDevEngPeakThroughputType;

typedef UINT32 CiDevEngPeakThroughputType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_PRECEDENCE_CLASS_TYPE {	 
 CI_DEV_EM_GPRS_PRECED_CLASS_SUBSCRIBED =0 , /**< Subscribed precedence ( in MS to network direction ) */	 
 CI_DEV_EM_GPRS_PRECED_CLASS_1 , /**< High priority ( in MS to network direction ) */	 
 CI_DEV_EM_GPRS_PRECED_CLASS_2 , /**< Normal priority ( in MS to network direction ) */	 
 CI_DEV_EM_GPRS_PRECED_CLASS_3 , /**< Low priority ( in MS to network direction ) */	 
 CI_DEV_EM_GPRS_PRECED_CLASS_RESERVED = 7 , /**< Reserved */	 
 CI_DEV_EM_PRECEDENCE_CLASS_TYPE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngprecedenceClassType;

typedef UINT32 CiDevEngprecedenceClassType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_MEANTHROUGHPUT_TYPE {	 
 CI_DEV_EM_GPRS_MEAN_THRPT_SUBSCRIBED =0 , /**< Subscribed precedence ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_100_OPH , /**< 100 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_200_OPH , /**< 200 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_500_OPH , /**< 500 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_1K_OPH , /**< 1 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_2K_OPH , /**< 2 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_5K_OPH , /**< 5 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_10K_OPH , /**< 10 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_20K_OPH , /**< 20 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_50K_OPH , /**< 50 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_100K_OPH , /**< 100 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_200K_OPH , /**< 200 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_500K_OPH , /**< 500 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_1M_OPH , /**< 1 , 0 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_2M_OPH , /**< 2 , 0 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_5M_OPH , /**< 5 , 0 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_10M_OPH , /**< 10 , 0 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_20M_OPH , /**< 20 , 0 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_50M_OPH , /**< 50 , 0 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_RESERVED = 30 , /**< Reserved ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_BEST_EFFORT = 31 , /**< Best effort. The value indicates that throughput is made available to the MS on a per need and availability basis ( in MS to network direction and in network to MS direction ) . */	 
 CI_DEV_EM_MEANTHROUGHPUT_TYPE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevMeanThroughputType;

typedef UINT32 CiDevMeanThroughputType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngQualityOfServiceType_struct 
 {	 
 CiDevEngDelayClassType delayClass ; /**< GPRS delay class \sa CiDevEngDelayClassType */	 
 CiDevEngReliabilityClassType reliabilityClass ; /**< Reliability class \sa CiDevEngReliabilityClassType */	 
 CiDevEngPeakThroughputType peakThroughput ; /**< Peak throughput \sa CiDevEngPeakThroughputType */	 
 CiDevEngprecedenceClassType precedenceClass ; /**< Precedence class \sa CiDevEngprecedenceClassType */	 
 CiDevMeanThroughputType meanThroughput ; /**< Mean throughput \sa CiDevMeanThroughputType */	 
 } CiDevEngQualityOfServiceType;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngAPNType_struct 
 {	 
 INT8 length ;	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 UINT8 name [ 100 ] ; /**< IP address or an ASCII character string that identifies the GGSN */	 
 } CiDevEngAPNType;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngActivePDPContextinfoType_struct 
 {	 
 CiDevEngIPAddressType IPaddress ; /**< IP address \sa CiDevEngIPAddressType_struct */	 
 CiDevEngQualityOfServiceType QOS ; /**< Quality of service information \sa CiDevEngQualityOfServiceType_struct */	 
 CiDevEngAPNType APN ; /**< \sa CiDevEngAPNType_struct */	 
 } CiDevEngActivePDPContextinfoType;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimActivePDPContextEngModeInd_struct {	 
 UINT8 Index ; /**< PDP context index */	 
 CiDevEngActivePDPContextinfoType ActivePDPContextinfo ; /**< PDP context information \sa CiDevEngActivePDPContextinfoType_struct */	 
 } CiDevPrimActivePDPContextEngModeInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGPRSPTMInfo_struct 
 {	 
 CiBoolean GPRSAttached ; /**< TRUE - MS is GPRS attached ; FALSE - other \sa CCI API Ref Manual */	 
 INT8 EGPRSBEPPeriod ; /**< BEP measurement averaging coefficient */	 
 CiBoolean IsSingleGmmRejectCause ; /**< TRUE - only one GMM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 UINT8 NumActivePDPContext ; /**< 0 means no active PDP context [ range: 0 -7 ] */	 
	 
 CiDevEngGPRSAttachType GPRSAttachType ; /**< GPRS attach type \sa CiDevEngGPRSAttachType */	 
 CiDevEngMacModeType MacMode ; /**< Mac mode type \sa CiDevEngMacModeType */	 
 CiDevEngNetworkControlType NetworkControl ; /**< Not in use ( network control order ) \sa CiDevEngNetworkControlType */	 
 CiDevEngNetworkModeType NetworkMode ; /**< Network mode type \sa CiDevEngNetworkModeType */	 
 CiDevEngCodingSchemeType CodingSchemeUL ; /**< UL coding scheme \sa CiDevEngCodingSchemeType */	 
 CiDevEngCodingSchemeType CodingSchemeDL ; /**< DL coding scheme \sa CiDevEngCodingSchemeType*/	 
 CiDevEngEGPRSLQMeasModeType EGPRSLQMeasurementMode ; /**< Link quality measurement mode \sa CiDevEngEGPRSLQMeasModeType */	 
 CiDevEngGMMRejectCauseCodeType GMMRejectCause ; /**< Reported during the last engineering information period \sa CiDevEngGMMRejectCauseCodeType */	 
	 
 UINT8 cValue ; /**< C value */	 
 UINT8 txPower ; /**< Transmit power of every block - TBD: phase 2 */	 
 UINT8 ulTimeSlot ; /**< Uplink time slot allocation bitmap */	 
 UINT8 dlTimeSlot ; /**< Downlink time slot allocation bitmap */	 
	 
 CiDevGprsServiceType gprsServiceType ; /**< GPRS service type GPRS / EDGE \sa CiDevGprsServiceType */	 
 CiDevModulationScheme ulMod ; /**< Uplink modulation - TBD: phase 2 \sa CiDevModulationScheme */	 
 CiDevModulationScheme dlMod ; /**< Downlink modulation - TBD: phase 2 \sa CiDevModulationScheme */	 
 /*Michal Bukai - I-Mate Addition. Start:*/	 
 UINT8 USFGranularity ; /**< USF granularity defines the number of RLC / MAC blocks to transmit if USF is present. 0 - the mobile station shall transmit one RLC / MAC block , 1 - the mobile station shall transmit four consecutive RLC / MAC blocks */	 
 UINT32 ULThroughput ; /**< UL throughput in octets per second */	 
 UINT32 DLThroughput ; /**< DL throughput in octets per second */	 
 /*Michal Bukai - I-Mate Addition. End*/	 
 CiDevEgprsBepCvMeanInfo egprsBep ; /**< BEP period - TBD: phase 2 \sa CiDevEgprsBepCvMeanInfo_struct */	 
 } CiDevGPRSPTMInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeNcellInfoGsm_struct {	 
 UINT32 ci ; /**< Cell identity */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT8 bsic ; /**< Base transceiver station identity code */	 
 UINT8 rxSigLevel ; /**< Receive signal level */	 
 } CiDevEngModeNcellInfoGsm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeNcellInfoListGsm_struct {	 
 UINT8 numNcellGsm ; /**< Number of GSM neighbor cells */	 
 CiDevEngModeNcellInfoGsm nCellInfoGsm [ 32 ] ; /**< GSM neighbor cells info , maximum 32 cells */	 
 } CiDevEngModeNcellInfoListGsm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeNcellInfoUmts_struct {	 
 UINT32 ci ; /**< Cell Identity */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power */	 
 } CiDevEngModeNcellInfoUmts;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeNcellInfoListUmts_struct {	 
 UINT8 numNcellUmts ; /**< Number of UMTS neighbor cells */	 
 CiDevEngModeNcellInfoUmts nCellInfoUmts [ 32 *2 ] ; /**< UMTS neighbor cells info , maximum 32 ( intraFreq ) +32 ( interFreq ) cells */	 
 } CiDevEngModeNcellInfoListUmts;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeNcellInfoLte_struct {	 
 UINT16 physCellId ; /**< Physical cell identity */	 
 UINT32 earfcn ; /**< Eutra absolute radio frequency channel number */	 
 UINT8 rsrp ; /**< Reference signal receive power */	 
 UINT8 rsrq ; /**< Reference signal receive quality */	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 INT16 s_rxlev ;	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevEngModeNcellInfoLte;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeNcellInfoListLte_struct {	 
 UINT8 numNcellLte ; /**< Number of LTE neighbor cells */	 
 CiDevEngModeNcellInfoLte nCellInfoLte [ 32 *2 ] ; /**< LTE neighbor cells info , maximum 32 ( intraFreq ) +32 ( interFreq ) cells */	 
 } CiDevEngModeNcellInfoListLte;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmNeighboringCellInfo_struct 
 {	 
 UINT8 rxSigLevel ; /**< Receive signal level */	 
 UINT8 bsic ; /**< Base transceiver station identity code */	 
 UINT8 rac ; /**< Routing area code */	 
 UINT8 res1U8 ; /**< ( padding ) */	 
	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 ci ; /**< Cell identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
	 
 INT16 C1 ; /**< Path loss criterion parameter #1 */	 
 INT16 C2 ; /**< Path loss criterion parameter #2 */	 
 INT16 C31 ; /**< GPRS signal level threshold criterion parameter */	 
 INT16 C32 ; /**< GPRS cell ranking criterion parameter */	 
 /*Michal Bukai - I-Mate Addition. Start:*/	 
 CiBoolean IsForbiddenLA ; /**< Indicates if cell belongs to forbidden location area. FALSE: Cell is not in forbidden LA or forbidden status is unknown ; TRUE: Cell is in forbidden LA. \sa CCI API Ref Manual */	 
 CiDevCellPrioriytType CellPriority ; /**< Cell priority for cell selection or reselection. Cell priority can be normal , low or barred. \sa CiDevCellPrioriytType */	 
 /*Michal Bukai - I-Mate Addition. End*/	 
 /*Lilei , CQ00134586 , 20211221 , begin*/	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 /*Lilei , CQ00134586 , 20211221 , begin*/	 
 } CiDevGsmNeighboringCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmUMTSNeighboringCellInfo_struct 
 {	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power */	 
 INT16 cpichEcN0 ; /**< CPICH Ec / N0 , only valid for FDD */	 
 } CiDevGsmUMTSNeighboringCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeGsmData_struct 
 {	 
 CiDevGsmServingCellInfo svcCellInfo ; /**< Serving cell information \sa CiDevGsmServingCellInfo_struct */	 
	 
 CiDevGsmGMMInfo GMMInfo ; /**< Mobility management information \sa CiDevGsmGMMInfo_struct */	 
 CiDevAMRInfo AMRInfo ; /**< AMR information \sa CiDevAMRInfo_struct */	 
 CiDevGPRSPTMInfo GPRSPTMInfo ; /**< Packet data information \sa CiDevGPRSPTMInfo_struct */	 
	 
 UINT8 numNCells ; /**< Number of neighboring cells [ 0 ..CI_DEV_MAX_GSM_NEIGHBORING_CELLS ] */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevGsmNeighboringCellInfo nbCellInfo [ 6 ] ; /**< Neighboring cell information \sa CiDevGsmNeighboringCellInfo_struct */	 
	 
 UINT8 numInterRATNCells ; /**< Number of InterRAT cells [ 0 ..CI_DEV_MAX_GSM_NEIGHBORING_CELLS ] */	 
 UINT8 res2U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevGsmUMTSNeighboringCellInfo InterRATCellInfo [ 6 ] ; /**< InterRAT cell information \sa CiDevCiDevGsmUMTSNeighboringCellInfo */	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiDevEngModeNcellInfoListLte nCellInfoListLte ; /**< LTE neighbor cells info list */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevEngModeGsmData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsServingCellMeasurements_struct 
 {	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power ; in UMTS FDD / TDD messages RSCP is	 
 transmitted as an integer value in the range of -120 dBm to -25 dBm.	 
 The value is coded into integers from -5 to 99 according to 3 GPP ' s 25.133000 . */	 
 INT16 utraRssi ; /**< UTRA Carrier RSSI ; range 0 - 63	 
 UTRA_carrier_RSSI_LEV _00: UTRA carrier RSSI < -94 dBm	 
 UTRA_carrier_RSSI_LEV _01: -94 dBm ?UTRA carrier RSSI < -93 dBm	 
 UTRA_carrier_RSSI_LEV _02: -93 dBm ?UTRA carrier RSSI < -92 dBm	 
 UTRA_carrier_RSSI_LEV _61: -32 dBm ?UTRA carrier RSSI < -33 dBm	 
 UTRA_carrier_RSSI_LEV _62: -33 dBm ?UTRA carrier RSSI < -32 dBm	 
 UTRA_carrier_RSSI_LEV _63: -32 dBm ?UTRA carrier RSSI */	 
 INT16 cpichEcN0 ; /**< CPICH Ec / N0 , only valid for FDD */	 
 INT16 sQual ; /**< Cell selection quality ( Squal ) , only valid for FDD */	 
 INT16 sRxLev ; /**< Cell selection Rx level ( Srxlev ) */	 
 INT16 txPower ; /**< UE transmitted power */	 
 INT16 RxPower ; /**< CDMA will don ' t support now , be filled in future */ /*added by taow 20181107 CQ00112754 */	 
 /* TBD: Transport Channel BLER */	 
	 
 } CiDevUmtsServingCellMeasurements;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsServingCellParameters_struct 
 {	 
 UINT8 rac ; /**< Routing area code */	 
 UINT8 nom ; /**< Network operation mode */	 
	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT32 ci ; /**< Cell identity ; as per 3 G TS 25.331000 , 10.300000 .2.2 ( 28 bits ) */	 
 UINT16 uraId ; /**< URA identity */	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
	 
 UINT16 t3212 ; /**< Periodic LA update timer ( T3212 ) in minutes */	 
 UINT16 t3312 ; /**< Periodic RA update timer ( T3312 ) in minutes */	 
	 
 CiBoolean hcsUsed ; /**< Hierarchical cell structure used? \sa CCI API Ref Manual */	 
 CiBoolean attDetAllowed ; /**< Attach-detach allowed? \sa CCI API Ref Manual */	 
	 
	 
 UINT16 csDrxCycleLen ; /**< CS domain DRX cycle length */	 
 UINT16 psDrxCycleLen ; /**< PS domain DRX cycle length */	 
 UINT16 utranDrxCycleLen ; /**< UTRAN DRX cycle length */	 
 CiBoolean HSDPASupport ; /**< TRUE - serving cell supports HSDPA ; FALSE - other. \sa CCI API Ref Manual */	 
 CiBoolean HSUPASupport ; /**< TRUE - serving cell supports HSUPA ; FALSE - other. \sa CCI API Ref Manual */	 
	 
 /*Lilei , CQ00092855 , 20150427 , begin*/	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 /*Lilei , CQ00092855 , 20150427 , end*/	 
 /*Lilei , CQ00109042 , 20180118 , begin*/	 
 UINT8 band ;	 
 /*Lilei , CQ00109042 , 20180118 , end*/	 
 /*Lilei , CQ00115868 , 20190815 , begin*/	 
 UINT32 totalHandoversCount ;	 
 UINT32 succeededHandoversCount ;	 
 UINT32 succeededUmtsReselectionCount ;	 
 UINT32 timeStayUmtsConnectedMode ; // seconds	 
 /*Lilei , CQ00115868 , 20190815 , begin*/	 
 } CiDevUmtsServingCellParameters;

//ICAT EXPORTED ENUM 
 typedef enum CI_CIPHER_ALGORITHM_TYPE 
 {	 
 CI_CIPHER_ALGORITHM_TYPE_UEA0 , /**< As per 3 G TS 25.331000 , 10.300000 .3.4 */	 
 CI_CIPHER_ALGORITHM_TYPE_UEA1 /**< As per 3 G TS 25.331000 , 10.300000 .3.4 */	 
 } _CiCipherAlgorithmType;

typedef UINT8 CiCipherAlgorithmType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCipherAlgorithm_struct 
 {	 
 CiBoolean algPresent ; /**< Indicates if an algorithm is defined \sa CCI API Ref Manual */	 
 CiCipherAlgorithmType cipherAlg ; /**< Cipher algorithm type \sa CiCipherAlgorithmType */	 
 CiBoolean cipherOn ; /* Ciphering status = on / off \sa CCI API Ref Manual */	 
 } CiCipherAlgorithmInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsUeOperationStatus_struct 
 {	 
 CiDevEngModeUeRrcState rrcState ; /**< RRC state \sa CiDevEngModeUeRrcState */	 
 UINT8 numLinks ; /**< Number of radio links */	 
	 
 UINT16 srncId ; /**< U-RNTI: SRNC identifier */	 
 UINT32 sRnti ; /**< U-RNTI: S-RNTI */	 
 CiCipherAlgorithmInfo csCipherInfo ; /**< CS domain ciphering information. \sa CiCipherAlgorithm_struct */	 
 CiCipherAlgorithmInfo psCipherInfo ; /**< PS domain ciphering information. \sa CiCipherAlgorithm_struct */	 
 CiBoolean HSDPAActive ; /**< TRUE - HSDPA is currently activated ; FALSE - other \sa CCI API Ref Manual */	 
 CiBoolean HSUPAActive ; /**< TRUE - HSUPA is currently activated ; FALSE - other \sa CCI API Ref Manual */	 
 UINT16 MccLastRegisteredNetwork ; /**< Mcc of last registered network */	 
 UINT16 MncLastRegisteredNetwork ; /**< Mnc of last registered network */	 
 INT32 TMSI ; /**< TMSI */	 
 INT32 PTMSI ; /**< PTMSI */	 
 CiBoolean IsSingleMmRejectCause ; /**< TRUE - only one MM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 CiBoolean IsSingleGmmRejectCause ; /**< TRUE - only one GMM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 CiDevEngMMRejectCauseCodeType MMRejectCause ; /**< The one that was reported during the last engineering information period reject cause ( 10.500000 .3.6 ) sent in CM Service Reject , Abort , MM-Status , and Location Updating Reject messages to MM from the network. \sa CiDevEngMMRejectCauseCodeType */	 
 CiDevEngGMMRejectCauseCodeType GMMRejectCause ; /**< Reported during the last engineering information period \sa CiDevEngGMMRejectCauseCodeType */	 
 UINT8 mmState ; /**< MM state refer to 3 GPP 24.008000 section 4.100000 .2 */ /* see enum MmState in Mm_comm.h. */	 
 UINT8 gmmState ; /**< GMM state refer to 3 GPP 24.008000 section 4.100000 .3 */ /* see enum GmmState in Gmm_comm.h */	 
 UINT8 gprsReadyState ; /**< 0 - IDLE_STATE / 1 - STANDBY_STATE / 2 - READY_STATE. */ /* see enum GprsReadyState in grrmrtyp.h. */	 
 UINT16 readyTimerValueInSecs ; /**< MM ready timer value in sec [ value >0 ] */	 
 UINT8 NumActivePDPContext ; /**< Number of active PDP contexts */	 
 /*Michal Bukai - I-Mate Addition. Start:*/	 
 UINT32 ULThroughput ; /**< UL throughput in octets per second */	 
 UINT32 DLThroughput ; /**< DL throughput in octets per second */	 
 /*Michal Bukai - I-Mate Addition. End*/	 
 /*Added by Lilei for Network Info CQ56702 , begin*/	 
 UINT8 serviceStatus ; /**< Service status */ /* see enum ServiceStatus in Mmr_sig.h. */	 
 UINT8 pmmState ; /**< UMM state for PS services */ /* see enum UmmState in Mm_comm.h. */	 
 /*Added by Lilei for Network Info CQ56702 , end*/	 
 /*Lilei , CQ00082362 , 20150116 , begin*/	 
 UINT8 LAU_status ; /**<Current update status of the UE */ /* see enum LocationUpdateStatus in Mmr_sig.h. */	 
 UINT16 LAU_count ; /**<LAU attempt counter as held by UE ; number of consecutive LAU failures in current LAU procedure attempt */	 
 UINT8 RAU_status ; /**<RAU status of the UE */ /* see enum GprsUpdateStatus in Mmr_sig.h. */	 
 UINT16 RAU_count ; /**<RAU attempt counter as held by UE ; number of consecutive RAU failures in current RAU procedure attempt*/	 
 /*Lilei , CQ00082362 , 20150116 , end*/	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 UINT16 phyChType ; // 0 is DPCH , 1 is FDPCH. 0xFF is invalid	 
 UINT16 sf ;	 
 UINT8 slotFormat ;	 
 CiBoolean compressMode ;	 
 CiDevAmrCodecType codecType ; /*wCdma*/	 
 UINT32 speechCodecRate ; /*wCdma*/	 
 INT16 rssi ;	 
 CiBoolean isSinrPresent ;	 
 INT16 sinr ;	 
	 
 /*added by taow 20181107 CQ00112754 end*/	 
	 
 } CiDevUmtsUeOperationStatus;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsServingCellInfo_struct 
 {	 
 CiBoolean sCellMeasPresent ; /**< TRUE - is present ; FALSE - is not present. \sa CCI API Ref Manual */	 
 CiBoolean sCellParamPresent ; /**< TRUE - is present ; FALSE - is not present. \sa CCI API Ref Manual */	 
 CiBoolean ueOpStatusPresent ; /**< TRUE - is present ; FALSE - is not present. \sa CCI API Ref Manual */	 
 UINT8 res1U8 ; /**< padding */	 
 CiDevUmtsServingCellMeasurements sCellMeas ; /**< SCell measurements \sa CiDevUmtsServingCellMeasurements_struct */	 
 CiDevUmtsServingCellParameters sCellParam ; /**< PLMN / cell parameters \sa CiDevUmtsServingCellParameters_struct */	 
 CiDevUmtsUeOperationStatus ueOpStatus ; /**< UE operation status \sa CiDevUmtsUeOperationStatus_struct */	 
 } CiDevUmtsServingCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsASInfo_struct 
 {	 
 UINT32 ci ; /**< Cell identity ; as per 3 G TS 25.331000 , 10.300000 .2.2 ( 28 bits ) */	 
 UINT16 psc ; /**< Primary scrambling code */	 
 CiBoolean HSDPAServingCell ; /**< Indicates if this cell is the HSDPA serving cell \sa CCI API Ref Manual */	 
 CiBoolean HSUPAServingCell ; /**< Indicates if this cell is part of the HSUPA active set - relevant for rel. 6 \sa CCI API Ref Manual */	 
 INT16 cpichRSCP ; /**< CPICH received signal code power ; in UMTS FDD messages RSCP is transmitted as an integer value in the range of -120 dBm to -25 dBm. The value is coded into integers from -5 to 99 according to 3 GPP ' s 25.133000 . */	 
 INT16 cpichEcN0 ; /**< CPICH Ec / N0 [ dB ] */	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT8 rac ; /**< Routing area code , range 0 -1 ( 1 bit ) */	 
 } CiDevUmtsASInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeActiveSetInfoInd_struct 
 {	 
 UINT8 NumCells ; /**< Number of cells in active set */	 
 UINT16 arfcn ; /**< Absolute Radio Frequency Channel Number ; number 0 -1023 */	 
 UINT8 res1U8 ; /**< ( padding ) */	 
 CiDevUmtsASInfo ASinfo [ 6 ] ; /**< Active Set Information. \sa CiDevUmtsASInfo_struct */	 
 } CiDevPrimUmtsEngmodeActiveSetInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsFddTddNeighborInfo_struct 
 {	 
 /* Measurements */	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power */	 
 INT16 utraRssi ; /**< UTRA carrier RSSI */	 
 INT16 cpichEcN0 ; /**< CPICH Ec / N0 , only valid for FDD */	 
 INT16 sQual ; /**< Cell selection quality ( Squal ) , only valid for FDD */	 
 INT16 sRxLev ; /**< Cell selection Rx level ( Srxlev ) */	 
	 
 /* PLMN / Cell Parameters */	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 ci ; /**< Cell Identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiBoolean set ; /* intra freq neighbor 1 : active ; 0 : 2 sync neighbor set , 3 Async neighbor set */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevUmtsFddTddNeighborInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsGsmNeighborInfo_struct 
 {	 
 /* Measurements */	 
 INT16 gsmRssi ; /**< GSM carrier RSSI */	 
 INT16 rxLev ; /**< Cell selection Rx level */	 
 INT16 C1 ; /**< Path loss criterion parameter #1 */	 
 INT16 C2 ; /**< Path loss criterion parameter #2 */	 
	 
 /* PLMN / Cell Parameters */	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 ci ; /**< Cell identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT8 bsic ; /**< Base transceiver station identity code ; range 0 h-3Fh ( 6 bits ) */	 
 UINT8 res1U8 ;	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 INT16 rank ; // rValueRscp ;	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevUmtsGsmNeighborInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeUmtsData_struct 
 {	 
 /* Serving Cell information */	 
 CiDevUmtsServingCellInfo svcCellInfo ; /**< Serving cell information. \sa CiDevUmtsServingCellInfo_struct */	 
 UINT8 LastsCellParamsListIndex ; /**< Number of serving cells in last serving cells list */	 
 CiDevUmtsServingCellParameters LastsCellParamsList [ 6 ] ; /**< PLMN / cell parameters of the list \sa CiDevUmtsServingCellParameters_struct */	 
	 
 CiDevPrimUmtsEngmodeActiveSetInfo ASInfo ; /**< Active set information \sa CiDevPrimUmtsEngmodeActiveSetInfoInd_struct */	 
	 
 /* Neighboring Cell information */	 
 UINT8 numIntraFreq ; /**< Number of intra-frequency FDD cells */	 
 UINT8 numInterFreq ; /**< Number of inter-frequency FDD cells */	 
 UINT8 numInterRAT ; /**< Number of inter-RAT GSM cells */	 
 /*Add by taow for SSG request to get RRC release casue 20140902 , CQ 69749 , , begin*/	 
 UINT8 numberOfRabs ; // in order to not impact current EM CI interface , this only used by call drop	 
 UINT16 ul_arfcn ; // in order to not impact current EM CI interface , this only used by call drop , CQ77239	 
 /*Add by taow for SSG request to get RRC release casue 20140902 , CQ 69749 , , end*/	 
	 
 CiDevUmtsFddTddNeighborInfo intraFreq [ 32 ] ; /**< Intra-frequency information \sa CiDevUmtsFddTddNeighborInfo_struct */	 
 CiDevUmtsFddTddNeighborInfo interFreq [ 32 ] ; /**< Inter-frequency information \sa CiDevUmtsFddTddNeighborInfo_struct */	 
 CiDevUmtsGsmNeighborInfo interRAT [ 32 ] ; /**< Inter-RAT information \sa CiDevUmtsGsmNeighborInfo_struct */	 
	 
 CiDevEngActivePDPContextinfoType activePDPContextinfo [ 7 ] ; /**< Active PDP context data \sa CiDevEngActivePDPContextinfoType_struct */	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiDevEngModeNcellInfoListLte nCellInfoListLte ; /**< LTE neighbor cells info list */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevEngModeUmtsData;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_ENG_MODE_STATE_TAG 
 {	 
 CI_DEV_LTE_ENGINEER_RRC_DEACTIVATED = 0 , /**< RRC DEACTIVATED */	 
 CI_DEV_LTE_ENGINEER_RRC_IDLE , /**< RRC IDLE */	 
 CI_DEV_LTE_ENGINEER_RRC_CONNECTED , /**< RRC CONNECTED */	 
 CI_DEV_LTE_ENGINEER_RRC_IRAT_RESELETCTION , /**< RRC RESELETCTION */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_LTE_ENGINEER_MODE_STATE	 
 } _CiDevLteEngModeState;

typedef UINT8 CiDevLteEngModeState ;
//ICAT EXPORTED ENUM 
 typedef enum CiDEV_LTE_ENG_L1_CONFIG_TYPE_TAG 
 {	 
 CI_DEV_LTE_ENG_INVALID_RRC_L1_CONFIG , // The IE is not initialized	 
 CI_DEV_LTE_ENG_NOTCHANGE_SETUP_RRC_L1_CONFIG , // The IE was setup and its value is not changed in this configuration	 
 CI_DEV_LTE_ENG_NOTCHANGE_RELEASE_RRC_L1_CONFIG , // The IE was released and its value is not changed in this configuration	 
 CI_DEV_LTE_ENG_SETUP_RRC_L1_CONFIG , // The IE ' s value is setup or configured	 
 CI_DEV_LTE_ENG_RELEASE_RRC_L1_CONFIG , // The IE ' s value is released	 
 CI_DEV_LTE_ENG_L1_CREATE_VALUE_CONFIG , // Used for NEED OP with absent flag only , only when the default value is maintained by L1	 
	 
 CI_DEV_LTE_ENG_RRC_L1_CONFIG_TYPE_INVALID = 0x7FFFFFFF	 
 } 
 _CiDevLteEngL1ConfigType;

typedef UINT8 CiDevLteEngL1ConfigType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngDrxConfig_struct 
 {	 
 // Timer for DRX in TS 36.321000 , value range ( 1 , 2 , 3 , 4 , 5 , 6 , 8 , 10 , 20 , 30 , 40 , 50 , 60 , 80 , 100 , 200 )	 
 UINT8 onDurationTimer ;	 
 // Timer for DRX in TS 36.321000 , value range ( 1 , 2 , 4 , 6 , 8 , 16 , 24 , 33 )	 
 UINT8 drxRetransmissionTimer ;	 
 // Drx inactivity timer in TS36.321 , value range ( 1 , 2 , 3 , 4 , 5 , 6 , 8 , 10 , 20 , 30 , 40 , 50 , 60 , 80 , 100 , 200 , 300 , 500 , 750 , 1280 , 1920 , 2560 )	 
 UINT16 drxInactivityTimer ;	 
	 
 // long DRX cycle , value range ( 10 , 20 , 32 , 40 , 64 , 80 , 128 , 160 , 256 , 320 , 512 , 640 , 1024 , 1280 , 2048 , 2560 )	 
 UINT16 longDrxCycle ;	 
 // drx Start offset , value range ( 0 ~2559 ) , this value should be less than longDrxCycle	 
 UINT16 drxStartOffset ;	 
	 
 // If this IE doesn ' t exists in ASN.1 message , value 0 for release should be filled here	 
 // Value range ( 2 , 5 , 8 , 16 , 20 , 32.400000 , 64 , 80 , 128 , 160 , 256 , 320 , 512 , 640 )	 
 UINT16 shortDrxCycle ;	 
 // If this IE doesn ' t exists in ASN.1 message , value 0 for release should be filled here	 
 // Value range:1~16	 
 UINT8 drxShortCycleTimer ;	 
 UINT8 reserved0 ;	 
	 
 // Configuration type of shortDrx	 
 CiDevLteEngL1ConfigType shortDrxConfigType ;	 
 } 
 CiDevLteEngDrxConfig;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLtePlmnIdentity_struct 
 {	 
 UINT16 mcc ;	 
 // Length of MNC , value range ( 2 , 3 )	 
 UINT8 lenOfMnc ;	 
 // 2 -3 digits of MNC	 
 UINT16 mnc ;	 
 } CiDevLtePlmnIdentity;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngScellParams_struct 
 {	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT16 mcc ;	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT16 mnc ; /**< 2 -3 digits of MNC */	 
 UINT16 tac ;	 
 UINT16 phyCellId ;	 
 UINT32 dlEuArfcn ;	 
 UINT32 ulEuArfcn ;	 
 UINT16 band ;	 
 UINT8 dlBandwidth ; /*0 - 1.400000 M , 1 - 3 M , 2 - 5 M , 3 - 10 M , 4 - 15 M , 5 - 20 M */	 
 UINT32 cellId ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 /*Added by taow for LTE EM L2 info , begin*/	 
 UINT8 subFrameAssignType ;	 
 UINT8 specialSubframePatterns ;	 
 UINT8 transMode ;	 
 /*Added by taow for LTE EM L2 info , end*/	 
	 
 /*Added by taow for Handover event info , begin*/	 
	 
 UINT32 totalHandoversCount ;	 
 UINT32 succeededHandoversCount ;	 
 /*Added by taow for Handover event info , begin*/	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiBoolean isTdd ;	 
 UINT8 subframeAssignment ; // only Valid if isTdd= TRUE , Value range: ( 0 , 1 , 2 , 3 , 4 , 5 , 6 ) , in SIB1 tdd-Config.	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00115868 , 20190815 , begin*/	 
 UINT32 succeededLteReselectionCount ;	 
 UINT32 succeededLteReestCounter ;	 
 UINT32 timeStayConnectedMode ; // seconds	 
 /*Lilei , CQ00115868 , 20190815 , end*/	 
 /*Lilei , CQ00126320 , 20201123 , begin*/	 
 CiBoolean longDRXCyclePresent ;	 
 UINT16 longDRXCycle ; /**< long DRX cycle in ms */	 
 CiBoolean shortDRXCyclePresent ;	 
 UINT16 shortDRXCycle ; /**< short DRX cycle in ms */	 
 UINT16 pagingCycle ; /**< The pagingCycle is configured in unit of 10 ms , aligned to 36.331000 */	 
 /*Lilei , CQ00126320 , 20201123 , end*/	 
 /*Lilei , CQ00134582 , 20211221 , begin*/	 
 UINT16 t3402 ; /**< timer T3402 in seconds */	 
 UINT16 t3412 ; /**< timer T3412 in seconds */	 
 /*Lilei , CQ00137275 , 20220616 , begin*/	 
 // UINT32 reserved1 ;	 
 INT8 refSignalPower ; /**< PDSCH-ConfigCommon.referenceSignalPower. Value range: -60~50 , invalid ( 0x7F ) . */	 
 UINT8 establishmentCause ; /**< RRC connection request cause */ /*Lilei , CQ00146454 , 20231023 */	 
 UINT16 reserved1 ;	 
 /*Lilei , CQ00137275 , 20220616 , end*/	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 /*Lilei , CQ00134582 , 20211221 , end*/	 
 } 
 CiDevLteEngScellParams;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngScellMeas_struct 
 {	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 INT8 sinr ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT8 mainRsrp ; /**< Rsrp of main antenna. Value range: 0 ~97 , invalid ( 0xFF ) */	 
 UINT8 diversityRsrp ; /**< Rsrp of diversity antenna. Value range: 0 ~97 , invalid ( 0xFF ) */	 
 UINT8 mainRsrq ; /**< Rsrq of main antenna. Value range: 0 ~34 , invalid ( 0xFF ) */	 
 UINT8 diversityRsrq ; /**< Rsrq of diversity antenna. Value range: 0 ~34 , invalid ( 0xFF ) */	 
 UINT8 rssi ; /**< Same value as CESQ rxlev */	 
 UINT16 cqi ; /**< Value range: 0 ~15 , invalid ( 0xFFFF ) . */	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 /*Added by taow for LTE EM L2 info , begin*/	 
 UINT8 pathLoss ;	 
 UINT32 tb0DlTpt ;	 
 UINT32 tb1DlTpt ;	 
 UINT32 tb0DlPeakTpt ;	 
 UINT32 tb1DlPeakTpt ;	 
 UINT32 tb0UlPeakTpt ;	 
 UINT32 tb1UlPeakTpt ;	 
 // EmacdlStatisticDataTag	 
 UINT32 dlThroughPut ; // dl throughtput unit bps , sum ( dl tb size in bits ) / dl statistic time duration	 
 UINT32 dlPeakThroughPut ; // Kbps	 
 UINT8 averDlPRB ;	 
 UINT8 averCQITb0 ;	 
 UINT8 averCQITb1 ;	 
 UINT8 rankIndex ;	 
 // EmaculStatisticDataTag	 
 UINT32 grantTotal ; // total received grant size in unit of BYTE	 
 UINT32 ulThroughPut ; // Kbps	 
 UINT32 ulPeakThroughPut ; // Kbps	 
 INT16 currPuschTxPower ;	 
 UINT8 averUlPRB ;	 
 // add by taow 20150415 begin	 
 UINT8 averULMcs ; // modify by taow 20190220	 
 UINT16 dlBler ;	 
 UINT16 ulBler ;	 
 /*modify by taow CQ00131112 20210621 begin*/	 
 // UINT32 reserved1 ;	 
 INT8 diversitySinr ;	 
 UINT8 diversityRssi ;	 
 UINT8 qRxLevMin ; /**< report value range [ 0 , 96 ] , real value range [ -140 , -44 ] , real value =IE value - 140 ; eg:0-140= -140 , 96 -140=-44*/	 
 /*Lilei , CQ00137040 , 20220527 , begin*/	 
 INT8 qQualMin ;	 
 // UINT8 reserved1_1 ;	 
 /*Lilei , CQ00137040 , 20220527 , end*/	 
 /*modify by taow CQ00131112 20210621 end*/	 
 /*Lilei , CQ00143212 , 20230424 , begin*/	 
 // UINT32 reserved2 ;	 
 INT8 mainSinr ; /**< SINR of main antenna */	 
 UINT8 mainRssi ; /**< RSSI of main antenna */	 
 UINT16 reserved2_1 ;	 
 /*Lilei , CQ00143212 , 20230424 , end*/	 
	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 // add by taow 20150415 end	 
 /*Added by taow for LTE EM L2 info , end*/	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 INT16 srxlev ;	 
 INT16 txPower ; // PUSCH tx power.	 
 UINT8 mainDLMcs ; /**< Modulation and coding scheme ( MCS ) of main antenna. Value range: 0 ~32 */	 
 UINT8 diversityDLMcs ; /**< Modulation and coding scheme ( MCS ) of diversity antenna. Value range: 0 ~32 */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00115868 , 20190815 , begin*/	 
 UINT8 averDlMcsTb0 ;	 
 UINT8 averDlMcsTb1 ;	 
 /*Lilei , CQ00115868 , 20190815 , end*/	 
 } 
 CiDevLteEngScellMeas;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLtePlmnIdentityInfo_struct 
 {	 
 CiDevLtePlmnIdentity plmnIdentity ;	 
 CiBoolean cellReservedForOperatorUse ;	 
 } CiDevLtePlmnIdentityInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_CONFIG_TYPE_TAG 
 {	 
 CI_DEV_LTE_NOTPRESENT_RRC_CONFIG ,	 
 // PRESENT ,	 
 CI_DEV_LTE_SETUP_RRC_CONFIG ,	 
 CI_DEV_LTE_RELEASE_RRC_CONFIG	 
 } 
 _CiDevLteRrcConfigType;

typedef UINT8 CiDevLteRrcConfigType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngineerCellAccessRestrictions_struct 
 {	 
 UINT8 numOfPlmnInList ;	 
 CiDevLtePlmnIdentityInfo plmnIdentityList [ 6 ] ;	 
 // To identify a tracking area within the scope of a PLMN	 
 UINT16 trackingAreaCode ;	 
 // the IE is used to unambiguously identify a cll within a PLMN	 
 UINT32 cellIdentity ;	 
 CiBoolean cellBarred ;	 
 CiBoolean intraFreqReselAllowed ;	 
 CiBoolean csgIndication ;	 
 // Release or set up a closed subscriber group	 
 CiDevLteRrcConfigType csgIdentityR9ConfigType ;	 
 // to identify a Closed Subscriber Group , BIT STRING ( SIZE ( 27 ) )	 
 UINT32 csgIdentityR9 ;	 
	 
 } CiDevLteEngineerCellAccessRestrictions;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_ENGINEER_BARRED_STATUS_TAG 
 {	 
 CI_DEV_LTE_ENGINEER_NOT_BARRED ,	 
 CI_DEV_LTE_ENGINEER_BARRED_NO_SERVICE ,	 
 CI_DEV_LTE_ENGINEER_BARRED_EMERGENCY_ONLY	 
 } 
 _CiDevLteEngineerBarredStatus;

typedef UINT8 CiDevLteEngineerBarredStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteUeOperationStatus_struct 
 {	 
 CiDevLteEngModeState errcModeState ; /**< ERRC state \sa CiDevLteEngModeState */	 
 UINT8 emmState ; /**< EMM state */ /* see enum EmmState in Mmr_sig.h */	 
 UINT8 serviceState ; /**< Service state */ /* see enum ServiceStatus in Mmr_sig.h */	 
 CiBoolean IsSingleEmmRejectCause ; /**< TRUE - only one EMM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 UINT32 EMMRejectCause ; /**< Reported during the last engineering information period */	 
 UINT16 mmeGroupId ; /**< A member of GUTI */	 
 UINT8 mmeCode ; /**< A member of GUTI */	 
 UINT32 mTmsi ; /**< A member of GUTI */	 
 /*Lilei , CQ00126320 , 20201123 , begin*/	 
 CiDevServiceType serviceDomain ; /**< CS or PS domain , 0 :CS only ; 1 :PS only ; 2 :Combined CS / PS ; 3 :no service */	 
 /*Lilei , CQ00126320 , 20201123 , end*/	 
 } CiDevLteUeOperationStatus;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngScellInfo_struct 
 {	 
 CiDevLteEngScellParams params ;	 
 CiDevLteEngScellMeas meas ;	 
 // CiDevLteEngineerCellAccessRestrictions accessRestrictions ;	 
 // CiDevLteEngineerBarredStatus barredStatus ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 CiDevLteUeOperationStatus ueOpStatus ; /**< UE operation status \sa CiDevLteUeOperationStatus */	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 } 
 CiDevLteEngScellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngNcellSib1_struct 
 {	 
 // To indicate for cell re-selection the required minimum received RSRP level in the ( E-UTRA ) cell.	 
 // Corresponds to parameter Qrxlevmin in 36.304000 [ 4 ] . Actual value Qrxlevmin = IE value * 2 [ dBm ] .	 
 INT16 qRxLevMin ; // RHGUO: -140 ~ -44	 
 CiBoolean qRxLevMinOffsetPresent ;	 
 // Parameter Qrxlevminoffset in 36.304000 [ 4 ] . Actual value Qrxlevminoffset = IE value * 2 [ dB ] . If absent ,	 
 // apply the ( default ) value of 0 [ dB ] for Qrxlevminoffset. Affects the minimum required Rx level in the cell.	 
 UINT8 qRxLevMinOffset ;	 
 CiBoolean cellSelectionInfoV920Present ;	 
 INT8 qQualMinR9 ;	 
 CiBoolean qQualMinOffsetR9Present ;	 
 UINT8 qQualMinOffsetR9 ;	 
 } 
 CiDevLteEngNcellSib1;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngIntraFreqNcellInfo_struct 
 {	 
 UINT16 phyCellId ;	 
 UINT32 euArfcn ;	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 // CiBoolean ncellSib1Valid ;	 
 // CiDevLteEngNcellSib1 ncellSib1 ;	 
 // CiBoolean accessRestrictionsPresent ;	 
 // CiDevLteEngineerCellAccessRestrictions accessRestrictions ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT16 mcc ;	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT16 mnc ; /**< 2 -3 digits of MNC */	 
 UINT16 tac ;	 
 UINT32 cellId ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 INT16 srxlev ;	 
 // Value range:0~7 , Value 0 means lowest priority	 
 UINT8 cellReselectionPriority ;	 
 UINT8 sNonIntraSearch ;	 
 UINT8 threshServingLow ;	 
 UINT16 sIntraSearch ;	 
 // Int8 sinr // replace by rsrq ;	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00137275 , 20220630 , begin*/	 
 INT8 refSignalPower ; /**< PDSCH-ConfigCommon.referenceSignalPower. Value range: -60~50 , invalid ( 0x7F ) . */	 
 /*Lilei , CQ00137275 , 20220630 , end*/	 
 UINT8 reserved1_0 ;	 
 UINT16 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 } 
 CiDevLteEngIntraFreqNcellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngIntraFreqNcellList_struct 
 {	 
 UINT8 numberOfCells ;	 
 CiDevLteEngIntraFreqNcellInfo cellInfo [ 16 ] ;	 
 } 
 CiDevLteEngIntraFreqNcellList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngInterFreqNcellInfo_struct 
 {	 
 UINT16 phyCellId ;	 
 UINT32 euArfcn ;	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 // CiBoolean ncellSib1Valid ;	 
 // CiDevLteEngNcellSib1 ncellSib1 ;	 
 // CiBoolean accessRestrictionsPresent ;	 
 // CiDevLteEngineerCellAccessRestrictions accessRestrictions ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT16 mcc ;	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT16 mnc ; /**< 2 -3 digits of MNC */	 
 UINT16 tac ;	 
 UINT32 cellId ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 INT16 srxlev ;	 
 UINT8 threshXLow ; // Value range:0~31 received from SIB5	 
 UINT8 threshXHigh ; // Value range:0~31 received from SIB5	 
 UINT8 cellReselectionPriority ;	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 // Int8 sinr // replace by rsrq ;	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00137275 , 20220630 , begin*/	 
 INT8 refSignalPower ; /**< PDSCH-ConfigCommon.referenceSignalPower. Value range: -60~50 , invalid ( 0x7F ) . */	 
 /*Lilei , CQ00137275 , 20220630 , end*/	 
 UINT8 reserved1_0 ;	 
 UINT16 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 } 
 CiDevLteEngInterFreqNcellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngInterFreqNcellList_struct 
 {	 
 UINT8 numberOfCells ;	 
 CiDevLteEngInterFreqNcellInfo cellInfo [ 16 ] ;	 
 } 
 CiDevLteEngInterFreqNcellList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraCellParamsStruct 
 {	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT32 ci ; /**< Cell identity ; as per 3 G TS 25.331000 , 10.300000 .2.2 ( 28 bits ) */	 
 UINT16 uArfcn ;	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 // UINT16 phyCellId ;	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 UINT8 cellReselectionPriority ;	 
 UINT8 threshXHigh ; // Value range:0~31 received from SIB6	 
 UINT8 threshXLow ; // Value range:0~31 received from SIB6	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00134586 , 20211221 , begin*/	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 /*Lilei , CQ00134586 , 20211221 , end*/	 
 } 
 CiDevLteEngUtraCellParams;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraCellMeas_struct 
 {	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power ; in UMTS FDD / TDD messages RSCP is	 
 transmitted as an integer value in the range of -120 dBm to -25 dBm.	 
 The value is coded into integers from -5 to 99 according to 3 GPP ' s 25.133000 . */	 
 // INT16 pccpch_RSCP ; // for TDD	 
 INT16 cpichEcN0 ; // For FDD	 
 // INT16 cpichRscp ; // For FDD	 
 INT16 srxlev ; /*added by taow 20181107 CQ00112754 */	 
 } 
 CiDevLteEngUtraCellMeas;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraNcellInfo_struct 
 {	 
 CiDevLteEngUtraCellParams params ;	 
 CiDevLteEngUtraCellMeas meas ;	 
 } 
 CiDevLteEngUtraNcellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraCellList_struct 
 {	 
 UINT8 numberOfCells ;	 
 CiDevLteEngUtraNcellInfo cellInfo [ 16 ] ;	 
 } 
 CiDevLteEngUtraCellList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngBsic_struct 
 {	 
 // the lowest 0 ~2 bits of bsic store the bcc , the lowest 3 ~5 bit of bsic store the ncc	 
 UINT8 ncc ;	 
 UINT8 bcc ;	 
 } 
 CiDevLteEngBsic;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellParams_struct 
 {	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT32 ci ; /**< Cell identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 // UINT8 gsmBandIndicator ;	 
 // CiBoolean bsicPresent ; // ncc and bcc is valid only when bsicPresent is TURE.	 
 // CiDevLteEngBsic bsic ;	 
 UINT8 bsic ; /**< Base transceiver station identity code ; range 0 h-3Fh ( 6 bits ) ; 0xFF means not present */	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 UINT8 gsmBandIndicator ;	 
 UINT8 cellReselectionPriority ;	 
 UINT8 threshXHigh ; // Value range:0~31 received from SIB7	 
 UINT8 threshXLow ; // Value range:0~31 received from SIB7	 
 CiBoolean nccPermitted ;	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00134586 , 20211221 , begin*/	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 /*Lilei , CQ00134586 , 20211221 , end*/	 
 } 
 CiDevLteEngGsmCellParams;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellMeas_struct 
 {	 
 INT16 rssi ; /**< GSM carrier RSSI */	 
 INT16 srxlev ; /*added by taow 20181107 CQ00112754 */	 
 } 
 CiDevLteEngGsmCellMeas;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellInfo_struct 
 {	 
 CiDevLteEngGsmCellParams params ;	 
 CiDevLteEngGsmCellMeas meas ;	 
 } 
 CiDevLteEngGsmCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellList_struct 
 {	 
 UINT8 numberOfCells ;	 
 CiDevLteEngGsmCellInfo cellInfo [ 16 ] ;	 
 } 
 CiDevLteEngGsmCellList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeSvcCellInfoInd_struct 
 {	 
 // CiDevLteEngModeState mode ; / **< Current mode ( deactivated / idle / connected / reselection ) \sa CiDevLteEngModeState * /	 
 CiBoolean sCellPresent ; /**< Whether serving cell engmode info is present */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevLteEngScellInfo info ; /**< Engineering mode LTE serving cell information \sa CiDevLteEngScellInfo */	 
 } CiDevPrimLteEngmodeScellInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeIntraFreqInfoInd_struct 
 {	 
 UINT8 numIntraFreq ; /**< Number of Intra-Frequency Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevLteEngIntraFreqNcellInfo intraFreq [ 16 ] ; /**< Intra-Frequency Info. \sa CiDevLteEngIntraFreqNcellInfo */	 
 } CiDevPrimLteEngmodeIntraFreqInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeInterFreqInfoInd_struct 
 {	 
 UINT8 numInterFreq ; /**< Number of Inter-Frequency Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevLteEngInterFreqNcellInfo interFreq [ 16 ] ; /**< Inter-Frequency Info. \sa CiDevLteEngInterFreqNcellInfo */	 
 } CiDevPrimLteEngmodeInterFreqInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeInterRatInfoInd_struct 
 {	 
 UINT8 numInterRATUtra ; /**< Number of Inter-RAT UMTS Cells */	 
 UINT8 numInterRATGsm ; /**< Number of Inter-RAT GSM Cells */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 CiDevLteEngUtraNcellInfo interRATUtra [ 16 ] ; /**< Inter-Rat UMTS Info. \sa CiDevLteEngUtraNcellInfo */	 
 CiDevLteEngGsmCellInfo interRATGsm [ 16 ] ; /**< Inter-Rat UMTS Info. \sa CiDevLteEngUtraNcellInfo */	 
 } CiDevPrimLteEngmodeInterRatInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeGsmDataInfo_struct 
 {	 
 CiDevEngModeGsmData data ; /* GSM data \sa CiDevEngModeGsmData_struct */	 
 CiDevEngActivePDPContextinfoType activePDPContextinfo [ 7 ] ; /* ActivePDPContext data. \sa CiDevEngActivePDPContextinfoType_struct */	 
 } CiDevEngModeGsmDataInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeGsmUmtsData_struct {	 
 CiDevEngModeUmtsData umtsData ; /**< UMTS Data. \sa CiDevEngModeUmtsData_struct */	 
 CiDevEngModeGsmDataInfo gsmData ; /**< GSM Data. \sa CiDevEngModeGsmDataInfo_struct */	 
 } CiDevEngModeGsmUmtsData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeLteData_struct 
 {	 
 // CiDevLteEngModeState errcModeState ; / **< RRC DEACTIVATED , IDLE , CONNECTED and RESELETCTION* /	 
	 
 CiBoolean sCellPresent ;	 
 CiBoolean intraFreqNcellsPresent ;	 
 CiBoolean interFreqNcellsPresent ;	 
 CiBoolean utraNcellsPresent ;	 
 CiBoolean gsmNcellsPresent ;	 
 CiBoolean sCellUpdated ; /**< wether svc cell has been updated or not */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
	 
 CiDevLteEngScellInfo sCell ;	 
 CiDevLteEngIntraFreqNcellList intraFreqNcells ;	 
 CiDevLteEngInterFreqNcellList interFreqNcells ;	 
 CiDevLteEngUtraCellList utraNcells ;	 
 CiDevLteEngGsmCellList gsmNcells ;	 
 } CiDevEngModeLteData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeInfo_struct 
 {	 
 CiDevEngModeState mode ; /**< Current mode ( idle / dedicated ) \sa CiDevEngModeState */	 
 CiDevEngModeNetwork network ; /**< Network type ( GSM / UMTS ) \sa CiDevEngModeNetwork */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
	 
 /* VADIM fix for CQ00082654 - debug only */	 
 CiDevEngModeGsmUmtsData *data ;	 
 /* UMTS or GSM Data -- depending on network type */	 
 /* UMTS or GSM Data -- depending on Network Type */	 
 // union	 
 // {	 
 // CiDevEngModeUmtsData umtsData ; / **< UMTS Data. \sa CiDevEngModeUmtsData_struct * /	 
 // CiDevEngModeGsmDataInfo gsmData ; / **< GSM Data. \sa CiDevEngModeGsmDataInfo_struct * /	 
 // } data ;	 
 /* VADIM fix for CQ00082654 - debug only */	 
	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 CiDevEngModeLteData *lteData ; /**< LTE Enginerring Mode Data */	 
 CiBoolean isDualLinkLteOn ; /**< Whether LTE is registered for dual link */	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 } CiDevEngModeInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimStatusInd_struct {	 
 CiDevStatus status ; /**< Device status \sa CiDevStatus */	 
 } CiDevPrimStatusInd;

typedef CiEmptyPrim CiDevPrimGetManuIdReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetManuIdCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiString manuStr ; /**< Manufacture ID string. Refer to " Cellular Interface Application Programming Interface " , revision i0.6. Max length is 2048 . \sa CCI API Ref Manual */	 
 } CiDevPrimGetManuIdCnf;

typedef CiEmptyPrim CiDevPrimGetModelIdReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetModelIdCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiString modelStr ; /**< Model ID string. Refer to " Cellular Interface Application Programming Interface " , revision i0.6. Max length is 2048 . \sa CCI API Ref Manual */	 
 } CiDevPrimGetModelIdCnf;

typedef CiEmptyPrim CiDevPrimGetRevisionIdReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetRevisionIdCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiString revisionStr ; /**< Revision ID string. Refer to " Cellular Interface Application Programming Interface " , revision i0.6. Max length is 2048 . \sa CCI API Ref Manual */	 
 } CiDevPrimGetRevisionIdCnf;

typedef CiEmptyPrim CiDevPrimGetSerialNumIdReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSerialNumIdCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiString serialNumStr ; /**< Serial number ID string. Refer to " Cellular Interface Application Programming Interface " , revision i0.6. Max length is 2048 . \sa CCI API Ref Manual */	 
 } CiDevPrimGetSerialNumIdCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetFuncReq_struct {	 
 CiDevFunc func ; /**< Functionality , related to the power level a phone should draw. \sa CiDevFunc */	 
 CiBoolean reset ; /**< TRUE - Reset before setting to functionality power level ; FALSE - No reset before setting ( default ) \sa CCI API Ref Manual */	 
 CiBoolean IsCommFeatureConfig ; /**< TRUE - CommFeatureConfig should be changed , next field present */	 
 CiBitRange CommFeatureConfig ; /**< communication feature configuration Enable / Disable like CSD / FAX / etc */	 
 } CiDevPrimSetFuncReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetFuncCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 } CiDevPrimSetFuncCnf;

typedef CiEmptyPrim CiDevPrimGetFuncReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetFuncCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiDevFunc func ; /**< Functionality , related to the power level a phone should draw. \sa CiDevFunc */	 
 CiBitRange CommFeatureConfig ; /**< communication feature configuration Enable / Disable like CSD / FAX / etc */	 
 } CiDevPrimGetFuncCnf;

typedef CiEmptyPrim CiDevPrimGetFuncCapReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetFuncCapCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiBitRange bitsFunc ; /**< Supported functionality setting. Refer to " Cellular Interface Application Programming Interface " , revision i0.6. \sa CCI API Ref Manual */	 
 CiBitRange bitsReset ; /**< Supported reset setting. Refer to " Cellular Interface Application Programming Interface " , revision i0.6. \sa CCI API Ref Manual */	 
 } CiDevPrimGetFuncCapCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetGsmPowerClassReq_struct {	 
 CiDevBand band ;	 
 CiDevPwCls pwcls ;	 
 } CiDevPrimSetGsmPowerClassReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetGsmPowerClassCnf_struct {	 
 CiDevRc rc ;	 
 } CiDevPrimSetGsmPowerClassCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetGsmPowerClassReq_struct {	 
 CiDevBand band ;	 
 } CiDevPrimGetGsmPowerClassReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetGsmPowerClassCnf_struct {	 
 CiDevRc rc ;	 
 CiDevPwCls curPwCls ;	 
 CiDevPwCls defPwCls ;	 
 } CiDevPrimGetGsmPowerClassCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetGsmPowerClassCapReq_struct {	 
 CiDevBand band ;	 
 } CiDevPrimGetGsmPowerClassCapReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetGsmPowerClassCapCnf_struct {	 
 CiDevRc rc ;	 
 CiBitRange bitsPwCls ;	 
 } CiDevPrimGetGsmPowerClassCapCnf;

typedef CiEmptyPrim CiDevPrimPmPowerDownReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimPmPowerDownCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 } CiDevPrimPmPowerDownCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetEngmodeRepOptReq_struct 
 {	 
 CiDevEngModeReportOption type ; /**< Report type \sa CiDevEngModeReportOption */	 
 UINT16 interval ; /**< Report interval ( in seconds ) for PERIODIC */	 
 } CiDevPrimSetEngmodeRepOptReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetEngmodeRepOptCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ;	 
 } CiDevPrimSetEngmodeRepOptCnf;

//ICAT EXPORTED ENUM 
 typedef enum CiDEVENGMODETYPE_TAG {	 
 CI_DEV_ENGINEER_MODE_NONE= 0 , /**< worked with AT+ EEMOPT ; step1: AT+ EEMOPT , step2: AT+EEMGINFO? ; */	 
 CI_DEV_ENGINEER_MODE_NORMAL , /**< no used in oneshot mode AT+EEMGNFO? occupy a position*/	 
 CI_DEV_ENGINEER_MODE_ONESHOT , /**< used in oneshot mode AT+EEMGNFO? may include Ncell info*/	 
 CI_DEV_ENGINEER_MODE_ONESHOT_NCELL_REQUIRED , /**< used in oneshot mode AT+EEMGNFO?.must decode system info to get Ncell , but in the end , may still not get NCELL. this cost 7 s*/	 
 CI_DEV_ENGINEER_MODE_MAX	 
	 
 } _CiDevEngmodeType;

typedef UINT8 CiDevEngmodeType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetEngmodeInfoReq_struct 
 {	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiDevEngmodeType engmodeEnhanceType ; /**< enhancement request: until all engineer IND msgs from AS were recieved , sac send request confirm to AP */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevPrimGetEngmodeInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetEngmodeInfoCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiDevEngModeState mode ; /**< Current mode ( idle / dedicated ) \sa CiDevEngModeState */	 
 CiDevEngModeNetwork network ; /**< Network type ( GSM / UMTS ) \sa CiDevEngModeNetwork */	 
 } CiDevPrimGetEngmodeInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimEngmodeInfoInd_struct 
 {	 
 CiDevEngModeInfo info ;	 
 } CiDevPrimEngmodeInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGsmEngmodeInfoInd_struct 
 {	 
 CiDevEngModeState mode ; /**< Current Mode ( Idle / Dedicated ) . \sa CiDevEngModeState */	 
 UINT8 releaseVersion ; /**< 3 GPP release versions */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 CiDevEngModeGsmData info ; /**< GSM Engineering Mode information. \sa CiDevEngModeGsmData_struct */	 
 } CiDevPrimGsmEngmodeInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeSvcCellInfoInd_struct 
 {	 
 CiDevEngModeState mode ; /**< Current mode ( idle / dedicated ) \sa CiDevEngModeState */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsServingCellInfo info ; /**< Engineering mode 3 G ( UMTS ) serving cell information \sa CiDevUmtsServingCellInfo_struct */	 
 } CiDevPrimUmtsEngmodeScellInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeIntraFreqInfoInd_struct 
 {	 
 UINT8 numIntraFreq ; /**< Number of Intra-Frequency FDD Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsFddTddNeighborInfo intraFreq [ 32 ] ; /**< Intra-Frequency Info. \sa CiDevUmtsFddTddNeighborInfo_struct */	 
 } CiDevPrimUmtsEngmodeIntraFreqInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeInterFreqInfoInd_struct 
 {	 
 UINT8 numInterFreq ; /**< Number of Inter-Frequency FDD Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsFddTddNeighborInfo interFreq [ 32 ] ; /**< Inter-Frequency Info. \sa CiDevUmtsFddTddNeighborInfo_struct */	 
 } CiDevPrimUmtsEngmodeInterFreqInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeInterRatInfoInd_struct 
 {	 
 UINT8 numInterRAT ; /**< Number of Inter-RAT GSM Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsGsmNeighborInfo interRAT [ 32 ] ; /**< Inter-Rat Info. \sa CiDevUmtsGsmNeighborInfo_struct */	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiDevEngModeNcellInfoListLte nCellInfoListLte ; /**< LTE neighbor cells info list */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevPrimUmtsEngmodeInterRatInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetEngmodeNcellReportOptionReq_struct {	 
 CiBoolean enable ; /**< Enable ( 1 ) / disable ( 0 ) neighbor cell info report */	 
 UINT16 interval ; /**< Periodic report interval ( in seconds ) , default 2 seconds */	 
 } CiDevPrimSetEngmodeNcellReportOptionReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetEngmodeNcellReportOptionCnf_struct {	 
 CiDevRc result ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetEngmodeNcellReportOptionCnf;

typedef CiEmptyPrim CiDevPrimGetEngmodeNcellInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetEngmodeNcellInfoCnf_struct {	 
 CiDevRc result ; /**< Result code. \sa CiDevRc */	 
 CiDevEngModeNetwork network ; /**< Current network type. \sa CiDevEngModeNetwork */	 
 CiDevEngModeNcellInfoListGsm nCellInfoListGsm ; /**< GSM neighbor cells info list */	 
 CiDevEngModeNcellInfoListUmts nCellInfoListUmts ; /**< UMTS neighbor cells info list */	 
 CiDevEngModeNcellInfoListLte nCellInfoListLte ; /**< LTE neighbor cells info list */	 
 } CiDevPrimGetEngmodeNcellInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimEngmodeNcellInfoInd_struct {	 
 CiDevEngModeNetwork network ; /**< Current network type. \sa CiDevEngModeNetwork */	 
 CiDevEngModeNcellInfoListGsm nCellInfoListGsm ; /**< GSM neighbor cells info list */	 
 CiDevEngModeNcellInfoListUmts nCellInfoListUmts ; /**< UMTS neighbor cells info list */	 
 CiDevEngModeNcellInfoListLte nCellInfoListLte ; /**< LTE neighbor cells info list */	 
 } CiDevPrimEngmodeNcellInfoInd;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_SELF_TEST_RESULT 
 {	 
 CI_DEV_SELF_TEST_OK ,	 
 CI_DEV_SELF_TEST_FAILURE ,	 
 CI_DEV_SELF_TEST_INCOMPATIBLE_SW_VERSION ,	 
 CI_DEV_SELF_TEST_ILLEGAL_BATTERY ,	 
	 
 CI_DEV_NUM_SELF_TEST_RESULTS	 
	 
 } _CiDevSelfTestResult;

typedef UINT8 CiDevSelfTestResult ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RFS_LEVEL 
 {	 
 CI_DEV_RFS_USER_LEVEL ,	 
 CI_DEV_RFS_DEEP_LEVEL ,	 
	 
 CI_DEV_NUM_RFS_LEVEL	 
	 
 } _CiDevRfsLevel;

typedef UINT8 CiDevRfsLevel ;
//ICAT EXPORTED ENUM 
 typedef enum CiDEVLPRRCSTATE_TAG 
 {	 
 CI_DEV_LP_RRC_STATE_CELL_DCH = 0 , /**< RRC state CELL DCH */	 
 CI_DEV_LP_RRC_STATE_CELL_FACH , /**< RRC state CELL FACH */	 
 CI_DEV_LP_RRC_STATE_CELL_PCH , /**< RRC state CELL PCH */	 
 CI_DEV_LP_RRC_STATE_URA_PCH , /**< RRC state URA PCH */	 
 CI_DEV_LP_RRC_STATE_IDLE /**< RRC state idle */	 
 } _CiDevLpRRCState;

typedef UINT8 CiDevLpRRCState ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVLPBEARERTYPE_TAG 
 {	 
 CI_DEV_LP_RRC = 0 , /**< RRC */	 
 CI_DEV_LP_RRLP , /**< Radio resource location protocol */	 
 CI_DEV_LP_RRC_SIB15 , /**< RRC SIB15 */	 
 CI_DEV_LP_SS_AGPS_ASSIST_REQ , /**< Supplementary service AGPS assist request */	 
 CI_DEV_LP_LPP , /**< LPP container */	 
 CI_DEV_LP_LCS , /**< LCS container */	 
 CI_DEV_LP_RRC_UL_EXT , /**<RRC with uplink extensions support , added by lalon for CQ00094785 begin */	 
 CI_DEV_LP_NUM_OF_BEARER_TYPE	 
 } _CiDevLpBearerType;

typedef UINT8 CiDevLpBearerType ;
//ICAT EXPORTED ENUM 
 typedef enum CiDEVLPSESSIONTYPE_TAG 
 {	 
 CI_DEV_LP_NO_EMERGENCY = 0x0 , /**< Not an emergency call */	 
 CI_DEV_LP_EMERGENCY /**< An emergency call */	 
 } _CiDevLpSessionType;

typedef UINT8 CiDevLpSessionType ;
//ICAT EXPORTED ENUM 
 typedef enum CiDevNetworkType_Tag 
 {	 
 CI_DEV_NETWORK_TYPE_GERAN = 0x0 ,	 
 CI_DEV_NETWORK_TYPE_UTRAN ,	 
 CI_DEV_NETWORK_TYPE_EUTRAN ,	 
	 
 CI_DEV_NUM_NETWORK_TYPES	 
 } _CiDevNetworkType;

typedef UINT8 CiDevNetworkType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpNwdlMsgInd_struct {	 
 CiDevLpBearerType BearerType ; /**< Bearer type information \sa CiDevLpBearerType */	 
 UINT8 msg_data [ 1500 ] ; /**< Encoded RRLP / RRC data */	 
 UINT32 msg_size ; /**< Size of data , include all fragments */	 
 CiDevLpSessionType sessionType ; /**< Session type information \sa CiDevLpSessionType */	 
 CiDevLpRRCState RrcState ; /**< RRC state \sa CiDevLpRRCState */	 
 UINT8 count ; /**< Ordinal number of the message / fragment */	 
 UINT8 additional_info_len ; /**< Length of the additional information. If length is zero , than the additional information is not present.*/	 
 UINT8 additional_info [ 4 ] ; /**< Contains the value of the additional information element. Used for Routing Identifier ( 24.171000 ) */	 
 } CiDevPrimLpNwdlMsgInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpNwulMsgReq_struct {	 
 UINT8 msg_data [ 480 ] ; /**< OTA message */	 
 UINT32 msg_data_len ; /**< Size of data , include all fragments */	 
 UINT8 count ; /**< Ordinal number of the message / fragment */	 
 CiDevLpBearerType bearer_type ; /**< Radio bearer type \sa CiDevLpBearerType */	 
 CiBoolean isFinalResponse ; /**< Indication that this message is the last message in the AGPS session \sa CCI API Ref Manual */	 
 UINT8 additional_info_len ; /**< Length of the additional information. If length is zero , than the additional information is not present.*/	 
 UINT8 additional_info [ 4 ] ; /**< Contains the value of the additional information element. Used for Routing Identifier ( 24.171000 ) */	 
 } CiDevPrimLpNwulMsgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpNwulMsgCnf_struct {	 
 CiDevRc result ; /**< Result code \sa CiDevRc. */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimLpNwulMsgCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevNmrCellResult_struct 
 {	 
 UINT16 arfcn ;	 
 UINT8 bsic ;	 
 UINT8 rxLev ;	 
 } CiDevNmrCellResult;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcidInfoGsm_struct 
 {	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 UINT16 lac ;	 
 UINT16 ci ;	 
 UINT8 numOfCells ;	 
 CiDevNmrCellResult nmrCellResult [ 32 ] ; /**< Network measurement result */	 
 CiBoolean taPresent ;	 
 UINT8 timingAdv ;	 
 } CiDevEcidInfoGsm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCellResult_struct 
 {	 
 CiBoolean ucidPresent ;	 
 UINT32 ucid ; /**< Cell identiy */	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 UINT8 cpichRscp ; /**< FDD only */	 
 UINT8 cpichEcN0 ; /**< FDD only */	 
 CiBoolean pathLossPresent ;	 
 UINT16 pathLoss ;	 
 } CiDevCellResult;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCellResultList_struct 
 {	 
 UINT8 numOfCells ;	 
 CiDevCellResult cellResult [ 32 ] ;	 
 } CiDevCellResultList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUtraMeasResult_struct 
 {	 
 UINT16 uarfcnDl ;	 
 UINT16 rssi ;	 
 CiDevCellResultList cellResultList ;	 
 } CiDevUtraMeasResult;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUtraMeasResultList_struct 
 {	 
 UINT8 numUtraReportedFreqs ;	 
 CiDevUtraMeasResult utraMeasResult [ 3 ] ;	 
 } CiDevUtraMeasResultList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcidInfoUtra_struct 
 {	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 UINT32 ucid ;	 
 UINT16 uarfcnDl ;	 
 UINT16 uarfcnUl ;	 
 UINT16 psc ;	 
 CiBoolean MeasResultPresent ;	 
 CiDevUtraMeasResultList measResult ;	 
 } CiDevEcidInfoUtra;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCellGlobalIdEutra_struct 
 {	 
 CiBoolean mccPresent ;	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 UINT32 cellId ;	 
 } CiDevCellGlobalIdEutra;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcidMeasuredResultsElement_struct 
 {	 
 UINT16 physCellId ;	 
 CiBoolean cgiPresent ;	 
 CiDevCellGlobalIdEutra cellGlobalId ;	 
 UINT32 arfcnEutra ;	 
 CiBoolean sfnPresent ;	 
 UINT16 systemFrameNumber ;	 
 CiBoolean rsrpPresent ;	 
 UINT8 rsrp ;	 
 CiBoolean rsrqPresent ;	 
 UINT8 rsrq ;	 
 CiBoolean rxTxTimeDiffPresent ;	 
 UINT16 rxTxTimeDiff ; /**< UE RX-TX time difference measurement. Only valid for measurements of the primary cell */	 
 CiBoolean taPresent ;	 
 UINT16 timingAdvance ;	 
 CiBoolean tacPresent ;	 
 UINT16 trackingAreaCode ;	 
 } CiDevEcidMeasuredResultsElement;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcidSignalMeasInfo_struct 
 {	 
 CiBoolean primaryCellMeasuredResultsPresent ;	 
 CiDevEcidMeasuredResultsElement primaryCellMeasuredResults ; /**< Measurements for the primary cell. It ' s omitted when only primary cell measurements are reported ,	 
 in which case the measurements of the primary cell are reported in the measuredResultsList */	 
 UINT8 measuredResultsListLength ;	 
 CiDevEcidMeasuredResultsElement measuredResultsList [ 32 ] ;	 
 } CiDevEcidSignalMeasInfo;

//ICAT EXPORTED ENUM 
 typedef enum ECID_ERROR_CAUSES_ENUM 
 {	 
 CI_DEV_ECID_ERROR_CAUSE_UNDEFINED = 0x00 ,	 
 CI_DEV_ECID_ERROR_CAUSE_REQUESTED_MEASUREMENT_NOT_AVAILABLE ,	 
 CI_DEV_ECID_ERROR_CAUSE_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE ,	 
 CI_DEV_ECID_ERROR_CAUSE_RESERVED = 0xFF	 
 } _EcidErrorCauses;

typedef UINT8 EcidErrorCauses ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcidError_struct 
 {	 
 EcidErrorCauses ecidErrorCauses ;	 
 CiBoolean rsrpMeasurementNotPossible ; /**< Only for ERROR_CAUSE_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE */	 
 CiBoolean rsrqMeasurementNotPossible ; /**< Only for ERROR_CAUSE_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE */	 
 CiBoolean ueRxTxMeasurementNotPossible ; /**< Only for ERROR_CAUSE_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE */	 
 } CiDevEcidError;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcidInfoEutra_struct 
 {	 
 CiBoolean ecidSignalMeasInfoPresent ;	 
 CiDevEcidSignalMeasInfo ecidSignalMeasInfo ;	 
 CiBoolean ecidErrorPresent ;	 
 CiDevEcidError ecidError ;	 
 } CiDevEcidInfoEutra;

//ICAT EXPORTED UNION 
 typedef union CiDevEcidInfo_union 
 {	 
 CiDevEcidInfoGsm gsmInfo ;	 
 CiDevEcidInfoUtra utraInfo ;	 
 CiDevEcidInfoEutra eutraInfo ;	 
 } CiDevEcidInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpEcidMeasReq_struct 
 {	 
 UINT8 ecidMeasRequested ; /**< bit 0 : rsrpReq ; bit1: rsrqReq ; bit2: ueRxTxTimeDiffReq ; bit3-bit7: reserved. */	 
 } CiDevPrimLpEcidMeasReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpEcidMeasCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc. */	 
 CiDevNetworkType networkType ; /**< EUTRAN , UTRAN , or GERAN */	 
 CiDevEcidInfo info ;	 
 } CiDevPrimLpEcidMeasCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcgi_struct 
 {	 
 CiDevLtePlmnIdentity plmnIdentity ;	 
 UINT32 cellIdentity ; /* 0 to 268435455 */	 
 } CiDevEcgi;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrsInfo_struct 
 {	 
 UINT8 prsBandwidth ; /**< Specified in number of resource blocks. Value range: 6 , 15 , 25 , 50 , 75 , 100 */	 
 UINT16 prsConfigIndex ; /**< Value range: 0 - 4095 */	 
 UINT8 numDLFrames ; /**< The number of consecutive DL subframes. Value range: 1 , 2 , 4 , 6 */	 
 CiBoolean prsMutingInfoR9Present ;	 
 UINT8 prsMutingInfoR9LenInBit ; /**< PRS muting sequence length in bits. Value range: 2 , 4 , 8 , 16 */	 
 UINT16 prsMutingInfoR9 ; /**< PRS muting sequence */	 
 } CiDevPrsInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaReferenceCellInfo_struct 
 {	 
 UINT16 physCellId ; /**< Physical cell identity of the assistance data reference cell. Value range: 0 -503 */	 
 CiBoolean cgiPresent ;	 
 CiDevEcgi cellGlobalId ; /**< ECGI of the assistance data reference cell. */	 
 CiBoolean earfcnRefPresent ; /**< TRUE if not same as primary cell , otherwise FALSE. */	 
 UINT32 earfcnRef ; /**< EARFCN of the assistance data reference cell. */	 
 CiBoolean antennaPortConfigPresent ; /**< TRUE if not same as primary cell , otherwise FALSE. */	 
 UINT8 antennaPortConfig ; /**< The number of antenna ports for cell specific reference signals ( CRS ) . 0 : 1 or 2 port ( s ) ; 1 : 4 ports */	 
 UINT8 cpLength ; /**< Cyclic prefix length of PRS if prsInfo is present , otherwise of CRS. 0 : normal ; 1 : extended */	 
 CiBoolean prsInfoPresent ;	 
 CiDevPrsInfo prsInfo ; /**< PRS configuration of the assistance data reference cell. */	 
 } CiDevOtdoaReferenceCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaNeighbouCellInfoElement_struct 
 {	 
 UINT16 physCellId ; /**< Physical cell identity of the neighbour cell. Value range: 0 -503 */	 
 CiBoolean cgiPresent ;	 
 CiDevEcgi cellGlobalId ; /**< ECGI of the neighbour cell. */	 
 CiBoolean earfcnRefPresent ; /**< TRUE if not same as assistance data reference cell , otherwise FALSE. */	 
 UINT32 earfcnNbr ; /**< EARFCN of the neighbour cell. */	 
 CiBoolean cpLengthPresent ; /**< TRUE if not same as assistance data reference cell , otherwise FALSE. */	 
 UINT8 cpLength ; /**< Cyclic prefix length of PRS if prsInfo is present , otherwise of CRS. 0 : normal ; 1 : extended */	 
 CiBoolean prsInfoPresent ; /**< TRUE if not same as assistance data reference cell , otherwise FALSE. */	 
 CiDevPrsInfo prsInfo ; /**< PRS configuration */	 
 CiBoolean antennaPortConfigPresent ; /**< TRUE if not same as assistance data reference cell , otherwise FALSE. */	 
 UINT8 antennaPortConfig ; /**< The number of antenna ports for cell specific reference signals ( CRS ) . 0 : 1 or 2 port ( s ) ; 1 : 4 ports */	 
 CiBoolean slotNumberOffsetPresent ; /**< TRUE if not same as assistance data reference cell , otherwise FALSE. */	 
 UINT8 slotNumberOffset ; /**< Slot number offset at the transmitter between this cell and the assistance data reference cell. Value range: 0 -19 */	 
 CiBoolean prsSubframeOffsetPresent ;	 
 UINT16 prsSubframeOffset ; /**< Value range: 0 -1279 */	 
 UINT16 expectedRSTD ; /**< Value range: 0 -16383 */	 
 UINT16 expectedRSTDUncertainty ; /**< Value range: 0 -1023 */	 
 } CiDevOtdoaNeighbouCellInfoElement;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaNeighbourFreqInfo_struct 
 {	 
 UINT8 otdoaNeighbouCellInfoListLength ;	 
 CiDevOtdoaNeighbouCellInfoElement otdoaNeighbouCellInfoList [ 24 ] ;	 
 } CiDevOtdoaNeighbourFreqInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaNeighbourCellInfoList_struct 
 {	 
 UINT8 otdoaNeighbourFreqInfoNum ;	 
 // CiDevOtdoaNeighbourFreqInfo otdoaNeighbourFreqInfo [ CI_DEV_MAX_NUM_OTDOA_FREQ_LAYERS ] ;	 
 UINT8 otdoaNeighbourFreqCellNum [ 3 ] ; // Each element indicates how many cells belong to each frequency layer	 
 UINT8 otdoaNeighbouCellInfoListLength ;	 
 CiDevOtdoaNeighbouCellInfoElement otdoaNeighbouCellInfoList [ 24 ] ; // Totally a maximum of 24 cells	 
 } CiDevOtdoaNeighbourCellInfoList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaAssistanceData_struct 
 {	 
 CiBoolean otdoaReferenceCellInfoPresent ;	 
 CiDevOtdoaReferenceCellInfo otdoaReferenceCellInfo ;	 
 CiBoolean otdoaNeighbourCellInfoListPresent ;	 
 CiDevOtdoaNeighbourCellInfoList otdoaNeighbourCellInfoList ;	 
 } CiDevOtdoaAssistanceData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpOtdoaMeasReq_struct 
 {	 
 CiDevOtdoaAssistanceData otdoaAssistanceData ;	 
 } CiDevPrimLpOtdoaMeasReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpOtdoaMeasCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc. */	 
 } CiDevPrimLpOtdoaMeasCnf;

typedef CiEmptyPrim CiDevPrimLpOtdoaMeasAbortReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpOtdoaMeasAbortCnf_struct 
 {	 
 CiDevRc rc ;	 
 } CiDevPrimLpOtdoaMeasAbortCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaMeasQuality_struct 
 {	 
 UINT8 errorResolution ; /**< Resolution R. ' 0 ' : 5 meters ; ' 1 ' : 10 meters ; ' 10 ' : 20 meters ; ' 11 ' : 30 meters */	 
 UINT8 errorValue ; /**< Best estimate of the uncertainty of measurement.	 
 ' 0 ' : 0 - ( R*1-1 ) meters ;	 
 ' 1 ' : R*1 - ( R*2-1 ) meters ;	 
 ' 10 ' : R*2 - ( R*3-1 ) meters ;	 
 ...	 
 ' 11111 ' : R*31 meters or more */	 
 CiBoolean errorNumSamplesPresent ;	 
 UINT8 errorNumSamples ; /**< Measurements sample size.	 
 ' 0 ' : Not the baseline metric ( default value ) ;	 
 ' 1 ' : 5 -9 ;	 
 ' 10 ' : 10 -14 ;	 
 ' 11 ' : 15 -24 ;	 
 ' 100 ' : 25 -34 ;	 
 ' 101 ' : 53 -44 ;	 
 ' 110 ' : 45 -54 ;	 
 ' 111 ' : 55 or more */	 
 } CiDevOtdoaMeasQuality;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaNeighbourMeasurementElement_struct 
 {	 
 UINT16 physCellIdNeighbour ; /**< Physical cell identity of the neighbour cell. Value range: 0 -503 */	 
 CiBoolean cgiNeighbourPresent ;	 
 CiDevEcgi cellGlobalIdNeighbour ; /**< ECGI of the neighbour cell. */	 
 CiBoolean earfcnNeighbourPresent ; /**< TRUE if not same as RSTD reference cell , otherwise FALSE. */	 
 UINT32 earfcnNeighbour ; /**< EARFCN of the neighbour cell. */	 
 UINT16 rstd ; /**< Relative timing difference between this eighbour cell and the RSTD reference cell. Value range: 0 -12711 */	 
 CiDevOtdoaMeasQuality rstdQuality ; /**< Best estimate of the quality of the measured rstd. */	 
 } CiDevOtdoaNeighbourMeasurementElement;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaNeighbourMeasurementList_struct 
 {	 
 UINT8 otdoaNeighbourMeasurementListLength ;	 
 CiDevOtdoaNeighbourMeasurementElement otdoaNeighbourMeasurementList [ 24 ] ;	 
 } CiDevOtdoaNeighbourMeasurementList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaSignalMeasInfo_struct 
 {	 
 UINT16 systemFrameNumber ; /**< SFN of the RSTD reference cell. */	 
 UINT16 physCellIdRef ; /**< Physical cell identity of the RSTD reference cell. Value range: 0 -503 */	 
 CiBoolean cgiRefPresent ;	 
 CiDevEcgi cellGlobalIdRef ; /**< ECGI of the RSTD reference cell. */	 
 CiBoolean earfcnRefPresent ; /**< TRUE if not same as assistance data reference cell , otherwise FALSE. */	 
 UINT32 earfcnRef ; /**< EARFCN of the RSTD reference cell. */	 
 CiBoolean referenceQualityPresent ;	 
 CiDevOtdoaMeasQuality referenceQuality ; /**< Best estimate of the quality of TOA measurement from the RSTD reference cell. */	 
 CiDevOtdoaNeighbourMeasurementList neighbourMeasurementList ;	 
 } CiDevOtdoaSignalMeasInfo;

//ICAT EXPORTED ENUM 
 typedef enum OTDOA_ERROR_CAUSES_ENUM 
 {	 
 CI_DEV_OTDOA_ERROR_CAUSE_UNDEFINED = 0x00 ,	 
 CI_DEV_OTDOA_ERROR_CAUSE_ASSISTANCE_DATA_MISSING ,	 
 CI_DEV_OTDOA_ERROR_CAUSE_UNABLE_TO_MEASURE_REFERENCE_CELL ,	 
 CI_DEV_OTDOA_ERROR_CAUSE_UNABLE_TO_MEASURE_ANY_NEIGHBOUR_CELL ,	 
 CI_DEV_OTDOA_ERROR_CAUSE_ATTEMPTED_BUT_UNABLE_TO_MEASURE_SOME_NEIGHBOUR_CELLS ,	 
 CI_DEV_OTDOA_ERROR_CAUSE_RESERVED = 0xFF	 
 } _OtdoaErrorCauses;

typedef UINT8 OtdoaErrorCauses ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaError_struct 
 {	 
 OtdoaErrorCauses otdoaErrorCauses ;	 
 } CiDevOtdoaError;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaInfoEutra_struct 
 {	 
 CiBoolean otdoaSignalMeasInfoPresent ;	 
 CiDevOtdoaSignalMeasInfo otdoaSignalMeasInfo ;	 
 CiBoolean otdoaErrorPresent ;	 
 CiDevOtdoaError otdoaError ;	 
 } CiDevOtdoaInfoEutra;

//ICAT EXPORTED UNION 
 typedef union CiDevOtdoaInfo_union 
 {	 
 // CiDevOtdoaInfoUtra utraInfo ; // TBD	 
 CiDevOtdoaInfoEutra eutraInfo ;	 
 } CiDevOtdoaInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpOtdoaMeasInd_struct 
 {	 
 CiDevNetworkType networkType ; /**< EUTRAN , UTRAN , or GERAN */	 
 CiDevOtdoaInfo info ;	 
 } CiDevPrimLpOtdoaMeasInd;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LOCATION_COORDINATE_TYPE_ENUM 
 {	 
 CiDevLocCoordType_EllipsoidPoint = 0x00 ,	 
 CiDevLocCoordType_EllipsoidPointWithAltitude ,	 
 CiDevLocCoordType_EllipsoidPointWithUncertaintyCircle ,	 
 CiDevLocCoordType_EllipsoidPointWithUncertaintyEllipse ,	 
 CiDevLocCoordType_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid ,	 
 CiDevLocCoordType_EllipsoidArc ,	 
 CiDevLocCoordType_Polygon ,	 
 CiDevLocCoordType_Reserved = 0xFF	 
 } _CiDevLocationCoordinateType;

typedef UINT8 CiDevLocationCoordinateType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevLocationInfo_struct 
 {	 
 CiDevLocationCoordinateType locationCoordinateType ;	 
 UINT8 locationCoordinateLength ;	 
 UINT8 locationCoordinate [ 20 ] ;	 
 CiBoolean horizontalVelocityPresent ;	 
 UINT8 horizontalVelocityLength ;	 
 UINT8 horizontalVelocity [ 4 ] ;	 
 CiBoolean gnssTODMsecPresent ;	 
 UINT8 gnssTODMsecLength ;	 
 UINT8 gnssTODMsec [ 4 ] ;	 
 } CiDevLocationInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimRetrieveLocationInd_struct 
 {	 
 UINT16 seqNum ; /*< sequence number */	 
 } CiDevPrimRetrieveLocationInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimRetrieveLocationRsp_struct {	 
 UINT16 seqNum ; /*< sequence number */	 
 CiBoolean locationPresent ;	 
 CiDevLocationInfo location ;	 
 } CiDevPrimRetrieveLocationRsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetIgnitionStateReq_struct {	 
 CiBoolean ignitionOn ; /**< TRUE - ignition is on . FALSE otherwise \sa CCI API Ref Manual */	 
 CiBoolean updateSlowFratTimer ; /**< TRUE - enables update of slowFratTimer . FALSE otherwise. \sa CCI API Ref Manual */	 
 UINT16 slowFratTimer ; /**< SLOW FRAT Timer defines the periodicity of the HPPLMN searches when the SLOW FRAT trigger has been received \sa CCI API Ref Manual */	 
 CiBoolean updateFastFratTimer ; /**< TRUE - enables update of fastFratTimer. FALSE otherwise. \sa CCI API Ref Manual */	 
 UINT16 fastFratTimer ; /**< FAST FRAT Timer defines the periodicity of the HPPLMN searches when the FAST FRAT trigger has been received \sa CCI API Ref Manual */	 
 } CiDevPrimSetIgnitionStateReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetIgnitionStateCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetIgnitionStateCnf;

typedef CiEmptyPrim CiDevPrimGetIgnitionStateReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetIgnitionStateCnf_struct {	 
 CiDevRc rc ;	 
 CiBoolean ignitionOn ; /**< TRUE - ignition is on . FALSE otherwise \sa CCI API Ref Manual */	 
 UINT16 slowFratTimer ; /**< SLOW FRAT Timer defines the periodicity of the HPPLMN searches when the SLOW FRAT trigger has been received \sa CCI API Ref Manual */	 
 UINT16 fastFratTimer ; /**< FAST FRAT Timer defines the periodicity of the HPPLMN searches when the FAST FRAT trigger has been received \sa CCI API Ref Manual */	 
 } CiDevPrimGetIgnitionStateCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAreaInfoGsm_struct 
 {	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 UINT16 lac ;	 
 UINT16 ci ;	 
 } CiDevAreaInfoGsm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAreaInfoUtra_struct 
 {	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 UINT16 lac ;	 
 UINT32 ucid ;	 
 } CiDevAreaInfoUtra;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAreaInfoEutra_struct 
 {	 
 UINT16 arfcnEutra ;	 
 UINT16 physCellId ;	 
 CiBoolean cgiPresent ;	 
 CiDevCellGlobalIdEutra cellGlobalId ;	 
 } CiDevAreaInfoEutra;

//ICAT EXPORTED UNION 
 typedef union CiDevAreaInfo_union {	 
 CiDevAreaInfoGsm gsmInfo ;	 
 CiDevAreaInfoUtra utraInfo ;	 
 CiDevAreaInfoEutra eutraInfo ;	 
 } CiDevAreaInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLpUeAreaInfoIndReq_struct {	 
 CiBoolean enableUeAreaInfoInd ;	 
 } CiDevPrimSetLpUeAreaInfoIndReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLpUeAreaInfoIndCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc. */	 
 } CiDevPrimSetLpUeAreaInfoIndCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpUeAreaInfoInd_struct {	 
 CiDevNetworkType networkType ;	 
 CiDevAreaInfo info ;	 
 } CiDevPrimLpUeAreaInfoInd;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_LP_RRC_STATE_IND " > */ 
 typedef struct CiDevPrimLpRrcStateInd_struct {	 
 CiDevLpBearerType bearer_type ; /**< Radio bearer type \sa CiDevLpBearerType */	 
 CiDevLpRRCState rrc_state ; /**< Current RRC state \sa CiDevLpRRCState */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimLpRrcStateInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpMeasTerminateInd_struct {	 
 CiDevLpBearerType bearer_type ; /**< Radio bearer type \sa CiDevLpBearerType */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 } CiDevPrimLpMeasTerminateInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpResetStoreUePosInd_struct {	 
 CiDevLpBearerType bearer_type ; /**< Radio bearer type \sa CiDevLpBearerType */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 } CiDevPrimLpResetStoreUePosInd;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_DO_SELF_TEST_REQ " > */ 
 typedef struct CiDevPrimDoSelfTestReq_struct {	 
	 
 UINT32 appVersion ; /* Not in use */	 
	 
 } CiDevPrimDoSelfTestReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_DO_SELF_TEST_CNF " > */ 
 typedef struct CiDevPrimDoSelfTestCnf_struct {	 
	 
 CiDevRc result ; /* Result code \sa CiDevRc */	 
 CiDevSelfTestResult testResult ; /* Test result \sa CiDevSelfTestResult */	 
	 
 } CiDevPrimDoSelfTestCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_DO_SELF_TEST_IND " > */ 
 typedef struct CiCustPrimPerformSelfTestInd_struct {	 
	 
 CiDevSelfTestResult testResult ; /* Test result \sa CiDevSelfTestResult */	 
	 
 } CiDevPrimDoSelfTestInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetRfsReq_struct {	 
	 
 CiDevRfsLevel level ; /**< Not in use */	 
	 
 } CiDevPrimSetRfsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetRfsCnf_struct {	 
	 
 CiDevRc result ; /**< Result code \sa CiDevRc. */	 
	 
 } CiDevPrimSetRfsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetRfsReq_struct {	 
	 
 CiDevRfsLevel level ; /**< Not in use */	 
	 
 } CiDevPrimGetRfsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetRfsCnf_struct {	 
	 
 CiDevRc result ; /**< Result code \sa CiDevRc. */	 
	 
 } CiDevPrimGetRfsCnf;

typedef CiEmptyPrim CiDevPrimCommAssertReq ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVNWMODESET_TAG {	 
 CI_DEV_NW_GSM_MODE = 0 , /**< GSM */	 
 CI_DEV_NW_UMTS_MODE , /**< UMTS */	 
	 
 CI_DEV_NW_DUAL_GSM_UMTS_MODE , /**< GSM_UMTS , auto */	 
 CI_DEV_NW_DUAL_GSM_UMTS_MODE_GSM , /**< GSM_UMTS , GSM preferred */	 
 CI_DEV_NW_DUAL_GSM_UMTS_MODE_UMTS , /**< GSM_UMTS , UMTS preferred */	 
	 
 CI_DEV_NW_LTE_MODE , /**< LTE */	 
	 
 CI_DEV_NW_DUAL_GSM_LTE_MODE , /**< GSM_LTE , auto , single link */	 
 CI_DEV_NW_DUAL_GSM_LTE_MODE_GSM , /**< GSM_LTE , GSM preferred , single link */	 
 CI_DEV_NW_DUAL_GSM_LTE_MODE_LTE , /**< GSM_LTE , LTE preferred , single link */	 
	 
 CI_DEV_NW_DUAL_UMTS_LTE_MODE , /**< UMTS_LTE , auto , single link */	 
 CI_DEV_NW_DUAL_UMTS_LTE_MODE_UMTS , /**< UMTS_LTE , UMTS preferred , single link */	 
 CI_DEV_NW_DUAL_UMTS_LTE_MODE_LTE , /**< UMTS_LTE , LTE preferred , single link */	 
	 
 CI_DEV_NW_TRIP_MODE , /**< GSM_UMTS_LTE , auto , single link */	 
 CI_DEV_NW_TRIP_MODE_GSM , /**< GSM_UMTS_LTE , GSM preferred , single link */	 
 CI_DEV_NW_TRIP_MODE_UMTS , /**< GSM_UMTS_LTE , UMTS preferred , single link */	 
 CI_DEV_NW_TRIP_MODE_LTE , /**< GSM_UMTS_LTE , LTE preferred , single link */	 
	 
 CI_DEV_NW_GSM_LTE_MODE_DUALLINK , /**< GSM_LTE , dual link */	 
 CI_DEV_NW_UMTS_LTE_MODE_DUALLINK , /**< UMTS_LTE , dual link */	 
 CI_DEV_NW_TRIP_MODE_DUALLINK , /**< GSM_UMTS_LTE , dual link */	 
	 
 CI_DEV_NW_MODE_NOT_CHANGE = 0xF0 ,	 
	 
 CI_DEV_NUM_NW_MODES_SET	 
	 
 } _CiDevNwModeSet;

typedef UINT8 CiDevNwModeSet ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVNWMODES_TAG {	 
 CI_DEV_NW_GSM = 0 , /**< GSM */	 
 CI_DEV_NW_UMTS , /**< UMTS */	 
 CI_DEV_NW_GSM_UMTS , /**< GSM_UMTS */	 
 CI_DEV_NW_LTE , /**< LTE */	 
 CI_DEV_NW_GSM_LTE , /**< GSM_LTE */	 
 CI_DEV_NW_UMTS_LTE , /**< UMTS_LTE */	 
 CI_DEV_NW_GSM_UMTS_LTE , /**< GSM_UMTS_LTE */	 
	 
 CI_DEV_NUM_NW_MODES	 
	 
 } _CiDevNetworkMode;

typedef UINT8 CiDevNetworkMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVGSMBANDMODES_TAG {	 
 CI_DEV_PGSM_900 = 0 , /**< Standard or primary GSM 900 band */	 
 CI_DEV_DCS_GSM_1800 , /**< DCS 1800 band */	 
 CI_DEV_PCS_GSM_1900 , /**< PCS 1900 band */	 
 CI_DEV_EGSM_900 , /**< Extended GSM 900 band */	 
 CI_DEV_GSM_450 , /**< GSM 450 band */	 
 CI_DEV_GSM_480 , /**< GSM 480 band */	 
 CI_DEV_GSM_850 , /**< GSM 850 band */	 
	 
 CI_DEV_NUM_GSM_BAND	 
 } _CiDevGSMBandMode;

typedef UINT8 CiDevGSMBandMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVUMTSBANDMODES_TAG {	 
 CI_DEV_UMTS_BAND_1 = 0 , /**< UMTS operating band 1 */	 
 CI_DEV_UMTS_BAND_2 , /**< UMTS operating band 2 */	 
 CI_DEV_UMTS_BAND_3 , /**< UMTS operating band 3 */	 
 CI_DEV_UMTS_BAND_4 , /**< UMTS operating band 4 */	 
 CI_DEV_UMTS_BAND_5 , /**< UMTS operating band 5 */	 
 CI_DEV_UMTS_BAND_6 , /**< UMTS operating band 6 */	 
 CI_DEV_UMTS_BAND_7 , /**< UMTS operating band 7 */	 
 CI_DEV_UMTS_BAND_8 , /**< UMTS operating band 8 */	 
 CI_DEV_UMTS_BAND_9 , /**< UMTS operating band 9 */	 
	 
 CI_DEV_UMTS_BAND_10 , /**< UMTS operating band 10 */	 
 CI_DEV_UMTS_BAND_11 , /**< UMTS operating band 11 */	 
 CI_DEV_UMTS_BAND_12 , /**< UMTS operating band 12 */	 
 CI_DEV_UMTS_BAND_13 , /**< UMTS operating band 13 */	 
 CI_DEV_UMTS_BAND_14 , /**< UMTS operating band 14 */	 
 CI_DEV_UMTS_BAND_15 , /**< UMTS operating band 15 */	 
 CI_DEV_UMTS_BAND_16 , /**< UMTS operating band 16 */	 
 CI_DEV_UMTS_BAND_17 , /**< UMTS operating band 17 */	 
 CI_DEV_UMTS_BAND_18 , /**< UMTS operating band 18 */	 
 CI_DEV_UMTS_BAND_19 , /**< UMTS operating band 19 */	 
	 
 CI_DEV_NUM_UMTS_BAND	 
	 
 } _CiDevUMTSBandMode;

typedef UINT8 CiDevUMTSBandMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVEUTRANLOWBANDMODES_TAG {	 
 CI_DEV_EUTRAN_BAND_1 = 0 , /**< E-UTRAN operating band 1 */	 
 CI_DEV_EUTRAN_BAND_2 , /**< E-UTRAN operating band 2 */	 
 CI_DEV_EUTRAN_BAND_3 , /**< E-UTRAN operating band 3 */	 
 CI_DEV_EUTRAN_BAND_4 , /**< E-UTRAN operating band 4 */	 
 CI_DEV_EUTRAN_BAND_5 , /**< E-UTRAN operating band 5 */	 
 CI_DEV_EUTRAN_BAND_6 , /**< E-UTRAN operating band 6 */	 
 CI_DEV_EUTRAN_BAND_7 , /**< E-UTRAN operating band 7 */	 
 CI_DEV_EUTRAN_BAND_8 , /**< E-UTRAN operating band 8 */	 
 CI_DEV_EUTRAN_BAND_9 , /**< E-UTRAN operating band 10 */	 
 CI_DEV_EUTRAN_BAND_10 , /**< E-UTRAN operating band 11 */	 
 CI_DEV_EUTRAN_BAND_11 , /**< E-UTRAN operating band 12 */	 
 CI_DEV_EUTRAN_BAND_12 , /**< E-UTRAN operating band 13 */	 
 CI_DEV_EUTRAN_BAND_13 , /**< E-UTRAN operating band 14 */	 
 CI_DEV_EUTRAN_BAND_14 , /**< E-UTRAN operating band 15 */	 
 CI_DEV_EUTRAN_BAND_15_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_16_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_17 , /**< E-UTRAN operating band 17 */	 
 CI_DEV_EUTRAN_BAND_18 , /**< E-UTRAN operating band 18 */	 
 CI_DEV_EUTRAN_BAND_19 , /**< E-UTRAN operating band 19 */	 
 CI_DEV_EUTRAN_BAND_20 , /**< E-UTRAN operating band 20 */	 
 CI_DEV_EUTRAN_BAND_21 , /**< E-UTRAN operating band 21 */	 
 CI_DEV_EUTRAN_BAND_22 , /**< E-UTRAN operating band 22 */	 
 CI_DEV_EUTRAN_BAND_23 , /**< E-UTRAN operating band 23 */	 
 CI_DEV_EUTRAN_BAND_24 , /**< E-UTRAN operating band 24 */	 
 CI_DEV_EUTRAN_BAND_25 , /**< E-UTRAN operating band 25 */	 
 CI_DEV_EUTRAN_BAND_26 , /**< E-UTRAN operating band 26 */	 
 CI_DEV_EUTRAN_BAND_27_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_28_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_29_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_30_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_31_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_32_NOT_USED ,	 
 CI_DEV_NUM_LOW_EUTRAN_BAND	 
 } _CiDevEUTRANLowBandMode;

typedef UINT8 CiDevEUTRANLowBandMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVEUTRANHIGHBANDMODES_TAG {	 
 CI_DEV_EUTRAN_BAND_33 = 0 , /**< E-UTRAN operating band 33 */	 
 CI_DEV_EUTRAN_BAND_34 , /**< E-UTRAN operating band 34 */	 
 CI_DEV_EUTRAN_BAND_35 , /**< E-UTRAN operating band 35 */	 
 CI_DEV_EUTRAN_BAND_36 , /**< E-UTRAN operating band 36 */	 
 CI_DEV_EUTRAN_BAND_37 , /**< E-UTRAN operating band 37 */	 
 CI_DEV_EUTRAN_BAND_38 , /**< E-UTRAN operating band 38 */	 
 CI_DEV_EUTRAN_BAND_39 , /**< E-UTRAN operating band 39 */	 
 CI_DEV_EUTRAN_BAND_40 , /**< E-UTRAN operating band 40 */	 
 CI_DEV_EUTRAN_BAND_41 , /**< E-UTRAN operating band 41 */	 
 CI_DEV_EUTRAN_BAND_42 , /**< E-UTRAN operating band 42 */	 
 CI_DEV_EUTRAN_BAND_43 , /**< E-UTRAN operating band 43 */	 
 CI_DEV_NUM_HIGH_EUTRAN_BAND	 
 } _CiDevEUTRANHighBandMode;

typedef UINT8 CiDevEUTRANHighBandMode ;
typedef UINT8 CiDevSetBandRoamingConfig ;
typedef UINT8 CiDevSetBandSrvDomain ;
typedef UINT8 CiDevSetBandPriorityFlag ;
typedef UINT8 CiDevSetBandUsageType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetBandModeReq_struct {	 
 CiDevNetworkMode networkMode ;	 
 CiDevNetworkMode preferredMode ;	 
 CiBitRange GSMBandMode ;	 
 CiBitRange UMTSBandMode ;	 
 CiBitRange EUTRANBandModeH ; /**< Bit mask indicating the required E-UTRAN bands High part ( bands 33 - 43 ) . If bit is set the	 
 * band is supported. Bit definition is based on CIDEVEUTRANHIGHBANDMODES_TAG*/	 
 CiBitRange EUTRANBandModeL ; /**< Bit mask indicating the required E-UTRAN bands Low part ( bands 1 - 32 ) . If bit is set the	 
 * band is supported. Bit definition is based on CIDEVEUTRANLOWBANDMODES_TAG*/	 
 CiDevSetBandRoamingConfig roamingConfig ; /**< Roaming: 0 -not support , 1 -support , 2 -no change ( default ) */	 
 CiDevSetBandSrvDomain srvDomain ; /**< Service domain: 0 -CS only , 1 - PS only , 2 -CS and PS , 3 - ANY , 4 -no change ( default ) */	 
 CiDevSetBandPriorityFlag bandPriorityFlag ; /**0: default ; 1 : TD-LTE ; 2 :FDD-LTE*/	 
 CiBoolean isLteDualLink ; /**TRUE: dual Link ; FALSE: single Link*/	 
	 
 /*Added by Lilei for preferred band setting on 1152014 , begin*/	 
	 
 CiDevSetBandUsageType bandType ; /**< Band type: 0 -band capability ( default ) , 1 -preferred band , 2 -only registration band */	 
	 
 /*Added by Lilei for preferred band setting on 1152014 , end*/	 
 CiBitRange EUTRANBandModeExt ; /**< Bit mask indicating the required E-UTRAN bands Extended part ( bands 65 - 69 ) . */	 
 } CiDevPrimSetBandModeReq;

//ICAT EXPORTED ENUM 
 typedef enum CIDEVSETBANDCNFACT_TAG {	 
 CI_DEV_SET_BAND_CNF_NO_ACT = 0 ,	 
 CI_DEV_SET_BAND_CNF_NEED_SILENT_RESET	 
 } _CiDevSetBandCnfAct;

typedef UINT8 CiDevSetBandCnfAct ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetBandModeCnf_struct {	 
 CiDevRc result ; /**< Result code \sa CiDevRc */	 
 CiDevSetBandCnfAct apAct ;	 
 } CiDevPrimSetBandModeCnf;

typedef CiEmptyPrim CiDevPrimGetBandModeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetBandModeCnf_struct {	 
 CiDevRc result ;	 
 CiDevNetworkMode networkMode ;	 
 CiDevNetworkMode preferredMode ;	 
 CiBitRange GSMBandMode ;	 
 CiBitRange UMTSBandMode ;	 
 CiBitRange EUTRANBandModeH ; /**< Bit mask indicating the required E-UTRAN bands High part ( bands 33 - 43 ) . If bit is set the	 
 * band is supported. Bit definition is based on CIDEVEUTRANHIGHBANDMODES_TAG*/	 
 CiBitRange EUTRANBandModeL ; /**< Bit mask indicating the required E-UTRAN bands Low part ( bands 1 - 32 ) . If bit is set the	 
 * band is supported. Bit definition is based on CIDEVEUTRANLOWBANDMODES_TAG*/	 
 UINT8 roamingConfig ; /**< Roaming: 0 -not support , 1 -support */	 
 UINT8 srvDomain ; /**< Service domain: 0 -CS only , 1 - PS only , 2 -CS and PS , 3 - ANY*/	 
 UINT8 bandPriorityFlag ; /**0: default ; 1 : TD-LTE ; 2 :FDD-LTE*/	 
 /* Added by Lilei 20131009 , begin */	 
 CiBoolean isLteDualLink ; /**TRUE: dual Link ; FALSE: single Link*/	 
 /* Added by Lilei 20131009 , end */	 
 CiBitRange EUTRANBandModeExt ; /**< Bit mask indicating the required E-UTRAN bands Extended part ( bands 65 - 69 ) . */	 
 } CiDevPrimGetBandModeCnf;

typedef CiEmptyPrim CiDevPrimGetSupportedBandModeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSupportedBandModeCnf_struct {	 
 CiDevRc result ; /**< Result code \sa CiDevRc */	 
 CiBitRange bitsNetworkMode ; /**< Bit mask indicating the supported RAT modes. If bit is set the band is supported. Bit definition is based on CIDEVNWMODES_TAG \sa CCI API Ref Manual*/	 
 CiBitRange bitsGSMBandMode ; /**< Bit mask indicating the supported GSM bands. If bit is set the band is supported. Bit definition is based on CIDEVGSMBANDMODES_TAG \sa CCI API Ref Manual */	 
 CiBitRange bitsUMTSBandMode ; /**< Bit mask indicating the supportedUMTS bands. If bit is set the band is supported. Bit definition is based on CIDEVUMTSBANDMODES_TAG \sa CCI API Ref Manual */	 
 CiBitRange bitsEUTRANBandModeH ; /**< Bit mask indicating the required E-UTRAN bands High part ( bands 33 - 43 ) . If bit is set the	 
 * band is supported. Bit definition is based on CIDEVEUTRANHIGHBANDMODES_TAG*/	 
 CiBitRange bitsEUTRANBandModeL ; /**< Bit mask indicating the required E-UTRAN bands Low part ( bands 1 - 32 ) . If bit is set the	 
 * band is supported. Bit definition is based on CIDEVEUTRANLOWBANDMODES_TAG*/	 
 CiBitRange bitsEUTRANBandModeExt ; /**< Bit mask indicating the required E-UTRAN bands Extended part ( bands 65 - 69 ) . */	 
 } CiDevPrimGetSupportedBandModeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiImei_struct {	 
 UINT8 len ; /**< Length */	 
 CHAR val [ 16 ] ; /**< IMEI digits */	 
 } CiImei;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSvReq_struct {	 
 CiImei SVDigits ; /**< IMEI SV digits. \sa CiImei */	 
 } CiDevPrimSetSvReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSvCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetSvCnf;

typedef CiEmptyPrim CiDevPrimGetSvReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSvCnf_struct {	 
 CiImei SVDigits ; /**< IMEI SV dugits. \sa CiImei */	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimGetSvCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimApPowerNotifyReq_struct {	 
 UINT32 powerState ; /**< AP power state: 1 ~31 means suspend , bitmap: bit0 - NETWORK ;	 
 bit1 - SIM ;	 
 bit2 - SMS ;	 
 bit3 - CS CALL	 
 bit4 - PS DATA	 
 0 means resume all. \sa powerState */	 
 } CiDevPrimApPowerNotifyReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimApPowerNotifyCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 } CiDevPrimApPowerNotifyCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_TD_RX_TX_OPTION_TAG {	 
 CI_DEV_TD_TX_START = 0 ,	 
 CI_DEV_TD_RX_START ,	 
 CI_DEV_TD_TX_RX_STOP ,	 
	 
 CI_DEV_NUM_TD_TX_RX	 
 } _CiDevTdTxRxOption;

typedef UINT8 CiDevTdTxRxOption ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_RX_TX_OPTION_TAG {	 
 CI_DEV_GSM_TX_START = 0 ,	 
 CI_DEV_GSM_RX_START ,	 
 CI_DEV_GSM_TX_RX_START ,	 
 CI_DEV_GSM_TX_RX_STOP ,	 
	 
 CI_DEV_NUM_GSM_TX_RX	 
 } _CiDevGsmTxRxOption;

typedef UINT8 CiDevGsmTxRxOption ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_CONTROL_MODE_TAG {	 
 CI_DEV_GSM_CONTROL_READ = 0 ,	 
 CI_DEV_GSM_CONTROL_WRITE ,	 
 CI_DEV_GSM_CONTROL_LOOPBACK ,	 
	 
 CI_DEV_NUM_GSM_CONTROL	 
 } _CiDevGsmControlMode;

typedef UINT8 CiDevGsmControlMode ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetTdModeTxRxReq_struct {	 
 CiDevTdTxRxOption option ; /**< TD option. \sa CiDevTdTxRxOption */	 
 INT16 txRxGain ; /**< Tx or Rx gain */	 
 UINT16 freq ; /**< TD frequency */	 
 } CiDevPrimSetTdModeTxRxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetTdModeTxRxCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 } CiDevPrimSetTdModeTxRxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetTdModeLoopbackReq_struct {	 
 UINT32 regValue ; /**< The value to be written into RF register */	 
 } CiDevPrimSetTdModeLoopbackReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetTdModeLoopbackCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT32 regValue ; /**< The value to be read from RF register */	 
 } CiDevPrimSetTdModeLoopbackCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_WCDMA_RX_TX_OPTION_TAG {	 
 CI_DEV_WCDMA_TX_START = 0 ,	 
 CI_DEV_WCDMA_RX_START ,	 
 CI_DEV_WCDMA_TX_RX_STOP ,	 
	 
 CI_DEV_NUM_WCDMA_TX_RX	 
 } _CiDevWcdmaTxRxOption;

typedef UINT8 CiDevWcdmaTxRxOption ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetWcdmaModeTxRxReq_struct {	 
 CiDevWcdmaTxRxOption option ; /**< WCDMA option. \sa CiDevWcdmaTxRxOption */	 
 UINT16 DL_UARFCN ; /**< Downlink UARFCN*/	 
 UINT16 UL_UARFCN ; /**< Uplink UARFCN*/	 
 UINT8 PA_Mode ; /**< PA mode :2 ; range ( 0 , 1 , 2 ) */	 
 UINT16 APC_Dac ; /**< APC DAC :1600 ; range [ 0 , 2047 ] */	 
 UINT16 DCDC_Dac ; /**<DCDC DAC :Not used for LT02*/	 
 INT16 AFC_Dac ; /**< AFC DAC :18000*/	 
 } CiDevPrimSetWcdmaModeTxRxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetWcdmaModeTxRxCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 signed short acqRssi ; /**< The Rssi value to be returned in case of GSM RX mode*/	 
 } CiDevPrimSetWcdmaModeTxRxCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RX_TX_OPTION_TAG {	 
 CI_DEV_LTE_TX_START = 0 ,	 
 CI_DEV_LTE_RX_START ,	 
 CI_DEV_LTE_TX_RX_STOP ,	 
	 
 CI_DEV_NUM_LTE_TX_RX	 
 } _CiDevLteTxRxOption;

typedef UINT8 CiDevLteTxRxOption ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLteModeTxRxReq_struct {	 
 CiDevLteTxRxOption option ; /**< LTE option. \sa CiDevLteTxRxOption */	 
 INT16 txRxPower ; /**< Tx or Rx power. Range [ 0 , 2047 ] for TX*/	 
 UINT16 freq ; /**< LTE carrier frequency. Range [ 0 , 45589 ] */	 
 UINT8 bandwidth ; /**< LTE bandwidth. Range [ 0 , 5 ] */	 
 } CiDevPrimSetLteModeTxRxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLteModeTxRxCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
	 
 INT16 rssiPri ;	 
 INT16 rssiSec ;	 
	 
 } CiDevPrimSetLteModeTxRxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetGsmModeTxRxReq_struct {	 
 CiDevGsmTxRxOption option ; /**< TD option. \sa CiDevGsmTxRxOption */	 
 CiBitRange gsmBandMode ; /**< GSM band mode */	 
 UINT16 arfcn ; /**< Absolute Radio Frequency Channel Number */	 
 UINT32 afcDac ; /**< AFC DAC value*/	 
 UINT32 txRampScale ; /**< Tx ramp scale , only valid for Tx or Tx+Rx mode*/	 
 UINT32 rxGainCode ; /**< Rx gain code , only valid for Rx or Tx+Rx mode*/	 
 } CiDevPrimSetGsmModeTxRxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetGsmModeTxRxCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 signed short rssiDbmValue ; /**< The Rssi value to be returned in case of GSM RX mode*/	 
 } CiDevPrimSetGsmModeTxRxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetGsmControlInterfaceReq_struct {	 
 CiDevGsmControlMode mode ; /**< Operation mode. \sa CiDevGsmControlMode */	 
 UINT16 addrReg ; /**< Register address*/	 
 UINT16 regValue ; /**< The payload value to be written into RFIC in case of write or loopback mode*/	 
 } CiDevPrimSetGsmControlInterfaceReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetGsmControlInterfaceCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT16 addrReg ; /**< Register address*/	 
 UINT16 regValue ; /**< The payload value to be read from RFIC in case of read or loopback mode*/	 
 } CiDevPrimSetGsmControlInterfaceCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_HSPA_CONFIG_TAG {	 
 CI_DEV_HSDPA_OFF_HSUPA_OFF = 0 , /* set RRC release to R5 */	 
 CI_DEV_HSDPA_ON_HSUPA_OFF , /* set RRC release to R5 */	 
 CI_DEV_HSDPA_ON_HSUPA_ON , /* set RRC release to R7 */	 
 CI_DEV_HSDPA_ON_HSUPA_ON_DLDC , /* set RRC release to R9 , only used for TD-SCDMA */	 
 CI_DEV_HSPA_REL6 , /* set RRC release to R6 , only used for WCDMA */	 
	 
 CI_DEV_NUM_HSPA_CONFIG	 
 } _CiDevHspaConfig;

typedef UINT8 CiDevHspaConfig ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimEnableHsdpaReq_struct {	 
 CiDevHspaConfig hspaConfig ; /**< HSPA configurations \sa CiDevHspaConfig */	 
 UINT8 dlCategory ; /**< DL category , for WCDMA support 1 ~12 , default 10 for Rel7 ; support 1 ~15 except 12 on TD HSDPA , 16 , 23 , 35 on DLDC , default 15 */	 
 UINT8 ulCategory ; /**< UL category , for WCDMA support 1 ~6 , default 6 ; only support 6 on TD HSUPA , fix it if UPA is enabled */	 
 UINT8 cpcState ; /**< CPC state only used for WCDMA Rel7 , 0 :disabled , 1 :enabled , default enabled ; not supported on TD-SCDMA , hard coded with 0 or ingore it*/	 
	 
 UINT8 dpaCategoryExt ; /**< DPA category ext , for WCDMA Rel7 support 1 ~14 , default 14 for Rel7*/	 
 UINT8 edchCategoryExt ; /**< EDCH category ext , for WCDMA Rel7 only support 7 as default*/	 
	 
 UINT8 fdpchState ; /**< F-DPCH enabled or disabled on R6 / R7 for WCDMA , 0 :disabled , 1 :enabled , default enabled*/	 
 UINT8 eFdpchState ; /**< Enhanced F-DPCH enabled or disabled on R7 for WCDMA 0 :disabled , 1 :enabled , default enabled*/	 
	 
 /*Lilei , CQ00090354 , 20150410 , begin*/	 
 UINT8 eFachState ; /**< Enhanced FACH enabled or disabled on R7 for WCDMA. 0 :disabled , 1 :enabled , default enabled*/	 
 /*Lilei , CQ00090354 , 20150410 , end*/	 
 } CiDevPrimEnableHsdpaReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimEnableHsdpaCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 } CiDevPrimEnableHsdpaCnf;

typedef CiEmptyPrim CiDevPrimGetHsdpaStatusReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetHsdpaStatusCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
	 
 CiDevHspaConfig hspaConfig ; /**< HSPA configurations \sa CiDevHspaConfig */	 
 UINT8 dlCategory ; /**< DL category , for WCDMA support 1 ~12 , default 10 for Rel7 ; support 1 ~15 except 12 on TD HSDPA , 16 , 23 , 35 on DLDC , default 15 */	 
 UINT8 ulCategory ; /**< UL category , for WCDMA support 1 ~6 , default 6 ; only support 6 on TD HSUPA , fix it if UPA is enabled */	 
 UINT8 cpcState ; /**< CPC state only used for WCDMA Rel7 , 0 :disabled , 1 :enabled , default enabled ; not supported on TD-SCDMA , hard coded with 0 or ingore it*/	 
	 
 UINT8 dpaCategoryExt ; /**< DPA category ext , for WCDMA Rel7 support 1 ~14 , default 14 for Rel7*/	 
 UINT8 edchCategoryExt ; /**< EDCH category ext , for WCDMA Rel7 only support 7 as default*/	 
	 
 UINT8 fdpchState ; /**< F-DPCH enabled or disabled on R6 / R7 for WCDMA , 0 :disabled , 1 :enabled , default enabled*/	 
 UINT8 eFdpchState ; /**< Enhanced F-DPCH enabled or disabled on R7 for WCDMA 0 :disabled , 1 :enabled , default enabled*/	 
	 
 /*Lilei , CQ00090354 , 20150410 , begin*/	 
 UINT8 eFachState ; /**< Enhanced FACH enabled or disabled on R7 for WCDMA. 0 :disabled , 1 :enabled , default enabled*/	 
 /*Lilei , CQ00090354 , 20150410 , end*/	 
 } CiDevPrimGetHsdpaStatusCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_RF_TEMP_TYPE_TAG {	 
 CI_DEV_RF_TEMP_CELSIUS = 0 , /**< internal RF temp */	 
 CI_DEV_RF_TEMP_RAW_DATA , /**< internal RF temp */	 
	 
 /*Lilei , CQ00125096 , 20201013 , begin*/	 
 CI_DEV_RF_TEMP_CELSIUS_EXTERNAL , /**< external RF temp */	 
 CI_DEV_RF_TEMP_RAW_DATA_EXTERNAL , /**< external RF temp */	 
 /*Lilei , CQ00125096 , 20201013 , end*/	 
	 
 CI_DEV_NUM_RF_TEMP	 
 } _CiDevRfTempType;

typedef UINT8 CiDevRfTempType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimReadRfTemperatureReq_struct {	 
 CiDevRfTempType type ; /**< Read type. \sa CiDevRfTempType */	 
 } CiDevPrimReadRfTemperatureReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimReadRfTemperatureCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 INT32 tempData ; /**< Temperature data */	 
 } CiDevPrimReadRfTemperatureCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_NW_MONITOR_MODE_TAG {	 
 CI_DEV_NW_MONIOTR_NORMAL = 16 ,	 
 CI_DEV_NW_MONIOTR_DETECT = 96 ,	 
	 
 CI_DEV_NUM_RNW_MONIOTR	 
 } _CiDevNwMonitorMode;

typedef UINT8 CiDevNwMonitorMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_PROTOCOL_STATUS_TAG {	 
 CI_DEV_PROTOCOL_STATUS_IDLE = 0 ,	 
 CI_DEV_PROTOCOL_STATUS_CONNECT ,	 
	 
 CI_DEV_NUM_PROTOCOL_STATUS	 
 } _CiDevProtocolStatus;

typedef UINT8 CiDevProtocolStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_EVENT_OPER_TYPE_TAG {	 
 CI_DEV_EVENT_OPER_CS_VOICE = 0 ,	 
 CI_DEV_EVENT_OPER_CS_DATA ,	 
 CI_DEV_EVENT_OPER_PS ,	 
 CI_DEV_EVENT_OPER_SMS ,	 
	 
 CI_DEV_NUM_EVENT_OPER	 
 } _CiDevEventOperType;

typedef UINT8 CiDevEventOperType ;
typedef UINT32 CiDevEventId ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_SIGNALING_MSG_ID_TAG {	 
 CI_DEV_SIGNALING_BCH_MSG_IND = 12202 , /* only for TDD */	 
 CI_DEV_SIGNALING_BCCH_FACH_MSG_IND = 2020 , /* only for TDD */	 
 CI_DEV_SIGNALING_PCCH_PCH_MSG_IND = 2021 , /* only for TDD */	 
 CI_DEV_SIGNALING_UL_CCH_MSG_IND = 3005 , /* only for TDD */	 
 CI_DEV_SIGNALING_DL_CCH_MSG_IND = 3006 , /* only for TDD */	 
	 
 CI_DEV_SIGNALING_GSM_MSG_IND = 12155 , /* only for GSM */	 
	 
 CI_DEV_NUM_SIGNALING_MSG_D = 0xFFFF	 
 } _CiDevSignalingMsgId;

typedef UINT32 CiDevSignalingMsgId ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_BAND_TAG {	 
 CI_DEV_GSM_BAND_PGSM_900 = 0 ,	 
 CI_DEV_GSM_BAND_EGSM_900 ,	 
 CI_DEV_GSM_BAND_RGSM_900 ,	 
 CI_DEV_GSM_BAND_DCS_1800 ,	 
 CI_DEV_GSM_BAND_PCS_1900 ,	 
 CI_DEV_GSM_BAND_450 ,	 
 CI_DEV_GSM_BAND_480 ,	 
 CI_DEV_GSM_BAND_850 ,	 
 CI_DEV_GSM_BAND_750 ,	 
	 
 CI_DEV_NUM_BAND	 
 } _CiDevGsmBand;

typedef UINT8 CiDevGsmBand ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPlmnMcc_struct 
 {	 
 UINT8 mcc [ 3 ] ;	 
 } CiDevPlmnMcc;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPlmnMnc_struct 
 {	 
 UINT8 len ;	 
 UINT8 mnc [ 3 ] ;	 
 } CiDevPlmnMnc;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTsIscp_struct 
 {	 
 UINT8 timeSlot ; /**< TimeSlot ( 0 ..6 ) */	 
 UINT8 iscp ; /**< ISCP ( 0 ..91 ) , real value ( dbm ) =IE value -116 */	 
 } CiDevTsIscp;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTsIscpArray_struct 
 {	 
 UINT8 num ;	 
 CiDevTsIscp data [ 7 ] ;	 
 } CiDevTsIscpArray;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevDpchRscp_struct 
 {	 
 UINT8 timeSlot ; /**< TimeSlot ( 0 ..6 ) */	 
 UINT8 rscp ; /**< DPCH RSCP ( 0 ..91 ) , real value ( dbm ) =IE value -116 */	 
 } CiDevDpchRscp;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevDpchRscpArray_struct 
 {	 
 UINT8 num ;	 
 CiDevDpchRscp data [ 7 ] ;	 
 } CiDevDpchRscpArray;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTxPower_struct 
 {	 
 UINT8 timeSlot ; /**< TimeSlot ( 0 ..6 ) */	 
 UINT8 txPower ; /**< UE Transmitted Power ( 21 ..104 ) , 0xff means UE TxPower is not available.	 
 real value ( dbm ) =IE value -71 */	 
 } CiDevTxPower;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTxPowerArray_struct 
 {	 
 UINT8 num ;	 
 CiDevTxPower data [ 7 ] ;	 
 } CiDevTxPowerArray;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddNcellTsIscp_struct 
 {	 
 UINT8 tsNum ; /**< Timeslot number. ( 0 ..6 ) */	 
 UINT8 tsIscp ; /**< Timeslot ISCP. ( 0 ..91 ) */	 
 } CiDevTddNcellTsIscp;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddRrcDiagNcellTddPara_struct 
 {	 
 UINT8 cellParamId ; /**< Neighbor cell parameter ID. ( 0 ..127 ) */	 
 UINT16 uArfcn ; /**< Neighbor cell UARFCN. ( 0 ..16383 ) */	 
 UINT8 pccpchRscp ; /**< Neighbor cell PCCPCH RSCP. ( 0 ..91 ) */	 
	 
 UINT8 res1U8 ; /**< ( padding ) */	 
 UINT8 iscpNum ; /** ( 0 ..6 ) If it equals to 0 , nCellTsIscp does not xist. */	 
 CiDevTddNcellTsIscp nCellTsIscp [ 7 -1 ] ;	 
	 
 UINT32 res2U32 ; /**< ( padding ) */	 
 } CiDevTddRrcDiagNcellTddPara;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddRrcDiagNcellGsmPara_struct 
 {	 
 UINT16 arfcn ; /**< Neighbor cell ARFCN info. ( 0 ..1023 ) */	 
 CiDevGsmBand band ; /**< Neighbor cell current freq band. */	 
 UINT8 bsic ; /**< Neighbor cell BSIC. ( 0 ..63 ) */	 
 UINT8 rxlev ; /**< Neighbor cell GSM received signal level. */	 
 UINT8 res1U16 [ 3 ] ; /**< ( padding ) */	 
 } CiDevTddRrcDiagNcellGsmPara;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddNcellParamList_struct 
 {	 
 UINT8 numNcellTdd ; /**< If it equals 0 , the IE below will not exist */	 
 CiDevTddRrcDiagNcellTddPara nbCellInfoTdd [ 6 ] ;	 
	 
 UINT8 res1U8 ; /**< ( padding ) , always fill with 0xFE */	 
 UINT8 numNcellGsm ; /**< If it equals 0 , the IE below will not exist */	 
 CiDevTddRrcDiagNcellGsmPara nbCellInfoGsm [ 6 ] ;	 
 } CiDevTddNcellParamList;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_TDD_CHANNEL_CODE_TAG {	 
 CI_DEV_TDD_CC1_1 = 0 ,	 
 CI_DEV_TDD_CC2_1 ,	 
 CI_DEV_TDD_CC2_2 ,	 
 CI_DEV_TDD_CC4_1 ,	 
 CI_DEV_TDD_CC4_2 ,	 
 CI_DEV_TDD_CC4_3 ,	 
 CI_DEV_TDD_CC4_4 ,	 
 CI_DEV_TDD_CC8_1 ,	 
 CI_DEV_TDD_CC8_2 ,	 
 CI_DEV_TDD_CC8_3 ,	 
 CI_DEV_TDD_CC8_4 ,	 
 CI_DEV_TDD_CC8_5 ,	 
 CI_DEV_TDD_CC8_6 ,	 
 CI_DEV_TDD_CC8_7 ,	 
 CI_DEV_TDD_CC8_8 ,	 
 CI_DEV_TDD_CC16_1 ,	 
 CI_DEV_TDD_CC16_2 ,	 
 CI_DEV_TDD_CC16_3 ,	 
 CI_DEV_TDD_CC16_4 ,	 
 CI_DEV_TDD_CC16_5 ,	 
 CI_DEV_TDD_CC16_6 ,	 
 CI_DEV_TDD_CC16_7 ,	 
 CI_DEV_TDD_CC16_8 ,	 
 CI_DEV_TDD_CC16_9 ,	 
 CI_DEV_TDD_CC16_10 ,	 
 CI_DEV_TDD_CC16_11 ,	 
 CI_DEV_TDD_CC16_12 ,	 
 CI_DEV_TDD_CC16_13 ,	 
 CI_DEV_TDD_CC16_14 ,	 
 CI_DEV_TDD_CC16_15 ,	 
 CI_DEV_TDD_CC16_16 ,	 
	 
 CI_DEV_NUM_TDD_CC	 
 } _CiDevTddChannelCode;

typedef UINT8 CiDevTddChannelCode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_CODING_SCHEME_TAG {	 
 CI_DEV_GSM_CS_1 = 7 ,	 
 CI_DEV_GSM_CS_2 ,	 
 CI_DEV_GSM_CS_3 ,	 
 CI_DEV_GSM_CS_4 ,	 
	 
 CI_DEV_GSM_MCS_1 = 11 ,	 
 CI_DEV_GSM_MCS_2 ,	 
 CI_DEV_GSM_MCS_3 ,	 
 CI_DEV_GSM_MCS_4 ,	 
 CI_DEV_GSM_MCS_5 ,	 
 CI_DEV_GSM_MCS_6 ,	 
 CI_DEV_GSM_MCS_7 ,	 
 CI_DEV_GSM_MCS_8 ,	 
 CI_DEV_GSM_MCS_9 ,	 
	 
 CI_DEV_GSM_CS_INVALID = 0xFF ,	 
	 
 CI_DEV_NUM_GSM_CS	 
 } _CiDevGsmCodingScheme;

typedef UINT8 CiDevGsmCodingScheme ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddRrcDiagPhych_struct 
 {	 
 UINT8 phychId ; /**< PhyCH Id ( 0 ..47 ) */	 
 UINT8 phychDirection ; /**< PhyCH Direction , 0 :uplink ; 1 :downlink*/	 
 UINT8 timeSlot ; /**< Timeslot ( 0 ..6 ) */	 
	 
 CiDevTddChannelCode channelCode ; /**< Channel code */	 
 UINT16 res1U16 [ 2 ] ; /**< ( padding ) */	 
 } CiDevTddRrcDiagPhych;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddDedicatedPhyCchParam_struct 
 {	 
 UINT8 numPhych ; /**< ( 0 ..96 ) , 0 : all the followed item not exist ; others ( 1 -96 ) : actual physical channel number ; and the followed times exist*/	 
 CiDevTddRrcDiagPhych phychInfo [ 96 ] ;	 
	 
 UINT32 res1U32 ; /**< ( padding ) */	 
 UINT16 workFreq ; /**< Work frequency , ( 0 ..16383 ) UARFCN , real requency ( Mhz ) =UARFCN / 5 . It indicates the work frequency */	 
 } CiDevTddDedicatedPhyCchParam;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevHrnti_struct 
 {	 
 CiBoolean flag ; /**< 0 : H-RNTI is not existed , 1 :H-RNTI is existed */	 
 UINT16 hrnti ; /**< ( 0 ..65535 ) , exist only when flag=1 */	 
 } CiDevHrnti;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevErnti_struct 
 {	 
 CiBoolean flag ; /**< 0 : E-RNTI is not existed , 1 :E-RNTI is existed */	 
 UINT16 ernti ; /**< ( 0 ..65535 ) , exist only when flag=1 */	 
 } CiDevErnti;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUrntiCrnti_struct 
 {	 
 UINT8 flag ; /**< Bit0:C-RNTI ; Bit1:U-RNTI ; 0 :not existed , 1 :existed*/	 
 UINT32 urnti ; /**< ( 0 ..4294967295 ) , exist only when flag=1 */	 
 UINT16 crnti ; /**< ( 0 ..65535 ) , exist only when flag=1 */	 
 } CiDevUrntiCrnti;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddData_struct 
 {	 
 CiDevTsIscpArray iscp ; /**< TimeSlot ISCP */	 
 CiDevDpchRscpArray rscp ; /**< DPCH RSCP */	 
 CiDevTxPowerArray txPower ; /**< UE Timeslot Transmitted Power */	 
	 
 UINT8 sCellPccphRscp ; /**< Scell P-CCPCH RSCP , ( 0 ..91 ) real value ( dbm ) =IE value -116 */	 
 UINT32 sCellId ; /**< Scell Cell Identifier , BITSTRING ( 28 ) MSB 4 bits are 0 */	 
 UINT8 sCellParamId ; /**< Scell Cell parameter id , ( 0 ..127 ) */	 
 UINT16 sCellUarfcn ; /**< Scell UARFCN , ( 0 ..16383 ) , real frequency ( MHz ) =UARFCN / 5 */	 
 UINT8 sCellUtraRssi ; /**< Scell UTRA Carrier RSSI , ( 0 ..76 ) real value ( dbm ) =IE value - 101 */	 
	 
 CiDevTddNcellParamList nbCellInfo ; /**< Neigbour cell parameter list */	 
 CiDevTddDedicatedPhyCchParam dedicatedInfo ; /**< Dedicated PhyCh parameter */	 
	 
 CiDevHrnti hRnti ; /**< H-RNTI */	 
 CiDevErnti eRnti ; /**< E-RNTI */	 
 CiDevUrntiCrnti rnti ; /**< U-RNTI / C-RNTI */	 
 } CiDevTddData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmScellSysInfo_struct 
 {	 
 UINT16 arfcn ; /**< Serving cell ARFCN ( 0 ..1023 ) */	 
 UINT16 ci ; /**< Serving cell cell identity */	 
	 
 UINT16 res1U16 ; /**< ( padding ) */	 
 CiDevGsmBand band ; /**< Serving cell current freq band */	 
	 
 UINT32 res1U32 ; /**< ( padding ) */	 
 } CiDevGsmScellSysInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmScellRadioInfo_struct 
 {	 
 UINT8 fieldMap ; /**< bit0:C2 exist or not , bit1:C31 exist or not , bit2:C32 exist or not */	 
 INT16 rxLev ; /**< Serving cell GSM received signal level. ( -110..-30 ) */	 
 UINT8 bsic ; /**< Serving cell BSIC. ( 0 ..63 ) */	 
 INT16 c1 ; /**< Serving cell Path loss param C1*/	 
 INT16 c2 ; /**< Serving cell Path loss param C2*/	 
 INT16 c31 ; /**< Serving cell GPRS signal level threshold criterion param C31*/	 
 INT16 c32 ; /**< Serving cell GPRS cell ranking criterion param C32*/	 
 } CiDevGsmScellRadioInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmNcellSysInfo_struct 
 {	 
 UINT16 arfcn ; /**< GSM neigbour cell ARFCN ( 0 ..1023 ) */	 
 UINT16 res1U16 ; /**< ( padding ) */	 
	 
 CiDevGsmBand band ; /**< GSM neigbour cell current freq band */	 
 UINT8 bsic ; /**< GSM neigbour cell BSIC. ( 0 ..63 ) */	 
 UINT16 ci ; /**< GSM Ncell identity */	 
	 
 CiDevPlmnMcc mcc ; /**< Mobile country code ( 3 digitals ) . \sa CiDevPlmnMcc */	 
 CiDevPlmnMnc mnc ; /**< Mobile network code ( 2 or 3 digitals ) . \sa CiDevPlmnMnc */	 
	 
 UINT16 lac ; /**< Location area code */	 
 } CiDevGsmNcellSysInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmNcellRadioInfo_struct 
 {	 
 UINT8 fieldMap ; /**< bit0:C2 exist or not , bit1:C31 exist or not , bit2:C32 exist or not */	 
 INT16 c1 ; /**< GSM neigbour cell Path loss param C1*/	 
 INT16 rxLev ; /**< GSM neigbour cell GSM received signal level. ( -110..-30 ) */	 
	 
 INT16 c2 ; /**< GSM neigbour cell Path loss param C2*/	 
 INT16 c31 ; /**< GSM neigbour cell GPRS signal level threshold criterion param C31*/	 
 INT16 c32 ; /**< GSM neigbour cell GPRS cell ranking criterion param C32*/	 
 } CiDevGsmNcellRadioInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmNcellInfoGsm_struct 
 {	 
 CiDevGsmNcellSysInfo sysInfo ;	 
 CiDevGsmNcellRadioInfo radioInfo ;	 
 } CiDevGsmNcellInfoGsm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmTdNcellInfoTdd_struct 
 {	 
 UINT8 cellParamId ; /**< Cell parameter id , ( 0 ..127 ) */	 
 UINT16 uArfcn ; /**< UARFCN , ( 0 ..16383 ) , real frequency ( MHz ) =UARFCN / 5 */	 
 UINT8 pccpchRSCP ; /**< PCCPCH RSCP , ( 0 ..91 ) real value ( dbm ) =IE value -116 */	 
 UINT8 utraRssi ; /**< UTRA carrier RSSI , ( 0 ..76 ) real value ( dbm ) =IE value - 101 */	 
 } CiDevGsmNcellInfoTdd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmNcellInfo_struct 
 {	 
 UINT8 numNcellGsm ;	 
 CiDevGsmNcellInfoGsm nbCellInfoGsm [ 6 ] ;	 
	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 UINT8 numNcellTdd ; /**< Note: numNcellGsm+numNcellTdd <= CI_DEV_MAX_GSM_NEIGHBORING_CELLS */	 
 CiDevGsmNcellInfoTdd nbCellInfoTdd [ 6 ] ;	 
 } CiDevGsmNcellInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_SPEECH_CODE_TAG {	 
 CI_DEV_GSM_SPEECH_GSM_HR = 0 ,	 
 CI_DEV_GSM_SPEECH_GSM_FR ,	 
 CI_DEV_GSM_SPEECH_GSM_EFR ,	 
 CI_DEV_GSM_SPEECH_HR_AMR ,	 
 CI_DEV_GSM_SPEECH_FR_AMR ,	 
	 
 CI_DEV_NUM_GSM_SPEECH	 
 } _CiDevGsmSpeechCode;

typedef UINT8 CiDevGsmSpeechCode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_DED_CHANNEL_TYPE_TAG {	 
 CI_DEV_GSM_DEDICATED_TCH = 0 ,	 
 CI_DEV_GSM_DEDICATED_SDCCH ,	 
 CI_DEV_GSM_DEDICATED_PDCH ,	 
	 
 CI_DEV_NUM_GSM_DEDICATED_CHANNEL	 
 } _CiDevGsmDedChannelType;

typedef UINT8 CiDevGsmDedChannelType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmCellAlloc_struct 
 {	 
 UINT8 numCellAlloc ; /**< The number of Cell Allocation. ( 1 ~64 ) */	 
 UINT16 cellAlloc [ 64 ] ; /**< Cell Allocation list. ( 0 ~1024 ) */	 
 } CiDevGsmCellAlloc;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmDedArfcn_struct 
 {	 
 CiBoolean hoppingChannel ; /**< dedicated channel support arfcn hopping or not */	 
 UINT16 arfcn ; /**< absolute RF channel number. ( 0 ..1023 ) only exist when hoppingChannel=0 */	 
 CiDevHoppingGroup hoppingGroup ; /**< Hopping List , exist when hoppingChannel=1 */	 
 CiDevGsmCellAlloc cellAlloc ; /**< Cell Allocation*/	 
	 
 UINT8 MAIO ; /**< mobile allocation index offset , ( 0 ..63 ) exist when hoppingChannel=1*/	 
 UINT8 HSN ; /**< hopping sequence number , ( 0 ..63 ) exist when hoppingChannel=1*/	 
 } CiDevGsmDedArfcn;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmDedChannelInfo_struct 
 {	 
 UINT8 fieldMap ; /**< Bit0:Ded_arfcn_beforetime ; Bit1:Speech code used ; Bit2:Ded_arfcn_after_time and tn */	 
 CiDevGsmDedArfcn arfcnAfterTime ; /**< Arfcn of dedicated channel after starting timer */	 
	 
 UINT8 tn ; /**< current dedicated maining link timeslot mapping ( List of timeslots used. ( 0 ..7 ) */	 
	 
 CiDevGsmSpeechCode speechCode ; /**< Speech code used */	 
 CiDevGsmDedChannelType channelType ; /**< Channel Type */	 
	 
 CiDevGsmDedArfcn arfcnBeforeTime ; /**< Arfcn of dedicated channel before starting timer */	 
 } CiDevGsmDedChannelInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmDedMeasInfo_struct 
 {	 
 UINT8 sCellRxQualFull ; /**< Dedicated channel RXQUAL_FULL , ( 0 ..7 ) */	 
 UINT8 sCellRxQualSub ; /**< Dedicated channel RXQUAL_SUB , ( 0 ..7 ) */	 
 UINT8 sCellTimingAdv ; /**< TA , ( 0 ..63 ) , 0xff :invalid value */	 
 UINT8 sCellTxPower ; /**< power class of current dedicated channel */	 
	 
 UINT8 sCellRxLevFull ; /**< service cell received signal level full , ( 0 ..63 ) invalid value 0xff , real value ( dBm ) =IE value-110 */	 
 UINT8 sCellRxLevSub ; /**< service cell received signal level sub , ( 0 ..63 ) invalid value 0xff , real value ( dBm ) =IE value-110 */	 
 UINT8 res1U8 ; /**< ( padding ) */	 
 UINT8 bler ; /**< Block error rate for all code schemes. The actual ratio should be devided by 0xff :invalid value*/	 
 } CiDevGsmDedMeasInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmTimeSlotCi_struct 
 {	 
 UINT8 tsNo ; /**< Timeslot */	 
 INT16 rxLev ;	 
 INT16 ci ; /**< Bit0~bit7 ( LSB ) :decimal part , unsigned data ; Bit8~bit15 ( LSB ) : integer part , signed data. */	 
 } CiDevGsmTimeSlotCi;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmArfcnCiRep_struct 
 {	 
 UINT16 arfcn ; /**< BCCH Frequency , ( 0 ..1023 ) */	 
 CiDevGsmBand band ; /**< Frequency band */	 
	 
 UINT8 numSlot ; /**< The number of slots which this arfcn has appeared at one time. ( 0 ..4 ) */	 
 CiDevGsmTimeSlotCi slotCiArray [ 4 ] ;	 
 } CiDevGsmArfcnCiRep;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmCIInfo_struct 
 {	 
 UINT8 repArfcnNum ; /**< The number of the arfcn reported. ( 0 ..64 ) */	 
 CiDevGsmArfcnCiRep data [ 64 ] ;	 
 } CiDevGsmCIInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmBepCvBepInfo_struct 
 {	 
 CiBoolean isGmskValid ; /**< 0 :GMSK_MEAN_BEP and GMSK_CV_BEP is absent ; 1 :GMSK_MEAN_BEP and GMSK_CV_BEP is present*/	 
 UINT8 gmskMeanBepCvBep ; /**< GMSK_MEAN_BEP: High 5 bits of 1 octet ; GMSK_CV_BEP: Low 3 bits of above octet*/	 
	 
 CiBoolean is8pskValid ; /**< 0 :8PSK_MEAN_BEP and 8 PSK_CV_BEP is absent ; 1 :8PSK_MEAN_BEP and 8 PSK_CV_BEP is present*/	 
 UINT8 psk8MeanBepCvBep ; /**< 8 PSK_MEAN_BEP: High 5 bits of 1 octet ; 8 PSK_CV_BEP: Low 3 bits of above octet*/	 
 } CiDevGsmBepCvBepInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmUlCsMcs_struct 
 {	 
 UINT32 frameNo ; /**< Frame number of this UL block */	 
 CiDevGsmCodingScheme mcsCs ; /**< 7 ~10:CS1~CS4 ; 11 ~19:MCS1~MCS9 */	 
 } CiDevGsmUlCsMcs;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmMcsCs_struct 
 {	 
 UINT8 tsNo ; /**< Timeslot of this DL block */	 
 CiDevGsmCodingScheme mcsCs ; /**< 7 ~10:CS1~CS4 ; 11 ~19:MCS1~MCS9 */	 
 } CiDevGsmMcsCs;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmDlCsMcs_struct 
 {	 
 UINT32 frameNo ; /**< Frame number of this DL block */	 
	 
 UINT8 blkNum ; /**< The number of DL block received */	 
 CiDevGsmMcsCs mcsCs [ 4 ] ;	 
 } CiDevGsmDlCsMcs;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmMcsCsInfo_struct 
 {	 
 UINT8 ulLength ; /**< The number of UL_CS_MCS in peroid 1 s*/	 
 CiDevGsmUlCsMcs ulCsMcs [ 50 ] ;	 
	 
 UINT8 dlLength ; /**< The number of DL_CS_MCS in peroid 1 s*/	 
 CiDevGsmDlCsMcs dlCsMcs [ 50 ] ;	 
 } CiDevGsmMcsCsInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmTfiTimeslot_struct 
 {	 
 CiBoolean isUlTfiValid ; /**< 0 :UL_TFI and UL timeslot allocation is absent ; 1 : UL_TFI and UL timeslot allocation is present*/	 
 UINT8 ulTfi ; /**< UL_TFI */	 
 UINT8 ulTimeSlotAlloc ; /**< UL timeslot allocation */	 
	 
 CiBoolean isDlTfiValid ; /**< 0 :DL_TFI and DL timeslot allocation is absent ; 1 : DL_TFI and DL timeslot allocation is present*/	 
 UINT8 dlTfi ; /**< DL_TFI*/	 
 UINT8 dlTimeSlotAlloc ; /**< DL timeslot allocation */	 
 } CiDevGsmTfiTimeslot;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmData_struct 
 {	 
 CiDevGsmScellSysInfo sCellSysInfo ; /**< Serving cell system information. */	 
 UINT8 sCellSysInfoDtxInd ; /**< Serving cell reselection system information.	 
 ( 0 ..2 ) , DTX indicator , 0 :the MS may use uplink discontinous transmission ,	 
 1 :the MS shall use uplink discontinous transmission ,	 
 2 :the MS shall not use uplink discontinous transmission*/	 
	 
 CiDevGsmScellRadioInfo sCellRadioInfo ; /**< Serving cell radio information. */	 
 CiDevGsmNcellInfo nCellInfo ; /**< Neighbour cell information. */	 
	 
 CiDevGsmDedChannelInfo dedChannelInfo ; /**< Dedicated channel information. */	 
 CiDevGsmDedMeasInfo dedMeasInfo ; /**< Dedicated measurement information. */	 
	 
 CiDevGsmCIInfo ciInfo ; /**< C / I. */	 
 CiDevGsmBepCvBepInfo bepCvBepinfo ; /**< BEP / CV BEP. */	 
 CiDevGsmMcsCsInfo mscCsInfo ; /**< MCS / CS ( up / down ) . */	 
 CiDevGsmTfiTimeslot tfiTimeSlotInfo ; /**< TFI ( up / down ) and Timeslot Allocation ( up / down ) . */	 
 } CiDevGsmData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevMobileId_struct 
 {	 
 UINT8 digitSize ;	 
 UINT8 digit [ 16 ] ;	 
 } CiDevMobileId;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUeId_struct 
 {	 
 CiDevMobileId imei ; /**< IMEI for 14 ~16 digit. \sa CiDevMobileId */	 
 CiDevMobileId imsi ; /**< IMSI for 15 digit. \sa CiDevMobileId */	 
 CiDevMobileId tmsi ; /**< TMSI for 4 Hex. \sa CiDevMobileId */	 
 CiDevMobileId ptmsi ; /**< PTMSI for 4 Hex. \sa CiDevMobileId */	 
 } CiDevUeId;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevMmInfo_struct 
 {	 
 CiDevPlmnMcc mcc ; /**< Mobile country code ( 3 digitals ) . \sa CiDevPlmnMcc */	 
 CiDevPlmnMnc mnc ; /**< Mobile network code ( 2 or 3 digitals ) . \sa CiDevPlmnMnc */	 
	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 res1U16 ; /**< ( padding ) */	 
 } CiDevMmInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonData_struct 
 {	 
 CiDevUeId ueId ; /**< UE ID */	 
 CiDevMmInfo mmInfo ; /**< MM inforamtion */	 
 } CiDevCommonData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevWirelessParam_struct 
 {	 
 CiDevTddData tddInfo ; /**< TDSCDMA parameters */	 
 CiDevCommonData commonInfo ; /**< Common parameters */	 
 CiDevGsmData gsmInfo ; /**< GSM parameters */	 
 } CiDevWirelessParam;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_SYSTEM_INFO_TYPE_TAG {	 
 CI_DEV_SYS_INFO_TYPE_MIB = 0 ,	 
 CI_DEV_SYS_INFO_TYPE_SB1 ,	 
 CI_DEV_SYS_INFO_TYPE_SB2 ,	 
 CI_DEV_SYS_INFO_TYPE1 ,	 
 CI_DEV_SYS_INFO_TYPE2 ,	 
 CI_DEV_SYS_INFO_TYPE3 ,	 
 CI_DEV_SYS_INFO_TYPE4 ,	 
 CI_DEV_SYS_INFO_TYPE5 ,	 
 CI_DEV_SYS_INFO_TYPE6 ,	 
 CI_DEV_SYS_INFO_TYPE7 ,	 
 CI_DEV_SYS_INFO_TYPE8 ,	 
 CI_DEV_SYS_INFO_TYPE9 ,	 
 CI_DEV_SYS_INFO_TYPE10 ,	 
 CI_DEV_SYS_INFO_TYPE11 ,	 
 CI_DEV_SYS_INFO_TYPE12 ,	 
 CI_DEV_SYS_INFO_TYPE13 ,	 
 CI_DEV_SYS_INFO_TYPE13_1 ,	 
 CI_DEV_SYS_INFO_TYPE13_2 ,	 
 CI_DEV_SYS_INFO_TYPE13_3 ,	 
 CI_DEV_SYS_INFO_TYPE13_4 ,	 
 CI_DEV_SYS_INFO_TYPE14 ,	 
 CI_DEV_SYS_INFO_TYPE15 ,	 
 CI_DEV_SYS_INFO_TYPE15_1 ,	 
 CI_DEV_SYS_INFO_TYPE15_2 ,	 
 CI_DEV_SYS_INFO_TYPE15_3 ,	 
 CI_DEV_SYS_INFO_TYPE15_4 ,	 
 CI_DEV_SYS_INFO_TYPE15_5 ,	 
 CI_DEV_SYS_INFO_TYPE16 ,	 
 CI_DEV_SYS_INFO_TYPE17 ,	 
 CI_DEV_SYS_INFO_TYPE18 ,	 
 CI_DEV_SYS_INFO_TYPE5bis ,	 
	 
 CI_DEV_NUM_SYS_FINO	 
 } _CiDevSystemInfoType;

typedef UINT8 CiDevSystemInfoType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevBcchFachParam_struct 
 {	 
 UINT8 rbId ; /**< Rb identity. Value 34 , It is used for message from FACH to BCCH*/	 
 UINT16 noTb ; /**< Indicates the number of transport blocks transmitted by the peer entity within the TTI , beased on the TFI value*/	 
 } CiDevBcchFachParam;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPcchPchParam_struct 
 {	 
 UINT8 rbId ; /**< Rb identity. Value 33 , It is used for message from PCH to PCCH*/	 
 UINT16 noTb ; /**< Indicates the number of transport blocks transmitted by the peer entity within the TTI , beased on the TFI value*/	 
 } CiDevPcchPchParam;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAmDataInd_struct 
 {	 
 UINT8 fieldInd ; /**< Indicate the presence or absence of peer_msg and disc_info. 1 :peer_msg exists ; 2 :disc_info exists*/	 
 UINT16 discInfo ; /**< Indicates to ULR the discarded RLC SDU in the peer-RLC AM entity. 0 ~65535*/	 
 } CiDevAmDataInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTmDataInd_struct 
 {	 
 CiBoolean errIndFlag ; /**< Indicate the presence or absence of error_ind. 1 means exists. When " err_SDU_delv " is configured as YES and	 
 there are SDUs received in error , the err_ind parameter is present*/	 
 UINT8 errInd ; /**< Indicates that the RLC SDU is erroneous*/	 
 } CiDevTmDataInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevDataIndPara_struct 
 {	 
 UINT8 rlcMode ; /**< RLC mode. 1 :AM ; 2 :UM ; 3 :TM ; Other values are reserved*/	 
	 
 union	 
 {		 
 CiDevAmDataInd dlAmData ;		 
 CiDevTmDataInd dlTmData ;		 
 } dataIndPara ;	 
 } CiDevDataIndPara;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevDlCchParam_struct 
 {	 
 UINT8 rbId ; /**< Rb identity. 0 :CCCH ; 1 ~32:DCCH ; 36 :MCCH*/	 
 CiDevDataIndPara dataIndPara ; /**< \sa CiDevDataIndPara */	 
 } CiDevDlCchParam;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAmDataReq_struct 
 {	 
 CiBoolean cnfReq ; /**< If the value is true , uplayer requests RLC to confirm the reception of RLC SDUs by te peer-RLC AM entity.	 
 If the value is false , no confirmation is requested*/	 
 CiBoolean fieldInd ; /**< Indicate the presence or absence of MUI. When disc_req and CNF are both false , MUI does not exist. other situation , MUI exists.*/	 
 UINT16 mui ; /**< RLC shall give discarded info using this identifier for SDU. MUI: 0 ~65535*/	 
 } CiDevAmDataReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmDataReq_struct 
 {	 
 UINT16 mui ; /**< RLC shall give discarded info using this identifier for SDU. MUI: 0 ~65535*/	 
 } CiDevUmDataReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTmDataReq_struct 
 {	 
 UINT16 mui ; /**< RLC shall give discarded info using this identifier for SDU. MUI: 0 ~65535*/	 
 } CiDevTmDataReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUlCchParam_struct 
 {	 
 UINT8 rbId ; /**< Rb identity. 0 ~32*/	 
 CiBoolean discReq ; /**< If the value is true , uplink layer requests RLC for the discarded RLC SDU by local entity.	 
 If the value if false , no discarded RLC SDU is requested*/	 
 CiDevDataReqPara dataReqPara ; /**< \sa CiDevDataReqPara */	 
 } CiDevUlCchParam;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_CHANNEL_TYPE_TAG {	 
 CI_DEV_GSM_PBCCH = 1 ,	 
 CI_DEV_GSM_PRACH ,	 
 CI_DEV_GSM_PCCCH ,	 
 CI_DEV_GSM_PDTCH ,	 
 CI_DEV_GSM_PACCH ,	 
 CI_DEV_GSM_BCCH ,	 
 CI_DEV_GSM_N_BCCH ,	 
 CI_DEV_GSM_E_BCCH ,	 
 CI_DEV_GSM_CCCH ,	 
 CI_DEV_GSM_PAG_CH ,	 
 CI_DEV_GSM_RACH ,	 
	 
 CI_DEV_GSM_SDCCH ,	 
 CI_DEV_GSM_SDCCH4_0 , /**< SDCCH / 4 subchannel number 0 */	 
 CI_DEV_GSM_SDCCH4_1 , /**< SDCCH / 4 subchannel number 1 */	 
 CI_DEV_GSM_SDCCH4_2 , /**< SDCCH / 4 subchannel number 2 */	 
 CI_DEV_GSM_SDCCH4_3 , /**< SDCCH / 4 subchannel number 3 */	 
 CI_DEV_GSM_SDCCH8_0 , /**< SDCCH / 8 subchannel number 0 */	 
 CI_DEV_GSM_SDCCH8_1 , /**< SDCCH / 8 subchannel number 1 */	 
 CI_DEV_GSM_SDCCH8_2 , /**< SDCCH / 8 subchannel number 2 */	 
 CI_DEV_GSM_SDCCH8_3 , /**< SDCCH / 8 subchannel number 3 */	 
 CI_DEV_GSM_SDCCH8_4 , /**< SDCCH / 8 subchannel number 4 */	 
 CI_DEV_GSM_SDCCH8_5 , /**< SDCCH / 8 subchannel number 5 */	 
 CI_DEV_GSM_SDCCH8_6 , /**< SDCCH / 8 subchannel number 6 */	 
 CI_DEV_GSM_SDCCH8_7 , /**< SDCCH / 8 subchannel number 7 */	 
	 
 CI_DEV_GSM_SACCH ,	 
 CI_DEV_GSM_FACCH ,	 
 CI_DEV_GSM_TCH_F ,	 
 CI_DEV_GSM_TCH_H_0 , /**< TCH / H subchannel number 0 */	 
 CI_DEV_GSM_TCH_H_1 , /**< TCH / H subchannel number 1 */	 
	 
 CI_DEV_GSM_PPCH ,	 
 CI_DEV_GSM_ETCH_F ,	 
 CI_DEV_GSM_ATCH_F ,	 
 CI_DEV_GSM_ATCH_H ,	 
 CI_DEV_GSM_EIACCH_F ,	 
 CI_DEV_GSM_CBCH_4 ,	 
 CI_DEV_GSM_CBCH_8 ,	 
	 
 CI_DEV_NUM_GSM_CHANNEL	 
 } _CiDevGsmChannelType;

typedef UINT8 CiDevGsmChannelType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_BURST_TYPE_TAG {	 
 CI_DEV_GSM_ONE_ACCESS_BURST_OF_TYPE_8_BITS = 0 ,	 
 CI_DEV_GSM_ONE_ACCESS_BURST_OF_TYPE_11_BITS ,	 
 CI_DEV_GSM_FOUR_ACCESS_BURST_OF_TYPE_8_BITS ,	 
 CI_DEV_GSM_FOUR_ACCESS_BURST_OF_TYPE_11_BITS ,	 
 CI_DEV_GSM_FREQUENCY_CORRECTION_BURST ,	 
 CI_DEV_GSM_SYNCHRONIZATION_BURST ,	 
 CI_DEV_GSM_DUMMY_BURST ,	 
 CI_DEV_GSM_NORMAL_CS_1_RADIO_BLK_BURST ,	 
 CI_DEV_GSM_NORMAL_CS_2_RADIO_BLK_BURST ,	 
 CI_DEV_GSM_NORMAL_CS_3_RADIO_BLK_BURST ,	 
 CI_DEV_GSM_NORMAL_CS_4_RADIO_BLK_BURST ,	 
 CI_DEV_GSM_NORMAL_BURST = CI_DEV_GSM_NORMAL_CS_1_RADIO_BLK_BURST ,	 
	 
 CI_DEV_NUM_GSM_BURST	 
 } _CiDevGsmBurstType;

typedef UINT8 CiDevGsmBurstType ;
typedef UINT8 CiDevGsmSignalName ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmParam_struct 
 {	 
 CiBoolean isBadFrame ; /**< 1 : bad frame ; 0 :not bad frame*/	 
 CiBoolean isUpDownData ; /**< 1 : uplink data ; 0 :downlink data*/	 
 CiBoolean isNasMsg ; /**< 1 : nas message ; 0 :not nas message*/	 
	 
 CiDevGsmChannelType chType ; /**< \sa CiDevGsmChannelType */	 
 CiDevGsmCodingScheme cs ; /**< \sa CiDevGsmCodingScheme */	 
 CiDevGsmBurstType burstType ; /**< \sa CiDevGsmBurstType */	 
 CiDevGsmSignalName signalName ; /*add for GSM message decode*/	 
	 
 UINT8 sapi ; /**< sapi=0 or sapi=3 , other reserved */	 
 } CiDevGsmParam;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_NETWORK_MONITOR_OPTION_REQ " > */ 
 typedef struct CiDevPrimSetNetworkMonitorOptReq_struct 
 {	 
 CiBoolean Option ; /**< Always hard coded with zero. \sa CiBoolean */	 
 CiDevNwMonitorMode Mode ; /**< Report mode. \sa CiDevNwMonitorMode */	 
 } CiDevPrimSetNetworkMonitorOptReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_NETWORK_MONITOR_OPTION_CNF " > */ 
 typedef struct CiDevPrimSetNetworkMonitorOptCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimSetNetworkMonitorOptCnf;

typedef CiEmptyPrim CiDevPrimGetNetworkMonitorOptReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_GET_NETWORK_MONITOR_OPTION_CNF " > */ 
 typedef struct CiDevPrimGetNetworkMonitorOptCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 CiBoolean Option ; /**< Always hard coded with zero. \sa CiBoolean */	 
 CiDevNwMonitorMode Mode ; /**< Report mode. \sa CiDevNwMonitorMode */	 
 } CiDevPrimGetNetworkMonitorOptCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_PROTOCOL_STATUS_CONFIG_REQ " > */ 
 typedef struct CiDevPrimSetProtocolStatusConfigReq_struct 
 {	 
 CiBoolean Option ; /**< 0 : disable unsolicited result code ( default ) ; 1 :enable unsolicited result code*/	 
 } CiDevPrimSetProtocolStatusConfigReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_PROTOCOL_STATUS_CONFIG_CNF " > */ 
 typedef struct CiDevPrimSetProtocolStatusConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimSetProtocolStatusConfigCnf;

typedef CiEmptyPrim CiDevPrimGetProtocolStatusConfigReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_GET_PROTOCOL_STATUS_CONFIG_CNF " > */ 
 typedef struct CiDevPrimGetProtocolStatusConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 CiBoolean Option ; /**< 0 : disable unsolicited result code ( default ) ; 1 :enable unsolicited result code*/	 
 } CiDevPrimGetProtocolStatusConfigCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_PROTOCOL_STATUS_CHANGED_IND " > */ 
 typedef struct CiDevPrimProtocolStatusChangedInd_struct 
 {	 
 CiDevProtocolStatus status ; /**< Protocol status. \sa CiDevProtocolStatus */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 } CiDevPrimProtocolStatusChangedInd;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_EVENT_IND_CONFIG_REQ " > */ 
 typedef struct CiDevPrimSetEventIndConfigReq_struct 
 {	 
 CiBoolean Option ; /**< 0 : disable intermediate result code ( default ) ; 1 :enable intermediate result code*/	 
 } CiDevPrimSetEventIndConfigReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_EVENT_IND_CONFIG_CNF " > */ 
 typedef struct CiDevPrimSetEventIndConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimSetEventIndConfigCnf;

typedef CiEmptyPrim CiDevPrimGetEventIndConfigReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_GET_EVENT_IND_CONFIG_CNF " > */ 
 typedef struct CiDevPrimGetEventIndConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 CiBoolean Option ; /**< 0 : disable unsolicited result code ( default ) ; 1 :enable unsolicited result code*/	 
 } CiDevPrimGetEventIndConfigCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_EVENT_REPORT_IND " > */ 
 typedef struct CiDevPrimEventReportInd_struct 
 {	 
 UINT32 timeStamp ; /**< System tick value , ( 0 , -2147483648 ) .*/	 
 CiBitRange operationType ; /**< Operation type , bitmap - bit0:CS voice ; bit1:CS data ; bit2:PS ; bit3:SMS \sa CiDevEventOperType */	 
 CiDevEventId eventId ; /**< Event ID.*/	 
 } CiDevPrimEventReportInd;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_WIRELESS_PARAM_CONFIG_REQ " > */ 
 typedef struct CiDevPrimSetWirelessParamConfigReq_struct 
 {	 
 CiBoolean Option ; /**< 0 : disable result code presentation to TE ( default ) ; 1 :enable result code presentation to TE*/	 
 UINT16 Interval ; /**< Report Interval ( seconds ) for PERIODIC , default 3 s */	 
 } CiDevPrimSetWirelessParamConfigReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_WIRELESS_PARAM_CONFIG_CNF " > */ 
 typedef struct CiDevPrimSetWirelessParamConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimSetWirelessParamConfigCnf;

typedef CiEmptyPrim CiDevPrimGetWirelessParamConfigReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_GET_WIRELESS_PARAM_CONFIG_CNF " > */ 
 typedef struct CiDevPrimGetWirelessParamConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 CiBoolean Option ; /**< 0 : disable result code presentation to TE ( default ) ; 1 :enable result code presentation to TE*/	 
 UINT16 Interval ; /**< Report Interval ( seconds ) for PERIODIC , default 3 s */	 
 } CiDevPrimGetWirelessParamConfigCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_WIRELESS_PARAM_IND " > */ 
 typedef struct CiDevPrimWirelessParamInd_struct 
 {	 
 CiDevEngModeNetwork network ; /**< Network Type ( GSM / UMTS ) . \sa CiDevEngModeNetwork */	 
	 
 UINT32 timeStamp ; /**< System tick value , ( 0 , -2147483648 ) .*/	 
	 
 CiDevCommonData commonInfo ; /**< Common parameters */	 
	 
 UINT32 data_size ; /**< Size of data for CiDevTddData / CiDevGsmData */	 
 UINT8 tddGsmData [ 1908 ] ; /**< data for CiDevTddData / CiDevGsmData */	 
 UINT8 count ; /**< Ordinal number of the data. [ range:1-2 ] */	 
 } CiDevPrimWirelessParamInd;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_SIGNALING_REPORT_CONFIG_REQ " > */ 
 typedef struct CiDevPrimSetSignalingReportConfigReq_struct 
 {	 
 CiBoolean Option ; /**< 0 : disable unsolicited result code ( default ) ; 1 :enable unsolicited result code*/	 
 CiBoolean Mode ; /**< 0 : disable Uu signaling report ( default ) ; 1 :enable Uu signaling report*/	 
 } CiDevPrimSetSignalingReportConfigReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_SIGNALING_REPORT_CONFIG_CNF " > */ 
 typedef struct CiDevPrimSetSignalingReportConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimSetSignalingReportConfigCnf;

typedef CiEmptyPrim CiDevPrimGetSignalingReportConfigReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_GET_SIGNALING_REPORT_CONFIG_CNF " > */ 
 typedef struct CiDevPrimGetSignalingReportConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 CiBoolean Option ; /**< 0 : disable unsolicited result code ( default ) ; 1 :enable unsolicited result code*/	 
 CiBoolean Mode ; /**< 0 : disable Uu signaling report ( default ) ; 1 :enable Uu signaling report*/	 
 } CiDevPrimGetSignalingReportConfigCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SIGNALING_REPORT_IND " > */ 
 typedef struct CiDevPrimSignalingReportInd_struct 
 {	 
 UINT16 totalMsglen ; /**< The total message length = parameter length + peer message length + 17 */	 
 UINT8 frameType ; /**< The type of freame , 0xAA : used for trace data ; others: reserved.*/	 
	 
 CiDevSignalingMsgId msgId ; /**< The message identifier. \sa CiDevSignalingMsgId */	 
 UINT32 timeStamp ; /**< Timrt counter , Unit:ms , the value would be set to 0 when power on.*/	 
	 
 UINT16 paramLen ; /**< The length of the parameter data in byte , the length can be zero , in such case , the parameter would include nother */	 
 union	 
 {		 
 CiDevSystemInfoType bchParam ;		 
 CiDevBcchFachParam bcchFachParam ;		 
 CiDevPcchPchParam pcchPchParam ;		 
 CiDevDlCchParam dlCchParam ;		 
 CiDevUlCchParam ulCchParam ;		 
 CiDevGsmParam gsmParam ;		 
 } paramData ;	 
	 
 UINT16 peerMsgLen ; /**< The length of the peer message in byte */	 
 UINT16 freeHeaderSpaceLen ; /**< The length of the free bit header space in bit. It is said the number of the free header space length bits is just filled for alignment , and not usefull */	 
 UINT8 peerMsgData [ 356 ] ; /**< Peer message encoded with ASN.1.*/	 
 } CiDevPrimSignalingReportInd;

typedef UINT16 Arfcn ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimDipChannelChangeInd_struct 
 {	 
 CiDevNetworkMode networkMode ; // 0 : CI_DEV_NW_GSM ; 1 :CI_DEV_NW_UMTS ; 3 : CI_DEV_NW_LTE	 
 /*Arfcn*/ UINT32 arfcn ; /*Lilei , CQ00073839 , 20141023 */	 
 CiDevBand band ; // band: Dip band GSM : 0 : EGSM 1 :DCS 2 :PCS 6 :GSM850 ; WCDMA:1: BAND1 ; 2 :BAND2 ; ... ; 14 :BAND14 ; LTE: 1 : BAND1 ; 2 : BAND2...	 
 CiDevServiceType servicetype ;	 
 /*Added by Lilei for CQ58144 on 4032014 , begin*/	 
 UINT8 dipOption ; // 0 : disable ; 1 : enable manual mode for special case ( such as test model ) -default one ; 2 : enable manual mode for user model ; 3 : enable auto mode for end user ( not used )	 
 /*Added by Lilei for CQ58144 on 4032014 , end*/	 
 /*Added by Lilei for CQ58144 on 4292014 , begin*/	 
 CiBoolean LpmEnabled ; // 0 : Lpm disabled ; 1 : Lpm enabled	 
 /*Added by Lilei for CQ58144 on 4292014 , end*/	 
 } CiDevPrimDipChannelChangeInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSecurityParamsReq_struct {	 
 CiBoolean EnableCiphering ; /**< TRUE - ciphering capabilities are derived from NVM ; FALSE - ciphering capabilities are disabled. \sa CCI API Ref Manual */	 
 CiBoolean EnableIntegrityProtection ; /**< TRUE - integrity protection capabilities are derived from NVM ; FALSE - integrity protection capabilities are disabled. \sa CCI API Ref Manual */	 
 } CiDevPrimSetSecurityParamsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSecurityParamsCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetSecurityParamsCnf;

typedef CiEmptyPrim CiDevPrimGetSecurityParamsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSecurityParamsCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiBoolean EnableCiphering ; /**< TRUE - ciphering capabilities are derived from NVM ; FALSE - ciphering capabilities are disabled. \sa CCI API Ref Manual */	 
 CiBoolean EnableIntegrityProtection ; /**< TRUE - integrity protection capabilities are derived from NVM ; FALSE - integrity protection capabilities are disabled. \sa CCI API Ref Manual */	 
 } CiDevPrimGetSecurityParamsCnf;

//ICAT EXPORTED ENUM 
 /*add by taow 20180920 begin*/ 
 typedef enum CIDEV_SET_POWER_BACK_OFF_TYPE_TAG {	 
 CI_DEV_POWER_BACK_OFF = 0 , // for grip sensor control	 
 CI_DEV_POWER_BACK_ON = 1 , // for grip sensor control	 
 CI_DEV_POWER_REDUCTION = 2 , // for temperature control	 
 CI_DEV_POWER_RAISING = 3 , // for temperature control	 
 CI_DEV_POWER_PCLFIX = 4 , // for PCLFIX	 
	 
 CI_DEV_UNLOCK_FREQUENCY = 8 , // for frequency unthrottle	 
 CI_DEV_LOCK_FREQUENCY = 9 , // for frequency throttle	 
	 
 CI_DEV_NUM_OF_POWER_BACK_OFF_TYPES	 
 } _CiDevSetPowerBackOffType;

typedef UINT8 CiDevSetPowerBackOffType ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_POWER_BACK_OFF_REQ " > */ 
 typedef struct CiDevPrimSetPowerBackOffReq_struct 
 {	 
 CiDevSetPowerBackOffType PowerBackOffType ;	 
 UINT8 value ; /**< Specific value for certain type , such as power reduction / raising */	 
 /*Lilei , CQ00124125 , 20200914 , begin*/	 
 CiDevEngModeNetwork networkMode ; /**< 0 : GSM ; 1 : UMTS ; 2 : LTE ; 6 : all modes & bands ( default ) */	 
 UINT8 band ; /**< GSM: 0 -PGSM , 1 -DCS , 2 -PCS , 3 -EGSM , 4 -GSM450 , 5 -GSM480 , 6 -GSM850 ;	 
 WCDMA: 1 -BAND1 , 2 -BAND2 , ... , 14 :BAND14 ; LTE: 1 -BAND1 , 2 -BAND2...	 
 If mode is 0 / 1 / 2 ( single mode ) , band=0xFF means all bands.	 
 If mode is 6 ( multi-mode ) , band is not used.*/	 
 /*Lilei , CQ00124125 , 20200914 , end*/	 
 /*Lilei , CQ00137338 , 20220621 , begin*/	 
 UINT8 bandwidth ; /**< 0 : invalid ; 1 : 1.400000 MHz ; 2 : 3 MHz ; 3 : 5 MHz ; 4 : 10 MHz ; 5 : 15 MHz ; 6 : 20 MHz ; If bandwidth > 0 , then <value> is in 0.100000 Db unit*/	 
 /*Lilei , CQ00137338 , 20220621 , end*/	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 } CiDevPrimSetPowerBackOffReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_POWER_BACK_OFF_CNF " > */ 
 typedef struct CiDevPrimSetPowerBackOffCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 } CiDevPrimSetPowerBackOffCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevRevision_struct {	 
 UINT16 len ;	 
 CHAR valStr [ 400 ] ;	 
 } CiDevRevision;

typedef CiEmptyPrim CiDevPrimGetInternalRevisionIdReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_CNF " > */ 
 typedef struct CiDevPrimGetInternalRevisionIdCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiDevRevision internalRevisionStr ; /**< Internal Revision ID string. Max length is 100 . \sa CCI API Ref Manual */	 
 CiString buildTimeStr ; /**< Build Time string. Max length is 100 . \sa CCI API Ref Manual */	 
 } CiDevPrimGetInternalRevisionIdCnf;

//ICAT EXPORTED ENUM 
 /** \brief Mode of requested reset*/ 
 typedef enum CIDEVRESETMODETYPE_TAG {	 
 CI_DEV_RESET_FUN , /**< Perform Functionality reset ( CFUN=0 - CFUN=1 ) */	 
 CI_DEV_RESET_HW /**< Perform com hardware reset */	 
 } _CiDevResetModeType;

typedef UINT8 CiDevResetModeType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimResetRequestInd_struct {	 
 CiDevResetModeType reset_mode ;	 
 } CiDevPrimResetRequestInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetUsertestReportOptionReq_struct {	 
 CiBoolean enable ; /**< TRUE - Set User Testing reporting to ON ; FALSE - Set User Testing reporting to OFF. */	 
 UINT8 reserved [ 3 ] ;	 
 } CiDevPrimSetUsertestReportOptionReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetUsertestReportOptionCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetUsertestReportOptionCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUsertestValuableEventReportInd_struct {	 
 UINT32 initiator ; /**< Event initiator environment. */	 
 UINT32 eventType ; /**< Type of valuable event ( severity , etc. ) . */	 
 CiString eventDescription ; /**< Event description as ASCII string. */	 
 CiBoolean includeSdLog ; /**< Indicates if SD log should be sent to user test server. */	 
 UINT8 reserved [ 3 ] ;	 
 UINT32 binaryLogSize ; /**< Indicates how many bytes ( if any ) are used by binaryLog array. */	 
 UINT8 binaryLog [ 1024 ] ; /**< User supplied binary log. */	 
 } CiDevPrimUsertestValuableEventReportInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetParkModeReq_struct {	 
 CiBoolean enableParkMode ; /**< TRUE - enables park mode. FALSE disables park mode. \sa CCI API Ref Manual */	 
 UINT8 roamingTimer ; /**< timer value for PLMN search in roaming state. This override the default value \sa CCI API Ref Manual */	 
 UINT8 emergencyTimer ; /**< timer value for PLMN search in limited service state ( emergency only ) . This override the default value \sa CCI API Ref Manual */	 
 UINT8 oosTimer ; /**< timer value for PLMN search in out of service state. This override the default value \sa CCI API Ref Manual */	 
 } CiDevPrimSetParkModeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetParkModeCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetParkModeCnf;

typedef CiEmptyPrim CiDevPrimGetParkModeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetParkModeCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiBoolean enableParkMode ; /**< TRUE - enables park mode. FALSE disables park mode. \sa CCI API Ref Manual */	 
 UINT8 roamingTimer ; /**< timer value for PLMN search in roaming state. This override the default value \sa CCI API Ref Manual */	 
 UINT8 emergencyTimer ; /**< timer value for PLMN search in limited service state ( emergency only ) . This override the default value \sa CCI API Ref Manual */	 
 UINT8 oosTimer ; /**< timer value for PLMN search in out of service state. This override the default value \sa CCI API Ref Manual */	 
 } CiDevPrimGetParkModeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetIMSMediaReq_struct {	 
 UINT32 requestId ; /**< Media request identifier */	 
 UINT32 inBufSize ; /**< Media API input parameter length */	 
 UINT8 inBuf [ 1200 ] ; /**< array of char of length InBufSize */	 
 } CiDevPrimSetIMSMediaReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetIMSMediaCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 UINT32 retCode ; /**< Return Code Value */	 
 UINT32 outBufSize ; /**< Media API input parameter length */	 
 UINT8 outBuf [ 1200 ] ; /**< array of char of length OutBufSize */	 
 } CiDevPrimSetIMSMediaCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimIMSMediaInd_struct {	 
 UINT32 notifyCode ; /**< Media notification identifier */	 
 UINT32 bufSize ; /**< Media API parameter length */	 
 UINT8 buf [ 1200 ] ; /**< array of char of length BufSize */	 
 } CiDevPrimIMSMediaInd;

//ICAT EXPORTED ENUM 
 /** \brief Com Config types */ 
 /** \remarks Common Data Section */ 
 typedef enum CIDEV_COMCFG_TOKEN_TYPE {	 
	 
 CI_DEV_COMCFG_TOKEN_UMTS_WB_AMR = 0 ,	 
 CI_DEV_COMCFG_TOKEN_GSM_WB_AMR ,	 
 // CI_DEV_COMCFG_TOKEN_HSDPA ,	 
 // CI_DEV_COMCFG_TOKEN_HSUPA ,	 
 CI_DEV_COMCFG_TOKEN_VENDOR ,	 
 CI_DEV_COMCFG_TOKEN_MANUFACTURE ,	 
 /*Added by Lilei for LTE category on 5282014 , begin*/	 
 CI_DEV_COMCFG_TOKEN_LTE_CATEGORY ,	 
 /*Added by Lilei for LTE category on 5282014 , end*/	 
 /*Lilei , CQ00124026 , 20200910 , begin*/	 
 CI_DEV_COMCFG_TOKEN_MULTISLOT_POWERPROFILE = 5 ,	 
 /*Lilei , CQ00124026 , 20200910 , end*/	 
	 
 CI_DEV_COMCFG_TOKEN_LTE_SMS_ONLY , /*presentation of SMS only for additional update type in ATTACH reqest or TAU*/	 
	 
 CI_DEV_COMCFG_TOKEN_EC_SUPPORTED , /*presentation of restriction of enhanced coverage in ATTACH reqest or TAU , 0 : not supported , EC is restrited ; 1 : supported , EC is not restricted */	 
 CI_DEV_COMCFG_TOKEN_EPCO_SUPPORTED , /* 0 - ePCO not support , 1 - ePCO support */	 
 CI_DEV_COMCFG_TOKEN_HCCP_SUPPORTED , /* 0 - HC-CP CIoT not support , 1 - HC-CP CIoT support */	 
 CI_DEV_COMCFG_TOKEN_MDRB_SUPPORTED = 10 , /* 0 - multipleDRB not support , 1 - multipleDRB support */	 
 CI_DEV_COMCFG_TOKEN_CP_BACKOFF , /* 0 - CP backoff not support , 1 - CP backoff support */	 
	 
 CI_DEV_COMCFG_TOKEN_NSLP , /* bitmap: bit 0 - nasSigLowPriority , bit 1 - overrideNasSignallingPriority */	 
 CI_DEV_COMCFG_TOKEN_EAB , /* bitmap: bit 0 - extendedAccessBarring , 1 - overrideExtendedAccessBarring */	 
	 
 CI_DEV_COMCFG_TOKEN_ROHC , /*RoHC profiles , bitmap: bit 0 ~8 , profile 0x0001 / 0x0002 / 0x0003 / 0x0004 / 0x0006 / 0x0101 / 0x0102 / 0x0103 / 0x0104 */	 
 /*Lilei , CQ00147330 , 20231201 , begin*/	 
 CI_DEV_COMCFG_TOKEN_ATTACH_WO_PDN = 15 , /* 0 - attachWithoutPdn not support , 1 - attachWithoutPdn support */	 
 /*Lilei , CQ00147330 , 20231201 , end*/	 
	 
 CI_DEV_NUM_COMCFG_TOKEN	 
	 
 } _CiDevComcfgTokenType;

typedef UINT8 CiDevComcfgTokenType ;
//ICAT EXPORTED ENUM 
 /** \brief Vendor types */ 
 /** \remarks Common Data Section */ 
 typedef enum CIDEV_COMCFG_VENDOR_TYPE {	 
	 
 CI_DEV_COMCFG_VENDOR_NONE = 0 ,	 
 CI_DEV_COMCFG_VENDOR_ATT ,	 
 CI_DEV_COMCFG_VENDOR_CMCC ,	 
 CI_DEV_COMCFG_VENDOR_IOT , /**< it is not for vendor specific , just for some implements such as CC redial*/	 
 CI_DEV_COMCFG_VENDOR_TELCEL ,	 
 CI_DEV_COMCFG_VENDOR_H3G ,	 
 CI_DEV_COMCFG_VENDOR_VDF ,	 
 CI_DEV_COMCFG_VENDOR_SILVER , /**< it is not for vendor specific , just for some implements of MANUFACTURE*/	 
 CI_DEV_COMCFG_VENDOR_ORG ,	 
 CI_DEV_COMCFG_VENDOR_TMOBILE ,	 
 CI_DEV_COMCFG_VENDOR_VERIZON ,	 
 CI_DEV_COMCFG_VENDOR_HP ,	 
 /*Added by Lilei for CQ58190 on 4042014 , begin*/	 
 CI_DEV_COMCFG_VENDOR_CLOSE_RAMLOG_SWITCH , /**< it is not for vendor specific , just for some implements */	 
 CI_DEV_COMCFG_VENDOR_2G_ROAMING ,	 
 CI_DEV_COMCFG_VENDOR_RRM ,	 
 CI_DEV_COMCFG_VENDOR_CMCC_FRSUPPORT ,	 
 CI_DEV_COMCFG_VENDOR_SILENTRESET , /**< it is not for vendor specific , just for some implements */	 
 CI_DEV_COMCFG_VENDOR_PSOPT , /**< it is not for vendor specific , just for some implements */	 
 CI_DEV_COMCFG_VENDOR_HOMETEST ,	 
 CI_DEV_COMCFG_VENDOR_MTNET ,	 
 /*Added by Lilei for CQ58190 on 4042014 , end*/	 
 CI_DEV_COMCFG_VENDOR_DEUTSCHETELE ,	 
 CI_DEV_COMCFG_VENDOR_CMCC_5MODE_ROAMING ,	 
	 
 CI_DEV_NUM_COMCFG_VENDOR_TYPE	 
	 
 } _CiDevComcfgVendorType;

typedef UINT8 CiDevComcfgVendorType ;
//ICAT EXPORTED ENUM 
 /** \brief Manufacture types */ 
 /** \remarks Common Data Section */ 
 typedef enum CIDEV_COMCFG_MANUFACTURE_TYPE {	 
	 
 CI_DEV_COMCFG_MANUFACTURE_NONE = 0 ,	 
 CI_DEV_COMCFG_MANUFACTURE_M_SILVER ,	 
	 
 CI_DEV_NUM_COMCFG_MANUFACTURE_TYPE	 
	 
 } _CiDevComcfgManufactureType;

typedef UINT8 CiDevComcfgManufactureType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevComcfgToken_struct {	 
 CiDevComcfgTokenType name ; /**< Token name \sa CiDevComcfgTokenType */	 
 /*UINT16*/ UINT32 value ; /**< Token value */ // Modified by Lilei 4042014 CQ58190	 
 } CiDevComcfgToken;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetComConfigReq_struct {	 
 UINT8 numTokens ; /**< Number of tokens to set */	 
 CiDevComcfgToken Token [ CI_DEV_NUM_COMCFG_TOKEN ] ; /**< Tokens info \sa CiDevComcfgToken */	 
 } CiDevPrimSetComConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetComConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetComConfigCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetComConfigReq_struct {	 
 CiBitRange tokens ; /**< This is a bitmap representing the Token to get. The bitmap format matches the enum CIDEV_COMCFG_TOKEN_TYPE */	 
 } CiDevPrimGetComConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetComConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT8 numTokens ; /**< Number of tokens */	 
 CiDevComcfgToken Token [ CI_DEV_NUM_COMCFG_TOKEN ] ; /**< Tokens info \sa CiDevComcfgToken */	 
 } CiDevPrimGetComConfigCnf;

typedef CiEmptyPrim CiDevPrimGetLteMeasReq ;
//ICAT EXPORTED STRUCT 
 typedef struct LteMeasInfo_tag {	 
 UINT16 cellID ; /**< Cell ID of lte rsrp&rsrq measurement info */	 
 UINT32 earfcn ; /**< Arfcn */	 
 UINT8 rsrp ; /**< Rsrp info */	 
 UINT8 rsrq ; /**< Rsrq Info */	 
 } LteMeasInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetLteMeasCnf_struct {	 
 CiDevRc result ; /**< Result code. \sa CiDevRc. */	 
 UINT8 num ; /**< Number of cells that confirm rsrp&rsrq info. */	 
 LteMeasInfo eMeasInfo [ 32 ] ; /**< Rsrp&rsrq measurement info. \sa LteMeasInfo */	 
 } CiDevPrimGetLteMeasCnf;

//ICAT EXPORTED ENUM 
 typedef enum CiDEVLTERRCSTATE_TAG 
 {	 
 CI_DEV_LTE_RRC_STATE_IDLE = 0 , /**< LTE RRC state IDLE */	 
 CI_DEV_LTE_RRC_STATE_CONNECTED /**< LTE RRC state CONNECTED */	 
 } _CiDevLteRrcState;

typedef UINT8 CiDevLteRrcState ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVEUTRANBAND_TAG {	 
 CI_DEV_EUTRAN_BAND_FDD_1 = 1 , /**< E-UTRAN operating band 1 */	 
 CI_DEV_EUTRAN_BAND_FDD_2 , /**< E-UTRAN operating band 2 */	 
 CI_DEV_EUTRAN_BAND_FDD_3 , /**< E-UTRAN operating band 3 */	 
 CI_DEV_EUTRAN_BAND_FDD_4 , /**< E-UTRAN operating band 4 */	 
 CI_DEV_EUTRAN_BAND_FDD_5 , /**< E-UTRAN operating band 5 */	 
 CI_DEV_EUTRAN_BAND_FDD_6 , /**< E-UTRAN operating band 6 */	 
 CI_DEV_EUTRAN_BAND_FDD_7 , /**< E-UTRAN operating band 7 */	 
 CI_DEV_EUTRAN_BAND_FDD_8 , /**< E-UTRAN operating band 8 */	 
 CI_DEV_EUTRAN_BAND_FDD_9 , /**< E-UTRAN operating band 10 */	 
 CI_DEV_EUTRAN_BAND_FDD_10 , /**< E-UTRAN operating band 11 */	 
 CI_DEV_EUTRAN_BAND_FDD_11 , /**< E-UTRAN operating band 12 */	 
 CI_DEV_EUTRAN_BAND_FDD_12 , /**< E-UTRAN operating band 13 */	 
 CI_DEV_EUTRAN_BAND_FDD_13 , /**< E-UTRAN operating band 14 */	 
 CI_DEV_EUTRAN_BAND_FDD_14 , /**< E-UTRAN operating band 15 */	 
 CI_DEV_EUTRAN_BAND_FDD_15_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_FDD_16_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_FDD_17 , /**< E-UTRAN operating band 17 */	 
 CI_DEV_EUTRAN_BAND_FDD_18 , /**< E-UTRAN operating band 18 */	 
 CI_DEV_EUTRAN_BAND_FDD_19 , /**< E-UTRAN operating band 19 */	 
 CI_DEV_EUTRAN_BAND_FDD_20 , /**< E-UTRAN operating band 20 */	 
 CI_DEV_EUTRAN_BAND_FDD_21 , /**< E-UTRAN operating band 21 */	 
 CI_DEV_EUTRAN_BAND_FDD_22 , /**< E-UTRAN operating band 22 */	 
 CI_DEV_EUTRAN_BAND_FDD_23 , /**< E-UTRAN operating band 23 */	 
 CI_DEV_EUTRAN_BAND_FDD_24 , /**< E-UTRAN operating band 24 */	 
 CI_DEV_EUTRAN_BAND_FDD_25 , /**< E-UTRAN operating band 25 */	 
 CI_DEV_EUTRAN_BAND_FDD_26 , /**< E-UTRAN operating band 26 */	 
 CI_DEV_EUTRAN_BAND_FDD_27 , /**< E-UTRAN operating band 27 */	 
 CI_DEV_EUTRAN_BAND_FDD_28 , /**< E-UTRAN operating band 28 */	 
 CI_DEV_EUTRAN_BAND_FDD_29 , /**< E-UTRAN operating band 29 . Restricted to E-UTRA operation when CA is configured */	 
 CI_DEV_EUTRAN_BAND_FDD_30_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_FDD_31_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_FDD_32_NOT_USED ,	 
	 
 CI_DEV_EUTRAN_BAND_TDD_33 , /**< E-UTRAN operating band 33 */	 
 CI_DEV_EUTRAN_BAND_TDD_34 , /**< E-UTRAN operating band 34 */	 
 CI_DEV_EUTRAN_BAND_TDD_35 , /**< E-UTRAN operating band 35 */	 
 CI_DEV_EUTRAN_BAND_TDD_36 , /**< E-UTRAN operating band 36 */	 
 CI_DEV_EUTRAN_BAND_TDD_37 , /**< E-UTRAN operating band 37 */	 
 CI_DEV_EUTRAN_BAND_TDD_38 , /**< E-UTRAN operating band 38 */	 
 CI_DEV_EUTRAN_BAND_TDD_39 , /**< E-UTRAN operating band 39 */	 
 CI_DEV_EUTRAN_BAND_TDD_40 , /**< E-UTRAN operating band 40 */	 
 CI_DEV_EUTRAN_BAND_TDD_41 , /**< E-UTRAN operating band 41 */	 
 CI_DEV_EUTRAN_BAND_TDD_42 , /**< E-UTRAN operating band 42 */	 
 CI_DEV_EUTRAN_BAND_TDD_43 , /**< E-UTRAN operating band 43 */	 
 CI_DEV_EUTRAN_BAND_TDD_44 , /**< E-UTRAN operating band 44 */	 
	 
 // More bands supported...	 
 CI_DEV_EUTRAN_BAND_FDD_65 = 65 ,	 
 CI_DEV_EUTRAN_BAND_FDD_66 ,	 
 CI_DEV_EUTRAN_BAND_FDD_96 ,	 
	 
 CI_DEV_EUTRAN_BAND_NEXTVAL	 
 } _CiDevEutranBand;

typedef UINT8 CiDevEutranBand ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLteCoexReportOptionReq_struct {	 
 CiBoolean enableLteCoexReport ; /**< Enable / disable LTE coexist info report */	 
 } CiDevPrimSetLteCoexReportOptionReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLteCoexReportOptionCnf_struct {	 
 CiDevRc result ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetLteCoexReportOptionCnf;

typedef CiEmptyPrim CiDevPrimGetLteCoexInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetLteCoexInfoCnf_struct {	 
 CiDevRc result ; /**< Result code. \sa CiDevRc. */	 
 CiBoolean isLteOn ; /**< TRUE: current operating on LTE ; FALSE otherwise */	 
 CiDevLteRrcState rrcState ; /**< Current ERRC state: IDLE or CONNECTED */	 
 CiDevEutranBand lteBand ; /**< LTE current operation band */	 
 UINT32 earfcn ; /**< Earfcn */	 
 CiBoolean tddSubframeConfigPresent ;	 
 UINT8 tddUlDlConfig ; /**< TD-LTE UL / DL configuration index: 0 -6 */	 
 UINT8 tddSpecialSubframeConfig ; /**< TD-LTE special subframe configuration index: 0 -9 */	 
 CiBoolean longDRXCyclePresent ;	 
 UINT16 longDRXCycle ; /**< long DRX cycle in ms */	 
 CiBoolean shortDRXCyclePresent ;	 
 UINT16 shortDRXCycle ; /**< short DRX cycle in ms */	 
 } CiDevPrimGetLteCoexInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteCoexInfoInd_struct {	 
 CiBoolean isLteOn ; /**< TRUE: current operating on LTE ; FALSE otherwise */	 
 CiDevLteRrcState rrcState ; /**< Current ERRC state: IDLE or CONNECTED */	 
 CiDevEutranBand lteBand ; /**< LTE current operation band */	 
 UINT32 earfcn ; /**< Earfcn */	 
 CiBoolean tddSubframeConfigPresent ;	 
 UINT8 tddUlDlConfig ; /**< TD-LTE UL / DL configuration index: 0 -6 */	 
 UINT8 tddSpecialSubframeConfig ; /**< TD-LTE special subframe configuration index: 0 -9 */	 
 CiBoolean longDRXCyclePresent ;	 
 UINT16 longDRXCycle ; /**< long DRX cycle in ms */	 
 CiBoolean shortDRXCyclePresent ;	 
 UINT16 shortDRXCycle ; /**< short DRX cycle in ms */	 
 } CiDevPrimLteCoexInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetL2RandFillEnabledReq_struct {	 
 CiBoolean isL2RandomFillBitsEnabled ; /**< TRUE: Enabled ; FALSE: Disabled*/	 
 } CiDevPrimSetL2RandFillEnabledReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetL2RandFillEnabledCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetL2RandFillEnabledCnf;

typedef CiEmptyPrim CiDevPrimGetL2RandFillEnabledReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetL2RandFillEnabledCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiBoolean isL2RandomFillBitsEnabled ; /**< TRUE: Enabled ; FALSE: Disabled*/	 
 } CiDevPrimGetL2RandFillEnabledCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_T323_IND " > */ 
 typedef struct CiDevPrimT323Ind_struct {	 
 CiBoolean t323Valid ;	 
 UINT16 t_323 ;	 
 } CiDevPrimT323Ind;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetMccMncCcReq_struct {	 
 UINT16 countryCode ;	 
 UINT16 operCode ;	 
 UINT8 customerCode [ 3 ] ;	 
 } CiDevPrimSetMccMncCcReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetMccMncCcCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetMccMncCcCnf;

typedef CiEmptyPrim CiDevPrimGetMccMncCcReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetMccMncCcCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT16 countryCode ;	 
 UINT16 operCode ;	 
 UINT8 customerCode [ 3 ] ;	 
 } CiDevPrimGetMccMncCcCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetL1DebugReq_struct {	 
 UINT16 length ;	 
 UINT8 data [ 10 ] ; /**< L1 Debug data sent to L1 */	 
 } CiDevPrimSetL1DebugReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetL1DebugCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetL1DebugCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimL1DebugInfoInd_struct {	 
 UINT16 length ;	 
 UINT8 data [ 256 ] ; /**< L1 Debug info received from L1 */	 
 } CiDevPrimL1DebugInfoInd;

//ICAT EXPORTED ENUM 
 typedef enum CiDEVIMLLOGTYPE_TAG 
 {	 
 CI_DEV_IMLLOG_OFF = 0 ,	 
 CI_DEV_IMLLOG_2SD ,	 
 CI_DEV_IMLLOG_2DDR ,	 
 CI_DEV_IMLLOG_2HSL_BIGBOARD ,	 
 CI_DEV_IMLLOG_2HSL_SMALLBOARD ,	 
 CI_DEV_IMLLOG_2SU_ENABLE ,	 
 CI_DEV_IMLLOG_2SU_DISABLE ,	 
 /*Lilei , CQ00131002 , 20210616 , begin*/	 
 CI_DEV_IPCLOG_DISABLE , /**< DSP IPC log close */	 
 CI_DEV_IPCLOG_ENABLE , /**< DSP IPC log open */	 
 /*Lilei , CQ00131002 , 20210616 , end*/	 
 /*Lilei , CQ00140747 , 20221215 , begin*/	 
 CI_DEV_DIAGLOG_LEVEL , /**< Diag log level */	 
 /*Lilei , CQ00140747 , 20221215 , end*/	 
	 
 CI_DEV_NUM_IMLLOG_CFG	 
 } _CiDevImlLogType;

typedef UINT8 CiDevImlLogType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetImlConfigReq_struct {	 
 CiDevImlLogType imlLogType ; /**< IML log type. */	 
 UINT8 cfgDataLen ; /**< Config data length */	 
 UINT8 cfgData [ 64 ] ; /**< Config data */	 
 } CiDevPrimSetImlConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetImlConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetImlConfigCnf;

typedef CiEmptyPrim CiDevPrimGetImlConfigReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetImlConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiDevImlLogType imlLogType ; /**< IML log type. */	 
 UINT8 cfgDataLen ; /**< Only valid for IML2SU log type ; For other types , it shall be zero */	 
 UINT8 cfgData [ 64 ] ; /**< Config data for IML2SU log type. */	 
 } CiDevPrimGetImlConfigCnf;

//ICAT EXPORTED ENUM 
 enum CiDevPrimMrdOperCmd_enum 
 {	 
 CI_DEV_MRD_CDF_CMD = 0 , /* AT*MRD_CDF no use any more , process by ap*/	 
 CI_DEV_MRD_IMEI_CMD , /* AT*MRD_IMEI*/	 
 CI_DEV_MRD_MEP_CMD , /* AT*MRD_MEP no use any more , process by ap*/	 
 CI_DEV_MRD_MIPS_CMD , /* AT*CP_MIPS no use any more , process by ap*/	 
	 
 CI_DEV_MRD_VSIM_CMD , /* AT*AVSIM */	 
 CI_DEV_MRD_ADC_CMD , /* AT*MRD_ADC */	 
 CI_DEV_MRD_RTPADC_CMD , /* AT*MRD_RTPADC */	 
	 
 CI_DEV_MRD_CMD_NUM	 
 };

typedef UINT8 CiDevMrdType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimCpMrdOperReq_struct 
 {	 
 CiDevMrdType mrdType ; /**< MRD type. \sa CiDevPrimMrdOperCmd_enum. */	 
 UINT8 opType ; /* 0 - set VSIM ; 1 - get VSIM ; 3 - set IMEI */	 
 UINT8 paraNums ; /* Always set to 1 */	 
 UINT8 parameters [ 14 ] [ 64 ] ;	 
 } CiDevPrimCpMrdOperReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimCpMrdOperCnf_struct 
 {	 
 CiDevRc rc ;	 
 CiDevMrdType mrdType ;	 
 UINT8 resultCode ;	 
 UINT16 errCode ;	 
 UINT8 parameters [ ( 1024 -64 ) ] ;	 
 } CiDevPrimCpMrdOperCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimRbTestModeInd_struct 
 {	 
 CiBoolean rbModeStatus ; /**< 0 : RB test mode stop ; 1 : RB test mode start*/	 
 } CiDevPrimRbTestModeInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLteBandOrderReq_struct {	 
 UINT8 numOfLteBands ; /**< Number of the ordered LTE bands */	 
 CiDevEutranBand lteBands [ 20 ] ; /**< LTE bands in order */	 
 } CiDevPrimSetLteBandOrderReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLteBandOrderCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetLteBandOrderCnf;

typedef CiEmptyPrim CiDevPrimGetLteBandOrderReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetLteBandOrderCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT8 numOfLteBands ; /**< Number of the ordered LTE bands */	 
 CiDevEutranBand lteBands [ 20 ] ; /**< LTE bands in order */	 
 } CiDevPrimGetLteBandOrderCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevSalesCode_struct {	 
 UINT8 len ;	 
 UINT8 data [ 8 ] ;	 
 } CiDevSalesCode;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSalesCodeReq_struct {	 
 UINT8 codeNum ;	 
 CiDevSalesCode code [ 10 ] ; /**< Sales code info */	 
 } CiDevPrimSetSalesCodeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSalesCodeCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetSalesCodeCnf;

typedef CiEmptyPrim CiDevPrimGetSalesCodeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSalesCodeCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT8 codeNum ;	 
 CiDevSalesCode code [ 10 ] ; /**< Sales code info */	 
 } CiDevPrimGetSalesCodeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevFeature_struct {	 
 // UINT8 featureId ;	 
 UINT32 featureId ;	 
 UINT32 featureValue ;	 
 } CiDevFeature;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetOperConfigReq_struct {	 
 UINT8 numFeatures ;	 
 CiDevFeature feature [ 32 ] ; /**< Operators config info */	 
 } CiDevPrimSetOperConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetOperConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetOperConfigCnf;

//ICAT EXPORTED ENUM 
 typedef enum CiDevGetOperCfgType_enum 
 {	 
 CI_DEV_GET_ALL_OPER_CFG = 0 ,	 
 CI_DEV_GET_SPECIFIC_OPER_CFG ,	 
	 
 CI_DEV_NUM_GET_OPER_CFG_TYPE	 
 } _CiDevGetOperCfgType;

typedef UINT8 CiDevGetOperCfgType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetOperConfigReq_struct {	 
 CiDevGetOperCfgType type ;	 
 UINT32 featureIdOrIndex ; /**< Feature index when type=0 , specific feature ID when type=1 */	 
 } CiDevPrimGetOperConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetOperConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT16 totalNum ; /**< Total num of feature IDs */	 
 UINT16 validNum ; /**< Valid num of feature IDs of this query */	 
 CiDevFeature feature [ 32 ] ; /**< Operators config info */	 
 } CiDevPrimGetOperConfigCnf;

typedef CiEmptyPrim CiDevPrimGetStatusReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetStatusCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiDevStatus status ; /**< Device status \sa CiDevStatus */	 
 } CiDevPrimGetStatusCnf;

typedef CiEmptyPrim CiDevPrimFactoryResetReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimFactoryResetCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimFactoryResetCnf;

typedef CiEmptyPrim CiDevPrimGetImsUlStatisticReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetImsUlStatisticCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT32 ulThroughPut ; /**< UL throughput of IMS video */	 
 UINT16 ulBler ; /**< UL BLER of IMS video */	 
 UINT8 rsrp ; /**< Value range: 0 ~97 , invalid ( 0xFF ) */	 
 UINT8 rsrq ; /**< Value range: 0 ~34 , invalid ( 0xFF ) */	 
 INT16 snr ; /**< Value range: [ -10~40 ] *256 */	 
 UINT32 l2DiscardPacketsLen ; /**< Length of L2 discarded UL IMS video packet */	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 } CiDevPrimGetImsUlStatisticCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetMedataCommReserveReq_struct {	 
 UINT8 positionToSet ; /*position of Medata comm reserved */	 
 UINT8 setConfigValue ; /*value to set */	 
 } CiDevPrimSetMedataCommReserveReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetMedataCommReserveCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 /*added by taow 20181107 CQ00112754 begin */	 
 UINT8 positionToSet ; /*added by taow 20190218 :position of Medata comm reserved */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevPrimSetMedataCommReserveCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetMedataCommReserveReq_struct {	 
 UINT8 positionToGet ; /*position of Medata comm reserved */	 
 } CiDevPrimGetMedataCommReserveReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetMedataCommReserveCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT8 ConfigValue ; /*value to set */	 
 /*added by taow 20181107 CQ00112754 begin */	 
 UINT8 positionToGet ; /*added by taow 20190218 :position of Medata comm reserved */	 
 /*added by taow 20181107 CQ00112754 end */	 
 } CiDevPrimGetMedataCommReserveCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetCellSelectCfgReq_struct {	 
 INT8 offset_scell ; /**< serving cell , SrxLev + offset , to check whether do neighbor cell measurement */	 
 INT8 offset_scell_qual ; /**< serving cell , Squal + offset , to check whether do neighbor cell measurement */	 
 INT8 offset_ncell_lte ; /**< neighbor cell , LTE RSRP - offset , for cell reselection evaluation */	 
 INT8 offset_ncell_lte_qual ; /**< neighbor cell , LTE RSRQ - offset , for cell reselection evaluation */	 
 INT8 offset_ncell_umts ; /**< neighbor cell , UMTS RSCP - offset , for cell reselection evaluation */	 
 INT8 offset_ncell_umts_qual ; /**< neighbor cell , UMTS EcN0 - offset , for cell reselection evaluation */	 
 INT8 offset_ncell_gsm ; /**< neighbor cell , GSM RSSI - offset , for cell reselection evaluation */	 
 } CiDevPrimSetCellSelectCfgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetCellSelectCfgCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetCellSelectCfgCnf;

typedef UINT8 CiDevCommonCause ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_EVENT_TYPE_AS_ENUM 
 {	 
 CI_DEV_RRC_EVENT_RACH_FAIL = 0 ,	 
 CI_DEV_RRC_EVENT_DL_LOSS_SYNC ,	 
 CI_DEV_RRC_EVENT_SIB_MISSING ,	 
 CI_DEV_RRC_EVENT_RLC_MAX_RETRANS ,	 
 CI_DEV_RRC_EVENT_RRC_RECONFIG_ABNORMAL ,	 
 CI_DEV_RRC_EVENT_RRC_REDIRECT_ABNORMAL ,	 
 CI_DEV_RRC_EVENT_IRAT_RESELECTION_FAIL ,	 
 CI_DEV_RRC_EVENT_RRC_ESTABLISH_SUCCESS ,	 
 CI_DEV_RRC_EVENT_RRC_RELEASE ,	 
	 
 /*Lilei , CQ00144545 , 20230706 , begin*/	 
 CI_DEV_RRC_EVENT_LTE_RESELECTION_SUCCESS ,	 
 CI_DEV_RRC_EVENT_LTE_HANDOVER_SUCCESS ,	 
 CI_DEV_RRC_EVENT_LTE_REDIRECTION_SUCCESS ,	 
 CI_DEV_RRC_EVENT_LTE_MEAS_REPORT_SENT ,	 
 CI_DEV_RRC_EVENT_LTE_RRC_CONN_SETUP_NOT_RECEIVED ,	 
 /*Lilei , CQ00144545 , 20230706 , end*/	 
 /*Lilei , CQ00146454 , 20231023 , begin*/	 
 CI_DEV_RRC_EVENT_LTE_MAC_SR_MAX ,	 
 CI_DEV_RRC_EVENT_LTE_INTRA_HANDOVER_SUCCESS ,	 
 CI_DEV_RRC_EVENT_LTE_INTRA_HANDOVER_FAIL ,	 
 CI_DEV_RRC_EVENT_LTE_INTER_HANDOVER_SUCCESS ,	 
 CI_DEV_RRC_EVENT_LTE_INTER_HANDOVER_FAIL ,	 
 CI_DEV_RRC_EVENT_LTE_INTER_BAND_HANDOVER_SUCCESS ,	 
 CI_DEV_RRC_EVENT_LTE_INTER_BAND_HANDOVER_FAIL ,	 
 CI_DEV_RRC_EVENT_LTE_RESELECTION_FAIL ,	 
 /*Lilei , CQ00146454 , 20231023 , end*/	 
	 
 CI_DEV_GRR_EVENT_RACH_FAIL = 0 , // radio link timeout , downlink signal fail , scell not reach threshhold	 
 CI_DEV_GRR_EVENT_RACH_TIMEOUT , // rach timeout: t3126 , t3146 , t3147	 
 CI_DEV_GRR_EVENT_DCH_MDL_ERROR , // dch mdl error:T200_EXPIRED_N200_TIMES , UNSOLICITED_DM_PERF_RELEASE , SEQ_ERROR_PERF_RELEASE	 
 CI_DEV_GRR_EVENT_PRACH_ERROR , // scell not reach threshhold , radio link timeout , downlink signal fialure , mph error	 
 CI_DEV_GRR_EVENT_PDCH_TIMEOUT , // T3166 , T3168 etc.	 
 CI_DEV_GRR_EVENT_L2_MDL_ERROR , // l2 est mdl error ind	 
 CI_DEV_GRR_EVENT_GSM_HANDOVER_FAIL , // irat CS handover fail	 
 CI_DEV_GRR_EVENT_GSM_IRAT_RESELECTION_FAIL , // irat reselection fail	 
 CI_DEV_GRR_EVENT_UL_TBF_ACTIVE , // ul tbf active	 
 CI_DEV_GRR_EVENT_DL_TBF_ACTIVE , // dl tbf active	 
 CI_DEV_GRR_EVENT_UL_TBF_INACTIVE , // ul tbf release	 
 CI_DEV_GRR_EVENT_DL_TBF_INACTIVE // dl tbf release	 
 } _CiDevEventTypeAs;

typedef UINT8 CiDevEventTypeAs ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_EVENT_TYPE_MM_ENUM 
 {	 
 CI_DEV_GMM_EVENT_NEW_ATTACH_REQ = 0 , /*GPRS ATTACH START*/	 
 CI_DEV_GMM_EVENT_ATTACH_SUCCESS , /*GPRS ATTACH SUCESS*/	 
 CI_DEV_GMM_EVENT_ATTACH_REJECT , /*GPRS ATTACH REJECT*/	 
 CI_DEV_GMM_EVENT_RAU_REJECT , /*GPRS RAU REJECT*/	 
 CI_DEV_GMM_EVENT_SERVICE_REJECT , /*GPRS SERVICE REJECT*/	 
 CI_DEV_GMM_EVENT_AUTHENTICATION_REJECT , /*GPRS AUTHENTICATION REJECT*/	 
 CI_DEV_GMM_EVENT_DETACH_REQ , /*GPRS DETACH REQUEST*/	 
	 
 CI_DEV_MM_EVENT_LU_REJECT , /*LU REJECT*/	 
 CI_DEV_MM_EVENT_AUTHENTICATION_REJECT , /*CS AUTHENTICATION REJECT*/	 
	 
 CI_DEV_EMM_EVENT_NEW_ATTACH_REQ =0 , /*EPS ATTACH START*/	 
 CI_DEV_EMM_EVENT_ATTACH_SUCCESS , /*EPS ATTACH SUCCESS*/	 
 CI_DEV_EMM_EVENT_ATTACH_REJECT , /*EPS ATTACH REJECT*/	 
 CI_DEV_EMM_EVENT_TAU_REJECT , /*EPS TAU REJECT*/	 
 CI_DEV_EMM_EVENT_SERVICE_REJECT , /*EPS SERVICE REJECT*/	 
 CI_DEV_EMM_EVENT_AUTHENTICATION_REJECT , /*EPS AUTHENTICATION REJECT*/	 
 CI_DEV_EMM_EVENT_DETACH_REQ , /*EPS DETACH REQUEST for MT*/	 
 CI_DEV_MM_TAU_ACCEPT , /*EPS TAU ACCEPT*/	 
 CI_DEV_EMM_EXTENDED_ACCESS_BARRED ,	 
 /*Lilei , CQ00144545 , 20230706 , begin*/	 
 CI_DEV_EMM_ATTACH_TIMEOUT , /*EPS ATTACH timeout for all retries*/	 
 CI_DEV_EMM_TAU_TIMEOUT , /*EPS TAU timeout for all retries*/	 
 CI_DEV_EMM_SERVICE_REQ_TIMEOUT /*EPS SERVICE_REQ timeout for all retries*/	 
 /*Lilei , CQ00144545 , 20230706 , end*/	 
	 
 } _CiDevEventTypeMm;

typedef UINT8 CiDevEventTypeMm ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_EVENT_TYPE_SM_ENUM 
 {	 
 CI_DEV_SM_EVENT_PDP_ACT_REJ = 0 , /* PDP activation reject */	 
 CI_DEV_SM_EVENT_PDP_MODIFY_REJ , /* PDP modification reject */	 
 CI_DEV_SM_EVENT_PDP_DEACT_REJ , /* PDP deactivation reject */	 
 /*Lilei , CQ00144545 , 20230706 , begin*/	 
 CI_DEV_SM_EVENT_PDP_ACT_IGNORED /* PDP activation ignored */	 
 /*Lilei , CQ00144545 , 20230706 , end*/	 
 } _CiDevEventTypeSm;

typedef UINT8 CiDevEventTypeSm ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonGsmCellInfo_struct 
 {	 
 UINT16 cellId ;	 
 UINT16 arfcn ;	 
 UINT8 bsic ;	 
 } CiDevCommonGsmCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonUmtsCellInfo_struct 
 {	 
 UINT32 cellId ;	 
 UINT16 uArfcn ;	 
 UINT16 psc ;	 
 } CiDevCommonUmtsCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonLteCellInfo_struct 
 {	 
 UINT32 cellId ;	 
 UINT32 euArfcn ;	 
 UINT16 phyCellId ;	 
 } CiDevCommonLteCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonReportAS_struct 
 {	 
 CiDevEventTypeAs event ;	 
 CiDevEngModeNetwork networkMode ;	 
 /*Lilei , CQ00144545 , 20230706 , begin*/	 
 CiDevCommonLteCellInfo currentLteCell ;	 
 CiDevCommonLteCellInfo sourceLteCell ; /* Only valid for HO / Reselection / Redirect etc. */	 
 UINT8 rsrpOfsourceCell ;	 
 UINT8 rsrqOfsourceCell ;	 
 UINT8 rsrpOfcurrentCell ;	 
 UINT8 rsrqOfcurrentCell ;	 
 /*Lilei , CQ00144545 , 20230706 , end*/	 
 } CiDevCommonReportAS;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonReportMm_struct 
 {	 
 CiDevCommonCause cause ; /* For attach initiation or success , there ' s no cause ( value 0 ) */	 
 CiDevEventTypeMm event ;	 
 /*Lilei , CQ00127026 , 20201222 , begin*/	 
 CiDevEngModeNetwork network ; /* 0 :GSM , 1 :UMTS */	 
 CiDevCommonGsmCellInfo gsmCellInfo ;	 
 CiDevCommonUmtsCellInfo umtsCellInfo ;	 
 /*Lilei , CQ00127026 , 20201222 , end*/	 
 CiDevCommonCause remapCause ; /*CQ00140020 , lilei , 20221205 */	 
 } CiDevCommonReportMm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonReportGmm_struct 
 {	 
 CiDevCommonCause cause ;	 
 CiDevEventTypeMm event ;	 
 /*Lilei , CQ00127026 , 20201222 , begin*/	 
 CiDevEngModeNetwork network ; /* 0 :GSM , 1 :UMTS */	 
 CiDevCommonGsmCellInfo gsmCellInfo ;	 
 CiDevCommonUmtsCellInfo umtsCellInfo ;	 
 /*Lilei , CQ00127026 , 20201222 , end*/	 
 CiDevCommonCause remapCause ; /*CQ00140020 , lilei , 20221205 */	 
 } CiDevCommonReportGmm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonReportSm_struct 
 {	 
 CiDevCommonCause cause ;	 
 CiDevEventTypeSm event ;	 
 } CiDevCommonReportSm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonReportEmm_struct 
 {	 
 CiDevCommonCause cause ;	 
 CiDevEventTypeMm event ;	 
 /*Lilei , CQ00127026 , 20201222 , begin*/	 
 CiDevCommonLteCellInfo lteCellInfo ;	 
 /*Lilei , CQ00127026 , 20201222 , end*/	 
 CiDevCommonCause remapCause ; /*CQ00140020 , lilei , 20221205 */	 
 } CiDevCommonReportEmm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonReportEsm_struct 
 {	 
 CiDevCommonCause cause ;	 
 CiDevEventTypeSm event ;	 
 /*Lilei , CQ00144545 , 20230706 , begin*/	 
 CiDevCommonLteCellInfo lteCellInfo ;	 
 /*Lilei , CQ00144545 , 20230706 , end*/	 
 } CiDevCommonReportEsm;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_COMMON_REPORT_ENUM 
 {	 
 CI_DEV_COMMON_REPORT_AS ,	 
 CI_DEV_COMMON_REPORT_MM ,	 
 CI_DEV_COMMON_REPORT_GMM ,	 
 CI_DEV_COMMON_REPORT_SM ,	 
 CI_DEV_COMMON_REPORT_EMM ,	 
 CI_DEV_COMMON_REPORT_ESM ,	 
	 
 CI_DEV_NUM_COMMON_REPORT_TYPES	 
 } _CiDevCommonReportType;

typedef UINT8 CiDevCommonReportType ;
//ICAT EXPORTED UNION 
 typedef union CiDevCommonReport_union 
 {	 
 CiDevCommonReportAS as ; /* AS layer reject info */	 
 CiDevCommonReportMm mm ; /* MM reject info */	 
 CiDevCommonReportGmm gmm ; /* GMM reject info */	 
 CiDevCommonReportSm sm ; /* SM reject info */	 
 CiDevCommonReportEmm emm ; /* EMM reject info */	 
 CiDevCommonReportEsm esm ; /* ESM reject info */	 
 } CiDevCommonReport;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimCommonReportInd_struct 
 {	 
 CiDevCommonReportType type ;	 
 CiDevCommonReport info ;	 
 } CiDevPrimCommonReportInd;

//ICAT EXPORTED ENUM 
 typedef enum CiDevCmdType_TAG {	 
 /*For #3748 roaming forbiden plmn */	 
 CI_DEV_CMD_SET = 0 , /**< set */	 
 CI_DEV_CMD_DELETE = 1 , /**< Delete one or limit per time*/	 
	 
 /*For #46621 forbiden plmn */	 
 CI_DEV_CMD_DELETE_SIM = 2 , /**< Delete SIM card FPLMN*/	 
 CI_DEV_CMD_DELETE_NVM = 3 , /**< Delete NVM FPLMN*/	 
 CI_DEV_CMD_DELETE_ALL = 4 , /**< Delete SIM card and NVM FPLMN*/	 
	 
 CI_DEV_CMD_NUM ,	 
 } _CiDevCmdType;

typedef UINT8 CiDevCmdType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetRoamingForbidenPlmnReq_struct {	 
 CiDevCmdType cmdType ;	 
 UINT8 numOfPlmnIdentity ;	 
 CiDevLtePlmnIdentity plmnIdentityList [ 10 ] ;	 
 } CiDevPrimSetRoamingForbidenPlmnReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetRoamingForbidenPlmnCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetRoamingForbidenPlmnCnf;

typedef CiEmptyPrim CiDevPrimGetRoamingForbidenPlmnReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetRoamingForbidenPlmnCnf_struct {	 
 CiDevRc rc ;	 
 UINT8 numOfPlmnIdentity ;	 
 CiDevLtePlmnIdentity plmnIdentityList [ 10 ] ;	 
 } CiDevPrimGetRoamingForbidenPlmnCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevBlackCellId_struct 
 {	 
 UINT32 afrcn ; /**< LTE : EARFCN ; URTAN: UARFCN ; GSM: ARFCN */	 
 UINT16 cellId ; /**< LTE : PCI ; URTAN: PSC ; GSM: BSCI */	 
 } CiDevBlackCellId;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevBlackCellList_struct {	 
 UINT8 numOfBlackCell ;	 
 CiDevBlackCellId blackCellIdList [ 10 ] ;	 
 } CiDevLteBlackCellList , CiDevUmtsBlackCellList , CiDevGsmBlackCellList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetBlackCellReq_struct {	 
 CiDevCmdType cmdType ;	 
 CiDevLteBlackCellList LteBlackCellList ;	 
 CiDevUmtsBlackCellList UmtsBlackCellList ;	 
 CiDevGsmBlackCellList GsmBlackCellList ;	 
 } CiDevPrimSetBlackCellReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetBlackCellCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetBlackCellCnf;

typedef CiEmptyPrim CiDevPrimGetBlackCellReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetBlackCellCnf_struct {	 
 CiDevRc rc ;	 
 CiDevLteBlackCellList LteBlackCellList ;	 
 CiDevUmtsBlackCellList UmtsBlackCellList ;	 
 CiDevGsmBlackCellList GsmBlackCellList ;	 
 } CiDevPrimGetBlackCellCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetFeatureConfigReq_struct {	 
 CiDevFeature feature ; /**< Features config info */	 
 } CiDevPrimSetFeatureConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetFeatureConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiDevFeature feature ; /**< Features config info */	 
 } CiDevPrimSetFeatureConfigCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetFeatureConfigReq_struct {	 
 UINT32 featureId ; /**< Feature index. 0xFF indicates all feauters */	 
 } CiDevPrimGetFeatureConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetFeatureConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT16 numFeatures ; /**< Num of feature IDs */	 
 CiDevFeature feature [ 80 ] ; /**< Features config info */	 
 } CiDevPrimGetFeatureConfigCnf;

//ICAT EXPORTED ENUM 
 typedef enum CiDevPdpType_enum 
 {	 
 PDP_TYPE_IPV4 = 0x1 ,	 
 PDP_TYPE_IPV6 = 0x2 ,	 
 PDP_TYPE_IPV4V6 = 0x3 ,	 
 PDP_TYPE_UNUSED = 0x4	 
 } _CiDevPdpType;

typedef UINT8 CiDevPdpType ;
//ICAT EXPORTED ENUM 
 typedef enum CiDevSetRoamAction_enum 
 {	 
 CI_DEV_ROAM_ADD_UPDATE = 0 ,	 
 CI_DEV_ROAM_DELETE = 1 ,	 
	 
 CI_DEV_NUM_ROAM_ACTIONS	 
 } _CiDevSetRoamAction;

typedef UINT8 CiDevSetRoamAction ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevRoamConfig_struct {	 
 CiDevLtePlmnIdentity plmn ;	 
 CiDevPdpType attachPdpType ;	 
 } CiDevRoamConfig;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetRoamConfigReq_struct {	 
 CiDevSetRoamAction action ;	 
 CiDevRoamConfig config ;	 
 } CiDevPrimSetRoamConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetRoamConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetRoamConfigCnf;

typedef CiEmptyPrim CiDevPrimGetRoamConfigReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetRoamConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT16 num ; /**< Num of configs */	 
 CiDevRoamConfig config [ 10 ] ; /**< Attach PDP type info */	 
 } CiDevPrimGetRoamConfigCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_CELL_DECODE_RC_ENUM 
 {	 
 CI_DEV_CELL_DECODE_NONE = 0 ,	 
 CI_DEV_CELL_DECODE_SUCCESS = 1 ,	 
 CI_DEV_CELL_DECODE_FAIL = 2 ,	 
	 
 CI_DEV_NUM_CELL_DECODE_RC	 
 } _CiDevCellDecodeRc;

typedef UINT8 CiDevCellDecodeRc ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_CELL_TYPE_ENUM 
 {	 
 CI_DEV_CELL_TYPE_SEARCH = 0 , /**< Cell result from search */	 
 CI_DEV_CELL_TYPE_SVC = 1 , /**< Serving cell */	 
 CI_DEV_CELL_TYPE_NEIGHBOR = 2 , /**< Neighbor cell. Only for GSM */	 
 CI_DEV_CELL_TYPE_INTRA_FREQ = 3 ,	 
 CI_DEV_CELL_TYPE_INTER_FREQ = 4 ,	 
 CI_DEV_CELL_TYPE_INTERRAT_GSM = 5 ,	 
 CI_DEV_CELL_TYPE_INTERRAT_UMTS = 6 ,	 
 CI_DEV_CELL_TYPE_INTERRAT_LTE = 7 ,	 
	 
 CI_DEV_NUM_CELL_TYPE	 
 } _CiDevCellType;

typedef UINT8 CiDevCellType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmCellInfoItem_struct 
 {	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT8 bsic ; /**< Base transceiver station identity code ; range 0 h-3Fh ( 6 bits ) ; 0xFF means not present */	 
 INT16 rssi ; /**< GSM carrier RSSI. rssi = rxLevel-110 ; 0x7FFF means not present */	 
 INT16 sinr ; /**< SINR ; 0x7FFF means not present */	 
 CiDevCellDecodeRc decodeRc ; /**< Cell decode return code */	 
 CiDevCellType cellType ; /**< Which type of cell */	 
 } CiDevGsmCellInfoItem;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsCellInfoItem_struct 
 {	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT16 psc ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 INT16 rssi ; /**< UTRA carrier RSSI ; 0x7FFF means not present */	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power ; 0x7FFF means not present */	 
 INT16 ecN0 ; /**< CPICH Ec / N0 , only valid for FDD ; 0x7FFF means not present */	 
 INT16 sinr ; /**< SINR ; 0x7FFF means not present */	 
 CiDevCellDecodeRc decodeRc ; /**< Cell decode return code*/	 
 CiDevCellType cellType ; /**< Which type of cell */	 
 } CiDevUmtsCellInfoItem;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteCellInfoItem_struct 
 {	 
 UINT32 earfcn ; /**< Eutra absolute radio frequency channel number */	 
 UINT16 physCellId ; /**< Physical cell identity */	 
 INT16 rssi ; /**< EUTRA carrier RSSI ; 0x7FFF means not present */	 
 INT16 rsrp ; /**< Reference signal receive power ; 0x7FFF means not present */	 
 INT16 rsrq ; /**< Reference signal receive quality ; 0x7FFF means not present */	 
 INT16 sinr ; /**< SINR ; 0x7FFF means not present */	 
 CiDevCellDecodeRc decodeRc ; /**< Cell decode return code*/	 
 CiDevCellType cellType ; /**< Which type of cell */	 
 } CiDevLteCellInfoItem;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimCellsInfoInd_struct 
 {	 
 CiDevEngModeNetwork network ; /**< Current network type ( GSM / UMTS / LTE ) */	 
 UINT8 numGsmCells ; /**< Number of GSM cells */	 
 CiDevGsmCellInfoItem gsmCellInfo [ 33 ] ; /**< GSM cells info */	 
 UINT8 numUmtsCells ; /**< Number of UMTS cells */	 
 CiDevUmtsCellInfoItem umtsCellInfo [ 33 ] ; /**< UMTS cells info */	 
 UINT8 numLteCells ; /**< Number of LTE cells */	 
 CiDevLteCellInfoItem lteCellInfo [ 33 ] ; /**< LTE cells info */	 
 /*Lilei , CQ00135655 , 20220224 , begin*/	 
 /* Parameters only valid for GSM , begin */	 
 UINT8 radioLinkTimeout ; /**< RADIO_LINK_TIMEOUT */	 
 UINT8 counterS ; /**< Radio link counter S. Invalid if radioLinkTimeout=0 */	 
 UINT8 dscInitValue ; /**< Initial value of downlink signaling failure counter */	 
 UINT8 dsfCount ; /**< Downlink signaling failure counter. Invalid if dscInitValue=0 */	 
 CiDevEngModeState mode ; /**< Current mode ( idle / dedicated ) \sa CiDevEngModeState */	 
 CiBoolean isInVoiceCall ; /**< Whether in a voice call */	 
 /* Parameters only valid for GSM , end */	 
 /*Lilei , CQ00135655 , 20220224 , end*/	 
 } CiDevPrimCellsInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetDrxDynamicAdujustReq_struct {	 
 CiBoolean dynamicFlag ; /**< TRUE: enable dynamic adjust , FALSE: disable */	 
 INT16 rsrpTh ; /**< Threshold of RSRP , range [ -144 , -44 ] , default -105 */	 
 INT16 snrTh ; /**< Threshold of SNR , range [ -20 , 30 ] , default 5 */	 
 } CiDevPrimSetDrxDynamicAdujustReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetDrxDynamicAdujustCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetDrxDynamicAdujustCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimConfigHwPsmProfileReq_struct {	 
 CiBoolean hwPsmEnable ; /**< if enable for hardware PSM feature. */	 
	 
 UINT32 psmWindowThreshold ; /**< threshold for PSM windown to check T3412 or eDRX length */	 
 UINT8 eDrxToT3324Threshold ; /**< threshold for eDRX when both PSM / eDRX enabled */	 
 } CiDevPrimConfigHwPsmProfileReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimConfigHwPsmProfileCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimConfigHwPsmProfileCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetAntennaTunerParamReq_struct {	 
 UINT8 paramId ; /**< ID of the set of antenna tuner parameters */	 
 } CiDevPrimSetAntennaTunerParamReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetAntennaTunerParamCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetAntennaTunerParamCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimPagingFailureInd_struct 
 {	 
 UINT8 reserve ;	 
 } CiDevPrimPagingFailureInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevForbidenPlmnListDataSim_struct {	 
	 
 CiDevLtePlmnIdentity fPlmnList [ 8 ] ; /**<the array is used in GET response*/	 
 UINT8 numFPlmn ; /**< set:MAX num is 1 ;	 
 * del: 0 del all , 1 del the PLMN in forbidenPlmnList [ 0 ]	 
 * get: max num is 8 CI_DEV_NUM_FORBIDDEN_PLMN_SIM*/	 
 UINT8 reserved1 [ 3 ] ;	 
 } CiDevForbidenPlmnListDataSim;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevForbidenPlmnListDataNvm_struct {	 
 CiDevLtePlmnIdentity hPlmnList [ 10 ] ;	 
 CiDevLtePlmnIdentity fPlmnList [ 10 ] ;	 
 UINT8 NumHPlmn ;	 
 UINT8 numFPlmn ;	 
 UINT8 currentIndex ; /**<currentIndex is used in GET response*/	 
 UINT8 totalNum ; /**<totalNum is used in GET responsenum of imsiPlmn stored in UE */	 
 UINT8 reserved1 [ 3 ] ;	 
 } CiDevForbidenPlmnListDataNvm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEhplmnList_struct 
 {	 
 CiDevLtePlmnIdentity imsiPlmn ;	 
 CiDevLtePlmnIdentity eHplmnList [ 10 ] ;	 
 UINT8 numEhplmn ;	 
 UINT8 currentIndex ; /**<currentIndex is used in GET response*/	 
 UINT8 totalNum ; /**<totalNum is used in GET responsenum of imsiPlmn stored in UE */	 
 UINT8 reserved1 [ 3 ] ;	 
	 
	 
 } CiDevEhplmnListData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevBarredPlmnData_Tag 
 {	 
 UINT8 plmnNum ;	 
 UINT8 reserved1 [ 3 ] ;	 
 CiDevLtePlmnIdentity BarredPlmnList [ 16 ] ; /** all PLMN will be barred in the list , including HPLMN */	 
 } CiDevBarredPlmnData;

//ICAT EXPORTED ENUM 
 typedef enum CiDevRemapProcedureTag 
 {	 
 CI_DEV_REMAP_GMM_ATTCH_RAU_REJ = 0 ,	 
 CI_DEV_REMAP_GMM_SERVICE_REJ ,	 
 CI_DEV_REMAP_GMM_DETACH ,	 
 CI_DEV_REMAP_MM_LU_REJ ,	 
 CI_DEV_REMAP_CM_SERVICE_REJ ,	 
 CI_DEV_REMAP_MM_ABORT ,	 
 CI_DEV_REMAP_EMM_ATTACH_TAU_REJ ,	 
 CI_DEV_REMAP_EMM_SERVICE_REJ ,	 
 CI_DEV_REMAP_EMM_DETACH ,	 
 CI_DEV_REMAP_MAX_PROC	 
	 
 } _CiDevRemapProcedure;

typedef UINT32 CiDevRemapProcedure ;
//ICAT EXPORTED ENUM 
 typedef enum CiDevRemapCauseTag 
 {	 
 CI_DEV_REMAP_CAUSE_0 = 0 ,	 
 CI_DEV_REMAP_CAUSE_1 ,	 
 CI_DEV_REMAP_CAUSE_2 ,	 
 CI_DEV_REMAP_CAUSE_3 ,	 
 CI_DEV_REMAP_CAUSE_4 ,	 
 CI_DEV_REMAP_CAUSE_5 ,	 
 CI_DEV_REMAP_CAUSE_6 ,	 
 CI_DEV_REMAP_CAUSE_7 ,	 
 CI_DEV_REMAP_CAUSE_8 ,	 
 CI_DEV_REMAP_CAUSE_9 ,	 
 CI_DEV_REMAP_CAUSE_10 ,	 
 CI_DEV_REMAP_CAUSE_11 ,	 
 CI_DEV_REMAP_CAUSE_12 ,	 
 CI_DEV_REMAP_CAUSE_13 ,	 
 CI_DEV_REMAP_CAUSE_14 ,	 
 CI_DEV_REMAP_CAUSE_15 ,	 
 CI_DEV_REMAP_CAUSE_16 ,	 
 CI_DEV_REMAP_CAUSE_17 ,	 
 CI_DEV_REMAP_CAUSE_18 ,	 
 CI_DEV_REMAP_CAUSE_19 ,	 
 CI_DEV_REMAP_CAUSE_20 ,	 
 CI_DEV_REMAP_CAUSE_21 ,	 
 CI_DEV_REMAP_CAUSE_22 ,	 
 CI_DEV_REMAP_CAUSE_23 ,	 
 CI_DEV_REMAP_CAUSE_24 ,	 
 CI_DEV_REMAP_CAUSE_25 ,	 
 CI_DEV_REMAP_CAUSE_26 ,	 
 CI_DEV_REMAP_CAUSE_27 ,	 
 CI_DEV_REMAP_CAUSE_28 ,	 
 CI_DEV_REMAP_CAUSE_29 ,	 
 CI_DEV_REMAP_CAUSE_30 ,	 
 CI_DEV_REMAP_CAUSE_31 ,	 
 CI_DEV_REMAP_CAUSE_32 ,	 
 CI_DEV_REMAP_CAUSE_33 ,	 
 CI_DEV_REMAP_CAUSE_34 ,	 
 CI_DEV_REMAP_CAUSE_35 ,	 
 CI_DEV_REMAP_CAUSE_36 ,	 
 CI_DEV_REMAP_CAUSE_37 ,	 
 CI_DEV_REMAP_CAUSE_38 ,	 
 CI_DEV_REMAP_CAUSE_39 ,	 
 CI_DEV_REMAP_CAUSE_40 ,	 
 CI_DEV_REMAP_CAUSE_41 ,	 
 CI_DEV_REMAP_CAUSE_42 ,	 
 CI_DEV_REMAP_CAUSE_95 = 95 ,	 
 CI_DEV_REMAP_CAUSE_96 ,	 
 CI_DEV_REMAP_CAUSE_97 ,	 
 CI_DEV_REMAP_CAUSE_98 ,	 
 CI_DEV_REMAP_CAUSE_99 ,	 
 CI_DEV_REMAP_CAUSE_100 ,	 
 CI_DEV_REMAP_CAUSE_101 ,	 
 CI_DEV_REMAP_CAUSE_111 = 111 ,	 
 CI_DEV_REMAP_CAUSE_NO_CAUSE= 0xFE ,	 
 CI_DEV_REMAP_MAX_CAUSE = 255	 
 } _CiDevRemapCause;

typedef UINT8 CiDevRemapCause ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevRemapCauseEntryTag 
 {	 
 CiDevRemapCause originalCause ;	 
 CiDevRemapCause remapHPLMNcause ;	 
 CiDevRemapCause remapVPLMNcause ;	 
	 
 UINT8 reserved [ 5 ] ;	 
 } CiDevRemapCauseEntry;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevRemapCauseProEntryTag 
 {	 
 CiDevRemapProcedure procedureId ;	 
 CiDevRemapCauseEntry remapCauseEntry [ 10 ] ;	 
 UINT8 numCauseRemap ;	 
 UINT8 reserved [ 3 ] ;	 
 } CiDevRemapCauseProEntry;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevRemapCauseData_struct {	 
 CiDevRemapCauseProEntry remapCauseProEntry [ 10 ] ;	 
 UINT8 numCausePro ;	 
 UINT8 reserved [ 3 ] ;	 
 } CiDevRemapCauseData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevRejectCounterTag 
 {	 
 CiDevRemapCause rejectCause ;	 
 INT8 rejectHplmnCounter ;	 
 INT8 rejectVplmnCounter ;	 
 INT8 reserved [ 1 ] ;	 
 } CiDevRejectCounter;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevRejectCounterData_struct {	 
 CiDevRejectCounter remapRejectCounter [ 10 ] ;	 
 INT8 numRejectCounter ;	 
 INT8 reserved [ 3 ] ;	 
 } CiDevRejectCounterData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevMultipleGsmBandTag 
 {	 
 UINT8 gsmMultiple ;	 
 UINT8 dcsMultiple ;	 
 UINT8 pcsMultiple ;	 
 UINT8 reserved ;	 
 } CiDevMultipleGsmBand;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevRplmnInfoTag 
 {	 
 Boolean lastEpsRplmnIsValid ;	 
 Boolean lastRplmnIsValid ;	 
 CiDevEngModeNetwork lastRplmnNwMode ;	 
 CiDevLtePlmnIdentity lastEpsRplmn ;	 
 CiDevLtePlmnIdentity lastRplmn ;	 
 } CiDevRplmnInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPlmnId_struct 
 {	 
 UINT16 mcc ;	 
 // 2 -3 digits of MNC	 
 UINT16 mnc ;	 
 // Length of MNC , value range ( 2 , 3 )	 
 UINT8 lenOfMnc ;	 
 UINT8 dummy ;	 
 } CiDevPlmnId;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevWhiteCellId_struct 
 {	 
 UINT32 xArfcn ; /**< LTE : EARFCN ; URTAN: UARFCN ; GSM: ARFCN */	 
 UINT16 xCellId ; /**< LTE : PCI ; URTAN: PSC ; GSM: BSIC */	 
 UINT16 dummy0 ;	 
 UINT32 dummy1 [ 6 ] ;	 
 } CiDevWhiteCellId;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevWhiteCellList_struct {	 
 CiDevPlmnId plmn ;	 
 UINT8 maxNumOfWhiteCell ;	 
 UINT8 numOfWhiteCell ;	 
 CiDevWhiteCellId whiteCellList [ 10 ] ;	 
 } CiDevLteWhiteCellList , CiDevUmtsWhiteCellList , CiDevGsmWhiteCellList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevWhiteCellListInfoTag 
 { CiBoolean isEnable ; /**< TRUE : Enable ; FALSE: DISABLE */	 
 UINT8 dummy [ 3 ] ;	 
 CiDevLteWhiteCellList lteWhiteCellList ;	 
 CiDevUmtsWhiteCellList umtsWhiteCellList ;	 
 CiDevGsmWhiteCellList gsmWhiteCellList ;	 
 } CiDevWhiteCellListInfo;

//ICAT EXPORTED ENUM 
 typedef enum CiDevFeatureId_TAG {	 
 CI_DEV_FT_BAND_FREQ_BASE = 0 ,	 
 CI_DEV_FT_BAND_ORDER = 1 ,	 
 CI_DEV_FT_FORBIDDEN_PLMN_SIM = 2 ,	 
 CI_DEV_FT_FORBIDDEN_PLMN_NVM = 3 ,	 
 CI_DEV_FT_EHPLMN = 4 ,	 
 /*add by taow 20220829 CQ00138615 begin*/	 
 CI_DEV_FT_BARRED_PLMN = 5 ,	 
 /*add by taow 20220829 CQ00138615 end*/	 
 CI_DEV_FT_MEAS_REPORT_CFG = 6 , /*Lilei , CQ00138904 , 20220916 */	 
 /*add by taow CQ00139968 20221108 begin */	 
 CI_DEV_FT_REMAP_CAUSE ,	 
 CI_DEV_FT_REJECT_COUNTER ,	 
 /*add by taow CQ00139968 20221108 end */	 
 /*add by taow 20221215 begin*/	 
 CI_DEV_FT_MULTIPLE_GSM_BAND ,	 
 /*add by taow 20221215 end*/	 
 /*add by taow 20230720 CQ00144858 begin*/	 
 CI_DEV_FT_RPLMN_INFO ,	 
 /*add by taow 20230720 CQ00144858 end*/	 
 /*add by taow 20231110 CQ00146922 begin*/	 
 CI_DEV_FT_WHITE_CELL_LIST ,	 
 /*add by taow 20231110 CQ00146922 end*/	 
 CI_DEV_FT_NUM ,	 
	 
 CI_DEV_FT_MAX = 65535	 
 } _CiDevFeatureId;

typedef UINT16 CiDevFeatureId ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevBandOffset_Tag 
 {	 
 UINT8 bandId ;	 
 UINT8 reserved1 [ 3 ] ;	 
 UINT32 bandFreqLow ;	 
 UINT32 bandFreqHigh ;	 
 } CiDevBandFreq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAbmmBandOffsetData_Tag 
 {	 
 UINT8 bandFreqNum ;	 
 UINT8 reserved1 [ 3 ] ;	 
 CiDevBandFreq bandFreq [ 20 ] ;	 
 } CiDevBandFreqBaseData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteSetBandOrderReq_struct {	 
 UINT8 lteBandNum ;	 
 UINT8 lteBandList [ 20 ] ;	 
 UINT8 reserved1 [ 3 ] ;	 
 } CiDevLteSetBandOrderData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevMeasReportConfigData_struct {	 
 INT8 offset_scell ; /*serving cell , LTE RSRP - offset , for check A1~A5 MR event Condition.*/	 
 INT8 offset_ncell_lte ; /*LTE ncell , LTE RSRP - offset , for check A1~A5 MR event Condition.*/	 
 } CiDevMeasReportConfigData;

//ICAT EXPORTED UNION:_CiDevFeatureId 
 typedef union CiDevCommonFeatureData_union 
 {	 
 CiDevBandFreqBaseData bandFreqBase ;	 
 CiDevLteSetBandOrderData lteSetBandOrder ;	 
 /* add by taow 20220228 CQ00135794 end*/	 
 CiDevForbidenPlmnListDataSim forbidenPlmnDataSim ;	 
 CiDevForbidenPlmnListDataNvm forbidenPlmnDataNvm ;	 
 CiDevEhplmnListData ehplmnData ;	 
 /* add by taow 20220228 CQ00135794 end*/	 
	 
 /*add by taow 20220829 CQ00138615 begin*/	 
 CiDevBarredPlmnData barredPlmnData ; /** all PLMN will be barred in the list , including HPLMN */	 
 /*add by taow 20220829 CQ00138615 end*/	 
 CiDevMeasReportConfigData measReportConfig ; /*Lilei , CQ00138904 , 20220916 */	 
 /*add by taow 20221108 CQ00139968 begin */	 
 CiDevRemapCauseData remapCauseData ;	 
 CiDevRejectCounterData rejectCounterData ;	 
 /*add by taow 20221108 CQ00139968 end */	 
 /*add by taow 20221215 begin*/	 
 CiDevMultipleGsmBand multipleGsmBand ;	 
 /*add by taow 20221215 end*/	 
 /*add by taow 20230720 CQ00144858 begin*/	 
 CiDevRplmnInfo rplmnInfo ;	 
 /*add by taow 20230720 CQ00144858 end*/	 
 /*add by taow 20231110 CQ00146922 begin*/	 
 CiDevWhiteCellListInfo whiteCellListInfo ;	 
 /*add by taow 20231110 CQ00146922 end*/	 
 UINT8 dummy [ 1024 ] ;	 
 } CiDevCommonFeatureData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetCommonFeatureReq_struct {	 
 CiDevCmdType cmdType ; /*@ITEM_DESC@ 0 : Set or modify CMD 1 : Del CMD*/	 
 /** featureId == CI_DEV_FT_BAND_ORDER cmdType only use CI_DEV_CMD_SET */	 
	 
 UINT8 reserved ;	 
 CiDevFeatureId featureId ; /*@ITEM_DESC@ 0 : Set Band Freq Base 1 : Set lte Band Order 2 :FPlmn sim 3 :FPLMN nvm , 4 :ehplmn*/	 
 CiDevCommonFeatureData commonFtData ;	 
 } CiDevPrimSetCommonFeatureReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetCommonFeatureCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiDevFeatureId featureId ; /*@ITEM_DESC@ 0 : Set Band Freq Base 1 : Set lte Band Order 2 :FPlmn sim 3 :FPLMN nvm , 4 :ehplmn*/	 
 CiDevCommonFeatureData commonFtData ;	 
 } CiDevPrimSetCommonFeatureCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetCommonFeatureReq_struct {	 
 CiDevFeatureId featureId ; /*@ITEM_DESC@ 0 : Set Band Freq Base 1 : Set lte Band Order 2 :FPlmn sim 3 :FPLMN nvm , 4 :ehplmn */	 
 UINT32 index ;	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
	 
 } CiDevPrimGetCommonFeatureReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetCommonFeatureCnf_struct {	 
 CiDevRc rc ;	 
 CiDevFeatureId featureId ; /*@ITEM_DESC@ 0 : Set Band Freq Base 1 : Set lte Band Order 2 :FPlmn sim 3 :FPLMN nvm , 4 :ehplmn*/	 
 CiDevCommonFeatureData commonFtData ;	 
	 
 } CiDevPrimGetCommonFeatureCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_TX_RX_OPTION_TAG {	 
 CI_DEV_TX_START = 0 ,	 
 CI_DEV_RX_START ,	 
 CI_DEV_TX_RX_STOP ,	 
	 
 CI_DEV_NUM_TX_RX	 
 } _CiDevTxRxOption;

typedef UINT8 CiDevTxRxOption ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetNstTxRxReq_struct {	 
 CiDevTxRxOption option ; /**< Option. \sa CiDevTxRxOption */	 
 CiDevEngModeNetwork networkMode ; /**< 0 : GSM ; 1 : UMTS ; 2 : LTE */	 
 UINT8 band ; /**< GSM: 1 -PGSM , 2 -DCS , 4 -PCS , 8 -EGSM , 16 -GSM450 , 32 -GSM480 , 64 -GSM850 ; */	 
 /* WCDMA: 1 -BAND1 , 2 -BAND2 , ... , 14 :BAND14 ; LTE: 1 -BAND1 , 2 -BAND2... */	 
 UINT32 arfcn ;	 
 INT16 power ; /**< Tx or Rx power. For GSM TX , range [ 0 , 1 ] , otherwise in 0.100000 Dbm unit. */	 
 UINT8 slot ; /**< GSM TX slot. Range [ 1 , 4 ] . */	 
 UINT8 bandwidth ; /**< LTE bandwidth. Range [ 0 , 5 ] . */	 
	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 UINT32 reserved5 ;	 
 UINT32 reserved6 ;	 
 UINT32 reserved7 ;	 
 UINT32 reserved8 ;	 
 } CiDevPrimSetNstTxRxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetNstTxRxCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 INT16 rssiPri ; /**< The Rssi value of primary antenna to be returned for RX mode. */	 
 INT16 rssiSec ; /**< The Rssi value of secondary antenna to be returned for RX mode. Only used for LTE now. */	 
	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 } CiDevPrimSetNstTxRxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSimSlotReq_struct {	 
 UINT8 simSlot ; /**< 0 - sim slot 1 ; 1 - sim slot 2 */	 
 UINT8 reserved [ 3 ] ;	 
 } CiDevPrimSetSimSlotReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSimSlotCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 } CiDevPrimSetSimSlotCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSimSlotReq_struct {	 
 UINT8 reserved [ 4 ] ;	 
 } CiDevPrimGetSimSlotReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSimSlotCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
	 
 UINT8 simSlot ; /**< 0 - sim slot 1 ; 1 - sim slot 2 */	 
 UINT8 reserved [ 3 ] ;	 
 } CiDevPrimGetSimSlotCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmServingCellInfo_v0002_struct 
 {	 
 UINT8 rxSigLevel ; /**< Receive signal level [ range: 0 h-3Fh ] */	 
 UINT8 rxSigLevelFull ; /**< Receive signal level accessed over all TDMA frames [ range: 0 h-3Fh ] */	 
 UINT8 rxSigLevelSub ; /**< Receive signal level accessed over subset of TDMA frames [ range: 0 h-3Fh ] */	 
 UINT8 rxQualityFull ; /**< Receive quality accessed over all TDMA frames [ range: 0 -7 ] */	 
 UINT8 rxQualitySub ; /**< Receive quality accessed over subset of TDMA frames [ range: 0 -7 ] */	 
 UINT8 rac ; /**< Routing area code [ range: 0 -1 ( 1 bit ) ] */	 
 UINT8 bsic ; /**< Base transceiver station identity code [ range: 0 h-3Fh ( 6 bits ) ] */	 
 UINT8 nom ; /**< Network operation mode [ range: MODE_1= 0 / MODE_2= 1 / MODE_3= 2 ] */	 
 UINT8 nco ; /**< Network control order [ range: NC_0=0 / NC_1=1 / NC_2=2 / NC_RESET=3 ] */	 
 UINT8 bs_pa_mfrms ; /**< Number of multiframes between paging messages sent [ range: 0 -7 ] */	 
	 
 UINT16 mcc ; /**< Mobile country code [ range: 0 -999 ( 3 digits ) ] */	 
 UINT16 mnc ; /**< Mobile network code [ range: 0 -99 ( 2 digits ) ] */	 
 UINT16 lac ; /**< Location area code [ range: 0 h-FFFFh ( 2 octets ) ] */	 
 UINT16 ci ; /**< Cell identity [ range: 0 h-FFFFh ( 2 octets ) ] */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number [ range: 0 -1023 ] */	 
	 
 INT16 C1 ; /**< Path loss criterion parameter #1 */	 
	 
 INT16 C2 ; /**< Path loss criterion parameter #2 */	 
	 
 INT16 C31 ; /**< GPRS signal level threshold criterion parameter*/	 
	 
 INT16 C32 ; /**< GPRS cell ranking criterion parameter */	 
	 
	 
 UINT16 t3212 ; /**< Periodic LA update timer ( T3212 ) in minutes */	 
 UINT16 t3312 ; /**< Periodic RA update timer ( T3312 ) in minutes */	 
	 
 CiBoolean pbcchSupport ; /**< Support of PBCCH \sa CCI API Ref Manual */	 
 UINT8 TxPowerLevel ; /**< Tx power level [ range: 0 h-3Fh ] */	 
 UINT8 timingAdv ; /**< Timing advance [ range 0 -63 ] */	 
 CiBoolean hoppingChannel ; /**< Hopping channel */	 
 CiBoolean EGPRSSupport ; /**< EGPRS support capability */	 
 CiDevEngChannelType ChType ; /**< Values are TCH_F = 1 , TCH_H = 2 , SDCCH_4 = 4 , SDCCH_8 = 8 \sa CIDEV_ENGMODE_CHANNEL_TYPE */	 
 CiBoolean nccPermitted ; /**< The NCC permitted parameter sets the NCCs ( network color codes ) that the mobile station is permitted to report. \sa CCI API Ref Manual */	 
 UINT8 RadioLinkTimeout ; /**< Radio link timeout [ range: value >=0 ] */	 
 UINT16 hoCount ; /**< Handovers counter [ range: value>=0 ] */	 
 UINT16 hoSuccessCount ; /**< Success handovers counter [ range: value>=0 ] */	 
 UINT16 chanAssCount ; /**< Channel assignment counter [ range: value>=0 ] */	 
 UINT16 chanAssSuccessCount ; /**< Success channel assignment counter [ range: value>=0 ] */	 
	 
 UINT16 arfcnTch ; /**< ARFCN for traffic channel , only valid for dedicated state [ range: 0 -1023 ] */	 
 UINT8 timeSlot ; /**< Time slot , only valid for dedicated state*/	 
 CiDevPacketIdleType isInPacketIdle ; /**< Only valid for idle state \sa CiDevPacketIdleType */	 
 /*Michal Bukai - I-Mate Addition. Start:*/	 
 CiBoolean IsForbiddenLA ; /**< Indicates if cell belongs to forbidden location area. FALSE: Cell is not in forbidden LA or forbidden status is unknown ; TRUE: Cell is in forbidden LA. \sa CCI API Ref Manual */	 
 CiDevCellPrioriytType CellPriority ; /**< Cell priority for cell selection or reselection. Cell priority can be normal , low or barred. \sa CiDevCellPrioriytType */	 
 UINT8 HSN ; /**< Hopping sequence number. Value 0 means cyclic hopping is done*/	 
 CiDevHoppingGroup HoppingGroup ; /**< List of ARFCNs assigned for frequency hopping . \sa CiDevHoppingGroup */	 
 /*Michal Bukai - I-Mate Addition. End*/	 
 /*Added by Lilei for Network Info CQ56702 , begin*/	 
 UINT8 gsmBand ; /**< 0 :PGSM_900 ; 1 :DCS_GSM_1800 ; 2 :PCS_GSM_1900 ; 3 :EGSM_900 ; 4 :GSM_450 ; 5 :GSM_480 ; 6 :GSM_850 */	 
 UINT8 channelMode ; /**< Mode of a dedicated channel , used during dedicated channel setup to specify channel mode ( signaling-only , speech or data ) , mode version and data rate. */	 
 /*Added by Lilei for Network Info CQ56702 , end*/	 
 /*Lilei , CQ00092855 , 20150427 , begin*/	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 /*Lilei , CQ00092855 , 20150427 , end*/	 
	 
 } CiDevGsmServingCellInfo_V0001 , CiDevGsmServingCellInfo_V0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeGsmData_v0002_struct 
 {	 
 CiDevGsmServingCellInfo_V0002 svcCellInfo ; /**< Serving cell information \sa CiDevGsmServingCellInfo_struct */	 
	 
 CiDevGsmGMMInfo GMMInfo ; /**< Mobility management information \sa CiDevGsmGMMInfo_struct */	 
 CiDevAMRInfo AMRInfo ; /**< AMR information \sa CiDevAMRInfo_struct */	 
 CiDevGPRSPTMInfo GPRSPTMInfo ; /**< Packet data information \sa CiDevGPRSPTMInfo_struct */	 
	 
 UINT8 numNCells ; /**< Number of neighboring cells [ 0 ..CI_DEV_MAX_GSM_NEIGHBORING_CELLS ] */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevGsmNeighboringCellInfo nbCellInfo [ 6 ] ; /**< Neighboring cell information \sa CiDevGsmNeighboringCellInfo_struct */	 
	 
 UINT8 numInterRATNCells ; /**< Number of InterRAT cells [ 0 ..CI_DEV_MAX_GSM_NEIGHBORING_CELLS ] */	 
 UINT8 res2U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevGsmUMTSNeighboringCellInfo InterRATCellInfo [ 6 ] ; /**< InterRAT cell information \sa CiDevCiDevGsmUMTSNeighboringCellInfo */	 
	 
 } CiDevEngModeGsmData_v0001 , CiDevEngModeGsmData_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGsmEngmodeInfoInd_v0002_struct 
 {	 
 CiDevEngModeState mode ; /**< Current Mode ( Idle / Dedicated ) . \sa CiDevEngModeState */	 
 UINT8 releaseVersion ; /**< 3 GPP release versions */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 CiDevEngModeGsmData_v0002 info ; /**< GSM Engineering Mode information. \sa CiDevEngModeGsmData_struct */	 
 } CiDevPrimGsmEngmodeInfoInd_v0001 , CiDevPrimGsmEngmodeInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 
 typedef struct CiDevUmtsUeOperationStatus_v0002_struct 
 {	 
 CiDevEngModeUeRrcState rrcState ; /**< RRC state \sa CiDevEngModeUeRrcState */	 
 UINT8 numLinks ; /**< Number of radio links */	 
	 
 UINT16 srncId ; /**< U-RNTI: SRNC identifier */	 
 UINT32 sRnti ; /**< U-RNTI: S-RNTI */	 
 CiCipherAlgorithmInfo csCipherInfo ; /**< CS domain ciphering information. \sa CiCipherAlgorithm_struct */	 
 CiCipherAlgorithmInfo psCipherInfo ; /**< PS domain ciphering information. \sa CiCipherAlgorithm_struct */	 
 CiBoolean HSDPAActive ; /**< TRUE - HSDPA is currently activated ; FALSE - other \sa CCI API Ref Manual */	 
 CiBoolean HSUPAActive ; /**< TRUE - HSUPA is currently activated ; FALSE - other \sa CCI API Ref Manual */	 
 UINT16 MccLastRegisteredNetwork ; /**< Mcc of last registered network */	 
 UINT16 MncLastRegisteredNetwork ; /**< Mnc of last registered network */	 
 INT32 TMSI ; /**< TMSI */	 
 INT32 PTMSI ; /**< PTMSI */	 
 CiBoolean IsSingleMmRejectCause ; /**< TRUE - only one MM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 CiBoolean IsSingleGmmRejectCause ; /**< TRUE - only one GMM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 CiDevEngMMRejectCauseCodeType MMRejectCause ; /**< The one that was reported during the last engineering information period reject cause ( 10.500000 .3.6 ) sent in CM Service Reject , Abort , MM-Status , and Location Updating Reject messages to MM from the network. \sa CiDevEngMMRejectCauseCodeType */	 
 CiDevEngGMMRejectCauseCodeType GMMRejectCause ; /**< Reported during the last engineering information period \sa CiDevEngGMMRejectCauseCodeType */	 
 UINT8 mmState ; /**< MM state refer to 3 GPP 24.008000 section 4.100000 .2 */ /* see enum MmState in Mm_comm.h. */	 
 UINT8 gmmState ; /**< GMM state refer to 3 GPP 24.008000 section 4.100000 .3 */ /* see enum GmmState in Gmm_comm.h */	 
 UINT8 gprsReadyState ; /**< 0 - IDLE_STATE / 1 - STANDBY_STATE / 2 - READY_STATE. */ /* see enum GprsReadyState in grrmrtyp.h. */	 
 UINT16 readyTimerValueInSecs ; /**< MM ready timer value in sec [ value >0 ] */	 
 UINT8 NumActivePDPContext ; /**< Number of active PDP contexts */	 
 /*Michal Bukai - I-Mate Addition. Start:*/	 
 UINT32 ULThroughput ; /**< UL throughput in octets per second */	 
 UINT32 DLThroughput ; /**< DL throughput in octets per second */	 
 /*Michal Bukai - I-Mate Addition. End*/	 
 /*Added by Lilei for Network Info CQ56702 , begin*/	 
 UINT8 serviceStatus ; /**< Service status */ /* see enum ServiceStatus in Mmr_sig.h. */	 
 UINT8 pmmState ; /**< UMM state for PS services */ /* see enum UmmState in Mm_comm.h. */	 
 /*Added by Lilei for Network Info CQ56702 , end*/	 
 /*Lilei , CQ00082362 , 20150116 , begin*/	 
 UINT8 LAU_status ; /**<Current update status of the UE */ /* see enum LocationUpdateStatus in Mmr_sig.h. */	 
 UINT16 LAU_count ; /**<LAU attempt counter as held by UE ; number of consecutive LAU failures in current LAU procedure attempt */	 
 UINT8 RAU_status ; /**<RAU status of the UE */ /* see enum GprsUpdateStatus in Mmr_sig.h. */	 
 UINT16 RAU_count ; /**<RAU attempt counter as held by UE ; number of consecutive RAU failures in current RAU procedure attempt*/	 
 /*Lilei , CQ00082362 , 20150116 , end*/	 
 } CiDevUmtsUeOperationStatus_v0001 , CiDevUmtsUeOperationStatus_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsServingCellInfo_v0002_struct 
 {	 
 CiBoolean sCellMeasPresent ; /**< TRUE - is present ; FALSE - is not present. \sa CCI API Ref Manual */	 
 CiBoolean sCellParamPresent ; /**< TRUE - is present ; FALSE - is not present. \sa CCI API Ref Manual */	 
 CiBoolean ueOpStatusPresent ; /**< TRUE - is present ; FALSE - is not present. \sa CCI API Ref Manual */	 
 UINT8 res1U8 ; /**< padding */	 
 CiDevUmtsServingCellMeasurements sCellMeas ; /**< SCell measurements \sa CiDevUmtsServingCellMeasurements_struct */	 
 CiDevUmtsServingCellParameters sCellParam ; /**< PLMN / cell parameters \sa CiDevUmtsServingCellParameters_struct */	 
 CiDevUmtsUeOperationStatus_v0001 ueOpStatus ; /**< UE operation status \sa CiDevUmtsUeOperationStatus_struct */	 
 } CiDevUmtsServingCellInfo_v0001 , CiDevUmtsServingCellInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeSvcCellInfoInd_v0002_struct 
 {	 
 CiDevEngModeState mode ; /**< Current mode ( idle / dedicated ) \sa CiDevEngModeState */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsServingCellInfo_v0001 info ; /**< Engineering mode 3 G ( UMTS ) serving cell information \sa CiDevUmtsServingCellInfo_struct */	 
 } CiDevPrimUmtsEngmodeScellInfoInd_v0001 , CiDevPrimUmtsEngmodeScellInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsFddTddNeighborInfo_v0002_struct 
 {	 
 /* Measurements */	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power */	 
 INT16 utraRssi ; /**< UTRA carrier RSSI */	 
 INT16 cpichEcN0 ; /**< CPICH Ec / N0 , only valid for FDD */	 
 INT16 sQual ; /**< Cell selection quality ( Squal ) , only valid for FDD */	 
 INT16 sRxLev ; /**< Cell selection Rx level ( Srxlev ) */	 
	 
 /* PLMN / Cell Parameters */	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 ci ; /**< Cell Identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
	 
 } CiDevUmtsFddTddNeighborInfo_v0001 , CiDevUmtsFddTddNeighborInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeInterFreqInfoInd_v0002_struct 
 {	 
 UINT8 numInterFreq ; /**< Number of Inter-Frequency FDD Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsFddTddNeighborInfo_v0001 interFreq [ 32 ] ; /**< Inter-Frequency Info. \sa CiDevUmtsFddTddNeighborInfo_struct */	 
 } CiDevPrimUmtsEngmodeInterFreqInfoInd_v0001 , CiDevPrimUmtsEngmodeInterFreqInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeIntraFreqInfoInd_v0002_struct 
 {	 
 UINT8 numIntraFreq ; /**< Number of Intra-Frequency FDD Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsFddTddNeighborInfo_v0001 intraFreq [ 32 ] ; /**< Intra-Frequency Info. \sa CiDevUmtsFddTddNeighborInfo_struct */	 
 } CiDevPrimUmtsEngmodeIntraFreqInfoInd_v0001 , CiDevPrimUmtsEngmodeIntraFreqInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsGsmNeighborInfo_v0002_struct 
 {	 
 /* Measurements */	 
 INT16 gsmRssi ; /**< GSM carrier RSSI */	 
 INT16 rxLev ; /**< Cell selection Rx level */	 
 INT16 C1 ; /**< Path loss criterion parameter #1 */	 
 INT16 C2 ; /**< Path loss criterion parameter #2 */	 
	 
 /* PLMN / Cell Parameters */	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 ci ; /**< Cell identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT8 bsic ; /**< Base transceiver station identity code ; range 0 h-3Fh ( 6 bits ) */	 
 UINT8 res1U8 ;	 
	 
 } CiDevUmtsGsmNeighborInfo_v0001 , CiDevUmtsGsmNeighborInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeInterRatInfoInd_v0002_struct 
 {	 
 UINT8 numInterRAT ; /**< Number of Inter-RAT GSM Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsGsmNeighborInfo_v0001 interRAT [ 32 ] ; /**< Inter-Rat Info. \sa CiDevUmtsGsmNeighborInfo_struct */	 
	 
 } CiDevPrimUmtsEngmodeInterRatInfoInd_v0001 , CiDevPrimUmtsEngmodeInterRatInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngScellParams_v0002_struct 
 {	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT16 mcc ;	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT16 mnc ; /**< 2 -3 digits of MNC */	 
 UINT16 tac ;	 
 UINT16 phyCellId ;	 
 UINT32 dlEuArfcn ;	 
 UINT32 ulEuArfcn ;	 
 UINT16 band ;	 
 UINT8 dlBandwidth ; /*0 - 1.400000 M , 1 - 3 M , 2 - 5 M , 3 - 10 M , 4 - 15 M , 5 - 20 M */	 
 UINT32 cellId ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 /*Added by taow for LTE EM L2 info , begin*/	 
 UINT8 subFrameAssignType ;	 
 UINT8 specialSubframePatterns ;	 
 UINT8 transMode ;	 
 /*Added by taow for LTE EM L2 info , end*/	 
	 
	 
 } CiDevLteEngScellParams_v0001 , CiDevLteEngScellParams_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngScellMeas_v0002_struct 
 {	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 INT8 sinr ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT8 mainRsrp ; /**< Rsrp of main antenna. Value range: 0 ~97 , invalid ( 0xFF ) */	 
 UINT8 diversityRsrp ; /**< Rsrp of diversity antenna. Value range: 0 ~97 , invalid ( 0xFF ) */	 
 UINT8 mainRsrq ; /**< Rsrq of main antenna. Value range: 0 ~34 , invalid ( 0xFF ) */	 
 UINT8 diversityRsrq ; /**< Rsrq of diversity antenna. Value range: 0 ~34 , invalid ( 0xFF ) */	 
 UINT8 rssi ; /**< Value range: 0 ~128 , invalid ( 0xFF ) . ( rssi-128 ) for dbm format */	 
 UINT16 cqi ; /**< Value range: 0 ~15 , invalid ( 0xFFFF ) . */	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 /*Added by taow for LTE EM L2 info , begin*/	 
 UINT8 pathLoss ;	 
 UINT32 tb0DlTpt ;	 
 UINT32 tb1DlTpt ;	 
 UINT32 tb0DlPeakTpt ;	 
 UINT32 tb1DlPeakTpt ;	 
 UINT32 tb0UlPeakTpt ;	 
 UINT32 tb1UlPeakTpt ;	 
 // EmacdlStatisticDataTag	 
 UINT32 dlThroughPut ; // dl throughtput unit bps , sum ( dl tb size in bits ) / dl statistic time duration	 
 UINT32 dlPeakThroughPut ; // Kbps	 
 UINT8 averDlPRB ;	 
 UINT8 averCQITb0 ;	 
 UINT8 averCQITb1 ;	 
 UINT8 rankIndex ;	 
 // EmaculStatisticDataTag	 
 UINT32 grantTotal ; // total received grant size in unit of BYTE	 
 UINT32 ulThroughPut ; // Kbps	 
 UINT32 ulPeakThroughPut ; // Kbps	 
 INT16 currPuschTxPower ;	 
 UINT8 averUlPRB ;	 
 // add by taow 20150415 begin	 
 UINT8 reserved0 ;	 
 UINT16 dlBler ;	 
 UINT16 ulBler ;	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 // add by taow 20150415 end	 
 /*Added by taow for LTE EM L2 info , end*/	 
	 
 } CiDevLteEngScellMeas_v0001 , CiDevLteEngScellMeas_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngScellInfo_v0002_struct 
 {	 
 CiDevLteEngScellParams_v0001 params ;	 
 CiDevLteEngScellMeas_v0001 meas ;	 
 // CiDevLteEngineerCellAccessRestrictions accessRestrictions ;	 
 // CiDevLteEngineerBarredStatus barredStatus ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 CiDevLteUeOperationStatus ueOpStatus ; /**< UE operation status \sa CiDevLteUeOperationStatus */	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 } CiDevLteEngScellInfo_v0001 , CiDevLteEngScellInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeSvcCellInfoInd_v0002_struct 
 {	 
 // CiDevLteEngModeState mode ; / **< Current mode ( deactivated / idle / connected / reselection ) \sa CiDevLteEngModeState * /	 
 CiBoolean sCellPresent ; /**< Whether serving cell engmode info is present */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevLteEngScellInfo_v0001 info ; /**< Engineering mode LTE serving cell information \sa CiDevLteEngScellInfo */	 
 } CiDevPrimLteEngmodeScellInfoInd_v0001 , CiDevPrimLteEngmodeScellInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngInterFreqNcellInfo_v0001_struct 
 {	 
 UINT16 phyCellId ;	 
 UINT32 euArfcn ;	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 // CiBoolean ncellSib1Valid ;	 
 // CiDevLteEngNcellSib1 ncellSib1 ;	 
 // CiBoolean accessRestrictionsPresent ;	 
 // CiDevLteEngineerCellAccessRestrictions accessRestrictions ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT16 mcc ;	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT16 mnc ; /**< 2 -3 digits of MNC */	 
 UINT16 tac ;	 
 UINT32 cellId ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
	 
 } 
 CiDevLteEngInterFreqNcellInfo_v0001 , CiDevLteEngInterFreqNcellInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngIntraFreqNcellInfo_v0002_struct 
 {	 
 UINT16 phyCellId ;	 
 UINT32 euArfcn ;	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 // CiBoolean ncellSib1Valid ;	 
 // CiDevLteEngNcellSib1 ncellSib1 ;	 
 // CiBoolean accessRestrictionsPresent ;	 
 // CiDevLteEngineerCellAccessRestrictions accessRestrictions ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT16 mcc ;	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT16 mnc ; /**< 2 -3 digits of MNC */	 
 UINT16 tac ;	 
 UINT32 cellId ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
	 
 } CiDevLteEngIntraFreqNcellInfo_v0001 , CiDevLteEngIntraFreqNcellInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeIntraFreqInfoInd_v0002_struct 
 {	 
 UINT8 numIntraFreq ; /**< Number of Intra-Frequency Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevLteEngIntraFreqNcellInfo_v0001 intraFreq [ 16 ] ; /**< Intra-Frequency Info. \sa CiDevLteEngIntraFreqNcellInfo */	 
 } CiDevPrimLteEngmodeIntraFreqInfoInd_v0001 , CiDevPrimLteEngmodeIntraFreqInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeInterFreqInfoInd_v0002_struct 
 {	 
 UINT8 numInterFreq ; /**< Number of Inter-Frequency Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevLteEngInterFreqNcellInfo_v0001 interFreq [ 16 ] ; /**< Inter-Frequency Info. \sa CiDevLteEngInterFreqNcellInfo */	 
 } CiDevPrimLteEngmodeInterFreqInfoInd_v0001 , CiDevPrimLteEngmodeInterFreqInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraCellParams_v0002_Struct 
 {	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT32 ci ; /**< Cell identity ; as per 3 G TS 25.331000 , 10.300000 .2.2 ( 28 bits ) */	 
 UINT16 uArfcn ;	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 // UINT16 phyCellId ;	 
	 
 } CiDevLteEngUtraCellParams_v0001 , CiDevLteEngUtraCellParams_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraCellMeas_v0002_struct 
 {	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power ; in UMTS FDD / TDD messages RSCP is	 
 transmitted as an integer value in the range of -120 dBm to -25 dBm.	 
 The value is coded into integers from -5 to 99 according to 3 GPP ' s 25.133000 . */	 
 // INT16 pccpch_RSCP ; // for TDD	 
 INT16 cpichEcN0 ; // For FDD	 
 // INT16 cpichRscp ; // For FDD	 
 } 
 CiDevLteEngUtraCellMeas_v0001 , CiDevLteEngUtraCellMeas_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraNcellInfo_v0002_struct 
 {	 
 CiDevLteEngUtraCellParams_v0001 params ;	 
 CiDevLteEngUtraCellMeas_v0001 meas ;	 
 } CiDevLteEngUtraNcellInfo_v0001 , CiDevLteEngUtraNcellInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellParams_v0002_struct 
 {	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT32 ci ; /**< Cell identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 // UINT8 gsmBandIndicator ;	 
 // CiBoolean bsicPresent ; // ncc and bcc is valid only when bsicPresent is TURE.	 
 // CiDevLteEngBsic bsic ;	 
 UINT8 bsic ; /**< Base transceiver station identity code ; range 0 h-3Fh ( 6 bits ) ; 0xFF means not present */	 
 } 
 CiDevLteEngGsmCellParams_v0001 , CiDevLteEngGsmCellParams_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellMeas_v0002_struct 
 {	 
 INT16 rssi ; /**< GSM carrier RSSI */	 
 } CiDevLteEngGsmCellMeas_v0001 , CiDevLteEngGsmCellMeas_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellInfo_v0002_struct 
 {	 
 CiDevLteEngGsmCellParams_v0001 params ;	 
 CiDevLteEngGsmCellMeas_v0001 meas ;	 
 } CiDevLteEngGsmCellInfo_v0001 , CiDevLteEngGsmCellInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeInterRatInfoInd_v0002_struct 
 {	 
 UINT8 numInterRATUtra ; /**< Number of Inter-RAT UMTS Cells */	 
 UINT8 numInterRATGsm ; /**< Number of Inter-RAT GSM Cells */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 CiDevLteEngUtraNcellInfo_v0001 interRATUtra [ 16 ] ; /**< Inter-Rat UMTS Info. \sa CiDevLteEngUtraNcellInfo */	 
 CiDevLteEngGsmCellInfo_v0001 interRATGsm [ 16 ] ; /**< Inter-Rat UMTS Info. \sa CiDevLteEngUtraNcellInfo */	 
 } CiDevPrimLteEngmodeInterRatInfoInd_v0001 , CiDevPrimLteEngmodeInterRatInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetMedataCommReserveCnf_v0001_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetMedataCommReserveCnf_v0001 , CiDevPrimSetMedataCommReserveCnf_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetMedataCommReserveCnf_v0001_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT8 ConfigValue ; /*value to set */	 
 } CiDevPrimGetMedataCommReserveCnf_v0001 , CiDevPrimGetMedataCommReserveCnf_v0002;

typedef union
 {
 char *filename ;
 __QUEC_CONFIG_ENUM config_num ;
 } quec_baudrate_info_u ;
typedef void ( *debug_to_app_callback ) ( char *data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\tsc.ppp
//PPL Source File Name : \\quectel\\lcd\\rtp_controller\\tsc.c
typedef unsigned int size_t ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 OSA_TASK_READY ,	 
 OSA_TASK_COMPLETED ,	 
 OSA_TASK_TERMINATED ,	 
 OSA_TASK_SUSPENDED ,	 
 OSA_TASK_SLEEP ,	 
 OSA_TASK_QUEUE_SUSP ,	 
 OSA_TASK_SEMAPHORE_SUSP ,	 
 OSA_TASK_EVENT_FLAG ,	 
 OSA_TASK_BLOCK_MEMORY ,	 
 OSA_TASK_MUTEX_SUSP ,	 
 OSA_TASK_STATE_UNKNOWN ,	 
 } OSA_TASK_STATE;

//ICAT EXPORTED STRUCT 
 typedef struct OSA_TASK_STRUCT 
 {	 
 char *task_name ; /* Pointer to thread ' s name */	 
 unsigned int task_priority ; /* Priority of thread ( 0 -255 ) */	 
 unsigned long task_stack_def_val ; /* default vaule of thread */	 
 OSA_TASK_STATE task_state ; /* Thread ' s execution state */	 
 unsigned long task_stack_ptr ; /* Thread ' s stack pointer */	 
 unsigned long task_stack_start ; /* Stack starting address */	 
 unsigned long task_stack_end ; /* Stack ending address */	 
 unsigned long task_stack_size ; /* Stack size */	 
 unsigned long task_run_count ; /* Thread ' s run counter */	 
	 
 } OSA_TASK;

typedef void *OsaRefT ;
typedef UINT8 OSA_STATUS ;
typedef UINT8 OS_STATUS ;
typedef void* OS_HISR ;
typedef void* OSATaskRef ;
typedef void* OSAHISRRef ;
typedef void* OSASemaRef ;
typedef void* OSAMutexRef ;
typedef void* OSAMsgQRef ;
typedef void* OSAMailboxQRef ;
typedef void* OSAPoolRef ;
typedef void* OSATimerRef ;
typedef void* OSAFlagRef ;
typedef void* OSAPartitionPoolRef ;
typedef void* OSTaskRef ;
typedef void* OSSemaRef ;
typedef void* OSMutexRef ;
typedef void* OSMsgQRef ;
typedef void* OSMailboxQRef ;
typedef void* OSPoolRef ;
typedef void* OSTimerRef ;
typedef void* OSFlagRef ;
typedef UINT8 OS_STATUS ;
typedef OsaTimerStatusParamsT OSATimerStatus ;
typedef void* OSATaskRef ;
typedef void* OSAHISRRef ;
typedef void* OSAMsgQRef ;
typedef void* OSAMailboxQRef ;
typedef void* OSAPartitionPoolRef ;
typedef UINT8 OS_STATUS ;
typedef unsigned long UNSIGNED ;
typedef long SIGNED ;
typedef unsigned char DATA_ELEMENT ;
typedef DATA_ELEMENT OPTION ;
typedef DATA_ELEMENT BOOLEAN ;
typedef int STATUS ;
typedef unsigned char UNSIGNED_CHAR ;
typedef unsigned int UNSIGNED_INT ;
typedef int INT ;
typedef unsigned long * UNSIGNED_PTR ;
typedef unsigned char * BYTE_PTR ;
typedef va_list __gnuc_va_list ;
typedef signed char int8_t ;
typedef signed short int int16_t ;
typedef signed int int32_t ;
typedef signed __int64 int64_t ;
typedef unsigned char uint8_t ;
typedef unsigned short int uint16_t ;
typedef unsigned int uint32_t ;
typedef unsigned __int64 uint64_t ;
typedef signed char int_least8_t ;
typedef signed short int int_least16_t ;
typedef signed int int_least32_t ;
typedef signed __int64 int_least64_t ;
typedef unsigned char uint_least8_t ;
typedef unsigned short int uint_least16_t ;
typedef unsigned int uint_least32_t ;
typedef unsigned __int64 uint_least64_t ;
typedef signed int int_fast8_t ;
typedef signed int int_fast16_t ;
typedef signed int int_fast32_t ;
typedef signed __int64 int_fast64_t ;
typedef unsigned int uint_fast8_t ;
typedef unsigned int uint_fast16_t ;
typedef unsigned int uint_fast32_t ;
typedef unsigned __int64 uint_fast64_t ;
typedef signed int intptr_t ;
typedef unsigned int uintptr_t ;
typedef signed long long intmax_t ;
typedef unsigned long long uintmax_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef unsigned char uint8 ;
typedef signed char int8 ;
typedef unsigned short int uint16 ;
typedef signed short int int16 ;
typedef unsigned int uint32 ;
typedef signed int int32 ;
typedef unsigned long long uint64 ;
typedef signed long long int64 ;
typedef int QuecOSStatus ;
typedef unsigned char uint8_t ;
typedef unsigned short uint16_t ;
typedef unsigned int uint32_t ;
typedef unsigned long long uint64_t ;
typedef unsigned int uint_t ;
typedef unsigned char uint_8 ;
typedef unsigned short uint_16 ;
typedef unsigned int uint_32 ;
typedef unsigned long long uint_64 ;
typedef signed int int_32 ;
typedef signed int int32_t ;
typedef unsigned char u8 ;
typedef unsigned short u16 ;
typedef unsigned int u32 ;
typedef uint8 data_t ;
typedef uint32 datasize_t ;
typedef uint32 node_cnt_t ;
typedef int32 linklist_id_t ;
typedef linklist_t * linklist_handler_t ;
typedef uint32 quec_tcb_id_t ;
typedef linklist_handler_t QuecTCBLinklist_t ;
typedef OSTaskRef quec_task_t ;
typedef OSSemaRef quec_sem_t ;
typedef OSMutexRef quec_mutex_t ;
typedef OSMsgQRef quec_queue_t ;
typedef OSMailboxQRef quec_mailbox_t ;
typedef OSFlagRef quec_flag_t ;
typedef OSTimerRef quec_timer_t ;
typedef OSATimerStatus quec_timer_status_t ;
typedef void ( * task_delete_work_cb_t ) ( task_delete_result_t * task_delete_result ) ;
typedef void ( *touch_panel_down_cb ) ( unsigned int x , unsigned int y ) ;
typedef unsigned char BOOL ;
typedef unsigned char UINT8 ;
typedef unsigned short UINT16 ;
typedef signed char INT8 ;
typedef signed short INT16 ;
typedef unsigned short WORD ;
typedef int HANDLE ;
typedef HANDLE* LPHANDLE ;
typedef unsigned char* PUINT8 ;
typedef long LONG ;
typedef char* LPCTSTR ;
typedef char* LPTSTR ;
typedef void* LPVOID ;
typedef unsigned int* LPDWORD ;
typedef unsigned int* PDWORD ;
typedef unsigned int* PUINT32 ;
typedef unsigned int UINT ;
typedef INT16 *PINT16 ;
typedef UINT16 *PUINT16 ;
typedef INT8 *PINT8 ;
typedef UINT8 *PUINT8 ;
typedef int utlReturnCode_T , *utlReturnCode_P ;
typedef const utlReturnCode_T *utlReturnCode_P2c ;
typedef unsigned int utlDataId_T , *utlDataId_P ;
typedef unsigned int size_t , ssize_t ;
typedef const utlDataId_T *utlDataId_P2c ;
typedef const utlLinkedListNode_T *utlLinkedListNode_P2c ;
typedef unsigned int utlNodeCount_T ;
typedef const utlLinkedList_T *utlLinkedList_P2c ;
typedef int utlSecond_T ;
typedef int utlNanosecond_T ;
typedef const utlRelativeTime_T *utlRelativeTime_P2c ;
typedef const utlAbsoluteTime_T *utlAbsoluteTime_P2c ;
typedef const utlVString_T *utlVString_P2c ;
typedef signed long utlTimerId_T ;
typedef unsigned long utlTimeOutCount_T , *utlTimeOutCount_P ;
typedef utlReturnCode_T ( *utlTimerFunction_P ) ( const utlTimerId_T id ,
 const utlTimeOutCount_T time_out_count ,
 void *arg_p ,
 const utlAbsoluteTime_P2c curr_time_p ) ;
typedef unsigned int utlMutexAttributes_T , *utlMutexAttributes_P ;
typedef unsigned int utlSemaphoreAttributes_T , *utlSemaphoreAttributes_P ;
typedef int utlStateMachineStateId_T , *utlStateMachineStateId_P ;
typedef int utlStateMachineEventId_T , *utlStateMachineEventId_P ;
typedef utlReturnCode_T ( *utlStateMachineStateFunction_P ) ( const utlStateMachine_P state_machine_p ,
 const utlStateMachineStateId_T state ,
 const utlAbsoluteTime_P2c curr_time_p ,
 void *arg_p ) ;
typedef utlReturnCode_T ( *utlStateMachineEventFunction_P ) ( const utlStateMachine_P state_machine_p ,
 const utlStateMachineStateId_T state ,
 const utlStateMachineEventId_T event ,
 const utlAbsoluteTime_P2c curr_time_p ,
 void *arg_p ,
 va_list va_arg_p ) ;
typedef const utlStateMachineEvent_T *utlStateMachineEvent_P2c ;
typedef const utlStateMachineState_T *utlStateMachineState_P2c ;
typedef unsigned int utlStateMachineFlags_T ;
typedef const utlStateMachine_T *utlStateMachine_P2c ;
typedef volatile UINT8 *V_UINT8_PTR ;
typedef volatile UINT16 *V_UINT16_PTR ;
typedef volatile UINT32 *V_UINT32_PTR ;
typedef unsigned int U32Bits ;
typedef BOOL BOOLEAN ;
typedef const char * SwVersion ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_E ,	 
 MAT_I ,	 
 MAT_L ,	 
 MAT_M ,	 
 MAT_O ,	 
 MAT_P ,	 
 MAT_Q ,	 
 MAT_T ,	 
 MAT_V ,	 
 MAT_X ,	 
 MAT_Z ,	 
 MAT_ampC ,	 
 MAT_ampD ,	 
 MAT_ampF ,	 
 MAT_ampS ,	 
 MAT_ampZ ,	 
 MAT_ampM ,	 
 MAT_ampV ,	 
 MAT_CGMI ,	 
 MAT_CGMM ,	 
 MAT_CGMR ,	 
 MAT_CGSN ,	 
 MAT_CSCS ,	 
 MAT_CIMI ,	 
 MAT_ASTO ,	 
 MAT_GMI ,	 
 MAT_GMM ,	 
 MAT_GMR ,	 
 MAT_GSN ,	 
 MAT_GOI ,	 
 MAT_GCAP ,	 
 MAT_GCI ,	 
 MAT_IPR ,	 
 MAT_ICF ,	 
 MAT_IFC ,	 
 MAT_IDSR ,	 
 MAT_EXAMPLE ,	 
 MAT_RawAT ,	 
 MAT_A ,	 
 MAT_D ,	 
 MAT_H ,	 
 MAT_CSTA ,	 
 MAT_CMOD ,	 
 MAT_CVMOD ,	 
 MAT_CHUP ,	 
 MAT_CBST ,	 
 MAT_CVHU ,	 
 MAT_CRLP ,	 
 MAT_CEER ,	 
 MAT_CMUT ,	 
 MAT_ECHUPVT ,	 
	 
 MAT_CREG ,	 
 MAT_CIND ,	 
 MAT_COPS ,	 
 MAT_CPOL ,	 
 MAT_CLCK ,	 
 MAT_CPWD ,	 
 MAT_CLIP ,	 
 MAT_CLIR ,	 
 MAT_COLP ,	 
 MAT_COLR ,	 
 MAT_CNAP ,	 
 MAT_CCFC ,	 
 MAT_CCWA ,	 
 MAT_CHLD ,	 
 MAT_CAOC ,	 
 MAT_VTS ,	 
 MAT_VTD ,	 
 MAT_CSSN ,	 
 MAT_CLCC ,	 
 MAT_FCLASS ,	 
 MAT_starCISCC ,	 
 MAT_dollarVTS ,	 
 MAT_starDIALE ,	 
	 
 MAT_CUSD ,	 
 MAT_PEER ,	 
 MAT_CSQ ,	 
 MAT_starREJCUSE ,	 
 MAT_CMUX ,	 
	 
 MAT_NETDMSG ,	 
 MAT_CSQEX ,	 
	 
 MAT_CPAS ,	 
 MAT_CFUN ,	 
 MAT_starCFUN ,	 
	 
 MAT_MINI_START ,	 
 MAT_MINI_END ,	 
	 
 MAT_CPIN ,	 
 MAT_CPIN2 ,	 
 MAT_EPIN ,	 
 MAT_CPINR ,	 
 MAT_starSIMDETEC ,	 
 MAT_CPOFF ,	 
 MAT_CTZR ,	 
 MAT_CTZU ,	 
 MAT_starCTZR ,	 
 MAT_CPBS ,	 
 MAT_CPBR ,	 
 MAT_CPBW ,	 
 MAT_CPBF ,	 
 MAT_CSIM ,	 
 MAT_CRSM ,	 
 MAT_CGLA ,	 
 MAT_CRLA ,	 
 MAT_CCHO ,	 
 MAT_CCHC ,	 
 MAT_MSTK ,	 
 MAT_starEUICC ,	 
 MAT_CACM ,	 
 MAT_CAMM ,	 
 MAT_CCWE ,	 
 MAT_ADMINDATA ,	 
 MAT_CGREG ,	 
 MAT_starREGOPT ,	 
 MAT_CGATT ,	 
	 
 MAT_CGATTEX ,	 
	 
 MAT_CGACT ,	 
 MAT_CGDATA ,	 
 MAT_CGDCONT ,	 
 MAT_CGDSCONT ,	 
 MAT_CGQMIN ,	 
 MAT_CGQREQ ,	 
 MAT_CGEQREQ ,	 
 MAT_CGEQMIN ,	 
 MAT_GETIP ,	 
 MAT_starTGSINK ,	 
 MAT_CGSEND ,	 
 MAT_starICSSINK ,	 
 MAT_starAUTHReq ,	 
	 
 MAT_starCHAPAUTH ,	 
	 
 MAT_CMGF ,	 
 MAT_starCMGF ,	 
 MAT_CMSS ,	 
 MAT_CMGS ,	 
 MAT_CMGR ,	 
 MAT_CMGW ,	 
 MAT_CSCA ,	 
 MAT_CSCB ,	 
 MAT_CNMI ,	 
 MAT_CGSMS ,	 
 MAT_CMMS ,	 
 MAT_CMGD ,	 
 MAT_CMGL ,	 
 MAT_CSMS ,	 
 MAT_CPMS ,	 
 MAT_CNMA ,	 
 MAT_CSMP ,	 
 MAT_CSDH ,	 
 MAT_CSAS ,	 
 MAT_CRES ,	 
 MAT_CPNER ,	 
 MAT_CGCI ,	 
 MAT_CGOI ,	 
 MAT_VDUMP ,	 
 MAT_VPDUS ,	 
 MAT_VHDL ,	 
 MAT_VECHO ,	 
 MAT_ATDB ,	 
 MAT_starCCIREG ,	 
 MAT_CPUC ,	 
 MAT_CRC ,	 
 MAT_CMEE ,	 
 MAT_CDIP ,	 
 MAT_CPLS ,	 
 MAT_CGCMOD ,	 
 MAT_CNUM ,	 
 MAT_DS ,	 
 MAT_CGTFT ,	 
 MAT_starBAND ,	 
 MAT_starBANDIND ,	 
 MAT_starCLCK ,	 
 MAT_starMEPCG ,	 
 MAT_starENVSIM ,	 
 MAT_starCNMA ,	 
 MAT_starRSTMEMFULL ,	 
 MAT_starPOWERIND ,	 
 MAT_starFASTDORM ,	 
 MAT_starCellLock ,	 
 MAT_EEMOPT ,	 
 MAT_EEMGINFO ,	 
 MAT_ERGA ,	 
 MAT_ERTCA ,	 
 MAT_LPNWUL ,	 
 MAT_LPLOCVR ,	 
 MAT_starSYSSLEEP ,	 
 MAT_starCam_I2C ,	 
 MAT_starISP_REG ,	 
 MAT_starCam_rawdump ,	 
 MAT_starFILETEST ,	 
 MAT_starMRD_CDF ,	 
 MAT_starMRD_IMEI ,	 
 MAT_starMRD_MEP ,	 
 MAT_starMRD_CalInfo ,	 
 MAT_starMRD_MEPPLMN ,	 
 MAT_starMRD_SN ,	 
 MAT_starMRD_ITEM ,	 
 MAT_starMRD_ADC ,	 
 MAT_starMRD_RTPADC ,	 
 // #ifdef AT_PRODUCTION_CMNDS	 
 MAT_starGSMTR ,	 
 // #endif	 
 MAT_OFF ,	 
 MAT_starCGSN ,	 
 MAT_starMODEMTYPE ,	 
 MAT_starHTCCTO ,	 
 MAT_CMEMFULL ,	 
 MAT_starEHSDPA ,	 
	 
	 
	 
	 
 MAT_starFDY ,	 
 MAT_xorSYSINFO ,	 
 MAT_starCPBC ,	 
 MAT_starFDNBYPASS ,	 
 MAT_starCSCB ,	 
 MAT_starCBMCS ,	 
 MAT_starNASCHK ,	 
 MAT_CGEQOS ,	 
 MAT_CEREG ,	 
 MAT_CGCONTRDP ,	 
 MAT_CGSCONTRDP ,	 
 MAT_CGTFTRDP ,	 
 MAT_CGEQOSRDP ,	 
 MAT_CGEREP ,	 
 MAT_CEMODE ,	 
 MAT_CGPADDR ,	 
 MAT_xorCACAP ,	 
 MAT_CGCLASS ,	 
 MAT_CESQ ,	 
 MAT_BGLTEPLMN ,	 
 MAT_STARCGDFAUTH ,	 
 MAT_dollarMYMINISYS ,	 
 MAT_dollarMYFOTA ,	 
 MAT_VZWRSRP ,	 
 MAT_VZWRSRQ ,	 
 MAT_starCGDFLT ,	 
	 
 MAT_STARNETACT ,	 
 MAT_STARNETREF ,	 
 MAT_STARNETDNS ,	 
 MAT_STARNETIF ,	 
 MAT_STARNETIFCM ,	 
 MAT_STARMPSAPN ,	 
	 
	 
 MAT_starMODEMRESET ,	 
	 
 MAT_starVZWTESTAPP ,	 
 MAT_VZWAPNE ,	 
 MAT_COPN ,	 
 MAT_starGATR ,	 
 MAT_starGRIP ,	 
 MAT_playMP3 ,	 
 MAT_starCGMR ,	 
 MAT_starCOMCFG ,	 
 MAT_starRFTEMP ,	 
 MAT_startRFTEMPEX ,	 
	 
 MAT_starSOCTEMP ,	 
	 
 MAT_TEMPTEST ,	 
 MAT_BANSELCT ,	 
 MAT_SYSSLEEP ,	 
 MAT_PSSDC ,	 
 MAT_starCGATT ,	 
 MAT_CGPIAF ,	 
 MAT_CIREG ,	 
 MAT_starUSBT ,	 
 MAT_starLTECOEX ,	 
 MAT_LTEPOWER ,	 
 MAT_LTETR ,	 
 MAT_starCSQ ,	 
 MAT_MAXPOWER ,	 
 MAT_SIMDETEC ,	 
 MAT_APPPIN ,	 
 MAT_CPLMNS ,	 
 MAT_starMOBILEDATA ,	 
 MAT_MCCMNCCC ,	 
 MAT_WS46 ,	 
 MAT_starCELL ,	 
 MAT_CISRVCC ,	 
 MAT_CEVDP ,	 
 MAT_CEUS ,	 
 /* add for BT SAP */	 
 MAT_BTSCNCT ,	 
 MAT_BTSDISSCNCT ,	 
 MAT_BTSTAPDU ,	 
 MAT_BTSTATR ,	 
 MAT_BTSCTRL ,	 
 MAT_BTSCRSTAT ,	 
 MAT_BTSTP ,	 
 MAT_starWBAMR ,	 
 MAT_CNMPSD ,	 
 MAT_starREGMODE ,	 
 MAT_starIMLCONFIG ,	 
 MAT_CCLK ,	 
 MAT_starURSLCT ,	 
 MAT_starCBRAT ,	 
 MAT_starSECCAP ,	 
 MAT_starLTEBAND ,	 
 MAT_starPSTHRESHOLD ,	 
 MAT_CACL ,	 
 MAT_LPECID ,	 
 MAT_LPOTDOAABORT ,	 
 MAT_LPOTDOAREQ ,	 
 MAT_L1DEBUG ,	 
 MAT_CSC ,	 
 MAT_OPERCFG ,	 
 MAT_starPSDC ,	 
 MAT_CEN ,	 
 MAT_CNEM ,	 
 MAT_CMMIVT ,	 
 MAT_CPSMS ,	 
 MAT_CEDRXS ,	 
 MAT_CEDRXRDP ,	 
 MAT_CCIOTOPT ,	 
 MAT_CRCES ,	 
 MAT_CSCON ,	 
 MAT_CIPCA ,	 
 MAT_CABTSR ,	 
 MAT_CABTRDP ,	 
 MAT_CGAPNRC ,	 
 MAT_MPBK ,	 
 MAT_CSODCP ,	 
 MAT_CRTDCP ,	 
	 
 MAT_LOG ,	 
 MAT_starDIALMODE ,	 
 MAT_starAPNMODE ,	 
 MAT_starAGDCONT ,	 
 MAT_starAGACT ,	 
 MAT_starLWIPCTRL ,	 
 MAT_starNTP ,	 
 MAT_starCGDCONT ,	 
 MAT_starMTU ,	 
 MAT_plusSWITCHSIM ,	 
 MAT_plusDUALSIM ,	 
 MAT_plusBINDSIM ,	 
	 
	 
	 
 MAT_Q_QDSIM ,	 
	 
 MAT_Q_QDSTYPE ,	 
 MAT_Q_QDSBIND ,	 
 MAT_Q_QDSIMI ,	 
 MAT_Q_QDSCCID ,	 
 MAT_Q_QDSPIN ,	 
 MAT_Q_QDSREG ,	 
 MAT_Q_QDSGREG ,	 
 MAT_Q_QDSEREG ,	 
 MAT_Q_QDSQ ,	 
 MAT_Q_QDSOPS ,	 
 MAT_Q_QDSLOCK ,	 
 MAT_Q_QDSRELEASE ,	 
	 
 // MAT_plusCWRITESIM ,	 
 // #ifdef BT_TEST_SUPPORT 20201214 @xiaokeweng force enable as BT / WIFI could be enable / disable in SDK build	 
 MAT_BTTEST ,	 
 // #endif	 
 MAT_startECCLIST ,	 
	 
	 
	 
	 
	 
 MAT_TRUSTNUM ,	 
	 
 /* STASR1606-2810: CHKTRUSTNUM can not be shielded because the cloesd source IMS will use it for checking the trust number. */	 
 MAT_CHKTRUSTNUM ,	 
	 
 MAT_starISIMAID ,	 
 MAT_CSSAC ,	 
 MAT_MEDCR ,	 
	 
 MAT_Q_QFOTADL ,	 
	 
	 
 MAT_STARREADVER ,	 
 MAT_RESET ,	 
 MAT_RSTSET ,	 
	 
 MAT_DNS ,	 
 MAT_dollarMYPOWEROFF ,	 
 MAT_dollarMYSOCKETLED ,	 
 MAT_dollarMYGMR ,	 
 MAT_dollarMYCCID ,	 
 MAT_dollarMYNETURC ,	 
 MAT_dollarMYTYPE ,	 
 MAT_dollarMYNETCON ,	 
 MAT_dollarMYNETACT ,	 
 MAT_dollarMYIPFILTER ,	 
 MAT_dollarMYNETSRV ,	 
 MAT_dollarMYNETOPEN ,	 
 MAT_dollarMYNETREAD ,	 
 MAT_dollarMYNETWRITE ,	 
 MAT_dollarMYNETCLOSE ,	 
 MAT_dollarMYNETACK ,	 
 MAT_dollarMYNETACCEPT ,	 
 MAT_dollarMYNETCREATE ,	 
 MAT_dollarMYFTPOPEN ,	 
 MAT_dollarMYFTPCLOSE ,	 
 MAT_dollarMYFTPSIZE ,	 
 MAT_dollarMYFTPGET ,	 
 MAT_dollarMYFTPPUT ,	 
 MAT_dollarMYBCCH ,	 
 MAT_dollarMYBAND ,	 
 MAT_dollarMYTIMEUPDATE ,	 
 MAT_dollarMYLACID ,	 
 MAT_dollarMYGPSPOS ,	 
 MAT_dollarMYGETKEY ,	 
 MAT_dollarMYSETINFO ,	 
 MAT_dollarMYSYSINFO ,	 
 MAT_dollarMYSYSINFOURC ,	 
 MAT_QICSGP ,	 
 MAT_QIACT ,	 
 MAT_QIDEACT ,	 
 MAT_QIOPEN ,	 
 MAT_QICLOSE ,	 
 MAT_QISTATE ,	 
 MAT_QISEND ,	 
 MAT_QIRD ,	 
 MAT_QISENDEX ,	 
 MAT_QISWTMD ,	 
 MAT_QIGETERROR ,	 
 MAT_QISDE ,	 
 MAT_QICFG ,	 
 MAT_QFTPCFG ,	 
 MAT_QFTPOPEN ,	 
 MAT_QFTPCLOSE ,	 
 MAT_QFTPCWD ,	 
 MAT_QFTPPWD ,	 
 MAT_QFTPPUT ,	 
 MAT_QFTPGET ,	 
 MAT_QFTPSIZE ,	 
 MAT_QFTPDEL ,	 
 MAT_QFTPMKDIR ,	 
 MAT_QFTPRMDIR ,	 
 MAT_QFTPMDTM ,	 
 MAT_QFTPRENAME ,	 
 MAT_QFTPLIST ,	 
 MAT_QFTPNLST ,	 
 MAT_QFTPMLSD ,	 
 MAT_QFTPLEN ,	 
 MAT_QFTPSTAT ,	 
 MAT_TCPKEEPALIVE ,	 
	 
 MAT_dollarMYDOWNLOAD ,	 
	 
	 
 MAT_xorHVER ,	 
 MAT_CDU ,	 
 MAT_starPROD ,	 
 MAT_NVMFLUSH ,	 
 MAT_starSLT ,	 
 MAT_starPMICREG ,	 
 MAT_starREGRW ,	 
 MAT_ZDON ,	 
 MAT_starASRCOPS ,	 
 MAT_starICCID ,	 
 MAT_CEN1 ,	 
 MAT_CEN2 ,	 
 MAT_starSULOGCFG ,	 
	 
 MAT_starWIFICTRL ,	 
	 
 MAT_starSIMPOLL ,	 
 MAT_cellinfo ,	 
 MAT_starEPIN ,	 
 MAT_starVER ,	 
 // #ifdef WIFI_FUNCTION_SUPPOR 20201214 @xiaokeweng force enable as BT / WIFI could be enable / disable in SDK build	 
 MAT_WIFI_CMD ,	 
 // #endif	 
 MAT_Audio_CMD ,	 
 MAT_starMRDBACKUP ,	 
 MAT_starMRDWIFIMAC ,	 
 MAT_starMRDBTID ,	 
 MAT_starAUDNVM ,	 
 MAT_starSPN ,	 
 MAT_CMRSS ,	 
 MAT_CMGSS ,	 
 MAT_CMSMS ,	 
 MAT_CMGMS ,	 
 MAT_PACSP ,	 
 MAT_ENVCFG ,	 
 MAT_CUAD ,	 
	 
 MAT_STARGETIP ,	 
 MAT_CR ,	 
 MAT_PROPERTY ,	 
 MAT_UNKNOWN ,	 
 MAT_CMD_UNKNOWN = MAT_UNKNOWN ,	 
	 
 /* response type for MAT */	 
 MAT_RSP_UNKNOWN = 1000 ,	 
 MAT_RSP_OK ,	 
 MAT_RSP_ERROR ,	 
 MAT_RSP_CME_ERROR ,	 
 MAT_RSP_CMS_ERROR ,	 
 MAT_RSP_BUSY ,	 
	 
 /* indication type for MAT */	 
 MAT_IND_CONNECT ,	 
 MAT_IND_NO_CARRIER ,	 
 MAT_IND_RING ,	 
 MAT_IND_NO_ANSWER ,	 
 MAT_IND_NO_DIALTONE ,	 
	 
 /* CC Indication */	 
 MAT_IND_CRING ,	 
 MAT_IND_CCCM ,	 
 MAT_IND_CSSU ,	 
 MAT_IND_CSSI ,	 
 MAT_IND_CR ,	 
 MAT_IND_CEI ,	 
	 
 /* DEV Indication */	 
 MAT_IND_SYSCONFIG ,	 
 MAT_IND_EEMGINFOBASIC ,	 
 MAT_IND_EEMGINFOSVC ,	 
 MAT_IND_EEMGINFOPS ,	 
 MAT_IND_EEMGINFONC ,	 
 MAT_IND_EEMGINBFTM ,	 
 MAT_IND_EEMUMTSSVC ,	 
 MAT_IND_EEMUMTSINTRA ,	 
 MAT_IND_EEMUMTSINTER ,	 
 MAT_IND_EEMUMTSINTERRAT ,	 
 MAT_IND_EEMLTESVC ,	 
 MAT_IND_EEMLTEINTRA ,	 
 MAT_IND_EEMLTEINTER ,	 
 MAT_IND_EEMLTEINTERRAT ,	 
 MAT_IND_SNETIND ,	 
 MAT_IND_LPNWDL ,	 
 MAT_IND_LPSTATE ,	 
 MAT_IND_LPMEAST ,	 
 MAT_IND_LPRESET ,	 
 MAT_IND_DIP ,	 
 MAT_IND_LPOTDOAMEAS ,	 
 /* MM Indication */	 
 MAT_IND_CACAP ,	 
 MAT_IND_MODE ,	 
 MAT_IND_COPN ,	 
 MAT_IND_NITZ ,	 
 MAT_IND_MSRI ,	 
 MAT_IND_HOME_ZONE ,	 
	 
 /* MSG Indication */	 
 MAT_IND_MMSG ,	 
 MAT_IND_CMTI ,	 
 MAT_IND_CBM ,	 
 MAT_IND_CDS ,	 
 MAT_IND_CMT ,	 
	 
 /* PB Indication */	 
 MAT_IND_SCPBR ,	 
 MAT_IND_MPBK ,	 
	 
 /* PS Indication */	 
 MAT_IND_CGEQNEG ,	 
 MAT_IND_CGEV ,	 
	 
 /* SIM Indication */	 
 MAT_IND_COTA ,	 
 MAT_IND_REFRESH ,	 
 MAT_IND_SIM_RESET ,	 
 MAT_IND_CARDMODE ,	 
 MAT_IND_SPN ,	 
	 
 /* SS Indication */	 
 MAT_IND_LPLOC ,	 
 MAT_IND_SSRC ,	 
	 
 /* DAT Indication */	 
 MAT_IND_PSSDC ,	 
	 
 /* the change of sim / usim availability status report */	 
 MAT_IND_BTSSTAT ,	 
	 
 MAT_IND_DSAC ,	 
 MAT_IND_ADMINDATA ,	 
 MAT_IND_CIMI ,	 
 MAT_IND_PSLOAD ,	 
 MAT_IND_RBLOOP ,	 
 MAT_IND_CELL ,	 
 MAT_IND_CIREPI ,	 
 MAT_IND_CIREPH ,	 
 MAT_IND_DATASTATUS ,	 
 MAT_IND_CEDRXP ,	 
 MAT_IND_CCIOTOPTI ,	 
 MAT_IND_CABTSRI ,	 
 MAT_IND_CIREGU ,	 
 MAT_IND_AMRCODEC ,	 
 MAT_IND_CNEC_ESM ,	 
 MAT_IND_ATREADY ,	 
 MAT_IND_PLMNLIST ,	 
 MAT_IND_WIFICELLINFO ,	 
	 
	 
	 
	 
	 
 MAT_CWRITESIM ,	 
	 
 MAT_Q_QPOWD ,	 
	 
	 
	 
 MAT_Q_I ,	 
 MAT_Q_E ,	 
 MAT_Q_Z ,	 
	 
 MAT_Q_IPR ,	 
 MAT_Q_CBAUD ,	 
 MAT_Q_IFC ,	 
 MAT_Q_QSCLK ,	 
	 
 MAT_Q_QNETDEVCTL ,	 
 MAT_Q_QDBGCFG ,	 
	 
 MAT_Q_QENGINFO ,	 
	 
	 
 MAT_Q_EGMR ,	 
 MAT_Q_QGMR ,	 
	 
	 
	 
	 
	 
 MAT_Q_CUSTOMERAREA ,	 
 MAT_Q_CVERSION ,	 
 MAT_Q_CSUB ,	 
 MAT_Q_QINF ,	 
 MAT_Q_QURCCFG ,	 
 MAT_Q_AMP_V ,	 
 MAT_Q_AMP_W ,	 
 MAT_Q_CMEE ,	 
 MAT_Q_CFUN ,	 
 MAT_Q_CSCS ,	 
 MAT_Q_CGMI ,	 
 MAT_Q_CGMM ,	 
 MAT_Q_CGMR ,	 
 MAT_Q_CGSN ,	 
 MAT_Q_GSN ,	 
 MAT_Q_QGSN ,	 
 MAT_Q_QCCID ,	 
 MAT_Q_CCID ,	 
 MAT_Q_ICCID ,	 
 MAT_Q_GMI ,	 
 MAT_Q_GMM ,	 
 MAT_Q_GMR ,	 
 MAT_Q_QCFG ,	 
 MAT_Q_QINDCFG ,	 
 MAT_Q_QNWINFO ,	 
 MAT_Q_CSQ ,	 
 MAT_Q_QCSQ ,	 
 MAT_Q_CGREG ,	 
 MAT_Q_CEREG ,	 
 MAT_Q_CREG ,	 
 MAT_Q_CGEREP ,	 
 MAT_Q_CTZR ,	 
 MAT_Q_QENG ,	 
 MAT_Q_QLTS ,	 
 MAT_Q_QGDCNT ,	 
 MAT_Q_QAUGDCNT ,	 
 MAT_Q_QOEM ,	 
 MAT_Q_SMONC ,	 
 MAT_Q_QGPAPN ,	 
 MAT_Q_QRFTESTMODE ,	 
 MAT_Q_QRFTEST ,	 
 MAT_Q_QRXFTM ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MAT_Q_QICSGP ,	 
 MAT_Q_QIACT ,	 
 MAT_Q_QIACTEX ,	 
 MAT_Q_QIDEACT ,	 
 MAT_Q_QIDEACTEX ,	 
 MAT_Q_QIDNSCFG ,	 
 MAT_Q_QIDNSGIP ,	 
 MAT_Q_QICFG ,	 
 MAT_Q_QIOPEN ,	 
 MAT_Q_QIRD ,	 
 MAT_Q_QISEND ,	 
 MAT_Q_QISENDEX ,	 
 MAT_Q_QISWTMD ,	 
 MAT_Q_QISTATE ,	 
 MAT_Q_QICLOSE ,	 
 MAT_Q_QISDE ,	 
 MAT_Q_QPING ,	 
	 
 MAT_Q_QIACCEPT ,	 
	 
 MAT_Q_QISWCMD ,	 
	 
 MAT_Q_QNTP ,	 
 MAT_Q_QIGETERROR ,	 
	 
 MAT_Q_QSSLCFG ,	 
 MAT_Q_QSSLOPEN ,	 
 MAT_Q_QSSLRECV ,	 
 MAT_Q_QSSLSEND ,	 
 MAT_Q_QSSLCLOSE ,	 
 MAT_Q_QSSLSTATE ,	 
	 
 MAT_Q_QDMCFG ,	 
 MAT_Q_QDMCFGEX ,	 
 MAT_Q_QDMSTART ,	 
 MAT_Q_QDMSTOP ,	 
 MAT_Q_QDMSTAT ,	 
 MAT_Q_QMTCFG ,	 
 MAT_Q_QMTOPEN ,	 
 MAT_Q_QMTCLOSE ,	 
 MAT_Q_QMTCONN ,	 
 MAT_Q_QMTDISC ,	 
 MAT_Q_QMTSUB ,	 
 MAT_Q_QMTUNS ,	 
 MAT_Q_QMTPUB ,	 
 MAT_Q_QMTPUBEX ,	 
 MAT_Q_QMTRECV ,	 
	 
 MAT_Q_QFTPCFG ,	 
 MAT_Q_QFTPOPEN ,	 
 MAT_Q_QFTPCLOSE ,	 
 MAT_Q_QFTPCWD ,	 
 MAT_Q_QFTPPWD ,	 
 MAT_Q_QFTPSIZE ,	 
 MAT_Q_QFTPDEL ,	 
 MAT_Q_QFTPMKDIR ,	 
 MAT_Q_QFTPRMDIR ,	 
 MAT_Q_QFTPRENAME ,	 
 MAT_Q_QFTPSTAT ,	 
 MAT_Q_QFTPMDTM ,	 
 MAT_Q_QFTPPUT ,	 
 MAT_Q_QFTPGET ,	 
 MAT_Q_QFTPLIST ,	 
 MAT_Q_QFTPNLST ,	 
 MAT_Q_QFTPMLSD ,	 
 MAT_Q_QFTPLEN ,	 
 MAT_Q_QHTTPCFG ,	 
 MAT_Q_QHTTPURL ,	 
 MAT_Q_QHTTPURLEX ,	 
 MAT_Q_QHTTPGET ,	 
 MAT_Q_QHTTPGETEX ,	 
 MAT_Q_QHTTPPOST ,	 
 MAT_Q_QHTTPPOSTFILE ,	 
 MAT_Q_QHTTPPUT ,	 
 MAT_Q_QHTTPPUTFILE ,	 
 MAT_Q_QHTTPREAD ,	 
 MAT_Q_QHTTPREADFILE ,	 
 MAT_Q_QHTTPSTOP ,	 
 MAT_Q_QLBS ,	 
 MAT_Q_QLBSCFG ,	 
	 
 MAT_Q_QHTTPCFGEX ,	 
 MAT_Q_QHTTPSEND ,	 
	 
 MAT_Q_QLBSDEBUG ,	 
 MAT_Q_QCERT ,	 
 MAT_Q_QSVN ,	 
 MAT_Q_QIOTRPT ,	 
 MAT_Q_QIOTRPTCFG ,	 
 MAT_Q_QGPIOS ,	 
 MAT_Q_QGPIOR ,	 
 MAT_Q_QGPIOW ,	 
 MAT_Q_MRDBACKUP ,	 
 MAT_Q_QCMGR ,	 
 MAT_Q_QCMGS ,	 
	 
 MAT_Q_QINISTAT ,	 
 MAT_Q_QPINC ,	 
 MAT_Q_QSIMDET ,	 
 MAT_Q_QSIMSTAT ,	 
 MAT_Q_QAUDLOOP ,	 
 MAT_Q_QAUDPLAYSPL ,	 
	 
 MAT_Q_QAUDSW ,	 
	 
	 
	 
	 
	 
 MAT_Q_QAUTHCODE ,	 
 MAT_Q_UID ,	 
	 
 MAT_Q_QLICENSE ,	 
 MAT_Q_QLICENSEINFO ,	 
	 
	 
	 
 MAT_Q_QAUDHSDET ,	 
	 
	 
 MAT_Q_QPSND ,	 
	 
	 
	 
	 
 MAT_Q_QTTS ,	 
	 
	 
	 
	 
 MAT_Q_QAUDPLAY ,	 
 MAT_Q_QAUDSTOP ,	 
 MAT_Q_QAUDRD ,	 
 MAT_Q_QSIDET ,	 
 MAT_Q_QMIC ,	 
 MAT_Q_CLVL ,	 
 MAT_Q_QRXGAIN ,	 
 MAT_Q_QAUDMUT ,	 
	 
 MAT_Q_CLEVLE ,	 
 MAT_Q_AUDUPDATE ,	 
 MAT_Q_QEEC ,	 
 MAT_Q_QCODECTABLE ,	 
 MAT_Q_QEQTABLE ,	 
 MAT_Q_QTXCODECTABLE ,	 
 MAT_Q_QTXDSPGAIN ,	 
 MAT_Q_QDSPTABLE ,	 
	 
 MAT_Q_QAUDINIT ,	 
 MAT_Q_QAUDMOD ,	 
 MAT_Q_QIIC ,	 
 MAT_Q_QTTSETUP ,	 
 MAT_Q_QTTSMODE ,	 
 MAT_Q_QDAI ,	 
 MAT_Q_QFLDS ,	 
	 
 MAT_Q_QDTMFVOL ,	 
 MAT_Q_QLDTMF ,	 
	 
	 
 MAT_Q_QWDTMF ,	 
	 
	 
 MAT_Q_QTONEDET ,	 
	 
	 
 MAT_Q_QLTONE ,	 
	 
 MAT_Q_QFLST ,	 
 MAT_Q_QFDEL ,	 
 MAT_Q_QFOPEN ,	 
 MAT_Q_QFREAD ,	 
 MAT_Q_QFWRITE ,	 
 MAT_Q_QFSEEK ,	 
	 
	 
 MAT_Q_QFREADDELYSET ,	 
	 
 MAT_Q_QPTABLEVSTART ,	 
 MAT_Q_QFPOSITION ,	 
 MAT_Q_QFTUCAT ,	 
	 
	 
	 
 MAT_Q_QFCLOSE ,	 
	 
 MAT_Q_QFUPL ,	 
 MAT_Q_QFDWL ,	 
 MAT_Q_QFRENAME ,	 
	 
 MAT_Q_QFTCMD ,	 
	 
	 
 MAT_Q_QFMD5 ,	 
	 
 MAT_Q_QFSIZE ,	 
 // MAT_Q_QFOTADL ,	 
	 
	 
	 
	 
 MAT_Q_QDUMPCFG ,	 
 MAT_Q_QFLASH ,	 
 MAT_Q_QVOLCFG ,	 
 MAT_Q_QPMICCFG ,	 
 MAT_Q_QGPIOCFG ,	 
 MAT_Q_QFOTAUPDATE ,	 
 MAT_Q_QFATTEST ,	 
 MAT_Q_QLEDSTAT ,	 
 MAT_Q_QLEDCFG ,	 
	 
	 
	 
 MAT_Q_QADC ,	 
 MAT_Q_QWSETMAC ,	 
 MAT_Q_QTEMP ,	 
 MAT_Q_FLASH_TEST ,	 
 MAT_Q_FALSH_TEST ,	 
 MAT_Q_QVSIM ,	 
 MAT_Q_QMMSCFG ,	 
 MAT_Q_QMMSEDIT ,	 
 MAT_Q_QMMSEND ,	 
	 
	 
	 
 MAT_Q_CINDCFG ,	 
	 
 MAT_Q_QGPIOEXT ,	 
	 
	 
	 
	 
	 
	 
	 
 MAT_Q_QCUSDCVT ,	 
	 
	 
 MAT_Q_REMOTEWAKE ,	 
	 
	 
 MAT_Q_CWLAPOPT ,	 
 MAT_Q_CWLAP ,	 
 MAT_Q_CWMODE ,	 
	 
	 
 MAT_Q_QCELLSELECTCFG ,	 
	 
 MAT_Q_SIMPOLLCFG ,	 
	 
	 
 MAT_Q_CELL ,	 
 MAT_Q_CELLEX ,	 
	 
 MAT_Q_QIPV6CONFIG ,	 
	 
	 
 MAT_Q_QERASECOUNT ,	 
	 
	 
 MAT_Q_QISENDX ,	 
	 
	 
 MAT_Q_QISENDCRC ,	 
	 
 MAT_Q_RSRP ,	 
	 
	 
 MAT_Q_JAMDET_ENABLE ,	 
 MAT_Q_JAMDET_CFG ,	 
	 
	 
 MAT_Q_SAWCFG ,	 
	 
 MAT_Q_QPAGUPDATE ,	 
	 
	 
 MAT_Q_QCELLINFOEX ,	 
 MAT_Q_QCELLINFO ,	 
	 
 MAT_Q_GPIOCTRL ,	 
	 
	 
 MAT_Q_QNVFD ,	 
	 
	 
 MAT_Q_BLACKCELL ,	 
 MAT_Q_BLACKCELLCFG ,	 
	 
	 
 MAT_Q_QLWPINGCFG ,	 
	 
	 
	 
	 
 MAT_Q_QIMSXML ,	 
	 
 MAT_Q_QSCLKEX ,	 
 MAT_Q_QSCLKEXCFG ,	 
	 
	 
 MAT_Q_QUESTAT ,	 
	 
	 
	 
 MAT_Q_BLACKCELLEX ,	 
 MAT_Q_BLACKCELLCFGEX ,	 
 MAT_Q_BLACKCELLWEIGHT ,	 
 MAT_Q_BLACKLWIPCFG ,	 
	 
	 
 MAT_Q_BLACKEXTAND ,	 
	 
	 
	 
	 
	 
 MAT_Q_QTESTFLAG ,	 
	 
	 
 MAT_Q_QNWCFG ,	 
	 
	 
 MAT_Q_QNETWORKSTATUS ,	 
	 
 MAT_Q_QNWLOCK ,	 
	 
 MAT_Q_QAUTOAPN ,	 
 MAT_Q_QAUTOAPNURC ,	 
	 
	 
	 
	 
	 
 MAT_Q_NETDUALCHCFG ,	 
	 
 MAT_Q_QMNCLK ,	 
	 
 MAT_Q_QCEER ,	 
	 
 MAT_Q_COOSPPT ,	 
	 
 NUM_OF_MAT_CMD	 
 } MATCmdType , MATRspType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_SVC_0 ,	 
 MAT_SVC_1 ,	 
 MAT_SVC_2 ,	 
 MAT_SVC_3 ,	 
 MAT_SVC_4 ,	 
 MAT_SVC_5 ,	 
 MAT_SVC_6 ,	 
 MAT_SVC_7 ,	 
 MAT_SVC_8 ,	 
 MAT_SVC_9 ,	 
 MAT_SVC_10 ,	 
 MAT_SVC_11 ,	 
 MAT_SVC_12 ,	 
 MAT_SVC_13 ,	 
 MAT_SVC_14 ,	 
 MAT_SVC_15 ,	 
 MAT_SVC_16 ,	 
 MAT_SVC_17 ,	 
 MAT_SVC_18 ,	 
 MAT_SVC_19 ,	 
 MAT_SVC_20 ,	 
 MAT_SVC_21 ,	 
 MAT_SVC_22 ,	 
 MAT_SVC_23 ,	 
 MAT_SVC_24 ,	 
 MAT_SVC_25 ,	 
 MAT_SVC_26 ,	 
 MAT_SVC_27 ,	 
 MAT_SVC_28 ,	 
 MAT_SVC_29 ,	 
 MAT_SVC_30 ,	 
 MAT_SVC_31 ,	 
 MAT_SVC_32 ,	 
 MAT_SVC_33 ,	 
 MAT_SVC_34 ,	 
 MAT_SVC_35 ,	 
 MAT_SVC_36 ,	 
 MAT_SVC_37 ,	 
 MAT_SVC_38 ,	 
 MAT_SVC_39 ,	 
 MAT_SVC_40 ,	 
 MAT_SVC_41 ,	 
 MAT_SVC_42 ,	 
 MAT_SVC_43 ,	 
 MAT_SVC_44 ,	 
 MAT_SVC_45 ,	 
 MAT_SVC_46 ,	 
 MAT_SVC_47 ,	 
 MAT_SVC_48 ,	 
 MAT_SVC_49 ,	 
 MAT_SVC_50 ,	 
 MAT_SVC_51 ,	 
 MAT_SVC_52 ,	 
 MAT_SVC_53 ,	 
 MAT_SVC_54 ,	 
 MAT_SVC_55 ,	 
 MAT_SVC_56 ,	 
 MAT_SVC_57 ,	 
 MAT_SVC_58 ,	 
 MAT_SVC_59 ,	 
 MAT_SVC_60 ,	 
 MAT_SVC_61 ,	 
 MAT_SVC_62 ,	 
 MAT_SVC_63 ,	 
 NUM_OF_MAT_SVC	 
 } MATSvcId;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_SIM_0 ,	 
 MAT_SIM_1 ,	 
 NUM_OF_MAT_SIM	 
 } MATSimId;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 MAT_DATA_TYPE_DECIMAL ,	 
 MAT_DATA_TYPE_STRING ,	 
 MAT_DATA_TYPE_SET ,	 
 MAT_DATA_TYPE_RANGE ,	 
 } MATDataType;

//ICAT EXPORTED STRUCT 
 struct MATParameterRange 
 {	 
 int min ;	 
 int max ;	 
 };

//ICAT EXPORTED STRUCT 
 struct MATParameterItem_T ; 
 // ICAT EXPORTED STRUCT 
 typedef union MATDataValue_U {	 
 unsigned int decimal ;	 
 char *string_p ;	 
 struct MATParameterItem_T *set_p ;	 
 struct MATParameterRange range ;	 
 } MATDataValue;

//ICAT EXPORTED STRUCT 
 typedef struct MATParameter_T 
 {	 
 MATDataType type ;	 
 BOOL is_default ;	 
 MATDataValue value ;	 
 } MATParameter;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_RC_NULL ,	 
 MAT_RC_OK , // OK will be sent	 
 MAT_RC_ERROR , // ERROR will be sent	 
 MAT_RC_CME_ERROR , // CME ERROR will be sent	 
 MAT_RC_CMS_ERROR , // CMS ERROR will be sent	 
 MAT_RC_RESERVED	 
 } MATResultCode;

//ICAT EXPORTED STRUCT 
 typedef struct MATParameterItem_T 
 {	 
 UINT16 max_para_number ;	 
 UINT16 num_Retparameters ;	 
 MATParameter* RetPara ;	 
 } MATParameterItem , MATParameterSet;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_RET_CONFIRM ,	 
 MAT_RET_INDICATION	 
 } MATRetType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_PAR_RESULT_CODE_OK ,	 
 MAT_PAR_RESULT_CODE_ERROR	 
 } MATParseResultCode;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MAT_RET_SUCCESS ,	 
 MAT_RET_TOO_MANY_PARAMETERS ,	 
 MAT_RET_CURRENT_CH_HAS_CMD_PROCESSING ,	 
 MAT_RET_PARA_TYPE_UNSUPPORT ,	 
 MAT_RET_NULL_CLINET_TAG_POINTER ,	 
 MAT_RET_NUM_PARA_ERROR ,	 
 MAT_RET_PARA_TYPE_ERROR ,	 
 MAT_RET_HANDLER_FAILURE ,	 
 MAT_RET_FIND_FREE_CHANNEL_ERROR	 
 } MATRecvRetType;

//ICAT EXPORTED STRUCT 
 typedef struct MATReturnPara_T 
 {	 
 MATResultCode resultCode ;	 
 UINT16 numItems ;	 
 MATParameterItem* RetParaItems ;	 
 MATRspType cmd_type ;	 
 } MATReturnPara;

typedef union utlAtDataValue_U {
 unsigned int decimal ;
 unsigned int hexadecimal ;
 unsigned int binary ;
 char *string_p ;
 char *qstring_p ;
 char *dial_string_p ;
 } utlAtDataValue_T , *utlAtDataValue_P ;
typedef const utlAtParameterValue_T *utlAtParameterValue_P2c ;
typedef const utlAtParameter_T *utlAtParameter_P2c ;
typedef const utlAtDceIoConfig_T *utlAtDceIoConfig_P2c ;
typedef const utlAtSoundConfig_T *utlAtSoundConfig_P2c ;
typedef utlReturnCode_T ( *utlAtGetParameterFunction_P ) ( const utlAtParameterOp_T op , const char *command_name_p , const utlAtParameterValue_P2c parameter_values_p , const size_t num_parameters , const char *info_text_p , unsigned int *xid_p , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtSetParameterFunction_P ) ( const utlAtParameterOp_T op , const char *command_name_p , const utlAtParameterValue_P2c parameter_values_p , const size_t num_parameters , const char *info_text_p , unsigned int *xid_p , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtDceIoConfigFunction_P ) ( const utlAtDceIoConfig_P2c dce_io_config_p , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtSoundConfigFunction_P ) ( const utlAtSoundConfig_P2c sound_config_p , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtSParameterFunction_P ) ( const unsigned int parameter_num , const unsigned int parameter_value , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtSaveDialStringFunction_P ) ( const char *location_name_p , const char *dial_string_p , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtRetrieveDialStringFunction_P ) ( const char **location_name_pp , const char **dial_string_pp , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtReplyFunction_P ) ( const char *string_p , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtTxLineDataFunction_P ) ( const unsigned char *octets_p , const size_t n , void *arg_p ) ;
typedef utlReturnCode_T ( *utlAtDriverRequestFunction_P ) ( const utlAtParser_P parser_p , const utlAtDriverRequest_T request , void *arg_p , ... ) ;
typedef utlReturnCode_T ( *utlAtCommandSyntaxFunction_P ) ( const utlAtParameterOp_T op , const char *command_name_p , const utlAtParameterValue_P2c parameter_values_p , const size_t num_parameters , const char *info_text_p , unsigned int *xid_p , void *arg_p ) ;
typedef unsigned int ( *utlAtGetAtcmdTimeoutValueFunction_P ) ( const utlAtCommand_P2c cmd_p , const utlAtAsyncOp_T op ) ;
typedef int ( *utlAtcmdTimeoutErrorFunction_P ) ( unsigned int atHandle ) ;
typedef void ( *utlAtcmdContinuousTimeoutFunction_P ) ( void ) ;
typedef int ( *utlAtParserTriggerFunction_P ) ( const utlAtParser_P parser_p ) ;
typedef void ( *utlSetAutoAnswerDelay_P ) ( void *arg_p , unsigned int delay_seconds ) ;
typedef void ( *utlGetAutoAnswerDelay_P ) ( void *arg_p , unsigned short *delay_seconds ) ;
typedef utlReturnCode_T ( *utlSendToProxy_P ) ( const char *command_name_p , const utlAtParameterOp_T op , const char *parameters_string_p , unsigned int *xid_p , void *arg_p ) ;
typedef unsigned int ( *utlIsProxyReq_P ) ( const char *cmdName , utlAtParameterOp_T cmdOp , unsigned int parserId ) ;
typedef void ( *utlIncProxyTOCounter_P ) ( unsigned int incValue ) ;
typedef const utlAtCommand_T *utlAtCommand_P2c ;
typedef const utlAtDialStringOptions_T *utlAtDialStringOptions_P2c ;
typedef const utlAtAsyncResponse_T *utlAtAsyncResponse_P2c ;
typedef const utlAtAsyncResponses_T *utlAtAsyncResponses_P2c ;
typedef const utlAtParser_T *utlAtParser_P2c ;
typedef void ( *CommandAddress ) ( void ) ;
typedef char* CommandProto ;
typedef const char * DiagDBVersion ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PROTOCOL_TYPE_0 = 0 ,	 
 MAX_PROTOCOL_TYPES	 
 } ProtocolType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 BOOL bEnabled ; // enable / disable the trace logging feature	 
 ProtocolType eProtocolType ; // protocol type for communication with ICAT , currently only protocol type 0 is supported	 
 UINT16 nMaxDataPerTrace ; // for each trace , what is the maximum data length to accompany the trace , in protocol type 0 , this is relevant only to DSP messages	 
 } DiagLoggerDefs;

typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef unsigned long long UINT64 ;
typedef unsigned long TimeIn32KhzUnit ;
typedef void ( *TickCallbackPtr ) ( UINT32 ) ;
typedef TimeIn32KhzUnit ( *SuspendCallbackPtr ) ( void ) ;
typedef void ( *PrepareTimeCallbackPtr ) ( void ) ;
typedef void ( *GPIOCallback ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_PIN_NOT_ASSIGNED = -1 ,	 
	 
 GPIO_PIN_0=0 , GPIO_PIN_1 , GPIO_PIN_2 , GPIO_PIN_3 , GPIO_PIN_4 , GPIO_PIN_5 , GPIO_PIN_6 , GPIO_PIN_7 ,	 
 GPIO_PIN_8 , GPIO_PIN_9 , GPIO_PIN_10 , GPIO_PIN_11 , GPIO_PIN_12 , GPIO_PIN_13 , GPIO_PIN_14 , GPIO_PIN_15 ,	 
 GPIO_PIN_16 , GPIO_PIN_17 , GPIO_PIN_18 , GPIO_PIN_19 , GPIO_PIN_20 , GPIO_PIN_21 , GPIO_PIN_22 , GPIO_PIN_23 ,	 
 GPIO_PIN_24 , GPIO_PIN_25 , GPIO_PIN_26 , GPIO_PIN_27 , GPIO_PIN_28 , GPIO_PIN_29 , GPIO_PIN_30 , GPIO_PIN_31 ,	 
 GPIO_PIN_32 ,	 
 // #ifndef SILICON_PV2	 
 GPIO_PIN_33 , GPIO_PIN_34 , GPIO_PIN_35 , GPIO_PIN_36 , GPIO_PIN_37 , GPIO_PIN_38 , GPIO_PIN_39 ,	 
 GPIO_PIN_40 , GPIO_PIN_41 , GPIO_PIN_42 , GPIO_PIN_43 , GPIO_PIN_44 , GPIO_PIN_45 , GPIO_PIN_46 , GPIO_PIN_47 ,	 
 GPIO_PIN_48 , GPIO_PIN_49 , GPIO_PIN_50 , GPIO_PIN_51 , GPIO_PIN_52 , GPIO_PIN_53 , GPIO_PIN_54 , GPIO_PIN_55 ,	 
 GPIO_PIN_56 , GPIO_PIN_57 , GPIO_PIN_58 , GPIO_PIN_59 , GPIO_PIN_60 , GPIO_PIN_61 , GPIO_PIN_62 , GPIO_PIN_63 ,	 
 // #endif // _TAVOR_HARBELL_	 
	 
 // #if 1 // quectel define for build defined ( GPIO_128_ENTRIES )	 
 GPIO_PIN_64 , GPIO_PIN_65 , GPIO_PIN_66 , GPIO_PIN_67 , GPIO_PIN_68 , GPIO_PIN_69 , GPIO_PIN_70 , GPIO_PIN_71 ,	 
 GPIO_PIN_72 , GPIO_PIN_73 , GPIO_PIN_74 , GPIO_PIN_75 , GPIO_PIN_76 , GPIO_PIN_77 , GPIO_PIN_78 , GPIO_PIN_79 ,	 
 GPIO_PIN_80 , GPIO_PIN_81 , GPIO_PIN_82 , GPIO_PIN_83 , GPIO_PIN_84 , GPIO_PIN_85 , GPIO_PIN_86 , GPIO_PIN_87 ,	 
 GPIO_PIN_88 , GPIO_PIN_89 , GPIO_PIN_90 , GPIO_PIN_91 , GPIO_PIN_92 , GPIO_PIN_93 , GPIO_PIN_94 , GPIO_PIN_95 ,	 
 GPIO_PIN_96 , GPIO_PIN_97 , GPIO_PIN_98 , GPIO_PIN_99 , GPIO_PIN_100 , GPIO_PIN_101 , GPIO_PIN_102 , GPIO_PIN_103 ,	 
 GPIO_PIN_104 , GPIO_PIN_105 , GPIO_PIN_106 , GPIO_PIN_107 , GPIO_PIN_108 , GPIO_PIN_109 , GPIO_PIN_110 , GPIO_PIN_111 ,	 
 GPIO_PIN_112 , GPIO_PIN_113 , GPIO_PIN_114 , GPIO_PIN_115 , GPIO_PIN_116 , GPIO_PIN_117 , GPIO_PIN_118 , GPIO_PIN_119 ,	 
 GPIO_PIN_120 , GPIO_PIN_121 , GPIO_PIN_122 , GPIO_PIN_123 , GPIO_PIN_124 , GPIO_PIN_125 , GPIO_PIN_126 , GPIO_PIN_127 ,	 
 // #endif // INTEL_2CHIP_PLAT_BVD	 
 GPIO_MAX_AMOUNT_OF_PINS	 
	 
	 
	 
 } GPIO_PinNumbers;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_RC_OK = 1 ,	 
	 
 GPIO_RC_INVALID_PORT_HANDLE = -100 ,	 
 GPIO_RC_NOT_OUTPUT_PORT ,	 
 GPIO_RC_NO_TIMER ,	 
 GPIO_RC_NO_FREE_HANDLE ,	 
 GPIO_RC_AMOUNT_OUT_OF_RANGE ,	 
 GPIO_RC_INCORRECT_PORT_SIZE ,	 
 GPIO_RC_PORT_NOT_ON_ONE_REG ,	 
 GPIO_RC_INVALID_PIN_NUM ,	 
 GPIO_RC_PIN_USED_IN_PORT ,	 
 GPIO_RC_PIN_NOT_FREE ,	 
 GPIO_RC_PIN_NOT_LOCKED ,	 
 GPIO_RC_NULL_POINTER ,	 
 GPIO_RC_PULLED_AND_OUTPUT ,	 
 GPIO_RC_INCORRECT_PORT_TYPE ,	 
 GPIO_RC_INCORRECT_TRANSITION_TYPE ,	 
 GPIO_RC_INCORRECT_DEBOUNCE ,	 
 GPIO_RC_INCORRECT_DIRECTION ,	 
 GPIO_RC_INCORRECT_INIT_VALUE ,	 
 GPIO_RC_INTC_ERROR ,	 
 GPIO_RC_PRM_ERROR ,	 
 GPIO_RC_PIN_LOCKED ,	 
 } GPIO_ReturnCode;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_PIN_FREE_FOR_USE = 0 ,	 
 GPIO_PIN_USE_IN_PORT ,	 
 GPIO_PIN_USE_IN_INTERRUPT ,	 
 GPIO_PIN_USE_IN_PORT_WITH_INTERRUPT ,	 
 GPIO_PIN_LOCKED	 
 } GPIO_PinUsage;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 GPIO_PinUsage pinUsage ;	 
 GPIOPinDirection direction ;	 
 } GPIO_PinStatus;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_INITIAL_VALUE_NO_CHANGE = 0 ,	 
 GPIO_INITIAL_VALUE_LOW=0 ,	 
 GPIO_INITIAL_VALUE_HIGH	 
 } GPIO_BitInitialValue;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_PULL_UP_DOWN_DISABLE = 0 ,	 
 GPIO_PULL_UP_ENABLE ,	 
 GPIO_PULL_DOWN_ENABLE	 
 } GPIO_PullUpDown;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 GPIO_PinNumbers pinNumber ;	 
 GPIOPinDirection direction ;	 
 GPIOTransitionType transitionType ;	 
 GPIO_Debounce debounce ;	 
 GPIOPullUpDown pullUpDown ;	 
 GPIO_BitInitialValue initialValue ;	 
 } GPIO_PinConfiguration;

typedef void ( *GPIO_ISR ) ( void ) ;
typedef UINT32 INTC_InterruptPriorityTable [ MAX_INTERRUPT_CONTROLLER_SOURCES ] ;
typedef UINT32 INTC_InterruptInfo ;
typedef void ( *INTC_ISR ) ( INTC_InterruptInfo interruptInfo ) ;
typedef void ( *PMCNotifyEventFunc ) ( UINT64 eventRegs ) ;
typedef void ( *PMCGetStatusNotifyFunc ) ( UINT16 status ) ;
typedef void ( *PMCReadCallback ) ( UINT8 *dataBuffPtr , UINT16 dataSize , UINT16 userId ) ;
typedef void ( *PMCWriteCallback ) ( UINT16 dataBuffPtr ) ;
typedef void ( *PMCGetGPADCValueNotifyFunc ) ( PMC_adc_reg_t reg , UINT16 value ) ;
typedef void ( * ReadingCallback ) ( int ) ;
typedef void ( * LTETempReadingCallback ) ( unsigned short , unsigned short ) ;
typedef void ( * ReadingCallbackBoth ) ( BOOL , int , int ) ;
typedef union
 {
 UINT8 autoControl ;
 UINT8 autoControl2 ;
 UINT8 manControl ;
 } adcModeCntrl_t ;
typedef union
 {
 UINT64 all ;
 Registers_ts regs ;
 } PMCEvents ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 SHD_POWER_DOWN ,	 
 SHD_RESET ,	 
 SHD_GHOST ,	 
 SHD_SW_ERROR /* EEHandler triggered the reset */	 
 } ShutDownType_te;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 RR_NORMAL_POWER_ON = 0x00 , // default , not combined with others	 
 RR_WATCH_DOG_TIMEOUT = 0x01 ,	 
 RR_SOFTWARE_GENERATED = 0x02 ,	 
 RR_CHARGING_BATTERY = 0x04 ,	 
 RR_LOW_BATTERY = 0x08 ,	 
 RR_ALARM_POWER_ON = 0x10 ,	 
 RR_EXT_POWER_ON = 0x20	 
 } 
 StartupReason_te;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 RE_RTC_ALARM = 0x01	 
 } StartupExtInd_te;

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PMU_POR = 1 ,	 
 PMU_EMR ,	 
 PMU_WDTR = ( PMU_EMR+2 )	 
 } PMU_LastResetStatus;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_INT_IFC ,	 
 DIAG_EXT_IFC	 
 } DIAG_IF_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_DEV_USB ,	 
 DIAG_DEV_SD ,	 
 DIAG_DEV_FS ,	 
 DIAG_DEV_UART ,	 
 DIAG_DEV_SPI ,	 
 DIAG_DEV_NONE	 
 } DIAG_DEV_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 SULOG_DEV_USB ,	 
 SULOG_DEV_SD	 
 } SULOG_DEV_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 EEH_DUMP_DEV_USB_SD ,	 
 EEH_DUMP_DEV_SPI	 
 } EEH_DUMP_DEV_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_START_PS_OFF ,	 
 DIAG_START_PS_ON	 
 } DIAG_START_PS_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_UART_SPEED_115200 ,	 
 DIAG_UART_SPEED_460800 ,	 
 DIAG_UART_SPEED_921600 ,	 
 DIAG_UART_DISABLE	 
 } DIAG_UART_SPEED_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 DIAG_IF_TYPE useIntIf ; /* use internal interface or external interface */	 
 DIAG_UART_SPEED_TYPE useHighSpeedUART ; /* high speed UART ( 460800 ) or low speed UART ( 115200 ) */	 
 // DIAG_MEM_SWITCH diagMemSwitch ;	 
 BOOL GLFeatureFlag ;	 
 DIAG_START_PS_TYPE diagStartPS ;	 
 DIAG_DEV_TYPE diagDevType ;	 
 SULOG_DEV_TYPE sulogDevType ;	 
 EEH_DUMP_DEV_TYPE eehDumpDevType ;	 
 // DIAG_MEM_SWITCH diagMemSwitch ;	 
 BOOL usbUserMode ;	 
 } diagCfgDataS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 dbID ;	 
 UINT32 filterBitLength ;	 
 UINT32 reserved [ 6 ] ;	 
 } DIAG_Nvm_Filter_File_Header_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 LOG_DISABLE = 0x0 ,	 
 UART_LOG_ENABLE = 0x1 ,	 
 ACAT_LOG_ENABLE = 0x2	 
 } Log_ConfigE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MSG_DISABLE = 0x0 ,	 
 ACAT_MSG_ENABLE = 0x1	 
 } Msg_ConfigE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 RTI_LOG_DISABLE = 0x0 ,	 
 RTI_DUMP_ENABLE = 0x1 ,	 
 RTI_TASK_ENABLE = 0x2 ,	 
 RTI_MIPS_ENABLE = 0x3	 
 } RTI_ConfigE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 Log_ConfigE log_cfg ;	 
 Msg_ConfigE msg_cfg ;	 
 RTI_ConfigE rti_cfg ;	 
 } Log_ConfigS;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 YMODEM_DISABLE = 0x0 ,	 
 YMODEM_ENABLE = 0x1	 
 } Ymodem_Dump_config;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 Ymodem_Dump_config config ;	 
 } Ymodem_Dump_type;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* MIFI driver*/	 
 USB_GENERIC_MIFI_DRIVER = 0x0 ,	 
 USB_MARVELL_MIFI_DRIVER = 0x1 ,	 
 USB_ASR_MIFI_DRIVER = 0x2 ,	 
 USB_GENERIC_MOD_DRIVER = 0x10 ,	 
 USB_GENERIC_MOD_ECM_DRIVER = 0x12 ,	 
	 
 USB_CDC_ACM_ONLY_DRIVER = 0x13 ,	 
	 
 USB_DIAG_UAC_DRIVER = 0x14 ,	 
	 
 /* MBIM driver*/	 
 USB_MBIM_ONLY_DRIVER = 0x40 ,	 
 USB_MBIM_GENERIC_DRIVER = 0x41 ,	 
 USB_MBIM_MAX_DRIVER = 0x4F ,	 
	 
 /* Other driver*/	 
 USB_CDROM_ONLY_DRIVER = 0x91 ,	 
 USB_CDROM_DIAG_DRIVER = 0x92 ,	 
 USB_DIAG_ONLY_DRIVER = 0x93 ,	 
 USB_MODEM_ONLY_DRIVER = 0x94 ,	 
 USB_MODEM_DIAG_DRIVER = 0x95 ,	 
	 
 USB_MAX_DRIVER = 0xFF	 
 } Usb_driver_typeE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MASS_STORAGE_DISABLE = 0x0 ,	 
 MASS_STORAGE_ENABLE = 0x1	 
 } MassStorage_ConfigE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 USB_AUTO_INSTALL_DISABLE = 0x0 ,	 
 USB_AUTO_INSTALL_ENABLE = 0x1	 
 } Usb_auto_install_type;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 USB_OS_DETECT_DISABLE = 0x0 ,	 
 USB_OS_DETECT_ENABLE = 0x1	 
 } Usb_OS_detect_type;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 Usb_driver_typeE usb_driver ;	 
 MassStorage_ConfigE mass_storage ;	 
 Usb_auto_install_type auto_install ;	 
 Usb_OS_detect_type os_detect ;	 
 } Usb_DriverS;

typedef UINT8 UART_Activity ;
//ICAT EXPORTED STRUCT 
 typedef struct /* This is structure of the UART Configuration */ 
 {	 
 UART_OpMode opMode ; /* fifo mode , non fifo mode or DMA for basic interface*/	 
 UART_TriggerLevel triggerLevel ; /* the trigger level interrupt on 1 , 8 , 16 , 32 */	 
 UART_BaudRates baudRate ; /* the rate of the transmit and the receive up to 111520 ( default - 9600 ) .*/	 
 UART_WordLen numDataBits ; /* 5 , 6 , 7 , or 8 number of data bits in the UART data frame ( default - 8 ) . */	 
 UART_StopBits stopBits ; /* 1 , 1.500000 or 2 stop bits in the UART data frame ( default - 1 ) . */	 
 UART_ParityTBits parityBitType ; /* Even , Odd or no-parity bit type in the UART data frame ( default - Non ) . */	 
 UART_InterfaceType interfaceType ; /* number of interface that the UART driver supplies ( default - UART_IF_TYPE_L2 ) */	 
 BOOL modemSignal ; /* enable operate modem - TRUE , disable modem - FALSE */	 
 BOOL flowControl ; /* enable Auto flow Control - TRUE , disable Auto flow Control - FALSE */	 
 UINT8 sleepMode ; /* enable sleep mode - TRUE , more fine control - see UARTSleepMode enum */	 
 BOOL auto_baud ; /* enable auto_baud , auto-baud-rate detection within the UART ( default - FALSE ) */	 
 UART_SIRConfigure sirIrDA ;	 
 } UARTConfiguration;

//ICAT EXPORTED ENUM 
 typedef enum // change the order -1 to + 
 {	 
 UART_RC_OK = 1 , /* 1 - no errors */	 
	 
 UART_RC_PORT_NUM_ERROR = -100 , /* -100 - Error in the UART port number */	 
 UART_RC_NO_DATA_TO_READ , /* -99 - Eror no data to read from the FIFO UART */	 
 UART_RC_ILLEGAL_BAUD_RATE , /* -98 - Error in the UART Bayd Rate */	 
 UART_RC_UART_PARITY_BITS_ERROR , /* -97 - Error in parity bit */	 
 UART_RC_UART_ONE_STOP_BIT_ERROR , /* -96 - Error in one stop bit */	 
 UART_RC_ONE_HALF_OR_TWO_STOP_BIT_ERROR , /* -95 - Error in two stop bit */	 
 UART_RC_BAD_INTERFACE_TYPE , /* -94 - Error in the Interface Type */	 
 UART_RC_UART_NOT_AVAILABLE , /* -93 - Error in try to open UART that is open */	 
 UART_RC_NO_DATA_TO_WRITE , /* -92 - Error No data to writ the len = 0 */	 
 UART_RC_NOT_ALL_BYTE_WRITTEN , /* -91 - Error Not all the Byte write to the UART FIFO */	 
 UART_RC_ISR_ALREADY_BIND , /* -90 - Error try to bind ISR for Basic Interface */	 
 UART_RC_WRONG_ISR_UNBIND , /* -89 - Error in the UnBind ISR for Basic Interface */	 
 UART_RC_FIFO_NOT_EMPTY , /* -88 - Error , the UART FIFO not empty */	 
 UART_RC_UART_OPEN , /* -87 - Error try chance the configurr when the UART open */	 
 UART_RC_GPIO_ERR , /* -86 - Error in the Configure of the GPIO */	 
 UART_RC_IRDA_CONFIG_ERR , /* -85 - Illegal IrDA configuration */	 
 UART_RC_TX_DMA_ERR /* -84 - DMA TX Error */	 
 } UART_ReturnCode;

typedef void ( *UARTNotifyInterrupt ) ( UART_Port ) ;
typedef void ( *UsbLogPrint_t ) ( const char * , ... ) ;
typedef void ( *StateChangedCb ) ( UINT8 , INT32 , void * ) ;
//ICAT EXPORTED ENUM 
 enum 
 {	 
 SIM_0 ,	 
 SIM_1 ,	 
 NUM_OF_SIM	 
 };

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 CHANNEL_MMI ,	 
 CHANNEL_IMS ,	 
 NUM_OF_CHANNEL_TYPE	 
 } AT_CHANNEL_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct _TelAtpCtrl 
 {	 
 void *taskRef ;	 
 UINT32 iFd ;	 
 char *path ;	 
 UINT32 index ;	 
 TelMsgDataMode smsDataEntryMode ;	 
 BOOL bEnable ;	 
 BOOL bIsSinkMode ;	 
	 
 TelAtpPdpCtx pdpCtx ;	 
 TelAtpTftCtx tftCtx ;	 
	 
 UINT32 reqHandle ;	 
 UINT32 cnmaReply ; /* used in +CNMA */	 
 UINT32 smsOverNas ;	 
 UINT32 cnmaFlag ; // 0 -- AT+CNMA , 1 -- AT*CNMA	 
	 
 Quec_TelAtpDataEntry pTelAtpDataEntry ;	 
 void ( *cb ) ( void *obj , void* arg ) ;	 
	 
 } TelAtpCtrl;

typedef union
 {
 / / quec_ioctl_default_type pin_state ; / / dcd , ri state
 quec_pin_level_value_e pin_level ;
 } quec_ioctl_param ;
typedef void ( *USBDeviceTransactionCompletedNotifyFn ) ( USBDevice_EndpointE ,
 UINT8 * ,
 UINT32 ,
 BOOL ) ;
typedef void ( *USBDeviceStatusNotifyFn ) ( USBDevice_StatusE ) ;
typedef void ( *USBDeviceVendorClassRequestNotifyFn ) ( USB_SetupCmdS * ) ;
typedef void ( *USBDeviceEndpointZeroNotifyFn ) ( USB_SetupCmdS * ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointMultiTransmit ) ( USBDevice_EndpointE endpoint ,
 UINT32 numOfBuffers ,
 USBDevice_MultiTransmitListS *pMultiList ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointTransmit ) ( USBDevice_EndpointE endpoint ,
 UINT8 *pTxBuffer ,
 UINT32 txLength ,
 BOOL autoZLP ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointCancelTransmit ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointCancelReceive ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointReceiveCompleted ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointReceiveCompletedExt ) ( USBDevice_EndpointE endpoint ,
 UINT8 *pRxBuffer ,
 UINT32 next_packet_expected_length ,
 BOOL expect_zlp ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointReceive ) ( USBDevice_EndpointE endpoint ,
 UINT8 *pRxBuffer ,
 UINT32 length ,
 BOOL expect_zlp ) ;
typedef void ( *fpUSBDeviceVendorClassResponse ) ( UINT8 *pBuffer ,
 UINT16 bufferLength ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointAbort ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointClose ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointOpen ) ( USBDevice_EndpointE endpoint ,
 USBDevice_UsageTypeE usageType ,
 UINT8 dmaChannel ,
 UINT8 *pDescBuffer ,
 UINT16 descBufferLength ,
 USBDeviceTransactionCompletedNotifyFn transactionCompletedNotifyFn ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointStall ) ( USBDevice_EndpointE endpoint ) ;
typedef void ( *fpUSBDevicePhase2Init ) ( void ) ;
typedef BOOL ( *fpUSBDeviceIsControllerEnabled ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum CISGID {	 
 CI_SG_ID_FIRST=1 ,	 
 CI_SG_ID_CC = CI_SG_ID_FIRST ,	 
 CI_SG_ID_SS ,	 
 CI_SG_ID_MM ,	 
 CI_SG_ID_PB ,	 
 CI_SG_ID_SIM ,	 
 CI_SG_ID_MSG ,	 
 CI_SG_ID_PS ,	 
 CI_SG_ID_DAT ,	 
 CI_SG_ID_DEV ,	 
 CI_SG_ID_HSCSD ,	 
 CI_SG_ID_DEB ,	 
 CI_SG_ID_ATPI ,	 
 CI_SG_ID_PL ,	 
 CI_SG_ID_OAM ,	 
 CI_SG_ID_NEXTAVAIL /* This must always be the last entry in the list */	 
 } _CiServiceGroupId;

//ICAT EXPORTED ENUM 
 typedef enum CIRC {	 
 CIRC_SUCCESS=0 ,	 
 CIRC_FAIL ,	 
 CIRC_INTERLINK_FAIL , /* the link between application subsystem and communication subsystem is broken */	 
 CIRC_SH_NULL_CONFIRM_CB ,	 
 CIRC_SH_NULL_FREEREQMEM_CB ,	 
 CIRC_SH_INVALID_HANDLE ,	 
 CIRC_SH_INVALID_OPER ,	 
 CIRC_SH_NULL_REQPARAS ,	 
 CIRC_SG_INVALID_HANDLE ,	 
 CIRC_SG_RESERVED_PRIMID ,	 
 CIRC_SG_NULL_REQPARAS ,	 
 CIRC_SG_NULL_RSPPARAS ,	 
 CIRC_NUM_RESCODES	 
 } _CiReturnCode;

typedef UINT16 CiReturnCode ;
//ICAT EXPORTED ENUM 
 typedef enum CISHOPER {	 
 CI_SH_OPER_REGISTERSH = 0 ,	 
 CI_SH_OPER_DEREGISTERSH ,	 
 CI_SH_OPER_GETVERSION ,	 
 CI_SH_OPER_REGISTERSG ,	 
 CI_SH_OPER_DEREGISTERSG ,	 
 CI_SH_OPER_REGISTERDEFSG ,	 
 CI_SH_OPER_DEREGISTERDEFSG ,	 
 CI_SH_QUERYEXTENDED ,	 
 CI_SH_QUERYEXTENDEDSERVICEPRIM ,	 
 CI_SH_QUERYEXTENDEDSERVICEGROUP ,	 
 CI_SH_OPER_CIVERSION_NEGO_REQ ,	 
 CI_SH_OPER_CIVERSION_NEGO_CNF ,	 
 CI_SH_NUMOPERS	 
 } CiShOper;

typedef UINT8 CiBoolean ;
typedef unsigned char Boolean ;
typedef UINT8 CiServiceGroupID ;
typedef UINT16 CiPrimitiveID ;
typedef UINT32 CiServiceHandle ;
typedef UINT32 CiRequestHandle ;
typedef UINT32 CiIndicationHandle ;
typedef UINT32 CiShHandle ;
typedef UINT32 CiShOpaqueHandle ;
typedef UINT32 CiShRequestHandle ;
typedef UINT32 CiSgOpaqueHandle ;
typedef void ( *CiShConfirm ) ( CiShOpaqueHandle opShHandle , CiShOper oper , void* cnfParas , CiShRequestHandle opHandle ) ;
typedef void ( *CiConfirm ) ( CiSgOpaqueHandle opSgOpaqueHandle , CiServiceGroupID id , CiPrimitiveID primId , CiRequestHandle reqHandle , void* paras ) ;
typedef void ( *CiIndicate ) ( CiSgOpaqueHandle opSgOpaqueHandle , CiServiceGroupID id , CiPrimitiveID primId , CiIndicationHandle indHandle , void* paras ) ;
typedef void ( *CiShFreeReqMem ) ( CiShOpaqueHandle opShFreeHandle , CiShOper oper , void* reqParas ) ;
typedef void ( *CiShFreeCnfMem ) ( CiShOpaqueHandle opShFreeHandle , CiShOper oper , void* cnfParas ) ;
typedef void ( *CiSgFreeReqMem ) ( CiSgOpaqueHandle opSgFreeHandle , CiServiceGroupID id , CiPrimitiveID primId , void* reqParas ) ;
typedef void ( *CiSgFreeRspMem ) ( CiSgOpaqueHandle opSgFreeHandle , CiServiceGroupID id , CiPrimitiveID primId , void* rspParas ) ;
typedef void ( *CiSgFreeCnfMem ) ( CiSgOpaqueHandle opSgFreeHandle , CiServiceGroupID id , CiPrimitiveID primId , void* cnfParas ) ;
typedef void ( *CiSgFreeIndMem ) ( CiSgOpaqueHandle opSgFreeHandle , CiServiceGroupID id , CiPrimitiveID primId , void* indParas ) ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPrimList_struct {	 
 UINT16 size ; /* actual number of primitive IDs that are held in the pList */	 
 CiPrimitiveID primId [ 156 ] ;	 
 } CiPrimitiveList;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperRegisterShCnf_struct {	 
 CiReturnCode rc ;	 
 CiShHandle handle ;	 
 CiShOpaqueHandle opShFreeHandle ;	 
 CiShFreeCnfMem ciShFreeCnfMem ;	 
 } CiShOperRegisterShCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperDeregisterShCnf_struct {	 
 CiReturnCode rc ;	 
 } CiShOperDeregisterShCnf;

//ICAT EXPORTED STRUCTURE 
 typedef struct CiShOperGetVersionReq_struct {	 
 CiServiceGroupID id ;	 
 } CiShOperGetVersionReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperGetVersionCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceGroupID id ;	 
 UINT8 major ;	 
 UINT8 minor ;	 
 } CiShOperGetVersionCnf;

//ICAT EXPORTED STRUCTURE 
 typedef struct CiShOperRegisterDefaultSgReq_struct {	 
 CiSgOpaqueHandle opSgDefCnfHandle ;	 
 CiConfirm ciCnfDef ;	 
 CiIndicate ciIndDef ;	 
 CiSgOpaqueHandle opSgDefIndHandle ;	 
 } CiShOperRegisterDefaultSgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperRegisterDefaultSgCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceHandle defHandle ;	 
 CiSgOpaqueHandle opSgFreeDefCnfHandle ;	 
 CiSgFreeCnfMem ciSgFreeDefCnfMem ;	 
 CiSgOpaqueHandle opSgFreeDefIndHandle ;	 
 CiSgFreeIndMem ciSgFreeDefIndMem ;	 
 } CiShOperRegisterDefaultSgCnf;

//ICAT EXPORTED STRUCTURE 
 typedef struct CiShOperDeregisterDefaultSgReq_struct {	 
 CiServiceHandle defHandle ;	 
 } CiShOperDeregisterDefaultSgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperDeregisterDefaultSgCnf_struct {	 
 CiReturnCode rc ;	 
 } CiShOperDeregisterDefaultSgCnf;

//ICAT EXPORTED STRUCTURE 
 typedef struct CiShOperRegisterSgReq_struct {	 
 CiServiceGroupID id ;	 
 CiSgOpaqueHandle opSgCnfHandle ;	 
 CiConfirm ciConfirm ;	 
 CiSgOpaqueHandle opSgIndHandle ;	 
 CiIndicate ciIndicate ;	 
 CiSgOpaqueHandle opSgFreeReqHandle ;	 
 CiSgFreeReqMem ciSgFreeReqMem ;	 
 CiSgOpaqueHandle opSgFreeRspHandle ;	 
 CiSgFreeRspMem ciSgFreeRspMem ;	 
 } CiShOperRegisterSgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperRegisterSgCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceGroupID id ;	 
 CiServiceHandle handle ;	 
 CiSgOpaqueHandle opSgFreeCnfHandle ;	 
 CiSgFreeCnfMem ciSgFreeCnfMem ;	 
 CiSgOpaqueHandle opSgFreeIndHandle ;	 
 CiSgFreeIndMem ciSgFreeIndMem ;	 
 } CiShOperRegisterSgCnf;

//ICAT EXPORTED STRUCTURE 
 typedef struct CiShOperDeregisterSgReq_struct {	 
 CiServiceHandle handle ;	 
 } CiShOperDeregisterSgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperDeregisterSgCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceGroupID id ;	 
 } CiShOperDeregisterSgCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiShQueryExtendedReq_struct {	 
 CiServiceGroupID id ;	 
 } CiShQueryExtendedReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShQueryExtendedCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceGroupID id ;	 
 UINT16 mSize ;	 
 CiPrimitiveList ciPrimList ;	 
 } CiShQueryExtendedCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiShQueryExtendedServicePrimReq_struct {	 
 CiServiceGroupID id ;	 
 CiPrimitiveID primId ;	 
 } CiShQueryExtendedServicePrimReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShQueryExtendedServicePrimCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceGroupID id ;	 
 CiPrimitiveID primId ;	 
 CiBoolean supported ;	 
 } CiShQueryExtendedServicePrimCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiShQueryExtendedServiceGroupReq_struct {	 
 CiServiceGroupID id ;	 
 } CiShQueryExtendedServiceGroupReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShQueryExtendedServiceGroupCnf_struct {	 
 CiReturnCode rc ;	 
 CiServiceGroupID id ;	 
 CiBoolean supported ;	 
 } CiShQueryExtendedServiceGroupCnf;

typedef UINT16 CiVersion ;
//ICAT EXPORTED STRUCT 
 typedef struct CiShOperCIVersionNegoReq_struct 
 {	 
 UINT8 ccSuppVerNum ;	 
 UINT8 ssSuppVerNum ;	 
 UINT8 mmSuppVerNum ;	 
 UINT8 pbSuppVerNum ;	 
 UINT8 simSuppVerNum ;	 
 UINT8 msgSuppVerNum ;	 
 UINT8 psSuppVerNum ;	 
 UINT8 datSuppVerNum ;	 
 UINT8 devSuppVerNum ;	 
 UINT8 hscsdSuppVerNum ;	 
 UINT8 debSuppVerNum ;	 
 UINT8 atpiSuppVerNum ;	 
 UINT8 plSuppVerNum ;	 
 UINT8 oamSuppVerNum ;	 
 CiVersion ccSuppVer [ 10 ] ;	 
 CiVersion ssSuppVer [ 10 ] ;	 
 CiVersion mmSuppVer [ 10 ] ;	 
 CiVersion pbSuppVer [ 10 ] ;	 
 CiVersion simSuppVer [ 10 ] ;	 
 CiVersion msgSuppVer [ 10 ] ;	 
 CiVersion psSuppVer [ 10 ] ;	 
 CiVersion datSuppVer [ 10 ] ;	 
 CiVersion devSuppVer [ 10 ] ;	 
 CiVersion hscsdSuppVer [ 10 ] ;	 
 CiVersion debSuppVer [ 10 ] ;	 
 CiVersion atpiSuppVer [ 10 ] ;	 
 CiVersion plSuppVer [ 10 ] ;	 
 CiVersion oamSuppVer [ 10 ] ;	 
 } CiShOperCIVersionNegoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiShOperCIVersionNegoCnf_struct 
 {	 
 CiReturnCode rc ;	 
 CiVersion ccVer ;	 
 CiVersion ssVer ;	 
 CiVersion mmVer ;	 
 CiVersion pbVer ;	 
 CiVersion simVer ;	 
 CiVersion msgVer ;	 
 CiVersion psVer ;	 
 CiVersion datVer ;	 
 CiVersion devVer ;	 
 CiVersion hscsdVer ;	 
 CiVersion debVer ;	 
 CiVersion atpiVer ;	 
 CiVersion plVer ;	 
 CiVersion oamVer ;	 
 } CiShOperCIVersionNegoCnf;

//ICAT EXPORTED ENUM 
 typedef enum CI_ADDR_NUMTYPE {	 
 CI_NUMTYPE_UNKNOWN = 0x00 , /* Unknown */	 
 CI_NUMTYPE_INTERNATIONAL= 0x01 , /* International Number */	 
 CI_NUMTYPE_NATIONAL = 0x02 , /* National Number */	 
 CI_NUMTYPE_NETWORK = 0x03 , /* Network Specific ( e.g. Operator Access ) */	 
 CI_NUMTYPE_DEDICATED = 0x04 , /* Dedicated Access Number , Short Code */	 
 CI_NUMTYPE_EXTENSION = 0x07 /* Reserved for Extension */	 
 /* << All other codes are reserved >> */	 
 } _CiAddrNumType;

typedef UINT8 CiAddrNumType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_ADDR_NUMPLAN {	 
 CI_NUMPLAN_UNKNOWN = 0x00 , /* Unknown */	 
 CI_NUMPLAN_E164_E163 = 0x01 , /* ISDN / Telephony ( E.164 / E.163 ) */	 
 CI_NUMPLAN_DATA_X121 = 0x03 , /* Data Numbering Plan ( X.121 ) */	 
 CI_NUMPLAN_TELEX_F69 = 0x04 , /* Telex Numbering Plan ( F.69 ) */	 
 CI_NUMPLAN_NATIONAL = 0x08 , /* National Numbering Plan */	 
 CI_NUMPLAN_PRIVATE = 0x09 , /* Private Numbering Plan */	 
 CI_NUMPLAN_RSVD_CTS = 0x0b , /* Reserved for CTS */	 
 CI_NUMPLAN_EXTENSION = 0x0f /* Reserved for Extension */	 
 /* << All other codes are reserved >> */	 
 } _CiAddrNumPlan;

typedef UINT8 CiAddrNumPlan ;
//ICAT EXPORTED STRUCT 
 typedef struct CiAddressType_struct {	 
 CiAddrNumType NumType ; /* TON: Type of Number */	 
 CiAddrNumPlan NumPlan ; /* NPI: Numbering Plan Identification */	 
 } CiAddressType;

//ICAT EXPORTED STRUCT 
 typedef struct CiAddressInfo_struct {	 
 CiAddressType AddrType ; /* Address Type Information */	 
 UINT8 Length ; /* Address Length in digits */	 
 UINT8 Digits [ 40 ] ; /* Address Digits */	 
	 
 } CiAddressInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiOptAddressInfo_struct {	 
 CiBoolean Present ; /* Address Info present? */	 
 CiAddressInfo AddressInfo ; /* Address Info */	 
 } CiOptAddressInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiSubaddrInfo_struct {	 
 CiBoolean Present ; /* Subaddress Info present? */	 
 UINT8 Type ; /* Subaddress Type */	 
 UINT8 Length ; /* Subaddress Length in characters */	 
 UINT8 Digits [ 40 ] ; /* Subaddress Digits */	 
 } CiSubaddrInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiNameInfo_struct {	 
 /*Added by cherryli@02.02.2015 for CQ84004 begin.*/	 
	 
	 
	 
 /*Added by cherryli@02.02.2015 for CQ84004 end.*/	 
 UINT8 Length ; /* Name Length in characters */	 
 UINT8 Name [ 40 ] ; /* Alphanumeric Name */	 
 } CiNameInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiOptNameInfo_struct {	 
 CiBoolean Present ; /* Name Info present? */	 
 CiNameInfo NameInfo ; /* Name Info */	 
 } CiOptNameInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiCallerInfo_struct {	 
 CiOptAddressInfo OptCallerNumber ; /* Optional Caller Phone Number */	 
 CiSubaddrInfo OptCallerSubaddr ; /* Optional Caller Subaddress */	 
 CiOptNameInfo OptCallerName ; /* Optional Caller Name ( Alpha Tag ) */	 
 } CiCallerInfo;

//ICAT EXPORTED ENUM 
 typedef enum SSI_CALL_STATUS {	 
 SSI_CS_CFU_ACTIVE = 0 , /* Unconditional Call Forwarding active */	 
 SSI_CS_CCF_ACTIVE , /* Conditional CF trigger ( s ) active */	 
 SSI_CS_FORWARDED , /* Call has been forwarded */	 
 SSI_CS_WAITING , /* Call is waiting */	 
 SSI_CS_CUG_CALL , /* Outgoing CUG call ( Index also present ) */	 
 SSI_CS_MO_BARRED , /* Outgoing ( MO ) calls are barred */	 
 SSI_CS_MT_BARRED , /* Incoming ( MT ) calls are barred */	 
 SSI_CS_CLIR_REJECTED , /* CLIR suppression rejected */	 
 SSI_CS_DEFLECTED , /* Call has been deflected */	 
 /* This one must always be last in the list! */	 
 SSI_NUM_CS /* Number of SSI Call Status values */	 
 } _CiSsiCallStatus;

typedef UINT8 CiSsiCallStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSsiNotifyInfo_struct {	 
 CiSsiCallStatus Status ; /* Call Status indicator */	 
 UINT8 CugIndex ; /* CUG Index ( if applicable ) */	 
 } CiSsiNotifyInfo;

//ICAT EXPORTED ENUM 
 typedef enum SSU_CALL_STATUS {	 
 SSU_CS_FORWARDED = 0 , /* Call has been forwarded */	 
 SSU_CS_CUG_CALL , /* Incoming CUG call ( Index also present ) */	 
 SSU_CS_HELD , /* Call held ( Voice Call ) */	 
 SSU_CS_UNHELD , /* Call retrieved ( Voice Call ) */	 
 SSU_CS_ENTERED_MPTY , /* Multiparty call entered ( Voice call ) */	 
 SSU_CS_RELEASED_HELD , /* Held call released ( Voice call ) */	 
 SSU_CS_FORWARD_CHECK , /* Forward Check SS message received */	 
 SSU_CS_ECT_ALERTING , /* Connecting with remote party in ECT */	 
 SSU_CS_ECT_CONNECTED , /* Connected with remote party in ECT */	 
 /* ( Caller Information may also be present ) */	 
 SSU_CS_DEFLECTED , /* Call has been deflected */	 
 SSU_CS_INCOMING_FORWARDED , /* Additional incoming call forwarded */	 
 /* This one must always be last in the list! */	 
 SSU_NUM_CS /* Number of SSU Call Status values */	 
 } _CiSsuCallStatus;

typedef UINT8 CiSsuCallStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSsuNotifyInfo_struct {	 
 CiSsuCallStatus Status ; /* Call Status indicator */	 
 UINT8 CugIndex ; /* CUG Index ( if applicable ) */	 
 CiCallerInfo CallerInfo ; /* Optional Caller Information */	 
 /* ( Caller Name info is never present ) */	 
 } CiSsuNotifyInfo;

//ICAT EXPORTED ENUM 
 typedef enum CI_BSTYPE_SPEED {	 
 CI_BSTYPE_SPEED_AUTOBAUD = 0 , /* Autobauding for 3.100000 kHz Non-Transparent */	 
	 
 /* 3.100000 kHz Audio definitions */	 
 CI_BSTYPE_SPEED_300_V21 , /* 300 bps ( V.21 ) */	 
 CI_BSTYPE_SPEED_1200_V22 , /* 1200 bps ( V.22 ) */	 
 CI_BSTYPE_SPEED_1200_75_V23 , /* 1200 / 75 bps ( V.23 ) */	 
 CI_BSTYPE_SPEED_2400_V22BIS , /* 2400 bps ( V.22bis ) */	 
 CI_BSTYPE_SPEED_2400_V26TER , /* 2400 bps ( V.26ter ) */	 
 CI_BSTYPE_SPEED_4800_V32 , /* 4800 bps ( V.32 ) */	 
 CI_BSTYPE_SPEED_9600_V32 , /* 9600 bps ( V.32 ) */	 
	 
 /* V.34 definitions */	 
 CI_BSTYPE_SPEED_9600_V34 , /* 9600 bps */	 
 CI_BSTYPE_SPEED_14400_V34 , /* 14400 bps */	 
 CI_BSTYPE_SPEED_19200_V34 , /* 19200 bps */	 
 CI_BSTYPE_SPEED_28800_V34 , /* 28800 bps */	 
 CI_BSTYPE_SPEED_33600_V34 , /* 33600 bps */	 
	 
 /* V.34 definitions */	 
 CI_BSTYPE_SPEED_1200_V120 , /* 1200 bps */	 
 CI_BSTYPE_SPEED_2400_V120 , /* 2400 bps */	 
 CI_BSTYPE_SPEED_4800_V120 , /* 4800 bps */	 
 CI_BSTYPE_SPEED_9600_V120 , /* 9600 bps */	 
 CI_BSTYPE_SPEED_14400_V120 , /* 14.400000 kbps */	 
 CI_BSTYPE_SPEED_19200_V120 , /* 19.200000 kbps */	 
 CI_BSTYPE_SPEED_28800_V120 , /* 28.800000 kbps */	 
 CI_BSTYPE_SPEED_38400_V120 , /* 38.400000 kbps */	 
 CI_BSTYPE_SPEED_48000_V120 , /* 48.000000 kbps */	 
 CI_BSTYPE_SPEED_56000_V120 , /* 56.000000 kbps */	 
	 
 /* V.110 or X.31 Flag Stuffing UDI definitions */	 
 CI_BSTYPE_SPEED_300_V110 , /* 300 bps */	 
 CI_BSTYPE_SPEED_1200_V110 , /* 1200 bps */	 
 CI_BSTYPE_SPEED_2400_V110_X31 , /* 2400 bps */	 
 CI_BSTYPE_SPEED_4800_V110_X31 , /* 4800 bps */	 
 CI_BSTYPE_SPEED_9600_V110_X31 , /* 9600 bps */	 
 CI_BSTYPE_SPEED_14400_V110_X31 , /* 14.400000 kbps */	 
 CI_BSTYPE_SPEED_19200_V110_X31 , /* 19.200000 kbps */	 
 CI_BSTYPE_SPEED_28800_V110_X31 , /* 28.800000 kbps */	 
 CI_BSTYPE_SPEED_38400_V110_X31 , /* 38.400000 kbps */	 
 CI_BSTYPE_SPEED_48000_V110_X31 , /* 48.000000 kbps */	 
 CI_BSTYPE_SPEED_56000_V110_X31 , /* 56.000000 kbps ( can also get FTM ) */	 
 CI_BSTYPE_SPEED_64000_X31 , /* 64.000000 kbps ( can also get FTM ) */	 
	 
 /* Bit Transparent Mode definitions */	 
 CI_BSTYPE_SPEED_56000_BTM , /* 56 kbps */	 
 CI_BSTYPE_SPEED_64000_BTM , /* 64 kbps */	 
	 
 /* PIAFS ( Personal Internet Access Forum Standard ) definitions */	 
 CI_BSTYPE_SPEED_32000_PIAFS , /* 56.000000 kbps ( PIAFS32k ) */	 
 CI_BSTYPE_SPEED_64000_PIAFS , /* 64.000000 kbps ( PIAFS64k ) */	 
	 
 /* Multimedia Call definitions */	 
 CI_BSTYPE_SPEED_28800_MM , /* 28.800000 kbps */	 
 CI_BSTYPE_SPEED_32000_MM , /* 32.000000 kbps */	 
 CI_BSTYPE_SPEED_33600_MM , /* 33.600000 kbps */	 
 CI_BSTYPE_SPEED_56000_MM , /* 56 kbps */	 
 CI_BSTYPE_SPEED_64000_MM , /* 64 kbps */	 
	 
 /* This one must always be last in the list! */	 
 CI_NUM_BSTYPE_SPEEDS /* Number of Bearer Service Speeds defined */	 
 } _CiBsTypeSpeed;

typedef UINT8 CiBsTypeSpeed ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPassword_struct {	 
 UINT8 len ; /* length of the password , [ CI_MIN_PASSWORD_LENGTH - CI_MAX_PASSWORD_LENGTH ] */	 
 UINT8 data [ 16 ] ;	 
 } CiPassword;

//ICAT EXPORTED STRUCT 
 typedef struct CiString_struct {	 
 UINT16 len ;	 
 CHAR valStr [ 100 ] ;	 
 } CiString;

//ICAT EXPORTED STRUCT 
 typedef struct CiStringExt_struct {	 
 UINT16 len ;	 
 CHAR valStr [ 200 ] ;	 
 } CiStringExt;

//ICAT EXPORTED STRUCT 
 typedef struct CiNumericRange_struct {	 
 UINT32 min ; /* lower limit */	 
 UINT32 max ; /* upper limit */	 
 } CiNumericRange;

typedef UINT32 CiBitRange ;
//ICAT EXPORTED STRUCT 
 typedef struct CiNumericList_struct {	 
 CiBoolean hasRange ; /* range of numbers are included */	 
 CiBoolean hasIndvNums ; /* individual numbers are included */	 
 UINT16 rangeLstSize ; /* actual number of CiNumericRange structures held in the range list ,	 
 ignored if hasRange is FALSE */	 
 CiNumericRange rangeLst [ 20 ] ;	 
 UINT16 indvLstSize ; /* actual number of numbers held in the individual number list ,	 
 ignored if hasIndNums is FALSE */	 
 UINT32 indvList [ 50 ] ;	 
 } CiNumericList;

//ICAT EXPORTED ENUM 
 typedef enum CIERRACCTYPE {	 
 CIERR_ACC_TYPE_CHV1 , /* CHV1 password */	 
 CIERR_ACC_TYPE_CHV2 , /* CHV2 password */	 
 CIERR_ACC_TYPE_UNBLOCK_CHV1 , /* Unblock CHV1 password */	 
 CIERR_ACC_TYPE_UNBLOCK_CHV2 , /* Unblock CHV2 password */	 
 CIERR_ACC_TYPE_ADMIN , /* Administrate access right */	 
 CIERR_ACC_TYPE_CB , /* call barring password */	 
 CIERR_ACC_TYPE_INTERNAL /* internal access type */	 
 } _CiErrAccType;

typedef UINT8 CiErrAccType ;
//ICAT EXPORTED ENUM 
 typedef enum CIERRACCCAUSE {	 
 CIERR_ACC_PRIV_REQUIRED , /* access privilege ( e.g. password ) is required to gain access right */	 
 CIERR_ACC_PW_NOT_INIT , /* password is not initialized or registered */	 
 CIERR_ACC_PW_BLOCKED , /* password was blocked because of a series of unsuccessful verification attempts */	 
 CIERR_ACC_RES_UNAVAIL , /* required resource is unavailable */	 
 CIERR_ACC_UNKNOWN /* unknown error access cause */	 
 } _CiErrAccCause;

typedef UINT8 CiErrAccCause ;
//ICAT EXPORTED ENUM 
 typedef enum CIERRINPUTCODE {	 
 /* wrong inputs */	 
 CIRC_ERR_WRONG_PASSWORD=0xF000 , /* wrong password */	 
 CIRC_ERR_BAD_PARAMETER , /* parameter invalid or out of range */	 
 CIRC_ERR_WRONG_INDEX , /* invalid index */	 
 CIRC_ERR_LONG_STR , /* string too long */	 
 CIRC_ERR_WRONG_CHAR , /* invalid characters in text string */	 
 CIRC_ERR_LONG_DIALSTR /* dial string too long */	 
 } _CiErrInputCode;

typedef UINT16 CiErrInputCode ;
//ICAT EXPORTED ENUM 
 typedef enum CIERRINTERLINKCAUSE {	 
 CIERR_INTERLINK_DOWN , /* interlink broken , receiver ' s action TBD */	 
 CIERR_INTERLINK_MEM_OVERFLOW /* memory overflow in the link , receiver ' s action TBD */	 
 } _CiErrInterLinkCause;

typedef UINT8 CiErrInterLinkCause ;
typedef UINT8 CiEmptyPrim ;
//ICAT EXPORTED STRUCT 
 typedef struct CiLongAdrInfo_tag {	 
 UINT8 Length ; /* Name Length in characters */	 
 UINT8 Name [ 50 ] ; /* Alphanumeric Name */	 
 } CiLongAdrInfo;

//ICAT EXPORTED ENUM 
 typedef enum CI_EDIT_CMD_ACTION {	 
 CIED_ADD=0 ,	 
 CIED_DELETE=1 ,	 
 CIED_REPLACE=2 ,	 
 } _CiEditCmdType;

typedef UINT8 CiEditCmdType ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_EMLPP_CALL_PRIORITY {	 
 CICC_EMLPP_CALL_PRIORITY_NONE = 0x00 ,	 
 CICC_EMLPP_CALL_PRIORITY_4 = 0x01 ,	 
 CICC_EMLPP_CALL_PRIORITY_3 = 0x02 ,	 
 CICC_EMLPP_CALL_PRIORITY_2 = 0x03 ,	 
 CICC_EMLPP_CALL_PRIORITY_1 = 0x04 ,	 
 CICC_EMLPP_CALL_PRIORITY_0 = 0x05 ,	 
 CICC_EMLPP_CALL_PRIORITY_B = 0x06 ,	 
 CICC_EMLPP_CALL_PRIORITY_A = 0x07 ,	 
 CICC_EMLPP_NUM_OF_PRIORITIES = 0x07	 
 } _CiCcEmlppCallPriority;

typedef UINT8 CiCcEmlppCallPriority ;
//ICAT EXPORTED ENUM 
 typedef enum CI_ERR_PRIM {	 
 CI_ERR_PRIM_HASNOSUPPORT_CNF = 0xF000 ,	 
 CI_ERR_PRIM_HASINVALIDPARAS_CNF ,	 
 CI_ERR_PRIM_ISINVALIDREQUEST_CNF ,	 
 CI_ERR_PRIM_SIMNOTREADY_CNF ,	 
 CI_ERR_PRIM_ACCESSDENIED_CNF ,	 
 CI_ERR_PRIM_INTERLINKDOWN_IND ,	 
 CI_ERR_PRIM_INTERLINKDOWN_RSP ,	 
 CI_ERR_PRIM_INTERLINKUP_IND ,	 
	 
 /* This should always be the last enum entry */	 
 CI_ERR_PRIM_NEXTAVAIL	 
 } _CiErrPrim;

typedef UINT16 CiErrPrim ;
typedef CiEmptyPrim CiErrPrimHasNoSupportCnf ;
//ICAT EXPORTED STRUCT 
 typedef struct CiErrPrimHasInvalidParasCnf_struct {	 
 CiErrInputCode err ;	 
 } CiErrPrimHasInvalidParasCnf;

typedef CiEmptyPrim CiErrPrimIsInvalidRequestCnf ;
typedef CiEmptyPrim CiErrPrimSimNotReadyCnf ;
//ICAT EXPORTED STRUCT 
 typedef struct CiErrPrimAccessDeniedCnf_struct {	 
 CiErrAccType type ;	 
 CiErrAccCause cause ;	 
 } CiErrPrimAccessDeniedCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiErrPrimInterlinkDownInd_struct {	 
 CiErrInterLinkCause cause ;	 
 } CiErrPrimInterlinkDownInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiErrPrimInterlinkDownRsp_struct {	 
 CiErrInterLinkCause cause ;	 
 } CiErrPrimInterlinkDownRsp;

typedef CiEmptyPrim CiErrPrimInterlinkUpInd ;
typedef UINT16 CiDevRc ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_MSG_CLASS_TYPE 
 {	 
 CI_DEV_LTE_RRC_MSG_CLASS_BCCH_BCH = 0 , /* BCCH-BCH massage */	 
 CI_DEV_LTE_RRC_MSG_CLASS_BCCH_DL_SCH , /* BCCH-DL-SCH message */	 
 CI_DEV_LTE_RRC_MSG_CLASS_PCCH , /* PCCH message */	 
 CI_DEV_LTE_RRC_MSG_CLASS_DL_CCCH , /* DL_CCCH message */	 
 CI_DEV_LTE_RRC_MSG_CLASS_DL_DCCH , /* DL_DCCH message */	 
 CI_DEV_LTE_RRC_MSG_CLASS_UL_CCCH , /* UL_CCCH message */	 
 CI_DEV_LTE_RRC_MSG_CLASS_UL_DCCH /* UL_DCCH message */	 
 } _CiDevLteRrcMsgClass;

typedef UINT8 CiDevLteRrcMsgClass ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_BCCH_BCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_BCCH_BCH_MSG_MASTR_INFO_BLK = 0 /* BCCH-BCH master information block massage */	 
 } _CiDevLteRrcBcchBchMsgType;

typedef UINT8 CiDevLteRrcBcchBchMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_BCCH_DL_SCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_BCCH_DL_SCH_MSG_SYS_INFO = 0 , /* BCCH-DL-SCH massage */	 
 CI_DEV_LTE_RRC_BCCH_DL_SCH_MSG_SYS_INFO_BLK_TYPE1 /* BCCH-DL-SCH System Information Block Type 1 message */	 
 } _CiDevLteRrcBcchDlSchMsgType;

typedef UINT8 CiDevLteRrcBcchDlSchMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_PCCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_PCCH_MSG_PAGING = 0 /* PCCH Paging massage */	 
 } _CiDevLteRrcPcchMsgType;

typedef UINT8 CiDevLteRrcPcchMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_DL_CCCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_DL_CCCH_MSG_RRC_CONN_REEST = 0 , /* DL-CCCH RRC Connection Reestablishment massage */	 
 CI_DEV_LTE_RRC_DL_CCCH_MSG_RRC_CONN_REEST_REJ , /* DL-CCCH RRC Connection Reestablishment Reject massage */	 
 CI_DEV_LTE_RRC_DL_CCCH_MSG_RRC_CONN_REJ , /* DL-CCCH RRC Connection Reject massage */	 
 CI_DEV_LTE_RRC_DL_CCCH_MSG_RRC_CONN_SETUP /* DL-CCCH RRC Connection Setup massage */	 
 } _CiDevLteRrcDlCcchMsgType;

typedef UINT8 CiDevLteRrcDlCcchMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_DL_DCCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_CSFB_PARAM_RESP = 0 , /* DL-DCCH CSFB Parameters Response */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_DL_INFO_TRANSFER , /* DL-DCCH DL Information Transfer message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_HO_FROM_EUTRA_REQ , /* DL-DCCH Handover From EUTRA Preparation Request message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_MOB_FROM_EUTRA_CMD , /* DL-DCCH Mobility From EUTRA Command message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_RRC_CONN_RECFG , /* DL-DCCH RRC Connection Reconfiguration message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_RRC_CONN_REL , /* DL-DCCH RRC Connection Release message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_SECUR_MODE_CMD , /* DL-DCCH Security Mode Command message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_UE_CAP_ENQ , /* DL-DCCH UE Capability Enquiry message */	 
 CI_DEV_LTE_RRC_DL_DCCH_MSG_CNTR_CHECK /* DL-DCCH Counter Check message */	 
 } _CiDevLteRrcDlDcchMsgType;

typedef UINT8 CiDevLteRrcDlDcchMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_UL_CCCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_UL_CCCH_MSG_RRC_CONN_REEST_REQ = 0 , /* UL-CCCH RRC Connection Reestablishment Request massage */	 
 CI_DEV_LTE_RRC_UL_CCCH_MSG_RRC_CONN_REQ /* UL-CCCH RRC Connection Request massage */	 
 } _CiDevLteRrcUlCcchMsgType;

typedef UINT8 CiDevLteRrcUlCcchMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_UL_DCCH_MSG_TYPE 
 {	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_CSFB_PARAM_REQ = 0 , /* UL-DCCH CSFB Parameters Request message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_MEAS_REPORT , /* UL-DCCH Measurement Report message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_RRC_CONN_RECFG_CMP , /* UL-DCCH RRC Connection Reconfiguration Complete message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_RRC_CONN_REEST_CMP , /* UL-DCCH RRC Connection Reestablishment Complete message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_RRC_CONN_SETUP_CMP , /* UL-DCCH RRC Connection Setup Complete message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_SECUR_MODE_CMP , /* UL-DCCH Security Mode Complete message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_SECURE_MODE_FAIL , /* UL-DCCH Security Mode Failure message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_UE_CAP_INFO , /* UL-DCCH UE Capability Information message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_HO_PREP_TXR , /* UL-DCCH UL Handover Preparation Transfer message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_INFO_TXR , /* UL-DCCH UL Information Transfer message */	 
 CI_DEV_LTE_RRC_UL_DCCH_MSG_CNTR_CHK_RESP /* UL-DCCH Counter Check Response message */	 
 } _CiDevLteRrcUlDcchMsgType;

typedef UINT8 CiDevLteRrcUlDcchMsgType ;
//ICAT EXPORTED UNION : _CiDevLteRrcMsgClass 
 typedef union CiDevLteRrcMsgType_Tag 
 {	 
 CiDevLteRrcBcchBchMsgType bch ;	 
 CiDevLteRrcBcchDlSchMsgType dl_sch ;	 
 CiDevLteRrcPcchMsgType pcch ;	 
 CiDevLteRrcDlCcchMsgType dl_ccch ;	 
 CiDevLteRrcDlDcchMsgType dl_dcch ;	 
 CiDevLteRrcUlCcchMsgType ul_ccch ;	 
 CiDevLteRrcUlDcchMsgType ul_dcch ;	 
 } CiDevLteRrcMsgType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevLteRrcMsgClass msgClass ;	 
 CiDevLteRrcMsgType msgType ;	 
 UINT16 msgLength ;	 
	 
 // Important Note: Due to dynamic signal payload allocation , the " msg " field must be last!	 
 CHAR msg [ 256 ] ;	 
 } CiDevLteEng_RRC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiBoolean direction ; /* TRUE - Uplink NAS message transmitted. FALSE - Downlink NAS message received */	 
 UINT16 msgLength ;	 
 CHAR msg [ 400 ] ; /* hex encoded NAS message ( unciphered ) */	 
 } CiDevLteEng_NAS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 earfcn ; /* The EARFCN of the neighbor cell */	 
 UINT16 phyCellId ; /* The physical cell ID of the neighbor cell */	 
 UINT8 rsrp ; /* The average RSRP of the neighbor cell over last measurement period */	 
 UINT8 rsrq ; /* The average RSRQ of the neighbor cell over last measurement period */	 
 } CiDevLteEng_EutraMeas;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 mcc ; /* The MCC of the serving cell */	 
 UINT16 mnc ; /* The MNC of the serving cell */	 
 UINT32 cellId ; /* The cell identity of the serving cell */	 
 UINT32 tac ; /* The tracking area code of the serving cell */	 
 UINT16 servEarfcn ; /* The EARFCN of the serving cell */	 
 UINT16 servPhyCellId ; /* The physical cell ID of the serving cell */	 
 UINT8 servRsrp ; /* The average RSRP of the serving cell over last measurement period */	 
 UINT8 servRsrq ; /* The average RSRQ of the serving cell over last measurement period */	 
 UINT8 servRssnr ; /* The average RSSNR of the serving cell over last measurement period in decibels */	 
 UINT8 FreqBandInd ; /* The operating band of the serving cell , see 3 GPP TS 36.101000 / Table 5.500000 -1. */	 
 UINT8 dlBandwidth ; /* The transmission bandwidth configuration of the serving cell on the downlink , see 3 GPP TS 36.101000 / Table 5.600000 -1. Value n6 corresponds to 6 resource blocks , n15 to 15 resource blocks and so on. */	 
 UINT8 ulBandwidth ; /* The transmission bandwidth configuration of the serving cell on the uplink , see 3 GPP TS 36.101000 / Table 5.600000 -1. Value n6 corresponds to 6 resource blocks , n15 to 15 resource blocks and so on. */	 
 UINT8 numMeas ; /* The number of E-UTRA neighbor cell measurements included in the current instance of this metric */	 
 CiDevLteEng_EutraMeas meas [ 32 ] ; /* An array of structures with a length of numMeas */	 
 } CiDevLteEng_MSR;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 uarfcn ; /* The UARFCN of the neighbor cell */	 
 UINT16 sc ; /* The neighbor cell primary scrambling code */	 
 UINT8 rscp ; /* The neighbor cell CPICH RSCP. */	 
 UINT8 ecno ; /* The neighbor cell CPICH Ec / N0. */	 
 } CiDevLteEng_UtraMeas;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ; /* The neighbor cell ARFCN. */	 
 UINT8 bsic ; /* The neighbor cell base station identity code. */	 
 UINT8 rssi ; /* The neighbor cell BCCH RSSI. */	 
 } CiDevLteEng_MeasGeran;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numMeasUtra ; /* The number of UTRA inter-RAT neighbor cell measurements included in this instance of this metric */	 
 UINT8 numMeasGeran ; /* The number of inter-RAT neighbor cell measurements included in this instance of this metric */	 
 CiDevLteEng_UtraMeas utraMeas [ 32 ] ; /* An array of structures with a length of numMeasUtra */	 
 CiDevLteEng_MeasGeran geranMeas [ 32 ] ; /* An array of structures with a length of numMeasGeran */	 
 } CiDevLteEng_InterMsr;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 earfcn ; /* The neighbor cell EARFCN. */	 
 UINT16 phyCellId ; /* The neighbor cell physical layer cell identity. */	 
 } CiDevLteEng_NeighbEutra;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 uarfcn ; /* The neighbor cell UARFCN. */	 
 UINT16 sc ; /* The neighbor cell primary scrambling code */	 
 } CiDevLteEng_NeighbUtra;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ; /* The neighbor cell ARFCN. */	 
 } CiDevLteEng_NeighbGeran;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 numNeighbEutra ; /* The number of E-UTRA neighbor cells */	 
 UINT16 numNeighbUtra ; /* The number of UTRA neighbor cells */	 
 UINT16 numNeighbGeran ; /* The number of neighbor cells */	 
 CiDevLteEng_NeighbEutra neighbEutra [ 32 ] ; /* An array of structures with a length of numNeighbEutra */	 
 CiDevLteEng_NeighbUtra neighbUtra [ 32 ] ; /* An array of structures with a length of numNeighbUtra */	 
 CiDevLteEng_NeighbGeran neighbGeran [ 32 ] ; /* An array of structures with a length of numNeighbGeran */	 
 } CiDevLteEng_NeighborList;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_STATE 
 {	 
 CI_DEV_LTE_RRC_STATE_NULL = 0 , /* The E-UTRA RRC state is not applicable. */	 
 CI_DEV_LTE_RRC_STATE_IDLE_ , /* The E-UTRA RRC state is RRC_IDLE */	 
 CI_DEV_LTE_RRC_STATE_ATMPT_CONNECTION , /* Attempting to establish an RRC connection and enter E-UTRA RRC_CONNECTED state. */	 
 CI_DEV_LTE_RRC_STATE_CONNECTED_ , /* The E-UTRA RRC state is RRC_CONNECTED */	 
 CI_DEV_LTE_RRC_STATE_ENDING , /* Leaving E-UTRA RRC_CONNECTED state. */	 
 CI_DEV_LTE_RRC_STATE_ATMPT_OUTBND_MOBILITY , /* Attempting to leave E-UTRA , i.e. , via handover , cell change order , or cell reselection */	 
 CI_DEV_LTE_RRC_STATE_ATMPT_INBND_MOBILITY /* Attempting to enter E-UTRA , i.e. , via handover , cell change order , or cell reselection */	 
 } _CiDevLteRrcStateExt;

typedef UINT8 CiDevLteRrcStateExt ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_CAUSE 
 {	 
 CI_DEV_LTE_RRC_CAUSE_EST_EMERGENCY = 0 , /* The RRC establishment cause is ¡®Emergency¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_HIGH_PRIO_ACC , /* The RRC establishment cause is ¡®High priority access¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_MT_ACC , /* The RRC establishment cause is ¡®MT access¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_MO_SIGNAL , /* The RRC establishment cause is ¡®MO signaling¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_MO_DATA , /* The RRC establishment cause is ¡®MO data¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_REEST_RECFG_FAIL , /* The RRC reestablishment cause is ¡®Reconfiguration failure¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_REEST_HO_FAIL , /* The RRC reestablishment cause is ¡®Handover failure¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_REEST_OTHER_FAIL , /* The RRC reestablishment cause is ¡®Other failure¡¯ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_OTHER_RECFG_FAIL , /* RRC connection reconfiguration failed Ref. 3 GPP TS 36.331000 , section 5.300000 .5.5 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_IRAT_RES , /* EL Inter-RAT cell reselection occurred during RRC connection reestablishment Ref. 3 GPP TS 36.331000 , section 5.300000 .7.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_T311_EXP , /* RRC connection reestablishment failed due to T311 expiry Ref. 3 GPP TS 36.331000 , section 5.300000 .7.6 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_CELL_NOT_SUIT , /* RRC connection reestablishment failed due to T301 expiry or because the cell is no longer suitable Ref. 3 GPP TS 36.331000 , section 5.300000 .7.7 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_REEST_REJ , /* RRC connection reestablishment failed due to reestablishment rejection Ref. 3 GPP TS 36.331000 , section 5.300000 .7.8 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_LOAD_BAL_TAU_REQD , /* The RRC connection was released with cause ¡®Load balancing TAU required¡¯ Ref. 3 GPP TS 36.331000 , section 5.300000 .8.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_OTHER , /* The RRC connection was released with cause ¡®Other¡¯ Ref. 3 GPP TS 36.331000 , section 5.300000 .8.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_T310_EXP , /* A radio link failure due to T310 expiry ( loss of physical layer synchronization ) has been detected Ref. 3 GPP TS 36.331000 , section 5.300000 .11.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_RND_ACC , /* A radio link failure due to a random access problem has been detected Ref. 3 GPP TS 36.331000 , section 5.300000 .11.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_MAX_RLC_RETRANS , /* A radio link failure due to the maximum number of RLC retransmissions being reached has been detected Ref. 3 GPP TS 36.331000 , section 5.300000 .11.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_SUCC_MOB_FROM_EUTRAN , /* Outbound mobility away from E-UTRAN was successful Ref. 3 GPP TS 36.331000 , section 5.400000 .3.4 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_FAIL_NO_RESP_FROM_CELL , /* The RRC connection establishment procedure failed due to T300 expiry ( no response from cell ) Ref. 3 GPP TS 36.331000 , section 7.300000 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_FAIL_REJ , /* The RRC connection was rejected by the cell Ref. 3 GPP TS 36.331000 , section 7.300000 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_FAIL_CELL_RESEL , /* The RRC connection establishment procedure failed due to cell reselection after the RRC Connection Request message was sent Ref. 3 GPP TS 36.331000 , section 7.300000 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_FAIL_ABORTED , /* The RRC connection was aborted by the UE Ref. 3 GPP TS 36.331000 , section 7.300000 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_FAIL_CELL_BARRED , /* The RRC connection establishment procedure failed because the cell is temporarily barred ( T302 , T303 , or T305 is running ) Ref. 3 GPP TS 36.331000 , section 7.300000 */	 
 CI_DEV_LTE_RRC_CAUSE_NO_SERVICE = 254 , /* The UE went to no service state either from idle or connected mode */	 
 CI_DEV_LTE_RRC_CAUSE_NA = 255 /* RRC cause is not applicable to this state */	 
 } _CiDevLteRrcCause;

typedef UINT8 CiDevLteRrcCause ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevLteRrcStateExt rrcState ; /* The E-UTRA RRC state */	 
 CiDevLteRrcCause rrcCause ; /* The E-UTRA RRC cause */	 
 } CiDevLteEng_RrcState;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 bufsize0 ; /* 0 -63 ; Buffer size for logical channel group #0 */	 
 UINT8 bufsize1 ; /* 0 -63 ; Buffer size for logical channel group #1 */	 
 UINT8 bufsize2 ; /* 0 -63 ; Buffer size for logical channel group #2 */	 
 UINT8 bufsize3 ; /* 0 -63 ; Buffer size for logical channel group #3 */	 
 UINT16 crnti ; /* C-RNTI */	 
 UINT8 ta ; /* 0 -63 ; Timing Advance command */	 
 UINT8 powerHroom ; /* 0 -63 ; Power Headroom */	 
 } CiDevLteEng_MAC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 earfcn ; /* The accessed cels EARFCN */	 
 UINT16 phyCellId ; /* The accessed cells physical cell identity */	 
 UINT16 raRnti ; /* 1 -60 ; RA-RNTI */	 
 UINT8 preambleCount ; /* 1 -200 ; Total number of preamble transmitted */	 
 UINT8 lastTxPower ; /* 0 -63 ; Transmit power headroom upon transmission of the last preamble */	 
 UINT32 ulGrant ; /* UL grant indicated in the Random Access Response */	 
 UINT16 raTempCrnti ; /* The temporary C-RNTI indicated in the random Access Response */	 
 UINT16 ta ; /* 0 -1282 ; Timing Advance indicated in the Random Access Response */	 
 UINT8 raRespSucc ; /* 0 - Random Access Response reception was not successful 1 - Random Access Response reception was successful */	 
 } CiDevLteEng_MAC_RACH;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RLC_MODE 
 {	 
 CI_DEV_LTE_RLC_MODE_TM = 0 , /* RLC Transparent Mode */	 
 CI_DEV_LTE_RLC_MODE_UM , /* RLC Unacknowledged Mode */	 
 CI_DEV_LTE_RLC_MODE_AM /* RLC Acknowledged Mode */	 
 } _CiDevLteRlcMode;

typedef UINT8 CiDevLteRlcMode ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 drbId ; /* ( 1 -32 ) DRB Id */	 
 UINT8 epsBearerId ; /* ( 0 , 5 -15 ) EPS Bearer Id */	 
 UINT8 logicalChId ; /* ( 3 -10 ) DTCH Logical Channel Id */	 
 CiDevLteRlcMode rlcMode ; /* TM , UM , AM RLC transfer mode */	 
 UINT32 rxSduCount ; /* Number of RLC SDUs received successfully on this DRB */	 
 UINT32 rxByteCount ; /* Number of RLC SDU bytes received successfully on this DRB */	 
 UINT32 rxPduCount ; /* Number of RLC PDUs received on this DTCH */	 
 UINT32 reRxPduCount ; /* Number of RLC PDUs requested for retransmission on this DTCH */	 
 } CiDevLteEng_drbDl;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 drbId ; /* ( 1 -32 ) DRB Id */	 
 UINT8 epsBearerId ; /* ( 0 , 5 -15 ) EPS Bearer Id */	 
 UINT8 logicalChId ; /* ( 3 -10 ) DTCH Logical Channel Id */	 
 CiDevLteRlcMode rlcMode ; /* TM , UM , AM RLC transfer mode */	 
 UINT32 txSduCount ; /* Number of RLC SDUs submitted via the RLC SAP for transmission on this DRB */	 
 UINT32 txByteCount ; /* Number of RLC SDU bytes submitted via the RLC SAP for transmission on this DRB */	 
 UINT32 txPduCount ; /* Number of RLC PDUs transmitted on this DTCH */	 
 UINT32 reTxPduCount ; /* Number of retransmitted RLC PDUs on this DTCH */	 
 } CiDevLteEng_drbUl;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 srbId ; /* ( 1 -2 ) The SRB Identity */	 
 UINT16 rxSduCount ; /* Number of RLC SDU ' s received successfully on this SRB */	 
 UINT16 rxByteCount ; /* Number of RLC SDU bytes received successfully on this SRB */	 
 UINT16 rxPduCount ; /* Number of RLC PDUs received on this DCCH */	 
 UINT16 reRxPduCount ; /* Number of RLC PDUs requested for retransmission on this DCCH */	 
 } CiDevLteEng_srbDl;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 srbId ; /* ( 1 -2 ) The SRB Identity */	 
 UINT16 txSduCount ; /* Number of RLC SDUs submitted via the RLC SAP for transmission on this SRB */	 
 UINT16 txByteCount ; /* Number of RLC SDU bytes submitted via the RLC SAP for transmission on this SRB */	 
 UINT16 txPduCount ; /* Number of RLC PDUs transmitted on this DCCH */	 
 UINT16 reTxPduCount ; /* Number of retransmitted RLC PDUs on this DCCH */	 
 } CiDevLteEng_srbUl;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 rlcUlDuration ; /* In our implementation it is always 960 RLC uplink measurement period to which this metric pertains in milliseconds */	 
 UINT16 rlcDlDuration ; /* In our implementation it is always 960 RLC downlink measurement period to which this metric pertains in milliseconds */	 
 UINT8 numSrbUl ; /* ( 1 -2 ) The number of uplink signaling radio bearers represented in this metric */	 
 UINT8 numSrbDl ; /* ( 1 -2 ) The number of downlink signaling radio bearers represented in this metric */	 
 UINT8 numDrbUl ; /* ( 0 -11 ) The number of uplink data radio bearers represented in this metric */	 
 UINT8 numDrbDl ; /* ( 0 -11 ) The number of downlink data radio bearers represented in this metric */	 
 CiDevLteEng_srbUl srbUl [ 2 ] ; /* An array of structures with a length of numSrbUl */	 
 CiDevLteEng_srbDl srbDl [ 2 ] ; /* An array of structures with a length of numSrbDl */	 
 CiDevLteEng_drbUl drbUl [ 12 ] ; /* An array of structures with a length of numDrbUl */	 
 CiDevLteEng_drbDl drbDl [ 12 ] ; /* An array of structures with a length of numDrbDl */	 
 } CiDevLteEng_RLC;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_EPS_BEARER_TYPE 
 {	 
 CI_DEV_LTE_EPS_DEFAULT_BEARER = 0 , /* Default EPS Bearer */	 
 CI_DEV_LTE_EPS_DEDICATED_BEARER /* Dedicated EPS Bearer */	 
 } _CiDevLteEpsBearerType;

typedef UINT8 CiDevLteEpsBearerType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_EPS_BEARER_CONTEXT_STATE 
 {	 
 CI_DEV_LTE_EPS_BEARER_INACTIVE = 0 , /* The EPS bearer Context does not exist */	 
 CI_DEV_LTE_EPS_BEARER_ACTIVE , /* The EPS bearer Context is active */	 
 CI_DEV_LTE_EPS_BEARER_ACTIVE_PENDING , /* The EPS bearer Context exist but not active */	 
 CI_DEV_LTE_EPS_BEARER_MODIFY /* The EPS bearer Context is in a process of being modified */	 
 } _CiDevLteEpsBearereContextState;

typedef UINT8 CiDevLteEpsBearereContextState ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 pdnConnectionId ; /* PDN connection id */	 
 UINT8 epsBearerId ; /* EPS bearer Id */	 
 CiDevLteEpsBearerType epsBearerType ; /* EPS bearer type ( default or dedicated ) */	 
 CiDevLteEpsBearereContextState epsBearerNewState ; /* The new EPS bearer context state ( see 3 GPP TS 24.301000 , 6.100000 .3.2 ) */	 
 } CiDevLteEng_EPS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 qci ; /* QoS Class Identifier */	 
 UINT8 maxBitRateUl ; /* Maximum bit rate for uplink */	 
 UINT8 maxBitRateDl ; /* Maximum bit rate for downlink */	 
 UINT8 gbrUl ; /* Guaranteed bit rate for uplink */	 
 UINT8 gbrDl ; /* Guaranteed bit rate for downlink */	 
 UINT8 maxBitRateUlEx ; /* Maximum bit rate for uplink ( extended ) */	 
 UINT8 maxBitRateDlEx ; /* Maximum bit rate for downlink ( extended ) */	 
 UINT8 gbrUlEx ; /* Guaranteed bit rate for uplink ( extended ) */	 
 UINT8 gbrDlEx ; /* Guaranteed bit rate for downlink ( extended ) */	 
 } CiDevLteEng_EpsQos;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 pdnConnectionId ; /* PDN connection id */	 
 UINT8 epsBearerId ; /* EPS bearer Id linked */	 
 UINT8 EpsBearerId ; /* The Linked EPS bearer Id when the QoS of a dedicated EPS bearer s assigned or changed */	 
 CiDevLteEng_EpsQos epsQos ; /* the EPS QoS */	 
 } CiDevLteEng_EPS_QoS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 totalPuschTxPower ; /* -112 - 23 ; Total UE transmit power for PUSCH transmission ( dBm ) */	 
 UINT8 puschTxPowerPerRb ; /* -10 - 23 ; UE transmit power for PUSCH transmission per resource block ( dBm ) */	 
 CiBoolean wbReportPresent ; /* Indication if cqiWbDist is valid. TRUE- CQI is present. */	 
 UINT8 numSubBandReport ; /* 1 -4 ; Number of sub bands for the CQI */	 
 UINT8 cqiWbDist [ 16 ] ; /* CQI distribution over all sub-bands */	 
 UINT8 cqSubBandDist [ 4 ] ; /* CQI distribution for each sub-band */	 
 UINT16 randIndDist [ 5 ] ; /* Rank Indicator ( RI ) distribution. */	 
 UINT16 pmiDist [ 16 ] ; /* Precoding matrix Indicator ( PMI ) distribution */	 
 } CiDevLteEng_PUSCH;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_T310_STATUS 
 {	 
 CI_DEV_LTE_T310_STATUS_STOPPED = 0 , /* T310 timer has been stopped. Radio link restored */	 
 CI_DEV_LTE_T310_STATUS_STARTED , /* T310 timer has been started. Physical layer problems detected */	 
 CI_DEV_LTE_T310_STATUS_EXPIRED , /* T310 timer has expired. Radio link has failed */	 
 CI_DEV_LTE_T310_STATUS_UNKNOWN /* T310 timer status is invalid */	 
 } _CiDevLteT310Status;

typedef UINT8 CiDevLteT310Status ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevLteT310Status t310Status ; /* The status of T310 timer associated with this radio link */	 
 } CiDevLteEng_RadioLink;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 pdpContextId ;	 
 UINT32 localIpAddress ;	 
 UINT32 ipAddrPrimaryDns ;	 
 UINT32 ipAddrSecondaryDns ;	 
 UINT8 localIpv6Address [ 16 ] ;	 
 UINT8 strIpV6Dns1 [ 16 ] ;	 
 UINT8 strIpV6Dns2 [ 16 ] ;	 
 } CiDevGsmUmtsComnPdpCActEng_SM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_SM_CAUSE_TYPE 
 {	 
 CI_DEV_SM_CAUSE_NO_NET_RESPONSE = 0 ,	 
 CI_DEV_SM_CAUSE_OP_DET_BARRING = 8 ,	 
 CI_DEV_SM_CAUSE_LLC_SNDCP_FAILURE = 25 ,	 
 CI_DEV_SM_CAUSE_INSUFF_RESOURCES = 26 ,	 
 CI_DEV_SM_CAUSE_UNKN_MISS_APN = 27 ,	 
 CI_DEV_SM_CAUSE_UNKN_PDP_ADDR_TYPE = 28 ,	 
 CI_DEV_SM_CAUSE_USER_AUTH_FAILED = 29 ,	 
 CI_DEV_SM_CAUSE_ACT_REJ_BY_GGSN = 30 ,	 
 CI_DEV_SM_CAUSE_ACT_REJ_UNSPEC = 31 ,	 
 CI_DEV_SM_CAUSE_SERV_OPT_NOT_SUPP = 32 ,	 
 CI_DEV_SM_CAUSE_SERV_OPT_NOT_SUBS = 33 ,	 
 CI_DEV_SM_CAUSE_SERV_OPT_TEMP_OUT_OF_ORDER = 34 ,	 
 CI_DEV_SM_CAUSE_NSAPI_ALREADY_USED = 35 ,	 
 CI_DEV_SM_CAUSE_REG_PDP_CONT_DEACT = 36 ,	 
 CI_DEV_SM_CAUSE_QOS_NOT_ACCEPTED = 37 ,	 
 CI_DEV_SM_CAUSE_NETWORK_FAILURE = 38 ,	 
 CI_DEV_SM_CAUSE_REACTIVATION_REQUESTED = 39 ,	 
 CI_DEV_SM_CAUSE_FEAT_NOT_SUPP = 40 ,	 
 CI_DEV_SM_CAUSE_SEM_ERR_TFT_OP = 41 ,	 
 CI_DEV_SM_CAUSE_SYN_ERR_TFT_OP = 42 ,	 
 CI_DEV_SM_CAUSE_UNKN_PDP_CONTEXT = 43 ,	 
 CI_DEV_SM_CAUSE_SEM_ERR_PKT_FILTER = 44 ,	 
 CI_DEV_SM_CAUSE_SYN_ERR_PKT_FILTER = 45 ,	 
 CI_DEV_SM_CAUSE_PDP_CXT_WOUT_TFT_ACT = 46 ,	 
 CI_DEV_SM_CAUSE_MULTICAST_GRP_TIMEOUT = 47 ,	 
 CI_DEV_SM_CAUSE_ACTIVATION_REJ_BCM_VIOLATION = 48 ,	 
 CI_DEV_SM_CAUSE_IPV4_ONLY = 50 ,	 
 CI_DEV_SM_CAUSE_IPV6_ONLY = 51 ,	 
 CI_DEV_SM_CAUSE_SINGLE_ADDR_ONLY = 52 ,	 
 CI_DEV_SM_CAUSE_COLLISION = 56 ,	 
 CI_DEV_SM_CAUSE_INVALID_TRANS_ID_VALUE = 81 ,	 
 CI_DEV_SM_CAUSE_SEM_INCORRECT_MESSAGE = 95 ,	 
 CI_DEV_SM_CAUSE_INVALID_MANDATORY_INFO = 96 ,	 
 CI_DEV_SM_CAUSE_NONEXISTENT_MESSAGE_TYPE = 97 ,	 
 CI_DEV_SM_CAUSE_INCOMPATIBLE_MESSAGE_TYPE = 98 ,	 
 CI_DEV_SM_CAUSE_NONEXISTENT_INFO_ELEMENT = 99 ,	 
 CI_DEV_SM_CAUSE_CONDITIONAL_IE_ERROR = 100 ,	 
 CI_DEV_SM_CAUSE_INCOMPATIBLE_MESSAGE = 101 ,	 
 CI_DEV_SM_CAUSE_PROTOCOL_ERROR_UNSPEC = 111 ,	 
 CI_DEV_SM_CAUSE_INCOMPATIBLE_APN_RESTR_VALUE = 112	 
 } _CiDevSmCauseType;

typedef UINT8 CiDevSmCauseType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_SM_PDP_INITIATOR_TYPE 
 {	 
 CI_DEV_SM_NETWORK_INITIATED = 0 ,	 
 CI_DEV_SM_UE_INITIATED	 
 } _CiDevSmPdpInitiatorType;

typedef UINT8 CiDevSmPdpInitiatorType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 pdpContextId ;	 
 CiDevSmCauseType termCode ;	 
 CiDevSmPdpInitiatorType pdpInitiator ;	 
 } CiDevGsmUmtsComnPdpCEndEng_SM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_SM_ORDINAL_TYPE 
 {	 
 CI_DEV_SM_PRIMARY_PDP_CONTEXT = 0 ,	 
 CI_DEV_SM_SECONDARY_PDP_CONTEXT	 
 } _CiDevSmOrdinalType;

typedef UINT8 CiDevSmOrdinalType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 pdpContextId ;	 
 UINT32 assocContextId ;	 
 CiDevSmOrdinalType ordinal ;	 
 CiDevSmPdpInitiatorType pdpInitiator ;	 
 UINT8 nsapi ;	 
 UINT8 sapi ;	 
 UINT8 apn [ 100 ] ;	 
 } CiDevGsmUmtsComnPdpCReqEng_SM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_ATTACH_TYPE 
 {	 
 CI_DEV_MM_GPRS_ATTACH = 0 ,	 
 CI_DEV_MM_GPRS_ATTACH_WHILE_IMSI_ATTACHED ,	 
 CI_DEV_MM_COMB_GPRS_ATTACH_IMSI_ATTACH ,	 
 CI_DEV_MM_IMSI_ATTACH	 
 } _CiDevMmAttachType;

typedef UINT8 CiDevMmAttachType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_IDENTITY_TYPE 
 {	 
 CI_DEV_MM_NO_IDENTITY = 0 ,	 
 CI_DEV_MM_IMSI ,	 
 CI_DEV_MM_IMEI ,	 
 CI_DEV_MM_IMEISV ,	 
 CI_DEV_MM_TMSI_PTMSI	 
 } _CiDevMmIdentityType;

typedef UINT8 CiDevMmIdentityType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevMmAttachType attachType ;	 
 CiDevMmIdentityType identityType ;	 
 UINT8 strIdentity [ 16 ] ;	 
 } CiDevGsmUmtsComnAttachBeginEng_MM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_ATTACH_MSG_TYPE 
 {	 
 CI_DEV_MM_ATTACH_ACCEPT = 0 ,	 
 CI_DEV_MM_ATTACH_COMPLETE ,	 
 CI_DEV_MM_ATTACH_REJECT ,	 
 CI_DEV_MM_LOC_UPDATE_ACCEPT ,	 
 CI_DEV_MM_LOC_UPDATE_REJECT	 
 } _CiDevMmAttachMsgType;

typedef UINT8 CiDevMmAttachMsgType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_ATTACH_RESULT_TYPE 
 {	 
 CI_DEV_MM_GPRS_ONLY_ATTACHED = 0 ,	 
 CI_DEV_MM_COMB_GPRS_IMSI_ATTACHED ,	 
 CI_DEV_MM_IMSI_ATTACHED	 
 } _CiDevMmAttachResultType;

typedef UINT8 CiDevMmAttachResultType ;
typedef UINT8 CiDevMmGmmCauseType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 Identity ;	 
 CiDevMmAttachMsgType attachMsgType ;	 
 CiDevMmGmmCauseType gmmCause ;	 
 CiDevMmAttachResultType attachResult ;	 
 } CiDevGsmUmtsComnAttachEndEng_MM;

typedef UINT8 CiDevGsmUmtsComnDetachAcceptEng_MM ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_AREA_UPDATE_RESULT_TYPE 
 {	 
 CI_DEV_MM_AREA_UPDATE_RESULT_RA_UPDATED = 0 ,	 
 CI_DEV_MM_AREA_UPDATE_RESULT_COMB_RA_LA_UPDATED = 1	 
 } _CiDevMmAreaUpdateResultType;

typedef UINT8 CiDevMmAreaUpdateResultType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 Identity ;	 
 UINT16 newLAC ;	 
 UINT8 newRAC ;	 
 CiDevMmGmmCauseType gmmCause ;	 
 CiDevMmAreaUpdateResultType raUpdateRes ;	 
 } CiDevGsmUmtsComnRAUEng_MM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_ACCESS_TECH_TYPE 
 {	 
 CI_DEV_MM_ACCESS_TECH_UNKNOWN = 0 ,	 
 CI_DEV_MM_ACCESS_TECH_GERAN = 1 ,	 
 CI_DEV_MM_ACCESS_TECH_UTRAN = 2 ,	 
 CI_DEV_MM_ACCESS_TECH_NONE = 255	 
 } _CiDevMmAccessTechType;

typedef UINT8 CiDevMmAccessTechType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_FREQ_BAND_TYPE 
 {	 
 CI_DEV_MM_BAND_INFO_T_GSM_380 ,	 
 CI_DEV_MM_BAND_INFO_T_GSM_410 ,	 
 CI_DEV_MM_BAND_INFO_GSM_450 ,	 
 CI_DEV_MM_BAND_INFO_GSM_480 ,	 
 CI_DEV_MM_BAND_INFO_GSM_710 ,	 
 CI_DEV_MM_BAND_INFO_GSM_750 ,	 
 CI_DEV_MM_BAND_INFO_T_GSM_810 ,	 
 CI_DEV_MM_BAND_INFO_GSM_850 ,	 
 CI_DEV_MM_BAND_INFO_P_GSM_900 ,	 
 CI_DEV_MM_BAND_INFO_E_GSM_900 ,	 
 CI_DEV_MM_BAND_INFO_R_GSM_900 ,	 
 CI_DEV_MM_BAND_INFO_T_GSM_900 ,	 
 CI_DEV_MM_BAND_INFO_DCS_1800 ,	 
 CI_DEV_MM_BAND_INFO_PCS_1800 ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_I ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_II ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_III ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_IV ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_V ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_VI ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_VII ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_VIII ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_IX ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_X ,	 
 CI_DEV_MM_BAND_INFO_UTRA_FDD_XI ,	 
 CI_DEV_MM_BAND_INFO_NOT_AVAILABLE = 255	 
 } _CiDevMmFreqBandType;

typedef UINT8 CiDevMmFreqBandType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 fieldValidity ;	 
 UINT8 rac ;	 
 CiDevMmAccessTechType accessTech ;	 
 CiDevMmFreqBandType freqBand ;	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 UINT16 lac ;	 
 UINT32 cellId ;	 
 UINT16 rncID ;	 
 } CiDevGsmUmtsComnNetInfoEng_MM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_RADIO_SVC_STATE_TYPE 
 {	 
 CI_DEV_MM_RADIO_SERV_STATE_UNKNOWN = 0 ,	 
 CI_DEV_MM_RADIO_SERV_STATE_OFF ,	 
 CI_DEV_MM_RADIO_SERV_STATE_SEARCHING ,	 
 CI_DEV_MM_RADIO_SERV_STATE_NO_SERVICE ,	 
 CI_DEV_MM_RADIO_SERV_STATE_2G ,	 
 CI_DEV_MM_RADIO_SERV_STATE_3G ,	 
 CI_DEV_MM_RADIO_SERV_STATE_4G	 
 } _CiDevMmRadioSvcStateType;

typedef UINT8 CiDevMmRadioSvcStateType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_NETWORK_SVC_STATE_TYPE 
 {	 
 CI_DEV_MM_NETW_SERV_STATE_NONE = 0 ,	 
 CI_DEV_MM_NETW_SERV_STATE_EMERGENCY ,	 
 CI_DEV_MM_NETW_SERV_STATE_HOME ,	 
 CI_DEV_MM_NETW_SERV_STATE_HOME_EQUIV ,	 
 CI_DEV_MM_NETW_SERV_STATE_ROAM	 
 } _CiDevMmNetworkSvcStateType;

typedef UINT8 CiDevMmNetworkSvcStateType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevMmRadioSvcStateType radioSvcState ;	 
 CiDevMmNetworkSvcStateType networkSvcState ;	 
 } CiDevGsmUmtsComnServcStateEng_MM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_MM_RADIO_MODE_TYPE 
 {	 
 CI_DEV_MM_RADIO_MODE_NONE = 0 ,	 
 CI_DEV_MM_RADIO_MODE_GSM ,	 
 CI_DEV_MM_RADIO_MODE_GPRS ,	 
 CI_DEV_MM_RADIO_MODE_EDGE ,	 
 CI_DEV_MM_RADIO_MODE_WCDMA ,	 
 CI_DEV_MM_RADIO_MODE_HSDPA ,	 
 CI_DEV_MM_RADIO_MODE_HSUPA ,	 
 CI_DEV_MM_RADIO_MODE_HSPA ,	 
 CI_DEV_MM_RADIO_MODE_HSPA_PLUS ,	 
 CI_DEV_MM_RADIO_MODE_LTE ,	 
 CI_DEV_MM_RADIO_MODE_RTT ,	 
 CI_DEV_MM_RADIO_MODE_EVDO ,	 
 CI_DEV_MM_RADIO_MODE_WIFI	 
 } _CiDevMmRadioModeType;

typedef UINT8 CiDevMmRadioModeType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevMmRadioModeType radioMode ;	 
 } CiDevGsmUmtsComnRadioModeEng_MM;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_PROTOCOL_DICRIMINATOR_TYPE 
 {	 
 CI_DEV_RR_DISCR_GROUP_CALL_CONTROL = 0 , /* Group call control */	 
 CI_DEV_RR_DISCR_BC_CALL_CONTROL = 1 , /* Broadcast call control */	 
 CI_DEV_RR_DISCR_RESERVED1 = 2 , /* Reserved */	 
 CI_DEV_RR_DISCR_CALL_CONTROL = 3 , /* Call control ; call related SS messages */	 
 CI_DEV_RR_DISCR_GTTP = 4 , /* GPRS transparent transport protocol ( GTTP ) */	 
 CI_DEV_RR_DISCR_MM = 5 , /* Mobility management messages */	 
 CI_DEV_RR_DISCR_RR = 6 , /* Radio resources management messages */	 
 CI_DEV_RR_DISCR_GMM = 8 , /* GPRS mobility management messages */	 
 CI_DEV_RR_DISCR_SMS = 9 , /* SMS messages */	 
 CI_DEV_RR_DISCR_SM = 10 , /* GPRS session management messages */	 
 CI_DEV_RR_DISCR_SS = 11 , /* Non call related SS messages */	 
 CI_DEV_RR_DISCR_LCS = 12 , /* Location services */	 
 CI_DEV_RR_DISCR_RESERVED2 = 14 , /* Reserved */	 
 CI_DEV_RR_DISCR_RESERVED3 = 15 /* Reserved */	 
 } _CiDevRrProtocolDicriminatorType;

typedef UINT8 CiDevRrProtocolDicriminatorType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_LOGICAL_CHANNEL_TYPE 
 {	 
 CI_DEV_RR_CHANNEL_BCCH = 0 , /* GSM Broadcast Control Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_PCH , /* GSM Paging Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_RACH , /* GSM Random Access Channel ( Uplink only ) */	 
 CI_DEV_RR_CHANNEL_AGCH , /* GSM Access Grant Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_NCH , /* GSM Notification Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_SACCH , /* GSM Slow Associated Control Channel */	 
 CI_DEV_RR_CHANNEL_FACCH , /* GSM Fast Associated Control Channel */	 
 CI_DEV_RR_CHANNEL_SDCCH , /* GSM Standalone Dedicated Control Channel */	 
 CI_DEV_RR_CHANNEL_PBCCH , /* GPRS Packet Broadcast Control Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_PPCH , /* GPRS Packet Paging Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_PRACH , /* GPRS Packet Random Access Channel ( Uplink only ) */	 
 CI_DEV_RR_CHANNEL_PAGCH , /* GPRS Packet Access Grant Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_PACCH , /* GPRS Packet Associated Control Channel */	 
 CI_DEV_RR_CHANNEL_CCCH_RACH , /* UMTS Common Control Channel over Random Access Channel ( Uplink only ) */	 
 CI_DEV_RR_CHANNEL_DCCH_RACH , /* UMTS Dedicated Control Channel over Random Access Channel ( Uplink only ) */	 
 CI_DEV_RR_CHANNEL_DCCH_DCH , /* UMTS Dedicated Control Channel over Random Access Channel ( Uplink only ) */	 
 CI_DEV_RR_CHANNEL_DCCH_EDCH , /* UMTS Dedicated Control Channel over Enhanced Dedicated Channel ( Uplink only ) */	 
 CI_DEV_RR_CHANNEL_BCCH_BCH , /* UMTS Broadcast Control Channel over Broadcast Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_BCCH_FACH , /* UMTS Broadcast Control Channel over Forward Access Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_BCCH_HSDSCH , /* UMTS Broadcast Control Channel over High-speed Downlink Shared Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_PCCH_PCH , /* UMTS Paging Control Channel over Paging Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_PCCH_HSDSCH , /* UMTS Paging Control Channel over High-speed Downlink Shared Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_CCCH_FACH , /* UMTS Common Control Channel over Forward Access Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_CCCH_HSDSCH , /* UMTS Common Control Channel over High-speed Downlink Shared Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_DCCH_FACH , /* UMTS Dedicated Control Channel over Forward Access Channel ( Downlink only ) */	 
 CI_DEV_RR_CHANNEL_DCCH_HSDSCH , /* UMTS Dedicated Control Channel over High-speed Downlink Shared Channel ( Downlink only ) */	 
 CI_DEV_CHANNEL_NOT_APPLICABLE = 255 /* Not applicable for this L3 protocol */	 
 } _CiDevRrLogicalChannelType;

typedef UINT8 CiDevRrLogicalChannelType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 transactionId ;	 
 CiDevRrProtocolDicriminatorType protDiscr ;	 
 UINT8 msgType ;	 
 CiDevRrLogicalChannelType logicalChannelType ;	 
 UINT8 msg [ 251 ] ;	 
 } CiDevGsmLayer3DwnlnkMsgEng_GRR;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 transactionId ;	 
 CiDevRrProtocolDicriminatorType protDiscr ;	 
 UINT8 sendSeqNum ;	 
 UINT8 msgType ;	 
 CiDevRrLogicalChannelType logicalChannelType ;	 
 UINT8 msg [ 251 ] ;	 
 } CiDevGsmLayer3UplnkMsgEng_GRR;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 bcchArfcn ;	 
 UINT8 rxLev ;	 
 UINT8 bsic ;	 
 BOOL bandInd ;	 
 } CiDevGsmRfServingCellInfoEng_GRR;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 UINT8 bsic ;	 
 UINT8 rxLev ;	 
 } CiDevRrGsmNcellMeasType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 uarfcn ;	 
 UINT16 scramblingCode ;	 
 UINT8 rssi ;	 
 UINT8 ecNo ;	 
 UINT8 rscp ;	 
 } CiDevRrInterRatMeasType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numGsmMeas ;	 
 BOOL numInterRatMeas ;	 
 CiDevRrGsmNcellMeasType gsmMeas [ 32 ] ;	 
 CiDevRrInterRatMeasType interRatMeas [ 32 ] ;	 
 } CiDevGsmNeighbrMeasEng_GRR;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_CELL_CHANGE_ORDER_TYPE 
 {	 
 CI_DEV_RR_CCO_MSG_RR_CELL_CHANGE_ORDER = 0 , /* RR-Cell Change Order */	 
 CI_DEV_RR_CCO_MSG_PACKET_CELL_CHANGE_ORDER , /* Packet Cell Change Order */	 
 CI_DEV_RR_CCO_MSG_CELL_CHANGE_ORDER_FROM_UTRAN , /* Cell Change Order From UTRAN */	 
 CI_DEV_RR_CCO_MSG_PS_HANDOVER_COMMAND , /* PS Handover Command */	 
 } _CiDevRrCellCngOrdMsgType;

typedef UINT8 CiDevRrCellCngOrdMsgType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrCellCngOrdMsgType cellChangeMsg ; /* Cell change message type */	 
 UINT8 targetBsic ; /* GERAN Target cell: BSIC ( 0xFF if not applicable ) */	 
 UINT16 targetArfcn ; /* Bit 15 : ARFCN is DCS ( 0 ) or PCS ( 1 ) ; Bits 0 -14: GERAN Target cell: ARFCN ( 0x7FFF if not applicable ) */	 
 UINT16 targetUarfcn ; /* UTRAN Target cell: UARFCN ( 0xFFFF if not applicable ) */	 
 UINT16 targetSc ; /* UTRAN Target cell: Primary Scrambling code ( 0xFFFF if not applicable ) */	 
 } CiDevGsmWbCellChngBginEng_RR;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_RESULT_TYPE 
 {	 
 CI_DEV_RR_RESULT_SUCCESS = 0 , /* The procedure was successful */	 
 CI_DEV_RR_RESULT_FAILURE , /* The procedure was unsuccessful */	 
 CI_DEV_RR_RESULT_UNKNOWN = 255 /* The result of the procedure is invalid or unknown , or this field is not applicable */	 
 } _CiDevRrResultType;

typedef UINT8 CiDevRrResultType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_IRAT_CH_CAUSE_TYPE 
 {	 
 CI_DEV_RR_RAT_CH_CAUSE_CONFIGURATION_UNACCEPTABLE = 0 , /* Configuration unacceptable */	 
 CI_DEV_RR_IRAT_CH_CAUSE_PHYSICAL_CHAN_FAILURE , /* Physical Channel Failure */	 
 CI_DEV_RR_RAT_CH_CAUSE_PROTOCOL_ERROR , /* Protocol Error */	 
 CI_DEV_RR_IRAT_CH_CAUSE_UNSPECIFIED /* Unspecified */	 
 } _CiDevRrIratChCauseType;

typedef UINT8 CiDevRrIratChCauseType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_PROTOCOL_ERROR_CAUSE_TYPE 
 {	 
 CI_DEV_RR_PROT_ERR_CAUSE_ASN_VIOL_ENC_ERR = 0 , /* ASN.1 violation or encoding error */	 
 CI_DEV_RR_PROT_ERR_CAUSE_MSG_TYPE_NON_EXIST , /* Message type non-existent or not implemented */	 
 CI_DEV_RR_PROT_ERR_CAUSE_MSG_NOT_COMPATIBLE , /* Message not compatible with receiver state */	 
 CI_DEV_RR_PROT_ERR_CAUSE_IE_VALUE_NOT_COMPREHENDED , /* Information element value not comprehended */	 
 CI_DEV_RR_PROT_ERR_CAUSE_IE_MISSING , /* Information element missing */	 
 CI_DEV_RR_PROT_ERR_CAUSE_MSG_EXT_NOT_COMPREHENDED , /* Message extension not comprehended */	 
 CI_DEV_RR_PROT_ERR_CAUSE_UNKNOWN = 255 /* Error cause is not known or cannot be supplied */	 
 } _CiDevRrProtErrCauseType;

typedef UINT8 CiDevRrProtErrCauseType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_CELL_CHANGE_FAIL_TYPE 
 {	 
 CI_DEV_RR_CELL_CH_FAIL_FREQ_NOT_IMPLEMENTED = 0 , /* Frequency not implemented */	 
 CI_DEV_RR_CELL_CH_FAIL_NO_RESP_ON_TARGET_CELL , /* No response on target cell */	 
 CI_DEV_RR_CELL_CH_FAIL_IMMED_ASS_PACCESS_REJ , /* Immediate Assign Reject or Packet Access Reject on target cell */	 
 CI_DEV_RR_CELL_CH_FAIL_ON_GOING_CS_CONN , /* On going CS connection */	 
 CI_DEV_RR_CELL_CH_FAIL_MS_IN_GMM_STANDBY , /* MS in GMM Standby state */	 
 CI_DEV_RR_CELL_CH_FAIL_FORCED_TO_STANDBY , /* Forced to the Standby state */	 
 CI_DEV_RR_CELL_CH_FAIL_RESERVED /* Reserved */	 
 } _CiDevRrCellChngFailType;

typedef UINT8 CiDevRrCellChngFailType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrResultType Result ; /* Result of the cell change procedure */	 
 CiDevRrIratChCauseType irFailure ; /* Inter-RAT Cell Change failure */	 
 CiDevRrProtErrCauseType irProtCause ; /* Protocol error cause , only valid if IrFailure = RR_CH_CAUSE_PROTOCOL_ERROR */	 
 CiDevRrCellChngFailType cellChCause ; /* Packet Cell Change Failure */	 
 } CiDevGsmWbCellChngEndEng_RR;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_HANDOVER_TYPE 
 {	 
 CI_DEV_RR_HANDOVER_TYPE_GSM_NON_SYNCHRONIZED = 0 , /* non-synchronized ( GSM ) */	 
 CI_DEV_RR_HANDOVER_TYPE_GSM_SYNCHRONIZED , /* synchronized ( GSM ) */	 
 CI_DEV_RR_HANDOVER_TYPE_GSM_PRE_SYNCHRONIZED , /* pre-synchronized ( GSM ) */	 
 CI_DEV_RR_HANDOVER_TYPE_GSM_PSEUDO_SYNCHRONIZED , /* pseudo-synchronized ( GSM ) */	 
 CI_DEV_RR_HANDOVER_TYPE_WCDMA_INTRA_FREQUENCY , /* intra-frequency ( WCDMA ) */	 
 CI_DEV_RR_HANDOVER_TYPE_WCDMA_INTER_FREQUENCY , /* inter-frequency ( WCDMA ) */	 
 CI_DEV_RR_HANDOVER_TYPE_INTER_RAT_GSM_TO_WCDMA , /* inter-RAT ( GSM to WCDMA ) */	 
 CI_DEV_RR_HANDOVER_TYPE_INTER_RAT_WCDMA_TO_GSM /* inter-RAT ( WCDMA to GSM ) */	 
 } _CiDevRrhandoverType;

typedef UINT8 CiDevRrhandoverType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrhandoverType handoverType ; /* Type of handover to be performed */	 
 UINT8 targetBsic ; /* GERAN Target cell: BSIC ( 0xFF if not applicable ) */	 
 UINT16 targetArfcn ; /* Bit 15 : ARFCN is DCS ( 0 ) or PCS ( 1 ) Bits 0 -14: GERAN Target cell: ARFCN ( 0x7FFF if not applicable ) */	 
 UINT16 targetUarfcn ; /* UTRAN Target cell: UARFCN ( 0xFFFF if not applicable ) */	 
 UINT16 targetSc ; /* UTRAN Target cell: Primary Scrambling code ( 0xFFFF if not applicable ) */	 
 } CiDevGsmWbHandoverBgnEng_RR;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_HANDOVER_END_TYPE 
 {	 
 CI_DEV_RR_HANDOVER_END_COMPLETE = 0 , /* HANDOVER COMPLETE */	 
 CI_DEV_RR_HANDOVER_END_FAILURE , /* HANDOVER FAILURE */	 
 CI_DEV_RR_HANDOVER_END_TO_UTRAN_COMPLETE , /* HANDOVER TO UTRAN COMPLETE */	 
 CI_DEV_RR_HANDOVER_END_FROM_UTRAN_FAILURE , /* HANDOVER FROM UTRAN FAILURE */	 
 CI_DEV_RR_HANDOVER_END_WCDMA_INTER_FREQ_COMPLETE , /* RADIO BEARER SETUP COMPLETE... */	 
 CI_DEV_RR_HANDOVER_END_WCDMA_INTER_FREQ_FAILURE /* RADIO BEARER SETUP FAILURE... */	 
 } _CiDevRrhandoverEndType;

typedef UINT8 CiDevRrhandoverEndType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_CAUSE_TYPE 
 {	 
 CI_DEV_RR_CAUSE_NORMAL_EVENT = 0 , /* Normal event */	 
 CI_DEV_RR_CAUSE_ABNORMAL_REL_UNSPECIFIED = 1 , /* Abnormal release , unspecified */	 
 CI_DEV_RR_CAUSE_ABNORMAL_REL_CHAN_UNACCEPTABLE = 2 , /* Abnormal release , channel unacceptable */	 
 CI_DEV_RR_CAUSE_ABNORMAL_REL_TIMER_EXPIRED = 3 , /* Abnormal release , timer expired */	 
 CI_DEV_RR_CAUSE_ABNORMAL_REL_NO_ACT_ON_RADIO_PATH = 4 , /* Abnormal release , no activity on the radio path */	 
 CI_DEV_RR_CAUSE_PREEMPTIVE_RELEASE = 5 , /* Preemptive release */	 
 CI_DEV_RR_CAUSE_UTRAN_CONFIG_UNKNOWN = 6 , /* UTRAN configuration unknown */	 
 CI_DEV_RR_CAUSE_HO_IMPOSSIBLE_TA_OOR = 8 , /* Handover impossible , timing advance out of range */	 
 CI_DEV_RR_CAUSE_CHANNEL_MODE_UNACCEPTABLE = 9 , /* Channel mode unacceptable */	 
 CI_DEV_RR_CAUSE_FREQ_NOT_IMPLEMENTED = 10 , /* Frequency not implemented */	 
 CI_DEV_RR_CAUSE_ORIG_TALKER_LEAVING_GROUP_AREA = 11 , /* Originator or talker leaving group call area */	 
 CI_DEV_RR_CAUSE_LOWER_LAYER_FAILURE = 12 , /* Lower layer failure */	 
 CI_DEV_RR_CAUSE_CALL_ALREADY_CLEARED = 65 , /* Call already cleared */	 
 CI_DEV_RR_CAUSE_SEMAN_INCORRECT_MESSAGE = 95 , /* Semantically incorrect message */	 
 CI_DEV_RR_CAUSE_INVALID_MAND_INFO = 96 , /* Invalid mandatory information */	 
 CI_DEV_RR_CAUSE_MESSAGE_TYPE_NON_EXISTENT = 97 , /* Message type non-existent or not implemented */	 
 CI_DEV_RR_CAUSE_MESSAGE_TYPE_NOT_COMPATIBLE = 98 , /* Message type not compatible with protocol state */	 
 CI_DEV_RR_CAUSE_CONDITIONAL_IE_ERROR = 100 , /* Conditional IE error */	 
 CI_DEV_RR_CAUSE_NO_CELL_ALLOC_AVAILABLE = 101 , /* No cell allocation available */	 
 CI_DEV_RR_CAUSE_PROTOCOL_ERR_UNSPECIFIED = 111 /* Protocol error unspecified */	 
 } _CiDevRrCauseType;

typedef UINT8 CiDevRrCauseType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_IRAT_HANDOVER_FAILURE_TYPE 
 {	 
 CI_DEV_RR_IRAT_HO_CAUSE_CONFIGURATION_UNACCEPTABLE , /* Configuration unacceptable */	 
 CI_DEV_RR_IRAT_HO_CAUSE_PHYSICAL_CHAN_FAILURE , /* Physical Channel Failure */	 
 CI_DEV_RR_IRAT_HO_CAUSE_PROTOCOL_ERROR , /* Protocol Error */	 
 CI_DEV_RR_IRAT_HO_CAUSE_INTER_RAT_PROTOCOL_ERROR , /* Inter-Rat protocol error */	 
 CI_DEV_RR_IRAT_HO_CAUSE_UNSPECIFIED /* Unspecified */	 
 } _CiDevRrIrHandoverFailureType;

typedef UINT8 CiDevRrIrHandoverFailureType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_RRC_HANDOVER_FAILURE_TYPE 
 {	 
 CI_DEV_RR_FAILURE_CAUSE_CONFIGURATION_UNSUPPORTED = 0 , /* Configuration unsupported */	 
 CI_DEV_RR_FAILURE_CAUSE_PHYSICAL_CHANNEL_FAILURE , /* Physical Channel Failure */	 
 CI_DEV_RR_FAILURE_CAUSE_INCOMPAT_SIM_RECONFIGURATION , /* Incompatible Simultaneous Reconfiguration */	 
 CI_DEV_RR_FAILURE_CAUSE_COMPRESSED_MODE_RT_ERROR , /* Compressed Mode Runtime Error */	 
 CI_DEV_RR_FAILURE_CAUSE_PROTOCOL_ERROR , /* Protocol Error */	 
 CI_DEV_RR_FAILURE_CAUSE_CELL_UPDATE_OCCURRED , /* Cell Update Occurred */	 
 CI_DEV_RR_FAILURE_CAUSE_INVALID_CONFIGURATION , /* Invalid Configuration */	 
 CI_DEV_RR_FAILURE_CAUSE_CONFIGURATION_INCOMPLETE , /* Configuration Incomplete */	 
 CI_DEV_RR_FAILURE_CAUSE_UNSUPPORTED_MEASUREMENT , /* Unsupported Measurement */	 
 CI_DEV_RR_FAILURE_CAUSE_UNKNOWN = 255 /* Unknown or successful configuration */	 
 } _CiDevRrcHandoverFailureType;

typedef UINT8 CiDevRrcHandoverFailureType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrhandoverEndType handoverMsg ; /* Type of handover message sent */	 
 CiDevRrCauseType rrCause ; /* RR Cause IE from HANDOVER COMPLETE & HANDOVER FAILURE messages. The values are derived directly from 3 GPP TS 44.018000 section 10.500000 .2.31 , RR Cause */	 
 CiDevRrIrHandoverFailureType irHandoverFailure ; /* Inter-RAT handover failure cause for normal handovers */	 
 CiDevRrcHandoverFailureType rrcHandoverFailure ; /* RRC failure cause for UMTS hard handovers */	 
 CiDevRrProtErrCauseType iRProtCause ; /* Protocol error cause , only valid if ucIRFailure = IQ_IRAT_CAUSE_INTER_RAT_PROTOCOL_ERROR or IQ_FAILURE_CAUSE_PROTOCOL_ERROR */	 
 } CiDevGsmWbHandoverEndEng_RR;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RLC_UL_MODE_TYPE 
 {	 
 CI_DEV_RLC_MODE_UNKNOWN = 0 , /* Mode could not be determined */	 
 CI_DEV_RLC_MODE_UNACKNOWLEDGED , /* Unacknowledged mode */	 
 CI_DEV_RLC_MODE_ACKNOWLEDGED , /* Acknowledged mode */	 
 CI_DEV_RLC_MODE_TRANSPARENT , /* Transparent mode */	 
 CI_DEV_RLC_MODE_FLEXIBLELAYERONE /* FLO mode ( GPRS / EDGE only ) */	 
 } _CiDevRlcUlModeType;

typedef UINT8 CiDevRlcUlModeType ;
typedef CiDevRlcUlModeType CiDevRlcDlModeType ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RLC_MCS_TYPE 
 {	 
 CI_DEV_RLC_MCS_TYPE_CS1 = 0 , /* GPRS Coding Scheme 1 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_CS2 , /* GPRS Coding Scheme 2 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_CS3 , /* GPRS Coding Scheme 3 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_CS4 , /* GPRS Coding Scheme 4 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS1 , /* EDGE Modulation Coding Scheme 1 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS2 , /* EDGE Modulation Coding Scheme 2 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS3 , /* EDGE Modulation Coding Scheme 3 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS4 , /* EDGE Modulation Coding Scheme 4 ( GMSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS5 , /* EDGE Modulation Coding Scheme 5 ( 8 PSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS6 , /* EDGE Modulation Coding Scheme 6 ( 8 PSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS7 , /* EDGE Modulation Coding Scheme 7 ( 8 PSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS8 , /* EDGE Modulation Coding Scheme 8 ( 8 PSK ) */	 
 CI_DEV_RLC_MCS_TYPE_MCS9 , /* EDGE Modulation Coding Scheme 9 ( 8 PSK ) */	 
 CI_DEV_RLC_MCS_TYPE_NOT_APPLICABLE = 255 /* The modulation and coding scheme is not applicable , e.g. , in the case of UMTS */	 
 } _CiDevRlcMcsType;

typedef UINT8 CiDevRlcMcsType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 rlcUlDuration ;	 
 UINT32 rlcUlByteCnt ;	 
 UINT32 rlcUlBlkCnt ;	 
 UINT32 rlcUlRetrBlkCnt ;	 
 UINT32 rlcDlDuration ;	 
 UINT32 rlcDlByteCnt ;	 
 UINT32 rlcDlBlkCnt ;	 
 UINT32 rlcDlMissingBlkCnt ;	 
 CiDevRlcUlModeType rlcUlMode ;	 
 CiDevRlcDlModeType rlcDlMode ;	 
 CiDevRlcMcsType ulCodingScheme ;	 
 CiDevRlcMcsType dlCodingScheme ;	 
 } CiDevGsmGprsEdgeRlcStatisticsEng_RLC;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_L1_CODEC_TYPE 
 {	 
 CI_DEV_L1_CODEC_TYPE_GSM_FR = 0 , /* GSM Full Rate ( 13.000000 kBit / s ) */	 
 CI_DEV_L1_CODEC_TYPE_GSM_HR , /* GSM Half Rate ( 5.600000 kBit / s ) */	 
 CI_DEV_L1_CODEC_TYPE_GSM_EFR , /* GSM Enhanced Full Rate ( 12.200000 kBit / s ) */	 
 CI_DEV_L1_CODEC_TYPE_FR_AMR , /* Full Rate Adaptive Multi-Rate */	 
 CI_DEV_L1_CODEC_TYPE_HR_AMR , /* Half Rate Adaptive Multi-Rate */	 
 CI_DEV_L1_CODEC_TYPE_UMTS_AMR , /* UMTS Adaptive Multi-Rate */	 
 CI_DEV_L1_CODEC_TYPE_UMTS_AMR2 , /* UMTS Adaptive Multi-Rate 2 */	 
 CI_DEV_L1_CODEC_TYPE_TDMA_EFR , /* TDMA Enhanced Full Rate ( 7.400000 kBit / s ) */	 
 CI_DEV_L1_CODEC_TYPE_PDC_EFR , /* PDC Enhanced Full Rate ( 6.700000 kBit / s ) */	 
 CI_DEV_L1_CODEC_TYPE_FR_AMR_WB , /* Full Rate Adaptive Multi-Rate WideBand */	 
 CI_DEV_L1_CODEC_TYPE_UMTS_AMR_WB , /* UMTS Adaptive Multi-Rate WideBand */	 
 CI_DEV_L1_CODEC_TYPE_OHR_AMR , /* 8 PSK Half Rate Adaptive Multi-Rate */	 
 CI_DEV_L1_CODEC_TYPE_OFR_AMR_WB , /* 8 PSK Full Rate Adaptive Multi-Rate WideBand */	 
 CI_DEV_L1_CODEC_TYPE_OHR_AMR_WB , /* 8 PSK Half Rate Adaptive Multi-Rate WideBand */	 
 CI_DEV_L1_CODEC_TYPE_NOT_APPLICABLE = 99 /* Speech codec not in use */	 
 } _CiDevL1CodecType;

typedef UINT8 CiDevL1CodecType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 dedArfcn ;	 
 UINT8 Maio ;	 
 UINT8 hsn ;	 
 UINT8 timeslot ;	 
 UINT8 rxLevelFull ;	 
 UINT8 rxLevelSub ;	 
 UINT8 rxQualFul ;	 
 UINT8 rxQualSub ;	 
 UINT8 ferFull ;	 
 UINT8 ferSub ;	 
 CiDevL1CodecType codec ;	 
 UINT8 timingAdv ;	 
 UINT8 powerLevel ;	 
 UINT8 dedConfig ;	 
 BOOL bandInd ;	 
 } CiDevGsmSrvCellInfoEng_L1;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 fer ;	 
 UINT8 ber ;	 
 UINT8 c2i ;	 
 UINT8 iLevel ;	 
 } CiDevL1GprsPdchType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevL1GprsPdchType pdch [ 8 ] ;	 
 UINT8 cValue ;	 
 UINT8 rxQual ;	 
 UINT8 meanBep ;	 
 UINT8 cvBep ;	 
 UINT8 signalVar ;	 
 } CiDevGsmGprsEdgeLinkQualityEng_L1;

typedef _CiDevRrProtocolDicriminatorType _CiDevRrNasProtDiscrType ;
typedef UINT8 CiDevRrNasProtDiscrType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrLogicalChannelType logicalTransportChannelType ;	 
 UINT8 rrcMessageType ;	 
 UINT8 rrcTransactionId ;	 
 CiDevRrNasProtDiscrType nasProtocolDiscriminator ;	 
 UINT8 nasMessageType ;	 
 UINT8 nasTransactionId ;	 
 UINT8 Msg [ 1520 ] ;	 
 } CiDevWbLayer3DwnlnkMsgEng_RRC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrLogicalChannelType logicalTransportChannelType ;	 
 UINT8 rrcMessageType ;	 
 UINT8 rrcTransactionId ;	 
 CiDevRrNasProtDiscrType nasProtocolDiscriminator ;	 
 UINT8 nasMessageType ;	 
 UINT8 nasTransactionId ;	 
 UINT8 Msg [ 1520 ] ;	 
 } CiDevWbLayer3UplnkMsgEng_RRC;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RR_RRC_STATE_TYPE 
 {	 
 CI_DEV_RRC_STATE_TYPE_IDLE = 0 , /* IDLE */	 
 CI_DEV_RRC_STATE_TYPE_URA_PCH , /* URA_PCH */	 
 CI_DEV_RRC_STATE_TYPE_CELL_PCH , /* CELL_PCH */	 
 CI_DEV_RRC_STATE_TYPE_CELL_FACH , /* CELL_FACH */	 
 CI_DEV_RRC_STATE_TYPE_CELL_DC /* CELL_DCH */	 
 } _CiDevRrRrcStateType;

typedef UINT8 CiDevRrRrcStateType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 CiDevRrRrcStateType rrcState ;	 
 } CiDevWbRrcStateEng_RRC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 tgpsId ;	 
 UINT8 tgpsStatus ;	 
 } CiDevRrCmInfoType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numCmInfo ;	 
 CiDevRrCmInfoType cmInfo [ 6 ] ;	 
 } CiDevWbCompressModeStateEng_RRC;

typedef CiDevRrInterRatMeasType CiDevRrCellsListType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numActive ;	 
 UINT8 numMonitored ;	 
 UINT8 numDetected ;	 
 CiDevRrCellsListType cells [ 32 + 32 ] ;	 
 } CiDevWbActiveAndMonitoredSetInfoEng_RRC;

typedef CiDevRrGsmNcellMeasType CiDevRrNeighMeasCellsListType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numMeas ;	 
 BOOL bandInd ;	 
 CiDevRrNeighMeasCellsListType measCells [ 32 ] ;	 
 } CiDevWbInterRatNeighborMeasEng_RRC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 Uarfcn ;	 
 UINT16 scellScramblingCode ;	 
 UINT8 scellRssi ;	 
 UINT8 scellEcN0 ;	 
 UINT8 scellRscp ;	 
 UINT8 txPower ;	 
 } CiDevWBRfInfoEng_RRC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 contextId ; /* The identity of PDP context associated with the referenced PS radio bearer */	 
 UINT8 rabId ; /* The identity of the PS radio access bearer ( RAB ) to which this structure pertains */	 
 UINT8 nsapi ; /* The NSAPI associated with the referenced PS RAB */	 
 UINT8 radioBearerId ; /* The identity of radio bearer currently associated with the referenced PS RAB */	 
 } CiDevRlcPsRbInfoType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 rabId ; /* The identity of the PS radio access bearer ( RAB ) to which this structure pertains */	 
 UINT8 radioBearerId ; /* The identity of radio bearer currently associated with the referenced CS RAB */	 
 } CiDevRlcCsRbInfoType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 radioBearerId ; /* The identity of the signaling radio bearer */	 
 } CiDevRlcSrbInfoType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numPsRb ; /* The number of PS RBs and PDP context IDs about which this metric contains information */	 
 UINT8 numCsRb ; /* The number of CS RBs about which this metric contains information */	 
 UINT8 numSrb ; /* The number of SRBs about which this metric contains information */	 
 CiDevRlcPsRbInfoType psRbInfo [ 11 ] ; /* An array of structures of type CiRlcPsRbInfoType */	 
 CiDevRlcCsRbInfoType csRbInfo [ 3 ] ; /* An array of structures of type CiRlcCsRbInfoType */	 
 CiDevRlcSrbInfoType srbRbInfo [ 8 ] ; /* An array of structures of type CiRlcSrbInfoType */	 
 } CiDevWBMultiRabStateEng_RLC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 userRBId ; /* The ID of the user radio bearer to which this structure pertains */	 
 CiDevRlcUlModeType rlcMode ; /* The RLC mode of operation for this radio bearer this metric pertains in milliseconds */	 
 UINT32 rlcByteCnt ; /* Number of new RLC data ( payload ) bytes received ( UL ) or transmitted ( DL ) on this radio bearer */	 
 UINT32 rlcBlkCnt ; /* Number of new RLC PDUs received or transmitted on this radio bearer */	 
 UINT32 rlcRetrBlkCnt ; /* Number retransmitted PDUs ( UL ) or number of PDUs requested for retransmission ( DL ) on this radio bearer */	 
 } CiDevRlcUlStatsType;

typedef CiDevRlcUlStatsType CiDevRlcDlStatsType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 unsigned long rlcUlDuration ; /* RLC uplink measurement period to which this metric pertains in milliseconds */	 
 unsigned long rlcDlDuration ; /* RLC downlink measurement period to which this metric pertains in milliseconds */	 
 unsigned char numUlUserRB ; /* Number of uplink user radio bearers to which this metric pertains ( The deprecated name of this field was ucNumUlTrCh ) */	 
 unsigned char numDlUserRB ; /* Number of user radio bearers to which this metric pertains ( The deprecated name of this field was ucNumDlTrCh ) */	 
 CiDevRlcUlStatsType rlcUlStats [ 11 ] ; /* An array of structure type iq_rb_rlc_stats_t whose length is numUlUserRB ( The deprecated name of this field was iq_trch_rlc_stats_t ) */	 
 CiDevRlcDlStatsType rlcDlStats [ 11 ] ; /* An array of structure type iq_rb_rlc_stats_t whose length is numDlUserRB ( The deprecated name of this field was iq_trch_rlc_stats_t ) */	 
 } CiDevWBUmtsHspaRlcStatisticsEng_RLC;

//ICAT EXPORTED ENUM 
 typedef enum UrlcEngModeResetPduTypeTag 
 {	 
 URLC_ENG_MODE_RESET_PDU = 1 ,	 
 URLC_ENG_MODE_RESET_ACK_PDU = 2	 
 } UrlcEngModeResetPduType;

//ICAT EXPORTED ENUM 
 typedef enum UrlcEngModeDirectionTypeTag 
 {	 
 URLC_ENG_MODE_DL_DIRECTION = 0 , /* The PDU was received by the UE */	 
 URLC_ENG_MODE_UL_DIRECTION = 1 /* The PDU was transmitted by the UE */	 
 } UrlcEngModeDirectionType;

//ICAT EXPORTED ENUM 
 typedef enum UrlcEngModeMaxResetTag 
 {	 
 URLC_ENG_MODE_MAX_RESET_NOT_REACHED = 0 , /* MaxRST has not yet been reached for this AM-RLC entity */	 
 URLC_ENG_MODE_MAX_RESET_REACHED = 1 /* MaxRST has been reached ( i.e. , transmission of this PDU is prohibited ) All other values are reserved */	 
 } UrlcEngModeMaxReset;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 radioBearerId ;	 
 UINT8 direction ; /* 0 : The PDU was received by the UE	 
 * 1 : The PDU was transmitted by the UE	 
 * All other values are reserved */	 
 UINT8 pduType ; /* The type of PDU to which this metric pertains:	 
 * 1 : RESET PDU	 
 * 2 : RESET ACK PDU	 
 * All other values are reserved	 
 * NOTE: This field corresponds to PDU Type as defined in 3 GPP TS 25.322000 / 9.200000 .2.2 */	 
	 
 UINT8 resetSeqNum ; /* The sequence number of the reset transaction to which this metric pertains.	 
 * Shall be set to 255 if the Reset sequence , Number is not available	 
 * NOTE: This field corresponds to Reset Sequence Number as defined in 3 GPP TS 25.322000 / 9.200000 .2.13 */	 
	 
 UINT8 maxRst ; /* 0 : MaxRST has not yet been reached for this AM-RLC entity	 
 * 1 : MaxRST has been reached ( i.e. , transmission of this PDU is prohibited )	 
 * All other values are reserved */	 
 } CiDevWBRlcResetEng_RLC;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 txDuration ; /* Duration of measurement period in milliseconds */	 
 UINT32 octetCnt ; /* Total number of octets transmitted in the measurement period , including retransmissions */	 
 UINT16 ackBlkCnt ; /* Positive acknowledgment ( ACK ) block count , indicating the number of blocks transmitted	 
 by the UE and successfully received by the Node B */	 
	 
 UINT16 nackBlkCnt ; /* Negative acknowledgment ( NACK ) block count , indicating the number of blocks transmitted	 
 by the UE but not successfully decoded / received by the Node B */	 
	 
 UINT8 servingGrant [ 32 ] ;	 
 /* Uplink Serving Grant contains distribution count of E-AGCH	 
 Absolute Grant Value Indexes observed during that metric reporting period */	 
	 
 UINT16 servingCell ; /* From PHY yyyy metric , HSUPA Serving Cell */	 
	 
	 
 UINT16 happyCnt ; /* The happy bit count is the number of sampled happy bits during the measurement period */	 
	 
	 
 UINT16 unhappyCnt ; /* The unhappy bit count is the number of sampled unhappy bits during the measurement period */	 
	 
 UINT16 etfciSampleCnt ; /* Number of E-TFCI samples in the array ETFCI */	 
	 
 UINT8 etfci [ 128 ] ;	 
 /* Array of uplink E-DCH transport format combination indicator ( E-TFCI )	 
 samples in the range ( 0 ..127 ) , used to identify the transport block size on E-DCH */	 
	 
	 
 UINT16 bpskBlkCnt ; /* From PHY yyyy metric , number of transport blocks transmitted using BSPK modulation */	 
	 
	 
 UINT16 qam16BlkCnt ; /* From PHY yyyy metric , number of transport blocks transmitted using 16 QAM modulation */	 
 } CiDevWBHsupaStatisticsEng_Phy;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 ack ;	 
 UINT16 nack ;	 
 UINT16 dtx ;	 
 } CiDevPhycCqiDistType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 qpskBlkCnt ;	 
 UINT16 qam16BlkCnt ;	 
 UINT16 Qam64BlkCnt ;	 
 UINT16 decodeAttemptCnt ;	 
 UINT16 decodeValidCnt ;	 
 UINT16 hsScchLessCnt ;	 
 CiDevPhycCqiDistType cqiDistPrimary [ 31 ] ;	 
 UINT16 numCodesAlloc [ 16 ] ;	 
 UINT16 mimoCqiReporting ;	 
 UINT16 trBlkSizePrSampleCnt ;	 
 UINT16 trBlkSizeSecSampleCnt ; /* Not in use */	 
 UINT16 numPciAlloc [ 4 ] ;	 
 CiDevPhycCqiDistType cqiDistSecondary [ 31 ] ;	 
 UINT16 trBlkSizePrimary [ 100 ] ; /* Size is max of trBlkSizePrSampleCnt */	 
 } CiDevPhycHsDschStatsType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 rcvByteCnt ;	 
 UINT16 hsDschCellCnt ;	 
 CiDevPhycHsDschStatsType hsDschCelStats [ 2 ] ;	 
 } CiDevWBHsdpaEvolvedStatisticsEng_Phy;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_PHYC_TRANSPORT_CH_TYPE 
 {	 
 CI_DEV_PHYC_TR_CH_TYPE_DL_DCH = 0 , /* Downlink dedicated transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_UL_DCH , /* Uplink dedicated transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_EDCH , /* Enhanced ( uplink ) dedicated transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_BCH , /* Broadcast common transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_FACH , /* Forward access common transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_PCH , /* Paging common transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_RACH , /* Random access common transport channel */	 
 CI_DEV_PHYC_TR_CH_TYPE_HSDSCH , /* High speed downlink shared transport channel */	 
 CI_DEV_TR_CH_TYPE_UNKNOWN = 255 /* The transport channel type is unknown */	 
 } _CiDevPhycTransportChType;

typedef UINT8 CiDevPhycTransportChType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 trChId ;	 
 CiDevPhycTransportChType trChType ;	 
 UINT16 numTrBlocks ;	 
 UINT16 numErrTrBlocks ;	 
 } CiDevL1TransportChType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numTrCh ;	 
 CiDevL1TransportChType trCh [ 25 ] ;	 
 } CiDevWBUmtsHspaTransportChannelInfoEng_L1;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_L1_T313_STATUS_TYPE 
 {	 
 CI_DEV_L1_T313_STATUS_STOPPED = 0 , /* The T313 timer for the RLS is stopped ( the radio link has been restored ) */	 
 CI_DEV_L1_T313_STATUS_RUNNING , /* The T313 timer for the RLS has been started */	 
 CI_DEV_L1_T313_STATUS_EXPIRED , /* The T313 timer for the RLS has expired ( the radio link has failed ) */	 
 CI_DEV_L1_T313_STATUS_UNKNOWN = 255 /* The T313 timer is status is invalid or unknown , or this field is not applicable */	 
 } _CiDevL1T313StatusType;

typedef UINT8 CiDevL1T313StatusType ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 ScramblingCode ;	 
 UINT8 tpcCombinationIndex ;	 
 CiDevL1T313StatusType t313Status ;	 
 } CiDevL1SyncStatusType;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numRlSyncStatus ;	 
 CiDevL1SyncStatusType RlSyncStatus [ 6 ] ;	 
 } CiDevWBUmtsHspaRadioLinkSyncStatusEng_L1;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_COMMON_ENGMODE_INFO_TAG 
 {	 
 CI_DEV_LT01_ERRC_MSG = 0 , /* E-UTRA RRC Message */	 
 CI_DEV_LT02_NAS_MSG , /* E-UTRA NAS Message */	 
 CI_DEV_LT03_LTE_MSR_MSG , /* E-UTRA Measurement Report */	 
 CI_DEV_LT04_LTE_INTER_MSR_MSG , /* E-UTRA Inter-RAT Measurement Report */	 
 CI_DEV_LT05_LTE_NEIGHBOR_LIST_MSG , /* E-UTRA Neighbor List */	 
 CI_DEV_LT06_LTE_ERRC_STATE_MSG , /* E-UTRA RRC State */	 
 CI_DEV_LT07_LTE_MAC_CONTROL_MSG , /* E-UTRA MAC Control State */	 
 CI_DEV_LT08_LTE_MAC_RACH_MSG , /* E-UTRA MAC Random Access Attempt */	 
 CI_DEV_LT17_LTE_RLC_MSG , /* E-UTRA RLC Data Transfer Report */	 
 CI_DEV_LT10_LTE_EPS_MSG , /* E-UTRA EPS Bearer Context Status */	 
 CI_DEV_LT11_LTE_EPS_QOS_MSG , /* E-UTRA EPS Bearer QoS */	 
 CI_DEV_LT12_LTE_PUSCH_STATUS_MSG , /* E-UTRA PUSCH Transmission Status */	 
 CI_DEV_LT13_LTE_RADIO_LINK_MSG , /* E-UTRA Radio Link Sync Status */	 
 CI_DEV_GS15_SM_PDP_CONTECXT_ACTIVATION , /* GSM / UMTS PDP Context Activation SM Message */	 
 CI_DEV_GS18_SM_PDP_CONTEXT_END , /* GSM / UMTS PDP Context End SM Message */	 
 CI_DEV_GS19_SM_PDP_CONTEXT_REQUEST , /* GSM / UMTS PDP Context Request SM Message */	 
 CI_DEV_GS40_MM_ATTACH_BEGIN , /* GSM / UMTS Attach Begin MM Message */	 
 CI_DEV_GS41_MM_ATTACH_END , /* GSM / UMTS Attach End MM Message */	 
 CI_DEV_GS42_MM_DETACH_END , /* GSM / UMTS Detach Accept MM Message */	 
 CI_DEV_GS43_MM_ROUTING_AREA_UPDATE , /* GSM / UMTS Routing Area Update MM Message */	 
 CI_DEV_GS46_MM_NETWORK_INFO , /* GSM / GPRS / UMTS Network Info MM Message */	 
 CI_DEV_GS47_MM_SERVICE_STATE , /* GSM / GPRS / UMTS Service State MM Message */	 
 CI_DEV_GS6E_MM_RADIO_MODE , /* GSM / GPRS / UMTS Radio Mode MM Message */	 
 CI_DEV_GS30_GRR_LAYER_3_DOWNLINK_MSG , /* GSM / GPRS / EDGE Layer 3 Downlink Message GRR Message */	 
 CI_DEV_GS31_GRR_LAYER_3_UPLINK_MSG , /* GSM / GPRS / EDGE Layer 3 Uplink Message GRR Message */	 
 CI_DEV_RF51_GRR_GSM_GPRS_EDGE_RF_SERVING_CELL_INFO , /* GSM Serving Cell Info GRR Message */	 
 CI_DEV_RF53_GRR_NEIGHBOR_MEASUERMENT_MSG , /* GSM Neighbor Measurement GRR Message */	 
 CI_DEV_GS57_RR_CELL_CHANGE_BEGIN_MSG , /* GSM and WB Cell Change Begin RR Message */	 
 CI_DEV_GS58_RR_CELL_CHANGE_END_MSG , /* GSM and WB Cell Change End RR Message */	 
 CI_DEV_GS54_RR_HANDOVER_BEGIN_MSG , /* GSM and WB Handover Begin RR Message */	 
 CI_DEV_GS55_RR_HANDOVER_END_MSG , /* GSM and WB Handover End RR Message */	 
 CI_DEV_GS81_RLC_GPRS_EDGE_RLC_STATISTICS , /* GPRS / EDGE RLC Statistics RLC Message */	 
 CI_DEV_RF52_L1_GSM_SERVING_CELL_INFO_MSG , /* GSM Serving Cell Info L1 Message */	 
 CI_DEV_RF54_L1_GPRS_EDGE_LINK_QUALITY_MSG , /* GSM Gprs Edge Link Quality L1 Message */	 
 CI_DEV_GS34_RRC_UMTS_HSPA_LAYER3_DOWNLINK_MSG , /* WB UMTS / HSPA Layer 3 Downlink RRC Message */	 
 CI_DEV_GS35_RRC_UMTS_HSPA_LAYER3_UPLINK_MSG , /* WB UMTS / HSPA Layer 3 Uplink RRC Message */	 
 CI_DEV_GS67_RRC_STATE_MSG , /* WB RRC State RRC Message */	 
 CI_DEV_GS6F_RRC_COMPRESS_MODE_STATE_MSG , /* WB CompressModeState RRC Message */	 
 CI_DEV_RF61_RRC_UMTS_HSPA_ACTIVE_AND_MONITORED_SET_INFO_MSG , /* WB UMTS / HSPA Active and Monitored Set Info RRC Message */	 
 CI_DEV_RF62_RRC_INTER_NEIGHBOR_MEAS_MSG , /* WB Inter Neighbor Measurement RRC Message */	 
 CI_DEV_RF60_RRC_RF_SERVING_CELL_INFO_MSG , /* WB RF and Serving Cell Info RRC Message */	 
 CI_DEV_GS6D_RLC_WB_MULTI_RAB_STATE_MSG , /* WB Multi-RAB State RLC Message */	 
 CI_DEV_GS84_RLC_UMTS_HSPA_RLC_STATISTICS_MSG , /* WB UMTS / HSPA RLC Statistics RLC Message */	 
 CI_DEV_GS86_RLC_RESET_MSG , /* WB RLC Reset RLC Message */	 
 CI_DEV_GS83_PHY_HSUPA_STATISTICS_MSG , /* WB HSUPA Statistics PHY Message */	 
 CI_DEV_GS88_PHY_HSDPA_EVOLVED_STATISTIC_MSG , /* WB HSDPA Evolved Statistics PHY Message */	 
 CI_DEV_RF63_L1_UMTS_HSPA_TRANSPORT_CHANNEL_INFO_MSG , /* WB UMTS / HSPA Transport Channel Info L1 Message */	 
 CI_DEV_RF64_L1_UMTS_HSPA_RADIO_LINK_SYNC_STATUS_MSG , /* WB UMTS / HSPA Radio Link Sync Status L1 Message */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_INFO_TYPES	 
 } _CiDevCommonEngmodeInfoType;

typedef UINT8 CiDevCommonEngmodeInfoType ;
//ICAT EXPORTED UNION : _CiDevCommonEngmodeInfoType 
 typedef union CiDevCommonEngmodeInfo_struct 
 {	 
 CiDevLteEng_RRC LT01 ; /* E-UTRA RRC Message */	 
 CiDevLteEng_NAS LT02 ; /* E-UTRA NAS Message */	 
 CiDevLteEng_MSR LT03 ; /* E-UTRA Measurement Report */	 
 CiDevLteEng_InterMsr LT04 ; /* E-UTRA Inter-RAT Measurement Report */	 
 CiDevLteEng_NeighborList LT05 ; /* E-UTRA Neighbor List */	 
 CiDevLteEng_RrcState LT06 ; /* E-UTRA RRC State */	 
 CiDevLteEng_MAC LT07 ; /* E-UTRA MAC Control State */	 
 CiDevLteEng_MAC_RACH LT08 ; /* E-UTRA MAC Random Access Attempt */	 
 CiDevLteEng_RLC LT17 ; /* E-UTRA RLC Data Transfer Report */	 
 CiDevLteEng_EPS LT10 ; /* E-UTRA EPS Bearer Context Status */	 
 CiDevLteEng_EPS_QoS LT11 ; /* E-UTRA EPS Bearer QoS */	 
 CiDevLteEng_PUSCH LT12 ; /* E-UTRA PUSCH Transmission Status */	 
 CiDevLteEng_RadioLink LT13 ; /* E-UTRA Radio Link Sync Status */	 
 CiDevGsmUmtsComnPdpCActEng_SM GS15 ; /* PDP Context Activation GSM / UMTS PDP Context Activation SM Message */	 
 CiDevGsmUmtsComnPdpCEndEng_SM GS18 ; /* PDP Context End GSM / UMTS PDP Context End SM Message */	 
 CiDevGsmUmtsComnPdpCReqEng_SM GS19 ; /* PDP Context Request GSM / UMTS PDP Context Request SM Message */	 
 CiDevGsmUmtsComnAttachBeginEng_MM GS40 ; /* Attach Begin GSM / UMTS Attach Begin MM Message */	 
 CiDevGsmUmtsComnAttachEndEng_MM GS41 ; /* Attach End GSM / UMTS Attach End MM Message */	 
 CiDevGsmUmtsComnDetachAcceptEng_MM GS42 ; /* Detach Accept GSM / UMTS Detach Accept MM Message */	 
 CiDevGsmUmtsComnRAUEng_MM GS43 ; /* Routing Area Update GSM / UMTS Routing Area Update MM Message */	 
 CiDevGsmUmtsComnNetInfoEng_MM GS46 ; /* GSM / GPRS / UMTS Network Info GSM / GPRS / UMTS Network Info MM Message */	 
 CiDevGsmUmtsComnServcStateEng_MM GS47 ; /* Service State GSM / GPRS / UMTS Service State MM Message */	 
 CiDevGsmUmtsComnRadioModeEng_MM GS6E ; /* Radio Mode GSM / GPRS / UMTS Radio Mode MM Message */	 
 CiDevGsmLayer3DwnlnkMsgEng_GRR GS30 ; /* GSM / GPRS / EDGE Layer 3 Downlink Message GSM / GPRS / EDGE Layer 3 Downlink Message GRR Message */	 
 CiDevGsmLayer3UplnkMsgEng_GRR GS31 ; /* GSM / GPRS / EDGE Layer 3 Uplink Message GSM / GPRS / EDGE Layer 3 Uplink Message GRR Message */	 
 CiDevGsmRfServingCellInfoEng_GRR RF51 ; /* GSM / GPRS / EDGE RF Serving Cell Info GSM Serving Cell Info GRR Message */	 
 CiDevGsmNeighbrMeasEng_GRR RF53 ; /* GSM Neighbor Measurements GSM Neighbor Measurement GRR Message */	 
 CiDevGsmWbCellChngBginEng_RR GS57 ; /* Cell Change Begin GSM and WB Cell Change Begin RR Message */	 
 CiDevGsmWbCellChngEndEng_RR GS58 ; /* Cell Change End GSM and WB Cell Change End RR Message */	 
 CiDevGsmWbHandoverBgnEng_RR GS54 ; /* Handover Begin GSM and WB Handover Begin RR Message */	 
 CiDevGsmWbHandoverEndEng_RR GS55 ; /* Handover End GSM and WB Handover End RR Message */	 
 CiDevGsmGprsEdgeRlcStatisticsEng_RLC GS81 ; /* GPRS / EDGE RLC Statistics GPRS / EDGE RLC Statistics RLC Message */	 
 CiDevGsmSrvCellInfoEng_L1 RF52 ; /* GSM RF Dedicated Set Info GSM Serving Cell Info L1 Message */	 
 CiDevGsmGprsEdgeLinkQualityEng_L1 RF54 ; /* GPRS / EDGE Link Quality Info GSM Gprs Edge Link Quality L1 Message */	 
 CiDevWbLayer3DwnlnkMsgEng_RRC GS34 ; /* UMTS / HSPA Layer 3 Downlink Message WB UMTS / HSPA Layer 3 Downlink RRC Message */	 
 CiDevWbLayer3UplnkMsgEng_RRC GS35 ; /* UMTS / HSPA Layer 3 UPLINK Message WB UMTS / HSPA Layer 3 Uplink RRC Message */	 
 CiDevWbRrcStateEng_RRC GS67 ; /* RRC State WB RRC State RRC Message */	 
 CiDevWbCompressModeStateEng_RRC GS6F ; /* Compress Mode State WB CompressModeState RRC Message */	 
 CiDevWbActiveAndMonitoredSetInfoEng_RRC RF61 ; /* UMTS / HSPA Active and Monitored Set Info WB UMTS / HSPA Active and Monitored Set Info RRC Message */	 
 CiDevWbInterRatNeighborMeasEng_RRC RF62 ; /* UMTS / HSPA Inter RAT Neighbor Measurements WB Inter Neighbor Measurement RRC Message */	 
 CiDevWBRfInfoEng_RRC RF60 ; /* UMTS / HSPA RF Info WB RF and Serving Cell Info RRC Message */	 
 CiDevWBMultiRabStateEng_RLC GS6D ; /* Multi-RAB State WB Multi-RAB State RLC Message */	 
 CiDevWBUmtsHspaRlcStatisticsEng_RLC GS84 ; /* UMTS / HSPA RLC Statistics WB UMTS / HSPA RLC Statistics RLC Message */	 
 CiDevWBRlcResetEng_RLC GS86 ; /* RLC Reset WB RLC Reset RLC Message */	 
 CiDevWBHsupaStatisticsEng_Phy GS83 ; /* HSUPA Statistics WB HSUPA Statistics PHY Message */	 
 CiDevWBHsdpaEvolvedStatisticsEng_Phy GS88 ; /* HSDPA Evolved Statistics WB HSDPA Evolved Statistics PHY Message */	 
 CiDevWBUmtsHspaTransportChannelInfoEng_L1 RF63 ; /* UMTS / HSPA Transport Channel Info WB UMTS / HSPA Transport Channel Info L1 Message */	 
 CiDevWBUmtsHspaRadioLinkSyncStatusEng_L1 RF64 ; /* UMTS / HSPA Radio Link Sync Status WB UMTS / HSPA Radio Link Sync Status L1 Message */	 
 } CiDevCommonEngmodeInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonEngmodeInfoInd_struct 
 {	 
 CiDevCommonEngmodeInfoType type ;	 
 CiDevCommonEngmodeInfo info ;	 
 } CiDevCommonEngmodeInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonEngmodeDB_struct 
 {	 
 CiDevLteEng_RRC LT01 ; /* E-UTRA RRC Message */	 
 CiDevLteEng_NAS LT02 ; /* E-UTRA NAS Message */	 
 CiDevLteEng_MSR LT03 ; /* E-UTRA Measurement Report */	 
 CiDevLteEng_InterMsr LT04 ; /* E-UTRA Inter-RAT Measurement Report */	 
 CiDevLteEng_NeighborList LT05 ; /* E-UTRA Neighbor List */	 
 CiDevLteEng_RrcState LT06 ; /* E-UTRA RRC State */	 
 CiDevLteEng_MAC LT07 ; /* E-UTRA MAC Control State */	 
 CiDevLteEng_MAC_RACH LT08 ; /* E-UTRA MAC Random Access Attempt */	 
 CiDevLteEng_RLC LT17 ; /* E-UTRA RLC Data Transfer Report */	 
 CiDevLteEng_EPS LT10 ; /* E-UTRA EPS Bearer Context Status */	 
 CiDevLteEng_EPS_QoS LT11 ; /* E-UTRA EPS Bearer QoS */	 
 CiDevLteEng_PUSCH LT12 ; /* E-UTRA PUSCH Transmission Status */	 
 CiDevLteEng_RadioLink LT13 ; /* E-UTRA Radio Link Sync Status */	 
 } CiDevCommonEngmodeDB;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_EXT_ENGMODE_REPORTOPTION_TAG 
 {	 
 CI_DEV_EM_OPTION_TURN_OFF , /**< Engineering mode report delivery: Turn off */	 
 CI_DEV_EM_OPTION_START /**< Engineering mode report delivery: Turn On */	 
 } _CiDevExtEngModeReportOption;

typedef UINT8 CiDevExtEngModeReportOption ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetExtEngmodeRepOptReq_struct 
 {	 
 CiDevExtEngModeReportOption reportOption ; /* Start / Stop Eng Info report */	 
 UINT32 reporting [ 2 ] ;	 
 } CiDevPrimSetExtEngmodeRepOptReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetExtEngmodeRepOptCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ;	 
 } CiDevPrimSetExtEngmodeRepOptCnf;

typedef CiEmptyPrim CiDevPrimGetExtEngmodeInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetExtEngmodeInfoCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 } CiDevPrimGetExtEngmodeInfoCnf;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_PRIM {	 
 CI_DEV_PRIM_STATUS_IND = 1 , /**< \brief Indicates that the device status has changed \details The client should not begin its initialization process before receiving CI_DEV_PRIM_STATUS_IND ( CI_DEV_STATUS_READY ) . This indication cannot be disabled. */	 
 CI_DEV_PRIM_GET_MANU_ID_REQ , /**< \brief Requests the manufacturer ID \details */	 
 CI_DEV_PRIM_GET_MANU_ID_CNF , /**< \brief Confirms a request and returns the manufacturer ID \details */	 
 CI_DEV_PRIM_GET_MODEL_ID_REQ , /**< \brief Requests the model ID \details */	 
 CI_DEV_PRIM_GET_MODEL_ID_CNF , /**< \brief Confirms a request and returns the model ID \details */	 
 CI_DEV_PRIM_GET_REVISION_ID_REQ , /**< \brief Requests the revision ID \details */	 
 CI_DEV_PRIM_GET_REVISION_ID_CNF , /**< \brief Confirms a request and returns the revision ID \details */	 
 CI_DEV_PRIM_GET_SERIALNUM_ID_REQ , /**< \brief Requests the serial number ID ( IMEI ) \details */	 
 CI_DEV_PRIM_GET_SERIALNUM_ID_CNF , /**< \brief Confirms a request and returns the serial number ID \details */	 
 CI_DEV_PRIM_SET_FUNC_REQ = 10 , /**< \brief Requests to set the level of functionality in the cellular subsystem \details */	 
 CI_DEV_PRIM_SET_FUNC_CNF , /**< \brief Confirms a request and sets the level of functionality in the cellular subsystem \details */	 
 CI_DEV_PRIM_GET_FUNC_REQ , /**< \brief Requests to get the level of functionality in the cellular subsystem \details */	 
 CI_DEV_PRIM_GET_FUNC_CNF , /**< \brief Confirms a request and returns the level of functionality in the cellular subsystem \details */	 
 CI_DEV_PRIM_GET_FUNC_CAP_REQ , /**< \brief Requests to get the level of functional capability in the cellular subsystem \details */	 
 CI_DEV_PRIM_GET_FUNC_CAP_CNF , /**< \brief Confirms a request and returns the level of functional capability in the cellular subsystem \details */	 
 CI_DEV_PRIM_SET_GSM_POWER_CLASS_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_SET_GSM_POWER_CLASS_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_GET_GSM_POWER_CLASS_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_GET_GSM_POWER_CLASS_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_GET_GSM_POWER_CLASS_CAP_REQ = 20 , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_GET_GSM_POWER_CLASS_CAP_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
	 
 CI_DEV_PRIM_PM_POWER_DOWN_REQ , /**< \brief Requests to perform power down for the current device \details */	 
 CI_DEV_PRIM_PM_POWER_DOWN_CNF , /**< \brief Confirms a request and powers down the current device \details */	 
	 
 CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_REQ , /**< \brief Requests to set the option for reporting engineering mode information \details If the Periodic option is selected: \n-	 
 * - For GSM , CCI sends a periodic CI_DEV_PRIM_GSM_ENGMODE_INFO_IND indication containing the current engineering mode information. For UMTS , the following periodic messages are sent: \n	 
 * CI_DEV_PRIM_UMTS_ENGMODE_SVCCELL_INFO_IND \n	 
 * CI_DEV_PRIM_UMTS_ENGMODE_INTERFREQ_INFO_IND \n	 
 * CI_DEV_PRIM_UMTS_ENGMODE_INTRAFREQ_INFO_IND \n	 
 * CI_DEV_PRIM_UMTS_ENGMODE_INTERRAT_INFO_IND \n	 
 * The report interval is received as the parameter interval of the CiDevPrimSetEngmodeRepOptReq structure.	 
 * If the request option is selected , the application requests current engineering mode information using the CI_DEV_PRIM_GET_ENGMODE_INFO_REQ request.	 
 * The default option is on request. */	 
 CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_CNF , /**< \brief Confirms a request and sets the option for reporting engineering mode information \details */	 
 CI_DEV_PRIM_GET_ENGMODE_INFO_REQ , /**< \brief Requests current engineering mode information \details Use this request when the engineering mode report option is set to on request.	 
 * Engineering mode information is currently available for GSM as well as for UMTS. */	 
 CI_DEV_PRIM_GET_ENGMODE_INFO_CNF , /**< \brief Confirms a request and returns current engineering mode information \details Engineering mode information is currently available for GSM as well as UMTS. */	 
 CI_DEV_PRIM_ENGMODE_INFO_IND , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
	 
 CI_DEV_PRIM_GSM_ENGMODE_INFO_IND , /**< \brief Indicates current GSM engineering mode information \details */	 
 CI_DEV_PRIM_UMTS_ENGMODE_SVCCELL_INFO_IND = 30 , /**< \brief Indicates UMTS engineering mode serving cell information \details */	 
 CI_DEV_PRIM_UMTS_ENGMODE_INTRAFREQ_INFO_IND , /**< \brief Indicates UMTS engineering mode intra-frequency measurements information \details */	 
 CI_DEV_PRIM_UMTS_ENGMODE_INTERFREQ_INFO_IND , /**< \brief Indicates UMTS engineering mode inter-frequency measurements information \details */	 
 CI_DEV_PRIM_UMTS_ENGMODE_INTERRAT_INFO_IND , /**< \brief Indicates UMTS engineering mode inter-rat measurements information \details */	 
 CI_DEV_PRIM_DO_SELF_TEST_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_DO_SELF_TEST_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_DO_SELF_TEST_IND , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_SET_RFS_REQ , /**< \brief Requests to change the current reset factory settings \details */	 
 CI_DEV_PRIM_SET_RFS_CNF , /**< \brief Confirms a request and changes the current reset factory setting \details */	 
 CI_DEV_PRIM_GET_RFS_REQ , /**< \brief Requests to obtain the current reset factory settings \details */	 
 CI_DEV_PRIM_GET_RFS_CNF = 40 , /**< \brief Confirms a request and obtains the current reset factory settings \details */	 
 CI_DEV_PRIM_UMTS_ENGMODE_ACTIVE_SET_INFO_IND , /**< \brief Indicates UMTS engineering mode active set information \details */	 
 CI_DEV_PRIM_ACTIVE_PDP_CONTEXT_ENGMODE_IND , /**< \brief Indicates engineering mode active PDP context information \details */	 
 CI_DEV_PRIM_NETWORK_MONITOR_INFO_IND , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_DEV_PRIM_LP_NWUL_MSG_REQ , /**< \brief Requests the PS to deliver a location position message to the network	 
 * \details The message can contain the location results , location error , or protocol error. */	 
 CI_DEV_PRIM_LP_NWUL_MSG_CNF , /**< \brief Confirms a request and delivers a location position message to the network \details */	 
 CI_DEV_PRIM_LP_NWDL_MSG_IND , /**< \brief Indicates a request from the network to provide location position information , for example , assistance data , location request , or a combination of the two	 
 * \details */	 
 CI_DEV_PRIM_LP_RRC_STATE_IND , /**< \brief Indicates a change in the RRC state \details It should be called by ABPS whenever the RRC state changes while a positioning session is active. */	 
 CI_DEV_PRIM_LP_MEAS_TERMINATE_IND , /**< \brief Indicates that the PS terminated the current location session \details A location session is terminated when PS changes RAT or enters out of service. */	 
 CI_DEV_PRIM_LP_RESET_STORED_UE_POS_IND , /**< \brief Indicates a request from the network to reset all stored assistance data	 
 * \details This is a test I / F message ( TIM ) ; therefore , it is not sent by a real network. */	 
 /*Michal Bukai - Silent Reset support - START*/	 
 CI_DEV_PRIM_COMM_ASSERT_REQ = 50 , /**< \brief Requests the communication subsystem to assert \details There is no confirmation for this primitive. This primitive is used for testing. */	 
 /*Michal Bukai - Silent Reset support - END*/	 
 /*Michal Bukai *BAND support - START*/	 
 CI_DEV_PRIM_SET_BAND_MODE_REQ , /**< \brief Requests the PS to set band and RAT mode	 
 * \details The communication subsystem performs a SW reset after sending the confirmation for updating RAT and band.	 
 * If the requested RAT is dual mode , the communication subsystem resets to default band parameters. */	 
	 
 CI_DEV_PRIM_SET_BAND_MODE_CNF , /**< \brief Confirms a request and sets band and RAT mode parameters	 
 * \details The communication subsystem performs a SW reset after sending the confirmation for updating RAT and band.*/	 
 CI_DEV_PRIM_GET_BAND_MODE_REQ , /**< \brief Requests to read the current band and RAT mode setting */	 
 CI_DEV_PRIM_GET_BAND_MODE_CNF , /**< \brief Confirms the request and returns the current band and RAT mode setting */	 
 CI_DEV_PRIM_GET_SUPPORTED_BAND_MODE_REQ , /**< \brief Requests the supported bands and supported RAT modes */	 
 CI_DEV_PRIM_GET_SUPPORTED_BAND_MODE_CNF , /**< \brief Confirms the request and returns the supported bands and supported RAT modes */	 
	 
 /*Michal Bukai *BAND support - END*/	 
 /*Michal Bukai - IMEI support - START*/	 
 CI_DEV_PRIM_SET_SV_REQ , /**< \brief Requests to update the SV digits in IMEISV. \details The default value of the SV digits is the value set during production. */	 
 CI_DEV_PRIM_SET_SV_CNF , /**< \brief Confirms a request to set SV digits in IMEISV. \details */	 
 CI_DEV_PRIM_GET_SV_REQ , /**< \brief Requests to get the SV digits in IMEISV. \details */	 
 CI_DEV_PRIM_GET_SV_CNF = 60 , /**< \brief Confirms a request and returns the SV digits in IMEISV. \details The full IMEISV can be read using the primitive CI_DEV_PRIM_GET_SERIALNUM_ID_REQ to read IMEI and this primitive to get SV digits. */	 
 /*Michal Bukai - IMEI support - END*/	 
	 
 CI_DEV_PRIM_AP_POWER_NOTIFY_REQ ,	 
 CI_DEV_PRIM_AP_POWER_NOTIFY_CNF ,	 
	 
 CI_DEV_PRIM_SET_TD_MODE_TX_RX_REQ , /**< \brief Requests to set Tx or Rx on TD for radio testing. */	 
 CI_DEV_PRIM_SET_TD_MODE_TX_RX_CNF , /**< \brief Confirms the TD Tx / Rx mode request. */	 
 CI_DEV_PRIM_SET_TD_MODE_LOOPBACK_REQ , /**< \brief Requests to set loopback mode on TD for radio testing. */	 
 CI_DEV_PRIM_SET_TD_MODE_LOOPBACK_CNF , /**< \brief Confirms to set loopback mode on TD for radio testing. */	 
	 
 CI_DEV_PRIM_SET_GSM_MODE_TX_RX_REQ , /**< \brief Requests to set Tx / Rx on GSM for radio testing. */	 
 CI_DEV_PRIM_SET_GSM_MODE_TX_RX_CNF , /**< \brief Confirms the GSM Tx / Rx mode request. */	 
 CI_DEV_PRIM_SET_GSM_CONTROL_INTERFACE_REQ , /**< \brief Requests to set GSM for control interface. */	 
 CI_DEV_PRIM_SET_GSM_CONTROL_INTERFACE_CNF = 70 , /**< \brief Confirms to set option on GSM for control interface testing. */	 
 CI_DEV_PRIM_ENABLE_HSDPA_REQ ,	 
 CI_DEV_PRIM_ENABLE_HSDPA_CNF ,	 
 CI_DEV_PRIM_GET_HSDPA_STATUS_REQ ,	 
 CI_DEV_PRIM_GET_HSDPA_STATUS_CNF ,	 
	 
 CI_DEV_PRIM_READ_RF_TEMPERATURE_REQ , /**< \brief Requests to read temperature from RF chip. */	 
 CI_DEV_PRIM_READ_RF_TEMPERATURE_CNF , /**< \brief Confirms to read temperature from RF chip. */	 
	 
 /*Mason CMCC Smart Network Monitor support - START*/	 
 /* AT^DCTS */	 
 CI_DEV_PRIM_SET_NETWORK_MONITOR_OPTION_REQ ,	 
 CI_DEV_PRIM_SET_NETWORK_MONITOR_OPTION_CNF ,	 
 CI_DEV_PRIM_GET_NETWORK_MONITOR_OPTION_REQ ,	 
 CI_DEV_PRIM_GET_NETWORK_MONITOR_OPTION_CNF = 80 ,	 
	 
 /* AT^DEELS */	 
 CI_DEV_PRIM_SET_PROTOCOL_STATUS_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_PROTOCOL_STATUS_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_PROTOCOL_STATUS_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_PROTOCOL_STATUS_CONFIG_CNF ,	 
 CI_DEV_PRIM_PROTOCOL_STATUS_CHANGED_IND ,	 
	 
 /* AT^DEVEI */	 
 CI_DEV_PRIM_SET_EVENT_IND_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_EVENT_IND_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_EVENT_IND_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_EVENT_IND_CONFIG_CNF ,	 
 CI_DEV_PRIM_EVENT_REPORT_IND = 90 ,	 
	 
 /* AT^DNPR */	 
 CI_DEV_PRIM_SET_WIRELESS_PARAM_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_WIRELESS_PARAM_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_WIRELESS_PARAM_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_WIRELESS_PARAM_CONFIG_CNF ,	 
 CI_DEV_PRIM_WIRELESS_PARAM_IND ,	 
	 
 /* AT^DUSR */	 
 CI_DEV_PRIM_SET_SIGNALING_REPORT_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_SIGNALING_REPORT_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_SIGNALING_REPORT_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_SIGNALING_REPORT_CONFIG_CNF ,	 
 CI_DEV_PRIM_SIGNALING_REPORT_IND = 100 ,	 
 /*Mason CMCC Smart Network Monitor support -- END*/	 
	 
 /*Alan DIP Channel support -- START*/	 
 CI_DEV_PRIM_DIP_CHANNEL_CHANGE_IND ,	 
 /*Alan DIP Channel support -- END*/	 
	 
 /*Add by Alan for LteEngModeInfoInd 12192012 -- Start*/	 
 CI_DEV_PRIM_LTE_ENGMODE_INFO_IND ,	 
 /*Add by Alan for LteEngModeInfoInd 12192012 -- End*/	 
	 
 CI_DEV_PRIM_CURRENT_AMR_CODEC_IND ,	 
	 
 /*Add by Alan for Power BackOff 4082013 , begin*/	 
 CI_DEV_PRIM_SET_POWER_BACK_OFF_REQ , /**< \brief Requests to set feature calibration of Grip Sensor TX power. */	 
 CI_DEV_PRIM_SET_POWER_BACK_OFF_CNF , /**< \brief Confirms to set feature calibration of Grip Sensor TX power. */	 
 /*Add by Alan for Power BackOff 4082013 , end*/	 
	 
 CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_REQ , /**< \brief Requests the internal revision ID and build time \details */	 
 CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_CNF , /**< \brief Confirms a request and returns the internal revision ID and build time \details */	 
	 
 CI_DEV_PRIM_SET_COM_CONFIG_REQ , /**< \brief Set a com related configuration.	 
 * \details Sending this CI overrides the value configured through the com config NVM file on the com side. It does not update the com config NVM file. */	 
 CI_DEV_PRIM_SET_COM_CONFIG_CNF , /**< \brief Confirms the request to set a com related configuration \details */	 
 CI_DEV_PRIM_GET_COM_CONFIG_REQ = 110 , /**< \brief Request to get a com configuration token \details */	 
 CI_DEV_PRIM_GET_COM_CONFIG_CNF , /**< \brief Confirmation and get com config token \details */	 
	 
 /*Add by Alan for WCDMA Radio test 5292013 , begin*/	 
 CI_DEV_PRIM_SET_WCDMA_MODE_TX_RX_REQ , /**< \brief Requests to set Tx or Rx on WCDMA for radio testing. */	 
 CI_DEV_PRIM_SET_WCDMA_MODE_TX_RX_CNF , /**< \brief Confirms the WCDMA Tx / Rx mode request. */	 
	 
 /*Michal Bukai - Security Configuration - Samsung - START*/	 
 CI_DEV_PRIM_SET_SECURITY_PARAMS_REQ , /**< \brief Requests to enable / disable ciphering and integrity protection. \details The setting will affect	 
 * the ciphering and integrity UE capabilities reported to the NW .	 
 * In case ciphering or integrity protection is enabled , the reported capabilities will be derived from NVM setting.	 
 * In case ciphering or integrity protection is disabled , all algorithms will be reported as unsupported ,	 
 * This command will not affect NVM setting.*/	 
 CI_DEV_PRIM_SET_SECURITY_PARAMS_CNF , /**< \brief Confirms a request to enable / disable ciphering and integrity protection \details */	 
 CI_DEV_PRIM_GET_SECURITY_PARAMS_REQ , /**< \brief Requests to read ciphering and integrity protection status \details */	 
 CI_DEV_PRIM_GET_SECURITY_PARAMS_CNF , /**< \brief Confirms the request and returns the ciphering and integrity protection status \details */	 
 /*Michal Bukai - Security Configuration - Samsung - END*/	 
 CI_DEV_PRIM_RESET_REQUEST_IND , /**< \brief Indication to request the apps to perform com reset */	 
 CI_DEV_PRIM_SET_USER_TEST_REPORT_OPTION_REQ , /**< \brief Requests to set the option for reporting user testing information */	 
 CI_DEV_PRIM_SET_USER_TEST_REPORT_OPTION_CNF = 120 , /**< \brief Confirms a request for reporting user testing information */	 
 CI_DEV_PRIM_USER_TEST_VALUABLE_EVENT_REPORT_IND , /**< \brief Reports a user testing valuable event */	 
 CI_DEV_PRIM_SET_PARK_MODE_REQ , /**< \brief Request to set the modem to enter or exit park mode */	 
 CI_DEV_PRIM_SET_PARK_MODE_CNF , /**< \brief Confirm the request to set the park mode. */	 
 CI_DEV_PRIM_GET_PARK_MODE_REQ , /**< \brief Request to get current status of park mode. */	 
 CI_DEV_PRIM_GET_PARK_MODE_CNF , /**< \brief Confirmation for the request to get the current park mode setting */	 
	 
 CI_DEV_PRIM_LP_ECID_MEAS_REQ ,	 
 CI_DEV_PRIM_LP_ECID_MEAS_CNF ,	 
	 
 CI_DEV_PRIM_SET_LP_UE_AREA_INFO_IND_REQ ,	 
 CI_DEV_PRIM_SET_LP_UE_AREA_INFO_IND_CNF ,	 
 CI_DEV_PRIM_LP_UE_AREA_INFO_IND = 130 ,	 
 CI_DEV_PRIM_SET_IMS_MEDIA_REQ , /**< \brief Request to set IMS Media configuration parameters */	 
 CI_DEV_PRIM_SET_IMS_MEDIA_CNF , /**< \brief Confirmation to the setting of the IMS media */	 
 CI_DEV_PRIM_IMS_MEDIA_IND , /**< \brief Indication from the IMS media on the com side */	 
	 
 /* Lilei VZWRSRP&VZWRSRQ support -- Start */	 
 CI_DEV_PRIM_GET_LTE_MEAS_REQ , /**< \brief Request to get lte rsrp&rsrq measurement info. */	 
 CI_DEV_PRIM_GET_LTE_MEAS_CNF , /**< \brief Confirm the request to get lte rsrp&rsrq measurement info. */	 
 /* Lilei VZWRSRP&VZWRSRQ support -- End */	 
	 
 /* Lilei LTE&WIFI coexist support 20131022 -- Start */	 
 CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_REQ ,	 
 CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_CNF ,	 
 CI_DEV_PRIM_GET_LTE_COEX_INFO_REQ ,	 
 CI_DEV_PRIM_GET_LTE_COEX_INFO_CNF ,	 
 CI_DEV_PRIM_LTE_COEX_INFO_IND = 140 ,	 
 /* Lilei LTE&WIFI coexist support 20131022 -- End */	 
	 
 /*Added by Lilei for neighbor cell info report on 1082014 , begin*/	 
 // #if defined ( SS_IPC_SUPPORT )	 
 CI_DEV_PRIM_SET_ENGMODE_NCELL_REPORT_OPTION_REQ , /**< \brief Requests to enable / disable the report of neighbor cell information \details If it ' s enabled , \n	 
 * CCI sends a periodic CI_DEV_PRIM_ENGMODE_NCELL_INFO_IND indication containing the current neighbor cell information. \n	 
 * The report interval is received as the parameter interval of the CiDevPrimSetEngmodeNcellRepOptReq structure , or set a defualt value. */	 
 CI_DEV_PRIM_SET_ENGMODE_NCELL_REPORT_OPTION_CNF , /**< \brief Confirms a request of enable / disable the report of neighbor cell information \details */	 
 CI_DEV_PRIM_GET_ENGMODE_NCELL_INFO_REQ , /**< \brief Requests current neighbor cell information \details */	 
 CI_DEV_PRIM_GET_ENGMODE_NCELL_INFO_CNF , /**< \brief Confirms a request and returns current neighbor cell information \details */	 
 CI_DEV_PRIM_ENGMODE_NCELL_INFO_IND , /**< \brief Indicates current neighbor cell information \details */	 
 // #endif	 
 /*Added by Lilei for neighbor cell info report on 1082014 , end*/	 
	 
 /*Added by Lilei for LTE Radio test on 1232014 , begin*/	 
 CI_DEV_PRIM_SET_LTE_MODE_TX_RX_REQ , /**< \brief Requests to set Tx or Rx on LTE for radio testing. */	 
 CI_DEV_PRIM_SET_LTE_MODE_TX_RX_CNF , /**< \brief Confirms the LTE Tx / Rx mode request. */	 
 /*Added by Lilei for LTE Radio test on 1232014 , end*/	 
	 
 /* Merged from UMTS7_Rel by Lilei 2182014 , begin */	 
 /*Add by Alan for L2RandomFillBitsEnabled on 2082014 , CQ54160 , begin*/	 
 CI_DEV_PRIM_SET_L2_RAND_FILL_ENABLED_REQ , /**< \brief Requests to set L2RandomFillBitsEnabled. */	 
 CI_DEV_PRIM_SET_L2_RAND_FILL_ENABLED_CNF , /**< \brief Confirms to set L2RandomFillBitsEnabled request. */	 
 CI_DEV_PRIM_GET_L2_RAND_FILL_ENABLED_REQ = 150 , /**< \brief Requests to get L2RandomFillBitsEnabled. */	 
 CI_DEV_PRIM_GET_L2_RAND_FILL_ENABLED_CNF , /**< \brief Confirms to get L2RandomFillBitsEnabled request. */	 
 /*Add by Alan for L2RandomFillBitsEnabled on 2082014 , CQ54160 , end*/	 
	 
 /*Add by Alan for reporting T323 on 2082014 , CQ54159 , begin*/	 
 CI_DEV_PRIM_T323_IND ,	 
 /*Add by Alan for reporting T323 on 2082014 , CQ54159 , end*/	 
 /* Merged from UMTS7_Rel by Lilei 2182014 , end */	 
	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 CI_DEV_PRIM_LTE_ENGMODE_SVCCELL_INFO_IND , /**< \brief Indicates LTE engineering mode serving cell information \details */	 
 CI_DEV_PRIM_LTE_ENGMODE_INTRAFREQ_INFO_IND , /**< \brief Indicates LTE engineering mode intra-frequency measurements information \details */	 
 CI_DEV_PRIM_LTE_ENGMODE_INTERFREQ_INFO_IND , /**< \brief Indicates LTE engineering mode inter-frequency measurements information \details */	 
 CI_DEV_PRIM_LTE_ENGMODE_INTERRAT_INFO_IND , /**< \brief Indicates LTE engineering mode inter-rat measurements information \details */	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
	 
 /*Add by Alan for MCC , MNC and CC on 3102014 , CQ54159 , begin*/	 
 CI_DEV_PRIM_SET_MCC_MNC_CC_REQ , /**< \brief Requests to set MCC_MNC_CC. */	 
 CI_DEV_PRIM_SET_MCC_MNC_CC_CNF , /**< \brief Confirms to set MCC_MNC_CC request. */	 
 CI_DEV_PRIM_GET_MCC_MNC_CC_REQ , /**< \brief Requests to get MCC_MNC_CC. */	 
 CI_DEV_PRIM_GET_MCC_MNC_CC_CNF = 160 , /**< \brief Confirms to get MCC_MNC_CC request. */	 
 /*Add by Alan for MCC , MNC and CC on 3102014 , CQ54159 , end*/	 
	 
 /*Added by Lilei for AT*L1DEBUG CQ60995 on 5162014 , begin*/	 
 CI_DEV_PRIM_SET_L1DEBUG_REQ , /**< \brief Requests to set L1 debug data. */	 
 CI_DEV_PRIM_SET_L1DEBUG_CNF , /**< \brief Confirms to set L1 debug data. */	 
 CI_DEV_PRIM_L1DEBUG_INFO_IND , /**< \brief Indicates L1 debug info. */	 
 /*Added by Lilei for AT*L1DEBUG CQ60995 on 5162014 , end*/	 
	 
 /*Added by Lilei for LTE positioning support , begin*/	 
 CI_DEV_PRIM_LP_OTDOA_MEAS_REQ ,	 
 CI_DEV_PRIM_LP_OTDOA_MEAS_CNF ,	 
 CI_DEV_PRIM_LP_OTDOA_MEAS_IND ,	 
 CI_DEV_PRIM_LP_OTDOA_MEAS_ABORT_REQ ,	 
 CI_DEV_PRIM_LP_OTDOA_MEAS_ABORT_CNF ,	 
 CI_DEV_PRIM_RETRIEVE_LOCATION_IND ,	 
 CI_DEV_PRIM_RETRIEVE_LOCATION_RSP = 170 ,	 
 /*Added by Lilei for LTE positioning support , end*/	 
	 
 /* Added by lalon CIQ Eng mode begin */	 
 CI_DEV_PRIM_COMMON_ENGMODE_INFO_IND ,	 
 CI_DEV_PRIM_SET_EXT_ENGMODE_REPORT_OPTION_REQ ,	 
 CI_DEV_PRIM_SET_EXT_ENGMODE_REPORT_OPTION_CNF ,	 
 CI_DEV_PRIM_GET_EXT_ENGMODE_REPORT_OPTION_REQ ,	 
 CI_DEV_PRIM_GET_EXT_ENGMODE_REPORT_OPTION_CNF ,	 
 /* Added by lalon CIQ Eng mode end */	 
 /*Added by arthurr for FRAT feature begin*/	 
 CI_DEV_PRIM_SET_IGNITION_STATE_REQ ,	 
 CI_DEV_PRIM_SET_IGNITION_STATE_CNF ,	 
 CI_DEV_PRIM_GET_IGNITION_STATE_REQ ,	 
 CI_DEV_PRIM_GET_IGNITION_STATE_CNF ,	 
 /*Added by arthurr for FRAT feature end*/	 
	 
	 
 /*Lilei , CQ00079390 , 20141217 , begin*/	 
 CI_DEV_PRIM_SET_IMLCONFIG_REQ = 180 ,	 
 CI_DEV_PRIM_SET_IMLCONFIG_CNF ,	 
 CI_DEV_PRIM_GET_IMLCONFIG_REQ ,	 
 CI_DEV_PRIM_GET_IMLCONFIG_CNF ,	 
 /*Lilei , CQ00079390 , 20141217 , end*/	 
	 
 /*Lilei , CQ00080629 , 20150104 , begin*/	 
 CI_DEV_PRIM_RB_TEST_MODE_IND , /**< \brief Indicates RB Test Loopback Mode status. */	 
 /*Lilei , CQ00080629 , 20150104 , end*/	 
	 
 /*Lilei , CQ00085118 , 20150202 , begin*/	 
 CI_DEV_PRIM_SET_LTE_BAND_ORDER_REQ , /**< \brief Requests to set LTE band scan order. */	 
 CI_DEV_PRIM_SET_LTE_BAND_ORDER_CNF , /**< \brief Confirms to set LTE band scan order. */	 
 CI_DEV_PRIM_GET_LTE_BAND_ORDER_REQ , /**< \brief Requests to get LTE band scan order. */	 
 CI_DEV_PRIM_GET_LTE_BAND_ORDER_CNF , /**< \brief Confirms to get LTE band scan order. */	 
 /*Lilei , CQ00085118 , 20150202 , end*/	 
	 
	 
 /*Lilei , CQ00087682 , 20150304 , begin*/	 
 CI_DEV_PRIM_SET_SALES_CODE_REQ ,	 
 CI_DEV_PRIM_SET_SALES_CODE_CNF = 190 ,	 
 CI_DEV_PRIM_GET_SALES_CODE_REQ ,	 
 CI_DEV_PRIM_GET_SALES_CODE_CNF ,	 
 CI_DEV_PRIM_SET_OPER_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_OPER_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_OPER_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_OPER_CONFIG_CNF ,	 
 /*Lilei , CQ00087682 , 20150304 , end*/	 
 CI_DEV_PRIM_MRD_CONFIG_REQ , // don ' t distinguish read / write / del operation , just transfer to platform	 
 CI_DEV_PRIM_MRD_CONFIG_CNF , // don ' t distinguish read / write / del operation , just transfer to platform	 
 CI_DEV_PRIM_GET_STATUS_REQ , // added by taow 20170524	 
 CI_DEV_PRIM_GET_STATUS_CNF = 200 ,	 
	 
 /*Lilei , CQ00108730 , 20171225 , begin*/	 
 CI_DEV_PRIM_FACTORY_RESET_REQ ,	 
 CI_DEV_PRIM_FACTORY_RESET_CNF ,	 
 /*Lilei , CQ00108730 , 20171225 , end*/	 
	 
 /*Lilei , CQ00112021 , 20180903 , begin*/	 
 CI_DEV_PRIM_GET_IMS_UL_STATISTIC_REQ ,	 
 CI_DEV_PRIM_GET_IMS_UL_STATISTIC_CNF ,	 
 /*Lilei , CQ00112021 , 20180903 , end*/	 
	 
 /*add by taow 20180525 CQ00110536 begin*/	 
 CI_DEV_PRIM_SET_MEDATA_RESERVER_REQ , /**< \brief Requests to set MEDATA COMM RESERVER . */	 
 CI_DEV_PRIM_SET_MEDATA_RESERVER_CNF , /**< \brief Requests to set MEDATA COMM RESERVER . */	 
 CI_DEV_PRIM_GET_MEDATA_RESERVER_REQ , /**< \brief Requests to get MEDATA COMM RESERVER . */	 
 CI_DEV_PRIM_GET_MEDATA_RESERVER_CNF , /**< \brief Requests to get MEDATA COMM RESERVER . */	 
 /*add by taow 20180525 CQ00110536 end*/	 
	 
 /*Lilei , CQ00115548 , 20190719 , begin*/	 
 CI_DEV_PRIM_SET_CELL_SELECT_CFG_REQ , /**< \brief Requests to set cell select config. */	 
 CI_DEV_PRIM_SET_CELL_SELECT_CFG_CNF = 210 , /**< \brief Requests to set cell selectr config. */	 
 CI_DEV_PRIM_GET_CELL_SELECT_CFG_REQ , /**< \brief Requests to get cell select config. */	 
 CI_DEV_PRIM_GET_CELL_SELECT_CFG_CNF , /**< \brief Requests to get cell select config. */	 
 /*Lilei , CQ00115548 , 20190719 , end*/	 
	 
 CI_DEV_PRIM_COMMON_REPORT_IND , /**< \brief Indicates common reports. */	 
 /*20190819 CQ00116678 add by taow begin*/	 
 CI_DEV_PRIM_SET_ROAMING_FORBIDEN_PLMN_REQ ,	 
 CI_DEV_PRIM_SET_ROAMING_FORBIDEN_PLMN_CNF ,	 
 CI_DEV_PRIM_GET_ROAMING_FORBIDEN_PLMN_REQ ,	 
 CI_DEV_PRIM_GET_ROAMING_FORBIDEN_PLMN_CNF ,	 
 CI_DEV_PRIM_SET_BLACK_CELL_REQ ,	 
 CI_DEV_PRIM_SET_BLACK_CELL_CNF ,	 
 CI_DEV_PRIM_GET_BLACK_CELL_REQ = 220 ,	 
 CI_DEV_PRIM_GET_BLACK_CELL_CNF ,	 
 /*20190819 CQ00116678 add by taow end*/	 
	 
 /*Lilei , CQ00113795 , 20190215 , begin*/	 
 CI_DEV_PRIM_SET_FEATURE_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_FEATURE_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_FEATURE_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_FEATURE_CONFIG_CNF ,	 
 CI_DEV_PRIM_SET_ROAM_CONFIG_REQ ,	 
 CI_DEV_PRIM_SET_ROAM_CONFIG_CNF ,	 
 CI_DEV_PRIM_GET_ROAM_CONFIG_REQ ,	 
 CI_DEV_PRIM_GET_ROAM_CONFIG_CNF ,	 
 /*Lilei , CQ00113795 , 20190215 , end*/	 
	 
 /*Lilei , CQ00119368 , 20200331 , begin*/	 
 CI_DEV_PRIM_CELLS_INFO_IND = 230 , /**< \brief Report cells info. */	 
 /*Lilei , CQ00119368 , 20200331 , end*/	 
	 
 /* ============== Added for REL13 ====================================================*/	 
 CI_DEV_PRIM_CONFIG_HW_PSM_PROFILE_REQ , /**< \brief Requests to set hardware PSM configuration . */	 
 CI_DEV_PRIM_CONFIG_HW_PSM_PROFILE_CNF , /**< \brief Confirms to set hardware PSM configuration . */	 
 CI_DEV_PRIM_GET_HW_PSM_PROFILE_REQ , /**< \brief Requests to get hardware PSM configuration . */	 
 CI_DEV_PRIM_GET_HW_PSM_PROFILE_CNF , /**< \brief Confirms to get hardware PSM configuration . */	 
	 
 /*Lilei , CQ00126499 , 20201207 , begin*/	 
 CI_DEV_PRIM_SET_DRX_DYNAMIC_ADJUST_REQ , /**< \brief Requests to set DRX dynamic adjust params. */	 
 CI_DEV_PRIM_SET_DRX_DYNAMIC_ADJUST_CNF , /**< \brief Confirms to set DRX dynamic adjust params. */	 
 /*Lilei , CQ00126499 , 20201207 , end*/	 
	 
 /*Lilei , CQ00127745 , 20210119 , begin*/	 
 CI_DEV_PRIM_SET_ANTENNA_TUNER_PARAM_REQ , /**< \brief Requests to set antenna tuner param. */	 
 CI_DEV_PRIM_SET_ANTENNA_TUNER_PARAM_CNF , /**< \brief Confirms to set antenna tuner param. */	 
 /*Lilei , CQ00127745 , 20210119 , end*/	 
	 
 /*Lilei , CQ00131521 , 20210706 , begin*/	 
 CI_DEV_PRIM_PAGING_FAILURE_IND , /**< \brief Report paging failure ind. */	 
 /*Lilei , CQ00131521 , 20210706 , end*/	 
 /* add by taow 20211214 CQ00134561 begin*/	 
 CI_DEV_PRIM_SET_COMMON_FEATURE_REQ = 240 ,	 
 CI_DEV_PRIM_SET_COMMON_FEATURE_CNF ,	 
	 
 CI_DEV_PRIM_GET_COMMON_FEATURE_REQ ,	 
 CI_DEV_PRIM_GET_COMMON_FEATURE_CNF ,	 
 /* add by taow 20211214 CQ00134561 end*/	 
 /*add by lilei 20220119 CQ00135497 begin */	 
 CI_DEV_PRIM_SET_NST_TX_RX_REQ , /**< \brief Requests to set NST Tx or Rx for radio testing. */	 
 CI_DEV_PRIM_SET_NST_TX_RX_CNF , /**< \brief Confirms the NST Tx / Rx mode request. */	 
 /*add by lilei 20220119 CQ00135497 end */	 
	 
 CI_DEV_PRIM_SET_SIM_SLOT_REQ ,	 
 CI_DEV_PRIM_SET_SIM_SLOT_CNF ,	 
 CI_DEV_PRIM_GET_SIM_SLOT_REQ ,	 
 CI_DEV_PRIM_GET_SIM_SLOT_CNF ,	 
	 
 /* ADD NEW COMMON PRIMITIVES HERE , BEFORE ' CI_DEV_PRIM_LAST_COMMON_PRIM ' */	 
 /* END OF COMMON PRIMITIVES LIST */	 
 CI_DEV_PRIM_LAST_COMMON_PRIM	 
	 
 /* The customer specific extension primitives must be added starting from	 
 * CI_DEV_PRIM_firstCustPrim = CI_DEV_PRIM_LAST_COMMON_PRIM as the first identifier.	 
 * The actual primitive names and IDs are defined in the associated	 
 * ' ci_dev_cust_xxx.h ' file.	 
 */	 
	 
 /* DO NOT ADD ANY MORE PRIMITIVES HERE */	 
	 
 } _CiDevPrim;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_AMR_CODEC_TYPE_TAG {	 
 CI_DEV_CODEC_WB_AMR = 0 ,	 
 CI_DEV_CODEC_NB_AMR = 1 ,	 
 CI_DEV_CODEC_OTHERS = 2 ,	 
	 
 CI_DEV_NUM_OF_CODEC_TYPES	 
 } _CiDevAmrCodecType;

typedef UINT8 CiDevAmrCodecType ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_CURRENT_AMR_CODEC_IND " > */ 
 typedef struct CiDevPrimCurrentAmrCodecInd_struct 
 {	 
 CiDevAmrCodecType codecType ;	 
 UINT32 speechCodecRate ; // added by taow 20141106	 
 } CiDevPrimCurrentAmrCodecInd;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_CELL_PRIORITY_TYPE_TAG {	 
 CI_DEV_CELL_PRIORITY_NORMAL =0 , /**< Normal cell priority */	 
 CI_DEV_CELL_PRIORITY_BARRED , /**< Barred cell priority */	 
 CI_DEV_CELL_PRIORITY_LOW , /**< Low cell priority */	 
 CI_DEV_NUM_CELL_PRIORITY	 
 } _CiDevCellPrioriytType;

typedef UINT8 CiDevCellPrioriytType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevHoppingGroup_struct 
 {	 
 UINT8 length ; /**< Length of the arfcn list. Range is 0 -64.0 - means list is not available */	 
 UINT16 Arfcns [ 64 ] ; /**< Absolute radio frequency channel number */	 
 } CiDevHoppingGroup;

//ICAT EXPORTED ENUM 
 typedef enum CIDEVSTATUS_TAG {	 
 CI_DEV_STATUS_READY = 0 , /**< Device is ready to handle requests */	 
 CI_DEV_STATUS_UNAVAILABLE , /**< Device cannot handle requests */	 
 CI_DEV_STATUS_UNKNOWN , /**< Device status unknown */	 
 CI_DEV_STATUS_RINGING , /**< Device is ringing */	 
 CI_DEV_STATUS_CALLINPROG , /**< Device has a call in progress */	 
 CI_DEV_STATUS_ASLEEP , /**< Device is in a low functionality state */	 
 CI_DEV_STATUS_CALLACTIVE , /**< Device has a call in active */	 
	 
 CI_DEV_NUM_STATUSES	 
 } _CiDevStatus;

typedef UINT8 CiDevStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CIRCDEV_TAG {	 
 CIRC_DEV_SUCCESS = 0 , /**< Request completed successfully */	 
 CIRC_DEV_FAILURE , /**< Phone failure */	 
 CIRC_DEV_NO_CONNECTION , /**< No connection to phone */	 
 CIRC_DEV_UNKNOWN , /**< Unknown error */	 
 CIRC_DEV_INVALID_PARAMETER , /**< Generic error - the requested service primitive has invalid parameters */	 
 CIRC_DEV_INVALID_REQ , /**< Generic error - the requested service primitive can not be handled at current state */	 
 CIRC_DEV_SIM_NOT_READY , /**< Generic error - the requested service primitive fails because SIM is not ready */	 
 CIRC_DEV_ACCESS_DENIED , /**< Generic error - the requested service primitive fails because access is denied */	 
	 
	 
	 
	 
 CIRC_DEV_BUSY_WITH_OTHER_PROCESS , /**< Generic error - the requested service primitive fails because other process is ongoing */	 
	 
 CIRC_DEV_NUM_RESCODES	 
 } _CiDevRc;

typedef UINT16 CiDevRc ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVFUNC_TAG {	 
 CI_DEV_FUNC_MIN = 0 , /**< Minimum functionality ( lowest power level ) */	 
 CI_DEV_FUNC_FULL , /**< Full functionality ( highest power level ) */	 
 CI_DEV_FUNC_DISABLE_TX_RF , /**< Disable phone transmit RF circuits only */	 
 CI_DEV_FUNC_DISABLE_RX_RF , /**< Disable phone receive RF circuits only */	 
 CI_DEV_FUNC_DISABLE_BOTH_RF , /**< Disable both phone transmit and receive RF circuits */	 
 CI_DEV_FUNC_UPDATE_NVM_MIN , /**< Update NVM file with minimum functionality mode */	 
 CI_DEV_FUNC_UPDATE_NVM_FULL , /**< Update NVM file with full functionality mode */	 
 CI_DEV_FUNC_MIN_NO_IMSI_DETACH , /**< minimum functionality but without IMSI detach */	 
 CI_DEV_FUNC_DISABLE_SIM , /**< disable SIM */	 
 CI_DEV_FUNC_UPDATE_NVM_DISABLE_BOTH_RF = 9 , /**< Update NVM file with both transmit and receive RF circuits disable mode */	 
 CI_DEV_FUNC_FULL_SECONDARY_RX_OFF = 10 , /**< full functionality for primary RF , secondary RX is OFF */	 
	 
 /*Lilei , CQ00085158 , 20150128 , begin*/	 
 CI_DEV_FUNC_INIT_RF_3G , /**< Init 3 G RF setting. Only used for 3 G RF test */	 
 CI_DEV_FUNC_PRI_ONLY_RF_3G , /**< Enable only primary RF ( Pri TX + Pri RX ) . Only used for 3 G RF test */	 
 CI_DEV_FUNC_SEC_ONLY_RF_3G , /**< Enable only secondary RF ( Pri TX + Sec RX ) . Only used for 3 G RF test */	 
 CI_DEV_FUNC_PRI_SEC_RF_3G , /**< Enable both primary and secondary RF ( Pri TX + Pri RX + Sec RX ) . Only used for 3 G RF test */	 
 /*Lilei , CQ00085158 , 20150128 , end*/	 
	 
 CI_DEV_NUM_FUNCS	 
 } _CiDevFunc;

typedef UINT8 CiDevFunc ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVCOMMFEATURECONFIG_TAG {	 
 CI_DEV_CSD = 1 , /**< CSD is supported */	 
 CI_DEV_FAX , /**< FAX is supported */	 
 CI_DEV_PRODUCTION , /**< Production Mode is in use*/	 
 CI_DEV_CONVENTIONAL_GPS , /**< Conventional GPS is supported */	 
 CI_DEV_MS_BASED_GPS , /**< Ms-Based A-GPS is supported */	 
 CI_DEV_MS_ASSISTED_GPS , /**< Ms-Assisted A-GPS is supported */	 
	 
 CI_DEV_NUM_COMM_FEATURE_CONFIG	 
 } _CommFeatureConfig;

//ICAT EXPORTED ENUM 
 typedef enum CIDEVBAND_TAG {	 
 CI_DEV_BAND_GSM_900 = 0 , /**< GSM_900 band */	 
 CI_DEV_BAND_GSM_1800 , /**< GSM_1800 band */	 
 CI_DEV_BAND_GSM_1900 , /**< GSM_1900 band */	 
 CI_DEV_BAND_GSM_400 , /**< GSM_400 band */	 
	 
 CI_DEV_NUM_BANDS	 
 } _CiDevBand;

typedef UINT8 CiDevBand ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVPWCLS_TAG {	 
 CI_DEV_PWCLS_DEFAULT = 0 , /**< Default power class */	 
 CI_DEV_PWCLS_1 , /**< Power class 1 */	 
 CI_DEV_PWCLS_2 , /**< Power class 2 */	 
 CI_DEV_PWCLS_3 , /**< Power class 3 */	 
 CI_DEV_PWCLS_4 , /**< Power class 4 */	 
 CI_DEV_PWCLS_5 , /**< Power class 5 */	 
	 
 CI_DEV_NUM_PWCLSES	 
 } _CiDevPwCls;

typedef UINT8 CiDevPwCls ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_REPORTOPTION_TAG 
 {	 
 CI_DEV_EM_OPTION_NONE = 0 , /**< Engineering mode report delivery: Turn off */	 
 CI_DEV_EM_OPTION_REQUEST , /**< Engineering mode report delivery: On request */	 
 CI_DEV_EM_OPTION_PERIODIC , /**< Engineering mode report delivery: Periodic */	 
 /*Lilei , CQ00091516 , 20150423 , begin*/	 
 CI_DEV_EM_OPTION_INTERNAL_CALL_END , /**< Engineering mode opened for internal purpose: call end statistic */	 
 /*Lilei , CQ00091516 , 20150423 , end*/	 
 CI_DEV_NUM_EM_REPORT_OPTIONS	 
 } _CiDevEngModeReportOption;

typedef UINT8 CiDevEngModeReportOption ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_STATE_TAG 
 {	 
 CI_DEV_EM_GSM_IDLE_STATE = 0 , /**< Mode is GSM in idle */	 
 CI_DEV_EM_GSM_DEDICATED_STATE , /**< Mode is GSM in dedicated */	 
 CI_DEV_EM_GPRS_EGPRS_PTM_STATE , /**< Mode is GSM and at least one PDP context is activated*/	 
 CI_DEV_EM_INVALID_STATE ,	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_EM_STATES	 
 } _CiDevEngModeState;

typedef UINT8 CiDevEngModeState ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_NETWORK_TAG 
 {	 
 CI_DEV_EM_NETWORK_GSM = 0 , /**< GSM network */	 
 CI_DEV_EM_NETWORK_UMTS , /**< UMTS network */	 
 CI_DEV_EM_NETWORK_LTE , /**< LTE Network */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_EM_NETWORKS	 
 } _CiDevEngModeNetwork;

typedef UINT8 CiDevEngModeNetwork ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_UERRC_STATE_TAG 
 {	 
 CI_DEV_EM_UERRC_DEACTIVATED = 0 , /**< ( UE ) RRC state DEACTIVATED RRC state */	 
 CI_DEV_EM_UERRC_SUSPENDED , /**< ( UE ) RRC state SUSPENDED RRC state */	 
 CI_DEV_EM_UERRC_IDLE , /**< ( UE ) RRC state IDLE RRC state */	 
 CI_DEV_EM_UERRC_CONN_URA_PCH , /**< ( UE ) RRC state CONN_URA_PCH RRC state */	 
 CI_DEV_EM_UERRC_CONN_CELL_PCH , /**< ( UE ) RRC state CONN_CELL_PCH RRC state */	 
 CI_DEV_EM_UERRC_CONN_CELL_FACH , /**< ( UE ) RRC state DEACTIVATED RRC state */	 
 CI_DEV_EM_UERRC_CONN_CELL_DCH , /**< ( UE ) RRC state CONN_CELL_FACH RRC state */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_EM_UERRC_STATES	 
 } _CiDevEngModeUeRrcState;

typedef UINT8 CiDevEngModeUeRrcState ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_NETWORKMONITOR_MODE_TAG 
 {	 
 CI_DEV_NM_IDLE_MODE = 0 , /**< Current GSM mode - idle */	 
 CI_DEV_NM_DEDICATED_MODE , /**< Current GSM mode - dedicated */	 
 CI_DEV_NM_GPRS_MODE , /**< Current GSM mode - during GPRS */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_NM_MODES	 
 } _CiDevNetworkMonitorMode;

typedef UINT8 CiDevNetworkMonitorMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_BEPCVMEAN_STATUS_TAG {	 
 CI_DEV_BEP_NONE =0 ,	 
 CI_DEV_BEP_GMSK ,	 
 CI_DEV_BEP_EIGHT_PSK ,	 
 CI_DEV_BEP_GMSK_AND_EIGHT_PSK ,	 
 CI_DEV_NUM_BEP_STATUS	 
 } _CiDevBepCvMeanStatus;

typedef UINT32 CiDevBepCvMeanStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_CHANNEL_TYPE_TAG 
 {	 
 CI_DEV_TCH_F_PLUS_ACCH = 1 ,	 
 CI_DEV_TCH_H_PLUS_ACCH = 2 ,	 
 CI_DEV_SDCCH_4 = 4 ,	 
 CI_DEV_SDCCH_8 = 8 ,	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_CHANNEL_TYPE	 
 } _CiDevChannelType;

typedef UINT8 CiDevChannelType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_MODULATION_SCHEME_TAG 
 {	 
 CI_DEV_MS_GMSK = 0 , /**< GMSK */	 
 CI_DEV_MS_8PSK = 1 , /**< 8 PSK */	 
 CI_DEV_MS_INVALID = 0xff , /**< Invalid value */	 
 CI_DEV_NUM_MS /**< Must be the last entry */	 
 } _CiDevModulationScheme;

typedef UINT8 CiDevModulationScheme ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_CODE_SCHEME_TAG 
 {	 
 CI_DEV_CS_CS_1 = 0 ,	 
 CI_DEV_CS_CS_2 ,	 
 CI_DEV_CS_CS_3 ,	 
 CI_DEV_CS_CS_4 ,	 
 CI_DEV_CS_CS_RACH_8 ,	 
 CI_DEV_CS_CS_RACH_11 ,	 
 CI_DEV_CS_MCS_1 ,	 
 CI_DEV_CS_MCS_2 ,	 
 CI_DEV_CS_MCS_3 ,	 
 CI_DEV_CS_MCS_4 ,	 
 CI_DEV_CS_MCS_5 ,	 
 CI_DEV_CS_MCS_6 ,	 
 CI_DEV_CS_MCS_7 ,	 
 CI_DEV_CS_MCS_8 ,	 
 CI_DEV_CS_MCS_9 ,	 
 CI_DEV_CS_MCS_5_7 ,	 
 CI_DEV_CS_MCS_6_9 ,	 
 CI_DEV_CS_INVALID = 0xff ,	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_CS	 
 } _CiDevCodeScheme;

typedef UINT8 CiDevCodeScheme ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_PACKET_IDLE_TYPE_TAG 
 {	 
 CI_DEV_PACKET_IDLE_NONE = 0 , /**< Not attached to packet domain */	 
 CI_DEV_PACKET_IDLE_GPRS , /**< Packet domain supports GPRS */	 
 CI_DEV_PACKET_IDLE_EDGE , /**< Packet domain supports GPRS and EDGE */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_PACKET_IDLE	 
 } _CiDevPacketIdleType;

typedef UINT8 CiDevPacketIdleType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GPRS_SERVICE_TYPE_TAG 
 {	 
 CI_DEV_GPRS_SERVICE_TYPE_GRPS = 0 , /**< Packet domain support GPRS */	 
 CI_DEV_GPRS_SERVICE_TYPE_EDGE , /**< Packet domain support GPRS and EDGE */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_SERVICE_TYPE	 
 } _CiDevGprsServiceType;

typedef UINT8 CiDevGprsServiceType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevEgprsBepCvMeanInfo_struct 
 {	 
 CiDevBepCvMeanStatus status ;	 
	 
 UINT8 gmskMeanBep ;	 
 UINT8 gmskCvBep ;	 
 UINT8 eightPskMeanBep ;	 
 UINT8 eightPskCvBep ;	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 } CiDevEgprsBepCvMeanInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevNetworkMonitorNcellInfo_struct 
 {	 
 UINT8 bsic ; /* Base transceiver station identity code */	 
 UINT8 rxSigLevel ; /* Receive signal level - BCCH */	 
	 
 UINT16 arfcn ; /* Absolute radio frequency channel number */	 
 INT16 C1 ; /* Path loss criterion parameter #1 */	 
 INT16 C2 ; /* Path loss criterion parameter #2 */	 
 } CiDevNetworkMonitorNcellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevNetworkMonitorIdleInfo_struct 
 {	 
 UINT16 arfcn ; /* Absolute radio frequency channel number */	 
 INT16 C1 ; /* Path loss criterion parameter #1 */	 
 INT16 C2 ; /* Path loss criterion parameter #2 */	 
	 
 UINT8 bsic ; /* Base transceiver station identity code */	 
 UINT8 rxSigLevel ; /* Receive signal level - BCCH */	 
	 
 CiDevPacketIdleType isInPacketIdle ;	 
 UINT8 txPower ; /* Transmit power - TBD: phase 2 */	 
 UINT8 res1U8 [ 2 ] ; /* ( padding ) */	 
 } CiDevNetworkMonitorIdleInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevNetworkMonitorDedicatedInfo_struct 
 {	 
 UINT16 arfcn ; /* Absolute radio frequency channel number */	 
 INT16 C1 ; /* Path loss criterion parameter #1 */	 
	 
 UINT8 bsic ; /* Base transceiver station identity code */	 
 UINT8 rxSigLevelFull ; /* Receive signal level accessed over all TDMA frames */	 
 UINT8 rxSigLevelSub ; /* Receive signal level accessed over subset of TDMA frames*/	 
 UINT8 rxQualityFull ; /* Receive quality accessed over all TDMA frames */	 
 UINT8 rxQualitySub ; /* Receive quality accessed over subset of TDMA frames */	 
 UINT8 timingAdv ; /* Initial timing advance or timing advance in SACCH block */	 
	 
 CiBoolean isChannelHopping ; /* Channeling is hopping*/	 
 CiDevChannelType channelType ; /* Channel type*/	 
 UINT16 arfcnTch ; /* ARFCN for traffic channel*/	 
	 
 UINT8 timeSlot ; /* Server time slot */	 
 UINT8 txPower ; /* Transmit Power - TBD: phase 2 */	 
 } CiDevNetworkMonitorDedicatedInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevNetworkMonitorGprsInfo_struct 
 {	 
 UINT16 arfcn ; /* Absolute radio frequency channel number */	 
 INT16 C1 ; /* Path loss criterion parameter #1 */	 
 INT16 C2 ; /* Path loss criterion parameter #2 */	 
	 
 UINT8 bsic ; /* Base transceiver station identity code */	 
 UINT8 rxSigLevelFull ; /* Receive signal level accessed over all TDMA frames */	 
 UINT8 rxSigLevelSub ; /* Receive signal level accessed over subset of TDMA frames*/	 
 UINT8 rxQualityFull ; /* Receive quality accessed over all TDMA frames */	 
 UINT8 rxQualitySub ; /* Receive quality accessed over subset of TDMA frames */	 
 UINT8 cValue ; /* C Value */	 
 UINT8 txPower ; /* Transmit power - TBD: phase 2 */	 
 UINT8 ulTimeSlot ; /* Uplink time slot - TBD: phase 2 */	 
 UINT8 dlTimeSlot ; /* Downlink time slot - TBD: phase 2 */	 
	 
 CiDevGprsServiceType gprsServiceType ; /* GPRS service type - TBD: phase 2 */	 
 CiDevCodeScheme ulCs ; /* Uplink code scheme - TBD: phase 2 */	 
 CiDevCodeScheme dlCs ; /* Downlink code scheme - TBD: phase 2 */	 
 CiDevModulationScheme ulMod ; /* Uplink modulation - TBD: phase 2 */	 
 CiDevModulationScheme dlMod ; /* Downlink modulation - TBD: phase 2 */	 
 CiDevEgprsBepCvMeanInfo egprsBep ; /* TBD: phase 2 */	 
 } CiDevNetworkMonitorGprsInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevNetworkMonitorData_struct 
 {	 
 CiDevNetworkMonitorMode mode ; /* Current mode ( idle / dedicated / GPRS ) */	 
 UINT8 res1U8 [ 3 ] ; /* ( padding ) */	 
	 
 /* Serving Cell information */	 
 union	 
 {		 
 CiDevNetworkMonitorIdleInfo IdleData ;		 
 CiDevNetworkMonitorDedicatedInfo DedicatedData ;		 
 CiDevNetworkMonitorGprsInfo GprsData ;		 
 } svcCellInfo ;	 
	 
 /* Neighboring Cell information */	 
 UINT8 numNCells ; /* 0 ..CI_DEV_MAX_GSM_NEIGHBORING_CELLS */	 
 UINT8 res2U8 [ 3 ] ; /* ( padding ) */	 
 CiDevNetworkMonitorNcellInfo nbCellInfo [ 6 ] ;	 
 } CiDevNetworkMonitorData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimNetworkMonitorInfoInd_struct 
 {	 
 CiDevNetworkMonitorData info ;	 
 } CiDevPrimNetworkMonitorInfoInd;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_CHANNEL_TYPE_TAG 
 {	 
 CI_DEV_EM_TCH_F = 1 ,	 
 CI_DEV_EM_TCH_H = 2 ,	 
 CI_DEV_EM_SDCCH_4 = 4 ,	 
 CI_DEV_EM_SDCCH_8 = 8	 
 } _CiDevEngChannelType;

typedef UINT8 CiDevEngChannelType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_SERVICE_TYPE_TAG 
 {	 
 CI_DEV_CIRCUIT_SWITCHED_SERVICE = 0 ,	 
 CI_DEV_GPRS_SERVICE = 1 ,	 
 CI_DEV_COMBINED_SERVICE = 2 ,	 
 CI_DEV_NO_SERVICES_AVAILABLE = 3 ,	 
	 
 CI_DEV_NUM_OF_SERVICE_TYPES	 
 } _CiDevServiceType;

typedef UINT8 CiDevServiceType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmServingCellInfo_struct 
 {	 
 UINT8 rxSigLevel ; /**< Receive signal level [ range: 0 h-3Fh ] */	 
 UINT8 rxSigLevelFull ; /**< Receive signal level accessed over all TDMA frames [ range: 0 h-3Fh ] */	 
 UINT8 rxSigLevelSub ; /**< Receive signal level accessed over subset of TDMA frames [ range: 0 h-3Fh ] */	 
 UINT8 rxQualityFull ; /**< Receive quality accessed over all TDMA frames [ range: 0 -7 ] */	 
 UINT8 rxQualitySub ; /**< Receive quality accessed over subset of TDMA frames [ range: 0 -7 ] */	 
 UINT8 rac ; /**< Routing area code [ range: 0 -1 ( 1 bit ) ] */	 
 UINT8 bsic ; /**< Base transceiver station identity code [ range: 0 h-3Fh ( 6 bits ) ] */	 
 UINT8 nom ; /**< Network operation mode [ range: MODE_1= 0 / MODE_2= 1 / MODE_3= 2 ] */	 
 UINT8 nco ; /**< Network control order [ range: NC_0=0 / NC_1=1 / NC_2=2 / NC_RESET=3 ] */	 
 UINT8 bs_pa_mfrms ; /**< Number of multiframes between paging messages sent [ range: 0 -7 ] */	 
	 
 UINT16 mcc ; /**< Mobile country code [ range: 0 -999 ( 3 digits ) ] */	 
 UINT16 mnc ; /**< Mobile network code [ range: 0 -99 ( 2 digits ) ] */	 
 UINT16 lac ; /**< Location area code [ range: 0 h-FFFFh ( 2 octets ) ] */	 
 UINT16 ci ; /**< Cell identity [ range: 0 h-FFFFh ( 2 octets ) ] */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number [ range: 0 -1023 ] */	 
	 
 INT16 C1 ; /**< Path loss criterion parameter #1 */	 
	 
 INT16 C2 ; /**< Path loss criterion parameter #2 */	 
	 
 INT16 C31 ; /**< GPRS signal level threshold criterion parameter*/	 
	 
 INT16 C32 ; /**< GPRS cell ranking criterion parameter */	 
	 
	 
 UINT16 t3212 ; /**< Periodic LA update timer ( T3212 ) in minutes */	 
 UINT16 t3312 ; /**< Periodic RA update timer ( T3312 ) in minutes */	 
	 
 CiBoolean pbcchSupport ; /**< Support of PBCCH \sa CCI API Ref Manual */	 
 UINT8 TxPowerLevel ; /**< Tx power level [ range: 0 h-3Fh ] */	 
 UINT8 timingAdv ; /**< Timing advance [ range 0 -63 ] */	 
 CiBoolean hoppingChannel ; /**< Hopping channel */	 
 CiBoolean EGPRSSupport ; /**< EGPRS support capability */	 
 CiDevEngChannelType ChType ; /**< Values are TCH_F = 1 , TCH_H = 2 , SDCCH_4 = 4 , SDCCH_8 = 8 \sa CIDEV_ENGMODE_CHANNEL_TYPE */	 
 CiBoolean nccPermitted ; /**< The NCC permitted parameter sets the NCCs ( network color codes ) that the mobile station is permitted to report. \sa CCI API Ref Manual */	 
 UINT8 RadioLinkTimeout ; /**< Radio link timeout [ range: value >=0 ] */	 
 UINT16 hoCount ; /**< Handovers counter [ range: value>=0 ] */	 
 UINT16 hoSuccessCount ; /**< Success handovers counter [ range: value>=0 ] */	 
 UINT16 chanAssCount ; /**< Channel assignment counter [ range: value>=0 ] */	 
 UINT16 chanAssSuccessCount ; /**< Success channel assignment counter [ range: value>=0 ] */	 
	 
 UINT16 arfcnTch ; /**< ARFCN for traffic channel , only valid for dedicated state [ range: 0 -1023 ] */	 
 UINT8 timeSlot ; /**< Time slot , only valid for dedicated state*/	 
 CiDevPacketIdleType isInPacketIdle ; /**< Only valid for idle state \sa CiDevPacketIdleType */	 
 /*Michal Bukai - I-Mate Addition. Start:*/	 
 CiBoolean IsForbiddenLA ; /**< Indicates if cell belongs to forbidden location area. FALSE: Cell is not in forbidden LA or forbidden status is unknown ; TRUE: Cell is in forbidden LA. \sa CCI API Ref Manual */	 
 CiDevCellPrioriytType CellPriority ; /**< Cell priority for cell selection or reselection. Cell priority can be normal , low or barred. \sa CiDevCellPrioriytType */	 
 UINT8 HSN ; /**< Hopping sequence number. Value 0 means cyclic hopping is done*/	 
 CiDevHoppingGroup HoppingGroup ; /**< List of ARFCNs assigned for frequency hopping . \sa CiDevHoppingGroup */	 
 /*Michal Bukai - I-Mate Addition. End*/	 
 /*Added by Lilei for Network Info CQ56702 , begin*/	 
 UINT8 gsmBand ; /**< 0 :PGSM_900 ; 1 :DCS_GSM_1800 ; 2 :PCS_GSM_1900 ; 3 :EGSM_900 ; 4 :GSM_450 ; 5 :GSM_480 ; 6 :GSM_850 */	 
 UINT8 channelMode ; /**< Mode of a dedicated channel , used during dedicated channel setup to specify channel mode ( signaling-only , speech or data ) , mode version and data rate. */	 
 /*Added by Lilei for Network Info CQ56702 , end*/	 
 /*Lilei , CQ00092855 , 20150427 , begin*/	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 /*Lilei , CQ00092855 , 20150427 , end*/	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiDevAmrCodecType codecType ; /*wCdma*/	 
 UINT32 speechCodecRate ; /*wCdma*/	 
 INT16 RLA ; // rxlevAccessMin ;	 
 INT8 DRX ; // drxTimerMax	 
 INT8 maio ;	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00115868 , 20190815 , begin*/	 
 UINT32 succeededGsmIratReselectionCount ; // gsm irat 4 g to 2 g count	 
 UINT32 succeededGsmHandoverCount ; // gsm cs irat handover count	 
 /*Lilei , CQ00115868 , 20190815 , end*/	 
 } CiDevGsmServingCellInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_MM_REJECTCAUSE_CODE_TYPE {	 
 CI_DEV_EM_MM_REJ_CAUSE_IMSI_UNKNOWN_IN_HLR = 2 , /**< MS identification cause */	 
 CI_DEV_EM_MM_REJ_CAUSE_ILLEGAL_MS=3 , /**< MS identification cause */	 
 CI_DEV_EM_MM_REJ_CAUSE_IMSI_UNKNOWN_IN_VLR =4 , /**< MS identification cause */	 
 CI_DEV_EM_MM_REJ_CAUSE_IMEI_NOT_ACCEPTED =5 , /**< MS identification cause */	 
 CI_DEV_EM_MM_REJ_CAUSE_ILLEGAL_ME =6 , /**< MS identification cause */	 
 CI_DEV_EM_MM_REJ_CAUSE_PLMN_NOT_ALLOWED =11 , /**< Subscription options */	 
 CI_DEV_EM_MM_REJ_CAUSE_LOCATION_AREA_NOT_ALLOWED =12 , /**< Subscription options */	 
 CI_DEV_EM_MM_REJ_CAUSE_ROAMING_NOT_ALLOWED_IN_THIS_LOCATION_AREA =13 , /**< Subscription options */	 
 CI_DEV_EM_MM_REJ_CAUSE_NO_SUITABLE_CELLS_IN_LOCATION_AREA =15 , /**< Subscription options */	 
 CI_DEV_EM_MM_REJ_CAUSE_NETWORK_FAILURE=17 , /**< PLMN specific network failures and congestion / authentication failures */	 
 CI_DEV_EM_MM_REJ_CAUSE_MAC_FAILURE=20 , /**< PLMN specific network failures and congestion / authentication failures*/	 
 CI_DEV_EM_MM_REJ_CAUSE_SYNC_FAILURE=21 , /**< PLMN specific network failures and congestion / authentication failures*/	 
 CI_DEV_EM_MM_REJ_CAUSE_CONGESTION=22 , /**< PLMN specific network failures and congestion / authentication failures*/	 
 CI_DEV_EM_MM_REJ_CAUSE_GSM_AUTHENTICATION_UNACCEPTABLE=23 , /**< PLMN specific network failures and congestion / authentication failures */	 
 CI_DEV_EM_MM_REJ_CAUSE_SERVICE_OPTION_NOT_SUPPORTED=32 , /**< Nature of request */	 
 CI_DEV_EM_MM_REJ_CAUSE_REQUEST_SERVICE_OPTION_NOT_SUBSCRIBED=33 , /**< Nature of request */	 
 CI_DEV_EM_MM_REJ_CAUSE_SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER=34 , /**< Nature of request */	 
 CI_DEV_EM_MM_REJ_CAUSE_CALL_CANNOT_BE_IDENTIFIED=38 , /**< Nature of request */	 
 CI_DEV_EM_MM_REJ_CAUSE_SEMANTICALLY_INCORRECT_MESSAGE=95 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_INVALID_MANDATORY_INFORMATION=96 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_MESSAGE_TYPE_NONEXISTENT_OR_NOT_IMPLEMENTED=97 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE=98 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_INFORMATION_ELEMENT_NONEXISTENT_OR_NOT_IMPLEMENTED=99 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_CONDITIONAL_IE_ERROR=100 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_PROTOCOL_ERROR_UNSPECIFIED=111 , /**< Invalid message */	 
 CI_DEV_EM_MM_REJ_CAUSE_CI_DEV_ALIGN_32_BIT=0XFFFFFFF /**< Used for alignment */	 
	 
 } _CiDevEngMMRejectCauseCodeType;

typedef UINT32 CiDevEngMMRejectCauseCodeType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_BAND_MODE_TYPE {	 
 CI_DEV_EM_BAND_MODE_PGSM_MODE=0 , /**< Standard or primary GSM 900 ( PGSM ) band supported */	 
 CI_DEV_EM_BAND_MODE_EGSM_MODE , /**< Extended GSM 900 band supported */	 
 CI_DEV_EM_BAND_MODE_DCS_MODE , /**< DCS 1800 band supported */	 
 CI_DEV_EM_BAND_MODE_PCS_MODE , /**< PCS 1900 band supported */	 
 CI_DEV_EM_BAND_MODE_GSM850_MODE , /**< GSM 850 band supported */	 
 CI_DEV_EM_BAND_MODE_PGSM_DCS_MODE , /**< PGSM band and DCS 1800 band supported */	 
 CI_DEV_EM_BAND_MODE_EGSM_DCS_MODE , /**< Extended GSM 900 band and DCS 1800 band supported */	 
 CI_DEV_EM_BAND_MODE_PGSM_PCS_MODE , /**< PGSM band and PCS 1900 band supported */	 
 CI_DEV_EM_BAND_MODE_EGSM_PCS_MODE , /**< Extended GSM 900 band and PCS 1900 band supported */	 
 CI_DEV_EM_BAND_MODE_GSM850_DCS_MODE , /**< GSM 850 band and DCS 1800 band supported */	 
 CI_DEV_EM_BAND_MODE_GSM850_PCS_MODE , /**< GSM 850 band and PCS 1900 band supported */	 
 CI_DEV_EM_BAND_MODE_EGSM_MODE_LOCK , /**< Lock the MS to Extended GSM 900 band mode. Autoband DISABLED. For use in testing only. */	 
 CI_DEV_EM_BAND_MODE_DCS_MODE_LOCK , /**< Lock the MS to DCS 1800 band mode. Autoband DISABLED. For use in testing only. */	 
 CI_DEV_EM_BAND_MODE_PCS_MODE_LOCK , /**< Lock the MS to Extended GSM 900 band or PCS 1900 band mode. Autoband DISABLED. For use in testing and 900 / 1900 countries only. */	 
 CI_DEV_EM_BAND_MODE_GSM850_MODE_LOCK , /**< Lock the MS to GSM 850 band mode. Autoband DISABLED. For use in testing only. */	 
 CI_DEV_EM_BAND_MODE_PGSM_PCS_MODE_LOCK , /**< Lock the MS to PGSM band or PCS 1900 band mode. Autoband DISABLED. For use in testing and 900 / 1900 countries only. */	 
 CI_DEV_EM_BAND_MODE_EGSM_PCS_MODE_LOCK , /**< Lock the MS to Extended GSM 900 band or PCS 1900 band mode. Autoband DISABLED. For use in testing and 900 / 1900 countries only. */	 
 CI_DEV_EM_BAND_MODE_EGSM_DCS_MODE_LOCK , /**< Lock the MS to Extended GSM 900 band or DCS 1800 band mode. Autoband DISABLED. For use in testing and 900 / 1800 countries only. */	 
 CI_DEV_EM_BAND_MODE_GSM850_DCS_MODE_LOCK , /**< Lock the MS to GSM 850 band or DCS 1800 band mode. Autoband DISABLED. For use in testing and 850 / 1800 countries only. */	 
 CI_DEV_EM_BAND_MODE_INVALID_BAND_MODE , /**< Invalid band */	 
 CI_DEV_EM_BAND_MODE_CI_DEV_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngBandModeType;

typedef UINT32 CiDevEngBandmodeType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmGMMInfo_struct 
 {	 
 UINT16 MccLastRegisteredNetwork ; /**< Mcc of last registered network */	 
 UINT16 MncLastRegisteredNetwork ; /**< Mnc of last registered network */	 
 UINT32 TMSI ; /**< TMSI */	 
 UINT32 PTMSI ; /**< PTMSI */	 
 CiBoolean IsSingleMmRejectCause ; /**< TRUE - only one MM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 CiDevEngMMRejectCauseCodeType MMRejectCause ; /**< The one that was reported during the last engineering information period. Reject cause ( 10.500000 .3.6 ) sent in CM Service Reject , Abort , MM-Status , and Location Updating Reject messages to MM from the network. \sa CiDevEngMMRejectCauseCodeType */	 
 CiDevEngBandmodeType currentBandMode ; /**< Band mode \sa CiDevEngBandModeType */	 
 UINT8 mmState ; /**< MM state refer to 3 GPP 24.008000 section 4.100000 .2 */ /* see enum MmState in Mm_comm.h. */	 
 UINT8 gmmState ; /**< GMM state refer to 3 GPP 24.008000 section 4.100000 .3 */ /* see enum GmmState in Gmm_comm.h */	 
 UINT8 gprsReadyState ; /**< 0 - IDLE_STATE / 1 - STANDBY_STATE / 2 - READY_STATE. */ /*For details , see enum GprsReadyState in grrmrtyp.h. */	 
 UINT16 readyTimerValueInSecs ; /**< MM ready timer value in seconds [ value >0 ] . Value of 0xffff indicates the timer is not running */	 
 /*Added by Lilei for Network Info CQ56702 , begin*/	 
 UINT8 serviceStatus ; /**< Service status */ /* see enum ServiceStatus in Mmr_sig.h. */	 
 UINT8 LAU_status ; /**<Current update status of the UE */ /* see enum LocationUpdateStatus in Mmr_sig.h. */	 
 UINT16 LAU_count ; /**<LAU attempt counter as held by UE ; number of consecutive LAU failures in current LAU procedure attempt */	 
 /*Added by Lilei for Network Info CQ56702 , end*/	 
 /*Lilei , CQ00082362 , 20150116 , begin*/	 
 UINT8 RAU_status ; /**<RAU status of the UE */ /* see enum GprsUpdateStatus in Mmr_sig.h. */	 
 UINT16 RAU_count ; /**<RAU attempt counter as held by UE ; number of consecutive RAU failures in current RAU procedure attempt*/	 
 /*Lilei , CQ00082362 , 20150116 , end*/	 
 } CiDevGsmGMMInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_AMR_CHANNEL_MODE_TYPE {	 
 CI_DEV_EM_AMR_CH_MODE_AMR_FR = 0 , /**< CHM_SPEECH_FULL_RATE_VER3 channel mode */	 
 CI_DEV_EM_AMR_CH_MODE_AMR_HR , /**< CHM_SPEECH_HALF_RATE_VER3 channel mode */	 
 CI_DEV_EM_AMR_CH_MODE_EFR , /**< CHM_SPEECH_FULL_RATE_VER2 / CHM_SPEECH_HALF_RATE_VER2 channel modes */	 
 CI_DEV_EM_AMR_CH_MODE_FR , /**< CHM_SPEECH_FULL_RATE channel mode */	 
 CI_DEV_EM_AMR_CH_MODE_HR , /**< CHM_SPEECH_HALF_RATE channel mode */	 
 CI_DEV_EM_AMR_CH_MODE_ALIGN_32_BIT=0XFFFFFFF /**< For alignment */	 
 } _CiDevEngAMRChannelModeType;

typedef UINT32 CiDevEngAMRChannelModeType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_AMR_CODE_TYPE {	 
 CI_DEV_EM_AMR_CODE_TYPE_4_75_KBPS = 1 , /**< AMR codec rate enumeration for 4.750000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_5_15_KBPS , /**< AMR codec rate enumeration for 5.150000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_5_9_KBPS , /**< AMR codec rate enumeration for 5.900000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_6_7_KBPS , /**< AMR codec rate enumeration for 6.700000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_7_4_KBPS , /**< AMR codec rate enumeration for 7.400000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_7_95_KPBS , /**< AMR codec rate enumeration for 7.950000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_10_2_KPBS , /**< AMR codec rate enumeration for 10.200000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_12_2_KBPS , /**< AMR codec rate enumeration for 12.200000 Kbit / s codec rate */	 
 CI_DEV_EM_AMR_CODE_TYPE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngAMRCodeType;

typedef UINT32 CiDevEngAMRCodeType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngAMRActiveCodeSetType_struct 
 {	 
 UINT8 AcsSize ; /**< Number of codes in AMR AS - up to 4 */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
	 
 CiDevEngAMRCodeType Acs [ 4 ] ; /**< AMR code type \sa CiDevEngAMRCodeType */	 
 } CiDevEngAMRActiveCodeSetType;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAMRInfo_struct 
 {	 
 CiDevEngAMRChannelModeType ULChannelMode ; /**< Current uplink channel mode { AMR FR , AMR HR , EFR , FR , HR } \sa CiDevEngAMRChannelModeType */	 
 CiDevEngAMRChannelModeType DLChannelMode ; /**< Current downlink channel mode { AMR FR , AMR HR , EFR , FR , HR } \sa CiDevEngAMRChannelModeType */	 
 CiDevEngAMRActiveCodeSetType ActiveCodeSet ; /**< Active code set ( ACS ) \sa CiDevEngAMRActiveCodeSetType_struct */	 
 CiBoolean DTXUl ; /**< DTX UL on / off \sa CCI API Ref Manual */	 
 CiBoolean DTXDl ; /**< If at least one DTX during DL has happened , then DTXDI =TRUE , otherwise = FALSE. \sa CCI API Ref Manual */	 
 INT16 DlCi ; /**< L1 calculates average of confidence measure for frequency offset for all the bursts of the multiframe. [ Ratio linear value 0 -500 ] . */	 
 UINT8 RxQualSub ; /**< Used when DTX is on , range is 0 -7 */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 } CiDevAMRInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_GPRS_ATTACH_TYPE {	 
 CI_DEV_EM_GPRS_ATTACH_TYPE_GPRS_ONLY_ATTACH=0 , /**< GPRS only */	 
 CI_DEV_EM_GPRS_ATTACH_TYPE_GPRS_ATTACH_WHILE_IMSI_ATTACHED , /**< GPRS attach while IMSI attached */	 
 CI_DEV_EM_GPRS_ATTACH_TYPE_COMBINED_IMSI_ATTACH , /**< Combined GPRS attach */	 
 CI_DEV_EM_GPRS_ATTACH_TYPE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngGPRSAttachType;

typedef UINT32 CiDevEngGPRSAttachType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_MACMODE_TYPE {	 
 CI_DEV_EM_MACMODE_TYPE_MAC_DYNAMIC_ALLOC =0 , /**< Dynamic allocation ( DA ) */	 
 CI_DEV_EM_MACMODE_TYPE_MAC_EXTENDED_DYNAMIC_ALLOC , /**< Extended dynamic allocation ( EDA ) */	 
 CI_DEV_EM_MACMODE_TYPE_MAC_FIXED_ALLOC_NOT_HALF_DUPLEX , /**< Fixed not half duplex allocation */	 
 CI_DEV_EM_MACMODE_TYPE_MAC_FIXED_ALLOC_HALF_DUPLEX , /**< Fixed half duplex allocation */	 
 CI_DEV_EM_MACMODE_TYPE_MAC_UNKNOWN_ALLOC_MODE , /**< Unknown allocation */	 
 CI_DEV_EM_MACMODE_TYPE_CI_DEV_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngMacModeType;

typedef UINT32 CiDevEngMacModeType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_NETWORK_CTRL_TYPE {	 
 CI_DEV_EM_NW_CTRL_NC_0 =0 ,	 
 CI_DEV_EM_NW_CTRL_NC_1 ,	 
 CI_DEV_EM_NW_CTRL_NC_2 ,	 
 CI_DEV_EM_NW_CTRL_NC_RESERVED ,	 
 CI_DEV_EM_NW_CTRL_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngNetworkControlType;

typedef UINT32 CiDevEngNetworkControlType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_NW_MODE_TYPE {	 
 CI_DEV_EM_NW_MODE_TYPE_NOM1 =0 , /**< NW provides simultaneous CS and PS */	 
 CI_DEV_EM_NW_MODE_TYPE_NOM2 , /**< UE remains attached to PS while receiving CS */	 
 CI_DEV_EM_NW_MODE_TYPE_NOM3 , /**< UE can be connected to CS or PS */	 
 CI_DEV_EM_NW_MODE_TYPE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngNetworkModeType;

typedef UINT32 CiDevEngNetworkModeType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_CODINGSCHEME_TYPE {	 
 CI_DEV_EM_CS_1 =0 , /**< CS1 */	 
 CI_DEV_EM_CS_2 , /**< CS2 */	 
 CI_DEV_EM_CS_3 , /**< CS3 */	 
 CI_DEV_EM_CS_4 , /**< CS4 */	 
 CI_DEV_EM_MCS_1 , /**< MCS1 */	 
 CI_DEV_EM_MCS_2 , /**< MCS2 */	 
 CI_DEV_EM_MCS_3 , /**< MCS3 */	 
 CI_DEV_EM_MCS_4 , /**< MCS4 */	 
 CI_DEV_EM_MCS_5 , /**< MCS5 */	 
 CI_DEV_EM_MCS_6 , /**< MCS6 */	 
 CI_DEV_EM_MCS_7 , /**< MCS7 */	 
 CI_DEV_EM_MCS_8 , /**< MCS8 */	 
 CI_DEV_EM_MCS_9 , /**< MCS9 */	 
 CI_DEV_EM_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngCodingSchemeType;

typedef UINT32 CiDevEngCodingSchemeType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_EGPR_SLQ_MEAS_MODE_TYPE {	 
 CI_DEV_EM_NO_LINK_QUAL_MEASUREMENTS =0 , /**< No report */	 
 CI_DEV_EM_LINK_QUAL_INT_MEAS_ONLY , /**< Report interference measurements */	 
 CI_DEV_EM_LINK_QUAL_BEP_MEAS_ONLY , /**< Report mean BEP measurements */	 
 CI_DEV_EM_LINK_QUAL_INT_AND_BEP_MEAS , /**< Report both interference and BEP measurements */	 
 CI_DEV_EM_EGPR_SLQ_MEAS_MODE_TYPE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngEGPRSLQMeasModeType;

typedef UINT32 CiDevEngEGPRSLQMeasModeType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_GMM_REJ_CAUSE_CODE_TYPE {	 
 CI_DEV_EM_GMM_REJ_CAUSE_GPRS_SERVICE_NOT_ALLOWED=7 , /**< GPRS services not allowed */	 
 CI_DEV_EM_GMM_REJ_CAUSE_GPRS_SERVICE_AND_NON_GPRS_SERVICE_NOT_ALLOWED=8 , /**< GPRS services and non-GPRS services not allowed */	 
 CI_DEV_EM_GMM_REJ_CAUSE_MS_IDENTITY_CANNOT_BE_DERIVED_BY_NW=9 , /**< MS identity cannot be derived by the network */	 
 CI_DEV_EM_GMM_REJ_CAUSE_IMPLICITLY_DETACHED=10 , /**< Implicitly detached */	 
 CI_DEV_EM_GMM_REJ_CAUSE_GPRS_SERVICES_NOT_ALLOWED_IN_PLMN=14 , /**< GPRS services not allowed in this PLMN */	 
 CI_DEV_EM_GMM_REJ_CAUSE_MSC_TEMPORARILY_NOT_REACHABLE=16 , /**< MSC temporarily not reachable */	 
 CI_DEV_EM_GMM_REJ_CAUSE_NO_PDP_CONTEXT_ACTIVATED=40 , /**< No PDP context activated */	 
 CI_DEV_EM_GMM_REJ_CAUSE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngGMMRejectCauseCodeType;

typedef UINT32 CiDevEngGMMRejectCauseCodeType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngIPAddressType_struct 
 {	 
 UINT8 len ; /**< Length of the address field */	 
 UINT8 address [ 16 ] ; /**< Address field */	 
 } CiDevEngIPAddressType;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_DELAY_CLASS_TYPE {	 
 CI_DEV_EM_GPRS_DELAY_CLASS_SUBSCRIBED =0 , /**< Subscribed delay class */	 
 CI_DEV_EM_GPRS_DELAY_CLASS_1 , /**< Delay class 1 */	 
 CI_DEV_EM_GPRS_DELAY_CLASS_PACKET_CELL_CHANGE_ORDER2 , /**< Delay class 2 */	 
 CI_DEV_EM_GPRS_DELAY_CLASS_3 , /**< Delay class 3 */	 
 CI_DEV_EM_GPRS_DELAY_CLASS_4 , /**< Delay class 4 ( best effort ) */	 
 CI_DEV_EM_GPRS_DELAY_CLASS_RESERVED = 7 , /**< Reserved */	 
 CI_DEV_EM_DELAY_CLASS_TYPE_ALIGN_32_BIT=0XFFFFFFF /**< Alignment */	 
 } _CiDevEngDelayClassType;

typedef UINT32 CiDevEngDelayClassType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_RELIABILITY_CLASS_TYPE {	 
 CI_DEV_EM_GPRS_RELIAB_CLASS_SUBSCRIBED =0 , /**< Subscribed reliability class */	 
 CI_DEV_EM_GPRS_RELIAB_CLASS_1 , /**< Unused. If received , it is interpreted as ' 10 ' . */	 
 CI_DEV_EM_GPRS_RELIAB_CLASS_2 , /**< Unacknowledged GTP ; acknowledged LLC and RLC , protected data */	 
 CI_DEV_EM_GPRS_RELIAB_CLASS_3 , /**< Unacknowledged GTP and LLC ; acknowledged RLC , protected data */	 
 CI_DEV_EM_GPRS_RELIAB_CLASS_4 , /**< Unacknowledged GTP , LLC , and RLC , protected data */	 
 CI_DEV_EM_GPRS_RELIAB_CLASS_5 , /**< Unacknowledged GTP , LLC , and RLC , unprotected data */	 
 CI_DEV_EM_RELIABILITY_CLASS_TYPE_ALIGN_32_BIT=0XFFFFFFF /**< Alignment */	 
 } _CiDevEngReliabilityClassType;

typedef UINT32 CiDevEngReliabilityClassType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_PEAK_THR_TYPE {	 
 CI_DEV_EM_GPRS_PEAK_THRPT_SUBSCRIBED =0 , /**< Subscribed peak throughput */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_1KOCT , /**< Up to 1 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_2KOCT , /**< Up to 2 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_4KOCT , /**< Up to 4 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_8KOCT , /**< Up to 8 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_16KOCT , /**< Up to 16 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_32KOCT , /**< Up to 32 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_64KOCT , /**< Up to 64 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_128KOCT , /**< Up to 128 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_256KOCT , /**< Up to 256 , 0 octet / s */	 
 CI_DEV_EM_GPRS_PEAK_THRPT_RESERVED = 0x0f , /**< Reserved */	 
 CI_DEV_EM_PEAK_THR_TYPE_ALIGN_32_BIT=0XFFFFFFF /**< Alignment */	 
 } _CiDevEngPeakThroughputType;

typedef UINT32 CiDevEngPeakThroughputType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_PRECEDENCE_CLASS_TYPE {	 
 CI_DEV_EM_GPRS_PRECED_CLASS_SUBSCRIBED =0 , /**< Subscribed precedence ( in MS to network direction ) */	 
 CI_DEV_EM_GPRS_PRECED_CLASS_1 , /**< High priority ( in MS to network direction ) */	 
 CI_DEV_EM_GPRS_PRECED_CLASS_2 , /**< Normal priority ( in MS to network direction ) */	 
 CI_DEV_EM_GPRS_PRECED_CLASS_3 , /**< Low priority ( in MS to network direction ) */	 
 CI_DEV_EM_GPRS_PRECED_CLASS_RESERVED = 7 , /**< Reserved */	 
 CI_DEV_EM_PRECEDENCE_CLASS_TYPE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevEngprecedenceClassType;

typedef UINT32 CiDevEngprecedenceClassType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_ENGMODE_MEANTHROUGHPUT_TYPE {	 
 CI_DEV_EM_GPRS_MEAN_THRPT_SUBSCRIBED =0 , /**< Subscribed precedence ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_100_OPH , /**< 100 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_200_OPH , /**< 200 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_500_OPH , /**< 500 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_1K_OPH , /**< 1 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_2K_OPH , /**< 2 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_5K_OPH , /**< 5 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_10K_OPH , /**< 10 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_20K_OPH , /**< 20 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_50K_OPH , /**< 50 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_100K_OPH , /**< 100 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_200K_OPH , /**< 200 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_500K_OPH , /**< 500 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_1M_OPH , /**< 1 , 0 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_2M_OPH , /**< 2 , 0 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_5M_OPH , /**< 5 , 0 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_10M_OPH , /**< 10 , 0 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_20M_OPH , /**< 20 , 0 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_50M_OPH , /**< 50 , 0 , 0 octet / h ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_RESERVED = 30 , /**< Reserved ( in MS to network direction and in network to MS direction ) */	 
 CI_DEV_EM_GPRS_MEAN_THRPT_BEST_EFFORT = 31 , /**< Best effort. The value indicates that throughput is made available to the MS on a per need and availability basis ( in MS to network direction and in network to MS direction ) . */	 
 CI_DEV_EM_MEANTHROUGHPUT_TYPE_ALIGN_32_BIT=0XFFFFFFF	 
 } _CiDevMeanThroughputType;

typedef UINT32 CiDevMeanThroughputType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngQualityOfServiceType_struct 
 {	 
 CiDevEngDelayClassType delayClass ; /**< GPRS delay class \sa CiDevEngDelayClassType */	 
 CiDevEngReliabilityClassType reliabilityClass ; /**< Reliability class \sa CiDevEngReliabilityClassType */	 
 CiDevEngPeakThroughputType peakThroughput ; /**< Peak throughput \sa CiDevEngPeakThroughputType */	 
 CiDevEngprecedenceClassType precedenceClass ; /**< Precedence class \sa CiDevEngprecedenceClassType */	 
 CiDevMeanThroughputType meanThroughput ; /**< Mean throughput \sa CiDevMeanThroughputType */	 
 } CiDevEngQualityOfServiceType;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngAPNType_struct 
 {	 
 INT8 length ;	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 UINT8 name [ 100 ] ; /**< IP address or an ASCII character string that identifies the GGSN */	 
 } CiDevEngAPNType;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngActivePDPContextinfoType_struct 
 {	 
 CiDevEngIPAddressType IPaddress ; /**< IP address \sa CiDevEngIPAddressType_struct */	 
 CiDevEngQualityOfServiceType QOS ; /**< Quality of service information \sa CiDevEngQualityOfServiceType_struct */	 
 CiDevEngAPNType APN ; /**< \sa CiDevEngAPNType_struct */	 
 } CiDevEngActivePDPContextinfoType;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimActivePDPContextEngModeInd_struct {	 
 UINT8 Index ; /**< PDP context index */	 
 CiDevEngActivePDPContextinfoType ActivePDPContextinfo ; /**< PDP context information \sa CiDevEngActivePDPContextinfoType_struct */	 
 } CiDevPrimActivePDPContextEngModeInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGPRSPTMInfo_struct 
 {	 
 CiBoolean GPRSAttached ; /**< TRUE - MS is GPRS attached ; FALSE - other \sa CCI API Ref Manual */	 
 INT8 EGPRSBEPPeriod ; /**< BEP measurement averaging coefficient */	 
 CiBoolean IsSingleGmmRejectCause ; /**< TRUE - only one GMM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 UINT8 NumActivePDPContext ; /**< 0 means no active PDP context [ range: 0 -7 ] */	 
	 
 CiDevEngGPRSAttachType GPRSAttachType ; /**< GPRS attach type \sa CiDevEngGPRSAttachType */	 
 CiDevEngMacModeType MacMode ; /**< Mac mode type \sa CiDevEngMacModeType */	 
 CiDevEngNetworkControlType NetworkControl ; /**< Not in use ( network control order ) \sa CiDevEngNetworkControlType */	 
 CiDevEngNetworkModeType NetworkMode ; /**< Network mode type \sa CiDevEngNetworkModeType */	 
 CiDevEngCodingSchemeType CodingSchemeUL ; /**< UL coding scheme \sa CiDevEngCodingSchemeType */	 
 CiDevEngCodingSchemeType CodingSchemeDL ; /**< DL coding scheme \sa CiDevEngCodingSchemeType*/	 
 CiDevEngEGPRSLQMeasModeType EGPRSLQMeasurementMode ; /**< Link quality measurement mode \sa CiDevEngEGPRSLQMeasModeType */	 
 CiDevEngGMMRejectCauseCodeType GMMRejectCause ; /**< Reported during the last engineering information period \sa CiDevEngGMMRejectCauseCodeType */	 
	 
 UINT8 cValue ; /**< C value */	 
 UINT8 txPower ; /**< Transmit power of every block - TBD: phase 2 */	 
 UINT8 ulTimeSlot ; /**< Uplink time slot allocation bitmap */	 
 UINT8 dlTimeSlot ; /**< Downlink time slot allocation bitmap */	 
	 
 CiDevGprsServiceType gprsServiceType ; /**< GPRS service type GPRS / EDGE \sa CiDevGprsServiceType */	 
 CiDevModulationScheme ulMod ; /**< Uplink modulation - TBD: phase 2 \sa CiDevModulationScheme */	 
 CiDevModulationScheme dlMod ; /**< Downlink modulation - TBD: phase 2 \sa CiDevModulationScheme */	 
 /*Michal Bukai - I-Mate Addition. Start:*/	 
 UINT8 USFGranularity ; /**< USF granularity defines the number of RLC / MAC blocks to transmit if USF is present. 0 - the mobile station shall transmit one RLC / MAC block , 1 - the mobile station shall transmit four consecutive RLC / MAC blocks */	 
 UINT32 ULThroughput ; /**< UL throughput in octets per second */	 
 UINT32 DLThroughput ; /**< DL throughput in octets per second */	 
 /*Michal Bukai - I-Mate Addition. End*/	 
 CiDevEgprsBepCvMeanInfo egprsBep ; /**< BEP period - TBD: phase 2 \sa CiDevEgprsBepCvMeanInfo_struct */	 
 } CiDevGPRSPTMInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeNcellInfoGsm_struct {	 
 UINT32 ci ; /**< Cell identity */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT8 bsic ; /**< Base transceiver station identity code */	 
 UINT8 rxSigLevel ; /**< Receive signal level */	 
 } CiDevEngModeNcellInfoGsm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeNcellInfoListGsm_struct {	 
 UINT8 numNcellGsm ; /**< Number of GSM neighbor cells */	 
 CiDevEngModeNcellInfoGsm nCellInfoGsm [ 32 ] ; /**< GSM neighbor cells info , maximum 32 cells */	 
 } CiDevEngModeNcellInfoListGsm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeNcellInfoUmts_struct {	 
 UINT32 ci ; /**< Cell Identity */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power */	 
 } CiDevEngModeNcellInfoUmts;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeNcellInfoListUmts_struct {	 
 UINT8 numNcellUmts ; /**< Number of UMTS neighbor cells */	 
 CiDevEngModeNcellInfoUmts nCellInfoUmts [ 32 *2 ] ; /**< UMTS neighbor cells info , maximum 32 ( intraFreq ) +32 ( interFreq ) cells */	 
 } CiDevEngModeNcellInfoListUmts;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeNcellInfoLte_struct {	 
 UINT16 physCellId ; /**< Physical cell identity */	 
 UINT32 earfcn ; /**< Eutra absolute radio frequency channel number */	 
 UINT8 rsrp ; /**< Reference signal receive power */	 
 UINT8 rsrq ; /**< Reference signal receive quality */	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 INT16 s_rxlev ;	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevEngModeNcellInfoLte;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeNcellInfoListLte_struct {	 
 UINT8 numNcellLte ; /**< Number of LTE neighbor cells */	 
 CiDevEngModeNcellInfoLte nCellInfoLte [ 32 *2 ] ; /**< LTE neighbor cells info , maximum 32 ( intraFreq ) +32 ( interFreq ) cells */	 
 } CiDevEngModeNcellInfoListLte;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmNeighboringCellInfo_struct 
 {	 
 UINT8 rxSigLevel ; /**< Receive signal level */	 
 UINT8 bsic ; /**< Base transceiver station identity code */	 
 UINT8 rac ; /**< Routing area code */	 
 UINT8 res1U8 ; /**< ( padding ) */	 
	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 ci ; /**< Cell identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
	 
 INT16 C1 ; /**< Path loss criterion parameter #1 */	 
 INT16 C2 ; /**< Path loss criterion parameter #2 */	 
 INT16 C31 ; /**< GPRS signal level threshold criterion parameter */	 
 INT16 C32 ; /**< GPRS cell ranking criterion parameter */	 
 /*Michal Bukai - I-Mate Addition. Start:*/	 
 CiBoolean IsForbiddenLA ; /**< Indicates if cell belongs to forbidden location area. FALSE: Cell is not in forbidden LA or forbidden status is unknown ; TRUE: Cell is in forbidden LA. \sa CCI API Ref Manual */	 
 CiDevCellPrioriytType CellPriority ; /**< Cell priority for cell selection or reselection. Cell priority can be normal , low or barred. \sa CiDevCellPrioriytType */	 
 /*Michal Bukai - I-Mate Addition. End*/	 
 /*Lilei , CQ00134586 , 20211221 , begin*/	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 /*Lilei , CQ00134586 , 20211221 , begin*/	 
 } CiDevGsmNeighboringCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmUMTSNeighboringCellInfo_struct 
 {	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power */	 
 INT16 cpichEcN0 ; /**< CPICH Ec / N0 , only valid for FDD */	 
 } CiDevGsmUMTSNeighboringCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeGsmData_struct 
 {	 
 CiDevGsmServingCellInfo svcCellInfo ; /**< Serving cell information \sa CiDevGsmServingCellInfo_struct */	 
	 
 CiDevGsmGMMInfo GMMInfo ; /**< Mobility management information \sa CiDevGsmGMMInfo_struct */	 
 CiDevAMRInfo AMRInfo ; /**< AMR information \sa CiDevAMRInfo_struct */	 
 CiDevGPRSPTMInfo GPRSPTMInfo ; /**< Packet data information \sa CiDevGPRSPTMInfo_struct */	 
	 
 UINT8 numNCells ; /**< Number of neighboring cells [ 0 ..CI_DEV_MAX_GSM_NEIGHBORING_CELLS ] */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevGsmNeighboringCellInfo nbCellInfo [ 6 ] ; /**< Neighboring cell information \sa CiDevGsmNeighboringCellInfo_struct */	 
	 
 UINT8 numInterRATNCells ; /**< Number of InterRAT cells [ 0 ..CI_DEV_MAX_GSM_NEIGHBORING_CELLS ] */	 
 UINT8 res2U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevGsmUMTSNeighboringCellInfo InterRATCellInfo [ 6 ] ; /**< InterRAT cell information \sa CiDevCiDevGsmUMTSNeighboringCellInfo */	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiDevEngModeNcellInfoListLte nCellInfoListLte ; /**< LTE neighbor cells info list */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevEngModeGsmData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsServingCellMeasurements_struct 
 {	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power ; in UMTS FDD / TDD messages RSCP is	 
 transmitted as an integer value in the range of -120 dBm to -25 dBm.	 
 The value is coded into integers from -5 to 99 according to 3 GPP ' s 25.133000 . */	 
 INT16 utraRssi ; /**< UTRA Carrier RSSI ; range 0 - 63	 
 UTRA_carrier_RSSI_LEV _00: UTRA carrier RSSI < -94 dBm	 
 UTRA_carrier_RSSI_LEV _01: -94 dBm ?UTRA carrier RSSI < -93 dBm	 
 UTRA_carrier_RSSI_LEV _02: -93 dBm ?UTRA carrier RSSI < -92 dBm	 
 UTRA_carrier_RSSI_LEV _61: -32 dBm ?UTRA carrier RSSI < -33 dBm	 
 UTRA_carrier_RSSI_LEV _62: -33 dBm ?UTRA carrier RSSI < -32 dBm	 
 UTRA_carrier_RSSI_LEV _63: -32 dBm ?UTRA carrier RSSI */	 
 INT16 cpichEcN0 ; /**< CPICH Ec / N0 , only valid for FDD */	 
 INT16 sQual ; /**< Cell selection quality ( Squal ) , only valid for FDD */	 
 INT16 sRxLev ; /**< Cell selection Rx level ( Srxlev ) */	 
 INT16 txPower ; /**< UE transmitted power */	 
 INT16 RxPower ; /**< CDMA will don ' t support now , be filled in future */ /*added by taow 20181107 CQ00112754 */	 
 /* TBD: Transport Channel BLER */	 
	 
 } CiDevUmtsServingCellMeasurements;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsServingCellParameters_struct 
 {	 
 UINT8 rac ; /**< Routing area code */	 
 UINT8 nom ; /**< Network operation mode */	 
	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT32 ci ; /**< Cell identity ; as per 3 G TS 25.331000 , 10.300000 .2.2 ( 28 bits ) */	 
 UINT16 uraId ; /**< URA identity */	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
	 
 UINT16 t3212 ; /**< Periodic LA update timer ( T3212 ) in minutes */	 
 UINT16 t3312 ; /**< Periodic RA update timer ( T3312 ) in minutes */	 
	 
 CiBoolean hcsUsed ; /**< Hierarchical cell structure used? \sa CCI API Ref Manual */	 
 CiBoolean attDetAllowed ; /**< Attach-detach allowed? \sa CCI API Ref Manual */	 
	 
	 
 UINT16 csDrxCycleLen ; /**< CS domain DRX cycle length */	 
 UINT16 psDrxCycleLen ; /**< PS domain DRX cycle length */	 
 UINT16 utranDrxCycleLen ; /**< UTRAN DRX cycle length */	 
 CiBoolean HSDPASupport ; /**< TRUE - serving cell supports HSDPA ; FALSE - other. \sa CCI API Ref Manual */	 
 CiBoolean HSUPASupport ; /**< TRUE - serving cell supports HSUPA ; FALSE - other. \sa CCI API Ref Manual */	 
	 
 /*Lilei , CQ00092855 , 20150427 , begin*/	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 /*Lilei , CQ00092855 , 20150427 , end*/	 
 /*Lilei , CQ00109042 , 20180118 , begin*/	 
 UINT8 band ;	 
 /*Lilei , CQ00109042 , 20180118 , end*/	 
 /*Lilei , CQ00115868 , 20190815 , begin*/	 
 UINT32 totalHandoversCount ;	 
 UINT32 succeededHandoversCount ;	 
 UINT32 succeededUmtsReselectionCount ;	 
 UINT32 timeStayUmtsConnectedMode ; // seconds	 
 /*Lilei , CQ00115868 , 20190815 , begin*/	 
 } CiDevUmtsServingCellParameters;

//ICAT EXPORTED ENUM 
 typedef enum CI_CIPHER_ALGORITHM_TYPE 
 {	 
 CI_CIPHER_ALGORITHM_TYPE_UEA0 , /**< As per 3 G TS 25.331000 , 10.300000 .3.4 */	 
 CI_CIPHER_ALGORITHM_TYPE_UEA1 /**< As per 3 G TS 25.331000 , 10.300000 .3.4 */	 
 } _CiCipherAlgorithmType;

typedef UINT8 CiCipherAlgorithmType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCipherAlgorithm_struct 
 {	 
 CiBoolean algPresent ; /**< Indicates if an algorithm is defined \sa CCI API Ref Manual */	 
 CiCipherAlgorithmType cipherAlg ; /**< Cipher algorithm type \sa CiCipherAlgorithmType */	 
 CiBoolean cipherOn ; /* Ciphering status = on / off \sa CCI API Ref Manual */	 
 } CiCipherAlgorithmInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsUeOperationStatus_struct 
 {	 
 CiDevEngModeUeRrcState rrcState ; /**< RRC state \sa CiDevEngModeUeRrcState */	 
 UINT8 numLinks ; /**< Number of radio links */	 
	 
 UINT16 srncId ; /**< U-RNTI: SRNC identifier */	 
 UINT32 sRnti ; /**< U-RNTI: S-RNTI */	 
 CiCipherAlgorithmInfo csCipherInfo ; /**< CS domain ciphering information. \sa CiCipherAlgorithm_struct */	 
 CiCipherAlgorithmInfo psCipherInfo ; /**< PS domain ciphering information. \sa CiCipherAlgorithm_struct */	 
 CiBoolean HSDPAActive ; /**< TRUE - HSDPA is currently activated ; FALSE - other \sa CCI API Ref Manual */	 
 CiBoolean HSUPAActive ; /**< TRUE - HSUPA is currently activated ; FALSE - other \sa CCI API Ref Manual */	 
 UINT16 MccLastRegisteredNetwork ; /**< Mcc of last registered network */	 
 UINT16 MncLastRegisteredNetwork ; /**< Mnc of last registered network */	 
 INT32 TMSI ; /**< TMSI */	 
 INT32 PTMSI ; /**< PTMSI */	 
 CiBoolean IsSingleMmRejectCause ; /**< TRUE - only one MM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 CiBoolean IsSingleGmmRejectCause ; /**< TRUE - only one GMM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 CiDevEngMMRejectCauseCodeType MMRejectCause ; /**< The one that was reported during the last engineering information period reject cause ( 10.500000 .3.6 ) sent in CM Service Reject , Abort , MM-Status , and Location Updating Reject messages to MM from the network. \sa CiDevEngMMRejectCauseCodeType */	 
 CiDevEngGMMRejectCauseCodeType GMMRejectCause ; /**< Reported during the last engineering information period \sa CiDevEngGMMRejectCauseCodeType */	 
 UINT8 mmState ; /**< MM state refer to 3 GPP 24.008000 section 4.100000 .2 */ /* see enum MmState in Mm_comm.h. */	 
 UINT8 gmmState ; /**< GMM state refer to 3 GPP 24.008000 section 4.100000 .3 */ /* see enum GmmState in Gmm_comm.h */	 
 UINT8 gprsReadyState ; /**< 0 - IDLE_STATE / 1 - STANDBY_STATE / 2 - READY_STATE. */ /* see enum GprsReadyState in grrmrtyp.h. */	 
 UINT16 readyTimerValueInSecs ; /**< MM ready timer value in sec [ value >0 ] */	 
 UINT8 NumActivePDPContext ; /**< Number of active PDP contexts */	 
 /*Michal Bukai - I-Mate Addition. Start:*/	 
 UINT32 ULThroughput ; /**< UL throughput in octets per second */	 
 UINT32 DLThroughput ; /**< DL throughput in octets per second */	 
 /*Michal Bukai - I-Mate Addition. End*/	 
 /*Added by Lilei for Network Info CQ56702 , begin*/	 
 UINT8 serviceStatus ; /**< Service status */ /* see enum ServiceStatus in Mmr_sig.h. */	 
 UINT8 pmmState ; /**< UMM state for PS services */ /* see enum UmmState in Mm_comm.h. */	 
 /*Added by Lilei for Network Info CQ56702 , end*/	 
 /*Lilei , CQ00082362 , 20150116 , begin*/	 
 UINT8 LAU_status ; /**<Current update status of the UE */ /* see enum LocationUpdateStatus in Mmr_sig.h. */	 
 UINT16 LAU_count ; /**<LAU attempt counter as held by UE ; number of consecutive LAU failures in current LAU procedure attempt */	 
 UINT8 RAU_status ; /**<RAU status of the UE */ /* see enum GprsUpdateStatus in Mmr_sig.h. */	 
 UINT16 RAU_count ; /**<RAU attempt counter as held by UE ; number of consecutive RAU failures in current RAU procedure attempt*/	 
 /*Lilei , CQ00082362 , 20150116 , end*/	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 UINT16 phyChType ; // 0 is DPCH , 1 is FDPCH. 0xFF is invalid	 
 UINT16 sf ;	 
 UINT8 slotFormat ;	 
 CiBoolean compressMode ;	 
 CiDevAmrCodecType codecType ; /*wCdma*/	 
 UINT32 speechCodecRate ; /*wCdma*/	 
 INT16 rssi ;	 
 CiBoolean isSinrPresent ;	 
 INT16 sinr ;	 
	 
 /*added by taow 20181107 CQ00112754 end*/	 
	 
 } CiDevUmtsUeOperationStatus;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsServingCellInfo_struct 
 {	 
 CiBoolean sCellMeasPresent ; /**< TRUE - is present ; FALSE - is not present. \sa CCI API Ref Manual */	 
 CiBoolean sCellParamPresent ; /**< TRUE - is present ; FALSE - is not present. \sa CCI API Ref Manual */	 
 CiBoolean ueOpStatusPresent ; /**< TRUE - is present ; FALSE - is not present. \sa CCI API Ref Manual */	 
 UINT8 res1U8 ; /**< padding */	 
 CiDevUmtsServingCellMeasurements sCellMeas ; /**< SCell measurements \sa CiDevUmtsServingCellMeasurements_struct */	 
 CiDevUmtsServingCellParameters sCellParam ; /**< PLMN / cell parameters \sa CiDevUmtsServingCellParameters_struct */	 
 CiDevUmtsUeOperationStatus ueOpStatus ; /**< UE operation status \sa CiDevUmtsUeOperationStatus_struct */	 
 } CiDevUmtsServingCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsASInfo_struct 
 {	 
 UINT32 ci ; /**< Cell identity ; as per 3 G TS 25.331000 , 10.300000 .2.2 ( 28 bits ) */	 
 UINT16 psc ; /**< Primary scrambling code */	 
 CiBoolean HSDPAServingCell ; /**< Indicates if this cell is the HSDPA serving cell \sa CCI API Ref Manual */	 
 CiBoolean HSUPAServingCell ; /**< Indicates if this cell is part of the HSUPA active set - relevant for rel. 6 \sa CCI API Ref Manual */	 
 INT16 cpichRSCP ; /**< CPICH received signal code power ; in UMTS FDD messages RSCP is transmitted as an integer value in the range of -120 dBm to -25 dBm. The value is coded into integers from -5 to 99 according to 3 GPP ' s 25.133000 . */	 
 INT16 cpichEcN0 ; /**< CPICH Ec / N0 [ dB ] */	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT8 rac ; /**< Routing area code , range 0 -1 ( 1 bit ) */	 
 } CiDevUmtsASInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeActiveSetInfoInd_struct 
 {	 
 UINT8 NumCells ; /**< Number of cells in active set */	 
 UINT16 arfcn ; /**< Absolute Radio Frequency Channel Number ; number 0 -1023 */	 
 UINT8 res1U8 ; /**< ( padding ) */	 
 CiDevUmtsASInfo ASinfo [ 6 ] ; /**< Active Set Information. \sa CiDevUmtsASInfo_struct */	 
 } CiDevPrimUmtsEngmodeActiveSetInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsFddTddNeighborInfo_struct 
 {	 
 /* Measurements */	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power */	 
 INT16 utraRssi ; /**< UTRA carrier RSSI */	 
 INT16 cpichEcN0 ; /**< CPICH Ec / N0 , only valid for FDD */	 
 INT16 sQual ; /**< Cell selection quality ( Squal ) , only valid for FDD */	 
 INT16 sRxLev ; /**< Cell selection Rx level ( Srxlev ) */	 
	 
 /* PLMN / Cell Parameters */	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 ci ; /**< Cell Identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiBoolean set ; /* intra freq neighbor 1 : active ; 0 : 2 sync neighbor set , 3 Async neighbor set */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevUmtsFddTddNeighborInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsGsmNeighborInfo_struct 
 {	 
 /* Measurements */	 
 INT16 gsmRssi ; /**< GSM carrier RSSI */	 
 INT16 rxLev ; /**< Cell selection Rx level */	 
 INT16 C1 ; /**< Path loss criterion parameter #1 */	 
 INT16 C2 ; /**< Path loss criterion parameter #2 */	 
	 
 /* PLMN / Cell Parameters */	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 ci ; /**< Cell identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT8 bsic ; /**< Base transceiver station identity code ; range 0 h-3Fh ( 6 bits ) */	 
 UINT8 res1U8 ;	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 INT16 rank ; // rValueRscp ;	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevUmtsGsmNeighborInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeUmtsData_struct 
 {	 
 /* Serving Cell information */	 
 CiDevUmtsServingCellInfo svcCellInfo ; /**< Serving cell information. \sa CiDevUmtsServingCellInfo_struct */	 
 UINT8 LastsCellParamsListIndex ; /**< Number of serving cells in last serving cells list */	 
 CiDevUmtsServingCellParameters LastsCellParamsList [ 6 ] ; /**< PLMN / cell parameters of the list \sa CiDevUmtsServingCellParameters_struct */	 
	 
 CiDevPrimUmtsEngmodeActiveSetInfo ASInfo ; /**< Active set information \sa CiDevPrimUmtsEngmodeActiveSetInfoInd_struct */	 
	 
 /* Neighboring Cell information */	 
 UINT8 numIntraFreq ; /**< Number of intra-frequency FDD cells */	 
 UINT8 numInterFreq ; /**< Number of inter-frequency FDD cells */	 
 UINT8 numInterRAT ; /**< Number of inter-RAT GSM cells */	 
 /*Add by taow for SSG request to get RRC release casue 20140902 , CQ 69749 , , begin*/	 
 UINT8 numberOfRabs ; // in order to not impact current EM CI interface , this only used by call drop	 
 UINT16 ul_arfcn ; // in order to not impact current EM CI interface , this only used by call drop , CQ77239	 
 /*Add by taow for SSG request to get RRC release casue 20140902 , CQ 69749 , , end*/	 
	 
 CiDevUmtsFddTddNeighborInfo intraFreq [ 32 ] ; /**< Intra-frequency information \sa CiDevUmtsFddTddNeighborInfo_struct */	 
 CiDevUmtsFddTddNeighborInfo interFreq [ 32 ] ; /**< Inter-frequency information \sa CiDevUmtsFddTddNeighborInfo_struct */	 
 CiDevUmtsGsmNeighborInfo interRAT [ 32 ] ; /**< Inter-RAT information \sa CiDevUmtsGsmNeighborInfo_struct */	 
	 
 CiDevEngActivePDPContextinfoType activePDPContextinfo [ 7 ] ; /**< Active PDP context data \sa CiDevEngActivePDPContextinfoType_struct */	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiDevEngModeNcellInfoListLte nCellInfoListLte ; /**< LTE neighbor cells info list */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevEngModeUmtsData;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_ENG_MODE_STATE_TAG 
 {	 
 CI_DEV_LTE_ENGINEER_RRC_DEACTIVATED = 0 , /**< RRC DEACTIVATED */	 
 CI_DEV_LTE_ENGINEER_RRC_IDLE , /**< RRC IDLE */	 
 CI_DEV_LTE_ENGINEER_RRC_CONNECTED , /**< RRC CONNECTED */	 
 CI_DEV_LTE_ENGINEER_RRC_IRAT_RESELETCTION , /**< RRC RESELETCTION */	 
	 
 /* This must be the last entry */	 
 CI_DEV_NUM_LTE_ENGINEER_MODE_STATE	 
 } _CiDevLteEngModeState;

typedef UINT8 CiDevLteEngModeState ;
//ICAT EXPORTED ENUM 
 typedef enum CiDEV_LTE_ENG_L1_CONFIG_TYPE_TAG 
 {	 
 CI_DEV_LTE_ENG_INVALID_RRC_L1_CONFIG , // The IE is not initialized	 
 CI_DEV_LTE_ENG_NOTCHANGE_SETUP_RRC_L1_CONFIG , // The IE was setup and its value is not changed in this configuration	 
 CI_DEV_LTE_ENG_NOTCHANGE_RELEASE_RRC_L1_CONFIG , // The IE was released and its value is not changed in this configuration	 
 CI_DEV_LTE_ENG_SETUP_RRC_L1_CONFIG , // The IE ' s value is setup or configured	 
 CI_DEV_LTE_ENG_RELEASE_RRC_L1_CONFIG , // The IE ' s value is released	 
 CI_DEV_LTE_ENG_L1_CREATE_VALUE_CONFIG , // Used for NEED OP with absent flag only , only when the default value is maintained by L1	 
	 
 CI_DEV_LTE_ENG_RRC_L1_CONFIG_TYPE_INVALID = 0x7FFFFFFF	 
 } 
 _CiDevLteEngL1ConfigType;

typedef UINT8 CiDevLteEngL1ConfigType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngDrxConfig_struct 
 {	 
 // Timer for DRX in TS 36.321000 , value range ( 1 , 2 , 3 , 4 , 5 , 6 , 8 , 10 , 20 , 30 , 40 , 50 , 60 , 80 , 100 , 200 )	 
 UINT8 onDurationTimer ;	 
 // Timer for DRX in TS 36.321000 , value range ( 1 , 2 , 4 , 6 , 8 , 16 , 24 , 33 )	 
 UINT8 drxRetransmissionTimer ;	 
 // Drx inactivity timer in TS36.321 , value range ( 1 , 2 , 3 , 4 , 5 , 6 , 8 , 10 , 20 , 30 , 40 , 50 , 60 , 80 , 100 , 200 , 300 , 500 , 750 , 1280 , 1920 , 2560 )	 
 UINT16 drxInactivityTimer ;	 
	 
 // long DRX cycle , value range ( 10 , 20 , 32 , 40 , 64 , 80 , 128 , 160 , 256 , 320 , 512 , 640 , 1024 , 1280 , 2048 , 2560 )	 
 UINT16 longDrxCycle ;	 
 // drx Start offset , value range ( 0 ~2559 ) , this value should be less than longDrxCycle	 
 UINT16 drxStartOffset ;	 
	 
 // If this IE doesn ' t exists in ASN.1 message , value 0 for release should be filled here	 
 // Value range ( 2 , 5 , 8 , 16 , 20 , 32.400000 , 64 , 80 , 128 , 160 , 256 , 320 , 512 , 640 )	 
 UINT16 shortDrxCycle ;	 
 // If this IE doesn ' t exists in ASN.1 message , value 0 for release should be filled here	 
 // Value range:1~16	 
 UINT8 drxShortCycleTimer ;	 
 UINT8 reserved0 ;	 
	 
 // Configuration type of shortDrx	 
 CiDevLteEngL1ConfigType shortDrxConfigType ;	 
 } 
 CiDevLteEngDrxConfig;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLtePlmnIdentity_struct 
 {	 
 UINT16 mcc ;	 
 // Length of MNC , value range ( 2 , 3 )	 
 UINT8 lenOfMnc ;	 
 // 2 -3 digits of MNC	 
 UINT16 mnc ;	 
 } CiDevLtePlmnIdentity;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngScellParams_struct 
 {	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT16 mcc ;	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT16 mnc ; /**< 2 -3 digits of MNC */	 
 UINT16 tac ;	 
 UINT16 phyCellId ;	 
 UINT32 dlEuArfcn ;	 
 UINT32 ulEuArfcn ;	 
 UINT16 band ;	 
 UINT8 dlBandwidth ; /*0 - 1.400000 M , 1 - 3 M , 2 - 5 M , 3 - 10 M , 4 - 15 M , 5 - 20 M */	 
 UINT32 cellId ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 /*Added by taow for LTE EM L2 info , begin*/	 
 UINT8 subFrameAssignType ;	 
 UINT8 specialSubframePatterns ;	 
 UINT8 transMode ;	 
 /*Added by taow for LTE EM L2 info , end*/	 
	 
 /*Added by taow for Handover event info , begin*/	 
	 
 UINT32 totalHandoversCount ;	 
 UINT32 succeededHandoversCount ;	 
 /*Added by taow for Handover event info , begin*/	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiBoolean isTdd ;	 
 UINT8 subframeAssignment ; // only Valid if isTdd= TRUE , Value range: ( 0 , 1 , 2 , 3 , 4 , 5 , 6 ) , in SIB1 tdd-Config.	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00115868 , 20190815 , begin*/	 
 UINT32 succeededLteReselectionCount ;	 
 UINT32 succeededLteReestCounter ;	 
 UINT32 timeStayConnectedMode ; // seconds	 
 /*Lilei , CQ00115868 , 20190815 , end*/	 
 /*Lilei , CQ00126320 , 20201123 , begin*/	 
 CiBoolean longDRXCyclePresent ;	 
 UINT16 longDRXCycle ; /**< long DRX cycle in ms */	 
 CiBoolean shortDRXCyclePresent ;	 
 UINT16 shortDRXCycle ; /**< short DRX cycle in ms */	 
 UINT16 pagingCycle ; /**< The pagingCycle is configured in unit of 10 ms , aligned to 36.331000 */	 
 /*Lilei , CQ00126320 , 20201123 , end*/	 
 /*Lilei , CQ00134582 , 20211221 , begin*/	 
 UINT16 t3402 ; /**< timer T3402 in seconds */	 
 UINT16 t3412 ; /**< timer T3412 in seconds */	 
 /*Lilei , CQ00137275 , 20220616 , begin*/	 
 // UINT32 reserved1 ;	 
 INT8 refSignalPower ; /**< PDSCH-ConfigCommon.referenceSignalPower. Value range: -60~50 , invalid ( 0x7F ) . */	 
 UINT8 establishmentCause ; /**< RRC connection request cause */ /*Lilei , CQ00146454 , 20231023 */	 
 UINT16 reserved1 ;	 
 /*Lilei , CQ00137275 , 20220616 , end*/	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 /*Lilei , CQ00134582 , 20211221 , end*/	 
 } 
 CiDevLteEngScellParams;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngScellMeas_struct 
 {	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 INT8 sinr ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT8 mainRsrp ; /**< Rsrp of main antenna. Value range: 0 ~97 , invalid ( 0xFF ) */	 
 UINT8 diversityRsrp ; /**< Rsrp of diversity antenna. Value range: 0 ~97 , invalid ( 0xFF ) */	 
 UINT8 mainRsrq ; /**< Rsrq of main antenna. Value range: 0 ~34 , invalid ( 0xFF ) */	 
 UINT8 diversityRsrq ; /**< Rsrq of diversity antenna. Value range: 0 ~34 , invalid ( 0xFF ) */	 
 UINT8 rssi ; /**< Same value as CESQ rxlev */	 
 UINT16 cqi ; /**< Value range: 0 ~15 , invalid ( 0xFFFF ) . */	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 /*Added by taow for LTE EM L2 info , begin*/	 
 UINT8 pathLoss ;	 
 UINT32 tb0DlTpt ;	 
 UINT32 tb1DlTpt ;	 
 UINT32 tb0DlPeakTpt ;	 
 UINT32 tb1DlPeakTpt ;	 
 UINT32 tb0UlPeakTpt ;	 
 UINT32 tb1UlPeakTpt ;	 
 // EmacdlStatisticDataTag	 
 UINT32 dlThroughPut ; // dl throughtput unit bps , sum ( dl tb size in bits ) / dl statistic time duration	 
 UINT32 dlPeakThroughPut ; // Kbps	 
 UINT8 averDlPRB ;	 
 UINT8 averCQITb0 ;	 
 UINT8 averCQITb1 ;	 
 UINT8 rankIndex ;	 
 // EmaculStatisticDataTag	 
 UINT32 grantTotal ; // total received grant size in unit of BYTE	 
 UINT32 ulThroughPut ; // Kbps	 
 UINT32 ulPeakThroughPut ; // Kbps	 
 INT16 currPuschTxPower ;	 
 UINT8 averUlPRB ;	 
 // add by taow 20150415 begin	 
 UINT8 averULMcs ; // modify by taow 20190220	 
 UINT16 dlBler ;	 
 UINT16 ulBler ;	 
 /*modify by taow CQ00131112 20210621 begin*/	 
 // UINT32 reserved1 ;	 
 INT8 diversitySinr ;	 
 UINT8 diversityRssi ;	 
 UINT8 qRxLevMin ; /**< report value range [ 0 , 96 ] , real value range [ -140 , -44 ] , real value =IE value - 140 ; eg:0-140= -140 , 96 -140=-44*/	 
 /*Lilei , CQ00137040 , 20220527 , begin*/	 
 INT8 qQualMin ;	 
 // UINT8 reserved1_1 ;	 
 /*Lilei , CQ00137040 , 20220527 , end*/	 
 /*modify by taow CQ00131112 20210621 end*/	 
 /*Lilei , CQ00143212 , 20230424 , begin*/	 
 // UINT32 reserved2 ;	 
 INT8 mainSinr ; /**< SINR of main antenna */	 
 UINT8 mainRssi ; /**< RSSI of main antenna */	 
 UINT16 reserved2_1 ;	 
 /*Lilei , CQ00143212 , 20230424 , end*/	 
	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 // add by taow 20150415 end	 
 /*Added by taow for LTE EM L2 info , end*/	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 INT16 srxlev ;	 
 INT16 txPower ; // PUSCH tx power.	 
 UINT8 mainDLMcs ; /**< Modulation and coding scheme ( MCS ) of main antenna. Value range: 0 ~32 */	 
 UINT8 diversityDLMcs ; /**< Modulation and coding scheme ( MCS ) of diversity antenna. Value range: 0 ~32 */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00115868 , 20190815 , begin*/	 
 UINT8 averDlMcsTb0 ;	 
 UINT8 averDlMcsTb1 ;	 
 /*Lilei , CQ00115868 , 20190815 , end*/	 
 } 
 CiDevLteEngScellMeas;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLtePlmnIdentityInfo_struct 
 {	 
 CiDevLtePlmnIdentity plmnIdentity ;	 
 CiBoolean cellReservedForOperatorUse ;	 
 } CiDevLtePlmnIdentityInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RRC_CONFIG_TYPE_TAG 
 {	 
 CI_DEV_LTE_NOTPRESENT_RRC_CONFIG ,	 
 // PRESENT ,	 
 CI_DEV_LTE_SETUP_RRC_CONFIG ,	 
 CI_DEV_LTE_RELEASE_RRC_CONFIG	 
 } 
 _CiDevLteRrcConfigType;

typedef UINT8 CiDevLteRrcConfigType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngineerCellAccessRestrictions_struct 
 {	 
 UINT8 numOfPlmnInList ;	 
 CiDevLtePlmnIdentityInfo plmnIdentityList [ 6 ] ;	 
 // To identify a tracking area within the scope of a PLMN	 
 UINT16 trackingAreaCode ;	 
 // the IE is used to unambiguously identify a cll within a PLMN	 
 UINT32 cellIdentity ;	 
 CiBoolean cellBarred ;	 
 CiBoolean intraFreqReselAllowed ;	 
 CiBoolean csgIndication ;	 
 // Release or set up a closed subscriber group	 
 CiDevLteRrcConfigType csgIdentityR9ConfigType ;	 
 // to identify a Closed Subscriber Group , BIT STRING ( SIZE ( 27 ) )	 
 UINT32 csgIdentityR9 ;	 
	 
 } CiDevLteEngineerCellAccessRestrictions;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_ENGINEER_BARRED_STATUS_TAG 
 {	 
 CI_DEV_LTE_ENGINEER_NOT_BARRED ,	 
 CI_DEV_LTE_ENGINEER_BARRED_NO_SERVICE ,	 
 CI_DEV_LTE_ENGINEER_BARRED_EMERGENCY_ONLY	 
 } 
 _CiDevLteEngineerBarredStatus;

typedef UINT8 CiDevLteEngineerBarredStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteUeOperationStatus_struct 
 {	 
 CiDevLteEngModeState errcModeState ; /**< ERRC state \sa CiDevLteEngModeState */	 
 UINT8 emmState ; /**< EMM state */ /* see enum EmmState in Mmr_sig.h */	 
 UINT8 serviceState ; /**< Service state */ /* see enum ServiceStatus in Mmr_sig.h */	 
 CiBoolean IsSingleEmmRejectCause ; /**< TRUE - only one EMM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 UINT32 EMMRejectCause ; /**< Reported during the last engineering information period */	 
 UINT16 mmeGroupId ; /**< A member of GUTI */	 
 UINT8 mmeCode ; /**< A member of GUTI */	 
 UINT32 mTmsi ; /**< A member of GUTI */	 
 /*Lilei , CQ00126320 , 20201123 , begin*/	 
 CiDevServiceType serviceDomain ; /**< CS or PS domain , 0 :CS only ; 1 :PS only ; 2 :Combined CS / PS ; 3 :no service */	 
 /*Lilei , CQ00126320 , 20201123 , end*/	 
 } CiDevLteUeOperationStatus;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngScellInfo_struct 
 {	 
 CiDevLteEngScellParams params ;	 
 CiDevLteEngScellMeas meas ;	 
 // CiDevLteEngineerCellAccessRestrictions accessRestrictions ;	 
 // CiDevLteEngineerBarredStatus barredStatus ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 CiDevLteUeOperationStatus ueOpStatus ; /**< UE operation status \sa CiDevLteUeOperationStatus */	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 } 
 CiDevLteEngScellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngNcellSib1_struct 
 {	 
 // To indicate for cell re-selection the required minimum received RSRP level in the ( E-UTRA ) cell.	 
 // Corresponds to parameter Qrxlevmin in 36.304000 [ 4 ] . Actual value Qrxlevmin = IE value * 2 [ dBm ] .	 
 INT16 qRxLevMin ; // RHGUO: -140 ~ -44	 
 CiBoolean qRxLevMinOffsetPresent ;	 
 // Parameter Qrxlevminoffset in 36.304000 [ 4 ] . Actual value Qrxlevminoffset = IE value * 2 [ dB ] . If absent ,	 
 // apply the ( default ) value of 0 [ dB ] for Qrxlevminoffset. Affects the minimum required Rx level in the cell.	 
 UINT8 qRxLevMinOffset ;	 
 CiBoolean cellSelectionInfoV920Present ;	 
 INT8 qQualMinR9 ;	 
 CiBoolean qQualMinOffsetR9Present ;	 
 UINT8 qQualMinOffsetR9 ;	 
 } 
 CiDevLteEngNcellSib1;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngIntraFreqNcellInfo_struct 
 {	 
 UINT16 phyCellId ;	 
 UINT32 euArfcn ;	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 // CiBoolean ncellSib1Valid ;	 
 // CiDevLteEngNcellSib1 ncellSib1 ;	 
 // CiBoolean accessRestrictionsPresent ;	 
 // CiDevLteEngineerCellAccessRestrictions accessRestrictions ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT16 mcc ;	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT16 mnc ; /**< 2 -3 digits of MNC */	 
 UINT16 tac ;	 
 UINT32 cellId ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 INT16 srxlev ;	 
 // Value range:0~7 , Value 0 means lowest priority	 
 UINT8 cellReselectionPriority ;	 
 UINT8 sNonIntraSearch ;	 
 UINT8 threshServingLow ;	 
 UINT16 sIntraSearch ;	 
 // Int8 sinr // replace by rsrq ;	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00137275 , 20220630 , begin*/	 
 INT8 refSignalPower ; /**< PDSCH-ConfigCommon.referenceSignalPower. Value range: -60~50 , invalid ( 0x7F ) . */	 
 /*Lilei , CQ00137275 , 20220630 , end*/	 
 UINT8 reserved1_0 ;	 
 UINT16 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 } 
 CiDevLteEngIntraFreqNcellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngIntraFreqNcellList_struct 
 {	 
 UINT8 numberOfCells ;	 
 CiDevLteEngIntraFreqNcellInfo cellInfo [ 16 ] ;	 
 } 
 CiDevLteEngIntraFreqNcellList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngInterFreqNcellInfo_struct 
 {	 
 UINT16 phyCellId ;	 
 UINT32 euArfcn ;	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 // CiBoolean ncellSib1Valid ;	 
 // CiDevLteEngNcellSib1 ncellSib1 ;	 
 // CiBoolean accessRestrictionsPresent ;	 
 // CiDevLteEngineerCellAccessRestrictions accessRestrictions ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT16 mcc ;	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT16 mnc ; /**< 2 -3 digits of MNC */	 
 UINT16 tac ;	 
 UINT32 cellId ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 INT16 srxlev ;	 
 UINT8 threshXLow ; // Value range:0~31 received from SIB5	 
 UINT8 threshXHigh ; // Value range:0~31 received from SIB5	 
 UINT8 cellReselectionPriority ;	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 // Int8 sinr // replace by rsrq ;	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00137275 , 20220630 , begin*/	 
 INT8 refSignalPower ; /**< PDSCH-ConfigCommon.referenceSignalPower. Value range: -60~50 , invalid ( 0x7F ) . */	 
 /*Lilei , CQ00137275 , 20220630 , end*/	 
 UINT8 reserved1_0 ;	 
 UINT16 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 } 
 CiDevLteEngInterFreqNcellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngInterFreqNcellList_struct 
 {	 
 UINT8 numberOfCells ;	 
 CiDevLteEngInterFreqNcellInfo cellInfo [ 16 ] ;	 
 } 
 CiDevLteEngInterFreqNcellList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraCellParamsStruct 
 {	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT32 ci ; /**< Cell identity ; as per 3 G TS 25.331000 , 10.300000 .2.2 ( 28 bits ) */	 
 UINT16 uArfcn ;	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 // UINT16 phyCellId ;	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 UINT8 cellReselectionPriority ;	 
 UINT8 threshXHigh ; // Value range:0~31 received from SIB6	 
 UINT8 threshXLow ; // Value range:0~31 received from SIB6	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00134586 , 20211221 , begin*/	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 /*Lilei , CQ00134586 , 20211221 , end*/	 
 } 
 CiDevLteEngUtraCellParams;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraCellMeas_struct 
 {	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power ; in UMTS FDD / TDD messages RSCP is	 
 transmitted as an integer value in the range of -120 dBm to -25 dBm.	 
 The value is coded into integers from -5 to 99 according to 3 GPP ' s 25.133000 . */	 
 // INT16 pccpch_RSCP ; // for TDD	 
 INT16 cpichEcN0 ; // For FDD	 
 // INT16 cpichRscp ; // For FDD	 
 INT16 srxlev ; /*added by taow 20181107 CQ00112754 */	 
 } 
 CiDevLteEngUtraCellMeas;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraNcellInfo_struct 
 {	 
 CiDevLteEngUtraCellParams params ;	 
 CiDevLteEngUtraCellMeas meas ;	 
 } 
 CiDevLteEngUtraNcellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraCellList_struct 
 {	 
 UINT8 numberOfCells ;	 
 CiDevLteEngUtraNcellInfo cellInfo [ 16 ] ;	 
 } 
 CiDevLteEngUtraCellList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngBsic_struct 
 {	 
 // the lowest 0 ~2 bits of bsic store the bcc , the lowest 3 ~5 bit of bsic store the ncc	 
 UINT8 ncc ;	 
 UINT8 bcc ;	 
 } 
 CiDevLteEngBsic;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellParams_struct 
 {	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT32 ci ; /**< Cell identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 // UINT8 gsmBandIndicator ;	 
 // CiBoolean bsicPresent ; // ncc and bcc is valid only when bsicPresent is TURE.	 
 // CiDevLteEngBsic bsic ;	 
 UINT8 bsic ; /**< Base transceiver station identity code ; range 0 h-3Fh ( 6 bits ) ; 0xFF means not present */	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 UINT8 gsmBandIndicator ;	 
 UINT8 cellReselectionPriority ;	 
 UINT8 threshXHigh ; // Value range:0~31 received from SIB7	 
 UINT8 threshXLow ; // Value range:0~31 received from SIB7	 
 CiBoolean nccPermitted ;	 
 /*added by taow 20181107 CQ00112754 end*/	 
 /*Lilei , CQ00134586 , 20211221 , begin*/	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 /*Lilei , CQ00134586 , 20211221 , end*/	 
 } 
 CiDevLteEngGsmCellParams;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellMeas_struct 
 {	 
 INT16 rssi ; /**< GSM carrier RSSI */	 
 INT16 srxlev ; /*added by taow 20181107 CQ00112754 */	 
 } 
 CiDevLteEngGsmCellMeas;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellInfo_struct 
 {	 
 CiDevLteEngGsmCellParams params ;	 
 CiDevLteEngGsmCellMeas meas ;	 
 } 
 CiDevLteEngGsmCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellList_struct 
 {	 
 UINT8 numberOfCells ;	 
 CiDevLteEngGsmCellInfo cellInfo [ 16 ] ;	 
 } 
 CiDevLteEngGsmCellList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeSvcCellInfoInd_struct 
 {	 
 // CiDevLteEngModeState mode ; / **< Current mode ( deactivated / idle / connected / reselection ) \sa CiDevLteEngModeState * /	 
 CiBoolean sCellPresent ; /**< Whether serving cell engmode info is present */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevLteEngScellInfo info ; /**< Engineering mode LTE serving cell information \sa CiDevLteEngScellInfo */	 
 } CiDevPrimLteEngmodeScellInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeIntraFreqInfoInd_struct 
 {	 
 UINT8 numIntraFreq ; /**< Number of Intra-Frequency Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevLteEngIntraFreqNcellInfo intraFreq [ 16 ] ; /**< Intra-Frequency Info. \sa CiDevLteEngIntraFreqNcellInfo */	 
 } CiDevPrimLteEngmodeIntraFreqInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeInterFreqInfoInd_struct 
 {	 
 UINT8 numInterFreq ; /**< Number of Inter-Frequency Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevLteEngInterFreqNcellInfo interFreq [ 16 ] ; /**< Inter-Frequency Info. \sa CiDevLteEngInterFreqNcellInfo */	 
 } CiDevPrimLteEngmodeInterFreqInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeInterRatInfoInd_struct 
 {	 
 UINT8 numInterRATUtra ; /**< Number of Inter-RAT UMTS Cells */	 
 UINT8 numInterRATGsm ; /**< Number of Inter-RAT GSM Cells */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 CiDevLteEngUtraNcellInfo interRATUtra [ 16 ] ; /**< Inter-Rat UMTS Info. \sa CiDevLteEngUtraNcellInfo */	 
 CiDevLteEngGsmCellInfo interRATGsm [ 16 ] ; /**< Inter-Rat UMTS Info. \sa CiDevLteEngUtraNcellInfo */	 
 } CiDevPrimLteEngmodeInterRatInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeGsmDataInfo_struct 
 {	 
 CiDevEngModeGsmData data ; /* GSM data \sa CiDevEngModeGsmData_struct */	 
 CiDevEngActivePDPContextinfoType activePDPContextinfo [ 7 ] ; /* ActivePDPContext data. \sa CiDevEngActivePDPContextinfoType_struct */	 
 } CiDevEngModeGsmDataInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeGsmUmtsData_struct {	 
 CiDevEngModeUmtsData umtsData ; /**< UMTS Data. \sa CiDevEngModeUmtsData_struct */	 
 CiDevEngModeGsmDataInfo gsmData ; /**< GSM Data. \sa CiDevEngModeGsmDataInfo_struct */	 
 } CiDevEngModeGsmUmtsData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeLteData_struct 
 {	 
 // CiDevLteEngModeState errcModeState ; / **< RRC DEACTIVATED , IDLE , CONNECTED and RESELETCTION* /	 
	 
 CiBoolean sCellPresent ;	 
 CiBoolean intraFreqNcellsPresent ;	 
 CiBoolean interFreqNcellsPresent ;	 
 CiBoolean utraNcellsPresent ;	 
 CiBoolean gsmNcellsPresent ;	 
 CiBoolean sCellUpdated ; /**< wether svc cell has been updated or not */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
	 
 CiDevLteEngScellInfo sCell ;	 
 CiDevLteEngIntraFreqNcellList intraFreqNcells ;	 
 CiDevLteEngInterFreqNcellList interFreqNcells ;	 
 CiDevLteEngUtraCellList utraNcells ;	 
 CiDevLteEngGsmCellList gsmNcells ;	 
 } CiDevEngModeLteData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeInfo_struct 
 {	 
 CiDevEngModeState mode ; /**< Current mode ( idle / dedicated ) \sa CiDevEngModeState */	 
 CiDevEngModeNetwork network ; /**< Network type ( GSM / UMTS ) \sa CiDevEngModeNetwork */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
	 
 /* VADIM fix for CQ00082654 - debug only */	 
 CiDevEngModeGsmUmtsData *data ;	 
 /* UMTS or GSM Data -- depending on network type */	 
 /* UMTS or GSM Data -- depending on Network Type */	 
 // union	 
 // {	 
 // CiDevEngModeUmtsData umtsData ; / **< UMTS Data. \sa CiDevEngModeUmtsData_struct * /	 
 // CiDevEngModeGsmDataInfo gsmData ; / **< GSM Data. \sa CiDevEngModeGsmDataInfo_struct * /	 
 // } data ;	 
 /* VADIM fix for CQ00082654 - debug only */	 
	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 CiDevEngModeLteData *lteData ; /**< LTE Enginerring Mode Data */	 
 CiBoolean isDualLinkLteOn ; /**< Whether LTE is registered for dual link */	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 } CiDevEngModeInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimStatusInd_struct {	 
 CiDevStatus status ; /**< Device status \sa CiDevStatus */	 
 } CiDevPrimStatusInd;

typedef CiEmptyPrim CiDevPrimGetManuIdReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetManuIdCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiString manuStr ; /**< Manufacture ID string. Refer to " Cellular Interface Application Programming Interface " , revision i0.6. Max length is 2048 . \sa CCI API Ref Manual */	 
 } CiDevPrimGetManuIdCnf;

typedef CiEmptyPrim CiDevPrimGetModelIdReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetModelIdCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiString modelStr ; /**< Model ID string. Refer to " Cellular Interface Application Programming Interface " , revision i0.6. Max length is 2048 . \sa CCI API Ref Manual */	 
 } CiDevPrimGetModelIdCnf;

typedef CiEmptyPrim CiDevPrimGetRevisionIdReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetRevisionIdCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiString revisionStr ; /**< Revision ID string. Refer to " Cellular Interface Application Programming Interface " , revision i0.6. Max length is 2048 . \sa CCI API Ref Manual */	 
 } CiDevPrimGetRevisionIdCnf;

typedef CiEmptyPrim CiDevPrimGetSerialNumIdReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSerialNumIdCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiString serialNumStr ; /**< Serial number ID string. Refer to " Cellular Interface Application Programming Interface " , revision i0.6. Max length is 2048 . \sa CCI API Ref Manual */	 
 } CiDevPrimGetSerialNumIdCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetFuncReq_struct {	 
 CiDevFunc func ; /**< Functionality , related to the power level a phone should draw. \sa CiDevFunc */	 
 CiBoolean reset ; /**< TRUE - Reset before setting to functionality power level ; FALSE - No reset before setting ( default ) \sa CCI API Ref Manual */	 
 CiBoolean IsCommFeatureConfig ; /**< TRUE - CommFeatureConfig should be changed , next field present */	 
 CiBitRange CommFeatureConfig ; /**< communication feature configuration Enable / Disable like CSD / FAX / etc */	 
 } CiDevPrimSetFuncReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetFuncCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 } CiDevPrimSetFuncCnf;

typedef CiEmptyPrim CiDevPrimGetFuncReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetFuncCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiDevFunc func ; /**< Functionality , related to the power level a phone should draw. \sa CiDevFunc */	 
 CiBitRange CommFeatureConfig ; /**< communication feature configuration Enable / Disable like CSD / FAX / etc */	 
 } CiDevPrimGetFuncCnf;

typedef CiEmptyPrim CiDevPrimGetFuncCapReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetFuncCapCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiBitRange bitsFunc ; /**< Supported functionality setting. Refer to " Cellular Interface Application Programming Interface " , revision i0.6. \sa CCI API Ref Manual */	 
 CiBitRange bitsReset ; /**< Supported reset setting. Refer to " Cellular Interface Application Programming Interface " , revision i0.6. \sa CCI API Ref Manual */	 
 } CiDevPrimGetFuncCapCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetGsmPowerClassReq_struct {	 
 CiDevBand band ;	 
 CiDevPwCls pwcls ;	 
 } CiDevPrimSetGsmPowerClassReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetGsmPowerClassCnf_struct {	 
 CiDevRc rc ;	 
 } CiDevPrimSetGsmPowerClassCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetGsmPowerClassReq_struct {	 
 CiDevBand band ;	 
 } CiDevPrimGetGsmPowerClassReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetGsmPowerClassCnf_struct {	 
 CiDevRc rc ;	 
 CiDevPwCls curPwCls ;	 
 CiDevPwCls defPwCls ;	 
 } CiDevPrimGetGsmPowerClassCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetGsmPowerClassCapReq_struct {	 
 CiDevBand band ;	 
 } CiDevPrimGetGsmPowerClassCapReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetGsmPowerClassCapCnf_struct {	 
 CiDevRc rc ;	 
 CiBitRange bitsPwCls ;	 
 } CiDevPrimGetGsmPowerClassCapCnf;

typedef CiEmptyPrim CiDevPrimPmPowerDownReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimPmPowerDownCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 } CiDevPrimPmPowerDownCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetEngmodeRepOptReq_struct 
 {	 
 CiDevEngModeReportOption type ; /**< Report type \sa CiDevEngModeReportOption */	 
 UINT16 interval ; /**< Report interval ( in seconds ) for PERIODIC */	 
 } CiDevPrimSetEngmodeRepOptReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetEngmodeRepOptCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ;	 
 } CiDevPrimSetEngmodeRepOptCnf;

//ICAT EXPORTED ENUM 
 typedef enum CiDEVENGMODETYPE_TAG {	 
 CI_DEV_ENGINEER_MODE_NONE= 0 , /**< worked with AT+ EEMOPT ; step1: AT+ EEMOPT , step2: AT+EEMGINFO? ; */	 
 CI_DEV_ENGINEER_MODE_NORMAL , /**< no used in oneshot mode AT+EEMGNFO? occupy a position*/	 
 CI_DEV_ENGINEER_MODE_ONESHOT , /**< used in oneshot mode AT+EEMGNFO? may include Ncell info*/	 
 CI_DEV_ENGINEER_MODE_ONESHOT_NCELL_REQUIRED , /**< used in oneshot mode AT+EEMGNFO?.must decode system info to get Ncell , but in the end , may still not get NCELL. this cost 7 s*/	 
 CI_DEV_ENGINEER_MODE_MAX	 
	 
 } _CiDevEngmodeType;

typedef UINT8 CiDevEngmodeType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetEngmodeInfoReq_struct 
 {	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiDevEngmodeType engmodeEnhanceType ; /**< enhancement request: until all engineer IND msgs from AS were recieved , sac send request confirm to AP */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevPrimGetEngmodeInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetEngmodeInfoCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiDevEngModeState mode ; /**< Current mode ( idle / dedicated ) \sa CiDevEngModeState */	 
 CiDevEngModeNetwork network ; /**< Network type ( GSM / UMTS ) \sa CiDevEngModeNetwork */	 
 } CiDevPrimGetEngmodeInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimEngmodeInfoInd_struct 
 {	 
 CiDevEngModeInfo info ;	 
 } CiDevPrimEngmodeInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGsmEngmodeInfoInd_struct 
 {	 
 CiDevEngModeState mode ; /**< Current Mode ( Idle / Dedicated ) . \sa CiDevEngModeState */	 
 UINT8 releaseVersion ; /**< 3 GPP release versions */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 CiDevEngModeGsmData info ; /**< GSM Engineering Mode information. \sa CiDevEngModeGsmData_struct */	 
 } CiDevPrimGsmEngmodeInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeSvcCellInfoInd_struct 
 {	 
 CiDevEngModeState mode ; /**< Current mode ( idle / dedicated ) \sa CiDevEngModeState */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsServingCellInfo info ; /**< Engineering mode 3 G ( UMTS ) serving cell information \sa CiDevUmtsServingCellInfo_struct */	 
 } CiDevPrimUmtsEngmodeScellInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeIntraFreqInfoInd_struct 
 {	 
 UINT8 numIntraFreq ; /**< Number of Intra-Frequency FDD Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsFddTddNeighborInfo intraFreq [ 32 ] ; /**< Intra-Frequency Info. \sa CiDevUmtsFddTddNeighborInfo_struct */	 
 } CiDevPrimUmtsEngmodeIntraFreqInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeInterFreqInfoInd_struct 
 {	 
 UINT8 numInterFreq ; /**< Number of Inter-Frequency FDD Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsFddTddNeighborInfo interFreq [ 32 ] ; /**< Inter-Frequency Info. \sa CiDevUmtsFddTddNeighborInfo_struct */	 
 } CiDevPrimUmtsEngmodeInterFreqInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeInterRatInfoInd_struct 
 {	 
 UINT8 numInterRAT ; /**< Number of Inter-RAT GSM Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsGsmNeighborInfo interRAT [ 32 ] ; /**< Inter-Rat Info. \sa CiDevUmtsGsmNeighborInfo_struct */	 
 /*added by taow 20181107 CQ00112754 begin*/	 
 CiDevEngModeNcellInfoListLte nCellInfoListLte ; /**< LTE neighbor cells info list */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevPrimUmtsEngmodeInterRatInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetEngmodeNcellReportOptionReq_struct {	 
 CiBoolean enable ; /**< Enable ( 1 ) / disable ( 0 ) neighbor cell info report */	 
 UINT16 interval ; /**< Periodic report interval ( in seconds ) , default 2 seconds */	 
 } CiDevPrimSetEngmodeNcellReportOptionReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetEngmodeNcellReportOptionCnf_struct {	 
 CiDevRc result ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetEngmodeNcellReportOptionCnf;

typedef CiEmptyPrim CiDevPrimGetEngmodeNcellInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetEngmodeNcellInfoCnf_struct {	 
 CiDevRc result ; /**< Result code. \sa CiDevRc */	 
 CiDevEngModeNetwork network ; /**< Current network type. \sa CiDevEngModeNetwork */	 
 CiDevEngModeNcellInfoListGsm nCellInfoListGsm ; /**< GSM neighbor cells info list */	 
 CiDevEngModeNcellInfoListUmts nCellInfoListUmts ; /**< UMTS neighbor cells info list */	 
 CiDevEngModeNcellInfoListLte nCellInfoListLte ; /**< LTE neighbor cells info list */	 
 } CiDevPrimGetEngmodeNcellInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimEngmodeNcellInfoInd_struct {	 
 CiDevEngModeNetwork network ; /**< Current network type. \sa CiDevEngModeNetwork */	 
 CiDevEngModeNcellInfoListGsm nCellInfoListGsm ; /**< GSM neighbor cells info list */	 
 CiDevEngModeNcellInfoListUmts nCellInfoListUmts ; /**< UMTS neighbor cells info list */	 
 CiDevEngModeNcellInfoListLte nCellInfoListLte ; /**< LTE neighbor cells info list */	 
 } CiDevPrimEngmodeNcellInfoInd;

//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_SELF_TEST_RESULT 
 {	 
 CI_DEV_SELF_TEST_OK ,	 
 CI_DEV_SELF_TEST_FAILURE ,	 
 CI_DEV_SELF_TEST_INCOMPATIBLE_SW_VERSION ,	 
 CI_DEV_SELF_TEST_ILLEGAL_BATTERY ,	 
	 
 CI_DEV_NUM_SELF_TEST_RESULTS	 
	 
 } _CiDevSelfTestResult;

typedef UINT8 CiDevSelfTestResult ;
//ICAT EXPORTED ENUM 
 typedef enum CI_DEV_RFS_LEVEL 
 {	 
 CI_DEV_RFS_USER_LEVEL ,	 
 CI_DEV_RFS_DEEP_LEVEL ,	 
	 
 CI_DEV_NUM_RFS_LEVEL	 
	 
 } _CiDevRfsLevel;

typedef UINT8 CiDevRfsLevel ;
//ICAT EXPORTED ENUM 
 typedef enum CiDEVLPRRCSTATE_TAG 
 {	 
 CI_DEV_LP_RRC_STATE_CELL_DCH = 0 , /**< RRC state CELL DCH */	 
 CI_DEV_LP_RRC_STATE_CELL_FACH , /**< RRC state CELL FACH */	 
 CI_DEV_LP_RRC_STATE_CELL_PCH , /**< RRC state CELL PCH */	 
 CI_DEV_LP_RRC_STATE_URA_PCH , /**< RRC state URA PCH */	 
 CI_DEV_LP_RRC_STATE_IDLE /**< RRC state idle */	 
 } _CiDevLpRRCState;

typedef UINT8 CiDevLpRRCState ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVLPBEARERTYPE_TAG 
 {	 
 CI_DEV_LP_RRC = 0 , /**< RRC */	 
 CI_DEV_LP_RRLP , /**< Radio resource location protocol */	 
 CI_DEV_LP_RRC_SIB15 , /**< RRC SIB15 */	 
 CI_DEV_LP_SS_AGPS_ASSIST_REQ , /**< Supplementary service AGPS assist request */	 
 CI_DEV_LP_LPP , /**< LPP container */	 
 CI_DEV_LP_LCS , /**< LCS container */	 
 CI_DEV_LP_RRC_UL_EXT , /**<RRC with uplink extensions support , added by lalon for CQ00094785 begin */	 
 CI_DEV_LP_NUM_OF_BEARER_TYPE	 
 } _CiDevLpBearerType;

typedef UINT8 CiDevLpBearerType ;
//ICAT EXPORTED ENUM 
 typedef enum CiDEVLPSESSIONTYPE_TAG 
 {	 
 CI_DEV_LP_NO_EMERGENCY = 0x0 , /**< Not an emergency call */	 
 CI_DEV_LP_EMERGENCY /**< An emergency call */	 
 } _CiDevLpSessionType;

typedef UINT8 CiDevLpSessionType ;
//ICAT EXPORTED ENUM 
 typedef enum CiDevNetworkType_Tag 
 {	 
 CI_DEV_NETWORK_TYPE_GERAN = 0x0 ,	 
 CI_DEV_NETWORK_TYPE_UTRAN ,	 
 CI_DEV_NETWORK_TYPE_EUTRAN ,	 
	 
 CI_DEV_NUM_NETWORK_TYPES	 
 } _CiDevNetworkType;

typedef UINT8 CiDevNetworkType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpNwdlMsgInd_struct {	 
 CiDevLpBearerType BearerType ; /**< Bearer type information \sa CiDevLpBearerType */	 
 UINT8 msg_data [ 1500 ] ; /**< Encoded RRLP / RRC data */	 
 UINT32 msg_size ; /**< Size of data , include all fragments */	 
 CiDevLpSessionType sessionType ; /**< Session type information \sa CiDevLpSessionType */	 
 CiDevLpRRCState RrcState ; /**< RRC state \sa CiDevLpRRCState */	 
 UINT8 count ; /**< Ordinal number of the message / fragment */	 
 UINT8 additional_info_len ; /**< Length of the additional information. If length is zero , than the additional information is not present.*/	 
 UINT8 additional_info [ 4 ] ; /**< Contains the value of the additional information element. Used for Routing Identifier ( 24.171000 ) */	 
 } CiDevPrimLpNwdlMsgInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpNwulMsgReq_struct {	 
 UINT8 msg_data [ 480 ] ; /**< OTA message */	 
 UINT32 msg_data_len ; /**< Size of data , include all fragments */	 
 UINT8 count ; /**< Ordinal number of the message / fragment */	 
 CiDevLpBearerType bearer_type ; /**< Radio bearer type \sa CiDevLpBearerType */	 
 CiBoolean isFinalResponse ; /**< Indication that this message is the last message in the AGPS session \sa CCI API Ref Manual */	 
 UINT8 additional_info_len ; /**< Length of the additional information. If length is zero , than the additional information is not present.*/	 
 UINT8 additional_info [ 4 ] ; /**< Contains the value of the additional information element. Used for Routing Identifier ( 24.171000 ) */	 
 } CiDevPrimLpNwulMsgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpNwulMsgCnf_struct {	 
 CiDevRc result ; /**< Result code \sa CiDevRc. */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimLpNwulMsgCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevNmrCellResult_struct 
 {	 
 UINT16 arfcn ;	 
 UINT8 bsic ;	 
 UINT8 rxLev ;	 
 } CiDevNmrCellResult;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcidInfoGsm_struct 
 {	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 UINT16 lac ;	 
 UINT16 ci ;	 
 UINT8 numOfCells ;	 
 CiDevNmrCellResult nmrCellResult [ 32 ] ; /**< Network measurement result */	 
 CiBoolean taPresent ;	 
 UINT8 timingAdv ;	 
 } CiDevEcidInfoGsm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCellResult_struct 
 {	 
 CiBoolean ucidPresent ;	 
 UINT32 ucid ; /**< Cell identiy */	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 UINT8 cpichRscp ; /**< FDD only */	 
 UINT8 cpichEcN0 ; /**< FDD only */	 
 CiBoolean pathLossPresent ;	 
 UINT16 pathLoss ;	 
 } CiDevCellResult;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCellResultList_struct 
 {	 
 UINT8 numOfCells ;	 
 CiDevCellResult cellResult [ 32 ] ;	 
 } CiDevCellResultList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUtraMeasResult_struct 
 {	 
 UINT16 uarfcnDl ;	 
 UINT16 rssi ;	 
 CiDevCellResultList cellResultList ;	 
 } CiDevUtraMeasResult;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUtraMeasResultList_struct 
 {	 
 UINT8 numUtraReportedFreqs ;	 
 CiDevUtraMeasResult utraMeasResult [ 3 ] ;	 
 } CiDevUtraMeasResultList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcidInfoUtra_struct 
 {	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 UINT32 ucid ;	 
 UINT16 uarfcnDl ;	 
 UINT16 uarfcnUl ;	 
 UINT16 psc ;	 
 CiBoolean MeasResultPresent ;	 
 CiDevUtraMeasResultList measResult ;	 
 } CiDevEcidInfoUtra;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCellGlobalIdEutra_struct 
 {	 
 CiBoolean mccPresent ;	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 UINT32 cellId ;	 
 } CiDevCellGlobalIdEutra;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcidMeasuredResultsElement_struct 
 {	 
 UINT16 physCellId ;	 
 CiBoolean cgiPresent ;	 
 CiDevCellGlobalIdEutra cellGlobalId ;	 
 UINT32 arfcnEutra ;	 
 CiBoolean sfnPresent ;	 
 UINT16 systemFrameNumber ;	 
 CiBoolean rsrpPresent ;	 
 UINT8 rsrp ;	 
 CiBoolean rsrqPresent ;	 
 UINT8 rsrq ;	 
 CiBoolean rxTxTimeDiffPresent ;	 
 UINT16 rxTxTimeDiff ; /**< UE RX-TX time difference measurement. Only valid for measurements of the primary cell */	 
 CiBoolean taPresent ;	 
 UINT16 timingAdvance ;	 
 CiBoolean tacPresent ;	 
 UINT16 trackingAreaCode ;	 
 } CiDevEcidMeasuredResultsElement;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcidSignalMeasInfo_struct 
 {	 
 CiBoolean primaryCellMeasuredResultsPresent ;	 
 CiDevEcidMeasuredResultsElement primaryCellMeasuredResults ; /**< Measurements for the primary cell. It ' s omitted when only primary cell measurements are reported ,	 
 in which case the measurements of the primary cell are reported in the measuredResultsList */	 
 UINT8 measuredResultsListLength ;	 
 CiDevEcidMeasuredResultsElement measuredResultsList [ 32 ] ;	 
 } CiDevEcidSignalMeasInfo;

//ICAT EXPORTED ENUM 
 typedef enum ECID_ERROR_CAUSES_ENUM 
 {	 
 CI_DEV_ECID_ERROR_CAUSE_UNDEFINED = 0x00 ,	 
 CI_DEV_ECID_ERROR_CAUSE_REQUESTED_MEASUREMENT_NOT_AVAILABLE ,	 
 CI_DEV_ECID_ERROR_CAUSE_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE ,	 
 CI_DEV_ECID_ERROR_CAUSE_RESERVED = 0xFF	 
 } _EcidErrorCauses;

typedef UINT8 EcidErrorCauses ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcidError_struct 
 {	 
 EcidErrorCauses ecidErrorCauses ;	 
 CiBoolean rsrpMeasurementNotPossible ; /**< Only for ERROR_CAUSE_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE */	 
 CiBoolean rsrqMeasurementNotPossible ; /**< Only for ERROR_CAUSE_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE */	 
 CiBoolean ueRxTxMeasurementNotPossible ; /**< Only for ERROR_CAUSE_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE */	 
 } CiDevEcidError;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcidInfoEutra_struct 
 {	 
 CiBoolean ecidSignalMeasInfoPresent ;	 
 CiDevEcidSignalMeasInfo ecidSignalMeasInfo ;	 
 CiBoolean ecidErrorPresent ;	 
 CiDevEcidError ecidError ;	 
 } CiDevEcidInfoEutra;

//ICAT EXPORTED UNION 
 typedef union CiDevEcidInfo_union 
 {	 
 CiDevEcidInfoGsm gsmInfo ;	 
 CiDevEcidInfoUtra utraInfo ;	 
 CiDevEcidInfoEutra eutraInfo ;	 
 } CiDevEcidInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpEcidMeasReq_struct 
 {	 
 UINT8 ecidMeasRequested ; /**< bit 0 : rsrpReq ; bit1: rsrqReq ; bit2: ueRxTxTimeDiffReq ; bit3-bit7: reserved. */	 
 } CiDevPrimLpEcidMeasReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpEcidMeasCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc. */	 
 CiDevNetworkType networkType ; /**< EUTRAN , UTRAN , or GERAN */	 
 CiDevEcidInfo info ;	 
 } CiDevPrimLpEcidMeasCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEcgi_struct 
 {	 
 CiDevLtePlmnIdentity plmnIdentity ;	 
 UINT32 cellIdentity ; /* 0 to 268435455 */	 
 } CiDevEcgi;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrsInfo_struct 
 {	 
 UINT8 prsBandwidth ; /**< Specified in number of resource blocks. Value range: 6 , 15 , 25 , 50 , 75 , 100 */	 
 UINT16 prsConfigIndex ; /**< Value range: 0 - 4095 */	 
 UINT8 numDLFrames ; /**< The number of consecutive DL subframes. Value range: 1 , 2 , 4 , 6 */	 
 CiBoolean prsMutingInfoR9Present ;	 
 UINT8 prsMutingInfoR9LenInBit ; /**< PRS muting sequence length in bits. Value range: 2 , 4 , 8 , 16 */	 
 UINT16 prsMutingInfoR9 ; /**< PRS muting sequence */	 
 } CiDevPrsInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaReferenceCellInfo_struct 
 {	 
 UINT16 physCellId ; /**< Physical cell identity of the assistance data reference cell. Value range: 0 -503 */	 
 CiBoolean cgiPresent ;	 
 CiDevEcgi cellGlobalId ; /**< ECGI of the assistance data reference cell. */	 
 CiBoolean earfcnRefPresent ; /**< TRUE if not same as primary cell , otherwise FALSE. */	 
 UINT32 earfcnRef ; /**< EARFCN of the assistance data reference cell. */	 
 CiBoolean antennaPortConfigPresent ; /**< TRUE if not same as primary cell , otherwise FALSE. */	 
 UINT8 antennaPortConfig ; /**< The number of antenna ports for cell specific reference signals ( CRS ) . 0 : 1 or 2 port ( s ) ; 1 : 4 ports */	 
 UINT8 cpLength ; /**< Cyclic prefix length of PRS if prsInfo is present , otherwise of CRS. 0 : normal ; 1 : extended */	 
 CiBoolean prsInfoPresent ;	 
 CiDevPrsInfo prsInfo ; /**< PRS configuration of the assistance data reference cell. */	 
 } CiDevOtdoaReferenceCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaNeighbouCellInfoElement_struct 
 {	 
 UINT16 physCellId ; /**< Physical cell identity of the neighbour cell. Value range: 0 -503 */	 
 CiBoolean cgiPresent ;	 
 CiDevEcgi cellGlobalId ; /**< ECGI of the neighbour cell. */	 
 CiBoolean earfcnRefPresent ; /**< TRUE if not same as assistance data reference cell , otherwise FALSE. */	 
 UINT32 earfcnNbr ; /**< EARFCN of the neighbour cell. */	 
 CiBoolean cpLengthPresent ; /**< TRUE if not same as assistance data reference cell , otherwise FALSE. */	 
 UINT8 cpLength ; /**< Cyclic prefix length of PRS if prsInfo is present , otherwise of CRS. 0 : normal ; 1 : extended */	 
 CiBoolean prsInfoPresent ; /**< TRUE if not same as assistance data reference cell , otherwise FALSE. */	 
 CiDevPrsInfo prsInfo ; /**< PRS configuration */	 
 CiBoolean antennaPortConfigPresent ; /**< TRUE if not same as assistance data reference cell , otherwise FALSE. */	 
 UINT8 antennaPortConfig ; /**< The number of antenna ports for cell specific reference signals ( CRS ) . 0 : 1 or 2 port ( s ) ; 1 : 4 ports */	 
 CiBoolean slotNumberOffsetPresent ; /**< TRUE if not same as assistance data reference cell , otherwise FALSE. */	 
 UINT8 slotNumberOffset ; /**< Slot number offset at the transmitter between this cell and the assistance data reference cell. Value range: 0 -19 */	 
 CiBoolean prsSubframeOffsetPresent ;	 
 UINT16 prsSubframeOffset ; /**< Value range: 0 -1279 */	 
 UINT16 expectedRSTD ; /**< Value range: 0 -16383 */	 
 UINT16 expectedRSTDUncertainty ; /**< Value range: 0 -1023 */	 
 } CiDevOtdoaNeighbouCellInfoElement;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaNeighbourFreqInfo_struct 
 {	 
 UINT8 otdoaNeighbouCellInfoListLength ;	 
 CiDevOtdoaNeighbouCellInfoElement otdoaNeighbouCellInfoList [ 24 ] ;	 
 } CiDevOtdoaNeighbourFreqInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaNeighbourCellInfoList_struct 
 {	 
 UINT8 otdoaNeighbourFreqInfoNum ;	 
 // CiDevOtdoaNeighbourFreqInfo otdoaNeighbourFreqInfo [ CI_DEV_MAX_NUM_OTDOA_FREQ_LAYERS ] ;	 
 UINT8 otdoaNeighbourFreqCellNum [ 3 ] ; // Each element indicates how many cells belong to each frequency layer	 
 UINT8 otdoaNeighbouCellInfoListLength ;	 
 CiDevOtdoaNeighbouCellInfoElement otdoaNeighbouCellInfoList [ 24 ] ; // Totally a maximum of 24 cells	 
 } CiDevOtdoaNeighbourCellInfoList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaAssistanceData_struct 
 {	 
 CiBoolean otdoaReferenceCellInfoPresent ;	 
 CiDevOtdoaReferenceCellInfo otdoaReferenceCellInfo ;	 
 CiBoolean otdoaNeighbourCellInfoListPresent ;	 
 CiDevOtdoaNeighbourCellInfoList otdoaNeighbourCellInfoList ;	 
 } CiDevOtdoaAssistanceData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpOtdoaMeasReq_struct 
 {	 
 CiDevOtdoaAssistanceData otdoaAssistanceData ;	 
 } CiDevPrimLpOtdoaMeasReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpOtdoaMeasCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc. */	 
 } CiDevPrimLpOtdoaMeasCnf;

typedef CiEmptyPrim CiDevPrimLpOtdoaMeasAbortReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpOtdoaMeasAbortCnf_struct 
 {	 
 CiDevRc rc ;	 
 } CiDevPrimLpOtdoaMeasAbortCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaMeasQuality_struct 
 {	 
 UINT8 errorResolution ; /**< Resolution R. ' 0 ' : 5 meters ; ' 1 ' : 10 meters ; ' 10 ' : 20 meters ; ' 11 ' : 30 meters */	 
 UINT8 errorValue ; /**< Best estimate of the uncertainty of measurement.	 
 ' 0 ' : 0 - ( R*1-1 ) meters ;	 
 ' 1 ' : R*1 - ( R*2-1 ) meters ;	 
 ' 10 ' : R*2 - ( R*3-1 ) meters ;	 
 ...	 
 ' 11111 ' : R*31 meters or more */	 
 CiBoolean errorNumSamplesPresent ;	 
 UINT8 errorNumSamples ; /**< Measurements sample size.	 
 ' 0 ' : Not the baseline metric ( default value ) ;	 
 ' 1 ' : 5 -9 ;	 
 ' 10 ' : 10 -14 ;	 
 ' 11 ' : 15 -24 ;	 
 ' 100 ' : 25 -34 ;	 
 ' 101 ' : 53 -44 ;	 
 ' 110 ' : 45 -54 ;	 
 ' 111 ' : 55 or more */	 
 } CiDevOtdoaMeasQuality;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaNeighbourMeasurementElement_struct 
 {	 
 UINT16 physCellIdNeighbour ; /**< Physical cell identity of the neighbour cell. Value range: 0 -503 */	 
 CiBoolean cgiNeighbourPresent ;	 
 CiDevEcgi cellGlobalIdNeighbour ; /**< ECGI of the neighbour cell. */	 
 CiBoolean earfcnNeighbourPresent ; /**< TRUE if not same as RSTD reference cell , otherwise FALSE. */	 
 UINT32 earfcnNeighbour ; /**< EARFCN of the neighbour cell. */	 
 UINT16 rstd ; /**< Relative timing difference between this eighbour cell and the RSTD reference cell. Value range: 0 -12711 */	 
 CiDevOtdoaMeasQuality rstdQuality ; /**< Best estimate of the quality of the measured rstd. */	 
 } CiDevOtdoaNeighbourMeasurementElement;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaNeighbourMeasurementList_struct 
 {	 
 UINT8 otdoaNeighbourMeasurementListLength ;	 
 CiDevOtdoaNeighbourMeasurementElement otdoaNeighbourMeasurementList [ 24 ] ;	 
 } CiDevOtdoaNeighbourMeasurementList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaSignalMeasInfo_struct 
 {	 
 UINT16 systemFrameNumber ; /**< SFN of the RSTD reference cell. */	 
 UINT16 physCellIdRef ; /**< Physical cell identity of the RSTD reference cell. Value range: 0 -503 */	 
 CiBoolean cgiRefPresent ;	 
 CiDevEcgi cellGlobalIdRef ; /**< ECGI of the RSTD reference cell. */	 
 CiBoolean earfcnRefPresent ; /**< TRUE if not same as assistance data reference cell , otherwise FALSE. */	 
 UINT32 earfcnRef ; /**< EARFCN of the RSTD reference cell. */	 
 CiBoolean referenceQualityPresent ;	 
 CiDevOtdoaMeasQuality referenceQuality ; /**< Best estimate of the quality of TOA measurement from the RSTD reference cell. */	 
 CiDevOtdoaNeighbourMeasurementList neighbourMeasurementList ;	 
 } CiDevOtdoaSignalMeasInfo;

//ICAT EXPORTED ENUM 
 typedef enum OTDOA_ERROR_CAUSES_ENUM 
 {	 
 CI_DEV_OTDOA_ERROR_CAUSE_UNDEFINED = 0x00 ,	 
 CI_DEV_OTDOA_ERROR_CAUSE_ASSISTANCE_DATA_MISSING ,	 
 CI_DEV_OTDOA_ERROR_CAUSE_UNABLE_TO_MEASURE_REFERENCE_CELL ,	 
 CI_DEV_OTDOA_ERROR_CAUSE_UNABLE_TO_MEASURE_ANY_NEIGHBOUR_CELL ,	 
 CI_DEV_OTDOA_ERROR_CAUSE_ATTEMPTED_BUT_UNABLE_TO_MEASURE_SOME_NEIGHBOUR_CELLS ,	 
 CI_DEV_OTDOA_ERROR_CAUSE_RESERVED = 0xFF	 
 } _OtdoaErrorCauses;

typedef UINT8 OtdoaErrorCauses ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaError_struct 
 {	 
 OtdoaErrorCauses otdoaErrorCauses ;	 
 } CiDevOtdoaError;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevOtdoaInfoEutra_struct 
 {	 
 CiBoolean otdoaSignalMeasInfoPresent ;	 
 CiDevOtdoaSignalMeasInfo otdoaSignalMeasInfo ;	 
 CiBoolean otdoaErrorPresent ;	 
 CiDevOtdoaError otdoaError ;	 
 } CiDevOtdoaInfoEutra;

//ICAT EXPORTED UNION 
 typedef union CiDevOtdoaInfo_union 
 {	 
 // CiDevOtdoaInfoUtra utraInfo ; // TBD	 
 CiDevOtdoaInfoEutra eutraInfo ;	 
 } CiDevOtdoaInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpOtdoaMeasInd_struct 
 {	 
 CiDevNetworkType networkType ; /**< EUTRAN , UTRAN , or GERAN */	 
 CiDevOtdoaInfo info ;	 
 } CiDevPrimLpOtdoaMeasInd;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LOCATION_COORDINATE_TYPE_ENUM 
 {	 
 CiDevLocCoordType_EllipsoidPoint = 0x00 ,	 
 CiDevLocCoordType_EllipsoidPointWithAltitude ,	 
 CiDevLocCoordType_EllipsoidPointWithUncertaintyCircle ,	 
 CiDevLocCoordType_EllipsoidPointWithUncertaintyEllipse ,	 
 CiDevLocCoordType_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid ,	 
 CiDevLocCoordType_EllipsoidArc ,	 
 CiDevLocCoordType_Polygon ,	 
 CiDevLocCoordType_Reserved = 0xFF	 
 } _CiDevLocationCoordinateType;

typedef UINT8 CiDevLocationCoordinateType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevLocationInfo_struct 
 {	 
 CiDevLocationCoordinateType locationCoordinateType ;	 
 UINT8 locationCoordinateLength ;	 
 UINT8 locationCoordinate [ 20 ] ;	 
 CiBoolean horizontalVelocityPresent ;	 
 UINT8 horizontalVelocityLength ;	 
 UINT8 horizontalVelocity [ 4 ] ;	 
 CiBoolean gnssTODMsecPresent ;	 
 UINT8 gnssTODMsecLength ;	 
 UINT8 gnssTODMsec [ 4 ] ;	 
 } CiDevLocationInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimRetrieveLocationInd_struct 
 {	 
 UINT16 seqNum ; /*< sequence number */	 
 } CiDevPrimRetrieveLocationInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimRetrieveLocationRsp_struct {	 
 UINT16 seqNum ; /*< sequence number */	 
 CiBoolean locationPresent ;	 
 CiDevLocationInfo location ;	 
 } CiDevPrimRetrieveLocationRsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetIgnitionStateReq_struct {	 
 CiBoolean ignitionOn ; /**< TRUE - ignition is on . FALSE otherwise \sa CCI API Ref Manual */	 
 CiBoolean updateSlowFratTimer ; /**< TRUE - enables update of slowFratTimer . FALSE otherwise. \sa CCI API Ref Manual */	 
 UINT16 slowFratTimer ; /**< SLOW FRAT Timer defines the periodicity of the HPPLMN searches when the SLOW FRAT trigger has been received \sa CCI API Ref Manual */	 
 CiBoolean updateFastFratTimer ; /**< TRUE - enables update of fastFratTimer. FALSE otherwise. \sa CCI API Ref Manual */	 
 UINT16 fastFratTimer ; /**< FAST FRAT Timer defines the periodicity of the HPPLMN searches when the FAST FRAT trigger has been received \sa CCI API Ref Manual */	 
 } CiDevPrimSetIgnitionStateReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetIgnitionStateCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetIgnitionStateCnf;

typedef CiEmptyPrim CiDevPrimGetIgnitionStateReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetIgnitionStateCnf_struct {	 
 CiDevRc rc ;	 
 CiBoolean ignitionOn ; /**< TRUE - ignition is on . FALSE otherwise \sa CCI API Ref Manual */	 
 UINT16 slowFratTimer ; /**< SLOW FRAT Timer defines the periodicity of the HPPLMN searches when the SLOW FRAT trigger has been received \sa CCI API Ref Manual */	 
 UINT16 fastFratTimer ; /**< FAST FRAT Timer defines the periodicity of the HPPLMN searches when the FAST FRAT trigger has been received \sa CCI API Ref Manual */	 
 } CiDevPrimGetIgnitionStateCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAreaInfoGsm_struct 
 {	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 UINT16 lac ;	 
 UINT16 ci ;	 
 } CiDevAreaInfoGsm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAreaInfoUtra_struct 
 {	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 UINT16 lac ;	 
 UINT32 ucid ;	 
 } CiDevAreaInfoUtra;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAreaInfoEutra_struct 
 {	 
 UINT16 arfcnEutra ;	 
 UINT16 physCellId ;	 
 CiBoolean cgiPresent ;	 
 CiDevCellGlobalIdEutra cellGlobalId ;	 
 } CiDevAreaInfoEutra;

//ICAT EXPORTED UNION 
 typedef union CiDevAreaInfo_union {	 
 CiDevAreaInfoGsm gsmInfo ;	 
 CiDevAreaInfoUtra utraInfo ;	 
 CiDevAreaInfoEutra eutraInfo ;	 
 } CiDevAreaInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLpUeAreaInfoIndReq_struct {	 
 CiBoolean enableUeAreaInfoInd ;	 
 } CiDevPrimSetLpUeAreaInfoIndReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLpUeAreaInfoIndCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc. */	 
 } CiDevPrimSetLpUeAreaInfoIndCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpUeAreaInfoInd_struct {	 
 CiDevNetworkType networkType ;	 
 CiDevAreaInfo info ;	 
 } CiDevPrimLpUeAreaInfoInd;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_LP_RRC_STATE_IND " > */ 
 typedef struct CiDevPrimLpRrcStateInd_struct {	 
 CiDevLpBearerType bearer_type ; /**< Radio bearer type \sa CiDevLpBearerType */	 
 CiDevLpRRCState rrc_state ; /**< Current RRC state \sa CiDevLpRRCState */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimLpRrcStateInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpMeasTerminateInd_struct {	 
 CiDevLpBearerType bearer_type ; /**< Radio bearer type \sa CiDevLpBearerType */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 } CiDevPrimLpMeasTerminateInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLpResetStoreUePosInd_struct {	 
 CiDevLpBearerType bearer_type ; /**< Radio bearer type \sa CiDevLpBearerType */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 } CiDevPrimLpResetStoreUePosInd;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_DO_SELF_TEST_REQ " > */ 
 typedef struct CiDevPrimDoSelfTestReq_struct {	 
	 
 UINT32 appVersion ; /* Not in use */	 
	 
 } CiDevPrimDoSelfTestReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_DO_SELF_TEST_CNF " > */ 
 typedef struct CiDevPrimDoSelfTestCnf_struct {	 
	 
 CiDevRc result ; /* Result code \sa CiDevRc */	 
 CiDevSelfTestResult testResult ; /* Test result \sa CiDevSelfTestResult */	 
	 
 } CiDevPrimDoSelfTestCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_DO_SELF_TEST_IND " > */ 
 typedef struct CiCustPrimPerformSelfTestInd_struct {	 
	 
 CiDevSelfTestResult testResult ; /* Test result \sa CiDevSelfTestResult */	 
	 
 } CiDevPrimDoSelfTestInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetRfsReq_struct {	 
	 
 CiDevRfsLevel level ; /**< Not in use */	 
	 
 } CiDevPrimSetRfsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetRfsCnf_struct {	 
	 
 CiDevRc result ; /**< Result code \sa CiDevRc. */	 
	 
 } CiDevPrimSetRfsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetRfsReq_struct {	 
	 
 CiDevRfsLevel level ; /**< Not in use */	 
	 
 } CiDevPrimGetRfsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetRfsCnf_struct {	 
	 
 CiDevRc result ; /**< Result code \sa CiDevRc. */	 
	 
 } CiDevPrimGetRfsCnf;

typedef CiEmptyPrim CiDevPrimCommAssertReq ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVNWMODESET_TAG {	 
 CI_DEV_NW_GSM_MODE = 0 , /**< GSM */	 
 CI_DEV_NW_UMTS_MODE , /**< UMTS */	 
	 
 CI_DEV_NW_DUAL_GSM_UMTS_MODE , /**< GSM_UMTS , auto */	 
 CI_DEV_NW_DUAL_GSM_UMTS_MODE_GSM , /**< GSM_UMTS , GSM preferred */	 
 CI_DEV_NW_DUAL_GSM_UMTS_MODE_UMTS , /**< GSM_UMTS , UMTS preferred */	 
	 
 CI_DEV_NW_LTE_MODE , /**< LTE */	 
	 
 CI_DEV_NW_DUAL_GSM_LTE_MODE , /**< GSM_LTE , auto , single link */	 
 CI_DEV_NW_DUAL_GSM_LTE_MODE_GSM , /**< GSM_LTE , GSM preferred , single link */	 
 CI_DEV_NW_DUAL_GSM_LTE_MODE_LTE , /**< GSM_LTE , LTE preferred , single link */	 
	 
 CI_DEV_NW_DUAL_UMTS_LTE_MODE , /**< UMTS_LTE , auto , single link */	 
 CI_DEV_NW_DUAL_UMTS_LTE_MODE_UMTS , /**< UMTS_LTE , UMTS preferred , single link */	 
 CI_DEV_NW_DUAL_UMTS_LTE_MODE_LTE , /**< UMTS_LTE , LTE preferred , single link */	 
	 
 CI_DEV_NW_TRIP_MODE , /**< GSM_UMTS_LTE , auto , single link */	 
 CI_DEV_NW_TRIP_MODE_GSM , /**< GSM_UMTS_LTE , GSM preferred , single link */	 
 CI_DEV_NW_TRIP_MODE_UMTS , /**< GSM_UMTS_LTE , UMTS preferred , single link */	 
 CI_DEV_NW_TRIP_MODE_LTE , /**< GSM_UMTS_LTE , LTE preferred , single link */	 
	 
 CI_DEV_NW_GSM_LTE_MODE_DUALLINK , /**< GSM_LTE , dual link */	 
 CI_DEV_NW_UMTS_LTE_MODE_DUALLINK , /**< UMTS_LTE , dual link */	 
 CI_DEV_NW_TRIP_MODE_DUALLINK , /**< GSM_UMTS_LTE , dual link */	 
	 
 CI_DEV_NW_MODE_NOT_CHANGE = 0xF0 ,	 
	 
 CI_DEV_NUM_NW_MODES_SET	 
	 
 } _CiDevNwModeSet;

typedef UINT8 CiDevNwModeSet ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVNWMODES_TAG {	 
 CI_DEV_NW_GSM = 0 , /**< GSM */	 
 CI_DEV_NW_UMTS , /**< UMTS */	 
 CI_DEV_NW_GSM_UMTS , /**< GSM_UMTS */	 
 CI_DEV_NW_LTE , /**< LTE */	 
 CI_DEV_NW_GSM_LTE , /**< GSM_LTE */	 
 CI_DEV_NW_UMTS_LTE , /**< UMTS_LTE */	 
 CI_DEV_NW_GSM_UMTS_LTE , /**< GSM_UMTS_LTE */	 
	 
 CI_DEV_NUM_NW_MODES	 
	 
 } _CiDevNetworkMode;

typedef UINT8 CiDevNetworkMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVGSMBANDMODES_TAG {	 
 CI_DEV_PGSM_900 = 0 , /**< Standard or primary GSM 900 band */	 
 CI_DEV_DCS_GSM_1800 , /**< DCS 1800 band */	 
 CI_DEV_PCS_GSM_1900 , /**< PCS 1900 band */	 
 CI_DEV_EGSM_900 , /**< Extended GSM 900 band */	 
 CI_DEV_GSM_450 , /**< GSM 450 band */	 
 CI_DEV_GSM_480 , /**< GSM 480 band */	 
 CI_DEV_GSM_850 , /**< GSM 850 band */	 
	 
 CI_DEV_NUM_GSM_BAND	 
 } _CiDevGSMBandMode;

typedef UINT8 CiDevGSMBandMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVUMTSBANDMODES_TAG {	 
 CI_DEV_UMTS_BAND_1 = 0 , /**< UMTS operating band 1 */	 
 CI_DEV_UMTS_BAND_2 , /**< UMTS operating band 2 */	 
 CI_DEV_UMTS_BAND_3 , /**< UMTS operating band 3 */	 
 CI_DEV_UMTS_BAND_4 , /**< UMTS operating band 4 */	 
 CI_DEV_UMTS_BAND_5 , /**< UMTS operating band 5 */	 
 CI_DEV_UMTS_BAND_6 , /**< UMTS operating band 6 */	 
 CI_DEV_UMTS_BAND_7 , /**< UMTS operating band 7 */	 
 CI_DEV_UMTS_BAND_8 , /**< UMTS operating band 8 */	 
 CI_DEV_UMTS_BAND_9 , /**< UMTS operating band 9 */	 
	 
 CI_DEV_UMTS_BAND_10 , /**< UMTS operating band 10 */	 
 CI_DEV_UMTS_BAND_11 , /**< UMTS operating band 11 */	 
 CI_DEV_UMTS_BAND_12 , /**< UMTS operating band 12 */	 
 CI_DEV_UMTS_BAND_13 , /**< UMTS operating band 13 */	 
 CI_DEV_UMTS_BAND_14 , /**< UMTS operating band 14 */	 
 CI_DEV_UMTS_BAND_15 , /**< UMTS operating band 15 */	 
 CI_DEV_UMTS_BAND_16 , /**< UMTS operating band 16 */	 
 CI_DEV_UMTS_BAND_17 , /**< UMTS operating band 17 */	 
 CI_DEV_UMTS_BAND_18 , /**< UMTS operating band 18 */	 
 CI_DEV_UMTS_BAND_19 , /**< UMTS operating band 19 */	 
	 
 CI_DEV_NUM_UMTS_BAND	 
	 
 } _CiDevUMTSBandMode;

typedef UINT8 CiDevUMTSBandMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVEUTRANLOWBANDMODES_TAG {	 
 CI_DEV_EUTRAN_BAND_1 = 0 , /**< E-UTRAN operating band 1 */	 
 CI_DEV_EUTRAN_BAND_2 , /**< E-UTRAN operating band 2 */	 
 CI_DEV_EUTRAN_BAND_3 , /**< E-UTRAN operating band 3 */	 
 CI_DEV_EUTRAN_BAND_4 , /**< E-UTRAN operating band 4 */	 
 CI_DEV_EUTRAN_BAND_5 , /**< E-UTRAN operating band 5 */	 
 CI_DEV_EUTRAN_BAND_6 , /**< E-UTRAN operating band 6 */	 
 CI_DEV_EUTRAN_BAND_7 , /**< E-UTRAN operating band 7 */	 
 CI_DEV_EUTRAN_BAND_8 , /**< E-UTRAN operating band 8 */	 
 CI_DEV_EUTRAN_BAND_9 , /**< E-UTRAN operating band 10 */	 
 CI_DEV_EUTRAN_BAND_10 , /**< E-UTRAN operating band 11 */	 
 CI_DEV_EUTRAN_BAND_11 , /**< E-UTRAN operating band 12 */	 
 CI_DEV_EUTRAN_BAND_12 , /**< E-UTRAN operating band 13 */	 
 CI_DEV_EUTRAN_BAND_13 , /**< E-UTRAN operating band 14 */	 
 CI_DEV_EUTRAN_BAND_14 , /**< E-UTRAN operating band 15 */	 
 CI_DEV_EUTRAN_BAND_15_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_16_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_17 , /**< E-UTRAN operating band 17 */	 
 CI_DEV_EUTRAN_BAND_18 , /**< E-UTRAN operating band 18 */	 
 CI_DEV_EUTRAN_BAND_19 , /**< E-UTRAN operating band 19 */	 
 CI_DEV_EUTRAN_BAND_20 , /**< E-UTRAN operating band 20 */	 
 CI_DEV_EUTRAN_BAND_21 , /**< E-UTRAN operating band 21 */	 
 CI_DEV_EUTRAN_BAND_22 , /**< E-UTRAN operating band 22 */	 
 CI_DEV_EUTRAN_BAND_23 , /**< E-UTRAN operating band 23 */	 
 CI_DEV_EUTRAN_BAND_24 , /**< E-UTRAN operating band 24 */	 
 CI_DEV_EUTRAN_BAND_25 , /**< E-UTRAN operating band 25 */	 
 CI_DEV_EUTRAN_BAND_26 , /**< E-UTRAN operating band 26 */	 
 CI_DEV_EUTRAN_BAND_27_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_28_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_29_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_30_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_31_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_32_NOT_USED ,	 
 CI_DEV_NUM_LOW_EUTRAN_BAND	 
 } _CiDevEUTRANLowBandMode;

typedef UINT8 CiDevEUTRANLowBandMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVEUTRANHIGHBANDMODES_TAG {	 
 CI_DEV_EUTRAN_BAND_33 = 0 , /**< E-UTRAN operating band 33 */	 
 CI_DEV_EUTRAN_BAND_34 , /**< E-UTRAN operating band 34 */	 
 CI_DEV_EUTRAN_BAND_35 , /**< E-UTRAN operating band 35 */	 
 CI_DEV_EUTRAN_BAND_36 , /**< E-UTRAN operating band 36 */	 
 CI_DEV_EUTRAN_BAND_37 , /**< E-UTRAN operating band 37 */	 
 CI_DEV_EUTRAN_BAND_38 , /**< E-UTRAN operating band 38 */	 
 CI_DEV_EUTRAN_BAND_39 , /**< E-UTRAN operating band 39 */	 
 CI_DEV_EUTRAN_BAND_40 , /**< E-UTRAN operating band 40 */	 
 CI_DEV_EUTRAN_BAND_41 , /**< E-UTRAN operating band 41 */	 
 CI_DEV_EUTRAN_BAND_42 , /**< E-UTRAN operating band 42 */	 
 CI_DEV_EUTRAN_BAND_43 , /**< E-UTRAN operating band 43 */	 
 CI_DEV_NUM_HIGH_EUTRAN_BAND	 
 } _CiDevEUTRANHighBandMode;

typedef UINT8 CiDevEUTRANHighBandMode ;
typedef UINT8 CiDevSetBandRoamingConfig ;
typedef UINT8 CiDevSetBandSrvDomain ;
typedef UINT8 CiDevSetBandPriorityFlag ;
typedef UINT8 CiDevSetBandUsageType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetBandModeReq_struct {	 
 CiDevNetworkMode networkMode ;	 
 CiDevNetworkMode preferredMode ;	 
 CiBitRange GSMBandMode ;	 
 CiBitRange UMTSBandMode ;	 
 CiBitRange EUTRANBandModeH ; /**< Bit mask indicating the required E-UTRAN bands High part ( bands 33 - 43 ) . If bit is set the	 
 * band is supported. Bit definition is based on CIDEVEUTRANHIGHBANDMODES_TAG*/	 
 CiBitRange EUTRANBandModeL ; /**< Bit mask indicating the required E-UTRAN bands Low part ( bands 1 - 32 ) . If bit is set the	 
 * band is supported. Bit definition is based on CIDEVEUTRANLOWBANDMODES_TAG*/	 
 CiDevSetBandRoamingConfig roamingConfig ; /**< Roaming: 0 -not support , 1 -support , 2 -no change ( default ) */	 
 CiDevSetBandSrvDomain srvDomain ; /**< Service domain: 0 -CS only , 1 - PS only , 2 -CS and PS , 3 - ANY , 4 -no change ( default ) */	 
 CiDevSetBandPriorityFlag bandPriorityFlag ; /**0: default ; 1 : TD-LTE ; 2 :FDD-LTE*/	 
 CiBoolean isLteDualLink ; /**TRUE: dual Link ; FALSE: single Link*/	 
	 
 /*Added by Lilei for preferred band setting on 1152014 , begin*/	 
	 
 CiDevSetBandUsageType bandType ; /**< Band type: 0 -band capability ( default ) , 1 -preferred band , 2 -only registration band */	 
	 
 /*Added by Lilei for preferred band setting on 1152014 , end*/	 
 CiBitRange EUTRANBandModeExt ; /**< Bit mask indicating the required E-UTRAN bands Extended part ( bands 65 - 69 ) . */	 
 } CiDevPrimSetBandModeReq;

//ICAT EXPORTED ENUM 
 typedef enum CIDEVSETBANDCNFACT_TAG {	 
 CI_DEV_SET_BAND_CNF_NO_ACT = 0 ,	 
 CI_DEV_SET_BAND_CNF_NEED_SILENT_RESET	 
 } _CiDevSetBandCnfAct;

typedef UINT8 CiDevSetBandCnfAct ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetBandModeCnf_struct {	 
 CiDevRc result ; /**< Result code \sa CiDevRc */	 
 CiDevSetBandCnfAct apAct ;	 
 } CiDevPrimSetBandModeCnf;

typedef CiEmptyPrim CiDevPrimGetBandModeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetBandModeCnf_struct {	 
 CiDevRc result ;	 
 CiDevNetworkMode networkMode ;	 
 CiDevNetworkMode preferredMode ;	 
 CiBitRange GSMBandMode ;	 
 CiBitRange UMTSBandMode ;	 
 CiBitRange EUTRANBandModeH ; /**< Bit mask indicating the required E-UTRAN bands High part ( bands 33 - 43 ) . If bit is set the	 
 * band is supported. Bit definition is based on CIDEVEUTRANHIGHBANDMODES_TAG*/	 
 CiBitRange EUTRANBandModeL ; /**< Bit mask indicating the required E-UTRAN bands Low part ( bands 1 - 32 ) . If bit is set the	 
 * band is supported. Bit definition is based on CIDEVEUTRANLOWBANDMODES_TAG*/	 
 UINT8 roamingConfig ; /**< Roaming: 0 -not support , 1 -support */	 
 UINT8 srvDomain ; /**< Service domain: 0 -CS only , 1 - PS only , 2 -CS and PS , 3 - ANY*/	 
 UINT8 bandPriorityFlag ; /**0: default ; 1 : TD-LTE ; 2 :FDD-LTE*/	 
 /* Added by Lilei 20131009 , begin */	 
 CiBoolean isLteDualLink ; /**TRUE: dual Link ; FALSE: single Link*/	 
 /* Added by Lilei 20131009 , end */	 
 CiBitRange EUTRANBandModeExt ; /**< Bit mask indicating the required E-UTRAN bands Extended part ( bands 65 - 69 ) . */	 
 } CiDevPrimGetBandModeCnf;

typedef CiEmptyPrim CiDevPrimGetSupportedBandModeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSupportedBandModeCnf_struct {	 
 CiDevRc result ; /**< Result code \sa CiDevRc */	 
 CiBitRange bitsNetworkMode ; /**< Bit mask indicating the supported RAT modes. If bit is set the band is supported. Bit definition is based on CIDEVNWMODES_TAG \sa CCI API Ref Manual*/	 
 CiBitRange bitsGSMBandMode ; /**< Bit mask indicating the supported GSM bands. If bit is set the band is supported. Bit definition is based on CIDEVGSMBANDMODES_TAG \sa CCI API Ref Manual */	 
 CiBitRange bitsUMTSBandMode ; /**< Bit mask indicating the supportedUMTS bands. If bit is set the band is supported. Bit definition is based on CIDEVUMTSBANDMODES_TAG \sa CCI API Ref Manual */	 
 CiBitRange bitsEUTRANBandModeH ; /**< Bit mask indicating the required E-UTRAN bands High part ( bands 33 - 43 ) . If bit is set the	 
 * band is supported. Bit definition is based on CIDEVEUTRANHIGHBANDMODES_TAG*/	 
 CiBitRange bitsEUTRANBandModeL ; /**< Bit mask indicating the required E-UTRAN bands Low part ( bands 1 - 32 ) . If bit is set the	 
 * band is supported. Bit definition is based on CIDEVEUTRANLOWBANDMODES_TAG*/	 
 CiBitRange bitsEUTRANBandModeExt ; /**< Bit mask indicating the required E-UTRAN bands Extended part ( bands 65 - 69 ) . */	 
 } CiDevPrimGetSupportedBandModeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiImei_struct {	 
 UINT8 len ; /**< Length */	 
 CHAR val [ 16 ] ; /**< IMEI digits */	 
 } CiImei;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSvReq_struct {	 
 CiImei SVDigits ; /**< IMEI SV digits. \sa CiImei */	 
 } CiDevPrimSetSvReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSvCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetSvCnf;

typedef CiEmptyPrim CiDevPrimGetSvReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSvCnf_struct {	 
 CiImei SVDigits ; /**< IMEI SV dugits. \sa CiImei */	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimGetSvCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimApPowerNotifyReq_struct {	 
 UINT32 powerState ; /**< AP power state: 1 ~31 means suspend , bitmap: bit0 - NETWORK ;	 
 bit1 - SIM ;	 
 bit2 - SMS ;	 
 bit3 - CS CALL	 
 bit4 - PS DATA	 
 0 means resume all. \sa powerState */	 
 } CiDevPrimApPowerNotifyReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimApPowerNotifyCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 } CiDevPrimApPowerNotifyCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_TD_RX_TX_OPTION_TAG {	 
 CI_DEV_TD_TX_START = 0 ,	 
 CI_DEV_TD_RX_START ,	 
 CI_DEV_TD_TX_RX_STOP ,	 
	 
 CI_DEV_NUM_TD_TX_RX	 
 } _CiDevTdTxRxOption;

typedef UINT8 CiDevTdTxRxOption ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_RX_TX_OPTION_TAG {	 
 CI_DEV_GSM_TX_START = 0 ,	 
 CI_DEV_GSM_RX_START ,	 
 CI_DEV_GSM_TX_RX_START ,	 
 CI_DEV_GSM_TX_RX_STOP ,	 
	 
 CI_DEV_NUM_GSM_TX_RX	 
 } _CiDevGsmTxRxOption;

typedef UINT8 CiDevGsmTxRxOption ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_CONTROL_MODE_TAG {	 
 CI_DEV_GSM_CONTROL_READ = 0 ,	 
 CI_DEV_GSM_CONTROL_WRITE ,	 
 CI_DEV_GSM_CONTROL_LOOPBACK ,	 
	 
 CI_DEV_NUM_GSM_CONTROL	 
 } _CiDevGsmControlMode;

typedef UINT8 CiDevGsmControlMode ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetTdModeTxRxReq_struct {	 
 CiDevTdTxRxOption option ; /**< TD option. \sa CiDevTdTxRxOption */	 
 INT16 txRxGain ; /**< Tx or Rx gain */	 
 UINT16 freq ; /**< TD frequency */	 
 } CiDevPrimSetTdModeTxRxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetTdModeTxRxCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 } CiDevPrimSetTdModeTxRxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetTdModeLoopbackReq_struct {	 
 UINT32 regValue ; /**< The value to be written into RF register */	 
 } CiDevPrimSetTdModeLoopbackReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetTdModeLoopbackCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT32 regValue ; /**< The value to be read from RF register */	 
 } CiDevPrimSetTdModeLoopbackCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_WCDMA_RX_TX_OPTION_TAG {	 
 CI_DEV_WCDMA_TX_START = 0 ,	 
 CI_DEV_WCDMA_RX_START ,	 
 CI_DEV_WCDMA_TX_RX_STOP ,	 
	 
 CI_DEV_NUM_WCDMA_TX_RX	 
 } _CiDevWcdmaTxRxOption;

typedef UINT8 CiDevWcdmaTxRxOption ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetWcdmaModeTxRxReq_struct {	 
 CiDevWcdmaTxRxOption option ; /**< WCDMA option. \sa CiDevWcdmaTxRxOption */	 
 UINT16 DL_UARFCN ; /**< Downlink UARFCN*/	 
 UINT16 UL_UARFCN ; /**< Uplink UARFCN*/	 
 UINT8 PA_Mode ; /**< PA mode :2 ; range ( 0 , 1 , 2 ) */	 
 UINT16 APC_Dac ; /**< APC DAC :1600 ; range [ 0 , 2047 ] */	 
 UINT16 DCDC_Dac ; /**<DCDC DAC :Not used for LT02*/	 
 INT16 AFC_Dac ; /**< AFC DAC :18000*/	 
 } CiDevPrimSetWcdmaModeTxRxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetWcdmaModeTxRxCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 signed short acqRssi ; /**< The Rssi value to be returned in case of GSM RX mode*/	 
 } CiDevPrimSetWcdmaModeTxRxCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_LTE_RX_TX_OPTION_TAG {	 
 CI_DEV_LTE_TX_START = 0 ,	 
 CI_DEV_LTE_RX_START ,	 
 CI_DEV_LTE_TX_RX_STOP ,	 
	 
 CI_DEV_NUM_LTE_TX_RX	 
 } _CiDevLteTxRxOption;

typedef UINT8 CiDevLteTxRxOption ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLteModeTxRxReq_struct {	 
 CiDevLteTxRxOption option ; /**< LTE option. \sa CiDevLteTxRxOption */	 
 INT16 txRxPower ; /**< Tx or Rx power. Range [ 0 , 2047 ] for TX*/	 
 UINT16 freq ; /**< LTE carrier frequency. Range [ 0 , 45589 ] */	 
 UINT8 bandwidth ; /**< LTE bandwidth. Range [ 0 , 5 ] */	 
 } CiDevPrimSetLteModeTxRxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLteModeTxRxCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
	 
 INT16 rssiPri ;	 
 INT16 rssiSec ;	 
	 
 } CiDevPrimSetLteModeTxRxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetGsmModeTxRxReq_struct {	 
 CiDevGsmTxRxOption option ; /**< TD option. \sa CiDevGsmTxRxOption */	 
 CiBitRange gsmBandMode ; /**< GSM band mode */	 
 UINT16 arfcn ; /**< Absolute Radio Frequency Channel Number */	 
 UINT32 afcDac ; /**< AFC DAC value*/	 
 UINT32 txRampScale ; /**< Tx ramp scale , only valid for Tx or Tx+Rx mode*/	 
 UINT32 rxGainCode ; /**< Rx gain code , only valid for Rx or Tx+Rx mode*/	 
 } CiDevPrimSetGsmModeTxRxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetGsmModeTxRxCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 signed short rssiDbmValue ; /**< The Rssi value to be returned in case of GSM RX mode*/	 
 } CiDevPrimSetGsmModeTxRxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetGsmControlInterfaceReq_struct {	 
 CiDevGsmControlMode mode ; /**< Operation mode. \sa CiDevGsmControlMode */	 
 UINT16 addrReg ; /**< Register address*/	 
 UINT16 regValue ; /**< The payload value to be written into RFIC in case of write or loopback mode*/	 
 } CiDevPrimSetGsmControlInterfaceReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetGsmControlInterfaceCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT16 addrReg ; /**< Register address*/	 
 UINT16 regValue ; /**< The payload value to be read from RFIC in case of read or loopback mode*/	 
 } CiDevPrimSetGsmControlInterfaceCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_HSPA_CONFIG_TAG {	 
 CI_DEV_HSDPA_OFF_HSUPA_OFF = 0 , /* set RRC release to R5 */	 
 CI_DEV_HSDPA_ON_HSUPA_OFF , /* set RRC release to R5 */	 
 CI_DEV_HSDPA_ON_HSUPA_ON , /* set RRC release to R7 */	 
 CI_DEV_HSDPA_ON_HSUPA_ON_DLDC , /* set RRC release to R9 , only used for TD-SCDMA */	 
 CI_DEV_HSPA_REL6 , /* set RRC release to R6 , only used for WCDMA */	 
	 
 CI_DEV_NUM_HSPA_CONFIG	 
 } _CiDevHspaConfig;

typedef UINT8 CiDevHspaConfig ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimEnableHsdpaReq_struct {	 
 CiDevHspaConfig hspaConfig ; /**< HSPA configurations \sa CiDevHspaConfig */	 
 UINT8 dlCategory ; /**< DL category , for WCDMA support 1 ~12 , default 10 for Rel7 ; support 1 ~15 except 12 on TD HSDPA , 16 , 23 , 35 on DLDC , default 15 */	 
 UINT8 ulCategory ; /**< UL category , for WCDMA support 1 ~6 , default 6 ; only support 6 on TD HSUPA , fix it if UPA is enabled */	 
 UINT8 cpcState ; /**< CPC state only used for WCDMA Rel7 , 0 :disabled , 1 :enabled , default enabled ; not supported on TD-SCDMA , hard coded with 0 or ingore it*/	 
	 
 UINT8 dpaCategoryExt ; /**< DPA category ext , for WCDMA Rel7 support 1 ~14 , default 14 for Rel7*/	 
 UINT8 edchCategoryExt ; /**< EDCH category ext , for WCDMA Rel7 only support 7 as default*/	 
	 
 UINT8 fdpchState ; /**< F-DPCH enabled or disabled on R6 / R7 for WCDMA , 0 :disabled , 1 :enabled , default enabled*/	 
 UINT8 eFdpchState ; /**< Enhanced F-DPCH enabled or disabled on R7 for WCDMA 0 :disabled , 1 :enabled , default enabled*/	 
	 
 /*Lilei , CQ00090354 , 20150410 , begin*/	 
 UINT8 eFachState ; /**< Enhanced FACH enabled or disabled on R7 for WCDMA. 0 :disabled , 1 :enabled , default enabled*/	 
 /*Lilei , CQ00090354 , 20150410 , end*/	 
 } CiDevPrimEnableHsdpaReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimEnableHsdpaCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 } CiDevPrimEnableHsdpaCnf;

typedef CiEmptyPrim CiDevPrimGetHsdpaStatusReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetHsdpaStatusCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
	 
 CiDevHspaConfig hspaConfig ; /**< HSPA configurations \sa CiDevHspaConfig */	 
 UINT8 dlCategory ; /**< DL category , for WCDMA support 1 ~12 , default 10 for Rel7 ; support 1 ~15 except 12 on TD HSDPA , 16 , 23 , 35 on DLDC , default 15 */	 
 UINT8 ulCategory ; /**< UL category , for WCDMA support 1 ~6 , default 6 ; only support 6 on TD HSUPA , fix it if UPA is enabled */	 
 UINT8 cpcState ; /**< CPC state only used for WCDMA Rel7 , 0 :disabled , 1 :enabled , default enabled ; not supported on TD-SCDMA , hard coded with 0 or ingore it*/	 
	 
 UINT8 dpaCategoryExt ; /**< DPA category ext , for WCDMA Rel7 support 1 ~14 , default 14 for Rel7*/	 
 UINT8 edchCategoryExt ; /**< EDCH category ext , for WCDMA Rel7 only support 7 as default*/	 
	 
 UINT8 fdpchState ; /**< F-DPCH enabled or disabled on R6 / R7 for WCDMA , 0 :disabled , 1 :enabled , default enabled*/	 
 UINT8 eFdpchState ; /**< Enhanced F-DPCH enabled or disabled on R7 for WCDMA 0 :disabled , 1 :enabled , default enabled*/	 
	 
 /*Lilei , CQ00090354 , 20150410 , begin*/	 
 UINT8 eFachState ; /**< Enhanced FACH enabled or disabled on R7 for WCDMA. 0 :disabled , 1 :enabled , default enabled*/	 
 /*Lilei , CQ00090354 , 20150410 , end*/	 
 } CiDevPrimGetHsdpaStatusCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_RF_TEMP_TYPE_TAG {	 
 CI_DEV_RF_TEMP_CELSIUS = 0 , /**< internal RF temp */	 
 CI_DEV_RF_TEMP_RAW_DATA , /**< internal RF temp */	 
	 
 /*Lilei , CQ00125096 , 20201013 , begin*/	 
 CI_DEV_RF_TEMP_CELSIUS_EXTERNAL , /**< external RF temp */	 
 CI_DEV_RF_TEMP_RAW_DATA_EXTERNAL , /**< external RF temp */	 
 /*Lilei , CQ00125096 , 20201013 , end*/	 
	 
 CI_DEV_NUM_RF_TEMP	 
 } _CiDevRfTempType;

typedef UINT8 CiDevRfTempType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimReadRfTemperatureReq_struct {	 
 CiDevRfTempType type ; /**< Read type. \sa CiDevRfTempType */	 
 } CiDevPrimReadRfTemperatureReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimReadRfTemperatureCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 INT32 tempData ; /**< Temperature data */	 
 } CiDevPrimReadRfTemperatureCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_NW_MONITOR_MODE_TAG {	 
 CI_DEV_NW_MONIOTR_NORMAL = 16 ,	 
 CI_DEV_NW_MONIOTR_DETECT = 96 ,	 
	 
 CI_DEV_NUM_RNW_MONIOTR	 
 } _CiDevNwMonitorMode;

typedef UINT8 CiDevNwMonitorMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_PROTOCOL_STATUS_TAG {	 
 CI_DEV_PROTOCOL_STATUS_IDLE = 0 ,	 
 CI_DEV_PROTOCOL_STATUS_CONNECT ,	 
	 
 CI_DEV_NUM_PROTOCOL_STATUS	 
 } _CiDevProtocolStatus;

typedef UINT8 CiDevProtocolStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_EVENT_OPER_TYPE_TAG {	 
 CI_DEV_EVENT_OPER_CS_VOICE = 0 ,	 
 CI_DEV_EVENT_OPER_CS_DATA ,	 
 CI_DEV_EVENT_OPER_PS ,	 
 CI_DEV_EVENT_OPER_SMS ,	 
	 
 CI_DEV_NUM_EVENT_OPER	 
 } _CiDevEventOperType;

typedef UINT8 CiDevEventOperType ;
typedef UINT32 CiDevEventId ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_SIGNALING_MSG_ID_TAG {	 
 CI_DEV_SIGNALING_BCH_MSG_IND = 12202 , /* only for TDD */	 
 CI_DEV_SIGNALING_BCCH_FACH_MSG_IND = 2020 , /* only for TDD */	 
 CI_DEV_SIGNALING_PCCH_PCH_MSG_IND = 2021 , /* only for TDD */	 
 CI_DEV_SIGNALING_UL_CCH_MSG_IND = 3005 , /* only for TDD */	 
 CI_DEV_SIGNALING_DL_CCH_MSG_IND = 3006 , /* only for TDD */	 
	 
 CI_DEV_SIGNALING_GSM_MSG_IND = 12155 , /* only for GSM */	 
	 
 CI_DEV_NUM_SIGNALING_MSG_D = 0xFFFF	 
 } _CiDevSignalingMsgId;

typedef UINT32 CiDevSignalingMsgId ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_BAND_TAG {	 
 CI_DEV_GSM_BAND_PGSM_900 = 0 ,	 
 CI_DEV_GSM_BAND_EGSM_900 ,	 
 CI_DEV_GSM_BAND_RGSM_900 ,	 
 CI_DEV_GSM_BAND_DCS_1800 ,	 
 CI_DEV_GSM_BAND_PCS_1900 ,	 
 CI_DEV_GSM_BAND_450 ,	 
 CI_DEV_GSM_BAND_480 ,	 
 CI_DEV_GSM_BAND_850 ,	 
 CI_DEV_GSM_BAND_750 ,	 
	 
 CI_DEV_NUM_BAND	 
 } _CiDevGsmBand;

typedef UINT8 CiDevGsmBand ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPlmnMcc_struct 
 {	 
 UINT8 mcc [ 3 ] ;	 
 } CiDevPlmnMcc;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPlmnMnc_struct 
 {	 
 UINT8 len ;	 
 UINT8 mnc [ 3 ] ;	 
 } CiDevPlmnMnc;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTsIscp_struct 
 {	 
 UINT8 timeSlot ; /**< TimeSlot ( 0 ..6 ) */	 
 UINT8 iscp ; /**< ISCP ( 0 ..91 ) , real value ( dbm ) =IE value -116 */	 
 } CiDevTsIscp;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTsIscpArray_struct 
 {	 
 UINT8 num ;	 
 CiDevTsIscp data [ 7 ] ;	 
 } CiDevTsIscpArray;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevDpchRscp_struct 
 {	 
 UINT8 timeSlot ; /**< TimeSlot ( 0 ..6 ) */	 
 UINT8 rscp ; /**< DPCH RSCP ( 0 ..91 ) , real value ( dbm ) =IE value -116 */	 
 } CiDevDpchRscp;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevDpchRscpArray_struct 
 {	 
 UINT8 num ;	 
 CiDevDpchRscp data [ 7 ] ;	 
 } CiDevDpchRscpArray;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTxPower_struct 
 {	 
 UINT8 timeSlot ; /**< TimeSlot ( 0 ..6 ) */	 
 UINT8 txPower ; /**< UE Transmitted Power ( 21 ..104 ) , 0xff means UE TxPower is not available.	 
 real value ( dbm ) =IE value -71 */	 
 } CiDevTxPower;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTxPowerArray_struct 
 {	 
 UINT8 num ;	 
 CiDevTxPower data [ 7 ] ;	 
 } CiDevTxPowerArray;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddNcellTsIscp_struct 
 {	 
 UINT8 tsNum ; /**< Timeslot number. ( 0 ..6 ) */	 
 UINT8 tsIscp ; /**< Timeslot ISCP. ( 0 ..91 ) */	 
 } CiDevTddNcellTsIscp;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddRrcDiagNcellTddPara_struct 
 {	 
 UINT8 cellParamId ; /**< Neighbor cell parameter ID. ( 0 ..127 ) */	 
 UINT16 uArfcn ; /**< Neighbor cell UARFCN. ( 0 ..16383 ) */	 
 UINT8 pccpchRscp ; /**< Neighbor cell PCCPCH RSCP. ( 0 ..91 ) */	 
	 
 UINT8 res1U8 ; /**< ( padding ) */	 
 UINT8 iscpNum ; /** ( 0 ..6 ) If it equals to 0 , nCellTsIscp does not xist. */	 
 CiDevTddNcellTsIscp nCellTsIscp [ 7 -1 ] ;	 
	 
 UINT32 res2U32 ; /**< ( padding ) */	 
 } CiDevTddRrcDiagNcellTddPara;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddRrcDiagNcellGsmPara_struct 
 {	 
 UINT16 arfcn ; /**< Neighbor cell ARFCN info. ( 0 ..1023 ) */	 
 CiDevGsmBand band ; /**< Neighbor cell current freq band. */	 
 UINT8 bsic ; /**< Neighbor cell BSIC. ( 0 ..63 ) */	 
 UINT8 rxlev ; /**< Neighbor cell GSM received signal level. */	 
 UINT8 res1U16 [ 3 ] ; /**< ( padding ) */	 
 } CiDevTddRrcDiagNcellGsmPara;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddNcellParamList_struct 
 {	 
 UINT8 numNcellTdd ; /**< If it equals 0 , the IE below will not exist */	 
 CiDevTddRrcDiagNcellTddPara nbCellInfoTdd [ 6 ] ;	 
	 
 UINT8 res1U8 ; /**< ( padding ) , always fill with 0xFE */	 
 UINT8 numNcellGsm ; /**< If it equals 0 , the IE below will not exist */	 
 CiDevTddRrcDiagNcellGsmPara nbCellInfoGsm [ 6 ] ;	 
 } CiDevTddNcellParamList;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_TDD_CHANNEL_CODE_TAG {	 
 CI_DEV_TDD_CC1_1 = 0 ,	 
 CI_DEV_TDD_CC2_1 ,	 
 CI_DEV_TDD_CC2_2 ,	 
 CI_DEV_TDD_CC4_1 ,	 
 CI_DEV_TDD_CC4_2 ,	 
 CI_DEV_TDD_CC4_3 ,	 
 CI_DEV_TDD_CC4_4 ,	 
 CI_DEV_TDD_CC8_1 ,	 
 CI_DEV_TDD_CC8_2 ,	 
 CI_DEV_TDD_CC8_3 ,	 
 CI_DEV_TDD_CC8_4 ,	 
 CI_DEV_TDD_CC8_5 ,	 
 CI_DEV_TDD_CC8_6 ,	 
 CI_DEV_TDD_CC8_7 ,	 
 CI_DEV_TDD_CC8_8 ,	 
 CI_DEV_TDD_CC16_1 ,	 
 CI_DEV_TDD_CC16_2 ,	 
 CI_DEV_TDD_CC16_3 ,	 
 CI_DEV_TDD_CC16_4 ,	 
 CI_DEV_TDD_CC16_5 ,	 
 CI_DEV_TDD_CC16_6 ,	 
 CI_DEV_TDD_CC16_7 ,	 
 CI_DEV_TDD_CC16_8 ,	 
 CI_DEV_TDD_CC16_9 ,	 
 CI_DEV_TDD_CC16_10 ,	 
 CI_DEV_TDD_CC16_11 ,	 
 CI_DEV_TDD_CC16_12 ,	 
 CI_DEV_TDD_CC16_13 ,	 
 CI_DEV_TDD_CC16_14 ,	 
 CI_DEV_TDD_CC16_15 ,	 
 CI_DEV_TDD_CC16_16 ,	 
	 
 CI_DEV_NUM_TDD_CC	 
 } _CiDevTddChannelCode;

typedef UINT8 CiDevTddChannelCode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_CODING_SCHEME_TAG {	 
 CI_DEV_GSM_CS_1 = 7 ,	 
 CI_DEV_GSM_CS_2 ,	 
 CI_DEV_GSM_CS_3 ,	 
 CI_DEV_GSM_CS_4 ,	 
	 
 CI_DEV_GSM_MCS_1 = 11 ,	 
 CI_DEV_GSM_MCS_2 ,	 
 CI_DEV_GSM_MCS_3 ,	 
 CI_DEV_GSM_MCS_4 ,	 
 CI_DEV_GSM_MCS_5 ,	 
 CI_DEV_GSM_MCS_6 ,	 
 CI_DEV_GSM_MCS_7 ,	 
 CI_DEV_GSM_MCS_8 ,	 
 CI_DEV_GSM_MCS_9 ,	 
	 
 CI_DEV_GSM_CS_INVALID = 0xFF ,	 
	 
 CI_DEV_NUM_GSM_CS	 
 } _CiDevGsmCodingScheme;

typedef UINT8 CiDevGsmCodingScheme ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddRrcDiagPhych_struct 
 {	 
 UINT8 phychId ; /**< PhyCH Id ( 0 ..47 ) */	 
 UINT8 phychDirection ; /**< PhyCH Direction , 0 :uplink ; 1 :downlink*/	 
 UINT8 timeSlot ; /**< Timeslot ( 0 ..6 ) */	 
	 
 CiDevTddChannelCode channelCode ; /**< Channel code */	 
 UINT16 res1U16 [ 2 ] ; /**< ( padding ) */	 
 } CiDevTddRrcDiagPhych;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddDedicatedPhyCchParam_struct 
 {	 
 UINT8 numPhych ; /**< ( 0 ..96 ) , 0 : all the followed item not exist ; others ( 1 -96 ) : actual physical channel number ; and the followed times exist*/	 
 CiDevTddRrcDiagPhych phychInfo [ 96 ] ;	 
	 
 UINT32 res1U32 ; /**< ( padding ) */	 
 UINT16 workFreq ; /**< Work frequency , ( 0 ..16383 ) UARFCN , real requency ( Mhz ) =UARFCN / 5 . It indicates the work frequency */	 
 } CiDevTddDedicatedPhyCchParam;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevHrnti_struct 
 {	 
 CiBoolean flag ; /**< 0 : H-RNTI is not existed , 1 :H-RNTI is existed */	 
 UINT16 hrnti ; /**< ( 0 ..65535 ) , exist only when flag=1 */	 
 } CiDevHrnti;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevErnti_struct 
 {	 
 CiBoolean flag ; /**< 0 : E-RNTI is not existed , 1 :E-RNTI is existed */	 
 UINT16 ernti ; /**< ( 0 ..65535 ) , exist only when flag=1 */	 
 } CiDevErnti;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUrntiCrnti_struct 
 {	 
 UINT8 flag ; /**< Bit0:C-RNTI ; Bit1:U-RNTI ; 0 :not existed , 1 :existed*/	 
 UINT32 urnti ; /**< ( 0 ..4294967295 ) , exist only when flag=1 */	 
 UINT16 crnti ; /**< ( 0 ..65535 ) , exist only when flag=1 */	 
 } CiDevUrntiCrnti;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTddData_struct 
 {	 
 CiDevTsIscpArray iscp ; /**< TimeSlot ISCP */	 
 CiDevDpchRscpArray rscp ; /**< DPCH RSCP */	 
 CiDevTxPowerArray txPower ; /**< UE Timeslot Transmitted Power */	 
	 
 UINT8 sCellPccphRscp ; /**< Scell P-CCPCH RSCP , ( 0 ..91 ) real value ( dbm ) =IE value -116 */	 
 UINT32 sCellId ; /**< Scell Cell Identifier , BITSTRING ( 28 ) MSB 4 bits are 0 */	 
 UINT8 sCellParamId ; /**< Scell Cell parameter id , ( 0 ..127 ) */	 
 UINT16 sCellUarfcn ; /**< Scell UARFCN , ( 0 ..16383 ) , real frequency ( MHz ) =UARFCN / 5 */	 
 UINT8 sCellUtraRssi ; /**< Scell UTRA Carrier RSSI , ( 0 ..76 ) real value ( dbm ) =IE value - 101 */	 
	 
 CiDevTddNcellParamList nbCellInfo ; /**< Neigbour cell parameter list */	 
 CiDevTddDedicatedPhyCchParam dedicatedInfo ; /**< Dedicated PhyCh parameter */	 
	 
 CiDevHrnti hRnti ; /**< H-RNTI */	 
 CiDevErnti eRnti ; /**< E-RNTI */	 
 CiDevUrntiCrnti rnti ; /**< U-RNTI / C-RNTI */	 
 } CiDevTddData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmScellSysInfo_struct 
 {	 
 UINT16 arfcn ; /**< Serving cell ARFCN ( 0 ..1023 ) */	 
 UINT16 ci ; /**< Serving cell cell identity */	 
	 
 UINT16 res1U16 ; /**< ( padding ) */	 
 CiDevGsmBand band ; /**< Serving cell current freq band */	 
	 
 UINT32 res1U32 ; /**< ( padding ) */	 
 } CiDevGsmScellSysInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmScellRadioInfo_struct 
 {	 
 UINT8 fieldMap ; /**< bit0:C2 exist or not , bit1:C31 exist or not , bit2:C32 exist or not */	 
 INT16 rxLev ; /**< Serving cell GSM received signal level. ( -110..-30 ) */	 
 UINT8 bsic ; /**< Serving cell BSIC. ( 0 ..63 ) */	 
 INT16 c1 ; /**< Serving cell Path loss param C1*/	 
 INT16 c2 ; /**< Serving cell Path loss param C2*/	 
 INT16 c31 ; /**< Serving cell GPRS signal level threshold criterion param C31*/	 
 INT16 c32 ; /**< Serving cell GPRS cell ranking criterion param C32*/	 
 } CiDevGsmScellRadioInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmNcellSysInfo_struct 
 {	 
 UINT16 arfcn ; /**< GSM neigbour cell ARFCN ( 0 ..1023 ) */	 
 UINT16 res1U16 ; /**< ( padding ) */	 
	 
 CiDevGsmBand band ; /**< GSM neigbour cell current freq band */	 
 UINT8 bsic ; /**< GSM neigbour cell BSIC. ( 0 ..63 ) */	 
 UINT16 ci ; /**< GSM Ncell identity */	 
	 
 CiDevPlmnMcc mcc ; /**< Mobile country code ( 3 digitals ) . \sa CiDevPlmnMcc */	 
 CiDevPlmnMnc mnc ; /**< Mobile network code ( 2 or 3 digitals ) . \sa CiDevPlmnMnc */	 
	 
 UINT16 lac ; /**< Location area code */	 
 } CiDevGsmNcellSysInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmNcellRadioInfo_struct 
 {	 
 UINT8 fieldMap ; /**< bit0:C2 exist or not , bit1:C31 exist or not , bit2:C32 exist or not */	 
 INT16 c1 ; /**< GSM neigbour cell Path loss param C1*/	 
 INT16 rxLev ; /**< GSM neigbour cell GSM received signal level. ( -110..-30 ) */	 
	 
 INT16 c2 ; /**< GSM neigbour cell Path loss param C2*/	 
 INT16 c31 ; /**< GSM neigbour cell GPRS signal level threshold criterion param C31*/	 
 INT16 c32 ; /**< GSM neigbour cell GPRS cell ranking criterion param C32*/	 
 } CiDevGsmNcellRadioInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmNcellInfoGsm_struct 
 {	 
 CiDevGsmNcellSysInfo sysInfo ;	 
 CiDevGsmNcellRadioInfo radioInfo ;	 
 } CiDevGsmNcellInfoGsm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmTdNcellInfoTdd_struct 
 {	 
 UINT8 cellParamId ; /**< Cell parameter id , ( 0 ..127 ) */	 
 UINT16 uArfcn ; /**< UARFCN , ( 0 ..16383 ) , real frequency ( MHz ) =UARFCN / 5 */	 
 UINT8 pccpchRSCP ; /**< PCCPCH RSCP , ( 0 ..91 ) real value ( dbm ) =IE value -116 */	 
 UINT8 utraRssi ; /**< UTRA carrier RSSI , ( 0 ..76 ) real value ( dbm ) =IE value - 101 */	 
 } CiDevGsmNcellInfoTdd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmNcellInfo_struct 
 {	 
 UINT8 numNcellGsm ;	 
 CiDevGsmNcellInfoGsm nbCellInfoGsm [ 6 ] ;	 
	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 UINT8 numNcellTdd ; /**< Note: numNcellGsm+numNcellTdd <= CI_DEV_MAX_GSM_NEIGHBORING_CELLS */	 
 CiDevGsmNcellInfoTdd nbCellInfoTdd [ 6 ] ;	 
 } CiDevGsmNcellInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_SPEECH_CODE_TAG {	 
 CI_DEV_GSM_SPEECH_GSM_HR = 0 ,	 
 CI_DEV_GSM_SPEECH_GSM_FR ,	 
 CI_DEV_GSM_SPEECH_GSM_EFR ,	 
 CI_DEV_GSM_SPEECH_HR_AMR ,	 
 CI_DEV_GSM_SPEECH_FR_AMR ,	 
	 
 CI_DEV_NUM_GSM_SPEECH	 
 } _CiDevGsmSpeechCode;

typedef UINT8 CiDevGsmSpeechCode ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_DED_CHANNEL_TYPE_TAG {	 
 CI_DEV_GSM_DEDICATED_TCH = 0 ,	 
 CI_DEV_GSM_DEDICATED_SDCCH ,	 
 CI_DEV_GSM_DEDICATED_PDCH ,	 
	 
 CI_DEV_NUM_GSM_DEDICATED_CHANNEL	 
 } _CiDevGsmDedChannelType;

typedef UINT8 CiDevGsmDedChannelType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmCellAlloc_struct 
 {	 
 UINT8 numCellAlloc ; /**< The number of Cell Allocation. ( 1 ~64 ) */	 
 UINT16 cellAlloc [ 64 ] ; /**< Cell Allocation list. ( 0 ~1024 ) */	 
 } CiDevGsmCellAlloc;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmDedArfcn_struct 
 {	 
 CiBoolean hoppingChannel ; /**< dedicated channel support arfcn hopping or not */	 
 UINT16 arfcn ; /**< absolute RF channel number. ( 0 ..1023 ) only exist when hoppingChannel=0 */	 
 CiDevHoppingGroup hoppingGroup ; /**< Hopping List , exist when hoppingChannel=1 */	 
 CiDevGsmCellAlloc cellAlloc ; /**< Cell Allocation*/	 
	 
 UINT8 MAIO ; /**< mobile allocation index offset , ( 0 ..63 ) exist when hoppingChannel=1*/	 
 UINT8 HSN ; /**< hopping sequence number , ( 0 ..63 ) exist when hoppingChannel=1*/	 
 } CiDevGsmDedArfcn;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmDedChannelInfo_struct 
 {	 
 UINT8 fieldMap ; /**< Bit0:Ded_arfcn_beforetime ; Bit1:Speech code used ; Bit2:Ded_arfcn_after_time and tn */	 
 CiDevGsmDedArfcn arfcnAfterTime ; /**< Arfcn of dedicated channel after starting timer */	 
	 
 UINT8 tn ; /**< current dedicated maining link timeslot mapping ( List of timeslots used. ( 0 ..7 ) */	 
	 
 CiDevGsmSpeechCode speechCode ; /**< Speech code used */	 
 CiDevGsmDedChannelType channelType ; /**< Channel Type */	 
	 
 CiDevGsmDedArfcn arfcnBeforeTime ; /**< Arfcn of dedicated channel before starting timer */	 
 } CiDevGsmDedChannelInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmDedMeasInfo_struct 
 {	 
 UINT8 sCellRxQualFull ; /**< Dedicated channel RXQUAL_FULL , ( 0 ..7 ) */	 
 UINT8 sCellRxQualSub ; /**< Dedicated channel RXQUAL_SUB , ( 0 ..7 ) */	 
 UINT8 sCellTimingAdv ; /**< TA , ( 0 ..63 ) , 0xff :invalid value */	 
 UINT8 sCellTxPower ; /**< power class of current dedicated channel */	 
	 
 UINT8 sCellRxLevFull ; /**< service cell received signal level full , ( 0 ..63 ) invalid value 0xff , real value ( dBm ) =IE value-110 */	 
 UINT8 sCellRxLevSub ; /**< service cell received signal level sub , ( 0 ..63 ) invalid value 0xff , real value ( dBm ) =IE value-110 */	 
 UINT8 res1U8 ; /**< ( padding ) */	 
 UINT8 bler ; /**< Block error rate for all code schemes. The actual ratio should be devided by 0xff :invalid value*/	 
 } CiDevGsmDedMeasInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmTimeSlotCi_struct 
 {	 
 UINT8 tsNo ; /**< Timeslot */	 
 INT16 rxLev ;	 
 INT16 ci ; /**< Bit0~bit7 ( LSB ) :decimal part , unsigned data ; Bit8~bit15 ( LSB ) : integer part , signed data. */	 
 } CiDevGsmTimeSlotCi;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmArfcnCiRep_struct 
 {	 
 UINT16 arfcn ; /**< BCCH Frequency , ( 0 ..1023 ) */	 
 CiDevGsmBand band ; /**< Frequency band */	 
	 
 UINT8 numSlot ; /**< The number of slots which this arfcn has appeared at one time. ( 0 ..4 ) */	 
 CiDevGsmTimeSlotCi slotCiArray [ 4 ] ;	 
 } CiDevGsmArfcnCiRep;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmCIInfo_struct 
 {	 
 UINT8 repArfcnNum ; /**< The number of the arfcn reported. ( 0 ..64 ) */	 
 CiDevGsmArfcnCiRep data [ 64 ] ;	 
 } CiDevGsmCIInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmBepCvBepInfo_struct 
 {	 
 CiBoolean isGmskValid ; /**< 0 :GMSK_MEAN_BEP and GMSK_CV_BEP is absent ; 1 :GMSK_MEAN_BEP and GMSK_CV_BEP is present*/	 
 UINT8 gmskMeanBepCvBep ; /**< GMSK_MEAN_BEP: High 5 bits of 1 octet ; GMSK_CV_BEP: Low 3 bits of above octet*/	 
	 
 CiBoolean is8pskValid ; /**< 0 :8PSK_MEAN_BEP and 8 PSK_CV_BEP is absent ; 1 :8PSK_MEAN_BEP and 8 PSK_CV_BEP is present*/	 
 UINT8 psk8MeanBepCvBep ; /**< 8 PSK_MEAN_BEP: High 5 bits of 1 octet ; 8 PSK_CV_BEP: Low 3 bits of above octet*/	 
 } CiDevGsmBepCvBepInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmUlCsMcs_struct 
 {	 
 UINT32 frameNo ; /**< Frame number of this UL block */	 
 CiDevGsmCodingScheme mcsCs ; /**< 7 ~10:CS1~CS4 ; 11 ~19:MCS1~MCS9 */	 
 } CiDevGsmUlCsMcs;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmMcsCs_struct 
 {	 
 UINT8 tsNo ; /**< Timeslot of this DL block */	 
 CiDevGsmCodingScheme mcsCs ; /**< 7 ~10:CS1~CS4 ; 11 ~19:MCS1~MCS9 */	 
 } CiDevGsmMcsCs;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmDlCsMcs_struct 
 {	 
 UINT32 frameNo ; /**< Frame number of this DL block */	 
	 
 UINT8 blkNum ; /**< The number of DL block received */	 
 CiDevGsmMcsCs mcsCs [ 4 ] ;	 
 } CiDevGsmDlCsMcs;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmMcsCsInfo_struct 
 {	 
 UINT8 ulLength ; /**< The number of UL_CS_MCS in peroid 1 s*/	 
 CiDevGsmUlCsMcs ulCsMcs [ 50 ] ;	 
	 
 UINT8 dlLength ; /**< The number of DL_CS_MCS in peroid 1 s*/	 
 CiDevGsmDlCsMcs dlCsMcs [ 50 ] ;	 
 } CiDevGsmMcsCsInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmTfiTimeslot_struct 
 {	 
 CiBoolean isUlTfiValid ; /**< 0 :UL_TFI and UL timeslot allocation is absent ; 1 : UL_TFI and UL timeslot allocation is present*/	 
 UINT8 ulTfi ; /**< UL_TFI */	 
 UINT8 ulTimeSlotAlloc ; /**< UL timeslot allocation */	 
	 
 CiBoolean isDlTfiValid ; /**< 0 :DL_TFI and DL timeslot allocation is absent ; 1 : DL_TFI and DL timeslot allocation is present*/	 
 UINT8 dlTfi ; /**< DL_TFI*/	 
 UINT8 dlTimeSlotAlloc ; /**< DL timeslot allocation */	 
 } CiDevGsmTfiTimeslot;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmData_struct 
 {	 
 CiDevGsmScellSysInfo sCellSysInfo ; /**< Serving cell system information. */	 
 UINT8 sCellSysInfoDtxInd ; /**< Serving cell reselection system information.	 
 ( 0 ..2 ) , DTX indicator , 0 :the MS may use uplink discontinous transmission ,	 
 1 :the MS shall use uplink discontinous transmission ,	 
 2 :the MS shall not use uplink discontinous transmission*/	 
	 
 CiDevGsmScellRadioInfo sCellRadioInfo ; /**< Serving cell radio information. */	 
 CiDevGsmNcellInfo nCellInfo ; /**< Neighbour cell information. */	 
	 
 CiDevGsmDedChannelInfo dedChannelInfo ; /**< Dedicated channel information. */	 
 CiDevGsmDedMeasInfo dedMeasInfo ; /**< Dedicated measurement information. */	 
	 
 CiDevGsmCIInfo ciInfo ; /**< C / I. */	 
 CiDevGsmBepCvBepInfo bepCvBepinfo ; /**< BEP / CV BEP. */	 
 CiDevGsmMcsCsInfo mscCsInfo ; /**< MCS / CS ( up / down ) . */	 
 CiDevGsmTfiTimeslot tfiTimeSlotInfo ; /**< TFI ( up / down ) and Timeslot Allocation ( up / down ) . */	 
 } CiDevGsmData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevMobileId_struct 
 {	 
 UINT8 digitSize ;	 
 UINT8 digit [ 16 ] ;	 
 } CiDevMobileId;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUeId_struct 
 {	 
 CiDevMobileId imei ; /**< IMEI for 14 ~16 digit. \sa CiDevMobileId */	 
 CiDevMobileId imsi ; /**< IMSI for 15 digit. \sa CiDevMobileId */	 
 CiDevMobileId tmsi ; /**< TMSI for 4 Hex. \sa CiDevMobileId */	 
 CiDevMobileId ptmsi ; /**< PTMSI for 4 Hex. \sa CiDevMobileId */	 
 } CiDevUeId;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevMmInfo_struct 
 {	 
 CiDevPlmnMcc mcc ; /**< Mobile country code ( 3 digitals ) . \sa CiDevPlmnMcc */	 
 CiDevPlmnMnc mnc ; /**< Mobile network code ( 2 or 3 digitals ) . \sa CiDevPlmnMnc */	 
	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 res1U16 ; /**< ( padding ) */	 
 } CiDevMmInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonData_struct 
 {	 
 CiDevUeId ueId ; /**< UE ID */	 
 CiDevMmInfo mmInfo ; /**< MM inforamtion */	 
 } CiDevCommonData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevWirelessParam_struct 
 {	 
 CiDevTddData tddInfo ; /**< TDSCDMA parameters */	 
 CiDevCommonData commonInfo ; /**< Common parameters */	 
 CiDevGsmData gsmInfo ; /**< GSM parameters */	 
 } CiDevWirelessParam;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_SYSTEM_INFO_TYPE_TAG {	 
 CI_DEV_SYS_INFO_TYPE_MIB = 0 ,	 
 CI_DEV_SYS_INFO_TYPE_SB1 ,	 
 CI_DEV_SYS_INFO_TYPE_SB2 ,	 
 CI_DEV_SYS_INFO_TYPE1 ,	 
 CI_DEV_SYS_INFO_TYPE2 ,	 
 CI_DEV_SYS_INFO_TYPE3 ,	 
 CI_DEV_SYS_INFO_TYPE4 ,	 
 CI_DEV_SYS_INFO_TYPE5 ,	 
 CI_DEV_SYS_INFO_TYPE6 ,	 
 CI_DEV_SYS_INFO_TYPE7 ,	 
 CI_DEV_SYS_INFO_TYPE8 ,	 
 CI_DEV_SYS_INFO_TYPE9 ,	 
 CI_DEV_SYS_INFO_TYPE10 ,	 
 CI_DEV_SYS_INFO_TYPE11 ,	 
 CI_DEV_SYS_INFO_TYPE12 ,	 
 CI_DEV_SYS_INFO_TYPE13 ,	 
 CI_DEV_SYS_INFO_TYPE13_1 ,	 
 CI_DEV_SYS_INFO_TYPE13_2 ,	 
 CI_DEV_SYS_INFO_TYPE13_3 ,	 
 CI_DEV_SYS_INFO_TYPE13_4 ,	 
 CI_DEV_SYS_INFO_TYPE14 ,	 
 CI_DEV_SYS_INFO_TYPE15 ,	 
 CI_DEV_SYS_INFO_TYPE15_1 ,	 
 CI_DEV_SYS_INFO_TYPE15_2 ,	 
 CI_DEV_SYS_INFO_TYPE15_3 ,	 
 CI_DEV_SYS_INFO_TYPE15_4 ,	 
 CI_DEV_SYS_INFO_TYPE15_5 ,	 
 CI_DEV_SYS_INFO_TYPE16 ,	 
 CI_DEV_SYS_INFO_TYPE17 ,	 
 CI_DEV_SYS_INFO_TYPE18 ,	 
 CI_DEV_SYS_INFO_TYPE5bis ,	 
	 
 CI_DEV_NUM_SYS_FINO	 
 } _CiDevSystemInfoType;

typedef UINT8 CiDevSystemInfoType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevBcchFachParam_struct 
 {	 
 UINT8 rbId ; /**< Rb identity. Value 34 , It is used for message from FACH to BCCH*/	 
 UINT16 noTb ; /**< Indicates the number of transport blocks transmitted by the peer entity within the TTI , beased on the TFI value*/	 
 } CiDevBcchFachParam;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPcchPchParam_struct 
 {	 
 UINT8 rbId ; /**< Rb identity. Value 33 , It is used for message from PCH to PCCH*/	 
 UINT16 noTb ; /**< Indicates the number of transport blocks transmitted by the peer entity within the TTI , beased on the TFI value*/	 
 } CiDevPcchPchParam;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAmDataInd_struct 
 {	 
 UINT8 fieldInd ; /**< Indicate the presence or absence of peer_msg and disc_info. 1 :peer_msg exists ; 2 :disc_info exists*/	 
 UINT16 discInfo ; /**< Indicates to ULR the discarded RLC SDU in the peer-RLC AM entity. 0 ~65535*/	 
 } CiDevAmDataInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTmDataInd_struct 
 {	 
 CiBoolean errIndFlag ; /**< Indicate the presence or absence of error_ind. 1 means exists. When " err_SDU_delv " is configured as YES and	 
 there are SDUs received in error , the err_ind parameter is present*/	 
 UINT8 errInd ; /**< Indicates that the RLC SDU is erroneous*/	 
 } CiDevTmDataInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevDataIndPara_struct 
 {	 
 UINT8 rlcMode ; /**< RLC mode. 1 :AM ; 2 :UM ; 3 :TM ; Other values are reserved*/	 
	 
 union	 
 {		 
 CiDevAmDataInd dlAmData ;		 
 CiDevTmDataInd dlTmData ;		 
 } dataIndPara ;	 
 } CiDevDataIndPara;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevDlCchParam_struct 
 {	 
 UINT8 rbId ; /**< Rb identity. 0 :CCCH ; 1 ~32:DCCH ; 36 :MCCH*/	 
 CiDevDataIndPara dataIndPara ; /**< \sa CiDevDataIndPara */	 
 } CiDevDlCchParam;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAmDataReq_struct 
 {	 
 CiBoolean cnfReq ; /**< If the value is true , uplayer requests RLC to confirm the reception of RLC SDUs by te peer-RLC AM entity.	 
 If the value is false , no confirmation is requested*/	 
 CiBoolean fieldInd ; /**< Indicate the presence or absence of MUI. When disc_req and CNF are both false , MUI does not exist. other situation , MUI exists.*/	 
 UINT16 mui ; /**< RLC shall give discarded info using this identifier for SDU. MUI: 0 ~65535*/	 
 } CiDevAmDataReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmDataReq_struct 
 {	 
 UINT16 mui ; /**< RLC shall give discarded info using this identifier for SDU. MUI: 0 ~65535*/	 
 } CiDevUmDataReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevTmDataReq_struct 
 {	 
 UINT16 mui ; /**< RLC shall give discarded info using this identifier for SDU. MUI: 0 ~65535*/	 
 } CiDevTmDataReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUlCchParam_struct 
 {	 
 UINT8 rbId ; /**< Rb identity. 0 ~32*/	 
 CiBoolean discReq ; /**< If the value is true , uplink layer requests RLC for the discarded RLC SDU by local entity.	 
 If the value if false , no discarded RLC SDU is requested*/	 
 CiDevDataReqPara dataReqPara ; /**< \sa CiDevDataReqPara */	 
 } CiDevUlCchParam;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_CHANNEL_TYPE_TAG {	 
 CI_DEV_GSM_PBCCH = 1 ,	 
 CI_DEV_GSM_PRACH ,	 
 CI_DEV_GSM_PCCCH ,	 
 CI_DEV_GSM_PDTCH ,	 
 CI_DEV_GSM_PACCH ,	 
 CI_DEV_GSM_BCCH ,	 
 CI_DEV_GSM_N_BCCH ,	 
 CI_DEV_GSM_E_BCCH ,	 
 CI_DEV_GSM_CCCH ,	 
 CI_DEV_GSM_PAG_CH ,	 
 CI_DEV_GSM_RACH ,	 
	 
 CI_DEV_GSM_SDCCH ,	 
 CI_DEV_GSM_SDCCH4_0 , /**< SDCCH / 4 subchannel number 0 */	 
 CI_DEV_GSM_SDCCH4_1 , /**< SDCCH / 4 subchannel number 1 */	 
 CI_DEV_GSM_SDCCH4_2 , /**< SDCCH / 4 subchannel number 2 */	 
 CI_DEV_GSM_SDCCH4_3 , /**< SDCCH / 4 subchannel number 3 */	 
 CI_DEV_GSM_SDCCH8_0 , /**< SDCCH / 8 subchannel number 0 */	 
 CI_DEV_GSM_SDCCH8_1 , /**< SDCCH / 8 subchannel number 1 */	 
 CI_DEV_GSM_SDCCH8_2 , /**< SDCCH / 8 subchannel number 2 */	 
 CI_DEV_GSM_SDCCH8_3 , /**< SDCCH / 8 subchannel number 3 */	 
 CI_DEV_GSM_SDCCH8_4 , /**< SDCCH / 8 subchannel number 4 */	 
 CI_DEV_GSM_SDCCH8_5 , /**< SDCCH / 8 subchannel number 5 */	 
 CI_DEV_GSM_SDCCH8_6 , /**< SDCCH / 8 subchannel number 6 */	 
 CI_DEV_GSM_SDCCH8_7 , /**< SDCCH / 8 subchannel number 7 */	 
	 
 CI_DEV_GSM_SACCH ,	 
 CI_DEV_GSM_FACCH ,	 
 CI_DEV_GSM_TCH_F ,	 
 CI_DEV_GSM_TCH_H_0 , /**< TCH / H subchannel number 0 */	 
 CI_DEV_GSM_TCH_H_1 , /**< TCH / H subchannel number 1 */	 
	 
 CI_DEV_GSM_PPCH ,	 
 CI_DEV_GSM_ETCH_F ,	 
 CI_DEV_GSM_ATCH_F ,	 
 CI_DEV_GSM_ATCH_H ,	 
 CI_DEV_GSM_EIACCH_F ,	 
 CI_DEV_GSM_CBCH_4 ,	 
 CI_DEV_GSM_CBCH_8 ,	 
	 
 CI_DEV_NUM_GSM_CHANNEL	 
 } _CiDevGsmChannelType;

typedef UINT8 CiDevGsmChannelType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_GSM_BURST_TYPE_TAG {	 
 CI_DEV_GSM_ONE_ACCESS_BURST_OF_TYPE_8_BITS = 0 ,	 
 CI_DEV_GSM_ONE_ACCESS_BURST_OF_TYPE_11_BITS ,	 
 CI_DEV_GSM_FOUR_ACCESS_BURST_OF_TYPE_8_BITS ,	 
 CI_DEV_GSM_FOUR_ACCESS_BURST_OF_TYPE_11_BITS ,	 
 CI_DEV_GSM_FREQUENCY_CORRECTION_BURST ,	 
 CI_DEV_GSM_SYNCHRONIZATION_BURST ,	 
 CI_DEV_GSM_DUMMY_BURST ,	 
 CI_DEV_GSM_NORMAL_CS_1_RADIO_BLK_BURST ,	 
 CI_DEV_GSM_NORMAL_CS_2_RADIO_BLK_BURST ,	 
 CI_DEV_GSM_NORMAL_CS_3_RADIO_BLK_BURST ,	 
 CI_DEV_GSM_NORMAL_CS_4_RADIO_BLK_BURST ,	 
 CI_DEV_GSM_NORMAL_BURST = CI_DEV_GSM_NORMAL_CS_1_RADIO_BLK_BURST ,	 
	 
 CI_DEV_NUM_GSM_BURST	 
 } _CiDevGsmBurstType;

typedef UINT8 CiDevGsmBurstType ;
typedef UINT8 CiDevGsmSignalName ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmParam_struct 
 {	 
 CiBoolean isBadFrame ; /**< 1 : bad frame ; 0 :not bad frame*/	 
 CiBoolean isUpDownData ; /**< 1 : uplink data ; 0 :downlink data*/	 
 CiBoolean isNasMsg ; /**< 1 : nas message ; 0 :not nas message*/	 
	 
 CiDevGsmChannelType chType ; /**< \sa CiDevGsmChannelType */	 
 CiDevGsmCodingScheme cs ; /**< \sa CiDevGsmCodingScheme */	 
 CiDevGsmBurstType burstType ; /**< \sa CiDevGsmBurstType */	 
 CiDevGsmSignalName signalName ; /*add for GSM message decode*/	 
	 
 UINT8 sapi ; /**< sapi=0 or sapi=3 , other reserved */	 
 } CiDevGsmParam;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_NETWORK_MONITOR_OPTION_REQ " > */ 
 typedef struct CiDevPrimSetNetworkMonitorOptReq_struct 
 {	 
 CiBoolean Option ; /**< Always hard coded with zero. \sa CiBoolean */	 
 CiDevNwMonitorMode Mode ; /**< Report mode. \sa CiDevNwMonitorMode */	 
 } CiDevPrimSetNetworkMonitorOptReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_NETWORK_MONITOR_OPTION_CNF " > */ 
 typedef struct CiDevPrimSetNetworkMonitorOptCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimSetNetworkMonitorOptCnf;

typedef CiEmptyPrim CiDevPrimGetNetworkMonitorOptReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_GET_NETWORK_MONITOR_OPTION_CNF " > */ 
 typedef struct CiDevPrimGetNetworkMonitorOptCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 CiBoolean Option ; /**< Always hard coded with zero. \sa CiBoolean */	 
 CiDevNwMonitorMode Mode ; /**< Report mode. \sa CiDevNwMonitorMode */	 
 } CiDevPrimGetNetworkMonitorOptCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_PROTOCOL_STATUS_CONFIG_REQ " > */ 
 typedef struct CiDevPrimSetProtocolStatusConfigReq_struct 
 {	 
 CiBoolean Option ; /**< 0 : disable unsolicited result code ( default ) ; 1 :enable unsolicited result code*/	 
 } CiDevPrimSetProtocolStatusConfigReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_PROTOCOL_STATUS_CONFIG_CNF " > */ 
 typedef struct CiDevPrimSetProtocolStatusConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimSetProtocolStatusConfigCnf;

typedef CiEmptyPrim CiDevPrimGetProtocolStatusConfigReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_GET_PROTOCOL_STATUS_CONFIG_CNF " > */ 
 typedef struct CiDevPrimGetProtocolStatusConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 CiBoolean Option ; /**< 0 : disable unsolicited result code ( default ) ; 1 :enable unsolicited result code*/	 
 } CiDevPrimGetProtocolStatusConfigCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_PROTOCOL_STATUS_CHANGED_IND " > */ 
 typedef struct CiDevPrimProtocolStatusChangedInd_struct 
 {	 
 CiDevProtocolStatus status ; /**< Protocol status. \sa CiDevProtocolStatus */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 } CiDevPrimProtocolStatusChangedInd;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_EVENT_IND_CONFIG_REQ " > */ 
 typedef struct CiDevPrimSetEventIndConfigReq_struct 
 {	 
 CiBoolean Option ; /**< 0 : disable intermediate result code ( default ) ; 1 :enable intermediate result code*/	 
 } CiDevPrimSetEventIndConfigReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_EVENT_IND_CONFIG_CNF " > */ 
 typedef struct CiDevPrimSetEventIndConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimSetEventIndConfigCnf;

typedef CiEmptyPrim CiDevPrimGetEventIndConfigReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_GET_EVENT_IND_CONFIG_CNF " > */ 
 typedef struct CiDevPrimGetEventIndConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 CiBoolean Option ; /**< 0 : disable unsolicited result code ( default ) ; 1 :enable unsolicited result code*/	 
 } CiDevPrimGetEventIndConfigCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_EVENT_REPORT_IND " > */ 
 typedef struct CiDevPrimEventReportInd_struct 
 {	 
 UINT32 timeStamp ; /**< System tick value , ( 0 , -2147483648 ) .*/	 
 CiBitRange operationType ; /**< Operation type , bitmap - bit0:CS voice ; bit1:CS data ; bit2:PS ; bit3:SMS \sa CiDevEventOperType */	 
 CiDevEventId eventId ; /**< Event ID.*/	 
 } CiDevPrimEventReportInd;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_WIRELESS_PARAM_CONFIG_REQ " > */ 
 typedef struct CiDevPrimSetWirelessParamConfigReq_struct 
 {	 
 CiBoolean Option ; /**< 0 : disable result code presentation to TE ( default ) ; 1 :enable result code presentation to TE*/	 
 UINT16 Interval ; /**< Report Interval ( seconds ) for PERIODIC , default 3 s */	 
 } CiDevPrimSetWirelessParamConfigReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_WIRELESS_PARAM_CONFIG_CNF " > */ 
 typedef struct CiDevPrimSetWirelessParamConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimSetWirelessParamConfigCnf;

typedef CiEmptyPrim CiDevPrimGetWirelessParamConfigReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_GET_WIRELESS_PARAM_CONFIG_CNF " > */ 
 typedef struct CiDevPrimGetWirelessParamConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 CiBoolean Option ; /**< 0 : disable result code presentation to TE ( default ) ; 1 :enable result code presentation to TE*/	 
 UINT16 Interval ; /**< Report Interval ( seconds ) for PERIODIC , default 3 s */	 
 } CiDevPrimGetWirelessParamConfigCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_WIRELESS_PARAM_IND " > */ 
 typedef struct CiDevPrimWirelessParamInd_struct 
 {	 
 CiDevEngModeNetwork network ; /**< Network Type ( GSM / UMTS ) . \sa CiDevEngModeNetwork */	 
	 
 UINT32 timeStamp ; /**< System tick value , ( 0 , -2147483648 ) .*/	 
	 
 CiDevCommonData commonInfo ; /**< Common parameters */	 
	 
 UINT32 data_size ; /**< Size of data for CiDevTddData / CiDevGsmData */	 
 UINT8 tddGsmData [ 1908 ] ; /**< data for CiDevTddData / CiDevGsmData */	 
 UINT8 count ; /**< Ordinal number of the data. [ range:1-2 ] */	 
 } CiDevPrimWirelessParamInd;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_SIGNALING_REPORT_CONFIG_REQ " > */ 
 typedef struct CiDevPrimSetSignalingReportConfigReq_struct 
 {	 
 CiBoolean Option ; /**< 0 : disable unsolicited result code ( default ) ; 1 :enable unsolicited result code*/	 
 CiBoolean Mode ; /**< 0 : disable Uu signaling report ( default ) ; 1 :enable Uu signaling report*/	 
 } CiDevPrimSetSignalingReportConfigReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_SIGNALING_REPORT_CONFIG_CNF " > */ 
 typedef struct CiDevPrimSetSignalingReportConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 } CiDevPrimSetSignalingReportConfigCnf;

typedef CiEmptyPrim CiDevPrimGetSignalingReportConfigReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_GET_SIGNALING_REPORT_CONFIG_CNF " > */ 
 typedef struct CiDevPrimGetSignalingReportConfigCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 CiBoolean Option ; /**< 0 : disable unsolicited result code ( default ) ; 1 :enable unsolicited result code*/	 
 CiBoolean Mode ; /**< 0 : disable Uu signaling report ( default ) ; 1 :enable Uu signaling report*/	 
 } CiDevPrimGetSignalingReportConfigCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SIGNALING_REPORT_IND " > */ 
 typedef struct CiDevPrimSignalingReportInd_struct 
 {	 
 UINT16 totalMsglen ; /**< The total message length = parameter length + peer message length + 17 */	 
 UINT8 frameType ; /**< The type of freame , 0xAA : used for trace data ; others: reserved.*/	 
	 
 CiDevSignalingMsgId msgId ; /**< The message identifier. \sa CiDevSignalingMsgId */	 
 UINT32 timeStamp ; /**< Timrt counter , Unit:ms , the value would be set to 0 when power on.*/	 
	 
 UINT16 paramLen ; /**< The length of the parameter data in byte , the length can be zero , in such case , the parameter would include nother */	 
 union	 
 {		 
 CiDevSystemInfoType bchParam ;		 
 CiDevBcchFachParam bcchFachParam ;		 
 CiDevPcchPchParam pcchPchParam ;		 
 CiDevDlCchParam dlCchParam ;		 
 CiDevUlCchParam ulCchParam ;		 
 CiDevGsmParam gsmParam ;		 
 } paramData ;	 
	 
 UINT16 peerMsgLen ; /**< The length of the peer message in byte */	 
 UINT16 freeHeaderSpaceLen ; /**< The length of the free bit header space in bit. It is said the number of the free header space length bits is just filled for alignment , and not usefull */	 
 UINT8 peerMsgData [ 356 ] ; /**< Peer message encoded with ASN.1.*/	 
 } CiDevPrimSignalingReportInd;

typedef UINT16 Arfcn ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimDipChannelChangeInd_struct 
 {	 
 CiDevNetworkMode networkMode ; // 0 : CI_DEV_NW_GSM ; 1 :CI_DEV_NW_UMTS ; 3 : CI_DEV_NW_LTE	 
 /*Arfcn*/ UINT32 arfcn ; /*Lilei , CQ00073839 , 20141023 */	 
 CiDevBand band ; // band: Dip band GSM : 0 : EGSM 1 :DCS 2 :PCS 6 :GSM850 ; WCDMA:1: BAND1 ; 2 :BAND2 ; ... ; 14 :BAND14 ; LTE: 1 : BAND1 ; 2 : BAND2...	 
 CiDevServiceType servicetype ;	 
 /*Added by Lilei for CQ58144 on 4032014 , begin*/	 
 UINT8 dipOption ; // 0 : disable ; 1 : enable manual mode for special case ( such as test model ) -default one ; 2 : enable manual mode for user model ; 3 : enable auto mode for end user ( not used )	 
 /*Added by Lilei for CQ58144 on 4032014 , end*/	 
 /*Added by Lilei for CQ58144 on 4292014 , begin*/	 
 CiBoolean LpmEnabled ; // 0 : Lpm disabled ; 1 : Lpm enabled	 
 /*Added by Lilei for CQ58144 on 4292014 , end*/	 
 } CiDevPrimDipChannelChangeInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSecurityParamsReq_struct {	 
 CiBoolean EnableCiphering ; /**< TRUE - ciphering capabilities are derived from NVM ; FALSE - ciphering capabilities are disabled. \sa CCI API Ref Manual */	 
 CiBoolean EnableIntegrityProtection ; /**< TRUE - integrity protection capabilities are derived from NVM ; FALSE - integrity protection capabilities are disabled. \sa CCI API Ref Manual */	 
 } CiDevPrimSetSecurityParamsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSecurityParamsCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetSecurityParamsCnf;

typedef CiEmptyPrim CiDevPrimGetSecurityParamsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSecurityParamsCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiBoolean EnableCiphering ; /**< TRUE - ciphering capabilities are derived from NVM ; FALSE - ciphering capabilities are disabled. \sa CCI API Ref Manual */	 
 CiBoolean EnableIntegrityProtection ; /**< TRUE - integrity protection capabilities are derived from NVM ; FALSE - integrity protection capabilities are disabled. \sa CCI API Ref Manual */	 
 } CiDevPrimGetSecurityParamsCnf;

//ICAT EXPORTED ENUM 
 /*add by taow 20180920 begin*/ 
 typedef enum CIDEV_SET_POWER_BACK_OFF_TYPE_TAG {	 
 CI_DEV_POWER_BACK_OFF = 0 , // for grip sensor control	 
 CI_DEV_POWER_BACK_ON = 1 , // for grip sensor control	 
 CI_DEV_POWER_REDUCTION = 2 , // for temperature control	 
 CI_DEV_POWER_RAISING = 3 , // for temperature control	 
 CI_DEV_POWER_PCLFIX = 4 , // for PCLFIX	 
	 
 CI_DEV_UNLOCK_FREQUENCY = 8 , // for frequency unthrottle	 
 CI_DEV_LOCK_FREQUENCY = 9 , // for frequency throttle	 
	 
 CI_DEV_NUM_OF_POWER_BACK_OFF_TYPES	 
 } _CiDevSetPowerBackOffType;

typedef UINT8 CiDevSetPowerBackOffType ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_POWER_BACK_OFF_REQ " > */ 
 typedef struct CiDevPrimSetPowerBackOffReq_struct 
 {	 
 CiDevSetPowerBackOffType PowerBackOffType ;	 
 UINT8 value ; /**< Specific value for certain type , such as power reduction / raising */	 
 /*Lilei , CQ00124125 , 20200914 , begin*/	 
 CiDevEngModeNetwork networkMode ; /**< 0 : GSM ; 1 : UMTS ; 2 : LTE ; 6 : all modes & bands ( default ) */	 
 UINT8 band ; /**< GSM: 0 -PGSM , 1 -DCS , 2 -PCS , 3 -EGSM , 4 -GSM450 , 5 -GSM480 , 6 -GSM850 ;	 
 WCDMA: 1 -BAND1 , 2 -BAND2 , ... , 14 :BAND14 ; LTE: 1 -BAND1 , 2 -BAND2...	 
 If mode is 0 / 1 / 2 ( single mode ) , band=0xFF means all bands.	 
 If mode is 6 ( multi-mode ) , band is not used.*/	 
 /*Lilei , CQ00124125 , 20200914 , end*/	 
 /*Lilei , CQ00137338 , 20220621 , begin*/	 
 UINT8 bandwidth ; /**< 0 : invalid ; 1 : 1.400000 MHz ; 2 : 3 MHz ; 3 : 5 MHz ; 4 : 10 MHz ; 5 : 15 MHz ; 6 : 20 MHz ; If bandwidth > 0 , then <value> is in 0.100000 Db unit*/	 
 /*Lilei , CQ00137338 , 20220621 , end*/	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 } CiDevPrimSetPowerBackOffReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_SET_POWER_BACK_OFF_CNF " > */ 
 typedef struct CiDevPrimSetPowerBackOffCnf_struct 
 {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 } CiDevPrimSetPowerBackOffCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevRevision_struct {	 
 UINT16 len ;	 
 CHAR valStr [ 400 ] ;	 
 } CiDevRevision;

typedef CiEmptyPrim CiDevPrimGetInternalRevisionIdReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_CNF " > */ 
 typedef struct CiDevPrimGetInternalRevisionIdCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 CiDevRevision internalRevisionStr ; /**< Internal Revision ID string. Max length is 100 . \sa CCI API Ref Manual */	 
 CiString buildTimeStr ; /**< Build Time string. Max length is 100 . \sa CCI API Ref Manual */	 
 } CiDevPrimGetInternalRevisionIdCnf;

//ICAT EXPORTED ENUM 
 /** \brief Mode of requested reset*/ 
 typedef enum CIDEVRESETMODETYPE_TAG {	 
 CI_DEV_RESET_FUN , /**< Perform Functionality reset ( CFUN=0 - CFUN=1 ) */	 
 CI_DEV_RESET_HW /**< Perform com hardware reset */	 
 } _CiDevResetModeType;

typedef UINT8 CiDevResetModeType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimResetRequestInd_struct {	 
 CiDevResetModeType reset_mode ;	 
 } CiDevPrimResetRequestInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetUsertestReportOptionReq_struct {	 
 CiBoolean enable ; /**< TRUE - Set User Testing reporting to ON ; FALSE - Set User Testing reporting to OFF. */	 
 UINT8 reserved [ 3 ] ;	 
 } CiDevPrimSetUsertestReportOptionReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetUsertestReportOptionCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetUsertestReportOptionCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUsertestValuableEventReportInd_struct {	 
 UINT32 initiator ; /**< Event initiator environment. */	 
 UINT32 eventType ; /**< Type of valuable event ( severity , etc. ) . */	 
 CiString eventDescription ; /**< Event description as ASCII string. */	 
 CiBoolean includeSdLog ; /**< Indicates if SD log should be sent to user test server. */	 
 UINT8 reserved [ 3 ] ;	 
 UINT32 binaryLogSize ; /**< Indicates how many bytes ( if any ) are used by binaryLog array. */	 
 UINT8 binaryLog [ 1024 ] ; /**< User supplied binary log. */	 
 } CiDevPrimUsertestValuableEventReportInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetParkModeReq_struct {	 
 CiBoolean enableParkMode ; /**< TRUE - enables park mode. FALSE disables park mode. \sa CCI API Ref Manual */	 
 UINT8 roamingTimer ; /**< timer value for PLMN search in roaming state. This override the default value \sa CCI API Ref Manual */	 
 UINT8 emergencyTimer ; /**< timer value for PLMN search in limited service state ( emergency only ) . This override the default value \sa CCI API Ref Manual */	 
 UINT8 oosTimer ; /**< timer value for PLMN search in out of service state. This override the default value \sa CCI API Ref Manual */	 
 } CiDevPrimSetParkModeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetParkModeCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetParkModeCnf;

typedef CiEmptyPrim CiDevPrimGetParkModeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetParkModeCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiBoolean enableParkMode ; /**< TRUE - enables park mode. FALSE disables park mode. \sa CCI API Ref Manual */	 
 UINT8 roamingTimer ; /**< timer value for PLMN search in roaming state. This override the default value \sa CCI API Ref Manual */	 
 UINT8 emergencyTimer ; /**< timer value for PLMN search in limited service state ( emergency only ) . This override the default value \sa CCI API Ref Manual */	 
 UINT8 oosTimer ; /**< timer value for PLMN search in out of service state. This override the default value \sa CCI API Ref Manual */	 
 } CiDevPrimGetParkModeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetIMSMediaReq_struct {	 
 UINT32 requestId ; /**< Media request identifier */	 
 UINT32 inBufSize ; /**< Media API input parameter length */	 
 UINT8 inBuf [ 1200 ] ; /**< array of char of length InBufSize */	 
 } CiDevPrimSetIMSMediaReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetIMSMediaCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 UINT32 retCode ; /**< Return Code Value */	 
 UINT32 outBufSize ; /**< Media API input parameter length */	 
 UINT8 outBuf [ 1200 ] ; /**< array of char of length OutBufSize */	 
 } CiDevPrimSetIMSMediaCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimIMSMediaInd_struct {	 
 UINT32 notifyCode ; /**< Media notification identifier */	 
 UINT32 bufSize ; /**< Media API parameter length */	 
 UINT8 buf [ 1200 ] ; /**< array of char of length BufSize */	 
 } CiDevPrimIMSMediaInd;

//ICAT EXPORTED ENUM 
 /** \brief Com Config types */ 
 /** \remarks Common Data Section */ 
 typedef enum CIDEV_COMCFG_TOKEN_TYPE {	 
	 
 CI_DEV_COMCFG_TOKEN_UMTS_WB_AMR = 0 ,	 
 CI_DEV_COMCFG_TOKEN_GSM_WB_AMR ,	 
 // CI_DEV_COMCFG_TOKEN_HSDPA ,	 
 // CI_DEV_COMCFG_TOKEN_HSUPA ,	 
 CI_DEV_COMCFG_TOKEN_VENDOR ,	 
 CI_DEV_COMCFG_TOKEN_MANUFACTURE ,	 
 /*Added by Lilei for LTE category on 5282014 , begin*/	 
 CI_DEV_COMCFG_TOKEN_LTE_CATEGORY ,	 
 /*Added by Lilei for LTE category on 5282014 , end*/	 
 /*Lilei , CQ00124026 , 20200910 , begin*/	 
 CI_DEV_COMCFG_TOKEN_MULTISLOT_POWERPROFILE = 5 ,	 
 /*Lilei , CQ00124026 , 20200910 , end*/	 
	 
 CI_DEV_COMCFG_TOKEN_LTE_SMS_ONLY , /*presentation of SMS only for additional update type in ATTACH reqest or TAU*/	 
	 
 CI_DEV_COMCFG_TOKEN_EC_SUPPORTED , /*presentation of restriction of enhanced coverage in ATTACH reqest or TAU , 0 : not supported , EC is restrited ; 1 : supported , EC is not restricted */	 
 CI_DEV_COMCFG_TOKEN_EPCO_SUPPORTED , /* 0 - ePCO not support , 1 - ePCO support */	 
 CI_DEV_COMCFG_TOKEN_HCCP_SUPPORTED , /* 0 - HC-CP CIoT not support , 1 - HC-CP CIoT support */	 
 CI_DEV_COMCFG_TOKEN_MDRB_SUPPORTED = 10 , /* 0 - multipleDRB not support , 1 - multipleDRB support */	 
 CI_DEV_COMCFG_TOKEN_CP_BACKOFF , /* 0 - CP backoff not support , 1 - CP backoff support */	 
	 
 CI_DEV_COMCFG_TOKEN_NSLP , /* bitmap: bit 0 - nasSigLowPriority , bit 1 - overrideNasSignallingPriority */	 
 CI_DEV_COMCFG_TOKEN_EAB , /* bitmap: bit 0 - extendedAccessBarring , 1 - overrideExtendedAccessBarring */	 
	 
 CI_DEV_COMCFG_TOKEN_ROHC , /*RoHC profiles , bitmap: bit 0 ~8 , profile 0x0001 / 0x0002 / 0x0003 / 0x0004 / 0x0006 / 0x0101 / 0x0102 / 0x0103 / 0x0104 */	 
 /*Lilei , CQ00147330 , 20231201 , begin*/	 
 CI_DEV_COMCFG_TOKEN_ATTACH_WO_PDN = 15 , /* 0 - attachWithoutPdn not support , 1 - attachWithoutPdn support */	 
 /*Lilei , CQ00147330 , 20231201 , end*/	 
	 
 CI_DEV_NUM_COMCFG_TOKEN	 
	 
 } _CiDevComcfgTokenType;

typedef UINT8 CiDevComcfgTokenType ;
//ICAT EXPORTED ENUM 
 /** \brief Vendor types */ 
 /** \remarks Common Data Section */ 
 typedef enum CIDEV_COMCFG_VENDOR_TYPE {	 
	 
 CI_DEV_COMCFG_VENDOR_NONE = 0 ,	 
 CI_DEV_COMCFG_VENDOR_ATT ,	 
 CI_DEV_COMCFG_VENDOR_CMCC ,	 
 CI_DEV_COMCFG_VENDOR_IOT , /**< it is not for vendor specific , just for some implements such as CC redial*/	 
 CI_DEV_COMCFG_VENDOR_TELCEL ,	 
 CI_DEV_COMCFG_VENDOR_H3G ,	 
 CI_DEV_COMCFG_VENDOR_VDF ,	 
 CI_DEV_COMCFG_VENDOR_SILVER , /**< it is not for vendor specific , just for some implements of MANUFACTURE*/	 
 CI_DEV_COMCFG_VENDOR_ORG ,	 
 CI_DEV_COMCFG_VENDOR_TMOBILE ,	 
 CI_DEV_COMCFG_VENDOR_VERIZON ,	 
 CI_DEV_COMCFG_VENDOR_HP ,	 
 /*Added by Lilei for CQ58190 on 4042014 , begin*/	 
 CI_DEV_COMCFG_VENDOR_CLOSE_RAMLOG_SWITCH , /**< it is not for vendor specific , just for some implements */	 
 CI_DEV_COMCFG_VENDOR_2G_ROAMING ,	 
 CI_DEV_COMCFG_VENDOR_RRM ,	 
 CI_DEV_COMCFG_VENDOR_CMCC_FRSUPPORT ,	 
 CI_DEV_COMCFG_VENDOR_SILENTRESET , /**< it is not for vendor specific , just for some implements */	 
 CI_DEV_COMCFG_VENDOR_PSOPT , /**< it is not for vendor specific , just for some implements */	 
 CI_DEV_COMCFG_VENDOR_HOMETEST ,	 
 CI_DEV_COMCFG_VENDOR_MTNET ,	 
 /*Added by Lilei for CQ58190 on 4042014 , end*/	 
 CI_DEV_COMCFG_VENDOR_DEUTSCHETELE ,	 
 CI_DEV_COMCFG_VENDOR_CMCC_5MODE_ROAMING ,	 
	 
 CI_DEV_NUM_COMCFG_VENDOR_TYPE	 
	 
 } _CiDevComcfgVendorType;

typedef UINT8 CiDevComcfgVendorType ;
//ICAT EXPORTED ENUM 
 /** \brief Manufacture types */ 
 /** \remarks Common Data Section */ 
 typedef enum CIDEV_COMCFG_MANUFACTURE_TYPE {	 
	 
 CI_DEV_COMCFG_MANUFACTURE_NONE = 0 ,	 
 CI_DEV_COMCFG_MANUFACTURE_M_SILVER ,	 
	 
 CI_DEV_NUM_COMCFG_MANUFACTURE_TYPE	 
	 
 } _CiDevComcfgManufactureType;

typedef UINT8 CiDevComcfgManufactureType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevComcfgToken_struct {	 
 CiDevComcfgTokenType name ; /**< Token name \sa CiDevComcfgTokenType */	 
 /*UINT16*/ UINT32 value ; /**< Token value */ // Modified by Lilei 4042014 CQ58190	 
 } CiDevComcfgToken;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetComConfigReq_struct {	 
 UINT8 numTokens ; /**< Number of tokens to set */	 
 CiDevComcfgToken Token [ CI_DEV_NUM_COMCFG_TOKEN ] ; /**< Tokens info \sa CiDevComcfgToken */	 
 } CiDevPrimSetComConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetComConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetComConfigCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetComConfigReq_struct {	 
 CiBitRange tokens ; /**< This is a bitmap representing the Token to get. The bitmap format matches the enum CIDEV_COMCFG_TOKEN_TYPE */	 
 } CiDevPrimGetComConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetComConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT8 numTokens ; /**< Number of tokens */	 
 CiDevComcfgToken Token [ CI_DEV_NUM_COMCFG_TOKEN ] ; /**< Tokens info \sa CiDevComcfgToken */	 
 } CiDevPrimGetComConfigCnf;

typedef CiEmptyPrim CiDevPrimGetLteMeasReq ;
//ICAT EXPORTED STRUCT 
 typedef struct LteMeasInfo_tag {	 
 UINT16 cellID ; /**< Cell ID of lte rsrp&rsrq measurement info */	 
 UINT32 earfcn ; /**< Arfcn */	 
 UINT8 rsrp ; /**< Rsrp info */	 
 UINT8 rsrq ; /**< Rsrq Info */	 
 } LteMeasInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetLteMeasCnf_struct {	 
 CiDevRc result ; /**< Result code. \sa CiDevRc. */	 
 UINT8 num ; /**< Number of cells that confirm rsrp&rsrq info. */	 
 LteMeasInfo eMeasInfo [ 32 ] ; /**< Rsrp&rsrq measurement info. \sa LteMeasInfo */	 
 } CiDevPrimGetLteMeasCnf;

//ICAT EXPORTED ENUM 
 typedef enum CiDEVLTERRCSTATE_TAG 
 {	 
 CI_DEV_LTE_RRC_STATE_IDLE = 0 , /**< LTE RRC state IDLE */	 
 CI_DEV_LTE_RRC_STATE_CONNECTED /**< LTE RRC state CONNECTED */	 
 } _CiDevLteRrcState;

typedef UINT8 CiDevLteRrcState ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEVEUTRANBAND_TAG {	 
 CI_DEV_EUTRAN_BAND_FDD_1 = 1 , /**< E-UTRAN operating band 1 */	 
 CI_DEV_EUTRAN_BAND_FDD_2 , /**< E-UTRAN operating band 2 */	 
 CI_DEV_EUTRAN_BAND_FDD_3 , /**< E-UTRAN operating band 3 */	 
 CI_DEV_EUTRAN_BAND_FDD_4 , /**< E-UTRAN operating band 4 */	 
 CI_DEV_EUTRAN_BAND_FDD_5 , /**< E-UTRAN operating band 5 */	 
 CI_DEV_EUTRAN_BAND_FDD_6 , /**< E-UTRAN operating band 6 */	 
 CI_DEV_EUTRAN_BAND_FDD_7 , /**< E-UTRAN operating band 7 */	 
 CI_DEV_EUTRAN_BAND_FDD_8 , /**< E-UTRAN operating band 8 */	 
 CI_DEV_EUTRAN_BAND_FDD_9 , /**< E-UTRAN operating band 10 */	 
 CI_DEV_EUTRAN_BAND_FDD_10 , /**< E-UTRAN operating band 11 */	 
 CI_DEV_EUTRAN_BAND_FDD_11 , /**< E-UTRAN operating band 12 */	 
 CI_DEV_EUTRAN_BAND_FDD_12 , /**< E-UTRAN operating band 13 */	 
 CI_DEV_EUTRAN_BAND_FDD_13 , /**< E-UTRAN operating band 14 */	 
 CI_DEV_EUTRAN_BAND_FDD_14 , /**< E-UTRAN operating band 15 */	 
 CI_DEV_EUTRAN_BAND_FDD_15_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_FDD_16_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_FDD_17 , /**< E-UTRAN operating band 17 */	 
 CI_DEV_EUTRAN_BAND_FDD_18 , /**< E-UTRAN operating band 18 */	 
 CI_DEV_EUTRAN_BAND_FDD_19 , /**< E-UTRAN operating band 19 */	 
 CI_DEV_EUTRAN_BAND_FDD_20 , /**< E-UTRAN operating band 20 */	 
 CI_DEV_EUTRAN_BAND_FDD_21 , /**< E-UTRAN operating band 21 */	 
 CI_DEV_EUTRAN_BAND_FDD_22 , /**< E-UTRAN operating band 22 */	 
 CI_DEV_EUTRAN_BAND_FDD_23 , /**< E-UTRAN operating band 23 */	 
 CI_DEV_EUTRAN_BAND_FDD_24 , /**< E-UTRAN operating band 24 */	 
 CI_DEV_EUTRAN_BAND_FDD_25 , /**< E-UTRAN operating band 25 */	 
 CI_DEV_EUTRAN_BAND_FDD_26 , /**< E-UTRAN operating band 26 */	 
 CI_DEV_EUTRAN_BAND_FDD_27 , /**< E-UTRAN operating band 27 */	 
 CI_DEV_EUTRAN_BAND_FDD_28 , /**< E-UTRAN operating band 28 */	 
 CI_DEV_EUTRAN_BAND_FDD_29 , /**< E-UTRAN operating band 29 . Restricted to E-UTRA operation when CA is configured */	 
 CI_DEV_EUTRAN_BAND_FDD_30_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_FDD_31_NOT_USED ,	 
 CI_DEV_EUTRAN_BAND_FDD_32_NOT_USED ,	 
	 
 CI_DEV_EUTRAN_BAND_TDD_33 , /**< E-UTRAN operating band 33 */	 
 CI_DEV_EUTRAN_BAND_TDD_34 , /**< E-UTRAN operating band 34 */	 
 CI_DEV_EUTRAN_BAND_TDD_35 , /**< E-UTRAN operating band 35 */	 
 CI_DEV_EUTRAN_BAND_TDD_36 , /**< E-UTRAN operating band 36 */	 
 CI_DEV_EUTRAN_BAND_TDD_37 , /**< E-UTRAN operating band 37 */	 
 CI_DEV_EUTRAN_BAND_TDD_38 , /**< E-UTRAN operating band 38 */	 
 CI_DEV_EUTRAN_BAND_TDD_39 , /**< E-UTRAN operating band 39 */	 
 CI_DEV_EUTRAN_BAND_TDD_40 , /**< E-UTRAN operating band 40 */	 
 CI_DEV_EUTRAN_BAND_TDD_41 , /**< E-UTRAN operating band 41 */	 
 CI_DEV_EUTRAN_BAND_TDD_42 , /**< E-UTRAN operating band 42 */	 
 CI_DEV_EUTRAN_BAND_TDD_43 , /**< E-UTRAN operating band 43 */	 
 CI_DEV_EUTRAN_BAND_TDD_44 , /**< E-UTRAN operating band 44 */	 
	 
 // More bands supported...	 
 CI_DEV_EUTRAN_BAND_FDD_65 = 65 ,	 
 CI_DEV_EUTRAN_BAND_FDD_66 ,	 
 CI_DEV_EUTRAN_BAND_FDD_96 ,	 
	 
 CI_DEV_EUTRAN_BAND_NEXTVAL	 
 } _CiDevEutranBand;

typedef UINT8 CiDevEutranBand ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLteCoexReportOptionReq_struct {	 
 CiBoolean enableLteCoexReport ; /**< Enable / disable LTE coexist info report */	 
 } CiDevPrimSetLteCoexReportOptionReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLteCoexReportOptionCnf_struct {	 
 CiDevRc result ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetLteCoexReportOptionCnf;

typedef CiEmptyPrim CiDevPrimGetLteCoexInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetLteCoexInfoCnf_struct {	 
 CiDevRc result ; /**< Result code. \sa CiDevRc. */	 
 CiBoolean isLteOn ; /**< TRUE: current operating on LTE ; FALSE otherwise */	 
 CiDevLteRrcState rrcState ; /**< Current ERRC state: IDLE or CONNECTED */	 
 CiDevEutranBand lteBand ; /**< LTE current operation band */	 
 UINT32 earfcn ; /**< Earfcn */	 
 CiBoolean tddSubframeConfigPresent ;	 
 UINT8 tddUlDlConfig ; /**< TD-LTE UL / DL configuration index: 0 -6 */	 
 UINT8 tddSpecialSubframeConfig ; /**< TD-LTE special subframe configuration index: 0 -9 */	 
 CiBoolean longDRXCyclePresent ;	 
 UINT16 longDRXCycle ; /**< long DRX cycle in ms */	 
 CiBoolean shortDRXCyclePresent ;	 
 UINT16 shortDRXCycle ; /**< short DRX cycle in ms */	 
 } CiDevPrimGetLteCoexInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteCoexInfoInd_struct {	 
 CiBoolean isLteOn ; /**< TRUE: current operating on LTE ; FALSE otherwise */	 
 CiDevLteRrcState rrcState ; /**< Current ERRC state: IDLE or CONNECTED */	 
 CiDevEutranBand lteBand ; /**< LTE current operation band */	 
 UINT32 earfcn ; /**< Earfcn */	 
 CiBoolean tddSubframeConfigPresent ;	 
 UINT8 tddUlDlConfig ; /**< TD-LTE UL / DL configuration index: 0 -6 */	 
 UINT8 tddSpecialSubframeConfig ; /**< TD-LTE special subframe configuration index: 0 -9 */	 
 CiBoolean longDRXCyclePresent ;	 
 UINT16 longDRXCycle ; /**< long DRX cycle in ms */	 
 CiBoolean shortDRXCyclePresent ;	 
 UINT16 shortDRXCycle ; /**< short DRX cycle in ms */	 
 } CiDevPrimLteCoexInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetL2RandFillEnabledReq_struct {	 
 CiBoolean isL2RandomFillBitsEnabled ; /**< TRUE: Enabled ; FALSE: Disabled*/	 
 } CiDevPrimSetL2RandFillEnabledReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetL2RandFillEnabledCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetL2RandFillEnabledCnf;

typedef CiEmptyPrim CiDevPrimGetL2RandFillEnabledReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetL2RandFillEnabledCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiBoolean isL2RandomFillBitsEnabled ; /**< TRUE: Enabled ; FALSE: Disabled*/	 
 } CiDevPrimGetL2RandFillEnabledCnf;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_DEV_PRIM_T323_IND " > */ 
 typedef struct CiDevPrimT323Ind_struct {	 
 CiBoolean t323Valid ;	 
 UINT16 t_323 ;	 
 } CiDevPrimT323Ind;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetMccMncCcReq_struct {	 
 UINT16 countryCode ;	 
 UINT16 operCode ;	 
 UINT8 customerCode [ 3 ] ;	 
 } CiDevPrimSetMccMncCcReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetMccMncCcCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetMccMncCcCnf;

typedef CiEmptyPrim CiDevPrimGetMccMncCcReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetMccMncCcCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT16 countryCode ;	 
 UINT16 operCode ;	 
 UINT8 customerCode [ 3 ] ;	 
 } CiDevPrimGetMccMncCcCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetL1DebugReq_struct {	 
 UINT16 length ;	 
 UINT8 data [ 10 ] ; /**< L1 Debug data sent to L1 */	 
 } CiDevPrimSetL1DebugReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetL1DebugCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetL1DebugCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimL1DebugInfoInd_struct {	 
 UINT16 length ;	 
 UINT8 data [ 256 ] ; /**< L1 Debug info received from L1 */	 
 } CiDevPrimL1DebugInfoInd;

//ICAT EXPORTED ENUM 
 typedef enum CiDEVIMLLOGTYPE_TAG 
 {	 
 CI_DEV_IMLLOG_OFF = 0 ,	 
 CI_DEV_IMLLOG_2SD ,	 
 CI_DEV_IMLLOG_2DDR ,	 
 CI_DEV_IMLLOG_2HSL_BIGBOARD ,	 
 CI_DEV_IMLLOG_2HSL_SMALLBOARD ,	 
 CI_DEV_IMLLOG_2SU_ENABLE ,	 
 CI_DEV_IMLLOG_2SU_DISABLE ,	 
 /*Lilei , CQ00131002 , 20210616 , begin*/	 
 CI_DEV_IPCLOG_DISABLE , /**< DSP IPC log close */	 
 CI_DEV_IPCLOG_ENABLE , /**< DSP IPC log open */	 
 /*Lilei , CQ00131002 , 20210616 , end*/	 
 /*Lilei , CQ00140747 , 20221215 , begin*/	 
 CI_DEV_DIAGLOG_LEVEL , /**< Diag log level */	 
 /*Lilei , CQ00140747 , 20221215 , end*/	 
	 
 CI_DEV_NUM_IMLLOG_CFG	 
 } _CiDevImlLogType;

typedef UINT8 CiDevImlLogType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetImlConfigReq_struct {	 
 CiDevImlLogType imlLogType ; /**< IML log type. */	 
 UINT8 cfgDataLen ; /**< Config data length */	 
 UINT8 cfgData [ 64 ] ; /**< Config data */	 
 } CiDevPrimSetImlConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetImlConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetImlConfigCnf;

typedef CiEmptyPrim CiDevPrimGetImlConfigReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetImlConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiDevImlLogType imlLogType ; /**< IML log type. */	 
 UINT8 cfgDataLen ; /**< Only valid for IML2SU log type ; For other types , it shall be zero */	 
 UINT8 cfgData [ 64 ] ; /**< Config data for IML2SU log type. */	 
 } CiDevPrimGetImlConfigCnf;

//ICAT EXPORTED ENUM 
 enum CiDevPrimMrdOperCmd_enum 
 {	 
 CI_DEV_MRD_CDF_CMD = 0 , /* AT*MRD_CDF no use any more , process by ap*/	 
 CI_DEV_MRD_IMEI_CMD , /* AT*MRD_IMEI*/	 
 CI_DEV_MRD_MEP_CMD , /* AT*MRD_MEP no use any more , process by ap*/	 
 CI_DEV_MRD_MIPS_CMD , /* AT*CP_MIPS no use any more , process by ap*/	 
	 
 CI_DEV_MRD_VSIM_CMD , /* AT*AVSIM */	 
 CI_DEV_MRD_ADC_CMD , /* AT*MRD_ADC */	 
 CI_DEV_MRD_RTPADC_CMD , /* AT*MRD_RTPADC */	 
	 
 CI_DEV_MRD_CMD_NUM	 
 };

typedef UINT8 CiDevMrdType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimCpMrdOperReq_struct 
 {	 
 CiDevMrdType mrdType ; /**< MRD type. \sa CiDevPrimMrdOperCmd_enum. */	 
 UINT8 opType ; /* 0 - set VSIM ; 1 - get VSIM ; 3 - set IMEI */	 
 UINT8 paraNums ; /* Always set to 1 */	 
 UINT8 parameters [ 14 ] [ 64 ] ;	 
 } CiDevPrimCpMrdOperReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimCpMrdOperCnf_struct 
 {	 
 CiDevRc rc ;	 
 CiDevMrdType mrdType ;	 
 UINT8 resultCode ;	 
 UINT16 errCode ;	 
 UINT8 parameters [ ( 1024 -64 ) ] ;	 
 } CiDevPrimCpMrdOperCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimRbTestModeInd_struct 
 {	 
 CiBoolean rbModeStatus ; /**< 0 : RB test mode stop ; 1 : RB test mode start*/	 
 } CiDevPrimRbTestModeInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLteBandOrderReq_struct {	 
 UINT8 numOfLteBands ; /**< Number of the ordered LTE bands */	 
 CiDevEutranBand lteBands [ 20 ] ; /**< LTE bands in order */	 
 } CiDevPrimSetLteBandOrderReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetLteBandOrderCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetLteBandOrderCnf;

typedef CiEmptyPrim CiDevPrimGetLteBandOrderReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetLteBandOrderCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT8 numOfLteBands ; /**< Number of the ordered LTE bands */	 
 CiDevEutranBand lteBands [ 20 ] ; /**< LTE bands in order */	 
 } CiDevPrimGetLteBandOrderCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevSalesCode_struct {	 
 UINT8 len ;	 
 UINT8 data [ 8 ] ;	 
 } CiDevSalesCode;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSalesCodeReq_struct {	 
 UINT8 codeNum ;	 
 CiDevSalesCode code [ 10 ] ; /**< Sales code info */	 
 } CiDevPrimSetSalesCodeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSalesCodeCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetSalesCodeCnf;

typedef CiEmptyPrim CiDevPrimGetSalesCodeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSalesCodeCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT8 codeNum ;	 
 CiDevSalesCode code [ 10 ] ; /**< Sales code info */	 
 } CiDevPrimGetSalesCodeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevFeature_struct {	 
 // UINT8 featureId ;	 
 UINT32 featureId ;	 
 UINT32 featureValue ;	 
 } CiDevFeature;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetOperConfigReq_struct {	 
 UINT8 numFeatures ;	 
 CiDevFeature feature [ 32 ] ; /**< Operators config info */	 
 } CiDevPrimSetOperConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetOperConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetOperConfigCnf;

//ICAT EXPORTED ENUM 
 typedef enum CiDevGetOperCfgType_enum 
 {	 
 CI_DEV_GET_ALL_OPER_CFG = 0 ,	 
 CI_DEV_GET_SPECIFIC_OPER_CFG ,	 
	 
 CI_DEV_NUM_GET_OPER_CFG_TYPE	 
 } _CiDevGetOperCfgType;

typedef UINT8 CiDevGetOperCfgType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetOperConfigReq_struct {	 
 CiDevGetOperCfgType type ;	 
 UINT32 featureIdOrIndex ; /**< Feature index when type=0 , specific feature ID when type=1 */	 
 } CiDevPrimGetOperConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetOperConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT16 totalNum ; /**< Total num of feature IDs */	 
 UINT16 validNum ; /**< Valid num of feature IDs of this query */	 
 CiDevFeature feature [ 32 ] ; /**< Operators config info */	 
 } CiDevPrimGetOperConfigCnf;

typedef CiEmptyPrim CiDevPrimGetStatusReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetStatusCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiDevStatus status ; /**< Device status \sa CiDevStatus */	 
 } CiDevPrimGetStatusCnf;

typedef CiEmptyPrim CiDevPrimFactoryResetReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimFactoryResetCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimFactoryResetCnf;

typedef CiEmptyPrim CiDevPrimGetImsUlStatisticReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetImsUlStatisticCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT32 ulThroughPut ; /**< UL throughput of IMS video */	 
 UINT16 ulBler ; /**< UL BLER of IMS video */	 
 UINT8 rsrp ; /**< Value range: 0 ~97 , invalid ( 0xFF ) */	 
 UINT8 rsrq ; /**< Value range: 0 ~34 , invalid ( 0xFF ) */	 
 INT16 snr ; /**< Value range: [ -10~40 ] *256 */	 
 UINT32 l2DiscardPacketsLen ; /**< Length of L2 discarded UL IMS video packet */	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 } CiDevPrimGetImsUlStatisticCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetMedataCommReserveReq_struct {	 
 UINT8 positionToSet ; /*position of Medata comm reserved */	 
 UINT8 setConfigValue ; /*value to set */	 
 } CiDevPrimSetMedataCommReserveReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetMedataCommReserveCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 /*added by taow 20181107 CQ00112754 begin */	 
 UINT8 positionToSet ; /*added by taow 20190218 :position of Medata comm reserved */	 
 /*added by taow 20181107 CQ00112754 end*/	 
 } CiDevPrimSetMedataCommReserveCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetMedataCommReserveReq_struct {	 
 UINT8 positionToGet ; /*position of Medata comm reserved */	 
 } CiDevPrimGetMedataCommReserveReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetMedataCommReserveCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT8 ConfigValue ; /*value to set */	 
 /*added by taow 20181107 CQ00112754 begin */	 
 UINT8 positionToGet ; /*added by taow 20190218 :position of Medata comm reserved */	 
 /*added by taow 20181107 CQ00112754 end */	 
 } CiDevPrimGetMedataCommReserveCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetCellSelectCfgReq_struct {	 
 INT8 offset_scell ; /**< serving cell , SrxLev + offset , to check whether do neighbor cell measurement */	 
 INT8 offset_scell_qual ; /**< serving cell , Squal + offset , to check whether do neighbor cell measurement */	 
 INT8 offset_ncell_lte ; /**< neighbor cell , LTE RSRP - offset , for cell reselection evaluation */	 
 INT8 offset_ncell_lte_qual ; /**< neighbor cell , LTE RSRQ - offset , for cell reselection evaluation */	 
 INT8 offset_ncell_umts ; /**< neighbor cell , UMTS RSCP - offset , for cell reselection evaluation */	 
 INT8 offset_ncell_umts_qual ; /**< neighbor cell , UMTS EcN0 - offset , for cell reselection evaluation */	 
 INT8 offset_ncell_gsm ; /**< neighbor cell , GSM RSSI - offset , for cell reselection evaluation */	 
 } CiDevPrimSetCellSelectCfgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetCellSelectCfgCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetCellSelectCfgCnf;

typedef UINT8 CiDevCommonCause ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_EVENT_TYPE_AS_ENUM 
 {	 
 CI_DEV_RRC_EVENT_RACH_FAIL = 0 ,	 
 CI_DEV_RRC_EVENT_DL_LOSS_SYNC ,	 
 CI_DEV_RRC_EVENT_SIB_MISSING ,	 
 CI_DEV_RRC_EVENT_RLC_MAX_RETRANS ,	 
 CI_DEV_RRC_EVENT_RRC_RECONFIG_ABNORMAL ,	 
 CI_DEV_RRC_EVENT_RRC_REDIRECT_ABNORMAL ,	 
 CI_DEV_RRC_EVENT_IRAT_RESELECTION_FAIL ,	 
 CI_DEV_RRC_EVENT_RRC_ESTABLISH_SUCCESS ,	 
 CI_DEV_RRC_EVENT_RRC_RELEASE ,	 
	 
 /*Lilei , CQ00144545 , 20230706 , begin*/	 
 CI_DEV_RRC_EVENT_LTE_RESELECTION_SUCCESS ,	 
 CI_DEV_RRC_EVENT_LTE_HANDOVER_SUCCESS ,	 
 CI_DEV_RRC_EVENT_LTE_REDIRECTION_SUCCESS ,	 
 CI_DEV_RRC_EVENT_LTE_MEAS_REPORT_SENT ,	 
 CI_DEV_RRC_EVENT_LTE_RRC_CONN_SETUP_NOT_RECEIVED ,	 
 /*Lilei , CQ00144545 , 20230706 , end*/	 
 /*Lilei , CQ00146454 , 20231023 , begin*/	 
 CI_DEV_RRC_EVENT_LTE_MAC_SR_MAX ,	 
 CI_DEV_RRC_EVENT_LTE_INTRA_HANDOVER_SUCCESS ,	 
 CI_DEV_RRC_EVENT_LTE_INTRA_HANDOVER_FAIL ,	 
 CI_DEV_RRC_EVENT_LTE_INTER_HANDOVER_SUCCESS ,	 
 CI_DEV_RRC_EVENT_LTE_INTER_HANDOVER_FAIL ,	 
 CI_DEV_RRC_EVENT_LTE_INTER_BAND_HANDOVER_SUCCESS ,	 
 CI_DEV_RRC_EVENT_LTE_INTER_BAND_HANDOVER_FAIL ,	 
 CI_DEV_RRC_EVENT_LTE_RESELECTION_FAIL ,	 
 /*Lilei , CQ00146454 , 20231023 , end*/	 
	 
 CI_DEV_GRR_EVENT_RACH_FAIL = 0 , // radio link timeout , downlink signal fail , scell not reach threshhold	 
 CI_DEV_GRR_EVENT_RACH_TIMEOUT , // rach timeout: t3126 , t3146 , t3147	 
 CI_DEV_GRR_EVENT_DCH_MDL_ERROR , // dch mdl error:T200_EXPIRED_N200_TIMES , UNSOLICITED_DM_PERF_RELEASE , SEQ_ERROR_PERF_RELEASE	 
 CI_DEV_GRR_EVENT_PRACH_ERROR , // scell not reach threshhold , radio link timeout , downlink signal fialure , mph error	 
 CI_DEV_GRR_EVENT_PDCH_TIMEOUT , // T3166 , T3168 etc.	 
 CI_DEV_GRR_EVENT_L2_MDL_ERROR , // l2 est mdl error ind	 
 CI_DEV_GRR_EVENT_GSM_HANDOVER_FAIL , // irat CS handover fail	 
 CI_DEV_GRR_EVENT_GSM_IRAT_RESELECTION_FAIL , // irat reselection fail	 
 CI_DEV_GRR_EVENT_UL_TBF_ACTIVE , // ul tbf active	 
 CI_DEV_GRR_EVENT_DL_TBF_ACTIVE , // dl tbf active	 
 CI_DEV_GRR_EVENT_UL_TBF_INACTIVE , // ul tbf release	 
 CI_DEV_GRR_EVENT_DL_TBF_INACTIVE // dl tbf release	 
 } _CiDevEventTypeAs;

typedef UINT8 CiDevEventTypeAs ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_EVENT_TYPE_MM_ENUM 
 {	 
 CI_DEV_GMM_EVENT_NEW_ATTACH_REQ = 0 , /*GPRS ATTACH START*/	 
 CI_DEV_GMM_EVENT_ATTACH_SUCCESS , /*GPRS ATTACH SUCESS*/	 
 CI_DEV_GMM_EVENT_ATTACH_REJECT , /*GPRS ATTACH REJECT*/	 
 CI_DEV_GMM_EVENT_RAU_REJECT , /*GPRS RAU REJECT*/	 
 CI_DEV_GMM_EVENT_SERVICE_REJECT , /*GPRS SERVICE REJECT*/	 
 CI_DEV_GMM_EVENT_AUTHENTICATION_REJECT , /*GPRS AUTHENTICATION REJECT*/	 
 CI_DEV_GMM_EVENT_DETACH_REQ , /*GPRS DETACH REQUEST*/	 
	 
 CI_DEV_MM_EVENT_LU_REJECT , /*LU REJECT*/	 
 CI_DEV_MM_EVENT_AUTHENTICATION_REJECT , /*CS AUTHENTICATION REJECT*/	 
	 
 CI_DEV_EMM_EVENT_NEW_ATTACH_REQ =0 , /*EPS ATTACH START*/	 
 CI_DEV_EMM_EVENT_ATTACH_SUCCESS , /*EPS ATTACH SUCCESS*/	 
 CI_DEV_EMM_EVENT_ATTACH_REJECT , /*EPS ATTACH REJECT*/	 
 CI_DEV_EMM_EVENT_TAU_REJECT , /*EPS TAU REJECT*/	 
 CI_DEV_EMM_EVENT_SERVICE_REJECT , /*EPS SERVICE REJECT*/	 
 CI_DEV_EMM_EVENT_AUTHENTICATION_REJECT , /*EPS AUTHENTICATION REJECT*/	 
 CI_DEV_EMM_EVENT_DETACH_REQ , /*EPS DETACH REQUEST for MT*/	 
 CI_DEV_MM_TAU_ACCEPT , /*EPS TAU ACCEPT*/	 
 CI_DEV_EMM_EXTENDED_ACCESS_BARRED ,	 
 /*Lilei , CQ00144545 , 20230706 , begin*/	 
 CI_DEV_EMM_ATTACH_TIMEOUT , /*EPS ATTACH timeout for all retries*/	 
 CI_DEV_EMM_TAU_TIMEOUT , /*EPS TAU timeout for all retries*/	 
 CI_DEV_EMM_SERVICE_REQ_TIMEOUT /*EPS SERVICE_REQ timeout for all retries*/	 
 /*Lilei , CQ00144545 , 20230706 , end*/	 
	 
 } _CiDevEventTypeMm;

typedef UINT8 CiDevEventTypeMm ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_EVENT_TYPE_SM_ENUM 
 {	 
 CI_DEV_SM_EVENT_PDP_ACT_REJ = 0 , /* PDP activation reject */	 
 CI_DEV_SM_EVENT_PDP_MODIFY_REJ , /* PDP modification reject */	 
 CI_DEV_SM_EVENT_PDP_DEACT_REJ , /* PDP deactivation reject */	 
 /*Lilei , CQ00144545 , 20230706 , begin*/	 
 CI_DEV_SM_EVENT_PDP_ACT_IGNORED /* PDP activation ignored */	 
 /*Lilei , CQ00144545 , 20230706 , end*/	 
 } _CiDevEventTypeSm;

typedef UINT8 CiDevEventTypeSm ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonGsmCellInfo_struct 
 {	 
 UINT16 cellId ;	 
 UINT16 arfcn ;	 
 UINT8 bsic ;	 
 } CiDevCommonGsmCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonUmtsCellInfo_struct 
 {	 
 UINT32 cellId ;	 
 UINT16 uArfcn ;	 
 UINT16 psc ;	 
 } CiDevCommonUmtsCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonLteCellInfo_struct 
 {	 
 UINT32 cellId ;	 
 UINT32 euArfcn ;	 
 UINT16 phyCellId ;	 
 } CiDevCommonLteCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonReportAS_struct 
 {	 
 CiDevEventTypeAs event ;	 
 CiDevEngModeNetwork networkMode ;	 
 /*Lilei , CQ00144545 , 20230706 , begin*/	 
 CiDevCommonLteCellInfo currentLteCell ;	 
 CiDevCommonLteCellInfo sourceLteCell ; /* Only valid for HO / Reselection / Redirect etc. */	 
 UINT8 rsrpOfsourceCell ;	 
 UINT8 rsrqOfsourceCell ;	 
 UINT8 rsrpOfcurrentCell ;	 
 UINT8 rsrqOfcurrentCell ;	 
 /*Lilei , CQ00144545 , 20230706 , end*/	 
 } CiDevCommonReportAS;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonReportMm_struct 
 {	 
 CiDevCommonCause cause ; /* For attach initiation or success , there ' s no cause ( value 0 ) */	 
 CiDevEventTypeMm event ;	 
 /*Lilei , CQ00127026 , 20201222 , begin*/	 
 CiDevEngModeNetwork network ; /* 0 :GSM , 1 :UMTS */	 
 CiDevCommonGsmCellInfo gsmCellInfo ;	 
 CiDevCommonUmtsCellInfo umtsCellInfo ;	 
 /*Lilei , CQ00127026 , 20201222 , end*/	 
 CiDevCommonCause remapCause ; /*CQ00140020 , lilei , 20221205 */	 
 } CiDevCommonReportMm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonReportGmm_struct 
 {	 
 CiDevCommonCause cause ;	 
 CiDevEventTypeMm event ;	 
 /*Lilei , CQ00127026 , 20201222 , begin*/	 
 CiDevEngModeNetwork network ; /* 0 :GSM , 1 :UMTS */	 
 CiDevCommonGsmCellInfo gsmCellInfo ;	 
 CiDevCommonUmtsCellInfo umtsCellInfo ;	 
 /*Lilei , CQ00127026 , 20201222 , end*/	 
 CiDevCommonCause remapCause ; /*CQ00140020 , lilei , 20221205 */	 
 } CiDevCommonReportGmm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonReportSm_struct 
 {	 
 CiDevCommonCause cause ;	 
 CiDevEventTypeSm event ;	 
 } CiDevCommonReportSm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonReportEmm_struct 
 {	 
 CiDevCommonCause cause ;	 
 CiDevEventTypeMm event ;	 
 /*Lilei , CQ00127026 , 20201222 , begin*/	 
 CiDevCommonLteCellInfo lteCellInfo ;	 
 /*Lilei , CQ00127026 , 20201222 , end*/	 
 CiDevCommonCause remapCause ; /*CQ00140020 , lilei , 20221205 */	 
 } CiDevCommonReportEmm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevCommonReportEsm_struct 
 {	 
 CiDevCommonCause cause ;	 
 CiDevEventTypeSm event ;	 
 /*Lilei , CQ00144545 , 20230706 , begin*/	 
 CiDevCommonLteCellInfo lteCellInfo ;	 
 /*Lilei , CQ00144545 , 20230706 , end*/	 
 } CiDevCommonReportEsm;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_COMMON_REPORT_ENUM 
 {	 
 CI_DEV_COMMON_REPORT_AS ,	 
 CI_DEV_COMMON_REPORT_MM ,	 
 CI_DEV_COMMON_REPORT_GMM ,	 
 CI_DEV_COMMON_REPORT_SM ,	 
 CI_DEV_COMMON_REPORT_EMM ,	 
 CI_DEV_COMMON_REPORT_ESM ,	 
	 
 CI_DEV_NUM_COMMON_REPORT_TYPES	 
 } _CiDevCommonReportType;

typedef UINT8 CiDevCommonReportType ;
//ICAT EXPORTED UNION 
 typedef union CiDevCommonReport_union 
 {	 
 CiDevCommonReportAS as ; /* AS layer reject info */	 
 CiDevCommonReportMm mm ; /* MM reject info */	 
 CiDevCommonReportGmm gmm ; /* GMM reject info */	 
 CiDevCommonReportSm sm ; /* SM reject info */	 
 CiDevCommonReportEmm emm ; /* EMM reject info */	 
 CiDevCommonReportEsm esm ; /* ESM reject info */	 
 } CiDevCommonReport;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimCommonReportInd_struct 
 {	 
 CiDevCommonReportType type ;	 
 CiDevCommonReport info ;	 
 } CiDevPrimCommonReportInd;

//ICAT EXPORTED ENUM 
 typedef enum CiDevCmdType_TAG {	 
 /*For #3748 roaming forbiden plmn */	 
 CI_DEV_CMD_SET = 0 , /**< set */	 
 CI_DEV_CMD_DELETE = 1 , /**< Delete one or limit per time*/	 
	 
 /*For #46621 forbiden plmn */	 
 CI_DEV_CMD_DELETE_SIM = 2 , /**< Delete SIM card FPLMN*/	 
 CI_DEV_CMD_DELETE_NVM = 3 , /**< Delete NVM FPLMN*/	 
 CI_DEV_CMD_DELETE_ALL = 4 , /**< Delete SIM card and NVM FPLMN*/	 
	 
 CI_DEV_CMD_NUM ,	 
 } _CiDevCmdType;

typedef UINT8 CiDevCmdType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetRoamingForbidenPlmnReq_struct {	 
 CiDevCmdType cmdType ;	 
 UINT8 numOfPlmnIdentity ;	 
 CiDevLtePlmnIdentity plmnIdentityList [ 10 ] ;	 
 } CiDevPrimSetRoamingForbidenPlmnReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetRoamingForbidenPlmnCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetRoamingForbidenPlmnCnf;

typedef CiEmptyPrim CiDevPrimGetRoamingForbidenPlmnReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetRoamingForbidenPlmnCnf_struct {	 
 CiDevRc rc ;	 
 UINT8 numOfPlmnIdentity ;	 
 CiDevLtePlmnIdentity plmnIdentityList [ 10 ] ;	 
 } CiDevPrimGetRoamingForbidenPlmnCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevBlackCellId_struct 
 {	 
 UINT32 afrcn ; /**< LTE : EARFCN ; URTAN: UARFCN ; GSM: ARFCN */	 
 UINT16 cellId ; /**< LTE : PCI ; URTAN: PSC ; GSM: BSCI */	 
 } CiDevBlackCellId;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevBlackCellList_struct {	 
 UINT8 numOfBlackCell ;	 
 CiDevBlackCellId blackCellIdList [ 10 ] ;	 
 } CiDevLteBlackCellList , CiDevUmtsBlackCellList , CiDevGsmBlackCellList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetBlackCellReq_struct {	 
 CiDevCmdType cmdType ;	 
 CiDevLteBlackCellList LteBlackCellList ;	 
 CiDevUmtsBlackCellList UmtsBlackCellList ;	 
 CiDevGsmBlackCellList GsmBlackCellList ;	 
 } CiDevPrimSetBlackCellReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetBlackCellCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetBlackCellCnf;

typedef CiEmptyPrim CiDevPrimGetBlackCellReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetBlackCellCnf_struct {	 
 CiDevRc rc ;	 
 CiDevLteBlackCellList LteBlackCellList ;	 
 CiDevUmtsBlackCellList UmtsBlackCellList ;	 
 CiDevGsmBlackCellList GsmBlackCellList ;	 
 } CiDevPrimGetBlackCellCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetFeatureConfigReq_struct {	 
 CiDevFeature feature ; /**< Features config info */	 
 } CiDevPrimSetFeatureConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetFeatureConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiDevFeature feature ; /**< Features config info */	 
 } CiDevPrimSetFeatureConfigCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetFeatureConfigReq_struct {	 
 UINT32 featureId ; /**< Feature index. 0xFF indicates all feauters */	 
 } CiDevPrimGetFeatureConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetFeatureConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT16 numFeatures ; /**< Num of feature IDs */	 
 CiDevFeature feature [ 80 ] ; /**< Features config info */	 
 } CiDevPrimGetFeatureConfigCnf;

//ICAT EXPORTED ENUM 
 typedef enum CiDevPdpType_enum 
 {	 
 PDP_TYPE_IPV4 = 0x1 ,	 
 PDP_TYPE_IPV6 = 0x2 ,	 
 PDP_TYPE_IPV4V6 = 0x3 ,	 
 PDP_TYPE_UNUSED = 0x4	 
 } _CiDevPdpType;

typedef UINT8 CiDevPdpType ;
//ICAT EXPORTED ENUM 
 typedef enum CiDevSetRoamAction_enum 
 {	 
 CI_DEV_ROAM_ADD_UPDATE = 0 ,	 
 CI_DEV_ROAM_DELETE = 1 ,	 
	 
 CI_DEV_NUM_ROAM_ACTIONS	 
 } _CiDevSetRoamAction;

typedef UINT8 CiDevSetRoamAction ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevRoamConfig_struct {	 
 CiDevLtePlmnIdentity plmn ;	 
 CiDevPdpType attachPdpType ;	 
 } CiDevRoamConfig;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetRoamConfigReq_struct {	 
 CiDevSetRoamAction action ;	 
 CiDevRoamConfig config ;	 
 } CiDevPrimSetRoamConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetRoamConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetRoamConfigCnf;

typedef CiEmptyPrim CiDevPrimGetRoamConfigReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetRoamConfigCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT16 num ; /**< Num of configs */	 
 CiDevRoamConfig config [ 10 ] ; /**< Attach PDP type info */	 
 } CiDevPrimGetRoamConfigCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_CELL_DECODE_RC_ENUM 
 {	 
 CI_DEV_CELL_DECODE_NONE = 0 ,	 
 CI_DEV_CELL_DECODE_SUCCESS = 1 ,	 
 CI_DEV_CELL_DECODE_FAIL = 2 ,	 
	 
 CI_DEV_NUM_CELL_DECODE_RC	 
 } _CiDevCellDecodeRc;

typedef UINT8 CiDevCellDecodeRc ;
//ICAT EXPORTED ENUM 
 typedef enum CIDEV_CELL_TYPE_ENUM 
 {	 
 CI_DEV_CELL_TYPE_SEARCH = 0 , /**< Cell result from search */	 
 CI_DEV_CELL_TYPE_SVC = 1 , /**< Serving cell */	 
 CI_DEV_CELL_TYPE_NEIGHBOR = 2 , /**< Neighbor cell. Only for GSM */	 
 CI_DEV_CELL_TYPE_INTRA_FREQ = 3 ,	 
 CI_DEV_CELL_TYPE_INTER_FREQ = 4 ,	 
 CI_DEV_CELL_TYPE_INTERRAT_GSM = 5 ,	 
 CI_DEV_CELL_TYPE_INTERRAT_UMTS = 6 ,	 
 CI_DEV_CELL_TYPE_INTERRAT_LTE = 7 ,	 
	 
 CI_DEV_NUM_CELL_TYPE	 
 } _CiDevCellType;

typedef UINT8 CiDevCellType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmCellInfoItem_struct 
 {	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT8 bsic ; /**< Base transceiver station identity code ; range 0 h-3Fh ( 6 bits ) ; 0xFF means not present */	 
 INT16 rssi ; /**< GSM carrier RSSI. rssi = rxLevel-110 ; 0x7FFF means not present */	 
 INT16 sinr ; /**< SINR ; 0x7FFF means not present */	 
 CiDevCellDecodeRc decodeRc ; /**< Cell decode return code */	 
 CiDevCellType cellType ; /**< Which type of cell */	 
 } CiDevGsmCellInfoItem;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsCellInfoItem_struct 
 {	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT16 psc ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 INT16 rssi ; /**< UTRA carrier RSSI ; 0x7FFF means not present */	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power ; 0x7FFF means not present */	 
 INT16 ecN0 ; /**< CPICH Ec / N0 , only valid for FDD ; 0x7FFF means not present */	 
 INT16 sinr ; /**< SINR ; 0x7FFF means not present */	 
 CiDevCellDecodeRc decodeRc ; /**< Cell decode return code*/	 
 CiDevCellType cellType ; /**< Which type of cell */	 
 } CiDevUmtsCellInfoItem;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteCellInfoItem_struct 
 {	 
 UINT32 earfcn ; /**< Eutra absolute radio frequency channel number */	 
 UINT16 physCellId ; /**< Physical cell identity */	 
 INT16 rssi ; /**< EUTRA carrier RSSI ; 0x7FFF means not present */	 
 INT16 rsrp ; /**< Reference signal receive power ; 0x7FFF means not present */	 
 INT16 rsrq ; /**< Reference signal receive quality ; 0x7FFF means not present */	 
 INT16 sinr ; /**< SINR ; 0x7FFF means not present */	 
 CiDevCellDecodeRc decodeRc ; /**< Cell decode return code*/	 
 CiDevCellType cellType ; /**< Which type of cell */	 
 } CiDevLteCellInfoItem;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimCellsInfoInd_struct 
 {	 
 CiDevEngModeNetwork network ; /**< Current network type ( GSM / UMTS / LTE ) */	 
 UINT8 numGsmCells ; /**< Number of GSM cells */	 
 CiDevGsmCellInfoItem gsmCellInfo [ 33 ] ; /**< GSM cells info */	 
 UINT8 numUmtsCells ; /**< Number of UMTS cells */	 
 CiDevUmtsCellInfoItem umtsCellInfo [ 33 ] ; /**< UMTS cells info */	 
 UINT8 numLteCells ; /**< Number of LTE cells */	 
 CiDevLteCellInfoItem lteCellInfo [ 33 ] ; /**< LTE cells info */	 
 /*Lilei , CQ00135655 , 20220224 , begin*/	 
 /* Parameters only valid for GSM , begin */	 
 UINT8 radioLinkTimeout ; /**< RADIO_LINK_TIMEOUT */	 
 UINT8 counterS ; /**< Radio link counter S. Invalid if radioLinkTimeout=0 */	 
 UINT8 dscInitValue ; /**< Initial value of downlink signaling failure counter */	 
 UINT8 dsfCount ; /**< Downlink signaling failure counter. Invalid if dscInitValue=0 */	 
 CiDevEngModeState mode ; /**< Current mode ( idle / dedicated ) \sa CiDevEngModeState */	 
 CiBoolean isInVoiceCall ; /**< Whether in a voice call */	 
 /* Parameters only valid for GSM , end */	 
 /*Lilei , CQ00135655 , 20220224 , end*/	 
 } CiDevPrimCellsInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetDrxDynamicAdujustReq_struct {	 
 CiBoolean dynamicFlag ; /**< TRUE: enable dynamic adjust , FALSE: disable */	 
 INT16 rsrpTh ; /**< Threshold of RSRP , range [ -144 , -44 ] , default -105 */	 
 INT16 snrTh ; /**< Threshold of SNR , range [ -20 , 30 ] , default 5 */	 
 } CiDevPrimSetDrxDynamicAdujustReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetDrxDynamicAdujustCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetDrxDynamicAdujustCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimConfigHwPsmProfileReq_struct {	 
 CiBoolean hwPsmEnable ; /**< if enable for hardware PSM feature. */	 
	 
 UINT32 psmWindowThreshold ; /**< threshold for PSM windown to check T3412 or eDRX length */	 
 UINT8 eDrxToT3324Threshold ; /**< threshold for eDRX when both PSM / eDRX enabled */	 
 } CiDevPrimConfigHwPsmProfileReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimConfigHwPsmProfileCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimConfigHwPsmProfileCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetAntennaTunerParamReq_struct {	 
 UINT8 paramId ; /**< ID of the set of antenna tuner parameters */	 
 } CiDevPrimSetAntennaTunerParamReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetAntennaTunerParamCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetAntennaTunerParamCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimPagingFailureInd_struct 
 {	 
 UINT8 reserve ;	 
 } CiDevPrimPagingFailureInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevForbidenPlmnListDataSim_struct {	 
	 
 CiDevLtePlmnIdentity fPlmnList [ 8 ] ; /**<the array is used in GET response*/	 
 UINT8 numFPlmn ; /**< set:MAX num is 1 ;	 
 * del: 0 del all , 1 del the PLMN in forbidenPlmnList [ 0 ]	 
 * get: max num is 8 CI_DEV_NUM_FORBIDDEN_PLMN_SIM*/	 
 UINT8 reserved1 [ 3 ] ;	 
 } CiDevForbidenPlmnListDataSim;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevForbidenPlmnListDataNvm_struct {	 
 CiDevLtePlmnIdentity hPlmnList [ 10 ] ;	 
 CiDevLtePlmnIdentity fPlmnList [ 10 ] ;	 
 UINT8 NumHPlmn ;	 
 UINT8 numFPlmn ;	 
 UINT8 currentIndex ; /**<currentIndex is used in GET response*/	 
 UINT8 totalNum ; /**<totalNum is used in GET responsenum of imsiPlmn stored in UE */	 
 UINT8 reserved1 [ 3 ] ;	 
 } CiDevForbidenPlmnListDataNvm;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEhplmnList_struct 
 {	 
 CiDevLtePlmnIdentity imsiPlmn ;	 
 CiDevLtePlmnIdentity eHplmnList [ 10 ] ;	 
 UINT8 numEhplmn ;	 
 UINT8 currentIndex ; /**<currentIndex is used in GET response*/	 
 UINT8 totalNum ; /**<totalNum is used in GET responsenum of imsiPlmn stored in UE */	 
 UINT8 reserved1 [ 3 ] ;	 
	 
	 
 } CiDevEhplmnListData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevBarredPlmnData_Tag 
 {	 
 UINT8 plmnNum ;	 
 UINT8 reserved1 [ 3 ] ;	 
 CiDevLtePlmnIdentity BarredPlmnList [ 16 ] ; /** all PLMN will be barred in the list , including HPLMN */	 
 } CiDevBarredPlmnData;

//ICAT EXPORTED ENUM 
 typedef enum CiDevRemapProcedureTag 
 {	 
 CI_DEV_REMAP_GMM_ATTCH_RAU_REJ = 0 ,	 
 CI_DEV_REMAP_GMM_SERVICE_REJ ,	 
 CI_DEV_REMAP_GMM_DETACH ,	 
 CI_DEV_REMAP_MM_LU_REJ ,	 
 CI_DEV_REMAP_CM_SERVICE_REJ ,	 
 CI_DEV_REMAP_MM_ABORT ,	 
 CI_DEV_REMAP_EMM_ATTACH_TAU_REJ ,	 
 CI_DEV_REMAP_EMM_SERVICE_REJ ,	 
 CI_DEV_REMAP_EMM_DETACH ,	 
 CI_DEV_REMAP_MAX_PROC	 
	 
 } _CiDevRemapProcedure;

typedef UINT32 CiDevRemapProcedure ;
//ICAT EXPORTED ENUM 
 typedef enum CiDevRemapCauseTag 
 {	 
 CI_DEV_REMAP_CAUSE_0 = 0 ,	 
 CI_DEV_REMAP_CAUSE_1 ,	 
 CI_DEV_REMAP_CAUSE_2 ,	 
 CI_DEV_REMAP_CAUSE_3 ,	 
 CI_DEV_REMAP_CAUSE_4 ,	 
 CI_DEV_REMAP_CAUSE_5 ,	 
 CI_DEV_REMAP_CAUSE_6 ,	 
 CI_DEV_REMAP_CAUSE_7 ,	 
 CI_DEV_REMAP_CAUSE_8 ,	 
 CI_DEV_REMAP_CAUSE_9 ,	 
 CI_DEV_REMAP_CAUSE_10 ,	 
 CI_DEV_REMAP_CAUSE_11 ,	 
 CI_DEV_REMAP_CAUSE_12 ,	 
 CI_DEV_REMAP_CAUSE_13 ,	 
 CI_DEV_REMAP_CAUSE_14 ,	 
 CI_DEV_REMAP_CAUSE_15 ,	 
 CI_DEV_REMAP_CAUSE_16 ,	 
 CI_DEV_REMAP_CAUSE_17 ,	 
 CI_DEV_REMAP_CAUSE_18 ,	 
 CI_DEV_REMAP_CAUSE_19 ,	 
 CI_DEV_REMAP_CAUSE_20 ,	 
 CI_DEV_REMAP_CAUSE_21 ,	 
 CI_DEV_REMAP_CAUSE_22 ,	 
 CI_DEV_REMAP_CAUSE_23 ,	 
 CI_DEV_REMAP_CAUSE_24 ,	 
 CI_DEV_REMAP_CAUSE_25 ,	 
 CI_DEV_REMAP_CAUSE_26 ,	 
 CI_DEV_REMAP_CAUSE_27 ,	 
 CI_DEV_REMAP_CAUSE_28 ,	 
 CI_DEV_REMAP_CAUSE_29 ,	 
 CI_DEV_REMAP_CAUSE_30 ,	 
 CI_DEV_REMAP_CAUSE_31 ,	 
 CI_DEV_REMAP_CAUSE_32 ,	 
 CI_DEV_REMAP_CAUSE_33 ,	 
 CI_DEV_REMAP_CAUSE_34 ,	 
 CI_DEV_REMAP_CAUSE_35 ,	 
 CI_DEV_REMAP_CAUSE_36 ,	 
 CI_DEV_REMAP_CAUSE_37 ,	 
 CI_DEV_REMAP_CAUSE_38 ,	 
 CI_DEV_REMAP_CAUSE_39 ,	 
 CI_DEV_REMAP_CAUSE_40 ,	 
 CI_DEV_REMAP_CAUSE_41 ,	 
 CI_DEV_REMAP_CAUSE_42 ,	 
 CI_DEV_REMAP_CAUSE_95 = 95 ,	 
 CI_DEV_REMAP_CAUSE_96 ,	 
 CI_DEV_REMAP_CAUSE_97 ,	 
 CI_DEV_REMAP_CAUSE_98 ,	 
 CI_DEV_REMAP_CAUSE_99 ,	 
 CI_DEV_REMAP_CAUSE_100 ,	 
 CI_DEV_REMAP_CAUSE_101 ,	 
 CI_DEV_REMAP_CAUSE_111 = 111 ,	 
 CI_DEV_REMAP_CAUSE_NO_CAUSE= 0xFE ,	 
 CI_DEV_REMAP_MAX_CAUSE = 255	 
 } _CiDevRemapCause;

typedef UINT8 CiDevRemapCause ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevRemapCauseEntryTag 
 {	 
 CiDevRemapCause originalCause ;	 
 CiDevRemapCause remapHPLMNcause ;	 
 CiDevRemapCause remapVPLMNcause ;	 
	 
 UINT8 reserved [ 5 ] ;	 
 } CiDevRemapCauseEntry;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevRemapCauseProEntryTag 
 {	 
 CiDevRemapProcedure procedureId ;	 
 CiDevRemapCauseEntry remapCauseEntry [ 10 ] ;	 
 UINT8 numCauseRemap ;	 
 UINT8 reserved [ 3 ] ;	 
 } CiDevRemapCauseProEntry;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevRemapCauseData_struct {	 
 CiDevRemapCauseProEntry remapCauseProEntry [ 10 ] ;	 
 UINT8 numCausePro ;	 
 UINT8 reserved [ 3 ] ;	 
 } CiDevRemapCauseData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevRejectCounterTag 
 {	 
 CiDevRemapCause rejectCause ;	 
 INT8 rejectHplmnCounter ;	 
 INT8 rejectVplmnCounter ;	 
 INT8 reserved [ 1 ] ;	 
 } CiDevRejectCounter;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevRejectCounterData_struct {	 
 CiDevRejectCounter remapRejectCounter [ 10 ] ;	 
 INT8 numRejectCounter ;	 
 INT8 reserved [ 3 ] ;	 
 } CiDevRejectCounterData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevMultipleGsmBandTag 
 {	 
 UINT8 gsmMultiple ;	 
 UINT8 dcsMultiple ;	 
 UINT8 pcsMultiple ;	 
 UINT8 reserved ;	 
 } CiDevMultipleGsmBand;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevRplmnInfoTag 
 {	 
 Boolean lastEpsRplmnIsValid ;	 
 Boolean lastRplmnIsValid ;	 
 CiDevEngModeNetwork lastRplmnNwMode ;	 
 CiDevLtePlmnIdentity lastEpsRplmn ;	 
 CiDevLtePlmnIdentity lastRplmn ;	 
 } CiDevRplmnInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPlmnId_struct 
 {	 
 UINT16 mcc ;	 
 // 2 -3 digits of MNC	 
 UINT16 mnc ;	 
 // Length of MNC , value range ( 2 , 3 )	 
 UINT8 lenOfMnc ;	 
 UINT8 dummy ;	 
 } CiDevPlmnId;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevWhiteCellId_struct 
 {	 
 UINT32 xArfcn ; /**< LTE : EARFCN ; URTAN: UARFCN ; GSM: ARFCN */	 
 UINT16 xCellId ; /**< LTE : PCI ; URTAN: PSC ; GSM: BSIC */	 
 UINT16 dummy0 ;	 
 UINT32 dummy1 [ 6 ] ;	 
 } CiDevWhiteCellId;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevWhiteCellList_struct {	 
 CiDevPlmnId plmn ;	 
 UINT8 maxNumOfWhiteCell ;	 
 UINT8 numOfWhiteCell ;	 
 CiDevWhiteCellId whiteCellList [ 10 ] ;	 
 } CiDevLteWhiteCellList , CiDevUmtsWhiteCellList , CiDevGsmWhiteCellList;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevWhiteCellListInfoTag 
 { CiBoolean isEnable ; /**< TRUE : Enable ; FALSE: DISABLE */	 
 UINT8 dummy [ 3 ] ;	 
 CiDevLteWhiteCellList lteWhiteCellList ;	 
 CiDevUmtsWhiteCellList umtsWhiteCellList ;	 
 CiDevGsmWhiteCellList gsmWhiteCellList ;	 
 } CiDevWhiteCellListInfo;

//ICAT EXPORTED ENUM 
 typedef enum CiDevFeatureId_TAG {	 
 CI_DEV_FT_BAND_FREQ_BASE = 0 ,	 
 CI_DEV_FT_BAND_ORDER = 1 ,	 
 CI_DEV_FT_FORBIDDEN_PLMN_SIM = 2 ,	 
 CI_DEV_FT_FORBIDDEN_PLMN_NVM = 3 ,	 
 CI_DEV_FT_EHPLMN = 4 ,	 
 /*add by taow 20220829 CQ00138615 begin*/	 
 CI_DEV_FT_BARRED_PLMN = 5 ,	 
 /*add by taow 20220829 CQ00138615 end*/	 
 CI_DEV_FT_MEAS_REPORT_CFG = 6 , /*Lilei , CQ00138904 , 20220916 */	 
 /*add by taow CQ00139968 20221108 begin */	 
 CI_DEV_FT_REMAP_CAUSE ,	 
 CI_DEV_FT_REJECT_COUNTER ,	 
 /*add by taow CQ00139968 20221108 end */	 
 /*add by taow 20221215 begin*/	 
 CI_DEV_FT_MULTIPLE_GSM_BAND ,	 
 /*add by taow 20221215 end*/	 
 /*add by taow 20230720 CQ00144858 begin*/	 
 CI_DEV_FT_RPLMN_INFO ,	 
 /*add by taow 20230720 CQ00144858 end*/	 
 /*add by taow 20231110 CQ00146922 begin*/	 
 CI_DEV_FT_WHITE_CELL_LIST ,	 
 /*add by taow 20231110 CQ00146922 end*/	 
 CI_DEV_FT_NUM ,	 
	 
 CI_DEV_FT_MAX = 65535	 
 } _CiDevFeatureId;

typedef UINT16 CiDevFeatureId ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevBandOffset_Tag 
 {	 
 UINT8 bandId ;	 
 UINT8 reserved1 [ 3 ] ;	 
 UINT32 bandFreqLow ;	 
 UINT32 bandFreqHigh ;	 
 } CiDevBandFreq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevAbmmBandOffsetData_Tag 
 {	 
 UINT8 bandFreqNum ;	 
 UINT8 reserved1 [ 3 ] ;	 
 CiDevBandFreq bandFreq [ 20 ] ;	 
 } CiDevBandFreqBaseData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteSetBandOrderReq_struct {	 
 UINT8 lteBandNum ;	 
 UINT8 lteBandList [ 20 ] ;	 
 UINT8 reserved1 [ 3 ] ;	 
 } CiDevLteSetBandOrderData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevMeasReportConfigData_struct {	 
 INT8 offset_scell ; /*serving cell , LTE RSRP - offset , for check A1~A5 MR event Condition.*/	 
 INT8 offset_ncell_lte ; /*LTE ncell , LTE RSRP - offset , for check A1~A5 MR event Condition.*/	 
 } CiDevMeasReportConfigData;

//ICAT EXPORTED UNION:_CiDevFeatureId 
 typedef union CiDevCommonFeatureData_union 
 {	 
 CiDevBandFreqBaseData bandFreqBase ;	 
 CiDevLteSetBandOrderData lteSetBandOrder ;	 
 /* add by taow 20220228 CQ00135794 end*/	 
 CiDevForbidenPlmnListDataSim forbidenPlmnDataSim ;	 
 CiDevForbidenPlmnListDataNvm forbidenPlmnDataNvm ;	 
 CiDevEhplmnListData ehplmnData ;	 
 /* add by taow 20220228 CQ00135794 end*/	 
	 
 /*add by taow 20220829 CQ00138615 begin*/	 
 CiDevBarredPlmnData barredPlmnData ; /** all PLMN will be barred in the list , including HPLMN */	 
 /*add by taow 20220829 CQ00138615 end*/	 
 CiDevMeasReportConfigData measReportConfig ; /*Lilei , CQ00138904 , 20220916 */	 
 /*add by taow 20221108 CQ00139968 begin */	 
 CiDevRemapCauseData remapCauseData ;	 
 CiDevRejectCounterData rejectCounterData ;	 
 /*add by taow 20221108 CQ00139968 end */	 
 /*add by taow 20221215 begin*/	 
 CiDevMultipleGsmBand multipleGsmBand ;	 
 /*add by taow 20221215 end*/	 
 /*add by taow 20230720 CQ00144858 begin*/	 
 CiDevRplmnInfo rplmnInfo ;	 
 /*add by taow 20230720 CQ00144858 end*/	 
 /*add by taow 20231110 CQ00146922 begin*/	 
 CiDevWhiteCellListInfo whiteCellListInfo ;	 
 /*add by taow 20231110 CQ00146922 end*/	 
 UINT8 dummy [ 1024 ] ;	 
 } CiDevCommonFeatureData;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetCommonFeatureReq_struct {	 
 CiDevCmdType cmdType ; /*@ITEM_DESC@ 0 : Set or modify CMD 1 : Del CMD*/	 
 /** featureId == CI_DEV_FT_BAND_ORDER cmdType only use CI_DEV_CMD_SET */	 
	 
 UINT8 reserved ;	 
 CiDevFeatureId featureId ; /*@ITEM_DESC@ 0 : Set Band Freq Base 1 : Set lte Band Order 2 :FPlmn sim 3 :FPLMN nvm , 4 :ehplmn*/	 
 CiDevCommonFeatureData commonFtData ;	 
 } CiDevPrimSetCommonFeatureReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetCommonFeatureCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 CiDevFeatureId featureId ; /*@ITEM_DESC@ 0 : Set Band Freq Base 1 : Set lte Band Order 2 :FPlmn sim 3 :FPLMN nvm , 4 :ehplmn*/	 
 CiDevCommonFeatureData commonFtData ;	 
 } CiDevPrimSetCommonFeatureCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetCommonFeatureReq_struct {	 
 CiDevFeatureId featureId ; /*@ITEM_DESC@ 0 : Set Band Freq Base 1 : Set lte Band Order 2 :FPlmn sim 3 :FPLMN nvm , 4 :ehplmn */	 
 UINT32 index ;	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
	 
 } CiDevPrimGetCommonFeatureReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetCommonFeatureCnf_struct {	 
 CiDevRc rc ;	 
 CiDevFeatureId featureId ; /*@ITEM_DESC@ 0 : Set Band Freq Base 1 : Set lte Band Order 2 :FPlmn sim 3 :FPLMN nvm , 4 :ehplmn*/	 
 CiDevCommonFeatureData commonFtData ;	 
	 
 } CiDevPrimGetCommonFeatureCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIDEV_TX_RX_OPTION_TAG {	 
 CI_DEV_TX_START = 0 ,	 
 CI_DEV_RX_START ,	 
 CI_DEV_TX_RX_STOP ,	 
	 
 CI_DEV_NUM_TX_RX	 
 } _CiDevTxRxOption;

typedef UINT8 CiDevTxRxOption ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetNstTxRxReq_struct {	 
 CiDevTxRxOption option ; /**< Option. \sa CiDevTxRxOption */	 
 CiDevEngModeNetwork networkMode ; /**< 0 : GSM ; 1 : UMTS ; 2 : LTE */	 
 UINT8 band ; /**< GSM: 1 -PGSM , 2 -DCS , 4 -PCS , 8 -EGSM , 16 -GSM450 , 32 -GSM480 , 64 -GSM850 ; */	 
 /* WCDMA: 1 -BAND1 , 2 -BAND2 , ... , 14 :BAND14 ; LTE: 1 -BAND1 , 2 -BAND2... */	 
 UINT32 arfcn ;	 
 INT16 power ; /**< Tx or Rx power. For GSM TX , range [ 0 , 1 ] , otherwise in 0.100000 Dbm unit. */	 
 UINT8 slot ; /**< GSM TX slot. Range [ 1 , 4 ] . */	 
 UINT8 bandwidth ; /**< LTE bandwidth. Range [ 0 , 5 ] . */	 
	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 UINT32 reserved5 ;	 
 UINT32 reserved6 ;	 
 UINT32 reserved7 ;	 
 UINT32 reserved8 ;	 
 } CiDevPrimSetNstTxRxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetNstTxRxCnf_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc */	 
 INT16 rssiPri ; /**< The Rssi value of primary antenna to be returned for RX mode. */	 
 INT16 rssiSec ; /**< The Rssi value of secondary antenna to be returned for RX mode. Only used for LTE now. */	 
	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 } CiDevPrimSetNstTxRxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSimSlotReq_struct {	 
 UINT8 simSlot ; /**< 0 - sim slot 1 ; 1 - sim slot 2 */	 
 UINT8 reserved [ 3 ] ;	 
 } CiDevPrimSetSimSlotReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetSimSlotCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
 } CiDevPrimSetSimSlotCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSimSlotReq_struct {	 
 UINT8 reserved [ 4 ] ;	 
 } CiDevPrimGetSimSlotReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetSimSlotCnf_struct {	 
 CiDevRc rc ; /**< Result code \sa CiDevRc */	 
	 
 UINT8 simSlot ; /**< 0 - sim slot 1 ; 1 - sim slot 2 */	 
 UINT8 reserved [ 3 ] ;	 
 } CiDevPrimGetSimSlotCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevGsmServingCellInfo_v0002_struct 
 {	 
 UINT8 rxSigLevel ; /**< Receive signal level [ range: 0 h-3Fh ] */	 
 UINT8 rxSigLevelFull ; /**< Receive signal level accessed over all TDMA frames [ range: 0 h-3Fh ] */	 
 UINT8 rxSigLevelSub ; /**< Receive signal level accessed over subset of TDMA frames [ range: 0 h-3Fh ] */	 
 UINT8 rxQualityFull ; /**< Receive quality accessed over all TDMA frames [ range: 0 -7 ] */	 
 UINT8 rxQualitySub ; /**< Receive quality accessed over subset of TDMA frames [ range: 0 -7 ] */	 
 UINT8 rac ; /**< Routing area code [ range: 0 -1 ( 1 bit ) ] */	 
 UINT8 bsic ; /**< Base transceiver station identity code [ range: 0 h-3Fh ( 6 bits ) ] */	 
 UINT8 nom ; /**< Network operation mode [ range: MODE_1= 0 / MODE_2= 1 / MODE_3= 2 ] */	 
 UINT8 nco ; /**< Network control order [ range: NC_0=0 / NC_1=1 / NC_2=2 / NC_RESET=3 ] */	 
 UINT8 bs_pa_mfrms ; /**< Number of multiframes between paging messages sent [ range: 0 -7 ] */	 
	 
 UINT16 mcc ; /**< Mobile country code [ range: 0 -999 ( 3 digits ) ] */	 
 UINT16 mnc ; /**< Mobile network code [ range: 0 -99 ( 2 digits ) ] */	 
 UINT16 lac ; /**< Location area code [ range: 0 h-FFFFh ( 2 octets ) ] */	 
 UINT16 ci ; /**< Cell identity [ range: 0 h-FFFFh ( 2 octets ) ] */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number [ range: 0 -1023 ] */	 
	 
 INT16 C1 ; /**< Path loss criterion parameter #1 */	 
	 
 INT16 C2 ; /**< Path loss criterion parameter #2 */	 
	 
 INT16 C31 ; /**< GPRS signal level threshold criterion parameter*/	 
	 
 INT16 C32 ; /**< GPRS cell ranking criterion parameter */	 
	 
	 
 UINT16 t3212 ; /**< Periodic LA update timer ( T3212 ) in minutes */	 
 UINT16 t3312 ; /**< Periodic RA update timer ( T3312 ) in minutes */	 
	 
 CiBoolean pbcchSupport ; /**< Support of PBCCH \sa CCI API Ref Manual */	 
 UINT8 TxPowerLevel ; /**< Tx power level [ range: 0 h-3Fh ] */	 
 UINT8 timingAdv ; /**< Timing advance [ range 0 -63 ] */	 
 CiBoolean hoppingChannel ; /**< Hopping channel */	 
 CiBoolean EGPRSSupport ; /**< EGPRS support capability */	 
 CiDevEngChannelType ChType ; /**< Values are TCH_F = 1 , TCH_H = 2 , SDCCH_4 = 4 , SDCCH_8 = 8 \sa CIDEV_ENGMODE_CHANNEL_TYPE */	 
 CiBoolean nccPermitted ; /**< The NCC permitted parameter sets the NCCs ( network color codes ) that the mobile station is permitted to report. \sa CCI API Ref Manual */	 
 UINT8 RadioLinkTimeout ; /**< Radio link timeout [ range: value >=0 ] */	 
 UINT16 hoCount ; /**< Handovers counter [ range: value>=0 ] */	 
 UINT16 hoSuccessCount ; /**< Success handovers counter [ range: value>=0 ] */	 
 UINT16 chanAssCount ; /**< Channel assignment counter [ range: value>=0 ] */	 
 UINT16 chanAssSuccessCount ; /**< Success channel assignment counter [ range: value>=0 ] */	 
	 
 UINT16 arfcnTch ; /**< ARFCN for traffic channel , only valid for dedicated state [ range: 0 -1023 ] */	 
 UINT8 timeSlot ; /**< Time slot , only valid for dedicated state*/	 
 CiDevPacketIdleType isInPacketIdle ; /**< Only valid for idle state \sa CiDevPacketIdleType */	 
 /*Michal Bukai - I-Mate Addition. Start:*/	 
 CiBoolean IsForbiddenLA ; /**< Indicates if cell belongs to forbidden location area. FALSE: Cell is not in forbidden LA or forbidden status is unknown ; TRUE: Cell is in forbidden LA. \sa CCI API Ref Manual */	 
 CiDevCellPrioriytType CellPriority ; /**< Cell priority for cell selection or reselection. Cell priority can be normal , low or barred. \sa CiDevCellPrioriytType */	 
 UINT8 HSN ; /**< Hopping sequence number. Value 0 means cyclic hopping is done*/	 
 CiDevHoppingGroup HoppingGroup ; /**< List of ARFCNs assigned for frequency hopping . \sa CiDevHoppingGroup */	 
 /*Michal Bukai - I-Mate Addition. End*/	 
 /*Added by Lilei for Network Info CQ56702 , begin*/	 
 UINT8 gsmBand ; /**< 0 :PGSM_900 ; 1 :DCS_GSM_1800 ; 2 :PCS_GSM_1900 ; 3 :EGSM_900 ; 4 :GSM_450 ; 5 :GSM_480 ; 6 :GSM_850 */	 
 UINT8 channelMode ; /**< Mode of a dedicated channel , used during dedicated channel setup to specify channel mode ( signaling-only , speech or data ) , mode version and data rate. */	 
 /*Added by Lilei for Network Info CQ56702 , end*/	 
 /*Lilei , CQ00092855 , 20150427 , begin*/	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 /*Lilei , CQ00092855 , 20150427 , end*/	 
	 
 } CiDevGsmServingCellInfo_V0001 , CiDevGsmServingCellInfo_V0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevEngModeGsmData_v0002_struct 
 {	 
 CiDevGsmServingCellInfo_V0002 svcCellInfo ; /**< Serving cell information \sa CiDevGsmServingCellInfo_struct */	 
	 
 CiDevGsmGMMInfo GMMInfo ; /**< Mobility management information \sa CiDevGsmGMMInfo_struct */	 
 CiDevAMRInfo AMRInfo ; /**< AMR information \sa CiDevAMRInfo_struct */	 
 CiDevGPRSPTMInfo GPRSPTMInfo ; /**< Packet data information \sa CiDevGPRSPTMInfo_struct */	 
	 
 UINT8 numNCells ; /**< Number of neighboring cells [ 0 ..CI_DEV_MAX_GSM_NEIGHBORING_CELLS ] */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevGsmNeighboringCellInfo nbCellInfo [ 6 ] ; /**< Neighboring cell information \sa CiDevGsmNeighboringCellInfo_struct */	 
	 
 UINT8 numInterRATNCells ; /**< Number of InterRAT cells [ 0 ..CI_DEV_MAX_GSM_NEIGHBORING_CELLS ] */	 
 UINT8 res2U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevGsmUMTSNeighboringCellInfo InterRATCellInfo [ 6 ] ; /**< InterRAT cell information \sa CiDevCiDevGsmUMTSNeighboringCellInfo */	 
	 
 } CiDevEngModeGsmData_v0001 , CiDevEngModeGsmData_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGsmEngmodeInfoInd_v0002_struct 
 {	 
 CiDevEngModeState mode ; /**< Current Mode ( Idle / Dedicated ) . \sa CiDevEngModeState */	 
 UINT8 releaseVersion ; /**< 3 GPP release versions */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 CiDevEngModeGsmData_v0002 info ; /**< GSM Engineering Mode information. \sa CiDevEngModeGsmData_struct */	 
 } CiDevPrimGsmEngmodeInfoInd_v0001 , CiDevPrimGsmEngmodeInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 
 typedef struct CiDevUmtsUeOperationStatus_v0002_struct 
 {	 
 CiDevEngModeUeRrcState rrcState ; /**< RRC state \sa CiDevEngModeUeRrcState */	 
 UINT8 numLinks ; /**< Number of radio links */	 
	 
 UINT16 srncId ; /**< U-RNTI: SRNC identifier */	 
 UINT32 sRnti ; /**< U-RNTI: S-RNTI */	 
 CiCipherAlgorithmInfo csCipherInfo ; /**< CS domain ciphering information. \sa CiCipherAlgorithm_struct */	 
 CiCipherAlgorithmInfo psCipherInfo ; /**< PS domain ciphering information. \sa CiCipherAlgorithm_struct */	 
 CiBoolean HSDPAActive ; /**< TRUE - HSDPA is currently activated ; FALSE - other \sa CCI API Ref Manual */	 
 CiBoolean HSUPAActive ; /**< TRUE - HSUPA is currently activated ; FALSE - other \sa CCI API Ref Manual */	 
 UINT16 MccLastRegisteredNetwork ; /**< Mcc of last registered network */	 
 UINT16 MncLastRegisteredNetwork ; /**< Mnc of last registered network */	 
 INT32 TMSI ; /**< TMSI */	 
 INT32 PTMSI ; /**< PTMSI */	 
 CiBoolean IsSingleMmRejectCause ; /**< TRUE - only one MM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 CiBoolean IsSingleGmmRejectCause ; /**< TRUE - only one GMM reject cause reported during the last engineering information period ; FALSE - other \sa CCI API Ref Manual */	 
 CiDevEngMMRejectCauseCodeType MMRejectCause ; /**< The one that was reported during the last engineering information period reject cause ( 10.500000 .3.6 ) sent in CM Service Reject , Abort , MM-Status , and Location Updating Reject messages to MM from the network. \sa CiDevEngMMRejectCauseCodeType */	 
 CiDevEngGMMRejectCauseCodeType GMMRejectCause ; /**< Reported during the last engineering information period \sa CiDevEngGMMRejectCauseCodeType */	 
 UINT8 mmState ; /**< MM state refer to 3 GPP 24.008000 section 4.100000 .2 */ /* see enum MmState in Mm_comm.h. */	 
 UINT8 gmmState ; /**< GMM state refer to 3 GPP 24.008000 section 4.100000 .3 */ /* see enum GmmState in Gmm_comm.h */	 
 UINT8 gprsReadyState ; /**< 0 - IDLE_STATE / 1 - STANDBY_STATE / 2 - READY_STATE. */ /* see enum GprsReadyState in grrmrtyp.h. */	 
 UINT16 readyTimerValueInSecs ; /**< MM ready timer value in sec [ value >0 ] */	 
 UINT8 NumActivePDPContext ; /**< Number of active PDP contexts */	 
 /*Michal Bukai - I-Mate Addition. Start:*/	 
 UINT32 ULThroughput ; /**< UL throughput in octets per second */	 
 UINT32 DLThroughput ; /**< DL throughput in octets per second */	 
 /*Michal Bukai - I-Mate Addition. End*/	 
 /*Added by Lilei for Network Info CQ56702 , begin*/	 
 UINT8 serviceStatus ; /**< Service status */ /* see enum ServiceStatus in Mmr_sig.h. */	 
 UINT8 pmmState ; /**< UMM state for PS services */ /* see enum UmmState in Mm_comm.h. */	 
 /*Added by Lilei for Network Info CQ56702 , end*/	 
 /*Lilei , CQ00082362 , 20150116 , begin*/	 
 UINT8 LAU_status ; /**<Current update status of the UE */ /* see enum LocationUpdateStatus in Mmr_sig.h. */	 
 UINT16 LAU_count ; /**<LAU attempt counter as held by UE ; number of consecutive LAU failures in current LAU procedure attempt */	 
 UINT8 RAU_status ; /**<RAU status of the UE */ /* see enum GprsUpdateStatus in Mmr_sig.h. */	 
 UINT16 RAU_count ; /**<RAU attempt counter as held by UE ; number of consecutive RAU failures in current RAU procedure attempt*/	 
 /*Lilei , CQ00082362 , 20150116 , end*/	 
 } CiDevUmtsUeOperationStatus_v0001 , CiDevUmtsUeOperationStatus_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsServingCellInfo_v0002_struct 
 {	 
 CiBoolean sCellMeasPresent ; /**< TRUE - is present ; FALSE - is not present. \sa CCI API Ref Manual */	 
 CiBoolean sCellParamPresent ; /**< TRUE - is present ; FALSE - is not present. \sa CCI API Ref Manual */	 
 CiBoolean ueOpStatusPresent ; /**< TRUE - is present ; FALSE - is not present. \sa CCI API Ref Manual */	 
 UINT8 res1U8 ; /**< padding */	 
 CiDevUmtsServingCellMeasurements sCellMeas ; /**< SCell measurements \sa CiDevUmtsServingCellMeasurements_struct */	 
 CiDevUmtsServingCellParameters sCellParam ; /**< PLMN / cell parameters \sa CiDevUmtsServingCellParameters_struct */	 
 CiDevUmtsUeOperationStatus_v0001 ueOpStatus ; /**< UE operation status \sa CiDevUmtsUeOperationStatus_struct */	 
 } CiDevUmtsServingCellInfo_v0001 , CiDevUmtsServingCellInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeSvcCellInfoInd_v0002_struct 
 {	 
 CiDevEngModeState mode ; /**< Current mode ( idle / dedicated ) \sa CiDevEngModeState */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsServingCellInfo_v0001 info ; /**< Engineering mode 3 G ( UMTS ) serving cell information \sa CiDevUmtsServingCellInfo_struct */	 
 } CiDevPrimUmtsEngmodeScellInfoInd_v0001 , CiDevPrimUmtsEngmodeScellInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsFddTddNeighborInfo_v0002_struct 
 {	 
 /* Measurements */	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power */	 
 INT16 utraRssi ; /**< UTRA carrier RSSI */	 
 INT16 cpichEcN0 ; /**< CPICH Ec / N0 , only valid for FDD */	 
 INT16 sQual ; /**< Cell selection quality ( Squal ) , only valid for FDD */	 
 INT16 sRxLev ; /**< Cell selection Rx level ( Srxlev ) */	 
	 
 /* PLMN / Cell Parameters */	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 ci ; /**< Cell Identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
	 
 } CiDevUmtsFddTddNeighborInfo_v0001 , CiDevUmtsFddTddNeighborInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeInterFreqInfoInd_v0002_struct 
 {	 
 UINT8 numInterFreq ; /**< Number of Inter-Frequency FDD Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsFddTddNeighborInfo_v0001 interFreq [ 32 ] ; /**< Inter-Frequency Info. \sa CiDevUmtsFddTddNeighborInfo_struct */	 
 } CiDevPrimUmtsEngmodeInterFreqInfoInd_v0001 , CiDevPrimUmtsEngmodeInterFreqInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeIntraFreqInfoInd_v0002_struct 
 {	 
 UINT8 numIntraFreq ; /**< Number of Intra-Frequency FDD Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsFddTddNeighborInfo_v0001 intraFreq [ 32 ] ; /**< Intra-Frequency Info. \sa CiDevUmtsFddTddNeighborInfo_struct */	 
 } CiDevPrimUmtsEngmodeIntraFreqInfoInd_v0001 , CiDevPrimUmtsEngmodeIntraFreqInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevUmtsGsmNeighborInfo_v0002_struct 
 {	 
 /* Measurements */	 
 INT16 gsmRssi ; /**< GSM carrier RSSI */	 
 INT16 rxLev ; /**< Cell selection Rx level */	 
 INT16 C1 ; /**< Path loss criterion parameter #1 */	 
 INT16 C2 ; /**< Path loss criterion parameter #2 */	 
	 
 /* PLMN / Cell Parameters */	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT16 ci ; /**< Cell identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 UINT8 bsic ; /**< Base transceiver station identity code ; range 0 h-3Fh ( 6 bits ) */	 
 UINT8 res1U8 ;	 
	 
 } CiDevUmtsGsmNeighborInfo_v0001 , CiDevUmtsGsmNeighborInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimUmtsEngmodeInterRatInfoInd_v0002_struct 
 {	 
 UINT8 numInterRAT ; /**< Number of Inter-RAT GSM Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevUmtsGsmNeighborInfo_v0001 interRAT [ 32 ] ; /**< Inter-Rat Info. \sa CiDevUmtsGsmNeighborInfo_struct */	 
	 
 } CiDevPrimUmtsEngmodeInterRatInfoInd_v0001 , CiDevPrimUmtsEngmodeInterRatInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngScellParams_v0002_struct 
 {	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT16 mcc ;	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT16 mnc ; /**< 2 -3 digits of MNC */	 
 UINT16 tac ;	 
 UINT16 phyCellId ;	 
 UINT32 dlEuArfcn ;	 
 UINT32 ulEuArfcn ;	 
 UINT16 band ;	 
 UINT8 dlBandwidth ; /*0 - 1.400000 M , 1 - 3 M , 2 - 5 M , 3 - 10 M , 4 - 15 M , 5 - 20 M */	 
 UINT32 cellId ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 /*Added by taow for LTE EM L2 info , begin*/	 
 UINT8 subFrameAssignType ;	 
 UINT8 specialSubframePatterns ;	 
 UINT8 transMode ;	 
 /*Added by taow for LTE EM L2 info , end*/	 
	 
	 
 } CiDevLteEngScellParams_v0001 , CiDevLteEngScellParams_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngScellMeas_v0002_struct 
 {	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 INT8 sinr ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT8 mainRsrp ; /**< Rsrp of main antenna. Value range: 0 ~97 , invalid ( 0xFF ) */	 
 UINT8 diversityRsrp ; /**< Rsrp of diversity antenna. Value range: 0 ~97 , invalid ( 0xFF ) */	 
 UINT8 mainRsrq ; /**< Rsrq of main antenna. Value range: 0 ~34 , invalid ( 0xFF ) */	 
 UINT8 diversityRsrq ; /**< Rsrq of diversity antenna. Value range: 0 ~34 , invalid ( 0xFF ) */	 
 UINT8 rssi ; /**< Value range: 0 ~128 , invalid ( 0xFF ) . ( rssi-128 ) for dbm format */	 
 UINT16 cqi ; /**< Value range: 0 ~15 , invalid ( 0xFFFF ) . */	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 /*Added by taow for LTE EM L2 info , begin*/	 
 UINT8 pathLoss ;	 
 UINT32 tb0DlTpt ;	 
 UINT32 tb1DlTpt ;	 
 UINT32 tb0DlPeakTpt ;	 
 UINT32 tb1DlPeakTpt ;	 
 UINT32 tb0UlPeakTpt ;	 
 UINT32 tb1UlPeakTpt ;	 
 // EmacdlStatisticDataTag	 
 UINT32 dlThroughPut ; // dl throughtput unit bps , sum ( dl tb size in bits ) / dl statistic time duration	 
 UINT32 dlPeakThroughPut ; // Kbps	 
 UINT8 averDlPRB ;	 
 UINT8 averCQITb0 ;	 
 UINT8 averCQITb1 ;	 
 UINT8 rankIndex ;	 
 // EmaculStatisticDataTag	 
 UINT32 grantTotal ; // total received grant size in unit of BYTE	 
 UINT32 ulThroughPut ; // Kbps	 
 UINT32 ulPeakThroughPut ; // Kbps	 
 INT16 currPuschTxPower ;	 
 UINT8 averUlPRB ;	 
 // add by taow 20150415 begin	 
 UINT8 reserved0 ;	 
 UINT16 dlBler ;	 
 UINT16 ulBler ;	 
 UINT32 reserved1 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 // add by taow 20150415 end	 
 /*Added by taow for LTE EM L2 info , end*/	 
	 
 } CiDevLteEngScellMeas_v0001 , CiDevLteEngScellMeas_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngScellInfo_v0002_struct 
 {	 
 CiDevLteEngScellParams_v0001 params ;	 
 CiDevLteEngScellMeas_v0001 meas ;	 
 // CiDevLteEngineerCellAccessRestrictions accessRestrictions ;	 
 // CiDevLteEngineerBarredStatus barredStatus ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 CiDevLteUeOperationStatus ueOpStatus ; /**< UE operation status \sa CiDevLteUeOperationStatus */	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
 } CiDevLteEngScellInfo_v0001 , CiDevLteEngScellInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeSvcCellInfoInd_v0002_struct 
 {	 
 // CiDevLteEngModeState mode ; / **< Current mode ( deactivated / idle / connected / reselection ) \sa CiDevLteEngModeState * /	 
 CiBoolean sCellPresent ; /**< Whether serving cell engmode info is present */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevLteEngScellInfo_v0001 info ; /**< Engineering mode LTE serving cell information \sa CiDevLteEngScellInfo */	 
 } CiDevPrimLteEngmodeScellInfoInd_v0001 , CiDevPrimLteEngmodeScellInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngInterFreqNcellInfo_v0001_struct 
 {	 
 UINT16 phyCellId ;	 
 UINT32 euArfcn ;	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 // CiBoolean ncellSib1Valid ;	 
 // CiDevLteEngNcellSib1 ncellSib1 ;	 
 // CiBoolean accessRestrictionsPresent ;	 
 // CiDevLteEngineerCellAccessRestrictions accessRestrictions ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT16 mcc ;	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT16 mnc ; /**< 2 -3 digits of MNC */	 
 UINT16 tac ;	 
 UINT32 cellId ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
	 
 } 
 CiDevLteEngInterFreqNcellInfo_v0001 , CiDevLteEngInterFreqNcellInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngIntraFreqNcellInfo_v0002_struct 
 {	 
 UINT16 phyCellId ;	 
 UINT32 euArfcn ;	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 // CiBoolean ncellSib1Valid ;	 
 // CiDevLteEngNcellSib1 ncellSib1 ;	 
 // CiBoolean accessRestrictionsPresent ;	 
 // CiDevLteEngineerCellAccessRestrictions accessRestrictions ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , begin*/	 
 UINT16 mcc ;	 
 UINT8 lenOfMnc ; /**< Length of MNC , value range ( 2 , 3 ) */	 
 UINT16 mnc ; /**< 2 -3 digits of MNC */	 
 UINT16 tac ;	 
 UINT32 cellId ;	 
 /*Added by Lilei for LTE Engineering Mode CQ56421 , end*/	 
	 
 } CiDevLteEngIntraFreqNcellInfo_v0001 , CiDevLteEngIntraFreqNcellInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeIntraFreqInfoInd_v0002_struct 
 {	 
 UINT8 numIntraFreq ; /**< Number of Intra-Frequency Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevLteEngIntraFreqNcellInfo_v0001 intraFreq [ 16 ] ; /**< Intra-Frequency Info. \sa CiDevLteEngIntraFreqNcellInfo */	 
 } CiDevPrimLteEngmodeIntraFreqInfoInd_v0001 , CiDevPrimLteEngmodeIntraFreqInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeInterFreqInfoInd_v0002_struct 
 {	 
 UINT8 numInterFreq ; /**< Number of Inter-Frequency Cells */	 
 UINT8 res1U8 [ 3 ] ; /**< ( padding ) */	 
 CiDevLteEngInterFreqNcellInfo_v0001 interFreq [ 16 ] ; /**< Inter-Frequency Info. \sa CiDevLteEngInterFreqNcellInfo */	 
 } CiDevPrimLteEngmodeInterFreqInfoInd_v0001 , CiDevPrimLteEngmodeInterFreqInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraCellParams_v0002_Struct 
 {	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT32 ci ; /**< Cell identity ; as per 3 G TS 25.331000 , 10.300000 .2.2 ( 28 bits ) */	 
 UINT16 uArfcn ;	 
 UINT16 psc_cellParameterId ; /**< Primary scrambling code for FDD or Cell parameter id for TDD */	 
 // UINT16 phyCellId ;	 
	 
 } CiDevLteEngUtraCellParams_v0001 , CiDevLteEngUtraCellParams_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraCellMeas_v0002_struct 
 {	 
 INT16 rscp ; /**< CPICH / PCCPCH received signal code power ; in UMTS FDD / TDD messages RSCP is	 
 transmitted as an integer value in the range of -120 dBm to -25 dBm.	 
 The value is coded into integers from -5 to 99 according to 3 GPP ' s 25.133000 . */	 
 // INT16 pccpch_RSCP ; // for TDD	 
 INT16 cpichEcN0 ; // For FDD	 
 // INT16 cpichRscp ; // For FDD	 
 } 
 CiDevLteEngUtraCellMeas_v0001 , CiDevLteEngUtraCellMeas_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngUtraNcellInfo_v0002_struct 
 {	 
 CiDevLteEngUtraCellParams_v0001 params ;	 
 CiDevLteEngUtraCellMeas_v0001 meas ;	 
 } CiDevLteEngUtraNcellInfo_v0001 , CiDevLteEngUtraNcellInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellParams_v0002_struct 
 {	 
 UINT16 mcc ; /**< Mobile country code */	 
 UINT16 mnc ; /**< Mobile network code */	 
 UINT16 lac ; /**< Location area code */	 
 UINT32 ci ; /**< Cell identity */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number */	 
 // UINT8 gsmBandIndicator ;	 
 // CiBoolean bsicPresent ; // ncc and bcc is valid only when bsicPresent is TURE.	 
 // CiDevLteEngBsic bsic ;	 
 UINT8 bsic ; /**< Base transceiver station identity code ; range 0 h-3Fh ( 6 bits ) ; 0xFF means not present */	 
 } 
 CiDevLteEngGsmCellParams_v0001 , CiDevLteEngGsmCellParams_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellMeas_v0002_struct 
 {	 
 INT16 rssi ; /**< GSM carrier RSSI */	 
 } CiDevLteEngGsmCellMeas_v0001 , CiDevLteEngGsmCellMeas_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevLteEngGsmCellInfo_v0002_struct 
 {	 
 CiDevLteEngGsmCellParams_v0001 params ;	 
 CiDevLteEngGsmCellMeas_v0001 meas ;	 
 } CiDevLteEngGsmCellInfo_v0001 , CiDevLteEngGsmCellInfo_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimLteEngmodeInterRatInfoInd_v0002_struct 
 {	 
 UINT8 numInterRATUtra ; /**< Number of Inter-RAT UMTS Cells */	 
 UINT8 numInterRATGsm ; /**< Number of Inter-RAT GSM Cells */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 CiDevLteEngUtraNcellInfo_v0001 interRATUtra [ 16 ] ; /**< Inter-Rat UMTS Info. \sa CiDevLteEngUtraNcellInfo */	 
 CiDevLteEngGsmCellInfo_v0001 interRATGsm [ 16 ] ; /**< Inter-Rat UMTS Info. \sa CiDevLteEngUtraNcellInfo */	 
 } CiDevPrimLteEngmodeInterRatInfoInd_v0001 , CiDevPrimLteEngmodeInterRatInfoInd_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimSetMedataCommReserveCnf_v0001_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 } CiDevPrimSetMedataCommReserveCnf_v0001 , CiDevPrimSetMedataCommReserveCnf_v0002;

//ICAT EXPORTED STRUCT 
 typedef struct CiDevPrimGetMedataCommReserveCnf_v0001_struct {	 
 CiDevRc rc ; /**< Result code. \sa CiDevRc. */	 
 UINT8 ConfigValue ; /*value to set */	 
 } CiDevPrimGetMedataCommReserveCnf_v0001 , CiDevPrimGetMedataCommReserveCnf_v0002;

typedef union
 {
 char *filename ;
 __QUEC_CONFIG_ENUM config_num ;
 } quec_baudrate_info_u ;
typedef void ( *debug_to_app_callback ) ( char *data ) ;
