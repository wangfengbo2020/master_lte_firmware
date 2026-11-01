//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\dialer_task.ppp
//PPL Source File Name : X:\\pcac\\dial\\src\\dialer_task.c
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
typedef unsigned long UINT32 ;
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
typedef int AT_RESP_STATUS ;
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
 } TelAtpCtrl;

typedef unsigned int size_t ;
typedef unsigned int clock_t ;
typedef unsigned int time_t ;
typedef void ( *wifi_event_cb_t ) ( char *iccid , char *mac ) ;
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

typedef void ( *nwst_callback_fn ) ( int event ) ;
typedef void ( *SwitchSimDoneCb ) ( UINT8 ) ;
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

typedef UINT8 AtciFacilityType ;
typedef UINT8 AtciSsCcfcMode ;
typedef UINT8 AtciFacilityLogicGroup ;
typedef UINT8 AtciMEPMode ;
typedef UINT8 AtciUDPMode ;
typedef UINT8 AtciUDPCat ;
typedef UINT8 AtciUssdState ;
typedef UINT8 AtciDataConnType ;
typedef UINT8 AtciPppState ;
typedef UINT8 AtciCharacterSet ;
typedef UINT8 AtciCallState ;
typedef UINT8 AtciGprsState ;
typedef UINT8 AtciDialNumberType ;
typedef UINT8 AtciSmsFormatMode ;
typedef UINT8 AtciCopsMode ;
typedef UINT8 AtciCopsModeFormat ;
typedef UINT8 AtciCpolAct ;
typedef UINT8 AtciCfunOpType ;
typedef UINT8 AtciChldModeTypes ;
typedef UINT8 AtciRegMode ;
typedef UINT8 AtciAocMode ;
typedef UINT8 AtciCbMode ;
typedef UINT8 AtciNmiProcessingMode ;
typedef UINT8 AtciNmiMode ;
typedef UINT8 AtciNmiBfr ;
typedef UINT8 AtciClirMode ;
typedef UINT16 AtciCmeError ;
typedef UINT8 AtciResultCode ;
typedef UINT8 AtciCsgMode ;
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
 CI_DEV_LTE_RRC_CAUSE_EST_EMERGENCY = 0 , /* The RRC establishment cause is ＆Emergency＊ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_HIGH_PRIO_ACC , /* The RRC establishment cause is ＆High priority access＊ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_MT_ACC , /* The RRC establishment cause is ＆MT access＊ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_MO_SIGNAL , /* The RRC establishment cause is ＆MO signaling＊ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_EST_MO_DATA , /* The RRC establishment cause is ＆MO data＊ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_REEST_RECFG_FAIL , /* The RRC reestablishment cause is ＆Reconfiguration failure＊ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_REEST_HO_FAIL , /* The RRC reestablishment cause is ＆Handover failure＊ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_REEST_OTHER_FAIL , /* The RRC reestablishment cause is ＆Other failure＊ Ref. 3 GPP TS 36.331000 , section 6.200000 .1 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_OTHER_RECFG_FAIL , /* RRC connection reconfiguration failed Ref. 3 GPP TS 36.331000 , section 5.300000 .5.5 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_IRAT_RES , /* EL Inter-RAT cell reselection occurred during RRC connection reestablishment Ref. 3 GPP TS 36.331000 , section 5.300000 .7.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_T311_EXP , /* RRC connection reestablishment failed due to T311 expiry Ref. 3 GPP TS 36.331000 , section 5.300000 .7.6 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_CELL_NOT_SUIT , /* RRC connection reestablishment failed due to T301 expiry or because the cell is no longer suitable Ref. 3 GPP TS 36.331000 , section 5.300000 .7.7 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_REEST_REJ , /* RRC connection reestablishment failed due to reestablishment rejection Ref. 3 GPP TS 36.331000 , section 5.300000 .7.8 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_LOAD_BAL_TAU_REQD , /* The RRC connection was released with cause ＆Load balancing TAU required＊ Ref. 3 GPP TS 36.331000 , section 5.300000 .8.3 */	 
 CI_DEV_LTE_RRC_CAUSE_REL_OTHER , /* The RRC connection was released with cause ＆Other＊ Ref. 3 GPP TS 36.331000 , section 5.300000 .8.3 */	 
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

typedef void ( *networkStatusChangeCb ) ( int , int ) ;
typedef void ( *networkModeChangeCb ) ( int , int ) ;
typedef void ( *simStatusChangedCb ) ( int , int ) ;
typedef void ( *pinStatusChangedCb ) ( int , int ) ;
typedef int ( *MATConfIndCB ) ( TelAtParserID chnlId , const char* response , int size ) ;
