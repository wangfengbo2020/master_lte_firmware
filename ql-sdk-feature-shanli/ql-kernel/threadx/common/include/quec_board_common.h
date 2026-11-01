/*==========================================================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
===========================================================================================================*/
 
/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
2022/04/26        Sharon.li    配置项目硬件的Pin
=================================================================*/

#ifndef _QUEC_BOARD_COMMON_H
#define _QUEC_BOARD_COMMON_H
#include "quec_cust_feature.h"

#define QUEC_PULL_DISABLE       MFP_PULL_NONE //pull disable
#define QUEC_PULL_UP_C          MFP_PULL_HIGH  //Enable pull up resistor
#define QUEC_PULL_DN_C          MFP_PULL_LOW  //Enable pull down resistor
#define QUEC_DRV_VERY_SLOW_C    MFP_DRIVE_VERY_SLOW  //Use slow drive strength
#define QUEC_DRV_SLOW_C         MFP_DRIVE_SLOW  //Use slow drive strength
#define QUEC_DRV_MED_C          MFP_DRIVE_MEDIUM  //Use medium drive strength
#define QUEC_DRV_FAST_C         MFP_DRIVE_FAST  //Use fast drive strength
#define QUEC_AF0_C              MFP_AF0  //Alternate function 0
#define QUEC_AF1_C              MFP_AF1  //Alternate function 1
#define QUEC_AF2_C              MFP_AF2  //Alternate function 2
#define QUEC_AF3_C              MFP_AF3  //Alternate function 3
#define QUEC_AF4_C              MFP_AF4  //Alternate function 4
#define QUEC_AF5_C              MFP_AF5  //Alternate function 5
#define QUEC_AF6_C              MFP_AF6  //Alternate function 6
#define QUEC_AF7_C              MFP_AF7  //Alternate function 7
#define QUEC_RESERVED_C         0x00C0  //RESERVED_C bits that must be set
#define QUEC_PULL_INTERNAL      0x8000  //PullDn/Up is decied by internal resiter.
#define QUEC_SLEEP_OUTPUT       0x0000  /* Output when in sleep. */
#define QUEC_SLEEP_HIGH         0x0100  /* High when in sleep.   */
#define QUEC_SLEEP_INPUT        0x0080  /* jensen.fang 20181030: Input when in sleep. */
#define QUEC_EDGE_RISE_EN       MFP_LPM_EDGE_RISE  /* jensen.fang 20181030: detect a rising edge on a pin. */
#define QUEC_EDGE_FALL_EN       MFP_LPM_EDGE_FALL  /* jensen.fang 20181030: detect a falling edge on a pin. */
#define QUEC_EDGE_CLEAR         MFP_LPM_EDGE_NONE  /* jensen.fang 20181030: The edge-detection logic is disabled and no edge is detected. */
#define QUEC_SLEEP_CTL_ENABLE  (1<<3 |1<<9)  /* Chaim.qian 20181218: enable sleep_mode  control  */

/*************************************************************************************
*NOTES:
* GPIO_MAX_AMOUNT_OF_PINS----No GPIO supports this feature,此项目不支持此引脚功能
*
*
*/
/*---------------------------------------------ASR-3601--ECxxxY系列-------------------------------------------------------------------*/ 
#ifdef QUECTEL_PROJECT_ECXXXY_BOARD_CONFIG
#endif
/*---------------------------------------------ASR-1601--ECxxxS系列---------------------------------------------------*/ 
#ifdef QUECTEL_PROJECT_ECXXXS_BOARD_CONFIG
#endif
/*---------------------------------------------ASR-1603--ECxxxN系列---------------------------------------------------*/ 
#ifdef QUECTEL_PROJECT_ECXXXN_BOARD_CONFIG
#if defined(__QUECTEL_PROJECT_EC600NCN_AA__) || defined (__QUECTEL_PROJECT_EC600NCN_AC__)//evin 20210909 Do not support PA
#define LCC_PA_PIN     GPIO_MAX_AMOUNT_OF_PINS
#define ASR_LCC_PA_PIN GPIO_MAX_AMOUNT_OF_PINS
#endif
#endif

/*--------------------------------------------------ASR-1602--ECxxxK系列------------------------------------------------------*/ 
#if defined (__QUECTEL_PROJECT_EC600KCN_CC__) || defined (__QUECTEL_PROJECT_EC600KCN_LC__)\
	|| defined (__QUECTEL_PROJECT_EC600KCN_CK__) || defined (__QUECTEL_PROJECT_EC600KCN_LK__)\
	|| defined (__QUECTEL_PROJECT_EC600KCN_MC__)
	

