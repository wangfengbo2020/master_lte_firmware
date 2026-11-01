/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#include "quec_spi_nor.h"
#include "common.h"
#include "quec_spi.h"
#ifdef QUECTEL_FOTA
#include "ql_updater_usr_func.h"
#endif

#define EXTERNAL_NORFLASH_PORT EXTERNAL_NORFLASH_PORT33_36
#define EXTERNAL_NORFLASH_CLK _APBC_SSP_FNCLKSEL_26MHZ


extern int uart_printf(const char *fmt, ...);
extern unsigned int SPINOR_Wipe(int sspport);
extern unsigned int SPINOR_EraseByBlock(int sspport, unsigned int Address, unsigned int Size);
extern unsigned int SPINOR_EraseBySector(int sspport, unsigned int Address, unsigned int Size);
extern unsigned int SPINOR_Read(int sspport, unsigned int FlashOffset, unsigned int Buffer, unsigned int Size);
extern unsigned int SPINOR_Write(int sspport, unsigned int Address, unsigned int Buffer, unsigned int Size);
extern void SPINOR_ReadId(int sspport, unsigned int *pID);
extern int InitializeSPIDevice(int sspport, int sspclock);

/********************************
变量ql_spi_pin_selflag功能描述
0：默认配置，SSP0使用GPIO16~19引脚
1: SSP0使用GPIO33~36
2: SSP2使用GPIO33~36
3: SSP2使用GPIO12~15
...:待新的配置
**********************************/
int quec_spi_pin_selflag = 0;
unsigned int quec_spi_pin_select(int port)
{
    quec_spi_pin_selflag = port;
    if(port == 1)//33~36 ssp0
    {
        return 0;
    }
    else if((port == 0)||(port == 2))
    {
        return port;
    }
    else//12~15 for SSP2
    {
        return 2;
    }
}     		
#define SPINOR_PIN_REMAP(A) quec_spi_pin_select(A)
//初始化SPI FLASH的IO Quec_Spi_Nor_Init
unsigned int QUEC_SPI_NOR_Init(int port, int clk)
{
	int ret = 0;
	unsigned char *id;
	unsigned int Retval = 0;
    
    port = SPINOR_PIN_REMAP(port);
    
	if ((port!=EXTERNAL_NORFLASH_PORT16_19) && (port!=EXTERNAL_NORFLASH_PORT33_36))
	{
		uart_printf("[%s][%d]invalid port \r\n", __func__, __LINE__);
		return QUEC_SSPPortInvalidError;
	}
	switch (clk)
	{
		case _APBC_SSP_FNCLKSEL_6_5MHZ:
		case _APBC_SSP_FNCLKSEL_13MHZ:

		case _APBC_SSP_FNCLKSEL_3_25MHZ:
		case _APBC_SSP_FNCLKSEL_1_625MHZ:
		case _APBC_SSP_FNCLKSEL_812_5KHZ:
			ret = InitializeSPIDevice(port, 0x0);	//SSP_CLOCK_13M
			break;
		case _APBC_SSP_FNCLKSEL_26MHZ:
			ret = InitializeSPIDevice(port, 0x1);	//SSP_CLOCK_26M
			break;
		case _APBC_SSP_FNCLKSEL_52MHZ:
		default:
			ret = InitializeSPIDevice(port, 0x2);	//SSP_CLOCK_52M
			break;
	}
	if (ret != 0)
	{
		uart_printf("[%s][%d]InitializeSPIDevice failed \r\n", __func__, __LINE__);
		return QUEC_SSPPortInvalidError;
	}	
	return Retval;
}  

//读取芯片ID
//返回值如丿				   	  
//void W25QXX_ReadID(u8 *id)
unsigned char *QUEC_SPI_NOR_ReadID(int port)
{
	unsigned int flash_id = 0;
	static unsigned char id[3] = {0};
    port = SPINOR_PIN_REMAP(port); 
	memset(id, 0, sizeof(id));
	SPINOR_ReadId(port, &flash_id);
	id[0] = flash_id & 0xFF;
	id[1] = (flash_id>>8) & 0xFF;
	id[2] = (flash_id>>16) & 0xFF;

	return id;
}  

