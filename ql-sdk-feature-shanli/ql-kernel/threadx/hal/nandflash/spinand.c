/******************************************************************************
 *
 *  (C)Copyright 2013 Marvell. All Rights Reserved.
 *
 *  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MARVELL.
 *  The copyright notice above does not evidence any actual or intended
 *  publication of such source code.
 *  This Module contains Proprietary Information of Marvell and should be
 *  treated as Confidential.
 *  The information in this file is provided for the exclusive use of the
 *  licensees of Marvell.
 *  Such users have the right to use, modify, and incorporate this code into
 *  products for purposes authorized by the license agreement provided they
 *  include this notice and the associated copyright notice with any such
 *  product.
 *  The information in this file is provided "AS IS" without warranty.
 *
 ******************************************************************************/

#include "spinand.h"
#include "flash_wk.h"
#include "Errors.h"
#include "xllp_dmac.h"
#include "UART.h"
#include "osa.h"
#include "cgpio.h"
#include "qspi_dma.h"
#include "ssp_reg.h"
#include "utils.h"  /* Required for ASSERT macro definition */
#include "stdlib.h"
#include "quec_rtos.h"

#define YAFFS_SUPPORT
#pragma arm section rwdata="SPINAND", zidata="SPINAND"
__attribute__ ((aligned(32))) XLLP_DMAC_DESCRIPTOR_T pRX_data, pTX_cmd;
__attribute__ ((aligned(32)))unsigned int	 tx_command[2113] = {0};
#pragma arm section rwdata, zidata

/* Non-cache */
#pragma arm section rwdata="DMARdBuf", zidata="DMARdBuf"
__align(32) unsigned char NANND_DMA_Read_Buffer[4096] = {0};
#pragma arm section rwdata, zidata

FlashProperties_T NandFlashProp[2];  
static unsigned char FlashProtect = 0;
static int GpioPinOfCS  = 0;
static int SSPport      = 0;
static OSSemaRef spinand_op_sem = NULL;
static unsigned int SSPBase[3] = {SSP0_BASE, SSP1_BASE, SSP2_BASE};
static unsigned int GpioOfCS[3] = {0,0,13};
static quec_mutex_t nand_mutex=NULL;
static int quec_spi_port = 0;
static SPI_PIN quec_spi_pin = SPI_PIN_33_36;
static SSP_Clock quec_spi_clk = SSP_CLOCK_26M;   

#define SPI_NAND_DMA_INTERRUPT //DMA polling mode if it's not defined

#ifdef SPI_NAND_DMA_INTERRUPT //add for interrupt replace poll
static OSFlagRef ssp2_nand_flash_rx_dma_done_FlgRef=NULL;
static OSFlagRef ssp2_nand_flash_tx_dma_done_FlgRef=NULL;

//debug only
static UINT32 g_spi_nand_tx_dma_spend_max=0;
static UINT32 g_spi_nand_rx_dma_spend_max=0;

#endif 

#define BU_REG_READ8(x) (*(volatile unsigned char *)(x) & 0xff)
#define BU_REG_WRITE8(x,y) ((*(volatile unsigned char *)(x)) = y & 0xff )

#define spi_nand_log_trace(fmt, args...) do { CPUartLogPrintf("[SPI]"fmt, ##args); } while(0)
#define spi_nand_log_err(fmt, args...) do { CPUartLogPrintf("[SPI]ERR-"fmt, ##args); } while(0)
#define spi_nand_log_uart(fmt, args...) do { RTI_LOG("[SPI]"fmt, ##args); } while(0)
struct spinand_device *g_spinand;

static void SPINAND_CacheLoad(unsigned int Address);
static unsigned int SPINAND_CacheRead_4Bytes(unsigned int Offset, unsigned int Buffer, unsigned int Size);
static unsigned int SPINAND_ProgramLoad_4Bytes(unsigned int Address, unsigned int Buffer, unsigned int Size);
static void SPINAND_WriteEnable(void);
static void SPINAND_WriteDisable(void);
static void SPINAND_ProgramExecute(unsigned int Address);
uint32_t dma_read_status(unsigned int channel);
static void SPINAND_BlockErase(unsigned int Address);
static unsigned int SPINAND_ProgramLoad_4Bytes_PIO(unsigned int Address, unsigned int Buffer, unsigned int Size);
static unsigned int SPINAND_CacheRead_4Bytes_PIO(unsigned int Offset, unsigned int Buffer, unsigned int Size);
static int spinand_check_ecc(unsigned char val);
int spinand_get_ecc_status(void);

int quec_nand_spi_init(int spi_port,SPI_PIN spi_pin,SSP_Clock spi_clk)
{
    quec_spi_port = spi_port;
    quec_spi_pin = spi_pin;
    quec_spi_clk = spi_clk;
    return 0;
}
    
static void raw_delay(unsigned int x)
{
	volatile long i = 0;
	i = x;

	while (i > 0)
	{
		i--;
	}
}

P_FlashProperties_T get_flashprop(int sspport)
{
	return &NandFlashProp[0];
}

unsigned int get_ssp_base(void)
{
	return SSPBase[SSPport];
}

static inline void set_ssp_port(int port)
{
	SSPport = port;
}

static inline void set_ssp_cs_gpio(int sspport, unsigned int gpio)
{
	GpioOfCS[sspport] = gpio;
}

static inline void assert_ssp_cs(void)
{
	GpioSetLevel(GpioOfCS[SSPport], 0);
	raw_delay(300);
}

static inline void deassert_ssp_cs(void)
{
    raw_delay(300);
	GpioSetLevel(GpioOfCS[SSPport], 1);
}


static inline void disable_ssp(void)
{
    spi_reg_bit_clr(SSPORT_TCR, SSP_TCR_SSE);

    spi_reg_write(SSPORT_TCR, SSP_TCR_INITIAL);
    spi_reg_write(SSPORT_FCR, SSP_FCR_INITIAL);
    spi_reg_write(SSPORT_IER, SSP_IER_INITIAL);
}
static inline void fireup_ssp(void)
{
    spi_reg_bit_set(SSPORT_TCR, SSP_TCR_SSE);
}


static void set_ssp_dss(int DataSize)
{
    switch(DataSize)
    {
        case 16:
        {
            spi_reg_bit_clr(SSPORT_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSPORT_TCR, SSP_TCR_DSS16);
        	break;
        }

        case 24:
        {
            spi_reg_bit_clr(SSPORT_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSPORT_TCR, SSP_TCR_DSS24);
        	break;
        }

        case 32:
        {
            spi_reg_bit_clr(SSPORT_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSPORT_TCR, SSP_TCR_DSS32);
        	break;
        }
	case 8:
	{
		spi_reg_bit_clr(SSPORT_TCR, SSP_TCR_DSS_MASK);
	         spi_reg_bit_set(SSPORT_TCR, SSP_TCR_DSS8);
		break;
	}
	
        default:
        {
		break;
        }
		
    }
}

static unsigned int raw_endian_convert (unsigned int in)
{
	unsigned int out;
	out = in << 24;
	out |= (in & 0xFF00) << 8;
	out |= (in & 0xFF0000) >> 8;
	out |= (in & 0xFF000000) >> 24;
	return out;
}


static void init_ssp_port(int port, SSP_Clock clock ,SPI_PIN PIN)
{
	unsigned int apbc_ssp_base = 0;
	if (port == 0)
	{
		//config spinand function by gpio33 ,gpio34 ,gpio35 ,gpio36
		apbc_ssp_base = APBC_SSP0_CLK_RST;
        if(PIN==SPI_PIN_33_36)
        {
    		/*  config clk, cs, rx, tx, hold, wp according to hardware,use cs as GPIO function. */
    		/* ssp0_sclk--gpio33 */
    		*(volatile unsigned int*)0xD401E160 = 0x1881; //0x1081;
    		//ssp0_frm --gpio34, cs use gpio function 
    		*(volatile unsigned int*)0xD401E164 = 0x1080;
    		set_ssp_cs_gpio(port, 34);
    		//ssp2_rxd --gpio35
    		*(volatile unsigned int*)0xD401E168 = 0x1881; //0x1081;
    		//ssp2_txd --gpio36
    		*(volatile unsigned int*)0xD401E16C = 0x1881; //0x1081;
    		
    		//ssp2_frm output high
    		GpioSetDirection(34, 1);
    		GpioSetLevel(34, 1);
        }
        
        if(PIN==SPI_PIN_16_19)
        {
            /* ssp0_sclk--gpio16 */
    		*(volatile unsigned int*)0xD401E11C = 0x1882; //0x1081;
    		//ssp0_frm --gpio17, cs use gpio function 
    		*(volatile unsigned int*)0xD401E120 = 0x1080;
    		set_ssp_cs_gpio(port, 17);
    		//ssp0_rxd --gpio18
    		*(volatile unsigned int*)0xD401E124 = 0x1884; //0x1081;
    		//ssp0_txd --gpio19
    		*(volatile unsigned int*)0xD401E128 = 0x1884; //0x1081;
    		
    		//ssp0_frm output high
    		GpioSetDirection(17, 1);
    		GpioSetLevel(17, 1);
        }

	}
	else if (port == 1)
		apbc_ssp_base = APBC_SSP1_CLK_RST;
	else
	{
        //config spinand function by gpio33 ,gpio34 ,gpio35 ,gpio36
    	apbc_ssp_base = APBC_SSP2_CLK_RST;
        if(PIN==SPI_PIN_33_36)
        {
    		/*  config clk, cs, rx, tx, hold, wp according to hardware,use cs as GPIO function. */
    		*(volatile unsigned int*)0xD401E160 = 0x1882;	//ssp2_sclk--gpio33
    		*(volatile unsigned int*)0xD401E164 = 0x1880;	//ssp2_frm --gpio34, cs use gpio function
    		set_ssp_cs_gpio(port, 34);	//set cs pin
    		*(volatile unsigned int*)0xD401E168 = 0x1882;	//ssp2_rxd --gpio35
    		*(volatile unsigned int*)0xD401E16C = 0x1882;	//ssp2_txd --gpio36

    		//ssp2_frm output high
    		GpioSetDirection(34, 1);
    		GpioSetLevel(34, 1);
        }
	}

	spi_reg_write(apbc_ssp_base, BIT_0 | BIT_1 | BIT_2);

	switch(clock)
	{
		case SSP_CLOCK_13M:
		{
			spi_reg_write(apbc_ssp_base, BIT_0 | BIT_1 | (1 << 4));
			break;
		}

		case SSP_CLOCK_26M:
		{
			spi_reg_write(apbc_ssp_base, BIT_0 | BIT_1 | (2 << 4));
			break;
		}

		case SSP_CLOCK_52M:
		{
			spi_reg_write(apbc_ssp_base, BIT_0 | BIT_1 | (3 << 4)); 
			break;
		} 

		default:
		{
			spi_reg_write(apbc_ssp_base, BIT_0 | BIT_1 | (1 << 4)); 
			break;
		}
	}

	
	set_ssp_port(port);
	CPUartLogPrintf("apbc_ssp_base value:REG0x%04x = 0x%02x", apbc_ssp_base, spi_reg_read(apbc_ssp_base));
	return;
}

