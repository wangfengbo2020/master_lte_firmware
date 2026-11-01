//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\ci_server_task_ttc.ppp
//PPL Source File Name : X:\\pcac\\ci_stub\\src\\ci_server_task_ttc.c
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
typedef UINT32 CCI_TRACE_LEVEL ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef volatile UINT8 *V_UINT8_PTR ;
typedef volatile UINT16 *V_UINT16_PTR ;
typedef volatile UINT32 *V_UINT32_PTR ;
typedef unsigned int U32Bits ;
typedef BOOL BOOLEAN ;
typedef const char * SwVersion ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_PIN_NOT_ASSIGNED = -1 ,	 
	 
 GPIO_PIN_0 = 0 , GPIO_PIN_1 , GPIO_PIN_2 , GPIO_PIN_3 , GPIO_PIN_4 , GPIO_PIN_5 , GPIO_PIN_6 , GPIO_PIN_7 ,	 
	 
 GPIO_PIN_8 , GPIO_PIN_9 , GPIO_PIN_10 , GPIO_PIN_11 , GPIO_PIN_12 , GPIO_PIN_13 , GPIO_PIN_14 , GPIO_PIN_15 ,	 
 GPIO_PIN_16 , GPIO_PIN_17 , GPIO_PIN_18 , GPIO_PIN_19 , GPIO_PIN_20 , GPIO_PIN_21 , GPIO_PIN_22 , GPIO_PIN_23 ,	 
 GPIO_PIN_24 , GPIO_PIN_25 , GPIO_PIN_26 , GPIO_PIN_27 , GPIO_PIN_28 , GPIO_PIN_29 , GPIO_PIN_30 , GPIO_PIN_31 ,	 
 GPIO_PIN_32 , GPIO_PIN_33 , GPIO_PIN_34 , GPIO_PIN_35 , GPIO_PIN_36 , GPIO_PIN_37 , GPIO_PIN_38 , GPIO_PIN_39 ,	 
	 
 GPIO_PIN_40 , GPIO_PIN_41 , GPIO_PIN_42 , GPIO_PIN_43 , GPIO_PIN_44 , GPIO_PIN_45 , GPIO_PIN_46 , GPIO_PIN_47 ,	 
 GPIO_PIN_48 , GPIO_PIN_49 , GPIO_PIN_50 , GPIO_PIN_51 , GPIO_PIN_52 , GPIO_PIN_53 , GPIO_PIN_54 , GPIO_PIN_55 ,	 
 GPIO_PIN_56 , GPIO_PIN_57 , GPIO_PIN_58 , GPIO_PIN_59 , GPIO_PIN_60 , GPIO_PIN_61 , GPIO_PIN_62 , GPIO_PIN_63 ,	 
	 
 GPIO_PIN_64 , GPIO_PIN_65 , GPIO_PIN_66 , GPIO_PIN_67 , GPIO_PIN_68 , GPIO_PIN_69 , GPIO_PIN_70 , GPIO_PIN_71 ,	 
 GPIO_PIN_72 , GPIO_PIN_73 , GPIO_PIN_74 , GPIO_PIN_75 , GPIO_PIN_76 , GPIO_PIN_77 , GPIO_PIN_78 , GPIO_PIN_79 ,	 
 GPIO_PIN_80 , GPIO_PIN_81 , GPIO_PIN_82 , GPIO_PIN_83 , GPIO_PIN_84 , GPIO_PIN_85 , GPIO_PIN_86 , GPIO_PIN_87 ,	 
 GPIO_PIN_88 , GPIO_PIN_89 , GPIO_PIN_90 , GPIO_PIN_91 , GPIO_PIN_92 , GPIO_PIN_93 , GPIO_PIN_94 , GPIO_PIN_95 ,	 
	 
 GPIO_PIN_96 , GPIO_PIN_97 , GPIO_PIN_98 , GPIO_PIN_99 , GPIO_PIN_100 , GPIO_PIN_101 , GPIO_PIN_102 , GPIO_PIN_103 ,	 
 GPIO_PIN_104 , GPIO_PIN_105 , GPIO_PIN_106 , GPIO_PIN_107 , GPIO_PIN_108 , GPIO_PIN_109 , GPIO_PIN_110 , GPIO_PIN_111 ,	 
 GPIO_PIN_112 , GPIO_PIN_113 , GPIO_PIN_114 , GPIO_PIN_115 , GPIO_PIN_116 , GPIO_PIN_117 , GPIO_PIN_118 , GPIO_PIN_119 ,	 
 GPIO_PIN_120 , GPIO_PIN_121 , GPIO_PIN_122 , GPIO_PIN_123 , GPIO_PIN_124 , GPIO_PIN_125 , GPIO_PIN_126 , GPIO_PIN_127 ,	 
	 
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
 GPIO_RC_INCORRECT_INIT_VALUE	 
	 
 , GPIO_RC_INTC_ERROR ,	 
 GPIO_RC_PRM_ERROR	 
	 
 } GPIO_ReturnCode;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_INPUT_PIN = 1 ,	 
 GPIO_OUTPUT_PIN	 
 } GPIO_PinDirection;

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
 GPIO_PinDirection direction ;	 
 } GPIO_PinStatus;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_INITIAL_VALUE_NO_CHANGE = 0 ,	 
 GPIO_INITIAL_VALUE_LOW ,	 
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
 GPIO_PinDirection direction ;	 
 GPIO_TransitionType transitionType ;	 
 GPIO_Debounce debounce ;	 
 GPIO_PullUpDown pullUpDown ;	 
 GPIO_BitInitialValue initialValue ;	 
 } GPIO_PinConfiguration;

typedef UINT8 GPIO_PortHandle ;
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
typedef UINT8 FSMState ;
typedef UINT8 FSMEvent ;
typedef UINT8 FSMAction ;
typedef const UINT8* FSMStateTable ;
typedef FSMDescriptor* FSMPtr ;
typedef BOOL ( *FSMActionFunc ) ( FSMPtr fsm ) ;
typedef const FSMActionFunc* FSMActionFuncTable ;
typedef UINT32 MSL_TRACE_LEVEL ;
typedef INT32 MSL_STATUS ;
typedef union _mslCallbackContext
 {
 MslDlSapStatusIndParms sapStatusIndParms ;
 MslDlCreateSapConfParms createSapConfParms ;
 MslDlDeleteSapConfParms deleteSapConfParms ;
 MslDlCeStatusIndParms ceStatusIndParms ;
 MslDlConnectIndParms connectIndParms ;
 MslDlConnectConfParms connectConfParms ;
 MslDlDisconnectIndParms disconnectIndParms ;
 MslDlDisconnectConfParms disconnectConfParms ;
 MslDlActivateIndParms activateIndParms ;
 MslDlActivateConfParms activateConfParms ;
 MslDlDmRxDataIndParms dmRxDataIndParms ;
 MslDlDmTxDataConfParms dmTxDataConfParms ;
 MslDlRxDataIndParms rxDataIndParms ;
 MslDlTxDataConfParms txDataConfParms ;

 MslClientDiscoverServiceConfParms discoverSvcConfParms ;
 MslClientAbortConfParms abortConfParms ;
 MslServerAddServiceConfParms addSvcConfParms ;
 } MslCallbackContext , *PMslCallbackContext ;
typedef MSL_STATUS ( *MSLDL_CTRL_CALLBACK ) (
 UINT32 ctrlCallbackPrimitive ,
 PMslCallbackContext ptParms
 ) ;
typedef MSL_STATUS ( *MSLDL_DATA_CALLBACK ) (
 UINT32 dataCallbackPrimitive ,
 PMslCallbackContext ptParms
 ) ;
typedef UINT8 MslDrErrorCode ;
typedef UINT8 MslDrState ;
typedef BOOL ( *MslDrFn ) ( MslDrStream* , void* ) ;
typedef UINT8 MslDrMemFree ( UINT32 , void* ) ;
typedef UINT8 MslDrMemAlloc ( UINT32 , void** , UINT32 , UINT32 ) ;
typedef UINT8 SAL_RPC_STATUS ;
typedef UINT8 Stbc_Status ;
typedef void ( *MslSalStbcStatusIndFunc ) ( UINT32 , Stbc_Status ) ;
typedef void ( *MslSalStbcCreateRpcPacketFunc ) ( UINT32 , void* , MslBuffer* ) ;
typedef void ( *MslSalStbcClientSvCallbackFunc ) ( UINT32 , UINT8* , UINT32 ) ;
typedef void ( *MslSalStbcServerSvCallbackFunc ) ( UINT32 , UINT8* , UINT32 , MslBuffer* ) ;
typedef void ( *MslSalStbcDataSendConfFunc ) ( UINT32 , Stbc_Status , void* ) ;
typedef void ( *MslSalStbcTimeoutReqFunc ) ( UINT32 ) ;
typedef Stbc_Status ( *MslSalStbcUnmarshalCallRespFunc ) ( UINT32 , UINT8* , UINT32 , void* ) ;
typedef void ( *MslDataChanReadyCallbackFunc ) ( BOOL , UINT32 ) ;
typedef MSL_STATUS ( *MslDataChanRxCallbackFunc ) ( UINT32 , PMslCallbackContext ) ;
typedef union _UstbcHandle {

 StbcServerHandle serverHandle ;





 } UstbcHandle ;
typedef UINT8 CiSysWrapReturnCode ;
typedef UINT8 CiSysWrapStatus ;
typedef void ( *CiClientStubStatusInd ) ( CiSysWrapStatus status ) ;
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
//ICAT EXPORTED ENUM 
 typedef enum CI_PS_PRIM 
 {	 
 CI_PS_PRIM_SET_ATTACH_STATE_REQ = 1 , /**< \brief Requests to attach ME to , or detach ME from , the packet domain service \details */	 
 CI_PS_PRIM_SET_ATTACH_STATE_CNF , /**< \brief Confirms a request and attaches ME to , or detaches ME from , the packet domain service \details */	 
 CI_PS_PRIM_GET_ATTACH_STATE_REQ , /**< \brief Requests to get the current packet domain service state \details */	 
 CI_PS_PRIM_GET_ATTACH_STATE_CNF , /**< \brief Confirms a request and returns the current packet domain service state \details */	 
 CI_PS_PRIM_DEFINE_PDP_CTX_REQ , /**< \brief Requests to define a PDP context for a specified CID \details */	 
 CI_PS_PRIM_DEFINE_PDP_CTX_CNF , /**< \brief Confirms a request to define a PDP context for a specified CID	 
 * \details If the PDP context address field is NULL , a dynamic address is requested. */	 
 CI_PS_PRIM_DELETE_PDP_CTX_REQ , /**< \brief Requests to delete a PDP context \details */	 
 CI_PS_PRIM_DELETE_PDP_CTX_CNF , /**< \brief Confirms a request to delete a PDP context \details */	 
 CI_PS_PRIM_GET_PDP_CTX_REQ , /**< \brief Requests to get a PDP context definition \details */	 
 CI_PS_PRIM_GET_PDP_CTX_CNF = 10 , /**< \brief Confirms a request and returns the PDP context setting \details */	 
 CI_PS_PRIM_GET_PDP_CTX_CAPS_REQ , /**< \brief Requests the PDP context capabilities supported by the cellular subsystem \details */	 
 CI_PS_PRIM_GET_PDP_CTX_CAPS_CNF , /**< \brief Confirms a request and returns the PDP context capabilities supported by the cellular subsystem \details */	 
 CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ , /**< \brief Requests to activate ( or deactivate ) one or all PDP contexts \details */	 
 CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_CNF , /**< \brief Confirms a request and activates ( or deactivates ) one or all PDP contexts \details */	 
 CI_PS_PRIM_GET_PDP_CTXS_ACT_STATE_REQ , /**< \brief Requests to get the current activation state of all defined PDP contexts \details */	 
 CI_PS_PRIM_GET_PDP_CTXS_ACT_STATE_CNF , /**< \brief Confirms a request and returns the current activation state of all defined PDP contexts \details */	 
 CI_PS_PRIM_ENTER_DATA_STATE_REQ , /**< \brief Requests to notify the cellular subsystem that the application subsystem is entering a data state , which means it is now going to send or receive packet data	 
 * \details This request triggers a PDP attach procedure and / or a PDP context activation procedure if they have not already been generated.	 
 * The parameter optimizedData enables the optimized ACI data plane.	 
 * This parameter must be set to TRUE to use the optimized DATA service group primitives.	 
 * Note that the option not to use the ACI optimized data plane is supported for backward compatibility. */	 
 CI_PS_PRIM_ENTER_DATA_STATE_CNF , /**< \brief Confirms a request and notifies the cellular subsystem that the application subsystem has entered a data state	 
 * \details Now , the cellular subsystem can start using the DATA service group	 
 * primitives to send and receive data over the packet service domain. */	 
 CI_PS_PRIM_MT_PDP_CTX_ACT_MODIFY_IND , /**< \brief Indicates that a network initiated the activation or modification of a PDP context \details */	 
 CI_PS_PRIM_MT_PDP_CTX_ACT_MODIFY_RSP = 20 , /**< \brief Responds to a mobile terminated PDP context indication \details */	 
 CI_PS_PRIM_MT_PDP_CTX_ACTED_IND , /**< \brief Indicates the mobile terminated PDP context is activated after manual or auto answer	 
 * \details The cellular subsystem assigns the CID ( context ID ) for the MT PDP context. */	 
 CI_PS_PRIM_SET_GSMGPRS_CLASS_REQ , /**< \brief Requests to set the mobile class for GSM / GPRS \details This primitive only applies to GSM / GPRS networks. */	 
 CI_PS_PRIM_SET_GSMGPRS_CLASS_CNF , /**< \brief Confirms the request and sets the mobile class for GSM / GPRS \details This primitive only applies to GSM / GPRS networks. */	 
 CI_PS_PRIM_GET_GSMGPRS_CLASS_REQ , /**< \brief Requests the current setting of the GSM / GPRS mobile class \details This primitive only applies to GSM / GPRS networks. */	 
 CI_PS_PRIM_GET_GSMGPRS_CLASS_CNF , /**< \brief Confirms a request and gets the current GSM / GPRS mobile class \details This only applies to GSM / GPRS networks. */	 
 CI_PS_PRIM_GET_GSMGPRS_CLASSES_REQ , /**< \brief Requests the supported GSM / GPRS mobile classes \details */	 
 CI_PS_PRIM_GET_GSMGPRS_CLASSES_CNF , /**< \brief Confirms a request and returns the supported GSM / GPRS mobile classes \details This only applies to GSM / GPRS networks. */	 
 CI_PS_PRIM_ENABLE_NW_REG_IND_REQ , /**< \brief Requests to enable or disable GPRS network registration status reports \details */	 
 CI_PS_PRIM_ENABLE_NW_REG_IND_CNF , /**< \brief Confirms a request and enables or disables GPRS network registration status reports \details */	 
 CI_PS_PRIM_NW_REG_IND = 30 , /**< \brief Indicates the GPRS network registration status \details GPRS network indications may be enabled or disabled by CI_PS_PRIM_ENABLE_NW_REG_IND_REQ.	 
 * This indication is disabled by default. No explicit response is required. */	 
 CI_PS_PRIM_SET_QOS_REQ , /**< \brief Requests to set the QoS profile for a PDP context	 
 * \details The ME checks the minimum acceptable profile against the negotiated profile returned in the Activate PDP Context Accept message.	 
 * The required quality of service profile is used when the ME sends an Activate PDP Context Request message to the network.	 
 * This is only used for 2.500000 G ( R97 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_GET_3G_QOS_REQ for 3 G ( R99 ) QoS profile parameters.*/	 
 CI_PS_PRIM_SET_QOS_CNF , /**< \brief Confirms a request and sets the QoS profile	 
 * \details This is only used for 2.500000 G ( R97 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_GET_3G_QOS_CNF for 3 G ( R99 ) QoS profile parameters. */	 
 CI_PS_PRIM_DEL_QOS_REQ , /**< \brief Requests to delete the QoS profile for a PDP context	 
 * \details If a PDP context does not have a minimum or required	 
 * QoS profile , the QoS is determined by the network on PDP context activation.	 
 * This is only used for 2.500000 G ( R97 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_DEL_3G_QOS_REQ for 3 G ( R99 ) QoS profile parameters.*/	 
 CI_PS_PRIM_DEL_QOS_CNF , /**< \brief Confirms a request and deletes the QoS profile setting	 
 * \details This is only used for 2.500000 G ( R97 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_DEL_3G_QOS_CNF for 3 G ( R99 ) QoS profile parameters.*/	 
 CI_PS_PRIM_GET_QOS_REQ , /**< \brief Requests the QoS profile for a PDP context	 
 * \details This is only used for 2.500000 G ( R97 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_GET_3G_QOS_REQ for 3 G ( R99 ) QoS profile parameters.*/	 
 CI_PS_PRIM_GET_QOS_CNF , /**< \brief Confirms a request and gets the QoS profile for a PDP context	 
 * \details This is only used for 2.500000 G ( R97 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_GET_3G_QOS_CNF for 3 G ( R99 ) QoS profile parameters.*/	 
 /*Michal Bukai - AutoAttach Configuration - Samsung - START*/	 
 CI_PS_PRIM_ENABLE_POWERON_AUTO_ATTACH_REQ , /**< \brief Configure auto attach to PS domain on power up	 
 * \details The configuration will be saved in NVM and will be effective in the next power up. */	 
 CI_PS_PRIM_ENABLE_POWERON_AUTO_ATTACH_CNF , /**< \brief Confirms the request and updates NVM auto attach configuration \details */	 
 /*Michal Bukai - AutoAttach Configuration - Samsung - End*/	 
 CI_PS_PRIM_MT_PDP_CTX_REJECTED_IND , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_PS_PRIM_PDP_CTX_DEACTED_IND = 40 , /**< \brief Indicates that the PDP context has been deactivated	 
 * \details This indication is sent if PS event reports are enabled ; see CI_PS_PRIM_ENABLE_EVENTS_REPORTING_REQ.*/	 
 CI_PS_PRIM_PDP_CTX_REACTED_IND , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_PS_PRIM_DETACHED_IND , /**< \brief Indicates that the ME has detached from the packet service domain	 
 * \details The indication is sent if PS event reports are enabled ; see CI_PS_PRIM_ENABLE_EVENTS_REPORTING_REQ. */	 
 CI_PS_PRIM_GPRS_CLASS_CHANGED_IND , /**< \brief Indicates that the GSM / GPRS mobile class has changed \details */	 
 CI_PS_PRIM_GET_DEFINED_CID_LIST_REQ , /**< \brief Requests the defined PDP context identifiers list \details */	 
 CI_PS_PRIM_GET_DEFINED_CID_LIST_CNF , /**< \brief Confirms a request and returns the defined PDP context identifiers list \details */	 
 CI_PS_PRIM_GET_NW_REG_STATUS_REQ , /**< \brief Requests the GPRS network registration status \details */	 
 CI_PS_PRIM_GET_NW_REG_STATUS_CNF , /**< \brief Confirms a request and returns the GPRS network registration status \details */	 
 CI_PS_PRIM_GET_QOS_CAPS_REQ , /**< \brief Requests the QoS capabilities	 
 * \details This is only used for 2.500000 G ( R97 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_GET_3G_QOS_CAPS_REQ for 3 G ( R99 ) QoS profile parameters.*/	 
 CI_PS_PRIM_GET_QOS_CAPS_CNF , /**< \brief Confirms a request and returns the QoS capabilities	 
 * \details This is only used for 2.500000 G ( R97 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_GET_3G_QOS_CAPS_CNF for 3 G ( R99 ) QoS profile parameters.*/	 
 CI_PS_PRIM_ENABLE_EVENTS_REPORTING_REQ = 50 , /**< \brief Requests to enable or disable PS event reports	 
 * \details By default , event reporting indications are enabled.	 
 * Event indications include the following: \n	 
 * CI_PS_PRIM_PDP_CTX_DEACTED_IND \n	 
 * CI_PS_PRIM_DETACHED_IND */	 
 CI_PS_PRIM_ENABLE_EVENTS_REPORTING_CNF , /**< \brief Confirms a request and enables or disables PS event reports \details */	 
	 
 /* SCR #1401348: 3 G Quality of Service ( QoS ) primitives */	 
 CI_PS_PRIM_GET_3G_QOS_REQ , /**< \brief Requests the 3 G QoS profile for a PDP context	 
 * \details This is only used for 3 G ( R99 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_GET_QOS_REQ for 2.500000 G ( R97 ) QoS profile parameters.*/	 
 CI_PS_PRIM_GET_3G_QOS_CNF , /**< \brief Confirms a request and returns the 3 G QoS profile for a PDP context	 
 * \details This is only used for 3 G ( R99 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_GET_QOS_CNF for 2.500000 G ( R97 ) QoS profile parameters.*/	 
 CI_PS_PRIM_SET_3G_QOS_REQ , /**< \brief Requests to set a 3 G QoS profile for PDP context activation	 
 * \details The negotiated QoS profile cannot be written by this request.	 
 * If the qosType parameter is set to CI_PS_3G_QOSTYPE_NEG , CCI returns an error indication.	 
 * The required and minimum quality of service profiles are used when the MT sends an Activate PDP Context Request for a primary or	 
 * secondary PDP context or a Modify PDP Context Request to the network.	 
 * This primitive is used to set 3 G ( R99 ) QoS profile parameters	 
 * Use CI_PS_PRIM_SET_QOS_REQ to set the 2.500000 G ( R97 ) QoS profile parameters.*/	 
 CI_PS_PRIM_SET_3G_QOS_CNF , /**< \brief Confirms a request and sets a 3 G QoS profile for a PDP context	 
 * \details This is only used for 3 G ( R99 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_SET_QOS_CNF for 2.500000 G ( R97 ) QoS profile parameters.*/	 
 CI_PS_PRIM_DEL_3G_QOS_REQ , /**< \brief Requests to delete the 3 G QoS profile for a PDP context	 
 * \details The negotiated QoS profile cannot be deleted by this request.	 
 * If the qosType parameter is set to CI_PS_3G_QOSTYPE_NEG , CCI returns an error indication.	 
 * If a PDP context does not have a minimum or required QoS profile ,	 
 * the QoS is determined by the network on PDP context activation.	 
 * This is only used for 3 G ( R99 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_DEL_QOS_REQ for 2.500000 G ( R97 ) QoS profile parameters.*/	 
 CI_PS_PRIM_DEL_3G_QOS_CNF , /**< \brief Confirms a request and deletes the 3 G QoS profile	 
 * \details This is only used for 3 G ( R99 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_DEL_QOS_CNF for 2.500000 G ( R97 ) QoS profile parameters. */	 
	 
 CI_PS_PRIM_GET_3G_QOS_CAPS_REQ , /**< \brief Requests the 3 G QoS capabilities	 
 * \details This is only used for the 3 G ( R99 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_GET_QOS_CAPS_REQ for 2.500000 G ( R97 ) QoS profile parameters.*/	 
 CI_PS_PRIM_GET_3G_QOS_CAPS_CNF , /**< \brief Confirms a request and gets the 3 G QoS capabilities	 
 * \details This is only used for 3 G ( R99 ) QoS profile parameters.	 
 * Use CI_PS_PRIM_GET_QOS_CAPS_CNF for 2.500000 G ( R97 ) QoS profile parameters. */	 
	 
 /* SCR #1438547: Secondary PDP Context primitives */	 
 CI_PS_PRIM_DEFINE_SEC_PDP_CTX_REQ = 60 , /**< \brief Requests to define a secondary PDP context \details */	 
 CI_PS_PRIM_DEFINE_SEC_PDP_CTX_CNF , /**< \brief Confirms a request to define a secondary PDP context \details */	 
 CI_PS_PRIM_DELETE_SEC_PDP_CTX_REQ , /**< \brief Requests to delete a secondary PDP context	 
 * \details An error is returned if the secondary PDP context does not exist. */	 
 CI_PS_PRIM_DELETE_SEC_PDP_CTX_CNF , /**< \brief Confirms a request to delete a secondary PDP context \details */	 
 CI_PS_PRIM_GET_SEC_PDP_CTX_REQ , /**< \brief Requests a secondary PDP context definition	 
 * \details An error is returned if the secondary PDP context does not exist. */	 
 CI_PS_PRIM_GET_SEC_PDP_CTX_CNF , /**< \brief Confirms a request and returns the secondary PDP context definition \details An error is returned if the secondary PDP context does not exist. */	 
	 
 /* SCR #1438547: traffic flow template ( TFT ) primitives */	 
 CI_PS_PRIM_DEFINE_TFT_FILTER_REQ , /**< \brief Requests to define a traffic flow template ( TFT ) packet filter	 
 * \details Traffic flow templates are described in 3 GPP TS 23.060000 section 15.300000 .	 
 * Each PDP context connected to a particular PDP address and APN may be associated with a traffic flow template ( TFT ) . ( TFTs enable	 
 * filtering of downlink IP packets. )	 
 * A TFT contains one to eight packet filters.	 
 * The use of traffic flow templates allows multiple PDP contexts	 
 * ( each with a different quality of service ) to share the same PDP address.	 
 * The TFT packet filters are used to route incoming IP packets to their appropriate PDP contexts.	 
 * Only one PDP context may exist without an associated TFT , and this PDP context	 
 * is considered the default	 
 * PDP context. The network routes downlink packets	 
 * to this PDP context if none of the TFT packet filters apply.	 
 * A TFT , if one exists , is always associated with a PDP context during secondary PDP context activation.	 
 * A TFT may be added to an activated PDP context ( either a primary or a secondary context )	 
 * using the MS-initiated PDP context modify procedure , which is initiated by a CI_PS_PRIM_MODIFY_PDP_CTX_REQ request.	 
 * The packet filter contents field encoding is specified in 3 GPP TS 24.008000 Table 10.500000 .162 ( Section 10.500000 .6.12 ) .	 
 * An error is returned if no more TFT packet filters are allowed. */	 
 CI_PS_PRIM_DEFINE_TFT_FILTER_CNF , /**< \brief Confirms a request and defines a TFT packet filter \details */	 
 CI_PS_PRIM_DELETE_TFT_REQ , /**< \brief Requests to delete the traffic flow template ( TFT ) associated with a PDP context \details All packet filters that comprise the indicated TFT are deleted.	 
 * An error is returned when: \n	 
 * No TFT exists for the indicated PDP context. \n	 
 * The PDP context itself ( either primary or secondary ) is not defined. \n	 
 * More than one PDP context is using a single PDP address , and deleting this TFT would violate the rule that only one PDP	 
 * context using a particular PDP address may exist without a TFT associated with it. \n	 
 * See 3 GPP TS 23.060000 section 15.300000 .1 ( Rules for Operations on TFTs ) . */	 
 CI_PS_PRIM_DELETE_TFT_CNF , /**< \brief Confirms a request and deletes the traffic flow template \details */	 
 CI_PS_PRIM_GET_TFT_REQ = 70 , /**< \brief Requests to get the traffic flow template ( TFT ) associated with a PDP context \details Requests a list of all packet filters that comprise the TFT for the specified PDP context.	 
 * An error is returned if a TFT does not exist for the indicated PDP context , or if the PDP context ( either primary or secondary ) is not	 
 * defined. */	 
 CI_PS_PRIM_GET_TFT_CNF , /**< \brief Confirms a request and gets the traffic flow template ( TFT ) associated with a PDP context \details */	 
	 
 /* SCR TBD: PDP context modify primitives */	 
 CI_PS_PRIM_MODIFY_PDP_CTX_REQ , /**< \brief Requests to modify one PDP context or all active PDP contexts \details Allows the quality of service ( QoS ) and / or the traffic flow template ( TFT ) to be modified for a PDP context that has already been	 
 * activated. This request can be used for either primary or secondary PDP contexts.	 
 * Before issuing this request , set up or modify the QoS and / or TFT , using the appropriate CI requests. */	 
 CI_PS_PRIM_MODIFY_PDP_CTX_CNF , /**< \brief Confirms a request and modifies one PDP context or all active PDP contexts \details */	 
 CI_PS_PRIM_GET_ACTIVE_CID_LIST_REQ , /**< \brief Requests to get a list of context identifiers for all active PDP contexts \details This request is similar to CI_PS_PRIM_GET_DEFINED_CID_LIST_REQ except that it only returns information for active PDP contexts.	 
 * It is provided to support the same functionality as the " AT+CGCMOD=? " command. See 3 GPP TS 27.007000 section 10.100000 .11. */	 
 CI_PS_PRIM_GET_ACTIVE_CID_LIST_CNF , /**< \brief Confirms a request and returns a list of context identifiers for all active PDP contexts \details */	 
 CI_PS_PRIM_REPORT_COUNTER_REQ , /**< \brief Requests to configure the PDP Context Data Counter report	 
 * \details Data counters are maintained by the protocol stack for all active PDP contexts.	 
 * Data counter values are reported to the application subsystem using CI_PS_PRIM_COUNTER_IND.	 
 * This request is rejected if the control plane has not been attached to packet domain services or there are no active PDP contexts. */	 
 CI_PS_PRIM_REPORT_COUNTER_CNF , /**< \brief Confirms a request and configures the PDP Context Data Counter report \details */	 
 CI_PS_PRIM_RESET_COUNTER_REQ , /**< \brief Requests to reset PDP context data counters	 
 * \details Data counters are maintained by the protocol stack for all active PDP contexts.	 
 * Depending on the parameter settings , this request resets the data counters to zero for one or all active PDP contexts.	 
 * This request is rejected if: \n	 
 * The Control Plane is not attached to Packet Domain services. \n	 
 * There are no active PDP contexts. \n	 
 * The doAll parameter is FALSE and the CID parameter is invalid or does not specify an active PDP context. */	 
 CI_PS_PRIM_RESET_COUNTER_CNF , /**< \brief Confirms a request and resets PDP context data counters \details */	 
 CI_PS_PRIM_COUNTER_IND = 80 , /**< \brief Indicates a PDP context data counter report \details CCI sends this indication on request or periodically , as configured by CI_PS_PRIM_REPORT_COUNTER_REQ. If a periodic report cycle	 
 * is stopped , this indication is disabled.	 
 * The totals indicate the number of bytes ( octets ) sent and received since the data counters were last reset. \n	 
 * The totalULBytes counter is the total number of uplink data octets before compression ( if any ) . \n	 
 * The totalDLBytes counter is the total number of downlink data octets after decompression ( if any ) . \n	 
 * See also CI_PS_PRIM_RESET_COUNTER_REQ. */	 
	 
 CI_PS_PRIM_SEND_DATA_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
	 
 CI_PS_PRIM_SEND_DATA_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
	 
 /* Michal Bukai & Boris Tsatkin AT&T Smart Card support - Start*/	 
 /*** AT&T- Smart Card CI_PS_PRIM_ ACL SERVICE: LIST , SET , EDIT -BT6 */	 
 CI_PS_PRIM_SET_ACL_SERVICE_REQ , /**< \brief Requests to enable or disable APN control list ( ACL ) service	 
 * \details PIN2 must be verified ( using CI_SIM_PRIM_OPERCHV_REQ ) before using this request */	 
 CI_PS_PRIM_SET_ACL_SERVICE_CNF , /**< \brief Confirms the request to enable or disable APN control list ( ACL ) service	 
 * \details */	 
 CI_PS_PRIM_GET_ACL_SIZE_REQ , /**< \brief Requests the size of the ACL list	 
 * \details */	 
 CI_PS_PRIM_GET_ACL_SIZE_CNF , /**< \brief Confirms the request and returns the size of the ACL list	 
 * \details */	 
 CI_PS_PRIM_READ_ACL_ENTRY_REQ , /**< \brief Requests to read an entry from the ACL list	 
 * \details */	 
 CI_PS_PRIM_READ_ACL_ENTRY_CNF , /**< \brief Confirms the request and returns the requested ACL entry	 
 * \details */	 
 CI_PS_PRIM_EDIT_ACL_ENTRY_REQ , /**< \brief Requests to edit an entry in the ACL list	 
 * \details PIN2 must be verified ( using CI_SIM_PRIM_OPERCHV_REQ ) before using this request. */	 
 CI_PS_PRIM_EDIT_ACL_ENTRY_CNF = 90 , /**< \brief Confirms the request to edit an entry in the ACL list */	 
 /* ADD NEW COMMON PRIMITIVES HERE , BEFORE ' CI_PS_PRIM_LAST_COMMON_PRIM ' */	 
 /* Michal Bukai & Boris Tsatkin AT&T Smart Card support - End*/	 
	 
 /* Michal Bukai 每 PDP authentication - Start*/	 
 CI_PS_PRIM_AUTHENTICATE_REQ , /**< \brief Requests to add authentication parameters to a defined PDP context.	 
 * \details The command must be sent after the PDP context was defined and before the PDP context is activated.	 
 * The authentication parameters will be sent to the GGSN in a protocol configuration information entry , when PDP context is activated.	 
 * In case authentication parameters are already defined for this PDP context the new authentication parameters will replace the existing parameters.	 
 * AuthenticationType = NONE , will delete authentication parameters defined for this PDP context. */	 
 CI_PS_PRIM_AUTHENTICATE_CNF , /**< \brief Confirms the authentication request. \details */	 
 /* Michal Bukai 每 PDP authentication - End*/	 
 /* Michal Bukai 每 Fast Dormancy - Start*/	 
 CI_PS_PRIM_FAST_DORMANT_REQ , /**< \brief Requests to release data radio bearers , in order to speed entry to DRX mode.	 
 * \details The application should use this request for offline applications such as push mail ,	 
 * in cases that it knows that data transition is complete and there is no anticipated data transmission in the next minute.	 
 * The PS will send " Signalling connection release indication " to the NW requesting to release data radio bearers. */	 
 CI_PS_PRIM_FAST_DORMANT_CNF , /**< \brief Confirms the fast dormancy request.	 
 * \details The following result codes can be received:	 
 * CIRC_PS_SUCCESS - Indicates " Signalling connection release indication " was sent to the NW	 
 * CIRC_PS_FAILURE Indicates " Signalling connection release indication " was not sent to the NW due to one of the following reasons:	 
 * Active RAT is not UMTS	 
 * There no active PDP contexts	 
 * There is an active CS connection	 
 * RRC state is not CELL DCH or CELL FACH	 
 * CIRC_PS SRVOPT_NOT_SUPPORTED -Indicates fast dormancy is not supported. */	 
 /* Michal Bukai 每 Fast Dormancy - End*/	 
	 
 CI_PS_PRIM_GET_CURRENT_JOB_REQ , /**< \brief Requests current ongoing request for PS service group. */	 
 CI_PS_PRIM_GET_CURRENT_JOB_CNF , /**< \brief Confirms the current job request. */	 
	 
 CI_PS_PRIM_SET_FAST_DORMANCY_CONFIG_REQ , /**< \brief Requests to set configuration of fast dormancy. */	 
 CI_PS_PRIM_SET_FAST_DORMANCY_CONFIG_CNF , /**< \brief Confirms the configuration of fast dormancy. */	 
	 
 CI_PS_PRIM_PDP_ACTIVATION_REJECT_CAUSE_IND , /**< \brief Indicates SM cause code for PDP activation reject. */	 
	 
 CI_PS_PRIM_SET_PS_PAGING_CONFIG_REQ = 100 , /**< \brief Requests to set activation / deactvation of DSDS PS+Paging. */	 
 CI_PS_PRIM_SET_PS_PAGING_CONFIG_CNF , /**< \brief Confirms the configuration of DSDS PS+Paging */	 
	 
 /*Michal Bukai - AutoAttach Configuration - Samsung - START*/	 
 CI_PS_PRIM_GET_POWERON_AUTO_ATTACH_STATUS_REQ , /**< \brief Requests to read the configuration status of auto attach to PS domain on power up \details */	 
 CI_PS_PRIM_GET_POWERON_AUTO_ATTACH_STATUS_CNF , /**< \brief Confirms the request and returns auto attach configuration status \details */	 
 /*Michal Bukai - AutoAttach Configuration - Samsung - END*/	 
 CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_REQ , /**< \brief Gets a PDP context definition. \details */	 
 CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_CNF , /**< \brief Gets a PDP context definition. \details */	 
 CI_PS_PRIM_READ_4G_PDP_CTXS_ACT_DYN_PARA_REQ , /**< \brief Gets all defined PDP contexts current activation state. \details */	 
 CI_PS_PRIM_READ_4G_PDP_CTXS_ACT_DYN_PARA_CNF , /**< \brief Reports the current activation state of all defined PDP contexts. \details */	 
 CI_PS_PRIM_ENABLE_4G_NW_REG_IND_REQ , /**< \brief Enables / disables EPS network registration status reports. \details */	 
 CI_PS_PRIM_ENABLE_4G_NW_REG_IND_CNF , /**< \brief Confirms request to enable / disable EPS network registration status reports. \details */	 
 CI_PS_PRIM_4G_NW_REG_IND = 110 ,	 
 CI_PS_PRIM_GET_4G_NW_REG_STATUS_REQ , /**< \brief Requests the EPS network registration status. \details */	 
 CI_PS_PRIM_GET_4G_NW_REG_STATUS_CNF , /**< \brief Reports the EPS network registration status. \details */	 
 CI_PS_PRIM_GET_4G_QOS_REQ ,	 
 CI_PS_PRIM_GET_4G_QOS_CNF ,	 
 CI_PS_PRIM_SET_4G_QOS_REQ ,	 
 CI_PS_PRIM_SET_4G_QOS_CNF ,	 
 CI_PS_PRIM_DEL_4G_QOS_REQ ,	 
 CI_PS_PRIM_DEL_4G_QOS_CNF ,	 
 CI_PS_PRIM_GET_4G_QOS_CAPS_REQ ,	 
 CI_PS_PRIM_GET_4G_QOS_CAPS_CNF = 120 ,	 
	 
 CI_PS_PRIM_GET_4G_MODE_REQ ,	 
 CI_PS_PRIM_GET_4G_MODE_CNF ,	 
 CI_PS_PRIM_SET_4G_MODE_REQ ,	 
 CI_PS_PRIM_SET_4G_MODE_CNF ,	 
 CI_PS_PRIM_GET_4G_MODE_CAPS_REQ ,	 
 CI_PS_PRIM_GET_4G_MODE_CAPS_CNF ,	 
 CI_PS_PRIM_GET_PDP_ADDR_REQ ,	 
 CI_PS_PRIM_GET_PDP_ADDR_CNF ,	 
 CI_PS_PRIM_GET_PDP_ADDR_LIST_REQ ,	 
 CI_PS_PRIM_GET_PDP_ADDR_LIST_CNF = 130 ,	 
 CI_PS_PRIM_READ_4G_SEC_PDP_CTX_DYN_PARA_REQ , /**< \brief Requests a Secondary PDP Context Read Dynamic Parameters .	 
 * \details Returns an error if the Secondary PDP Context does not exist. */	 
 CI_PS_PRIM_READ_4G_SEC_PDP_CTX_DYN_PARA_CNF , /**< \brief Reports a Secondary PDP Context Dynamic Parameters . Indicates an error if the Secondary PDP Context does not exist. \details */	 
 CI_PS_PRIM_READ_4G_SEC_PDP_CTXS_ACT_DYN_PARA_REQ ,	 
 CI_PS_PRIM_READ_4G_SEC_PDP_CTXS_ACT_DYN_PARA_CNF ,	 
 CI_PS_PRIM_READ_4G_QOS_DYN_PARA_REQ ,	 
 CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CNF ,	 
 CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CAPS_REQ ,	 
 CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CAPS_CNF ,	 
 CI_PS_PRIM_GET_4G_EVET_REP_REQ ,	 
 CI_PS_PRIM_GET_4G_EVET_REP_CNF = 140 ,	 
 CI_PS_PRIM_SET_4G_EVET_REP_REQ ,	 
 CI_PS_PRIM_SET_4G_EVET_REP_CNF ,	 
 CI_PS_PRIM_GET_4G_EVET_REP_CAPS_REQ ,	 
 CI_PS_PRIM_GET_4G_EVET_REP_CAPS_CNF ,	 
	 
	 
 CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_REQ ,	 
 CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CNF ,	 
 CI_PS_PRIM_SET_4G_VOICE_CALL_MODE_REQ ,	 
 CI_PS_PRIM_SET_4G_VOICE_CALL_MODE_CNF ,	 
 CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CAPS_REQ ,	 
 CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CAPS_CNF = 150 ,	 
	 
 CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_REQ , // Traffic Flow Template Read Dynamic Parameters +CGTFTRDP	 
 CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CNF , // Traffic Flow Template Read Dynamic Parameters +CGTFTRDP	 
 CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CAPS_REQ , // Traffic Flow Template Read Dynamic Parameters +CGTFTRDP	 
 CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CAPS_CNF , // Traffic Flow Template Read Dynamic Parameters +CGTFTRDP	 
	 
 CI_PS_PRIM_DATACOMP_REPORTING_REQ , /**< \brief Sets data compression reporting to on or off. Also used to read current setting of data	 
 compression reporting. Data compression	 
 reporting is used when AT+DR AT command is	 
 executed. If enabled , than sending of	 
 CI_PS_PRIM_DATACOMP_IND is enabled */	 
 CI_PS_PRIM_DATACOMP_REPORTING_CNF , /**< \brief Confirmation to the sets data compression	 
 reporting request. Returns the current setting	 
 of the data compression reporting. */	 
 CI_PS_PRIM_DATACOMP_IND , /**< \brief Indicates the status of the data compression. */	 
	 
 CI_PS_PRIM_SET_IMS_VOICE_CALL_AVAILABILITY_REQ , /**< \brief Set command informs the MT whether the UE is currently available for voice calls with the IMS ( see 3 GPP TS 24.229000 )	 
 * \details The information can be used by the MT to determine " IMS voice not available " as defined in 3 GPP TS 24.301000 ,	 
 * and for mobility management for IMS voice termination , see 3 GPP TS 24.008000 */	 
 CI_PS_PRIM_SET_IMS_VOICE_CALL_AVAILABILITY_CNF , /**< \brief Confirmation to the setting of whether the UE is currently available for voice calls with the IMS */	 
 CI_PS_PRIM_GET_IMS_VOICE_CALL_AVAILABILITY_REQ = 160 , /**< \brief Gets the stored setting of the IMS voice call availability */	 
 CI_PS_PRIM_GET_IMS_VOICE_CALL_AVAILABILITY_CNF , /**< \brief Confirmation to the request to get the stored setting of the IMS voice call availability */	 
 CI_PS_PRIM_SET_IMS_SMS_AVAILABILITY_REQ , /**< \brief Set command informs the MT whether the UE is currently available for SMS using IMS ( see 3 GPP TS 24.229000 )	 
 * \details The information can be used by the MT to determine the need to remain attached for non-EPS services ,	 
 * as defined in 3 GPP TS 24.301000 */	 
 CI_PS_PRIM_SET_IMS_SMS_AVAILABILITY_CNF , /**< \brief Confirmation to the setting of whether the UE is currently available for SMS with the IMS */	 
 CI_PS_PRIM_GET_IMS_SMS_AVAILABILITY_REQ , /**< \brief Gets the stored setting of the IMS SMS availability */	 
 CI_PS_PRIM_GET_IMS_SMS_AVAILABILITY_CNF , /**< \brief Confirmation to the request to get the stored setting of the IMS SMS availability */	 
 CI_PS_PRIM_SET_MM_IMS_VOICE_TERMINATION_REQ , /**< \brief Sets the Mobility Management for IMS Voice Termination to support terminating access domain selection by the network */	 
 CI_PS_PRIM_SET_MM_IMS_VOICE_TERMINATION_CNF , /**< \brief Confirmation to the request to set the MM for IMS Voice Termination */	 
 CI_PS_PRIM_GET_MM_IMS_VOICE_TERMINATION_REQ , /**< \brief Gets the setting of the Mobility Management for IMS Voice Termination */	 
 CI_PS_PRIM_GET_MM_IMS_VOICE_TERMINATION_CNF , /**< \brief Confirmation to the request to get the stored setting of the MM for IMS Voice Termination */	 
	 
 CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_REQ = 170 , /** AT*CGDFLT , set the default PDP info */	 
 CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_CNF ,	 
 CI_PS_PRIM_GET_DEFAULT_PDP_CTX_REQ , /** AT*CGDFLT? , get the default PDP info */	 
 CI_PS_PRIM_GET_DEFAULT_PDP_CTX_CNF ,	 
	 
 CI_PS_PRIM_SET_APN_REQ , /** AT+VZWAPNE= , used to set APN info */	 
 CI_PS_PRIM_SET_APN_CNF ,	 
 CI_PS_PRIM_GET_APN_REQ , /** AT+VZWAPNE? , used to get APN info */	 
 CI_PS_PRIM_GET_APN_CNF ,	 
	 
 CI_PS_PRIM_SET_IMS_REG_STATE_REQ , /** used to notify CP the IMS register state , as IMS on AP side now , when IMS register state changes , should notify CP */	 
 CI_PS_PRIM_SET_IMS_REG_STATE_CNF ,	 
 CI_PS_PRIM_UE_EVENT_TO_IMS_IND = 180 , /** used by CP to notify the IMS module some UE event , such as: UICC removed , APN changed , etc */	 
	 
 CI_PS_PRIM_SET_IMS_REG_INFO_IND_REQ , /** AT+CIREG= [ <n> ] , set whether need to report IMS register state. As IMS on AP side now , this CI do not need to be processed in CP side by now*/	 
 CI_PS_PRIM_SET_IMS_REG_INFO_IND_CNF ,	 
 CI_PS_PRIM_IMS_REG_INFO_IND , /** +CIREGU: <reg_info> [ , <ext_info> ] . IMS module report the IMS state*/	 
 CI_PS_PRIM_GET_IMS_REG_INFO_REQ , /** AT+CIREG? , read command*/	 
 CI_PS_PRIM_GET_IMS_REG_INFO_CNF ,	 
	 
 CI_PS_PRIM_SET_DEFAULT_PDP_AUTHENTICATE_REQ , /** AT*CGDFAUTH=<mode> , <type> [ , <UserName> [ , <Password> ] ] */	 
 CI_PS_PRIM_SET_DEFAULT_PDP_AUTHENTICATE_CNF ,	 
 CI_PS_PRIM_GET_DEFAULT_PDP_AUTHENTICATE_REQ ,	 
 CI_PS_PRIM_GET_DEFAULT_PDP_AUTHENTICATE_CNF , /** AT*CGDFAUTH=<mode> */	 
	 
 CI_PS_PRIM_SET_VOICE_DOMAIN_PREFERENCE_REQ = 190 , /** AT+CVDP= [ <setting> ] / AT+CEVDP= [ <setting> ] , UE ' s Voice Domain Preference */	 
 CI_PS_PRIM_SET_VOICE_DOMAIN_PREFERENCE_CNF ,	 
 CI_PS_PRIM_GET_VOICE_DOMAIN_PREFERENCE_REQ , /** AT+CVDP? AT+CEVDP? UE ' s Voice Domain Preference UTRAN */	 
 CI_PS_PRIM_GET_VOICE_DOMAIN_PREFERENCE_CNF ,	 
	 
 CI_PS_PRIM_SET_EPS_USAGE_SETTING_REQ , /** AT+CEUS= [ <setting> ] , UE ' s usage setting for EPS*/	 
 CI_PS_PRIM_SET_EPS_USAGE_SETTING_CNF ,	 
 CI_PS_PRIM_GET_EPS_USAGE_SETTING_REQ , /** AT+CEUS? , UE ' s usage setting for EPS*/	 
 CI_PS_PRIM_GET_EPS_USAGE_SETTING_CNF ,	 
	 
 CI_PS_PRIM_SET_AP_UNIVERSAL_SETTING_REQ ,	 
 CI_PS_PRIM_SET_AP_UNIVERSAL_SETTING_CNF ,	 
	 
 CI_PS_PRIM_SET_PS_SERVICE_DOMAIN_REQ = 200 ,	 
 CI_PS_PRIM_SET_PS_SERVICE_DOMAIN_CNF ,	 
 CI_PS_PRIM_GET_PS_SERVICE_DOMAIN_REQ ,	 
 CI_PS_PRIM_GET_PS_SERVICE_DOMAIN_CNF ,	 
	 
 CI_PS_PRIM_SET_IMS_SERVICE_STATUS_REQ ,	 
 CI_PS_PRIM_SET_IMS_SERVICE_STATUS_CNF ,	 
	 
 CI_PS_PRIM_SUSPEND_RESUME_IND ,	 
	 
 CI_PS_PRIM_CHAP_AUTHENTICATE_REQ , /** AT*CHAPAUTH=cid [ , <challenge> [ , <response> ] ] , for PPP CHAP authentication */	 
 CI_PS_PRIM_CHAP_AUTHENTICATE_CNF ,	 
	 
 CI_PS_PRIM_ACTIVATE_RECONF_PDP_CTX_REQ , /** used to activate reconfigured PDP ( an already activated PDP is re-defined ) */	 
 CI_PS_PRIM_ACTIVATE_RECONF_PDP_CTX_CNF = 210 ,	 
	 
 /* ============== Added for REL13 ====================================================*/	 
 CI_PS_PRIM_SET_PSM_CONFIG_REQ ,	 
 CI_PS_PRIM_SET_PSM_CONFIG_CNF ,	 
 CI_PS_PRIM_GET_PSM_CONFIG_REQ ,	 
 CI_PS_PRIM_GET_PSM_CONFIG_CNF ,	 
	 
 CI_PS_PRIM_SET_EDRX_CONFIG_REQ ,	 
 CI_PS_PRIM_SET_EDRX_CONFIG_CNF ,	 
 CI_PS_PRIM_GET_EDRX_CONFIG_REQ ,	 
 CI_PS_PRIM_GET_EDRX_CONFIG_CNF ,	 
 CI_PS_PRIM_EDRX_INFO_IND ,	 
 CI_PS_PRIM_READ_EDRX_DYN_PARA_REQ = 220 ,	 
 CI_PS_PRIM_READ_EDRX_DYN_PARA_CNF ,	 
	 
 CI_PS_PRIM_SET_CIOT_CONFIG_REQ ,	 
 CI_PS_PRIM_SET_CIOT_CONFIG_CNF ,	 
 CI_PS_PRIM_GET_CIOT_CONFIG_REQ ,	 
 CI_PS_PRIM_GET_CIOT_CONFIG_CNF ,	 
 CI_PS_PRIM_CIOT_NW_INFO_IND ,	 
	 
 CI_PS_PRIM_CONFIG_SIGNALLING_CONNECTION_REQ ,	 
 CI_PS_PRIM_CONFIG_SIGNALLING_CONNECTION_CNF ,	 
 CI_PS_PRIM_GET_SIGNALLING_CONNECTION_STATUS_REQ ,	 
 CI_PS_PRIM_GET_SIGNALLING_CONNECTION_STATUS_CNF = 230 ,	 
 CI_PS_PRIM_SIGNALLING_CONNECTION_IND ,	 
	 
 CI_PS_PRIM_SET_INITIAL_PDP_ACTIVATION_OPT_REQ ,	 
 CI_PS_PRIM_SET_INITIAL_PDP_ACTIVATION_OPT_CNF ,	 
 CI_PS_PRIM_GET_INITIAL_PDP_ACTIVATION_OPT_REQ ,	 
 CI_PS_PRIM_GET_INITIAL_PDP_ACTIVATION_OPT_CNF ,	 
	 
 CI_PS_PRIM_SET_APN_BACKOFF_TIMER_STATUS_REQ ,	 
 CI_PS_PRIM_SET_APN_BACKOFF_TIMER_STATUS_CNF ,	 
 CI_PS_PRIM_GET_APN_BACKOFF_TIMER_STATUS_REQ ,	 
 CI_PS_PRIM_GET_APN_BACKOFF_TIMER_STATUS_CNF ,	 
 CI_PS_PRIM_APN_BACKOFF_TIMER_STATUS_REPORT_IND = 240 ,	 
 CI_PS_PRIM_READ_APN_BACKOFF_TIMER_DYN_PARA_REQ ,	 
 CI_PS_PRIM_READ_APN_BACKOFF_TIMER_DYN_PARA_CNF ,	 
	 
 CI_PS_PRIM_GET_APN_RATE_CONTROL_REQ ,	 
 CI_PS_PRIM_GET_APN_RATE_CONTROL_CNF ,	 
	 
 CI_PS_PRIM_GET_PDP_CONTEXT_INFO_REQ ,	 
 CI_PS_PRIM_GET_PDP_CONTEXT_INFO_CNF ,	 
	 
 CI_PS_PRIM_SET_PDP_CTX_REMAP_REQ ,	 
 CI_PS_PRIM_SET_PDP_CTX_REMAP_CNF ,	 
	 
	 
 /* END OF COMMON PRIMITIVES LIST */	 
 CI_PS_PRIM_LAST_COMMON_PRIM	 
	 
 /* the customer specific extension primitives are added starting from	 
 * CI_PS_PRIM_firstCustPrim = CI_PS_PRIM_LAST_COMMON_PRIM as the first identifier.	 
 * The actual primitive names and IDs are defined in the associated	 
 * ' ci_ps_cust_xxx.h ' file.	 
 */	 
	 
 /* DO NOT ADD ANY MORE PRIMITIVES HERE */	 
	 
 } _CiPsPrim;

//ICAT EXPORTED ENUM 
 typedef enum CIRC_PS 
 {	 
 CIRC_PS_SUCCESS = 0 , /**< Request completed successfully */	 
 CIRC_PS_FAILURE , /**< Request failed */	 
	 
 /* failure to perform an Attach */	 
 CIRC_PS_ILLEGAL_MS = 0x03 , /**< Illegal MS */	 
 CIRC_PS_ILLEGAL_ME = 0x06 , /**< Illegal ME */	 
 CIRC_PS_GPRS_SERVICES_NOT_ALLOWED = 0x07 , /**< GPRS service not allowed */	 
 CIRC_PS_OPER_DETERMINED_BARRING = 0x08 , /**< Operator Determined Barring */	 
 CIRC_PS_DETACH = 10 , // 0x0A / **< implicitly detached * /	 
 CIRC_PS_PLMN_NOT_ALLOWED = 0x0B , /**< PLMN not allowed */	 
 CIRC_PS_LA_NOT_ALLOWED = 0x0C , /**< Location area not allowed */	 
 CIRC_PS_ROAMING_NOT_ALLOWED = 0x0D , /**< Roaming not allowed in this location area */	 
 CIRC_PS_MSC_NOT_REACH = 16 , // 0x10 / **< MSC temporarily not reachable * /	 
 CIRC_PS_NW_CONGESTION = 22 , // 0x16 / **< Congestion * /	 
 CIRC_PS_RESOURCE_INSUFF = 26 , // 0x1A / **< Insufficient resources * /	 
 CIRC_PS_APN = 27 , // 0x1B / **< Missing or unknown APN * /	 
 CIRC_PS_UNKNOWN_PDP_ADD_TYPE = 28 , // 0x1C / **< unknown PDP address or PDP type * /	 
 CIRC_PS_USER_AUTH_FAIL = 29 , // 0x1D / **< user authentication failed * /	 
 CIRC_PS_ACT_REJECT_GGSN = 30 , // 0x1E / **< Activation rejected by GGSN * /	 
 CIRC_PS_ACT_REJECT = 31 , // 0x1F / **< Activation rejected , unspecified * /	 
 /* failure to Activate a context */	 
 CIRC_PS_SRVOPT_NOT_SUPPORTED = 32 , // 0x20 / **< Service option not supported * /	 
 CIRC_PS_SRVOPT_NOT_SUBSCRIBED = 33 , // 0x21 / **< Requested service option not subscribed * /	 
 CIRC_PS_SRVOPT_TEMP_OUT_OF_ORDER = 34 , // 0x22 / **< Service option temporarily out of order * /	 
 CIRC_PS_NSAPI_ALREADY_USED = 35 , // 0x23 / **< NSAPI already used * /	 
 CIRC_PS_QOS = 37 , // 0x25 / **< QoS not accepted * /	 
 CIRC_PS_NETWORK_FAILURE = 38 , // 0x26 / **< Network failure * /	 
 CIRC_PS_REACTIVATION_REQ = 39 , // 0x27 / **< Reactivation required * /	 
 // Z.S. MT PDP support	 
 /* TFT errors for MT PDP start*/	 
 /* From spec ( 24.301000 / 9.900000 .4.4 ) */	 
 CIRC_PS_ESM_SEMANTIC_ERROR_IN_THE_TFT_OPERATION = 41 , // 0x29 / * SM_CAUSE_SEMANTIC_ERROR_IN_TFT_OPERATION * /	 
 CIRC_PS_ESM_SYNTACTICAL_ERROR_IN_THE_TFT_OPERATION = 42 , // 0x2A / * SM_CAUSE_SYNTACTICAL_ERROR_IN_TFT_OPERATION * /	 
 CIRC_PS_ESM_INVALID_EPS_BEARER_IDENTITY = 43 , // 0x2B / * SM_CAUSE_UNKNOWN_PDP_CONTEXT * /	 
 CIRC_PS_ESM_SEMANTIC_ERRORS_IN_PACKET_FILTER = 44 , // 0x2C / * SM_CAUSE_SEMANTIC_ERRORS_IN_PACKET_FILTER * /	 
 CIRC_PS_ESM_SYNTACTICAL_ERRORS_IN_PACKET_FILTER = 45 , // 0x2D / * SM_CAUSE_SYNTACTICAL_ERRORS_IN_PACKET_FILTER * /	 
 CIRC_PS_ESM_EPS_BEARER_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED = 46 , // 0x2E / * SM_CAUSE_PDP_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED * /	 
 CIRC_PS_ESM_LAST_PDN_DISCONNECTION_NOT_ALLOWED = 49 , // 0x31	 
 CIRC_PS_ESM_PDN_TYPE_IPV4_ONLY_ALLOWED = 50 , // 0x32	 
 CIRC_PS_ESM_PDN_TYPE_IPV6_ONLY_ALLOWED = 51 , // 0x33	 
 CIRC_PS_ESM_PDN_TYPE_SINGLE_IP_ALLOWED = 52 , // 0x34	 
 CIRC_PS_PROTOCOL_ERROR_MIN = 95 , // 0x5F / **< protocol errors - low range , old value , useless now * /	 
 CIRC_PS_PROTOCOL_ERROR_MAX = 111 , // 0x6F / **< protocol errors - high range , old value , useless now * /	 
 /* TFT errors for MT PDP end*/	 
 CIRC_PS_UNSPECIFIED_ERROR = 148 , // 0x94 / **< Unspecified GPRS error * /	 
 CIRC_PS_PDP_AUTHEN_FAILURE =149 , // 0x95 / **< PDP authentication failure * /	 
	 
 /* other GPRS errors */	 
 CIRC_PS_INVALID_MS_CLASS = 150 , // 0x96 / **< Invalid mobile class * /	 
	 
 /* Additional return codes , not specified in TS 27.007000 - start from 200 */	 
 CIRC_PS_INFO_UNAVAILABLE = 200 , // 0xC8 / **< Requested information is unavailable * /	 
	 
 CIRC_PS_ALREADY_PROCESSING = 201 , // 0xC9 / **< The requested command is already being processed , I.e. , this REQ is redundant * /	 
 CIRC_PS_BUSY_WITH_OTHER_JOB = 202 , // 0xCA / **< The CP is busy processing another command so this one can ' t be serviced , and CP will not add the REQ into its queue * /	 
	 
 CIRC_PS_INVALID_PARAMETER = 203 , // 0xCB / **< Generic error - the requested service primitive has invalid parameters * /	 
 CIRC_PS_INVALID_REQ = 204 , // 0xCC / **< Generic error - the requested service primitive can not be handled at current state * /	 
 CIRC_PS_SIM_NOT_READY = 205 , // 0xCD / **< Generic error - the requested service primitive fails because SIM is not ready * /	 
 CIRC_PS_ACCESS_DENIED = 206 , // 0xCE / **< Generic error - the requested service primitive fails because access is denied * /	 
 CIRC_PS_INVALID_CID = 207 , // 0xCF / **< Generic error - the requested Cid is invalid * /	 
 CIRC_PS_TFT_PACKET_ERROR_DEFAULT_PDP = 208 , // 0xD0 / **< Generic error - the TFT is invalid for default MT PDP * /	 
 CIRC_PS_TFT_PACKET_ERROR_NON_DEFAULT_PDP = 209 , // 0xD1 / **< Generic error - the TFT is invalid for NON default MT PDP * /	 
 CIRC_PS_PENDING_SUCCESS = 210 , // 0xD2 / **<LTE MO PDP equest completed successfully * /	 
 CIRC_PS_RPM_REJECT = 880 , // 0x370 / **< Generic error - the RPM manager rejected the request. * /	 
	 
 /**** SM reject cause ( 24.008000 ) also contained in CiPsRc vaule , one to one mapped with sml3_typ.h ****/	 
 CIRC_PS_SM_LLC_OR_SNDCP_FAILURE = 0x19 ,	 
 CIRC_PS_SM_INSUFFIC_RESOURCES = 0x1A ,	 
 CIRC_PS_SM_MISSING_OR_UNKNOWN_APN = 0x1B ,	 
 CIRC_PS_SM_UNKNOWN_PDP_ADDR_OR_TYPE = 0x1C ,	 
 CIRC_PS_SM_USER_AUTH_FAILED = 0x1D ,	 
 CIRC_PS_SM_ACTIV_REJ_BY_GGSN = 0x1E ,	 
 CIRC_PS_SM_ACTIV_REJ_UNSPECIFIED = 0x1F ,	 
 CIRC_PS_SM_SERVICE_OPT_NOT_SUPPORTED = 0x20 ,	 
 CIRC_PS_SM_SERVICE_OPT_NOT_SUBSCRIBED = 0x21 ,	 
 CIRC_PS_SM_SERVICE_OPT_TEMP_OUT_OF_ORDER = 0x22 ,	 
 CIRC_PS_SM_NSAPI_ALREADY_USED = 0x23 ,	 
 CIRC_PS_SM_REGULAR_DEACTIVATION = 0x24 ,	 
 CIRC_PS_SM_QOS_NOT_ACCEPTED = 0x25 ,	 
 CIRC_PS_SM_NETWORK_FAILURE = 0x26 ,	 
 CIRC_PS_SM_REACTIVATION_REQUIRED = 0x27 ,	 
 CIRC_PS_SM_FEATURE_NOT_SUPPORTED = 0x28 , /* Added for 111 -13748 */	 
 CIRC_PS_SM_SEMANTIC_ERROR_IN_TFT_OPERATION = 0x29 ,	 
 CIRC_PS_SM_SYNTACTICAL_ERROR_IN_TFT_OPERATION = 0x2A ,	 
 CIRC_PS_SM_UNKNOWN_PDP_CONTEXT = 0x2B ,	 
 CIRC_PS_SM_SEMANTIC_ERRORS_IN_PACKET_FILTER = 0x2C ,	 
 CIRC_PS_SM_SYNTACTICAL_ERRORS_IN_PACKET_FILTER = 0x2D ,	 
 CIRC_PS_SM_PDP_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED = 0x2E ,	 
 CIRC_PS_SM_PDP_TYPE_IPV4_ONLY_ALLOWED = 0x32 ,	 
 CIRC_PS_SM_PDP_TYPE_IPV6_ONLY_ALLOWED = 0x33 ,	 
 CIRC_PS_SM_SINGLE_ADDRESS_BEARERS_ONLY_ALLOWED = 0x34 ,	 
 CIRC_PS_SM_INVALID_TI_VALUE = 0x51 ,	 
 CIRC_PS_SM_SEMANTICALLY_INCORRECT_MSG = 0x5F ,	 
 CIRC_PS_SM_INVALID_MAND_INFORMATION = 0x60 ,	 
 CIRC_PS_SM_MSG_TYPE_NONEXIST_OR_NOT_IMP = 0x61 ,	 
 CIRC_PS_SM_MSG_TYPE_INCOMPAT_WITH_STATE = 0x62 ,	 
 CIRC_PS_SM_IE_NONEXIST_OR_NOT_IMP = 0x63 ,	 
 CIRC_PS_SM_CONDITIONAL_IE_ERROR = 0x64 ,	 
 CIRC_PS_SM_MSG_INCOMPAT_WITH_STATE = 0x65 ,	 
 CIRC_PS_SM_PROTOCOL_ERROR_UNSPEC = 0x6F ,	 
 /* Added for rel6: APN restriction value incompatible with active PDP context */	 
 CIRC_PS_SM_APN_RESTRICTION = 0x70 , // last SM cause	 
	 
 /**** ESM reject cause also contained in CiPsRc vaule , one to one mapped with sml3_typ.h ****/	 
 // ESM cause , 24.301000 - 9.900000 .4.4	 
 CIRC_PS_ESM_OPERATOR_DETERMINED_BARRING = 0x08 ,	 
 CIRC_PS_ESM_INSUFFICIENT_RESOURCES = 0x1a ,	 
 CIRC_PS_ESM_UNKNOWN_OR_MISSING_APN = 0x1b ,	 
 CIRC_PS_ESM_UNKNOWN_PDN_TYPE = 0x1c ,	 
 CIRC_PS_ESM_USER_AUTHENTICATION_FAILED = 0x1d ,	 
 CIRC_PS_ESM_REQUEST_REJECTED_BY_SERVING_GW_OR_PDN_GW = 0x1e ,	 
 CIRC_PS_ESM_REQUEST_REJECTED_UNSPECIFIED = 0x1f ,	 
 CIRC_PS_ESM_SERVICE_OPTION_NOT_SUPPORTED = 0x20 ,	 
 CIRC_PS_ESM_REQUESTED_SERVICE_OPTION_NOT_SUBSCRIBED = 0x21 ,	 
 CIRC_PS_ESM_SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER = 0x22 ,	 
 CIRC_PS_ESM_PTI_ALREADY_IN_USE = 0x23 ,	 
 CIRC_PS_ESM_REGULAR_DEACTIVATION = 0x24 ,	 
 CIRC_PS_ESM_EPS_QOS_NOT_ACCEPTED = 0x25 ,	 
 CIRC_PS_ESM_NETWORK_FAILURE = 0x26 ,	 
 // CIRC_PS_ESM_SEMANTIC_ERROR_IN_THE_TFT_OPERATION = 0x29 ,	 
 // CIRC_PS_ESM_SYNTACTICAL_ERROR_IN_THE_TFT_OPERATION = 0x2a ,	 
 // CIRC_PS_ESM_INVALID_EPS_BEARER_IDENTITY = 0x2b ,	 
 // CIRC_PS_ESM_SEMANTIC_ERRORS_IN_PACKET_FILTER = 0x2c ,	 
 // CIRC_PS_ESM_SYNTACTICAL_ERRORS_IN_PACKET_FILTER = 0x2d ,	 
 // CIRC_PS_ESM_EPS_BEARER_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED = 0x2e ,	 
 CIRC_PS_ESM_PTI_MISMATCH = 0x2f ,	 
 // CIRC_PS_ESM_LAST_PDN_DISCONNECTION_NOT_ALLOWED = 0x31 ,	 
 // CIRC_PS_ESM_PDN_TYPE_IPV4_ONLY_ALLOWED = 0x32 ,	 
 // CIRC_PS_ESM_PDN_TYPE_IPV6_ONLY_ALLOWED = 0x33 ,	 
 CIRC_PS_ESM_SINGLE_ADDRESS_BEARERS_ONLY_ALLOWED = 0x34 ,	 
 CIRC_PS_ESM_ESM_INFORMATION_NOT_RECEIVED = 0x35 ,	 
 CIRC_PS_ESM_PDN_CONNECTION_DOES_NOT_EXIST = 0x36 ,	 
 CIRC_PS_ESM_MULTIPLE_PDN_CONNECTIONS_FOR_A_GIVEN_APN_NOT_ALLOWED = 0x37 ,	 
 CIRC_PS_ESM_COLLISION_WITH_NETWORK_INITIATED_REQUEST= 0x38 ,	 
 CIRC_PS_ESM_UNSUPPORTED_QCI_VALUE = 0x3b ,	 
 CIRC_PS_ESM_INVALID_PTI_VALUE = 0x51 ,	 
 CIRC_PS_ESM_SEMANTICALLY_INCORRECT_MESSAGE = 0x5f ,	 
 CIRC_PS_ESM_INVALID_MANDATORY_INFORMATION = 0x60 ,	 
 CIRC_PS_ESM_MESSAGE_TYPE_NONEXISTENT_OR_NOT_IMPLEMENTED = 0x61 ,	 
 CIRC_PS_ESM_MESSAGE_TYPE_NOT_COMPATIBLE_WITH_THE_PROTOCOL_STATE = 0x62 ,	 
 CIRC_PS_ESM_INFORMATION_ELEMENT_NONEXISTENT_OR_NOT_IMPLEMENTED = 0x63 ,	 
 CIRC_PS_ESM_CONDITIONAL_IE_ERROR = 0x64 ,	 
 CIRC_PS_ESM_MESSAGE_NOT_COMPATIBLE_WITH_THE_PROTOCOL_STATE = 0x65 ,	 
 CIRC_PS_ESM_PROTOCOL_ERROR_OR_UNSPECIFIED = 0x6f ,	 
 CIRC_PS_ESM_APN_RESTRICTION_VALUE_INCOMPATIBLE_WITH_ACTIVE_EPS_BEARER_CONTEXT = 0x70 ,	 
	 
 /****internal reject cause also contained in CiPsRc vaule , one to one mapped with sml3_typ.h ****/	 
 // internal reject start from 0x0100 , and the cause before 0x0100 is reserved for 3 GPP ;	 
 /** !!!!!! Local cause !!!!!!!!!!*/	 
 CIRC_PS_INTERNAL_LOCAL_CAUSE_BASE = 0x0100 ,	 
 CIRC_PS_ENMERGNECY_BEARER_SERVICE_ALREADY_RUN = 0x0101 , // for emergency bearer only	 
 CIRC_PS_HANDOVER_FLAG = 0x0102 , // IRAT	 
 CIRC_PS_CAUSE_EPS_SERVICE_NOT_AVAILABLE = 0x0103 , // EPS PS service not available ,	 
	 
 CIRC_PS_NOTIFY_REATTACH = 0x0104 ,	 
 CIRC_PS_NOTIFY_DETACH = 0x0105 ,	 
 CIRC_PS_PDN_REQUEST_NEED_RETRY = 0x0106 ,	 
 CIRC_PS_APN_IS_NOT_AVAILABLE = 0x0107 , // APN is missing	 
 CIRC_PS_EMERGENCY_PDN_REQUEST_CONTAINS_APN = 0x0108 , // emergency bearer should not contain APN	 
 CIRC_PS_ATTACH_FOR_EMERGENCY_BEARER_SERVICE = 0x0109 , // emergency attached , but require additional bearer	 
 // ESM_CAUSE_IMS_BLOCK = 0x89 ,	 
	 
 CIRC_PS_PDP_OPERATTION_NOT_ALLOWED = 0x010B , // PDP operation not allowed for some reason	 
 CIRC_PS_PDP_INPUT_PARAM_INVALID = 0x010C ,	 
 CIRC_PS_T3396_RUNNING = 0x010D ,	 
 CIRC_PS_TIMER_OUT_ERROR = 0x010E ,	 
	 
 // Cause for PDP activation request reject in AB side ;	 
 CIRC_PS_NO_FREE_NSAPIS = 0x0150 ,	 
 CIRC_PS_GPRS_SERVICE_NOT_AVAILABLE = 0x0151 ,	 
 CIRC_PS_POWERING_DOWN = 0x0152 ,	 
 CIRC_PS_FDN_FAILURE = 0x0153 ,	 
 CIRC_PS_APN_CHECK_FAILURE = 0x0154 ,	 
	 
	 
 CIRC_PS_OPERATION_REJECT_BY_MM = 0x0200 , // reject by GMM / EMM	 
 CIRC_PS_PDP_REJECT_DSDS = 0x3300 , /**< PDP reject on DSDS */	 
	 
	 
 CIRC_PS_NO_CAUSE_SET = 0x3400 ,	 
	 
 /*!!!! internal cause add here !!!!*/	 
 CIRC_PS_CAUSE_UNKNOWN = 0xFFFF ,	 
 /* This one must always be last in the list! */	 
 CIRC_PS_NUM_RESCODES = 0xFFFF /**< Number of result codes */	 
 } _CiPsRc;

typedef UINT16 CiPsRc ;
//ICAT EXPORTED ENUM 
 typedef enum CIPSPDPTYPE_TAG 
 {	 
 CI_PS_PDP_TYPE_PPP = 0 , /**< PPP */	 
 CI_PS_PDP_TYPE_IP , /**< IPv4 */	 
 CI_PS_PDP_TYPE_IPV6 , /**< IPv6 */	 
 CI_PS_PDP_TYPE_IPV4V6 , /**< IPv4v6 */	 
 CI_PS_PDP_TYPE_X25 , /**< X25 */	 
 CI_PS_PDP_TYPE_OSPIH , /**< OSPIH */	 
 CI_PS_PDP_TYPE_NONIP , /**< Non-IP */	 
	 
 CI_PS_PDP_NUM_TYPES	 
 } _CiPsPdpType;

typedef UINT8 CiPsPdpType ;
//ICAT EXPORTED ENUM 
 typedef enum CIPSACTIONTYPE_TAG 
 { // Z.S. MT PS support	 
 CI_PS_ACT_IND_ACTION = 0 , /**< Indicates network initiated primary PDP context activation */	 
 CI_PS_ACT_SEC_IND_ACTION , /**< Indicates network initiated secondary PDP context activation */	 
 CI_PS_MODIFY_IND_ACTION , /**< Indicates network initiated primary PDP context modification */	 
 CI_PS_MODIFY_SEC_IND_ACTION , /**< Indicates network initiated secondary PDP context modification */	 
 // CI_PS_TFT_PACKET_ERROR_NON_DEFAULT_PDP , / **< Indicates COMM to update the pdp tft packets * /	 
 // CI_PS_TFT_PACKET_ERROR_DEFAULT_PDP , / **< Indicates COMM to release MT default pdp * /	 
 CI_PS_NUMBER_OF_ACTION_TYPES	 
 // CIRC_PS_ACT_IND_ACTION = 0 , / **< Indicates network initiated PDD context activation * /	 
 // CIRC_PS_MODIFY_IND_ACTION , / **< Indicates network initiated PDD context modification * /	 
 // CIRC_PS_NUMBER_OF_ACTION_TYPES	 
 } _CiPsActionType;

//ICAT EXPORTED ENUM 
 typedef enum CIPSPDPMODIFYCHANGEREASON_TAG 
 {	 
 CI_PS_PDP_MODIFY_RESERVED = 0 ,	 
 CI_PS_PDP_MODIFY_TFT = 0x01 ,	 
 CI_PS_PDP_MODIFY_QOS = 0x02 ,	 
 CI_PS_PDP_MODIFY_QOS_AND_TFT = 0x01 + 0x02 ,	 
	 
 CI_PS_PDP_MODIFY_INVALID_REASONS	 
 } _CiPsPdpModifyChangeReason;

typedef UINT8 CiPsPdpModifyChangeReason ;
typedef UINT8 SacPsEventReportMode ;
typedef UINT8 SacPsEventReportBufferMode ;
typedef UINT8 CiPsActionType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPdpAddr_struct 
 {	 
 UINT8 len ; /**< Length of the address field [ CI_PS_PDP_IP_V4_SIZE| CI_PS_PDP_IP_V6_SIZE ] */	 
 UINT8 valData [ 64 +1 ] ; /**< Address field */	 
 } CiPsPdpAddr;

//ICAT EXPORTED ENUM 
 typedef enum CIPSDCOMP_TAG 
 {	 
 CI_PS_DCOMP_OFF = 0 , /**< Off ; this is the default value */	 
 CI_PS_DCOMP_ON , /**< Manufacturer preferred compression */	 
 CI_PS_DCOMP_V42bis , /**< V.42 bis */	 
 CI_PS_DCOMP_V44 , /**< V.44 */	 
	 
 CI_PS_NUM_DCOMPS	 
 } _CiPsDcomp;

typedef UINT8 CiPsDcomp ;
//ICAT EXPORTED ENUM 
 typedef enum CIPSHCOMP_TAG 
 {	 
 CI_PS_HCOMP_OFF=0 , /**< Off ; this is the default value */	 
 CI_PS_HCOMP_TCPIP , /**< TCPIP header compression - RFC 1144 */	 
 CI_PS_HCOMP_IP , /**< IP header compression - RFC 2507 */	 
	 
 CI_PS_NUM_HCOMPS	 
 } _CiPsHcomp;

typedef UINT8 CiPsHcomp ;
typedef UINT8 CiPsIpv4AllocType ;
typedef UINT8 CiPsEmergencyIndType ;
typedef UINT8 CiPsPcscfDiscoveryType ;
typedef UINT8 CiPsImCnSignallingFlagIndType ;
typedef UINT8 CiPsEsmCauseType ;
typedef UINT8 CiPsSmFollowAct ;
typedef UINT8 CiPsIpv4MtuDiscoveryType ;
typedef UINT8 CiPsLocalAddrIndType ;
typedef UINT8 CiPsNonIpMtuDiscoveryType ;
typedef UINT8 CiPsMoPdpActReason ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsID_struct 
 {	 
 UINT8 cid ; /**< PDP Context Identifier , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 UINT8 p_cid ;	 
 UINT8 bearer_id ; /**< PDP Context Identifier , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsID;

//ICAT EXPORTED ENUM 
 typedef enum CiPsPdpAddrType_tag 
 {	 
 CI_PS_PDP_INVALID_ADDR = 0 ,	 
 CI_PS_PDP_IPV4 , // 4 bytes length	 
 CI_PS_PDP_FULL_IPV6 , // 16 bytes length	 
 CI_PS_PDP_IPV6_INTERFACE // 8 bytes length	 
 } CiPsPdpAddrType;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPdpIpAddr_struct 
 {	 
 UINT16 addrType ; // CiPsPdpAddrType , invalid - 0 , ipv4 - 1 , Full ipv6 - 2 , Ipv6 interface - 3 ;	 
 UINT16 subnetLength ; // 0 - invalid	 
 UINT8 valData [ 16 ] ; /**< Address field */	 
 } CiPsPdpIpAddr;

//ICAT EXPORTED ENUM 
 typedef enum CiPsPdpBearType_struct 
 {	 
 CI_PS_INVALID_PDP_TYPE = 0 ,	 
 CI_PS_PRIMARY_PDP = 1 ,	 
 CI_PS_DEFAULT_PDP = 1 ,	 
	 
 CI_PS_SECONDARY_PDP = 2 ,	 
 CI_PS_DEDICATED_PDP = 2 ,	 
	 
 CI_PS_MAX_PDP_TYPE	 
 } _CiPsPdpBearType;

typedef UINT8 CiPsPdpBearType ;
//ICAT EXPORTED ENUM 
 typedef enum CIPSREQTYPE_TAG 
 {	 
 CI_PS_REQ_FOR_NEW_OR_HANDOVER_PDP = 0 , /*0 - PDP context is for new PDP context establishment or for handover from a non-3GPP access network */	 
 CI_PS_REQ_FOR_EMERGENCY_BEARER_SERVICES = 1 , /*1 - PDP context is for emergency bearer services */	 
 CI_PS_REQ_FOR_NEW_PDP = 2 , /*2 - PDP context is for new PDP context establishment */	 
 CI_PS_REQ_FOR_HANDOVER = 3 , /*3 - PDP context is for handover from a non-3GPP access network */	 
 CI_PS_REQ_FOR_HANDOVER_EMERGENCY = 4 , /*4 - PDP context is for handover of emergency bearer services from a non-3GPP access network */	 
	 
 CI_PS_REQ_FOR_MMS = 10 , /*10 - PDP context is for MMS ( internal use only ) */	 
	 
 CI_PS_NUM_REQ_TYPE	 
 } _CiPsReqType;

typedef UINT8 CiPsReqType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPdpCtx_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiPsPdpType type ; /**< PDP type \sa CiPsPdpType */	 
 UINT8 bearer_id ; /**< PDP Context Identifier , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiPsPdpBearType pdpBearType ; // 0 - invalid , 1 - primary / default PDP , 2 - dedicated / secondary PDP	 
 UINT8 p_cid ;	 
	 
 /* # Start Contiguous Code Section # */	 
 CiBoolean apnPresent ; /**< Flag indicating that the APN is present ( optional field ) \sa CCI API Ref Manual*/	 
 CiString apn ; /**< APN , length range [ CI_PS_APN_MIN_SIZE - CI_PS_APN_MAX_SIZE ] . \sa CCI API Ref Manual */	 
 // CiBoolean addrPresent ; / **< Flag indicating that the address is present ( optional field ) \sa CCI API Ref Manual * /	 
 CiPsPdpIpAddr ipv4Addr ; /**< PDP address \sa CiPsPdpAddr_struct */	 
 CiPsPdpIpAddr ipv6Addr ;	 
 CiBoolean dcompPresent ; /**< Flag indicating that data compression field is present \sa CCI API Ref Manual */	 
 CiPsDcomp dcomp ; /**< PDP data compression , only applicable to SNDCP , ignore it for UMTS \sa CiPsDcomp */	 
 CiBoolean hcompPresent ; /**< Flag indicating that header compression field is present \sa CCI API Ref Manual */	 
 CiPsHcomp hcomp ; /**< PDP header compression \sa CiPsHcomp */	 
 CiBoolean pdParasPresent ; /**< Flag indicating that the pdParas is present ( optional field ) \sa CCI API Ref Manual*/	 
 CiString pdParas ; /**< PDP specific parameters \sa CCI API Ref Manual */	 
	 
 CiBoolean ipAddrAllocPresent ;	 
 CiPsIpv4AllocType ipAddrAlloc ;	 
	 
 CiBoolean reqTypePresent ; /**< Flag indicating that request type field is present \sa CiPsReqType */	 
 CiPsReqType reqType ; /**Type of PDP context activation request , refer to TS27.007 c80*/	 
 CiBoolean pCscfDiscoveryPresent ;	 
 CiPsPcscfDiscoveryType pCscfDiscovery ;	 
 CiBoolean imCnSignallingFlagIndPresent ;	 
 CiPsImCnSignallingFlagIndType imCnSignallingFlagInd ; /**IM_CN_Signalling_Flag_Ind*/	 
	 
 CiBoolean esmCausePresent ;	 
 CiPsEsmCauseType esmCause ;	 
 CiPsSmFollowAct smFlwAct ; // SM following action	 
	 
 // #if defined ( DS3_CAT1 )	 
 CiBoolean nslpiPresent ;	 
 UINT8 nslpi ; /**NSLPI*/	 
 CiBoolean securePcoPresent ;	 
 UINT8 securePco ; /**securePCO*/	 
	 
 CiBoolean ipv4MtudiscoveryPresent ;	 
 CiPsIpv4MtuDiscoveryType ipv4Mtudiscovery ; /**IPv4_MTU_discovery*/	 
 CiBoolean localAddrIndPresent ;	 
 CiPsLocalAddrIndType localAddrInd ; /**Local_Addr_ind*/	 
 CiBoolean nonIpMtuDiscoveryPresent ;	 
 CiPsNonIpMtuDiscoveryType nonIpMtuDiscovery ; /**Non-IP_MTU_discovery*/	 
 // #endif	 
 } CiPsPdpCtx;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPdpCtxInfo_struct 
 {	 
 CiBoolean actState ; /**< Activation state ; TRUE: activate \sa CCI API Ref Manual */	 
 CiPsPdpCtx pdpCtx ; /**< PDP context parameters \sa CiPsPdpCtx_struct */	 
 } CiPsPdpCtxInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPdpCtxLoopback_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiPsPdpType type ; /**< PDP type \sa CiPsPdpType */	 
 } CiPsPdpCtxLoopback;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPdpCtxInfoLoopback_struct 
 {	 
 CiBoolean actState ; /**< Activation state ; TRUE: activate \sa CCI API Ref Manual */	 
 CiPsPdpCtxLoopback pdpCtx ; /**< PDP context parameters \sa CiPsPdpCtx_struct */	 
 } CiPsPdpCtxInfoLoopback;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPdpCtxCap_struct 
 {	 
 CiNumericRange cids ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] \sa CCI API Ref Manual */	 
 CiPsPdpType type ; /**< PDP type \sa CiPsPdpType */	 
 CiBitRange bitsDcomp ; /**< Data compression capability , represented as bit mask. Each bit represents a value in CiPsDcomp. \sa CiPsDcomp */	 
 /* each bit represents a capability in CiPsDcomp ,	 
 e.g. ( bitsDcomp& ( 1 << CI_PS_HCOMP_OFF ) ) !=0 means	 
 CI_PS_DCOMP_OFF is supported ,	 
 ( bitsDcomp& ( 1 <<CI_PS_DCOMP_ON ) ) !=0 means	 
 CI_PS_DCOMP_ON is supported */	 
 CiBitRange bitsHcomp ; /**< Header compression capability , represented as bit mask. Each bit represents a value in CiPsHcomp. \sa CiPsHcomp*/	 
	 
 /* TBD , not sure <pd1> to <pdn> is going to be presented */	 
 } CiPsPdpCtxCap;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPdpCtxCaps_struct 
 {	 
 UINT8 size ; /**< Number of capability profiles ; currently only one profile is supported */	 
 CiPsPdpCtxCap caps [ 1 ] ; /**< PDP context capabilities \sa CiPsPdpCtxCap_struct*/	 
 } CiPsPdpCtxCaps;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPdpCtxActState_struct 
 {	 
 UINT8 cid ; /**< PDP context identification , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiBoolean activated ; /**< TRUE: activated ; FALSE: deactivated \sa CCI API Ref Manual */	 
 } CiPsPdpCtxActState;

typedef CiPsPdpCtxActState *CiPsPdpCtxActStateListPtr ;
//ICAT EXPORTED ENUM 
 typedef enum CIPSL2P_TAG 
 {	 
 CI_PS_L2P_NONE=0 , /**< Not PPP */	 
 CI_PS_L2P_PPP , /**< PPP */	 
	 
 CI_PS_NUM_L2PS	 
 } _CiPsL2P;

typedef UINT8 CiPsL2P ;
//ICAT EXPORTED ENUM 
 typedef enum CIPSGSMGPRSCLASS_TAG 
 {	 
 CI_PS_GSMGPRS_CLASS_A = 0 , /**< Class A */	 
 CI_PS_GSMGPRS_CLASS_B , /**< Class B */	 
 CI_PS_GSMGPRS_CLASS_CS , /**< Class C , GPRS only */	 
 CI_PS_GSMGPRS_CLASS_CC , /**< Class C , circuit switch only */	 
	 
 CI_PS_GSMGPRS_NUM_CLASSES	 
 } _CiPsGsmGprsClass;

typedef UINT8 CiPsGsmGprsClass ;
//ICAT EXPORTED ENUM 
 /** \brief Network registration configuration flag values */ 
 /** \remarks Common Data Section */ 
 typedef enum CIPSNWREGINDFLAG_TAG 
 {	 
 CI_PS_NW_REG_IND_DISABLE = 0 , /**< Disable network registration status reports , n = 0 */	 
 CI_PS_NW_REG_IND_ENABLE_STA_ONLY , /**< Enable network registration status reports , n = 1 */	 
 CI_PS_NW_REG_IND_ENABLE_DETAIL , /**< Enable detailed network registration status reports , n= 2 */	 
 CI_PS_NW_REG_IND_ENABLE_MORE_DETAIL , /**< Enable more detailed network registration status reports , n = 3 */	 
 CI_PS_NW_REG_IND_ENABLE_PSM , /**< Enable more detailed network registration status reports , n = 4 */	 
 CI_PS_NW_REG_IND_ENABLE_PSM_DETAIL , /**< Enable more detailed network registration status reports , n = 5 */	 
	 
 CI_PS_NW_REG_IND_ENABLE_NUM	 
	 
 } _CiPsNwRegIndFlag;

typedef UINT8 CiPsNwRegIndFlag ;
typedef UINT8 CiPs4GNwRegIndFlag ;
//ICAT EXPORTED ENUM 
 typedef enum CIPSNWREGSTATUS_TAG 
 {	 
 CI_PS_NW_REG_STA_NOT_REGED = 0 , /**< Not registered and not searching */	 
 CI_PS_NW_REG_STA_REG_HPLMN , /**< Registered on home PLMN */	 
 CI_PS_NW_REG_STA_TRYING , /**< Not registered , but cellular subsystem is searching for a PLMN to register to */	 
 CI_PS_NW_REG_STA_REG_DENIED , /**< Registration denied */	 
 CI_PS_NW_REG_STA_UNKNOWN , /**< Unknown */	 
 CI_PS_NW_REG_STA_REG_ROAMING , /**< Registered on visited PLMN */	 
 CI_PS_NW_REG_STA_SMS_ONLY_HOME , /**< registered for " SMS only " , home network ( applicable only when <AcT> indicates E-UTRAN ) */	 
 CI_PS_NW_REG_STA_SMS_ONLY_ROAMING , /**< registered for " SMS only " , roaming ( applicable only when <AcT> indicates E-UTRAN ) */	 
 CI_PS_NW_REG_STA_EMERGENCY_ONLY_NOT_USED , /**< attached for emergency bearer services only ( see NOTE 2 ) ( not applicable ) */	 
 CI_PS_NW_REG_STA_CSFB_NOT_PREFERRED_HOME , /**<registered for " CSFB not preferred " , home network ( applicable only when <AcT> indicates E-UTRAN ) */	 
 CI_PS_NW_REG_STA_CSFB_NOT_PREFERRED_ROAMING , /**<registered for " CSFB not preferred " , roaming ( applicable only when <AcT> indicates E-UTRAN ) */	 
 CI_PS_NW_REG_STA_REG_EMERGENCY , /**< attached for emergency bearer services only*/	 
	 
 CI_PS_NW_REG_STA_REG_DENIED_IN_ROAMING , /**< registeration denied in roaming , only used for SSG project by now*/	 
 CI_PS_NW_REG_STA_SYNC_DONE_IN_LTE_ROAMING , /**< sync done in LTE roaming network , only used for SSG project by now*/	 
	 
 CI_PS_NW_REG_STA_ECALL_INACTIVE , /**< eCall only when camp on LTE for eCall over IMS */	 
	 
 CI_PS_NUM_REGSTATUS /**< Number of status values defined */	 
 } _CiPsNwRegStatus;

typedef UINT8 CiPsNwRegStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CIPS_ACT_TECH_MODE 
 {	 
 CI_PS_ACT_GSM = 0 , /**< GSM */	 
 CI_PS_ACT_GSM_COMPACT , /**< Not supported */	 
 CI_PS_ACT_UTRAN , /**< UTRAN */	 
	 
 CI_PS_ACT_GSM_EGPRS , /**< GSM w / EGPRS */	 
 CI_PS_ACT_UTRAN_HSDPA , /**< UTRAN w / HSDPA */	 
 CI_PS_ACT_UTRAN_HSUPA , /**< UTRAN w / HSUPA */	 
 CI_PS_ACT_UTRAN_HSPA , /**< UTRAN w / HSDPA and HSUPA */	 
 CI_PS_ACT_EUTRAN , /**< E-UTRAN */	 
	 
 CI_PS_ACT_UTRAN_HSPA_PLUS , /**< UTRAN w / HSPA+ */	 
 CI_PS_ACT_EUTRAN_PLUS , /**< E-UTRAN CA*/	 
 /* Added by taow 20190708 CQ00115423 , begin */	 
 CI_PS_ACT_UTRAN_DC_HSPA , /**< DC-HSPA*/	 
 /* Added by taow 20190708 CQ00115423 , end */	 
	 
 CI_PS_NUM_ACT	 
 } _CiPsAccTechMode;

typedef UINT8 CiPsAccTechMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIPS_CAUSE_TYPE {	 
 CI_PS_CAUSE_TYPE_PS = 0 , /**< Indicates that <reject_cause> contains a GMM / EMM cause value , see 3 GPP TS 24.008000 [ 8 ] Annex G.*/	 
 CI_PS_CAUSE_TYPE_MANUFACTURER , /**< Indicates that <reject_cause> contains a manufacturer specific cause */	 
 CI_PS_CAUSE_NONE ,	 
 CI_PS_NUM_CAUSE_TYPE	 
 } _CiPsCauseType;

typedef UINT8 CiPsCauseType ;
//ICAT EXPORTED ENUM 
 typedef enum CIPS_NETOP_DIGIT_MNC {	 
 CIPS_NETOP_TWO_DIGIT_MNC = 2 , /*2 digit */	 
 CIPS_NETOP_THREE_DIGIT_MNC , /*3 digit */	 
 /* This one must always be last in the list! */	 
 CIPS_NUM_NETOP_DIGIT_MNC	 
 } _CiPsNetOpDigitMnc;

typedef UINT8 CiPsNetOpDigitMnc ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsNetworkId_struct {	 
 UINT16 CountryCode ; /**< 3 -digit country code */	 
 UINT16 NetworkCode ; /**< 3 -digit network code */	 
	 
 CiPsNetOpDigitMnc MncDigit ; /**< MncDigit \sa CiPsNetOpDigitMnc */	 
 } CiPsNetworkId;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsNwRegInfo_struct 
 {	 
 CiPsNwRegStatus status ; /**< Network registration status \sa CiPsNwRegStatus */	 
	 
 CiBoolean lacPresent ; /**< Indicates if LAC and cell ID are present \sa CCI API Ref Manual */	 
 UINT16 lac ; /**< Location area code */	 
 UINT32 cellId ; /**< Cell ID */	 
 CiPsAccTechMode act ; /**< Network access technology ( GSM , UTRAN , LTE etc. ) \sa CiPsAccTechMode */	 
 UINT8 rac ; /**<one byte routing area code> */	 
	 
 CiBoolean causePresent ; /**< Indicates if causeType and rejectCause are present> **/	 
 CiPsCauseType causeType ; /**<cause_type>: integer type ; indicates the type of <reject_cause>**/	 
 UINT32 rejectCause ; /**<reject_cause>: integer type ; contains the cause of the failed registration **/	 
 /* add by perse 1032018 add +CREG / +CGREG / +CEREG indication content with rplmn CQ00117472 , begin */	 
 // #if defined ( CRANE_Z1 )	 
 CiPsNetworkId rplmnInfo ; /**reprot rplmn information*/	 
 // #endif	 
 /* add by perse 1032018 add +CREG / +CGREG / +CEREG indication content with rplmn CQ00117472 , end */	 
 } CiPsNwRegInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiPs4GNwRegInfo_struct 
 {	 
 CiPsNwRegStatus status ; /**< Network registration status. \sa CiPsNwRegStatus */	 
	 
 CiBoolean tacPresent ; /**< Indicates if LAC and Cell ID are present. \sa CCI API Ref Manual */	 
 UINT16 tac ; /**< String type ; two byte tracking area code in hexadecimal format ( e.g. " 0 C3 " equals 195 in decimal ) */	 
 UINT32 cellId ; /**< Cell ID */	 
 CiPsAccTechMode act ; /**< Network access technology ( GSM , UTRAN , LTE etc. ) \sa CiPsAccTechMode */	 
	 
 CiBoolean causePresent ; /**< Indicates if causeType and rejectCause are present. >**/	 
 CiPsCauseType causeType ; /**<cause_type>: integer type ; indicates the type of <reject_cause>**/	 
 UINT32 rejectCause ; /**<reject_cause>: integer type ; contains the cause of the failed registration.**/	 
	 
 // #if defined ( DS3_CAT1 )	 
 CiBoolean activeTimePresent ; /**< Indicates if Active Time is present. >**/	 
 UINT8 activeTime ; /**< string type , one byte in an 8 bit format , indicates the Active Timer value T3324 **/	 
	 
 CiBoolean periodicTauPresent ; /**< Indicates if Periodic TAU is prenset. >**/	 
 UINT8 periodicTau ; /**< string type , one byte in an 8 bit format , indicates the extended periodic TAU value T3412 **/	 
 // #endif	 
	 
 /* add by xwzhou for CQ67291 on 8052014 , begin */	 
 CiBoolean volteAvailable ;	 
 CiBoolean imsEmergencyAvailable ;	 
 /* add by xwzhou for CQ67291 on 8052014 , end */	 
 /* add by perse 1032018 add +CREG / +CGREG / +CEREG indication content with rplmn CQ00117472 , begin */	 
 // #if defined ( CRANE_Z1 )	 
 CiPsNetworkId rplmnInfo ; /**reprot rplmn information*/	 
 // #endif	 
 /* add by perse 1032018 add +CREG / +CGREG / +CEREG indication content with rplmn CQ00117472 , end */	 
 } CiPs4GNwRegInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIPSQOSRELIABILITYCLASS 
 {	 
 CI_PS_QOS_RELIABILITY_CLASS_SUBSCRIBED = 0 , /**< Subscribed reliability class */	 
 CI_PS_QOS_RELIABILITY_CLASS_1 , /**< Acknowledged GTP , LLC , and RLC ; protected data */	 
 CI_PS_QOS_RELIABILITY_CLASS_2 , /**< Unacknowledged GTP ; acknowledged LLC and RLC , Protected data */	 
 CI_PS_QOS_RELIABILITY_CLASS_3 , /**< Unacknowledged GTP and LLC ; acknowledged RLC , Protected data */	 
 CI_PS_QOS_RELIABILITY_CLASS_4 , /**< Unacknowledged GTP , LLC , and RLC , protected data */	 
 CI_PS_QOS_RELIABILITY_CLASS_5 , /**< Unacknowledged GTP , LLC , and RLC , unprotected data */	 
	 
 CI_PS_QOS_NUM_RELIABILITY_CLASSES	 
 } _CiPsQosReliabilityClass;

typedef UINT8 CiPsQosReliabilityClass ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsQosProfile_struct 
 {	 
 UINT8 precedence ; /**< Precedence class */	 
 UINT8 delay ; /**< Delay class */	 
 UINT8 reliability ; /**< Reliability class */	 
 UINT8 peak ; /**< Peak throughput */	 
 UINT8 mean ; /**< Mean throughput */	 
 } CiPsQosProfile;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsSecPdpCtx_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier */	 
 UINT8 p_cid ; /**< Primary PDP context identifier */	 
 UINT8 bearer_id ; /**< PDP Context Identifier , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiBoolean dcompPresent ; /**< TRUE if present \sa CCI API Ref Manual */	 
 CiBoolean hcompPresent ; /**< TRUE if present \sa CCI API Ref Manual */	 
 CiPsDcomp dcomp ; /**< PDP data compression , only applicable to SNDCP , ignore it for UMTS \sa CiPsDcomp */	 
 CiPsHcomp hcomp ; /**< PDP header compression \sa CiPsHcomp */	 
 CiBoolean imCnSigFlagPresent ;	 
 CiPsImCnSignallingFlagIndType imCnSigFlag ;	 
 } CiPsSecPdpCtx;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsSecPdpCtxInfo_struct 
 {	 
 CiBoolean actState ; /**< Activation state \sa CCI API Ref Manual */	 
 CiPsSecPdpCtx secPdpCtx ; /**< Secondary PDP context information \sa CiPsSecPdpCtx_struct */	 
 } CiPsSecPdpCtxInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIPS3GQOSTYPE_TAG 
 {	 
 CI_PS_3G_QOSTYPE_MIN = 0 , /**< Minimum QoS */	 
 CI_PS_3G_QOSTYPE_REQ , /**< Requested QoS */	 
 CI_PS_3G_QOSTYPE_NEG , /**< Negotiated QoS */	 
	 
 CI_PS_3G_QOSTYPE_NUMTYPES	 
 } _CiPs3GQosType;

typedef UINT8 CiPs3GQosType ;
//ICAT EXPORTED ENUM 
 typedef enum CIPS3GTRAFFICCLASS_TAG 
 {	 
 CI_PS_3G_TRAFFIC_CLASS_CONVERSATIONAL = 0 , /**< Conversational */	 
 CI_PS_3G_TRAFFIC_CLASS_STREAMING , /**< Streaming */	 
 CI_PS_3G_TRAFFIC_CLASS_INTERACTIVE , /**< Interactive */	 
 CI_PS_3G_TRAFFIC_CLASS_BACKGROUND , /**< Background */	 
 CI_PS_3G_TRAFFIC_CLASS_SUBSCRIBED , /**< Subscribed value */	 
	 
 CI_PS_3G_TRAFFIC_CLASS_NUMCLASSES	 
 } _CiPs3GTrafficClass;

typedef UINT8 CiPs3GTrafficClass ;
//ICAT EXPORTED ENUM 
 typedef enum CIPS3GDLVORDER_TAG 
 {	 
 CI_PS_3G_DLV_ORDER_NO = 0 , /**< Without delivery order ( no ) */	 
 CI_PS_3G_DLV_ORDER_YES , /**< With delivery order ( yes ) */	 
 CI_PS_3G_DLV_ORDER_SUBSCRIBED , /**< Subscribed value */	 
	 
 CI_PS_3G_NUM_DLV_ORDER	 
 } _CiPs3GDlvOrder;

typedef UINT8 CiPs3GDlvOrder ;
//ICAT EXPORTED ENUM 
 typedef enum CIPS3GDLVERRORSDU_TAG 
 {	 
 CI_PS_3G_DLV_ERROR_SDU_NO = 0 , /**< Erroneous SDUs are not delivered ( no ) */	 
 CI_PS_3G_DLV_ERROR_SDU_YES , /**< Erroneous SDUs are delivered ( yes ) */	 
 CI_PS_3G_DLV_ERROR_SDU_NODETECT , /**< No detect ( ' - ' ) */	 
 CI_PS_3G_DLV_ERROR_SDU_SUBSCRIBED , /**< Subscribed value */	 
	 
 CI_PS_3G_NUM_DLV_ERROR_SDU	 
 } _CiPs3GDlvErrorSdu;

typedef UINT8 CiPs3GDlvErrorSdu ;
//ICAT EXPORTED ENUM 
 typedef enum CIPS3GRESIDUALBER_TAG 
 {	 
 CI_PS_3G_RESIDUAL_BER_SUBSCRIBED = 0 , /**< Subscribed value */	 
 CI_PS_3G_RESIDUAL_BER_5EM2 , /**< 5 * 10 ^-2 */	 
 CI_PS_3G_RESIDUAL_BER_1EM2 , /**< 1 * 10 ^-2 */	 
 CI_PS_3G_RESIDUAL_BER_5EM3 , /**< 5 * 10 ^-3 */	 
 CI_PS_3G_RESIDUAL_BER_4EM3 , /**< 4 * 10 ^-3 */	 
 CI_PS_3G_RESIDUAL_BER_1EM3 , /**< 1 * 10 ^-3 */	 
 CI_PS_3G_RESIDUAL_BER_1EM4 , /**< 1 * 10 ^-4 */	 
 CI_PS_3G_RESIDUAL_BER_1EM5 , /**< 1 * 10 ^-5 */	 
 CI_PS_3G_RESIDUAL_BER_1EM6 , /**< 1 * 10 ^-6 */	 
 CI_PS_3G_RESIDUAL_BER_6EM8 , /**< 6 * 10 ^-8 */	 
	 
 CI_PS_3G_NUM_RESIDUAL_BER	 
 } _CiPs3GResidualBer;

typedef UINT8 CiPs3GResidualBer ;
//ICAT EXPORTED ENUM 
 typedef enum CIPS3GSDUERRORRATIO_TAG 
 {	 
 CI_PS_3G_SDU_ERROR_RATIO_SUBSCRIBED = 0 , /**< Subscribed value */	 
 CI_PS_3G_SDU_ERROR_RATIO_1EM2 , /**< 1 * 10 ^-2 */	 
 CI_PS_3G_SDU_ERROR_RATIO_7EM3 , /**< 7 * 10 ^-3 */	 
 CI_PS_3G_SDU_ERROR_RATIO_1EM3 , /**< 1 * 10 ^-3 */	 
 CI_PS_3G_SDU_ERROR_RATIO_1EM4 , /**< 1 * 10 ^-4 */	 
 CI_PS_3G_SDU_ERROR_RATIO_1EM5 , /**< 1 * 10 ^-5 */	 
 CI_PS_3G_SDU_ERROR_RATIO_1EM6 , /**< 1 * 10 ^-6 */	 
 CI_PS_3G_SDU_ERROR_RATIO_1EM1 , /**< 1 * 10 ^-1 */	 
	 
 CI_PS_3G_NUM_SDU_ERROR_RATIOS	 
 } _CiPs3GSduErrorRatio;

typedef UINT8 CiPs3GSduErrorRatio ;
//ICAT EXPORTED ENUM 
 typedef enum CIPS3GTRAFFICPRIORITY_TAG 
 {	 
 CI_PS_3G_SDU_TRAFFIC_PRIORITY_SUBSCRIBED = 0 , /**< Subscribed value */	 
 CI_PS_3G_SDU_TRAFFIC_PRIORITY_LEVEL_1 , /**< Priority Level 1 */	 
 CI_PS_3G_SDU_TRAFFIC_PRIORITY_LEVEL_2 , /**< Priority Level 2 */	 
 CI_PS_3G_SDU_TRAFFIC_PRIORITY_LEVEL_3 , /**< Priority Level 3 */	 
	 
 CI_PS_3G_NUM_TRAFFIC_PRIORITIES	 
 } _CiPs3GTrafficPriority;

typedef UINT8 CiPs3GTrafficPriority ;
typedef CiPsQosProfile CiPs25GQosProfile ;
//ICAT EXPORTED ENUM 
 typedef enum CIPSISEXTENSION_TAG 
 {	 
 CI_PS_3G_MAX_BIT_RATE_FOR_DL = 0 , /**< Maximum bit rate for DL */	 
 CI_PS_3G_GUARNTEED_BIT_RATE_FOR_DL , /**< Maximum guaranteed bit rate for DL */	 
 CI_PS_3G_MAX_BIT_RATE_FOR_UL , /**< Maximum bit rate for UL */	 
 CI_PS_3G_GUARNTEED_BIT_RATE_FOR_UL , /**< Maximum guaranteed bit rate for UL */	 
 CI_PS_3G_NUM_EXTENTION_IND = 0x7FFFFFFF	 
 } _CiPsIsExtensionType;

typedef CiBitRange CiPsIsExtensionType ;
//ICAT EXPORTED ENUM 
 typedef enum CIPS_SOURCE_STATI_DESC_TAG 
 {	 
 CI_PS_SOURCE_STAT_DESC_UNKNOWN = 0 , /**< Unknown */	 
 CI_PS_SOURCE_STAT_DESC_SPEECH , /**< Speech */	 
 CI_PS_SOURCE_STAT_DESC_NUM = 0x7F	 
 } _CiPsSourceStatisticDescriptorType;

typedef UINT8 CiPsSourceStatisticDescriptorType ;
//ICAT EXPORTED ENUM 
 typedef enum CIPS_SIGNALLING_IND_TAG 
 {	 
 CI_PS_NOT_OPTIMIZED_FOR_SIGNALLING = 0 , /**< Not optimized for signaling traffic */	 
 CI_PS_OPTIMIZED_FOR_SIGNALLING , /**< Optimized for signaling traffic */	 
 CI_PS_SIGNALLING_IND_NUM = 0x7F	 
 } _CiPsSignallingIndicationType;

typedef UINT8 CiPsSignallingIndicationType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPs3GQosProfile_struct 
 {	 
 CiPs3GTrafficClass trafficClass ; /**< Traffic class \sa CiPs3GTrafficClass */	 
 CiPs3GDlvOrder deliveryOrder ; /**< Delivery order \sa CiPs3GDlvOrder */	 
 CiPs3GDlvErrorSdu deliveryOfErrSdu ; /**< Delivery of erroneous SDUs \sa CiPs3GDlvErrorSdu */	 
 CiPs3GResidualBer resBER ; /**< Residual bit error rate \sa CiPs3GResidualBer */	 
 CiPs3GSduErrorRatio sduErrRatio ; /**< SDU error ratio \sa CiPs3GSduErrorRatio */	 
 CiPs3GTrafficPriority thPriority ; /**< Traffic handling priority ( interactive class only ) \sa CiPs3GTrafficPriority */	 
	 
 UINT8 transDelay ; /**< Transfer delay ( conversational / streaming classes only ) */	 
 UINT8 maxSduSize ; /**< Max SDU size */	 
 UINT16 maxULRate ; /**< Max bit rate , uplink */	 
 UINT16 maxDLRate ; /**< Max bit rate , downlink */	 
 UINT16 guaranteedULRate ; /**< Guaranteed bit rate , uplink */	 
 UINT16 guaranteedDLRate ; /**< Guaranteed bit rate , downlink */	 
 CiPsIsExtensionType IsExtension ; /**< Bit mask indicating if the parameters maxDLRate and guaranteedDLRate are encoded as	 
 extension bytes */	 
 CiPsSourceStatisticDescriptorType SourceStatisticDescriptor ; /**< Specifies characteristics of the source of submitted SDUs */	 
 CiPsSignallingIndicationType SignallingIndication ; /**< Indicates the signaling nature of the submitted SDUs. */	 
	 
 } CiPs3GQosProfile;

typedef CiPsPdpAddr CiPsPdpAddrMask ;
//ICAT EXPORTED ENUM 
 typedef enum CIPS_TFT_DIRECTION_IND_TAG 
 {	 
 CI_PS_TFT_DIRECTION_PRE_R7 = 0 ,	 
 CI_PS_TFT_DIRECTION_UPLINK ,	 
 CI_PS_TFT_DIRECTION_DOWNLINK ,	 
 CI_PS_TFT_DIRECTION_BI_DIRECTIONAL ,	 
 CI_PS_NUM_TFT_DIR	 
 } _CiPsTftDirectionIndicationType;

typedef UINT8 CiPsTftDirectionIndicationType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsTftFilter_struct 
 {	 
 UINT8 cid ; /**< PDP Context Identifier , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 UINT8 pfId ; /**< Packet filter identifier */	 
 UINT8 epIndex ; /**< Evaluation precedence index */	 
 UINT8 pIdNextHdr ; /**< Protocol number ( ipv4 ) / next header ( ipv6 ) */	 
 CiBoolean pIdNextHdrPresent ; /**< TRUE: if present \sa CCI API Ref Manual */ // Michal	 
 UINT8 tosTc ; /**< Type of service / traffic class */	 
 CiBoolean tosPresent ; /**< TRUE: if present \sa CCI API Ref Manual */ // Michal	 
 UINT8 tosTcMask ; /**< Type of service / traffic class mask */	 
 CiNumericRange dstPortRange ; /**< Destination port range \sa CCI API Ref Manual */	 
 CiBoolean dstPortRangePresent ; /**< TRUE: if present \sa CCI API Ref Manual */ // Michal	 
 CiNumericRange srcPortRange ; /**< Source port range \sa CCI API Ref Manual */	 
 CiBoolean srcPortRangePresent ; /**< TRUE: if present \sa CCI API Ref Manual */ // Michal	 
	 
 UINT32 ipSecSPI ; /**< IPSec security parameter index */	 
 CiBoolean ipSecSPIPresent ; /**< TRUE: if present \sa CCI API Ref Manual */ // Michal	 
 UINT32 flowLabel ; /**< Flow label */	 
 CiBoolean flowLabelPresent ; /**< TRUE: if present \sa CCI API Ref Manual */ // Michal	 
 CiPsPdpIpAddr remoteAddrAndMask ; /**< remote address and subnet mask */ // the netmask infor store in this struct.	 
 // CiPsPdpAddrMask srcAddrMask ; / **< Source address mask - subnet mask \sa CiPsPdpAddrMask * /	 
 CiPsTftDirectionIndicationType direction ; /**< specifies the transmission direction in which the packet filter shall be applied */	 
 UINT8 nwpfId ; /**< NW Packet filter identifier */	 
	 
 CiPsPdpIpAddr localAddrAndMask ; /**< local address and subnet mask , seems useless */	 
 } CiPsTftFilter;

//ICAT EXPORTED ENUM 
 typedef enum CIPSTFTOPCODE_TAG 
 {	 
 CI_PS_TFT_OPCODE_SPARE = 0 ,	 
 CI_PS_TFT_OPCODE_CREATE_NEW ,	 
 CI_PS_TFT_OPCODE_DELETE_EXISTING ,	 
 CI_PS_TFT_OPCODE_ADD_PACKET_FILTERS ,	 
 CI_PS_TFT_OPCODE_REPLACE_PACKET_FILTERS ,	 
 CI_PS_TFT_OPCODE_DELETE_PACKET_FILTERS ,	 
 CI_PS_TFT_OPCODE_NO_TFT_OPERATION ,	 
 CI_PS_NUMBER_OF_TFT_OP_CODES	 
 } _CiPsTftOpCode;

typedef UINT8 CiPsTftOpCode ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsIndicatedPdpCtx_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiPsPdpType type ; /**< PDP type \sa CiPsPdpType */	 
 CiPsPdpBearType pdpBearType ; /**Primary PDP , or secondary PDP */	 
 UINT8 p_cid ; /**only valid , when secondary PDP*/	 
	 
 // CiBoolean addrPresent ; / **< TRUE: if present \sa CCI API Ref Manual * /	 
 // CiPsPdpAddr addr ; / **< PDP address string \sa CiPsPdpAddr_struct * /	 
 CiPsPdpIpAddr ipv4Addr ; /**if not vaiable , addrType = CI_PS_PDP_INVALID_ADDR*/	 
 CiPsPdpIpAddr ipv6Addr ; /**if not vaiable , addrType = CI_PS_PDP_INVALID_ADDR*/	 
 } CiPsIndicatedPdpCtx;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsQosCap_struct 
 {	 
 CiPsPdpType type ; /**< PDP type \sa CiPsPdpType */	 
 CiNumericRange precedenceCap ; /**< Precedence class [ 0 -4 ] \sa CCI API Ref Manual */	 
 CiNumericRange delayCap ; /**< Delay class [ 0 -3 ] \sa CCI API Ref Manual */	 
 CiNumericRange reliabilityCap ; /**< Reliability class [ 0 -5 ] \sa CCI API Ref Manual */	 
 CiNumericRange peakCap ; /**< Peak throughput [ 0 -9 ] \sa CCI API Ref Manual */	 
 CiNumericList meanCap ; /**< Mean throughput [ 0 -18 , 31 ] \sa CCI API Ref Manual */	 
 } CiPsQosCap;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsQosCaps_struct 
 {	 
 UINT8 size ; /**< Number of defined PDP contexts */	 
 CiPsQosCap caps [ 1 ] ; /**< QoS capabilities , optional if return code is not CIRC_PS_SUCCESS \sa CiPsQosCap_struc */	 
 } CiPsQosCaps;

typedef CiPsQosCap CiPs25GQosCap ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPs3GQosCap_struct 
 {	 
 CiPsPdpType type ; /**< PDP type \sa CiPsPdpType */	 
 CiNumericRange trafficClass ; /**< Traffic class [ 0 ..4 ] \sa CCI API Ref Manual */	 
 CiNumericRange deliveryOrder ; /**< Delivery order [ 0 ..2 ] \sa CCI API Ref Manual */	 
 CiNumericRange deliverErrSdu ; /**< Delivery of erroneous SDUs [ 0 ..3 ] \sa CCI API Ref Manual */	 
 CiNumericRange resBER ; /**< Residual BER [ 0 ..9 ] \sa CCI API Ref Manual */	 
 CiNumericRange errRatio ; /**< SDU error ratio [ 0 ..7 ] \sa CCI API Ref Manual */	 
 CiNumericRange thPriority ; /**< Traffic handling priority [ 0 ..3 ] \sa CCI API Ref Manual */	 
	 
 CiNumericRange transDelay ; /**< Transfer delay [ 0x00 ..0x3e ] \sa CCI API Ref Manual */	 
 CiNumericRange maxSduSize ; /**< Maximum SDU size [ 0x00 ..0x99 ] \sa CCI API Ref Manual */	 
 CiNumericRange maxULRate ; /**< Max bit rate , uplink [ 0x00 ..0xff ] \sa CCI API Ref Manual */	 
 CiNumericRange maxDLRate ; /**< Max bit rate , downlink [ 0x00 ..0xff ] \sa CCI API Ref Manual */	 
 CiNumericRange guaranteedULRate ; /**< Guaranteed bit rate , uplink [ 0x00 ..0xff ] \sa CCI API Ref Manual */	 
 CiNumericRange guaranteedDLRate ; /**< Guaranteed bit rate , downlink [ 0x00 ..0xff ] \sa CCI API Ref Manual */	 
 CiNumericRange SourceStatisticDescriptor ; /**< Specifies characteristics of the source of submitted SDUs [ 0x00 ..0xff ] \sa CCI API Ref Manual */	 
 } CiPs3GQosCap;

//ICAT EXPORTED STRUCT 
 typedef struct CiPs3GQosCaps_struct 
 {	 
 UINT8 size ; /**< Size */	 
 CiPs3GQosCap caps [ ( 8 ) ] ; /** 3 G QoS capability per defined PDP context \sa CiPs3GQosCap_struct */	 
 /*--3 / 5 / 2009 10 :26AM	 
 * Note: need to check max size of array	 
 * ------------*/	 
 } CiPs3GQosCaps;

//ICAT EXPORTED STRUCT 
 typedef struct CiNumericRangeBYTE_struct {	 
 UINT32 min ; /* lower limit */	 
 UINT32 max ; /* upper limit */	 
 } CiNumericRangeBYTE;

//ICAT EXPORTED STRUCT 
 typedef struct CiPs4GQosProfile_struct 
 {	 
 UINT8 qci ; /**Qos Class Identifier */	 
 CiBoolean gbrMbrPresent ; /**indicate whether GBR & MBR presnt */	 
 UINT32 maxULRate ; /**<UL_MBR Max Bit Rate , Uplink , in kbps */	 
 UINT32 maxDLRate ; /**<DL_MBR Max Bit Rate , Downlink , in kbps ( MAX 256000 kbps ) */	 
 UINT32 guaranteedULRate ; /**<UL_GBR Guaranteed Bit Rate , Uplink , in kbps */	 
 UINT32 guaranteedDLRate ; /**<DL_GBR Guaranteed Bit Rate , Downlink , in kbps */	 
 CiBoolean ambrPresent ; /**indicate whether AMBR presnt for +CGEQOSRDP */	 
 UINT32 apnULAmbr ; /**<UL_AMBR , UL APN aggregate MBR , in kbps */	 
 UINT32 apnDLAmbr ; /**<DL_AMBR , DL APN aggregate MBR , in kbps */	 
 } CiPs4GQosProfile;

//ICAT EXPORTED STRUCT 
 typedef struct CiPs4GQosCap_struct 
 {	 
 UINT8 qci ; /**Qos Class Identifier */	 
 CiNumericRangeBYTE maxULRate ; /**< Max Bit Rate , Uplink */	 
 CiNumericRangeBYTE maxDLRate ; /**< Max Bit Rate , Downlink */	 
 CiNumericRangeBYTE guaranteedULRate ; /**< Guaranteed Bit Rate , Uplink */	 
 CiNumericRangeBYTE guaranteedDLRate ; /**< Guaranteed Bit Rate , Downlink */	 
 } CiPs4GQosCap;

//ICAT EXPORTED STRUCT 
 typedef struct CiPs4GQosCaps_struct 
 {	 
 UINT8 size ; /**< Size. */	 
 /* # Start Contiguous Code Section # */	 
 CiPs4GQosCap caps [ ( 8 ) ] ; /** 4 G QoS capability per defined PDP context. \sa CiPs4GQosCap_struct */	 
	 
 /* # End Contiguous Code Section # */	 
 } CiPs4GQosCaps;

//ICAT EXPORTED ENUM 
 typedef enum CIPS_COUNTERREPORTTYPES 
 {	 
 CI_PS_COUNTER_REPORT_ONE_SHOT = 0 , /**< A single CI_PS_PRIM_COUNTER_IND indication is sent when the information is received from the protocol stack. */	 
 CI_PS_COUNTER_REPORT_PERIODIC , /**< Periodic CI_PS_PRIM_COUNTER_IND indications to be sent at intervals specified	 
 * by the interval parameter. The minimum value for the interval parameter is one second ; if it is set to zero , CCI uses a	 
 * one second interval. */	 
 CI_PS_COUNTER_REPORT_STOP , /**< Stop periodic report */	 
	 
 CI_PS_NUM_COUNTER_REPORT_TYPES	 
 } _CiPsCounterReportType;

typedef UINT8 CiPsCounterReportType ;
typedef UINT8 CiPsAttachStateCause ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetAttachStateReq_struct 
 {	 
 CiBoolean state ; /**< State of the PS attachment. TRUE: attach ; FALSE: detach. \sa CCI API Ref Manual */	 
 CiPsAttachStateCause cause ;	 
 } CiPsPrimSetAttachStateReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetAttachStateCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimSetAttachStateCnf;

typedef CiEmptyPrim CiPsPrimGetAttachStateReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetAttachStateCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiBoolean state ; /**< State of the PS attachment. TRUE: attached ; FALSE: detached. \sa CCI API Ref Manual */	 
 } CiPsPrimGetAttachStateCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDefinePdpCtxReq_struct 
 {	 
 CiPsPdpCtx pdpCtx ; /**< PDP context definition \sa CiPsPdpCtx_struct */	 
 } CiPsPrimDefinePdpCtxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDefinePdpCtxCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimDefinePdpCtxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDeletePdpCtxReq_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimDeletePdpCtxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDeletePdpCtxCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimDeletePdpCtxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetPdpCtxReq_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier */	 
 } CiPsPrimGetPdpCtxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetPdpCtxCnf_struct 
 {	 
	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiBoolean ctxPresent ; /**< TRUE: if present \sa CCI API Ref Manual */	 
 CiPsPdpCtxInfo ctx ; /**< PDP context information , optional if rc is not CIRC_PS_SUCCESS \sa CiPsPdpCtxInfo_struct */	 
 UINT8 pcoData [ 250 ] ; /**< Extended PCO to replace ctx.pdpCtx.pdParas.valStr */ /*Lilei , CQ00133813 , 20211104 */	 
 } CiPsPrimGetPdpCtxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimRead4GPdpCtxDynParaReq_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier. */	 
 } CiPsPrimRead4GPdpCtxDynParaReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPdpCtxDynPara_struct 
 {	 
 UINT8 cid ;	 
 CiBoolean bidPresent ;	 
 UINT8 bid ; // if CID actived , bear ID must configured	 
 CiBoolean apnPresent ;	 
 CiString apn ; // 104 bytes	 
 CiPsPdpIpAddr ipv4Addr ;	 
 CiPsPdpIpAddr ipv6Addr ;	 
 UINT8 gwAddrNum ;	 
 UINT8 dnsAddrNum ;	 
 UINT8 pCscfAddrNum ;	 
 UINT8 reserved0 ;	 
 CiPsPdpIpAddr gwAddr [ 4 ] ;	 
 CiPsPdpIpAddr dnsAddr [ 4 ] ;	 
 CiPsPdpIpAddr pCscfAddr [ 4 ] ;	 
 UINT8 imCnSigFlag ; // 0 , 1	 
 UINT8 lipaInd ; // 0 , 1	 
	 
 CiPsSmFollowAct smFlwAct ;	 
 CiBoolean smCausePresent ; // ESM CAUSE from NW	 
 CiPsEsmCauseType smCause ; // ESM CAUSE from NW	 
	 
 CiBoolean ipv4MtuPresent ;	 
 UINT16 ipv4Mtu ;	 
	 
 // #if defined ( DS3_CAT1 )	 
 CiBoolean wlanOffloadPresent ;	 
 UINT8 wlanOffload ; /**WLAN_Offload : 0 ~3 not supported*/	 
 CiBoolean localAddrIndPresent ;	 
 UINT8 localAddrInd ; /**Local_Addr_ind:0~1*/	 
 CiBoolean nonIpMtuPresent ;	 
 UINT16 nonIpMtu ; /**Non-IP_MTU*/	 
 CiBoolean servingPlmnRateControlPresent ;	 
 UINT16 servingPlmnRateControlValue ; /**Serving_PLMN_rate_control_value*/	 
 // #endif	 
 } CiPsPdpCtxDynPara;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimRead4GPdpCtxDynParaCnf_struct 
 {	 
	 
 CiPsRc rc ; // UINT16	 
 CiBoolean ctxPresent ;	 
 CiPsPdpCtxDynPara ctxDynPara ;	 
 } CiPsPrimRead4GPdpCtxDynParaCnf;

typedef CiEmptyPrim CiPsPrimGetPdpCtxCapsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetPdpCtxCapsCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiPsPdpCtxCaps pdpCtxCaps ; /**< PDP context capabilities supported by the cellular subsystem \sa CiPsPdpCtxCaps_struct */	 
 } CiPsPrimGetPdpCtxCapsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetPdpCtxActStateReq_struct 
 {	 
 CiBoolean state ; /**< State of the PS attachment. TRUE: activate ; FALSE: deactivate. \sa CCI API Ref Manual */	 
 CiBoolean doAll ; /**< Not supported*/	 
 UINT8 cid ; /**< PDP context identifier */	 
 CiPsL2P l2p ; /**< L2 protocol type \sa CiPsL2P */	 
 } CiPsPrimSetPdpCtxActStateReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetPdpCtxActStateCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
	 
 CiBoolean smCausePresent ; // if activated PDP , SM caused from NW , if deactivate PDP , this flag not valid	 
 CiPsEsmCauseType smCause ; // ESM CAUSE from NW	 
 CiPsSmFollowAct smFlwAct ; // SM following action , if deactivate a PDP , not valid	 
 } CiPsPrimSetPdpCtxActStateCnf;

typedef CiEmptyPrim CiPsPrimGetPdpCtxsActStateReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetPdpCtxsActStateCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 UINT8 num ; /**< Number of defined PDP contexts [ 0 -CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiPsPdpCtxActState lst [ ( 8 ) ] ; /**< Activation state for the defined PDP contexts \sa CiPsPdpCtxActState_struct */	 
 } CiPsPrimGetPdpCtxsActStateCnf;

typedef CiEmptyPrim CiPsPrimRead4GPdpCtxsActDynParaReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimRead4GPdpCtxsActDynParaCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 UINT8 num ; /**< Number of defined PDP contexts [ 0 -CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 UINT8 cid [ ( 8 ) ] ; /**< PDP context information , optional if rc is not CIRC_PS_SUCCESS. \sa CiPsPdpCtxInfo_struct */	 
 } CiPsPrimRead4GPdpCtxsActDynParaCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEnterDataStateReq_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier */	 
 CiPsL2P l2p ; /**< L2 protocol type \sa CiPsL2P */	 
 CiBoolean optimizedData ; /**< TRUE indicates that optimized ACI data plane is used \sa CCI API Ref Manual */	 
 } CiPsPrimEnterDataStateReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEnterDataStateCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiBoolean smCausePresent ; // ESM CAUSE from NW	 
 CiPsEsmCauseType smCause ; // ESM CAUSE from NW	 
 CiPsSmFollowAct smFlwAct ; // SM following action	 
 } CiPsPrimEnterDataStateCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimMtPdpCtxActModifyInd_struct 
 {	 
 CiPsPdpCtx pdpCtx ; /**< PDP context information \sa CiPsPdpCtx_struct */	 
 CiPsActionType actionType ; /**< Action requested on PDP context - activation or modification \sa CiPsActionType */	 
	 
 CiPsPdpModifyChangeReason change_reason ;	 
	 
 } CiPsPrimMtPdpCtxActModifyInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimMtPdpCtxActModifyRsp_struct {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 UINT8 cid ; /**< PDP context identifier */	 
 CiBoolean accept ; /**< TRUE: accept ; FALSE: reject \sa CCI API Ref Manual */	 
 CiPsL2P l2p ; /**< L2 protocol type \sa CiPsL2P */	 
 } CiPsPrimMtPdpCtxActModifyRsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimMtPdpCtxActedInd_struct 
 {	 
 CiPsPdpCtx pdpCtx ; /**< PDP context information \sa CiPsPdpCtx_struct */	 
 CiBoolean isMEInitiated ; /** MO / MT ; ME / NW */	 
 CiPsMoPdpActReason pdpReason ; /** for CGEV*/	 
 UINT8 cid_other ; // only valided when pdpReason = " CI_PS_PDP_SINGLE_ONLY_ALLOWED_SEC_SUCC "	 
 } CiPsPrimMtPdpCtxActedInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetGsmGprsClassReq_struct 
 {	 
 CiPsGsmGprsClass classType ; /**< Mobile class for GSM / GPRS \sa CiPsGsmGprsClass */	 
 } CiPsPrimSetGsmGprsClassReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetGsmGprsClassCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimSetGsmGprsClassCnf;

typedef CiEmptyPrim CiPsPrimGetGsmGprsClassReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetGsmGprsClassCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiPsGsmGprsClass classType ; /**< Mobile class for GSM / GPRS \sa CiPsGsmGprsClass */	 
 } CiPsPrimGetGsmGprsClassCnf;

typedef CiEmptyPrim CiPsPrimGetGsmGprsClassesReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetGsmGprsClassesCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiBitRange classes ; /**< Mobile class for GSM / GPRS \sa CCI API Ref Manual */	 
 } CiPsPrimGetGsmGprsClassesCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEnableNwRegIndReq_struct 
 {	 
 CiPsNwRegIndFlag flag ; /**< Configures network registration status reports \sa CiPsNwRegIndFlag */	 
 } CiPsPrimEnableNwRegIndReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEnableNwRegIndCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimEnableNwRegIndCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimNwRegInd_struct 
 {	 
 CiPsNwRegInfo nwRegInfo ; /**< Network registration information \sa CiPsNwRegInfo_struct */	 
 } CiPsPrimNwRegInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEnable4GNwRegIndReq_struct 
 {	 
 CiPs4GNwRegIndFlag flag ; /**< Configures nework registration status reports.\sa CiPsNwRegIndFlag */	 
 } CiPsPrimEnable4GNwRegIndReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEnable4GNwRegIndCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimEnable4GNwRegIndCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrim4GNwRegInd_struct 
 {	 
 CiPs4GNwRegInfo nwRegInfo ; /**< Network registration information \sa CiPsPrim4GNwRegInd_struct */	 
 } CiPsPrim4GNwRegInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetQosReq_struct 
 {	 
 CiBoolean isMin ; /**< Indicates if the profile requested is minimum or required QoS profile \sa CCI API Ref Manual */	 
 UINT8 cid ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiPsQosProfile qosProf ; /**< QoS profile data \sa CiPsQosProfile_struct */	 
 } CiPsPrimSetQosReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetQosCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimSetQosCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDelQosReq_struct 
 {	 
 CiBoolean isMin ; /**< Indicates if the profile requested is minimum or required QoS profile \sa CCI API Ref Manual */	 
 UINT8 cid ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimDelQosReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDelQosCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimDelQosCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetQosReq_struct 
 {	 
 CiBoolean isMin ; /**< Indicates if the profile requested is minimum or required QoS profile \sa CCI API Ref Manual */	 
 UINT8 cid ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimGetQosReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetQosCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiBoolean qosProfPresent ; /**< Not in use \sa CCI API Ref Manual */	 
 CiPsQosProfile qosProf ; /**< QoS profile , optional if rc is not CIRC_PS_SUCCESS \sa CiPsQosProfile_struct */	 
 } CiPsPrimGetQosCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEnablePoweronAutoAttachReq_struct 
 {	 
 CiBoolean enableAutoAttach ; /**< AutoAttach configuration. TRUE: Attach to PS domain will be automatically initiated on power up	 
 * FALSE: Attach to PS domain will be initiated by the user. \sa CCI API Ref Manual */	 
 } CiPsPrimEnablePoweronAutoAttachReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEnablePoweronAutoAttachCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc. */	 
 } CiPsPrimEnablePoweronAutoAttachCnf;

typedef CiEmptyPrim CiPsPrimGetPoweronAutoAttachStatusReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetPoweronAutoAttachStatusCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc. */	 
 CiBoolean AutoAttachStatus ; /**< AutoAttach configuration. TRUE: Attach to PS domain will be automatically initiated on power up	 
 * FALSE: Attach to PS domain will be initiated by the user. \sa CCI API Ref Manual */	 
 } CiPsPrimGetPoweronAutoAttachStatusCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimMtPdpCtxRejectedInd_struct 
 {	 
 UINT8 cause ;	 
 CiPsIndicatedPdpCtx indedPdpCtx ;	 
 } CiPsPrimMtPdpCtxRejectedInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimPdpCtxDeactedInd_struct 
 {	 
 UINT8 cause ; /**< Cause for PDP context deactivation. SM cause is defined in 3 GPP TS 24.008000 section 10.500000 .6.6. */	 
 CiBoolean isMEInitiated ; /**< TRUE if ME requested PDP context deactivation or PPP connection failure detected in comm . \sa CCI API Ref Manual */	 
 UINT8 res1U8 [ 2 ] ; /**< ( padding ) */	 
 CiPsIndicatedPdpCtx indedPdpCtx ; /**< Indicated PDP context \sa CiPsPdpCtxInd_struct */	 
 } CiPsPrimPdpCtxDeactedInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimPdpCtxReactedInd_struct 
 {	 
 CiPsIndicatedPdpCtx indedPdpCtx ;	 
 } CiPsPrimPdpCtxReactedInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDetachedInd_struct 
 {	 
 CiBoolean isMeDetach ; /**< Indicates if detach is initiated by ME or network. TRUE indicates by ME ; FALSE indicates by network. \sa CCI API Ref Manual */	 
 } CiPsPrimDetachedInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGprsClassChangedInd_struct 
 {	 
 CiPsGsmGprsClass classType ; /**< Mobile class for GSM / GPRS \sa CiPsGsmGprsClass */	 
 CiBoolean IsMEClassChanged ; /**< TRUE if network mode changed. \sa CCI API Ref Manual */	 
 } CiPsPrimGprsClassChangedInd;

typedef CiEmptyPrim CiPsPrimGetDefinedCidListReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetDefinedCidListCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 UINT8 size ; /**< Size of the CID list [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM ] */	 
 UINT8 cidLst [ ( 8 ) ] ; /**< CID list */	 
 } CiPsPrimGetDefinedCidListCnf;

typedef CiEmptyPrim CiPsPrimGetNwRegStatusReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetNwRegStatusCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiPsNwRegIndFlag regIndflag ; /** report level , n = 0 , 1 , 2 , 3 **/	 
 CiPsNwRegInfo nwRegInfo ; /**< Network registration information \sa CiPsNwRegInfo_struct */	 
 } CiPsPrimGetNwRegStatusCnf;

typedef CiEmptyPrim CiPsPrimGet4GNwRegStatusReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet4GNwRegStatusCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 CiPs4GNwRegIndFlag regIndflag ; /** report level , n = 0 , 1 , 2 , 3 **/	 
 CiPs4GNwRegInfo nwRegInfo ; /**< Network registration information. \sa CiPs4GNwRegInfo_struct */	 
 } CiPsPrimGet4GNwRegStatusCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetQosCapsReq_struct 
 {	 
 CiBoolean isMin ; /**< Not in use */	 
 } CiPsPrimGetQosCapsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetQosCapsCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiBoolean qosCapsPresent ; /**< TRUE: if present */	 
 CiPsQosCaps qosCaps ; /**< QoS capabilities , optional if rc is not CIRC_PS_SUCCESS \sa CiPsQosCaps_struct */	 
	 
 } CiPsPrimGetQosCapsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEnableEventsReportingReq_struct 
 {	 
 CiBoolean enable ; /**< TRUE: enable events reporting ; FALSE: disable events reporting ; default: FALSE \sa CCI API Ref Manual */	 
 } CiPsPrimEnableEventsReportingReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEnableEventsReportingCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimEnableEventsReportingCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet3GQosReq_struct 
 {	 
 CiPs3GQosType qosType ; /**< Specifies 3 G minimum , required or negotiated QoS profile \sa CiPs3GQosType */ // REQ / MIN / NEG	 
 UINT8 cid ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimGet3GQosReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet3GQosCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiBoolean qosProfPresent ; /**< If TRUE , qosProf contains the 3 G QoS profile ; if FALSE , qosProf does not contain useful information \sa CCI API Ref Manual */	 
 CiPs3GQosProfile qosProf ; /**< 3 G QoS profile , optional if rc is not CIRC_PS_SUCCESS \sa CiPs3GQosProfile_struct */	 
 } CiPsPrimGet3GQosCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSet3GQosReq_struct 
 {	 
 CiPs3GQosType qosType ; /**< Specifies 3 G minimum or required QoS profile \sa CiPs3GQosType */ // REQ / MIN ( NEG is not valid here )	 
 UINT8 cid ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiPs3GQosProfile qosProf ; /**< 3 G QoS profile \sa CiPs3GQosProfile_struct */	 
 } CiPsPrimSet3GQosReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSet3GQosCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimSet3GQosCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDel3GQosReq_struct 
 {	 
 CiPs3GQosType qosType ; /**< Specifies 3 G minimum or required QoS profile \sa CiPs3GQosType */ // REQ / MIN ( NEG is not valid here )	 
 UINT8 cid ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimDel3GQosReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDel3GQosCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimDel3GQosCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet3GQosCapsReq_struct 
 {	 
 CiPs3GQosType qosType ; /**< Not in use */ // REQ / MIN / NEG	 
 } CiPsPrimGet3GQosCapsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet3GQosCapsCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiBoolean qosCapsPresent ; /**< If TRUE , qosCaps contains the 3 G QoS capabilities ; if FALSE , qosCaps does not contain useful information. \sa CCI API Ref Manual*/	 
 CiPs3GQosCaps qosCaps ; /**< 3 G QoS capabilities ; optional if rc is not CIRC_PS_SUCCESS \sa CiPs3GQosCaps_struct */	 
 } CiPsPrimGet3GQosCapsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet4GQosReq_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimGet4GQosReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet4GQosCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 UINT8 cid ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiBoolean qosProfPresent ; /**< If TRUE , qosProf will have the 3 G QoS profile ; If FALSE , qosProf doesn ' t contain useful information ; \sa CCI API Ref Manual */	 
 CiPs4GQosProfile qosProfile ; /**< 4 G QoS profile , optional if rc is not CIRC_PS_SUCCESS ; \sa CiPs3GQosProfile_struct */	 
 } CiPsPrimGet4GQosCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSet4GQosReq_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiPs4GQosProfile qosProfile ; /**< 4 G QoS profile , optional if rc is not CIRC_PS_SUCCESS ; \sa CiPs3GQosProfile_struct */	 
 } CiPsPrimSet4GQosReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSet4GQosCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimSet4GQosCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDel4GQosReq_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimDel4GQosReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDel4GQosCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimDel4GQosCnf;

typedef CiEmptyPrim CiPsPrimGet4GQosCapsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet4GQosCapsCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 CiBoolean qosCapsPresent ; /**< If TRUE , qosCaps will have the 3 G QoS capabilities ; If FALSE , qosCaps doesn ' t contain useful information ; \sa CCI API Ref Manual*/	 
 CiPs4GQosCaps qosCaps ; /**< 4 G QoS profile , optional if rc is not CIRC_PS_SUCCESS ; \sa CiPs3GQosProfile_struct */	 
 } CiPsPrimGet4GQosCapsCnf;

typedef CiEmptyPrim CiPsPrimGet4GModeReq ;
//ICAT EXPORTED STRUCT 
 
 typedef struct CiPsPrimGet4GModeCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 UINT8 cipslteOperateMode ;	 
 } CiPsPrimGet4GModeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSet4GModeReq_struct 
 {	 
 UINT8 cipslteOperateMode ;	 
 } CiPsPrimSet4GModeReq;

//ICAT EXPORTED STRUCT 
 
 typedef struct CiPsPrimSet4GModeCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimSet4GModeCnf;

typedef CiEmptyPrim CiPsPrimGet4GModeCapsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsLteOperateModes_struct 
 {	 
 UINT8 ciPsLteOperateMode [ 4 ] ; /** 4 G QoS capability per defined PDP context. \sa CiPs4GQosCap_struct */	 
 } CiPsLteOperateModes;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet4GModeCapsCnf_struct 
 {	 
 CiPsLteOperateModes ciPsLteOperateModes ;	 
 } CiPsPrimGet4GModeCapsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetPdpAddrReq_struct 
 {	 
 UINT8 num ;	 
 UINT8 cid [ ( 8 ) ] ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimGetPdpAddrReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetPdpAddrCnf_struct 
 {	 
 CiPsRc rc ;	 
 UINT8 num ;	 
 UINT8 cid [ ( 8 ) ] ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiPsPdpAddr pdpAddress [ ( 8 ) ] ;	 
 } CiPsPrimGetPdpAddrCnf;

typedef CiEmptyPrim CiPsPrimGetPdpAddrListReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetPdpAddrListCnf_struct 
 {	 
 CiPsRc rc ;	 
 UINT8 nums ;	 
 UINT8 cid [ ( 8 ) ] ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimGetPdpAddrListCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDefineSecPdpCtxReq_struct 
 {	 
 CiPsSecPdpCtx secPdpCtx ; /**< Secondary PDP context \sa CiPsSecPdpCtx_struct */	 
 } CiPsPrimDefineSecPdpCtxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDefineSecPdpCtxCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimDefineSecPdpCtxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDeleteSecPdpCtxReq_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimDeleteSecPdpCtxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDeleteSecPdpCtxCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimDeleteSecPdpCtxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetSecPdpCtxReq_struct 
 {	 
 UINT8 cid ; /**< Secondary PDP context ID [ [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] ] */	 
 } CiPsPrimGetSecPdpCtxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetSecPdpCtxCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiBoolean ctxPresent ; /**< Set to FALSE , if the result code parameter indicates an error \sa CCI API Ref Manual */	 
 CiPsSecPdpCtxInfo ctx ; /**< Secondary PDP context information \sa CiPsSecPdpCtxInfo_struct */	 
 } CiPsPrimGetSecPdpCtxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimRead4GSecPdpCtxDynParaReq_struct 
 {	 
 UINT8 cid ; /**< Secondary PDP context ID [ [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] ] */	 
 } CiPsPrimRead4GSecPdpCtxDynParaReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimRead4GSecPdpCtxDynParaCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 UINT8 num ;	 
 CiPsID psId [ ( 8 ) ] ;	 
 CiPsImCnSignallingFlagIndType imCnSigFlag [ ( 8 ) ] ;	 
 } CiPsPrimRead4GSecPdpCtxDynParaCnf;

typedef CiEmptyPrim CiPsPrimRead4GSecPdpCtxsActDynParaReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimRead4GSecPdpCtxsActDynParaCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 UINT8 num ;	 
 UINT8 cid [ ( 8 ) ] ; /**< Secondary PDP Context Information. \sa CiPsSecPdpCtxInfo_struct */	 
 } CiPsPrimRead4GSecPdpCtxsActDynParaCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDefineTftFilterReq_struct 
 {	 
 UINT8 cid ; /**< Secondary PDP context ID [ [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] ] */	 
 CiPsTftFilter filter ; /**< TFT filter parameters \sa CiPsTftFilter_struct */	 
 } CiPsPrimDefineTftFilterReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDefineTftFilterCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimDefineTftFilterCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDeleteTftReq_struct 
 {	 
 UINT8 cid ; /**< Context ID [ [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] ] */	 
 } CiPsPrimDeleteTftReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDeleteTftCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimDeleteTftCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetTftReq_struct 
 {	 
 UINT8 cid ; /**< Context ID [ [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] ] */	 
 } CiPsPrimGetTftReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetTftCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 UINT8 numFilters ; /**< Number of packet filters */	 
 CiPsTftFilter filters [ 16 ] ; /**< Not in use */	 
 } CiPsPrimGetTftCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimModifyPdpCtxReq_struct 
 {	 
 CiBoolean doAll ; /**< Not supported */	 
 UINT8 cid ; /**< PDP context identifier */	 
 } CiPsPrimModifyPdpCtxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimModifyPdpCtxCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimModifyPdpCtxCnf;

typedef CiEmptyPrim CiPsPrimGetActiveCidListReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetActiveCidListCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 UINT8 size ; /**< Size of the CID list [ 0 ..CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM ] */	 
 UINT8 cidLst [ ( 8 ) ] ; /**< CID list */	 
 } CiPsPrimGetActiveCidListCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimReportCounterReq_struct 
 {	 
 CiPsCounterReportType type ; /**< Report type \sa CiPsCounterReportType */	 
 UINT16 interval ; /**< Report interval ( seconds ) , minimum report interval is 1 second. Required for periodic report configuration. */	 
 } CiPsPrimReportCounterReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimReportCounterCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimReportCounterCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimResetCounterReq_struct 
 {	 
 /*-----------------6 / 7 / 2009 11 :53AM-----------------	 
 * doAll parameter is a fix for SCR 1980451 -> 1818954 #9.	 
 * --------------------------------------------------*/	 
 CiBoolean doAll ; /**< Indicates if all counters should be reset ; TRUE: reset all counters ; FALSE: reset the counter for a requested context ID \sa CCI API Ref Manual*/	 
 UINT8 cid ; /**< Context ID , required if doAll == FALSE */	 
 } CiPsPrimResetCounterReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimResetCounterCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimResetCounterCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimCounterInd_struct 
 {	 
 UINT8 cid ; /**< PDP context ID , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 UINT32 totalULBytes ; /**< Total bytes sent on uplink ( uncompressed ) */	 
 UINT32 totalDLBytes ; /**< Total bytes received on downlink ( uncompressed ) */	 
 } CiPsPrimCounterInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSendDataReq_struct 
 {	 
 UINT16 pcktsize ; /* Packet size range: 0 - 10000 , default 1472 */	 
 UINT16 pcktcount ; /* Number of packets to send: 1 - 20 , default 1 */	 
 UINT8 nsapi ; /* PDP context ID */	 
 UINT8 PAD1 ;	 
 UINT8 PAD2 ;	 
 UINT8 PAD3 ;	 
 } CiPsPrimSendDataReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSendDataCnf_struct 
 {	 
 CiPsRc rc ;	 
 } CiPsPrimSendDataCnf;

//ICAT EXPORTED ENUM 
 typedef enum CiAbgpRequestStatusTag 
 {	 
 CI_ABGP_APN_OK , /**< OK */	 
 CI_ABGP_APN_NRAM_ERROR , /**< APN NRAM error */	 
 CI_ABGP_APN_RECORD_NOT_FOUND , /**< APN record not found */	 
	 
 CI_ABGP_ALLIGN =0xFFFF	 
	 
 } _CiPsSimResult;

typedef UINT16 CiPsSimResult ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetAclReq_struct {	 
 CiBoolean simAclPresent ;	 
 CiBoolean simAclEnable ; /**< TRUE: enable ACL service ; FALSE: disable ACL service \sa CCI API Ref Manual */	 
 CiBoolean psAclPresent ;	 
 CiBoolean psAclEnable ;	 
 } CiPsPrimSetAclReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetAclCnf_struct {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiPsSimResult SimCause ; /**< SIM result code \sa CiPsSimResult */	 
 CiBoolean simAclEnable ; /**< Service status ; TRUE: enabled , FALSE: disabled \sa CCI API Ref Manual*/	 
 CiBoolean psAclEnable ;	 
 } CiPsPrimSetAclCnf;

typedef CiEmptyPrim CiPsPrimGetAclSizeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetAclSizeCnf_struct {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiPsSimResult SimCause ; /**< SIM result code \sa CiPsSimResult */	 
 UINT8 totalNumApns ; /**< Number of APNs currently held in SIM file EF_ACL */	 
 } CiPsPrimGetAclSizeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimReadAclEntryReq_struct {	 
 UINT8 Index ; /**< Index into ACL list */	 
 } CiPsPrimReadAclEntryReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimReadAclEntryReqCnf_struct {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiPsSimResult SimCause ; /**< SIM result code \sa CiPsSimResult */	 
 CiLongAdrInfo apn ; /**< Requested APN in string format \sa CCI API Ref Manual*/	 
 } CiPsPrimReadAclEntryCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEditAclEntryReq_struct {	 
 CiEditCmdType EditCommand ; /**< Edit command ( add , delete , or replace ) \sa CCI API Ref Manual*/	 
 UINT8 position ; /**< Index into ACL list */	 
 /*To add the " Network provided APN " to the APN Control List , the length of the APN should be set to 0 */	 
 CiLongAdrInfo apn ; /**< APN in string format ; required for add or replace commands \sa CCI API Ref Manual*/	 
 } CiPsPrimEditAclEntryReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEditAclEntryCnf_struct {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiPsSimResult SimCause ; /**< SIM result code \sa CiPsSimResult */	 
 UINT8 position ; /**< Index in ACL list */	 
 } CiPsPrimEditAclEntryCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIPSAUTHENTICATIONTYPE_TAG 
 {	 
 CI_PS_AUTHENTICATION_TYPE_NONE , /**< No authentication protocol */	 
 CI_PS_AUTHENTICATION_TYPE_PAP , /**< Password authentication protocol */	 
 CI_PS_AUTHENTICATION_TYPE_CHAP , /**< Challenge-Handshake authentication protocol */	 
 CI_PS_AUTHENTICATION_TYPE_PAP_CHAP , /**< PAP preferred , CHAP as secondary */ /*Lilei , CQ00115591 , 20190724 */	 
 CI_PS_AUTHENTICATION_TYPE_CHAP_PAP , /**< CHAP preferred , PAP as secondary */ /*Lilei , CQ00115591 , 20191021 */	 
 CI_PS_AUTHENTICATION_TYPE_PPP_CHAP , /**< Challenge-Handshake authentication protocol for PPP */ /*Lilei , CQ00111775 , 20180814 */	 
	 
 CI_PS_AUTHENTICATION_TYPE_NUM	 
	 
 } _CiPsAuthenticationType;

typedef UINT8 CiPsAuthenticationType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimAuthenticateReq_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier */	 
 CiPsAuthenticationType AuthenticationType ; /**< Authentication type. \sa CiPsAuthenticationType */	 
 /* !!!!!!!!!!!!!!!!!!!	 
 * When RIL completes the transition to contiguous memory , all CCI_xx_CONTIGUOUS	 
 * & CCI_APP_NONCONTIGUOUS flags must be removed.	 
 * ONLY the code BETWEEN the following 2 comment lines will REMAIN:	 
 * # Start Contiguous Code Section # and # End Contiguous Code Section #	 
 * All other code OUTSIDE these comments must be REMOVED - ( The backwards compatible code )	 
 */	 
 /* # Start Contiguous Code Section # */	 
 CiStringExt UserName ; /**< UserName octets. \sa CCI API Ref Manual */	 
 CiStringExt Password ; /**< Password octets. \sa CCI API Ref Manual */	 
 /* # End Contiguous Code Section # */	 
	 
 } CiPsPrimAuthenticateReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimAuthenticateCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimAuthenticateCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetDefaultPdpAuthenticateReq_struct 
 {	 
 UINT8 modeType ; // 0 - not save to NVM , 1 - save to NUM ;	 
 CiPsAuthenticationType authenticationType ; /**< Authentication type. \sa CiPsAuthenticationType */	 
 CiBoolean authInfoPresent ;	 
 CiStringExt userName ; /**< UserName octets. \sa CCI API Ref Manual */	 
 CiStringExt password ; /**< Password octets. \sa CCI API Ref Manual */	 
 } CiPsPrimSetDefaultPdpAuthenticateReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetDefaultPdpAuthenticateCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimSetDefaultPdpAuthenticateCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetDefaultPdpAuthenticateReq_Tag 
 {	 
 UINT8 modeType ; // 0 - current used , 1 - from NVM	 
 } CiPsPrimGetDefaultPdpAuthenticateReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetDefaultPdpAuthenticateCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 CiPsAuthenticationType authenticationType ; /**< Authentication type. \sa CiPsAuthenticationType */	 
 CiStringExt userName ; /**< UserName octets. \sa CCI API Ref Manual */	 
 CiStringExt password ; /**< Password octets. \sa CCI API Ref Manual */	 
 } CiPsPrimGetDefaultPdpAuthenticateCnf;

typedef CiEmptyPrim CiPsPrimFastDormantReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimFastDormantCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimFastDormantCnf;

typedef CiEmptyPrim CiPsPrimGetCurrentJobReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetCurrentJobCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 CiPrimitiveID primId ; /**< Primitive ID. \sa CiPrimitiveID */	 
 } CiPsPrimGetCurrentJobCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIPS_FDY_OPTION {	 
 CIPS_FDY_DISABLE = 0 , /**< Disable PS power consuming control */	 
 CIPS_FDY_ENABLE , /**< Enable PS power consuming control */	 
	 
 /* This one must always be last in the list! */	 
 CIPS_NUM_FDY_OPTIONS /**< Number of options defined */	 
 } _CiPsFDYOpt;

typedef UINT8 CiPsFDYOpt ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_PS_PRIM_SET_FAST_DORMANCY_CONFIG_REQ " > */ 
 typedef struct CiPsPrimSetFastDormancyConfigReq_struct 
 {	 
 /* add by xwzhou for CQ55965 on 3032014 , begin */	 
 // CiPsFDYOpt type ; / **< Type. \sa CiPsFDYOpt * /	 
 // UINT16 interval ; / **< Trigger Interval ( seconds ) , the default value is 3 * /	 
 INT16 mode ; /**< 0 : disable fast dormancy timer ; 1 : enable fast dormancy timer*/	 
 UINT32 lcdOnTimerMsLength ; /**< ( unit:ms ) , if timer length=0 , disable FD*/	 
 UINT32 lcdOffTimerMsLength ; /**< ( unit:ms ) , if timer length=0 , disable FD*/	 
 UINT32 rel8LcdOnTimerMsLength ; /**< ( unit:ms ) , if timer length=0 , disable FD*/	 
 UINT32 rel8LcdOffTimerMsLength ; /**< ( unit:ms ) , if timer length=0 , disable FD*/	 
 /* add by xwzhou for CQ55965 on 3032014 , end */	 
 } CiPsPrimSetFastDormancyConfigReq;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_PS_PRIM_SET_FAST_DORMANCY_CONFIG_CNF " > */ 
 typedef struct CiPsPrimSetFastDormancyConfigCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimSetFastDormancyConfigCnf;

typedef UINT8 CiPsPdpTriggerType ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_PS_PRIM_PDP_ACTIVATION_REJECT_CAUSE_IND " > */ 
 typedef struct CiPsPrimPdpActivationRejectCauseInd_struct 
 {	 
 CiPsPdpTriggerType pdpType ;	 
 CiBoolean cidPresent ;	 
 UINT8 cid ;	 
 CiBoolean smCausePresent ;	 
 CiPsEsmCauseType smCause ;	 
 CiPsSmFollowAct smflwAction ;	 
 } CiPsPrimPdpActivationRejectCauseInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimRead4GQosDynParaReq_struct {	 
 UINT8 cid ; /**< PDP Context ID , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimRead4GQosDynParaReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimRead4GQosDynParaCnf_struct {	 
 CiPsRc rc ;	 
 UINT8 num ;	 
 CiPs4GQosProfile qosProfile [ ( 8 ) ] ; /**< 4 G QoS profile , optional if rc is not CIRC_PS_SUCCESS ; \sa CiPs3GQosProfile_struct */	 
 UINT8 cid [ ( 8 ) ] ; /**< PDP context ID list , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimRead4GQosDynParaCnf;

typedef CiEmptyPrim CiPsPrimRead4GQosDynParaCapsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimRead4GQosDynParaCapsCnf_struct {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 UINT8 num ;	 
 UINT8 cid [ ( 8 ) ] ; /**< PDP context ID list , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimRead4GQosDynParaCapsCnf;

typedef CiEmptyPrim CiPsPrimGet4GEventRepReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet4GEventRepCnf_struct {	 
 CiPsRc rc ;	 
 UINT16 mode ; /**<	 
 *0 buffer unsolicited result codes in the MT ; if MT result code buffer is full , the oldest ones can be discarded. No codes are forwarded to the TE.	 
 *1 discard unsolicited result codes when MT TE link is reserved ( e.g. in on line data mode ) ; otherwise forward them directly to the TE	 
 *2 buffer unsolicited result codes in the MT when MT TE link is reserved ( e.g. in on line data mode ) and flush them to the TE when MT TE link becomes available ; otherwise forward them directly to the TE	 
 */	 
 UINT16 bfr ; /**<	 
 *0 MT buffer of unsolicited result codes defined within this command is cleared when <mode> 1 or 2 is entered	 
 *1 MT buffer of unsolicited result codes defined within this command is flushed to the TE when <mode> 1 or 2 is entered ( OK response shall be given before flushing the codes )	 
 */	 
 } CiPsPrimGet4GEventRepCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSet4GEventRepReq_struct {	 
 UINT16 mode ; /**<	 
 *0 buffer unsolicited result codes in the MT ; if MT result code buffer is full , the oldest ones can be discarded. No codes are forwarded to the TE.	 
 *1 discard unsolicited result codes when MT TE link is reserved ( e.g. in on line data mode ) ; otherwise forward them directly to the TE	 
 *2 buffer unsolicited result codes in the MT when MT TE link is reserved ( e.g. in on line data mode ) and flush them to the TE when MT TE link becomes available ; otherwise forward them directly to the TE	 
 */	 
 UINT16 bfr ; /**<	 
 *0 MT buffer of unsolicited result codes defined within this command is cleared when <mode> 1 or 2 is entered	 
 *1 MT buffer of unsolicited result codes defined within this command is flushed to the TE when <mode> 1 or 2 is entered ( OK response shall be given before flushing the codes )	 
 */	 
 } CiPsPrimSet4GEventRepReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSet4GEventRepCnf_struct {	 
 CiPsRc rc ;	 
	 
 } CiPsPrimSet4GEventRepCnf;

typedef CiEmptyPrim CiPsPrimGet4GEventRepCapsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct SacPsEventReportCaps_struct 
 {	 
 SacPsEventReportMode mode_min ;	 
 SacPsEventReportMode mode_max ;	 
 SacPsEventReportBufferMode buffer_min ;	 
 SacPsEventReportBufferMode buffer_max ;	 
 } 
 SacPsEventReportCaps;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet4GEventRepCapsCnf_struct {	 
 CiPsRc rc ;	 
 SacPsEventReportCaps reportCaps ;	 
 } CiPsPrimGet4GEventRepCapsCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIPS_VOICE_CALL_MODE_TAG 
 {	 
 CIPS_CS_ONLY = 0 ,	 
 CIPS_VOIP_ONLY ,	 
 CIPS_CS_PREFERRED ,	 
 CIPS_VOIP_PREFERRED ,	 
 CIPS_VOICE_CALL_MODE_NUM	 
 } _CiPsVoiceCallMode;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet4GVoiceCallModeReq_struct {	 
 UINT8 cid ; /**< PDP Context ID , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimGet4GVoiceCallModeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet4GVoiceCallModeCnf_struct {	 
 CiPsRc rc ;	 
 UINT16 mode ; /* 0 CS_ONLY	 
 * 1 VOIP_ONLY	 
 * 2 CS_PREFERRED	 
 * 3 VOIP_PREFERRED	 
 */	 
 } CiPsPrimGet4GVoiceCallModeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSet4GVoiceCallModeReq_struct {	 
 UINT8 cid ; /**< PDP Context ID , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 UINT16 mode ; /* 0 CS_ONLY	 
 * 1 VOIP_ONLY	 
 * 2 CS_PREFERRED	 
 * 3 VOIP_PREFERRED	 
 */	 
 } CiPsPrimSet4GVoiceCallModeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSet4GVoiceCallModeCnf_struct {	 
 CiPsRc rc ;	 
 } CiPsPrimSet4GVoiceCallModeCnf;

typedef CiEmptyPrim CiPsPrimGet4GVoiceCallModeCapsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGet4GVoiceCallModeCapsCnf_struct {	 
 CiPsRc rc ;	 
 UINT16 modebitmap ; /*bit 0 CS_ONLY , will set 1	 
 *bit 1 VOIP_ONLY	 
 *bit 2 CS_PREFERRED	 
 *bit 3 VOIP_PREFERRED	 
 */	 
 } CiPsPrimGet4GVoiceCallModeCapsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimRead4GTrafficFlowTempDynParaReq_struct {	 
 UINT8 cid ; /**< PDP Context ID , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimRead4GTrafficFlowTempDynParaReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimRead4GTrafficFlowTempDynParaCnf_struct {	 
 CiPsRc rc ;	 
 UINT8 numFilters ; /**< Number of Packet Filters */	 
 CiPsTftOpCode opCode ; /** Only valid when get TFT of a specified CID */	 
 CiPsTftFilter filters [ 16 ] ; /**< Not in use */	 
 } CiPsPrimRead4GTrafficFlowTempDynParaCnf;

typedef CiEmptyPrim CiPsPrimRead4GTrafficFlowTempDynParaCapsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimRead4GTrafficFlowTempDynParaCapsCnf_struct {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 UINT8 num ;	 
 UINT8 cid [ ( 8 ) ] ; /**< PDP context ID list , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 } CiPsPrimRead4GTrafficFlowTempDynParaCapsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDataCompReportingReq_struct {	 
 UINT8 report ; /**< 0 - Disable reporting ;	 
 1 - Enable reporting ;	 
 2 - Get current setting. \sa CiPsRc. */	 
 } CiPsPrimDataCompReportingReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDataCompReportingCnf_struct {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc. */	 
 CiBoolean dcomp_report_enabled ; /**< FALSE - report is enabled	 
 TRUE - report is disabled */	 
 } CiPsPrimDataCompReportingCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIPS_DCOMP_STATUS_TAG 
 {	 
 CIPS_DCOMP_NONE , /**< Data compression is not in use */	 
 CIPS_DCOMP_BOTH , /**< V42B ITU-T Rec. V.42 bis is in use in	 
 both directions */	 
 CIPS_DCOMP_RX , /**< V42B RD ITU-T Rec. V.42 bis is in use in receive direction only */	 
 CIPS_DCOMP_TX , /**< V42B TD ITU-T Rec. V.42 bis is in use in transmit direction only */	 
 CIPS_DCOMP_TYPE_NUM ,	 
 } _CiPsDcompStatus;

typedef UINT8 CiPsDcompStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDataCompInd_struct {	 
 UINT8 cid ; /**< PDP context identifier. */	 
 CiPsDcompStatus dcomp ; /**< Indicates the data compression status */	 
 } CiPsPrimDataCompInd;

//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_PS_PRIM_SET_PS_PAGING_CONFIG_REQ " > */ 
 typedef struct CiPsPrimSetPsPagingyConfigReq_struct 
 {	 
	 
 CiBoolean enable ; /**< TRUE: Activate DSDS PS+Paing ; FALSE: Deactivate DSDS PS+Paing \sa CCI API Ref Manual */	 
 } CiPsPrimSetPsPagingyConfigReq;

//ICAT EXPORTED ENUM 
 typedef enum CIPS_VOICE_DOMAIN_PREFERNCE_TAG 
 {	 
 CIPS_VOICE_DOMAIN_CS = 0 ,	 
 CIPS_VOICE_DOMAIN_CS_PREFERRED ,	 
 CIPS_VOICE_DOMAIN_IMS_PS_PREFERRED ,	 
 CIPS_VOICE_DOMAIN_IMS_PS ,	 
 CIPS_VOICE_DOMAIN_PREFERNCE_NUM	 
 } _CiPsVoiceDomainPreference;

typedef UINT8 CiPsVoiceDomainPreference ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_PS_PRIM_SET_PS_PAGING_CONFIG_CNF " > */ 
 typedef struct CiPsPrimSetPsPagingyConfigCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimSetPsPagingyConfigCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetImsVoiceCallAvailabilityReq_struct 
 {	 
 UINT8 state ; /**< 0 - Voice calls with the IMS are not available , 1 - Voice calls with the IMS are available */	 
 } CiPsPrimSetImsVoiceCallAvailabilityReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetImsVoiceCallAvailabilityCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimSetImsVoiceCallAvailabilityCnf;

typedef CiEmptyPrim CiPsPrimGetImsVoiceCallAvailabilityReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetImsVoiceCallAvailabilityCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 UINT8 state ; /**< 0 - Voice calls with the IMS are not available , 1 - Voice calls with the IMS are available */	 
 } CiPsPrimGetImsVoiceCallAvailabilityCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetImsSmsAvailabilityReq_struct 
 {	 
 UINT8 state ; /**< 0 - SMS using IMS is not available , 1 - SMS using IMS is available */	 
 } CiPsPrimSetImsSmsAvailabilityReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetImsSmsAvailabilityCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimSetImsSmsAvailabilityCnf;

typedef CiEmptyPrim CiPsPrimGetImsSmsAvailabilityReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetImsSmsAvailabilityCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 UINT8 state ; /**< 0 - SMS using IMS is not available , 1 - SMS using IMS is available */	 
 } CiPsPrimGetImsSmsAvailabilityCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetMmImsVoiceTerminationReq_struct 
 {	 
 CiBoolean setting ; /**< If TRUE , Mobility Management for IMS Voice Termination disabled ; if FALSE , Mobility Management for IMS Voice Termination enabled \sa CCI API Ref Manual */	 
 } CiPsPrimSetMmImsVoiceTerminationReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetMmImsVoiceTerminationCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimSetMmImsVoiceTerminationCnf;

typedef CiEmptyPrim CiPsPrimGetMmImsVoiceTerminationReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetMmImsVoiceTerminationCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiBoolean setting ; /**< If TRUE , Mobility Management for IMS Voice Termination disabled ; if FALSE , Mobility Management for IMS Voice Termination enabled \sa CCI API Ref Manual */	 
 } CiPsPrimGetMmImsVoiceTerminationCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDefineDefaultPdpCtxReq_tag 
 {	 
 UINT8 modeType ; // 0 - not save to NVM , 1 - save to NUM ;	 
	 
 CiBoolean pdpTypePresent ;	 
 CiPsPdpType pdpType ;	 
 CiString apn ;	 
 CiBoolean emgIndPresent ;	 
 UINT8 emgInd ;	 
 CiBoolean ipcpReqPresent ;	 
 UINT8 ipcpReq ;	 
 CiBoolean pcscfIpv6ReqPresent ;	 
 UINT8 pcscfIpv6Req ;	 
 CiBoolean imcnSigPresent ;	 
 UINT8 imcnSig ;	 
 CiBoolean dnsIpv6Present ;	 
 UINT8 dnsIpv6 ;	 
 CiBoolean nwBearPresent ;	 
 UINT8 nwBear ;	 
 CiBoolean dsmIpv6HaPresent ;	 
 UINT8 dsmIpv6Ha ;	 
 CiBoolean dsmIpv6PrefPresent ;	 
 UINT8 dsmIpv6Pref ;	 
 CiBoolean dsmIpv6HaIpv4Present ;	 
 UINT8 dsmIpv6HaIpv4 ;	 
 CiBoolean ipViaNasPresent ;	 
 UINT8 ipViaNas ;	 
 CiBoolean ipViaDhcpPresent ;	 
 UINT8 ipViaDhcp ;	 
 CiBoolean pcscfIpv4Present ;	 
 UINT8 pcscfIpv4 ;	 
 CiBoolean dnsIpv4Present ;	 
 UINT8 dnsIpv4 ;	 
 CiBoolean msisdnPresent ;	 
 UINT8 msisdn ;	 
 CiBoolean ifomPresent ;	 
 UINT8 ifom ;	 
 CiBoolean v4mtuPresent ;	 
 UINT8 v4mtu ;	 
 CiBoolean localTftPresent ;	 
 UINT8 localTft ;	 
 CiBoolean etifPresent ;	 
 UINT8 etifFlag ;	 
 CiBoolean roamPdpTypePresent ; /*Lilei , CQ00113795 , 20190514 */	 
 CiPsPdpType roamPdpType ;	 
 } CiPsPrimDefineDefaultPdpCtxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimDefineDefaultPdpCtxCnf_tag 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimDefineDefaultPdpCtxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetDefaultPdpReq_Tag 
 {	 
 UINT8 modeType ; // 0 - current used , 1 - from NVM	 
 } CiPsPrimGetDefaultPdpReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetDefaultPdpCtx_tag 
 {	 
 UINT8 modeType ; // 0 - current used , 1 - from NVM	 
 CiString apn ;	 
 CiPsPdpType pdpType ;	 
 UINT8 emgInd ;	 
 UINT8 ipcpReq ;	 
 UINT8 pcscfIpv6Req ;	 
 UINT8 imcnSig ;	 
 UINT8 dnsIpv6 ;	 
 UINT8 nwBear ;	 
 UINT8 dsmIpv6Ha ;	 
 UINT8 dsmIpv6Pref ;	 
 UINT8 dsmIpv6HaIpv4 ;	 
 UINT8 ipViaNas ;	 
 UINT8 ipViaDhcp ;	 
 UINT8 pcscfIpv4 ;	 
 UINT8 dnsIpv4 ;	 
 UINT8 msisdn ;	 
 UINT8 ifom ;	 
 UINT8 v4mtu ;	 
 UINT8 localTft ;	 
 UINT8 etifFlag ;	 
 CiPsPdpType roamPdpType ; /*Lilei , CQ00113795 , 20190514 */	 
 } CiPsPrimGetDefaultPdpCtx;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetDefaultPdpCtxCnf_tag 
 {	 
 CiPsRc rc ;	 
 CiPsPrimGetDefaultPdpCtx pdpCtx ;	 
 } CiPsPrimGetDefaultPdpCtxCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetApnReq_Tag 
 {	 
 UINT8 wapn ; // which apn , 0 - no action , 1 - the first APN in apn table , 2 - the second APN , ....	 
 UINT8 apncl ; // APN class	 
	 
 CiString apnni ; // APN Network identifier	 
	 
 CiBoolean apnTypePresent ;	 
 UINT8 apnType ; // 0 - invalid , 1 - ipv4 , 2 - ipv6 , 3 - ipv4v6 // CiPsApnAddrType	 
	 
 CiBoolean apnBearPresent ;	 
 UINT8 apnBear ; // 0 - invalid , 1 - LTE // CiPsApnBearType	 
	 
 CiBoolean apnedPresent ;	 
 UINT8 apned ; // 0 - disable , 1 - enable	 
	 
 CiBoolean apnTimePresent ;	 
 UINT32 apnTime ;	 
 } CiPsPrimSetApnReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetApnCnf_tag 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimSetApnCnf;

typedef CiEmptyPrim CiPsPrimGetApnReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsApnInfo_tag 
 {	 
 UINT8 apncl ;	 
 UINT8 apnType ; // 0 - invalid , 1 - ipv4 , 2 - ipv6 , 3 - ipv4v6 // CiPsApnAddrType	 
 UINT8 apnBear ; // 0 - invalid , 1 - LTE // CiPsApnBearType	 
 UINT8 apned ; // 0 - disable , 1 - enable	 
 CiString apnni ;	 
 UINT32 apnTime ;	 
 } CiPsApnInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetApnCnf_Tag 
 {	 
 CiPsRc rc ; // UINT16 , 2 bytes	 
 UINT8 num ;	 
 CiPsApnInfo apnInfo [ 5 ] ;	 
 } CiPsPrimGetApnCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetImsRegStateReq_Tag 
 {	 
 UINT8 state ; /**< 0 - IMS de-registered , 1 - IMS registered , 2 - IMS Call Active*/	 
 } CiPsPrimSetImsRegStateReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetImsRegStateCnf_tag 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimSetImsRegStateCnf;

typedef UINT8 CiPsUeToImsEvent ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimUeEventToImsInd_tag 
 {	 
 CiPsUeToImsEvent ueEvent ; // 0 - SIM removed , 1 - IMS APN changed , 2 - other , 3 - T3346 start , 4 - T3346 expiry , 5 - T3346 stop , 6 -ERRC RELEASE.	 
 CiBoolean imsNeedDeReg ; // 0 - IMS not need to re-register , 1 - IMS need to de-register	 
 } CiPsPrimUeEventToImsInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimImsRegInfo_struct 
 {	 
 UINT8 regInfo ;	 
 UINT8 extInfo ;	 
 } CiPsPrimImsRegInfo;

typedef CiEmptyPrim CiPsPrimGetImsRegInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetImsRegInfoCnf_struct // +CIREG: <n> , <reg_info> , <ext_info> 
 {	 
 CiPsRc rc ;	 
 UINT8 reportState ;	 
 CiPsPrimImsRegInfo info ;	 
 } CiPsPrimGetImsRegInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetImsRegInfoIndReq_struct // AT+CIREG=n 
 {	 
 UINT8 reportState ;	 
 } CiPsPrimSetImsRegInfoIndReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetImsRegInfoIndCnf_struct // OK or false 
 {	 
 CiPsRc rc ;	 
 } CiPsPrimSetImsRegInfoIndCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimImsRegInfoInd_struct // +CIREGU: <reg_info> , <ext_info> 
 {	 
 UINT8 reportState ;	 
 CiPsPrimImsRegInfo newInfo ;	 
 } CiPsPrimImsRegInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetVoiceDomainPreferenceReq_struct 
 {	 
 CiBoolean eutran ; /**< If TRUE , E-UTRAN ; if FALSE , UTRAN \sa CCI API Ref Manual */	 
 CiPsVoiceDomainPreference setting ; /**< indicates the voice domain preference of the UE \sa CiPsVoiceDomainPreference */	 
 } CiPsPrimSetVoiceDomainPreferenceReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetVoiceDomainPreferenceCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimSetVoiceDomainPreferenceCnf;

typedef CiEmptyPrim CiPsPrimGetVoiceDomainPreferenceReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetVoiceDomainPreferenceCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 CiPsVoiceDomainPreference utran_setting ; /**< indicates the voice domain preference of the UE for UTRAN \sa CiPsVoiceDomainPreference */	 
 CiPsVoiceDomainPreference eutan_setting ; /**< indicates the voice domain preference of the UE for E-UTRAN \sa CiPsVoiceDomainPreference */	 
 } CiPsPrimGetVoiceDomainPreferenceCnf;

//ICAT EXPORTED ENUM 
 typedef enum CiPsEpsUsageSetting_Tag 
 {	 
 CIPS_EPS_VOICE_CENTRIC = 0 ,	 
 CIPS_EPS_DATA_CENTRIC ,	 
 CIPS_EPS_CENTRIC_NUM	 
 } _CiPsEpsUsageSetting;

typedef UINT8 CiPsEpsUsageSetting ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetEpsUsageSettingReq_struct 
 {	 
 CiPsEpsUsageSetting epsUsageSetting ; // 0 / 1	 
 } CiPsPrimSetEpsUsageSettingReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetEpsUsageSettingCnf_struct 
 {	 
 CiPsRc rc ;	 
 } CiPsPrimSetEpsUsageSettingCnf;

typedef CiEmptyPrim CiPsPrimGetEpsUsageSettingReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetEpsUsageSettingCnf_struct 
 {	 
 CiPsRc rc ;	 
 CiPsEpsUsageSetting epsUsageSetting ; // 0 / 1	 
 } CiPsPrimGetEpsUsageSettingCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetApUniversalSettingReq_struct 
 {	 
 CiBoolean enableDataStatePresent ;	 
 UINT8 enableDataState ; /**< State of Data enable setting. TRUE: enable ; FALSE: disable.\sa CCI API Ref Manual */	 
 } CiPsPrimSetApUniversalSettingReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetApUniversalSettingCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimSetApUniversalSettingCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetPsServiceDomainReq_struct 
 {	 
 CiBoolean psServiceEnable ; /**< State of Data enable setting. TRUE: enable ; FALSE: disable.\sa CCI API Ref Manual */	 
 } CiPsPrimSetPsServiceDomainReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetPsServiceDomainCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
 } CiPsPrimSetPsServiceDomainCnf;

typedef CiEmptyPrim CiPsPrimGetPsServiceDomainReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetPsServiceDomainCnf_struct 
 {	 
 CiBoolean psServiceEnable ; /**< State of Data enable setting. TRUE: enable ; FALSE: disable.\sa CCI API Ref Manual */	 
 } CiPsPrimGetPsServiceDomainCnf;

typedef UINT8 CiPsImsSrvType ;
typedef UINT8 CiPsImsSrvStatus ;
typedef UINT8 CiPsImsSrvFailCause ;
typedef UINT16 CiPsImsSrvCause ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetImsServiceStatusReq_struct 
 {	 
 CiPsImsSrvType imsSrvType ;	 
 CiPsImsSrvStatus imsSrvStatus ;	 
 CiPsImsSrvFailCause srvFailCause ;	 
 } CiPsPrimSetImsServiceStatusReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetImsServiceStatusCnf_struct 
 {	 
 CiPsRc rc ;	 
 CiPsImsSrvCause cause ;	 
 } CiPsPrimSetImsServiceStatusCnf;

typedef UINT16 CiPsSuspendCause ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSuspendResumeInd_struct 
 {	 
 CiBoolean suspended ; // 0 - resume , 1 - suspended	 
 CiPsSuspendCause suspendReason ;	 
 } CiPsPrimSuspendResumeInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimChapAuthenticateReq_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier. 0xFF for LTE attach PDN ; others for MO */	 
 CiStringExt challenge ; /**< CHAP challenge octets */	 
 CiStringExt response ; /**< CHAP response octets */	 
 } CiPsPrimChapAuthenticateReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimChapAuthenticateCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimChapAuthenticateCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimActivateReconfigPdpCtxReq_struct 
 {	 
 CiPsPdpCtx pdpCtx ; /**< PDP context definition \sa CiPsPdpCtx_struct */	 
 CiBoolean authInfoPresent ;	 
 CiPsAuthenticationType authenticationType ; /**< Authentication type. \sa CiPsAuthenticationType */	 
 CiStringExt userName ; /**< UserName octets. \sa CCI API Ref Manual */	 
 CiStringExt password ; /**< Password octets. \sa CCI API Ref Manual */	 
 } CiPsPrimActivateReconfigPdpCtxReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimActivateReconfigPdpCtxCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimActivateReconfigPdpCtxCnf;

typedef UINT8 CiPsPsmModeType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetPsmConfigReq_struct 
 {	 
 CiPsPsmModeType mode ; /**< Indication to disable or enable the use of PSM in the UE */	 
	 
 CiBoolean requestedPeriodRauPresent ;	 
 UINT8 requestedPeriodRau ; /** <not used , set to 0 */	 
 CiBoolean requestedGprsReadyTimerPresent ;	 
 UINT8 requestedGprsReadyTimer ; /** <not used , set to 0 */	 
	 
 CiBoolean requestedPeriodicTauPresent ;	 
 UINT8 requestedPeriodicTau ; /** <requested T3412 timer value , one byte in an 8 bit format */	 
 CiBoolean requestedActiveTimePresent ;	 
 UINT8 requestedActiveTime ; /** <requested T3324 timer value , one byte in an 8 bit format */	 
 } CiPsPrimSetPsmConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetPsmConfigCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimSetPsmConfigCnf;

typedef CiEmptyPrim CiPsPrimGetPsmConfigReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetPsmConfigCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
	 
 CiPsPsmModeType mode ; /**< Indication to disable or enable the use of PSM in the UE */	 
	 
 CiBoolean requestedPeriodRauPresent ;	 
 UINT8 requestedPeriodRau ; /** <not used , set to 0 */	 
 CiBoolean requestedGprsReadyTimerPresent ;	 
 UINT8 requestedGprsReadyTimer ; /** <not used , set to 0 */	 
	 
 CiBoolean requestedPeriodicTauPresent ;	 
 UINT8 requestedPeriodicTau ; /** <requested T3412 timer value , one byte in an 8 bit format */	 
 CiBoolean requestedActiveTimePresent ;	 
 UINT8 requestedActiveTime ; /** <requested T3324 timer value , one byte in an 8 bit format */	 
 } CiPsPrimGetPsmConfigCnf;

typedef UINT8 CiPsEdrxModeType ;
typedef UINT8 CiPsEdrxActType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetEdrxConfigReq_struct 
 {	 
 CiPsEdrxModeType mode ; /**< indicates to disable or enable the use of eDRX in the UE */	 
	 
 CiPsEdrxActType eDrxAct ; /**< indicates the type of access technology */	 
 CiBoolean requestedEdrxValuePresent ;	 
 UINT8 requestedEdrxValue ; /** <requested eDRX value , half a byte in a 4 bit format */	 
 } CiPsPrimSetEdrxConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetEdrxConfigCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimSetEdrxConfigCnf;

typedef CiEmptyPrim CiPsPrimGetEdrxConfigReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetEdrxConfigCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
	 
 CiPsEdrxActType eDrxAct ; /**< indicates the type of access technology */	 
 CiBoolean requestedEdrxValuePresent ;	 
 UINT8 requestedEdrxValue ; /** <requested eDRX value , half a byte in a 4 bit format */	 
 } CiPsPrimGetEdrxConfigCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimEdrxInfoInd_struct 
 {	 
 CiPsEdrxActType eDrxAct ; /**< indicates the type of access technology */	 
	 
 CiBoolean requestedEdrxValuePresent ;	 
 UINT8 requestedEdrxValue ; /** <requested eDRX value , half a byte in a 4 bit format */	 
	 
 CiBoolean nwProvidedEdrxvaluePresent ;	 
 UINT8 nwProvidedEdrxvalue ; /** <NW-provided eDRX value , half a byte in a 4 bit format */	 
 CiBoolean pagingTimerWindowPresent ;	 
 UINT8 pagingTimerWindow ; /** <NW-provided paing time window , half a byte in a 4 bit format */	 
 } CiPsPrimEdrxInfoInd;

typedef CiEmptyPrim CiPsPrimReadEdrxDynParaReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimReadEdrxDynParaCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
	 
 CiPsEdrxActType eDrxAct ; /**< indicates the type of access technology */	 
	 
 CiBoolean requestedEdrxValuePresent ;	 
 UINT8 requestedEdrxValue ; /** <requested eDRX value , half a byte in a 4 bit format */	 
	 
 CiBoolean nwProvidedEdrxvaluePresent ;	 
 UINT8 nwProvidedEdrxvalue ; /** <NW-provided eDRX value , half a byte in a 4 bit format */	 
 CiBoolean pagingTimerWindowPresent ;	 
 UINT8 pagingTimerWindow ; /** <NW-provided paing time window , half a byte in a 4 bit format */	 
 } CiPsPrimReadEdrxDynParaCnf;

typedef UINT8 CiPsCiotOption ;
typedef UINT8 CiPsCiotSupportedUeOpt ;
typedef UINT8 CiPsCiotPreferUeOpt ;
typedef UINT8 CiPsCiotSupportedNwOpt ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetCiotConfigReq_struct 
 {	 
 CiPsCiotOption option ; /**< Enables or disables reporting of unsolicated result codes +CCIOTOPTI */	 
 CiPsCiotSupportedUeOpt supportedUeOpt ; /**< indicates the UE ' s support for CIoT EPS optimization */	 
 CiPsCiotPreferUeOpt preferUeOpt ; /**< indicates the UE ' s preference for CIoT EPS optimization */	 
 } CiPsPrimSetCiotConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetCiotConfigCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimSetCiotConfigCnf;

typedef CiEmptyPrim CiPsPrimGetCiotConfigReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetCiotConfigReq_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
	 
 CiPsCiotOption option ; /**< Enables or disables reporting of unsolicated result codes +CCIOTOPTI */	 
 CiPsCiotSupportedUeOpt supportedUeOpt ; /**< indicates the UE ' s support for CIoT EPS optimization */	 
 CiPsCiotPreferUeOpt preferUeOpt ; /**< indicates the UE ' s preference for CIoT EPS optimization */	 
 } CiPsPrimGetCiotConfigCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimCiotNwInfoInd_struct 
 {	 
 CiPsCiotSupportedNwOpt supportedNwOpt ; /**< indicates the Network support for CIoT EPS optimization */	 
 } CiPsPrimCiotNwInfoInd;

typedef UINT8 CiPsSignallingConnectionOpt ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimConfigSignallingConnectionReq_struct 
 {	 
 CiPsSignallingConnectionOpt option ; /**< Enables or disables reporting of unsolicated result codes +CCIOTOPTI */	 
 } CiPsPrimConfigSignallingConnectionReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimConfigSignallingConnectionCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimConfigSignallingConnectionCnf;

typedef UINT8 CiPsCsconMode ;
typedef UINT8 CiPsCsconState ;
typedef UINT8 CiPsCsconAccess ;
typedef CiEmptyPrim CiPsPrimGetSignallingConnectionStatusReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetSignallingConnectionStatusCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
	 
 CiPsSignallingConnectionOpt option ; /**< Enables or disables reporting of unsolicated result codes +CCIOTOPTI */	 
 CiPsCsconMode mode ; /**<indicates the signalling connection satus */	 
	 
 CiBoolean statePresent ;	 
 CiPsCsconState state ; /**<indicates the CS or PS state while in GERAN and the RRC state information if the MTis in connected mode while in UTRAN and E-UTRAN */	 
	 
 CiBoolean accessPresent ;	 
 CiPsCsconAccess access ; /**<indicates the current radio access type */	 
 } CiPsPrimGetSignallingConnectionStatusCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSignallingConnectionInd_struct 
 {	 
 CiPsCsconMode mode ; /**<indicates the signalling connection satus */	 
	 
 CiBoolean statePresent ;	 
 CiPsCsconState state ; /**<indicates the CS or PS state while in GERAN and the RRC state information if the MTis in connected mode while in UTRAN and E-UTRAN */	 
	 
 CiBoolean accessPresent ;	 
 CiPsCsconAccess access ; /**<indicates the current radio access type */	 
 } CiPsPrimSignallingConnectionInd;

typedef UINT8 CiPsEpsAttachwithPdnOpt ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetInitialPdpActivationOptReq_struct 
 {	 
 UINT8 option ; /**<Activation of PDP context upon attach , only used for 2 / 3 G , 0 - Do not activate , 1 - Always activate , 2 - Activate when not roaming , 3 - No change in current setting only for EUTRAN */	 
 CiPsEpsAttachwithPdnOpt attachWithoutPdn ; /**< EPS attach with or without PDN connection */	 
 } CiPsPrimSetInitialPdpActivationOptReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetInitialPdpActivationOptCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimSetInitialPdpActivationOptCnf;

typedef CiEmptyPrim CiPsPrimGetInitialPdpActivationOptReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetInitialPdpActivationOptCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
	 
 UINT8 option ; /**<Activation of PDP context upon attach , only used for 2 / 3 G , 0 - Do not activate , 1 - Always activate , 2 - Activate when not roaming , 3 - No change in current setting only for EUTRAN */	 
 CiPsEpsAttachwithPdnOpt attachWithoutPdn ; /**< EPS attach with or without PDN connection */	 
 } CiPsPrimGetInitialPdpActivationOptCnf;

typedef UINT8 CiPsApnBackoffTimerOpt ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetApnBackoffTimerStatusReq_struct 
 {	 
 CiPsApnBackoffTimerOpt option ; /**< 0 - Disable presentation of the unsolicited result code , 1 -Enable presentation of the unsolicited result code */	 
 } CiPsPrimSetApnBackoffTimerStatusReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetApnBackoffTimerStatusCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 } CiPsPrimSetApnBackoffTimerStatusCnf;

typedef CiEmptyPrim CiPsPrimGetApnBackoffTimerStatusReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetApnBackoffTimerStatusCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
	 
 CiPsApnBackoffTimerOpt option ; /**< 0 - Disable presentation of the unsolicited result code , 1 -Enable presentation of the unsolicited result code */	 
 } CiPsPrimGetApnBackoffTimerStatusCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimApnBackoffTimerStatusReportInd_struct 
 {	 
 CiString apn ;	 
	 
 UINT32 eventType ; /**< 0 - the back-off timer is started , 1 -the backoff timer is stopped , 2 -the back-off timer is expired */	 
 UINT32 backoffTimerValue ; /**< Indicate the residual back-off timer value , in second */	 
	 
 CiBoolean reAttempPresent ;	 
 UINT8 reAttemptRatIndication ; /**< 0 - Re-attempt the seeion management afert inter-system change is allowed , 1 - not allowed , now no need to support it */	 
 UINT8 reAttemptEplmnIndication ; /**<0- Re-attempt the session management in an EPLMN is allowed , 1 - not allowed */	 
	 
 CiBoolean nslpiPresent ;	 
 UINT8 nslpi ; /**< 0 -Indicates that this PDN connection was set to " MS is configured for NAS signalling low priority " , 1 - set to " MS is not configured for NAS signalling low priority " */	 
 UINT8 procedure ; /**<0-all procedures , 1 -PDN connectivity proc , 2 -bearer resource allocation proc , 3 -bearer resource modification proc ,	 
 4 -PDP activation proc , 5 -secondary PDP activation proc , 6 -PDP modification proc */	 
 } CiPsPrimApnBackoffTimerStatusReportInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsApnBackoffTimerInfo_struct 
 {	 
 CiString apn ;	 
	 
 UINT32 backoffTimerValue ; /**< Indicate the residual back-off timer value , in second */	 
	 
 CiBoolean reAttempPresent ;	 
 UINT8 reAttemptRatIndication ; /**< 0 - Re-attempt the seeion management afert inter-system change is allowed , 1 - not allowed , now no need to support it. */	 
 UINT8 reAttemptEplmnIndication ; /**<0- Re-attempt the session management in an EPLMN is allowed , 1 - not allowed */	 
	 
 CiBoolean nslpiPresent ;	 
 UINT8 nslpi ; /**< 0 -Indicates that this PDN connection was set to " MS is configured for NAS signalling low priority " , 1 - set to " MS is not configured for NAS signalling low priority " */	 
 UINT8 procedure ; /**<0-all procedures , 1 -PDN connectivity proc , 2 -bearer resource allocation proc , 3 -bearer resource modification proc ,	 
 4 -PDP activation proc , 5 -secondary PDP activation proc , 6 -PDP modification proc */	 
 } CiPsApnBackoffTimerInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimReadApnBackoffTimerDynParaReq_struct 
 {	 
 CiBoolean apnPresent ; /**< if it is omitted , all APNs associated with back-off timers in the current RAT and PLMN combination is returned */	 
 CiString apn ;	 
 } CiPsPrimReadApnBackoffTimerDynParaReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimReadApnBackoffTimerDynParaCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
	 
 UINT8 num ; /**< Number of apn backoff timer info */	 
 CiPsApnBackoffTimerInfo list [ 10 ] ;	 
 } CiPsPrimReadApnBackoffTimerDynParaCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsApnRateCtrlnfo_struct 
 {	 
 UINT8 addExceptionReports ; /**< 0 - Additional_exception_reportes at max rate reached are not allowed to be sent , 1 - allowed. */	 
 UINT8 ulTimeUnit ; /**<0 -unrestricted , 1 -minute , 2 -hour , 3 -day , 4 - week */	 
 UINT32 maxUlRate ; /**< specifies the time unit to be used for the max uplink rate */	 
 } CiPsApnRateCtrlnfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetApnRateControlReq_struct 
 {	 
 CiBoolean cidPresent ; /**< if the parameter<cid> is omitted , the APN rate control parameters for all active PDP contexs are returned */	 
 UINT8 cid ;	 
 } CiPsPrimGetApnRateControlReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetApnRateControlCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
	 
 UINT8 num ;	 
 UINT8 cid [ ( 8 ) ] ; /**< PDP context identifier [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiPsApnRateCtrlnfo list [ ( 8 ) ] ;	 
 } CiPsPrimGetApnRateControlCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetPdpContextInfoReq_struct 
 {	 
 UINT8 cid ; /**< PDP context identifier */	 
 } CiPsPrimGetPdpContextInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimGetPdpContextInfoCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code \sa CiPsRc */	 
	 
 UINT8 cid ; /**< PDP context identifier , [ 0 - CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1 ] */	 
 CiBoolean ctxValid ; /**< TRUE: if present , only for activated PDP */	 
	 
 CiPsPdpType type ; /**< PDP type \sa CiPsPdpType */	 
 UINT8 bearerId ; /**< Bearer id or NSAPI , 5 ~15 */	 
 CiPsPdpBearType pdpBearType ; /**< 0 - invalid , 1 - primary / default PDP , 2 - dedicated / secondary PDP */	 
 UINT8 p_cid ; /**< 255 - invalid */	 
 UINT8 linked_bearerId ; /**< Linded Bearer id , 5 ~15 , 0 - invalid */	 
	 
 CiBoolean apnPresent ; /**< Flag indicating that the APN is present ( optional field ) \sa CCI API Ref Manual*/	 
 CiString apn ; /**< APN , length range [ CI_PS_APN_MIN_SIZE - CI_PS_APN_MAX_SIZE ] . \sa CCI API Ref Manual */	 
	 
 CiPsPdpIpAddr ipv4Addr ; /**< PDP address \sa CiPsPdpAddr_struct */	 
 CiPsPdpIpAddr ipv6Addr ;	 
	 
 CiBoolean negEpsQosAvailable ; /**< 4 G QoS profile */	 
 CiPs4GQosProfile negEpsQosProfile ;	 
	 
 CiBoolean neg3gQosAvailable ; /**< 3 G QoS profile */	 
 CiPs3GQosProfile neg3gQosProfile ;	 
	 
 UINT8 dnsAddrNum ; /**< DNS address */	 
 CiPsPdpIpAddr dnsAddr [ 4 ] ;	 
 } CiPsPrimGetPdpContextInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetPdpCtxRemapReq_struct 
 {	 
 CiBoolean state ; /**< State of activation / deactivation. TRUE: activate ; FALSE: deactivate. */	 
 UINT8 cid ; /**< PDP context identifier to activate / deactivate*/	 
 UINT8 cidRemap ; /**< PDP context identifier to remap from when activate , or remap back to when deactivate */	 
 CiPsPdpType type ; /**< PDP type */	 
 CiBoolean apnPresent ;	 
 CiString apn ;	 
 CiBoolean authInfoPresent ;	 
 CiPsAuthenticationType authenticationType ; /**< Authentication type. */	 
 CiStringExt userName ; /**< UserName octets. */	 
 CiStringExt password ; /**< Password octets. */	 
 } CiPsPrimSetPdpCtxRemapReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiPsPrimSetPdpCtxRemapCnf_struct 
 {	 
 CiPsRc rc ; /**< Result code. \sa CiPsRc */	 
 UINT8 cid ; /**< PDP context identifier to activate / deactivate*/	 
 UINT8 cidRemap ; /**< PDP context identifier to remap from when activate , or remap back to when deactivate */	 
 } CiPsPrimSetPdpCtxRemapCnf;

//ICAT EXPORTED ENUM 
 typedef enum CI_MM_PRIM 
 {	 
 CI_MM_PRIM_GET_NUM_SUBSCRIBER_NUMBERS_REQ = 1 , /**< \brief Requests the number of subscriber number entries in the MSISDN list \details */	 
 CI_MM_PRIM_GET_NUM_SUBSCRIBER_NUMBERS_CNF , /**< \brief Confirms the request to return the number of subscriber number entries in the MSISDN list \details Requires the SIM to be inserted and ready , plus prior PIN1 validation. */	 
 CI_MM_PRIM_GET_SUBSCRIBER_INFO_REQ , /**< \brief Requests subscriber information for a specified entry in the MSISDN list \details This information is stored on the SIM , so for this request to succeed , the SIM must be inserted and ready.	 
 * Access to the MSISDN list requires prior PIN1 ( CHV1 ) validation.	 
 * Use the CI_MM_PRIM_GET_NUM_SUBSCRIBER_NUMBERS_REQ to determine the number of MSISDN list entries. */	 
 CI_MM_PRIM_GET_SUBSCRIBER_INFO_CNF , /**< \brief Confirms the request to return subscriber information for a specified entry in the MSISDN list \details */	 
 CI_MM_PRIM_GET_SUPPORTED_REGRESULT_OPTIONS_REQ , /**< \brief Requests the supported settings for the unsolicited network registration reporting option \details */	 
 CI_MM_PRIM_GET_SUPPORTED_REGRESULT_OPTIONS_CNF , /**< \brief Confirms the request to return the supported settings for the unsolicited network registration reporting option \details There should be no reason for an error result. */	 
 CI_MM_PRIM_GET_REGRESULT_OPTION_REQ , /**< \brief Requests the current reporting option for Unsolicited Network Registration Result Indications \details See CI_MM_PRIM_SET_REGRESULT_OPTION for default information. */	 
 CI_MM_PRIM_GET_REGRESULT_OPTION_CNF , /**< \brief Confirms the request to return the current reporting option for Unsolicited Network Registration Result Indications \details There should be no reason for an error result. */	 
 CI_MM_PRIM_SET_REGRESULT_OPTION_REQ , /**< \brief Request to set the reporting option for Unsolicited Network Registration Result Indications \details Unsolicited Registration Result Indications ( CI_MM_PRIM_REG_RESULT_IND ) are sent ( if enabled ) only if the reported information	 
 * has changed since the last indication.	 
 * CIMM_REGRESULT_STATUS is the default reporting option. */	 
 CI_MM_PRIM_SET_REGRESULT_OPTION_CNF = 10 , /**< \brief Confirms a request to set the reporting option for Unsolicited Network Registration Result Indications \details */	 
 CI_MM_PRIM_REGRESULT_IND , /**< \brief Indicates the Unsolicited Network Registration Result \details Receipt of this indication ( and the information it contains ) can be configured by the	 
 * CI_MM_PRIM_SET_REGRESULT_OPTION_REQ request.	 
 * If this indication is enabled , the current registration status ( if available ) is reported.	 
 * As a configuration option , current cell information ( if available ) can also be included.	 
 * This information can also be requested at any time , using the CI_CC_PRIM_GET_REGRESULT_INFO_REQ request.	 
 * No explicit response is required. */	 
 CI_MM_PRIM_GET_REGRESULT_INFO_REQ , /**< \brief Requests the most recent registration result information \details See CI_MM_PRIM_SET_REGRESULT_OPTION for default information. */	 
 CI_MM_PRIM_GET_REGRESULT_INFO_CNF , /**< \brief Confirms the request to return the most recent registration result information \details Use the CI_MM_PRIM_GET_REGRESULT_OPTION_REQ request to get the current registration result reporting option.	 
 * This option setting may affect the availability of registration result information.	 
 * The current registration status and location information ( if available ) are included. */	 
 CI_MM_PRIM_GET_SUPPORTED_ID_FORMATS_REQ , /**< \brief Requests a list of supported format indicators for the network / operator ID information	 
 * \details These format indicators are used in the CiMmNetOpIdInfo structure , to indicate how SAC should format the network or operator	 
 * identification information. */	 
 CI_MM_PRIM_GET_SUPPORTED_ID_FORMATS_CNF , /**< \brief Confirms the request and returns a list of supported format indicators for the network / operator ID information	 
 * \details There should be no reason for an error result. */	 
 CI_MM_PRIM_GET_ID_FORMAT_REQ , /**< \brief Requests the currently selected network operator ID format indicator \details The network operator ID format indicator selects which of the supported formats SAC will use to represent the network / operator ID. */	 
 CI_MM_PRIM_GET_ID_FORMAT_CNF , /**< \brief Confirms the request to return the currently selected network operator ID format indicator \details There should be no reason for an error result. */	 
 CI_MM_PRIM_SET_ID_FORMAT_REQ , /**< \brief Requests to set the network / operator ID format indicator \details The network operator ID format indicator selects which of the supported formats SAC will use to represent the network / operator ID	 
 * when reporting network operator information. The default format indicator is set for a numeric network ID. */	 
 CI_MM_PRIM_SET_ID_FORMAT_CNF , /**< \brief Confirms the request to set the network / operator ID format indicator \details */	 
 CI_MM_PRIM_GET_NUM_NETWORK_OPERATORS_REQ = 20 , /**< \brief Requests the number of operators present in the network \details */	 
 CI_MM_PRIM_GET_NUM_NETWORK_OPERATORS_CNF , /**< \brief Confirms the request to get the number of operators present in the network \details */	 
 CI_MM_PRIM_GET_NETWORK_OPERATOR_INFO_REQ , /**< \brief Requests information about a specified operator present in the network \details Use CI_CC_PRIM_GET_NUM_NETWORK_OPERATORS_REQ to determine the number of operators present in the network ,	 
 * if there are any. This number determines the range of values for the Index parameter.	 
 * Index values start at 1 , which indicates the first operator in the network ( usually the home network operator ) . */	 
 CI_MM_PRIM_GET_NETWORK_OPERATOR_INFO_CNF , /**< \brief Confirms the request to get information about a specified operator present in the network \details There may be no operators currently present in the network. In that case , the network operator status information is not	 
 * included.	 
 * Status for network operators present should be indexed in the following order of precedence ( with the highest precedence listed first ) :	 
 * Home network operator ( if present )	 
 * Operators for networks that are referenced in the SIM	 
 * Other network operators that are present	 
 * The network and operator ID information is presented in all supported formats. If information for any of the formats is unavailable , SAC indicates this in the CiMmNetOpStatusInfo structure as follows:	 
 * Unavailable operator ID has its Length field set to zero.	 
 * Unavailable network ID has its fields set to CIMM_COUNTRYCODE_NONE and CIMM_NETWORKCODE_NONE. */	 
 CI_MM_PRIM_GET_NUM_PREFERRED_OPERATORS_REQ , /**< \brief Requests the number of entries in the preferred network operators list \details The preferred network operators list is stored on the SIM in the EFPLMNSel file.	 
 * The maximum number of entries in the EFPLMNSel file is specified when the SIM is provisioned , but the file must accommodate at least	 
 * 8 PLMN entries. See [ 1 ] for more information. */	 
 CI_MM_PRIM_GET_NUM_PREFERRED_OPERATORS_CNF , /**< \brief Confirms the request to get the number of entries in the preferred network operators list \details If the SIM is not present and ready , SAC sets the NumPref parameter to zero. */	 
 CI_MM_PRIM_GET_PREFERRED_OPERATOR_INFO_REQ , /**< \brief Requests information for a specified entry in the preferred network operators list \details Use CI_CC_PRIM_GET_NUM_PREFERRED_OPERATORS_REQ to determine the number of entries in the preferred network	 
 * operators list. This number determines the range of values for the Index parameter.	 
 * The preferred operator list is stored in the EFPLMNSel file on the SIM , and requires the Card Holder Verification password CHV1	 
 * ( if enabled ) to be established before access to this file is allowed.	 
 * The maximum number of entries in the EFPLMNSel file is specified when the SIM is provisioned , but the file must accommodate at least	 
 * 8 PLMN entries. See [ 1 ] for more information. */	 
 CI_MM_PRIM_GET_PREFERRED_OPERATOR_INFO_CNF , /**< \brief Confirms the request to get information for a specified entry in the preferred network operators list	 
 * \details The network / operator ID information is presented in the default format , or in the format set by the most recent	 
 * CI_CC_PRIM_SET_ID_FORMAT_REQ request. */	 
 CI_MM_PRIM_ADD_PREFERRED_OPERATOR_REQ , /**< \brief Requests a new entry to be added to the preferred network operators list \details Adds a new entry to the end of the Preferred Operators List.	 
 * The Preferred Operators List is stored in the EFPLMNSel file on the SIM , and requires a Card Holder Verification password CHV1	 
 * ( if enabled ) to be established before access to this file is allowed. */	 
 CI_MM_PRIM_ADD_PREFERRED_OPERATOR_CNF , /**< \brief Confirms a request to add a new entry to the preferred network operators list \details The network / operator ID information must be presented in the default format , or in the format set by the most recent CI_CC_PRIM_SET_ID_FORMAT_REQ request.	 
 * If the request fails , the list is unchanged. The maximum number of entries in the EFPLMNSel file is specified when the SIM is	 
 * provisioned , but the file must accommodate at least 8 PLMN entries. See [ 1 ] for more information.	 
 * The number of entries in the list is returned regardless of the success / failure of the request. */	 
 CI_MM_PRIM_DELETE_PREFERRED_OPERATOR_REQ = 30 , /**< \brief Requests an entry to be deleted from the preferred network operators list \details Use CI_CC_PRIM_GET_NUM_PREFERRED_OPERATORS_REQ to determine the number of entries in the preferred network	 
 * operators list. This number determines the range of values for the Index parameter.	 
 * The preferred operator list is stored in the EFPLMNSel file on the SIM , and requires a Card Holder Verification password CHV1	 
 * ( if enabled ) to be verified before access to this file is allowed. */	 
 CI_MM_PRIM_DELETE_PREFERRED_OPERATOR_CNF , /**< \brief Confirms a request to delete an entry from the preferred network operators list \details If the request fails , the list is unchanged.	 
 * The maximum number of entries in the EFPLMNSel file is specified when the SIM is provisioned , but the file must accommodate at	 
 * least 8 PLMN entries. See " Cellular Interface Application Programming Interface " , revision i0.6 , for more information.	 
 * The number of entries in the list is returned regardless of the success / failure of the request. */	 
 CI_MM_PRIM_GET_CURRENT_OPERATOR_INFO_REQ , /**< \brief Requests information about the current network operator ( if there is one ) \details */	 
 CI_MM_PRIM_GET_CURRENT_OPERATOR_INFO_CNF , /**< \brief Confirms the request to get information about the current network operator ( if there is one ) \details */	 
	 
 CI_MM_PRIM_AUTO_REGISTER_REQ , /**< \brief Requests automatic registration \details Uses PLNM lists stored on the SIM , so an installed SIM is required.	 
 * The handset is always in automatic PLMN selection mode , except when a manual registration request is received.	 
 * After completing a manual registration operation , SAC resets the registration mode to automatic. Therefore , the application layer	 
 * does not need to use this request to reset the current registration mode to automatic.	 
 * The PLMN selection mode ( registration mode ) is not saved to NVRAM ; it is always set to automatic mode during SAC initialization. */	 
 CI_MM_PRIM_AUTO_REGISTER_CNF , /**< \brief Confirms a request for automatic registration \details */	 
 CI_MM_PRIM_MANUAL_REGISTER_REQ , /**< \brief Requests manual registration \details The registration result itself is relayed by a CI_MM_PRIM_REGRESULT_IND indication. It can also be retrieved on demand , using	 
 * the CI_MM_PRIM_GET_REGRESULT_INFO_REQ request.	 
 * On successful completion of this request , SAC resets the registration mode to CIMM_REGMODE_AUTOMATIC. */	 
 CI_MM_PRIM_MANUAL_REGISTER_CNF , /**< \brief Confirms a request for manual registration \details The registration result is relayed by CI_MM_PRIM_REGRESULT_IND , if this is enabled. The information can also	 
 * be retrieved on demand , using CI_MM_PRIM_GET_REGRESULT_INFO_REQ.	 
 * On successful completion of this request , SAC resets the current registration mode to automatic. */	 
 CI_MM_PRIM_DEREGISTER_REQ , /**< \brief Requests deregistration \details */	 
 CI_MM_PRIM_DEREGISTER_CNF , /**< \brief Confirms a request for deregistration \details The deregistration result is relayed by CI_MM_PRIM_REGRESULT_IND. It can also be retrieved on demand , using	 
 * CI_MM_PRIM_GET_REGRESULT_INFO_REQ. */	 
 CI_MM_PRIM_GET_SIGQUALITY_IND_CONFIG_REQ = 40 , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_MM_PRIM_GET_SIGQUALITY_IND_CONFIG_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_MM_PRIM_SET_SIGQUALITY_IND_CONFIG_REQ , /**< \brief Requests the current configuration for unsolicited signal quality indications \details Unsolicited signal quality indications can be configured in one of two ways:	 
 * - Report signal quality information periodically. The time interval is specified in 100 ms units.	 
 * - Report signal quality information when the RSS changes by more than a specified threshold. The threshold is specified in dBm.	 
 * These two configuration options are mutually exclusive. */	 
 CI_MM_PRIM_SET_SIGQUALITY_IND_CONFIG_CNF , /**< \brief Confirms a request to set the current configuration for unsolicited signal quality indications \details */	 
 CI_MM_PRIM_SIGQUALITY_INFO_IND , /**< \brief Indicates the unsolicited signal quality \details This indication can be configured by CI_MM_PRIM_SET_SIGQUALITY_IND_CONFIG_REQ.	 
 * The RSS value is reported in dBm , and should be in the range -113dBm through -51 dBm.	 
 * The bit error rate ( BER ) is reported as an encoded value between 0 and 7 . The upper layers should convert this value to a suitable	 
 * BER representation.	 
 * No explicit response is required. */	 
	 
 /*Modified by xwzhou for CQ on 8052013 , begin*/	 
 CI_MM_PRIM_EXTENDED_SIGQUALITY_INFO_IND , // add by xwzhou	 
 /*Modified by xwzhou for CQ on 8052013 , end*/	 
 // SCR #1401348	 
 CI_MM_PRIM_ENABLE_NETWORK_MODE_IND_REQ , /**< \brief Requests that network mode indication be enabled or disabled \details The network mode indication ( if enabled ) is sent whenever the current network mode changes.	 
 * By default , the network mode indication is disabled. */	 
 CI_MM_PRIM_ENABLE_NETWORK_MODE_IND_CNF , /**< \brief Confirms a request to enable or disable network mode indication. \details By default , the network mode indication is disabled. */	 
 CI_MM_PRIM_NETWORK_MODE_IND , /**< \brief Indicates the current network mode \details Each of the CiMmNetworkMode parameters indicates the PDP status for their indicated system:	 
 * - gprsActive ( 1 - gprs is active , 0 - gprs is inactive )	 
 * - egprsActive ( 1 - egprs is active , 0 - egprs is inactive )	 
 * - hsdpaActive ( 1 - hsdpa is active , 0 - hsdpa is inactive )	 
 * - hsupaActive ( 1 - hsupa is active , 0 - hsupa is inactive )	 
 * This indication can be enabled or disabled by CI_MM_PRIM_ENABLE_NETWORK_MODE_IND_REQ.	 
 * By default , this indication is disabled.	 
 * No explicit response is required. */	 
 CI_MM_PRIM_GET_NITZ_INFO_REQ , /**< \brief Requests the current network identity and time zone ( NITZ ) information	 
 * \details NITZ information is updated by the protocol stack whenever it changes , for example , when acquiring or re-acquiring network service. */	 
 CI_MM_PRIM_GET_NITZ_INFO_CNF = 50 , /**< \brief Confirms a request for current network identity and time zone ( NITZ ) information \details */	 
 CI_MM_PRIM_NITZ_INFO_IND , /**< \brief Indicates the status of the current network identity and time zone ( NITZ ) information	 
 * \details NITZ information is reported by the protocol stack whenever it changes , for example , when acquiring or re-acquiring network service.	 
 * NITZ indications are enabled by default. */	 
	 
 CI_MM_PRIM_CIPHERING_STATUS_IND , /**< \brief Indicates a ciphering status change \details	 
 * The protocol stack sends a cipher indication signal to the application layer	 
 * specifying the CS and PS ciphering status. SAC captures this signal and sends a	 
 * ' CiMmPrimCipheringStatusInd ' notification.	 
 * The authentication and ciphering procedure is always initiated and controlled by the network.	 
 * The following events trigger a cipher notification:	 
 * - A request by the network to authenticate and / or set the ciphering mode	 
 * - GPRS authenticate confirmation from the SIM	 
 * - Processing the authentication result	 
 * - Failure to release a CS connection	 
 * - Invalidating the GPRS parameters that are stored on the SIM and	 
 * marking the SIM as invalid for GPRS services	 
 * - Receiving a SYNC signal indicating ciphering mode setting or some channel assignment or modification	 
 *	 
 * An additional parameter is needed to indicate if display of	 
 * the ciphering indicator is required. This parameter is provided in the	 
 * OFM bit ( first bit ) of the ' additional information ' entry ( bytes 2 and 3 ) of the EF_AD ( administrative	 
 * data ) SIM / USIM file.	 
 */	 
 CI_MM_PRIM_AIR_INTERFACE_REJECT_CAUSE_IND , /**< \brief Indicates an air interface reject cause code \details	 
 * The protocol stack sends an air interface reject cause code indication due to errors that	 
 * can occur during MM / GMM procedures such as LU / RA update reject , authentication reject , etc.	 
 * These reject codes are intended to enable vendors to give specific visual / audible feedback to the user.	 
 */	 
 /* Michal Bukai - Selection of preferred PLMN list +CPLS - START */	 
 CI_MM_PRIM_SELECT_PREFERRED_PLMN_LIST_REQ , /**< \brief Requests to select the preferred PLMN list	 
 * \details The selected preffered PLMN list will be used when operation on the list is required */	 
 CI_MM_PRIM_SELECT_PREFERRED_PLMN_LIST_CNF , /**< \brief Confirms the request to select a preferred PLMN list */	 
 CI_MM_PRIM_GET_PREFERRED_PLMN_LIST_REQ , /**< \brief Requests to read what is the selected preferred PLMN list */	 
 CI_MM_PRIM_GET_PREFERRED_PLMN_LIST_CNF , /**< \brief Confirms the response and returns the type of the selected preferred PLMN list */	 
 /* Michal Bukai - Selection of preferred PLMN list +CPLS - END */	 
 CI_MM_PRIM_BANDIND_IND , /**< \brief Indicates the current band	 
 * \details Indications are sent when the band changes and band indications are enabled. */	 
 CI_MM_PRIM_SET_BANDIND_REQ , /**< \brief Requests to enable / disable band indications \details */	 
 CI_MM_PRIM_SET_BANDIND_CNF = 60 , /**< \brief Confirms the request to enable / disable band indications \details */	 
 CI_MM_PRIM_GET_BANDIND_REQ , /**< \brief Requests the status of band indications ( enabled / disabled ) and an indication of the current band \details */	 
 CI_MM_PRIM_GET_BANDIND_CNF , /**< \brief Confirms the request and returns the status of band indications ( enabled / disabled ) and an indication of the current band \details */	 
 CI_MM_PRIM_SERVICE_RESTRICTIONS_IND , /**< \brief Indicates if display of PLMN selection menus is allowed	 
 * \details PLMN selection menu contol information is stored in SIM or USIM in bit ' PLMN Mode ' of file EF-CSP ( see CPHS Version 4.200000 ) .	 
 * On power up the application should assume that display of PLMN selection menus is not allowed.	 
 * This indication is sent on power if display of PLMN selection menus is allowed and whenever there is a change of this bit using OTA reprogramming.	 
 */	 
	 
 /* ADD NEW COMMON PRIMITIVES HERE , BEFORE ' CI_MM_PRIM_LAST_COMMON_PRIM ' */	 
 // Michal Bukai - HOMEZONE support	 
 CI_MM_PRIM_HOMEZONE_IND , /**< \brief Indicates a change in HomeZone indication status \details */	 
 /*Michal Bukai - Cell Lock - Start*/	 
 CI_MM_PRIM_CELL_LOCK_REQ , /**< \brief Requests to activate or to deactivate cell lock \details */	 
 CI_MM_PRIM_CELL_LOCK_CNF , /**< \brief Confirms the request and activates or deactivates cell lock \details */	 
 CI_MM_PRIM_CELL_LOCK_IND , /**< \brief Indicates the status of cell lock \details */	 
 /*Michal Bukai - Cell Lock - End*/	 
	 
 CI_MM_PRIM_SET_FAST_DORMANT_CAP_REQ , /**< \brief Requests to enable / disable fast dormancy capability , it will be saved in NVM \details */	 
 CI_MM_PRIM_SET_FAST_DORMANT_CAP_CNF , /**< \brief Confirms the request to enable / disable fast dormancy capability \details */	 
 CI_MM_PRIM_GET_FAST_DORMANT_CAP_REQ = 70 , /**< \brief Requests the capability of fast dormancy ( enabled / disabled ) \details */	 
 CI_MM_PRIM_GET_FAST_DORMANT_CAP_CNF , /**< \brief Confirms the request and returns the capability of fast dormancy ( enabled / disabled ) \details */	 
	 
 CI_MM_PRIM_SET_NAS_INTEGRITY_CHECK_REQ , /**< \brief Requests to enable / disable NAS integrity check , it will be saved in NVM \details */	 
 CI_MM_PRIM_SET_NAS_INTEGRITY_CHECK_CNF , /**< \brief Confirms the request to enable / disable NAS integrity check \details */	 
 CI_MM_PRIM_GET_NAS_INTEGRITY_CHECK_REQ , /**< \brief Requests the configuration of NAS integrity check ( enabled / disabled ) kept in NVM \details */	 
 CI_MM_PRIM_GET_NAS_INTEGRITY_CHECK_CNF , /**< \brief Confirms the request and returns configuration of NAS integrity check ( enabled / disabled ) \details */	 
	 
 CI_MM_PRIM_GET_NUM_LTE_NETWORK_OPERATORS_REQ , /**< \brief Requests the number of operators present in the network \details */	 
 CI_MM_PRIM_GET_NUM_LTE_NETWORK_OPERATORS_CNF , /**< \brief Confirms the request to get the number of operators present in the network \details */	 
 CI_MM_PRIM_GET_LTE_NETWORK_OPERATOR_INFO_REQ , /**< \brief Requests information about a specified operator present in the network \details Use CI_CC_PRIM_GET_NUM_LTE_NETWORK_OPERATORS_REQ to determine the number of operators present in the network ,	 
 * if there are any. This number determines the range of values for the Index parameter.	 
 * Index values start at 1 , which indicates the first operator in the network ( usually the home network operator ) . */	 
 CI_MM_PRIM_GET_LTE_NETWORK_OPERATOR_INFO_CNF , /**< \brief Confirms the request to get information about a specified operator present in the network \details There may be no operators currently present in the network. In that case , the network operator status information is not*/	 
 CI_MM_PRIM_GET_LTE_BACKGROUND_INFO_REQ = 80 , /**< \brief Requests information about the current network operator ( if there is one ) \details */	 
 CI_MM_PRIM_GET_LTE_BACKGROUND_INFO_CNF , /**< \brief Confirms the request to get information about the current network operator ( if there is one ) \details */	 
 CI_MM_PRIM_SET_LTE_BACKGROUND_INFO_REQ , /**< \brief Requests information about the current network operator ( if there is one ) \details */	 
 CI_MM_PRIM_SET_LTE_BACKGROUND_INFO_CNF , /**< \brief Confirms the request to get information about the current network operator ( if there is one ) \details */	 
	 
 CI_MM_PRIM_CS_SERVICE_NOTIFICATION_IND , /**CSFB indication from APEX_MM*/	 
 CI_MM_PRIM_CS_SERVICE_NOTIFICATION_RSP , /**CSFB respond from AP*/	 
	 
 CI_MM_PRIM_DSAC_STATUS_IND , /**< \brief Indicates domain service access status \details */	 
 CI_MM_PRIM_SET_SRVCC_SUPPORT_REQ , /**< \brief Set SRVCC Support of the UE. The network is updated when changing this parameter. \details */	 
 CI_MM_PRIM_SET_SRVCC_SUPPORT_CNF , /**< \brief Confirms the setting of the SRVCC support. \details */	 
 CI_MM_PRIM_GET_SRVCC_SUPPORT_REQ , /**< \brief Get the SRVCC Support status of the UE. \details */	 
 CI_MM_PRIM_GET_SRVCC_SUPPORT_CNF = 90 , /**< \brief Confirms the request to get the SRVCC support status. \details */	 
 CI_MM_PRIM_SET_IMS_NW_REPORT_MODE_REQ , /**< \brief Set command enables or disables reporting of SRVCC handover information and	 
 * of IMS Voice Over PS sessions ( IMSVOPS ) indicator information \details */	 
 CI_MM_PRIM_SET_IMS_NW_REPORT_MODE_CNF , /**< \brief Confirms the setting of the IMS reporting or SRVCC. \details */	 
 CI_MM_PRIM_GET_IMS_NW_REPORT_MODE_REQ , /**< \brief Get the reporting of SRVCC handover information and of IMS Voice Over PS	 
 * sessions ( IMSVOPS ) indicator information \details */	 
 CI_MM_PRIM_GET_IMS_NW_REPORT_MODE_CNF , /**< \brief Confirms the CI_MM_PRIM_GET_IMS_NW_REPORT_MODE_REQ \details */	 
 CI_MM_PRIM_IMSVOPS_IND , /**< \brief IMS Voice Over PS sessions ( IMSVOPS ) supported indication from the network \details */	 
 CI_MM_PRIM_SRVCC_HANDOVER_IND , /**< \brief Reporting of SRVCC handover information indication \details */	 
 CI_MM_PRIM_SET_EMERGENCY_NUMBER_REPORT_MODE_REQ , /**< \brief Set reporting of new emergency numbers received from the network \details */	 
 CI_MM_PRIM_SET_EMERGENCY_NUMBER_REPORT_MODE_CNF , /**< \brief Confirms the request to set reporting of new emergency numbers received from the network. \details */	 
 CI_MM_PRIM_GET_EMERGENCY_NUMBER_REPORT_REQ , /**< \brief Get the reporting status of new emergency numbers received from the network \details */	 
 CI_MM_PRIM_GET_EMERGENCY_NUMBER_REPORT_CNF = 100 , /**< \brief Confirm the request to get the reporting status of new emergency numbers received from the network. \details */	 
 CI_MM_PRIM_EMERGENCY_NUMBER_REPORT_IND , /**< \brief Unsolicited reporting of emergency numbers received from the network	 
 * \details sent if reporting was set with CI_MM_PRIM_SET_EMERGENCY_NUMBER_REPORT_MODE_REQ*/	 
 CI_MM_PRIM_SET_NW_EMERGENCY_BEARER_SERVICES_REQ , /**< \brief Set command enables reporting of changes in the emergency bearer services support indicators \details */	 
 CI_MM_PRIM_SET_NW_EMERGENCY_BEARER_SERVICES_CNF , /**< \brief Confirmation to the setting of reporting of changes in the emergency bearer services support indicators \details */	 
 CI_MM_PRIM_GET_NW_EMERGENCY_BEARER_SERVICES_REQ , /**< \brief Get the current setting of reporting of changes in the emergency bearer services support indicators \details */	 
 CI_MM_PRIM_GET_NW_EMERGENCY_BEARER_SERVICES_CNF , /**< \brief Response to get the current setting of reporting of changes in the emergency bearer services support indicators	 
 * \details The indications emb_Iu_supp and emb_S1_supp are only set to supported when explicitly signalled from the network*/	 
 CI_MM_PRIM_NW_EMERGENCY_BEARER_SERVICES_IU_IND , /**< \brief Unsolicited reporting of changes in the emergency bearer services support	 
 * indicators according to the network feature support information element , see	 
 * 3 GPP TS 24.008000 subclause 10.500000 .5.23 \details */	 
 CI_MM_PRIM_NW_EMERGENCY_BEARER_SERVICES_S1_IND , /**< \brief Unsolicited reporting of changes in the emergency bearer services support	 
 * indicators according to the EPS network feature support information element , see	 
 * 3 GPP TS 24.301000 subclause 9.900000 .3.12A \details */	 
 CI_MM_PRIM_GET_SSAC_STATUS_REQ , /**< \brief Get current status of SSAC ( Service Specific Access Control ) related information \details */	 
 CI_MM_PRIM_GET_SSAC_STATUS_CNF , /**< \brief Confirmation for the request to get SSAC status \details */	 
 CI_MM_PRIM_GET_SIGQUALITY_INFO_REQ = 110 , /**< \brief Request signal quality information */	 
 CI_MM_PRIM_GET_SIGQUALITY_INFO_CNF , /**< \brief Reports the signal quality */	 
	 
 CI_MM_PRIM_WB_CELL_LOCK_REQ , /**< \brief Requests to activate or to deactivate WB-GSM band cell lock \details , used by G+W */	 
 CI_MM_PRIM_WB_CELL_LOCK_CNF , /**< \brief Confirms the request and activates or deactivates WB-GSM band cell lock \details */	 
 /*Michal Bukai - cancel PLMN search ( Samsung ) - Start*/	 
 CI_MM_PRIM_CANCEL_MANUAL_PLMN_SEARCH_REQ , /**< \brief Requests to cancel manual PLMN search	 
 * \details The primitive CI_MM_PRIM_CANCEL_MANUAL_PLMN_SEARCH_REQ is used to trigger abort manual PLMN search.	 
 */	 
 CI_MM_PRIM_CANCEL_MANUAL_PLMN_SEARCH_CNF , /**< \brief Confirms the request and stops the manual PLMN search	 
 * \details If the search will be cencelled successfully CI_MM_PRIM_CANCEL_MANUAL_PLMN_SEARCH_CNF with failure result will be returned.	 
 */	 
 /*Michal Bukai - cancel PLMN search ( Samsung ) - End*/	 
	 
 CI_MM_PRIM_TRIGGER_USER_RESELECTION_REQ , /**< \brief Request to trigger user PLMN selection */	 
 CI_MM_PRIM_TRIGGER_USER_RESELECTION_CNF , /**< \brief confirm that trigger user PLMN selection was received */	 
	 
 CI_MM_PRIM_SET_POWER_UP_PLMN_MODE_REQ , /**< \brief Sets the PLMN selection mode at power up	 
 * \details according to 3 GPP TS 23.122000 , section 4.400000 .3.1 switch on reovery from lack of coverage. */	 
 CI_MM_PRIM_SET_POWER_UP_PLMN_MODE_CNF , /**< \brief confirm the request to set the PLMN selection mode at power up	 
 * \details according to 3 GPP TS 23.122000 , section 4.400000 .3.1 switch on reovery from lack of coverage.*/	 
 CI_MM_PRIM_GET_POWER_UP_PLMN_MODE_REQ = 120 , /**< \brief Gets the PLMN selection mode at power up	 
 * \details according to 3 GPP TS 23.122000 , section 4.400000 .3.1 switch on reovery from lack of coverage.*/	 
 CI_MM_PRIM_GET_POWER_UP_PLMN_MODE_CNF , /**< \brief Confirm the request to get the PLMN selection mode at power up	 
 * \details according to 3 GPP TS 23.122000 , section 4.400000 .3.1 switch on reovery from lack of coverage.*/	 
 CI_MM_PRIM_NETWORK_MODE_REQ ,	 
 CI_MM_PRIM_NETWORK_MODE_CNF ,	 
	 
 CI_MM_PRIM_FIRST_SEARCHED_NETWORK_OPERATOR_IND , /**First searched network operator indication from APEX_MM*/	 
 CI_MM_PRIM_FRAT_LIST_ACTION_REQ ,	 
 CI_MM_PRIM_FRAT_LIST_ACTION_CNF ,	 
 CI_MM_PRIM_GET_FRAT_LIST_REQ ,	 
 CI_MM_PRIM_GET_FRAT_LIST_CNF ,	 
	 
 CI_MM_PRIM_CSG_AUTO_SEARCH_REQ , /**< \brief Request for Automatic camping on the strongest CSG cell. */	 
 CI_MM_PRIM_CSG_AUTO_SEARCH_CNF = 130 , /**< \brief Confirm the request for Automatic camping on the strongest CSG cell. */	 
 CI_MM_PRIM_CSG_LIST_SEARCH_REQ , /**< \brief Request for searching all CSG cells. */	 
 CI_MM_PRIM_CSG_LIST_SEARCH_CNF , /**< \brief List of all the CSG which were found. */	 
 CI_MM_PRIM_CSG_SELECT_REQ , /**< \brief Selects CSG ID , as a result the Comm. will try to camp on it */	 
 CI_MM_PRIM_CSG_SELECT_CNF , /**< \brief Result of selecting CSG ID request. */	 
 CI_MM_PRIM_CSG_SEARCH_STOP_REQ , /**< \brief Request to stop CSG Search. */	 
 CI_MM_PRIM_CSG_SEARCH_STOP_CNF , /**< \brief Confirm that the stop request was received. */	 
 CI_MM_PRIM_REGRESULT_EXTENDED_IND , /** < \brief Indicates the Extended ( csg info ) Unsolicited Network Registration Result \details Receipt of this indication ( and the information it contains ) can be configured by the	 
 * CI_MM_PRIM_SET_REGRESULT_OPTION_REQ request.	 
 * If this indication is enabled , the current registration status ( if available ) is reported.	 
 * As a configuration option , current cell information ( if available ) can also be included.	 
 * This information can also be requested at any time , using the CI_CC_PRIM_GET_REGRESULT_INFO_REQ request.*/	 
 CI_MM_PRIM_SET_SECURITY_CAPABILITY_REQ ,	 
 CI_MM_PRIM_SET_SECURITY_CAPABILITY_CNF ,	 
 CI_MM_PRIM_GET_SECURITY_CAPABILITY_REQ = 140 ,	 
 CI_MM_PRIM_GET_SECURITY_CAPABILITY_CNF ,	 
	 
 CI_MM_PRIM_NETWORK_CELL_MAT_INFO_IND ,	 
	 
 CI_MM_PRIM_EMERGENCY_CALL_STATUS_REQ ,	 
 CI_MM_PRIM_EMERGENCY_CALL_STATUS_CNF ,	 
	 
 CI_MM_PRIM_NEW_ATTACH_IND , /** < \brief Indicates that MM is starting a new ATTACH process */ /* Added by liorgo , for CQ00086808 , 8 / 3 / 2015 */	 
 CI_MM_PRIM_JAMMING_DETECTION_REQ , /**< \brief Request to configure jamming detection.*/	 
 CI_MM_PRIM_JAMMING_DETECTION_CNF , /**< \brief confirtm the reuqest to configure jamming detection.*/	 
 CI_MM_PRIM_GET_JAMMING_DETECTION_STATUS_REQ , /**< \brief request to read jamming detection configuration.*/	 
 CI_MM_PRIM_GET_JAMMING_DETECTION_STATUS_CNF , /**< \brief The configured valued of the jamming detection.*/	 
 CI_MM_PRIM_JAMMING_DETECTION_IND = 150 , /**< \brief unsolicited reporting of change in jamming status.*/	 
	 
 CI_MM_PRIM_SET_GPRS_EGPRS_MULTISLOT_CLASS_REQ , /**< \brief Change the GPRS and EGPRS multislot classes.*/	 
 CI_MM_PRIM_SET_GPRS_EGPRS_MULTISLOT_CLASS_CNF , /**< \brief Confirm the request to change GPRS and EGPRS multislot class.*/	 
 CI_MM_PRIM_GET_GPRS_EGPRS_MULTISLOT_CLASS_REQ , /**< \brief Request to read the GPRS and EGPRS multislot classes.*/	 
 CI_MM_PRIM_GET_GPRS_EGPRS_MULTISLOT_CLASS_CNF , /**< \brief The configured valued of GPRS and EGPRS multislot classes.*/	 
 CI_MM_PRIM_GET_DISPLAY_OPERATOR_NAME_REQ , /**< \brief The command displays the name of the network of the requested type. In case the requested informationis not available , the command displays the network name which is most similar to the requested type.*/	 
 CI_MM_PRIM_GET_DISPLAY_OPERATOR_NAME_CNF , /**< \brief A confirmation for the request command , will return the operator name according to the type that was requested.*/	 
 CI_MM_PRIM_ECALLREG_REQ , /**< \brief Set the forced registration status*/	 
 CI_MM_PRIM_ECALLREG_CNF , /**< \brief Confirms the request to set the forced registration status*/	 
 CI_MM_PRIM_RPM_INFO_REQ ,	 
 CI_MM_PRIM_RPM_INFO_CNF =160 ,	 
 CI_MM_PRIM_RPM_INFO_IND ,	 
 // add by taow 20171124 CQ00108549 begin	 
 CI_MM_PRIM_SET_NETWORK_SELECTION_REQ ,	 
 CI_MM_PRIM_SET_NETWORK_SELECTION_CNF ,	 
 CI_MM_PRIM_GET_NETWORK_SELECTION_REQ ,	 
 CI_MM_PRIM_GET_NETWORK_SELECTION_CNF ,	 
 CI_MM_PRIM_GET_LTE_CA_INFO_REQ ,	 
 CI_MM_PRIM_GET_LTE_CA_INFO_CNF ,	 
 CI_MM_PRIM_GET_OPERATOR_INFO_REQ ,	 
 CI_MM_PRIM_GET_OPERATOR_INFO_CNF ,	 
 CI_MM_PRIM_OPERATOR_STATUS_IND =170 ,	 
 // add by taow 20171124 CQ00108549 end	 
	 
 /*20190605 add for IMS BEGIN */	 
 CI_MM_PRIM_GET_ASRCURRENT_OPERATOR_INFO_REQ , /**< \brief Requests information about the current network operator ( if there is one ) \details */	 
 CI_MM_PRIM_GET_ASRCURRENT_OPERATOR_INFO_CNF , /**< \brief Confirms the request to get information about the current network operator ( if there is one ) \details */	 
 /*20190605 add for IMS BEGIN*/	 
	 
 CI_MM_PRIM_GET_CELL_LOCK_INFO_REQ ,	 
 CI_MM_PRIM_GET_CELL_LOCK_INFO_CNF ,	 
 CI_MM_PRIM_NETWORK_SEARCH_IND , /*add CQ00114574 by taow 20190419 */	 
 CI_MM_PRIM_GET_NETWORK_REGISTRATION_INFO_REQ ,	 
 CI_MM_PRIM_GET_NETWORK_REGISTRATION_INFO_CNF ,	 
 /*add by taow CQ00125209 20201020 begin*/	 
 CI_MM_PRIM_SET_OOS_PHASE_PERIOD_REQ ,	 
 CI_MM_PRIM_SET_OOS_PHASE_PERIOD_CNF ,	 
 CI_MM_PRIM_GET_OOS_PHASE_PERIOD_REQ =180 ,	 
 CI_MM_PRIM_GET_OOS_PHASE_PERIOD_CNF ,	 
 /*add by taow CQ00125209 20201020 end*/	 
 /*add by CQ00130201 taow 20210513 begin*/	 
 CI_MM_PRIM_SET_BANDS_SCAN_CONFIG_REQ ,	 
 CI_MM_PRIM_SET_BANDS_SCAN_CONFIG_CNF ,	 
 CI_MM_PRIM_GET_BANDS_SCAN_CONFIG_REQ ,	 
 CI_MM_PRIM_GET_BANDS_SCAN_CONFIG_CNF ,	 
 CI_MM_PRIM_GET_BANDS_SCAN_REQ ,	 
 CI_MM_PRIM_GET_BANDS_SCAN_CNF ,	 
 CI_MM_PRIM_GET_BANDS_SCAN_IND ,	 
 CI_MM_PRIM_ABORT_BANDS_SCAN_REQ ,	 
 CI_MM_PRIM_ABORT_BANDS_SCAN_CNF =190 ,	 
	 
 /*add by CQ00130201 taow 20210513 end*/	 
	 
 CI_MM_PRIM_NW_ECALL_OVER_IMS_SUPPORT_IND , /**< \brief Unsolicited reporting of changes in eCall over IMS support indicators according to SIB1 --36.331 rel14 and above \details */	 
 /*20220225 with CQ00135513 for IMSECALL for IMSECALL begin*/	 
 CI_MM_PRIM_IMSECALL_REG_REQ ,	 
 CI_MM_PRIM_IMSECALL_REG_CNF ,	 
 /*20220225 with CQ00135513 for IMSECALL for IMSECALL end */	 
	 
 /*Lilei , CQ00134598 , 20220418 , begin*/	 
 CI_MM_PRIM_SET_RPM_REQ ,	 
 CI_MM_PRIM_SET_RPM_CNF ,	 
 /*Lilei , CQ00134598 , 20220418 , end*/	 
 /*add for new feature to support VSIM with CQ00141543 20230208 BEGIN*/	 
 CI_MM_PRIM_SET_SELECT_VSIM_REQ ,	 
 CI_MM_PRIM_SET_SELECT_VSIM_CNF ,	 
	 
 CI_MM_PRIM_GET_SELECT_VSIM_REQ ,	 
 CI_MM_PRIM_GET_SELECT_VSIM_CNF ,	 
 /*add for new feature to support VSIM with CQ00141543 20230208 END*/	 
	 
 /* ADD NEW COMMON PRIMITIVES HERE , BEFORE ' CI_MM_PRIM_LAST_COMMON_PRIM ' */	 
 /* END OF COMMON PRIMITIVES LIST */	 
 CI_MM_PRIM_LAST_COMMON_PRIM	 
	 
 /* The customer specific extension primitives are added starting from	 
 * CI_MM_PRIM_firstCustPrim = CI_MM_PRIM_LAST_COMMON_PRIM as the first identifier.	 
 * The actual primitive names and IDs are defined in the associated	 
 * ' ci_mm_cust_xxx.h ' file.	 
 */	 
	 
 /* DO NOT ADD ANY MORE PRIMITIVES HERE */	 
	 
 } _CiMmPrim;

//ICAT EXPORTED ENUM 
 typedef enum CIRC_MM 
 {	 
 CIRC_MM_SUCCESS = 0 , /**< Request completed successfully */	 
 CIRC_MM_FAIL , /**< General failure ( catch-all ) */	 
 CIRC_MM_INCOMPLETE_INFO , /**< Incomplete information for request */	 
 CIRC_MM_INVALID_ADDRESS , /**< Invalid address ( phone number ) */	 
 CIRC_MM_NO_SERVICE , /**< No network service */	 
 CIRC_MM_NOT_REGISTERED , /**< Not currently registered */	 
 CIRC_MM_REJECTED , /**< Request rejected by network */	 
 CIRC_MM_TIMEOUT , /**< Request timed out */	 
 CIRC_MM_UNAVAILABLE , /**< Information not available */	 
 CIRC_MM_NO_MORE_ENTRIES , /**< No more entries in list */	 
 CIRC_MM_NO_MORE_ROOM , /**< No more room in list */	 
 CIRC_MM_PLMN_LIST_SIM_NOK , /**< PLMN list SIM is not OK */	 
 CIRC_MM_PLMN_LIST_NOT_FOUND , /**< PLMN list is not found */	 
 CIRC_MM_PLMN_LIST_NOT_ALLOWED , /**< PLMN list is not allowed */	 
 CIRC_MM_PLMN_LIST_MANUAL_NOT_ALLOWED , /* manual selection of */	 
 CIRC_MM_PLMN_LIST_MANUAL_NOT_ALLOWED_IN_DEDICATED_MODE , /* PLMN list is not allowed in dedicated mode*/	 
 CIRC_MM_INVALID_PARAMETER , /**< Generic error - the requested service primitive has invalid parameters */	 
 CIRC_MM_INVALID_REQ , /**< Generic error - the requested service primitive can not be handled at current state */	 
 CIRC_MM_SIM_NOT_READY , /**< Generic error - the requested service primitive fails because SIM is not ready */	 
	 
 CIRC_MM_CANCELLED , /*procedure was cancelled*/	 
	 
 CIRC_MM_NETWORK_NOT_ALLOWED_EMERGENCY_CALLS_ONLY ,	 
 CIRC_MM_NO_SERVICE_BUT_SEARCHING ,	 
	 
 /* This one must always be last in the list! */	 
 CIRC_MM_NUM_RESCODES /**< Number of result codes defined */	 
 } _CiMmResultCode;

typedef UINT16 CiMmResultCode ;
typedef UINT32 CiMmCause ;
typedef UINT32 CiGmmCause ;
typedef UINT32 CiEmmCause ;
//ICAT EXPORTED ENUM 
 typedef enum CIMM_PLMN_SELECTION_POWER_UP_MODE {	 
 CI_MM_PLMN_SELECTION_POWER_UP_MODE_AUTO = 0 , /**< At power up , use auto plmn selection mode*/	 
 CI_MM_PLMN_SELECTION_POWER_UP_MODE_MANUAL , /**< At power up , use auto manual selection mode */	 
 CI_MM_PLMN_SELECTION_POWER_UP_MODE_LAST_USED , /**< At power up , use last used plmn mode before power down*/	 
	 
 /* This one must always be last in the list! */	 
 CI_MM_NUM_PLMN_SELECTION_POWER_UP_MODE	 
 } _CiMmPowerUpPlmnSelectionMode;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_ERROR_CAUSE_TYPE {	 
 CI_MM_ERROR_CAUSE_TYPE_MM , /**< MM Reject code is received during an MM procedure */	 
 CI_MM_ERROR_CAUSE_TYPE_GMM_NON_COMBINED , /**< GMM Reject code is received during a non-combined GMM procedure for GPRS services */	 
 CI_MM_ERROR_CAUSE_TYPE_GMM_COMBINED_NON_GPRS , /**< GMM reject code is received during a combined GMM procedure for non-GPRS services */	 
 CI_MM_ERROR_CAUSE_TYPE_GMM_COMBINED_GPRS , /**< GMM reject code is received during a combined GMM procedure for GPRS and non-GPRS services */	 
 CI_MM_ERROR_CAUSE_TYPE_EMM_NON_COMBINED , /**< EMM reject code is received for a non combined EMM procedure for EPS services */	 
 CI_MM_ERROR_CAUSE_TYPE_EMM_COMBINED_NON_EPS , /**< EMM reject code is received during a combined procedure for non-EPS services */	 
 CI_MM_ERROR_CAUSE_TYPE_EMM_COMBINED_EPS , /**< EMM reject code is received during a combined procedure for EPS and non-EPS services */	 
	 
 /* This one must always be last in the list! */	 
 CIMM_NUM_ERROR_CAUSE_TYPES	 
 } _CiMmErrorCauseType;

typedef UINT8 CiMmErrorCauseType ;
typedef UINT8 CiMmPowerUpPlmnSelectionMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIMM_SERVICE {	 
 CIMM_SERVICE_ASYNC_MODEM = 0 , /**< Asynchronous modem */	 
 CIMM_SERVICE_SYNC_MODEM , /**< Synchronous modem */	 
 CIMM_SERVICE_PAD_ASYNC , /**< PAD access ( asynchronous ) */	 
 CIMM_SERVICE_PACKET_SYNC , /**< Packet access ( synchronous ) */	 
 CIMM_SERVICE_VOICE , /**< Voice */	 
 CIMM_SERVICE_FAX , /**< Fax */	 
	 
 /* This one must always be last in the list! */	 
 CIMM_NUM_SERVICES /**< Number of network services defined */	 
 } _CiMmService;

typedef UINT8 CiMmService ;
//ICAT EXPORTED ENUM 
 typedef enum CIMM_ITC {	 
 CIMM_ITC_3_1_KHZ= 0 , /**< 3.100000 kHz */	 
 CIMM_ITC_UDI , /**< Unrestricted digital information ( UDI ) */	 
	 
 /* This one must always be last in the list! */	 
 CIMM_NUM_ITC /**< Number of ITC indicators defined */	 
 } _CiMmITC;

typedef UINT8 CiMmITC ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmServiceInfo_struct {	 
 CiBoolean Present ; /**< Service information present? \sa CCI API Ref Manual */	 
 CiMmService SvcType ; /**< Associated service type \sa CiMmService */	 
 CiBsTypeSpeed Speed ; /**< Connection speed \sa CCI API Ref Manual */	 
 CiMmITC Itc ; /**< Information transfer capability \sa CiMmITC. */	 
 } CiMmServiceInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSubscriberInfo_struct {	 
 CiAddressInfo Number ; /**< Subscriber number ( MSISDN ) \sa CCI API Ref Manual */	 
 CiOptNameInfo AlphaTag ; /**< Associated alpha tag ( optional ) \sa CCI API Ref Manual */	 
 CiMmServiceInfo SvcInfo ; /**< Service information ( optional ) \sa CiMmServiceInfo_struct */	 
 } CiMmSubscriberInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_REGRESULT_OPTION {	 
 CIMM_REGRESULT_DISABLE = 0 , /**< Disable reporting */	 
 CIMM_REGRESULT_STATUS , /**< Report registration status only */	 
 CIMM_REGRESULT_CELLINFO , /**< Report status and current cell information */	 
 CIMM_REGRESULT_MORE_DETAIL , /**< Report more detail info: [ , <cause_type> , <reject_cause> ] ] > */	 
 /* This one must always be last in the list! */	 
 CIMM_NUM_REGRESULT_OPTIONS /**< Number of options defined */	 
 } _CiMmRegResultOption;

typedef UINT8 CiMmRegResultOption ;
//ICAT EXPORTED ENUM 
 typedef enum CIMM_REGSTATUS {	 
 CIMM_REGSTATUS_NOT_SEARCHING = 0 ,	 
 /**< Not registered , not searching operators */	 
 CIMM_REGSTATUS_HOME , /**< Registered with home network */	 
 CIMM_REGSTATUS_SEARCHING , /**< Not registered , searching operators */	 
 CIMM_REGSTATUS_DENIED , /**< Registration denied */	 
 CIMM_REGSTATUS_UNKNOWN , /**< Registration status unknown */	 
 CIMM_REGSTATUS_ROAMING , /**< Registered , roaming */	 
 CIMM_REGSTATUS_SMS_ONLY_HOME , /**< registered for " SMS only " , home network ( applicable only when <AcT> indicates E-UTRAN ) */	 
 CIMM_REGSTATUS_SMS_ONLY_ROAMING , /**< registered for " SMS only " , roaming ( applicable only when <AcT> indicates E-UTRAN ) */	 
 CIMM_REGSTATUS_EMERGENCY_ONLY_NOT_USED , /**< attached for emergency bearer services only ( see NOTE 2 ) ( not applicable ) */	 
 CIMM_REGSTATUS_CSFB_NOT_PREFERRED_HOME , /**<registered for " CSFB not preferred " , home network ( applicable only when <AcT> indicates E-UTRAN ) */	 
 CIMM_REGSTATUS_CSFB_NOT_PREFERRED_ROAMING , /**<registered for " CSFB not preferred " , roaming ( applicable only when <AcT> indicates E-UTRAN ) */	 
 CIMM_REGSTATUS_EMERGENCY_ONLY ,	 
 /**< Only emergency services are available*/	 
 CIMM_REGSTATUS_DENIED_IN_ROAMING , /**< registeration denied in roaming*/	 
 CIMM_REGSTATUS_SYNC_DONE_IN_LTE_ROAMING , /**< sync done in LTE roaming network*/	 
 CIMM_REGSTATUS_ECALL_INACTIVE ,	 
	 
 /* This one must always be last in the list! */	 
 CIMM_NUM_REGSTATUS /**< Number of status values defined */	 
 } _CiMmRegStatus;

typedef UINT8 CiMmRegStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CIMM_REGMODE {	 
 CIMM_REGMODE_AUTOMATIC = 0 , /**< Automatic registration request */	 
 CIMM_REGMODE_MANUAL , /**< Manual registration request */	 
 CIMM_REGMODE_DEREGISTER , /**< Deregistration request */	 
 CIMM_REGMODE_MANUAL_AUTO , /**< Manual request , fallback to automatic */	 
	 
 /* This one must always be last in the list! */	 
 CIMM_NUM_REGMODES /**< Number of mode indicators defined */	 
 } _CiMmRegMode;

typedef UINT8 CiMmRegMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIMM_ACT_TECH_MODE 
 {	 
 CI_MM_ACT_GSM = 0 , /**< GSM */	 
 CI_MM_ACT_GSM_COMPACT , /**< Not supported */	 
 CI_MM_ACT_UTRAN , /**< UTRAN */	 
	 
 CI_MM_ACT_GSM_EGPRS , /**< GSM w / EGPRS */	 
 CI_MM_ACT_UTRAN_HSDPA , /**< UTRAN w / HSDPA */	 
 CI_MM_ACT_UTRAN_HSUPA , /**< UTRAN w / HSUPA */	 
 CI_MM_ACT_UTRAN_HSPA , /**< UTRAN w / HSDPA and HSUPA */	 
 CI_MM_ACT_EUTRAN , /**< E-UTRAN */	 
	 
 CI_MM_ACT_UTRAN_HSPA_PLUS , /**< UTRAN w / HSPA+ */	 
	 
 CI_MM_ACT_EUTRAN_PLUS , /*E-UTRAN CA*/	 
 /* Added by taow 20190708 CQ00115423 , begin */	 
 CI_MM_ACT_UTRAN_DC_HSPA , /*DC-HSPA*/	 
 /* Added by taow 20190708 CQ00115423 , end */	 
 CI_MM_NUM_ACT	 
 } _CiMmAccTechMode;

typedef UINT8 CiMmAccTechMode ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmCellInfo_struct {	 
 CiBoolean Present ; /**< Current cell information present? \sa CCI API Ref Manual */	 
 UINT16 LocArea ; /**< Location area code */	 
 UINT32 CellId ; /**< Cell identifier. GSM case: 16 least significant bits , WCDMA case: CellId - 16 least significant bits , RNCID - 12 most significant bits */	 
	 
 CiMmAccTechMode AcT ; /**< Network access technology ( GSM , UTRAN , LTE etc. ) \sa CiMmAccTechMode */	 
 } CiMmCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmRegResultInfo_struct {	 
 CiMmRegStatus Status ; /**< Registration status \sa CiMmRegStatus */	 
 CiMmCellInfo CellInfo ; /**< Current cell information ( optional ) \sa CiMmRegStatus */	 
 } CiMmRegResultInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_NETOP_ID_FORMAT {	 
 CIMM_NETOP_ID_FORMAT_ALPHA_LONG = 0 , /**< Operator ID: long alphanumeric */	 
 CIMM_NETOP_ID_FORMAT_ALPHA_SHORT , /**< Operator ID: short alphanumeric */	 
 CIMM_NETOP_ID_FORMAT_NETWORK , /**< Network ID ( numeric ) */	 
	 
 /* This one must always be last in the list! */	 
 CIMM_NUM_NETOP_ID_FORMATS /**< Number of format indicators defined */	 
 } _CiMmNetOpIdFormat;

typedef UINT8 CiMmNetOpIdFormat ;
//ICAT EXPORTED ENUM 
 typedef enum CIMM_NETOP_DIGIT_MNC {	 
 CIMM_NETOP_TWO_DIGIT_MNC = 2 , /*2 digit */	 
 CIMM_NETOP_THREE_DIGIT_MNC , /*3 digit */	 
 /* This one must always be last in the list! */	 
 CIMM_NUM_NETOP_DIGIT_MNC	 
 } _CiMmNetOpDigitMnc;

typedef UINT8 CiMmNetOpDigitMnc ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmNetworkId_struct {	 
 UINT16 CountryCode ; /**< 3 -digit country code */	 
 UINT16 NetworkCode ; /**< 3 -digit network code */	 
 /*Added by xwzhou on 4092014 for CQ58416 , begin*/	 
 CiMmNetOpDigitMnc MncDigit ; /**< MncDigit \sa CiMmNetOpDigitMnc */	 
 /*Added by xwzhou on 4092014 for CQ58416 , end*/	 
 } CiMmNetworkId;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmOperatorId_struct {	 
 UINT8 Length ; /**< Operator ID length ( characters ) */	 
 char Id [ 32 ] ; /**< Operator ID */	 
 } CiMmOperatorId;

//ICAT EXPORTED UNION 
 typedef union CiMmNetOpId_tag {	 
 CiMmNetworkId NetworkId ; /**< Network ID \sa CiMmNetworkId_struct */	 
 CiMmOperatorId OperatorId ; /**< Operator ID \sa CiMmOperatorId_struct */	 
 } CiMmNetOpIdUnion;

//ICAT EXPORTED STRUCT 
 typedef struct CiNetOpIdInfo_struct {	 
 CiBoolean Present ; /**< Indicates if network or operator ID is present \sa CCI API Ref Manual */	 
 CiMmNetOpIdFormat Format ; /**< ID format: network or operator \sa CiMmNetOpIdFormat */	 
 CiMmNetOpIdUnion CiMmNetOpId ; /**< ID \sa CiMmNetOpId_tag*/	 
	 
 CiMmAccTechMode AccTchMode ; /**< Access radio technology ; default is GSM \sa CiMmAccTechMode */	 
 UINT8 Domain ; /**< CS or PS domain , 0 :CS only ; 1 :PS only ; 2 :Combined CS / PS */	 
	 
 } CiMmNetOpIdInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_NETOPSTATUS {	 
 CIMM_NETOP_UNKNOWN = 0 , /**< Operator status unavailable */	 
 CIMM_NETOP_AVAILABLE , /**< Operator is available */	 
 CIMM_NETOP_CURRENT , /**< Current operator */	 
 CIMM_NETOP_FORBIDDEN , /**< Operator is forbidden */	 
	 
 /* This one must always be last in the list! */	 
 CIMM_NUM_NETOPSTATUS /**< Number of status indicators defined */	 
 } _CiMmNetOpStatus;

typedef UINT8 CiMmNetOpStatus ;
typedef INT16 CiMmRssi ;
typedef UINT8 CiMmEncodedBER ;
typedef UINT8 CiMmRsrq ;
typedef UINT8 CiMmRsrp ;
typedef UINT8 CiMmRscp ;
typedef UINT8 CiMmEcno ;
typedef UINT8 CiMmRxlev ;
//ICAT EXPORTED STRUCT 
 typedef struct CiNetOpStatusInfo_struct {	 
 CiMmNetOpStatus Status ; /**< Network operator status \sa CiMmNetOpStatus */	 
 CiMmRssi Rssi ; /**< RSSI value in dBm \sa CiMmRssi */	 
 CiMmOperatorId LongAlphaId ; /**< Long alphanumeric operator ID \sa CiMmOperatorId_struct */	 
 CiMmOperatorId ShortAlphaId ; /**< Short alphanumeric operator ID \sa CiMmOperatorId */	 
 CiMmNetworkId NetworkId ; /**< Network ID information \sa CiMmNetworkId */	 
 CiMmAccTechMode AccTchMode ; /**< Network access technology ( GSM , UTRAN , etc. ) \sa CiMmAccTechMode */	 
 } CiMmNetOpStatusInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_SIGQUAL_OPTIONS {	 
 CIMM_SIGQUAL_OPTION_INTERVAL = 0 , /**< Time interval - used for periodic reports */	 
 CIMM_SIGQUAL_OPTION_THRESHOLD , /**< RSSI threshold */	 
 CIMM_SIGQUAL_OPTION_DISABLE , /**< Disable indications */	 
	 
 /* This one must always be last in the list! */	 
 CIMM_NUM_SIGQUAL_OPTIONS /**< Number of status indicators defined */	 
 } _CiMmSigQualOpts;

typedef UINT8 CiMmSigQualOpts ;
//ICAT EXPORTED UNION 
 typedef union CfgUnion_Tag {	 
 UINT8 Interval ; /**< Time Interval in 100 ms units */	 
 UINT8 Threshold ; /**< RSSI threshold in dBm */	 
 } CfgUnion;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSigQualityConfig_struct {	 
 CiMmSigQualOpts Option ; /**< Signal quality report type interval or theshold \sa CiMmSigQualOpts */	 
 CfgUnion Cfg ; /**< Configuration \sa CfgUnion_Tag*/	 
 } CiMmSigQualityConfig;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_NETWORK_MODE 
 {	 
 CI_MM_NETWORK_MODE_GSM = 0 , /**< GSM */	 
 CI_MM_NETWORK_MODE_UMTS , /**< UMTS */	 
	 
 CI_MM_NETWORK_MODE_LTE , /**< TD LTE */	 
 CI_MM_NETWORK_MODE_DEFAULT ,	 
 CI_MM_NUM_NETWORK_MODES	 
 } _CiMmNetworkMode;

typedef UINT8 CiMmNetworkMode ;
typedef UINT8 CiMmCellLockActMode ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmSigQualityInfo_struct {	 
 CiMmRssi Rssi ; /**< RSSI value in dBm \sa CiMmRssi */	 
 CiMmEncodedBER BER ; /**< Encoded bit error rate \sa CiMmEncodedBER */	 
 CiMmRsrq Rsrq ; /**Report reference signal received quality*/	 
 CiMmNetworkMode Mode ; /**< Network mode \sa CiMmNetworkMode */	 
 CiBoolean IsLtePsOnly ; /**TRUE: lte ps only , set 3 G / 2 G RSSI to default ; FALSE: just update lte RSSI*/	 
 } CiMmSigQualityInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSigExtendedQualityInfo_struct {	 
 CiMmRxlev Rxlev ;	 
 CiMmEncodedBER Ber ; // bit error rate	 
 CiMmRscp Rscp ;	 
 CiMmEcno Ecno ; // RadioInfo->receiveQuality	 
 CiMmRsrq Rsrq ;	 
 CiMmRsrp Rsrp ;	 
 // add by taow 20150730 begin	 
 UINT8 LteCqi ;	 
 INT8 SINR ;	 
 // add by taow 20150730 end	 
 } CiMmSigExtendedQualityInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSigNormalQualityInfo_struct {	 
 UINT8 Rssi ;	 
 CiMmEncodedBER Ber ;	 
 } CiMmSigNormalQualityInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_NETWORK_MODE_REPORT 
 {	 
 CI_MM_NETWORK_MODE_REPORT_GSM = 0 , /**< GSM only */	 
 CI_MM_NETWORK_MODE_REPORT_UMTS , /**< 3 G only */	 
 CI_MM_NETWORK_MODE_REPORT_UMTS_HSDPA , /**< 3 G and HSDPA capabilities */	 
 CI_MM_NETWORK_MODE_REPORT_UMTS_HSUPA , /**< 3 G and HSUPA capabilities */	 
 CI_MM_NETWORK_MODE_REPORT_UMTS_HSDPA_HSUPA , /**< 3 G , HSDPA , and HSDPA capabilities */	 
 CI_MM_NETWORK_MODE_REPORT_GSM_EGPRS , /**< GSM , GPRS , and EGPRS capabilities */	 
 CI_MM_NETWORK_MODE_REPORT_GSM_GPRS , /**< GSM and GPRS capabilities */	 
	 
 CI_MM_NETWORK_MODE_REPORT_UMTS_HSPA_PLUS = 8 , /**< 3 G and HSPA+ capabilities */	 
 CI_MM_NETWORK_MODE_REPORT_LTE , /**< TD LTE capabilities */	 
 CI_MM_NUM_NETWORK_MODE_REPORTS	 
 } _CiMmNetworkModeReport;

//ICAT EXPORTED ENUM 
 /** \brief UMTS band values */ 
 /** \remarks Common Data Section */ 
 
 typedef enum CI_UMTS_BANDS_TYPE 
 {	 
 CI_BAND_1 , /**< UMTS Band1 */	 
 CI_BAND_2 , /**< UMTS Band2 */	 
 CI_BAND_3 , /**< UMTS Band3 */	 
 CI_BAND_4 , /**< UMTS Band4 */	 
 CI_BAND_5 , /**< UMTS Band5 */	 
 CI_BAND_6 , /**< UMTS Band6 */	 
 CI_BAND_7 , /**< UMTS Band7 */	 
 CI_BAND_8 , /**< UMTS Band8 */	 
 CI_BAND_9 , /**< UMTS Band9 */	 
 CI_BAND_10 , /**< UMTS Band10 */	 
 CI_BAND_11 , /**< UMTS Band11 */	 
 CI_BAND_12 , /**< UMTS Band12 */	 
 CI_BAND_13 , /**< UMTS Band13 */	 
 CI_BAND_14 , /**< UMTS Band14 */	 
 CI_BAND_15 , /**< UMTS Band15 */	 
 CI_BAND_16 , /**< UMTS Band16 */	 
 CI_BAND_17 , /**< UMTS Band17 */	 
 CI_BAND_18 , /**< UMTS Band18 */	 
 CI_BAND_19 , /**< UMTS Band19 */	 
	 
 CI_BAND_GSM /**< Band GSM */	 
 } _CiUmtsBandsType;

typedef UINT8 CiUmtsBandsType ;
//ICAT EXPORTED ENUM 
 /** \brief LTE band values */ 
 /** \remarks Common Data Section */ 
 
 typedef enum CI_LTE_BANDS_TYPE 
 {	 
 CI_LTE_BAND_1 = 1 , /**< LTE Band1 */	 
 CI_LTE_BAND_2 , /**< LTE Band2 */	 
 CI_LTE_BAND_3 , /**< LTE Band3 */	 
 CI_LTE_BAND_4 , /**< LTE Band4 */	 
 CI_LTE_BAND_5 , /**< LTE Band5 */	 
 CI_LTE_BAND_6 , /**< LTE Band6 */	 
 CI_LTE_BAND_7 , /**< LTE Band7 */	 
 CI_LTE_BAND_8 , /**< LTE Band8 */	 
 CI_LTE_BAND_9 , /**< LTE Band9 */	 
 CI_LTE_BAND_10 , /**< LTE Band10 */	 
	 
 CI_LTE_BAND_11 , /**< LTE Band11 */	 
 CI_LTE_BAND_12 , /**< LTE Band12 */	 
 CI_LTE_BAND_13 , /**< LTE Band13 */	 
 CI_LTE_BAND_14 , /**< LTE Band14 */	 
 CI_LTE_BAND_15 , /**< LTE Band15 */	 
 CI_LTE_BAND_16 , /**< LTE Band16 */	 
 CI_LTE_BAND_17 , /**< LTE Band17 */	 
 CI_LTE_BAND_18 , /**< LTE Band18 */	 
 CI_LTE_BAND_19 , /**< LTE Band19 */	 
 CI_LTE_BAND_20 , /**< LTE Band20 */	 
	 
 CI_LTE_BAND_21 , /**< LTE Band21 */	 
 CI_LTE_BAND_22 , /**< LTE Band22 */	 
 CI_LTE_BAND_23 , /**< LTE Band23 */	 
 CI_LTE_BAND_24 , /**< LTE Band24 */	 
 CI_LTE_BAND_25 , /**< LTE Band25 */	 
 CI_LTE_BAND_26 , /**< LTE Band26 */	 
 CI_LTE_BAND_27 , /**< LTE Band27 */	 
 CI_LTE_BAND_28 , /**< LTE Band28 */	 
 CI_LTE_BAND_29 , /**< LTE Band29 */	 
 CI_LTE_BAND_30 , /**< LTE Band30 */	 
	 
 CI_LTE_BAND_31 , /**< LTE Band31 */	 
 CI_LTE_BAND_32 , /**< LTE Band32 */	 
 CI_LTE_BAND_33 , /**< LTE Band33 */	 
 CI_LTE_BAND_34 , /**< LTE Band34 */	 
 CI_LTE_BAND_35 , /**< LTE Band35 */	 
 CI_LTE_BAND_36 , /**< LTE Band36 */	 
 CI_LTE_BAND_37 , /**< LTE Band37 */	 
 CI_LTE_BAND_38 , /**< LTE Band38 */	 
 CI_LTE_BAND_39 , /**< LTE Band39 */	 
 CI_LTE_BAND_40 , /**< LTE Band40 */	 
	 
 CI_LTE_BAND_41 , /**< LTE Band41 */	 
	 
 CI_LTE_BAND_64 = 64 /**< LTE Band64 */	 
	 
 } _CiLteBandsType;

typedef UINT8 CiLteBandsType ;
//ICAT EXPORTED ENUM 
 /** \brief GSM band values */ 
 /** \remarks Common Data Section */ 
 
 typedef enum CI_GSM_BANDS_TYPE 
 {	 
 CI_GSM_BAND = 0 , /**< PGSM 900 ( standard or primary ) */	 
 CI_DCS_BAND = 1 , /**< DCS GSM 1800 */	 
 CI_PCS_BAND = 2 , /**< PCS GSM 1900 */	 
 CI_EGSM_BAND = 3 , /**< EGSM 900 ( extended ) */	 
 CI_GSM_450_BAND = 4 , /**< GSM 450 */	 
 CI_GSM_480_BAND = 5 , /**< GSM 480 */	 
 CI_GSM_850_BAND = 6 , /**< GSM 850 */	 
	 
 CI_NUM_BANDS ,	 
	 
	 
	 
 CI_INVALID_BAND = 0xFF /**< Invalid band */	 
 } _CiGsmBandsType;

typedef UINT8 CiGsmBandsType ;
//ICAT EXPORTED UNION 
 typedef union CiMmCurrentBandTag 
 {	 
 CiGsmBandsType gsmBand ; /**< access technology is GSM \sa CiGsmBandsType */	 
 CiGsmBandsType gsmCompactBand ; /**< Not used */	 
 CiUmtsBandsType umtsBand ; /**< access technology is UMTS \sa CiUmtsBandsType */	 
 CiLteBandsType lteBand ; /**< access technology is LTE \sa CiLteBandsType */	 
 } CiMmCurrentBand;

//ICAT EXPORTED STRUCT 
 /** \brief Current band */ 
 /** \remarks Common Data Section */ 
 typedef struct CiMmCurrentbandInfo_struct 
 {	 
 CiMmAccTechMode accessTechnology ; /**< Access technology \sa CiMmAccTechMode */	 
 CiMmCurrentBand currentBand ; /**< Current band \sa CiMmCurrentBandTag */	 
 } CiMmCurrentBandInfo;

typedef UINT8 CiMmNetworkModeReport ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmNetworkHsMode_struct 
 {	 
 CiBoolean gprsActive ; /**< TRUE - is active ; FALSE - is not ; \sa CCI API Ref Manual */	 
 CiBoolean egprsActive ; /**< TRUE - is active ; FALSE - is not ; \sa CCI API Ref Manual */	 
 CiBoolean hsdpaActive ; /**< TRUE - is active ; FALSE - is not ; \sa CCI API Ref Manual */	 
 CiBoolean hsupaActive ; /**< TRUE - is active ; FALSE - is not ; \sa CCI API Ref Manual */	 
 CiBoolean hspaPlusActive ; /**< TRUE - is active ; FALSE - is not ; \sa CCI API Ref Manual */	 
 } CiMmNetworkHsMode;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_DSTIND 
 {	 
 CI_MM_DST_IND_NO_ADJUSTMENT = 0 ,	 
 CI_MM_DST_IND_PLUS_ONE_HOUR ,	 
 CI_MM_DST_IND_PLUS_TWO_HOURS ,	 
	 
 CI_MM_NUM_DST_INDS	 
 } _CiMmDstInd;

typedef UINT8 CiMmDstInd ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmUniTime_struct 
 {	 
 UINT8 year ; /**< Year [ 0 ..99 ] */	 
 UINT8 month ; /**< Month [ 1 ..12 ] */	 
 UINT8 day ; /**< Day [ 1 ..31 ] */	 
 UINT8 hour ; /**< Hour [ 0 ..59 ] */	 
 UINT8 minute ; /**< Minute [ 0 ..59 ] */	 
 UINT8 second ; /**< Second [ 0 ..59 ] */	 
 INT8 locTimeZone ; /**< Local time zone */	 
 } CiMmUniTime;

//ICAT EXPORTED ENUM 
 typedef enum CiNetworkNameCodingSchemeTag 
 {	 
 CI_NETWORK_NAME_SMS_CB_CODED = 0 ,	 
 CI_NETWORK_NAME_UCS2_CODED = 1	 
 } 
 _CiNetworkNameCodingScheme;

typedef UINT8 CiNetworkNameCodingScheme ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmLsaIdentity_struct 
 {	 
 UINT8 length ; /**< length */	 
 UINT8 data [ 3 ] ; /**< data */	 
 } CiMmLsaIdentity;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmNetworkName_struct 
 {	 
 CiBoolean extBit ;	 
 CiBoolean addCIBit ; /**<addCountryInitials*/	 
 CiNetworkNameCodingScheme networkNameDCS ; /**< SMS_CB_CODED / UCS2_CODED */	 
 UINT8 networkNameLength ;	 
 UINT8 numOfSpareBitsInLastOctet ;	 
 char networkName [ 64 ] ;	 
	 
 } CiMmNetworkName;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmNitzInfo_struct 
 {	 
 CiMmOperatorId longAlphaId ; /**< Long alphanumeric operator ID \sa CiMmOperatorId_struct */	 
 CiBoolean longAlphaIdPresent ; /**< TRUE - if long alphanumeric ID is present \sa CCI API Ref Manual */	 
 CiMmOperatorId shortAlphaId ; /**< Short alphanumeric operator ID \sa CiMmOperatorId_struct */	 
 CiBoolean shortAlphaIdPresent ; /**< TRUE - if short alphanumeric ID is present \sa CCI API Ref Manual */	 
 CiMmNetworkId networkId ; /**< Network ID information \sa CiMmNetworkId */	 
 CiBoolean networkIdPresent ; /**< TRUE - if Network ID information is present \sa CCI API Ref Manual */	 
 CiMmUniTime uniTime ; /**< Universal time \sa CiMmUniTime_struct */	 
 CiBoolean uniTimePresent ; /**< TRUE - if universal time is present \sa CCI API Ref Manual */	 
 INT8 locTimeZone ; /**< local time zone */	 
 CiBoolean locTimeZonePresent ; /**< TRUE - if local time zone is present \sa CCI API Ref Manual */	 
 CiMmDstInd dstInd ; /**< Daylight savings indicator \sa CiMmDstInd */	 
 CiBoolean dstIndPresent ; /**< TRUE - if daylight saving indicator present \sa CCI API Ref Manual */	 
 CiMmLsaIdentity lsaIdentity ; /**< LSA - localized service area identity \sa CiMmLsaIdentity */	 
 UINT8 domain ; /**< CS or PS domain , 0 :CS ; 1 :PS */	 
	 
 CiNetworkNameCodingScheme networkNameCodingScheme ; /** SMS_CB_CODED / UCS2_CODED */	 
 CiBoolean addCountryInitials ;	 
 /*added by taow 20220708 CQ00137666 begin*/	 
 CiMmNetworkName fullNWName ;	 
 CiMmNetworkName shortNWName ;	 
	 
 UINT32 resrveData [ 4 ] ;	 
 /*added by taow 20220708 CQ00137666 end*/	 
 } CiMmNitzInfo;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_ADDPREFOP_TYPES 
 {	 
 CI_MM_ADDPREFOP_FIRST_AVAILABLE = 0 ,	 
 CI_MM_ADDPREFOP_INSERT_AT_INDEX ,	 
	 
 CI_MM_NUM_ADD_PREFOP_TYPES	 
 } _CiMmAddPrefOpType;

typedef UINT8 CiMmAddPrefOpType ;
//ICAT EXPORTED ENUM 
 typedef enum CIMM_LIST_INDEX_TYPE {	 
 CI_MM_LIST_INDEX_USER_CONTROLLED_WACTSUCCESS = 0 , /**< User controlled PLMN selector with Access Technology EFPLMNwAcT. if not found in the SIM / UICC then select PLMN preferred list EFPLMNsel */	 
 CI_MM_LIST_INDEX_OPERATOR_CONTROLLED_WACT , /**< Operator controlled PLMN selector with Access Technology FOPLMNwAcT */	 
 CI_MM_LIST_INDEX_HPLMN_WACT , /**< HPLMN selector with Access Technology EFHPLMNwAcT */	 
	 
 CI_MM_NUM_LIST_INDEX_TYPES	 
	 
 } _CiMmListIndexType;

typedef UINT8 CiMmListIndexType ;
typedef CiEmptyPrim CiMmPrimGetNumSubscriberNumbersReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetNumSubscriberNumbersCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 UINT8 NumMSISDN ; /**< Number of entries in the MSISDN list */	 
 } CiMmPrimGetNumSubscriberNumbersCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetSubscriberInfoReq_struct {	 
 UINT8 Index ; /**< MSISDN list entry number [ 1 ..number of MSISDN list entries ] */	 
 } CiMmPrimGetSubscriberInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetSubscriberInfoCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 CiMmSubscriberInfo info ; /**< Subscriber information \sa CiMmSubscriberInfo_struct */	 
 } CiMmPrimGetSubscriberInfoCnf;

typedef CiEmptyPrim CiMmPrimGetSupportedRegResultOptionsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetSupportedRegResultOptionsCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 UINT8 NumOptions ; /**< Number of supported options */	 
 CiMmRegResultOption Option [ CIMM_NUM_REGRESULT_OPTIONS ] ; /**< Supported options \sa CiMmRegResultOption*/	 
 } CiMmPrimGetSupportedRegResultOptionsCnf;

typedef CiEmptyPrim CiMmPrimGetRegResultOptionReq ;
typedef CiEmptyPrim CiMmPrimGetBandIndReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetBandIndCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 CiBoolean enableBandInd ; /**< Enable status \sa CCI API Ref Manual */	 
 CiMmCurrentBandInfo currentBand ; /**< Current band \sa CiMmCurrentbandInfo_struct */	 
	 
 } CiMmPrimGetBandIndCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetRegResultOptionCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 CiMmRegResultOption Option ; /**< Reporting option \sa CiMmRegResultOption */	 
 } CiMmPrimGetRegResultOptionCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetRegResultOptionReq_struct {	 
 CiMmRegResultOption Option ; /**< Reporting option \sa CiMmRegResultOption */	 
 } CiMmPrimSetRegResultOptionReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetBandIndReq_struct {	 
 CiBoolean enableBandInd ; /**< Enable / Disable band indications \sa CCI API Ref Manual */	 
 } CiMmPrimSetBandIndReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetBandIndCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimSetBandIndCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetRegResultOptionCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimSetRegResultOptionCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_CAUSE_TYPE {	 
 CI_MM_CAUSE_TYPE_MM = 0 , /**< Indicates that <reject_cause> contains an MM cause value , see 3 GPP TS 24.008000 [ 8 ] Annex G*/	 
 CI_MM_CAUSE_TYPE_MANUFACTURER , /**< Indicates that <reject_cause> contains a manufacturer specific cause */	 
 CI_MM_CAUSE_NONE ,	 
 CIMM_NUM_CAUSE_TYPE	 
 } _CiMmCauseType;

typedef UINT8 CiMmCauseType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimRegResultInd_struct {	 
 CiMmRegStatus RegStatus ; /**< Registration status \sa CiMmRegStatus */	 
 CiMmCellInfo info ; /**< Current cell information \sa CiMmCellInfo_struct */	 
 /* deleted by xwzhou 9052013 CQ43000 , begin */	 
 // CiMmAccTechMode AccTchMode ; / **< Network access technology \sa CiMmAccTechMode * /	 
 /* deleted by xwzhou 9052013 CQ43000 , end */	 
	 
 CiMmCauseType causeType ; /**< cuase type \sa CiMmCauseType */	 
 UINT16 rejectCause ; /**< contains the cause of the failed registration ( if MM cause type , values define in 3 GPP TS 24.008000 [ 8 ] Annex G ) . The value is of type as defined by causeType */	 
 CiBoolean pscValid ; /**<Indicates if the psc field is valid. The psc should be valid only on UMTS */	 
 UINT16 psc ; /**< Primary scrambling code */	 
 /* add by perse 1032018 add +CREG / +CGREG / +CEREG indication content with rplmn CQ00117472 , begin */	 
 // #if defined ( CRANE_Z1 )	 
 CiMmNetworkId rplmnInfo ; /**reprot rplmn information*/	 
 // #endif	 
 /* add by perse 1032018 add +CREG / +CGREG / +CEREG indication content with rplmn CQ00117472 , end */	 
 } CiMmPrimRegResultInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimBandIndInd_struct 
 {	 
 CiMmCurrentBandInfo currentBand ; /**< Current band \sa CiMmCurrentbandInfo_struct */	 
 } 
 CiMmPrimBandIndInd;

typedef CiEmptyPrim CiMmPrimGetRegResultInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetRegResultInfoCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 CiMmRegResultOption option ; /** just the n flag in CREG */	 
 CiMmRegStatus RegStatus ; /**< Registration status \sa CiMmRegStatus */	 
 CiMmCellInfo info ; /**< Current cell information \sa CiMmCellInfo_struct */	 
 /* deleted by xwzhou 9052013 CQ43000 , begin */	 
 // CiMmAccTechMode AccTchMode ; / **< Network access technology \sa CiMmAccTechMode * /	 
 /* deleted by xwzhou 9052013 CQ43000 , end */	 
 CiMmCauseType causeType ; /**< cuase type \sa CiMmCauseType */	 
 UINT16 rejectCause ; /**< contains the cause of the failed registration ( if MM cause type , values define in 3 GPP TS 24.008000 [ 8 ] Annex G ) . The value is of type as defined by causeType */	 
 CiBoolean pscValid ; /**<Indicates if the psc field is valid. The psc should be valid only on UMTS */	 
 UINT16 psc ; /**< Primary scrambling code */	 
 /* add by perse 1032018 add +CREG / +CGREG / +CEREG indication content with rplmn CQ00117472 , begin */	 
 // #if defined ( CRANE_Z1 )	 
 CiMmNetworkId rplmnInfo ; /**reprot rplmn information*/	 
 // #endif	 
 /* add by perse 1032018 add +CREG / +CGREG / +CEREG indication content with rplmn CQ00117472 end */	 
 } CiMmPrimGetRegResultInfoCnf;

typedef CiEmptyPrim CiMmPrimGetSupportedIdFormatsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetSupportedIdFormatsCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 UINT8 NumFormats ; /**< Number of supported formats */	 
 CiMmNetOpIdFormat Format [ CIMM_NUM_NETOP_ID_FORMATS ] ; /**< Supported formats \sa CiMmNetOpIdFormat */	 
 } CiMmPrimGetSupportedIdFormatsCnf;

typedef CiEmptyPrim CiMmPrimGetIdFormatReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetIdFormatCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 CiMmNetOpIdFormat Format ; /**< Current format \sa CiMmNetOpIdFormat */	 
 } CiMmPrimGetIdFormatCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetIdFormatReq_struct {	 
 CiMmNetOpIdFormat Format ; /**< Current format \sa CiMmNetOpIdFormat */	 
 } CiMmPrimSetIdFormatReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetIdFormatCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimSetIdFormatCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetNumNetworkOperatorsReq_struct {	 
 CiMmNetworkMode networkMode ;	 
 CiBoolean extendedNetworkSearch ; /**<TRUE run extended Network PLMN Search. FALSE run PLMN Search ; add CQ00114574 by taow 20190419 */	 
 } CiMmPrimGetNumNetworkOperatorsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetNumNetworkOperatorsCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 UINT8 NumOperators ; /**< Number of operators present */	 
 } CiMmPrimGetNumNetworkOperatorsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetNetworkOperatorInfoReq_struct {	 
 UINT8 Index ; /**< Numeric index , specifying the network operator for which information is requested [ 1 ..number of operators present ] */	 
 } CiMmPrimGetNetworkOperatorInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetNetworkOperatorInfoCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 CiMmNetOpStatusInfo opStatus ; /**< Network operator status information , if available \sa CiNetOpStatusInfo_struct */	 
 } CiMmPrimGetNetworkOperatorInfoCnf;

typedef CiEmptyPrim CiMmPrimGetNumPreferredOperatorsReq ;
//ICAT EXPORTED STRUCT 
 /** <paramref name= " CI_MM_PRIM_GET_NUM_PREFERRED_OPERATORS_CNF " > */ 
 // ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetNumPreferredOperatorsCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 UINT8 NumPref ; /**< Number of entries in the list */	 
 UINT8 NumTotalInSim ; /**< Number of total entries in the SIM */	 
 } CiMmPrimGetNumPreferredOperatorsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetPreferredOperatorInfoReq_struct {	 
 UINT8 Index ; /**< Not in use */	 
 } CiMmPrimGetPreferredOperatorInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetPreferredOperatorInfoCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 CiMmNetOpIdInfo info ; /**< Network / operator ID information \sa CiNetOpIdInfo_struct */	 
 UINT8 AccTchMode ; /**< Access Radio technology bitmap ; bit 1 - GSM , bit2 - GSM COMPACT , bit 3 - UTRAN , bit4 - EUTRAN , bit 5 - NG-RAN */	 
 } CiMmPrimGetPreferredOperatorInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimAddPreferredOperatorReq_struct {	 
 CiMmNetOpIdInfo info ; /**< New network / operator ID information \sa CiNetOpIdInfo_struct */	 
 CiMmAddPrefOpType addPrefOpType ; /**< \sa CiMmAddPrefOpType */	 
 UINT8 res1U8 ; /**< ( padding ) just in case */	 
 UINT16 index ; /**< Entry number to add */	 
 UINT8 AccTchMode ; /**< ACT parameter for CPOL command bitmap ; bit 1 - GSM , bit2 - GSM COMPACT , bit 3 - UTRAN , bit4 - EUTRAN , bit 5 - NG-RAN*/	 
 } CiMmPrimAddPreferredOperatorReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimAddPreferredOperatorCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 UINT8 NumPref ; /**< Not in use */	 
 } CiMmPrimAddPreferredOperatorCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimDeletePreferredOperatorReq_struct {	 
 UINT8 Index ; /**< Index ( entry number ) to delete */	 
 } CiMmPrimDeletePreferredOperatorReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimDeletePreferredOperatorCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 UINT8 NumPref ; /**< Not in use */	 
 } CiMmPrimDeletePreferredOperatorCnf;

typedef CiEmptyPrim CiMmPrimGetCurrentOperatorInfoReq ;
typedef CiEmptyPrim CiMmPrimGetAsrCurrentOperatorInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetCurrentOperatorInfoCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 CiMmRegMode RegMode ; /**< Current registration mode \sa CiMmRegMode */	 
 CiMmNetOpIdInfo info [ 2 ] ; /**< Current network / operator ID information \sa CiNetOpIdInfo_struct */	 
 /* deleted by xwzhou 9052013 CQ43000 , begin */	 
 // CiMmAccTechMode AccTchMode ; / **< Access radio technology ; default is GSM \sa CiMmAccTechMode * /	 
 /* deleted by xwzhou 9052013 CQ43000 , end */	 
 } CiMmPrimGetCurrentOperatorInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetAsrCurrentOperatorInfoCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 CiMmRegMode RegMode ; /**< Current registration mode \sa CiMmRegMode */	 
 CiMmNetOpIdInfo info [ 2 ] ; /**< Current network / operator ID information \sa CiNetOpIdInfo_struct */	 
 CiMmNetOpIdInfo info_alpha [ 2 ] ; /**< Current network / operator ID information \sa CiNetOpIdInfo_struct */	 
 CiMmNetOpIdInfo info_longAlpha [ 2 ] ; /**< Current network / operator ID information \sa CiNetOpIdInfo_struct */	 
 } CiMmPrimGetAsrCurrentOperatorInfoCnf;

typedef CiEmptyPrim CiMmPrimNetworkModeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimNetworkModeCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 CiMmNetworkModeReport mode ; /**< Cell capabilities network mode*/	 
 CiBoolean gprsActive ; /**< Active high speed service: gprsActive ( 1 - gprs is active , 0 - gprs is inactive ) */	 
 CiBoolean egprsActive ; /**< Active high speed service: egprsActive ( 1 - egprs is active , 0 - egprs is inactive ) */	 
 CiBoolean hsdpaActive ; /**< Active high speed service: hsdpaActive ( 1 - hsdpa is active , 0 - hsdpa is inactive ) */	 
 CiBoolean hsupaActive ; /**< Active high speed service: hsupaActive ( 1 - hsupa is active , 0 - hsupa is inactive ) */	 
 CiBoolean epsActive ; /**< Active high speed service: epsActive ( 1 - eps is active , 0 - eps is inactive ) */	 
 CiBoolean dcHsdpaActive ; /**< Active high speed service: dcHsdpaActive ( 1 - dcHsdpa is active , 0 - dcHsdpa is inactive ) */	 
 CiBoolean hspaPlusActive ; /**< Active high speed service: hspaPlusActive ( 1 - HSPA+ is active , 0 - HSPA+ is inactive ) */	 
 } CiMmPrimNetworkModeCnf;

typedef CiEmptyPrim CiMmPrimAutoRegisterReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimAutoRegisterCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimAutoRegisterCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimManualRegisterReq_struct {	 
 CiBoolean AutoFallback ; /**< TRUE - Fallback to automatic registration ; FALSE - No fallback to automatic registration \sa CCI API Ref Manual */	 
 CiMmNetOpIdInfo info ; /**< Network operator identification information \sa CiNetOpIdInfo_struct */	 
 CiMmAccTechMode AccTchMode ; /**< Access radio technology ; default is GSM \sa CiMmAccTechMode */	 
 } CiMmPrimManualRegisterReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimManualRegisterCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimManualRegisterCnf;

typedef CiEmptyPrim CiMmPrimDeregisterReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimDeregisterCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimDeregisterCnf;

typedef CiEmptyPrim CiMmPrimGetSigQualityIndConfigReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetSigQualityIndConfigCnf_struct {	 
 CiMmResultCode Result ;	 
 CiMmSigQualityConfig config ;	 
 } CiMmPrimGetSigQualityIndConfigCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetSigQualityIndConfigReq_struct {	 
 CiMmSigQualityConfig config ; /**< Signal quality configuration \sa CiMmSigQualityConfig_struct */	 
 } CiMmPrimSetSigQualityIndConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetSigQualityIndConfigCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimSetSigQualityIndConfigCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSigQualityInfoInd_struct {	 
 CiMmSigQualityInfo info ; /**< Signal quality information \sa CiMmSigQualityInfo_struct */	 
 } CiMmPrimSigQualityInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimExtendedSigQualityInfoInd_struct {	 
 CiMmSigExtendedQualityInfo info ; /**< Signal quality information \sa CiMmSigExtendedQualityInfo_struct */	 
 } CiMmPrimExtendedSigQualityInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimNormalSigQualityInfoInd_struct {	 
 CiMmSigNormalQualityInfo info ; /**< Signal quality information \sa CiMmSigQualityInfo_struct */	 
 } CiMmPrimNormalSigQualityInfoInd;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_SIGQUALITY_TYPE {	 
 CI_MM_SIGQUALITY_CSQ = 0 , /**< Indicates that <reject_cause> contains an MM cause value , see 3 GPP TS 24.008000 [ 8 ] Annex G*/	 
 CI_MM_SIGQUALITY_ECSQ , /**< Indicates that <reject_cause> contains a manufacturer specific cause */	 
 CI_MM_SIGQUALITY_NONE ,	 
 } _CiMmSigQualityType;

typedef UINT8 CiMmSigQualityType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSigQualityInfoReq_struct {	 
 CiMmSigQualityType sigQualityType ;	 
	 
 } CiMmPrimSigQualityInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSigQualityInfoCnf_struct {	 
 CiMmResultCode result ;	 
 CiMmSigQualityType sigQualityType ;	 
 CiMmSigNormalQualityInfo normalInfo ; /**< Signal quality information \sa CiMmSigQualityInfo_struct */	 
 CiMmSigExtendedQualityInfo extendedInfo ; /**< Signal quality information \sa CiMmSigExtendedQualityInfo_struct */	 
 } CiMmPrimSigQualityInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimEnableNetworkModeIndReq_struct 
 {	 
 CiBoolean enable ; /**< TRUE - Enable network mode indication ; FALSE - Disable network mode indication ( default ) \sa CCI API Ref Manual */	 
 } CiMmPrimEnableNetworkModeIndReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimEnableNetworkModeIndCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimEnableNetworkModeIndCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimNetworkModeInd_struct 
 {	 
 /* Michal Bukai enter Vadim modification for NetworkModeIndication */	 
	 
	 
	 
 CiMmNetworkModeReport mode ; /**< Cell capabilities network mode \sa CiMmNetworkModeReport */	 
 CiBoolean gprsActive ; /**< Active high speed service: gprsActive ( 1 - gprs is active , 0 - gprs is inactive ) \sa CCI API Ref Manual */	 
 CiBoolean egprsActive ; /**< Active high speed service: egprsActive ( 1 - egprs is active , 0 - egprs is inactive ) \sa CCI API Ref Manual */	 
 CiBoolean hsdpaActive ; /**< Active high speed service: hsdpaActive ( 1 - hsdpa is active , 0 - hsdpa is inactive ) \sa CCI API Ref Manual */	 
 CiBoolean hsupaActive ; /**< Active high speed service: hsupaActive ( 1 - hsupa is active , 0 - hsupa is inactive ) \sa CCI API Ref Manual */	 
 CiBoolean hspaPlusActive ; /**< Active high speed service: hspa+ ( 1 - hspa+ is active , 0 - hspa+ is inactive ) \sa CCI API Ref Manual */	 
	 
 CiBoolean epsActive ; /**< Active high speed service: epsActive ( 1 - eps is active , 0 - eps is inactive ) \sa CCI API Ref Manual */	 
	 
 UINT8 domain ; /**< CS or PS domain , 0 :CS only ; 1 :PS only ; 2 :Combined CS / PS */	 
 } CiMmPrimNetworkModeInd;

typedef CiEmptyPrim CiMmPrimGetNitzInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetNitzInfoCnf_struct 
 {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 CiMmNitzInfo info ; /**< NITZ information \sa CiMmNitzInfo_struct */	 
 } CiMmPrimGetNitzInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimNitzInfoInd_struct 
 {	 
 CiMmNitzInfo info ; /**< NITZ information \sa CiMmNitzInfo_struct */	 
 } CiMmPrimNitzInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimCipheringStatusInd_struct {	 
 CiBoolean CsCipheringOn ; /**< TRUE if ON , FALSE if OFF ; \sa CCI API Ref Manual */	 
 CiBoolean PsCipheringOn ; /**< TRUE if ON , FALSE if OFF ; \sa CCI API Ref Manual */	 
 CiBoolean CipheringIndicatorOn ; /**< TRUE if required , FALSE if not required ; \sa CCI API Ref Manual */	 
	 
 } CiMmPrimCipheringStatusInd;

typedef UINT8 CiMmRejectType ;
typedef UINT8 CiGmmRejectType ;
typedef UINT8 CiEmmRejectType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimAirInterfaceRejectCauseInd_struct {	 
 CiMmRejectType mmRejectType ; /**< MM Reject type \sa CiMmRejectType */	 
 CiMmCause mmCause ; /**< MM state \sa CiMmCause */	 
	 
 CiGmmRejectType gmmRejectType ; /**< GMM Reject type \sa CiGmmRejectType */	 
 CiGmmCause gmmCause ; /**< GMM state \sa CiGmmCause */	 
	 
 CiEmmRejectType emmRejectType ;	 
 CiEmmCause emmCause ; /**< EMM state \sa CiEmmCause */	 
	 
 CiMmErrorCauseType causeType ;	 
 } CiMmPrimAirInterfaceRejectCauseInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSelectPreferredPlmnListReq_struct {	 
 CiMmListIndexType ListIndex ; /**< Preferred PLMN list type \sa CiMmListIndexType*/	 
 } CiMmPrimSelectPreferredPlmnListReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSelectPreferredPlmnListCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimSelectPreferredPlmnListCnf;

typedef CiEmptyPrim CiMmPrimGetPreferredPlmnListReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetPreferredPlmnListCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 CiMmListIndexType ListIndex ; /**< Preferred PLMN list type \sa CiMmListIndexType*/	 
 } CiMmPrimGetPreferredPlmnListCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimServiceRestrictionsInd_struct 
 {	 
 CiBoolean manualPlmnSelectionAllowed ; /**< TRUE if display of PLMN selection menus is allowed \sa CCI API Ref Manual */	 
 } CiMmPrimServiceRestrictionsInd;

typedef CiEmptyPrim CiMmPrimCancelManualPlmnSearchReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimCancelManualPlmnSearchCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimCancelManualPlmnSearchCnf;

typedef CiEmptyPrim CiMmPrimTriggerUserReselectionReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimTriggerUserReselectionCnf_struct {	 
 CiMmResultCode result ; /**< Result code */	 
 } CiMmPrimTriggerUserReselectionCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimHomeZoneInd_struct {	 
 CiBoolean ZoneInd ; /**< TRUE - display HomeZone / CitiZone Indication for the zone specified in " ZoneId " field , FALSE -remove HomeZone / CitiZone indication \sa CCI API Ref Manual */	 
 UINT8 ZoneId ; /**< Zone ID*/	 
 CiBoolean IsCityZone ; /**< TRUE - detected zone is CityZone , FALSE - detected zone is HomeZone \sa CCI API Ref Manual */	 
 CiBoolean ZoneTagPreset ; /**< TRUE - Zone TAG is included , FALSE - Zone TAG is not included \sa CCI API Ref Manual */	 
 CiString ZoneTag ; /**< 13 -character string coded in the short message alphabet given in GSM 3.380000 with bit 8 set to Zero. 0xff indicates end of string \sa CCI API Ref Manual */	 
 } CiMmPrimHomeZoneInd;

//ICAT EXPORTED ENUM 
 /** \brief Cell lock modes */ 
 /** \remarks Common Data Section */ 
 typedef enum CIMM_CELL_LOCK_MODE 
 {	 
 CIMM_CELL_LOCK_MODE_NONE = 0 , /**< Cell / Freq Lock and IRAT optimization disabled */	 
 CIMM_CELL_LOCK_MODE_LOCKFREQ = 1 , /**< Freq Lock enabled */	 
 CIMM_CELL_LOCK_MODE_LOCKCELL = 2 , /**< Cell Lock enabled */	 
 // CIMM_CELL_LOCK_MODE_IRAT_OPTIMIZATION = 3 , / **< IRAT optimization for cell reselection enabled * /	 
 CIMM_CELL_LOCK_MODE_LOCKBAND = 3 ,	 
 // CIMM_CELL_LOCK_MODE_SYNC_CELL = 4 , / **< LTE Cell sync detection enabled * /	 
	 
 CIMM_NUM_CELLLOCK_MODES ,	 
 } _CiMmCellLockMode;

typedef UINT8 CiMmCellLockMode ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimCellLockReq_struct {	 
 CiMmCellLockMode mode ; /**< Cell lock mode \sa CiMmCellLockMode */	 
 CiMmCellLockActMode act ; /**< Network mode \sa CiMmNetworkMode */	 
 UINT8 bandValue ;	 
 UINT32 freq ; /**< Absolute radio frequency channel number ; GSM number 0 -1023 , TD number 10054 -10121 and 9404 -9596 */	 
 INT16 cellId ; /**< Cell parameter ID This parameter if valid for 3 G cells only 0 -127 , and for TD LTE cells only 0 -503 */	 
 // INT8 tddOffset ; / **< RSCP threshold for IRAT cell reselection ; -115~-25dB and default -85dB* /	 
 } CiMmPrimCellLockReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimCellLockCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimCellLockCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimCellLockInd_struct {	 
 CiMmCellLockMode mode ; /**< Cell lock mode \sa CiMmCellLockMode */	 
 CiMmNetworkMode networkMode ; /**< Network mode \sa CiMmNetworkMode */	 
	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number ; GSM number 0 -1023 , TD number 10054 -10121 and 9404 -9596 */	 
 UINT8 cellParameterId ; /**< Cell parameter ID This parameter if valid for 3 G cells only 0 -127*/	 
 INT8 tddOffset ; /**< RSCP threshold for IRAT cell reselection ; -115~-25dB and default -85dB*/	 
 } CiMmPrimCellLockInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimWBCellLockReq_struct {	 
 CiBoolean ActivateCellLock ; /**< TRUE - activate cell lock ; FALSE - deactivate cell lock \sa CiBoolean */	 
 CiMmCurrentBandInfo Band ; /**< Band \sa CiMmCurrentbandInfo */	 
 UINT16 arfcn ; /**< Absolute radio frequency channel number ; number 0 -1023 */	 
 UINT16 ScramblingCode ; /**< Primary scrambling code This parameter if valid for 3 G cells only */	 
 } CiMmPrimWBCellLockReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimWBCellLockCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimWBCellLockCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetFastDormantCapReq_struct {	 
 CiBoolean fastDormantEnabled ; /**< TRUE - enabled ; FALSE - disabled ; \sa CCI API Ref Manual */	 
 } CiMmPrimSetFastDormantCapReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetFastDormantCapCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimSetFastDormantCapCnf;

typedef CiEmptyPrim CiMmPrimGetFastDormantCapReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetFastDormantCapCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
	 
 CiBoolean fastDormantEnabled ; /**< TRUE - enabled ; FALSE - disabled ; \sa CCI API Ref Manual */	 
 } CiMmPrimGetFastDormantCapCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetNasIntegrityCheckReq_struct {	 
 CiBoolean integrityCheckEnabled ; /**< TRUE - enabled ; FALSE - disabled ; \sa CCI API Ref Manual */	 
 } CiMmPrimSetNasIntegrityCheckReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetNasIntegrityCheckCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimSetNasIntegrityCheckCnf;

typedef CiEmptyPrim CiMmPrimGetNasIntegrityCheckReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetNasIntegrityCheckCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
	 
 CiBoolean integrityCheckEnabled ; /**< TRUE - enabled ; FALSE - disabled ; \sa CCI API Ref Manual */	 
 } CiMmPrimGetNasIntegrityCheckCnf;

typedef CiEmptyPrim CiMmPrimGetNumLteNetworkOperatorsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetNumLteNetworkOperatorsCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
 UINT8 NumOperators ; /**< Number of operators present */	 
 } CiMmPrimGetNumLteNetworkOperatorsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetLteNetworkOperatorInfoReq_struct {	 
 UINT8 Index ; /**< Numeric index , specifying the network operator for which information is requested [ 1 ..number of operators present ] */	 
 } CiMmPrimGetLteNetworkOperatorInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetLteNetworkOperatorInfoCnf_struct {	 
 CiMmResultCode Result ; /**< Result code \sa CiMmResultCode */	 
	 
 CiMmNetOpStatusInfo opStatus ; /**< Network operator status information , if available \sa CiNetOpStatusInfo_struct */	 
 } CiMmPrimGetLteNetworkOperatorInfoCnf;

typedef CiEmptyPrim CiMmPrimGetLteBackgroundInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetLteBackgroundInfoCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 CiBoolean status ; /**< TRUE - enabled ; FALSE - disabled ; \sa CCI API Ref Manual */	 
 UINT16 interval ; /**< Background search interval in minutes , 0 :immediately ; 15 , 30 , 60 minutes ; 0xFFFF don ' t search*/	 
 } CiMmPrimGetLteBackgroundInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetLteBackgroundInfoReq_struct {	 
 CiBoolean status ; /**< TRUE - enabled ; FALSE - disabled ; \sa CCI API Ref Manual */	 
 UINT16 interval ; /**< Background search interval in minutes , 0 :immediately ; 15 , 30 , 60 minutes ; 0xFFFF don ' t search*/	 
 } CiMmPrimSetLteBackgroundInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetLteBackgroundInfoCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimSetLteBackgroundInfoCnf;

//ICAT EXPORTED ENUM 
 /** \brief Paging Identity Element */ 
 /** \remarks Common Data Section */ 
 typedef enum CIMM_PAGING_IDENTITY_ELEMENT 
 {	 
 CI_MM_CN_PAGING_BY_IMSI ,	 
 CI_MM_CN_PAGING_BY_TMSI ,	 
	 
 CI_MM_NUM_PAGING_IDENTITY_ELEMENT	 
 } _CiMmPagingIdentityElement;

typedef UINT8 CiMmPagingIdentityElement ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmCliElement_struct 
 {	 
 INT8 length ;	 
 INT8 data [ 12 ] ; /* 24008 , 10.500000 .4.9 */	 
 } CiMmCliElement;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSsCodeElement_struct 
 {	 
 INT8 value ; /* 29002 , 17.700000 .5 */	 
 } CiMmSsCodeElement;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmLcsIndicatorElement_struct 
 {	 
 INT8 value ;	 
 } CiMmLcsIndicatorElement;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmLcsClientIdentityElement_struct 
 {	 
 INT8 length ;	 
 INT8 data [ 255 ] ; /* 29002 , 17.700000 .13 */	 
 } CiMmLcsClientIdentityElement;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimCsServiceNotificationInd_struct {	 
 CiMmPagingIdentityElement pagingIdentity ; /* 24301 , 9.900000 .3.25A */	 
 CiBoolean cliPresent ;	 
 CiMmCliElement cli ; /* 24301 , 9.900000 .3.38 */	 
 CiBoolean ssCodePresent ;	 
 CiMmSsCodeElement ssCode ; /* 24301 , 9.900000 .3.39 */	 
 CiBoolean lcsIndicatorPresent ;	 
 CiMmLcsIndicatorElement lcsIndicator ; /* 24301 , 9.900000 .3.40 */	 
 CiBoolean lcsClientIdentityPresent ;	 
 CiMmLcsClientIdentityElement lcsClientIdentity ; /* 24301 , 9.900000 .3.41 */	 
 } CiMmPrimCsServiceNotificationInd;

//ICAT EXPORTED ENUM 
 /** \brief CIMM Respond Value */ 
 /** \remarks Common Data Section */ 
 typedef enum CIMM_RSP_VALUE 
 {	 
 CI_MM_CSFB_ACCEPT ,	 
 CI_MM_CSFB_REJECT ,	 
 CI_MM_CSFB_OTHERS , // set it when timer expired , or others	 
	 
 CI_MM_NUM_RSP_VALUE	 
 } _CiMmRspValue;

typedef UINT8 CiMmRspValue ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimCsServiceNotificationRsp_struct {	 
 CiMmRspValue rspValue ;	 
 } CiMmPrimCsServiceNotificationRsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimDsacStatusInd_struct {	 
 CiBoolean csDomainBarred ;	 
 CiBoolean psDomainBarred ;	 
 } CiMmPrimDsacStatusInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSetSrvccSupportReq_struct {	 
 CiBoolean srvcc_status ;	 
 } CiMmSetSrvccSupportReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSetSrvccSupportCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmSetSrvccSupportCnf;

typedef CiEmptyPrim CiMmGetSrvccSupportReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmGetSrvccSupportCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 CiBoolean srvcc_status ;	 
 } CiMmGetSrvccSupportCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSetImsNwReportModeReq_struct {	 
 CiBoolean reporting ;	 
 } CiMmSetImsNwReportModeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSetImsNwReportModeCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmSetImsNwReportModeCnf;

typedef CiEmptyPrim CiMmGetImsNwReportModeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmGetImsNwReportModeCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 CiBoolean reporting ;	 
 CiBoolean nwimsvops ;	 
 } CiMmGetImsNwReportModeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmImsvopsInd_struct {	 
 CiBoolean nwimsvops ;	 
 } CiMmImsvopsInd;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_SRVCC_IND_TYPE {	 
 CI_MM_SRVCC_STARTED = 0 ,	 
 CI_MM_SRVCC_SUCCESSFUL ,	 
 CI_MM_SRVCC_CANCELLED ,	 
 CI_MM_SRVCC_GENERAL_FAILURE ,	 
	 
 /* This one must always be last in the list! */	 
 CI_MM_SRVCC_NUM_TYPE	 
 } _CiMmSrvccType;

typedef UINT8 CiMmSrvccHType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmSrvccHandoverInd_struct {	 
 CiMmSrvccHType srvcch ;	 
 } CiMmSrvccHandoverInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSetEmergencyNumberReportModeReq_struct {	 
 CiBoolean reporting ;	 
 } CiMmSetEmergencyNumberReportModeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSetEmergencyNumberReportModeCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmSetEmergencyNumberReportModeCnf;

typedef CiEmptyPrim CiMmGetEmergencyNumberReportReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmEmergencyNumberInfo_struct {	 
 CHAR dialString [ 40 ] ;	 
 CiBitRange ServiceCat ;	 
 } CiMmEmergencyNumberInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmGetEmergencyNumberReportCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 CiBoolean reporting ; /** 0 - disable ; 1 - enable */	 
 CiMmNetworkId networkId ;	 
 UINT8 numNumbers ; /** num of emergency numbers */	 
 CiMmEmergencyNumberInfo numbers [ 15 ] ;	 
 } CiMmGetEmergencyNumberReportCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmEmergencyNumberReportInd_struct {	 
 CiBoolean reporting ; /** 0 - disable ; 1 - enable */	 
 CiMmNetworkId networkId ;	 
 UINT8 numNumbers ; /** num of emergency numbers */	 
 CiMmEmergencyNumberInfo numbers [ 15 ] ;	 
 } CiMmEmergencyNumberReportInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSetNwEmergencyBearerServicesReq_struct {	 
 CiBoolean reporting ;	 
 } CiMmSetNwEmergencyBearerServicesReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmSetNwEmergencyBearerServicesCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmSetNwEmergencyBearerServicesCnf;

typedef CiEmptyPrim CiMmGetNwEmergencyBearerServicesReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmGetNwEmergencyBearerServicesCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 CiBoolean reporting ;	 
 UINT8 emb_Iu_supp ;	 
 UINT8 emb_S1_supp ;	 
 } CiMmGetNwEmergencyBearerServicesCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmNwEmergencyBearerServicesIuInd_struct {	 
 UINT8 emb_Iu_supp ;	 
 } CiMmNwEmergencyBearerServicesIuInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmNwEmergencyBearerServicesS1Ind_struct {	 
 UINT8 emb_S1_supp ;	 
 } CiMmNwEmergencyBearerServicesS1Ind;

typedef CiEmptyPrim CiMmGetSsacStatusReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmGetSsacStatusCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 UINT8 BFVoice ; /**< parameter shows the barring factor for MMTEL voice ( 0 -16 ) */	 
 UINT8 BFVideo ; /**< parameter shows the barring factor for MMTEL video ( 0 -16 ) */	 
 UINT8 BTVoice ; /**< parameter shows the barring timer for MMTEL voice ( 0 -8 ) */	 
 UINT8 BTVideo ; /**< parameter shows the barring timer for MMTEL video ( 0 -8 ) */	 
 } CiMmGetSsacStatusCnf;

typedef UINT8 CiMmCsgWhiteListType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmCsgInfo_struct {	 
 UINT32 csgId ; /**< indicates the CSG ID of the cells which were found. */	 
 CiBoolean hnbNamePresent ; /**< indicates if HnbName is used. TRUE - HnbName is used. False - HnbName is unused.*/	 
 UINT8 hnbName [ 48 ] ; /**< text of up to 48 chars. */	 
 CiBoolean hnbTypePresent ; /**< indicates if HnbType is used. TRUE - HnbType is used. False - HnbType is unused.*/	 
 UINT8 hnbType [ 12 ] ; /**< Additional information for this CSG. */	 
 CiMmCsgWhiteListType whileListType ;	 
 } CiMmCsgInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmCsgCellInfo_struct {	 
 CiMmCsgInfo csgInfo ; /**< CSG information */	 
 CiMmNetworkId networkId ; /**< Network ID */	 
 CiMmNetworkMode mode ; /**< Cell capabilities network mode */	 
 } CiMmCsgCellInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimCsgListSearchReq_struct {	 
 UINT8 csgIndexReq ; /**< indicates the CSG index requsted to get , 0 means beging of the new search , else is reading of the last resulsts from listed offset*/	 
 } CiMmPrimCsgListSearchReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimCsgListSearchCnf_struct {	 
 CiMmResultCode result ; /**< Result code */	 
 UINT8 totalNumOfCsg ; /**< number of CSG ID which were found 0 ..MAX_NUMBER_OF_CSG ( = 40 ) */	 
 UINT8 startCsgIndex ; /**< first CSG ID inedx which were included in this message */	 
 UINT8 numCsgList ; /**< number of CSG ID which were included in this message */	 
 CiMmCsgCellInfo csgList [ 20 ] ; /**< list of all the CSG which were found and their parameters*/	 
 } CiMmPrimCsgListSearchCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimCsgSelectReq_struct {	 
 UINT32 csgId ; /**< indicates the CSG ID of the cells which were found. bits 0 -26: can receive any value. 27 - 31 should be set to 0 .*/	 
 CiMmNetworkId networkId ; /**< Network ID */	 
 CiMmNetworkMode mode ; /**< Selected network mode */	 
 } CiMmPrimCsgSelectReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimCsgSelectCnf_struct {	 
 CiMmResultCode result ; /**< Result code */	 
 } CiMmPrimCsgSelectCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimRegResultExtendedInd_struct {	 
 CiMmRegStatus RegStatus ; /**< Registration status \sa CiMmRegStatus */	 
 CiBoolean csgCellInfoPresent ; /**< Indication if CSG Information field is valid */	 
 CiMmCsgCellInfo csgCellInfo ; /**< CSG Information */	 
 } CiMmPrimRegResultExtendedInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetPowerUpNetworkModeReq_struct {	 
 CiMmPowerUpPlmnSelectionMode mode ; /**< Power up PLMN selection mode \sa CiMmPowerUpPlmnSelectionMode */	 
 } CiMmPrimSetPowerUpNetworkModeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetPowerUpNetworkModeCnf_struct {	 
 CiMmResultCode result ; /**< Result code */	 
 } CiMmPrimSetPowerUpNetworkModeCnf;

typedef CiEmptyPrim CiMmPrimGetPowerUpNetworkModeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetPowerUpNetworkModeCnf_struct {	 
 CiMmResultCode result ; /**< Result code */	 
 CiMmPowerUpPlmnSelectionMode mode ; /**< Power up PLMN selection mode \sa CiMmPowerUpPlmnSelectionMode */	 
 } CiMmPrimGetPowerUpNetworkModeCnf;

typedef UINT32 CiMmFratPlmnAction ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimFratListActionReq_struct {	 
 CiMmFratPlmnAction action ;	 
 CiMmNetworkId newPlmn ; /**< PLMN mnc / mcc to be added to FRAT list*/	 
 } CiMmPrimFratListActionReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimFratListActionCnf_struct {	 
 CiMmResultCode result ; /**< Result code */	 
 } CiMmPrimFratListActionCnf;

typedef CiEmptyPrim CiMmPrimGetFratListReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetFratListCnf_struct {	 
 UINT8 listSize ; /**< FRAT list size*/	 
 CiMmNetworkId fratList [ 20 ] ; /**< FRAT list*/	 
 } CiMmPrimGetFratListCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetSecurityCapablilityReq_struct 
 {	 
 CiBoolean nasSecCapPresent ;	 
 CiBoolean umtsRrcCACapPresent ;	 
 CiBoolean umtsRrcIPCapPresent ;	 
	 
 INT32 nasSecCap ;	 
 INT16 umtsRrcCACap ;	 
 INT16 umtsRrcIPCap ;	 
 } CiMmPrimSetSecurityCapablilityReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetSecurityCapablilityCnf_struct 
 {	 
 CiMmResultCode result ; /**< Result code */	 
 } CiMmPrimSetSecurityCapablilityCnf;

typedef CiEmptyPrim CiMmPrimGetSecurityCapablilityReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetSecurityCapablilityCnf_struct 
 {	 
 CiMmResultCode result ; /**< Result code */	 
	 
 INT32 nasSecCap ;	 
 INT16 umtsRrcCACap ;	 
 INT16 umtsRrcIPCap ;	 
 } CiMmPrimGetSecurityCapablilityCnf;

//ICAT EXPORTED ENUM 
 typedef enum CiMmCipheringIndicatorTag 
 {	 
 CI_MM_CIPHERING_NONE = 0x00 , /* Ciphering not used */	 
 CI_MM_CIPHERING_CS = 0x01 , /* EPS integrity Algorithm EIA / 1 */	 
 CI_MM_CIPHERING_PS = 0x02 ,	 
 CI_MM_CIPHERING_CS_PS = 0x03 ,	 
	 
 } 
 _CiMmCipheringIndicator;

typedef UINT8 CiMmCipheringIndicator ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimNetworkCellMatInfoInd_struct 
 {	 
 CiMmRegMode regMode ; // <mode> , from COPS	 
 CiMmRegStatus stat ; // <stat> , from CREG	 
 CiMmNetOpIdInfo netOpInfo ; // <format> , <oper> , <act> , <domain> , from COPS	 
	 
 CiBoolean lacPresent ; // in LTE NW mode , LAC maybe not existed	 
 UINT16 lac ; // <lac> , two bytes	 
 CiBoolean racPresent ; // in LTE NW mode , no RAC	 
 UINT8 rac ; // <RAC> , one byte	 
 CiBoolean cellIdPresent ;	 
 UINT32 cellId ; // <cellId>	 
 CiBoolean tacPresent ; // in LTE NW mode , no RAC	 
 UINT16 tac ; // <tac> , two bytes	 
	 
 CiBoolean nwDTMSupported ; // whether NW support DTM	 
 CiBoolean volteAvaiable ; // whether NW support VOLTE	 
 CiBoolean imsEmAvaiable ; // whether NW support emergency bearer	 
 CiBoolean t323Avaiable ;	 
	 
 UINT8 mmtelVoiceAcBarringFactor ; /*0-100 , Voice service barring factor. From 0 to 100 where 0 means 0 % probability and 100 means 100 % probability. */	 
 UINT16 mmtelVoiceAcBarringTime ; /*0-512 , Voice service mean access barring time value in seconds. */	 
 UINT8 mmtelVideoAcBarringFactor ; /*0-100 , Video service barring factor. From 0 to 100 where 0 means 0 % probability and 100 means 100 % probability. */	 
 UINT16 mmtelVideoAcBarringTime ; /*0-512 , Video service mean access barring time value in seconds. */	 
	 
 CiBoolean phyCellIdPresent ;	 
 /*LTE: phy cell ID ;	 
 *UMTS Primary scrambling code	 
 *GSM bsic: base station identity code*/	 
 UINT16 phyCellId ;	 
 // add by taow 20150506 for ciphering begin	 
 CiMmCipheringIndicator cipheringIndicator ;	 
 // add by taow 20150506 for ciphering end	 
 /*add by taow 20181102 CQ00112738 begin*/	 
 /*GSM MODE 16 -bit GSM Absolute RF channel number ; this value must be reported *	 
 *wcdma 16 -bit UMTS Absolute RF Channel Number ; this value must be reported	 
 *lte 18 -bit LTE Absolute RF Channel Number ; this value must be reported	 
 */	 
 UINT32 frequency ;	 
 /*add by taow 20181102 CQ00112738 end*/	 
 } CiMmPrimNetworkCellMatInfoInd;

typedef UINT8 CiMmEccStatus ;
typedef UINT8 CiMmEccCnfActStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimEmergencyCallStatusReq_struct 
 {	 
 CiMmEccStatus eccStatus ;	 
 CiMmAccTechMode reqAct ;	 
 } CiMmPrimEmergencyCallStatusReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimEmergencyCallStatusCnf_struct 
 {	 
 CiMmResultCode result ;	 
 CiMmAccTechMode act ;	 
 CiMmEccCnfActStatus actStatus ;	 
 } CiMmPrimEmergencyCallStatusCnf;

typedef CiEmptyPrim CiMmPrimNewAttachInd ;
typedef UINT8 CiMmUcdOpMode ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimJammingDetectionReq_struct {	 
 UINT8 mode ; /**< mode of operation */	 
 UINT8 minNumberOfGsmCarriers ; /**< The number of 2 G carriers */	 
 UINT8 gsmRxLevThreshold ; /**< Threshold level for 2 G carriers */	 
 UINT8 minNumberOfUmtsCarriers ; /**< The number of 3 G carriers */	 
 UINT8 umtsRssiLevThreshold ; /**< Threshold level for 3 G carriers */	 
 CiBoolean networkIdPresent ; /**< If true - a prefered network operator is attached */	 
 CiMmNetworkId networkId ; /**< Prefered network operator */	 
 } CiMmPrimJammingDetectionReq;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_JAMMING_STATUS {	 
 CI_MM_2G_JAMMING_NOT_DETECTED = 0 ,	 
 CI_MM_2G_JAMMING_DETECTED ,	 
 CI_MM_3G_JAMMING_NOT_DETECTED ,	 
 CI_MM_3G_JAMMING_DETECTED	 
 } _CiMmJammingStatus;

typedef UINT8 CiMmJammingStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimJammingDetectionInd_struct {	 
 CiMmJammingStatus active ; /**< jamming status report */	 
 } CiMmPrimJammingDetectionInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimJammingDetectionCnf_struct {	 
 CiMmResultCode result ; /**< result code */	 
 CiBoolean activePresent ; /**< if true - the current jamming status is return */	 
 UINT8 active ; /**< the current jamming status */	 
 } CiMmPrimJammingDetectionCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetGprsEgprsMultislotClassReq_struct {	 
 UINT8 msClassGprs ; /**< Value is 10 or 12 . Define the GPRS multislot Class according to 3 GPP TS45.002 */	 
 UINT8 msClassEgprs ; /**< Value is 10 or 12 . Define the EGPRS multislot Class according to 3 GPP TS45.002*/	 
 } CiMmPrimSetGprsEgprsMultislotClassReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetGprsEgprsMultislotClassCnf_struct {	 
 CiMmResultCode result ; /**< result code */	 
 } CiMmPrimSetGprsEgprsMultislotClassCnf;

typedef CiEmptyPrim CiMmPrimGetGprsEgprsMultislotClassReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetGprsEgprsMultislotClassCnf_struct {	 
 CiMmResultCode result ; /**< result code */	 
 UINT8 msClassGprs ; /**< Value is 10 or 12 . Define the GPRS multislot Class according to 3 GPP TS45.002 */	 
 UINT8 msClassEgprs ; /**< Value is 10 or 12 . Define the EGPRS multislot Class according to 3 GPP TS45.002*/	 
 } CiMmPrimGetGprsEgprsMultislotClassCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIMM_OPERATOR_NAME_SOURCE {	 
 CI_MM_OPERATOR_NAME_EONS , /**< EF_OPL and EF_PNN files.*/	 
 CI_MM_OPERATOR_NAME_NITZ , /**< NITZ service.*/	 
 CI_MM_OPERATOR_NAME_CPHS , /**< CPHS Operator Name string.*/	 
 CI_MM_OPERATOR_NAME_MT , /**< MT hardcoded operator name.*/	 
 CI_MM_OPERATOR_NAME_INVALID , /**< String containing the operator name to be displayed.*/	 
 } _CiMmOperatorNameSource;

typedef UINT8 CiMmOperatorDisplayType ;
typedef UINT8 CiMmDisplayCondition ;
//ICAT EXPORTED ENUM 
 typedef enum CIMM_OPERATOR_DISPLAY_TYPE {	 
 CI_MM_NUMERIC_FORMAT = 0 , /**< The network name will appear as MCC / MNC , for example 425 / 1 */	 
 CI_MM_SHORT_NAME_IN_ROM , /**< The short network name from the ROM will be returned*/	 
 CI_MM_LONG_NAME_IN_ROM , /**< The long network name from the ROM will be returned*/	 
 CI_MM_SHORT_NAME_CPHS , /**< The short network name that appears in the CPHS files on the SIM will be returned*/	 
 CI_MM_LONG_NAME_CPHS , /**< The long network name that appears in the CPHS files on the SIM will be returned*/	 
 CI_MM_SHORT_NITZ_NAME , /**< The short network name received by NITZ will be returned*/	 
 CI_MM_FULL_NITZ_NAME , /**< The full network name received by NITZ will be returned*/	 
 CI_MM_SERVICE_PROVIDER_NAME , /**< The network name that has been read from the EF_SPN file on the SIM will be returned*/	 
 CI_MM_EONS_SHORT_NAME , /**< The short network name that appears in the EONS files on the SIM will be returned*/	 
 CI_MM_EONS_LONG_NAME , /**< The long network name that appears in the EONS files on the SIM will be returned*/	 
 CI_MM_SHORT_NETWORK_NAME , /**< Not supported - for future use*/	 
 CI_MM_LONG_NETWORK_NAME , /**< Not supported - for future use*/	 
 } _CiMmOperatorDisplayType;

typedef UINT8 CiMmOperatorNameSource ;
//ICAT EXPORTED ENUM 
 typedef enum CIMM_DISPLAY_CONDITION {	 
 CI_MM_SPN_DONT_DISPLAY_PLMN = 0 , /**< display of the registered PLMN is not required when the registered PLMN is either the HPLMN or a PLMN listed in SPDI list*/	 
 CI_MM_SPN_DISPLAY_PLMN , /**< display of the registered PLMN is required when the registered PLMN is either the HPLMN or a PLMN listed in the SPDI list*/	 
 CI_MM_SPN_DISPLAY_NOT_APPLICABLE , /**< */	 
 } _CiMmDisplayCondition;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmOperatorDisplayName_struct {	 
 INT8 Length ; /**< The length of the string*/	 
 char OperatorName [ 128 ] ; /**< String containing the operator name to be displayed.*/	 
 CiMmOperatorNameSource OperatorNameSource ; /**< Source of returned operator name. */	 
 } CiMmOperatorDisplayName;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetDisplayOperatorNameReq_struct {	 
 CiMmOperatorDisplayType type ; /**< Which type of network name should be returned. See CiMmOperatorDisplayType_enum */	 
 } CiMmPrimGetDisplayOperatorNameReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetDisplayOperatorNameCnf_struct {	 
 CiMmResultCode result ; /**< Result code */	 
 CiMmOperatorDisplayType type ; /**< Which type of network name should be returned. See CiMmOperatorDisplayType_enum */	 
 CiMmOperatorDisplayName OperatorName ; /**< The requested operator name to be displayed. See CiMmOperatorDisplayName_struct */	 
 CiMmDisplayCondition DisplayCondition ; /**< The display condition indicated by the SIM. see CiMmDisplayCondition_enum*/	 
 } CiMmPrimGetDisplayOperatorNameCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimEcallRegReq_struct {	 
 CiBoolean active ; /**< TRUE - New requested implementaion is acrive ; FALSE - Normal operation*/	 
 } CiMmPrimEcallRegReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimEcallRegCnf_struct {	 
 CiMmResultCode ResultCode ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimEcallRegCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMMRpmPdpBlockInfoTag 
 {	 
 CiString apn ;	 
 UINT16 pdpBlockTime ;	 
 CiMmRpmPdpBlockReason pdpBlockReason ;	 
 /*Lilei , CQ00134598 , 20220418 , begin*/	 
 UINT8 F1 ;	 
 UINT8 F2 ;	 
 UINT8 F3 ;	 
 UINT8 F4 ;	 
 /*Lilei , CQ00134598 , 20220418 , end*/	 
 } CiMMRpmPdpBlockInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmRpmParamsInfoTag 
 {	 
 UINT8 N1const ; /**< Amount of application resets allowed by RPM , this value will be constant either default or value from SIM */	 
	 
 UINT8 N1 ; /**< Amount of application resets allowed by RPM. 0x00 requirement is disabled , 0x01 to 0xFF number of resets per hour */	 
 UINT8 T1 ; /**< Time to wait before PS is reset following a " Permanent " MM / GMM reject cause. 0x00 requirement is disabled , 0x01 to 0xFE in 6 minutes , 0xFF Time value to use T1_ext */	 
 UINT8 F1 ; /**< Counter that decides how many times a PDP activation can be made when PDP activation is ignored by the NW. 0x00 requirement is disabled , 0x01 to 0xFF the max attempts allowed */	 
 UINT8 F2 ; /**< Counter that decides how many times a PDP activation can be made when PDP activation is rejected by the NW with a " Permanent " reject. 0x00 requirement is disabled , 0x01 to 0xFF the max attempts allowed */	 
 UINT8 F3 ; /**< Counter that decides how many times a PDP activation can be made when PDP activation is rejected by the NW with a " Temporary " reject. 0x00 requirement is disabled , 0x01 to 0xFF the max attempts allowed */	 
 UINT8 F4 ; /**< Counter that decides how many times a PDP activation / deactivation pair can be made. 0x00 disabled , 0x01 to 0xFF the max attempts allowed */	 
	 
 UINT8 LR1 ; /**< Every LR1 hours the CBR1 counter will be decremented by 1 ( if it is 0 the requirement is disabled ) */	 
 UINT8 LR2 ; /**< Every LR2 hours the CR1 counter will be decremented by 1 ( if it is 0 the requirement is disabled ) */	 
 UINT8 LR3 ; /**< Every LR3 hours the CPDP1-4 counters will be decremented by 1 ( if it is 0 the requirement is disabled ) */	 
	 
 UINT8 CBR1 ; /**< Counter that holds the number of application resets that were blocked by the RPM because of N1 limitation. 0x00 to 0xFF */	 
 UINT8 CR1 ; /**< Counter that holds the number of times the PS was reset because of T1 expiration. 0x00 to 0xFF */	 
 UINT8 CPDP1 ; /**< Counter that holds the number of times a PDP activation req was rejected by RPM because of F1 limitation. 0x00 to 0xFF */	 
 UINT8 CPDP2 ; /**< Counter that holds the number of times a PDP activation req was rejected by RPM because of F2 limitation. 0x00 to 0xFF */	 
 UINT8 CPDP3 ; /**< Counter that holds the number of times a PDP activation req was rejected by RPM because of F3 limitation. 0x00 to 0xFF */	 
 UINT8 CPDP4 ; /**< Counter that holds the number of times a PDP activation req was rejected by RPM because of F4 limitation. 0x00 to 0xFF */	 
	 
 UINT8 Version ; /**< Holds the current RPM version. 0x00 no version info , 0x01 to 0xFF for Version 1 ~255 */	 
	 
 CiBoolean rpmEnabledFileExists ; /**< TRUE - EF_RPM Enabled flag file exists on SIM , FALSE - EF_RPM Enabled flag file doesn ' t exist on SIM */	 
 CiBoolean rpmParamsExists ; /**< TRUE - EF_RPM Params file exists on SIM , FALSE - EF_RPM Params file doesn ' t exist on SIM */	 
 CiBoolean rpmOperLrCountersExists ; /**< TRUE - EF_RPM Operational Management Counters Leak Rate file exists on SIM , FALSE - EF_RPM Operational Management Counters Leak Rate file doesn ' t exist on SIM */	 
 CiBoolean rpmOperCountersExists ; /**< TRUE - EF_RPM Operational Management Counters file exists on SIM , FALSE - EF_RPM Operational Management Counters file doesn ' t exist on SIM */	 
 CiBoolean rpmVersionExists ; /**< TRUE - EF_RPM Version file exists on SIM , FALSE - EF_RPM Version file doesn ' t exist on SIM */	 
 } CiMmRpmParamsInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimRpmInfoCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 CiBoolean att_SIM ; /**< Is SIM AT&T */	 
 CiBoolean rpmSim ; /**< Is RPM SIM AT&T */	 
 CiBoolean RpmEnabled ; /**< Is RPM enabled */	 
	 
 CiMMRpmPdpBlockInfo pdpBlockInfo [ 4 ] ;	 
 UINT16 resetBlockTime ;	 
	 
 CiMmRpmParamsInfo rpmData ; /**< RPM parameters */	 
 } CiMmPrimRpmInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimRpmInfoInd_struct {	 
 CiBoolean att_SIM ; /**< Is SIM AT&T */	 
 CiBoolean rpmSim ; /**< Is RPM SIM AT&T */	 
 CiBoolean RpmEnabled ; /**< Is RPM enabled */	 
	 
 CiMMRpmPdpBlockInfo pdpBlockInfo [ 4 ] ;	 
 UINT16 resetBlockTime ;	 
	 
 CiMmRpmParamsInfo rpmData ; /**< RPM parameters */	 
 } CiMmPrimRpmInfoInd;

//ICAT EXPORTED ENUM 
 typedef enum CIMmSELECTMODES_TAG {	 
 CI_MM_SELECT_AUTO = 0 ,	 
 CI_MM_SELECT_MANUAL ,	 
	 
 CI_MM_NUM_SELECT_MODES	 
 } _CiMmSelectMode;

typedef UINT8 CiMmSelectMode ;
//ICAT EXPORTED ENUM 
 typedef enum CIMMUSERNWMODES_TAG {	 
 CI_MM_USER_NW_GSM = 0 , /**< GSM */	 
 CI_MM_USER_NW_UMTS , /**< UMTS */	 
 CI_MM_USER_NW_GSM_UMTS , /**< GSM_UMTS */	 
 CI_MM_USER_NW_LTE , /**< LTE */	 
 CI_MM_USER_NW_GSM_LTE , /**< GSM_LTE */	 
 CI_MM_USER_NW_UMTS_LTE , /**< UMTS_LTE */	 
 CI_MM_USER_NW_GSM_UMTS_LTE , /**< GSM_UMTS_LTE */	 
	 
 CI_MM_NUM_NW_MODES	 
	 
 } _CiMmUserNetworkMode;

typedef UINT8 CiMmUserNetworkMode ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetNetworkSelectionReq_struct {	 
 CiMmUserNetworkMode preferredMode ;	 
 CiMmSelectMode selectionMode ;	 
 CiMmUserNetworkMode networkMode ;	 
 } CiMmPrimSetNetworkSelectionReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetNetworkSelectionCnf_struct {	 
 CiMmResultCode rc ;	 
 } CiMmPrimSetNetworkSelectionCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmCellMeas_struct 
 {	 
 UINT8 rsrp ;	 
 UINT8 rsrq ;	 
 INT16 rssi ;	 
 INT8 sinr ;	 
 } 
 CiMmCellMeas;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmLteCaBandInfo_struct 
 {	 
 UINT8 dlBandwidth ; /**<0 - 1.400000 M , 1 - 3 M , 2 - 5 M , 3 - 10 M , 4 - 15 M , 5 - 20 M */	 
 UINT16 band ;	 
 UINT32 dlEuArfcn ;	 
 Boolean measValid ;	 
 CiMmCellMeas measResult ;	 
 } 
 CiMmLteCaBandInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmLteRrcPcell_struct {	 
 UINT16 Pci ;	 
 UINT32 tac ;	 
 CiMmLteCaBandInfo BandInfo ;	 
	 
 } CiMmLteRrcPcell;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmLteRrcScell_struct {	 
 UINT16 Pci ;	 
 UINT8 ScellStatus ;	 
 CiMmLteCaBandInfo BandInfo ;	 
 } CiMmLteRrcScell;

typedef CiEmptyPrim CiMmPrimGetLteCaInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetLteCaInfoCnf_struct {	 
 CiMmResultCode rc ;	 
 CiMmLteRrcPcell PcellInfo ;	 
 CiMmLteRrcScell ScellInfo ;	 
 } CiMmPrimGetLteCaInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmNetOpNameInfo_struct {	 
 CiMmOperatorId LongAlphaId ; /**<Long Alphanumeric Operator ID */	 
 CiMmNetworkId NetworkId ; /**< Network ID \sa CiMmNetworkId_struct */	 
 } CiMmNetOpNameInfo;

//ICAT EXPORTED STRUCT 
 typedef CiEmptyPrim CiMmPrimGetOperatorInfoReq ; 
 
 // ICAT EXPORTED ENUM 
 typedef enum CIMMROAMINGSTATUS_TAG {	 
 CI_MM_ROAMING_NONE = 0 ,	 
 CI_MM_ROAMING_ON ,	 
 CI_MM_ROAMING_OFF ,	 
	 
	 
 CI_MM_NUM_ROAMING	 
	 
 } _CiMmRoamingStatus;

typedef UINT8 CiMmRoamingStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetOperatorInfoCnf_struct {	 
 CiMmResultCode Result ; /**< Result code */	 
 CiMmNetOpNameInfo RPlmn ; /**< Current registration mode */	 
 CiMmNetOpNameInfo HPlmn ; /**< Current network / operator ID information */	 
 CiMmRoamingStatus RoamingStatus ;	 
 } CiMmPrimGetOperatorInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimOperatorStatusInd_struct {	 
 CiMmNetOpNameInfo RPlmn ; /**< Current registration mode */	 
 CiMmNetOpNameInfo HPlmn ; /**< Current network / operator ID information */	 
 CiMmRoamingStatus RoamingStatus ;	 
 } CiMmPrimOperatorStatusInd;

typedef UINT8 CiMmNetworkRegStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetNetworkRegistrationStatusInfoCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 CiMmNetworkRegStatus RegStatus ; /**< Registration status \sa CiMmRegStatus */	 
 CiMmAccTechMode AcT ; /**< Network access technology ( GSM , UTRAN , LTE etc. ) \sa CiMmAccTechMode */	 
 } CiMmPrimGetNetworkRegistrationStatusInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimFirstSearchedNetworkOperatorInd_struct {	 
 CiBoolean Present ;	 
 CiMmNetworkId NetworkId ; /**< Network ID information \sa CiMmNetworkId */	 
 CiMmAccTechMode AccTchMode ; /**< Network access technology ( GSM , UTRAN , etc. ) \sa CiMmAccTechMode */	 
 } CiMmPrimFirstSearchedNetworkOperatorInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimNetworkSearchInd_struct {	 
 CiMmAccTechMode Act ; /**< Access radio technology */	 
 UINT8 numPlmns ; /**< Number of shared PLMNs in that cell */	 
 CiMmNetworkId plmns [ 20 ] ;	 
 INT32 rssiOrRscpOrRsrp [ 20 ] ; /**< 2 G:RSSI ; 3 G:RSCP ; 4 G:RSRP*/	 
 INT32 rsrqOrEcno [ 20 ] ; /**< 2 G: NA ; 3 G:rsrqOrEcno means UMTS ecno ; 4 G: rsrqOrEcno means LTE rsrq*/	 
 UINT32 freq [ 20 ] ;	 
	 
 } CiMmPrimNetworkSearchInd;

typedef CiEmptyPrim CiMmPrimGetCellLockInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetCellLockInfoCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 CiMmCellLockMode mode ; /**< Cell lock mode \sa CiMmCellLockMode */	 
 CiMmCellLockActMode act ; /**< Network mode \sa CiMmNetworkMode */	 
 UINT8 bandValue ;	 
 UINT32 freq ; /**< Absolute radio frequency channel number ; GSM number 0 -1023 , TD number 10054 -10121 and 9404 -9596 */	 
 INT16 cellId ; /**< Cell parameter ID This parameter if valid for 3 G cells only 0 -127 , and for TD LTE cells only 0 -503 */	 
 } CiMmPrimGetCellLockInfoCnf;

//ICAT EXPORTED ENUM 
 /** \remarks Common Data Section */ 
 typedef enum CIMM_OOS_MODE 
 {	 
 CIMM_OOS_MODE_DISABLE = 0 ,	 
 CIMM_OOS_MODE_ENABLE ,	 
	 
	 
 CIMM_NUM_OOS_MODES ,	 
 } _CiMmOosMode;

typedef UINT8 CiMmOosMode ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetOosPhasePeriodReq_struct {	 
 CiMmOosMode mode ;	 
 UINT32 oosPhasePeriod [ 3 ] ;	 
	 
 } CiMmPrimSetOosPhasePeriodReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetOosPhasePeriodCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
	 
 } CiMmPrimSetOosPhasePeriodCnf;

typedef CiEmptyPrim CiMmPrimGetOosPhasePeriodReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetOosPhasePeriodCnf_struct {	 
 CiMmResultCode result ;	 
 CiMmOosMode mode ;	 
 UINT32 oosPhasePeriod [ 3 ] ;	 
	 
 } CiMmPrimGetOosPhasePeriodCnf;

//ICAT EXPORTED ENUM 
 typedef enum CIMMGSMBNADSCAN_TAG {	 
 CI_MM_SCAN_GSM_NONE = 0 ,	 
 CI_MM_SCAN_GSM900 = 0x01 , /**< P GSM 900 band */	 
 CI_MM_SCAN_GSM1800= 0x02 , /**< DCS 1800 band */	 
 CI_MM_SCAN_GSM850 = 0x04 , /**< GSM 850 band */	 
 CI_MM_SCAN_GSM1900 =0x08 , /**< PCS 1900 band */	 
	 
	 
 CI_MM_NUM_GSM_BAND	 
 } _CiMmGSMBandScan;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetBandsScanConfigReq_struct {	 
 CiMmUserNetworkMode networkMode ;	 
 CiBitRange gsmBand ;	 
 /**< A hexadecimal value that specifies the GSM frequency band. If it is set to 0 , it means not to change GSM frequency band. Range: 0 -FFFFFFFF.	 
 ( e.g.: 0x 3 = 1 ( GSM900 ) + 2 ( GSM1800 ) ) .	 
 0 No change	 
 1 GSM900 -->PGSM_BAND_BIT ( B8 )	 
 2 GSM1800 ( B3 )	 
 4 GSM850 ( B5 )	 
 8 GSM1900 ( B2 )	 
	 
 FFFFFFFF Any frequency band*/	 
 CiBitRange umtsBand ;	 
 /**< A hexadecimal value that specifies the WCDMA frequency band. If it is set to 0 , it means not to change WCDMA frequency band. Range: 0 -FFFFFFFF.	 
 ( e.g.: 0x 13 = 1 ( WCDMA 2100 ) + 2 ( WCDMA 1900 ) + 10 ( WCDMA 850 ) ) .	 
 1 band 1 ( WCDMA 2100 )	 
 2 band 2 ( WCDMA 1900 )	 
 4 band 3 ( ... )	 
 8 band 4 ( WCDMA 1700 )	 
 10 band 5 ( WCDMA 850 )	 
 20 band 6 ( WCDMA 800 )	 
 40 band 7 ( ... )	 
 80 band 8 ( WCDMA 900 )	 
	 
 FFFFFFFF Any frequency band*/	 
	 
 CiBitRange eutranBandL ; /**< Bit mask indicating the required E-UTRAN bands Low part ( bands 1 - 32 ) .*/	 
 CiBitRange eutranBandH ; /**< Bit mask indicating the required E-UTRAN bands High part ( bands 33 - 43 ) .*/	 
 CiBitRange eutranBandExt ; /**< Bit mask indicating the required E-UTRAN bands Extended part ( bands 65 - 69 ) . */	 
 /**< A hexadecimal value that specifies the LTE frequency band. If it is set to 0 or 0x40000000 , it means not to change LTE frequency band. Range: 0 -7FFFFDF3FFF	 
 ( e.g.: 0x15 =0x1 ( LTE B1 ) + 0x4 ( LTE B3 ) + 0x10 ( LTE B5 ) ) .	 
 0x1 ( CM_BAND_PREF_LTE_EUTRAN_BAND1 ) LTE B1	 
 0x4 ( CM_BAND_PREF_LTE_EUTRAN_BAND3 ) LTE B3	 
 0x10 ( CM_BAND_PREF_LTE_EUTRAN_BAND5 ) LTE B5	 
 0x40 ( CM_BAND_PREF_LTE_EUTRAN_BAND7 ) LTE B7	 
 0x80 ( CM_BAND_PREF_LTE_EUTRAN_BAND8 ) LTE B8	 
 0x80000 ( CM_BAND_PREF_LTE_EUTRAN_BAND20 ) LTE B20	 
	 
 ( eutranBandL 0xFFFFFFFF && eutranBandH 0xFFFFFFFF && eutranBandExt 0xFFFFFFFF	 
 ( CM_BAND_PREF_ANY ) Any frequency band ) */	 
	 
 } CiMmPrimSetBandsScanConfigReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetBandsScanConfigCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
	 
 } CiMmPrimSetBandsScanConfigCnf;

typedef CiEmptyPrim CiMmPrimGetBandsScanConfigReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetBandsScanConfigCnf_struct {	 
 CiMmResultCode result ;	 
 CiMmUserNetworkMode networkMode ;	 
 CiBitRange gsmBand ;	 
 CiBitRange umtsBand ;	 
	 
 CiBitRange eutranBandL ; /**< Bit mask indicating the required E-UTRAN bands Low part ( bands 1 - 32 ) .*/	 
 CiBitRange eutranBandH ; /**< Bit mask indicating the required E-UTRAN bands High part ( bands 33 - 43 ) .*/	 
 CiBitRange eutranBandExt ; /**< Bit mask indicating the required E-UTRAN bands Extended part ( bands 65 - 69 ) . */	 
	 
	 
 } CiMmPrimGetBandsScanConfigCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmBandsScanResultTag /* Used to report frequencies of each PLMN*/ 
 {	 
 CiMmAccTechMode act ; /**< Access radio technology */	 
 UINT32 band ; /**< lte / umts / gsm band*/	 
 UINT32 freq ;	 
 INT32 rscpOrGsmRssi ; /**< 2 G:RSSI ; 3 G:RSCP ; 4 G:RSRP*/	 
 INT32 rsrqOrEcno ; /**< 2 G: NA ; 3 G:rsrqOrEcno means UMTS ecno ; 4 G: rsrqOrEcno means LTE rsrq*/	 
	 
 UINT16 pciOrpscOrbsic ; /**< 2 G:bsic 3 G:psc , 4 G:pci*/	 
 UINT16 tacOrLac ; /**<lte / gsm / umts use*/	 
 UINT32 cellId ; /**<gsm / umts / LTE use*/	 
 INT16 rxlev ; /**< only gsm use */	 
 INT16 c1 ; /**< only gsm use*/	 
 INT16 rssi ; /**< use in LTE , umts */	 
	 
 CiBoolean gprsSupported ; /**<only gsm use*/	 
 CiBoolean cellBarred ; /**< lte / gsm / umts use*/	 
 /*modify by taow CQ00143894 20230518 begin*/	 
 UINT8 dlBandwidth ; /**< 0 : 1.400000 MHZ , 1 : 3 MHZ , 2 : 5 MHZ , 4 : 10 MHZ , 5 : 15 MHZ , 6 : 20 MHZ. */	 
 UINT8 reserved0 ;	 
 UINT16 reserved1 ;	 
 // UINT32 reserved1 ;	 
 /*modify by taow CQ00143894 20230518 begin*/	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
 UINT32 reserved4 ;	 
 UINT32 reserved5 ;	 
 UINT32 reserved6 ;	 
	 
	 
 } CiMmBandsScanResult;

typedef CiEmptyPrim CiMmPrimGetBandsScanReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetBandsScanCnf_struct {	 
 CiMmResultCode result ;	 
 } CiMmPrimGetBandsScanCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimGetBandsScanInd_struct {	 
	 
 CiMmOperatorId longAlphaId ; /**< Long alphanumeric operator ID \sa CiMmOperatorId_struct */	 
 CiMmOperatorId shortAlphaId ; /**< Short alphanumeric operator ID \sa CiMmOperatorId */	 
 CiMmNetworkId networkId ; /**< Network ID information \sa CiMmNetworkId */	 
 UINT32 numScanResult ;	 
 CiMmBandsScanResult scanResult [ 20 ] ;	 
	 
 } CiMmPrimGetBandsScanInd;

typedef CiEmptyPrim CiMmPrimAbortBandsScanReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimAbortBandsScanCnf_struct {	 
 CiMmResultCode result ;	 
 } CiMmPrimAbortBandsScanCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimNwEcallOverImsSupportInd_struct {	 
 UINT8 eCall_IMS_supp ;	 
 } CiMmPrimNwEcallOverImsSupportInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimImsEcallRegReq_struct {	 
 CiBoolean active ; /**< TRUE - New requested implementaion is acrive ; FALSE - detach operation*/	 
 } CiMmPrimImsEcallRegReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimImsEcallRegCnf_struct {	 
 CiMmResultCode result ;	 
 } CiMmPrimImsEcallRegCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetRpmReq_struct {	 
 UINT8 option ; /**< Set options. 0 : RPM enabled ; 1 : RPM params ; 2 : RPM LR */	 
	 
 CiBoolean rpmEnabledPresent ; /**< whether <rpmEnabled> is set or not */	 
 CiBoolean rpmEnabled ; /**< Is RPM enabled / disabled */	 
	 
 /**< RPM params */	 
 CiBoolean N1constPresent ;	 
 CiBoolean T1Present ;	 
 CiBoolean F1Present ;	 
 CiBoolean F2Present ;	 
 CiBoolean F3Present ;	 
 CiBoolean F4Present ;	 
 UINT8 N1const ; /**< Amount of application resets allowed by RPM , this value will be constant either default or value from SIM */	 
 UINT8 T1 ; /**< Time to wait before PS is reset following a " Permanent " MM / GMM reject cause. 0x00 requirement is disabled , 0x01 to 0xFE in 6 minutes , 0xFF Time value to use T1_ext */	 
 UINT8 F1 ; /**< Counter that decides how many times a PDP activation can be made when PDP activation is ignored by the NW. 0x00 requirement is disabled , 0x01 to 0xFF the max attempts allowed */	 
 UINT8 F2 ; /**< Counter that decides how many times a PDP activation can be made when PDP activation is rejected by the NW with a " Permanent " reject. 0x00 requirement is disabled , 0x01 to 0xFF the max attempts allowed */	 
 UINT8 F3 ; /**< Counter that decides how many times a PDP activation can be made when PDP activation is rejected by the NW with a " Temporary " reject. 0x00 requirement is disabled , 0x01 to 0xFF the max attempts allowed */	 
 UINT8 F4 ; /**< Counter that decides how many times a PDP activation / deactivation pair can be made. 0x00 disabled , 0x01 to 0xFF the max attempts allowed */	 
	 
 /**< RPM LR */	 
 CiBoolean LR1Present ;	 
 CiBoolean LR2Present ;	 
 CiBoolean LR3Present ;	 
 UINT8 LR1 ; /**< Every LR1 hours the CBR1 counter will be decremented by 1 ( if it is 0 the requirement is disabled ) */	 
 UINT8 LR2 ; /**< Every LR2 hours the CR1 counter will be decremented by 1 ( if it is 0 the requirement is disabled ) */	 
 UINT8 LR3 ; /**< Every LR3 hours the CPDP1-4 counters will be decremented by 1 ( if it is 0 the requirement is disabled ) */	 
 } CiMmPrimSetRpmReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetRpmCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimSetRpmCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiPlmnTag 
 {	 
 UINT16 mcc ; /**< 3 -digit country code */	 
 UINT16 mnc ; /**< 3 -digit network code */	 
 UINT16 accessTechnology ;	 
	 
 } CiPlmn;

//ICAT EXPORTED STRUCT 
 typedef struct CiArfcnListForCuTag 
 {	 
 UINT16 accessTechnology ;	 
 UINT8 numArfcn ;	 
 UINT32 arfcnList [ 8 ] ;	 
 } 
 CiArfcnListForCu;

//ICAT EXPORTED STRUCT 
 typedef struct CiUarfcnInsrtFromCuTag 
 {	 
 CiPlmn reqPlmn ;	 
 CiArfcnListForCu arfcnInsrtFromCu ;	 
 } CiUarfcnInsrtFromCu;

//ICAT EXPORTED STRUCT 
 typedef struct CiUarfcnListForCuTag 
 {	 
 CiPlmn reqPlmn ;	 
 CiArfcnListForCu arfcnListForCu [ 3 ] ;	 
 } CiUarfcnListForCu;

//ICAT EXPORTED STRUCT 
 typedef struct CiModemInfoTag 
 {	 
 UINT8 cat ; /**< 1 , cat1 ; 4 , cat4 ; */	 
 UINT8 rel ; /**<cat1 , 9 or 13 ; cat4 , 4 ; */	 
 UINT8 antType ;	 
 UINT16 xo ; /**<0 , TCXO ; 1 , DCXO*/	 
 UINT8 resev [ 28 ] ;	 
 } CiModemInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPrimSetSelectVsimReq_struct {	 
 UINT8 vsimEnable ; /* vsimEnable 0 :disable VSIM ; 1 : enable VSIM*/	 
 UINT8 resevered ;	 
 } CiMmPrimSetSelectVsimReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMmPriSetSelectVsimCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 } CiMmPrimSetSelectVsimCnf;

typedef CiEmptyPrim CiMmPrimGetSelectVsimReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiMmPriGetSelectVsimCnf_struct {	 
 CiMmResultCode result ; /**< Result code \sa CiMmResultCode */	 
 UINT8 vsimEnable ; /* vsimEnable 0 :disable VSIM ; 1 : enable VSIM*/	 
 UINT8 resevered ;	 
 } CiMmPrimGetSelectVsimCnf;

//ICAT EXPORTED ENUM 
 typedef enum CI_DAT_PRIM {	 
 CI_DAT_PRIM_GET_MAX_PDU_SIZE_REQ = 1 , /**< \brief Requests the maximum PDU size the underlying data link can send and receive\details */	 
 CI_DAT_PRIM_GET_MAX_PDU_SIZE_CNF , /**< \brief Confirms the request to get the maximum PDU size the underlying transport link can send and receive	 
 * \details It is assumed that the upper layer of CI segments and assembles data based on this primitive.*/	 
 CI_DAT_PRIM_SEND_REQ , /**< \brief Requests CS / PS data	 
 * \details This primitive is kept for backward compatibility. Instead , use CI_DAT_PRIM_SEND_DATA_OPT_REQ.*/	 
 CI_DAT_PRIM_SEND_CNF , /**< \brief Confirms the request to send CS / PS data	 
 * \details This primitive is kept for backward compatibility. Instead , use CI_DAT_PRIM_SEND_DATA_OPT_CNF.*/	 
 CI_DAT_PRIM_RECV_IND , /**< \brief Indicates receipt of CS / PS data	 
 * \details This primitive is kept for backward compatibility. Instead , use CI_DAT_PRIM_RECV_DATA_OPT_IND.*/	 
 CI_DAT_PRIM_RECV_RSP , /**< \brief Responds confirming receipt of CS / PS data	 
 * \details This primitive is kept for backward compatibility. Instead , use CI_DAT_PRIM_RECV_DATA_OPT_RSP.*/	 
 CI_DAT_PRIM_OK_IND , /**< \brief Indicates that a data connection was established	 
 * \details The data connection link should be set up using primitives in the CC or PS service group.	 
 * This primitive indicates that a data connection has been established and that data send and receive primitives can be used.*/	 
 CI_DAT_PRIM_NOK_IND , /**< \brief Indicates that a data connection was disconnected	 
 * \details The data connection link should be deactivated using primitives in the CC or PS	 
 * service group before this primitive is used. After this primitive , sending and receiving data through the corresponding data connection is not allowed.*/	 
 /* Begin of ACI optimization for data channel */	 
 CI_DAT_PRIM_SEND_DATA_OPT_REQ , /**< \brief Requests to send PS data over the optimized data plane	 
 * \details CI does not manipulate data by itself. It is a proxy , forwarding and receiving data between the application subsystem and cellular subsystem.	 
 * The maximum PDU size tells the upper layer of CI the throughput limitation between the application subsystem and cellular subsystem.	 
 * For example , for IP data , the upper layer of CI should build the IP packet based on the maximum PDU size or do IP fragmentation	 
 * if the IP packet size is greater than the maximum PDU size.	 
 * The CI does not send or receive incomplete IP packets.	 
 * The same concept is applied to PPP data: the upper layer of CI makes sure the PPP data sent and received at the CI level is a whole PPP frame.	 
 * For raw data ( such as CS streaming data ) , the upper layer of CI should split the raw data based on the maximum PDU size.\n	 
 * The data connection link should be set up using primitives in the CC or PS service group before this primitive is used.	 
 * For the data to be sent over the optimized data plane ,	 
 * the CI_PS_PRIM_ENTER_DATA_STATE_REQ primitive must have been sent with the ' optimizedData ' flag set to TRUE.	 
 * To avoid buffer overflow and data loss , do not send a new CI_DAT_PRIM_SEND_DATA_OPT_REQ primitive before a CI_DAT_PRIM_SEND_DATA_OPT_CNF primitive is received.	 
 * The data buffer can be freed or reused when the ' free primitive memory ' callback function of the	 
 * CI_DAT_PRIM_SEND_DATA_OPT_REQ primitive is called by the lower layer ; this may happen before or after the	 
 * CI_DAT_PRIM_SEND_DATA_OPT_CNF primitive is sent. */	 
 CI_DAT_PRIM_SEND_DATA_OPT_CNF = 10 , /**< \brief Confirms the request to send PS data over the optimized data plane \details */	 
 CI_DAT_PRIM_RECV_DATA_OPT_IND , /**< \brief Indicates that PS data was received over the optimized data plane	 
 * \details It is assumed that the upper layer of CI has segmented the data based on the	 
 * CI_DAT_PRIM_GET_MAX_PDU_SIZE_CNF primitive.	 
 * The data connection link must have been set up using primitives in the PS service group before this primitive can be used.	 
 * For the data to be sent over the optimized data plane , the CI_PS_PRIM_ENTER_DATA_STATE_REQ	 
 * primitive must have been sent with the ' optimizedData ' flag set to TRUE.	 
 * To avoid buffer overflow and data loss , do not send a new CI_DAT_PRIM_RECV_DATA_OPT_IND primitive before a CI_DAT_PRIM_RECV_DATA_OPT_RSP primitive is received.	 
 * The Rx data buffer must be made available for reuse by the lower layer ; for this purpose ,	 
 * invoke the ' free primitive memory ' callback function of the CI_DAT_PRIM_RECV_DATA_OPT_IND primitive ( if it was registered ) .	 
 */	 
 CI_DAT_PRIM_RECV_DATA_OPT_RSP , /**< \brief Responds confirming receipt of CS / PS data over the optimized data plane	 
 * \details Response to received PS data over the optimized data plane.*/	 
 CI_DAT_PRIM_SET_UL_TP_IND_REQ , /**< \brief Requests communication subsystem to enable / disable UL throughput indications and sets the report interval */	 
 CI_DAT_PRIM_SET_UL_TP_IND_CNF , /**< \brief Confirms previous TP reports request */	 
 CI_DAT_PRIM_UL_TP_IND , /**< \brief Indicates UL throughput reports received from COMM MAC \details These indications are disabled by default. The primitive CI_DAT_PRIM_SET_UL_TP_IND_REQ is used to enable periodic reports */	 
 /* End of ACI optimization for data channel */	 
	 
	 
 CI_DAT_PRIM_TEST_APP_REQ , /** This CI only used for internal testing , just simulate the test application*/	 
 CI_DAT_PRIM_TEST_APP_CNF ,	 
 CI_DAT_PRIM_GET_CUMULATIVE_DATA_COUNT_REQ ,	 
 CI_DAT_PRIM_GET_CUMULATIVE_DATA_COUNT_CNF ,	 
 CI_DAT_PRIM_CUMULATIVE_DATA_COUNT_IND = 20 ,	 
	 
 CI_DAT_PRIM_SET_MBMS_CMD_REQ ,	 
 CI_DAT_PRIM_SET_MBMS_CMD_CNF ,	 
 CI_DAT_PRIM_GET_MBMS_CMD_REQ ,	 
 CI_DAT_PRIM_GET_MBMS_CMD_CNF ,	 
 CI_DAT_PRIM_GET_MBMS_CMD_AREA_INFO_REQ ,	 
 CI_DAT_PRIM_GET_MBMS_CMD_AREA_INFO_CNF ,	 
 CI_DAT_PRIM_SET_MBMS_EV_REQ ,	 
 CI_DAT_PRIM_SET_MBMS_EV_CNF ,	 
 CI_DAT_PRIM_MBMS_EV_IND ,	 
	 
 /* ADD NEW COMMON PRIMITIVES HERE , BEFORE ' CI_DAT_PRIM_LAST_COMMON_PRIM ' */	 
	 
 /* END OF COMMON PRIMITIVES LIST */	 
 CI_DAT_PRIM_LAST_COMMON_PRIM	 
	 
 /* the customer specific extension primitives will be added starting from	 
 * CI_DAT_PRIM_firstCustPrim = CI_DAT_PRIM_LAST_COMMON_PRIM as the first identifier.	 
 * The actual primitive names and IDs are defined in the associated	 
 * ' ci_dat_cust_xxx.h ' file.	 
 */	 
	 
 /* DO NOT ADD ANY MORE PRIMITIVES HERE */	 
	 
 } _CiDatPrim;

//ICAT EXPORTED ENUM 
 typedef enum CIDATTYPE_TAG {	 
 CI_DAT_TYPE_PPP = 0 , /**< PPP */	 
 CI_DAT_TYPE_IP , /**< IPv4 */	 
 CI_DAT_TYPE_IPV6 , /**< IPv6 */	 
 CI_DAT_TYPE_RAW , /**< Raw data */	 
 CI_DAT_TYPE_HDLC , /**< Not supported */	 
 CI_DAT_NUM_TYPES	 
 } _CiDatType;

typedef UINT8 CiDatType ;
//ICAT EXPORTED ENUM 
 typedef enum CIRC_DAT {	 
	 
 CIRC_DAT_SUCCESS = 0 , /**< Request completed successfully */	 
 CIRC_DAT_FAILURE , /**< Request failed */	 
 CIRC_DAT_CONNECTION_FAILED , /**< Connection failed */	 
 CIRC_DAT_PDU_TOO_BIG , /**< PDU is too big */	 
 CIRC_DAT_INVALID_PARAMETER , /**< Generic error - the requested service primitive has invalid parameters */	 
 CIRC_DAT_INVALID_REQ , /**< Generic error - the requested service primitive can not be handled at current state */	 
 CIRC_DAT_SIM_NOT_READY , /**< Generic error - the requested service primitive fails because SIM is not ready */	 
 CIRC_DAT_ACCESS_DENIED , /**< Generic error - the requested service primitive fails because access is denied */	 
	 
 /* This one must always be last in the list! */	 
 CIRC_DAT_NUM_RESCODES /* Number of result codes defined */	 
 } _CiDatRc;

typedef UINT16 CiDatRc ;
//ICAT EXPORTED ENUM 
 typedef enum CIDATA_NW_TYPE_TAG {	 
	 
 CI_DATA_NW_TYPE_GPRS_EDGE = 0 , /**< NW type is GPRS or EDGE */	 
 CI_DATA_NW_TYPE_UMTS , /**< NW type is UMTS */	 
 CI_DATA_NW_TYPE_HSDPA , /**< NW type is HSDPA */	 
 /* This one must always be last in the list! */	 
 CI_DATA_NW_TYPE_NUM_TYPES /* Number of data network types defined */	 
 } _CiDataNWType;

typedef UINT8 CiDataNWType ;
//ICAT EXPORTED ENUM 
 typedef enum CIDATCONNTYPE_TAG {	 
 CI_DAT_CONNTYPE_CS = 0 , /**< CS connection */	 
 CI_DAT_CONNTYPE_PS , /**< PS connection */	 
 CI_DAT_NUM_CONNTYPES	 
 } _CiDatConnType;

typedef UINT8 CiDatConnType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDatConnInfo_struct {	 
 CiDatConnType type ; /**< Connection type \sa CiDatConnType */	 
 UINT32 id ; /**< Link ID: call ID for the CS connection ; context ID for the PS connection */	 
 } CiDatConnInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPdu_struct {	 
 CiDatType type ; /**< Data type \sa CiDatType */	 
 UINT16 len ; /**< Data length */	 
 UINT8 *data ; /**< Pointer to data */	 
 CiBoolean isLast ; /**< Indicates this is the last PDU \sa CCI API Ref Manual*/	 
 UINT8 seqNo ; /**< Sequence number for each CI data PDU */	 
 } CiDatPdu;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatUlTpInfo_struct {	 
 UINT16 cid ; /**< Context id */	 
 UINT32 sentBytes ; /**< Number of bytes sent since previous indication */	 
 UINT32 pendingBytes ; /**< Number of bytes pending in Tx queues */	 
 } CiDatUlTpInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimGetMaxPduSizeCnf_struct {	 
 CiDatRc rc ; /**< Result code \sa CiDatRc */	 
 UINT16 size ; /**< The maximum PDU size depends on the underlying data link layer protocol. */	 
 } CiDatPrimGetMaxPduSizeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimSetUlTpIndReq_struct 
 {	 
 UINT16 reportInterval ; /**< Enables TP reports from MAC at every report interval ( milli seconds ) . Setting report interval to 0 disables the reports */	 
 } CiDatPrimSetUlTpIndReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimSetUlTpIndCnf_struct 
 {	 
 CiDatRc result ; /**< Result code \sa CiDatRc */	 
 } CiDatPrimSetUlTpIndCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimSendReq_struct {	 
 CiDatConnInfo connInfo ; /**< Connection information , including the PS or CS connection type and context ID for the PS and CS connection type , respectively \sa CiDatConnInfo_struct */	 
	 
 /* # Start Contiguous Code Section # */	 
 CiDatPdu sendPdu ; /**< Transferred data PDU \sa CiDatPdu_struct */	 
 /* # End Contiguous Code Section # */	 
 } CiDatPrimSendReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimSendCnf_struct {	 
 CiDatRc rc ; /**< Result code \sa CiDatRc */	 
 CiDatConnInfo connInfo ; /**< Connection information , including the PS or CS connection type and context ID for the PS and CS connection type , respectively \sa CiDatConnInfo_struct */	 
 } CiDatPrimSendCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimRecvInd_struct {	 
 CiDatConnInfo connInfo ; /**< Connection information , including the PS or CS connection type and context ID for the PS and CS connection type , respectively \sa CiDatConnInfo_struct */	 
	 
 /* # Start Contiguous Code Section # */	 
 CiDatPdu recvPdu ; /**< Received data PDU \sa CiDatPdu_struct */	 
 /* # End Contiguous Code Section # */	 
 } CiDatPrimRecvInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimRecvRsp_struct {	 
 CiDatRc rc ; /**< Result code \sa CiDatRc */	 
 CiDatConnInfo connInfo ; /**< Connection information , including the PS or CS connection type and context ID for the PS and CS connection type , respectively \sa CiDatConnInfo_struct */	 
 } CiDatPrimRecvRsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimOkInd_struct {	 
 CiDatConnInfo connInfo ; /**< Connection information , including the PS or CS connection type and context ID for the PS and CS connection type , respectively \sa CiDatConnInfo_struct */	 
 UINT16 maxPduSize ; /**< The maximum PDU size for the connection depends on the underlying data link layer protocol. */	 
 } CiDatPrimOkInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimUlTpInd_struct {	 
 UINT32 minLimitBytes ; /**< The minimum number of bytes required to be in the mac Q in order to maintain an active UL TBF */	 
 UINT32 maxLimitBytesHint ; /**< This value may be used to calculate an optimal value for flow control on Data Tx */	 
 CiDataNWType nwType ; /**< Network type \sa CiDataNwType */	 
 UINT8 number ; /**< Number of valid UL throughput information indication elements , each context ID will have a separate indication element */	 
 CiDatUlTpInfo ulTpInfo [ 8 ] ; /**< Array of TP indications per context id \sa CiDatUlTpInfo_struct */	 
 } CiDatPrimUlTpInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimNokInd_struct {	 
 CiDatConnInfo connInfo ; /**< Connection information , including the PS or CS connection type and context ID for the PS and CS connection type , respectively \sa CiDatConnInfo_struct */	 
 } CiDatPrimNokInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimSendDataOptReq_struct {	 
	 
 CiDatConnInfo connInfo ; /**< Connection information , including the PS or CS connection type and context ID for the PS and CS connection type , respectively \sa CiDatConnInfo_struct */	 
 CiDatPdu sendPdu ; /**< Transferred data PDU \sa CiDatPdu_struct */	 
 BOOL sinkPdu ;	 
	 
 CiPsL2P l2p ;	 
	 
 } CiDatPrimSendDataOptReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimSendDataOptCnf_struct {	 
	 
 CiDatRc rc ; /**< Result code \sa CiDatRc */	 
 CiDatConnInfo connInfo ; /**< Connection information , including the PS or CS connection type and context ID for the PS and CS connection type , respectively \sa CiDatConnInfo_struct */	 
 UINT8 *pReqData ; /**< Pointer to data */	 
 } CiDatPrimSendDataOptCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimRecvDataOptInd_struct {	 
	 
 CiDatConnInfo connInfo ; /**< Connection information , including the PS or CS connection type and context ID for the PS and CS connection type , respectively \sa CiDatConnInfo_struct*/	 
 CiDatPdu recvPdu ; /**< Received data PDU \sa CiDatPdu_struct */	 
 UINT8 *pStartBuffer ; /**< Pointer to start of the buffer including data */	 
 } CiDatPrimRecvDataOptInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimRecvDataOptRsp_struct {	 
	 
 CiDatRc rc ; /**< Result code \sa CiDatRc */	 
 CiDatConnInfo connInfo ; /**< Connection information , including the PS or CS connection type and context ID for the PS and CS connection type , respectively \sa CiDatConnInfo_struct */	 
 UINT8 *pIndData ; /**< Pointer to data */	 
 UINT8 *pStartBuffer ; /**< Pointer to start of the buffer including data */	 
 CiIndicationHandle dataIndHandle ;	 
 } CiDatPrimRecvDataOptRsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimTestAppReq_struct {	 
 CiString apn ;	 
 UINT8 state ; // 0 -application disconnected ; 1 -application idle ; 2 -application transmitting	 
 UINT32 msPeriod ; // period in milli-second	 
 } CiDatPrimTestAppReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimTestAppCnf_struct {	 
 CiDatRc rc ;	 
 } CiDatPrimTestAppCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimGetCumulativeDataReq_struct {	 
	 
 UINT32 cid ; /**< Result code \sa CiDatRc */	 
 } CiDatPrimGetCumulativeDataReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimGetCumulativeDataCnf_struct {	 
 CiDatRc rc ;	 
 UINT32 cid ;	 
 UINT32 cumulativeDL ; // cumulative DL data bytes	 
 UINT32 cumulativeUL ; // cumulative UL data bytes	 
 } CiDatPrimGetCumulativeDataCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimCumulativeDataInd_struct {	 
 UINT32 cid ;	 
 UINT32 cumulativeDL ; // cumulative DL data bytes	 
 UINT32 cumulativeUL ; // cumulative UL data bytes	 
 } CiDatPrimCumulativeDataInd;

//ICAT EXPORTED ENUM 
 typedef enum Ci_DAT_MBMS_CMD_TAG 
 {	 
 CI_DAT_MBMS_CMD_ENABLER = 0 ,	 
 CI_DAT_MBMS_CMD_ACT ,	 
 CI_DAT_MBMS_CMD_DEACT ,	 
 CI_DAT_MBMS_CMD_DEACT_ALL ,	 
 CI_DAT_MBMS_CMD_SET_PREFER ,	 
 CI_DAT_MBMS_CMD_GET_NW_TIME ,	 
 CI_DAT_MBMS_CMD_GET_SIGNAL_LEVEL ,	 
 CI_DAT_MBMS_CMD_GET_NW_INFO ,	 
 CI_DAT_MBMS_CMD_GET_MODEM_STATUS ,	 
 CI_DAT_MBMS_CMD_SET_HYSTERESIS ,	 
 CI_DAT_MBMS_CMD_SET_AVAILABILITY_INFO ,	 
 CI_DAT_MBMS_CMD_GET_CURRENT_SAIS // add by taow 20150204	 
 } _CiDatMbmsCmd;

typedef UINT8 CiDatMbmsCmd ;
//ICAT EXPORTED ENUM 
 typedef enum Ci_DAT_MBMS_PREFER_TAG 
 {	 
 CI_DAT_MBMS_PREFER_NONE = 0 ,	 
 CI_DAT_MBMS_PREFER_UNICAST ,	 
 CI_DAT_MBMS_PREFER_MULTICAST	 
 } _CiDatMbmsPrefer;

typedef UINT8 CiDatMbmsPrefer ;
//ICAT EXPORTED ENUM 
 typedef enum Ci_DAT_MBMS_MODEM_STATUS_TAG 
 {	 
 CI_DAT_MBMS_MODEM_STATUS_NONE = 0 ,	 
 CI_DAT_MBMS_MODEM_STATUS_OFF ,	 
 CI_DAT_MBMS_MODEM_STATUS_ON	 
 } _CiDatMbmsModemStatus;

typedef UINT8 CiDatMbmsModemStatus ;
//ICAT EXPORTED ENUM 
 typedef enum Ci_DAT_MBMS_EV_TAG 
 {	 
 CI_DAT_MBMS_EV_SERVICE_CHANGE = 0 ,	 
 CI_DAT_MBMS_EV_NO_SERVICE ,	 
 CI_DAT_MBMS_EV_ONLY_UNICAST_AVAIL ,	 
 CI_DAT_MBMS_EV_UNICAST_AND_MBMS_AVAIL	 
 } _CiDatMbmsEv;

typedef UINT8 CiDatMbmsEv ;
//ICAT EXPORTED STRUCT 
 typedef struct CiDatMbmsTmgi_struct {	 
 UINT32 serviceId ;	 
 UINT16 mcc ;	 
 UINT16 mnc ;	 
 CiMmNetOpDigitMnc mncDigit ;	 
 } CiDatMbmsTmgi;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatMbmsSessionInfo_struct {	 
 CiDatMbmsTmgi tmgi ;	 
 CiBoolean sessionIdPresent ;	 
 UINT8 sessionId ;	 
 } CiDatMbmsSessionInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimSaiInfo_struct {	 
 UINT16 sai ;	 
 UINT8 numOfFreq ;	 
 UINT32 freq [ 10 ] ;	 
 } CiDatPrimSaiInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimSetMbmsCmdReq_struct {	 
 CiDatMbmsCmd cmd ;	 
 CiBoolean enabler ;	 
 CiDatMbmsTmgi tmgi ;	 
 CiDatMbmsPrefer prefer ;	 
 UINT8 inSessionHysteresis ;	 
 UINT8 outSessionHysteresis ;	 
 UINT8 inMbmsHysteresis ;	 
 UINT8 outMbmsHysteresis ;	 
 UINT8 numOfSai ;	 
 CiDatPrimSaiInfo saiInfo [ 30 ] ;	 
 } CiDatPrimSetMbmsCmdReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimGetMbmsCmdSaiListCnf_struct 
 {	 
 // UINT8 numOfSai ;	 
 // UINT16 sai [ CI_DAT_MBMS_MAX_CURRENT_SAI ] ;	 
 // Boolean result ;	 
 UINT8 numOfCurrentSai ;	 
 UINT16 currentSai [ 64 ] ;	 
 UINT8 numOfNeighborSai ;	 
 UINT16 neighborSai [ 64 ] ;	 
 } 
 CiDatPrimGetMbmsCmdSaiListCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPlmnIdentityTag 
 {	 
 // 3 digits of MMC	 
 UINT16 mcc ;	 
 // Length of MNC , value range ( 2 , 3 )	 
 UINT8 lenOfMnc ;	 
 // 2 -3 digits of MNC	 
 UINT16 mnc ;	 
 } CiDatPlmnIdentity;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimSetMbmsCmdCnf_struct {	 
 CiDatRc rc ; /**< Result code. \sa CiDatRc. */	 
 CiDatMbmsCmd cmd ;	 
 CiBoolean enabler ;	 
 UINT32 timingInfoHigh ;	 
 UINT32 timingInfoLow ;	 
 UINT16 signalLevel ;	 
 UINT32 cellId ;	 
 CiDatMbmsModemStatus modemStatus ;	 
 CiDatPrimGetMbmsCmdSaiListCnf currentSai ; // add by taow 20150204	 
 CiDatPlmnIdentity plmnIdentity ; // add by taow 20150428	 
 } CiDatPrimSetMbmsCmdCnf;

//ICAT EXPORTED STRUCT 
 typedef CiEmptyPrim CiDatPrimGetMbmsCmdReq ; 
 
 // ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimGetMbmsCmdCnf_struct {	 
 CiDatRc rc ; /**< Result code. \sa CiDatRc. */	 
 UINT8 numOfArea ;	 
 UINT16 areaId [ 8 ] ;	 
 } CiDatPrimGetMbmsCmdCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimGetMbmsCmdAreaInfoReq_struct {	 
 UINT16 areaId ;	 
 } CiDatPrimGetMbmsCmdAreaInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimGetMbmsCmdAreaInfoCnf_struct {	 
 CiDatRc rc ; /**< Result code. \sa CiDatRc. */	 
 UINT16 areaId ;	 
 UINT8 numOfSession ;	 
 CiDatMbmsSessionInfo sessionInfo [ 29 ] ;	 
 } CiDatPrimGetMbmsCmdAreaInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimSetMbmsEvReq_struct {	 
 CiBoolean cmd ;	 
 } CiDatPrimSetMbmsEvReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimSetMbmsEvCnf_struct {	 
 CiDatRc rc ; /**< Result code. \sa CiDatRc. */	 
 CiBoolean cmd ;	 
 } CiDatPrimSetMbmsEvCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiDatPrimMbmsEvInd_struct {	 
 CiDatMbmsEv ev ;	 
 } CiDatPrimMbmsEvInd;

//ICAT EXPORTED ENUM 
 typedef enum CI_CC_PRIM {	 
 CI_CC_PRIM_GET_NUMBERTYPE_REQ = 1 , /**< \brief Requests the type of number \details */	 
 CI_CC_PRIM_GET_NUMBERTYPE_CNF , /**< \brief Confirms the request and returns the type of number \details See CI_CC_PRIM_SET_NUMBERTYPE_REQ for internal default information.	 
 There should be no reason for an unsuccessful result.	 
 */	 
 CI_CC_PRIM_SET_NUMBERTYPE_REQ , /**< \brief Requests to set the type of number to be used for subsequent outgoing calls	 
 * \details Default values for the Address Type fields are based on the outgoing call requests themselves ( in the Dial String parameter field ) .	 
 * See also the CI_CC_PRIM_MAKE_CALL_REQ request.	 
 * For international calls ( where the ' + ' character appears as a prefix to the dial string ) , the values are:	 
 * Type of Number = CI_NUMTYPE_INTERNATIONAL	 
 * Numbering Plan = CI_NUMPLAN_E164_E163	 
 * For all other calls ( this is the SAC internal default ) , the values are:	 
 * Type of Number = CI_NUMTYPE_UNKNOWN	 
 * Numbering Plan = CI_NUMPLAN_E164_E163 */	 
 CI_CC_PRIM_SET_NUMBERTYPE_CNF , /**< \brief Confirms the request and sets the type of number to be used for subsequent outgoing call requests \details */	 
 CI_CC_PRIM_GET_SUPPORTED_CALLMODES_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_GET_SUPPORTED_CALLMODES_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_GET_CALLMODE_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_GET_CALLMODE_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_SET_CALLMODE_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_SET_CALLMODE_CNF = 10 , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_GET_SUPPORTED_DATA_BSTYPES_REQ , /**< \brief Requests supported Bearer Service Type parameter settings for data calls \details */	 
 CI_CC_PRIM_GET_SUPPORTED_DATA_BSTYPES_CNF , /**< \brief Confirms the request and returns the supported Bearer Service Type parameter settings for data calls \details There should be no reason for an unsuccessful result.*/	 
 CI_CC_PRIM_GET_DATA_BSTYPE_REQ , /**< \brief Requests currently selected Bearer Service Type information for outgoing ( and incoming ) data calls \details */	 
 CI_CC_PRIM_GET_DATA_BSTYPE_CNF , /**< \brief Confirms the request and returns currently selected Bearer Service Type information for outgoing ( and incoming ) data calls \details There should be no reason for an unsuccessful result.*/	 
 CI_CC_PRIM_SET_DATA_BSTYPE_REQ , /**< \brief Requests Bearer Service Type information for outgoing ( and incoming ) data calls	 
 * \details This information ( or the default ) is used when outgoing data calls ( or multi-mode calls with a data component )	 
 * are originated. It can also be used during mobile terminated data call setup.	 
 * Not all combinations of the Data Bearer Service Type parameters are supported for GSM / UMTS.	 
 * Other bearer capability information for outgoing and incoming calls is set up from internal defaults. */	 
 CI_CC_PRIM_SET_DATA_BSTYPE_CNF , /**< \brief Confirms the request and sets Bearer Service Type information for outgoing ( and incoming ) data calls	 
 * \details This information can be " negotiated " with the network as required , on a per-call basis. */	 
 CI_CC_PRIM_GET_AUTOANSWER_ACTIVE_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_GET_AUTOANSWER_ACTIVE_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_SET_AUTOANSWER_ACTIVE_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_SET_AUTOANSWER_ACTIVE_CNF = 20 , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_LIST_CURRENT_CALLS_REQ , /**< \brief Requests a list of current calls that are present in the mobile	 
 * \details Requests current call information for all calls.	 
 * CI_CC_PRIM_GET_CALLINFO_REQ can also be used to request call information for a specified call. */	 
 CI_CC_PRIM_LIST_CURRENT_CALLS_CNF , /**< \brief Confirms the request and returns a list of the current calls	 
 * \details Returns an array of current call information structures. CI_CC_PRIM_GET_CALLINFO_REQ can also be used to	 
 * request call information for a specified call. If there are no current calls , NumCalls = 0 , and the CallInfo array	 
 * contains no useful information. There should be no reason for an unsuccessful result. */	 
 CI_CC_PRIM_GET_CALLINFO_REQ , /**< \brief Requests current call information for a specified call identifier\details */	 
 CI_CC_PRIM_GET_CALLINFO_CNF , /**< \brief Confirms the request and returns the current call information for a specified call identifier	 
 * \details Use CI_CC_PRIM_LIST_CURRENT_CALLS_REQ to request a list of current call identifiers. For a data call , the	 
 * bearer service information may have been " negotiated " with the network. If Result indicates an error , the call	 
 * information structure contains no useful information.	 
 */	 
 CI_CC_PRIM_MAKE_CALL_REQ , /**< \brief Requests to make an outgoing call	 
 * \details Uses the default call mode and current bearer service type information ( or the appropriate defaults ) .	 
 * The default call mode is Single Mode ; therefore , a CI_CC_PRIM_MAKE_CALL_REQ request uses	 
 * the BasicCMode parameter to indicate which mode is required.	 
 * Bearer service type is set by CI_CC_PRIM_SET_DATA_BSTYPE_REQ. Other bearer capability information is set up from internal defaults.	 
 * Call options can be used to:	 
 * - Enable or disable closed user group ( CUG ) information for this call ;	 
 * - Override the CLIR option for this call ( force enable or disable ) .	 
 * CUG information is configured by CI_SS_PRIM_SET_CUG_CONFIG_REQ.	 
 * The default CLIR option is set up by CI_SS_PRIM_SET_CLIR_OPTION_REQ.	 
 * Valid dial digits are defined in " Mobile Radio Interface layer 3 specification ; Core Network Protocols - Stage 3 " , revision 3.110000 .0 , 3 GPP TS 24.008000 .	 
 * The supplied dial string can incorporate a prefix ' + ' character , to indicate that this is an international call. In this	 
 * situation , SAC uses the default Address Type information ( if necessary ) for an international call. For details ,	 
 * see the CI_CC_PRIM_SET_NUMBERTYPE_REQ request.	 
 * SAC uses the dial string digits to determine whether an emergency call is being requested.	 
 * SAC also supports fixed dialing mode ( if enabled in the SIM ) , using the fixed dialing numbers ( FDN ) list	 
 * that is stored on the SIM. For the fixed number dialing support requirements , see:	 
 * " Technical Specification Group Services and System Aspects. Service Aspects ; Service principles " , revision	 
 * 3.130000 .0 , 3 GPP TS 22.101000 , Section A.24. */	 
 CI_CC_PRIM_MAKE_CALL_CNF , /**< \brief Confirms the request to make an outgoing call \details */	 
 CI_CC_PRIM_CALL_PROCEEDING_IND , /**< \brief Indicates that an outgoing call is in progress	 
 * \details This indication is triggered by a CALL PROCEEDING notification from the network. It indicates that the outgoing	 
 * call request has been accepted , and is proceeding through the network. If in-band tones are available from the	 
 * network , the receive audio path should be enabled , so that the subscriber can hear the tones. No	 
 * explicit response is required. */	 
 CI_CC_PRIM_MO_CALL_FAILED_IND , /**< \brief Indicates that an outgoing ( mobile originated ) call failed	 
 * \details The reason for the call failure is indicated by the Cause parameter. If in-band tones are available from the	 
 * network , the receive audio path should be enabled , so that the subscriber can hear the tones.	 
 * No explicit response is required. */	 
 CI_CC_PRIM_ALERTING_IND , /**< \brief Indicates that an outgoing call is alerting	 
 * \details This indication is triggered by an ALERTING notification from the network , and indicates that the called party ' s phone is alerting.	 
 * If in-band tones ( ringback ) are available from the network , the receive audio path should be	 
 * enabled , so that the subscriber can hear the tones. Otherwise , the tones must be generated locally. */	 
 CI_CC_PRIM_CONNECT_IND = 30 , /**< \brief Indicates that an outgoing or incoming call is connected	 
 * \details This indication is triggered by a connect notification from the network , indicating that the called party has accepted and	 
 * answered the call , or an incoming call has been answered. If not already done , the audio paths should now be enabled. No explicit response is required. */	 
 CI_CC_PRIM_DISCONNECT_IND , /**< \brief Indicates that a call was disconnected	 
 * \details This indication is triggered by:	 
 * - A disconnect message received from the network , indicating network-initiated call clearing	 
 * - Mobile-initiated call clearing ( hangup )	 
 * The reason for call clearing is indicated by the Cause parameter. If not already done , the transmit and receive	 
 * audio paths should now be disabled. No explicit response is required */	 
 CI_CC_PRIM_INCOMING_CALL_IND , /**< \brief Indicates an incoming call	 
 * \details SAC allocates a unique call identifier , which must be used for all subsequent requests that are directed to this call.	 
 * The incoming call setup from the network has already been accepted , and the mobile has sent an alerting indication to the network in response.	 
 * The subscriber can answer the call , using the CI_CC_PRIM_ANSWER_CALL_REQ request.	 
 * The subscriber can refuse the call ( if allowed ) , using the CI_CC_PRIM_REFUSE_CALL_REQ request.	 
 * In either case , the subscriber must be alerted to the incoming call. */	 
 CI_CC_PRIM_CALL_WAITING_IND , /**< \brief Indicates the call waiting ( CW ) information for an incoming call	 
 * \details AC allocates a unique call identifier , which must be used for all subsequent requests that are directed at this call.	 
 * Call waiting indications are enabled or disabled by the CI_SS_SET_CW_OPTION_REQ request.	 
 * This indication is enabled by default.	 
 * This indication is received only if the call waiting supplementary service is provisioned.	 
 * First , the active call must be held , then the subscriber can decide to answer or refuse the waiting call.	 
 * No explicit response is required.*/	 
 CI_CC_PRIM_HELD_CALL_IND , /**< \brief Indicates that there is a held call	 
 * \details SAC sends this indication if an active call is released while a held call exists.	 
 * The held call can then be released or retrieved , as desired.	 
 * No explicit response is required , although a request is needed to take the call off hold.*/	 
 CI_CC_PRIM_ANSWER_CALL_REQ , /**< \brief Requests to answer an incoming call	 
 * \details If auto-answer is active ( see CI_CC_PRIM_SET_AUTOANSWER_ACTIVE_REQ ) ,	 
 * SAC may answer the incoming call automatically , and the CI_CC_PRIM_ANSWER_CALL_REQ request may not be required.	 
 * This request does not answer a waiting call.	 
 * The active call must first be held or released , which triggers SAC to send a	 
 * CI_CC_PRIM_INCOMING_CALL_IND indication for the waiting call. Then the waiting call can be answered.	 
 * This request does not switch modes for a multi-mode call ( alternating voice / data , alternating voice / fax , or voice followed by data ) . To do this , use the CI_CC_PRIM_SWITCH_CALLMODE_REQ request. */	 
 CI_CC_PRIM_ANSWER_CALL_CNF , /**< \brief Confirms the request to answer the incoming call	 
 * \details The call identifier is included as a crosscheck or confirmation.*/	 
 CI_CC_PRIM_REFUSE_CALL_REQ , /**< \brief Requests to reject an incoming call \details The incoming call may be a call waiting. */	 
 CI_CC_PRIM_REFUSE_CALL_CNF , /**< \brief Confirms the reject request */	 
 CI_CC_PRIM_MT_CALL_FAILED_IND , /**< \brief Indicates that an incoming ( mobile terminated ) call failed \details */	 
 CI_CC_PRIM_HOLD_CALL_REQ = 40 , /**< \brief Requests an active call to be held	 
 * \details This request can be used to hold the active call , if there is one.	 
 * The subscriber can subsequently:	 
 * retrieve the held call ;	 
 * set up another ( outgoing ) call ;	 
 * accept an incoming call.	 
 * If another active call is set up , the user can subsequently:	 
 * alternate between the active call and the held call ;	 
 * disconnect the active call ;	 
 * disconnect the held call ;	 
 * disconnect both the active call and the held call.	 
 * GSM allows only one call to be held at any time ( except for calls that are part of a multiparty call ) .	 
 * If a held call already exists , this request fails with an error result.*/	 
 CI_CC_PRIM_HOLD_CALL_CNF , /**< \brief Confirms the request to hold a call */	 
 CI_CC_PRIM_RETRIEVE_CALL_REQ , /**< \brief Requests a held call to be retrieved	 
 * \details This request can be used to retrieve a held call , if there is one.	 
 * For GSM , the HOLD service does not allow more than one held call ( non-multiparty ) at any time.	 
 * The CallId parameter is provided here to accommodate multi-call procedures for other 3 G protocols.	 
 * This request should not be used to perform operations on a multiparty ( MPTY ) call.	 
 * If this is attempted , the request fails with an error result.*/	 
 CI_CC_PRIM_RETRIEVE_CALL_CNF , /**< \brief Confirms the request to retrieve a held call	 
 * \details If Result is CIRC_CC_REJECTED , the cause information is reported as received in a retrieve reject message from the network.*/	 
 CI_CC_PRIM_SWITCH_ACTIVE_HELD_REQ , /**< \brief Requests an active call and a held call to be switched ( shuttle request )	 
 * \details This request is used to transfer ( shuttle ) between an active call and a held call.	 
 * The active call is held and the held call is retrieved ( becomes the active call ) .	 
 * The shuttle operation is handled by the network.	 
 * The mobile must send a hold request for the current active call , immediately followed ( see below ) by a retrieve request for the held call.	 
 * The HOLD service does not support more than one held call at any time. To avoid this , the network must receive the retrieve request within five seconds of receiving the hold request.	 
 * The same result could be achieved by sending a CI_CC_PRIM_HOLD_CALL_REQ request for the active call ,	 
 * followed by a CI_CC_RETRIEVE_CALL_REQ request for the held call.	 
 * However , the above timing requirements may not be fulfilled by this method , and the shuttle operation could fail.	 
 * Use the CI_CC_PRIM_SHUTTLE_MPTY_REQ request for shuttle operations that involve multiparty ( MPTY ) conference calls. */	 
 CI_CC_PRIM_SWITCH_ACTIVE_HELD_CNF , /**< \brief Confirms the request to switch between the active and held calls ( shuttle request )	 
 * \details */	 
 CI_CC_PRIM_CALL_DEFLECT_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_CALL_DEFLECT_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_EXPLICIT_CALL_TRANSFER_REQ , /**< \brief Requests an explicit call transfer ( ECT ) for an active call and a held call	 
 * \details This request is used to connect an active call and a held call , and then to exit both calls.	 
 * The GSM standard allows ECT for a held call and an outgoing call in the alerting state	 
 * ( an MO call that has been presented to the called party , but has not yet been answered ) .	 
 * This is described in the standard as a network option , and therefore is a valid operation only if the network supports it.	 
 * For more information , see 3 GPP TS 22.091000 .	 
 * The ECT service requires the provision of the call Hold ( HOLD ) Supplementary Service.	 
 * If the subscriber has an active call , a held call , and a call waiting ,	 
 * then after successful completion of the ECT request , the subscriber receives an incoming call indication for the waiting call.	 
 * Multiparty ( MPTY ) calls cannot be transferred by this ( or any other ) request.*/	 
 CI_CC_PRIM_EXPLICIT_CALL_TRANSFER_CNF , /**< \brief Confirms the explicit call transfer ( ECT ) request	 
 * \details If the ECT request is successfully completed , there is a normal call between the original held party and	 
 * the active / alerting party ( see 3 GPP TS 22.091000 , Section 5.800000 ) . SAC removes the call identifiers for the original	 
 * calls. An attempt to use these call identifiers in any subsequent call related request fails with Result =	 
 * CIRC_CC_INVALID_CALLID. */	 
 CI_CC_PRIM_RELEASE_CALL_REQ = 50 , /**< \brief Requests release ( hangup ) of a call ( mobile originated call clearing )	 
 * \details Requests disconnect of an active or held call.	 
 * If there is a held call and the active call is released , SAC sends a CI_CC_PRIM_HELD_CALL_IND indication for the held call. The subscriber then can either retrieve the held call or release it.	 
 * If there is a waiting call and the active call is released , SAC sends a CI_CC_PRIM_INCOMING_CALL_IND indication for the waiting call , which can then be answered or refused.	 
 * This request is also used to release individual calls in a multiparty call.	 
 * If CallId is CICC_NO_CALL_ID and there is only one call in progress , this call is released. */	 
 CI_CC_PRIM_RELEASE_CALL_CNF , /**< \brief Confirms the request to release ( hangs up ) an active or held call ( mobile originated call clearing ) */	 
 CI_CC_PRIM_RELEASE_ALL_CALLS_REQ , /**< \brief Requests release ( disconnect ) of all calls ( mobile originated call clearing )	 
 * \details For GSM , there can be only one active call and only one held call.*/	 
 CI_CC_PRIM_RELEASE_ALL_CALLS_CNF , /**< \brief Confirms the request to release ( disconnects ) all calls ( mobile originated call clearing )	 
 * \details If the calls are successfully released ( disconnected ) , SAC removes all individual call identifiers.	 
 * An attempt to use any of these call identifiers in subsequent call related requests fails with Result =	 
 * CIRC_CC_INVALID_CALLID.*/	 
 CI_CC_PRIM_SWITCH_CALLMODE_REQ , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_SWITCH_CALLMODE_CNF , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_ESTABLISH_MPTY_REQ , /**< \brief Requests establishment of a multiparty ( MPTY ) conference call	 
 * \details This request is used to establish a multiparty call , starting with an active call and a held call.	 
 * If this request completes successfully , the active and held calls are joined into a multiparty call , which	 
 * then becomes active. The original call identifiers still exist for the two calls , and both calls are now marked as	 
 * MPTY calls in their respective Call Information structures.*/	 
 CI_CC_PRIM_ESTABLISH_MPTY_CNF , /**< \brief Confirms the request to establish a multiparty ( MPTY ) conference call	 
 * \details If Result indicates an error , the MPTY identifier is not valid and should be ignored.*/	 
 CI_CC_PRIM_ADD_TO_MPTY_REQ , /**< \brief Requests a new call to be added to an existing multiparty ( MPTY ) conference	 
 * \details Before this request is sent , the existing MPTY call is held and the new call becomes active.	 
 * On successful completion of this request , the expanded MPTY call becomes active.	 
 * If a call was previously split from the MPTY call , this request can be used to add the call back into the conference. */	 
 CI_CC_PRIM_ADD_TO_MPTY_CNF , /**< \brief Confirms the request to add a new call to an existing multiparty ( MPTY ) conference call */	 
 CI_CC_PRIM_HOLD_MPTY_REQ = 60 , /**< \brief Requests an active multiparty ( MPTY ) call to be held	 
 * \details On successful completion of this request , the active MPTY call ( if there is one ) is held. */	 
 CI_CC_PRIM_HOLD_MPTY_CNF , /**< \brief Confirms the request to hold an active multiparty ( MPTY ) conference call */	 
 CI_CC_PRIM_RETRIEVE_MPTY_REQ , /**< \brief Requests a held multiparty ( MPTY ) call to be retrieved	 
 * \details On successful completion of this request , the held MPTY call ( if there is one ) becomes active.*/	 
 CI_CC_PRIM_RETRIEVE_MPTY_CNF , /**< \brief Confirms the request to retrieve a held multiparty ( MPTY ) conference call */	 
 CI_CC_PRIM_SPLIT_FROM_MPTY_REQ , /**< \brief Requests a call to be split from a multiparty ( MPTY ) conference	 
 * \details On successful completion of this request the existing MPTY call is held , except for the split call , which becomes active.	 
 * Use the CI_CC_PRIM_ADD_TO_MPTY_REQ request to add the split call back into the MPTY call. */	 
 CI_CC_PRIM_SPLIT_FROM_MPTY_CNF , /**< \brief Confirms the request to split a call from a multiparty ( MPTY ) conference call */	 
 CI_CC_PRIM_SHUTTLE_MPTY_REQ , /**< \brief Requests to shuttle between a multiparty ( MPTY ) conference call and a single call	 
 * \details The subscriber can use this request to shuttle back and forth between a multiparty ( MPTY ) call and a separate single call.	 
 * This is similar to the shuttle operation between an active call and a held call. This is how it works:	 
 * - Single call active ; MPTY call held MPTY call active , single call held \n	 
 * - MPTY call active ; single call held Single call active , MPTY call held \n	 
 * The shuttle operation is handled at the network. The mobile must send a hold ( or hold MPTY ) request for the current active call / MPTY , immediately followed ( see below ) by a retrieve ( or retrieve MPTY ) request for the held call / MPTY.	 
 * There cannot be more than one held call at any time. To avoid this , the network must receive the retrieve request within five seconds of receiving the hold request.	 
 * The same result could be achieved by sending a CI_CC_PRIM_HOLD_CALL_REQ or CI_CC_PRIM_HOLD_MPTY_REQ request for the active call / MPTY , followed by a CI_CC_RETRIEVE_CALL_REQ or CI_CC_RETRIEVE_MPTY_REQ request for the held call / MPTY. However , the above timing requirements may not be fulfilled by this method , and the shuttle operation could fail.	 
 * */	 
 CI_CC_PRIM_SHUTTLE_MPTY_CNF , /**< \brief Confirms the request to shuttle between a multiparty ( MPTY ) conference call and a single call */	 
 CI_CC_PRIM_RELEASE_MPTY_REQ , /**< \brief Requests a multiparty ( MPTY ) conference call to be released	 
 * \details On successful completion of this request , all calls for the MPTY call ( if there is one ) are released.	 
 * To release calls individually from the MPTY call , use the CI_CC_RELEASE_CALL_REQ request.	 
 */	 
 CI_CC_PRIM_RELEASE_MPTY_CNF , /**< \brief Confirms the request to release an active multiparty ( MPTY ) conference call */	 
 CI_CC_PRIM_START_DTMF_REQ = 70 , /**< \brief Requests to start sending a DTMF digit to the network during an active call	 
 * \details Valid DTMF digits are defined by the GSM Standard.	 
 * DTMF digits can be sent only on an active speech connection , where a traffic channel has been allocated.	 
 * A DTMF request cannot be sent while a previous DTMF request is still in progress. If this is attempted , the request fails with an error result.	 
 * For this request , the application layer must handle the timing of individual DTMF digits , and must stop the transmission by issuing a CI_CC_PRIM_STOP_DTMF_REQ request at the appropriate time.	 
 */	 
 CI_CC_PRIM_START_DTMF_CNF , /**< \brief Confirms the request to start sending a DTMF digit to the network during an active call	 
 * \details	 
 * This confirmation is received in any of the following situations:	 
 * - The DTMF digit was sent successfully.	 
 * - A DTMF start reject message was received from the network.	 
 * - SAC did not accept the DTMF request.	 
 * - There was a timeout on receiving a response from the network.	 
 * The application layer must handle the timing of individual DTMF digits , and must stop the transmission by issuing a CI_CC_PRIM_STOP_DTMF_REQ request at the appropriate time.	 
 * */	 
 CI_CC_PRIM_STOP_DTMF_REQ , /**< \brief Requests to stop sending a DTMF digit to the network during an active call	 
 * \details DTMF digits can only be sent on an active speech connection , where a traffic channel has been allocated.	 
 * A DTMF request cannot be sent while a previous DTMF request is still in progress. If this is attempted , the request fails with an error result.	 
 * Similarly , if this request is received when no DTMF tone is currently active , the request fails with an error result. */	 
 CI_CC_PRIM_STOP_DTMF_CNF , /**< \brief Confirms the request to stop sending a DTMF digit to the network during an active call	 
 * \details This confirmation is received in any of the following situations:	 
 * the DTMF digit was stopped successfully ;	 
 * a DTMF stop reject message was received from the network ;	 
 * SAC did not accept the DTMF request ;	 
 * there was a timeout on receiving a response from the network. */	 
	 
 CI_CC_PRIM_GET_DTMF_PACING_REQ , /**< \brief Requests the current DTMF pacing configuration values	 
 * \details The DTMF pacing configuration values are initially set to internal defaults.	 
 * These values can be changed by a CI_CC_SET_DTMF_CONFIG_REQ request.	 
 * The pacing configuration values are used by CI when sending strings of DTMF digits to the network. In this situation ,	 
 * CI performs a " handshake " with the network for each digit in turn , and uses the configured tone duration and inter-digit	 
 * intervals to pace the individual tones. */	 
 CI_CC_PRIM_GET_DTMF_PACING_CNF , /**< \brief Confirms the request and returns the current DTMF pacing configuration values	 
 * \details There should be no reason for an unsuccessful result.	 
 * On GSM , the network enforces the minimum inter-digit interval. SAC does not use the Interval field in the	 
 * CiCcDtmfPacing structure. */	 
 CI_CC_PRIM_SET_DTMF_PACING_REQ , /**< \brief Requests to set the DTMF pacing configuration values	 
 * \details If this request is not invoked , SAC uses default configuration values ( CICC_MIN_DTMF_DURATION	 
 * for duration and CICC_DTMF_DEFAULT_INTERVAL for interval ) .	 
 * The pacing configuration values are used by SAC when sending strings of DTMF digits to the network	 
 * ( see the CI_CC_PRIM_SEND_DTMF_STRING_REQ request ) . In this situation , SAC performs a handshake with the	 
 * network for each digit , and uses the configured tone duration and inter-digit intervals to pace the	 
 * individual tones.	 
 * SAC does not check for extremely large values in the supplied DTMF pacing configuration structure. However ,	 
 * if any of the pacing configuration values are set below the specified minimum values , which are specified in CICC_MIN_DTMF_DURATION	 
 * for duration and CICC_DTMF_DEFAULT_INTERVAL for interval , this request fails with an error result.	 
 * On GSM , the network enforces the minimum inter-digit interval. SAC does not use the interval field in the	 
 * CiCcDtmfPacing structure. */	 
 CI_CC_PRIM_SET_DTMF_PACING_CNF , /**< \brief Confirms the request to set the DTMF pacing configuration values	 
 * \details SAC returns an error result if any of the pacing configuration values are less then specified minimum values	 
 * in the request ( CICC_MIN_DTMF_DURATION for duration and CICC_DTMF_DEFAULT_INTERVAL for interval ) . */	 
 CI_CC_PRIM_SEND_DTMF_STRING_REQ , /**< \brief Requests a string of DTMF digits to be sent on an active call	 
 * \details Valid DTMF digits are defined by the GSM Standard.	 
 * DTMF digits can be sent only on an active speech connection , where a traffic channel has been allocated.	 
 * If this is not the case , this request fails with an error result.	 
 * As the GSM protocol provides only a single-digit DTMF control procedure , SAC sends the DTMF digits	 
 * individually , using Start DTMF and Stop DTMF requests to the network.	 
 * The DTMF pacing parameters ( tone duration and inter-digit interval ) can be specified by the	 
 * CI_CC_PRIM_SET_DTMF_PACING_REQ request. See CICC_MIN_DTMF_DURATION	 
 * and CICC_DTMF_DEFAULT_INTERVAL for the parameter defaults.	 
 * On GSM , the network enforces the minimum inter-digit interval. SAC does not use the interval field in the	 
 * CiCcDtmfPacing structure.*/	 
 CI_CC_PRIM_SEND_DTMF_STRING_CNF , /**< \brief Confirms the request to send a string of DTMF digits on an active call	 
 * \details This confirmation is received in any of the following situations:	 
 * the complete DTMF string was sent successfully ;	 
 * a DTMF Reject message ( Start or Stop ) was received from the network ;	 
 * SAC did not accept the DTMF request ;	 
 * there was a timeout on receiving a response from the network. */	 
 CI_CC_PRIM_CLIP_INFO_IND = 80 , /**< \brief Indicates CLIP information ( when enabled ) for an incoming call	 
 * \details CLIP indications are enabled or disabled by CI_SS_PRIM_SET_CLIP_OPTION_REQ.	 
 * This indication is enabled by default.	 
 * No explicit response is required. */	 
 CI_CC_PRIM_COLP_INFO_IND , /**< \brief Indicates CoLP information ( when enabled locally ) for an outgoing call	 
 * \details CoLP indications are enabled or disabled by the CI_SS_PRIM_SET_COLP_OPTION_REQ.	 
 * This indication is enabled by default.	 
 * No explicit response is required.*/	 
 CI_CC_PRIM_CCM_UPDATE_IND , /**< \brief Indicates periodic current call meter ( CCM ) unsolicited reports	 
 * \details CCM unsolicited reports are enabled or disabled by CI_SS_PRIM_SET_CCM_OPTION_REQ.	 
 * If enabled indications are reported periodically , not more than once every 10 seconds during a call.	 
 * This indication is enabled by default.	 
 * No explicit response is required.*/	 
 CI_CC_PRIM_GET_CCM_VALUE_REQ , /**< \brief Requests the current value of the current call meter ( CCM ) .	 
 * \details The CCM value is normally requested only during a call , which is why this request is in the CC service group , but	 
 * it can be requested at any time. Other quantities related to call charging ( ACM , ACMmax , and PUCT ) are accessible	 
 * through the SIM Manager interface. For more information , see the SIM Service Group primitives. */	 
 CI_CC_PRIM_GET_CCM_VALUE_CNF , /**< \brief Confirms the request and returns the current value of the current call meter ( CCM )	 
 * \details If the Result Code indicates failure , the CCM value is not useful , and should be ignored. */	 
 CI_CC_PRIM_AOC_WARNING_IND , /**< \brief Indicates an unsolicited advice of charge ( AoC ) warning	 
 * \details If the advice of charge service is provisioned , SAC can send a warning indication during a call when the accumulated charge meter ( ACM ) is within 30 seconds of the programmed maximum ( ACMmax ) value.	 
 * This indication can be enabled or disabled by the CI_SS_PRIM_SET_AOC_WARNING_ENABLE_REQ request.	 
 In addition , this indication can be sent if a new incoming or outgoing call is set up when the ACM is within 30 seconds of the programmed ACMmax value.	 
 This indication is enabled by default.	 
 No explicit response is required.	 
 */	 
 CI_CC_PRIM_SSI_NOTIFY_IND , /**< \brief Indicates supplementary service intermediate ( SSI ) notification	 
 * \details SSI notifications ( if enabled , see CI_SS_PRIM_SET_SS_NOTIFY_OPTIONS_REQ ) are triggered by receipt of an intermediate supplementary service notification after mobile originated call setup , but before any call setup results are received.	 
 * This notification is enabled by default.	 
 * No explicit response is required.*/	 
	 
 CI_CC_PRIM_SSU_NOTIFY_IND , /**< \brief Indicates supplementary service unsolicited ( SSU ) notification	 
 * \details SSU notifications ( if enabled , see CI_SS_PRIM_SET_SS_NOTIFY_OPTIONS_REQ ) are triggered by receipt of an unsolicited supplementary service notification at any of the following times:	 
 * during mobile terminated call setup ;	 
 * during a call ;	 
 * whenever a forward check supplementary service notification is received ( in call or out of call ) .	 
 * This notification is enabled by default.	 
 * No response is required.*/	 
 CI_CC_PRIM_LOCALCB_NOTIFY_IND , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_CC_PRIM_GET_ACM_VALUE_REQ , /**< \brief Requests the current value of the accumulated call meter ( ACM )	 
 * \details The ACM value holds accumulated CCM units for the current call ( if there is one ) and all previous calls since the	 
 * ACM was last reset. */	 
	 
 CI_CC_PRIM_GET_ACM_VALUE_CNF = 90 , /**< \brief Confirms the request and returns the current value of the accumulated call meter maximum value ( ACMmax )	 
 * \details If the Result code indicates failure , the ACMmax value is not useful , and should be ignored.*/	 
 CI_CC_PRIM_RESET_ACM_VALUE_REQ , /**< \brief Requests the accumulated call meter ( ACM ) to be reset to zero	 
 * \details The ACM value holds accumulated CCM units for the current call ( if there is one ) and all previous calls since the ACM was last reset.	 
 * This operation requires prior PIN2 verification.*/	 
 CI_CC_PRIM_RESET_ACM_VALUE_CNF , /**< \brief Confirms the request to reset the accumulated call meter ( ACM ) to zero	 
 * \details If the Result code indicates failure , the ACM value was not reset. */	 
 CI_CC_PRIM_GET_ACMMAX_VALUE_REQ , /**< \brief Requests the current value of the accumulated call meter maximum value ( ACMmax )	 
 * \details The ACMmax value holds the maximum value allowed for the ACM.	 
 * If the ACM approaches the ACMmax value , SAC can issue a warning indication ( if enabled ) .	 
 * For more information , see the CI_CC_PRIM_AOC_WARNING_IND indication.*/	 
 CI_CC_PRIM_GET_ACMMAX_VALUE_CNF , /**< \brief Confirms the request and returns the current value of the accumulated call meter maximum value ( ACMmax )	 
 * \details If the Result code indicates failure , the ACMmax value is not useful , and should be ignored.*/	 
 CI_CC_PRIM_SET_ACMMAX_VALUE_REQ , /**< \brief Requests the accumulated call meter maximum ( ACMmax ) to be set to the supplied value	 
 * \details The ACMmax value holds the maximum value allowed for the ACM.	 
 * If the ACM is close to the ACMmax value , SAC can issue a warning indication ( if enabled ) . For more information see the CI_CC_PRIM_AOC_WARNING_IND indication.	 
 * Setting ACMmax to zero disables it , and effectively removes the maximum ACM limit. In this case , there are no CI_CC_PRIM_AOC_WARNING_IND indications , whether they are enabled locally or not.	 
 * This operation requires prior PIN2 verification.*/	 
 CI_CC_PRIM_SET_ACMMAX_VALUE_CNF , /**< \brief Confirms the request to set the accumulated call meter maximum ( ACMmax ) value	 
 * \details If the Result code indicates failure , the ACMmax value was not changed.*/	 
 CI_CC_PRIM_GET_PUCT_INFO_REQ , /**< \brief Requests the current Price per Unit and Currency Table ( PUCT ) information	 
 * \details The PUCT information is used to enable the application to calculate the cost of a call , in a currency chosen by the subscriber.*/	 
 CI_CC_PRIM_GET_PUCT_INFO_CNF , /**< \brief Confirms the request and returns the current Price per Unit and Currency Table ( PUCT ) information	 
 * \details If the Result code indicates failure , the PUCT information is not useful , and should be ignored. */	 
 CI_CC_PRIM_SET_PUCT_INFO_REQ , /**< \brief Requests the current Price per Unit and Currency Table ( PUCT ) information to be updated	 
 * \details The PUCT information is used to enable the application to calculate the cost of a call , in a currency chosen by the subscriber.	 
 * This operation requires prior PIN2 validation.*/	 
 CI_CC_PRIM_SET_PUCT_INFO_CNF = 100 , /**< \brief Confirms the request to update the current Price per Unit and Currency Table ( PUCT ) information	 
 * \details If the Result code indicates failure , the PUCT information was not updated.*/	 
 CI_CC_PRIM_GET_BASIC_CALLMODES_REQ , /**< \brief Requests the basic call modes currently supported for outgoing calls	 
 * \details The basic call mode is used when placing an outgoing call request while the current call mode is set to single mode.	 
 * See CI_CC_PRIM_MAKE_CALL_REQ for more information.	 
 * See CI_CC_PRIM_SET_CALLMODE_REQ for default call mode information. */	 
	 
 CI_CC_PRIM_GET_BASIC_CALLMODES_CNF , /**< \brief Confirms the request and returns the basic call modes currently supported for outgoing calls	 
 * \details Use this request to return the supported basic call modes ( or types ) .	 
 * To place an outgoing call when the call mode is set to single mode , the basic call mode must be specified in the outgoing call request.	 
 * See CI_CC_PRIM_SET_CALLMODE_REQ for default call mode information.	 
 * There should be no reason for an unsuccessful result. */	 
 CI_CC_PRIM_GET_CALLOPTIONS_REQ , /**< \brief Requests to get the call options currently supported for outgoing calls	 
 * \details See CI_CC_PRIM_MAKE_CALL_REQ for more information.*/	 
 CI_CC_PRIM_GET_CALLOPTIONS_CNF , /**< \brief Confirms the request and returns the call options currently supported for outgoing calls	 
 * \details Returns the call options currently supported for outgoing calls.	 
 * There should be no reason for an unsuccessful result.*/	 
 CI_CC_PRIM_GET_DATACOMP_CAP_REQ , /**< \brief Requests to get the V.42 bis data compression configuration capability	 
 * \details Mandatory if V.42 bis is supported.*/	 
 CI_CC_PRIM_GET_DATACOMP_CAP_CNF , /**< \brief Confirms the request and returns the V.42 bis data compression configuration capability	 
 * \details Mandatory if V.42 bis is supported.*/	 
 CI_CC_PRIM_GET_DATACOMP_REQ , /**< \brief Requests to get the current V.42 bis data compression information	 
 * \details Mandatory if V.42 bis is supported.*/	 
 CI_CC_PRIM_GET_DATACOMP_CNF , /**< \brief Confirms the request and returns the current V.42 bis data compression information	 
 * \details Mandatory if V.42 bis is supported.*/	 
 CI_CC_PRIM_SET_DATACOMP_REQ , /**< \brief Requests to configure V.42 bis data compression	 
 * \details Mandatory if V.42 bis is supported.*/	 
 CI_CC_PRIM_SET_DATACOMP_CNF = 110 , /**< \brief Confirms the request to configures V.42 bis data compression	 
 * \details Mandatory if V.42 bis is supported.*/	 
 CI_CC_PRIM_GET_RLP_CAP_REQ , /**< \brief Requests to get RLP configuration capability for NT data calls	 
 * \details Mandatory if RLP is supported. */	 
 CI_CC_PRIM_GET_RLP_CAP_CNF , /**< \brief Confirms the request and returns the RLP configuration capability for NT data calls	 
 * \details Mandatory if RLP is supported. */	 
 CI_CC_PRIM_GET_RLP_CFG_REQ , /**< \brief Requests the current RLP configuration for a RLP version	 
 * \details Mandatory if RLP is supported. */	 
 CI_CC_PRIM_GET_RLP_CFG_CNF , /**< \brief Confirms the request and returns the current RLP configuration for the requested version	 
 * \details Mandatory if RLP is supported. */	 
 CI_CC_PRIM_SET_RLP_CFG_REQ , /**< \brief Requests to configure the RLP for NT data calls	 
 * \details Mandatory if RLP is supported. */	 
 CI_CC_PRIM_SET_RLP_CFG_CNF , /**< \brief Confirms the request to configure the RLP for NT data calls	 
 * \details Mandatory if RLP is supported. */	 
 CI_CC_PRIM_DATA_SERVICENEG_IND , /**< \brief Indicates the report of bearer service , during connect negotiation for data calls	 
 * \details No explicit response is required.	 
 * This notification can be enabled or disabled by the CI_CC_PRIM_ENABLE_DATA_SERVICENEG_REQ request. It is disabled by	 
 * default. */	 
 CI_CC_PRIM_ENABLE_DATA_SERVICENEG_IND_REQ , /**< \brief Requests that bearer service reporting during connect negotiation for data calls be enabled or disabled	 
 * \details */	 
 CI_CC_PRIM_ENABLE_DATA_SERVICENEG_IND_CNF , /**< \brief Confirms the request to enable / disable bearer service reporting during	 
 * connect negotiation for data calls	 
 * \details Mandatory if RLP is supported. */	 
 CI_CC_PRIM_SET_UDUB_REQ = 120 , /**< \brief Requests that user determined user busy ( UDUB ) for a waiting or incoming call be set	 
 * \details Use this request if the subscriber opts to refuse a waiting or incoming call by setting a user determined user busy ( UDUB ) condition.	 
 * This informs the network that the call may be redirected to another number ( if already set up ) .	 
 * The network may clear the call with a busy indication to the calling party.*/	 
 CI_CC_PRIM_SET_UDUB_CNF , /**< \brief Confirms the request to set UDUB for a waiting or incoming call	 
 * \details */	 
 CI_CC_PRIM_GET_SUPPORTED_CALLMAN_OPS_REQ , /**< \brief Requests a list of supported call manipulation operation codes for	 
 * supplementary services within a call	 
 * \details These operations are described in TS 22.030000 , Section 6.500000 .5.1 , and are implemented	 
 * by the " AT+CHLD " command in TS 27.007000 Section 7.130000 .*/	 
 CI_CC_PRIM_GET_SUPPORTED_CALLMAN_OPS_CNF , /**< \brief Confirms the request and returns a list of supported call manipulation operation codes for	 
 * supplementary services within a call	 
 * \details */	 
 CI_CC_PRIM_MANIPULATE_CALLS_REQ , /**< \brief Requests call manipulation for supplementary services within a call	 
 * \details This primitive performs the operations described in TS 22.030000 , Section 6.500000 .5.1 ,	 
 * and are implemented by the " AT+CHLD " command in TS 27.007000 Section 7.130000 .	 
 * The CallId parameter is used only for the CI_CC_MANOP_RLS_CALL and CI_CC_MANOP_HOLD_ALL_EXCEPT_ONE operations.*/	 
 CI_CC_PRIM_MANIPULATE_CALLS_CNF , /**< \brief Confirms the request to perform call manipulation for supplementary services within a call	 
 * \details */	 
 CI_CC_PRIM_LIST_CURRENT_CALLS_IND , /**< \brief Indicates the current call information	 
 * \details */	 
	 
 CI_CC_PRIM_CALL_DIAGNOSTIC_IND , /**< \brief Indicates the diagnostic octets of a specific call	 
 * \details Diagnostic information is sent by the protocol stack in one of the following	 
 * notifications: CcDisconnectInd , CcDisconnectedInd , CcDisconnectingInd , CcFailureInd.	 
 * SAC processes these signals and sends a corresponding CI indication primitive	 
 * ( CI_CC_PRIM_DISCONNECT_IND , CI_CC_PRIM_MO_CALL_FAILED_IND , CI_CC_PRIM_MT_CALL_FAILED_IND ,	 
 * CI_DAT_PRIM_NOK_IND ) but it does not include the diagnostic information.	 
 * SAC sends the CiCcCustPrimCallDiagnosticInd each time it receives any of these	 
 * notifications from the protocol stack.	 
 */	 
 CI_CC_PRIM_DTMF_EVENT_IND , /**< \brief Indicates a DTMF event	 
 * \details This notification is sent each time SAC receives a confirmation signal from the protocol	 
 * stack indicating that a start / stop DTMF request has been successfully completed.	 
 * In case of a single DTMF tone , the notification is sent along with the CiCcPrimStartDtmfCnf	 
 * and CiCcPrimStopDtmfCnf.	 
 * In case of a DTMF tone sequence , the notification is sent for each tone in the sequence	 
 * when that tone is started / stopped.	 
 * A DTMF aborted indication is sent when a Start or Stop DTMF request is rejected by SAC or the	 
 * network for various reasons ( see GSM TS 4.080000 section 8.400000 and section 5.500000 .7.2. ) ; also if no	 
 * answer is received from the network. */	 
 CI_CC_PRIM_CLEAR_BLACK_LIST_REQ , /**< \brief Requests to clear the call blacklist	 
 * \details To clear the entire blacklist is not yet supported by the protocol stack.	 
 * A blacklist is created by the protocol stack with the numbers that	 
 * are used to initiate MO calls and are marked as auto-dial numbers.	 
 * In this case , SAC would have to create its own blacklist and save all	 
 * the auto-dial numbers that are reported by the protocol stack as blacklisted.	 
 * For clearing the entire list , it sends a separate ' clear blacklist '	 
 * request for each dial number in the blacklist.	 
 * NOTE: To support the blacklist functionality CI must add the capability of	 
 * specifying if a number is auto-dial , when an MO call is requested.*/	 
 CI_CC_PRIM_CLEAR_BLACK_LIST_CNF = 130 , /**< \brief Confirms the request and returns the completion status of the request	 
 * \details */	 
 CI_CC_PRIM_SET_CTM_STATUS_REQ , /**< \brief Requests to set the status of the CTM state when a CTM jack is connected and CTM is enabled in MENU	 
 * \details */	 
 CI_CC_PRIM_SET_CTM_STATUS_CNF , /**< \brief Confirms the request to set the status of the CTM state when a CTM jack is connected and CTM is enabled in MENU	 
 * \details */	 
 CI_CC_PRIM_CTM_NEG_REPORT_IND , /**< \brief Indicates the CTM negotiation status report	 
 * \details */	 
 /*Michal Bukai - CDIP support */	 
 CI_CC_PRIM_CDIP_INFO_IND , /**< \brief Indicates a report for CDIP information for an incoming call	 
 * \details CDIP indications are enabled or disabled by the CI_SS_SET_CDIP_OPTION_REQ request.	 
 * This indication is enabled by default.	 
 * No explicit response is required.*/	 
 CI_CC_PRIM_SYNC_AUDIO_REQ , /**< \brief Requests to sync audio path.	 
 * \details */	 
 CI_CC_PRIM_SYNC_AUDIO_CNF , /**< \brief Confirms a request to sync audio path.	 
 * \details */	 
 /*Michal Bukai - ALS support - START */	 
 CI_CC_PRIM_GET_LINE_ID_REQ , /**< \brief Requests to read the selected line ID for outgoing calls.	 
 * \details ALS provides the MS with the capability of associating two alternate lines with one IMSI.	 
 * A user will be able to make and receive calls on either line as desired and will be billed separately for calls on each line.	 
 * Each line will be associated with a separate directory number ( MSISDN ) and separate subscription profile.	 
 * For outgoing calls , the handset shall enable the user to select the desired line.*/	 
 CI_CC_PRIM_GET_LINE_ID_CNF , /**< \brief Confirms the request and returns the selected line ID.	 
 * \details ALS provides the MS with the capability of associating two alternate lines with one IMSI.	 
 * A user will be able to make and receive calls on either line as desired and will be billed separately for calls on each line.	 
 * Each line will be associated with a separate directory number ( MSISDN ) and separate subscription profile.	 
 * For outgoing calls , the handset shall enable the user to select the desired line.*/	 
 CI_CC_PRIM_SET_LINE_ID_REQ , /**< \brief Requests to set the line ID for outgoing calls.	 
 * \details ALS provides the MS with the capability of associating two alternate lines with one IMSI.	 
 * A user will be able to make and receive calls on either line as desired and will be billed separately for calls on each line.	 
 * Each line will be associated with a separate directory number ( MSISDN ) and separate subscription profile.	 
 * For outgoing calls , the handset shall enable the user to select the desired line.*/	 
 CI_CC_PRIM_SET_LINE_ID_CNF = 140 , /**< \brief Confirms the request and sets user requested line ID.	 
 * \details ALS provides the MS with the capability of associating two alternate lines with one IMSI.	 
 * A user will be able to make and receive calls on either line as desired and will be billed separately for calls on each line.	 
 * Each line will be associated with a separate directory number ( MSISDN ) and separate subscription profile.	 
 * For outgoing calls , the handset shall enable the user to select the desired line.*/	 
 /*Michal Bukai - ALS support - END */	 
 CI_CC_PRIM_READY_STATE_IND ,	 
 /*add by cherryli@2014.02.11 for CQ56277 begin.*/	 
 CI_CC_PRIM_SRVCC_STATUS_REQ ,	 
 CI_CC_PRIM_SRVCC_STATUS_CNF ,	 
 /*add by cherryli@2014.02.11 for CQ56277 end.*/	 
	 
 CI_CC_PRIM_CALL_END_INFO_IND , /*Added by cherryli@09.02.2014 for CQ69642.*/	 
 /*merged by lxliu for CQ00098090 on 7152015 begin*/	 
 /* CECALL */	 
 CI_CC_PRIM_SET_CECALL_REQ , /**< \brief Request to trigger an eCall to the network.	 
 * \details This CI is used when there is necessity to start eCall.	 
 * eCall can be started manually in emergency case , automatically in the case car system decide that this is an emergency case ;	 
 * also manually for test purpose.*/	 
 CI_CC_PRIM_SET_CECALL_CNF , /**< \brief Confirms the request to trigger an eCall to the network.*/	 
 CI_CC_PRIM_GET_CECALL_REQ , /**< \brief Get command request the type of eCall that is currently in progress , if any.*/	 
 CI_CC_PRIM_GET_CECALL_CNF , /**< \brief This command confirms the request and return type of eCall in progress or no eCall.*/	 
 CI_CC_PRIM_GET_CECALL_CAP_REQ , /**< \brief Request to read the supported values and ranges of eCall type.*/	 
 CI_CC_PRIM_GET_CECALL_CAP_CNF = 150 , /**< \brief Confirms a request and return supported values of eCall type*/	 
	 
 /*CI_CC_PRIM_CALL_PROGRESS_IND , This primitive is removed by lxliu for CQ00100555*/	 
 /**< \brief This CI contains the progress indicator information element and is sent whenever a PROGRESS message is received	 
 * or another call control message ( like SETUP , CALL PROCEEDING , ALERTING , CONNECT ) includes the optional progress indicator	 
 * information element */	 
	 
 /*merged by lxliu for CQ00098090 on 7152015 end*/	 
	 
 /*Added by lxliu for CQ00100555 on 6082015 */	 
 CI_CC_PRIM_AUDIO_ECALL_TO_AP_INFO_IND , /*brief This CI Indicates that the information which came from audio about ecall was sent to CI*/	 
	 
 /*Merged by cherryli@04.26.2016 CQ105208 begin.*/	 
 CI_CC_PRIM_ECALL_CFG_REQ , /**< \for eCall: defines what is the time interval in which the elapsed time since the eCall was operated ( T3242 / T3243 ) is written to the NVM*/	 
 CI_CC_PRIM_ECALL_CFG_CNF , /**< \for eCall: confirms the request to set the timer interval for writing to the NVM */	 
 CI_CC_PRIM_GET_ECALL_CFG_REQ , /**< \for eCall: request to get the configured time interval for writing the elapsed time into the NVM , and if eCall operated - the elapsed time */	 
 CI_CC_PRIM_GET_ECALL_CFG_CNF , /**< \for eCall: response to the request to get the configured time interval and the elapsed time*/	 
 CI_CC_PRIM_ECALL_ONLY_REQ , /**< \for eCallOnly: Forces the UE to act as an eCall-only mode */	 
 CI_CC_PRIM_ECALL_ONLY_CNF , /**< \for eCallOnly: confirms the request to act as an eCall-only mode */	 
 CI_CC_PRIM_GET_ECALL_ONLY_REQ , /**< \for eCallOnly: request to get the status of eCall-only mode */	 
 CI_CC_PRIM_GET_ECALL_ONLY_CNF , /**< \for eCallOnly: confirms the request to get the status of eCall-only mode */	 
 CI_CC_PRIM_SET_EMLPP_SUBSCRIPTIONS_INFO_REQ = 160 , /**< \brief Requests to set EMLPP subscriptions information */	 
 CI_CC_PRIM_SET_EMLPP_SUBSCRIPTIONS_INFO_CNF , /**< \brief Confirms request to set EMLPP subscriptions information */	 
 CI_CC_PRIM_GET_EMLPP_SUBSCRIPTIONS_INFO_REQ , /**< \brief Requests to get EMLPP subscriptions information */	 
 CI_CC_PRIM_GET_EMLPP_SUBSCRIPTIONS_INFO_CNF , /**< \brief Confirms request to get EMLPP subscriptions information */	 
 /*Merged by cherryli@04.26.2016 CQ105208 end.*/	 
 CI_CC_PRIM_LIST_CALL_INFO_IND , /*Added by cherryli@ 12.010000 .2017 CQ108522 .*/	 
	 
 /* ADD NEW COMMON PRIMITIVES HERE , BEFORE ' CI_CC_PRIM_LAST_COMMON_PRIM ' */	 
 /* END OF COMMON PRIMITIVES LIST */	 
 CI_CC_PRIM_LAST_COMMON_PRIM	 
	 
 /* Customer specific extension primitives must be added starting from	 
 * CI_CC_PRIM_FIRST_CUST_PRIM = CI_CC_PRIM_LAST_COMMON_PRIM as the first identifier.	 
 * The actual primitive names and IDs are defined in the associated	 
 * ' ci_cc_cust_xxx.h ' file.	 
 */	 
	 
 /* DO NOT ADD ANY MORE PRIMITIVES HERE */	 
	 
 } _CiCcPrim;

//ICAT EXPORTED ENUM 
 typedef enum CIRC_CC {	 
 CIRC_CC_SUCCESS = 0 , /**< Request completed successfully */	 
 CIRC_CC_FAIL , /**< General failure ( catch-all ) */	 
 CIRC_CC_INCOMPLETE_INFO , /**< Incomplete information for request */	 
 CIRC_CC_BAD_DIALSTRING , /**< Invalid characters in dial string */	 
 CIRC_CC_INVALID_ADDRESS , /**< Invalid address ( phone number ) */	 
 CIRC_CC_INVALID_CALLID , /**< Invalid call identifier */	 
 CIRC_CC_INVALID_MPTYID , /**< Invalid MPTY identifier */	 
 CIRC_CC_NO_SERVICE , /**< No network service */	 
 CIRC_CC_FDN_ONLY , /**< Only fixed dialing numbers allowed */	 
 CIRC_CC_EMERGENCY_ONLY , /**< Only emergency calls allowed */	 
 CIRC_CC_CALL_BARRED , /**< Calls are barred */	 
 CIRC_CC_NO_MORE_CALLS , /**< No more calls allowed */	 
 CIRC_CC_NO_MORE_TIME , /**< No more airtime left */	 
 CIRC_CC_NOT_PROVISIONED , /**< Service not provisioned */	 
 CIRC_CC_CANNOT_SWITCH , /**< Call mode cannot be switched */	 
 CIRC_CC_SWITCH_FAILED , /**< Failed to switch call mode */	 
 CIRC_CC_REJECTED , /**< Request rejected by network */	 
 CIRC_CC_TIMEOUT , /**< Request timed out */	 
 CIRC_CC_SIM_ACCESS_DENIED , /**< SIM access related error ( CHV needed? ) */	 
 CIRC_CC_INVALID_PARAMETER , /**< Generic error - the requested service primitive has invalid parameters */	 
 CIRC_CC_INVALID_REQ , /**< Generic error - the requested service primitive can not be handled at current state */	 
 CIRC_CC_SIM_NOT_READY , /**< Generic error - the requested service primitive fails because SIM is not ready */	 
 CIRC_CC_ACCESS_DENIED , /**< Generic error - the requested service primitive fails because access is denied */	 
 CIRC_CC_ST_MODIFIED , /**< Call Modified By STK */	 
 /* << Define additional specific CC result codes here >> */	 
 /*added by cherryli@10.24.2018 CQ00112632 begin.*/	 
 CIRC_CC_RETRY , /**< Previous call is in disconnecting , retry later */	 
 /*added by cherryli@10.24.2018 CQ00112632 end.*/	 
	 
 /* This one must always be last in the list! */	 
 CIRC_CC_NUM_RESCODES /**< Number of result codes defined */	 
 } _CiCcResultCode;

typedef UINT16 CiCcResultCode ;
typedef UINT16 CiCcCallId ;
typedef UINT16 CiCcMptyId ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_CMODE {	 
 CICC_CMODE_SINGLE = 0 , /**< Single mode ( see below ) */	 
 CICC_CMODE_ALT_VOICE_FAX , /**< Alternating voice / fax ( Teleservice 61 ) */	 
 CICC_CMODE_ALT_VOICE_DATA , /**< Alternating voice / data ( Bearer Svc 61 ) */	 
 CICC_CMODE_VOICE_THEN_DATA , /**< Voice followed by data ( Bearer Svc 81 ) */	 
 /* This one must always be last in the list! */	 
 CICC_NUM_CMODES /* Number of call modes defined */	 
 } _CiCcCallMode;

typedef UINT8 CiCcCallMode ;
typedef UINT8 CiCcVioceMode ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_BASIC_CMODE {	 
 CICC_BASIC_CMODE_VOICE = 0 , /**< Basic call mode: voice */	 
 CICC_BASIC_CMODE_FAX , /**< Basic call mode: fax */	 
 CICC_BASIC_CMODE_DATA , /**< Basic call mode: data */	 
	 
 /* This one must always be last in the list! */	 
 CICC_NUM_BASIC_CMODES /* Number of basic call modes defined */	 
 } _CiCcBasicCMode;

typedef UINT8 CiCcBasicCMode ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_CURRENT_CMODE {	 
 CICC_CURRENT_CMODE_VOICE = 0 , /**< Voice only */	 
 CICC_CURRENT_CMODE_DATA , /**< Data only */	 
 CICC_CURRENT_CMODE_FAX , /**< Fax only */	 
 CICC_CURRENT_CMODE_VOICE_FB_DATA_IS_VOICE , /**< Voice followed by data , voice mode */	 
 CICC_CURRENT_CMODE_ALT_VOICE_DATA_IS_VOICE , /**< Alternating voice / data , voice mode */	 
 CICC_CURRENT_CMODE_ALT_VOICE_FAX_IS_VOICE , /**< Alternating voice / fax , voice mode */	 
 CICC_CURRENT_CMODE_VOICE_FB_DATA_IS_DATA , /**< Voice followed by data , data mode */	 
 CICC_CURRENT_CMODE_ALT_VOICE_DATA_IS_DATA , /**< Alternating voice / data , data mode */	 
 CICC_CURRENT_CMODE_ALT_VOICE_FAX_IS_FAX , /**< Alternating voice / fax , fax mode */	 
 CICC_CURRENT_CMODE_UNKNOWN , /**< Unknown call mode */	 
	 
	 
	 
	 
 /* This one must always be last in the list! */	 
 CICC_NUM_CURRENT_CMODES /**< Number of current call modes defined */	 
 } _CiCcCurrentCMode;

typedef UINT8 CiCcCurrentCMode ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_CURRENT_CSTATE {	 
 CICC_CURRENT_CSTATE_ACTIVE = 0 , /**< Call is active */	 
 CICC_CURRENT_CSTATE_HELD , /**< Call is held */	 
 CICC_CURRENT_CSTATE_DIALING , /**< Dialing ( MO call ) */	 
 CICC_CURRENT_CSTATE_ALERTING , /**< Alerting ( MO call ) */	 
 CICC_CURRENT_CSTATE_INCOMING , /**< Incoming MT call */	 
 CICC_CURRENT_CSTATE_WAITING , /**< MT call waiting */	 
 CICC_CURRENT_CSTATE_OFFERING , /**< MT call offering ( call setup ) */	 
 /*Added by cherryli@ 12.010000 .2017 CQ108522 begin.*/	 
 CICC_CURRENT_CSTATE_DISCONNECTING , /**< call in disconnect procedure.*/	 
 CICC_CURRENT_CSTATE_END , /**< call is disconnected.*/	 
 /*Added by cherryli@ 12.010000 .2017 CQ108522 end.*/	 
	 
 /* This one must always be last in the list! */	 
 CICC_NUM_CURRENT_CSTATES /* Number of current call states defined */	 
 } _CiCcCurrentCState;

typedef UINT8 CiCcCurrentCState ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_CALL_DIRECTION {	 
 CICC_MO_CALL = 0 , /**< Mobile originated call */	 
 CICC_MT_CALL /**< Mobile terminated call */	 
 } _CiCcCallDirection;

typedef UINT8 CiCcCallDirection ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_SRVCC_HO_STATE {	 
 CICC_SRVCC_HO_START ,	 
 CICC_SRVCC_HO_SUCCESS ,	 
 CICC_SRVCC_HO_CANCEL ,	 
 CICC_SRVCC_HO_FAIL ,	 
	 
 CICC_SRVCC_HO_STATE	 
	 
 } _CiCcSrvccHoState;

typedef UINT8 CiCcSrvccHoState ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_CALLTYPE {	 
	 
 /* Single Modes */	 
 CICC_CALLTYPE_ASYNC = 0 , /**< Asynchronous transparent data */	 
 CICC_CALLTYPE_SYNC , /**< Synchronous transparent data */	 
 CICC_CALLTYPE_REL_ASYNC , /**< Asynchronous non-transparent data */	 
 CICC_CALLTYPE_REL_SYNC , /**< Synchronous non-transparent data */	 
 CICC_CALLTYPE_FAX , /**< Facsimile */	 
 CICC_CALLTYPE_VOICE , /**< Voice */	 
	 
 /* Voice mode followed by data mode ( bearer service 81 ) */	 
 CICC_CALLTYPE_VOICE_THEN_ASYNC , /**< VOICE followed by ASYNC */	 
 CICC_CALLTYPE_VOICE_THEN_SYNC , /**< VOICE followed by SYNC */	 
 CICC_CALLTYPE_VOICE_THEN_REL_ASYNC , /**< VOICE followed by REL_ASYNC */	 
 CICC_CALLTYPE_VOICE_THEN_REL_SYNC , /**< VOICE followed by REL_SYNC */	 
	 
 /* Alternating Voice / Data Mode , Voice Mode first ( Bearer Service 61 ) */	 
 CICC_CALLTYPE_ALT_VOICE_ASYNC , /**< Alternating VOICE / ASYNC , VOICE first */	 
 CICC_CALLTYPE_ALT_VOICE_SYNC , /**< Alternating VOICE / SYNC , VOICE first */	 
 CICC_CALLTYPE_ALT_VOICE_REL_ASYNC , /**< Alternating VOICE / REL_ASYNC , VOICE first */	 
 CICC_CALLTYPE_ALT_VOICE_REL_SYNC , /**< Alternating VOICE / REL_SYNC , VOICE first */	 
	 
 /* Alternating Voice / Data Mode , Data Mode first ( Bearer Service 61 ) */	 
 CICC_CALLTYPE_ALT_ASYNC_VOICE , /**< Alternating ASYNC / VOICE , ASYNC first */	 
 CICC_CALLTYPE_ALT_SYNC_VOICE , /**< Alternating SYNC / VOICE , SYNC first */	 
 CICC_CALLTYPE_ALT_REL_ASYNC_VOICE , /**< Alternating REL_ASYNC / VOICE , REL_ASYNC first */	 
 CICC_CALLTYPE_ALT_REL_SYNC_VOICE , /**< Alternating REL_SYNC / VOICE , REL_SYNC first */	 
	 
 /* Alternating Voice / Facsimile Modes ( Teleservice 61 ) */	 
 CICC_CALLTYPE_ALT_VOICE_FAX , /**< Alternating VOICE / FAX , VOICE first */	 
 CICC_CALLTYPE_ALT_FAX_VOICE , /**< Alternating VOICE / FAX , FAX first */	 
	 
 /* This one must always be last in the list! */	 
 CICC_NUM_CALLTYPES /**< Number of call types defined */	 
 } _CiCcCallType;

typedef UINT8 CiCcCallType ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_BSTYPE_NAME {	 
	 
 /* UDI or 3.100000 kHz Modem definitions */	 
 CICC_BSTYPE_NAME_DATA_ASYNC_UDI = 0 , /**< Data circuit asynchronous ( UDI , 3.100000 kHz ) */	 
 CICC_BSTYPE_NAME_DATA_SYNC_UDI , /**< Data circuit synchronous ( UDI , 3.100000 kHz ) */	 
 CICC_BSTYPE_NAME_PAD_ASYNC_UDI , /**< PAD access asynchronous ( UDI ) */	 
 CICC_BSTYPE_NAME_PACKET_SYNC_UDI , /**< Packet access synchronous ( UDI ) */	 
	 
 /* RDI definitions */	 
 CICC_BSTYPE_NAME_DATA_ASYNC_RDI = 0 , /**< Data circuit asynchronous ( RDI ) */	 
 CICC_BSTYPE_NAME_DATA_SYNC_RDI , /**< Data circuit synchronous ( RDI ) */	 
 CICC_BSTYPE_NAME_PAD_ASYNC_RDI , /**< PAD access asynchronous ( RDI ) */	 
 CICC_BSTYPE_NAME_PACKET_SYNC_RDI , /**< Packet access synchronous ( RDI ) */	 
	 
 /* This one must always be last in the list! */	 
 CICC_NUM_BSTYPE_NAMES /**< Number of bearer service names defined */	 
 } _CiCcBsTypeName;

typedef UINT8 CiCcBsTypeName ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_BSTYPE_CE {	 
 CICC_BSTYPE_CE_TRANSPARENT_ONLY = 0 , /**< Transparent required */	 
 CICC_BSTYPE_CE_NONTRANSPARENT_ONLY , /**< Non-transparent required */	 
 CICC_BSTYPE_CE_PREFER_TRANSPARENT , /**< Either , transparent preferred */	 
 CICC_BSTYPE_CE_PREFER_NONTRANSPARENT , /**< Either , non-transparent preferred */	 
	 
 /* This one must always be last in the list! */	 
 CICC_NUM_BSTYPE_CE /**< Number of CE indicators defined */	 
 } _CiCcBsTypeCe;

typedef UINT8 CiCcBsTypeCe ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcDataBsTypeInfo_struct {	 
 CiBsTypeSpeed Speed ; /**< Data speed indicator \sa CCI API Ref Manual */	 
 CiCcBsTypeName Name ; /**< Bearer service name indicator \sa CiCcBsTypeName */	 
 CiCcBsTypeCe Ce ; /**< Connection element \sa CiCcBsTypeCe */	 
 } CiCcDataBsTypeInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcSuppDataBsTypes_struct {	 
 CiNumericRange bsTypeSpeedsRange ; /**< Supported data speeds \sa CCI API Ref Manual */	 
 CiNumericRange bsTypeNamesRange ; /**< Supported bearer service names \sa CCI API Ref Manual */	 
 CiNumericRange bsTypeCeRange ; /**< Supported connection elements \sa CCI API Ref Manual */	 
 } CiCcSuppDataBsTypes;

//ICAT EXPORTED ENUM 
 typedef enum CICC_PROTOCOL_DISC {	 
	 
 CICC_PROTOCOL_DISC_USP = 0 , /* User specified protocol */	 
 CICC_PROTOCOL_DISC_OSIHLP , /* OSI higher layer protocol */	 
 CICC_PROTOCOL_DISC_X244 , /* X.244 */	 
 CICC_PROTOCOL_DISC_RMCF3 , /* Reserved for system mangement convergence function */	 
 CICC_PROTOCOL_DISC_IA5c4 , /* IA5 characters */	 
	 
 CICC_NUM_PROTOCOL_DISC /* Number of protocols discriminator defined */	 
 } _CiCcProtocolDisc;

typedef UINT8 CiCcProtocolDisc ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_ACT_MODE {	 
 CICC_ACTMODE_NO_SRV =0 ,	 
 CICC_ACTMODE_CDMA ,	 
 CICC_ACTMODE_GSM ,	 
 CICC_ACTMODE_UMTS ,	 
 CICC_ACTMODE_LTE ,	 
 CICC_ACTMODE_TDS ,	 
 /* This one must always be last in the list! */	 
 CICC_NUM_ACTMODE /* Number of call act modes defined */	 
 } _CiCcActMode;

typedef UINT8 CiCcActMode ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_ALERTING_TYPE {	 
 CICC_AlERTING_TYPE_LOCAL ,	 
 CICC_AlERTING_TYPE_REMOTE ,	 
 CICC_NUM_AlERTING_TYPE	 
 } _CiccAlertingType;

typedef UINT8 CiccAlertingType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCCOptUUSInfo_struct {	 
 CiBoolean UUSInfoValid ; /**< TRUE Indicates UUS information is valid \sa CCI API Ref Manual */	 
 CiCcProtocolDisc protocolDisc ; /**< Protocol discriminator as defined in 3 GPP TS 24.008000 section 10.500000 .4.25. This field is valid if UUSInfoValid == TRUE \sa CiCcProtocolDisc*/	 
 CiString userUserInfo ; /**< User-user information element as defined in 3 GPP TS 24.008000 appendix O2. This field is valid if UUSInfoValid == TRUE \sa CCI API Ref Manual */	 
 } CiCcOptUUSInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcCallInfo_struct {	 
 CiCcCallId CallId ; /**< Unique call identifier \sa CiCcCallId */	 
 CiBoolean IsEmergency ; /**< If TRUE indicates emergency call \sa CCI API Ref Manual */	 
 CiBoolean IsMPTY ; /**< If TRUE indicates this call is part of a multiparty call \sa CCI API Ref Manual */	 
 CiCcCallDirection Direction ; /**< Call direction ( MT or MO ) indicator \sa CiCcCallDirection */	 
 CiCcCurrentCState State ; /**< Current call state \sa CiCcCurrentCState */	 
 CiCcCurrentCMode Mode ; /**< Current call mode \sa CiCcCurrentCMode */	 
 CiCallerInfo callerInfo ; /**< Caller information \sa CCI API Ref Manual */	 
 CiCcDataBsTypeInfo dataSvcInfo ; /**< Service information ( for data calls ) \sa CiCcDataBsTypeInfo_struct */	 
 CiBoolean IsAutoDial ; /**< If TRUE indicates an auto dial call \sa CCI API Ref Manual */	 
	 
 CiCcOptUUSInfo optUUSInfo ; /**< Optional user to user information \sa CiCCOptUUSInfo */	 
	 
 UINT8 LineID ; /**< Line ID ( ALS ) - 1 or 2 */	 
 // CQ105208	 
 // CiCcCliValidity CliValidity ; / **< CLI validity indicator* /	 
 CiCcEmlppCallPriority emlppCallPriority ; /** calling-subscriber eMLPP call priority. coded according to 3 GPP TS 24.008000 section 10.500000 .1.11 */	 
	 
 } CiCcCallInfo;

//ICAT EXPORTED ENUM 
 typedef enum CICC_CALLOPTIONS {	 
 CICC_CALLOPTIONS_NONE = 0x00 , /**< CLIR as provisioned ; no CUG information */	 
 CICC_CALLOPTIONS_CLIR_ALLOW = 0x01 , /**< Allow CLI presentation on this call */	 
 CICC_CALLOPTIONS_CLIR_RESTRICT = 0x02 , /**< Restrict CLI presentation on this call */	 
 CICC_CALLOPTIONS_CUG_ENABLE = 0x04 /**< Enable CUG information on this call */	 
 } _CiCcCallOptions;

typedef UINT8 CiCcCallOptions ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_EMRGENCYCAT {	 
 CICC_EMERGENCYCAT_POLICE = 0 ,	 
 CICC_EMERGENCYCAT_AMBULANCE ,	 
 CICC_EMERGENCYCAT_FIRE_BRIGADE ,	 
 CICC_EMERGENCYCAT_MARINE_GUARD ,	 
 CICC_EMERGENCYCAT_MOUNTAIN_RESCUE ,	 
 CICC_NUM_EMERGENCYCAT	 
 } _CiCcEmergencyCat;

typedef UINT8 CiCcEmergencyCat ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcMakeCallInfo_struct {	 
 CiCcBasicCMode BasicCMode ; /**< Basic call mode ( if applicable ) \sa CiCcBasicCMode */	 
 CiCcCallOptions Options ; /**< Call options bitmap \sa CiCcCallOptions */	 
 CHAR dialString [ 40 ] ;	 
 CiBoolean IsAutoDial ; /**< Is this an auto dial call? \sa CCI API Ref Manual */	 
 CiBoolean IsCtmCall ; /**< Is this call is CTM TTY MO call? \sa CCI API Ref Manual */	 
 CiBoolean IsEmergency ; /**< Indicates if the call is an emergency call \sa CCI API Ref Manual */	 
 CiBitRange ServiceCat ; /**< Bit mask indicating the required emergency call service category. coded according to 3 GPP TS 24.008000 [ 10 ] [ 15 ] section 10.500000 .4.33. This filed is valid if IsEmergency is TRUE \sa CCI API Ref Manual */	 
 // CQ105208	 
 CiCcEmlppCallPriority emlppCallPriority ; /** User chosen eMLPP call priority. Coded according to 3 GPP TS 24.008000 section 10.500000 .1.11. Might be above the maximum priority level for which the service subscriber has a subscription in the network */	 
 } CiCcMakeCallInfo;

//ICAT EXPORTED ENUM 
 typedef enum CICC_CAUSE {	 
 CICC_CAUSE_UNKNOWN = 0 , /**< Unknown cause ( includes " None " ) */	 
 CICC_CAUSE_UNASSIGNED_NUMBER , /**< Unassigned ( unallocated ) number */	 
 CICC_CAUSE_NO_ROUTE_TO_DEST , /**< No route to destination */	 
 CICC_CAUSE_CHAN_UNACCEPTABLE , /**< Channel unacceptable */	 
 CICC_CAUSE_OPERATOR_BARRING , /**< Operator determined barring */	 
 CICC_CAUSE_NORMAL_CLEARING , /**< Normal call clearing */	 
 CICC_CAUSE_USER_BUSY , /**< User busy */	 
 CICC_CAUSE_NO_USER_RESPONSE , /**< No user responding */	 
 CICC_CAUSE_ALERT_NO_ANSWER , /**< User alerting , no answer */	 
 CICC_CAUSE_CALL_REJECTED , /**< Call rejected */	 
 CICC_CAUSE_NUMBER_CHANGED = 10 , /**< Number changed */	 
 CICC_CAUSE_PREEMPTION , /**< Pre-emption */	 
 CICC_CAUSE_NONSELECTED_USER_CLEAR , /**< Non selected user clearing */	 
 CICC_CAUSE_DEST_OUT_OF_ORDER , /**< Destination out of order */	 
 CICC_CAUSE_INVALID_NUMFORMAT , /**< Invalid number format ( incomplete ) */	 
 CICC_CAUSE_FACILITY_REJECT , /**< Facility rejected */	 
 CICC_CAUSE_STATUSENQ_RESPONSE , /**< Response to STATUS ENQUIRY */	 
 CICC_CAUSE_NORMAL_UNSPECIFIED , /**< Normal , unspecified */	 
 CICC_CAUSE_NO_CCT_AVAILABLE , /**< No circuit / channel available */	 
 CICC_CAUSE_NETWORK_OUT_OF_ORDER , /**< Network out of order */	 
 CICC_CAUSE_TEMP_FAILURE = 20 , /**< Temporary failure */	 
 /*21-30*/	 
 CICC_CAUSE_CONGESTION , /**< Switching equipment congestion */	 
 CICC_CAUSE_ACCESSINFO_DISCARDED , /**< Access information discarded */	 
 CICC_CAUSE_CIRCUIT_UNAVAILABLE , /**< Requested circuit / channel unavailable */	 
 CICC_CAUSE_RESOURCES_UNAVAILABLE , /**< Resources unavailable , unspecified */	 
 CICC_CAUSE_QOS_UNAVAIL , /**< Quality of service ( QoS ) unavailable */	 
 CICC_CAUSE_FACILITY_NOTSUBSCRIBED , /**< Requested facility not subscribed */	 
 CICC_CAUSE_MT_CALLBARRING_IN_CUG , /**< Incoming ( MT ) calls barred within CUG */	 
 CICC_CAUSE_BEARERCAP_NOTAUTHORIZED , /**< Bearer capability not authorized */	 
 CICC_CAUSE_BEARERCAP_UNAVAILABLE , /**< Bearer capability not available */	 
 CICC_CAUSE_SVC_UNAVAILABLE = 30 , /**< Service or option not available */	 
 /*31-40*/	 
 CICC_CAUSE_BEARERSVC_NOT_IMPLEMENTED , /**< Bearer service not implemented */	 
 CICC_CAUSE_ACMMAX_REACHED , /**< ACM equal to , or greater than , ACMmax */	 
 CICC_CAUSE_FACILITY_NOT_IMPLEMENTED , /**< Requested facility not implemented */	 
 CICC_CAUSE_BEARERCAP_RDI_ONLY , /**< Only RDI bearer capability is available */	 
 CICC_CAUSE_SVC_NOT_IMPLEMENTED , /**< Service or option not implemented */	 
 CICC_CAUSE_INVALID_TRANSACTID , /**< Invalid transaction ID value */	 
 CICC_CAUSE_NOT_CUG_MEMBER , /**< User not member of CUG */	 
 CICC_CAUSE_DEST_INCOMPATIBLE , /**< Incompatible destination */	 
 CICC_CAUSE_INCORRECT_MESSAGE , /**< Semantically incorrect message */	 
 CICC_CAUSE_TRANSIT_NETWORK_INVALID = 40 , /**< Invalid transit network selection */	 
 /*41-50*/	 
 CICC_CAUSE_NO_SUCH_MSGTYPE , /**< Message type non-existent or not implemented */	 
 CICC_CAUSE_MSGTYPE_WRONG_STATE , /**< Message type incompatible with current protocol state */	 
 CICC_CAUSE_NO_SUCH_IE , /**< Information element non-existent or not implemented */	 
 CICC_CAUSE_CONDITIONAL_IE_ERROR , /**< Conditional IE error */	 
 CICC_CAUSE_MSG_WRONG_STATE , /**< Message incompatible with current protocol state */	 
 CICC_CAUSE_RECOVERY_AFTER_TIMEOUT , /**< Recovery after timer expiry */	 
 CICC_CAUSE_PROTOCOL_ERROR , /**< Protocol error , unspecified */	 
 CICC_CAUSE_INTERWORKING , /**< Interworking , unspecified */	 
	 
 /* Error codes originated locally */	 
 CICC_CAUSE_ABNORMAL , /**< Abnormal release */	 
 CICC_CAUSE_ERROR_REESTABLISHMENT_BARRED = 50 , /**< Reestablishment barred */	 
 /*51-60*/	 
 CICC_CAUSE_CELL_SELECTION_IN_PROGRESS , /**< Cell seection in progress */	 
 CICC_CAUSE_LOWER_LAYER_FAILURE , /**< Lower layer failure */	 
 CICC_CAUSE_RACH_FAIL , /**< Rach fail */	 
	 
 CICC_CAUSE_FDN_BLOCKED , /**< FDN Mismatch */	 
	 
 CICC_CAUSE_ACCESS_CLASS_BARRED , /**< Cell barred */	 
	 
 CICC_CAUSE_MAND_IE_ERROR , /**< Invalid mandatory information */	 
	 
 CICC_CAUSE_EMERGENCY_ONLY , /**< Only Emergency calls allowed */	 
 CICC_CAUSE_NO_CS_SERVICE ,	 
 CICC_CAUSE_DMM_DEDICATE , /**< other sim in dedicate mode */	 
 CICC_CAUSE_UNALLOCATED_TMSI = 60 , /**< unallocated TMSI */	 
 /*61-70*/	 
 CICC_CAUSE_ILLEGAL_MS , /**< Illegal MS */	 
 CICC_CAUSE_ILLEGAL_ME , /**< Illegal ME */	 
 CICC_CAUSE_NETWORK_FAILURE , /**< Network failure */	 
 CICC_CAUSE_SYNCH_FAILURE , /**< Synch failure */	 
 CICC_CAUSE_CALL_CANNOT_BE_IDENTIFIED , /**< Call cannot be identified */	 
 CICC_CAUSE_AUTH_FAILURE , /**< Authentication failure */	 
	 
 // 67	 
	 
 /*Added by cherryli@09.02.2014 for CQ69642 begin.*/	 
 CICC_RRC_REL_CAUSE_NORMAL = 68 ,	 
 CICC_RRC_REL_CAUSE_UNSPEC ,	 
 CICC_RRC_REL_CAUSE_PRE_EMPTIVE = 70 ,	 
	 
 /*71-80*/	 
 CICC_RRC_REL_CAUSE_CONGESTION ,	 
 CICC_RRC_REL_CAUSE_RE_ESTABLISH_REJECT ,	 
 CICC_RRC_REL_CAUSE_DIRECTED_SIGNALLING_REESTABLISHMENT ,	 
 CICC_RRC_REL_CAUSE_USER_INACTIVITY ,	 
 /*Added by cherryli@09.02.2014 for CQ69642 end.*/	 
	 
 /*Added by cherryli@06.28.2020 CQ00121837 begin.*/	 
 CICC_CAUSE_IN_REGISTER = 75 ,	 
 /*Added by cherryli@06.28.2020 CQ00121837 end.*/	 
	 
 /* This one must always be last in the list! */	 
 CICC_NUM_CAUSES /**< Number of cause codes defined */	 
 } _CiCcCause;

typedef UINT8 CiCcCause ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcExtCallType_struct {	 
 CiCcCallType CallType ; /**< Call type indicator \sa CiCcCallType */	 
 CiSubaddrInfo subaddress ; /**< Optional subaddress information \sa CCI API Ref Manual */	 
 } CiCcExtCallType;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcCdAddressInfo_struct {	 
 CiBoolean Present ; /* Is Call Deflection info present? */	 
 CiAddressInfo number ;	 
 CiSubaddrInfo subaddress ;	 
	 
 } CiCcCdAddressInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcDtmfPacing_struct {	 
 UINT16 Duration ; /**< DTMF tone duration ( ms ) */	 
 UINT16 Interval ; /**< Inter-digit interval ( ms ) */	 
 } CiCcDtmfPacing;

//ICAT EXPORTED ENUM 
 typedef enum CICC_CLI_VALIDITY {	 
 CLI_VALIDITY_VALID = 0 , /**< CLI information is valid */	 
 CLI_VALIDITY_WITHHELD , /**< CLI information withheld by caller */	 
 CLI_VALIDITY_UNAVAILABLE , /**< CLI information is unavailable */	 
 CLI_VALIDITY_NOT_PRESENT /**< CLI information is not present */	 
 } _CiCcCliValidity;

typedef UINT8 CiCcCliValidity ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_CauseOfNoCli {	 
	 
 CLI_CAUSE_OF_NO_CLI_UNAVAILABLE = 0 ,	 
 CLI_CAUSE_OF_NO_CLI_REJECT_BY_USER = 1 ,	 
 CLI_CAUSE_OF_NO_CLI_INTERACTION_WITH_OTHER_SERVICE = 2 ,	 
 CLI_CAUSE_OF_NO_CLI_COIN_LINE_PAYPHONE = 3	 
	 
 } _CiCauseOfNoCli;

typedef UINT8 CiCauseOfNoCli ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcClipInfo_struct {	 
 CiCcCallId CallId ; /**< call identifier \sa CiCcCallId */	 
 CiCcCliValidity CliValidity ; /**< CLI validity indicator \sa CiCcCliValidity */	 
 CiCallerInfo callerInfo ; /**< Calling party ( caller ) information \sa CCI API Ref Manual */	 
	 
	 
	 
 } CiCcClipInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcCdipInfo_struct {	 
 CiCcCallId CallId ; /**< call identifier \sa CiCcCallId */	 
 CiCcCliValidity CliValidity ; /**< CLI validity indicator \sa CiCcCliValidity */	 
 CiCallerInfo callerInfo ; /**< Called line Information \sa CCI API Ref Manual */	 
 } CiCcCdipInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcColpInfo_struct {	 
 CiCcCallId CallId ; /**< call identifier \sa CiCcCallId */	 
 CiCcCliValidity CliValidity ; /**< CLI validity indicator \sa CiCcCliValidity */	 
 CiCallerInfo callerInfo ; /**< Connected party information \sa CCI API Ref Manual */	 
 } CiCcColpInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcCwInfo_struct {	 
 CiCcCliValidity CliValidity ; /**< CLI validity indicator \sa CiCcCliValidity */	 
 CiCallerInfo callerInfo ; /**< Calling party ( caller ) information \sa CCI API Ref Manual */	 
 // CQ105208	 
 CiCcEmlppCallPriority emlppCallPriority ; /** calling-subscriber eMLPP call priority. coded according to 3 GPP TS 24.008000 section 10.500000 .1.11 */	 
 CiBoolean emlppAutoAnswer ; /**< Indicates whether it was decided by CP that the new incoming call should be auto-answered and on-going call shall be pre-empted */	 
 } CiCcCwInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPuctInfo_struct {	 
 CHAR curr [ 3 ] ; /**< Currency string */	 
 UINT16 eppu ; /**< Extended price per unit */	 
 CiBoolean negExp ; /**< TRUE if exponent is negative \sa CCI API Ref Manual */	 
 UINT8 exp ; /**< Modulus of exponent */	 
 } CiCcPuctInfo;

//ICAT EXPORTED ENUM 
 typedef enum CICCDATACOMPDIR_TAG {	 
 CI_CC_DATACOMP_DIR_NONE = 0 , /**< Negotiated , no compression ( V.42 bis P0=0 ) */	 
 CI_CC_DATACOMP_DIR_TX , /**< Transmit only */	 
 CI_CC_DATACOMP_DIR_RX , /**< Receive only */	 
 CI_CC_DATACOMP_DIR_BOTH , /**< Both directions , accept any direction ( V.42 bis P0=11 ) */	 
	 
 /* This one must always be last in the list! */	 
 CI_CC_DATACOMPS_NUM_DIRS	 
 } _CiCcDataCompDir;

typedef UINT8 CiCcDataCompDir ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcDataCompInfo_struct {	 
 CiCcDataCompDir dir ; /**< Data compression direction , default: CI_CC_DATACOMP_BOTH \sa CiCcDataCompDir */	 
 CiBoolean zNegRequired ; /**< Is compression negotiation required? Default: FALSE \sa CCI API Ref Manual */	 
 UINT16 maxDict ; /**< Maximum number of dictionary entries to be negotiated , [ 512 -65535 ] */	 
 UINT8 maxStrLen ; /**< Maximum string length to be negotiated ( V.42 bis P2 ) , [ 6 -250 ] , default: 6 */	 
 } CiCcDataCompInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcDataCompCap_struct {	 
 CiBitRange bitsDir ; /**< Supported direction values \sa CCI API Ref Manual */	 
 CiBitRange bitsNegComp ; /**< Supported negotiation values \sa CCI API Ref Manual */	 
 CiNumericRange maxDictRange ; /**< Range of supported maximum number of dictionary entries \sa CCI API Ref Manual */	 
 CiNumericRange maxStrLenRange ; /**< Range of supported maximum string length to be negotiated \sa CCI API Ref Manual */	 
 } CiCcDataCompCap;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcRlpCfg_struct {	 
 UINT8 winIWS ; /**< IWF-to-MS window size */	 
 UINT8 winMWS ; /**< MS-to-IWF window size */	 
 UINT8 ackTimer ; /**< Acknowledgement timer ( T1 ) , units of 10 ms */	 
 UINT8 reTxAttempts ; /**< Retransmission attempts ( N2 ) */	 
 UINT8 ver ; /**< RLP version number , [ 0 -2 ] , default: 0 , recommend: 2 */	 
 UINT8 reSeqPeriod ; /**< Resequencing period ( T4 ) , units of 10 ms */	 
 UINT8 initialT1 ; /**< Acknowledgement timer ( T1 ) , units of 10 ms */	 
 UINT8 initialN2 ; /**< Retransmission attempts ( N2 ) , units of 10 ms */	 
 } CiCcRlpCfg;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcRlpCap_struct {	 
 CiNumericRange winIWSRange ; /**< Range of supported IWF-to-MS window size \sa CCI API Ref Manual. */	 
 CiNumericRange winMWSRange ; /**< Range of supported MS-to-IWF window size \sa CCI API Ref Manual. */	 
 CiNumericRange ackTimerRange ; /**< Range of supported acknowledgement timer \sa CCI API Ref Manual. */	 
 CiNumericRange reTxAttemptsRange ; /**< Range of supported retransmission attempts \sa CCI API Ref Manual. */	 
 CiBitRange bitsVer ; /**< Supported RLP version \sa CCI API Ref Manual. */	 
 CiNumericRange reSeqPeriodRange ; /**< Range of supported resequencing period \sa CCI API Ref Manual. */	 
 } CiCcRlpCap;

//ICAT EXPORTED ENUM 
 typedef enum CICCCALLMANOP_TAG {	 
	 
 CI_CC_MANOP_RLS_HELD_OR_UDUB = 0 , /**< " AT+CHLD=0 " - Release all held calls or set user determined user busy ( UDUB ) for a waiting call */	 
 CI_CC_MANOP_RLS_ACT_ACCEPT_OTHER , /**< " AT+CHLD=1 " - Release all active calls ( if any exist ) and accept the other ( held or waiting ) call*/	 
 CI_CC_MANOP_RLS_CALL , /**< " AT+CHLD=1X " - Releases a specific active call X*/	 
 CI_CC_MANOP_HOLD_ACT_ACCEPT_OTHER , /**< " AT+CHLD=2 " Places all active calls ( if any exist ) on hold and accepts the other ( held or waiting ) call.*/	 
 CI_CC_MANOP_HOLD_ALL_EXCEPT_ONE , /**< " AT+CHLD=2X " - Places all active calls on hold except call X with which communication shall be supported*/	 
 CI_CC_MANOP_ADD_HELD_TO_MPTY , /**< " AT+CHLD=3 " - Add a held call to the conversation ( multiparty ) */	 
 CI_CC_MANOP_ECT , /**< " AT+CHLD=4 " - Connects the two calls and disconnects the subscriber from both calls ( ECT ) */	 
 CI_CC_MANOP_CALL_REDIRECT , /**< " AT+CTFR " ( " 4 *<number><SEND> " ) - Redirect an incoming or a waiting call to the specified number followed by SEND directory number */	 
 CI_CC_MANOP_CCBS , /**< " AT+CHLD=5 " - Activates the completion of calls when subscriber is busy */	 
 CI_CC_MANOP_NUM_OPS	 
	 
 } _CiCcCallManOp;

typedef UINT8 CiCcCallManOp ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_RELEASE_WHICHCALLS 
 {	 
 CICC_WHICHCALLS_ALL_ACTIVE = 0 ,	 
 CICC_WHICHCALLS_ALL_HELD ,	 
 CICC_WHICHCALLS_ALL_CALLS	 
	 
 } _CiCcReleaseWhichCalls;

typedef UINT8 CiCcReleaseWhichCalls ;
typedef CiEmptyPrim CiCcPrimGetNumberTypeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetNumberTypeCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiAddressType numType ; /**< Type of number ( address type ) \sa CCI API Ref Manual */	 
 } CiCcPrimGetNumberTypeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetNumberTypeReq_struct {	 
 CiAddressType numType ; /**< Type of number ( address type ) \sa CCI API Ref Manual */	 
 } CiCcPrimSetNumberTypeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetNumberTypeCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSetNumberTypeCnf;

typedef CiEmptyPrim CiCcPrimGetSupportedCallModesReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetSupportedCallModesCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 UINT8 NumModes ; /**< Number of supported call modes */	 
 CiCcCallMode Modes [ CICC_NUM_CMODES ] ; /**< Supported call modes \sa CiCcCallMode */	 
 } CiCcPrimGetSupportedCallModesCnf;

typedef CiEmptyPrim CiCcPrimGetCallModeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetCallModeCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcCallMode Mode ; /**< Current call mode \sa CiCcCallMode */	 
 } CiCcPrimGetCallModeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetCallModeReq_struct {	 
 CiCcCallMode Mode ; /**< Selected call mode \sa CiCcCallMode */	 
 } CiCcPrimSetCallModeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetCallModeCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSetCallModeCnf;

typedef CiEmptyPrim CiCcPrimGetSupportedDataBsTypesReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetSupportedDataBsTypesCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcSuppDataBsTypes types ; /**< Supported data bearer service type parameter settings \sa CiCcSuppDataBsTypes_struct */	 
 } CiCcPrimGetSupportedDataBsTypesCnf;

typedef CiEmptyPrim CiCcPrimGetDataBsTypeReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetDataBsTypeCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcDataBsTypeInfo info ; /**< Current data bearer service type information \sa CiCcDataBsTypeInfo_struct */	 
 } CiCcPrimGetDataBsTypeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetDataBsTypeReq_struct {	 
 CiCcDataBsTypeInfo info ;	 
 } CiCcPrimSetDataBsTypeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetDataBsTypeCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSetDataBsTypeCnf;

typedef CiEmptyPrim CiCcPrimGetAutoAnswerActiveReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetAutoAnswerActiveCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiBoolean Active ;	 
 } CiCcPrimGetAutoAnswerActiveCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetAutoAnswerActiveReq_struct {	 
 CiBoolean Active ;	 
 } CiCcPrimSetAutoAnswerActiveReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetAutoAnswerActiveCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSetAutoAnswerActiveCnf;

typedef CiEmptyPrim CiCcPrimListCurrentCallsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimListCurrentCallsCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 UINT8 NumCalls ; /**< Number of current calls */	 
 CiCcCallInfo callInfo [ 7 ] ; /**< Call information list \sa CiCcCallInfo_struct */	 
 } CiCcPrimListCurrentCallsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetCallInfoReq_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 } CiCcPrimGetCallInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetCallInfoCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcCallInfo info ; /**< Current call information \sa CiCcCallInfo_struct */	 
 } CiCcPrimGetCallInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimMakeCallReq_struct {	 
 CiCcMakeCallInfo info ; /**< Outgoing ( make ) call information \sa CiCcMakeCallInfo_struct*/	 
 } CiCcPrimMakeCallReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimMakeCallCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcCallId CallId ; /**< Unique call identifier \sa CiCcCallId */	 
 } CiCcPrimMakeCallCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimCallProceedingInd_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 CiBoolean InBandTones ; /**< Indicates if in-band tones are available from network \sa CCI API Ref Manual */	 
 // CQ105208	 
 CiCcEmlppCallPriority emlppCallPriorityGranted ; /** The eMLPP call priority granted by the network. coded according to 3 GPP TS 24.008000 section 10.500000 .1.11 */	 
 } CiCcPrimCallProceedingInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimMoCallFailedInd_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 CiCcCause Cause ; /**< Cause code \sa CiCcCause */	 
 CiBoolean InBandTones ; /**< Indicates if in-band tones are available from network \sa CCI API Ref Manual */	 
 /* SCR #1255830 */	 
 } CiCcPrimMoCallFailedInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimAlertingInd_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 CiBoolean InBandTones ; /**< Indicates if in-band tones are available from network \sa CCI API Ref Manual */	 
 } CiCcPrimAlertingInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimConnectInd_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 } CiCcPrimConnectInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimDisconnectInd_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 CiCcCause Cause ; /**< Disconnect cause code \sa CiCcCause */	 
 } CiCcPrimDisconnectInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimIncomingCallInd_struct {	 
 CiCcCallId CallId ; /**< Incoming call identifier \sa CiCcCallId */	 
 CiCcExtCallType callType ; /**< Extended call type information \sa CiCcExtCallType_struct */	 
 // CQ105208	 
 CiCcEmlppCallPriority emlppCallPriority ; /** calling-subscriber eMLPP call priority. coded according to 3 GPP TS 24.008000 section 10.500000 .1.11 */	 
 CiBoolean emlppAutoAnswer ; /**< Indicates whether it was decided by CP that the new incoming call should be auto-answered and on-going call shall be pre-empted */	 
 } CiCcPrimIncomingCallInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimCallWaitingInd_struct {	 
 CiCcCallId CallId ; /**< Waiting call identifier \sa CiCcCallId */	 
 CiCcCwInfo info ; /**< Call waiting information for incoming call \sa CiCcCwInfo_struct */	 
 } CiCcPrimCallWaitingInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimHeldCallInd_struct {	 
 CiCcCallId CallId ; /**< Held call identifier \sa CiCcCallId */	 
 } CiCcPrimHeldCallInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimAnswerCallReq_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 } CiCcPrimAnswerCallReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimAnswerCallCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 } CiCcPrimAnswerCallCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimRefuseCallReq_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 UINT16 Cause ; /**< Cause Code. */	 
 } CiCcPrimRefuseCallReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimRefuseCallCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimRefuseCallCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimMtCallFailedInd_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 CiCcCause Cause ; /**< Cause of call failure \sa CiCcCause */	 
 /* SCR #1255830 */	 
 CiBoolean InBandTones ; /**< Indicates if in-band tones are available from network \sa CCI API Ref Manual */	 
 } CiCcPrimMtCallFailedInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimHoldCallReq_struct {	 
 CiCcCallId CallId ; /**< Call identifier for the active call \sa CiCcCallId */	 
 } CiCcPrimHoldCallReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimHoldCallCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcCause Cause ; /**< Not in use */	 
 } CiCcPrimHoldCallCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimRetrieveCallReq_struct {	 
 CiCcCallId CallId ; /**< Call identifier for the held call \sa CiCcCallId */	 
 } CiCcPrimRetrieveCallReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimRetrieveCallCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcCause Cause ; /**< Not in use */	 
 } CiCcPrimRetrieveCallCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSwitchActiveHeldReq_struct {	 
 CiCcCallId Active ; /**< Call identifier for the active call \sa CiCcCallId */	 
 CiCcCallId Held ; /**< Call identifier for the held call \sa CiCcCallId*/	 
 } CiCcPrimSwitchActiveHeldReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSwitchActiveHeldCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcCause Cause ; /**< Not in use */	 
 } CiCcPrimSwitchActiveHeldCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimExplicitCallTransferReq_struct {	 
 CiCcCallId ActiveCall ; /**< Call identifier for the active call \sa CiCcCallId */	 
 CiCcCallId HeldCall ; /**< Call identifier for the held call \sa CiCcCallId*/	 
 } CiCcPrimExplicitCallTransferReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimExplicitCallTransferCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimExplicitCallTransferCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimReleaseCallReq_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 } CiCcPrimReleaseCallReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimReleaseCallCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimReleaseCallCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimReleaseAllCallsReq_struct {	 
 UINT8 WhichCalls ; /**< Not in use */	 
 } CiCcPrimReleaseAllCallsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimReleaseAllCallsCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimReleaseAllCallsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSwitchCallModeReq_struct {	 
 CiCcCallId CallId ;	 
 } CiCcPrimSwitchCallModeReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSwitchCallModeCnf_struct {	 
 CiCcResultCode Result ;	 
 } CiCcPrimSwitchCallModeCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimEstablishMptyReq_struct {	 
 CiCcCallId ActiveCall ; /**< Call identifier for the active call \sa CiCcCallId */	 
 CiCcCallId HeldCall ; /**< Call identifier for the held call \sa CiCcCallId */	 
 } CiCcPrimEstablishMptyReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimEstablishMptyCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcMptyId MptyId ; /**< MPTY identifier \sa CiCcMptyId */	 
 } CiCcPrimEstablishMptyCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimAddToMptyReq_struct {	 
 CiCcMptyId MptyId ; /**< MPTY identifier for the conference \sa CiCcMptyId */	 
 CiCcCallId CallId ; /**< Call identifier for the new call \sa CiCcCallId */	 
 } CiCcPrimAddToMptyReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimAddToMptyCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimAddToMptyCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimHoldMptyReq_struct {	 
 CiCcMptyId MptyId ; /**< MPTY Identifier \sa CiCcMptyId */	 
 } CiCcPrimHoldMptyReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimHoldMptyCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimHoldMptyCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimRetrieveMptyReq_struct {	 
 CiCcMptyId MptyId ; /**< MPTY Identifier \sa CiCcMptyId */	 
 } CiCcPrimRetrieveMptyReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimRetrieveMptyCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimRetrieveMptyCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSplitFromMptyReq_struct {	 
 CiCcMptyId MptyId ; /**< MPTY identifier for the conference \sa CiCcMptyId */	 
 CiCcCallId CallId ; /**< Call identifier for the call to be split out \sa CiCcCallId */	 
 } CiCcPrimSplitFromMptyReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSplitFromMptyCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSplitFromMptyCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimShuttleMptyReq_struct {	 
 CiCcMptyId MptyId ; /**< MPTY identifier for the conference \sa CiCcMptyId */	 
 CiCcCallId CallId ; /**< Call identifier for the single call \sa CiCcCallId */	 
 } CiCcPrimShuttleMptyReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimShuttleMptyCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimShuttleMptyCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimReleaseMptyReq_struct {	 
 CiCcMptyId MptyId ; /**< MPTY identifier \sa CiCcMptyId */	 
 } CiCcPrimReleaseMptyReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimReleaseMptyCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimReleaseMptyCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimStartDtmfReq_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 UINT8 Digit ; /**< DTMF digit */	 
 } CiCcPrimStartDtmfReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimStartDtmfCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimStartDtmfCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimStopDtmfReq_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 } CiCcPrimStopDtmfReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimStopDtmfCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimStopDtmfCnf;

typedef CiEmptyPrim CiCcPrimGetDtmfPacingReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetDtmfPacingCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcDtmfPacing Pacing ; /**< DTMF pacing configuration \sa CiCcDtmfPacing_struct */	 
 } CiCcPrimGetDtmfPacingCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetDtmfPacingReq_struct {	 
 CiCcDtmfPacing Pacing ; /**< DTMF pacing configuration \sa CiCcDtmfPacing_struct */	 
 } CiCcPrimSetDtmfPacingReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetDtmfPacingCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSetDtmfPacingCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSendDtmfStringReq_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId. */	 
 UINT8 digits [ 32 ] ; /**< DTMF digits */	 
 } CiCcPrimSendDtmfStringReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSendDtmfStringCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSendDtmfStringCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimClipInfoInd_struct {	 
 CiCcClipInfo info ; /**< CLIP information for incoming call \sa CiCcClipInfo_struct */	 
 } CiCcPrimClipInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimCdipInfoInd_struct {	 
 CiCcCdipInfo info ; /**< CDIP information for incoming call \sa CiCcCdipInfo_struct */	 
 } CiCcPrimCdipInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimColpInfoInd_struct {	 
 CiCcColpInfo info ; /**< CoLP information for incoming call \sa CiCcColpInfo_struct */	 
 } CiCcPrimColpInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimCcmUpdateInd_struct {	 
 UINT32 Ccm ; /**< Current CCM reading in Home units. Unsigned 24 -bit integer. */	 
 UINT32 Duration ; /**< Current call duration in seconds. Unsigned 24 -bit integer. */	 
 } CiCcPrimCcmUpdateInd;

typedef CiEmptyPrim CiCcPrimGetCcmValueReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetCcmValueCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 UINT32 Ccm ; /**< Current CCM value in Home units. Unsigned 24 -bit integer. */	 
 UINT32 Duration ; /**< Current call duration in seconds. Unsigned 24 -bit integer. */	 
 } CiCcPrimGetCcmValueCnf;

typedef CiEmptyPrim CiCcPrimAocWarningInd ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSsiNotifyInd_struct {	 
 CiSsiNotifyInfo info ; /**< Supplementary service intermediate ( SSI ) notification information \sa CI SS Spec */	 
 } CiCcPrimSsiNotifyInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSsuNotifyInd_struct {	 
 CiSsuNotifyInfo info ; /**< Supplementary service unsolicited ( SSU ) notification information \sa CI SS Spec */	 
 } CiCcPrimSsuNotifyInd;

typedef CiEmptyPrim CiCcPrimGetAcmValueReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetAcmValueCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 UINT32 Acm ; /**< Current ACM value. Unsigned 24 -bit integer. */	 
 } CiCcPrimGetAcmValueCnf;

typedef CiEmptyPrim CiCcPrimResetAcmValueReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimResetAcmValueCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimResetAcmValueCnf;

typedef CiEmptyPrim CiCcPrimGetAcmMaxValueReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetAcmMaxValueCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 UINT32 AcmMax ; /**< Current ACMmax value. Unsigned 24 -bit integer */	 
 } CiCcPrimGetAcmMaxValueCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetAcmMaxValueReq_struct {	 
 UINT32 AcmMax ; /**< New ACMmax value. Unsigned 24 -bit integer. */	 
 } CiCcPrimSetAcmMaxValueReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetAcmMaxValueCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
	 
 } CiCcPrimSetAcmMaxValueCnf;

typedef CiEmptyPrim CiCcPrimGetPuctInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetPuctInfoCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcPuctInfo info ; /**< Current PUCT information \sa CiCcPuctInfo_struct */	 
 } CiCcPrimGetPuctInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetPuctInfoReq_struct {	 
 CiCcPuctInfo info ; /**< New PUCT information \sa CiCcPuctInfo_struct */	 
 } CiCcPrimSetPuctInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetPuctInfoCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSetPuctInfoCnf;

typedef CiEmptyPrim CiCcPrimGetBasicCallModesReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetBasicCallModesCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 UINT8 NumModes ; /**< Number of supported basic call modes */	 
 CiCcBasicCMode Modes [ CICC_NUM_BASIC_CMODES ] ; /**< Supported basic call modes \sa CiCcBasicCMode */	 
 } CiCcPrimGetBasicCallModesCnf;

typedef CiEmptyPrim CiCcPrimGetCallOptionsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetCallOptionsCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcCallOptions Options ; /**< Supported call options bitmap \sa CiCcCallOptions */	 
 } CiCcPrimGetCallOptionsCnf;

typedef CiEmptyPrim CiCcPrimGetDataCompCapReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetDataCompCapCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcDataCompCap cap ; /**< Data compression configuration capability \sa CiCcDataCompCap_struct */	 
 } CiCcPrimGetDataCompCapCnf;

typedef CiEmptyPrim CiCcPrimGetDataCompReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetDataCompCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcDataCompInfo info ; /**< Data compression information \sa CiCcDataCompInfo_struct */	 
 } CiCcPrimGetDataCompCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetDataCompReq_struct {	 
 CiCcDataCompInfo info ; /**< Data compression information \sa CiCcDataCompInfo_struct */	 
 } CiCcPrimSetDataCompReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetDataCompCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSetDataCompCnf;

typedef CiEmptyPrim CiCcPrimGetRlpCapReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetRlpCapCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcRlpCap cap ; /**< Data compression configuration capability \sa CiCcRlpCap_struct */	 
 } CiCcPrimGetRlpCapCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetRlpCfgReq_struct {	 
 UINT8 ver ; /**< RLP version. */	 
 } CiCcPrimGetRlpCfgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetRlpCfgCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcRlpCfg cfg ; /**< RLP configuration \sa CiCcRlpCfg_struct */	 
 } CiCcPrimGetRlpCfgCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetRlpCfgReq_struct {	 
 CiCcRlpCfg cfg ; /**< RLP configuration \sa CiCcRlpCfg_struct */	 
 } CiCcPrimSetRlpCfgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetRlpCfgCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSetRlpCfgCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimDataServiceNegInd_struct {	 
 CiBoolean isAsync ; /**< Sync / async indication \sa CCI API Ref Manual */	 
 CiBoolean isTransparent ; /**< Transparent / non-transparent indication \sa CCI API Ref Manual */	 
 } CiCcPrimDataServiceNegInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimEnableDataServiceNegIndReq_struct {	 
 CiBoolean enable ; /**< TRUE: enable reporting ; FALSE: disable reporting , default \sa CCI API Ref Manual */	 
 } CiCcPrimEnableDataServiceNegIndReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimEnableDataServiceNegIndCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimEnableDataServiceNegIndCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetUDUBReq_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 } CiCcPrimSetUDUBReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetUDUBCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSetUDUBCnf;

typedef CiEmptyPrim CiCcPrimGetSupportedCallManOpsReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetSupportedCallManOpsCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 UINT8 NumOps ; /**< Number of operation codes [ 0 ..CI_CC_MANOP_NUM_OPS - 1 ] */	 
 CiCcCallManOp OpCodes [ CI_CC_MANOP_NUM_OPS ] ; /**< Array of supported operation codes \sa CiCcCallManOp */	 
 } CiCcPrimGetSupportedCallManOpsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimManipulateCallsReq_struct {	 
 CiCcCallManOp OpCode ; /**< Call manipulation operation code \sa CiCcCallManOp */	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 } CiCcPrimManipulateCallsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimManipulateCallsCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimManipulateCallsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimListCurrentCallsInd_struct {	 
 UINT8 NumCalls ; /**< Number of current calls [ 0 ..CICC_MAX_CURRENT_CALLS ] */	 
 CiCcCallInfo callInfo [ 7 ] ; /**< Call information list \sa CiCcCallInfo_struct */	 
 } CiCcPrimListCurrentCallsInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSrvccStatusReq_struct {	 
 UINT8 NumCalls ; /**< Number of current calls [ 0 ..CICC_MAX_CURRENT_CALLS ] */	 
 CiCcCallInfo callInfo [ 7 ] ; /**< Call information list \sa CiCcCallInfo_struct */	 
 } CiCcPrimSrvccStatusReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSrvccStatusCnf_struct {	 
 CiCcCallId CallId ;	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSrvccStatusCnf;

//ICAT EXPORTED ENUM 
 typedef enum CICC_TONESTATUS {	 
 CICC_TONE_STARTED , /**< DTMF tone started */	 
 CICC_TONE_STOPPED , /**< DTMF tone stopped normally */	 
 CICC_TONE_ABORTED /**< DTMF tone aborted due to abnormal condition */	 
 } _CiCcToneStatus;

typedef UINT8 CiCcToneStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimDtmfEventInd_struct {	 
	 
 CiCcCallId CallId ; /**< Identifier of the call for which a DTMF operation was required \sa CiCcCallId */	 
 UINT8 ToneDigit ; /**< Indicates the DTMF tone digit ; valid = " 123456789 *#ABCD " */	 
 CiBoolean SingleTone ; /**< Indicates a single DTMF tone or a tone sent as part of a DTMF string \sa CCI API Ref Manual */	 
 CiCcToneStatus ToneStatus ; /**< Indicates the DTMF tone status ( started , aborted , or stopped ) \sa CiCcToneStatus*/	 
	 
 } CiCcPrimDtmfEventInd;

//ICAT EXPORTED STRUCT 
 typedef struct _CiCcDiagnosticInfo_struct {	 
	 
 UINT16 Length ; /**< Number of bytes in diagnostic information */	 
 UINT8 Data [ 28 ] ; /**< Diagnostic information */	 
	 
 } CiCcDiagnosticInfo;

//ICAT EXPORTED ENUM 
 typedef enum CiCcCodingStandardTag 
 {	 
 CICC_CODING_CCITT_Q931 = 0 , /**< Coding as specified in ITU-T Rec. Q.931 */	 
 CICC_CODING_OTHER_INTERNATL = 1 , /**< Reserved for other international standards */	 
 CICC_CODING_NATIONAL = 2 , /**< National standard */	 
 CICC_CODING_GSM_NETWORK = 3 /**< Standard defined for the GSM PLMNS */	 
 } _CiCcCodingStandard;

typedef UINT8 CiCcCodingStandard ;
//ICAT EXPORTED ENUM 
 typedef enum CiCcLocationTag 
 {	 
 CICC_LOC_USER = 0 , /**< User */	 
 CICC_LOC_PRIV_LOCAL = 1 , /**< Private network serving the local user */	 
 CICC_LOC_PUB_LOCAL = 2 , /**< Public network serving the local user */	 
 CICC_LOC_TRANSIT = 3 , /**< Transit network */	 
 CICC_LOC_PUB_REMOTE = 4 , /**< Public network serving the remote user */	 
 CICC_LOC_PRIV_REMOTE = 5 , /**< Private network serving the remote user */	 
 CICC_LOC_INTERNATIONAL = 7 , /**< International network */	 
 CICC_LOC_BEYOND_IWF = 10 /**< Network beyond interworking point */	 
 } _CiCcLocation;

typedef UINT8 CiCcLocation ;
//ICAT EXPORTED ENUM 
 typedef enum CiCcRecommendationTag 
 {	 
 CICC_REC_Q931 = 0 , /**< Recommendation Q.931: " ISDN user-network interface layer 3 specification for basic control " */	 
 CICC_REC_GSM = 1 , /**< Recommendation GSM */	 
 CICC_REC_X21 = 3 , /**< Recommendation X.21: " Interface between data terminal equipment ( DTE ) and data circuit-terminating equipment ( DCE ) for synchronous operation on public data networks " */	 
 CICC_REC_X25 = 4 /**< Recommendation X.25: " Interface between data terminal equipment ( DTE ) and data circuit-terminating equipment ( DCE ) for terminals operating in the packet mode and connected to public data networks by dedicated circuit " */	 
 } _CiCcRecommendation;

typedef UINT8 CiCcRecommendation ;
typedef CiCcCause CiCcCustCause ;
//ICAT EXPORTED STRUCT 
 typedef struct _CiCcDiagnostic_struct {	 
	 
 CiBoolean InfoPresent ; /**< TRUE - is present ; FALSE - is not present \sa CCI API Ref Manual */	 
 CiCcCodingStandard Coding ; /**< Coding standard ( octet 3 of Cause Information Element ) as per 24.008000 10.500000 .4.11 \sa CiCcCodingStandard*/	 
 CiCcLocation Location ; /**< Location ( octet 3 of Cause Information Element ) as per 24.008000 10.500000 .4.11 \sa CiCcLocation */	 
 CiCcRecommendation Recommendation ; /**< Recommendation \sa CiCcRecommendation */	 
 CiCcCustCause Cause ; /**< Cause code \sa CiCcCustCause */	 
 CiCcDiagnosticInfo Info ; /**< Diagnostic information \sa _CiCcDiagnosticInfo_struct */	 
	 
 } CiCcDiagnostic;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimCallDiagnosticInd_struct {	 
	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 CiCcDiagnostic Diagnostic1 ; /**< First diagnostic information field \sa _CiCcDiagnosticInfo_struct */	 
 CiCcDiagnostic Diagnostic2 ; /**< Second diagnostic information field \sa _CiCcDiagnosticInfo_struct */	 
	 
 } CiCcPrimCallDiagnosticInd;

typedef CiEmptyPrim CiCcPrimClearBlackListReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimClearBlackListCnf_struct {	 
	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
	 
 } CiCcPrimClearBlackListCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetCtmStatusReq_struct {	 
 CiBoolean Active ; /**< Current CTM status \sa CCI API Ref Manual */	 
 } CiCcPrimSetCtmStatusReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetCtmStatuscnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSetCtmStatusCnf;

//ICAT EXPORTED ENUM 
 typedef enum CiCcCTMNegReportType_Tags {	 
 CTM_STARTED=1 , /**< Started */	 
 CTM_SUCCEDED , /**< Succeeded */	 
 CTM_FAILED /**< Failed */	 
 } _CiCcCTMNegReportType;

typedef UINT8 CiCcCTMNegReportType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimCTMNegReportInd_struct {	 
 CiCcCTMNegReportType CTMNegReport ; /**< Negotiation status result \sa CiCcCTMNegReportType */	 
 } CiCcPrimCTMNegReportInd;

typedef CiEmptyPrim CiCcPrimSyncAudioReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSyncAudioCnf_struct {	 
 CiCcResultCode Result ; /**< Result code. \sa CiCcResultCode */	 
 } CiCcPrimSyncAudioCnf;

typedef CiEmptyPrim CiCcPrimGetLineIdReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetLineIdCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 UINT8 LineID ; /**< Line ID - 1 or 2 */	 
 } CiCcPrimGetLineIdCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetLineIdReq_struct {	 
 UINT8 LineID ; /**< Line ID - 1 or 2 */	 
 } CiCcPrimSetLineIdReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetLineIdCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSetLineIdCnf;

//ICAT EXPORTED ENUM 
 typedef enum CICC_CD_CAUSE {	 
	 
 CICC_CD_ERROR = 0 , /* NW responded with error to call deflection request */	 
 CICC_CD_REJECT , /* OSI higher layer protocol */	 
 CICC_CD_NO_NW_RESPONSE , /* X.244 */	 
 CICC_CD_CALL_RELEASED , /* Reserved for system mangement convergence function */	 
	 
 CICC_NUM_CD_CAUSE /* Number of protocols discriminator defined */	 
 } _CiCcCDCauseType;

typedef UINT8 CiCcCDCauseType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimCallDeflectReq_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 CiAddressInfo DeflectedNumber ; /**< Call identifier \sa CiAddressInfo */	 
 CiSubaddrInfo DeflectedSubAddress ; /**< Call identifier \sa CiSubaddrInfo */	 
 } CiCcPrimCallDeflectReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimCallDeflectCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcCDCauseType CallDeflectionFailCause ; /**< Call deflection failure cause \sa CiCcCDCauseType */	 
 } CiCcPrimCallDeflectCnf;

typedef CiEmptyPrim CiCcPrimReadyStateInd ;
//ICAT EXPORTED ENUM 
 typedef enum CI_CC_ECALL_TYPE {	 
 CI_CC_ECALL_TYPE_TEST = 0 , /**< test call */	 
 CI_CC_ECALL_TYPE_RECONFIGURE = 1 , /**< reconfiguration call */	 
 CI_CC_ECALL_TYPE_MANUAL = 2 , /**< manually initiated */	 
 CI_CC_ECALL_TYPE_AUTOMATIC = 3 , /**< automatically initiated */	 
 CI_CC_ECALL_TYPE_NO_ACTIVE = 4 /**< no active eCall */	 
 } _CiCcECallTypeCode;

typedef UINT16 CiCcECallTypeCode ;
typedef UINT16 CiCcECallBitMaskTypes ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetCeCallReq_struct {	 
 CiCcECallTypeCode eCallType ; /**< eCall type */	 
 } CiCcPrimSetCeCallReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetCeCallCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimSetCeCallCnf;

typedef CiEmptyPrim CiCcPrimGetCeCallReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetCeCallCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcECallTypeCode eCallType ; /**< eCall type */	 
 } CiCcPrimGetCeCallCnf;

typedef CiEmptyPrim CiCcPrimGetCeCallCapReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetCeCallCapCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcECallBitMaskTypes eCallBitMaskSupportedTypes ; /**< eCall type */	 
 } CiCcPrimGetCeCallCapCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimAudioEcallToApInfoInd_struct 
 {	 
 UINT16 Length ;	 
 UINT8 RawData [ 128 ] ;	 
 } CiCcPrimAudioEcallToApInfoInd;

//ICAT EXPORTED ENUM 
 typedef enum CICC_CE_CAUSE {	 
	 
 CICC_CE_CALL_END_UNDEFINE = 0 , /*default value.*/	 
 CICC_CE_CALL_END_NORMAL , /*according to 24.008000 . involved:User busy.No user responding.User alerting no answer.	 
 user rejected.Destination out of order.Number changed.*/	 
 CICC_CE_CALL_END_RX_DISCONNECT ,	 
 CICC_CE_CALL_END_RX_RELEASE ,	 
 CICC_CE_CALL_END_UNRECOVERABLE , /*RLC Reset ( MaxRST or UL lost.Unrecoverable error in RLC on reset PDU ) .	 
 Cell Update ( unrecoverable error ) .*/	 
 CICC_CE_CALL_END_RLF_OR_WEAK_SIGNAL , /*RL failure ( T313 Expire ) or phych est failure ( T312 expire.Sync start fail ) .	 
 Cell Update ( RLF ) .*/	 
 CICC_CE_CALL_END_RX_RRC_CONNECTION_RELEASE ,	 
 CICC_CE_CALL_END_TX_DISCONNECT , /*User disconnect req from AP.*/	 
 CICC_CE_CALL_END_TX_RELEASE , /*No used now.*/	 
 CICC_CE_CALL_END_OTHERS ,	 
	 
 CICC_NUM_CE_CAUSE	 
 } _CiCcCEEventType;

typedef UINT8 CiCcCEEventType ;
//ICAT EXPORTED ENUM 
 typedef enum CICC_CE_MSG {	 
	 
 CICC_CE_MSG_TYPE_UNDEFINE = 0 ,	 
 CICC_CE_MSG_TYPE_CELL_UPDATE ,	 
 CICC_CE_MSG_TYPE_DISCONNECT ,	 
 CICC_CE_MSG_TYPE_RELEASE ,	 
 CICC_CE_MSG_TYPE_RRC_CONNECTION_RELEASE ,	 
	 
 CICC_NUM_CE_MSG	 
 } _CiCcCEMsgType;

typedef UINT8 CiCcCEMsgType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimCallEndInfoInd_struct {	 
 CiCcCallId CallId ; /**< Call identifier \sa CiCcCallId */	 
 CiCcCurrentCState State ; /**< Current call state \sa CiCcCurrentCState */	 
 CiCcCEMsgType CallEndMsg ;	 
 CiCcCEEventType CallEndType ;	 
 CiCcCause CallEndCause ;	 
 CiCcPrimCallDropCauseInfoInd	 
 SacDevInfo ;	 
 } CiCcPrimCallEndInfoInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiCCPrimEcallCfgReq_struct {	 
 UINT16 time ; /**< The time interval for writing eCall elapsed time to the NVM */	 
 UINT16 intimer1 ; /**< The eCall inactivity timer value */	 
 UINT16 intimer2 ; /**< The eCall inactivity timer value */	 
 } CiCcPrimEcallCfgReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCCPrimEcallCfgCnf_struct {	 
 CiCcResultCode result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimEcallCfgCnf;

typedef CiEmptyPrim CiCcPrimGetEcallCfgReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCCPrimGetEcallCfgCnf_struct {	 
 CiCcResultCode result ; /**< Result code \sa CiCcResultCode */	 
 UINT16 time ; /**< The interval to write to the NVM , the eCall elapsed time */	 
 UINT16 rtime ; /**< If an eCall was operated - the time elapsed since eCall was operated */	 
 UINT16 intimer1 ; /**< The eCall inactivity timer value */	 
 UINT16 intimer2 ; /**< The eCall inactivity timer value */	 
 } CiCcPrimGetEcallCfgCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimEcallOnlyReq_struct {	 
 CiBoolean Activate ; /**< If set to TRUE , than UE will act as if the USIM is configured for eCall only mode. If set the FALSE , than the UE returns to normal mode of operation. */	 
 CHAR testnum [ 40 ] ; /**< The eCall test number */	 
 UINT8 testnumLen ;	 
 CHAR reconfignum [ 40 ] ; /**< The eCall reconfiguration number */	 
 UINT8 reconfignumLen ;	 
 } CiCcPrimEcallOnlyReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimEcallOnlyCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 } CiCcPrimEcallOnlyCnf;

typedef CiEmptyPrim CiCcPrimGetEcallOnlyReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetEcallOnlyCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiBoolean Active ; /**< If set to TRUE , than the UE is configured to act as eCall only mode. If SIM support eCall only always return FALSE */	 
 UINT8 simEcall ; /**< 0 ��?SIM does not support eCall ( service No. 89 is ���not available��?in the USIM ) ; 1 ��?SIM supports eCall mode ( Service No. 89 and Service No. 4 are " available " ) ; 2 ��?SIM supports eCall only mode ( Service No. 89 and Service No. 2 are " available " and FDN service is enabled in EFEST ) */	 
 CHAR testnum [ 40 ] ; /**< The eCall test number */	 
 UINT8 testnumLen ;	 
 CHAR reconfignum [ 40 ] ; /**< The eCall reconfiguration number */	 
 UINT8 reconfignumLen ;	 
 } CiCcPrimGetEcallOnlyCnf;

//ICAT EXPORTED ENUM 
 typedef enum CICC_EMLPP_SUBSCRIPTIONS_INFO_TYPE {	 
 CICC_EMLPP_CALL_SUBSCRIPTIONS_INFO_TYPE_ENABLED = 0x00 , /* Indicates the info type is enabled call priorities , only { 0 , 1 , .. , 4 } are valid */	 
 CICC_EMLPP_CALL_SUBSCRIPTIONS_INFO_TYPE_FAST_CALL_SETUP = 0x01 , /* Indicates the info type is fast call set-up enabled priorities ( and enabled ) , { 0 , 1 , .. , 4 } are valid */	 
 CICC_EMLPP_CALL_SUBSCRIPTIONS_INFO_TYPE_AUTO_ANSWER = 0x02 , /* Indicates the info type is auto-answer enabled priorities ( and enabled ) , all priorities are valid*/	 
 } _CiCcEmlppSubscriptionsInfoType;

typedef UINT8 CiCcEmlppSubscriptionsInfoType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetEmlppSubscriptionsInfoReq_struct {	 
 CiCcEmlppSubscriptionsInfoType infoType ; /** Indicates which type of information is modified ( fast call setup OR automatic answer ) */	 
 CiCcEmlppCallPriority callPriority ; /** Indicates which call priority shall be modified */	 
 CiBoolean isEnabled ; /** Indicates whether the fast-call-set-up or auto-answer should be enabled / disabled */	 
 } CiCcPrimSetEmlppSubscriptionsInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimSetEmlppSubscriptionsInfoCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcEmlppSubscriptionsInfoType infoType ; /** Indicates which type of information was modified*/	 
 } CiCcPrimSetEmlppSubscriptionsInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetEmlppSubscriptionsInfoReq_struct {	 
 CiCcEmlppSubscriptionsInfoType infoType ; /** Indicates which type of information is required*/	 
 } CiCcPrimGetEmlppSubscriptionsInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimGetEmlppSubscriptionsInfoCnf_struct {	 
 CiCcResultCode Result ; /**< Result code \sa CiCcResultCode */	 
 CiCcEmlppSubscriptionsInfoType infoType ; /** Indicates which type of information is returned*/	 
 UINT8 numOfCallPriorities ; /** Indicates how many entries in the enabledCallPriorities array are valid*/	 
 CiCcEmlppCallPriority enabledCallPriorities [ CICC_EMLPP_NUM_OF_PRIORITIES ] ; /** List of enabled priorities , depending on the infoType. it can be enabled / enabled + fast-call-set-up enabled / enabled + auto-answer enabled */	 
 } CiCcPrimGetEmlppSubscriptionsInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiCcPrimListCallInfoInd_struct {	 
 UINT8 NumCalls ; /**< Number of current calls [ 0 ..CICC_MAX_CURRENT_CALLS ] */	 
 CiCcActMode callActMode ; /**< Current network mode>*/	 
 CiccAlertingType alertType [ 7 ] ; /**< InbandTones >*/	 
 CiCcCallInfo callInfo [ 7 ] ; /**< Call information list \sa CiCcCallInfo_struct */	 
 } CiCcPrimListCallInfoInd;

//ICAT EXPORTED ENUM 
 typedef enum CI_SIM_PRIM 
 {	 
 CI_SIM_PRIM_EXECCMD_REQ = 1 , /**< \brief Requests to execute a SIM command \details */	 
 CI_SIM_PRIM_EXECCMD_CNF , /**< \brief Confirms the request to execute a SIM command \details */	 
 CI_SIM_PRIM_DEVICE_IND , /**< \brief Indicates that the current SIM status changed \details */	 
 CI_SIM_PRIM_PERSONALIZEME_REQ , /**< \brief Requests that ME personalization be activated , deactivated , disabled , or queried \details */	 
 CI_SIM_PRIM_PERSONALIZEME_CNF , /**< \brief Confirms the request to activate , deactivate , disable , or query ME personalization \details */	 
 CI_SIM_PRIM_OPERCHV_REQ , /**< \brief Requests that CHVs be verified , enabled , disabled , changed , unblocked , or queried \details */	 
 CI_SIM_PRIM_OPERCHV_CNF , /**< \brief Confirms the request to verify , enable , disable , change , unblock , or query CHVs \details */	 
 CI_SIM_PRIM_DOWNLOADPROFILE_REQ , /**< \brief Requests a download of the profile that shows ME capabilities relevant to SIM Application Toolkit functionality \details The functionality of this primitive is equivalent to using the SIM command TERMINAL PROFILE in the CI_SIM_PRIM_EXECCMD_REQ primitive.	 
 * This primitive saves upper layer effort to build a header for the Terminal Profile SIM command.	 
 * If the pProfile pointer is NULL for this request , the communications interface assumes that the application layer does not support	 
 * SIM Application Toolkit operations. */	 
 CI_SIM_PRIM_DOWNLOADPROFILE_CNF , /**< \brief Confirms the request to download the profile that shows ME capabilities relevant to SIM Application Toolkit functionality \details */	 
 CI_SIM_PRIM_ENDATSESSION_IND , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_SIM_PRIM_PROACTIVE_CMD_IND , /**< \brief Indicates a SIMAT proactive command \details This primitive forwards the SIMAT proactive command with its original syntax. The primitive CI_SIM_PRIM_ENABLE_SIMAT_INDS_REQ enables and disables proactive command indication. */	 
 CI_SIM_PRIM_PROACTIVE_CMD_RSP , /**< \brief Responds to the SIMAT proactive command \details The primitive forwards a SIMAT proactive command response from the entity , such as DISPLAY or TERMINAL , that received the proactive command. */	 
 CI_SIM_PRIM_ENVELOPE_CMD_REQ , /**< \brief Requests that an ENVELOPE command be executed \details */	 
 CI_SIM_PRIM_ENVELOPE_CMD_CNF , /**< \brief Confirms the request to execute an ENVELOPE command \details */	 
 CI_SIM_PRIM_GET_SUBSCRIBER_ID_REQ , /**< \brief Requests the subscriber ID \details */	 
 CI_SIM_PRIM_GET_SUBSCRIBER_ID_CNF , /**< \brief Confirms the request for the subscriber ID \details */	 
 CI_SIM_PRIM_GET_PIN_STATE_REQ , /**< \brief Requests the current PIN state \details */	 
 CI_SIM_PRIM_GET_PIN_STATE_CNF , /**< \brief Confirms the request for the current PIN state \details */	 
 CI_SIM_PRIM_GET_TERMINALPROFILE_REQ , /**< \brief Requests the SIMAT terminal profile \details */	 
 CI_SIM_PRIM_GET_TERMINALPROFILE_CNF , /**< \brief Confirms the request and returns the SIMAT terminal profile \details */	 
 CI_SIM_PRIM_ENABLE_SIMAT_INDS_REQ , /**< \brief Requests that SIMAT related indications , such as the proactive SIM command indication and the SIMAT session ended indication , be enabled or disabled \details */	 
 CI_SIM_PRIM_ENABLE_SIMAT_INDS_CNF , /**< \brief Confirms the request to enable or disable SIMAT related indications \details */	 
 CI_SIM_PRIM_LOCK_FACILITY_REQ , /**< \brief Requests to lock , unlock , or query SIM-related ME \details */	 
 CI_SIM_PRIM_LOCK_FACILITY_CNF , /**< \brief Confirms a request to lock , unlock , or query SIM-related ME \details */	 
 CI_SIM_PRIM_GET_FACILITY_CAP_REQ , /**< \brief Requests the bitmask of supported SIM-related facility codes \details */	 
 CI_SIM_PRIM_GET_FACILITY_CAP_CNF , /**< \brief Confirms the request for the bitmask of supported SIM-related facility codes \details */	 
 CI_SIM_PRIM_GET_SIMAT_NOTIFY_CAP_REQ , /**< \brief Requests SIM Application Toolkit ( SIMAT ) notification capability information. \details */	 
 CI_SIM_PRIM_GET_SIMAT_NOTIFY_CAP_CNF , /**< \brief Confirms the request for SIM Application Toolkit ( SIMAT ) notification capability information \details */	 
 CI_SIM_PRIM_GET_CALL_SETUP_ACK_IND , /**< \brief Indicates that the SIM Application Toolkit ( SIMAT ) has initiated an outgoing CALL SETUP operation , and requests confirmation / acknowledgment from the mobile user \details The application returns the required acknowledgment in a CI_SIM_PRIM_GET_CALL_SETUP_ACK_RSP response. */	 
 CI_SIM_PRIM_GET_CALL_SETUP_ACK_RSP , /**< \brief Responds with an acknowledgment from the mobile user for an outgoing CALL SETUP indication \details The mobile user may accept ( allow ) or reject ( disallow ) the SIMAT initiated CALL SETUP operation.	 
 * If the user allows the CALL SETUP , it proceeds. If the user disallows the CALL SETUP , it is aborted.	 
 * If the CALL SETUP is allowed to proceed , the MO call progression is managed by the normal call control procedures. See the	 
 * CI CC Service Group API definition for more information. */	 
	 
 /* service provider name */	 
 CI_SIM_PRIM_GET_SERVICE_PROVIDER_NAME_REQ , /**< \brief Requests the service provider name , as stored on SIM or USIM \details The PIN status is not required to read this information. */	 
 CI_SIM_PRIM_GET_SERVICE_PROVIDER_NAME_CNF , /**< \brief Confirms the request to get the service provider name , as stored on SIM or USIM \details The service provider name is coded as 7 -bit GSM characters , with the most-significant bit of each character set to zero.	 
 * The service provider name pointer is NULL if the result code indicates an error. */	 
	 
 /* Message Waiting Information */	 
 CI_SIM_PRIM_GET_MESSAGE_WAITING_INFO_REQ , /**< \brief Requests to get message waiting information stored on SIM or USIM \details The PIN status is required to read this information. */	 
 CI_SIM_PRIM_GET_MESSAGE_WAITING_INFO_CNF , /**< \brief Confirms the request to get message waiting information stored on SIM or USIM \details If the result code indicates an error , the message waiting status information is not useful.	 
 * There is a difference between the message categories defined for 2 G and 3 G SIM storage. This is rationalized by the CCI implementation. */	 
 CI_SIM_PRIM_SET_MESSAGE_WAITING_INFO_REQ , /**< \brief Requests to set message waiting information on SIM or USIM \details Requires PIN status to write this information. There is a difference between the message categories defined for 2 G and 3 G SIM storage. This is rationalized by the CCI implementation. */	 
 CI_SIM_PRIM_SET_MESSAGE_WAITING_INFO_CNF , /**< \brief Confirms a request to set the message waiting information on SIM or USIM \details */	 
	 
 /* SIM Service Table */	 
 CI_SIM_PRIM_GET_SIM_SERVICE_TABLE_REQ , /**< \brief Requests to get the SIM Service Table from SIM or USIM \details The PIN status is required to read this information. If CPHS features are not supported by the handset , this information is unavailable. */	 
 CI_SIM_PRIM_GET_SIM_SERVICE_TABLE_CNF , /**< \brief Confirms the request to get the SIM Service Table from SIM or USIM \details If CPHS features are not supported by the handset , this information is unavailable. */	 
	 
 /* CPHS Customer Service Profile */	 
 CI_SIM_PRIM_GET_CUSTOMER_SERVICE_PROFILE_REQ , /**< \brief Requests to get the CPHS customer service profile from SIM or USIM \details The PIN status is required to read this information. If CPHS features are not supported by the handset , this information is unavailable. */	 
 CI_SIM_PRIM_GET_CUSTOMER_SERVICE_PROFILE_CNF , /**< \brief Confirms the request and returns the CPHS customer service profile from SIM or USIM. \details If CPHS features are not supported by the handset , this information is unavailable. */	 
	 
 /* Display Alpha and Icon Identifiers */	 
 CI_SIM_PRIM_SIMAT_DISPLAY_INFO_IND , /**< \brief Indicates to the application that text and optionally an icon should be displayed.	 
 * The text to be displayed results from a SAT transaction such as SS , SMS , USSD , SS , or send DTMF. \details */	 
	 
 /* Default Language */	 
 CI_SIM_PRIM_GET_DEFAULT_LANGUAGE_REQ , /**< \brief Requests the default language stored on the SIM / USIM card \details */	 
 CI_SIM_PRIM_GET_DEFAULT_LANGUAGE_CNF , /**< \brief Confirms the request to get the default language stored on the SIM / USIM card and returns the first entry in the EF_LP file \details Extract from ETSI TS 102.221000 : " the language code is a pair of alphanumeric characters , as defined in ISO 639 [ 30 ] .	 
 * Each alphanumeric character shall be coded on one byte using the SMS default 7 -bit coded alphabet as defined in TS 23.038000	 
 * ( " Man-machine Interface ( MMI ) of the User Equipment " , revision 3.400000 .0 , Doc Number 3 GPP TS 22.030000 )	 
 * with bit 8 set to 0 . " . ' FF FF ' means undefined default language. */	 
	 
 /* Generic SIM commands */	 
 CI_SIM_PRIM_GENERIC_CMD_REQ , /**< \brief Requests to send a generic command to the SIM / USIM card	 
 * \details The request reflects the structure of a SIM application protocol data unit ( APDU ) ,	 
 * as defined in ETSI 102.221000 . The ' class of instruction ' element is not controlled by the user , comm. use class 0x0 or 0xa depending on the command.	 
 * Note that updating a file using this command only updates the file on the SIM ; it does not trigger a REFRESH of the ME memory. */	 
 CI_SIM_PRIM_GENERIC_CMD_CNF , /**< \brief Confirms a request to send a generic command to the SIM or USIM \details */	 
	 
 /* Indication of card type , status and PIN state */	 
 CI_SIM_PRIM_CARD_IND , /**< \brief Indicates that the current SIM / USIM status changed \details This indication is sent each time CI_SIM_PRIM_DEVICE_IND is sent. */	 
	 
 CI_SIM_PRIM_IS_EMERGENCY_NUMBER_REQ , /**< \brief Requests to determine if the specified dial number is an emergency call code \details */	 
 CI_SIM_PRIM_IS_EMERGENCY_NUMBER_CNF , /**< \brief Confirms the request to determine if the specified number is an emergency call code \details If a SIM card is present , the EF_ECC SIM card file is searched for the specified number. If a SIM card is not present , a default table of possible emergency call codes is searched for the specified number , as per TS 22.101000 . */	 
	 
 CI_SIM_PRIM_SIM_OWNED_IND , /**< \brief Indicates whether the SIM is owned	 
 * \details This indication is sent each time a SIM-OK notification is received	 
 * from the protocol stack and indicates that the SIM card can be accessed. SIM owned is TRUE if the IMSI did not change	 
 * since the last SIM-OK notification. */	 
 CI_SIM_PRIM_SIM_CHANGED_IND , /**< \brief Indicates whether the IMSI on the current SIM has changed	 
 * \details This indication is sent each time a SIM-OK notification is received	 
 * from the protocol stack. */	 
 CI_SIM_PRIM_DEVICE_STATUS_REQ , /**< \brief Requests SIM status \details */	 
 CI_SIM_PRIM_DEVICE_STATUS_CNF , /**< \brief Confirms the request for the current SIM status \details */	 
 CI_SIM_PRIM_READ_MEP_CODES_REQ , /**< \brief Requests the MEP codes for a specified category \details This operation does not require a password.*/	 
 CI_SIM_PRIM_READ_MEP_CODES_CNF , /**< \brief Confirms the request and returns the MEP codes for the specified category \details */	 
 CI_SIM_PRIM_UDP_LOCK_REQ , /**< \brief Requests an activate , deactivate , or query UDP lock \details An operation can be done on only one category at a time. A password is required for an unlock operation. */	 
 CI_SIM_PRIM_UDP_LOCK_CNF , /**< \brief Confirms the UDP lock request \details */	 
 CI_SIM_PRIM_UDP_CHANGE_PASSWORD_REQ , /**< \brief Requests to set a new password for a UDP lock \details */	 
 CI_SIM_PRIM_UDP_CHANGE_PASSWORD_CNF , /**< \brief Confirms the request to set a new password for a UDP lock \details */	 
 CI_SIM_PRIM_UDP_ASL_REQ , /**< \brief Requests to manipulate the UDP authorized SIM list \details */	 
 CI_SIM_PRIM_UDP_ASL_CNF , /**< \brief Confirms the request to manipulate the UDP authorized SIM list \details */	 
 /* Michal Bukai - Virtual SIM support - START */	 
 CI_SIM_PRIM_SET_VSIM_REQ , /**< \brief Requests to enable virtual SIM	 
 * \details Virtual SIM can be enabled if no SIM is inserted.	 
 * An error is sent if the user tried to enable virtual SIM while a SIM is inserted.	 
 * The application needs to reset the communication subsystem after receiving a confirmation. */	 
 CI_SIM_PRIM_SET_VSIM_CNF , /**< \brief Confirms setting virtual SIM	 
 * \details Virtual SIM can be enabled if no SIM is inserted.	 
 * An error is sent if the user tried to enable virtual SIM while a SIM is inserted.	 
 * The application needs to reset the communication subsystem after receiving a confirmation. */	 
 CI_SIM_PRIM_GET_VSIM_REQ , /**< \brief Requests the current setting of the virtual SIM ( enabled / disabled ) \details*/	 
 CI_SIM_PRIM_GET_VSIM_CNF , /**< \brief Confirms the request and returns the current setting of the virtual SIM ( enabled / disabled ) \details*/	 
 /* Michal Bukai - Virtual SIM support - END */	 
 /*Michal Bukai - OTA support for AT&T - START*/	 
 CI_SIM_PRIM_CHECK_MMI_STATE_IND , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 CI_SIM_PRIM_CHECK_MMI_STATE_RSP , /**< \brief \details NOT SUPPORTED REMOVE FROM API */	 
 /*Michal Bukai - OTA support for AT&T - END*/	 
 /*Michal Bukai - BT SAP support - START*/	 
 CI_SIM_PRIM_BTSAP_CONNECT_REQ , /**< \brief Requests to start a BT SAP session \details */	 
 CI_SIM_PRIM_BTSAP_CONNECT_CNF , /**< \brief Confirms the request to start a BT SAP session \details */	 
 CI_SIM_PRIM_BTSAP_DISCONNECT_REQ , /**< \brief Requests to disconnect from a BT SAP session \details */	 
 CI_SIM_PRIM_BTSAP_DISCONNECT_CNF , /**< \brief Confirms the request to disconnect from a BT SAP session \details */	 
 CI_SIM_PRIM_BTSAP_TRANSFER_APDU_REQ , /**< \brief Requests to transfer APDU to the SIM / USIM \details */	 
 CI_SIM_PRIM_BTSAP_TRANSFER_APDU_CNF , /**< \brief Confirms the request to transfer APDU to the SIM / USIM and may return a response APDU from the SIM / USIM \details */	 
 CI_SIM_PRIM_BTSAP_TRANSFER_ATR_REQ , /**< \brief Requests to get Answer To Reset data from SIM / USIM \details */	 
 CI_SIM_PRIM_BTSAP_TRANSFER_ATR_CNF , /**< \brief Confirms the request to get Answer To Reset data from SIM / USIM \details */	 
 CI_SIM_PRIM_BTSAP_SIM_CONTROL_REQ , /**< \brief Requests to control SIM / USIM status , this command can be used to power off , power on or reset the SIM / USIM \details */	 
 CI_SIM_PRIM_BTSAP_SIM_CONTROL_CNF , /**< \brief Confirms the SIM control request \details */	 
 CI_SIM_PRIM_BTSAP_STATUS_IND , /**< \brief indicates a change in the availably of the subscription module during BT SAP connection \details */	 
 CI_SIM_PRIM_BTSAP_STATUS_REQ , /**< \brief Requests the subscription module availability status during BT SAP connection \details */	 
 CI_SIM_PRIM_BTSAP_STATUS_CNF , /**< \brief Confirms the request and returns the status of the subscription module during BT SAP connection \details */	 
 CI_SIM_PRIM_BTSAP_SET_TRANSPORT_PROTOCOL_REQ , /**< \brief Requests to set transport protocol \details */	 
 CI_SIM_PRIM_BTSAP_SET_TRANSPORT_PROTOCOL_CNF , /**< \brief Confirms the request to set transport protocol \details */	 
 /*Michal Bukai - BT SAP support - END*/	 
 /*Michal Bukai - Add IMSI to MEP code group - START*/	 
 CI_SIM_PRIM_MEP_ADD_IMSI_REQ , /**< \brief Requests to add the current IMSI to MEP SIM / USIM code group	 
 * \details This operation requires a password.	 
 * This operation requires that SIM / USIM personalization is deactivated.*/	 
 CI_SIM_PRIM_MEP_ADD_IMSI_CNF , /**< \brief Confirms the request to add the current IMSI to MEP SIM / USIM code group. \details */	 
 /*Michal Bukai - Add IMSI to MEP code group - END*/	 
 /*Michal Bukai - SIM Logic CH - NFC\ISIM support - START*/	 
 CI_SIM_PRIM_OPEN_LOGICAL_CHANNEL_REQ , /**< \brief Requests to open a logical channel that will be used to access the UICC application identified by DFname. \details The UICC will open a new logical channel ; select the application identified by the DFname , and return a session ID that will be used to identify the new channel.*/	 
 CI_SIM_PRIM_OPEN_LOGICAL_CHANNEL_CNF , /**< \brief Confirms the request to open a logical channel and returns the session ID. \details */	 
 CI_SIM_PRIM_CLOSE_LOGICAL_CHANNEL_REQ , /**< \brief Requests to close a logical channel. \details */	 
 CI_SIM_PRIM_CLOSE_LOGICAL_CHANNEL_CNF , /**< \brief Confirms the request to close a logical channel. \details */	 
 /*Michal Bukai - SIM Logic CH - NFC\ISIM support support - END*/	 
 /*Michal Bukai - additional SIMAT primitives - START*/	 
 CI_SIM_PRIM_SIMAT_CC_STATUS_IND , /**< \brief Indicates the SIM Application Toolkit ( SIMAT ) call control status response	 
 * \details If call control service in SIMAT is activated , all dialled digit strings , supplementary service control strings and USSD strings are passed to the UICC before the call setup request ,	 
 * the supplementary service operation or the USSD operation is sent to the network.	 
 * The SIMAT has the ability to allow , bar or modify the request.	 
 * In addition SIMAT has the ability to replace the request by another operation , for instance call request may be replaced by SS or USSD operation.	 
 */	 
 CI_SIM_PRIM_SIMAT_SEND_CALL_SETUP_RSP_IND , /**< \brief Indicates the response sent to SIM Application Toolkit ( SIMAT ) after call setup. \details */	 
 CI_SIM_PRIM_SIMAT_SEND_SS_USSD_RSP_IND , /**< \brief Indicates the response sent to SIM Application Toolkit ( SIMAT ) after SS or USSD operation. \details */	 
 CI_SIM_PRIM_SIMAT_SM_CONTROL_STATUS_IND , /**< \brief Indicates the SIM Application Toolkit ( SIMAT ) short message control status response.	 
 \details If SM control service in SIMAT is activated , all MO short messages are passed to the UICC before the short message is sent to the network.	 
 * The SIMAT has the ability to allow , bar or modify the destination address.	 
 */	 
 CI_SIM_PRIM_SIMAT_SEND_SM_RSP_IND , /**< \brief Indicates the response sent to SIM Application Toolkit ( SIMAT ) after SM operation. \details */	 
 /*Michal Bukai - additional SIMAT primitives - END*/	 
	 
 /*Michal Bukai - RSAP support - START*/	 
 CI_SIM_PRIM_RSAP_CONN_REQ_IND , /**< \brief Request to connect to a remote SIM received from the protocol stack \details */	 
 CI_SIM_PRIM_RSAP_CONN_REQ_RSP , /**< \Response to protocol stack request to connect to a remote SIM \details */	 
 CI_SIM_PRIM_RSAP_STAT_REQ , /**< \brief Request received from a SAP conversion module to update the RSAP card status.	 
 * \details This request is actually an indication from a remote SAP conversion module indicating a status change in the remote connection or card status */	 
 CI_SIM_PRIM_RSAP_STAT_CNF , /**< \brief Confirms that the update of the remote card status was received by the protocol stack \details */	 
 CI_SIM_PRIM_RSAP_DISCONN_REQ_IND , /**< \brief Request to disconnect from a remote SIM received from the protocol stack \details */	 
 CI_SIM_PRIM_RSAP_DISCONN_REQ_RSP , /**< \Response to protocol stack request to disconnect from a remote SIM \details */	 
 CI_SIM_PRIM_RSAP_GET_ATR_IND , /**< \brief Request to get ATR from a remote SIM received from the protocol stack \details */	 
 CI_SIM_PRIM_RSAP_GET_ATR_RSP , /**< \brief Response from a remote SIM with the ATR APDU \details */	 
 CI_SIM_PRIM_RSAP_GET_STATUS_REQ_IND , /**< \brief Request from the protocol stack to get the RSAP connection status.	 
 * \details The request is answered by CI_SIM_PRIM_RSAP_CONN_STAT_REQ */	 
	 
 CI_SIM_PRIM_RSAP_SET_TRAN_P_REQ_IND , /**< \brief Request from the protocol stack to change the transport protocol of the remote SIM \details */	 
 CI_SIM_PRIM_RSAP_SET_TRAN_P_REQ_RSP , /**< \brief Response to a protocol stack request to change the transport protocol of the remote SIM.	 
 * \details If the requested transport protocol is supported by the remote SIM and by the SAP conversion module ,	 
 * the requested transport protocol is selected and the remote SIM is reset. If the requested transport protocol is not supported ,	 
 * SIM status is changed to CARD_NOT_ACC. The request is followed by CI_SIM_PRIM_RSAP_CONN_STAT_REQ , which indicates the new remote SIM status.*/	 
 CI_SIM_PRIM_RSAP_SIM_CONTROL_REQ_IND , /**< \brief Request from the protocol stack to control the remote SIM status.	 
 * \details This command can be used to power off , power on , or reset the remote SIM */	 
 CI_SIM_PRIM_RSAP_SIM_CONTROL_REQ_RSP , /**< \brief Response to a protocol stack request to control the remote SIM status.	 
 * \details The response is followed by CI_SIM_PRIM_RSAP_CONN_STAT_REQ , which indicates the new status of the remote SIM.*/	 
 CI_SIM_PRIM_RSAP_SIM_SELECT_REQ , /**< \brief Request to select the local or remote SIM \details */	 
 CI_SIM_PRIM_RSAP_SIM_SELECT_CNF , /**< \brief Confirms the request to select the local or remote SIM \details */	 
 CI_SIM_PRIM_RSAP_STATUS_IND , /**< \brief Indicates that the current SIM / USIM status changed during RSAP connection \details */	 
 CI_SIM_PRIM_RSAP_TRANSFER_APDU_IND , /**< \brief Request from the protocol stack to transfer APDU to the remote SIM \details */	 
 CI_SIM_PRIM_RSAP_TRANSFER_APDU_RSP , /**< \brief Request from the protocol stack to transfer APDU to the remote SIM.	 
 * \details A response APDU is returned if the transfer of APDU is successful.*/	 
 /*Michal Bukai - RSAP support - END*/	 
	 
 CI_SIM_PRIM_DEVICE_RSP , /**< \brief Response to CI_SIM_PRIM_DEVICE_RSP.	 
 * \details This response is confirms that the CI_SIM_PRIM_DEVICE_RSP has been received and handled. Specially the SIM clock stop level. This indicates the Comm that D2 can be enabled on SIM driver level.*/	 
 // ICC ID feature	 
 CI_SIM_PRIM_ICCID_IND , /**< \brief Indicates the content of the EF-ICCID file. This indication is sent at init. The EF-ICCID can be accessed even if PIN is required.*/	 
 CI_SIM_PRIM_GET_ICCID_REQ , /**< \brief Request to get the content of the EF-ICCID file. Can be sent if ICC is ready.	 
 * \details Can be sent when the SIM state is CI_SIM_ST_READY or CI_SIM_ST_INSERTED. Otherwise the request will fail.*/	 
	 
 CI_SIM_PRIM_GET_ICCID_CNF , /**< \brief Confirmation with the ICC id to the request to get the ICC Id.*/	 
 // ICC ID feature	 
 CI_SIM_PRIM_EAP_AUTHENTICATION_REQ , /**< \brief Requests to exchange EAP packets with the UICC. */	 
 CI_SIM_PRIM_EAP_AUTHENTICATION_CNF , /**< \brief Confirms the EAP authentication request and returns the authentication response */	 
	 
 CI_SIM_EAP_RETRIEVE_PARAMETERS_REQ , /**< \brief Requests to retrieve EAP parameters from the UICC. */	 
 CI_SIM_EAP_RETRIEVE_PARAMETERS_CNF , /**< \brief Confirms the request to retrieve EAP parameters and returns the contents of the	 
 * \elementary file corresponding to requested parameter.*/	 
	 
 CI_SIM_PRIM_GET_NUM_UICC_APPLICATIONS_REQ , /**< \brief Requests to get number of applications available on the UICC. */	 
 CI_SIM_PRIM_GET_NUM_UICC_APPLICATIONS_CNF , /**< \brief Confirms the request to get number of applications available on the UICC. */	 
	 
 CI_SIM_PRIM_GET_UICC_APPLICATIONS_INFO_REQ , /**< \brief Requests to get list of applications available on the UICC. */	 
 CI_SIM_PRIM_GET_UICC_APPLICATIONS_INFO_CNF , /**< \brief Confirms the request to get list of applications available on the UICC. */	 
 /* ADD NEW COMMON PRIMITIVES HERE , BEFORE ' CI_SIM_PRIM_LAST_COMMON_PRIM ' */	 
 /*2013.12.11 , added by Xili for CQ00051618 , begin*/	 
 CI_SIM_PRIM_ISIM_AID_IND , /**< \brief Indicates the content of the ISIM Aid. This indication is sent at init if it had one. */	 
 /*2013.12.11 , added by Xili for CQ00051618 , end*/	 
	 
 /* Add by jungle for CQ00057999 on 2014 -04-02 Begin */	 
 CI_SIM_PRIM_APP_PIN_REQ ,	 
 CI_SIM_PRIM_APP_PIN_CNF ,	 
 /* Add by jungle for CQ00057999 on 2014 -04-02 End*/	 
	 
 /*2014.05.08 , added by Xili for CQ00060947 , begin*/	 
 CI_SIM_PRIM_ADMIN_DATA_IND ,	 
 /*2014.05.08 , added by Xili for CQ00060947 , end*/	 
	 
 /*2015.03.19 , mod by Xili for adding ECC list indication , CQ00088196 begin*/	 
 CI_SIM_PRIM_ECC_LIST_IND ,	 
 /*2015.03.19 , mod by Xili for adding ECC list indication , CQ00088196 end*/	 
	 
 /* Mod by jungle for CQ00089692 on 2015 -04-08 Begin */	 
 CI_SIM_PRIM_EXEC_LARGE_CMD_CNF ,	 
 CI_SIM_PRIM_GENERIC_LARGE_CMD_CNF ,	 
 /* Mod by jungle for CQ00089692 on 2015 -04-08 End */	 
	 
 /*CQ00113882 , Cgliu , 2019 -02-26 , Begin*/	 
 CI_SIM_PRIM_UPDATE_COUNT_REQ ,	 
 CI_SIM_PRIM_UPDATE_COUNT_CNF ,	 
 /*CQ00113882 , Cgliu , 2019 -02-26 , End */	 
 /*CQ00116569 , Cgliu , 2019 -10-15 , Begin*/	 
 /*Add *SIMPOLL command...*/	 
 CI_SIM_PRIM_SET_POLL_REQ ,	 
 CI_SIM_PRIM_SET_POLL_CNF ,	 
 CI_SIM_PRIM_GET_POLL_REQ ,	 
 CI_SIM_PRIM_GET_POLL_CNF ,	 
 /*CQ00116569 , Cgliu , 2019 -10-15 , End */	 
	 
 /* END OF COMMON PRIMITIVES LIST */	 
 CI_SIM_PRIM_LAST_COMMON_PRIM	 
	 
 /* The customer specific extension primitives are added starting from	 
 * CI_SIM_PRIM_firstCustPrim = CI_SIM_PRIM_LAST_COMMON_PRIM as the first identifier.	 
 * The actual primitive names and IDs are defined in the associated	 
 * ' ci_sim_cust_xxx.h ' file.	 
 */	 
	 
 /* DO NOT ADD ANY MORE PRIMITIVES HERE */	 
	 
 } _CiSimPrim;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimCmdReq_Struct {	 
 UINT16 len ; /**< Length of SIM command [ 5 -CI_SIM_MAX_CMD_DATA_SIZE ] */	 
 UINT8 data [ 261 ] ; /**< SIM command data. The format is according to 3 GPP TS 11.110000 , v8.6.0 , 9 . */	 
 } CiSimCmdReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiMepPassword_struct {	 
 UINT8 len ; /* length of the password , [ CI_MIN_PASSWORD_LENGTH - CI_MAX_PASSWORD_LENGTH ] */	 
	 
 UINT8 data [ 32 ] ;	 
	 
 } CiMepPassword;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimCmdRsp_Struct {	 
 UINT16 len ; /**< Length of the SIM response , [ 2 -CI_SIM_MAX_CMD_DATA_SIZE ] */	 
 UINT8 data [ 261 ] ; /**< SIM response. The format is according to 3 GPP TS 11.110000 , v8.6.0 , 9 . */	 
 } CiSimCmdRsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimLargeCmdRsp_Struct {	 
 UINT16 len ;	 
 UINT8 data [ 2050 ] ;	 
 } CiSimLargeCmdRsp;

//ICAT EXPORTED ENUM 
 typedef enum CISIMSTATUS_TAG {	 
 CI_SIM_ST_READY = 0 , /**< SIM is initialized / validated and can be accessed. */	 
 CI_SIM_ST_NOT_READY , /**< SIM is not inserted or has not been successfully initialized / validated. */	 
	 
 CI_SIM_ST_INSERTED , /**< SIM is inserted and is being initialized / validated. */	 
 CI_SIM_ST_ERROR , /**< SIM is inserted , but frame error happens */	 
	 
 CI_SIM_ST_SIM_PRESENT , /**< SIM1 / 2 is inserted , specially only for SIM2 detect first */	 
 CI_SIM_ST_SIM_ABSENT , /**< SIM1 / 2 is not inserted , specially only for SIM2 detect first */	 
	 
 CI_SIM_NUM_STATUSES	 
 } _CiSimStatus;

typedef UINT8 CiSimStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMPINSTATE_TAG {	 
 CI_SIM_PIN_ST_READY , /**< SIM is ready */	 
	 
 CI_SIM_PIN_ST_CHV1_REQUIRED , /**< SIM is locked ; waiting for a CHV1 password */	 
 CI_SIM_PIN_ST_CHV2_REQUIRED , /**< SIM is locked ; waiting for a CHV2 password */	 
 CI_SIM_PIN_ST_UNBLOCK_CHV1_REQUIRED , /**< SIM is blocked ; CHV1 unblocking password is required */	 
 CI_SIM_PIN_ST_UNBLOCK_CHV2_REQUIRED , /**< SIM is blocked ; CHV2 unblocking password is required */	 
	 
 /* Note: the ' **CK ' states are not fully supported at this time */	 
 CI_SIM_PIN_ST_PCK_REQUIRED , /**< SIM is locked due to a SIM / USIM personalization check failure.	 
 * SIM is waiting for a PCK control key to deactivate SIM / USIM personalization. */	 
 CI_SIM_PIN_ST_NCK_REQUIRED , /**< SIM is locked due to a network personalization check failure.	 
 * SIM is waiting for a NCK control key to deactivate network personalization. */	 
 CI_SIM_PIN_ST_NSCK_REQUIRED , /**< SIM is locked due to a network subset personalization check failure.	 
 * SIM is waiting for a NSCK control key to deactivate network subset personalization. */	 
 CI_SIM_PIN_ST_SPCK_REQUIRED , /**< SIM is locked due to a service provider personalization check failure.	 
 * SIM is waiting for a SPCK control key to deactivate service provider personalization. */	 
 CI_SIM_PIN_ST_CCK_REQUIRED , /**< SIM is locked due to a corporate personalization check failure.	 
 * SIM is waiting for a CCK control key to deactivate corporate personalization. */	 
 CI_SIM_PIN_ST_UNBLOCK_PCK_REQUIRED , /**< SIM is blocked due to an incorrect PCK ; an MEP unblocking password is required. */	 
 CI_SIM_PIN_ST_UNBLOCK_NCK_REQUIRED , /**< SIM is blocked due to an incorrect NCK ; an MEP unblocking password is required. */	 
 CI_SIM_PIN_ST_UNBLOCK_NSCK_REQUIRED , /**< SIM is blocked due to an incorrect NSCK ; an MEP unblocking password is required. */	 
 CI_SIM_PIN_ST_UNBLOCK_SPCK_REQUIRED , /**< SIM is blocked due to an incorrect SPCK ; an MEP unblocking password is required. */	 
 CI_SIM_PIN_ST_UNBLOCK_CCK_REQUIRED , /**< SIM is blocked due to an incorrect CCK ; an MEP unblocking password is required. */	 
	 
 /* note , according to 3 GPP TS 22.022000 , v3.4.0 , there is no standard way to unblock a locked */	 
 /* personalization key */	 
	 
 /* Note: the ' HIDDENKEY ' states are not supported at this time */	 
 CI_SIM_PIN_ST_HIDDENKEY_REQUIRED , /**< Expecting key for hidden phone book entries */	 
 CI_SIM_PIN_ST_UNBLOCK_HIDDENKEY_REQUIRED , /**< Expecting code to unblock the hidden key */	 
	 
 CI_SIM_PIN_ST_UNIVERSALPIN_REQUIRED , /**< Expecting the universal PIN */	 
 CI_SIM_PIN_ST_UNBLOCK_UNIVERSALPIN_REQUIRED , /**< Expecting code to unblock the universal PIN */	 
	 
 CI_SIM_PIN_ST_CHV1_BLOCKED , /**< Use of CHV1 is blocked */	 
 CI_SIM_PIN_ST_CHV2_BLOCKED , /**< Use of CHV2 is blocked */	 
 CI_SIM_PIN_ST_UNIVERSALPIN_BLOCKED , /**< Use of the universal PIN is blocked */	 
 CI_SIM_PIN_ST_UNBLOCK_CHV1_BLOCKED , /**< Use of code to unblock the CHV1 is blocked */	 
 CI_SIM_PIN_ST_UNBLOCK_CHV2_BLOCKED , /**< Use of code to unblock the CHV2 is blocked */	 
 CI_SIM_PIN_ST_UNBLOCK_UNIVERSALPIN_BLOCKED , /**< Use of code to unblock the universal PIN is blocked */	 
	 
 CI_SIM_PIN_ST_NETWORK_REJECTED , /**< SIM was rejected by the network. See GSM 3.220000 for possible reasons of network rejection. For example , IMSI is unknown in	 
 * the HLR or the IMSI is on the blacklist. */	 
 CI_SIM_PIN_ST_WAIT_INITIALISATION , /**< SIM is being initialized ; waiting for completion */	 
 CI_SIM_PIN_ST_INIT_FAILED , /**< SIM initialization failed */	 
 CI_SIM_PIN_ST_REMOVED , /**< SIM was removed */	 
 CI_SIM_PIN_ST_WRONG_SIM , /**< SIM was inserted but was not accepted by the protocol stack */	 
 CI_SIM_PIN_ST_GENERAL_ERROR , /**< SIM access encountered a serious error */	 
 CI_SIM_PIN_ST_MEP_ERROR , /**< Error in checking or accessing ME personalization data */	 
 CI_SIM_PIN_ST_UDP_ERROR , /**< Error in checking or accessing UDP personalization data */	 
 CI_SIM_PIN_ST_CPHS_ERROR , /**< Error in accessing CPHS data */	 
	 
 CI_SIM_PIN_ST_EMPTY_ESIM , /**< SIM is being initialized , but empty eSIM */	 
	 
 CI_SIM_PIN_NUM_STATES	 
 } _CiSimPinState;

typedef UINT8 CiSimPinState ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMRC_TAG {	 
 CIRC_SIM_OK = 0 , /**< Success */	 
 CIRC_SIM_FAILURE , /**< CME 13 - SIM failure */	 
 CIRC_SIM_MEM_PROBLEM , /**< CME 23 - Memory problem */	 
 CIRC_SIM_SIMAT_BUSY , /**< CME 14 - SIMAT busy */	 
 CIRC_SIM_INFO_UNAVAILABLE , /**< CME 100 - Requested information is unavailable */	 
 CIRC_SIM_NOT_INSERTED , /**< CME 10 - SIM not inserted */	 
 CIRC_SIM_PIN_REQUIRED , /**< CME 11 - SIM PIN ( CHV1 ) required */	 
 CIRC_SIM_PUK_REQUIRED , /**< CME 12 - SIM PUK required */	 
 CIRC_SIM_BUSY , /**< CME 14 - SIM busy */	 
 CIRC_SIM_WRONG , /**< CME 15 - SIM wrong */	 
 CIRC_SIM_INCORRECT_PASSWORD , /**< CME 16 - Incorrect password */	 
 CIRC_SIM_PIN2_REQUIRED , /**< CME 17 - SIM PIN2 ( CHV2 ) required */	 
 CIRC_SIM_PUK2_REQUIRED , /**< CME 18 - SIM PUK2 required */	 
 CIRC_SIM_OPERATION_NOT_ALLOWED , /**< CME 3 - Operation not allowed */	 
 CIRC_SIM_MEMORY_FULL , /**< CME 20 - Memory full */	 
 CIRC_SIM_UNKNOWN , /**< CME 100 - General error */	 
 CIRC_SIM_PERSONALISATION_DISABLED , /**< CME 3 - Operation failed since personalization is disabled */	 
 CIRC_SIM_PERSONALISATION_BLOCKED , /**< CME 41 , CME 43 , CME 45 or CME 47 - Operation failed since personalization is blocked */	 
 CIRC_SIM_PERSONALISATION_UNKNOWN , /**< CME 100 - Operation failed since personalization database is not available */	 
 CIRC_SIM_PERSONALISATION_NOT_SUPPORTED , /**< CME 4 - Operation failed since personalization is not supported */	 
 CI_SIM_BTSAP_RC_ERR_CARD_NOT_ACC , /**< Error , card not accessible */	 
 CI_SIM_BTSAP_RC_ERR_CARD_POWERED_OFF , /**< Error , card ( already ) powered off */	 
 CI_SIM_BTSAP_RC_ERR_CARD_REMOVED , /**< Error , card removed */	 
 CI_SIM_BTSAP_RC_ERR_CARD_POWERED_ON , /**< Error , card ( already ) powered on */	 
 CI_SIM_BTSAP_RC_ERR_DATA_NOT_AVAILABLE , /**< Error , data not available */	 
 CI_SIM_BTSAP_RC_ERR_NOT_SUPPORTED , /**< Error , not supported */	 
 CIRC_SIM_INVALID_PARAMETER , /**< Generic error - the requested service primitive has invalid parameters */	 
 CIRC_SIM_INVALID_REQ , /**< Generic error - the requested service primitive can not be handled at current state */	 
 CIRC_SIM_SIM_NOT_READY , /**< Generic error - the requested service primitive fails because SIM is not ready */	 
 CIRC_SIM_ACCESS_DENIED , /**< Generic error - the requested service primitive fails because access is denied */	 
 CIRC_SIM_LONG_STR , /**< Generic error - the requested service primitive has an invalid parameter with string too long */	 
	 
	 
 CIRC_SIM_NUM_RESCODES	 
 } _CiSimRc;

typedef UINT16 CiSimRc ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMMMISTATE_TAG {	 
 CI_SIM_MMI_IDLE = 0 , /**< MMI is in idle screen and user did not enter any keys */	 
 CI_SIM_MMI_BUSY , /**< There is an acitve menu or the user entered keys on the idle screen */	 
	 
 CI_SIM_MMI_NUM_STATE	 
 } _CiSimMMIState;

typedef UINT8 CiSimMMIState ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMCHVNO_TAG {	 
 CI_SIM_CHV_1 = 1 , /**< CHV1 */	 
 CI_SIM_CHV_2 , /**< CHV2 */	 
	 
 CI_SIM_CHV_NEXT_FREE	 
 } _CiSimChvNo;

typedef UINT8 CiSimChvNo ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMCHVOPER_TAG {	 
 CI_SIM_CHV_VERIFY = 0 , /**< Verify CHV value */	 
 CI_SIM_CHV_CHANGE , /**< Change CHV value */	 
 CI_SIM_CHV_DISABLE , /**< Disable the need for CHV verification , only applied to CHV1 */	 
 CI_SIM_CHV_ENABLE , /**< Enable the need for CHV verification , only applied to CHV1 */	 
 CI_SIM_CHV_UNBLOCK , /**< Unblock CHV */	 
 CI_SIM_CHV_QUERY , /**< Query CHV enable / disable status , only applied to CHV1 */	 
	 
 CI_SIM_CHV_NUM_OPERS	 
 } _CiSimChvOper;

typedef UINT8 CiSimChvOper ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMPERSMEOPER_TAG {	 
 CI_SIM_PERSME_ACTIVATE_PERSONALISATION , /**< Activates MEP. This operation requires the SIM pin state to be CI_SIM_PIN_ST_READY. */	 
 CI_SIM_PERSME_DEACTIVATE_PERSONALISATION , /**< Deactivates MEP. This operation can be done in any SIM pin state and requires an MEP category password. */	 
 CI_SIM_PERSME_DISABLE_PERSONALISATION , /**< Disables MEP. This operation permanently deactivates the requested MEP category and can be done in any SIM pin state. The operation requires an MEP category password. */	 
 CI_SIM_PERSME_READ_PERSONALIZATION_STATUS , /**< Reads MEP status. This operation can be done in any SIM pin state. */	 
 CI_SIM_PERSME_UNBLOCK_PERSONALISATION , /**< Unblocks the SIM. This operation requires an MEP unblocking password. */	 
 CI_SIM_PERSME_NUM_OPERS	 
 } _CiSimPersOper;

typedef UINT8 CiSimPersOper ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMPERSCAT_TAG {	 
 CI_SIM_PERS_CAT_SIM , /**< SIM MEP category */	 
 CI_SIM_PERS_CAT_NETWORK , /**< Network MEP category */	 
 CI_SIM_PERS_CAT_NETWORKSUBSET , /**< Sub network MEP category */	 
 CI_SIM_PERS_CAT_SERVICEPROVIDER , /**< Service provider MEP category */	 
 CI_SIM_PERS_CAT_CORPORATE , /**< Corporate MEP category */	 
 CI_SIM_PERS_CAT_ZTE , /*CQ00108573 , Cgliu , 2017 -12-12*/	 
	 
 CI_SIM_PERS_NUM_CATS	 
 } _CiSimPersCat;

typedef UINT8 CiSimPersCat ;
typedef UINT8 CiSimMEP_BCD ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimMEP_IMSI_Tag 
 {	 
 UINT8 length ; /**< Number of bytes */	 
 UINT8 contents [ 8 ] ; /**< IMSI value represented as an array of bytes ; each byte contains 2 digits */	 
 } CiSimMEP_IMSI;

typedef UINT16 CiSimMEP_MNC ;
typedef UINT16 CiSimMEP_MCC ;
typedef UINT16 CiSimMEP_AccessTechnologyId ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimMEP_PLMN_Tag 
 {	 
 CiSimMEP_MCC mcc ; /**< Mobile country code \sa CiSimMEP_MCC */	 
 CiSimMEP_MNC mnc ; /**< Mobile network code \sa CiSimMEP_MNC */	 
 CiSimMEP_AccessTechnologyId accessTechnology ; /**< Access technology \sa CiSimMEP_AccessTechnologyId */	 
 } CiSimMEP_PLMN;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimMEPCodeType_PLMN_Tag 
 {	 
 CiSimMEP_PLMN plmn ; /**< PLMN \sa CiSimMEP_PLMN_Tag */	 
 CiBoolean mncThreeDigitsDecoding ; /**< If TRUE indicates 3 digit coding is used else 4 digit coding is used \sa CCI API Ref Manual */	 
 } CiSimMEPCodeType_PLMN;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimMEPCodeType_NS_Tag 
 {	 
 CiSimMEP_BCD networkSubsetId ; /**< Bits 0 -3 = IMSI digit 6 , Bits 4 -7 = IMSI digit 7 . \sa CiSimMEP_BCD */	 
 } CiSimMEPCodeType_NS;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimMEPCodeType_SP_Tag 
 {	 
 UINT8 serviceproviderId ; /**< Service provider ID */	 
 } CiSimMEPCodeType_SP;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimMEPCodeType_CP_Tag 
 {	 
 UINT8 corporateId ; /**< Corporate ID */	 
 } CiSimMEPCodeType_CP;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimMEPCodeType_SIMUSIM_Tag 
 {	 
 CiSimMEP_IMSI simId ; /**< IMSI \sa CiSimMEP_IMSI_Tag */	 
 } CiSimMEPCodeType_SIMUSIM;

//ICAT EXPORTED UNION 
 typedef union CiSimMEPCodeType_Tag 
 {	 
 CiSimMEPCodeType_PLMN Network ; /**< Network code - PLMN \sa CiSimMEPCodeType_PLMN_Tag */	 
 CiSimMEPCodeType_NS NetworkSubset ; /**< Network subset code - IMSI bits 6 and 7 \sa CiSimMEPCodeType_NS_Tag */	 
 CiSimMEPCodeType_SP SP ; /**< Service provider code \sa CiSimMEPCodeType_SP_Tag */	 
 CiSimMEPCodeType_CP Corporate ; /**< Corporate code \sa CiSimMEPCodeType_CP_Tag */	 
 CiSimMEPCodeType_SIMUSIM SimUsim ; /**< SIM / USIM code - IMSI \sa CiSimMEPCodeType_SIMUSIM_Tag */	 
 } CiSimMEPCodeType;

//ICAT EXPORTED ENUM 
 typedef enum CISIMUDPOPER {	 
 CI_SIM_UDP_OPER_ACTIVATE_PERSONALISATION , /**< Activate */	 
 CI_SIM_UDP_OPER_DEACTIVATE_PERSONALISATION , /**< Deactivate - this operation requires a password */	 
 CI_SIM_UDP_READ_PERSONALIZATION_STATUS , /**< Read UDP lock status */	 
 CI_SIM_UDP_OPER_NUM	 
 } _CiSimUDPOper;

typedef UINT8 CiSimUDPOper ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMUDPCAT {	 
 CI_SIM_UDP_CAT_UNAUTHERIZED_SIM_DETECTION , /**< Unauthorized SIM detection - SIM is unauthorized if its ICCID does not match any of the values stored in the authorized SIM list */	 
 CI_SIM_UDP_CAT_INVALID_SIM_DETECTION , /**< Invalid SIM detection - SIM is invalid if it is rejected by the network */	 
 CI_SIM_UDP_CAT_NUM	 
 } _CiSimUDPCat;

typedef UINT8 CiSimUDPCat ;
//ICAT EXPORTED ENUM 
 typedef enum CiSIMUDPSTATUS_TAG {	 
 CI_SIM_UDP_UNKNOWN , /**< Data based was not read */	 
 CI_SIM_UDP_INACTIVE , /**< UDP lock is not active */	 
 CI_SIM_UDP_ACTIVE , /**< UDP lock is active */	 
 CI_SIM_UDP_IS_NOT_SUPPORTED , /**< UDP lock feature is not supported */	 
 CI_SIM_UDP_STATUS_NUM	 
 } _CiSimUDPStatus;

typedef UINT8 CiSimUDPStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimIccid_Tag 
 {	 
 UINT8 data [ 10 ] ;	 
 } CiSimIccid;

//ICAT EXPORTED ENUM 
 typedef enum CiSIMUDPASLOPER_Tag {	 
 CI_SIM_UDP_ASL_ADD_CURRENT_SIM , /**< Add ICCID of current SIM to authorized SIM list */	 
 CI_SIM_UDP_ASL_DELETE , /**< Delete specified ICCID from authorized SIM list */	 
 CI_SIM_UDP_ASL_DELETE_ALL , /**< Delete all values from authorized SIM list */	 
 CI_SIM_UDP_ASL_READ_ALL , /**< Read authorized SIM list */	 
 CI_SIM_UDP_ASL_OPER_NUM	 
 } _CiSimUDPASLOper;

typedef UINT8 CiSimUDPASLOper ;
//ICAT EXPORTED STRUCT 
 typedef struct CiRtcDate_Tag 
 {	 
 UINT16 year ; /**< RTC year */	 
 UINT8 month ; /**< RTC month ( 1 -12 ) */	 
 UINT8 day ; /**< RTC day of month ( 1 -31 ) */	 
 } CiRtcDate;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimUDPASLEntry_Tag 
 {	 
 CiSimIccid iccid ; /**< \sa CiSimIccid_Tag */	 
 CiRtcDate updateTime ; /**< \sa CiRtcDate_Tag */	 
 } CiSimUDPASLEntry;

//ICAT EXPORTED ENUM 
 typedef enum CISIMPERSSTATUS_TAG {	 
 CI_SIM_MEP_ACTIVATED , /**< Activated */	 
 CI_SIM_MEP_DEACTIVATED , /**< Deactivated */	 
 CI_SIM_MEP_DISABLED , /**< Disabled - permanently deactivated */	 
 CI_SIM_MEP_BLOCKED , /**< Blocked */	 
 CI_SIM_MEP_UNKNOWN , /**< Unknown - database not read or corrupted */	 
 CI_SIM_PERS_ST_IS_NOT_SUPPORTED , /**< Personalization not supported */	 
	 
 CI_SIM_PERS_NUM_STATUSES	 
 } _CiSimPersStatus;

typedef UINT8 CiSimPersStatus ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimTermProfile_Struct {	 
 UINT8 len ; /**< Length of the terminal profile [ 1 - CI_SIM_MAX_ME_PROFILE_SIZE ] */	 
 UINT8 data [ 64 ] ; /**< Terminal profile data.	 
 * Content conforms to 3 GPP TS 11.140000 , v3.10.0 , 5.200000 ; if empty , communication	 
 * subsystem assumes ME doesn ' t support SIMAT. */	 
 } CiSimTermProfile;

//ICAT EXPORTED ENUM 
 typedef enum CISIMFACLCKMODE_TAG {	 
 CI_SIM_FACLCK_MODE_UNLOCK = 0 , /**< Unlock */	 
 CI_SIM_FACLCK_MODE_LOCK , /**< Lock */	 
 CI_SIM_FACLCK_MODE_QUERY , /**< Query */	 
	 
 CI_SIM_FACLCK_NUM_MODES	 
 } _CiSimFacLckMode;

typedef UINT8 CiSimFacLckMode ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMFACCODE_TAG {	 
 CI_SIM_FAC_CODE_SIM = 0 , /**< Locks SIM , needs to be unlocked with CHV1 */	 
 CI_SIM_FAC_CODE_FDN , /**< Enables FDN feature , needs CHV2 verification ,	 
 * refer to 3 GPP 11.110000 and 3 GPP 11.140000 */	 
	 
 /* The following facility codes are related to personalization. Refer to 3 GPP TS 22.022000 */	 
 CI_SIM_FAC_CODE_PERS_FSIM , /**< SIM personalization , lock phone with the first inserted SIM. Not supported */	 
	 
 CI_SIM_FAC_CODE_P2 , /* Add by jungle for CQ00055548 on 2014 -03-04 */	 
	 
 CI_SIM_FAC_NUM_CODES	 
 } _CiSimFacCode;

typedef UINT8 CiSimFacCode ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMFACSTATUS_TAG {	 
 CI_SIM_FACLCK_ST_DEACTIVE = 0 , /**< Not active */	 
 CI_SIM_FACLCK_ST_ACTIVE , /**< Active */	 
	 
 CI_SIM_FACLCK_NUM_STS	 
 } _CiSimFacStatus;

typedef UINT8 CiSimFacStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMATNOTIFYSUPPORT_TAG {	 
 CI_SIMATNOT_NOT_IMPLEMENTED = 0 , /**< Not implemented */	 
 CI_SIMATNOT_APP_IMPLEMENTS , /**< Implemented in the application */	 
 CI_SIMATNOT_SIMAT_IMPLEMENTS_NO_NOTIFY , /**< Implemented in the communication subsystem without notifying the application */	 
 CI_SIMATNOT_SIMAT_IMPLEMENTS_NOTIFY , /**< Implemented in the communication subsystem and the application is notified */	 
 CI_SIMATNOT_SIMAT_IMPLEMENTS_WITH_APP_INPUT , /**< Implemented in the communication subsystem but requires input from the application */	 
	 
 CI_NUM_SIMATNOT_SUPPORT_OPTIONS	 
 } _CiSimatNotifySupport;

typedef UINT8 CiSimatNotifySupport ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimatNotifyCap_struct {	 
 CiSimatNotifySupport capDisplayText ; /**< DISPLAY TEXT , which displays text or an icon on the screen. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capGetInkey ; /**< GET INKEY , which sends text or an icon to the display and requests a single character response in return. It is intended to allow a dialog between the SIM and the user , particularly for selecting an option from a menu. \sa CiSimatNotifySupport*/	 
 CiSimatNotifySupport capGetInput ; /**< GET INPUT , which sends text or an icon to the display and requests a response in return. It is intended to allow a dialog between the SIM and the user. \sa CiSimatNotifySupport*/	 
 CiSimatNotifySupport capMoreTime ; /**< MORE TIME , which does not request any action from the ME. The ME is required to respond with TERMINAL RESPONSE ( OK ) as normal. The purpose of the MORE TIME command is to provide a mechanism for the SIM Application Toolkit task in the SIM to request more processing time. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capPlayTone ; /**< PLAY TONE , which requests the ME to play a tone in its earpiece , ringer , or other appropriate loudspeaker. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capPollInterval ; /**< POLL INTERVAL , which negotiates how often the ME sends STATUS commands to the SIM during idle mode. Polling is disabled with POLLING OFF. Use of STATUS for the proactive SIM is described in TS 11.110000 . \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capRefresh ; /**< REFRESH , which requests the ME to carry out a SIM initialization according to TS 11.110000 subclause 12.200000 .1 , and / or advises the ME that the contents or structure of EFs on the SIM have been changed. The command also makes it possible to restart a card session by resetting the SIM. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capSetupMenu ; /**< SETUP MENU: The SIM shall supply a set of menu items , which shall be integrated with the menu system ( or other MMI facility ) to give the user the opportunity to choose one of these menu items at his own discretion. Each item comprises a short identifier ( used to indicate the selection ) , a text string , and optionally an icon identifier , contained in an item icon identifier list data object located at the end of the list of items. \sa CiSimatNotifySupport*/	 
 CiSimatNotifySupport capSelectItem ; /**< SELECT ITEM , where the SIM supplies a list of items , and the user is expected to choose one. The ME presents the list in an implementation-dependent way. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capSendSMS ; /**< SEND DATA , which requests the ME to send data on the specified channel provided by the SIM ( if class " e " is supported ) . \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capSendSS ; /**< SEND SS , which sends an SS request to the network. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capSendUSSD ; /**< SEND USSD , which sends a USSD string to the network. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capSetupCall ; /**< SET UP CALL , of which there are three types:	 
 * set up a call , but only if not currently busy on another call ;	 
 * set up a call , putting all other calls ( if any ) on hold ;	 
 * set up a call , disconnecting all other calls ( if any ) \sa CiSimatNotifySupport*/	 
 CiSimatNotifySupport capPollingOff ; /**< POLLING OFF - This command disables the Proactive Polling ( defined in TS 11.110000 [ 20 ] ) . SIM Presence Detection ( defined in TS 11.110000 [ 20 ] ) is not affected by this command. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capSetupIdleModeText ; /**< SETUP IDLE MODE TEXT \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capProvideLocalInfo ; /**< Provide local information -	 
 * This command requests the ME to send current local information to the SIM.	 
 * At present , this information is restricted to	 
 * location information ( the mobile country code ( MCC ) , mobile network code ( MNC ) , location area code ( LAC ) and cell ID of the current serving cell ) ;	 
 * the IMEI of the ME ;	 
 * the network measurement results and the BCCH channel list ;	 
 * the current date , time and time zone ;	 
 * the current ME language setting ;	 
 * the timing advance \sa CiSimatNotifySupport*/	 
 CiSimatNotifySupport capSetupEventList ; /**< SET UP EVENT LIST - The SIM shall use this command to supply a set of events. This set of events shall become the current list of events that the ME is to monitor. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capLaunchBrowser ; /**< LAUNCH BROWSER , which requests a browser inside a browser enabled ME to interpret the content corresponding to a URL. \sa CiSimatNotifySupport */	 
	 
 /*Mason BIP support - START*/	 
 CiSimatNotifySupport capOpenChannel ; /**< OPEN CHANNEL realted to GPRS. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capCloseChannel ; /**< CLOSE CHANNEL. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capReceiveData ; /**< RECEIVE DATA. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capSendData ; /**< SEND DATA. \sa CiSimatNotifySupport */	 
 CiSimatNotifySupport capGetChannelStatus ; /**< GET CHANNEL STATUS. \sa CiSimatNotifySupport */	 
 /*Mason BIP support - END*/	 
 } CiSimatNotifyCap;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimatAlphaTag_struct {	 
 UINT16 len ; /**< Length */	 
 UINT8 tag [ 241 ] ; /**< Tag data */	 
 } CiSimatAlphaTag;

//ICAT EXPORTED ENUM 
 typedef enum CI_SIM_MSGWAITING_FLAGS_TAG 
 {	 
 CI_SIM_MSG_WAITING_VOICE = 0x01 , /**< Voice mail messages waiting */	 
 CI_SIM_MSG_WAITING_FAX = 0x02 , /**< Fax messages waiting */	 
 CI_SIM_MSG_WAITING_EMAIL = 0x04 , /**< Email messages waiting */	 
 CI_SIM_MSG_WAITING_OTHER = 0x08 /**< Other messages waiting */	 
 } _CiSimMsgWaitingFlags;

typedef UINT8 CiSimMsgWaitingFlags ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimMsgWaitingInfo_struct 
 {	 
 UINT8 flags ; /**< Bit mask indicating message waiting status. A set bit indicates there is a message waiting in the specified group. Bit 0 - Voice mail ; Bit 1 - Fax ; Bit 2 - Email ; Bit 3 - other */	 
 /*If " flags " == TRUE : next values contains message numbers ( for MWIS file )	 
 If FALSE: Next value are only flags: 0 - No Msg , Else Msg Exist ( for VMWF file ) */	 
 UINT8 numVoice ; /**< Number of voice mail messages waiting */	 
 UINT8 numFax ; /**< Number of fax messages waiting */	 
 UINT8 numEmail ; /**< Number of email messages waiting */	 
 UINT8 numOther ; /**< Number of other messages waiting */	 
 } CiSimMsgWaitingInfo;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimServiceTable_struct 
 {	 
 UINT8 size ; /**< Actual number of bytes used in services [ ] array */	 
 UINT8 services [ ( ( 56 + 7 ) / 8 ) ] ; /**< SIM service table */	 
 } CiSimServiceTable;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimCustServiceProfile_struct 
 {	 
 UINT8 cspCallOffering ; /**< Bitmap: Call offering services */	 
 UINT8 cspCallRestriction ; /**< Bitmap: Call restriction services */	 
 UINT8 cspOtherSuppServices ; /**< Bitmap: Other supplementary services */	 
 UINT8 cspCallCompletion ; /**< Bitmap: Call completion services */	 
 UINT8 cspTeleServices ; /**< Bitmap: Teleservices */	 
 UINT8 cspCphsTeleServices ; /**< Bitmap: CPHS teleservices */	 
 UINT8 cspCphsFeatures ; /**< Bitmap: CPHS features */	 
 UINT8 cspNumberIdent ; /**< Bitmap: Number identification services */	 
 UINT8 cspPhase2PlusServices ; /**< Bitmap: Phase 2 + services */	 
 UINT8 cspValueAddedServices ; /**< Bitmap: Value added services */	 
 UINT8 cspInformationNumbers ; /**< Bitmap: CPHS information numbers */	 
 } CiSimCustServiceProfile;

//ICAT EXPORTED ENUM 
 typedef enum CISIMATDISPLAYCMDTYPE_TAG {	 
 CI_SIMAT_DISPLAYCMD_SMS = 0 , /**< SMS */	 
 CI_SIMAT_DISPLAYCMD_USSD , /**< USSD */	 
 CI_SIMAT_DISPLAYCMD_SS , /**< SS */	 
 CI_SIMAT_DISPLAYCMD_SD , /**< SEND DTMF */	 
 CI_NUM_SIMAT_NUM_DISPLAYCMD_TYPES	 
 } _CiSimatDisplayCmdType;

typedef UINT8 CiSimatDisplayCmdType ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMATICONDISPLAY_TAG {	 
 CI_SIMAT_DISPLAY_ICONID_ONLY = 0 , /**< Display only icons */	 
 CI_SIMAT_DISPLAY_ICONID_WITH_ALPHAID , /**< Display icons and text */	 
 CI_NUM_SIMAT_NUM_DISPLAY_ICON_TYPES	 
 } _CiSimatIconDisplay;

typedef UINT8 CiSimatIconDisplay ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimatIconTag_struct {	 
 CiSimatIconDisplay display ; /**< Icon display \sa CiSimatIconDisplay */	 
 UINT8 tag ; /**< Icon tag data */	 
 } CiSimatIconTag;

//ICAT EXPORTED ENUM 
 typedef enum CISIMGENERICCMDTYPE_TAG 
 {	 
 CI_SIM_SELECT = 0xa4 ,	 
 CI_SIM_STATUS = 0xf2 ,	 
	 
 CI_SIM_READ_BINARY = 0xb0 ,	 
 CI_SIM_UPDATE_BINARY = 0xd6 ,	 
 CI_SIM_READ_RECORD = 0xb2 ,	 
 CI_SIM_UPDATE_RECORD = 0xdc ,	 
	 
 CI_SIM_SEARCH_RECORD = 0xa2 , /**< Named as in ETSI TS 102.221000 sec 10.100000 .2 */	 
 CI_SIM_SEEK = 0xa2 , /**< Named as in 3 gpp TS 11.110000 sec 9.200000 */	 
 CI_SIM_INCREASE = 0x32 ,	 
	 
 CI_SIM_VERIFY = 0x20 , /**< Named as in ETSI TS 102.221000 sec 10.100000 .2 */	 
 CI_SIM_VERIFY_CHV = 0x20 , /**< Named as in 3 gpp TS 11.110000 sec 9.200000 */	 
	 
 CI_SIM_CHANGE_PIN = 0x24 , /**< Named as in ETSI TS 102.221000 sec 10.100000 .2 */	 
 CI_SIM_CHANGE_CHV = 0x24 , /**< Named as in 3 gpp TS 11.110000 sec 9.200000 */	 
	 
 CI_SIM_DISABLE_PIN = 0x26 , /**< Named as in ETSI TS 102.221000 sec 10.100000 .2 */	 
 CI_SIM_DISABLE_CHV = 0x26 , /**< Named as in 3 gpp TS 11.110000 sec 9.200000 */	 
	 
 CI_SIM_ENABLE_PIN = 0x28 , /**< Named as in ETSI TS 102.221000 sec 10.100000 .2 */	 
 CI_SIM_ENABLE_CHV = 0x28 , /**< Named as in 3 gpp TS 11.110000 sec 9.200000 */	 
	 
 CI_SIM_UNBLOCK_PIN = 0x2c , /**< Named as in ETSI TS 102.221000 sec 10.100000 .2 */	 
 CI_SIM_UNBLOCK_CHV = 0x2c , /**< Named as in 3 gpp TS 11.110000 sec 9.200000 */	 
	 
 CI_SIM_DEACTIVATE_FILE = 0x04 , /**< Named as in ETSI TS 102.221000 sec 10.100000 .2 */	 
 CI_SIM_INVALIDATE = 0x04 , /**< Named as in 3 gpp TS 11.110000 sec 9.200000 */	 
	 
 CI_SIM_ACTIVATE_FILE = 0x44 , /**< Named as in ETSI TS 102.221000 sec 10.100000 .2 */	 
 CI_SIM_REHABILITATE = 0x44 , /**< Named as in 3 gpp TS 11.110000 sec 9.200000 */	 
	 
 CI_SIM_AUTHENTICATE = 0x88 , /**< Named as in ETSI TS 102.221000 sec 10.100000 .2 */	 
 CI_SIM_RUN_GSM_ALGORITHM = 0x88 , /**< Named as in 3 gpp TS 11.110000 sec 9.200000 */	 
	 
 CI_SIM_SLEEP = 0xfa , /**< Only defined in 3 gpp TS 11.110000 sec 9.200000 */	 
 CI_SIM_GET_RESPONSE = 0xc0 , /**< Only defined in 3 gpp TS 11.110000 sec 9.200000 */	 
	 
 CI_SIM_TERMINAL_PROFILE = 0x10 ,	 
 CI_SIM_ENVELOPE = 0xC2 ,	 
 CI_SIM_FETCH = 0x12 ,	 
 CI_SIM_TERMINAL_RESPONSE = 0x14 ,	 
	 
 CI_SIM_MANAGE_CHANNEL = 0x70 , /**< Only defined in ETSI TS 102.221000 */	 
	 
 /* this should always be the last entry */	 
 CI_SIM_INVALID_CMD = 0x00	 
	 
 } _CiSimGenericCmdType;

typedef UINT8 CiSimGenericCmdType ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMGENERICRWMODETYPE_TAG 
 {	 
 CI_SIM_NEXT_REC = 0x02 ,	 
 CI_SIM_PREVIOUS_REC = 0x03 ,	 
 CI_SIM_CURRENT_ABSOLUTE = 0x04	 
 } _CiSimGenericRwModeType;

typedef UINT8 CiSimGenericRwModeType ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMGENERICSELECTMODETYPE_TAG 
 {	 
 CI_SIM_SELECT_BY_FILE_ID = 0x00 ,	 
 CI_SIM_SELECT_CHILD_DF = 0x01 ,	 
 CI_SIM_SELECT_PARENT_DF = 0x03 ,	 
 CI_SIM_SELECT_BY_DF_NAME = 0x04 ,	 
 CI_SIM_SELECT_BY_PATH_FROM_MF = 0x08 ,	 
 CI_SIM_SELECT_BY_PATH_FROM_DF = 0x09	 
	 
 } _CiSimGenericSelectModeType;

typedef UINT8 CiSimGenericSelectModeType ;
typedef CiString CiSimFilePath ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMGENERICRESPONSETYPE_TAG 
 {	 
 CI_SIM_RETURN_FCP = 0x04 ,	 
 CI_SIM_RETURN_NO_DATA = 0x0C	 
	 
 /* NOTE: more to be defined as needed */	 
 } _CiSimGenericResponseType;

typedef UINT8 CiSimGenericResponseType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimExecCmdReq_struct {	 
 /*Michal Bukai - SIM Logic CH - NFC\ISIM support*/	 
 UINT16 SessionId ; /**< A session Id to be used in order to target a specific application on the smart card using logical channel mechanism. */	 
 CiSimCmdReq cmd ; /**< SIM Command. \sa CiSimCmdReq_Struct */	 
 } CiSimPrimExecCmdReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimExecCmdCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiSimCmdRsp cnf ; /**< Confirmation of last SIM command request ; if rc is CI_SIM_CMDREQ_FAILURE , this field is optional. \sa CiSimCmdRsp */	 
 /*Michal Bukai - SIM Logic CH - NFC\ISIM support*/	 
 UINT16 SessionId ; /**< A session Id to be used in order to target a specific application on the smart card using logical channel mechanism. */	 
 } CiSimPrimExecCmdCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimExecLargeCmdCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiSimLargeCmdRsp cnf ; /**< Confirmation of last SIM command request ; if rc is CI_SIM_CMDREQ_FAILURE , this field is optional. \sa CiSimCmdRsp */	 
 UINT16 SessionId ; /**< A session Id to be used in order to target a specific application on the smart card using logical channel mechanism. */	 
 } CiSimPrimExecLargeCmdCnf;

//ICAT EXPORTED ENUM 
 typedef enum CI_SIM_CLOCK_STOP_LEVEL_TAG {	 
 CI_SIM_CLOCK_STOP_NONE = 0 , /**< Clock Stop No Level Preferred */	 
 CI_SIM_CLOCK_STOP_LOW , /**< Clock Stop Low Level Preferred */	 
 CI_SIM_CLOCK_STOP_HIGH , /**< Clock Stop High Level Preferred */	 
 CI_SIM_CLOCK_STOP_NUM	 
 } _CiSimClockStopLevel;

typedef UINT8 CiSimClockStopLevel ;
//ICAT EXPORTED ENUM 
 typedef enum CI_SIM_ECALL_SUPPORT_TYPE_TAG {	 
 CI_SIM_ECALL_NONE = 0 ,	 
 CI_SIM_ECALL_SUPPORTED ,	 
 CI_SIM_ECALL_ONLY ,	 
 CI_SIM_ECALL_NUM	 
 } _CiSimEcallSuppurtType;

typedef UINT8 CiSimEcallSuppurtType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimDeviceInd_struct {	 
 CiSimStatus status ; /**< SIM Status.\sa CiSimStatus */	 
 CiSimPinState pinState ; /**< PIN state when SIM becomes ready , ignored if status is NOT CI_SIM_ST_ READY. \sa CiSimPinState */	 
 /*Michal Bukai - OTA support for AT&T*/	 
 CiBoolean ProactiveSessionStatus ; /**< Indicates if in proactive session or not. \sa CCI API Ref Manual */	 
 /*merged by cherryli@04.26.2016 CQ105208 begin.*/	 
 CiBoolean EcallData ; /**< TRUE if service 48 is enabled on SIM and this SIM support eCall \sa */	 
 CiBoolean EcallOnlyMode ; /**< TRUE if the SIM works in eCall only mode \sa */	 
 /*merged by cherryli@04.26.2016 CQ105208 end.*/	 
 } CiSimPrimDeviceInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimPersonalizeMEReq_struct {	 
 CiSimPersOper oper ; /**< Operation on ME personalization \sa CiSimPersOper */	 
 CiSimPersCat cat ; /**< Personalization category \sa CiSimPersCat */	 
 CiMepPassword pass ; /**< this field is optional if oper is CI_SIM_PERS_OPER_DISABLE or CI_SIM_PERS_OPER_QUERY. \sa CCI API Ref Manual */	 
 } CiSimPrimPersonalizeMEReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimPersonalizeMECnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiSimPersStatus status ; /**< Personalization indicator status \sa CiSimPersStatus */	 
 } CiSimPrimPersonalizeMECnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimReadMEPCodesReq_struct {	 
 CiSimPersCat MEPCategory ; /**< Personalization category \sa CiSimPersCat */	 
 } CiSimPrimReadMEPCodesReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimReadMEPCodesCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa _CiSimRc */	 
 CiSimPersCat MEPCategory ; /**< Personalization category \sa CiSimPersCat */	 
 UINT8 NumberOfcodes ; /**< Number of codes stored in ME */	 
 CiSimMEPCodeType Codes [ 100 ] ; /**< MEP personalization codes \sa CiSimMEPCodeType_Tag */	 
 } CiSimPrimReadMEPCodesCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimUDPLockReq_struct {	 
 CiSimUDPOper oper ; /**< Operation on UDP lock \sa CiSimUDPOper */	 
 CiSimUDPCat UDPCategory ; /**< UDP category \sa CiSimUDPCat */	 
 CiPassword Pass ; /**< This is the password required to deactivate the UDP lock. This field is optional in activate or read status operations. \sa CCI API Ref Manual */	 
 } CiSimPrimUDPLockReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimUDPLockCnf_struct {	 
 CiSimRc rc ; /**< Result code. Note that the following values are not valid for UDP: CIR_SIM_ PERSONALISATION_DISABLED and CIRC_SIM_ PERSONALISATION_BLOCKED. \sa _CiSimRc */	 
 CiSimUDPStatus status ; /**< UDP lock status \sa CiSimUDPStatus */	 
 } CiSimPrimUDPLockCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimUDPChangePasswordReq_struct {	 
 CiPassword oldPassword ; /**< This is the current password required to unlock the UE. \sa CCI API Ref Manual */	 
 CiPassword newPassword ; /**< This is the new password. \sa CCI API Ref Manual */	 
 } CiSimPrimUDPChangePasswordReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimUDPChangePasswordCnf_struct {	 
 CiSimRc rc ; /**< Result code. Note that the following values are not valid for UDP: CIRC_SIM_ PERSONALISATION_DISABLED and CIRC_SIM_ PERSONALISATION_BLOCKED. \sa _CiSimRc */	 
 } CiSimPrimUDPChangePasswordCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimUDPASLReq_struct {	 
 CiSimUDPASLOper Oper ; /**< Operation that should be performed on ASL \sa CiSimUDPASLOper */	 
 CiSimIccid Iccid ; /**< Required only for delete operation \sa CiSimIccid_Tag */	 
 } CiSimPrimUDPASLReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimUDPASLCnf_struct {	 
 CiSimRc rc ; /**< Result code. Note that the following values are not valid for UDP: CIRC_SIM_ PERSONALISATION_DISABLED and CIRC_SIM_ PERSONALISATION_BLOCKED. \sa _CiSimRc */	 
 UINT8 num ; /**< Number of entries in ASL. Valid if operation was READ_ALL. 0 means there are no entries in ASL [ range: 0 - max number of ASL elements ] . */	 
 CiSimUDPASLEntry TypeAutherizedSIMlist [ 10 ] ; /**< Valid if operation was READ_ALL. Reports the ICCID of all SIMs in the authorized list and the date they were added. \sa CiSimUDPASLEntry_Tag */	 
 } CiSimPrimUDPASLCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimOperChvReq_struct {	 
 CiSimChvOper oper ; /**< \sa CiSimChvOper */	 
 CiSimChvNo chvNo ; /**< \sa CiSimChvNo */	 
 CiPassword chvVal ; /**< \sa CCI API Ref Manual */	 
 CiPassword newChvVal ; /**< \sa CCI API Ref Manual */	 
 } CiSimPrimOperChvReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimOperChvCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiBoolean enabled ; /**< Not optional if operation is CI_SIM_CHV_QUERY. TRUE: CHV1 is enabled ; FALSE: CHV1 is disabled. \sa CCI API Ref Manual */	 
 } CiSimPrimOperChvCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimDownloadProfileReq_struct {	 
 CiSimTermProfile profile ; /**< Terminal profile structure \sa CiSimTermProfile_Struct */	 
 } CiSimPrimDownloadProfileReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimDownloadProfileCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 } CiSimPrimDownloadProfileCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimEndAtSessionInd_struct {	 
 UINT8 fetchSize ;	 
 } CiSimPrimEndAtSessionInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimProactiveCmdInd_struct {	 
 UINT16 len ; /**< Length of the proactive command data [ 1 -255 ] */	 
 UINT8 data [ 261 ] ; /**< Proactive command data */	 
 } CiSimPrimProactiveCmdInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimProactiveCmdRsp_struct {	 
 UINT16 len ; /**< Length of the terminal response command data [ 1 -255 ] */	 
 UINT8 data [ 261 ] ; /**< Terminal response command data */	 
 } CiSimPrimProactiveCmdRsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimEnvelopeCmdReq_struct {	 
 UINT16 len ; /**< Length of the envelope command data [ 1 -255 ] */	 
 UINT8 data [ 261 ] ; /**< Envelope command data */	 
 } CiSimPrimEnvelopeCmdReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimEnvelopeCmdCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiSimCmdRsp cnf ; /**< Confirmation to an ENVELOPE command request ; if rc is CI_SIM_CMDREQ_FAILURE , this field is optional. \sa CiSimCmdRsp_Struct */	 
 } CiSimPrimEnvelopeCmdCnf;

typedef CiEmptyPrim CiSimPrimGetSubscriberIdReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetSubscriberIdCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiString subscriberStr ; /**< Subscriber ID string \sa CCI API Ref Manual */	 
 } CiSimPrimGetSubscriberIdCnf;

typedef CiEmptyPrim CiSimPrimGetPinStateReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetPinStateCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiSimPinState state ; /**< Current PIN state \sa CiSimPinState */	 
 UINT8 chv1NumRetrys ; /**< Pin1 status - number of remaining retries */	 
 UINT8 chv2NumRetrys ; /**< Pin2 status - number of remaining retries */	 
 UINT8 puk1NumRetrys ; /**< Unblock pin1 status - number of remaining retries */	 
 UINT8 puk2NumRetrys ; /**< Unblock pin2 status - number of remaining retries */	 
 UINT8 MEPSimNumRetrys ; /**< SIM MEP category - number of remaining retries */	 
 UINT8 MEPNwNumRetrys ; /**< Network MEP category - number of remaining retries */	 
 UINT8 MEPNwsubNumRetrys ; /**< Sub Network MEP category - number of remaining retries */	 
 UINT8 MEPSPNumRetrys ; /**< Service provider MEP category - number of remaining retries */	 
 UINT8 MEPCorpNumRetrys ; /**< Corporate MEP category - number of remaining retries */	 
	 
 } CiSimPrimGetPinStateCnf;

typedef CiEmptyPrim CiSimPrimGetTerminalProfileReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetTerminalProfileCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiSimTermProfile profile ; /**< The terminal profile structure ; optional if rc is not CIRC_SIM_OK. \sa CiSimTermProfile_Struct */	 
 } CiSimPrimGetTerminalProfileCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimEnableSimatIndsReq_struct {	 
 CiBoolean enable ; /**< TRUE: enable the indication report ; FALSE: disable the indication report , default \sa CCI API Ref Manual */	 
 } CiSimPrimEnableSimatIndsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimEnableSimatIndsCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 } CiSimPrimEnableSimatIndsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimLockFacilityReq_struct {	 
 CiSimFacLckMode mode ; /**< Facility setting mode \sa CiSimFacLckMode */	 
 CiSimFacCode fac ; /**< Facility code \sa CiSimFacCode */	 
 CiPassword pass ; /**< Password , optional if mode is CI_SIM_FACLCK_MODE_QUERY \sa CCI API Ref Manual */	 
 } CiSimPrimLockFacilityReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimLockFacilityCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiSimFacStatus status ; /**< Optional if rc is not CIRC_SIM_OK \sa CiSimFacStatus */	 
 } CiSimPrimLockFacilityCnf;

typedef CiEmptyPrim CiSimPrimGetFacilityCapReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetFacilityCapCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiBitRange bitsFac ; /**< Optional if rc is not CIRC_SIM_OK \sa CCI API Ref Manual */	 
 } CiSimPrimGetFacilityCapCnf;

typedef CiEmptyPrim CiSimPrimGetSimatNotifyCapReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetSimatNotifyCapCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiSimatNotifyCap caps ; /**< SIMAT notification capability information \sa CiSimatNotifyCap_struct */	 
 } CiSimPrimGetSimatNotifyCapCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetCallSetupAckInd_struct {	 
 CiBoolean alphaIdPresent ; /**< Indicates whether the CALL SETUP has an accompanying alphanumeric ID string \sa CCI API Ref Manual */	 
 CiSimatAlphaTag alphaId ; /**< Optional alphanumeric ID \sa CiSimatAlphaTag_struct */	 
 } CiSimPrimGetCallSetupAckInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetCallSetupAckRsp_struct {	 
 CiBoolean accept ; /**< CALL SETUP response \sa CCI API Ref Manual */	 
 } CiSimPrimGetCallSetupAckRsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetServiceProviderNameReq_struct {	 
 UINT8 type ; /**< SPN type: 0 -GSM_SPN , 1 -USIM_SPN. \sa CCI API Ref Manual */	 
 } CiSimPrimGetServiceProviderNameReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetServiceProviderNameCnf_struct 
 {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 UINT8 dispRplmn ; /**< Display RPLMN: 0 -no display , 1 -display , 99 -invalid. \sa CCI API Ref Manual */	 
 CiNameInfo spName ; /**< Service provider name ; NULL pointer if name is not available \sa CCI API Ref Manual */	 
 } CiSimPrimGetServiceProviderNameCnf;

typedef CiEmptyPrim CiSimPrimGetMessageWaitingInfoReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetMessageWaitingInfoCnf_struct 
 {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiSimMsgWaitingInfo info ; /**< Message waiting information \sa CiSimMsgWaitingInfo_struct */	 
 } CiSimPrimGetMessageWaitingInfoCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSetMessageWaitingInfoReq_struct 
 {	 
 CiSimMsgWaitingInfo info ; /**< Message waiting information \sa CiSimMsgWaitingInfo_struct */	 
 } CiSimPrimSetMessageWaitingInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSetMessageWaitingInfoCnf_struct 
 {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 } CiSimPrimSetMessageWaitingInfoCnf;

typedef CiEmptyPrim CiSimPrimGetSimServiceTableReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetSimServiceTableCnf_struct 
 {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiBoolean sstPresent ; /**< Indicates whether SIM Service Table is present \sa CCI API Ref Manual */	 
 CiSimServiceTable sst ; /**< SIM Service Table ( if available ) \sa CiSimServiceTable_struct */	 
 } CiSimPrimGetSimServiceTableCnf;

typedef CiEmptyPrim CiSimPrimGetCustomerServiceProfileReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetCustomerServiceProfileCnf_struct 
 {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc. */	 
 CiBoolean cspPresent ; /**< Indicates whether Customer Service Profile is present \sa CCI API Ref Manual */	 
 CiSimCustServiceProfile csp ; /**< Customer Service Profile ( if available ) \sa CiSimCustServiceProfile_struct */	 
 } CiSimPrimGetCustomerServiceProfileCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSimatDisplayInfoInd_struct {	 
 CiSimatDisplayCmdType type ; /**< Type of SIMAT proactive command that triggered the display info indication \sa CiSimatDisplayCmdType */	 
 CiBoolean alphaIdPresent ; /**< Indicates whether alpha identifier is present \sa CCI API Ref Manual */	 
 CiBoolean iconIdPresent ; /**< Indicates whether icon identifier is present \sa CCI API Ref Manual */	 
 CiSimatAlphaTag alphaId ; /**< Alpha ID ( if available ) \sa CiSimatAlphaTag_struct */	 
 CiSimatIconTag iconId ; /**< Icon ID ( if available ) \sa CiSimatIconTag_struct */	 
 } CiSimPrimSimatDisplayInfoInd;

typedef CiEmptyPrim CiSimPrimGetDefaultLanguageReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetDefaultLanguageCnf_struct 
 {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 UINT16 language ; /**< One byte for each alphanumeric character */	 
	 
 } CiSimPrimGetDefaultLanguageCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGenericCmdReq_struct 
 {	 
 CiSimFilePath path ; /**< Path of the elementary file \sa CiSimFilePath */	 
 CiSimGenericCmdType instruction ; /**< Instruction code \sa CiSimGenericCmdType */	 
 UINT8 param1 ; /**< Instruction parameter 1 for the instruction */	 
 UINT8 param2 ; /**< Instruction parameter 2 for the instruction*/	 
 UINT8 length ; /**< Number of bytes in the command data string */	 
 UINT8 data [ 255 ] ; /**< Command data string */	 
 CiBoolean responseExpected ; /**< Indicates if a response is expected by the application \sa CCI API Ref Manual */	 
 UINT8 responseLength ; /**< Number of bytes expected in the response data string */	 
 /*Michal Bukai - SIM Logic CH - NFC\ISIM support*/	 
 UINT16 SessionId ; /**< A session Id to be used in order to target a specific application on the smart card using logical channel mechanism. */	 
 } CiSimPrimGenericCmdReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGenericCmdCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiSimCmdRsp cnf ; /**< SIM generic command response \sa CiSimCmdRsp_Struct */	 
 UINT8 sw1 ; /**< Status byte 1 as returned from the card */	 
 UINT8 sw2 ; /**< Status byte 2 as returned from the card */	 
 /*Michal Bukai - SIM Logic CH - NFC\ISIM support*/	 
 UINT16 SessionId ; /**< A session Id to be used in order to target a specific application on the smart card using logical channel mechanism. */	 
 } CiSimPrimGenericCmdCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGenericLargeCmdCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiSimLargeCmdRsp cnf ; /**< SIM generic command response \sa CiSimCmdRsp_Struct */	 
 UINT16 SessionId ; /**< A session Id to be used in order to target a specific application on the smart card using logical channel mechanism. */	 
 } CiSimPrimGenericLargeCmdCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSetPollReq_struct {	 
 UINT8 mode ; /*0: disable polling ; 1 : enable polling ( Default ) ; others RFU*/	 
 UINT8 pollingConfig ; /*0: use UE default inverval , 28 s , ( Default ) ; 1 : enable polling config value ; others RFU*/	 
 UINT8 stkPolling ; /*0: don ' t use stk polling interval ; 1 : use the stk polling interval ( default ) ; others RFU*/	 
 UINT32 interval ; /*unit: second*/	 
 } CiSimPrimSetPollReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSetPollCnf_struct {	 
 CiSimRc result ; /**< Result code \sa CiSimRc */	 
 } CiSimPrimSetPollCnf;

typedef CiEmptyPrim CiSimPrimGetPollReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetPollCnf_struct {	 
 CiSimRc result ; /**< Result code \sa CiSimRc */	 
 UINT8 mode ; /*0: disable polling ; 1 : enable polling ( Default ) ; others RFU*/	 
 UINT8 pollingConfig ; /*0: use UE default inverval , 28 s , ( Default ) ; 1 : enable polling config value ; others RFU*/	 
 UINT8 stkPolling ; /*0: don ' t use stk polling interval ; 1 : use the stk polling interval ( default ) ; others RFU*/	 
 UINT32 interval ; /*unit: second*/	 
 } CiSimPrimGetPollCnf;

typedef CiEmptyPrim CiSimPrimDeviceRsp ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimCardInd_struct {	 
 CiSimStatus status ; /**< SIM Status. \sa CiSimStatus */	 
 CiSimPinState pinState ; /**< PIN state when SIM becomes ready , ignored if status is NOT CI_SIM_ST_READY. \sa CiSimPinState */	 
 CiBoolean cardIsUicc ; /**< TRUE if USIM card ; FALSE if SIM card. \sa CCI API Ref Manual */	 
	 
 CiBoolean isTestCard ; /**< TRUE if Test card ; FALSE if normal / special card. \sa CCI API Ref Manual */	 
 /*2015.01.13 , mod by Xili for #517213 , CQ00081907 begin*/	 
 /*mod for CQ00085367 by yunhail 2015 2 13 begin*/	 
 /*delete the SS_IPC_SUPPORT*/	 
 /*mod for CQ00085367 by yunhail 2015 2 13 end*/	 
 CiString ImsiStr ; /**< Subscriber ID ( IMSI ) string. The value is valid	 
 only if SIM status is CI_SIM_ST_READY and pin state is CI_SIM_PIN_ST_READY \sa */	 
 /*mod for CQ00085367 by yunhail 2015 2 13 begin*/	 
 /*delete the SS_IPC_SUPPORT*/	 
 /*mod for CQ00085367 by yunhail 2015 2 13 end*/	 
 /*2015.01.13 , mod by Xili for #517213 , CQ00081907 end*/	 
 } CiSimPrimCardInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimIsEmergencyNumberReq_struct {	 
 CHAR eccDigitsStr [ 7 ] ; /**< Null-terminated dial string \sa CCI API Ref Manual */	 
 } CiSimPrimIsEmergencyNumberReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimIsEmergencyNumberCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiBoolean isEmergency ; /**< TRUE = number is an emergency call code ; FALSE = otherwise \sa CCI API Ref Manual */	 
 } CiSimPrimIsEmergencyNumberCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSimOwnedInd_struct {	 
	 
 CiBoolean isOwned ; /**< TRUE = the SIM is owned ; FALSE = the SIM is not owned \sa CCI API Ref Manual */	 
	 
 } CiSimPrimSimOwnedInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSimChangedInd_struct {	 
	 
 CiBoolean isChanged ; /**< TRUE = the current SIM card has changed ; FALSE = the current SIM card has not changed \sa CCI API Ref Manual */	 
	 
 } CiSimPrimSimChangedInd;

typedef CiEmptyPrim CiSimPrimDeviceStatusReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimDeviceStatusCnf_struct {	 
	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 CiSimStatus SIMstatus ; /**< SIM status \sa CiSimStatus */	 
 CiSimPinState pinState ; /**< Not in use \sa CiSimPinState */	 
 } CiSimPrimDeviceStatusCnf;

typedef CiEmptyPrim CiSimPrimSetVSimReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSetVSimCnf_struct {	 
 CiSimRc result ; /**< Result code \sa CiSimRc */	 
 } CiSimPrimSetVSimCnf;

typedef CiEmptyPrim CiSimPrimGetVSimReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetVSimCnf_struct {	 
 CiSimRc result ; /**< Result code \sa CiSimRc */	 
 CiBoolean status ; /**< Virtual SIM status: TRUE = enabled ; FALSE = disabled \sa CCI API Ref Manual */	 
 } CiSimPrimGetVSimCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimCheckMMIStateInd_struct {	 
 UINT16 len ; /**< Length of the proactive command data [ 1 -255 ] */	 
 UINT8 data [ 261 ] ; /**< Proactive command data for SIM refresh */	 
 } CiSimPrimCheckMMIStateInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimCheckMMIStateRsp_struct {	 
 CiSimMMIState MMIState ; /**< Indicates if MMI state is IDLE or BUSY. \sa CiSimPinState */	 
 UINT8 generalResult ; /**< General result of TR for SIM refresh if reject , used only when MMI state is busy */	 
 UINT8 addtionResult ; /**< Additional result of TR for SIM refresh if reject , 0 means no addtional result */	 
 } CiSimPrimCheckMMIStateRsp;

//ICAT EXPORTED ENUM 
 typedef enum CI_SIM_BTSAP_CONN_STAT_TAG {	 
 CI_SIM_BTSAP_OK = 0 , /**< OK , Server can fulfill requirements */	 
 CI_SIM_BTSAP_UNABLE_TO_ESTABLISH_CONNECTION , /**< Error , Server unable to establish connection */	 
 CI_SIM_BTSAP_MAX_MESSAGE_SIZE_NOT_SUPPORTED , /**< SIM personalization , lock phone with the first */	 
 CI_SIM_BTSAP_MAX_MESSAGE_SIZE_TOO_SMALL , /**< Error , maximum message size by Client is too small */	 
 CI_SIM_BTSAP_ONGOING_CALL , /**< OK , ongoing call */	 
 CI_SIM_BTSAP_NUM_STATE	 
 } _CiSimBTSapConnectionStatus;

typedef UINT8 CiSimBTSapConnectionStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CI_SIM_BTSAP_STATUS_TAG {	 
 CI_SIM_BTSAP_STAT_ERR = 0 , /**< Unknown error */	 
 CI_SIM_BTSAP_STAT_CARD_RESET , /**< Card reset */	 
 CI_SIM_BTSAP_STAT_CARD_NOT_ACC , /**< Card not accessible */	 
 CI_SIM_BTSAP_STAT_CARD_REMOVED , /**< Card removed */	 
 CI_SIM_BTSAP_STAT_CARD_INSERTED , /**< Card inserted */	 
 CI_SIM_BTSAP_STAT_CARD_RECOVERED , /**< Card recovered */	 
 CI_SIM_BTSAP_STAT_NUM_STATE	 
 } _CiSimBTSapStatus;

typedef UINT8 CiSimBTSapStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CI_SIM_BTSAP_TP_TAG {	 
 CI_SIM_BTSAP_TP_T0 = 0 , /**< T=0 */	 
 CI_SIM_BTSAP_TP_T1 , /**< T=1 */	 
 CI_SIM_BTSAP_TP_NUM_STATE	 
	 
 } _CiSimTransportProtocol;

typedef UINT8 CiSimTransportProtocol ;
//ICAT EXPORTED ENUM 
 typedef enum CI_SIM_BTSAP_CONTROL_TAG {	 
 CI_SIM_BTSAP_POWER_OFF = 0 , /**< Power off the SIM / USIM */	 
 CI_SIM_BTSAP_POWER_ON , /**< Power on the SIM / USIM */	 
 CI_SIM_BTSAP_RESET , /**< Reset the SIM / USIM */	 
 CI_SIM_BTSAP_NUM_CONTROL	 
	 
 } _CiSimBTSapControl;

typedef UINT8 CiSimBTSapControl ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimBTSAPConnectReq_struct {	 
 UINT16 maxMsgSize ; /**< Maximum message size requested by the Client */	 
 } CiSimPrimBTSAPConnectReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimBTSAPConnectCnf_struct {	 
 CiSimBTSapConnectionStatus ConnectionStatus ; /**< Connection status. \sa CiSimBTSapConnectionStatus */	 
 UINT16 maxMsgSize ; /**< Maximum message size supported by comm. subsystem */	 
 CiSimRc ResultCode ; /**< result code. \sa CiSimRc */	 
 } CiSimPrimBTSAPConnectCnf;

typedef CiEmptyPrim CiSimPrimBTSAPDisconnectReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimBTSAPDisconnectCnf_struct {	 
 CiSimRc ResultCode ; /**< result code. \sa CiSimRc */	 
 } CiSimPrimBTSAPDisconnectCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimBTSAPTransferApduReq_struct {	 
 CiSimCmdReq CommandAPDU ; /**< SIM command ; If command type is not APDU7816 it is coded according to Referenced Documents [ 12 ] ; If command type is APDU7816 it is coded according to Referenced Documents [ 25 ] . \sa CiSimCmdReq */	 
 } CiSimPrimBTSAPTransferApduReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimBTSAPTransferApduCnf_struct {	 
 CiSimCmdRsp ResponseAPDU ; /**< SIM response is optional and will be present only if command was processed without errors.	 
 Coding of the response depends on the APDU that was sent to the SIM / USIM	 
 If command type is not APDU7816 it is coded according to Referenced Documents [ 12 ]	 
 If command type is APDU7816 it is coded according to Referenced Documents [ 25 ] . \sa CiSimCmdRsp */	 
 CiSimRc ResultCode ; /**< result code. \sa CiSimRc */	 
 } CiSimPrimBTSAPTransferApduCnf;

typedef CiEmptyPrim CiSimPrimBTSAPTransferAtrReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimBTSAPTransferAtrCnf_struct {	 
 CiSimCmdRsp ATRData ; /**< ATR will be present only if there are no errors ATR is coded according to Referenced Documents [ 25 ] \sa CiSimCmdRsp */	 
 CiSimRc ResultCode ; /**< result code. \sa CiSimRc */	 
 } CiSimPrimBTSAPTransferAtrCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimBTSAPSimControlReq_struct {	 
 CiSimBTSapControl Control ; /**< SIM control operation. \sa CiSimBTSapControl */	 
 } CiSimPrimBTSAPSimControlReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimBTSAPSimControlCnf_struct {	 
 CiSimRc ResultCode ; /**< result code. \sa CiSimRc */	 
 } CiSimPrimBTSAPSimControlCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimBTSAPStatusInd_struct {	 
 CiSimBTSapStatus StatusChange ; /**< Subscription module availability status. \sa CiSimBTSapStatus */	 
 } CiSimPrimBTSAPStatusInd;

typedef CiEmptyPrim CiSimPrimBTSAPStatusReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimBTSAPStatusCnf_struct {	 
 CiSimBTSapStatus Status ; /**< Status of the subscription module availability \sa CiSimBTSapStatus */	 
 CiSimRc ResultCode ; /**< result code. \sa CiSimRc */	 
 } CiSimPrimBTSAPStatusCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimBTSAPSetTransportProtocolReq_struct {	 
 CiSimTransportProtocol TransportProtocol ; /**< Transport Protocol type T=0 or T=1 \sa CiSimTransportProtocol */	 
 } CiSimPrimBTSAPSetTransportProtocolReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimBTSAPSetTransportProtocolCnf_struct {	 
 CiSimRc ResultCode ; /**< result code. \sa CiSimRc */	 
 } CiSimPrimBTSAPSetTransportProtocolCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimMEPAddIMSIReq_struct {	 
	 
 /* # Start Contiguous Code Section # */	 
 CiPassword pass ; /**< The password is the personalization control key PCK. \sa CCI API Ref Manual */	 
 /* # End Contiguous Code Section # */	 
 } CiSimPrimMEPAddIMSIReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimMEPAddIMSICnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 } CiSimPrimMEPAddIMSICnf;

//ICAT EXPORTED ENUM 
 typedef enum CISIMUICCEXTAUTHTYPE_TAG {	 
 CI_SIM_UICC_AUTH_IMS_AKA = 0 , /**< See 3 GPP TS 31.103000 section 7.100000 .2.1 */	 
 CI_SIM_UICC_AUTH_GBA_BOOT , /**< See 3 GPP TS 31.103000 section 7.100000 .2.3 */	 
 CI_SIM_UICC_AUTH_GBA_NAF , /**< See 3 GPP TS 31.103000 section 7.100000 .2.4 */	 
 CI_SIM_UICC_AUTH_HTTP_DIGEST , /**< See 3 GPP TS 31.103000 section 7.100000 .2.2 */	 
	 
 CI_SIM_UICC_AUTH_NUM_TYPES	 
 } _CiSimUiccExtAuthType;

typedef UINT8 CiSimUiccExtAuthType ;
//ICAT EXPORTED STRUCT 
 typedef struct CISIMDfName_struct {	 
 UINT8 len ; /**< Length */	 
 UINT8 data [ 16 ] ; /**< Array of 1 to 16 bytes in hexadecimal format representing the AID of the UICC application */	 
 } CISIMDfName;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimOpenLogicalChannelReq_struct 
 {	 
 CISIMDfName DFname ; /**< DFName is the AID. All selectable applications are represented in the UICC by an AID coded on 1 to 16 hexadecimal bytes. \sa CISIMDfName_struct */	 
 UINT16 SessionId ; /**< A session ID to be used to open the logical channel id if assigned */	 
 } CiSimPrimOpenLogicalChannelReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimOpenLogicalChannelCnf_struct 
 {	 
 CiSimRc rc ; /**< result code. \sa CiSimRc */	 
 UINT16 SessionId ; /**< A session ID to be used to target a specific application on the smart card using the logical channel mechanism. */	 
 UINT16 StatusWord ; /**< Status Word is used to return if SIM fail with statusWord , just ingore if it is 0 */	 
 } CiSimPrimOpenLogicalChannelCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimCloseLogicalChannelReq_struct 
 {	 
 UINT16 SessionId ; /**< A session ID to be used to target a specific application on the smart card using the logical channel mechanism. */	 
 } CiSimPrimCloseLogicalChannelReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimCloseLogicalChannelCnf_struct 
 {	 
 CiSimRc rc ; /**< result code. \sa CiSimRc */	 
 } CiSimPrimCloseLogicalChannelCnf;

typedef CiEmptyPrim CiSimPrimAppPinReq ;
//ICAT EXPORTED STRUCT 
 typedef struct AppPinInfoArrTag 
 {	 
 UINT8 AIDlength ;	 
 UINT8 AIDdata [ 16 ] ;	 
	 
 CiBoolean isPIN1Enabled ;	 
 UINT8 PIN1RetryCount ;	 
 UINT8 PUK1RetryCount ;	 
	 
 CiBoolean isPIN2Enabled ;	 
 UINT8 PIN2RetryCount ;	 
 UINT8 PUK2RetryCount ;	 
 } AppPinInfoArr;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimAppPinCnf_struct 
 {	 
 CiSimRc rc ;	 
 UINT8 AIDnum ;	 
 AppPinInfoArr appPinInfo [ 8 ] ;	 
 } CiSimPrimAppPinCnf;

//ICAT EXPORTED ENUM 
 typedef enum CISIMSIMATCCSTATUS_TAG {	 
 CI_SIM_SIMAT_CC_STATUS_NO_CHANGE = 0 , /**< The request was not modified by SIMAT CC */	 
 CI_SIM_SIMAT_CC_STATUS_CALL_CHANGED , /**< SIMAT CC changed a call setup request */	 
 CI_SIM_SIMAT_CC_STATUS_CALL_BARRED , /**< SIMAT CC barred a call setup request */	 
 CI_SIM_SIMAT_CC_STATUS_CALL_REPLACED_BY_SS , /**< SIMAT CC replaced a call setup request with an SS operation */	 
 CI_SIM_SIMAT_CC_STATUS_SS_CHANGED , /**< SIMAT CC changed an SS operation */	 
 CI_SIM_SIMAT_CC_STATUS_SS_BARRED , /**< SIMAT CC barred an SS operation */	 
 CI_SIM_SIMAT_CC_STATUS_SS_REPLACED_BY_CALL , /**< SIMAT CC replaced an SS operation request with call setup */	 
 CI_SIM_SIMAT_CC_STATUS_SS_FAILED , /**< SIMAT CC changed an SS operation or replaced a call setup request or a USSD operation with an SS operation and SS operation failed */	 
 CI_SIM_SIMAT_CC_STATUS_CALL_FAILED , /**< SIMAT CC changed a call setup request or replaced an SS operation or a USSD operation with a call setup request and call setup failed */	 
 CI_SIM_SIMAT_CC_STATUS_SS_OK , /**< SIMAT CC changed an SS operation or replaced a call setup request or a USSD operation with an SS operation and SS operation is OK */	 
 CI_SIM_SIMAT_CC_STATUS_USSD_FAILED , /**< SIMAT CC changed a USSD operation or replaced a call setup request or an SS operation with a USSD operation and USSD operation failed */	 
 CI_SIM_SIMAT_CC_STATUS_USSD_OK , /**< SIMAT CC changed a USSD operation or replaced a call setup request or an SS operation with a USSD operation and USSD operation is OK */	 
 CI_SIM_SIMAT_CC_STATUS_CALL_REPLACED_BY_USSD , /**< SIMAT CC replaced a call setup request with a USSD operation */	 
 CI_SIM_SIMAT_CC_STATUS_SS_REPLACED_BY_USSD , /**< SIMAT CC replaced an SS operation request with a USSD operation */	 
 CI_SIM_SIMAT_CC_STATUS_USSD_CHANGED , /**< SIMAT CC changed a USSD operation */	 
 CI_SIM_SIMAT_CC_STATUS_USSD_BARRED , /**< SIMAT CC barred a USSD operation */	 
 CI_SIM_SIMAT_CC_STATUS_USSD_REPLACED_BY_CALL , /**< SIMAT CC replaced a USSD operation with call setup */	 
 CI_SIM_SIMAT_CC_STATUS_USSD_REPLACED_BY_SS , /**< SIMAT CC replaced a USSD operation with an SS operation */	 
	 
 CI_SIM_SIMAT_CC_STATUS_NUM_TYPES	 
 } _CiSimSIMATCcStatus;

typedef UINT8 CiSimSIMATCcStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMSIMATCCOPERATION_TAG {	 
 CI_SIM_SIMAT_CC_CALL_SET_UP = 0 , /**< Call setup */	 
 CI_SIM_SIMAT_CC_SS_OPERATION , /**< SS operation */	 
 CI_SIM_SIMAT_CC_USSD_OPERATION , /**< USSD operation */	 
	 
 CI_SIM_SIMAT_CC_OPERATION_NUM_TYPES	 
 } _CiSimSIMATCcOperation;

typedef UINT8 CiSimSIMATCcOperation ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMSIMATSMSTATUS_TAG {	 
 CI_SIM_SIMAT_SM_STATUS_NO_CHANGE = 0 , /**< SIMAT SM did not modify an SMS request */	 
 CI_SIM_SIMAT_SM_STATUS_CHANGED , /**< SIMAT SM changed an SMS destination address */	 
 CI_SIM_SIMAT_SM_STATUS_BARRED , /**< SIMAT CC barred a call setup request */	 
	 
 CI_SIM_SIMAT_SM_STATUS_NUM_TYPES	 
 } _CiSimSIMATSmStatus;

typedef UINT8 CiSimSIMATSmStatus ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMCCCONTROLRESULT_TAG {	 
 CI_SIM_CC_NO_CONTROL , /**< SIMAT CC did not allow a request */	 
 CI_SIM_CC_ALLOWED_NO_MOD , /**< SIMAT CC did allow a request without modifications */	 
 CI_SIM_CC_NOT_ALLOWED , /**< SIMAT CC barred a request */	 
 CI_SIM_CC_ALLOWED_WITH_MOD , /**< SIMAT CC did allow a request with modifications */	 
	 
 CI_SIM_CC_NUM_TYPES	 
 } _CiSimCcControlResult;

typedef UINT8 CiSimCcControlResult ;
//ICAT EXPORTED ENUM 
 typedef enum CISIMCCCALLTYPE_TAG {	 
 CI_SIM_CC_CALL_TYPE_MO_VOICE , /**< SIMAT CC original call type is MO voice */	 
 CI_SIM_CC_CALL_TYPE_MO_SMS , /**< SIMAT CC original call type is MO SMS */	 
 CI_SIM_CC_CALL_TYPE_MO_SS , /**< SIMAT CC original call type is MO SS */	 
 CI_SIM_CC_CALL_TYPE_MO_USSD , /**< SIMAT CC original call type is MO USSD */	 
 CI_SIM_CC_CALL_PDP_CTXT , /**< SIMAT CC original call type is PDP context ( not supported ) */	 
	 
 CI_SIM_CC_CALL_TYPE_NUM_TYPES	 
 } _CiSimCcCallType;

typedef UINT8 CiSimCcCallType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSIMATCcStatusInd_struct {	 
 CiSimSIMATCcStatus status ; /**< SIMAT CC status response \sa CiSimSIMATCcStatus */	 
 CiSimSIMATCcOperation OperationType ; /**< The operation type that was passed to USIM \sa CiSimSIMATCcOperation */	 
 CiBoolean alphaIdPresent ; /**< Indicates whether the SIMAT CC status response has an accompanying alphanumeric ID string \sa CCI API Ref Manual */	 
 CiSimatAlphaTag alphaId ; /**< Optional alphanumeric ID \sa CiSimatAlphaTag_struct */	 
	 
 CiBoolean addressPresent ; /**< Indicates whether the SIMAT CC status response has a changed called number \sa CCI API Ref Manual */	 
 CiAddressInfo AddressInfo ; /**< Optional changed called number \sa CiAddressInfo_struct */	 
	 
 /* Add by jungle for CQ00057794 on 2014 -03-31 Begin */	 
 UINT8 ccRawDataLen ;	 
 UINT8 ccRawData [ 255 ] ;	 
 /* Add by jungle for CQ00057794 on 2014 -03-31 End */	 
 } CiSimPrimSIMATCcStatusInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSIMATSendCallSetupRspInd_struct {	 
 CiBoolean status ; /**< Response sent to SIMAT ; TRUE: call setup is OK ; FALSE: call setup failed. \sa CCI API Ref Manual */	 
	 
 UINT8 generalResult ; /** If status is set to FALSE , will fill general result to notify AP if it is ME ( 0x20 ) or NET ( 0x21 ) failed */	 
 UINT8 additionResult ; /** If addtion result is present will fill it , else set it to 0x00 */	 
 } CiSimPrimSIMATSendCallSetupRspInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSIMATSendSsUssdRspInd_struct {	 
 CiBoolean status ; /**< Response sent to SIMAT ; TRUE: SS or USSD operation is OK ; FALSE: SS or USSD operation failed. \sa CCI API Ref Manual */	 
 CiSimSIMATCcOperation OperationType ; /**< The operation type that was passed to USIM \sa CiSimSIMATCcOperation */	 
 } CiSimPrimSIMATSendSsUssdRspInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSIMATSmControlStatusInd_struct {	 
 CiSimSIMATSmStatus status ; /**< SIMAT SM status response \sa CiSimSIMATSmStatus */	 
 CiBoolean alphaIdPresent ; /**< Indicates whether the SIMAT SM status response has an accompanying alphanumeric ID string \sa CCI API Ref Manual */	 
 CiSimatAlphaTag alphaId ; /**< Optional alphanumeric ID \sa CiSimatAlphaTag_struct */	 
 /* Add by jungle for CQ00057794 on 2014 -03-31 Begin */	 
 UINT8 ccRawDataLen ;	 
 UINT8 ccRawData [ 255 ] ;	 
 /* Add by jungle for CQ00057794 on 2014 -03-31 End */	 
 } CiSimPrimSIMATSmControlStatusInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimSIMATSendSmRspInd_struct {	 
 CiBoolean status ; /**< Response sent to SIMAT ; TRUE: SM operation is OK ; FALSE: SM operation failed. \sa CCI API Ref Manual */	 
	 
 UINT8 generalResult ; /** If status is set to FALSE , will fill general result to notify AP if it is ME ( 0x20 ) or RP-ERR ( 0x35 ) or SMS control ( 0x39 ) failed */	 
 UINT8 additionResult ; /** If addtion result is present will fill it , else set it to 0x00 */	 
 } CiSimPrimSIMATSendSmRspInd;

//ICAT EXPORTED ENUM 
 typedef enum CISIMRSAPSERVICETYPE_TAG {	 
 CI_SIM_RSAP_SERVICE_RECONNECT = 0 , /**< Reconnect to local or remote SIM */	 
 CI_SIM_RSAP_SERVICE_DISCONNECT , /**< Disconnect from local or remote SIM */	 
 CI_SIM_RSAP_SERVICE_NUM_TYPES	 
 } _CiSimRsapServiceType;

typedef UINT8 CiSimRsapServiceType ;
typedef CiEmptyPrim CiSimPrimRsapConnReqInd ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapConnReqRsp_struct {	 
 CiSimRc ResultCode ; /**< Result code \sa CiSimRc */	 
 CiSimBTSapConnectionStatus ConnecitonStatus ; /**< RSAP connection status \sa CiSimBTSapConnectionStatus */	 
 } CiSimPrimRsapConnReqRsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapStatReq_struct {	 
 CiSimBTSapStatus status ; /**< RSAP connection status \sa CiSimBTSapStatus */	 
 } CiSimPrimRsapStatReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapStatCnf_struct {	 
 CiSimRc ResultCode ; /**< Result code \sa CiSimRc */	 
 } CiSimPrimRsapStatCnf;

typedef CiEmptyPrim CiSimPrimRsapDisconnReqInd ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapDisconnReqRsp_struct {	 
 CiSimRc ResultCode ; /**< Result code \sa CiSimRc */	 
 } CiSimPrimRsapDisconnReqRsp;

typedef CiEmptyPrim CiSimPrimRsapGetAtrInd ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapGetAtrRsp_struct {	 
 CiSimRc ResultCode ; /**< Result code \sa CiSimRc */	 
 CiSimCmdRsp ATRData ; /**< ATR will be present only if there are no errors.\sa CiSimCmdRsp */	 
 } CiSimPrimRsapGetAtrRsp;

typedef CiEmptyPrim CiSimPrimRsapGetStatusInd ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapSetTranPReqInd_struct {	 
 CiSimTransportProtocol TransportProtocol ; /**< Transport Protocol type T=0 or T=1 \sa CiSimTransportProtocol */	 
 } CiSimPrimRsapSetTranPReqInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapSetTranPReqRsp_struct {	 
 CiSimRc ResultCode ; /**< Result code \sa CiSimRc */	 
 } CiSimPrimRsapSetTranPReqRsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapSimControlReqInd_struct {	 
 CiSimBTSapControl Control ; /**< SIM control operation. \sa CiSimBTSapControl */	 
 } CiSimPrimRsapSimControlReqInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapSimControlReqRsp_struct {	 
 CiSimRc ResultCode ; /**< Result code \sa CiSimRc */	 
 } CiSimPrimRsapSimControlReqRsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapSimSelectReq_struct {	 
 CiSimRsapServiceType ServiceType ; /**< Type of operation required: reconnect or disconnect \sa CiSimRsapServiceType */	 
 CiBoolean RemoteSIM ; /**< TRUE - Select remote SIM ; FALSE - Select local SIM \sa CCI API Ref Manual */	 
 } CiSimPrimRsapSimSelectReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapSimSelectCnf_struct {	 
 CiSimRc ResultCode ; /**< Result code \sa CiSimRc */	 
 } CiSimPrimRsapSimSelectCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapStatusInd_struct {	 
 CiSimBTSapStatus status ; /**< RSAP connection status \sa CiSimBTSapStatus */	 
 } CiSimPrimRsapStatusInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapTransferAPDUInd_struct {	 
 CiSimCmdReq CommandAPDU ; /**< SIM command.\sa CiSimCmdReq */	 
 } CiSimPrimRsapTransferAPDUInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimRsapTransferAPDURsp_struct {	 
 CiSimRc ResultCode ; /**< Result code \sa CiSimRc */	 
 CiSimCmdRsp ResponseAPDU ; /**< SIM response is optional and is only sent if the command was processed without errors.\sa CiSimCmdRsp */	 
 } CiSimPrimRsapTransferAPDURsp;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimIccidInd_struct {	 
 CiSimIccid iccid ; /**< ICC Id value \sa CiSimIccid */	 
 } CiSimPrimIccidInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimIsimAidInd_struct {	 
 CiSimPinState isimPinState ;	 
 UINT8 isimAIDlength ;	 
 UINT8 isimAIDdata [ 16 ] ; /**< ISIM Aid value \sa CiSimIsimAid */	 
 } CiSimPrimIsimAidInd;

//ICAT EXPORTED ENUM 
 typedef enum EfAdMsOperationModeTag 
 {	 
 EF_AD_MS_OPERN_NORMAL = 0x00 , /* normal operation */	 
 EF_AD_MS_OPERN_TA = 0x80 , /* type approval operation */	 
 EF_AD_MS_OPERN_NORMAL_PLUS_SPECIFIC = 0x01 , /* normal + specific operation */	 
 EF_AD_MS_OPERN_TA_PLUS_SPECIFIC = 0x81 , /* type approval + specific operation */	 
 EF_AD_MS_OPERN_MAINTENANCE = 0x02 , /* maintenance operation */	 
 EF_AD_MS_OPERN_CELL_TEST = 0x04 /* cell test operation */	 
 } _EfAdMsOperationMode;

typedef UINT8 EfAdMsOperationMode ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimAdminDataInd_struct 
 {	 
 EfAdMsOperationMode efadmsOperationMode ;	 
 /* MSB is byte 1 2 of AD file */	 
 UINT8 mncLength ;	 
 UINT32 additionalInfo ;	 
 } CiSimPrimAdminDataInd;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimEmergencyCallCode_struct 
 {	 
 UINT8 serviceCategory ;	 
 CHAR EmergencyCallCode [ 7 ] ;	 
 } CiSimEmergencyCallCode;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimEccListInd_struct 
 {	 
 UINT8 numEccsOnSim ;	 
 CiSimEmergencyCallCode eccList [ 20 ] ;	 
 } CiSimPrimEccListInd;

typedef CiEmptyPrim CiSimPrimGetIccidReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetIccidCnf_struct {	 
 CiSimRc ResultCode ; /**< Result code \sa CiSimRc */	 
 CiSimIccid iccid ; /**< ICC Id value \sa CiSimIccid */	 
 } CiSimPrimGetIccidCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimEAPAuthenticationReq_struct {	 
 CISIMDfName DFname ;	 
 UINT8 EAPMethod [ 8 ] ;	 
 UINT8 length ;	 
 UINT8 EAPPacketData [ 256 ] ;	 
 UINT16 DFeap ;	 
 } CiSimPrimEAPAuthenticationReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimEAPAuthenticationCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 UINT8 length ;	 
 UINT8 EAPPacketResponse [ 256 ] ;	 
 UINT32 EAPSessionID ;	 
 } CiSimPrimEAPAuthenticationCnf;

//ICAT EXPORTED ENUM 
 typedef enum CISIMACTAPPYPE_TAG {	 
 CI_SIM_ACT_APP_NONE = 0 , /**< no SIM or USIM active */	 
 CI_SIM_ACT_APP_SIM , /**< active application is SIM */	 
 CI_SIM_ACT_APP_USIM , /**< active application is USIM , followed by <AID> */	 
 CI_SIM_ACT_APP_NUM_TYPES	 
 } _CiSimActAppType;

typedef UINT8 CiSimActAppType ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetNumUiccApplicationsReq_struct {	 
 UINT8 option ;	 
 } CiSimPrimGetNumUiccApplicationsReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetNumUiccApplicationsCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 UINT16 NumUiccApplication ;	 
 CiSimActAppType active_application ;	 
 CISIMDfName aid ;	 
 } CiSimPrimGetNumUiccApplicationsCnf;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetUiccApplicationsInfoReq_struct {	 
 UINT8 index ;	 
 } CiSimPrimGetUiccApplicationsInfoReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimGetUiccApplicationsInfoCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 UINT8 responseLen ;	 
 UINT8 response [ 127 ] ;	 
 UINT8 index ;	 
 } CiSimPrimGetUiccApplicationsInfoCnf;

typedef UINT8 CiSimEapParameters ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimEapRetrieveParametersReq_struct {	 
 UINT32 EAPSessionID ;	 
 CiSimEapParameters EAPParameters ;	 
 } CiSimEapRetrieveParametersReq;

//ICAT EXPORTED STRUCT 
 typedef struct CiSimEapRetrieveParametersCnf_struct {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 UINT8 length ;	 
 UINT8 EAPParamResp [ 256 ] ;	 
 } CiSimEapRetrieveParametersCnf;

typedef CiEmptyPrim CiSimPrimUpdateCountReq ;
//ICAT EXPORTED STRUCT 
 typedef struct CiSimPrimUpdateCountCnf_struct 
 {	 
 CiSimRc rc ; /**< Result code \sa CiSimRc */	 
 UINT32 totalCount ;	 
 UINT16 startHfn ;	 
 UINT32 updateStartHfnCount ;	 
 UINT16 keyps ;	 
 UINT32 updateKeypsCount ;	 
 UINT16 kc ;	 
 UINT32 updateKcCount ;	 
 UINT16 psloci ;	 
 UINT32 updatePsLociCount ;	 
 UINT16 kcGprs ;	 
 UINT32 updateKcGprsCount ;	 
 UINT16 loci ;	 
 UINT32 updateLociCount ;	 
 UINT16 keys ;	 
 UINT32 updateKeysCount ;	 
 /*CQ00113882 , Cgliu , 2019 -11-27 , Begin*/	 
 UINT16 epsloci ; /*6FE3*/	 
 UINT32 updateEpslociCount ;	 
 UINT16 epsnsc ; /*6FE4*/	 
 UINT32 updateEpsnscCount ;	 
 /*CQ00113882 , Cgliu , 2019 -11-27 , End */	 
 } CiSimPrimUpdateCountCnf;

typedef UINT8 CiDatPduType ;
typedef union _CiGroupHandle
 {
 CiServiceHandle svcHandle ;
 CiSgOpaqueHandle sgHandle ;
 } CiGroupHandle ;
typedef union _CiCallHandle
 {
 CiRequestHandle reqHandle ;
 CiIndicationHandle indHandle ;
 } CiCallHandle ;
typedef UINT32 CiDatBufSize ;
typedef UINT8 *CiDatBufArray [ 10 ] ;
typedef union
 {
 CiDatPrimSendReq ciDatPrimSendReq ;
 CiDatPrimRecvInd ciDatPrimRecvInd ;
 } CiDatPrim ;
typedef UINT32 CIStubMsgId ;
typedef UINT32 CiCallbackId ;
typedef UINT32 enum_t ;
typedef Boolean ( *CiSgAdjustSacCiReq ) ( CiServiceHandle handle , CiPrimitiveID primId , void* paras ) ;
typedef Boolean ( *CiSgAdjustSacCiInd ) ( CiServiceGroupID sgId , CiPrimitiveID indPrimId , void *indParas ) ;
typedef Boolean ( *CiSgAdjustSacCiCnf ) ( CiServiceGroupID sgId , CiPrimitiveID cnfPrimId , void *cnfParas ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
	 
 ACIPCD_RESERVED = 0 ,	 
 ACIPCD_CI_SID , /* ci stub */	 
 ACIPCD_NVM_SID , /* nvm stub */	 
 ACIPCD_CI_DATA_SID , /* ci data stub */	 
 ACIPCD_DIAG_PORT_SID , /* DIAG port stub */	 
 ACIPCD_AUDIO_SID , /* Audio stub */	 
 ACIPCD_DIAG_SID = 16 , /* DIAG control stub */	 
 ACIPCD_RTC_SID = 18 , /* RTC tunnel stub */	 
 ACIPCD_USB_SID , /* USB tunnel stub */	 
 ACIPCD_LAST_SID = 31 , /* Max service id = 31 */	 
 ACIPCD_DIAG_DATA_SID = 0 /* DIAG data stub */	 
	 
 } ACIPCD_ServiceIdE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPCD_DO_NOTHING , // No action is required before send or after receive.	 
 ACIPCD_HANDLE_CACHE , // Tx: Clean cache before sending / Rx: Invalidate cache before receive.	 
 ACIPCD_COPY // Tx: Copy to shared memory before sending / Rx: Currently not supported.	 
 } ACIPCD_ActionE;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 void ( *RxIndCB ) ( void * , UINT32 ) ; // Data indication ( Pointer to the data & its length ) .	 
 void ( *LinkStatusIndCB ) ( BOOL ) ; // Link status ( TRUE=Up , FALSE=Down ) .	 
 void ( *LowWmIndCB ) ( void ) ; // Low water mark indication - can restart sending.	 
 void ( *TxDoneCnfCB ) ( void * ) ; // Tx complete ( Pointer to buffer ) - can free the buffer.	 
 void ( *TxFailCnfCB ) ( void * ) ; // Tx fail ( Pointer to buffer ) - can free the buffer.	 
 } ACIPCD_CallBackFuncS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 void ( *RxIndCB ) ( int id , void *ptr , UINT32 size ) ; // Data indication ( Pointer to the data & its length ) .	 
 void ( *LinkStatusIndCB ) ( int id , BOOL up_down ) ; // Link status ( TRUE=Up , FALSE=Down ) .	 
 void ( *LowWmIndCB ) ( int id ) ; // Low water mark indication - can restart sending.	 
 void ( *TxDoneCnfCB ) ( int id , void *ptr ) ; // Tx complete ( Pointer to buffer ) - can free the buffer.	 
 void ( *TxFailCnfCB ) ( int id , void *ptr ) ; // Tx fail ( Pointer to buffer ) - can free the buffer.	 
 } ACIPCD_CallBackFuncExtS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 RpcTimout ; // 0 - Not RPC , Else timout according to OSA.	 
 UINT8 HighWm ; // How many messages we allow other side to send befor he receives our TxComplete.	 
 UINT8 LowWm ; // Once he stoped sending , he will restart when Send-Ack <= LowWm	 
 ACIPCD_ActionE TxAction ; // Action to take before sending.	 
 ACIPCD_ActionE RxAction ; // Action to take before calling the RxIndCB callback function.	 
 BOOL BlockOnRegister ; // TRUE - ACIPCD will block until the link on the other side is up.	 
 } ACIPCD_ConfigS;

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
	 
	 
 MAT_CIREP ,	 
 MAT_CAVIMS ,	 
 MAT_CASIMS ,	 
	 
 MAT_starCIIND ,	 
 MAT_starIMSSRV ,	 
 MAT_POCCMD ,	 
	 
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
	 
 MAT_plusCWRITESIM ,	 
 // #ifdef BT_TEST_SUPPORT 20201214 @xiaokeweng force enable as BT / WIFI could be enable / disable in SDK build	 
 MAT_BTTEST ,	 
 // #endif	 
 MAT_GPSINIT ,	 
 MAT_GPSSLEEP ,	 
 MAT_GPSPF ,	 
 MAT_AGNSSGET ,	 
 MAT_AGNSSSET ,	 
 MAT_GPSST ,	 
 MAT_GPSSET ,	 
 MAT_startECCLIST ,	 
 MAT_TRUSTNUM ,	 
 MAT_CHKTRUSTNUM ,	 
 MAT_starISIMAID ,	 
 MAT_CSSAC ,	 
 MAT_MEDCR ,	 
	 
 MAT_STARREADVER ,	 
 MAT_RESET ,	 
 MAT_RSTSET ,	 
	 
	 
	 
	 
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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
 } TelAtpCtrl;

DIAG_FILTER ( IMS , IMS_STUB , ACIPCDImsTxdefault , DIAG_INFORMATION)  
 diagPrintf ( " --- send IMS data --- " );

DIAG_FILTER ( IMS , IMS_STUB , ACIPCDImsRxdefault , DIAG_INFORMATION)  
 diagPrintf ( " --- received IMS data :%s , size:%d " , ptr , size );

DIAG_FILTER ( CI_SERVER_STUB , CI_SERVER_TASK , 577 , CCI_TRACE_INFO)  
 diagPrintf ( " ciServerStubInit:The ciServerStubPriority is %d " , 70 );

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\ci_msl.ppp
//PPL Source File Name : X:\\pcac\\ci_stub\\src\\ci_msl.c
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
typedef volatile UINT8 *V_UINT8_PTR ;
typedef volatile UINT16 *V_UINT16_PTR ;
typedef volatile UINT32 *V_UINT32_PTR ;
typedef unsigned int U32Bits ;
typedef BOOL BOOLEAN ;
typedef const char * SwVersion ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_PIN_NOT_ASSIGNED = -1 ,	 
	 
 GPIO_PIN_0 = 0 , GPIO_PIN_1 , GPIO_PIN_2 , GPIO_PIN_3 , GPIO_PIN_4 , GPIO_PIN_5 , GPIO_PIN_6 , GPIO_PIN_7 ,	 
	 
 GPIO_PIN_8 , GPIO_PIN_9 , GPIO_PIN_10 , GPIO_PIN_11 , GPIO_PIN_12 , GPIO_PIN_13 , GPIO_PIN_14 , GPIO_PIN_15 ,	 
 GPIO_PIN_16 , GPIO_PIN_17 , GPIO_PIN_18 , GPIO_PIN_19 , GPIO_PIN_20 , GPIO_PIN_21 , GPIO_PIN_22 , GPIO_PIN_23 ,	 
 GPIO_PIN_24 , GPIO_PIN_25 , GPIO_PIN_26 , GPIO_PIN_27 , GPIO_PIN_28 , GPIO_PIN_29 , GPIO_PIN_30 , GPIO_PIN_31 ,	 
 GPIO_PIN_32 , GPIO_PIN_33 , GPIO_PIN_34 , GPIO_PIN_35 , GPIO_PIN_36 , GPIO_PIN_37 , GPIO_PIN_38 , GPIO_PIN_39 ,	 
	 
 GPIO_PIN_40 , GPIO_PIN_41 , GPIO_PIN_42 , GPIO_PIN_43 , GPIO_PIN_44 , GPIO_PIN_45 , GPIO_PIN_46 , GPIO_PIN_47 ,	 
 GPIO_PIN_48 , GPIO_PIN_49 , GPIO_PIN_50 , GPIO_PIN_51 , GPIO_PIN_52 , GPIO_PIN_53 , GPIO_PIN_54 , GPIO_PIN_55 ,	 
 GPIO_PIN_56 , GPIO_PIN_57 , GPIO_PIN_58 , GPIO_PIN_59 , GPIO_PIN_60 , GPIO_PIN_61 , GPIO_PIN_62 , GPIO_PIN_63 ,	 
	 
 GPIO_PIN_64 , GPIO_PIN_65 , GPIO_PIN_66 , GPIO_PIN_67 , GPIO_PIN_68 , GPIO_PIN_69 , GPIO_PIN_70 , GPIO_PIN_71 ,	 
 GPIO_PIN_72 , GPIO_PIN_73 , GPIO_PIN_74 , GPIO_PIN_75 , GPIO_PIN_76 , GPIO_PIN_77 , GPIO_PIN_78 , GPIO_PIN_79 ,	 
 GPIO_PIN_80 , GPIO_PIN_81 , GPIO_PIN_82 , GPIO_PIN_83 , GPIO_PIN_84 , GPIO_PIN_85 , GPIO_PIN_86 , GPIO_PIN_87 ,	 
 GPIO_PIN_88 , GPIO_PIN_89 , GPIO_PIN_90 , GPIO_PIN_91 , GPIO_PIN_92 , GPIO_PIN_93 , GPIO_PIN_94 , GPIO_PIN_95 ,	 
	 
 GPIO_PIN_96 , GPIO_PIN_97 , GPIO_PIN_98 , GPIO_PIN_99 , GPIO_PIN_100 , GPIO_PIN_101 , GPIO_PIN_102 , GPIO_PIN_103 ,	 
 GPIO_PIN_104 , GPIO_PIN_105 , GPIO_PIN_106 , GPIO_PIN_107 , GPIO_PIN_108 , GPIO_PIN_109 , GPIO_PIN_110 , GPIO_PIN_111 ,	 
 GPIO_PIN_112 , GPIO_PIN_113 , GPIO_PIN_114 , GPIO_PIN_115 , GPIO_PIN_116 , GPIO_PIN_117 , GPIO_PIN_118 , GPIO_PIN_119 ,	 
 GPIO_PIN_120 , GPIO_PIN_121 , GPIO_PIN_122 , GPIO_PIN_123 , GPIO_PIN_124 , GPIO_PIN_125 , GPIO_PIN_126 , GPIO_PIN_127 ,	 
	 
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
 GPIO_RC_INCORRECT_INIT_VALUE	 
	 
 , GPIO_RC_INTC_ERROR ,	 
 GPIO_RC_PRM_ERROR	 
	 
 } GPIO_ReturnCode;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_INPUT_PIN = 1 ,	 
 GPIO_OUTPUT_PIN	 
 } GPIO_PinDirection;

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
 GPIO_PinDirection direction ;	 
 } GPIO_PinStatus;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 GPIO_INITIAL_VALUE_NO_CHANGE = 0 ,	 
 GPIO_INITIAL_VALUE_LOW ,	 
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
 GPIO_PinDirection direction ;	 
 GPIO_TransitionType transitionType ;	 
 GPIO_Debounce debounce ;	 
 GPIO_PullUpDown pullUpDown ;	 
 GPIO_BitInitialValue initialValue ;	 
 } GPIO_PinConfiguration;

typedef UINT8 GPIO_PortHandle ;
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
typedef UINT32 rti_uint32_t ;
typedef UINT64 rti_uint64_t ;
//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 product_id ;	 
 UINT8 data [ 20 ] ;	 
 } InfoForBoardTracking_t;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 RTI_DISABLE=0 ,	 
 RTI_EN_VER1=1 ,	 
 RTI_EN_VER2=2	 
 } RTI_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 RTI_QUE_DISABLE=0 ,	 
 RTI_QUE_ENABLE=1	 
 } RTI_QUE_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 RTI_EVT_DISABLE=0 ,	 
 RTI_EVT_ENABLE=1	 
 } RTI_EVT_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 TIME_OUT_3MS=0x62 ,	 
 TIME_OUT_4MS=0x83 ,	 
 TIME_OUT_5MS=0xA4 ,	 
 TIME_OUT_6MS=0xC4 ,	 
 TIME_OUT_MAX=0xFF	 
 } Timeout_Threshold;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 RTI_TYPE rtiType ;	 
 RTI_QUE_TYPE rtiQueType ;	 
 RTI_EVT_TYPE rtiEvtType ;	 
	 
 int rtiChange ;	 
 int rtiHT ;	 
 int rtiLT ;	 
	 
 int modeChange ;	 
 int modeHT ;	 
 int modeLT ;	 
	 
 Timeout_Threshold Timeout ;	 
 } RTICfg_t;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 UART_DEV_UART ,	 
 UART_DEV_DIAG ,	 
 } UART_DEV_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 offset ;	 
 UINT32 size ;	 
 } activateCode_info_t;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UART_DEV_TYPE uartDevType ;	 
 BOOL actiCodeFlag ;	 
 activateCode_info_t activateCode [ 4 ] ; // for Ali activation code , [ 0 ] :flag , [ 1 ] :offset , [ 2 ] :size	 
 BOOL astRandomFlag ;	 
 UINT8 multiVol ; // for log_parition	 
 UINT8 reserved1_1 ;	 
 UINT8 reserved1_2 ;	 
 UINT8 reserved1_3 ;	 
 UINT32 reserved2 ;	 
 UINT32 reserved3 ;	 
	 
 } uartCfgDataS;

typedef UINT32 GpcChHandle ;
