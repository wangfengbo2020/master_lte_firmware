/**
 ******************************************************************************
 * @file    quec_common.h
 * @author  Chavis.Chen
 * @version V1.0.0
 * @date    26-Sep-2018
 * @brief   This file contains the common definitions, macros and functions to
 *          be shared throughout the project.
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2014 QUECTEL Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 */


#ifndef _QUEC_MEMORY_H
#define _QUEC_MEMORY_H

#include "csw_mem.h"
#include "csw_mem_gki.h"
#include "csw_memory.h"
#include "sig_mem.h"
#include "quec_common.h"
#include "quec_debug.h"

extern void * _quec_malloc(size_t size, char * file, int line);
extern void * _quec_calloc(size_t num, size_t size, char * file, int line);
extern void * _quec_realloc(void * mem_ptr, size_t size, char * file, int line);
extern void _quec_free(void * mem_ptr, char * file, int line);

#define quec_malloc(size)			_quec_malloc(size, SHORT_FILE, __LINE__)
#define quec_calloc(num, size)		_quec_calloc(num, size, SHORT_FILE, __LINE__)
#define quec_realloc(mem_ptr, size)	_quec_realloc(mem_ptr, size, SHORT_FILE, __LINE__)
#define quec_free(mem_ptr)			_quec_free(mem_ptr, SHORT_FILE, __LINE__)


extern QuecOSStatus quec_memory_status_query(TelAtParserID atp_index, uint8 query_item);
#endif

#ifdef QUEC_PPP_MAX_MALLOC_CTRL
extern uint32 quec_get_poll_avalibsize(void);
#endif

