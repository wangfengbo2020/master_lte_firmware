//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\poc.ppp
//PPL Source File Name : poc.c
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *pfn_sl_notify_adapter ) ( void* user , void* notify ) ;
typedef void ( *tts_netnifo_notify_cb ) ( void* arg ) ;
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
typedef int QlOSStatus ;
typedef void * ql_task_t ;
typedef void * ql_sem_t ;
typedef void * ql_mutex_t ;
typedef void * ql_queue_t ;
typedef void * ql_timer_t ;
typedef void * ql_flag_t ;
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
typedef void ( *uart_callback ) ( UART_Port port , void *para ) ;
typedef void ( *uart_callback_ex ) ( UART_Port port , int len , void *private ) ;
typedef void ( *ql_atcmd_asyc_cb ) ( QL_AT_RESP_STATUS_E errno , char * buffer , unsigned int len ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\addressing.ppp
//PPL Source File Name : src\\addressing.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *pfn_addressing_result_callback ) ( addressing_status status , int err , int login_model , void* user ) ;
typedef void ( *pfn_connection_notify ) ( connection_t* connection , CONNECTION_STATUS status , void* user ) ;
typedef void ( *pfn_connection_on_recv_msg_timeout ) ( connection_t* connection , const char* message_name , void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void* hal_mutex_t ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Login_Closure )
 ( const Ptt__Rr__Login *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LoginAck_Closure )
 ( const Ptt__Rr__LoginAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Logout_Closure )
 ( const Ptt__Rr__Logout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LogoutAck_Closure )
 ( const Ptt__Rr__LogoutAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroup_Closure )
 ( const Ptt__Rr__QueryGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroupAck_Closure )
 ( const Ptt__Rr__QueryGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroup_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroupAck_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembers_Closure )
 ( const Ptt__Rr__QueryMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck_Closure )
 ( const Ptt__Rr__QueryMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck2_Closure )
 ( const Ptt__Rr__QueryMembersAck2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContacts_Closure )
 ( const Ptt__Rr__QueryContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContactsAck_Closure )
 ( const Ptt__Rr__QueryContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsers_Closure )
 ( const Ptt__Rr__QueryUsers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsersAck_Closure )
 ( const Ptt__Rr__QueryUsersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartments_Closure )
 ( const Ptt__Rr__QueryDepartments *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentsAck_Closure )
 ( const Ptt__Rr__QueryDepartmentsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembers_Closure )
 ( const Ptt__Rr__QueryDepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembersAck_Closure )
 ( const Ptt__Rr__QueryDepartmentMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTree_Closure )
 ( const Ptt__Rr__QueryDepartmentTree *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTreeAck_Closure )
 ( const Ptt__Rr__QueryDepartmentTreeAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroup_Closure )
 ( const Ptt__Rr__JoinGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroupAck_Closure )
 ( const Ptt__Rr__JoinGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroup_Closure )
 ( const Ptt__Rr__WatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupAck_Closure )
 ( const Ptt__Rr__WatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ByeGroup_Closure )
 ( const Ptt__Rr__ByeGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__IgnoreTalk_Closure )
 ( const Ptt__Rr__IgnoreTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ContinueTalk_Closure )
 ( const Ptt__Rr__ContinueTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dnd_Closure )
 ( const Ptt__Rr__Dnd *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroup_Closure )
 ( const Ptt__Rr__LeaveGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroupAck_Closure )
 ( const Ptt__Rr__LeaveGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMic_Closure )
 ( const Ptt__Rr__RequestMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMicAck_Closure )
 ( const Ptt__Rr__RequestMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMic_Closure )
 ( const Ptt__Rr__ReleaseMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMicAck_Closure )
 ( const Ptt__Rr__ReleaseMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Call_Closure )
 ( const Ptt__Rr__Call *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CallAck_Closure )
 ( const Ptt__Rr__CallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCall_Closure )
 ( const Ptt__Rr__SingleCall *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCallAck_Closure )
 ( const Ptt__Rr__SingleCallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDial_Closure )
 ( const Ptt__Rr__QuickDial *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDialAck_Closure )
 ( const Ptt__Rr__QuickDialAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeName_Closure )
 ( const Ptt__Rr__ChangeName *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeNameAck_Closure )
 ( const Ptt__Rr__ChangeNameAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePassword_Closure )
 ( const Ptt__Rr__ChangePassword *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePasswordAck_Closure )
 ( const Ptt__Rr__ChangePasswordAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContacts_Closure )
 ( const Ptt__Rr__MakeContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsAck_Closure )
 ( const Ptt__Rr__MakeContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponse_Closure )
 ( const Ptt__Rr__MakeContactsResponse *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponseAck_Closure )
 ( const Ptt__Rr__MakeContactsResponseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContacts_Closure )
 ( const Ptt__Rr__RemoveContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContactsAck_Closure )
 ( const Ptt__Rr__RemoveContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocation_Closure )
 ( const Ptt__Rr__ReportLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocationAck_Closure )
 ( const Ptt__Rr__ReportLocationAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroup_Closure )
 ( const Ptt__Rr__CreateGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroupAck_Closure )
 ( const Ptt__Rr__CreateGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroup_Closure )
 ( const Ptt__Rr__DeleteGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroupAck_Closure )
 ( const Ptt__Rr__DeleteGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroup_Closure )
 ( const Ptt__Rr__ModifyGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroupAck_Closure )
 ( const Ptt__Rr__ModifyGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembership_Closure )
 ( const Ptt__Rr__EmpowerMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembershipAck_Closure )
 ( const Ptt__Rr__EmpowerMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembership_Closure )
 ( const Ptt__Rr__DepriveMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembershipAck_Closure )
 ( const Ptt__Rr__DepriveMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dispatch_Closure )
 ( const Ptt__Rr__Dispatch *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DispatchAck_Closure )
 ( const Ptt__Rr__DispatchAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUser_Closure )
 ( const Ptt__Rr__ConfigureUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUserAck_Closure )
 ( const Ptt__Rr__ConfigureUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMic_Closure )
 ( const Ptt__Rr__TakeMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMicAck_Closure )
 ( const Ptt__Rr__TakeMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabase_Closure )
 ( const Ptt__Rr__SynchDatabase *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabaseAck_Closure )
 ( const Ptt__Rr__SynchDatabaseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheet_Closure )
 ( const Ptt__Rr__PostWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheetAck_Closure )
 ( const Ptt__Rr__PostWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheet_Closure )
 ( const Ptt__Rr__ResponseWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheetAck_Closure )
 ( const Ptt__Rr__ResponseWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServer_Closure )
 ( const Ptt__Rr__QueryServer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServerAck_Closure )
 ( const Ptt__Rr__QueryServerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigure_Closure )
 ( const Ptt__Rr__RequestConfigure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigureAck_Closure )
 ( const Ptt__Rr__RequestConfigureAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivate_Closure )
 ( const Ptt__Rr__RequestActivate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivateAck_Closure )
 ( const Ptt__Rr__RequestActivateAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcast_Closure )
 ( const Ptt__Rr__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcastAck_Closure )
 ( const Ptt__Rr__CustomBroadcastAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRoles_Closure )
 ( const Ptt__Rr__ChangeUserRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRolesAck_Closure )
 ( const Ptt__Rr__ChangeUserRolesAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroup_Closure )
 ( const Ptt__Rr__GetWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroupAck_Closure )
 ( const Ptt__Rr__GetWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroup_Closure )
 ( const Ptt__Rr__AddWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroupAck_Closure )
 ( const Ptt__Rr__AddWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroup_Closure )
 ( const Ptt__Rr__RemoveWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroupAck_Closure )
 ( const Ptt__Rr__RemoveWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupEx_Closure )
 ( const Ptt__Rr__WatchGroupEx *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupExAck_Closure )
 ( const Ptt__Rr__WatchGroupExAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Invite_Closure )
 ( const Ptt__Rr__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__InviteAck_Closure )
 ( const Ptt__Rr__InviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInvite_Closure )
 ( const Ptt__Rr__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInviteAck_Closure )
 ( const Ptt__Rr__ResponseInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInvite_Closure )
 ( const Ptt__Rr__CancelInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInviteAck_Closure )
 ( const Ptt__Rr__CancelInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncrypt_Closure )
 ( const Ptt__Rr__SetEncrypt *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncryptAck_Closure )
 ( const Ptt__Rr__SetEncryptAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUser_Closure )
 ( const Ptt__Rr__ListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUserAck_Closure )
 ( const Ptt__Rr__ListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUser_Closure )
 ( const Ptt__Rr__UnListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUserAck_Closure )
 ( const Ptt__Rr__UnListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListener_Closure )
 ( const Ptt__Rr__QueryListener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListenerAck_Closure )
 ( const Ptt__Rr__QueryListenerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Deliver_Closure )
 ( const Ptt__Rr__Deliver *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeliverAck_Closure )
 ( const Ptt__Rr__DeliverAck *message ,
 void *closure_data ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\algorithm.ppp
//PPL Source File Name : src\\algorithm.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\audiopacket.ppp
//PPL Source File Name : src\\audiopacket.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\broadcast.ppp
//PPL Source File Name : src\\broadcast.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *pfn_focus_notify ) ( focus_manager_t* fm , void* requestor , boolean focus ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *pfn_connection_notify ) ( connection_t* connection , CONNECTION_STATUS status , void* user ) ;
typedef void ( *pfn_connection_on_recv_msg_timeout ) ( connection_t* connection , const char* message_name , void* user ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\cache.ppp
//PPL Source File Name : src\\cache.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *pfn_registerprocess_cb ) ( const ProtobufCMessage* message , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef void ( *pfn_connection_notify ) ( connection_t* connection , CONNECTION_STATUS status , void* user ) ;
typedef void ( *pfn_connection_on_recv_msg_timeout ) ( connection_t* connection , const char* message_name , void* user ) ;
typedef void* hal_mutex_t ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Login_Closure )
 ( const Ptt__Rr__Login *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LoginAck_Closure )
 ( const Ptt__Rr__LoginAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Logout_Closure )
 ( const Ptt__Rr__Logout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LogoutAck_Closure )
 ( const Ptt__Rr__LogoutAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroup_Closure )
 ( const Ptt__Rr__QueryGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroupAck_Closure )
 ( const Ptt__Rr__QueryGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroup_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroupAck_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembers_Closure )
 ( const Ptt__Rr__QueryMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck_Closure )
 ( const Ptt__Rr__QueryMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck2_Closure )
 ( const Ptt__Rr__QueryMembersAck2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContacts_Closure )
 ( const Ptt__Rr__QueryContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContactsAck_Closure )
 ( const Ptt__Rr__QueryContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsers_Closure )
 ( const Ptt__Rr__QueryUsers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsersAck_Closure )
 ( const Ptt__Rr__QueryUsersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartments_Closure )
 ( const Ptt__Rr__QueryDepartments *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentsAck_Closure )
 ( const Ptt__Rr__QueryDepartmentsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembers_Closure )
 ( const Ptt__Rr__QueryDepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembersAck_Closure )
 ( const Ptt__Rr__QueryDepartmentMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTree_Closure )
 ( const Ptt__Rr__QueryDepartmentTree *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTreeAck_Closure )
 ( const Ptt__Rr__QueryDepartmentTreeAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroup_Closure )
 ( const Ptt__Rr__JoinGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroupAck_Closure )
 ( const Ptt__Rr__JoinGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroup_Closure )
 ( const Ptt__Rr__WatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupAck_Closure )
 ( const Ptt__Rr__WatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ByeGroup_Closure )
 ( const Ptt__Rr__ByeGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__IgnoreTalk_Closure )
 ( const Ptt__Rr__IgnoreTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ContinueTalk_Closure )
 ( const Ptt__Rr__ContinueTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dnd_Closure )
 ( const Ptt__Rr__Dnd *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroup_Closure )
 ( const Ptt__Rr__LeaveGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroupAck_Closure )
 ( const Ptt__Rr__LeaveGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMic_Closure )
 ( const Ptt__Rr__RequestMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMicAck_Closure )
 ( const Ptt__Rr__RequestMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMic_Closure )
 ( const Ptt__Rr__ReleaseMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMicAck_Closure )
 ( const Ptt__Rr__ReleaseMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Call_Closure )
 ( const Ptt__Rr__Call *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CallAck_Closure )
 ( const Ptt__Rr__CallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCall_Closure )
 ( const Ptt__Rr__SingleCall *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCallAck_Closure )
 ( const Ptt__Rr__SingleCallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDial_Closure )
 ( const Ptt__Rr__QuickDial *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDialAck_Closure )
 ( const Ptt__Rr__QuickDialAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeName_Closure )
 ( const Ptt__Rr__ChangeName *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeNameAck_Closure )
 ( const Ptt__Rr__ChangeNameAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePassword_Closure )
 ( const Ptt__Rr__ChangePassword *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePasswordAck_Closure )
 ( const Ptt__Rr__ChangePasswordAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContacts_Closure )
 ( const Ptt__Rr__MakeContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsAck_Closure )
 ( const Ptt__Rr__MakeContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponse_Closure )
 ( const Ptt__Rr__MakeContactsResponse *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponseAck_Closure )
 ( const Ptt__Rr__MakeContactsResponseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContacts_Closure )
 ( const Ptt__Rr__RemoveContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContactsAck_Closure )
 ( const Ptt__Rr__RemoveContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocation_Closure )
 ( const Ptt__Rr__ReportLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocationAck_Closure )
 ( const Ptt__Rr__ReportLocationAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroup_Closure )
 ( const Ptt__Rr__CreateGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroupAck_Closure )
 ( const Ptt__Rr__CreateGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroup_Closure )
 ( const Ptt__Rr__DeleteGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroupAck_Closure )
 ( const Ptt__Rr__DeleteGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroup_Closure )
 ( const Ptt__Rr__ModifyGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroupAck_Closure )
 ( const Ptt__Rr__ModifyGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembership_Closure )
 ( const Ptt__Rr__EmpowerMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembershipAck_Closure )
 ( const Ptt__Rr__EmpowerMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembership_Closure )
 ( const Ptt__Rr__DepriveMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembershipAck_Closure )
 ( const Ptt__Rr__DepriveMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dispatch_Closure )
 ( const Ptt__Rr__Dispatch *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DispatchAck_Closure )
 ( const Ptt__Rr__DispatchAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUser_Closure )
 ( const Ptt__Rr__ConfigureUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUserAck_Closure )
 ( const Ptt__Rr__ConfigureUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMic_Closure )
 ( const Ptt__Rr__TakeMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMicAck_Closure )
 ( const Ptt__Rr__TakeMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabase_Closure )
 ( const Ptt__Rr__SynchDatabase *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabaseAck_Closure )
 ( const Ptt__Rr__SynchDatabaseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheet_Closure )
 ( const Ptt__Rr__PostWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheetAck_Closure )
 ( const Ptt__Rr__PostWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheet_Closure )
 ( const Ptt__Rr__ResponseWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheetAck_Closure )
 ( const Ptt__Rr__ResponseWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServer_Closure )
 ( const Ptt__Rr__QueryServer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServerAck_Closure )
 ( const Ptt__Rr__QueryServerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigure_Closure )
 ( const Ptt__Rr__RequestConfigure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigureAck_Closure )
 ( const Ptt__Rr__RequestConfigureAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivate_Closure )
 ( const Ptt__Rr__RequestActivate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivateAck_Closure )
 ( const Ptt__Rr__RequestActivateAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcast_Closure )
 ( const Ptt__Rr__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcastAck_Closure )
 ( const Ptt__Rr__CustomBroadcastAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRoles_Closure )
 ( const Ptt__Rr__ChangeUserRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRolesAck_Closure )
 ( const Ptt__Rr__ChangeUserRolesAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroup_Closure )
 ( const Ptt__Rr__GetWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroupAck_Closure )
 ( const Ptt__Rr__GetWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroup_Closure )
 ( const Ptt__Rr__AddWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroupAck_Closure )
 ( const Ptt__Rr__AddWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroup_Closure )
 ( const Ptt__Rr__RemoveWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroupAck_Closure )
 ( const Ptt__Rr__RemoveWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupEx_Closure )
 ( const Ptt__Rr__WatchGroupEx *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupExAck_Closure )
 ( const Ptt__Rr__WatchGroupExAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Invite_Closure )
 ( const Ptt__Rr__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__InviteAck_Closure )
 ( const Ptt__Rr__InviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInvite_Closure )
 ( const Ptt__Rr__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInviteAck_Closure )
 ( const Ptt__Rr__ResponseInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInvite_Closure )
 ( const Ptt__Rr__CancelInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInviteAck_Closure )
 ( const Ptt__Rr__CancelInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncrypt_Closure )
 ( const Ptt__Rr__SetEncrypt *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncryptAck_Closure )
 ( const Ptt__Rr__SetEncryptAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUser_Closure )
 ( const Ptt__Rr__ListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUserAck_Closure )
 ( const Ptt__Rr__ListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUser_Closure )
 ( const Ptt__Rr__UnListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUserAck_Closure )
 ( const Ptt__Rr__UnListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListener_Closure )
 ( const Ptt__Rr__QueryListener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListenerAck_Closure )
 ( const Ptt__Rr__QueryListenerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Deliver_Closure )
 ( const Ptt__Rr__Deliver *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeliverAck_Closure )
 ( const Ptt__Rr__DeliverAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Reconfigured_Closure )
 ( const Ptt__Push__Reconfigured *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__UsersChanged_Closure )
 ( const Ptt__Push__UsersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__GroupListChanged_Closure )
 ( const Ptt__Push__GroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__WatchGroupListChanged_Closure )
 ( const Ptt__Push__WatchGroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged__MemberChanged_Closure )
 ( const Ptt__Push__MembersChanged__MemberChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged_Closure )
 ( const Ptt__Push__MembersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked__Request_Closure )
 ( const Ptt__Push__ContactshipAsked__Request *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked_Closure )
 ( const Ptt__Push__ContactshipAsked *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactsChanged_Closure )
 ( const Ptt__Push__ContactsChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberGetMic_Closure )
 ( const Ptt__Push__MemberGetMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberLostMic_Closure )
 ( const Ptt__Push__MemberLostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__LostMic_Closure )
 ( const Ptt__Push__LostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CurrentGroup_Closure )
 ( const Ptt__Push__CurrentGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Kickout_Closure )
 ( const Ptt__Push__Kickout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__NewWorksheet_Closure )
 ( const Ptt__Push__NewWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CustomBroadcast_Closure )
 ( const Ptt__Push__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ChangeRoles_Closure )
 ( const Ptt__Push__ChangeRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Invite_Closure )
 ( const Ptt__Push__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ResponseInvite_Closure )
 ( const Ptt__Push__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__TxtBroadcast_Closure )
 ( const Ptt__Serv__TxtBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__MobileStandard_Closure )
 ( const Ptt__Serv__MobileStandard *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__DispatchReconnection_Closure )
 ( const Ptt__Serv__DispatchReconnection *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__Configuration_Closure )
 ( const Ptt__Serv__Configuration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__MultimediaMessage_Closure )
 ( const Ptt__Serv__MultimediaMessage *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__ExternalServMsg_Closure )
 ( const Ptt__Serv__ExternalServMsg *message ,
 void *closure_data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\cJSON.ppp
//PPL Source File Name : src\\cJSON.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef float float_t ;
typedef double double_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\collect.pb-c.ppp
//PPL Source File Name : src\\collect.pb-c.c
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__User_Closure )
 ( const Ptt__Collect__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Server_Closure )
 ( const Ptt__Collect__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Terminal_Closure )
 ( const Ptt__Collect__Terminal *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__NetWork_Closure )
 ( const Ptt__Collect__NetWork *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__NetDelay_Closure )
 ( const Ptt__Collect__NetDelay *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__GpsCnoInfo_Closure )
 ( const Ptt__Collect__GpsCnoInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__BaseInfo_Closure )
 ( const Ptt__Collect__BaseInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Disconnect_Closure )
 ( const Ptt__Collect__Disconnect *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Reconnect_Closure )
 ( const Ptt__Collect__Reconnect *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__NetStat_Closure )
 ( const Ptt__Collect__NetStat *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Speaker_Closure )
 ( const Ptt__Collect__Speaker *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Listener_Closure )
 ( const Ptt__Collect__Listener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__SessionStat_Closure )
 ( const Ptt__Collect__SessionStat *message ,
 void *closure_data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\compress.ppp
//PPL Source File Name : src\\compress.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef float float_t ;
typedef double double_t ;
typedef unsigned int size_t ;
typedef unsigned long int WeightType ;
typedef unsigned char MyType ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\connection.ppp
//PPL Source File Name : src\\connection.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *pfn_addressing_result_callback ) ( addressing_status status , int err , int login_model , void* user ) ;
typedef void ( *pfn_connection_notify ) ( connection_t* connection , CONNECTION_STATUS status , void* user ) ;
typedef void ( *pfn_connection_on_recv_msg_timeout ) ( connection_t* connection , const char* message_name , void* user ) ;
typedef void ( *pfn_registerprocess_cb ) ( const ProtobufCMessage* message , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Login_Closure )
 ( const Ptt__Rr__Login *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LoginAck_Closure )
 ( const Ptt__Rr__LoginAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Logout_Closure )
 ( const Ptt__Rr__Logout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LogoutAck_Closure )
 ( const Ptt__Rr__LogoutAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroup_Closure )
 ( const Ptt__Rr__QueryGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroupAck_Closure )
 ( const Ptt__Rr__QueryGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroup_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroupAck_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembers_Closure )
 ( const Ptt__Rr__QueryMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck_Closure )
 ( const Ptt__Rr__QueryMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck2_Closure )
 ( const Ptt__Rr__QueryMembersAck2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContacts_Closure )
 ( const Ptt__Rr__QueryContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContactsAck_Closure )
 ( const Ptt__Rr__QueryContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsers_Closure )
 ( const Ptt__Rr__QueryUsers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsersAck_Closure )
 ( const Ptt__Rr__QueryUsersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartments_Closure )
 ( const Ptt__Rr__QueryDepartments *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentsAck_Closure )
 ( const Ptt__Rr__QueryDepartmentsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembers_Closure )
 ( const Ptt__Rr__QueryDepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembersAck_Closure )
 ( const Ptt__Rr__QueryDepartmentMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTree_Closure )
 ( const Ptt__Rr__QueryDepartmentTree *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTreeAck_Closure )
 ( const Ptt__Rr__QueryDepartmentTreeAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroup_Closure )
 ( const Ptt__Rr__JoinGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroupAck_Closure )
 ( const Ptt__Rr__JoinGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroup_Closure )
 ( const Ptt__Rr__WatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupAck_Closure )
 ( const Ptt__Rr__WatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ByeGroup_Closure )
 ( const Ptt__Rr__ByeGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__IgnoreTalk_Closure )
 ( const Ptt__Rr__IgnoreTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ContinueTalk_Closure )
 ( const Ptt__Rr__ContinueTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dnd_Closure )
 ( const Ptt__Rr__Dnd *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroup_Closure )
 ( const Ptt__Rr__LeaveGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroupAck_Closure )
 ( const Ptt__Rr__LeaveGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMic_Closure )
 ( const Ptt__Rr__RequestMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMicAck_Closure )
 ( const Ptt__Rr__RequestMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMic_Closure )
 ( const Ptt__Rr__ReleaseMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMicAck_Closure )
 ( const Ptt__Rr__ReleaseMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Call_Closure )
 ( const Ptt__Rr__Call *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CallAck_Closure )
 ( const Ptt__Rr__CallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCall_Closure )
 ( const Ptt__Rr__SingleCall *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCallAck_Closure )
 ( const Ptt__Rr__SingleCallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDial_Closure )
 ( const Ptt__Rr__QuickDial *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDialAck_Closure )
 ( const Ptt__Rr__QuickDialAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeName_Closure )
 ( const Ptt__Rr__ChangeName *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeNameAck_Closure )
 ( const Ptt__Rr__ChangeNameAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePassword_Closure )
 ( const Ptt__Rr__ChangePassword *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePasswordAck_Closure )
 ( const Ptt__Rr__ChangePasswordAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContacts_Closure )
 ( const Ptt__Rr__MakeContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsAck_Closure )
 ( const Ptt__Rr__MakeContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponse_Closure )
 ( const Ptt__Rr__MakeContactsResponse *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponseAck_Closure )
 ( const Ptt__Rr__MakeContactsResponseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContacts_Closure )
 ( const Ptt__Rr__RemoveContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContactsAck_Closure )
 ( const Ptt__Rr__RemoveContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocation_Closure )
 ( const Ptt__Rr__ReportLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocationAck_Closure )
 ( const Ptt__Rr__ReportLocationAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroup_Closure )
 ( const Ptt__Rr__CreateGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroupAck_Closure )
 ( const Ptt__Rr__CreateGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroup_Closure )
 ( const Ptt__Rr__DeleteGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroupAck_Closure )
 ( const Ptt__Rr__DeleteGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroup_Closure )
 ( const Ptt__Rr__ModifyGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroupAck_Closure )
 ( const Ptt__Rr__ModifyGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembership_Closure )
 ( const Ptt__Rr__EmpowerMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembershipAck_Closure )
 ( const Ptt__Rr__EmpowerMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembership_Closure )
 ( const Ptt__Rr__DepriveMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembershipAck_Closure )
 ( const Ptt__Rr__DepriveMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dispatch_Closure )
 ( const Ptt__Rr__Dispatch *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DispatchAck_Closure )
 ( const Ptt__Rr__DispatchAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUser_Closure )
 ( const Ptt__Rr__ConfigureUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUserAck_Closure )
 ( const Ptt__Rr__ConfigureUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMic_Closure )
 ( const Ptt__Rr__TakeMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMicAck_Closure )
 ( const Ptt__Rr__TakeMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabase_Closure )
 ( const Ptt__Rr__SynchDatabase *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabaseAck_Closure )
 ( const Ptt__Rr__SynchDatabaseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheet_Closure )
 ( const Ptt__Rr__PostWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheetAck_Closure )
 ( const Ptt__Rr__PostWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheet_Closure )
 ( const Ptt__Rr__ResponseWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheetAck_Closure )
 ( const Ptt__Rr__ResponseWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServer_Closure )
 ( const Ptt__Rr__QueryServer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServerAck_Closure )
 ( const Ptt__Rr__QueryServerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigure_Closure )
 ( const Ptt__Rr__RequestConfigure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigureAck_Closure )
 ( const Ptt__Rr__RequestConfigureAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivate_Closure )
 ( const Ptt__Rr__RequestActivate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivateAck_Closure )
 ( const Ptt__Rr__RequestActivateAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcast_Closure )
 ( const Ptt__Rr__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcastAck_Closure )
 ( const Ptt__Rr__CustomBroadcastAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRoles_Closure )
 ( const Ptt__Rr__ChangeUserRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRolesAck_Closure )
 ( const Ptt__Rr__ChangeUserRolesAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroup_Closure )
 ( const Ptt__Rr__GetWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroupAck_Closure )
 ( const Ptt__Rr__GetWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroup_Closure )
 ( const Ptt__Rr__AddWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroupAck_Closure )
 ( const Ptt__Rr__AddWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroup_Closure )
 ( const Ptt__Rr__RemoveWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroupAck_Closure )
 ( const Ptt__Rr__RemoveWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupEx_Closure )
 ( const Ptt__Rr__WatchGroupEx *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupExAck_Closure )
 ( const Ptt__Rr__WatchGroupExAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Invite_Closure )
 ( const Ptt__Rr__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__InviteAck_Closure )
 ( const Ptt__Rr__InviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInvite_Closure )
 ( const Ptt__Rr__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInviteAck_Closure )
 ( const Ptt__Rr__ResponseInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInvite_Closure )
 ( const Ptt__Rr__CancelInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInviteAck_Closure )
 ( const Ptt__Rr__CancelInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncrypt_Closure )
 ( const Ptt__Rr__SetEncrypt *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncryptAck_Closure )
 ( const Ptt__Rr__SetEncryptAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUser_Closure )
 ( const Ptt__Rr__ListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUserAck_Closure )
 ( const Ptt__Rr__ListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUser_Closure )
 ( const Ptt__Rr__UnListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUserAck_Closure )
 ( const Ptt__Rr__UnListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListener_Closure )
 ( const Ptt__Rr__QueryListener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListenerAck_Closure )
 ( const Ptt__Rr__QueryListenerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Deliver_Closure )
 ( const Ptt__Rr__Deliver *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeliverAck_Closure )
 ( const Ptt__Rr__DeliverAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Net__HeartBeat_Closure )
 ( const Ptt__Net__HeartBeat *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Net__Ping_Closure )
 ( const Ptt__Net__Ping *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Net__Pong_Closure )
 ( const Ptt__Net__Pong *message ,
 void *closure_data ) ;
typedef void ( *Terminal__Status__TerminalStatusDetail_Closure )
 ( const Terminal__Status__TerminalStatusDetail *message ,
 void *closure_data ) ;
typedef void ( *Terminal__Status__ReqPrivilegeList_Closure )
 ( const Terminal__Status__ReqPrivilegeList *message ,
 void *closure_data ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\context.ppp
//PPL Source File Name : src\\context.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\datatype.ppp
//PPL Source File Name : src\\datatype.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\device.ppp
//PPL Source File Name : src\\device.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\dispatcher.ppp
//PPL Source File Name : src\\dispatcher.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *pfn_registerprocess_cb ) ( const ProtobufCMessage* message , void* user ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\dsp.ppp
//PPL Source File Name : src\\dsp.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( *pfn_dsp_on_play_stop ) ( hal_dsp_t* dsp , void* user ) ;
typedef void ( *pfn_dsp_on_record_stop ) ( hal_dsp_t* dsp , void* user , const hal_frame_t** frames , size_t count ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\echat.ppp
//PPL Source File Name : src\\echat.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\echat_http.ppp
//PPL Source File Name : src\\echat_http.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef int ( *http_data_cb ) ( http_parser* , const char *at , size_t length ) ;
typedef int ( *http_cb ) ( http_parser* ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef int socket_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\echat_imp.ppp
//PPL Source File Name : src\\echat_imp.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef void* hal_mutex_t ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Login_Closure )
 ( const Ptt__Rr__Login *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LoginAck_Closure )
 ( const Ptt__Rr__LoginAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Logout_Closure )
 ( const Ptt__Rr__Logout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LogoutAck_Closure )
 ( const Ptt__Rr__LogoutAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroup_Closure )
 ( const Ptt__Rr__QueryGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroupAck_Closure )
 ( const Ptt__Rr__QueryGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroup_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroupAck_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembers_Closure )
 ( const Ptt__Rr__QueryMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck_Closure )
 ( const Ptt__Rr__QueryMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck2_Closure )
 ( const Ptt__Rr__QueryMembersAck2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContacts_Closure )
 ( const Ptt__Rr__QueryContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContactsAck_Closure )
 ( const Ptt__Rr__QueryContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsers_Closure )
 ( const Ptt__Rr__QueryUsers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsersAck_Closure )
 ( const Ptt__Rr__QueryUsersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartments_Closure )
 ( const Ptt__Rr__QueryDepartments *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentsAck_Closure )
 ( const Ptt__Rr__QueryDepartmentsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembers_Closure )
 ( const Ptt__Rr__QueryDepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembersAck_Closure )
 ( const Ptt__Rr__QueryDepartmentMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTree_Closure )
 ( const Ptt__Rr__QueryDepartmentTree *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTreeAck_Closure )
 ( const Ptt__Rr__QueryDepartmentTreeAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroup_Closure )
 ( const Ptt__Rr__JoinGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroupAck_Closure )
 ( const Ptt__Rr__JoinGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroup_Closure )
 ( const Ptt__Rr__WatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupAck_Closure )
 ( const Ptt__Rr__WatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ByeGroup_Closure )
 ( const Ptt__Rr__ByeGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__IgnoreTalk_Closure )
 ( const Ptt__Rr__IgnoreTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ContinueTalk_Closure )
 ( const Ptt__Rr__ContinueTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dnd_Closure )
 ( const Ptt__Rr__Dnd *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroup_Closure )
 ( const Ptt__Rr__LeaveGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroupAck_Closure )
 ( const Ptt__Rr__LeaveGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMic_Closure )
 ( const Ptt__Rr__RequestMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMicAck_Closure )
 ( const Ptt__Rr__RequestMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMic_Closure )
 ( const Ptt__Rr__ReleaseMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMicAck_Closure )
 ( const Ptt__Rr__ReleaseMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Call_Closure )
 ( const Ptt__Rr__Call *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CallAck_Closure )
 ( const Ptt__Rr__CallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCall_Closure )
 ( const Ptt__Rr__SingleCall *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCallAck_Closure )
 ( const Ptt__Rr__SingleCallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDial_Closure )
 ( const Ptt__Rr__QuickDial *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDialAck_Closure )
 ( const Ptt__Rr__QuickDialAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeName_Closure )
 ( const Ptt__Rr__ChangeName *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeNameAck_Closure )
 ( const Ptt__Rr__ChangeNameAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePassword_Closure )
 ( const Ptt__Rr__ChangePassword *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePasswordAck_Closure )
 ( const Ptt__Rr__ChangePasswordAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContacts_Closure )
 ( const Ptt__Rr__MakeContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsAck_Closure )
 ( const Ptt__Rr__MakeContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponse_Closure )
 ( const Ptt__Rr__MakeContactsResponse *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponseAck_Closure )
 ( const Ptt__Rr__MakeContactsResponseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContacts_Closure )
 ( const Ptt__Rr__RemoveContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContactsAck_Closure )
 ( const Ptt__Rr__RemoveContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocation_Closure )
 ( const Ptt__Rr__ReportLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocationAck_Closure )
 ( const Ptt__Rr__ReportLocationAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroup_Closure )
 ( const Ptt__Rr__CreateGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroupAck_Closure )
 ( const Ptt__Rr__CreateGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroup_Closure )
 ( const Ptt__Rr__DeleteGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroupAck_Closure )
 ( const Ptt__Rr__DeleteGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroup_Closure )
 ( const Ptt__Rr__ModifyGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroupAck_Closure )
 ( const Ptt__Rr__ModifyGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembership_Closure )
 ( const Ptt__Rr__EmpowerMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembershipAck_Closure )
 ( const Ptt__Rr__EmpowerMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembership_Closure )
 ( const Ptt__Rr__DepriveMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembershipAck_Closure )
 ( const Ptt__Rr__DepriveMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dispatch_Closure )
 ( const Ptt__Rr__Dispatch *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DispatchAck_Closure )
 ( const Ptt__Rr__DispatchAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUser_Closure )
 ( const Ptt__Rr__ConfigureUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUserAck_Closure )
 ( const Ptt__Rr__ConfigureUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMic_Closure )
 ( const Ptt__Rr__TakeMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMicAck_Closure )
 ( const Ptt__Rr__TakeMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabase_Closure )
 ( const Ptt__Rr__SynchDatabase *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabaseAck_Closure )
 ( const Ptt__Rr__SynchDatabaseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheet_Closure )
 ( const Ptt__Rr__PostWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheetAck_Closure )
 ( const Ptt__Rr__PostWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheet_Closure )
 ( const Ptt__Rr__ResponseWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheetAck_Closure )
 ( const Ptt__Rr__ResponseWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServer_Closure )
 ( const Ptt__Rr__QueryServer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServerAck_Closure )
 ( const Ptt__Rr__QueryServerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigure_Closure )
 ( const Ptt__Rr__RequestConfigure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigureAck_Closure )
 ( const Ptt__Rr__RequestConfigureAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivate_Closure )
 ( const Ptt__Rr__RequestActivate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivateAck_Closure )
 ( const Ptt__Rr__RequestActivateAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcast_Closure )
 ( const Ptt__Rr__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcastAck_Closure )
 ( const Ptt__Rr__CustomBroadcastAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRoles_Closure )
 ( const Ptt__Rr__ChangeUserRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRolesAck_Closure )
 ( const Ptt__Rr__ChangeUserRolesAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroup_Closure )
 ( const Ptt__Rr__GetWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroupAck_Closure )
 ( const Ptt__Rr__GetWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroup_Closure )
 ( const Ptt__Rr__AddWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroupAck_Closure )
 ( const Ptt__Rr__AddWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroup_Closure )
 ( const Ptt__Rr__RemoveWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroupAck_Closure )
 ( const Ptt__Rr__RemoveWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupEx_Closure )
 ( const Ptt__Rr__WatchGroupEx *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupExAck_Closure )
 ( const Ptt__Rr__WatchGroupExAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Invite_Closure )
 ( const Ptt__Rr__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__InviteAck_Closure )
 ( const Ptt__Rr__InviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInvite_Closure )
 ( const Ptt__Rr__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInviteAck_Closure )
 ( const Ptt__Rr__ResponseInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInvite_Closure )
 ( const Ptt__Rr__CancelInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInviteAck_Closure )
 ( const Ptt__Rr__CancelInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncrypt_Closure )
 ( const Ptt__Rr__SetEncrypt *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncryptAck_Closure )
 ( const Ptt__Rr__SetEncryptAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUser_Closure )
 ( const Ptt__Rr__ListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUserAck_Closure )
 ( const Ptt__Rr__ListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUser_Closure )
 ( const Ptt__Rr__UnListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUserAck_Closure )
 ( const Ptt__Rr__UnListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListener_Closure )
 ( const Ptt__Rr__QueryListener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListenerAck_Closure )
 ( const Ptt__Rr__QueryListenerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Deliver_Closure )
 ( const Ptt__Rr__Deliver *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeliverAck_Closure )
 ( const Ptt__Rr__DeliverAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__TxtBroadcast_Closure )
 ( const Ptt__Serv__TxtBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__MobileStandard_Closure )
 ( const Ptt__Serv__MobileStandard *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__DispatchReconnection_Closure )
 ( const Ptt__Serv__DispatchReconnection *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__Configuration_Closure )
 ( const Ptt__Serv__Configuration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__MultimediaMessage_Closure )
 ( const Ptt__Serv__MultimediaMessage *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__ExternalServMsg_Closure )
 ( const Ptt__Serv__ExternalServMsg *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Reconfigured_Closure )
 ( const Ptt__Push__Reconfigured *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__UsersChanged_Closure )
 ( const Ptt__Push__UsersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__GroupListChanged_Closure )
 ( const Ptt__Push__GroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__WatchGroupListChanged_Closure )
 ( const Ptt__Push__WatchGroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged__MemberChanged_Closure )
 ( const Ptt__Push__MembersChanged__MemberChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged_Closure )
 ( const Ptt__Push__MembersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked__Request_Closure )
 ( const Ptt__Push__ContactshipAsked__Request *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked_Closure )
 ( const Ptt__Push__ContactshipAsked *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactsChanged_Closure )
 ( const Ptt__Push__ContactsChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberGetMic_Closure )
 ( const Ptt__Push__MemberGetMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberLostMic_Closure )
 ( const Ptt__Push__MemberLostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__LostMic_Closure )
 ( const Ptt__Push__LostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CurrentGroup_Closure )
 ( const Ptt__Push__CurrentGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Kickout_Closure )
 ( const Ptt__Push__Kickout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__NewWorksheet_Closure )
 ( const Ptt__Push__NewWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CustomBroadcast_Closure )
 ( const Ptt__Push__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ChangeRoles_Closure )
 ( const Ptt__Push__ChangeRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Invite_Closure )
 ( const Ptt__Push__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ResponseInvite_Closure )
 ( const Ptt__Push__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Sos__Alarm_Closure )
 ( const Sos__Alarm *message ,
 void *closure_data ) ;
typedef void ( *Sos__Report_Closure )
 ( const Sos__Report *message ,
 void *closure_data ) ;
typedef void ( *Sos__ReportAck_Closure )
 ( const Sos__ReportAck *message ,
 void *closure_data ) ;
typedef void ( *Sos__Process_Closure )
 ( const Sos__Process *message ,
 void *closure_data ) ;
typedef void ( *Sos__ProcessAck_Closure )
 ( const Sos__ProcessAck *message ,
 void *closure_data ) ;
typedef void ( *Sos__Close_Closure )
 ( const Sos__Close *message ,
 void *closure_data ) ;
typedef void ( *Sos__CloseAck_Closure )
 ( const Sos__CloseAck *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmNew_Closure )
 ( const Sos__AlarmNew *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmProcess_Closure )
 ( const Sos__AlarmProcess *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmClosed_Closure )
 ( const Sos__AlarmClosed *message ,
 void *closure_data ) ;
typedef void ( *Sos__Query_Closure )
 ( const Sos__Query *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmList_Closure )
 ( const Sos__AlarmList *message ,
 void *closure_data ) ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef void ( *pfn_connection_notify ) ( connection_t* connection , CONNECTION_STATUS status , void* user ) ;
typedef void ( *pfn_connection_on_recv_msg_timeout ) ( connection_t* connection , const char* message_name , void* user ) ;
typedef void ( *pfn_registerprocess_cb ) ( const ProtobufCMessage* message , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void ( *pfn_focus_notify ) ( focus_manager_t* fm , void* requestor , boolean focus ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef VO_S32 ( * VOAUDIOCALLBACKPROC ) ( VO_PTR pUserData , VO_CODECBUFFER * pAudioBuffer , VO_AUDIO_FORMAT * pAudioFormat , VO_S32 nStart ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\file.ppp
//PPL Source File Name : src\\file.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\focus_manager.ppp
//PPL Source File Name : src\\focus_manager.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef void ( *pfn_focus_notify ) ( focus_manager_t* fm , void* requestor , boolean focus ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\hash.ppp
//PPL Source File Name : src\\hash.c
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_audio_ai.ppp
//PPL Source File Name : src\\http_audio_ai.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void* hal_mutex_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_create_group.ppp
//PPL Source File Name : src\\http_create_group.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void* hal_mutex_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef float float_t ;
typedef double double_t ;
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
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
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_lbs.ppp
//PPL Source File Name : src\\http_lbs.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void* hal_mutex_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef float float_t ;
typedef double double_t ;
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
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
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_location.ppp
//PPL Source File Name : src\\http_location.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void* hal_mutex_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef float float_t ;
typedef double double_t ;
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
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
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_parser.ppp
//PPL Source File Name : src\\http_parser.c
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
typedef int ( *http_data_cb ) ( http_parser* , const char *at , size_t length ) ;
typedef int ( *http_cb ) ( http_parser* ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_patrol.ppp
//PPL Source File Name : src\\http_patrol.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void* hal_mutex_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_record_file.ppp
//PPL Source File Name : src\\http_record_file.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void* hal_mutex_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_reminder.ppp
//PPL Source File Name : src\\http_reminder.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void* hal_mutex_t ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_scheme.ppp
//PPL Source File Name : src\\http_scheme.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_sos.ppp
//PPL Source File Name : src\\http_sos.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void* hal_mutex_t ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef float float_t ;
typedef double double_t ;
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
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
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_update.ppp
//PPL Source File Name : src\\http_update.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void* hal_mutex_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef char* SSLCertPathPtr ;
typedef char* SSLCipherListPtr ;
typedef unsigned char UINT8 ;
typedef void* qlFotaImgProcCtxPtr ;
typedef void* qlFotaImgProcCtxPtr ;
typedef void ( *qlFotaProgressCB_t ) ( qlFotaSta sta , int progress ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_upload.ppp
//PPL Source File Name : src\\http_upload.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_weather.ppp
//PPL Source File Name : src\\http_weather.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void* hal_mutex_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef float float_t ;
typedef double double_t ;
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
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
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\http_write_account.ppp
//PPL Source File Name : src\\http_write_account.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void* hal_mutex_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef int ( *data_recv_cb_t ) ( echat_http_t* http , const char* data , int size , int total , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\info_collect.ppp
//PPL Source File Name : src\\info_collect.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__User_Closure )
 ( const Ptt__Collect__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Server_Closure )
 ( const Ptt__Collect__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Terminal_Closure )
 ( const Ptt__Collect__Terminal *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__NetWork_Closure )
 ( const Ptt__Collect__NetWork *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__NetDelay_Closure )
 ( const Ptt__Collect__NetDelay *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__GpsCnoInfo_Closure )
 ( const Ptt__Collect__GpsCnoInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__BaseInfo_Closure )
 ( const Ptt__Collect__BaseInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Disconnect_Closure )
 ( const Ptt__Collect__Disconnect *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Reconnect_Closure )
 ( const Ptt__Collect__Reconnect *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__NetStat_Closure )
 ( const Ptt__Collect__NetStat *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Speaker_Closure )
 ( const Ptt__Collect__Speaker *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Listener_Closure )
 ( const Ptt__Collect__Listener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__SessionStat_Closure )
 ( const Ptt__Collect__SessionStat *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Login_Closure )
 ( const Ptt__Rr__Login *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LoginAck_Closure )
 ( const Ptt__Rr__LoginAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Logout_Closure )
 ( const Ptt__Rr__Logout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LogoutAck_Closure )
 ( const Ptt__Rr__LogoutAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroup_Closure )
 ( const Ptt__Rr__QueryGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroupAck_Closure )
 ( const Ptt__Rr__QueryGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroup_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroupAck_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembers_Closure )
 ( const Ptt__Rr__QueryMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck_Closure )
 ( const Ptt__Rr__QueryMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck2_Closure )
 ( const Ptt__Rr__QueryMembersAck2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContacts_Closure )
 ( const Ptt__Rr__QueryContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContactsAck_Closure )
 ( const Ptt__Rr__QueryContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsers_Closure )
 ( const Ptt__Rr__QueryUsers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsersAck_Closure )
 ( const Ptt__Rr__QueryUsersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartments_Closure )
 ( const Ptt__Rr__QueryDepartments *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentsAck_Closure )
 ( const Ptt__Rr__QueryDepartmentsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembers_Closure )
 ( const Ptt__Rr__QueryDepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembersAck_Closure )
 ( const Ptt__Rr__QueryDepartmentMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTree_Closure )
 ( const Ptt__Rr__QueryDepartmentTree *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTreeAck_Closure )
 ( const Ptt__Rr__QueryDepartmentTreeAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroup_Closure )
 ( const Ptt__Rr__JoinGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroupAck_Closure )
 ( const Ptt__Rr__JoinGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroup_Closure )
 ( const Ptt__Rr__WatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupAck_Closure )
 ( const Ptt__Rr__WatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ByeGroup_Closure )
 ( const Ptt__Rr__ByeGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__IgnoreTalk_Closure )
 ( const Ptt__Rr__IgnoreTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ContinueTalk_Closure )
 ( const Ptt__Rr__ContinueTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dnd_Closure )
 ( const Ptt__Rr__Dnd *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroup_Closure )
 ( const Ptt__Rr__LeaveGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroupAck_Closure )
 ( const Ptt__Rr__LeaveGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMic_Closure )
 ( const Ptt__Rr__RequestMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMicAck_Closure )
 ( const Ptt__Rr__RequestMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMic_Closure )
 ( const Ptt__Rr__ReleaseMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMicAck_Closure )
 ( const Ptt__Rr__ReleaseMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Call_Closure )
 ( const Ptt__Rr__Call *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CallAck_Closure )
 ( const Ptt__Rr__CallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCall_Closure )
 ( const Ptt__Rr__SingleCall *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCallAck_Closure )
 ( const Ptt__Rr__SingleCallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDial_Closure )
 ( const Ptt__Rr__QuickDial *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDialAck_Closure )
 ( const Ptt__Rr__QuickDialAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeName_Closure )
 ( const Ptt__Rr__ChangeName *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeNameAck_Closure )
 ( const Ptt__Rr__ChangeNameAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePassword_Closure )
 ( const Ptt__Rr__ChangePassword *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePasswordAck_Closure )
 ( const Ptt__Rr__ChangePasswordAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContacts_Closure )
 ( const Ptt__Rr__MakeContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsAck_Closure )
 ( const Ptt__Rr__MakeContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponse_Closure )
 ( const Ptt__Rr__MakeContactsResponse *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponseAck_Closure )
 ( const Ptt__Rr__MakeContactsResponseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContacts_Closure )
 ( const Ptt__Rr__RemoveContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContactsAck_Closure )
 ( const Ptt__Rr__RemoveContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocation_Closure )
 ( const Ptt__Rr__ReportLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocationAck_Closure )
 ( const Ptt__Rr__ReportLocationAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroup_Closure )
 ( const Ptt__Rr__CreateGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroupAck_Closure )
 ( const Ptt__Rr__CreateGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroup_Closure )
 ( const Ptt__Rr__DeleteGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroupAck_Closure )
 ( const Ptt__Rr__DeleteGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroup_Closure )
 ( const Ptt__Rr__ModifyGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroupAck_Closure )
 ( const Ptt__Rr__ModifyGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembership_Closure )
 ( const Ptt__Rr__EmpowerMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembershipAck_Closure )
 ( const Ptt__Rr__EmpowerMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembership_Closure )
 ( const Ptt__Rr__DepriveMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembershipAck_Closure )
 ( const Ptt__Rr__DepriveMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dispatch_Closure )
 ( const Ptt__Rr__Dispatch *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DispatchAck_Closure )
 ( const Ptt__Rr__DispatchAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUser_Closure )
 ( const Ptt__Rr__ConfigureUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUserAck_Closure )
 ( const Ptt__Rr__ConfigureUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMic_Closure )
 ( const Ptt__Rr__TakeMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMicAck_Closure )
 ( const Ptt__Rr__TakeMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabase_Closure )
 ( const Ptt__Rr__SynchDatabase *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabaseAck_Closure )
 ( const Ptt__Rr__SynchDatabaseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheet_Closure )
 ( const Ptt__Rr__PostWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheetAck_Closure )
 ( const Ptt__Rr__PostWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheet_Closure )
 ( const Ptt__Rr__ResponseWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheetAck_Closure )
 ( const Ptt__Rr__ResponseWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServer_Closure )
 ( const Ptt__Rr__QueryServer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServerAck_Closure )
 ( const Ptt__Rr__QueryServerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigure_Closure )
 ( const Ptt__Rr__RequestConfigure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigureAck_Closure )
 ( const Ptt__Rr__RequestConfigureAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivate_Closure )
 ( const Ptt__Rr__RequestActivate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivateAck_Closure )
 ( const Ptt__Rr__RequestActivateAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcast_Closure )
 ( const Ptt__Rr__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcastAck_Closure )
 ( const Ptt__Rr__CustomBroadcastAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRoles_Closure )
 ( const Ptt__Rr__ChangeUserRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRolesAck_Closure )
 ( const Ptt__Rr__ChangeUserRolesAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroup_Closure )
 ( const Ptt__Rr__GetWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroupAck_Closure )
 ( const Ptt__Rr__GetWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroup_Closure )
 ( const Ptt__Rr__AddWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroupAck_Closure )
 ( const Ptt__Rr__AddWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroup_Closure )
 ( const Ptt__Rr__RemoveWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroupAck_Closure )
 ( const Ptt__Rr__RemoveWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupEx_Closure )
 ( const Ptt__Rr__WatchGroupEx *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupExAck_Closure )
 ( const Ptt__Rr__WatchGroupExAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Invite_Closure )
 ( const Ptt__Rr__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__InviteAck_Closure )
 ( const Ptt__Rr__InviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInvite_Closure )
 ( const Ptt__Rr__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInviteAck_Closure )
 ( const Ptt__Rr__ResponseInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInvite_Closure )
 ( const Ptt__Rr__CancelInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInviteAck_Closure )
 ( const Ptt__Rr__CancelInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncrypt_Closure )
 ( const Ptt__Rr__SetEncrypt *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncryptAck_Closure )
 ( const Ptt__Rr__SetEncryptAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUser_Closure )
 ( const Ptt__Rr__ListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUserAck_Closure )
 ( const Ptt__Rr__ListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUser_Closure )
 ( const Ptt__Rr__UnListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUserAck_Closure )
 ( const Ptt__Rr__UnListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListener_Closure )
 ( const Ptt__Rr__QueryListener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListenerAck_Closure )
 ( const Ptt__Rr__QueryListenerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Deliver_Closure )
 ( const Ptt__Rr__Deliver *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeliverAck_Closure )
 ( const Ptt__Rr__DeliverAck *message ,
 void *closure_data ) ;
typedef void* hal_mutex_t ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\ini.ppp
//PPL Source File Name : src\\ini.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef void* hal_mutex_t ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\ini_d.ppp
//PPL Source File Name : src\\ini_d.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\libscl-adapter.ppp
//PPL Source File Name : src\\libscl-adapter.c
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\list.ppp
//PPL Source File Name : src\\list.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\location.ppp
//PPL Source File Name : src\\location.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\locator.ppp
//PPL Source File Name : src\\locator.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *pfn_connection_notify ) ( connection_t* connection , CONNECTION_STATUS status , void* user ) ;
typedef void ( *pfn_connection_on_recv_msg_timeout ) ( connection_t* connection , const char* message_name , void* user ) ;
typedef void ( *pfn_registerprocess_cb ) ( const ProtobufCMessage* message , void* user ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Reconfigured_Closure )
 ( const Ptt__Push__Reconfigured *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__UsersChanged_Closure )
 ( const Ptt__Push__UsersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__GroupListChanged_Closure )
 ( const Ptt__Push__GroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__WatchGroupListChanged_Closure )
 ( const Ptt__Push__WatchGroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged__MemberChanged_Closure )
 ( const Ptt__Push__MembersChanged__MemberChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged_Closure )
 ( const Ptt__Push__MembersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked__Request_Closure )
 ( const Ptt__Push__ContactshipAsked__Request *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked_Closure )
 ( const Ptt__Push__ContactshipAsked *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactsChanged_Closure )
 ( const Ptt__Push__ContactsChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberGetMic_Closure )
 ( const Ptt__Push__MemberGetMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberLostMic_Closure )
 ( const Ptt__Push__MemberLostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__LostMic_Closure )
 ( const Ptt__Push__LostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CurrentGroup_Closure )
 ( const Ptt__Push__CurrentGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Kickout_Closure )
 ( const Ptt__Push__Kickout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__NewWorksheet_Closure )
 ( const Ptt__Push__NewWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CustomBroadcast_Closure )
 ( const Ptt__Push__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ChangeRoles_Closure )
 ( const Ptt__Push__ChangeRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Invite_Closure )
 ( const Ptt__Push__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ResponseInvite_Closure )
 ( const Ptt__Push__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Login_Closure )
 ( const Ptt__Rr__Login *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LoginAck_Closure )
 ( const Ptt__Rr__LoginAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Logout_Closure )
 ( const Ptt__Rr__Logout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LogoutAck_Closure )
 ( const Ptt__Rr__LogoutAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroup_Closure )
 ( const Ptt__Rr__QueryGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroupAck_Closure )
 ( const Ptt__Rr__QueryGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroup_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroupAck_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembers_Closure )
 ( const Ptt__Rr__QueryMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck_Closure )
 ( const Ptt__Rr__QueryMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck2_Closure )
 ( const Ptt__Rr__QueryMembersAck2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContacts_Closure )
 ( const Ptt__Rr__QueryContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContactsAck_Closure )
 ( const Ptt__Rr__QueryContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsers_Closure )
 ( const Ptt__Rr__QueryUsers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsersAck_Closure )
 ( const Ptt__Rr__QueryUsersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartments_Closure )
 ( const Ptt__Rr__QueryDepartments *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentsAck_Closure )
 ( const Ptt__Rr__QueryDepartmentsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembers_Closure )
 ( const Ptt__Rr__QueryDepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembersAck_Closure )
 ( const Ptt__Rr__QueryDepartmentMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTree_Closure )
 ( const Ptt__Rr__QueryDepartmentTree *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTreeAck_Closure )
 ( const Ptt__Rr__QueryDepartmentTreeAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroup_Closure )
 ( const Ptt__Rr__JoinGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroupAck_Closure )
 ( const Ptt__Rr__JoinGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroup_Closure )
 ( const Ptt__Rr__WatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupAck_Closure )
 ( const Ptt__Rr__WatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ByeGroup_Closure )
 ( const Ptt__Rr__ByeGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__IgnoreTalk_Closure )
 ( const Ptt__Rr__IgnoreTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ContinueTalk_Closure )
 ( const Ptt__Rr__ContinueTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dnd_Closure )
 ( const Ptt__Rr__Dnd *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroup_Closure )
 ( const Ptt__Rr__LeaveGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroupAck_Closure )
 ( const Ptt__Rr__LeaveGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMic_Closure )
 ( const Ptt__Rr__RequestMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMicAck_Closure )
 ( const Ptt__Rr__RequestMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMic_Closure )
 ( const Ptt__Rr__ReleaseMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMicAck_Closure )
 ( const Ptt__Rr__ReleaseMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Call_Closure )
 ( const Ptt__Rr__Call *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CallAck_Closure )
 ( const Ptt__Rr__CallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCall_Closure )
 ( const Ptt__Rr__SingleCall *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCallAck_Closure )
 ( const Ptt__Rr__SingleCallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDial_Closure )
 ( const Ptt__Rr__QuickDial *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDialAck_Closure )
 ( const Ptt__Rr__QuickDialAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeName_Closure )
 ( const Ptt__Rr__ChangeName *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeNameAck_Closure )
 ( const Ptt__Rr__ChangeNameAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePassword_Closure )
 ( const Ptt__Rr__ChangePassword *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePasswordAck_Closure )
 ( const Ptt__Rr__ChangePasswordAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContacts_Closure )
 ( const Ptt__Rr__MakeContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsAck_Closure )
 ( const Ptt__Rr__MakeContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponse_Closure )
 ( const Ptt__Rr__MakeContactsResponse *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponseAck_Closure )
 ( const Ptt__Rr__MakeContactsResponseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContacts_Closure )
 ( const Ptt__Rr__RemoveContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContactsAck_Closure )
 ( const Ptt__Rr__RemoveContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocation_Closure )
 ( const Ptt__Rr__ReportLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocationAck_Closure )
 ( const Ptt__Rr__ReportLocationAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroup_Closure )
 ( const Ptt__Rr__CreateGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroupAck_Closure )
 ( const Ptt__Rr__CreateGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroup_Closure )
 ( const Ptt__Rr__DeleteGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroupAck_Closure )
 ( const Ptt__Rr__DeleteGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroup_Closure )
 ( const Ptt__Rr__ModifyGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroupAck_Closure )
 ( const Ptt__Rr__ModifyGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembership_Closure )
 ( const Ptt__Rr__EmpowerMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembershipAck_Closure )
 ( const Ptt__Rr__EmpowerMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembership_Closure )
 ( const Ptt__Rr__DepriveMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembershipAck_Closure )
 ( const Ptt__Rr__DepriveMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dispatch_Closure )
 ( const Ptt__Rr__Dispatch *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DispatchAck_Closure )
 ( const Ptt__Rr__DispatchAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUser_Closure )
 ( const Ptt__Rr__ConfigureUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUserAck_Closure )
 ( const Ptt__Rr__ConfigureUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMic_Closure )
 ( const Ptt__Rr__TakeMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMicAck_Closure )
 ( const Ptt__Rr__TakeMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabase_Closure )
 ( const Ptt__Rr__SynchDatabase *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabaseAck_Closure )
 ( const Ptt__Rr__SynchDatabaseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheet_Closure )
 ( const Ptt__Rr__PostWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheetAck_Closure )
 ( const Ptt__Rr__PostWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheet_Closure )
 ( const Ptt__Rr__ResponseWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheetAck_Closure )
 ( const Ptt__Rr__ResponseWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServer_Closure )
 ( const Ptt__Rr__QueryServer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServerAck_Closure )
 ( const Ptt__Rr__QueryServerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigure_Closure )
 ( const Ptt__Rr__RequestConfigure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigureAck_Closure )
 ( const Ptt__Rr__RequestConfigureAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivate_Closure )
 ( const Ptt__Rr__RequestActivate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivateAck_Closure )
 ( const Ptt__Rr__RequestActivateAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcast_Closure )
 ( const Ptt__Rr__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcastAck_Closure )
 ( const Ptt__Rr__CustomBroadcastAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRoles_Closure )
 ( const Ptt__Rr__ChangeUserRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRolesAck_Closure )
 ( const Ptt__Rr__ChangeUserRolesAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroup_Closure )
 ( const Ptt__Rr__GetWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroupAck_Closure )
 ( const Ptt__Rr__GetWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroup_Closure )
 ( const Ptt__Rr__AddWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroupAck_Closure )
 ( const Ptt__Rr__AddWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroup_Closure )
 ( const Ptt__Rr__RemoveWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroupAck_Closure )
 ( const Ptt__Rr__RemoveWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupEx_Closure )
 ( const Ptt__Rr__WatchGroupEx *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupExAck_Closure )
 ( const Ptt__Rr__WatchGroupExAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Invite_Closure )
 ( const Ptt__Rr__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__InviteAck_Closure )
 ( const Ptt__Rr__InviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInvite_Closure )
 ( const Ptt__Rr__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInviteAck_Closure )
 ( const Ptt__Rr__ResponseInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInvite_Closure )
 ( const Ptt__Rr__CancelInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInviteAck_Closure )
 ( const Ptt__Rr__CancelInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncrypt_Closure )
 ( const Ptt__Rr__SetEncrypt *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncryptAck_Closure )
 ( const Ptt__Rr__SetEncryptAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUser_Closure )
 ( const Ptt__Rr__ListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUserAck_Closure )
 ( const Ptt__Rr__ListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUser_Closure )
 ( const Ptt__Rr__UnListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUserAck_Closure )
 ( const Ptt__Rr__UnListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListener_Closure )
 ( const Ptt__Rr__QueryListener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListenerAck_Closure )
 ( const Ptt__Rr__QueryListenerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Deliver_Closure )
 ( const Ptt__Rr__Deliver *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeliverAck_Closure )
 ( const Ptt__Rr__DeliverAck *message ,
 void *closure_data ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\log.ppp
//PPL Source File Name : src\\log.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void* hal_mutex_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\looper_st.ppp
//PPL Source File Name : src\\looper_st.c
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef void ( * pfn_hal_looper_handle_callback ) ( hal_looper_t* looper , int handle , void* user ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\lrq.ppp
//PPL Source File Name : src\\lrq.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\map.ppp
//PPL Source File Name : src\\map.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\memory.ppp
//PPL Source File Name : src\\memory.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
typedef unsigned long UTF32 ;
typedef unsigned short UTF16 ;
typedef unsigned char UTF8 ;
typedef unsigned int INT ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\net.pb-c.ppp
//PPL Source File Name : src\\net.pb-c.c
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *Ptt__Net__HeartBeat_Closure )
 ( const Ptt__Net__HeartBeat *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Net__Ping_Closure )
 ( const Ptt__Net__Ping *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Net__Pong_Closure )
 ( const Ptt__Net__Pong *message ,
 void *closure_data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\network.ppp
//PPL Source File Name : src\\network.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( * pfn_hal_looper_handle_callback ) ( hal_looper_t* looper , int handle , void* user ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\notify.ppp
//PPL Source File Name : src\\notify.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\null_location.ppp
//PPL Source File Name : src\\null_location.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_algorithm.ppp
//PPL Source File Name : src\\oem_algorithm.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef float float_t ;
typedef double double_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_aud.ppp
//PPL Source File Name : src\\oem_aud.c
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
typedef void* OSATaskRef ;
typedef void* OSAHISRRef ;
typedef void* OSAMsgQRef ;
typedef void* OSAMailboxQRef ;
typedef void* OSAPartitionPoolRef ;
typedef UINT8 OS_STATUS ;
typedef UINT8 OS_STATUS ;
typedef void* OS_HISR ;
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
typedef void *QL_PCM_HANDLE ;
typedef void *PCM_HANDLE_T ;
typedef void ( *QL_AUDIOHAL_HANDLER_T ) ( void ) ;
typedef void ( *ql_cb_on_speakerpa ) ( unsigned int on ) ;
typedef void ( *ql_cb_on_player ) ( char *p_data , int len , ql_aud_player_state state ) ;
typedef int ( *ql_cb_on_record ) ( char *p_data , int len , ql_aud_record_state state ) ;
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
typedef int QlOSStatus ;
typedef void * ql_task_t ;
typedef void * ql_sem_t ;
typedef void * ql_mutex_t ;
typedef void * ql_queue_t ;
typedef void * ql_timer_t ;
typedef void * ql_flag_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef int ( *pfn_play_type_cb ) ( int status ) ;
typedef int ( *pfn_record_cb ) ( int result , unsigned char *pBuf , unsigned int len ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_device.ppp
//PPL Source File Name : src\\oem_device.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
typedef void ( *QL_NW_EventHandlerFunc_t ) ( unsigned int ind_flag , void *ind_msg_buf , unsigned int ind_msg_len , void *contextPtr ) ;
typedef void ( *QL_NW_DSDS_EventHandlerFunc_t ) ( unsigned int ind_flag , void *ind_msg_buf , unsigned int ind_msg_len , void *contextPtr , unsigned short simid ) ;
typedef void ( *QL_NW_Wifiscan_CBFunc_t ) ( unsigned char scan_count , const char *scan_info ) ;
typedef int QlOSStatus ;
typedef void * ql_task_t ;
typedef void * ql_sem_t ;
typedef void * ql_mutex_t ;
typedef void * ql_queue_t ;
typedef void * ql_timer_t ;
typedef void * ql_flag_t ;
typedef unsigned int size_t ;
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
typedef UINT8 u8_t ;
typedef UINT16 u16_t ;
typedef UINT32 u32_t ;
typedef UINT64 u64_t ;
typedef INT8 s8_t ;
typedef INT16 s16_t ;
typedef INT32 s32_t ;
typedef void* msg_t ;
typedef u32_t mem_ptr_t ;
typedef union {
 ip_addr_t ip4 ;
 ip6_addr_t ip6 ;
 } ipX_addr_t ;
typedef s8_t err_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef size_t mem_size_t ;
typedef UINT32 sys_prot_t ;
typedef void * sys_mutex_t ;
typedef void * sys_sem_t ;
typedef void * sys_mbox_t ;
typedef void * sys_thread_t ;
typedef void ( *printCallback ) ( char *printstr ) ;
typedef void ( *lwip_thread_fn ) ( void *pArgs ) ;
typedef err_t ( *lwip_run_entry ) ( void *pArgs ) ;
typedef void ( * socket_callback ) ( int s , int evt , u16_t len ) ;
typedef u32_t socklen_t ;
typedef void ( * ql_data_call_event_cb_t ) ( int profile_idx , int state ) ;
typedef void ( * nw_status_cb ) ( int profile_idx , int nw_status ) ;
typedef int ( *g_ql_network_register_wait ) ( int timeout ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_dsp.ppp
//PPL Source File Name : src\\oem_dsp.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
typedef int ( *pfn_play_type_cb ) ( int status ) ;
typedef int ( *pfn_record_cb ) ( int result , unsigned char *pBuf , unsigned int len ) ;
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
typedef void* OSATaskRef ;
typedef void* OSAHISRRef ;
typedef void* OSAMsgQRef ;
typedef void* OSAMailboxQRef ;
typedef void* OSAPartitionPoolRef ;
typedef UINT8 OS_STATUS ;
typedef UINT8 OS_STATUS ;
typedef void* OS_HISR ;
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
typedef void *QL_PCM_HANDLE ;
typedef void *PCM_HANDLE_T ;
typedef void ( *QL_AUDIOHAL_HANDLER_T ) ( void ) ;
typedef void ( *ql_cb_on_speakerpa ) ( unsigned int on ) ;
typedef void ( *ql_cb_on_player ) ( char *p_data , int len , ql_aud_player_state state ) ;
typedef int ( *ql_cb_on_record ) ( char *p_data , int len , ql_aud_record_state state ) ;
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
typedef int QlOSStatus ;
typedef void * ql_task_t ;
typedef void * ql_sem_t ;
typedef void * ql_mutex_t ;
typedef void * ql_queue_t ;
typedef void * ql_timer_t ;
typedef void * ql_flag_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_event.ppp
//PPL Source File Name : src\\oem_event.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
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
//PPL Source File Name : build\obj\src\oem_file.ppp
//PPL Source File Name : src\\oem_file.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
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
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
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
typedef unsigned int File_Handle ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_log.ppp
//PPL Source File Name : src\\oem_log.c
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
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
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_memory.ppp
//PPL Source File Name : src\\oem_memory.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_network.ppp
//PPL Source File Name : src\\oem_network.c
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
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
typedef UINT8 u8_t ;
typedef UINT16 u16_t ;
typedef UINT32 u32_t ;
typedef UINT64 u64_t ;
typedef INT8 s8_t ;
typedef INT16 s16_t ;
typedef INT32 s32_t ;
typedef void* msg_t ;
typedef u32_t mem_ptr_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef union {
 ip_addr_t ip4 ;
 ip6_addr_t ip6 ;
 } ipX_addr_t ;
typedef s8_t err_t ;
typedef size_t mem_size_t ;
typedef UINT32 sys_prot_t ;
typedef void * sys_mutex_t ;
typedef void * sys_sem_t ;
typedef void * sys_mbox_t ;
typedef void * sys_thread_t ;
typedef void ( *printCallback ) ( char *printstr ) ;
typedef void ( *lwip_thread_fn ) ( void *pArgs ) ;
typedef err_t ( *lwip_run_entry ) ( void *pArgs ) ;
typedef void ( * socket_callback ) ( int s , int evt , u16_t len ) ;
typedef u32_t socklen_t ;
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
typedef void ( * ql_data_call_event_cb_t ) ( int profile_idx , int state ) ;
typedef void ( * nw_status_cb ) ( int profile_idx , int nw_status ) ;
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_platform.ppp
//PPL Source File Name : src\\oem_platform.c
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
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
typedef UINT8 u8_t ;
typedef UINT16 u16_t ;
typedef UINT32 u32_t ;
typedef UINT64 u64_t ;
typedef INT8 s8_t ;
typedef INT16 s16_t ;
typedef INT32 s32_t ;
typedef void* msg_t ;
typedef u32_t mem_ptr_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef union {
 ip_addr_t ip4 ;
 ip6_addr_t ip6 ;
 } ipX_addr_t ;
typedef s8_t err_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef size_t mem_size_t ;
typedef UINT32 sys_prot_t ;
typedef void * sys_mutex_t ;
typedef void * sys_sem_t ;
typedef void * sys_mbox_t ;
typedef void * sys_thread_t ;
typedef void ( *printCallback ) ( char *printstr ) ;
typedef void ( *lwip_thread_fn ) ( void *pArgs ) ;
typedef err_t ( *lwip_run_entry ) ( void *pArgs ) ;
typedef void ( * socket_callback ) ( int s , int evt , u16_t len ) ;
typedef u32_t socklen_t ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_queue.ppp
//PPL Source File Name : src\\oem_queue.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_thread.ppp
//PPL Source File Name : src\\oem_thread.c
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
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
typedef UINT8 u8_t ;
typedef UINT16 u16_t ;
typedef UINT32 u32_t ;
typedef UINT64 u64_t ;
typedef INT8 s8_t ;
typedef INT16 s16_t ;
typedef INT32 s32_t ;
typedef void* msg_t ;
typedef u32_t mem_ptr_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef union {
 ip_addr_t ip4 ;
 ip6_addr_t ip6 ;
 } ipX_addr_t ;
typedef s8_t err_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef size_t mem_size_t ;
typedef UINT32 sys_prot_t ;
typedef void * sys_mutex_t ;
typedef void * sys_sem_t ;
typedef void * sys_mbox_t ;
typedef void * sys_thread_t ;
typedef void ( *printCallback ) ( char *printstr ) ;
typedef void ( *lwip_thread_fn ) ( void *pArgs ) ;
typedef err_t ( *lwip_run_entry ) ( void *pArgs ) ;
typedef void ( * socket_callback ) ( int s , int evt , u16_t len ) ;
typedef u32_t socklen_t ;
typedef int QlOSStatus ;
typedef void * ql_task_t ;
typedef void * ql_sem_t ;
typedef void * ql_mutex_t ;
typedef void * ql_queue_t ;
typedef void * ql_timer_t ;
typedef void * ql_flag_t ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_time.ppp
//PPL Source File Name : src\\oem_time.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned int clock_t ;
typedef unsigned int time_t ;
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
typedef char ascii ;
typedef unsigned char u8 ;
typedef signed char s8 ;
typedef unsigned short u16 ;
typedef short s16 ;
typedef unsigned int u32 ;
typedef int s32 ;
typedef unsigned long long u64 ;
typedef long long s64 ;
typedef unsigned int ticks ;
typedef int HANDLE ;
typedef unsigned char uint8_t ;
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
typedef UINT8 u8_t ;
typedef UINT16 u16_t ;
typedef UINT32 u32_t ;
typedef UINT64 u64_t ;
typedef INT8 s8_t ;
typedef INT16 s16_t ;
typedef INT32 s32_t ;
typedef void* msg_t ;
typedef u32_t mem_ptr_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef union {
 ip_addr_t ip4 ;
 ip6_addr_t ip6 ;
 } ipX_addr_t ;
typedef s8_t err_t ;
typedef size_t mem_size_t ;
typedef UINT32 sys_prot_t ;
typedef void * sys_mutex_t ;
typedef void * sys_sem_t ;
typedef void * sys_mbox_t ;
typedef void * sys_thread_t ;
typedef void ( *printCallback ) ( char *printstr ) ;
typedef void ( *lwip_thread_fn ) ( void *pArgs ) ;
typedef err_t ( *lwip_run_entry ) ( void *pArgs ) ;
typedef void ( * socket_callback ) ( int s , int evt , u16_t len ) ;
typedef u32_t socklen_t ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_tone_pcm.ppp
//PPL Source File Name : src\\oem_tone_pcm.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef int ( *pfn_play_type_cb ) ( int status ) ;
typedef int ( *pfn_record_cb ) ( int result , unsigned char *pBuf , unsigned int len ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef float float_t ;
typedef double double_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\oem_tts.ppp
//PPL Source File Name : src\\oem_tts.c
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef void ( *ql_tts_cb_type ) ( QL_TTS_ENVENT_E event , char *str ) ;
typedef unsigned long UTF32 ;
typedef unsigned short UTF16 ;
typedef unsigned char UTF8 ;
typedef unsigned int INT ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\pack.ppp
//PPL Source File Name : src\\pack.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef uint32_t hal_time_t ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Net__HeartBeat_Closure )
 ( const Ptt__Net__HeartBeat *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Net__Ping_Closure )
 ( const Ptt__Net__Ping *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Net__Pong_Closure )
 ( const Ptt__Net__Pong *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Login_Closure )
 ( const Ptt__Rr__Login *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LoginAck_Closure )
 ( const Ptt__Rr__LoginAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Logout_Closure )
 ( const Ptt__Rr__Logout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LogoutAck_Closure )
 ( const Ptt__Rr__LogoutAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroup_Closure )
 ( const Ptt__Rr__QueryGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroupAck_Closure )
 ( const Ptt__Rr__QueryGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroup_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroupAck_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembers_Closure )
 ( const Ptt__Rr__QueryMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck_Closure )
 ( const Ptt__Rr__QueryMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck2_Closure )
 ( const Ptt__Rr__QueryMembersAck2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContacts_Closure )
 ( const Ptt__Rr__QueryContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContactsAck_Closure )
 ( const Ptt__Rr__QueryContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsers_Closure )
 ( const Ptt__Rr__QueryUsers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsersAck_Closure )
 ( const Ptt__Rr__QueryUsersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartments_Closure )
 ( const Ptt__Rr__QueryDepartments *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentsAck_Closure )
 ( const Ptt__Rr__QueryDepartmentsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembers_Closure )
 ( const Ptt__Rr__QueryDepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembersAck_Closure )
 ( const Ptt__Rr__QueryDepartmentMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTree_Closure )
 ( const Ptt__Rr__QueryDepartmentTree *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTreeAck_Closure )
 ( const Ptt__Rr__QueryDepartmentTreeAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroup_Closure )
 ( const Ptt__Rr__JoinGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroupAck_Closure )
 ( const Ptt__Rr__JoinGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroup_Closure )
 ( const Ptt__Rr__WatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupAck_Closure )
 ( const Ptt__Rr__WatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ByeGroup_Closure )
 ( const Ptt__Rr__ByeGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__IgnoreTalk_Closure )
 ( const Ptt__Rr__IgnoreTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ContinueTalk_Closure )
 ( const Ptt__Rr__ContinueTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dnd_Closure )
 ( const Ptt__Rr__Dnd *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroup_Closure )
 ( const Ptt__Rr__LeaveGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroupAck_Closure )
 ( const Ptt__Rr__LeaveGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMic_Closure )
 ( const Ptt__Rr__RequestMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMicAck_Closure )
 ( const Ptt__Rr__RequestMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMic_Closure )
 ( const Ptt__Rr__ReleaseMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMicAck_Closure )
 ( const Ptt__Rr__ReleaseMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Call_Closure )
 ( const Ptt__Rr__Call *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CallAck_Closure )
 ( const Ptt__Rr__CallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCall_Closure )
 ( const Ptt__Rr__SingleCall *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCallAck_Closure )
 ( const Ptt__Rr__SingleCallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDial_Closure )
 ( const Ptt__Rr__QuickDial *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDialAck_Closure )
 ( const Ptt__Rr__QuickDialAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeName_Closure )
 ( const Ptt__Rr__ChangeName *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeNameAck_Closure )
 ( const Ptt__Rr__ChangeNameAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePassword_Closure )
 ( const Ptt__Rr__ChangePassword *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePasswordAck_Closure )
 ( const Ptt__Rr__ChangePasswordAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContacts_Closure )
 ( const Ptt__Rr__MakeContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsAck_Closure )
 ( const Ptt__Rr__MakeContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponse_Closure )
 ( const Ptt__Rr__MakeContactsResponse *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponseAck_Closure )
 ( const Ptt__Rr__MakeContactsResponseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContacts_Closure )
 ( const Ptt__Rr__RemoveContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContactsAck_Closure )
 ( const Ptt__Rr__RemoveContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocation_Closure )
 ( const Ptt__Rr__ReportLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocationAck_Closure )
 ( const Ptt__Rr__ReportLocationAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroup_Closure )
 ( const Ptt__Rr__CreateGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroupAck_Closure )
 ( const Ptt__Rr__CreateGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroup_Closure )
 ( const Ptt__Rr__DeleteGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroupAck_Closure )
 ( const Ptt__Rr__DeleteGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroup_Closure )
 ( const Ptt__Rr__ModifyGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroupAck_Closure )
 ( const Ptt__Rr__ModifyGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembership_Closure )
 ( const Ptt__Rr__EmpowerMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembershipAck_Closure )
 ( const Ptt__Rr__EmpowerMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembership_Closure )
 ( const Ptt__Rr__DepriveMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembershipAck_Closure )
 ( const Ptt__Rr__DepriveMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dispatch_Closure )
 ( const Ptt__Rr__Dispatch *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DispatchAck_Closure )
 ( const Ptt__Rr__DispatchAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUser_Closure )
 ( const Ptt__Rr__ConfigureUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUserAck_Closure )
 ( const Ptt__Rr__ConfigureUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMic_Closure )
 ( const Ptt__Rr__TakeMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMicAck_Closure )
 ( const Ptt__Rr__TakeMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabase_Closure )
 ( const Ptt__Rr__SynchDatabase *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabaseAck_Closure )
 ( const Ptt__Rr__SynchDatabaseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheet_Closure )
 ( const Ptt__Rr__PostWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheetAck_Closure )
 ( const Ptt__Rr__PostWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheet_Closure )
 ( const Ptt__Rr__ResponseWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheetAck_Closure )
 ( const Ptt__Rr__ResponseWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServer_Closure )
 ( const Ptt__Rr__QueryServer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServerAck_Closure )
 ( const Ptt__Rr__QueryServerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigure_Closure )
 ( const Ptt__Rr__RequestConfigure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigureAck_Closure )
 ( const Ptt__Rr__RequestConfigureAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivate_Closure )
 ( const Ptt__Rr__RequestActivate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivateAck_Closure )
 ( const Ptt__Rr__RequestActivateAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcast_Closure )
 ( const Ptt__Rr__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcastAck_Closure )
 ( const Ptt__Rr__CustomBroadcastAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRoles_Closure )
 ( const Ptt__Rr__ChangeUserRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRolesAck_Closure )
 ( const Ptt__Rr__ChangeUserRolesAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroup_Closure )
 ( const Ptt__Rr__GetWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroupAck_Closure )
 ( const Ptt__Rr__GetWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroup_Closure )
 ( const Ptt__Rr__AddWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroupAck_Closure )
 ( const Ptt__Rr__AddWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroup_Closure )
 ( const Ptt__Rr__RemoveWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroupAck_Closure )
 ( const Ptt__Rr__RemoveWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupEx_Closure )
 ( const Ptt__Rr__WatchGroupEx *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupExAck_Closure )
 ( const Ptt__Rr__WatchGroupExAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Invite_Closure )
 ( const Ptt__Rr__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__InviteAck_Closure )
 ( const Ptt__Rr__InviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInvite_Closure )
 ( const Ptt__Rr__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInviteAck_Closure )
 ( const Ptt__Rr__ResponseInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInvite_Closure )
 ( const Ptt__Rr__CancelInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInviteAck_Closure )
 ( const Ptt__Rr__CancelInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncrypt_Closure )
 ( const Ptt__Rr__SetEncrypt *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncryptAck_Closure )
 ( const Ptt__Rr__SetEncryptAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUser_Closure )
 ( const Ptt__Rr__ListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUserAck_Closure )
 ( const Ptt__Rr__ListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUser_Closure )
 ( const Ptt__Rr__UnListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUserAck_Closure )
 ( const Ptt__Rr__UnListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListener_Closure )
 ( const Ptt__Rr__QueryListener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListenerAck_Closure )
 ( const Ptt__Rr__QueryListenerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Deliver_Closure )
 ( const Ptt__Rr__Deliver *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeliverAck_Closure )
 ( const Ptt__Rr__DeliverAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Reconfigured_Closure )
 ( const Ptt__Push__Reconfigured *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__UsersChanged_Closure )
 ( const Ptt__Push__UsersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__GroupListChanged_Closure )
 ( const Ptt__Push__GroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__WatchGroupListChanged_Closure )
 ( const Ptt__Push__WatchGroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged__MemberChanged_Closure )
 ( const Ptt__Push__MembersChanged__MemberChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged_Closure )
 ( const Ptt__Push__MembersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked__Request_Closure )
 ( const Ptt__Push__ContactshipAsked__Request *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked_Closure )
 ( const Ptt__Push__ContactshipAsked *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactsChanged_Closure )
 ( const Ptt__Push__ContactsChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberGetMic_Closure )
 ( const Ptt__Push__MemberGetMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberLostMic_Closure )
 ( const Ptt__Push__MemberLostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__LostMic_Closure )
 ( const Ptt__Push__LostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CurrentGroup_Closure )
 ( const Ptt__Push__CurrentGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Kickout_Closure )
 ( const Ptt__Push__Kickout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__NewWorksheet_Closure )
 ( const Ptt__Push__NewWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CustomBroadcast_Closure )
 ( const Ptt__Push__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ChangeRoles_Closure )
 ( const Ptt__Push__ChangeRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Invite_Closure )
 ( const Ptt__Push__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ResponseInvite_Closure )
 ( const Ptt__Push__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__TxtBroadcast_Closure )
 ( const Ptt__Serv__TxtBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__MobileStandard_Closure )
 ( const Ptt__Serv__MobileStandard *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__DispatchReconnection_Closure )
 ( const Ptt__Serv__DispatchReconnection *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__Configuration_Closure )
 ( const Ptt__Serv__Configuration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__MultimediaMessage_Closure )
 ( const Ptt__Serv__MultimediaMessage *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__ExternalServMsg_Closure )
 ( const Ptt__Serv__ExternalServMsg *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__User_Closure )
 ( const Ptt__Collect__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Server_Closure )
 ( const Ptt__Collect__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Terminal_Closure )
 ( const Ptt__Collect__Terminal *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__NetWork_Closure )
 ( const Ptt__Collect__NetWork *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__NetDelay_Closure )
 ( const Ptt__Collect__NetDelay *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__GpsCnoInfo_Closure )
 ( const Ptt__Collect__GpsCnoInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__BaseInfo_Closure )
 ( const Ptt__Collect__BaseInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Disconnect_Closure )
 ( const Ptt__Collect__Disconnect *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Reconnect_Closure )
 ( const Ptt__Collect__Reconnect *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__NetStat_Closure )
 ( const Ptt__Collect__NetStat *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Speaker_Closure )
 ( const Ptt__Collect__Speaker *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__Listener_Closure )
 ( const Ptt__Collect__Listener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Collect__SessionStat_Closure )
 ( const Ptt__Collect__SessionStat *message ,
 void *closure_data ) ;
typedef void ( *Terminal__Status__TerminalStatusDetail_Closure )
 ( const Terminal__Status__TerminalStatusDetail *message ,
 void *closure_data ) ;
typedef void ( *Terminal__Status__ReqPrivilegeList_Closure )
 ( const Terminal__Status__ReqPrivilegeList *message ,
 void *closure_data ) ;
typedef void ( *Sos__Alarm_Closure )
 ( const Sos__Alarm *message ,
 void *closure_data ) ;
typedef void ( *Sos__Report_Closure )
 ( const Sos__Report *message ,
 void *closure_data ) ;
typedef void ( *Sos__ReportAck_Closure )
 ( const Sos__ReportAck *message ,
 void *closure_data ) ;
typedef void ( *Sos__Process_Closure )
 ( const Sos__Process *message ,
 void *closure_data ) ;
typedef void ( *Sos__ProcessAck_Closure )
 ( const Sos__ProcessAck *message ,
 void *closure_data ) ;
typedef void ( *Sos__Close_Closure )
 ( const Sos__Close *message ,
 void *closure_data ) ;
typedef void ( *Sos__CloseAck_Closure )
 ( const Sos__CloseAck *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmNew_Closure )
 ( const Sos__AlarmNew *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmProcess_Closure )
 ( const Sos__AlarmProcess *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmClosed_Closure )
 ( const Sos__AlarmClosed *message ,
 void *closure_data ) ;
typedef void ( *Sos__Query_Closure )
 ( const Sos__Query *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmList_Closure )
 ( const Sos__AlarmList *message ,
 void *closure_data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\pinyin.ppp
//PPL Source File Name : src\\pinyin.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef void* hal_mutex_t ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\platform.ppp
//PPL Source File Name : src\\platform.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef void* hal_mutex_t ;
typedef uint32_t hal_time_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
typedef int oem_socket_t ;
typedef void * oem_thread_id_t ;
typedef void* ( *oem_thread_function_t ) ( void* arg ) ;
typedef void* oem_semaphore_t ;
typedef void* oem_mutex_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\post_util.ppp
//PPL Source File Name : src\\post_util.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *pfn_connection_notify ) ( connection_t* connection , CONNECTION_STATUS status , void* user ) ;
typedef void ( *pfn_connection_on_recv_msg_timeout ) ( connection_t* connection , const char* message_name , void* user ) ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Login_Closure )
 ( const Ptt__Rr__Login *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LoginAck_Closure )
 ( const Ptt__Rr__LoginAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Logout_Closure )
 ( const Ptt__Rr__Logout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LogoutAck_Closure )
 ( const Ptt__Rr__LogoutAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroup_Closure )
 ( const Ptt__Rr__QueryGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroupAck_Closure )
 ( const Ptt__Rr__QueryGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroup_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroupAck_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembers_Closure )
 ( const Ptt__Rr__QueryMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck_Closure )
 ( const Ptt__Rr__QueryMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck2_Closure )
 ( const Ptt__Rr__QueryMembersAck2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContacts_Closure )
 ( const Ptt__Rr__QueryContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContactsAck_Closure )
 ( const Ptt__Rr__QueryContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsers_Closure )
 ( const Ptt__Rr__QueryUsers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsersAck_Closure )
 ( const Ptt__Rr__QueryUsersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartments_Closure )
 ( const Ptt__Rr__QueryDepartments *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentsAck_Closure )
 ( const Ptt__Rr__QueryDepartmentsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembers_Closure )
 ( const Ptt__Rr__QueryDepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembersAck_Closure )
 ( const Ptt__Rr__QueryDepartmentMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTree_Closure )
 ( const Ptt__Rr__QueryDepartmentTree *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTreeAck_Closure )
 ( const Ptt__Rr__QueryDepartmentTreeAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroup_Closure )
 ( const Ptt__Rr__JoinGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroupAck_Closure )
 ( const Ptt__Rr__JoinGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroup_Closure )
 ( const Ptt__Rr__WatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupAck_Closure )
 ( const Ptt__Rr__WatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ByeGroup_Closure )
 ( const Ptt__Rr__ByeGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__IgnoreTalk_Closure )
 ( const Ptt__Rr__IgnoreTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ContinueTalk_Closure )
 ( const Ptt__Rr__ContinueTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dnd_Closure )
 ( const Ptt__Rr__Dnd *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroup_Closure )
 ( const Ptt__Rr__LeaveGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroupAck_Closure )
 ( const Ptt__Rr__LeaveGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMic_Closure )
 ( const Ptt__Rr__RequestMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMicAck_Closure )
 ( const Ptt__Rr__RequestMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMic_Closure )
 ( const Ptt__Rr__ReleaseMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMicAck_Closure )
 ( const Ptt__Rr__ReleaseMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Call_Closure )
 ( const Ptt__Rr__Call *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CallAck_Closure )
 ( const Ptt__Rr__CallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCall_Closure )
 ( const Ptt__Rr__SingleCall *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCallAck_Closure )
 ( const Ptt__Rr__SingleCallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDial_Closure )
 ( const Ptt__Rr__QuickDial *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDialAck_Closure )
 ( const Ptt__Rr__QuickDialAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeName_Closure )
 ( const Ptt__Rr__ChangeName *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeNameAck_Closure )
 ( const Ptt__Rr__ChangeNameAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePassword_Closure )
 ( const Ptt__Rr__ChangePassword *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePasswordAck_Closure )
 ( const Ptt__Rr__ChangePasswordAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContacts_Closure )
 ( const Ptt__Rr__MakeContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsAck_Closure )
 ( const Ptt__Rr__MakeContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponse_Closure )
 ( const Ptt__Rr__MakeContactsResponse *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponseAck_Closure )
 ( const Ptt__Rr__MakeContactsResponseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContacts_Closure )
 ( const Ptt__Rr__RemoveContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContactsAck_Closure )
 ( const Ptt__Rr__RemoveContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocation_Closure )
 ( const Ptt__Rr__ReportLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocationAck_Closure )
 ( const Ptt__Rr__ReportLocationAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroup_Closure )
 ( const Ptt__Rr__CreateGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroupAck_Closure )
 ( const Ptt__Rr__CreateGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroup_Closure )
 ( const Ptt__Rr__DeleteGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroupAck_Closure )
 ( const Ptt__Rr__DeleteGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroup_Closure )
 ( const Ptt__Rr__ModifyGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroupAck_Closure )
 ( const Ptt__Rr__ModifyGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembership_Closure )
 ( const Ptt__Rr__EmpowerMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembershipAck_Closure )
 ( const Ptt__Rr__EmpowerMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembership_Closure )
 ( const Ptt__Rr__DepriveMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembershipAck_Closure )
 ( const Ptt__Rr__DepriveMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dispatch_Closure )
 ( const Ptt__Rr__Dispatch *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DispatchAck_Closure )
 ( const Ptt__Rr__DispatchAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUser_Closure )
 ( const Ptt__Rr__ConfigureUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUserAck_Closure )
 ( const Ptt__Rr__ConfigureUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMic_Closure )
 ( const Ptt__Rr__TakeMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMicAck_Closure )
 ( const Ptt__Rr__TakeMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabase_Closure )
 ( const Ptt__Rr__SynchDatabase *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabaseAck_Closure )
 ( const Ptt__Rr__SynchDatabaseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheet_Closure )
 ( const Ptt__Rr__PostWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheetAck_Closure )
 ( const Ptt__Rr__PostWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheet_Closure )
 ( const Ptt__Rr__ResponseWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheetAck_Closure )
 ( const Ptt__Rr__ResponseWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServer_Closure )
 ( const Ptt__Rr__QueryServer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServerAck_Closure )
 ( const Ptt__Rr__QueryServerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigure_Closure )
 ( const Ptt__Rr__RequestConfigure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigureAck_Closure )
 ( const Ptt__Rr__RequestConfigureAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivate_Closure )
 ( const Ptt__Rr__RequestActivate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivateAck_Closure )
 ( const Ptt__Rr__RequestActivateAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcast_Closure )
 ( const Ptt__Rr__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcastAck_Closure )
 ( const Ptt__Rr__CustomBroadcastAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRoles_Closure )
 ( const Ptt__Rr__ChangeUserRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRolesAck_Closure )
 ( const Ptt__Rr__ChangeUserRolesAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroup_Closure )
 ( const Ptt__Rr__GetWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroupAck_Closure )
 ( const Ptt__Rr__GetWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroup_Closure )
 ( const Ptt__Rr__AddWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroupAck_Closure )
 ( const Ptt__Rr__AddWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroup_Closure )
 ( const Ptt__Rr__RemoveWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroupAck_Closure )
 ( const Ptt__Rr__RemoveWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupEx_Closure )
 ( const Ptt__Rr__WatchGroupEx *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupExAck_Closure )
 ( const Ptt__Rr__WatchGroupExAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Invite_Closure )
 ( const Ptt__Rr__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__InviteAck_Closure )
 ( const Ptt__Rr__InviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInvite_Closure )
 ( const Ptt__Rr__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInviteAck_Closure )
 ( const Ptt__Rr__ResponseInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInvite_Closure )
 ( const Ptt__Rr__CancelInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInviteAck_Closure )
 ( const Ptt__Rr__CancelInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncrypt_Closure )
 ( const Ptt__Rr__SetEncrypt *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncryptAck_Closure )
 ( const Ptt__Rr__SetEncryptAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUser_Closure )
 ( const Ptt__Rr__ListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUserAck_Closure )
 ( const Ptt__Rr__ListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUser_Closure )
 ( const Ptt__Rr__UnListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUserAck_Closure )
 ( const Ptt__Rr__UnListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListener_Closure )
 ( const Ptt__Rr__QueryListener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListenerAck_Closure )
 ( const Ptt__Rr__QueryListenerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Deliver_Closure )
 ( const Ptt__Rr__Deliver *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeliverAck_Closure )
 ( const Ptt__Rr__DeliverAck *message ,
 void *closure_data ) ;
typedef void ( *Terminal__Status__TerminalStatusDetail_Closure )
 ( const Terminal__Status__TerminalStatusDetail *message ,
 void *closure_data ) ;
typedef void ( *Terminal__Status__ReqPrivilegeList_Closure )
 ( const Terminal__Status__ReqPrivilegeList *message ,
 void *closure_data ) ;
typedef void ( *Sos__Alarm_Closure )
 ( const Sos__Alarm *message ,
 void *closure_data ) ;
typedef void ( *Sos__Report_Closure )
 ( const Sos__Report *message ,
 void *closure_data ) ;
typedef void ( *Sos__ReportAck_Closure )
 ( const Sos__ReportAck *message ,
 void *closure_data ) ;
typedef void ( *Sos__Process_Closure )
 ( const Sos__Process *message ,
 void *closure_data ) ;
typedef void ( *Sos__ProcessAck_Closure )
 ( const Sos__ProcessAck *message ,
 void *closure_data ) ;
typedef void ( *Sos__Close_Closure )
 ( const Sos__Close *message ,
 void *closure_data ) ;
typedef void ( *Sos__CloseAck_Closure )
 ( const Sos__CloseAck *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmNew_Closure )
 ( const Sos__AlarmNew *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmProcess_Closure )
 ( const Sos__AlarmProcess *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmClosed_Closure )
 ( const Sos__AlarmClosed *message ,
 void *closure_data ) ;
typedef void ( *Sos__Query_Closure )
 ( const Sos__Query *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmList_Closure )
 ( const Sos__AlarmList *message ,
 void *closure_data ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\protobuf-c.ppp
//PPL Source File Name : src\\protobuf-c.c
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *GenericHandler ) ( void *service ,
 const ProtobufCMessage *input ,
 ProtobufCClosure closure ,
 void *closure_data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\ptt.pb-c.ppp
//PPL Source File Name : src\\ptt.pb-c.c
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\push.pb-c.ppp
//PPL Source File Name : src\\push.pb-c.c
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Reconfigured_Closure )
 ( const Ptt__Push__Reconfigured *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__UsersChanged_Closure )
 ( const Ptt__Push__UsersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__GroupListChanged_Closure )
 ( const Ptt__Push__GroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__WatchGroupListChanged_Closure )
 ( const Ptt__Push__WatchGroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged__MemberChanged_Closure )
 ( const Ptt__Push__MembersChanged__MemberChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged_Closure )
 ( const Ptt__Push__MembersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked__Request_Closure )
 ( const Ptt__Push__ContactshipAsked__Request *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked_Closure )
 ( const Ptt__Push__ContactshipAsked *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactsChanged_Closure )
 ( const Ptt__Push__ContactsChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberGetMic_Closure )
 ( const Ptt__Push__MemberGetMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberLostMic_Closure )
 ( const Ptt__Push__MemberLostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__LostMic_Closure )
 ( const Ptt__Push__LostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CurrentGroup_Closure )
 ( const Ptt__Push__CurrentGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Kickout_Closure )
 ( const Ptt__Push__Kickout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__NewWorksheet_Closure )
 ( const Ptt__Push__NewWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CustomBroadcast_Closure )
 ( const Ptt__Push__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ChangeRoles_Closure )
 ( const Ptt__Push__ChangeRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Invite_Closure )
 ( const Ptt__Push__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ResponseInvite_Closure )
 ( const Ptt__Push__ResponseInvite *message ,
 void *closure_data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\queuebuf.ppp
//PPL Source File Name : src\\queuebuf.c
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\recorder.ppp
//PPL Source File Name : src\\recorder.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef void* hal_mutex_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\recorder_audio.ppp
//PPL Source File Name : src\\recorder_audio.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef VO_S32 ( * VOAUDIOCALLBACKPROC ) ( VO_PTR pUserData , VO_CODECBUFFER * pAudioBuffer , VO_AUDIO_FORMAT * pAudioFormat , VO_S32 nStart ) ;
typedef void ( *pfn_focus_notify ) ( focus_manager_t* fm , void* requestor , boolean focus ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\recorder_c2c.ppp
//PPL Source File Name : src\\recorder_c2c.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef VO_S32 ( * VOAUDIOCALLBACKPROC ) ( VO_PTR pUserData , VO_CODECBUFFER * pAudioBuffer , VO_AUDIO_FORMAT * pAudioFormat , VO_S32 nStart ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\ringbuffer.ppp
//PPL Source File Name : src\\ringbuffer.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\rr.pb-c.ppp
//PPL Source File Name : src\\rr.pb-c.c
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Login_Closure )
 ( const Ptt__Rr__Login *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LoginAck_Closure )
 ( const Ptt__Rr__LoginAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Logout_Closure )
 ( const Ptt__Rr__Logout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LogoutAck_Closure )
 ( const Ptt__Rr__LogoutAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroup_Closure )
 ( const Ptt__Rr__QueryGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroupAck_Closure )
 ( const Ptt__Rr__QueryGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroup_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroupAck_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembers_Closure )
 ( const Ptt__Rr__QueryMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck_Closure )
 ( const Ptt__Rr__QueryMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck2_Closure )
 ( const Ptt__Rr__QueryMembersAck2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContacts_Closure )
 ( const Ptt__Rr__QueryContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContactsAck_Closure )
 ( const Ptt__Rr__QueryContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsers_Closure )
 ( const Ptt__Rr__QueryUsers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsersAck_Closure )
 ( const Ptt__Rr__QueryUsersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartments_Closure )
 ( const Ptt__Rr__QueryDepartments *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentsAck_Closure )
 ( const Ptt__Rr__QueryDepartmentsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembers_Closure )
 ( const Ptt__Rr__QueryDepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembersAck_Closure )
 ( const Ptt__Rr__QueryDepartmentMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTree_Closure )
 ( const Ptt__Rr__QueryDepartmentTree *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTreeAck_Closure )
 ( const Ptt__Rr__QueryDepartmentTreeAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroup_Closure )
 ( const Ptt__Rr__JoinGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroupAck_Closure )
 ( const Ptt__Rr__JoinGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroup_Closure )
 ( const Ptt__Rr__WatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupAck_Closure )
 ( const Ptt__Rr__WatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ByeGroup_Closure )
 ( const Ptt__Rr__ByeGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__IgnoreTalk_Closure )
 ( const Ptt__Rr__IgnoreTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ContinueTalk_Closure )
 ( const Ptt__Rr__ContinueTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dnd_Closure )
 ( const Ptt__Rr__Dnd *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroup_Closure )
 ( const Ptt__Rr__LeaveGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroupAck_Closure )
 ( const Ptt__Rr__LeaveGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMic_Closure )
 ( const Ptt__Rr__RequestMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMicAck_Closure )
 ( const Ptt__Rr__RequestMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMic_Closure )
 ( const Ptt__Rr__ReleaseMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMicAck_Closure )
 ( const Ptt__Rr__ReleaseMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Call_Closure )
 ( const Ptt__Rr__Call *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CallAck_Closure )
 ( const Ptt__Rr__CallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCall_Closure )
 ( const Ptt__Rr__SingleCall *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCallAck_Closure )
 ( const Ptt__Rr__SingleCallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDial_Closure )
 ( const Ptt__Rr__QuickDial *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDialAck_Closure )
 ( const Ptt__Rr__QuickDialAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeName_Closure )
 ( const Ptt__Rr__ChangeName *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeNameAck_Closure )
 ( const Ptt__Rr__ChangeNameAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePassword_Closure )
 ( const Ptt__Rr__ChangePassword *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePasswordAck_Closure )
 ( const Ptt__Rr__ChangePasswordAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContacts_Closure )
 ( const Ptt__Rr__MakeContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsAck_Closure )
 ( const Ptt__Rr__MakeContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponse_Closure )
 ( const Ptt__Rr__MakeContactsResponse *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponseAck_Closure )
 ( const Ptt__Rr__MakeContactsResponseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContacts_Closure )
 ( const Ptt__Rr__RemoveContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContactsAck_Closure )
 ( const Ptt__Rr__RemoveContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocation_Closure )
 ( const Ptt__Rr__ReportLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocationAck_Closure )
 ( const Ptt__Rr__ReportLocationAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroup_Closure )
 ( const Ptt__Rr__CreateGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroupAck_Closure )
 ( const Ptt__Rr__CreateGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroup_Closure )
 ( const Ptt__Rr__DeleteGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroupAck_Closure )
 ( const Ptt__Rr__DeleteGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroup_Closure )
 ( const Ptt__Rr__ModifyGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroupAck_Closure )
 ( const Ptt__Rr__ModifyGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembership_Closure )
 ( const Ptt__Rr__EmpowerMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembershipAck_Closure )
 ( const Ptt__Rr__EmpowerMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembership_Closure )
 ( const Ptt__Rr__DepriveMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembershipAck_Closure )
 ( const Ptt__Rr__DepriveMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dispatch_Closure )
 ( const Ptt__Rr__Dispatch *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DispatchAck_Closure )
 ( const Ptt__Rr__DispatchAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUser_Closure )
 ( const Ptt__Rr__ConfigureUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUserAck_Closure )
 ( const Ptt__Rr__ConfigureUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMic_Closure )
 ( const Ptt__Rr__TakeMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMicAck_Closure )
 ( const Ptt__Rr__TakeMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabase_Closure )
 ( const Ptt__Rr__SynchDatabase *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabaseAck_Closure )
 ( const Ptt__Rr__SynchDatabaseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheet_Closure )
 ( const Ptt__Rr__PostWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheetAck_Closure )
 ( const Ptt__Rr__PostWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheet_Closure )
 ( const Ptt__Rr__ResponseWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheetAck_Closure )
 ( const Ptt__Rr__ResponseWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServer_Closure )
 ( const Ptt__Rr__QueryServer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServerAck_Closure )
 ( const Ptt__Rr__QueryServerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigure_Closure )
 ( const Ptt__Rr__RequestConfigure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigureAck_Closure )
 ( const Ptt__Rr__RequestConfigureAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivate_Closure )
 ( const Ptt__Rr__RequestActivate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivateAck_Closure )
 ( const Ptt__Rr__RequestActivateAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcast_Closure )
 ( const Ptt__Rr__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcastAck_Closure )
 ( const Ptt__Rr__CustomBroadcastAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRoles_Closure )
 ( const Ptt__Rr__ChangeUserRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRolesAck_Closure )
 ( const Ptt__Rr__ChangeUserRolesAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroup_Closure )
 ( const Ptt__Rr__GetWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroupAck_Closure )
 ( const Ptt__Rr__GetWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroup_Closure )
 ( const Ptt__Rr__AddWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroupAck_Closure )
 ( const Ptt__Rr__AddWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroup_Closure )
 ( const Ptt__Rr__RemoveWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroupAck_Closure )
 ( const Ptt__Rr__RemoveWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupEx_Closure )
 ( const Ptt__Rr__WatchGroupEx *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupExAck_Closure )
 ( const Ptt__Rr__WatchGroupExAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Invite_Closure )
 ( const Ptt__Rr__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__InviteAck_Closure )
 ( const Ptt__Rr__InviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInvite_Closure )
 ( const Ptt__Rr__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInviteAck_Closure )
 ( const Ptt__Rr__ResponseInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInvite_Closure )
 ( const Ptt__Rr__CancelInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInviteAck_Closure )
 ( const Ptt__Rr__CancelInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncrypt_Closure )
 ( const Ptt__Rr__SetEncrypt *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncryptAck_Closure )
 ( const Ptt__Rr__SetEncryptAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUser_Closure )
 ( const Ptt__Rr__ListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUserAck_Closure )
 ( const Ptt__Rr__ListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUser_Closure )
 ( const Ptt__Rr__UnListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUserAck_Closure )
 ( const Ptt__Rr__UnListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListener_Closure )
 ( const Ptt__Rr__QueryListener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListenerAck_Closure )
 ( const Ptt__Rr__QueryListenerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Deliver_Closure )
 ( const Ptt__Rr__Deliver *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeliverAck_Closure )
 ( const Ptt__Rr__DeliverAck *message ,
 void *closure_data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\rtpistream.ppp
//PPL Source File Name : src\\rtpistream.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_rtp_istream_notify ) ( rtp_istream_t* rtpis , RTP_ISTREAM_EVENT event , void* user ) ;
typedef int16_t spx_int16_t ;
typedef uint16_t spx_uint16_t ;
typedef int32_t spx_int32_t ;
typedef uint32_t spx_uint32_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef union {
 dwsplit_t split ;
 uint32_t one ;
 } poly32_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\rtpostream.ppp
//PPL Source File Name : src\\rtpostream.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *pfn_rtp_ostream_notify ) ( rtp_ostream_t* rtpos , RTP_OSTREAM_EVENT event , void* user ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef union {
 dwsplit_t split ;
 uint32_t one ;
 } poly32_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\rtpstream_d.ppp
//PPL Source File Name : src\\rtpstream_d.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef union {
 dwsplit_t split ;
 uint32_t one ;
 } poly32_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\serv.pb-c.ppp
//PPL Source File Name : src\\serv.pb-c.c
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *Ptt__Serv__TxtBroadcast_Closure )
 ( const Ptt__Serv__TxtBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__MobileStandard_Closure )
 ( const Ptt__Serv__MobileStandard *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__DispatchReconnection_Closure )
 ( const Ptt__Serv__DispatchReconnection *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__Configuration_Closure )
 ( const Ptt__Serv__Configuration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__MultimediaMessage_Closure )
 ( const Ptt__Serv__MultimediaMessage *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Serv__ExternalServMsg_Closure )
 ( const Ptt__Serv__ExternalServMsg *message ,
 void *closure_data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\session.ppp
//PPL Source File Name : src\\session.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *pfn_connection_notify ) ( connection_t* connection , CONNECTION_STATUS status , void* user ) ;
typedef void ( *pfn_connection_on_recv_msg_timeout ) ( connection_t* connection , const char* message_name , void* user ) ;
typedef void ( *pfn_registerprocess_cb ) ( const ProtobufCMessage* message , void* user ) ;
typedef void ( *pfn_rtp_istream_notify ) ( rtp_istream_t* rtpis , RTP_ISTREAM_EVENT event , void* user ) ;
typedef void ( *pfn_rtp_ostream_notify ) ( rtp_ostream_t* rtpos , RTP_OSTREAM_EVENT event , void* user ) ;
typedef void ( *pfn_focus_notify ) ( focus_manager_t* fm , void* requestor , boolean focus ) ;
typedef void ( *Ptt__Net__HeartBeat_Closure )
 ( const Ptt__Net__HeartBeat *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Net__Ping_Closure )
 ( const Ptt__Net__Ping *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Net__Pong_Closure )
 ( const Ptt__Net__Pong *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Login_Closure )
 ( const Ptt__Rr__Login *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LoginAck_Closure )
 ( const Ptt__Rr__LoginAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Logout_Closure )
 ( const Ptt__Rr__Logout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LogoutAck_Closure )
 ( const Ptt__Rr__LogoutAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroup_Closure )
 ( const Ptt__Rr__QueryGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroupAck_Closure )
 ( const Ptt__Rr__QueryGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroup_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroupAck_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembers_Closure )
 ( const Ptt__Rr__QueryMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck_Closure )
 ( const Ptt__Rr__QueryMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck2_Closure )
 ( const Ptt__Rr__QueryMembersAck2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContacts_Closure )
 ( const Ptt__Rr__QueryContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContactsAck_Closure )
 ( const Ptt__Rr__QueryContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsers_Closure )
 ( const Ptt__Rr__QueryUsers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsersAck_Closure )
 ( const Ptt__Rr__QueryUsersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartments_Closure )
 ( const Ptt__Rr__QueryDepartments *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentsAck_Closure )
 ( const Ptt__Rr__QueryDepartmentsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembers_Closure )
 ( const Ptt__Rr__QueryDepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembersAck_Closure )
 ( const Ptt__Rr__QueryDepartmentMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTree_Closure )
 ( const Ptt__Rr__QueryDepartmentTree *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTreeAck_Closure )
 ( const Ptt__Rr__QueryDepartmentTreeAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroup_Closure )
 ( const Ptt__Rr__JoinGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroupAck_Closure )
 ( const Ptt__Rr__JoinGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroup_Closure )
 ( const Ptt__Rr__WatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupAck_Closure )
 ( const Ptt__Rr__WatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ByeGroup_Closure )
 ( const Ptt__Rr__ByeGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__IgnoreTalk_Closure )
 ( const Ptt__Rr__IgnoreTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ContinueTalk_Closure )
 ( const Ptt__Rr__ContinueTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dnd_Closure )
 ( const Ptt__Rr__Dnd *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroup_Closure )
 ( const Ptt__Rr__LeaveGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroupAck_Closure )
 ( const Ptt__Rr__LeaveGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMic_Closure )
 ( const Ptt__Rr__RequestMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMicAck_Closure )
 ( const Ptt__Rr__RequestMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMic_Closure )
 ( const Ptt__Rr__ReleaseMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMicAck_Closure )
 ( const Ptt__Rr__ReleaseMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Call_Closure )
 ( const Ptt__Rr__Call *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CallAck_Closure )
 ( const Ptt__Rr__CallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCall_Closure )
 ( const Ptt__Rr__SingleCall *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCallAck_Closure )
 ( const Ptt__Rr__SingleCallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDial_Closure )
 ( const Ptt__Rr__QuickDial *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDialAck_Closure )
 ( const Ptt__Rr__QuickDialAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeName_Closure )
 ( const Ptt__Rr__ChangeName *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeNameAck_Closure )
 ( const Ptt__Rr__ChangeNameAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePassword_Closure )
 ( const Ptt__Rr__ChangePassword *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePasswordAck_Closure )
 ( const Ptt__Rr__ChangePasswordAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContacts_Closure )
 ( const Ptt__Rr__MakeContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsAck_Closure )
 ( const Ptt__Rr__MakeContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponse_Closure )
 ( const Ptt__Rr__MakeContactsResponse *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponseAck_Closure )
 ( const Ptt__Rr__MakeContactsResponseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContacts_Closure )
 ( const Ptt__Rr__RemoveContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContactsAck_Closure )
 ( const Ptt__Rr__RemoveContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocation_Closure )
 ( const Ptt__Rr__ReportLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocationAck_Closure )
 ( const Ptt__Rr__ReportLocationAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroup_Closure )
 ( const Ptt__Rr__CreateGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroupAck_Closure )
 ( const Ptt__Rr__CreateGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroup_Closure )
 ( const Ptt__Rr__DeleteGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroupAck_Closure )
 ( const Ptt__Rr__DeleteGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroup_Closure )
 ( const Ptt__Rr__ModifyGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroupAck_Closure )
 ( const Ptt__Rr__ModifyGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembership_Closure )
 ( const Ptt__Rr__EmpowerMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembershipAck_Closure )
 ( const Ptt__Rr__EmpowerMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembership_Closure )
 ( const Ptt__Rr__DepriveMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembershipAck_Closure )
 ( const Ptt__Rr__DepriveMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dispatch_Closure )
 ( const Ptt__Rr__Dispatch *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DispatchAck_Closure )
 ( const Ptt__Rr__DispatchAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUser_Closure )
 ( const Ptt__Rr__ConfigureUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUserAck_Closure )
 ( const Ptt__Rr__ConfigureUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMic_Closure )
 ( const Ptt__Rr__TakeMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMicAck_Closure )
 ( const Ptt__Rr__TakeMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabase_Closure )
 ( const Ptt__Rr__SynchDatabase *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabaseAck_Closure )
 ( const Ptt__Rr__SynchDatabaseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheet_Closure )
 ( const Ptt__Rr__PostWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheetAck_Closure )
 ( const Ptt__Rr__PostWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheet_Closure )
 ( const Ptt__Rr__ResponseWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheetAck_Closure )
 ( const Ptt__Rr__ResponseWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServer_Closure )
 ( const Ptt__Rr__QueryServer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServerAck_Closure )
 ( const Ptt__Rr__QueryServerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigure_Closure )
 ( const Ptt__Rr__RequestConfigure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigureAck_Closure )
 ( const Ptt__Rr__RequestConfigureAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivate_Closure )
 ( const Ptt__Rr__RequestActivate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivateAck_Closure )
 ( const Ptt__Rr__RequestActivateAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcast_Closure )
 ( const Ptt__Rr__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcastAck_Closure )
 ( const Ptt__Rr__CustomBroadcastAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRoles_Closure )
 ( const Ptt__Rr__ChangeUserRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRolesAck_Closure )
 ( const Ptt__Rr__ChangeUserRolesAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroup_Closure )
 ( const Ptt__Rr__GetWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroupAck_Closure )
 ( const Ptt__Rr__GetWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroup_Closure )
 ( const Ptt__Rr__AddWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroupAck_Closure )
 ( const Ptt__Rr__AddWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroup_Closure )
 ( const Ptt__Rr__RemoveWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroupAck_Closure )
 ( const Ptt__Rr__RemoveWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupEx_Closure )
 ( const Ptt__Rr__WatchGroupEx *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupExAck_Closure )
 ( const Ptt__Rr__WatchGroupExAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Invite_Closure )
 ( const Ptt__Rr__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__InviteAck_Closure )
 ( const Ptt__Rr__InviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInvite_Closure )
 ( const Ptt__Rr__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInviteAck_Closure )
 ( const Ptt__Rr__ResponseInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInvite_Closure )
 ( const Ptt__Rr__CancelInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInviteAck_Closure )
 ( const Ptt__Rr__CancelInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncrypt_Closure )
 ( const Ptt__Rr__SetEncrypt *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncryptAck_Closure )
 ( const Ptt__Rr__SetEncryptAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUser_Closure )
 ( const Ptt__Rr__ListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUserAck_Closure )
 ( const Ptt__Rr__ListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUser_Closure )
 ( const Ptt__Rr__UnListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUserAck_Closure )
 ( const Ptt__Rr__UnListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListener_Closure )
 ( const Ptt__Rr__QueryListener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListenerAck_Closure )
 ( const Ptt__Rr__QueryListenerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Deliver_Closure )
 ( const Ptt__Rr__Deliver *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeliverAck_Closure )
 ( const Ptt__Rr__DeliverAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Reconfigured_Closure )
 ( const Ptt__Push__Reconfigured *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__UsersChanged_Closure )
 ( const Ptt__Push__UsersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__GroupListChanged_Closure )
 ( const Ptt__Push__GroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__WatchGroupListChanged_Closure )
 ( const Ptt__Push__WatchGroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged__MemberChanged_Closure )
 ( const Ptt__Push__MembersChanged__MemberChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged_Closure )
 ( const Ptt__Push__MembersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked__Request_Closure )
 ( const Ptt__Push__ContactshipAsked__Request *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked_Closure )
 ( const Ptt__Push__ContactshipAsked *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactsChanged_Closure )
 ( const Ptt__Push__ContactsChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberGetMic_Closure )
 ( const Ptt__Push__MemberGetMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberLostMic_Closure )
 ( const Ptt__Push__MemberLostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__LostMic_Closure )
 ( const Ptt__Push__LostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CurrentGroup_Closure )
 ( const Ptt__Push__CurrentGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Kickout_Closure )
 ( const Ptt__Push__Kickout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__NewWorksheet_Closure )
 ( const Ptt__Push__NewWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CustomBroadcast_Closure )
 ( const Ptt__Push__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ChangeRoles_Closure )
 ( const Ptt__Push__ChangeRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Invite_Closure )
 ( const Ptt__Push__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ResponseInvite_Closure )
 ( const Ptt__Push__ResponseInvite *message ,
 void *closure_data ) ;
typedef unsigned int size_t ;
typedef int ( *pfn_session_transaction ) ( session_t* self , SESSION_STATUS status , SESSION_SIGNAL sig ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\sessionset.ppp
//PPL Source File Name : src\\sessionset.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *pfn_connection_notify ) ( connection_t* connection , CONNECTION_STATUS status , void* user ) ;
typedef void ( *pfn_connection_on_recv_msg_timeout ) ( connection_t* connection , const char* message_name , void* user ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef void ( *pfn_registerprocess_cb ) ( const ProtobufCMessage* message , void* user ) ;
typedef void ( *pfn_network_notify ) ( void* user , boolean succ ) ;
typedef void ( *pfn_sock_notify ) ( hal_sock_t* sock , void* user , int error ) ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Login_Closure )
 ( const Ptt__Rr__Login *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LoginAck_Closure )
 ( const Ptt__Rr__LoginAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Logout_Closure )
 ( const Ptt__Rr__Logout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LogoutAck_Closure )
 ( const Ptt__Rr__LogoutAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroup_Closure )
 ( const Ptt__Rr__QueryGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryGroupAck_Closure )
 ( const Ptt__Rr__QueryGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroup_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryEnterpriseGroupAck_Closure )
 ( const Ptt__Rr__QueryEnterpriseGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembers_Closure )
 ( const Ptt__Rr__QueryMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck_Closure )
 ( const Ptt__Rr__QueryMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryMembersAck2_Closure )
 ( const Ptt__Rr__QueryMembersAck2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContacts_Closure )
 ( const Ptt__Rr__QueryContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryContactsAck_Closure )
 ( const Ptt__Rr__QueryContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsers_Closure )
 ( const Ptt__Rr__QueryUsers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryUsersAck_Closure )
 ( const Ptt__Rr__QueryUsersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartments_Closure )
 ( const Ptt__Rr__QueryDepartments *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentsAck_Closure )
 ( const Ptt__Rr__QueryDepartmentsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembers_Closure )
 ( const Ptt__Rr__QueryDepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentMembersAck_Closure )
 ( const Ptt__Rr__QueryDepartmentMembersAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTree_Closure )
 ( const Ptt__Rr__QueryDepartmentTree *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryDepartmentTreeAck_Closure )
 ( const Ptt__Rr__QueryDepartmentTreeAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroup_Closure )
 ( const Ptt__Rr__JoinGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__JoinGroupAck_Closure )
 ( const Ptt__Rr__JoinGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroup_Closure )
 ( const Ptt__Rr__WatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupAck_Closure )
 ( const Ptt__Rr__WatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ByeGroup_Closure )
 ( const Ptt__Rr__ByeGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__IgnoreTalk_Closure )
 ( const Ptt__Rr__IgnoreTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ContinueTalk_Closure )
 ( const Ptt__Rr__ContinueTalk *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dnd_Closure )
 ( const Ptt__Rr__Dnd *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroup_Closure )
 ( const Ptt__Rr__LeaveGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__LeaveGroupAck_Closure )
 ( const Ptt__Rr__LeaveGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMic_Closure )
 ( const Ptt__Rr__RequestMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestMicAck_Closure )
 ( const Ptt__Rr__RequestMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMic_Closure )
 ( const Ptt__Rr__ReleaseMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReleaseMicAck_Closure )
 ( const Ptt__Rr__ReleaseMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Call_Closure )
 ( const Ptt__Rr__Call *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CallAck_Closure )
 ( const Ptt__Rr__CallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCall_Closure )
 ( const Ptt__Rr__SingleCall *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SingleCallAck_Closure )
 ( const Ptt__Rr__SingleCallAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDial_Closure )
 ( const Ptt__Rr__QuickDial *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QuickDialAck_Closure )
 ( const Ptt__Rr__QuickDialAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeName_Closure )
 ( const Ptt__Rr__ChangeName *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeNameAck_Closure )
 ( const Ptt__Rr__ChangeNameAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePassword_Closure )
 ( const Ptt__Rr__ChangePassword *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangePasswordAck_Closure )
 ( const Ptt__Rr__ChangePasswordAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContacts_Closure )
 ( const Ptt__Rr__MakeContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsAck_Closure )
 ( const Ptt__Rr__MakeContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponse_Closure )
 ( const Ptt__Rr__MakeContactsResponse *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__MakeContactsResponseAck_Closure )
 ( const Ptt__Rr__MakeContactsResponseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContacts_Closure )
 ( const Ptt__Rr__RemoveContacts *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveContactsAck_Closure )
 ( const Ptt__Rr__RemoveContactsAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocation_Closure )
 ( const Ptt__Rr__ReportLocation *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ReportLocationAck_Closure )
 ( const Ptt__Rr__ReportLocationAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroup_Closure )
 ( const Ptt__Rr__CreateGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CreateGroupAck_Closure )
 ( const Ptt__Rr__CreateGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroup_Closure )
 ( const Ptt__Rr__DeleteGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeleteGroupAck_Closure )
 ( const Ptt__Rr__DeleteGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroup_Closure )
 ( const Ptt__Rr__ModifyGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ModifyGroupAck_Closure )
 ( const Ptt__Rr__ModifyGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembership_Closure )
 ( const Ptt__Rr__EmpowerMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__EmpowerMembershipAck_Closure )
 ( const Ptt__Rr__EmpowerMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembership_Closure )
 ( const Ptt__Rr__DepriveMembership *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DepriveMembershipAck_Closure )
 ( const Ptt__Rr__DepriveMembershipAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Dispatch_Closure )
 ( const Ptt__Rr__Dispatch *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DispatchAck_Closure )
 ( const Ptt__Rr__DispatchAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUser_Closure )
 ( const Ptt__Rr__ConfigureUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ConfigureUserAck_Closure )
 ( const Ptt__Rr__ConfigureUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMic_Closure )
 ( const Ptt__Rr__TakeMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__TakeMicAck_Closure )
 ( const Ptt__Rr__TakeMicAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabase_Closure )
 ( const Ptt__Rr__SynchDatabase *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SynchDatabaseAck_Closure )
 ( const Ptt__Rr__SynchDatabaseAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheet_Closure )
 ( const Ptt__Rr__PostWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__PostWorksheetAck_Closure )
 ( const Ptt__Rr__PostWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheet_Closure )
 ( const Ptt__Rr__ResponseWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseWorksheetAck_Closure )
 ( const Ptt__Rr__ResponseWorksheetAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServer_Closure )
 ( const Ptt__Rr__QueryServer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryServerAck_Closure )
 ( const Ptt__Rr__QueryServerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigure_Closure )
 ( const Ptt__Rr__RequestConfigure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestConfigureAck_Closure )
 ( const Ptt__Rr__RequestConfigureAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivate_Closure )
 ( const Ptt__Rr__RequestActivate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RequestActivateAck_Closure )
 ( const Ptt__Rr__RequestActivateAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcast_Closure )
 ( const Ptt__Rr__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CustomBroadcastAck_Closure )
 ( const Ptt__Rr__CustomBroadcastAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRoles_Closure )
 ( const Ptt__Rr__ChangeUserRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ChangeUserRolesAck_Closure )
 ( const Ptt__Rr__ChangeUserRolesAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroup_Closure )
 ( const Ptt__Rr__GetWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__GetWatchGroupAck_Closure )
 ( const Ptt__Rr__GetWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroup_Closure )
 ( const Ptt__Rr__AddWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__AddWatchGroupAck_Closure )
 ( const Ptt__Rr__AddWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroup_Closure )
 ( const Ptt__Rr__RemoveWatchGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__RemoveWatchGroupAck_Closure )
 ( const Ptt__Rr__RemoveWatchGroupAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupEx_Closure )
 ( const Ptt__Rr__WatchGroupEx *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__WatchGroupExAck_Closure )
 ( const Ptt__Rr__WatchGroupExAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Invite_Closure )
 ( const Ptt__Rr__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__InviteAck_Closure )
 ( const Ptt__Rr__InviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInvite_Closure )
 ( const Ptt__Rr__ResponseInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ResponseInviteAck_Closure )
 ( const Ptt__Rr__ResponseInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInvite_Closure )
 ( const Ptt__Rr__CancelInvite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__CancelInviteAck_Closure )
 ( const Ptt__Rr__CancelInviteAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncrypt_Closure )
 ( const Ptt__Rr__SetEncrypt *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__SetEncryptAck_Closure )
 ( const Ptt__Rr__SetEncryptAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUser_Closure )
 ( const Ptt__Rr__ListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__ListenUserAck_Closure )
 ( const Ptt__Rr__ListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUser_Closure )
 ( const Ptt__Rr__UnListenUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__UnListenUserAck_Closure )
 ( const Ptt__Rr__UnListenUserAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListener_Closure )
 ( const Ptt__Rr__QueryListener *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__QueryListenerAck_Closure )
 ( const Ptt__Rr__QueryListenerAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__Deliver_Closure )
 ( const Ptt__Rr__Deliver *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Rr__DeliverAck_Closure )
 ( const Ptt__Rr__DeliverAck *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Reconfigured_Closure )
 ( const Ptt__Push__Reconfigured *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__UsersChanged_Closure )
 ( const Ptt__Push__UsersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__GroupListChanged_Closure )
 ( const Ptt__Push__GroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__WatchGroupListChanged_Closure )
 ( const Ptt__Push__WatchGroupListChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged__MemberChanged_Closure )
 ( const Ptt__Push__MembersChanged__MemberChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MembersChanged_Closure )
 ( const Ptt__Push__MembersChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked__Request_Closure )
 ( const Ptt__Push__ContactshipAsked__Request *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactshipAsked_Closure )
 ( const Ptt__Push__ContactshipAsked *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ContactsChanged_Closure )
 ( const Ptt__Push__ContactsChanged *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberGetMic_Closure )
 ( const Ptt__Push__MemberGetMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__MemberLostMic_Closure )
 ( const Ptt__Push__MemberLostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__LostMic_Closure )
 ( const Ptt__Push__LostMic *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CurrentGroup_Closure )
 ( const Ptt__Push__CurrentGroup *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Kickout_Closure )
 ( const Ptt__Push__Kickout *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__NewWorksheet_Closure )
 ( const Ptt__Push__NewWorksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__CustomBroadcast_Closure )
 ( const Ptt__Push__CustomBroadcast *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ChangeRoles_Closure )
 ( const Ptt__Push__ChangeRoles *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__Invite_Closure )
 ( const Ptt__Push__Invite *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Push__ResponseInvite_Closure )
 ( const Ptt__Push__ResponseInvite *message ,
 void *closure_data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\sl_tts.ppp
//PPL Source File Name : src\\sl_tts.c
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *tts_netnifo_notify_cb ) ( void* arg ) ;
typedef unsigned int size_t ;
typedef void ( *pfn_sl_notify_adapter ) ( void* user , void* notify ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\sl_ui.ppp
//PPL Source File Name : src\\sl_ui.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef unsigned int size_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *pfn_sl_notify_adapter ) ( void* user , void* notify ) ;
typedef void ( *tts_netnifo_notify_cb ) ( void* arg ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\slmos.ppp
//PPL Source File Name : src\\slmos.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\sos.pb-c.ppp
//PPL Source File Name : src\\sos.pb-c.c
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *Ptt__SocketAddress_Closure )
 ( const Ptt__SocketAddress *message ,
 void *closure_data ) ;
typedef void ( *Ptt__EncryptKey_Closure )
 ( const Ptt__EncryptKey *message ,
 void *closure_data ) ;
typedef void ( *Ptt__AgentInfo_Closure )
 ( const Ptt__AgentInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__CompanyInfo_Closure )
 ( const Ptt__CompanyInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UserInfo_Closure )
 ( const Ptt__UserInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__User_Closure )
 ( const Ptt__User *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Member_Closure )
 ( const Ptt__Member *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ListenerInfo_Closure )
 ( const Ptt__ListenerInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__ChatUser_Closure )
 ( const Ptt__ChatUser *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Group_Closure )
 ( const Ptt__Group *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers_Closure )
 ( const Ptt__GroupMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__GroupMembers2_Closure )
 ( const Ptt__GroupMembers2 *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Department_Closure )
 ( const Ptt__Department *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DepartmentMembers_Closure )
 ( const Ptt__DepartmentMembers *message ,
 void *closure_data ) ;
typedef void ( *Ptt__DateTime_Closure )
 ( const Ptt__DateTime *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Coordinate_Closure )
 ( const Ptt__Coordinate *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Location_Closure )
 ( const Ptt__Location *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Configure_Closure )
 ( const Ptt__Configure *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MediaFile_Closure )
 ( const Ptt__MediaFile *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Worksheet_Closure )
 ( const Ptt__Worksheet *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SystemInfo_Closure )
 ( const Ptt__SystemInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__MobileCardInfo_Closure )
 ( const Ptt__MobileCardInfo *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Server_Closure )
 ( const Ptt__Server *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Version_Closure )
 ( const Ptt__Version *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Accelerometer_Closure )
 ( const Ptt__Accelerometer *message ,
 void *closure_data ) ;
typedef void ( *Ptt__BleRSS_Closure )
 ( const Ptt__BleRSS *message ,
 void *closure_data ) ;
typedef void ( *Ptt__Calibration_Closure )
 ( const Ptt__Calibration *message ,
 void *closure_data ) ;
typedef void ( *Ptt__SingleBeacon_Closure )
 ( const Ptt__SingleBeacon *message ,
 void *closure_data ) ;
typedef void ( *Ptt__UwbLocation_Closure )
 ( const Ptt__UwbLocation *message ,
 void *closure_data ) ;
typedef void ( *Sos__Alarm_Closure )
 ( const Sos__Alarm *message ,
 void *closure_data ) ;
typedef void ( *Sos__Report_Closure )
 ( const Sos__Report *message ,
 void *closure_data ) ;
typedef void ( *Sos__ReportAck_Closure )
 ( const Sos__ReportAck *message ,
 void *closure_data ) ;
typedef void ( *Sos__Process_Closure )
 ( const Sos__Process *message ,
 void *closure_data ) ;
typedef void ( *Sos__ProcessAck_Closure )
 ( const Sos__ProcessAck *message ,
 void *closure_data ) ;
typedef void ( *Sos__Close_Closure )
 ( const Sos__Close *message ,
 void *closure_data ) ;
typedef void ( *Sos__CloseAck_Closure )
 ( const Sos__CloseAck *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmNew_Closure )
 ( const Sos__AlarmNew *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmProcess_Closure )
 ( const Sos__AlarmProcess *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmClosed_Closure )
 ( const Sos__AlarmClosed *message ,
 void *closure_data ) ;
typedef void ( *Sos__Query_Closure )
 ( const Sos__Query *message ,
 void *closure_data ) ;
typedef void ( *Sos__AlarmList_Closure )
 ( const Sos__AlarmList *message ,
 void *closure_data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\sound.ppp
//PPL Source File Name : src\\sound.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_sound_notify ) ( hal_sound_t* sound , int param , void * user ) ;
typedef void ( *pfn_sound_on_record_stop ) ( hal_sound_t* sound , int param , void * user , const hal_frame_t** frames , size_t count ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef void ( *pfn_dsp_on_play_stop ) ( hal_dsp_t* dsp , void* user ) ;
typedef void ( *pfn_dsp_on_record_stop ) ( hal_dsp_t* dsp , void* user , const hal_frame_t** frames , size_t count ) ;
typedef void ( *pfn_tts_notify ) ( void* user ) ;
typedef void ( *pfn_tone_notify ) ( void* user ) ;
typedef int ( *pfn_sound_action ) ( hal_sound_t* self , sound_action_t* action ) ;
typedef void ( *pfn_sound_action_destroy ) ( sound_action_t** p_action ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\speex_jitter.ppp
//PPL Source File Name : src\\speex_jitter.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef int16_t spx_int16_t ;
typedef uint16_t spx_uint16_t ;
typedef int32_t spx_int32_t ;
typedef uint32_t spx_uint32_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\stackbuf.ppp
//PPL Source File Name : src\\stackbuf.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\symbol.ppp
//PPL Source File Name : src\\symbol.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
typedef union U_symbol_t
 {
 long integer ;
 double real ;
 void* pointer ;
 }
 U_symbol_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\terminal.pb-c.ppp
//PPL Source File Name : src\\terminal.pb-c.c
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
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef va_list __gnuc_va_list ;
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef int protobuf_c_boolean ;
typedef void ( *ProtobufCClosure ) ( const ProtobufCMessage * , void *closure_data ) ;
typedef void ( *ProtobufCMessageInit ) ( const ProtobufCMessageDescriptor* , ProtobufCMessage * ) ;
typedef void ( *ProtobufCServiceDestroy ) ( ProtobufCService * ) ;
typedef void ( *Terminal__Status__TerminalStatusDetail_Closure )
 ( const Terminal__Status__TerminalStatusDetail *message ,
 void *closure_data ) ;
typedef void ( *Terminal__Status__ReqPrivilegeList_Closure )
 ( const Terminal__Status__ReqPrivilegeList *message ,
 void *closure_data ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\timet.ppp
//PPL Source File Name : src\\timet.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\tone.ppp
//PPL Source File Name : src\\tone.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_tone_notify ) ( void* user ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\tree.ppp
//PPL Source File Name : src\\tree.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\tts.ppp
//PPL Source File Name : src\\tts.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( *hal_device_alarm_timer_cb_t ) ( void* user ) ;
typedef void ( *pfn_tts_notify ) ( void* user ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\vector.ppp
//PPL Source File Name : src\\vector.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\vocodec.ppp
//PPL Source File Name : src\\vocodec.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef VO_S32 ( * VOAUDIOCALLBACKPROC ) ( VO_PTR pUserData , VO_CODECBUFFER * pAudioBuffer , VO_AUDIO_FORMAT * pAudioFormat , VO_S32 nStart ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\a2lsp.ppp
//PPL Source File Name : src\\evrc\\a2lsp.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\acb_ex.ppp
//PPL Source File Name : src\\evrc\\acb_ex.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\acelp_pf.ppp
//PPL Source File Name : src\\evrc\\acelp_pf.c
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\apf.ppp
//PPL Source File Name : src\\evrc\\apf.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\auto.ppp
//PPL Source File Name : src\\evrc\\auto.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\bitpack.ppp
//PPL Source File Name : src\\evrc\\bitpack.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\bitupack.ppp
//PPL Source File Name : src\\evrc\\bitupack.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\bl_intrp.ppp
//PPL Source File Name : src\\evrc\\bl_intrp.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\bqiir.ppp
//PPL Source File Name : src\\evrc\\bqiir.c
typedef unsigned int size_t ;
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\c3_10pf.ppp
//PPL Source File Name : src\\evrc\\c3_10pf.c
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\c8_35pf.ppp
//PPL Source File Name : src\\evrc\\c8_35pf.c
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\cmnMemory.ppp
//PPL Source File Name : src\\evrc\\cmnMemory.c
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\comacb.ppp
//PPL Source File Name : src\\evrc\\comacb.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\convh.ppp
//PPL Source File Name : src\\evrc\\convh.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\cshift.ppp
//PPL Source File Name : src\\evrc\\cshift.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\d_fer.ppp
//PPL Source File Name : src\\evrc\\d_fer.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\d_no_fer.ppp
//PPL Source File Name : src\\evrc\\d_no_fer.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\d_rate_1.ppp
//PPL Source File Name : src\\evrc\\d_rate_1.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\d3_10pf.ppp
//PPL Source File Name : src\\evrc\\d3_10pf.c
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\d8_35pf.ppp
//PPL Source File Name : src\\evrc\\d8_35pf.c
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\decode.ppp
//PPL Source File Name : src\\evrc\\decode.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\durbin.ppp
//PPL Source File Name : src\\evrc\\durbin.c
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\encode.ppp
//PPL Source File Name : src\\evrc\\encode.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\evrcc.ppp
//PPL Source File Name : src\\evrc\\evrcc.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef VO_S32 ( * VOAUDIOCALLBACKPROC ) ( VO_PTR pUserData , VO_CODECBUFFER * pAudioBuffer , VO_AUDIO_FORMAT * pAudioFormat , VO_S32 nStart ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\fcbgq.ppp
//PPL Source File Name : src\\evrc\\fcbgq.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\fer.ppp
//PPL Source File Name : src\\evrc\\fer.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\filter.ppp
//PPL Source File Name : src\\evrc\\filter.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\fndppf.ppp
//PPL Source File Name : src\\evrc\\fndppf.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\getext1k.ppp
//PPL Source File Name : src\\evrc\\getext1k.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\getgain.ppp
//PPL Source File Name : src\\evrc\\getgain.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\getres.ppp
//PPL Source File Name : src\\evrc\\getres.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\impulser.ppp
//PPL Source File Name : src\\evrc\\impulser.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\interpol.ppp
//PPL Source File Name : src\\evrc\\interpol.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\intr_cos.ppp
//PPL Source File Name : src\\evrc\\intr_cos.c
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\inv_sqrt_evrcc.ppp
//PPL Source File Name : src\\evrc\\inv_sqrt_evrcc.c
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\lpcana.ppp
//PPL Source File Name : src\\evrc\\lpcana.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\lsp2a.ppp
//PPL Source File Name : src\\evrc\\lsp2a.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\lspmaq.ppp
//PPL Source File Name : src\\evrc\\lspmaq.c
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\math_adv.ppp
//PPL Source File Name : src\\evrc\\math_adv.c
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\math_ext32.ppp
//PPL Source File Name : src\\evrc\\math_ext32.c
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\maxeloc.ppp
//PPL Source File Name : src\\evrc\\maxeloc.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\mdfyorig.ppp
//PPL Source File Name : src\\evrc\\mdfyorig.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\mem_align.ppp
//PPL Source File Name : src\\evrc\\mem_align.c
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\mod.ppp
//PPL Source File Name : src\\evrc\\mod.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\ns127.ppp
//PPL Source File Name : src\\evrc\\ns127.c
typedef unsigned int size_t ;
typedef float float_t ;
typedef double double_t ;
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\pit_shrp.ppp
//PPL Source File Name : src\\evrc\\pit_shrp.c
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\pktoav.ppp
//PPL Source File Name : src\\evrc\\pktoav.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\pre_enc.ppp
//PPL Source File Name : src\\evrc\\pre_enc.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\putacbc.ppp
//PPL Source File Name : src\\evrc\\putacbc.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\r_fft_evrcc.ppp
//PPL Source File Name : src\\evrc\\r_fft_evrcc.c
typedef long int Longword ;
typedef short int Shortword ;
typedef short int ShortwordRom ;
typedef long int LongwordRom ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\rda.ppp
//PPL Source File Name : src\\evrc\\rda.c
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\rom.ppp
//PPL Source File Name : src\\evrc\\rom.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\stream.ppp
//PPL Source File Name : src\\evrc\\stream.c
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\synfltr.ppp
//PPL Source File Name : src\\evrc\\synfltr.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\voEVRCDec.ppp
//PPL Source File Name : src\\evrc\\voEVRCDec.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef VO_S32 ( * VOAUDIOCALLBACKPROC ) ( VO_PTR pUserData , VO_CODECBUFFER * pAudioBuffer , VO_AUDIO_FORMAT * pAudioFormat , VO_S32 nStart ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\voEVRCEnc.ppp
//PPL Source File Name : src\\evrc\\voEVRCEnc.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef VO_S32 ( * VOAUDIOCALLBACKPROC ) ( VO_PTR pUserData , VO_CODECBUFFER * pAudioBuffer , VO_AUDIO_FORMAT * pAudioFormat , VO_S32 nStart ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\w2res.ppp
//PPL Source File Name : src\\evrc\\w2res.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\weight.ppp
//PPL Source File Name : src\\evrc\\weight.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef short Word16 ;
typedef unsigned short UNS_Word16 ;
typedef short Word16Rom ;
typedef int Word32 ;
typedef int Word32Rom ;
typedef double Word40 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\evrc\zeroinpt.ppp
//PPL Source File Name : src\\evrc\\zeroinpt.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef void VO_VOID ;
typedef unsigned char VO_U8 ;
typedef unsigned char VO_BYTE ;
typedef signed char VO_S8 ;
typedef char VO_CHAR ;
typedef unsigned short VO_U16 ;
typedef signed short VO_S16 ;
typedef unsigned long VO_U32 ;
typedef signed long VO_S32 ;
typedef unsigned long long VO_U64 ;
typedef signed long long VO_S64 ;
typedef void* VO_PTR ;
typedef const void* VO_CPTR ;
typedef void* VO_HANDLE ;
typedef char* VO_PCHAR ;
typedef unsigned char* VO_PBYTE ;
typedef char* VO_PTTCHAR ;
typedef char VO_TTCHAR ;
typedef int ( * VOThreadCreate ) ( void ** pHandle , int * pID , void * fProc , void * pParam ) ;
typedef int ( * VOLOG_PRINT ) ( void * pUserData , int nLevel , char * pLogText ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\a_refl.ppp
//PPL Source File Name : src\\amrcc\\a_refl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\add.ppp
//PPL Source File Name : src\\amrcc\\add.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\agc.ppp
//PPL Source File Name : src\\amrcc\\agc.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\amrdecode.ppp
//PPL Source File Name : src\\amrcc\\amrdecode.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\amrencode.ppp
//PPL Source File Name : src\\amrcc\\amrencode.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\autocorr.ppp
//PPL Source File Name : src\\amrcc\\autocorr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\az_lsp.ppp
//PPL Source File Name : src\\amrcc\\az_lsp.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\b_cn_cod.ppp
//PPL Source File Name : src\\amrcc\\b_cn_cod.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\bgnscd.ppp
//PPL Source File Name : src\\amrcc\\bgnscd.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\bitno_tab.ppp
//PPL Source File Name : src\\amrcc\\bitno_tab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\bitreorder_tab.ppp
//PPL Source File Name : src\\amrcc\\bitreorder_tab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\c_g_aver.ppp
//PPL Source File Name : src\\amrcc\\c_g_aver.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\c1035pf.ppp
//PPL Source File Name : src\\amrcc\\c1035pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\c2_11pf.ppp
//PPL Source File Name : src\\amrcc\\c2_11pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\c2_9pf.ppp
//PPL Source File Name : src\\amrcc\\c2_9pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\c2_9pf_tab.ppp
//PPL Source File Name : src\\amrcc\\c2_9pf_tab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\c3_14pf.ppp
//PPL Source File Name : src\\amrcc\\c3_14pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\c4_17pf.ppp
//PPL Source File Name : src\\amrcc\\c4_17pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\c8_31pf.ppp
//PPL Source File Name : src\\amrcc\\c8_31pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\calc_cor.ppp
//PPL Source File Name : src\\amrcc\\calc_cor.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\calc_en.ppp
//PPL Source File Name : src\\amrcc\\calc_en.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\cbsearch.ppp
//PPL Source File Name : src\\amrcc\\cbsearch.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\cl_ltp.ppp
//PPL Source File Name : src\\amrcc\\cl_ltp.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\cod_amr.ppp
//PPL Source File Name : src\\amrcc\\cod_amr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\convolve.ppp
//PPL Source File Name : src\\amrcc\\convolve.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\cor_h.ppp
//PPL Source File Name : src\\amrcc\\cor_h.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\cor_h_x_amr.ppp
//PPL Source File Name : src\\amrcc\\cor_h_x_amr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\cor_h_x2.ppp
//PPL Source File Name : src\\amrcc\\cor_h_x2.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\corrwght_tab.ppp
//PPL Source File Name : src\\amrcc\\corrwght_tab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\d_gain_c.ppp
//PPL Source File Name : src\\amrcc\\d_gain_c.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\d_gain_p.ppp
//PPL Source File Name : src\\amrcc\\d_gain_p.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\d_plsf.ppp
//PPL Source File Name : src\\amrcc\\d_plsf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\d_plsf_3.ppp
//PPL Source File Name : src\\amrcc\\d_plsf_3.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\d_plsf_5.ppp
//PPL Source File Name : src\\amrcc\\d_plsf_5.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\d1035pf.ppp
//PPL Source File Name : src\\amrcc\\d1035pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\d2_11pf.ppp
//PPL Source File Name : src\\amrcc\\d2_11pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\d2_9pf.ppp
//PPL Source File Name : src\\amrcc\\d2_9pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\d3_14pf.ppp
//PPL Source File Name : src\\amrcc\\d3_14pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\d4_17pf.ppp
//PPL Source File Name : src\\amrcc\\d4_17pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\d8_31pf.ppp
//PPL Source File Name : src\\amrcc\\d8_31pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\dec_amr.ppp
//PPL Source File Name : src\\amrcc\\dec_amr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\dec_gain.ppp
//PPL Source File Name : src\\amrcc\\dec_gain.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\dec_input_format_tab.ppp
//PPL Source File Name : src\\amrcc\\dec_input_format_tab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\dec_lag3.ppp
//PPL Source File Name : src\\amrcc\\dec_lag3.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\dec_lag6.ppp
//PPL Source File Name : src\\amrcc\\dec_lag6.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\div_32.ppp
//PPL Source File Name : src\\amrcc\\div_32.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\div_s.ppp
//PPL Source File Name : src\\amrcc\\div_s.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\dtx_dec.ppp
//PPL Source File Name : src\\amrcc\\dtx_dec.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\dtx_enc.ppp
//PPL Source File Name : src\\amrcc\\dtx_enc.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\ec_gains.ppp
//PPL Source File Name : src\\amrcc\\ec_gains.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\enc_lag3.ppp
//PPL Source File Name : src\\amrcc\\enc_lag3.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\enc_lag6.ppp
//PPL Source File Name : src\\amrcc\\enc_lag6.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\enc_output_format_tab.ppp
//PPL Source File Name : src\\amrcc\\enc_output_format_tab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\ets_to_if2.ppp
//PPL Source File Name : src\\amrcc\\ets_to_if2.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\ets_to_wmf.ppp
//PPL Source File Name : src\\amrcc\\ets_to_wmf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\ex_ctrl.ppp
//PPL Source File Name : src\\amrcc\\ex_ctrl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\extract_h.ppp
//PPL Source File Name : src\\amrcc\\extract_h.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\extract_l.ppp
//PPL Source File Name : src\\amrcc\\extract_l.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\g_adapt.ppp
//PPL Source File Name : src\\amrcc\\g_adapt.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\g_code_amr.ppp
//PPL Source File Name : src\\amrcc\\g_code_amr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\g_pitch.ppp
//PPL Source File Name : src\\amrcc\\g_pitch.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\gain_q.ppp
//PPL Source File Name : src\\amrcc\\gain_q.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\gains_tbl.ppp
//PPL Source File Name : src\\amrcc\\gains_tbl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\gc_pred.ppp
//PPL Source File Name : src\\amrcc\\gc_pred.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\get_const_tbls.ppp
//PPL Source File Name : src\\amrcc\\get_const_tbls.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\gmed_n.ppp
//PPL Source File Name : src\\amrcc\\gmed_n.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\gray_tbl.ppp
//PPL Source File Name : src\\amrcc\\gray_tbl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\grid_tbl.ppp
//PPL Source File Name : src\\amrcc\\grid_tbl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\hp_max.ppp
//PPL Source File Name : src\\amrcc\\hp_max.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\if2_to_ets.ppp
//PPL Source File Name : src\\amrcc\\if2_to_ets.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\int_lpc.ppp
//PPL Source File Name : src\\amrcc\\int_lpc.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\int_lsf.ppp
//PPL Source File Name : src\\amrcc\\int_lsf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\inter_36.ppp
//PPL Source File Name : src\\amrcc\\inter_36.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\inter_36_tab.ppp
//PPL Source File Name : src\\amrcc\\inter_36_tab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\inv_sqrt.ppp
//PPL Source File Name : src\\amrcc\\inv_sqrt.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\inv_sqrt_tbl.ppp
//PPL Source File Name : src\\amrcc\\inv_sqrt_tbl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\l_abs_amr.ppp
//PPL Source File Name : src\\amrcc\\l_abs_amr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\l_comp.ppp
//PPL Source File Name : src\\amrcc\\l_comp.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\l_deposit_h.ppp
//PPL Source File Name : src\\amrcc\\l_deposit_h.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\l_deposit_l.ppp
//PPL Source File Name : src\\amrcc\\l_deposit_l.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\l_extract.ppp
//PPL Source File Name : src\\amrcc\\l_extract.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\l_negate_amr.ppp
//PPL Source File Name : src\\amrcc\\l_negate_amr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\l_shr_r.ppp
//PPL Source File Name : src\\amrcc\\l_shr_r.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\lag_wind.ppp
//PPL Source File Name : src\\amrcc\\lag_wind.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\lag_wind_tab.ppp
//PPL Source File Name : src\\amrcc\\lag_wind_tab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\levinson.ppp
//PPL Source File Name : src\\amrcc\\levinson.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\lflg_upd.ppp
//PPL Source File Name : src\\amrcc\\lflg_upd.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\log2.ppp
//PPL Source File Name : src\\amrcc\\log2.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\log2_norm.ppp
//PPL Source File Name : src\\amrcc\\log2_norm.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\log2_tbl.ppp
//PPL Source File Name : src\\amrcc\\log2_tbl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\lpc.ppp
//PPL Source File Name : src\\amrcc\\lpc.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\lsfwt.ppp
//PPL Source File Name : src\\amrcc\\lsfwt.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\lsp_amr.ppp
//PPL Source File Name : src\\amrcc\\lsp_amr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\lsp_avg.ppp
//PPL Source File Name : src\\amrcc\\lsp_avg.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\lsp_az.ppp
//PPL Source File Name : src\\amrcc\\lsp_az.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\lsp_lsf.ppp
//PPL Source File Name : src\\amrcc\\lsp_lsf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\lsp_lsf_tbl.ppp
//PPL Source File Name : src\\amrcc\\lsp_lsf_tbl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\lsp_tab.ppp
//PPL Source File Name : src\\amrcc\\lsp_tab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\mult_r_amr.ppp
//PPL Source File Name : src\\amrcc\\mult_r_amr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\negate.ppp
//PPL Source File Name : src\\amrcc\\negate.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\norm_l_amr.ppp
//PPL Source File Name : src\\amrcc\\norm_l_amr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\norm_s_amr.ppp
//PPL Source File Name : src\\amrcc\\norm_s_amr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\ol_ltp.ppp
//PPL Source File Name : src\\amrcc\\ol_ltp.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\overflow_tbl.ppp
//PPL Source File Name : src\\amrcc\\overflow_tbl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\p_ol_wgh.ppp
//PPL Source File Name : src\\amrcc\\p_ol_wgh.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\ph_disp.ppp
//PPL Source File Name : src\\amrcc\\ph_disp.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\ph_disp_tab.ppp
//PPL Source File Name : src\\amrcc\\ph_disp_tab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\pitch_fr.ppp
//PPL Source File Name : src\\amrcc\\pitch_fr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\pitch_ol.ppp
//PPL Source File Name : src\\amrcc\\pitch_ol.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\post_pro.ppp
//PPL Source File Name : src\\amrcc\\post_pro.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\pow2.ppp
//PPL Source File Name : src\\amrcc\\pow2.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\pow2_tbl.ppp
//PPL Source File Name : src\\amrcc\\pow2_tbl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\pre_big.ppp
//PPL Source File Name : src\\amrcc\\pre_big.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\pre_proc.ppp
//PPL Source File Name : src\\amrcc\\pre_proc.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\pred_lt.ppp
//PPL Source File Name : src\\amrcc\\pred_lt.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\preemph.ppp
//PPL Source File Name : src\\amrcc\\preemph.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\prm2bits.ppp
//PPL Source File Name : src\\amrcc\\prm2bits.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\pstfilt.ppp
//PPL Source File Name : src\\amrcc\\pstfilt.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\q_gain_c.ppp
//PPL Source File Name : src\\amrcc\\q_gain_c.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\q_gain_p.ppp
//PPL Source File Name : src\\amrcc\\q_gain_p.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\q_plsf.ppp
//PPL Source File Name : src\\amrcc\\q_plsf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\q_plsf_3.ppp
//PPL Source File Name : src\\amrcc\\q_plsf_3.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\q_plsf_3_tbl.ppp
//PPL Source File Name : src\\amrcc\\q_plsf_3_tbl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\q_plsf_5.ppp
//PPL Source File Name : src\\amrcc\\q_plsf_5.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\q_plsf_5_tbl.ppp
//PPL Source File Name : src\\amrcc\\q_plsf_5_tbl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\qgain475.ppp
//PPL Source File Name : src\\amrcc\\qgain475.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\qgain475_tab.ppp
//PPL Source File Name : src\\amrcc\\qgain475_tab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\qgain795.ppp
//PPL Source File Name : src\\amrcc\\qgain795.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\qua_gain.ppp
//PPL Source File Name : src\\amrcc\\qua_gain.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\qua_gain_tbl.ppp
//PPL Source File Name : src\\amrcc\\qua_gain_tbl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\reorder.ppp
//PPL Source File Name : src\\amrcc\\reorder.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\residu.ppp
//PPL Source File Name : src\\amrcc\\residu.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\round.ppp
//PPL Source File Name : src\\amrcc\\round.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\s10_8pf.ppp
//PPL Source File Name : src\\amrcc\\s10_8pf.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\set_sign.ppp
//PPL Source File Name : src\\amrcc\\set_sign.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\set_zero.ppp
//PPL Source File Name : src\\amrcc\\set_zero.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\shr_amr.ppp
//PPL Source File Name : src\\amrcc\\shr_amr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\shr_r.ppp
//PPL Source File Name : src\\amrcc\\shr_r.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\sid_sync.ppp
//PPL Source File Name : src\\amrcc\\sid_sync.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\sp_dec.ppp
//PPL Source File Name : src\\amrcc\\sp_dec.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\sp_enc.ppp
//PPL Source File Name : src\\amrcc\\sp_enc.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\spreproc.ppp
//PPL Source File Name : src\\amrcc\\spreproc.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\spstproc.ppp
//PPL Source File Name : src\\amrcc\\spstproc.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\sqrt_l.ppp
//PPL Source File Name : src\\amrcc\\sqrt_l.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\sqrt_l_tbl.ppp
//PPL Source File Name : src\\amrcc\\sqrt_l_tbl.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\sub_amr.ppp
//PPL Source File Name : src\\amrcc\\sub_amr.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\syn_filt.ppp
//PPL Source File Name : src\\amrcc\\syn_filt.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\ton_stab.ppp
//PPL Source File Name : src\\amrcc\\ton_stab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\vad1.ppp
//PPL Source File Name : src\\amrcc\\vad1.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\weight_a.ppp
//PPL Source File Name : src\\amrcc\\weight_a.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\window_tab.ppp
//PPL Source File Name : src\\amrcc\\window_tab.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\wmf_to_ets.ppp
//PPL Source File Name : src\\amrcc\\wmf_to_ets.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\amrcc\wrapper.ppp
//PPL Source File Name : src\\amrcc\\wrapper.c
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
typedef int8_t int8 ;
typedef uint8_t uint8 ;
typedef int16_t int16 ;
typedef uint16_t uint16 ;
typedef int32_t int32 ;
typedef uint32_t uint32 ;
typedef int64_t int64 ;
typedef uint64_t uint64 ;
typedef int8 Word8 ;
typedef uint8 UWord8 ;
typedef int16 Word16 ;
typedef uint16 UWord16 ;
typedef int32 Word32 ;
typedef uint32 UWord32 ;
typedef int Bool ;
typedef int32 Flag ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\at\at_keyEvt.ppp
//PPL Source File Name : src\\at\\at_keyEvt.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_notify_at ) ( void* user , unsigned char cid , unsigned char rst ) ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *tts_netnifo_notify_cb ) ( void* arg ) ;
typedef unsigned int size_t ;
typedef void ( *pfn_sl_notify_adapter ) ( void* user , void* notify ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\at\at_swap.ppp
//PPL Source File Name : src\\at\\at_swap.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *HOOK_FUN ) ( void* , void* ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\at\sl_at.ppp
//PPL Source File Name : src\\at\\sl_at.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *HOOK_FUN ) ( void* , void* ) ;
typedef void ( *tts_netnifo_notify_cb ) ( void* arg ) ;
typedef void ( *pfn_sl_notify_adapter ) ( void* user , void* notify ) ;
typedef void ( * pfn_hal_looper_user_free ) ( void* user ) ;
typedef void ( *pfn_looper_event_destroy ) ( hal_looper_event_t* event ) ;
typedef void ( * pfn_hal_looper_event_processer ) ( hal_looper_t* looper , hal_looper_event_t* event , void* user ) ;
typedef void ( * pfn_hal_looper_timer_callback ) ( hal_looper_t* looper , hal_time_t now , void* user ) ;
typedef int ( * pfn_hal_looper_routine ) ( hal_looper_t* looper , void* user ) ;
typedef void ( *pfn_ini_parser ) ( void* user , const char* section , const char* name , const char* value ) ;
typedef void ( *pfn_notify_at ) ( void* user , unsigned char cid , unsigned char rst ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\at\sl_at_backdoor.ppp
//PPL Source File Name : src\\at\\sl_at_backdoor.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *HOOK_FUN ) ( void* , void* ) ;
typedef void ( *tts_netnifo_notify_cb ) ( void* arg ) ;
typedef void ( *pfn_sl_notify_adapter ) ( void* user , void* notify ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\bnd_sdk\broad.ppp
//PPL Source File Name : src\\bnd_sdk\\broad.c
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *tts_netnifo_notify_cb ) ( void* arg ) ;
typedef unsigned int uid_t ;
typedef unsigned int gid_t ;
typedef unsigned char boolean ;
typedef void ( *init_cb ) ( int ret ) ;
typedef void ( *login_state_cb ) ( int online ) ;
typedef void ( *join_group_cb ) ( const char* groupname , gid_t gid ) ;
typedef void ( *audio_cb ) ( AUDIO_STATE state , uid_t uid , const char* name , int flag , gid_t gid , const char* g_name ) ;
typedef void ( *callmember_cb ) ( int ret ) ;
typedef void ( *listupdate_cb ) ( int flag ) ;
typedef void ( *member_change_cb ) ( int flag , int nun , uid_t* uids ) ;
typedef void ( *error_cb ) ( const char* info ) ;
typedef void ( *poc_at_cb ) ( char* at ) ;
typedef void ( *upgrade_cb ) ( int ret ) ;
typedef void ( *write_account_cb ) ( int ret ) ;
typedef void ( *member_audio_enable ) ( int enable ) ;
typedef void ( *reminder_cb ) ( char* reminder , int day ) ;
typedef void ( *pa_cb ) ( int on_off ) ;
typedef void ( *request_lbs_info_cb ) ( char *z8filename , char *z12filename , char *z16filename , char *lbs_tts , char is_lbs_tts , char is_static_map ) ;
typedef void ( *location_change_cb ) ( int location_switch , int report_rate ) ;
typedef void ( *weather_info_cb ) ( char *lbs_tts , char is_lbs_tts ) ;
typedef void ( *request_invite_ack_cb ) ( uint64_t invite_id , int32_t result , uint32_t *invites , int invites_count , int reason ) ;
typedef void ( *response_invite_ack_cb ) ( int32_t result , uint32_t is_timeout ) ;
typedef void ( *push_invite_cb ) ( uint64_t invite_id , uint32_t inviter ) ;
typedef void ( *push_response_invite_cb ) ( uint64_t invite_id , uint32_t invitee , uint32_t accept , int reason ) ;
typedef void ( *sos_status_cb ) ( char send_sos_status ) ;
typedef void ( *sos_map_cb ) ( char *z8filename , char *z12filename , char *z16filename , char is_sos_map ) ;
typedef void ( *recv_sos_info_cb ) ( char *sendname , char *timestamp , double lon , double lat ) ;
typedef void ( *recv_enclosure_alarm_cb ) ( int alarm , char *tips ) ;
typedef void ( *recv_broadcast_info_cb ) ( int flags , char *tts ) ;
typedef void ( *recv_http_request_status_cb ) ( int status ) ;
typedef void ( *recv_http_request_add_group_status_cb ) ( int status , int gid , char *group_name , char *invite_code ) ;
typedef void ( *recv_http_get_invitation_code_cb ) ( int status , char *invitation_code ) ;
typedef void ( *recv_http_request_timeout_cb ) ( ) ;
typedef void ( *create_group_cb ) ( int create_group_switch ) ;
typedef void ( *recv_sos_alarm_cb ) ( uint32_t reporter , uint64_t uuid , double lon , double lat , uint32_t gid ) ;
typedef void ( *recv_report_sos_ack_cb ) ( int result ) ;
typedef void ( *recv_report_sos_ack_timeout_cb ) ( ) ;
typedef void ( *recv_close_sos_cb ) ( int uid , uint64_t uuid ) ;
typedef void ( *sos_switch_cb ) ( int sos_switch ) ;
typedef void ( *ai_switch_cb ) ( int ai_switch ) ;
typedef void ( *recv_reportType_msg_cb ) ( char* msg ) ;
typedef void ( *recv_ai_audio_info_cb ) ( int robot_status , char *ai_msg ) ;
typedef void ( *recv_record_file_err_cb ) ( BND_RECORD_FILE_ERR err ) ;
typedef void ( *recv_record_file_list_cb ) ( int size , bnd_record_file_info_t* list_struct_array ) ;
typedef void ( *patrol_switch_cb ) ( int patrol_switch ) ;
typedef void ( *recv_patrol_err_cb ) ( BND_PATROL_ERR err ) ;
typedef void ( *recv_patrol_job_today_array_cb ) ( broad_job_info_t* job_array , int job_size ) ;
typedef void ( *recv_patrol_job_detail_cb ) ( broad_job_detail_t* job_detail ) ;
typedef void ( *recv_patrol_send_clockin_cb ) ( int clockin_result , char* clockin_result_str ) ;
typedef void ( *recv_patrol_job_remind ) ( char* jobid , char* planname , unsigned int starttime , unsigned int countdownminutes ) ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef int SCL_CHECK_UINT32_1 [ 4 -sizeof ( uint32_t ) ] ;
typedef int SCL_CHECK_UINT32_2 [ sizeof ( uint32_t ) -4 ] ;
typedef int ( *SCL_cbfn_t ) ( const char* , long , void* , void* ) ;
typedef uint32_t ( *SCL_mdfn_t ) ( const char* , size_t ) ;
typedef void* ( *SCL_getfn_t ) ( size_t ) ;
typedef int ( *SCL_putfn_t ) ( void* , size_t ) ;
typedef void* SCL_iterator_t ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\encrypt\en_decrypt.ppp
//PPL Source File Name : src\\encrypt\\en_decrypt.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef va_list __gnuc_va_list ;
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
typedef int8_t byte_t ;
typedef unsigned char boolean ;
typedef uint32_t hal_time_t ;
typedef uint32_t echat_uid_t ;
typedef uint32_t echat_gid_t ;
typedef void ( *pfn_location_cb ) ( loc_info_t* loc_info , void* user ) ;
typedef void ( *win_pfn_broadcast_record_async_stop ) ( void ) ;
typedef void ( *win_pfn_broadcast_play_async_stop ) ( void ) ;
typedef void ( *echat_notify_cb_t ) ( void* user , echat_notify_t* notify ) ;
typedef void ( *echat_notify_param_cb_t ) ( void* user , int param , void * arg ) ;
typedef void ( *oem_notify_cb_t ) ( void* user ) ;
typedef void ( *oem_stream_dB_cb_t ) ( int dB , void* user ) ;
typedef void ( *oem_stream_has_data_cb_t ) ( const void* data , size_t size , void* user ) ;
typedef void ( *oem_tone_cb_t ) ( void* user ) ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\encrypt\encrypt_method\aes256\aes_core.ppp
//PPL Source File Name : src\\encrypt\\encrypt_method\\aes256\\aes_core.c
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned int u32 ;
typedef unsigned short u16 ;
typedef unsigned char u8 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\encrypt\encrypt_method\aes256\aes_ecb.ppp
//PPL Source File Name : src\\encrypt\\encrypt_method\\aes256\\aes_ecb.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef unsigned int u32 ;
typedef unsigned short u16 ;
typedef unsigned char u8 ;
//PPC Version : V2.1.9.30
//PPL Source File Name : build\obj\src\encrypt\encrypt_method\aes256\aes_encrypt.ppp
//PPL Source File Name : src\\encrypt\\encrypt_method\\aes256\\aes_encrypt.c
typedef unsigned int size_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef unsigned int size_t ;
typedef unsigned int u32 ;
typedef unsigned short u16 ;
typedef unsigned char u8 ;
