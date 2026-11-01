//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\aam_debug.ppp
//PPL Source File Name : X:\\hop\\aam\\src\\aam_debug.c
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
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
typedef UINT32 PM_TimeIn32KHzUnitsT ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 PM_EXT_DBG_EVENT_EMPTY = 0 ,	 
 PM_EXT_DBG_EVENT_GENERAL_PURPOSE = 99 , // for debug purposes , general event to	 
 // track something while debug ( not to be left in code permanently ) !	 
 PM_EXT_DBG_EVENT_D2_EXIT =100 , // 100	 
 PM_EXT_DBG_EVENT_C1_EXIT , // 101	 
 PM_EXT_DBG_EVENT_C1_GATED_EXIT , // 102	 
 PM_EXT_DBG_EVENT_TM_GET_NEAREST , // 103	 
 PM_EXT_DBG_EVENT_TM_SUSPEND , // 104	 
 PM_EXT_DBG_EVENT_TM_SYNCH_AFTER , // 105	 
 PM_EXT_DBG_EVENT_TM_NU_TICK , // 106	 
 PM_EXT_DBG_EVENT_TM_EXT_TICK , // 107	 
 PM_EXT_DBG_EVENT_TM_SKIP_OS_TICK , // 108	 
 PM_EXT_DBG_EVENT_TM_SUSPEND_ENABLE , // 109	 
 PM_EXT_DBG_EVENT_TM_SUSPEND_DISABLE , // 110	 
 PM_EXT_DBG_EVENT_TM_TRIGGER_ERROR , // 111	 
 PM_EXT_DBG_EVENT_TICK_FROM_SYNCH , // 112	 
 PM_EXT_DBG_EVENT_TICK_FROM_TRIGGER , // 113	 
 PM_EXT_DBG_EVENT_TM_HW_TIMER_SET , // 114	 
 PM_EXT_DBG_EVENT_OS_TIMER_EXPIRE , // 115	 
 PM_EXT_DBG_EVENT_TM_TICK_SUSPENDED , // 116	 
 PM_EXT_DBG_EVENT_ACTIVATE_NU_HISR , // 117	 
 PM_EXT_DBG_EVENT_ACTIVATE_GKI_HISR , // 118	 
 PM_EXT_DBG_EVENT_TIMER_DEACTIVATE , // 119	 
 PM_EXT_DBG_EVENT_TIMER_CONFIGURE , // 120	 
 PM_EXT_DBG_EVENT_TIMER_ACTIVATE , // 121	 
 PM_EXT_DBG_EVENT_TIMER_STATUS_CLEAR , // 122	 
 PM_EXT_DBG_EVENT_TIMER_TCMR_SET , // 123	 
 PM_EXT_DBG_EVENT_TIMER_STATUS_READ , // 124	 
 PM_EXT_DBG_EVENT_TIMER_TIER_CLEAR , // 125	 
 PM_EXT_DBG_EVENT_TIMER_TMR_SET , // 126	 
 PM_EXT_DBG_EVENT_TIMER_TCCR_SET , // 127	 
 PM_EXT_DBG_EVENT_TIMER_TIER_SET , // 128	 
 PM_EXT_DBG_EVENT_RM_PREVENT_D2 , // 129	 
 PM_EXT_DBG_EVENT_AAM_PREVENT_D2 , // 130	 
 PM_EXT_DBG_EVENT_GP_FLAG_1 , // 131	 
 PM_EXT_DBG_EVENT_AAM_D2_TIMER_WAKEUP , // 132	 
 PM_EXT_DBG_EVENT_AAM_D2_OWN_WAKEUP , // 133	 
 PM_EXT_DBG_EVENT_AAM_MANAGE_BUSY , // 134	 
 PM_EXT_DBG_EVENT_AAM_MANAGE_FREE , // 135	 
 PM_EXT_DBG_EVENT_AAM_ALLOW_D2 , // 136	 
 PM_EXT_DBG_EVENT_AAM_AA_FORBID_D2 , // 137	 
 PM_EXT_DBG_EVENT_AAM_TM_FORBID_D2 , // 138	 
 PM_EXT_DBG_EVENT_AAM_APP_TM_D2 , // 139	 
 PM_EXT_DBG_EVENT_AAM_OST_TM_D2 , // 140	 
 PM_EXT_DBG_EVENT_RM_TCU_ALLOC , // 141	 
 PM_EXT_DBG_EVENT_RM_TCU_FREE , // 142	 
 PM_EXT_DBG_EVENT_RM_SCK_ALLOC , // 143	 
 PM_EXT_DBG_EVENT_RM_SCK_FREE , // 144	 
 PM_EXT_DBG_EVENT_RM_ALLOW_D2 , // 145	 
 PM_EXT_DBG_EVENT_RM_FORBID_D2 , // 146	 
 PM_EXT_DBG_EVENT_RM_ALLOW_C1_GATED , // 147	 
 PM_EXT_DBG_EVENT_TCU_D2_PREPARE , // 148	 
 PM_EXT_DBG_EVENT_TCU_D2_RECOVER , // 149	 
 PM_EXT_DBG_EVENT_CPA_D2_PREPARE , // 150	 
 PM_EXT_DBG_EVENT_CPA_D2_RECOVER , // 151	 
 PM_EXT_DBG_EVENT_CPA_D2_WAKEUP , // 152	 
 PM_EXT_DBG_EVENT_D2_WAKEUP_TIMER , // 153	 
 PM_EXT_DBG_EVENT_GSM_WAKEUP_SWI , // 154	 
 PM_EXT_DBG_EVENT_GSM_SLEEP_SWI , // 155	 
 ////////////////////////////////////////////// DDR	 
 PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_HIGH_FREQ_ACK_WHILE_RELINQUISH_HIGH_IS_PENDING ,	 
 PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_REQUEST_ACK ,	 
 PM_EXT_DBG_EVENT_CHANGED_TO_SYSTEM_IN_REG_RUNNING_MODE_AND_SEND_REQ ,	 
 PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_REQUEST_ACK_WHILE_HIGH_IS_PENDING ,	 
 PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_HIGH_FREQ_ACK ,	 
 PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_HIGH_FREQ_ACK_AND_SEND_REQ ,	 
 PM_EXT_DBG_EVENT_CHANGED_TO_SYSTEM_IN_REG_RUNNING_MODE ,	 
 PM_EXT_DBG_EVENT_AC_IPC_INTERRUPT_HANDLER ,	 
 PM_EXT_DBG_EVENT_260_REL_ACK ,	 
 PM_EXT_DBG_EVENT_CHANGED_SYSTEM_IN_HIGH_FREQ_MODE ,	 
 PM_EXT_DBG_EVENT_DDR_REG_REQ ,	 
 PM_EXT_DBG_EVENT_DDR_REG_RELINQUISH ,	 
 PM_EXT_DBG_EVENT_DDR_REG_REQ_AND_RELINQUISH ,	 
 PM_EXT_DBG_EVENT_DDR_HF_REQ ,	 
 PM_EXT_DBG_EVENT_DDR_HF_RELINQUISH ,	 
 PM_EXT_DBG_EVENT_DDR_HF_REQ_AND_RELINQUISH ,	 
	 
 PM_EXT_DBG_EVENT_DDR_STATUS_FORBID_D2 ,	 
 ////////////////////////////////////////////// DDR	 
	 
 PM_EXT_DBG_EVENT_RM_ALLOC ,	 
 PM_EXT_DBG_EVENT_RM_FREE ,	 
	 
 PM_EXT_DBG_EVENT_D2_ENTRY ,	 
 PM_EXT_DBG_EVENT_C1_ENTRY ,	 
 PM_EXT_DBG_EVENT_C1_GATED_ENTRY ,	 
 PM_EXT_DBG_EVENT_D0CS_ENTRY ,	 
 PM_EXT_DBG_EVENT_D0CS_EXIT ,	 
 // BRN	 
 PM_EXT_DBG_EVENT_VCTCXO_RELINQUISH ,	 
 PM_EXT_DBG_EVENT_VCTCXO_REQUEST ,	 
 PM_EXT_DBG_EVENT_DDR_LPM_DONE ,	 
 PM_EXT_DBG_EVENT_POUT_DISABLE ,	 
 PM_EXT_DBG_EVENT_POUT_ENABLE ,	 
 PM_EXT_DBG_EVENT_FREQ_CHANGE_HIGH ,	 
 PM_EXT_DBG_EVENT_FREQ_CHANGE_LOW ,	 
 PM_EXT_DBG_EVENT_FREQ_CHANGE_USER ,	 
 PM_EXT_DBG_EVENT_FREQ_CHANGE_START ,	 
 PM_EXT_DBG_EVENT_FREQ_CHANGE_DONE ,	 
 PM_EXT_DBG_EVENT_FREQ_CHANGE_GET_FREQ ,	 
 PM_EXT_DBG_EVENT_DVFM_TABLE_UPDATE ,	 
 PM_EXT_DBG_EVENT_LPM_DECISION ,	 
 PM_EXT_DBG_EVENT_SRAM_MEMORY_ERRORS_COUNT ,	 
 PM_EXT_DBG_WAKEUP_SRC ,	 
 PM_EXT_DBG_WAKEUP_SRC_NOTREGISTER ,	 
 PM_EXT_DBG_EVENT_NO_DATA = 1500 , /* indicates that no data is send with the event	 
 ( and forces the enum to be treated as UINT32 ) */	 
 PM_EXT_DBG_DATA_FAKE_D2 =0x2000000 , //	 
 PM_EXT_DBG_DATA_REAL_D2 =0x4000000 // we add to this bit hte wakeup event register	 
 // - relevant bits are 0 -19	 
 } PM_EventTypeE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 PM_TimeIn32KHzUnitsT timeStamp ;	 
 PM_EventTypeE event ;	 
 UINT32 data ;	 
 } PM_TimeStampLogEnteryS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 nextEntryIndex ;	 
 PM_TimeStampLogEnteryS eventLog [ 256 ] ;	 
 BOOL logEnabled ;	 
 BOOL cyclic ;	 
 } PM_EventLogS;

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
 typedef enum {	 
 COMMPM_PP_NOTSET ,	 
 COMMPM_PP_1 ,	 
 COMMPM_PP_2 ,	 
 COMMPM_PP_3 ,	 
 COMMPM_PP_4 ,	 
 COMMPM_NUMBER_OF_PP = 4	 
 } CommPM_PPE;

