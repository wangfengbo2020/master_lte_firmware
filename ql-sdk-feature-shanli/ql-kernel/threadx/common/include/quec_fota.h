/**  @file
  quec_fota.h

  @brief
  This file is used to define the fota for different Quectel Project.

*/

/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/

/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
01/15/2019        Jensen     	 add recover counter for fota pkg, add header check for image info
12/18/2018        Jensen     	 Init version
=================================================================*/


#ifndef _QUEC_FOTA_H
#define _QUEC_FOTA_H

/*> include header files here*/
#include "Errors.h"
//#include "download.h"
#include "FlashPartition.h"
#include "quec_cust_feature.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined QUEC_FOTA_SUPPORT

/*========================================================================
 *  Macro Definition
 *========================================================================*/
#define QUEC_FOTA_PKG_MAX	4//最多支持的升级文件数 
#define QUEC_MAX_NUMBER_OF_IMAGE_STRUCTS_IN_DEVICE_HEADER  150


#define QUEC_FOTA_BYTE_LEN	32
#define QUEC_FOTA_BYTE_STR	"QuecFota"

#define QUEC_IMAGE_INFO_BYTE_LEN	16//max len of header for image info
#define QUEC_IMAGE_INFO_BYTE_STR	"QuecINFO"//header for image info


//最高位为1代表URC已上报。如0x83代表QUEC_FOTA_FAILED已上报，0x82代表QUEC_FOTA_SUCCESS已上报
#define QUEC_FOTA_RESULT_URC_MASK 0x80 
#define QUEC_FOTA_FAILED	3//升级失败
#define QUEC_FOTA_SUCCESS	2//升级成功
#define QUEC_FOTA_ENABLE	1//允许升级，一般在fota包下载后更新为该值 
#define QUEC_FOTA_DISABLE	0//默认值 

#define QUEC_FOTA_DIFF_IMAGE_ENABLE 0//是否支持差分升级 

#define QUEC_FOTA_MD5_CHECK_ENABLE	1//是否要求MD5校验 

#define QUEC_MD5_BYTE_LEN	16
#define QUEC_FOTA_MD5_BYTE_LEN	QUEC_MD5_BYTE_LEN//MD5值长度 

#define QUEC_FOTA_PKG_FULL_IMAGE 1//FOTA包为完整包 
#define QUEC_FOTA_PKG_DIFF_IMAGE 0//FOTA包为差分包 

#define QUEC_FOTA_EXEC_IMAGE_VALID 1//当前加载使用的程序包有效
#define QUEC_FOTA_EXEC_IMAGE_INVALID 0//当前加载使用的程序包无效

#define QUEC_MODULUS_OPERATION(a,b) ((a) & (b-1)) //快速取模运算 b为2的倍数


#define QUEC_FOTA_HEADER_MAX_LEN 2048
#define QUEC_FOTA_FLASH_SECTOR_SIZE 2048

#define QUEC_IMAGE_INFO_FILE_SIZE (2048)
#define QUEC_IMAGE_CHECK_VERSION  (0)

/*========================================================================
 *  Enumeration Definition
 *========================================================================*/
