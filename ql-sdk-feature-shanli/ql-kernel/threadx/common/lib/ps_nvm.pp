//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\ps_nvm.ppp
//PPL Source File Name : \\tavor\\Arbel\\src\\ps_nvm.c
typedef unsigned int size_t ;
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

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT32 StructSize ;	 
 char StructNameString [ ( 30 ) ] ;	 
 char DateString [ ( 30 ) ] ;	 
 char TimeString [ ( 30 ) ] ;	 
 char HwId [ ( 30 ) ] ;	 
 char VersionString [ ( 30 ) ] ;	 
 char PcCalibrationSwVersionString [ ( 30 ) ] ;	 
 } NVMStructHeader_ts;

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
 /* @ENUM_DESC@ Enable or Disable a feature */	 
 SYS_DISABLE = 0 , /* @ENUM_VAL_DESC@ Enable this feature*/	 
 SYS_ENABLE = 1 /* @ENUM_VAL_DESC@ Disable this feature*/	 
 } systemfeatureenable_ts;

//ICAT EXPORTED ENUM 
 typedef enum // 0 ( disable ) , 1 ( core only ) , 3 ( core+PX ) , 7 ( core+PX+drowsy ) , F ( full ) 
 { /* @ENUM_DESC@ Not used in Tavor */	 
 DISABLE = 0x0 ,	 
 CORE_ONLY = 0x1 ,	 
 CORE_PX = 0x3 ,	 
 CORE_PX_DROWSY = 0x7 ,	 
 FULL = 0xF	 
 } xscalePowerManagement_ts;

//ICAT EXPORTED ENUM 
 typedef enum // 1 ( ICAT ) , 2 ( Modem ) , 4 ( Genie ) , 8 ( MAST ) ; ; 3 ( ICAT Modem ) , 5 ( ICAT Genie ) , 7 ( ICAT Modem Genie ) , A ( ICAT Modem Genie MassStorage ) , F ( full ) 
 {	 
 /* @ENUM_DESC@ Defines the USB work mode - not to be changed for Tavor*/	 
 ICAT = 0x1 , /* @ENUM_VAL_DESC@ Configure USB to work with ACAT only*/	 
 MODEM = 0x2 , /* @ENUM_VAL_DESC@ Configure USB to work as Modem only*/	 
 ICAT_MODEM = 0x3 , /* @ENUM_VAL_DESC@ Configure USB to work with ACAT and Modem*/	 
 GENIE = 0x4 , /* @ENUM_VAL_DESC@ Configure USB to work with Genie only*/	 
 ICAT_GENIE = 0x5 , /* @ENUM_VAL_DESC@ Configure USB to work with ACAT and Genie*/	 
 ICAT_MODEM_GENIE = 0x7 , /* @ENUM_VAL_DESC@ Configure USB to work with ACAT Genie and as a Modem*/	 
 MAST = 0x8 , /* @ENUM_VAL_DESC@ Configure USB to work as mass storage device only*/	 
 MODEM_MAST = 0xA , /* @ENUM_VAL_DESC@ Configure USB to work as Modem and mass storage device only*/	 
 USB_FULL = 0xF /* @ENUM_VAL_DESC@ Configure USB to work with ACAT , Genie , and as Modem and mass storage device in parallel*/	 
 } USBConfiguration_ts;

//ICAT EXPORTED ENUM 
 typedef enum // 0 ( disable ) , 1 ( core only ) , 3 ( core+PX ) , 7 ( core+PX+drowsy ) , F ( full ) 
 { /* @ENUM_DESC@ Not used in Tavor */	 
 UF_NONE = 0x0 ,	 
 UF_UART_1 = 0x1 ,	 
 UF_UART_2 = 0x2 ,	 
 UF_UART_1_2 = 0x3 ,	 
 UF_UART_3 = 0x4 ,	 
 UF_UART_1_3 = 0x5 ,	 
 UF_UART_2_3 = 0x6 ,	 
 UF_UART_1_2_3 = 0x7	 
 } uartForceAwakeMode_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 { /* @STRUCT_DESC@ Protocol features */	 
 systemfeatureenable_ts PS_INIT_AUTO ; /* @ITEM_DESC@ When enabled L2 / 3 will be initiated at power on. It is set to off mainly during calibration mode where L2\3 is not used. @ITEM_MODE@ ReadWrite @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts GSM_DRX_SLEEP ; /* @ITEM_DESC@ Enables GSM DRX sleep @ITEM_MODE@ ReadWrite @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts WBCDMA_DRX_SLEEP ; /* @ITEM_DESC@ Enables UMTS DRX sleep @ITEM_MODE@ ReadWrite @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts IN_GSM ; /* @ITEM_DESC@ When enabled UE will start in GSM mode at power up @ITEM_MODE@ ReadWrite @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts ONLY_GSM ; /* @ITEM_DESC@ prevent WCDMA measurements during GSM mode to prevent reselection to WCDMA - not used @ITEM_MODE@ ReadWrite @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts CIRCUIT_SWITCHED_ONLY ; /* @ITEM_DESC@ if enabled it disables PS services @ITEM_MODE@ ReadWrite @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts RESERVED ; /* @ITEM_DESC@ not used @ITEM_MODE@ ReadOnly @ITEM_UNIT@ not used */	 
 systemfeatureenable_ts UICC_PROTOCOL_T0_ONLY ; /* @ITEM_DESC@ USIM - Force working with T=0 protocol @ITEM_MODE@ ReadWrite @ITEM_UNIT@ Enable / Disable */	 
 } systemfeaturesParams_ts;

