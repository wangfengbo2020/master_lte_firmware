/**
 ******************************************************************************
 * @file    quec_spi.h
 * @author  
 * @version V1.0.0
 * @date    2022-4-6
 * @brief   This file contains the common definitions, macros and functions to
 *          be shared throughout the project.
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2014 QUECTEL Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 */


#ifndef _QUEC_SPI_H
#define _QUEC_SPI_H


typedef unsigned char   UINT8;
typedef void* OSFlagRef;
typedef void* OSSemaRef;
typedef UINT8   OSA_STATUS;


/*Read byte from register*/
#define BU_REG_READ8(x) (*(volatile UINT8 *)(x) & 0xff)
/*Write byte to register*/
#define BU_REG_WRITE8(x,y) ((*(volatile UINT8 *)(x)) = (y & 0xff) )


/* THE BIT DEFINES */
#define BIT_0 (1 << 0)
#define BIT_1 (1 << 1)
#define BIT_2 (1 << 2)
#define BIT_3 (1 << 3)
#define BIT_4 (1 << 4)
#define BIT_5 (1 << 5)
#define BIT_6 (1 << 6)
#define BIT_7 (1 << 7)
#define BIT_8 (1 << 8)
#define BIT_9 (1 << 9)
#define BIT_10 (1 << 10)
#define BIT_11 (1 << 11)
#define BIT_12 (1 << 12)
#define BIT_13 (1 << 13)
#define BIT_14 (1 << 14)
#define BIT_15 (1 << 15)
#define BIT_16 (1 << 16)
#define BIT_17 (1 << 17)
#define BIT_18 (1 << 18)
#define BIT_19 (1 << 19)
#define BIT_20 (1 << 20)
#define BIT_21 (1 << 21)
#define BIT_22 (1 << 22)
#define BIT_23 (1 << 23)
#define BIT_24 (1 << 24)
#define BIT_25 (1 << 25)
#define BIT_26 (1 << 26)
#define BIT_27 (1 << 27)
#define BIT_28 (1 << 28)
#define BIT_29 (1 << 29)
#define BIT_30 (1 << 30)
#define BIT_31 ((unsigned)1 << 31)


#define SHIFT0(Val)  (Val)
#define SHIFT1(Val)  ((Val) << 1)
#define SHIFT2(Val)  ((Val) << 2)
#define SHIFT3(Val)  ((Val) << 3)
#define SHIFT4(Val)  ((Val) << 4)
#define SHIFT5(Val)  ((Val) << 5)
#define SHIFT6(Val)  ((Val) << 6)
#define SHIFT7(Val)  ((Val) << 7)
#define SHIFT8(Val)  ((Val) << 8)
#define SHIFT9(Val)  ((Val) << 9)
#define SHIFT10(Val) ((Val) << 10)
#define SHIFT11(Val) ((Val) << 11)
#define SHIFT12(Val) ((Val) << 12)
#define SHIFT13(Val) ((Val) << 13)
#define SHIFT14(Val) ((Val) << 14)
#define SHIFT15(Val) ((Val) << 15)
#define SHIFT16(Val) ((Val) << 16)
#define SHIFT17(Val) ((Val) << 17)
#define SHIFT18(Val) ((Val) << 18)
#define SHIFT19(Val) ((Val) << 19)
#define SHIFT20(Val) ((Val) << 20)
#define SHIFT21(Val) ((Val) << 21)
#define SHIFT22(Val) ((Val) << 22)
#define SHIFT23(Val) ((Val) << 23)
#define SHIFT24(Val) ((Val) << 24)
#define SHIFT25(Val) ((Val) << 25)
#define SHIFT26(Val) ((Val) << 26)
#define SHIFT27(Val) ((Val) << 27)
#define SHIFT28(Val) ((Val) << 28)
#define SHIFT29(Val) ((Val) << 29)
#define SHIFT30(Val) ((Val) << 30)
#define SHIFT31(Val) ((Val) << 31)


/* Motorola SPI SSPSCLK phase setting */
#define SSP_TCR_SPH				BIT_11
/* Motorola SPI SSPSCLK Polarity Setting */
#define SSP_TCR_SPO				BIT_10

