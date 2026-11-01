#include "spi_drv.h"
#include "quec_rtos.h"
#include "qspi_dma.h"
#include "lcd_log.h"
#include "cgpio.h"
#include "panel_drv.h"

#define TX_FIFO_INT_EN             (0x1<<3)   //SSP_INT_EN[3]
#define RX_FIFO_INT_EN             (0x1<<2)   //SSP_INT_EN[2]
#define TIMEOUT_EN                 (0x1<<1)   //SSP_INT_EN[1]
#define PERI_TRAIL_EN              (0x1<<0)   //SSP_INT_EN[0]
#define SSPSFRM_M                  (0x0<<4)   //SSP_TOP_CTRL[4]
#define SSPSCLK_M                  (0x0<<3)   //SSP_TOP_CTRL[3]
#define FRF_SPI                    (0x0<<1)   //SSP_TOP_CTRL[2:1]
#define SSP_FORMAT        FRF_SPI
#define RX_AUTO_FULL_CTRL_EN       (0x1<<17)  //SSP_FIFO_CTRL[17]
#define FIFO_UNPACKING             (0x0<<16)  //SSP_FIFO_CTRL[16]
#define RX_THRES_7                 (0x7<<5)   //SSP_FIFO_CTRL[9:5]
#define TX_THRES_7                 (0x7<<0)   //SSP_FIFO_CTRL[4:0]
#define SSE_EN                     (0x1<<0)   //SSP_TOP_CTRL[0]


#define SSP0_BASE_ADDRESS			0xD401B000
#define APB_SSP0_CLK_RST            0xd401501c
#define SSP2_BASE_ADDRESS           0xD401C000 
#define APB_SSP2_CLK_RST            0xd401504c

#define LCD_BASE_ADDR               SSP0_BASE_ADDRESS

#define DW_9BITS (0x8 << 5)
#define SSP_DATAR                0x10 
#define SSP__STATUS               0x14
#define DMA_BASE_ADDRESS   0xD4000000
#define REG32(x)	*((volatile unsigned long*)(x))

#define SSP_TX_DMA_DESC   0x20    /*dma描述符个数，个数越多传输数据量越大*/


__align(32) UINT8 SPI_TX_DESCRIPTO[SSP_TX_DMA_DESC*sizeof(DMA_DESCRIPTOR)]={0};

static OS_HISR  spi_dma_hisr_ref;

volatile P_QSPI_XLLP_DMAC_T DMA_ADDR=(P_QSPI_XLLP_DMAC_T)(volatile unsigned int*)0xd4000000;

volatile unsigned int dma_tx_complete = 0;

unsigned int send_flag_error = 0;

struct s_spi_ctx g_spi_ctx;
quec_flag_t g_lcd_interrupt_flag;

extern void dma_load_descriptor(P_DMA_DESCRIPTOR p_desc, uint32_t channel);

struct s_spi_ctx* spi_get_interface(void)
{
    return &g_spi_ctx;
}

//atomic operation to fill single descriptor.
static void _dma_config_desc(P_DMA_DESCRIPTOR p_des, 
							 P_DMA_DESCRIPTOR p_next_des, 
							 unsigned int stop, 
							 unsigned int branch_mode, 
							 unsigned int src, 
							 unsigned int trg, 
							 P_DMA_CMDx_T pCMD)
{
	unsigned int next_des_addr = (unsigned int)p_next_des;
	if(!stop){
		//clear the reserved bits.
		next_des_addr = next_des_addr & DMA_DDADR_RESERVED_MASK;
	}else{
		next_des_addr = 0;
	}

	next_des_addr |= ( (stop & 0x1) | ( (branch_mode&0x1) << 1) );

	//fill the descriptor entries.
	p_des->DDADR = (unsigned int)next_des_addr;
	p_des->DSADR = (unsigned int)src;
	p_des->DTADR = (unsigned int)trg;
	p_des->DCMD = (unsigned int)pCMD->value;

	return;
}

/**
 * Configure the descriptor entries.
 * p_des should be malloc ahead and the malloc size can be got by dma_get_des_num().
 * Descriptor, source and target address should align.
 */
