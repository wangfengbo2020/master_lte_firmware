/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#ifndef __QUEC_SPI_NOR_H
#define __QUEC_SPI_NOR_H

#define QUEC_SPI_NOR_FLASH
#ifdef QUEC_SPI_NOR_FLASH
		
		
#define EXTERNAL_NORFLASH_SSP0        0
#define EXTERNAL_NORFLASH_SSP2        2
					 
////////////////////////////////////////////////////////////////////////////
//spi ±÷”∆µ¬ 
#define _APBC_SSP_FNCLKSEL_6_5MHZ	(0x00)
#define _APBC_SSP_FNCLKSEL_13MHZ	(0x01)
#define _APBC_SSP_FNCLKSEL_26MHZ	(0x02)
#define _APBC_SSP_FNCLKSEL_52MHZ	(0x03)
#define _APBC_SSP_FNCLKSEL_3_25MHZ	(0x04)
#define _APBC_SSP_FNCLKSEL_1_625MHZ	(0x05)
#define _APBC_SSP_FNCLKSEL_812_5KHZ	(0x06)

//∑¢ÀÕƒ£èè
#define     READ_NORFLASH         0x00
#define 	WRITE_NORFLASH   	  0x03	
#define 	CMD_READ  	          0x02
#define 	CMD_WERTE             0x01

//÷∏¡ÓÒ∆
#define QUEC_SPI_NOR_WriteEnable		0x06 
#define QUEC_SPI_NOR_WriteDisable		0x04 
#define QUEC_SPI_NOR_ReadStatusReg		0x05 
#define QUEC_SPI_NOR_WriteStatusReg		0x01 
#define QUEC_SPI_NOR_ReadData			0x03 
#define QUEC_SPI_NOR_FastReadData		0x0B 
#define QUEC_SPI_NOR_FastReadDual		0x3B 
#define QUEC_SPI_NOR_PageProgram		0x02 
#define QUEC_SPI_NOR_BlockErase			0xD8 
#define QUEC_SPI_NOR_SectorErase		0x20 
#define QUEC_SPI_NOR_ChipErase			0xC7 
#define QUEC_SPI_NOR_PowerDown			0xB9 
#define QUEC_SPI_NOR_ReleasePowerDown	0xAB 
#define QUEC_SPI_NOR_DeviceID			0xAB 
#define QUEC_SPI_NOR_ManufactDeviceID	0x90 
#define QUEC_SPI_NOR_JedecDeviceID		0x9F 

#define QUEC_SPINOR_MAX_ID_LEN		0x03

////SPI_Nor operation ERROR CODE
#define QUEC_SSPOperationNoError				0x0
#define QUEC_SSPPortInvalidError			    0x20
#define QUEC_SSPBufferParamInvalidError		    0x21
#define QUEC_FlashAddrOutOfRange				0x3d
#define QUEC_SSPWaitTxEmptyTimeOutError			0x80
#define QUEC_SSPRdStatusTimeOutError		    0x81
#define QUEC_SSPWelWaitTxEmptyTimeOutError	    0x82
#define QUEC_SSPWaitForWELTimeOutError		    0x83
#define QUEC_SSPWaitCompleteTimeOutError        0x84
#define QUEC_SSPRxChannelTimeOutError           0x85
#define QUEC_SSPTxChannelTimeOutError           0x86
#define QUEC_SSPNOTREADY						0x87

typedef struct quec_spi_nor_info{
	char				*name; 
	
	unsigned char		id[QUEC_SPINOR_MAX_ID_LEN];
	unsigned char		id_len;
	unsigned int		sector_size;
	unsigned int		n_sectors;
	unsigned int		page_size;
	unsigned int		total_size;
	unsigned int		addr_width;	
}quec_spi_nor_info_t;


unsigned int QUEC_SPI_NOR_Init(int port, int clk);
unsigned char *QUEC_SPI_NOR_ReadID(int port);  	    		//∂¡»°FLASH ID
unsigned char QUEC_SPI_NOR_ReadSR(int port);        		//∂¡»°◊¥Ã¨ºƒ¥Ê∆˜ 
unsigned char  QUEC_SPI_NOR_ReadWriteNumByte(int port, unsigned char *cmd, unsigned char*data, unsigned int len, unsigned char mode);
void QUEC_SPI_NOR_Write_SR(int port, unsigned char sr);  			//–¥◊¥Ã¨ºƒ¥Ê∆˜
void QUEC_SPI_NOR_Write_Enable(int port);  		//–¥ π√v
void QUEC_SPI_NOR_Write_Disable(int port);		//–¥±£√Ú
void QUEC_SPI_NOR_Write_NoCheck(int port, unsigned char* pBuffer,unsigned int WriteAddr,unsigned short NumByteToWrite);
unsigned int  QUEC_SPI_NOR_Read(int port, unsigned char* pBuffer,unsigned int ReadAddr,unsigned short NumByteToRead);   //∂¡»°flash
unsigned int  QUEC_SPI_NOR_Write(int port, unsigned char* pBuffer,unsigned int WriteAddr,unsigned short NumByteToWrite);//–¥»Îflash
unsigned int  QUEC_SPI_NOR_Erase_Chip(int port);    	  	//’˚∆¨≤¡≥˝
unsigned int  QUEC_SPI_NOR_Erase_Sector(int port, unsigned int Dst_Addr);	//…»«¯≤¡≥˝
unsigned int  QUEC_SPI_NOR_Erase_Block(int port, unsigned int Dst_Addr);	//block≤¡≥˝
void QUEC_SPI_NOR_Wait_Busy(int port);           	//µ»¥˝ø’œ–
void QUEC_SPI_NOR_Power_Down(int port);        	//Ω¯»ÎµÙµÁƒ£ Ω
void QUEC_SPI_NOR_WAKEUP(int port);				//ªΩ–—

void QUEC_SPI_NOR_Tese(void);

#endif

#endif