/*SPI MODE*/
#define SSP_SPI_MODE0			0x00
#define SSP_SPI_MODE1			SSP_TCR_SPH
#define SSP_SPI_MODE2			SSP_TCR_SPO
#define SSP_SPI_MODE3			(SSP_TCR_SPO | SSP_TCR_SPH)

#define	APBC_SSP0_CLK_RST  			((volatile UINT32 *)(0xD4015000 + 0x001C)) 
#define APBC_SSP1_CLK_RST       	((volatile UINT32 *)(0xD4015000 + 0x0020)) 
#define APBC_SSP2_CLK_RST       	((volatile UINT32 *)(0xD4015000 + 0x004C)) 

#define	SPI_SSP0_BASE			 	0xD401B000  
#define	SPI_SSP2_BASE			 	0xD401C000
#define	SPI_SSP1_BASE			 	0xD401B800

	
	
#define SSP0_TCR		       		((volatile UINT32 *)(SPI_SSP0_BASE + 0x0000))	/* 32 bit	SSP TOP Control Register 0 */
#define SSP0_FCR		       		((volatile UINT32 *)(SPI_SSP0_BASE + 0x0004))	/* 32 bit	SSP FIFO Control Register 1  */
#define SSP0_IER		       		((volatile UINT32 *)(SPI_SSP0_BASE + 0x0008))	/* 32 bit	SSP Interrupt Enable Register  */
#define SSP0_TOR					((volatile UINT32 *)(SPI_SSP0_BASE + 0x000C))	/* 32 bit	SSP Time Out Register  */
#define SSP0_DR		       			((volatile UINT32 *)(SPI_SSP0_BASE + 0x0010))	/* 32 bit	SSP Data Register */
#define SSP0_SR		       			((volatile UINT32 *)(SPI_SSP0_BASE + 0x0014))	/* 32 bit	SSP Status Register */

#define SSP1_TCR		       		((volatile UINT32 *)(SPI_SSP1_BASE + 0x0000))	/* 32 bit	SSP TOP Control Register 0 */
#define SSP1_FCR		       		((volatile UINT32 *)(SPI_SSP1_BASE + 0x0004))	/* 32 bit	SSP FIFO Control Register 1  */
#define SSP1_IER		       		((volatile UINT32 *)(SPI_SSP1_BASE + 0x0008))	/* 32 bit	SSP Interrupt Enable Register  */
#define SSP1_TOR					((volatile UINT32 *)(SPI_SSP1_BASE + 0x000C))	/* 32 bit	SSP Time Out Register  */
#define SSP1_DR		       			((volatile UINT32 *)(SPI_SSP1_BASE + 0x0010))	/* 32 bit	SSP Data Register */
#define SSP1_SR		       			((volatile UINT32 *)(SPI_SSP1_BASE + 0x0014))	/* 32 bit	SSP Status Register */

	
	
#define SSP2_TCR		       		((volatile UINT32 *)(SPI_SSP2_BASE + 0x0000))	/* 32 bit	SSP TOP Control Register 0 */
#define SSP2_FCR		       		((volatile UINT32 *)(SPI_SSP2_BASE + 0x0004))	/* 32 bit	SSP FIFO Control Register 1  */
#define SSP2_IER		       		((volatile UINT32 *)(SPI_SSP2_BASE + 0x0008))	/* 32 bit	SSP Interrupt Enable Register  */
#define SSP2_TOR					((volatile UINT32 *)(SPI_SSP2_BASE + 0x000C))	/* 32 bit	SSP Time Out Register  */
#define SSP2_DR		       			((volatile UINT32 *)(SPI_SSP2_BASE + 0x0010))	/* 32 bit	SSP Data Register */
#define SSP2_SR		       			((volatile UINT32 *)(SPI_SSP2_BASE + 0x0014))	/* 32 bit	SSP Status Register */


/* Data Size Select */
#define SSP_TCR_DSS_MASK		SHIFT5(0x1f)
#define SSP_TCR_DSS32			SHIFT5(0x1f)
#define SSP_TCR_DSS24			SHIFT5(0x17)
#define SSP_TCR_DSS16			SHIFT5(0xf)
#define SSP_TCR_DSS8			SHIFT5(0x7)




