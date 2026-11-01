


#include "quec_cust_startup_feature.h"

#if 1//def QUECTEL_OPEN_CPU

#include "mfpr_api.h"
#include "common.h"
#include "ningbo.h"
#include "quec_startup_gpio.h"
#include "pmic.h"
#include "bsp.h"
 /*
MFPR Fragments
*/

#define  GPIO_MFPR_BASE1 0xD401E0DC
#define  GPIO_MFPR_BASE2 0xD401E1A0
#define  GPIO_MFPR_BASE3 0xD401E304
#define  GPIO_MFPR_BASE4 0xD401E1B8
#define  GPIO_MFPR_BASE5 0xD401E1E0
#define  GPIO_MFPR_BASE6 0xD401E0C8
#define  GPIO_MFPR_BASE7 0xD401E2EC
#define  GPIO_MFPR_BASE8 0xD401E2E4
																	
#define  GPIO_MFPR_BASE9 0xD401E2BC
#define  GPIO_MFPR_BASE10 0xD401E32C
#define  GPIO_MFPR_BASE11 0xD401E094
																	
#define  GPIO_MFPR_BASE12 0xD401E2F0 //added for GPIO55~59,2F0~300
#define  GPIO_MFPR_BASE13 0xD401E0B4 //added for GPIO117~120,0B4-0C0
#define  GPIO_MFPR_BASE14 0xD401E2DC //added for GPIO77~78
#define  GPIO_MFPR_BASE15 0xD401E260 //added for GPIO45~47,260~268
#define  INVALID_GPIO_MFPR_ADDR	0xFFFFFFFF
									
UINT32 GPIO_MFPR_ADDR(UINT32 n) 	
{
    if(CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR){
        return  (  n <= 36  ?   GPIO_MFPR_BASE1 + (n << 2): \
                   ((n ==37)) ?   0xD401E1CC: \
                   ((n <= 47) &&(n >=45)) ?   GPIO_MFPR_BASE15 + ((n-45) << 2): \
                   ((n <= 54) &&(n >=49)) ?   GPIO_MFPR_BASE2 + ((n-49) << 2): \
                   ((n == 55))?    0xD401E0C8: \
                   ((n <= 66)&&(n >=60) )  ?   GPIO_MFPR_BASE3 + ((n-60) << 2): \
                   ((n <= 70)&&(n >=68) )  ?   0xD401E2B8 + ((n-68) << 2): \
                   ((n <= 74)&&(n>=71))  ?   0xD401E1BC + ((n-71)<<2): \
                   ((n <= 80)&&(n>=78))  ?   0xD401E2E0 + ((n-78)<<2): \
				   ((n == 85))?  0xD401E0D4: \
				   ((n == 86))?  0xD401E0D8: \
				   ((n <=90 )&&(n >=87) ) ? 0xD401E0B4 + ((n-87)<<2): \
                   ((n <=120)&&(n >= 117))?  0xD401E0B4+((n-117)<<2): \
                   ((n == 121))?   0xD401E32C:     \
                   ((n <= 126)&&(n >= 122))?   GPIO_MFPR_BASE6+((n-122) << 2) :     \
                   ((n == 122))?  GPIO_MFPR_BASE6:     \
                   ((n == 124))?  0xD401E0D0:   \
                   ((n == 126))?  0xD401E0D8:   \
                   ((n == 77))?   0xD401E2DC: \
                   ((n == 56))?  0xD401E2F4: \
                   ((n == 57))?  0xD401E2F8: \
                   INVALID_GPIO_MFPR_ADDR);

    }
	else{
		return ((CHIP_IS_CRANEM)? \
					(  n <= 36	?	GPIO_MFPR_BASE1 + (n << 2): \
					   ((n <= 43) &&(n >=37)) ?   GPIO_MFPR_BASE11 + ((n-37) << 2): \
					   ((n <= 47) &&(n >=45)) ?   GPIO_MFPR_BASE15 + ((n-45) << 2): \
					   ((n <= 54) &&(n >=49)) ?   GPIO_MFPR_BASE2 + ((n-49) << 2): \
					   ((n <= 66)&&(n >=60) )  ?   GPIO_MFPR_BASE3 + ((n-60) << 2): \
					   ((n <= 76)&&(n>=71))  ?	 GPIO_MFPR_BASE4 + ((n-71)<<2): \
					   ((n <= 86)&&(n>=81) ) ?	 GPIO_MFPR_BASE5 + ((n-81) << 2): \
					   ((n <= 126)&&(n >= 122))?   GPIO_MFPR_BASE6+((n-122) << 2) : 	\
					   (n == 48 )?	 GPIO_MFPR_BASE7 :		\
					   ((n <= 59)&&(n >=55) )  ?   GPIO_MFPR_BASE12 + ((n-55) << 2): \
					   ((n <= 120)&&(n >=117) )  ?	 GPIO_MFPR_BASE13 + ((n-117) << 2): \
					   (n == 121 )?   GPIO_MFPR_BASE10 :		\
					   ((n <= 80)&&(n >=79)) ? GPIO_MFPR_BASE8 + ((n-79)<<2) : \
					   ((n <= 70)&&(n >=69)) ? GPIO_MFPR_BASE9 + ((n-69)<<2) : \
					   ((n <= 78)&&(n>=77))  ?	 GPIO_MFPR_BASE14 + ((n-77)<<2): \
					   INVALID_GPIO_MFPR_ADDR): \
					(  n <= 36	?	GPIO_MFPR_BASE1 + (n << 2): \
					   ((n <= 43) &&(n >=37)) ?   GPIO_MFPR_BASE11 + ((n-37) << 2): \
					   ((n <= 47) &&(n >=45)) ?   GPIO_MFPR_BASE15 + ((n-45) << 2): \
					   ((n <= 54) &&(n >=49)) ?   GPIO_MFPR_BASE2 + ((n-49) << 2): \
					   ((n <= 66)&&(n >=60) )  ?   GPIO_MFPR_BASE3 + ((n-60) << 2): \
					   ((n <= 78)&&(n>=71))  ?	 GPIO_MFPR_BASE4 + ((n-71)<<2): \
					   ((n <= 86)&&(n>=81) ) ?	 GPIO_MFPR_BASE5 + ((n-81) << 2): \
					   ((n <= 126)&&(n >= 122))?   GPIO_MFPR_BASE6+((n-122) << 2) : 	\
					   (n == 48 )?	 GPIO_MFPR_BASE7 :		\
					   ((n <= 59)&&(n >=55) )  ?   GPIO_MFPR_BASE12 + ((n-55) << 2): \
					   ((n <= 120)&&(n >=117) )  ?	 GPIO_MFPR_BASE13 + ((n-117) << 2): \
					   (n == 121 )?   GPIO_MFPR_BASE10 :		\
					   ((n <= 80)&&(n >=79)) ? GPIO_MFPR_BASE8 + ((n-79)<<2) : \
					   ((n <= 70)&&(n >=69)) ? GPIO_MFPR_BASE9 + ((n-69)<<2) : \
					   INVALID_GPIO_MFPR_ADDR));

	}

}	 


