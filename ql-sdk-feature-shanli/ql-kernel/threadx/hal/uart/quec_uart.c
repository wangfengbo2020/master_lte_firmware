/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/*=================================================================

						EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN			  WHO		  WHAT, WHERE, WHY
------------	 -------	 -------------------------------------------------------------------------------
23/02/2023		  Sharon.li		  增加宏控制，本文件只有OPEN项目使用，编译标准的项目的不参与编译,标准部分函数还是要使用
=================================================================*/

#include <stdio.h>
#include <string.h>
#include "quec_rtos.h"
#include "quec_ring_buffer.h"
#include "UART.h"
#include "quec_uart.h"
#include "cgpio.h"
#include "UART_CommonControl.h"


#define uart_dbg_log(fmt, args...)	quec_debug_print_uart("[%s][%d]"fmt, __FUNCTION__, __LINE__, ##args)

// Default configuration in all UART ports
static	UARTConfiguration uart_default_config[NUMBER_OF_SUPPORT_PORTS] =
{
	{
		UART_FIFO_CTL,
		UART_INT_TRIGGER_L32,
		UART_BAUD_115200,
		UART_WORD_LEN_8,
		UART_ONE_STOP_BIT,
		UART_NO_PARITY_BITS,
		UART_BASIC_INTERFACE,//UART_L2_INTERFACE;
		FALSE,
		FALSE
	},
	{
		UART_FIFO_CTL,
		UART_INT_TRIGGER_L32,
		UART_BAUD_115200,
		UART_WORD_LEN_8,
		UART_ONE_STOP_BIT,
		UART_NO_PARITY_BITS,
		UART_BASIC_INTERFACE,//UART_L1_INTERFACE;
		FALSE,
		FALSE
	},
	{
		UART_FIFO_CTL,
		UART_INT_TRIGGER_L32,
		UART_BAUD_115200,
		UART_WORD_LEN_8,
		UART_ONE_STOP_BIT,
		UART_NO_PARITY_BITS,
		UART_BASIC_INTERFACE,
		FALSE,
		FALSE
	},
	{
	//port = QL_U4_UART_PORT;
	 UART_FIFO_CTL,
	 UART_INT_TRIGGER_L32,
	 UART_BAUD_115200,
	 UART_WORD_LEN_8,
	 UART_ONE_STOP_BIT,
	 UART_NO_PARITY_BITS,
	 UART_BASIC_INTERFACE,
	 FALSE,
	 FALSE
	}
};


#define QUEC_CHECK_UART_PORT_VALID(port_num)  do { \
    if(port_num >= NUMBER_OF_PORTS) { \
        uart_dbg_log("port_num =%d is invalid! \n", port_num); \
        return -4; \
    } \
}while(0)

#define QUEC_CHECK_UART_PORT_VALID_VOID(port_num)  do { \
    if(port_num >= NUMBER_OF_PORTS) { \
        uart_dbg_log("port_num =%d is invalid! \n", port_num); \
        return; \
    } \
}while(0)

static int quec_uart_config(UART_Port port, UARTConfiguration uart_config)
{
	int ret = 0;
	QUEC_CHECK_UART_PORT_VALID(port);
	//UARTInitializePortAddress((UART_Port)UART_PORT_FFUART);
    /* Close UART port. */
    UARTClose(port);
    /* Confige the INTC (interrupt controller) */
	UARTConfigINTC(port);
    /* Confige the STUART port */
	UARTConfigure(port, &uart_config);
    /* Open UART port. */
    ret = UARTOpen(port);
	if (ret != 1) {
		uart_dbg_log("open uart failed, port:%d, ret:%d \n", port, ret);
		return -1;
	}
	return 0;
}

#if defined (QUECTEL_OPEN_CPU) || defined (HX_GNSS_SUPPORT) || defined (QUEC_GPS_SUPPORT) || defined(QUEC_FGM842D_WIFI_SUPPORT)

extern void UARTClearRxTxFIFO(UART_Port portNumber);

#define QUEC_DEBUGUART_TX_BUFF_SIZE         (1024*8)
#define QUEC_DEBUGUART_RX_BUFF_SIZE         (1024*8)

#define QUEC_DEBUGUART_FC_HIGH_THRESHOLD    (1024*6)
#define QUEC_DEBUGUART_FC_LOW_THRESHOLD     (1024*3)


#define QUEC_BTUART_TX_BUFF_SIZE         (1024*8)
#define QUEC_BTUART_RX_BUFF_SIZE         (1024*8)

#define QUEC_BTUART_FC_HIGH_THRESHOLD    (1024*6)
#define QUEC_BTUART_FC_LOW_THRESHOLD     (1024*3)


#define QUEC_MAINUART_TX_BUFF_SIZE         (1024*8)
#define QUEC_MAINUART_RX_BUFF_SIZE         (1024*16)

#define QUEC_UART_U4_TX_BUFF_SIZE		    (1024*8)
#define QUEC_UART_U4_RX_BUFF_SIZE		    (1024*8)


/*此处rb总大小减流控上限得到的剩余大小必须大于dma缓冲块大小（8k）加上uart fifo大小(64byte)*/
#define QUEC_MAINUART_FC_HIGH_THRESHOLD    (1024*7)
#define QUEC_MAINUART_FC_LOW_THRESHOLD     (1024*4)

/*主串口流控标志*/
char g_stop_main_uart_f = 0;

quec_queue_t      quec_debuguart_tx_msg_ref;
quec_queue_t      quec_btuart_tx_msg_ref;
quec_queue_t      quec_mainuart_tx_msg_ref;
quec_queue_t      quec_uart_u4_tx_msg_ref;
quec_queue_t      quec_uart_rx_msg_ref;

quec_task_t       quec_debuguart_tx_task;
quec_task_t       quec_btuart_tx_task;
quec_task_t       quec_mainuart_tx_task;
quec_task_t       quec_uart_u4_tx_task;
quec_task_t       quec_uart_rx_task;


quec_uart_data_t quec_uart_data[NUMBER_OF_SUPPORT_PORTS] = {{0}, {0}, {0},{0}};
char uart_wakeup_mode_open[NUMBER_OF_PORTS]={0};


