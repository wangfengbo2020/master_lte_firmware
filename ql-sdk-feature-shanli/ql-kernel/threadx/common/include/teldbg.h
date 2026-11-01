/******************************************************************************
*(C) Copyright 2008 Marvell International Ltd.
* All Rights Reserved
******************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: teldbg.h
 *
 *  Description:
 *
 *  History:
 *   Jun 5, 2008 - Creation of file
 *
 *  Notes:
 *
 ******************************************************************************/
#ifndef TELDBG_H
#define TELDBG_H

#include "ci_api_types.h"
#include "ci_api_client.h"
#include "teldef.h"
#include "telatci.h"
#include "telconfig.h"
#include "telatparamdef.h"
#include "ci_dev.h"

void dbg_dump_buffer(char* name,char* buf, int len);
void dbg_dump_string(char* name,char* buf, int len);
RETURNCODE_T  vDump(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);

/* Debugging Commands*/
RETURNCODE_T  cciReg(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  vHDL(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  vECHO(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
/* Fake Commands*/
RETURNCODE_T  ciCSCS(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);

#ifdef LWIP_IPNETBUF_SUPPORT
#ifndef LTEONLY_THIN_SINGLE_SIM_2MFLASH
utlReturnCode_T ciSetLogFunction(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
utlReturnCode_T ciGetLogFunction(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
#endif
#endif
#ifdef BT_TEST_SUPPORT
utlReturnCode_T ciBTTEST(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
#endif
utlReturnCode_T AtSLT(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);

#if defined(DM_SUPPORT_FRAMEWORK)
RETURNCODE_T  AtCam_I2C(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c  parameter_values_p,const size_t num_parameters, const char *info_text_p,unsigned int *xid_p,void *arg_p);
RETURNCODE_T  AtISP_REG(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c  parameter_values_p,const size_t num_parameters, const char *info_text_p,unsigned int *xid_p,void *arg_p);
RETURNCODE_T  AtCam_rawdump(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c  parameter_values_p,const size_t num_parameters, const char *info_text_p,unsigned int *xid_p,void *arg_p);
#endif
RETURNCODE_T  AtPMICReg(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c  parameter_values_p,const size_t num_parameters, const char *info_text_p,unsigned int *xid_p,void *arg_p);
RETURNCODE_T  AtRegRW(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c  parameter_values_p,const size_t num_parameters, const char *info_text_p,unsigned int *xid_p,void *arg_p);
RETURNCODE_T  atLwipCtrl(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c  parameter_values_p,const size_t num_parameters, const char *info_text_p,unsigned int *xid_p,void *arg_p);
RETURNCODE_T  atNtpCtrl(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c  parameter_values_p,const size_t num_parameters, const char *info_text_p,unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciSulogCfg(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c  parameter_values_p,const size_t num_parameters, const char *info_text_p,unsigned int *xid_p,void *arg_p);
RETURNCODE_T  AtFILETEST(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c  parameter_values_p,const size_t num_parameters, const char *info_text_p,unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciAudioCmd(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
#ifdef WIFI_FUNCTION_SUPPORT
RETURNCODE_T  ciWifiCmd(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
#endif
RETURNCODE_T  ATAUDNVM(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ciENVCFG(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
#endif
