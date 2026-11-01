

#ifndef	__INC_TWSI_H
#define	__INC_TWSI_H

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


#define	TWSI0_BASE	0xD4011000
#define	TWSI1_BASE	0xD4010800
#define	TWSI2_BASE	0xD403e000
#define	TWSI3_BASE	0xD4037000


#define	TWSI_ICR		(0x0010)	/* 32 bit	TWSI TWSI Control Register */
#define	TWSI_ISR		(0x0018)	/* 32 bit	TWSI TWSI Status Register */
#define	TWSI_ISAR		(0x0020)	/* 32 bit	TWSI TWSI Slave Address Register */
#define	TWSI_IDBR		(0x0008)	/* 32 bit	TWSI TWSI Data Buffer Register */
#define	TWSI_ILCR		(0x0028)	/* 32 bit	TWSI TWSI Load Count Register */
#define	TWSI_IWCR		(0x0030)	/* 32 bit	TWSI TWSI Wait Count Register */
#define	TWSI_RST_CYC	(0x0060)	/* 32 bit	TWSI The TWSI  bus reset cycle counter defines the tcycles of SCL during bus reset */
#define	TWSI_IBMR		(0x0000)	/* 32 bit	TWSI TWSI Bus Monitor Register */
#define	TWSI_WFIFO		(0x0040)	/* 32 bit	TWSI TWSI Write FIFO Register */
#define	TWSI_WFIFO_WPTR	(0x0044)	/* 32 bit	TWSI TWSI Write FIFO Write Pointer Register */
#define	TWSI_WFIFO_RPTR	(0x0048)	/* 32 bit	TWSI TWSI Write FIFO Read Pointer Register */
#define	TWSI_RFIFO		(0x0050)	/* 32 bit	TWSI TWSI Read FIFO Register */
#define	TWSI_RFIFO_WPTR	(0x0054)	/* 32 bit	TWSI TWSI Read FIFO Write Pointer Register */
#define	TWSI_RFIFO_RPTR	(0x0058)	/* 32 bit	TWSI TWSI Read FIFO Read Pointer Register */

/*	TWSI_IBMR		0x0000	TWSI TWSI Bus Monitor Register */
#define	TWSI_IBMR_SCL		BIT_1	/* SCL */
#define	TWSI_IBMR_SDA		BIT_0	/* SDA */

/*	TWSI_IDBR		0x0008	TWSI TWSI Data Buffer Register */
#define	TWSI_IDBR_DATA_BUFFER_MSK		MASK_(0,8)	/* Data Buffer */
#define	TWSI_IDBR_DATA_BUFFER_BASE		0


/*	TWSI_ICR		0x0010	TWSI TWSI Control Register */
#define	TWSI_ICR_BUS_RESET			BIT_28			/*The twsi will do bus reset upon this bit set.this bit is self-cleared  */
#define	TWSI_ICR_DMA_EN				BIT_27			/* DMA Enable for both TX and RX FIFOs */
#define	TWSI_ICR_RXOV_IE			BIT_26			/* Receive FIFO overrun Interrupt Enable */
#define	TWSI_ICR_RXF_IE				BIT_25			/* Receive FIFO full Interrupt Enable */
#define	TWSI_ICR_TXE_IE				BIT_24			/* Transmit FIFO Empty Interrupt Enable */
#define	TWSI_ICR_RXHF_IE			BIT_23			/* Receive FIFO Half Full Interrupt Enable */
#define	TWSI_ICR_TXDONE_IE			BIT_22			/* Transaction Done Interrupt Enable */
#define	TWSI_ICR_TXBEGIN			BIT_21			/* Transaction Begin */
#define	TWSI_ICR_FIFOEN				BIT_20			/* FIFO mode */
#define	TWSI_ICR_GPIOEN				BIT_19			/* GPIO mode Enable for SCL during HS mode */
#define	TWSI_ICR_MSDE				BIT_18			/* Master Stop Detected Enable */
#define	TWSI_ICR_MSDIE				BIT_17			/* Master Stop Detected Interrupt Enable */
#define	TWSI_ICR_MODE_MSK			MASK_(15,2)		/* Bus Mode (Master operation) */
#define	TWSI_ICR_MODE_BASE			15
#define	TWSI_ICR_UR					BIT_14			/* Unit Reset */
#define	TWSI_ICR_SADIE				BIT_13			/* Slave Address Detected Interrupt Enable */
#define	TWSI_ICR_ALDIE				BIT_12			/* Arbitration Loss Detected Interrupt Enable */
#define	TWSI_ICR_SSDIE				BIT_11			/* Slave Stop Detected Interrupt Enable */
#define	TWSI_ICR_BEIE				BIT_10			/* Bus Error Interrupt Enable */
#define	TWSI_ICR_DRFIE				BIT_9			/* DBR Receive Full Interrupt Enable */
#define	TWSI_ICR_ITEIE				BIT_8			/* IDBR Transmit Empty Interrupt Enable */
#define	TWSI_ICR_GCD				BIT_7			/* General Call Disable */
#define	TWSI_ICR_IUE				BIT_6			/* TWSI Unit Enable */
#define	TWSI_ICR_SCLE				BIT_5			/* SCL Enable */
#define	TWSI_ICR_MA					BIT_4			/* Master Abort */
#define	TWSI_ICR_TB					BIT_3			/* Transfer Byte */
#define	TWSI_ICR_ACKNAK				BIT_2			/* The positive/negative acknowledge control bit */
#define	TWSI_ICR_STOP				BIT_1			/* Stop */
#define	TWSI_ICR_START				BIT_0			/* Start */