static void quec_uart_gpio_config(UART_Port port, unsigned int flag)
{
	unsigned long mfpr_reg_data = 0;
	switch (port) {
		case UART_PORT_FFUART:
            
			break;
		case UART_PORT_BTUART:	
			mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(14));	
			mfpr_reg_data = mfpr_reg_data & ~(0x1fff) | 0x1c07;
			*(volatile unsigned long *)(GPIO_MFPR_ADDR(14)) = mfpr_reg_data;
			mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(15));	
			mfpr_reg_data = mfpr_reg_data & ~(0x1fff) | 0x1c07;
			*(volatile unsigned long *)(GPIO_MFPR_ADDR(15)) = mfpr_reg_data;
			break;
		case UART_PORT_STUART:
            if(uart_wakeup_mode_open[port])
            {
                mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(51));	//GPIO51
    			mfpr_reg_data = mfpr_reg_data & ~(0x1fff) | 0x1c31;
    			*(volatile unsigned long *)(GPIO_MFPR_ADDR(51)) = mfpr_reg_data;
            }
            else 
            {
    			mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(51));	//GPIO51
    			mfpr_reg_data = mfpr_reg_data & ~(0x1fff) | 0x1c01;
    			*(volatile unsigned long *)(GPIO_MFPR_ADDR(51)) = mfpr_reg_data;
            }
			mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(52));	//GPIO52
			mfpr_reg_data = mfpr_reg_data & ~(0x1fff) | 0x1c01;
			*(volatile unsigned long *)(GPIO_MFPR_ADDR(52)) = mfpr_reg_data;

			if (flag) 
			{	//QUEC_FC_HW
                #if  defined(__QUECTEL_PROJECT_EG800WCN_11LG__)/*asr gps*/
				mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(4));	//GPIO4
				mfpr_reg_data = mfpr_reg_data & ~(0x1fff) | 0x1c03;
				*(volatile unsigned long *)(GPIO_MFPR_ADDR(4)) = mfpr_reg_data;
				mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(5));	//GPIO5
				mfpr_reg_data = mfpr_reg_data & ~(0x1fff) | 0x1c03;
				*(volatile unsigned long *)(GPIO_MFPR_ADDR(5)) = mfpr_reg_data;
                #else 
				   	mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(53));	//GPIO53
				mfpr_reg_data = mfpr_reg_data & ~(0x1fff) | 0x1c01;
				*(volatile unsigned long *)(GPIO_MFPR_ADDR(53)) = mfpr_reg_data;
				mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(54));	//GPIO54
				mfpr_reg_data = mfpr_reg_data & ~(0x1fff) | 0x1c01;
				*(volatile unsigned long *)(GPIO_MFPR_ADDR(54)) = mfpr_reg_data;
				#endif
			
			}
			break;

            case UART_PORT_U4UART:
            #if defined(__QUECTEL_PROJECT_EG915NEA_AK__) || defined (__QUECTEL_PROJECT_EG915NLA_AK__)|| defined (__QUECTEL_PROJECT_EG915NEA_AN__)||defined(__QUECTEL_PROJECT_EG915NLA_AN__)
                //rx
                mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(4)); 
                mfpr_reg_data = mfpr_reg_data & ~(0x7) | 0x4;
                *(volatile unsigned long *)(GPIO_MFPR_ADDR(4)) = mfpr_reg_data;
                //tx
                mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(5)); 
                mfpr_reg_data = mfpr_reg_data & ~(0x7) | 0x4;
                *(volatile unsigned long *)(GPIO_MFPR_ADDR(5)) = mfpr_reg_data;
            #else
                //rx
                mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(2)); //GPIO2--pin28
                mfpr_reg_data = mfpr_reg_data & ~(0x1fff) | 0x1c04;
                *(volatile unsigned long *)(GPIO_MFPR_ADDR(2)) = mfpr_reg_data;
                //tx
                mfpr_reg_data = *(volatile unsigned long *)(GPIO_MFPR_ADDR(3)); //GPIO3--pin29
                mfpr_reg_data = mfpr_reg_data & ~(0x1fff) | 0x1c04;
                *(volatile unsigned long *)(GPIO_MFPR_ADDR(3)) = mfpr_reg_data;  
            #endif  
            break;

		default:
			break;
	}
}

int quec_uart_wakeup_mode_enable(UART_Port port)
{
    uart_wakeup_mode_open[port]=1;
    return 0;
}
int quec_uart_wakeup_mode_disable(UART_Port port)
{
    uart_wakeup_mode_open[port]=0;
    return 0;
}