//ICAT EXPORTED ENUM 
 typedef enum // 0 ( disable ) , 1 ( enable ) 
 { /* @ENUM_DESC@ PS-feature to reduce accesses to NVM */	 
 NVM_ACCESS_NORMAL_READ_WRITE , /* @ENUM_VAL_DESC@ Always read , write GKI file from , to NVM*/	 
 NVM_ACCESS_REDUCED_ON_CFUN01_ONLY /* @ENUM_VAL_DESC@ Read GKI-file upon CFUN1 , Write upon CFUN0 only*/	 
 } psNvmAccessBehavior_e;

//ICAT EXPORTED STRUCT 
 typedef struct 
 { /* @STRUCT_DESC@ Reserved - not used */	 
 psNvmAccessBehavior_e psNvmAccessBehavior ; /* @ITEM_DESC@ PS-feature to reduce NVM accesses , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ Enable / Disable */	 
 UINT8 isInProductionLine ;	 
 UINT16 RESERVED1 ; /* @ITEM_DESC@ not used , @ITEM_MODE@ ReadOnly @ITEM_UNIT@ special dbg using */	 
 } systemfeaturesUnderDevelopment_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 { /* @STRUCT_DESC@ Enables GSM GRR extended logging */	 
 systemfeatureenable_ts GRR_LOG_CELL_SELECTION_L3MSG ; /* @ITEM_DESC@ Messages received in MphUnitDataInd during cell selection , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts GRR_LOG_CCT_SWTCH_IDLE_L3MSG ; /* @ITEM_DESC@ Messages received in MphUnitDataInd while in CCCH idle , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts GRR_LOG_CCT_SWTCH_ESTAB_L3MSG ; /* @ITEM_DESC@ Messages received in MphUnitDataInd while establishing on RACH / AGCH , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts GRR_LOG_PLMN_SEARCH_L3MSG ; /* @ITEM_DESC@ Messages received in MphUnitDataInd while PLMN searching , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts GRR_LOG_CCT_SWTC_DED_L3MSG ; /* @ITEM_DESC@ Messages received in DlUnitDataInd / DlDataInd in dedicated mode , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts GRR_LOG_RET_TO_IDLE_L3MSG ; /* @ITEM_DESC@ Messages received in MphUnitDataInd while returning to idle state , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts GRR_LOG_PKT_IDLE_CCCH_L3MSG ; /* @ITEM_DESC@ All messages received in MphUnitDataInd in packet idle , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts GRR_LOG_PKT_L3MSG ; /* @ITEM_DESC@ Messages received in GrrMacPktControlInd ( GRRPL3 ) , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts GRR_LOG_PKT_SYS_INFO_MSG ; /* @ITEM_DESC@ Packet System Information messages , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts GRR_LOG_IR_RESELECTION_L3MSG ; /* @ITEM_DESC@ log Inter RAT reselection messages , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ Enable / Disable */	 
 systemfeatureenable_ts RESERVED1 ; /* @ITEM_DESC@ not used , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ not used */	 
 systemfeatureenable_ts RESERVED2 ; /* @ITEM_DESC@ not used , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ not used */	 
 } GRRLogs_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 { /* @ENUM_DESC@ UMTS RLC release 5 extention - changing the Acknowldege Mode ( AM ) buffer size */	 
 R5_EXT_KB200=0 , /* @ENUM_VAL_DESC@ 200 Kbyte*/	 
 R5_EXT_KB300=1 , /* @ENUM_VAL_DESC@ 300 Kbyte*/	 
 R5_EXT_KB400=2 , /* @ENUM_VAL_DESC@ 400 Kbyte*/	 
 R5_EXT_KB750=3 /* @ENUM_VAL_DESC@ 750 Kbyte*/	 
 } TotalRLC_AM_BufferSize_r5ext_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 { /* @ENUM_DESC@ UMTS RLC - changing the RLC maximum window size */	 
 MWS2047 = 2047 , /* @ENUM_VAL_DESC@ 2047 */	 
 MWS4095 = 4095 /* @ENUM_VAL_DESC@ 4095 - not supported*/	 
 } MaximumRLC_WindowSize_ts;