#define UART_DTR_PIN_NUM_AF                         (MFP_AF0)     //DTR--复用功能
#define UART_DTR_PIN_NUM                            (GPIO_PIN_73) //DTR
#define UART1_DCD_PIN_NUM_AF	                    (MFP_AF0)     //DCD
#define UART1_DCD_PIN_NUM	                        (GPIO_PIN_74)  //DCD
#define QUEC_APREADY_DET_PIN_AF	                    (MFP_AF0)     //AP_READY
#define QUEC_APREADY_DET_PIN	                    (GPIO_PIN_8) //AP_READY
#define UART1_RI_PIN_NUM_AF	                        (MFP_AF0)     //RI
#define UART1_RI_PIN_NUM	                        (GPIO_PIN_56) //RI
#define IPC_SLEEP_IND_NUM_AF		                (MFP_AF0)     //SLEEP_IND
#define IPC_SLEEP_IND_NUM		                    (GPIO_PIN_1)  //SLEEP_IND
#define QUEC_WAKEUP_IN_GPIO_AF                      (MFP_AF0)     // WAKEUP_IN
#define QUEC_WAKEUP_IN_GPIO                         (GPIO_PIN_3)  // WAKEUP_IN
#define QUEC_NET_MODE_GPIO_AF                       (MFP_AF0)     // NET_MODE----指示网络注册状态
#define QUEC_NET_MODE_GPIO                          (GPIO_PIN_0)  // NET_MODE----指示网络注册状态
#define QUEC_NET_STATUS_GPIO_AF                     (MFP_AF0)     // NET_STATUS----指示网络运行状态
#define QUEC_NET_STATUS_GPIO                        (GPIO_PIN_9)  // NET_STATUS----指示网络运行状态
#define QUEC_AIR_PLAN_CTRL_PIN_AF                   (MFP_AF0)  //W_DISABLE#--fly mode control 复用功能几
#define QUEC_AIR_PLAN_CTRL_PIN                      (GPIO_PIN_68) //W_DISABLE#--fly mode control 
#define QUEC_USIM2_DET_PIN                          (GPIO_MAX_AMOUNT_OF_PINS)  // USIM_DET--SIM2
#define QUEC_POWER_STATUS_PIN_AF                    (MFP_AF0)     //STATUS--power status
#define QUEC_POWER_STATUS_PIN                       (GPIO_PIN_2)  //STATUS--power status
#define QUEC_USIM_DET_PIN_AF                        (MFP_AF1)     //USIM_DET--SIM1
#define QUEC_USIM_DET_PIN                           (GPIO_PIN_85) //USIM_DET--SIM1
#if QUEC_AT_QGPIOEXT_SUPPORT
//Audio Pa Ctrl---推荐控制外部音频PA的引脚
#define LCC_PA_PIN                                  (48)   //QUEC--PIN NO.
#define ASR_LCC_PA_PIN_AF                           (QUEC_AF0_C)
#define ASR_LCC_PA_PIN                              (GPIO_PIN_2)
#endif

//使用GPIO控制CAM的IOVDD
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN_AF              (MFP_AF1)           
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN                 (GPIO_MAX_AMOUNT_OF_PINS)
//使用GPIO控制CAM的VDD
//#define QUEC_GPIO_CTRL_CAMVDD_PIN_AF                (GPIO_PIN_2)           
//#define QUEC_GPIO_CTRL_CAMVDD_PIN                   (GPIO_PIN_49)

#elif defined (__QUECTEL_PROJECT_EC800KCN_CC__) || defined (__QUECTEL_PROJECT_EG800KCN_GC__) \
	|| defined (__QUECTEL_PROJECT_EG800KEU_CC__) || defined (__QUECTEL_PROJECT_EC800KCN_CZ__) \
	|| defined (__QUECTEL_PROJECT_EC800KCN_LC__)||defined (__QUECTEL_PROJECT_EC800KCN_MC__)\
	|| defined (__QUECTEL_PROJECT_EG800KLA_CC__)|| defined (__QUECTEL_PROJECT_EC800KCN_MD__)\
	|| defined (__QUECTEL_PROJECT_EG800KLA_LC__)|| defined (__QUECTEL_PROJECT_EG800KEU_LC__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_CK__) || defined (__QUECTEL_PROJECT_EC800KCN_LK__)
	
