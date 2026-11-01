//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\rm.ppp
//PPL Source File Name : X:\\hop\\rm\\src\\rm.c
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
//ICAT EXPORTED ENUM 
 typedef enum {	 
 COMMCCU_SYS_PLL_FREQ_52MHZ = 0 ,	 
 COMMCCU_SYS_PLL_FREQ_104MHZ ,	 
 COMMCCU_SYS_PLL_FREQ_156MHZ ,	 
 COMMCCU_SYS_PLL_FREQ_208MHZ ,	 
 COMMCCU_SYS_PLL_FREQ_312MHZ ,	 
 COMMCCU_SYS_PLL_NUM_OF_FREQS	 
 } CommCCU_SystemPLLFreqE;

typedef UINT32 CPMU_State ;
typedef void ( *CPMUL2PowerChangeNotifyFn ) ( void ) ;
typedef void ( *CPMUPMICCOmmandSetNotifyFn ) ( void ) ;
typedef void ( *CPMUFrequencyChangeNotifyFn ) ( void ) ;
typedef UINT32 CPMU_EventStatus ;
typedef UINT32 CPMU_L2Status ;
typedef UINT32 CPMU_WakeupEventCombination ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // APB Application Subsystem	 
 RM_SRVC_UART0 ,	 
 RM_SRVC_UART1 ,	 
 RM_SRVC_GPIO ,	 
 RM_SRVC_PWM0 ,	 
 RM_SRVC_PWM1 ,	 
 RM_SRVC_PWM2 ,	 
 RM_SRVC_PWM3 ,	 
 RM_SRVC_SSP0 ,	 
 RM_SRVC_SSP1 ,	 
 RM_SRVC_ACIPC ,	 
 RM_SRVC_RTC ,	 
 RM_SRVC_TWSI_HS ,	 
 RM_SRVC_KPC ,	 
 RM_SRVC_TIMERS_AS ,	 
 RM_SRVC_TB_ROTARY ,	 
 RM_SRVC_AIB ,	 
 RM_SRVC_SW_JTAG ,	 
 RM_SRVC_TIMERS1_AS ,	 
 RM_SRVC_ONEWIRE ,	 
 RM_SRVC_SSP2 ,	 
	 
 // APB Communication Subsystem	 
 RM_SRVC_TCU ,	 
 RM_SRVC_AIRQ ,	 
 RM_SRVC_UART2 , // Seagull	 
 RM_SRVC_USIM1 ,	 
 RM_SRVC_USIM2 ,	 
 RM_SRVC_TWSI ,	 
 RM_SRVC_ECIPHER ,	 
 RM_SRVC_TIMER_CS ,	 
 RM_SRVC_GSSP ,	 
 RM_SRVC_IPC ,	 
	 
 // Main PMU	 
 RM_SRVC_WDTPCR ,	 
	 
 // Application Subsystem PMU	 
 RM_SRVC_IRE ,	 
 RM_SRVC_LCD ,	 
 RM_SRVC_CCIC ,	 
 RM_SRVC_SDH0 ,	 
 RM_SRVC_SDH1 ,	 
 RM_SRVC_USB ,	 
 RM_SRVC_NF ,	 
 RM_SRVC_DMA ,	 
 RM_SRVC_GEU ,	 
 RM_SRVC_DTC ,	 
 RM_SRVC_GC ,	 
 RM_SRVC_SMC ,	 
 RM_SRVC_RTU ,	 
	 
 RM_NUM_OF_SRVCS ,	 
 RM_INVALID_SRVCS = RM_NUM_OF_SRVCS ,	 
 RM_SRVC_VCTCXO = RM_INVALID_SRVCS ,	 
 RM_SRVC_TIMER0_13M = RM_INVALID_SRVCS ,	 
 RM_SRVC_TIMER2_13M_GB = RM_INVALID_SRVCS ,	 
 RM_SRVC_DDR_HIGH_FREQ = RM_INVALID_SRVCS	 
	 
 } RM_ServiceIdE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 RM_CALLBACK_SRVC_INTC = 0 , /* MUST BE FIRST - it saves data while request are	 
 done , thus if request to enable / disable interrupt	 
 will come from onother source ( on there exit routine )	 
 the data to restore interrup controler will be ruined */	 
 RM_CALLBACK_SRVC_TIMER , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_SSP , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_DMA ,	 
 RM_CALLBACK_SRVC_I2C , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_WDT , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_IPC ,	 
 RM_CALLBACK_SRVC_USIM , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_PMIC , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_MSL , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_SCK , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_WB_SLEEP_MODULE , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_LTE_SLEEP_MODULE ,	 
 RM_CALLBACK_SRVC_WB_LTE_SLEEP_MODULE ,	 
 RM_CALLBACK_SRVC_TCU ,	 
 RM_CALLBACK_SRVC_UART ,	 
 RM_CALLBACK_SRVC_HSI ,	 
 RM_CALLBACK_SRVC_AC_IPC , /* Apps-Comm IPC service wakeup */ // YKYK TODO	 
 RM_CALLBACK_SRVC_CGPIO , /** This service may register for wakeup **/	 
 RM_NUM_OF_CALLBACK_SRVCS ,	 
 RM_INVALID_CALLBACK = RM_NUM_OF_CALLBACK_SRVCS	 
	 
 } RM_ServiceCallbackE;