//读取SPI FLASH  
//在指定地址开始读取指定长度的数据
//pBuffer:数据存储匿
//ReadAddr:开始读取的地址(24bit)
//NumByteToRead:要读取的字节敿最夿5535)
unsigned int  QUEC_SPI_NOR_Read(int port, unsigned char* pBuffer,unsigned int ReadAddr,unsigned int NumByteToRead)   
{
	unsigned int Retval = 0;
    port = SPINOR_PIN_REMAP(port);
    
	if ((port!=EXTERNAL_NORFLASH_PORT16_19) && (port!=EXTERNAL_NORFLASH_PORT33_36))
	{
		uart_printf("[%s][%d]invalid port \r\n", __func__, __LINE__);
		return QUEC_SSPPortInvalidError;
	}
	if (0 == pBuffer)
	{
		uart_printf("[%s][%d]invalid param, pBuffer is NULL \r\n", __func__, __LINE__);
		return QUEC_SSPBufferParamInvalidError;
	}
	Retval = SPINOR_Read(port, ReadAddr, (unsigned int)pBuffer, NumByteToRead);
    
	return Retval;
}  

//写SPI FLASH  
//在指定地址开始写入指定长度的数据
//该函数带擦除操作!
//pBuffer:数据存储匿
//WriteAddr:开始写入的地址(24bit)						
//NumByteToWrite:要写入的字节敿最夿5535)   		 
unsigned int  QUEC_SPI_NOR_Write(int port, unsigned char* pBuffer,unsigned int WriteAddr,unsigned int NumByteToWrite)   
{
	unsigned int Retval = 0;
	port = SPINOR_PIN_REMAP(port);
	if ((port!=EXTERNAL_NORFLASH_PORT16_19) && (port!=EXTERNAL_NORFLASH_PORT33_36))
	{
		uart_printf("[%s][%d]invalid port \r\n", __func__, __LINE__);
		return QUEC_SSPPortInvalidError;
	}
	if (0 == pBuffer)
	{
		uart_printf("[%s][%d]invalid param, pBuffer is NULL \r\n", __func__, __LINE__);
		return QUEC_SSPBufferParamInvalidError;
	}
	SPINOR_Write(port, WriteAddr, (unsigned int)pBuffer, NumByteToWrite);
    
	return Retval;
}

//擦除整个芯片		  
//等待时间超长...
unsigned int  QUEC_SPI_NOR_Erase_Chip(int port)
{
	unsigned int	Retval = 0;
    port = SPINOR_PIN_REMAP(port);
	if ((port!=EXTERNAL_NORFLASH_PORT16_19) && (port!=EXTERNAL_NORFLASH_PORT33_36))
	{
		uart_printf("[%s][%d]invalid port \r\n", __func__, __LINE__);
		return QUEC_SSPPortInvalidError;
	}
	Retval = SPINOR_Wipe(port);

	return Retval;
}   

//擦除一个扇匿
//Dst_Addr:扇区地址 根据实际容量设置
//擦除一个山区的最少时闿150ms
unsigned int  QUEC_SPI_NOR_Erase_Sector(int port, unsigned int Dst_Addr)
{
	unsigned int Retval = 0;
	port = SPINOR_PIN_REMAP(port);
	if ((port!=EXTERNAL_NORFLASH_PORT16_19) && (port!=EXTERNAL_NORFLASH_PORT33_36))
	{
		uart_printf("[%s][%d]invalid port \r\n", __func__, __LINE__);
		return QUEC_SSPPortInvalidError;
	}
	Retval = SPINOR_EraseBySector(port, Dst_Addr, 1);
    
	return Retval;
} 

static int externl_falsh_port = 1;
int quec_spi_init(void)
{
	int clk = 0x2;
	ql_set_external_fs_info(&externl_falsh_port, &clk, 0, 0);
	uart_printf("externl_falsh_port:%d ,clk:%d \r\n", externl_falsh_port,clk);
	return (int)QUEC_SPI_NOR_Init(externl_falsh_port, clk);
}

#if 0
unsigned int tx_buf[1024] = {0};
void spi_nor_test()
{
    int i ,ret;
    quec_spi_init();
    while(1){
        for(i=0; i<1024; i++)
    	{
    		tx_buf[i] = 0xA5A5A5A5;
    	}
        QUEC_SPI_NOR_Erase_Chip(externl_falsh_port);
    	uart_printf("[NORFLASH]=====erase:\r\n");
    	
    	ret = QUEC_SPI_NOR_Write(externl_falsh_port, tx_buf, 0x1000, 4096);
    	uart_printf("[NORFLASH]=====write\r\n");
    	for(i=0; i<1024; i++)
    	{
    	
    		tx_buf[i] = 0;
    	}

    	ret = QUEC_SPI_NOR_Read(externl_falsh_port, tx_buf, 0x1000, 4096);
    	uart_printf("[NORFLASH]=====read\r\n");
    	for(i=0; i<1024; i++)
    	{
    		uart_printf("[NORFLASH]=====read[%d]: 0x%08X \r\n", i, tx_buf[i]);
    	}
    }
}
#endif