#define UART_DTR_PIN_NUM_AF                         (MFP_AF0) //DTR--复用功能
#define UART_DTR_PIN_NUM                            (GPIO_PIN_73) //DTR
#define UART1_DCD_PIN_NUM_AF	                    (MFP_AF0)  //DCD
#define UART1_DCD_PIN_NUM	                        (GPIO_PIN_55)  //DCD
#define QUEC_APREADY_DET_PIN_AF	                    (MFP_AF0)     //AP_READY
#define QUEC_APREADY_DET_PIN	                    (GPIO_MAX_AMOUNT_OF_PINS) //AP_READY
#define UART1_RI_PIN_NUM_AF	                        (MFP_AF0)     //RI
#define UART1_RI_PIN_NUM	                        (GPIO_PIN_74) //RI
#define IPC_SLEEP_IND_NUM_AF		                (MFP_AF0)     //SLEEP_IND
#define IPC_SLEEP_IND_NUM		                    (GPIO_MAX_AMOUNT_OF_PINS)  //SLEEP_IND
#define QUEC_WAKEUP_IN_GPIO_AF                      (MFP_AF0)     // WAKEUP_IN
#define QUEC_WAKEUP_IN_GPIO                         (GPIO_MAX_AMOUNT_OF_PINS)     // WAKEUP_IN
#define QUEC_NET_MODE_GPIO_AF                       (MFP_AF0)     // NET_MODE----指示网络注册状态
#define QUEC_NET_MODE_GPIO                          (GPIO_MAX_AMOUNT_OF_PINS)     // NET_MODE----指示网络注册状态
#define QUEC_NET_STATUS_GPIO_AF                     (MFP_AF1)     // NET_STATUS----指示网络运行状态
#define QUEC_NET_STATUS_GPIO                        (GPIO_PIN_70)  // NET_STATUS----指示网络运行状态
#define QUEC_AIR_PLAN_CTRL_PIN_AF                   (MFP_AF0)  //W_DISABLE#--fly mode control 复用功能几
#define QUEC_AIR_PLAN_CTRL_PIN                      (GPIO_MAX_AMOUNT_OF_PINS) //W_DISABLE#--fly mode control 
#define QUEC_USIM2_DET_PIN                          (GPIO_MAX_AMOUNT_OF_PINS)  // USIM_DET--SIM2
#define QUEC_POWER_STATUS_PIN_AF                    (MFP_AF0)     //STATUS--power status
#define QUEC_POWER_STATUS_PIN                       (GPIO_PIN_68)  //STATUS--power status
#define QUEC_USIM_DET_PIN_AF                        (MFP_AF0)     //USIM_DET--SIM1
#define QUEC_USIM_DET_PIN                           (GPIO_PIN_37) //USIM_DET--SIM1
#if QUEC_AT_QGPIOEXT_SUPPORT
//Audio Pa Ctrl---推荐控制外部音频PA的引脚
#define LCC_PA_PIN                                  (21)   //QUEC--PIN NO.
#define ASR_LCC_PA_PIN_AF                           (QUEC_AF0_C)
#define ASR_LCC_PA_PIN                              (GPIO_PIN_124)
#endif

//使用GPIO控制CAM的IOVDD
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN_AF              (GPIO_MAX_AMOUNT_OF_PINS)           
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN                 (GPIO_MAX_AMOUNT_OF_PINS)
//使用GPIO控制CAM的VDD
//#define QUEC_GPIO_CTRL_CAMVDD_PIN_AF                (GPIO_PIN_2)           
//#define QUEC_GPIO_CTRL_CAMVDD_PIN                   (GPIO_PIN_49)


/*-----------------------------------------------ASR-1606--ECxxxM系列-----------------------------------------------------*/ 
#elif defined (__QUECTEL_PROJECT_EC600MCN_LA__) || defined (__QUECTEL_PROJECT_EC600MCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EC600MCN_CC__)|| defined (__QUECTEL_PROJECT_EC600MCN_GC__)\
	|| defined (__QUECTEL_PROJECT_EC600MCN_MC__)|| defined (__QUECTEL_PROJECT_EC600MCN_LF__)\
	|| defined (__QUECTEL_PROJECT_EC600MCN_LE__)|| defined (__QUECTEL_PROJECT_EC600MCN_NC__)\
	|| defined (__QUECTEL_PROJECT_EC600MEU_LA__)|| defined (__QUECTEL_PROJECT_EC600MLA_LA__)