typedef UINT32 RM_CurrentResourcesStatusT ;
typedef RM_CurrentResourcesStatusT RM_ResourcesArrT [ 32 ] ;
typedef void ( *RM_CallbackFuncT ) ( void ) ;
typedef void ( *RM_D2RecoverCallbackFuncT ) ( PM_PowerStatesE psType ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 MULTI_USER_CLK_DSSP_BUS=0 ,	 
 MULTI_USER_CLK_VCTCXO ,	 
 MULTI_USER_CLK_MODEM_78MHZ ,	 
 MULTI_USER_CLK_MODEM_104MHZ ,	 
 MULTI_USER_CLK_DDR_HIGH_FREQ , // rafiagiv - 21 / 12	 
 NUMBER_OF_MULTI_USER_CLOCKS ,	 
 NO_MULTI_USER_CLOCK = -1	 
 } RM_MultiUserClocksE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 d2CbkPrepare ;	 
 UINT32 d2CbkRecover ;	 
 RM_ServiceCallbackE cbkevent ;	 
 } RM_PrepareRecoverEventsS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 cbkWakeup ;	 
 RM_ServiceCallbackE cbkevent ;	 
 } RM_WakeUpEventsS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 RM_PrepareRecoverEventsS RM_PrepareRecoverEventsEArray [ RM_NUM_OF_CALLBACK_SRVCS ] ;	 
 } RM_EventsArrayRecPreS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 RM_WakeUpEventsS RM_WakeUpEventsArray [ RM_NUM_OF_CALLBACK_SRVCS ] ;	 
 } RM_EventsArrayWakeupS;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_RC_OK = 0 ,	 
 PRM_RC_FAIL , // MB _ Added General Fail	 
 PRM_RC_RESET_NOT_SUPPORTED ,	 
 PRM_RC_ERR_CLOCK = -100 ,	 
 PRM_RC_ERR_FREQ ,	 
 PRM_RC_ERR_NULL_POINTER ,	 
 PRM_RC_WAKEUP_NOT_SUPPORTED ,	 
 PRM_RC_SERVICE_NOT_SUPPORTED ,	 
 PRM_RC_ERR_CPMU // MB - Arbel Specific on reset on CPMU	 
 } PRM_ReturnCodeE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_SRVC_DMA ,	 
 PRM_SRVC_DVFM ,	 
 PRM_SRVC_DSSP0_GB ,	 
 PRM_SRVC_DSSP1_GB ,	 
 PRM_SRVC_DSSP2_GB ,	 
 PRM_SRVC_I2C ,	 
 PRM_SRVC_MSL ,	 
 PRM_SRVC_RTC ,	 
 PRM_SRVC_SSP1 ,	 
 PRM_SRVC_SSP2 ,	 
 PRM_SRVC_SSP3 ,	 
 PRM_SRVC_TIMER0_13M ,	 
 PRM_SRVC_TIMER1_13M ,	 
 PRM_SRVC_TIMER2_13M_GB ,	 
 PRM_SRVC_TIMER3_13M_GB ,	 
 PRM_SRVC_VCTCXO ,	 
 PRM_SRVC_UART1 ,	 
 PRM_SRVC_USIM ,	 
 PRM_SRVC_WB_CIPHER_GB , // DTC	 
 PRM_SRVC_USIM2 ,	 
 /*should be deleted for wujing */	 
 PRM_SRVC_CPA_DDR_HPerf , // Seagull - DDR Request from Harbell ( calls PRM_SRVC_MC_DDR_HPerf if needed )	 
 PRM_SRVC_AIRQ , // Seagull	 
 PRM_SRVC_COMM_IPC , // Seagull	 
 PRM_SRVC_RESOURCE_IPC , // Seagull	 
 PRM_SRVC_AXI_CFG , // Seagull	 
 PRM_SRVC_ETB , // Seagull	 
 PRM_SRVC_DTC , // Seagull	 
 PRM_SRVC_TCU_CTRL , // Seagull	 
 PRM_SRVC_ABP_BUS , // Seagull	 
 PRM_SRVC_AXI_BUS , // Seagull	 
 PRM_LAST_SERVICE=PRM_SRVC_AXI_BUS , // Always update this field.	 
 PRM_NUM_OF_SRVCS ,	 
 PRM_SRVC_NOT_AVAILABLE ,	 
 PRM_SRVC_MC_DDR_HPerf = PRM_SRVC_NOT_AVAILABLE	 
	 
 } PRM_ServiceE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_WU_SRVC_TIMER , // Harbell , BRN ( relevant for RTOS )	 
 PRM_WU_SRVC_SSP , // Harbell	 
 PRM_WU_SRVC_SCK , // Harbell	 
 PRM_WU_SRVC_WB_SLEEP_MODULE , // Harbell	 
 PRM_WU_SRVC_TD_SLEEP_MODULE = PRM_WU_SRVC_WB_SLEEP_MODULE ,	 
 PRM_WU_SRVC_LTE_SLEEP_MODULE , // Harbell	 
 PRM_WU_SRVC_TD_LTE_SLEEP_MODULE ,	 
 PRM_WU_SRVC_TCU , // Harbell	 
 PRM_WU_SRVC_UART , // Harbell , ( BRN via GPIO ( relevant for RTOS ) )	 
 PRM_WU_SRVC_AC_IPC , // Harbell , BRN ( relevant for RTOS )	 
 PRM_WU_SRVC_RTC , // BRN	 
 PRM_WU_SRVC_ROTARY , // BRN	 
 PRM_WU_SRVC_USB20_CLIENT , // BRN - Do we need to USB events or not?	 
 PRM_WU_SRVC_USB_OTGP2 , // BRN - Tx , P2 , P3 ( 3 diferent wakeups )	 
 PRM_WU_SRVC_USB_OTGP3 , // BRN - Tx , P2 , P3 ( 3 diferent wakeups )	 
 PRM_WU_SRVC_KEYPAD , // BRN	 
 PRM_WU_SRVC_USIM , // BRN	 
 PRM_WU_SRVC_USB_OTGTX , // BRN - Tx , P2 , P3 ( 3 diferent wakeups )	 
 PRM_WU_SRVC_GPIO , // BRN ( relevant for RTOS )	 
 PRM_WU_SRVC_COMM_WDT , // BRN	 
 PRM_WU_SRVC_AC97 , // BRN ored with BSSP wakeup	 
 PRM_WU_SRVC_CI2C , // BRN	 
 PRM_WU_SRVC_MMC1 , // BRN	 
 PRM_WU_SRVC_SDIO1 , // BRN	 
 PRM_WU_SRVC_MMC2 , // BRN	 
 PRM_WU_SRVC_SDIO2 , // BRN	 
 PRM_WU_SRVC_NAND , // BRN	 
 PRM_WU_SRVC_PMIC , // BRN ( relevant for RTOS )	 
 PRM_WU_BTUART , // BRN	 
 PRM_WU_STUART , // BRN	 
 PRM_WU_SRVC_ICP , // BRN - In A0 is ored with UARTs wakeup	 
 PRM_WU_SRVC_KEYPAD_ROTARY , // BRN	 
 PRM_WU_SRVC_KEYPAD_DIRECT_KEYS , // BRN	 
 PRM_WU_SRVC_EXTERNAL_EVENT0 , // BRN - Special case - Driver not defined	 
 PRM_WU_SRVC_EXTERNAL_EVENT1 , // BRN - Special case - Driver not defined	 
 PRM_WU_SRVC_BSSP1 , // BRN	 
 PRM_WU_SRVC_BSSP2 , // BRN	 
 PRM_WU_SRVC_BSSP3 , // BRN	 
 PRM_WU_SRVC_BSSP4 , // BRN	 
	 
 PRM_NUM_OF_WU_SRVCS ,	 
 PRM_ORED_INT_MSL0 , // For BRM B0	 
 PRM_WU_INVALID_RSRC	 
 } PRM_WU_ServiceE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_NONRETAINED_SRVC_INTC = 0 , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_TIMER , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_SSP , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_DMA , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_I2C , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_WDT , // Harbell , BRN ( ? )	 
 PRM_NONRETAINED_SRVC_IPC , // Harbell	 
 PRM_NONRETAINED_SRVC_USIM , // Harbell	 
 PRM_NONRETAINED_SRVC_PMIC , // Harbell	 
 PRM_NONRETAINED_SRVC_MSL , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_SCK , // Harbell	 
 PRM_NONRETAINED_SRVC_WB_SLEEP_MODULE , // Harbell	 
 PRM_NONRETAINED_SRVC_LTE_SLEEP_MODULE , // Harbell	 
 PRM_NONRETAINED_SRVC_TD_LTE_SLEEP_MODULE , // Harbell	 
 PRM_NONRETAINED_SRVC_TCU , // Harbell	 
 PRM_NONRETAINED_SRVC_UART , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_HSI ,	 
 PRM_NONRETAINED_SRVC_GPIO , // BRN	 
 PRM_NONRETAINED_SRVC_USB20 , // BRN	 
 PRM_NONRETAINED_SRVC_UDC , // BRN	 
 PRM_NONRETAINED_SRVC_LCD , // BRN	 
 PRM_NONRETAINED_SRVC_DTC , // Seagull	 
 PRM_NONRETAINED_SRVC_PMNC , // Seagull	 
	 
 PRM_NUM_OF_NONRETAINED_SRVCS ,	 
 PRM_INVALID_NONRETAINED	 
	 
	 
 } PRM_NRS_ServiceE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_FREQ_13MHZ = 0 ,	 
 PRM_FREQ_26MHZ ,	 
 PRM_FREQ_52MHZ ,	 
 PRM_FREQ_78MHZ ,	 
 PRM_FREQ_89_1MHZ ,	 
 PRM_FREQ_104MHZ ,	 
 PRM_FREQ_124_8MHZ ,	 
 PRM_FREQ_156MHZ ,	 
 PRM_FREQ_208MHZ ,	 
 PRM_FREQ_260MHZ ,	 
 PRM_FREQ_312MHZ ,	 
 PRM_NUM_OF_FREQS ,	 
 PRM_INVALID_FREQ	 
 } PRM_ServiceFreqE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_RSRC_FREE=0 ,	 
 PRM_RSRC_ALLOC	 
	 
 } PRM_AllocFreeE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_RSRC_SC_FREE=1 , // resource is free , single client handling	 
 PRM_RSRC_SC_BUSY , // resource is busy , single client handling	 
 PRM_RSRC_MC_FREE , // resource is free , multi client handling	 
 PRM_RSRC_MC_BUSY , // resource is busy , multi client handling	 
 PRM_RSRC_NOT_DEFINED // resource is not defined	 
 // in this plat / sub-system	 
 } PRM_resourceStatusE;