char quec_uart_get_wakeup_mode_flag(UART_Port port)
{
    return uart_wakeup_mode_open[port];
}
int quec_uart_open(UART_Port port, QUEC_UART_BAUD_E baudrate, QUEC_UART_FLOWCTRL_E flow_ctrl)
{
    int ret = 0;
    UARTConfiguration *UART_CONFIG = NULL;
    
    QUEC_CHECK_UART_PORT_VALID(port);
    
	if (quec_uart_data[port].uart_state) {
    	uart_dbg_log("The serial port has been opened \r\n");
    	return QUEC_UART_ALREAD_OPEN;
	}
    
    quec_uart_gpio_config(port, flow_ctrl);
    
	UART_CONFIG  = &uart_default_config[port];
	UART_CONFIG->baudRate = (UART_BaudRates)baudrate;
	if(UART_PORT_STUART == port)//Only Main UART support flow_ctrl
	UART_CONFIG->flowControl = (unsigned char)flow_ctrl;
	else	
	UART_CONFIG->flowControl = (unsigned char)QUEC_FC_NONE;
	ret = quec_uart_config(port, uart_default_config[port]);
	if (ret) {
		uart_dbg_log("config uart failed \n");
		return QUEC_UART_OPEN_FAILED;
	}
    
     switch (port)
    {
        case UART_PORT_FFUART:
            quec_uart_data[port].tx_rb = __kfifo_rb_create(QUEC_DEBUGUART_TX_BUFF_SIZE);
            quec_uart_data[port].rx_rb = __kfifo_rb_create(QUEC_DEBUGUART_RX_BUFF_SIZE);
            break;
        case UART_PORT_BTUART:
            quec_uart_data[port].tx_rb = __kfifo_rb_create(QUEC_BTUART_TX_BUFF_SIZE);
            quec_uart_data[port].rx_rb = __kfifo_rb_create(QUEC_BTUART_RX_BUFF_SIZE);
            break;
        case UART_PORT_STUART:
            quec_uart_data[port].tx_rb = __kfifo_rb_create(QUEC_MAINUART_TX_BUFF_SIZE);
            quec_uart_data[port].rx_rb = __kfifo_rb_create(QUEC_MAINUART_RX_BUFF_SIZE);
            break;
		case UART_PORT_U4UART:
            quec_uart_data[port].tx_rb = __kfifo_rb_create(QUEC_UART_U4_TX_BUFF_SIZE);
            quec_uart_data[port].rx_rb = __kfifo_rb_create(QUEC_UART_U4_RX_BUFF_SIZE);
            break;
        default:
		    return QUEC_UART_ILLEGAL_PORT;
    }
     
    if(quec_uart_data[port].tx_rb !=NULL && quec_uart_data[port].rx_rb != NULL)
    {
        quec_uart_data[port].IsSendingStatus=FALSE;
        quec_uart_data[port].uart_state = TRUE;
    	uart_dbg_log("uart open port=%d,success",port);
		quec_uart_data[port].uart_state = 1;
        return QUEC_UART_SUCCESS;
    }
    else
    {
        uart_dbg_log("uart open port=%d,fail",port);
		if(quec_uart_data[port].tx_rb !=NULL)
			__kfifo_rb_destroy(&quec_uart_data[port].tx_rb);
		if(quec_uart_data[port].rx_rb !=NULL)
			__kfifo_rb_destroy(&quec_uart_data[port].rx_rb);
        return QUEC_UART_RB_CFG_FAILED;
    }
}

int quec_uart_close(UART_Port port)
{

	QUEC_CHECK_UART_PORT_VALID(port);
	if (quec_uart_data[port].uart_state) {
		/* Close UART port. */
		UARTClose(port);

		quec_uart_data[port].uart_state = 0;
		__kfifo_rb_destroy(&quec_uart_data[port].tx_rb);
		__kfifo_rb_destroy(&quec_uart_data[port].rx_rb);
	}
    
	return QUEC_UART_SUCCESS;
}

void quec_uart_register_cb(UART_Port port, uart_callback uart_cb)
{
	QUEC_CHECK_UART_PORT_VALID_VOID(port);
	quec_uart_data[port].uart_cb = uart_cb;
    quec_uart_data[port].uart_cb_ex = NULL;
}

void quec_uart_register_cb_ex(UART_Port port, uart_callback_ex uart_cb, void *priavte)
{
    QUEC_CHECK_UART_PORT_VALID_VOID(port);
    quec_uart_data[port].uart_cb_ex = uart_cb;
    quec_uart_data[port].callback_private_argv = priavte;
    quec_uart_data[port].uart_cb = NULL;
}
#endif

int quec_uart_get_dcbconfig(UART_Port port, quec_uart_config_t *dcb)
{
	QUEC_CHECK_UART_PORT_VALID(port);
	
	if (NULL == dcb) {
		uart_dbg_log("set dcbconfig failed, the dcb is NULL \n");
		return -1;
	}

	if (!_UARTPorts[port].config.baudRate) {
		_UARTPorts[port].config  = uart_default_config[port];
	}

	dcb->baudrate 	= _UARTPorts[port].config.baudRate;
	dcb->data_bit 	= _UARTPorts[port].config.numDataBits;
	dcb->stop_bit   = _UARTPorts[port].config.stopBits;
	dcb->parity_bit = _UARTPorts[port].config.parityBitType;
	dcb->flow_ctrl  = _UARTPorts[port].config.flowControl;

	return 0;
}

int quec_uart_set_dcbconfig(UART_Port port, quec_uart_config_t *dcb)
{
	int ret = 0;
   
    UARTConfiguration *UART_CONFIG = NULL;
    
	QUEC_CHECK_UART_PORT_VALID(port);
	
	if (NULL == dcb) {
		uart_dbg_log("set dcbconfig failed, the dcb is NULL \n");
		return QUEC_UART_DCB_PRAM_ERR;
	}

	UART_CONFIG                 = &uart_default_config[port];
	UART_CONFIG->baudRate 		= (UART_BaudRates)dcb->baudrate;
	UART_CONFIG->numDataBits 	= (UART_WordLen)dcb->data_bit;
	UART_CONFIG->stopBits 		= (UART_StopBits)dcb->stop_bit;
	UART_CONFIG->parityBitType   = (UART_ParityTBits)dcb->parity_bit;
    if(port == UART_PORT_STUART){ 
	UART_CONFIG->flowControl 	= (unsigned char)dcb->flow_ctrl;
    }else{
    UART_CONFIG->flowControl     = (unsigned char )QUEC_FC_NONE;
    }
    
#ifdef QUECTEL_OPEN_CPU
    quec_uart_gpio_config(port, dcb->flow_ctrl);
#endif

	ret = quec_uart_config(port, uart_default_config[port]);
	if (ret) {
		uart_dbg_log("config uart failed \n");
		return QUEC_UART_DCB_CFG_ERR;
	}

	return QUEC_UART_SUCCESS;
}

#if defined (QUECTEL_OPEN_CPU) || defined (HX_GNSS_SUPPORT) || defined (QUEC_GPS_SUPPORT)  || defined(QUEC_FGM842D_WIFI_SUPPORT)