//ICAT EXPORTED ENUM 
 typedef enum 
 { /* @ENUM_DESC@ UMTS RLC - changing the Acknowldege Mode ( AM ) buffer size */	 
 DUMMY=0 , /* @ENUM_VAL_DESC@ dummy*/	 
 KB10=1 , /* @ENUM_VAL_DESC@ 10 Kbyte*/	 
 KB50=2 , /* @ENUM_VAL_DESC@ 50 Kbyte*/	 
 KB100=3 , /* @ENUM_VAL_DESC@ 100 Kbyte*/	 
 KB150=4 , /* @ENUM_VAL_DESC@ 150 Kbyte*/	 
 KB500=5 , /* @ENUM_VAL_DESC@ 500 Kbyte*/	 
 KB1000=6 , /* @ENUM_VAL_DESC@ 1000 Kbyte*/	 
 SPARE=7 /* @ENUM_VAL_DESC@ not used*/	 
 } TotalRLC_AM_BufferSize_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 { /* @STRUCT_DESC@ Part of the Mobile Equipement parameters reported to the network that can be changed. */	 
 TotalRLC_AM_BufferSize_r5ext_ts TOTAL_RLC_AM_BUFFER_SIZE_R5EXT ; // int8 , default is UTotalRLC_AM_BufferSize_r5_ext_kb200 / * @ITEM_DESC@ Total UMTS RLC AM release 5 extention buffer size @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see Structure definition * /	 
 TotalRLC_AM_BufferSize_ts TOTAL_RLC_AM_BUFFER_SIZE ; // int8 / * @ITEM_DESC@ Total UMTS RLC AM buffer size @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see Structure definition * /	 
 MaximumRLC_WindowSize_ts MAX_RLC_WINDOW_SIZE ; // int16 ( ? ) / * @ITEM_DESC@ Maximum UMTS RLC window size @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see Structure definition * /	 
 UINT8 BIT_MAP_ALGO_A5_AVAILABLE ; // int 8 / * @ITEM_DESC@ Decleration of supported chipering algoritm for GSM @ITEM_MODE@ ReadWrite @ITEM_UNIT@ bitmap * /	 
 UINT8 BIT_MAP_ALGO_GPRS_AVAILABLE ; /* @ITEM_DESC@ Decleration of supported chipering algoritm for GPRS @ITEM_MODE@ ReadWrite @ITEM_UNIT@ bitmap */	 
 UINT8 BIT_MAP_UEA1_UEA0 ; /* @ITEM_DESC@ Decleration of supported chipering algoritm for UMTS @ITEM_MODE@ ReadWrite @ITEM_UNIT@ bitmap */	 
 } MobileEquipment_ts;

