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

#include <stdlib.h>
#include "quec_spi.h"

#define ASSERT(x)  						assert(x)
#define CPUartLogPrintf(fmt,args...)	uart_printf(fmt, ##args)

static UINT32 v_spimode = SSP_SPI_MODE0;
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
void SPI_SSP0_Initialize(SPI_MODE_T spimode, SPI_CLK_T spiclk)
{
	unsigned int v_reg, v_spiclk,especially_spiclk=0 ;

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
	spi_reg_write(SPI0_RXD, 0x1082);
	spi_reg_write(SPI0_TXD, 0x1082);


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

void SPI_SSP2_Initialize(SPI_MODE_T spimode, SPI_CLK_T spiclk)
{
	unsigned int v_reg, v_spiclk,especially_spiclk=0;

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

	//CONFIG GPIO33~36 as SSP2		
	spi_reg_write(SPI2_CLK, 0x1082);
	spi_reg_write(SPI2_FRM, 0x9082);
	spi_reg_write(SPI2_RXD, 0x1082);
	spi_reg_write(SPI2_TXD, 0x1082);

        
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

static int quec_spi_init(QUEC_SPI_PORT_E port, SPI_MODE_T spimode, SPI_CLK_T spiclk)
{
	if((spimode >= SPI_MODE_MAX)||(spiclk >= SPI_CLK_MAX)||(port <= QUEC_SPI_PORT_INVALID || port >= QUEC_SPI_PORT_MAX)){
		uart_printf("invalid mode parameter!!\n");
		return -1;
	}

	switch (port) 
	{
		case QUEC_SPI_PORT0:
			SPI_SSP0_Initialize(spimode, spiclk);
			break;
		case QUEC_SPI_PORT1:
			SPI_SSP2_Initialize(spimode, spiclk);
			break;
		default:
			break;
	}

	return 0;
}

static int quec_spi_write_read(QUEC_SPI_PORT_E port, unsigned char *inbuf, unsigned char *outbuf, unsigned int len)
{
	int ret = 0;

	if (port <= QUEC_SPI_PORT_INVALID || port >= QUEC_SPI_PORT_MAX) {
		uart_printf("invalid port parameter");
		return -1;
	}
	
	if((inbuf != NULL) && (outbuf != NULL))
	{
		switch (port) 
		{
			case QUEC_SPI_PORT0:
				QUEC_SPI_SSP0_PIO_transfer(inbuf, outbuf, len);
				break;
			case QUEC_SPI_PORT1:
				QUEC_SPI_SSP2_PIO_transfer(inbuf, outbuf, len);
				break;
			default:
				break;
		}
	}
	
	return ret;
}

void quec_spi_test(void)
{
	int ret = -1;
	unsigned char buf_in[256] = {0};
	unsigned char buf_out[128] = "=========This is the spi test !!===========\r\n";
	uart_printf("spi ql_spi_write_read test \r\n");
	quec_spi_init(QUEC_SPI_PORT1, SPI_MODE0,SPI_CLK_500KHZ);
	spi_delay_us(10000);

	while(1)
	{	
		uart_printf("ql_spi_buf_out:  %s \r\n ",buf_out);	
		ret= quec_spi_write_read(QUEC_SPI_PORT1, buf_in, buf_out, sizeof(buf_out));
		if(ret != 0)
		{
			uart_printf("ql_spi_read error, ret = %d \r\n",ret);
			break;
		}
		
		uart_printf("ql_spi_buf_in:  %s \r\n",buf_in);
		spi_delay_us(10000);
	}
}

