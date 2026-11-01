/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/

#ifndef _QL_FS_H
#define _QL_FS_H

#ifdef __OCPU_COMPILER_GCC__
	#include "ql_type.h"
	#include "lfs.h"
#else
	#include "quec_rtos.h"
	#include "lfs.h"
	#include "lfs_api.h"
#ifdef QUEC_NAND_YAFFS    
    #include "yaffs_fdi2.h"
#endif
#endif
typedef unsigned int File_Handle;


#define QFS_ID_MAX   3

#define EXTERNAL_NORFLASH   1
#define INTERNAL_NORFLASH   0


#ifdef QUEC_FS_WEAR_BALANCE_VERIFY
#define FS_FLASH_BLOCK_SIZE (1024*4)				//each block size:4K byte
#endif

//freddy @20200713 Add for external fs
typedef struct
{
    unsigned int start_addr;//外部spi的起始地址
    unsigned int size;//挂载为文件系统的大小
    unsigned char spi_port;//SPI端口
}ex_spifs_info;

typedef struct
{
	quec_mutex_t mutex;
	char disk_sym;
	lfs_t lfs;
	struct lfs_config cfg;
	lfs_flash_info flash_info;
	bool is_inited;
	char *patition_name;
	unsigned char is_exflash;
	ex_spifs_info spi_info;//外部SPI的信息
} qfs_ctx_t;

struct ql_yaffs_dev
{
    const char *name;
    u32 start_block;    
    u32 end_block;
};

typedef struct
{
	int fs_id;
	lfs_file_t file;
} QFILE;

typedef struct
{
	int fs_id;
	lfs_dir_t dir;
} QDIR;

#define GET_FILE_PATH(path) (path+2)

#define FILE_OPEN_FLAGS_R		(LFS_O_RDONLY)
#define FILE_OPEN_FLAGS_W		(LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC)
#define FILE_OPEN_FLAGS_A		(LFS_O_WRONLY | LFS_O_CREAT | LFS_O_APPEND)
#define FILE_OPEN_FLAGS_RPluse	(LFS_O_RDWR)
#define FILE_OPEN_FLAGS_WPluse	(LFS_O_RDWR | LFS_O_CREAT | LFS_O_TRUNC)
#define FILE_OPEN_FLAGS_APluse	(LFS_O_RDWR | LFS_O_CREAT | LFS_O_APPEND)

#define U_DISK_SYM	'U'
#define B_DISK_SYM	'B'

int qfs_per_init(int fs_id, char disk_sym, unsigned char is_format);

void qfs_per_deinit(int fs_id);

int qfs_deinit(char disk_sym);

int qfs_get_fs_id_from_disk_sym(char disk_sym);

int qfs_init(char disk_sym, char *patition_name, unsigned char is_format);

int qextfs_init(char disk_sym, char *patition_name, unsigned char is_format, unsigned char spi_port, unsigned int startaddr, unsigned int size);

int qfs_format(int fs_id);

int qfs_mount(int fs_id);

int qfs_unmount(int fs_id);

int qfs_size(int fs_id);

int qfs_used_size(int fs_id);

int qfs_free_size(int fs_id);

int qfs_remove(int fs_id, const char *path);

int qfs_rename(int fs_id, const char *oldpath, const char *newpath);

int qfs_rename_ex(int old_fs_id, int new_fs_id, const char *oldpath, const char *newpath);

int qfs_copy(int fs_id, const char *oldpath, const char *newpath);

int qfs_copy_ex(int old_fs_id, int new_fs_id, const char *oldpath, const char *newpath);

int qfs_access(int fs_id, const char *path);

int qfs_stat(int fs_id, const char *path, struct lfs_info *info);

int qfs_file_open(int fs_id, lfs_file_t *file,
        const char *path, int flags);

int qfs_file_opencfg(int fs_id, lfs_file_t *file,
        const char *path, int flags,
        const struct lfs_file_config *config);

int qfs_file_close(int fs_id, lfs_file_t *file);

int qfs_file_sync(int fs_id, lfs_file_t *file);

lfs_ssize_t qfs_file_read(int fs_id, lfs_file_t *file,
        void *buffer, lfs_size_t size);

lfs_ssize_t qfs_file_write(int fs_id, lfs_file_t *file,
        const void *buffer, lfs_size_t size);

lfs_soff_t qfs_file_seek(int fs_id, lfs_file_t *file,
        lfs_soff_t off, int whence);

int qfs_file_truncate(int fs_id, lfs_file_t *file, lfs_off_t size);

lfs_soff_t qfs_file_tell(int fs_id, lfs_file_t *file);

int qfs_file_rewind(int fs_id, lfs_file_t *file);

lfs_soff_t qfs_file_size(int fs_id, lfs_file_t *file);

int qfs_mkdir(int fs_id, const char *path);

int qfs_dir_open(int fs_id, lfs_dir_t *dir, const char *path);

int qfs_dir_close(int fs_id, lfs_dir_t *dir);

int qfs_dir_read(int fs_id, lfs_dir_t *dir, struct lfs_info *info);

int qfs_dir_seek(int fs_id, lfs_dir_t *dir, lfs_off_t off);

lfs_soff_t qfs_dir_tell(int fs_id, lfs_dir_t *dir);

int qfs_dir_rewind(int fs_id, lfs_dir_t *dir);

int qfs_traverse(int fs_id, int (*cb)(void*, lfs_block_t), void *data);

int qfs_deorphan(int fs_id);

int ql_fs_format(char disk_sym);

int ql_fs_mount(char disk_sym);

int ql_fs_unmount(char disk_sym);

int ql_fs_size(char disk_sym);

int ql_fs_used_size(char disk_sym);