typedef UINT16 Mcc ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 { /* @STRUCT_DESC@ MCC for PCS classmark 3 . Used for debug , mainly during IOT */	 
 systemfeatureenable_ts isMccValid ; // use / not use the mcc / * @ITEM_DESC@ If Enabled the below Mcc is used @ITEM_MODE@ ReadWrite @ITEM_UNIT@ Enable / Disable * /	 
 Mcc mcc ; /* @ITEM_DESC@ Mcc to use , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ mcc */	 
 } MccForClassmark3_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 { /* @STRUCT_DESC@ List of desired ARFCN ' s to search. Used to ignore other cells which we do not want to camp on .Used for Debug only mainly during IOT. This chose will be relevant during the initial cell search only. It will have no effect on the measurements , reselections and HHO. */	 
 systemfeatureenable_ts GrrCampOnDesArfcn ; /* @ITEM_DESC@ When enabled , only the following list of ARFCN ' s will be searched @ITEM_MODE@ ReadWrite @ITEM_UNIT@ Enable / Disable */	 
 INT8 GrrCampOnDesNumberOfArfcn2Search ; /* @ITEM_DESC@ Number of ARFCN ' s to search , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ 1 -5 */	 
 UINT16 GrrCampOnDesArfcnList [ 5 ] ; /* @ITEM_DESC@ List of ARFCN ' s to search , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ ARFCN list*/	 
	 
 } GsmResidesArfcn_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 { /* @STRUCT_DESC@ protocol paramaters that used mainly during IOT */	 
 GRRLogs_ts GRRLogs ; // 12 *int8 / * @ITEM_DESC@ When enabled , only a provided list of ARFCN ' s will be searched @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see Structure definition * /	 
 systemfeatureenable_ts GMM_REL_CONTEXT_T3312_EXPIRY ; // int8 / * @ITEM_DESC@ If disabled GMM will not release PDP context on T3312 expiry. For debug use. @ITEM_MODE@ ReadWrite @ITEM_UNIT@ Enable / Disable * /	 
 MobileEquipment_ts MobileEquipment ; // int8 / * @ITEM_DESC@ Mobile equipement parameters , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ see Structure definition * /	 
 MccForClassmark3_ts mccForPcsClassmark3 ; /* @ITEM_DESC@ MCC for PCS classmark 3 . Used for debug , mainly during IOT @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see Structure definition */	 
 GsmResidesArfcn_ts GsmResideOnlyOnFollowingARFCNs ; /* @ITEM_DESC@ When enabled , only a provided list of ARFCN ' s will be searched @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see Structure definition */	 
 UINT16 LlcDisableUiHistoryCheckOnSapi ; /* @ITEM_DESC@ Discarding duplicate UI frames on certain SAPI @ITEM_MODE@ ReadWrite @ITEM_UNIT@ none */	 
 } IOTParams_ts;

typedef UINT32 VendorSpecificInfo_ts ;
//ICAT EXPORTED ENUM 
 typedef enum 
 { /* @ENUM_DESC@ Used for internal debug only */	 
 ACI_SW_DEFAULT = 0 , // use SW default	 
 ACI_SAC_ONLY = 1 ,	 
 ACI_GKI_ONLY = 2 ,	 
 ACI_COMBINED = 3	 
 } AciSacGki_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ System and common Protocol configurable parameters */	 
 /* @STRUCT_NVM_FILE_NAME@ SystemControl.nvm */	 
	 
 systemfeaturesParams_ts featuresParams ; /* @ITEM_DESC@ Protocol features @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see Structure definition */	 
 systemfeaturesUnderDevelopment_ts developmentSwitch ; /* @ITEM_DESC@ reserved @ITEM_MODE@ ReadOnly @ITEM_UNIT@ not used */	 
 xscalePowerManagement_ts xscalePowerManagement ; /* @ITEM_DESC@ Not used in Tavor @ITEM_MODE@ ReadOnly @ITEM_UNIT@ obsolate */	 
 USBConfiguration_ts USBConfiguration ; /* @ITEM_DESC@ Defines the USB work mode - not to be changed for Tavor @ITEM_MODE@ ReadOnly @ITEM_UNIT@ see Structure definition */	 
 uartForceAwakeMode_ts uartForceAwakeMode ; /* @ITEM_DESC@ Not used in Tavor @ITEM_MODE@ ReadOnly @ITEM_UNIT@ obsolate */	 
 AciSacGki_ts aciSacGki ; /* @ITEM_DESC@ Used for internal debug only @ITEM_MODE@ ReadOnly @ITEM_UNIT@ see Structure definition */	 
 VendorSpecificInfo_ts vendorSpecificInfo ; /* @ITEM_DESC@ Enables Vendor specific requirements @ITEM_MODE@ ReadWrite @ITEM_UNIT@ bitmap of supported vendors. */	 
 /*-----------------6 / 7 / 2007 3 :11PM------------------	 
 * NVM programmable parameters for IOT	 
 * --------------------------------------------------*/	 
 IOTParams_ts IOTParams ; /* @ITEM_DESC@ paremeters used mainly during IOT @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see Structure definition */	 
 // end of NVM programmable parameters for IOT	 
 /*Fixed CQ00024251 xyzheng for U+D optimistion start 2012 -11-07*/	 
	 
 /*Fixed for U+D begin date: 2010 -08-11 yinfei*/	 
 UINT8 optMethodFlag ; /*@ITEM_DESC@ 0 : optimization off 1 : 1000 threhold version 2 : test version for higher quility default is 1 */	 
 /*cgliu 20130922 for sync nvm*/	 
 // UINT8 reserved2 [ 3 ] ;	 
 UINT8 ratioForHWMDiscardData ;	 
 UINT16 GCFTimingAdvance ;	 
 /*Fixed for U+D End date: 2010 -08-11 yinfei*/	 
	 
 /*Fixed CQ00024251 xyzheng for U+D optimistion end 2012 -11-07*/	 
	 
 UINT32 reserved2 ; /* @ITEM_DESC@ reserved , @ITEM_MODE@ ReadOnly , @ITEM_UNIT@ not used */	 
 UINT32 reserved3 ; /* @ITEM_DESC@ reserved @ITEM_MODE@ ReadOnly @ITEM_UNIT@ not used */	 
 } SystemcNvm_ts;

