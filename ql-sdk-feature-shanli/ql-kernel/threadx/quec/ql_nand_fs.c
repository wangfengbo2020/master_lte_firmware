#include "quec_cust_feature.h"
#ifdef QUEC_NAND_YAFFS   
#include "yaffs_fdi2.h"
#include "spinand.h"
#endif
#include "ql_fs.h"
#ifdef QL_NAND_YAFFS
static int nand_star = 1;
int ql_spi_nand_init(int spi_port, int spi_pin,int spi_clk)
{
   return quec_nand_spi_init((int)spi_port, (SPI_PIN)spi_pin,(SSP_Clock)spi_clk);
}

File_Handle ql_nand_fopen(const char *filename_ptr, const char *mode)
{
	if(nand_star){	
		nand_star = 0;
		unsigned char val=0;
		val=FDI2YaffsSysInit();
		if(val!=0)	
		{
			return NULL;
		}
	}
	return FDI2_fopen(filename_ptr, mode);
}

int ql_nand_fclose(File_Handle stream)
{
	return FDI2_fclose(stream);
}

int ql_nand_fread(void *buff, size_t element_size, size_t count, File_Handle stream)
{
	return FDI2_fread(buff, element_size, count, stream);
}

int ql_nand_fwrite(const void *buff, size_t element_size, size_t count, File_Handle stream)
{
	return FDI2_fwrite(buff, element_size, count, stream);
}

int ql_nand_fseek(File_Handle stream, long offset, int wherefrom)
{
	return FDI2_fseek(stream, offset, wherefrom);
}

int ql_nand_lseek(File_Handle stream, long offset, int wherefrom)
{
	return FDI2_lseek(stream, offset, wherefrom);
}

int  ql_nand_ftell(File_Handle stream)
{
	return FDI2_ftell(stream);
}

int ql_nand_fremove(const char *filename_ptr)
{
	if(nand_star){	
		nand_star = 0;
		FDI2YaffsSysInit();
	}
	return FDI2_remove(filename_ptr);
}

int ql_nand_frename(char *name, char *new_name)
{
	if(nand_star){	
		nand_star = 0;
		unsigned char val=0;
		val=FDI2YaffsSysInit();
		if(val!=0)	
		{
			return NULL;
		}
	}
	return FDI2_rename(name, new_name);
}


int ql_nand_fsize(char *file_name)
{
	if(nand_star){	
		nand_star = 0;
		unsigned char val=0;
		val=FDI2YaffsSysInit();
		if(val!=0)	
		{
			return NULL;
		}
	}
	return FDI2_stat(file_name);
}

//0:success
int	ql_nand_mkdir(char *dir_name)
{
	if(nand_star){	
		nand_star = 0;
		unsigned char val=0;
		val=FDI2YaffsSysInit();
		if(val!=0)	
		{
			return NULL;
		}
	}
	return FDI2_MakeDir(dir_name);
}

int	ql_nand_readddir(FILE_ID hDirID, NandFs_info *fileinfo_ptr)
{
	return FDI2_DirRead(hDirID,fileinfo_ptr);
}

int	ql_nand_closedir(FILE_ID stream)
{
	return FDI2_CloseDir(stream);
}

int	ql_nand_removedir(char *dir_name)
{
	return FDI2_RmoveDir(dir_name);
}

FILE_ID	ql_nand_opendir(char *dir_name)
{
	if(nand_star){	
		nand_star = 0;
		unsigned char val=0;
		val=FDI2YaffsSysInit();
		if(val!=0)	
		{
			return NULL;
		}
	}
	return FDI2_OpenDir(dir_name);
}

int ql_nand_access(char *file_name)
{
	int ret = 0;
	if(nand_star){	
		nand_star = 0;
		unsigned char val=0;
		val=FDI2YaffsSysInit();
		if(val!=0)	
		{
			return NULL;
		}
	}
	ret = FDI2_Access(file_name, NULL);
	return ret;
}

int ql_nand_get_free_size(void)
{
	if(nand_star){	
		nand_star = 0;
		unsigned char val=0;
		val=FDI2YaffsSysInit();
		if(val!=0)	
		{
			return NULL;
		}
	}
	return FDI2_freesize();
}

void ql_nand_format(void){
	if(nand_star){	
		nand_star = 0;
		unsigned char val=0;
		val=FDI2YaffsSysInit();
		if(val!=0)	
		{
			return NULL;
		}
	}
	int ret = FDI2_Format();
	if(ret < 0) uart_printf("nand format fail:%d \n",ret);
	else uart_printf("nand format success!!! \n");
}
int ql_nand_lstat(char *path,NandFs_info *fileinfo_ptr)
{
    if(nand_star){	
		nand_star = 0;
		unsigned char val=0;
		val=FDI2YaffsSysInit();
		if(val!=0)	
		{
			return NULL;
		}
	}
	return FDI2_lstat(path,fileinfo_ptr);
}

int ql_nand_fgetc(File_Handle stream)
{
	int ret;
	char c = 0;

	ret = FDI2_fread((void*)&c,1,1,stream);
	if(ret <= 0) return ret;

	return (int)c;
}

char *ql_nand_fgets(char *str, int n, File_Handle stream)
{
	int ret, i = 0;
	char *chr_lf = NULL;
	
	if(!(str && n && stream)) return NULL;

	memset(str, 0, n);

	for(; i<n; i++)
	{
		ret = FDI2_fread(str+i, 1, 1, stream);
		if(ret < 0 || (ret == 0 && i == 0)) return NULL;
 		
		if(str[i] == '\n' || ret == 0) break;
	}

	return str;	
}

int ql_nand_fsync(File_Handle stream)
{
	return	FDI2_fsync(stream);
}

int ql_nand_yaffs_sync(void)
{
	return	FDI2_yaffs_sync();
}

int ql_nand_feof(File_Handle stream,char *file_name)
{
	return ql_nand_ftell(stream) >= ql_nand_fsize(file_name) ? 1 : 0; 
}

int ql_nand_frewind(File_Handle stream)
{
	return FDI2_fseek(stream, 0, 0);	
}

#endif

