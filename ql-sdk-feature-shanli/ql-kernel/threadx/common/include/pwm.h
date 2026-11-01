/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code ("Material") are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel's prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/

//
// PWM API
//

#ifndef PWM_API_H
#define PWM_API_H

#include "global_types.h"
#include "quec_cust_feature.h"
/***************************************************************************/
/***************************************************************************/

typedef enum
{
#if defined QUECTEL_PROJECT_CUST
    PWM_DEVICE_0 = 0,
    PWM_DEVICE_1,
    PWM_DEVICE_2,
    PWM_DEVICE_3,
#endif
    PWM_MAX_DEVICE
} PWM_DEVICE_NUM;



typedef enum
{
    PWM_SHUTDOWN_GRACEFULLY,
    PWM_SHUTDOWN_ABRUPTLY
} PWM_SD;



typedef enum
{
    PWM_OUT_SET_BY_DCYCLE,
    PWM_OUT_SET_FOR_FULL_PERIOD
} PWM_OUT;

#if defined QUECTEL_PROJECT_CUST
typedef enum
{
	PWM_CLK_SRC_13M,
	PWM_CLK_SRC_32K,
}PWM_CLK_SRC;
#endif

typedef struct
{
  PWM_SD        shutdown;    // Graceful(0) or Abruptly(1)
  UINT32        clk_freq;    // The resolution is multiply of 203,125.  13,000,000 MHz is the maximum, minimum is 13000000/64 = 203,125 KHz.
  PWM_OUT       pwm_out;
  UINT16        high_one_cycle_duration;  //Time that PWM_OUT puls is high in term of "clk_freq" define above. This value is written to PWDUTY register.
  UINT16        total_one_cycle_duration; //One cycle of PWM_OUT puls (high and low) in term of "clk_freq" define above. This value is written to PERVAL register.
#if defined QUECTEL_PROJECT_CUST
  PWM_CLK_SRC	clk_src;
#endif
}PWM_CONFIGURE;



typedef enum
 {
    PWM_RC_OK,
    PWM_RC_ERROR,
    PWM_RC_ILLEGALL_FREQUENCY,
    PWM_RC_ILLEGALL_DUTY_CYCLE,
    PWM_RC_ILLEGALL_DEVICE_NUMBER
 }  PWM_ReturnCode;




//PWM API's

PWM_ReturnCode pwmPhase1Init ( void );
PWM_ReturnCode pwmPhase2Init ( void );
PWM_ReturnCode pwmConfigure ( PWM_DEVICE_NUM      PWMn , PWM_CONFIGURE    *configuration );
PWM_ReturnCode pwmConfigureGet ( PWM_DEVICE_NUM     PWMn , PWM_CONFIGURE     *configuration );
PWM_ReturnCode pwmEnable ( PWM_DEVICE_NUM      pwm_num );
PWM_ReturnCode pwmDisable ( PWM_DEVICE_NUM      pwm_num );
#if defined QUECTEL_PROJECT_CUST
void pwm_test(BOOL   on);
#endif


#endif // PWM_API_H