typedef void ( *COMMPM_DDRAckNotificationT ) ( CommPM_DDRAckE ackType ) ;
typedef void ( *COMMPM_DDRDVFMNotificationT ) ( CommPM_PPE PPType ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 Service_UART = 0x01 ,	 
 Enable_TCU_clock= 0x02 ,	 
 Service_HSPDA = 0x04 ,	 
 Service_ICAT = 0x08 ,	 
 Service_client5 = 0x10 ,	 
 Service_client6 = 0x20 ,	 
 Service_client7 = 0x40 ,	 
 Service_client8 = 0x80	 
	 
 } CommPM_servicesD1E;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 COMMPM_MODEM_ENABLE = 0 ,	 
 COMMPM_MODEM_DISABLE ,	 
 COMMPM_INVALID_STATE	 
	 
 } PM_Modem_StateE;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 D2mode ; // 0 - no D2 , 1 - D2 alike , 2 - full D2	 
 UINT32 D2Variation ; // 0 Stay in D0 , 1 , go to C1 , 2 Full D2	 
 UINT32 LPTsleepTicks ; // how many ticks the LPT should sleep	 
 // temp solution for L1 Standalone.	 
 UINT32 LPTdebugBusyWait ; // to enable time to enter commands when	 
 // waking up ( since currently ( Sep 6 ) at C1 / D2	 
 // we can not submit commands )	 
 UINT32 DDRFunctionalityIsOn ; // 0 -regular work without DDR / 1 -DDR functionality is open for debug / 2 -DDR full functionality	 
 UINT32 endlessLoopAfterD2nExit ;	 
 UINT32 endlessLoopAfterDDRgrantnTimes ;	 
 UINT32 kickWDTonD2Exit ;	 
 UINT16 ServiceD1control ; // word that indicates service controlling D1 , if bit is set , D1 should be prevented	 
 // ( the bit position is set by the enum CommPM_servicesD1E )	 
 UINT8 AppsCommSyncActivated ;	 
 BOOL allowC1 ; // when set real C1 from HW ( if D2 set , also C1 ? )	 
 BOOL notifyMSA ; // if set - we work with L1 , and should notify them	 
 // otherwise we are in ' D2 standalone ' - only us	 
 BOOL LPTidle ; // LPT does nothing	 
 BOOL LPTdecisionOnly ; // do only decision no setting to HW , no prepare	 
 // ( means no real D2 , no C1 ) ( not relevant in LPTidle )	 
 // if not set - we have full LPT functionality	 
 BOOL L1isRegister ; // to synchronize D2 decisions on L1 registration	 
 BOOL PmDebugTaskEnalbe ; // to enable / disable comm pm debug task	 
 } CommPM_workModeS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 DdrHfRequestTS ; // current client request TS ( maybe DDR in HF already )	 
 UINT32 DdrHfRequestFirstClientTS ; // signifies the first client request ( the one we wait for its ack )	 
 UINT32 DdrRegRequestTS ;	 
 UINT32 DdrRegMaxResponseTime ;	 
 UINT32 DdrHfClientTabResponseTime [ 30 ] ;	 
 UINT32 DdrRegClientTabResponseTime [ 30 ] ;	 
 UINT32 DdrHfMaxResponseTime ;	 
 } CommPM_DDRtimingS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 CommPM_Active ,	 
 CommPM_Idle ,	 
 COMMPM_NUMBER_OF_CPU_STATES ,	 
 } CommPM_CPUStateE;

