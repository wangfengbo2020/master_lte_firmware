#ifndef _PLAT_TYPES_H_
#define _PLAT_TYPES_H_

#include "common.h"
//#include "utils.h"
//#include "uart.h"
//#include "cam_types.h"

typedef unsigned long				uint_32;
typedef unsigned short              uint16_t;
typedef unsigned char               uint8_t;
typedef unsigned char               u8;
typedef unsigned int				u32;
typedef unsigned char               BOOL;
typedef unsigned char               uint8;
typedef unsigned short              uint16;
typedef signed int					int32_t;
typedef unsigned char              bool;
typedef int                        INT;
typedef unsigned char                u8;

#define OSA_TICK_FREQ_IN_MILLISEC   5
#define MS_TO_TICKS(n) ((n) / OSA_TICK_FREQ_IN_MILLISEC ? (n) / OSA_TICK_FREQ_IN_MILLISEC : 1)

#define raw_uart_log(fmt, args...) do { uart_printf("[lcd]"fmt, ##args); uart_printf("\r\n"); } while(0)
#define ALIGN(val,exp)                  (((val) + ((exp)-1)) & ~((exp)-1))


#define CONFIG_BOARD_CRANE_EVB_Z2


#define BOARD_ID_CRANE_EVB_V100		0x00
#define BOARD_ID_CRANE_PHONE_V100	0x01

#ifdef WATCHLCDST7789_CODE_USE
#define BOARD_ID_CRANE_WATCH_V100	0x02
#define HW_PLATFORM_4_LINE_SUPPORT
#endif
//temp solution

#ifndef IS_HW_PLATFORM
#ifdef HW_PLATFORM_4_LINE_SUPPORT
	#ifdef WATCHLCDST7789_CODE_USE
	#define IS_HW_PLATFORM(id)	(BOARD_ID_CRANE_WATCH_V100 == (unsigned int)(id))
	#else
	#define IS_HW_PLATFORM(id)	(BOARD_ID_CRANE_PHONE_V100 == (unsigned int)(id))
	#endif
#else
#define IS_HW_PLATFORM(id)	(BOARD_ID_CRANE_EVB_V100 == (unsigned int)(id))
#endif
#endif


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
#define BIT(n) (1<<(n))


#define INVALID_FLAG_ID NULL
#define INVALID_MUTEX_ID NULL
#define INVALID_TIMER_ID NULL

#define PRIVATE static      /*item with scope limited to the module*/
#define PUBLIC              /*specifies an item of public API scope*/

#define PERF_CATCH_TIME 0x1
#define PERF_ALARM_TIME 0x2


#define LCD_ASSERT(cOND) {if (!(cOND)) {raw_uart_log("ASSERT!! %s,%d\r\n", __FUNC__, __LINE__, );while(1);}}

typedef int (*lpEnterD2Callback)(void);
typedef int (*lpExitD2Callback)(BOOL ExitFromD2);
void uiD2CallbackRegister(int id,lpEnterD2Callback enter,lpExitD2Callback exit);
void uiD2CallbackunRegister(int id);

typedef int (*lpEnterC1Callback)(void);
typedef int (*lpExitC1Callback)(void);
void uiC1CallbackRegister(int id,lpEnterC1Callback enter,lpExitC1Callback exit);
void uiC1CallbackunRegister(int id);

void uiSetSuspendFlag(int id,int flag);
void PmicLcdBackLightCtrl(uint8_t brightness);
BOOL Pmic_is_pm812(void);
BOOL Pmic_is_pm813(void);
void Performance_Exit(char * str);
void Performance_Entry(char *str,int mode,int valu1,int value2);


#endif
