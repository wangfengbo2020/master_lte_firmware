#ifndef E02T_BOARD_CFG_H
#define E02T_BOARD_CFG_H

#include "ql_gpio.h"
#include "ql_uart.h"

/*
 * E02T 硬件版本选择
 * E02T_BOARD_NEW_4G: 新版4G模组
 * 注释掉则使用旧版引脚定义
 */
#define E02T_BOARD_NEW_4G

#ifdef E02T_BOARD_NEW_4G
    #define E02T_MCU_UART_PORT      QL_BT_UART_PORT
    #define AUDIO_PA_CONTRL_PIN     GPIO_PIN_NO_20
    #define CORGET_POC_PTT_PIN      GPIO_PIN_NO_16
    #define GNSS_PWR_PIN            GPIO_PIN_NO_17
#else
    #define E02T_MCU_UART_PORT      QL_MAIN_UART_PORT
    #define AUDIO_PA_CONTRL_PIN     GPIO_PIN_NO_53
    #define CORGET_POC_PTT_PIN      GPIO_PIN_NO_14
    #define GNSS_PWR_PIN            GPIO_PIN_NO_6
#endif

#define GNSS_RSTN_PIN               GPIO_PIN_NO_5
#define E02T_MCU_UART_BAUD          QL_UART_BAUD_115200

/* 测试开关：置 1 则 GPS 模块不下电，方便调试定位 */
#define E02T_GPS_KEEP_ON            0

#endif /* E02T_BOARD_CFG_H */