void quec_uart_flush_fifo(UART_Port port)
{
    QUEC_CHECK_UART_PORT_VALID(port);
    
    
    /*step1 清除软件fifo*/    
    if (quec_uart_data[port].tx_rb) {
        switch (port)
        {
            case UART_PORT_FFUART:
            quec_uart_data[port].tx_rb->size = QUEC_DEBUGUART_TX_BUFF_SIZE;
            quec_uart_data[port].tx_rb->wpos = 0;
            quec_uart_data[port].tx_rb->rpos = 0;
            if (quec_uart_data[port].tx_rb->data) {
            memset(quec_uart_data[port].tx_rb->data, 0, QUEC_DEBUGUART_TX_BUFF_SIZE);
            }
            break;
            
            case UART_PORT_BTUART:
            quec_uart_data[port].tx_rb->size = QUEC_BTUART_TX_BUFF_SIZE;
            quec_uart_data[port].tx_rb->wpos = 0;
            quec_uart_data[port].tx_rb->rpos = 0;
            if (quec_uart_data[port].tx_rb->data) {
            memset(quec_uart_data[port].tx_rb->data, 0, QUEC_BTUART_TX_BUFF_SIZE);
            }
            break;
            
            case UART_PORT_STUART:
            quec_uart_data[port].tx_rb->size = QUEC_MAINUART_TX_BUFF_SIZE;
            quec_uart_data[port].tx_rb->wpos = 0;
            quec_uart_data[port].tx_rb->rpos = 0;
            if (quec_uart_data[port].tx_rb->data) {
            memset(quec_uart_data[port].tx_rb->data, 0, QUEC_MAINUART_TX_BUFF_SIZE);
            }
            break;

        }
    }
    
    if (quec_uart_data[port].rx_rb) {
        switch (port)
        {
            case UART_PORT_FFUART:
            quec_uart_data[port].rx_rb->size = QUEC_DEBUGUART_TX_BUFF_SIZE;
            quec_uart_data[port].rx_rb->wpos = 0;
            quec_uart_data[port].rx_rb->rpos = 0;
            if (quec_uart_data[port].rx_rb->data) {
            memset(quec_uart_data[port].rx_rb->data, 0, QUEC_DEBUGUART_TX_BUFF_SIZE);
            }
            break;
            
            case UART_PORT_BTUART:
            quec_uart_data[port].rx_rb->size = QUEC_BTUART_TX_BUFF_SIZE;
            quec_uart_data[port].rx_rb->wpos = 0;
            quec_uart_data[port].rx_rb->rpos = 0;
            if (quec_uart_data[port].rx_rb->data) {
            memset(quec_uart_data[port].rx_rb->data, 0, QUEC_BTUART_TX_BUFF_SIZE);
            }
            break;
            
            case UART_PORT_STUART:
            quec_uart_data[port].rx_rb->size = QUEC_MAINUART_TX_BUFF_SIZE;
            quec_uart_data[port].rx_rb->wpos = 0;
            quec_uart_data[port].rx_rb->rpos = 0;
            if (quec_uart_data[port].rx_rb->data) {
            memset(quec_uart_data[port].rx_rb->data, 0, QUEC_MAINUART_TX_BUFF_SIZE);
            }
            break;
        }
    }

   /* step2 清除硬件fifo */
	UARTClearRxTxFIFO(port);
}

void quec_aotu_flow_enable(UART_Port portNumber)
{
    UINT32 address = _UARTHwAddresses[portNumber];
	if((quec_check_uart_is_open(portNumber))&&(_UARTPorts[portNumber].config.flowControl == 1))
	{
    HW_UART_WRITE_MCR(address,(MCR_AFE|MCR_FORCE_RTS|MCR_ENABLE_INTS));
    }
}

void quec_aotu_flow_Disable(UART_Port portNumber)
{
    UINT32 address = _UARTHwAddresses[portNumber];
    unsigned long val = 0;
	if((quec_check_uart_is_open(portNumber))&&(_UARTPorts[portNumber].config.flowControl == 1))
	{
    HW_UART_READ_MCR(address,val);
    val &= ~(MCR_AFE|MCR_FORCE_RTS|MCR_ENABLE_INTS);
    HW_UART_WRITE_MCR(address,val);
	}
}
unsigned char quec_check_uart_tx_fifo_empty(UART_Port portNumber)
{
    unsigned int lineStatus;
    QUEC_CHECK_UART_PORT_VALID(portNumber);
    unsigned int address = _UARTHwAddresses[portNumber];
    HW_UART_READ_LSR(address, lineStatus);
	//wait for tx fifo and shift register empty
    if ( lineStatus & LSR_EMP_DATA   )  // 64 byte in the FIFO are free
        return 1;//TBD!!!// fifo empty
    else 
        return 0;
}