typedef void ( *PRM_CallbackFuncWakeupT ) ( PM_PowerStatesE sleepstate , PM_PowerStatesE WUState , BOOL b_DDR_ready , BOOL b_RegsRetainedState ) ;
typedef void ( *PRM_CallbackFuncPrepareT ) ( PM_PowerStatesE statetoprepare ) ;
typedef void ( *PRM_CallbackFuncRecoverT ) ( PM_PowerStatesE stateexited , BOOL b_DDR_ready , BOOL b_RegsRetainedState ) ;
typedef void ( *PRM_CallbackFuncBeforeIntT ) ( void ) ;
typedef void ( *clk_onoff_func ) ( CLK_OnOff ) ;
//ICAT EXPORTED FUNCTION - PM , RM , dumpRMCount 
 void dumpRMCount ( void ) 
 {	 
 int i ;	 
 for ( i= 0 ; i < RM_NUM_OF_SRVCS ; i++ )	 
 {		 
DIAG_FILTER ( PM , RM , dumpRMCount_1 , DIAG_INFORMATION)  
 diagPrintf ( " RM Service [ %d ] : %d " , i , ServiceIdCount [ i ] );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - PM , PRM , RMEventsGet 
 void RMEventsGet ( void ) 
 {	 
 RM_EventsArrayRecPreS RM_EventsArrayRecPre ;	 
 RM_EventsArrayWakeupS RM_EventsArrayWakeup ;	 
 UINT32 i ;	 
	 
 // going over all structs to get current status , if callback is registerd or not	 
 for ( i=0 ; i<RM_NUM_OF_CALLBACK_SRVCS ; i++ )	 
 {		 
 if ( _rmVars.d2CbkPrepare [ i ] == 0 )		 
 RM_EventsArrayRecPre.RM_PrepareRecoverEventsEArray [ i ] .d2CbkPrepare = 0 ;		 
 else RM_EventsArrayRecPre.RM_PrepareRecoverEventsEArray [ i ] .d2CbkPrepare = 1 ;		 
		 
 if ( _rmVars.d2CbkRecover [ i ] == 0 )		 
 RM_EventsArrayRecPre.RM_PrepareRecoverEventsEArray [ i ] .d2CbkRecover = 0 ;		 
 else RM_EventsArrayRecPre.RM_PrepareRecoverEventsEArray [ i ] .d2CbkRecover = 1 ;		 
		 
 RM_EventsArrayRecPre.RM_PrepareRecoverEventsEArray [ i ] .cbkevent = ( RM_ServiceCallbackE ) i ;		 
		 
 if ( _rmVars.cbkWakeup [ i ] == 0 )		 
 RM_EventsArrayWakeup.RM_WakeUpEventsArray [ i ] .cbkWakeup = 0 ;		 
 else RM_EventsArrayWakeup.RM_WakeUpEventsArray [ i ] .cbkWakeup = 1 ;		 
		 
 RM_EventsArrayWakeup.RM_WakeUpEventsArray [ i ] .cbkevent = ( RM_ServiceCallbackE ) i ;		 
 }	 
	 
	 
DIAG_FILTER ( PM , PRM , RM_EVENTS_GET1 , DIAG_INFORMATION)  
 diagStructPrintf ( " RM EVENTS - %S { RM_EventsArrayWakeupS } " , & ( RM_EventsArrayWakeup ) , sizeof ( RM_EventsArrayWakeupS ) );

	 
DIAG_FILTER ( PM , PRM , RM_EVENTS_GET2 , DIAG_INFORMATION)  
 diagStructPrintf ( " RM EVENTS - %S { RM_EventsArrayRecPreS } " , & ( RM_EventsArrayRecPre ) , sizeof ( RM_EventsArrayRecPreS ) );

	 
	 
	 
DIAG_FILTER ( PM , PRM , RM_EVENTS_GET3 , DIAG_INFORMATION)  
 diagPrintf ( " Events IGNORE at init 0x%lx , Events ignore now 0x%lx , Event on 0x%lx " , 
 ( ( 0x1 << 14 ) | ( 0x1 << 2 ) | ( 0x1 << 3 ) | ( 0x1 << 12 ) ) , 
 RmIgnoreRsrcsRequests , 
 _rmVars.currentResourcesStatus );

	 
	 
	 
	 
 return ;	 
 }

//ICAT EXPORTED FUNCTION - PM , PRM , EnableGPBclose 
 void EnableGPBbusclose ( void ) 
 {	 
 iBlockGPBclose = 1 ;	 
DIAGM_TRACE( PM , PRM , EnableGPBclose , " Enabling to close GPB bus when required " );  
	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\rm_memRetain.ppp
//PPL Source File Name : X:\\hop\\rm\\src\\rm_memRetain.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PM_RC_OK = 0 ,	 
 PM_RC_FAIL , // General Failure	 
 PM_RC_ALREADY_EXISTS // Exit function since required target alrteady exists	 
 } PM_ReturnCodeE;

typedef void ( *PM_CallbackFuncDDRstateT ) ( BOOL b_DDR_ready ) ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // APB Application Subsystem	 
 RM_SRVC_UART0 ,	 
 RM_SRVC_UART1 ,	 
 RM_SRVC_GPIO ,	 
 RM_SRVC_PWM0 ,	 
 RM_SRVC_PWM1 ,	 
 RM_SRVC_PWM2 ,	 
 RM_SRVC_PWM3 ,	 
 RM_SRVC_SSP0 ,	 
 RM_SRVC_SSP1 ,	 
 RM_SRVC_ACIPC ,	 
 RM_SRVC_RTC ,	 
 RM_SRVC_TWSI_HS ,	 
 RM_SRVC_KPC ,	 
 RM_SRVC_TIMERS_AS ,	 
 RM_SRVC_TB_ROTARY ,	 
 RM_SRVC_AIB ,	 
 RM_SRVC_SW_JTAG ,	 
 RM_SRVC_TIMERS1_AS ,	 
 RM_SRVC_ONEWIRE ,	 
 RM_SRVC_SSP2 ,	 
	 
 // APB Communication Subsystem	 
 RM_SRVC_TCU ,	 
 RM_SRVC_AIRQ ,	 
 RM_SRVC_UART2 , // Seagull	 
 RM_SRVC_USIM1 ,	 
 RM_SRVC_USIM2 ,	 
 RM_SRVC_TWSI ,	 
 RM_SRVC_ECIPHER ,	 
 RM_SRVC_TIMER_CS ,	 
 RM_SRVC_GSSP ,	 
 RM_SRVC_IPC ,	 
	 
 // Main PMU	 
 RM_SRVC_WDTPCR ,	 
	 
 // Application Subsystem PMU	 
 RM_SRVC_IRE ,	 
 RM_SRVC_LCD ,	 
 RM_SRVC_CCIC ,	 
 RM_SRVC_SDH0 ,	 
 RM_SRVC_SDH1 ,	 
 RM_SRVC_USB ,	 
 RM_SRVC_NF ,	 
 RM_SRVC_DMA ,	 
 RM_SRVC_GEU ,	 
 RM_SRVC_DTC ,	 
 RM_SRVC_GC ,	 
 RM_SRVC_SMC ,	 
 RM_SRVC_RTU ,	 
	 
 RM_NUM_OF_SRVCS ,	 
 RM_INVALID_SRVCS = RM_NUM_OF_SRVCS ,	 
 RM_SRVC_VCTCXO = RM_INVALID_SRVCS ,	 
 RM_SRVC_TIMER0_13M = RM_INVALID_SRVCS ,	 
 RM_SRVC_TIMER2_13M_GB = RM_INVALID_SRVCS ,	 
 RM_SRVC_DDR_HIGH_FREQ = RM_INVALID_SRVCS	 
	 
 } RM_ServiceIdE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 RM_CALLBACK_SRVC_INTC = 0 , /* MUST BE FIRST - it saves data while request are	 
 done , thus if request to enable / disable interrupt	 
 will come from onother source ( on there exit routine )	 
 the data to restore interrup controler will be ruined */	 
 RM_CALLBACK_SRVC_TIMER , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_SSP , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_DMA ,	 
 RM_CALLBACK_SRVC_I2C , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_WDT , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_IPC ,	 
 RM_CALLBACK_SRVC_USIM , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_PMIC , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_MSL , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_SCK , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_WB_SLEEP_MODULE , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_LTE_SLEEP_MODULE ,	 
 RM_CALLBACK_SRVC_WB_LTE_SLEEP_MODULE ,	 
 RM_CALLBACK_SRVC_TCU ,	 
 RM_CALLBACK_SRVC_UART ,	 
 RM_CALLBACK_SRVC_HSI ,	 
 RM_CALLBACK_SRVC_AC_IPC , /* Apps-Comm IPC service wakeup */ // YKYK TODO	 
 RM_CALLBACK_SRVC_CGPIO , /** This service may register for wakeup **/	 
 RM_NUM_OF_CALLBACK_SRVCS ,	 
 RM_INVALID_CALLBACK = RM_NUM_OF_CALLBACK_SRVCS	 
	 
 } RM_ServiceCallbackE;