typedef int ( *MMIC1PrepareFunc ) ( void ) ;
typedef int ( *MMIC1RecoverFunc ) ( void ) ;
typedef int ( *MMID2PrepareFunc ) ( void ) ;
typedef int ( *MMID2RecoverFunc ) ( BOOL ExitFromD2 ) ;
typedef int ( *MMIStatusFunc ) ( void ) ;
typedef UINT32 AAM_AppsStatusT ;
typedef UINT32 AAM_HandleT ;
typedef void ( AAM_CallbackFuncT ) ( void ) ;
typedef void ( AAM_CallbackFuncPrepareT ) ( PM_PowerStatesE statetoprepare ) ;
typedef void ( AAM_CallbackFuncRecoverT ) ( PM_PowerStatesE stateexited , BOOL b_DDR_ready , BOOL b_RegsRetainedState ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\aam.ppp
//PPL Source File Name : X:\\hop\\aam\\src\\aam.c
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
typedef UINT32 PM_TimeIn32KHzUnitsT ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 PM_EXT_DBG_EVENT_EMPTY = 0 ,	 
 PM_EXT_DBG_EVENT_GENERAL_PURPOSE = 99 , // for debug purposes , general event to	 
 // track something while debug ( not to be left in code permanently ) !	 
 PM_EXT_DBG_EVENT_D2_EXIT =100 , // 100	 
 PM_EXT_DBG_EVENT_C1_EXIT , // 101	 
 PM_EXT_DBG_EVENT_C1_GATED_EXIT , // 102	 
 PM_EXT_DBG_EVENT_TM_GET_NEAREST , // 103	 
 PM_EXT_DBG_EVENT_TM_SUSPEND , // 104	 
 PM_EXT_DBG_EVENT_TM_SYNCH_AFTER , // 105	 
 PM_EXT_DBG_EVENT_TM_NU_TICK , // 106	 
 PM_EXT_DBG_EVENT_TM_EXT_TICK , // 107	 
 PM_EXT_DBG_EVENT_TM_SKIP_OS_TICK , // 108	 
 PM_EXT_DBG_EVENT_TM_SUSPEND_ENABLE , // 109	 
 PM_EXT_DBG_EVENT_TM_SUSPEND_DISABLE , // 110	 
 PM_EXT_DBG_EVENT_TM_TRIGGER_ERROR , // 111	 
 PM_EXT_DBG_EVENT_TICK_FROM_SYNCH , // 112	 
 PM_EXT_DBG_EVENT_TICK_FROM_TRIGGER , // 113	 
 PM_EXT_DBG_EVENT_TM_HW_TIMER_SET , // 114	 
 PM_EXT_DBG_EVENT_OS_TIMER_EXPIRE , // 115	 
 PM_EXT_DBG_EVENT_TM_TICK_SUSPENDED , // 116	 
 PM_EXT_DBG_EVENT_ACTIVATE_NU_HISR , // 117	 
 PM_EXT_DBG_EVENT_ACTIVATE_GKI_HISR , // 118	 
 PM_EXT_DBG_EVENT_TIMER_DEACTIVATE , // 119	 
 PM_EXT_DBG_EVENT_TIMER_CONFIGURE , // 120	 
 PM_EXT_DBG_EVENT_TIMER_ACTIVATE , // 121	 
 PM_EXT_DBG_EVENT_TIMER_STATUS_CLEAR , // 122	 
 PM_EXT_DBG_EVENT_TIMER_TCMR_SET , // 123	 
 PM_EXT_DBG_EVENT_TIMER_STATUS_READ , // 124	 
 PM_EXT_DBG_EVENT_TIMER_TIER_CLEAR , // 125	 
 PM_EXT_DBG_EVENT_TIMER_TMR_SET , // 126	 
 PM_EXT_DBG_EVENT_TIMER_TCCR_SET , // 127	 
 PM_EXT_DBG_EVENT_TIMER_TIER_SET , // 128	 
 PM_EXT_DBG_EVENT_RM_PREVENT_D2 , // 129	 
 PM_EXT_DBG_EVENT_AAM_PREVENT_D2 , // 130	 
 PM_EXT_DBG_EVENT_GP_FLAG_1 , // 131	 
 PM_EXT_DBG_EVENT_AAM_D2_TIMER_WAKEUP , // 132	 
 PM_EXT_DBG_EVENT_AAM_D2_OWN_WAKEUP , // 133	 
 PM_EXT_DBG_EVENT_AAM_MANAGE_BUSY , // 134	 
 PM_EXT_DBG_EVENT_AAM_MANAGE_FREE , // 135	 
 PM_EXT_DBG_EVENT_AAM_ALLOW_D2 , // 136	 
 PM_EXT_DBG_EVENT_AAM_AA_FORBID_D2 , // 137	 
 PM_EXT_DBG_EVENT_AAM_TM_FORBID_D2 , // 138	 
 PM_EXT_DBG_EVENT_AAM_APP_TM_D2 , // 139	 
 PM_EXT_DBG_EVENT_AAM_OST_TM_D2 , // 140	 
 PM_EXT_DBG_EVENT_RM_TCU_ALLOC , // 141	 
 PM_EXT_DBG_EVENT_RM_TCU_FREE , // 142	 
 PM_EXT_DBG_EVENT_RM_SCK_ALLOC , // 143	 
 PM_EXT_DBG_EVENT_RM_SCK_FREE , // 144	 
 PM_EXT_DBG_EVENT_RM_ALLOW_D2 , // 145	 
 PM_EXT_DBG_EVENT_RM_FORBID_D2 , // 146	 
 PM_EXT_DBG_EVENT_RM_ALLOW_C1_GATED , // 147	 
 PM_EXT_DBG_EVENT_TCU_D2_PREPARE , // 148	 
 PM_EXT_DBG_EVENT_TCU_D2_RECOVER , // 149	 
 PM_EXT_DBG_EVENT_CPA_D2_PREPARE , // 150	 
 PM_EXT_DBG_EVENT_CPA_D2_RECOVER , // 151	 
 PM_EXT_DBG_EVENT_CPA_D2_WAKEUP , // 152	 
 PM_EXT_DBG_EVENT_D2_WAKEUP_TIMER , // 153	 
 PM_EXT_DBG_EVENT_GSM_WAKEUP_SWI , // 154	 
 PM_EXT_DBG_EVENT_GSM_SLEEP_SWI , // 155	 
 ////////////////////////////////////////////// DDR	 
 PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_HIGH_FREQ_ACK_WHILE_RELINQUISH_HIGH_IS_PENDING ,	 
 PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_REQUEST_ACK ,	 
 PM_EXT_DBG_EVENT_CHANGED_TO_SYSTEM_IN_REG_RUNNING_MODE_AND_SEND_REQ ,	 
 PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_REQUEST_ACK_WHILE_HIGH_IS_PENDING ,	 
 PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_HIGH_FREQ_ACK ,	 
 PM_EXT_DBG_EVENT_CHANGED_TO_WAIT_FOR_DDR_HIGH_FREQ_ACK_AND_SEND_REQ ,	 
 PM_EXT_DBG_EVENT_CHANGED_TO_SYSTEM_IN_REG_RUNNING_MODE ,	 
 PM_EXT_DBG_EVENT_AC_IPC_INTERRUPT_HANDLER ,	 
 PM_EXT_DBG_EVENT_260_REL_ACK ,	 
 PM_EXT_DBG_EVENT_CHANGED_SYSTEM_IN_HIGH_FREQ_MODE ,	 
 PM_EXT_DBG_EVENT_DDR_REG_REQ ,	 
 PM_EXT_DBG_EVENT_DDR_REG_RELINQUISH ,	 
 PM_EXT_DBG_EVENT_DDR_REG_REQ_AND_RELINQUISH ,	 
 PM_EXT_DBG_EVENT_DDR_HF_REQ ,	 
 PM_EXT_DBG_EVENT_DDR_HF_RELINQUISH ,	 
 PM_EXT_DBG_EVENT_DDR_HF_REQ_AND_RELINQUISH ,	 
	 
 PM_EXT_DBG_EVENT_DDR_STATUS_FORBID_D2 ,	 
 ////////////////////////////////////////////// DDR	 
	 
 PM_EXT_DBG_EVENT_RM_ALLOC ,	 
 PM_EXT_DBG_EVENT_RM_FREE ,	 
	 
 PM_EXT_DBG_EVENT_D2_ENTRY ,	 
 PM_EXT_DBG_EVENT_C1_ENTRY ,	 
 PM_EXT_DBG_EVENT_C1_GATED_ENTRY ,	 
 PM_EXT_DBG_EVENT_D0CS_ENTRY ,	 
 PM_EXT_DBG_EVENT_D0CS_EXIT ,	 
 // BRN	 
 PM_EXT_DBG_EVENT_VCTCXO_RELINQUISH ,	 
 PM_EXT_DBG_EVENT_VCTCXO_REQUEST ,	 
 PM_EXT_DBG_EVENT_DDR_LPM_DONE ,	 
 PM_EXT_DBG_EVENT_POUT_DISABLE ,	 
 PM_EXT_DBG_EVENT_POUT_ENABLE ,	 
 PM_EXT_DBG_EVENT_FREQ_CHANGE_HIGH ,	 
 PM_EXT_DBG_EVENT_FREQ_CHANGE_LOW ,	 
 PM_EXT_DBG_EVENT_FREQ_CHANGE_USER ,	 
 PM_EXT_DBG_EVENT_FREQ_CHANGE_START ,	 
 PM_EXT_DBG_EVENT_FREQ_CHANGE_DONE ,	 
 PM_EXT_DBG_EVENT_FREQ_CHANGE_GET_FREQ ,	 
 PM_EXT_DBG_EVENT_DVFM_TABLE_UPDATE ,	 
 PM_EXT_DBG_EVENT_LPM_DECISION ,	 
 PM_EXT_DBG_EVENT_SRAM_MEMORY_ERRORS_COUNT ,	 
 PM_EXT_DBG_WAKEUP_SRC ,	 
 PM_EXT_DBG_WAKEUP_SRC_NOTREGISTER ,	 
 PM_EXT_DBG_EVENT_NO_DATA = 1500 , /* indicates that no data is send with the event	 
 ( and forces the enum to be treated as UINT32 ) */	 
 PM_EXT_DBG_DATA_FAKE_D2 =0x2000000 , //	 
 PM_EXT_DBG_DATA_REAL_D2 =0x4000000 // we add to this bit hte wakeup event register	 
 // - relevant bits are 0 -19	 
 } PM_EventTypeE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 PM_TimeIn32KHzUnitsT timeStamp ;	 
 PM_EventTypeE event ;	 
 UINT32 data ;	 
 } PM_TimeStampLogEnteryS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 nextEntryIndex ;	 
 PM_TimeStampLogEnteryS eventLog [ 256 ] ;	 
 BOOL logEnabled ;	 
 BOOL cyclic ;	 
 } PM_EventLogS;