#define GPIO_SHIFT(gpio) (1 << (gpio%32))

/*bit definition for GPIO functions*/
#define GPIO_BIT_ENABLE_RED	(1 << 4)
#define GPIO_BIT_ENABLE_FED	(1 << 5)
#define GPIO_BIT_CLEAR_ED	(1 << 6)
#define GPIO_BIT_SLEEP_DIR	(1 << 7)

#define GPIO_BIT_DRIVE_0	(1 << 11)
#define GPIO_BIT_DRIVE_1	(1 << 12)
#define GPIO_BIT_PULLDN		(1 << 13)
#define GPIO_BIT_PULLUP		(1 << 14)
#define GPIO_BIT_PULL_SEL	(1 << 15)

#define GPIO_REGISTER_BASE				0xD4019000
#define GPIO_REGISTER_GROUPS				4
#define GPIO_GROUP_BASE1					0
#define GPIO_GROUP_BASE2					4
#define GPIO_GROUP_BASE3					8
#define GPIO_GROUP_BASE4					0x100

typedef struct 
{
	unsigned long REG;
	unsigned long padding[2];
}GPIO_Single_Register;

typedef volatile struct
{
	volatile GPIO_Single_Register PLR;//0x0
	volatile GPIO_Single_Register PDR;//0xc
	volatile GPIO_Single_Register PSR;//0X18
	volatile GPIO_Single_Register PCR;//0X24
	volatile GPIO_Single_Register RER;//0X30
	volatile GPIO_Single_Register FER;//0X3C
	volatile GPIO_Single_Register EDR;//0X48
	volatile GPIO_Single_Register SDR;//0X54
	volatile GPIO_Single_Register CDR;//0X60
	volatile GPIO_Single_Register SRER;//0X6C
	volatile GPIO_Single_Register CRER;//0X78
	volatile GPIO_Single_Register SFER;//0X84
	volatile GPIO_Single_Register CFER;//0X90
	volatile GPIO_Single_Register AP_MASK;//0X9C
	volatile GPIO_Single_Register CP_MASK;//0XA8
}GPIORegisters;

static unsigned long GPIORegisterBase[GPIO_REGISTER_GROUPS] = {	GPIO_GROUP_BASE1,
															GPIO_GROUP_BASE2,
															GPIO_GROUP_BASE3,
															GPIO_GROUP_BASE4};

typedef enum
{
	VSPI_GPIO_0=0,
	VSPI_GPIO_32=32,
	VSPI_GPIO_33=33,
	VSPI_GPIO_34,
	VSPI_GPIO_35,
	VSPI_GPIO_36,
	VSPI_GPIO_64=64,
	VSPI_GPIO_96=96,
	VSPI_GPIO_121=121,
	VSPI_GPIO_MAX=127,
	VSPI_GPIO_NULL=128
}VSpiGpio;

/*START @20220629 for configure UART gpio function (expecially gpio31 and so on)*/
static void AIB_Secure_Write(unsigned int address, unsigned int value)
{
	BU_REG_WRITE(0xd4015050, 0xBABA);	
	BU_REG_WRITE(0xd4015054, 0xEB10);
	BU_REG_WRITE(address, value);
}