typedef enum
{
	QUEC_FOTA_GENERAL_ERROR = -100,

	QUEC_FOTA_IMAGE_TYPE_ERROR,//FOTA包类型错误，应为完整包或者差分包
	QUEC_FOTA_DIFF_IMAGE_NOTSUPPORT,//FOTA差分包格式不支持
		
	QUEC_FOTA_CRC32_CALCULATE_ERROR,//CRC32计算错误
	QUEC_FOTA_CRC32_CHECK_ERROR,//CRC32校验错误
	QUEC_FOTA_MD5_CALCULATE_ERROR,//MD5计算错误
	QUEC_FOTA_MD5_CHECK_ERROR,//MD5校验错误
	QUEC_FOTA_HEADER_CHECK_ERROR,//常量字节头检验错误
		
	QUEC_IMAGEINFO_NONE,//没有当前加载使用的程序包信息
	QUEC_IMAGEINFO_READ_ERROR,//当前加载使用的程序包信息读取错误
	QUEC_IMAGEINFO_BACKUP_READ_ERROR,//当前加载使用的程序包信息备份区读取错误
	QUEC_IMAGEINFO_WRITE_ERROR,//加载使用的程序包信息回写错误
	QUEC_IMAGEINFO_ERASE_ERROR,//加载使用的程序包信息擦除错误
	QUEC_IMAGEINFO_PARSE_ERROR,//加载使用的程序包信息解析错误
	QUEC_IMAGEINFO_LINE_PARSE_ERROR,//加载使用的程序包信息行解析错误
	QUEC_IMAGEINFO_ITEM_PARSE_ERROR,//加载使用的程序包信息项解析错误
	QUEC_IMAGEINFO_HEADER_CHECK_ERROR,//加载使用的程序包信息头字符串检验错误
	QUEC_IMAGEINFO_MD5_CHECK_ERROR,//加载使用的程序包信息MD5检验错误

	QUEC_FOTA_FLAG_READ_ERROR,//FOTA升级标志区读取错误
	QUEC_FOTA_FLAG_WRITE_ERROR,//FOTA升级标志区回写错误
	QUEC_FOTA_FLAG_ERASE_ERROR,//FOTA升级标志区擦除错误
	QUEC_FOTA_FLAG_INDEX_ERROR,//FOTA升级标志包序号错误
	QUEC_FOTA_FLAG_INDEX_MISMATCH,//FOTA升级标志程序包序号不匹配
	QUEC_FOTA_FLAG_INDEX_NOTSUPPORT,//FOTA升级标志程序包序号不支持
	
	QUEC_FOTA_SRC_IMAGE_LEN_ERROR,//FOTA升级程序包长度错误
	QUEC_FOTA_SRC_IMAGE_NOT_FULL_ERROR,//FOTA升级程序包错误：不是完整包
	QUEC_FOTA_SRC_IMAGE_UNCOMPRESSED_ERROR,//FOTA升级程序包错误：未压缩
	QUEC_FOTA_SRC_IMAGE_DECOMPRESS_ERROR,//FOTA升级程序包解压错误
	QUEC_FOTA_SRC_IMAGE_DECOMPRESS_LEN_ERROR,//FOTA升级程序包解压后长度错误
	QUEC_FOTA_SRC_IMAGE_READ_ERROR,//FOTA升级程序包读取错误
	QUEC_FOTA_SRC_IMAGE_WRITE_ERROR,//FOTA升级程序包写错误
	QUEC_FOTA_SRC_IMAGE_ERASE_ERROR,//FOTA升级程序包擦除错误
	QUEC_FOTA_SRC_IMAGE_CHECK_ERROR,//FOTA升级程序包校验错误
	
	QUEC_FOTA_DST_IMAGE_READ_ERROR,//用于加载使用的程序包读取错误（包括升级前后）
	QUEC_FOTA_DST_IMAGE_WRITE_ERROR,//用于加载使用的程序包更新错误
	QUEC_FOTA_DST_IMAGE_ERASE_ERROR,//用于加载使用的程序包擦除错误
	QUEC_FOTA_DST_IMAGE_CHECK_ERROR,//用于加载使用的程序包校验错误
	
	QUEC_FOTA_NOERROR = 0,
	QUEC_FOTA_GENERAL_SUCESS = QUEC_FOTA_NOERROR,
	
	QUEC_FOTA_WAIT_TO_UPGRADE = 90,//FOTA程序包待升级，一般在fota包下载后更新为该值
	QUEC_FOTA_UPGRADE_SUCCESS = 100,//FOTA程序包升级成功
}quec_fota_internal_result;

typedef enum
{
	QUEC_FOTA_CODE_NOERROR = 0,
	QUEC_FOTA_CODE_GENERAL_SUCESS = QUEC_FOTA_CODE_NOERROR,
	
	QUEC_FOTA_CODE_GENERAL_ERROR = 500,
	QUEC_FOTA_CODE_NULL_POINTER,
	QUEC_FOTA_CODE_LEN_ERROR,

	QUEC_FOTA_CODE_UPGRADE_FAILED = 504,

	QUEC_FOTA_CODE_FILE_CHK_FAILED = 505,
	QUEC_FOTA_CODE_MD5_CHECK_ERROR,
	QUEC_FOTA_CODE_FILE_NUM_CHECK_ERROR,
	QUEC_FOTA_CODE_FILE_START_CHECK_ERROR,
	QUEC_FOTA_CODE_FILE_INFO_CHECK_ERROR,
	QUEC_FOTA_CODE_HEADER_CHECK_ERROR,
	
	QUEC_FOTA_CODE_FLASH_ERASE_ERROR = 511,
	QUEC_FOTA_CODE_FLASH_WRITE_ERROR,
	QUEC_FOTA_CODE_FLASH_READ_ERROR,

    QUEC_FOTA_CODE_RECV_TASK_ERROR = 514,
	QUEC_FOTA_CODE_WRITE_TASK_ERROR = 515,

	QUEC_FOTA_PKG_FILE_WRITE_ERROR = 535,
	QUEC_FOTA_PKG_FILE_HANDLE_ERROR = 536,
	QUEC_FOTA_FILE_SYSTEM_SPACE_NOT_ENOUGH = 537,

	QUEC_FOTA_NO_MEMORY_ERROR  = 545,   //! Not enough memory was available to perform the operation.

#ifdef QUEC_PROTOCOL_DOWNLOAD_FILE_FOTA
	QUEC_FOTA_CODE_PDL_GENERAL_ERROR= 550,
	QUEC_FOTA_CODE_PDL_HOST_CMD_ERROR = 551,
	QUEC_FOTA_CODE_URL_INVALIED = 552,
#endif
}quec_fota_error_code_e;

