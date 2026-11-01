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
/* Title: I2C package configuration file                                */
/*                                                                      */
/* Filename:  I2C_config.h                                              */
/*                                                                      */
/* Authors: Adi Dayan                                                   */
/*                                                                      */
/* Target, subsystem: Common Platform, HAL                              */
/************************************************************************/

#ifndef _I2C_CONFIG_H_
#define _I2C_CONFIG_H_



// All but Hermon
#if !defined(_HERMON_B0_SILICON_) || defined(_TAVOR_BOERNE_)

//#define I2C_RUN_FAST_MODE					1  /* the value is set by platfrom.nvm*/
//#define I2C_RUN_REPEAT_START_MODE			1  /* the value is set by platfrom.nvm*/

#endif


#if defined(_HERMON_B0_SILICON_) && !defined (INTEL_2CHIP_PLAT_BVD)

#define I2C_CHANGE_PIN_MUX			1

#endif


/***************** Macros ***********************/

#define I2C_ERROR_INFO
#define _TAVOR_B0_EARLY_BUS_BUSY_NEW_BIT_		1
#define STOP_MISSING_WORKAROUND					1



//#if defined(_TAVOR_HARBELL_) || defined(SILICON_PV2)
#if defined(SILICON_PV2)
	#define I2C_DELAY(td)   (timerDelayLite(td))
 #else
	#define I2C_DELAY(td)   (timerDelay(td))
 #endif



/* MASTERS_COLLISION_SILICON_BUG_WORKAROUND*/
/* In Hermon 2 chip there was a silicon I2c issue which cause the I2c bus to get stuck
 * The define bellow is a SW W/A for that.
 * For Tavor this should be modify becuase CP14 is not exist on Habell - !!! does not work for Harbell !!!:
 * CP14 - time stamp taken should be replace by time stamp from other free-running timer
 *         resolution should be in 1usec or less, TIME_TO_SAMPLE & CONVERT_TO_MICRO_SEC should be modify.*/

//#if defined(INTEL_2CHIP_PLAT) || defined(_TAVOR_HARBELL_) || defined(_TAVOR_BOERNE_) || defined(SILICON_TTC) || defined(SILICON_PV2)
#if defined(INTEL_2CHIP_PLAT) || defined(_TAVOR_BOERNE_) || defined(SILICON_TTC) || defined(SILICON_PV2)
   #if !defined(_TAVOR_B0_EARLY_BUS_BUSY_NEW_BIT_)
       #define MASTERS_COLLISION_SILICON_BUG_WORKAROUND /* Hermon2chip,Bvd, Boerne*/
   #endif
#else
	//No need for single chip platfrom , this is only for existing of 2 MASTERS on the I2C bus
#endif

/********************* HW Parameters ********************/
//#define I2C_REGISTER_BASE_ADDRESS		0xD4037000//0xD4011000 
#define I2C_INT_SRC 					INTC_HW_I2C //INTC_SRC_I2C_CP

#if 0 
#ifdef PHS_SW_DEMO_TTC
#if 0//pinmux_b
#ifdef PMIC_LEVANTE
//gwl add for levante
#define I2C_REGISTER_BASE_ADDRESS   	0xD4011000
#define I2C_INT_SRC        				INTC_SRC_I2C_AP
#else
#define I2C_REGISTER_BASE_ADDRESS		0xD4037000
#define I2C_INT_SRC 					INTC_HW_I2C //INTC_SRC_I2C_CP
#endif
#endif
#define I2C_REGISTER_BASE_ADDRESS   	0xD4037000 //(((PMC_TYPE_IS_MICCO)||(CUSTOMER_IS_HUAWEI))?0xD4037000 : 0xD4011000)
#define I2C_INT_SRC        				INTC_HW_I2C //(((PMC_TYPE_IS_MICCO)||(CUSTOMER_IS_HUAWEI))?INTC_HW_I2C : INTC_SRC_I2C_AP)
#else
#if defined(_TAVOR_HARBELL_) || defined(SILICON_PV2)

	#define I2C_INT_SRC     			INTC_HW_I2C

	#define I2C_REGISTER_BASE_ADDRESS   0xF0000000
#elif defined(SILICON_TTC)

	#if defined(FLAVOR_APP) && defined(FLAVOR_DUALCORE)
     	// AP I2C connected to CI2C_SDA/SCL (muxed)
     	#define I2C_REGISTER_BASE_ADDRESS   	0xD4011000
     	#define I2C_INT_SRC        				INTC_SRC_I2C_AP
   #else
     	// PWR I2C connected to PWR_SDA/SCL (dedicated)
     	#define I2C_REGISTER_BASE_ADDRESS   	0xD4037000
     	#define I2C_INT_SRC        				INTC_SRC_I2C_CP
   #endif

#elif !defined (INTEL_2CHIP_PLAT_BVD) || defined(_TAVOR_BOERNE_)

    #define I2C_REGISTER_BASE_ADDRESS   0x40301680
    #define I2C_INT_SRC     			INTC_SRC_I2C

