/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
                SPI.c
GENERAL DESCRIPTION

    This file is for SPI nor flash.

EXTERNALIZED FUNCTIONS

INITIALIZATION AND SEQUENCING REQUIREMENTS

   Copyright (c) by ASR micro.  All Rights Reserved.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
===========================================================================*/

/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/
#include "spi.h"
#include "qspi_dma.h"
#include "quec_spi.h"
#include "quec_startup_gpio.h"

/*===========================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

===========================================================================*/
#if 0
/* Non-cache */
//#pragma arm section rwdata="SSPCmd", zidata="SSPCmd"
//__align(16) unsigned int 	TxCmd[2];
//__align(16) unsigned char 	tx_1bytes[5];
//__align(8)  unsigned char 	DMA_PP[260];
//#pragma arm section rwdata, zidata
#endif
unsigned int TxCmd[2];

#if 0
/* Non-cache */
//#pragma arm section rwdata="DMARdBuf", zidata="DMARdBuf"
//__align(16) unsigned char DMA_Read_Buffer[MAX_TEST_SIZE+16] = {0};
//#pragma arm section rwdata, zidata
#endif

#define spi_uart_log(fmt, args...)     do { uart_printf("[SPI]"fmt"\r\n", ##args); } while(0)
#define spi_uart_log_err(fmt, args...) do { uart_printf("[SPI]ERR-"fmt"\r\n", ##args); } while(0)


//#define SSP_DMA_INTERRUPT

#ifdef SSP_DMA_INTERRUPT
static OSFlagRef ssp_rx_dma_done_FlgRef = NULL;
static OSFlagRef ssp_tx_dma_done_FlgRef = NULL;
#endif
unsigned char ssp_rx_dma_work_flg = FALSE;
unsigned char ssp_tx_dma_work_flg = FALSE;

#define BU_REG_READ8(x) (*(volatile unsigned char *)(x) & 0xff)
#define BU_REG_WRITE8(x,y) ((*(volatile unsigned char *)(x)) = y & 0xff )

/*===========================================================================

            EXTERN DEFINITIONS AND DECLARATIONS FOR MODULE

===========================================================================*/

extern unsigned int dma_read_status(unsigned int channel);
extern void CacheInvalidateMemory( void *pMem, unsigned int size);
extern void CacheCleanMemory( void *pMem ,unsigned int size);
/*===========================================================================

                          INTERNAL FUNCTION DEFINITIONS

===========================================================================*/
void SPINOR_Write_Read(unsigned char *cmd, unsigned char *data, unsigned char len);
unsigned int SPINOR_Page_Program_DMA(unsigned int Address, unsigned char * Buffer, unsigned int Size);
unsigned int SPINOR_EraseBlock(unsigned int Addr);
unsigned int SPINOR_Endian_Convert (unsigned int in);
unsigned int SPINOR_WaitSSPComplete(void);
unsigned int SPINOR_ReadStatus(unsigned int Wait);
void SPINOR_DisableSSP(void);
void SPINOR_FireUpSSP(void);
void SPINOR_Reset(int sspport);
void SPINOR_ReadId(int sspport, unsigned int *pID);
void SPINOR_WriteEnable(void);
void Assert_CS(void);
void Deassert_CS(void);
unsigned int SPINOR_WaitForWEL(unsigned int Wait);


static FlashProperties_T FlashProp[3];
static unsigned char FlashProtect = 0;
static int GpioPinOfCS  = 0;
static int SSPport      = 0;  //assign SSPx //0-SPI0, 1-SPI1, 2-SP2
#if 0
static OSSemaRef spiSem = NULL;
#endif
static unsigned int SSPBase[3] = {SSP0_BASE, SSP1_BASE, SSP2_BASE};
static unsigned int GpioOfCS[3] = {0,0,13};

#if 1
#define GPIO_SHIFT(gpio) (1 << (gpio%32))
typedef struct 
{
	unsigned int REG;
	unsigned int padding[2];
}GPIO_Single_Register;

typedef volatile struct
{
	volatile GPIO_Single_Register PLR;//0x0
	volatile GPIO_Single_Register PDR;//0xc
	volatile GPIO_Single_Register PSR;//0X18
	volatile GPIO_Single_Register PCR;//0X24
	volatile GPIO_Single_Register RER;//0X30
	volatile GPIO_Single_Register FER;//0X3C
	volatile GPIO_Single_Register EDR;//0X48
	volatile GPIO_Single_Register SDR;//0X54
	volatile GPIO_Single_Register CDR;//0X60
	volatile GPIO_Single_Register SRER;//0X6C
	volatile GPIO_Single_Register CRER;//0X78
	volatile GPIO_Single_Register SFER;//0X84
	volatile GPIO_Single_Register CFER;//0X90
	volatile GPIO_Single_Register AP_MASK;//0X9C
	volatile GPIO_Single_Register CP_MASK;//0XA8
}GPIORegisters;

static unsigned int *GetBaseAddr(unsigned int portHandle)
{
	unsigned int base_addr;

	if(portHandle < 32)
		base_addr =  0xD4019000 + 0x0;
	else if(portHandle < 64)
		base_addr =  0xD4019000 + 0x4;
	else if(portHandle < 96)
		base_addr =  0xD4019000 + 0x8;
	else if(portHandle < 128)
		base_addr =  0xD4019000 + 0x100;
	else
		base_addr =  0;

	return (unsigned int *)base_addr;
}

static void GpioSetDirection(unsigned int portHandle, unsigned int dir)
{
	GPIORegisters *GPIOReg;
	GPIOReg = (GPIORegisters *)GetBaseAddr(portHandle);

	switch (dir) {
		case 1:
			GPIOReg->SDR.REG =	GPIO_SHIFT(portHandle);
			break;
		case 0:
			GPIOReg->CDR.REG =	GPIO_SHIFT(portHandle);
			break;
	}
	return;

}
static void GpioSetLevel(unsigned int portHandle, unsigned int value)
{
	GPIORegisters *GPIOReg;
	GPIOReg = (GPIORegisters *)GetBaseAddr(portHandle);

	switch (value) {
		case 1:
			GPIOReg->PSR.REG = GPIO_SHIFT(portHandle);
			break;
		case 0:
			GPIOReg->PCR.REG = GPIO_SHIFT(portHandle);
			break;
		}

	return;
}
#endif


static unsigned int GetSSPBase()
{
	return SSPBase[SSPport];
}

static void SetSSPPort(int port)
{
	SSPport = port;
}

int SPINOR_getSSPPort(void)
{
	return SSPport;
}


static void SetCSGpio(int sspport, unsigned int gpio)
{
	GpioOfCS[sspport] = gpio;
}

static void Assert_CS(void)
{
	ql_gpio_set_level((GPIO_PIN_NUMBER_E)GpioOfCS[SSPport], PIN_LEVEL_LOW);
}

static void Deassert_CS(void)
{
	ql_gpio_set_level((GPIO_PIN_NUMBER_E)GpioOfCS[SSPport], PIN_LEVEL_HIGH);
}

