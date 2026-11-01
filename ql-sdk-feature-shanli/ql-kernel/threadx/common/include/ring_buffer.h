/**
 ******************************************************************************
 * @file    ring_buffer.h
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


#ifndef RING_BUFFER_H
#define RING_BUFFER_H


#include "quec_common.h"
#include "quec_rtos.h"


typedef struct
{
	uint8 			* buffer;
	uint32 			in_pos;
	uint32 			out_pos;
	uint32 			total_size;
	uint32 			used_size;
	uint32 			free_size;
	quec_mutex_t 	mutex;
	quec_mutex_t 	mutex_ex;
} ring_buffer_t, * ring_buffer_handler_t;


extern QuecOSStatus quec_ring_buffer_init(ring_buffer_handler_t * ring_buffer_handler_ptr, uint32 buffer_size);
extern QuecOSStatus quec_ring_buffer_get_used_size(ring_buffer_handler_t ring_buffer_handler, uint32 * size_out);
extern QuecOSStatus quec_ring_buffer_get_free_size(ring_buffer_handler_t ring_buffer_handler, uint32 * size_out);
extern QuecOSStatus quec_ring_buffer_get_in_pos(ring_buffer_handler_t ring_buffer_handler, uint32 * in_pos_out);
extern QuecOSStatus quec_ring_buffer_get_out_pos(ring_buffer_handler_t ring_buffer_handler, uint32 * out_pos_out);
extern QuecOSStatus quec_ring_buffer_get_total_size(ring_buffer_handler_t ring_buffer_handler, uint32 * total_size_out);
extern QuecOSStatus quec_ring_buffer_write(ring_buffer_handler_t ring_buffer_handler, uint8 * data_ptr, uint32 data_size);
extern QuecOSStatus quec_ring_buffer_read(ring_buffer_handler_t ring_buffer_handler, uint8 * data_ptr, uint32 data_size);
extern QuecOSStatus quec_ring_buffer_write_ex(ring_buffer_handler_t ring_buffer_handler, uint8 * data_ptr, uint32 data_size, uint32 * actually_write_size_out);
extern QuecOSStatus quec_ring_buffer_read_ex(ring_buffer_handler_t ring_buffer_handler, uint8 * data_ptr, uint32 data_size, uint32 * actually_read_size_out);
extern QuecOSStatus quec_ring_buffer_reset(ring_buffer_handler_t ring_buffer_handler);
extern QuecOSStatus quec_ring_buffer_deinit(ring_buffer_handler_t * ring_buffer_handler_ptr);
extern QuecOSStatus quec_ring_buffer_jump(ring_buffer_handler_t ring_buffer_handler, uint32 jump_size);

#endif