void spi_dma_config_desc(P_DMA_DESCRIPTOR p_des,P_DMA_CMDx_T pCMD,unsigned int src, unsigned int trg,unsigned int bytes_len)
{
    unsigned int bytes_step = (unsigned int)pCMD->bits.Length;
	unsigned int des_num = bytes_len / bytes_step;
	unsigned int bytes_tail = bytes_len % bytes_step;

	unsigned int i = 0;
	unsigned int p_cur_des;
	unsigned int p_next_des = 0;


    if(bytes_tail != 0){
        des_num++;
    }else{
        bytes_tail = bytes_step;
    }
    p_cur_des= (unsigned int)p_des;

    for(i=0; i<des_num-1; i++){
        p_cur_des = (unsigned int)p_des + i*sizeof(DMA_DESCRIPTOR);
        p_next_des = (unsigned int)p_des + (i+1)*sizeof(DMA_DESCRIPTOR);
        _dma_config_desc((P_DMA_DESCRIPTOR)p_cur_des, (P_DMA_DESCRIPTOR)p_next_des, 0, 0, src, trg, pCMD);

        // For some cases, such as ssp fifo. FIFO address should set src_inc but the address may not increase.
        if(pCMD->bits.IncSrcAddr)
            src = src + pCMD->bits.Length;
        if(pCMD->bits.IncTrgAddr) 
            trg = trg + pCMD->bits.Length;
    }

    //handle the tail bytes.
    p_cur_des = (unsigned int)p_des + (des_num-1)*sizeof(DMA_DESCRIPTOR);
    p_next_des = (unsigned int)p_des + des_num*sizeof(DMA_DESCRIPTOR);
    pCMD->bits.Length = bytes_tail;
    _dma_config_desc((P_DMA_DESCRIPTOR)p_cur_des, (P_DMA_DESCRIPTOR)p_next_des, 1, 0, src, trg, pCMD);

    if(des_num>1)
    pCMD->bits.Length = bytes_step;//reset the pCMD.

    return;
}

void spi_dma_tx_hisr(void) 
{
    int ret;
        ret = quec_rtos_flag_release(g_lcd_interrupt_flag, SPI_INTER_FLAG_FRAMEDONE, QUEC_FLAG_OR);
        if (ret != 0) {
            send_flag_error++;
        }
}

void ClearDmaInterrupt( unsigned int channel )
{
    DMA_ADDR->DCSR[channel] &= ~CSR_STOPIRQEN;
}

int spi_dma_tx_complete_handler(unsigned int val) 
{
    struct s_spi_ctx* spi_ctx=spi_get_interface();
    switch(spi_ctx->info.device_id)
    {
        case SPI_CONETROLER_1:
            if(DMA_ADDR->DCSR[DMA_DEV_LCD_TX_CH] & CSR_STOPINTR)
            {
                OS_Activate_HISR(&spi_dma_hisr_ref);
                ClearDmaInterrupt(DMA_DEV_LCD_TX_CH);
            }
        break;
            
        case SPI_CONETROLER_0:
            if(DMA_ADDR->DCSR[DMA_DEV_LCD_TX_CH] & CSR_STOPINTR)
            {
                OS_Activate_HISR(&spi_dma_hisr_ref);
                ClearDmaInterrupt(DMA_DEV_LCD_TX_CH);
            }
        break;
            
        default:
             LCDLOGE("!!!"); 
        break;
    }
    return 0;
}


void spi_dma_init(void)
{
    struct s_spi_ctx* spi_ctx=spi_get_interface();
    switch(spi_ctx->info.device_id)
    {
        case SPI_CONETROLER_1:
            OS_Create_HISR(&spi_dma_hisr_ref, "tx_ssp2_dma_hisr", spi_dma_tx_hisr, HISR_PRIORITY_2);
            dma_irq_callback_register(spi_dma_tx_complete_handler, DMA_DEV_LCD_TX_CH);
            dma_map_device_to_channel(DMA_REQ_SSP2_TX, DMA_DEV_LCD_TX_CH);
            set_user_aligment(DMA_DEV_LCD_TX_CH);  // 1 = user aligned (source and target addresses)
        break;
        
        case SPI_CONETROLER_0:
            OS_Create_HISR(&spi_dma_hisr_ref, "tx_ssp0_dma_hisr", spi_dma_tx_hisr, HISR_PRIORITY_2);
            dma_irq_callback_register(spi_dma_tx_complete_handler, DMA_DEV_LCD_TX_CH);
            dma_map_device_to_channel(DMA_REQ_SSP0_TX, DMA_DEV_LCD_TX_CH);
            set_user_aligment(DMA_DEV_LCD_TX_CH);  // 1 = user aligned (source and target addresses)
        break;
        
        default:
            LCDLOGE("dma init failed");  
        break;

    }
    quec_rtos_flag_create(&g_lcd_interrupt_flag);
}

/*************************************************************************
       RFT:    RXFIFO Trigger Threshold (bit 13:10)
       TFT:    TXFIFO Trigger Threshold (bit 9:6)

       TFT = RFT -1
       DMA burst size <= DMA Width * RFT (in unpack mode of SSP FIFO)
       =========================================================
       DMA Width    |    DMA burst size       |   RFT   |   TFT
       -----------+------------------+------+-------
       2 Bytes         |       16 Bytes            |   8       |   7
       -----------+------------------+------+-------
       4 Bytes         |       16  Bytes           |   4       |   3
       -----------+------------------+------+-------
       4 Byets         |       32 Byets            |   8       |   7
       =========================================================
*************************************************************************/