//FOTA包类型
typedef enum
{
	QUEC_IMAGE_NULL = 0,
	QUEC_IMAGE_CP,//SDK, modem程序
	QUEC_IMAGE_MSA,//DSP程序
	QUEC_IMAGE_RF,//RF参数 
	QUEC_IMAGE_MAX
}quec_fota_image;

//MD5值类型
typedef enum
{
	QUEC_FOTA_PKG_MD5_NULL = 0,//无MD5加密
	QUEC_FOTA_PKG_MD5_BINARY = 2,//二进制MD5 
	QUEC_FOTA_PKG_MD5_HEX = 16,//16进制MD5 
	QUEC_FOTA_PKG_MD5_MAX,
}quec_fota_md5_type;

typedef enum
{
	QUEC_FOTA_PKG_UNCOMPRESSED = 0, //原包为非压缩格式，FOTA包为非压缩格式，即原始文件，目标包为非压缩格式，不需要压缩 
	QUEC_FOTA_PKG_TO_COMPRESSED,	//原包为非压缩格式，FOTA包为压缩 格式，需要进行压缩，目标包为非压缩格式 
	QUEC_FOTA_PKG_BE_COMPRESSED,	//原包为压缩格式，FOTA包为压缩 格式，目标包为压缩格式 
	QUEC_FOTA_PKG_COMPRESSED_MAX,
}quec_fota_compressed_option;

typedef struct
{
    unsigned char quec_file_md5[QUEC_MD5_BYTE_LEN];
    int check_version;
}quec_check_info_s;

/*========================================================================
 *  Type Definition
 *========================================================================*/
//用于加载使用的程序包信息
typedef struct
{
	unsigned char quec_pkg_header_bytes[QUEC_IMAGE_INFO_BYTE_LEN];//常量串校验
	int	quec_pkg_info_index;//见FOTA包类型quec_fota_image
	int quec_pkg_recover_state;
	int quec_pkg_recover_cnt;//fota包用来恢复为加载程序包的次数
	int	quec_pkg_info_len[2];//第一个len表示FOTA包长度，如果是压缩格式，为压缩后的长度；第二个len表示MD5加密使用的源文件长度，如果是压缩格式，则为压缩前的文件长度
	int	quec_pkg_info_compressed;//FOTA包是否是压缩格式 
	int	quec_pkg_info_fota_type;//FOTA类型，整包升级，还是差分升级 
	int	quec_pkg_info_md5_type;//MD5值类型，见quec_fota_md5_type
	unsigned char  quec_pkg_info_md5[QUEC_FOTA_MD5_BYTE_LEN];//MD5值
} quec_fota_pkg_info_s;

//FOTA升级标志
typedef struct
{
	int	quec_fota_upgrade_state;//FOTA升级状态，是否允许升级或者升级结果
	int	quec_fota_pkg_num;//FOTA升级程序包数
	int	quec_fota_pkg_result[QUEC_FOTA_PKG_MAX];//每个FOTA升级程序包的升级结果
	quec_fota_pkg_info_s quec_fota_pkg_info[QUEC_FOTA_PKG_MAX];//每个FOTA升级程序包信息
} quec_fota_info_s;

struct tr069_firmwar_flag {
	unsigned int header;
	unsigned int upgrade_flag;
	unsigned int fbf_flash_address;
	unsigned int fbf_file_size;
	unsigned int erase_psm;
	unsigned int erase_psm_address;
	unsigned int erase_psm_size;
	unsigned int Erase_FS;
	unsigned int FS_Erase_Address;
	unsigned int FS_Erase_Size;
	unsigned int Upgrade_Method; // 1, TR069; 2, SD; 3, WebUI.;4, DFOTA
	unsigned int Webdata_LZMA2;
	unsigned int Webdata_Address;
	unsigned int Webdata_Size;
	unsigned int WIFI_NoCal_LZMA2;
	unsigned int WIFI_NoCal_Address;
	unsigned int WIFI_NoCal_Size;
	unsigned int WIFI_LAMA2;
	unsigned int WIFI_Address;
	unsigned int WIFI_Size;
	unsigned int Version_Flag;
	unsigned char Version[64];
    /*AT$MYDOWNLOAD to contrl USB Download mode for TIGX*/
	unsigned int download_flag;
	/*AT+IPR to contrl uart2 send 'RDY' for TIGX*/
	unsigned int uart2_baudrate_flag;
	unsigned int uart2_baudrate;
	unsigned int DFota_nOfImages;
	unsigned int DFota_NeedCopyOnly;
	unsigned int DFota_CopyLen;
};

