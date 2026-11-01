/******************************************************************************
*(C) Copyright 2008 Marvell International Ltd.
* All Rights Reserved
******************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: teldat.h
 *
 *  Description: Telephony Definitions for AT Command for CI_SG_ID_DEV.
 *
 *  History:
 *   Jan 17, 2008 - Creation of file
 *
 *  Notes:
 *
 ******************************************************************************/
#ifndef TELDAT_H
#define TELDAT_H

#include "ci_dat.h"
#include "ci_api_types.h"
#include "teldef.h"

#define CI_STUB_DAT_BUFFER_SIZE 0x800

typedef struct PS_sink_node
{
	void* 	data;
	UINT32 	length;
	struct PS_sink_node *next, *prev;
}PS_sink_node;


RETURNCODE_T  ciGpCGSink(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciGpTGSINK(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCGSend(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCsDataSink(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  atdb(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  vPDUS(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciVZWTESTAPP(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciPSSDC(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
#ifdef AT_FOR_GW20180208SN
RETURNCODE_T  ciNETDMSG(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCSQEX(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
#endif


void datCnf(CiSgOpaqueHandle opSgCnfHandle,
		CiServiceGroupID svgId,
		CiPrimitiveID    primId,
		CiRequestHandle  reqHandle,
		void*            paras);

void datCnf_2(CiSgOpaqueHandle  opSgCnfHandle,
		CiServiceGroupID  svgId,
		CiPrimitiveID     primId,
		CiRequestHandle   reqHandle,
		void*             paras);

void datInd(CiSgOpaqueHandle    opSgIndHandle,
		CiServiceGroupID    svgId,
		CiPrimitiveID       primId,
		CiIndicationHandle  indHandle,
		void*               pParam);

void datInd_2(CiSgOpaqueHandle    opSgIndHandle,
		CiServiceGroupID    svgId,
		CiPrimitiveID       primId,
		CiIndicationHandle  indHandle,
		void*               pParam);

UINT8 Get_sATP_Mode(UINT8 sATP);

extern void sendData2SACReq(unsigned char cid,char *buf, int len);
extern void ppp_process_data_nok(UINT8 cid, BOOL force);
void insert_node_into_PS_sink_Queue(PS_sink_node* node);
BOOL search_and_remove_node_from_PS_sink_Queue(char* buffer);
void ReleaseCid2ATPMap(UINT8 sATP);

/* 20201024 CSD buffer begin*/
#define TEL_CSD_BUFFER_UNIT_MAX_NUM 512
typedef struct 
{
	unsigned short atp;
	unsigned short size;
	unsigned char *p;	
}csd_buf_unit;
/* 20201024 CSD buffer end*/

#endif