int ql_fs_free_size(char disk_sym);

QFILE * ql_fopen(const char *fname, const char *mode);

int ql_fclose(QFILE * fp);

int ql_fsync(QFILE * fp);

int ql_fread(void * buffer, size_t size, size_t num, QFILE * fp);

int ql_fwrite(void * buffer, size_t size, size_t num, QFILE * fp);

int ql_fputc(int chr, QFILE *fp);

int ql_fputs(const char *str, QFILE *fp);
int _ql_fprintf(QFILE *fp, const char *format, va_list arg_ptr);
int ql_fprintf(QFILE *fp, const char *format, ...);

int ql_fgetc(QFILE *fp);

char *ql_fgets(char *str, int n, QFILE *fp);

int ql_fscanf(QFILE *fp, const char *format, ...);
int _ql_fscanf(QFILE *fp, const char *format, va_list arg_ptr);

int ql_fseek(QFILE *fp, long offset, int origin);

int ql_ftruncate(QFILE *fp, uint32 length);

long ql_ftell(QFILE *fp);

int ql_frewind(QFILE *fp);

int ql_fsize(QFILE *fp);

int ql_mkdir(const char *path, uint32 mode);

QDIR * ql_opendir(const char *path);

int ql_closedir(QDIR *dp);

int ql_readdir(QDIR *dp, struct lfs_info *info);

int ql_seekdir(QDIR *dp, long int loc);

long ql_telldir(QDIR *dp);

int ql_rewinddir(QDIR *dp);

int ql_remove(const char *fname);

int ql_rename(const char *oldpath, const char *newpath);

int ql_copy(const char *oldpath, const char *newpath);

int ql_access(const char *path, uint32 mode);

int ql_stat(const char *path, struct lfs_info *info);

File_Handle ql_FDI_fopen(const char *filename_ptr, const char *mode);
int ql_FDI_fclose(File_Handle stream);
size_t ql_FDI_fread(void *buffer_ptr, size_t element_size, size_t count, File_Handle stream);
size_t ql_FDI_fwrite(const void *buffer_ptr,size_t element_size,size_t count,File_Handle stream);
int ql_FDI_fseek(File_Handle stream, long offset, int wherefrom);
unsigned int ql_FDI_GetFileSize(int fd);
int ql_fs_get_bk_erase_count(int flash_addr);
#ifdef QL_NAND_YAFFS
int ql_spi_nand_init(int spi_port, int spi_pin,int spi_clk);
File_Handle ql_nand_fopen(const char *filename_ptr, const char *mode);
int ql_nand_fclose(File_Handle stream);
int ql_nand_fread(void *buff, size_t element_size, size_t count, File_Handle stream);
int ql_nand_fwrite(const void *buff, size_t element_size, size_t count, File_Handle stream);
int ql_nand_fseek(File_Handle stream, long offset, int wherefrom);
int ql_nand_lseek(File_Handle stream, long offset, int wherefrom);
int ql_nand_ftell(File_Handle stream);
int ql_nand_fremove(const char *filename_ptr);
int ql_nand_frename(char *name, char *new_name);
int ql_nand_fsize(char *file_name);
int	ql_nand_mkdir(char *dir_name);
int ql_nand_access(char *file_name);
int ql_nand_get_free_size(void);
void ql_nand_format(void);
int	ql_nand_removedir(char *dir_name);
int	ql_nand_closedir(FILE_ID hDirID);
int	ql_nand_readddir(FILE_ID hDirID, NandFs_info *fileinfo_ptr);
FILE_ID	ql_nand_opendir(char *dir_name);
int ql_nand_lstat(char *path,NandFs_info *fileinfo_ptr);
int ql_nand_fgetc(File_Handle stream);
char *ql_nand_fgets(char *str, int n, File_Handle stream);
int ql_nand_fsync(File_Handle stream);
int ql_nand_yaffs_sync(void);
int ql_nand_feof(File_Handle stream,char *file_name);
int ql_nand_frewind(File_Handle stream);

/*yaffs原生接口,支持分区*/
int ql_yaffs_start_up(void);
int ql_yaffs_create_dev(struct ql_yaffs_dev *dev_config);
int ql_yaffs_mount(const char *path);
int ql_yaffs_unmount(const char *path);
int ql_yaffs_open(const char *filename, const char *mode);
int ql_yaffs_close(int fd);
int ql_yaffs_read(void *buff, size_t element_size, size_t count, int fd);
int ql_yaffs_write(const void *buff, size_t element_size, size_t count, int fd);
int ql_yaffs_lseek(int fd, long offset, int whence);
int ql_yaffs_unlink(const char *path);
int ql_yaffs_fsize(const char *path);
int ql_yaffs_rename(const char *name, const char *new_name);
int ql_yaffs_mkdir(const char *dir_name);
int ql_yaffs_opendir(const char *dir_name);
int	ql_yaffs_closedir(int fd);
int ql_yaffs_rmdir(const char *dir_name);
int ql_yaffs_access(const char *path);
int ql_yaffs_freespace(const char *path);
int ql_yaffs_fsync(int fd);
int ql_yaffs_sync(const char *path);
int ql_yaffs_format(const char *path, int unmount_flag, int force_unmount_flag, int remount_flag);
int ql_yaffs_ftell(int fd);
int ql_yaffs_fgetc(int fd);
char *ql_yaffs_fgets(char *str, int n, int fd);
int ql_yaffs_feof(int fd, const char *file_name);
int ql_yaffs_frewind(int fd);
int	ql_yaffs_readddir(int fd, NandFs_info *fileinfo_ptr);
int ql_yaffs_lstat(char *path, NandFs_info *fileinfo_ptr);
#endif
#endif