typedef unsigned long long UINT64 ;
typedef unsigned long TimeIn32KhzUnit ;
typedef void ( *TickCallbackPtr ) ( UINT32 ) ;
typedef TimeIn32KhzUnit ( *SuspendCallbackPtr ) ( void ) ;
typedef void ( *PrepareTimeCallbackPtr ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 COMMPM_PP_NOTSET ,	 
 COMMPM_PP_1 ,	 
 COMMPM_PP_2 ,	 
 COMMPM_PP_3 ,	 
 COMMPM_PP_4 ,	 
 COMMPM_NUMBER_OF_PP = 4	 
 } CommPM_PPE;

typedef void ( *COMMPM_DDRAckNotificationT ) ( CommPM_DDRAckE ackType ) ;
typedef void ( *COMMPM_DDRDVFMNotificationT ) ( CommPM_PPE PPType ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 Service_UART = 0x01 ,	 
 Enable_TCU_clock= 0x02 ,	 
 Service_HSPDA = 0x04 ,	 
 Service_ICAT = 0x08 ,	 
 Service_client5 = 0x10 ,	 
 Service_client6 = 0x20 ,	 
 Service_client7 = 0x40 ,	 
 Service_client8 = 0x80	 
	 
 } CommPM_servicesD1E;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 COMMPM_MODEM_ENABLE = 0 ,	 
 COMMPM_MODEM_DISABLE ,	 
 COMMPM_INVALID_STATE	 
	 
 } PM_Modem_StateE;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 D2mode ; // 0 - no D2 , 1 - D2 alike , 2 - full D2	 
 UINT32 D2Variation ; // 0 Stay in D0 , 1 , go to C1 , 2 Full D2	 
 UINT32 LPTsleepTicks ; // how many ticks the LPT should sleep	 
 // temp solution for L1 Standalone.	 
 UINT32 LPTdebugBusyWait ; // to enable time to enter commands when	 
 // waking up ( since currently ( Sep 6 ) at C1 / D2	 
 // we can not submit commands )	 
 UINT32 DDRFunctionalityIsOn ; // 0 -regular work without DDR / 1 -DDR functionality is open for debug / 2 -DDR full functionality	 
 UINT32 endlessLoopAfterD2nExit ;	 
 UINT32 endlessLoopAfterDDRgrantnTimes ;	 
 UINT32 kickWDTonD2Exit ;	 
 UINT16 ServiceD1control ; // word that indicates service controlling D1 , if bit is set , D1 should be prevented	 
 // ( the bit position is set by the enum CommPM_servicesD1E )	 
 UINT8 AppsCommSyncActivated ;	 
 BOOL allowC1 ; // when set real C1 from HW ( if D2 set , also C1 ? )	 
 BOOL notifyMSA ; // if set - we work with L1 , and should notify them	 
 // otherwise we are in ' D2 standalone ' - only us	 
 BOOL LPTidle ; // LPT does nothing	 
 BOOL LPTdecisionOnly ; // do only decision no setting to HW , no prepare	 
 // ( means no real D2 , no C1 ) ( not relevant in LPTidle )	 
 // if not set - we have full LPT functionality	 
 BOOL L1isRegister ; // to synchronize D2 decisions on L1 registration	 
 BOOL PmDebugTaskEnalbe ; // to enable / disable comm pm debug task	 
 } CommPM_workModeS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 DdrHfRequestTS ; // current client request TS ( maybe DDR in HF already )	 
 UINT32 DdrHfRequestFirstClientTS ; // signifies the first client request ( the one we wait for its ack )	 
 UINT32 DdrRegRequestTS ;	 
 UINT32 DdrRegMaxResponseTime ;	 
 UINT32 DdrHfClientTabResponseTime [ 30 ] ;	 
 UINT32 DdrRegClientTabResponseTime [ 30 ] ;	 
 UINT32 DdrHfMaxResponseTime ;	 
 } CommPM_DDRtimingS;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 CommPM_Active ,	 
 CommPM_Idle ,	 
 COMMPM_NUMBER_OF_CPU_STATES ,	 
 } CommPM_CPUStateE;

typedef int ( *MMIC1PrepareFunc ) ( void ) ;
typedef int ( *MMIC1RecoverFunc ) ( void ) ;
typedef int ( *MMID2PrepareFunc ) ( void ) ;
typedef int ( *MMID2RecoverFunc ) ( BOOL ExitFromD2 ) ;
typedef int ( *MMIStatusFunc ) ( void ) ;
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
 PMU_POR = 1 ,	 
 PMU_EMR ,	 
 PMU_WDTR = ( PMU_EMR+2 )	 
 } PMU_LastResetStatus;

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
typedef UINT32 AAM_AppsStatusT ;
typedef UINT32 AAM_HandleT ;
typedef void ( AAM_CallbackFuncT ) ( void ) ;
typedef void ( AAM_CallbackFuncPrepareT ) ( PM_PowerStatesE statetoprepare ) ;
typedef void ( AAM_CallbackFuncRecoverT ) ( PM_PowerStatesE stateexited , BOOL b_DDR_ready , BOOL b_RegsRetainedState ) ;
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

typedef BOOL ( *DiagPSisRunningFn ) ( void ) ;
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

typedef UINT32 Earfcn ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 Bool bandIndicator ;	 
 UINT8 clientBitmap ;	 
 } GsmCell_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numCells ;	 
 UINT8 pad [ 3 ] ;	 
 GsmCell_ts cellInfo [ 32 ] ;	 
 } plwGsmCellInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 Bool bandIndicator ;	 
 UINT8 clientBitmap ;	 
 Bool bsicInfoExist ;	 
 UINT8 expectedBsic ;	 
 UINT8 pad [ 2 ] ;	 
 } GsmBsicCell_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numCells ;	 
 UINT8 pad [ 3 ] ;	 
 GsmBsicCell_ts cellInfo [ 32 ] ;	 
 } plwGsmBsicCellInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 UINT16 nCellBcchControl ; // 0 means stop the bsic / bcch decoding	 
 Bool bandIndicator ;	 
 UINT8 pad [ 3 ] ;	 
 } plwGsmMultiArfcnList_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfArfcns ;	 
 Bool reportList ;	 
 UINT8 pad [ 2 ] ;	 
 plwGsmMultiArfcnList_ts list [ 40 ] ;	 
 } plwGsmMultiBcchDecodeReq_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 Bool bandIndicator ;	 
 UINT8 rxLev ;	 
 UINT8 clientBitmap ;	 
 } gsmRssiInfo;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numCells ;	 
 UINT8 pad [ 3 ] ;	 
 gsmRssiInfo rssiInfo [ 32 ] ;	 
 } plwGsmRssiMeasInd_ts;

typedef UINT16 plwGsmBandMode_te ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 list [ 128 ] ;	 
 } plwGsmArfcnList_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 plwGsmArfcnList_ts arfcnList ;	 
 plwGsmBandMode_te bandMode ;	 
 } plwGsmRssiScanReq_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 INT16 rssi ;	 
 } 
 allCellsMeas_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numMeas ;	 
 UINT8 pad ;	 
 UINT16 numMeasInAllCells ;	 
 UINT16 arfcn [ 40 ] ;	 
 plwGsmBandMode_te bandMode ;	 
 UINT8 level [ 40 ] ;	 
 allCellsMeas_ts allCellsMeas [ 128 *8 ] ;	 
 } plwGsmRssiScanInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 bsic ;	 
 UINT16 arfcn ;	 
 Bool bandIndicator ;	 
 UINT8 clientBitmap ;	 
 } plwGsmBsicDecodeInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 Bool bandIndicator ;	 
 UINT8 pad ;	 
 UINT16 nCellBcchControl ; // if = 0 - means stop the bcch decoding	 
 } plwGsmBcchDecodeReq_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 Bool bandIndicator ;	 
 UINT8 pad ;	 
 } plwGsmArfcnInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfArfcns ;	 
 UINT8 pad [ 3 ] ;	 
 plwGsmArfcnInfo_ts arfcnList [ 40 ] ;	 
 } plwGsmMultiBcchDecodeInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Bool gsmScoreReq ; /**< GSM Scores Request. When TRUE , the RSSI Scan procedure report GSM RSSI on all requested frequencys. */	 
 Bool wbScoreReq ; /**< WB Scores Request. When TRUE , the RSSI Scan procedure report WB scores on all requested frequencys. */	 
 UINT8 lteScoreReq ; /**< lteScoreReq [ 0 ] - When TRUE , scanning of LTE with BW = 1.400000 MHz is required.	 
	 
 * If FALSE , scanning is not required. lteScoreReq [ 5 ] - When TRUE , scanning of LTE with BW = 20 MHz	 
 * is required. If FALSE , scanning is not required. */	 
 UINT8 bandNum ; /**< Band number , as defined 36.101000 .	 
 * In " List Mode " it is per frequency.	 
 * In " Range Mode " only first entry is used for the entire range. */	 
 UINT16 frequency ; /**< Frequency represented as 10 x Frequency in MHz. In " Range Mode " - first entry is the start	 
 * frequency in MHz and the second entry is the stop frequency in MHz. The start frequency represents	 
 * the first frequency for reporting its score in the narrowest scanned BW as requested by lteScoreReq	 
 * field. The stop frequency represents the first frequency for reporting it ' s score in the narrowest	 
 * scanned BW as requested by lteScoreReq field.	 
 * In " List Mode " - each entry represent the frequency in MHz to be search for */	 
 } plwPlmsRssiScanFreqList_ts;