static UINT32 AIB_Secure_Read(unsigned int address)
{
	UINT32 val;
	BU_REG_WRITE(0xd4015050, 0xBABA);	
	BU_REG_WRITE(0xd4015054, 0xEB10);
	val = BU_REG_READ(address);
	return val;
}

#define AIB_UART_IO_REG                  0xD401E81C

static void AIB_UART_IO_Set_1_8V(void)
{
    volatile unsigned int val = 0;

    val = AIB_Secure_Read(AIB_UART_IO_REG); //AIB_UART_IO_REG
    val |= 0x85;
    AIB_Secure_Write(AIB_UART_IO_REG, val);
}
/*ENDT @20220629 for configure UART gpio function (expecially gpio31 and so on)*/

//设置Pin脚的复用功能以及驱动能力，上下拉
int quec_set_gpio_mfprReg(GPIO_PIN_NUMBER_E pin_num, unsigned long mfprReg_data )
{
	if( pin_num > GPIO_MAX_AMOUNT_OF_PINS || pin_num < GPIO_PIN_NO_0 )
	{
		 uart_printf("pin_num=%d error", pin_num);
		 return -1;
	}

	*(volatile unsigned long *)(GPIO_MFPR_ADDR(pin_num)) = mfprReg_data;
	return 0;
}


static __inline unsigned long *GetBaseAddr(unsigned int portHandle)
{
	unsigned int base_addr;
	
	if(portHandle < VSPI_GPIO_32)
		base_addr =  GPIO_REGISTER_BASE + GPIORegisterBase[0];
	else if(portHandle < VSPI_GPIO_64)
		base_addr =  GPIO_REGISTER_BASE + GPIORegisterBase[1];
	else if(portHandle < VSPI_GPIO_96)
		base_addr =  GPIO_REGISTER_BASE + GPIORegisterBase[2];
	else if(portHandle <= VSPI_GPIO_MAX)
		base_addr =  GPIO_REGISTER_BASE + GPIORegisterBase[3];
	else
		base_addr =  0;

	return (unsigned int *)base_addr;
}

static int GpioInitConfiguration(GPIO_PIN_NUMBER_E gpio_num, quec_gpio_cfg_t config)
{
	int ret = -1;
	volatile unsigned int *mfpr_addr;
	
	/* init pull up and pull down registors */
	if (PIN_DIRECTION_IN == config.pin_dir) {
		ql_gpio_set_pull(gpio_num, config.pin_pull);
	}
	
	/* init direction */
	ret = ql_gpio_set_direction(gpio_num, config.pin_dir);
	if (ret) {
		return -1;
	}
	
	//shaohua.li@20201027 解决bootloader阶段设置GPIO为输入模式时，接口报错
	//gpio为输入模式时，不需要设置电平
	if(PIN_DIRECTION_OUT == config.pin_dir)
	{	
		/* set up an initial pin level */
		ret = ql_gpio_set_level(gpio_num, config.pin_level);
		if (ret) {
			return -1;
		}
	}
	return 0;
}

static int quec_gpio_config_set(GPIO_PIN_NUMBER_E gpio_num, PIN_DIRECTION_E pin_dir, PIN_PULL_E pin_pull, PIN_LEVEL_E pin_level)
{
	quec_gpio_cfg_t gpio_config_data =
	{
		.gpio_pin_num = gpio_num,
		.pin_dir  = pin_dir,
		.pin_pull = pin_pull,
		.pin_level  = pin_level,
		.pin_edge 	 = PIN_NO_EDGE,
	};
	return GpioInitConfiguration(gpio_num, gpio_config_data);
}

int GpioSetPullControl(UINT32 portHandle, PIN_PULL_E pull)
{
	volatile UINT32 *mfpr_addr;
	UINT32 regval;

	mfpr_addr = (volatile UINT32 *)GPIO_MFPR_ADDR(portHandle);
	if((UINT32)mfpr_addr == INVALID_GPIO_MFPR_ADDR)
	{
	    uart_printf("INVALID_GPIO_MFPR_ADDR: %d in func: %s",portHandle, __func__);
		return -93;
    }
	if(pull == PIN_PULL_DISABLE)
	{
		regval  = *(mfpr_addr);
		*(mfpr_addr) = (regval | (GPIO_BIT_PULL_SEL))
			& ~(GPIO_BIT_PULLUP) &~(GPIO_BIT_PULLDN);
	}
	else if(pull == PIN_PULL_PU)
	{
		regval  = *(mfpr_addr);
		*(mfpr_addr) = (regval | (GPIO_BIT_PULL_SEL)| (GPIO_BIT_PULLUP))
						& ~(GPIO_BIT_PULLDN);
	}
	else if(pull == PIN_PULL_PD)
	{
		regval  = *(mfpr_addr);
		*(mfpr_addr) = (regval | (GPIO_BIT_PULL_SEL) | (GPIO_BIT_PULLDN))
						& ~(GPIO_BIT_PULLUP);
	}
	else
	{
		/*mischecked by coverity*/
		/*coverity[dead_error_line]*/
		return -83;
	}

	return 0;
}