/* SSP Top Control Register */
/* TXD Three-state Enable On Last Phase */
#define SSP_TCR_TTELP			BIT_18

/* TXD Three-State Enable */
#define SSP_TCR_TTE				BIT_17

/* Slave Clock Free Running */
#define SSP_TCR_SCFR			BIT_16

/* Invert Frame Signal */
#define SSP_TCR_IFS				BIT_15

/* Hold Frame Low Control */
#define SSP_TCR_HFL				BIT_14

/* Trailing Byte */
#define SSP_TCR_TRIAL			BIT_13

/* Loopback Mode */
#define SSP_TCR_LBM				BIT_12

/* Motorola SPI SSPSCLK phase setting */
#define SSP_TCR_SPH				BIT_11

/* Motorola SPI SSPSCLK Polarity Setting */
#define SSP_TCR_SPO				BIT_10
/* Synchronous Serial Port Enable */
#define SSP_TCR_SSE				BIT_0



/* SSP Interrupt Enable Register */
/* Transmit FIFO Underrun Interrupt Mask */
#define SSP_IER_TIM				BIT_5

/* Receive FIFO Overrun Interrupt Mask */
#define SSP_IER_RIM				BIT_4

/* Transmit FIFO Interrupt Enable */
#define SSP_IER_TIE				BIT_3

/* Receive FIFO Interrupt Enable */
#define SSP_IER_RIE				BIT_2

/* Receiver Time-out Interrupt Enable */
#define SSP_IER_RTOIE	        BIT_1



/**/
#define SSP0_TCR_INITIAL 	       	(SSP_TCR_TTELP | SSP_TCR_TTE | SSP_TCR_TRIAL | SSP_TCR_DSS8)   // default set data size 8bits
#define SSP0_FCR_INITIAL 	       	(0)
#define SSP0_IER_INITIAL 	       	(SSP_IER_RIM|SSP_IER_TIM)

#define SSP1_TCR_INITIAL 	       	(SSP_TCR_TTELP | SSP_TCR_TTE | SSP_TCR_TRIAL | SSP_TCR_DSS8)   // default set data size 8bits
#define SSP1_FCR_INITIAL 	       	(0)
#define SSP1_IER_INITIAL 	       	(SSP_IER_RIM|SSP_IER_TIM)

#define SSP2_TCR_INITIAL 	       	(SSP_TCR_TTELP | SSP_TCR_TTE | SSP_TCR_TRIAL | SSP_TCR_DSS8)   // default set data size 8bits
#define SSP2_FCR_INITIAL 	       	(0)
#define SSP2_IER_INITIAL 	       	(SSP_IER_RIM|SSP_IER_TIM)

#define spi_reg_read(reg)		*(volatile unsigned int *)(reg)
#define spi_reg_write(reg, val) *(volatile unsigned int *)reg = val; *(volatile unsigned int *)reg;
#define spi_reg_bit_set(reg, val) *(volatile unsigned int *)reg |= val; *(volatile unsigned int *)reg;
#define spi_reg_bit_clr(reg, val) *(volatile unsigned int *)reg &= ~val; *(volatile unsigned int *)reg;



	/* Transmit FIFO Level: BIT 11:7, when it's 0x0, TXFIFO is emptry or full. */
#define SSP_SR_TFL	            0xF80
	
	/* Transmit FIFO Not Full: 0 = TXFIFO is ful, 1 = TXFIFO is not full */
#define	SSP_SR_TF_NF		    (1<<6)
	
	/* SSP Busy: 0 = SSPx port is idle or disabled, 1 = SSPx port is currently transmitting or receiving framed data */
#define	SSP_SR_BSY	            (1<<0)

// Timer out error	code						0x80 - 0x8F
#define SSPWaitTxEmptyTimeOutError			0x80
#define SSPRdStatusTimeOutError		        0x81
#define SSPWelWaitTxEmptyTimeOutError	    0x82
#define SSPWaitForWELTimeOutError		    0x83
#define SSPWaitCompleteTimeOutError         0x84
#define SSPRxChannelTimeOutError            0x85
#define SSPTxChannelTimeOutError            0x86

// return error code
#define NoError            					0x0
#define NotFoundError      					0x1

// SUCCESS 	code	
#define OS_SUCCESS            				0x0

