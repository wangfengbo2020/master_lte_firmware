#include <stdio.h>
#include <stdlib.h>
#include "alipay_common.h"
#include "crossPlatformSW.h"

#define ALIPAY_MAX_FILE_PATH_NAME 136
#define ALIPAY_FILE_ROOT_DIR                      "C:/"

#include "UART.h"
#define vendor_file_printf(fmt,args...)  do {CPUartLogPrintf("[ali_file]"fmt, ##args);}while(0)
//#define vendor_file_printf(...)

typedef struct file_node {
    struct file_node *next;
    char *name;
} file_node_t;

file_node_t *file_list_head;
/*
 * 打开文件名为filename的文件，要求权限为可读写；
 * 参数：filename [in] 文件名(字符串)
 * 返回值: 文件句柄: 成功
 *        -1 或者 NULL: 失败
*/
void* alipay_open_rsvd_part(PARAM_IN char filename[128])
{
	FILE_ID *p_fd = NULL;
	FILE_ID fd = 0;
	
	p_fd = malloc(sizeof(p_fd));
	fd = FDI_fopen(filename,"rb");
	if(fd == 0)
	{
		fd = FDI_fopen(filename,"wb");
		if(fd == 0)
		{
			vendor_file_printf("%s create %s failed\n", __func__, filename);
            free(p_fd);
			return NULL;
		}
		
		file_node_t *fileNode = malloc(sizeof(file_node_t));
		memset(fileNode, 0, sizeof(file_node_t));
        fileNode->name = malloc(ALIPAY_MAX_FILE_PATH_NAME);
        memcpy(fileNode->name, filename, strlen(filename)+1);
		
        if (file_list_head == NULL) {
            file_list_head = fileNode;
        } else {
            fileNode->next = file_list_head;
            file_list_head = fileNode;
        }
	}
	FDI_fclose(fd);
	
	fd = FDI_fopen(filename,"rb+");
	if(fd == 0)
	{
		vendor_file_printf("%s open %s failed\n", __func__, filename);
		free(p_fd);
		return NULL;
	}
	*p_fd = fd;
	
	return p_fd;
}

/*
 * 往文件中写数据
 * 参数：fd [in] 文件句柄
 *      data [in] 要写入的数据
 *      data_len [in] 要写入的数据的长度
 * 返回值: 0: 写入成功
 *        -1: 写入失败
*/
int alipay_write_rsvd_part(PARAM_IN void* fd, PARAM_IN void *data,PARAM_IN uint32_t data_len)
{
    if ((fd == NULL) || (data == NULL) || (data_len == 0)) {
        vendor_file_printf("%s param is invalid\n", __func__);
        return -1;
    }

    uint32_t WriteLen=0;
	WriteLen = FDI_fwrite(data, 1, data_len, *(FILE_ID *)fd);
	if (data_len != WriteLen)
	{
		vendor_file_printf("%s failed", __func__);
	}

    return 0;
}

/*
 * 从提供给alipay kv存储的文件中读取数据
 * 参数：fd [in] 文件句柄
 *      buffer [out] 存放读取的数据的缓存
 *      read_len [in] 允许读取的最大长度
 *      read_len [out] 实际读取的数据长度
 * 返回值: 0: 读取成功
 *        -1: 读取失败,或者长度为0
*/
int alipay_read_rsvd_part(PARAM_IN void* fd,PARAM_OUT void *buffer,PARAM_INOUT uint32_t* read_len)
{
    if ((fd == NULL) || (buffer == NULL) || (*read_len == 0)) {
        vendor_file_printf("%s param is invalid\n", __func__);
        return -1;
    }

    uint32_t ReadLen=0;
    ReadLen = FDI_fread(buffer, 1, *read_len, *(FILE_ID *)fd);
	*read_len = ReadLen;
	vendor_file_printf("%s fd=%p, ReadLen = %d", __func__, fd, ReadLen);
    if(ReadLen == 0) {
        vendor_file_printf("%s failed", __func__);
        return -1;
    }

    return 0;
}

/*
 * 关闭打开的文件
 * 参数：fd [in] 文件句柄
 * 返回值: 0: 关闭成功
 *        -1: 关闭失败
*/
int alipay_close_rsvd_part(PARAM_IN void* fd)
{
	if (fd == NULL) {
        vendor_file_printf("%s param is invalid\n", __func__);
        return -1;
	}
	
    vendor_file_printf("%s %p\n", __func__, fd);
	if(FDI_fclose(*(FILE_ID *)fd) != 0)
		return -1;
	
	free(fd);
	return 0;
}

/*
 * 查看文件是否存在
 * 参数: filename [in] 文件名(字符串)
 * 返回值: 1: 文件存在
          0: 文件不存在
 */
int alipay_access_rsvd_part(PARAM_IN char filename[128])
{
	FILE_ID fd = 0;
	
	fd = FDI_fopen(filename, "rb");
	if(fd != 0)
	{
		FDI_fclose(fd);
		return 1;
	}

	vendor_file_printf("%s %s is not exist\n", __func__, filename);
    return 0;
}

/*
 * 删除文件
 * 参数: filename [in] 文件名(字符串)
 * 返回值: 0: 删除成功
 *       -1: 删除失败
 */
int alipay_remove_rsvd_part(PARAM_IN char filename[128])
{
	
    file_node_t *pNode = file_list_head;
    file_node_t *tmp = pNode;
    while (pNode) {
        if(!strcmp(pNode->name, filename)) 
		{
            int ret = FDI_remove(filename);
            if (ret != 0) {
                printf("%s remove %s failed\n", __func__, filename);
                return -1;
            }
            if (pNode == file_list_head) {
                file_list_head = pNode->next;
            } else {
                tmp->next = pNode->next;
            }
            free(pNode->name);
            free(pNode);
            vendor_file_printf("%s remove %s success\n", __func__, filename);
            return 0;
        }
        tmp = pNode;
        pNode = pNode->next;
    }
	
	vendor_file_printf("%s not found %s\n", __func__, filename);
    return -1;
}

/*
 * 清除所有通过alipay_write_rsvd_part存储的alipay文件
 * 返回值: 0: 清除成功
 *       -1: 清除失败
 */
int alipay_clear_rsvd_part(void)
{
    file_node_t *pNode = file_list_head;
    while (pNode) {
        int ret = FDI_remove(pNode->name);
        if (ret != 0) {
            vendor_file_printf("%s remove %s failed\n", __func__, pNode->name);
            return -1;
        }
        vendor_file_printf("%s remove %s success\n", __func__, pNode->name);
        pNode = pNode->next;
        free(file_list_head->name);
        free(file_list_head);
        file_list_head = pNode;
    }
    vendor_file_printf("%s success\n", __func__);

    return 0;
}