unsigned char quec_check_uart_rx_fifo_busy(UART_Port portNumber)
{
	unsigned int lineStatus;
	unsigned int address = _UARTHwAddresses[portNumber];
	if((quec_uart_data[portNumber].uart_state)&&(_UARTPorts[portNumber].config.flowControl == (unsigned char)QUEC_FC_HW))
	{
		/* Read Line Status. */
	    HW_UART_READ_LSR(address, lineStatus);
	    if (lineStatus & LSR_DATA_READY)  // LSR_DATA_READY == 0x01
	    	return 1;//rx fifo have data
	    else
		{
			if(__kfifo_rb_is_empty(quec_uart_data[portNumber].rx_rb))
				return 0;
			else
				return 1;//rx rb have data
		}
	}
	else
		return 0;//UART not open,think rx not busy
}
#ifdef QUEC_UART_DMA_TX_ENABLE
/*同步发送接口，此接口数据未发送完成会阻塞线程*/
int quec_uart_write_sync(UART_Port port, unsigned char *data, int len)
{
    int send_len = 0;
    unsigned short unsend_len = len;
    while(send_len < len) {
        /*若对端流控被拉起，此函数将一直阻塞直到流控被去使能*/
        QUEC_UART_DMAWrite(port, (data+send_len), &unsend_len);
        send_len = len - unsend_len;
    }
    return len;
}
#endif
int quec_uart_write(UART_Port port, unsigned char *data, int len)
{
    int send_len = QUEC_UART_SUCCESS;
	quec_uart_msg_t uart_msg={0};
    unsigned int reg = 0;
    unsigned int address =0;
    
    QUEC_CHECK_UART_PORT_VALID(port);

    if ((NULL == data) || (len <= 0) || (NULL==quec_uart_data[port].tx_rb)) {
	    uart_dbg_log("write uart data, invalid param, len=%d,rb=%#x,port=%d\n", len,quec_uart_data[port].tx_rb,port);
		return QUEC_UART_WRITE_PRAM_ERR;
    }
    if (quec_debuguart_tx_msg_ref == NULL || quec_btuart_tx_msg_ref == NULL || quec_mainuart_tx_msg_ref == NULL)
    {
        return QUEC_UART_OPEN_FAILED;
    }
    /*只有设置了硬件流控会去判断流控脚状态*/
    if(uart_default_config[port].flowControl == QUEC_FC_HW)
    {
        address = _UARTHwAddresses[port];
    	HW_UART_READ_MSR(address,reg); //read cts level from MSR register.
    	if((reg & 0X10)==0)
    	{ 
            /*此时dma已经暂停，上层来数据不应再发往物理层，同时通知应用层cts被拉高*/
            send_len =  QUEC_UART_CTS_HIGH ;   
        }
    }
    
    if(send_len == QUEC_UART_SUCCESS)
    {
        uart_msg.direction = quec_uart_tx;
        uart_msg.uart_port = port;

        send_len = __kfifo_rb_write(quec_uart_data[port].tx_rb, data, len);
        
        uart_msg.data_len = send_len;
        //uart_dbg_log("%s,port=%d,send_len=%d;",__func__,port,send_len);
        
        if(send_len > 0)
            switch (port)
            {
                case UART_PORT_FFUART:
                    quec_rtos_queue_release(quec_debuguart_tx_msg_ref, sizeof(quec_uart_msg_t), (unsigned char *)&uart_msg, 10);
                    break;
                case UART_PORT_BTUART:
                    quec_rtos_queue_release(quec_btuart_tx_msg_ref, sizeof(quec_uart_msg_t), (unsigned char *)&uart_msg, 10);
                    break;
                case UART_PORT_STUART:
                    quec_rtos_queue_release(quec_mainuart_tx_msg_ref, sizeof(quec_uart_msg_t), (unsigned char *)&uart_msg, 10);
                    break;                
                case UART_PORT_U4UART:
                    quec_rtos_queue_release(quec_uart_u4_tx_msg_ref, sizeof(quec_uart_msg_t), (u8 *)&uart_msg, 10);
                    break;
                default:
                    send_len = QUEC_UART_ILLEGAL_PORT;
                    break;
            }
        else
            send_len = QUEC_UART_WRITE_ERR; 
    }
    
    return send_len;
}

int quec_uart_read_fifo_to_rb(UART_Port port, unsigned char *data, int len)
{
	unsigned int read_len = 0;
	
	QUEC_CHECK_UART_PORT_VALID(port);
    
    if ((NULL == data) || (len <= 0)) {
        uart_dbg_log("read uart fifo data, uart data is null or len is less 0, len=%d \n", len);
		return -1;
    }
    
	if (quec_uart_data[port].rx_rb && quec_uart_data[port].rx_rb->data) {
		read_len = __kfifo_rb_write(quec_uart_data[port].rx_rb, data, len);
	}	

	return read_len;
}

int quec_uart_fc_high_threshold(UART_Port port)
{
    unsigned int ret=0;
    switch (port)
    {
        case UART_PORT_FFUART:
            ret=QUEC_DEBUGUART_FC_HIGH_THRESHOLD;
        break;
        
        case UART_PORT_BTUART:
            ret=QUEC_BTUART_FC_HIGH_THRESHOLD;
        break;
        
        case UART_PORT_STUART:
            ret=QUEC_MAINUART_FC_HIGH_THRESHOLD;
        break;
            
        default:
            ret=QUEC_UART_ILLEGAL_PORT;
        break;
    }
    return ret;
}
unsigned int quec_uart_fc_low_threshold(UART_Port port)
{
    unsigned int ret=0;
    switch (port)
    {
        case UART_PORT_FFUART:
            ret=QUEC_DEBUGUART_FC_LOW_THRESHOLD;
        break;
        
        case UART_PORT_BTUART:
            ret=QUEC_BTUART_FC_LOW_THRESHOLD;
        break;
        
        case UART_PORT_STUART:
            ret=QUEC_MAINUART_FC_LOW_THRESHOLD;
        break;
            
        default:
            ret=QUEC_UART_ILLEGAL_PORT;
        break;
    }
    return ret;

}
#endif

static unsigned int  quec_selfadatpt_baud_array[] = 
{
    4800,
    9600, 
    19200,
    38400,
    57600,
    115200,
    230400,
    460800,
    921600
};

void quec_uart_baud_selfadatpt_enable(UART_Port port)
{
    UINT32 address= _UARTHwAddresses[port] ;
    HW_UART_WRITE_ABR(address, UART_ABR_ABE|UART_ABR_ABUP|UART_ABR_ABLIE|UART_ABR_ABT);
}
void quec_uart_baud_selfadatpt_disable(UART_Port port,unsigned int *bandrate)
{
    unsigned int real_band = QUEC_UART_BAUD_300;
    UINT32 address= _UARTHwAddresses[port] ;
    unsigned int div = 0,i;
    unsigned int current_band = 0;
    unsigned int deviation_band=0;
    unsigned int min_deviation_band=0xFFFFFFFF;
	quec_uart_config_t uart_dcb = {0};
    HW_UART_READ_ACR(address,div);
    current_band=UART_CLOCK*2/(div&0XFFFF);
    for(i = 0; i < sizeof(quec_selfadatpt_baud_array)/sizeof(unsigned int); i++)
    {
        if(current_band > quec_selfadatpt_baud_array[i])
        {
            deviation_band = current_band - quec_selfadatpt_baud_array[i];
        }
        else 
        {
            deviation_band = quec_selfadatpt_baud_array[i] - current_band;
        }
        if(deviation_band<min_deviation_band)
        {
            min_deviation_band = deviation_band;
            real_band = quec_selfadatpt_baud_array[i];
        }
    } 
    HW_UART_WRITE_ABR(address, 0);
    *bandrate = real_band;
	quec_uart_get_dcbconfig(port, &uart_dcb);
	if(real_band != uart_dcb.baudrate)
    {
        uart_dcb.baudrate = real_band;
        quec_uart_set_dcbconfig(port,&uart_dcb);//设置自适应得到的波特率，防止自适应误差过大造成串口乱码
    }	
}

