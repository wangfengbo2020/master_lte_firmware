/*--------------------------------------------------------------------------------------------------------------------
(C) Copyright 2006, 2007 Marvell DSPC Ltd. All Rights Reserved.
-------------------------------------------------------------------------------------------------------------------*/

/* ===========================================================================
File        : gbl_types.h
Description : Global types file.

Notes       : This file includes the types from the correct environment.
              The environment is set via the ENV_<ENV> macro. This macro
              is usually set in /env/<host>/build/<env>_env.mak.
              
Copyright 2001, Intel Corporation, All rights reserved.
=========================================================================== */

#if !defined(_AT_GBL_TYPES_H_)
#define _AT_GBL_TYPES_H_

/* Use the POSIX environment types */
#ifndef UNUSEDPARAM
#define UNUSEDPARAM(param) (void)param
#endif
//#include "linux_types.h"

#define _POSIX_TYPES_H_

typedef unsigned char	BOOL;
typedef unsigned char   UINT8;
typedef unsigned short  UINT16;
//typedef unsigned int   UINT32;

//typedef signed char     CHAR;
typedef signed char     INT8;
typedef signed short    INT16;
//typedef signed int     INT32;	//conflict with xscale_types.h
typedef unsigned short  WORD;
//typedef unsigned int    DWORD;
typedef int             HANDLE;
typedef HANDLE*         LPHANDLE;
typedef unsigned char*  PUINT8;
typedef long            LONG;
typedef char*           LPCTSTR;
typedef char*           LPTSTR;
typedef void*           LPVOID;
typedef unsigned int*   LPDWORD;
typedef unsigned int*   PDWORD;
typedef unsigned int*   PUINT32;
//typedef unsigned short  TCHAR;
typedef unsigned int    UINT;
 
//typedef INT32   *PINT32;
//typedef UINT32  *PUINT32;
typedef INT16   *PINT16;
typedef UINT16  *PUINT16;
typedef INT8    *PINT8;
typedef UINT8   *PUINT8;



#ifdef  TRUE
#undef  TRUE
#endif	/* TRUE */
#define TRUE	1

#ifdef  FALSE
#undef  FALSE
#endif	/* FALSE */
#define FALSE	0

#ifndef NULL
#define NULL 0
#endif 

#define TEXT(arg) arg

#endif /* _GBL_TYPES_H_ */

/*                         end of gbl_types.h
--------------------------------------------------------------------------- */