int ql_gpio_init(GPIO_PIN_NUMBER_E gpio_num, PIN_DIRECTION_E pin_dir, PIN_PULL_E pin_pull, PIN_LEVEL_E pin_level)
{
	int ret = -1;
    unsigned int reg_val;
	unsigned long mfpr_data = MFP_DRIVE_MEDIUM | MFP_LPM_EDGE_NONE;
	
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_MAX_AMOUNT_OF_PINS < gpio_num) {
		uart_printf("gpio number is invalid\n");
		return -1;
	}
	
	/*必须先config，再设置MFPR。,防止配置过程中发生电平抖动*/
	
	/* step 1: set gpio reg */
	ret = quec_gpio_config_set(gpio_num, pin_dir, pin_pull, pin_level);
	if (ret)
	{
		uart_printf("config gpio reg failed, gpio_num:%d, ret = %d \n", gpio_num, ret);
		return -1;
	}

	reg_val = *(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num))&(~0x07)&(~(0x3<< 11));
    
	if (GPIO_PIN_NO_117==gpio_num)
	{	//MMC2 GPIOS
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num)) = MFP_AF1 | mfpr_data | reg_val;
	} 
	else if((GPIO_PIN_NO_31==gpio_num) || (GPIO_PIN_NO_27==gpio_num))
	{
		AIB_UART_IO_Set_1_8V(); 			//@20220629 for configure MAIN UART gpio function (expecially gpio31 gpio27 and so on) 
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num)) = MFP_AF0 | mfpr_data | reg_val;
	}
	else
	{
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num)) = MFP_AF0 | mfpr_data | reg_val;
	}
	
	ret = GpioSetPullControl(gpio_num, pin_pull);
	if (ret) {
		uart_printf("set gpio pin pull failed, ret = %d \n", ret);
		return -1;
	}

	return 0;
}

int ql_gpio_deinit(GPIO_PIN_NUMBER_E gpio_num)
{
	return 0;
}

int ql_gpio_set_direction(GPIO_PIN_NUMBER_E gpio_num, PIN_DIRECTION_E pin_dir)
{
	volatile unsigned int *mfpr_addr = NULL;
	GPIORegisters *GPIOReg;
	unsigned int reg_val = 0;
	
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_MAX_AMOUNT_OF_PINS < gpio_num) {
		uart_printf("gpio number is invalid\n");
		return -1;
	}
	
	mfpr_addr = (volatile unsigned int *)GPIO_MFPR_ADDR(gpio_num);
	if (INVALID_GPIO_MFPR_ADDR == mfpr_addr) {
		return -1;
	}
	
	GPIOReg = (GPIORegisters *)GetBaseAddr(gpio_num);
	
	switch (pin_dir) {
		case PIN_DIRECTION_OUT:
			GPIOReg->SDR.REG =	GPIO_SHIFT(gpio_num);
			*(mfpr_addr) &= ~(GPIO_BIT_SLEEP_DIR);			
			break;
		case PIN_DIRECTION_IN:
			GPIOReg->CDR.REG =	GPIO_SHIFT(gpio_num);
			*(mfpr_addr) |= GPIO_BIT_SLEEP_DIR;			
			break;
	}

	//medium drive slew rate
	*(mfpr_addr) |= GPIO_BIT_DRIVE_1;
	return 0;
}

int ql_gpio_get_direction(GPIO_PIN_NUMBER_E gpio_num, PIN_DIRECTION_E *p_pin_dir)
{
	GPIORegisters *GPIOReg;
	unsigned int bit;
	
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_MAX_AMOUNT_OF_PINS < gpio_num || NULL == p_pin_dir) {
		uart_printf("para is invalid \n");
		return -1;
	}
	
	GPIOReg = (GPIORegisters *)GetBaseAddr(gpio_num);
	
	bit = GPIOReg->PDR.REG & GPIO_SHIFT(gpio_num);

	if (bit) {
		*p_pin_dir = PIN_DIRECTION_OUT;
	}
	else {
		*p_pin_dir = PIN_DIRECTION_IN;
	}
	
	return 0;
}

void quec_gpio_set_output(unsigned int port)
{
	GPIORegisters *GPIOReg;
	GPIOReg = (GPIORegisters *)GetBaseAddr(port);
	GPIOReg->SDR.REG =	GPIO_SHIFT(port);
}
__inline void quec_gpio_set_value(unsigned int port, int value)
{
	//set high
	GPIORegisters *GPIOReg;
	GPIOReg = (GPIORegisters *)GetBaseAddr(port);
	if(value == 0) {
		GPIOReg->PCR.REG = GPIO_SHIFT(port);
	}
	else {
		GPIOReg->PSR.REG = GPIO_SHIFT(port);
	}
}