static void SPI_DMACacheReadCmdSetUp(void)
{
        //spi_reg_write(SSPORT_TOR, SSP_TOR_TIMEOUT);

    	//setup in 32 bit mode
    	spi_reg_bit_clr(SSPORT_TCR, SSP_TCR_DSS_MASK);
    	spi_reg_bit_set(SSPORT_TCR, SSP_TCR_DSS32);

        //setup for DMA: TX and RX DMA request + DMA handles Trailing bytes + FIFO RX Thresh+1
    	//SSP controller does endian convert, enable RX FIFO Auto Full Control
    	//spi_reg_write(SSPORT_FCR, SSP_FCR_NAND_DMA_READ | SSP_FCR_RRE(2) | SSP_FCR_RAFC);
    	//spi_reg_bit_set(SSPORT_TCR, SSP_TCR_TRIAL);

        //setup IER
    	//spi_reg_bit_set(SSPORT_IER, SSP_IER_TIE | SSP_IER_RIE | SSP_IER_RTOIE);
}


static void SPI_DMACacheReadSetUp(void)
{
    spi_reg_write(SSPORT_TOR, SSP_TOR_TIMEOUT);

	//setup in 32 bit mode
	spi_reg_bit_clr(SSPORT_TCR, SSP_TCR_DSS_MASK);
	spi_reg_bit_set(SSPORT_TCR, SSP_TCR_DSS32);

    //setup for DMA: TX and RX DMA request + DMA handles Trailing bytes + FIFO RX Thresh+1
	//SSP controller does endian convert, enable RX FIFO Auto Full Control
	spi_reg_write(SSPORT_FCR, SSP_FCR_NAND_DMA_READ | SSP_FCR_RRE(2) | SSP_FCR_RAFC);
	spi_reg_bit_set(SSPORT_TCR, SSP_TCR_TRIAL);

        //setup IER
    	//spi_reg_bit_set(SSPORT_IER, SSP_IER_TIE | SSP_IER_RIE | SSP_IER_RTOIE);
}

static void SPI_DMAProgramLoadCmdSetUp(void)
{
	//spi_reg_write(SSPORT_TOR, SSP_TOR_TIMEOUT);

    	//setup in 8 bit mode
	spi_reg_bit_clr(SSPORT_TCR, SSP_TCR_DSS_MASK);
	spi_reg_bit_set(SSPORT_TCR, SSP_TCR_DSS8);

	//setup for DMA: TX and RX DMA request + DMA handles Trailing bytes
	//spi_reg_bit_set(SSPORT_FCR, SSP_FCR_RSRE | SSP_FCR_TSRE | SSP_FCR_RFT(4) | SSP_FCR_RAFC | SSP_FCR_TFT(3));
	//spi_reg_bit_set(SSPORT_TCR, SSP_TCR_TRIAL);

	//setup IER
	//spi_reg_bit_set(SSPORT_IER, SSP_IER_TIE | SSP_IER_RIE | SSP_IER_RTOIE);
}

static void SPI_DMAProgramLoadDataSetUp(void)
{
    spi_reg_write(SSPORT_TOR, SSP_TOR_TIMEOUT);

	//setup in 32 bit mode
	spi_reg_bit_clr(SSPORT_TCR, SSP_TCR_DSS_MASK);
	spi_reg_bit_set(SSPORT_TCR, SSP_TCR_DSS32);

	//setup for DMA: TX and RX DMA request + DMA handles Trailing bytes
	//reg_bit_set(SSP_FCR, SSP_FCR_RSRE | SSP_FCR_TSRE | SSP_FCR_RFT(4) | SSP_FCR_RAFC | SSP_FCR_TFT(3));
	spi_reg_bit_set(SSPORT_FCR, SSP_FCR_RSRE | SSP_FCR_TSRE | SSP_FCR_RFT(4) | SSP_FCR_TFT(3));
	spi_reg_bit_set(SSPORT_TCR, SSP_TCR_TRIAL);

    	 //setup IER
    	//spi_reg_bit_set(SSPORT_IER, SSP_IER_TIE | SSP_IER_RIE | SSP_IER_RTOIE);

}

static void SPI_WaitSSPComplete(void)
{
	volatile int timeout = 0xFFFFF;

	while ((*SSPORT_STS & (SSP_STS_TFL | SSP_STS_TF_NF | SSP_STS_BSY)) != SSP_STS_TF_NF)
	{
		raw_delay(DMA_DEFAULT_TIMEOUT);

		if((timeout--) <= 0)
		{
			CPUartLogPrintf("[NZC]SPI_WaitSSPComplete timeout");
			break;
		}
	}
}

