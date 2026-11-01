#include "common.h"
#include "guilin_lite.h"
#include "bsp.h"

/****************************************************************
 * console output
 ****************************************************************/
 
#define CP_UART2_BASE   0xd4018000
#define CP_UART_BASE   0xd4017000	

#ifdef QUECTEL_FOTA
#include "lfs.h"
#include "lfs_api.h"

#define QUEC_CP_BAUDRATE_INI  "quec_cp_baudrate.ini"
#define UART_CLOCK                  14745600L  /* the UART clock Hz input clock */

typedef enum   /* All the UART Baud Rate that the UART Package supplay */
{
    UART_BAUD_150       = 150,
    UART_BAUD_300       = 300,
    UART_BAUD_600       = 600,
    UART_BAUD_1200      = 1200,
    UART_BAUD_2400      = 2400,
    UART_BAUD_3600      = 3600,
    UART_BAUD_4800      = 4800,
    UART_BAUD_7200      = 7200,
    UART_BAUD_9600      = 9600,
    UART_BAUD_14400     = 14400,
    UART_BAUD_19200     = 19200,
    UART_BAUD_28800     = 28800,
    UART_BAUD_38400     = 38400,
    UART_BAUD_57600     = 57600,
    UART_BAUD_115200    = 115200,
    UART_BAUD_230400    = 230400,
    UART_BAUD_460800    = 460800,
    UART_BAUD_921600    = 921600,

	UART_BAUD_1000000	= 1000000,
	UART_BAUD_1842000	= 1842000,
	UART_BAUD_3686400	= 3686400,
    UART_MAX_NUM_BAUD
}UART_BaudRates;


UART_BaudRates quec_get_cp_baudrate()
{

	UART_BaudRates tmp_baudrate = UART_BAUD_115200;
	int filehandle = 0;
	int read_size = -1;


	filehandle = lfs_io_open(QUEC_CP_BAUDRATE_INI,LFS_O_RDONLY,0);
	if(filehandle < 0)
	{
		uart_printf("function:%s,quec_cp_baudrate.ini open fail.\r\n",__func__);
		tmp_baudrate = UART_BAUD_115200;
		return tmp_baudrate;
	}
	read_size = lfs_io_read(filehandle,(void*)&tmp_baudrate,sizeof(tmp_baudrate));
	if(sizeof(tmp_baudrate) != read_size  )
	{
		uart_printf("update file read error: %d\r\n",read_size);
		tmp_baudrate = UART_BAUD_115200;
		lfs_io_close(filehandle);
		return tmp_baudrate;
	 }

	uart_printf("quec_cp_baudrate.ini read success baudrate = %d\r\n",tmp_baudrate);
	lfs_io_close(filehandle);
	return tmp_baudrate;

}
#endif

 
void cp_uart_init()
{
	volatile unsigned long *r;
	
	/* PMUM_ACGR */
	writel(0xffffffff,0xd4050024); 

	writel(0x03,0xd401503c); //AIB

	/* UART clock control/UCER */
	writel(0x13,0xd4015000);

    if (CHIP_IS_CRANELR)
    {
        /* MFPR GPIO 71 */
        r = (volatile unsigned long*)0xd401e1bc; //AP_UART1_RXD
        *r = 0xd0c1;
        
        /* MFPR GPIO 72 */
        r = (volatile unsigned long*)0xd401e1c0; //AP_UART1_TXD
        *r = 0xd0c1;
    }
    else if (CHIP_IS_CRANELS_A0)
    {
        /* MFPR GPIO 27 */
        r = (volatile unsigned long*)0xd401e148; //AP_UART1_RXD
        *r = 0xd0c1;

        /* MFPR GPIO 28 */
        r = (volatile unsigned long*)0xd401e14C; //AP_UART1_TXD
        *r = 0xd0c1;

    }
    else
    {
    	/* MFPR GPIO 29 */
    	r = (volatile unsigned long*)0xd401e150; //UART1_RXD
    	*r = 0xd0c1;

    	/* MFPR GPIO 30 */
    	r = (volatile unsigned long*)0xd401e154; //UART1_TXD
    	*r = 0xd0c1;
    }

	// UALCR
	r = (volatile unsigned long*)(CP_UART_BASE + 0xc);
	*r = 0x83;

	// UADLL
	r = (volatile unsigned long*)(CP_UART_BASE + 0x0);
	*r = 0x08; //0x08 for 14.7456M on DKB, 0x7 for 13M on FPGA;

	// UADLH
	r = (volatile unsigned long*)(CP_UART_BASE + 0x4);
	*r = 0;

	// UALCR
	r = (volatile unsigned long*)(CP_UART_BASE + 0xC);
	*r &= ~0x80;

	// UAFCR
	r = (volatile unsigned long*)(CP_UART_BASE + 0x8);
	*r = 0x07;

	// UAIER
	r = (volatile unsigned long*)(CP_UART_BASE + 0x4);
	*r = 0x40;
}
 