/* Rx FIFO Auto Full Control */
#define SSP_FCR_RAFC                    BIT_17

/* Receive Service Request Enable */
#define SSP_FCR_RSRE			BIT_11

/* Transmit Service Request Enable */
#define SSP_FCR_TSRE			BIT_10

/* RXFIFO Trigger Threshold */
/* MaxBurstSize(DMA)/Data Size Select(SSP) - 1 */
#define SSP_FCR_RFT_MASK		SHIFT5(0x1f)
#define SSP_FCR_RFT(x)			(x << 5)
	
/* TXFIFO Trigger Threshold */
/* MaxBurstSize(DMA)/Data Size Select(SSP) - 1 */
#define SSP_FCR_TFT_MASK		SHIFT0(0x1f)
#define SSP_FCR_TFT(x)			(x << 0)
/* apb_prdata Read from Rx FIFO Endian */
#define SSP_FCR_RRE_MASK		SHIFT12(0x3)
#define SSP_FCR_RRE(x)          (x << 12)

#define SSP0_RX_DMA_DEVICE		        DMAC_SSP_0_RX
#define SSP0_TX_DMA_DEVICE		        DMAC_SSP_0_TX

#define SSP1_RX_DMA_DEVICE		        DMAC_SSP_1_RX
#define SSP1_TX_DMA_DEVICE		        DMAC_SSP_1_TX

	
#define SSP2_RX_DMA_DEVICE		        DMAC_SSP_2_RX
#define SSP2_TX_DMA_DEVICE		        DMAC_SSP_2_TX

#define SSP0_TX_CHANNEL		XLLP_DMAC_CHANNEL_16
#define SSP0_RX_CHANNEL		XLLP_DMAC_CHANNEL_17

#define SSP1_TX_CHANNEL		XLLP_DMAC_CHANNEL_18
#define SSP1_RX_CHANNEL		XLLP_DMAC_CHANNEL_19

#define SSP2_TX_CHANNEL		XLLP_DMAC_CHANNEL_23
#define SSP2_RX_CHANNEL		XLLP_DMAC_CHANNEL_24

#define SSP0_FCR_DMA_READ					(SSP_FCR_RFT(8) | SSP_FCR_TFT(7) | SSP_FCR_RSRE | SSP_FCR_TSRE)
#define SSP0_FCR_DMA_WRITE	        		(SSP_FCR_TFT(6) | SSP_FCR_RSRE | SSP_FCR_TSRE)

#define SSP1_FCR_DMA_READ					(SSP_FCR_RFT(8) | SSP_FCR_TFT(7) | SSP_FCR_RSRE | SSP_FCR_TSRE)
#define SSP1_FCR_DMA_WRITE	        		(SSP_FCR_TFT(6) | SSP_FCR_RSRE | SSP_FCR_TSRE)

	
#define SSP2_FCR_DMA_READ					(SSP_FCR_RFT(8) | SSP_FCR_TFT(7) | SSP_FCR_RSRE | SSP_FCR_TSRE)
#define SSP2_FCR_DMA_WRITE	        		(SSP_FCR_TFT(6) | SSP_FCR_RSRE | SSP_FCR_TSRE)

typedef enum SPI_PORT_ENUM
{
	SPI_PORT_INVALID = -1,
	SPI_PORT0 = 0,	//GPIO16-GPIO19
	SPI_PORT1 = 1,  //GPIO33-GPIO36   
	SPI_PORT2 = 2,	//GPIO4 -GPIO7 spi1
	SPI_PORT_MAX,
}SPI_PORT_T;

typedef enum{
	SPI_MODE0,
	SPI_MODE1,
	SPI_MODE2,
	SPI_MODE3,
	SPI_MODE_MAX,
}SPI_MODE_T;

typedef enum {
	SPI_CLK_100KHZ,
	SPI_CLK_200KHZ,
	SPI_CLK_300KHZ,
	SPI_CLK_400KHZ,
	SPI_CLK_500KHZ,
	SPI_CLK_600KHZ,
	SPI_CLK_700KHZ,
	SPI_CLK_812_5KHZ,
	SPI_CLK_1_625MHZ,
	SPI_CLK_3_25MHZ,
	SPI_CLK_6_5MHZ,
	SPI_CLK_13MHZ,
	SPI_CLK_26MHZ,
	SPI_CLK_52MHZ,
	SPI_CLK_MAX,
}SPI_CLK_T;

