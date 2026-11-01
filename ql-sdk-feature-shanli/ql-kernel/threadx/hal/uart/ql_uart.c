/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
#include "ql_uart.h"
#include "quec_usb.h"
UART_Port uart_ql_to_quec(QL_UART_PORT_NUMBER_E port)
{
   UART_Port QUEC_UART_PORT = NUMBER_OF_PORTS;
    switch(port)
    {
        case QL_DEBUG_UART_PORT:
            QUEC_UART_PORT = UART_PORT_FFUART;
            break;
        case QL_BT_UART_PORT: 
            QUEC_UART_PORT = UART_PORT_BTUART;
            break;
        case QL_MAIN_UART_PORT:
            QUEC_UART_PORT = UART_PORT_STUART;
            break;
        case QL_U4_UART_PORT:
            QUEC_UART_PORT = UART_PORT_U4UART;
            break;
        default:
            QUEC_UART_PORT = NUMBER_OF_PORTS;
            break;
    }
	return  QUEC_UART_PORT;
}

int ql_uart_open(QL_UART_PORT_NUMBER_E port, QL_UART_BAUD_E baudrate, QL_UART_FLOWCTRL_E flow_ctrl)
{
    int ret = 0;
    #ifdef QUEC_USB_CDC_SUPPORT
    if(QL_USB_CDC_PORT == port)
    {
        ret = quec_usbcdc_open();
        if(ret != 0)
            return QL_UART_OPEN_FAILED ;
        else 
            return QL_UART_SUCCESS ;
    }
    #endif
    UART_Port QUEC_PORT =  uart_ql_to_quec(port);
    
    ret = quec_uart_open(QUEC_PORT, (QUEC_UART_BAUD_E)baudrate, (QUEC_UART_FLOWCTRL_E)flow_ctrl);
    
    return ret;
}

int ql_uart_close(QL_UART_PORT_NUMBER_E port)
{
     int ret = 0;
#ifdef QUEC_USB_CDC_SUPPORT
    if(QL_USB_CDC_PORT == port)
    {
        ret = quec_usbcdc_close();
        if(ret != 0)
            return QL_UART_OPEN_FAILED ;
        else 
            return QL_UART_SUCCESS ;
    }
#endif
     UART_Port QUEC_PORT = uart_ql_to_quec(port);
     
     ret = quec_uart_close(QUEC_PORT);
     
     return ret;
}

int ql_uart_set_dcbconfig(QL_UART_PORT_NUMBER_E port, ql_uart_config_t *dcb)
{
    int ret = 0;
    UART_Port QUEC_PORT = uart_ql_to_quec(port);

    ret = quec_uart_set_dcbconfig(QUEC_PORT, (quec_uart_config_t*)dcb);
    
    return ret;
}

int ql_uart_get_dcbconfig(QL_UART_PORT_NUMBER_E port, ql_uart_config_t *dcb)
{
    int ret = 0;
    UART_Port QUEC_PORT = uart_ql_to_quec(port);
    
    ret = quec_uart_get_dcbconfig(QUEC_PORT,(quec_uart_config_t*)dcb);
    
    return ret;
}

int ql_uart_write(QL_UART_PORT_NUMBER_E port, unsigned char *data, int len)
{
     int ret = 0;
#ifdef QUEC_USB_CDC_SUPPORT
    if(QL_USB_CDC_PORT == port)
    {
        ret = quec_uartcdc_write(data,len);
        if(ret < 0)
            return QL_UART_WRITE_ERR ;
        else 
            return ret ;
    }
#endif
    UART_Port QUEC_PORT = uart_ql_to_quec(port);
    
    ret = quec_uart_write(QUEC_PORT,data,len);
    
    return ret; 
}

int ql_uart_read(QL_UART_PORT_NUMBER_E port, unsigned char *data, int len)
{
    int ret = 0;
#ifdef QUEC_USB_CDC_SUPPORT
    if(QL_USB_CDC_PORT == port)
    {
        ret = quec_usbcdc_read(data,len);
        if(ret < 0)
            return QL_UART_READ_ERR ;
        else 
            return ret ;
    }
#endif
    UART_Port QUEC_PORT = uart_ql_to_quec(port);
    
    ret = quec_uart_read(QUEC_PORT,data,len);
    
    return ret;
}

void ql_uart_register_cb(QL_UART_PORT_NUMBER_E port, uart_callback uart_cb)
{
    int ret = 0;
#ifdef QUEC_USB_CDC_SUPPORT
        if(QL_USB_CDC_PORT == port)
        {
           quec_usbcdc_register_cb(uart_cb);
		   return;
        }
#endif
    UART_Port QUEC_PORT = uart_ql_to_quec(port);
    
    quec_uart_register_cb(QUEC_PORT,uart_cb);
}

void ql_uart_register_cb_ex(QL_UART_PORT_NUMBER_E port, uart_callback_ex uart_cb, void *private)
{
    int ret = 0;
#ifdef QUEC_USB_CDC_SUPPORT
    if(QL_USB_CDC_PORT == port)
    {
       quec_usbcdc_register_cb_ex(uart_cb,private);
	   return;
    }
#endif
    UART_Port QUEC_PORT = uart_ql_to_quec(port);
    
    quec_uart_register_cb_ex(QUEC_PORT, uart_cb, private);
}

void ql_uart_flush_fifo(QL_UART_PORT_NUMBER_E port)
{
    int ret = 0;
    UART_Port QUEC_PORT = uart_ql_to_quec(port);
    
    quec_uart_flush_fifo(QUEC_PORT);
}

unsigned char ql_uart_is_sending(QL_UART_PORT_NUMBER_E port)
{
    unsigned char ret = 0;
    UART_Port QUEC_PORT = uart_ql_to_quec(port); 
    
    ret = quec_uart_is_sending(QUEC_PORT);
    
    return ret;
}

unsigned int ql_uart_get_rxrb_data_len(QL_UART_PORT_NUMBER_E port)
{
    unsigned int ret = 0;
    UART_Port QUEC_PORT = uart_ql_to_quec(port); 
    
    ret = quec_uart_get_rxrb_data_len(QUEC_PORT);
    
    return ret;
}


int ql_uart_write_sync(QL_UART_PORT_NUMBER_E  port, unsigned char *data , int dataLength)
{

	  unsigned int ret = 0;
	  UART_Port QUEC_PORT = uart_ql_to_quec(port);   
	  
	  ret = quec_uart_write_sync(QUEC_PORT,data,dataLength) ;
	  
	  return ret ;
}

int ql_uart_wakeup_mode_enable(QL_UART_PORT_NUMBER_E port)
{
    UART_Port QUEC_PORT = uart_ql_to_quec(port);   
    return quec_uart_wakeup_mode_enable(QUEC_PORT);
}
int ql_uart_wakeup_mode_disable(QL_UART_PORT_NUMBER_E port)
{
    UART_Port QUEC_PORT = uart_ql_to_quec(port);   
    return quec_uart_wakeup_mode_enable(QUEC_PORT);
}