#else//INTEL_2CHIP_PLAT_BVD
    //currently Power I2c is instead of the standard I2c in BVD

    #define I2C_REGISTER_BASE_ADDRESS   0x40f00180
    #define I2C_INT_SRC      			INTC_SRC_POWER_I2C

#endif// silicon type
#endif
#endif //#if 0
/*
 * I2C package user IDs (compile-time allocation)
 * Product specific
 */
#if !defined(_HERMON_B0_SILICON_) || defined(_TAVOR_BOERNE_)
typedef enum
{
    I2C_CAMERA_ID = 0,
	I2C_PMC_ID,
    I2C_TRACII_ID,
    I2C_CEDAR_CODEC_ID,
	I2C_EEPROM_ID,
	I2C_MICCO_ID,
	I2C_PMC_TEMP_VBAT_ID,
	I2C_PMC_TEMP_ID,
	I2C_PMC_VBAT_ID,
	I2C_MAX_NUM_OF_IDS
}I2C_UserId;
#else
typedef enum
{
    I2C_CAMERA_ID,
    I2C_PMC_ID,
	I2C_CEDAR_CODEC_ID,
	I2C_EEPROM_ID,
	I2C_BSP_ID,
	I2C_PMC_TEMP_ID,
	I2C_PMC_VBAT_ID,
    I2C_MAX_NUM_OF_IDS
}I2C_UserId;
#endif//_TAVOR_BOERNE_ || defined(_TAVOR_HARBELL_)
/*
 * I2C slave addresses
 * ASIC specific
 */
#if !defined(_HERMON_B0_SILICON_) || defined(_TAVOR_BOERNE_)
		//MICCO_A0 PMC_I2C_WRITE_SLAVE_ADDRESS            0x34
		//MICCO_A0 PMC_I2C_READ_SLAVE_ADDRESS             0x35
#if 0 //pinmux_b		
#ifdef PMIC_LEVANTE  //gwl add for levante
        #define PMC_I2C_WRITE_SLAVE_ADDRESS            ((PMC_TYPE_IS_LEVANTE_B0)?0x68:0x60) //0x60  //for levante a1
		#define PMC_I2C_READ_SLAVE_ADDRESS             ((PMC_TYPE_IS_LEVANTE_B0)?0x69:0x61) //  0x61

        #define PMC_PORTOFINO_I2C_WRITE_SLAVE_ADDRESS	  0x22	  // Levante - Portofino
        #define PMC_PORTOFINO_I2C_READ_SLAVE_ADDRESS	  0x23
#else		
		#define PMC_I2C_WRITE_SLAVE_ADDRESS               0x68
		#define PMC_I2C_READ_SLAVE_ADDRESS                0x69
		#define PMC_PORTOFINO_I2C_WRITE_SLAVE_ADDRESS	  0x22	  // Levante - Portofino
        #define PMC_PORTOFINO_I2C_READ_SLAVE_ADDRESS	  0x23
#endif
#endif
		#define AUDIO_I2C_WRITE_SLAVE_ADDRESS	 0x60	 // 88CE156 audio chip
	    #define AUDIO_I2C_READ_SLAVE_ADDRESS 	 0x61
		//for intel acturally usful
 //       #define PMC_I2C_WRITE_SLAVE_ADDRESS      0x68//0x32    //  ((PMC_TYPE_IS_LEVANTE_B0||PMC_TYPE_IS_MICCO)?0x68:0x60) //0x60  //for levante a1
//		#define PMC_I2C_READ_SLAVE_ADDRESS       0x69//0x33    //  ((PMC_TYPE_IS_LEVANTE_B0||PMC_TYPE_IS_MICCO)?0x69:0x61) //  0x61
		#define AUDIO_PM805_I2C_WRITE_SLAVE_ADDRESS	 0x70	 // 88CE156 audio chip
	    #define AUDIO_PM805_I2C_READ_SLAVE_ADDRESS 	 0x71
        #define PMC_PORTOFINO_I2C_WRITE_SLAVE_ADDRESS	  0x22	  // Levante - Portofino
        #define PMC_PORTOFINO_I2C_READ_SLAVE_ADDRESS	  0x23

		#define I2C_OWN_SLAVE_ADDRESS                     0xFF        /* response */

		/*temp - shold be remove after audioMICCO.c will use PMC_I2C_WRITE_SLAVE_ADDRESS & PMC_I2C_READ_SLAVE_ADDRESS */
		#define MICCO_I2C_WRITE_SLAVE_ADDRESS   PMC_I2C_WRITE_SLAVE_ADDRESS
		#define MICCO_I2C_READ_SLAVE_ADDRESS    PMC_I2C_READ_SLAVE_ADDRESS

#else
#define CAMERA_OV9640_I2C_WRITE_SLAVE_ADDRESS       0x60        /* For B0 */
#define CAMERA_OV9640_I2C_READ_SLAVE_ADDRESS        0x61        /* For B0 */