static P_FlashProperties_T GetFlashProperties(int sspport)
{
    return &FlashProp[sspport];
}
extern int quec_spi_pin_selflag;
static void ChipSelectSPI(int port, SSP_Clock clock )
{
	unsigned int apbc_ssp_base = 0;
	if (port == 0)
	{
		apbc_ssp_base = (unsigned int)APBC_SSP0_CLK_RST;
		//config clk, cs, rx, tx, hold, wp according to hardware,use cs as GPIO function.
		if(quec_spi_pin_selflag == 1)//miles.ma 20221105 add
		{
			*(volatile unsigned int*)0xD401E160 = 0x1881;	//ssp0_sclk--gpio33
			*(volatile unsigned int*)0xD401E164 = 0x1880;	//ssp0_frm --gpio34, cs use gpio function
			SetCSGpio(port, 34);	//set cs pin
			*(volatile unsigned int*)0xD401E168 = 0x1881;	//ssp0_rxd --gpio35
			*(volatile unsigned int*)0xD401E16C = 0x1881;	//ssp0_txd --gpio36

			ql_gpio_set_direction((GPIO_PIN_NUMBER_E)34, PIN_DIRECTION_OUT);
    		ql_gpio_set_level((GPIO_PIN_NUMBER_E)34,PIN_LEVEL_HIGH);
		}
		else
		{
			*(volatile unsigned int*)0xD401E11C = 0x1882;	//ssp0_sclk--gpio16
			*(volatile unsigned int*)0xD401E120 = 0x1880;	//ssp0_frm --gpio17, cs use gpio function
			SetCSGpio(port, 17);	//set cs pin
			*(volatile unsigned int*)0xD401E124 = 0x1884;	//ssp0_rxd --gpio18
			*(volatile unsigned int*)0xD401E128 = 0x1884;	//ssp0_txd --gpio19

			//ssp0_frm output high
			ql_gpio_set_direction((GPIO_PIN_NUMBER_E)17, PIN_DIRECTION_OUT);
    		ql_gpio_set_level((GPIO_PIN_NUMBER_E)17,PIN_LEVEL_HIGH);
		}

	}
	else if (port == 1)
		apbc_ssp_base = (unsigned int)APBC_SSP1_CLK_RST;
	else
	{
		apbc_ssp_base = (unsigned int)APBC_SSP2_CLK_RST;
		
		/*************************************************************************
		config clk, cs, rx, tx, hold, wp according to hardware,use cs as GPIO function.
		*steps:
		*1. config clk,rx,tx as SSP function
		*2. config cs as gpio functon and use SetCSGpio(ssppot, csgpionum)
		*3. config hold&wp as gpio function, set output direction, set high level
		*4. config cs with output direction and high level
		*************************************************************************/
        if(quec_spi_pin_selflag == 3)//miles.ma 20221105 add
        {
            *(volatile unsigned int*)0xD401E10C = 0x1881;	//ssp2_sclk--gpio12
    		*(volatile unsigned int*)0xD401E110 = 0x1880;	//ssp2_frm --gpio13, cs use gpio function
    		SetCSGpio(port, 13);	//set cs pin
    		*(volatile unsigned int*)0xD401E114 = 0x1881;	//ssp2_rxd --gpio14
    		*(volatile unsigned int*)0xD401E118 = 0x1881;	//ssp2_txd --gpio15

    		//ssp2_frm output high
    		ql_gpio_set_direction((GPIO_PIN_NUMBER_E)13, PIN_DIRECTION_OUT);
    		ql_gpio_set_level((GPIO_PIN_NUMBER_E)13,PIN_LEVEL_HIGH);
        }
        else
        {
    		*(volatile unsigned int*)0xD401E160 = 0x1882;	//ssp2_sclk--gpio33
    		*(volatile unsigned int*)0xD401E164 = 0x1880;	//ssp2_frm --gpio34, cs use gpio function
    		SetCSGpio(port, 34);	//set cs pin
    		*(volatile unsigned int*)0xD401E168 = 0x1882;	//ssp2_rxd --gpio35
    		*(volatile unsigned int*)0xD401E16C = 0x1882;	//ssp2_txd --gpio36

    		//ssp2_frm output high
    		ql_gpio_set_direction((GPIO_PIN_NUMBER_E)34, PIN_DIRECTION_OUT);
    		ql_gpio_set_level((GPIO_PIN_NUMBER_E)34,PIN_LEVEL_HIGH);
        }
		
	}
	
	
	/*enabled SSP2 clock, then take out of reset
      BIT 0: SSP 2 APB Bus Clock Enable/Disable.
        0 = Clock off
        1 = Clock on
      BIT 1: SSP 2 Functional Clock Enable/Disable.
        0 = Clock off
        1 = Clock on
      BIT 2: SSP 2 Reset Generation.
        This field resets both the APB and functional domain.
        0 = No Reset
        1 = Reset
    */
	spi_reg_write(apbc_ssp_base, BIT_0 | BIT_1 | BIT_2);

    /*Functional Clock Select
	    0x0 = 6.5 MHz
	    0x1 = 13 MHz
	    0x2 = 26 MHz
	    0x3 = 52 MHz
	    All other values = Reserved, do not use
	*/
    switch(clock)
    {
        case SSP_CLOCK_13M:
        {
            spi_reg_write(apbc_ssp_base, BIT_0 | BIT_1 | (1 << 4)); // 13MHZ
            break;
        }

        case SSP_CLOCK_26M:
        {
            spi_reg_write(apbc_ssp_base, BIT_0 | BIT_1 | (2 << 4)); // 26MHZ
            break;
        }

		case SSP_CLOCK_52M:
        {
            spi_reg_write(apbc_ssp_base, BIT_0 | BIT_1 | (3 << 4)); // 52MHZ
            break;
        }

        default:
        {
            spi_reg_write(apbc_ssp_base, BIT_0 | BIT_1 | (1 << 4)); // 13MHZ
            break;
        }
    }

	spi_uart_log("%s,port=%d,apbc_ssp_base addr:0x%x,value:0x%02x",__func__, port, apbc_ssp_base, spi_reg_read(apbc_ssp_base));

	return;
}

#ifdef SSP_DMA_INTERRUPT
int ssp_dma_tx_complete_handler(UINT32 val) 
{
    dma_xfer_stop( DMA_DEV_SSP2_TX_CH );
	dma_xfer_stop( DMA_DEV_SSP2_RX_CH );
	OSAFlagSet(ssp_tx_dma_done_FlgRef, 0x01, OSA_FLAG_OR);
	return 0;
}

