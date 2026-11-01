/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*********************************************************************
*                      M O D U L E     B O D Y                       *
**********************************************************************
*                                                                    *
* Title:  Header File for the COMCfg package						 *
*                                                                    *
* Author: Idan Hemdat                                                *
* Target, subsystem: Common Platform, HAL                            *
*                                                                    *
*        *
*                                                                    *
*********************************************************************/

#ifndef _COMCFG_H_
#define _COMCFG_H_

#define COMCFG_MIN_STR_LEN				3

#define COMCFG_INVALID_HANDLE			(-1)


/*These defines are used in the COMCFG_V1 API COMCfgGetParameter() */
//#define COMCFG_V1_MAX_PARAMETERS			30
#define COMCFG_V1_MAX_VALUE_LENGTH	  		25
#define	COMCFG_V1_MAX_PARAMETER_LENGTH   	25
//#define COMCFG_V1_MAX_FILE_LENGTH 			((COMCFG_V1_MAX_PARAMETER_LENGTH + COMCFG_V1_MAX_VALUE_LENGTH + 5) * (COMCFG_V1_MAX_PARAMETERS + 1))

/*-- Type definitions (T type) -----------------------------------------*/

typedef int	COMCFG_HANDLE;

//parameters name and value are handled with these strings types
//For use only with COMCfgGetParameter, please use COMCfgFind--, COMCfgRead-- instead.
typedef char COMCfgName[COMCFG_V1_MAX_PARAMETER_LENGTH+1];
typedef char COMCfgValue[COMCFG_V1_MAX_VALUE_LENGTH+1];

//this enum is used to indicate if the data file is valid or invalid
typedef enum
{
	COMCfg_INVALID = 0,
	COMCfg_VALID
} COMCfg_Type;

/*----------------------------------------------------------------------*/



/*-- Global variables declarations (Public G type) ---------------------*/
/*---Definitions for backward compatability ----------------------------*/

/*-- Public Functions Prototypes ---------------------------------------*/
COMCFG_HANDLE COMCfgFindExact (const char *param);
COMCFG_HANDLE COMCfgFindFirst (const char *prefix);
COMCFG_HANDLE COMCfgFindNext (const char *prefix, COMCFG_HANDLE handle);

const char *COMCfgReadName(COMCFG_HANDLE handle);
const char *COMCfgReadValue(COMCFG_HANDLE handle);
void 			COMCfgPhase1Init(void);
void 			COMCfgPhase2Init(void);

COMCfg_Type 	IsCOMCfgValid (void); //This is obsolete, DO NOT add to new code
BOOL 			COMCfgGetParameter (COMCfgName param, COMCfgValue value); //This is the old method, please use COMCfgFind--, COMCfgRead-- instead.

#ifdef GFS_OVER_RAM
void defaultComcfgCreate (const char *dirName);
#endif
#endif    //_COMCFG_H_