//ICAT EXPORTED STRUCT AutoDoc System 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ System and common Protocol configurable parameters */	 
 BOOL IMSNWReportStatus ;	 
 BOOL NWIMSVoPS ;	 
 BOOL EmerBearerSrvReportStatus ;	 
 BOOL EmerBearerSRVIuStatus ;	 
 BOOL EmerBearerSRVS1Status ;	 
 } IMSNWReportStatusNvm_ts;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 /* @STRUCT_DESC@ System and common Protocol configurable parameters */	 
 /* @STRUCT_NVM_FILE_NAME@ TermnialProfile */	 
 UINT8 LengthOfSatProfile ; /* @ITEM_DESC@ Length of SAT profile , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ 0 -20 */	 
 UINT8 SatProfile [ 64 ] ; /* @ITEM_DESC@ SAT Terminal Profile , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ SAT profile*/	 
	 
 UINT8 LengthOfUsatProfile ; /* @ITEM_DESC@ Length of USAT profile , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ 0 -20 */	 
 UINT8 UsatProfile [ 64 ] ; /* @ITEM_DESC@ USAT Terminal Profile , @ITEM_MODE@ ReadWrite , @ITEM_UNIT@ USAT profile*/	 
 } TermProfileNvm_ts;

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

DIAG_FILTER ( SYSTEM , SYSNVM , psNvmReadPsmContext_01 , DIAG_INFORMATION)  
 diagPrintf ( " File %s doesn ' t exist - using System defaults " , " PsmContextProfile.nvm " );

DIAG_FILTER ( SYSTEM , SYSNVM , psNvmReadPsmContext_02 , DIAG_INFORMATION)  
 diagPrintf ( " File %s doesn ' t exist - using System defaults " , " PsmContextProfile1.nvm " );

DIAG_FILTER ( SYSTEM , SYSNVM , psNvmReadPsmContext_03 , DIAG_INFORMATION)  
 diagPrintf ( " File %s OPEN error! " , " PsmContextProfile.nvm " );

DIAG_FILTER ( SYSTEM , SYSNVM , psNvmReadPsmContext_4 , DIAG_INFORMATION)  
 diagPrintf ( " File %s OPEN error! " , " PsmContextProfile1.nvm " );

DIAG_FILTER ( SYSTEM , SYSNVM , psNvmReadPsmContext_05 , DIAG_INFORMATION)  
 diagPrintf ( " Read %d words from file %s " , fileInfo.size-sizeof ( NVM_Header_ts ) , " PsmContextProfile.nvm " );

DIAG_FILTER ( SYSTEM , SYSNVM , psNvmReadPsmContext_06 , DIAG_INFORMATION)  
 diagPrintf ( " Read %d words from file %s " , fileInfo.size-sizeof ( NVM_Header_ts ) , " PsmContextProfile1.nvm " );

DIAG_FILTER ( SYSTEM , SYSNVM , psNvmSavePsmContext_01 , DIAG_INFORMATION)  
 diagPrintf ( " Save %s from PSM context " , " PsmContextProfile.nvm " );

DIAG_FILTER ( SYSTEM , SYSNVM , psNvmSavePsmContext_02 , DIAG_INFORMATION)  
 diagPrintf ( " Save %s from PSM context " , " PsmContextProfile1.nvm " );

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreateCellLockInfo 
 BOOL psNvmCreateIMSNWReportInfo ( IMSNWReportStatusNvm_ts* params ) 
 {	 
	 
 FILE_ID fdiID ;	 
	 
 char fileName [ ( 30 ) ] ;	 
 strcpy ( fileName , " IMSNWReportingProfile " ) ;	 
	 
 memcpy ( &IMSNWReportModeParams , params , sizeof ( IMSNWReportStatusNvm_ts ) ) ;	 
	 
 fdiID = FDI_remove ( ( const FDI_TCHAR * ) fileName ) ;	 
	 
 /* ' 0 ' open fail , ! ' 0 ' open ok. */	 
 if ( ( fdiID = FDI_fopen ( ( const FDI_TCHAR * ) fileName , " wb+ " ) ) != 0 )	 
 {		 
 FDI_fwrite ( &IMSNWReportModeParams , sizeof ( IMSNWReportStatusNvm_ts ) , 1 , fdiID ) ;		 
 FDI_fclose ( fdiID ) ;		 
 }	 
	 
 return 1 ;	 
	 
 }