void spi_dma_transfer_request(spidir dir, uint16 *buf, unsigned int size)
{
    DMA_CMDx_T cmd;
    DMA_DESCRIPTOR* TX_Desc = NULL;
    struct s_spi_ctx* spi_ctx=spi_get_interface();
    
    if(dir == spi_rx){//rx对于lcd这部分没用
        cmd.value = 0;
        cmd.bits.IncSrcAddr = 0; //Always use SSP_DR
        cmd.bits.IncTrgAddr = 1; //Increase in SPI_RXBuffer[]
        cmd.bits.FlowTrg = 0; //Target(SPI_RXBuffer) is memory, not need flow control
        cmd.bits.FlowSrc = 1; //Source(SSP_DR) is on-chip peripheral, need flow control
        cmd.bits.Width = 2;
        cmd.bits.MaxBurstSize = 2;
        cmd.bits.Length = size * sizeof(short);
       
        // dma_set_reg_nf((unsigned int)(SSP0_BASE_ADDRESS + SSP_DATAR), (unsigned int)buf, &cmd,DMA_DEV_SSP0_RX_CH);
        // dma_xfer_start(DMA_DEV_SSP0_RX_CH);
        // dma_stop_irq_en(DMA_DEV_SSP0_RX_CH);
    }
    else{
        cmd.value = 0;
        cmd.bits.IncSrcAddr = 1;//Increase in SPI_TXBuffer[] memory
        cmd.bits.IncTrgAddr = 0; //Always use SSP_DR
        cmd.bits.FlowTrg = 1;   //Target(SSP_DR) is on-chip peripheral, need flow control
        cmd.bits.FlowSrc = 0;  //Source(SPI_TXBuffer) is memory, not need flow control
        cmd.bits.Width = 2; //Width of onchip peripheral - 0=reserved, 1=1B, 2=2B, 3=4B
        cmd.bits.MaxBurstSize = 2; //Max Burst Size - 0=reserved, 1=8B, 2=16B, 3=32B
        cmd.bits.Length = (size > 8191) ? (7936):size;
        cmd.bits.EndIRQEn = 1;       //Enable End Interrupt

        TX_Desc = (DMA_DESCRIPTOR*)(SPI_TX_DESCRIPTO);
        switch(spi_ctx->info.device_id)
        {
            case SPI_CONETROLER_1:
            spi_dma_config_desc(TX_Desc, &cmd, (unsigned int)buf, (unsigned int)(SSP2_BASE_ADDRESS + SSP_DATAR), size);
            dma_set_reg_nf((unsigned int)buf, (unsigned int)(SSP2_BASE_ADDRESS + SSP_DATAR), &cmd,DMA_DEV_LCD_TX_CH);
            dma_load_descriptor(&TX_Desc[0], DMA_DEV_LCD_TX_CH);
            CacheCleanMemory((void *) TX_Desc, SSP_TX_DMA_DESC * sizeof(DMA_DESCRIPTOR));
            dma_stop_irq_en(DMA_DEV_LCD_TX_CH);
            dma_xfer_start(DMA_DEV_LCD_TX_CH);
            break;
            
            case SPI_CONETROLER_0:
            spi_dma_config_desc(TX_Desc, &cmd, (unsigned int)buf, (unsigned int)(SSP0_BASE_ADDRESS + SSP_DATAR), size);
            dma_set_reg_nf((unsigned int)buf, (unsigned int)(SSP0_BASE_ADDRESS + SSP_DATAR), &cmd,DMA_DEV_LCD_TX_CH);
            dma_load_descriptor(&TX_Desc[0], DMA_DEV_LCD_TX_CH);
            CacheCleanMemory((void *) TX_Desc, SSP_TX_DMA_DESC * sizeof(DMA_DESCRIPTOR));
            dma_stop_irq_en(DMA_DEV_LCD_TX_CH);
            dma_xfer_start(DMA_DEV_LCD_TX_CH);
            break;
            
            default:
                LCDLOGE("dma enable failed");  
            break;
        }
        //raw_uart_log("--------config dma----------\r\n");
}

	return;
}
extern void spi_dump(void);

