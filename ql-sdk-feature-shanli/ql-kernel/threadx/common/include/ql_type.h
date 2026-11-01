/*==========================================================================
 |               Quectel OpenCPU --  User API
 |
 |              Copyright (c) 2010 Quectel Ltd.
 |
 |--------------------------------------------------------------------------
 | File Description
 | ----------------
 |      Basic data type definition
 |
 |--------------------------------------------------------------------------
 |
 |  Designed by     :   
 |  Coded    by     :   
 |  Tested   by     :   
 |
 \=========================================================================*/

#ifndef __QL_TYPE_H__
#define __QL_TYPE_H__

#include "gbl_types.h"

#ifndef FALSE
#define FALSE    0
#endif

#ifndef TRUE
#define TRUE     1
#endif

#ifndef NULL
#define NULL    ((void *) 0)
#endif

/****************************************************************************
 * Type Definitions
 ***************************************************************************/
//typedef unsigned char       bool;
typedef          char       ascii;
typedef unsigned char       u8;
typedef signed   char       s8;//char 默认为无符号型
typedef unsigned short      u16;
typedef          short      s16;
typedef unsigned int        u32;
typedef          int        s32;
typedef unsigned long long  u64;
typedef          long long  s64;
typedef unsigned int        ticks;

typedef          int        HANDLE;
typedef unsigned char		uint8_t;

#ifndef uint8
	typedef unsigned char 		uint8;
#endif

#ifndef int8
	typedef signed char 		int8;
#endif

#ifndef uint16
	typedef unsigned short int 	uint16;
#endif

#ifndef int16
	typedef signed short int 	int16;
#endif

#ifndef uint32
	typedef unsigned int 		uint32;
#endif

#ifndef int32
	typedef signed int 			int32;
#endif

#ifndef uint64
	typedef unsigned long long 	uint64;
#endif

#ifndef int64
	typedef signed long long 	int64;
#endif

#ifndef uint_8
	typedef unsigned char 		uint_8;
#endif

#ifndef uint16_t
	typedef unsigned short int 	uint16_t;
#endif

#ifndef VOID
typedef void                VOID;
#endif

#define MOD_QL 0

#endif  
// End-of __QL_TYPE_H__