#define UART_DTR_PIN_NUM_AF                         (MFP_AF0)     //DTR--复用功能
#define UART_DTR_PIN_NUM                            (GPIO_PIN_27) //DTR
#define UART1_DCD_PIN_NUM_AF	                    (MFP_AF0)     //DCD
#define UART1_DCD_PIN_NUM	                        (GPIO_PIN_2)  //DCD
#define QUEC_APREADY_DET_PIN_AF	                    (MFP_AF0)     //AP_READY
#define QUEC_APREADY_DET_PIN	                    (GPIO_PIN_71) //AP_READY
#define UART1_RI_PIN_NUM_AF	                        (MFP_AF0)     //RI
#define UART1_RI_PIN_NUM	                        (GPIO_PIN_31) //RI
#define IPC_SLEEP_IND_NUM_AF		                (MFP_AF0)     //SLEEP_IND
#define IPC_SLEEP_IND_NUM		                    (GPIO_PIN_7)  //SLEEP_IND
#define QUEC_WAKEUP_IN_GPIO_AF                      (MFP_AF0)     // WAKEUP_IN
#define QUEC_WAKEUP_IN_GPIO                         (GPIO_PIN_5)  // WAKEUP_IN
#define QUEC_NET_MODE_GPIO_AF                       (MFP_AF0)     // NET_MODE----指示网络注册状态
#define QUEC_NET_MODE_GPIO                          (GPIO_PIN_6)  // NET_MODE----指示网络注册状态
#define QUEC_NET_STATUS_GPIO_AF                     (MFP_AF1)     // NET_STATUS----指示网络运行状态
#define QUEC_NET_STATUS_GPIO                        (GPIO_PIN_9)  // NET_STATUS----指示网络运行状态
#define QUEC_AIR_PLAN_CTRL_PIN_AF                   (QUEC_AF0_C)  //W_DISABLE#--fly mode control 复用功能几
#define QUEC_AIR_PLAN_CTRL_PIN                      (GPIO_PIN_72) //W_DISABLE#--fly mode control 
#define QUEC_USIM2_DET_PIN                          (GPIO_MAX_AMOUNT_OF_PINS)  // USIM_DET--SIM2
#define QUEC_POWER_STATUS_PIN_AF                    (MFP_AF0)     //STATUS--power status
#define QUEC_POWER_STATUS_PIN                       (GPIO_PIN_4)  //STATUS--power status
#define QUEC_USIM_DET_PIN_AF                        (MFP_AF0)     //USIM_DET--SIM1
#define QUEC_USIM_DET_PIN                           (GPIO_PIN_49) //USIM_DET--SIM1
#if QUEC_AT_QGPIOEXT_SUPPORT
//Audio Pa Ctrl---推荐控制外部音频PA的引脚
#define LCC_PA_PIN                                  (48)   //QUEC--PIN NO.
#define ASR_LCC_PA_PIN_AF                           (QUEC_AF0_C)
#define ASR_LCC_PA_PIN                              (GPIO_PIN_2)
#endif

//使用GPIO控制CAM的IOVDD
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN_AF              (MFP_AF1)           
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN                 (GPIO_PIN_77)
//使用GPIO控制CAM的VDD
//#define QUEC_GPIO_CTRL_CAMVDD_PIN_AF                (GPIO_PIN_2)           
//#define QUEC_GPIO_CTRL_CAMVDD_PIN                   (GPIO_PIN_49)


#elif defined (__QUECTEL_PROJECT_EC800MCN_LA__) || defined (__QUECTEL_PROJECT_EC800MCN_LE__)\
	|| defined (__QUECTEL_PROJECT_EC800MCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_LF__)|| defined (__QUECTEL_PROJECT_EC800MCN_GA__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_GC__)|| defined (__QUECTEL_PROJECT_EC800MCN_GB__)\
	|| defined (__QUECTEL_PROJECT_EC800MCN_GM__) || defined (__QUECTEL_PROJECT_EC800MCN_MC__)\
	|| defined (__QUECTEL_PROJECT_EG810MCN_GA__) || defined (__QUECTEL_PROJECT_EG810MCN_GB__)\
	|| defined (__QUECTEL_PROJECT_EC800MCN_CC__) || defined (__QUECTEL_PROJECT_EC800MCN_NC__)\
	|| defined (__QUECTEL_PROJECT_EC800MCN_GD__) || defined (__QUECTEL_PROJECT_EG810MCN_LA__)\
	|| defined (__QUECTEL_PROJECT_EG810MEU_LA__) || defined (__QUECTEL_PROJECT_EG810MCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EG810MEU_LC__) || defined (__QUECTEL_PROJECT_EG810MLA_LC__)


