/**  @file
  quec_file_interface.h

  @brief
  This file is used to define the file at command interface for different Quectel Project.

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
------------     -------     ---------------------------------------
11/30/2018        West     Init version
=================================================================*/
#ifndef QUEC_FILE_INTERFACE_H
#define QUEC_FILE_INTERFACE_H

/*========================================================================
 *  Include Header Files
 *========================================================================*/
#include "quec_include.h"


#ifdef __cplusplus
extern "C" {                             /* C++ SUPPORT                 */
#endif

#ifdef QUEC_FILE_API

/*========================================================================
*  Macro Definition
*========================================================================*/
/* To fix QC1071 */
/* 80 bytes for filename max */
#define QUEC_FILENAME_AT_INPUT_MAX_LEN_NONE_UFS (80)
#define QUEC_FILE_PREFIX_LEN (4)

/* 80 bytes for filename max, 4 bytes for "UFS:" */
#define QUEC_FILE_FILENAME_MAX_LEN     (QUEC_FILENAME_AT_INPUT_MAX_LEN_NONE_UFS+QUEC_FILE_PREFIX_LEN)
#define QUEC_FILE_MAX_PATH_LEN         (QUEC_FILE_FILENAME_MAX_LEN * 2)

#define QUEC_FILE_WILDCARD_CHAR "*"      /* wildcard multi char          */
#define QUEC_FILENAME_HEAD_FLAG "_QUEC"  /* user creater filename head   */
#define QUEC_FILENAME_HEAD_FLAG_LEN (5)  /* length of suffix */

 #define O_RDONLY 0x0001                 /* Open: Read only             */
 #define O_WRONLY 0x0002                 /* Open: Write only            */
 #define O_RDWR   0x0003                 /* Open: Read/Write            */
 #define O_CREAT  0x0100                 /* Open: Create file           */
 #define O_TRUNC  0x0200                 /* Open: Truncate file         */
 #define O_EXCL   0x0400                 /* Open: Exclusively           */
 #define O_APPEND 0x0800                 /* Open: For append            */

 #define SEEK_SET 0                      /* Seek from start of file     */
 #define SEEK_CUR 1                      /* Seek from current position  */
 #define SEEK_END 2                      /* Seek from end of file       */

/*File type handle identification*/
#define QFILE_HANDLE_FD_MASK            0x00FFFFFF
#define QFILE_HANDLE_ID_MASK            0xFF000000
#define QFILE_HANDLE_RAM_ID             0x10000000
#define QFILE_HANDLE_UFS_ID             0x11000000
#define QFILE_HANDLE_SD_ID              0X12000000
#define QFILE_HANDLE_EFS_ID             0X14000000
#if defined(QUECTEL_SFS_FILE)
#define QFILE_HANDLE_SFS_ID             0X18000000
#endif

/*========================================================================
 *  Type Definition
 *========================================================================*/
/* file operation cmd */
typedef  enum
{
    QFILE_MIN_CMD = -1,
    QFILE_MOV_CMD,
    QFILE_GET_OPENFILE_CMD,             /* get opened file              */
#if defined(__QUEC_OEM_VER_XGD__)
    QFILE_GTFCLOSE_CMD,                 /* XGD get opened file          */
    QFILE_GTFWRITE_CMD,                 /* XGD write file               */
    QFILE_GTFSIZE_CMD,                  /* XGD get file size            */
#endif    
    QFILE_OPENONEFILE_CMD,              /* open file                    */
    QFILE_CLOSEFILE_CMD,                /* close file                   */
    QFILE_GET_FILEPOSITION_CMD,         /* get file position            */
    QFILE_FFLUSH_CMD,
    QFILE_FTUCAT_CMD,                   /* ftruncate file               */
    QFILE_FSEEK_CMD,                    /* fseek file                   */
    QFILE_FREAD_CMD,                    /* read file                    */
    QFILE_FWRITE_CMD,                   /* write file                   */
    QFILE_FDEL_CMD,                     /* delete file                  */
    QFILE_FLDS_CMD,                     /* lds file info                */
    QFILE_FLST_CMD,                     /* lst file info                */
	QFILE_FSEND_CMD,					/* send file to interface		*/
	QFILE_RENAME_CMD,                   /* file rename                  */   
	QFILE_QFSIZE_CMD,                  /*  get file size            */
    QFILE_CLEAR_FLAG_CMD,
    QFILE_CLOSEDELFILE_CMD,
    QFILE_ACDBLOAD_SYNC_CMD,
    QFILE_ACDBLOAD_OPEN_CMD,
    QFILE_ACDBLOAD_WRITE_CMD,
    QFILE_ACDBLOAD_READ_CMD,
    QFILE_ACDBLOAD_ABORT_CMD,
    QFILE_ACDBLOAD_LIST_CMD,
    QFILE_ACDBDLOAD_DELETE_CMD,
    QFILE_ERROR_CMD,                   /* occur error                   */
    QFILE_MAX_CMD
}qfile_cmd_e_type;

/* file storage type */
/*g_quecFileOptStructArray  QF_FILETYPE , The two definitions must be in the same order*/
typedef enum
{
      FILE_UFS = 0,              /* ufs          */
	  FILE_SFS, 				 /* sfs 		 */
	  FILE_SD,                   /* sd           */
      FILE_RAM,                  /* ram          */
      FILE_EFS,                  /* efs          */
    FILE_MAX
}QF_FILETYPE;

typedef enum
{
    QFILE_UFS_INFORMATION   = 0,        /* UFS information            */
	QFILE_SPACE_INFORMATION             /* storage space information  */
}qfile_storage_info;

typedef enum
{
	QFILE_LIST_SINGLE_FILE  = 0,        /* qflist single file info    */
	QFILE_LIST_ALL_FILE                 /* qflist all file info       */
}qfile_list_type;

typedef enum
{
	QFILE_DELE_SINGLE_FILE  = 0,        /* qfile delete single file info    */
	QFILE_DELE_ALL_FILE                 /* qfile delete all file info       */
}qfile_dele_type;

typedef enum
{
	QFILE_FSEEK_DEFAULT     = 0,        /* move position to the beginning of the file*/
	QFILE_FSEEK_SEEK_SET,	            /* Move forward from the current position of the pointer */
	QFILE_FSEEK_SEEK_CUR                /* Moving forward from the tail */
}qfile_fseek_whence;

typedef struct
{
    char file_name[QUEC_FILE_FILENAME_MAX_LEN];
    char mode;
}QFILE_INFO;

typedef struct
{
    int     fd;
    uint32  offset;
    uint32  position;
	uint32  total_size;
}FSEEK_PARA;

typedef struct
{
    char    fdwl_flag;
    uint32  bytes_need;
    int8    file_name[QUEC_FILE_FILENAME_MAX_LEN];
    uint8   end;
    uint32  bytes_total;
}FREAD_PARA;

typedef struct
{
    char    fupl_flag;
    uint32  write_total;
    char    file_name[QUEC_FILE_FILENAME_MAX_LEN];
    int32   bytes_left;
    char    end;
    uint32  rx_input_timeout;
    bool    ack_mode;
}FWRITE_PARA;

typedef struct
{
    uint8   ufs_def;
    char    flds_file_path[QUEC_FILE_MAX_PATH_LEN];
}FLDS_PARA;

typedef struct
{
    char    flst_file_path[QUEC_FILE_MAX_PATH_LEN];
	uint8   first_list;
    uint8   type;
}FLST_PARA;

typedef struct
{
    char    fdel_file_path[QUEC_FILE_MAX_PATH_LEN];
	uint8   first_delete;
    uint8   type;
}FDEL_PARA;

typedef struct
{
    char    *file_path_old;
    char    *file_path_new;
}FRENAME_PARA;

#if defined(__QUEC_OEM_VER_XGD__)
typedef struct
{
    char    *data;
    int     fd;
}GTFWRITE_PARA;

typedef struct
{
    int     fd;    
}GTFSIZE_PARA;
#endif

typedef struct
{
    TelAtParserID       atp_index;
    uint32              atHandle;
    qfile_cmd_e_type    cmd_id;
    QF_FILETYPE         file_type;
    union
    {
        QFILE_INFO      file_info;
        int32           fd;
        FSEEK_PARA      fseek_para;
        FREAD_PARA      fread_para;
        FWRITE_PARA     fwrite_para;
        FDEL_PARA       fdel_para;
        FLDS_PARA       flds_para;
        FLST_PARA       flst_para;
        FRENAME_PARA    frename_para;
    #if defined(__QUEC_OEM_VER_XGD__)
        GTFWRITE_PARA   gtfwrite_para;
        GTFSIZE_PARA    gtfsize_para;
    #endif
    }cmd_info;   
}QFILE_CMD_TYPE;

typedef struct storage_info
{
    uint32  free_size;
    uint32  total_size;
    uint32  maxalloc_size;
}STORAGE_INFO;

typedef struct ufs_file_info
{
	uint32 ufs_file_size;       /* the size of all files in ufs      */
	uint32 ufs_file_number;     /* the number of files in ufs        */
}UFS_FILE_INFO;

/*attention : when open file, the second param is char* type, not int type */
typedef int32  (*openHandler)(const int8 *path, char *open_mode);
typedef int32  (*readHandler)(int32 fileHandle, int8 *read_buf, int32 buf_size);
typedef int32  (*writeHandler)(int32 fileHandle, int8 *write_buf, int32 buf_size);
typedef int32  (*closeHandler)(int32 fileHandle);
typedef int32  (*seekHandler)(int32 fileHandle, int32 offset, int32 whence);
typedef int32  (*delHandler)(uint8 *filename);
typedef int32  (*checkFileExistHandler)(uint8 *filename);
typedef uint64 (*getFreeSizeHandler)(void);
typedef int64  (*getFileSizeHandler)(int32 fileHandle);
typedef int64  (*getFileSizeHandlerByName)(uint8 *filename);
typedef int32  (*getStorageInfoHandler)(STORAGE_INFO *storage_info);
typedef int32  (*getAllFileInfoHandler)(UFS_FILE_INFO *file_info);
typedef int32  (*seekFileHandler)(int32 fileHandle, int32 offset, int32 whence);
typedef int32  (*truncateHandler)(int32 fileHandle, int32 length);
typedef int32  (*getpositionHandler)(int32 fileHandle);

typedef struct FileType
{
    QF_FILETYPE                 fileType;
    openHandler                 openFunc;
    closeHandler                closeFunc;
    readHandler                 readFunc;
    writeHandler                writeFunc;
    delHandler                  delFunc;
    checkFileExistHandler       checkFileExistFunc;
    getFreeSizeHandler          getFreeSizeFunc;
    getFileSizeHandler          getFileSizeFunc;
    getFileSizeHandlerByName    getFileSizeByNameFunc;
    getStorageInfoHandler       getStorageInfoFunc;
    getAllFileInfoHandler       getAllFileInfoFunc;
    seekFileHandler             seekFileFunc;
    truncateHandler             truncateFunc;
	getpositionHandler          getpositionFunc;
}QFileStructure;

/*========================================================================
 *  Function Declaration
 *========================================================================*/
/* errno get and set */
void quec_file_set_last_errno(int errno);
int quec_file_get_last_errno(void);

/* file operation function */
int32 quec_ufs_file_open(const char *file_name, char *open_mode);
int32 quec_ufs_file_read(int32 file_handler, void *read_buf, size_t read_size);
int32 quec_ufs_file_write(int32 file_handler, const void *write_buf, size_t write_size);
int32 quec_ufs_file_close(int32 file_handler);
int32 quec_ufs_file_seek(int32 file_handler, int32 offset, int32 whence);
int32 quec_ufs_file_delete(uint8 *file_name);
int32 quec_ufs_file_is_exist(uint8 *file_name);
uint64 quec_ufs_storage_freespace_get(void);
int64 quec_ufs_file_size_get_by_handler(int32 file_handler);
int64 quec_ufs_file_size_get_by_name(uint8 *file_name);
int32 quec_ufs_storage_info_get(STORAGE_INFO *storage_info);
int32 quec_ufs_all_file_info_get(UFS_FILE_INFO *file_info);
int32 quec_ufs_file_truncate(int32 file_handler, int32 length);
int32 quec_ufs_file_position_get(int32 file_handler);
QFileStructure *quec_file_opt_struct_get(QF_FILETYPE file_type);

/* file queue operation */
QuecOSStatus quec_file_queue_init(void);
QuecOSStatus quec_file_queue_put(QFILE_CMD_TYPE * cmd_ptr);
QuecOSStatus quec_file_queue_put_cmd(QFILE_CMD_TYPE *cmd_ptr);
QuecOSStatus quec_file_queue_get(QFILE_CMD_TYPE *cmd_ptr);
QuecOSStatus quec_file_delete_queue(quec_queue_t *rx_queue);

uint32 quec_file_queue_cnt_get(void);
bool quec_file_queue_is_empty(void);

/* file flag operation */
QuecOSStatus quec_file_flag_init(void);
QuecOSStatus quec_file_flag_wait(void);
QuecOSStatus quec_file_flag_release(void);

/* file read timer opration */
QuecOSStatus quec_file_read_timer_create(void);
QuecOSStatus quec_file_read_timer_start(uint32 init_time, bool cyclical_enable, void(* callback_routine)(uint32), uint32 timer_argc);
QuecOSStatus quec_file_read_timer_stop(void);
bool quec_file_read_timer_is_alive(void);
bool quec_file_read_timer_is_exist(void);
QuecOSStatus quec_file_read_timer_delete(void);

/* file write timer opration */
QuecOSStatus quec_file_write_timer_create(void);
QuecOSStatus quec_file_write_timer_start(uint32 init_time, bool cyclical_enable, void(* callback_routine)(uint32), uint32 timer_argc);
QuecOSStatus quec_file_write_timer_stop(void);
QuecOSStatus quec_file_write_timer_delete(void);
bool quec_file_write_timer_is_exist(void);

/* file mutex operation */
QuecOSStatus quec_file_lock_create(quec_mutex_t *    	   mutex);
QuecOSStatus quec_file_lock(quec_mutex_t 	    mutex);
QuecOSStatus quec_file_trylock(quec_mutex_t 		 mutex);
QuecOSStatus quec_file_unlock(quec_mutex_t  	   mutex);
QuecOSStatus quec_file_lock_delete(quec_mutex_t     	   mutex);

/* Upload/Downloader calculate checksum */
uint16 file_CalcCheckSum(uint16 *checksum, uint16 *odd_tmp, uint8 *odd_flag, uint8 *buffer, uint16 size, bool bend);

/* file upgrade status */
void quec_file_upgrade_status_set(bool status);
bool quec_file_upgrade_status_get(void);
void quec_file_upgrade_wm_status_set(bool status);
bool quec_file_upgrade_wm_status_get(void);


void quec_file_write_atp_index_set(TelAtParserID index);
TelAtParserID quec_file_write_apt_index_get(void);




/* add filename filter */
bool  quec_filename_filter(char *file_name);
int   quec_add_filename_suffix_flag(char *ptr_char);
char *quec_delete_filename_suffix_flag(char *file_name);


extern int32 quec_judge_file_path_type(char **pfile);
extern uint32 quec_file_get_actual_fat_size(uint32 file_size);
#ifdef QUECTEL_SFS_FILE
int32 quec_sfs_file_write(int32 file_handler, const void *write_buf, size_t write_size);
int32 quec_sfs_file_read(int32 file_handler, void *read_buf, size_t read_size);
int64 quec_sfs_file_size_get_by_handler(int32 file_handler);
int32 quec_sfs_file_position_get(int32 file_handler);
QF_FILETYPE quec_file_get_fileType(int32 hid);
void quec_sfs_key_init(void);
#endif
QF_FILETYPE getFileType(char	*filename);

signed int Quectel_FileOpen(INT8 *path, INT32 flag);

INT32 Quectel_FileClose(INT32 fileHandle);

INT32 Quectel_FileRead(int32 fileHandle, int8 *buf, uint32 bufSize);

INT32 Quectel_FileWrite(INT32 fileHandle, INT8 *buf, UINT32 bufSize);

INT32 Quectel_FileGetSize(INT8 *path ,INT32 *size);

INT32 Quectel_FileisExist(char *path);

INT32 Quectel_FileGetPositon(INT32 fileHandle);

INT32 Quectel_FileDel(char *path);

INT32 Quectel_FileSize(INT32 fileHandle, INT32 *size);

INT32  Quectel_FileTrunck(INT32 fileHandle, int32 length); //底层无接口暂未实现，先封装
INT32 Quectel_FileSeek(INT32 fileHandle, INT32 offset, INT32 whence);


#endif                                  /* QUEC_AT_FILE_CMD         */
#ifdef __cplusplus                      /* C++ SUPPORT              */
    }
#endif
#endif                                  /* QUEC_FILE_INTERFACE_H    */
