//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\EEIRAMBuffer.ppp
//PPL Source File Name : \\softutil\\EEhandler\\src\\EEIRAMBuffer.c
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
typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
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

typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure what deffered modes are Enabled*/	 
 EE_DEFER_NONE , /* @ENUM_VAL_DESC@ Defer no actions*/	 
 EE_DEFER_ASSERTS , /* @ENUM_VAL_DESC@ Defer asserts*/	 
 EE_DEFER_EXCEPTIONS , /* @ENUM_VAL_DESC@ Defer exceptions*/	 
 EE_DEFER_ALL /* @ENUM_VAL_DESC@ Defer all actions*/	 
 } EE_DeferredMode_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Deffered action configuration*/	 
 EE_DeferredMode_t enable ; /* @ITEM_DESC@ Configure what deffered modes are Enabled , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t deferIntermediateActions ; /* @ITEM_DESC@ Set defer intermidate actions , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT16 limitMs ; /* @ITEM_DESC@ deferred actions time limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF in milisec*/	 
 UINT16 limitHits ; /* @ITEM_DESC@ deferred actions hits limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF*/	 
 UINT16 reserved2 ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 } EE_DeferredCfg_t;

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
	 
 // -------- version 1 +D ----------	 
 EE_DeferredCfg_t deferredCfg ; /* @ITEM_DESC@ Deffered action configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
	 
	 
	 
 EE_WdtTimeCfg_t wdtConfigTime ; /* @ITEM_DESC@ WatchDog timer configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/ // UINT16	 
 UINT16 sysEeHandlerLimit ; /* @ITEM_DESC@ EE handler system limit ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 1 -0xFFFF , 0 -No limit*/ // relevant for EE_ASSISTING_MASTER only ; ZERO is no limits	 
 UINT32 dumpDdrSizeBytes ; /* @ITEM_DESC@ Limit DDR size to dump ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes , 0x1 -0x400 - No limit*/ // relevant for EE_ASSISTING_MASTER only	 
 UINT8 reserved [ 24 ] ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 UINT32 dumpResetFlag ; /*default is 0 . When finalAction is EE_RESET , 1 :dump and then silent reset ; 0 :silent reset without dump*/	 
 } EE_Configuration_t;

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

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\EEHandler.ppp
//PPL Source File Name : \\softutil\\EEhandler\\src\\EEHandler.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
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
typedef int sig_atomic_t ;
typedef void ( *__ARM_sigh_t ) ( int ) ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure what deffered modes are Enabled*/	 
 EE_DEFER_NONE , /* @ENUM_VAL_DESC@ Defer no actions*/	 
 EE_DEFER_ASSERTS , /* @ENUM_VAL_DESC@ Defer asserts*/	 
 EE_DEFER_EXCEPTIONS , /* @ENUM_VAL_DESC@ Defer exceptions*/	 
 EE_DEFER_ALL /* @ENUM_VAL_DESC@ Defer all actions*/	 
 } EE_DeferredMode_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Deffered action configuration*/	 
 EE_DeferredMode_t enable ; /* @ITEM_DESC@ Configure what deffered modes are Enabled , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t deferIntermediateActions ; /* @ITEM_DESC@ Set defer intermidate actions , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT16 limitMs ; /* @ITEM_DESC@ deferred actions time limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF in milisec*/	 
 UINT16 limitHits ; /* @ITEM_DESC@ deferred actions hits limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF*/	 
 UINT16 reserved2 ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 } EE_DeferredCfg_t;

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
	 
 // -------- version 1 +D ----------	 
 EE_DeferredCfg_t deferredCfg ; /* @ITEM_DESC@ Deffered action configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
	 
	 
	 
 EE_WdtTimeCfg_t wdtConfigTime ; /* @ITEM_DESC@ WatchDog timer configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/ // UINT16	 
 UINT16 sysEeHandlerLimit ; /* @ITEM_DESC@ EE handler system limit ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 1 -0xFFFF , 0 -No limit*/ // relevant for EE_ASSISTING_MASTER only ; ZERO is no limits	 
 UINT32 dumpDdrSizeBytes ; /* @ITEM_DESC@ Limit DDR size to dump ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes , 0x1 -0x400 - No limit*/ // relevant for EE_ASSISTING_MASTER only	 
 UINT8 reserved [ 24 ] ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 UINT32 dumpResetFlag ; /*default is 0 . When finalAction is EE_RESET , 1 :dump and then silent reset ; 0 :silent reset without dump*/	 
 } EE_Configuration_t;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures Product Debug Level */	 
 PRODUCT_MODE = 0 , /* @ENUM_VAL_DESC@ Product Mode Debug level*/	 
 DEBUG_NORMAL = 1 , /* @ENUM_VAL_DESC@ Normal Debug level*/	 
 DEBUG_EXTEND = 2 /* @ENUM_VAL_DESC@ Extended Debug level*/	 
 } ProductDebugLevel_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures UART route */	 
 UART_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 UART_DATA_IO = 1 , /* @ENUM_VAL_DESC@ Route UART to DATA IO */	 
 UART_DIAG_ACAT = 2 , /* @ENUM_VAL_DESC@ Route UART to DIAG ACAT */	 
 UART_NULL = 0xFF /* @ENUM_VAL_DESC@ Disable*/	 
 } platformUART_route_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures DIAG route */	 
 DIAG_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 USB = 1 , /* @ENUM_VAL_DESC@ Route DIAG through USB*/	 
 UART = 2 /* @ENUM_VAL_DESC@ Route DIAG through UART*/	 
 } platformDIAG_route_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures USB detection*/	 
 USB_DETECT_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 USB_DETECT_ENABLE = 1 , /* @ENUM_VAL_DESC@ Enable USB detection*/	 
 USB_DETECT_DISABLE = 2 , /* @ENUM_VAL_DESC@ Disable USB detection*/	 
 USB_ALWAYS_CONNECT = 3 , /* @ENUM_VAL_DESC@ Always connect to USB*/	 
 USB_ALWAYS_DISCONNECT = 4 /* @ENUM_VAL_DESC@ Never connect to USB*/	 
 } platformUSBdetection_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures HeartBeat mode*/	 
 HB_DISABLE= 0 , /* @ENUM_VAL_DESC@ Disable heart beat*/	 
 TO_UART = 1 , /* @ENUM_VAL_DESC@ Send heart beat to UART*/	 
 TO_ACAT = 2 , /* @ENUM_VAL_DESC@ Send heart beat to ACAT*/	 
 ANOTHER = 3 /* @ENUM_VAL_DESC@ Reserved*/	 
 } platformHeartBeat_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures RTC Client*/	 
 RTC_CLIENT_DEFAULT = 0x0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 RTC_CLIENT_ENABLE = 1 , /* @ENUM_VAL_DESC@ Enable RTC client*/	 
 RTC_CLIENT_DISABLE = 2 /* @ENUM_VAL_DESC@ Disable RTC client*/	 
 } platformRtcClient_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures Relaiable Data load source*/	 
 RD_DEFAULT = 0x0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 RD_LOAD_CALIB_FILES_FROM_FLASH = 1 , /* @ENUM_VAL_DESC@ Load Callibration files from flash*/	 
 RD_DONT_LOAD_CALIB_FILES_FROM_FALSH = 2 /* @ENUM_VAL_DESC@ Don ' t load Callibration files from flash*/	 
 } platformRelaibeData_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure Comm-Apps sync*/	 
 PM_COMM_APPS_SYNC_DISABLED = 0 , /* @ENUM_VAL_DESC@ Disable Comm-Apps sync*/	 
 PM_COMM_APPS_SYNC_ENABLED = 1 /* @ENUM_VAL_DESC@ Enable Comm-Apps sync*/	 
 } nvmPM_CommAppsSync_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure Power Manager operation level*/	 
 PM_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 PM_FULL_ENABLE = 1 , /* @ENUM_VAL_DESC@ Enable Power Manager full functionality*/	 
 PM_DISABLE = 2 , /* @ENUM_VAL_DESC@ Disable Power Manager */	 
 PM_LEVEL_C1 = 3 , /* @ENUM_VAL_DESC@ Enable Power Manager C1 */	 
 PM_LEVEL_D2 = 4 /* @ENUM_VAL_DESC@ Enable Power Manager D2 */	 
 } nvmPM_level_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Set product point*/	 
 PP_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 PP_1 = 1 , /* @ENUM_VAL_DESC@ Set product point to 1 */	 
 PP_2 = 2 , /* @ENUM_VAL_DESC@ Set product point to 2 */	 
 PP_3 = 3 , /* @ENUM_VAL_DESC@ Set product point to 3 */	 
 PP_4 = 4 /* @ENUM_VAL_DESC@ Set product point to 4 */	 
 } nvmPM_ProductPoint_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PNVM_DEFAULT=0 ,	 
 PNVM_ENABLE ,	 
 PNVM_DISABLE	 
 } nvm_EN_DIS_DEF_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Configures Power Manager*/	 
 nvmPM_CommAppsSync_ts PM_AppsCommSyncEnabled ; /* @ITEM_DESC@ Configure Comm-Apps sync , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 nvmPM_ProductPoint_ts PM_ProductPoint ; /* @ITEM_DESC@ Set product point , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 nvmPM_level_ts PM_dbgLevel ; /* @ITEM_DESC@ Configure Power Manager operation level , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 nvm_EN_DIS_DEF_ts PM_newDDRHandshakeEnabled ;	 
 } platformPowerMngr_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures USIM error handling*/	 
 USIM_ERR_SILENT = 0 , /* @ENUM_VAL_DESC@ Silent error handling*/	 
 USIM_ERR_ASSERT = 1 , /* @ENUM_VAL_DESC@ Assert on error*/	 
 USIM_ERR_RECOVERY = 2 /* @ENUM_VAL_DESC@ error handling recovery*/	 
 } nvmUsimErrorHandler_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Configures USIM driver settings*/	 
 ProductDebugLevel_ts DebugLevel ; /* @ITEM_DESC@ Configures USIM Debug Level , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT8 TxDmaDisable ; /* @ITEM_DESC@ Configure Tx Dma Disable , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFF*/	 
 UINT8 DetectGpioPinNo ; /* @ITEM_DESC@ Set USIM detection GPIO , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Entries 1 -0xFF according to available GPIOs , 0 to diasble detection*/ // disable=0 , Detect_Pin=0xFF , others are GPIO / CGPIO pins	 
 nvmUsimErrorHandler_ts ErrorHandler ; /* @ITEM_DESC@ Configures USIM error handling , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 } platformUsim_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures AppCommMode*/	 
 APPCOMM_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 APPCOMM_COMM_IN_RESET = 1 , /* @ENUM_VAL_DESC@ Set Comm in reset*/	 
 APPCOMM_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force AppsComm enum long*/	 
 } platformAppsCommMode_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures OSA Error behavior*/	 
 OSA_ERROR_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 OSA_ERROR_ASSERT = 1 , /* @ENUM_VAL_DESC@ Assert on OSA errors*/	 
 OSA_ERROR_IGNORE = 2 , /* @ENUM_VAL_DESC@ Ignore OSA errors*/	 
 OSA_ERROR_RESTORE_OK = 3 , /* @ENUM_VAL_DESC@ OSA error restore*/	 
 OSA_ERROR_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force OSA error enum long*/	 
 } platformOsaErrBehavior_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures I2C FAST-SLOW mode*/	 
 NVM_I2C_CLK_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 NVM_I2C_SLOW_ClK_MODE = 0x00007fff , /* @ENUM_VAL_DESC@ Configure for slow mode align to I2c.h*/	 
 NVM_I2C_FAST_CLK_MODE = 0x00008000 , /* @ENUM_VAL_DESC@ Configure for fast mode align to I2c.h*/	 
 NVM_I2C_CLK_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force I2C error enum long*/	 
 } platfromI2cModeCfg_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures I2C repeat start configuration */	 
 NVM_I2C_REPEAT_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 NVM_I2C_NOT_REPEAT_START = 1 , /* @ENUM_VAL_DESC@ Configure for slow mode align to I2c.h*/	 
 NVM_I2C_REPEAT_START = 2 , /* @ENUM_VAL_DESC@ Configure for fast mode align to I2c.h*/	 
 NVM_I2C_REPEAT_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force I2C error enum long*/	 
 } platfromI2cRepeatCfg_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ I2C Configures */	 
 platfromI2cModeCfg_ts I2cClkMode ; /* @ITEM_DESC@ Configures I2C CLK mode FAST / SLOW , @ITEM_MODE@ Configuration , @ITEM_UNIT@ see enum*/	 
 platfromI2cRepeatCfg_ts I2cRptStrt ; /* @ITEM_DESC@ Configures I2C REPEAT_START mode yes / no , @ITEM_MODE@ Configuration , @ITEM_UNIT@ see enum*/	 
 } platfromI2cCfg_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Platfrom configuration */	 
 /* @STRUCT_NVM_FILE_NAME@ platfrom.nvm */	 
 ProductDebugLevel_ts ProductDebugLevel ; /* @ITEM_DESC@ Configures Product Debug Level , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
 UINT32 DelayMSEC_Startup ; /* @ITEM_DESC@ Startup Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_MSL ; /* @ITEM_DESC@ MSL Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_Audio ; /* @ITEM_DESC@ Audio Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_Power ; /* @ITEM_DESC@ Power Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_L1start ; /* @ITEM_DESC@ L1 start Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_reserv1 ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not Relevant*/	 
	 
 platformUART_route_ts UART_route ; /* @ITEM_DESC@ Configures UART route , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformDIAG_route_ts DIAG_route ; /* @ITEM_DESC@ Configures DIAG route , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformUSBdetection_ts USBdetection ; /* @ITEM_DESC@ Configures USB detection , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformHeartBeat_ts HeartBeat ; /* @ITEM_DESC@ Configures HeartBeat modes , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformPowerMngr_ts PowerManagement ; /* @ITEM_DESC@ Configures Power Manager , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
 platformRtcClient_ts RTC_Client ; /* @ITEM_DESC@ Configures RTC Client , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformRelaibeData_ts RD_LoadCalibFiles ; /* @ITEM_DESC@ Configures Relaiable Data load source , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
	 
 platformUsim_ts USIM ; /* @ITEM_DESC@ Configures USIM driver settings , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
 platformAppsCommMode_ts AppCommMode ; /* @ITEM_DESC@ Configures AppCommMode , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
 platformOsaErrBehavior_ts OsaErrBehavior ; /* @ITEM_DESC@ Configures OSA Error behavior , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platfromI2cCfg_ts NvmCfgI2C ; /* @ITEM_DESC@ Configures I2c CLK and REPEAT_START , @ITEM_MODE@ Configuration , @ITEM_UNIT@ see enum*/	 
 /* the reserved [ X ] must be update for backward	 
 * compatible if new fields are added to PlatformNvm_ts.	 
 * for example if you add UNIT32 you need to reduce X = X-4*/	 
 UINT8 reserved [ 44 ] ; /* @ITEM_DESC@ the amount of the reserved must be reduced if fields are added , @ITEM_MODE@ debugging , @ITEM_UNIT@ none*/	 
	 
 } PlatformNvm_ts;

DIAG_FILTER ( EE_HANDLER , EE , EE_LOG_RESET , DIAG_INFORMATION)  
 diagStructPrintf ( " EE LOG: RESET: %S { EE_Entry_t } " , ( UINT16 * ) entry , sizeof ( *entry ) );

DIAG_FILTER ( EE_HANDLER , EE , EE_LOG_ASSERT , DIAG_INFORMATION)  
 diagStructPrintf ( " EE LOG: ASSERT: %S { EE_Entry_t } " , ( UINT16 * ) entry , sizeof ( *entry ) );

DIAG_FILTER ( EE_HANDLER , EE , EE_LOG_EXCEPTION , DIAG_INFORMATION)  
 diagStructPrintf ( " EE LOG: EXCEPTION: %S { EE_Entry_t } " , ( UINT16 * ) entry , sizeof ( *entry ) );

DIAG_FILTER ( EE_HANDLER , EE , EE_LOG_WARNING , DIAG_INFORMATION)  
 diagStructPrintf ( " EE LOG: WARNING: %S { EE_Entry_t } " , ( UINT16 * ) entry , sizeof ( *entry ) );

DIAG_FILTER ( EE_HANDLER , EE , EE_LOG_UNKNOWN , DIAG_WARNING)  
 diagStructPrintf ( " EE LOG: UNKNOWN: %S { EE_Entry_t } " , ( UINT16 * ) entry , sizeof ( *entry ) );

//ICAT EXPORTED FUNCTION - EE_HANDLER , EE , EE_Read_LogFile 
 void EeHandlerReadFile ( void ) 
 {	 
 FILE_ID fdiID ;	 
 // UINT16 count ;	 
 // ERR_CODE ret_val ;	 
 EE_Entry_t LocalEntry = { 0 } ;	 
 UINT8 type_count [ EE_NUM_ENTRY_TYPES ] = { 0 } ;	 
 int iType ; // type of entry , enumerated 0 ..EE_NUM_ENTRY_TYPES	 
 char sw_version [ 10 ] ;	 
 const char* ver ;	 
	 
 // Get the version , other info is not required	 
 ver = " Hermon " ;	 
	 
 strncpy ( sw_version , ver , sizeof ( sw_version ) - 1 ) ;	 
	 
 fdiID = FDI_fopen ( eehLogFileName , " rb " ) ;	 
	 
 if ( fdiID != 0 )	 
 {		 
DIAGM_TRACE_1S( EE_HANDLER , EE , EE_SW_VERSION , " EE_SW_VERSION %s " , sw_version );  
		 
		 
 while ( ( /*count = */ FDI_fread ( &LocalEntry , sizeof ( EE_Entry_t ) , 1 , fdiID ) ) ==1 )		 
 {			 
 LocalEntry.fileWriteOffset = 0 ;			 
 if ( ( iType=EeHandlerPrintEntry ( &LocalEntry ) ) <EE_NUM_ENTRY_TYPES )			 
 type_count [ iType ] ++ ;			 
 }		 
 DIAGM_PRINT_TEXT ( " EEhandler - end of file " ) ;		 
		 
 /*mischecked by coverity*/		 
 /*coverity [ result_independent_of_operands ] */		 
DIAGM_TRACE_1( EE_HANDLER , EE , EE_SUMMARY1 , " RESET = %b " , type_count [ 0 ] );  
		 
 /*mischecked by coverity*/		 
 /*coverity [ result_independent_of_operands ] */		 
DIAGM_TRACE_1( EE_HANDLER , EE , EE_SUMMARY2 , " ASSERT = %b " , type_count [ 1 ] );  
		 
 /*mischecked by coverity*/		 
 /*coverity [ result_independent_of_operands ] */		 
DIAGM_TRACE_1( EE_HANDLER , EE , EE_SUMMARY3 , " EXCEPTION = %b " , type_count [ 2 ] );  
		 
 /*mischecked by coverity*/		 
 /*coverity [ result_independent_of_operands ] */		 
DIAGM_TRACE_1( EE_HANDLER , EE , EE_SUMMARY4 , " WARNING = %b " , type_count [ 3 ] );  
		 
 }	 
 else	 
 DIAGM_PRINT_TEXT ( " EEhandler - log file does not exist! " ) ;	 
	 
 // Closing file any way.	 
 /*ret_val = */ FDI_fclose ( fdiID ) ;	 
 }

//ICAT EXPORTED FUNCTION - EE_HANDLER , EE , EE_Delete_LogFile 
 void errHandlerDeleteLogFile ( void ) 
 {	 
 FDI_remove ( eehLogFileName ) ;	 
 DIAGM_PRINT_TEXT ( " EEhandler - Log file deleted " ) ;	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\EEHandler_fatal.ppp
//PPL Source File Name : \\softutil\\EEhandler\\src\\EEHandler_fatal.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef FILE* ( *fopen_t ) ( const char * , const char * ) ;
typedef int ( *fclose_t ) ( FILE* ) ;
typedef size_t ( *fread_t ) ( void * , size_t , size_t , FILE* ) ;
typedef size_t ( *fwrite_t ) ( const void * , size_t , size_t , FILE* ) ;
typedef int ( *fprintf_t ) ( FILE* , const char * , ... ) ;
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
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
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

typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure what deffered modes are Enabled*/	 
 EE_DEFER_NONE , /* @ENUM_VAL_DESC@ Defer no actions*/	 
 EE_DEFER_ASSERTS , /* @ENUM_VAL_DESC@ Defer asserts*/	 
 EE_DEFER_EXCEPTIONS , /* @ENUM_VAL_DESC@ Defer exceptions*/	 
 EE_DEFER_ALL /* @ENUM_VAL_DESC@ Defer all actions*/	 
 } EE_DeferredMode_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Deffered action configuration*/	 
 EE_DeferredMode_t enable ; /* @ITEM_DESC@ Configure what deffered modes are Enabled , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t deferIntermediateActions ; /* @ITEM_DESC@ Set defer intermidate actions , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT16 limitMs ; /* @ITEM_DESC@ deferred actions time limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF in milisec*/	 
 UINT16 limitHits ; /* @ITEM_DESC@ deferred actions hits limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF*/	 
 UINT16 reserved2 ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 } EE_DeferredCfg_t;

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
	 
 // -------- version 1 +D ----------	 
 EE_DeferredCfg_t deferredCfg ; /* @ITEM_DESC@ Deffered action configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
	 
	 
	 
 EE_WdtTimeCfg_t wdtConfigTime ; /* @ITEM_DESC@ WatchDog timer configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/ // UINT16	 
 UINT16 sysEeHandlerLimit ; /* @ITEM_DESC@ EE handler system limit ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 1 -0xFFFF , 0 -No limit*/ // relevant for EE_ASSISTING_MASTER only ; ZERO is no limits	 
 UINT32 dumpDdrSizeBytes ; /* @ITEM_DESC@ Limit DDR size to dump ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes , 0x1 -0x400 - No limit*/ // relevant for EE_ASSISTING_MASTER only	 
 UINT8 reserved [ 24 ] ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 UINT32 dumpResetFlag ; /*default is 0 . When finalAction is EE_RESET , 1 :dump and then silent reset ; 0 :silent reset without dump*/	 
 } EE_Configuration_t;