//ICAT EXPORTED STRUCT 
 typedef enum 
 {	 
 PLW_PLMS_GSM_RAT_PLMS = 0 ,	 
 PLW_PLMS_UMTS_RAT ,	 
 PLW_PLMS_EUTRA_RAT ,	 
 } plwPlmsRssiScanRat_te_enum;

typedef UINT8 plwPlmsRssiScanRat_te ;
//ICAT EXPORTED STRUCT 
 typedef struct PlwLteResultsTableElementTag 
 {	 
 UINT16 lteBestScore ; /*Best Score of the Earfcn*/	 
 } PlwLteResultsTableElement_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 simId ;	 
 UINT8 reserved0 ;	 
 UINT8 reserved1 ;	 
 UINT8 reserved2 ;	 
 plwPlmsRssiScanRat_te rat ; /* indicate which RAT request the RssiScanReq */ /*CQ00071284 */	 
 Bool bgInd ; /*Indicates if the RSSI Scan is BG or FG operation.*/	 
 Bool listIndication ; /**< frequency list indication. When TRUE , the frequencys that are need to be scanned are in given by	 
 * the list in earfcnList field. When FALSE , the frequencys to be scanned are indicated by startfrq	 
 * and endfrq fields. */	 
 UINT8 pad1 ;	 
 UINT16 numOfFreqs ; /**< In " Range Mode " this number is always 2 .	 
 In " List Mode " the number represents the number of EARFCNs in the list. Maximum number of EARFCNs is 32 .*/	 
 plwPlmsRssiScanFreqList_ts freqList [ 32 ] ; /** < In " Range Mode " - first entry is the start frequency in MHz and the second	 
 * entry is the stop frequency in MHz. In " List Mode " - each entry represent the frequency in MHz to be search for*/	 
	 
 PlwLteResultsTableElement_ts *lteResult_p ; /**< Lte Pointer to the results in the shared memory */	 
 UINT16 *wbResult_p ; /**< WB Pointer to the results in the shared memory */	 
 UINT16 *gsmResult_p ; /**< GSM Pointer to the results in the shared memory */	 
 } plwPlmsRssiScanReq_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PLW_PLMS_RSSI_SCAN_CNF_NO_ERRORS = 0 ,	 
 PLW_PLMS_RSSI_SCAN_CNF_UL1_TIMER_EXPIRED ,	 
 PLW_PLMS_RSSI_SCAN_CNF_INVALID_REQUEST_PARAMS ,	 
 PLW_PLMS_RSSI_SCAN_CNF_INVALID_L1_CONFIGURATION ,	 
 PLW_PLMS_RSSI_SCAN_CNF_AUTO_ABORT_BY_HOST_L1 ,	 
 } plwRssiScanCnfCompleteStatus_te_enum;

typedef UINT8 plwRssiScanCnfCompleteStatus_te ;
//ICAT EXPORTED STRUCT 
 typedef UINT8 plwPlmsRssiScanAbortCnf_ts ; 
 
 // ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 // #if defined ( UPGRADE_DSDSWB )	 
 INT8 simId ;	 
 INT8 reserved0 ;	 
 INT8 reserved1 ;	 
 INT8 reserved2 ;	 
 // #endif	 
 plwRssiScanCnfCompleteStatus_te completeStatus ; /**< RSSI Scan completion status. When TRUE , the RSSI Scan completed successfully. When FASLE , the RSSI Scan failed */	 
 UINT16 numOfEarfcns ; /**< Number of reported EARFCNs. */	 
 UINT16 numOfUarfcns ; /**< Number of reported UARFCNs. */	 
 UINT16 numOfArfcns ; /**< Number of reported ARFCNs. */	 
 } plwPlmsRssiScanCnf_ts;

typedef Earfcn LteARFCN ;
typedef UINT8 IratGapOrderType_te ;
//ICAT EXPORTED ENUM 
 enum IratGapOrderType_values 
 {	 
 LTE_NCELL_BCH = 0x00 ,	 
 };