typedef struct tr069_firmwar_flag tr069_firmwar_flag_s;
typedef struct
{
	tr069_firmwar_flag_s quec_TR069_Firmware;//与ASR的tr069使用同一个FOTA升级标志区，保留tr069的升级标志
	char quec_fota_bytes[QUEC_FOTA_BYTE_LEN];//常量串校验
	quec_fota_info_s quec_fota_info;//Quectel升级标志区
} quec_fota_s;


//fota包中的文件信息 
typedef struct
{
	int	quec_file_index; //程序包序号 
	int	quec_file_start; //程序包在fota文件中的起始位置
	int	quec_file_len;  //程序包在fota文件中的长度 
}quec_file_info_s; 
 
typedef struct
{
	unsigned char 	quec_header_md5[QUEC_FOTA_MD5_BYTE_LEN];//头信息区MD5值，不包含本字段
	int	quec_fota_total_size;//整个fota包的大小
	int	quec_fota_file_num;//fota包中的文件数 
	quec_file_info_s quec_fota_file_info[QUEC_FOTA_PKG_MAX];//fota包中的文件信息 
	quec_fota_info_s quec_fota_info;//Quectel升级标志区
} quec_fota_header_s;


/*
struct fota_firmwar_flag {
	unsigned int header;
	unsigned int upgrade_flag;
	unsigned int fbf_flash_address;
	unsigned int fbf_file_size;
	unsigned int Upgrade_Method; // 1, TR069; 2, SD; 3, WebUI.;4, DFOTA
	unsigned int Version_Flag;
	unsigned char Version[64];
	unsigned int DFota_nOfImages;
	unsigned int DFota_NeedCopyOnly;
	unsigned int DFota_CopyLen;
	unsigned char Image_status[QUEC_MAX_NUMBER_OF_IMAGE_STRUCTS_IN_DEVICE_HEADER]; // Quectel 
	unsigned int Index;
	unsigned int checksum;
};*/
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
	
		
		UINT32 reserved[6];
	
	}asr_non_diff_info;

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
		asr_ota_ImageStruct Image[32];
	}asr_ota_head_info;

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
		asr_mini_ota_ImageStruct Image[12];
	}asr_mini_ota_head_info;

typedef union{
		asr_mini_ota_head_info mini_ota_head;//new mini ota
#ifdef SUPPORT_ADIFF_DFOTA_VERSION
		asr_ota_head_info ota_diffhead;//new adiff ota
#endif
		unsigned char reserved[2048];
	}ASR_OTA_HEADER;

#ifdef QUEC_PROTOCOL_DOWNLOAD_FILE_FOTA
typedef struct _quec_url_store{
	char	  path_name[256];
	unsigned char dl_urc_num;	  //max number of urc when downloading
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
	unsigned char Image_status[150];
	unsigned int Index;	
	
	ASR_OTA_HEADER ota_header;
#ifdef QUEC_PROTOCOL_DOWNLOAD_FILE_FOTA
	quec_url_store quec_url_info;
	unsigned int reserved[382];
#else
	unsigned int reserved[447];
#endif
	unsigned int checksum;
};


/******************************************************************
*	 Functions
******************************************************************/
//初始化全局的 md5 state 变量
void quec_fota_md5_init(void);
//分块更新md5信息
void quec_fota_update_md5(const unsigned char *data_ptr, int data_len);
//输出最后的md5信息
void quec_fota_update_md5_finish(unsigned char *header_md5);
//Fota包头信息区解析和检验
int quec_fota_pkg_header_check(char * p_header);
//Fota升级标志区数据有效性检查
int quec_fota_pkg_header_check(char * p_header);
//Fota升级标志区读取
int quec_fota_flag_read(quec_fota_info_s * p_fota_info);
//Fota升级标志区保存
int quec_fota_flag_write(char * p_fota_flag, int blk_size);
//Fota包中的程序文件保存
int quec_fota_file_write(unsigned int flash_addr, char * p_file_data, int data_len, int blk_size);

//fota update flag for ASR_fota write
int  quec_fota_write_ASR_update_flag(void);

// fota update flag write
int quec_fota_write_update_flag(void);
// fota包系入到文件系统，保存到file里
int quec_fota_pkg_write_file(unsigned int flash_addr, char * p_file_data, int data_len, int blk_size);

//Fota升级标志设置URC上报标志失效
int quec_fota_flag_set_urc_mask(void);

//read the imageinfo block
int quec_imageinfo_read(char * p_imageinfo, int size);
void quec_imageinfo_md5_calculate(unsigned char *data, int data_len, unsigned char *md5_out);

#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif


