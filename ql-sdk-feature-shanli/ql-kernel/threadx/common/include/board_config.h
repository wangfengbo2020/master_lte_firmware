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

/************************************************************************/
/*                                                                      */
/* Title: BOARD CONFIGURATION package                                   */
/*                                                                      */
/* Filename: BOARD_CONFIG.h                                             */
/*                                                                      */
/* Author: Rony Hanina                                                  */
/*                                                                      */
/* Target, subsystem: Common Platform, HAL                              */
/************************************************************************/
#ifndef _BOARD_CONFIG__H_
#define _BOARD_CONFIG__H_
/***************************************************************************/
#include "i2c_eeprom.h"
/***************************************************************************/



typedef enum
{
	BOARD_TYPE_PDK,
	BOARD_TYPE_MATHIS,
	BOARD_TYPE_2
} BOARD_TYPE;

////pinmux_b
#define xlli_MFPR_PHYSICAL_BASE_C              0xD401E000      // MFPR physical register base                                 
                                                                                                                              
#define PULL_UP_C          0xC000  //Enable pull up resistor                                                             
#define PULL_DN_C          0xA000  //Enable pull down resistor                                                           
#define DRV_SLOW_C         0x0800  //Use slow drive strength                                                             
#define DRV_MED_C          0x1000  //Use medium drive strength                                                             
#define DRV_FAST_C         0x1800  //Use fast drive strength                                                              
#define AF0_C              0X0000  //Alternate function 0                                                                 
#define AF1_C              0X0001  //Alternate function 1                                                                 
#define AF2_C              0X0002  //Alternate function 2                                                                 
#define AF3_C              0X0003  //Alternate function 3                                                                 
#define AF4_C              0X0004  //Alternate function 4                                                                 
#define AF5_C              0X0005  //Alternate function 5                                                                 
#define AF6_C              0X0006  //Alternate function 6                                                                 
#define AF7_C              0X0007  //Alternate function 7                                                                 
#define RESERVED_C         0x00C0  //RESERVED_C bits that must be set                                                      
                              
const unsigned long MFPR_offset[] ={                                               
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs   0->7
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs   8->15
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  16->23
        0x0FF,  0x140,  0x144,  0x148,  0x14C,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  24->31
        0x0FF,  0x160,  0x0FF,  0x168,  0x16C,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  32->39
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  40->47
        0x0FF,  0x1A0,  0x1A4,  0x1A8,  0x1AC,  0x1B0,  0x1B4,  0x0FF,   //MFPRs  48->55
		0x2F4,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  56->63
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  64->71
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  72->79
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  80->87
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  88->95
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  96->103
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs 104->111
        0x0FF,  0x0FF,  0x2A8,  0x2AC,  0x2B0,  0x0FF,  0x0FF,  0x0FF ,  //MFPRs 112->119
        0x0FF,  0x0FF,  0x0C8,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF ,  //MFPRs 120->127
		0x260,	0x264,	0x268,	0x26C,	0x270,	0x274,	0x278,	0x27C,
		0x280,	0x284,	0x288,	0x28C,	0x0FF,	0x294,	
		0x2B4,	0x2B8,	0x2BC,	0x2C0,	0x2C4,	0x2C8,	0x2CC,	0x2D0 ,  //
		0x2D4,	0x2D8,	0x2DC,	0x2E0,	0x2E4,	0x2E8,	0x2EC,	
		0x000 // 0x000 marks the end of the table //del GPIO 55 57 58 59 60 124
};

const unsigned long MFPR_offset_1920[] ={                                               
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs   0->7
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs   8->15
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  16->23
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  24->31
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  32->39 
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  40->47
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  48->55
	    0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  56->63
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  64->71
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x1E4,  0x0FF,   //MFPRs  72->79 //GPIO78
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  80->87
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  88->95
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs  96->103
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,   //MFPRs 104->111
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF ,  //MFPRs 112->119
        0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF ,  //MFPRs 120->127
		0x000 // 0x000 marks the end of the table //del GPIO 55 57 58 59 60 124
};