int ql_gpio_set_level(GPIO_PIN_NUMBER_E gpio_num, PIN_LEVEL_E pin_level)
{
	GPIORegisters *GPIOReg;
	PIN_DIRECTION_E pin_dir;
	
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_MAX_AMOUNT_OF_PINS < gpio_num)
	{
		uart_printf("gpio number is invalid\n");
		return -1;
	}
	
	ql_gpio_get_direction(gpio_num, &pin_dir);
	if (PIN_DIRECTION_IN == pin_dir)
	{
		uart_printf("This is input gpio, can't be writen\r\n");
		return -1;
	}	
	quec_gpio_set_value(gpio_num,pin_level);
	
	return 0;
}

int ql_gpio_get_level(GPIO_PIN_NUMBER_E gpio_num, PIN_LEVEL_E *p_pin_level)
{
	GPIORegisters *GPIOReg;
	unsigned int bit;
	
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_MAX_AMOUNT_OF_PINS < gpio_num || NULL == p_pin_level) {
		uart_printf("para is invalid \n");
		return -1;
	}
	
	GPIOReg = (GPIORegisters *)GetBaseAddr(gpio_num);

	bit = GPIOReg->PLR.REG & GPIO_SHIFT(gpio_num);
	
	if (bit) {
		*p_pin_level = PIN_LEVEL_HIGH;
	}
	else {
		*p_pin_level = PIN_LEVEL_LOW;
	}

	return 0;
}

int ql_gpio_set_pull(GPIO_PIN_NUMBER_E gpio_num, PIN_PULL_E pin_pull)
{
	volatile unsigned int *mfpr_addr;
	unsigned int reg_val;

	if (GPIO_PIN_NO_0 > gpio_num || GPIO_MAX_AMOUNT_OF_PINS < gpio_num) {
		uart_printf("gpio number is invalid\n");
		return -1;
	}

	mfpr_addr = (volatile unsigned int *)GPIO_MFPR_ADDR(gpio_num);
	if (INVALID_GPIO_MFPR_ADDR == mfpr_addr) {
		uart_printf("invalid gpio number \r\n");
		return -1;
	}
	
	if(pin_pull == PIN_PULL_DISABLE) {	
		reg_val  = *(mfpr_addr);
		*(mfpr_addr) = (reg_val | (GPIO_BIT_PULL_SEL)) 
			& ~(GPIO_BIT_PULLUP) &~(GPIO_BIT_PULLDN);
	}
	else if(pin_pull == PIN_PULL_PU) {
		reg_val  = *(mfpr_addr);
		*(mfpr_addr) = (reg_val | (GPIO_BIT_PULL_SEL)| (GPIO_BIT_PULLUP))
						& ~(GPIO_BIT_PULLDN);
	}
	else if(pin_pull == PIN_PULL_PD) {
		reg_val  = *(mfpr_addr);
		*(mfpr_addr) = (reg_val | (GPIO_BIT_PULL_SEL) | (GPIO_BIT_PULLDN))
						& ~(GPIO_BIT_PULLUP);
	}
	else {
		/*mischecked by coverity*/
		/*coverity[dead_error_line]*/
		return -1;
	}
	
	return 0;
}

int ql_gpio_get_pull(GPIO_PIN_NUMBER_E gpio_num, PIN_PULL_E *p_pin_pull)
{
	volatile unsigned int *mfpr_addr;
	unsigned int regval;
	
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_MAX_AMOUNT_OF_PINS < gpio_num || NULL == p_pin_pull) {
		uart_printf("para is invalid \n");
		return -1;
	}

	mfpr_addr = (volatile unsigned int *)GPIO_MFPR_ADDR(gpio_num);
	if(mfpr_addr == INVALID_GPIO_MFPR_ADDR)
		return -1;

	regval  = *(mfpr_addr);
	if ((regval & GPIO_BIT_PULL_SEL) && (regval & GPIO_BIT_PULLUP)) {
		*p_pin_pull = PIN_PULL_PU;
	}
	else if ((regval & GPIO_BIT_PULL_SEL) && (regval & GPIO_BIT_PULLDN)) {
		*p_pin_pull = PIN_PULL_PD;
	}
	else {
		*p_pin_pull = PIN_PULL_DISABLE;
	}
	
	return 0;
}

void ql_boot_gpio_test(void)
{
	int xx=0,yy=00,zz=0;

	//EC600S pin66
	//EC600N pin14
	ql_gpio_init(GPIO_PIN_NO_24,PIN_DIRECTION_OUT,PIN_PULL_PU,PIN_LEVEL_HIGH);

	while(1)
	{
		uart_printf("boot out high\r\n");
		ql_gpio_set_level(GPIO_PIN_NO_24, PIN_LEVEL_HIGH);
		
		for(yy=0;yy<3000;yy++)
			for(xx=0;xx<10000;xx++);
		
		uart_printf("boot out low\r\n");
		ql_gpio_set_level(GPIO_PIN_NO_24, PIN_LEVEL_LOW);
		
		for(yy=0;yy<3000;yy++)
			for(xx=0;xx<10000;xx++);


		if(zz++>20)
			break;
	}
}