void cp_uart_putc(const char ch)
{
	volatile unsigned long* ualsr;
	volatile unsigned long* uathr;

	ualsr = (volatile unsigned long*)(CP_UART_BASE + 0x14);
	uathr = (volatile unsigned long*)(CP_UART_BASE);

	while (!(*ualsr & 0x20));

	*uathr = ch;
}
extern int quec_dualport_support;
int uart_printf(const char *fmt, ...)
{
#if !defined (ENABLE_SLT_FEATURE)
	va_list ap;
	char buffer[128], *ptr;
	void (*console_output)(const char ch);
#if QUEC_UART2_ENABLE
	if(quec_production_config.quec_dualport_support)
		return 1;
#endif
	memset(buffer, 0, sizeof(buffer));
	va_start(ap, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, ap);
	va_end(ap);

	console_output = cp_uart_putc;

	ptr = &buffer[0];
	while (*ptr)
	{
		console_output(*ptr);
		ptr ++;
	}

	return ptr - buffer;
#else
    return 0;
#endif
}

void display_binary(void *data, size_t len)
{
#define XK_BYTE_COUNT_EACH_LINE 8

    static const char hex[] = "0123456789ABCDEF";
    static const char seperator = ' ';
    unsigned char *p = (unsigned char *)data;
    char stash[XK_BYTE_COUNT_EACH_LINE * (2 + 2 + 1) + 1];
    size_t j = 0;
    size_t i;

	uart_printf("\r\n----------------------------\r\n");
    uart_printf("BASE=[%0.8x]LEN=[%0.8x]",data,len);

    for (i = 0; i < len; i=i+2) {
        //stash[j++] = '0';
        //stash[j++] = 'x';
        stash[j++] = hex[(p[i] >> 4) & 0xF];
        stash[j++] = hex[p[i] & 0xF];

        stash[j++] = hex[(p[i+1] >> 4) & 0xF];
        stash[j++] = hex[p[i+1] & 0xF];

        stash[j++] = seperator;
        if (j == sizeof(stash) - 1) {
            stash[j] = '\0';
            uart_printf("\r\n[%0.8x]%s",((unsigned int)data + i - 0xe), stash);
            j = 0;
        }
    }
    if (j) {
        stash[j] = '\0';
        uart_printf("\r\n[%0.8x]%s",((unsigned int)data + i - 0xe + XK_BYTE_COUNT_EACH_LINE), stash);
    }
	uart_printf("\r\n----------------------------\r\n");
}

#define AIB_UART_IO_REG                  0xD401E81C
extern int GuilinLite_LDO_Set_VOUT(unsigned char reg, unsigned char value);

void _AIB_Secure_Write(unsigned int address, unsigned int value)
{
	BU_REG_WRITE(0xd4015050, 0xBABA);	
	BU_REG_WRITE(0xd4015054, 0xEB10);
	BU_REG_WRITE(address, value);
}

UINT32 _AIB_Secure_Read(unsigned int address)
{
	UINT32 val;
	BU_REG_WRITE(0xd4015050, 0xBABA);	
	BU_REG_WRITE(0xd4015054, 0xEB10);
	val = BU_REG_READ(address);
	return val;
}

void AIB_UART_IO_Set_1_8V(void)
{
    volatile unsigned int val = 0;

    val = _AIB_Secure_Read(AIB_UART_IO_REG); //AIB_UART_IO_REG
    val |= 0x85;
    _AIB_Secure_Write(AIB_UART_IO_REG, val);
}

