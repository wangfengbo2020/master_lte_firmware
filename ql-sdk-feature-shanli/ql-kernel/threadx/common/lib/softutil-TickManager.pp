//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\tick_manager.ppp
//PPL Source File Name : X:\\softutil\\TickManager\\src\\tick_manager.c
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

typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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
typedef UINT8 OS_STATUS ;
typedef void* OS_HISR ;
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
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\NUtick.ppp
//PPL Source File Name : X:\\softutil\\TickManager\\src\\NUtick.c
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

typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
typedef unsigned long long UINT64 ;
typedef unsigned long TimeIn32KhzUnit ;
typedef void ( *TickCallbackPtr ) ( UINT32 ) ;
typedef TimeIn32KhzUnit ( *SuspendCallbackPtr ) ( void ) ;
typedef void ( *PrepareTimeCallbackPtr ) ( void ) ;
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
typedef UINT8 OS_STATUS ;
typedef void* OS_HISR ;
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
DIAG_FILTER ( SW_PLAT , NUTick , dumpNutickDelayInfo_1 , DIAG_INFORMATION)  
 diagPrintf ( " [ %d ] Unknown 0x%lx , delay 0x%lx at 0x%lx , LR 0x%lx " , index , currDelayContext , 
 NutickDelayContextInfo [ index ] [ 1 ] , NutickDelayContextInfo [ index ] [ 2 ] , NutickDelayContextInfo [ index ] [ 3 ] );

DIAG_FILTER ( SW_PLAT , NUTick , dumpNutickDelayInfo_2 , DIAG_INFORMATION)  
 diagPrintf ( " [ %d ] task %s , delay 0x%lx at 0x%lx , LR 0x%lx " , index , OSATaskGetName ( ( OSATaskRef ) currDelayContext ) , 
 NutickDelayContextInfo [ index ] [ 1 ] , NutickDelayContextInfo [ index ] [ 2 ] , NutickDelayContextInfo [ index ] [ 3 ] );

DIAG_FILTER ( SW_PLAT , NUTick , dumpNutickDelayInfo_0 , DIAG_INFORMATION)  
 diagPrintf ( " NU TICK: max delay 0x%lx , max cost 0x%lx , total ticks 0x%lx , total cnt 0x%lx " , NutickCompensateMaxTick , NutickCompensateMaxCost , NutickTotalCompensateTicks , NutickTotalCompensateCnts );

