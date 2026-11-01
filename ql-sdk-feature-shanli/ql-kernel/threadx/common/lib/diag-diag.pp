//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_API.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_API.c
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef unsigned int size_t ;
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
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_API_var.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_API_var.c
typedef va_list __gnuc_va_list ;
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
typedef unsigned int size_t ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
typedef unsigned int size_t ;
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
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
DIAG_FILTER ( SW_PLAT , DIAG , ERROR_PRINTFTYPE , DIAG_ERROR)  
 diagTextPrintf ( " DIAG - problem in diagPrintfthe - Report Param Info -> Type is wrong " );

DIAG_FILTER ( SW_PLAT , DIAG , ERROR_PRINTFTYPE , DIAG_ERROR)  
 diagTextPrintf ( " DIAG - problem in diagPrintfthe - Report Param Info -> Type is wrong " );

DIAG_FILTER ( SW_PLAT , DIAG , PRINTF_ERROR_IN_PARAMS_NUMBER , DIAG_FATAL_ERROR)  
 diagTextPrintf ( " DIAG - problem in diagPrintf - the Report Params number is wrong , API called is printf - but the code is for another API " );

DIAG_FILTER ( SW_PLAT , DIAG , PRINTF_LENGTH_ERROR , DIAG_FATAL_ERROR)  
 diagPrintf ( " The Diag msg [ msg Id %lu , length %lu ] is too long " , localReportID , reportDataLength );

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_buff.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_buff.c
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
typedef unsigned int size_t ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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

typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
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

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

//ICAT EXPORTED FUNCTION - Diag , Debug , LostMSGdata 
 void LostMSGdata ( void ) 
 {	 
DIAG_FILTER ( Diag , Utils , LostMsg_1 , REPORT)  
 diagPrintf ( " Lost messages / bytes: MEM: %lu / %lu , ExtQ: %lu / %lu ( size:%d ) , IntQ: %lu / %lu ( size:%d ) , CMIQ: %lu / %lu ( size:%d ) , rx-task %lu / %lu ( size:%d ) " , 
 _diagInternalData.diagNumberOfTracesMEMLostTotal , 
 _diagInternalData.diagNumberOfTracesMEMLostBytes , 
 _diagInternalData.diagNumberOfTracesExtQLostTotal , 
 _diagInternalData.diagNumberOfTracesExtQLostBytes , 
 _diagExtIfQPtrData->diagNumOfItemsAllowedOnQ , 
 _diagInternalData.diagNumberOfTracesIntQLostTotal , 
 _diagInternalData.diagNumberOfTracesIntQLostBytes , 
 
 ( ( _diagIntIfQPtrData ) ?_diagIntIfQPtrData->diagNumOfItemsAllowedOnQ:0 ) , 
 
 
 
 _diagInternalData.diagNumberOfTracesCMIQLostTotal , 
 _diagInternalData.diagNumberOfTracesCMIQLostBytes , 
 ( ( _diagCMIfQPtrData ) ?_diagCMIfQPtrData->diagNumOfItemsAllowedOnQ:0 ) , 
 _diagInternalData.diagNumberOfTraceRxTaskLostTotal , 
 _diagInternalData.diagNumberOfTraceRxTaskLostBytes , 
 0x0a 
 );

	 
 // add data of CMI interface is exist...	 
 }

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_statistics_active ;	 
 UINT32 CP_Bytes_For_stat_collection ;	 
 } setCPbytes_S;

//ICAT EXPORTED FUNCTION - Diag , Debug , StatsSetCPBytes 
 void StatsSetCPBytes ( setCPbytes_S * ptr ) 
 {	 
 UINT32 oldval=d_stat_internal.CP_trace_bytes_for_statistics_period ;	 
	 
 d_stat_internal.CP_trace_statistics = ptr->CP_statistics_active ;	 
	 
 if ( ptr->CP_Bytes_For_stat_collection )	 
 d_stat_internal.CP_trace_bytes_for_statistics_period=ptr->CP_Bytes_For_stat_collection ;	 
	 
DIAG_FILTER ( Diag , Debug , SetCPBytes , REPORT)  
 diagPrintf ( " COMM statistcis collection is %d , every %ld bytes ( old val %ld bytes ) " , 
 d_stat_internal.CP_trace_statistics , 
 d_stat_internal.CP_trace_bytes_for_statistics_period , oldval );

	 
	 
 }

//ICAT EXPORTED FUNCTION - Diag , Debug , StatsTestCPonly 
 void StatsTestCPonly ( void ) 
 {	 
DIAG_FILTER ( Diag , Debug , CP_AP_Statistics , REPORT)  
 diagStructPrintf ( " Stats %S { DiagStats_CP_AP_S } " , &d_stat_CP_AP , sizeof ( DiagStats_CP_AP_S ) );

	 
 }

//ICAT EXPORTED FUNCTION - Diag , Debug , StatsGetCP_Q 
 void StatsGetCPQ ( void ) 
 {	 
	 
 UINT32 numberOfQuickBuffs , i , j ;	 
 UINT32 firstQuickBuf ;	 
 UINT32 cpsr ;	 
	 
 diag_lock ( &cpsr ) ;	 
 numberOfQuickBuffs= ( _diagIntIfQQPtrData.diagTotalNumOfItems ) ;	 
 firstQuickBuf=_diagIntIfQQPtrData.NextItemToSend ;	 
 diag_unlock ( cpsr ) ;	 
	 
DIAG_FILTER ( Diag , DEB , STATS_DATA06 , INFORM)  
 diagPrintf ( " statistics INT run: Num buffs in Quick Q %d ( first=%d ) " , 
 numberOfQuickBuffs , firstQuickBuf );

	 
	 
 if ( numberOfQuickBuffs )	 
 {		 
 for ( i=firstQuickBuf , j=0 ; j<numberOfQuickBuffs && i<10 ; i++ )		 
 {			 
DIAG_FILTER ( Diag , DEB , STATS_DATA04 , INFORM)  
 diagPrintf ( " Quick Bufs ind %d , total %d , len %d " , 
 i , 
 numberOfQuickBuffs , 
 _diagIntIfQQReportsList [ i ] .reportLength 
 );

			 
DIAG_FILTER ( Diag , DEB , STATS_DATA05 , INFORM)  
 diagStructPrintf ( " statistics INT: %S " , _diagIntIfQQReportsList [ i ] .virtualReportPtr , _diagIntIfQQReportsList [ i ] .reportLength );

			 
 }		 
 }	 
 }

//ICAT EXPORTED FUNCTION - Diag , Debug , StatsGetParams 
 void StatsGetParams ( void ) 
 {	 
	 
DIAG_FILTER ( Diag , Debug , StatsGetParams , REPORT)  
 diagPrintf ( " Stats Multiplier for average byte calc %ld sizeStruct %d , ( CP: active=%d , bytes-period=%ld ) " , 
 32768 , 
 sizeof ( DiagStats_CP_AP_S ) , 
 d_stat_internal.CP_trace_statistics , 
 d_stat_internal.CP_trace_bytes_for_statistics_period 
 );

	 
 }

//ICAT EXPORTED FUNCTION - Diag , Debug , DiagLossCountPrintf 
 void DiagLossCountPrintf ( void ) 
 {	 
DIAG_FILTER ( Diag , Debug , DiagLoss , DIAG_INFORMATION)  
 diagPrintf ( " Diag loss count is %ld " , diag_loss_count );

	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_init.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_init.c
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PMU_POR = 1 ,	 
 PMU_EMR ,	 
 PMU_WDTR = ( PMU_EMR+2 )	 
 } PMU_LastResetStatus;

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
DIAGM_TRACE( DIAG , INIT , UP , " Diag is up and running " );  
DIAG_FILTER ( SW_PLAT , DIAG , CREATE_TASK_ERROR , DIAG_FATAL_ERROR)  
 diagPrintf ( " DIAG - Rx task creation is failed , the return status is %d " , status );

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_header_handler.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_header_handler.c
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
typedef unsigned int size_t ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_restore_fixups.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_restore_fixups.c
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
typedef unsigned int size_t ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_rx.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_rx.c
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
typedef unsigned int size_t ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
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
DIAG_FILTER ( Diag , Utils , diagTransferDiagDB_Resp , TRACE_CHECK)  
 diagPrintf ( " Command ( diagTransferDiagDB ) - not supported " );

//ICAT EXPORTED FUNCTION - SW_PLAT , AAAP , diagDisableAllFilter 
 void diagDisableAllFilter ( void ) 
 {	 
 int i ;	 
 UINT32 cpsr ;	 
 UINT8 *tmp1 , *tmp2 ;	 
	 
 // This part is not relevant for CMI clients , but we don ' t save anything if we check this for the master.	 
 tmp1=disableFilterArray ;	 
 tmp2=enableFilterArray ;	 
	 
 diag_lock ( &cpsr ) ;	 
	 
 // This part is not relevant for CMI clients , but we don ' t save anything if we check this for the master.	 
 if ( filteringState!=SPLIT_FILTER_STATE_ARRAY ) filteringState=SPLIT_FILTER_STATE_DISABLE_ALL ;	 
 disableFilterArray=0 ;	 
 enableFilterArray =0 ;	 
 en_dis_ableFilterArrayLength=0 ;	 
	 
 for ( i = 0 ; i < ( ( diagNumOfReports / 8 ) +1 ) ; i++ )	 
 {		 
 filterArray [ i ] = 0xff ; // 0xff means filter i.e. disable		 
 }	 
 diag_unlock ( cpsr ) ;	 
	 
 // CMI support	 
 if ( diagIntData.m_bIsMaster )	 
 {		 
 if ( tmp1 )		 
 {			 
 DiagAlignFree ( ( void * ) tmp1 ) ;			 
 tmp1=0 ;			 
 }		 
 if ( tmp2 )		 
 {			 
 DiagAlignFree ( ( void * ) tmp2 ) ;			 
 tmp2=0 ;			 
 }		 
 FilterAllCMM [ 5 ] =0 ; // 1 -enable ; 0 -disable		 
 FilterAllCMM2All ( ) ;		 
 }	 
	 
 return ;	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , AAAP , diagEnableAllFilter 
 void diagEnableAllFilter ( void ) 
 {	 
	 
 int i ;	 
 UINT32 cpsr ;	 
 UINT8 *tmp1 , *tmp2 ;	 
	 
 // This part is not relevant for CMI clients , but we don ' t save anything if we check this for the master.	 
 tmp1=disableFilterArray ;	 
 tmp2=enableFilterArray ;	 
	 
 diag_lock ( &cpsr ) ;	 
	 
 // This part is not relevant for CMI clients , but we don ' t save anything if we check this for the master.	 
 if ( filteringState!=SPLIT_FILTER_STATE_ARRAY ) filteringState=SPLIT_FILTER_STATE_ENABLE_ALL ;	 
 disableFilterArray=0 ;	 
 enableFilterArray =0 ;	 
 en_dis_ableFilterArrayLength=0 ;	 
	 
 for ( i = 0 ; i < ( ( diagNumOfReports / 8 ) +1 ) ; i++ )	 
 {		 
 filterArray [ i ] =0 ; // 0 means don ' t filter i.e. enable		 
 }	 
 diag_unlock ( cpsr ) ;	 
	 
 // CMI support	 
 if ( diagIntData.m_bIsMaster )	 
 {		 
 if ( tmp1 )		 
 {			 
 DiagAlignFree ( ( void * ) tmp1 ) ;			 
 tmp1=0 ;			 
 }		 
 if ( tmp2 )		 
 {			 
 DiagAlignFree ( ( void * ) tmp2 ) ;			 
 tmp2=0 ;			 
 }		 
 FilterAllCMM [ 5 ] =1 ; // 1 -enable ; 0 -disable		 
 FilterAllCMM2All ( ) ;		 
 }	 
	 
 return ;	 
 }

DIAGM_TRACE( SW_PLAT , BOOT , BOOT_TO_START , " Bootloader is activated , target will be reset now " );  
DIAGM_TRACE( SW_PLAT , BOOT , BOOT_NOT_SUPPORTED , " The functionality is not supported for this Platform " );  
DIAG_FILTER ( SW_PLAT , DIAG , RX_SERVICEID_WRONG , DIAG_FATAL_ERROR)  
 diagPrintf ( " DIAG - msg received with wrong RX service ID , the serviceID is %d " , serviceID );

DIAG_FILTER ( SW_PLAT , DIAG , DIAG_RX_COMM_ALLOCBUF_ERROR , DIAG_FATAL_ERROR)  
 diagPrintf ( " DIAG_rx_COMMAND - Prev message was not freed ( len=%d , rx-if=%d ) " , 
 RxMsgFromIf [ comind ] .dataLen , RxMsgFromIf [ comind ] .rxIF );

DIAG_FILTER ( SW_PLAT , DIAG , DIAG_RX_COMM_ALLOC_FAIL , DIAG_FATAL_ERROR)  
 diagPrintf ( " DIAG_rx_COMMAND - Could not alloc ( len=%d , tries=%d , rx-if=%d ) " , 
 p_packet->total_bytes_expected , 
 tries , 
 p_packet->rxIF );

DIAG_FILTER ( SW_PLAT , DIAG , DIAG_RX_COMM_MEM_CORRUPT_PREVENT , DIAG_FATAL_ERROR)  
 diagPrintf ( " DIAG diagReceiveCommand: A memory corruption was prevented!!! %d+%d>%d " , 
 RxMsgFromIf [ comind ] .dataLen , length , memGuard [ comind ] );

DIAG_FILTER ( SW_PLAT , DIAG , DIAG_RX_COMM_MSG_TO_Q_FAIL , DIAG_FATAL_ERROR)  
 diagPrintf ( " DIAG_rx_COMMAND - msg was not stored in RXMsgQ. Status=%d ( len=%d , tries=%d , rx-if=%d ) " , 
 status , 
 p_packet->total_bytes_expected , 
 tries , 
 p_packet->rxIF );

DIAG_FILTER ( SW_PLAT , DIAG , DIAG_CMI_CMND_FAIL , DIAG_ERROR)  
 diagPrintf ( " DIAG_CMI_COMMAND - Client is not registered ( MsgID=%d ) " , MessageID );

DIAG_FILTER ( SW_PLAT , DIAG , DIAG_CMI_ALLOC_FAIL , DIAG_FATAL_ERROR)  
 diagPrintf ( " DIAG_CMI_COMMAND - Could not alloc ( len=%d , tries=%d , cmi-client=%d ) " , 
 4 +longMsg->dataLen , 
 tries , 
 clientID );

DIAG_FILTER ( SW_PLAT , DIAG , RX_BAD_FIXUPS , DIAG_FATAL_ERROR)  
 diagPrintf ( " DIAG - problem with fixup ' s in moduleID %d commandID %d " , GetRxMsgModuleID ( longMsg.data ) , ( UINT8 ) ( MessageID ) );

DIAG_FILTER ( SW_PLAT , DIAG , RX_SAP_WRONG_CMI1 , DIAG_FATAL_ERROR)  
 diagPrintf ( " DIAG - msg received with wrong RX SAP ( CMI ) , the DiagSAP is %d " , GetRxMsgDiagSap ( longMsg.data ) );

DIAG_FILTER ( SW_PLAT , DIAG , RX_SAP_WRONG_CMI2 , DIAG_FATAL_ERROR)  
 diagPrintf ( " DIAG - msg received with wrong RX SAP ( CMI ) , the DiagSAP is %d " , GetRxMsgDiagSap ( longMsg.data ) );

DIAG_FILTER ( SW_PLAT , DIAG , RX_SAP_WRONG , DIAG_FATAL_ERROR)  
 diagPrintf ( " DIAG - msg received with wrong RX SAP , the DiagSAP is %d " , GetRxMsgDiagSap ( longMsg.data ) );

//ICAT EXPORTED FUNCTION - SW_PLAT , AAAP , filterReport 
 void filterReport ( void *p ) 
 {	 
 reportFilterStatus *pFilter= ( reportFilterStatus* ) p ;	 
 UINT16 id=pFilter->commandID ;	 
 UINT16 index = ( ( ( UINT16 ) ( id ) ) >>3 ) ;	 
 UINT8 mask = ( 1 << ( ( ( UINT8 ) ( id%8 ) ) ) ) ;	 
 UINT8 filterMode= ( UINT8 ) pFilter->isFiltered ; // since ACAT sometimes sends only 1 byte - lets cast ( fixed in ACAT dec 2007 )	 
 UINT32 cpsr ;	 
	 
 diag_lock ( &cpsr ) ; // TBDIY this is a " big " lock , try to reduce the locking time!!!	 
	 
 if ( diagIntData.m_bIsMaster && id>diagNumOfReports ) // TBDIY no need to maintain filter arrays for the master itself	 
 {		 
 // Prepare the en / dis / ableFilterArray: malloc or realloc to a bigger array as necessary.		 
 if ( disableFilterArray==0 ) // if disableFilterArray==NULL then also enableFilterArray==NULL		 
 { // malloc en / dis / ableFilterArray			 
 en_dis_ableFilterArrayLength= ( id+8 ) / 8 ;			 
 disableFilterArray=DiagAlignMalloc ( en_dis_ableFilterArrayLength ) ;			 
 enableFilterArray =DiagAlignMalloc ( en_dis_ableFilterArrayLength ) ;			 
 if ( disableFilterArray && enableFilterArray )			 
 {				 
 // fprintf ( stderr , " ***** DIAG Master - DiagAlignMalloc succeeded for en / dis / ableFilterArray ena=0x%x dis=0x%x *****\r\n " ,				 
 // disableFilterArray , enableFilterArray ) ;				 
 memset ( disableFilterArray , 0 , en_dis_ableFilterArrayLength ) ;				 
 memset ( enableFilterArray , 0 , en_dis_ableFilterArrayLength ) ;				 
 } else			 
 {				 
 en_dis_ableFilterArrayLength=0 ;				 
 if ( disableFilterArray )				 
 {					 
 DiagAlignFree ( ( void * ) disableFilterArray ) ;					 
 disableFilterArray=0 ;					 
 }				 
 if ( enableFilterArray )				 
 {					 
 DiagAlignFree ( ( void * ) enableFilterArray ) ;					 
 enableFilterArray=0 ;					 
 }				 
 fprintf ( ( & __stderr ) , " ***** DIAG Master - DiagAlignMalloc failed for en / dis / ableFilterArray *****\r\n " ) ;				 
 }			 
 } else if ( en_dis_ableFilterArrayLength< ( id+8 ) / 8 )		 
 { // realloc en / dis / ableFilterArray			 
 UINT8 *tmp_dis , *tmp_ena ;			 
			 
 tmp_dis=DiagAlignMalloc ( ( id+8 ) / 8 ) ;			 
 tmp_ena=DiagAlignMalloc ( ( id+8 ) / 8 ) ;			 
 if ( tmp_dis && tmp_ena )			 
 {				 
 memcpy ( tmp_dis , disableFilterArray , en_dis_ableFilterArrayLength ) ;				 
 memcpy ( tmp_ena , enableFilterArray , en_dis_ableFilterArrayLength ) ;				 
 memset ( tmp_dis+en_dis_ableFilterArrayLength , 0 , ( ( id+8 ) / 8 ) -en_dis_ableFilterArrayLength ) ;				 
 memset ( tmp_ena+en_dis_ableFilterArrayLength , 0 , ( ( id+8 ) / 8 ) -en_dis_ableFilterArrayLength ) ;				 
 // fprintf ( stderr , " ***** DIAG Master - DiagAlignFree for en / dis / ableFilterArray ena=0x%x dis=0x%x *****\r\n " ,				 
 // disableFilterArray , enableFilterArray ) ;				 
 DiagAlignFree ( ( void * ) disableFilterArray ) ;				 
 disableFilterArray=tmp_dis ;				 
 DiagAlignFree ( ( void * ) enableFilterArray ) ;				 
 enableFilterArray =tmp_ena ;				 
 en_dis_ableFilterArrayLength= ( id+8 ) / 8 ;				 
 fprintf ( ( & __stderr ) , " ***** DIAG Master - ( Re ) DiagAlignMalloc succeeded for en / dis / ableFilterArray *****\r\n " ) ;				 
 } else			 
 {				 
 if ( tmp_dis )				 
 {					 
 DiagAlignFree ( ( void * ) tmp_dis ) ;					 
 tmp_dis=0 ;					 
 }				 
 if ( tmp_ena )				 
 {					 
 DiagAlignFree ( ( void * ) tmp_ena ) ;					 
 tmp_ena=0 ;					 
 }				 
 DiagAlignFree ( ( void * ) disableFilterArray ) ;				 
 disableFilterArray=0 ;				 
 DiagAlignFree ( ( void * ) enableFilterArray ) ;				 
 enableFilterArray=0 ;				 
 en_dis_ableFilterArrayLength=0 ;				 
 fprintf ( ( & __stderr ) , " ***** DIAG Master - ( Re ) DiagAlignMalloc failed for en / dis / ableFilterArray *****\r\n " ) ;				 
 }			 
 }		 
		 
 if ( disableFilterArray ) // if disableFilterArray!=NULL then also enableFilterArray!=NULL		 
 {			 
 fprintf ( ( & __stderr ) , " ***** DIAG Master - filterMode=%d index=%d mask=0x%x *****\r\n " , filterMode , index , mask ) ;			 
 if ( filterMode )			 
 {				 
 enableFilterArray [ index ] |= mask ;				 
 disableFilterArray [ index ] &= ~mask ;				 
 } else			 
 {				 
 enableFilterArray [ index ] &= ~mask ;				 
 disableFilterArray [ index ] |= mask ;				 
 }			 
 }		 
		 
 // handle the filtering state machine		 
 if ( filteringState==SPLIT_FILTER_STATE_NONE )		 
 {			 
 filteringState=SPLIT_FILTER_STATE_REPORT_NONE ;			 
 fprintf ( ( & __stderr ) , " ***** DIAG Master - SPLIT_FILTER_STATE_REPORT_NONE *****\r\n " ) ;			 
 }		 
 if ( filteringState==SPLIT_FILTER_STATE_ENABLE_ALL )		 
 {			 
 filteringState=SPLIT_FILTER_STATE_REPORT_ENABLE_ALL ;			 
 fprintf ( ( & __stderr ) , " ***** DIAG Master - SPLIT_FILTER_STATE_REPORT_ENABLE_ALL *****\r\n " ) ;			 
 }		 
 if ( filteringState==SPLIT_FILTER_STATE_DISABLE_ALL )		 
 {			 
 filteringState=SPLIT_FILTER_STATE_REPORT_DISABLE_ALL ;			 
 fprintf ( ( & __stderr ) , " ***** DIAG Master - SPLIT_FILTER_STATE_REPORT_DISABLE_ALL *****\r\n " ) ;			 
 }		 
 }	 
	 
 // 1 . check value is zero or 1 only.	 
 // 2 . lock for update of filter table.	 
 if ( id<=diagNumOfReports )	 
 {		 
 if ( filterMode )		 
 {			 
 filterArray [ index ] |= mask ;			 
 } else		 
 {			 
 filterArray [ index ] &= ~mask ;			 
 }		 
 }	 
	 
 diag_unlock ( cpsr ) ; // TBDIY this is a " big " lock , try to reduce the locking time!!!	 
	 
 if ( diagIntData.m_bIsMaster && id>diagNumOfReports ) // TBDIY should be > and NOT >= ???	 
 {		 
 UINT8 clientID=DIAG_COMMDEV_NODEVICE ;		 
 UINT32 i ;		 
		 
 // 1 . Resolve the clientID from the master internal database:		 
 for ( i=0 ; i<5 ; i++ )		 
 {			 
 // TBDIY distClientDB should be initialized - this is global and initialized to 0 =CMI_FREE by default.			 
 if ( distClientDB [ i ] .clientStat == CMI_REGISTERED &&			 
 distClientDB [ i ] .firstReportID <= id &&			 
 distClientDB [ i ] .lastReportID >= id )			 
 {				 
 clientID=DIAG_COMMDEV_CMI+i ;				 
 break ;				 
 }			 
 }		 
 if ( clientID==DIAG_COMMDEV_NODEVICE )		 
 {			 
 // Resolving Failed			 
 fprintf ( ( & __stderr ) , " ***** DIAG Master Filter Report - Client is not registered ( reportID=%d ) *****\r\n " , id ) ;			 
 } else		 
 {			 
 fprintf ( ( & __stderr ) , " ***** DIAG Master Filter Report - Client %d filter [ %d ] =%d *****\r\n " , clientID , id , filterMode ) ;			 
 diagFilterSpecificCMM ( clientID , id , filterMode ) ;			 
 }		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , DIAG , Disconnect 
 void diagDisconnectIcat ( void ) 
 {	 
 diagDisconnectIcatInt ( 0 ) ;	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , DIAG , setDiagFilterArray 
 void setDiagFilterArray ( void *filter , UINT16 length ) 
 {	 
 diagSetFilter ( filter , length ) ;	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , DIAG , getDiagFilterArray 
 void getDiagFilterArray ( void ) 
 {	 
	 
 int size = ( ( diagNumOfReports / 8 ) +1 ) ;	 
	 
DIAG_FILTER ( SW_PLAT , DIAG , FILTER_ARRAY_REPORT , INFO)  
 diagStructPrintf ( " %S " , ( char * ) ( filterArray ) , size );

	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_rx_OSA_NUCLEUS.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_rx_OSA_NUCLEUS.c
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
typedef unsigned int size_t ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
DIAG_FILTER ( SW_PLAT , DIAG , COMMANDID_WRONG , DIAG_ERROR)  
 diagPrintf ( " DIAG - command received with ID out of range: %d " , fID );

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_tx.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_tx.c
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef unsigned int size_t ;
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
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

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

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

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
//ICAT EXPORTED FUNCTION - SW_PLAT , DIAG , DiagSendFullFN 
 void DiagSendFullFN ( void ) 
 {	 
 gFlg.FrameNumberExist = 1 ;	 
	 
DIAG_FILTER ( SW_PLAT , DIAG , DiagSendFullFN_Called , DIAG_INFORMATION)  
 diagPrintf ( " Usage of FULL Frame Number is set. " );

	 
 return ;	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_Utils.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_Utils.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
//ICAT EXPORTED STRUCT 
 typedef struct {	 
 /// *COMDEV_NAME* / UINT8 connectedDev ;	 
 diagErrStatesE err_state ;	 
 UINT32 num_lost ;	 
 } diagSimulErrMsg_S;

//ICAT EXPORTED FUNCTION - Diag , Utils , OutMsgBodyLimit 
 UINT32 diagGetOutMsgBodyLimit ( void ) 
 {	 
	 
 // YK change -100 to value of FOOTER+HEADER ( sizeof ( TxPDU ) +TX_PDU_FOOTER_SIZE )	 
 UINT32 msgBodySize = ( _diagInternalData.MsgLimits.diagMaxMsgOutLimit - 100 ) ; /* deduct 100 bytes ~= message header overhead */	 
	 
 // MB - This should be set to the corrcet value depending on te header used.	 
 // At this point this is a work around for the worst case. ( ethernet-l2 / l4 )	 
 msgBodySize = 4096 - 100 ;	 
	 
	 
	 
	 
	 
DIAG_FILTER ( Diag , Utils , MaxOutMsgBodySize , DIAG_INFORMATION)  
 diagPrintf ( " diag ( target ) to ACAT: %ld " , msgBodySize );

	 
	 
 return msgBodySize ;	 
 }

//ICAT EXPORTED FUNCTION - Diag , Utils , InMsgBodyLimit 
 UINT32 diagGetInMsgBodyLimit ( void ) 
 {	 
 // YK change -100 to value of FOOTER+HEADER ( sizeof ( TxPDU ) +TX_PDU_FOOTER_SIZE )	 
 UINT32 msgBodySize = ( _diagInternalData.MsgLimits.diagMaxMsgInLimit - 100 ) ; /* deduct 100 bytes ~= message header overhead */	 
	 
	 
 // on old header , we have limitation of different interfaces , the L2 / L4 is limited to 4096 bytes form ACAT to diag ( target )	 
	 
 extern UINT32 clr_minBuffToSend ;	 
 if ( ( clr_minBuffToSend ) && ( diagIntData.m_eConnectionType == tUSBConnection ) && ( diagIntData.m_eLLtype == tLL_USB ) )	 
 ;	 
 else	 
	 
 msgBodySize = 4096 - 100 ;	 
	 
	 
	 
	 
	 
DIAG_FILTER ( Diag , Utils , MaxInMsgBodySize , DIAG_INFORMATION)  
 diagPrintf ( " ACAT to diag ( target ) : %ld " , msgBodySize );

	 
	 
 return msgBodySize ;	 
 }

//ICAT EXPORTED FUNCTION - Diag , Debug , ResetDiagBuffers 
 void ResetDiagBuffers ( void ) 
 {	 
	 
	 
	 
 DiagCommExtIfResetQueue ( ) ;	 
	 
	 
	 
 DiagCommIntIfResetQueue ( ) ;	 
	 
 }

//ICAT EXPORTED FUNCTION - Diag , Utils , MsgLimitDisp 
 void MsgLimitDisp ( void ) 
 {	 
DIAG_FILTER ( Diag , Utils , MsgLimitDisp_1 , INFORM)  
 diagPrintf ( " Limits are OUT MSG: %ld ( limit ) , %ld ( signal ) " , 
 _diagInternalData.MsgLimits.diagMaxMsgOutLimit , 
 _diagInternalData.MsgLimits.diagMaxMsgOutWarning 
 );

	 
	 
DIAG_FILTER ( Diag , Utils , MsgLimitDisp_2 , INFORM)  
 diagPrintf ( " Limits are IN MSG: %ld ( limit ) , %ld ( signal ) " , 
 _diagInternalData.MsgLimits.diagMaxMsgInLimit , 
 _diagInternalData.MsgLimits.diagMaxMsgInWarning 
 );

	 
 }

//ICAT EXPORTED FUNCTION - Diag , Utils , MsgLimitSet 
 void MsgLimitSet ( diagMsgLimitSet_S *ptr ) 
 {	 
 if ( ptr )	 
 {		 
 // set values only if they are not zero ( if zero , leave current values )		 
 if ( ptr->diagMaxMsgOutLimit )		 
 {			 
 _diagInternalData.MsgLimits.diagMaxMsgOutLimit = ptr->diagMaxMsgOutLimit ;			 
 }		 
 if ( ptr->diagMaxMsgOutWarning )		 
 {			 
 _diagInternalData.MsgLimits.diagMaxMsgOutWarning= ptr->diagMaxMsgOutWarning ;			 
 }		 
 if ( ptr->diagMaxMsgInLimit )		 
 {			 
 _diagInternalData.MsgLimits.diagMaxMsgInLimit = ptr->diagMaxMsgInLimit ;			 
 }		 
 if ( ptr->diagMaxMsgInWarning )		 
 {			 
 _diagInternalData.MsgLimits.diagMaxMsgInWarning = ptr->diagMaxMsgInWarning ;			 
 }		 
 }	 
 MsgLimitDisp ( ) ;	 
	 
 fprintf ( ( & __stderr ) , " ***** DIAG MsgLimitSet OutLimit=%d OutWarning=%d InLimit=%d InWarning=%d *****\r\n " ,	 
 _diagInternalData.MsgLimits.diagMaxMsgOutLimit ,	 
 _diagInternalData.MsgLimits.diagMaxMsgOutWarning ,	 
 _diagInternalData.MsgLimits.diagMaxMsgInLimit ,	 
 _diagInternalData.MsgLimits.diagMaxMsgInWarning ) ;	 
	 
 if ( diagIntData.m_bIsMaster ) // Advertise the change to all the registered clients	 
 {		 
 SetMsgLimitCMM [ 5 ] =_diagInternalData.MsgLimits.diagMaxMsgOutLimit ;		 
 SetMsgLimitCMM [ 6 ] =_diagInternalData.MsgLimits.diagMaxMsgOutWarning ;		 
 SetMsgLimitCMM [ 7 ] =_diagInternalData.MsgLimits.diagMaxMsgInLimit ;		 
 SetMsgLimitCMM [ 8 ] =_diagInternalData.MsgLimits.diagMaxMsgInWarning ;		 
 SetMsgLimitCMM2All ( ) ;		 
 }	 
 }

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 Sunday=0 ,	 
 Monday ,	 
 Tuesday ,	 
 Dummy_day=0xFFFFF // dummy event to force events to occupy in 4 bytes word	 
 } Days;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 a ;	 
 UINT32 b ;	 
 } a_b;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 BVE1 = 1 ,	 
 BVE2 ,	 
 BVE3 ,	 
 BVE4 ,	 
 BVE5 ,	 
 BVE127 = 127 ,	 
 BVE253 = 253	 
 } Test_byteVals_E;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 SVE1 = 1 ,	 
 SVE2 ,	 
 SVE3 ,	 
 SVE4 ,	 
 SVE5 ,	 
 SVE127 = 127 ,	 
 SVE253 = 253 ,	 
 SVE511 = 511 ,	 
 SVE32765 = 32765 ,	 
 SVE57343 = 57343	 
 } Test_shortVals_E;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 LVE1 = 1 ,	 
 LVE2 ,	 
 LVE3 ,	 
 LVE4 ,	 
 LVE5 ,	 
 LVE127 = 127 ,	 
 LVE253 = 253 ,	 
 LVE511 = 511 ,	 
 LVE32767 = 327657 ,	 
 LVE57343 = 57343 ,	 
 LVE2147483647 = 2147483647 // 7 FFFFFFF	 
 } Test_longVals_E;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 a ;	 
 UINT8 b ;	 
 } 
 TestUint8_2_Struct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 a ;	 
 UINT16 b ;	 
 } 
 TestUint16_2_Struct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 a ;	 
 UINT32 b ;	 
 } 
 TestUint32_2_Struct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Test_byteVals_E e_val ;	 
 UINT8 b1 ;	 
 UINT8 b2 ;	 
 UINT32 l3 ;	 
 } 
 TestEnum8_Struct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Test_shortVals_E e_val ;	 
 UINT8 b1 ;	 
 UINT8 b2 ;	 
 UINT32 l3 ;	 
 } 
 TestEnum16_Struct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Test_longVals_E e_val ;	 
 UINT8 b1 ;	 
 UINT8 b2 ;	 
 UINT32 l3 ;	 
 } 
 TestEnum32_Struct;