typedef UINT16 Lte_PhysicalCellIdentity ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Lte_PhysicalCellIdentity physicalCellIdentity ;	 
	 
 /** 1 dB steps from 0 ( -141dBm ) to 97 ( -44 dBm ) . */	 
 UINT16 rSRP ;	 
	 
 /** 1 / 2 dB steps from 0 ( -20dB ) to 34 ( -3 dB ) . */	 
 UINT16 rSRQ ;	 
 // Added by xqshi to align	 
 UINT8 padding [ 2 ] ;	 
 // Added end	 
 } 
 plwULteCellReport_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 LteARFCN earfcn ;	 
	 
 UINT16 numberOfCells ;	 
 // added by xqshi to 32 bit align	 
	 
 UINT8 padding [ 2 ] ;	 
 // Added by xqshi to 32 bit align end	 
	 
 plwULteCellReport_ts detectCellResult [ 4 ] ;	 
 } 
 plwULteFreqCellList_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /** Indicates if the physical layer has detected one or more cells on the	 
 * requested frequency.	 
 */	 
 Bool cellDetected ;	 
	 
 UINT8 numOfFrequencies ;	 
 // added by xqshi to 32 bit align	 
	 
 UINT8 padding [ 2 ] ;	 
 // Added by xqshi to 32 bit align	 
	 
	 
 plwULteFreqCellList_ts freqCellList [ 16 ] ;	 
 } 
 plwCphyDrxFindLteCellCnf_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 ScramblingCode ; /* Primary scrambling code */	 
 } EcphyUtranCellParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 Uarfcn ;	 
 UINT16 numPrimaryScramblingCodes ; /* Max 32 . If numOfCells is 0 , only RSSI will be reported for each frequency in uarfcnList */	 
 EcphyUtranCellParams_ts utraCellParams [ 32 ] ; /*LTE_MAX_FDD_UTRA_CELL_NUM is 32 */	 
 } EcphyUtranUarfcnParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 measSyncId ;	 
 UINT8 numOfUarfcn ; /* Number of frequencies in uarfcnList array. If numOfUarfcn is 0 , L1 will stop measurements reports */	 
 UINT8 highPriorityBitmap [ 2 ] ;	 
 EcphyUtranUarfcnParams_ts utraFddElement [ 16 ] ; /* LTE_MAX_FDD_UTRA_FREQ_NUM is 3 */	 
 } plwEwiMonitorFddUtraCellReq_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Earfcn earfcn ;	 
	 
 /* From RRC ASN definition: UEUTRA_MeasurementBandwidth	 
 * 0 - MeasurementBandwidth_mbw6 ,	 
 * 1 - MeasurementBandwidth_mbw15 ,	 
 * 2 - MeasurementBandwidth_mbw25 ,	 
 * 3 - MeasurementBandwidth_mbw50 ,	 
 * 4 - MeasurementBandwidth_mbw75 ,	 
 * 5 - MeasurementBandwidth_mbw100	 
 */	 
 UINT8 measBandwidth ;	 
 UINT8 pad [ 3 ] ;	 
 } LteFreq_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /** Indicates uniquely the identifier of this measurement request and is	 
 * only an internal reference used by RRC to tie up measurement requests	 
 * with measurement reports.	 
 * This is NOT the same as the measurement identity that is used on the	 
 * air interface.	 
 */	 
 UINT8 measurementIdentity ;	 
	 
 /** Indicates a bit mask to define the RSCP measurement required	 
 * for the corresponding freqs.	 
 */	 
 UINT8 Rsrp ;	 
 /** Indicates a bit mask to define the RSCQ measurement required	 
 * for the corresponding freqs.	 
 */	 
 UINT8 Rsrq ;	 
 /** high Priority or not for the freq in bitmask Rsrp||Rsrq */	 
 Bool isHighPrioLayers ;	 
 UINT8 numberOfFreqs ;	 
 UINT8 pad [ 3 ] ;	 
 LteFreq_ts lteFreq [ 8 ] ;	 
 } plwCphyMonitorLteCellReq_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 physicalCellIdentity ;	 
	 
 /** 1 dB steps from 0 ( -141dBm ) to 97 ( -44 dBm ) . */	 
 INT16 rSRP ;	 
	 
 /** 1 / 2 dB steps from 0 ( -20dB ) to 34 ( -3 dB ) . */	 
 INT16 rSRQ ;	 
 // added by xqshi to align	 
	 
 UINT8 padding [ 2 ] ;	 
 // Added by xqshi to align	 
 } 
 LteCellReport;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Earfcn earfcn ; // HTFENG_TBD	 
 Bool rSRPPresent ;	 
 Bool rSRQPresent ;	 
	 
 UINT16 numberOfCells ;	 
 // Modified by xqshi to align 32 bit	 
 // UINT8 pad [ 2 ] ;	 
 // modified end	 
 LteCellReport lteCellMeasdata [ 8 ] ;	 
 } LteFreqReport;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 measureIdentity ; // HTFENG_TBD	 
 UINT8 numberOfFreqs ;	 
 UINT8 pad [ 2 ] ;	 
	 
 LteFreqReport lteFreqReport [ 8 ] ;	 
 } plwCphyMonitorLteCellInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 Earfcn earfcn ;	 
 UINT16 numberOfCells ;	 
 // Added by xqshi to align	 
 UINT8 padding [ 2 ] ;	 
 // Added end	 
 LteCellReport lteCellMeasdata [ 8 ] ;	 
 } LteFreqResultReport;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 simID ;	 
 UINT8 numberOfFreqs ;	 
 UINT8 measType ;	 
 // Added by xqshi to align	 
 UINT8 padding ;	 
 // Added end	 
	 
 LteFreqResultReport LteFreqResultReport [ 8 ] ;	 
 } LteMeasPlmnResult_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 supportedRfBands ; // a bitmap of the supported RF bands	 
 UINT8 powerClass [ 16 ] ; // UE Power Class per Band	 
 UINT8 numOfBandCom ;	 
 UINT8 Reserved ;	 
 UINT8 bandComList [ 16 ] ;	 
 } l1WcdmaCapabilityReportInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 Bool bandIndicator ;	 
 UINT8 frame [ 23 ] ;	 
 UINT16 subChannel ;	 
 Bool crcCheckResult ;	 
	 
	 
	 
 } plwGsmBcchDecodeInd_ts;

typedef UINT8 GsmBcchDecodeErrCode_te ;
//ICAT EXPORTED ENUM 
 enum GsmBcchDecodeErrCode_values 
 {	 
 GSM_BCCH_DECODE_FAILED = 0x00 ,	 
 GSM_BCCH_SHORT_DRX_CYCLE = 0x01 ,	 
 GSM_BCCH_REACHED_MAX_TRIALS = 0x02	 
 };

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 Bool bandIndicator ;	 
 GsmBcchDecodeErrCode_te errorCode ;	 
 } plwGsmBcchDecodeErrorInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 ScramblingCode ; /* Primary scrambling code */	 
 sttdInd_te sttdInd ; /* STTD indicator TS: 25.331000 : 10.300000 .6.78 */	 
 } plgUtranCellParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 Uarfcn ;	 
 UINT16 numPrimaryScramblingCodes ; /* Max 32 . If numOfCells is 0 , only RSSI will be reported for each frequency in uarfcnList */	 
 plgUtranCellParams_ts utraCellParams [ 32 ] ; /*MAX_REQ_FDD_CELLS is 32 */	 
 } plgUtranUarfcnParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 measurementId ; /* Integer that will be reported with the measurement indication ( 0 255 ) */	 
 UINT8 numOfUarfcn ; /* Number of frequencies in uarfcnList array. If numOfUarfcn is 0 , L1 will stop measurements reports ( 0 3 ) */	 
 Bool fddCellsHavePriority ; /* Not supported */	 
 plgUtranUarfcnParams_ts utraFddElement [ 3 ] ; /* MAX_FDD_UARFCN is 3 */	 
 } plgUtranCellMeasReq_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 dlUarfcnIndex ; /* Index to uarfcnList entry representing the downlink UARFCN i.e. index to the fddRxLev array 0 ..2*/	 
 UINT16 scramblingCode ; /* Primary scrambling code */	 
 INT16 cpichEcNo ; /* In 1 / 8 dB units ( -320 0 ) */	 
 INT16 cpichRscp ; /* In 1 / 8 dBm units. ( -1336 0 ) */	 
 } plgUtranCellMeasIndParams_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 uarfcn ; // ( 0 16383 ) RF channel number	 
 INT16 rssiInd ; // ( -1016 0 ) In 1 / 8 dBm units	 
 } plgUtranRxLev_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 measurementId ; /* Integer that will be reported with the measurement indication. Zero is reserved for internal use. ( 0 255 ) */	 
 UINT8 numOfCells ; /* Number of cells in utraCellParams array. ( 0 64 ) */	 
 UINT8 numOfUarfcn ; /* Number of frequencies in uarfcnList array ( , 1 3 ) */	 
 plgUtranRxLev_ts fddRxLev [ 3 ] ; /* MAX_FDD_UARFCN is 3 , See ?4.3.21.2 */	 
 plgUtranCellMeasIndParams_ts fddCellMeas [ 64 ] ; /* MAX_MEAS_FDD_CELLS is 64 , See ?4.6.12.2 */	 
 } plgUtranCellMeasInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 numOfFreqs ;	 
 BYTE pad [ 3 ] ;	 
 plgUtranRxLev_ts freqList [ 32 ] ;	 
 } plgUtranRssiMeasInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 startStopInd ;	 
 UINT8 actionType ;	 
 UINT8 numOfFreqs ;	 
 UINT8 freqScanMode ;	 
 Bool runInFastMode ;	 
 UINT8 pad [ 3 ] ;	 
 UINT16 freqList [ 32 ] ;	 
 } plgUtranRssiScanReq_ts;

typedef plgUtranRssiScanReq_ts UmphRssiScanReq ;
typedef freqScanInd_ts plgUtranRssiScanInd_ts ;
typedef plgUtranRssiScanInd_ts UmphRssiScanInd ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 startStopInd ;	 
 UINT8 actionType ;	 
 UINT8 numOfFreqs ;	 
 UINT8 freqScanMode ;	 
 Bool runInFastMode ;	 
 UINT8 pad [ 3 ] ;	 
 UINT16 freqList [ 32 ] ;	 
 } plgUtranRssiMeasReq_ts;

