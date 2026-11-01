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

#ifndef _LEDS_H_
#define _LEDS_H_

#if !defined(_HERMON_A0_SILICON_) && !defined (FLAVOR_MINIPLAT)
#define ENABLE_LEDS
#else
#if defined (BSP_MATHISV1) && !defined (INTEL_2CHIP_PLAT_BVD)
#define ENABLE_LEDS
#endif
#endif

#ifdef ENABLE_LEDS

#if defined (_MANITOBA_EVB_)
#ifdef ENABLE_LEDS
#define     LedsRegister1       (*(volatile WORD    *) 0xc000000)
#ifndef _WHITESAIL_
#define     LedsRegister2       (*(volatile WORD    *) 0xc000040)
#endif

extern UINT32 _ledsImage1;


#define LED_ON(ledNum)       {_ledsImage1 &= (~(0x1UL<<(ledNum+16))); \
                              LedsRegister1 = _ledsImage1;}
#define LED_OFF(ledNum)      {_ledsImage1 |= (0x1UL<<(ledNum+16)); \
                              LedsRegister1 = _ledsImage1;}
#endif
#else/*_MANITOBA_EVB_*/
#endif/*_MANITOBA_EVB_*/


void ledsInit(void);
void ledsBlink(void);
void ledSetOnComm(int ledNo, int setOn);


//Correct for BSP_MATHISV1 && !INTEL_2CHIP_PLAT_BVD
typedef enum CommLedEnumTag
{
    COMM_LED_RED   = 0,
    COMM_LED_GREEN = 1,
    COMM_LED_AMOUNT
}CommLedEnum;

#define  LED_OFF_VAL   0
#define  LED_ON_VAL    1

#else /* ifdef ENABLE_LEDS */

#define ledsInit()
#define ledsBlink()
#define ledSetOnComm(a,b)

#endif /*def ENABLE_LEDS */


#endif/*_LEDS_H_*/