/***********************************************************
*   SPI_Write_Read
*   	PIO mode to write and then read out the data
*   Returns:
*	    None
*************************************************************/
static void SPI_Write_Read(unsigned char *cmd, unsigned char *data, unsigned char len)
{
	unsigned int out_index = 0,in_index = 0;
	unsigned int tmp_rxfifo=0;
    unsigned char TxFifoLevel=0, RxFifoLevel=0;
    int i;
    
	if(((*SSPORT_SR) & SSP_STS_TF_NF) == 0)
	TxFifoLevel = 32; //1802s TxFIFO Trigger Level max vaule is 32
    else
	TxFifoLevel = ((*SSPORT_SR)>>7)&0x1f;

	for(i=TxFifoLevel; i<32 && out_index<len; i++)
	{
		BU_REG_WRITE8(SSPORT_DR, cmd[out_index++]);
       //uart_printf("%s:buf_out[%d]=0x%x", __func__, out_index-1,buf_out[out_index-1]);
	}
    do{
    
        tmp_rxfifo=*SSPORT_SR;
    
        RxFifoLevel=((tmp_rxfifo>>15)&0x1f);
     
        if(((tmp_rxfifo & SSP_STS_TF_NE) == 0) && RxFifoLevel == 0x1f)
        {
         RxFifoLevel=0;
        }
        else
        {
         RxFifoLevel++;
        }
           for(i = 0; i<RxFifoLevel && in_index<len; i++)
           {
               data[in_index++] = BU_REG_READ8(SSPORT_DR); 
               if(out_index<len)
               BU_REG_WRITE8(SSPORT_DR, cmd[out_index++]);
               //uart_printf("%s:buf_in[%d]=0x%x", __func__, in_index-1,buf_in[in_index-1]);
           }  
     }while(in_index <len);
    
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_GetFeatures                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function Reads the corresponding feature value of SPI device.*/
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      The feature type to be read out                                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      status value                                                     */
/*                                                                       */
/*************************************************************************/
static unsigned char SPINAND_GetFeatures(SPINAND_Feature_E feature_type)
{
    UINT8 cmd[3], data[3];

    //fill out the command (2 bytes) plus dummy bytes for the readback
    cmd[0] = SPINAND_GET_FEATURES;
    cmd[1] = feature_type;
    cmd[2] = 0;

    //make sure SSP is disabled
    disable_ssp();

    //fire it up
    fireup_ssp();

    assert_ssp_cs();

    SPI_Write_Read(cmd, data, sizeof(cmd));

    deassert_ssp_cs();

    disable_ssp();

    return data[2];
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_SetFeatures                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function set the corresponding feature value of SPI device.  */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      The feature type to be read out                                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      status value                                                     */
/*                                                                       */
/*************************************************************************/
static unsigned char SPINAND_SetFeatures(SPINAND_Feature_E feature_type, unsigned char feature)
{
    UINT8 cmd[3], data[3];;

    //fill out the command (2 bytes) plus data byte
    cmd[0] = SPINAND_SET_FEATURES;
    cmd[1] = feature_type;
    cmd[2] = feature;

    disable_ssp();

    fireup_ssp();

    assert_ssp_cs();

    SPI_Write_Read(cmd, data, sizeof(cmd));

    deassert_ssp_cs();

    disable_ssp();

    return 0;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_Reset                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      Issues command to reset flash.                                   */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      The flash address of the block to be erased                      */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      status value                                                     */
/*                                                                       */
/*************************************************************************/
static unsigned int SPINAND_Reset(FlashBootType_T fbt)
{
	unsigned char cmd[1] = {0}, data[1] = {0};
	volatile unsigned char status = 0;
    /* The RESET (FFH) command stops all operations.
    For example, in case of a program or erase or read operation,
    the reset command can make the device enter the wait state.
    During a cache program or cache read, a reset can also stops
    the previous operation and the pending operation. The OIP
    status can be read from 300ns after the reset command is sent.
    */
	cmd[0] = SPINAND_RESET;

	disable_ssp();

	fireup_ssp();

	assert_ssp_cs();

	SPI_Write_Read(cmd, data, sizeof(cmd));

	deassert_ssp_cs();

	disable_ssp();

    do //等待重启成功
    {	//Read the Status register on the device
        status = SPINAND_GetFeatures(SPINAND_STATUS);        
    //stay in loop if OIP bit is still high AND no timeout error has occured
    } while( (status & GIGA_SPINAND_STATUS_OIP));
    
	return NoError;
}



/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_CheckReady                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function check SPI nand ready status.                        */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
static unsigned int  SPINAND_CheckReady(unsigned char *s)
{
    volatile int timeout = 0;
    unsigned int retval = NoError;
    volatile unsigned char status = 0;
#if 0
    timeout = 0xFFF;
    do
    {	//Read the Status register on the device
        status = SPINAND_GetFeatures(SPINAND_STATUS);        

        if((timeout--) <= 0)
        {
            retval = TimeOutError;
        }
		raw_delay(1000);
    //stay in loop if OIP bit is still high AND no timeout error has occured
    } while( (status & GIGA_SPINAND_STATUS_OIP)&& (retval != TimeOutError);
    if ((status & GIGA_SPINAND_STATUS_P_FAIL)&& (value == SPINAND_WRITE))
    {
        retval = ProgramError;
    }

    if ((status & GIGA_SPINAND_STATUS_E_FAIL)&&(value == SPINAND_ERASE))
    {
        retval = EraseError;
    }
	if(retval != NoError)
	{
        SPINAND_Reset(BOOT_FLASH);
		printf("[SPI_NAND]%s fail, status=0x%x\r\n",__func__,status);
		printf("[SPI_NAND]%s fail, retval=0x%x\r\n",__func__,retval);
	}

    return retval;
#endif
    timeout = 0xFFFFF;
    do
    {	//Read the Status register on the device
        status = SPINAND_GetFeatures(SPINAND_STATUS);        
        if(!(status & GIGA_SPINAND_STATUS_OIP))
            goto end;
		raw_delay(1000);
    
    } while( timeout--);

end:
    if(s)
        *s = status;

    return status & GIGA_SPINAND_STATUS_OIP ? TimeOutError:0;

}




/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_Read                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function read SPI nand with DMA.                             */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
unsigned int SPINAND_Read(unsigned int FlashOffset, unsigned int Buffer, 
					unsigned int Size, FlashBootType_T fbt)
{
	unsigned int retval = NoError;
	unsigned int read_size = 0;
	OSA_STATUS	status;
	fbt = fbt;
    unsigned char s = 0;
	//RTI_LOG("SPINAND_Read: [0x%x][0x%x]!!", FlashOffset, Size);

	//calculate the initial read size (for the first page)
	read_size = SPINAND_PAGE_SIZE - (FlashOffset & (SPINAND_PAGE_SIZE - 1));	//whole page - pre_bytes

	//for each loop iteration, one page of flash will be read into internal memory
	while (Size > 0)
	{	//update read_size if there are post_bytes (i.e. leftover for the last page)
		read_size = read_size > Size ? Size : read_size;
		/** Step 1: Cache Load: Load the correct page into cache **/
		SPINAND_CacheLoad(FlashOffset);
        //printf("[NAND FLASH]READ1-----\r\n");
		/** Step 2: Get Features: wait for OIP to be cleared **/
        retval = SPINAND_CheckReady(&s);
        if(retval > 0)
        {
            RTI_LOG("Check Ready retval1 0x%x", retval);
            break;
        }

		/** Step 3: Cache Read: Read the page in cache to memory (DMA) **/
		retval = SPINAND_CacheRead_4Bytes(FlashOffset, Buffer, read_size);
		if(retval != NoError)
		{
			RTI_LOG("SSPINAND_CacheRead_4Bytes Error[0x%x]!!", retval);
			break;
		}
		//printf("[NAND FLASH]READ2-----\r\n");
        retval = SPINAND_CheckReady(&s);
        if(retval > 0)
        {
            RTI_LOG("Check Ready retval1 0x%x", retval);
            break;
        }

		/** Step 4: Update counters: make sure to adjust up to a page boundary each iteration **/
		FlashOffset += read_size;
		Buffer += read_size;
		Size -= read_size;
		read_size = SPINAND_PAGE_SIZE;
	}

         if(retval == EraseError)	
            retval = 0;
	return retval;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_CacheLoad                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      Issues command to read a page of NAND into the cache.            */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      The flash address of the page to be loaded.                      */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
static void SPINAND_CacheLoad(unsigned int Address)
{
	unsigned char cmd[4], data[4];

	cmd[0] = SPINAND_CACHE_LOAD ;
	cmd[1] = ((Address>>11)&0xff0000) >> 16; /*>>11相当于除以2048得到pagenum*/
	cmd[2] = ((Address>>11)&0xff00) >> 8;
	cmd[3] = ((Address>>11)&0xff);

	disable_ssp();

    fireup_ssp();

	assert_ssp_cs();

	SPI_Write_Read(cmd, data, sizeof(cmd));

	deassert_ssp_cs();

	disable_ssp();

	return;
}




/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_CacheRead_4Bytes                                         */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      Reads the loaded page from Cache to internal memory using DMA.   */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      The feature type to be read out                                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      status value                                                     */
/*                                                                       */
/*************************************************************************/
struct spinand_dma_reg
{
	volatile UINT32 DMA_TX_DCSR;
	volatile UINT32 DMA_TX_DCMD;
	volatile UINT32 DMA_RX_DCSR;
	volatile UINT32 DMA_RX_DCMD;
	volatile UINT32 SSP_STS;
};

struct spinand_dma_reg g_spinand_reg_debug;


static unsigned int SPINAND_CacheRead_4Bytes(unsigned int Offset, unsigned int Buffer, unsigned int Size)
{
	unsigned int command, i = 0, Retval = NoError, total_size = 0;
	SPINAND_ADDRESS_FIELD_T addr;
	DMA_CMDx_T RX_Cmd, TX_Cmd;
	unsigned int read_buff = 0;
	unsigned int *temp_buff = NULL;
	volatile int timeout = 0xFFFFF;	

	/* Fill out the "command" sequence: CMD + Column Address (CA) + dummy byte	*/
	addr.value = Offset;
	command = SPINAND_CACHE_READ << 24;
	command |= 0;	/* (upper bits will be 0's for the 'wrap')	*/
	command |= 0;				/* 0xA5 is a dummy byte that easily seen on a scope	*/
	tx_command[0] = command;

    read_buff = (unsigned int)NANND_DMA_Read_Buffer;

	/* Fill out commands	*/
	RX_Cmd.value = 0;
	RX_Cmd.bits.IncSrcAddr = 0;
	RX_Cmd.bits.IncTrgAddr = 1;
	RX_Cmd.bits.FlowSrc = 1;
	RX_Cmd.bits.FlowTrg = 0;
	RX_Cmd.bits.Width = 3;
	RX_Cmd.bits.MaxBurstSize = 2;
	RX_Cmd.bits.Length = (Size);


	TX_Cmd.value = 0;
	TX_Cmd.bits.IncSrcAddr = 0;
	TX_Cmd.bits.IncTrgAddr = 0;
	TX_Cmd.bits.FlowSrc = 0;
	TX_Cmd.bits.FlowTrg = 1;
	TX_Cmd.bits.Width = 3;
	TX_Cmd.bits.MaxBurstSize = 2;
	TX_Cmd.bits.Length = (Size);

	if (SSPport == 0)
	{
		dma_map_device_to_channel(DMA_REQ_SSP0_RX, DMA_DEV_SSP2_RX_CH);
		dma_map_device_to_channel(DMA_REQ_SSP0_TX, DMA_DEV_SSP2_TX_CH);
	}
	else if (SSPport == 2)
	{
		dma_map_device_to_channel(DMA_REQ_SSP2_RX, DMA_DEV_SSP2_RX_CH);
		dma_map_device_to_channel(DMA_REQ_SSP2_TX, DMA_DEV_SSP2_TX_CH);
	}
	
	set_user_aligment(DMA_DEV_SSP2_TX_CH);
	set_user_aligment(DMA_DEV_SSP2_RX_CH);
	dma_set_mode(DMA_MODE_NONFETCH, DMA_DEV_SSP2_TX_CH);
	dma_set_mode(DMA_MODE_NONFETCH, DMA_DEV_SSP2_RX_CH);

	dma_set_reg_nf((unsigned int)SSPORT_DR, (unsigned int)read_buff, &RX_Cmd, DMA_DEV_SSP2_RX_CH);
	dma_set_reg_nf((unsigned int)&tx_command[1], (unsigned int)SSPORT_DR, &TX_Cmd, DMA_DEV_SSP2_TX_CH);

	disable_ssp();
	SPI_DMACacheReadCmdSetUp();
    fireup_ssp();
	assert_ssp_cs();
	
	spi_reg_write(SSPORT_DR, tx_command[0]);
	SPI_WaitSSPComplete();
	spi_reg_read(SSPORT_DR);

	disable_ssp();
	SPI_DMACacheReadSetUp();
	fireup_ssp();
#if 0
	g_spinand_reg_debug.DMA_TX_DCMD = QSPI_XLLP_DmacReg()->DMA_DESC[DMA_DEV_SSP2_TX_CH].DCMD;
	g_spinand_reg_debug.DMA_TX_DCSR = QSPI_XLLP_DmacReg()->DCSR[DMA_DEV_SSP2_TX_CH];
	g_spinand_reg_debug.DMA_RX_DCMD = QSPI_XLLP_DmacReg()->DMA_DESC[DMA_DEV_SSP2_RX_CH].DCMD;
	g_spinand_reg_debug.DMA_RX_DCSR = QSPI_XLLP_DmacReg()->DCSR[DMA_DEV_SSP2_RX_CH];
	g_spinand_reg_debug.SSP_STS = *SSPORT_STS;
#endif
#ifdef SPI_NAND_DMA_INTERRUPT
	dma_xfer_start(DMA_DEV_SSP2_TX_CH);
	dma_xfer_start_with_irq_enable(DMA_DEV_SSP2_RX_CH);
	UINT32 rx_tick_start = get_current_TStimer_tick();
	UINT32 rx_tick_spend = 0;
    spi_nand_log_trace("read-dma kick off, TS tick:0x%x",rx_tick_start);
#else
    dma_xfer_start(DMA_DEV_SSP2_TX_CH);
	dma_xfer_start(DMA_DEV_SSP2_RX_CH);
#endif


#ifdef SPI_NAND_DMA_INTERRUPT
	OSA_STATUS os_status = OS_SUCCESS;
	UINT32	flag_value = 0;

	os_status = OSAFlagWait(ssp2_nand_flash_rx_dma_done_FlgRef, 0x01, OSA_FLAG_OR_CLEAR, &flag_value, 200);
	if(os_status == OS_SUCCESS)
	{
		rx_tick_spend = get_current_TStimer_tick()-rx_tick_start;
		if(g_spi_nand_rx_dma_spend_max < rx_tick_spend)
			g_spi_nand_rx_dma_spend_max = rx_tick_spend;
		spi_nand_log_trace("------%s:rx DMA Transfer Done,rx DMA_STS:0x%x, SSP_STS=0x%x, TS tick:0x%x, spend:0x%x", __func__,dma_read_status(DMA_DEV_SSP2_RX_CH),*SSPORT_STS,get_current_TStimer_tick(), rx_tick_spend);
	}
	else
	{
		spi_nand_log_err("!!!!%s:TIMEOUT,os_status=0x%x,rx DMA_STS:0x%x,SSP_STS=0x%x,TS tick:0x%x",__func__,os_status,dma_read_status(DMA_DEV_SSP2_RX_CH),*SSPORT_STS,get_current_TStimer_tick());
		spi_nand_log_uart("!!!!%s:TIMEOUT,os_status=0x%x,rx DMA_STS:0x%x,SSP_STS=0x%x,TS tick:0x%x",__func__,os_status,dma_read_status(DMA_DEV_SSP2_RX_CH),*SSPORT_STS,get_current_TStimer_tick());
		//dma_reg_printf(DMA_DEV_SSP2_TX_CH);
		//dma_reg_printf(DMA_DEV_SSP2_RX_CH);
#if 0
		RTI_LOG("TX:0x%x,0x%x,RX:0x%x,0x%x,SSP_STS:0x%x", g_spinand_reg_debug.DMA_TX_DCMD, g_spinand_reg_debug.DMA_TX_DCSR, 
								g_spinand_reg_debug.DMA_RX_DCMD, g_spinand_reg_debug.DMA_RX_DCSR, g_spinand_reg_debug.SSP_STS);
#endif
		Retval = SSPTxChannelTimeOutError;
	}
#else
	timeout = 0xFFFFF;
	/* wait until the RX channel gets the stop unsigned interrupt    */
	while( (dma_read_status(DMA_DEV_SSP2_RX_CH) & XLLP_DMAC_DCSR_STOP_INTR) != XLLP_DMAC_DCSR_STOP_INTR)
	{
		raw_delay(DMA_DEFAULT_TIMEOUT);

		if((timeout--) <= 0)			
		{
			Retval = SSPRxChannelTimeOutError;

			RTI_LOG("!!!SPINAND_CacheRead_4Bytes	RXerror[%x]!!, RX status:0x%x", Retval, dma_read_status(DMA_DEV_SSP2_RX_CH));
			break;
		}
	}
	
	timeout = 0xFFFFF;
	/* wait until the TX channel gets the stop unsigned interrupt    */
	while( (dma_read_status(DMA_DEV_SSP2_TX_CH) & XLLP_DMAC_DCSR_STOP_INTR) != XLLP_DMAC_DCSR_STOP_INTR)
	{
		raw_delay(DMA_DEFAULT_TIMEOUT);

		if((timeout--) <= 0)			
		{
			Retval = SSPTxChannelTimeOutError;

			RTI_LOG("!!!SPINAND_CacheRead_4Bytes	TXerror[%x]!!, TX status:0x%x", Retval, dma_read_status(DMA_DEV_SSP2_TX_CH));
			break;
		}
	}
#endif

	SPI_WaitSSPComplete();

	if(Retval != 0)
	{
	         dma_xfer_stop( DMA_DEV_SSP2_RX_CH );
	         dma_xfer_stop( DMA_DEV_SSP2_TX_CH );
	}

	deassert_ssp_cs();

	disable_ssp();

         spi_reg_write(SSPORT_TOR, 0);

	if(Retval == 0)
		memcpy( (unsigned char *)Buffer, (unsigned char *)NANND_DMA_Read_Buffer, Size );
	return Retval;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_Write                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      SPI NAND WRITE: using DMA.                                       */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      The feature type to be read out                                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      status value                                                     */
/*                                                                       */
/*************************************************************************/
unsigned int SPINAND_Write(unsigned int FlashOffset, unsigned int Buffer, 
						unsigned int Size, FlashBootType_T fbt)
{
	unsigned int 	retval = NoError;
	unsigned int 	write_size;
	OSA_STATUS	status;
	fbt = fbt;
	unsigned char s= 0;
	//spi_nand_log_trace("SPINAND_Write: [0x%x][0x%x]!!", FlashOffset, Size);
	
	/* for each loop iteration, one page of flash will be written */
	while (Size > 0)
	{
	         /* Update write_size if there are post_bytes (i.e. leftover for the last page) */
		write_size = Size > SPINAND_PAGE_SIZE ? SPINAND_PAGE_SIZE : Size;

                   /*  Step 0: Write Enable: set the write enable bit 		*/

		SPINAND_WriteEnable();

		/** Step 1: Program Load: Load the data into cache (DMA) **/
		retval = SPINAND_ProgramLoad_4Bytes(FlashOffset, Buffer, write_size);
		if(retval != NoError)
		{
		    RTI_LOG("SPINAND_ProgramLoad_4Bytes, retval 0x%x", retval);
			break;
	    }
        //printf("[NAND FLASH]Write1-----\r\n");
        retval = SPINAND_CheckReady(&s);
        if(!retval && (s & GIGA_SPINAND_STATUS_P_FAIL))
        {
            RTI_LOG("Check Ready retval1 0x%x", retval);
            break;
        }


		/*  Step 2: Write Enable: set the write enable bit 				*/
		SPINAND_WriteEnable();

		/* Step 3: Program Execute: Write the page in cache to flash 		*/
		SPINAND_ProgramExecute(FlashOffset);
        //printf("[NAND FLASH]Write2-----\r\n");
		/* Step 4: Get Features: wait for OIP to be cleared 				*/
        retval = SPINAND_CheckReady(&s);
        if(!retval && (s & GIGA_SPINAND_STATUS_P_FAIL))
        {
            RTI_LOG("Check Ready retval1 0x%x", retval);
            break;
        }

	
		/* Step 5: Update counters: make sure to adjust up to a page boundary each iteration */
		FlashOffset += write_size;
		Buffer += write_size;
		Size -= write_size;
		write_size = SPINAND_PAGE_SIZE;
	}

	SPINAND_WriteDisable();
	
	return retval;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_ProgramLoad_4Bytes                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      Writes a page of data to Cache from internal memory using DMA.   */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      The feature type to be read out                                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      status value                                                     */
/*                                                                       */
/*************************************************************************/
static unsigned int SPINAND_ProgramLoad_4Bytes(unsigned int Address, unsigned int Buffer, unsigned int Size)
{
	unsigned int Retval = NoError, i;
	DMA_CMDx_T TX_Cmd;
	unsigned char cmd[3], data[3];
	volatile int timeout = 0xFFFFF;
	unsigned int *write_buff;
	SPINAND_ADDRESS_FIELD_T addr;
	unsigned int convert_size = Size;

	write_buff = (unsigned int *)(&NANND_DMA_Read_Buffer[0]);
	memcpy(write_buff, (unsigned int *)Buffer, Size);	
	unsigned int *convert_buff = write_buff;

	convert_size >>= 2;	
	for(i = 0; i < convert_size + 1; i++)
		convert_buff[i] = raw_endian_convert(convert_buff[i]);
	/* fill out the "command" sequence: CMD + Column Address (CA)*/
	addr.value = Address;
	cmd[0] = SPINAND_PROGRAM_LOAD;
	cmd[1] = 0;//(addr.fields.CA && 0xFF00) >> 8;
	cmd[2] = 0;//addr.fields.CA && 0xFF;

	TX_Cmd.value = 0;
	TX_Cmd.bits.IncSrcAddr = 1;
	TX_Cmd.bits.IncTrgAddr = 0;
	TX_Cmd.bits.FlowSrc = 0;
	TX_Cmd.bits.FlowTrg = 1;
	TX_Cmd.bits.Width = 3;
	TX_Cmd.bits.MaxBurstSize = 2;
    TX_Cmd.bits.Length = (Size);
	if (SSPport == 0)
		dma_map_device_to_channel(DMA_REQ_SSP0_TX, DMA_DEV_SSP2_TX_CH);
	else if (SSPport == 2)
		dma_map_device_to_channel(DMA_REQ_SSP2_TX, DMA_DEV_SSP2_TX_CH);
	
	set_user_aligment(DMA_DEV_SSP2_TX_CH);
	
	dma_set_mode(DMA_MODE_NONFETCH, DMA_DEV_SSP2_TX_CH);
	dma_set_reg_nf((unsigned int)write_buff, (unsigned int)SSPORT_DR, &TX_Cmd, DMA_DEV_SSP2_TX_CH);

	disable_ssp();

	SPI_DMAProgramLoadCmdSetUp();

         fireup_ssp();

	assert_ssp_cs();
	SPI_Write_Read(cmd, data, sizeof(cmd));

	disable_ssp();
	SPI_DMAProgramLoadDataSetUp();
          fireup_ssp();

#ifdef SPI_NAND_DMA_INTERRUPT
	//dma_xfer_start(DMA_DEV_SSP2_RX_CH);
	dma_xfer_start_with_irq_enable(DMA_DEV_SSP2_TX_CH);
	UINT32 tx_tick_start = get_current_TStimer_tick();
	UINT32 tx_tick_spend = 0;
	spi_nand_log_trace("write-dma kick off, TS tick:0x%x", tx_tick_start);
#else
	dma_xfer_start(DMA_DEV_SSP2_TX_CH);
#endif


#ifdef SPI_NAND_DMA_INTERRUPT
	OSA_STATUS os_status = OS_SUCCESS;
	UINT32	flag_value = 0;

	os_status = OSAFlagWait(ssp2_nand_flash_tx_dma_done_FlgRef, 0x01, OSA_FLAG_OR_CLEAR, &flag_value, 200);
	if(os_status == OS_SUCCESS)
	{
		tx_tick_spend = get_current_TStimer_tick()-tx_tick_start;
		if(g_spi_nand_tx_dma_spend_max < tx_tick_spend)
			g_spi_nand_tx_dma_spend_max = tx_tick_spend;
		spi_nand_log_trace("------%s:Tx DMA Transfer Done,tx DMA_STS:0x%x,SSP_STS=0x%x,TS tick:0x%x, spend:0x%x", __func__,dma_read_status(DMA_DEV_SSP2_TX_CH),*SSPORT_STS,get_current_TStimer_tick(),tx_tick_spend);
	}
	else
	{
		spi_nand_log_err("!!!!%s:TIMEOUT,os_status=0x%x,tx DMA_STS:0x%x,SSP_STS=0x%x,TS tick:0x%x",__func__,os_status,dma_read_status(DMA_DEV_SSP2_TX_CH),*SSPORT_STS,get_current_TStimer_tick());
		spi_nand_log_uart("!!!!%s:TIMEOUT,os_status=0x%x,tx DMA_STS:0x%x,SSP_STS=0x%x,TS tick:0x%x",__func__,os_status,dma_read_status(DMA_DEV_SSP2_TX_CH),*SSPORT_STS,get_current_TStimer_tick());
		Retval = SSPTxChannelTimeOutError;
	}
#else
	timeout = 0xFFFFF;
	/* wait until the TX channel gets the stop unsigned interrupt and the TX fifo is drained	*/
	while( (dma_read_status(DMA_DEV_SSP2_TX_CH) & XLLP_DMAC_DCSR_STOP_INTR) != XLLP_DMAC_DCSR_STOP_INTR)
	{
		raw_delay(DMA_DEFAULT_TIMEOUT);

		if((timeout--) <= 0)			
		{
			Retval = SSPRxChannelTimeOutError;
			RTI_LOG("!!!SPINAND_ProgramLoad_4Bytes  error[%x]!!, TX status:0x%x", Retval, dma_read_status(DMA_DEV_SSP2_TX_CH));
			break;
		}
	}

	timeout = 0xFFFFF;
	/* wait until the RX channel gets the stop unsigned interrupt and the TX fifo is drained	*/
	while( (dma_read_status(DMA_DEV_SSP2_RX_CH) & XLLP_DMAC_DCSR_STOP_INTR) != XLLP_DMAC_DCSR_STOP_INTR)
	{
		raw_delay(DMA_DEFAULT_TIMEOUT);

		if((timeout--) <= 0)			
		{
			Retval = SSPTxChannelTimeOutError;
			RTI_LOG("!!!SPINAND_ProgramLoad_4Bytes  error[%x]!!, RX status:0x%x", Retval, dma_read_status(DMA_DEV_SSP2_RX_CH));
			break;
		}
	}
#endif

	SPI_WaitSSPComplete();

	if(Retval != 0)
	{
		//dma_xfer_stop( DMA_DEV_SSP2_RX_CH );
		dma_xfer_stop( DMA_DEV_SSP2_TX_CH );
	}
	

	deassert_ssp_cs();

	disable_ssp();
	return Retval;
}


static unsigned int SPINAND_ProgramLoad_4Bytes_PIO(unsigned int Address, unsigned int Buffer, unsigned int Size)
{
	unsigned int Retval = NoError, i;
	unsigned char cmd[3], data[3];
	unsigned char *pbuf = (unsigned char *)Buffer;

	/* fill out the "command" sequence: CMD + Column Address (CA)*/
	cmd[0] = SPINAND_PROGRAM_LOAD;
	cmd[1] = 0;
	cmd[2] = 0;
	
	disable_ssp();

         fireup_ssp();
	assert_ssp_cs();
	SPI_Write_Read(cmd, data, sizeof(cmd));
	
	for(i=0; i<Size; i++)
	{
		spi_reg_write(SSPORT_DR, pbuf[i]);
		SPI_WaitSSPComplete();
		spi_reg_read(SSPORT_DR);
	}

	deassert_ssp_cs();
	disable_ssp();

	return Retval;
}

static unsigned int SPINAND_CacheRead_4Bytes_PIO(unsigned int Offset, unsigned int Buffer, unsigned int Size)
{
	unsigned int i = 0, Retval = NoError;
	unsigned char cmd[4], data[4];
	unsigned char *pbuf = (unsigned char *)Buffer;
	cmd[0] = SPINAND_CACHE_READ;
	cmd[1] = 0;
	cmd[2] = 0;
	cmd[3] = 0xA5;

	disable_ssp();
          fireup_ssp();
	 assert_ssp_cs();

	 SPI_Write_Read(cmd, data, sizeof(cmd));
	 SPI_WaitSSPComplete();

	 for(i=0; i<Size; i++)
	 {
		spi_reg_write(SSPORT_DR, 0);
		SPI_WaitSSPComplete();
		pbuf[i]= spi_reg_read(SSPORT_DR);
	 }
	 
	deassert_ssp_cs();
	disable_ssp();

	return Retval;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_WriteEnable                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      Sets the WEL bit in the SPI NAND status register, allowing the   */
/*      device to be programmed or erased.                               */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      The feature type to be read out                                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      status value                                                     */
/*                                                                       */
/*************************************************************************/
static void SPINAND_WriteEnable(void)
{
	unsigned char cmd[1], data[1];

	cmd[0] = SPINAND_WRITE_ENABLE;

	disable_ssp();

    fireup_ssp();

	assert_ssp_cs();

	SPI_Write_Read(cmd, data, sizeof(cmd));

	deassert_ssp_cs();

	disable_ssp();
}

void SPINAND_WriteDisable(void)
{
	unsigned char cmd[1], data[1];

	cmd[0] = SPINAND_WRITE_DISABLE;

	disable_ssp();

    fireup_ssp();

	assert_ssp_cs();

	SPI_Write_Read(cmd, data, sizeof(cmd));

	deassert_ssp_cs();

	disable_ssp();

}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_ProgramExecute                                           */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      Issues command to program a page of NAND from the cache.         */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      The flash address of the page to be loaded                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      status value                                                     */
/*                                                                       */
/*************************************************************************/
static void SPINAND_ProgramExecute(unsigned int Address)
{
	unsigned char cmd[4], data[4];

	cmd[0] = SPINAND_PROGRAM_EXECUTE;
	cmd[1] = ((Address>>11)&0xff0000) >> 16;
	cmd[2] = ((Address>>11)&0xff00) >> 8;
	cmd[3] = ((Address>>11)&0xff);

	disable_ssp();

    fireup_ssp();

	assert_ssp_cs();

	SPI_Write_Read(cmd, data, sizeof(cmd));

	deassert_ssp_cs();

	disable_ssp();

	return;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_Erase                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      SPI NAND ERASE: Erases 1 whole block at a time.                  */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      The flash address of the page to be loaded                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      status value                                                     */
/*                                                                       */
/*************************************************************************/
unsigned int SPINAND_Erase(unsigned int FlashOffset, unsigned int Size, 
					FlashBootType_T fbt)
{
    quec_rtos_mutex_lock(nand_mutex, OSA_SUSPEND);
	unsigned int retval = NoError;
	fbt = fbt;
	OSA_STATUS	status;
    unsigned char s;
    int count = 0;
	//RTI_LOG("SPINAND_Erase: [0x%x][0x%x]!!", FlashOffset, Size);
	
	//adjust the size/offset fields to start on a block boundary
	Size += FlashOffset & (SPINAND_BLOCK_SIZE - 1);
	FlashOffset &= ~(SPINAND_BLOCK_SIZE - 1);
	
	//for each loop iteration, one block of flash will be erased
	while (Size > 0)
	{	/** Step 1: Write Enable: set the write enable bit **/
		SPINAND_WriteEnable();
		/** Step 2: Block Erase: erase 1 block **/
		SPINAND_BlockErase(FlashOffset);
        //printf("[NAND FLASH]%XERASE-----\r\n",FlashOffset);
		/** Step 3: Get Features: wait for OIP to be cleared **/
		retval = SPINAND_CheckReady(&s);
		if(!retval && (s & GIGA_SPINAND_STATUS_E_FAIL))
			break;
        count++;
        if(count>1)
            ASSERT(0);
		/** Step 4: Update counters **/
		FlashOffset += SPINAND_BLOCK_SIZE;
		Size = (Size > SPINAND_BLOCK_SIZE) ? (Size - SPINAND_BLOCK_SIZE) : 0;
	}

    SPINAND_WriteDisable();
	quec_rtos_mutex_unlock(nand_mutex);
	return retval;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINAND_BlockErase                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      Issues command to erase 1 block of flash.                        */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      The flash address of the block to be erased                      */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      status value                                                     */
/*                                                                       */
/*************************************************************************/
static void SPINAND_BlockErase(unsigned int Address)
{
	unsigned char cmd[4], data[4];

	cmd[0] = SPINAND_BLOCK_ERASE;
	cmd[1] = ((Address>>11)&0xff0000) >> 16;
	cmd[2] = ((Address>>11)&0xff00) >> 8;
	cmd[3] = ((Address>>11)&0xff);

	disable_ssp();

    fireup_ssp();

	assert_ssp_cs();

	SPI_Write_Read(cmd, data, sizeof(cmd));

	deassert_ssp_cs();

	disable_ssp();

	return;
}



unsigned int SPINAND_Read_Page_SpareData(unsigned int FlashOffset, 
									unsigned int Buffer,  unsigned int size)
{
    quec_rtos_mutex_lock(nand_mutex, OSA_SUSPEND);
	unsigned int retval = NoError;
	unsigned int read_size = SPINAND_PAGE_WITH_SPARE_BYTES_SIZE;
	size = size;
    unsigned char s = 0;

	//spi_nand_log_trace("SPINAND_Read_Page_SpareData: [0x%x]!!", FlashOffset);
		
	/** Step 1: Cache Load: Load the correct page into cache **/
	SPINAND_CacheLoad(FlashOffset);
    //printf("[NAND FLASH]%XReadSpareData1-----\r\n",FlashOffset);
	/** Step 2: Get Features: wait for OIP to be cleared **/
	retval = SPINAND_CheckReady(&s);
    if(retval > 0)
	{
		RTI_LOG("Check Ready retval1 0x%x", retval);
		goto func_end;
	}

        if(1 == spinand_get_ecc_status())
        {
            retval = spinand_check_ecc(s);
            if(retval != 0)
            {
                goto func_end;
            }
        }
	
	/** Step 3: Cache Read: Read the page in cache to memory (DMA) **/
	retval = SPINAND_CacheRead_4Bytes(FlashOffset, Buffer, read_size);
	if(retval != NoError)
	{
		RTI_LOG("SPINAND_ProgramLoad_4Bytes, retval 0x%x", retval);
		goto func_end;
	}
	//printf("[NAND FLASH]%XReadSpareData2-----\r\n",FlashOffset);
	retval = SPINAND_CheckReady(&s);
    if(retval > 0)
	{
		RTI_LOG("Check Ready retval1 0x%x", retval);
		goto func_end;
	}


func_end:
    quec_rtos_mutex_unlock(nand_mutex);
	return retval;
    
}

unsigned int SPINAND_Write_Page_SpareData(unsigned int FlashOffset, 
								unsigned int Buffer,  unsigned int size)
{
    quec_rtos_mutex_lock(nand_mutex,OSA_SUSPEND);
	unsigned int retval = NoError;
	unsigned int write_size = SPINAND_PAGE_WITH_SPARE_BYTES_SIZE ;
	size = size;
	OSA_STATUS	status;
    unsigned char s;
	
	//spi_nand_log_trace("SPINAND_Write_Page_SpareData: [0x%x]!!", FlashOffset);
	
           /*  Step 0: Write Enable: set the write enable bit 		*/
	SPINAND_WriteEnable();

	/* Step 1: Program Load: Load the data into cache (DMA) 	*/
	retval = SPINAND_ProgramLoad_4Bytes(FlashOffset, Buffer, write_size);
	//retval = SPINAND_ProgramLoad_4Bytes_PIO(FlashOffset, Buffer, write_size);
	if(retval != NoError)
	{
		RTI_LOG("SPINAND_ProgramLoad_4Bytes, retval 0x%x", retval);
		goto func_end;
	}
    //printf("[NAND FLASH]%XSpareData1-----\r\n",FlashOffset);
	retval = SPINAND_CheckReady(&s);
	if(!retval && (s & GIGA_SPINAND_STATUS_P_FAIL))
	{
		RTI_LOG("Check Ready retval1 0x%x", retval);
		goto func_end;
	}

	/*  Step 2: Write Enable: set the write enable bit 				*/
	SPINAND_WriteEnable();

	/* Step 3: Program Execute: Write the page in cache to flash 		*/
	SPINAND_ProgramExecute(FlashOffset);
    //printf("[NAND FLASH]%XSpareData2-----\r\n",FlashOffset);
	/* Step 4: Get Features: wait for OIP to be cleared 				*/
	retval = SPINAND_CheckReady(&s);
	if(!retval && (s & GIGA_SPINAND_STATUS_P_FAIL))
	{
		RTI_LOG("Check Ready retval1 0x%x", retval);
		goto func_end;
	}

func_end:
    SPINAND_WriteDisable();
    quec_rtos_mutex_unlock(nand_mutex);
	return retval;
    
}

#ifdef SPI_NAND_DMA_INTERRUPT
int ssp2_nand_flash_dma_tx_complete_handler(UINT32 val) 
{
    dma_xfer_stop( DMA_DEV_SSP2_TX_CH );
	dma_xfer_stop( DMA_DEV_SSP2_RX_CH );
	OSAFlagSet(ssp2_nand_flash_tx_dma_done_FlgRef, 0x01, OSA_FLAG_OR);
	spi_nand_log_trace("dma_hisr_tx_done,0x%x",get_current_TStimer_tick()&0xFFFFF);
	return 0;
}

int ssp2_nand_flash_dma_rx_complete_handler(UINT32 val)
{
    dma_xfer_stop( DMA_DEV_SSP2_TX_CH );
	dma_xfer_stop( DMA_DEV_SSP2_RX_CH );
	OSAFlagSet(ssp2_nand_flash_rx_dma_done_FlgRef, 0x01, OSA_FLAG_OR);
	spi_nand_log_trace("dma_hisr_rx_done,0x%x",get_current_TStimer_tick()&0xFFFFF);
	return 0;
}
#endif

static int spinand_check_ecc(unsigned char val)
{
    return g_spinand->manufacturer->ops->check_ecc(val);
}


int spinand_get_ecc_status(void)
{
	struct nand_device *nand = spinand_to_nand(g_spinand);
	return nand->eccreq.hw_ecc;
}


static int spinand_match_and_init(struct  spinand_device * spinand,
										const struct spinand_info *table,
										unsigned int table_size,
										enum spinand_readid_method rdid_method)
{
	unsigned char *id = spinand->id.data;
	struct nand_device *nand = spinand_to_nand(spinand);
	unsigned int i  =0;

	for(i=0; i<table_size; i++)
	{
		const struct spinand_info *info = &table[i];

		if(rdid_method != info->devid.method)
			continue;

		if(memcmp(id+1, info->devid.id, info->devid.len))
			continue;

		nand->memorg = table[i].memorg;
		nand->eccreq = table[i].eccreq;
		spinand->id.len = table[i].devid.len + 1;
		spinand->select_target = table[i].select_target;
		
		RTI_LOG("%s SPI NAND was matched.", table[i].model);

		return 0;			
	}

	return -1;	
}


static const struct spinand_manufacturer * spinand_manufacturers[] = 
{
	&winbond_spinand_manufacturer,
	&gigadevice_spinand_manufacturer
};




static int spinand_manufacturer_match(struct spinand_device *spinand, 
									enum spinand_readid_method rdid_method)
{
	unsigned char *id = spinand->id.data;
	unsigned int i;
	int ret;

	for(i=0; i<ARRAY_SIZE(spinand_manufacturers); i++)
	{
		const struct spinand_manufacturer *manufacturer =
			spinand_manufacturers[i];

		if(id[0] != manufacturer->id)
			continue;

		ret = spinand_match_and_init(spinand, manufacturer->chips,
							manufacturer->nchips, rdid_method);
		if(ret < 0)
			continue;

		spinand->manufacturer = manufacturer;
		return 0;
	}

	return -1;
}

static int spinand_read_id_op(struct spinand_device * spinand, 
							enum spinand_readid_method rdid_method, unsigned char *buf)
{
	unsigned char cmd[5]={0}, data[5]={0};

 	if (SPINAND_READID_METHOD_OPCODE_DUMMY == rdid_method )
	{		
		cmd[0] = SPINAND_READ_ID;
		cmd[1] = 0; 	 /*DUMMY Code.	It for winbond.*/		 
		cmd[2] = 0;
		cmd[3] = 0;
		cmd[4] = 0;
		
		disable_ssp();
		
		fireup_ssp();
		
		assert_ssp_cs();
		
		SPI_Write_Read(cmd, data, sizeof(cmd));
		
		deassert_ssp_cs();
		
		disable_ssp();

		memcpy( buf, &data[2], SPINAND_MAX_ID_LEN-2);
		
		RTI_LOG("Manufacture ID: 0x%x, Device ID: 0x%x", data[2], data[3]);

	}
	else if(SPINAND_READID_METHOD_OPCODE_ADDR == rdid_method)
	{
		cmd[0] = SPINAND_READ_ID;
		cmd[1] = 0; 	/* Addr code, It is for giga.	*/		 
		cmd[2] = 0;
		cmd[3] = 0;
		
		disable_ssp();
		
		fireup_ssp();
		
		assert_ssp_cs();
		
		SPI_Write_Read(cmd, data, sizeof(cmd));
		
		deassert_ssp_cs();
		
		disable_ssp();

		memcpy( buf, &data[2], SPINAND_MAX_ID_LEN-2);
		
		RTI_LOG("Manufacture ID: 0x%x, Device ID: 0x%x", data[2], data[3]);

	}
	else if(SPINAND_READID_METHOD_OPCODE == rdid_method)
	{
		cmd[0] = SPINAND_READ_ID;
		cmd[1] = 0; 			 
		cmd[2] = 0;		/*There is IDs[2].	*/
		cmd[3] = 0;
		
		disable_ssp();
		
		fireup_ssp();
		
		assert_ssp_cs();
		
		SPI_Write_Read(cmd, data, sizeof(cmd));
		
		deassert_ssp_cs();
		
		disable_ssp();

		memcpy( buf, &data[1], SPINAND_MAX_ID_LEN-1);
		
		RTI_LOG("Manufacture ID: 0x%x, Device ID: 0x%x", data[1], data[2]);
	}

	return 0;
}

static int spinnand_id_detect(struct spinand_device * spinand)
{
	unsigned char *id =spinand->id.data;
	int ret = 0;

	ret = spinand_read_id_op(spinand, SPINAND_READID_METHOD_OPCODE, id);
	if(ret)
		return ret;
	ret = spinand_manufacturer_match(spinand, SPINAND_READID_METHOD_OPCODE);
	if(!ret)
		return 0;

	ret = spinand_read_id_op(spinand, SPINAND_READID_METHOD_OPCODE_ADDR, id);
	if(ret)
		return ret;
	ret = spinand_manufacturer_match(spinand, SPINAND_READID_METHOD_OPCODE_ADDR);
	if(!ret)
		return 0;

	ret = spinand_read_id_op(spinand, SPINAND_READID_METHOD_OPCODE_DUMMY, id);
	if(ret)
		return ret;
	ret = spinand_manufacturer_match(spinand, SPINAND_READID_METHOD_OPCODE_DUMMY);

	return ret;
}


static int spinand_reset_op(struct spinand_device * spinand)
{
	unsigned char cmd[1] = {0}, data[1] = {0};
	
    /* The RESET (FFH) command stops all operations.
    For example, in case of a program or erase or read operation,
    the reset command can make the device enter the wait state.
    During a cache program or cache read, a reset can also stops
    the previous operation and the pending operation. The OIP
    status can be read from 300ns after the reset command is sent.
    */
	cmd[0] = SPINAND_RESET;

	disable_ssp();

	fireup_ssp();

	assert_ssp_cs();

	SPI_Write_Read(cmd, data, sizeof(cmd));

	deassert_ssp_cs();

	disable_ssp();

	return 0;

}

/*
* Just for winbond W25M02GV */
int spinand_die_select(struct spinand_device * spinand, unsigned int target)
{
	unsigned char cmd[2] = {0}, data[2] = {0};
	
	cmd[0] = 0x21;
	cmd[1] = target;
	
	disable_ssp();

	fireup_ssp();

	assert_ssp_cs();

	SPI_Write_Read(cmd, data, sizeof(cmd));

	deassert_ssp_cs();

	disable_ssp();

	return 0;

}


static int spinand_unlock_block(struct spinand_device * spinand)
{
	unsigned char protection;

	protection = SPINAND_GetFeatures(SPINAND_PROTECTION);

	if ((protection & (GIGA_SPINAND_PROTECTION_BP3 |
	                    GIGA_SPINAND_PROTECTION_BP2 |
						GIGA_SPINAND_PROTECTION_BP1 |
						GIGA_SPINAND_PROTECTION_BP0)) == 0)
	{
		RTI_LOG("SPINAND is already unprotected, protection 0x%x", protection);
		return 0;
	}
	else
	{
		RTI_LOG("SPINAND is not unprotected, protection 0x%x", protection);
	}

	// clear BP0/BP1/BP2
	protection &= ~(GIGA_SPINAND_PROTECTION_BP3 |
	                GIGA_SPINAND_PROTECTION_BP2 |
					GIGA_SPINAND_PROTECTION_BP1 |
					GIGA_SPINAND_PROTECTION_BP0);

	SPINAND_SetFeatures(SPINAND_PROTECTION, protection);

	return 0;
}

int spinand_enable_ecc(struct spinand_device * spinand)
{
	unsigned char sn_feature;
	sn_feature = SPINAND_GetFeatures(SPINAND_FEATURE);
	CPUartLogPrintf("SN_feature: 0x%x", sn_feature);

	if ((sn_feature & GIGA_SPINAND_FEATURE_ECC_EN) == 0)
		SPINAND_SetFeatures(SPINAND_FEATURE, (sn_feature | GIGA_SPINAND_FEATURE_ECC_EN));

	sn_feature = SPINAND_GetFeatures(SPINAND_FEATURE);
	CPUartLogPrintf("SN_feature: 0x%x", sn_feature);
	return 0;
}

int spinand_disable_ecc(struct spinand_device * spinand)
{
	unsigned char sn_feature;
	sn_feature = SPINAND_GetFeatures(SPINAND_FEATURE);
	CPUartLogPrintf("SN_feature: 0x%x", sn_feature);

	if (sn_feature & GIGA_SPINAND_FEATURE_ECC_EN) 
		SPINAND_SetFeatures(SPINAND_FEATURE, (sn_feature &( ~GIGA_SPINAND_FEATURE_ECC_EN)));

	sn_feature = SPINAND_GetFeatures(SPINAND_FEATURE);
	CPUartLogPrintf("SN_feature: 0x%x", sn_feature);

	return 0;
}

static int spinand_detect(struct spinand_device *spinand)
{
	struct nand_device *nand = spinand_to_nand(spinand);
	int ret = 0;
	
	ret = spinand_reset_op(spinand);
	if(ret)
		return ret;

	ret = spinnand_id_detect(spinand);
	if(ret)
	{
		RTI_LOG("unkown raw ID %*phN.", SPINAND_MAX_ID_LEN, spinand->id.data);
		return ret;
	}

	if(nand->memorg.ntargets > 1 && !spinand->select_target)
	{
		RTI_LOG("SPI NAND with more one die must with select function.");
		return -1;
	}

	RTI_LOG("%s SPI NAND was found.", spinand->manufacturer->name);

	RTI_LOG("%u MiB, Block size: %u KiB, page size: %u, OOB size: %u",
		nanddev_size(nand) >> 20, nanddev_eraseblock_size(nand) >> 10,
		nanddev_page_size(nand), nanddev_per_page_oobsize(nand));
	
	return  nanddev_ntargets(nand);
}



static int spinand_manufacturer_init(struct spinand_device *spinand)
{
	if(spinand->manufacturer->ops->init)
		return spinand->manufacturer->ops->init(spinand);
	return 0;
}

static int spinand_manufacturer_cleanup(struct spinand_device *spinand)
{
	if(spinand->manufacturer->ops->cleanup)
		return spinand->manufacturer->ops->cleanup(spinand);
	return 0;
}


int spinand_select_target(struct spinand_device *spinand, unsigned int target)
{
	struct nand_device *nand = spinand_to_nand(spinand);
	int ret;

	if(target > nand->memorg.ntargets)
		return -1;

	if(spinand->cur_target == target)
		return 0;

	if(nand->memorg.ntargets == 1) 
	{
		spinand->cur_target = target;
		return 0;
	}

	ret = spinand->select_target(spinand, target);
	if(ret)
		return ret;

	spinand->cur_target = target;
	
	return 0;
}


static int spinand_init(	struct spinand_device *spinand)
{
	int ret = 0;
	int ntargets = -1;
	int i = 0;

#ifdef SPI_NAND_DMA_INTERRUPT
	ASSERT(OSAFlagCreate(&ssp2_nand_flash_tx_dma_done_FlgRef) == OS_SUCCESS);
	ASSERT(OSAFlagCreate(&ssp2_nand_flash_rx_dma_done_FlgRef) == OS_SUCCESS);
	dma_irq_callback_register((dma_callback_t)ssp2_nand_flash_dma_tx_complete_handler,DMA_DEV_SSP2_TX_CH);
	dma_irq_callback_register((dma_callback_t)ssp2_nand_flash_dma_rx_complete_handler,DMA_DEV_SSP2_RX_CH);
	spi_nand_log_trace("%s, dma intterupt enabled\r\n", __func__);
#endif

		
	ntargets = spinand_detect(spinand);
	if(ntargets < 0)
	{
		RTI_LOG("Failed to Detecting of NAND DEVICE !!");	
		goto err_manuf_cleanup;
	}
	
	ret = spinand_manufacturer_init(spinand);
	if(ret)
	{
		RTI_LOG("Failed to initialize of SPI NAND !!");	
		goto err_manuf_cleanup;
	}

	/* After Power up,all blocks are locked, so unlock them.*/
	for (i = 0; i < ntargets; i++)
	{
		ret = spinand_select_target(spinand, i);
		if(ret)
		{
			RTI_LOG("Failed to select SPI NAND !!");	
			goto err_manuf_cleanup;
		}

		ret = spinand_unlock_block(spinand);
		if(ret)
		{
			RTI_LOG("Failed to select SPI NAND !!");	
			goto err_manuf_cleanup;
		}

#ifdef YAFFS_SUPPORT
                  ret = spinand_enable_ecc(spinand);
                  if(ret)
                  {
                      RTI_LOG("Failed to disable ecc!!");    
                      goto err_manuf_cleanup;
                  }
#endif
	}

	return 0;

err_manuf_cleanup:
	if(spinand->manufacturer)
	spinand_manufacturer_cleanup(spinand);
	return -1;

}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      InitializeSPINAND                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function Initializes the SSP port on the platform and issues.*/
/*      a Read ID command to see if a device is connected                */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/

unsigned int  SPINANDDevice_Init(unsigned char flashnu, FlashBootType_T flashbootType, unsigned char *P_DefaultPartitonNum)
{
	P_FlashProperties_T pFlashP = get_flashprop(0);
	struct spinand_device *spinand; 
	struct nand_device *nand; 
	int ret = 0;
		
	spinand = malloc(sizeof(struct spinand_device)); 
	if(!spinand )		
		return 0xFF;

	memset(spinand, 0, sizeof(struct spinand_device));
    
    g_spinand = spinand;
	init_ssp_port(quec_spi_port, SSP_CLOCK_26M,quec_spi_pin);

	ret = spinand_init(spinand);
	if(ret)
		return 0xFF;
	
	nand = spinand_to_nand(spinand);

	/* Update membership of flashporperity.	*/
	pFlashP->ReadFromFlash			    = &SPINAND_Read;
	pFlashP->WriteToFlash			    = &SPINAND_Write;
	pFlashP->EraseFlash			    = &SPINAND_Erase;
	pFlashP->ResetFlash			    = &SPINAND_Reset;
#ifdef YAFFS_SUPPORT
    pFlashP->WriteOTP               = &SPINAND_Write_Page_SpareData;
    pFlashP->ReadOTP                = &SPINAND_Read_Page_SpareData;
#endif
	pFlashP->FlashSettings.UseBBM		= 1;
	pFlashP->FlashSettings.UseSpareArea	= 0;
	pFlashP->FlashSettings.SASize		= nanddev_per_page_oobsize(nand);
	pFlashP->FlashSettings.UseHwEcc		= 1;
	pFlashP->FlashType                  			= SPI_NAND_FLASH;
	pFlashP->FinalizeFlash			    = NULL;
	pFlashP->BlockSize			        	= nanddev_eraseblock_size(nand);
	pFlashP->PageSize			        	= nanddev_page_size(nand);
	pFlashP->NumBlocks		    	= nanddev_eraseblocks_per_target(nand);
    quec_rtos_mutex_create(&nand_mutex);
	*P_DefaultPartitonNum = 0;
//	RTI_LOG("SPINANDDevice_Init %d",pFlashP->NumBlocks);
	return NoError;
}

#define SPINAND_TEST
#ifdef SPINAND_TEST
void spinand_test_task(void *arg)
{

	int test_size    = 0;
	unsigned int count = 0;
	unsigned char *wbuf = NULL;
    unsigned char *wbuf1 = NULL;
    unsigned char *wbuf2 = NULL;
	unsigned char *rbuf = NULL;
    unsigned char *rbuf1 = NULL;
    unsigned char *rbuf2 = NULL;
	int i = 0;
	int j = 0;
	int k = 0;
	unsigned int address = 0;	
    unsigned int address1 = 0;
    unsigned int address2 = 0;
	int page_num = 0;
	unsigned int round = 0;
	unsigned int err_cnt = 0;
	unsigned int ret=0;
    unsigned char default_Num =0;
    SPINANDDevice_Init(0, BOOT_FLASH, &default_Num);
	P_FlashProperties_T pFlashP = get_flashprop(0);
	
	test_size = pFlashP->PageSize + pFlashP->FlashSettings.SASize; //page = 0x800; block= 0x20000
	wbuf = (unsigned char *)malloc(test_size);
    wbuf1 = (unsigned char *)malloc(test_size);
    wbuf2 = (unsigned char *)malloc(test_size);
	rbuf = (unsigned char *)malloc(test_size);
    rbuf2 = (unsigned char *)malloc(test_size);
	rbuf1 = (unsigned char *)malloc(test_size);
	memset(wbuf,0,test_size);
	for (i = 0; i < test_size; i++)
		wbuf[i] = 'A';
	for (i = 0; i < test_size; i++)
		wbuf1[i] = 'B';
    for (i = 0; i < test_size; i++)
		wbuf2[i] = 'C';

	RTI_LOG("start testing, test size=%d", test_size);


		address = 4093*64*2048;
        address1 = 4094*64*2048;
        address2 = 4095*64*2048;

		memset(rbuf,0,test_size);
        memset(rbuf1,0,test_size);
           
        ret = SPINAND_Erase(address, pFlashP->BlockSize, BOOT_FLASH);
        if(ret != NoError)
        {   
            RTI_LOG("!!!SPINAND_Erase FAIL, ret=%d",ret);
        }
        ret = SPINAND_Erase(address1, pFlashP->BlockSize, BOOT_FLASH);
        if(ret != NoError)
        {   
            RTI_LOG("!!!SPINAND_Erase FAIL, ret=%d",ret);
        }
        ret = SPINAND_Erase(address2, pFlashP->BlockSize, BOOT_FLASH);
        if(ret != NoError)
        {   
            RTI_LOG("!!!SPINAND_Erase FAIL, ret=%d",ret);
        }

        ret=SPINAND_Read_Page_SpareData(address,(unsigned int)rbuf,test_size);
        if(ret != NoError)
        {
			RTI_LOG("!!!SPINAND_Write FAIL, ret=%d",ret);
        }
        RTI_LOG("\r\n============================erase rbuf=================================\r\n");
        for(i=0;i<test_size;i++)
        {
            RTI_LOG("0x%X",rbuf[i]);
        }

        RTI_LOG("\r\n=================================================================\r\n");
        
        ret=SPINAND_Read_Page_SpareData(address1,(unsigned int)rbuf1,test_size);
        if(ret != NoError)
        {
			RTI_LOG("!!!SPINAND_Write FAIL, ret=%d",ret);
        }
        RTI_LOG("\r\n===========================erase rbuf1=================================\r\n");
        for(i=0;i<test_size;i++)
        {
            RTI_LOG("0x%X",rbuf1[i]);
        }
        RTI_LOG("\r\n=================================================================\r\n");   
        ret=SPINAND_Read_Page_SpareData(address2,(unsigned int)rbuf2,test_size);
        if(ret != NoError)
        {
			RTI_LOG("!!!SPINAND_Write FAIL, ret=%d",ret);
        }
        RTI_LOG("\r\n===========================erase rbuf2=================================\r\n");
        for(i=0;i<test_size;i++)
        {
            RTI_LOG("0x%X",rbuf2[i]);
        }
        RTI_LOG("\r\n=================================================================\r\n"); 


       ret = SPINAND_Write_Page_SpareData(address,(unsigned int)wbuf,test_size);
        if(ret != NoError)
        {
			RTI_LOG("!!!SPINAND_Write FAIL, ret=%d",ret);
        }
        RTI_LOG("\r\n=========================wbuf=====================================\r\n");
        for(i=0;i<test_size;i++)
        {
            RTI_LOG("%c",wbuf[i]);
        }
        RTI_LOG("\r\n=================================================================\r\n");

        ret=SPINAND_Write_Page_SpareData(address1,(unsigned int)wbuf1,test_size);
        if(ret != NoError)
        {
			RTI_LOG("!!!SPINAND_Write FAIL, ret=%d",ret);
        }
        RTI_LOG("\r\n===========================wbuf1===================================\r\n");
        for(i=0;i<test_size;i++)
        {
            RTI_LOG("%c",wbuf1[i]);
        }
        RTI_LOG("\r\n=================================================================\r\n");

       ret=SPINAND_Write_Page_SpareData(address2,(unsigned int)wbuf2,test_size);
        if(ret != NoError)
        {
			RTI_LOG("!!!SPINAND_Write FAIL, ret=%d",ret);
        }
        RTI_LOG("\r\n===========================wbuf2===================================\r\n");
        for(i=0;i<test_size;i++)
        {
            RTI_LOG("%c",wbuf2[i]);
        }
        RTI_LOG("\r\n=================================================================\r\n");


        ret = SPINAND_Erase(address1, pFlashP->BlockSize, BOOT_FLASH);
        if(ret != NoError)
        {   
            RTI_LOG("!!!SPINAND_Erase FAIL, ret=%d",ret);
        }


        ret=SPINAND_Read_Page_SpareData(address,(unsigned int)rbuf,test_size);
        if(ret != NoError)
        {
			RTI_LOG("!!!SPINAND_Write FAIL, ret=%d",ret);
        }
        RTI_LOG("\r\n============================rbuf=================================\r\n");
        for(i=0;i<test_size;i++)
        {
            RTI_LOG("%c",rbuf[i]);
        }
        RTI_LOG("\r\n=================================================================\r\n");
        
        ret=SPINAND_Read_Page_SpareData(address1,(unsigned int)rbuf1,test_size);
        if(ret != NoError)
        {
			RTI_LOG("!!!SPINAND_Write FAIL, ret=%d",ret);
        }
        RTI_LOG("\r\n===========================rbuf1=================================\r\n");
        for(i=0;i<test_size;i++)
        {
            RTI_LOG("0x%X",rbuf1[i]);
        }

        RTI_LOG("\r\n=================================================================\r\n");   

        ret=SPINAND_Read_Page_SpareData(address2,(unsigned int)rbuf2,test_size);
        if(ret != NoError)
        {
			RTI_LOG("!!!SPINAND_Write FAIL, ret=%d",ret);
        }
        RTI_LOG("\r\n===========================rbuf2=================================\r\n");
        for(i=0;i<test_size;i++)
        {
            RTI_LOG("%c",rbuf2[i]);
        }
        RTI_LOG("\r\n=================================================================\r\n");  

		OSATaskSleep(1*20); //10*100
}

void spinand_test_task222(void *arg)
{

	int test_size    = 0;
	unsigned int count = 0;
	unsigned char *wbuf = NULL;
	unsigned char *rbuf = NULL;
	int i = 0;
	int j = 0;
	unsigned int address = 0;	
	int block_num = 0;
	unsigned int round = 0;
	unsigned int err_cnt = 0;
	unsigned int ret=0;

	P_FlashProperties_T pFlashP = get_flashprop(0);
	
	test_size = pFlashP->BlockSize; //page = 0x800; block= 0x20000
	wbuf = (unsigned char *)malloc(test_size);
	rbuf = (unsigned char *)malloc(test_size);
	
	memset(wbuf,0,test_size);
	for (i = 0; i < test_size; i++)
		wbuf[i] = i%256;

	RTI_LOG("start testing, test size=%d", test_size);


	while(1)
	{
		address = block_num * test_size;
		if (address > (pFlashP->BlockSize * pFlashP->NumBlocks))
		{
			address = 0;
			block_num = 0;
			round += 1;
		}
		
		if(count%10 == 0)
			RTI_LOG("spi nand flash testing, round=%d, count:%d, address:%p, err_cnt:%d, tx spend max:0x%x, rx spend max:0x%x", round, count, address,err_cnt,g_spi_nand_tx_dma_spend_max,g_spi_nand_rx_dma_spend_max);

		if(address % pFlashP->BlockSize == 0)
		{
			ret = SPINAND_Erase(address, pFlashP->BlockSize, BOOT_FLASH);
			if(ret != NoError)
			{	RTI_LOG("!!!SPINAND_Erase FAIL, ret=%d",ret);
			}
		}

		ret = SPINAND_Write(address, (unsigned int)wbuf, test_size, BOOT_FLASH);
		if(ret != NoError)
			RTI_LOG("!!!SPINAND_Write FAIL, ret=%d",ret);

		memset(rbuf,0,test_size);
		ret = SPINAND_Read(address, (unsigned int)rbuf, test_size, BOOT_FLASH);
		if(ret != NoError)
			RTI_LOG("!!!SPINAND_Read FAIL, ret=%d",ret);
		
		if (memcmp(wbuf, rbuf, test_size) != 0)
		{
			err_cnt++;
			CPUartLogPrintf("!!!spinand test error, count:%d, address:%p", count, address);
			RTI_LOG("!!!!!!!!!!!!!!!!!!!!!spinand test error, count:%d, address:%p", count, address);
			for(i=0; i<test_size; i=i+16)
			{
				CPUartLogPrintf("i=%d: %x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x",i,
					rbuf[i],rbuf[i+1],rbuf[i+2],rbuf[i+3],rbuf[i+4],rbuf[i+5],rbuf[i+6],rbuf[i+7],
					rbuf[i+8],rbuf[i+9],rbuf[i+10],rbuf[i+11],rbuf[i+12],rbuf[i+13],rbuf[i+14],rbuf[i+15]);
				RTI_LOG("i=%d: %x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x",i,
					rbuf[i],rbuf[i+1],rbuf[i+2],rbuf[i+3],rbuf[i+4],rbuf[i+5],rbuf[i+6],rbuf[i+7],
					rbuf[i+8],rbuf[i+9],rbuf[i+10],rbuf[i+11],rbuf[i+12],rbuf[i+13],rbuf[i+14],rbuf[i+15]);
			}
			return;
		}
		else
		{
			CPUartLogPrintf("spinand test ok, count:%d, address:%p", count, address);
		}
		count++;
		block_num++;
		OSATaskSleep(1*100); //10*100
	}
}


OSTaskRef     spinand_testtaskref   = NULL;
static void   *spinand_teststack     = NULL;

int spinand_flashtest(void)
{
    spinand_teststack = (void *)malloc(20*1024);
    OSATaskCreate(&spinand_testtaskref, spinand_teststack, 20*1024, 60, "spinandt", spinand_test_task, NULL);
	return 0;
}

int spinand_flashtest222(void)
{
    spinand_teststack = (void *)malloc(20*1024);
    OSATaskCreate(&spinand_testtaskref, spinand_teststack, 20*1024, 60, "spinandt", spinand_test_task222, NULL);
	return 0;
}

#define SPI_NAND_PAGE_SZIE 0x800
void spinand_read_page(unsigned int FlashOffset)
{
	unsigned int ret=0;
	unsigned int i=0;
	unsigned char *rbuf = (unsigned char *)malloc(SPI_NAND_PAGE_SZIE);
	
	CPUartLogPrintf("%s,address:0x%x",FlashOffset);
	memset(rbuf,0x0,SPI_NAND_PAGE_SZIE);
	ret = SPINAND_Read(FlashOffset, (unsigned int)rbuf, SPI_NAND_PAGE_SZIE, BOOT_FLASH);
	if(ret != NoError)
	RTI_LOG("!!!SPINAND_Read FAIL, ret=%d",ret);

	for(i=0; i<SPI_NAND_PAGE_SZIE; i=i+16)
	{
		CPUartLogPrintf("%s,i=%d: %x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x",__func__,i,
			rbuf[i],rbuf[i+1],rbuf[i+2],rbuf[i+3],rbuf[i+4],rbuf[i+5],rbuf[i+6],rbuf[i+7],
			rbuf[i+8],rbuf[i+9],rbuf[i+10],rbuf[i+11],rbuf[i+12],rbuf[i+13],rbuf[i+14],rbuf[i+15]);
	}

	free(rbuf);

}

void spinand_write_page(unsigned int FlashOffset)
{
	unsigned int ret=0;
	unsigned int i=0;
	unsigned char *wbuf = (unsigned char *)malloc(SPI_NAND_PAGE_SZIE);
	unsigned char *rbuf = (unsigned char *)malloc(SPI_NAND_PAGE_SZIE);

	RTI_LOG("address:0x%x",FlashOffset);

	memset(wbuf,0,SPI_NAND_PAGE_SZIE);
	for (i = 0; i < SPI_NAND_PAGE_SZIE; i++)
		wbuf[i] = i%256;

	ret = SPINAND_Erase(FlashOffset, 0x10000, BOOT_FLASH);
	if(ret != NoError)
	{	RTI_LOG("!!!SPINAND_Erase FAIL, ret=%d",ret);
	}

	ret = SPINAND_Write(FlashOffset, (unsigned int)wbuf, SPI_NAND_PAGE_SZIE, BOOT_FLASH);
	if(ret != NoError)
	RTI_LOG("!!!SPINAND_Read FAIL, ret=%d",ret);

	memset(rbuf,0x0,SPI_NAND_PAGE_SZIE);
	ret = SPINAND_Read(FlashOffset, (unsigned int)rbuf, SPI_NAND_PAGE_SZIE, BOOT_FLASH);
	if(ret != NoError)
		RTI_LOG("!!!SPINAND_Read FAIL, ret=%d",ret);
	
	if (memcmp(wbuf, rbuf, SPI_NAND_PAGE_SZIE) != 0)
	{
		RTI_LOG("!!!%s error",__func__);
		for(i=0; i<SPI_NAND_PAGE_SZIE; i=i+16)
		{
			RTI_LOG("%s,i=%d: %x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x",__func__,i,
				rbuf[i],rbuf[i+1],rbuf[i+2],rbuf[i+3],rbuf[i+4],rbuf[i+5],rbuf[i+6],rbuf[i+7],
				rbuf[i+8],rbuf[i+9],rbuf[i+10],rbuf[i+11],rbuf[i+12],rbuf[i+13],rbuf[i+14],rbuf[i+15]);
		}
	}

	free(wbuf);
	free(rbuf);

}


#endif


