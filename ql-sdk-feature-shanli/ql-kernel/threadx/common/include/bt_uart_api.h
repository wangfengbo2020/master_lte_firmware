#ifndef __BT_UART_DRV_H__
#define __BT_UART_DRV_H__
#ifndef UART_NEW_VERSION
#include "UART_common_type.h"

#define UART_PORT_0     0
#define UART_PORT_1     1
#define UART_PORT_2     2
#define UART_PORT_3     3
//#define UART_PORT_4     4

typedef int (*BT_UartIsrCb)(uint32 port_id);

typedef enum
{
    bt_uart_rx = 0,
    bt_uart_tx,
    bt_max_dir,
}bt_uartdir;

typedef enum
{
    bt_int_none = 0,
    bt_rx_int,
    bt_tx_int,
    bt_eor_int,
    bt_all_int,
    bt_int_max,
}bt_uartirqtype;

typedef struct
{
  uint32_t port_id;
  uint32_t fifo;
  uint32_t dma;
  uint32_t loopback;
  bt_uartirqtype int_tpye;
  uint32_t highspeed;
  uint32_t flowctrl;
  uint32_t baudrate;
  uint32_t datawidth;
  uint32_t parity;
  BT_UartIsrCb rx_callback;
  BT_UartIsrCb tx_callback;
}bt_uart_cfg;

#define BAUDRATE_9600       9600
#define BAUDRATE_14400      14400
#define BAUDRATE_19200      19200
#define BAUDRATE_38400      38400
#define BAUDRATE_57600      57600
#define BAUDRATE_115200     115200
#define BAUDRATE_230400     230400
#define BAUDRATE_460800     460800
#define BAUDRATE_921600     921600
#define BAUDRATE_1842000    1842000
#define BAUDRATE_3000000    3000000
#define BAUDRATE_3686400    3686400

typedef enum
{
  BT_PARITY_NONE = 0,
  BT_PARITY_ODD = 1,
  BT_PARITY_EVEN = 3,
} BT_PARITY_TYPE;

typedef enum
{
  BT_DATA_5 = 0,
  BT_DATA_6 = 1,
  BT_DATA_7 = 2,
  BT_DATA_8 = 3,
} BT_DATA_WIDTH;

typedef struct
{
  uint32_t base_addr;
  uint32_t apbc_base;
  uint32_t irq;
  uint32_t fpga;
} bt_uart_glb_info;

extern void bt_uart_init (bt_uart_cfg *port);
extern void bt_uart_irq_init (bt_uart_cfg *port);
extern void bt_uart_basic_init (bt_uart_cfg *port);
extern uint32 bt_uart_send_data(uint32 port_id, uint8 *data, uint32_t size);
extern uint32 bt_uart_recv_data(uint32 port_id, uint8 *pbuf, uint32_t size);
extern void bt_uart_set_baudrate(uint32 port_id, uint32_t rate);
//extern void WriteChar(char c);
//extern void WriteString(char *s);

extern void bt_uart_enable (uint32 port_id, uint32 enable);
extern int  bt_uart_flush(uint32);
extern void bt_uart_mask_RxInt(uint32, uint32);
extern uint32 bt_uart_get_IntStatus(uint32);
extern uint32 bt_uart_get_base_addr(uint32);
extern BOOL bt_uart_is_RxInt(uint32);
void bt_uart_dma_enable (uint32 port_id, uint32 enable);

/* remove as uart shell not nesscery for CP_PLT currently
extern void uart_shell_putc(char ch);
extern char uart_shell_chks(void);
extern char uart_shell_getc(void);
extern void uart_shell_puts(const char *s);
*/
#else

#include "UART_drv.h"
void bt_uart_irq_init (uartdrv_cfg *port);
void bt_uart_basic_init (uartdrv_cfg *port);
void bt_uart_change_to_115200(uint32 port_id);
void bt_uart_change_to_921600(uint32 port_id);
void bt_uart_change_to_3000000(uint32 port_id);
void bt_uart_enable_flowctrl (uint32 port_id, uint32 enable);
uint32 bt_uart_send_data(uint32 port_id, uint8 *data, uint32 size);
uint32 bt_uart_recv_data(uint32 port_id, uint8 *pbuf, uint32 size);
void bt_uart_mask_RxInt(uint32 port_id, uint32 enable);
void bt_uart_dma_enable (uint32 port_id, uint32 enable);
void bt_uart_enable (uint32 port_id, uint32 enable);
#endif //UART_NEW_VERSION

#endif