typedef enum QUEC_SPI_OpMode_ENUM        /* The Operation Mode that the SPI could work */
{
	QUEC_SPI_OP_PIO=0,              /* PIO mode */
    QUEC_SPI_OP_DMA                 /* DMA mode */
}QUEC_SPI_OpMode;

#define APBC_SSP0_FNCLKSEL_6_5MHZ	(0x00<<4)
#define APBC_SSP0_FNCLKSEL_13MHZ	(0x01<<4)
#define APBC_SSP0_FNCLKSEL_26MHZ	(0x02<<4)
#define APBC_SSP0_FNCLKSEL_52MHZ	(0x03<<4)
#define APBC_SSP0_FNCLKSEL_3_25MHZ	(0x04<<4)
#define APBC_SSP0_FNCLKSEL_1_625MHZ	(0x05<<4)
#define APBC_SSP0_FNCLKSEL_812_5KHZ	(0x06<<4)
#define APBC_SSP0_RST				(1<<2)
#define APBC_SSP0_FNCLK_ENABLE		(1<<1)
#define APBC_SSP0_APBCLK_ENABLE		(1<<0)

#define APBC_SSP1_FNCLKSEL_6_5MHZ	(0x00<<4)
#define APBC_SSP1_FNCLKSEL_13MHZ	(0x01<<4)
#define APBC_SSP1_FNCLKSEL_26MHZ	(0x02<<4)
#define APBC_SSP1_FNCLKSEL_52MHZ	(0x03<<4)
#define APBC_SSP1_FNCLKSEL_3_25MHZ	(0x04<<4)
#define APBC_SSP1_FNCLKSEL_1_625MHZ	(0x05<<4)
#define APBC_SSP1_FNCLKSEL_812_5KHZ	(0x06<<4)
#define APBC_SSP1_RST				(1<<2)
#define APBC_SSP1_FNCLK_ENABLE		(1<<1)
#define APBC_SSP1_APBCLK_ENABLE		(1<<0)	
	
#define APBC_SSP2_FNCLKSEL_6_5MHZ	(0x00<<4)
#define APBC_SSP2_FNCLKSEL_13MHZ	(0x01<<4)
#define APBC_SSP2_FNCLKSEL_26MHZ	(0x02<<4)
#define APBC_SSP2_FNCLKSEL_52MHZ	(0x03<<4)
#define APBC_SSP2_FNCLKSEL_3_25MHZ	(0x04<<4)
#define APBC_SSP2_FNCLKSEL_1_625MHZ	(0x05<<4)
#define APBC_SSP2_FNCLKSEL_812_5KHZ	(0x06<<4)
#define APBC_SSP2_RST				(1<<2)
#define APBC_SSP2_FNCLK_ENABLE		(1<<1)
#define APBC_SSP2_APBCLK_ENABLE		(1<<0)

#define APBC_GPIO_CLK_RST			((volatile UINT32 *)(0xD4015000 + 0x0008))
	
#define APBC_GPIO_RST				(1<<2)
#define APBC_GPIO_FNCLK_ENABLE		(1<<1)
#define APBC_GPIO_APBCLK_ENABLE		(0<<1)

