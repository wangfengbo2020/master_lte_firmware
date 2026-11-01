/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*****************************************************************************
 *
 * Title: USIM Detection module
 *
 * Filename: usim_detect.h
 *
 * Author: Yan Markman
 *
 * Description: Platform depend USIM presence detection.
 *              The dependency is upon GPIO/CGPIO.
 *              There is no any dependency upon USIM controller.
 *              Provides reliable SIM status change notification.
 *              Makes all required debounces.
 *              When the status is REALLY changed calls for the 
 *
 *****************************************************************************/