//ICAT EXPORTED FUNCTION - Diag , Utils , getIfDataStat 
 void getIfDataStat ( void ) 
 {	 
DIAG_FILTER ( Diag , Utils , ExtIfTxMulti , INFO)  
 diagPrintf ( " diagIntData.m_extIfTxMulti==%d " , diagIntData.m_extIfTxMulti );

	 
	 
DIAG_FILTER ( Diag , Utils , ExtIfData1 , INFO)  
 diagPrintf ( " External Interface %e { EActiveConnectionType } ( %e { EActiveConnectionLL_Type } ) , is-connected %d " , 
 diagIntData.m_eConnectionType , 
 diagIntData.m_eLLtype , 
 IsDeviceConnctedExternally ( ) 
 );

	 
	 
DIAG_FILTER ( Diag , Utils , IntIfData1 , INFO)  
 diagPrintf ( " Internal Interface %e { EActiveConnectionType } ( %e { EActiveConnectionLL_Type } ) , is-connected %d " , 
 diagIntData.m_eIntConnectionType , 
 diagIntData.m_eIntLLtype , 
 IsDeviceConnctedInternally ( ) 
 );

	 
 }

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT16 command_ref ; // number of command to activate	 
 UINT16 total_command_size ; // size of the command data	 
 UINT16 current_chunk_size ; // size of hte current chunk ( of the command data )	 
 UINT8 current_chunk_number ; // number of chunk ( 1 to total_number_of_chunks )	 
 UINT8 total_number_of_chunks ; // total of chunks which will be sent for this command	 
 UINT8 data [ 1 ] ; // the data itself of the current chunk	 
 } command_data_chunk_S;

DIAG_FILTER ( Diag , CommandAssemblyFailure , respond03 , REPORT)  
 diagPrintf ( " Expecting command first , but: %d , chunk %d / %d , size %d ( size recieved: %d ) / %d " , 
 ptr->command_ref , 
 ptr->current_chunk_number , 
 ptr->total_number_of_chunks , 
 ptr->current_chunk_size , 
 size , 
 ptr->total_command_size 
 );

DIAG_FILTER ( Diag , CommandAssemblyFailure , respond04 , REPORT)  
 diagPrintf ( " Command subsequent: %d not equal current %d " , 
 ptr->command_ref , 
 current_data.command_ref 
 );

DIAG_FILTER ( Diag , CommandAssemblyFailure , respond05 , REPORT)  
 diagPrintf ( " Command subsequent chunk %d does not match next chunk %d " , 
 current_data.current_chunk_number+1 , 
 ptr->current_chunk_number 
 );

DIAG_FILTER ( Diag , CommandAssemblyFailure , respond06 , REPORT)  
 diagPrintf ( " Command subsequent size %d does not match current %d " , 
 ptr->total_command_size , 
 current_data.total_command_size 
 );

DIAG_FILTER ( Diag , CommandAssemblyFailure , respond07 , REPORT)  
 diagPrintf ( " Command subsequent tot chunk %d does not match %d " , 
 ptr->total_number_of_chunks , 
 current_data.total_number_of_chunks 
 );

DIAG_FILTER ( Diag , CommandAssemblyFailure , respond08 , REPORT)  
 diagPrintf ( " Command subsequent size %d does not match input size %d " , 
 ptr->current_chunk_size , 
 size 
 );

DIAG_FILTER ( Diag , CommandAssemblyFailure , respond09 , REPORT)  
 diagPrintf ( " Command buffer too small ( allocated: %d ) offset %d , current_chunk_size %d " , 
 current_data.total_command_size , 
 current_offset , 
 ptr->current_chunk_size 
 );

DIAG_FILTER ( Diag , CommandAssemblyFailure , respond010 , REPORT)  
 diagPrintf ( " Total chunks size ( including last ) %d is not equal total size %d " , 
 current_offset+ptr->current_chunk_size , 
 current_data.total_command_size 
 );

DIAG_FILTER ( Diag , CommandAssemblyFailure , respond011 , REPORT)  
 diagPrintf ( " Command Buffer NOT ALLOCATED: %d , chunk %d / %d , size %d ( size recieved: %d ) / %d " , 
 ptr->command_ref , 
 ptr->current_chunk_number , 
 ptr->total_number_of_chunks , 
 ptr->current_chunk_size , 
 size , 
 ptr->total_command_size 
 );

DIAG_FILTER ( Diag , CommandAssemblyFailure , respond012 , REPORT)  
 diagPrintf ( " Failure - exiting assembly mode " );

DIAG_FILTER ( Diag , CommandAssemblySuccess , respond013 , REPORT)  
 diagPrintf ( " Command Done: %d , chunk %d / %d , size %d / %d " , 
 ptr->command_ref , 
 ptr->current_chunk_number , 
 ptr->total_number_of_chunks , 
 ptr->current_chunk_size , 
 ptr->total_command_size 
 );

DIAG_FILTER ( Diag , CommandAssemblySuccess , respond014 , REPORT)  
 diagPrintf ( " Command cont: %d , chunk %d / %d , size %d / %d " , 
 ptr->command_ref , 
 ptr->current_chunk_number , 
 ptr->total_number_of_chunks , 
 ptr->current_chunk_size , 
 ptr->total_command_size 
 );

//ICAT EXPORTED FUNCTION - Diag , Utils , ActivateCommandInputInParts 
 void ActivateCommandInputInParts ( command_data_chunk_S *ptr , int size ) 
 {	 
 UINT8 *data=0 ;	 
	 
 if ( size < 8 ) // sizeof ( command_data_chunk_S ) )	 
 {		 
 // print failure - no such command		 
DIAG_FILTER ( Diag , Command_In_Parts , respond01 , REPORT)  
 diagPrintf ( " Failure - size ( %u ) too small " , 
 size );

		 
 // reset the assembly data		 
 release_assembled_command_data ( data ) ;		 
 return ;		 
 }	 
	 
DIAG_FILTER ( Diag , Command_In_Parts , respond02 , REPORT)  
 diagPrintf ( " rx size ( %d ) " , size );

	 
	 
 data=assembly_command_processing ( ptr , size-8 ) ; // size- ( sizeof ( command_data_chunk_S ) -1 ) ) ;	 
 if ( data )	 
 {		 
DIAG_FILTER ( Diag , Command_In_Parts , respond03 , REPORT)  
 diagPrintf ( " Activating command %u. Size of data %u " , 
 ptr->command_ref , 
 ptr->total_command_size );

		 
		 
 diagCommandServer ( /*0 not used , */ ptr->command_ref , ( PackedUnPackedData * ) data , ptr->total_command_size ) ;		 
		 
 release_assembled_command_data ( data ) ;		 
 }	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_mem.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_mem.c
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
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef unsigned int size_t ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef TX_THREAD OS_Task_t ;
typedef TX_SEMAPHORE OS_Sema_t ;
typedef TX_SEMAPHORE OS_Mutex_t ;
typedef TX_TIMER OS_Timer_t ;
typedef TX_EVENT_FLAGS_GROUP OS_EventGroup_t ;
typedef TX_EVENT_FLAGS_GROUP OS_Flag_t ;
typedef void* OS_Hisr_t ;
typedef TX_BYTE_POOL OS_MemPool_t ;
typedef TX_BLOCK_POOL OS_PartitionPool_t ;
typedef STATUS NU_RTN_STATUS ;
typedef UINT32 OS_Proc_t ;
typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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
typedef UINT32 rt_uint32_t ;
typedef UINT8 rt_uint8_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_nvm.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_nvm.c
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
typedef unsigned int size_t ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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
//ICAT EXPORTED ENUM 
 typedef enum {	 
	 
 IMLConfig_OFF=0 ,	 
 IMLConfig_2SD ,	 
 IMLConfig_2DDR ,	 
 IMLConfig_2HSL_BIGBOARD ,	 
 IMLConfig_2HSL_SMALLBOARD ,	 
 IMLConfig_2SU_ENABLE ,	 
 IMLConfig_2SU_DISABLE	 
	 
 } IMLCONFIG_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
	 
 IMLCONFIG_TYPE IMLConfigVal ;	 
	 
 UINT8 DataLen ;	 
 UINT8 data [ 64 ] ;	 
 } IMLCfgDataS;

typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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

typedef UINT32 lfs_size_t ;
typedef UINT32 lfs_off_t ;
typedef int lfs_ssize_t ;
typedef int lfs_soff_t ;
typedef UINT32 lfs_block_t ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPC_DDR_RELQ_REQ = 0x00000001 ,	 
 ACIPC_DDR_RELQ_ACK = 0x00000001 ,	 
 ACIPC_DDR_260_RELQ_REQ = 0x00000002 ,	 
 ACIPC_DDR_260_RELQ_ACK = 0x00000002 ,	 
 ACIPC_MSL_SLEEP_ALLOW = 0x00000004 ,	 
 ACIPC_MSL_WAKEUP_ACK = 0x00000008 ,	 
 ACIPC_MSL_WAKEUP_REQ = 0x00000010 ,	 
 ACIPC_DATA_Q_ADRS = 0x00000020 ,	 
 ACIPC_DATA_IND = 0x00000040 ,	 
 ACIPC_SPARE_1 = 0x00000080 ,	 
 ACIPC_DDR_260_READY_REQ = 0x00000100 ,	 
 ACIPC_DDR_260_READY_ACK = 0x00000100 ,	 
 ACIPC_DDR_READY_REQ = 0x00000200 ,	 
 ACIPC_DDR_READY_ACK = 0x00000200 ,	 
	 
 } ACIPC_EventsE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 DDR_FREQUENCY_104 ,	 
 DDR_FREQUENCY_156 ,	 
 DDR_FREQUENCY_208 ,	 
 DDR_FREQUENCY_312 ,	 
 DDR_FREQUENCY_400 ,	 
 DDR_FREQUENCY_528 ,	 
 DDR_FREQUENCY_NUM ,	 
 DDR_FREQUENCY_INVALID = DDR_FREQUENCY_NUM ,	 
 } DDR_FREQUENCY;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPC_DDR_AVAIL=0x00000001	 
 } ACIPC_FlagsE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPC_CB_NORMAL=0 , /* callback will be called only if the DDR available */	 
 ACIPC_CB_ALWAYS_NO_DDR /* callback will be called always , even if the DDR is not available*/	 
 } ACIPC_CBModeE;

typedef UINT32 ( *ACIPC_RecEventCB ) ( UINT32 eventsStatus ) ;
typedef UINT32 ACIPC_Data ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 _HWDFC_TEST_DISABEL=0 ,	 
 _HWDFC_TEST_ACTIVE_LPM_CORE ,	 
 _HWDFC_TEST_ACTIVE_LPM ,	 
 _HWDFC_TEST_ACTIVE ,	 
 _HWDFC_TEST_CORE ,	 
 _HWDFC_TEST_NEW_API ,	 
 } HWDFC_TEST_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _HWDFC_DISABEL=0 ,	 
 _HWDFC_ENABLE ,	 
 } HWDFC_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 CFG_PP_0 = 0 ,	 
 CFG_PP_1 ,	 
 CFG_PP_2 ,	 
 CFG_PP_3 ,	 
 CFG_PP_4 ,	 
 CFG_PP_5 ,	 
 CFG_PP_6 ,	 
 CFG_PP_7 ,	 
 CFG_PP_AUTO = 0xFF , // CQ00023417	 
 } PP_TYPE;

//ICAT EXPORTED ENUM - add by zhangwl for PP chang - CQ00023417 
 typedef enum {	 
 CPIDLE_0_5 = 5 ,	 
 CPIDLE_1_0 = 10 ,	 
 CPIDLE_1_5 = 15 ,	 
 CPIDLE_2_0 = 20 ,	 
 CPIDLE_2_5 = 25 ,	 
 CPIDLE_3_0 = 30 ,	 
 CPIDLE_3_5 = 35 ,	 
 CPIDLE_4_0 = 40 ,	 
 CPIDLE_4_5 = 45 ,	 
 CPIDLE_5_0 = 50 ,	 
 CPIDLE_5_5 = 55 ,	 
 CPIDLE_6_0 = 60 ,	 
 CPIDLE_6_5 = 65 ,	 
 CPIDLE_7_0 = 70 ,	 
 CPIDLE_7_5 = 75 ,	 
 CPIDLE_8_0 = 80 ,	 
 CPIDLE_8_5 = 85 ,	 
 CPIDLE_9_0 = 90 ,	 
 CPIDLE_9_5 = 95 ,	 
 CPIDLE_DEFAULT = 0xFF ,	 
 } PP_CPIDLE_T;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 LTE_DMA_78M = 0x7F ,	 
 LTE_DMA_156M = 0x5F ,	 
 LTE_DMA_208M = 0x4B ,	 
 LTE_DMA_312M = 0x4F ,	 
 } LTE_DMA_CLOCK;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 VOLTAGE_0_65 = 0x04 ,	 
 VOLTAGE_0_70 = 0x08 ,	 
 VOLTAGE_0_75 = 0x0C ,	 
 VOLTAGE_0_775 = 0x0E ,	 
 VOLTAGE_0_7875 = 0x0F ,	 
 VOLTAGE_0_80 = 0x10 ,	 
 VOLTAGE_0_8125 = 0x11 ,	 
 VOLTAGE_0_825 = 0x12 ,	 
 VOLTAGE_0_8375 = 0x13 ,	 
 VOLTAGE_0_85 = 0x14 ,	 
 VOLTAGE_0_8625 = 0x15 ,	 
 VOLTAGE_0_875 = 0x16 ,	 
 VOLTAGE_0_8875 = 0x17 ,	 
 VOLTAGE_0_90 = 0x18 ,	 
 VOLTAGE_0_9125 = 0x19 ,	 
 VOLTAGE_0_925 = 0x1A ,	 
 VOLTAGE_0_9375 = 0x1B ,	 
 VOLTAGE_0_95 = 0x1C ,	 
 VOLTAGE_0_9625 = 0x1D ,	 
 VOLTAGE_0_975 = 0x1E ,	 
 VOLTAGE_0_9875 = 0x1F ,	 
 VOLTAGE_1_00 = 0x20 ,	 
 VOLTAGE_1_0125 = 0x21 ,	 
 VOLTAGE_1_025 = 0x22 ,	 
 VOLTAGE_1_0375 = 0x23 ,	 
 VOLTAGE_1_05 = 0x24 ,	 
 VOLTAGE_1_0625 = 0x25 ,	 
 VOLTAGE_1_075 = 0x26 ,	 
 VOLTAGE_1_0875 = 0x27 ,	 
 VOLTAGE_1_10 = 0x28 ,	 
 VOLTAGE_1_1125 = 0x29 ,	 
 VOLTAGE_1_125 = 0x2A ,	 
 VOLTAGE_1_1375 = 0x2B ,	 
 VOLTAGE_1_15 = 0x2C ,	 
 VOLTAGE_1_1625 = 0x2D ,	 
 VOLTAGE_1_175 = 0x2E ,	 
 VOLTAGE_1_1875 = 0x2F ,	 
 VOLTAGE_1_20 = 0x30 ,	 
 VOLTAGE_1_2125 = 0x31 ,	 
 VOLTAGE_1_225 = 0x32 ,	 
 VOLTAGE_1_2375 = 0x33 ,	 
 VOLTAGE_1_25 = 0x34 ,	 
 VOLTAGE_1_2625 = 0x35 ,	 
 VOLTAGE_1_275 = 0x36 ,	 
 VOLTAGE_1_2875 = 0x37 ,	 
 VOLTAGE_1_30 = 0x38 ,	 
 VOLTAGE_1_35 = 0x3C ,	 
 VOLTAGE_DEFAULT = 0xFF ,	 
 } PP_VOLTAGE_T;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MIPS_5 = 5 ,	 
 MIPS_1_0 = 10 ,	 
 MIPS_1_5 = 15 ,	 
 MIPS_2_0 = 20 ,	 
 MIPS_2_5 = 25 ,	 
 MIPS_3_0 = 30 ,	 
 MIPS_3_5 = 35 ,	 
 MIPS_4_0 = 40 ,	 
 MIPS_4_5 = 45 ,	 
 MIPS_5_0 = 50 ,	 
 MIPS_5_5 = 55 ,	 
 MIPS_6_0 = 60 ,	 
 MIPS_6_5 = 65 ,	 
 MIPS_7_0 = 70 ,	 
 MIPS_7_5 = 75 ,	 
 MIPS_8_0 = 80 ,	 
 MIPS_8_5 = 85 ,	 
 MIPS_9_0 = 90 ,	 
 MIPS_9_5 = 95 ,	 
 MIPS_MAX = 0xFF ,	 
 } Mips_Threshold;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 PP_TYPE ProductPoint ;	 
 Mips_Threshold HighWaterMark ; // add by zhangwl for PP chang - CQ00023417	 
 Mips_Threshold LowWaterMark ; // add by zhangwl for PP chang - CQ00023417	 
 LTE_DMA_CLOCK LTEDmaClock ;	 
 PP_VOLTAGE_T ActiveVoltage ;	 
 PP_VOLTAGE_T SleepVoltage ;	 
 } LTE_CONFIG_S;

//ICAT EXPORTED STRUCT 
 typedef struct NVM_Header 
 {	 
 unsigned long StructSize ; // the size of the user structure below	 
 unsigned long NumofStructs ; // >1 in case of array of structs ( default is 1 ) .	 
 char StructName [ 64 ] ; // the name of the user structure below	 
 char Date [ 32 ] ; // date updated by the ICAT when the file is saved. Filled by calibration SW.	 
 char time [ 32 ] ; // time updated by the ICAT when the file is saved. Filled by calibration SW.	 
 char Version [ 64 ] ; // user version - this field is updated by the SW eng. Every time they update the UserStruct.	 
 char HW_ID [ 32 ] ; // signifies the board number. Filled by calibration SW.	 
 char CalibVersion [ 32 ] ; // signifies the calibration SW version. Filled by calibration SW.	 
 } NVM_Header_ts;

typedef unsigned int size_t ;
typedef unsigned int clock_t ;
typedef unsigned int time_t ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 second ; // Seconds after minute: 0 - 59	 
 UINT8 minute ; // Minutes after hour: 0 - 59	 
 UINT8 hour ; // Hours after midnight: 0 - 23	 
 UINT8 day ; // Day of month: 1 - 31	 
 UINT8 month ; // Month of year: 1 - 12	 
 UINT16 year ; // Calendar year: e.g 2001	 
 } RTC_CalendarTime;

typedef UINT8 RTC_Handle ;
typedef void ( *RTC_ISR ) ( void ) ;
typedef void ( *RTCOnTimeSetNotifyCallback ) ( RTC_CalendarTime* oldTime , RTC_CalendarTime* newTime ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // enumerated	 
 EE_SYS_RESET_EN ,	 
 EE_ASSERT_EN ,	 
 EE_EXCEPTION_EN ,	 
 EE_WARNING_EN ,	 
 EE_NUM_ENTRY_TYPES ,	 
 // Codes	 
 EE_SYS_RESET = 300 ,	 
 EE_ASSERT = 350 ,	 
 EE_EXCEPTION = 450 ,	 
 EE_WARNING = 550	 
 } EE_entry_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EEE_DataAbort ,	 
 EEE_PrefetchAbort ,	 
 EEE_FatalError ,	 
 EEE_SWInterrupt ,	 
 EEE_UndefInst ,	 
 EEE_ReservedInt	 
 } EE_ExceptionType_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_NO_RESET_SOURCE ,	 
 EE_POWER_ON_RESET = PMU_POR ,	 
 EE_EXT_MASTER_RESET ,	 
 EE_WDT_RESET = ( PMU_EMR+2 )	 
 } EE_PMU_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 r0 ; /* register r0 contents */	 
 UINT32 r1 ; /* register r1 contents */	 
 UINT32 r2 ; /* register r2 contents */	 
 UINT32 r3 ; /* register r3 contents */	 
 UINT32 r4 ; /* register r4 contents */	 
 UINT32 r5 ; /* register r5 contents */	 
 UINT32 r6 ; /* register r6 contents */	 
 UINT32 r7 ; /* register r7 contents */	 
 UINT32 r8 ; /* register r8 contents */	 
 UINT32 r9 ; /* register r9 contents */	 
 UINT32 r10 ; /* register r10 contents */	 
 UINT32 r11 ; /* register r11 contents */	 
 UINT32 r12 ; /* register r12 contents */	 
 UINT32 SP ; /* register r13 contents */	 
 UINT32 LR ; /* register r14 contents ( excepted mode ) */	 
 UINT32 PC ; /* PC - excepted instruction */	 
 UINT32 cpsr ; /* saved program status register contents */	 
 UINT32 FSR ; /* Fault status register */	 
 UINT32 FAR_R ; /* Fault address register */	 
 EE_PMU_t PMU_reg ; /* saved reset cause - should be last */	 
	 
 // UINT32 PESR ; / * Extension * /	 
 // UINT32 XESR ;	 
 // UINT32 PEAR ;	 
 // UINT32 FEAR ;	 
 // UINT32 SEAR ;	 
 // UINT32 GEAR ;	 
 } EE_RegInfo_Data_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ EE context types to be saved in the context buffer*/	 
 EE_CT_None , /* @ENUM_VAL_DESC@ Save no context*/	 
 EE_CT_ExecTrace , /* @ENUM_VAL_DESC@ Save Trace buffer*/	 
 EE_CT_StackDump /* @ENUM_VAL_DESC@ Save Stack Dump*/	 
 } EE_ContextType_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_CDT_None ,	 
 EE_CDT_ExecTrace ,	 
 EE_CDT_StackDump ,	 
 EE_CDT_UserDefined=0x10	 
 } EE_ContextDataType_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 _PESR ;	 
 UINT32 _XESR ;	 
 UINT32 _PEAR ;	 
 UINT32 _FEAR ;	 
 UINT32 _SEAR ;	 
 UINT32 _GEAR ;	 
 } EE_XscGasketRegs;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 fileWriteOffset ; // DO NOT REMOVE OR CHANGE TYPE!!! ( for cyclic file )	 
 EE_entry_t type ;	 
 RTC_CalendarTime dateAndTime ;	 
 char desc [ 100 ] ; /* Description string size =ERROR_HANDLER_MAX_DESC_SIZE*/	 
 EE_RegInfo_Data_t RegInfo ;	 
 EE_ContextDataType_t contextBufferType ;	 
 UINT8 contextBuffer [ 512 ] ;	 
 UINT32 CHKPT0 ;	 
 UINT32 CHKPT1 ;	 
 char taskName [ 10 ] ;	 
 UINT32 taskStackStart ;	 
 UINT32 taskStackEnd ;	 
 // UP TO HERE 0x1e4 bytes ( out of 0x200 allocated by linker control file INT_RAM_EE segment )	 
 EE_XscGasketRegs xscaleGasketRegs ;	 
 UINT32 warningCntr ; // reserved [ 1 ] ;	 
	 
	 
	 
	 
 } EE_Entry_t;