int ssp_dma_rx_complete_handler(UINT32 val)
{
    dma_xfer_stop( DMA_DEV_SSP2_TX_CH );
	dma_xfer_stop( DMA_DEV_SSP2_RX_CH );
	OSAFlagSet(ssp_rx_dma_done_FlgRef, 0x01, OSA_FLAG_OR);
	return 0;
}
#endif


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      InitializeSPIDevice                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function intializes SPI nor device                           */
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
#if 0
BOOL CheckIf32MNOR( void )
{
    P_FlashProperties_T pFlashP = GetFlashProperties(BOOT_FLASH);

    if((pFlashP->BlockSize * pFlashP->NumBlocks) == 0x2000000)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
#endif


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_ROW_DELAY                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function delay some times.                                   */
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
static void SPINOR_ROW_DELAY(unsigned int x)
{
    volatile long i = 0;

    i = x;

	while (i > 0)
	{
		i--;
	}
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_Endian_Convert                                            */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function is endian conversion function                       */
/*      convert to big endian                                            */
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
static unsigned int SPINOR_Endian_Convert (unsigned int in)
{
	unsigned int out;
	out = in << 24;
	out |= (in & 0xFF00) << 8;
	out |= (in & 0xFF0000) >> 8;
	out |= (in & 0xFF000000) >> 24;
	return out;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_DisableSSP                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function disable SSP.                                        */
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
static void SPINOR_DisableSSP(void)
{
    //make sure SSP is disabled
    spi_reg_bit_clr(SSP_TCR, SSP_TCR_SSE);

    //reset SSP CR's
    spi_reg_write(SSP_TCR, SSP_TCR_INITIAL);
    spi_reg_write(SSP_FCR, SSP_FCR_INITIAL);
    spi_reg_write(SSP_IER, SSP_IER_INITIAL);
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_FireUpSSP                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function Enable SSP.                                         */
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
static void SPINOR_FireUpSSP(void)
{
    spi_reg_bit_set(SSP_TCR, SSP_TCR_SSE);
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_SSP_DSS                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function Select Data Size.                                   */
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
static void SPINOR_SSP_DSS(int DataSize)
{
    switch(DataSize)
    {
        case 16:
        {
            spi_reg_bit_clr(SSP_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP_TCR, SSP_TCR_DSS16);
        	break;
        }

        case 24:
        {
            spi_reg_bit_clr(SSP_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP_TCR, SSP_TCR_DSS24);
        	break;
        }

        case 32:
        {
            spi_reg_bit_clr(SSP_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP_TCR, SSP_TCR_DSS32);
        	break;
        }
		case 8:
		{
			spi_reg_bit_clr(SSP_TCR, SSP_TCR_DSS_MASK);
            spi_reg_bit_set(SSP_TCR, SSP_TCR_DSS8);
			break;
		}
        default:
        {
            break;
        }
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_WaitSSPComplete                                           */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function wait for SSP completion.                            */
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
static unsigned int SPINOR_WaitSSPComplete(void)
{
    volatile int timeout = 0;

	timeout = 0xFFFFF;

    while ((*SSP_STS & (SSP_STS_TFL | SSP_STS_TF_NF | SSP_STS_BSY)) != SSP_STS_TF_NF)
	{
		if((timeout--) <= 0)
    	{
    		spi_uart_log_err("SPINOR_WaitSSPComplete timeout");
    		return SSPWaitCompleteTimeOutError;
        }

        SPINOR_ROW_DELAY(DEFAULT_TIMEOUT);
	}

	return 0;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_Write_Read                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function use PIO mode to write and then read out the data.   */
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
static void SPINOR_Write_Read(unsigned char *cmd, unsigned char *data, unsigned char len)
{
	unsigned char i;

	for (i = 0; i < len; i++)
	{
		BU_REG_WRITE8(SSP_DR, cmd[i]);
		SPINOR_WaitSSPComplete();

		data[i] = BU_REG_READ8(SSP_DR);
	}
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_Reset                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function reset SPI nor.                                      */
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
static void SPINOR_Reset(int sspport)
{
	unsigned int temp;
    unsigned int Retval = 0;
	
	SetSSPPort(sspport);

    SPINOR_DisableSSP();

    //fire it up
	SPINOR_FireUpSSP();

    Assert_CS();

	spi_reg_write(SSP_DR, SPI_CMD_RELEASE_POWER_DOWN);

	Retval = SPINOR_WaitSSPComplete();
    if(Retval != 0)
    {
        spi_uart_log_err("SPINOR_Reset status 0x%x", Retval);
    }

	temp = *SSP_DR;

    Deassert_CS();

	SPINOR_DisableSSP();

	SPINOR_ROW_DELAY(1000);

	spi_uart_log("%s done",__func__);

	return;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_SW_Reset                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function reset SPI nor.                                      */
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
void SPINOR_SW_Reset(int sspport)
{
	unsigned int temp;
    unsigned int Retval = 0;
	unsigned short reset_cmd = 0x0;
	
	spi_uart_log("%s, enter",__func__);

	SetSSPPort(sspport);

    SPINOR_DisableSSP();

	//setup in 16 bit mode
   	SPINOR_SSP_DSS(16);

	reset_cmd = SPI_CMD_RESET_ENABLE<<8 | SPI_CMD_RESET;

    //fire it up
	SPINOR_FireUpSSP();

    Assert_CS();

	spi_reg_write(SSP_DR, reset_cmd);

	Retval = SPINOR_WaitSSPComplete();
    if(Retval != 0)
    {
        spi_uart_log_err("SPINOR_SW_Reset status 0x%x", Retval);
    }

	temp = *SSP_DR;

    Deassert_CS();

	SPINOR_DisableSSP();

	SPINOR_ROW_DELAY(1000);

	return;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_ReadStatus                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function read SPI nor status.                                */
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
static unsigned int SPINOR_ReadStatus(unsigned int Wait)
{
	unsigned int read = 0, ready = 0, dummy = 0, status = 0;
	volatile int timeout = 0;

	timeout = 0xFFFFF;

	read = FALSE;	//this flag gets set when we read first entry from fifo
	//if the caller waits to 'Wait' for the BUSY to be cleared, start READY off as FALSE
	//if the caller doesn't wait to wait, set READY as true, so we don't wait on the bit
	ready = (Wait) ? FALSE : TRUE;

	do{
	    //make sure SSP is disabled
	    SPINOR_DisableSSP();

    	//setup in 16 bit mode
    	SPINOR_SSP_DSS(16);

    	//fire it up
    	SPINOR_FireUpSSP();

        Assert_CS();

		//load the command + 1 dummy byte
		*SSP_DR = SPI_CMD_READ_STATUS << 8;

		//wait till the TX fifo is empty, then read out the status
		if(SPINOR_WaitSSPComplete() != 0)
		{
            spi_uart_log_err("SPINOR_ReadStatus timeout");
			return SSPWaitTxEmptyTimeOutError;
		}

		dummy = *SSP_DR;

		Deassert_CS();

		//set the READ flag, and read the status
		read = TRUE;
		status = dummy & 0xFF;	//the status will be in the second byte

		//set the READY flag if the status wait bit is cleared
		if((status & 1) == 0)		// operation complete (eg. not busy)?
			ready = TRUE;

		//make sure SSP is disabled
		SPINOR_DisableSSP();

		//if we've waited long enough, fail
		if((timeout--) <= 0)
		{
		    spi_uart_log_err("SSP Read Status 0x%x", *SSP_DR);
			return SSPRdStatusTimeOutError;
		}
		//we need to wait until we read at least 1 valid status entry
		//if we're waiting for the Write, wait till WIP bits goes to 0
	}while ((!read) || (!ready));


	//return last known status
	return 0;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_WaitForWEL                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function wait for write enablle.                                */
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
static unsigned int SPINOR_WaitForWEL(unsigned int Wait)
{
	unsigned int read = 0, ready = 0, dummy = 0, status = 0;
	volatile int timeout = 0;

	read = FALSE;	//this flag gets set when we read first entry from fifo
	//if the caller waits to 'Wait' for the BUSY to be cleared, start READY off as FALSE
	//if the caller doesn't wait to wait, set READY as true, so we don't wait on the bit
	ready = (Wait) ? FALSE : TRUE;

	timeout = 0xFF;

	do{
	    //make sure SSP is disabled
	    SPINOR_DisableSSP();

    	//setup in 16 bit mode
    	SPINOR_SSP_DSS(16);

    	//fire it up
    	SPINOR_FireUpSSP();

    	Assert_CS();

		//load the command + 1 dummy byte
		*SSP_DR = SPI_CMD_READ_STATUS << 8;

        //wait till the TX fifo is empty, then read out the status
		if(SPINOR_WaitSSPComplete() != 0)
		{
            spi_uart_log_err("Wait For WEL timeout");
			return SSPWelWaitTxEmptyTimeOutError;
		}

		dummy = *SSP_DR;

		Deassert_CS();

		//set the READ flag, and read the status
		read = TRUE;
		status = dummy & 0xFF;	//the status will be in the second byte

		//set the READY flag if the status wait bit is cleared*/
		/* WIP bit(S0):The Write in Progress (WIP) bit indicates whether the memory is busy in program/erase/write status register progress. */
		/* When WIP bit sets to 1, means the device is busy in program/erase/write status register progress, */
		/* when WIP bit sets 0, means the device is not in program/erase/write status register progress. */

		/*WEL bit(S1):The Write Enable Latch (WEL) bit indicates the status of the internal Write Enable Latch. */
		/*When set to 1 the internal Write Enable Latch is set, */
		/*when set to 0 the internal Write Enable Latch is reset and no Write Status Register, Program or Erase command is accepted. */
		if((status & 0x03) == 0x02)		// Write Enable Latch and Operation not in Progress
			ready = TRUE;

		//make sure SSP is disabled
		SPINOR_DisableSSP();

		//if we've waited long enough, fail
		if((timeout--) <= 0)
		{
		    spi_uart_log_err("Wait For WEL, SSP Read Status 0x%x", *SSP_DR);
			return SSPWaitForWELTimeOutError;
		}

		//we need to wait until we read at least 1 valid status entry
		//if we're waiting for the Write, wait till WIP bits goes to 0
	}while ((!read) || (!ready));


	//return last known status
	return 0;
}



/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_WriteEnable                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function enable SPI nor write operation.                     */
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
static void SPINOR_WriteEnable(void)
{
	unsigned int temp;
    unsigned int Retval = 0;

    //make sure SSP is disabled
    SPINOR_DisableSSP();

	//fire it up
	SPINOR_FireUpSSP();

	Assert_CS();

	//load the command
	spi_reg_write(SSP_DR, SPI_CMD_WRITE_ENABLE);

	//wait till TX fifo is empty
	Retval = SPINOR_WaitSSPComplete();
    if(Retval != 0)
    {
        spi_uart_log_err("SPINOR_WriteEnable status 0x%x", Retval);
    }

	temp = *SSP_DR;

	Deassert_CS();

	//make sure SSP is disabled
	SPINOR_DisableSSP();

	return;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_ReadId                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function read the Nor ID.                                     */
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
void SPINOR_ReadId(int sspport, unsigned int *pID)
{
	unsigned int ID;
    unsigned int Retval = 0;

	SetSSPPort(sspport);

    SPINOR_DisableSSP();

	//setup in 32 bit mode
	SPINOR_SSP_DSS(32);

	//fire it up
	SPINOR_FireUpSSP();

	Assert_CS();

	spi_reg_write(SSP_DR, (unsigned int)SPI_CMD_JEDEC_ID << 24);

	Retval = SPINOR_WaitSSPComplete();
    if(Retval != 0)
    {
        spi_uart_log_err("SPINOR_ReadId status 0x%x", Retval);
    }

	ID = *SSP_DR;

    Deassert_CS();

	//make sure SSP is disabled
	//it must be executed lastly,
	//because disable SP will result in RXFIFO/TXFIFO reset.
	SPINOR_DisableSSP();

	*pID = ID;

	return;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      spinor_dma_work                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function control spi nor flash dma work lock flag.           */
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

unsigned char spinor_dma_work(void)
{
	return ssp_rx_dma_work_flg|ssp_tx_dma_work_flg;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_Page_Program_DMA                                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function do DMA page program operation.                      */
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
static unsigned int SPINOR_Page_Program_DMA(unsigned int Address, unsigned char * Buffer, unsigned int Size)
{
    unsigned int *pWrite = NULL;
    DMA_CMDx_T TX_Cmd, RX_Cmd;
    unsigned char data[10];
    unsigned int Retval = 0, i = 0;
    volatile int timeout = 0;
    unsigned char cmd[4];

	ssp_tx_dma_work_flg = TRUE;

	TX_Cmd.value = 0;
	TX_Cmd.bits.IncSrcAddr = 1;
	TX_Cmd.bits.IncTrgAddr = 0;
	TX_Cmd.bits.FlowSrc = 0;
	TX_Cmd.bits.FlowTrg = 1;
	TX_Cmd.bits.Width = 3;
	TX_Cmd.bits.MaxBurstSize = 2;
    TX_Cmd.bits.Length = Size;

    cmd[0] = SPI_CMD_PROGRAM;
	cmd[1] = (Address >> 16) & 0xFF;
	cmd[2] = (Address >> 8) & 0xFF;
	cmd[3] = (Address >> 0) & 0xFF;

#if 0
    ASSERT(Size <= 256);
#endif

   // memcpy(DMA_PP, (unsigned char *)Buffer, Size);
  //  pWrite = (unsigned int *)DMA_PP;
    CacheCleanMemory((void *)Buffer, Size);    

	if (SSPport == 0)
		dma_map_device_to_channel(DMA_REQ_SSP0_TX, DMA_DEV_SSP2_TX_CH);
	else if(SSPport == 1)
		dma_map_device_to_channel(DMA_REQ_SSP1_TX, DMA_DEV_SSP2_TX_CH);
	else if (SSPport == 2)
		dma_map_device_to_channel(DMA_REQ_SSP2_TX, DMA_DEV_SSP2_TX_CH);
	else
	{
        spi_uart_log_err("port %d not support",SSPport);
		return 1;
    }

	set_user_aligment(DMA_DEV_SSP2_TX_CH);
	dma_set_mode(DMA_MODE_NONFETCH, DMA_DEV_SSP2_TX_CH);
	dma_set_reg_nf((unsigned int)Buffer, (unsigned int)SSP_DR, &TX_Cmd, DMA_DEV_SSP2_TX_CH);

    SPINOR_DisableSSP();

    //fire it up
    SPINOR_FireUpSSP();

    Assert_CS();

    SPINOR_Write_Read(cmd, data, 4);

    //make sure SSP is disabled
	spi_reg_bit_clr(SSP_TCR, SSP_TCR_SSE);

    //reset SSP CR's
    spi_reg_write(SSP_TCR, SSP_TCR_INITIAL);
    spi_reg_write(SSP_FCR, SSP_FCR_INITIAL);
    spi_reg_write(SSP_IER, SSP_IER_INITIAL);

	//setup in 32bit mode
	spi_reg_bit_clr(SSP_TCR, SSP_TCR_DSS_MASK);
	spi_reg_bit_set(SSP_TCR, SSP_TCR_DSS32);

	spi_reg_bit_set(SSP_TCR, SSP_TCR_TRIAL);

	spi_reg_write(SSP_FCR, SSP_FCR_DMA_PAGE_PROGRAM | SSP_FCR_TWE(2));

	//setup IER
	spi_reg_bit_set(SSP_IER, SSP_IER_TIE | SSP_IER_RIE);

	//fire SSP up
	spi_reg_bit_set(SSP_TCR, SSP_TCR_SSE);

#ifdef SSP_DMA_INTERRUPT
    OSA_STATUS os_status = OS_SUCCESS;
    UINT32  flag_value = 0;

    dma_xfer_start_with_irq_enable(DMA_DEV_SSP2_TX_CH);
    os_status = OSAFlagWait(ssp_tx_dma_done_FlgRef, 0x01, OSA_FLAG_OR_CLEAR, &flag_value, 600);
    if(os_status != OS_SUCCESS)
    {
    	if((dma_read_status(DMA_DEV_SSP2_TX_CH) & CSR_STOPINTR) != CSR_STOPINTR)
        {
        	spi_uart_log_err("%s, os_status:%d, DMA status:0x%x, SSP status:0x%x", __FUNCTION__, os_status, dma_read_status(DMA_DEV_SSP2_TX_CH), *SSP_STS);
        	Retval = SSPTxChannelTimeOutError;
    	}
    }
#else    
    //Kick off DMA
	dma_xfer_start(DMA_DEV_SSP2_TX_CH);

    //timer loop waiting for dma to finish
    //setup a timer to fail gracefully in case of error
    timeout = 0xFFFFF;

    //wait until the TX channel gets the stop unsigned interrupt and the TX fifo is drained
    while( ((dma_read_status(DMA_DEV_SSP2_TX_CH) & CSR_STOPINTR) != CSR_STOPINTR) ||
           ((*SSP_STS & (SSP_STS_TFL | SSP_STS_TF_NF | SSP_STS_BSY)) != SSP_STS_TF_NF) )
    {
        //if we've waited long enough, fail
        if((timeout--) <= 0)
        {
            spi_uart_log_err("write DMA Status 0x%x, SSP Status 0x%x", dma_read_status(DMA_DEV_SSP2_TX_CH), *SSP_STS);
			Retval = SSPTxChannelTimeOutError;
			break;
        }
    }
#endif

    //if we errored out, kill the DMA transfers
    if(Retval != 0)
    {
        dma_xfer_stop( DMA_DEV_SSP2_TX_CH );
    }

    SPINOR_WaitSSPComplete();

    Deassert_CS();

    //make sure SSP is disabled
    SPINOR_DisableSSP();
	
	ssp_tx_dma_work_flg = FALSE;

	return Retval;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_Read_DMA                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function do DMA read operation.                              */
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
static unsigned int SPINOR_Read_DMA(unsigned int FlashOffset, unsigned char * Buffer, unsigned int Size, unsigned int CopySize)
{
    unsigned int  i = 0;
    unsigned char data[10];
    unsigned int  *temp_buff = NULL;
    unsigned int  read_size = 0, total_size = 0, Retval = 0, read_buff = 0;
    DMA_CMDx_T RX_Cmd, TX_Cmd;
    volatile int timeout = 0;
    unsigned char cmd[4];

	ssp_rx_dma_work_flg = TRUE;

    //read_buff = (unsigned int)DMA_Read_Buffer;
    CacheInvalidateMemory((void *)Buffer,Size);

    //fill out commands
    RX_Cmd.value = 0;
    RX_Cmd.bits.IncSrcAddr = 0;
    RX_Cmd.bits.IncTrgAddr = 1;
    RX_Cmd.bits.FlowSrc = 1;
    RX_Cmd.bits.FlowTrg = 0;
    RX_Cmd.bits.Width = 3;
    RX_Cmd.bits.MaxBurstSize = 2;
    RX_Cmd.bits.Length = Size;


    TX_Cmd.value = 0;
    TX_Cmd.bits.IncSrcAddr = 0;
    TX_Cmd.bits.IncTrgAddr = 0;
    TX_Cmd.bits.FlowSrc = 0;
    TX_Cmd.bits.FlowTrg = 1;
    TX_Cmd.bits.Width = 3;
    TX_Cmd.bits.MaxBurstSize = 2;
    TX_Cmd.bits.Length = Size;

	TxCmd[0] = 0x00;
    CacheCleanMemory(TxCmd, sizeof(TxCmd));

    cmd[0] = SPI_CMD_READ;
	cmd[1] = (FlashOffset >> 16) & 0xFF;
	cmd[2] = (FlashOffset >> 8) & 0xFF;
	cmd[3] = (FlashOffset >> 0) & 0xFF;

	if (SSPport == 0)
	{
		dma_map_device_to_channel(DMA_REQ_SSP0_RX, DMA_DEV_SSP2_RX_CH);
		dma_map_device_to_channel(DMA_REQ_SSP0_TX, DMA_DEV_SSP2_TX_CH);
	}
	else if (SSPport == 1)
	{
		dma_map_device_to_channel(DMA_REQ_SSP1_RX, DMA_DEV_SSP2_RX_CH);
		dma_map_device_to_channel(DMA_REQ_SSP1_TX, DMA_DEV_SSP2_TX_CH);
	}
	else if (SSPport == 2)
	{
		dma_map_device_to_channel(DMA_REQ_SSP2_RX, DMA_DEV_SSP2_RX_CH);
		dma_map_device_to_channel(DMA_REQ_SSP2_TX, DMA_DEV_SSP2_TX_CH);
	}
	else
	{
       	spi_uart_log_err("port %d not support",SSPport);
		return 1;
    }

	set_user_aligment(DMA_DEV_SSP2_TX_CH);
	set_user_aligment(DMA_DEV_SSP2_RX_CH);
	dma_set_mode(DMA_MODE_NONFETCH, DMA_DEV_SSP2_TX_CH);
	dma_set_mode(DMA_MODE_NONFETCH, DMA_DEV_SSP2_RX_CH);

	dma_set_reg_nf((unsigned int)SSP_DR, (unsigned int)Buffer, &RX_Cmd, DMA_DEV_SSP2_RX_CH);
	dma_set_reg_nf((unsigned int)&TxCmd[0], (unsigned int)SSP_DR, &TX_Cmd, DMA_DEV_SSP2_TX_CH);


    SPINOR_DisableSSP();

    //fire it up
    SPINOR_FireUpSSP();

    Assert_CS();

    SPINOR_Write_Read(cmd, data, 4);

    //make sure SSP is disabled
    spi_reg_bit_clr(SSP_TCR, SSP_TCR_SSE);

    //reset SSP CR's
    spi_reg_write(SSP_TCR, SSP_TCR_INITIAL);
    spi_reg_write(SSP_FCR, SSP_FCR_INITIAL);
    spi_reg_write(SSP_IER, SSP_IER_INITIAL);

    spi_reg_write(SSP_TOR, SSP_TOR_TIMEOUT);

	//setup in 32bit mode
    spi_reg_bit_clr(SSP_TCR, SSP_TCR_DSS_MASK);
    spi_reg_bit_set(SSP_TCR, SSP_TCR_DSS32);


    spi_reg_write(SSP_FCR, SSP_FCR_DMA_READ|SSP_FCR_RRE(2)|SSP_FCR_RAFC);

    spi_reg_bit_set(SSP_TCR, SSP_TCR_TRIAL);

    //setup IER
    spi_reg_bit_set(SSP_IER, SSP_IER_TIE | SSP_IER_RIE | SSP_IER_RTOIE);

    //fire SSP up
    spi_reg_bit_set(SSP_TCR, SSP_TCR_SSE);
    
#ifdef SSP_DMA_INTERRUPT
	OSA_STATUS os_status = OS_SUCCESS;
	UINT32	flag_value = 0;
    dma_xfer_start_with_irq_enable(DMA_DEV_SSP2_RX_CH);	
    dma_xfer_start(DMA_DEV_SSP2_TX_CH);	
	os_status = OSAFlagWait(ssp_rx_dma_done_FlgRef, 0x01, OSA_FLAG_OR_CLEAR, &flag_value, 600);
	if(os_status != OS_SUCCESS)
	{
		if((dma_read_status(DMA_DEV_SSP2_RX_CH) & CSR_STOPINTR) != CSR_STOPINTR)
        {
        	spi_uart_log_err("%s,os_status:%d,DMA Status:0x%x,SSP Status:0x%x", __FUNCTION__, os_status, dma_read_status(DMA_DEV_SSP2_RX_CH), *SSP_STS);
			Retval = SSPTxChannelTimeOutError;
		}
    }
#else
    //Kick off DMA    
    dma_xfer_start(DMA_DEV_SSP2_TX_CH);
	dma_xfer_start(DMA_DEV_SSP2_RX_CH);

    //setup a timer to fail gracefully in case of error
    timeout = 0x1FFFFF;

    //wait until the RX channel gets the stop unsigned interrupt and the TX fifo is drained
    while( ((dma_read_status(DMA_DEV_SSP2_RX_CH) & CSR_STOPINTR) != CSR_STOPINTR) ||
			(*SSP_STS & (0xF8000 | BIT_14 | SSP_STS_BSY)) != 0xF8000)
           //((*SSP_STS & (SSP_STS_TFL | SSP_STS_TF_NF | SSP_STS_BSY)) != SSP_STS_TF_NF) )
    {
        //if we've waited long enough, fail
        if((timeout--) <= 0)
        {
			spi_uart_log_err("DMA Status 0x%x, SSP Status 0x%x", dma_read_status(DMA_DEV_SSP2_RX_CH), *SSP_STS);

			Retval = SSPRxChannelTimeOutError;

            break;
        }
    }
#endif
    //if we errored out, kill the DMA transfers
    if(Retval != 0)
    {
        dma_xfer_stop( DMA_DEV_SSP2_RX_CH );
        dma_xfer_stop( DMA_DEV_SSP2_TX_CH );
    }

    SPINOR_WaitSSPComplete();

    Deassert_CS();

    //make sure SSP is disabled
    spi_reg_bit_clr(SSP_TCR, SSP_TCR_SSE | SSP_TCR_HFL);
    //reset SSP CR's
    spi_reg_write(SSP_TCR, SSP_TCR_INITIAL);
    spi_reg_write(SSP_FCR, SSP_FCR_INITIAL);
    spi_reg_write(SSP_IER, SSP_IER_INITIAL);
    spi_reg_write(SSP_TOR, 0);

	//if(Retval == 0)
    //	memcpy( (unsigned char *)Buffer, (unsigned char *)DMA_Read_Buffer, CopySize );

	ssp_rx_dma_work_flg = FALSE;
    return Retval;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_EraseSector                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function erase spi nor sector.                               */
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
static unsigned int SPINOR_EraseBlock(unsigned int Addr)
{
	unsigned int temp, command;
    unsigned int	Retval = 0;
    volatile int timeout = 0;
    spi_uart_log("%s: 0x%x", __FUNCTION__, Addr);

	timeout = 0xFF;

    do {
		//make sure the device is ready to be written to
		Retval = SPINOR_ReadStatus(TRUE);

		//get device ready to Program
		SPINOR_WriteEnable();

        Retval = SPINOR_WaitForWEL(TRUE);

	} while( ((--timeout) > 0) && (Retval != 0) );

    if(Retval != 0)
    {
    	spi_uart_log_err("%s: not ready to erase", __FUNCTION__);
        return Retval;
    }

	//command  = (unsigned int)(SPI_CMD_BLOCK_ERASE << 24);
	command = SPI_CMD_BLOCK_ERASE;
    command = (command << 24);
    
	command |= Addr & 0xFFFFFF;

    SPINOR_DisableSSP();

	//setup in 32 bit mode
	SPINOR_SSP_DSS(32);

	//fire it up
	SPINOR_FireUpSSP();

	Assert_CS();

	spi_reg_write(SSP_DR, command);

	//wait for TX fifo to empty AND busy signal to go away
	Retval = SPINOR_WaitSSPComplete();

	temp = *SSP_DR;

	Deassert_CS();

	//make sure SSP is disabled
	SPINOR_DisableSSP();

	Retval = SPINOR_ReadStatus(TRUE);

	return Retval;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_EraseSector                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function erase spi nor sector.                               */
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
static unsigned int SPINOR_EraseSector(unsigned int Addr)
{
	unsigned int temp, command;
    unsigned int Retval = 0;
    volatile int timeout = 0;

    //spi_uart_log("%s: 0x%x", __FUNCTION__, Addr);

	timeout = 0xFF;

    do {
		//make sure the device is ready to be written to
		Retval = SPINOR_ReadStatus(TRUE);

		//get device ready to Program
		SPINOR_WriteEnable();

        Retval = SPINOR_WaitForWEL(TRUE);

	} while( ((--timeout) > 0) && (Retval != 0) );

    if(Retval != 0)
    {
    	spi_uart_log_err("%s: not ready to erase", __FUNCTION__);
        return Retval;
    }

	command  = SPI_CMD_SECTOR_ERASE << 24;
	command |= Addr & 0xFFFFFF;

    SPINOR_DisableSSP();

	//setup in 32 bit mode
	SPINOR_SSP_DSS(32);

	//fire it up
	SPINOR_FireUpSSP();

	Assert_CS();

	spi_reg_write(SSP_DR, command);

	//wait for TX fifo to empty AND busy signal to go away
	Retval = SPINOR_WaitSSPComplete();

	temp = *SSP_DR;

	Deassert_CS();

	//make sure SSP is disabled
	SPINOR_DisableSSP();

	Retval = SPINOR_ReadStatus(TRUE);

	return Retval;
}

static unsigned int SPINOR_Page_Program_PIO(unsigned int Address, unsigned int Buffer, unsigned int Size)
{
    unsigned char data[10];
    unsigned int Retval = 0, i = 0;
    unsigned char cmd[4];
	unsigned char *pbuf = (unsigned char *)Buffer;
    int sspport = SPINOR_getSSPPort();
    cmd[0] = SPI_CMD_PROGRAM;
	cmd[1] = (Address >> 16) & 0xFF;
	cmd[2] = (Address >> 8) & 0xFF;
	cmd[3] = (Address >> 0) & 0xFF;


    //fire it up

    Assert_CS();

    if(sspport==0){
        QUEC_SPI_SSP0_PIO_Write(cmd,4);
    }else if(sspport==2){
        QUEC_SPI_SSP2_PIO_Write(cmd,4);
    }

    if(sspport==0){
        QUEC_SPI_SSP0_PIO_Write(pbuf,Size);
    }else if(sspport==2){
        QUEC_SPI_SSP2_PIO_Write(pbuf,Size);
    }


    Deassert_CS();

    //make sure SSP is disabled

	return Retval;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_Wipe                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function do SPI Nor wipe operation.                          */
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
unsigned int SPINOR_Wipe(int sspport)
{
	unsigned int temp;
    unsigned int	Retval = 0;
    volatile int timeout = 0;
#if 0	
	OSA_STATUS	status;

	status = OSASemaphoreAcquire(spiSem, OS_SUSPEND);
	if (status != OS_SUCCESS)
	{
		spi_uart_log_err("%s: ssp not ready", __FUNCTION__);
		return SSPNOTREADY;
	}
#endif	

	SetSSPPort(sspport);

	timeout = 0xFF;

    do {
		//make sure the device is ready to be written to
		Retval = SPINOR_ReadStatus(TRUE);

		//get device ready to Program
		SPINOR_WriteEnable();

        Retval = SPINOR_WaitForWEL(TRUE);

	} while( ((--timeout) > 0) && (Retval != 0) );

    if(Retval != 0)
    {
#if 0		
    	OSASemaphoreRelease(spiSem);
#endif		
        return Retval;
    }

	// sequence for issuing the wipe command (aka chip erase, aka bulk erase)
	//make sure SSP is disabled

	SPINOR_DisableSSP();

	//fire it up
	SPINOR_FireUpSSP();

	Assert_CS();

	// write the command to the fifo. this starts the spi clock running and the command appears on the bus.
	spi_reg_write(SSP_DR, SPI_CMD_CHIP_ERASE);

	//wait for TX fifo to empty AND busy signal to go away
	Retval = SPINOR_WaitSSPComplete();

	temp = *SSP_DR;

    Deassert_CS();

	//make sure SSP is disabled
	SPINOR_DisableSSP();

	Retval = SPINOR_ReadStatus(TRUE);
#if 0
	OSASemaphoreRelease(spiSem);
#endif	

	return Retval;
}

unsigned int SPINOR_Write_PIO(int sspport, unsigned int Address, unsigned int Buffer, unsigned int Size)
{
    volatile int timeout = 0;
	unsigned int Retval = 0, total_size = 0, write_size = 0;
    P_FlashProperties_T pFlashP = GetFlashProperties(sspport);
#if 0	
	OSA_STATUS	status;
#endif
    spi_uart_log("%s: enter", __FUNCTION__);

	if ((Address + Size) > (pFlashP->BlockSize * pFlashP->NumBlocks))
	{
		return FlashAddrOutOfRange;
    }
#if 0
	status = OSASemaphoreAcquire(spiSem, OS_SUSPEND);
	if (status != OS_SUCCESS)
	{
		spi_uart_log_err("%s: ssp not ready", __FUNCTION__);
		return SSPNOTREADY;
	}
#endif
	SetSSPPort(sspport);


	do {

    	timeout = 0xFF;

        do {
    		//make sure the device is ready to be written to
    		Retval = SPINOR_ReadStatus(TRUE);

    		//get device ready to Program
    		SPINOR_WriteEnable();

            Retval = SPINOR_WaitForWEL(TRUE);

    	} while( ((--timeout) > 0) && (Retval != 0) );

        if(Retval != 0)
        {
        	spi_uart_log_err("%s: not ready to write", __FUNCTION__);
            break;
        }

		write_size = Size > WRITE_SIZE ? WRITE_SIZE : Size;

		//write a byte
		if (write_size == WRITE_SIZE)
		{
			Retval = SPINOR_Page_Program_PIO(Address, Buffer, WRITE_SIZE);

			//update counters
			Address+=WRITE_SIZE;
			Buffer+=WRITE_SIZE;
			Size-=WRITE_SIZE;
		}
		else
		{
			Retval = SPINOR_Page_Program_PIO(Address, Buffer, write_size);
			Size=0;
		}

		Retval = SPINOR_ReadStatus(TRUE);

	} while( (Size > 0) && (Retval == 0) );

#if 0
	OSASemaphoreRelease(spiSem);
#endif
    spi_uart_log("%s: leave", __FUNCTION__);

	return Retval;
}


unsigned int SPINOR_Read_PIO(int sspport, unsigned int FlashOffset, unsigned int Buffer, unsigned int Size)
{
    unsigned int  i = 0;
    unsigned char data[10];
    unsigned int Retval = 0;
	unsigned char * pbuf = (unsigned char *)Buffer;
    unsigned char cmd[4];
    P_FlashProperties_T pFlashP = GetFlashProperties(sspport);

	spi_uart_log("%s enter", __FUNCTION__);

	if ((FlashOffset + Size) > (pFlashP->BlockSize * pFlashP->NumBlocks))
	{
	    uart_printf("%s: 0x%x is out of range", __FUNCTION__, FlashOffset);
		return FlashAddrOutOfRange;
    }

	SetSSPPort(sspport);

    cmd[0] = SPI_CMD_READ;
	cmd[1] = (FlashOffset >> 16) & 0xFF;
	cmd[2] = (FlashOffset >> 8) & 0xFF;
	cmd[3] = (FlashOffset >> 0) & 0xFF;
    
    Assert_CS();

    //SPINOR_Write_Read(tx_1bytes, data, 4);
    if(sspport==0){
        QUEC_SPI_SSP0_PIO_Write(cmd,4);
    }else if(sspport==2){
        QUEC_SPI_SSP2_PIO_Write(cmd,4);
    }
    
    if(sspport==0){
        QUEC_SPI_SSP0_PIO_Read(pbuf,Size,0x00);
    }else if(sspport==2){
        QUEC_SPI_SSP2_PIO_Read(pbuf,Size,0x00);
    }

    Deassert_CS();

	SPINOR_DisableSSP();
#if 0
	OSASemaphoreRelease(spiSem);
#endif

	spi_uart_log("%s leave", __FUNCTION__);

    return Retval;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_Erase                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function do SPI Nor erase operation.                         */
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
unsigned int SPINOR_EraseByBlock(int sspport, unsigned int Address, unsigned int Size)
{
	unsigned int num = 0, i = 0;
	unsigned int block_size = 0, Retval = 0;
#if 0	
	OSA_STATUS	status;
#endif	
	P_FlashProperties_T pFlashP = GetFlashProperties(sspport);

    //spi_uart_log("%s, addr:0x%x, size:0x%x", __FUNCTION__, Address, Size);

	if ((Address + Size) > (pFlashP->BlockSize * pFlashP->NumBlocks))
	{
		spi_uart_log_err("%s: erase size is out of range", __FUNCTION__);
		return FlashAddrOutOfRange;
    }

	block_size = pFlashP->BlockSize;

	if ((Size % pFlashP->BlockSize) == 0)
	{
		num = Size / pFlashP->BlockSize;
	}
	else
	{
		num = (Size / pFlashP->BlockSize) + 1;
    }

#if 0
	status = OSASemaphoreAcquire(spiSem, OS_SUSPEND);
	if (status != OS_SUCCESS)
	{
		spi_uart_log_err("%s: ssp not ready", __FUNCTION__);
		return SSPNOTREADY;
	}
#endif	

	SetSSPPort(sspport);

	for (i = 0; i < num; i++)
	{
		//erase this sector
		Retval = SPINOR_EraseBlock(Address);

		Address += block_size;

		if (Retval != 0)
		{
			spi_uart_log_err("%s: eraseblock error", __FUNCTION__);
			break;
		}
	}
#if 0
	OSASemaphoreRelease(spiSem);
#endif
	//spi_uart_log("%s: leave", __FUNCTION__);

	return Retval;
}

unsigned int SPINOR_EraseBySector(int sspport, unsigned int Address, unsigned int Size)
{
	unsigned int num = 0, i = 0;
	unsigned int sector_size = 0, Retval = 0;
#if 0	
	OSA_STATUS	status;
#endif	
	P_FlashProperties_T pFlashP = GetFlashProperties(sspport);

   //spi_uart_log("%s, addr:0x%x, size:0x%x", __FUNCTION__, Address, Size);

	if ((Address + Size) > (pFlashP->BlockSize * pFlashP->NumBlocks))
	{
		spi_uart_log_err("%s: erase size is out of range", __FUNCTION__);
		return FlashAddrOutOfRange;
    }

	sector_size = pFlashP->SectorSize;

	if ((Size % sector_size) == 0)
	{
		num = Size / sector_size;
	}
	else
	{
		num = (Size / sector_size) + 1;
    }
#if 0
	status = OSASemaphoreAcquire(spiSem, OS_SUSPEND);
	if (status != OS_SUCCESS)
	{
		spi_uart_log_err("%s: ssp not ready", __FUNCTION__);
		return SSPNOTREADY;
	}
#endif	

	SetSSPPort(sspport);

	for (i = 0; i < num; i++)
	{
		//erase this sector
		Retval = SPINOR_EraseSector(Address);

		Address += sector_size;

		if (Retval != 0)
		{
			spi_uart_log_err("%s: eraseblock error", __FUNCTION__);
			break;
		}
	}
#if 0
	OSASemaphoreRelease(spiSem);
#endif	

	//spi_uart_log("%s: leave", __FUNCTION__);

	return Retval;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_Wipe                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function do SPI Nor wipe operation.                          */
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
unsigned int SPINOR_Write(int sspport, unsigned int Address, unsigned char * Buffer, unsigned int Size)
{
    volatile int timeout = 0;
#if 0	
	OSA_STATUS	status;
#endif	
	unsigned int Retval = 0, total_size = 0, write_size = 0;
    P_FlashProperties_T pFlashP = GetFlashProperties(sspport);

    //spi_uart_log("%s, Address:0x%x, size:0x%x", __FUNCTION__, Address, Size);

	if ((Address + Size) > (pFlashP->BlockSize * pFlashP->NumBlocks))
	{
		spi_uart_log_err("%s: 0x%x is out of range", __FUNCTION__, Address);
		return FlashAddrOutOfRange;
    }
#if 0
	status = OSASemaphoreAcquire(spiSem, OS_SUSPEND);
	if (status != OS_SUCCESS)
	{
		spi_uart_log_err("%s: ssp not ready", __FUNCTION__);
		return SSPNOTREADY;
	}
#endif
	SetSSPPort(sspport);

	do
	{

    	timeout = 0xFF;

        do
		{
    		//make sure the device is ready to be written to
    		Retval = SPINOR_ReadStatus(TRUE);

    		//get device ready to Program
    		SPINOR_WriteEnable();

            Retval = SPINOR_WaitForWEL(TRUE);

    	} while( ((--timeout) > 0) && (Retval != 0) );

        if(Retval != 0)
        {
        	spi_uart_log_err("%s: not ready to write", __FUNCTION__);
            break;
        }

		write_size = Size > WRITE_SIZE ? WRITE_SIZE : Size;

		Retval = SPINOR_Page_Program_DMA(Address, Buffer, write_size);

		//update counters
		Address += write_size;
		Buffer += write_size;
		Size -= write_size;

		SPINOR_ReadStatus(TRUE);

	} while( Size > 0 && Retval == 0);
#if 0
	OSASemaphoreRelease(spiSem);
#endif
    //spi_uart_log("%s: leave", __FUNCTION__);

	return Retval;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SPINOR_Read                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function do SPI Nor read operation.                          */
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
unsigned int SPINOR_Read(int sspport, unsigned int FlashOffset, unsigned char* Buffer, unsigned int Size)
{
	unsigned int Retval = 0, read_size = 0;
	int count = 0;
#if 0	
	OSA_STATUS	status;
#endif
    //spi_uart_log("%s, Address:0x%x, size:0x%x", __FUNCTION__, FlashOffset, Size);

	P_FlashProperties_T pFlashP = GetFlashProperties(sspport);

	if ((FlashOffset + Size) > (pFlashP->BlockSize * pFlashP->NumBlocks))
	{
	    spi_uart_log_err("%s: 0x%x is out of range", __FUNCTION__, FlashOffset);
		return FlashAddrOutOfRange;
    }
#if 0
	status = OSASemaphoreAcquire(spiSem, OS_SUSPEND);
	if (status != OS_SUCCESS)
	{
		spi_uart_log_err("%s: ssp not ready", __FUNCTION__);
		return SSPNOTREADY;
	}
#endif
	SetSSPPort(sspport);

	do
	{
		read_size = Size > SSP_DMA_READ_SIZE ? SSP_DMA_READ_SIZE : Size;
		Retval = SPINOR_Read_DMA(FlashOffset, Buffer, read_size, read_size);

		if (Retval == 0)
		{
			//update counters
			FlashOffset += read_size;
			Buffer += read_size;
			Size -= read_size;
		}
		else
		{
			spi_uart_log_err("%s: try read again", __FUNCTION__);
			count++;
		}
	} while(Size > 0 && count < 3);
#if 0
	OSASemaphoreRelease(spiSem);
#endif
    //spi_uart_log("%s: leave", __FUNCTION__);
	return Retval;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      InitializeSPIDevice                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function intializes SPI nor device                           */
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
/*      sspport (0,1,2)                                                  */
/*      sspclock:														 */
/*		SSP_CLOCK_13M = 0x0,											 */
/*		SSP_CLOCK_26M = 0x1,											 */
/*		SSP_CLOCK_52M = 0x2,											 */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
int InitializeSPIDevice(int sspport, int sspclock)
{
	unsigned int SPI_FlashID = 0;

	if (sspport < SSP_PORT_0 || sspport > SSP_PORT_2)
	{
		spi_uart_log_err("InitializeSPIDevice,sspport %d not support", sspport);
		return -1;
	}
	
	P_FlashProperties_T pFlashP = GetFlashProperties(sspport);

	//Config ssp clock, ssp pin
	ChipSelectSPI(sspport, (SSP_Clock)sspclock);

	//Have to setup Flash Properties info according to FLASH's datasheet
	//these info will be used in APIs
	pFlashP->BlockSize = 0x10000; // 64KB
	pFlashP->NumBlocks = 0x100;   // 16MB--0x100; 8MB--0x80; 4MB--0x40; 2MB--0x20; 1MB--0x10;
	pFlashP->PageSize  = 0x100;   // 256
	pFlashP->SectorSize = 0x1000; // 4096

#if 0
	if (spiSem == NULL)
		OSASemaphoreCreate(&spiSem, 1, OSA_FIFO);
	else 
		return 0; //already init done once
#endif	

#ifdef SSP_DMA_INTERRUPT    
	ASSERT(OSAFlagCreate(&ssp_tx_dma_done_FlgRef) == OS_SUCCESS);
	ASSERT(OSAFlagCreate(&ssp_rx_dma_done_FlgRef) == OS_SUCCESS);
	dma_irq_callback_register((dma_callback_t)ssp_dma_tx_complete_handler,DMA_DEV_SSP2_TX_CH);
	dma_irq_callback_register((dma_callback_t)ssp_dma_rx_complete_handler,DMA_DEV_SSP2_RX_CH);
#endif

	SPINOR_Reset(sspport);
	SPINOR_ReadId(sspport, &SPI_FlashID);

	//RTI_LOG("InitializeSPIDevice done, sspport %d, clk %d, flash ID 0x%x", sspport, sspclock, SPI_FlashID);
	uart_printf("InitializeSPIDevice done, sspport %d, clk %d, flash ID 0x%x", sspport, sspclock, SPI_FlashID);
	
	return 0;
}

//#define SPI_TEST
#ifdef SPI_TEST
void spi_test_task(void *argv)
{
	int sspport = SSP_PORT_0;
	int size    = 0x1000;
	unsigned int count = 0, err_count = 0, ok_count = 0;
	unsigned char *wbuf = (unsigned char *)malloc(size);
	unsigned char *rbuf = (unsigned char *)malloc(size);
	int i = 0;
	unsigned int address = 0;
	int sectornum = 0;
	
	InitializeSPIDevice(sspport,SSP_CLOCK_26M); //SSP_CLOCK_52M

	for (i = 0; i < size; i++)
		wbuf[i] = i%256;

	P_FlashProperties_T pFlashP = GetFlashProperties(sspport);

	while(1)
	{
		address = sectornum*pFlashP->SectorSize;
		if (address >= (pFlashP->BlockSize * pFlashP->NumBlocks))
		{
			address = 0;
			sectornum = 0;
		}

		memset(rbuf, 0, size);
		SPINOR_EraseBySector(sspport, address, size);
		SPINOR_Write(sspport, address, wbuf, size);
		memset(rbuf,0, size);
		SPINOR_Read(sspport, address, rbuf, size);

		if (memcmp(wbuf, rbuf, size) != 0)
		{
			err_count++;
			CPUartLogPrintf("!!!spi test error, err_count:%d, address:%p", err_count, address);
			ASSERT(0);
		}
		else
		{
			ok_count++;
			CPUartLogPrintf("spi test ok, ok_count:%d, address:%p", ok_count, address);
		}
		count++;
		sectornum++;
		OSATaskSleep(10);
		if((count % 40) == 0)
			RTI_LOG("spi test,total_count:%d,ok_count:%d,err_count:%d,addr:0x%x", count, ok_count, err_count, address);
	}
}

OSTaskRef           spitesttaskref   = NULL;
static void*		spiteststack     = NULL;

int spiflashtest(void)
{
    spiteststack = (void *)malloc(2048);
    OSATaskCreate(&spitesttaskref, spiteststack, 2048, 100, "spitest", spi_test_task, NULL);
	return 0;
}
#endif