#if defined (QUECTEL_OPEN_CPU) || defined (HX_GNSS_SUPPORT) || defined (QUEC_GPS_SUPPORT) || defined(QUEC_FGM842D_WIFI_SUPPORT)


int quec_move_uart_buffer_to_rb(UART_Port port, unsigned char *dma_buffer, unsigned int move_len)
{
    int trans_len = 0;
    int ret = 0;
    unsigned int rb_data_len = 0;
    trans_len = quec_uart_read_fifo_to_rb(port, (unsigned char *)dma_buffer,move_len);
    rb_data_len = __kfifo_rb_data_len(quec_uart_data[port].rx_rb);
    if(trans_len != move_len)
    {
        ret = -1;
        goto err;
    }
    
    //If the flow control function is not enabled and the amount of data in a packet is very large, the serial port is stuck //pony@2021-07-23
    if((_UARTPorts[port].config.flowControl==(unsigned char)QUEC_FC_HW))
    {
        if(rb_data_len > quec_uart_fc_high_threshold(port))//到达流控阈值
        {
            switch(port)
            {
                /*目前仅主串口支持流控机制*/
                case UART_PORT_STUART : 
                    g_stop_main_uart_f = 1 ;
                    ret = 1;
                    break;
                case UART_PORT_FFUART :
                case UART_PORT_BTUART : 
                default:
                    ret = 0;
                    break;
            }
        }
    }
    else 
        ret = 0;
err:
    return ret;
}

int quec_get_uart_rb_state(UART_Port port)
{
    int  ret = 0;
    if((_UARTPorts[port].config.flowControl==(unsigned char)QUEC_FC_HW))
    {
        switch(port)
        {
            case UART_PORT_STUART :
                ret=g_stop_main_uart_f;
                break;
            case UART_PORT_FFUART :
            case UART_PORT_BTUART : 
            default:
                ret = 0;
                break;
        }
    }
    else 
        ret = 0;
    return ret;
}

int quec_uart_read(UART_Port port, unsigned char *data, int len)
{
    int read_len = 0;
    unsigned int rb_data_len = 0;
    QUEC_CHECK_UART_PORT_VALID(port);

	if (quec_uart_data[port].rx_rb && data && (len>0)) {
		read_len = __kfifo_rb_read(quec_uart_data[port].rx_rb, data, len);
        rb_data_len = __kfifo_rb_data_len(quec_uart_data[port].rx_rb);;
        /*如果高限位流控被拉起接收中断会被关闭，此处检测rb到达低限值重新打开接收中断*/
        if((_UARTPorts[port].config.flowControl==(unsigned char)QUEC_FC_HW) &&(quec_get_uart_rb_state(port) == 1))
        {     
            if(rb_data_len <= quec_uart_fc_low_threshold( port))//到达流控下限值
            {
                switch(port)
                {
                    case UART_PORT_STUART : //目前只有主串口支持流控机制
                        g_stop_main_uart_f = 0 ;
                        ENABLE_UART_INT(port, IER_TIME_OUT|IER_RCV_DATA_AVAILABLE);  //start interrupt 
                        break;
                    case UART_PORT_FFUART :
                    case UART_PORT_BTUART : 
                    default:
                        break;
                }
            }
        }
        return read_len;
	}
	return QUEC_UART_READ_ERR;
}

unsigned char quec_uart_is_sending(UART_Port port)
{
    QUEC_CHECK_UART_PORT_VALID(port);

    if((quec_uart_data[port].IsSendingStatus ) || (!__kfifo_rb_is_empty(quec_uart_data[port].tx_rb)) || (!quec_check_uart_tx_fifo_empty(port)))
		return QUEC_UART_IS_SENDING;
    else
        return  QUEC_UART_NOT_SENDING;
}

unsigned int quec_rb_free_space(UART_Port port)
{
    QUEC_CHECK_UART_PORT_VALID(port);
	return __kfifo_rb_free_space(quec_uart_data[port].rx_rb);
}

unsigned char quec_check_uart_is_open(UART_Port port)
{
    QUEC_CHECK_UART_PORT_VALID(port);
	return quec_uart_data[port].uart_state;
}

unsigned int quec_uart_get_rxrb_data_len(UART_Port port)
{
    QUEC_CHECK_UART_PORT_VALID(port);
	if (quec_uart_data[port].rx_rb) {
		return __kfifo_rb_data_len(quec_uart_data[port].rx_rb);
	}
	return 0;
}

void quec_uart_send_msg(UART_Port port)
{
	quec_uart_msg_t uart_msg;

    uart_msg.direction = 1;
    uart_msg.uart_port = port;
    uart_msg.data_len = __kfifo_rb_data_len(quec_uart_data[port].rx_rb);
	
    if (quec_uart_rx_msg_ref && (quec_uart_data[port].uart_cb || quec_uart_data[port].uart_cb_ex) && (uart_msg.data_len > 0)) 
    {
        quec_rtos_queue_release(quec_uart_rx_msg_ref, sizeof(quec_uart_msg_t), (unsigned char *)&uart_msg, QUEC_NO_WAIT);
    }
    return;
}