typedef void voidPFuncVoid ( void ) ;
typedef void ( * ExceptionHendler ) ( EE_RegInfo_Data_t* ) ;
typedef EEHandlerAction ( * ExceptionHendlerExt ) ( EE_ExceptionType_t type , EE_RegInfo_Data_t* ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures Error handling final action*/	 
 EE_RESET , /* @ENUM_VAL_DESC@ final action RESET*/	 
 EE_STALL , /* @ENUM_VAL_DESC@ final action STALL*/	 
 EE_CONTINUE , /* @ENUM_VAL_DESC@ report but continue ( like ignore or warning ) */	 
 EE_EXTERNAL , /* @ENUM_VAL_DESC@ final action EXTERNAL*/	 
 EE_RESET_START_BASIC , /* @ENUM_VAL_DESC@ final action RESET START BASIC*/	 
 EE_NON_WDT_SERIAL /* @ENUM_VAL_DESC@ final action NON WDT SERIAL*/	 
 } FinalAct_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Error Handler options ON / OFF enum*/	 
 EE_OFF , /* @ENUM_VAL_DESC@ Option turned OFF*/	 
 EE_ON /* @ENUM_VAL_DESC@ Option turned ON*/	 
 } EE_OnOff_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure EE logs data in case of warning*/	 
 EE_WARN_OFF , /* @ENUM_VAL_DESC@ EE warning log OFF*/	 
 EE_WARN_ASSERTCONTINUE , /* @ENUM_VAL_DESC@ EE logs warning assert and continue */	 
 EE_WARN_ASSERT /* @ENUM_VAL_DESC@ EE logs warning assert */	 
 } EE_WarningOn_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_VER_3 = 3 ,	 
 EE_VER	 
 } EE_Version_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_HSL_OFF = 0 ,	 
 EE_HSL_1_8V= 1 ,	 
 EE_HSL_3V = 3	 
 } EE_HSL_V_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ WatchDog timer ( WDT ) configuration*/	 
 EE_WDT_OFF = 0 , /* @ENUM_VAL_DESC@ Set WDT OFF*/	 
 EE_WDT_TIME_6SEC = 6000 , /* @ENUM_VAL_DESC@ Set WDT to 6 sec*/ // in miliseconds ; for max WCDMA / GSM DRX cycle	 
 EE_WDT_TIME_7SEC = 7000 , /* @ENUM_VAL_DESC@ Set WDT to 7 sec*/ // in miliseconds	 
 EE_WDT_TIME_8SEC = 8000 , /* @ENUM_VAL_DESC@ Set WDT to 8 sec*/ // in miliseconds	 
 EE_WDT_TIME_10SEC = 10000 , /* @ENUM_VAL_DESC@ Set WDT to 10 sec*/ // in miliseconds	 
 EE_WDT_TIME_20SEC = 20000 , /* @ENUM_VAL_DESC@ Set WDT to 20 sec*/ // in miliseconds	 
 EE_WDT_TIME_30SEC = 30000 , /* @ENUM_VAL_DESC@ Set WDT to 30 sec*/ // in miliseconds	 
 EE_WDT_TIME_MAX = 0xFFFF /* @ENUM_VAL_DESC@ Set WDT to MAX ( 65.535000 sec ) */ // UINT16	 
 } EE_WdtTimeCfg_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Error Handler Configuration*/	 
 /* @STRUCT_NVM_FILE_NAME@ EEHandlerConfig.nvm*/	 
 EE_OnOff_t AssertHandlerOn ; /* @ITEM_DESC@ Configure EE logs data in case of ASSERT , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t ExcepHandlerOn ; /* @ITEM_DESC@ Configure EE logs data in case of Exception handler , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_WarningOn_t WarningHandlerOn ; /* @ITEM_DESC@ Configure EE logs data in case of warning , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t powerUpLogOn ; /* @ITEM_DESC@ Configure EE logs data at power-on , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t extHandlersOn ; /* @ITEM_DESC@ Configure EE logs data in case of extHandler , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t printRecentLogOnStartup ; /* @ITEM_DESC@ Indicates if to search for EE logs on NVM and notify regarding them on startup , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 FinalAct_t finalAction ; /* @ITEM_DESC@ Configures Error handling final action , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT32 EELogFileSize ; /* @ITEM_DESC@ Set Error Handler log file size , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes*/	 
 UINT16 delayOnStartup ; /* @ITEM_DESC@ Set delay on startup before printing recent log , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF in 5 milisec ticks */ // Delay for ICAT log coverage in 5 ms units	 
 EE_ContextType_t assertContextBufType ; /* @ITEM_DESC@ What context to save in case ASSERT happened , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_ContextType_t exceptionContextBufType ; /* @ITEM_DESC@ What context to save in case Exception Handler happened , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_ContextType_t warningContextBufType ; /* @ITEM_DESC@ What context to save in case Warning happened , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
	 
	 
	 
 UINT8 reserved1 [ 8 ] ; /* @ITEM_DESC@ reserved place for when deferredCfg not used , @ITEM_MODE@ , @ITEM_UNIT@ Not relevant*/	 
	 
 EE_WdtTimeCfg_t wdtConfigTime ; /* @ITEM_DESC@ WatchDog timer configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/ // UINT16	 
 UINT16 sysEeHandlerLimit ; /* @ITEM_DESC@ EE handler system limit ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 1 -0xFFFF , 0 -No limit*/ // relevant for EE_ASSISTING_MASTER only ; ZERO is no limits	 
 UINT32 dumpDdrSizeBytes ; /* @ITEM_DESC@ Limit DDR size to dump ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes , 0x1 -0x400 - No limit*/ // relevant for EE_ASSISTING_MASTER only	 
 UINT8 reserved [ 24 ] ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 UINT32 dumpResetFlag ; /*default is 0 . When finalAction is EE_RESET , 1 :dump and then silent reset ; 0 :silent reset without dump*/	 
 } EE_Configuration_t;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 SULOG_OFF = 0 ,	 
 SULOG_ENABLE_HW_SW ,	 
 SULOG_ENABLE_HW ,	 
 SULOG_ENABLE_SW ,	 
 } SULOG_TYPE_ID;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 value32 [ 2 ] ;	 
 } LteSulogCfgS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 SULOG_TYPE_ID logSwitch ;	 
 LteSulogCfgS PrintLevel ;	 
 UINT8 Sulog2SdCardFlag ;	 
 UINT8 reserved [ 3 ] ;	 
 } SULOG_ST;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 SULOG_TYPE_ID logSwitch ;	 
 LteSulogCfgS PrintLevelForSdCardDisable ;	 
 LteSulogCfgS PrintLevelForSdCardEnable ;	 
 UINT8 Sulog2SdCardFlag ;	 
 } SulogCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 HSL_DISABLE = 0 ,	 
 HSL_BIGBOARD_ENABLE ,	 
 HSL_MINIBOARD_ENABLE ,	 
 } HSL_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _PM_DISABLE = 0 ,	 
 _PM_ENABLE ,	 
 } PM_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 VCXO_SD_DISABLE = 0 ,	 
 VCXO_SD_ENABLE ,	 
 } VCXO_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 SD_LOG_DISABLE = 0 ,	 
 SD_LOG_ENABLE ,	 
 } SDLOG_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _L1_ACAT_LOG_DISABLE = 0 ,	 
 _L1_ACAT_LOG_ENABLE ,	 
 } L1AcatLog_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 L1_IML2DDR_DISABLE = 0 ,	 
 L1_IML2DDR_ENABLE ,	 
 } L1IML2DDR_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 PM_TYPE PMCfgVal ;	 
 HWDFC_TYPE HWDFCCfgVal ;	 
 HWDFC_TEST_TYPE HWDFCTestCfgVal ;	 
 VCXO_TYPE VCXOCfgVal ;	 
 SDLOG_TYPE SDLogCfgVal ;	 
 L1AcatLog_TYPE L1AcatLogVal ; /* CQ0003TTTT */	 
	 
	 
	 
 IMLCfgDataS IMLCfgdata ;	 
 } HSLCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _CPU_USAGE_DUMP_DISABLE = 0 ,	 
 _CPU_USAGE_DUMP_ENABLE	 
 } CPUUSAGEDUMP_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 CPUUSAGEDUMP_TYPE cpuUsageDumpEnable ;	 
 UINT32 dumpInterval ;	 
 } SYSDBGCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 APT_DISABLE = 0 ,	 
 APT_ENABLE ,	 
 } APT_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT8 ucVcxoStableTime ;	 
 UINT8 ucPllStableTime ;	 
 UINT8 ucClkGenTime ;	 
 UINT8 ucDualCarrierFlag ;	 
 UINT8 ucDualAntFlag ;	 
 APT_TYPE AptFlag ;	 
 } MSACfgDataS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 MSACfgDataS MsaCfg ;	 
 HSLCfgDataS HslCfg ;	 
 SYSDBGCfgDataS SysDbgCfg ;	 
 Log_ConfigS LogCfg ;	 
 Usb_DriverS usbDrvCfg ;	 
 LTE_CONFIG_S LteCfg ;	 
 Ymodem_Dump_type YmodemCfg ;	 
 SulogCfgDataS SulogCfg ;	 
 RTICfg_t rtiConfig ;	 
 uartCfgDataS uartCfg ;	 
 EE_Configuration_t eeCfg ;	 
 diagCfgDataS diagCfg ;	 
 UINT32 TailGuard ;	 
 } PlatformCfgDataS;

typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
typedef unsigned char BYTE ;
typedef unsigned short int WORD ;
typedef unsigned long DWORD ;
typedef WORD * WORD_PTR ;
typedef DWORD * DWORD_PTR ;
typedef BYTE BYTE_BITMASK ;
typedef VOID_PTR * VOID_PTR_PTR ;
typedef WORD FLASH_DATA_WIDTH ;
typedef char FDI_TCHAR ;
typedef OSASemaRef SEM_ID ;
typedef int SEM_STATUS ;
typedef SEM_MTX * SEM_MTX_ID ;
typedef WORD IDTYPE ;
typedef DATA_LOOKUP * DATA_LOOKUP_PTR ;
typedef DATA_LOCATION * DATA_LOC_PTR ;
typedef OPEN_PARAM * OPEN_STREAM_PTR ;
typedef COMMAND * COMMAND_PTR ;
typedef UNIT_HEADER * UNIT_HDR_PTR ;
typedef MULTI_INSTANCE * MULTI_INST_PTR ;
typedef BLOCK_INFO * BLK_INFO_PTR ;
typedef COMMAND_CONTROL * CMD_CNTRL_PTR ;
typedef unsigned short FILE_ID ;
//ICAT EXPORTED FUNCTION - SW_PLAT , DIAG , readFilterFile 
 BOOL diagReadFilterFile ( void ) 
 {	 
 FILE_ID fdiID ;	 
 UINT32 count ;	 
 UINT32 size ;	 
 UINT32 dbid ;	 
 // ERR_CODE ret_val ;	 
 BOOL valid=0 ;	 
 DIAG_Nvm_Filter_File_Header_t filterHeader ;	 
	 
 if ( !diagReadDBVersion ( &dbid ) ) return 0 ;	 
	 
 if ( ( fdiID = FDI_fopen ( diagFilterNvmFileName , " rb " ) ) !=0 )	 
 { // success on open file . now read it		 
 if ( nvmReadHeader ( fdiID , " DIAG_Nvm_Filter_File_Header_t " ) >=sizeof ( DIAG_Nvm_Filter_File_Header_t ) )		 
 {			 
 if ( ( count = FDI_fread ( &filterHeader , sizeof ( DIAG_Nvm_Filter_File_Header_t ) , 1 , fdiID ) ) ==1 )			 
 {				 
 if ( filterHeader.dbID!=dbid )				 
 {					 
DIAG_FILTER ( SW_PLAT , DIAG , NVM_FILTER_FILE_DBID , DIAG_INFORMATION)  
 diagPrintf ( " DIAG NVM filer file not applied: DBID mismatch ( Expected: %lx , File: %lx ) " , dbid , filterHeader.dbID );

					 
 }				 
 else				 
 {					 
 valid=1 ;					 
 size= ( ( ( ( ( filterHeader . filterBitLength ) < ( diagNumOfReports ) ) ? ( filterHeader . filterBitLength ) : ( diagNumOfReports ) ) ) +7 ) / 8 ;					 
 if ( ( count = FDI_fread ( filterArray , 1 , size , fdiID ) ) <size )					 
 {						 
DIAG_FILTER ( SW_PLAT , DIAG , NVM_FILTER_FILE_SHORT , DIAG_INFORMATION)  
 diagPrintf ( " DIAG NVM filer file is shorter than expected ( Expected: %lx , File: %lx ) " , size , count );

						 
 }					 
DIAG_FILTER ( SW_PLAT , DIAG , NVM_FILTER_FILE_APPLIED , DIAG_INFORMATION)  
 diagPrintf ( " DIAG NVM filer file applied " );

					 
 }				 
 }			 
 }		 
 /*ret_val = ( ERR_CODE ) ( actually not used ) */ FDI_fclose ( fdiID ) ;		 
 }	 
 return valid ;	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , DIAG , saveFilterFile 
 BOOL diagSaveFilterFile ( void ) 
 {	 
 FILE_ID fdiID ;	 
 // UINT32 count ;	 
 UINT32 dbid ;	 
 // ERR_CODE ret_val ;	 
 BOOL valid=0 ;	 
 DIAG_Nvm_Filter_File_Header_t filterHeader ;	 
	 
 if ( !diagReadDBVersion ( &dbid ) ) return 0 ;	 
	 
 if ( ( fdiID = FDI_fopen ( diagFilterNvmFileName , " wb " ) ) !=0 )	 
 {		 
 if ( diagWriteNvmHeader ( fdiID ) )		 
 {			 
 filterHeader.dbID=dbid ;			 
 filterHeader.filterBitLength=diagNumOfReports ;			 
 if ( ( /*count = */ FDI_fwrite ( &filterHeader , sizeof ( filterHeader ) , 1 , fdiID ) ) ==1 )			 
 {				 
 if ( ( /*count = */ FDI_fwrite ( filterArray , ( ( diagNumOfReports+7 ) / 8 ) , 1 , fdiID ) ) ==1 )				 
 {					 
 valid=1 ;					 
 }				 
 }			 
 }		 
 FDI_fclose ( fdiID ) ;		 
 }	 
	 
 if ( valid )	 
 {		 
DIAG_FILTER ( SW_PLAT , DIAG , NVM_FILTER_FILE_WRITE_OK , DIAG_INFORMATION)  
 diagPrintf ( " DIAG NVM filer file saved " );

		 
 return 1 ;		 
 }	 
	 
DIAG_FILTER ( SW_PLAT , DIAG , NVM_FILTER_FILE_WRITE_FAILED , DIAG_ERROR)  
 diagPrintf ( " Failed to write DIAG NVM filer file " );

	 
 return 0 ;	 
 }

//ICAT EXPORTED FUNCTION - HW_PLAT , utilities , DIAGTOUSB 
 void set_diag_dev_usb ( void ) 
 {	 
 setDiagDevType ( DIAG_DEV_USB ) ;	 
 }

//ICAT EXPORTED FUNCTION - HW_PLAT , utilities , DIAGTOSD 
 void set_diag_dev_sd ( void ) 
 {	 
 setDiagDevType ( DIAG_DEV_SD ) ;	 
 }

//ICAT EXPORTED FUNCTION - HW_PLAT , utilities , SULOGTOUSB 
 void set_sulog_dev_usb ( void ) 
 {	 
 setSulogDevType ( SULOG_DEV_USB ) ;	 
 }

//ICAT EXPORTED FUNCTION - HW_PLAT , utilities , SULOGTOSD 
 void set_sulog_dev_sd ( void ) 
 {	 
 setSulogDevType ( SULOG_DEV_SD ) ;	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\DiagSigStubCreateNSend.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\DiagSigStubCreateNSend.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\DiagSigStubFrameNumber.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\DiagSigStubFrameNumber.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diaglogger.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diaglogger.c
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_osif.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diag_osif.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diagloggerbuf.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\diagloggerbuf.c
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\DiagSig_L1.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\DiagSig_L1.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\DiagSig_PS.ppp
//PPL Source File Name : X:\\diag\\diag_logic\\src\\DiagSig_PS.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
typedef unsigned char Char ;
typedef unsigned char Int8 ;
typedef signed char SignedInt8 ;
typedef unsigned short Int16 ;
typedef signed short SignedInt16 ;
typedef unsigned long Int32 ;
typedef signed long SignedInt32 ;
typedef Int8 Boolean ;
typedef SignedInt8 TP_SInt8 ;
typedef SignedInt16 TP_SInt16 ;
typedef SignedInt32 TP_SInt32 ;
typedef Int8 TP_UInt8 ;
typedef Int16 TP_UInt16 ;
typedef Int32 TP_UInt32 ;
typedef Boolean TP_Boolean ;
typedef char * TP_String ;
typedef char TP_Char ;
typedef TP_UInt16 TP_WChar ;
typedef TP_WChar TP_TChar ;
typedef union SysBasicTypesUnionTag
 {
 Int8 int8Member ;
 SignedInt8 signedInt8Member ;
 Int16 int16Member ;
 SignedInt16 signedInt16Member ;
 Int32 int32Member ;
 SignedInt32 signedInt32Member ;
 Boolean booleanMember ;
 void *pointerMember ;

 TP_SInt8 tp_SInt8Member ;
 TP_SInt16 tp_SInt16Member ;
 TP_SInt32 tp_SInt32Member ;
 TP_UInt8 tp_UInt8Member ;
 TP_UInt16 tp_UInt16Member ;
 TP_UInt32 tp_UInt32Member ;
 TP_Boolean tp_BooleanMember ;
 TP_String tp_StringMember ;
 TP_Char tp_CharMember ;
 TP_WChar tp_WCharMember ;
 TP_TChar tp_TCharMember ;
 } SysBasicTypesUnion ;
typedef unsigned long long Ulong64 ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 lineNo ; // CONST	 
 char idString [ 14 ] ; // CONST = 16 bytes	 
 UINT32 timeStamp ; // var	 
 UINT32 param1 ; // var	 
 UINT32 param2 ; // var	 
 UINT32 param3 ; // var	 
 } BspLogRecord;

//ICAT EXPORTED ENUM 
 typedef enum TaskIdTag /* tasks sent to identified by their task ids */ 
 {	 
 /* @ENUM_DESC@ TBD */	 
	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / kisystsk.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : System task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a	 
 ** #if !defined KISYSTSK_H	 
 ** as it can be legitimately included twice	 
 **	 
 ** This must never be included directly by any file outside of the kernel.	 
 */	 
	 
 KI_TASK_SET_START_0 = ( 0 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** External Client task Set , not for TTPCom use	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / extask.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : External GKI Task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** Add ids for any tasks external to the TTPCom Product.	 
 ** ( the format is as in the comment below. )	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** Example task specification	 
 **	 
 ** Task Id Queue Id Entry Point Stack Queue Priority	 
 ** KI_TASK_DEF ( SIM_TASK_ID , SIM_QUEUE_ID , SimManagerTask , 1024 , 30 , 8 )	 
 **	 
 */	 
	 
	 
	 
	 
 PS_L2_TOOL_TASK_ID ,	 
	 
	 
	 
	 
 /*	 
 ** Create aliases for any task id handled by a GKI task.	 
 */	 
 START_EX_ALIASES ,	 
	 
 /*	 
 ** Example alias definition	 
 **	 
 ** Real Task Id Alias Task Id Alias Queue Id	 
 ** KI_ALIAS_DEF ( AL_TASK_ID , ALSM_TASK_ID , ALSM_QUEUE_ID )	 
 **	 
 ** WARNING: When using aliases the value in the enumeration must be stored	 
 ** first ( using the KI_START_ALIAS macro ) and then re-instated after	 
 ** ( using the KI_END_ALIAS macro ) the alias definition. See	 
 ** kisystsk.h as an example.	 
 **	 
 */	 
	 
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **	 
 ** Add external aliases here **	 
 ** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */	 
	 
 STOP_EX_ALIASES = START_EX_ALIASES - 1 ,	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_0 ,	 
	 
 KI_TASK_SET_START_1 = ( 1 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** External Silicon Client task set , not for TTPCom use	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / platforms / hermon / sys / gki.typ / api / cfg / exstask.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2007 / 1 / 12 13 :10:41 $	 
 **************************************************************************	 
 * File Description :	 
 * Task Definitions for the Hermon Silicon Platform	 
 **************************************************************************/	 
	 
 /*	 
 ** Add ids for any tasks external to the TTPCom Product.	 
 ** ( the format is as in the comment below. )	 
 */	 
	 
 /*	 
 ** Modifiers to TTPCom CORE task stack sizes	 
 ** The values here are ADDED to the CORE stack	 
 ** size defined in the ??task.h file	 
 */	 
	 
 // The SimDriver is using the sprintf ( ) which requires min 256 bytes on stack	 
	 
	 
 /*	 
 ** Modifiers to TTPCom CORE task queue lengths	 
 ** The values here are ADDED to the CORE queue	 
 ** size defined in the ??task.h file	 
 */	 
	 
	 
	 
 /* Modifiers to TTPCom CORE task priorities	 
 ** The values here REPLACE the CORE task	 
 ** priorities defined in the ??task.h file	 
 */	 
	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** Example task specification	 
 **	 
 ** Task Id Queue Id Entry Point Stack Queue Priority	 
 ** KI_TASK_DEF ( SIM_TASK_ID , SIM_QUEUE_ID , SimManagerTask , 1024 , 30 , 8 )	 
 **	 
 */	 
	 
	 
	 
	 
	 
 /*	 
 to reserve a dummy SAC task id to avoid the first SAC related task id	 
 has the same number as START_AL_ALIASES	 
 */	 
 SAC_DUMMY_TASK_ID ,	 
	 
	 
	 
	 
	 
 SAC_RESERVED_TASK_ID ,	 
	 
	 
 /* SAC_TEST_TASK definition */	 
	 
	 
	 
 SAC_TEST_TASK_ID ,	 
	 
	 
 /* SAC_OSA_TASK definition */	 
	 
 SAC_OSA_TASK_ID ,	 
	 
	 
	 
	 
	 
 INTEL_NON_GKI_TASK_ID , /* Psudeo Intel task */	 
	 
	 
 HA_COMMS_TASK_ID ,	 
	 
	 
	 
	 
 /* Map HAW and AMR tasks to the UP_PHY_TASK_ID on Hermon */	 
	 
	 
	 
	 
 /*	 
 ** Create aliases for any task id handled by a GKI task.	 
 */	 
 START_EXS_ALIASES ,	 
	 
 /*	 
 ** Example alias definition	 
 **	 
 ** Real Task Id Alias Task Id Alias Queue Id	 
 ** KI_ALIAS_DEF ( AL_TASK_ID , ALSM_TASK_ID , ALSM_QUEUE_ID )	 
 **	 
 ** WARNING: When using aliases the value in the enumeration must be stored	 
 ** first ( using the KI_START_ALIAS macro ) and then re-instated after	 
 ** ( using the KI_END_ALIAS macro ) the alias definition. See	 
 ** kisystsk.h as an example.	 
 **	 
 */	 
	 
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **	 
 ** Add external aliases here **	 
 ** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */	 
	 
	 
 STOP_EXS_ALIASES = START_EXS_ALIASES - 1 ,	 
	 
 /* END OF FILE */	 
	 
	 
 KI_TASK_SET_STOP_1 ,	 
	 
 KI_TASK_SET_START_2 = ( 2 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** GKI / System Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / kitask.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : GKI / System task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
 TIMER_TASK_ID ,	 
	 
	 
 TEST_TASK_ID ,	 
	 
 EMMI_LOW_PRI_TASK_ID ,	 
 EMMI_HIGH_PRI_TASK_ID ,	 
	 
	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_2 ,	 
	 
 KI_TASK_SET_START_3 = ( 3 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Layer 1 Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / l1task.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : Layer 1 task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
	 
	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 LOW_PRIORITY_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 L1_PROF_TASK_ID ,	 
	 
	 
	 
	 
	 
 /* CQ00100336 - Begin */	 
 // 3 G L1C	 
	 
	 
	 
 /* CQ00100336 - End */	 
	 
	 
	 
	 
	 
	 
	 
 MINI_LOGGER_TASK_ID ,	 
 ML_SIGNAL_DUMPER_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MIPS_MANAGER_TASK_ID ,	 
	 
	 
	 
	 
	 
 L1_VCXO_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_3 ,	 
	 
 KI_TASK_SET_START_4 = ( 4 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Device Management Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / dmtask.h#4 $	 
 * $Revision: #4 $	 
 * $DateTime: 2007 / 3 / 30 13 :53:25 $	 
 **************************************************************************	 
 * File Description : Device Management task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
	 
	 
	 
	 
	 
	 
	 
 L1_SD_TASK_ID ,	 
	 
 L1_SD_TASK_ID2 ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 // KI_TASK_DEF ( L1_AL_TASK_ID , L1_AL_QUEUE_ID , L1AlTask , 4094 , 30 , 51 ) // CQ00136121	 
	 
	 
	 
 /* Redundant task - may be reused */	 
 L1_BM_TASK_ID ,	 
	 
 /* Redundant task - may be reused */	 
 L1_SP_TASK_ID ,	 
	 
	 
	 
	 
 L1_CTM_TASK_ID ,	 
	 
	 
 // KI_TASK_DEF ( DM_TASK_ID , DM_QUEUE_ID , DmTask , 1024 , 30 , 51 )	 
	 
	 
	 
 DTF_STIMULATE_TASK_ID ,	 
 DTF_SIMULATE_TASK_ID ,	 
	 
 DTF_SELF_TEST_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 DM_NVM_TASK_ID ,	 
	 
	 
	 
	 
	 
 DM_BM_TASK_ID ,	 
	 
	 
	 
	 
 DM_RTC_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 /* Use NVRAM task unless explicitly removed */	 
	 
	 
	 
 DM_NVP_TASK_ID , // CQ00146716 change 80 to 81 fo #91812 by yuling	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 USB_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 IRDA_TASK_ID ,	 
 IRDA_STACK_TASK_ID ,	 
 IRDA_FRAMER_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 OBEX_TASK_ID ,	 
 OBEX_TEST_TASK_ID ,	 
	 
	 
	 
 /* A task priority of 9 is chosen as priority range 0 -9 are reserved for interrupt launched	 
 * tasks such as L1_AL_HI_TASK_ID. This task is triggered by the L1 frame interrupt and	 
 * provides a periodic tick to the L1AL layer. */	 
	 
 /* L1_AL_HI_TASK stack max usage measured at 660 on 430 gpdev build 2005 _June_08. Allow some	 
 * extra to support use of printf & other debugging => size=800 */	 
 // KI_TASK_DEF ( L1_AL_HI_TASK_ID , L1_AL_HI_QUEUE_ID , L1AlHiTask , 800 , 1 , 16 ) // CQ00136121	 
	 
	 
	 
	 
	 
	 
	 
 SIM_IF_CHECK_TASK_ID ,	 
	 
	 
	 
 /* include as part of Camera Multiplex layer Test Task */	 
	 
	 
	 
	 
	 
	 
	 
 CATT_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MP_SERIALPORT_DRV_TASK_ID ,	 
	 
	 
	 
 /* This is the USB EMMI task */	 
	 
	 
	 
 USB_EMMI_COMMS_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 TAC_TASK_ID ,	 
	 
	 
 START_DM_ALIASES ,	 
	 
 SIMDRV_TASK_ID = L1_SD_TASK_ID ,	 
	 
 SIMDRV_TASK_ID2 = L1_SD_TASK_ID2 ,	 
	 
	 
	 
	 
	 
 HAD_L1_SD_TASK_ID = L1_SD_TASK_ID ,	 
	 
	 
	 
	 
	 
 // KI_ALIAS_DEF ( L1_AL_TASK_ID , L1AM_TASK_ID , L1AM_QUEUE_ID ) // CQ00136121	 
	 
	 
 STOP_DM_ALIASES = START_DM_ALIASES - 1 ,	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_4 ,	 
	 
 KI_TASK_SET_START_5 = ( 5 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Protocol Stack Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / pstask.h#6 $	 
 * $Revision: #6 $	 
 * $DateTime: 2007 / 3 / 19 13 :59:30 $	 
 **************************************************************************	 
 * File Description : Protocol Stack task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deliberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
	 
	 
	 
 NAS_STUB_TASK_ID ,	 
	 
	 
	 
 L2_BCH_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
 L2_BCH_2_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
 L2_DD_TASK_ID ,	 
 L2_CBCH_TASK_ID ,	 
 L2_SACCH_0_TASK_ID ,	 
 L2_SACCH_3_TASK_ID ,	 
 L2_DCCH_0_TASK_ID ,	 
 L2_DCCH_3_TASK_ID ,	 
 GRR_TASK_ID ,	 
 GRR_2_TASK_ID ,	 
	 
	 
	 
 CB_TASK_ID ,	 
	 
 CB_2_TASK_ID ,	 
	 
	 
 /*Modifed size to 5000 by Fengzhuan , CQ00023736 , 20121029 , begin*/	 
 MM_TASK_ID ,	 
 /*Modifed size to 5000 by Fengzhuan , CQ00023736 , 20121029 , end*/	 
	 
	 
 /*Modified by Hanko for CQ67542 20140808 , begin*/	 
 MM_2_TASK_ID ,	 
 /*Modified by Hanko for CQ67542 20140808 , end*/	 
	 
 /*CQ00146133 , Cgliu , 2023 -09-27 , Begin*/	 
	 
	 
 SIM_TASK_ID ,	 
	 
 SIM_2_TASK_ID ,	 
	 
	 
	 
 /*CQ00146133 , Cgliu , 2023 -09-27 , End */	 
	 
	 
 TIM_TASK_ID , // CQ00146716 // change from 55 to 81 , stack from 360 t0 1300 20231012 by yuling	 
	 
 /*Modified by fxzhang , CQ00108415 , 20171116 , begin*/	 
 // #if !defined ( UPGRADE_DSDS_EXCLUDE_SIM2_L1 )	 
 // KI_RESERVED_TASK ( TIM_2_TASK_ID , TIM_2_QUEUE_ID )	 
 // #else	 
 TIM_2_TASK_ID , // CQ00146716 // change from 55 to 81 , stack from 360 t0 1300 20231012 by yuling	 
 /*KI_RESERVED_TASK ( TIM_2_TASK_ID , TIM_2_QUEUE_ID ) */	 
 // #endif	 
 /*Modified by fxzhang , CQ00108415 , 20171116 , end*/	 
	 
	 
	 
	 
 SMTL_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
	 
 SMTL_2_TASK_ID ,	 
	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
 SMCM_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
	 
 SMCM_2_TASK_ID ,	 
	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
 SMRL_TASK_ID ,	 
	 
 SMRL_2_TASK_ID ,	 
	 
	 
	 
	 
 START_PS_AS_ALIASES ,	 
	 
	 
	 
 STOP_PS_AS_ALIASES = START_PS_AS_ALIASES - 1 ,	 
	 
	 
 START_PS_NAS_ALIASES ,	 
 GP_GMM_TASK_ID = MM_TASK_ID ,	 
	 
 GP_GMM_2_TASK_ID = MM_2_TASK_ID ,	 
	 
	 
	 
 GP_SMS_TASK_ID = SMCM_TASK_ID , /* To bottom SMS */	 
	 
 STOP_PS_NAS_ALIASES = START_PS_NAS_ALIASES - 1 ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA14_ID ,	 
	 
	 
 /*CQ00119446 add begin*/	 
	 
 VG_CI_TASK_ID ,	 
	 
	 
 /*Cat0 20160615 transient*/	 
 // KI_ALIAS_DEF ( UNKNOWNS_TASK_ID , VG_RTFDP_TASK_ID , VG_RTFDP_QUEUE_ID )	 
 VG_RTFDP_TASK_ID ,	 
	 
 PCCI_STUB_TASK_ID ,	 
 MODEM_TASK_ID ,	 
 ATPARSER_TASK_ID ,	 
	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
 ATPARSER_1_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
	 
	 
	 
	 
 VG_MUX_TASK_ID ,	 
	 
	 
	 
	 
	 
 VG_MUX1_TASK_ID ,	 
	 
	 
 // MR	 
	 
	 
 VG_MUX_NULL_NOPL_TASK_ID ,	 
 // KI_TASK_DEF ( VG_MUX_NULL_NOPL_TASK_ID , VG_MUX_NULL_NOPL_QUEUE_ID , VgMux1NoPLTask , 1000 , 30 , 55 )	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 VG_MUX2_TASK_ID ,	 
	 
	 
	 
 VG_MUX_USBNULL_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 /* Reduce impact on TaskID ' s next time MUX tasks have to be added */	 
 VG_MUX_SPARE1 ,	 
	 
	 
	 
	 
	 
	 
 VG_MUX_GSM710S_TASK_ID ,	 
	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
 VG_MUX_GSM710S_1_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
 START_MUX_ALIASES ,	 
	 
	 
	 
	 
	 
 VG_MUX_NULL_TASK_ID = VG_MUX1_TASK_ID ,	 
	 
 VG_DS_TASK_ID = VG_CI_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 STOP_MUX_ALIASES = START_MUX_ALIASES - 1 ,	 
	 
	 
	 
	 
	 
	 
 CSR_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
 CSR_2_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
	 
	 
	 
	 
 GP_MAC_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
 GP_MAC_2_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
 GP_RD_TASK_ID ,	 
	 
 GP_RD_2_TASK_ID ,	 
	 
 GP_LLC_TASK_ID ,	 
	 
 GP_LLC_2_TASK_ID ,	 
	 
	 
	 
	 
 // KI_TASK_DEF ( GP_SNDCP_TASK_ID , GP_SNDCP_QUEUE_ID , / *GpSndcpTask* / UpUlbgTask , 900 , 1000 , 62 ) // TODO: This is a workaround!!!	 
	 
 UP_DLBG_TASK_ID ,	 
	 
 UP_DLBG_2_TASK_ID ,	 
	 
	 
 GP_SM_TASK_ID ,	 
	 
 GP_SM_2_TASK_ID ,	 
	 
	 
 /* Modified by Daniel for CQ00018823 20120605 , begin */	 
 GP_PPP_TASK_ID ,	 
 // KI_TASK_DEF ( GP_PPP_TASK_ID , GP_PPP_QUEUE_ID , GpPppTask , 2000 , 272 , 65 )	 
	 
 GP_PPP_2_TASK_ID ,	 
 // KI_TASK_DEF ( GP_PPP_2_TASK_ID , GP_PPP_2_QUEUE_ID , GpPppTask , 2000 , 272 , 65 )	 
	 
 /* Modified by Daniel for CQ00018823 20120605 , end */	 
	 
	 
	 
	 
	 
	 
	 
 UT_TMM_TASK_ID ,	 
	 
	 
 /* Only used for unit testing - reserved here to keep task IDs the same */	 
 GP_UNITTEST_TASK_ID ,	 
 /* Only used for simulation testing - reserved here to keep task IDs the same */	 
 GP_AUXRD_TASK_ID ,	 
 GP_AUXLLC_TASK_ID ,	 
 GP_AUXSNDCP_TASK_ID ,	 
 GP_PPP_DIALLER_TASK_ID ,	 
 GP_DS_DIALLER_TASK_ID ,	 
 GP_PPP_PC_COMMS_TASK_ID ,	 
 GP_PPP_PC_COMMS_DIALLER_TASK_ID ,	 
	 
	 
	 
	 
 // 20100506 hlhu: add for lte psas start	 
	 
 LTE_L1A_TASK_ID , // CQ64122	 
	 
 LTE_L1A_2_TASK_ID , /*CQ00107342 add*/	 
	 
	 
 LTE_RRC_TASK_ID ,	 
	 
	 
	 
	 
	 
 LTE_RRC_2_TASK_ID ,	 
	 
	 
	 
	 
 // KI_TASK_DEF ( LTE_L1_SIMU_TASK_ID , LTE_L1_SIMU_QUEUE_ID , tLteL1SimulatorTask , 5000 , 30 , 29 )	 
 LTE_MACRLC_TASK_ID ,	 
	 
	 
 LTE_MACRLC_2_TASK_ID ,	 
	 
 // #if defined ( UPGRADE_DSDS )	 
 // KI_TASK_DEF ( LTE_MACRLC_2_TASK_ID , LTE_MACRLC_2_QUEUE_ID , tLteMacRlcTask2 , 5000 , 600 , 30 )	 
 // #endif	 
	 
	 
	 
 PLMS_TASK_ID ,	 
	 
	 
 // #ifdef LTE_TARGET_TEST_MCU_ONLY	 
	 
	 
	 
 // added by jcweng to process the signals from Anite / TTCN2C side	 
 LTE_ANITE_ADAPOTR_TASK_ID ,	 
	 
	 
	 
 // 20100506 hlhu: add for lte psas end	 
	 
	 
	 
	 
 START_UPS_ALIASES ,	 
	 
 UP_BMC_TASK_ID = CB_TASK_ID ,	 
	 
 UP_PDCP_TASK_ID = LTE_MACRLC_TASK_ID ,	 
	 
 UP_PDCP_2_TASK_ID = LTE_MACRLC_2_TASK_ID ,	 
	 
	 
	 
	 
	 
 UP_RABM_TASK_ID = LTE_MACRLC_TASK_ID ,	 
	 
 UP_ULBG_TASK_ID = LTE_MACRLC_TASK_ID ,	 
 // KI_ALIAS_DEF ( LTE_MACRLC_TASK_2_ID , UP_ULBG_2_TASK_ID , UP_ULBG_2_QUEUE_ID )	 
	 
 // KI_ALIAS_DEF ( GP_SNDCP_TASK_ID , UP_ULBG_TASK_ID , UP_ULBG_QUEUE_ID ) // TODO: remove	 
	 
 UP_ULBG_2_TASK_ID = LTE_MACRLC_2_TASK_ID , // TODO: remove	 
 // KI_ALIAS_DEF ( LTE_MACRLC_2_TASK_ID , UP_PDCP_2_TASK_ID , UP_PDCP_2_QUEUE_ID )	 
 GP_SNDCP_2_TASK_ID = LTE_MACRLC_2_TASK_ID ,	 
	 
	 
	 
	 
 GP_SNDCP_TASK_ID = LTE_MACRLC_TASK_ID ,	 
	 
	 
	 
 STOP_UPS_ALIASES = START_UPS_ALIASES - 1 ,	 
	 
	 
	 
	 
	 
	 
 TASK_BL_ID , // change queue 30 by aliOS	 
	 
 TASK_BL_2_ID , // add by aliOS	 
	 
	 
 TASK_ANRM2_ID_DUMMY ,	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
 TASK_ANRM2_ID_2_DUMMY ,	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
 START_USE_ANRM2 ,	 
 TASK_ANRM2_ID = DM_NVM_TASK_ID ,	 
 STOP_USE_ANRM2 = START_USE_ANRM2 - 1 ,	 
	 
	 
	 
 VG_MUX_IP_TRAN_TASK_ID ,	 
	 
 /* Streaming tasks */	 
	 
	 
	 
 SNTP_TASK_ID ,	 
	 
	 
	 
	 
	 
 RTP_TASK_ID ,	 
	 
	 
	 
	 
	 
 RTSP_TASK_ID ,	 
	 
	 
	 
	 
	 
 RTP_RTSP_TEST_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 TASK_FS_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
 POC_TASK_ID ,	 
	 
	 
	 
	 
	 
 SIP_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 VG_GMX_NULL_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
 VG_MUX_GSM710E_TASK_ID ,	 
	 
	 
	 
	 
 VG_MUX_GSM710E_NOPL_TASK_ID ,	 
 // KI_TASK_DEF ( VG_MUX_GSM710E_NOPL_TASK_ID , VG_MUX_GSM710E_NOPL_QUEUE_ID , VgMux710eNoPLTask , 615 , 30 , 55 )	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 VG_MUX_GSM710SM_TASK_ID ,	 
	 
	 
	 
 // redefine pdcp task id	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 // 2017 -09-26 , WQS , move TTCN PC Test related tasks to the end for correct display in CATStudio	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_5 ,	 
	 
 KI_TASK_SET_START_6 = ( 6 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Application Layer Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / aftask.h#5 $	 
 * $Revision: #5 $	 
 * $DateTime: 2007 / 3 / 30 13 :53:25 $	 
 **************************************************************************	 
 * File Description : Application Foreground task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 TCPIP_TASK_ID ,	 
	 
 BLIP_TASK_ID ,	 
 LPPP_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 WPPP_TASK_ID ,	 
	 
	 
 /* Application Layer */	 
 AAUD_TASK_ID ,	 
	 
	 
 /*remove 20220927 CQ00139071 begin*/	 
	 
 /*remove 20220927 CQ00139071 end*/	 
 TASK_DISH_ID ,	 
	 
 TASK_EXTRA2_ID ,	 
	 
 /* 20163 removed AEIT task */	 
 TASK_NOT_USED_ID ,	 
	 
 TASK_ATCV_MAILER_ID ,	 
 TASK_AL_TEST_ID ,	 
 TASK_AL_SCRIPT_ID ,	 
	 
	 
	 
	 
 TASK_AL_TEST2_ID ,	 
	 
	 
	 
	 
	 
	 
	 
 SIMAT_TASK_ID ,	 
	 
 SIMAT_2_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 TASK_EXTRA4_ID ,	 
 TASK_EXTRA5_ID ,	 
	 
 /* WAP Tasks */	 
	 
	 
	 
	 
	 
	 
	 
 TASK_EXTRA6_ID ,	 
 TASK_EXTRA7_ID ,	 
	 
	 
	 
 TASK_EXTRA8_ID ,	 
	 
	 
	 
	 
 TASK_EXTRA9_ID ,	 
	 
	 
	 
	 
	 
 MMI_TEST_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 TASK_EXTRA10_ID ,	 
	 
	 
	 
	 
	 
	 
 TASK_EXTRA11_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA12_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA13_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA15_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA16_ID ,	 
	 
	 
 START_AB_ALIASES ,	 
	 
 ALSH_TASK_ID = TASK_BL_ID ,	 
 AL_TASK_ID = TASK_BL_ID ,	 
	 
	 
	 
	 
	 
 GP_ABGP_TASK_ID = TASK_BL_ID ,	 
	 
	 
	 
	 
	 
 STOP_AB_ALIASES = START_AB_ALIASES - 1 ,	 
	 
	 
	 
	 
 /*	 
 Absorb task receives signals and deletes them. Useful when a destination task is needed for IND	 
 and CNF signals.	 
 */	 
	 
	 
	 
 ABSORB_TASK_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA17_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA18_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA19_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA20_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA21_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA22_ID ,	 
	 
	 
	 
	 
	 
 FM_TASK_ID ,	 
	 
	 
 TASK_EXTRA23_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
 SOCKTEST_TASK_ID ,	 
	 
	 
 /* Transport Task */	 
	 
	 
	 
 TRANSPORT_TASK_ID ,	 
	 
	 
	 
	 
	 
 AP_BG_TASK_ID ,	 
	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_6 ,	 
	 
 KI_TASK_SET_START_7 = ( 7 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Mapal Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2006 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / mptask.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : Mapal task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
	 
	 
 MAPAL_TASK_ID ,	 
 MAPAL_DRIVERS_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MP_RESERVED0_TASK_ID ,	 
 MP_RESERVED1_TASK_ID ,	 
	 
	 
	 
	 
	 
 MAPAL_SPAL_HF_TASK_ID ,	 
	 
	 
	 
	 
	 
 MP_RESERVED2_TASK_ID ,	 
 MP_RESERVED3_TASK_ID ,	 
	 
	 
	 
	 
 MP_TESTING_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
 MP_TARGET_DRIVER_TEST_TASK_ID ,	 
 MP_PC_AUTOTEST_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
 MP_PC_BORG_AUTOTEST_TASK_ID ,	 
 PC_DRIVER_DEBUG_TEST_TASK_ID ,	 
	 
	 
	 
 MAPAL_DPRAMHWFWD_TASK_ID ,	 
 MAPAL_COMMS_TASK_ID ,	 
 MAPAL_FWDTEST_TASK_ID ,	 
 MAPAL_LOGGING_TASK_ID ,	 
	 
	 
	 
	 
	 
 MP_GKI_TEST_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
 MP_ASYNC_APP1_TASK_ID ,	 
 MP_ASYNC_DRV1_TASK_ID ,	 
	 
	 
	 
	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_7 ,	 
	 
 KI_TASK_SET_START_8 = ( 8 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Bluetooth Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / bttask.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : Bluetooth task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 BT_SCHEDULER_TASK_ID ,	 
 BT_SCHEDULER_TEST_TASK_ID ,	 
 BT_BG_TASK_ID ,	 
 ABBT_AU_TASK_ID ,	 
 RMT_SIM_TASK_ID ,	 
	 
	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_8 ,	 
	 
 KI_TASK_SET_START_9 = ( 9 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Test Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / testtask.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : Protocol stack test task definitions	 
 **************************************************************************/	 
	 
 /* UPGRADE_COOLART should never be defined for a MS target build.	 
 * It is used exclusively for the testing of protocol stacks */	 
	 
	 
	 
	 
	 
	 
 KI_TASK_SET_STOP_9 ,	 
	 
 KI_TASK_SET_START_10 = ( 10 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Multimedia Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / mediatask.h#4 $	 
 * $Revision: #4 $	 
 * $DateTime: 2007 / 2 / 2 13 :54:44 $	 
 **************************************************************************	 
 * File Description : Multimedia task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deliberately does not have multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority , Stack Pool	 
 */	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MMAC_TASK_ID ,	 
 MMAC_HIGH_PRIORITY_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
 MF_PROCS0_TASK_ID ,	 
 MF_PROCS1_TASK_ID ,	 
 MF_RM_TASK_ID ,	 
 MF_COMMS_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MEDIA_CONTROLLER_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MDS_CONTROL_TASK_ID ,	 
 VIDEO_RENDER_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
 MES_CONTROL_TASK_ID ,	 
 MES_CAPTURE_TASK_ID ,	 
	 
	 
 CME_SM_SETUP_TASK_ID ,	 
 CME_AUDIO_LOW_PRI_TASK_ID ,	 
	 
	 
	 
	 
 MMCC_TASK_ID ,	 
	 
	 
	 
	 
	 
 AM_TASK_ID ,	 
	 
	 
	 
	 
 AU_DDR_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
 MMSC_CONTROLLER_TASK_ID ,	 
	 
	 
	 
	 
	 
 AU_ROUTER_TASK_ID ,	 
	 
	 
	 
 KI_TASK_SET_STOP_10 ,	 
	 
 /* END OF FILE */	 
	 
	 
	 
	 
	 
	 
	 
 KI_TASK_ID_END ,	 
 /* Task sets add one to the end of a set for the task set stop id ,	 
 ** so need to subtract one to get the max id. */	 
 KI_MAX_TASK_ID = KI_TASK_ID_END - 1 ,	 
 UNKNOWN_TASK_ID = 0xFFFF ,	 
	 
 /* This is the task id used by PassThru tasks in Genie.	 
 ** Do not send signals from target entities to this task	 
 ** as it does not exist on the target. */	 
 PASS_THRU_TASK_ID = 0 ,	 
	 
 UNKNOWN_TASK = UNKNOWN_TASK_ID	 
	 
 /* Any new TaskId which is to be recognised by GENIE should end in the	 
 ** string " _ID " ; conversely , any value which is not to be displayed by	 
 ** GENIE should NOT end in this string. */	 
	 
 } TaskId , KiTaskId;

typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef Int32 FrameTicks ;
typedef Int32 KernelTicks ;
typedef Int8 EmptySignal ;
typedef Int8 SignalNotYetDefined ;
typedef Int8 KiTimerIndex ;
typedef Int16 KiTimerId ;
typedef Int16 KiTimerUserValue ;
typedef Int8 EmptyCommand ;
typedef union CommandBodyTag
 {
 WaitCommand wait ;
 DelayCommand delay ;
 EmptyCommand start ;
 TransparentCommand transparent ;
 EmptyCommand stop ;
 EmptyCommand unused1 ;
 EmptyCommand unused2 ;
 EmptyCommand unused3 ;
 SubsequentSigsToTaskCommand subsequentSigsToTask ;
 TaskStateCommand taskState ;
 }
 CommandBody ;
//ICAT EXPORTED ENUM 
 typedef enum LlcFrameFormatTag 
 {	 
 FRAME_I ,	 
 FRAME_S ,	 
 FRAME_UI ,	 
 FRAME_U ,	 
 FRAME_INVALID	 
 } 
 LlcFrameFormat;

//ICAT EXPORTED UNION : LlcFrameFormat 
 typedef union ControlFieldTag 
 { /* Four types of LLC frame formats: */	 
 FormatI formatI ; /* I+S */	 
 FormatS formatS ;	 
 FormatUI formatUI ;	 
 FormatU formatU ;	 
 } 
 ControlField;

//ICAT EXPORTED STRUCT 
 typedef struct LlcHeaderTag 
 {	 
 LlcFrameFormat format ; /* I+S , S , UI or U */	 
 AddressField address ;	 
 ControlField control ;	 
 Int8 length ; /* LLC header length ( Address and Control fields ) */	 
 FrameError error ;	 
 } 
 LlcHeader;

typedef Int16 Mnc ;
typedef Int16 Mcc ;
typedef Int16 AccessTechnologyId ;
//ICAT EXPORTED STRUCT 
 typedef struct PlmnTag 
 {	 
 Mcc mcc ; /**< Mobile Country Code. */	 
 /* @ITEM_DESC@ Mobile Country Code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number*/	 
 Mnc mnc ; /**< Mobile Network Code. */	 
 /* @ITEM_DESC@ Mobile Network Code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number*/	 
 AccessTechnologyId accessTechnology ; /**< Access Technology: GSM_ACCESS_TECHNOLOGY , UTRAN_ACCESS_TECHNOLOGY or GSM_COMPACT_ACCESS_TECHNOLOGY. */	 
 /* @ITEM_DESC@ Access Technology ID. For coding see ETSI TS 131 102 . @ITEM_MODE@ ReadWrite @ITEM_UNIT@ bitmap	 
 @ITEM_DEPENDENCY@ ETSI TS 131 102 . */	 
 } 
 Plmn;

//ICAT EXPORTED STRUCT 
 typedef struct SimPlmnTag 
 {	 
 /* @STRUCT_DESC@ PLMN with MNC length */	 
 Plmn plmn ; /**< PLMN. */	 
 /* @ITEM_DESC@ PLMN @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see structure definition */	 
 Boolean mncThreeDigitsDecoding ; /**< Is three digit encoding used. */	 
 /* @ITEM_DESC@ Is three digit encoding used @ITEM_MODE@ ReadWrite @ITEM_UNIT@ on / off ( 0 -not active , 1 -active ) */	 
 } 
 SimPlmn;

//ICAT EXPORTED ENUM 
 typedef enum PlmnNameCodingSchemeTag 
 {	 
 PLMN_CODING_DEFAULT , /**< Default coding scheme. */	 
 PLMN_CODING_UCS2 /**< UCS2 coding scheme. */	 
 } 
 PlmnNameCodingScheme;

//ICAT EXPORTED ENUM 
 typedef enum FreqBandTag 
 {	 
 FreqBand_dcs1800Band ,	 
 FreqBand_pcs1900Band	 
 } 
 FreqBand;

typedef Int8 FullName [ ( ( 25 ) ) ] ;
typedef Int8 AbbrName [ ( ( 11 ) ) ] ;
typedef Int8 Initials [ ( 4 ) ] ;
typedef Int8 FormatSpecifier [ ( 14 ) ] ;
//ICAT EXPORTED STRUCT 
 typedef struct PlmnNameTag 
 {	 
 /* @STRUCT_DESC@ PLMN Name */	 
 PlmnNameCodingScheme plmnCoding ; /**< Coding scheme for ' full ' , ' abbr ' & ' initials ' . */	 
 /* @ITEM_DESC@ @ITEM_MODE@ ReadWrite @ITEM_UNIT@ See enum for values*/	 
 FullName full ; /**< Full network name ( long ) . */	 
 AbbrName abbr ; /**< Abbreviated network name ( short ) . */	 
 Initials initials ; /**< Country initials. */	 
 FormatSpecifier format ; /**< Format specifier. */	 
 } 
 PlmnName;

//ICAT EXPORTED STRUCT 
 typedef struct PlmnIdTag 
 {	 
 /* @STRUCT_DESC@ PLMN ID */	 
	 
 Boolean present ; /**< Is present. */	 
 /* @ITEM_DESC@ Is present @ITEM_MODE@ ReadWrite @ITEM_UNIT@ on / off ( 0 -not active , 1 -active ) */	 
 Plmn plmn ; /**< PLMN. */	 
 /* @ITEM_DESC@ PLMN @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see structure definition */	 
 Boolean threeDigitMnc ; /**< Is the MNC three digit. */	 
 /* @ITEM_DESC@ Is present @ITEM_MODE@ ReadWrite @ITEM_UNIT@ on / off ( 0 -not active , 1 -active ) */	 
 PlmnName plmnName ; /**< PLMN Name. */	 
 /* @ITEM_DESC@ PLMN Name @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see structure definition */	 
 } 
 PlmnId;

typedef Int16 Arfcn ;
typedef Int16 ReducedFrameNumber ;
typedef Int8 Bsic ;
typedef Int8 Tsc ;
typedef SignedInt32 Otd ;
//ICAT EXPORTED ENUM 
 typedef enum BandTag 
 {	 
 GSM_BAND = 0 ,	 
 DCS_BAND = 1 ,	 
 PCS_BAND = 2 ,	 
 EGSM_BAND = 3 ,	 
 GSM_450_BAND = 4 ,	 
 GSM_480_BAND = 5 ,	 
 GSM_850_BAND = 6 ,	 
 NUM_BANDS , /**< The number of bands supported by Layer 1 and RR */	 
 /*2013.12.30 , mod by Xili for CQ00051491 , begin*/	 
 /* used by SIMAT */	 
 LTE_BAND = 0xFD ,	 
 /*2013.12.30 , mod by Xili for CQ00051491 , end*/	 
 /* used by MM */	 
 UMTS_BAND = 0xFE ,	 
 INVALID_BAND = 0xFF	 
 } 
 Band;

//ICAT EXPORTED ENUM 
 typedef enum BandModeTag 
 {	 
 /* @ENUM_DESC@ GSM Band Mode */	 
 ZERO_BAND_MODE = 0x0000 ,	 
 PGSM_MODE = 0x0001 , /**< Autoband enabled */	 
 EGSM_MODE = ( 0x0001 + 0x0008 ) , /**< Autoband enabled */	 
 DCS_MODE = 0x0002 , /**< Autoband enabled */	 
 PGSM_DCS_MODE = 0x0001 + 0x0002 , /**< Autoband enabled */	 
 EGSM_DCS_MODE = ( 0x0001 + 0x0008 ) + 0x0002 , /**< Autoband enabled */	 
 PCS_MODE = 0x0004 , /**< Autoband enabled */	 
 PGSM_PCS_MODE = 0x0001 + 0x0004 , /**< Autoband enabled */	 
 EGSM_PCS_MODE = ( 0x0001 + 0x0008 ) + 0x0004 , /**< Autoband enabled */	 
	 
 PGSM_PCS_MODE_LOCK = 0x0001 + 0x0004 + 0x0200 , /**< LOCK the MS to PGSM / PCS mode. Autoband DISABLED. For use in testing and 900 / 1900 countries only */	 
 EGSM_PCS_MODE_LOCK = ( 0x0001 + 0x0008 ) + 0x0004 + 0x0200 , /**< LOCK the MS to EGSM / PCS mode. Autoband DISABLED. For use in testing and 900 / 1900 countries only */	 
 EGSM_DCS_MODE_LOCK = ( 0x0001 + 0x0008 ) + 0x0002 + 0x0200 , /**< LOCK the MS to EGSM / DCS mode. Autoband DISABLED. For use in testing and 900 / 1800 countries only */	 
 DCS_MODE_LOCK = 0x0002 + 0x0200 , /**< LOCK the MS to DCS mode. Autoband DISABLED. For use in testing only */	 
 PCS_MODE_LOCK = 0x0004 + 0x0200 , /**< LOCK the MS to PCS mode. Autoband DISABLED. For use in testing only */	 
 EGSM_MODE_LOCK = ( 0x0001 + 0x0008 ) + 0x0200 , /**< LOCK the MS to EGSM mode. Autoband DISABLED. For use in testing only */	 
	 
 /* Band mode for GSM850 support */	 
 GSM850_MODE = 0x0040 , /**< Autoband enabled */	 
 GSM850_PCS_MODE = 0x0040 + 0x0004 , /**< Autoband enabled */	 
 GSM850_PCS_MODE_LOCK = 0x0040 + 0x0004 + 0x0200 , /**< LOCK the MS to GSM850 / PCS1900 mode. */	 
 GSM850_PCS_EGSM_DCS_MODE = 0x0040 + 0x0004 + EGSM_DCS_MODE ,	 
 GSM850_DCS_EGSM_MODE = 0x0040 + EGSM_DCS_MODE , /**< Autoband enabled */	 
 GSM850_PCS_EGSM_MODE = 0x0040 + EGSM_PCS_MODE , /**< Autoband enabled */	 
	 
 GSM850_DCS_MODE = 0x0040 + 0x0002 , /**< Autoband enabled */	 
 GSM850_MODE_LOCK = 0x0040 + 0x0200 , /**< LOCK the MS to GSM850 mode. Autoband DISABLED. For use in testing only */	 
 GSM850_DCS_MODE_LOCK = 0x0040 + 0x0002 + 0x0200 , /**< LOCK the MS to GSM850 / DCS1800 mode. Autoband DISABLED. For use in testing and 850 / 1800 countries only */	 
 GSM850_DCS_EGSM_MODE_LOCK = 0x0040 + EGSM_DCS_MODE + 0x0200 , /**< LOCK the MS to GSM850 / DCS1800 mode. Autoband DISABLED. For use in testing and 850 / 1800 countries only */	 
 GSM850_PCS_EGSM_MODE_LOCK = 0x0040 + EGSM_PCS_MODE + 0x0200 , /**< LOCK the MS to GSM850 / DCS1800 mode. Autoband DISABLED. For use in testing and 850 / 1800 countries only */	 
	 
 EGSM_DCS_PCS_MODE = ( 0x0001 + 0x0008 ) + 0x0002 + 0x0004 ,	 
 EGSM_DCS_PCS_MODE_LOCK = ( 0x0001 + 0x0008 ) + 0x0002 + 0x0004 + 0x0200 ,	 
	 
 /* used by MM */	 
 UMTS_MODE = 0x0100 ,	 
 /* used by MM */	 
 LTE_MODE = 0x0400 ,	 
	 
 QUAD_MODE = 0x0002 + 0x0004 + ( 0x0001 + 0x0008 ) + 0x0040 ,	 
 QUAD_MODE_LOCK = QUAD_MODE + 0x0200 ,	 
	 
 /* This is used to verify value is within the allowed range. */	 
 /* Note that the value should be updated if new bit is added.*/	 
 ALL_BITS_BAND_MODE = 0x0200 + 0x0100 + 0x0080 + 0x0040 + ( 0x0010 + 0x0020 ) + ( 0x0001 + 0x0008 ) + 0x0002 + 0x0004	 
 + 0x0400 ,	 
	 
 INVALID_BAND_MODE = 0xffff	 
 } 
 BandMode;

//ICAT EXPORTED ENUM 
 typedef enum NetworkModeTag 
 {	 
 /* @ENUM_DESC@ used in PLMN search to determine the networks to search */	 
	 
 NMODE_GSM ,	 
 NMODE_UMTS ,	 
 NMODE_LTE ,	 
 NMODE_GSM_UMTS ,	 
 NMODE_GSM_LTE ,	 
 NMODE_UMTS_LTE ,	 
 NMODE_GSM_UMTS_LTE ,	 
 NMODE_NULL	 
 } 
 NetworkMode;

//ICAT EXPORTED ENUM 
 typedef enum NetworkModeBitMaskTag 
 {	 
 NW_MODE_NO_RATS = 0 ,	 
 NW_MODE_BIT_GSM = 0x01 ,	 
 NW_MODE_BIT_UMTS = 0x02 ,	 
 NW_MODE_BIT_DUAL_RAT = NW_MODE_BIT_GSM | NW_MODE_BIT_UMTS ,	 
 NW_MODE_BIT_LTE = 0x04 ,	 
 NW_MODE_BIT_GSM_LTE = NW_MODE_BIT_GSM | NW_MODE_BIT_LTE ,	 
 NW_MODE_BIT_UMTS_LTE = NW_MODE_BIT_UMTS | NW_MODE_BIT_LTE ,	 
 NW_MODE_BIT_TRI_RAT = NW_MODE_BIT_DUAL_RAT | NW_MODE_BIT_LTE ,	 
 NW_MODE_BIT_ALL_RATS = NW_MODE_BIT_TRI_RAT ,	 
 NW_MODE_BIT_MAX	 
 } NetworkModeBitMask;

//ICAT EXPORTED ENUM 
 typedef enum UmtsWorkModeTag 
 {	 
 UWMODE_TDD ,	 
 UWMODE_FDD	 
 } 
 UmtsWorkMode;

//ICAT EXPORTED ENUM 
 typedef enum LteOperateModeTag 
 {	 
 PS_MODE_2 ,	 
 CS_PS_MODE_1 ,	 
 CS_PS_MODE_2 ,	 
 PS_MODE_1	 
 } 
 LteOperateMode;

//ICAT EXPORTED ENUM 
 typedef enum LteUsageSettingTag 
 {	 
 VOICE_CENTRIC ,	 
 DATA_CENTRIC	 
 } 
 LteUsageSetting;

//ICAT EXPORTED ENUM 
 typedef enum LteVoiceDomainPreferTag 
 {	 
 CS_VOICE_ONLY ,	 
 IMS_PS_VOICE_ONLY ,	 
 CS_PS_VOICE_PREFER_IMS_PS_VOICE_SEC ,	 
 IMS_PS_VOICE_PREFER_CS_VOICE_SEC	 
 } 
 LteVoiceDomainPrefer;

//ICAT EXPORTED ENUM 
 typedef enum LteSmsDomainTag 
 {	 
 SMS_OVER_IMS ,	 
 SMS_OVER_SGS	 
 } 
 LteSmsDomain;

//ICAT EXPORTED ENUM 
 typedef enum AccessBurstTypeTag 
 {	 
 EIGHT_BIT_ACCESS_BURST = 0 ,	 
 ELEVEN_BIT_ACCESS_BURST = 1 ,	 
 ACCESS_BURST_NOT_DEFINED = 2	 
 } 
 AccessBurstType;

typedef Int32
 Tmsi ;
typedef Int16
 AccessClass ;
typedef Int16
 Lac ;
typedef Int8
 Rac ;
typedef Int16
 CellId ;
typedef Int8
 TmsiTime ;
typedef Int16
 Tac ;
typedef Int32
 MTmsi ;
typedef Int16
 MmeGroupId ;
typedef Int8
 MmeCode ;
//ICAT EXPORTED STRUCT 
 typedef struct TaiTag 
 {	 
 Mcc mcc ;	 
 Mnc mnc ;	 
 Tac tac ;	 
 Int8 rawIe [ 5 ] ;	 
 } 
 Tai;

typedef Tai TrackingAreaIdentityElement ;
//ICAT EXPORTED ENUM 
 typedef enum PartialTaiListTypeTag 
 {	 
 PARTIAL_TAI_LIST_TYPE_0 = 0 , /* Type of list = " 0 " */	 
 PARTIAL_TAI_LIST_TYPE_1 = 1 , /* Type of list = " 1 " */	 
 PARTIAL_TAI_LIST_TYPE_2 = 2 /* Type of list = " 10 " */	 
 } 
 PartialTaiListType;

//ICAT EXPORTED STRUCT 
 typedef struct PartialTaiList_0Tag 
 {	 
 Mcc mcc ;	 
 Mnc mnc ;	 
 Tac tac [ 16 ] ;	 
 } 
 PartialTaiList_0;

typedef PartialTaiList_0 PartialTaiList_1 ;
//ICAT EXPORTED STRUCT 
 typedef struct PartialTaiList_2Tag 
 {	 
 Tai tai [ 16 ] ;	 
 } 
 PartialTaiList_2;

//ICAT EXPORTED UNION:PartialTaiListType 
 typedef union TaiListUnionElementTag 
 
 {	 
 PartialTaiList_0 taiListType_0 ;	 
 PartialTaiList_1 taiListType_1 ;	 
 PartialTaiList_2 taiListType_2 ;	 
 } TaiListUnion;

//ICAT EXPORTED STRUCT 
 typedef struct PartialTaiListElementTag 
 {	 
 PartialTaiListType taiListType ;	 
 Int16 numOfElements ; /* 1 ~16 */	 
 TaiListUnion taiListUnion ;	 
 } 
 PartialTaiList;

//ICAT EXPORTED STRUCT 
 typedef struct TaiListElementTag 
 { /* Refer to 9.900000 .3.33-24.301 */	 
 Int16 numOfList ; /* Number of Partial tracking area identity list */	 
 PartialTaiList partialTaiList [ 16 ] ;	 
 } 
 TaiListElement;

//ICAT EXPORTED STRUCT 
 typedef struct GutiTag 
 {	 
 Int8 guti [ 10 ] ;	 
 } 
 Guti;

//ICAT EXPORTED ENUM 
 typedef enum TinTag 
 {	 
 TIN_PTMSI ,	 
 TIN_GUTI ,	 
 TIN_RAT_RELATED_TMSI ,	 
 TIN_DELETED	 
 } 
 Tin;

//ICAT EXPORTED ENUM 
 typedef enum MsOperationModeTag 
 {	 
 MS_OPERN_NORMAL = 0x00 , /* normal operation */	 
 MS_OPERN_TA = 0x80 , /* type approval operation */	 
 MS_OPERN_NORMAL_PLUS_SPECIFIC = 0x01 , /* normal + specific operation */	 
 MS_OPERN_TA_PLUS_SPECIFIC = 0x81 , /* type approval + specific operation */	 
 MS_OPERN_MAINTENANCE = 0x02 , /* maintenance operation */	 
 MS_OPERN_CELL_TEST = 0x04 /* cell test operation */	 
 } 
 MsOperationMode;

//ICAT EXPORTED ENUM 
 typedef enum KeySequenceTag 
 {	 
 KEY_SEQUENCE_0 = 0 ,	 
 KEY_SEQUENCE_1 = 1 ,	 
 KEY_SEQUENCE_2 = 2 ,	 
 KEY_SEQUENCE_3 = 3 ,	 
 KEY_SEQUENCE_4 = 4 ,	 
 KEY_SEQUENCE_5 = 5 ,	 
 KEY_SEQUENCE_6 = 6 ,	 
 NO_KEY_SEQUENCE_AVAILABLE = 7	 
 } 
 KeySequence;

//ICAT EXPORTED STRUCT 
 typedef struct LocationAreaIdTag 
 {	 
 Mcc mcc ;	 
 /* @ITEM_DESC@ Mobile Country Code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ code*/	 
 Mnc mnc ;	 
 /* @ITEM_DESC@ Mobile Network Code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ code*/	 
 Lac lac ;	 
 /* @ITEM_DESC@ Location area code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ code*/	 
 Int8 rawIe [ 5 ] ;	 
 /* @ITEM_DESC@ Information as read on SI @ITEM_MODE@ ReadWrite @ITEM_UNIT@ */	 
 } 
 LocationAreaIdElement;

typedef LocationAreaIdElement Lai ;
typedef LocationAreaIdElement LocationAreaId ;
//ICAT EXPORTED STRUCT 
 typedef struct EquivalentPlmnTag 
 {	 
 /* @STRUCT_DESC@ Equivalent PLMN */	 
 Mcc mcc ;	 
 /* @ITEM_DESC@ Mobile Country Code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number */	 
 Mnc mnc ;	 
 /* @ITEM_DESC@ Mobile Network Code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number */	 
 } 
 EquivalentPlmn;

//ICAT EXPORTED STRUCT 
 typedef struct EquivalentPlmnListTag 
 {	 
 /* @STRUCT_DESC@ List of Equivalent PLMNs */	 
 Int16 numPlmn ;	 
 /* @ITEM_DESC@ Number of PLMNs in the list @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number */	 
 EquivalentPlmn plmn [ 16 ] ;	 
 /* @ITEM_DESC@ Array of Equivalent PLMNs @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see structure definition */	 
 } 
 EquivalentPlmnListElement;

typedef EquivalentPlmnListElement EquivalentPlmnList ;
//ICAT EXPORTED STRUCT 
 typedef struct ChannelBitMapTag 
 {	 
 Boolean valid ;	 
 Int8 channelData [ 128 ] ;	 
 } 
 BaList;

//ICAT EXPORTED ENUM 
 typedef enum MmErrorCauseTag 
 {	 
 MM_ERROR_UNEX_CAMP_REQ ,	 
 MM_ERROR_UNEX_REG_REQ ,	 
 MM_ERROR_UNEX_NREG_REQ ,	 
 MM_ERROR_UNEX_PLMN_LIST_REQ ,	 
 MM_ERROR_UNEX_PLMN_LIST_RRC_CONN_EXIST_REQ ,	 
 MM_ERROR_UNEX_CAMP_REQ_IN_REG_PROC ,	 
 MM_ERROR_SIM_PROBLEM	 
 } 
 MmErrorCause;

//ICAT EXPORTED ENUM 
 typedef enum MmStateTag /* defined in 4.100000 .2.1.1 */ 
 {	 
 /* GRR */	 
 /* connection y / n */	 
 M0_MM_NULL = 0 , /* n */	 
 M3_WAIT_FOR_LOC_UPDATE_RESPONSE = 3 , /* y */	 
 M5_WAIT_FOR_OUTGOING_MM_CONNECTION = 5 , /* y */	 
 M6_MM_CONNECTION_ACTIVE = 6 , /* y */	 
 M7_IMSI_DETACH_INITIATED = 7 , /* y */	 
 M9_WAIT_FOR_NETWORK_COMMAND = 9 , /* y */	 
 M10_LOCATION_UPDATE_REJECTED = 10 , /* y */	 
 M13_RR_CONN_PENDING_LOC_UPDATING = 13 , /* n */	 
 M14_RR_CONN_PENDING_MM_CONNECTION = 14 , /* n */	 
 M15_RR_CONN_PENDING_IMSI_DETACH = 15 , /* n */	 
 M17_WAIT_FOR_CM_REESTABLISH = 17 , /* n */	 
 M18_WAIT_FOR_RR_ACTIVE = 18 , /* n */	 
 M20_WAIT_FOR_ADDITIONAL_OUTGOING_MM_CONNECTION = 20 , /* y */	 
	 
 M23_LOCATION_UPDATE_PENDING = 23 ,	 
 M24_IMSI_DETACH_PENDING = 24 ,	 
	 
	 
	 
 M25_RR_CONNECTION_RELEASE_NOT_ALLOWED = 25 ,	 
	 
	 
	 
 M19_MM_IDLE_NORMAL_SERVICE = 191 , /* state 19.100000 */ /* n */	 
 M19_MM_IDLE_ATTEMPTING_TO_UPDATE = 192 , /* state 19.200000 */ /* n */	 
 M19_MM_IDLE_LIMITED_SERVICE = 193 , /* state 19.300000 */ /* n */	 
 M19_MM_IDLE_NO_IMSI = 194 , /* state 19.400000 */ /* n */	 
 M19_MM_IDLE_NO_CELL_AVAILABLE = 195 , /* state 19.500000 */ /* n */	 
 M19_MM_IDLE_LOC_UPDATE_NEEDED = 196 , /* state 19.600000 */ /* n */	 
	 
 M19_MM_IDLE_ECALL_INACTIVE = 197 , /* state 19.110000 */ /*added by xyma for CQ00100279 20150814 */	 
 /*	 
 ** Other MM states are not implemented ; they are insufficient to	 
 ** describe behaviour.	 
 */	 
 MM_NUM_STATES /* leave as last constant */	 
 } 
 MmState;

//ICAT EXPORTED ENUM 
 typedef enum UmmStateTag 
 {	 
 UMM_DETACHED ,	 
 UMM_IDLE ,	 
 UMM_CONNECTED ,	 
 NUM_UMM_STATES	 
 } UmmState;

//ICAT EXPORTED ENUM 
 typedef enum EmmEpsStateTag 
 {	 
 EMM_DETACHED ,	 
 EMM_IDLE ,	 
 EMM_CONNECTED ,	 
 EMM_IDLE_SUSPEND , // add by xyma for CQ00125818 2021.100000 .4	 
 NUM_EMM_STATES	 
 } 
 EmmEpsState;

//ICAT EXPORTED ENUM 
 typedef enum SRStateTag 
 {	 
 S_START = 0 ,	 
 S_SUCCESS ,	 
 S_CANCEL ,	 
 S_FAIL	 
 } SRState;

//ICAT EXPORTED ENUM 
 typedef enum EmmStateTag /* defined in 24301 5.100000 .3 */ 
 {	 
 EMM_NULL = 0 ,	 
 EMM_REGISTERED_INITIATED = 1 ,	 
 EMM_DEREGISTERED_INITIATED = 2 ,	 
 EMM_TRACKING_AREA_UPDATING_INITIATED = 3 ,	 
 EMM_REGISTERED_NORMAL_SERVICE = 10 ,	 
 EMM_REGISTERED_UPDATE_NEEDED = 12 ,	 
 EMM_REGISTERED_ATTEMPTING_TO_UPDATE = 13 ,	 
 EMM_REGISTERED_NO_CELL_AVAILABLE = 14 ,	 
 EMM_REGISTERED_LIMITED_SERVICE = 15 ,	 
 EMM_REGISTERED_ATTEMPTING_TO_UPDATE_MM = 16 ,	 
 EMM_DEREGISTERED_NORMAL_SERVICE = 20 ,	 
 EMM_DEREGISTERED_LIMITED_SERVICE = 21 ,	 
 EMM_DEREGISTERED_ATTACH_NEEDED = 22 ,	 
 EMM_DEREGISTERED_ATTEMPTING_TO_ATTACH = 23 ,	 
 EMM_DEREGISTERED_NO_IMSI = 24 ,	 
 EMM_DEREGISTERED_NO_CELL_AVAILABLE = 25 ,	 
 EMM_DEREGISTERED_PLMN_SEARCH = 27 ,	 
 EMM_REGISTERED_IMSI_DETACH_INITIATED = 28 ,	 
 EMM_SERVICE_REQUEST_INITIATED = 29 ,	 
 EMM_NUM_STATES /* leave as last constant */	 
 } 
 EmmState;

//ICAT EXPORTED ENUM 
 typedef enum EmmSpecificProcedureTag 
 {	 
 EPS_ONLY_ATTACH_PROC = 0 ,	 
 EMM_COMBINED_ATTACH_PROC ,	 
 EMM_PERIODIC_TA_PROC ,	 
 EMM_NORMAL_TA_PROC ,	 
 EMM_COMBINED_TA_PROC ,	 
 EMM_COMBINED_TA_WITH_IMSI_PROC ,	 
 EPS_ONLY_DETACH_PROC ,	 
 EPS_IMSI_DETACH_PROC ,	 
 EPS_ONLY_MT_DETACH ,	 
 EPS_MT_DETACH_REATTACH ,	 
 EMM_COMBINED_DETACH_PROC ,	 
 EMM_CELL_UPDATE_PROC ,	 
 EMM_WAIT_FOR_ESM_RESP_FOR_TAU ,	 
 EMM_WAIT_FOR_ESM_RESP_FOR_ATTACH ,	 
 EMM_SERVICE_REQUEST_PROC ,	 
 EMM_WAIT_FOR_ESM_RESP_FOR_PAGING ,	 
 /* added by xyma for CQ00059052 , 2014.040000 .18 , begin*/	 
 EPS_EMERGENCY_ATTACH_PROC ,	 
 /* added by xyma for CQ00059052 , 2014.040000 .18 , end*/	 
 NO_EMM_SPECIFIC_PROC	 
 } EmmSpecificProcedure;

//ICAT EXPORTED ENUM 
 typedef enum EmmCommonProcedureTag 
 {	 
 EMM_EPS_AUTHEN_PROC = 0 ,	 
 /* All the other EMM common procedures are single signal procedures so are not really needed here */	 
 NO_EMM_COMMON_PROC	 
 } EmmCommonProcedure;

//ICAT EXPORTED ENUM 
 typedef enum EmmProcedureStatusTag 
 {	 
 EMM_AWAITING_EXECUTION = 0 ,	 
 EMM_EXECUTING ,	 
 EMM_AWAITING_COMPLETION ,	 
 EMM_NO_ACTIVE_PROC	 
 } EmmProcedureStatus;

//ICAT EXPORTED STRUCT 
 typedef struct EmmProcedureTag 
 {	 
 EmmSpecificProcedure emmSpecificProc ;	 
 EmmCommonProcedure emmCommonProc ;	 
 EmmProcedureStatus emmSpecificProcStatus ;	 
 } EmmProcedure;

//ICAT EXPORTED ENUM 
 typedef enum EpsOptPreferModeTag 
 {	 
 EPS_OPT_CP_ONLY ,	 
 EPS_OPT_UP_ONLY ,	 
 EPS_OPT_CP_PREFER ,	 
 EPS_OPT_UP_PREFER ,	 
 EPS_OPT_RESERVED = 0xFF	 
 } 
 EpsOptPreferMode;

//ICAT EXPORTED ENUM 
 typedef enum CsrProcIdTag 
 {	 
 CSR_NO_PROC ,	 
 CSR_PROC_CSRR ,	 
 CSR_PROC_CSRP ,	 
 CSR_PROC_CSRS ,	 
 CSR_PROC_CSRC	 
 // CQ00070469 add begin	 
	 
	 
	 
 // CQ00070469 add end	 
 } 
 CsrProcId;

//ICAT EXPORTED ENUM 
 typedef enum CsrcStateTag 
 {	 
 CSRC_IDLE ,	 
 CSRC_AWAIT_CPHY_FIND_CELL_CNF ,	 
 CSRC_AWAIT_SYS_INFO ,	 
 CSRC_AWAIT_CPHY_CELL_SELECT_CNF ,	 
 CSRC_AWAIT_CPHY_NEXT_CELL_CNF ,	 
 /* PTK_CQ00236868 begin */	 
 CSRC_SEARCH_ABORTING_WAIT_L1_CNF	 
 /* PTK_CQ00236868 end */	 
 } 
 CsrcState;

//ICAT EXPORTED ENUM 
 typedef enum CsrrReselectorStateTag 
 {	 
	 
 CSRR_AWAIT_RESELECT_TO_UMTS_FAIL_CNF ,	 
 CSRR_AWAIT_RESELECTION_TO_GSM ,	 
 CSRR_SUSPENDED_DUE_TO_CCOFU ,	 
	 
 CSRR_IDLE ,	 
 CSRR_AWAIT_MEASUREMENTS ,	 
 CSRR_AWAIT_BCH_DECODING_CNF ,	 
 CSRR_AWAIT_SYS_INFO ,	 
 CSRR_AWAIT_L1_CAMPED_ON_CELL ,	 
 CSRR_AWAIT_PHY_RESYNCH_TO_SERV_CELL ,	 
 CSRR_RANKING_CSRP_ACTIVE ,	 
 CSRR_ABORTING	 
 ,	 
 CSRR_AWAIT_RESELECTION_TO_LTE ,	 
 CSRR_AWAIT_DEACTIVATE_CNF	 
 } 
 CsrrReselectorState;

//ICAT EXPORTED ENUM 
 typedef enum CsrpPlmsStateTag 
 {	 
 CSRP_PLMS_NOT_SEARCHING , /* idle */	 
 CSRP_PLMS_WAIT_PLMS_FREQ_SCAN , /* RSSI scan is done by PLMS task */	 
 CSRP_PLMS_UMTS_WAIT_FOR_BCH_ESTABLISH , /* Waiting for L1 to open BCH */	 
 CSRP_PLMS_UMTS_READING_SIBS , /* Reading BCCH info */	 
 CSRP_PLMS_UMTS_WAIT_FOR_BCH_RELEASE , /* Waiting for L1 to close BCH */	 
 CSRP_PLMS_GSM_READING_SIBS , /* Reading BCCH info */	 
 CSRP_PLMS_LTE_READING_SIBS , /* Reading BCCH info */	 
 CSRP_PLMS_LTE_WAIT_FOR_BCH_RELEASE /* Waiting for L1 to close BCH */	 
	 
 } 
 CsrpPlmsState;

//ICAT EXPORTED ENUM 
 typedef enum CsrpActiveStateTag 
 {	 
 CSRP_STATE_NOT_SEARCHING , /* idle */	 
 CSRP_STATE_ACTIVE , /* active */	 
 CSRP_STATE_ABORTING_AWAIT_PLMS , /* Waiting for PLMS to trigger CSRP abort */	 
 CSRP_STATE_ABORTING_AWAIT_L1_CNF , /* Waiting for L1 CNF so abort can take place */	 
 CSRP_STATE_SUSPENDING_AWAIT_PLMS , /* Waiting for PLMS to trigger CSRP suspend */	 
 CSRP_STATE_SUSPENDING_AWAIT_L1_CNF , /* Waiting for L1 CNF so suspend can take place */	 
 CSRP_STATE_SUSPENDED , /* PLMN search process is suspended */	 
 CSRP_STATE_COMPLETING_AWAIT_L1_CNF /*Waiting for L1 to deactivate before completing search*/	 
 } 
 CsrpActiveState;

//ICAT EXPORTED ENUM 
 typedef enum CsrsSearchStatusTag 
 {	 
 CSRS_NOT_SEARCHING ,	 
 CSRS_SEARCH_WAIT_FOR_SCAN_CNF ,	 
 CSRS_SEARCH_WAIT_FOR_SEARCH_CNF ,	 
 CSRS_SEARCH_WAIT_FOR_SEARCH_BCH ,	 
 CSRS_SEARCH_WAIT_FOR_CHECK_PLMN_REJ_CNF ,	 
 CSRS_SEARCH_WAIT_FOR_CHECK_PLMN_REJ_BCH ,	 
 CSRS_SEARCH_WAIT_PHY_DEACTIVATE_CNF ,	 
 CSRS_SEARCH_ABORTING_WAIT_L1_CNF ,	 
 CSRS_SEARCH_WAIT_FOR_PLMS , // search is ongoing in PLMS	 
 CSRS_SEARCH_WAIT_FB_BCH_CNF , // Wating for CphyFgBchCnf	 
 CSRS_SEARCH_WAIT_PLMS_ABORT , // Wating for PLMS to Abort the search	 
 CSRS_SEARCH_WAIT_FOR_IRAT_RESEL , // ICS started in another RAT waiting for reselection to URR	 
 CSRS_SEARCH_WAIT_HAW_INIT ,	 
 CSRS_SEARCH_WAIT_FB_BCH_CNF_BEFORE_PLMS_ABORT // Wating for CphyFgBchCnf Before aborting PLMS	 
 } 
 CsrsSearchStatus;

//ICAT EXPORTED ENUM 
 typedef enum UrrCSRExitCodesTag 
 {	 
 // CSRC	 
 CSRC_CELL_SELECTION_FAILURE_OOS = 1 ,	 
 CSRC_CELL_CAMPED_ON_SUITABLE_CELL ,	 
 CSRC_CSRTU_FAILURE ,	 
 CSRC_CSRTU_T3174_EXPIRY ,	 
 CSRC_REDIRECTION_FAILED ,	 
 /* PTK_CQ00236868 begin */	 
 CSRC_ABORT_REQUEST ,	 
 /* PTK_CQ00236868 end */	 
 // CSRS	 
 CSRS_ABORT_REQUEST ,	 
 CSRS_INITIAL_CELL_SELECTION_SUCCESS ,	 
 CSRS_FAIL_TO_SELECT_ANY_CELL ,	 
 // CSRR	 
 CSRR_ABORT_REQUEST ,	 
 // CSRR_START_INTERNAL_PLMN_SEARCH , / * CQ00094524 * /	 
 CSRR_START_ICS_IDLE_OOS ,	 
 CSRR_COMPLETE_RESELECTION ,	 
 CSRR_OOS_DETECTED ,	 
 CSRR_RESELECTION_REQUIRED ,	 
 CSRR_ABORT_SUSPENDED_PLMN ,	 
 CSRR_START_CSRR_PROC ,	 
 // CSRP	 
 CSRP_START_CELL_RESELECTION ,	 
 CSRP_ABORT_REQUEST ,	 
 CSRP_ABORT_GSM_MODE_PLMN ,	 
 CSRP_ABORT_LTE_MODE_PLMN ,	 
 CSRP_SUSPENSION_COMPLETE ,	 
 CSRP_FG_GSM_OOS_CONN_NON_DCH_COMPLETE	 
 // CQ00070469 add begin	 
	 
 // CQ00070469 add end	 
 } 
 UrrCSRExitCodes;

//ICAT EXPORTED ENUM 
 typedef enum UrrCerStateTag 
 {	 
 CER_IDLE ,	 
 CER_CONNECTING_WAIT_TX ,	 
 CER_RETRYING_WAIT_TX ,	 
 CER_WAIT_CONNECTION_SETUP ,	 
 CER_WAIT_SETUP_COMPLETE_TX ,	 
 CER_REJECTED_WAIT ,	 
 CER_REJECTED_NEW_FREQ_WAIT_SELECTION ,	 
 CER_REJECTED_SAME_FREQ_WAIT_SIBS ,	 
 CER_REJECTED_DIFF_FREQ_WAIT_SIBS ,	 
 CER_REJECTED_NEW_RAT_WAIT_SELECTION ,	 
 CER_DISC_DCH_WAIT_TX ,	 
 CER_DISC_FACH_WAIT_TX ,	 
 CER_CONNECTED ,	 
 CER_WAIT_IDT_TX_CONFIRM ,	 
 CER_WAIT_RBC_PROCESS_RRC_CONN_SETUP ,	 
 CER_WAIT_RACH_MEAS_RESULTS ,	 
 CER_WAIT_RBC_PROCESS_RRC_CON_RELEASE_FACH ,	 
 CER_WAIT_RBC_PROCESS_RRC_CON_RELEASE_DCH ,	 
 CER_DISC_DCH_WAIT_ALL_SIBS_DISTRIBUTED ,	 
 CER_WAIT_CSR_PLMN_ABORT_CNF ,	 
	 
 CER_WAIT_IRAT_DS_SUSPEND_CNF ,	 
	 
 CER_WAIT_CELL_UPDATE_OCCURRED ,	 
 CER_WAIT_RBC_MOVE_TO_FACH	 
 } 
 UrrCerState;

typedef union KiStateMachinesStateTag
 {
 Int16 genState ;
 MmState MM_state ;

 EmmState EMM_state ;



 CsrProcId CSR_Active_Proc ;
 CsrcState CSRC_State ;
 CsrsSearchStatus CSRS_State ;
 CsrrReselectorState CSRR_State ;




 CsrpActiveState CSRP_State ;


 UrrCerState URR_CER_State ;


 } KiStateMachinesState ;
typedef SignalNotYetDefined KiMemReadReq ;
typedef SignalNotYetDefined KiMemReadCnf ;
typedef SignalNotYetDefined KiMemWriteReq ;
typedef SignalNotYetDefined KiMemWriteCnf ;
typedef SignalNotYetDefined KiMemReadMultiReq ;
typedef SignalNotYetDefined KiMemReadMultiCnf ;
typedef SignalNotYetDefined KiMemWriteMultiReq ;
typedef SignalNotYetDefined KiMemWriteMultiCnf ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef OSAFlagRef KiOsEventHandle ;
typedef OSASemaRef KiOsSemaphoreHandle ;
typedef OSATaskRef KiOsTaskHandle ;
typedef OSAMsgQRef KiOsMailboxHandle ;
typedef OSAPartitionPoolRef KiOsPoolHandle ;
typedef Int32 KiOsDynamicPoolHandle ;
typedef Int8 KiTaskSetIndex ;
typedef union GenericStructureTag
 {
 KiSigHeader header ;
 SignalStructure signal ;
 CommandStructure command ;
 LoggedSignalStructure loggedSignal ;
 }
 GenericStructure ;
typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
typedef UINT8 Int8 ;
typedef UINT16 Int16 ;
typedef UINT32 Int32 ;
DIAG_FILTER ( SW_PLAT , DIAGSIG , UPDATE_SIGNALS_FILTER_MATRIX_ERROR , DIAG_ERROR)  
 diagTextPrintf ( " Error allocating memory for new filter matrix. Old filter is still valid " );

//ICAT EXPORTED FUNCTION - SW_PLAT , DIAG , TurnSignalsOn 
 void TurnGKISignalsOn ( void ) 
 {	 
 UINT32 cpsr ;	 
	 
 diag_lock ( &cpsr ) ;	 
 SignalsTrace = 1 ;	 
 diag_unlock ( cpsr ) ;	 
	 
DIAG_FILTER ( SW_PLAT , DIAG , TurnSignalsOnReply , DIAG_INFORMATION)  
 diagTextPrintf ( " Signal trace is now ON " );

	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , DIAG , TurnSignalsOff 
 void TurnGKISignalsOff ( void ) 
 {	 
 UINT32 cpsr ;	 
	 
 diag_lock ( &cpsr ) ;	 
 SignalsTrace = 0 ;	 
 diag_unlock ( cpsr ) ;	 
	 
DIAG_FILTER ( SW_PLAT , DIAG , TurnSignalsOffReply , DIAG_INFORMATION)  
 diagTextPrintf ( " Signal trace is now OFF " );

	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , DIAG , getSignalsFilterMatrix 
 void getSignalsFilterMatrix ( void ) 
 {	 
 UINT32 filter_matrix_size ;	 
	 
 // if there ' s valid filter matrix	 
 if ( currentFilterLog )	 
 {		 
		 
 filter_matrix_size = currentFilterLogSize ;		 
		 
		 
		 
		 
DIAG_FILTER ( SW_PLAT , DIAGSIG , SIGNALS_FILTER_MATRIX_REPORT , DIAG_INFORMATION)  
 diagStructPrintf ( " %S " , currentFilterLog , filter_matrix_size );

		 
		 
 }	 
 // else , all signals have their default filter state	 
 else	 
 {		 
DIAG_FILTER ( SW_PLAT , DIAGSIG , DEFAULT_SIGNALS_FILTER_MATRIX_REPORT , DIAG_INFORMATION)  
 diagPrintf ( " 1 " );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , DIAG , setSignalFilter 
 void setSignalFilter ( SignalFilterInfoStruct *signalFilterInfo ) 
 {	 
 SignalRecord pSignal ;	 
	 
 pSignal.id = ( SignalId ) ( signalFilterInfo->SignalID ) ;	 
	 
 diagSetSignalFiltered ( &pSignal , signalFilterInfo->IsFiltered ) ;	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , DIAG , getSignalFilter 
 void getSignalFilter ( SignalFilterInfoStruct *signalFilterInfo ) 
 {	 
 SignalRecord pSignal ;	 
 BOOL isFiltered ;	 
	 
 pSignal.id = ( SignalId ) ( signalFilterInfo->SignalID ) ;	 
	 
	 
 isFiltered = diagSignalFiltered ( &pSignal ) ;	 
	 
	 
DIAG_FILTER ( SW_PLAT , DIAGSIG , SIGNAL_FILTER_REPORT , DIAG_INFORMATION)  
 diagPrintf ( " %d:%d " , signalFilterInfo->SignalID , isFiltered );

	 
 }

//ICAT EXPORTED FUNCTION - Diag , Utils , Test8KStructure 
 void _Test8KStructure ( void ) 
 {	 
 UINT32 i ;	 
 unsigned char* array ;	 
 array = ( unsigned char* ) ( DiagAlignMalloc ( 6 *1024 ) ) ;	 
 for ( i=0 ; i<6*1024 ; i++ )	 
 array [ i ] = ( unsigned char ) i ;	 
	 
DIAG_FILTER ( Diag , Utils , ST_8kTest , DIAG_INFORMATION)  
 diagStructPrintf ( " %S { St8kTest } " , ( void* ) array , ( 6 *1024 ) );

	 
	 
 DiagAlignFree ( array ) ;	 
 array=0 ;	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_comm.ppp
//PPL Source File Name : X:\\diag\\diag_comm\\src\\diag_comm.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

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

typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
typedef void ( *PDeviceFunctionVV ) ( void ) ;
typedef BOOL ( *PDeviceFunctionBV ) ( ) ;
typedef void ( *PDeviceFunctionVP ) ( void* ptr ) ;
//ICAT EXPORTED FUNCTION - ADEMO , CALL , Diag_Switch 
 void Diag_Switch ( ) 
 {	 
 if ( DeviceIf [ DIAG_COMMDEV_EXT ] .bIsConnected )	 
 {		 
 SetDeviceConection ( DIAG_COMMDEV_EXT , 0 ) ;		 
 }	 
 else	 
 {		 
 SetDeviceConection ( DIAG_COMMDEV_EXT , 1 ) ;		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , DIAG , TestDiagComm 
 void TestDiagComm ( void *Str ) 
 {	 
 UINT16 size = * ( ( UINT16* ) Str ) ;	 
 UINT8 *pData = ( UINT8* ) Str ;	 
	 
DIAG_FILTER ( SW_PLAT , DIAG , TestDiagCommReply , DIAG_INFORMATION)  
 diagStructPrintf ( " TestDiagCommReply " , pData , size );

	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_comm_if.ppp
//PPL Source File Name : X:\\diag\\diag_comm\\src\\diag_comm_if.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef TX_THREAD OS_Task_t ;
typedef TX_SEMAPHORE OS_Sema_t ;
typedef TX_SEMAPHORE OS_Mutex_t ;
typedef TX_TIMER OS_Timer_t ;
typedef TX_EVENT_FLAGS_GROUP OS_EventGroup_t ;
typedef TX_EVENT_FLAGS_GROUP OS_Flag_t ;
typedef void* OS_Hisr_t ;
typedef TX_BYTE_POOL OS_MemPool_t ;
typedef TX_BLOCK_POOL OS_PartitionPool_t ;
typedef STATUS NU_RTN_STATUS ;
typedef UINT32 OS_Proc_t ;
typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_comm_EXTif.ppp
//PPL Source File Name : X:\\diag\\diag_comm\\src\\diag_comm_EXTif.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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

typedef void* ( *alloc_fn ) ( size_t size ) ;
typedef void ( *free_fn ) ( pmsg* msg ) ;
typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
typedef char * char_ptr ;
typedef signed char int_8 , * int_8_ptr ;
typedef unsigned char uint_8 , * uint_8_ptr ;
typedef short int_16 , * int_16_ptr ;
typedef unsigned short uint_16 , * uint_16_ptr ;
typedef int int_32 , * int_32_ptr ;
typedef unsigned int uint_32 , * uint_32_ptr ;
typedef unsigned long boolean ;
typedef void * pointer ;
typedef pointer _usb_device_handle ;
typedef uint_32 USB_REGISTER , * USB_REGISTER_PTR ;
typedef uint_32 EHCI_FRAME_LIST_ELEMENT_POINTER ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef TX_THREAD OS_Task_t ;
typedef TX_SEMAPHORE OS_Sema_t ;
typedef TX_SEMAPHORE OS_Mutex_t ;
typedef TX_TIMER OS_Timer_t ;
typedef TX_EVENT_FLAGS_GROUP OS_EventGroup_t ;
typedef TX_EVENT_FLAGS_GROUP OS_Flag_t ;
typedef void* OS_Hisr_t ;
typedef TX_BYTE_POOL OS_MemPool_t ;
typedef TX_BLOCK_POOL OS_PartitionPool_t ;
typedef STATUS NU_RTN_STATUS ;
typedef UINT32 OS_Proc_t ;
typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
typedef int ( tpl_parse_t ) ( UINT8 , const unsigned char * , unsigned ) ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 MIN_BUFFERS_NUM ;	 
 // wait in the queue until sent - the worst case of task loop is diag_comm_extIF_tx_config.TASK_TIMER_PERIOD	 
 UINT8 TASK_TIMER_PERIOD ;	 
 UINT8 task_priority ;	 
 } DiagTransmitTxConfig;

//ICAT EXPORTED FUNCTION - Diag , Debug , ClearExtTxMinBuffToSend 
 void clearMinBuffToSendExtIf ( void ) 
 {	 
 clr_minBuffToSend=1 ;	 
 }

//ICAT EXPORTED FUNCTION - Diag , Debug , SetExtTxMinBuffToSend 
 void setMinBuffToSendExtIf ( void ) 
 {	 
 clr_minBuffToSend=0 ;	 
 }

DIAGM_TRACE( Diag , Utils , TraceStopUSB , " Diag USB queue cleared " );  
//ICAT EXPORTED FUNCTION - Diag , Utils , TxAddQueueEvent 
 void DiagCommExtIfTxEventQCallback ( UINT32 param ) 
 {	 
 OS_STATUS os_status ;	 
 ( void ) param ;	 
 // diag_multi_tx_timer_is_active=FALSE ;	 
 // count_timer++ ;	 
 os_status = OsaFlagSet ( dataExtIf . TxFlgRef , 0x4 , 7 , 0 ) ;	 
 { if ( ! ( os_status == OS_SUCCESS ) ) { utilsAssertFail ( " os_status == OS_SUCCESS " , " diag_comm_EXTif.c " , 566 , 1 ) ; } } ;	 
	 
 // TBDIY test	 
 // DIAG_WM_CONSOLE_PRN ( ( TEXT ( " ***** DIAG DiagCommExtIfTxTimerCallback *****\r\n " ) ) ) ;	 
 // DIAG_FILTER ( Diag , Timer , Callback , REPORT )	 
 // diagTextPrintf ( " DiagCommExtIfTxTimerCallback " ) ;	 
 }

//ICAT EXPORTED FUNCTION - SYSTEM , PROD , AT_SER 
 void UART_diag_toAT ( ) 
 {	 
DIAG_FILTER ( SYSTEM , PROD , AT_SER_OK , DIAG_INFORMATION)  
 diagPrintf ( " Switch to AT mode OK " );

	 
 set_at_diag_mode ( 0 ) ;	 
	 
 // reset diag flag	 
 SetDeviceConection ( DIAG_COMMDEV_EXT , 0 ) ;	 
 setDiagBlock ( 1 ) ;	 
	 
 send_string_2uart ( " AT COMMAND OK\r\n " ) ;	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_comm_INTif.ppp
//PPL Source File Name : X:\\diag\\diag_comm\\src\\diag_comm_INTif.c
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

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 MIN_BUFFERS_NUM ;	 
 UINT8 TASK_TIMER_PERIOD ;	 
 UINT8 task_priority ;	 
 } DiagIntIfTaskConfig;

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_comm_EXTif_OSA_NUCLEUS.ppp
//PPL Source File Name : X:\\diag\\diag_comm\\src\\diag_comm_EXTif_OSA_NUCLEUS.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
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
//ICAT EXPORTED ENUM 
 typedef enum {	 
	 
 IMLConfig_OFF=0 ,	 
 IMLConfig_2SD ,	 
 IMLConfig_2DDR ,	 
 IMLConfig_2HSL_BIGBOARD ,	 
 IMLConfig_2HSL_SMALLBOARD ,	 
 IMLConfig_2SU_ENABLE ,	 
 IMLConfig_2SU_DISABLE	 
	 
 } IMLCONFIG_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
	 
 IMLCONFIG_TYPE IMLConfigVal ;	 
	 
 UINT8 DataLen ;	 
 UINT8 data [ 64 ] ;	 
 } IMLCfgDataS;

typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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

typedef UINT32 lfs_size_t ;
typedef UINT32 lfs_off_t ;
typedef int lfs_ssize_t ;
typedef int lfs_soff_t ;
typedef UINT32 lfs_block_t ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPC_DDR_RELQ_REQ = 0x00000001 ,	 
 ACIPC_DDR_RELQ_ACK = 0x00000001 ,	 
 ACIPC_DDR_260_RELQ_REQ = 0x00000002 ,	 
 ACIPC_DDR_260_RELQ_ACK = 0x00000002 ,	 
 ACIPC_MSL_SLEEP_ALLOW = 0x00000004 ,	 
 ACIPC_MSL_WAKEUP_ACK = 0x00000008 ,	 
 ACIPC_MSL_WAKEUP_REQ = 0x00000010 ,	 
 ACIPC_DATA_Q_ADRS = 0x00000020 ,	 
 ACIPC_DATA_IND = 0x00000040 ,	 
 ACIPC_SPARE_1 = 0x00000080 ,	 
 ACIPC_DDR_260_READY_REQ = 0x00000100 ,	 
 ACIPC_DDR_260_READY_ACK = 0x00000100 ,	 
 ACIPC_DDR_READY_REQ = 0x00000200 ,	 
 ACIPC_DDR_READY_ACK = 0x00000200 ,	 
	 
 } ACIPC_EventsE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 DDR_FREQUENCY_104 ,	 
 DDR_FREQUENCY_156 ,	 
 DDR_FREQUENCY_208 ,	 
 DDR_FREQUENCY_312 ,	 
 DDR_FREQUENCY_400 ,	 
 DDR_FREQUENCY_528 ,	 
 DDR_FREQUENCY_NUM ,	 
 DDR_FREQUENCY_INVALID = DDR_FREQUENCY_NUM ,	 
 } DDR_FREQUENCY;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPC_DDR_AVAIL=0x00000001	 
 } ACIPC_FlagsE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPC_CB_NORMAL=0 , /* callback will be called only if the DDR available */	 
 ACIPC_CB_ALWAYS_NO_DDR /* callback will be called always , even if the DDR is not available*/	 
 } ACIPC_CBModeE;

typedef UINT32 ( *ACIPC_RecEventCB ) ( UINT32 eventsStatus ) ;
typedef UINT32 ACIPC_Data ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 _HWDFC_TEST_DISABEL=0 ,	 
 _HWDFC_TEST_ACTIVE_LPM_CORE ,	 
 _HWDFC_TEST_ACTIVE_LPM ,	 
 _HWDFC_TEST_ACTIVE ,	 
 _HWDFC_TEST_CORE ,	 
 _HWDFC_TEST_NEW_API ,	 
 } HWDFC_TEST_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _HWDFC_DISABEL=0 ,	 
 _HWDFC_ENABLE ,	 
 } HWDFC_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 CFG_PP_0 = 0 ,	 
 CFG_PP_1 ,	 
 CFG_PP_2 ,	 
 CFG_PP_3 ,	 
 CFG_PP_4 ,	 
 CFG_PP_5 ,	 
 CFG_PP_6 ,	 
 CFG_PP_7 ,	 
 CFG_PP_AUTO = 0xFF , // CQ00023417	 
 } PP_TYPE;

//ICAT EXPORTED ENUM - add by zhangwl for PP chang - CQ00023417 
 typedef enum {	 
 CPIDLE_0_5 = 5 ,	 
 CPIDLE_1_0 = 10 ,	 
 CPIDLE_1_5 = 15 ,	 
 CPIDLE_2_0 = 20 ,	 
 CPIDLE_2_5 = 25 ,	 
 CPIDLE_3_0 = 30 ,	 
 CPIDLE_3_5 = 35 ,	 
 CPIDLE_4_0 = 40 ,	 
 CPIDLE_4_5 = 45 ,	 
 CPIDLE_5_0 = 50 ,	 
 CPIDLE_5_5 = 55 ,	 
 CPIDLE_6_0 = 60 ,	 
 CPIDLE_6_5 = 65 ,	 
 CPIDLE_7_0 = 70 ,	 
 CPIDLE_7_5 = 75 ,	 
 CPIDLE_8_0 = 80 ,	 
 CPIDLE_8_5 = 85 ,	 
 CPIDLE_9_0 = 90 ,	 
 CPIDLE_9_5 = 95 ,	 
 CPIDLE_DEFAULT = 0xFF ,	 
 } PP_CPIDLE_T;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 LTE_DMA_78M = 0x7F ,	 
 LTE_DMA_156M = 0x5F ,	 
 LTE_DMA_208M = 0x4B ,	 
 LTE_DMA_312M = 0x4F ,	 
 } LTE_DMA_CLOCK;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 VOLTAGE_0_65 = 0x04 ,	 
 VOLTAGE_0_70 = 0x08 ,	 
 VOLTAGE_0_75 = 0x0C ,	 
 VOLTAGE_0_775 = 0x0E ,	 
 VOLTAGE_0_7875 = 0x0F ,	 
 VOLTAGE_0_80 = 0x10 ,	 
 VOLTAGE_0_8125 = 0x11 ,	 
 VOLTAGE_0_825 = 0x12 ,	 
 VOLTAGE_0_8375 = 0x13 ,	 
 VOLTAGE_0_85 = 0x14 ,	 
 VOLTAGE_0_8625 = 0x15 ,	 
 VOLTAGE_0_875 = 0x16 ,	 
 VOLTAGE_0_8875 = 0x17 ,	 
 VOLTAGE_0_90 = 0x18 ,	 
 VOLTAGE_0_9125 = 0x19 ,	 
 VOLTAGE_0_925 = 0x1A ,	 
 VOLTAGE_0_9375 = 0x1B ,	 
 VOLTAGE_0_95 = 0x1C ,	 
 VOLTAGE_0_9625 = 0x1D ,	 
 VOLTAGE_0_975 = 0x1E ,	 
 VOLTAGE_0_9875 = 0x1F ,	 
 VOLTAGE_1_00 = 0x20 ,	 
 VOLTAGE_1_0125 = 0x21 ,	 
 VOLTAGE_1_025 = 0x22 ,	 
 VOLTAGE_1_0375 = 0x23 ,	 
 VOLTAGE_1_05 = 0x24 ,	 
 VOLTAGE_1_0625 = 0x25 ,	 
 VOLTAGE_1_075 = 0x26 ,	 
 VOLTAGE_1_0875 = 0x27 ,	 
 VOLTAGE_1_10 = 0x28 ,	 
 VOLTAGE_1_1125 = 0x29 ,	 
 VOLTAGE_1_125 = 0x2A ,	 
 VOLTAGE_1_1375 = 0x2B ,	 
 VOLTAGE_1_15 = 0x2C ,	 
 VOLTAGE_1_1625 = 0x2D ,	 
 VOLTAGE_1_175 = 0x2E ,	 
 VOLTAGE_1_1875 = 0x2F ,	 
 VOLTAGE_1_20 = 0x30 ,	 
 VOLTAGE_1_2125 = 0x31 ,	 
 VOLTAGE_1_225 = 0x32 ,	 
 VOLTAGE_1_2375 = 0x33 ,	 
 VOLTAGE_1_25 = 0x34 ,	 
 VOLTAGE_1_2625 = 0x35 ,	 
 VOLTAGE_1_275 = 0x36 ,	 
 VOLTAGE_1_2875 = 0x37 ,	 
 VOLTAGE_1_30 = 0x38 ,	 
 VOLTAGE_1_35 = 0x3C ,	 
 VOLTAGE_DEFAULT = 0xFF ,	 
 } PP_VOLTAGE_T;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MIPS_5 = 5 ,	 
 MIPS_1_0 = 10 ,	 
 MIPS_1_5 = 15 ,	 
 MIPS_2_0 = 20 ,	 
 MIPS_2_5 = 25 ,	 
 MIPS_3_0 = 30 ,	 
 MIPS_3_5 = 35 ,	 
 MIPS_4_0 = 40 ,	 
 MIPS_4_5 = 45 ,	 
 MIPS_5_0 = 50 ,	 
 MIPS_5_5 = 55 ,	 
 MIPS_6_0 = 60 ,	 
 MIPS_6_5 = 65 ,	 
 MIPS_7_0 = 70 ,	 
 MIPS_7_5 = 75 ,	 
 MIPS_8_0 = 80 ,	 
 MIPS_8_5 = 85 ,	 
 MIPS_9_0 = 90 ,	 
 MIPS_9_5 = 95 ,	 
 MIPS_MAX = 0xFF ,	 
 } Mips_Threshold;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 PP_TYPE ProductPoint ;	 
 Mips_Threshold HighWaterMark ; // add by zhangwl for PP chang - CQ00023417	 
 Mips_Threshold LowWaterMark ; // add by zhangwl for PP chang - CQ00023417	 
 LTE_DMA_CLOCK LTEDmaClock ;	 
 PP_VOLTAGE_T ActiveVoltage ;	 
 PP_VOLTAGE_T SleepVoltage ;	 
 } LTE_CONFIG_S;

//ICAT EXPORTED STRUCT 
 typedef struct NVM_Header 
 {	 
 unsigned long StructSize ; // the size of the user structure below	 
 unsigned long NumofStructs ; // >1 in case of array of structs ( default is 1 ) .	 
 char StructName [ 64 ] ; // the name of the user structure below	 
 char Date [ 32 ] ; // date updated by the ICAT when the file is saved. Filled by calibration SW.	 
 char time [ 32 ] ; // time updated by the ICAT when the file is saved. Filled by calibration SW.	 
 char Version [ 64 ] ; // user version - this field is updated by the SW eng. Every time they update the UserStruct.	 
 char HW_ID [ 32 ] ; // signifies the board number. Filled by calibration SW.	 
 char CalibVersion [ 32 ] ; // signifies the calibration SW version. Filled by calibration SW.	 
 } NVM_Header_ts;

typedef unsigned int size_t ;
typedef unsigned int clock_t ;
typedef unsigned int time_t ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 second ; // Seconds after minute: 0 - 59	 
 UINT8 minute ; // Minutes after hour: 0 - 59	 
 UINT8 hour ; // Hours after midnight: 0 - 23	 
 UINT8 day ; // Day of month: 1 - 31	 
 UINT8 month ; // Month of year: 1 - 12	 
 UINT16 year ; // Calendar year: e.g 2001	 
 } RTC_CalendarTime;

typedef UINT8 RTC_Handle ;
typedef void ( *RTC_ISR ) ( void ) ;
typedef void ( *RTCOnTimeSetNotifyCallback ) ( RTC_CalendarTime* oldTime , RTC_CalendarTime* newTime ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // enumerated	 
 EE_SYS_RESET_EN ,	 
 EE_ASSERT_EN ,	 
 EE_EXCEPTION_EN ,	 
 EE_WARNING_EN ,	 
 EE_NUM_ENTRY_TYPES ,	 
 // Codes	 
 EE_SYS_RESET = 300 ,	 
 EE_ASSERT = 350 ,	 
 EE_EXCEPTION = 450 ,	 
 EE_WARNING = 550	 
 } EE_entry_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EEE_DataAbort ,	 
 EEE_PrefetchAbort ,	 
 EEE_FatalError ,	 
 EEE_SWInterrupt ,	 
 EEE_UndefInst ,	 
 EEE_ReservedInt	 
 } EE_ExceptionType_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_NO_RESET_SOURCE ,	 
 EE_POWER_ON_RESET = PMU_POR ,	 
 EE_EXT_MASTER_RESET ,	 
 EE_WDT_RESET = ( PMU_EMR+2 )	 
 } EE_PMU_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 r0 ; /* register r0 contents */	 
 UINT32 r1 ; /* register r1 contents */	 
 UINT32 r2 ; /* register r2 contents */	 
 UINT32 r3 ; /* register r3 contents */	 
 UINT32 r4 ; /* register r4 contents */	 
 UINT32 r5 ; /* register r5 contents */	 
 UINT32 r6 ; /* register r6 contents */	 
 UINT32 r7 ; /* register r7 contents */	 
 UINT32 r8 ; /* register r8 contents */	 
 UINT32 r9 ; /* register r9 contents */	 
 UINT32 r10 ; /* register r10 contents */	 
 UINT32 r11 ; /* register r11 contents */	 
 UINT32 r12 ; /* register r12 contents */	 
 UINT32 SP ; /* register r13 contents */	 
 UINT32 LR ; /* register r14 contents ( excepted mode ) */	 
 UINT32 PC ; /* PC - excepted instruction */	 
 UINT32 cpsr ; /* saved program status register contents */	 
 UINT32 FSR ; /* Fault status register */	 
 UINT32 FAR_R ; /* Fault address register */	 
 EE_PMU_t PMU_reg ; /* saved reset cause - should be last */	 
	 
 // UINT32 PESR ; / * Extension * /	 
 // UINT32 XESR ;	 
 // UINT32 PEAR ;	 
 // UINT32 FEAR ;	 
 // UINT32 SEAR ;	 
 // UINT32 GEAR ;	 
 } EE_RegInfo_Data_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ EE context types to be saved in the context buffer*/	 
 EE_CT_None , /* @ENUM_VAL_DESC@ Save no context*/	 
 EE_CT_ExecTrace , /* @ENUM_VAL_DESC@ Save Trace buffer*/	 
 EE_CT_StackDump /* @ENUM_VAL_DESC@ Save Stack Dump*/	 
 } EE_ContextType_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_CDT_None ,	 
 EE_CDT_ExecTrace ,	 
 EE_CDT_StackDump ,	 
 EE_CDT_UserDefined=0x10	 
 } EE_ContextDataType_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 _PESR ;	 
 UINT32 _XESR ;	 
 UINT32 _PEAR ;	 
 UINT32 _FEAR ;	 
 UINT32 _SEAR ;	 
 UINT32 _GEAR ;	 
 } EE_XscGasketRegs;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 fileWriteOffset ; // DO NOT REMOVE OR CHANGE TYPE!!! ( for cyclic file )	 
 EE_entry_t type ;	 
 RTC_CalendarTime dateAndTime ;	 
 char desc [ 100 ] ; /* Description string size =ERROR_HANDLER_MAX_DESC_SIZE*/	 
 EE_RegInfo_Data_t RegInfo ;	 
 EE_ContextDataType_t contextBufferType ;	 
 UINT8 contextBuffer [ 512 ] ;	 
 UINT32 CHKPT0 ;	 
 UINT32 CHKPT1 ;	 
 char taskName [ 10 ] ;	 
 UINT32 taskStackStart ;	 
 UINT32 taskStackEnd ;	 
 // UP TO HERE 0x1e4 bytes ( out of 0x200 allocated by linker control file INT_RAM_EE segment )	 
 EE_XscGasketRegs xscaleGasketRegs ;	 
 UINT32 warningCntr ; // reserved [ 1 ] ;	 
	 
	 
	 
	 
 } EE_Entry_t;