typedef void ( *WATCHDOG_Handler ) ( void ) ;
typedef void ( *WdtApps4comIntHandler ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 WDT_COM_RESET_DISABLE = 0 ,	 
 WDT_COM_RESET_IMMEDIATE ,	 
 WDT_COM_RESET_KEEP_PENDING	 
 } WdtComResetCfgType;

typedef UINT32 lowTaskEventHandler_t ;
typedef void ( *LowEventFuncPtr ) ( lowTaskEventHandler_t ) ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures Product Debug Level */	 
 PRODUCT_MODE = 0 , /* @ENUM_VAL_DESC@ Product Mode Debug level*/	 
 DEBUG_NORMAL = 1 , /* @ENUM_VAL_DESC@ Normal Debug level*/	 
 DEBUG_EXTEND = 2 /* @ENUM_VAL_DESC@ Extended Debug level*/	 
 } ProductDebugLevel_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures UART route */	 
 UART_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 UART_DATA_IO = 1 , /* @ENUM_VAL_DESC@ Route UART to DATA IO */	 
 UART_DIAG_ACAT = 2 , /* @ENUM_VAL_DESC@ Route UART to DIAG ACAT */	 
 UART_NULL = 0xFF /* @ENUM_VAL_DESC@ Disable*/	 
 } platformUART_route_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures DIAG route */	 
 DIAG_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 USB = 1 , /* @ENUM_VAL_DESC@ Route DIAG through USB*/	 
 UART = 2 /* @ENUM_VAL_DESC@ Route DIAG through UART*/	 
 } platformDIAG_route_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures USB detection*/	 
 USB_DETECT_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 USB_DETECT_ENABLE = 1 , /* @ENUM_VAL_DESC@ Enable USB detection*/	 
 USB_DETECT_DISABLE = 2 , /* @ENUM_VAL_DESC@ Disable USB detection*/	 
 USB_ALWAYS_CONNECT = 3 , /* @ENUM_VAL_DESC@ Always connect to USB*/	 
 USB_ALWAYS_DISCONNECT = 4 /* @ENUM_VAL_DESC@ Never connect to USB*/	 
 } platformUSBdetection_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures HeartBeat mode*/	 
 HB_DISABLE= 0 , /* @ENUM_VAL_DESC@ Disable heart beat*/	 
 TO_UART = 1 , /* @ENUM_VAL_DESC@ Send heart beat to UART*/	 
 TO_ACAT = 2 , /* @ENUM_VAL_DESC@ Send heart beat to ACAT*/	 
 ANOTHER = 3 /* @ENUM_VAL_DESC@ Reserved*/	 
 } platformHeartBeat_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures RTC Client*/	 
 RTC_CLIENT_DEFAULT = 0x0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 RTC_CLIENT_ENABLE = 1 , /* @ENUM_VAL_DESC@ Enable RTC client*/	 
 RTC_CLIENT_DISABLE = 2 /* @ENUM_VAL_DESC@ Disable RTC client*/	 
 } platformRtcClient_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures Relaiable Data load source*/	 
 RD_DEFAULT = 0x0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 RD_LOAD_CALIB_FILES_FROM_FLASH = 1 , /* @ENUM_VAL_DESC@ Load Callibration files from flash*/	 
 RD_DONT_LOAD_CALIB_FILES_FROM_FALSH = 2 /* @ENUM_VAL_DESC@ Don ' t load Callibration files from flash*/	 
 } platformRelaibeData_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure Comm-Apps sync*/	 
 PM_COMM_APPS_SYNC_DISABLED = 0 , /* @ENUM_VAL_DESC@ Disable Comm-Apps sync*/	 
 PM_COMM_APPS_SYNC_ENABLED = 1 /* @ENUM_VAL_DESC@ Enable Comm-Apps sync*/	 
 } nvmPM_CommAppsSync_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure Power Manager operation level*/	 
 PM_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 PM_FULL_ENABLE = 1 , /* @ENUM_VAL_DESC@ Enable Power Manager full functionality*/	 
 PM_DISABLE = 2 , /* @ENUM_VAL_DESC@ Disable Power Manager */	 
 PM_LEVEL_C1 = 3 , /* @ENUM_VAL_DESC@ Enable Power Manager C1 */	 
 PM_LEVEL_D2 = 4 /* @ENUM_VAL_DESC@ Enable Power Manager D2 */	 
 } nvmPM_level_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Set product point*/	 
 PP_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 PP_1 = 1 , /* @ENUM_VAL_DESC@ Set product point to 1 */	 
 PP_2 = 2 , /* @ENUM_VAL_DESC@ Set product point to 2 */	 
 PP_3 = 3 , /* @ENUM_VAL_DESC@ Set product point to 3 */	 
 PP_4 = 4 /* @ENUM_VAL_DESC@ Set product point to 4 */	 
 } nvmPM_ProductPoint_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PNVM_DEFAULT=0 ,	 
 PNVM_ENABLE ,	 
 PNVM_DISABLE	 
 } nvm_EN_DIS_DEF_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Configures Power Manager*/	 
 nvmPM_CommAppsSync_ts PM_AppsCommSyncEnabled ; /* @ITEM_DESC@ Configure Comm-Apps sync , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 nvmPM_ProductPoint_ts PM_ProductPoint ; /* @ITEM_DESC@ Set product point , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 nvmPM_level_ts PM_dbgLevel ; /* @ITEM_DESC@ Configure Power Manager operation level , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 nvm_EN_DIS_DEF_ts PM_newDDRHandshakeEnabled ;	 
 } platformPowerMngr_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures USIM error handling*/	 
 USIM_ERR_SILENT = 0 , /* @ENUM_VAL_DESC@ Silent error handling*/	 
 USIM_ERR_ASSERT = 1 , /* @ENUM_VAL_DESC@ Assert on error*/	 
 USIM_ERR_RECOVERY = 2 /* @ENUM_VAL_DESC@ error handling recovery*/	 
 } nvmUsimErrorHandler_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Configures USIM driver settings*/	 
 ProductDebugLevel_ts DebugLevel ; /* @ITEM_DESC@ Configures USIM Debug Level , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT8 TxDmaDisable ; /* @ITEM_DESC@ Configure Tx Dma Disable , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFF*/	 
 UINT8 DetectGpioPinNo ; /* @ITEM_DESC@ Set USIM detection GPIO , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Entries 1 -0xFF according to available GPIOs , 0 to diasble detection*/ // disable=0 , Detect_Pin=0xFF , others are GPIO / CGPIO pins	 
 nvmUsimErrorHandler_ts ErrorHandler ; /* @ITEM_DESC@ Configures USIM error handling , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 } platformUsim_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures AppCommMode*/	 
 APPCOMM_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 APPCOMM_COMM_IN_RESET = 1 , /* @ENUM_VAL_DESC@ Set Comm in reset*/	 
 APPCOMM_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force AppsComm enum long*/	 
 } platformAppsCommMode_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures OSA Error behavior*/	 
 OSA_ERROR_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 OSA_ERROR_ASSERT = 1 , /* @ENUM_VAL_DESC@ Assert on OSA errors*/	 
 OSA_ERROR_IGNORE = 2 , /* @ENUM_VAL_DESC@ Ignore OSA errors*/	 
 OSA_ERROR_RESTORE_OK = 3 , /* @ENUM_VAL_DESC@ OSA error restore*/	 
 OSA_ERROR_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force OSA error enum long*/	 
 } platformOsaErrBehavior_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures I2C FAST-SLOW mode*/	 
 NVM_I2C_CLK_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 NVM_I2C_SLOW_ClK_MODE = 0x00007fff , /* @ENUM_VAL_DESC@ Configure for slow mode align to I2c.h*/	 
 NVM_I2C_FAST_CLK_MODE = 0x00008000 , /* @ENUM_VAL_DESC@ Configure for fast mode align to I2c.h*/	 
 NVM_I2C_CLK_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force I2C error enum long*/	 
 } platfromI2cModeCfg_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures I2C repeat start configuration */	 
 NVM_I2C_REPEAT_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 NVM_I2C_NOT_REPEAT_START = 1 , /* @ENUM_VAL_DESC@ Configure for slow mode align to I2c.h*/	 
 NVM_I2C_REPEAT_START = 2 , /* @ENUM_VAL_DESC@ Configure for fast mode align to I2c.h*/	 
 NVM_I2C_REPEAT_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force I2C error enum long*/	 
 } platfromI2cRepeatCfg_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ I2C Configures */	 
 platfromI2cModeCfg_ts I2cClkMode ; /* @ITEM_DESC@ Configures I2C CLK mode FAST / SLOW , @ITEM_MODE@ Configuration , @ITEM_UNIT@ see enum*/	 
 platfromI2cRepeatCfg_ts I2cRptStrt ; /* @ITEM_DESC@ Configures I2C REPEAT_START mode yes / no , @ITEM_MODE@ Configuration , @ITEM_UNIT@ see enum*/	 
 } platfromI2cCfg_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Platfrom configuration */	 
 /* @STRUCT_NVM_FILE_NAME@ platfrom.nvm */	 
 ProductDebugLevel_ts ProductDebugLevel ; /* @ITEM_DESC@ Configures Product Debug Level , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
 UINT32 DelayMSEC_Startup ; /* @ITEM_DESC@ Startup Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_MSL ; /* @ITEM_DESC@ MSL Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_Audio ; /* @ITEM_DESC@ Audio Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_Power ; /* @ITEM_DESC@ Power Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_L1start ; /* @ITEM_DESC@ L1 start Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_reserv1 ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not Relevant*/	 
	 
 platformUART_route_ts UART_route ; /* @ITEM_DESC@ Configures UART route , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformDIAG_route_ts DIAG_route ; /* @ITEM_DESC@ Configures DIAG route , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformUSBdetection_ts USBdetection ; /* @ITEM_DESC@ Configures USB detection , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformHeartBeat_ts HeartBeat ; /* @ITEM_DESC@ Configures HeartBeat modes , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformPowerMngr_ts PowerManagement ; /* @ITEM_DESC@ Configures Power Manager , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
 platformRtcClient_ts RTC_Client ; /* @ITEM_DESC@ Configures RTC Client , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformRelaibeData_ts RD_LoadCalibFiles ; /* @ITEM_DESC@ Configures Relaiable Data load source , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
	 
 platformUsim_ts USIM ; /* @ITEM_DESC@ Configures USIM driver settings , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
 platformAppsCommMode_ts AppCommMode ; /* @ITEM_DESC@ Configures AppCommMode , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
 platformOsaErrBehavior_ts OsaErrBehavior ; /* @ITEM_DESC@ Configures OSA Error behavior , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platfromI2cCfg_ts NvmCfgI2C ; /* @ITEM_DESC@ Configures I2c CLK and REPEAT_START , @ITEM_MODE@ Configuration , @ITEM_UNIT@ see enum*/	 
 /* the reserved [ X ] must be update for backward	 
 * compatible if new fields are added to PlatformNvm_ts.	 
 * for example if you add UNIT32 you need to reduce X = X-4*/	 
 UINT8 reserved [ 44 ] ; /* @ITEM_DESC@ the amount of the reserved must be reduced if fields are added , @ITEM_MODE@ debugging , @ITEM_UNIT@ none*/	 
	 
 } PlatformNvm_ts;

typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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
typedef unsigned char UINT8 ;
typedef unsigned short UINT16 ;
typedef unsigned long UINT32 ;
typedef unsigned char Int8 ;
typedef unsigned short Int16 ;
typedef unsigned long Int32 ;
typedef void* ( *alloc_fn ) ( size_t size ) ;
typedef void ( *free_fn ) ( pmsg* msg ) ;
typedef int ( tpl_parse_t ) ( UINT8 , const unsigned char * , unsigned ) ;
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

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 char name [ ( 7 +1 ) ] ; // 8 bytes Name for the buffer to be accessed or saved into file	 
 UINT8* bufAddr ; // 4 bytes pointer to the buffer to be accessed or saved into file	 
 UINT32 bufLen ; // 4 bytes length of the buffer to be accessed or saved into file	 
 } EE_PostmortemDesc_Entry;

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
typedef UINT32 lfs_size_t ;
typedef UINT32 lfs_off_t ;
typedef int lfs_ssize_t ;
typedef int lfs_soff_t ;
typedef UINT32 lfs_block_t ;
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

DIAG_FILTER ( EE_HANDLER , EE_LOG , REENTRY , DIAG_INFORMATION)  
 diagPrintf ( " EE LOG: EE re-entry: %s , file: %s , line: %d " , pInfo->desc , pInfo->file , pInfo->line );

DIAG_FILTER ( EE_HANDLER , EE_LOG , DESC_LOG , DIAG_INFORMATION)  
 diagPrintf ( " EE LOG: DESC : %s , FILE : %s , LINE : %d " , pInfo->desc , pInfo->file , pInfo->line );

DIAG_FILTER ( EE_HANDLER , EE_LOG , REG_LOG , DIAG_INFORMATION)  
 diagPrintf ( " EE LOG: LR: 0x%lx , PC: 0x%lx , SP: 0x%lx " , __Saved_Registers.LR , __Saved_Registers.PC , __Saved_Registers.SP );

DIAG_FILTER ( EE_HANDLER , EE_LOG , TASK_LOG , DIAG_INFORMATION)  
 diagPrintf ( " EE LOG: Task: %s " , getCurrentTaskName ( ) );

DIAG_FILTER ( EE_HANDLER , EE_LOG , CustVersionInfo , DIAG_INFORMATION)  
 diagPrintf ( " EE LOG: Version: %s " , GetBuildVersion ( ) );

DIAG_FILTER ( EE_HANDLER , EE_LOG , RECENT_LOG , DIAG_INFORMATION)  
 diagPrintf ( " EE recent error log: %s " , PhysicalExcepBuffer_p [ _exceptionSRAMBufIndex ] .desc );

//ICAT EXPORTED FUNCTION - EE_HANDLER , EE , EE_Test_data_abort 
 void EeHandlerTestDataAbortExcep ( void ) 
 {	 
 int i=2 ;	 
 * ( volatile int* ) ( 0x1807bbff ) = i ;	 
 }

//ICAT EXPORTED FUNCTION - EE_HANDLER , EE , EE_Test_Assert 
 void EeHandlerTestAssert ( void ) 
 {	 
 { if ( ! ( 0 ) ) { utilsAssertFail ( " FALSE " , " EEHandler_fatal.c " , 2225 , 1 ) ; } } ;	 
 }

//ICAT EXPORTED FUNCTION - EE_HANDLER , EE , EE_Test_Warning 
 void EeHandlerTestWarning ( void ) 
 {	 
 { if ( ! ( 0 ) ) { utilsAssertFail ( 0 , " EEHandler_fatal.c " , 2231 , 0xFF ) ; } } ;	 
 }

//ICAT EXPORTED FUNCTION - EE_HANDLER , EE , EE_WarningFirstINFO 
 void EeHandlerWarningINFO ( void ) 
 {	 
 if ( eeWarningInfo.idx >= eeWarningInfo.cntr )	 
 {		 
DIAG_FILTER ( EE_HANDLER , EE_LOG , WARN_NOINFO , DIAG_INFORMATION)  
 diagPrintf ( " WARNING INFO: no new warnings " );

		 
 }	 
 else	 
 {		 
DIAG_FILTER ( EE_HANDLER , EE_LOG , WARN_INFO , DIAG_INFORMATION)  
 diagPrintf ( " WARNING INFO for no_%d from total %d: %s , line_%ld " , 
 ( eeWarningInfo.idx+1 ) , eeWarningInfo.cntr , eeWarningInfo.file , eeWarningInfo.line );

		 
		 
 if ( eeConfiguration.WarningHandlerOn == EE_WARN_ASSERTCONTINUE )		 
 {			 
DIAG_FILTER ( EE_HANDLER , EE_LOG , WARN_INFOEXT , DIAG_INFORMATION)  
 diagPrintf ( " EE WARNING no_%d: %s " , eeWarningInfo.cntr , PhysicalExcepBuffer_p [ _exceptionSRAMBufIndex ] .desc );

			 
 EeHandlerPrintEntry ( &PhysicalExcepBuffer_p [ _exceptionSRAMBufIndex ] ) ;			 
 }		 
		 
 eeWarningInfo.idx = eeWarningInfo.cntr ;		 
		 
 }	 
 }

//ICAT EXPORTED FUNCTION - EE_HANDLER , EE , EE_Test_Branch_Zero 
 void EeHandlerTestBranchZeroHandler ( void ) 
 {	 
 void ( *pFn ) ( void ) = 0 ;	 
	 
 /* Branch to zero */	 
 /*just a special test*/	 
 /*coverity [ var_deref_op ] */	 
 pFn ( ) ;	 
 }

DIAG_FILTER ( EE_HANDLER , EE_LOG , DEFERRED_LOG , DIAG_INFORMATION)  
 diagPrintf ( " EE DEFERRED ERROR: %s " , PhysicalExcepBuffer_p [ _exceptionSRAMBufIndex ] .desc );

DIAG_FILTER ( EE_HANDLER , EE_LOG , YMODEMENUM , DIAG_INFORMATION)  
 diagPrintf ( " EE LOG: Start enum ymodem device " );

DIAG_FILTER ( EE_HANDLER , EE_LOG , DEFERRED_LOG_END , DIAG_INFORMATION)  
 diagPrintf ( " EE LOG: COM BINS DUMP FINISHED " );

DIAG_FILTER ( EE_HANDLER , EE_LOG , RESET_BOARD , DIAG_INFORMATION)  
 diagPrintf ( " EE LOG: You can reset board now...... " );

DIAG_FILTER ( EE_HANDLER , EE_LOG , StartSilentReset , DIAG_INFORMATION)  
 diagPrintf ( " ---- Start Silent Reset ---- " );

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\EEHandler_config.ppp
//PPL Source File Name : \\softutil\\EEhandler\\src\\EEHandler_config.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure what deffered modes are Enabled*/	 
 EE_DEFER_NONE , /* @ENUM_VAL_DESC@ Defer no actions*/	 
 EE_DEFER_ASSERTS , /* @ENUM_VAL_DESC@ Defer asserts*/	 
 EE_DEFER_EXCEPTIONS , /* @ENUM_VAL_DESC@ Defer exceptions*/	 
 EE_DEFER_ALL /* @ENUM_VAL_DESC@ Defer all actions*/	 
 } EE_DeferredMode_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Deffered action configuration*/	 
 EE_DeferredMode_t enable ; /* @ITEM_DESC@ Configure what deffered modes are Enabled , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t deferIntermediateActions ; /* @ITEM_DESC@ Set defer intermidate actions , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT16 limitMs ; /* @ITEM_DESC@ deferred actions time limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF in milisec*/	 
 UINT16 limitHits ; /* @ITEM_DESC@ deferred actions hits limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF*/	 
 UINT16 reserved2 ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 } EE_DeferredCfg_t;

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
	 
 // -------- version 1 +D ----------	 
 EE_DeferredCfg_t deferredCfg ; /* @ITEM_DESC@ Deffered action configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
	 
	 
	 
 EE_WdtTimeCfg_t wdtConfigTime ; /* @ITEM_DESC@ WatchDog timer configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/ // UINT16	 
 UINT16 sysEeHandlerLimit ; /* @ITEM_DESC@ EE handler system limit ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 1 -0xFFFF , 0 -No limit*/ // relevant for EE_ASSISTING_MASTER only ; ZERO is no limits	 
 UINT32 dumpDdrSizeBytes ; /* @ITEM_DESC@ Limit DDR size to dump ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes , 0x1 -0x400 - No limit*/ // relevant for EE_ASSISTING_MASTER only	 
 UINT8 reserved [ 24 ] ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 UINT32 dumpResetFlag ; /*default is 0 . When finalAction is EE_RESET , 1 :dump and then silent reset ; 0 :silent reset without dump*/	 
 } EE_Configuration_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 char name [ ( 7 +1 ) ] ; // 8 bytes Name for the buffer to be accessed or saved into file	 
 UINT8* bufAddr ; // 4 bytes pointer to the buffer to be accessed or saved into file	 
 UINT32 bufLen ; // 4 bytes length of the buffer to be accessed or saved into file	 
 } EE_PostmortemDesc_Entry;

typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
//ICAT EXPORTED FUNCTION - EE_HANDLER , EE , eePrintConfiguration 
 void eePrintConfiguration ( void ) 
 {	 
	 
DIAG_FILTER ( EE_HANDLER , EE , EE_CONFIG_PRINT , DIAG_INFORMATION)  
 diagStructPrintf ( " EE CONFIGURATION: %S { EE_Configuration_t } " , &eeConfiguration , sizeof ( eeConfiguration ) );

	 
	 
 }

//ICAT EXPORTED FUNCTION - EE_HANDLER , EE , eeSetConfiguration 
 void eeSetConfiguration ( const EE_Configuration_t* pConfig , int len ) 
 {	 
 eeConfiguration=eeDefaultConfiguration ;	 
	 
 if ( pConfig && len>0 )	 
 {		 
 memcpy ( &eeConfiguration , pConfig , ( ( ( len ) < ( sizeof ( EE_Configuration_t ) ) ) ? ( len ) : ( sizeof ( EE_Configuration_t ) ) ) ) ;		 
 }	 
	 
 eePrintConfiguration ( ) ;	 
	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\EEHandler_handlers.ppp
//PPL Source File Name : \\softutil\\EEhandler\\src\\EEHandler_handlers.c
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
typedef unsigned int size_t ;
typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
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

typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure what deffered modes are Enabled*/	 
 EE_DEFER_NONE , /* @ENUM_VAL_DESC@ Defer no actions*/	 
 EE_DEFER_ASSERTS , /* @ENUM_VAL_DESC@ Defer asserts*/	 
 EE_DEFER_EXCEPTIONS , /* @ENUM_VAL_DESC@ Defer exceptions*/	 
 EE_DEFER_ALL /* @ENUM_VAL_DESC@ Defer all actions*/	 
 } EE_DeferredMode_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Deffered action configuration*/	 
 EE_DeferredMode_t enable ; /* @ITEM_DESC@ Configure what deffered modes are Enabled , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t deferIntermediateActions ; /* @ITEM_DESC@ Set defer intermidate actions , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT16 limitMs ; /* @ITEM_DESC@ deferred actions time limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF in milisec*/	 
 UINT16 limitHits ; /* @ITEM_DESC@ deferred actions hits limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF*/	 
 UINT16 reserved2 ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 } EE_DeferredCfg_t;

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
	 
 // -------- version 1 +D ----------	 
 EE_DeferredCfg_t deferredCfg ; /* @ITEM_DESC@ Deffered action configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
	 
	 
	 
 EE_WdtTimeCfg_t wdtConfigTime ; /* @ITEM_DESC@ WatchDog timer configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/ // UINT16	 
 UINT16 sysEeHandlerLimit ; /* @ITEM_DESC@ EE handler system limit ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 1 -0xFFFF , 0 -No limit*/ // relevant for EE_ASSISTING_MASTER only ; ZERO is no limits	 
 UINT32 dumpDdrSizeBytes ; /* @ITEM_DESC@ Limit DDR size to dump ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes , 0x1 -0x400 - No limit*/ // relevant for EE_ASSISTING_MASTER only	 
 UINT8 reserved [ 24 ] ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 UINT32 dumpResetFlag ; /*default is 0 . When finalAction is EE_RESET , 1 :dump and then silent reset ; 0 :silent reset without dump*/	 
 } EE_Configuration_t;

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\EEHandler_Serial.ppp
//PPL Source File Name : \\softutil\\EEhandler\\src\\EEHandler_Serial.c
typedef unsigned int size_t ;
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
typedef void ( *WATCHDOG_Handler ) ( void ) ;
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
//ICAT EXPORTED FUNCTION - EE_HANDLER , EE , eeSerialOutputBind 
 void eeSerialOutputBind ( void ) 
 {	 
 /*pfnOldAction = */ EEHandlerExternalFinalActionBind ( finalActionSerialLoop ) ;	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\EE_Postmortem.ppp
//PPL Source File Name : \\softutil\\EEhandler\\src\\EE_Postmortem.c
typedef unsigned int size_t ;
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
typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
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

typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure what deffered modes are Enabled*/	 
 EE_DEFER_NONE , /* @ENUM_VAL_DESC@ Defer no actions*/	 
 EE_DEFER_ASSERTS , /* @ENUM_VAL_DESC@ Defer asserts*/	 
 EE_DEFER_EXCEPTIONS , /* @ENUM_VAL_DESC@ Defer exceptions*/	 
 EE_DEFER_ALL /* @ENUM_VAL_DESC@ Defer all actions*/	 
 } EE_DeferredMode_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Deffered action configuration*/	 
 EE_DeferredMode_t enable ; /* @ITEM_DESC@ Configure what deffered modes are Enabled , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t deferIntermediateActions ; /* @ITEM_DESC@ Set defer intermidate actions , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT16 limitMs ; /* @ITEM_DESC@ deferred actions time limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF in milisec*/	 
 UINT16 limitHits ; /* @ITEM_DESC@ deferred actions hits limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF*/	 
 UINT16 reserved2 ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 } EE_DeferredCfg_t;

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
	 
 // -------- version 1 +D ----------	 
 EE_DeferredCfg_t deferredCfg ; /* @ITEM_DESC@ Deffered action configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
	 
	 
	 
 EE_WdtTimeCfg_t wdtConfigTime ; /* @ITEM_DESC@ WatchDog timer configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/ // UINT16	 
 UINT16 sysEeHandlerLimit ; /* @ITEM_DESC@ EE handler system limit ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 1 -0xFFFF , 0 -No limit*/ // relevant for EE_ASSISTING_MASTER only ; ZERO is no limits	 
 UINT32 dumpDdrSizeBytes ; /* @ITEM_DESC@ Limit DDR size to dump ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes , 0x1 -0x400 - No limit*/ // relevant for EE_ASSISTING_MASTER only	 
 UINT8 reserved [ 24 ] ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 UINT32 dumpResetFlag ; /*default is 0 . When finalAction is EE_RESET , 1 :dump and then silent reset ; 0 :silent reset without dump*/	 
 } EE_Configuration_t;

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
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 char name [ ( 7 +1 ) ] ; // 8 bytes Name for the buffer to be accessed or saved into file	 
 UINT8* bufAddr ; // 4 bytes pointer to the buffer to be accessed or saved into file	 
 UINT32 bufLen ; // 4 bytes length of the buffer to be accessed or saved into file	 
 } EE_PostmortemDesc_Entry;

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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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

DIAG_FILTER ( SW_PLAT , PERFORMANCE , SAVE2FILE0 , DIAG_INFORMATION)  
 diagPrintf ( " COMM MEM-DUMP File %s: nothing to save " , fNameBuf );

//ICAT EXPORTED FUNCTION - Diag , comMem , SaveComPostmortemEx 
 void SaveComPostmortemEx ( void ) 
 {	 
 /*Fixed coverity [ returned_pointer ] */	 
	 
	 
	 
 EE_PostmortemDesc_Entry* p = 0 ;	 
	 
	 
 p = getEntryNext ( 1 /*getFirst*/ ) ;	 
 while ( p != ( ( EE_PostmortemDesc_Entry* ) 0xDEADDEAD ) )	 
 {		 
		 
 SaveToFileEx ( p->name , ( ( UINT8* ) ( ( UINT32 ) ( p->bufAddr ) ) ) , p->bufLen ) ;		 
 p = getEntryNext ( 0 /*getFirst*/ ) ;		 
 }	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\EE_wdtManager.ppp
//PPL Source File Name : \\softutil\\EEhandler\\src\\EE_wdtManager.c
typedef unsigned int size_t ;
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
typedef va_list __gnuc_va_list ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure what deffered modes are Enabled*/	 
 EE_DEFER_NONE , /* @ENUM_VAL_DESC@ Defer no actions*/	 
 EE_DEFER_ASSERTS , /* @ENUM_VAL_DESC@ Defer asserts*/	 
 EE_DEFER_EXCEPTIONS , /* @ENUM_VAL_DESC@ Defer exceptions*/	 
 EE_DEFER_ALL /* @ENUM_VAL_DESC@ Defer all actions*/	 
 } EE_DeferredMode_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Deffered action configuration*/	 
 EE_DeferredMode_t enable ; /* @ITEM_DESC@ Configure what deffered modes are Enabled , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t deferIntermediateActions ; /* @ITEM_DESC@ Set defer intermidate actions , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT16 limitMs ; /* @ITEM_DESC@ deferred actions time limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF in milisec*/	 
 UINT16 limitHits ; /* @ITEM_DESC@ deferred actions hits limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF*/	 
 UINT16 reserved2 ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 } EE_DeferredCfg_t;

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
	 
 // -------- version 1 +D ----------	 
 EE_DeferredCfg_t deferredCfg ; /* @ITEM_DESC@ Deffered action configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
	 
	 
	 
 EE_WdtTimeCfg_t wdtConfigTime ; /* @ITEM_DESC@ WatchDog timer configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/ // UINT16	 
 UINT16 sysEeHandlerLimit ; /* @ITEM_DESC@ EE handler system limit ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 1 -0xFFFF , 0 -No limit*/ // relevant for EE_ASSISTING_MASTER only ; ZERO is no limits	 
 UINT32 dumpDdrSizeBytes ; /* @ITEM_DESC@ Limit DDR size to dump ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes , 0x1 -0x400 - No limit*/ // relevant for EE_ASSISTING_MASTER only	 
 UINT8 reserved [ 24 ] ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 UINT32 dumpResetFlag ; /*default is 0 . When finalAction is EE_RESET , 1 :dump and then silent reset ; 0 :silent reset without dump*/	 
 } EE_Configuration_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 char name [ ( 7 +1 ) ] ; // 8 bytes Name for the buffer to be accessed or saved into file	 
 UINT8* bufAddr ; // 4 bytes pointer to the buffer to be accessed or saved into file	 
 UINT32 bufLen ; // 4 bytes length of the buffer to be accessed or saved into file	 
 } EE_PostmortemDesc_Entry;

typedef void ( *WATCHDOG_Handler ) ( void ) ;
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
typedef void ( * void_pF_UINT32 ) ( UINT32 tmrId ) ;
//ICAT EXPORTED FUNCTION - EE_HANDLER , WDT , PrintTrace 
 void eeWdtPrintTrace ( void ) 
 {	 
DIAG_FILTER ( EE_HANDLER , EE_LOG , WDTtrace , DIAG_INFORMATION)  
 diagPrintf ( " EE-WATCHDOG TRACE counters of 13 MHz cycles: %lx / %lx , %lx / %lx " , 
 eeWdtTraceBuf [ 0 ] .apdc , eeWdtTraceBuf [ 0 ] .timer32k , 
 eeWdtTraceBuf [ 1 ] .apdc , eeWdtTraceBuf [ 1 ] .timer32k );

	 
 }

//ICAT EXPORTED FUNCTION - EE_HANDLER , WDT , eeWdtMgrCfg 
 void eeWdtMgrCfg_ACAT ( UINT32* p ) 
 {	 
 eeWdtMgrCfg ( ( EeWdtMgrModes ) ( *p ) ) ;	 
 }

//ICAT EXPORTED FUNCTION - HW_PLAT , utilities , TriggerWDTInt 
 void TriggerWDTInt ( void ) 
 {	 
 unsigned int cpsr , timestamp ;	 
	 
 { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " TriggerWDTInt " ) ; } } ;	 
	 
 cpsr = disableInterrupts ( ) ;	 
 timestamp = timerCountRead ( TCR_2 ) ;	 
	 
	 
 while ( ( timerCountRead ( TCR_2 ) - timestamp ) < 32768 *20 )	 
 {		 
		 
 }	 
	 
 restoreInterrupts ( cpsr ) ;	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\EE_DSP_Data.ppp
//PPL Source File Name : \\softutil\\EEhandler\\src\\EE_DSP_Data.c
//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\EEHandler_hal.ppp
//PPL Source File Name : \\softutil\\EEhandler\\src\\EEHandler_hal.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef FILE* ( *fopen_t ) ( const char * , const char * ) ;
typedef int ( *fclose_t ) ( FILE* ) ;
typedef size_t ( *fread_t ) ( void * , size_t , size_t , FILE* ) ;
typedef size_t ( *fwrite_t ) ( const void * , size_t , size_t , FILE* ) ;
typedef int ( *fprintf_t ) ( FILE* , const char * , ... ) ;
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
typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
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

typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure what deffered modes are Enabled*/	 
 EE_DEFER_NONE , /* @ENUM_VAL_DESC@ Defer no actions*/	 
 EE_DEFER_ASSERTS , /* @ENUM_VAL_DESC@ Defer asserts*/	 
 EE_DEFER_EXCEPTIONS , /* @ENUM_VAL_DESC@ Defer exceptions*/	 
 EE_DEFER_ALL /* @ENUM_VAL_DESC@ Defer all actions*/	 
 } EE_DeferredMode_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Deffered action configuration*/	 
 EE_DeferredMode_t enable ; /* @ITEM_DESC@ Configure what deffered modes are Enabled , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 EE_OnOff_t deferIntermediateActions ; /* @ITEM_DESC@ Set defer intermidate actions , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT16 limitMs ; /* @ITEM_DESC@ deferred actions time limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF in milisec*/	 
 UINT16 limitHits ; /* @ITEM_DESC@ deferred actions hits limit , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFF*/	 
 UINT16 reserved2 ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 } EE_DeferredCfg_t;

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
	 
 // -------- version 1 +D ----------	 
 EE_DeferredCfg_t deferredCfg ; /* @ITEM_DESC@ Deffered action configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
	 
	 
	 
 EE_WdtTimeCfg_t wdtConfigTime ; /* @ITEM_DESC@ WatchDog timer configuration , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/ // UINT16	 
 UINT16 sysEeHandlerLimit ; /* @ITEM_DESC@ EE handler system limit ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 1 -0xFFFF , 0 -No limit*/ // relevant for EE_ASSISTING_MASTER only ; ZERO is no limits	 
 UINT32 dumpDdrSizeBytes ; /* @ITEM_DESC@ Limit DDR size to dump ( only EE_ASSISTING_MASTER ) , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFFFFFFFF in bytes , 0x1 -0x400 - No limit*/ // relevant for EE_ASSISTING_MASTER only	 
 UINT8 reserved [ 24 ] ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not relevant*/	 
 UINT32 dumpResetFlag ; /*default is 0 . When finalAction is EE_RESET , 1 :dump and then silent reset ; 0 :silent reset without dump*/	 
 } EE_Configuration_t;

typedef void ( *WATCHDOG_Handler ) ( void ) ;
typedef void ( *WdtApps4comIntHandler ) ( void ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 WDT_COM_RESET_DISABLE = 0 ,	 
 WDT_COM_RESET_IMMEDIATE ,	 
 WDT_COM_RESET_KEEP_PENDING	 
 } WdtComResetCfgType;