#define UART_DTR_PIN_NUM_AF                         (MFP_AF0) //DTR--复用功能
#define UART_DTR_PIN_NUM                            (GPIO_PIN_27) //DTR
#define UART1_DCD_PIN_NUM_AF	                    (MFP_AF0)  //DCD
#define UART1_DCD_PIN_NUM	                        (GPIO_PIN_124)  //DCD
#define QUEC_APREADY_DET_PIN_AF	                    (GPIO_MAX_AMOUNT_OF_PINS)     //AP_READY
#define QUEC_APREADY_DET_PIN	                    (GPIO_MAX_AMOUNT_OF_PINS) //AP_READY
#define UART1_RI_PIN_NUM_AF	                        (MFP_AF0)     //RI
#define UART1_RI_PIN_NUM	                        (GPIO_PIN_31) //RI
#define IPC_SLEEP_IND_NUM_AF		                (MFP_AF0)     //SLEEP_IND
#define IPC_SLEEP_IND_NUM		                    (GPIO_PIN_7)  //SLEEP_IND
#define QUEC_WAKEUP_IN_GPIO_AF                      (MFP_AF0)     // WAKEUP_IN
#define QUEC_WAKEUP_IN_GPIO                         (GPIO_PIN_1)     // WAKEUP_IN
#define QUEC_NET_MODE_GPIO_AF                       (GPIO_MAX_AMOUNT_OF_PINS)     // NET_MODE----指示网络注册状态
#define QUEC_NET_MODE_GPIO                          (GPIO_MAX_AMOUNT_OF_PINS)     // NET_MODE----指示网络注册状态
#define QUEC_NET_STATUS_GPIO_AF                     (MFP_AF3)     // NET_STATUS----指示网络运行状态
#define QUEC_NET_STATUS_GPIO                        (GPIO_PIN_6)  // NET_STATUS----指示网络运行状态
#define QUEC_AIR_PLAN_CTRL_PIN_AF                   (GPIO_MAX_AMOUNT_OF_PINS)  //W_DISABLE#--fly mode control 复用功能几
#define QUEC_AIR_PLAN_CTRL_PIN                      (GPIO_MAX_AMOUNT_OF_PINS) //W_DISABLE#--fly mode control 
#define QUEC_USIM2_DET_PIN                          (GPIO_MAX_AMOUNT_OF_PINS)  // USIM_DET--SIM2
#define QUEC_POWER_STATUS_PIN_AF                    (MFP_AF0)     //STATUS--power status
#define QUEC_POWER_STATUS_PIN                       (GPIO_PIN_70)  //STATUS--power status
#define QUEC_USIM_DET_PIN_AF                        (MFP_AF0)     //USIM_DET--SIM1
#define QUEC_USIM_DET_PIN                           (GPIO_PIN_69) //USIM_DET--SIM1
#if QUEC_AT_QGPIOEXT_SUPPORT
//Audio Pa Ctrl---推荐控制外部音频PA的引脚
#define LCC_PA_PIN                                  (21)   //QUEC--PIN NO.
#define ASR_LCC_PA_PIN_AF                           (QUEC_AF0_C)
#define ASR_LCC_PA_PIN                              (GPIO_PIN_124)
#endif

//使用GPIO控制CAM的IOVDD
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN_AF              (GPIO_MAX_AMOUNT_OF_PINS)           
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN                 (GPIO_MAX_AMOUNT_OF_PINS)
//使用GPIO控制CAM的VDD
//#define QUEC_GPIO_CTRL_CAMVDD_PIN_AF                (GPIO_PIN_2)           
//#define QUEC_GPIO_CTRL_CAMVDD_PIN                   (GPIO_PIN_49)

#elif defined (__QUECTEL_PROJECT_EC200MCN_LA__) || defined (__QUECTEL_PROJECT_EC200MCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EC200MCN_GB__) || defined (__QUECTEL_PROJECT_EC200MCN_LE__) \
	|| defined (__QUECTEL_PROJECT_EC200MCN_LF__)