typedef void voidPFuncVoid ( void ) ;
typedef void ( * ExceptionHendler ) ( EE_RegInfo_Data_t* ) ;
typedef EEHandlerAction ( * ExceptionHendlerExt ) ( EE_ExceptionType_t type , EE_RegInfo_Data_t* ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures Error handling final action*/	 
 EE_RESET , /* @ENUM_VAL_DESC@ final action RESET*/	 
 EE_STALL , /* @ENUM_VAL_DESC@ final action STALL*/	 
 EE_CONTINUE , /* @ENUM_VAL_DESC@ report but continue ( like ignore or warning ) */	 
 EE_EXTERNAL , /* @ENUM_VAL_DESC@ final action EXTERNAL*/	 
 EE_RESET_START_BASIC , /* @ENUM_VAL_DESC@ final action RESET START BASIC*/	 
 EE_NON_WDT_SERIAL /* @ENUM_VAL_DESC@ final action NON WDT SERIAL*/	 
 } FinalAct_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Error Handler options ON / OFF enum*/	 
 EE_OFF , /* @ENUM_VAL_DESC@ Option turned OFF*/	 
 EE_ON /* @ENUM_VAL_DESC@ Option turned ON*/	 
 } EE_OnOff_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure EE logs data in case of warning*/	 
 EE_WARN_OFF , /* @ENUM_VAL_DESC@ EE warning log OFF*/	 
 EE_WARN_ASSERTCONTINUE , /* @ENUM_VAL_DESC@ EE logs warning assert and continue */	 
 EE_WARN_ASSERT /* @ENUM_VAL_DESC@ EE logs warning assert */	 
 } EE_WarningOn_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_VER_3 = 3 ,	 
 EE_VER	 
 } EE_Version_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_HSL_OFF = 0 ,	 
 EE_HSL_1_8V= 1 ,	 
 EE_HSL_3V = 3	 
 } EE_HSL_V_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ WatchDog timer ( WDT ) configuration*/	 
 EE_WDT_OFF = 0 , /* @ENUM_VAL_DESC@ Set WDT OFF*/	 
 EE_WDT_TIME_6SEC = 6000 , /* @ENUM_VAL_DESC@ Set WDT to 6 sec*/ // in miliseconds ; for max WCDMA / GSM DRX cycle	 
 EE_WDT_TIME_7SEC = 7000 , /* @ENUM_VAL_DESC@ Set WDT to 7 sec*/ // in miliseconds	 
 EE_WDT_TIME_8SEC = 8000 , /* @ENUM_VAL_DESC@ Set WDT to 8 sec*/ // in miliseconds	 
 EE_WDT_TIME_10SEC = 10000 , /* @ENUM_VAL_DESC@ Set WDT to 10 sec*/ // in miliseconds	 
 EE_WDT_TIME_20SEC = 20000 , /* @ENUM_VAL_DESC@ Set WDT to 20 sec*/ // in miliseconds	 
 EE_WDT_TIME_30SEC = 30000 , /* @ENUM_VAL_DESC@ Set WDT to 30 sec*/ // in miliseconds	 
 EE_WDT_TIME_MAX = 0xFFFF /* @ENUM_VAL_DESC@ Set WDT to MAX ( 65.535000 sec ) */ // UINT16	 
 } EE_WdtTimeCfg_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Error Handler Configuration*/	 
 /* @STRUCT_NVM_FILE_NAME@ EEHandlerConfig.nvm*/	 
 EE_OnOff_t AssertHandlerOn ; /* @ITEM_DESC@ Configure EE logs data in case of ASSERT , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t ExcepHandlerOn ; /* @ITEM_DESC@ Configure EE logs data in case of Exception handler , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_WarningOn_t WarningHandlerOn ; /* @ITEM_DESC@ Configure EE logs data in case of warning , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t powerUpLogOn ; /* @ITEM_DESC@ Configure EE logs data at power-on , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t extHandlersOn ; /* @ITEM_DESC@ Configure EE logs data in case of extHandler , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t printRecentLogOnStartup ; /* @ITEM_DESC@ Indicates if to search for EE logs on NVM and notify regarding them on startup , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 FinalAct_t finalAction ; /* @ITEM_DESC@ Configures Error handling final action , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT32 EELogFileSize ; /* @ITEM_DESC@ Set Error Handler log file size , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes*/	 
 UINT16 delayOnStartup ; /* @ITEM_DESC@ Set delay on startup before printing recent log , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF in 5 milisec ticks */ // Delay for ICAT log coverage in 5 ms units	 
 EE_ContextType_t assertContextBufType ; /* @ITEM_DESC@ What context to save in case ASSERT happened , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_ContextType_t exceptionContextBufType ; /* @ITEM_DESC@ What context to save in case Exception Handler happened , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_ContextType_t warningContextBufType ; /* @ITEM_DESC@ What context to save in case Warning happened , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
	 
	 
	 
 UINT8 reserved1 [ 8 ] ; /* @ITEM_DESC@ reserved place for when deferredCfg not used , @ITEM_MODE@ , @ITEM_UNIT@ Not relevant*/	 
	 
 EE_WdtTimeCfg_t wdtConfigTime ; /* @ITEM_DESC@ WatchDog timer configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/ // UINT16	 
 UINT16 sysEeHandlerLimit ; /* @ITEM_DESC@ EE handler system limit ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 1 -0xFFFF , 0 -No limit*/ // relevant for EE_ASSISTING_MASTER only ; ZERO is no limits	 
 UINT32 dumpDdrSizeBytes ; /* @ITEM_DESC@ Limit DDR size to dump ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes , 0x1 -0x400 - No limit*/ // relevant for EE_ASSISTING_MASTER only	 
 UINT8 reserved [ 24 ] ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 UINT32 dumpResetFlag ; /*default is 0 . When finalAction is EE_RESET , 1 :dump and then silent reset ; 0 :silent reset without dump*/	 
 } EE_Configuration_t;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 SULOG_OFF = 0 ,	 
 SULOG_ENABLE_HW_SW ,	 
 SULOG_ENABLE_HW ,	 
 SULOG_ENABLE_SW ,	 
 } SULOG_TYPE_ID;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 value32 [ 2 ] ;	 
 } LteSulogCfgS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 SULOG_TYPE_ID logSwitch ;	 
 LteSulogCfgS PrintLevel ;	 
 UINT8 Sulog2SdCardFlag ;	 
 UINT8 reserved [ 3 ] ;	 
 } SULOG_ST;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 SULOG_TYPE_ID logSwitch ;	 
 LteSulogCfgS PrintLevelForSdCardDisable ;	 
 LteSulogCfgS PrintLevelForSdCardEnable ;	 
 UINT8 Sulog2SdCardFlag ;	 
 } SulogCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 HSL_DISABLE = 0 ,	 
 HSL_BIGBOARD_ENABLE ,	 
 HSL_MINIBOARD_ENABLE ,	 
 } HSL_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _PM_DISABLE = 0 ,	 
 _PM_ENABLE ,	 
 } PM_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 VCXO_SD_DISABLE = 0 ,	 
 VCXO_SD_ENABLE ,	 
 } VCXO_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 SD_LOG_DISABLE = 0 ,	 
 SD_LOG_ENABLE ,	 
 } SDLOG_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _L1_ACAT_LOG_DISABLE = 0 ,	 
 _L1_ACAT_LOG_ENABLE ,	 
 } L1AcatLog_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 L1_IML2DDR_DISABLE = 0 ,	 
 L1_IML2DDR_ENABLE ,	 
 } L1IML2DDR_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 PM_TYPE PMCfgVal ;	 
 HWDFC_TYPE HWDFCCfgVal ;	 
 HWDFC_TEST_TYPE HWDFCTestCfgVal ;	 
 VCXO_TYPE VCXOCfgVal ;	 
 SDLOG_TYPE SDLogCfgVal ;	 
 L1AcatLog_TYPE L1AcatLogVal ; /* CQ0003TTTT */	 
	 
	 
	 
 IMLCfgDataS IMLCfgdata ;	 
 } HSLCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _CPU_USAGE_DUMP_DISABLE = 0 ,	 
 _CPU_USAGE_DUMP_ENABLE	 
 } CPUUSAGEDUMP_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 CPUUSAGEDUMP_TYPE cpuUsageDumpEnable ;	 
 UINT32 dumpInterval ;	 
 } SYSDBGCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 APT_DISABLE = 0 ,	 
 APT_ENABLE ,	 
 } APT_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT8 ucVcxoStableTime ;	 
 UINT8 ucPllStableTime ;	 
 UINT8 ucClkGenTime ;	 
 UINT8 ucDualCarrierFlag ;	 
 UINT8 ucDualAntFlag ;	 
 APT_TYPE AptFlag ;	 
 } MSACfgDataS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 MSACfgDataS MsaCfg ;	 
 HSLCfgDataS HslCfg ;	 
 SYSDBGCfgDataS SysDbgCfg ;	 
 Log_ConfigS LogCfg ;	 
 Usb_DriverS usbDrvCfg ;	 
 LTE_CONFIG_S LteCfg ;	 
 Ymodem_Dump_type YmodemCfg ;	 
 SulogCfgDataS SulogCfg ;	 
 RTICfg_t rtiConfig ;	 
 uartCfgDataS uartCfg ;	 
 EE_Configuration_t eeCfg ;	 
 diagCfgDataS diagCfg ;	 
 UINT32 TailGuard ;	 
 } PlatformCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef TX_THREAD OS_Task_t ;
