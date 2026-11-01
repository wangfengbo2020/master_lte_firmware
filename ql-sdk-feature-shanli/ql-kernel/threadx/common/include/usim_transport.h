/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/******************************************************************************
*               MODULE HEADER FILE
*******************************************************************************
*  COPYRIGHT (C) 2005 Intel Corporation, All rights reserved..
*
*  This file and the software in it is furnished under
*  license and may only be used or copied in accordance with the terms of the
*  license. The information in this file is furnished for informational use
*  only, is subject to change without notice, and should not be construed as
*  a commitment by Intel Corporation. Intel Corporation assumes no
*  responsibility or liability for any errors or inaccuracies that may appear
*  in this document or any software that may be provided in association with
*  this document.
*  Except as permitted by such license, no part of this document may be
*  reproduced, stored in a retrieval system, or transmitted in any form or by
*  any means without the express written consent of Intel Corporation.
*
* Title: USIM transport header file
*
* Filename: usim_transport.h
*
* Author: Eilam Ben-Dror
*
* Description: This is the header file for the USIM transport layer.
*
* Last Updated: 14-Dec-2005
*
******************************************************************************/

#ifndef _USIM_TRANSPORT_H_
#define _USIM_TRANSPORT_H_

#include "usim_hw.h"
#include "usim_dl.h"
#include "usim_db.h"

/*----------- Global defines ------------------------------------------------*/

/*----------- Global macro definitions --------------------------------------*/

/*----------- Global type definitions ---------------------------------------*/



/*----------- Extern definition ---------------------------------------------*/

/*----------- Global variable declarations ----------------------------------*/


/*----------- Global constant definitions -----------------------------------*/

/*---------- Global function prototypes -------------------------------------*/

USIM_ReturnCode USIMTransportT0CommandSend	(USIM_Card card);
USIM_ReturnCode USIMTransportT1CommandSend	(USIM_Card card);
void 			USIMResponseNotify			(USIM_Card card,
											USIM_ResponseHeader * header,
                                        	UINT16 dataLength,
											UINT8 * data);


#endif /* _USIM_TRANSPORT_H_ */
