/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#ifndef _QUEC_UART_H_
#define _QUEC_UART_H_

#include "quec_ring_buffer.h"
#include "UART.h"
#ifdef __cplusplus
	 extern "C" {
#endif

typedef void (*uart_callback)(UART_Port port, void *para);
typedef void (*uart_callback_ex)(UART_Port port, int len, void *private);

typedef enum QUEC_UART_FLOWCTRL_ENUM
{
	QUEC_FC_NONE = 0,
	QUEC_FC_HW,
}QUEC_UART_FLOWCTRL_E;

typedef struct quec_uart_msg_struct {
	unsigned char direction;	//TX/RX
	unsigned char uart_port;
	unsigned int data_len;
}quec_uart_msg_t;

typedef struct quec_uart_data_struct
{
    unsigned char uart_state;
    uart_callback uart_cb;
    uart_callback_ex uart_cb_ex;
    void *callback_private_argv;
    quec_ring_buf_t *tx_rb;
    quec_ring_buf_t *rx_rb;
    unsigned char IsSendingStatus;
}quec_uart_data_t;

typedef enum QUEC_UART_BAUD_ENUM
{
	QUEC_UART_BAUD_300 		  = 300,
	QUEC_UART_BAUD_600    	  = 600,
    QUEC_UART_BAUD_1200       = 1200,
    QUEC_UART_BAUD_2400       = 2400,
    QUEC_UART_BAUD_3600       = 3600,
    QUEC_UART_BAUD_4800       = 4800,
    QUEC_UART_BAUD_7200       = 7200,
    QUEC_UART_BAUD_9600       = 9600,
    QUEC_UART_BAUD_14400      = 14400,
    QUEC_UART_BAUD_19200      = 19200,
    QUEC_UART_BAUD_28800      = 28800,
    QUEC_UART_BAUD_38400      = 38400,
    QUEC_UART_BAUD_57600      = 57600,
    QUEC_UART_BAUD_115200     = 115200,
    QUEC_UART_BAUD_230400     = 230400,
    QUEC_UART_BAUD_256000     = 256000,
    QUEC_UART_BAUD_460800     = 460800,
    QUEC_UART_BAUD_921600     = 921600,
	QUEC_UART_BAUD_1000000	  = 1000000,
	QUEC_UART_BAUD_1500000	  = 1500000,
	QUEC_UART_BAUD_1843200	  = 1843200,
	QUEC_UART_BAUD_3686400	  = 3686400,
}QUEC_UART_BAUD_E;
    
typedef enum
{
    quec_uart_tx,
    quec_uart_rx,
}Enum_quec_uart_dir;

typedef enum QUEC_UART_DATABIT_ENUM
{
	QUEC_UART_DATABIT_5,
	QUEC_UART_DATABIT_6,
	QUEC_UART_DATABIT_7,
	QUEC_UART_DATABIT_8,
}QUEC_UART_DATABIT_E;

typedef enum QUEC_UART_STOPBIT_ENUM
{
	QUEC_UART_STOP_1,
	QUEC_UART_STOP_2,
}QUEC_UART_STOPBIT_E;

typedef enum QUEC_UART_PARITYBIT_ENUM
{
	QUEC_UART_PARITY_NONE,
	QUEC_UART_PARITY_EVEN,
	QUEC_UART_PARITY_ODD,
}QUEC_UART_PARITYBIT_E;

typedef struct quec_uart_config_struct
{
	QUEC_UART_BAUD_E baudrate;
	QUEC_UART_DATABIT_E data_bit;
	QUEC_UART_STOPBIT_E stop_bit;
	QUEC_UART_PARITYBIT_E parity_bit;
	QUEC_UART_FLOWCTRL_E flow_ctrl;
}quec_uart_config_t;

enum
{
 QUEC_UART_SUCCESS          =     0,
 QUEC_UART_OPEN_FAILED      =    -1,
 QUEC_UART_ALREAD_OPEN      =    -2,
 QUEC_UART_ONT_OPEN         =    -3,
 QUEC_UART_ILLEGAL_PORT     =    -4,
 QUEC_UART_RB_CFG_FAILED    =    -5,
 QUEC_UART_DCB_PRAM_ERR     =    -6,
 QUEC_UART_DCB_CFG_ERR      =    -7,
 QUEC_UART_WRITE_ERR        =    -8,
 QUEC_UART_WRITE_PRAM_ERR   =    -9,
 QUEC_UART_WRITE_MALLOC_ERR =   -10,
 QUEC_UART_READ_ERR         =   -11,
 QUEC_UART_CTS_HIGH         =   -12,
 QUEC_UART_IS_SENDING       =    1,
 QUEC_UART_NOT_SENDING      =    0
};

typedef enum 
{
	QUEC2QL_DEBUG_UART_PORT,
	QUEC2QL_BT_UART_PORT,
	QUEC2QL_MAIN_UART_PORT,
	QUEC2QL_USB_CDC_PORT,
	QUEC2QL_U4_UART_PORT,
    QUEC2QL_MAX_UART_PORT,
}QUEC2QL_UART_PORT_NUMBER_E;

/***********************************************************************
 *
 * Name:   QUEC_uart_open    
 *
 * Description: 打开对应串口
 *
 * Parameters:  baudrate:设置波特率
 *              flow_ctrl:是否使能流控
 * Returns:     0：打开成功
 *              
 * Notes:
 *
 ***********************************************************************/
int quec_uart_open(UART_Port port, QUEC_UART_BAUD_E baudrate, QUEC_UART_FLOWCTRL_E flow_ctrl);
/***********************************************************************
 *
 * Name:   QUEC_uart_close    
 *
 * Description: 关闭对应串口
 *
 * Parameters:  port:要关闭的port口
 *             
 * Returns:     0：关闭成功
 *              other: faile
 * Notes:
 *
 ***********************************************************************/
int quec_uart_close(UART_Port port);
/***********************************************************************
 *
 * Name:   QUEC_uart_set_dcbconfig   
 *
 * Description: 设置对应串口模式
 *
 * Parameters:  port:对应的串口，cdc口无需设置
 *              dcb:模式对象
 * Returns:     0：send_success
 *              other: faile
 * Notes:
 *
 ***********************************************************************/
int quec_uart_set_dcbconfig(UART_Port port, quec_uart_config_t *dcb);
/***********************************************************************
 *
 * Name:   QUEC_uart_get_dcbconfig   
 *
 * Description: 获取对应串口当前的模式
 *
 * Parameters:  port:要获取模式的串口
 *              dcb:存方模式的内存
 * Returns:     0：send_success
 *              other: faile
 * Notes:
 *
 ***********************************************************************/

int quec_uart_get_dcbconfig(UART_Port port, quec_uart_config_t *dcb);
/***********************************************************************
 *
 * Name:  quec_uart_write  
 *
 * Description: 往外部发送数据
 *
 * Parameters:  data:要发送的数据首地址
 *              len:要发送的数据长度
 * Returns:     0：send_success
 *              other: faile
 * Notes:
 *
 ***********************************************************************/
int quec_uart_write(UART_Port port, unsigned char *data, int len);
/***********************************************************************
 *
 * Name:   quec_uart_read    
 *
 * Description: 接收串口数据
 *
 * Parameters:  data:要接收的数据存放位置首地址
 *              len:要接收的数据长度
 * Returns:     0：send_success
 *              other: faile
 * Notes:
 *
 ***********************************************************************/
int quec_uart_read(UART_Port port, unsigned char *data, int len);
/***********************************************************************
 *
 * Name:   QUEC_uart_register_cb    
 *
 * Description: 注册接收回调不带参数
 *
 * Parameters:  port:注册回调的串口号
 *              uart_cb:客户回调函数
 * Returns:     
 *              
 * Notes:
 *
 ***********************************************************************/
void quec_uart_register_cb(UART_Port port, uart_callback uart_cb);
/***********************************************************************
 *
 * Name:   QUEC_uart_register_cb_ex    
 *
 * Description: 注册回调函数带参
 *
 * Parameters:  port:注册回调的串口号
 *              uart_cb:客户回调函数
 *              private ：参数
 * Returns:     
 *              
 * Notes:
 *
 ***********************************************************************/

void quec_uart_register_cb_ex(UART_Port port, uart_callback_ex uart_cb, void *private);
/***********************************************************************
 *
 * Name:   QUEC_uart_flush_fifo   
 *
 * Description: 清空串口fifo
 *
 * Parameters:  port:要清空的串口fifo端口号
 *              
 * Returns:     none
 *              
 * Notes:
 *
 ***********************************************************************/

void quec_uart_flush_fifo(UART_Port port);

/*****************************************************************
* Function:     QUEC_uart_is_sending 
* 
* Description:
*               Return the status of the serial port is sending data or not.
*
* Parameters:
*               port:
*               [in]   uart port.
* Return:        
*               FALSE, not sending.
*               TRUE,  is sending.
*****************************************************************/
unsigned char quec_uart_is_sending(UART_Port port);
unsigned int quec_uart_get_rx_data_len(UART_Port port);
unsigned char quec_check_uart_is_open(UART_Port port);
int quec_move_uart_buffer_to_rb(UART_Port port, unsigned char *dma_buffer, unsigned int move_len);
int quec_get_uart_rb_state(UART_Port port);
void quec_uart_send_msg(UART_Port port);
int quec_uart_read_fifo_to_rb(UART_Port port, unsigned char *data, int len);
unsigned char quec_check_uart_tx_fifo_empty(UART_Port portNumber);
int quec_uart_driver_init(void);
void quec_uart_baud_selfadatpt_enable(UART_Port port);
void quec_uart_baud_selfadatpt_disable(UART_Port port,unsigned int *bandrate);
void quec_aotu_flow_enable(UART_Port portNumber);
void quec_aotu_flow_Disable(UART_Port portNumber);
int quec_uart_write_sync(UART_Port port, unsigned char *data, int len);
unsigned int quec_uart_get_rxrb_data_len(UART_Port port);
int quec_uart_wakeup_mode_enable(UART_Port port);
int quec_uart_wakeup_mode_disable(UART_Port port);


#ifdef __cplusplus
	} /*"C" */
#endif

#endif /* _QUEC_UART_H_ */