typedef TX_SEMAPHORE OS_Sema_t ;
typedef TX_SEMAPHORE OS_Mutex_t ;
typedef TX_TIMER OS_Timer_t ;
typedef TX_EVENT_FLAGS_GROUP OS_EventGroup_t ;
typedef TX_EVENT_FLAGS_GROUP OS_Flag_t ;
typedef void* OS_Hisr_t ;
typedef TX_BYTE_POOL OS_MemPool_t ;
typedef TX_BLOCK_POOL OS_PartitionPool_t ;
typedef STATUS NU_RTN_STATUS ;
typedef UINT32 OS_Proc_t ;
typedef UINT32 ( *DiagHSprotocolSendCB ) ( UINT8 * , UINT32 ) ;
typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
typedef unsigned char BYTE ;
typedef unsigned short int WORD ;
typedef unsigned long DWORD ;
typedef WORD * WORD_PTR ;
typedef DWORD * DWORD_PTR ;
typedef BYTE BYTE_BITMASK ;
typedef VOID_PTR * VOID_PTR_PTR ;
typedef WORD FLASH_DATA_WIDTH ;
typedef char FDI_TCHAR ;
typedef OSASemaRef SEM_ID ;
typedef int SEM_STATUS ;
typedef SEM_MTX * SEM_MTX_ID ;
typedef unsigned short FILE_ID ;
typedef unsigned int UINT ;
typedef unsigned char BYTE ;
typedef unsigned short WORD ;
typedef unsigned short WCHAR ;
typedef unsigned long DWORD ;
typedef char TCHAR ;
typedef DWORD FSIZE_t ;
typedef void ( *AlCallback ) ( void ) ;
typedef void ( *DMATransferErrorNotifyFn ) ( UINT32 channel , UINT32 callbackCookie ) ;
typedef void ( *DMATransferEndedNotifyFn ) ( UINT32 channel , UINT32 callbackCookie ) ;
typedef void ( *DMATransferStoppedNotifyFn ) ( UINT32 channel , UINT32 callbackCookie ) ;
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
typedef void * UDC_HANDLE ;
typedef void ( *UDCDriverTransactionNofityFn ) ( UDC_EndpointE , UINT8 * , UINT32 , BOOL ) ;
DIAG_FILTER ( diag , throughput , Test_02 , DIAG_INFORMATION)  
 diagPrintf ( " diag Interval is 0x%lx , count is %ld " , ( diag_tick1-DiagThroughStartTick ) , diag_count );

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_comm_L2.ppp
//PPL Source File Name : X:\\diag\\diag_comm\\src\\diag_comm_L2.c
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
typedef unsigned int size_t ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef UINT32 ( *DiagHSprotocolSendCB ) ( UINT8 * , UINT32 ) ;
typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
DIAG_FILTER ( DIAG , PROTOCOL , L2_Rx_Error , DIAG_ERROR)  
 diagTextPrintf ( " Error in received packet " );