typedef UINT32 RM_CurrentResourcesStatusT ;
typedef RM_CurrentResourcesStatusT RM_ResourcesArrT [ 32 ] ;
typedef void ( *RM_CallbackFuncT ) ( void ) ;
typedef void ( *RM_D2RecoverCallbackFuncT ) ( PM_PowerStatesE psType ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_RC_OK = 0 ,	 
 PRM_RC_FAIL , // MB _ Added General Fail	 
 PRM_RC_RESET_NOT_SUPPORTED ,	 
 PRM_RC_ERR_CLOCK = -100 ,	 
 PRM_RC_ERR_FREQ ,	 
 PRM_RC_ERR_NULL_POINTER ,	 
 PRM_RC_WAKEUP_NOT_SUPPORTED ,	 
 PRM_RC_SERVICE_NOT_SUPPORTED ,	 
 PRM_RC_ERR_CPMU // MB - Arbel Specific on reset on CPMU	 
 } PRM_ReturnCodeE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_SRVC_DMA ,	 
 PRM_SRVC_DVFM ,	 
 PRM_SRVC_DSSP0_GB ,	 
 PRM_SRVC_DSSP1_GB ,	 
 PRM_SRVC_DSSP2_GB ,	 
 PRM_SRVC_I2C ,	 
 PRM_SRVC_MSL ,	 
 PRM_SRVC_RTC ,	 
 PRM_SRVC_SSP1 ,	 
 PRM_SRVC_SSP2 ,	 
 PRM_SRVC_SSP3 ,	 
 PRM_SRVC_TIMER0_13M ,	 
 PRM_SRVC_TIMER1_13M ,	 
 PRM_SRVC_TIMER2_13M_GB ,	 
 PRM_SRVC_TIMER3_13M_GB ,	 
 PRM_SRVC_VCTCXO ,	 
 PRM_SRVC_UART1 ,	 
 PRM_SRVC_USIM ,	 
 PRM_SRVC_WB_CIPHER_GB , // DTC	 
 PRM_SRVC_USIM2 ,	 
 /*should be deleted for wujing */	 
 PRM_SRVC_CPA_DDR_HPerf , // Seagull - DDR Request from Harbell ( calls PRM_SRVC_MC_DDR_HPerf if needed )	 
 PRM_SRVC_AIRQ , // Seagull	 
 PRM_SRVC_COMM_IPC , // Seagull	 
 PRM_SRVC_RESOURCE_IPC , // Seagull	 
 PRM_SRVC_AXI_CFG , // Seagull	 
 PRM_SRVC_ETB , // Seagull	 
 PRM_SRVC_DTC , // Seagull	 
 PRM_SRVC_TCU_CTRL , // Seagull	 
 PRM_SRVC_ABP_BUS , // Seagull	 
 PRM_SRVC_AXI_BUS , // Seagull	 
 PRM_LAST_SERVICE=PRM_SRVC_AXI_BUS , // Always update this field.	 
 PRM_NUM_OF_SRVCS ,	 
 PRM_SRVC_NOT_AVAILABLE ,	 
 PRM_SRVC_MC_DDR_HPerf = PRM_SRVC_NOT_AVAILABLE	 
	 
 } PRM_ServiceE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_WU_SRVC_TIMER , // Harbell , BRN ( relevant for RTOS )	 
 PRM_WU_SRVC_SSP , // Harbell	 
 PRM_WU_SRVC_SCK , // Harbell	 
 PRM_WU_SRVC_WB_SLEEP_MODULE , // Harbell	 
 PRM_WU_SRVC_TD_SLEEP_MODULE = PRM_WU_SRVC_WB_SLEEP_MODULE ,	 
 PRM_WU_SRVC_LTE_SLEEP_MODULE , // Harbell	 
 PRM_WU_SRVC_TD_LTE_SLEEP_MODULE ,	 
 PRM_WU_SRVC_TCU , // Harbell	 
 PRM_WU_SRVC_UART , // Harbell , ( BRN via GPIO ( relevant for RTOS ) )	 
 PRM_WU_SRVC_AC_IPC , // Harbell , BRN ( relevant for RTOS )	 
 PRM_WU_SRVC_RTC , // BRN	 
 PRM_WU_SRVC_ROTARY , // BRN	 
 PRM_WU_SRVC_USB20_CLIENT , // BRN - Do we need to USB events or not?	 
 PRM_WU_SRVC_USB_OTGP2 , // BRN - Tx , P2 , P3 ( 3 diferent wakeups )	 
 PRM_WU_SRVC_USB_OTGP3 , // BRN - Tx , P2 , P3 ( 3 diferent wakeups )	 
 PRM_WU_SRVC_KEYPAD , // BRN	 
 PRM_WU_SRVC_USIM , // BRN	 
 PRM_WU_SRVC_USB_OTGTX , // BRN - Tx , P2 , P3 ( 3 diferent wakeups )	 
 PRM_WU_SRVC_GPIO , // BRN ( relevant for RTOS )	 
 PRM_WU_SRVC_COMM_WDT , // BRN	 
 PRM_WU_SRVC_AC97 , // BRN ored with BSSP wakeup	 
 PRM_WU_SRVC_CI2C , // BRN	 
 PRM_WU_SRVC_MMC1 , // BRN	 
 PRM_WU_SRVC_SDIO1 , // BRN	 
 PRM_WU_SRVC_MMC2 , // BRN	 
 PRM_WU_SRVC_SDIO2 , // BRN	 
 PRM_WU_SRVC_NAND , // BRN	 
 PRM_WU_SRVC_PMIC , // BRN ( relevant for RTOS )	 
 PRM_WU_BTUART , // BRN	 
 PRM_WU_STUART , // BRN	 
 PRM_WU_SRVC_ICP , // BRN - In A0 is ored with UARTs wakeup	 
 PRM_WU_SRVC_KEYPAD_ROTARY , // BRN	 
 PRM_WU_SRVC_KEYPAD_DIRECT_KEYS , // BRN	 
 PRM_WU_SRVC_EXTERNAL_EVENT0 , // BRN - Special case - Driver not defined	 
 PRM_WU_SRVC_EXTERNAL_EVENT1 , // BRN - Special case - Driver not defined	 
 PRM_WU_SRVC_BSSP1 , // BRN	 
 PRM_WU_SRVC_BSSP2 , // BRN	 
 PRM_WU_SRVC_BSSP3 , // BRN	 
 PRM_WU_SRVC_BSSP4 , // BRN	 
	 
 PRM_NUM_OF_WU_SRVCS ,	 
 PRM_ORED_INT_MSL0 , // For BRM B0	 
 PRM_WU_INVALID_RSRC	 
 } PRM_WU_ServiceE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_NONRETAINED_SRVC_INTC = 0 , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_TIMER , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_SSP , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_DMA , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_I2C , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_WDT , // Harbell , BRN ( ? )	 
 PRM_NONRETAINED_SRVC_IPC , // Harbell	 
 PRM_NONRETAINED_SRVC_USIM , // Harbell	 
 PRM_NONRETAINED_SRVC_PMIC , // Harbell	 
 PRM_NONRETAINED_SRVC_MSL , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_SCK , // Harbell	 
 PRM_NONRETAINED_SRVC_WB_SLEEP_MODULE , // Harbell	 
 PRM_NONRETAINED_SRVC_LTE_SLEEP_MODULE , // Harbell	 
 PRM_NONRETAINED_SRVC_TD_LTE_SLEEP_MODULE , // Harbell	 
 PRM_NONRETAINED_SRVC_TCU , // Harbell	 
 PRM_NONRETAINED_SRVC_UART , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_HSI ,	 
 PRM_NONRETAINED_SRVC_GPIO , // BRN	 
 PRM_NONRETAINED_SRVC_USB20 , // BRN	 
 PRM_NONRETAINED_SRVC_UDC , // BRN	 
 PRM_NONRETAINED_SRVC_LCD , // BRN	 
 PRM_NONRETAINED_SRVC_DTC , // Seagull	 
 PRM_NONRETAINED_SRVC_PMNC , // Seagull	 
	 
 PRM_NUM_OF_NONRETAINED_SRVCS ,	 
 PRM_INVALID_NONRETAINED	 
	 
	 
 } PRM_NRS_ServiceE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_FREQ_13MHZ = 0 ,	 
 PRM_FREQ_26MHZ ,	 
 PRM_FREQ_52MHZ ,	 
 PRM_FREQ_78MHZ ,	 
 PRM_FREQ_89_1MHZ ,	 
 PRM_FREQ_104MHZ ,	 
 PRM_FREQ_124_8MHZ ,	 
 PRM_FREQ_156MHZ ,	 
 PRM_FREQ_208MHZ ,	 
 PRM_FREQ_260MHZ ,	 
 PRM_FREQ_312MHZ ,	 
 PRM_NUM_OF_FREQS ,	 
 PRM_INVALID_FREQ	 
 } PRM_ServiceFreqE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_RSRC_FREE=0 ,	 
 PRM_RSRC_ALLOC	 
	 
 } PRM_AllocFreeE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_RSRC_SC_FREE=1 , // resource is free , single client handling	 
 PRM_RSRC_SC_BUSY , // resource is busy , single client handling	 
 PRM_RSRC_MC_FREE , // resource is free , multi client handling	 
 PRM_RSRC_MC_BUSY , // resource is busy , multi client handling	 
 PRM_RSRC_NOT_DEFINED // resource is not defined	 
 // in this plat / sub-system	 
 } PRM_resourceStatusE;

