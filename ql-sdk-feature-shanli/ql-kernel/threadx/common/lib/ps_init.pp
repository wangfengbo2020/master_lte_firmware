//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\ps_init.ppp
//PPL Source File Name : \\tavor\\Arbel\\src\\ps_init.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
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
typedef void ( *fpUSBDeviceCableDetectionNotify ) ( USBCable_StatusE ) ;
typedef void ( *UsbWkpCallback ) ( void ) ;
typedef void ( *USBMgrControlIndicationFunc ) ( USBMgr_Status , USBMgr_Error , UINT32 ) ;
typedef void ( *USBMgrTxIndicationFunc ) ( UINT32 , UINT8 , UINT8* , UINT32 ) ;
typedef void ( *USBMgrRxIndicationFunc ) ( UINT8 , UINT8 * , UINT32 ) ;
typedef void ( *USBMgrSetupCommandRspFunc ) ( UINT8* , UINT16 ) ;
typedef void ( *USBMgrSetupCommandIndicationFunc ) ( USBMgr_SetupDataStruct * ) ;
typedef void * USBMGR_IF_HANDLER ;
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
	 
 UINT8 bsic ;	 
	 
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

typedef void ( *pldResetCnf_t ) ( void ) ;
typedef void ( *pldInitCnf_t ) ( void ) ;
typedef void ( *pldGsmCnf_t ) ( UINT8 simId ) ;
typedef void ( *pldGsmTerminateCnf_t ) ( UINT8 simId ) ;
typedef void ( *pldLteCnf_t ) ( UINT8 simId ) ;
typedef void ( *pldWcdmaCnf_t ) ( UINT8 simId ) ;
typedef void ( *pldWcdmaTerminateCnf_t ) ( UINT8 simId ) ;
typedef void ( *pldL1WcdmaCapabilityReportInd_t ) ( l1WcdmaCapabilityReportInd_ts* L1CapabilityReportInd , UINT8 simId ) ;
typedef void ( *plwNoActionInd_t ) ( void ) ;
typedef void ( *plwEdchSharedMemAddrInd_t ) ( edchSharedMemAddrInd_ts* edchSharedMemAddrIndParam ) ;
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
typedef void* * VOID_PTR_PTR ;
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
DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUS9 , DIAG_INFORMATION)  
 diagPrintf ( " COMPOSITE USB status %e { USBConfiguration_ts } " , ps_init_usb_app_mask );

DIAG_FILTER ( BOOT , BOOT_TASK , L1Init_1 , DIAG_INFORMATION)  
 diagPrintf ( " plAMReset is called " );

DIAG_FILTER ( SYSTEM , SYSTEM_BUILD , RELEASE_FULL_NAME , DIAG_INFORMATION)  
 diagPrintf ( " Release: SYSTEM %s " , GetSystemReleaseName ( ) );

DIAG_FILTER ( SYSTEM , SYSTEM_BUILD , RELEASE_DATE , DIAG_INFORMATION)  
 diagPrintf ( " Release creation date: %s " , " NO_DATE_NO_TIME " );

DIAG_FILTER ( SYSTEM , SYSTEM_BUILD , RELEASE_COMMENTS , DIAG_INFORMATION)  
 diagPrintf ( " Release comments: SYSTEM %s " , " system build " );

DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUS1 , DIAG_INFORMATION)  
 diagPrintf ( " PS INIT AUTO status %e { systemfeatureenable_ts } " , systemcNvmParams.featuresParams.PS_INIT_AUTO );

DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUS2 , DIAG_INFORMATION)  
 diagPrintf ( " GSM DRX SLEEP status %e { systemfeatureenable_ts } " , systemcNvmParams.featuresParams.GSM_DRX_SLEEP );

DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUS3 , DIAG_INFORMATION)  
 diagPrintf ( " WBCDMA DRX SLEEP status %e { systemfeatureenable_ts } " , systemcNvmParams.featuresParams.WBCDMA_DRX_SLEEP );

DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUS4 , DIAG_INFORMATION)  
 diagPrintf ( " GSM status %e { systemfeatureenable_ts } " , systemcNvmParams.featuresParams.IN_GSM );

DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUS5 , DIAG_INFORMATION)  
 diagPrintf ( " CIRCUIT SWITCHED ONLY status %e { systemfeatureenable_ts } " , systemcNvmParams.featuresParams.CIRCUIT_SWITCHED_ONLY );

DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUS6 , DIAG_INFORMATION)  
 diagPrintf ( " Xscale Power Management status %e { xscalePowerManagement_ts } " , systemcNvmParams.xscalePowerManagement );

DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUS7 , DIAG_INFORMATION)  
 diagPrintf ( " ONLY GSM status %e { systemfeatureenable_ts } " , systemcNvmParams.featuresParams.ONLY_GSM );

DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUS10 , DIAG_INFORMATION)  
 diagPrintf ( " UART force wake mode %e { uartForceAwakeMode_ts } " , systemcNvmParams.uartForceAwakeMode );

DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUS11 , DIAG_INFORMATION)  
 diagPrintf ( " UICC use only T=0 transmission protocol %e { systemfeatureenable_ts } " , systemcNvmParams.featuresParams.UICC_PROTOCOL_T0_ONLY );

DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUS12 , DIAG_INFORMATION)  
 diagPrintf ( " NvmAccessBehavior %e { psNvmAccessBehavior_e } " , systemcNvmParams.developmentSwitch.psNvmAccessBehavior );

DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUS14 , DIAG_INFORMATION)  
 diagStructPrintf ( " SAT / USAT terminal profile %S { TermProfileNvm_ts } " , &termProfileParams , sizeof ( TermProfileNvm_ts ) );

DIAG_FILTER ( SYSTEM , SYSNVM , NVMSTATUSdbg , DIAG_INFORMATION)  
 diagPrintf ( " NO L1 INIT AUTO - developmentSwitch.RESERVED1 BIT1 is set " );

typedef unsigned char Boolean ;
//ICAT EXPORTED FUNCTION - PS , UMTS , setAttachAtPwrOn 
 void setAttachAtPwrOn ( UINT16* attach ) 
 {	 
 abmmGprsAttachAtPowerOn = ( Boolean ) *attach ;	 
 }

//ICAT EXPORTED FUNCTION - PS , UMTS , setTxInitPower 
 void setTxInitPower ( INT8* txInitPower ) 
 {	 
	 
	 
	 
 }

//ICAT EXPORTED FUNCTION - PS , UMTS , setServiceType 
 void setServiceType ( UINT16* svcType ) 
 {	 
 ICATsetServiceType ( ( int ) *svcType ) ;	 
 }

//ICAT EXPORTED FUNCTION - PS , UMTS , setNetworkMode 
 void setNetworkMode ( UINT16* nmode ) 
 {	 
 // sets the network mode to UMTS or GSM	 
 ICATsetNetworkMode ( ( int ) *nmode ) ;	 
 }

//ICAT EXPORTED FUNCTION - PS , UMTS , setUserMode 
 void setUserMode ( UINT16* nmode ) 
 {	 
 // sets the user mode	 
 ICATsetUserMode ( ( int ) *nmode ) ;	 
 }

DIAG_FILTER ( PS , UMTS , CIPHERING_PARAMS_CS , DIAG_INFORMATION)  
 diagStructPrintf ( " New ciphering parameters for CS domain: " , pCk , 16 );

DIAG_FILTER ( PS , UMTS , CIPHERING_PARAMS_PS , DIAG_INFORMATION)  
 diagStructPrintf ( " New ciphering parameters for PS domain: " , pCk , 16 );

//ICAT EXPORTED FUNCTION - PS , UMTS , ICATtestCipheringInfo 
 void ICATtestCipheringInfo ( UINT8* p ) 
 {	 
 ICATexportCipheringInfo ( ( p [ 0 ] !=0 ) , &p [ 4 ] ) ;	 
 }

//ICAT EXPORTED FUNCTION - PS , FDI , PSInformationDelete 
 void PSInformationDelete ( void ) 
 {	 
	 
 FILE_INFO info ;	 
	 
 while ( FDI_findfirst ( " TTPCom_NRAM2_*.* " , &info ) == 0 )	 
 {		 
 FDI_remove ( info.file_name ) ;		 
DIAG_FILTER ( PS , FDI , DATA_ERASE , DIAG_INFORMATION)  
 diagPrintf ( " Erasing file %s " , info.file_name );

		 
		 
 }	 
	 
	 
	 
	 
 }

typedef void pFuncVoidVoid ( void ) ;
//ICAT EXPORTED FUNCTION - PS , PS_INIT , PS_INIT 
 void psInit_PS_INIT_ACAT ( void ) 
 {	 
 if ( systemcNvmParams.featuresParams.PS_INIT_AUTO )	 
 return ; // Already done	 
	 
DIAG_FILTER ( PS , PS_INIT , Started , DIAG_INFORMATION)  
 diagPrintf ( " PS_INIT manual Started " );

	 
	 
 psInit_PS_INIT ( ) ;	 
	 
DIAG_FILTER ( PS , PS_INIT , Finished , DIAG_INFORMATION)  
 diagPrintf ( " PS_INIT manual Finished " );

	 
 }