#define UART_DTR_PIN_NUM_AF                         (MFP_AF0) //DTR--复用功能
#define UART_DTR_PIN_NUM                            (GPIO_PIN_27) //DTR
#define UART1_DCD_PIN_NUM_AF	                    (MFP_AF0)  //DCD
#define UART1_DCD_PIN_NUM	                        (GPIO_PIN_28)  //DCD
#define QUEC_APREADY_DET_PIN_AF	                    (MFP_AF0)     //AP_READY
#define QUEC_APREADY_DET_PIN	                    (GPIO_PIN_7) //AP_READY
#define UART1_RI_PIN_NUM_AF	                        (MFP_AF0)     //RI
#define UART1_RI_PIN_NUM	                        (GPIO_PIN_31) //RI
#define IPC_SLEEP_IND_NUM_AF		                (MFP_AF0)     //SLEEP_IND
#define IPC_SLEEP_IND_NUM		                    (GPIO_PIN_4)  //SLEEP_IND
#define QUEC_WAKEUP_IN_GPIO_AF                      (MFP_AF0)     // WAKEUP_IN
#define QUEC_WAKEUP_IN_GPIO                         (GPIO_PIN_8)     // WAKEUP_IN
#define QUEC_NET_MODE_GPIO_AF                       (MFP_AF0)     // NET_MODE----指示网络注册状态
#define QUEC_NET_MODE_GPIO                          (GPIO_PIN_3)     // NET_MODE----指示网络注册状态
#define QUEC_NET_STATUS_GPIO_AF                     (MFP_AF3)     // NET_STATUS----指示网络运行状态
#define QUEC_NET_STATUS_GPIO                        (GPIO_PIN_6)  // NET_STATUS----指示网络运行状态
#define QUEC_AIR_PLAN_CTRL_PIN_AF                   (MFP_AF0)  //W_DISABLE#--fly mode control 复用功能几
#define QUEC_AIR_PLAN_CTRL_PIN                      (GPIO_PIN_5) //W_DISABLE#--fly mode control 
#define QUEC_USIM2_DET_PIN                          (GPIO_PIN_32)  // USIM_DET--SIM2
#define QUEC_POWER_STATUS_PIN_AF                    (MFP_AF0)     //STATUS--power status
#define QUEC_POWER_STATUS_PIN                       (GPIO_PIN_2)  //STATUS--power status
#define QUEC_USIM_DET_PIN_AF                        (MFP_AF0)     //USIM_DET--SIM1
#define QUEC_USIM_DET_PIN                           (GPIO_PIN_13) //USIM_DET--SIM1
#if QUEC_AT_QGPIOEXT_SUPPORT
//Audio Pa Ctrl---推荐控制外部音频PA的引脚
#define LCC_PA_PIN                                  (116)   //QUEC--PIN NO.
#define ASR_LCC_PA_PIN_AF                           (QUEC_AF0_C)
#define ASR_LCC_PA_PIN                              (GPIO_PIN_78)
#endif

//使用GPIO控制CAM的IOVDD
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN_AF              (GPIO_MAX_AMOUNT_OF_PINS)           
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN                 (GPIO_MAX_AMOUNT_OF_PINS)
//使用GPIO控制CAM的VDD
//#define QUEC_GPIO_CTRL_CAMVDD_PIN_AF                (GPIO_PIN_2)           
//#define QUEC_GPIO_CTRL_CAMVDD_PIN                   (GPIO_PIN_49)

#elif defined (__QUECTEL_PROJECT_EC100MCN_LA__)
#define UART_DTR_PIN_NUM_AF                         (MFP_AF0)     //DTR--复用功能
#define UART_DTR_PIN_NUM                            (GPIO_PIN_27) //DTR
#define UART1_DCD_PIN_NUM_AF	                    (MFP_AF0)     //DCD
#define UART1_DCD_PIN_NUM	                        (GPIO_PIN_124)  //DCD
#define QUEC_APREADY_DET_PIN_AF	                    (MFP_AF0)     //AP_READY
#define QUEC_APREADY_DET_PIN	                    (GPIO_PIN_71) //AP_READY
#define UART1_RI_PIN_NUM_AF	                        (MFP_AF0)     //RI
#define UART1_RI_PIN_NUM	                        (GPIO_PIN_31) //RI
#define IPC_SLEEP_IND_NUM_AF		                (MFP_AF0)     //SLEEP_IND
#define IPC_SLEEP_IND_NUM		                    (GPIO_PIN_7)  //SLEEP_IND
#define QUEC_WAKEUP_IN_GPIO_AF                      (MFP_AF0)     // WAKEUP_IN
#define QUEC_WAKEUP_IN_GPIO                         (GPIO_MAX_AMOUNT_OF_PINS)  // WAKEUP_IN
#define QUEC_NET_MODE_GPIO_AF                       (MFP_AF0)     // NET_MODE----指示网络注册状态
#define QUEC_NET_MODE_GPIO                          (GPIO_MAX_AMOUNT_OF_PINS)  // NET_MODE----指示网络注册状态
#define QUEC_NET_STATUS_GPIO_AF                     (MFP_AF1)     // NET_STATUS----指示网络运行状态
#define QUEC_NET_STATUS_GPIO                        (GPIO_PIN_6)  // NET_STATUS----指示网络运行状态
#define QUEC_AIR_PLAN_CTRL_PIN_AF                   (QUEC_AF0_C)  //W_DISABLE#--fly mode control 复用功能几
#define QUEC_AIR_PLAN_CTRL_PIN                      (GPIO_PIN_72) //W_DISABLE#--fly mode control 
#define QUEC_USIM2_DET_PIN                          (GPIO_PIN_3)  // USIM_DET--SIM2
#define QUEC_POWER_STATUS_PIN_AF                    (MFP_AF0)     //STATUS--power status
#define QUEC_POWER_STATUS_PIN                       (GPIO_PIN_13)  //STATUS--power status
#define QUEC_USIM_DET_PIN_AF                        (MFP_AF0)     //USIM_DET--SIM1
#define QUEC_USIM_DET_PIN                           (GPIO_PIN_2) //USIM_DET--SIM1
#if QUEC_AT_QGPIOEXT_SUPPORT
//Audio Pa Ctrl---推荐控制外部音频PA的引脚
#define LCC_PA_PIN                                  (48)   //QUEC--PIN NO.
#define ASR_LCC_PA_PIN_AF                           (QUEC_AF0_C)
#define ASR_LCC_PA_PIN                              (GPIO_PIN_NOT_ASSIGNED)
#endif