typedef UINT32 lowTaskEventHandler_t ;
typedef void ( *LowEventFuncPtr ) ( lowTaskEventHandler_t ) ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures Product Debug Level */	 
 PRODUCT_MODE = 0 , /* @ENUM_VAL_DESC@ Product Mode Debug level*/	 
 DEBUG_NORMAL = 1 , /* @ENUM_VAL_DESC@ Normal Debug level*/	 
 DEBUG_EXTEND = 2 /* @ENUM_VAL_DESC@ Extended Debug level*/	 
 } ProductDebugLevel_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures UART route */	 
 UART_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 UART_DATA_IO = 1 , /* @ENUM_VAL_DESC@ Route UART to DATA IO */	 
 UART_DIAG_ACAT = 2 , /* @ENUM_VAL_DESC@ Route UART to DIAG ACAT */	 
 UART_NULL = 0xFF /* @ENUM_VAL_DESC@ Disable*/	 
 } platformUART_route_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures DIAG route */	 
 DIAG_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 USB = 1 , /* @ENUM_VAL_DESC@ Route DIAG through USB*/	 
 UART = 2 /* @ENUM_VAL_DESC@ Route DIAG through UART*/	 
 } platformDIAG_route_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures USB detection*/	 
 USB_DETECT_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 USB_DETECT_ENABLE = 1 , /* @ENUM_VAL_DESC@ Enable USB detection*/	 
 USB_DETECT_DISABLE = 2 , /* @ENUM_VAL_DESC@ Disable USB detection*/	 
 USB_ALWAYS_CONNECT = 3 , /* @ENUM_VAL_DESC@ Always connect to USB*/	 
 USB_ALWAYS_DISCONNECT = 4 /* @ENUM_VAL_DESC@ Never connect to USB*/	 
 } platformUSBdetection_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures HeartBeat mode*/	 
 HB_DISABLE= 0 , /* @ENUM_VAL_DESC@ Disable heart beat*/	 
 TO_UART = 1 , /* @ENUM_VAL_DESC@ Send heart beat to UART*/	 
 TO_ACAT = 2 , /* @ENUM_VAL_DESC@ Send heart beat to ACAT*/	 
 ANOTHER = 3 /* @ENUM_VAL_DESC@ Reserved*/	 
 } platformHeartBeat_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures RTC Client*/	 
 RTC_CLIENT_DEFAULT = 0x0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 RTC_CLIENT_ENABLE = 1 , /* @ENUM_VAL_DESC@ Enable RTC client*/	 
 RTC_CLIENT_DISABLE = 2 /* @ENUM_VAL_DESC@ Disable RTC client*/	 
 } platformRtcClient_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures Relaiable Data load source*/	 
 RD_DEFAULT = 0x0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 RD_LOAD_CALIB_FILES_FROM_FLASH = 1 , /* @ENUM_VAL_DESC@ Load Callibration files from flash*/	 
 RD_DONT_LOAD_CALIB_FILES_FROM_FALSH = 2 /* @ENUM_VAL_DESC@ Don ' t load Callibration files from flash*/	 
 } platformRelaibeData_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure Comm-Apps sync*/	 
 PM_COMM_APPS_SYNC_DISABLED = 0 , /* @ENUM_VAL_DESC@ Disable Comm-Apps sync*/	 
 PM_COMM_APPS_SYNC_ENABLED = 1 /* @ENUM_VAL_DESC@ Enable Comm-Apps sync*/	 
 } nvmPM_CommAppsSync_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure Power Manager operation level*/	 
 PM_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 PM_FULL_ENABLE = 1 , /* @ENUM_VAL_DESC@ Enable Power Manager full functionality*/	 
 PM_DISABLE = 2 , /* @ENUM_VAL_DESC@ Disable Power Manager */	 
 PM_LEVEL_C1 = 3 , /* @ENUM_VAL_DESC@ Enable Power Manager C1 */	 
 PM_LEVEL_D2 = 4 /* @ENUM_VAL_DESC@ Enable Power Manager D2 */	 
 } nvmPM_level_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Set product point*/	 
 PP_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 PP_1 = 1 , /* @ENUM_VAL_DESC@ Set product point to 1 */	 
 PP_2 = 2 , /* @ENUM_VAL_DESC@ Set product point to 2 */	 
 PP_3 = 3 , /* @ENUM_VAL_DESC@ Set product point to 3 */	 
 PP_4 = 4 /* @ENUM_VAL_DESC@ Set product point to 4 */	 
 } nvmPM_ProductPoint_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PNVM_DEFAULT=0 ,	 
 PNVM_ENABLE ,	 
 PNVM_DISABLE	 
 } nvm_EN_DIS_DEF_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Configures Power Manager*/	 
 nvmPM_CommAppsSync_ts PM_AppsCommSyncEnabled ; /* @ITEM_DESC@ Configure Comm-Apps sync , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 nvmPM_ProductPoint_ts PM_ProductPoint ; /* @ITEM_DESC@ Set product point , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 nvmPM_level_ts PM_dbgLevel ; /* @ITEM_DESC@ Configure Power Manager operation level , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 nvm_EN_DIS_DEF_ts PM_newDDRHandshakeEnabled ;	 
 } platformPowerMngr_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures USIM error handling*/	 
 USIM_ERR_SILENT = 0 , /* @ENUM_VAL_DESC@ Silent error handling*/	 
 USIM_ERR_ASSERT = 1 , /* @ENUM_VAL_DESC@ Assert on error*/	 
 USIM_ERR_RECOVERY = 2 /* @ENUM_VAL_DESC@ error handling recovery*/	 
 } nvmUsimErrorHandler_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Configures USIM driver settings*/	 
 ProductDebugLevel_ts DebugLevel ; /* @ITEM_DESC@ Configures USIM Debug Level , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT8 TxDmaDisable ; /* @ITEM_DESC@ Configure Tx Dma Disable , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFF*/	 
 UINT8 DetectGpioPinNo ; /* @ITEM_DESC@ Set USIM detection GPIO , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Entries 1 -0xFF according to available GPIOs , 0 to diasble detection*/ // disable=0 , Detect_Pin=0xFF , others are GPIO / CGPIO pins	 
 nvmUsimErrorHandler_ts ErrorHandler ; /* @ITEM_DESC@ Configures USIM error handling , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 } platformUsim_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures AppCommMode*/	 
 APPCOMM_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 APPCOMM_COMM_IN_RESET = 1 , /* @ENUM_VAL_DESC@ Set Comm in reset*/	 
 APPCOMM_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force AppsComm enum long*/	 
 } platformAppsCommMode_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures OSA Error behavior*/	 
 OSA_ERROR_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 OSA_ERROR_ASSERT = 1 , /* @ENUM_VAL_DESC@ Assert on OSA errors*/	 
 OSA_ERROR_IGNORE = 2 , /* @ENUM_VAL_DESC@ Ignore OSA errors*/	 
 OSA_ERROR_RESTORE_OK = 3 , /* @ENUM_VAL_DESC@ OSA error restore*/	 
 OSA_ERROR_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force OSA error enum long*/	 
 } platformOsaErrBehavior_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures I2C FAST-SLOW mode*/	 
 NVM_I2C_CLK_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 NVM_I2C_SLOW_ClK_MODE = 0x00007fff , /* @ENUM_VAL_DESC@ Configure for slow mode align to I2c.h*/	 
 NVM_I2C_FAST_CLK_MODE = 0x00008000 , /* @ENUM_VAL_DESC@ Configure for fast mode align to I2c.h*/	 
 NVM_I2C_CLK_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force I2C error enum long*/	 
 } platfromI2cModeCfg_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures I2C repeat start configuration */	 
 NVM_I2C_REPEAT_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 NVM_I2C_NOT_REPEAT_START = 1 , /* @ENUM_VAL_DESC@ Configure for slow mode align to I2c.h*/	 
 NVM_I2C_REPEAT_START = 2 , /* @ENUM_VAL_DESC@ Configure for fast mode align to I2c.h*/	 
 NVM_I2C_REPEAT_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force I2C error enum long*/	 
 } platfromI2cRepeatCfg_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ I2C Configures */	 
 platfromI2cModeCfg_ts I2cClkMode ; /* @ITEM_DESC@ Configures I2C CLK mode FAST / SLOW , @ITEM_MODE@ Configuration , @ITEM_UNIT@ see enum*/	 
 platfromI2cRepeatCfg_ts I2cRptStrt ; /* @ITEM_DESC@ Configures I2C REPEAT_START mode yes / no , @ITEM_MODE@ Configuration , @ITEM_UNIT@ see enum*/	 
 } platfromI2cCfg_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Platfrom configuration */	 
 /* @STRUCT_NVM_FILE_NAME@ platfrom.nvm */	 
 ProductDebugLevel_ts ProductDebugLevel ; /* @ITEM_DESC@ Configures Product Debug Level , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
 UINT32 DelayMSEC_Startup ; /* @ITEM_DESC@ Startup Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_MSL ; /* @ITEM_DESC@ MSL Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_Audio ; /* @ITEM_DESC@ Audio Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_Power ; /* @ITEM_DESC@ Power Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_L1start ; /* @ITEM_DESC@ L1 start Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_reserv1 ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not Relevant*/	 
	 
 platformUART_route_ts UART_route ; /* @ITEM_DESC@ Configures UART route , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformDIAG_route_ts DIAG_route ; /* @ITEM_DESC@ Configures DIAG route , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformUSBdetection_ts USBdetection ; /* @ITEM_DESC@ Configures USB detection , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformHeartBeat_ts HeartBeat ; /* @ITEM_DESC@ Configures HeartBeat modes , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformPowerMngr_ts PowerManagement ; /* @ITEM_DESC@ Configures Power Manager , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
 platformRtcClient_ts RTC_Client ; /* @ITEM_DESC@ Configures RTC Client , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformRelaibeData_ts RD_LoadCalibFiles ; /* @ITEM_DESC@ Configures Relaiable Data load source , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
	 
 platformUsim_ts USIM ; /* @ITEM_DESC@ Configures USIM driver settings , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
 platformAppsCommMode_ts AppCommMode ; /* @ITEM_DESC@ Configures AppCommMode , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
 platformOsaErrBehavior_ts OsaErrBehavior ; /* @ITEM_DESC@ Configures OSA Error behavior , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platfromI2cCfg_ts NvmCfgI2C ; /* @ITEM_DESC@ Configures I2c CLK and REPEAT_START , @ITEM_MODE@ Configuration , @ITEM_UNIT@ see enum*/	 
 /* the reserved [ X ] must be update for backward	 
 * compatible if new fields are added to PlatformNvm_ts.	 
 * for example if you add UNIT32 you need to reduce X = X-4*/	 
 UINT8 reserved [ 44 ] ; /* @ITEM_DESC@ the amount of the reserved must be reduced if fields are added , @ITEM_MODE@ debugging , @ITEM_UNIT@ none*/	 
	 
 } PlatformNvm_ts;

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
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 char name [ ( 7 +1 ) ] ; // 8 bytes Name for the buffer to be accessed or saved into file	 
 UINT8* bufAddr ; // 4 bytes pointer to the buffer to be accessed or saved into file	 
 UINT32 bufLen ; // 4 bytes length of the buffer to be accessed or saved into file	 
 } EE_PostmortemDesc_Entry;

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\EE_silentReset.ppp
//PPL Source File Name : \\softutil\\EEhandler\\src\\EE_silentReset.c
typedef unsigned int size_t ;
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
typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
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
//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\platform_nvm.ppp
//PPL Source File Name : \\softutil\\nvm\\src\\platform_nvm.c
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
typedef unsigned int size_t ;
typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
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

typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
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
 /* @ENUM_DESC@ Configures Product Debug Level */	 
 PRODUCT_MODE = 0 , /* @ENUM_VAL_DESC@ Product Mode Debug level*/	 
 DEBUG_NORMAL = 1 , /* @ENUM_VAL_DESC@ Normal Debug level*/	 
 DEBUG_EXTEND = 2 /* @ENUM_VAL_DESC@ Extended Debug level*/	 
 } ProductDebugLevel_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures UART route */	 
 UART_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 UART_DATA_IO = 1 , /* @ENUM_VAL_DESC@ Route UART to DATA IO */	 
 UART_DIAG_ACAT = 2 , /* @ENUM_VAL_DESC@ Route UART to DIAG ACAT */	 
 UART_NULL = 0xFF /* @ENUM_VAL_DESC@ Disable*/	 
 } platformUART_route_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures DIAG route */	 
 DIAG_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 USB = 1 , /* @ENUM_VAL_DESC@ Route DIAG through USB*/	 
 UART = 2 /* @ENUM_VAL_DESC@ Route DIAG through UART*/	 
 } platformDIAG_route_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures USB detection*/	 
 USB_DETECT_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 USB_DETECT_ENABLE = 1 , /* @ENUM_VAL_DESC@ Enable USB detection*/	 
 USB_DETECT_DISABLE = 2 , /* @ENUM_VAL_DESC@ Disable USB detection*/	 
 USB_ALWAYS_CONNECT = 3 , /* @ENUM_VAL_DESC@ Always connect to USB*/	 
 USB_ALWAYS_DISCONNECT = 4 /* @ENUM_VAL_DESC@ Never connect to USB*/	 
 } platformUSBdetection_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures HeartBeat mode*/	 
 HB_DISABLE= 0 , /* @ENUM_VAL_DESC@ Disable heart beat*/	 
 TO_UART = 1 , /* @ENUM_VAL_DESC@ Send heart beat to UART*/	 
 TO_ACAT = 2 , /* @ENUM_VAL_DESC@ Send heart beat to ACAT*/	 
 ANOTHER = 3 /* @ENUM_VAL_DESC@ Reserved*/	 
 } platformHeartBeat_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures RTC Client*/	 
 RTC_CLIENT_DEFAULT = 0x0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 RTC_CLIENT_ENABLE = 1 , /* @ENUM_VAL_DESC@ Enable RTC client*/	 
 RTC_CLIENT_DISABLE = 2 /* @ENUM_VAL_DESC@ Disable RTC client*/	 
 } platformRtcClient_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures Relaiable Data load source*/	 
 RD_DEFAULT = 0x0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 RD_LOAD_CALIB_FILES_FROM_FLASH = 1 , /* @ENUM_VAL_DESC@ Load Callibration files from flash*/	 
 RD_DONT_LOAD_CALIB_FILES_FROM_FALSH = 2 /* @ENUM_VAL_DESC@ Don ' t load Callibration files from flash*/	 
 } platformRelaibeData_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure Comm-Apps sync*/	 
 PM_COMM_APPS_SYNC_DISABLED = 0 , /* @ENUM_VAL_DESC@ Disable Comm-Apps sync*/	 
 PM_COMM_APPS_SYNC_ENABLED = 1 /* @ENUM_VAL_DESC@ Enable Comm-Apps sync*/	 
 } nvmPM_CommAppsSync_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configure Power Manager operation level*/	 
 PM_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 PM_FULL_ENABLE = 1 , /* @ENUM_VAL_DESC@ Enable Power Manager full functionality*/	 
 PM_DISABLE = 2 , /* @ENUM_VAL_DESC@ Disable Power Manager */	 
 PM_LEVEL_C1 = 3 , /* @ENUM_VAL_DESC@ Enable Power Manager C1 */	 
 PM_LEVEL_D2 = 4 /* @ENUM_VAL_DESC@ Enable Power Manager D2 */	 
 } nvmPM_level_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Set product point*/	 
 PP_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 PP_1 = 1 , /* @ENUM_VAL_DESC@ Set product point to 1 */	 
 PP_2 = 2 , /* @ENUM_VAL_DESC@ Set product point to 2 */	 
 PP_3 = 3 , /* @ENUM_VAL_DESC@ Set product point to 3 */	 
 PP_4 = 4 /* @ENUM_VAL_DESC@ Set product point to 4 */	 
 } nvmPM_ProductPoint_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 PNVM_DEFAULT=0 ,	 
 PNVM_ENABLE ,	 
 PNVM_DISABLE	 
 } nvm_EN_DIS_DEF_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Configures Power Manager*/	 
 nvmPM_CommAppsSync_ts PM_AppsCommSyncEnabled ; /* @ITEM_DESC@ Configure Comm-Apps sync , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 nvmPM_ProductPoint_ts PM_ProductPoint ; /* @ITEM_DESC@ Set product point , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 nvmPM_level_ts PM_dbgLevel ; /* @ITEM_DESC@ Configure Power Manager operation level , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 nvm_EN_DIS_DEF_ts PM_newDDRHandshakeEnabled ;	 
 } platformPowerMngr_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures USIM error handling*/	 
 USIM_ERR_SILENT = 0 , /* @ENUM_VAL_DESC@ Silent error handling*/	 
 USIM_ERR_ASSERT = 1 , /* @ENUM_VAL_DESC@ Assert on error*/	 
 USIM_ERR_RECOVERY = 2 /* @ENUM_VAL_DESC@ error handling recovery*/	 
 } nvmUsimErrorHandler_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Configures USIM driver settings*/	 
 ProductDebugLevel_ts DebugLevel ; /* @ITEM_DESC@ Configures USIM Debug Level , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 UINT8 TxDmaDisable ; /* @ITEM_DESC@ Configure Tx Dma Disable , @ITEM_MODE@ Debug , @ITEM_UNIT@ 0 -0xFF*/	 
 UINT8 DetectGpioPinNo ; /* @ITEM_DESC@ Set USIM detection GPIO , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Entries 1 -0xFF according to available GPIOs , 0 to diasble detection*/ // disable=0 , Detect_Pin=0xFF , others are GPIO / CGPIO pins	 
 nvmUsimErrorHandler_ts ErrorHandler ; /* @ITEM_DESC@ Configures USIM error handling , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 } platformUsim_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures AppCommMode*/	 
 APPCOMM_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 APPCOMM_COMM_IN_RESET = 1 , /* @ENUM_VAL_DESC@ Set Comm in reset*/	 
 APPCOMM_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force AppsComm enum long*/	 
 } platformAppsCommMode_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures OSA Error behavior*/	 
 OSA_ERROR_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 OSA_ERROR_ASSERT = 1 , /* @ENUM_VAL_DESC@ Assert on OSA errors*/	 
 OSA_ERROR_IGNORE = 2 , /* @ENUM_VAL_DESC@ Ignore OSA errors*/	 
 OSA_ERROR_RESTORE_OK = 3 , /* @ENUM_VAL_DESC@ OSA error restore*/	 
 OSA_ERROR_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force OSA error enum long*/	 
 } platformOsaErrBehavior_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures I2C FAST-SLOW mode*/	 
 NVM_I2C_CLK_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 NVM_I2C_SLOW_ClK_MODE = 0x00007fff , /* @ENUM_VAL_DESC@ Configure for slow mode align to I2c.h*/	 
 NVM_I2C_FAST_CLK_MODE = 0x00008000 , /* @ENUM_VAL_DESC@ Configure for fast mode align to I2c.h*/	 
 NVM_I2C_CLK_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force I2C error enum long*/	 
 } platfromI2cModeCfg_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 /* @ENUM_DESC@ Configures I2C repeat start configuration */	 
 NVM_I2C_REPEAT_DEFAULT = 0 , /* @ENUM_VAL_DESC@ Maintain code default*/	 
 NVM_I2C_NOT_REPEAT_START = 1 , /* @ENUM_VAL_DESC@ Configure for slow mode align to I2c.h*/	 
 NVM_I2C_REPEAT_START = 2 , /* @ENUM_VAL_DESC@ Configure for fast mode align to I2c.h*/	 
 NVM_I2C_REPEAT_LONG_TYPE = 0x0FFFFFFF /* @ENUM_VAL_DESC@ force I2C error enum long*/	 
 } platfromI2cRepeatCfg_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ I2C Configures */	 
 platfromI2cModeCfg_ts I2cClkMode ; /* @ITEM_DESC@ Configures I2C CLK mode FAST / SLOW , @ITEM_MODE@ Configuration , @ITEM_UNIT@ see enum*/	 
 platfromI2cRepeatCfg_ts I2cRptStrt ; /* @ITEM_DESC@ Configures I2C REPEAT_START mode yes / no , @ITEM_MODE@ Configuration , @ITEM_UNIT@ see enum*/	 
 } platfromI2cCfg_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ Platfrom configuration */	 
 /* @STRUCT_NVM_FILE_NAME@ platfrom.nvm */	 
 ProductDebugLevel_ts ProductDebugLevel ; /* @ITEM_DESC@ Configures Product Debug Level , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
 UINT32 DelayMSEC_Startup ; /* @ITEM_DESC@ Startup Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_MSL ; /* @ITEM_DESC@ MSL Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_Audio ; /* @ITEM_DESC@ Audio Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_Power ; /* @ITEM_DESC@ Power Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_L1start ; /* @ITEM_DESC@ L1 start Delay , @ITEM_MODE@ Debug , @ITEM_UNIT@ milisec*/	 
 UINT32 DelayMSEC_reserv1 ; /* @ITEM_DESC@ Reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Not Relevant*/	 
	 
 platformUART_route_ts UART_route ; /* @ITEM_DESC@ Configures UART route , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformDIAG_route_ts DIAG_route ; /* @ITEM_DESC@ Configures DIAG route , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformUSBdetection_ts USBdetection ; /* @ITEM_DESC@ Configures USB detection , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformHeartBeat_ts HeartBeat ; /* @ITEM_DESC@ Configures HeartBeat modes , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformPowerMngr_ts PowerManagement ; /* @ITEM_DESC@ Configures Power Manager , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
 platformRtcClient_ts RTC_Client ; /* @ITEM_DESC@ Configures RTC Client , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platformRelaibeData_ts RD_LoadCalibFiles ; /* @ITEM_DESC@ Configures Relaiable Data load source , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
	 
 platformUsim_ts USIM ; /* @ITEM_DESC@ Configures USIM driver settings , @ITEM_MODE@ Debug , @ITEM_UNIT@ see structure*/	 
 platformAppsCommMode_ts AppCommMode ; /* @ITEM_DESC@ Configures AppCommMode , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
	 
 platformOsaErrBehavior_ts OsaErrBehavior ; /* @ITEM_DESC@ Configures OSA Error behavior , @ITEM_MODE@ Debug , @ITEM_UNIT@ see enum*/	 
 platfromI2cCfg_ts NvmCfgI2C ; /* @ITEM_DESC@ Configures I2c CLK and REPEAT_START , @ITEM_MODE@ Configuration , @ITEM_UNIT@ see enum*/	 
 /* the reserved [ X ] must be update for backward	 
 * compatible if new fields are added to PlatformNvm_ts.	 
 * for example if you add UNIT32 you need to reduce X = X-4*/	 
 UINT8 reserved [ 44 ] ; /* @ITEM_DESC@ the amount of the reserved must be reduced if fields are added , @ITEM_MODE@ debugging , @ITEM_UNIT@ none*/	 
	 
 } PlatformNvm_ts;

DIAG_FILTER ( SW_PLAT , NVM , Create , DIAG_INFORMATION)  
 diagPrintf ( " New %s created. But still DEFAULT currently used " , " platform.nvm " );

DIAG_FILTER ( SW_PLAT , NVM , NoFile , DIAG_INFORMATION)  
 diagPrintf ( " No %s file found. Code DEFAULT currently used " , filePath );

DIAG_FILTER ( SW_PLAT , NVM , OldVerUpdate , DIAG_INFORMATION)  
 diagPrintf ( " WARNING: OLD or BAD version of %s file. MUST BE DELETED!!! " , filePath );

//ICAT EXPORTED FUNCTION - SW_PLAT , NVM , PLATcfgPrint 
 void PlatformNvm_Print ( void ) 
 {	 
DIAG_FILTER ( SW_PLAT , NVM , ConfigPrint , DIAG_INFORMATION)  
 diagStructPrintf ( " Platform NVM configuration: %S { PlatformNvm_ts } " , &platformNvm , sizeof ( PlatformNvm_ts ) );

	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , NVM , PLATsetUARTroute 
 void PlatformNvm_setUARTroute ( void *p ) 
 {	 
 platformNvm.UART_route = ( platformUART_route_ts ) ( * ( BYTE* ) p ) ;	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\comBasicCfg_nvm.ppp
//PPL Source File Name : \\softutil\\nvm\\src\\comBasicCfg_nvm.c
typedef unsigned int size_t ;
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
typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
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

typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
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
 COM_PM_DEFAULT = 0x00000000 L , // COM_BASIC_CFG_DEFAULT	 
 COM_PM_ENABLE = 0x00000001 L ,	 
 COM_PM_DISABLE = 0x00000002 L	 
 } comBasicCfgNvm_PM_level;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 comBasicCfgNvm_PM_level PM_level ;	 
 UINT32 reserved [ 28 ] ;	 
 } comBasicCfgNvm_ts;

DIAG_FILTER ( SW_PLAT , NVM , BAD_ComBasicCfg , DIAG_INFORMATION)  
 diagPrintf ( " WARNING: BAD file %s found " , filePath );