/*	TWSI_ISR		0x0018	TWSI TWSI Status Register */
#define	TWSI_ISR_RXOV		BIT_17	/* Receive FIFO Overrun (FIFO mode) */
#define	TWSI_ISR_RXF		BIT_16	/* Receive FIFO Full (FIFO mode) */
#define	TWSI_ISR_TXE		BIT_15	/* Transmit FIFO Empty(FIFO mode) */
#define	TWSI_ISR_RXHF		BIT_14	/* Receive FIFO Half Full  (FIFO mode) */
#define	TWSI_ISR_TXDONE		BIT_13	/* Transaction Done (FIFO mode) */
#define	TWSI_ISR_MSD		BIT_12	/* Master Stop Detected */
#define	TWSI_ISR_EBB		BIT_11	/* Early Bus Busy */
#define	TWSI_ISR_BED		BIT_10	/* Bus Error Detected */
#define	TWSI_ISR_SAD		BIT_9	/* Slave Address Detected */
#define	TWSI_ISR_GCAD		BIT_8	/* General Call Address Detected */
#define	TWSI_ISR_IRF		BIT_7	/* IDBR Receive Full */
#define	TWSI_ISR_ITE		BIT_6	/* IDBR Transmit Empty */
#define	TWSI_ISR_ALD		BIT_5	/* Arbitration Loss Detected */
#define	TWSI_ISR_SSD		BIT_4	/* Slave Stop Detected */
#define	TWSI_ISR_IBB		BIT_3	/* TWSI Bus Busy */
#define	TWSI_ISR_UB			BIT_2	/* Unit Busy */
#define	TWSI_ISR_ACKNAK		BIT_1	/* ACK/NACK Status */
#define	TWSI_ISR_RWM		BIT_0	/* Read/write Mode */



/*	TWSI_ISAR		0x0020	TWSI TWSI Slave Address Register */
#define	TWSI_ISAR_SLAVE_ADDRESS_MSK			MASK_(0,7)	/* Slave Address */
#define	TWSI_ISAR_SLAVE_ADDRESS_BASE		0

/*	TWSI_ILCR		0x0028	TWSI TWSI Load Count Register */
#define	TWSI_ILCR_HLVL_MSK		MASK_(27,5)	/* HLVL */
#define	TWSI_ILCR_HLVL_BASE		27
#define	TWSI_ILCR_HLVH_MSK		MASK_(18,9)		/* HLVH */
#define	TWSI_ILCR_HLVH_BASE		18
#define	TWSI_ILCR_FLV_MSK		MASK_(9,9)	/* FLV */
#define	TWSI_ILCR_FLV_BASE		9
#define	TWSI_ILCR_SLV_MSK		MASK_(0,9)	/* SLV */
#define	TWSI_ILCR_SLV_BASE		0

/*	TWSI_IWCR		0x0030	TWSI TWSI Wait Count Register */
#define	TWSI_IWCR_HS_COUNT2_MSK			MASK_(10,5)	/* HS_COUNT2 */
#define	TWSI_IWCR_HS_COUNT2_BASE		10
#define	TWSI_IWCR_HS_COUNT1_MSK			MASK_(5,5)	/* HS_COUNT1 */
#define	TWSI_IWCR_HS_COUNT1_BASE		5
#define	TWSI_IWCR_COUNT_MSK				MASK_(0,5)	/* COUNT */
#define	TWSI_IWCR_COUNT_BASE			0

/*	TWSI_WFIFO		0x0040	TWSI TWSI Write FIFO Register */
#define	TWSI_WFIFO_CONTROL_MSK		MASK_(8,4)		/* Control */
#define	TWSI_WFIFO_CONTROL_BASE		8
#define	TWSI_WFIFO_DATA_MSK			MASK_(0,8)	/* Data */
#define	TWSI_WFIFO_DATA_BASE		0

/*	TWSI_WFIFO_WPTR	0x0044	TWSI TWSI Write FIFO Write Pointer Register */
#define	TWSI_WFIFO_WPTR_DATA_MSK		MASK_(0,5)	/* Data */
#define	TWSI_WFIFO_WPTR_DATA_BASE		0

/*	TWSI_WFIFO_RPTR	0x0048	TWSI TWSI Write FIFO Read Pointer Register */
#define	TWSI_WFIFO_RPTR_DATA_MSK		MASK_(0,5)	/* Data */
#define	TWSI_WFIFO_RPTR_DATA_BASE		0

/*	TWSI_RFIFO		0x0050	TWSI TWSI Read FIFO Register */
#define	TWSI_RFIFO_DATA_MSK			MASK_(0,8)	/* Data */
#define	TWSI_RFIFO_DATA_BASE		0

/*	TWSI_RFIFO_WPTR	0x0054	TWSI TWSI Read FIFO Write Pointer Register */
#define	TWSI_RFIFO_WPTR_DATA_MSK		MASK_(0,5)	/* Data */
#define	TWSI_RFIFO_WPTR_DATA_BASE		0

/*	TWSI_RFIFO_RPTR	0x0058	TWSI TWSI Read FIFO Read Pointer Register */
#define	TWSI_RFIFO_RPTR_DATA_MSK		MASK_(0,5)	/* Data */
#define	TWSI_RFIFO_RPTR_DATA_BASE		0

/*	TWSI_RST_CYC	0x0060	TWSI TWSI Bus reset cycle counter Register */
#define	TWSI_RST_CYC_MSK		MASK_(0,4)	/* The cycles of SCL during bus reset */
#define	TWSI_RST_CYC_BASE		0


#endif	/* __INC_TWSI_H */
