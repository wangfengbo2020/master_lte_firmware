/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/

#include "global_types.h"
#include "quec_cust_feature.h"
#include "twsi.h"
#include "cgpio_HW.h"
#include "mfpr_api.h"
#include "quec_iic.h"
#include "quec_gpio.h"


#ifdef __cplusplus
extern "C" {
#endif

static int QL_RET_ERR_IIC_SLAVE_NOT_FOUND=-308;

#ifndef MIN_SYS

#define	TWSI0_BASE	0xD4011000
#define	TWSI1_BASE	0xD4010800
#define	TWSI2_BASE	0xD403e000
#define	TWSI3_BASE	0xD4037000
#define TWSI4_BASE  0XD403f000


#define	APBC_BASE	0xD4015000
#define	APBC_TWSI0_CLK_RST		(APBC_BASE+0x002c)	/* 32 bit	APBClock Clock/Reset Control Register for TWSI0*/
#define	APBC_TWSI1_CLK_RST		(APBC_BASE+0x0060)	/* 32 bit	APBClock Clock/Reset Control Register for TWSI1*/
#define	APBC_TWSI2_CLK_RST		(APBC_BASE+0x007c)	/* 32 bit	APBClock Clock/Reset Control Register for TWSI2*/
#define	APBC_TWSI3_CLK_RST		(APBC_BASE+0x0078)	/* 32 bit	APBClock Clock/Reset Control Register for TWSI3*/
#define APBC_TWSI4_CLK_RST      (APBC_BASE+0x0088)  /* 32 bit  APBClock Clock/Reset Control Register for TWSI4*/

#define msleep(x) OSATaskSleep((x) * 20)//100*msecond

    
unsigned int quec_apbc_clk_reg[] =
{
    APBC_TWSI0_CLK_RST,
    APBC_TWSI1_CLK_RST,
    APBC_TWSI2_CLK_RST,
    APBC_TWSI3_CLK_RST,
    APBC_TWSI4_CLK_RST
};
#define I2C_SLAVE_WRITE(slv)        ( (slv << 1) & (~0x1) )			/* Master is writing to the slave */
#define I2C_SLAVE_READ(slv)         ( (slv << 1) | 0x00000001 )      	/* Master is reading from the slave */
#define quec_write32(addr, val)     (*(volatile unsigned int *)(addr) = (val))
#define quec_read32(addr)           (*(volatile unsigned int *)(addr))

unsigned int quec_twsi_base[] = {TWSI0_BASE, TWSI1_BASE,TWSI2_BASE,TWSI3_BASE,TWSI4_BASE};

void quec_ui_delay_us(unsigned int us)
{
    int cnt = 26;//0x100,0x300
    volatile int i = 0;
    while (us--) {
        i = cnt;
        while (i--);
    }
}

unsigned int quec_get_i2c_bus_mode(int port_idx)
{
    unsigned int port_base = quec_twsi_base[port_idx];

    return ((quec_read32(TWSI_ICR+port_base))>>TWSI_ICR_MODE_BASE)&3;
}
void quec_i2c_clear_control(int port_idx)
{
    unsigned int port_base = quec_twsi_base[port_idx];
    unsigned int ICRRegValue=0;

    ICRRegValue=quec_read32(TWSI_ICR+port_base);
    ICRRegValue&=~(TWSI_ICR_TB|TWSI_ICR_ACKNAK|TWSI_ICR_STOP|TWSI_ICR_START);
    quec_write32(TWSI_ICR+port_base, ICRRegValue);
}

void quec_i2c_clear_status(int port_idx,unsigned int status)
{
    unsigned int port_base = quec_twsi_base[port_idx];

    quec_write32(TWSI_ISR+port_base, status);
}

void quec_iic_reset_unit(int port_idx)
{
    unsigned int port_base = quec_twsi_base[port_idx];

    quec_write32(TWSI_ICR+port_base, TWSI_ICR_UR);
    quec_write32(TWSI_ISR+port_base, (TWSI_ISR_RXOV|TWSI_ISR_RXF|TWSI_ISR_RXHF|TWSI_ISR_TXE|TWSI_ISR_TXDONE|
                        TWSI_ISR_MSD|TWSI_ISR_SSD|TWSI_ISR_SAD|TWSI_ISR_BED|TWSI_ISR_GCAD|
                        TWSI_ISR_IRF|TWSI_ISR_ITE|TWSI_ISR_ALD));
    quec_write32(TWSI_ICR+port_base, 0);
}

int quec_i2c_bus_reset(int port_idx)
{
    unsigned int ICRRegValue=0;
    unsigned int port_base = quec_twsi_base[port_idx];
    unsigned int    i=0;

    quec_write32(TWSI_RST_CYC+port_base,0x9);

    ICRRegValue = quec_read32(TWSI_ICR+port_base);
    ICRRegValue |= (TWSI_ICR_BUS_RESET);
    quec_write32(TWSI_ICR+port_base, ICRRegValue);

    while(0!=(quec_read32(TWSI_ICR+port_base)&TWSI_ICR_BUS_RESET))
    {
        quec_ui_delay_us(10);
        i++;
        if(i>10000)
        {
            RTI_LOG("Error: i2c_bus_reset error TWSI_ICR=0x%X\n",ICRRegValue);
            return -1;
        }
    }
    return 0;

}

void quec_i2c_set_mode(unsigned char i2c_no,QUEC_I2C_FAST_MODE mode)
{
    unsigned int LCR = 0,SLV = 0,FLV = 0,HLVL = 0,HLVH = 0,WCR,WCR_COUNT;
    unsigned int port_base = quec_twsi_base[i2c_no];
    unsigned int reg;
    unsigned int fclk,I2c_clk;
    reg = quec_apbc_clk_reg[i2c_no];
    quec_write32( reg, 0x4);
    quec_write32( reg, 0x7);
    quec_write32( reg, 0x3);//apb function clk 0:33mhz
    fclk = 33000;//33mhz = 33000khz
    LCR = quec_read32(TWSI_ILCR+port_base);
    SLV = LCR & 0x1ff;
    FLV = (LCR & 0x3fe00) >> 9;
    HLVH = (LCR & 0x7fc0000) >> 18;
    HLVL = (LCR & 0xf8000000) >> 27;
    switch(mode)
	{
        case STANDARD_MODE:
            I2c_clk = 100;//i2c clk 100khz
            SLV = (fclk / I2c_clk - 8) / 2;
            SLV &= 0x1ff;
        break;
        case FAST_MODE:
            I2c_clk = 400;//i2c clk 400khz
            FLV = (fclk / I2c_clk - 8) / 2 - 1;
            FLV &= 0x1ff;
            WCR = quec_read32(TWSI_IWCR+port_base);
            WCR_COUNT = WCR & 0x1f;
            if(WCR_COUNT > FLV / 3)
            {
                WCR_COUNT = FLV / 3;
                quec_write32(TWSI_IWCR+port_base,(WCR & (~0x1f)) | WCR_COUNT);
            }
        break;
        case HS_MODE:
        case HS_MODE_FAST:
            I2c_clk = 1800;//i2c clk 1.8Mhz
            HLVH = 6;  //use register default value
            HLVL = fclk / I2c_clk - 9 - HLVH;
            HLVL &= 0x1f;
        break;
        default:
           quec_debug_print_uart("I2c not support mode:%d\n",mode);
           break;
    }
    quec_write32(TWSI_ILCR+port_base,(HLVL << 27) | (HLVH << 18) | (FLV << 9) | SLV);
}

void quec_i2c_fifo_set_control(int port_idx, int control)
{
    unsigned int port_base = quec_twsi_base[port_idx];
    unsigned int ICRRegValue=0;

    ICRRegValue=quec_read32(TWSI_ICR+port_base);
    ICRRegValue&=~(TWSI_ICR_TB|TWSI_ICR_ACKNAK|TWSI_ICR_STOP|TWSI_ICR_START);
    ICRRegValue |= control;
    quec_write32(TWSI_ICR+port_base, ICRRegValue);
}

int quec_i2c_init(unsigned char i2c_no, unsigned int fastMode)
{
    unsigned int port_base = quec_twsi_base[i2c_no]; 
	if(CHIP_IS_CRANEL)
	{
		switch(i2c_no)
		{
			case 0:
				quec_set_gpio_mfprReg(49, MFP_AF1);
				quec_set_gpio_mfprReg(50, MFP_AF1);
				break;
			case 1:
				quec_set_gpio_mfprReg(10, MFP_AF1);
				quec_set_gpio_mfprReg(11, MFP_AF1);
				break;
			case 2:
				quec_set_gpio_mfprReg(12, MFP_AF7);
				quec_set_gpio_mfprReg(13, MFP_AF7);
				break;
			case 4:
				quec_set_gpio_mfprReg(25, MFP_AF2);
				quec_set_gpio_mfprReg(26, MFP_AF2);
				break;
			default:
				return -1;
		}
	}else if(CHIP_IS_CRANELR)
	{
		switch(i2c_no)
		{
			case 0:
				quec_set_gpio_mfprReg(49, MFP_AF1);
				quec_set_gpio_mfprReg(50, MFP_AF1);
				break;
			case 1:
				quec_set_gpio_mfprReg(10, MFP_AF1);
				quec_set_gpio_mfprReg(11, MFP_AF1);
				break;
			default:
				return -1;
		}

	}
    quec_iic_reset_unit(i2c_no);
    quec_i2c_bus_reset(i2c_no);
    quec_ui_delay_us(5000);
    
//  quec_write32(TWSI_ILCR+port_base, 0x4024bb56);//HS:2.0MHz
    quec_write32(TWSI_IWCR+port_base, 0x1a|(1<<5)|(20<<10));
    quec_i2c_set_mode(i2c_no,(QUEC_I2C_FAST_MODE)fastMode);
    quec_write32(TWSI_ICR+port_base,TWSI_ICR_IUE | TWSI_ICR_SCLE|(fastMode<<TWSI_ICR_MODE_BASE));
    quec_debug_print_uart("%s quec_i2c_init=0x%x\n",__func__,quec_read32(TWSI_ICR+port_base));
    return 0;
}

int quec_i2c_wait_status(int port_idx,unsigned int status)
{
    unsigned int port_base = quec_twsi_base[port_idx];
    unsigned int i = 0;

    while(status!=(status&(quec_read32(TWSI_ISR+port_base))))
    {
        if(TWSI_ISR_BED&(quec_read32(TWSI_ISR+port_base)))
        {
            quec_debug_print_uart("Error: bus error detected,0x%x,0x%x!\n",quec_read32(TWSI_ICR+port_base),quec_read32(TWSI_ISR+port_base));
            quec_i2c_init(port_idx,quec_get_i2c_bus_mode(port_idx));
            return -1;
        }
        else if(i>10000)
        {
            quec_debug_print_uart("Error: i2c_wait_status time out,0x%x,0x%x!\n",quec_read32(TWSI_ICR+port_base),quec_read32(TWSI_ISR+port_base));
            quec_i2c_init(port_idx,quec_get_i2c_bus_mode(port_idx));
            return -1;
        }
        quec_ui_delay_us(1);
        i++;
    }
    return 0;
}

//slaveaddress:从机地址; addr:要写入的的寄存器地址;data:要写入的数据；datalen:要写入的数据长度
int quec_i2c_write(unsigned char i2c_no, unsigned short slaveaddress, unsigned short addr, unsigned char *data, unsigned int datalen)
{
    int     i;
    int addr_len;
    
    unsigned int port_base = quec_twsi_base[i2c_no];
    unsigned char   *wp = (unsigned char *)&addr;

    quec_write32(TWSI_IDBR+port_base, I2C_SLAVE_WRITE(slaveaddress));
    quec_i2c_clear_status(i2c_no, TWSI_ISR_ITE);
    quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_START | TWSI_ICR_TB);
    if(quec_i2c_wait_status(i2c_no,TWSI_ISR_ITE | TWSI_ISR_UB)<0)
    {
        quec_debug_print_uart("Error:Write start+slaveaddress\n");
        return -2;
    }
    
    addr_len = addr & 0xFF00 ? 2 :1;

    

    wp = (unsigned char *)&addr;
    for(i = 0; i < (addr_len + datalen - 1); i++)
    {
        if(i == addr_len)           /*start to send from data buf when cmd finishes*/
            wp = data;

        quec_write32(TWSI_IDBR+port_base, *wp); /*write data byte to the IDBR register*/
        wp++;
        quec_i2c_clear_status(i2c_no, TWSI_ISR_ITE);
        quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_TB);/*Set 'Tranfer Byte' bit to intiate the access*/
        if(quec_i2c_wait_status(i2c_no,TWSI_ISR_ITE | TWSI_ISR_UB)<0)
        {
            quec_debug_print_uart("Error:Write cmdlen+datalen %d\n", i);
            return -2;
        }
    }
    if(i == addr_len)           /*start to send from data buf when cmd finishes*/
            wp = data;
    /*** Send the last byte with STOP bit ***/
    quec_write32(TWSI_IDBR+port_base, *wp);
    quec_i2c_clear_status(i2c_no, TWSI_ISR_ITE);
    quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_TB|TWSI_ICR_STOP);
    if(quec_i2c_wait_status(i2c_no,TWSI_ISR_ITE)<0)
    {
        RTI_LOG("Error:Write stop\n");
        return -2;
    }
    quec_i2c_clear_control(i2c_no);
    return 0;
}
int quec_i2c_read(unsigned char i2c_no, unsigned short slaveaddress, unsigned short addr, unsigned char *data, unsigned int datalen)
{
    int     i;
    unsigned int port_base = quec_twsi_base[i2c_no];
    unsigned char   *wp = (unsigned char *)&addr;
    int addr_len;
    

    addr_len = addr & 0xFF00 ? 2 :1;

    if(0 != addr_len)/*cmdlen=0 means no need to write the device reg addr, so no need to write the device addr*/
    {
        quec_write32(TWSI_IDBR+port_base, I2C_SLAVE_WRITE(slaveaddress));
        quec_i2c_clear_status(i2c_no, TWSI_ISR_ITE);
        quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_START | TWSI_ICR_TB);
        if(quec_i2c_wait_status(i2c_no,TWSI_ISR_ITE | TWSI_ISR_UB)<0)
        {
            RTI_LOG("Error:Write start+slaveaddress\n");
            return -2;
        }
        wp = (unsigned char *)&addr;
        for(i = 0; i < addr_len; i++)
        {
            quec_write32(TWSI_IDBR+port_base, *wp); /*write data byte to the IDBR register*/
            wp++;
            quec_i2c_clear_status(i2c_no, TWSI_ISR_ITE);
            quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_TB);/*Set 'Tranfer Byte' bit to intiate the access*/
            if(quec_i2c_wait_status(i2c_no,TWSI_ISR_ITE | TWSI_ISR_UB)<0)
            {
                quec_debug_print_uart("Error:Write cmdlen %d\n", i);
                return -2;
            }
        }
    }

    /*** send Read Request ***/
    quec_write32(TWSI_IDBR+port_base, I2C_SLAVE_READ(slaveaddress)); /*write IDBR: target slave address and R/W# bit (1 for read)*/
    quec_i2c_clear_status(i2c_no, TWSI_ISR_ITE);
    quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_START | TWSI_ICR_TB);
    if(quec_i2c_wait_status(i2c_no,TWSI_ISR_ITE | TWSI_ISR_UB |TWSI_ISR_RWM)<0)
    {
        quec_debug_print_uart("Error:send Read Request\n");
        return -2;
    }
    while(datalen)
    {
        if(datalen > 1)
        {
            quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_TB);
        }
        else if(datalen == 1)
        {
            quec_i2c_fifo_set_control(i2c_no,(TWSI_ICR_STOP | TWSI_ICR_ACKNAK | TWSI_ICR_TB));
        }
        if(quec_i2c_wait_status(i2c_no,TWSI_ISR_IRF)<0)
        {
            RTI_LOG("Error:rx data %d\n",datalen);
            return -2;
        }
        quec_i2c_clear_status(i2c_no, TWSI_ISR_IRF);
        *data++ = quec_read32(TWSI_IDBR+port_base);                 /*read the received byte*/
        datalen--;
    }
    quec_i2c_clear_control(i2c_no);
    return 0;
}