DIAG_FILTER ( SYSTEM , SYSNVM , psNvmSetTermProfileNvmDefaultParams_0 , DIAG_INFORMATION)  
 diagPrintf ( " termProfileParams.LengthOfSatProfile=%d , termProfileParams.LengthOfUsatProfile=%d " , termProfileParams.LengthOfSatProfile , termProfileParams.LengthOfUsatProfile );

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreateTermProfile 
 BOOL psNvmCreateTermProfile ( TermProfileNvm_ts* params ) 
 {	 
	 
 FILE_ID fdiID ;	 
	 
 char fileName [ ( 30 ) ] ;	 
 strcpy ( fileName , " TerminalProfile " ) ;	 
	 
 memcpy ( &termProfileParams , params , sizeof ( TermProfileNvm_ts ) ) ;	 
	 
 fdiID = FDI_remove ( ( const FDI_TCHAR * ) fileName ) ;	 
	 
 /* ' 0 ' open fail , ! ' 0 ' open ok. */	 
 if ( ( fdiID = FDI_fopen ( ( const FDI_TCHAR * ) fileName , " wb+ " ) ) != 0 )	 
 {		 
 FDI_fwrite ( &termProfileParams , sizeof ( TermProfileNvm_ts ) , 1 , fdiID ) ;		 
 FDI_fclose ( fdiID ) ;		 
 }	 
	 
 return 1 ;	 
	 
 }

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreate 
 BOOL psNvmCreate ( void ) 
 {	 
	 
	 
 FILE_ID fileIndex ;	 
 UINT32 StructSize = sizeof ( SystemcNvm_ts ) ;	 
	 
	 
	 
	 
 NVM_Header_ts header = {		 
 StructSize , // StructSize		 
 1 , // NumofStructs		 
 " SystemcNvm_ts " , // StructName		 
 " NULL " , // Date		 
 " NULL " , // time		 
 " 4.000000 " , // Version		 
 " 0 " , // HW_ID		 
 " 0 " // CalibVersion		 
 } ;	 
	 
	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateNew , DIAG_INFORMATION)  
 diagPrintf ( " Creating %s from SYSTEM_DEFAULT_DATA " , " SystemControl.nvm " );

	 
	 
 fileIndex = FDI_fopen ( " SystemControl.nvm " , " wb " ) ;	 
	 
	 
 // Create NVM standard header	 
 FDI_CreateNVMFormatHeader ( &header , StructSize , 1 , " SystemcNvm_ts " , " 4.000000 " , " 0 " , " 0 " ) ;	 
	 
 FDI_fwrite ( &header , sizeof ( NVM_Header_ts ) , 1 , fileIndex ) ;	 
	 
 psNvmSetSystemcNvmDefaultParams ( ) ;	 
	 
 FDI_fwrite ( &systemcNvmParams , sizeof ( systemcNvmParams ) , 1 , fileIndex ) ;	 
	 
	 
 FDI_fclose ( fileIndex ) ;	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateCompNew , DIAG_INFORMATION)  
 diagPrintf ( " %s create completed " , " SystemControl.nvm " );

	 
	 
 return ( 1 ) ;	 
	 
	 
	 
	 
	 
 }

DIAG_FILTER ( SYSTEM , SYSNVM , SYS_CREATE_NVM_FILE , DIAG_INFORMATION)  
 diagPrintf ( " File %s doesn ' t exist - using System defaults " , " SystemControl.nvm " );

DIAG_FILTER ( SYSTEM , SYSNVM , SYS_READ_NVM , DIAG_INFORMATION)  
 diagPrintf ( " Read %d words from file %s " , info.size , " SystemControl.nvm " );

