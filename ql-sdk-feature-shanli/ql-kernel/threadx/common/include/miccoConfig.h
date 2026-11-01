/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/************************************************************************/
/* COPYRIGHT (C) 2002 Intel Corporation.                                */
/*                                                                      */
/* This file and the software in it is furnished under                  */
/* license and may only be used or copied in accordance with the terms  */
/* of the license. The information in this file is furnished for        */
/* informational use only, is subject to change without notice, and     */
/* should not be construed as a commitment by Intel Corporation.        */
/* Intel Corporation assumes no responsibility or liability for any     */
/* errors or inaccuracies that may appear in this document or any       */
/* software that may be provided in association with this document.     */
/* Except as permitted by such license, no part of this document may    */
/* be reproduced, stored in a retrieval system, or transmitted in any   */
/* form or by any means without the express written consent of Intel    */
/* Corporation.                                                         */
/*                                                                      */

/*******************************************************************************
*               MODULE HEADER FILE
********************************************************************************
* Title: miccoConfig Header
*
* Filename: miccoConfig.h
*
* Target, platform: Tavor
*
* Author: Maayan Riklin
*
* Description: Micco configuration header file - This file contains function
 *             headers for the micco registers configuration of:
*              power\RF, audio codec and usim voltage.
*
* Last Updated:
*
* Notes:
*******************************************************************************/


#ifndef _MICCO_CONFIG_H_
#define _MICCO_CONFIG_H_

#include "global_types.h"

/*----------- Global definitions ---------------------------------------------*/
typedef enum {
    MICCO_USIM_1_8V,
    MICCO_USIM_3V
} MiccoUsimV_TYPE;
void configMiccoOnPowerUp(void);
void configMiccoAudio(void);
BOOL miccoConfigUsimV(MiccoUsimV_TYPE voltage);
void miccoEnableUsimV(void);
void miccoDisableUsimV(void);
void miccoPhase2Init(void);


#define MICCO_UPDATE_OK_FLAG 		(0x1)
#define MICCO_UPDATE_ERROR_FLAG     (0x2)


#endif