const unsigned long MFPR_offset_emei[] ={                                               
	0x0ff,	0x0ff,	0x0ff,	0x0ff,	0x0ff,	0x0Ff,	0x0Ff,	0x0Ff,	 //MFPRs   0->7
	0x0ff,  0x0ff,  0x104,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs   8->15  10
	0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs  16->23  
	0x0ff,  0x140,  0x144,  0x148,  0x14C,  0x0ff,  0x0ff,  0x0ff,	//MFPRs  24->31  25 26 27 28
	0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs  32->39
	0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs  40->47
	0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs  48->55
	0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs  56->63
	0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs  64->71
	0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs  72->79
	0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs  80->87
	0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs  88->95
	0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs  96->103
	0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs 104->111
	0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs 112->119
	0x0ff,  0x0ff,  0x0c8,  0x0ff,  0x0ff,  0x0ff,  0x0ff,  0x0ff,	//MFPRs 120->127
	0x0FF,  0x0FF,  0x0FF,  0x26c,  0x0FF,  0x0FF,  0x0FF,  0x0FF,
	0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  
	0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF ,	//
	0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF ,
	0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,  0x0FF,
	0x000 // 0x000 marks the end of the table //del GPIO 55 57 58 59 60 124
};     
const unsigned long MFPR_data_emei[] ={                                                                  
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_0   - KP_MKIN[0] - for keypad
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_1   - KP_MKOUT[0]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_2   - KP_MKIN[1]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_3   - KP_MKOUT[1]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_4   - KP_MKIN[2]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_5   - KP_MKOUT[2]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_6   - KP_MKIN[3]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C)             ,//GPIO_7   - KP_MKOUT[3]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_8   - KP_MKIN[4]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C)             ,//GPIO_9   - KP_MKOUT[4]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_10  - KP_MKIN[5]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C)             ,//GPIO_11  - KP_MKOUT[5]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_12  - KP_MKIN[6]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C)             ,//GPIO_13  - KP_MKOUT[6]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_14  - KP_MKIN[7]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C)             ,//GPIO_15  - KP_MKOUT[7]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C)             ,//GPIO_16  - KP_DKIN[0]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C)             ,//GPIO_17  - KP_DKIN[1]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C)             ,//GPIO_18  - KP_DKIN[2]
         (PULL_UP_C  | DRV_SLOW_C | RESERVED_C | AF0_C)             ,//GPIO_19  - KP_DKIN[3]
         (PULL_DN_C  | DRV_MED_C  | RESERVED_C | AF0_C)             ,//GPIO_20  - SSP_SYSCLK - for audio codec (I2S mode)
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_21  - SSP_BITCLK
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_22  - SSP_SYNC
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_23  - SSP_DATA_OUT
         (PULL_DN_C  | DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_24  - SSP_SDATA_IN
         (DRV_MED_C  | RESERVED_C | AF1_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_25  - 
         (DRV_MED_C  | RESERVED_C | AF1_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_26  - 
         (DRV_MED_C  | RESERVED_C | AF1_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_27  - 
         (DRV_MED_C  | RESERVED_C | AF1_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_28  - 
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF0_C)  ,  //GPIO_29  -                          
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF0_C)  ,  //GPIO_30  -     
         
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF0_C) ,  //GPIO_31  -                          
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF0_C) ,  //GPIO_32  -                          
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF5_C) ,  //GPIO_33  -                          
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF5_C) ,  //GPIO_34  -                          
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF5_C) ,  //GPIO_35  -                          
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF5_C) ,   //GPIO_36  - 
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF1_C) , //GPIO_37  - 
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF1_C) , //GPIO_38  - 
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF1_C) , //GPIO_39  - 
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF1_C) , //GPIO_40  - 
         
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF1_C) , //GPIO_41  - 
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF1_C) , //GPIO_42  - 
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF0_C) , //GPIO_43  -
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF0_C) , //GPIO_44  - 
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF1_C), // GPIO_45  -
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF1_C), // GPIO_46  - 
         (PULL_UP_C  | DRV_MED_C | RESERVED_C | AF6_C) , // GPIO_47  - UART1_RXD - for debug UART
         (PULL_UP_C  | DRV_MED_C | RESERVED_C | AF6_C) , // GPIO_48  - UART1_TXD
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF0_C) ,// GPIO_49  -                   //
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF0_C) ,// GPIO_50  -                   //

		 
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF1_C) , //(PULL_UP_C  | DRV_MED_C | RESERVED_C | AF1_C),   //GPIO_51  - CP_UART_RXD 
         (PULL_UP_C  | DRV_MED_C  | RESERVED_C | AF1_C) , //(DRV_MED_C | RESERVED_C | AF1_C)             , //GPIO_52  - CP_UART_TXD
        (PULL_UP_C | DRV_SLOW_C | RESERVED_C | AF2_C)   , // GPIO_53  - I2C_SCL - for I2C bus
        (PULL_UP_C | DRV_SLOW_C | RESERVED_C | AF2_C)   , // GPIO_54  - I2C_SDA
        
        0x00C0, // GPIO_55  -  0x2F0
        0xC0C0, // GPIO_56  -  0x2F4
        0x00C0, // GPIO_57  -  0x2F8
        0x00C0, // GPIO_58  -  0x2FC
        0x00C0, // GPIO_59  -  0x300
        0x00C0, //  0x304     pinmux_b   (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,//0x00C0  ; GPIO_60  - 
        0x00C0 ,//0x00C0  ; GPIO_61  - 
        0x00C0,//  0x30c      pinmux_b    (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,//0x00C0  ; GPIO_62  - 
        0x00C0 ,//0x00C0  ; GPIO_63  - 
        0x00C0 ,//0x00C0  ; GPIO_64  - 
        0x00C0,//  0x318      pinmux_b  (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,//0x00C0  ; GPIO_65  -
        0x00C0 ,//0x00C0  ; GPIO_66  - 
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_67  - CCIC_IN[7] - for camera interface
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_68  - CCIC_IN[6]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_69  - CCIC_IN[5]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_70  - CCIC_IN[4]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_71  - CCIC_IN[3]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_72  - CCIC_IN[2]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_73  - CCIC_IN[1]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_74  - CCIC_IN[0]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_75  - CAM_HSYNC
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_76  - CAM_VSYNC
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_77  - CAM_MCLK
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_78  - CAM_PCLK
        
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C) ,  //GPIO_79  - 
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C) ,  //GPIO_80  - 

        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C),  //GPIO_81  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_81  - LCD FCLK - for primary LCD
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C),  //GPIO_82  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_82  - LDC LCLK
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C),  //GPIO_83  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_83  - LCD PCLK
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C),  //GPIO_84  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_84  - LCD DENA
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C)  ,   //GPIO_85  - LCD DD[0]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C)  ,   //GPIO_86  - LCD DD[1]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF5_C)  ,   //GPIO_87  - LCD DD[2]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF5_C)  ,   //GPIO_88  - LCD DD[3]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF5_C)  ,   //GPIO_89  - LCD DD[4]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF5_C)  ,   //GPIO_90  - LCD DD[5]
        
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C)  ,   //GPIO_91  - LCD DD[6]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C)  ,   //GPIO_92  - LCD DD[7]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C)  ,   //GPIO_93  - LCD DD[8]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C)  ,   //GPIO_94  - LCD DD[9]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C)  ,   //GPIO_95  - LCD DD[10]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C)  ,   //GPIO_96  - LCD DD[11]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C)  ,   //GPIO_97  - LCD DD[12]
        (PULL_UP_C | DRV_FAST_C | RESERVED_C | AF0_C)  ,   //GPIO_98  - LCD DD[13]
        
        0x00C0 , // GPIO_99  -            //
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_100 - LCD DD[14]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_101 - LCD DD[15]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_102 - LCD DD[16]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_103 - LCD DD[17]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_104 - LCD DD[18]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_105 - LCD DD[19]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_106 - LCD DD[20]
        (DRV_FAST_C | RESERVED_C | AF1_C)   ,   //GPIO_107 - LCD DD[21]
        (DRV_FAST_C | RESERVED_C | AF1_C)   ,   //GPIO_108 - LCD DD[22]
        (DRV_FAST_C | RESERVED_C | AF1_C)   ,   //GPIO_109 - LCD DD[23]
        (PULL_UP_C | RESERVED_C | AF1_C) , //0x00C0  GPIO_110 -   ;pinmux_a
        (DRV_MED_C | RESERVED_C | AF1_C) , //0x00C0  GPIO_111 - 
        (DRV_MED_C | RESERVED_C | AF1_C) , //0x00C0  GPIO_112 -
        (DRV_MED_C | RESERVED_C | AF1_C) , //0x00C0  GPIO_113 - 
        (PULL_UP_C | RESERVED_C | AF1_C) , //0x00C0  GPIO_114 -  ;pinmux_a
        (PULL_UP_C | RESERVED_C | AF1_C) , //0x00C0  GPIO_115 -  ;pinmux_a
        (PULL_UP_C | RESERVED_C | AF1_C) , //0x00C0  GPIO_116 -  ;pinmux_a
        0x00C0  ,///GPIO_117 - 
        0x00C0  ,///GPIO_118 - 
        0x00C0  ,///GPIO_119 - 
        0x00C0  ,///GPIO_120 - 
        0x00C0  ,///GPIO_121 - 
        (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,// ; (PULL_UP_C | DRV_MED_C | RESERVED_C | AF1_C) ; 0x00C0  ; GPIO_122 - 
        0x00C0,  // GPIO_123 - 
        (DRV_FAST_C | RESERVED_C | AF1_C) , // GPIO_124 - //for MN_CLK_OUT -- audio.
        0x00C0 ,  //GPIO_125 - 
        0x00C0 , //GPIO_126 - 
        0x00C0 , //GPIO_127 - 
        //pinmux_a
		  0x00C0 , //0x260
		  0x00C0 , //0x264
 		  0x00C0 , //0x268
		  (PULL_UP_C | RESERVED_C | AF6_C) , //0x26C
		  0x00C0 , //0x270
		  0x00C0 , //0x274
		  0x00C0 , //0x278
		  0x00C0 , //0x27C
		  0x00C0 , //0x280
		  0xA0C0 , //0x284
		  0x00C0 , //0x288
		  0xA0C0 , //0x28C
		  0x80C0 , //0x290
		  0x00C0 , //0x294
		         
		  0x00C0 , // 0xd401E2B4
		  0x00C0 , // 0xd401E2B8											
		  0x00C0 , // 0xd401E2BC											
		  0x00C0 , // 0xd401E2C0											
		  0x00C0 , // 0xd401E2C4											
		  0x00C0 , // 0xd401E2C8											
		  0x00C0 , // 0xd401E2CC											
		  0x00C0 , // 0xd401E2D0											
		  0x00C0 , // 0xd401E2D4											
		  0x00C0 , // 0xd401E2D8											
		  0x00C0 , // 0xd401E2DC											
		  0x00C0 , // 0xd401E2E0											
		  0x00C0 , // 0xd401E2E4											
		  0x00C0 , // 0xd401E2E8											
		  0x00C0 , // 0xd401E2EC	
		  (PULL_UP_C | RESERVED_C | AF1_C),   //0xd401e074
		  (PULL_UP_C | RESERVED_C | AF1_C),   //0xd401e078
		  (PULL_UP_C | RESERVED_C | AF1_C),   //0xd401e07c
		  (PULL_UP_C | RESERVED_C | AF0_C),   //0xd401e070
		  (PULL_UP_C | RESERVED_C | AF1_C),   //0xd401e04c
		  (PULL_UP_C | RESERVED_C | AF1_C),   //0xd401e050
		  (PULL_UP_C | RESERVED_C | AF1_C),   //0xd401e048
};       
const unsigned long MFPR_offset_Intel_EVT[] ={                                               
		 //MFPRs 
		0x048,  0x04C,  0x050,  0x078,
        0x140,  0x144,  0x148,  0x14C, //MFPRs  25->31
        0x160,  0x168,  0x16C,  //MFPRs  32->39
        0x1A0,  0x1A4,  0x1A8,  0x1AC,  0x1B0,  0x1B4, //MFPRs  48->55
		0x2F4,  //MFPRs  56->63
         //MFPRs 104->111
        0x2A0,  0x2A4 , 0x2A8,  0x2AC,  0x2B0,    //MFPRs 112->119
        0x0C8,   //MFPRs 120->127
		0x260,	0x264,	0x268,	0x26C,	0x270,	0x274,	0x278,	0x27C,
		0x280,	0x284,	0x288,	0x28C,	0x0FF,	0x294,	0x29C,
		0x2B4,	0x2B8,	0x2BC,	0x2C0,	0x2C4,	0x2C8,	0x2CC,	0x2D0 ,  //
		0x2D4,	0x2D8,	0x2DC,	0x2E0,	0x2E4,	0x2E8,	0x2EC,0x304,0x298,	
		0x000 // 0x000 marks the end of the table //del GPIO 55 57 58 59 60 124
};     

const unsigned long MFPR_data_1920[] ={                                                                  
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_0   - KP_MKIN[0] - for keypad
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_1   - KP_MKOUT[0]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_2   - KP_MKIN[1]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_3   - KP_MKOUT[1]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_4   - KP_MKIN[2]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_5   - KP_MKOUT[2]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_6   - KP_MKIN[3]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_7   - KP_MKOUT[3]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_8   - KP_MKIN[4]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_9   - KP_MKOUT[4]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_10  - KP_MKIN[5]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_11  - KP_MKOUT[5]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_12  - KP_MKIN[6]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_13  - KP_MKOUT[6]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_14  - KP_MKIN[7]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_15  - KP_MKOUT[7]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_16  - KP_DKIN[0]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_17  - KP_DKIN[1]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_18  - KP_DKIN[2]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_19  - KP_DKIN[3]
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_20  - SSP_SYSCLK - for audio codec (I2S mode)
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_21  - SSP_BITCLK
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_22  - SSP_SYNC
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_23  - SSP_DATA_OUT
         0x00C0             ,//GPIO_24  - SSP_SDATA_IN //gh_zh
        (0x9000 |DRV_MED_C  | RESERVED_C | AF1_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_25  - 
         (0x9000 |DRV_MED_C  | RESERVED_C | AF1_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_26  - 
         (0x9000 |DRV_MED_C  | RESERVED_C | AF1_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_27  - 
         (0x9000 |DRV_MED_C  | RESERVED_C | AF1_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_28  - 
         0x00C0 ,  //GPIO_29  -                          
         0x00C0 ,  //GPIO_30  -                          
         0x00C0 ,  //GPIO_31  -      // gh_zh_end
         0x00C0 ,  //GPIO_32  -                          
         0x00C0 ,  //GPIO_33  -                          
         0x00C0 ,  //GPIO_34  -                          
         (DRV_MED_C  | RESERVED_C | AF0_C) ,  //GPIO_35  -      //for GPIO                 
         (DRV_MED_C  | RESERVED_C | AF0_C) ,   //GPIO_36  -    //for GPIO
         0x00C0 , //GPIO_37  - 
         0x00C0 , //GPIO_38  - 
         0x00C0 , //GPIO_39  - 
         0x00C0 , //GPIO_40  - 
         0x00C0 , //GPIO_41  - 
         0x00C0 , //GPIO_42  - 
         0x00C0 , //(PULL_UP_C  | DRV_MED_C | RESERVED_C | AF7_C) ,  //GPIO_43  - CP_UART_RXD 
         0x00C0 , //(DRV_MED_C | RESERVED_C | AF7_C)              ,//GPIO_44  - CP_UART_TXD
         0x00C0, // GPIO_45  -
         0x00C0, // GPIO_46  - 
         0x00C0 , //(PULL_UP_C  | DRV_MED_C | RESERVED_C | AF6_C) , // GPIO_47  - UART1_RXD - for debug UART
         0x00C0 , //(PULL_UP_C  | DRV_MED_C | RESERVED_C | AF6_C) , // GPIO_48  - UART1_TXD
         (DRV_MED_C  | RESERVED_C | AF0_C) ,// GPIO_49  -           //for GPIO
         (DRV_MED_C  | RESERVED_C | AF0_C) ,// GPIO_50  -           //for GPIO
         0xd0C1 ,// GPIO_51  - 
         0xd0C1 ,// GPIO_52  - 
        (DRV_SLOW_C | RESERVED_C | AF2_C)   , // GPIO_53  - I2C_SCL - for I2C bus
        (DRV_SLOW_C | RESERVED_C | AF2_C)   , // GPIO_54  - I2C_SDA
        0x00C0, // GPIO_55  -  0x2F0
        0x00C0, // GPIO_56  -  0x2F4
        0x00C0, // GPIO_57  -  0x2F8
        0x00C0, // GPIO_58  -  0x2FC
        0x00C0, // GPIO_59  -  0x300 
        (PULL_UP_C | RESERVED_C | AF0_C), //td_y1 //  0x304     pinmux_b   (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,//0x00C0  ; GPIO_60  - 
 
        //pull up or pull down?
        0x1845 ,//0X1845, 0x00C0  ; GPIO_61  - 
        0x1845, //0X1845,   0x30c      pinmux_b    (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,//0x00C0  ; GPIO_62  - 
        0x1845 ,//0X1845,  ; GPIO_63  - 
        0x1845 ,//0X1845,   ; GPIO_64  - 
        0x1845, //0X1845,       pinmux_b  (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,//0x00C0  ; GPIO_65  -
        0x1845 ,//0X1845,   ; GPIO_66  - 
        //td_y1 end

        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_67  - CCIC_IN[7] - for camera interface
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_68  - CCIC_IN[6]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_69  - CCIC_IN[5]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_70  - CCIC_IN[4]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_71  - CCIC_IN[3]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_72  - CCIC_IN[2]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_73  - CCIC_IN[1]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_74  - CCIC_IN[0]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_75  - CAM_HSYNC
        0xB000,//gh_zh GPIO76 PullDown
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_77  - CAM_MCLK
        0xB000,//GPIO_78  - CAM_PCLK //gh_zh GPIO78 PullDown
        0xC0C0,  //GPIO_79  - 
        0x00C0,  //GPIO_80  - 
        0x00C0,  //GPIO_81  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_81  - LCD FCLK - for primary LCD
        0x00C0,  //GPIO_82  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_82  - LDC LCLK
        0x00C0,  //GPIO_83  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_83  - LCD PCLK
        0x00C0,  //GPIO_84  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_84  - LCD DENA
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_85  - LCD DD[0]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_86  - LCD DD[1]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_87  - LCD DD[2]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_88  - LCD DD[3]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_89  - LCD DD[4]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_90  - LCD DD[5]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_91  - LCD DD[6]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_92  - LCD DD[7]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_93  - LCD DD[8]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_94  - LCD DD[9]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_95  - LCD DD[10]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_96  - LCD DD[11]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_97  - LCD DD[12]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_98  - LCD DD[13]
        0x00C0 , // GPIO_99  -            //
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_100 - LCD DD[14]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_101 - LCD DD[15]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_102 - LCD DD[16]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_103 - LCD DD[17]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_104 - LCD DD[18]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_105 - LCD DD[19]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_106 - LCD DD[20]
        (DRV_FAST_C | RESERVED_C | AF1_C)   ,   //GPIO_107 - LCD DD[21]
        (DRV_FAST_C | RESERVED_C | AF1_C)   ,   //GPIO_108 - LCD DD[22]
        (DRV_FAST_C | RESERVED_C | AF1_C)   ,   //GPIO_109 - LCD DD[23]
        (PULL_DN_C  | RESERVED_C | AF4_C) , //td_y1 0x00C0  GPIO_110 -   ;pinmux_a
        (PULL_DN_C  | RESERVED_C | AF4_C) , //td_y1 0x00C0  GPIO_111 - 
        (RESERVED_C | AF4_C),  //td_y1 gwl_y0 func?  (DRV_MED_C | RESERVED_C | AF1_C) , // 0x00C0  GPIO_112 -
        (PULL_UP_C  | RESERVED_C | AF0_C) , //0x00C0  GPIO_113 - 
        (RESERVED_C | AF1_C) , //0x00C0  GPIO_114 -  ;pinmux_a
        (RESERVED_C | AF1_C) , //0x00C0  GPIO_115 -  ;pinmux_a
        (RESERVED_C | AF1_C) , //0x00C0  GPIO_116 -  ;pinmux_a
        0x00C0  ,///GPIO_117 - 
        0x00C0  ,///GPIO_118 - 
        0x00C0  ,///GPIO_119 - 
        0x00C0  ,///GPIO_120 - 
        0x00C0  ,///GPIO_121 - 
        (PULL_DN_C | DRV_MED_C | RESERVED_C | AF0_C) ,// ; (PULL_UP_C | DRV_MED_C | RESERVED_C | AF1_C) ; 0x00C0  ; GPIO_122 - 
        0x00C0,  // GPIO_123 - 
        (DRV_FAST_C | RESERVED_C | AF1_C) , // GPIO_124 - //for MN_CLK_OUT -- audio.
        0x00C0 ,  //GPIO_125 - 
        0x00C0 , //GPIO_126 - 
        0x00C0 , //GPIO_127 - 
        //pinmux_a
		  0xA0C0 , //0x260
		  0xA0C0 , //0x264
 		  0x00C0 , //0x268
		  0x00C0 , //0x26C
		  0x00C0 , //0x270
		  0x00C0 , //0x274
		  0xA0C0 , //0x278
		  0xA0C0 , //0x27C
		  0xA0C0 , //0x280
		  0xA0C0 , //0x284
		  0xA0C0 , //0x288
		  0xA0C0 , //0x28C
		  0xA0C0 , //0x290
		  0xA0C0 , //0x294
		         
		  0xA0C0 , // 0xd401E2B4
		  0xA0C0 , // 0xd401E2B8											
		  0xA0C0 , // 0xd401E2BC											
		  0xA0C0 , // 0xd401E2C0											
		  0xA0C0 , // 0xd401E2C4											
		  0xA0C0 , // 0xd401E2C8											
		  0xA0C0 , // 0xd401E2CC											
		  0xA0C0 , // 0xd401E2D0											
		  0xA0C0 , // 0xd401E2D4											
		  0xA0C0 , // 0xd401E2D8											
		  0xA0C0 , // 0xd401E2DC											
		  0x00C0 , // 0xd401E2E0											
		  0x00C0 , // 0xd401E2E4											
		  0x00C0 , // 0xd401E2E8											
		  0x00C0 , // 0xd401E2EC		
}; 


const unsigned long MFPR_data[] ={                                                                  
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_0   - KP_MKIN[0] - for keypad
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_1   - KP_MKOUT[0]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_2   - KP_MKIN[1]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_3   - KP_MKOUT[1]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_4   - KP_MKIN[2]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_5   - KP_MKOUT[2]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_6   - KP_MKIN[3]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_7   - KP_MKOUT[3]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_8   - KP_MKIN[4]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_9   - KP_MKOUT[4]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_10  - KP_MKIN[5]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_11  - KP_MKOUT[5]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_12  - KP_MKIN[6]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_13  - KP_MKOUT[6]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_14  - KP_MKIN[7]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_15  - KP_MKOUT[7]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_16  - KP_DKIN[0]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_17  - KP_DKIN[1]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_18  - KP_DKIN[2]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_19  - KP_DKIN[3]
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_20  - SSP_SYSCLK - for audio codec (I2S mode)
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_21  - SSP_BITCLK
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_22  - SSP_SYNC
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_23  - SSP_DATA_OUT
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_24  - SSP_SDATA_IN
         (0x9000 |DRV_MED_C  | RESERVED_C | AF1_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_25  - 
         (0x9000 |DRV_MED_C  | RESERVED_C | AF1_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_26  - 
         (0x9000 |DRV_MED_C  | RESERVED_C | AF1_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_27  - 
         (0x9000 |DRV_MED_C  | RESERVED_C | AF1_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_28  - 
         0x00C0 ,  //GPIO_29  -                          
         0x00C0 ,  //GPIO_30  -                          
         0x00C0 ,  //GPIO_31  -                          
         0x00C0 ,  //GPIO_32  -                          
         0x00C0 ,  //GPIO_33  -                          
         0x00C0 ,  //GPIO_34  -                          
         (DRV_MED_C  | RESERVED_C | AF0_C) ,  //GPIO_35  -      //for GPIO                 
         (DRV_MED_C  | RESERVED_C | AF0_C) ,   //GPIO_36  -    //for GPIO
         0x00C0 , //GPIO_37  - 
         0x00C0 , //GPIO_38  - 
         0x00C0 , //GPIO_39  - 
         0x00C0 , //GPIO_40  - 
         0x00C0 , //GPIO_41  - 
         0x00C0 , //GPIO_42  - 
         0x00C0 , //(PULL_UP_C  | DRV_MED_C | RESERVED_C | AF7_C) ,  //GPIO_43  - CP_UART_RXD 
         0x00C0 , //(DRV_MED_C | RESERVED_C | AF7_C)              ,//GPIO_44  - CP_UART_TXD
         0x00C0, // GPIO_45  -
         0x00C0, // GPIO_46  - 
         0x00C0 , //(PULL_UP_C  | DRV_MED_C | RESERVED_C | AF6_C) , // GPIO_47  - UART1_RXD - for debug UART
         0x00C0 , //(PULL_UP_C  | DRV_MED_C | RESERVED_C | AF6_C) , // GPIO_48  - UART1_TXD
         (DRV_MED_C  | RESERVED_C | AF0_C) ,// GPIO_49  -           //for GPIO
         (DRV_MED_C  | RESERVED_C | AF0_C) ,// GPIO_50  -           //for GPIO
         0xd0C1 ,// GPIO_51  - 
         0xd0C1 ,// GPIO_52  - 
        (DRV_SLOW_C | RESERVED_C | AF2_C)   , // GPIO_53  - I2C_SCL - for I2C bus
        (DRV_SLOW_C | RESERVED_C | AF2_C)   , // GPIO_54  - I2C_SDA
        0x00C0, // GPIO_55  -  0x2F0
        0x00C0, // GPIO_56  -  0x2F4
        0x00C0, // GPIO_57  -  0x2F8
        0x00C0, // GPIO_58  -  0x2FC
        0x00C0, // GPIO_59  -  0x300 
        (PULL_UP_C | RESERVED_C | AF0_C), //td_y1 //  0x304     pinmux_b   (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,//0x00C0  ; GPIO_60  - 
 
        //pull up or pull down?
        0x1845 ,//0X1845, 0x00C0  ; GPIO_61  - 
        0x1845, //0X1845,   0x30c      pinmux_b    (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,//0x00C0  ; GPIO_62  - 
        0x1845 ,//0X1845,  ; GPIO_63  - 
        0x1845 ,//0X1845,   ; GPIO_64  - 
        0x1845, //0X1845,       pinmux_b  (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,//0x00C0  ; GPIO_65  -
        0x1845 ,//0X1845,   ; GPIO_66  - 
        //td_y1 end

        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_67  - CCIC_IN[7] - for camera interface
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_68  - CCIC_IN[6]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_69  - CCIC_IN[5]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_70  - CCIC_IN[4]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_71  - CCIC_IN[3]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_72  - CCIC_IN[2]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_73  - CCIC_IN[1]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_74  - CCIC_IN[0]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_75  - CAM_HSYNC
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_76  - CAM_VSYNC
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_77  - CAM_MCLK
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_78  - CAM_PCLK
        0xC0C0,  //GPIO_79  - 
        0x00C0,  //GPIO_80  - 
        0x00C0,  //GPIO_81  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_81  - LCD FCLK - for primary LCD
        0x00C0,  //GPIO_82  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_82  - LDC LCLK
        0x00C0,  //GPIO_83  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_83  - LCD PCLK
        0x00C0,  //GPIO_84  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_84  - LCD DENA
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_85  - LCD DD[0]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_86  - LCD DD[1]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_87  - LCD DD[2]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_88  - LCD DD[3]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_89  - LCD DD[4]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_90  - LCD DD[5]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_91  - LCD DD[6]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_92  - LCD DD[7]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_93  - LCD DD[8]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_94  - LCD DD[9]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_95  - LCD DD[10]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_96  - LCD DD[11]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_97  - LCD DD[12]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_98  - LCD DD[13]
        0x00C0 , // GPIO_99  -            //
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_100 - LCD DD[14]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_101 - LCD DD[15]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_102 - LCD DD[16]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_103 - LCD DD[17]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_104 - LCD DD[18]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_105 - LCD DD[19]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_106 - LCD DD[20]
        (DRV_FAST_C | RESERVED_C | AF1_C)   ,   //GPIO_107 - LCD DD[21]
        (DRV_FAST_C | RESERVED_C | AF1_C)   ,   //GPIO_108 - LCD DD[22]
        (DRV_FAST_C | RESERVED_C | AF1_C)   ,   //GPIO_109 - LCD DD[23]
        (PULL_DN_C  | RESERVED_C | AF4_C) , //td_y1 0x00C0  GPIO_110 -   ;pinmux_a
        (PULL_DN_C  | RESERVED_C | AF4_C) , //td_y1 0x00C0  GPIO_111 - 
        (RESERVED_C | AF4_C),  //td_y1 gwl_y0 func?  (DRV_MED_C | RESERVED_C | AF1_C) , // 0x00C0  GPIO_112 -
        (PULL_UP_C  | RESERVED_C | AF0_C) , //0x00C0  GPIO_113 - 
        (RESERVED_C | AF1_C) , //0x00C0  GPIO_114 -  ;pinmux_a
        (RESERVED_C | AF1_C) , //0x00C0  GPIO_115 -  ;pinmux_a
        (RESERVED_C | AF1_C) , //0x00C0  GPIO_116 -  ;pinmux_a
        0x00C0  ,///GPIO_117 - 
        0x00C0  ,///GPIO_118 - 
        0x00C0  ,///GPIO_119 - 
        0x00C0  ,///GPIO_120 - 
        0x00C0  ,///GPIO_121 - 
        (PULL_DN_C | DRV_MED_C | RESERVED_C | AF0_C) ,// ; (PULL_UP_C | DRV_MED_C | RESERVED_C | AF1_C) ; 0x00C0  ; GPIO_122 - 
        0x00C0,  // GPIO_123 - 
        (DRV_FAST_C | RESERVED_C | AF1_C) , // GPIO_124 - //for MN_CLK_OUT -- audio.
        0x00C0 ,  //GPIO_125 - 
        0x00C0 , //GPIO_126 - 
        0x00C0 , //GPIO_127 - 
        //pinmux_a
		  0xA0C0 , //0x260
		  0xA0C0 , //0x264
 		  0x00C0 , //0x268
		  0x00C0 , //0x26C
		  0x00C0 , //0x270
		  0x00C0 , //0x274
		  0xA0C0 , //0x278
		  0xA0C0 , //0x27C
		  0xA0C0 , //0x280
		  0xA0C0 , //0x284
		  0xA0C0 , //0x288
		  0xA0C0 , //0x28C
		  0xA0C0 , //0x290
		  0xA0C0 , //0x294
		         
		  0xA0C0 , // 0xd401E2B4
		  0xA0C0 , // 0xd401E2B8											
		  0xA0C0 , // 0xd401E2BC											
		  0xA0C0 , // 0xd401E2C0											
		  0xA0C0 , // 0xd401E2C4											
		  0xA0C0 , // 0xd401E2C8											
		  0xA0C0 , // 0xd401E2CC											
		  0xA0C0 , // 0xd401E2D0											
		  0xA0C0 , // 0xd401E2D4											
		  0xA0C0 , // 0xd401E2D8											
		  0xA0C0 , // 0xd401E2DC											
		  0x00C0 , // 0xd401E2E0											
		  0x00C0 , // 0xd401E2E4											
		  0x00C0 , // 0xd401E2E8											
		  0x00C0 , // 0xd401E2EC											
};  


const unsigned long MFPR_data_APSE[] ={                                                                  
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_0   - KP_MKIN[0] - for keypad
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_1   - KP_MKOUT[0]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_2   - KP_MKIN[1]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_3   - KP_MKOUT[1]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_4   - KP_MKIN[2]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_5   - KP_MKOUT[2]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_6   - KP_MKIN[3]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_7   - KP_MKOUT[3]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_8   - KP_MKIN[4]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_9   - KP_MKOUT[4]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_10  - KP_MKIN[5]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_11  - KP_MKOUT[5]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_12  - KP_MKIN[6]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_13  - KP_MKOUT[6]
         (PULL_DN_C  | DRV_SLOW_C | RESERVED_C | AF1_C),  //GPIO_14  - KP_MKIN[7]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_15  - KP_MKOUT[7]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_16  - KP_DKIN[0]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_17  - KP_DKIN[1]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_18  - KP_DKIN[2]
         (DRV_SLOW_C | RESERVED_C | AF1_C)             ,//GPIO_19  - KP_DKIN[3]
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_20  - SSP_SYSCLK - for audio codec (I2S mode)
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_21  - SSP_BITCLK
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_22  - SSP_SYNC
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_23  - SSP_DATA_OUT
         (DRV_MED_C  | RESERVED_C | AF1_C)             ,//GPIO_24  - SSP_SDATA_IN

		 
         (PULL_DN_C | DRV_MED_C  | RESERVED_C | AF0_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_25  - 
         (PULL_DN_C | DRV_MED_C  | RESERVED_C | AF0_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_26  - 
         (PULL_DN_C | DRV_MED_C  | RESERVED_C | AF0_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_27  - 
         (PULL_DN_C | DRV_MED_C  | RESERVED_C | AF0_C)     ,//   ;pinmux_a     0x00C0  ; GPIO_28  - 
         
         0x00C0 ,  //GPIO_29  -                          
         0x00C0 ,  //GPIO_30  -                          
         0x00C0 ,  //GPIO_31  -                          
         0x00C0 ,  //GPIO_32  -                          
         0x00C0 ,  //GPIO_33  -                          
         0x00C0 ,  //GPIO_34  -                          
         (DRV_MED_C  | RESERVED_C | AF0_C) ,  //GPIO_35  -      //for GPIO                 
         (DRV_MED_C  | RESERVED_C | AF0_C) ,   //GPIO_36  -    //for GPIO
         0x00C0 , //GPIO_37  - 
         0x00C0 , //GPIO_38  - 
         0x00C0 , //GPIO_39  - 
         0x00C0 , //GPIO_40  - 
         0x00C0 , //GPIO_41  - 
         0x00C0 , //GPIO_42  - 
         0x00C0 , //(PULL_UP_C  | DRV_MED_C | RESERVED_C | AF7_C) ,  //GPIO_43  - CP_UART_RXD 
         0x00C0 , //(DRV_MED_C | RESERVED_C | AF7_C)              ,//GPIO_44  - CP_UART_TXD
         0x00C0, // GPIO_45  -
         0x00C0, // GPIO_46  - 
         0x00C0 , //(PULL_UP_C  | DRV_MED_C | RESERVED_C | AF6_C) , // GPIO_47  - UART1_RXD - for debug UART
         0x00C0 , //(PULL_UP_C  | DRV_MED_C | RESERVED_C | AF6_C) , // GPIO_48  - UART1_TXD
         (DRV_MED_C  | RESERVED_C | AF0_C) ,// GPIO_49  -           //for GPIO
         (DRV_MED_C  | RESERVED_C | AF0_C) ,// GPIO_50  -           //for GPIO
         0xd0C1 ,// GPIO_51  - 
         0xd0C1 ,// GPIO_52  - 
        (DRV_SLOW_C | RESERVED_C | AF2_C)   , // GPIO_53  - I2C_SCL - for I2C bus
        (DRV_SLOW_C | RESERVED_C | AF2_C)   , // GPIO_54  - I2C_SDA
        0x00C0, // GPIO_55  -  0x2F0
        0x00C0, // GPIO_56  -  0x2F4
        0x00C0, // GPIO_57  -  0x2F8
        0x00C0, // GPIO_58  -  0x2FC
        0x00C0, // GPIO_59  -  0x300 
        (PULL_UP_C | RESERVED_C | AF0_C), //td_y1 //  0x304     pinmux_b   (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,//0x00C0  ; GPIO_60  - 
 
        //pull up or pull down?
        0x1845 ,//0X1845, 0x00C0  ; GPIO_61  - 
        0x1845, //0X1845,   0x30c      pinmux_b    (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,//0x00C0  ; GPIO_62  - 
        0x1845 ,//0X1845,  ; GPIO_63  - 
        0x1845 ,//0X1845,   ; GPIO_64  - 
        0x1845, //0X1845,       pinmux_b  (PULL_DN_C | DRV_MED_C | RESERVED_C | AF1_C) ,//0x00C0  ; GPIO_65  -
        0x1845 ,//0X1845,   ; GPIO_66  - 
        //td_y1 end

        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_67  - CCIC_IN[7] - for camera interface
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_68  - CCIC_IN[6]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_69  - CCIC_IN[5]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_70  - CCIC_IN[4]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_71  - CCIC_IN[3]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_72  - CCIC_IN[2]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_73  - CCIC_IN[1]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_74  - CCIC_IN[0]
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_75  - CAM_HSYNC
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_76  - CAM_VSYNC
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_77  - CAM_MCLK
        (DRV_FAST_C | RESERVED_C | AF1_C)    ,//GPIO_78  - CAM_PCLK
        0xC0C0,  //GPIO_79  - 
        0x00C0,  //GPIO_80  - 
        0x00C0,  //GPIO_81  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_81  - LCD FCLK - for primary LCD
        0x00C0,  //GPIO_82  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_82  - LDC LCLK
        0x00C0,  //GPIO_83  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_83  - LCD PCLK
        0x00C0,  //GPIO_84  - //(DRV_FAST_C | RESERVED_C | AF1_C)     ; GPIO_84  - LCD DENA
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_85  - LCD DD[0]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_86  - LCD DD[1]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_87  - LCD DD[2]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_88  - LCD DD[3]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_89  - LCD DD[4]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_90  - LCD DD[5]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_91  - LCD DD[6]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_92  - LCD DD[7]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_93  - LCD DD[8]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_94  - LCD DD[9]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_95  - LCD DD[10]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_96  - LCD DD[11]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_97  - LCD DD[12]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_98  - LCD DD[13]
        0x00C0 , // GPIO_99  -            //
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_100 - LCD DD[14]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_101 - LCD DD[15]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_102 - LCD DD[16]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_103 - LCD DD[17]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_104 - LCD DD[18]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_105 - LCD DD[19]
        (DRV_FAST_C | RESERVED_C | AF1_C)  ,   //GPIO_106 - LCD DD[20]
        (DRV_FAST_C | RESERVED_C | AF1_C)   ,   //GPIO_107 - LCD DD[21]
        (DRV_FAST_C | RESERVED_C | AF1_C)   ,   //GPIO_108 - LCD DD[22]
        (DRV_FAST_C | RESERVED_C | AF1_C)   ,   //GPIO_109 - LCD DD[23]
        (PULL_DN_C  | RESERVED_C | AF4_C) , //td_y1 0x00C0  GPIO_110 -   ;pinmux_a
        (PULL_DN_C  | RESERVED_C | AF4_C) , //td_y1 0x00C0  GPIO_111 - 
        (RESERVED_C | AF4_C),  //td_y1 gwl_y0 func?  (DRV_MED_C | RESERVED_C | AF1_C) , // 0x00C0  GPIO_112 -
        (PULL_UP_C  | RESERVED_C | AF0_C) , //0x00C0  GPIO_113 - 
        (RESERVED_C | AF1_C) , //0x00C0  GPIO_114 -  ;pinmux_a
        (RESERVED_C | AF1_C) , //0x00C0  GPIO_115 -  ;pinmux_a
        (RESERVED_C | AF1_C) , //0x00C0  GPIO_116 -  ;pinmux_a
        0x00C0  ,///GPIO_117 - 
        0x00C0  ,///GPIO_118 - 
        0x00C0  ,///GPIO_119 - 
        0x00C0  ,///GPIO_120 - 
        0x00C0  ,///GPIO_121 - 
        (PULL_DN_C | DRV_MED_C | RESERVED_C | AF0_C) ,// ; (PULL_UP_C | DRV_MED_C | RESERVED_C | AF1_C) ; 0x00C0  ; GPIO_122 - 
        0x00C0,  // GPIO_123 - 
        (DRV_FAST_C | RESERVED_C | AF1_C) , // GPIO_124 - //for MN_CLK_OUT -- audio.
        0x00C0 ,  //GPIO_125 - 
        0x00C0 , //GPIO_126 - 
        0x00C0 , //GPIO_127 - 
        //pinmux_a
		  0xA0C0 , //0x260
		  0xA0C0 , //0x264
 		  0x00C0 , //0x268
		  0x00C0 , //0x26C
		  0x00C0 , //0x270
		  0x00C0 , //0x274
		  0xA0C0 , //0x278
		  0xA0C0 , //0x27C
		  0xA0C0 , //0x280
		  0xA0C0 , //0x284
		  0xA0C0 , //0x288
		  0xA0C0 , //0x28C
		  0xA0C0 , //0x290
		  0xA0C0 , //0x294
		         
		  0xA0C0 , // 0xd401E2B4
		  0xA0C0 , // 0xd401E2B8											
		  0xA0C0 , // 0xd401E2BC											
		  0xA0C0 , // 0xd401E2C0											
		  0xA0C0 , // 0xd401E2C4											
		  0xA0C0 , // 0xd401E2C8											
		  0xA0C0 , // 0xd401E2CC											
		  0xA0C0 , // 0xd401E2D0											
		  0xA0C0 , // 0xd401E2D4											
		  0xA0C0 , // 0xd401E2D8											
		  0xA0C0 , // 0xd401E2DC											
		  0x00C0 , // 0xd401E2E0											
		  0x00C0 , // 0xd401E2E4											
		  0x00C0 , // 0xd401E2E8											
		  0x00C0 , // 0xd401E2EC											
};  


#define INTEL_EVT
const unsigned long MFPR_data_Intel_EVT[] ={  
		 (DRV_SLOW_C | RESERVED_C | AF1_C),   			//0x48   NDRDY1> GPIO86
         (DRV_SLOW_C | RESERVED_C | AF1_C),             //0x4c   sm_ncs0> GPIO87 
         (DRV_SLOW_C | RESERVED_C | AF1_C),             // 0x50	SM_NCS1> GPIO88
         (DRV_SLOW_C | RESERVED_C | AF1_C),  			// 0x78   NDRDY1> GPIO1       
         (0x9000 |DRV_MED_C  | RESERVED_C | AF1_C),		//0x140  GPIO_25 I2S CLK  - 
         (0x9000 |DRV_MED_C  | RESERVED_C | AF1_C),		//0x144  GPIO_26 I2S Frame - 
         (0x9000 |DRV_MED_C  | RESERVED_C | AF1_C),		//0x148  GPIO_27 I2S TX 
         (0x9000 |DRV_MED_C  | RESERVED_C | AF1_C),		//0x14C  GPIO_28 i2S RX - 
         #ifdef INTEL_EVT                      
         (DRV_MED_C | RESERVED_C | AF2_C),				// 0x160 GPIO_33 -ssp0_clk
         #else
		 0x00C0 , 										// 0x160 GPIO_33 -ssp0_clk
		 #endif
         #ifdef INTEL_EVT
		 (DRV_MED_C | RESERVED_C | AF2_C),    			//0x168 GPIO_35 -ssp0_rxd
		 (DRV_MED_C | RESERVED_C | AF2_C),	  			//0x16cGPIO_36 ssp0_txd
		 #else
         (DRV_MED_C  | RESERVED_C | AF0_C),   			//0x168 GPIO_35  -                     
         (DRV_MED_C  | RESERVED_C | AF0_C),   			//0x16c GPIO_36  -    
         #endif 
         #ifdef INTEL_EVT
         (DRV_SLOW_C | RESERVED_C | AF2_C),  			//0x1A0 GPIO_49  - CI2C_SCL - for I2C bus
         (DRV_SLOW_C | RESERVED_C | AF2_C), 			//0x1A4GPIO_50  - CI2C_SDA
         #else
		 (DRV_MED_C  | RESERVED_C | AF0_C),				// 0x1A0 GPIO_49  -           
         (DRV_MED_C  | RESERVED_C | AF0_C),				// 0x1A4 GPIO_50  -          
		 #endif
         0xd0C1,										//0X1A8 GPIO_51  - 
         0xd0C1,										//0X1AC GPIO_52  
         #ifdef INTEL_EVT
		 (DRV_MED_C | RESERVED_C | AF1_C), 				//0x1B0 GPIO_53  - UART1_CTS
         (DRV_MED_C | RESERVED_C | AF1_C), 				//0x1B4 GPIO_54  - UART1_RTS
		 #else
        (DRV_SLOW_C | RESERVED_C | AF2_C), 				//0x1B0 GPIO_53  - I2C_SCL - for I2C bus
        (DRV_SLOW_C | RESERVED_C | AF2_C), 				//0x1B4 GPIO_54  - I2C_SDA
         #endif
         0x00C0, // GPIO_56  -  0x2F4
        (RESERVED_C | AF4_C),  // 0X2A0 GPIO_112 -
        (PULL_UP_C  | RESERVED_C | AF0_C) , //0x2A4  GPIO_113 - 
        (RESERVED_C | AF1_C) , //0x2A8  GPIO_114 - RF_SPI1_D 
        (RESERVED_C | AF1_C) , //0x2AC  GPIO_115 - RF_SPI1_CLK 
        (RESERVED_C | AF1_C) , //0x2B0  GPIO_116 - RF_SPI1_STRB0
        (PULL_DN_C | DRV_MED_C | RESERVED_C | AF0_C) ,//0x0c8 GPIO_122 -slaveresetout
        //pinmux_a
		  0xA0C0 , //0x260
		  0xA0C0 , //0x264
 		  0x00C0 , //0x268
		  0x00C0 , //0x26C
		  0x00C0 , //0x270
		  0x00C0 , //0x274
		  0xA0C0 , //0x278
		  0xA0C0 , //0x27C
		  0xA0C0 , //0x280
		  0xA0C0 , //0x284
		  0xA0C0 , //0x288
		  0xA0C0 , //0x28C
		  0xA0C0 , //0x290
		  0xA0C0 , //0x294
		  (PULL_UP_C |RESERVED_C|AF0_C) , //0x29C   GPIO111
		  0xA0C0 , // 0xd401E2B4
		  0xA0C0 , // 0xd401E2B8											
		  0xA0C0 , // 0xd401E2BC											
		  0xA0C0 , // 0xd401E2C0											
		  0xA0C0 , // 0xd401E2C4											
		  0xA0C0 , // 0xd401E2C8											
		  0xA0C0 , // 0xd401E2CC											
		  0xA0C0 , // 0xd401E2D0											
		  0xA0C0 , // 0xd401E2D4											
		  0xA0C0 , // 0xd401E2D8											
		  0xA0C0 , // 0xd401E2DC											
		  0x00C0 , // 0xd401E2E0											
		  0x00C0 , // 0xd401E2E4											
		  0x00C0 , // 0xd401E2E8											
		  0x00C0 , // 0xd401E2EC
		  (DRV_SLOW_C | RESERVED_C | AF0_C) , // 0xd401E304	GP1O60
		  (DRV_SLOW_C | RESERVED_C | AF0_C) , // 0xd401E298	GP1O110 
};                                             

const unsigned long MFPR_offset_nezha2[] ={                                               
        0x140,
        0x144,
        0x148,
        0x14C,
//        0x160,
//        0x164,
//        0x168,
//        0x16C,
//        0x1A0,
//        0x1A4,
//        0x1A8,
//        0x1AC,
        0x1B0,
        0x1B4,
//        0x2F4,
//        0x2A0,
//        0x2A8,
//        0x2AC,
//        0x2B0,
////        0x0CC,
//        0x0D0,
        0x260,
        0x264,
        0x268,
//        0x26C,
//        0x270,
//        0x274,
//        0x278,
//        0x27C,
//        0x280,
//        0x284,
//        0x288,
//        0x28C,
//        0x294,
//        0x2B4,
//        0x2B8,
//        0x2BC,
//        0x2C0,
//        0x2C4,
//        0x2C8,
//        0x2CC,
//        0x2D0,
//        0x2D4,
//        0x2D8,
#if 0 //Z3
        0x2DC,
        0x2E0,
        0x2E4,
        0x2E8,
        0x2EC,
#endif        
        0x304,
		0x000 // 0x000 marks the end of the table
};     

const unsigned long MFPR_data_nezha2[] ={                                                                  
        (DRV_MED_C	| RESERVED_C | AF0_C), // GPIO25
        (DRV_MED_C	| RESERVED_C | AF0_C),
        (DRV_MED_C	| RESERVED_C | AF0_C),
        (DRV_MED_C	| RESERVED_C | AF0_C),
//        (DRV_MED_C	| RESERVED_C | AF0_C), 
//        (DRV_MED_C	| RESERVED_C | AF0_C),
//        (DRV_MED_C	| RESERVED_C | AF0_C),
//        (DRV_MED_C	| RESERVED_C | AF0_C),
//        (DRV_MED_C  | RESERVED_C | AF0_C), // GPIO49
//        (DRV_MED_C  | RESERVED_C | AF0_C), // GPIO50
//        0xd0c1, // (DRV_MED_C  | RESERVED_C | AF0_C)}, // GPIO51
//        0xd0c1, // (DRV_MED_C  | RESERVED_C | AF0_C)}, // GPIO52
        (DRV_SLOW_C  | RESERVED_C | AF2_C), // GPIO53
        (DRV_SLOW_C  | RESERVED_C | AF2_C), // GPIO54
//        0x00C0, // GPIO56
//        (RESERVED_C | AF4_C), // GPIO112
//        (RESERVED_C | AF1_C),
//        (RESERVED_C | AF1_C),
//        (RESERVED_C | AF1_C),
////        (DRV_MED_C | RESERVED_C | AF1_C),
//        (DRV_MED_C | RESERVED_C | AF0_C),
        0xA0C0,
        0xA0C0,
        0x00C0,
//        0x00C0,
//        0x00C0,
//        0x00C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
//        0xA0C0,
#if 0 //Z3
        0xA0C1, //GPIO77->SEC_DIGRF_EN
        0xA0C1, //GPIO78->RF_DCDC_EN
        0xA0C1, //GPIO79->SEC_SYS_CLK_EN
        0xA0C1, //GPIO80->SEC_RESET_B
        0xA0C1, //GPIO81->OCLK2_EN
#endif        
        0xA0C0, //GPIO60->DigRF_EN	
};

#if defined(QUECTEL_PROJECT_EC100Y)
//fitz.xu 20191114: add pin mux for 3601 EC100Y-CN
const unsigned long quec_MFPR_offset[] =
{
/*  GPIO_0  GPIO_1  GPIO_2  GPIO_3  GPIO_4  GPIO_5  GPIO_6  GPIO_7*/
    0x0DC,  0x0E0,  0x0E4,  0x0E8,  0x0EC,  0x0F0,  0x0F4,  0x0F8,   //MFPRs   0->7
    0x000,                                                           // 0x000 marks the end of the table
    
};

const unsigned long quec_MFPR_data[] =
{
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_0
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_1
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_2
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_3
    (PULL_UP_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_4   PM_ENABLE
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_5   WLAN_EN
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF3_C),  //GPIO_6,  NET_STATUS
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_7,  STATUS, do not pull high before start up
};
#elif defined(QUECTEL_PROJECT_EC200S)
//fitz.xu 20191213: add pin mux for 1601 EC200S 
const unsigned long quec_MFPR_offset[] =
{
/*  GPIO_0  GPIO_1  GPIO_2  GPIO_3  GPIO_4  GPIO_5  GPIO_6  GPIO_7*/
    0x0DC,  0x0E0,  0x0E4,  0x0E8,  0x0EC,  0x0F0,  0x0F4,  0x0F8,   //MFPRs   0->7

/*  GPIO_8 */
    0x0FC,
    0x000,                                                           // 0x000 marks the end of the table
    
};

const unsigned long quec_MFPR_data[] =
{
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_0
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_1
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_2, net mode
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_3, air plan ctrl
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_4, power status
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_5, sleep_ind
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF3_C),  //GPIO_6, net status
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_7, wake up in
    (PULL_DN_C | DRV_SLOW_C | RESERVED_C | AF0_C),  //GPIO_8, ap_ready
};
#endif

BOARD_TYPE  EEPROMGetBoardVersion ( void );                              
//void  EEPROMWriteBoardVersion ( BOARD_TYPE    *board_type , EEPROMWriteCallback   	callBackFun );
void  EEPROMWriteBoardVersionBlocking ( BOARD_TYPE    *board_type );


/***************************************************************************/
/***************************************************************************/
#endif /* _BOARD_CONFIG__H_ */