/*********************************************************
	在boot侧添加 ALL GPIO PIN TEXT
**********************************************************/
#define QUEC_WORKING_PROJECT_ID_TEXT							3
#define QUEC_WORKING_PROJECT_ID_EC800NCNLA						1
#define QUEC_WORKING_PROJECT_ID_EC100NCNAB						2
#define QUEC_WORKING_PROJECT_ID_EC600KCNCC                      3

#define QUEC_CURRURT_WORKING_PROJECT_ID_UNIQUE	QUEC_WORKING_PROJECT_ID_TEXT

#if QUEC_CURRURT_WORKING_PROJECT_ID_UNIQUE
typedef struct quec_gpio_pin_mux_test {
	GPIO_PIN_NUMBER_E gpio_num;
	PIN_DIRECTION_E pin_dir;
	PIN_EDGE_E pin_edge;
	PIN_PULL_E pin_pull;
	PIN_LEVEL_E pin_level;
	unsigned long mfpr_reg_data;
}quec_gpio_pin_mux_test_t;

#define QUEC_GPIO_CMD_MAX_LEN  60
typedef struct QuecBootGpioVmCtrlTab
{
	char cmd[QUEC_GPIO_CMD_MAX_LEN];
	char busy_flag;
}QuecBootGpioVmCtrlTab_t;
static QuecBootGpioVmCtrlTab_t boot_gpio_cfg;

#ifndef QUEC_ARR_SIZE
#define QUEC_ARR_SIZE(a)         	( sizeof(a) / sizeof(a[0]) )
#endif
#define CP_UART_BASE    0xd4017000	//(UART1-debug)