//ICAT EXPORTED FUNCTION - SW_PLAT , NVM , CREATE_comBasicCfgNvm_noPM 
 void comBasicCfgNvm_CREATE ( void ) 
 {	 
	 
 FILE_ID fileIndex ;	 
 NVM_Header_ts header ;	 
 RTC_CalendarTime calendarTime ;	 
 comBasicCfgNvm_ts nvmBuf ;	 
	 
 memset ( &header , 0 , sizeof ( NVM_Header_ts ) ) ;	 
 memset ( &nvmBuf , 0 , sizeof ( comBasicCfgNvm_ts ) ) ;	 
	 
 fileIndex = FDI_fopen ( " comBasicCfg.nvm " , " wb " ) ;	 
	 
 // Create NVM standard header	 
 RTCCurrentDateAndTimeGet ( &calendarTime ) ;	 
 header.StructSize = sizeof ( comBasicCfgNvm_ts ) ;	 
 header.NumofStructs = 1 ;	 
 // -+ UID START CQ00180999 19 -Sep-2011 +-	 
 strncpy ( header.StructName , " comBasicCfgNvm_ts " , sizeof ( header.StructName ) ) ;	 
 snprintf ( header.Date , sizeof ( header.Date ) , " %d / %d / %d " , calendarTime.day , calendarTime.month , calendarTime.year ) ;	 
 snprintf ( header.time , sizeof ( header.time ) , " %d:%d:%d " , calendarTime.hour , calendarTime.minute , calendarTime.second ) ;	 
 strncpy ( header.HW_ID , " 0 " , sizeof ( header.HW_ID ) ) ;	 
 strncpy ( header.Version , " 1.000000 " , sizeof ( header.Version ) ) ;	 
 strncpy ( header.CalibVersion , " 0 " , sizeof ( header.CalibVersion ) ) ;	 
 // -+ UID END CQ00180999 19 -Sep-2011 +-	 
 nvmBuf.PM_level = COM_PM_DISABLE ; // NO PM	 
	 
 FDI_fwrite ( &header , sizeof ( NVM_Header_ts ) , 1 , fileIndex ) ;	 
 FDI_fwrite ( &nvmBuf , sizeof ( comBasicCfgNvm_ts ) , 1 , fileIndex ) ;	 
 FDI_fclose ( fileIndex ) ;	 
DIAG_FILTER ( SW_PLAT , NVM , CreateBasic , DIAG_INFORMATION)  
 diagPrintf ( " File %s created. Restart required to use parameters " , " comBasicCfg.nvm " );

	 
	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\COMCfg.ppp
//PPL Source File Name : \\softutil\\nvm\\src\\COMCfg.c
typedef unsigned int size_t ;
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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
typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
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

typedef int COMCFG_HANDLE ;
typedef char COMCfgName [ 25 +1 ] ;
typedef char COMCfgValue [ 25 +1 ] ;
//ICAT EXPORTED FUNCTION - SW_PLAT , COMCfg , COMCfg_Reset 
 void COMCfgPhase2Init ( void ) 
 {	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , COMCfg , COMCfgFindNext 
 void testCOMCfgFindNext ( void *data ) 
 {	 
 return ;	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , COMCfg , COMCfgFindExact 
 void testCOMCfgFindExact ( void *data ) 
 {	 
 return ;	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , COMCfg , AddRecord 
 void COMCfgAddRecord ( void *data ) 
 {	 
 return ;	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\COMCfg_parser.ppp
//PPL Source File Name : \\softutil\\nvm\\src\\COMCfg_parser.c
//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\partition_ops.ppp
//PPL Source File Name : \\softutil\\partition_raw\\src\\partition_ops.c
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
typedef void ( *TaskSuspendCB ) ( void ) ;
typedef void ( *TaskResumeCB ) ( void ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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
typedef volatile unsigned long VUINT32_T ;
typedef unsigned long UINT32_T ;
typedef volatile unsigned int VUINT_T ;
typedef unsigned int UINT_T ;
typedef int INT_T ;
typedef unsigned short UINT16_T , USHORT ;
typedef volatile unsigned short VUINT16_T ;
typedef unsigned char UINT8_T ;
typedef char INT8_T ;
typedef void ( *FnPVOID ) ( void ) ;
typedef unsigned int UINT , *PUINT ;
typedef unsigned long long UINT64 , *PUINT64 ;
typedef unsigned short UINT16 , *PUINT16 ;
typedef unsigned char UINT8 , *PUINT8 ;
typedef unsigned char UCHAR , BYTE , *PUCHAR ;
typedef int INT , *PINT ;
typedef long long INT64 , *PINT64 ;
typedef short INT16 , *PINT16 ;
typedef char CHAR , *PCHAR ;
typedef volatile UINT VUINT , *PVUINT ;
typedef volatile UINT64 VUINT64 , *PVUINT64 ;
typedef volatile unsigned int VUINT32 , *PVUINT32 ;
typedef volatile UINT16 VUINT16 , *PVUINT16 ;
typedef volatile UINT8 VUINT8 , *PVUINT8 ;
typedef volatile UCHAR VUCHAR , *PVUCHAR ;
typedef volatile INT VINT , *PVINT ;
typedef volatile INT64 VINT64 , *PVINT64 ;
typedef volatile int VINT32 , *PVINT32 ;
typedef volatile INT16 VINT16 , *PVINT16 ;
typedef volatile char VINT8 , *PVINT8 ;
typedef volatile CHAR VCHAR , *PVCHAR ;
typedef UINT16 WORD ;
typedef void *VOID_PTR ;
DIAG_FILTER ( SW_PLAT , partition_ops , read , DIAG_INFORMATION)  
 diagPrintf ( " vaddr= [ %lx ] , size= [ %lx ] , dst= [ %ld ] " , vaddr , size , buf_addr );

DIAG_FILTER ( SW_PLAT , partition_ops , write , DIAG_INFORMATION)  
 diagPrintf ( " vaddr= [ %lx ] , size= [ %lx ] , dst= [ %ld ] " , vaddr , size , buf_addr );

DIAG_FILTER ( SW_PLAT , partition_ops , erase , DIAG_INFORMATION)  
 diagPrintf ( " vaddr= [ %lx ] , size= [ %lx ] " , vaddr , size );

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\lfs.ppp
//PPL Source File Name : \\softutil\\littlefs\\lfs_v1\\src\\lfs.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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
typedef unsigned short wchar_t ;
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
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
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
typedef linklist_handler_t urc_cache_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\lfs_api.ppp
//PPL Source File Name : \\softutil\\littlefs\\lfs_v1\\src\\lfs_api.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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
typedef unsigned int size_t ;
typedef unsigned int clock_t ;
typedef unsigned int time_t ;
typedef unsigned int time_t ;
typedef unsigned char BOOL ;
typedef signed char BYTE8 ;
typedef unsigned char UBYTE8 ;
typedef short HWD16 ;
typedef long WORD32 ;
typedef unsigned short UHWD16 ;
typedef unsigned long UWORD32 ;
typedef unsigned long long ULLONG64 ;
typedef char S8 ;
typedef HWD16 S16 ;
typedef WORD32 S32 ;
typedef UBYTE8 U8 ;
typedef UHWD16 U16 ;
typedef UWORD32 U32 ;
typedef void ( *apTYPE_rCallback ) ( UWORD32 ) ;
typedef WORD32 apError ;
typedef UWORD32 fatTYPE_tSector ;
typedef UWORD32 fatTYPE_tCluster ;
typedef UWORD32 fatTYPE_tEntry ;
typedef UWORD32 fatTYPE_tSize ;
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
typedef void ( *TaskSuspendCB ) ( void ) ;
typedef void ( *TaskResumeCB ) ( void ) ;
typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
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
//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\lfs_cache.ppp
//PPL Source File Name : \\softutil\\littlefs\\lfs_v1\\src\\lfs_cache.c
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
typedef unsigned int size_t ;
typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
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
typedef void ( *TaskSuspendCB ) ( void ) ;
typedef void ( *TaskResumeCB ) ( void ) ;
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

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\lfs_crc.ppp
//PPL Source File Name : \\softutil\\littlefs\\lfs_v1\\src\\lfs_crc.c
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

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\stdlib_util.ppp
//PPL Source File Name : \\softutil\\softutil\\src\\stdlib_util.c
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
//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\simPin.ppp
//PPL Source File Name : \\softutil\\softutil\\src\\simPin.c
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
typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
typedef unsigned long UINT32 ;
typedef unsigned short UINT16 ;
typedef unsigned char UINT8 ;
typedef unsigned int UINT_T ;
typedef ImageStruct_11 *PImageStruct_11 ;
typedef DeviceHeader_11 *PDeviceHeader_11 ;
typedef MasterBlockHeader *PMasterBlockHeader ;
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
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
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
typedef unsigned char BOOL ;
typedef union {
 asr_mini_ota_head_info mini_ota_head ; / / new mini ota

 asr_ota_head_info ota_diffhead ; / / new adiff ota

 unsigned char reserved [ 2048 ] ;
 } ASR_OTA_HEADER ;
//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\mep.ppp
//PPL Source File Name : \\softutil\\softutil\\src\\mep.c
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
typedef UINT8 MEP_BCD ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 number [ 32 ] ;	 
 UINT8 length ;	 
 } MEP_PASSWORD;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 year ;	 
 UINT8 month ;	 
 UINT8 day ;	 
 } MEP_DATE;

typedef UINT16 MEP_MNC ;
typedef UINT16 MEP_MCC ;
typedef UINT16 MEP_AccessTechnologyId ;
typedef UINT8 MEP_Boolean ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 serviceproviderId [ 4 ] ;	 
 } MEP_CODE_SP;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 corporateId [ 4 ] ;	 
 } MEP_CODE_CP;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 MEP_SIMPLMN networkIds [ 100 ] ;	 
 MEP_CODE_NS lockNS [ 100 ] ;	 
 MEP_CODE_SP lockSP [ 100 ] ;	 
 MEP_CODE_CP lockCP [ 100 ] ;	 
 MEP_CODE_SIMUSIM SimUsim ;	 
 } MEP_CODE;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 MEP_CODE code ;	 
 UINT8 DefaultSiActivated ;	 
 UINT8 DefaultSiEnabled ;	 
 } MEP_CAT_DATA;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 MEP_PASSWORD CatPsw [ MEP_MAX_CAT ] ;	 
 MEP_PASSWORD UnblockPsw ;	 
 // #if defined ( SS_IPC_SUPPORT ) && defined ( EXTENED_TRIAL_LIMIT_MEP )	 
	 
	 
 UINT8 TrialLimit [ MEP_MAX_CAT ] ;	 
	 
	 
	 
 } MEP_BLOCK_DATA;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /*modified for #499867 2014.031800 by yunhail begin*/	 
 UINT32 VersionSize ;	 
 /*modified for #499867 2014.031800 by yunhail end*/	 
 MEP_CAT_DATA data ; // !!! Run F8 And F9 on this field	 
 MEP_BLOCK_DATA blocking ; // !!! Run F8 And F9 on this field	 
 UINT8 signature [ 20 ] ; // This is the output of the F9 function	 
 UINT8 DataIsEncrypted ; // Should be set to FALSE or TRUE -- do not run F8 | F9	 
 } MEP_FIX;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 SiActivated ;	 
 UINT8 SiEnabled ;	 
 UINT8 TrialCounter [ MEP_MAX_CAT ] ;	 
 UINT8 padding [ 15 ] ;	 
 UINT8 signature [ 20 ] ;	 
 } MEP_CHANGEABLE;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 iccid [ 10 ] ;	 
 MEP_DATE date ;	 
 } UDP_ASL_DATA;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UDP_ASL_DATA data [ 10 ] ;	 
 UINT8 NumAslEntries ;	 
 } UDP_ASL;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 MEP_PASSWORD psw ;	 
 UDP_ASL asl ;	 
 UINT8 si ;	 
 UINT8 padding [ 15 ] ;	 
 UINT8 signature [ 20 ] ;	 
 } UDP_CHANGEABLE;

typedef void ( *MEP_Callback ) ( MEP_UDP_RC* ) ;
typedef union
 {
 void ( *MEP_PutTC_Callback ) ( MEP_UDP_RC* ) ;
 void ( *MEP_PutSI_Callback ) ( MEP_UDP_RC* ) ;
 void ( *UDP_PutSI_Callback ) ( MEP_UDP_RC* ) ;
 void ( *UDP_PutASL_Callback ) ( MEP_UDP_RC* ) ;
 void ( *UDP_PutPassword_Callback ) ( MEP_UDP_RC* ) ;
 } MEP_UDP_CallBackFuncS ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 ulDebugInfoTag ;	 
 UINT32 ulMrdInfo ;	 
 UINT32 ulMepInfo ;	 
 } MRD_DEBUG_INFO;

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
typedef UINT32 lowTaskEventHandler_t ;
typedef void ( *LowEventFuncPtr ) ( lowTaskEventHandler_t ) ;
typedef unsigned char Ipp8u ;
typedef unsigned short Ipp16u ;
typedef unsigned int Ipp32u ;
typedef signed char Ipp8s ;
typedef signed short Ipp16s ;
typedef signed int Ipp32s ;
typedef float Ipp32f ;
typedef long long Ipp64s ;
typedef unsigned long long Ipp64u ;
typedef double Ipp64f ;
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

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , mep_read_si 
 void mep_read_si ( void ) 
 {	 
 UINT8 SiActivated , SiEnabled ;	 
	 
 MEP_GetSI ( &SiActivated , &SiEnabled ) ;	 
	 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Mep SiActivated value is = %x and SiEnabled is = %x " , SiActivated , SiEnabled ) ; } } ; } while ( 0 ) ;	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , mep_write_si 
 void mep_write_si ( void *p ) 
 {	 
 UINT8 *param = ( UINT8 * ) p ;	 
	 
 cb.MEP_PutSI_Callback = MEP_PutSI_Callback ;	 
 MEP_PutSI ( &param [ 0 ] , &param [ 1 ] , &cb ) ;	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , mep_read_tl 
 void mep_read_tl ( void ) 
 {	 
 UINT8 tl ;	 
 MEP_UDP_RC rc ;	 
	 
 MEP_CAT category ;	 
	 
 for ( category = MEP_CAT_NP ; category < MEP_MAX_CAT ; category ++ )	 
 {		 
 rc = MEP_GetTL ( category , &tl ) ;		 
 if ( rc != MEP_UDP_RC_OK )		 
 {			 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Error while reading MEP - TL " ) ; } } ; } while ( 0 ) ;			 
 return ;			 
 }		 
		 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Mep TL [ cat: %d ] value is = %x " , category , tl ) ; } } ; } while ( 0 ) ;		 
 }	 
	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , mep_read_upsw 
 void mep_read_upsw ( void ) 
 {	 
 MEP_PASSWORD Upsw ;	 
 MEP_UDP_RC rc ;	 
	 
 rc = ME_GetUPW ( &Upsw ) ;	 
 if ( rc != MEP_UDP_RC_OK )	 
 {		 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Error while reading MEP - UPSW " ) ; } } ; } while ( 0 ) ;		 
 return ;		 
 }	 
	 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Mep u_psw value is = %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , length = %x " , Upsw . number [ 0 ] , Upsw . number [ 1 ] , Upsw . number [ 2 ] , Upsw . number [ 3 ] , Upsw . number [ 4 ] , Upsw . number [ 5 ] , Upsw . number [ 6 ] , Upsw . number [ 7 ] , Upsw . number [ 8 ] , Upsw . number [ 9 ] , Upsw . number [ 10 ] , Upsw . number [ 11 ] , Upsw . number [ 12 ] , Upsw . number [ 13 ] , Upsw . number [ 14 ] , Upsw . number [ 15 ] , Upsw . length ) ; } } ; } while ( 0 ) ;	 
	 
	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , mep_read_ck 
 void mep_read_ck ( void ) 
 {	 
 MEP_PASSWORD ck ;	 
 MEP_UDP_RC rc ;	 
 MEP_CAT category ;	 
	 
 for ( category = MEP_CAT_NP ; category < MEP_MAX_CAT ; category++ )	 
 {		 
 rc = MEP_GetCK ( category , &ck ) ;		 
 if ( rc != MEP_UDP_RC_OK )		 
 {			 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Error while reading MEP - CK " ) ; } } ; } while ( 0 ) ;			 
 return ;			 
 }		 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Mep CK of category %x value is = %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , length = %x " , category , ck . number [ 0 ] , ck . number [ 1 ] , ck . number [ 2 ] , ck . number [ 3 ] , ck . number [ 4 ] , ck . number [ 5 ] , ck . number [ 6 ] , ck . number [ 7 ] , ck . number [ 8 ] , ck . number [ 9 ] , ck . number [ 10 ] , ck . number [ 11 ] , ck . number [ 12 ] , ck . number [ 13 ] , ck . number [ 14 ] , ck . number [ 15 ] , ck . length ) ; } } ; } while ( 0 ) ;		 
		 
		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , mep_read_gc 
 void mep_read_gc ( void ) 
 {	 
 MEP_CODE gc ;	 
 MEP_UDP_RC rc ;	 
 MEP_CODE_ID codeId ;	 
 UINT8 i ;	 
	 
 for ( codeId = MEP_CODE_ID_NP ; codeId < MEP_MAX_CODE_ID_CAT ; codeId++ )	 
 {		 
 rc = MEP_GetGC ( codeId , &gc ) ;		 
 if ( rc != MEP_UDP_RC_OK )		 
 {			 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Error while reading MEP - GC " ) ; } } ; } while ( 0 ) ;			 
 return ;			 
 }		 
		 
 switch ( codeId )		 
 {			 
 case MEP_CODE_ID_NP :			 
 for ( i = 0 ; i < 100 ; i++ )			 
 {				 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " NP code_id value is mcc [ %x ] = %x , mnc [ %x ] = %x , at [ %x ] = %x , ThreeDigitsDecoded [ %x ] = %x " , i , gc . networkIds [ i ] . plmn . mcc , i , gc . networkIds [ i ] . plmn . mnc , i , gc . networkIds [ i ] . plmn . AccessTechnology , i , gc . networkIds [ i ] . mncThreeDigitsDecoding ) ; } } ; } while ( 0 ) ;				 
				 
 }			 
 break ;			 
 case MEP_CODE_ID_NSP :			 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " NSP code_id value is = %x , " , gc . lockNS [ 0 ] . networkSubsetId [ 0 ] ) ; } } ; } while ( 0 ) ;			 
 break ;			 
 case MEP_CODE_ID_SP :			 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " SP code_id value is = %x " , gc . lockSP [ 0 ] . serviceproviderId [ 0 ] ) ; } } ; } while ( 0 ) ;			 
 break ;			 
 case MEP_CODE_ID_CP :			 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " CP code_id value is = %x " , gc . lockCP [ 0 ] . corporateId [ 0 ] ) ; } } ; } while ( 0 ) ;			 
 break ;			 
 case MEP_CODE_ID_SIM_LOCK :			 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " SIM_LOCK code_id length is = %x , contents = %x , %x , %x , %x , %x , %x , %x , %x " , gc . SimUsim . simId . length , gc . SimUsim . simId . contents [ 0 ] , gc . SimUsim . simId . contents [ 1 ] , gc . SimUsim . simId . contents [ 2 ] , gc . SimUsim . simId . contents [ 3 ] , gc . SimUsim . simId . contents [ 4 ] , gc . SimUsim . simId . contents [ 5 ] , gc . SimUsim . simId . contents [ 6 ] , gc . SimUsim . simId . contents [ 7 ] ) ; } } ; } while ( 0 ) ;			 
			 
			 
 break ;			 
 default:			 
 return ;			 
 }		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , mep_read_tc 
 void mep_read_tc ( void ) 
 {	 
 UINT8 tc ;	 
 MEP_UDP_RC rc ;	 
 MEP_CAT category ;	 
	 
 for ( category = MEP_CAT_NP ; category < MEP_MAX_CAT ; category++ )	 
 {		 
 rc = MEP_GetTC ( category , &tc ) ;		 
 if ( rc != MEP_UDP_RC_OK )		 
 {			 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Error while reading MEP - TC " ) ; } } ; } while ( 0 ) ;			 
 return ;			 
 }		 
		 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Mep TC of category %x value is = %x " , category , tc ) ; } } ; } while ( 0 ) ;		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , udp_read_si 
 void udp_read_si ( void ) 
 {	 
 UINT8 SiActivated ;	 
 MEP_UDP_RC rc ;	 
	 
 rc = UDP_GetSI ( &SiActivated ) ;	 
 if ( rc != MEP_UDP_RC_OK )	 
 {		 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Error while reading UDP - SI or UDP is not support " ) ; } } ; } while ( 0 ) ;		 
 return ;		 
 }	 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Udp SiActivated value is = %x " , SiActivated ) ; } } ; } while ( 0 ) ;	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , udp_read_psw 
 void udp_read_psw ( void ) 
 {	 
 MEP_PASSWORD psw ;	 
 MEP_UDP_RC rc ;	 
	 
 rc = UDP_GetPassword ( &psw ) ;	 
 if ( rc != MEP_UDP_RC_OK )	 
 {		 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Error while reading UDP - PSW or UDP is not support " ) ; } } ; } while ( 0 ) ;		 
 return ;		 
 }	 
	 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Udp psw value is = %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x , %x " , psw . number [ 0 ] , psw . number [ 1 ] , psw . number [ 2 ] , psw . number [ 3 ] , psw . number [ 4 ] , psw . number [ 5 ] , psw . number [ 6 ] , psw . number [ 7 ] , psw . number [ 8 ] , psw . number [ 9 ] , psw . number [ 10 ] , psw . number [ 11 ] , psw . number [ 12 ] , psw . number [ 13 ] , psw . number [ 14 ] , psw . number [ 15 ] ) ; } } ; } while ( 0 ) ;	 
	 
	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , udp_read_asl 
 void udp_read_asl ( void ) 
 {	 
 UDP_ASL asl ;	 
 UINT8 i ;	 
 MEP_UDP_RC rc ;	 
	 
 rc = UDP_GetASL ( &asl ) ;	 
 if ( rc != MEP_UDP_RC_OK )	 
 {		 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Error while reading UDP - ASL or UDP is not support " ) ; } } ; } while ( 0 ) ;		 
 return ;		 
 }	 
	 
 for ( i = 0 ; i < 10 ; i++ )	 
 {		 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Udp ASL data_%x is = %x , %x , %x , %x , %x , %x , %x , %x , %x , %x Date = %u.%u.%u " , i , asl . data [ i ] . iccid [ 0 ] , asl . data [ i ] . iccid [ 1 ] , asl . data [ i ] . iccid [ 2 ] , asl . data [ i ] . iccid [ 3 ] , asl . data [ i ] . iccid [ 4 ] , asl . data [ i ] . iccid [ 5 ] , asl . data [ i ] . iccid [ 6 ] , asl . data [ i ] . iccid [ 7 ] , asl . data [ i ] . iccid [ 8 ] , asl . data [ i ] . iccid [ 9 ] , asl . data [ i ] . date . day , asl . data [ i ] . date . month , asl . data [ i ] . date . year ) ; } } ; } while ( 0 ) ;		 
		 
		 
		 
 }	 
	 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Udp ASL number of entries is = %x " , asl . NumAslEntries ) ; } } ; } while ( 0 ) ;	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , mep_write_tc 
 void mep_write_tc ( void *p ) 
 {	 
 UINT8 *param = ( UINT8 * ) p ;	 
 MEP_UDP_RC rc ;	 
	 
 cb.MEP_PutTC_Callback = MEP_PutTC_Callback ;	 
 rc = MEP_PutTC ( &param [ 0 ] , ( MEP_CAT ) param [ 1 ] , &cb ) ;	 
 if ( rc != MEP_UDP_RC_OK )	 
 {		 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Error while writing to MEP TC " ) ; } } ; } while ( 0 ) ;		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , udp_write_si 
 void udp_write_si ( void *p ) 
 {	 
 UINT8 *param = ( UINT8 * ) p ;	 
 MEP_UDP_RC rc ;	 
	 
 cb.UDP_PutSI_Callback = UDP_PutSI_Callback ;	 
 rc = UDP_PutSI ( &param [ 0 ] , &cb ) ;	 
 if ( rc != MEP_UDP_RC_OK )	 
 {		 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Error while writing to Udp si or UDP is not support " ) ; } } ; } while ( 0 ) ;		 
 return ;		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , udp_write_psw 
 void udp_write_psw ( void *p ) 
 {	 
 UINT8 *param = ( UINT8 * ) p ;	 
 MEP_PASSWORD psw ;	 
 UINT8 i ;	 
 MEP_UDP_RC rc ;	 
	 
 rc = UDP_GetPassword ( &psw ) ;	 
 if ( rc != MEP_UDP_RC_OK )	 
 {		 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Error while reading Udp psw or UDP is not support " ) ; } } ; } while ( 0 ) ;		 
 return ;		 
 }	 
	 
 if ( param [ 0 ] == 1 )	 
 {		 
 for ( i = 0 ; i < 32 ; i++ )		 
 psw.number [ i ] = ( psw.number [ i ] + 1 ) ;		 
 }	 
 else	 
 {		 
 for ( i = 0 ; i < 32 ; i++ )		 
 psw.number [ i ] = ( psw.number [ i ] - 1 ) ;		 
 }	 
	 
 cb.UDP_PutPassword_Callback = UDP_PutPassword_Callback ;	 
 rc = UDP_PutPassword ( &psw , &cb ) ;	 
 if ( rc != MEP_UDP_RC_OK )	 
 {		 
 do { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " [ MEP ] " " Error while writing to Udp psw or UDP is not support " ) ; } } ; } while ( 0 ) ;		 
 return ;		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , MEP , MepEncryptTest 
 void MepEncryptTest ( void ) 
 {	 
	 
 }

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
typedef void ( *StateChangedCb ) ( UINT8 , INT32 , void * ) ;
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

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 TEMP_NORMAL = 0 ,	 
 TEMP_LOW ,	 
 TEMP_HIGH ,	 
 TEMP_TYPE_MAX	 
 } ADC_TEMP_t;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 volt [ 10 ] ;	 
 UINT8 data [ 10 ] ;	 
 } ADCValue;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 ADCValue value [ 10 ] ;	 
 UINT32 flag ;	 
 } ADCInfo;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 version ;	 
 UINT32 timestamp ;	 
 ADCInfo info ;	 
 } MRDADCInfoS;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 ADCValue value [ TEMP_TYPE_MAX-1 ] [ 10 ] ;	 
 UINT8 temp [ 4 ] ;	 
 UINT32 flag ;	 
 } ADCInfo2;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 version ;	 
 UINT32 timestamp ;	 
 ADCInfo2 info ;	 
 } MRDADCInfoS2;

typedef unsigned int time_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\mep_data.ppp
//PPL Source File Name : \\softutil\\softutil\\src\\mep_data.c
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
typedef UINT8 MEP_BCD ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 number [ 32 ] ;	 
 UINT8 length ;	 
 } MEP_PASSWORD;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 year ;	 
 UINT8 month ;	 
 UINT8 day ;	 
 } MEP_DATE;