//使用GPIO控制CAM的IOVDD
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN_AF              (MFP_AF1)           
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN                 (GPIO_MAX_AMOUNT_OF_PINS)

#elif defined (__QUECTEL_PROJECT_EC600NCN_AC__)
#define UART_DTR_PIN_NUM_AF                         (MFP_AF0)     //DTR--复用功能
#define UART_DTR_PIN_NUM                            (GPIO_PIN_121) //DTR
#define UART1_DCD_PIN_NUM_AF	                    (MFP_AF0)     //DCD
#define UART1_DCD_PIN_NUM	                        (GPIO_PIN_2)  //DCD
#define QUEC_APREADY_DET_PIN_AF	                    (MFP_AF0)     //AP_READY
#define QUEC_APREADY_DET_PIN	                    (GPIO_PIN_4) //AP_READY
#define UART1_RI_PIN_NUM_AF	                        (MFP_AF0)     //RI
#define UART1_RI_PIN_NUM	                        (GPIO_PIN_78) //RI
#define IPC_SLEEP_IND_NUM_AF		                (MFP_AF0)     //SLEEP_IND
#define IPC_SLEEP_IND_NUM		                    (GPIO_PIN_7)  //SLEEP_IND
#define QUEC_WAKEUP_IN_GPIO_AF                      (MFP_AF0)     // WAKEUP_IN
#define QUEC_WAKEUP_IN_GPIO                         (GPIO_PIN_3)  // WAKEUP_IN
#define QUEC_NET_MODE_GPIO_AF                       (MFP_AF0)     // NET_MODE----指示网络注册状态
#define QUEC_NET_MODE_GPIO                          (GPIO_PIN_6)  // NET_MODE----指示网络注册状态
#define QUEC_NET_STATUS_GPIO_AF                     (MFP_AF0)     // NET_STATUS----指示网络运行状态
#define QUEC_NET_STATUS_GPIO                        (GPIO_PIN_9)  // NET_STATUS----指示网络运行状态
#define QUEC_AIR_PLAN_CTRL_PIN_AF                   (QUEC_AF0_C)  //W_DISABLE#--fly mode control 复用功能几
#define QUEC_AIR_PLAN_CTRL_PIN                      (GPIO_PIN_5) //W_DISABLE#--fly mode control 
#define QUEC_USIM2_DET_PIN                          (GPIO_MAX_AMOUNT_OF_PINS)  // USIM_DET--SIM2
#define QUEC_POWER_STATUS_PIN_AF                    (MFP_AF0)     //STATUS--power status
#define QUEC_POWER_STATUS_PIN                       (GPIO_PIN_8)  //STATUS--power status
#define QUEC_USIM_DET_PIN_AF                        (MFP_AF0)     //USIM_DET--SIM1
#define QUEC_USIM_DET_PIN                           (GPIO_PIN_124) //USIM_DET--SIM1
#if QUEC_AT_QGPIOEXT_SUPPORT
//Audio Pa Ctrl---推荐控制外部音频PA的引脚
#define LCC_PA_PIN                                  (48)   //QUEC--PIN NO.
#define ASR_LCC_PA_PIN_AF                           (QUEC_AF0_C)
#define ASR_LCC_PA_PIN                              (GPIO_PIN_NOT_ASSIGNED)
#endif

