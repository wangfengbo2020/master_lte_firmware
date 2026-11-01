#ifndef __DMA_EXT_H_
#define __DMA_EXT_H_
#include "xllp_dmac.h"



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



typedef unsigned int uint32_t;

#if 1
typedef struct
{
	unsigned int DDADR; //descriptor address reg
	unsigned int DSADR; //source address reg
	unsigned int DTADR; //target address reg
	unsigned int DCMD; //command address register
}QSPI_XLLP_DMAC_DESCRIPTOR_T, *P_QSPI_XLLP_DMAC_DESCRIPTOR_T;



typedef struct
{
	unsigned int DCSR[32];
	unsigned int RESERVED0[0x8];
	unsigned int DALGN;
	unsigned int DPCSR;
	unsigned int RESERVED1[0xE];
	unsigned int DRQSR0;
	unsigned int DRQSR1;
	unsigned int DRQSR2;
	unsigned int RESERVED2[0x1];
	unsigned int DINT;
	unsigned int RESERVED3[0x3];
	unsigned int DRCMR1[64];
	QSPI_XLLP_DMAC_DESCRIPTOR_T DMA_DESC[32];
	unsigned int RESERVED4[0x340];
	unsigned int DRCMR2[36];
}QSPI_XLLP_DMAC_T, *P_QSPI_XLLP_DMAC_T;
#endif



#define CSR_BUSERRINTR              BIT_0
#define CSR_STARTINTR               BIT_1
#define CSR_ENDINTR                 BIT_2
#define CSR_STOPINTR                BIT_3
#define RCMR_MAPVLD                 BIT_7
#define CSR_RECVENDINTR             BIT_9
#define CSR_EORIRQEN                BIT_28
#define CSR_STOPIRQEN               BIT_29
#define CSR_NODESCFETCH             BIT_30
#define CSR_RUN                     BIT_31

#define DMA_DDADR_RESERVED_MASK     0xFFFFFFF0
#define DMA_STATUS_INTERRUPTS_MASK  0x01000217
#define DMA_DEVICE_PART1_NUM        64

#define DMA_SQU_2_SQU_CHANNEL       0
#define DMA_SQU_2_DDR_CHANNEL       1
#define DMA_DDR_2_SQU_CHANNEL       2
#define DMA_DDR_2_DDR_CHANNEL       3
#define DMA_XFER_CHANNEL            4

#define DMA_GEU_W_CHANNEL           5
#define DMA_GEU_R_CHANNEL           6

#define DMA_SQU_ADDR_1              0xD1000000
#define DMA_SQU_ADDR_2              0xD1004000

#define DMA_MDMA_XFER_SIZE	        0xF000
#define DMA_MAX_BYTES_PER_DESC      0x1F00

#define DMA_MDMA_NF_XFER_SIZE       0x1F00

#define DMA_STRESS_XFER_SIZE        0x5000


typedef struct
{
    uint32_t    DDADR;  // descriptor address reg
    uint32_t    DSADR;  // source address register
    uint32_t    DTADR;  // target address register
    uint32_t    DCMD;   // command address register
}DMA_DESCRIPTOR, *P_DMA_DESCRIPTOR;
#if 0
struct DMA_CMD_BITS
{
    uint32_t Length         :13; //Bits [12:0]: Length of transfer in Bytes
    uint32_t Reserved4      :1; //Bit 13: reserved
    uint32_t Width          :2; //Bits [15:14]: Width of onchip peripheral - 0=reserved, 1=1B, 2=2B, 3=4B
    uint32_t MaxBurstSize   :2; //Bits [17:16]: Max Burst Size - 0=reserved, 1=8B, 2=16B, 3=32B
    uint32_t Reserved3      :3; //Bits [20:18]: reserved
    uint32_t EndIRQEn       :1; //Bit 21: end interrupt enable
    uint32_t StartIRQEn     :1; //Bit 22: start interrupt enable
    uint32_t AddrMode       :1; //Bit 23: Addressing mode for descriptor compare - 0=target has addr/1=target has data
    uint32_t Reserved2      :1; //Bit 24: reserved
    uint32_t CmpEn          :1; //Bit 25: Compare Enable - descriptor branching compare enable
    uint32_t Reserved1      :2; //Bits [27:26]: reserved
    uint32_t FlowTrg        :1; //Bit 28: Target flow control - 1=wait for request signal
    uint32_t FlowSrc        :1; //Bit 29: Source flow control - 1=wait for request signal
    uint32_t IncTrgAddr     :1; //Bit 30: Target increment - 0=no increment, 1=increment
    uint32_t IncSrcAddr     :1; //Bit 31: Source increment - 0=no increment, 1=increment
};

typedef union
{
    uint32_t value;
    struct DMA_CMD_BITS bits;
} DMA_CMDx_T, *P_DMA_CMDx_T;
#endif








typedef enum{
	DMA_DEV_SULOG_CH = 0,
	DMA_DEV_UART1_RX_CH = 2,
	DMA_DEV_UART1_TX_CH = 3,
	/* Ported from Quectel Patch.@0104/2021.*/
	//	DMA_DEV_SSP0_TX_CH = 10, //20221104 miles.ma modify
	//	DMA_DEV_SSP0_RX_CH = 11,
	
	DMA_DEV_SSP2Slave_TX_CH = 16,
	DMA_DEV_SSP2Slave_RX_CH = 17,

	#ifdef QUECTEL_PROJECT_CUST
	DMA_DEV_LCD_TX_CH = 28,
	#endif
	DMA_DEV_SSP2_TX_CH = 29,
	DMA_DEV_SSP2_RX_CH = 30,
} DMA_DEVICE_CHANNEL;