#define CAMERA_OV9650_I2C_WRITE_SLAVE_ADDRESS       0x60        /* For B0 and Mathis */
#define CAMERA_OV9650_I2C_READ_SLAVE_ADDRESS        0x61        /* For B0 and Mathis */

#define CAMERA_OV7660_I2C_WRITE_SLAVE_ADDRESS       0x42        /* For Mathis */
#define CAMERA_OV7660_I2C_READ_SLAVE_ADDRESS        0x43        /* For Mathis */

#define CAMERA_OV6650_I2C_WRITE_SLAVE_ADDRESS       0xC0        /* For B0 */
#define CAMERA_OV6650_I2C_READ_SLAVE_ADDRESS        0xC1        /* For B0 */

#if 0
#ifdef PMIC_LEVANTE  //gwl add for levante
		#define PMC_I2C_WRITE_SLAVE_ADDRESS 		   ((PMC_TYPE_IS_LEVANTE_B0)?0x68:0x60) //0x60	//for levante a1
		#define PMC_I2C_READ_SLAVE_ADDRESS			   ((PMC_TYPE_IS_LEVANTE_B0)?0x69:0x61) //	0x61
		#define PMC_PORTOFINO_I2C_WRITE_SLAVE_ADDRESS	  0x22	  // Levante - Portofino
        #define PMC_PORTOFINO_I2C_READ_SLAVE_ADDRESS	  0x23

#else		
        #define PMC_I2C_WRITE_SLAVE_ADDRESS 			  0x68
        #define PMC_I2C_READ_SLAVE_ADDRESS				  0x69
		#define PMC_PORTOFINO_I2C_WRITE_SLAVE_ADDRESS	  0x22	  // Levante - Portofino
        #define PMC_PORTOFINO_I2C_READ_SLAVE_ADDRESS	  0x23
#endif
#endif
//pinmux_b
        #define AUDIO_I2C_WRITE_SLAVE_ADDRESS	 0x60	 // 88CE156 audio chip
	    #define AUDIO_I2C_READ_SLAVE_ADDRESS 	 0x61

		#define AUDIO_PM805_I2C_WRITE_SLAVE_ADDRESS	 0x70	 // 88CE156 audio chip
	    #define AUDIO_PM805_I2C_READ_SLAVE_ADDRESS 	 0x71

        #define PMC_I2C_WRITE_SLAVE_ADDRESS      0x32    //  ((PMC_TYPE_IS_LEVANTE_B0||PMC_TYPE_IS_MICCO)?0x68:0x60) //0x60  //for levante a1
		#define PMC_I2C_READ_SLAVE_ADDRESS       0x33    //  ((PMC_TYPE_IS_LEVANTE_B0||PMC_TYPE_IS_MICCO)?0x69:0x61) //  0x61
		
		#define PMC_PORTOFINO_I2C_WRITE_SLAVE_ADDRESS	  0x22	  // Levante - Portofino
        #define PMC_PORTOFINO_I2C_READ_SLAVE_ADDRESS	  0x23




#define CAMERA_I2C_WRITE_SLAVE_ADDRESS              0xa4        /* For A0 */
#define CAMERA_I2C_READ_SLAVE_ADDRESS               0xa5        /* For A0 */

#define I2C_OWN_SLAVE_ADDRESS                       0x93        /* response */
#endif //_TAVOR_BOERNE_  || defined( _TAVOR_HARBELL_)

#define CEDAR_CODEC_I2C_WRITE_SLAVE_ADDRESS         0x36
#define CEDAR_CODEC_I2C_READ_SLAVE_ADDRESS          0x37

#define EEPROM_I2C_WRITE_SLAVE_ADDRESS              0xa0
#define EEPROM_I2C_READ_SLAVE_ADDRESS				0xa1


/* USER define */
/* this define the number of users registrations for call back*/
#define I2C_MAX_NUM_OF_REGISTERS    10
/* this define the size of data that can be sent to the I2C */
#define I2C_TX_MSG_DATA_SIZE            0xa
/* this define the number of element in the I2c task Q*/
#define I2C_MAX_NUM_OF_ELEMENTS         0x14
/* this define the I2c timeout for ack - recomened not to change*/
#define LOOP_COUNTER_LIMIT              4000L

//#if defined(_TAVOR_HARBELL_) || defined(SILICON_PV2)
#if defined(SILICON_PV2)
	#define CONVERT_TO_MICRO_SEC	         	14  //clocks/uSec;  <= 208/16=13MHz frequency
#elif defined(_TAVOR_BOERNE_)
    // For Freq=624MHz 1_Sec=(624000000/64) = 9750000 => 5uSec = 9.75*5 = 49 clocks
	#define CONVERT_TO_MICRO_SEC	         	10
#elif defined(SILICON_TTC)
    // For Freq=624MHz 1_Sec=(624000000) = 624000000 => 5uSec = 624*5 = 3120 clocks
	#define CONVERT_TO_MICRO_SEC	         	624
#else
	#define CONVERT_TO_MICRO_SEC				 5
#endif


#endif