#ifdef QUECTEL_OPEN_CPU
int quec_i2c_write_ext(unsigned char  i2c_no, unsigned char  slaveaddress,unsigned char  *addr,unsigned int  addrlen, unsigned char  *data, unsigned int datalen)
{
	int 	i;
	
	unsigned int port_base = quec_twsi_base[i2c_no];
	unsigned char	*wp = addr;

	quec_write32(TWSI_IDBR+port_base, I2C_SLAVE_WRITE(slaveaddress));
	quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_START | TWSI_ICR_TB);
	quec_i2c_clear_status(i2c_no, TWSI_ISR_ITE);
	if(quec_i2c_wait_status(i2c_no,TWSI_ISR_ITE | TWSI_ISR_UB)<0)
	{
		uart_printf("Error:Write start+slaveaddress\n");
		return QL_RET_ERR_IIC_SLAVE_NOT_FOUND;
	}
	
	if(NULL == addr)
		addrlen=0;

	for(i = 0; i < (addrlen + datalen - 1); i++)
	{
		if(i == addrlen)			/*start to send from data buf when cmd finishes*/
			wp = data;

		quec_write32(TWSI_IDBR+port_base, *wp);	/*write data byte to the IDBR register*/
		wp++;
		quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_TB);/*Set 'Tranfer Byte' bit to intiate the access*/
		quec_i2c_clear_status(i2c_no, TWSI_ISR_ITE);
		if(quec_i2c_wait_status(i2c_no,TWSI_ISR_ITE | TWSI_ISR_UB)<0)
		{
			uart_printf("Error:Write cmdlen+datalen %d\n", i);
			return QL_RET_ERR_IIC_SLAVE_NOT_FOUND;
		}
	}
    
	if(i == addrlen)			
		wp = data;

	/*** Send the last byte with STOP bit ***/
	quec_write32(TWSI_IDBR+port_base, *wp);
	quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_TB|TWSI_ICR_STOP);
	quec_i2c_clear_status(i2c_no, TWSI_ISR_ITE);
	if(quec_i2c_wait_status(i2c_no,TWSI_ISR_ITE)<0)
	{
		uart_printf("Error:Write stop\n");
		return QL_RET_ERR_IIC_SLAVE_NOT_FOUND;
	}
	quec_i2c_clear_control(i2c_no);
	return 0;
}