void PMIC_Set_UART_1_8V(void)
{
    if(PMIC_IS_PM803())
    {
        GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO7_ACTIVE_VOUT_REG, GUILIN_LITE_LDO7_ACTIVE_1V80);
    }
    AIB_UART_IO_Set_1_8V();
}

void PMIC_Set_UART_Poweron(void)
{
    if(PMIC_IS_PM803())
    {
        GuilinLite_Ldo_7_set(TRUE);
    }
}
#ifdef QUECTEL_FOTA
void cp_uart2_init(unsigned int buad)
#else
void cp_uart2_init(void)
#endif
{
	volatile unsigned long *r;
	if (IsChipCraneL() || IsChipCraneL_Z1() || IsChipCraneLS()) {
      PMIC_Set_UART_1_8V();
      PMIC_Set_UART_Poweron();
    }
	
#ifdef QUECTEL_FOTA
	UART_BaudRates baudrate = UART_BAUD_115200;
	UINT32 divisor;
	UINT8 DLHval, DLLval;
	
	if(buad) baudrate = buad;
#endif

	/* PMUM_ACGR */
	writel(0xffffffff,0xd4051024); //0xdffefffe;

	writel(0x03,0xd401503c); //AIB
	
#if 0
		writel(0x00,0xd4015004);
		{
			unsigned long uart_delay = 0xffff;
			while(uart_delay--);
		}
#endif
		/* UART clock control/UCER */
		writel(0x13,0xd4015004);
	
	
		/* MFPR GPIO 51, UART2 rx */
		r = (volatile unsigned long*)0xd401e1a8;
		*r = 0xd0c1;
	
		/* MFPR GPIO 52, UART2 TX */
		r = (volatile unsigned long*)0xd401e1ac;
		*r = 0xd0c1;

	// UALCR
	r = (volatile unsigned long*)(CP_UART2_BASE + 0xc);
	*r = 0x83;
	
#ifdef QUECTEL_FOTA
	divisor = (UINT32)(UART_CLOCK / (16L*baudrate));
	DLLval = (UINT8)(divisor & 0xFF);
	DLHval = (UINT8)((divisor & 0xFF00) >> 8);
	
	// UADLL
	r = (volatile unsigned long*)(CP_UART2_BASE + 0x0);
	*r = DLLval; //0x08 for 14.7456M on DKB, 0x7 for 13M on FPGA;
	
	// UADLH
	r = (volatile unsigned long*)(CP_UART2_BASE + 0x4);
	*r = DLHval;
#else
	// UADLL
	r = (volatile unsigned long*)(CP_UART2_BASE + 0x0);
	*r = 0x08; //0x08 for 14.7456M on DKB, 0x7 for 13M on FPGA;

	// UADLH
	r = (volatile unsigned long*)(CP_UART2_BASE + 0x4);
	*r = 0;
#endif

	// UALCR
	r = (volatile unsigned long*)(CP_UART2_BASE + 0xC);
	*r &= ~0x80;

	// UAFCR
	r = (volatile unsigned long*)(CP_UART2_BASE + 0x8);
	*r = 0x07;

	// UAIER
	r = (volatile unsigned long*)(CP_UART2_BASE + 0x4);
	*r = 0x40;
}
 
void cp_uart2_putc(const char ch)
{
	volatile unsigned long* ualsr;
	volatile unsigned long* uathr;

	ualsr = (volatile unsigned long*)(CP_UART2_BASE + 0x14);
	uathr = (volatile unsigned long*)(CP_UART2_BASE);

	while (!(*ualsr & 0x20));

	*uathr = ch;
}
 
int uart2_printf(const char *fmt, ...)
{
	va_list ap;
	char buffer[128], *ptr;
	void (*console_output)(const char ch);

	memset(buffer, 0, sizeof(buffer));
	va_start(ap, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, ap);
	va_end(ap);

	console_output = cp_uart2_putc;

	ptr = &buffer[0];
	while (*ptr)
	{
		console_output(*ptr);
		ptr ++;
	}

	return ptr - buffer;
}