//使用GPIO控制CAM的IOVDD
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN_AF              (MFP_AF1)           
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN                 (GPIO_MAX_AMOUNT_OF_PINS)
#elif defined (__QUECTEL_PROJECT_EG800PCN_00LA__)
#define UART_DTR_PIN_NUM_AF                         (MFP_AF1)     //DTR--复用功能
#define UART_DTR_PIN_NUM                            (GPIO_PIN_58) //DTR
#define UART1_DCD_PIN_NUM_AF	                    (MFP_AF0)     //DCD
#define UART1_DCD_PIN_NUM	                        (GPIO_PIN_2)  //DCD
#define QUEC_APREADY_DET_PIN_AF	                    (MFP_AF0)     //AP_READY
#define QUEC_APREADY_DET_PIN	                    (GPIO_PIN_4) //AP_READY
#define UART1_RI_PIN_NUM_AF	                        (MFP_AF0)     //RI
#define UART1_RI_PIN_NUM	                        (GPIO_PIN_78) //RI
#define IPC_SLEEP_IND_NUM_AF		                (MFP_AF0)     //SLEEP_IND
#define IPC_SLEEP_IND_NUM		                    (GPIO_PIN_7)  //SLEEP_IND
#define QUEC_WAKEUP_IN_GPIO_AF                      (MFP_AF0)     // WAKEUP_IN
#define QUEC_WAKEUP_IN_GPIO                         (GPIO_PIN_3)  // WAKEUP_IN
#define QUEC_NET_MODE_GPIO_AF                       (MFP_AF0)     // NET_MODE----指示网络注册状态
#define QUEC_NET_MODE_GPIO                          (GPIO_PIN_6)  // NET_MODE----指示网络注册状态
#define QUEC_NET_STATUS_GPIO_AF                     (MFP_AF0)     // NET_STATUS----指示网络运行状态
#define QUEC_NET_STATUS_GPIO                        (GPIO_PIN_29)  // NET_STATUS----指示网络运行状态
#define QUEC_AIR_PLAN_CTRL_PIN_AF                   (QUEC_AF0_C)  //W_DISABLE#--fly mode control 复用功能几
#define QUEC_AIR_PLAN_CTRL_PIN                      (GPIO_PIN_5) //W_DISABLE#--fly mode control 
#define QUEC_USIM2_DET_PIN                          (GPIO_MAX_AMOUNT_OF_PINS)  // USIM_DET--SIM2
#define QUEC_POWER_STATUS_PIN_AF                    (MFP_AF0)     //STATUS--power status
#define QUEC_POWER_STATUS_PIN                       (GPIO_PIN_30)  //STATUS--power status
#define QUEC_USIM_DET_PIN_AF                        (MFP_AF0)     //USIM_DET--SIM1
#define QUEC_USIM_DET_PIN                           (GPIO_PIN_124) //USIM_DET--SIM1
#if QUEC_AT_QGPIOEXT_SUPPORT
//Audio Pa Ctrl---推荐控制外部音频PA的引脚
#define LCC_PA_PIN                                  (48)   //QUEC--PIN NO.
#define ASR_LCC_PA_PIN_AF                           (QUEC_AF0_C)
#define ASR_LCC_PA_PIN                              (GPIO_PIN_NOT_ASSIGNED)
#endif

//使用GPIO控制CAM的IOVDD
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN_AF              (MFP_AF1)           
#define QUEC_GPIO_CTRL_CAMIOVDD_PIN                 (GPIO_MAX_AMOUNT_OF_PINS)

#else
	#error "Please configure the project"
#endif

#define UART_CTS_PIN_NUM_AF 	                     (QUEC_AF0_C)
#define UART_CTS_PIN_NUM 	                         (GPIO_PIN_53) 
#define UART1_RTS_PIN_NUM_AF						 (QUEC_AF0_C)
#define UART1_RTS_PIN_NUM                            (GPIO_PIN_54)
#define UART1_TX_PIN_NUM                             (GPIO_PIN_52)
#define UART1_RX_PIN_NUM                             (GPIO_PIN_51)

#if defined(__QUEC_OEM_VER_WUS__)
#define QUEC_WUS_WAKEUP_SRC4                         GPIO_PIN_4 
#define QUEC_WUS_POWER_IO                            GPIO_PIN_5
#define QUEC_WUSSRC4_GPIO_AF                         MFP_AF0
#define QUEC_WUS_POWER_IO_AF                         MFP_AF0

#endif

/*-----------------------------移远未来系列-----------------------------------*/ 
#endif
