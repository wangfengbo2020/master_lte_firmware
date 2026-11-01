//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\dma.ppp
//PPL Source File Name : X:\\hop\\dma\\src\\dma.c
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
typedef void ( *DMATransferErrorNotifyFn ) ( UINT32 channel , UINT32 callbackCookie ) ;
typedef void ( *DMATransferEndedNotifyFn ) ( UINT32 channel , UINT32 callbackCookie ) ;
typedef void ( *DMATransferStoppedNotifyFn ) ( UINT32 channel , UINT32 callbackCookie ) ;
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
//PPC Version : V2.1.9.30
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\xllp_dma.ppp
//PPL Source File Name : X:\\hop\\dma\\src\\xllp_dma.c
typedef long XLLP_INT32_T , *P_XLLP_INT32_T ;
typedef volatile XLLP_INT32_T XLLP_VINT32_T , *P_XLLP_VINT32_T ;
typedef unsigned long XLLP_UINT32_T , *P_XLLP_UINT32_T ;
typedef volatile XLLP_UINT32_T XLLP_VUINT32_T , *P_XLLP_VUINT32_T ;
typedef const volatile XLLP_UINT32_T XLLP_CVUINT32_T , *P_CVUINT32_T ;
typedef int XLLP_INT_T , *P_XLLP_INT_T ;
typedef volatile XLLP_INT_T XLLP_VINT_T , *P_XLLP_VINT_T ;
typedef unsigned int XLLP_UINT_T , *P_XLLP_UINT_T ;
typedef volatile XLLP_UINT_T XLLP_VUINT_T , *P_XLLP_VUINT_T ;
typedef const volatile XLLP_UINT_T XLLP_CVUINT_T , *P_CVUINT_T ;
typedef short XLLP_INT16_T , *P_XLLP_INT16_T ;
typedef volatile XLLP_INT16_T XLLP_VINT16_T , *P_XLLP_VINT16_T ;
typedef unsigned short XLLP_UINT16_T , *P_XLLP_UINT16_T ;
typedef volatile XLLP_UINT16_T XLLP_VUINT16_T , *P_XLLP_VUINT16_T ;
typedef const volatile XLLP_UINT16_T XLLP_CVUINT16_T , *P_CVUINT16_T ;
typedef char XLLP_INT8_T , *P_XLLP_INT8_T ;
typedef volatile XLLP_INT8_T XLLP_VINT8_T , *P_XLLP_VINT8_T ;
typedef unsigned char XLLP_UINT8_T , *P_XLLP_UINT8_T ;
typedef volatile XLLP_UINT8_T XLLP_VUINT8_T , *P_XLLP_VUINT8_T ;
typedef const volatile XLLP_UINT8_T XLLP_CVUINT8_T , *P_CVUINT8_T ;
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
typedef void ( *DMATransferErrorNotifyFn ) ( UINT32 channel , UINT32 callbackCookie ) ;
typedef void ( *DMATransferEndedNotifyFn ) ( UINT32 channel , UINT32 callbackCookie ) ;
typedef void ( *DMATransferStoppedNotifyFn ) ( UINT32 channel , UINT32 callbackCookie ) ;
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
//PPL Source File Name : X:\tavor\Arbel\obj_PMD2NONE\prepass_results\dma_hw_connectivity.ppp
//PPL Source File Name : X:\\hop\\dma\\src\\dma_hw_connectivity.c
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