DIAG_FILTER ( DIAG , PROTOCOL , L2_Rx_Comm_Timout , DIAG_ERROR)  
 diagTextPrintf ( " Timeout in received message " );

//ICAT EXPORTED FUNCTION - Diag , Debug , getDiagSppRxNumberOfBadMessages 
 void getDiagSppRxNumberOfBadMessages ( void ) 
 {	 
DIAG_FILTER ( Diag , Debug , NumberOfBadRxMessages , DIAG_INFORMATION)  
 diagPrintf ( " diagSppRxNumberOfBadMessages = %ld " , diagSppRxNumberOfBadMessages );

	 
	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_comm_L4.ppp
//PPL Source File Name : X:\\diag\\diag_comm\\src\\diag_comm_L4.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef UINT32 ( *DiagHSprotocolSendCB ) ( UINT8 * , UINT32 ) ;
typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_comm_SD.ppp
//PPL Source File Name : X:\\diag\\diag_comm\\src\\diag_comm_SD.c
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
typedef unsigned int size_t ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

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

typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef void ( *AlCallback ) ( void ) ;
typedef signed char INT8 ;
typedef signed short INT16 ;
typedef signed long INT32 ;
typedef unsigned char UINT8 ;
typedef unsigned short UINT16 ;
typedef unsigned long UINT32 ;
typedef unsigned long BU_U32 ;
typedef unsigned char BOOL ;
typedef union CNT_32 {
 UINT8 cnt_8 [ 4 ] ;
 UINT32 cnt_32 ;
 } COUNTER_32 ;
typedef void ( *PmicCallback ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 BUCK_0_700 = 0x08 , /* 0.700000 V */	 
 BUCK_0_750 = 0x0C ,	 
 BUCK_0_800 = 0x10 ,	 
 BUCK_0_850 = 0x14 ,	 
 BUCK_0_900 = 0x18 ,	 
 BUCK_0_950 = 0x1C ,	 
 BUCK_1_000 = 0x20 ,	 
 BUCK_1_025 = 0x22 ,	 
 BUCK_1_050 = 0x24 ,	 
 BUCK_1_075 = 0x26 ,	 
 BUCK_1_100 = 0x28 ,	 
 BUCK_1_150 = 0x2C ,	 
 BUCK_1_200 = 0x30 ,	 
 BUCK_1_250 = 0x34 ,	 
 BUCK_1_300 = 0x38 ,	 
 BUCK_1_350 = 0x3C ,	 
	 
 BUCK_1_600 = 0x50 ,	 
 BUCK_1_650 = 0x51 ,	 
 BUCK_1_700 = 0x52 ,	 
 BUCK_1_750 = 0x53 ,	 
 BUCK_1_800 = 0x54 ,	 
 BUCK_1_850 = 0x55 ,	 
 BUCK_1_900 = 0x56 ,	 
 BUCK_1_950 = 0x57 ,	 
 BUCK_2_000 = 0x58 ,	 
	 
 BUCK_DEFAULT = 0xFF ,	 
 } PMIC_BUCK_T;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 pmic_rtc_setting_sys_offset ;	 
 UINT32 pmic_rtc_setting_app_offset ;	 
 INT32 pmic_rtc_setting_timezone ;	 
 } PMIC_RTC_Setting;

//ICAT EXPORTED ENUM 
 typedef enum {	 
	 
 IMLConfig_OFF=0 ,	 
 IMLConfig_2SD ,	 
 IMLConfig_2DDR ,	 
 IMLConfig_2HSL_BIGBOARD ,	 
 IMLConfig_2HSL_SMALLBOARD ,	 
 IMLConfig_2SU_ENABLE ,	 
 IMLConfig_2SU_DISABLE	 
	 
 } IMLCONFIG_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
	 
 IMLCONFIG_TYPE IMLConfigVal ;	 
	 
 UINT8 DataLen ;	 
 UINT8 data [ 64 ] ;	 
 } IMLCfgDataS;

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

typedef UINT32 lfs_size_t ;
typedef UINT32 lfs_off_t ;
typedef int lfs_ssize_t ;
typedef int lfs_soff_t ;
typedef UINT32 lfs_block_t ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPC_DDR_RELQ_REQ = 0x00000001 ,	 
 ACIPC_DDR_RELQ_ACK = 0x00000001 ,	 
 ACIPC_DDR_260_RELQ_REQ = 0x00000002 ,	 
 ACIPC_DDR_260_RELQ_ACK = 0x00000002 ,	 
 ACIPC_MSL_SLEEP_ALLOW = 0x00000004 ,	 
 ACIPC_MSL_WAKEUP_ACK = 0x00000008 ,	 
 ACIPC_MSL_WAKEUP_REQ = 0x00000010 ,	 
 ACIPC_DATA_Q_ADRS = 0x00000020 ,	 
 ACIPC_DATA_IND = 0x00000040 ,	 
 ACIPC_SPARE_1 = 0x00000080 ,	 
 ACIPC_DDR_260_READY_REQ = 0x00000100 ,	 
 ACIPC_DDR_260_READY_ACK = 0x00000100 ,	 
 ACIPC_DDR_READY_REQ = 0x00000200 ,	 
 ACIPC_DDR_READY_ACK = 0x00000200 ,	 
	 
 } ACIPC_EventsE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 DDR_FREQUENCY_104 ,	 
 DDR_FREQUENCY_156 ,	 
 DDR_FREQUENCY_208 ,	 
 DDR_FREQUENCY_312 ,	 
 DDR_FREQUENCY_400 ,	 
 DDR_FREQUENCY_528 ,	 
 DDR_FREQUENCY_NUM ,	 
 DDR_FREQUENCY_INVALID = DDR_FREQUENCY_NUM ,	 
 } DDR_FREQUENCY;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPC_DDR_AVAIL=0x00000001	 
 } ACIPC_FlagsE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPC_CB_NORMAL=0 , /* callback will be called only if the DDR available */	 
 ACIPC_CB_ALWAYS_NO_DDR /* callback will be called always , even if the DDR is not available*/	 
 } ACIPC_CBModeE;

typedef UINT32 ( *ACIPC_RecEventCB ) ( UINT32 eventsStatus ) ;
typedef UINT32 ACIPC_Data ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 _HWDFC_TEST_DISABEL=0 ,	 
 _HWDFC_TEST_ACTIVE_LPM_CORE ,	 
 _HWDFC_TEST_ACTIVE_LPM ,	 
 _HWDFC_TEST_ACTIVE ,	 
 _HWDFC_TEST_CORE ,	 
 _HWDFC_TEST_NEW_API ,	 
 } HWDFC_TEST_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _HWDFC_DISABEL=0 ,	 
 _HWDFC_ENABLE ,	 
 } HWDFC_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 CFG_PP_0 = 0 ,	 
 CFG_PP_1 ,	 
 CFG_PP_2 ,	 
 CFG_PP_3 ,	 
 CFG_PP_4 ,	 
 CFG_PP_5 ,	 
 CFG_PP_6 ,	 
 CFG_PP_7 ,	 
 CFG_PP_AUTO = 0xFF , // CQ00023417	 
 } PP_TYPE;

//ICAT EXPORTED ENUM - add by zhangwl for PP chang - CQ00023417 
 typedef enum {	 
 CPIDLE_0_5 = 5 ,	 
 CPIDLE_1_0 = 10 ,	 
 CPIDLE_1_5 = 15 ,	 
 CPIDLE_2_0 = 20 ,	 
 CPIDLE_2_5 = 25 ,	 
 CPIDLE_3_0 = 30 ,	 
 CPIDLE_3_5 = 35 ,	 
 CPIDLE_4_0 = 40 ,	 
 CPIDLE_4_5 = 45 ,	 
 CPIDLE_5_0 = 50 ,	 
 CPIDLE_5_5 = 55 ,	 
 CPIDLE_6_0 = 60 ,	 
 CPIDLE_6_5 = 65 ,	 
 CPIDLE_7_0 = 70 ,	 
 CPIDLE_7_5 = 75 ,	 
 CPIDLE_8_0 = 80 ,	 
 CPIDLE_8_5 = 85 ,	 
 CPIDLE_9_0 = 90 ,	 
 CPIDLE_9_5 = 95 ,	 
 CPIDLE_DEFAULT = 0xFF ,	 
 } PP_CPIDLE_T;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 LTE_DMA_78M = 0x7F ,	 
 LTE_DMA_156M = 0x5F ,	 
 LTE_DMA_208M = 0x4B ,	 
 LTE_DMA_312M = 0x4F ,	 
 } LTE_DMA_CLOCK;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 VOLTAGE_0_65 = 0x04 ,	 
 VOLTAGE_0_70 = 0x08 ,	 
 VOLTAGE_0_75 = 0x0C ,	 
 VOLTAGE_0_775 = 0x0E ,	 
 VOLTAGE_0_7875 = 0x0F ,	 
 VOLTAGE_0_80 = 0x10 ,	 
 VOLTAGE_0_8125 = 0x11 ,	 
 VOLTAGE_0_825 = 0x12 ,	 
 VOLTAGE_0_8375 = 0x13 ,	 
 VOLTAGE_0_85 = 0x14 ,	 
 VOLTAGE_0_8625 = 0x15 ,	 
 VOLTAGE_0_875 = 0x16 ,	 
 VOLTAGE_0_8875 = 0x17 ,	 
 VOLTAGE_0_90 = 0x18 ,	 
 VOLTAGE_0_9125 = 0x19 ,	 
 VOLTAGE_0_925 = 0x1A ,	 
 VOLTAGE_0_9375 = 0x1B ,	 
 VOLTAGE_0_95 = 0x1C ,	 
 VOLTAGE_0_9625 = 0x1D ,	 
 VOLTAGE_0_975 = 0x1E ,	 
 VOLTAGE_0_9875 = 0x1F ,	 
 VOLTAGE_1_00 = 0x20 ,	 
 VOLTAGE_1_0125 = 0x21 ,	 
 VOLTAGE_1_025 = 0x22 ,	 
 VOLTAGE_1_0375 = 0x23 ,	 
 VOLTAGE_1_05 = 0x24 ,	 
 VOLTAGE_1_0625 = 0x25 ,	 
 VOLTAGE_1_075 = 0x26 ,	 
 VOLTAGE_1_0875 = 0x27 ,	 
 VOLTAGE_1_10 = 0x28 ,	 
 VOLTAGE_1_1125 = 0x29 ,	 
 VOLTAGE_1_125 = 0x2A ,	 
 VOLTAGE_1_1375 = 0x2B ,	 
 VOLTAGE_1_15 = 0x2C ,	 
 VOLTAGE_1_1625 = 0x2D ,	 
 VOLTAGE_1_175 = 0x2E ,	 
 VOLTAGE_1_1875 = 0x2F ,	 
 VOLTAGE_1_20 = 0x30 ,	 
 VOLTAGE_1_2125 = 0x31 ,	 
 VOLTAGE_1_225 = 0x32 ,	 
 VOLTAGE_1_2375 = 0x33 ,	 
 VOLTAGE_1_25 = 0x34 ,	 
 VOLTAGE_1_2625 = 0x35 ,	 
 VOLTAGE_1_275 = 0x36 ,	 
 VOLTAGE_1_2875 = 0x37 ,	 
 VOLTAGE_1_30 = 0x38 ,	 
 VOLTAGE_1_35 = 0x3C ,	 
 VOLTAGE_DEFAULT = 0xFF ,	 
 } PP_VOLTAGE_T;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MIPS_5 = 5 ,	 
 MIPS_1_0 = 10 ,	 
 MIPS_1_5 = 15 ,	 
 MIPS_2_0 = 20 ,	 
 MIPS_2_5 = 25 ,	 
 MIPS_3_0 = 30 ,	 
 MIPS_3_5 = 35 ,	 
 MIPS_4_0 = 40 ,	 
 MIPS_4_5 = 45 ,	 
 MIPS_5_0 = 50 ,	 
 MIPS_5_5 = 55 ,	 
 MIPS_6_0 = 60 ,	 
 MIPS_6_5 = 65 ,	 
 MIPS_7_0 = 70 ,	 
 MIPS_7_5 = 75 ,	 
 MIPS_8_0 = 80 ,	 
 MIPS_8_5 = 85 ,	 
 MIPS_9_0 = 90 ,	 
 MIPS_9_5 = 95 ,	 
 MIPS_MAX = 0xFF ,	 
 } Mips_Threshold;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 PP_TYPE ProductPoint ;	 
 Mips_Threshold HighWaterMark ; // add by zhangwl for PP chang - CQ00023417	 
 Mips_Threshold LowWaterMark ; // add by zhangwl for PP chang - CQ00023417	 
 LTE_DMA_CLOCK LTEDmaClock ;	 
 PP_VOLTAGE_T ActiveVoltage ;	 
 PP_VOLTAGE_T SleepVoltage ;	 
 } LTE_CONFIG_S;

//ICAT EXPORTED STRUCT 
 typedef struct NVM_Header 
 {	 
 unsigned long StructSize ; // the size of the user structure below	 
 unsigned long NumofStructs ; // >1 in case of array of structs ( default is 1 ) .	 
 char StructName [ 64 ] ; // the name of the user structure below	 
 char Date [ 32 ] ; // date updated by the ICAT when the file is saved. Filled by calibration SW.	 
 char time [ 32 ] ; // time updated by the ICAT when the file is saved. Filled by calibration SW.	 
 char Version [ 64 ] ; // user version - this field is updated by the SW eng. Every time they update the UserStruct.	 
 char HW_ID [ 32 ] ; // signifies the board number. Filled by calibration SW.	 
 char CalibVersion [ 32 ] ; // signifies the calibration SW version. Filled by calibration SW.	 
 } NVM_Header_ts;

typedef unsigned int size_t ;
typedef unsigned int clock_t ;
typedef unsigned int time_t ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 second ; // Seconds after minute: 0 - 59	 
 UINT8 minute ; // Minutes after hour: 0 - 59	 
 UINT8 hour ; // Hours after midnight: 0 - 23	 
 UINT8 day ; // Day of month: 1 - 31	 
 UINT8 month ; // Month of year: 1 - 12	 
 UINT16 year ; // Calendar year: e.g 2001	 
 } RTC_CalendarTime;

typedef UINT8 RTC_Handle ;
typedef void ( *RTC_ISR ) ( void ) ;
typedef void ( *RTCOnTimeSetNotifyCallback ) ( RTC_CalendarTime* oldTime , RTC_CalendarTime* newTime ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // enumerated	 
 EE_SYS_RESET_EN ,	 
 EE_ASSERT_EN ,	 
 EE_EXCEPTION_EN ,	 
 EE_WARNING_EN ,	 
 EE_NUM_ENTRY_TYPES ,	 
 // Codes	 
 EE_SYS_RESET = 300 ,	 
 EE_ASSERT = 350 ,	 
 EE_EXCEPTION = 450 ,	 
 EE_WARNING = 550	 
 } EE_entry_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EEE_DataAbort ,	 
 EEE_PrefetchAbort ,	 
 EEE_FatalError ,	 
 EEE_SWInterrupt ,	 
 EEE_UndefInst ,	 
 EEE_ReservedInt	 
 } EE_ExceptionType_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_NO_RESET_SOURCE ,	 
 EE_POWER_ON_RESET = PMU_POR ,	 
 EE_EXT_MASTER_RESET ,	 
 EE_WDT_RESET = ( PMU_EMR+2 )	 
 } EE_PMU_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 r0 ; /* register r0 contents */	 
 UINT32 r1 ; /* register r1 contents */	 
 UINT32 r2 ; /* register r2 contents */	 
 UINT32 r3 ; /* register r3 contents */	 
 UINT32 r4 ; /* register r4 contents */	 
 UINT32 r5 ; /* register r5 contents */	 
 UINT32 r6 ; /* register r6 contents */	 
 UINT32 r7 ; /* register r7 contents */	 
 UINT32 r8 ; /* register r8 contents */	 
 UINT32 r9 ; /* register r9 contents */	 
 UINT32 r10 ; /* register r10 contents */	 
 UINT32 r11 ; /* register r11 contents */	 
 UINT32 r12 ; /* register r12 contents */	 
 UINT32 SP ; /* register r13 contents */	 
 UINT32 LR ; /* register r14 contents ( excepted mode ) */	 
 UINT32 PC ; /* PC - excepted instruction */	 
 UINT32 cpsr ; /* saved program status register contents */	 
 UINT32 FSR ; /* Fault status register */	 
 UINT32 FAR_R ; /* Fault address register */	 
 EE_PMU_t PMU_reg ; /* saved reset cause - should be last */	 
	 
 // UINT32 PESR ; / * Extension * /	 
 // UINT32 XESR ;	 
 // UINT32 PEAR ;	 
 // UINT32 FEAR ;	 
 // UINT32 SEAR ;	 
 // UINT32 GEAR ;	 
 } EE_RegInfo_Data_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ EE context types to be saved in the context buffer*/	 
 EE_CT_None , /* @ENUM_VAL_DESC@ Save no context*/	 
 EE_CT_ExecTrace , /* @ENUM_VAL_DESC@ Save Trace buffer*/	 
 EE_CT_StackDump /* @ENUM_VAL_DESC@ Save Stack Dump*/	 
 } EE_ContextType_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_CDT_None ,	 
 EE_CDT_ExecTrace ,	 
 EE_CDT_StackDump ,	 
 EE_CDT_UserDefined=0x10	 
 } EE_ContextDataType_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 _PESR ;	 
 UINT32 _XESR ;	 
 UINT32 _PEAR ;	 
 UINT32 _FEAR ;	 
 UINT32 _SEAR ;	 
 UINT32 _GEAR ;	 
 } EE_XscGasketRegs;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 fileWriteOffset ; // DO NOT REMOVE OR CHANGE TYPE!!! ( for cyclic file )	 
 EE_entry_t type ;	 
 RTC_CalendarTime dateAndTime ;	 
 char desc [ 100 ] ; /* Description string size =ERROR_HANDLER_MAX_DESC_SIZE*/	 
 EE_RegInfo_Data_t RegInfo ;	 
 EE_ContextDataType_t contextBufferType ;	 
 UINT8 contextBuffer [ 512 ] ;	 
 UINT32 CHKPT0 ;	 
 UINT32 CHKPT1 ;	 
 char taskName [ 10 ] ;	 
 UINT32 taskStackStart ;	 
 UINT32 taskStackEnd ;	 
 // UP TO HERE 0x1e4 bytes ( out of 0x200 allocated by linker control file INT_RAM_EE segment )	 
 EE_XscGasketRegs xscaleGasketRegs ;	 
 UINT32 warningCntr ; // reserved [ 1 ] ;	 
	 
	 
	 
	 
 } EE_Entry_t;

typedef void voidPFuncVoid ( void ) ;
typedef void ( * ExceptionHendler ) ( EE_RegInfo_Data_t* ) ;
typedef EEHandlerAction ( * ExceptionHendlerExt ) ( EE_ExceptionType_t type , EE_RegInfo_Data_t* ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures Error handling final action*/	 
 EE_RESET , /* @ENUM_VAL_DESC@ final action RESET*/	 
 EE_STALL , /* @ENUM_VAL_DESC@ final action STALL*/	 
 EE_CONTINUE , /* @ENUM_VAL_DESC@ report but continue ( like ignore or warning ) */	 
 EE_EXTERNAL , /* @ENUM_VAL_DESC@ final action EXTERNAL*/	 
 EE_RESET_START_BASIC , /* @ENUM_VAL_DESC@ final action RESET START BASIC*/	 
 EE_NON_WDT_SERIAL /* @ENUM_VAL_DESC@ final action NON WDT SERIAL*/	 
 } FinalAct_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Error Handler options ON / OFF enum*/	 
 EE_OFF , /* @ENUM_VAL_DESC@ Option turned OFF*/	 
 EE_ON /* @ENUM_VAL_DESC@ Option turned ON*/	 
 } EE_OnOff_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure EE logs data in case of warning*/	 
 EE_WARN_OFF , /* @ENUM_VAL_DESC@ EE warning log OFF*/	 
 EE_WARN_ASSERTCONTINUE , /* @ENUM_VAL_DESC@ EE logs warning assert and continue */	 
 EE_WARN_ASSERT /* @ENUM_VAL_DESC@ EE logs warning assert */	 
 } EE_WarningOn_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_VER_3 = 3 ,	 
 EE_VER	 
 } EE_Version_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_HSL_OFF = 0 ,	 
 EE_HSL_1_8V= 1 ,	 
 EE_HSL_3V = 3	 
 } EE_HSL_V_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ WatchDog timer ( WDT ) configuration*/	 
 EE_WDT_OFF = 0 , /* @ENUM_VAL_DESC@ Set WDT OFF*/	 
 EE_WDT_TIME_6SEC = 6000 , /* @ENUM_VAL_DESC@ Set WDT to 6 sec*/ // in miliseconds ; for max WCDMA / GSM DRX cycle	 
 EE_WDT_TIME_7SEC = 7000 , /* @ENUM_VAL_DESC@ Set WDT to 7 sec*/ // in miliseconds	 
 EE_WDT_TIME_8SEC = 8000 , /* @ENUM_VAL_DESC@ Set WDT to 8 sec*/ // in miliseconds	 
 EE_WDT_TIME_10SEC = 10000 , /* @ENUM_VAL_DESC@ Set WDT to 10 sec*/ // in miliseconds	 
 EE_WDT_TIME_20SEC = 20000 , /* @ENUM_VAL_DESC@ Set WDT to 20 sec*/ // in miliseconds	 
 EE_WDT_TIME_30SEC = 30000 , /* @ENUM_VAL_DESC@ Set WDT to 30 sec*/ // in miliseconds	 
 EE_WDT_TIME_MAX = 0xFFFF /* @ENUM_VAL_DESC@ Set WDT to MAX ( 65.535000 sec ) */ // UINT16	 
 } EE_WdtTimeCfg_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Error Handler Configuration*/	 
 /* @STRUCT_NVM_FILE_NAME@ EEHandlerConfig.nvm*/	 
 EE_OnOff_t AssertHandlerOn ; /* @ITEM_DESC@ Configure EE logs data in case of ASSERT , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t ExcepHandlerOn ; /* @ITEM_DESC@ Configure EE logs data in case of Exception handler , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_WarningOn_t WarningHandlerOn ; /* @ITEM_DESC@ Configure EE logs data in case of warning , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t powerUpLogOn ; /* @ITEM_DESC@ Configure EE logs data at power-on , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t extHandlersOn ; /* @ITEM_DESC@ Configure EE logs data in case of extHandler , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t printRecentLogOnStartup ; /* @ITEM_DESC@ Indicates if to search for EE logs on NVM and notify regarding them on startup , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 FinalAct_t finalAction ; /* @ITEM_DESC@ Configures Error handling final action , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT32 EELogFileSize ; /* @ITEM_DESC@ Set Error Handler log file size , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes*/	 
 UINT16 delayOnStartup ; /* @ITEM_DESC@ Set delay on startup before printing recent log , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF in 5 milisec ticks */ // Delay for ICAT log coverage in 5 ms units	 
 EE_ContextType_t assertContextBufType ; /* @ITEM_DESC@ What context to save in case ASSERT happened , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_ContextType_t exceptionContextBufType ; /* @ITEM_DESC@ What context to save in case Exception Handler happened , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_ContextType_t warningContextBufType ; /* @ITEM_DESC@ What context to save in case Warning happened , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
	 
	 
	 
 UINT8 reserved1 [ 8 ] ; /* @ITEM_DESC@ reserved place for when deferredCfg not used , @ITEM_MODE@ , @ITEM_UNIT@ Not relevant*/	 
	 
 EE_WdtTimeCfg_t wdtConfigTime ; /* @ITEM_DESC@ WatchDog timer configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/ // UINT16	 
 UINT16 sysEeHandlerLimit ; /* @ITEM_DESC@ EE handler system limit ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 1 -0xFFFF , 0 -No limit*/ // relevant for EE_ASSISTING_MASTER only ; ZERO is no limits	 
 UINT32 dumpDdrSizeBytes ; /* @ITEM_DESC@ Limit DDR size to dump ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes , 0x1 -0x400 - No limit*/ // relevant for EE_ASSISTING_MASTER only	 
 UINT8 reserved [ 24 ] ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 UINT32 dumpResetFlag ; /*default is 0 . When finalAction is EE_RESET , 1 :dump and then silent reset ; 0 :silent reset without dump*/	 
 } EE_Configuration_t;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 SULOG_OFF = 0 ,	 
 SULOG_ENABLE_HW_SW ,	 
 SULOG_ENABLE_HW ,	 
 SULOG_ENABLE_SW ,	 
 } SULOG_TYPE_ID;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 value32 [ 2 ] ;	 
 } LteSulogCfgS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 SULOG_TYPE_ID logSwitch ;	 
 LteSulogCfgS PrintLevel ;	 
 UINT8 Sulog2SdCardFlag ;	 
 UINT8 reserved [ 3 ] ;	 
 } SULOG_ST;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 SULOG_TYPE_ID logSwitch ;	 
 LteSulogCfgS PrintLevelForSdCardDisable ;	 
 LteSulogCfgS PrintLevelForSdCardEnable ;	 
 UINT8 Sulog2SdCardFlag ;	 
 } SulogCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 HSL_DISABLE = 0 ,	 
 HSL_BIGBOARD_ENABLE ,	 
 HSL_MINIBOARD_ENABLE ,	 
 } HSL_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _PM_DISABLE = 0 ,	 
 _PM_ENABLE ,	 
 } PM_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 VCXO_SD_DISABLE = 0 ,	 
 VCXO_SD_ENABLE ,	 
 } VCXO_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 SD_LOG_DISABLE = 0 ,	 
 SD_LOG_ENABLE ,	 
 } SDLOG_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _L1_ACAT_LOG_DISABLE = 0 ,	 
 _L1_ACAT_LOG_ENABLE ,	 
 } L1AcatLog_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 L1_IML2DDR_DISABLE = 0 ,	 
 L1_IML2DDR_ENABLE ,	 
 } L1IML2DDR_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 PM_TYPE PMCfgVal ;	 
 HWDFC_TYPE HWDFCCfgVal ;	 
 HWDFC_TEST_TYPE HWDFCTestCfgVal ;	 
 VCXO_TYPE VCXOCfgVal ;	 
 SDLOG_TYPE SDLogCfgVal ;	 
 L1AcatLog_TYPE L1AcatLogVal ; /* CQ0003TTTT */	 
	 
	 
	 
 IMLCfgDataS IMLCfgdata ;	 
 } HSLCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _CPU_USAGE_DUMP_DISABLE = 0 ,	 
 _CPU_USAGE_DUMP_ENABLE	 
 } CPUUSAGEDUMP_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 CPUUSAGEDUMP_TYPE cpuUsageDumpEnable ;	 
 UINT32 dumpInterval ;	 
 } SYSDBGCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 APT_DISABLE = 0 ,	 
 APT_ENABLE ,	 
 } APT_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT8 ucVcxoStableTime ;	 
 UINT8 ucPllStableTime ;	 
 UINT8 ucClkGenTime ;	 
 UINT8 ucDualCarrierFlag ;	 
 UINT8 ucDualAntFlag ;	 
 APT_TYPE AptFlag ;	 
 } MSACfgDataS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 MSACfgDataS MsaCfg ;	 
 HSLCfgDataS HslCfg ;	 
 SYSDBGCfgDataS SysDbgCfg ;	 
 Log_ConfigS LogCfg ;	 
 Usb_DriverS usbDrvCfg ;	 
 LTE_CONFIG_S LteCfg ;	 
 Ymodem_Dump_type YmodemCfg ;	 
 SulogCfgDataS SulogCfg ;	 
 RTICfg_t rtiConfig ;	 
 uartCfgDataS uartCfg ;	 
 EE_Configuration_t eeCfg ;	 
 diagCfgDataS diagCfg ;	 
 UINT32 TailGuard ;	 
 } PlatformCfgDataS;

typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
typedef unsigned char BYTE ;
typedef unsigned short int WORD ;
typedef unsigned long DWORD ;
typedef WORD * WORD_PTR ;
typedef DWORD * DWORD_PTR ;
typedef BYTE BYTE_BITMASK ;
typedef VOID_PTR * VOID_PTR_PTR ;
typedef WORD FLASH_DATA_WIDTH ;
typedef char FDI_TCHAR ;
typedef OSASemaRef SEM_ID ;
typedef int SEM_STATUS ;
typedef SEM_MTX * SEM_MTX_ID ;
typedef unsigned short FILE_ID ;
typedef unsigned int UINT ;
typedef unsigned char BYTE ;
typedef unsigned short WORD ;
typedef unsigned short WCHAR ;
typedef unsigned long DWORD ;
typedef char TCHAR ;
typedef DWORD FSIZE_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_comm_FS.ppp
//PPL Source File Name : X:\\diag\\diag_comm\\src\\diag_comm_FS.c
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
//ICAT EXPORTED ENUM 
 typedef enum {	 
	 
 IMLConfig_OFF=0 ,	 
 IMLConfig_2SD ,	 
 IMLConfig_2DDR ,	 
 IMLConfig_2HSL_BIGBOARD ,	 
 IMLConfig_2HSL_SMALLBOARD ,	 
 IMLConfig_2SU_ENABLE ,	 
 IMLConfig_2SU_DISABLE	 
	 
 } IMLCONFIG_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
	 
 IMLCONFIG_TYPE IMLConfigVal ;	 
	 
 UINT8 DataLen ;	 
 UINT8 data [ 64 ] ;	 
 } IMLCfgDataS;

typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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

typedef UINT32 lfs_size_t ;
typedef UINT32 lfs_off_t ;
typedef int lfs_ssize_t ;
typedef int lfs_soff_t ;
typedef UINT32 lfs_block_t ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPC_DDR_RELQ_REQ = 0x00000001 ,	 
 ACIPC_DDR_RELQ_ACK = 0x00000001 ,	 
 ACIPC_DDR_260_RELQ_REQ = 0x00000002 ,	 
 ACIPC_DDR_260_RELQ_ACK = 0x00000002 ,	 
 ACIPC_MSL_SLEEP_ALLOW = 0x00000004 ,	 
 ACIPC_MSL_WAKEUP_ACK = 0x00000008 ,	 
 ACIPC_MSL_WAKEUP_REQ = 0x00000010 ,	 
 ACIPC_DATA_Q_ADRS = 0x00000020 ,	 
 ACIPC_DATA_IND = 0x00000040 ,	 
 ACIPC_SPARE_1 = 0x00000080 ,	 
 ACIPC_DDR_260_READY_REQ = 0x00000100 ,	 
 ACIPC_DDR_260_READY_ACK = 0x00000100 ,	 
 ACIPC_DDR_READY_REQ = 0x00000200 ,	 
 ACIPC_DDR_READY_ACK = 0x00000200 ,	 
	 
 } ACIPC_EventsE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 DDR_FREQUENCY_104 ,	 
 DDR_FREQUENCY_156 ,	 
 DDR_FREQUENCY_208 ,	 
 DDR_FREQUENCY_312 ,	 
 DDR_FREQUENCY_400 ,	 
 DDR_FREQUENCY_528 ,	 
 DDR_FREQUENCY_NUM ,	 
 DDR_FREQUENCY_INVALID = DDR_FREQUENCY_NUM ,	 
 } DDR_FREQUENCY;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPC_DDR_AVAIL=0x00000001	 
 } ACIPC_FlagsE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 ACIPC_CB_NORMAL=0 , /* callback will be called only if the DDR available */	 
 ACIPC_CB_ALWAYS_NO_DDR /* callback will be called always , even if the DDR is not available*/	 
 } ACIPC_CBModeE;