int quec_i2c_read_ext(unsigned char i2c_no, unsigned char slaveaddress, unsigned char *addr,unsigned int addrlen, unsigned char *data, unsigned int datalen)
{
	int 	i;
	unsigned int port_base = quec_twsi_base[i2c_no];
	unsigned char	*wp = addr;
	
	

	if((0 != addrlen) && (NULL != addr))/*cmdlen=0 means no need to write the device reg addr, so no need to write the device addr*/
	{
		quec_write32(TWSI_IDBR+port_base, I2C_SLAVE_WRITE(slaveaddress));
		quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_START | TWSI_ICR_TB);
		quec_i2c_clear_status(i2c_no, TWSI_ISR_ITE);
		if(quec_i2c_wait_status(i2c_no,TWSI_ISR_ITE | TWSI_ISR_UB)<0)
		{
			uart_printf("Error:Write start+slaveaddress\n");
			return QL_RET_ERR_IIC_SLAVE_NOT_FOUND;
		}
		wp = addr;
		for(i = 0; i < addrlen; i++)
		{
			quec_write32(TWSI_IDBR+port_base, *wp);	/*write data byte to the IDBR register*/
			wp++;
			quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_TB);/*Set 'Tranfer Byte' bit to intiate the access*/
			quec_i2c_clear_status(i2c_no, TWSI_ISR_ITE);
			if(quec_i2c_wait_status(i2c_no,TWSI_ISR_ITE | TWSI_ISR_UB)<0)
			{
				uart_printf("Error:Write cmdlen %d\n", i);
				return QL_RET_ERR_IIC_SLAVE_NOT_FOUND;
			}
		}
	}

	/*** send Read Request ***/
	quec_write32(TWSI_IDBR+port_base, I2C_SLAVE_READ(slaveaddress)); /*write IDBR: target slave address and R/W# bit (1 for read)*/
	quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_START | TWSI_ICR_TB);
	quec_i2c_clear_status(i2c_no, TWSI_ISR_ITE);
	if(quec_i2c_wait_status(i2c_no,TWSI_ISR_ITE | TWSI_ISR_UB |TWSI_ISR_RWM)<0)
	{
		uart_printf("Error:send Read Request\n");
		return QL_RET_ERR_IIC_SLAVE_NOT_FOUND;
	}
	while(datalen)
	{
		if(datalen > 1)
		{
			quec_i2c_fifo_set_control(i2c_no,TWSI_ICR_TB);
		}
		else if(datalen == 1)
		{
			quec_i2c_fifo_set_control(i2c_no,(TWSI_ICR_STOP | TWSI_ICR_ACKNAK | TWSI_ICR_TB));
		}
		if(quec_i2c_wait_status(i2c_no,TWSI_ISR_IRF)<0)
		{
			uart_printf("Error:rx data %d\n",datalen);
			return QL_RET_ERR_IIC_SLAVE_NOT_FOUND;
		}
		quec_i2c_clear_status(i2c_no, TWSI_ISR_IRF);
		*data++ = quec_read32(TWSI_IDBR+port_base);					/*read the received byte*/
		datalen--;
	}
	quec_i2c_clear_control(i2c_no);
	return 0;
}
#endif 

