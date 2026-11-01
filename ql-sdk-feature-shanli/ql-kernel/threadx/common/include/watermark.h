/**
 ******************************************************************************
 * @file    watermark.h
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


#ifndef _WATERMARK_H
#define _WATERMARK_H


#include "ring_buffer.h"
#include "quec_rtos.h"


typedef struct
{
	ring_buffer_handler_t 	ringBuffer;
	uint32					lowVal;
	uint32					highVal;
	bool					isReachedLow;
	bool					isReachedHigh;
	void					(* cbReachedLow)(void *);
	void					(* cbReachedHigh)(void *);
	void					(* cbWMEmpty)(void *);
	quec_mutex_t			mutex;
} wm_t, * wm_handle_t;


extern QuecOSStatus quec_wm_init(wm_handle_t * wm_handle, uint32 bufSz, uint32 lowVal, uint32 highVal, void (* cbReachedLow)(void *), void (* cbReachedHigh)(void *), void (* cbWMEmpty)(void *));
extern QuecOSStatus quec_wm_deinit(wm_handle_t * wm_handle);
extern QuecOSStatus quec_wm_read(wm_handle_t * wm_handle, uint8 * buf, uint32 toReadLen, uint32 * pActualReadLen, void * cbArgv);
extern QuecOSStatus quec_wm_write(wm_handle_t * wm_handle, uint8 * buf, uint32 toWriteLen, uint32 * pActualWriteLen, void * cbArgv);
extern QuecOSStatus quec_wm_cnt(wm_handle_t * wm_handle, uint32 * pWmCnt);
extern QuecOSStatus quec_wm_empty(wm_handle_t * wm_handle);

#endif

