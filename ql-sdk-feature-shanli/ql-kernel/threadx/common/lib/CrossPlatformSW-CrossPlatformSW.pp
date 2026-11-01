//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\commonStub.ppp
//PPL Source File Name : \\CrossPlatformSW\\common\\src\\commonStub.c
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
 NVM_STATUS_SUCCESS=0x10000 , // force to be 4 Bytes wide	 
 NVM_STATUS_READ_EOF ,	 
 NVM_STATUS_FAILURE ,	 
 NVM_STATUS_API_FAIL_GETDRIVERNAME ,	 
 NVM_STATUS_API_FAIL_OPENDRIVER ,	 
 NVM_STATUS_API_FAIL_IOCTL ,	 
 NVM_STATUS_NON_TRUSTED_CLIENT ,	 
 NVM_STATUS_NO_RESOURCES ,	 
 NVM_STATUS_FAIL_READ_CLIENT_DATA , // client registry data could not be found	 
 NVM_STATUS_TB_SIZE_MISMATCH_ERR , // size field of translation table does not match nimber of records in table	 
 NVM_STATUS_TB_ENTRY_ERR , // translation table entry error	 
 NVM_STATUS_DP_ENTRY_ERR , // default path entry error	 
 NVM_STATUS_UNSUPPORTED_CLIENT_POLICY , // for example : no TTB and only read-only path exists. against system definition	 
 NVM_STATUS_OPEN_FAILED_MAPPING , // try to open a file , but mapping to phy path failed.	 
 NVM_STATUS_OPEN_FILE_NOT_FOUND , //	 
 NVM_STSTUS_CLIENT_NOT_FOUND ,	 
 NVM_STATUS_INVALID_FILE_HANDLE ,	 
 NVM_STATUS_CLOSE_FILE_FAILED ,	 
 NVM_STATUS_SEEK_FAILED ,	 
 NVM_STATUS_READ_FAILED ,	 
 NVM_STATUS_WRITE_FAILED ,	 
 NVM_STATUS_WRITE_FAILED_READ_ONLY ,	 
 NVM_STATUS_FLUSH_FAILED ,	 
 // NVM_STATUS_GET_FILE_SIZE_FAILED ,	 
 NVM_STATUS_FILE_FIND_FIRST_FAILED ,	 
 NVM_STATUS_FILE_FIND_NEXT_FAILED ,	 
 //// File System Error //////	 
 /// Those are mapped to file errors in winerror.h	 
 NVM_STATUS_FS_ERROR ,	 
 NVM_STATUS_FS_INVALID_FUNCTION , // ERROR_INVALID_FUNCTION	 
 NVM_STATUS_FS_FILE_NOT_FOUND , // ERROR_FILE_NOT_FOUND	 
 NVM_STATUS_FS_PATH_NOT_FOUND , // ERROR_PATH_NOT_FOUND	 
 NVM_STATUS_FS_TOO_MANY_OPEN_FILES , // ERROR_TOO_MANY_OPEN_FILES	 
 NVM_STATUS_FS_ACCESS_DENIED , // ERROR_ACCESS_DENIED	 
 NVM_STATUS_FS_HANDLE , // ERROR_INVALID_HANDLE	 
 NVM_RTC_READING_ERROR ,	 
 NVM_STATUS_UNKNOWN ,	 
 NVM_STATUS_ERROR_COUNT	 
	 
 } NVM_STATUS_T;

typedef UINT32 NVM_OP_CODE ;
//ICAT EXPORTED STRUCTURE 
 typedef struct 
 {	 
 CHAR file_name [ ( ( 6 ) + 60 ) +1 ] ;	 
 INT32 time ;	 
 INT32 date ;	 
 INT32 size ;	 
 UINT32 data_id ; /* FDI identifier for file data */	 
 INT32 dir_id ; /* use for winCE handler and FDI directory handler*/	 
 INT32 plr_date ; /* use by FDI */	 
 } NVM_FILE_INFO;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 NVM_OP_CODE op_code ;	 
 NVM_FILE_INFO fileParms ;	 
 NVM_STATUS_T error_code ; // error code of the requested operation	 
 } NVM_FILE_FIND_FIRST_RESPONSE_STRUCT;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 NVM_OP_CODE op_code ;	 
 NVM_FILE_INFO fileParms ;	 
 NVM_STATUS_T error_code ; // error code of the requested operation	 
 } NVM_FILE_FIND_NEXT_RESPONSE_STRUCT;

//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 NVM_OP_CODE op_code ;	 
 NVM_STATUS_T error_code ; // error code of the requested operation	 
 UINT8 second ; // Seconds after minute: 0 - 59	 
 UINT8 minute ; // Minutes after hour: 0 - 59	 
 UINT8 hour ; // Hours after midnight: 0 - 23	 
 UINT8 day ; // Day of month: 1 - 31	 
 UINT8 month ; // Month of year: 1 - 12	 
 UINT16 year ; // Calendar year: e.g 2001	 
 } RTC_GET_RESPONSE_STRUCT;

//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\crossPlatformSW.ppp
//PPL Source File Name : \\CrossPlatformSW\\CrossPlatformSW\\src\\crossPlatformSW.c
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
typedef unsigned short FILE_ID ;
typedef WORD IDTYPE ;
typedef DATA_LOOKUP * DATA_LOOKUP_PTR ;
typedef DATA_LOCATION * DATA_LOC_PTR ;
typedef OPEN_PARAM * OPEN_STREAM_PTR ;
typedef COMMAND * COMMAND_PTR ;
typedef UNIT_HEADER * UNIT_HDR_PTR ;
typedef MULTI_INSTANCE * MULTI_INST_PTR ;
typedef BLOCK_INFO * BLK_INFO_PTR ;
typedef COMMAND_CONTROL * CMD_CNTRL_PTR ;
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