static void quec_uart_rx_msg_process(void * argv)
{
	int ret = -1;
	unsigned int transfer_len = 0; 
    quec_uart_msg_t uart_msg;
	unsigned char *data = NULL;
    unsigned char ql_uart_port = 0;


	while (1) {
		ret = quec_rtos_queue_wait(quec_uart_rx_msg_ref, (unsigned char *)&uart_msg, sizeof(quec_uart_msg_t), (unsigned int)QUEC_WAIT_FOREVER);
		if (ret) {
			return;
		}
        //miles.ma 20221121将CB传递给APP测试的port参数，由kernel侧UART_PORT_U4UART(3)转换为app侧的QL_U4_UART_PORT(4)
        if(UART_PORT_U4UART == uart_msg.uart_port)
        {
            ql_uart_port = QUEC2QL_U4_UART_PORT;           
        }
        else
        {
            ql_uart_port =  uart_msg.uart_port; 
        }

        switch (uart_msg.direction) 
        {
			case quec_uart_rx:	//rx

			   // test_log("quec_uart_rx\n");
				if (NULL != quec_uart_data[uart_msg.uart_port].uart_cb) {
					quec_uart_data[uart_msg.uart_port].uart_cb((UART_Port)ql_uart_port, (void *)&uart_msg.data_len);
				}
            	if (NULL != quec_uart_data[uart_msg.uart_port].uart_cb_ex) {
				quec_uart_data[uart_msg.uart_port].uart_cb_ex((UART_Port)ql_uart_port, uart_msg.data_len, quec_uart_data[uart_msg.uart_port].callback_private_argv);
			    }
                
			default:
				break;
		}
	}
}

/*因为串口cts流控会阻塞dma 导致此线程会被阻塞，所以在dma模式下每个串口tx需要单独的线程去处理*/
static void quec_debuguart_tx_msg_process(void * argv)
{
	int ret = -1;
	unsigned int transfer_len = 0;
	unsigned int send_len = 0;
    unsigned short unsend_len = 0;
	quec_uart_msg_t uart_msg;
	unsigned char *usb_data = NULL;
    unsigned char *tx_data = NULL;

    
    while (1) {
    	ret = quec_rtos_queue_wait(quec_debuguart_tx_msg_ref, (unsigned char *)&uart_msg, sizeof(quec_uart_msg_t), (unsigned int)QUEC_WAIT_FOREVER);
    	if (ret) {
    		return;
    	}
        
        quec_uart_data[uart_msg.uart_port].IsSendingStatus=TRUE;
        
        tx_data = malloc(uart_msg.data_len);
        
    	switch (uart_msg.direction) {
            
    	case quec_uart_tx:
            {
                transfer_len = __kfifo_rb_read(quec_uart_data[uart_msg.uart_port].tx_rb, tx_data,uart_msg.data_len);
    			send_len = 0;
    			unsend_len = (unsigned short)transfer_len;
         
                
                /*如果tx_fifo为空直接退出不发数据*/
                
                if(transfer_len <= 0)
                    break;
                    
    			while(send_len < transfer_len) {
                    //uart_dbg_log("#b%s port=%d,trs=%u,sdl=%u,unst=%u\r\n",__func__,uart_msg.uart_port,transfer_len,send_len,unsend_len);
                    #ifdef QUEC_UART_DMA_TX_ENABLE
                    QUEC_UART_DMAWrite(uart_msg.uart_port, (tx_data+send_len), &unsend_len);
                    #endif
                    //uart_dbg_log("##QUEC_UART_DMAWrite,ret=%d;",ret);
                    send_len = transfer_len - unsend_len;
                    //uart_dbg_log("#c%s port=%d,trs=%u,sdl=%u,unst=%u\r\n",__func__,uart_msg.uart_port,transfer_len,send_len,unsend_len);
    			}
                quec_uart_data[uart_msg.uart_port].IsSendingStatus=FALSE;
            }
            break;
                
    	default:
    		break;
            
    	}
       free(tx_data);
    }
        
}

/*因为串口cts流控会阻塞dma 进而导致此线程会被阻塞，所以在dma模式下每个串口tx需要单独的线程去处理*/
static void quec_btuart_tx_msg_process(void * argv)
{
	int ret = -1;
	unsigned int transfer_len = 0;
	unsigned int send_len = 0;
    unsigned short unsend_len = 0;
	quec_uart_msg_t uart_msg;
	unsigned char *usb_data = NULL;
    unsigned char *tx_data = NULL;

    
    while (1) {
    	ret = quec_rtos_queue_wait(quec_btuart_tx_msg_ref, (unsigned char *)&uart_msg, sizeof(quec_uart_msg_t), (unsigned int)QUEC_WAIT_FOREVER);
    	if (ret) {
    		return;
    	}
        
        quec_uart_data[uart_msg.uart_port].IsSendingStatus=TRUE;
        
        tx_data = malloc(uart_msg.data_len);
        
    	switch (uart_msg.direction) {
            
    	case quec_uart_tx:
            {
                transfer_len = __kfifo_rb_read(quec_uart_data[uart_msg.uart_port].tx_rb, tx_data,uart_msg.data_len);
    			send_len = 0;
    			unsend_len = (unsigned short)transfer_len;
         
                
                /*如果tx_fifo为空直接退出不发数据*/
                
                if(transfer_len <= 0)
                    break;
                    
    			while(send_len < transfer_len) {
                    //uart_dbg_log("#b%s port=%d,trs=%u,sdl=%u,unst=%u\r\n",__func__,uart_msg.uart_port,transfer_len,send_len,unsend_len);
                    #ifdef QUEC_UART_DMA_TX_ENABLE
                    ret = QUEC_UART_DMAWrite(uart_msg.uart_port, (tx_data+send_len), &unsend_len);
                    #endif
                    //uart_dbg_log("##QUEC_UART_DMAWrite,ret=%d;",ret);
                    send_len = transfer_len - unsend_len;
                    //uart_dbg_log("#c%s port=%d,trs=%u,sdl=%u,unst=%u\r\n",__func__,uart_msg.uart_port,transfer_len,send_len,unsend_len);
    			}
                quec_uart_data[uart_msg.uart_port].IsSendingStatus=FALSE;
            }
            break;
                
    	default:
    		break;
            
    	}
       free(tx_data);
    }
        
}