void spi_write_data_dma(unsigned short* data,unsigned int sum_pixel,unsigned int data_bits,unsigned short line_num)
{
    int i,ret;
    unsigned int actual_flags = 0;
    struct s_spi_ctx* spi_ctx=spi_get_interface();
    
    if((data_bits <1) || (data_bits >31))
        return;
    switch (spi_ctx->info.device_id)
    {
        case SPI_CONETROLER_1:
         REG32(SSP2_BASE_ADDRESS) = 0x261e0; // disable spi
         REG32(SSP2_BASE_ADDRESS + 0x4) = 0x20d07;
         REG32(SSP2_BASE_ADDRESS) = 0x261e1; // enable spi start trancemit
         break;
     
        case SPI_CONETROLER_0:
         REG32(SSP0_BASE_ADDRESS) = 0x261e0; // disable spi
         REG32(SSP0_BASE_ADDRESS + 0x4) = 0x20d07;
         REG32(SSP0_BASE_ADDRESS) = 0x261e1; // enable spi start trancemit
         break;
         
        default:
            LCDLOGE("spi enable failed"); 
        break;
    }
	//2023410 add在每次spi dma数据传输请求前清除DMA中断标志
     quec_rtos_flag_release(g_lcd_interrupt_flag,0,OSA_FLAG_AND);
     spi_dma_transfer_request(spi_tx,data,sum_pixel);
    //spi_dump();
    i = 0;
    while(i < 10) {
    ret = quec_rtos_flag_wait(g_lcd_interrupt_flag, SPI_INTER_FLAG_FRAMEDONE, QUEC_FLAG_OR_CLEAR,
        &actual_flags, 20);
        if ((ret == OS_SUCCESS) && (0 != (actual_flags & SPI_INTER_FLAG_FRAMEDONE))){
            dma_tx_complete = 0;
            break;
        }else{
            LCDLOGE("####wait to finish (0x%x)(%d)!\n", actual_flags, i);
        }
        i++;
    }
    if(i>= 10 && (0 == (actual_flags & SPI_INTER_FLAG_FRAMEDONE))){
        LCDLOGE("got dma done timeout!");
	}
}

void spi_dump(void)
{
	unsigned int i = 0;
	for(i=0;i<12;i++)
	{
		LCDLOGI("--------SPI0a start dump----------\r\n");
		LCDLOGI("SPI0a offset: 0x%x, value:0x%lx\r\n",i*4, REG32(SSP0_BASE_ADDRESS + i*4));
	}
	LCDLOGI("SPI0a offset: 0x54, value:0x%lx\r\n", REG32(SSP0_BASE_ADDRESS + 0x54));
	LCDLOGI("--------SPI0 start dump end----------\r\n");
    LCDLOGI("--------dmareg CSR031(DCSR)----------0x%x\r\n",REG32(DMA_BASE_ADDRESS + 4*DMA_DEV_LCD_TX_CH));
    LCDLOGI("--------dmareg ALGN----------0x%x\r\n",REG32(DMA_BASE_ADDRESS + 0xa0));
    LCDLOGI("--------dmareg INT----------0x%x\r\n",REG32(DMA_BASE_ADDRESS + 0xf0));
    LCDLOGI("--------dmareg DRCMR1(RCMR)----------0x%x\r\n",REG32(DMA_BASE_ADDRESS + 0x100+4*DMA_REQ_SSP0_TX));
    LCDLOGI("--------dmareg DSADR(DSADR)----------0x%x\r\n",REG32(DMA_BASE_ADDRESS + 0x204+16*DMA_DEV_LCD_TX_CH));
    LCDLOGI("--------dmareg DTADR(DTADR)----------0x%x\r\n",REG32(DMA_BASE_ADDRESS + 0x208+16*DMA_DEV_LCD_TX_CH));
    LCDLOGI("--------dmareg DCMD(DCMD)----------0x%x\r\n",REG32(DMA_BASE_ADDRESS + 0x20C+16*DMA_DEV_LCD_TX_CH));
    
}

void spi_set_clk_rate(unsigned int clk_dev)
{
    struct s_spi_ctx* spi_ctx=spi_get_interface();
	if(clk_dev >= SPI_CLK_LIMIT)
		return;
	switch(spi_ctx->info.device_id)
	{
        case SPI_CONETROLER_1:

    	REG32(APB_SSP2_CLK_RST) = 0x3|(clk_dev << 4);

        break;
        
        case SPI_CONETROLER_0:

        REG32(APB_SSP0_CLK_RST) = 0x3|(clk_dev << 4);
        
        break;
        
        default:
          LCDLOGE("set spi clk") ; 
        break;

    }
}
int spi_lcd_init(unsigned char controler)
{
    unsigned ssp_top_cfg,  ssp_fifo_cfg,  ssp_int_en_cfg, ssp_to_cfg;
    struct s_spi_ctx* spi_ctx=spi_get_interface();
    LCDLOGD("++++++++spi controler:%d,%d",spi_ctx->info.device_id,controler);
    int ret = 0;
    switch(controler)
    {
        case SPI_CONETROLER_1:
            
            REG32(APB_SSP2_CLK_RST) = 0x7;
            spi_set_clk_rate(SPI_812_5k);
            ssp_top_cfg	 = 0x4d00;

            ssp_fifo_cfg	 = 0x200e7;

            ssp_int_en_cfg = 0xf;

            ssp_to_cfg	 = 0x200;
            REG32(SSP2_BASE_ADDRESS + 0)  = ssp_top_cfg;

            REG32(SSP2_BASE_ADDRESS + 0x4) = ssp_fifo_cfg;

            REG32(SSP2_BASE_ADDRESS + 0x8) = ssp_int_en_cfg;

            REG32(SSP2_BASE_ADDRESS + 0xc) = ssp_to_cfg;

            REG32(SSP2_BASE_ADDRESS + 0) = ssp_top_cfg|0x1;
            ret = 0;
            break;
            
        case SPI_CONETROLER_0:

            REG32(APB_SSP0_CLK_RST) = 0x7;
            spi_set_clk_rate(SPI_812_5k);
            ssp_top_cfg	 = 0x4100;

            ssp_fifo_cfg	 = 0x200e7;

            ssp_int_en_cfg = 0xf;

            ssp_to_cfg	 = 0x200;
            REG32(SSP0_BASE_ADDRESS + 0)  = ssp_top_cfg;

            REG32(SSP0_BASE_ADDRESS + 0x4) = ssp_fifo_cfg;

            REG32(SSP0_BASE_ADDRESS + 0x8) = ssp_int_en_cfg;

            REG32(SSP0_BASE_ADDRESS + 0xc) = ssp_to_cfg;

            REG32(SSP0_BASE_ADDRESS + 0) = ssp_top_cfg|0x1;
            
            ret = 0;
            
            break;
            
        default:
            ret = -1;
            break;
    }
   return ret;
}