typedef plgUtranRssiMeasReq_ts UmphRssiMeasReq ;
typedef plgUtranRssiMeasInd_ts UmphRssiMeasInd ;
typedef plgUtranCellMeasReq_ts UmphCellMeasReq ;
typedef plgUtranCellMeasInd_ts UmphCellMeasInd ;
typedef interFreqCellMeasInd_ts UmphDetectedCellMeasInd ;
typedef plDetectedCellMeas_ts UmphDetectedCellMeasReq ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 reason_stop =0 ,	 
 reason_start	 
 } ScanReqReason_te;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT8 bssid [ 6 ] ;	 
 UINT8 padding [ 2 ] ;	 
 INT32 rssi ;	 
 UINT32 channel_number ; //	 
 } channelCellInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef enum 
 {	 
 NULL_FAILURE =0 ,	 
 FAILURE_DUAL_SIM_CAMP =1 ,	 
 FAILURE_SERVICE_ONGOING =2 ,	 
 FAILURE_SERVICE_ONGOING_NOT_ENTER_IDLE =6 ,	 
 FAILURE_NOT_ENTER_IDLE =4 ,	 
 FAILURE_DSP_NOT_SUPPORT = 8 ,	 
 } wifi_failure_cause_te;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
	 
 UINT8 bssid_number ;	 
 channelCellInfo_ts channelCellList [ 30 ] ;	 
 ////// CQ00143839	 
	 
 wifi_failure_cause_te wifi_failure_cause ;	 
 UINT8 pad1 [ 3 ] ;	 
	 
 } WFScanInd_ts;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
	 
 UINT8 bssid_number ;	 
 channelCellInfo_ts channelCellList [ 30 ] ;	 
	 
 } WFScanIndPLP_ts;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
	 
 UINT8 bssid_number ;	 
 channelCellInfo_ts channelCellList [ 30 *3 ] ;	 
 // scanRestult_te scanRestult ;	 
 UINT32 WifiScanReportTime ;	 
 } WFScanIndBk_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 NULL_RAT =0 ,	 
 WCDMA_RAT ,	 
 TDSCDMA_RAT ,	 
 GSM_RAT ,	 
 LTE_RAT ,	 
 ALL_RAT ,	 
 NR_RAT // CQ00133130 add	 
 } initialRat_te;

//ICAT EXPORTED ENUM 
 typedef enum RatSetCauseTag 
 {	 
 RAT_CAUSE_NULL ,	 
 POWER_ON_ON_GSM ,	 
 POWER_ON_ON_TD ,	 
 DRAT_HO_TD_TO_GSM ,	 
 DRAT_HO_TD_TO_GSM_FAIL , // 4	 
 DRAT_HO_GSM_TO_TD ,	 
 DRAT_HO_GSM_TO_TD_FAIL ,	 
 DRAT_RESEL_GSM_TO_TD ,	 
 DRAT_RESEL_GSM_TO_TD_FAIL ,	 
 DRAT_CCO_TD_DCH_TO_GSM , // 9	 
 DRAT_CCO_TD_DCH_TO_GSM_FAIL ,	 
 DRAT_RESEL_TD_IDLE_TO_GSM ,	 
 DRAT_RESEL_TD_IDLE_TO_GSM_FAIL ,	 
 DRAT_RESEL_TD_FACH_TO_GSM ,	 
 DRAT_RESEL_TD_FACH_TO_GSM_FAIL , // 14	 
 DRAT_SWITCH_TD_TO_GSM ,	 
 DRAT_SWITCH_GSM_TO_TD ,	 
 PLMN_SEARCH_IN_TD_GSM_BCCH_DECODE ,	 
 PLMN_SEARCH_IN_TD_BACK_TO_TD ,	 
 PLMN_SEARCH_IN_GSM_TD_BCH_DECODE , // 19	 
 PLMN_SEARCH_IN_GSM_BACK_TO_GSM ,	 
 SWITCH_TO_TD_ATTER_GSM_TERMINATE ,	 
 DRAT_SET_FROM_GPLC ,	 
 POWER_ON_LTE , // 23	 
 /* CQ00019250 - Update IRAT feature - begin */	 
	 
 IRAT_HO_LTE_TO_TD , // 24	 
 IRAT_HO_LTE_TO_TD_FAIL ,	 
 IRAT_HO_TD_TO_LTE ,	 
 IRAT_HO_TD_TO_LTE_FAIL ,	 
	 
 IRAT_RESEL_LTE_TO_TD ,	 
 IRAT_RESEL_LTE_TO_TD_FAIL , // 29	 
 IRAT_RESEL_TD_TO_LTE ,	 
 IRAT_RESEL_TD_TO_LTE_FAIL ,	 
	 
 PLMN_SEARCH_IN_LTE_TD_BCCH_DECODE ,	 
 PLMN_SEARCH_IN_TD_LTE_BCCH_DECODE ,	 
	 
 DRAT_RESEL_GSM_TO_LTE , // 34	 
 DRAT_RESEL_GSM_TO_LTE_FAIL ,	 
	 
 DRAT_RESEL_LTE_TO_GSM ,	 
 DRAT_RESEL_LTE_TO_GSM_FAIL ,	 
	 
 PLMN_SEARCH_IN_TD_LTE_BACK_TO_TD ,	 
 PLMN_SEARCH_IN_GSM_LTE_BCCH_DECODE , // 39	 
 PLMN_SEARCH_IN_GSM_LTE_BACK_TO_GSM , // 4 40	 
 PLMN_SEARCH_IN_LTE_GSM_BCCH_DECODE ,	 
 PLMN_SEARCH_IN_LTE_GSM_BACK_TO_LTE ,	 
 PLMN_SEARCH_IN_LTE_TD_BACK_TO_LTE ,	 
	 
 /*Add by qhli begin*/	 
 IRAT_HO_LTE_TO_WB = 44 ,	 
 IRAT_HO_LTE_TO_WB_FAIL ,	 
 IRAT_HO_WB_TO_LTE ,	 
 IRAT_HO_WB_TO_LTE_FAIL ,	 
	 
 IRAT_RESEL_LTE_TO_WB , // 48	 
 IRAT_RESEL_LTE_TO_WB_FAIL ,	 
 IRAT_RESEL_WB_TO_LTE , // 4 50	 
 IRAT_RESEL_WB_TO_LTE_FAIL ,	 
 IRAT_REDIR_WB_TO_LTE_FAIL , // CQ65927 for WB Redir To Lte Fail issue	 
	 
 PLMN_SEARCH_IN_LTE_WB_BCCH_DECODE ,	 
 PLMN_SEARCH_IN_WB_LTE_BCCH_DECODE ,	 
 PLMN_SEARCH_IN_LTE_WB_BACK_TO_LTE ,	 
 PLMN_SEARCH_IN_WB_LTE_BACK_TO_WB ,	 
 /*Add by qhli end*/	 
	 
 // IRAT_RESEL_WB_TO_LTE ,	 
 // PLMN_SEARCH_IN_WB_LTE_BCCH_DECODE ,	 
 // PLMN_SEARCH_IN_WB_LTE_BACK_TO_WB ,	 
 // IRAT_RESEL_LTE_TO_WB_FAIL ,	 
	 
 /* CQ00019250 - Update IRAT feature - end */	 
	 
 // CQ00035825 , Add IRAT CGI cause , start	 
 IRAT_WB_CGI_IN_LTE ,	 
 IRAT_WB_CGI_BACK_TO_LTE ,	 
 IRAT_GSM_CGI_IN_LTE ,	 
 IRAT_GSM_CGI_BACK_TO_LTE , // 4 60	 
 IRAT_TD_CGI_IN_LTE ,	 
 IRAT_TD_CGI_BACK_TO_LTE ,	 
 // CQ00035825 , Add IRAT CGI cause , end	 
	 
 // CQ35801 w / g iRat Casue , start	 
 PLMN_SEARCH_IN_WB_GSM_BCCH_DECODE ,	 
 PLMN_SEARCH_IN_WB_GSM_BACK_TO_WB ,	 
 PLMN_SEARCH_IN_GSM_WB_BCCH_DECODE ,	 
 PLMN_SEARCH_IN_GSM_WB_BACK_TO_GSM ,	 
 IRAT_HO_WB_TO_GSM ,	 
 IRAT_HO_WB_TO_GSM_FAIL ,	 
 IRAT_HO_GSM_TO_WB ,	 
 IRAT_HO_GSM_TO_WB_FAIL , // 4 70	 
 IRAT_RESEL_GSM_TO_WB ,	 
 IRAT_RESEL_GSM_TO_WB_FAIL ,	 
 IRAT_RESEL_WB_TO_GSM ,	 
 IRAT_RESEL_WB_TO_GSM_FAIL ,	 
 IRAT_SWITCH_WB_TO_GSM ,	 
 IRAT_SWITCH_GSM_TO_WB ,	 
 // CQ35801 w / g iRat Casue , end	 
 POWER_ON_WB , // CQ42646 for CQ42639	 
 /*Modify for CQ00054259 by qhli begin*/	 
 IRAT_SWITCH_WB_TO_LTE ,	 
 IRAT_SWITCH_LTE_TO_WB ,	 
 /*Modify for CQ00054259 by qhli end*/	 
	 
 /* Add for LTE / GSM handover IRAT case */	 
 IRAT_HO_LTE_TO_GSM , // 4 80	 
 IRAT_HO_LTE_TO_GSM_FAIL ,	 
 IRAT_HO_GSM_TO_LTE ,	 
 IRAT_HO_GSM_TO_LTE_FAIL ,	 
	 
 LTE_IPC_RECEIVED_IN_NON_LTE_MODE ,	 
 LTE_CSFB_GSM , /*CQ00079576 add , value = 84 */	 
 GSM_PWROFF_TO_RESETMODE ,	 
 /*CQ00133130 start add*/	 
 RAT_CAUSE_RESERVED_2 ,	 
 RAT_CAUSE_RESERVED_1 ,	 
 RAT_CAUSE_RESERVED_0 ,	 
 // #if defined ( UPGRADE_NR ) // not add macro to adapt to all products.	 
 POWER_ON_NR = 90 , // 4 90	 
 // NR->LTE	 
 IRAT_RESEL_NR_TO_LTE , // common for resel / redirect	 
 IRAT_RESEL_NR_TO_LTE_FAIL , // common for resel / redirect	 
 IRAT_HO_NR_TO_LTE ,	 
 IRAT_HO_NR_TO_LTE_FAIL ,	 
 // LTE->NR fail	 
 IRAT_RESEL_LTE_TO_NR , // common for resel / redirect	 
 IRAT_RESEL_LTE_TO_NR_FAIL , // common for resel / redirect	 
 IRAT_HO_LTE_TO_NR ,	 
 IRAT_HO_LTE_TO_NR_FAIL ,	 
 // #endif	 
 /*CQ00133130 end add*/	 
	 
 // 3 NOTE: make sure enum value < 127 , because SetModeReq ( 0x8e ) ->modeSetCause only take 7 bits. ( 111 1111 = 127 )	 
	 
 RAT_CAUSE_MAX_NUM = 127 // RAT_CAUSE_NUM	 
 } RatSetCause;