typedef UINT32 ( *ACIPC_RecEventCB ) ( UINT32 eventsStatus ) ;
typedef UINT32 ACIPC_Data ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 _HWDFC_TEST_DISABEL=0 ,	 
 _HWDFC_TEST_ACTIVE_LPM_CORE ,	 
 _HWDFC_TEST_ACTIVE_LPM ,	 
 _HWDFC_TEST_ACTIVE ,	 
 _HWDFC_TEST_CORE ,	 
 _HWDFC_TEST_NEW_API ,	 
 } HWDFC_TEST_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _HWDFC_DISABEL=0 ,	 
 _HWDFC_ENABLE ,	 
 } HWDFC_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 CFG_PP_0 = 0 ,	 
 CFG_PP_1 ,	 
 CFG_PP_2 ,	 
 CFG_PP_3 ,	 
 CFG_PP_4 ,	 
 CFG_PP_5 ,	 
 CFG_PP_6 ,	 
 CFG_PP_7 ,	 
 CFG_PP_AUTO = 0xFF , // CQ00023417	 
 } PP_TYPE;

//ICAT EXPORTED ENUM - add by zhangwl for PP chang - CQ00023417 
 typedef enum {	 
 CPIDLE_0_5 = 5 ,	 
 CPIDLE_1_0 = 10 ,	 
 CPIDLE_1_5 = 15 ,	 
 CPIDLE_2_0 = 20 ,	 
 CPIDLE_2_5 = 25 ,	 
 CPIDLE_3_0 = 30 ,	 
 CPIDLE_3_5 = 35 ,	 
 CPIDLE_4_0 = 40 ,	 
 CPIDLE_4_5 = 45 ,	 
 CPIDLE_5_0 = 50 ,	 
 CPIDLE_5_5 = 55 ,	 
 CPIDLE_6_0 = 60 ,	 
 CPIDLE_6_5 = 65 ,	 
 CPIDLE_7_0 = 70 ,	 
 CPIDLE_7_5 = 75 ,	 
 CPIDLE_8_0 = 80 ,	 
 CPIDLE_8_5 = 85 ,	 
 CPIDLE_9_0 = 90 ,	 
 CPIDLE_9_5 = 95 ,	 
 CPIDLE_DEFAULT = 0xFF ,	 
 } PP_CPIDLE_T;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 LTE_DMA_78M = 0x7F ,	 
 LTE_DMA_156M = 0x5F ,	 
 LTE_DMA_208M = 0x4B ,	 
 LTE_DMA_312M = 0x4F ,	 
 } LTE_DMA_CLOCK;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 VOLTAGE_0_65 = 0x04 ,	 
 VOLTAGE_0_70 = 0x08 ,	 
 VOLTAGE_0_75 = 0x0C ,	 
 VOLTAGE_0_775 = 0x0E ,	 
 VOLTAGE_0_7875 = 0x0F ,	 
 VOLTAGE_0_80 = 0x10 ,	 
 VOLTAGE_0_8125 = 0x11 ,	 
 VOLTAGE_0_825 = 0x12 ,	 
 VOLTAGE_0_8375 = 0x13 ,	 
 VOLTAGE_0_85 = 0x14 ,	 
 VOLTAGE_0_8625 = 0x15 ,	 
 VOLTAGE_0_875 = 0x16 ,	 
 VOLTAGE_0_8875 = 0x17 ,	 
 VOLTAGE_0_90 = 0x18 ,	 
 VOLTAGE_0_9125 = 0x19 ,	 
 VOLTAGE_0_925 = 0x1A ,	 
 VOLTAGE_0_9375 = 0x1B ,	 
 VOLTAGE_0_95 = 0x1C ,	 
 VOLTAGE_0_9625 = 0x1D ,	 
 VOLTAGE_0_975 = 0x1E ,	 
 VOLTAGE_0_9875 = 0x1F ,	 
 VOLTAGE_1_00 = 0x20 ,	 
 VOLTAGE_1_0125 = 0x21 ,	 
 VOLTAGE_1_025 = 0x22 ,	 
 VOLTAGE_1_0375 = 0x23 ,	 
 VOLTAGE_1_05 = 0x24 ,	 
 VOLTAGE_1_0625 = 0x25 ,	 
 VOLTAGE_1_075 = 0x26 ,	 
 VOLTAGE_1_0875 = 0x27 ,	 
 VOLTAGE_1_10 = 0x28 ,	 
 VOLTAGE_1_1125 = 0x29 ,	 
 VOLTAGE_1_125 = 0x2A ,	 
 VOLTAGE_1_1375 = 0x2B ,	 
 VOLTAGE_1_15 = 0x2C ,	 
 VOLTAGE_1_1625 = 0x2D ,	 
 VOLTAGE_1_175 = 0x2E ,	 
 VOLTAGE_1_1875 = 0x2F ,	 
 VOLTAGE_1_20 = 0x30 ,	 
 VOLTAGE_1_2125 = 0x31 ,	 
 VOLTAGE_1_225 = 0x32 ,	 
 VOLTAGE_1_2375 = 0x33 ,	 
 VOLTAGE_1_25 = 0x34 ,	 
 VOLTAGE_1_2625 = 0x35 ,	 
 VOLTAGE_1_275 = 0x36 ,	 
 VOLTAGE_1_2875 = 0x37 ,	 
 VOLTAGE_1_30 = 0x38 ,	 
 VOLTAGE_1_35 = 0x3C ,	 
 VOLTAGE_DEFAULT = 0xFF ,	 
 } PP_VOLTAGE_T;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 MIPS_5 = 5 ,	 
 MIPS_1_0 = 10 ,	 
 MIPS_1_5 = 15 ,	 
 MIPS_2_0 = 20 ,	 
 MIPS_2_5 = 25 ,	 
 MIPS_3_0 = 30 ,	 
 MIPS_3_5 = 35 ,	 
 MIPS_4_0 = 40 ,	 
 MIPS_4_5 = 45 ,	 
 MIPS_5_0 = 50 ,	 
 MIPS_5_5 = 55 ,	 
 MIPS_6_0 = 60 ,	 
 MIPS_6_5 = 65 ,	 
 MIPS_7_0 = 70 ,	 
 MIPS_7_5 = 75 ,	 
 MIPS_8_0 = 80 ,	 
 MIPS_8_5 = 85 ,	 
 MIPS_9_0 = 90 ,	 
 MIPS_9_5 = 95 ,	 
 MIPS_MAX = 0xFF ,	 
 } Mips_Threshold;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 PP_TYPE ProductPoint ;	 
 Mips_Threshold HighWaterMark ; // add by zhangwl for PP chang - CQ00023417	 
 Mips_Threshold LowWaterMark ; // add by zhangwl for PP chang - CQ00023417	 
 LTE_DMA_CLOCK LTEDmaClock ;	 
 PP_VOLTAGE_T ActiveVoltage ;	 
 PP_VOLTAGE_T SleepVoltage ;	 
 } LTE_CONFIG_S;

//ICAT EXPORTED STRUCT 
 typedef struct NVM_Header 
 {	 
 unsigned long StructSize ; // the size of the user structure below	 
 unsigned long NumofStructs ; // >1 in case of array of structs ( default is 1 ) .	 
 char StructName [ 64 ] ; // the name of the user structure below	 
 char Date [ 32 ] ; // date updated by the ICAT when the file is saved. Filled by calibration SW.	 
 char time [ 32 ] ; // time updated by the ICAT when the file is saved. Filled by calibration SW.	 
 char Version [ 64 ] ; // user version - this field is updated by the SW eng. Every time they update the UserStruct.	 
 char HW_ID [ 32 ] ; // signifies the board number. Filled by calibration SW.	 
 char CalibVersion [ 32 ] ; // signifies the calibration SW version. Filled by calibration SW.	 
 } NVM_Header_ts;

typedef unsigned int size_t ;
typedef unsigned int clock_t ;
typedef unsigned int time_t ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 second ; // Seconds after minute: 0 - 59	 
 UINT8 minute ; // Minutes after hour: 0 - 59	 
 UINT8 hour ; // Hours after midnight: 0 - 23	 
 UINT8 day ; // Day of month: 1 - 31	 
 UINT8 month ; // Month of year: 1 - 12	 
 UINT16 year ; // Calendar year: e.g 2001	 
 } RTC_CalendarTime;

typedef UINT8 RTC_Handle ;
typedef void ( *RTC_ISR ) ( void ) ;
typedef void ( *RTCOnTimeSetNotifyCallback ) ( RTC_CalendarTime* oldTime , RTC_CalendarTime* newTime ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // enumerated	 
 EE_SYS_RESET_EN ,	 
 EE_ASSERT_EN ,	 
 EE_EXCEPTION_EN ,	 
 EE_WARNING_EN ,	 
 EE_NUM_ENTRY_TYPES ,	 
 // Codes	 
 EE_SYS_RESET = 300 ,	 
 EE_ASSERT = 350 ,	 
 EE_EXCEPTION = 450 ,	 
 EE_WARNING = 550	 
 } EE_entry_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EEE_DataAbort ,	 
 EEE_PrefetchAbort ,	 
 EEE_FatalError ,	 
 EEE_SWInterrupt ,	 
 EEE_UndefInst ,	 
 EEE_ReservedInt	 
 } EE_ExceptionType_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_NO_RESET_SOURCE ,	 
 EE_POWER_ON_RESET = PMU_POR ,	 
 EE_EXT_MASTER_RESET ,	 
 EE_WDT_RESET = ( PMU_EMR+2 )	 
 } EE_PMU_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 r0 ; /* register r0 contents */	 
 UINT32 r1 ; /* register r1 contents */	 
 UINT32 r2 ; /* register r2 contents */	 
 UINT32 r3 ; /* register r3 contents */	 
 UINT32 r4 ; /* register r4 contents */	 
 UINT32 r5 ; /* register r5 contents */	 
 UINT32 r6 ; /* register r6 contents */	 
 UINT32 r7 ; /* register r7 contents */	 
 UINT32 r8 ; /* register r8 contents */	 
 UINT32 r9 ; /* register r9 contents */	 
 UINT32 r10 ; /* register r10 contents */	 
 UINT32 r11 ; /* register r11 contents */	 
 UINT32 r12 ; /* register r12 contents */	 
 UINT32 SP ; /* register r13 contents */	 
 UINT32 LR ; /* register r14 contents ( excepted mode ) */	 
 UINT32 PC ; /* PC - excepted instruction */	 
 UINT32 cpsr ; /* saved program status register contents */	 
 UINT32 FSR ; /* Fault status register */	 
 UINT32 FAR_R ; /* Fault address register */	 
 EE_PMU_t PMU_reg ; /* saved reset cause - should be last */	 
	 
 // UINT32 PESR ; / * Extension * /	 
 // UINT32 XESR ;	 
 // UINT32 PEAR ;	 
 // UINT32 FEAR ;	 
 // UINT32 SEAR ;	 
 // UINT32 GEAR ;	 
 } EE_RegInfo_Data_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ EE context types to be saved in the context buffer*/	 
 EE_CT_None , /* @ENUM_VAL_DESC@ Save no context*/	 
 EE_CT_ExecTrace , /* @ENUM_VAL_DESC@ Save Trace buffer*/	 
 EE_CT_StackDump /* @ENUM_VAL_DESC@ Save Stack Dump*/	 
 } EE_ContextType_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_CDT_None ,	 
 EE_CDT_ExecTrace ,	 
 EE_CDT_StackDump ,	 
 EE_CDT_UserDefined=0x10	 
 } EE_ContextDataType_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 _PESR ;	 
 UINT32 _XESR ;	 
 UINT32 _PEAR ;	 
 UINT32 _FEAR ;	 
 UINT32 _SEAR ;	 
 UINT32 _GEAR ;	 
 } EE_XscGasketRegs;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 fileWriteOffset ; // DO NOT REMOVE OR CHANGE TYPE!!! ( for cyclic file )	 
 EE_entry_t type ;	 
 RTC_CalendarTime dateAndTime ;	 
 char desc [ 100 ] ; /* Description string size =ERROR_HANDLER_MAX_DESC_SIZE*/	 
 EE_RegInfo_Data_t RegInfo ;	 
 EE_ContextDataType_t contextBufferType ;	 
 UINT8 contextBuffer [ 512 ] ;	 
 UINT32 CHKPT0 ;	 
 UINT32 CHKPT1 ;	 
 char taskName [ 10 ] ;	 
 UINT32 taskStackStart ;	 
 UINT32 taskStackEnd ;	 
 // UP TO HERE 0x1e4 bytes ( out of 0x200 allocated by linker control file INT_RAM_EE segment )	 
 EE_XscGasketRegs xscaleGasketRegs ;	 
 UINT32 warningCntr ; // reserved [ 1 ] ;	 
	 
	 
	 
	 
 } EE_Entry_t;

typedef void voidPFuncVoid ( void ) ;
typedef void ( * ExceptionHendler ) ( EE_RegInfo_Data_t* ) ;
typedef EEHandlerAction ( * ExceptionHendlerExt ) ( EE_ExceptionType_t type , EE_RegInfo_Data_t* ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures Error handling final action*/	 
 EE_RESET , /* @ENUM_VAL_DESC@ final action RESET*/	 
 EE_STALL , /* @ENUM_VAL_DESC@ final action STALL*/	 
 EE_CONTINUE , /* @ENUM_VAL_DESC@ report but continue ( like ignore or warning ) */	 
 EE_EXTERNAL , /* @ENUM_VAL_DESC@ final action EXTERNAL*/	 
 EE_RESET_START_BASIC , /* @ENUM_VAL_DESC@ final action RESET START BASIC*/	 
 EE_NON_WDT_SERIAL /* @ENUM_VAL_DESC@ final action NON WDT SERIAL*/	 
 } FinalAct_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Error Handler options ON / OFF enum*/	 
 EE_OFF , /* @ENUM_VAL_DESC@ Option turned OFF*/	 
 EE_ON /* @ENUM_VAL_DESC@ Option turned ON*/	 
 } EE_OnOff_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure EE logs data in case of warning*/	 
 EE_WARN_OFF , /* @ENUM_VAL_DESC@ EE warning log OFF*/	 
 EE_WARN_ASSERTCONTINUE , /* @ENUM_VAL_DESC@ EE logs warning assert and continue */	 
 EE_WARN_ASSERT /* @ENUM_VAL_DESC@ EE logs warning assert */	 
 } EE_WarningOn_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_VER_3 = 3 ,	 
 EE_VER	 
 } EE_Version_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 EE_HSL_OFF = 0 ,	 
 EE_HSL_1_8V= 1 ,	 
 EE_HSL_3V = 3	 
 } EE_HSL_V_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ WatchDog timer ( WDT ) configuration*/	 
 EE_WDT_OFF = 0 , /* @ENUM_VAL_DESC@ Set WDT OFF*/	 
 EE_WDT_TIME_6SEC = 6000 , /* @ENUM_VAL_DESC@ Set WDT to 6 sec*/ // in miliseconds ; for max WCDMA / GSM DRX cycle	 
 EE_WDT_TIME_7SEC = 7000 , /* @ENUM_VAL_DESC@ Set WDT to 7 sec*/ // in miliseconds	 
 EE_WDT_TIME_8SEC = 8000 , /* @ENUM_VAL_DESC@ Set WDT to 8 sec*/ // in miliseconds	 
 EE_WDT_TIME_10SEC = 10000 , /* @ENUM_VAL_DESC@ Set WDT to 10 sec*/ // in miliseconds	 
 EE_WDT_TIME_20SEC = 20000 , /* @ENUM_VAL_DESC@ Set WDT to 20 sec*/ // in miliseconds	 
 EE_WDT_TIME_30SEC = 30000 , /* @ENUM_VAL_DESC@ Set WDT to 30 sec*/ // in miliseconds	 
 EE_WDT_TIME_MAX = 0xFFFF /* @ENUM_VAL_DESC@ Set WDT to MAX ( 65.535000 sec ) */ // UINT16	 
 } EE_WdtTimeCfg_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Error Handler Configuration*/	 
 /* @STRUCT_NVM_FILE_NAME@ EEHandlerConfig.nvm*/	 
 EE_OnOff_t AssertHandlerOn ; /* @ITEM_DESC@ Configure EE logs data in case of ASSERT , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t ExcepHandlerOn ; /* @ITEM_DESC@ Configure EE logs data in case of Exception handler , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_WarningOn_t WarningHandlerOn ; /* @ITEM_DESC@ Configure EE logs data in case of warning , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t powerUpLogOn ; /* @ITEM_DESC@ Configure EE logs data at power-on , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t extHandlersOn ; /* @ITEM_DESC@ Configure EE logs data in case of extHandler , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t printRecentLogOnStartup ; /* @ITEM_DESC@ Indicates if to search for EE logs on NVM and notify regarding them on startup , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 FinalAct_t finalAction ; /* @ITEM_DESC@ Configures Error handling final action , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT32 EELogFileSize ; /* @ITEM_DESC@ Set Error Handler log file size , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes*/	 
 UINT16 delayOnStartup ; /* @ITEM_DESC@ Set delay on startup before printing recent log , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF in 5 milisec ticks */ // Delay for ICAT log coverage in 5 ms units	 
 EE_ContextType_t assertContextBufType ; /* @ITEM_DESC@ What context to save in case ASSERT happened , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_ContextType_t exceptionContextBufType ; /* @ITEM_DESC@ What context to save in case Exception Handler happened , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_ContextType_t warningContextBufType ; /* @ITEM_DESC@ What context to save in case Warning happened , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
	 
	 
	 
 UINT8 reserved1 [ 8 ] ; /* @ITEM_DESC@ reserved place for when deferredCfg not used , @ITEM_MODE@ , @ITEM_UNIT@ Not relevant*/	 
	 
 EE_WdtTimeCfg_t wdtConfigTime ; /* @ITEM_DESC@ WatchDog timer configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/ // UINT16	 
 UINT16 sysEeHandlerLimit ; /* @ITEM_DESC@ EE handler system limit ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 1 -0xFFFF , 0 -No limit*/ // relevant for EE_ASSISTING_MASTER only ; ZERO is no limits	 
 UINT32 dumpDdrSizeBytes ; /* @ITEM_DESC@ Limit DDR size to dump ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes , 0x1 -0x400 - No limit*/ // relevant for EE_ASSISTING_MASTER only	 
 UINT8 reserved [ 24 ] ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 UINT32 dumpResetFlag ; /*default is 0 . When finalAction is EE_RESET , 1 :dump and then silent reset ; 0 :silent reset without dump*/	 
 } EE_Configuration_t;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 SULOG_OFF = 0 ,	 
 SULOG_ENABLE_HW_SW ,	 
 SULOG_ENABLE_HW ,	 
 SULOG_ENABLE_SW ,	 
 } SULOG_TYPE_ID;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 value32 [ 2 ] ;	 
 } LteSulogCfgS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 SULOG_TYPE_ID logSwitch ;	 
 LteSulogCfgS PrintLevel ;	 
 UINT8 Sulog2SdCardFlag ;	 
 UINT8 reserved [ 3 ] ;	 
 } SULOG_ST;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 SULOG_TYPE_ID logSwitch ;	 
 LteSulogCfgS PrintLevelForSdCardDisable ;	 
 LteSulogCfgS PrintLevelForSdCardEnable ;	 
 UINT8 Sulog2SdCardFlag ;	 
 } SulogCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 HSL_DISABLE = 0 ,	 
 HSL_BIGBOARD_ENABLE ,	 
 HSL_MINIBOARD_ENABLE ,	 
 } HSL_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _PM_DISABLE = 0 ,	 
 _PM_ENABLE ,	 
 } PM_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 VCXO_SD_DISABLE = 0 ,	 
 VCXO_SD_ENABLE ,	 
 } VCXO_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 SD_LOG_DISABLE = 0 ,	 
 SD_LOG_ENABLE ,	 
 } SDLOG_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _L1_ACAT_LOG_DISABLE = 0 ,	 
 _L1_ACAT_LOG_ENABLE ,	 
 } L1AcatLog_TYPE;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 L1_IML2DDR_DISABLE = 0 ,	 
 L1_IML2DDR_ENABLE ,	 
 } L1IML2DDR_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 PM_TYPE PMCfgVal ;	 
 HWDFC_TYPE HWDFCCfgVal ;	 
 HWDFC_TEST_TYPE HWDFCTestCfgVal ;	 
 VCXO_TYPE VCXOCfgVal ;	 
 SDLOG_TYPE SDLogCfgVal ;	 
 L1AcatLog_TYPE L1AcatLogVal ; /* CQ0003TTTT */	 
	 
	 
	 
 IMLCfgDataS IMLCfgdata ;	 
 } HSLCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 _CPU_USAGE_DUMP_DISABLE = 0 ,	 
 _CPU_USAGE_DUMP_ENABLE	 
 } CPUUSAGEDUMP_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 CPUUSAGEDUMP_TYPE cpuUsageDumpEnable ;	 
 UINT32 dumpInterval ;	 
 } SYSDBGCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 APT_DISABLE = 0 ,	 
 APT_ENABLE ,	 
 } APT_TYPE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT8 ucVcxoStableTime ;	 
 UINT8 ucPllStableTime ;	 
 UINT8 ucClkGenTime ;	 
 UINT8 ucDualCarrierFlag ;	 
 UINT8 ucDualAntFlag ;	 
 APT_TYPE AptFlag ;	 
 } MSACfgDataS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 MSACfgDataS MsaCfg ;	 
 HSLCfgDataS HslCfg ;	 
 SYSDBGCfgDataS SysDbgCfg ;	 
 Log_ConfigS LogCfg ;	 
 Usb_DriverS usbDrvCfg ;	 
 LTE_CONFIG_S LteCfg ;	 
 Ymodem_Dump_type YmodemCfg ;	 
 SulogCfgDataS SulogCfg ;	 
 RTICfg_t rtiConfig ;	 
 uartCfgDataS uartCfg ;	 
 EE_Configuration_t eeCfg ;	 
 diagCfgDataS diagCfg ;	 
 UINT32 TailGuard ;	 
 } PlatformCfgDataS;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

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

typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
typedef unsigned char BYTE ;
typedef unsigned short int WORD ;
typedef unsigned long DWORD ;
typedef WORD * WORD_PTR ;
typedef DWORD * DWORD_PTR ;
typedef BYTE BYTE_BITMASK ;
typedef VOID_PTR * VOID_PTR_PTR ;
typedef WORD FLASH_DATA_WIDTH ;
typedef char FDI_TCHAR ;
typedef OSASemaRef SEM_ID ;
typedef int SEM_STATUS ;
typedef SEM_MTX * SEM_MTX_ID ;
typedef unsigned short FILE_ID ;
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\diag_port.ppp
//PPL Source File Name : X:\\diag\\diag_comm\\src\\diag_port.c
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

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 diagErrNoMemory ,	 
 diagErrMemoryOK ,	 
 diagErrExtQueueCongest ,	 
 diagErrINTQueueCongest ,	 
 diagErrCMIQueueCongest ,	 
 diagErrExtQueueOK ,	 
 diagErrINTQueueOK ,	 
 diagErrCMIQueueOK ,	 
 diagErrMSGmaxLen ,	 
 diagErrMsgwarningLen	 
 } diagErrStatesE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 CP_TimeStamp ; // time stamp in COMM when X bytes ( or more ) were produced	 
 UINT32 CP_bytes_produced ; // number of bytes produced in traces in the last period	 
 UINT32 CP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 CP_bytes_sent ; // number of bytes sent out on the internal channel in the last period	 
 UINT32 CP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 CP_max_time_byteOint ; // max time to send a byte over internal interface	 
 UINT32 AP_TimeStamp ; // time stamp in APPS when the message arrived over internal interface and processed	 
 UINT32 AP_bytes_produced ; // number of bytes produced in traces ( on APPS or coming from COMM ) in the last period	 
 UINT32 AP_bytes_dropped ; // number of bytes produced but discarded ( due to congestion ) in the last period	 
 UINT32 AP_bytes_sent ; // number of bytes sent out on the external channel in the last period	 
 UINT32 AP_bytes_sent_tot_time ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 UINT32 AP_max_time_byteOext ; // max time to send a byte over external interface	 
 UINT32 AP_bytes_recieved_from_CP ; // total time to send all bytes in the period ( each send has start / end TS , delta is added to this counter )	 
 // Fields added after first diag release of stats ( rel 4.280000 ) - not exist in all versions!! must be checked for.	 
 UINT16 CP_struct_size ; // size of the statistics structure on CP side ( data allows for backward / forward compatibility )	 
 UINT16 AP_struct_size ; // size of the statistics structure on AP side ( data allows for backward / forward compatibility )	 
 UINT32 CP_bytes_added_INTif ; // bytes added for sending over INT if	 
 UINT32 AP_bytes_removed_INTif ; // bytes recieved from CP and removed ( used for IntIF protocol only )	 
 UINT32 AP_bytes_added_ExtIf ; // bytes added on external interface	 
 } DiagStats_CP_AP_S;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 diagMaxMsgOutLimit ;	 
 UINT32 diagMaxMsgOutWarning ;	 
 UINT32 diagMaxMsgInLimit ;	 
 UINT32 diagMaxMsgInWarning ;	 
 } diagMsgLimitSet_S;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // for external interfaces	 
 tNoConnection ,	 
 tUSBConnection ,	 
 tTCPConnection ,	 
 tUDPConnection ,	 
 tUARTConnection ,	 
 tSSPConnection ,	 
 tVIRTIOConnection ,	 
 // for internal interfaces	 
 tMSLConnection ,	 
 tSHMConnection // shared memory	 
 } EActiveConnectionType;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 tLL_none , // not set	 
 tLL_SSP , // external int. SSP	 
 tLL_UART , // external int. UART	 
 tLL_USB , // external int. USB	 
 tLL_ETHERNET , // external int. over Ethernet port	 
 tLL_LocalIP , // external int. / CMI int. localIP	 
 tLL_ACIPC , // internal int. SHMEM	 
 tLL_SAL , // internal int. MSL o SAL	 
 tLL_GPC , // internal int. MSL o GPC	 
 tLL_FS , // external int. File System	 
 tLL_SC // external int. Storage Card ( SD card )	 
 } EActiveConnectionLL_Type;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 DIAG_COMMDEV_EXT , // EXT is also for clients that communicate with the master CMI	 
 DIAG_COMMDEV_INT ,	 
 DIAG_COMMDEV_CMI ,	 
 // for client-master - up to 5 clients	 
 DIAG_COMMDEV_CMI1 = DIAG_COMMDEV_CMI ,	 
 DIAG_COMMDEV_CMI2 ,	 
 DIAG_COMMDEV_CMI3 ,	 
 DIAG_COMMDEV_CMI4 ,	 
 DIAG_COMMDEV_CMI5 ,	 
 DIAG_COMMDEV_RX_MAX=DIAG_COMMDEV_CMI5 ,	 
	 
 // This enum is used also in UINT8 DiagReportItem_S.clientID and we want to limit the size to 8 bits.	 
 DIAG_COMMDEV_NODEVICE = 0xEF , // large enough value not to be a valid rx interface...	 
 DIAG_COMMDEV_DUMMY = 0x1FFFFFFF // to keep 4 bytes alignment in structs	 
 } COMDEV_NAME;

typedef void ( *DiagICATReadyNotifyEventFunc ) ( void ) ;
typedef void ( *DiagEnterBootLoaderCBFunc ) ( void ) ;
typedef void * ( *DiagMemAlloctionFn ) ( UINT32 size ) ;
typedef void ( *DiagMemFreeFn ) ( void * block ) ;
typedef void ( *FunctionPtr ) ( void * , UINT32 ) ;
typedef void ( *RSVPFunctionPtr ) ( void * , UINT32 , UINT32 ) ;
typedef union {
 UINT8 packedMsgData [ 13 ] ;
 UINT8 msgData [ 13 ] ;
 } PackedUnPackedData ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 MIN_BUFFERS_NUM ;	 
 UINT8 TASK_TIMER_PERIOD ;	 
 UINT8 task_priority ;	 
 } DiagIntIfTaskConfig;

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

DIAG_FILTER ( SW_PLAT , DIAG , DIAG_INT_RX_COMM_NO_DATA , DIAG_FATAL_ERROR)  
 diagPrintf ( " command messsage is not empty " );

DIAG_FILTER ( SW_PLAT , DIAG , DIAG_INT_RX_COMM_Multiple_DATA , DIAG_FATAL_ERROR)  
 diagPrintf ( " CP can not handle multiple message in one buffer " );

DIAG_FILTER ( SW_PLAT , DIAG , DIAG_INT_RX_COMM_ALLOC_FAIL , DIAG_FATAL_ERROR)  
 diagPrintf ( " DIAG_rx_COMMAND - Could not alloc ( alloc len=%d , len=%d , tries=%d ) " , * ( UINT32* ) data + 6 , size , retry );

DIAG_FILTER ( SW_PLAT , DIAG , RX_AP_CMD , DIAG_FATAL_ERROR)  
 diagPrintf ( " Rx AP Cmd , discard! " );

DIAG_FILTER ( SW_PLAT , DIAG , DIAG_INT_RX_COMM_MSG_TO_Q_FAIL , DIAG_FATAL_ERROR)  
 diagPrintf ( " diag_internal_command - msg was not stored in RXMsgQ. Status=%d ( len=%d , tries=%d ) " , 
 status , msg.dataLen , index );

//ICAT EXPORTED FUNCTION - ADEMO , DIAGPORT , DiagDisable 
 void DiagDisable ( void ) 
 {	 
 setDiagBlock ( 1 ) ;	 
	 
 }

//ICAT EXPORTED FUNCTION - ADEMO , DIAGPORT , DiagEnable 
 void DiagEnable ( void ) 
 {	 
 setDiagBlock ( 0 ) ;	 
 }