typedef UINT16 MEP_MNC ;
typedef UINT16 MEP_MCC ;
typedef UINT16 MEP_AccessTechnologyId ;
typedef UINT8 MEP_Boolean ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 serviceproviderId [ 4 ] ;	 
 } MEP_CODE_SP;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 corporateId [ 4 ] ;	 
 } MEP_CODE_CP;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 MEP_SIMPLMN networkIds [ 100 ] ;	 
 MEP_CODE_NS lockNS [ 100 ] ;	 
 MEP_CODE_SP lockSP [ 100 ] ;	 
 MEP_CODE_CP lockCP [ 100 ] ;	 
 MEP_CODE_SIMUSIM SimUsim ;	 
 } MEP_CODE;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 MEP_CODE code ;	 
 UINT8 DefaultSiActivated ;	 
 UINT8 DefaultSiEnabled ;	 
 } MEP_CAT_DATA;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 MEP_PASSWORD CatPsw [ MEP_MAX_CAT ] ;	 
 MEP_PASSWORD UnblockPsw ;	 
 // #if defined ( SS_IPC_SUPPORT ) && defined ( EXTENED_TRIAL_LIMIT_MEP )	 
	 
	 
 UINT8 TrialLimit [ MEP_MAX_CAT ] ;	 
	 
	 
	 
 } MEP_BLOCK_DATA;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /*modified for #499867 2014.031800 by yunhail begin*/	 
 UINT32 VersionSize ;	 
 /*modified for #499867 2014.031800 by yunhail end*/	 
 MEP_CAT_DATA data ; // !!! Run F8 And F9 on this field	 
 MEP_BLOCK_DATA blocking ; // !!! Run F8 And F9 on this field	 
 UINT8 signature [ 20 ] ; // This is the output of the F9 function	 
 UINT8 DataIsEncrypted ; // Should be set to FALSE or TRUE -- do not run F8 | F9	 
 } MEP_FIX;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 SiActivated ;	 
 UINT8 SiEnabled ;	 
 UINT8 TrialCounter [ MEP_MAX_CAT ] ;	 
 UINT8 padding [ 15 ] ;	 
 UINT8 signature [ 20 ] ;	 
 } MEP_CHANGEABLE;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT8 iccid [ 10 ] ;	 
 MEP_DATE date ;	 
 } UDP_ASL_DATA;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UDP_ASL_DATA data [ 10 ] ;	 
 UINT8 NumAslEntries ;	 
 } UDP_ASL;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 MEP_PASSWORD psw ;	 
 UDP_ASL asl ;	 
 UINT8 si ;	 
 UINT8 padding [ 15 ] ;	 
 UINT8 signature [ 20 ] ;	 
 } UDP_CHANGEABLE;

typedef void ( *MEP_Callback ) ( MEP_UDP_RC* ) ;
typedef union
 {
 void ( *MEP_PutTC_Callback ) ( MEP_UDP_RC* ) ;
 void ( *MEP_PutSI_Callback ) ( MEP_UDP_RC* ) ;
 void ( *UDP_PutSI_Callback ) ( MEP_UDP_RC* ) ;
 void ( *UDP_PutASL_Callback ) ( MEP_UDP_RC* ) ;
 void ( *UDP_PutPassword_Callback ) ( MEP_UDP_RC* ) ;
 } MEP_UDP_CallBackFuncS ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 ulDebugInfoTag ;	 
 UINT32 ulMrdInfo ;	 
 UINT32 ulMepInfo ;	 
 } MRD_DEBUG_INFO;

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\RmiFunctions.ppp
//PPL Source File Name : \\softutil\\softutil\\src\\RmiFunctions.c
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 short data0 ;	 
 short data1 ;	 
 short data2 ;	 
 } DummyStruct;