void ssp_write_cmd_data_to_LCD(unsigned int cmd, unsigned int data,unsigned int data_bits,unsigned short line_num)
{
    int reg;
    if((data_bits <1) || (data_bits >31))
    	return;
    struct s_spi_ctx* spi_ctx=spi_get_interface();
    switch(spi_ctx->info.device_id)
    {
        case SPI_CONETROLER_1:
            REG32(SSP2_BASE_ADDRESS + 0x54)  = 0x5;  //master output
            reg = REG32(SSP2_BASE_ADDRESS) & ~(0x1f << 5);
            if(line_num == 3)
            {
            	REG32(SSP2_BASE_ADDRESS) = reg | (data_bits << 5); //9 bit
            	if(!cmd)
            	{ 
                	*(volatile unsigned int*)(SSP2_BASE_ADDRESS + SSP_DATAR) = data; 
            	}
            	else
            	{
                	*(volatile unsigned int*)(SSP2_BASE_ADDRESS + SSP_DATAR) = (1<< data_bits) | data;    

            	}
            }
            else if(line_num == 4)
            {
            	REG32(SSP2_BASE_ADDRESS) = reg | ((data_bits -1) << 5); //sent bit
                *(volatile unsigned int*)(SSP2_BASE_ADDRESS + SSP_DATAR) = data; 
            }
            else
            	LCDLOGE("ERROR: spi line number error!\r\n");
        break;
        
        case SPI_CONETROLER_0:
            
            REG32(SSP0_BASE_ADDRESS + 0x54)  = 0x5;  //master output
            reg = REG32(SSP0_BASE_ADDRESS) & ~(0x1f << 5);
            if(line_num == 3)
            {
            	REG32(SSP0_BASE_ADDRESS) = reg | (data_bits << 5); //9 bit
            	if(!cmd)
            	{ 
                	*(volatile unsigned int*)(SSP0_BASE_ADDRESS + SSP_DATAR) = data; 
            	}
            	else
            	{
                	*(volatile unsigned int*)(SSP0_BASE_ADDRESS + SSP_DATAR) = (1<< data_bits) | data;    

            	}
            }
            else if(line_num == 4)
            {
            	REG32(SSP0_BASE_ADDRESS) = reg | ((data_bits -1) << 5); //sent bit
                *(volatile unsigned int*)(SSP0_BASE_ADDRESS + SSP_DATAR) = data; 
            }
            else
            	LCDLOGE("ERROR: spi line number error!\r\n");
        break;
        default:
            LCDLOGE(" spi write error\r\n");
            break;
    }
}