//ICAT EXPORTED ENUM 
 typedef enum {	 
 GPLC_IN_STATE_INVALID = 0 ,	 
 GPLC_IN_STATE_IDLE ,	 
 GPLC_IN_STATE_IDLE_AFTER_PCH ,	 
 GPLC_IN_STATE_GPRS_PTM ,	 
 GPLC_IN_STATE_DEDICATED	 
 } GplcState_te;

//ICAT EXPORTED STRUCT 
 typedef struct pldGsmCellInfo_tsTag 
 {	 
 unsigned short wArfcn ;	 
 signed short iRssi ;	 
 unsigned long dwRssiAgeInMs ;	 
 signed short iFreqOffset ;	 
 unsigned short wQBitOffset ;	 
 unsigned long dwFrameOffset ;	 
 unsigned long dwBsicAgeInMs ;	 
 unsigned char ucCellStatus ;	 
 unsigned char ucBsic ;	 
 unsigned char pad [ 2 ] ;	 
 } pldGsmCellInfo_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 Bool bandIndicator ; /* ( GPLC define:TRUE == DCS 1800 ; FALSE == PCS 1900 ) */	 
 UINT8 bsic ;	 
 UINT16 nCellBcchControl ;	 
 } GsmBcchDecodeReqInTd_ts;

//ICAT EXPORTED STRUCT 
 typedef enum 
 {	 
 RSSI_NOT_ACTIVE ,	 
 RSSI_ACTIVE ,	 
 RSSI_SUSPEND ,	 
 RSSI_FINISH ,	 
 RSSI_STOP ,	 
 } RssiStateInIrat_te;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 numOfUarfcns ;	 
 UINT16 uarfcnList [ ( ( ( 1513 + 1 ) - 1162 ) + 0 ) ] ;	 
 INT16 rssi [ ( ( ( 1513 + 1 ) - 1162 ) + 0 ) ] ;	 
 } rssi_reply_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 MeasSyncId ;	 
 RssiStateInIrat_te RssiState ;	 
 UINT16 numOfUarfcns ;	 
 UINT16 currentUarfcnIndex ;	 
 UINT16 minFreqInBand ;	 
 UINT16 uarfcnList [ ( ( ( 1513 + 1 ) - 1162 ) + 0 ) ] ;	 
 INT16 rssi [ ( ( ( 1513 + 1 ) - 1162 ) + 0 ) ] ;	 
 UINT16 uarfcnScoreList [ ( ( ( 1513 + 1 ) - 1162 ) + 0 ) ] ;	 
 UINT32 endTs ; // valid only for RssiScanMeas	 
 } UtranRssiMeasParamInLte;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT8 CyclesBetweenBSS ;	 
 GplcState_te GplcState ;	 
 } plgGsmScenarioForCellMeas_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 arfcn ;	 
 UINT16 nCellBcchControl ;	 
 Bool bandIndicator ;	 
 // UINT8 pad [ 3 ] ;	 
 INT16 rssivalue ;	 
 } GsmBcchDecodeReqInWb_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 GsmBcchDecodeReqInWb_ts gsmBcchInfoArray [ 8 ] ;	 
 UINT8 NumOfBcchArfcn ;	 
 } GsmBcchDecodeReqDBInWb_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 time2Meas ;	 
 UINT8 numOfUarfcns ;	 
 BYTE pad [ 3 ] ;	 
 UINT16 UafcnList [ 10 ] ;	 
 } GsmRssiScanInWb_ts;

//ICAT EXPORTED STRUCT 
 typedef struct utranCellMeasIndPerSCTag 
 {	 
 UINT16 scramblingCode ; /* Primary scrambling code */	 
 INT16 cpichEcNo ; /* In 1 / 8 dB units ( -320 0 ) */	 
 INT16 cpichRscp ; /* In 1 / 8 dBm units ( -1336 0 ) */	 
 UINT16 pad ;	 
 } utranCellMeasIndPerSC;

//ICAT EXPORTED STRUCT 
 typedef struct UtranCellMeasIndPerUarfcnTag 
 {	 
 UINT16 uarfcn ;	 
 UINT8 numOfCells ; /* ( 0 32 ) */	 
 Bool lastIndicationFlag ; /* last indication in measurement cycle */	 
 INT16 rssiInd ; /* { -1016 - 0 } in [ 1 / 8 dBm ] units */	 
 utranCellMeasIndPerSC utranCellMeasInd [ 32 ] ;	 
 } UtranCellMeasIndPerUarfcn;

typedef void ( *plgMphDeactivateCnf_t ) ( UINT8 simId ) ;
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

typedef UINT8 CellularPowerAppState ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 CPA_NO_ACTIVE_RAT = 0 ,	 
 CPA_GSM_ACTIVE = 1 ,	 
 CPA_WCDMA_ACTIVE = 2 , CPA_TDSCDMA_ACTIVE=CPA_WCDMA_ACTIVE ,	 
 CPA_LTE_ACTIVE = 3 ,	 
 CPA_GSM_DRX = 4 ,	 
 CPA_WCDMA_DRX = 5 , CPA_TDSCDMA_DRX=CPA_WCDMA_DRX ,	 
 CPA_LTE_DRX = 6 ,	 
 CPA_GSM_OOS = 7 ,	 
 CPA_WCDMA_OOS = 8 , CPA_TDSCDMA_OOS=CPA_WCDMA_OOS ,	 
 CPA_LTE_OOS = 9 ,	 
 NUMBER_OF_CPA_STATES	 
 } CellularPowerAppStateEnum;

//ICAT EXPORTED FUNCTION - AAM , Apps , GetRegisteredApps 
 void GetRegisteredApps ( void ) 
 {	 
 AAM_HandleT appHandle ;	 
	 
 for ( appHandle = 0x0 ; appHandle < COMMPM_NUMBER_OF_CLIENTS ; appHandle++ )	 
 {		 
DIAG_FILTER ( PM , AAM , AppsInfo , DIAG_INFORMATION)  
 diagPrintf ( " Application numbers %d registeration value is %d " , appHandle , _aamGlobals.appsInfo [ appHandle ] .appRegistered );

		 
 }	 
 }