typedef void ( *PRM_CallbackFuncWakeupT ) ( PM_PowerStatesE sleepstate , PM_PowerStatesE WUState , BOOL b_DDR_ready , BOOL b_RegsRetainedState ) ;
typedef void ( *PRM_CallbackFuncPrepareT ) ( PM_PowerStatesE statetoprepare ) ;
typedef void ( *PRM_CallbackFuncRecoverT ) ( PM_PowerStatesE stateexited , BOOL b_DDR_ready , BOOL b_RegsRetainedState ) ;
typedef void ( *PRM_CallbackFuncBeforeIntT ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 COMMCCU_SYS_PLL_FREQ_52MHZ = 0 ,	 
 COMMCCU_SYS_PLL_FREQ_104MHZ ,	 
 COMMCCU_SYS_PLL_FREQ_156MHZ ,	 
 COMMCCU_SYS_PLL_FREQ_208MHZ ,	 
 COMMCCU_SYS_PLL_FREQ_312MHZ ,	 
 COMMCCU_SYS_PLL_NUM_OF_FREQS	 
 } CommCCU_SystemPLLFreqE;

typedef UINT32 CPMU_State ;
typedef void ( *CPMUL2PowerChangeNotifyFn ) ( void ) ;
typedef void ( *CPMUPMICCOmmandSetNotifyFn ) ( void ) ;
typedef void ( *CPMUFrequencyChangeNotifyFn ) ( void ) ;
typedef UINT32 CPMU_EventStatus ;
typedef UINT32 CPMU_L2Status ;
typedef UINT32 CPMU_WakeupEventCombination ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 MULTI_USER_CLK_DSSP_BUS=0 ,	 
 MULTI_USER_CLK_VCTCXO ,	 
 MULTI_USER_CLK_MODEM_78MHZ ,	 
 MULTI_USER_CLK_MODEM_104MHZ ,	 
 MULTI_USER_CLK_DDR_HIGH_FREQ , // rafiagiv - 21 / 12	 
 NUMBER_OF_MULTI_USER_CLOCKS ,	 
 NO_MULTI_USER_CLOCK = -1	 
 } RM_MultiUserClocksE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 d2CbkPrepare ;	 
 UINT32 d2CbkRecover ;	 
 RM_ServiceCallbackE cbkevent ;	 
 } RM_PrepareRecoverEventsS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 cbkWakeup ;	 
 RM_ServiceCallbackE cbkevent ;	 
 } RM_WakeUpEventsS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 RM_PrepareRecoverEventsS RM_PrepareRecoverEventsEArray [ RM_NUM_OF_CALLBACK_SRVCS ] ;	 
 } RM_EventsArrayRecPreS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 RM_WakeUpEventsS RM_WakeUpEventsArray [ RM_NUM_OF_CALLBACK_SRVCS ] ;	 
 } RM_EventsArrayWakeupS;

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\prm_hrbl.ppp
//PPL Source File Name : X:\\hop\\rm\\src\\prm_hrbl.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_RC_OK = 0 ,	 
 PRM_RC_FAIL , // MB _ Added General Fail	 
 PRM_RC_RESET_NOT_SUPPORTED ,	 
 PRM_RC_ERR_CLOCK = -100 ,	 
 PRM_RC_ERR_FREQ ,	 
 PRM_RC_ERR_NULL_POINTER ,	 
 PRM_RC_WAKEUP_NOT_SUPPORTED ,	 
 PRM_RC_SERVICE_NOT_SUPPORTED ,	 
 PRM_RC_ERR_CPMU // MB - Arbel Specific on reset on CPMU	 
 } PRM_ReturnCodeE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_SRVC_DMA ,	 
 PRM_SRVC_DVFM ,	 
 PRM_SRVC_DSSP0_GB ,	 
 PRM_SRVC_DSSP1_GB ,	 
 PRM_SRVC_DSSP2_GB ,	 
 PRM_SRVC_I2C ,	 
 PRM_SRVC_MSL ,	 
 PRM_SRVC_RTC ,	 
 PRM_SRVC_SSP1 ,	 
 PRM_SRVC_SSP2 ,	 
 PRM_SRVC_SSP3 ,	 
 PRM_SRVC_TIMER0_13M ,	 
 PRM_SRVC_TIMER1_13M ,	 
 PRM_SRVC_TIMER2_13M_GB ,	 
 PRM_SRVC_TIMER3_13M_GB ,	 
 PRM_SRVC_VCTCXO ,	 
 PRM_SRVC_UART1 ,	 
 PRM_SRVC_USIM ,	 
 PRM_SRVC_WB_CIPHER_GB , // DTC	 
 PRM_SRVC_USIM2 ,	 
 /*should be deleted for wujing */	 
 PRM_SRVC_CPA_DDR_HPerf , // Seagull - DDR Request from Harbell ( calls PRM_SRVC_MC_DDR_HPerf if needed )	 
 PRM_SRVC_AIRQ , // Seagull	 
 PRM_SRVC_COMM_IPC , // Seagull	 
 PRM_SRVC_RESOURCE_IPC , // Seagull	 
 PRM_SRVC_AXI_CFG , // Seagull	 
 PRM_SRVC_ETB , // Seagull	 
 PRM_SRVC_DTC , // Seagull	 
 PRM_SRVC_TCU_CTRL , // Seagull	 
 PRM_SRVC_ABP_BUS , // Seagull	 
 PRM_SRVC_AXI_BUS , // Seagull	 
 PRM_LAST_SERVICE=PRM_SRVC_AXI_BUS , // Always update this field.	 
 PRM_NUM_OF_SRVCS ,	 
 PRM_SRVC_NOT_AVAILABLE ,	 
 PRM_SRVC_MC_DDR_HPerf = PRM_SRVC_NOT_AVAILABLE	 
	 
 } PRM_ServiceE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_WU_SRVC_TIMER , // Harbell , BRN ( relevant for RTOS )	 
 PRM_WU_SRVC_SSP , // Harbell	 
 PRM_WU_SRVC_SCK , // Harbell	 
 PRM_WU_SRVC_WB_SLEEP_MODULE , // Harbell	 
 PRM_WU_SRVC_TD_SLEEP_MODULE = PRM_WU_SRVC_WB_SLEEP_MODULE ,	 
 PRM_WU_SRVC_LTE_SLEEP_MODULE , // Harbell	 
 PRM_WU_SRVC_TD_LTE_SLEEP_MODULE ,	 
 PRM_WU_SRVC_TCU , // Harbell	 
 PRM_WU_SRVC_UART , // Harbell , ( BRN via GPIO ( relevant for RTOS ) )	 
 PRM_WU_SRVC_AC_IPC , // Harbell , BRN ( relevant for RTOS )	 
 PRM_WU_SRVC_RTC , // BRN	 
 PRM_WU_SRVC_ROTARY , // BRN	 
 PRM_WU_SRVC_USB20_CLIENT , // BRN - Do we need to USB events or not?	 
 PRM_WU_SRVC_USB_OTGP2 , // BRN - Tx , P2 , P3 ( 3 diferent wakeups )	 
 PRM_WU_SRVC_USB_OTGP3 , // BRN - Tx , P2 , P3 ( 3 diferent wakeups )	 
 PRM_WU_SRVC_KEYPAD , // BRN	 
 PRM_WU_SRVC_USIM , // BRN	 
 PRM_WU_SRVC_USB_OTGTX , // BRN - Tx , P2 , P3 ( 3 diferent wakeups )	 
 PRM_WU_SRVC_GPIO , // BRN ( relevant for RTOS )	 
 PRM_WU_SRVC_COMM_WDT , // BRN	 
 PRM_WU_SRVC_AC97 , // BRN ored with BSSP wakeup	 
 PRM_WU_SRVC_CI2C , // BRN	 
 PRM_WU_SRVC_MMC1 , // BRN	 
 PRM_WU_SRVC_SDIO1 , // BRN	 
 PRM_WU_SRVC_MMC2 , // BRN	 
 PRM_WU_SRVC_SDIO2 , // BRN	 
 PRM_WU_SRVC_NAND , // BRN	 
 PRM_WU_SRVC_PMIC , // BRN ( relevant for RTOS )	 
 PRM_WU_BTUART , // BRN	 
 PRM_WU_STUART , // BRN	 
 PRM_WU_SRVC_ICP , // BRN - In A0 is ored with UARTs wakeup	 
 PRM_WU_SRVC_KEYPAD_ROTARY , // BRN	 
 PRM_WU_SRVC_KEYPAD_DIRECT_KEYS , // BRN	 
 PRM_WU_SRVC_EXTERNAL_EVENT0 , // BRN - Special case - Driver not defined	 
 PRM_WU_SRVC_EXTERNAL_EVENT1 , // BRN - Special case - Driver not defined	 
 PRM_WU_SRVC_BSSP1 , // BRN	 
 PRM_WU_SRVC_BSSP2 , // BRN	 
 PRM_WU_SRVC_BSSP3 , // BRN	 
 PRM_WU_SRVC_BSSP4 , // BRN	 
	 
 PRM_NUM_OF_WU_SRVCS ,	 
 PRM_ORED_INT_MSL0 , // For BRM B0	 
 PRM_WU_INVALID_RSRC	 
 } PRM_WU_ServiceE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_NONRETAINED_SRVC_INTC = 0 , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_TIMER , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_SSP , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_DMA , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_I2C , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_WDT , // Harbell , BRN ( ? )	 
 PRM_NONRETAINED_SRVC_IPC , // Harbell	 
 PRM_NONRETAINED_SRVC_USIM , // Harbell	 
 PRM_NONRETAINED_SRVC_PMIC , // Harbell	 
 PRM_NONRETAINED_SRVC_MSL , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_SCK , // Harbell	 
 PRM_NONRETAINED_SRVC_WB_SLEEP_MODULE , // Harbell	 
 PRM_NONRETAINED_SRVC_LTE_SLEEP_MODULE , // Harbell	 
 PRM_NONRETAINED_SRVC_TD_LTE_SLEEP_MODULE , // Harbell	 
 PRM_NONRETAINED_SRVC_TCU , // Harbell	 
 PRM_NONRETAINED_SRVC_UART , // Harbell , BRN	 
 PRM_NONRETAINED_SRVC_HSI ,	 
 PRM_NONRETAINED_SRVC_GPIO , // BRN	 
 PRM_NONRETAINED_SRVC_USB20 , // BRN	 
 PRM_NONRETAINED_SRVC_UDC , // BRN	 
 PRM_NONRETAINED_SRVC_LCD , // BRN	 
 PRM_NONRETAINED_SRVC_DTC , // Seagull	 
 PRM_NONRETAINED_SRVC_PMNC , // Seagull	 
	 
 PRM_NUM_OF_NONRETAINED_SRVCS ,	 
 PRM_INVALID_NONRETAINED	 
	 
	 
 } PRM_NRS_ServiceE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_FREQ_13MHZ = 0 ,	 
 PRM_FREQ_26MHZ ,	 
 PRM_FREQ_52MHZ ,	 
 PRM_FREQ_78MHZ ,	 
 PRM_FREQ_89_1MHZ ,	 
 PRM_FREQ_104MHZ ,	 
 PRM_FREQ_124_8MHZ ,	 
 PRM_FREQ_156MHZ ,	 
 PRM_FREQ_208MHZ ,	 
 PRM_FREQ_260MHZ ,	 
 PRM_FREQ_312MHZ ,	 
 PRM_NUM_OF_FREQS ,	 
 PRM_INVALID_FREQ	 
 } PRM_ServiceFreqE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_RSRC_FREE=0 ,	 
 PRM_RSRC_ALLOC	 
	 
 } PRM_AllocFreeE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PRM_RSRC_SC_FREE=1 , // resource is free , single client handling	 
 PRM_RSRC_SC_BUSY , // resource is busy , single client handling	 
 PRM_RSRC_MC_FREE , // resource is free , multi client handling	 
 PRM_RSRC_MC_BUSY , // resource is busy , multi client handling	 
 PRM_RSRC_NOT_DEFINED // resource is not defined	 
 // in this plat / sub-system	 
 } PRM_resourceStatusE;