void ssp_write_data_to_LCD_Gram(unsigned short* data,unsigned int sum_pixel,unsigned int data_bits,unsigned short line_num)
{
    int reg;
    int cnt,i;
    if((data_bits <1) || (data_bits >31))
    	return;
    struct s_spi_ctx* spi_ctx=spi_get_interface();
    switch(spi_ctx->info.device_id)
    {
        case SPI_CONETROLER_1:
            
            REG32(SSP2_BASE_ADDRESS + 0x54)  = 0x5;  //master output
            reg = REG32(SSP2_BASE_ADDRESS) & ~(0x1f << 5);
            if(line_num == 3)
            	REG32(SSP2_BASE_ADDRESS) = reg | (8 << 5); //
            else if(line_num == 4)
            	REG32(SSP2_BASE_ADDRESS) = reg | ((data_bits -1) << 5); //
            for(i=0;i<sum_pixel;i++)
            {
            	cnt = 0;
            	while(!(REG32(SSP2_BASE_ADDRESS + SSP__STATUS) & (0x1 << 6))) //wait for tx not full
            	{
            		if(cnt++ > 1000000)
            		{
            			LCDLOGE("ERROR: spi write byte error!\r\n");
            			return;
            		}
            	}
            	if(line_num == 3)
            	{
            		if((data_bits == 16) || (data_bits == 8))
            		{
            			*(volatile unsigned int*)(SSP2_BASE_ADDRESS + SSP_DATAR) = (1<< 8) | (*(data+i) >> 8);
            			cnt = 0;
            			while(!(REG32(SSP2_BASE_ADDRESS + SSP__STATUS) & (0x1 << 6))) //wait for tx not full
            			{
            				if(cnt++ > 1000000)
            				{
            					LCDLOGE("ERROR: spi write byte error!\r\n");
            					return;
            				}
            			}
            			*(volatile unsigned int*)(SSP2_BASE_ADDRESS + SSP_DATAR) = (1<< 8) | (*(data+i) & 0xff);
            		}
            		else
            			LCDLOGE("spi write byte not support length!\r\n");
            	}
            	else if(line_num == 4)
            		*(volatile unsigned int*)(SSP2_BASE_ADDRESS + SSP_DATAR) = *(data+i);
            	else
            	{
            		LCDLOGE("ERROR: spi line number error!\r\n");
            		return;
            	}
            }
        break;
            
        case SPI_CONETROLER_0:

        REG32(SSP0_BASE_ADDRESS + 0x54)  = 0x5;  //master output
        reg = REG32(SSP0_BASE_ADDRESS) & ~(0x1f << 5);
        if(line_num == 3)
        	REG32(SSP0_BASE_ADDRESS) = reg | (8 << 5); //
        else if(line_num == 4)
        	REG32(SSP0_BASE_ADDRESS) = reg | ((data_bits -1) << 5); //
        for(i=0;i<sum_pixel;i++)
        {
        	cnt = 0;
        	while(!(REG32(SSP0_BASE_ADDRESS + SSP__STATUS) & (0x1 << 6))) //wait for tx not full
        	{
        		if(cnt++ > 1000000)
        		{
        			LCDLOGE("ERROR: spi write byte error!\r\n");
        			return;
        		}
        	}
        	if(line_num == 3)
        	{
        		if((data_bits == 16) || (data_bits == 8))
        		{
        			*(volatile unsigned int*)(SSP0_BASE_ADDRESS + SSP_DATAR) = (1<< 8) | (*(data+i) >> 8);
        			cnt = 0;
        			while(!(REG32(SSP0_BASE_ADDRESS + SSP__STATUS) & (0x1 << 6))) //wait for tx not full
        			{
        				if(cnt++ > 1000000)
        				{
        					LCDLOGE("ERROR: spi write byte error!\r\n");
        					return;
        				}
        			}
        			*(volatile unsigned int*)(SSP0_BASE_ADDRESS + SSP_DATAR) = (1<< 8) | (*(data+i) & 0xff);
        		}
        		else
        			LCDLOGE("spi write byte not support length!\r\n");
        	}
        	else if(line_num == 4)
        		*(volatile unsigned int*)(SSP0_BASE_ADDRESS + SSP_DATAR) = *(data+i);
        	else
        	{
        		LCDLOGE("ERROR: spi line number error!\r\n");
        		return;
        	}
        }
        break;
        default:
             LCDLOGE(" spi write error\r\n");
        break;
    }
		
}

void ssp_read_data_from_LCD(unsigned int *data,  unsigned int data_bits)
{    
    int status = 0;
    unsigned reg = 0;
    struct s_spi_ctx* spi_ctx=spi_get_interface();
    switch(spi_ctx->info.device_id)
    {
        case SPI_CONETROLER_1:
            reg = REG32(SSP2_BASE_ADDRESS) & ~(0x1f << 5);
        	if((data_bits <1) || (data_bits >31))
        		return;
        	if(data_bits >8)
        		 REG32(SSP2_BASE_ADDRESS) = reg | (data_bits << 5);
        	else
            	REG32(SSP2_BASE_ADDRESS) = reg | ((data_bits -1) << 5); //8 bit 
            REG32(SSP2_BASE_ADDRESS+0x54)  = 0x7;  //master input 
            REG32(SSP2_BASE_ADDRESS + SSP_DATAR) = 0x00; //dummy read
            while(((status = REG32(SSP2_BASE_ADDRESS + SSP__STATUS)) & (0x1 << 14)) == 0);
        	*data = REG32(SSP2_BASE_ADDRESS +SSP_DATAR);
        break;
            
        case SPI_CONETROLER_0:
            reg = REG32(SSP0_BASE_ADDRESS) & ~(0x1f << 5);
        	if((data_bits <1) || (data_bits >31))
        		return;
        	if(data_bits >8)
        		 REG32(SSP0_BASE_ADDRESS) = reg | (data_bits << 5);
        	else
            	REG32(SSP0_BASE_ADDRESS) = reg | ((data_bits -1) << 5); //8 bit 
            REG32(SSP0_BASE_ADDRESS+0x54)  = 0x7;  //master input 
            REG32(SSP0_BASE_ADDRESS + SSP_DATAR) = 0x00; //dummy read
            while(((status = REG32(SSP0_BASE_ADDRESS + SSP__STATUS)) & (0x1 << 14)) == 0);
        	*data = REG32(SSP0_BASE_ADDRESS +SSP_DATAR);
        break;
            
        default:
            LCDLOGE(" spi read error\r\n");
        break;
    }
}