DIAG_FILTER ( SYSTEM , SYSNVM , Warnning_OldVersionOfSystemControlNvmFile , DIAG_INFORMATION)  
 diagPrintf ( " Warnning - incompatible version of %s. Version %s instead of %s. Deleting the file and using system defaults " , 
 " SystemControl.nvm " , header.Version , " 4.000000 " );

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmEnableDisablePsInit 
 BOOL psNvmEnableDisablePsInitAuto ( UINT16* mmode ) 
 {	 
	 
	 
 FILE_ID fileIndex ;	 
 UINT32 StructSize = sizeof ( SystemcNvm_ts ) ;	 
	 
	 
 NVM_Header_ts header ;	 
	 
	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreatePsInitAuto1 , DIAG_INFORMATION)  
 diagPrintf ( " start Create %s from SYSTEM_DEFAULT_DATA " , " SytemControl " );

	 
	 
 fileIndex = FDI_fopen ( " SystemControl.nvm " , " wb " ) ;	 
	 
	 
 // Create NVM standard header	 
 FDI_CreateNVMFormatHeader ( &header , StructSize , 1 , " SystemcNvm_ts " , " 4.000000 " , " 0 " , " 0 " ) ;	 
	 
 FDI_fwrite ( &header , sizeof ( NVM_Header_ts ) , 1 , fileIndex ) ;	 
	 
 psNvmSetSystemcNvmDefaultParams ( ) ;	 
	 
 if ( *mmode == 1 )	 
 {		 
 systemcNvmParams.featuresParams.PS_INIT_AUTO = SYS_ENABLE ;		 
 }	 
 else	 
 {		 
 systemcNvmParams.featuresParams.PS_INIT_AUTO = SYS_DISABLE ;		 
 }	 
	 
 FDI_fwrite ( &systemcNvmParams , sizeof ( systemcNvmParams ) , 1 , fileIndex ) ;	 
	 
	 
 FDI_fclose ( fileIndex ) ;	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateCompPsInitAuto , DIAG_INFORMATION)  
 diagPrintf ( " SystemControl create completed , PS_INIT_AUTO = %d " , systemcNvmParams.featuresParams.PS_INIT_AUTO );

	 
	 
 return ( 1 ) ;	 
	 
	 
	 
	 
	 
 }

DIAG_FILTER ( SYSTEM , SYSNVM , psVendorPrintf_1 , DIAG_INFORMATION)  
 diagPrintf ( " original vendor information VENDOR_SPECIFIC_INFO_NULL " );

DIAG_FILTER ( SYSTEM , SYSNVM , psVendorPrintf_2 , DIAG_INFORMATION)  
 diagPrintf ( " original vendor information VENDOR_SPECIFIC_INFO_ATT " );

DIAG_FILTER ( SYSTEM , SYSNVM , psVendorPrintf_3 , DIAG_INFORMATION)  
 diagPrintf ( " original vendor information VENDOR_SPECIFIC_INFO_CMCC " );

DIAG_FILTER ( SYSTEM , SYSNVM , psVendorPrintf_4 , DIAG_INFORMATION)  
 diagPrintf ( " original vendor information VENDOR_SPECIFIC_INFO_RRM " );

DIAG_FILTER ( SYSTEM , SYSNVM , psVendorPrintf_5 , DIAG_INFORMATION)  
 diagPrintf ( " original vendor information VENDOR_SPECIFIC_INFO_MTNET " );

DIAG_FILTER ( SYSTEM , SYSNVM , psVendorPrintf_7 , DIAG_INFORMATION)  
 diagPrintf ( " original vendor information VENDOR_SPECIFIC_INFO_IOT " );

DIAG_FILTER ( SYSTEM , SYSNVM , psVendorPrintf_8 , DIAG_INFORMATION)  
 diagPrintf ( " original vendor information VENDOR_SPECIFIC_INFO_SILENTRESET " );

DIAG_FILTER ( SYSTEM , SYSNVM , psVendorPrintf_9 , DIAG_INFORMATION)  
 diagPrintf ( " original vendor information VENDOR_SPECIFIC_INFO_PSOPT " );

DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateNew1 , DIAG_INFORMATION)  
 diagPrintf ( " start Create %s from SYSTEM_DEFAULT_DATA and Vendor Specific 0x%x " , " SytemControl " , *mmode );

DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateCompNew1 , DIAG_INFORMATION)  
 diagTextPrintf ( " SystemControl create completed " );

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreateH3G 
 BOOL psNvmCreateH3G ( void ) 
 {	 
 VendorSpecificInfo_ts mmode = ( 0x10 ) ;	 
	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateNew2 , DIAG_INFORMATION)  
 diagPrintf ( " start to create %s Vendor Specific Data " , " H3G " );

	 
 return psNvmCreateVS ( &mmode ) ;	 
 }

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreateNull 
 BOOL psNvmCreateNull ( void ) 
 {	 
 VendorSpecificInfo_ts mmode = ( 0 ) ;	 
	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateNew3 , DIAG_INFORMATION)  
 diagPrintf ( " start to create %s Vendor Specific Data " , " Null " );

	 
 return psNvmCreateVS ( &mmode ) ;	 
 }

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreateATT 
 BOOL psNvmCreateATT ( void ) 
 {	 
 VendorSpecificInfo_ts mmode = ( 0x01 ) ;	 
	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateNew2 , DIAG_INFORMATION)  
 diagPrintf ( " start to create %s Vendor Specific Data " , " AT&T " );

	 
 return psNvmCreateVS ( &mmode ) ;	 
 }

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreateCMCC 
 BOOL psNvmCreateCMCC ( void ) 
 {	 
 VendorSpecificInfo_ts mmode = ( 0x02 ) ;	 
	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateNew3 , DIAG_INFORMATION)  
 diagPrintf ( " start to create %s Vendor Specific Data " , " CMCC " );

	 
 return psNvmCreateVS ( &mmode ) ;	 
 }

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreateTELCE 
 BOOL psNvmCreateTELCE ( void ) 
 {	 
 VendorSpecificInfo_ts mmode = ( 0x08 ) ;	 
	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateNew6 , DIAG_INFORMATION)  
 diagPrintf ( " start to create %s Vendor Specific Data " , " TELCE " );

	 
 return psNvmCreateVS ( &mmode ) ;	 
 }

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreateVDF 
 BOOL psNvmCreateVDF ( void ) 
 {	 
 VendorSpecificInfo_ts mmode = ( 0x20 ) ;	 
	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateNew7 , DIAG_INFORMATION)  
 diagPrintf ( " start to create %s Vendor Specific Data " , " VDF " );

	 
 return psNvmCreateVS ( &mmode ) ;	 
 }

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreateMANUFACTURESILVER 
 BOOL psNvmCreateMANUFACTURESILVER ( void ) 
 {	 
 VendorSpecificInfo_ts mmode = ( 0x40 ) ;	 
	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateNew71 , DIAG_INFORMATION)  
 diagPrintf ( " start to create %s Vendor Specific Data " , " MANUFACTURE_SILVER " );

	 
 return psNvmCreateVS ( &mmode ) ;	 
 }

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreate2GROMING 
 BOOL psNvmCreate2GROMING ( void ) 
 {	 
 VendorSpecificInfo_ts mmode = ( 0x1000 ) ;	 
	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateNew7 , DIAG_INFORMATION)  
 diagPrintf ( " start to create %s Vendor Specific Data " , " 2 G ROAMING " );

	 
 return psNvmCreateVS ( &mmode ) ;	 
 }

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreateCTA 
 BOOL psNvmCreateCTA ( void ) 
 {	 
 VendorSpecificInfo_ts mmode = ( 0x04 ) ;	 
	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateNew6 , DIAG_INFORMATION)  
 diagPrintf ( " start to create %s Vendor Specific Data " , " CTA " );

	 
 return psNvmCreateVS ( &mmode ) ;	 
 }

//ICAT EXPORTED FUNCTION - PS , SYSNVM , psNvmCreateOptVersion 
 void psNvmCreateOptVersion ( UINT8 *versionNum ) 
 {	 
	 
	 
 FILE_ID fileIndex ;	 
 UINT32 StructSize = sizeof ( SystemcNvm_ts ) ;	 
	 
	 
 NVM_Header_ts header ;	 
	 
	 
	 
 psNvmRead ( ) ;	 
	 
 systemcNvmParams.optMethodFlag = *versionNum ;	 
DIAG_FILTER ( SYSTEM , SYSNVM , SYS_NVM_CreateNew6 , DIAG_INFORMATION)  
 diagPrintf ( " start to create OptVersion %d " , *versionNum );

	 
	 
	 
	 
	 
 fileIndex = FDI_fopen ( " SystemControl.nvm " , " wb " ) ;	 
	 
	 
 // Create NVM standard header	 
 FDI_CreateNVMFormatHeader ( &header , StructSize , 1 , " SystemcNvm_ts " , " 4.000000 " , " 0 " , " 0 " ) ;	 
	 
 FDI_fwrite ( &header , sizeof ( NVM_Header_ts ) , 1 , fileIndex ) ;	 
	 
	 
	 
 FDI_fwrite ( &systemcNvmParams , sizeof ( systemcNvmParams ) , 1 , fileIndex ) ;	 
	 
	 
 FDI_fclose ( fileIndex ) ;	 
	 
	 
	 
	 
	 
	 
 }