typedef void ( *PRM_CallbackFuncWakeupT ) ( PM_PowerStatesE sleepstate , PM_PowerStatesE WUState , BOOL b_DDR_ready , BOOL b_RegsRetainedState ) ;
typedef void ( *PRM_CallbackFuncPrepareT ) ( PM_PowerStatesE statetoprepare ) ;
typedef void ( *PRM_CallbackFuncRecoverT ) ( PM_PowerStatesE stateexited , BOOL b_DDR_ready , BOOL b_RegsRetainedState ) ;
typedef void ( *PRM_CallbackFuncBeforeIntT ) ( void ) ;
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // APB Application Subsystem	 
 RM_SRVC_UART0 ,	 
 RM_SRVC_UART1 ,	 
 RM_SRVC_GPIO ,	 
 RM_SRVC_PWM0 ,	 
 RM_SRVC_PWM1 ,	 
 RM_SRVC_PWM2 ,	 
 RM_SRVC_PWM3 ,	 
 RM_SRVC_SSP0 ,	 
 RM_SRVC_SSP1 ,	 
 RM_SRVC_ACIPC ,	 
 RM_SRVC_RTC ,	 
 RM_SRVC_TWSI_HS ,	 
 RM_SRVC_KPC ,	 
 RM_SRVC_TIMERS_AS ,	 
 RM_SRVC_TB_ROTARY ,	 
 RM_SRVC_AIB ,	 
 RM_SRVC_SW_JTAG ,	 
 RM_SRVC_TIMERS1_AS ,	 
 RM_SRVC_ONEWIRE ,	 
 RM_SRVC_SSP2 ,	 
	 
 // APB Communication Subsystem	 
 RM_SRVC_TCU ,	 
 RM_SRVC_AIRQ ,	 
 RM_SRVC_UART2 , // Seagull	 
 RM_SRVC_USIM1 ,	 
 RM_SRVC_USIM2 ,	 
 RM_SRVC_TWSI ,	 
 RM_SRVC_ECIPHER ,	 
 RM_SRVC_TIMER_CS ,	 
 RM_SRVC_GSSP ,	 
 RM_SRVC_IPC ,	 
	 
 // Main PMU	 
 RM_SRVC_WDTPCR ,	 
	 
 // Application Subsystem PMU	 
 RM_SRVC_IRE ,	 
 RM_SRVC_LCD ,	 
 RM_SRVC_CCIC ,	 
 RM_SRVC_SDH0 ,	 
 RM_SRVC_SDH1 ,	 
 RM_SRVC_USB ,	 
 RM_SRVC_NF ,	 
 RM_SRVC_DMA ,	 
 RM_SRVC_GEU ,	 
 RM_SRVC_DTC ,	 
 RM_SRVC_GC ,	 
 RM_SRVC_SMC ,	 
 RM_SRVC_RTU ,	 
	 
 RM_NUM_OF_SRVCS ,	 
 RM_INVALID_SRVCS = RM_NUM_OF_SRVCS ,	 
 RM_SRVC_VCTCXO = RM_INVALID_SRVCS ,	 
 RM_SRVC_TIMER0_13M = RM_INVALID_SRVCS ,	 
 RM_SRVC_TIMER2_13M_GB = RM_INVALID_SRVCS ,	 
 RM_SRVC_DDR_HIGH_FREQ = RM_INVALID_SRVCS	 
	 
 } RM_ServiceIdE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 RM_CALLBACK_SRVC_INTC = 0 , /* MUST BE FIRST - it saves data while request are	 
 done , thus if request to enable / disable interrupt	 
 will come from onother source ( on there exit routine )	 
 the data to restore interrup controler will be ruined */	 
 RM_CALLBACK_SRVC_TIMER , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_SSP , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_DMA ,	 
 RM_CALLBACK_SRVC_I2C , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_WDT , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_IPC ,	 
 RM_CALLBACK_SRVC_USIM , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_PMIC , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_MSL , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_SCK , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_WB_SLEEP_MODULE , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_LTE_SLEEP_MODULE ,	 
 RM_CALLBACK_SRVC_WB_LTE_SLEEP_MODULE ,	 
 RM_CALLBACK_SRVC_TCU ,	 
 RM_CALLBACK_SRVC_UART ,	 
 RM_CALLBACK_SRVC_HSI ,	 
 RM_CALLBACK_SRVC_AC_IPC , /* Apps-Comm IPC service wakeup */ // YKYK TODO	 
 RM_CALLBACK_SRVC_CGPIO , /** This service may register for wakeup **/	 
 RM_NUM_OF_CALLBACK_SRVCS ,	 
 RM_INVALID_CALLBACK = RM_NUM_OF_CALLBACK_SRVCS	 
	 
 } RM_ServiceCallbackE;