void wait_ssp_write_data_to_LCD_complete(void)
{
	int cnt = 0;
    struct s_spi_ctx* spi_ctx=spi_get_interface();
    switch(spi_ctx->info.device_id)
    {
        case SPI_CONETROLER_1:
        	while((REG32(SSP2_BASE_ADDRESS + SSP__STATUS) & 0xfc0) != 0x40) //wait for tx empty	
        	{
        		if(cnt++ > 1000000)
        		{
        			LCDLOGE("ERROR: spi write byte error!\r\n");
        			return;
        		}
            }
        break;
            
        case SPI_CONETROLER_0:
            while((REG32(SSP0_BASE_ADDRESS + SSP__STATUS) & 0xfc0) != 0x40) //wait for tx empty
            {
        		if(cnt++ > 1000000)
        		{
        			LCDLOGE("ERROR: spi write byte error!\r\n");
        			return;
        		}
            }
        break;
            
        default:
            LCDLOGE("port error\r\n");
        break;
    }

}

/*spi 3wire 1data lane 1interface function*/
unsigned int mfp_cfg_lcd_spi_3w_1l_1if[] = {
	MFP_REG(QUEC_LCD_SPI_CS_NUM ) | QUEC_LCD_SPI_CS_AF | MFP_DRIVE_MEDIUM | MFP_PULL_HIGH | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE, /*CS*/
	MFP_REG(QUEC_LCD_SPI_RST_NUM ) | QUEC_LCD_SPI_RST_AF | MFP_DRIVE_MEDIUM | MFP_PULL_HIGH | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE, /*RST*/
	MFP_REG(QUEC_LCD_SPI_SCLK_NUM ) | QUEC_LCD_SPI_SCLK_AF | MFP_DRIVE_MEDIUM | MFP_PULL_HIGH | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE, /*SCLK*/
	MFP_REG(QUEC_LCD_SPI_SDA_NUM ) | QUEC_LCD_SPI_SDA_AF | MFP_DRIVE_MEDIUM | MFP_PULL_HIGH | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE, /*SDA*/
	MFP_EOC
};

/*spi 4wire 1data lane 1interface function*/
unsigned int mfp_cfg_lcd_spi_4w_1l_1if[] = {
	MFP_REG(QUEC_LCD_SPI_CS_NUM ) | QUEC_LCD_SPI_CS_AF | MFP_DRIVE_MEDIUM | MFP_PULL_HIGH | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE, /*CS*/
	MFP_REG(QUEC_LCD_SPI_RST_NUM ) | QUEC_LCD_SPI_RST_AF | MFP_DRIVE_MEDIUM | MFP_PULL_HIGH | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE, /*RST*/
	MFP_REG(QUEC_LCD_SPI_SCLK_NUM ) | QUEC_LCD_SPI_SCLK_AF | MFP_DRIVE_MEDIUM | MFP_PULL_HIGH | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE, /*SCLK*/
	MFP_REG(QUEC_LCD_SPI_SDA_NUM ) | QUEC_LCD_SPI_SDA_AF | MFP_DRIVE_MEDIUM | MFP_PULL_HIGH | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE, /*SDA*/
	MFP_REG(QUEC_LCD_SPI_DCX_NUM ) | QUEC_LCD_SPI_DCX_AF | MFP_DRIVE_MEDIUM | MFP_PULL_HIGH | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE, /*DCX*/
	MFP_EOC
};

void LCD_Pinmuxcfg(unsigned int interface)
{
    LCDLOGI("pin:%d\r\n",interface);
	switch(interface){
	case 0: /*spi_3wire_1datalane_1if*/
		mfp_config(mfp_cfg_lcd_spi_3w_1l_1if);
		break;
	case 1: /*spi_3wire_2datalane_1if*/
		break;
	case 2: /*spi_3wire_1datalane_2if*/
		break;
	case 3: /*spi_3wire_2datalane_2if*/
		break;
	case 4: /*spi_4wire_1datalane_1if*/
		mfp_config(mfp_cfg_lcd_spi_4w_1l_1if);
		break;
	case 5: /*spi_4wire_1datalane_2if*/
		break;
	default:/*Invalid case*/
		;
	}
}

