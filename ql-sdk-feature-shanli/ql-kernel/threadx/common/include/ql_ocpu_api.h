/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#ifndef __QL_OCPU_API_H__
#define __QL_OCPU_API_H__
#include "ql_type.h"

typedef struct {
	s32 (*trace)(char* fmt, ... );
	s32 (*sprintf)(char *, const char *, ...);
	s32 (*snprintf)(char*, u32, const char*, ...);
	s32 (*sscanf)(const char*, const char*, ...);
} ql_static_mapping;

typedef struct func_map         
{
    u32   *table_size;
    void  *get_fun_ptr_dep_name;
	//add system info here
}func_mapping;

typedef struct
{
    s32 hash;
    void * api_ptr;
} ql_open_api_list;

#endif  // End-of __QL_OCPU_API_H__
