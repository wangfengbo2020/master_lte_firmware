/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#include <stdio.h>
#include "global_types.h"
#include "osa.h"
#include "quec_spi.h"
#include "ql_spi.h"

//#define spi_dbg_log(fmt, args...)	uart_printf("[%s][%d]"fmt, __FUNCTION__, __LINE__, ##args)

#define spi_dbg_log(fmt, args...)                                                      \
{                                                                                       \
    /*if (log_config.log_cfg != LOG_DISABLE)*/      \
    {                                                                                   \
        UARTLogPrintf_Extend(fmt, ##args);                                              \
    }                                                                                   \
}
QL_SPI_OpMode ql_spi_mode_set = QL_SPI_OP_DMA;

int ql_spi_init(QL_SPI_PORT_E port, QL_SPI_MODE_E spimode, QL_SPI_CLK_E spiclk)
{
	QL_SPI_MODE_E ql_spimode=QL_SPI_MODE_INVALID;
	QL_SPI_CLK_E ql_spiclk=QL_SPI_CLK_INVALID;

	if (spimode <=QL_SPI_MODE_INVALID  || spimode >= QL_SPI_MODE_MAX) {
		spi_dbg_log("invalid mode parameter!!\n");
		return -1;
	}
	
	ql_spimode = spimode;

	if (spiclk <=QL_SPI_CLK_INVALID  || spiclk >= QL_SPI_CLK_MAX) {
		spi_dbg_log("invalid clk parameter!!\n");
		return -1;
	}
	
	ql_spiclk = spiclk;

	if (port <= QL_SPI_PORT_INVALID || port >= QL_SPI_PORT_MAX) {
		spi_dbg_log("invalid port parameter");
		return -1;
	}

	switch (port) 
	{
		case QL_SPI_PORT0:
			SPI_SSP0_Initialize(ql_spimode, ql_spiclk);
			break;
		case QL_SPI_PORT1:
			SPI_SSP2_Initialize(ql_spimode, ql_spiclk);
			break;
		case QL_SPI_PORT2:
			SPI_SSP1_Initialize(ql_spimode, ql_spiclk);
			break;
		default:
			break;
	}

	return 0;
}

int ql_spi_write(QL_SPI_PORT_E port, unsigned char *buf, unsigned int len)
{
	int ret = 0;

	if (port <= QL_SPI_PORT_INVALID || port >= QL_SPI_PORT_MAX) {
		spi_dbg_log("invalid port parameter");
		return -1;
	}
	
	if(buf==NULL){
		spi_dbg_log("error with a NULL pointer,please check up the parameter please!\n");
		return -1;
	}

	switch (port) 
	{
		case QL_SPI_PORT0:
			if(QL_SPI_OP_DMA==ql_spi_mode_set)
			{
				QUEC_SPI_SSP0_DMA_WriteData(buf, len);
			}
			else
			{
				QUEC_SPI_SSP0_PIO_Write(buf, len);
			}
			break;
		case QL_SPI_PORT1:
			if(QL_SPI_OP_DMA==ql_spi_mode_set)
			{
				QUEC_SPI_SSP2_DMA_WriteData(buf, len);
			}
			else
			{
				QUEC_SPI_SSP2_PIO_Write(buf, len);
			}
			break;
		case QL_SPI_PORT2:
			if(QL_SPI_OP_DMA==ql_spi_mode_set)
			{
				QUEC_SPI_SSP1_DMA_WriteData(buf, len);
			}
			else
			{
				QUEC_SPI_SSP1_PIO_Write(buf, len);
			}
			break;	
		default:
			break;
	}

	return ret;
}

int ql_spi_read(QL_SPI_PORT_E port, unsigned char *buf, unsigned int len)
{
	int ret = 0;

	if (port <= QL_SPI_PORT_INVALID || port >= QL_SPI_PORT_MAX) {
		spi_dbg_log("invalid port parameter");
		return -1;
	}

	if(buf==NULL){
		spi_dbg_log("error with a NULL pointer,please check up the parameter please!\n");
		return -1;
	}

	switch (port)
	{
		case QL_SPI_PORT0:
			if(QL_SPI_OP_DMA==ql_spi_mode_set)
			{
				QUEC_SPI_SSP0_DMA_ReadData(buf, len);
			}
			else
			{
				QUEC_SPI_SSP0_PIO_Read(buf, len,0);
			}
			break;
		case QL_SPI_PORT1:
			if(QL_SPI_OP_DMA==ql_spi_mode_set)
			{
				QUEC_SPI_SSP2_DMA_ReadData(buf, len);
			}
			else
			{
				QUEC_SPI_SSP2_PIO_Read(buf, len, 0);
			}
			break;
		case QL_SPI_PORT2:
			if(QL_SPI_OP_DMA==ql_spi_mode_set)
			{
				QUEC_SPI_SSP1_DMA_ReadData(buf, len);
			}
			else
			{
				QUEC_SPI_SSP1_PIO_Read(buf, len, 0);
			}
			break;
		default:
			break;
	}

	return ret;
}

int ql_spi_write_read(QL_SPI_PORT_E port, unsigned char *inbuf, unsigned char *outbuf, unsigned int len)
{
	int ret = 0;

	if (port <= QL_SPI_PORT_INVALID || port >= QL_SPI_PORT_MAX) {
		spi_dbg_log("invalid port parameter");
		return -1;
	}
	
	if((inbuf != NULL) && (outbuf != NULL))
	{
		switch (port) 
		{
			case QL_SPI_PORT0:
				if(QL_SPI_OP_DMA==ql_spi_mode_set)
				{
					QUEC_SPI_SSP0_DataTransfer(inbuf,outbuf, len);
				}
				else
				{
					QUEC_SPI_SSP0_PIO_transfer(inbuf, outbuf, len);
				}
				break;
			case QL_SPI_PORT1:
				if(QL_SPI_OP_DMA==ql_spi_mode_set)
				{
					QUEC_SPI_SSP2_DataTransfer(inbuf,outbuf, len);
				}
				else
				{
					QUEC_SPI_SSP2_PIO_transfer(inbuf, outbuf, len);
				}
				break;
			case QL_SPI_PORT2:
				if(QL_SPI_OP_DMA==ql_spi_mode_set)
				{
					QUEC_SPI_SSP1_DataTransfer(inbuf,outbuf, len);
				}
				else
				{
					QUEC_SPI_SSP1_PIO_transfer(inbuf, outbuf, len);
				}
				break;
			default:
				break;
		}
	}
	else
	{
		if(inbuf == NULL) {
			spi_dbg_log("ql_spi_transfer with NULL pointer to inbuf\n");
		}

		if(outbuf == NULL) {
			spi_dbg_log("ql_spi_transfer with NULL pointer to outbuf\n");
		}
	}

	return ret;
}