typedef struct DMA_STRESS_ARG_TAG{
    uint32_t channel;
    uint32_t num;
    uint32_t size;
    uint32_t stop_flag;
    uint32_t mask;
    uint32_t mask_t;
    uint32_t src[32];
    uint32_t dst[32];
    uint32_t des[32];
}DMA_STRESS_ARG, *P_DMA_STRESS_ARG;

typedef enum{
    DMA_BURST_SIZE_RSVD = 0,
    DMA_BURST_SIZE_8B,
    DMA_BURST_SIZE_16B,
    DMA_BURST_SIZE_32B
}DMA_BURST_SIZE;

typedef enum{
    DMA_MODE_FETCH = 0,
    DMA_MODE_NONFETCH
}DMA_MODE;



typedef enum
{
	DMA_STOP = 0,
	DMA_END
}DMA_WAIT_DONE_FLAG;
typedef int(*dma_callback_t)(uint32_t);

void udelay(unsigned int cnt);
BOOL dma_wakelock(void);
int qspi_dma_init(void);
int dma_irq_callback_register(dma_callback_t func, uint32_t channel);
void dma_stop_irq_en(uint32_t channel);
void dma_map_device_to_channel(DMA_MAP_DEVICE device_id, uint32_t channel);
void set_user_aligment(uint32_t channel);
void dma_set_mode(uint32_t mode, uint32_t channel);
void dma_set_reg_nf(uint32_t src, uint32_t trg, P_DMA_CMDx_T pCMD, uint32_t channel);
void dma_xfer_start(uint32_t channel);
void dma_xfer_start_with_irq_enable(uint32_t channel);
void dma_xfer_stop(uint32_t channel);
uint32_t dma_is_channel_busy(uint32_t channel);

#if 0
#define QSPI_DMA_TX_CHANNEL_X  20
#define  AP_DMA_INT

int test_dma_complete_handler(uint32_t val) {
	uart_printf("irq is comming-------------:%d\n", QSPI_DMA_TX_CHANNEL_X);
	return 0;
}


int qspi_dma_test(void) {
        uart_printf("qspi_dma_test >>>>>>>\n");
#ifdef AP_DMA_INT
        dma_irq_callback_register(test_dma_complete_handler,QSPI_DMA_TX_CHANNEL_X);
#endif

	char *src_addr  = 0xd1080000;
	char* des_addr = 0xd1081000;
	int i;
	int *p =src_addr;
	for(i =0; i<1024; i++){
		*(p+i) = i+1;
	}
	memset(des_addr, 0, 4096);
	uart_printf("qspi_dma_test >>>>>>>1\n");
    	DMA_CMDx_T TX_data;
#if 0
	TX_data.value = 0;
	TX_data.bits.IncSrcAddr = 1;
	TX_data.bits.FlowTrg = 0;
	TX_data.bits.Width = 0;
	TX_data.bits.MaxBurstSize = 1;
	TX_data.bits.Length =1024;
#else
TX_data.value = 0;
TX_data.bits.IncTrgAddr = 1;
TX_data.bits.IncSrcAddr = 1;
TX_data.bits.FlowTrg = 0;
TX_data.bits.Width = 3;
TX_data.bits.MaxBurstSize = 3;
TX_data.bits.Length =1024;
#if 0
TX_data.value = 0;
TX_data.bits.IncSrcAddr = 1;
TX_data.bits.FlowTrg = 1;
TX_data.bits.Width = 3;
TX_data.bits.MaxBurstSize = 3;
TX_data.bits.Length = host->bytes_left;
#endif

#endif
	dma_map_device_to_channel(99, QSPI_DMA_TX_CHANNEL_X); //TX
	/* alignment is handled in qspi, should not set this in DMAC */
	set_user_aligment(QSPI_DMA_TX_CHANNEL_X); //byte align
	uart_printf("qspi_dma_test 6>>>>>>>2\n");

#if 0
       DMA_DESCRIPTOR *tx_desc = 0xd1082000;
	dma_config_descriptor((uint32_t *)tx_desc, 0, (uint32_t)src_addr,
				des_addr, TX_data.value, 1);
	dma_load_descriptor((void *)tx_desc, QSPI_DMA_TX_CHANNEL_X);
#else
	dma_map_device_to_channel(99, QSPI_DMA_TX_CHANNEL_X); //TX
	dma_set_mode(DMA_MODE_NONFETCH, QSPI_DMA_TX_CHANNEL_X);//set simple transfer
	int count =0;
test_again:

	dma_set_reg_nf((uint32_t)src_addr, des_addr, &TX_data,
			QSPI_DMA_TX_CHANNEL_X);
#endif
        uart_printf("qspi_dma_test >>>>>>>3\n");
//	dcache_clean_invalidate_range((uint32_t)cmd->tx_buf, cmd->n_tx);
	dma_xfer_start(QSPI_DMA_TX_CHANNEL_X);
	dma_stop_irq_en(QSPI_DMA_TX_CHANNEL_X);

        uart_printf("start transfer ---------------\n");

        do {
			if (!dma_is_channel_busy(QSPI_DMA_TX_CHANNEL_X)){
				uart_printf("statussss :%x\n", DMA->DCSR[QSPI_DMA_TX_CHANNEL_X] );
				break;
			}
			OSATaskSleep(400);
			uart_printf("status :%x\n", DMA->DCSR[QSPI_DMA_TX_CHANNEL_X] );

	} while (1);

    OSATaskSleep(200);

	p = des_addr;
	int *p2= src_addr;
       for(i = 0; i<258; i++) {
	   	 if (*(p+i)  != (i+1))  {
			uart_printf("i:%d, value:%d origin:%d\n", i, *(p+i), *(p2+i));
	   	 }
       }
    count++;


       uart_printf("end transfer-----------------\n");
    if (count>3)
		return;
	goto test_again;

}
#endif









#endif