void spi_set_cs_high(void)
{
    GpioSetDirection(SPI_LCD_CS,GPIO_OUT_PIN); 
    GpioSetLevel(SPI_LCD_CS,GPIORC_HIGH);
}

void spi_set_cs_low(void)
{
    GpioSetDirection(SPI_LCD_CS,GPIO_OUT_PIN); 
    GpioSetLevel(SPI_LCD_CS,GPIORC_LOW);

}

void spi_uninit(struct s_spi_ctx *spi_ctx)
{
    spi_ctx->status = SPI_STATUS_UNINIT;
	return;
}
void spi_reset(struct s_spi_ctx *spi_ctx)
{
	return;
}

void lcd_spi_set_data_mode(void)
{
    GpioSetDirection(SPI_LCD_DCX , GPIO_OUT_PIN);
	GpioSetLevel(SPI_LCD_DCX ,GPIORC_HIGH);
}

void lcd_spi_set_cmd_mode(void)
{
    GpioSetDirection(SPI_LCD_DCX , GPIO_OUT_PIN);
	GpioSetLevel(SPI_LCD_DCX ,GPIORC_LOW);
}

int spi_write_cmd(struct s_spi_ctx *spi_ctx, unsigned int cmd, unsigned int bits)
{
	struct spi_info *spi = &(spi_ctx->info);
    spi_set_clk_rate(spi->timing->wclk);
    if(4 == spi->line_num)
	{
        lcd_spi_set_cmd_mode();
    }
    spi_set_cs_low();
    ssp_write_cmd_data_to_LCD(0,cmd,bits,spi->line_num);
    wait_ssp_write_data_to_LCD_complete();
    panel_delay(1);
    spi_set_cs_high(); 
    return 0;
    
}

int spi_write_data(struct s_spi_ctx *spi_ctx, unsigned int data, unsigned int bits)
{
  
    struct spi_info *spi = &(spi_ctx->info);
    spi_set_clk_rate(spi->timing->wclk);
	if(4 == spi->line_num)
	{
        lcd_spi_set_data_mode();
    }
	
    spi_set_cs_low();
	ssp_write_cmd_data_to_LCD(1,data,bits,spi->line_num);
    wait_ssp_write_data_to_LCD_complete();
	panel_delay(1);
    spi_set_cs_high(); 
    return 0;
}

int spi_read_data(struct s_spi_ctx *spi_ctx, unsigned int cmd, unsigned int cmd_bits,
	unsigned int *data,  unsigned int data_bits)
{
    struct spi_info *spi = &(spi_ctx->info);
	if(4 == spi->line_num)
	{
        lcd_spi_set_cmd_mode();
	}
    spi_set_clk_rate(spi->timing->rclk);
    spi_set_cs_low();
	ssp_write_cmd_data_to_LCD(0,cmd,cmd_bits,spi->line_num);
	panel_delay(10);
	ssp_read_data_from_LCD(data,data_bits);
    spi_set_cs_high();
    return 0;
}

struct s_spi_ctx* spi_init(unsigned int sclk, struct spi_info *info, int work_mode)
{
    int ret = 0;
	struct s_spi_ctx* spi_ctx = &g_spi_ctx;
	int i;

	LCDLOGD("( dev_id:%d)+++",info->device_id);

	if(info == NULL || info->timing == NULL){
		LCDLOGE("Invalid param!");
		return NULL;
	}

	if((info->format != SPI_FORMAT_RGB565) &&
		(info->format != SPI_FORMAT_RGB666) && (info->data_lane_num == 1)){
		LCDLOGE("Format error!");
		return NULL;
	}
  
    spi_ctx->cur_path = 0;
	spi_ctx->cur_cs = 0;
	spi_ctx->status = 0;    
	spi_ctx->base_addr = 0;
	spi_ctx->sclk = sclk;
	spi_ctx->info.line_num = info->line_num;
	spi_ctx->info.interface_id = info->interface_id;
	spi_ctx->info.data_lane_num = info->data_lane_num;
	spi_ctx->info.format = info->format;
	spi_ctx->info.device_id = info->device_id; /*spi控制器*/
	spi_ctx->info.sample_edge = info->sample_edge;
	spi_ctx->info.force_cs = info->force_cs;
	spi_ctx->info.endian = info->endian;
	spi_ctx->info.timing = info->timing;
    spi_ctx->work_mode = work_mode;
    
	ret = spi_lcd_init(info->device_id);
    if(ret != 0)
    {
       LCDLOGE("spi initialize failed"); 
    }
    
    if(work_mode == SPI_WORK_MODE_DMA){
    spi_dma_init();
    }

	spi_ctx->status = SPI_STATUS_INIT;
	return spi_ctx;
}

int spi_update(struct s_spi_ctx *spi_ctx, int work_mode)
{

	LCDLOGI("spi_update +++\r\n");
   
	spi_ctx->work_mode = work_mode;
	LCDLOGI("spi_update ----\r\n");
	return 0;
}