//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 DUMMY_ZERO = 0 ,	 
 DUMMY_ONE ,	 
 DUMMY_TWO ,	 
 DUMMY_THREE	 
 } DummyEnum;

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , restartCmd 
 void restartCmd ( void* pv ) 
 {	 
 // doRestart ( ) ;	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , ArmRead16 
 void armRead16 ( void* p ) 
 {	 
 UINT32 addr=* ( UINT32* ) p ;	 
 UINT32 val ;	 
 val=* ( UINT16* ) addr ;	 
DIAG_FILTER ( SW_PLAT , CONTROL , ArmRead16Reply , DIAG_INFORMATION)  
 diagPrintf ( " Read from %lx ( 16 bit ) : %x " , addr , val );

	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , ArmRead32 
 void armRead32 ( void* p ) 
 {	 
 UINT32 addr=* ( UINT32* ) p ;	 
 UINT32 val ;	 
 val=* ( UINT32* ) addr ;	 
DIAG_FILTER ( SW_PLAT , CONTROL , ArmRead32Reply , DIAG_INFORMATION)  
 diagPrintf ( " Read from %lx ( 32 bit ) : %lx " , addr , val );

	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , ArmWrite16 
 void armWrite16 ( void* p ) 
 {	 
 UINT32 addr=* ( UINT32* ) p ;	 
 UINT32 val=* ( ( UINT32* ) p+1 ) ;	 
 * ( UINT16* ) addr=val ;	 
DIAG_FILTER ( SW_PLAT , CONTROL , ArmWrite16Reply , DIAG_INFORMATION)  
 diagPrintf ( " Written to %lx ( 16 bit ) : %x " , addr , val );

	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , ArmWrite32 
 void armWrite32 ( void* p ) 
 {	 
 UINT32 addr=* ( UINT32* ) p ;	 
 UINT32 val=* ( ( UINT32* ) p+1 ) ;	 
 * ( UINT32* ) addr=val ;	 
DIAG_FILTER ( SW_PLAT , CONTROL , ArmWrite32Reply , DIAG_INFORMATION)  
 diagPrintf ( " Written to %lx ( 32 bit ) : %lx " , addr , val );

	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , memTest16 
 void memTest16 ( void* p ) 
 {	 
 UINT32 addr=* ( UINT32* ) p ;	 
 UINT32 size=* ( ( UINT32* ) p+1 ) ;	 
 UINT32 i , val ;	 
 UINT32 failureCount=0 ;	 
 UINT16 shift=0xa5a5 ;	 
	 
 if ( size>0x800000 ) size=0x800000 ;	 
 else size&=~1 ; // even	 
 addr&=~1 ;	 
	 
DIAG_FILTER ( SW_PLAT , CONTROL , memTestReplyWrite , DIAG_INFORMATION)  
 diagTextPrintf ( " Mem Test: Write " );

	 
	 
 for ( i=0 ; i<size ; i+=2 )	 
 {		 
 * ( UINT16* ) ( addr+i ) = ( UINT16 ) ( addr+i+shift ) ;		 
 }	 
	 
DIAG_FILTER ( SW_PLAT , CONTROL , memTestReplyRead , DIAG_INFORMATION)  
 diagTextPrintf ( " Mem Test: Read Back " );

	 
	 
 for ( i=0 ; i<size ; i+=2 )	 
 {		 
 val=* ( UINT16* ) ( addr+i ) ;		 
 if ( val!= ( UINT16 ) ( addr+i+shift ) ) failureCount++ ;		 
 }	 
	 
DIAG_FILTER ( SW_PLAT , CONTROL , memTestReply , DIAG_INFORMATION)  
 diagPrintf ( " Mem Test Done , %d failures " , failureCount );

	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , AAAP , getPlpVersion 
 void getPlpVersion ( void *p ) 
 {	 
 // extern const char plpVersion [ ] ;	 
 const char plpVersion [ ] = " Not available " ;	 
DIAG_FILTER ( SW_PLAT , AAAP , plpVersionReport , DIAG_INFORMATION)  
 diagPrintf ( " PLP version: %s " , plpVersion );

	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , AAAP , holdPLP 
 void holdPLPCmd ( void *p ) 
 {	 
 // holdPLP ( ) ;	 
DIAG_FILTER ( SW_PLAT , AAAP , holdPLP_reply , DIAG_INFORMATION)  
 diagTextPrintf ( " PLP is held in reset " );

	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , malloc 
 void exportedMalloc ( UINT32 *p , int len ) 
 {	 
 if ( len>=sizeof ( UINT32 ) )	 
 {		 
 UINT32 size=*p ;		 
 UINT32 addr= ( UINT32 ) malloc ( size ) ;		 
DIAG_FILTER ( SW_PLAT , CONTROL , malloc_reply , DIAG_INFORMATION)  
 diagPrintf ( " Allocated: 0x%lx " , addr );

		 
		 
 /*mischecked by coverity*/		 
 /*coverity [ leaked_storage ] */		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , free 
 void exportedFree ( UINT32 *p , int len ) 
 {	 
 if ( len>=sizeof ( UINT32 ) )	 
 {		 
 UINT32 addr=*p ;		 
 free ( ( void * ) addr ) ;		 
DIAG_FILTER ( SW_PLAT , CONTROL , free_reply , DIAG_INFORMATION)  
 diagPrintf ( " Deallocated: 0x%lx " , addr );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , ICacheParityErrorCount 
 void ICacheParityErrorCount ( void *p ) 
 {	 
 extern UINT32 ICParityCount ;	 
DIAG_FILTER ( SW_PLAT , CONTROL , ICacheParityErrorCount_rep , DIAG_INFORMATION)  
 diagPrintf ( " IC parity error numer: %d " , ICParityCount );

	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , GetSteppingID 
 void expGetSteppingID ( void *p ) 
 {	 
 CPU_Version id=GetCpuVersion ( ) ;	 
 char name [ ] = " Bx " ;	 
 switch ( id )	 
 {		 
 case CPU_HERMON_B0 :		 
 case CPU_HERMON_B1 :		 
 case CPU_HERMON_B2 :		 
 case CPU_HERMON_B3 :		 
 name [ 1 ] = ' 0 ' + ( id-CPU_HERMON_B0 ) ;		 
 break ;		 
 default:		 
 strcpy ( name , " ?? " ) ;		 
 }	 
DIAG_FILTER ( SW_PLAT , CONTROL , GetSteppingID_rep , DIAG_INFORMATION)  
 diagPrintf ( " Hermon stepping is: %s " , name );

	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , writeUINT8 
 void writeUINT8 ( volatile void *base ) 
 {	 
 UINT32 *desAdd = ( UINT32* ) ( * ( UINT32* ) ( base ) ) ;	 
 UINT8 val2Write = * ( ( UINT8* ) base+4 ) ;	 
	 
 *desAdd = ( *desAdd & 0xffffff00 ) | val2Write ;	 
	 
DIAG_FILTER ( SW_PLAT , CONTROL , writeUINT8 , writeUINT8a)  
 diagPrintf ( " address %lx contain %lx " , desAdd , *desAdd );

	 
	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , readUINT32burst 
 void readUINT32 ( volatile void *base , void *byteAmount ) 
 {	 
 UINT32 numOfUINT32 , i , *baseAdd ;	 
 numOfUINT32 = * ( ( UINT32* ) base+1 ) ;	 
 baseAdd = ( UINT32* ) ( * ( UINT32* ) base ) ;	 
	 
 if ( ( UINT32 ) byteAmount==4 )	 
 numOfUINT32=1 ; /* in case only address is given*/	 
	 
 for ( i=numOfUINT32 ; i>0 ; i-- )	 
 {		 
DIAG_FILTER ( SW_PLAT , CONTROL , readUINT32 , readUINT32a)  
 diagPrintf ( " address %lx contain %lx " , baseAdd , *baseAdd );

		 
 baseAdd++ ;		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , readUINT16burst 
 void readUINT16 ( volatile void *base , void *byteAmount ) 
 {	 
 UINT32 numOfUINT16 , i ;	 
 UINT16 *baseAdd ;	 
	 
 numOfUINT16 = * ( ( UINT32* ) base+1 ) ;	 
 baseAdd = ( UINT16 * ) ( * ( UINT32* ) base ) ;	 
	 
 if ( ( UINT32 ) byteAmount==4 )	 
 numOfUINT16=1 ; /* in case only address is given*/	 
	 
 for ( i=numOfUINT16 ; i>0 ; i-- )	 
 {		 
DIAG_FILTER ( SW_PLAT , CONTROL , readUINT16 , readUINT16a)  
 diagPrintf ( " address %lx contain %x " , baseAdd , *baseAdd );

		 
 baseAdd++ ;		 
 }	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , CONTROL , readUINT8burst 
 void readUINT8 ( volatile void *base , void *byteAmount ) 
 {	 
 UINT32 numOfUINT8 , i ;	 
 UINT8 *baseAdd ;	 
	 
 numOfUINT8 = * ( ( UINT32* ) base+1 ) ;	 
 baseAdd = ( UINT8 * ) ( * ( UINT32* ) base ) ;	 
	 
 if ( ( UINT32 ) byteAmount==4 )	 
 numOfUINT8=1 ; /* in case only address is given*/	 
	 
 for ( i=numOfUINT8 ; i>0 ; i-- )	 
 {		 
DIAG_FILTER ( SW_PLAT , CONTROL , readUINT8 , readUINT8a)  
 diagPrintf ( " address %lx contain %x " , baseAdd , *baseAdd );

		 
 baseAdd++ ;		 
 }	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\osa_utils.ppp
//PPL Source File Name : \\softutil\\softutil\\src\\osa_utils.c
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
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
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
//ICAT EXPORTED FUNCTION - SW_PLAT , OSA_UTIL , osaSuspendTask 
 void utils_suspend_task ( OSATaskRef **task_ref ) 
 {	 
	 
 OsaTaskSuspend ( *task_ref , 0 ) ;	 
	 
DIAG_FILTER ( SW_PLAT , OSA_UTIL , OSA_UTIL_SUSPEND , DIAG_INFORMATION)  
 diagPrintf ( " Suspending of task ID %lx done " , *task_ref );

	 
	 
 }

//ICAT EXPORTED FUNCTION - SW_PLAT , OSA_UTIL , osaResumeTask 
 void utils_resume_task ( OSATaskRef **task_ref ) 
 {	 
	 
 OsaTaskResume ( *task_ref , 0 ) ;	 
	 
DIAG_FILTER ( SW_PLAT , OSA_UTIL , OSA_UTIL_RESUME , DIAG_INFORMATION)  
 diagPrintf ( " Resuming of task ID %lx done " , *task_ref );

	 
	 
 }

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\RdGenData.ppp
//PPL Source File Name : \\softutil\\softutil\\src\\RdGenData.c
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
//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\fstdio_wrap.ppp
//PPL Source File Name : \\softutil\\softutil\\src\\fstdio_wrap.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef FILE* ( *fopen_t ) ( const char * , const char * ) ;
typedef int ( *fclose_t ) ( FILE* ) ;
typedef size_t ( *fread_t ) ( void * , size_t , size_t , FILE* ) ;
typedef size_t ( *fwrite_t ) ( const void * , size_t , size_t , FILE* ) ;
typedef int ( *fprintf_t ) ( FILE* , const char * , ... ) ;
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
//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\FatSysWrapper.ppp
//PPL Source File Name : \\softutil\\softutil\\src\\FatSysWrapper.c
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
typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
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

typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
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
typedef unsigned int size_t ;
typedef unsigned int clock_t ;
typedef unsigned int time_t ;
typedef void ( *AlCallback ) ( void ) ;
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
typedef unsigned int time_t ;
typedef unsigned char BOOL ;
typedef signed char BYTE8 ;
typedef unsigned char UBYTE8 ;
typedef short HWD16 ;
typedef long WORD32 ;
typedef unsigned short UHWD16 ;
typedef unsigned long UWORD32 ;
typedef unsigned long long ULLONG64 ;
typedef char S8 ;
typedef HWD16 S16 ;
typedef WORD32 S32 ;
typedef UBYTE8 U8 ;
typedef UHWD16 U16 ;
typedef UWORD32 U32 ;
typedef void ( *apTYPE_rCallback ) ( UWORD32 ) ;
typedef WORD32 apError ;
typedef UWORD32 fatTYPE_tSector ;
typedef UWORD32 fatTYPE_tCluster ;
typedef UWORD32 fatTYPE_tEntry ;
typedef UWORD32 fatTYPE_tSize ;
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

typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef UINT32 lfs_size_t ;
typedef UINT32 lfs_off_t ;
typedef int lfs_ssize_t ;
typedef int lfs_soff_t ;
typedef UINT32 lfs_block_t ;
DIAG_FILTER ( FDI , fatsys , F_Open_start , DIAG_INFORMATION)  
 diagPrintf ( " Fdi open start: %s: mode: %s " , filename_ptr , mode );

DIAG_FILTER ( FDI , fatsys , F_Open_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi open succeed: %s: handle: %d " , filename_ptr , handle );

DIAG_FILTER ( FDI , fatsys , F_Open_error , DIAG_INFORMATION)  
 diagPrintf ( " Fdi open error: %s , status: %d " , filename_ptr , handle );

DIAG_FILTER ( FDI , fatsys , F_Close_start , DIAG_INFORMATION)  
 diagPrintf ( " Fdi close start , handle: %d " , stream );

DIAG_FILTER ( FDI , fatsys , F_Close_error , DIAG_INFORMATION)  
 diagPrintf ( " Fdi close error , handle: %d , errCode: %d " , stream , res );

DIAG_FILTER ( FDI , fatsys , F_Close_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi close succeed , handle: %d " , stream );

DIAG_FILTER ( FDI , fatsys , F_read_error , DIAG_INFORMATION)  
 diagPrintf ( " Fdi read error , handle: %d , errCode: %d " , stream , res );

DIAG_FILTER ( FDI , fatsys , F_readEx_error , DIAG_INFORMATION)  
 diagPrintf ( " Fdi read error , handle: %d , errCode: %d " , stream , res );

DIAG_FILTER ( FDI , fatsys , F_write_start , DIAG_INFORMATION)  
 diagPrintf ( " Fdi write start , handle: %d , size: %ld " , stream , element_size*count );

DIAG_FILTER ( FDI , fatsys , F_write_error , DIAG_INFORMATION)  
 diagPrintf ( " Fdi write error , handle: %d , errCode: %d " , stream , res );

DIAG_FILTER ( FDI , fatsys , F_write_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi write succeed , handle: %d , actual size: %ld " , stream , res );

DIAG_FILTER ( FDI , fatsys , F_writeEx_start , DIAG_INFORMATION)  
 diagPrintf ( " Fdi write start , handle: %d , size: %ld " , stream , element_size*count );

DIAG_FILTER ( FDI , fatsys , F_writeEx_error , DIAG_INFORMATION)  
 diagPrintf ( " Fdi write error , handle: %d , errCode: %d " , stream , res );

DIAG_FILTER ( FDI , fatsys , F_writeEx_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi write succeed , handle: %d , actual size: %ld " , stream , res );

DIAG_FILTER ( FDI , fatsys , F_seek_start , DIAG_INFORMATION)  
 diagPrintf ( " Fdi seek start , handle: %d , offset:%d , wherefrom: %d " , stream , offset , wherefrom );

DIAG_FILTER ( FDI , fatsys , F_seek_error , DIAG_INFORMATION)  
 diagPrintf ( " Fdi seek error , handle: %d , errCode: %d " , stream , res );

DIAG_FILTER ( FDI , fatsys , F_seek_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi seek succeed , handle: %d , res: %d " , stream , res );

DIAG_FILTER ( FDI , fatsys , F_tell_start , DIAG_INFORMATION)  
 diagPrintf ( " Fdi tell start , handle: %d " , stream );

DIAG_FILTER ( FDI , fatsys , F_tell_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi tell succeed , handle: %d " , stream );

DIAG_FILTER ( FDI , fatsys , F_Opendir , DIAG_INFORMATION)  
 diagPrintf ( " Fdi open dir error: %s , status: %d " , dir_name , handle );

DIAG_FILTER ( FDI , fatsys , F_Opendir_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi open dir succeed: %s: handle: %d " , dir_name , handle );

DIAG_FILTER ( FDI , fatsys , F_Closedir , DIAG_INFORMATION)  
 diagPrintf ( " Fdi close dir error: handle:%d , status: %d " , stream , res );

DIAG_FILTER ( FDI , fatsys , F_Closedir_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi close dir succeed:handle: %d , res: %d " , stream , res );

DIAG_FILTER ( FDI , fatsys , F_Makedir , DIAG_INFORMATION)  
 diagPrintf ( " Fdi make dir error: %s , status: %d " , dir_name , res );

DIAG_FILTER ( FDI , fatsys , F_Makedir_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi make dir succeed: %s: status: %d " , dir_name , res );

DIAG_FILTER ( FDI , fatsys , F_findfirst_start , DIAG_INFORMATION)  
 diagPrintf ( " Fdi findfirst start , filename_ptr: %s " , filename_ptr );

DIAG_FILTER ( FDI , fatsys , F_findfirst_error_0 , DIAG_INFORMATION)  
 diagPrintf ( " Fdi findfirst error , ERR_PARAM " );

DIAG_FILTER ( FDI , fatsys , F_findfirst_error_1 , DIAG_INFORMATION)  
 diagPrintf ( " Fdi findfirst error 1 , errCode: %d " , rec );

DIAG_FILTER ( FDI , fatsys , F_findfirst_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi findfirst succeed , the found file: %s " , gFullFileName );

DIAG_FILTER ( FDI , fatsys , F_findnext_start , DIAG_INFORMATION)  
 diagPrintf ( " Fdi findnext start " );

DIAG_FILTER ( FDI , fatsys , F_findnext_end , DIAG_INFORMATION)  
 diagPrintf ( " Fdi findnext there is not matching files " );

DIAG_FILTER ( FDI , fatsys , F_findnext_error , DIAG_INFORMATION)  
 diagPrintf ( " Fdi findnext error errCode: %d " , rec );

DIAG_FILTER ( FDI , fatsys , F_findnext_finished , DIAG_INFORMATION)  
 diagPrintf ( " Fdi find process finished: the final file: %s " , gFullFileName );

DIAG_FILTER ( FDI , fatsys , F_findnext_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi findnext succeed: the found file: %s " , gFullFileName );

DIAG_FILTER ( FDI , fatsys , F_remove_start , DIAG_INFORMATION)  
 diagPrintf ( " Fdi remove start , file: %s " , filename_ptr );

DIAG_FILTER ( FDI , fatsys , F_remove_error , DIAG_INFORMATION)  
 diagPrintf ( " Fdi remove error , file: %s , errCode: %d " , filename_ptr , res );

DIAG_FILTER ( FDI , fatsys , F_remove_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi remove succeed , file: %s " , filename_ptr );

DIAG_FILTER ( FDI , FDI5to6 , FDI_feof , DIAG_ERROR)  
 diagPrintf ( " FDI_feof ( ) not implemented in FDI5 API to FDI7 converter " );

DIAG_FILTER ( FDI , fatsys , F_eof_start , DIAG_INFORMATION)  
 diagPrintf ( " Fdi eof start , handle: %d " , stream );

DIAG_FILTER ( FDI , fatsys , F_eof_succeed , DIAG_INFORMATION)  
 diagPrintf ( " Fdi eof succeed , handle: %d , res: %d " , stream , res );

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\FDI_Transport.ppp
//PPL Source File Name : \\softutil\\softutil\\src\\FDI_Transport.c
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
typedef UINT32 Attribs_Mmu ;
typedef void ( * mmuNotifyEventFunc ) ( MMU_ERROR_STATUS mmuErrorHandle ) ;
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

typedef union {
 rw_region_item compress_rw_region_list [ 16 ] ;

 UINT8 filer [ 512 ] ;
 } LOADTABLE_AREA_RW_CPZ_INFO ;
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int time_t ;
typedef unsigned char BOOL ;
typedef signed char BYTE8 ;
typedef unsigned char UBYTE8 ;
typedef short HWD16 ;
typedef long WORD32 ;
typedef unsigned short UHWD16 ;
typedef unsigned long UWORD32 ;
typedef unsigned long long ULLONG64 ;
typedef char S8 ;
typedef HWD16 S16 ;
typedef WORD32 S32 ;
typedef UBYTE8 U8 ;
typedef UHWD16 U16 ;
typedef UWORD32 U32 ;
typedef void ( *apTYPE_rCallback ) ( UWORD32 ) ;
typedef WORD32 apError ;
typedef UWORD32 fatTYPE_tSector ;
typedef UWORD32 fatTYPE_tCluster ;
typedef UWORD32 fatTYPE_tEntry ;
typedef UWORD32 fatTYPE_tSize ;
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
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 char fileName [ 256 ] ; // name of file located in Flash ( or to be create )	 
 char mode [ 256 ] ; // Opening mode ( e.g. open for readonly )	 
 } FOpenInputStruct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 FILE_ID fileID ; // an ID of an already open file in Flash memory.	 
 char fileName [ 256 ] ; // name of file located in Flash memory.	 
 } FOpenReturnStruct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 FILE_ID fileID ; // File ID of the file being handled.	 
 UINT16 PacketSize ; // size of packet being transfered.	 
 char writeBuf [ 1024 ] ; // buffer of bytes to be written	 
 } WriteInputStruct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 FILE_ID fileID ; // File ID of the file being handled.	 
 UINT16 PacketSize ; // size of packet being transfered.	 
 UINT32 filePos ; // offset to start to write	 
 UINT32 remainBytes ; // offset to start to write	 
 char writeBuf [ 1024 *2 ] ; // buffer of bytes to be written	 
 } WriteInputStruct_Ex;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 FILE_ID fileID ; // File ID of the file being handled.	 
 UINT16 PacketOK ; // Contian the error code see FDI Doc ( e.g. ERR_OK )	 
 UINT16 PacketSize ; // size of packet being transfered.	 
 UINT32 fileCurPos ; // current posof file	 
 UINT32 reserved ; // size to write from current filepos	 
 } WriteReturnStruct_Ex;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 FILE_ID fileID ;	 
 UINT16 bufferSize ;	 
 } ReadInputStruct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 PacketOK ; // Contian the error code see FDI Doc ( e.g. ERR_OK )	 
 UINT16 LastPacket ; // equal to 1 if it ' s the last packet , 0 - otherwise.	 
 UINT16 PacketSize ; // size in bytes of the buffer being read from file.	 
 char readBuf [ 1024 ] ; // buffer of bytes contains the Flash file data.	 
 } ReadReturnStruct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 FILE_ID fileID ;	 
 UINT16 bufferSize ;	 
 UINT32 filePos ; // offset to start to read	 
 UINT32 sizetoRead ; // size to read from current filepos	 
 UINT32 dataBlockSize ;	 
 } ReadInputStruct_Ex;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 FILE_ID fileID ;	 
 UINT16 PacketOK ; // Contian the error code see FDI Doc ( e.g. ERR_OK )	 
 UINT16 LastPacket ; // equal to 1 if it ' s the last packet , 0 - otherwise.	 
 UINT16 PacketSize ; // size in bytes of the buffer being read from file.	 
 UINT32 filePos ; // offset to start to read	 
 char readBuf [ 1024 *4 ] ; // buffer of bytes contains the Flash file data.	 
 } ReadReturnStruct_Ex;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 char fInfoList [ 1024 ] ; // buffer contain file properties information ( name , size , date etc. )	 
 UINT16 fListLen ; // Number of files describe in the buffer ( fInfoList )	 
 UINT8 LastPacket ; // Flag which intecates whether this is the last structure contain file -	 
 } FNamesReturnStruct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 char fOldName [ 256 ] ;	 
 char fNewName [ 256 ] ;	 
 } RenameInputStruct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 char fileName [ 256 ] ;	 
 UINT32 newMode ;	 
 } ChangModeStruct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 short fileID ;	 
 long offset ;	 
 int whereFrom ;	 
 } FSeekStruct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 unsigned long long fdvSize ;	 
 } FdvSizeStruct;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 fdvAvailableSpace ;	 
 } FdvAvailableSpaceStruct;

DIAG_FILTER ( FDI , Transport , FdvAvailableSize , DIAG_INFORMATION)  
 diagStructPrintf ( " %S { FdvAvailableSpaceStruct } " , ptr , size );

DIAG_FILTER ( FDI , Transport , F_NameList_Packet , DIAG_INFORMATION)  
 diagStructPrintf ( " %S { FNamesReturnStruct } " , ptr , size );

//ICAT EXPORTED FUNCTION - Diag , Utils , SetRTC 
 void _SetRTC ( void *pDateAmdTime ) 
 {	 
 RTC_CalendarTime* pstDateAndTime = ( RTC_CalendarTime* ) pDateAmdTime ;	 
 RTC_ReturnCode rc ;	 
	 
 RTCAlarmReset ( ) ; // Clear the alarm - needed for the next code line.	 
 rc = RTCDateAndTimeSet ( pstDateAndTime ) ;	 
 if ( rc == RTC_RC_OK )	 
 {		 
DIAG_FILTER ( Diag , Utils , SetRTC_Success , DIAG_INFORMATION)  
 diagPrintf ( " RTC was successfully set. " );

		 
 }	 
 else if ( rc == RTC_RC_MAKETIME_FAILURE )	 
 {		 
DIAG_FILTER ( Diag , Utils , SetRTC_Failure , DIAG_INFORMATION)  
 diagPrintf ( " RTC set failed , check the input parameter validity. " );

		 
 }	 
 else if ( rc == RTC_RC_ALARM_ALREADY_SET )	 
 {		 
DIAG_FILTER ( Diag , Utils , RTC_Already_Set , DIAG_INFORMATION)  
 diagPrintf ( " RTC was already set. " );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - Diag , Utils , ReadRTC 
 void _ReadRTC ( void ) 
 {	 
 RTC_CalendarTime stCalendarTime ;	 
 RTC_ReturnCode rc ;	 
	 
 rc = RTCCurrentDateAndTimeGet ( &stCalendarTime ) ;	 
 if ( rc == RTC_RC_OK )	 
 {		 
 char sCalanderTime [ 256 ] ;		 
 sprintf ( sCalanderTime , " The RTC Value is: %d / %02d / %02d , %d:%02d:%02d " ,		 
 stCalendarTime.day , stCalendarTime.month , stCalendarTime.year ,		 
 stCalendarTime.hour , stCalendarTime.minute , stCalendarTime.second ) ;		 
DIAG_FILTER ( Diag , Utils , ReadRTC_Success , DIAG_INFORMATION)  
 diagPrintf ( " %s " , sCalanderTime );

		 
 }	 
 else	 
 {		 
DIAG_FILTER ( Diag , Utils , ReadRTC_Failure , DIAG_INFORMATION)  
 diagPrintf ( " Failed to read RTC " );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , Fopen 
 void _Fopen ( void* fInOpenStruct ) 
 {	 
 FOpenInputStruct* fOpenInSt = ( FOpenInputStruct* ) fInOpenStruct ;	 
 FILE_ID hFileID = FDI_fopen ( fOpenInSt->fileName , fOpenInSt->mode ) ;	 
	 
 if ( hFileID == 0 )	 
 {		 
DIAG_FILTER ( FDI , Transport , F_Open_Error , DIAG_INFORMATION)  
 diagPrintf ( " fopen %s error ( Error Code: %d ) " , fOpenInSt->fileName , hFileID );

		 
 }	 
 else	 
 {		 
 FOpenReturnStruct retOpenStruct ;		 
 retOpenStruct.fileID = ( UINT16 ) hFileID ;		 
 memset ( retOpenStruct.fileName , 0 , 256 ) ;		 
 strcpy ( retOpenStruct.fileName , fOpenInSt->fileName ) ;		 
		 
		 
 /*Fixed coverity [ overrun-buffer-arg ] */		 
		 
		 
		 
		 
DIAG_FILTER ( FDI , Transport , F_Open_Return_FileID , DIAG_INFORMATION)  
 diagStructPrintf ( " %S { FOpenReturnStruct } " , ( void* ) &retOpenStruct , sizeof ( FOpenReturnStruct ) );

		 
		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , Fclose 
 void _Fclose ( void *fileID ) 
 {	 
 UINT8 retVal = 1 ;	 
 FILE_ID hFileID = * ( FILE_ID* ) fileID ;	 
	 
 retVal = FDI_fclose ( hFileID ) ;	 
 if ( retVal != 0 )	 
 {		 
DIAG_FILTER ( FDI , Transport , F_Close_Error , DIAG_INFORMATION)  
 diagPrintf ( " File ( ID: %d ) close error ( Error Code: %d ) " , ( UINT16 ) hFileID , retVal );

		 
 }	 
 else	 
 {		 
DIAG_FILTER ( FDI , Transport , F_Close_Success , DIAG_INFORMATION)  
 diagPrintf ( " File ( ID: %d ) was succesfully closed " , ( UINT16 ) hFileID );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , Fread 
 void _Fread ( void *pReadStruct ) 
 {	 
 ERR_CODE errFdi ;	 
 ReadReturnStruct* pRetReadBuf ;	 
 size_t nElementsToRead , nActualReadElemenets ;	 
	 
 FILE_ID hFileID = ( FILE_ID ) ( ( ( ReadInputStruct* ) pReadStruct ) ->fileID ) ;	 
 nElementsToRead = ( size_t ) ( ( ( ReadInputStruct* ) pReadStruct ) ->bufferSize ) ;	 
	 
 if ( nElementsToRead > 1024 )	 
 {		 
DIAG_FILTER ( FDI , Transport , F_Read_Bad_Input , DIAG_INFORMATION)  
 diagPrintf ( " Number of packets to read exceeded the maximal number ( %d ) " , ( UINT16 ) 1024 );

		 
 return ;		 
 }	 
 pRetReadBuf = ( ReadReturnStruct* ) ( malloc ( sizeof ( ReadReturnStruct ) ) ) ;	 
	 
 if ( pRetReadBuf )	 
 {		 
 nActualReadElemenets = FDI_fread ( & ( pRetReadBuf->readBuf ) , sizeof ( UINT8 ) , nElementsToRead , hFileID ) ;		 
		 
 errFdi = FDI_ferror ( hFileID ) ; // If any error occured errFdi will contain the error code.		 
 pRetReadBuf->PacketOK = ( UINT16 ) errFdi ; // Update the return struct to contain any error information.		 
 pRetReadBuf->PacketSize = nActualReadElemenets ;		 
 if ( ( errFdi == ERR_EOF ) || ( nActualReadElemenets < nElementsToRead ) )		 
 {			 
 pRetReadBuf->PacketOK = ( UINT16 ) ( ERR_EOF ) ;			 
 pRetReadBuf->LastPacket = 1 ;			 
 }		 
 else if ( errFdi == ERR_NONE )		 
 {			 
 pRetReadBuf->LastPacket = 0 ;			 
 }		 
 else		 
 {			 
DIAG_FILTER ( FDI , Transport , F_Read_Error , DIAG_INFORMATION)  
 diagPrintf ( " File read error ( ID: %d , Error number: %d ) " , ( UINT16 ) hFileID , ( UINT16 ) errFdi );

			 
 free ( pRetReadBuf ) ;			 
 return ;			 
 }		 
DIAG_FILTER ( FDI , Transport , F_Read_Packet , DIAG_INFORMATION)  
 diagStructPrintf ( " %S { ReadReturnStruct } " , ( void* ) pRetReadBuf , sizeof ( ReadReturnStruct ) );

		 
 free ( pRetReadBuf ) ;		 
 }	 
 else	 
 { // Unsuccessful allocation		 
DIAG_FILTER ( FDI , Transport , F_Read_Malloc_Error , DIAG_INFORMATION)  
 diagPrintf ( " Malloc in Fread failed " );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , FreadEx 
 void _FreadEx ( void *pReadStruct ) 
 {	 
 ERR_CODE errFdi ;	 
 ReadReturnStruct_Ex* pRetReadBuf ;	 
 size_t nElementsToRead , nActualReadElemenets , nSizetoread , nWholeBytes ;	 
 UINT32 filepostoreadstart ;	 
 UINT32 packagecount = 0 ;	 
 FILE_ID hFileID = ( FILE_ID ) ( ( ( ReadInputStruct_Ex* ) pReadStruct ) ->fileID ) ;	 
	 
 nElementsToRead = ( size_t ) ( ( ( ReadInputStruct_Ex* ) pReadStruct ) ->bufferSize ) ;	 
 nWholeBytes = nSizetoread = ( size_t ) ( ( ( ReadInputStruct_Ex* ) pReadStruct ) ->sizetoRead ) ;	 
 filepostoreadstart = ( ( ReadInputStruct_Ex* ) pReadStruct ) ->filePos ;	 
	 
 pRetReadBuf = ( ReadReturnStruct_Ex* ) ( malloc ( sizeof ( ReadReturnStruct_Ex ) ) ) ;	 
 if ( !pRetReadBuf )	 
 {		 
 // Unsuccessful allocation		 
 { if ( log_config . log_cfg != LOG_DISABLE ) { ErrorLogPrintf_Extend ( " %08x " " %s: memory exhaust " " \r\n " , get_current_TStimer_tick ( ) , __FUNCTION__ ) ; } } ;		 
DIAG_FILTER ( FDI , Transport , F_Read_Malloc_Error , DIAG_INFORMATION)  
 diagPrintf ( " Malloc in Fread failed " );

		 
 return ;		 
 }	 
	 
 FDI_fseek ( hFileID , filepostoreadstart , 0 ) ;	 
	 
 while ( nSizetoread>0 )	 
 {		 
 memset ( pRetReadBuf , 0 , sizeof ( ReadReturnStruct_Ex ) ) ;		 
 pRetReadBuf->fileID = hFileID ;		 
 if ( nElementsToRead > ( 1024 *4 ) )		 
 {			 
 pRetReadBuf->filePos = filepostoreadstart ;			 
DIAG_FILTER ( FDI , Transport , F_Read_Bad_Input , DIAG_INFORMATION)  
 diagStructPrintf ( " %S { ReadReturnStruct_Ex } " , ( void* ) pRetReadBuf , sizeof ( ReadReturnStruct_Ex ) );

			 
			 
 free ( pRetReadBuf ) ;			 
 pRetReadBuf = 0 ;			 
 return ;			 
 }		 
		 
 if ( pRetReadBuf )		 
 {			 
 if ( nSizetoread>=nElementsToRead )			 
 {				 
 // CPUartLogPrintf ( " new FDI Read :%s --- FDI_freadEx ( nElementsToRead ) , nSizetoread = %d " , __FUNCTION__ , nSizetoread ) ;				 
 nActualReadElemenets = FDI_freadEx_fatsys ( & ( pRetReadBuf->readBuf ) , sizeof ( UINT8 ) , nElementsToRead , hFileID , filepostoreadstart ) ;				 
				 
 }			 
 else			 
 {				 
 // CPUartLogPrintf ( " new FDI Read :%s --- FDI_freadEx ( nSizetoread ) , nSizetoread = %d " , __FUNCTION__ , nSizetoread ) ;				 
 nActualReadElemenets = FDI_freadEx_fatsys ( & ( pRetReadBuf->readBuf ) , sizeof ( UINT8 ) , nSizetoread , hFileID , filepostoreadstart ) ;				 
 }			 
			 
			 
 errFdi = FDI_ferror ( hFileID ) ; // If any error occured errFdi will contain the error code.			 
 pRetReadBuf->PacketOK = ( UINT16 ) errFdi ; // Update the return struct to contain any error information.			 
 pRetReadBuf->PacketSize = nActualReadElemenets ;			 
			 
			 
 if ( ( errFdi == ERR_EOF ) || ( nActualReadElemenets < nElementsToRead ) )			 
 {				 
 pRetReadBuf->PacketOK = ( UINT16 ) ( ERR_EOF ) ;				 
 pRetReadBuf->LastPacket = 1 ;				 
 }			 
 else if ( errFdi == ERR_NONE )			 
 {				 
 pRetReadBuf->LastPacket = 0 ;				 
 }			 
 else			 
 {				 
 pRetReadBuf->filePos = filepostoreadstart ;				 
DIAG_FILTER ( FDI , Transport , F_Read_Error , DIAG_INFORMATION)  
 diagStructPrintf ( " %S { ReadReturnStruct_Ex } " , ( void* ) pRetReadBuf , sizeof ( ReadReturnStruct_Ex ) );

				 
 free ( pRetReadBuf ) ;				 
 pRetReadBuf = 0 ;				 
 return ;				 
 }			 
			 
 nSizetoread -= nActualReadElemenets ;			 
 pRetReadBuf->filePos = filepostoreadstart ;			 
DIAG_FILTER ( FDI , Transport , F_Read_PacketEx , DIAG_INFORMATION)  
 diagStructPrintf ( " %S { ReadReturnStruct_Ex } " , ( void* ) pRetReadBuf , sizeof ( ReadReturnStruct_Ex ) );

			 
 filepostoreadstart += nActualReadElemenets ;			 
			 
 if ( pRetReadBuf->LastPacket == 1 ) {				 
 free ( pRetReadBuf ) ;				 
 pRetReadBuf = 0 ;				 
 return ;				 
 }			 
			 
			 
 }		 
		 
 packagecount++ ;		 
		 
 if ( packagecount%8==0 )		 
 {			 
 OsaTaskSleep ( 5 , 0 ) ;			 
 }		 
 }	 
	 
 if ( pRetReadBuf )	 
 {		 
 free ( pRetReadBuf ) ;		 
 pRetReadBuf = 0 ;		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , Fwrite 
 void _Fwrite ( void * pWriteStruct ) 
 {	 
 ERR_CODE errFdi ;	 
 FILE_ID hFileID = ( FILE_ID ) ( ( ( WriteInputStruct* ) pWriteStruct ) ->fileID ) ;	 
 UINT32 numberOfElementsWritten = 0 ;	 
	 
 numberOfElementsWritten = FDI_fwrite ( ( ( ( WriteInputStruct* ) pWriteStruct ) ->writeBuf ) ,	 
 sizeof ( char ) ,	 
 ( ( ( WriteInputStruct* ) pWriteStruct ) ->PacketSize ) ,	 
 hFileID ) ;	 
	 
 if ( numberOfElementsWritten == ( ( ( WriteInputStruct* ) pWriteStruct ) ->PacketSize ) )	 
 {		 
DIAG_FILTER ( FDI , Transport , F_Write_Success , DIAG_INFORMATION)  
 diagPrintf ( " The Packet was written successfully ( packet size %d ) " , ( UINT16 ) ( ( ( WriteInputStruct* ) pWriteStruct ) ->PacketSize ) );

		 
 }	 
 else	 
 {		 
 errFdi = FDI_ferror ( hFileID ) ; // If any error occured errFdi will contain the error code.		 
DIAG_FILTER ( FDI , Transport , F_Write_Error , DIAG_INFORMATION)  
 diagPrintf ( " File write error ( ID: %d , Error number: %d ) " , ( UINT16 ) hFileID , ( UINT16 ) errFdi );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , FwriteEx 
 void _FwriteEx ( void * pWriteStruct ) 
 {	 
 ERR_CODE errFdi ;	 
 WriteReturnStruct_Ex* pRetWriteBuf ;	 
 FILE_ID hFileID = ( FILE_ID ) ( ( ( WriteInputStruct_Ex* ) pWriteStruct ) ->fileID ) ;	 
 UINT32 numberOfElementsWritten = 0 ;	 
 UINT32 filepostowrite , retCurfilepos ;	 
 filepostowrite = ( ( WriteInputStruct_Ex* ) pWriteStruct ) ->filePos ;	 
 retCurfilepos = filepostowrite ;	 
	 
	 
 pRetWriteBuf = ( WriteReturnStruct_Ex* ) ( malloc ( sizeof ( WriteReturnStruct_Ex ) ) ) ;	 
	 
 if ( !pRetWriteBuf )	 
 {		 
 // Unsuccessful allocation		 
 { if ( log_config . log_cfg != LOG_DISABLE ) { ErrorLogPrintf_Extend ( " %08x " " %s: memory exhaust " " \r\n " , get_current_TStimer_tick ( ) , __FUNCTION__ ) ; } } ;		 
DIAG_FILTER ( FDI , Transport , F_Write_Malloc_Error , DIAG_INFORMATION)  
 diagPrintf ( " Malloc in Fread failed " );

		 
 return ;		 
 }	 
	 
 numberOfElementsWritten = FDI_fwriteEx_fatsys ( ( ( ( WriteInputStruct_Ex* ) pWriteStruct ) ->writeBuf ) ,	 
 sizeof ( char ) ,	 
 ( ( ( WriteInputStruct_Ex* ) pWriteStruct ) ->PacketSize ) ,	 
 hFileID , filepostowrite ) ;	 
	 
 pRetWriteBuf->fileID = hFileID ;	 
 pRetWriteBuf->fileCurPos = retCurfilepos + numberOfElementsWritten ;	 
 pRetWriteBuf->PacketSize = numberOfElementsWritten ;	 
	 
 if ( numberOfElementsWritten == ( ( ( WriteInputStruct_Ex* ) pWriteStruct ) ->PacketSize ) )	 
 {		 
DIAG_FILTER ( FDI , Transport , F_Write_Success , DIAG_INFORMATION)  
 diagStructPrintf ( " %S { WriteReturnStruct_Ex } " , ( void* ) pRetWriteBuf , sizeof ( WriteReturnStruct_Ex ) );

		 
 }	 
 else	 
 {		 
 errFdi = FDI_ferror ( hFileID ) ; // If any error occured errFdi will contain the error code.		 
 pRetWriteBuf->PacketOK = ( UINT16 ) errFdi ;		 
DIAG_FILTER ( FDI , Transport , F_Write_Error , DIAG_INFORMATION)  
 diagStructPrintf ( " %S { WriteReturnStruct_Ex } " , ( void* ) pRetWriteBuf , sizeof ( WriteReturnStruct_Ex ) );

		 
 }	 
	 
	 
 free ( pRetWriteBuf ) ;	 
 pRetWriteBuf = 0 ;	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , Format_Flash 
 void _Format ( void ) 
 {	 
 ERR_CODE errFdi ;	 
	 
 errFdi = FDI_Format ( ) ;	 
 if ( errFdi == ERR_NONE ) // No errors occurred.	 
 {		 
DIAG_FILTER ( FDI , Transport , Format_Success , DIAG_INFORMATION)  
 diagPrintf ( " The flash was successfully formated " );

		 
 }	 
 else	 
 {		 
DIAG_FILTER ( FDI , Transport , Format_Error , DIAG_INFORMATION)  
 diagPrintf ( " An error occurred while formating ( %d ) " , errFdi );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , Remove_File 
 void _Remove ( void* fileName ) 
 {	 
 int errFdi ;	 
	 
 errFdi = FDI_remove ( ( char * ) fileName ) ;	 
 if ( errFdi == 0 )	 
 {		 
DIAG_FILTER ( FDI , Transport , Remove_Success , DIAG_INFORMATION)  
 diagPrintf ( " The file was successfully deleted " );

		 
 }	 
 else	 
 {		 
DIAG_FILTER ( FDI , Transport , Remove_Error , DIAG_INFORMATION)  
 diagPrintf ( " An error occurred while deleting file ( %d ) " , ( UINT16 ) errFdi );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , GetFileNameList 
 void _GetFileNameList ( void* wildcard ) 
 {	 
	 
 BOOL find = 0 ;	 
 int result = 0 , count = 0 ;	 
 FILE_ID hFileID ;	 
	 
 FILE_INFO file_info ; /* Holds the file information */	 
 char sTemp [ 256 +41 ] = { 0 } ; // max num of digits recieved from DWORD / int ( type of file attributes ) = 10 + file name length + 1 ( NULL terminator )	 
 INT16 ret_val , nFInfoListLen ;	 
 FNamesReturnStruct retFNamesStruct = { 0 } ;	 
	 
 if ( fs_mode_is_fat ( ) ==1 )	 
 {		 
		 
 { if ( LfsTraceEnable ) { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " lfs: " " _GetFileNameList: %s " , ( char* ) wildcard ) ; } } ; } } ;		 
 hFileID = FDI_OpenDir ( " / " ) ;		 
 if ( hFileID == 0 )		 
 {			 
DIAG_FILTER ( FDI , TRANSPORT , FName_DIR_NOTEXISTS , DIAG_INFORMATION)  
 diagPrintf ( " unsuccessful trial to open Current DIR " );

			 
 { if ( LfsTraceEnable ) { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " lfs: " " _GetFileNameList: fail to open Current DIR " ) ; } } ; } } ;			 
 return ;			 
 }		 
		 
 while ( 1 )		 
 {			 
 result = FDI_DirRead ( hFileID , &file_info ) ;			 
 if ( result != 1 )			 
 {				 
 { if ( LfsTraceEnable ) { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " lfs: " " FDI_DirRead result %d " , result ) ; } } ; } } ;				 
 break ;				 
 }			 
			 
 /* Skip " . " and " .. " */			 
 if ( ( file_info.file_name [ 0 ] != 0 ) && ( file_info.file_name [ 0 ] != 0x2E ) )			 
 {				 
 find = 1 ;				 
 break ;				 
 }			 
 }		 
		 
 if ( !find )		 
 {			 
DIAG_FILTER ( FDI , TRANSPORT , FName_LIST_NOTEXISTS , DIAG_INFORMATION)  
 diagPrintf ( " Currently There are no files on flash matching wildcard - %s " , ( char* ) wildcard );

			 
 { if ( LfsTraceEnable ) { { if ( log_config . log_cfg != LOG_DISABLE ) { UARTLogPrintf_Extend ( LOG_MODULE_MAX , " lfs: " " Currently There are no files on flash matching wildcard - %s " , ( char* ) wildcard ) ; } } ; } } ;			 
			 
 FDI_CloseDir ( hFileID ) ;			 
 return ;			 
 }		 
		 
 do		 
 {			 
 retFNamesStruct.LastPacket = 1 ;			 
 retFNamesStruct.fListLen = 0 ; /* Length meauered in number of files in the list */			 
 retFNamesStruct.fInfoList [ 0 ] = 0 ;			 
 nFInfoListLen = 0 ;			 
 do			 
 {				 
 /* Skip " . " and " .. " */				 
 if ( ( file_info.file_name [ 0 ] != 0x2E ) )				 
 {					 
 nFInfoListLen += sprintf ( sTemp , " %s@%d@%d@%lu@%u@ " , ( char* ) file_info.file_name , file_info.time , file_info.date , file_info.size , file_info.permissions ) ;					 
					 
 /* Check if file properties list will not exceed maximum list buffer length ( +1 counts the ' \n ' at the end ) */					 
 if ( ( nFInfoListLen+1 ) > 1024 )					 
 {						 
 retFNamesStruct.LastPacket = 0 ; /* Indicates on packet which DOES NOT contain all flash files information */						 
 break ;						 
 }					 
 retFNamesStruct.fListLen ++ ; /* counts number of files */					 
 strcat ( retFNamesStruct.fInfoList , sTemp ) ;					 
 }				 
				 
 result = FDI_DirRead ( hFileID , &file_info ) ;				 
 } while ( ( result == 1 ) && ( file_info.file_name [ 0 ] != 0 ) ) ; /* Loop until we don ' t find anymore files. */			 
			 
DIAG_FILTER ( FDI , Transport , F_NameList_Packet , DIAG_INFORMATION)  
 diagStructPrintf ( " %S { FNamesReturnStruct } " , ( void* ) &retFNamesStruct , sizeof ( FNamesReturnStruct ) );

			 
			 
 } while ( retFNamesStruct.LastPacket != ( UINT8 ) 1 ) ; /* Loop until we don ' t find anymore files. */		 
		 
 FDI_CloseDir ( hFileID ) ;		 
		 
		 
 }	 
	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , RenameFile 
 void _RenameFile ( void* pRenameStruct ) 
 {	 
 INT16 ret_val ;	 
 RenameInputStruct* pRenameSt = ( RenameInputStruct* ) pRenameStruct ;	 
	 
 ret_val = FDI_rename ( ( char* ) ( pRenameSt->fOldName ) , ( char* ) ( pRenameSt->fNewName ) ) ;	 
 if ( ret_val == 0 )	 
 {		 
DIAG_FILTER ( FDI , Transport , F_Rename_Succes , DIAG_INFORMATION)  
 diagPrintf ( " The file was successfully renamed to %s " , pRenameSt->fNewName );

		 
 }	 
 else	 
 {		 
DIAG_FILTER ( FDI , Transport , F_Rename_Error , DIAG_INFORMATION)  
 diagPrintf ( " Error occured while trying to change file name ( %d ) " , ret_val );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , FStatus 
 void _FStatus ( void* fileName ) 
 {	 
 INT32 fStatus ;	 
 INT32 ret_val ;	 
	 
 ret_val = FDI_stat ( ( char* ) fileName , ( int * ) &fStatus ) ;	 
 if ( ret_val == 0 )	 
 {		 
DIAG_FILTER ( FDI , Transport , F_Status_Success , DIAG_INFORMATION)  
 diagPrintf ( " ( %d ) " , fStatus );

		 
 }	 
 else	 
 {		 
DIAG_FILTER ( FDI , Transport , F_Status_Error , DIAG_INFORMATION)  
 diagPrintf ( " An error occurred while checking the file status ( %d ) " , ret_val );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , FchangeMode 
 void _FChangeMode ( void* stInChMode ) 
 {	 
 char* fileName = ( char* ) ( ( ( ChangModeStruct* ) stInChMode ) ->fileName ) ;	 
 INT32 newMode = ( INT32 ) ( ( ( ChangModeStruct* ) stInChMode ) ->newMode ) ;	 
	 
 if ( FDI_chmod ( fileName , newMode ) == 0 )	 
 {		 
DIAG_FILTER ( FDI , Transport , F_ChangeMode_Success , DIAG_INFORMATION)  
 diagPrintf ( " mode of %s was successfully changed " , fileName );

		 
 }	 
 else	 
 {		 
DIAG_FILTER ( FDI , Transport , F_ChangeMode_Error , DIAG_INFORMATION)  
 diagPrintf ( " An error occurred while changing %s mode " , fileName );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , Fseek 
 void _Fseek ( void* stFSeek ) 
 {	 
 FSeekStruct* fSeekSt = ( FSeekStruct* ) ( stFSeek ) ;	 
	 
 if ( FDI_fseek ( fSeekSt->fileID , fSeekSt->offset , fSeekSt->whereFrom ) == 0 )	 
 {		 
DIAG_FILTER ( FDI , Transport , Fseek_Success , DIAG_INFORMATION)  
 diagPrintf ( " File ( ID: %d ) indicator was offset by %d " , ( UINT16 ) ( fSeekSt->fileID ) , fSeekSt->offset );

		 
 }	 
 else	 
 {		 
DIAG_FILTER ( FDI , Transport , Fseek_Error , DIAG_INFORMATION)  
 diagPrintf ( " Error occured while trying to seek within file ( ID: %d ) " , ( UINT16 ) ( fSeekSt->fileID ) );

		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , GetMaxFileNameLen 
 void _GetMaxFileNameLength ( ) 
 {	 
DIAG_FILTER ( FDI , Transport , MaxFileNameLen , DIAG_INFORMATION)  
 diagPrintf ( " %d " , ( UINT16 ) ( 96 ) );

	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , GetFdiFdvSize 
 void _GetFdiFdvSize ( ) 
 {	 
	 
	 
 FdvSizeStruct retFdvSizeStruct ;	 
	 
	 
 {		 
 retFdvSizeStruct.fdvSize = FdvBlockSize*FdvBlockCount ;		 
 }	 
DIAG_FILTER ( FDI , Transport , FdvSpace , DIAG_INFORMATION)  
 diagStructPrintf ( " %S { FdvSizeStruct } " , ( void* ) &retFdvSizeStruct , sizeof ( FdvSizeStruct ) );

	 
	 
	 
	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , GetFdiFdvAvailableSpace 
 void _GetFdiFdvAvailableSpace ( void *volName ) 
 {	 
 ERR_CODE errCode ;	 
 FdvAvailableSpaceStruct retAvailableSpaceStruct ;	 
 UINT32 bytes_returned = 0 ;	 
 OSA_STATUS status ;	 
	 
	 
 {		 
		 
 if ( assertFlag != 1 )		 
 {			 
 if ( ( bspGetAcLinkType ( ) == AC_NONE ) )			 
 {				 
 status = OsaSemaphoreAcquire ( FatSysRef , 0xFFFFFFFF , 0 ) ;				 
 { if ( ! ( status == OS_SUCCESS ) ) { utilsAssertFail ( " status == OS_SUCCESS " , " FDI_Transport.c " , 1093 , 1 ) ; } } ;				 
 }			 
 }		 
		 
 if ( ( bspGetAcLinkType ( ) == AC_NONE ) )		 
 {			 
			 
 lfs_io_statfs ( " " , &bytes_returned ) ;			 
			 
			 
			 
 }		 
 else		 
 {			 
 bytes_returned = 0x20000 ;			 
 }		 
		 
 retAvailableSpaceStruct.fdvAvailableSpace = bytes_returned ;		 
 ACATwrapper_print_space ( ( void* ) &retAvailableSpaceStruct , sizeof ( FdvAvailableSpaceStruct ) ) ;		 
 // DIAG_FILTER ( FDI , Transport , FdvAvailableSize_RAM , DIAG_INFORMATION )		 
 // diagStructPrintf ( " %S { FdvAvailableSpaceStruct } " , ( VOID* ) &retAvailableSpaceStruct , sizeof ( FdvAvailableSpaceStruct ) ) ;		 
 if ( assertFlag != 1 )		 
 {			 
 if ( ( bspGetAcLinkType ( ) == AC_NONE ) )			 
 {				 
 status = OsaSemaphoreRelease ( FatSysRef , 0 ) ;				 
 { if ( ! ( status == OS_SUCCESS ) ) { utilsAssertFail ( " status == OS_SUCCESS " , " FDI_Transport.c " , 1119 , 1 ) ; } } ;				 
 }			 
			 
 }		 
 return ;		 
		 
 }	 
 }

//ICAT EXPORTED FUNCTION - FDI , Transport , GetFdiVersion 
 void _GetFdiVersion ( ) 
 {	 
DIAG_FILTER ( FDI , Transport , FDI5 , DIAG_INFORMATION)  
 diagPrintf ( " FDI 5 " );

	 
 }

