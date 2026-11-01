#ifndef __DOWNLOAD_H__
#define __DOWNLOAD_H__
#include "fbf_parse.h"
#include "uart.h"
#include "diag_API.h"
#include "simPin.h"

#define NEW_MINI_OTA_VERSION
#define DOWNLOAD_BREAKPOINT_SUPPORT
#define SUPPORT_ADIFF_DFOTA_VERSION

#ifdef LTEONLY_THIN
#define fota_debug(cat3, fmt, args...)
#else
#define fota_debug(cat3, fmt, args...)  		\
	do{									\
		DIAG_FILTER(MIFI, FOTA, cat3, DIAG_INFORMATION)	\
		diagPrintf(fmt, ##args);			\
	}while(0)

#endif

#define fota_error(cat3, fmt, args...) 	\
	do{									\
		DIAG_FILTER(MIFI, FOTA, cat3, DIAG_INFORMATION)	\
		diagPrintf(fmt, ##args);			\
	}while(0)


#ifdef QUECTEL_PROJECT_CUST

#define fota_printf(fmt, args...) do { CPUartLogPrintf("[ %s, %d ]""[ fota ]"fmt,__FUNCTION__, __LINE__, ##args); } while(0)

#else
#define fota_printf(cat3, fmt, args...) 	\
	do{									\
		DIAG_FILTER(MIFI, FOTA, cat3, DIAG_INFORMATION)	\
		diagPrintf(fmt, ##args);			\
	}while(0)
#endif


#define FLASH_BLOCK         0x00010000 //64K
#define FLASH_4K_SECTOR     0x00001000 //4K

/* CRANE QSPI base address.*/
#define FOTA_CRANE_QSPI_BASE_ADDRESS             0x80000000
//#define SUPPORT_FOTA_NVM

#define RW_REGION_MARK_PRE_STRING "RW_CPZ_"
#define RW_REGION_COMPRESSED_ADDR_NONE  0x00000000
#define IPR_BUAD_MAGIC                  0x42554144
#define FOTA_WRITE_FLASH_TRY_NUM        5
#define FOTA_HEADER_MAGIC 		        0x54524657


#define FORWARD_MODE  0x00000001
#define REVERSE_MODE  0x00000002

#define ASR_FOTA_UPDATE_SYSTEM		0x00000001
#define ASR_FOTA_UPDATE_RF			0x00000002
#define ASR_FOTA_UPDATE_UPDATER		0x00000004

#define ASR_FOTA_CLEAN_RD


typedef enum {
	FOTA_SUCCESS=0,
	FOTA_COMPLETED=100,
	FOTA_DOMAIN_NOT_EXIST=1001,
	FOTA_DOMAIN_TIMEOUT,
	FOTA_DOMAIN_UNKNOWN,
	FOTA_AUTH_FAILED,
	FOTA_FILE_NOT_EXIST,
	FOTA_FILE_SIZE_INVALID,
	FOTA_FILE_GET_ERR,
	FOTA_FILE_CHECK_ERR,
	FOTA_INTERNAL_ERR,
	FOTA_FILE_SIZE_TOO_LARGE,
	FOTA_SET_FLAG_FAILED,
	FOTA_PARAM_SIZE_INVALID,
} _FOTARes;

typedef enum {
	FOTA_FTP,
	FOTA_HTTP,
	FOTA_NONE,
} _FotaMode;


enum {
	HEADER,
	CONTENT,
};

struct image_state {
	struct imginfo_table * image_info;
	struct image_state * next_image;
	int result;
};

typedef struct _asr_non_diff_info{
	UINT32 roAddress;
	UINT32 roLen;
	UINT32 roChecksum;
	UINT32 nonfotaAddress;
	UINT32 nonfotaLen;
	UINT32 nonfotaChecksum;
	
	UINT32 app1PartionAddress;
	UINT32 app1PartionLen;
	UINT32 app1PartionChecksum;

	UINT32 app2PartionAddress;
	UINT32 app2PartionLen;
	UINT32 app2PartionChecksum;

	UINT32 app3PartionAddress;
	UINT32 app3PartionLen;
	UINT32 app3PartionChecksum;

	
	UINT32 reserved[3];
	UINT32 updater_offset;
	UINT32 updater_size;
	UINT32 updater_addr;
}asr_non_diff_info;



struct image_process_context {
	ImginfoTable * image_info_table;
	ImginfoTable * current_process;
	unsigned int processed_cnt;
	int state;
	char * flash_cache;
	int flash_cache_index;
	int (*flash_cb)(struct image_process_context *, char *, int);
	char * checksum_cache;
	int checksum_cache_index;
	unsigned int image_checksum;
	struct image_state * image_state_list;

//#ifdef SUPPORT_MINI_SYSTEM
    unsigned int download_stage;

    unsigned int saved_head;
    unsigned int backupAddress;
    unsigned int startFirAddress;
    unsigned int startFirSize;
    unsigned int startSecAddress;
    unsigned int startSecSize;

    asr_non_diff_info nondiffinfo;
	#if defined(DOWNLOAD_BREAKPOINT_SUPPORT)
    char * url;
	unsigned int url_checksum;
    //char * username;
	//char * password;
	unsigned int file_size;
    #endif
    /*
    unsigned int non_fota_address;
    unsigned int non_fota_len;
    unsigned int non_fota_checksum; 
    unsigned int ro_address;
    unsigned int ro_len;
    unsigned int ro_checksum; 
    */
    
//#endif
};


typedef unsigned char	BOOL;

// Call http client for download special image
// This function will be called in main thread
enum {
	CONNECT_FAILED      = 9015,
	ABORT_FAILED        = 9017,
	CORRUPT_FILE_FAILED = 9018,
	AUTH_FAILED         = 9012,
	NOT_PRESENT_FAILED  = 9016,
};


enum {
	DOWNLOAD_STAGE_NONE,
	DOWNLOAD_STAGE_FIRST,
	DOWNLOAD_STAGE_SECOND,
	DOWNLOAD_STAGE_SECOND_HEADER
};


enum {
	MINI_SYS_DFOTA_START,
	MINI_SYS_DFOTA_DOWNLOAD_DONE=512,
	MINI_SYS_DFOTA_PRE_RO_BACKUP,
	MINI_SYS_DFOTA_PRE_RO_DONE,
    MINI_SYS_DFOTA_PRE_DDR_RW_BACKUP,
    MINI_SYS_DFOTA_PRE_DDR_RW_DONE,
    MINI_SYS_DFOTA_DDR_RW_BACKUP,
    MINI_SYS_DFOTA_DDR_RW_BACKUP_OLD_DONE,
    MINI_SYS_DFOTA_DDR_RW_DONE,
    MINI_SYS_DFOTA_PS_NCAH_BACKUP,
    MINI_SYS_DFOTA_PS_NCAH_BACKUP_OLD_DONE,
    MINI_SYS_DFOTA_PS_NCAH_DONE,
    MINI_SYS_DFOTA_USBNCAH_BACKUP,
    MINI_SYS_DFOTA_USBNCAH_BACKUP_OLD_DONE,
    MINI_SYS_DFOTA_USBNCAH_DONE,
    MINI_SYS_DFOTA_CODE_PS_BACKUP,
    MINI_SYS_DFOTA_CODE_PS_BACKUP_OLD_DONE,
    MINI_SYS_DFOTA_CODE_PS_DONE,
    MINI_SYS_DFOTA_CODEPSB_BACKUP,
    MINI_SYS_DFOTA_CODEPSB_BACKUP_OLD_DONE,
    MINI_SYS_DFOTA_CODEPSB_DONE,
    MINI_SYS_DFOTA_CODE_PL_BACKUP,
    MINI_SYS_DFOTA_CODE_PL_BACKUP_OLD_DONE,
    MINI_SYS_DFOTA_CODE_PL_DONE,
    MINI_SYS_DFOTA_DSP_RF_BACKUP,
    MINI_SYS_DFOTA_DSP_RF_BACKUP_OLD_DONE,
    MINI_SYS_DFOTA_DSP_DONE,
    MINI_SYS_DFOTA_RF_DONE,
	MINI_SYS_DFOTA_FIRST_MOVE,
	MINI_SYS_DFOTA_FIRST_MOVE_DONE,
	MINI_SYS_DFOTA_SECOND_MOVE,
	MINI_SYS_DFOTA_SECOND_MOVE_DONE,
	MINI_SYS_DFOTA_DONE=1024
};


enum {
	MINI_SYS_STATUS_DISABLE,
	MINI_SYS_STATUS_ENABLE,
	MINI_SYS_STATUS_NONE
};

#ifdef QUEC_FOTA_BREAK_POINT_DOWN_LOAD_CACHE_FEATURE
/* fota recv cache msg*/
typedef enum{
	QUEC_FOTA_CACHE_RECV_IND = 0,
	QUEC_FOTA_CACHE_HTTP_IND,
	QUEC_FOTA_CACHE_FTP_IND,
	QUEC_FOTA_CACHE_HIGH_IND,
	QUEC_FOTA_CACHE_LOW_IND,
	QUEC_FOTA_CACHE_EMPTY_IND,
}QUEC_FOTA_CACHE_MSG;
#endif


struct method_download {
	char * command_key;
	char * file_type;
	char * url;
	char * username;
	char * password;
	unsigned int file_size;
	char * target_file_name;
	unsigned int delay_seconds;
	char * success_url;
	char * failure_url;
	int status; // Use trace this method result sent count
	char * start_time;// data time format
	char * complete_time;// data time format
};


struct DeviceHeader_11_tr069 {
	unsigned int DeviceFlags;
	unsigned int DeviceParameters[16];        /*  Device Parameters, reserve 16 U32 here, will be defined depending on different devices */
	FlashOptStruct  FlashOpt;
	unsigned int Reserved[MAX_RESEVERD_LEN];
	unsigned int nOfImages;        /* number of images */
	ImageStruct_11 imageStruct_11[0]; /* array of image structs */
} __attribute__((packed)); // Same as struct 'DeviceHeader_11' but the ImageStruct cnt is zero


#define FOTA_MAGIC 0X464F5441
#define ASR_FOTA_FLAG_LEN_MAX 16
#define ASR_FOTA_FILE_NAME_SIZE 8


#ifdef NEW_MINI_OTA_VERSION
#if defined(LTEONLY_8M8M) || defined(CRANEL_4MRAM)
#define MINI_OTA_MAX_NUMBER_OF_IMAGE	32
#else
#define MINI_OTA_MAX_NUMBER_OF_IMAGE	12
#endif


typedef struct _asr_mini_ota_ImageStruct{

	UINT32 ImageID;
	UINT32 ImageOffset;
	UINT32 ImageLen;
	UINT32 ImageCheckSum;

	UINT32 oldDeviceFlashAddress;
	UINT32 oldDeviceLen;
	UINT32 oldDeviceCheckSum;
	UINT32 newDeviceFlashAddress;
	UINT32 newDeviceLen;
	UINT32 newDeviceCheckSum;
	UINT32 reserved[2];

}asr_mini_ota_ImageStruct;


typedef struct _asr_mini_ota_head_info{
	UINT32 magic;
	UINT32 format_version;
	
	/*add for mini sys fota*/
	unsigned int second_flash_address;
	unsigned int second_file_size;
	unsigned int first_backup_address;
	unsigned int first_backup_len;
	unsigned int second_backup_address;
	unsigned int second_backup_len;
	unsigned int old_backup_len;
	unsigned int mini_dfota_status;
	unsigned int DFota_CopyAddr;
	unsigned int DFota_CopyFlag;
	unsigned int DFota_TempAddr;
	UINT32 reserved[2];
	
	asr_non_diff_info nonDiffInfo;
	asr_mini_ota_ImageStruct Image[MINI_OTA_MAX_NUMBER_OF_IMAGE];
	#if defined(LTEONLY_8M8M) || defined(CRANEL_4MRAM)
	UINT32 reserved2[87];
    #else
	UINT32 reserved2[327];
    #endif
	unsigned int first_flash_address;
	unsigned int first_file_size;
	unsigned int first_dfota_size;
	unsigned int second_dfota_size;
	unsigned int checksum;
}asr_mini_ota_head_info;
#endif


#ifdef SUPPORT_ADIFF_DFOTA_VERSION

enum {
	SYS_ADIFF_DFOTA_FIRST,
	SYS_ADIFF_DFOTA_SECOND
};

enum {
	SYS_ADIFF_DFOTA_STATUS_BACKUP,
	SYS_ADIFF_DFOTA_STATUS_BACKUP_OLD,
	SYS_ADIFF_DFOTA_STATUS_UPDATE
};



typedef struct _asr_ota_ImageStruct{
	UINT32 ImageID;
	UINT32 ImageOffset;
	UINT32 ImageLen;
	UINT32 ImageCheckSum;
	
	UINT32 oldDeviceFlashAddress;
	UINT32 oldDeviceLen;
	UINT32 oldDeviceCheckSum;
	UINT32 newDeviceFlashAddress;
	UINT32 newDeviceLen;
	UINT32 newDeviceCheckSum;
	UINT32 reserved[2];

}asr_ota_ImageStruct;

#define OTA_MAX_NUMBER_OF_IMAGE	32

typedef struct _asr_ota_head_info{
	UINT32 magic;
	UINT32 format_version;
	UINT32 reserved1[2];
	UINT32 uncompressed_image_num;
	UINT32 loadtable_image_num;
	UINT32 update_num;
	UINT32 update_status;
	UINT32 move_num;
	UINT32 move_ready;
	
	UINT32 first_backup_address;
	UINT32 first_backup_len;
	UINT32 old_backup_len;
	UINT32 DFota_CopyAddr;
	UINT32 DFota_TempAddr;
	UINT32 dsp_later_num;
	UINT32 app_num;
	UINT32 reserved2[1];
	asr_ota_ImageStruct Image[OTA_MAX_NUMBER_OF_IMAGE];
}asr_ota_head_info;
#endif



typedef union{
	asr_mini_ota_head_info mini_ota_head;//new mini ota
#ifdef SUPPORT_ADIFF_DFOTA_VERSION
	asr_ota_head_info ota_diffhead;//new adiff ota
#endif
	unsigned char reserved[2048];
}ASR_OTA_HEADER;

#ifdef QUEC_MINISYS_PROJECT_CUST
typedef struct _quec_url_store{
	char      path_name[256];
    unsigned char dl_urc_num;     //max number of urc when downloading
    unsigned char dl_urc_cnt;
	unsigned char down_fail_stop_open;
	unsigned char dl_first_pkg_suc;
}quec_url_store;
#endif

struct fota_firmwar_flag {
	unsigned int header;
	unsigned int upgrade_flag;
	unsigned int fbf_flash_address;
	unsigned int fbf_file_size;
	unsigned int Upgrade_Method; // 1, TR069; 2, SD; 3, WebUI.;4, DFOTA; 5;MINI System DFOTA
	unsigned int Version_Flag;
	unsigned char Version[64];
	unsigned int DFota_nOfImages;
	unsigned int DFota_NeedCopyOnly;
	unsigned int DFota_CopyLen;
	unsigned char Image_status[MAX_NUMBER_OF_IMAGE_STRUCTS_IN_DEVICE_HEADER];
	unsigned int Index;	
	
	ASR_OTA_HEADER ota_header;
#ifdef QUEC_MINISYS_PROJECT_CUST
	quec_url_store quec_url_info;
	unsigned int reserved[382];
#else
	unsigned int reserved[447];
#endif
	unsigned int checksum;
};

#if defined(DOWNLOAD_BREAKPOINT_SUPPORT)
typedef struct _mini_ota_breadkpoint_info {
	unsigned int  breadkpoint_magic; //==0xaabbccaa
	unsigned int  checksum;          //cal the image_context checksum 
	struct image_process_context image_context;
}mini_ota_breadkpoint_info;

#define MINI_BREAKPOINT_NVM_NAME "mini_bp_info.nvm"
#endif

struct fota_param {
	unsigned char fotaFlag[ASR_FOTA_FLAG_LEN_MAX];
	unsigned int baudrate_flag;
	unsigned int baudrate;
	unsigned int mini_sys_enable;
#ifdef QUEC_MINISYS_PROJECT_CUST
	unsigned int large_sys_erased_back;//´Ë±äÁ¿ÊÇÎªÁË¼æÈÝlarge_sys_erasedÎ»ÖÃ±ä»¯µÄ°æ±¾¼äÉý¼¶ÒÀÈ»ÓÐÐ§
	unsigned int reserved[63];
#else
	unsigned int reserved[64];
#endif
	#ifdef CSD_SUPPORT
	unsigned int dte_dce_format_parity_flag;
	unsigned int dte_dce_format_parity;
	#endif
	unsigned int large_sys_erased;
	UINT8 simPinCode[DUAL_SIM_PIN_CODE_SIZE];
};
/*************************************************************************
*************************************************************************/
#ifdef QUECTEL_MINIFOTA_SUPPORT

	typedef enum
	{
		DS_FTP_OK			   = 0,
		DS_FTP_ERROR		   = 601,
		DS_FTP_WOULDBLOCK	   = 602,
		DS_FTP_BUSY 		   = 603,
		DS_FTP_ERROR_DNS	   = 604,	/*failed to parse domain name*/
		DS_FTP_ERROR_NETWORK   = 605,	/*failed to establish socket or the network is deactivated*/
		DS_FTP_CTRL_CLOSE	   = 606,	/*the ftp session has been closed by the ftp server*/
		DS_FTP_DATA_CLOSE	   = 607,	/*the data connection was closed by the ftp server*/
		DS_FTP_BEARER_FAIL	   = 608,
		DS_FTP_ERROR_TIMEOUT   = 609,
		DS_FTP_INVALID_PARAM   = 610,
		DS_FTP_FILE_NOT_FOUND  = 611,
		DS_FTP_FILE_POINT_ERR  = 612,
		DS_FTP_FS_FILE_ERROR   = 613,
		DS_FTP_SERVICE_END	   = 614,
		DS_FTP_DATA_FAILED	   = 615,
		DS_FTP_CLOSE_CONN	   = 616,
		DS_FTP_FILE_UNOPER	   = 617,
		DS_FTP_REQUEST_ABORT   = 618,
		DS_FTP_OVER_MEMORY	   = 619,
		DS_FTP_COMMAND_ERROR   = 620,
		DS_FTP_PARAM_ERROR	   = 621,
		DS_FTP_COMMAND_FAILED  = 622,
		DS_FTP_COMMAND_BAD_SEQUENCE = 623,
		DS_FTP_COMMAND_NOT_IMPLENT = 624,
		DS_FTP_ERROR_UNLOGIN   = 625,
		DS_FTP_NO_ACCOUNT	   = 626,
		DS_FTP_REQUEST_FAILED  = 627,
		DS_FTP_REQUEST_STOP    = 628,
		DS_FTP_FILEREQ_STOP    = 629,
		DS_FTP_FILENAME_ERROR  = 630,
		DS_FTP_SSL_AUTH_FAIL   = 631,
	}quectel_ds_miniftp_error_code;
		

typedef enum
{
	   mTEL_AT_CMD_ATP_0,	   
	   mTEL_AT_CMD_ATP_1,	  
	   mTEL_AT_CMD_ATP_2,	  
	   mTEL_AT_CMD_ATP_3,	  
	   mTEL_AT_CMD_ATP_4,	  
	   mTEL_AT_CMD_ATP_5,	  
	   mTEL_AT_CMD_ATP_6,	  
	   mTEL_AT_CMD_ATP_7,			  
	//	 TEL_ESP_AT_CMD_ATP,		  //external serial port
	   mTEL_MODEM_AT_CMD_ATP,   // act as Modem when linked with PC
	   mNUM_OF_TEL_ATP
}
mTelAtParserID;

typedef enum
{
	QUEC_FOTA_PATH_NULL = 0,
	QUEC_FOTA_PATH_FILE,//fota by file
	QUEC_FOTA_PATH_SD,//fota by sd card
	QUEC_FOTA_PATH_MEMORY,//fota by memory
	QUEC_FOTA_PATH_HTTP,//fota by http
	QUEC_FOTA_PATH_FTP,//fota by ftp
	QUEC_FOTA_PATH_MAX,
}quec_minifota_path_e;

typedef struct qminifotaupl_param
	{
		char			  path_name[256];
		quec_minifota_path_e  data_type;	  //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ô´ï¿½ï¿½ï¿½ï¿½
		unsigned int			  upgrade_flag;   //ï¿½Ç·ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
		unsigned int			  want_size;	  //ï¿½Ú´ï¿½ï¿½Ü³ï¿½ï¿½ï¿½
		unsigned int			  size_uploaded;  //ï¿½Ä¼ï¿½ï¿½ï¿½ï¿½Í¸ï¿½fota_taskï¿½ï¿½ï¿½ï¿½
#ifdef QUEC_FOTA_HTTP_RETRY_SUPPORT
		unsigned int			  remaining_size; //Remaining size to download when http  fota retry 
#endif
		unsigned int			  cache_count;	  //ï¿½ï¿½ï¿½æ³¤ï¿½ï¿½
		unsigned int			  atHandle; 	  //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
		unsigned int			  current_dw_len; //ï¿½ï¿½Ç°ï¿½ï¿½ï¿½Ú½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý³ï¿½ï¿½ï¿½
		mTelAtParserID	  atp_index;	  //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ô´ï¿½ï¿½ï¿½ï¿½
		int	  error_code;	  //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?
		unsigned short			  fota_error_code; //fota upgrade error
#ifdef QUEC_FOTA_DOWNLOAD_URC_SUPPORT
		unsigned char			  dl_urc_num;	  //max number of urc when downloading
		unsigned char			  up_urc_num;	  //max number of urc when updating
		unsigned char			  urc_cnt;		  //urc report counter	
		unsigned int			  flash_wr_size;  //Size of data has writen to flash
		unsigned int			  flash_want_size;//Expect total size write to falsh
#endif
	
#ifdef QUEC_PROTOCOL_DOWNLOAD_FILE_FOTA
		unsigned char protocol_down_flag;
#endif
#ifdef QUECTEL_QUECFOTA_SUPPORT
		unsigned int			  quecfota_fota_flag;	//quecfota_fota_flag:1:quecfota enable.0:disable quecfota
#endif
	
	}QMINIFOTAUPL_PARAM;

	typedef struct
	{
		char			username[256];	//User name for authentication
		char			password[256];	//Password for authentication
		char			url[256];		//IP address or domain
		char			port[10];			//Port of FTP server
		char			file_path[256]; //Download file path
		char			file_name[256]; //Download file name
		int 			err_code;		//FTP FOTA error code
		unsigned int			want_size;		//Expect ftp download total size
		mTelAtParserID	atHandle;
	}ftp_minifota_info_t;
	
	/*later add new parameters ,put them to this structure*/
	typedef struct{
		char   			*ptr_url;/*qfotadl param, complete AT command parameters for comparison*/
		int    			atpIndex;
		unsigned int 	atHandle;
		unsigned char 	upgrade_mode;
		unsigned char 	urc_dl_num;
		char   			url_abort;/*Downloading, reset qfotadl param url,  1:Terminate exit*/
		char 			active_stop;/*1:stop flag*/
		struct http_client * client;
		//unsigned char	ftp_evt;
		//unsigned char	quec_urc_num;
		//unsigned char	quec_urc_cnt;
		char 			cfun_flag;/*Reconnect to the core network, EPC*/
	}quec_minios_fota_st;
	extern quec_minios_fota_st quec_minios_fota;

extern int quec_minisys_check_url(char *url, int size);
#endif


/*************************************************************************
*************************************************************************/

#ifdef QUEC_MINISYS_USEFOR_APN_ACTIVATE
typedef struct{
	char   apn[129];
	char   user_name[129];
	char   password[129];
	char   auth_type;
	char   pdp_type;/*-1:Indicates that APN is not configured, and an error is reported when executing QFOTADL*/
	char   nwscanmode;
}quec_minios_pdp_profile;
extern quec_minios_pdp_profile minios_profile_info;
#define QUEC_MINIOS_PDP_INFO_INI "minios_pdp_info.ini"
extern int quec_minisys_pdp_info_configuration_init(void);
extern int quec_minisys_get_pdp_type(void);
#endif


extern int ota_downalod_progress;

extern int ota_firmware_download_http(const char * url, const char * username, const char * psw);

extern int verify_flash_image(struct image_process_context * context, int * file_size, int * is_dfota);


int get_at_ota_progress(unsigned int requestHandle);
void init_fota(void);

unsigned int get_uart_baud_ipr(void);
int save_uart_baud_ipr(unsigned int baudRate);
int enable_mini_sys(void);
int get_mini_sys_status(struct fota_firmwar_flag * flag);
#ifdef QUEC_MINISYS_PROJECT_CUST
int disable_mini_sys(void);
#endif
extern BOOL IsMiniSystem(void);

void quec_minisys_usb_vid_pid_init(void);


/*******************************************************************************
*
* Function:        fota_pkg_write
*
* Parameters: 
*   data           - the fota file data
*   dataLen        - the fota file data length
*   total          - the total size of fota file,if using ADIFF PRO fota solution,this parameter must be set.
*
* Returns:          
*   FOTA_SUCCESS               - OK
*   FOTA_INTERNAL_ERR          - Fota file write failed
*
* Description:      *  This function write the fota file to flash
*                      
*
*********************************************************************************/
int fota_pkg_write(char * data, int dataLen, int total);

/*******************************************************************************
*
* Function:        fota_pkg_flush_flash
*
* Parameters:      none
*
* Returns:          
*   FOTA_SUCCESS               - OK
*   FOTA_INTERNAL_ERR          - Fota file flush failed
*
* Description:      *  If the fota file size not 64K alignment,
*                      this function flush the rest data to flash
*
*********************************************************************************/

int fota_pkg_flush_flash(void);


/*******************************************************************************
*
* Function:        fota_image_verify
*
* Parameters:      none
*
* Returns:          
*   FOTA_SUCCESS               - OK
*   FOTA_FILE_CHECK_ERR        - Fota file verify failed
*
* Description:      *  This function verify the fota file is correct or not
*                      if the file is correct,the fota flag will be set
*
*********************************************************************************/
int fota_image_verify(void);


/*******************************************************************************
*
* Function:        mini_fota_pkg_write
*
* Parameters: 
*   data           - the mini fota file data
*   dataLen        - the mini fota file data length
*   size           - the total size of mini fota file
*
* Returns:          
*   FOTA_SUCCESS               - OK
*   FOTA_INTERNAL_ERR          - Fota file write failed
*
* Description:      *  This function write the mini fota file to flash
*                      
*
*********************************************************************************/
int mini_fota_pkg_write(char * data, int dataLen, int size);


/*******************************************************************************
*
* Function:        mini_fota_image_verify
*
* Parameters:      none
*
* Returns:          
*   FOTA_SUCCESS               - OK
*   FOTA_FILE_CHECK_ERR        - Fota file verify failed
*
* Description:      *  This function verify the mini fota file is correct or not
*                      if the file is correct,the fota flag will be set
*
*********************************************************************************/
int mini_fota_image_verify(void);

#ifdef QUECTEL_PROJECT_CUST
int quec_fullfota_app_work(void);
#endif

#endif
