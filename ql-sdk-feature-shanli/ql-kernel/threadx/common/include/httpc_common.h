/**
 ******************************************************************************
 * @file    httpc_common.h
 * @author  Chavis.Chen
 * @version V1.0.0
 * @date    06-Dec-2018
 * @brief   This file declares http request APIs.
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


#ifndef _HTTPC_COMMON_H
#define _HTTPC_COMMON_H


#define	HTTP_PROT_VER					"HTTP/1.1"
#define HTTP_PROT_VER_1_0               "HTTP/1.0"
#define	HTTP_RESP_HEAD_FIELD_END_STR	"\r\n"
#define	HTTP_RESP_HEAD_WHOLE_END_STR	"\r\n\r\n"
#define HTTP_RESP_CHUNKED_DELIMIT_STR	"\r\n"

#define CHR_SPACE						' '
#define CHR_COLON						':'
#define CHR_OPEN_BRACKET                '['
#define CHR_CLOSE_BRACKET               ']'


#define httpc_log(msg, ...)				custom_log("HTTP", msg, ##__VA_ARGS__)


typedef struct
{
	unsigned char * ptr;
	unsigned int  len;
} httpc_data_t;				/*> basic data type for big mass of memory */



extern char * httpc_skip(char * str, char chr, int * skip_num);
extern char * httpc_skip_spaces(char * str);


#endif