//封装接口FOR Camera
int TWSI_REG_WRITE_BYTE(uint8 i2c_no, uint8 slaveaddress, uint8 addr, uint8 data)
{
	int ret=0, repeat = 3 ;

	while(repeat--)
	{
		ret = quec_i2c_write(i2c_no,slaveaddress,addr, &data, 1);
		if(0 == ret)
			return 0;
		else
			quec_debug_print_uart("Error: i2c_write [%dth] device[0x%x] addr[0x%x] data[0x%x] failed \n",repeat, slaveaddress, addr, data);
	}
	quec_debug_print_uart("Error:TWSI_REG_WRITE_BYTE\n");
	return -1;
}

int TWSI_REG_READ_BYTE(uint8 i2c_no, uint8 slaveaddress, uint8 addr)
{
	int ret=0, repeat = 3 ;
	uint8 data;

	while(repeat--)
	{
		ret = quec_i2c_read(i2c_no,slaveaddress,addr,&data,1);/*1 byte address, 1 byte data*/
		if(0 == ret)
			return data;
		else
			quec_debug_print_uart("Error: i2c_read [%dth] device[0x%x] addr[0x%x] failed \n",repeat, slaveaddress, addr);
	}
	quec_debug_print_uart("Error:TWSI_REG_READ_BYTE\n");
	return -1;
}

void TWSI_Init(uint32 mode, unsigned int i2c_no)
{
	quec_i2c_init(i2c_no, mode);
}


	
#endif /*MIN_SYS*/



#ifdef __cplusplus
} /*"C" */
#endif


