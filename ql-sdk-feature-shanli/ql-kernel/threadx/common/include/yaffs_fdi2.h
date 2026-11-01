#ifndef _YAFFS_FDI2_H_
#define _YAFFS_FDI2_H_
#include "fattypes.h"
#include "FDI_FILE.h"

#define NAND_FILE_NAME_SIZE 128
typedef struct 
{   
    // Type of the file, either LFS_TYPE_REG or LFS_TYPE_DIR
    UINT8 type;

    // Size of the file, only valid for REG files
    unsigned int size;

    // Name of the file stored as a null-terminated string
    char name[NAND_FILE_NAME_SIZE];
}NandFs_info;
OSA_STATUS FDI2YaffsSysInit(void);
FILE_ID  FDI2_fopen(const char *filename_ptr, const char *mode);
int FDI2_fclose(FILE_ID stream);
size_t FDI2_fread(void *buff, size_t element_size, size_t count, FILE_ID stream);
size_t FDI2_freadEx(void *buff, size_t element_size, size_t count, FILE_ID stream, UINT32 filepostoread);
unsigned int FDI2_fsize(FILE_ID stream);
size_t FDI2_fwrite(const void *buff, size_t element_size,
		  size_t count, FILE_ID stream);
size_t FDI2_fwriteEx(const void *buff, size_t element_size,
		  size_t count, FILE_ID stream, UINT32 filePostowrite);
int FDI2_fseek(FILE_ID stream, long offset, int wherefrom);
int  FDI2_ftell(FILE_ID stream);
int FDI2_Access(const char *path, UINT32 mode);
int FDI2_Stat(const char *file_name, fatTYPE_sStat *stat);
FILE_ID FDI2_OpenDir(const char *dir_name);
int FDI2_CloseDir(FILE_ID stream);
int FDI2_DirRead(FILE_ID hDirID, NandFs_info *fileinfo_ptr);
int  FDI2_MakeDir(const char *dir_name);
int  FDI2_RmoveDir(const char *dir_name);
int FDI2_remove(const char *filename_ptr);
int FDI2_rename(const char *name, const char *new_name);
int FDI2_stat(const char *file_name);
ERR_CODE FDI2_Format(void);
int FDI2_freesize(void);
int FDI2_lstat(char* path,NandFs_info *fileinfo_ptr);
#ifdef QUECTEL_OPEN_CPU
int FDI2_fsync(FILE_ID stream);
int FDI2_yaffs_sync(void);
#endif

#endif