typedef UINT32 RM_CurrentResourcesStatusT ;
typedef RM_CurrentResourcesStatusT RM_ResourcesArrT [ 32 ] ;
typedef void ( *RM_CallbackFuncT ) ( void ) ;
typedef void ( *RM_D2RecoverCallbackFuncT ) ( PM_PowerStatesE psType ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 COMMCCU_SYS_PLL_FREQ_52MHZ = 0 ,	 
 COMMCCU_SYS_PLL_FREQ_104MHZ ,	 
 COMMCCU_SYS_PLL_FREQ_156MHZ ,	 
 COMMCCU_SYS_PLL_FREQ_208MHZ ,	 
 COMMCCU_SYS_PLL_FREQ_312MHZ ,	 
 COMMCCU_SYS_PLL_NUM_OF_FREQS	 
 } CommCCU_SystemPLLFreqE;

typedef UINT32 CPMU_State ;
typedef void ( *CPMUL2PowerChangeNotifyFn ) ( void ) ;
typedef void ( *CPMUPMICCOmmandSetNotifyFn ) ( void ) ;
typedef void ( *CPMUFrequencyChangeNotifyFn ) ( void ) ;
typedef UINT32 CPMU_EventStatus ;
typedef UINT32 CPMU_L2Status ;
typedef UINT32 CPMU_WakeupEventCombination ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 MULTI_USER_CLK_DSSP_BUS=0 ,	 
 MULTI_USER_CLK_VCTCXO ,	 
 MULTI_USER_CLK_MODEM_78MHZ ,	 
 MULTI_USER_CLK_MODEM_104MHZ ,	 
 MULTI_USER_CLK_DDR_HIGH_FREQ , // rafiagiv - 21 / 12	 
 NUMBER_OF_MULTI_USER_CLOCKS ,	 
 NO_MULTI_USER_CLOCK = -1	 
 } RM_MultiUserClocksE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 d2CbkPrepare ;	 
 UINT32 d2CbkRecover ;	 
 RM_ServiceCallbackE cbkevent ;	 
 } RM_PrepareRecoverEventsS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 cbkWakeup ;	 
 RM_ServiceCallbackE cbkevent ;	 
 } RM_WakeUpEventsS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 RM_PrepareRecoverEventsS RM_PrepareRecoverEventsEArray [ RM_NUM_OF_CALLBACK_SRVCS ] ;	 
 } RM_EventsArrayRecPreS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 RM_WakeUpEventsS RM_WakeUpEventsArray [ RM_NUM_OF_CALLBACK_SRVCS ] ;	 
 } RM_EventsArrayWakeupS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 PRM_ServiceE resourceNum ;	 
 PRM_AllocFreeE allocFreeState ;	 
 } PRM_SetResourceStatusS;

//ICAT EXPORTED FUNCTION - PM , PRM , SetResourceState 
 void prmSetResourceState ( PRM_SetResourceStatusS *pDataParam ) 
 {	 
	 
 PRMManage ( pDataParam->resourceNum , pDataParam->allocFreeState ) ;	 
	 
DIAG_FILTER ( PM , PRM , SetResourceState1 , DIAG_INFORMATION)  
 diagPrintf ( " Resource %e { PRM_ServiceE } Set to %e { PRM_AllocFreeE } " , 
 pDataParam->resourceNum , 
 pDataParam->allocFreeState );

	 
 }

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 PRM_ServiceE Srvc ;	 
 UINT32 Value ;	 
 } _RmControlS;

//ICAT EXPORTED FUNCTION - PM , PRM , SetExceptionSrvc 
 void SetExceptionSrvc ( _RmControlS *ControlStructP ) 
 {	 
 PRMTurnOnAndIgnoreLpmSrvc ( ControlStructP->Srvc , ControlStructP->Value ) ;	 
 if ( ControlStructP->Value )	 
 {		 
DIAG_FILTER ( PM , PRM , SetExceptionSrvc1 , DIAG_INFORMATION)  
 diagPrintf ( " Srvc %e { PRM_ServiceE } is always on and D2 decision for this srvc is ignored " , ControlStructP->Srvc );

		 
 }	 
 else	 
 {		 
DIAG_FILTER ( PM , PRM , SetExceptionSrvc2 , DIAG_INFORMATION)  
 diagPrintf ( " Srvc %e { PRM_ServiceE } is back to normal ( OnOff controlled by driver and not ignored for D2 decision ) " , ControlStructP->Srvc );

		 
 }	 
	 
 }

//ICAT EXPORTED FUNCTION - PM , PRM , GetExceptionSrvc 
 void GetExceptionSrvc ( void ) 
 {	 
 UINT32 Index ; // PRM_ServiceE	 
	 
 for ( Index=0 ; Index!=PRM_NUM_OF_SRVCS ; Index++ )	 
 {		 
 // is the resource in ignore D2 resources... ( INiT + dynamic changes )		 
 UINT32 mainNum= ( rmLookUpTables . serviceToMainResourceBitVector [ ( PRM_HRBL_LUT . LUT [ Index ] ) ] ) ;		 
 if ( ( RmIgnoreRsrcsRequests| ( ( 0x1 << 14 ) | ( 0x1 << 2 ) | ( 0x1 << 3 ) | ( 0x1 << 12 ) ) ) & ( mainNum ) )		 
 {			 
DIAG_FILTER ( PM , PRM , GetExceptionSrvc1 , DIAG_INFORMATION)  
 diagPrintf ( " Srvc %e ( PRM_ServiceE ) is back to normal ( OnOff controlled by driver and not ignored for D2 decision ) " , ControlStructP->Srvc );

			 
 diagPrintf ( " Exception service: %e { PRM_ServiceE } - 0x%lx " , Index , mainNum ) ;			 
 // diagPrintf ( " hello %d " , Index ) ;			 
 }		 
 }	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\rm_debug.ppp
//PPL Source File Name : X:\\hop\\rm\\src\\rm_debug.c
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
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 // APB Application Subsystem	 
 RM_SRVC_UART0 ,	 
 RM_SRVC_UART1 ,	 
 RM_SRVC_GPIO ,	 
 RM_SRVC_PWM0 ,	 
 RM_SRVC_PWM1 ,	 
 RM_SRVC_PWM2 ,	 
 RM_SRVC_PWM3 ,	 
 RM_SRVC_SSP0 ,	 
 RM_SRVC_SSP1 ,	 
 RM_SRVC_ACIPC ,	 
 RM_SRVC_RTC ,	 
 RM_SRVC_TWSI_HS ,	 
 RM_SRVC_KPC ,	 
 RM_SRVC_TIMERS_AS ,	 
 RM_SRVC_TB_ROTARY ,	 
 RM_SRVC_AIB ,	 
 RM_SRVC_SW_JTAG ,	 
 RM_SRVC_TIMERS1_AS ,	 
 RM_SRVC_ONEWIRE ,	 
 RM_SRVC_SSP2 ,	 
	 
 // APB Communication Subsystem	 
 RM_SRVC_TCU ,	 
 RM_SRVC_AIRQ ,	 
 RM_SRVC_UART2 , // Seagull	 
 RM_SRVC_USIM1 ,	 
 RM_SRVC_USIM2 ,	 
 RM_SRVC_TWSI ,	 
 RM_SRVC_ECIPHER ,	 
 RM_SRVC_TIMER_CS ,	 
 RM_SRVC_GSSP ,	 
 RM_SRVC_IPC ,	 
	 
 // Main PMU	 
 RM_SRVC_WDTPCR ,	 
	 
 // Application Subsystem PMU	 
 RM_SRVC_IRE ,	 
 RM_SRVC_LCD ,	 
 RM_SRVC_CCIC ,	 
 RM_SRVC_SDH0 ,	 
 RM_SRVC_SDH1 ,	 
 RM_SRVC_USB ,	 
 RM_SRVC_NF ,	 
 RM_SRVC_DMA ,	 
 RM_SRVC_GEU ,	 
 RM_SRVC_DTC ,	 
 RM_SRVC_GC ,	 
 RM_SRVC_SMC ,	 
 RM_SRVC_RTU ,	 
	 
 RM_NUM_OF_SRVCS ,	 
 RM_INVALID_SRVCS = RM_NUM_OF_SRVCS ,	 
 RM_SRVC_VCTCXO = RM_INVALID_SRVCS ,	 
 RM_SRVC_TIMER0_13M = RM_INVALID_SRVCS ,	 
 RM_SRVC_TIMER2_13M_GB = RM_INVALID_SRVCS ,	 
 RM_SRVC_DDR_HIGH_FREQ = RM_INVALID_SRVCS	 
	 
 } RM_ServiceIdE;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 RM_CALLBACK_SRVC_INTC = 0 , /* MUST BE FIRST - it saves data while request are	 
 done , thus if request to enable / disable interrupt	 
 will come from onother source ( on there exit routine )	 
 the data to restore interrup controler will be ruined */	 
 RM_CALLBACK_SRVC_TIMER , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_SSP , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_DMA ,	 
 RM_CALLBACK_SRVC_I2C , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_WDT , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_IPC ,	 
 RM_CALLBACK_SRVC_USIM , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_PMIC , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_MSL , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_SCK , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_WB_SLEEP_MODULE , /** This service may register for wakeup **/	 
 RM_CALLBACK_SRVC_LTE_SLEEP_MODULE ,	 
 RM_CALLBACK_SRVC_WB_LTE_SLEEP_MODULE ,	 
 RM_CALLBACK_SRVC_TCU ,	 
 RM_CALLBACK_SRVC_UART ,	 
 RM_CALLBACK_SRVC_HSI ,	 
 RM_CALLBACK_SRVC_AC_IPC , /* Apps-Comm IPC service wakeup */ // YKYK TODO	 
 RM_CALLBACK_SRVC_CGPIO , /** This service may register for wakeup **/	 
 RM_NUM_OF_CALLBACK_SRVCS ,	 
 RM_INVALID_CALLBACK = RM_NUM_OF_CALLBACK_SRVCS	 
	 
 } RM_ServiceCallbackE;

typedef UINT32 RM_CurrentResourcesStatusT ;
typedef RM_CurrentResourcesStatusT RM_ResourcesArrT [ 32 ] ;
typedef void ( *RM_CallbackFuncT ) ( void ) ;
typedef void ( *RM_D2RecoverCallbackFuncT ) ( PM_PowerStatesE psType ) ;
//ICAT EXPORTED ENUM 
 typedef enum {	 
 MULTI_USER_CLK_DSSP_BUS=0 ,	 
 MULTI_USER_CLK_VCTCXO ,	 
 MULTI_USER_CLK_MODEM_78MHZ ,	 
 MULTI_USER_CLK_MODEM_104MHZ ,	 
 MULTI_USER_CLK_DDR_HIGH_FREQ , // rafiagiv - 21 / 12	 
 NUMBER_OF_MULTI_USER_CLOCKS ,	 
 NO_MULTI_USER_CLOCK = -1	 
 } RM_MultiUserClocksE;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 d2CbkPrepare ;	 
 UINT32 d2CbkRecover ;	 
 RM_ServiceCallbackE cbkevent ;	 
 } RM_PrepareRecoverEventsS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 UINT32 cbkWakeup ;	 
 RM_ServiceCallbackE cbkevent ;	 
 } RM_WakeUpEventsS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 RM_PrepareRecoverEventsS RM_PrepareRecoverEventsEArray [ RM_NUM_OF_CALLBACK_SRVCS ] ;	 
 } RM_EventsArrayRecPreS;

//ICAT EXPORTED STRUCT 
 typedef struct {	 
 RM_WakeUpEventsS RM_WakeUpEventsArray [ RM_NUM_OF_CALLBACK_SRVCS ] ;	 
 } RM_EventsArrayWakeupS;

//ICAT EXPORTED FUNCTION - PM , DDR , AllocDDRHighFreq 
 void AllocDDRHighFreq ( void ) 
 {	 
DIAG_FILTER ( PM , RM , AllocDDRHighFreq0 , DIAG_INFORMATION)  
 diagPrintf ( " previous status was: %lx highFreq counter is : %lx " , _rmVars.currentResourcesStatus , 
 _rmVars.multiUserCounters [ MULTI_USER_CLK_DDR_HIGH_FREQ ] );

	 
 RMManage ( RM_SRVC_DDR_HIGH_FREQ , RM_RSRC_ALLOC ) ;	 
DIAG_FILTER ( PM , RM , AllocDDRHighFreq1 , DIAG_INFORMATION)  
 diagPrintf ( " current status is: %lx highFreq counter is : %lx " , _rmVars.currentResourcesStatus , 
 _rmVars.multiUserCounters [ MULTI_USER_CLK_DDR_HIGH_FREQ ] );

	 
 }

//ICAT EXPORTED FUNCTION - PM , DDR , FreeDDRHighFreq 
 void FreeDDRHighFreq ( void ) 
 {	 
DIAG_FILTER ( PM , RM , FreeDDRHighFreq0 , DIAG_INFORMATION)  
 diagPrintf ( " previous status was: %lx highFreq counter is : %lx " , _rmVars.currentResourcesStatus , 
 _rmVars.multiUserCounters [ MULTI_USER_CLK_DDR_HIGH_FREQ ] );

	 
 RMManage ( RM_SRVC_DDR_HIGH_FREQ , RM_RSRC_FREE ) ;	 
DIAG_FILTER ( PM , RM , FreeDDRHighFreq1 , DIAG_INFORMATION)  
 diagPrintf ( " current status is: %lx highFreq counter is : %lx " , _rmVars.currentResourcesStatus , 
 _rmVars.multiUserCounters [ MULTI_USER_CLK_DDR_HIGH_FREQ ] );

	 
 }

