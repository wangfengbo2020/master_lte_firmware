/*--------------------------------------------------------------------------------------------------------------------
(C) Copyright 2006, 2007 Marvell DSPC Ltd. All Rights Reserved.
-------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
*  INTEL CONFIDENTIAL
*  Copyright 2006 Intel Corporation All Rights Reserved.
*  The source code contained or described herein and all documents related to the source code (?Material? are owned
*  by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
*  its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
*  Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
*  treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
*  transmitted, distributed, or disclosed in any way without Intel?s prior express written permission.
*
*  No license under any patent, copyright, trade secret or other intellectual property right is granted to or
*  conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
*  estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
*  Intel in writing.
*  -------------------------------------------------------------------------------------------------------------------
*
*  Filename: telconfig.h
*
*  Authors:  Vincent Yeung
*
*  Description: Configurable macro for telephony controller
*
*  History:
*   May 19, 2006 - Creation of file
*
*  Notes:
*
******************************************************************************/



#ifndef TELCONFIG_H
#define TELCONFIG_H

#define ATCMDSRV_VERSION_STR "atcmdsrv v3.0.0"

/******************************************************************************
*   Serial Port Related
******************************************************************************/
#define DEFAULT_EXT_SERIAL_DEVICE         "(null)" //"/dev/ttyS1"
#define BACKEND_ATCMD_CHAN_DEVICE_0     "AT_TASK0"
#define BACKEND_ATCMD_CHAN_DEVICE_1     "AT_TASK1"
#define BACKEND_ATCMD_CHAN_DEVICE_2     "AT_TASK2"
#define BACKEND_ATCMD_CHAN_DEVICE_3     "AT_TASK3"
#define BACKEND_ATCMD_CHAN_DEVICE_4     "AT_TASK4"
#define BACKEND_ATCMD_CHAN_DEVICE_5     "AT_TASK5"
#define BACKEND_ATCMD_CHAN_DEVICE_6     "AT_TASK6"
#define BACKEND_ATCMD_CHAN_DEVICE_7     "AT_TASK7"
#define BACKEND_ATCMD_CHAN_DEVICE_8     "AT_TASK8"
#define BACKEND_ATCMD_CHAN_DEVICE_9     "AT_TASK9"
#define BACKEND_ATCMD_CHAN_DEVICE_10     "AT_TASK10"

#define BACKEND_ATCMD_CHAN_DEVICE_11     "AT_TASK11"
#define BACKEND_ATCMD_CHAN_DEVICE_12     "AT_TASK12"
#define BACKEND_ATCMD_CHAN_DEVICE_13     "AT_TASK13"
#define BACKEND_ATCMD_CHAN_DEVICE_14     "AT_TASK14"
#define BACKEND_ATCMD_CHAN_DEVICE_15     "AT_TASK15"
#define BACKEND_ATCMD_CHAN_DEVICE_16     "AT_TASK16"
#define BACKEND_ATCMD_CHAN_DEVICE_17     "AT_TASK17"
#define BACKEND_ATCMD_CHAN_DEVICE_18     "AT_TASK18"
#define BACKEND_ATCMD_CHAN_DEVICE_19     "AT_TASK19"
#define BACKEND_ATCMD_CHAN_DEVICE_20     "AT_TASK20"



#define BACKEND_TEST_ATCMD_CHAN_DEVICE    "/dev/cctdev8"

#define DATABITS        CS8
#define BAUD            B115200  //B38400
#define STOPBITS        0
#define PARITYON        0
#define PARITY          0

/******************************************************************************
*   Telephony Controller Timer
******************************************************************************/
#define TEL_RINGING_TIMER_PERIOD_IN_SEC 30
#define TEL_RINGING_TIMER_NUM_CYCLES	1

#define TEL_MUTE_OFF	0
#define TEL_MUTE_ON		1

#endif
/* END OF FILE */