static quec_gpio_pin_mux_test_t boot_pin_test[] =
{
#if (QUEC_CURRURT_WORKING_PROJECT_ID_UNIQUE == QUEC_WORKING_PROJECT_ID_EC800NCNLA)
	//uart 
	{GPIO_PIN_NO_51,	PIN_DIRECTION_OUT, 	PIN_NO_EDGE, 	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH,	MFP_AF0},
	{GPIO_PIN_NO_52, 	PIN_DIRECTION_OUT, 	PIN_NO_EDGE, 	PIN_PULL_DISABLE, 	PIN_LEVEL_HIGH,	MFP_AF0},
	{GPIO_PIN_NO_121, 	PIN_DIRECTION_OUT, 	PIN_NO_EDGE, 	PIN_PULL_DISABLE, 	PIN_LEVEL_HIGH,	MFP_AF0},
	{GPIO_PIN_NO_122, 	PIN_DIRECTION_OUT, 	PIN_NO_EDGE, 	PIN_PULL_DISABLE, 	PIN_LEVEL_HIGH,	MFP_AF1},
	{GPIO_PIN_NO_124, 	PIN_DIRECTION_OUT, 	PIN_NO_EDGE, 	PIN_PULL_DISABLE, 	PIN_LEVEL_HIGH,	MFP_AF0},
	{GPIO_PIN_NO_54,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_53,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_0,		PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_1,		PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_29,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},	//DBG_RXD
	{GPIO_PIN_NO_30,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},	//DBG_TXD
	//PCM
	{GPIO_PIN_NO_16, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_17, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_19,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_18,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	//lcd
	{GPIO_PIN_NO_32, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_33, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_34,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_35,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_36,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_7,		PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	//camera
	{GPIO_PIN_NO_21, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_22, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_23,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_24,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_25,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_26,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_28,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	//key
	{GPIO_PIN_NO_11, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_10, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_5,		PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_4,		PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_9,		PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_8,		PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_14,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_15,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_3,		PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_2,		PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	//i2c
	{GPIO_PIN_NO_50,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_49,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_13,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_12,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	//othes
	{GPIO_PIN_NO_31,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_70,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_6,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	
#elif (QUEC_CURRURT_WORKING_PROJECT_ID_UNIQUE == QUEC_WORKING_PROJECT_ID_EC600KCNCC)

	{GPIO_PIN_NO_4,    PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
 	{GPIO_PIN_NO_5,    PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
 	{GPIO_PIN_NO_6,    PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
    {GPIO_PIN_NO_7,	    PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_10,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_11,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_12,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF1},
	{GPIO_PIN_NO_13,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_14,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_15,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_71, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_72, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_73, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_74,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},	//DBG_RXD
	{GPIO_PIN_NO_0,	    PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},	//DBG_TXD
	//PCM
	{GPIO_PIN_NO_1,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_2,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_3,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_8,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	//lcd
	{GPIO_PIN_NO_9,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_68,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_69,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_70,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_85,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF1},
	{GPIO_PIN_NO_86, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF1},
	//camera
	{GPIO_PIN_NO_87,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF1},
	{GPIO_PIN_NO_88,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF1},
	{GPIO_PIN_NO_89,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF1},
	{GPIO_PIN_NO_90,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF1},
	{GPIO_PIN_NO_79,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_80,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_33,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	//key
	{GPIO_PIN_NO_34,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_35,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_36, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_49, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_50, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_51,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_52,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_53, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_54, 	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	//i2c
	{GPIO_PIN_NO_55,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_56,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_57,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF0},
	{GPIO_PIN_NO_81,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF1},
	//othes
	{GPIO_PIN_NO_82,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF1},
	{GPIO_PIN_NO_83,	PIN_DIRECTION_OUT,	PIN_NO_EDGE,	PIN_PULL_DISABLE,	PIN_LEVEL_HIGH, MFP_AF1},





	//其他板子的pinmux配置

#else
	#error Un-correct constant definition
#endif
};

static void delay_ms(int time)
{    
   int i=0;  
   while(time-- > 0)
   {
      i=12000;  //自己定义
      while(i-- > 0) ;    
   }
}

static int quec_gpio_cust_config(void)
{
	int i=0;
	int ret = -1;
	PIN_DIRECTION_E pin_dir = 0;
	PIN_LEVEL_E pin_level = 0;
	
	for(i =0; i <  QUEC_ARR_SIZE(boot_pin_test) ; i++)
	{
		//默认不配置	DBG_RXD/DBG_TXD
		if((boot_pin_test[i].gpio_num == GPIO_PIN_NO_29)||(boot_pin_test[i].gpio_num == GPIO_PIN_NO_30))
			continue;
		ret = quec_set_gpio_mfprReg(boot_pin_test[i].gpio_num, boot_pin_test[i].mfpr_reg_data);// set gpio function
		if(ret){
			uart_printf("quec_set_gpio_mfprReg error pin_num = %d\n",boot_pin_test[i].gpio_num);
			
		}
		delay_ms(20);
		ret = ql_gpio_set_direction(boot_pin_test[i].gpio_num,boot_pin_test[i].pin_dir);
		if(ret){
			uart_printf("ql_gpio_set_direction error pin_num = %d\n",boot_pin_test[i].gpio_num);
		}
		delay_ms(20);
		ret = ql_gpio_get_direction(boot_pin_test[i].gpio_num,&pin_dir);
		if(ret){
			uart_printf("ql_gpio_get_direction error pin_num = %d\n",boot_pin_test[i].gpio_num);
		}
		else{
			uart_printf("pin_num = %d dir = %s\n",boot_pin_test[i].gpio_num,pin_dir?"OUTPUT" : "INPUT");
		}
		delay_ms(20);
		ret = ql_gpio_set_level(boot_pin_test[i].gpio_num,boot_pin_test[i].pin_level);
		if(ret){
			uart_printf("ql_gpio_set_level error pin_num = %d\n",boot_pin_test[i].gpio_num);
		}
		delay_ms(20);
		ret = ql_gpio_get_level(boot_pin_test[i].gpio_num,&pin_level);
		if(ret){
			uart_printf("ql_gpio_get_level error pin_num = %d\n",boot_pin_test[i].gpio_num);
		}
		else{
			uart_printf("pin_num = %d level = %s\n",boot_pin_test[i].gpio_num,pin_level?"HIGH" : "LOW");
		}
		delay_ms(20);
	}

	return 0;
}

static int quec_boot_uart_fifo_read(unsigned int addr, UINT8 *data, unsigned short lenToRead, unsigned short *dataLength)
{
  
    unsigned int  lineStatus;
    unsigned short readLen = 0;
	unsigned int  address = addr;
	lineStatus= *((volatile UINT32 *)((address) + 0x14));
    if (lineStatus & 0x01)  // LSR_DATA_READY == 0x01
    {
        do
        {   
			(*data) = (unsigned char)(*((volatile unsigned int *)((address) + 0))); 
            readLen++;
            data++;
			lineStatus= *((volatile unsigned int *)((address) + 0x14));
        } while ((lineStatus & 0x01) && ( lenToRead != readLen));
       *dataLength = readLen;
    }
    else
    {
        *dataLength = readLen;
        return -1;
    }

    return 0;
}

static void quec_uart_data_recv_cb(char *rcv_buf,int len)
{
	int datalen=0,read_len=0;
	if(rcv_buf == NULL)
		return;
	
	while(1)
	{
		quec_boot_uart_fifo_read(CP_UART_BASE,rcv_buf+datalen,64,&read_len);
		if (read_len>0)
		{
			datalen+=read_len;
			if(datalen>len)
			{
				break;
			}
			delay_ms(2); //等待FIFO数据，115200bit/s 不延迟会出现读取FIFO可能为空
		}
		else
		{
			break;
		}
	}
}

static void quec_boot_uart_receive(void)
{
	char data_buf[128];
	int len = 0;
	memset(data_buf,0,sizeof(data_buf));
	quec_uart_data_recv_cb(data_buf,sizeof(data_buf));
	len = strlen(data_buf);
	if(len)
	{
		if(boot_gpio_cfg.busy_flag!=1){
			memset(boot_gpio_cfg.cmd, 0, QUEC_GPIO_CMD_MAX_LEN);
			memcpy(boot_gpio_cfg.cmd,data_buf,(len>QUEC_GPIO_CMD_MAX_LEN)?QUEC_GPIO_CMD_MAX_LEN : len);
			boot_gpio_cfg.busy_flag = 1;
		}
	
	}
}

static int my_atoi(const char *str)
{
    int total = 0;          //保存转换后的数值
    int isNegative = 0;     //记录字符串中是否有负号
    int length = 0;         //记录字符串的长度
    const char *p = str;
    char temp = '0';
	int i = 0;

    if(NULL == p)           //判断指针的合法性
    {
        uart_printf("error");
        return -1;
    }
    
    while(*p++!='\0')       //计算字符串的长度
    {
        length++;
    }

    p = str;            //重新指向字符串的首地址

    if(*p == '-')           //判断是否有负号
    {
        isNegative = 1;     
    }
    
    for(i = 0;i < length;i++)
    {
        temp = *p++;
        if(temp > '9'||temp < '0')      //滤除非数字字符
        {
            continue;
        }
        if(total != 0||temp != '0')     //滤除字符串开始的0字符
        {
            temp -= '0';
            total = total*10 + temp;
        }
    }

    if(isNegative)                  //如果字符串中有负号，将数值取反
        return (0 - total);
    else
        return total;               //返回转换后的数值
}

static int quec_gpio_cfg_init(char *gpio_cfg)
{
	int ret = -1;
	quec_gpio_cfg_t config;
	memset(&config,0,sizeof(quec_gpio_cfg_t));

	config.gpio_pin_num = gpio_cfg[0];
	config.pin_dir = gpio_cfg[2];
	config.pin_pull = gpio_cfg[3];
	config.pin_level = gpio_cfg[4];

	ret = quec_set_gpio_mfprReg(config.gpio_pin_num,gpio_cfg[1]);
	if(ret){
		uart_printf("quec_set_gpio_mfprReg error pin_num = %d\n",config.gpio_pin_num);
		return -1;
	}
	ret = GpioInitConfiguration(config.gpio_pin_num,config);
	if(ret){
		uart_printf("GpioInitConfiguration error pin_num = %d\n",config.gpio_pin_num);
		return -1;
	}
	return 0;
}


#define  QUEC_MSG_MAX_SEG_LEN   5
#define  QUEC_MSG_MAX_ITEM_NBR  6

static int quec_boot_gpio_cmd_process(void)
{
	int i = 0;
	char *ptr,*retptr;
	char sTmp[QUEC_MSG_MAX_ITEM_NBR][QUEC_MSG_MAX_SEG_LEN];
	memset(sTmp,0,sizeof(sTmp));
	char gpio_cfg[QUEC_MSG_MAX_ITEM_NBR]={0};
	quec_gpio_cfg_t config;
	memset(&config,0,sizeof(quec_gpio_cfg_t));
	int ret = -1;
	ptr = memchr(boot_gpio_cfg.cmd, '=', QUEC_GPIO_CMD_MAX_LEN);
	if (NULL == ptr) {
		return -1;
	}
	
	memcpy(gpio_cfg,boot_gpio_cfg.cmd,ptr-boot_gpio_cfg.cmd);
	ptr++;

	if(!(strcmp(gpio_cfg,"GPIOR"))){
		//把GPIO的配置打印出来
		//GPIOR=GPIOPIN 
		config.gpio_pin_num = my_atoi(ptr);
		ql_gpio_get_level(config.gpio_pin_num,&config.pin_level);
		ql_gpio_get_direction(config.gpio_pin_num,&config.pin_dir);
		ql_gpio_get_pull(config.gpio_pin_num,&config.pin_pull);
		uart_printf("GPIO%d: dir:%s,level:%s,pull:%d\n",config.gpio_pin_num,config.pin_dir?"OUTPUT" : "INPUT",config.pin_level?"HIGH" : "LOW", config.pin_pull);	
	}
	else if(!(strcmp(gpio_cfg,"GPIOW"))){
		//设置GPIO模式，配置GPIO
		//GPIOW=GPIOPIN,fun,dir,pull,pin_level 
		while (((retptr=strtok(ptr, ",")) != NULL) && (i<QUEC_MSG_MAX_ITEM_NBR)){
			strncpy(sTmp[i++], retptr, strlen(retptr)<QUEC_MSG_MAX_SEG_LEN?strlen(retptr):QUEC_MSG_MAX_SEG_LEN);
			ptr = NULL;
		}

		for(i=0;i<QUEC_MSG_MAX_ITEM_NBR;i++){
			if(strlen(sTmp[i]))
			{
				gpio_cfg[i] = my_atoi(sTmp[i]);
			}
		}
		
		//设置GPIO模式
		ret = quec_gpio_cfg_init(gpio_cfg);
		if(ret){
			uart_printf("GPIO%d set failure!!!\n",gpio_cfg[0]);
		}else{
			uart_printf("GPIO%d set success!!!\n",gpio_cfg[0]);
		}
	}
	else{
		return -1;
	}
	return 0;
}

static void quec_boot_cmd_request(void)
{
	if(boot_gpio_cfg.busy_flag){
		quec_boot_gpio_cmd_process();
		boot_gpio_cfg.busy_flag = 0;
	}
	
	return;
}

void ql_boot_gpio_all_pin_test(void)
{
	while(1)
	{
		quec_boot_uart_receive();

		quec_boot_cmd_request();
	}
}
#endif


#endif
