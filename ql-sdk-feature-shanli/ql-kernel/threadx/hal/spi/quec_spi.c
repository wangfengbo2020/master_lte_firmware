/*==========================================================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
===========================================================================================================*/

/*==========================================================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
09/04/2022        Fias        此文件是SPI的驱动接口 
===========================================================================================================*/



#include <stdio.h>
#include <stdlib.h>

#include "osa.h"
#include "xllp_dmac.h"
#include "quec_spi.h"
#include "bsp.h"

#ifndef MIN_SYS

#if defined(QUECTEL_OPEN_CPU) || defined(QUEC_FGM842D_WIFI_SUPPORT)

#define CPUartLogPrintf(fmt,args...)                                                    \
{                                                                                       \
    /*if (log_config.log_cfg != LOG_DISABLE)*/      \
    {                                                                                   \
        UARTLogPrintf_Extend(fmt, ##args);                                              \
    }                                                                                   \
}

#ifdef QUECTEL_OPEN_CPU

#define SSP0_DMA_BUF_LEN	1024
#define SSP1_DMA_BUF_LEN	1024
#define SSP2_DMA_BUF_LEN	1024

#else //标准版本.

#ifdef QUEC_FGM842D_WIFI_SUPPORT

//只有EC600K用到spi0.  EC800K/EC600M/EC800M/EG810M都是用到的spi2
#if defined(__QUECTEL_PROJECT_EC600KCN_CC__) || defined(__QUECTEL_PROJECT_EC600KCN_CK__) || \
    defined(__QUECTEL_PROJECT_EC600KCN_MC__) || defined(__QUECTEL_PROJECT_EC600KCN_LC__) || \
    defined(__QUECTEL_PROJECT_EC600KCN_LK__)
#define SSP0_DMA_BUF_LEN	1600
#define SSP1_DMA_BUF_LEN	0
#define SSP2_DMA_BUF_LEN	0
#else
#define SSP0_DMA_BUF_LEN	0
#define SSP1_DMA_BUF_LEN	0
#define SSP2_DMA_BUF_LEN	1600
#endif

#endif /*QUEC_FGM842D_WIFI_SUPPORT*/

#endif /*QUECTEL_OPEN_CPU*/


OSFlagRef SSP0_DMA_Done_FlgRef=NULL;
OSSemaRef SSP0SemaRef=NULL;

OSFlagRef SSP2_DMA_Done_FlgRef=NULL;
OSSemaRef SSP2SemaRef=NULL;

OSFlagRef SSP1_DMA_Done_FlgRef=NULL;
OSSemaRef SSP1SemaRef=NULL;

#define SSP0_DMA_INT_SUPPORT
#define SSP2_DMA_INT_SUPPORT
#define SSP1_DMA_INT_SUPPORT

/* Non-cache */
#pragma arm section rwdata="SSP0DmaBuf", zidata="SSP0DmaBuf"
__align(8) UINT8 DMA_SSP0_Tx_buf[SSP0_DMA_BUF_LEN+16]={0};
__align(8) UINT8 DMA_SSP0_Rx_buf[SSP0_DMA_BUF_LEN+16]={0};
#pragma arm section rwdata, zidata


/* Non-cache */
#pragma arm section rwdata="SSP2DmaBuf", zidata="SSP2DmaBuf"
__align(8) UINT8 DMA_SSP2_Tx_buf[SSP2_DMA_BUF_LEN+16]={0};
__align(8) UINT8 DMA_SSP2_Rx_buf[SSP2_DMA_BUF_LEN+16]={0};
#pragma arm section rwdata, zidata

/* Non-cache */
#pragma arm section rwdata="SSP1DmaBuf", zidata="SSP1DmaBuf"
__align(8) UINT8 DMA_SSP1_Tx_buf[SSP1_DMA_BUF_LEN+16]={0};
__align(8) UINT8 DMA_SSP1_Rx_buf[SSP1_DMA_BUF_LEN+16]={0};
#pragma arm section rwdata, zidata

static UINT32 v_spimode = SSP_SPI_MODE0;


void XllpDmacStartTransferWithStopIrqEnable( XLLP_DMAC_CHANNEL_T aChannel )
{
	UINT32 aTargetData;

	aTargetData  = XLLP_Return_PDmacHandle()->DCSR[aChannel];
	aTargetData |= XLLP_DMAC_DCSR_RUN | XLLP_DMAC_DCSR_STOP_IRQ_EN;
	XLLP_Return_PDmacHandle()->DCSR[aChannel]  =	aTargetData;
}

static void spi_delay_us(unsigned int time)
{
	volatile long i = 0;

    i = time * 50;

	while (i > 0)
	{
		i--;
	}
}


static void Disable_SPI_SSP0(void)
{
	spi_reg_bit_clr(SSP0_TCR, SSP_TCR_SSE);

	spi_reg_write(SSP0_TCR, SSP0_TCR_INITIAL); //default set data size 8bit
	spi_reg_write(SSP0_FCR, SSP0_FCR_INITIAL);
	spi_reg_write(SSP0_IER, SSP0_IER_INITIAL);

	//CPUartLogPrintf("%s:SSP0_TCR[0x%x],SSP0_FCR[0x%x],SSP0_IER[0x%x]", __func__, spi_reg_read(SSP0_TCR), spi_reg_read(SSP0_FCR), spi_reg_read(SSP0_IER));
}

static void Disable_SPI_SSP1(void)
{
	spi_reg_bit_clr(SSP1_TCR, SSP_TCR_SSE);
	spi_reg_write(SSP1_TCR, SSP1_TCR_INITIAL); //default set data size 8bit
	spi_reg_write(SSP1_FCR, SSP1_FCR_INITIAL);
	spi_reg_write(SSP1_IER, SSP1_IER_INITIAL);

	//CPUartLogPrintf("%s:SSP1_TCR[0x%x],SSP1_FCR[0x%x],SSP1_IER[0x%x]", __func__, spi_reg_read(SSP1_TCR), spi_reg_read(SSP1_FCR), spi_reg_read(SSP1_IER));
}


static void Disable_SPI_SSP2(void)
{
	spi_reg_bit_clr(SSP2_TCR, SSP_TCR_SSE);
	spi_reg_write(SSP2_TCR, SSP2_TCR_INITIAL); //default set data size 8bit
	spi_reg_write(SSP2_FCR, SSP2_FCR_INITIAL);
	spi_reg_write(SSP2_IER, SSP2_IER_INITIAL);

	//CPUartLogPrintf("%s:SSP0_TCR[0x%x],SSP0_FCR[0x%x],SSP0_IER[0x%x]", __func__, spi_reg_read(SSP0_TCR), spi_reg_read(SSP0_FCR), spi_reg_read(SSP0_IER));
}

static void Enable_SPI_SSP0(void)
{
	spi_reg_bit_set(SSP0_TCR, SSP_TCR_SSE);
	//CPUartLogPrintf("%s:SSP0_TCR[0x%x]", __func__, spi_reg_read(SSP0_TCR));
}

static void Enable_SPI_SSP1(void)
{
	spi_reg_bit_set(SSP1_TCR, SSP_TCR_SSE);
	//CPUartLogPrintf("%s:SSP1_TCR[0x%x]", __func__, spi_reg_read(SSP1_TCR));
}


static void Enable_SPI_SSP2(void)
{
	spi_reg_bit_set(SSP2_TCR, SSP_TCR_SSE);
	//CPUartLogPrintf("%s:SSP0_TCR[0x%x]", __func__, spi_reg_read(SSP0_TCR));
}

/*Select the data bit length*/
static void SPI_SSP0_DSS(int DataSize)
{
	switch(DataSize)
	{
		case 8:
		{
			spi_reg_bit_clr(SSP0_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP0_TCR, SSP_TCR_DSS8);
			break;
		}
		case 9:
		{
			spi_reg_bit_clr(SSP0_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP0_TCR, 0x8<<5/*SSP_TCR_DSS9*/);
			break;
		}
		case 16:
		{
			spi_reg_bit_clr(SSP0_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP0_TCR, SSP_TCR_DSS16);
			break;
		}
		case 18:
		{
			spi_reg_bit_clr(SSP0_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP0_TCR, 0x11<<5/*SSP_TCR_DSS18*/);
			break;
		}
		case 24:
		{
			spi_reg_bit_clr(SSP0_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP0_TCR, SSP_TCR_DSS24);
			break;
		}
		case 32:
		{
			spi_reg_bit_clr(SSP0_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP0_TCR, SSP_TCR_DSS32);
			break;
		}
		default:
		{
			CPUartLogPrintf("%s:invalid data size", __func__);
			break;
		}		
	}
	
	//CPUartLogPrintf("%s:DataSize=%d,SSP0_TCR[0x%x]", __func__, DataSize, spi_reg_read(SSP0_TCR));
}

/*Select the data bit length*/
static void SPI_SSP1_DSS(int DataSize)
{
	switch(DataSize)
	{
		case 8:
		{
			spi_reg_bit_clr(SSP1_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP1_TCR, SSP_TCR_DSS8);
			break;
		}
		case 9:
		{
			spi_reg_bit_clr(SSP1_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP1_TCR, 0x8<<5/*SSP_TCR_DSS9*/);
			break;
		}
		case 16:
		{
			spi_reg_bit_clr(SSP1_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP1_TCR, SSP_TCR_DSS16);
			break;
		}
		case 18:
		{
			spi_reg_bit_clr(SSP1_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP1_TCR, 0x11<<5/*SSP_TCR_DSS18*/);
			break;
		}
		case 24:
		{
			spi_reg_bit_clr(SSP1_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP1_TCR, SSP_TCR_DSS24);
			break;
		}
		case 32:
		{
			spi_reg_bit_clr(SSP1_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP1_TCR, SSP_TCR_DSS32);
			break;
		}
		default:
		{
			CPUartLogPrintf("%s:invalid data size", __func__);
			break;
		}		
	}
	
	//CPUartLogPrintf("%s:DataSize=%d,SSP0_TCR[0x%x]", __func__, DataSize, spi_reg_read(SSP0_TCR));
}


static void SPI_SSP2_DSS(int DataSize)
{
	switch(DataSize)
	{
		case 8:
		{
			spi_reg_bit_clr(SSP2_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP2_TCR, SSP_TCR_DSS8);
			break;
		}
		case 9:
		{
			spi_reg_bit_clr(SSP2_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP2_TCR, 0x8<<5/*SSP_TCR_DSS9*/);
			break;
		}
		case 16:
		{
			spi_reg_bit_clr(SSP2_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP2_TCR, SSP_TCR_DSS16);
			break;
		}
		case 18:
		{
			spi_reg_bit_clr(SSP2_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP2_TCR, 0x11<<5/*SSP_TCR_DSS18*/);
			break;
		}
		case 24:
		{
			spi_reg_bit_clr(SSP2_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP2_TCR, SSP_TCR_DSS24);
			break;
		}
		case 32:
		{
			spi_reg_bit_clr(SSP2_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP2_TCR, SSP_TCR_DSS32);
			break;
		}
		default:
		{
			CPUartLogPrintf("%s:invalid data size", __func__);
			break;
		}		
	}
	
	//CPUartLogPrintf("%s:DataSize=%d,SSP0_TCR[0x%x]", __func__, DataSize, spi_reg_read(SSP0_TCR));
}


static UINT32 SPI_SSP0_WaitSSPComplete(void)
{
    volatile int timeout = 0;

	timeout = 0xFFFF;

    while ((spi_reg_read(SSP0_SR) & (SSP_SR_TFL | SSP_SR_TF_NF | SSP_SR_BSY)) != SSP_SR_TF_NF)
	{
		if((timeout--) <= 0)
    	{
    		CPUartLogPrintf("[NZC]SPINOR_WaitSSPComplete timeout");
    		return SSPWaitCompleteTimeOutError;
        }
	}

	CPUartLogPrintf("%s:Exit", __func__);

	return NoError;
}

static UINT32 SPI_SSP1_WaitSSPComplete(void)
{
    volatile int timeout = 0;

	timeout = 0xFFFF;

    while ((spi_reg_read(SSP1_SR) & (SSP_SR_TFL | SSP_SR_TF_NF | SSP_SR_BSY)) != SSP_SR_TF_NF)
	{
		if((timeout--) <= 0)
    	{
    		CPUartLogPrintf("[NZC]SPINOR_WaitSSPComplete timeout");
    		return SSPWaitCompleteTimeOutError;
        }
	}

	//CPUartLogPrintf("%s:Exit", __func__);

	return NoError;
}


static UINT32 SPI_SSP2_WaitSSPComplete(void)
{
    volatile int timeout = 0;

	timeout = 0xFFFF;

    while ((spi_reg_read(SSP2_SR) & (SSP_SR_TFL | SSP_SR_TF_NF | SSP_SR_BSY)) != SSP_SR_TF_NF)
	{
		if((timeout--) <= 0)
    	{
    		CPUartLogPrintf("[NZC]SPINOR_WaitSSPComplete timeout");
    		return SSPWaitCompleteTimeOutError;
        }
	}

	CPUartLogPrintf("%s:Exit", __func__);

	return NoError;
}

/* START SPI DMA transfer*/
static UINT32 QUEC_SPI_SSP0_DMA_transfer(unsigned char *inbuf, unsigned char *outbuf, unsigned int len)
{
    UINT32  i = 0;
    UINT32  flag_value, Retval = NoError;
    DMA_CMDx_T RX_Cmd, TX_Cmd;
	OSA_STATUS os_status = OS_SUCCESS;

	ASSERT(len <= SSP0_DMA_BUF_LEN);

	ASSERT(OSASemaphoreAcquire(SSP0SemaRef, OS_SUSPEND) == OS_SUCCESS);

	//paddy.li 2020-06-16 fix SPI DMA Transfer Fail when without USB PLUGIN	
	//SleepFlag_SPI_Interface_DMA_Set(1);

	if(outbuf != NULL)
	{
		memcpy(DMA_SSP0_Tx_buf, outbuf, len);
	}
	else
	{
		memset(&DMA_SSP0_Tx_buf[0], 0xFF, 8);
	}

    //fill out commands
    RX_Cmd.value = 0;
    RX_Cmd.bits.IncSrcAddr = 0;
    RX_Cmd.bits.IncTrgAddr = 1;
    RX_Cmd.bits.FlowSrc = 1;
    RX_Cmd.bits.FlowTrg = 0;
    RX_Cmd.bits.Width = 1;
    RX_Cmd.bits.MaxBurstSize = 1;
    RX_Cmd.bits.Length = len;


    TX_Cmd.value = 0;
    TX_Cmd.bits.IncSrcAddr = (outbuf != NULL);//if outbuf is not NULL, set IncSrcAddr 1,  else set IncSrcAddr 0
    TX_Cmd.bits.IncTrgAddr = 0;
    TX_Cmd.bits.FlowSrc = 0;
    TX_Cmd.bits.FlowTrg = 1;
    TX_Cmd.bits.Width = 1;
    TX_Cmd.bits.MaxBurstSize = 1;
    TX_Cmd.bits.Length = len;

    //setup DMA
    //Map Device to Channels
    XllpDmacMapDeviceToChannel(SSP0_RX_DMA_DEVICE, SSP0_RX_CHANNEL);//map dma channel in DMA_RCMRx
    XllpDmacMapDeviceToChannel(SSP0_TX_DMA_DEVICE, SSP0_TX_CHANNEL);//map dma channel in DMA_RCMRx

    XllpDmacNoDescriptorFetch(SSP0_RX_CHANNEL);//set No-Descriptor Fetch bit in DMA_CSR031 
    XllpDmacNoDescriptorFetch(SSP0_TX_CHANNEL);//set No-Descriptor Fetch bit in DMA_CSR031 

    //turn ON user alignment - in case buffer address is 64bit aligned
    alignChannel(SSP0_RX_CHANNEL, 1);    // 1 = user aligned (source and target addresses)
    alignChannel(SSP0_TX_CHANNEL, 1);	 //DALGNX |= 1 << SSP0_TX_CHANNEL
	
	//CPUartLogPrintf("TXCMD:0x%x, RXCMD:0x%x, raddr:0x%x, &DMA_SSP0_Tx_buf[0]=0x%x, &DMA_SSP0_Rx_buf[0]=0x%x\n", TX_Cmd.value, RX_Cmd.value, read_buff, &DMA_SSP0_Tx_buf[0], &DMA_SSP0_Rx_buf[0]);

    loadNonDescriptor((UINT32)SSP0_DR, (UINT32)&DMA_SSP0_Rx_buf[0], &RX_Cmd, SSP0_RX_CHANNEL);//CMDx=RX_Cmd.value, TADRx=read_buff, SADRx=SSP0_DR
    loadNonDescriptor((UINT32)&DMA_SSP0_Tx_buf[0], (UINT32)SSP0_DR, &TX_Cmd, SSP0_TX_CHANNEL);

    //make sure SSP is disabled
     Disable_SPI_SSP0();

    //reset SSP CR's
    spi_reg_write(SSP0_TCR, SSP0_TCR_INITIAL | v_spimode);
    spi_reg_write(SSP0_FCR, SSP0_FCR_INITIAL);
    spi_reg_write(SSP0_IER, SSP0_IER_INITIAL);
	/*Fias 2021-09-06 锟斤拷锟斤拷 Time Out Register TOR值*/
    spi_reg_write(SSP0_TOR, 0x300);

    //setup in 8bit mode
    spi_reg_bit_clr(SSP0_TCR, SSP_TCR_DSS_MASK);
    spi_reg_bit_set(SSP0_TCR, SSP_TCR_DSS8);
    //spi_reg_bit_set(SSP_TCR, SSP_TCR_DSS8);

    //setup FIFO CTRL, use SSP to do endian convert
    spi_reg_write(SSP0_FCR, SSP0_FCR_DMA_READ | SSP_FCR_RRE(0) | SSP_FCR_RAFC);
    spi_reg_bit_set(SSP0_TCR, SSP_TCR_TRIAL);

    //setup IER
    spi_reg_bit_set(SSP0_IER, SSP_IER_TIE | SSP_IER_RIE | SSP_IER_RTOIE);

    //fire SSP up
     Enable_SPI_SSP0();

    //Kick off DMA
#ifdef SSP0_DMA_INT_SUPPORT
	XllpDmacStartTransferWithStopIrqEnable(SSP0_RX_CHANNEL); //enable SSP0 RX DMA STOP INT
#else
    XllpDmacStartTransfer(SSP0_RX_CHANNEL);
#endif	

    XllpDmacStartTransfer(SSP0_TX_CHANNEL);

	CPUartLogPrintf("%s,kick off DMA",__func__);


#ifdef SSP0_DMA_INT_SUPPORT
	os_status = OSAFlagWait( SSP0_DMA_Done_FlgRef, 0x01, OSA_FLAG_OR_CLEAR, &flag_value, 10 );
	if(os_status == OS_SUCCESS)
	{
		CPUartLogPrintf("DMA Transfer Done,len=0x%x",len);
	}
	else
	{
		
	   UINT32 timeout = 0xFFFF;
	    //wait until the RX channel gets the stop UINT_Terrupt and the TX fifo is drained
	    while( ((readDmaStatusRegister(SSP0_RX_CHANNEL) & XLLP_DMAC_DCSR_STOP_INTR) != XLLP_DMAC_DCSR_STOP_INTR) )
	    {
	        //if we've waited long enough, fail
	        if((timeout--) <= 0)
	        {
	            RTI_LOG("TIMEOUT, os_status=0x%x, DMA Status 0x%x, SSP Status 0x%x", os_status, readDmaStatusRegister(SSP0_RX_CHANNEL), *SSP0_SR);
	            Retval = SSPRxChannelTimeOutError;
				break;
	        }		
	    }
		if(Retval == NoError)
			CPUartLogPrintf("%s,DMA Transfer Done after polling",__func__);
	}
#endif

	SPI_SSP0_WaitSSPComplete();
    //make sure SSP is disabled
    spi_reg_bit_clr(SSP0_TCR, SSP_TCR_SSE | SSP_TCR_HFL);
    //reset SSP CR's
    spi_reg_write(SSP0_TCR, SSP0_TCR_INITIAL);
    spi_reg_write(SSP0_FCR, SSP0_FCR_INITIAL);
    spi_reg_write(SSP0_IER, SSP0_IER_INITIAL);
    spi_reg_write(SSP0_TOR, 0);

    //clear out DMA settings
    XllpDmacUnMapDeviceToChannel(SSP0_RX_DMA_DEVICE, SSP0_RX_CHANNEL);
    XllpDmacUnMapDeviceToChannel(SSP0_TX_DMA_DEVICE, SSP0_TX_CHANNEL);

	if(inbuf)
		memcpy( (UINT8 *)inbuf, DMA_SSP0_Rx_buf, len );
	/*else
		for(i=0;i<len;i++)
			CPUartLogPrintf("DMA_SSP0_Rx_buf[%d]=0x%x\n", i, DMA_SSP0_Rx_buf[i]);
	*/

	//paddy.li 2020-06-16 fix SPI DMA Transfer Fail when without USB PLUGIN	
	//SleepFlag_SPI_Interface_DMA_Set(0);

	ASSERT(OSASemaphoreRelease(SSP0SemaRef) == OS_SUCCESS);
    return Retval;
}

/* START SPI DMA transfer*/
static UINT32 QUEC_SPI_SSP1_DMA_transfer(unsigned char *inbuf, unsigned char *outbuf, unsigned int len)
{
    UINT32  i = 0;
    UINT32  flag_value, Retval = NoError;
    DMA_CMDx_T RX_Cmd, TX_Cmd;
	OSA_STATUS os_status = OS_SUCCESS;

	ASSERT(len <= SSP1_DMA_BUF_LEN);

	ASSERT(OSASemaphoreAcquire(SSP1SemaRef, OS_SUSPEND) == OS_SUCCESS);

	//paddy.li 2020-06-16 fix SPI DMA Transfer Fail when without USB PLUGIN	
	//SleepFlag_SPI_Interface_DMA_Set(1);

	if(outbuf != NULL)
	{
		memcpy(DMA_SSP1_Tx_buf, outbuf, len);
	}
	else
	{
		memset(&DMA_SSP1_Tx_buf[0], 0xFF, 8);
	}

    //fill out commands
    RX_Cmd.value = 0;
    RX_Cmd.bits.IncSrcAddr = 0;
    RX_Cmd.bits.IncTrgAddr = 1;
    RX_Cmd.bits.FlowSrc = 1;
    RX_Cmd.bits.FlowTrg = 0;
    RX_Cmd.bits.Width = 1;
    RX_Cmd.bits.MaxBurstSize = 1;
    RX_Cmd.bits.Length = len;


    TX_Cmd.value = 0;
    TX_Cmd.bits.IncSrcAddr = (outbuf != NULL);//if outbuf is not NULL, set IncSrcAddr 1,  else set IncSrcAddr 0
    TX_Cmd.bits.IncTrgAddr = 0;
    TX_Cmd.bits.FlowSrc = 0;
    TX_Cmd.bits.FlowTrg = 1;
    TX_Cmd.bits.Width = 1;
    TX_Cmd.bits.MaxBurstSize = 1;
    TX_Cmd.bits.Length = len;

    //setup DMA
    //Map Device to Channels
    XllpDmacMapDeviceToChannel(SSP1_RX_DMA_DEVICE, SSP1_RX_CHANNEL);//map dma channel in DMA_RCMRx
    XllpDmacMapDeviceToChannel(SSP1_TX_DMA_DEVICE, SSP1_TX_CHANNEL);//map dma channel in DMA_RCMRx

    XllpDmacNoDescriptorFetch(SSP1_RX_CHANNEL);//set No-Descriptor Fetch bit in DMA_CSR031 
    XllpDmacNoDescriptorFetch(SSP1_TX_CHANNEL);//set No-Descriptor Fetch bit in DMA_CSR031 

    //turn ON user alignment - in case buffer address is 64bit aligned
    alignChannel(SSP1_RX_CHANNEL, 1);    // 1 = user aligned (source and target addresses)
    alignChannel(SSP1_TX_CHANNEL, 1);	 //DALGNX |= 1 << SSP1_TX_CHANNEL
	
	//CPUartLogPrintf("TXCMD:0x%x, RXCMD:0x%x, raddr:0x%x, &DMA_SSP1_Tx_buf[0]=0x%x, &DMA_SSP1_Rx_buf[0]=0x%x\n", TX_Cmd.value, RX_Cmd.value, read_buff, &DMA_SSP1_Tx_buf[0], &DMA_SSP1_Rx_buf[0]);

    loadNonDescriptor((UINT32)SSP1_DR, (UINT32)&DMA_SSP1_Rx_buf[0], &RX_Cmd, SSP1_RX_CHANNEL);//CMDx=RX_Cmd.value, TADRx=read_buff, SADRx=SSP1_DR
    loadNonDescriptor((UINT32)&DMA_SSP1_Tx_buf[0], (UINT32)SSP1_DR, &TX_Cmd, SSP1_TX_CHANNEL);

    //make sure SSP is disabled
     Disable_SPI_SSP1();

    //reset SSP CR's
    spi_reg_write(SSP1_TCR, SSP1_TCR_INITIAL | v_spimode);
    spi_reg_write(SSP1_FCR, SSP1_FCR_INITIAL);
    spi_reg_write(SSP1_IER, SSP1_IER_INITIAL);
	/*Fias 2021-09-06 锟斤拷锟斤拷 Time Out Register TOR值*/
    spi_reg_write(SSP1_TOR, 0x300);

    //setup in 8bit mode
    spi_reg_bit_clr(SSP1_TCR, SSP_TCR_DSS_MASK);
    spi_reg_bit_set(SSP1_TCR, SSP_TCR_DSS8);
    //spi_reg_bit_set(SSP_TCR, SSP_TCR_DSS8);

    //setup FIFO CTRL, use SSP to do endian convert
    spi_reg_write(SSP1_FCR, SSP1_FCR_DMA_READ | SSP_FCR_RRE(0) | SSP_FCR_RAFC);
    spi_reg_bit_set(SSP1_TCR, SSP_TCR_TRIAL);

    //setup IER
    spi_reg_bit_set(SSP1_IER, SSP_IER_TIE | SSP_IER_RIE | SSP_IER_RTOIE);

    //fire SSP up
     Enable_SPI_SSP1();

    //Kick off DMA
#ifdef SSP1_DMA_INT_SUPPORT
	XllpDmacStartTransferWithStopIrqEnable(SSP1_RX_CHANNEL); //enable SSP1 RX DMA STOP INT
#else
    XllpDmacStartTransfer(SSP1_RX_CHANNEL);
#endif	

    XllpDmacStartTransfer(SSP1_TX_CHANNEL);

	//CPUartLogPrintf("%s,kick off DMA",__func__);


#ifdef SSP1_DMA_INT_SUPPORT
	os_status = OSAFlagWait( SSP1_DMA_Done_FlgRef, 0x01, OSA_FLAG_OR_CLEAR, &flag_value, 10 );
	if(os_status == OS_SUCCESS)
	{
		//CPUartLogPrintf("DMA Transfer Done,len=0x%x",len);
	}
	else
	{
		
	   UINT32 timeout = 0xFFFF;
	    //wait until the RX channel gets the stop UINT_Terrupt and the TX fifo is drained
	    while( ((readDmaStatusRegister(SSP1_RX_CHANNEL) & XLLP_DMAC_DCSR_STOP_INTR) != XLLP_DMAC_DCSR_STOP_INTR) )
	    {
	        //if we've waited long enough, fail
	        if((timeout--) <= 0)
	        {
	            RTI_LOG("TIMEOUT, os_status=0x%x, DMA Status 0x%x, SSP Status 0x%x", os_status, readDmaStatusRegister(SSP1_RX_CHANNEL), *SSP1_SR);
	            Retval = SSPRxChannelTimeOutError;
				break;
	        }		
	    }
		if(Retval == NoError)
			CPUartLogPrintf("%s,DMA Transfer Done after polling",__func__);
	}
#endif

	SPI_SSP1_WaitSSPComplete();
    //make sure SSP is disabled
    spi_reg_bit_clr(SSP1_TCR, SSP_TCR_SSE | SSP_TCR_HFL);
    //reset SSP CR's
    spi_reg_write(SSP1_TCR, SSP1_TCR_INITIAL);
    spi_reg_write(SSP1_FCR, SSP1_FCR_INITIAL);
    spi_reg_write(SSP1_IER, SSP1_IER_INITIAL);
    spi_reg_write(SSP1_TOR, 0);

    //clear out DMA settings
    XllpDmacUnMapDeviceToChannel(SSP1_RX_DMA_DEVICE, SSP1_RX_CHANNEL);
    XllpDmacUnMapDeviceToChannel(SSP1_TX_DMA_DEVICE, SSP1_TX_CHANNEL);

	if(inbuf)
		memcpy( (UINT8 *)inbuf, DMA_SSP1_Rx_buf, len );
	/*else
		for(i=0;i<len;i++)
			CPUartLogPrintf("DMA_SSP1_Rx_buf[%d]=0x%x\n", i, DMA_SSP1_Rx_buf[i]);
	*/

	//paddy.li 2020-06-16 fix SPI DMA Transfer Fail when without USB PLUGIN	
	//SleepFlag_SPI_Interface_DMA_Set(0);

	ASSERT(OSASemaphoreRelease(SSP1SemaRef) == OS_SUCCESS);
    return Retval;
}


static UINT32 QUEC_SPI_SSP2_DMA_transfer(unsigned char *inbuf, unsigned char *outbuf, unsigned int len)
{
    UINT32  i = 0;
    UINT32  flag_value, Retval = NoError;
    DMA_CMDx_T RX_Cmd, TX_Cmd;
	OSA_STATUS os_status = OS_SUCCESS;

	ASSERT(len <= SSP2_DMA_BUF_LEN);

	
	ASSERT(OSASemaphoreAcquire(SSP2SemaRef, OS_SUSPEND) == OS_SUCCESS);
	//SleepFlag_SPI_Interface_DMA_Set(1);

	if(outbuf != NULL)
	{
		memcpy(DMA_SSP2_Tx_buf, outbuf, len);
	}
	else
	{
		memset(&DMA_SSP2_Tx_buf[0], 0xFF, 8);
	}

    //fill out commands
    RX_Cmd.value = 0;
    RX_Cmd.bits.IncSrcAddr = 0;
    RX_Cmd.bits.IncTrgAddr = 1;
    RX_Cmd.bits.FlowSrc = 1;
    RX_Cmd.bits.FlowTrg = 0;
    RX_Cmd.bits.Width = 1;
    RX_Cmd.bits.MaxBurstSize = 1;
    RX_Cmd.bits.Length = len;


    TX_Cmd.value = 0;
    TX_Cmd.bits.IncSrcAddr = (outbuf != NULL);//if outbuf is not NULL, set IncSrcAddr 1,  else set IncSrcAddr 0
    TX_Cmd.bits.IncTrgAddr = 0;
    TX_Cmd.bits.FlowSrc = 0;
    TX_Cmd.bits.FlowTrg = 1;
    TX_Cmd.bits.Width = 1;
    TX_Cmd.bits.MaxBurstSize = 1;
    TX_Cmd.bits.Length = len;

    //setup DMA
    //Map Device to Channels
    XllpDmacMapDeviceToChannel(SSP2_RX_DMA_DEVICE, SSP2_RX_CHANNEL);//map dma channel in DMA_RCMRx
    XllpDmacMapDeviceToChannel(SSP2_TX_DMA_DEVICE, SSP2_TX_CHANNEL);//map dma channel in DMA_RCMRx

    XllpDmacNoDescriptorFetch(SSP2_RX_CHANNEL);//set No-Descriptor Fetch bit in DMA_CSR031 
    XllpDmacNoDescriptorFetch(SSP2_TX_CHANNEL);//set No-Descriptor Fetch bit in DMA_CSR031 

    //turn ON user alignment - in case buffer address is 64bit aligned
    alignChannel(SSP2_RX_CHANNEL, 1);    // 1 = user aligned (source and target addresses)
    alignChannel(SSP2_TX_CHANNEL, 1);	 //DALGNX |= 1 << SSP0_TX_CHANNEL
	
    loadNonDescriptor((UINT32)SSP2_DR, (UINT32)&DMA_SSP2_Rx_buf[0], &RX_Cmd, SSP2_RX_CHANNEL);//CMDx=RX_Cmd.value, TADRx=read_buff, SADRx=SSP0_DR
    loadNonDescriptor((UINT32)&DMA_SSP2_Tx_buf[0], (UINT32)SSP2_DR, &TX_Cmd, SSP2_TX_CHANNEL);

    //make sure SSP is disabled
    Disable_SPI_SSP2();

    //reset SSP CR's
    spi_reg_write(SSP2_TCR, SSP2_TCR_INITIAL | v_spimode);
    spi_reg_write(SSP2_FCR, SSP2_FCR_INITIAL);
    spi_reg_write(SSP2_IER, SSP2_IER_INITIAL);
	/*Fias 2021-09-06 锟斤拷锟斤拷 Time Out Register TOR值*/
    spi_reg_write(SSP2_TOR, 0x300);

    //setup in 8bit mode
    spi_reg_bit_clr(SSP2_TCR, SSP_TCR_DSS_MASK);
    spi_reg_bit_set(SSP2_TCR, SSP_TCR_DSS8);
    //spi_reg_bit_set(SSP_TCR, SSP_TCR_DSS8);

    //setup FIFO CTRL, use SSP to do endian convert
    spi_reg_write(SSP2_FCR, SSP2_FCR_DMA_READ | SSP_FCR_RRE(0) | SSP_FCR_RAFC);
    spi_reg_bit_set(SSP2_TCR, SSP_TCR_TRIAL);

    //setup IER
    spi_reg_bit_set(SSP2_IER, SSP_IER_TIE | SSP_IER_RIE | SSP_IER_RTOIE);

    //fire SSP up
    Enable_SPI_SSP2();

    //Kick off DMA
#ifdef SSP2_DMA_INT_SUPPORT
	XllpDmacStartTransferWithStopIrqEnable(SSP2_RX_CHANNEL); //enable SSP0 RX DMA STOP INT
#else
    XllpDmacStartTransfer(SSP2_RX_CHANNEL);
#endif	

    XllpDmacStartTransfer(SSP2_TX_CHANNEL);

	CPUartLogPrintf("%s,kick off DMA",__func__);


#ifdef SSP2_DMA_INT_SUPPORT
	os_status = OSAFlagWait( SSP2_DMA_Done_FlgRef, 0x01, OSA_FLAG_OR_CLEAR, &flag_value, 10);
	if(os_status == OS_SUCCESS)
	{
		CPUartLogPrintf("DMA Transfer Done,len=0x%x",len);
	}
	else
	{
		UINT32 timeout = 0xFFFF;
	    //wait until the RX channel gets the stop UINT_Terrupt and the TX fifo is drained
	    while( ((readDmaStatusRegister(SSP2_RX_CHANNEL) & XLLP_DMAC_DCSR_STOP_INTR) != XLLP_DMAC_DCSR_STOP_INTR) )
	    {
	        //if we've waited long enough, fail
	        if((timeout--) <= 0)
	        {
	            RTI_LOG("TIMEOUT, os_status=0x%x, DMA Status 0x%x, SSP Status 0x%x", os_status, readDmaStatusRegister(SSP2_RX_CHANNEL), *SSP2_SR);
	            Retval = SSPRxChannelTimeOutError;
				break;
	        }		
	    }
		if(Retval == NoError)
			CPUartLogPrintf("%s,DMA Transfer Done after polling",__func__);
	}
#endif

	SPI_SSP2_WaitSSPComplete();

    //make sure SSP is disabled
    spi_reg_bit_clr(SSP2_TCR, SSP_TCR_SSE | SSP_TCR_HFL);
    //reset SSP CR's
    spi_reg_write(SSP2_TCR, SSP2_TCR_INITIAL);
    spi_reg_write(SSP2_FCR, SSP2_FCR_INITIAL);
    spi_reg_write(SSP2_IER, SSP2_IER_INITIAL);
    spi_reg_write(SSP2_TOR, 0);

    //clear out DMA settings
    XllpDmacUnMapDeviceToChannel(SSP2_RX_DMA_DEVICE, SSP2_RX_CHANNEL);
    XllpDmacUnMapDeviceToChannel(SSP2_TX_DMA_DEVICE, SSP2_TX_CHANNEL);

	if(inbuf)
		memcpy( (UINT8 *)inbuf, DMA_SSP2_Rx_buf, len );
	/*else
		for(i=0;i<len;i++)
			CPUartLogPrintf("DMA_SSP0_Rx_buf[%d]=0x%x\n", i, DMA_SSP0_Rx_buf[i]);
	*/

	//SleepFlag_SPI_Interface_DMA_Set(0);

	ASSERT(OSASemaphoreRelease(SSP2SemaRef) == OS_SUCCESS);	
    return Retval;
}



#ifdef SSP0_DMA_INT_SUPPORT
int SSP0_DMA_DONE_ISR(UINT32 val) 
{
	XllpDmacStopTransfer( SSP0_RX_CHANNEL );
	XllpDmacStopTransfer( SSP0_TX_CHANNEL );
	OSAFlagSet(SSP0_DMA_Done_FlgRef, 0x01, OSA_FLAG_OR);
	//CPUartLogPrintf("yjy,ssp0 dma stop int,ch:%d\n", SSP0_RX_CHANNEL);
	return 0;
}
#endif

#ifdef SSP1_DMA_INT_SUPPORT
int SSP1_DMA_DONE_ISR(UINT32 val) 
{
	XllpDmacStopTransfer( SSP1_RX_CHANNEL );
	XllpDmacStopTransfer( SSP1_TX_CHANNEL );
	OSAFlagSet(SSP1_DMA_Done_FlgRef, 0x01, OSA_FLAG_OR);
	//CPUartLogPrintf("yjy,SSP1 dma stop int,ch:%d\n", SSP1_RX_CHANNEL);
	return 0;
}
#endif


#ifdef SSP2_DMA_INT_SUPPORT
int SSP2_DMA_DONE_ISR(UINT32 val) 
{
	XllpDmacStopTransfer( SSP2_RX_CHANNEL );
	XllpDmacStopTransfer( SSP2_TX_CHANNEL );
	OSAFlagSet(SSP2_DMA_Done_FlgRef, 0x01, OSA_FLAG_OR);
	//CPUartLogPrintf("yjy,ssp2 dma stop int,ch:%d\n", SSP2_RX_CHANNEL);
	return 0;
}
#endif


UINT32 QUEC_SPI_SSP0_DataTransfer(unsigned char *inbuf, unsigned char *outbuf, unsigned int len)
{
    UINT32 Retval = NoError;
	
	while(len > SSP0_DMA_BUF_LEN)
	{
		Retval = QUEC_SPI_SSP0_DMA_transfer(inbuf, outbuf, SSP0_DMA_BUF_LEN);
		if(Retval != NoError)
			return Retval;

		inbuf += SSP0_DMA_BUF_LEN;
		outbuf += SSP0_DMA_BUF_LEN;
		len -= SSP0_DMA_BUF_LEN;
	}

	if(len != 0)
		Retval = QUEC_SPI_SSP0_DMA_transfer(inbuf, outbuf, len);

	return Retval;
}
UINT32 QUEC_SPI_SSP1_DataTransfer(unsigned char *inbuf, unsigned char *outbuf, unsigned int len)
{
    UINT32 Retval = NoError;
	
	while(len > SSP1_DMA_BUF_LEN)
	{
		Retval = QUEC_SPI_SSP1_DMA_transfer(inbuf, outbuf, SSP1_DMA_BUF_LEN);
		if(Retval != NoError)
			return Retval;

		inbuf += SSP1_DMA_BUF_LEN;
		outbuf += SSP1_DMA_BUF_LEN;
		len -= SSP1_DMA_BUF_LEN;
	}

	if(len != 0)
		Retval = QUEC_SPI_SSP1_DMA_transfer(inbuf, outbuf, len);

	return Retval;
}

UINT32 QUEC_SPI_SSP2_DataTransfer(unsigned char *inbuf, unsigned char *outbuf, unsigned int len)
{
    UINT32 Retval = NoError;
	
	while(len > SSP2_DMA_BUF_LEN)
	{
		Retval = QUEC_SPI_SSP2_DMA_transfer(inbuf, outbuf, SSP2_DMA_BUF_LEN);
		if(Retval != NoError)
			return Retval;

		inbuf += SSP2_DMA_BUF_LEN;
		outbuf += SSP2_DMA_BUF_LEN;
		len -= SSP2_DMA_BUF_LEN;
	}

	if(len != 0)
		Retval = QUEC_SPI_SSP2_DMA_transfer(inbuf, outbuf, len);

	return Retval;
}


UINT32 QUEC_SPI_SSP0_DMA_WriteData(unsigned char *buf, unsigned int len)
{
    UINT32 Retval = NoError;
	
	while(len > SSP0_DMA_BUF_LEN)
	{
		Retval = QUEC_SPI_SSP0_DMA_transfer(NULL, buf, SSP0_DMA_BUF_LEN);
		if(Retval != NoError)
			return Retval;

		buf += SSP0_DMA_BUF_LEN;
		len -= SSP0_DMA_BUF_LEN;
	}

	if(len != 0)
		Retval = QUEC_SPI_SSP0_DMA_transfer(NULL, buf, len);


	return Retval;
}

UINT32 QUEC_SPI_SSP1_DMA_WriteData(unsigned char *buf, unsigned int len)
{
    UINT32 Retval = NoError;
	
	while(len > SSP1_DMA_BUF_LEN)
	{
		Retval = QUEC_SPI_SSP1_DMA_transfer(NULL, buf, SSP1_DMA_BUF_LEN);
		if(Retval != NoError)
			return Retval;

		buf += SSP1_DMA_BUF_LEN;
		len -= SSP1_DMA_BUF_LEN;
	}

	if(len != 0)
		Retval = QUEC_SPI_SSP1_DMA_transfer(NULL, buf, len);


	return Retval;
}
UINT32 QUEC_SPI_SSP2_DMA_WriteData(unsigned char *buf, unsigned int len)
{
    UINT32 Retval = NoError;
	
	while(len > SSP2_DMA_BUF_LEN)
	{
		Retval = QUEC_SPI_SSP2_DMA_transfer(NULL, buf, SSP2_DMA_BUF_LEN);
		if(Retval != NoError)
			return Retval;

		buf += SSP2_DMA_BUF_LEN;
		len -= SSP2_DMA_BUF_LEN;
	}

	if(len != 0)
		Retval = QUEC_SPI_SSP2_DMA_transfer(NULL, buf, len);


	return Retval;
}


UINT32 QUEC_SPI_SSP0_DMA_ReadData(unsigned char *buf, unsigned int len)
{
    UINT32 Retval = NoError;
	
	while(len > SSP0_DMA_BUF_LEN)
	{
		Retval = QUEC_SPI_SSP0_DMA_transfer(buf, NULL, SSP0_DMA_BUF_LEN);
		
		if(Retval != NoError)
			return Retval;

		buf += SSP0_DMA_BUF_LEN;
		len -= SSP0_DMA_BUF_LEN;
	}

	if(len != 0)
		Retval = QUEC_SPI_SSP0_DMA_transfer(buf, NULL, len);

	return Retval;
}
UINT32 QUEC_SPI_SSP1_DMA_ReadData(unsigned char *buf, unsigned int len)
{
    UINT32 Retval = NoError;
	
	while(len > SSP1_DMA_BUF_LEN)
	{
		Retval = QUEC_SPI_SSP1_DMA_transfer(buf, NULL, SSP1_DMA_BUF_LEN);
		
		if(Retval != NoError)
			return Retval;

		buf += SSP1_DMA_BUF_LEN;
		len -= SSP1_DMA_BUF_LEN;
	}

	if(len != 0)
		Retval = QUEC_SPI_SSP1_DMA_transfer(buf, NULL, len);

	return Retval;
}

UINT32 QUEC_SPI_SSP2_DMA_ReadData(unsigned char *buf, unsigned int len)
{
    UINT32 Retval = NoError;
	
	while(len > SSP2_DMA_BUF_LEN)
	{
		Retval = QUEC_SPI_SSP2_DMA_transfer(buf, NULL, SSP2_DMA_BUF_LEN);
		
		if(Retval != NoError)
			return Retval;

		buf += SSP2_DMA_BUF_LEN;
		len -= SSP2_DMA_BUF_LEN;
	}

	if(len != 0)
		Retval = QUEC_SPI_SSP2_DMA_transfer(buf, NULL, len);

	return Retval;
}

/* END SPI DMA transfer*/


/* START SPI FIFO transfer*/
//#ifdef  QUEC_SPI_FIFO
void QUEC_SPI_SSP0_PIO_transfer(unsigned char *buf_in,unsigned char *buf_out, unsigned int len)
{
	unsigned int out_index = 0,in_index = 0;
	unsigned int tmp_rxfifo;
    unsigned char TxFifoLevel, RxFifoLevel;
	//unsigned char miso_data;
	int i;
    
	Disable_SPI_SSP0();
	SPI_SSP0_DSS(8);
	Enable_SPI_SSP0();
	

	//SpiCsEnalbe();
	if(((*SSP0_SR) & SSP_SR_TX_FIFO_NOT_FULL) == 0)
	TxFifoLevel = 32; //1802s TxFIFO Trigger Level max vaule is 32
    else
	TxFifoLevel = ((*SSP0_SR)>>7)&0x1f;

	for(i=TxFifoLevel; i<32 && out_index<len; i++)
	{
		BU_REG_WRITE8(SSP0_DR, buf_out[out_index++]);
       //uart_printf("%s:buf_out[%d]=0x%x", __func__, out_index-1,buf_out[out_index-1]);
	}
    do{
    
        tmp_rxfifo=*SSP0_SR;
    
        RxFifoLevel=((tmp_rxfifo>>15)&0x1f);
     
        if(((tmp_rxfifo & SSP_SR_RX_FIFO_NOT_EMPTY) == 0) && RxFifoLevel == 0x1f)
        {
         RxFifoLevel=0;
        }
        else
        {
         RxFifoLevel++;
        }
           for(i = 0; i<RxFifoLevel && in_index<len; i++)
           {
               buf_in[in_index++] = BU_REG_READ8(SSP0_DR); 
               if(out_index<len)
               BU_REG_WRITE8(SSP0_DR, buf_out[out_index++]);
               //uart_printf("%s:buf_in[%d]=0x%x", __func__, in_index-1,buf_in[in_index-1]);
           }  
     }while(in_index <len);
    
	Disable_SPI_SSP0();

    
}

void QUEC_SPI_SSP1_PIO_transfer(unsigned char *buf_in,unsigned char *buf_out, unsigned int len)
{
	unsigned int out_index = 0,in_index = 0;
	unsigned int tmp_rxfifo;
    unsigned char TxFifoLevel, RxFifoLevel;
	//unsigned char miso_data;
	int i;
    
	Disable_SPI_SSP1();
	SPI_SSP1_DSS(8);
	Enable_SPI_SSP1();
	

	//SpiCsEnalbe();
	if(((*SSP1_SR) & SSP_SR_TX_FIFO_NOT_FULL) == 0)
	TxFifoLevel = 32; //1802s TxFIFO Trigger Level max vaule is 32
    else
	TxFifoLevel = ((*SSP1_SR)>>7)&0x1f;

	for(i=TxFifoLevel; i<32 && out_index<len; i++)
	{
		BU_REG_WRITE8(SSP1_DR, buf_out[out_index++]);
       //uart_printf("%s:buf_out[%d]=0x%x", __func__, out_index-1,buf_out[out_index-1]);
	}
    do{
    
        tmp_rxfifo=*SSP1_SR;
    
        RxFifoLevel=((tmp_rxfifo>>15)&0x1f);
     
        if(((tmp_rxfifo & SSP_SR_RX_FIFO_NOT_EMPTY) == 0) && RxFifoLevel == 0x1f)
        {
         RxFifoLevel=0;
        }
        else
        {
         RxFifoLevel++;
        }
           for(i = 0; i<RxFifoLevel && in_index<len; i++)
           {
               buf_in[in_index++] = BU_REG_READ8(SSP1_DR); 
               if(out_index<len)
               BU_REG_WRITE8(SSP1_DR, buf_out[out_index++]);
               //uart_printf("%s:buf_in[%d]=0x%x", __func__, in_index-1,buf_in[in_index-1]);
           }  
     }while(in_index <len);
    
	Disable_SPI_SSP1();

    
}

void QUEC_SPI_SSP2_PIO_transfer(unsigned char *buf_in,unsigned char *buf_out, unsigned int len)
{
	unsigned int out_index = 0,in_index = 0;
	unsigned int tmp_rxfifo;
    unsigned char TxFifoLevel, RxFifoLevel;
	//unsigned char miso_data;
	int i;
    
	Disable_SPI_SSP2();
	SPI_SSP2_DSS(8);
	Enable_SPI_SSP2();
	

	//SpiCsEnalbe();
	if(((*SSP2_SR) & SSP_SR_TX_FIFO_NOT_FULL) == 0)
	TxFifoLevel = 32; //1802s TxFIFO Trigger Level max vaule is 32
    else
	TxFifoLevel = ((*SSP2_SR)>>7)&0x1f;

	for(i=TxFifoLevel; i<32 && out_index<len; i++)
	{
		BU_REG_WRITE8(SSP2_DR, buf_out[out_index++]);
       //uart_printf("%s:buf_out[%d]=0x%x", __func__, out_index-1,buf_out[out_index-1]);
	}
    do{
    
        tmp_rxfifo=*SSP2_SR;
    
        RxFifoLevel=((tmp_rxfifo>>15)&0x1f);
     
        if(((tmp_rxfifo & SSP_SR_RX_FIFO_NOT_EMPTY) == 0) && RxFifoLevel == 0x1f)
        {
         RxFifoLevel=0;
        }
        else
        {
         RxFifoLevel++;
        }
           for(i = 0; i<RxFifoLevel && in_index<len; i++)
           {
               buf_in[in_index++] = BU_REG_READ8(SSP2_DR); 
               if(out_index<len)
               BU_REG_WRITE8(SSP2_DR, buf_out[out_index++]);
               //uart_printf("%s:buf_in[%d]=0x%x", __func__, in_index-1,buf_in[in_index-1]);
           }  
     }while(in_index <len);
    
	Disable_SPI_SSP2();
    
}

/***********************************************************
*   SPI_SSP0_Write
*   	PIO mode to write and then read out the data
*   Returns:
*	    None
*************************************************************/
void QUEC_SPI_SSP0_PIO_Write(unsigned char *buf, unsigned int len)
{
	unsigned int out_index = 0,in_index = 0;
	unsigned int tmp_rxfifo;
    unsigned char TxFifoLevel, RxFifoLevel;
	unsigned char miso_data;
	int i;
    
	Disable_SPI_SSP0();
	SPI_SSP0_DSS(8);
	Enable_SPI_SSP0();
	

	//SpiCsEnalbe();
	if(((*SSP0_SR) & SSP_SR_TX_FIFO_NOT_FULL) == 0)
	TxFifoLevel = 32; //1802s TxFIFO Trigger Level max vaule is 32
    else
	TxFifoLevel = ((*SSP0_SR)>>7)&0x1f;

	for(i=TxFifoLevel; i<32 && out_index<len; i++)
	{
		BU_REG_WRITE8(SSP0_DR, buf[out_index++]);
       //uart_printf("%s:buf_out[%d]=0x%x", __func__, out_index-1,buf_out[out_index-1]);
	}
    do{
    
        tmp_rxfifo=*SSP0_SR;
    
        RxFifoLevel=((tmp_rxfifo>>15)&0x1f);
     
        if(((tmp_rxfifo & SSP_SR_RX_FIFO_NOT_EMPTY) == 0) && RxFifoLevel == 0x1f)
        {
         RxFifoLevel=0;
        }
        else
        {
         RxFifoLevel++;
        }
           for(i = 0; i<RxFifoLevel && in_index<len; i++)
           {
               miso_data = BU_REG_READ8(SSP0_DR);
               in_index++;
               if(out_index<len)
               BU_REG_WRITE8(SSP0_DR, buf[out_index++]);
               //uart_printf("%s:buf_in[%d]=0x%x", __func__, in_index-1,buf_in[in_index-1]);
           }  
     }while(in_index <len);
    
	Disable_SPI_SSP0();

    /*asr add end*/
}

void QUEC_SPI_SSP1_PIO_Write(unsigned char *buf, unsigned int len)
{
	unsigned int out_index = 0,in_index = 0;
	unsigned int tmp_rxfifo;
    unsigned char TxFifoLevel, RxFifoLevel;
	unsigned char miso_data;
	int i;
    
	Disable_SPI_SSP1();
	SPI_SSP1_DSS(8);
	Enable_SPI_SSP1();
	

	//SpiCsEnalbe();
	if(((*SSP1_SR) & SSP_SR_TX_FIFO_NOT_FULL) == 0)
	TxFifoLevel = 32; //1802s TxFIFO Trigger Level max vaule is 32
    else
	TxFifoLevel = ((*SSP1_SR)>>7)&0x1f;

	for(i=TxFifoLevel; i<32 && out_index<len; i++)
	{
		BU_REG_WRITE8(SSP1_DR, buf[out_index++]);
       //uart_printf("%s:buf_out[%d]=0x%x", __func__, out_index-1,buf_out[out_index-1]);
	}
    do{
    
        tmp_rxfifo=*SSP1_SR;
    
        RxFifoLevel=((tmp_rxfifo>>15)&0x1f);
     
        if(((tmp_rxfifo & SSP_SR_RX_FIFO_NOT_EMPTY) == 0) && RxFifoLevel == 0x1f)
        {
         RxFifoLevel=0;
        }
        else
        {
         RxFifoLevel++;
        }
           for(i = 0; i<RxFifoLevel && in_index<len; i++)
           {
               miso_data = BU_REG_READ8(SSP1_DR);
               in_index++;
               if(out_index<len)
               BU_REG_WRITE8(SSP1_DR, buf[out_index++]);
               //uart_printf("%s:buf_in[%d]=0x%x", __func__, in_index-1,buf_in[in_index-1]);
           }  
     }while(in_index <len);
    
	Disable_SPI_SSP1();

    /*asr add end*/
}
/***********************************************************
*   SPI_SSP2_Write
*   	PIO mode to write and then read out the data
*   Returns:
*	    None
*************************************************************/
void QUEC_SPI_SSP2_PIO_Write(unsigned char *buf, unsigned int len)
{
    unsigned int out_index = 0,in_index = 0;
	unsigned int tmp_rxfifo;
    unsigned char TxFifoLevel, RxFifoLevel;
	unsigned char miso_data;
	int i;
    
	Disable_SPI_SSP2();
	SPI_SSP2_DSS(8);
	Enable_SPI_SSP2();
	

	//SpiCsEnalbe();
	if(((*SSP2_SR) & SSP_SR_TX_FIFO_NOT_FULL) == 0)
	TxFifoLevel = 32; //1802s TxFIFO Trigger Level max vaule is 32
    else
	TxFifoLevel = ((*SSP2_SR)>>7)&0x1f;

	for(i=TxFifoLevel; i<32 && out_index<len; i++)
	{
		BU_REG_WRITE8(SSP2_DR, buf[out_index++]);
       //uart_printf("%s:buf_out[%d]=0x%x", __func__, out_index-1,buf_out[out_index-1]);
	}
    do{
    
        tmp_rxfifo=*SSP2_SR;
    
        RxFifoLevel=((tmp_rxfifo>>15)&0x1f);
     
        if(((tmp_rxfifo & SSP_SR_RX_FIFO_NOT_EMPTY) == 0) && RxFifoLevel == 0x1f)
        {
         RxFifoLevel=0;
        }
        else
        {
         RxFifoLevel++;
        }
           for(i = 0; i<RxFifoLevel && in_index<len; i++)
           {
               miso_data = BU_REG_READ8(SSP2_DR);
               in_index++;
               if(out_index<len)
               BU_REG_WRITE8(SSP2_DR, buf[out_index++]);
               //uart_printf("%s:buf_in[%d]=0x%x", __func__, in_index-1,buf_in[in_index-1]);
           }  
     }while(in_index <len);
    
	Disable_SPI_SSP2();
}


/***********************************************************
*   SPI_SSP0_Read
*   	PIO mode to write and then read out the data
*   Returns:
*	    None
*************************************************************/
void QUEC_SPI_SSP0_PIO_Read(unsigned char *buf, unsigned int len, unsigned char mosi_status)
{
    unsigned int out_index = 0,in_index = 0;
	unsigned int tmp_rxfifo;
    unsigned char TxFifoLevel, RxFifoLevel;
	unsigned char mosi_data;
	int i;
    
	Disable_SPI_SSP0();
	SPI_SSP0_DSS(8);
	Enable_SPI_SSP0();
	if(mosi_status)
		mosi_data = 0xff;
	else
		mosi_data = 0x00;

	//SpiCsEnalbe();
	if(((*SSP0_SR) & SSP_SR_TX_FIFO_NOT_FULL) == 0)
	TxFifoLevel = 32; //1802s TxFIFO Trigger Level max vaule is 32
    else
	TxFifoLevel = ((*SSP0_SR)>>7)&0x1f;

	for(i=TxFifoLevel; i<32 && out_index<len; i++)
	{
		BU_REG_WRITE8(SSP0_DR, mosi_data);
        out_index++;
       //uart_printf("%s:buf_out[%d]=0x%x", __func__, out_index-1,buf_out[out_index-1]);
	}
    do{
    
        tmp_rxfifo=*SSP0_SR;
    
        RxFifoLevel=((tmp_rxfifo>>15)&0x1f);
     
        if(((tmp_rxfifo & SSP_SR_RX_FIFO_NOT_EMPTY) == 0) && RxFifoLevel == 0x1f)
        {
         RxFifoLevel=0;
        }
        else
        {
         RxFifoLevel++;
        }
           for(i = 0; i<RxFifoLevel && in_index<len; i++)
           {
               buf[in_index++] = BU_REG_READ8(SSP0_DR); 
               if(out_index<len)
               BU_REG_WRITE8(SSP0_DR, mosi_data);
               out_index++;
               //uart_printf("%s:buf_in[%d]=0x%x", __func__, in_index-1,buf_in[in_index-1]);
           }  
     }while(in_index <len);
    
	Disable_SPI_SSP0();
}

void QUEC_SPI_SSP1_PIO_Read(unsigned char *buf, unsigned int len, unsigned char mosi_status)
{
    unsigned int out_index = 0,in_index = 0;
	unsigned int tmp_rxfifo;
    unsigned char TxFifoLevel, RxFifoLevel;
	unsigned char mosi_data;
	int i;
    
	Disable_SPI_SSP1();
	SPI_SSP1_DSS(8);
	Enable_SPI_SSP1();
	if(mosi_status)
		mosi_data = 0xff;
	else
		mosi_data = 0x00;

	//SpiCsEnalbe();
	if(((*SSP1_SR) & SSP_SR_TX_FIFO_NOT_FULL) == 0)
	TxFifoLevel = 32; //1802s TxFIFO Trigger Level max vaule is 32
    else
	TxFifoLevel = ((*SSP1_SR)>>7)&0x1f;

	for(i=TxFifoLevel; i<32 && out_index<len; i++)
	{
		BU_REG_WRITE8(SSP1_DR, mosi_data);
        out_index++;
       //uart_printf("%s:buf_out[%d]=0x%x", __func__, out_index-1,buf_out[out_index-1]);
	}
    do{
    
        tmp_rxfifo=*SSP1_SR;
    
        RxFifoLevel=((tmp_rxfifo>>15)&0x1f);
     
        if(((tmp_rxfifo & SSP_SR_RX_FIFO_NOT_EMPTY) == 0) && RxFifoLevel == 0x1f)
        {
         RxFifoLevel=0;
        }
        else
        {
         RxFifoLevel++;
        }
           for(i = 0; i<RxFifoLevel && in_index<len; i++)
           {
               buf[in_index++] = BU_REG_READ8(SSP1_DR); 
               if(out_index<len)
               BU_REG_WRITE8(SSP1_DR, mosi_data);
               out_index++;
               //uart_printf("%s:buf_in[%d]=0x%x", __func__, in_index-1,buf_in[in_index-1]);
           }  
     }while(in_index <len);
    
	Disable_SPI_SSP1();
}
/***********************************************************
*   SPI_SSP2_Read
*   	PIO mode to write and then read out the data
*   Returns:
*	    None
*************************************************************/
void QUEC_SPI_SSP2_PIO_Read(unsigned char *buf, unsigned int len, unsigned char mosi_status)
{
    unsigned int out_index = 0,in_index = 0;
	unsigned int tmp_rxfifo;
    unsigned char TxFifoLevel, RxFifoLevel;
	unsigned char mosi_data;
	int i;
    
	Disable_SPI_SSP2();
	SPI_SSP2_DSS(8);
	Enable_SPI_SSP2();
	if(mosi_status)
		mosi_data = 0xff;
	else
		mosi_data = 0x00;

	//SpiCsEnalbe();
	if(((*SSP2_SR) & SSP_SR_TX_FIFO_NOT_FULL) == 0)
	TxFifoLevel = 32; //1802s TxFIFO Trigger Level max vaule is 32
    else
	TxFifoLevel = ((*SSP2_SR)>>7)&0x1f;

	for(i=TxFifoLevel; i<32 && out_index<len; i++)
	{
		BU_REG_WRITE8(SSP2_DR, mosi_data);
        out_index++;
       //uart_printf("%s:buf_out[%d]=0x%x", __func__, out_index-1,buf_out[out_index-1]);
	}
    do{
    
        tmp_rxfifo=*SSP2_SR;
    
        RxFifoLevel=((tmp_rxfifo>>15)&0x1f);
     
        if(((tmp_rxfifo & SSP_SR_RX_FIFO_NOT_EMPTY) == 0) && RxFifoLevel == 0x1f)
        {
         RxFifoLevel=0;
        }
        else
        {
         RxFifoLevel++;
        }
           for(i = 0; i<RxFifoLevel && in_index<len; i++)
           {
               buf[in_index++] = BU_REG_READ8(SSP2_DR); 
               if(out_index<len)
               BU_REG_WRITE8(SSP2_DR, mosi_data);
               out_index++;
               //uart_printf("%s:buf_in[%d]=0x%x", __func__, in_index-1,buf_in[in_index-1]);
           }  
     }while(in_index <len);
    
	Disable_SPI_SSP2();

}
/* END SPI FIFO transfer*/


/* SPI Init*/

int ssp0_inited = 0;
int ssp2_inited = 0;		//To prevent memory leaks due to frequent initialization
int ssp1_inited = 0;


void SPI_SSP0_Initialize(SPI_MODE_T spimode, SPI_CLK_T spiclk)
{
	unsigned int v_reg, v_spiclk,especially_spiclk=0 ;
    if(ssp0_inited== 0)
    {
    	ASSERT(OSAFlagCreate(&SSP0_DMA_Done_FlgRef) == OS_SUCCESS);
    	ASSERT(OSASemaphoreCreate(&SSP0SemaRef,1,OSA_PRIORITY) == OS_SUCCESS);

#ifdef SSP0_DMA_INT_SUPPORT
    	dma_irq_callback_register(SSP0_DMA_DONE_ISR,SSP0_RX_CHANNEL);
#endif
        ssp0_inited = 1;
    }

	switch(spimode)
	{
		case SPI_MODE0:
			v_spimode = SSP_SPI_MODE0;
			break;
		case SPI_MODE1:
			v_spimode = SSP_SPI_MODE1;
			break;
		case SPI_MODE2:
			v_spimode = SSP_SPI_MODE2;
			break;
		case SPI_MODE3:
			v_spimode = SSP_SPI_MODE3;
			break;
		default:
			v_spimode = SSP_SPI_MODE0;
			break;
	}

	switch(spiclk)
	{
		case SPI_CLK_100KHZ:
		case SPI_CLK_200KHZ:
		case SPI_CLK_300KHZ:
		case SPI_CLK_400KHZ:
		case SPI_CLK_500KHZ:
		case SPI_CLK_600KHZ:
		case SPI_CLK_700KHZ:	
			especially_spiclk=spiclk+1;
			break;
		case SPI_CLK_812_5KHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_812_5KHZ;
			break;
		case SPI_CLK_1_625MHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_1_625MHZ;
			break;
		case SPI_CLK_3_25MHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_3_25MHZ;
			break;
		case SPI_CLK_6_5MHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_6_5MHZ;
			break;
		case SPI_CLK_13MHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_13MHZ;
			break;
		case SPI_CLK_26MHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_26MHZ;
			break;
		case SPI_CLK_52MHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_52MHZ;
			break;
		default:
			v_spiclk= APBC_SSP0_FNCLKSEL_6_5MHZ;
			break;
	}

	if(0 != especially_spiclk)
	{
		spi_reg_bit_set(0xD4050008, BIT_27);	
		spi_reg_write(0xD4050044, 0xE0007800|((especially_spiclk*100/5)<<15));
		spi_reg_write(APBC_SSP0_CLK_RST, 0x7B);
		CPUartLogPrintf("%s:especially_spiclk=%d ;spiclk= %d]", __func__, especially_spiclk,spiclk);
	}
	else
	{
		spi_reg_write(APBC_SSP0_CLK_RST, APBC_SSP0_APBCLK_ENABLE|APBC_SSP0_FNCLK_ENABLE|APBC_SSP0_RST);	
		spi_reg_write(APBC_SSP0_CLK_RST, APBC_SSP0_APBCLK_ENABLE|APBC_SSP0_FNCLK_ENABLE|v_spiclk);
	}
	CPUartLogPrintf("%s:APBC_SSP0_CLK_RST[0x%x]", __func__, spi_reg_read(APBC_SSP0_CLK_RST));

   	v_reg = spi_reg_read(APBC_GPIO_CLK_RST);  //0xD4015008   APBC_GPIO_CLK_RST
    if((v_reg & 0x3) != 0x3)
    {
    	CPUartLogPrintf("%s:v_reg[0x%x]", __func__, v_reg);
    	//if clk is not enable,-->reset and enable
    	spi_reg_write(APBC_GPIO_CLK_RST, APBC_GPIO_RST);
    	spi_reg_write(APBC_GPIO_CLK_RST, APBC_GPIO_APBCLK_ENABLE|APBC_GPIO_FNCLK_ENABLE);
    }

	//CPUartLogPrintf("%s:APBC_GPIO_CLK_RST[0x%x]", __func__, reg_read(APBC_GPIO_CLK_RST));
	//CPUartLogPrintf("before,%s:SPI0_CLK[0x%x],SPI0_FRM[0x%x],SPI0_RXD[0x%x],SPI0_TXD[0x%x]", __func__, 
		//			spi_reg_read(SPI0_CLK), spi_reg_read(SPI0_FRM), spi_reg_read(SPI0_RXD), spi_reg_read(SPI0_TXD));


	//CONFIG GPIO16~19 as SSP0		
	spi_reg_write(SPI0_CLK, 0x1082);
	spi_reg_write(SPI0_FRM, 0x9082);
	spi_reg_write(SPI0_RXD, 0x1084);//20230724 软件修改gpio18,19的func4作为spi功能
	spi_reg_write(SPI0_TXD, 0x1084);


    //make sure SSP is disabled
     Disable_SPI_SSP0();

    //reset SSP CR's
    spi_reg_write(SSP0_TCR, SSP0_TCR_INITIAL | v_spimode);
    spi_reg_write(SSP0_FCR, SSP0_FCR_INITIAL);
    spi_reg_write(SSP0_IER, SSP0_IER_INITIAL);

    spi_reg_write(SSP0_TOR, 0xC00);

    //setup in 8bit mode
    spi_reg_bit_clr(SSP0_TCR, SSP_TCR_DSS_MASK);
    spi_reg_bit_set(SSP0_TCR, SSP_TCR_DSS8);
    //spi_reg_bit_set(SSP_TCR, SSP_TCR_DSS8);

    //setup FIFO CTRL, use SSP to do endian convert
    spi_reg_write(SSP0_FCR, SSP0_FCR_DMA_READ | SSP_FCR_RRE(0) | SSP_FCR_RAFC);
    spi_reg_bit_set(SSP0_TCR, SSP_TCR_TRIAL);

    //setup IER
    spi_reg_bit_set(SSP0_IER, SSP_IER_TIE | SSP_IER_RIE | SSP_IER_RTOIE);

    //fire SSP up
     Enable_SPI_SSP0();

	//CPUartLogPrintf("after,%s:SPI0_CLK[0x%x],SPI0_FRM[0x%x],SPI0_RXD[0x%x],SPI0_TXD[0x%x]", __func__, 
		//			spi_reg_read(SPI0_CLK), spi_reg_read(SPI0_FRM), spi_reg_read(SPI0_RXD), spi_reg_read(SPI0_TXD));
	
	//CPUartLogPrintf("%s:TCR[0x%x],FCR[0x%x],IER[0x%x],TOR[0x%x]", __func__,
		//			spi_reg_read(SSP0_TCR), spi_reg_read(SSP0_FCR), spi_reg_read(SSP0_IER), spi_reg_read(SSP0_TOR));

}


void SPI_SSP1_Initialize(SPI_MODE_T spimode, SPI_CLK_T spiclk)
{

	unsigned int v_reg, v_spiclk,especially_spiclk=0 ;
    if(ssp1_inited== 0)
    {
    	ASSERT(OSAFlagCreate(&SSP1_DMA_Done_FlgRef) == OS_SUCCESS);
    	ASSERT(OSASemaphoreCreate(&SSP1SemaRef,1,OSA_PRIORITY) == OS_SUCCESS);

#ifdef SSP1_DMA_INT_SUPPORT
    	dma_irq_callback_register(SSP1_DMA_DONE_ISR,SSP1_RX_CHANNEL);
#endif
        ssp1_inited = 1;
    }

	switch(spimode)
	{
		case SPI_MODE0:
			v_spimode = SSP_SPI_MODE0;
			break;
		case SPI_MODE1:
			v_spimode = SSP_SPI_MODE1;
			break;
		case SPI_MODE2:
			v_spimode = SSP_SPI_MODE2;
			break;
		case SPI_MODE3:
			v_spimode = SSP_SPI_MODE3;
			break;
		default:
			v_spimode = SSP_SPI_MODE0;
			break;
	}

	switch(spiclk)
	{
		case SPI_CLK_100KHZ:
		case SPI_CLK_200KHZ:
		case SPI_CLK_300KHZ:
		case SPI_CLK_400KHZ:
		case SPI_CLK_500KHZ:
		case SPI_CLK_600KHZ:
		case SPI_CLK_700KHZ:	
			especially_spiclk=spiclk+1;
			break;
		case SPI_CLK_812_5KHZ:
			v_spiclk= APBC_SSP1_FNCLKSEL_812_5KHZ;
			break;
		case SPI_CLK_1_625MHZ:
			v_spiclk= APBC_SSP1_FNCLKSEL_1_625MHZ;
			break;
		case SPI_CLK_3_25MHZ:
			v_spiclk= APBC_SSP1_FNCLKSEL_3_25MHZ;
			break;
		case SPI_CLK_6_5MHZ:
			v_spiclk= APBC_SSP1_FNCLKSEL_6_5MHZ;
			break;
		case SPI_CLK_13MHZ:
			v_spiclk= APBC_SSP1_FNCLKSEL_13MHZ;
			break;
		case SPI_CLK_26MHZ:
			v_spiclk= APBC_SSP1_FNCLKSEL_26MHZ;
			break;
		case SPI_CLK_52MHZ:
			v_spiclk= APBC_SSP1_FNCLKSEL_52MHZ;
			break;
		default:
			v_spiclk= APBC_SSP1_FNCLKSEL_6_5MHZ;
			break;
	}

	if(0 != especially_spiclk)
	{
		spi_reg_bit_set(0xD4050008, BIT_27);	
		spi_reg_write(0xD4050044, 0xE0007800|((especially_spiclk*100/5)<<15));
		spi_reg_write(APBC_SSP1_CLK_RST, 0x7B);
		CPUartLogPrintf("%s:especially_spiclk=%d ;spiclk= %d]", __func__, especially_spiclk,spiclk);
	}
	else
	{
		spi_reg_write(APBC_SSP1_CLK_RST, APBC_SSP1_APBCLK_ENABLE|APBC_SSP1_FNCLK_ENABLE|APBC_SSP1_RST);	
		spi_reg_write(APBC_SSP1_CLK_RST, APBC_SSP1_APBCLK_ENABLE|APBC_SSP1_FNCLK_ENABLE|v_spiclk);
	}
	CPUartLogPrintf("%s:APBC_SSP1_CLK_RST[0x%x]", __func__, spi_reg_read(APBC_SSP1_CLK_RST));

   	v_reg = spi_reg_read(APBC_GPIO_CLK_RST);  //0xD4015008   APBC_GPIO_CLK_RST
    if((v_reg & 0x3) != 0x3)
    {
    	CPUartLogPrintf("%s:v_reg[0x%x]", __func__, v_reg);
    	//if clk is not enable,-->reset and enable
    	spi_reg_write(APBC_GPIO_CLK_RST, APBC_GPIO_RST);
    	spi_reg_write(APBC_GPIO_CLK_RST, APBC_GPIO_APBCLK_ENABLE|APBC_GPIO_FNCLK_ENABLE);
    }

	//CPUartLogPrintf("%s:APBC_GPIO_CLK_RST[0x%x]", __func__, reg_read(APBC_GPIO_CLK_RST));
	//CPUartLogPrintf("before,%s:SPI0_CLK[0x%x],SPI0_FRM[0x%x],SPI0_RXD[0x%x],SPI0_TXD[0x%x]", __func__, 
		//			spi_reg_read(SPI0_CLK), spi_reg_read(SPI0_FRM), spi_reg_read(SPI0_RXD), spi_reg_read(SPI0_TXD));


	//CONFIG GPIO4~7 as SSP1		
	spi_reg_write(SPI1_CLK, 0x1087);
	spi_reg_write(SPI1_FRM, 0x9087);
    	
    spi_reg_write(SPI1_RXD, 0x1087);
	spi_reg_write(SPI1_TXD, 0x1087);
	
    //make sure SSP is disabled
     Disable_SPI_SSP1();

    //reset SSP CR's
    spi_reg_write(SSP1_TCR, SSP1_TCR_INITIAL | v_spimode);
    spi_reg_write(SSP1_FCR, SSP1_FCR_INITIAL);
    spi_reg_write(SSP1_IER, SSP1_IER_INITIAL);

    spi_reg_write(SSP1_TOR, 0xC00);

    //setup in 8bit mode
    spi_reg_bit_clr(SSP1_TCR, SSP_TCR_DSS_MASK);
    spi_reg_bit_set(SSP1_TCR, SSP_TCR_DSS8);
    //spi_reg_bit_set(SSP_TCR, SSP_TCR_DSS8);

    //setup FIFO CTRL, use SSP to do endian convert
    spi_reg_write(SSP1_FCR, SSP1_FCR_DMA_READ | SSP_FCR_RRE(0) | SSP_FCR_RAFC);
    spi_reg_bit_set(SSP1_TCR, SSP_TCR_TRIAL);

    //setup IER
    spi_reg_bit_set(SSP1_IER, SSP_IER_TIE | SSP_IER_RIE | SSP_IER_RTOIE);

    //fire SSP up
     Enable_SPI_SSP1();

	//CPUartLogPrintf("after,%s:SPI0_CLK[0x%x],SPI0_FRM[0x%x],SPI0_RXD[0x%x],SPI0_TXD[0x%x]", __func__, 
		//			spi_reg_read(SPI0_CLK), spi_reg_read(SPI0_FRM), spi_reg_read(SPI0_RXD), spi_reg_read(SPI0_TXD));
	
	//CPUartLogPrintf("%s:TCR[0x%x],FCR[0x%x],IER[0x%x],TOR[0x%x]", __func__,
		//			spi_reg_read(SSP1_TCR), spi_reg_read(SSP1_FCR), spi_reg_read(SSP1_IER), spi_reg_read(SSP1_TOR));

}


void SPI_SSP2_Initialize(SPI_MODE_T spimode, SPI_CLK_T spiclk)
{
	unsigned int v_reg, v_spiclk,especially_spiclk=0 ;
    if(ssp2_inited == 0)
    {
    	ASSERT(OSAFlagCreate(&SSP2_DMA_Done_FlgRef) == OS_SUCCESS);
    	ASSERT(OSASemaphoreCreate(&SSP2SemaRef,1,OSA_PRIORITY) == OS_SUCCESS);
#ifdef SSP2_DMA_INT_SUPPORT
	    dma_irq_callback_register(SSP2_DMA_DONE_ISR,SSP2_RX_CHANNEL);
#endif
        ssp2_inited = 1;
    }

	switch(spimode)
	{
		case SPI_MODE0:
			v_spimode = SSP_SPI_MODE0;
			break;
		case SPI_MODE1:
			v_spimode = SSP_SPI_MODE1;
			break;
		case SPI_MODE2:
			v_spimode = SSP_SPI_MODE2;
			break;
		case SPI_MODE3:
			v_spimode = SSP_SPI_MODE3;
			break;
		default:
			v_spimode = SSP_SPI_MODE0;
			break;
	}

	switch(spiclk)
	{
		case SPI_CLK_100KHZ:
		case SPI_CLK_200KHZ:
		case SPI_CLK_300KHZ:
		case SPI_CLK_400KHZ:
		case SPI_CLK_500KHZ:
		case SPI_CLK_600KHZ:
		case SPI_CLK_700KHZ:	
			especially_spiclk=spiclk+1;
			break;
		case SPI_CLK_812_5KHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_812_5KHZ;
			break;
		case SPI_CLK_1_625MHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_1_625MHZ;
			break;
		case SPI_CLK_3_25MHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_3_25MHZ;
			break;
		case SPI_CLK_6_5MHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_6_5MHZ;
			break;
		case SPI_CLK_13MHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_13MHZ;
			break;
		case SPI_CLK_26MHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_26MHZ;
			break;
		case SPI_CLK_52MHZ:
			v_spiclk= APBC_SSP0_FNCLKSEL_52MHZ;
			break;
		default:
			v_spiclk= APBC_SSP0_FNCLKSEL_6_5MHZ;
			break;
	}

	if(0 != especially_spiclk)
	{
		spi_reg_bit_set(0xD4050008, BIT_27);	
		spi_reg_write(0xD4050044, 0xE0007800|((especially_spiclk*100/5)<<15));
		spi_reg_write(APBC_SSP2_CLK_RST, 0x7B);
		CPUartLogPrintf("%s:especially_spiclk=%d ;spiclk= %d]", __func__, especially_spiclk,spiclk);
	}
	else
	{
		spi_reg_write(APBC_SSP2_CLK_RST, APBC_SSP2_APBCLK_ENABLE|APBC_SSP2_FNCLK_ENABLE|APBC_SSP2_RST);	
		spi_reg_write(APBC_SSP2_CLK_RST, APBC_SSP2_APBCLK_ENABLE|APBC_SSP2_FNCLK_ENABLE|v_spiclk);
	}
	CPUartLogPrintf("%s:APBC_SSP2_CLK_RST[0x%x]", __func__, spi_reg_read(APBC_SSP2_CLK_RST));

   	v_reg = spi_reg_read(APBC_GPIO_CLK_RST);  //0xD4015008   APBC_GPIO_CLK_RST
    if((v_reg & 0x3) != 0x3)
    {
    	CPUartLogPrintf("%s:v_reg[0x%x]", __func__, v_reg);
    	//if clk is not enable,-->reset and enable
    	spi_reg_write(APBC_GPIO_CLK_RST, APBC_GPIO_RST);
    	spi_reg_write(APBC_GPIO_CLK_RST, APBC_GPIO_APBCLK_ENABLE|APBC_GPIO_FNCLK_ENABLE);
    }

	//CPUartLogPrintf("%s:APBC_GPIO_CLK_RST[0x%x]", __func__, reg_read(APBC_GPIO_CLK_RST));
	//CPUartLogPrintf("before,%s:SPI0_CLK[0x%x],SPI0_FRM[0x%x],SPI0_RXD[0x%x],SPI0_TXD[0x%x]", __func__, 
		//			spi_reg_read(SPI0_CLK), spi_reg_read(SPI0_FRM), spi_reg_read(SPI0_RXD), spi_reg_read(SPI0_TXD));

#if 0
	//CONFIG GPIO33~36 as SSP0		
	spi_reg_write(SPI0_CLK, 0x1081);
	spi_reg_write(SPI0_FRM, 0x9081);
	spi_reg_write(SPI0_RXD, 0x1081);
	spi_reg_write(SPI0_TXD, 0x1081);
#endif
    if(CHIP_IS_CRANELR || CHIP_IS_CRANELS)  //1602/1609
	{
		//CONFIG GPIO12~15 as SSP2	1602平台仅有这一组ssp2，固定写死	
		spi_reg_write(0xD401E10C, 0x1081);
		spi_reg_write(0xD401E110, 0xb880);//CS GPIO13
		spi_reg_write(0xD401E114, 0xd081);//MISO
		spi_reg_write(0xD401E118, 0x1081);
	}
	else 
    {
        //CONFIG GPIO33~36 as SSP2		
        spi_reg_write(SPI2_CLK, 0x1082);
        spi_reg_write(SPI2_FRM, 0x9082);
        spi_reg_write(SPI2_RXD, 0x1082);
        spi_reg_write(SPI2_TXD, 0x1082);
    }

     Disable_SPI_SSP2();

    //reset SSP CR's
    spi_reg_write(SSP2_TCR, SSP2_TCR_INITIAL | v_spimode);
    spi_reg_write(SSP2_FCR, SSP2_FCR_INITIAL);
    spi_reg_write(SSP2_IER, SSP2_IER_INITIAL);

    spi_reg_write(SSP2_TOR, 0xC00);

    //setup in 8bit mode
    spi_reg_bit_clr(SSP2_TCR, SSP_TCR_DSS_MASK);
    spi_reg_bit_set(SSP2_TCR, SSP_TCR_DSS8);
    //spi_reg_bit_set(SSP_TCR, SSP_TCR_DSS8);

    //setup FIFO CTRL, use SSP to do endian convert
    spi_reg_write(SSP2_FCR, SSP2_FCR_DMA_READ | SSP_FCR_RRE(0) | SSP_FCR_RAFC);
    spi_reg_bit_set(SSP2_TCR, SSP_TCR_TRIAL);

    //setup IER
    spi_reg_bit_set(SSP2_IER, SSP_IER_TIE | SSP_IER_RIE | SSP_IER_RTOIE);

    //fire SSP up
     Enable_SPI_SSP2();
	//CPUartLogPrintf("after,%s:SPI0_CLK[0x%x],SPI0_FRM[0x%x],SPI0_RXD[0x%x],SPI0_TXD[0x%x]", __func__, 
		//			spi_reg_read(SPI0_CLK), spi_reg_read(SPI0_FRM), spi_reg_read(SPI0_RXD), spi_reg_read(SPI0_TXD));
	
	//CPUartLogPrintf("%s:TCR[0x%x],FCR[0x%x],IER[0x%x],TOR[0x%x]", __func__,
		//			spi_reg_read(SSP0_TCR), spi_reg_read(SSP0_FCR), spi_reg_read(SSP0_IER), spi_reg_read(SSP0_TOR));

}


QUEC_SPI_OpMode quec_spi_mode_set = QUEC_SPI_OP_DMA;

int quec_spi_init(SPI_PORT_T port, SPI_MODE_T spimode, SPI_CLK_T spiclk)
{
	SPI_MODE_T quec_spimode=SPI_MODE_MAX;
	SPI_CLK_T quec_spiclk=SPI_CLK_MAX;
	if (spimode >= SPI_MODE_MAX) {
		CPUartLogPrintf("invalid mode parameter!!\n");
		return -1;
	}
	
	quec_spimode = spimode;

	if (spiclk >= SPI_CLK_MAX) {
		CPUartLogPrintf("invalid clk parameter!!\n");
		return -1;
	}
	
	quec_spiclk = spiclk;

	if (port <= SPI_PORT_INVALID || port >= SPI_PORT_MAX) {
		CPUartLogPrintf("invalid port parameter");
		return -1;
	}

	switch (port) 
	{
		case SPI_PORT0:
			SPI_SSP0_Initialize(quec_spimode, quec_spiclk);
			break;
		case SPI_PORT1:
			SPI_SSP1_Initialize(quec_spimode, quec_spiclk);
			break;
		case SPI_PORT2:
			SPI_SSP2_Initialize(quec_spimode, quec_spiclk);
			break;
		default:
			break;
	}

	return 0;
}

int quec_spi_write(SPI_PORT_T port, unsigned char *buf, unsigned int len)
{
	int ret = 0;

	if (port <= SPI_PORT_INVALID || port >= SPI_PORT_MAX) {
		CPUartLogPrintf("invalid port parameter");
		return -1;
	}
	
	if(buf==NULL){
		CPUartLogPrintf("error with a NULL pointer,please check up the parameter please!\n");
		return -1;
	}

	switch (port) 
	{
		case SPI_PORT0:
			if(QUEC_SPI_OP_DMA==quec_spi_mode_set)
			{
				QUEC_SPI_SSP0_DMA_WriteData(buf, len);
			}
			else
			{
				QUEC_SPI_SSP0_PIO_Write(buf, len);
			}
			break;
		case SPI_PORT1:
            if(QUEC_SPI_OP_DMA==quec_spi_mode_set)
            {
                QUEC_SPI_SSP1_DMA_WriteData(buf, len);
            }
            else
            {
                QUEC_SPI_SSP1_PIO_Write(buf, len);
            }
			break;
		case SPI_PORT2:
            if(QUEC_SPI_OP_DMA==quec_spi_mode_set)
            {
                QUEC_SPI_SSP2_DMA_WriteData(buf, len);
            }
            else
            {
                QUEC_SPI_SSP2_PIO_Write(buf, len);
            }
			break;
			
		default:
			break;
	}

	return ret;

}

int quec_spi_read(SPI_PORT_T port, unsigned char *buf, unsigned int len)
{
	int ret = 0;

	if (port <= SPI_PORT_INVALID || port >= SPI_PORT_MAX) {
		CPUartLogPrintf("invalid port parameter");
		return -1;
	}

	if(buf==NULL){
		CPUartLogPrintf("error with a NULL pointer,please check up the parameter please!\n");
		return -1;
	}

	switch (port)
	{
		case SPI_PORT0:
			if(QUEC_SPI_OP_DMA==quec_spi_mode_set)
			{
				QUEC_SPI_SSP0_DMA_ReadData(buf, len);
			}
			else
			{
				QUEC_SPI_SSP0_PIO_Read(buf, len,0);
			}
			break;
		case SPI_PORT1:
            if(QUEC_SPI_OP_DMA==quec_spi_mode_set)
            {
                QUEC_SPI_SSP1_DMA_ReadData(buf, len);
            }
            else
            {
                QUEC_SPI_SSP1_PIO_Read(buf, len, 0);
            }
			break;
		case SPI_PORT2:
            if(QUEC_SPI_OP_DMA==quec_spi_mode_set)
            {
                QUEC_SPI_SSP2_DMA_ReadData(buf, len);
            }
            else
            {
                QUEC_SPI_SSP2_PIO_Read(buf, len, 0);
            }
			break;
		default:
			break;
	}

	return ret;

}

int quec_spi_write_read(SPI_PORT_T port, unsigned char *inbuf, unsigned char *outbuf, unsigned int len)
{
	int ret = 0;

	if (port <= SPI_PORT_INVALID || port >= SPI_PORT_MAX) {
		CPUartLogPrintf("invalid port parameter");
		return -1;
	}
	
	if((inbuf != NULL) && (outbuf != NULL))
	{
		switch (port) 
		{
			case SPI_PORT0:
				if(QUEC_SPI_OP_DMA==quec_spi_mode_set)
				{
					QUEC_SPI_SSP0_DataTransfer(inbuf,outbuf, len);
				}
				else
				{
					QUEC_SPI_SSP0_PIO_transfer(inbuf, outbuf, len);
				}
				break;
			case SPI_PORT1:
                if(QUEC_SPI_OP_DMA==quec_spi_mode_set)
                {
                    QUEC_SPI_SSP1_DataTransfer(inbuf,outbuf, len);
                    
                }
                else
                {
                    QUEC_SPI_SSP1_PIO_transfer(inbuf, outbuf, len);
                }
				break;
			case SPI_PORT2:
                if(QUEC_SPI_OP_DMA==quec_spi_mode_set)
                {
                    QUEC_SPI_SSP2_DataTransfer(inbuf,outbuf, len);
                    CPUartLogPrintf("QUEC_SPI_SSP2\n");
                }
                else
                {
                    QUEC_SPI_SSP2_PIO_transfer(inbuf, outbuf, len);
                }
				break;
			default:
				break;
		}
	}
	else
	{
		if(inbuf == NULL) {
			CPUartLogPrintf("ql_spi_transfer with NULL pointer to inbuf\n");
		}

		if(outbuf == NULL) {
			CPUartLogPrintf("ql_spi_transfer with NULL pointer to outbuf\n");
		}
	}

	return ret;

}

#endif

#endif