#define	SPI0_CLK			((volatile UINT32 *)(0xD401E000 + 0x11C))		//GPIO16,  /SSP0_CLK, AF2
#define	SPI0_FRM		    ((volatile UINT32 *)(0xD401E000 + 0x120))	    //GPIO17,  /SSP0_FRM, AF2
#define	SPI0_RXD		    ((volatile UINT32 *)(0xD401E000 + 0x124))		//GPIO18,  /SSP0_RX,  AF2
#define	SPI0_TXD		    ((volatile UINT32 *)(0xD401E000 + 0x128))		//GPIO19,  /SSP0_TX,  AF2
#define	SPI1_CLK			((volatile UINT32 *)(0xD401E000 + 0xEC))		//GPIO4,  /SSP0_CLK, AF2
#define	SPI1_FRM		    ((volatile UINT32 *)(0xD401E000 + 0xF0))	    //GPIO5,  /SSP0_FRM, AF2
#define	SPI1_RXD		    ((volatile UINT32 *)(0xD401E000 + 0xF4))		//GPIO6,  /SSP0_RX,  AF2
#define	SPI1_TXD		    ((volatile UINT32 *)(0xD401E000 + 0xF8))		//GPIO7,  /SSP0_TX,  AF2

	
#define	SPI2_CLK			((volatile UINT32 *)(0xD401E000 + 0x160))		//GPIO33, 0xD401_E160 /SSP2_CLK, AF2
#define	SPI2_FRM		    ((volatile UINT32 *)(0xD401E000 + 0x164))	    //GPIO34, 0xD401_E164 /SSP2_FRM, AF2
#define	SPI2_RXD		    ((volatile UINT32 *)(0xD401E000 + 0x168))		//GPIO35, 0xD401_E168 /SSP2_RX,  AF2
#define	SPI2_TXD		    ((volatile UINT32 *)(0xD401E000 + 0x16C))		//GPIO36, 0xD401_E16C /SSP2_TX,  AF2

#define SSP_SR_TX_FIFO_NOT_FULL		(1<<6)
#define SSP_SR_RX_FIFO_NOT_EMPTY	(1<<14)

int quec_spi_init(SPI_PORT_T port, SPI_MODE_T spimode, SPI_CLK_T spiclk);
int quec_spi_write(SPI_PORT_T port, unsigned char *buf, unsigned int len);
int quec_spi_read(SPI_PORT_T port, unsigned char *buf, unsigned int len);
int quec_spi_write_read(SPI_PORT_T port, unsigned char *inbuf, unsigned char *outbuf, unsigned int len);


void SPI_SSP0_Initialize(SPI_MODE_T spimode, SPI_CLK_T spiclk);
void SPI_SSP1_Initialize(SPI_MODE_T spimode, SPI_CLK_T spiclk);
void SPI_SSP2_Initialize(SPI_MODE_T spimode, SPI_CLK_T spiclk);
UINT32 QUEC_SPI_SSP0_DataTransfer(unsigned char *inbuf, unsigned char *outbuf, unsigned int len);
UINT32 QUEC_SPI_SSP1_DataTransfer(unsigned char *inbuf, unsigned char *outbuf, unsigned int len);
UINT32 QUEC_SPI_SSP2_DataTransfer(unsigned char *inbuf, unsigned char *outbuf, unsigned int len);
UINT32 QUEC_SPI_SSP0_DMA_WriteData(unsigned char *buf, unsigned int len);
UINT32 QUEC_SPI_SSP1_DMA_WriteData(unsigned char *buf, unsigned int len);
UINT32 QUEC_SPI_SSP2_DMA_WriteData(unsigned char *buf, unsigned int len);
UINT32 QUEC_SPI_SSP0_DMA_ReadData(unsigned char *buf, unsigned int len);
UINT32 QUEC_SPI_SSP1_DMA_ReadData(unsigned char *buf, unsigned int len);
UINT32 QUEC_SPI_SSP2_DMA_ReadData(unsigned char *buf, unsigned int len);

void QUEC_SPI_SSP0_PIO_transfer(unsigned char *buf_in,unsigned char *buf_out, unsigned int len);
void QUEC_SPI_SSP1_PIO_transfer(unsigned char *buf_in,unsigned char *buf_out, unsigned int len);
void QUEC_SPI_SSP2_PIO_transfer(unsigned char *buf_in,unsigned char *buf_out, unsigned int len);
void QUEC_SPI_SSP0_PIO_Write(unsigned char *buf, unsigned int len);
void QUEC_SPI_SSP1_PIO_Write(unsigned char *buf, unsigned int len);
void QUEC_SPI_SSP2_PIO_Write(unsigned char *buf, unsigned int len);
void QUEC_SPI_SSP0_PIO_Read(unsigned char *buf, unsigned int len, unsigned char mosi_status);
void QUEC_SPI_SSP1_PIO_Read(unsigned char *buf, unsigned int len, unsigned char mosi_status);
void QUEC_SPI_SSP2_PIO_Read(unsigned char *buf, unsigned int len, unsigned char mosi_status);


#endif