/*因为串口cts流控会阻塞dma 导致此线程会被阻塞，所以在dma模式下每个串口tx需要单独的线程去处理*/
static void quec_mainuart_tx_msg_process(void * argv)
{
	int ret = -1;
	unsigned int transfer_len = 0;
	unsigned int send_len = 0;
    unsigned short unsend_len = 0;
	quec_uart_msg_t uart_msg;
	unsigned char *usb_data = NULL;
    unsigned char *tx_data = NULL;
    
    while (1) {
    	ret = quec_rtos_queue_wait(quec_mainuart_tx_msg_ref, (unsigned char *)&uart_msg, sizeof(quec_uart_msg_t), (unsigned int)QUEC_WAIT_FOREVER);
    	if (ret) {
    		return;
    	}
        
        quec_uart_data[uart_msg.uart_port].IsSendingStatus=TRUE;
        
         tx_data = malloc(uart_msg.data_len);
        
    	switch (uart_msg.direction) {
            
    	case quec_uart_tx:
            {
                
                transfer_len = __kfifo_rb_read(quec_uart_data[uart_msg.uart_port].tx_rb, tx_data,uart_msg.data_len);
    			send_len = 0;
    			unsend_len = (unsigned short)transfer_len;
                //uart_dbg_log("%s",tx_data);
                /*如果tx_fifo为空直接退出不发数据*/
                
                if(transfer_len <= 0)
                    break;
                    
    			while(send_len < transfer_len) {
                    //uart_dbg_log("#b%s port=%d,trs=%u,sdl=%u,unst=%u\r\n",__func__,uart_msg.uart_port,transfer_len,send_len,unsend_len);
                    #ifdef QUEC_UART_DMA_TX_ENABLE
                    ret = QUEC_UART_DMAWrite(uart_msg.uart_port, (tx_data+send_len), &unsend_len);
                    #endif
                    //uart_dbg_log("##QUEC_UART_DMAWrite,ret=%d;",ret);
                    send_len = transfer_len - unsend_len;
                    //uart_dbg_log("#c%s port=%d,trs=%u,sdl=%u,unst=%u\r\n",__func__,uart_msg.uart_port,transfer_len,send_len,unsend_len);
    			}
                quec_uart_data[uart_msg.uart_port].IsSendingStatus=FALSE;
            }
            break;
                
    	default:
    		break;
            
    	}
       free(tx_data);
    }
        
}

static void quec_uart_u4_tx_msg_process(void * argv)
{
	int ret = -1;
	unsigned int transfer_len = 0;
	unsigned int send_len = 0, unsend_len = 0;
	quec_uart_msg_t uart_msg;
    unsigned char *tx_data = NULL;

	while (1) 
	{
		ret = quec_rtos_queue_wait(quec_uart_u4_tx_msg_ref, (unsigned char *)&uart_msg, sizeof(quec_uart_msg_t), (unsigned int)QUEC_WAIT_FOREVER);
		if (ret) {
			return;
		}
        
        quec_uart_data[uart_msg.uart_port].IsSendingStatus=TRUE;
        
         tx_data = malloc(uart_msg.data_len);
        
    	 switch (uart_msg.direction) {
            
    	 case quec_uart_tx:
            {
                
                transfer_len = __kfifo_rb_read(quec_uart_data[uart_msg.uart_port].tx_rb, tx_data,uart_msg.data_len);
    			send_len = 0;
    			unsend_len = (unsigned short)transfer_len;
                //uart_dbg_log("%s",tx_data);
                /*如果tx_fifo为空直接退出不发数据*/
                
                if(transfer_len <= 0)
                    break;
                    
    			while(send_len < transfer_len) {
                    //uart_dbg_log("#b%s port=%d,trs=%u,sdl=%u,unst=%u\r\n",__func__,uart_msg.uart_port,transfer_len,send_len,unsend_len);
                    #ifdef QUEC_U4_UART_DMA_TX_ENABLE
                    ret = QUEC_UART_DMAWrite(uart_msg.uart_port, (tx_data+send_len), &unsend_len);
                    #endif
                    //uart_dbg_log("##QUEC_UART_DMAWrite,ret=%d;",ret);
                    send_len = transfer_len - unsend_len;
                    //uart_dbg_log("#c%s port=%d,trs=%u,sdl=%u,unst=%u\r\n",__func__,uart_msg.uart_port,transfer_len,send_len,unsend_len);
    			}
                quec_uart_data[uart_msg.uart_port].IsSendingStatus=FALSE;
            }
            break;
			default:
				break;
		}
       free(tx_data);	
    }
}

int quec_uart_driver_init(void)
{
	OSA_STATUS status = OS_SUCCESS;
    
	status = quec_rtos_queue_create(&quec_uart_rx_msg_ref, sizeof(quec_uart_msg_t), 256); 
    ASSERT(status == OS_SUCCESS);
    status = quec_rtos_queue_create(&quec_debuguart_tx_msg_ref, sizeof(quec_uart_msg_t), 256); 
    ASSERT(status == OS_SUCCESS);	
    status = quec_rtos_queue_create(&quec_btuart_tx_msg_ref, sizeof(quec_uart_msg_t), 256); 
    ASSERT(status == OS_SUCCESS);	
    status = quec_rtos_queue_create(&quec_mainuart_tx_msg_ref, sizeof(quec_uart_msg_t), 256); 
    ASSERT(status == OS_SUCCESS);	
    /* quec_rtos_task_create  */
    status = quec_rtos_task_create(&quec_uart_rx_task, 2048, 40, "QUARTRx", quec_uart_rx_msg_process, NULL);
    ASSERT(status == OS_SUCCESS);
    status = quec_rtos_task_create(&quec_debuguart_tx_task, 2048, 90, "QUART1Tx", quec_debuguart_tx_msg_process, NULL);
    ASSERT(status == OS_SUCCESS);
    status = quec_rtos_task_create(&quec_btuart_tx_task, 2048, 90, "QUART2Tx", quec_btuart_tx_msg_process, NULL);
    ASSERT(status == OS_SUCCESS);
    status = quec_rtos_task_create(&quec_mainuart_tx_task, 2048, 90, "QUART3Tx", quec_mainuart_tx_msg_process, NULL);
    ASSERT(status == OS_SUCCESS);
    status = quec_rtos_queue_create(&quec_uart_u4_tx_msg_ref, sizeof(quec_uart_msg_t), 256); 
    ASSERT(status == OS_SUCCESS);
    status = quec_rtos_task_create(&quec_uart_u4_tx_task, 2048, 90, "QUART4Tx", quec_uart_u4_tx_msg_process, NULL);
    ASSERT(status == OS_SUCCESS);
	return 0;
}

#endif

