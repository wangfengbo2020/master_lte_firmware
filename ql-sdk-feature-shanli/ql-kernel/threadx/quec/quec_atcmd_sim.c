/**  @file
  quec_atcmd_sim.c

  @brief
  This file is used to define the sim at command handler for different Quectel Project.

*/

/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
03/28/2019		  Tery	     aad airplanecontrol function
02/22/2019		  Tery	     add cfun urc and simdet urc
01/21/2019		  Tery	     add at+qoem="landipin" function
12/18/2018		  Tery	     add quec_exec_qsimdet_cmd and quec_exec_qsimstat_cmd function,spport AT+QSIMDET and AT+QSIMSTAT
12/10/2018		  Tery	     add quec_exec_qpinc_cmd function 
11/29/2018		  Tery	     add quec_exec_qinistat_cmd function,support AT+QINISTAT cmd
11/27/2018		  Tery	     add quec_exec_iccid_cmd function,support AT+QCCID?,AT+CCID cmd
11/09/2018        Jensen     Init version
=================================================================*/

/******************************************************************
 * include files
 ******************************************************************/
#include "telatci.h"
#include "ci_sim.h"
#include "ci_api_types.h"
#include "sim_api.h"
#include "telutl.h"
#include "FlashPartition.h"
#include "telcontroller.h"
#include "quec_include.h"
#include "quec_cust_feature.h"
#include "quec_atcmd_sim.h"
#include "quec_urc.h"
#include "quec_drivers.h"
#include "lfs_cache.h"
#include "dev_api.h"
#include "usim.h"
#include "quec_siolib.h"
#include "duster.h"
#include "ps_api.h"
#include "quec_sim.h"
#if QUEC_DUAL_SIM_SUPPORT
#include "quec_atcmd_network.h"
#include "mm_api.h"
#endif

#if QUEC_DUAL_IMEI_SUPPORT
#include "IMEI.h"
#endif

#ifndef MIN_SYS


#ifdef QUEC_ATCMD_LOG
	#define atcmd_sim_log(msg, ...)  custom_log("ATCMD_SIM", msg, ##__VA_ARGS__)
#else
	#define atcmd_sim_log(msg, ...)
#endif

static UINT8 gsimccidReqHandle;
static UINT8 gsimqpincOper = 0;

//Fitz.xu 20220125: To save reqhandle for AT+QDSIM response
#if QUEC_DUAL_SIM_SUPPORT
static UINT32 g_atHandle = 0;
#endif

#ifdef QUEC_CDMA_IMSI_SUPPORT
cdma_imsi_s quec_cdma_imsi={0};
extern int SendATCMDWaitResp(int sATPInd, char *inStr, int timeOut, char *okFmt, int okFlag, char *errFmt, char *outStr, int outLen);
#endif

#if QUEC_DUAL_SIM_SUPPORT
extern CiSimPinState gSimPinState;
extern CiSimPinState gSimPinState_1;
extern int getMasterSimID(void);
extern void CM_SwitchSimDone(UINT8 state);

extern char IMSI[16];
extern char IMSI_1[16];
extern UINT8 ICCID[CI_SIM_UDP_ICCID_LEN];
extern UINT8 ICCID_1[CI_SIM_UDP_ICCID_LEN];
extern CiPsNwRegInfo quec_cgreg_info[2];
extern CiPs4GNwRegInfo quec_cereg_info[2];
extern CiMmPrimRegResultInd quec_creg_info[2];
extern mmExtendedSignal_quec quec_netquality_info[2];
extern Quec_qnwinfo_type quec_qnwinfo[2];
extern CiSimPinState gSimPinState;
extern CiSimPinState gSimPinState_1;
#endif

#ifdef QUEC_ASR_SIM_ENBALE
/*Tery.shi 2018/11/29 <SIM> add QINISTAT command*/
extern UINT8 	SMSReadyFlag;
#if QUEC_DUAL_SIM_SUPPORT
extern UINT8 SMSReadyFlag_1;
#endif
extern CiBoolean gModemPbkReady;
extern CiBoolean gModemPbkReady_1;
extern CiSimStatus gSimStatus;
extern CiSimStatus gSimStatus_1;
//extern CiBoolean g_ISUSIM;
extern BOOL gSimType;
extern OSMsgQRef gATMsgQ;
#endif

/*Tery 2019-05-11 add cfun status urc when power on*/
extern int CurrentCfunValue;

#if QUEC_DUAL_SIM_SUPPORT
typedef struct 
{
	int mode;
	int format;
	//Fitz.xu 20211220: To fix BZASR-2319, Coverity scan error CID=4262082
	char oper[24];
	int Act;
	bool isRegister;
}quec_ds_cops_info_t;

quec_ds_cops_info_t quec_ds_cops_info[2];

void quec_ds_udpate_cops_info(bool isRegister, int mode, int format, char *name, int AcT, char simid)
{
	if (simid == SIM1)
	{
		memset(&quec_ds_cops_info[SIM1], 0, sizeof(quec_ds_cops_info_t));
	}
	else if (simid == SIM2)
	{
		memset(&quec_ds_cops_info[SIM2], 0, sizeof(quec_ds_cops_info_t));
	}
	else
	{
		CPUartLogPrintf("%s,%d, input sim id error", __func__, __LINE__);
		return;
	}
	
	quec_ds_cops_info[simid].isRegister = isRegister;
	quec_ds_cops_info[simid].mode = mode;
	quec_ds_cops_info[simid].format = format;
	strncpy(quec_ds_cops_info[simid].oper, name, 16);
	quec_ds_cops_info[simid].Act = AcT;
}

#endif
#ifdef QUEC_STARTREPORT_OPTIMIZE
int StartupReportStatusFlag = NONE_URC_ON;
int QuecStartReportFlag = 0;
char quec_startcpinurc[32] = {0};
char quec_startusimurc[32] = {0};
#endif
//Fitz.xu 20211221: To fix conflict between WIFISCAN and QDSRELEASE.
#if QUEC_DUAL_SIM_SUPPORT
static bool qdsrelease_flag = FALSE; 
#endif

/*===========================================================================
* FUNCTION quec_set_sim_ccid_cmd
*
* DESCRIPTION
*   This function set ccid value,indicates whether the QCCID or CCID command is enabled. 
*
* PARAMETERS
*	<mode>	  ccid oper cmd
*
* RETURNS
*	None
*  
* SIDE EFFECTS
*   None
===========================================================================*/
void quec_set_sim_ccid_cmd(UINT8 mode)
{
    gsimccidReqHandle = mode;
}

/*===========================================================================
* FUNCTION quec_get_sim_ccid_cmd
*
* DESCRIPTION
*	This function get ccid value,indicates whether the QCCID or CCID command is enabled. 
*
* PARAMETERS
*	None
*
* RETURNS
*	oper cmd idx
*  
* SIDE EFFECTS
*	None
===========================================================================*/
UINT8 quec_get_sim_ccid_cmd(void)
{
    return gsimccidReqHandle;
}
/******************************************************************
 *   Global Variable
 ******************************************************************/


#ifdef QUEC_AT_ICCID_SUPPORT
/*===========================================================================

FUNCTION QUEC_EXEC_ICCID_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QCCID command.
  This command returns iccid information.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.
    utlFAILED :if there was any problem in executing the command.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_exec_iccid_cmd
(
    const utlAtParameterOp_T        op,                  /* AT cmd type          */
    const char                     *command_name_p,      /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p,  /* AT cmd value         */
    const size_t                    num_parameters,      /* AT cmd number        */
    const char                     *info_text_p,         /* AT cmd usage string  */
    unsigned int                   *xid_p,               /* AT cmd handle        */
    void                           *arg_p                /* AT cmd parser number */
)
{

    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
	CiReturnCode    ret      = CIRC_FAIL;
    UINT32	        atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
	*xid_p = atHandle;
	/* Check the format of the request */
	switch (op)
	{
		case TEL_EXT_TEST_CMD:      /* AT+QCCID=? */
	    {
	#ifndef YS_GNSS_SUPPORT
		    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, 0);
	#else
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_YS_CCID_ERROR, 0);
	#endif
		    break;
	    }	        
    #if defined(__QUEC_OEM_VER_XGD__) || defined(YS_GNSS_SUPPORT)
        case TEL_EXT_GET_CMD:
	#ifdef YS_GNSS_SUPPORT 
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_YS_CCID_ERROR, 0);
			break;
	#endif

    #endif
        case TEL_EXT_SET_CMD:      /* AT+CCID= */
		case TEL_EXT_ACTION_CMD:   /* AT+QCCID  */
		#if defined (__QUEC_OEM_VER_CAC__)
		case TEL_EXT_GET_CMD:   /* AT+QCCID?  */
		#endif
		{
            if (strncasecmp(command_name_p, (char *)"+QCCID", 6) == 0)
            {
                quec_set_sim_ccid_cmd(QUEC_QCCID);
            }
    		else if (strncasecmp(command_name_p, (char *)"+ICCID", 6) == 0)
    		{
                quec_set_sim_ccid_cmd(QUEC_ICCID);
    		}
    		else
            {
                quec_set_sim_ccid_cmd(QUEC_CCID);
    		}
            ret = SIM_GetICCID(atHandle);
    		break;
    	}
		
		default:
		{
			ret = ATRESP(atHandle,
                         ATCI_RESULT_CODE_CME_ERROR,
                         CME_OPERATION_NOT_SUPPORTED,
                         NULL);
			break;
		}
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);

	return(rc);

}

#endif

#ifdef QUEC_ASR_SIM_ENBALE
/*Tery.shi 2018/11/29 <SIM> add QINISTAT command*/
/*===========================================================================
	
FUNCTION QUEC_EXEC_QINISTAT_CMD
		
DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QINISTAT command.
  This command can query initialization status of SIM/USIM card,like phonebook and SMS initialization is done or not.

DEPENDENCIES
  None
	
RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
     utlSUCCESS : if it is a success.
     utlFAILED :if there was any problem in executing the command.
		
SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_exec_qinistat_cmd
(
	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
	const char					   *command_name_p, 	 /* AT cmd name 		 */
	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
	const size_t					num_parameters, 	 /* AT cmd number		 */
	const char					   *info_text_p,		 /* AT cmd usage string  */
	unsigned int				   *xid_p,				 /* AT cmd handle		 */
	void						   *arg_p				 /* AT cmd parser number */
)
{
	UNUSEDPARAM(command_name_p)
	UNUSEDPARAM(num_parameters)
	UNUSEDPARAM(info_text_p)

	RETURNCODE_T rc = INITIAL_RETURN_CODE;
	CiReturnCode ret = CIRC_FAIL;
	UINT32 atHandle = MAKE_AT_HANDLE(* (TelAtParserID *) arg_p);
		
	*xid_p = atHandle;

    char            AtRespBuf[32] = {0};
	UINT8 respdata = 0;
    UINT8 smsready_flag=0;
    UINT8 pddome_flag=0;
	CiSimStatus *pSimStatus;

	if (atHandle == IND_REQ_HANDLE) {
		pSimStatus = &gSimStatus;
        smsready_flag=SMSReadyFlag;
        pddome_flag=gModemPbkReady;
	} else if (atHandle == IND_REQ_HANDLE_1) {
		pSimStatus = &gSimStatus_1;
        #if QUEC_DUAL_SIM_SUPPORT
        smsready_flag=SMSReadyFlag_1;
        #endif
        pddome_flag=gModemPbkReady_1;
	} else if (!GET_SIM1_FLAG(atHandle)) {
		pSimStatus = &gSimStatus;
        smsready_flag=SMSReadyFlag;
        pddome_flag=gModemPbkReady;
	} else {
		pSimStatus = &gSimStatus_1;
        #if QUEC_DUAL_SIM_SUPPORT
        smsready_flag=SMSReadyFlag_1;
        #endif
        pddome_flag=gModemPbkReady_1;
	}

	/* Check the format of the request */
	switch (op)
	{
		case TEL_EXT_TEST_CMD:      /* AT+QINISTAT=? */
		{
		    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QINISTAT: (0-7)");
		    break;
		}
		case TEL_EXT_EXEC_CMD:
		case TEL_EXT_ACTION_CMD:   /* AT+QINISTAT  */
		{
		    //extern BOOL pbkGetReady();  /* Tery.shi 2018/11/29 <PHB> modify PHB done judgement condition */
		    if(*pSimStatus == CI_SIM_ST_READY)
		    {
		        respdata |= 1;
		    }
#ifdef QUEC_ASR_SMS_ENABLE
		    if(!smsready_flag)
		    {
		        respdata |= 2;
		    }
#endif
#ifdef QUEC_ASR_PHB_ENBALE
		    if(pddome_flag)
		    {
		        respdata |= 4;
		    }
#endif
		    sprintf((char *)AtRespBuf, "%s%d", (char *)"+QINISTAT: ", respdata);		
            ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, AtRespBuf);
			break;
		}
		default:
		{
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			break;
		}
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);

	return(rc);

}

/*===========================================================================

FUNCTION quec_sim_type_urc

DESCRIPTION
  This function report sim type

DEPENDENCIES
  None

RETURN VALUE
  NULL

SIDE EFFECTS
  None
===========================================================================*/
#if QUEC_DUAL_SIM_SUPPORT
void quec_sim_type_urc(UINT32 indHandle)
#else
void quec_sim_type_urc(void)
#endif
{
    char   AtRspBuf [32] = {0};

#if QUEC_DUAL_SIM_SUPPORT
	if ((gSimStatus == CI_SIM_ST_READY) || (gSimStatus_1 == CI_SIM_ST_READY))
#else
	if(gSimStatus == CI_SIM_ST_READY)
#endif
    {
	#if QUEC_DUAL_SIM_SUPPORT
		if (getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)
		{
			#if 1
			//双卡单待模式下,SIM2上报也不带DS字样
			sprintf((char *)AtRspBuf, "%s\r\n", (char *)"+QUSIM: 1");	
			#else
			if (isMasterSim0() && (gSimStatus == CI_SIM_ST_READY))
			{
				sprintf((char *)AtRspBuf, "%s\r\n", (char *)"+QUSIM: 1");	
			}
			else if (!isMasterSim0() && (gSimStatus_1 == CI_SIM_ST_READY))
			{
				sprintf((char *)AtRspBuf, "%s\r\n", (char *)"+QUSIMDS: 1");	
			}
			#endif
		}
		else
		{
			if ((indHandle == IND_REQ_HANDLE) && (gSimStatus == CI_SIM_ST_READY))
			{
				sprintf((char *)AtRspBuf, "%s\r\n", (char *)"+QUSIM: 1");
			}
			else if ((indHandle == IND_REQ_HANDLE_1) && (gSimStatus_1 == CI_SIM_ST_READY))
			{
				sprintf((char *)AtRspBuf, "%s\r\n", (char *)"+QUSIMDS: 1");
			}
		}
	#else
		sprintf((char *)AtRspBuf, "%s\r\n", (char *)"+QUSIM: 1");
	#endif
      
	   #ifdef __QUEC_OEM_VER_NL__
       //NL not send 
       #else
		#ifdef QUEC_STARTREPORT_OPTIMIZE
		#if QUEC_DUAL_SIM_SUPPORT
			if ((indHandle == IND_REQ_HANDLE) &&(gSimStatus == CI_SIM_ST_READY))
		#else
			if ((gSimStatus == CI_SIM_ST_READY))
		#endif
			{
				if ((StartupReportStatusFlag != CFUN_URC_ON) &&(QuecStartReportFlag == 0))
				{
					int resbuflen = (strlen(AtRspBuf)>32)?32:strlen(AtRspBuf);
					strncpy(quec_startusimurc, AtRspBuf,resbuflen);
					quec_startusimurc[resbuflen] = '\0';
					StartupReportStatusFlag = USIM_URC_ON;
				}
				else 
				{
					(void)at_urc_send(NUM_OF_TEL_ATP, (uint8 *)AtRspBuf, strlen(AtRspBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
					StartupReportStatusFlag = USIM_URC_ON;
					QuecStartReportFlag = 1;
				}
			}
			#if QUEC_DUAL_SIM_SUPPORT
			else if ((indHandle == IND_REQ_HANDLE_1) &&(gSimStatus_1 == CI_SIM_ST_READY))
			{
				(void)at_urc_send(NUM_OF_TEL_ATP, (uint8 *)AtRspBuf, strlen(AtRspBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
			}
			#endif
		#else
			(void)at_urc_send(NUM_OF_TEL_ATP, (uint8 *)AtRspBuf, strlen(AtRspBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
		#endif
       #endif
	}
}

/*Tery.shi 2018/12/10 <SIM> add QPINC command*/
/*===========================================================================
* FUNCTION quec_get_qpinc_oper
*
* DESCRIPTION
*	This function get qpinc value,indicates whether the SC ,P2 or all command is enabled. 
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*  
* SIDE EFFECTS
*	None
===========================================================================*/
UINT8 quec_get_qpinc_oper(void)
{
    return gsimqpincOper;
}
/*===========================================================================
* FUNCTION quec_set_qpinc_oper
*
* DESCRIPTION
*   This function set qpinc value,indicates whether the SC ,P2 or all command is enabled. 
*
* PARAMETERS
*	<mode>	  qpinc oper cmd
*
* RETURNS
*	None
*  
* SIDE EFFECTS
*   None
===========================================================================*/
void quec_set_qpinc_oper(UINT8 oper)
{
    gsimqpincOper = oper;
}
/*===========================================================================
	
FUNCTION QUEC_EXEC_QPINC_CMD
		
DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QPINC command.
  This command can the number of attempts left to enter the password of SIM PIN/PUK.

DEPENDENCIES
  None
	
RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
     utlSUCCESS : if it is a success.
     utlFAILED :if there was any problem in executing the command.
		
SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_exec_qpinc_cmd
(
	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
	const char					   *command_name_p, 	 /* AT cmd name 		 */
	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
	const size_t					num_parameters, 	 /* AT cmd number		 */
	const char					   *info_text_p,		 /* AT cmd usage string  */
	unsigned int				   *xid_p,				 /* AT cmd handle		 */
	void						   *arg_p				 /* AT cmd parser number */
)
{
	UNUSEDPARAM(command_name_p)
	UNUSEDPARAM(num_parameters)
	UNUSEDPARAM(info_text_p)

	RETURNCODE_T rc = INITIAL_RETURN_CODE;
	CiReturnCode ret = CIRC_FAIL;
	CHAR  facStr[5];
	INT16 facStrLen = 0;
	
	UINT32 atHandle = MAKE_AT_HANDLE(* (TelAtParserID *) arg_p);
		
	*xid_p = atHandle;

    char            AtRespBuf[32] = {0};
	UINT8 respdata = 0;
	CiSimStatus *pSimStatus;

	if (atHandle == IND_REQ_HANDLE) {
		pSimStatus = &gSimStatus;
	} else if (atHandle == IND_REQ_HANDLE_1) {
		pSimStatus = &gSimStatus_1;
	} else if (!GET_SIM1_FLAG(atHandle)) {
		pSimStatus = &gSimStatus;
	} else {
		pSimStatus = &gSimStatus_1;
	}

	/* Check the format of the request */
	switch (op)
	{
		case TEL_EXT_TEST_CMD:      /* AT+QPINC=? */
		{
		    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QPINC: (\"SC\",\"P2\")");
		    break;
		}
		case TEL_EXT_SET_CMD:   /* AT+QPINC=  */
		{
		    if(getExtString( parameter_values_p, 0, &facStr[0], 2, &facStrLen, NULL) == TRUE)
		    {
		        if(!strncasecmp((char *)facStr, (char *)"SC", 2))
		        {
		            quec_set_qpinc_oper(QUEC_SIM_QPINC_QUERY_SC);
		        }
				else if(!strncasecmp((char *)facStr, (char *)"P2", 2))
				{
				    quec_set_qpinc_oper(QUEC_SIM_QPINC_QUERY_P2);
				}
				else
				{
				    ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
					break;
			    }
		        ret = SIM_GetPinState(atHandle, CMD_TYPE_PINCNT);
		    }
			else
			{
			    ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			}
			break;
		}
		case TEL_EXT_GET_CMD:   /* AT+QPINC?  */
		{
		    quec_set_qpinc_oper(QUEC_SIM_QPINC_QUERY_ALL);
		    ret = SIM_GetPinState(atHandle, CMD_TYPE_PINCNT);
		    break;
		}
		default:
		{
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			break;
		}
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);

	return(rc);

}


/*===========================================================================

FUNCTION quec_sim_set_cfun

DESCRIPTION
  This function set cfun value

DEPENDENCIES
  None

RETURN VALUE
  NULL

SIDE EFFECTS
  None
===========================================================================*/
void quec_sim_set_cfun(int cfun_value)
{
    char ATCFUN[11] = {'\0'};
   	OSA_STATUS osa_status;
	ATParserMsg atMsg;
	char *buf_ptr = NULL;

   	if(gATMsgQ == NULL)
   		return;

	snprintf(ATCFUN,11,"at+cfun=%d\r",cfun_value);

	buf_ptr = malloc(strlen(ATCFUN));
	if(buf_ptr == NULL)
		ASSERT(0);
	memcpy(buf_ptr,ATCFUN,strlen(ATCFUN));
	atMsg.data = (char *)buf_ptr;
	atMsg.length = strlen(ATCFUN);
#if 0
	atMsg.sATPInd = TEL_AT_CMD_ATP_11;
#else
    /* Fitz.xu 20200306: 
     * when use TEL_AT_CMD_ATP_11, parser_p in utlAtParse(...) is NULL, this causes dump.
     * because aParser_p[TEL_AT_CMD_ATP_11] is not initialized.
     */
    atMsg.sATPInd = TEL_AT_CMD_ATP_QUEC_INTERNAL;
#endif

	CPUartLogPrintf("%s: set CFUN%d",__FUNCTION__,cfun_value);

	//send the receive command to AT task
 	osa_status = OSAMsgQSend(gATMsgQ, sizeof(atMsg), (UINT8*)&atMsg, OSA_NO_SUSPEND);
	ASSERT(osa_status == OS_SUCCESS);

	CPUartLogPrintf("%s: set CFUN%d Done",__FUNCTION__,cfun_value);
	return;
}


#if (QUEC_USIM_PRESENCE_INTERRUPT_ENABLE == 1)
/*===========================================================================

FUNCTION quec_sim_insert_handle

DESCRIPTION
  This function handle sim insert

DEPENDENCIES
  None

RETURN VALUE
  NULL

SIDE EFFECTS
  None
===========================================================================*/
void quec_sim_insert_handle(UINT8* simdetenable, quec_pin_level_value_e simgpiostatus)
{
    UINT8 simstatenable = 0;
	UINT8 insertstatus = 0;
	char   AtRspBuf [50] = {0};
	
    
   // {
       // if(quectel_nv_fat_read(__QUEC_AT_QSIMSTAT_VALUE, &simstatenable, sizeof(simstatenable)) == QUEC_FAT_SUCCESS)
		//{
		    simstatenable = g_usim_det_stat.sim_report_enable;
		    if(1 == simstatenable)
		    {
		        insertstatus = 1;

				sprintf(AtRspBuf, "+QSIMSTAT: %d,%d", simstatenable, (UINT8)insertstatus);
				(void)at_urc_send(NUM_OF_TEL_ATP, (uint8 *)AtRspBuf, strlen(AtRspBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
		    }
		//}
			if(0 == simdetenable[0])  //Chaim20190831  det disable
			{
				atcmd_sim_log("sim det disable"); 
				return;
			}
			atcmd_sim_log("quec_usim insert process"); 
        #ifdef QUECTEL_PROJECT_CUST 
		
			if(GetCfunValue() != 0)  //Chaim 20191031 cfun0,if insert simcard,module will read simcard,receive cfun1,will not register
			{
				USIM_DetectFoundByHW(1);
			}
			else
			{
				atcmd_sim_log("cfun0 not allow handle sim card"); 		
			}
        #else
			quec_sim_set_cfun(0);
		    quec_sim_set_cfun(1);
        #endif
   // }
}

/*===========================================================================

FUNCTION quec_sim_remove_handle

DESCRIPTION
  This function handle sim remove

DEPENDENCIES
  None

RETURN VALUE
  NULL

SIDE EFFECTS
  None
===========================================================================*/
void quec_sim_remove_handle(UINT8* simdetenable, quec_pin_level_value_e simgpiostatus)
{
    char   AtRspBuf [50] = {0};
	UINT8 simstatenable = 0;
	UINT8 insertstatus = 0;

	//if(quectel_nv_fat_read(__QUEC_AT_QSIMSTAT_VALUE, &simstatenable, sizeof(simstatenable)) == QUEC_FAT_SUCCESS)
	//{
	    simstatenable = g_usim_det_stat.sim_report_enable;
	    if(1 == simstatenable)
	    {
	        insertstatus = 0;

			sprintf(AtRspBuf, "+QSIMSTAT: %d,%d", simstatenable, (UINT8)insertstatus);
			(void)at_urc_send(NUM_OF_TEL_ATP, (uint8 * )AtRspBuf, strlen(AtRspBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
	    }
	//}
	if(0 == simdetenable[0])  //Chaim20190831  det disable
	{
		atcmd_sim_log("sim det disable"); 
		return;
	}
#ifdef QUECTEL_PROJECT_CUST 
    atcmd_sim_log("quec_usim remove process"); 
    USIM_DetectFoundByHW(0);
    #else
	quec_sim_set_cfun(0);
	quec_sim_set_cfun(1);
    #endif
}

/*===========================================================================

FUNCTION quec_sim_hot_plug_handle

DESCRIPTION
  This function handle sim hot plug,incluede insert and remove

DEPENDENCIES
  None

RETURN VALUE
  NULL

SIDE EFFECTS
  None
===========================================================================*/
void quec_sim_hot_plug_handle(quec_pin_level_value_e level)
{
	UINT8 simdetenable[2] = {0};
	quec_pin_level_value_e simgpiostatus = level;
	//quec_siolib_get_usim_level(&simgpiostatus);  //Chaim20190831 use interrupt level
/*
	if(quectel_nv_fat_read(__QUEC_AT_QSIMDET_VALUE, &simdetenable, sizeof(simdetenable)) == QUEC_FAT_SUCCESS)
        
	{*/
        
        atcmd_sim_log("quec_usim hotplug interrupt_level=%d",level); 
        simdetenable[0] = g_usim_det_stat.sim_det_enable;
        simdetenable[1] = g_usim_det_stat.sim_insert_level;
	    /*insert (u)sim card*/
	    if(((0 == simdetenable[1]) && (0 == simgpiostatus)) 
			|| ((1 == simdetenable[1]) && (1 == simgpiostatus)))
	    {
            atcmd_sim_log("quec_usim insert,det_enable=%d,insert_level=%d",simdetenable[0],simdetenable[1]); 
            quec_sim_insert_handle(simdetenable, simgpiostatus);
	    }
		/*remove (u)sim card*/
		else if(((0 == simdetenable[1]) && (1 == simgpiostatus)) 
			|| ((1 == simdetenable[1]) && (0 == simgpiostatus)))
		{
            atcmd_sim_log("quec_usim remove,det_enable=%d,insert_level=%d",simdetenable[0],simdetenable[1]); 
		    quec_sim_remove_handle(simdetenable, simgpiostatus);
		}
	//}
}
#endif
/*Tery.shi 2018/11/29 <SIM> add QSIMDET,QSIMSTAT command*/
/*===========================================================================
	
FUNCTION quec_exec_qsimdet_cmd
		
DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QSIMDET command.
  This command enable sim card hotswap function. sim card is detected by gpio interrupt.

DEPENDENCIES
  None
	
RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
     utlSUCCESS : if it is a success.
     utlFAILED :if there was any problem in executing the command.
		
SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_exec_qsimdet_cmd
(
	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
	const char					   *command_name_p, 	 /* AT cmd name 		 */
	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
	const size_t					num_parameters, 	 /* AT cmd number		 */
	const char					   *info_text_p,		 /* AT cmd usage string  */
	unsigned int				   *xid_p,				 /* AT cmd handle		 */
	void						   *arg_p				 /* AT cmd parser number */
)
{
	UNUSEDPARAM(command_name_p)
	UNUSEDPARAM(num_parameters)
	UNUSEDPARAM(info_text_p)

	RETURNCODE_T rc = INITIAL_RETURN_CODE;
	CiReturnCode ret = CIRC_FAIL;
	UINT32 atHandle = MAKE_AT_HANDLE(* (TelAtParserID *) arg_p);
		
	*xid_p = atHandle;

    char   AtSaveBuf[2] = {0};
	char   AtRespBuf[32] = {0};
	UINT8 detenable = 0;
	UINT8 insertlevel = 0;
	int32 readresult = 0;
	

	/* Check the format of the request */
	switch (op)
	{
		case TEL_EXT_TEST_CMD:      /* AT+QSIMDET=? */
		{
		    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QSIMDET: (0,1),(0,1)");
		    break;
		}
		case TEL_EXT_GET_CMD:     /* AT+QSIMDET?  */
		{
            /*
			readresult = quectel_nv_fat_read(__QUEC_AT_QSIMDET_VALUE, &AtSaveBuf, sizeof(AtSaveBuf));

			if(readresult == QUEC_FAT_ERR_READ)
			{
			    ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				atcmd_sim_log("simdet value read from nv ERROR");
				break;
			}
            
			sprintf(AtRespBuf, "+QSIMDET: %d,%d", AtSaveBuf[0], AtSaveBuf[1]);
			*/
			atcmd_sim_log("get sim_det_enable=%d,sim_insert_level=%d",g_usim_det_stat.sim_det_enable,g_usim_det_stat.sim_insert_level); 
			sprintf(AtRespBuf, "+QSIMDET: %d,%d", g_usim_det_stat.sim_det_enable, g_usim_det_stat.sim_insert_level);
		    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)AtRespBuf);
		    break;
		}
		case TEL_EXT_SET_CMD:     /* AT+QSIMDET=  */
		{
		    if((getExtValue(parameter_values_p, 0, (int *)&detenable, 0, 1, 0) == TRUE) 
				&& (getExtValue(parameter_values_p, 1, (int *)&insertlevel, 0, 1, 0) == TRUE))
		    {
                /*
                readresult = quectel_nv_fat_read(__QUEC_AT_QSIMDET_VALUE, AtSaveBuf, sizeof(AtSaveBuf));
    			if(readresult == QUEC_FAT_SUCCESS)
    			{
                    if ((AtSaveBuf[0] == detenable) && (AtSaveBuf[1] == insertlevel))
                    {
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                        atcmd_sim_log("The same as NV");
                        break;
                    }   			    
    			}*/

                if((g_usim_det_stat.sim_det_enable == detenable) &&(g_usim_det_stat.sim_insert_level == insertlevel))
                {
                    atcmd_sim_log("set sim_det value is same with system value, return ok directly"); 
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                    break;
                }
                
		        AtSaveBuf[0] = detenable;
				AtSaveBuf[1] = insertlevel;
		        if(quectel_nv_fat_write(__QUEC_AT_QSIMDET_VALUE, AtSaveBuf, sizeof(AtSaveBuf))!=QUEC_FAT_SUCCESS)
		        {
		            ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
		            atcmd_sim_log("simdet value save to nv ERROR");
				    break;
		        }
                atcmd_sim_log("set sim_det_enable=%d,sim_insert_level=%d",detenable,insertlevel); 
                g_usim_det_stat.sim_det_enable = detenable;
                g_usim_det_stat.sim_insert_level = insertlevel;

				//Fitz.xu 20210422: Update insert_level for dual sim detect task.
			#if QUEC_ASR_SIM_HOT_PLUG_SUPPORT
				void quec_sim_set_insert_level(UINT8 insert_level);
				quec_sim_set_insert_level(g_usim_det_stat.sim_insert_level);
				extern void quec_usim_1_detect_pin_reconfig(void);
				quec_usim_1_detect_pin_reconfig();
			#endif 
			
			    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
		        break;
			}
			else
			{
			    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}
		}
		case TEL_EXT_ACTION_CMD: 
		default:
		{
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			break;
		}
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);

	return(rc);

}

/*===========================================================================
	
FUNCTION quec_exec_qsimstat_cmd
		
DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QSIMSTAT command.
  This command can urc report sim insert or remove.

DEPENDENCIES
  None
	
RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
     utlSUCCESS : if it is a success.
     utlFAILED :if there was any problem in executing the command.
		
SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_exec_qsimstat_cmd
(
	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
	const char					   *command_name_p, 	 /* AT cmd name 		 */
	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
	const size_t					num_parameters, 	 /* AT cmd number		 */
	const char					   *info_text_p,		 /* AT cmd usage string  */
	unsigned int				   *xid_p,				 /* AT cmd handle		 */
	void						   *arg_p				 /* AT cmd parser number */
)
{
	UNUSEDPARAM(command_name_p)
	UNUSEDPARAM(num_parameters)
	UNUSEDPARAM(info_text_p)

	RETURNCODE_T rc = INITIAL_RETURN_CODE;
	CiReturnCode ret = CIRC_FAIL;
	UINT32 atHandle = MAKE_AT_HANDLE(* (TelAtParserID *) arg_p);
		
	*xid_p = atHandle;

    char  AtRespBuf[32] = {0};
	UINT8 statenable = 0;
	quec_pin_level_value_e simgpiostatus = QUEC_PIN_LEVEL_LOW;
	UINT8 insertstatus = 0;
	int32 readresult = 0;
    char  at_read_buf[2] = {0};
    UINT8 insert_level = 0;

	/* Check the format of the request */
	switch (op)
	{
		case TEL_EXT_TEST_CMD:      /* AT+QSIMSTAT=? */
		{
		    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QSIMSTAT: (0,1)");
		    break;
		}
		case TEL_EXT_GET_CMD:     /* AT+QSIMSTAT?  */
		{

         //Chaim 20190831 not read fat directly
        
         /*
		    readresult = quectel_nv_fat_read(__QUEC_AT_QSIMSTAT_VALUE, &statenable, sizeof(UINT8));
			if(readresult == QUEC_FAT_ERR_READ)
			{
			    ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				atcmd_sim_log("simstat value read from nv ERROR");
				break;
			}
			else if(readresult == QUEC_FAT_FILE_NOT_EXIST)
			{
			    statenable = 0;
			}
          

            readresult = quectel_nv_fat_read(__QUEC_AT_QSIMDET_VALUE, at_read_buf, sizeof(at_read_buf));
			if(readresult == QUEC_FAT_ERR_READ)
			{
			    ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				atcmd_sim_log("simdet value read from nv ERROR");
                insert_level = 0;
			}
            else 
            {
                insert_level = at_read_buf[1];
            }*/
            insert_level = g_usim_det_stat.sim_insert_level;
            
			quec_get_usim_level(&simgpiostatus);
            /* When SIM inserted, GPIO level = 0*/
            if (insert_level == 0)
            {
                if(1 == simgpiostatus)
                {
                    insertstatus = 0;
                }
                else if(0 == simgpiostatus)
                {
                    insertstatus = 1;
                }
            }
            /* When SIM inserted, GPIO level = 1*/
            else if(insert_level == 1)
            {
                if(1 == simgpiostatus)
                {
                    insertstatus = 1;
                }
                else if(0 == simgpiostatus)
                {
                    insertstatus = 0;
                }
            }
			
			//sprintf(AtRespBuf, "+QSIMSTAT: %d,%d", statenable, (UINT8)insertstatus);
			atcmd_sim_log("get sim_report_enable=%d,insert_level=%d",g_usim_det_stat.sim_report_enable,insert_level); 
            sprintf(AtRespBuf, "+QSIMSTAT: %d,%d", g_usim_det_stat.sim_report_enable, (UINT8)insertstatus);
		    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)AtRespBuf);
		    break;
		}
		case TEL_EXT_SET_CMD:     /* AT+QSIMSTAT=  */
		{
		    if(getExtValue(parameter_values_p, 0, (int *)&statenable, 0, 1, 0) == TRUE)
		    {
                if(g_usim_det_stat.sim_report_enable == statenable)
                {
                    atcmd_sim_log("sim_report_enable is same with system");
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);  
				    break;
                }
		        if(quectel_nv_fat_write(__QUEC_AT_QSIMSTAT_VALUE, &statenable, sizeof(UINT8))!=QUEC_FAT_SUCCESS)
		        {
		            ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
		            atcmd_sim_log("simstat value save to nv ERROR");
				    break;
		        }
                
                atcmd_sim_log("set sim_report_enable=%d",statenable); 
                g_usim_det_stat.sim_report_enable = statenable;
			    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
		        break;
			}
			else
			{
			    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}
		}
		case TEL_EXT_ACTION_CMD:   
		default:
		{
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			break;
		}
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);

	return(rc);

}
#define QUEC_SIM_STATENABLE_DEFAULT      1
#define QUEC_SIM_DETENABLE_DEFAULT       1
#define QUEC_SIM_INSERTLEVEL_DEFAULT     0
/*===========================================================================
* FUNCTION quec_simdet_init
*
* DESCRIPTION
*	This function init sim det value. 
*
* PARAMETERS
*	None
*
* SIDE EFFECTS
*	None
===========================================================================*/
void quec_simdet_init(void)
{
    UINT8 statenable = QUEC_SIM_STATENABLE_DEFAULT;
	char   AtSaveBuf[2] = {0};

    AtSaveBuf[0] = QUEC_SIM_DETENABLE_DEFAULT;
	AtSaveBuf[1] = QUEC_SIM_INSERTLEVEL_DEFAULT;
	
	if(quectel_nv_fat_write(__QUEC_AT_QSIMSTAT_VALUE, &statenable, sizeof(UINT8))!=QUEC_FAT_SUCCESS)
	{
	    atcmd_sim_log("simstat value init error");
	}

	if(quectel_nv_fat_write(__QUEC_AT_QSIMDET_VALUE, &AtSaveBuf, sizeof(AtSaveBuf))!=QUEC_FAT_SUCCESS)
	{
	    atcmd_sim_log("simdet value init error");
	}
}

#if 0//删除联迪的定制//def QUECTEL_CUSTOMIZATION_FOR_LIANDI
#define __QUEC_SIM_LANDIPIN_STATUS_VALUE "quec_sim_landipin_status.value"

/*===========================================================================
* FUNCTION quec_get_sim_landipin_status
*
* DESCRIPTION
*	This function get sim landipin status value. 
*
* PARAMETERS
*	None
*
* SIDE EFFECTS
*	None
===========================================================================*/
bool quec_get_sim_landipin_status(uint8* status)
{
    uint8 landipin_status = 0;
	uint8 nvresult = 0;
#if QUEC_PRODUCTION_CFG_SUPPORT
	ST_quecCfgCustFeatureParams ST_CustFeatureParams = {0};
	nvresult = Quec_SysItemPara_Item_get(QUEC_CUST_FEATURE_CFG, &ST_CustFeatureParams, sizeof(ST_CustFeatureParams));
	if(nvresult == QUEC_SUCCESS)
	{
		landipin_status = ST_CustFeatureParams.oemLandiPin;
		CPUartLogPrintf("Item get landi pin status:%d", landipin_status);
	}
#else
	nvresult = quectel_nv_fat_read(__QUEC_SIM_LANDIPIN_STATUS_VALUE, &landipin_status, sizeof(landipin_status));
#endif
    if(nvresult == QUEC_FAT_SUCCESS)
    {
        *status = landipin_status;
		CPUartLogPrintf("get status:%d", *status);
		return TRUE;
    }
	else if(nvresult == QUEC_FAT_FILE_NOT_EXIST)
	{
	    uint8 landipin_default_value = 0;
#if 0
	    quectel_nv_fat_write(__QUEC_SIM_LANDIPIN_STATUS_VALUE, &landipin_default_value, sizeof(landipin_default_value));
#endif
		*status = landipin_default_value;
		return TRUE;
	}
	return FALSE;
}

/*===========================================================================
* FUNCTION quec_set_sim_landipin_status
*
* DESCRIPTION
*	This function get sim landipin status value. 
*
* PARAMETERS
*	None
*
* SIDE EFFECTS
*	None
===========================================================================*/
bool quec_set_sim_landipin_status(uint8 value)
{
    uint8 landipin_value = value;
#if QUEC_PRODUCTION_CFG_SUPPORT
	ST_quecCfgCustFeatureParams ST_CustFeatureParams = {0};
	/*reload params*/
    if(QUEC_SUCCESS != Quec_SysItemPara_Item_get(QUEC_CUST_FEATURE_CFG, &ST_CustFeatureParams, sizeof(ST_quecCfgCustFeatureParams)))
	{	
		atcmd_sim_log("Failed:Quec_SysItemPara_Item_get QUEC_CUST_FEATURE_CFG");
	}
	/*save params*/
	atcmd_sim_log("Quec_SysItemPara_Item_get QUEC_CUST_FEATURE_CFG ST_CustFeatureParams.oemLandiPin%d",ST_CustFeatureParams.oemLandiPin);
	ST_CustFeatureParams.oemLandiPin = landipin_value;
	if(QUEC_SUCCESS != Quec_SysItemPara_Item_set(QUEC_CUST_FEATURE_CFG, &ST_CustFeatureParams, sizeof(ST_quecCfgCustFeatureParams)))
#else		
    if(quectel_nv_fat_write(__QUEC_SIM_LANDIPIN_STATUS_VALUE, &landipin_value, sizeof(landipin_value))!=QUEC_FAT_SUCCESS)
#endif

    {
        atcmd_sim_log("set landipin value ERROR");
		return FALSE;
    }
	return TRUE;
}

#endif

/*===========================================================================

FUNCTION quec_cfun_report

DESCRIPTION
  This function report cfun status

DEPENDENCIES
  None

RETURN VALUE
  NULL

SIDE EFFECTS
  None
===========================================================================*/
#if QUEC_DUAL_SIM_SUPPORT
extern int CurrentCfunValue_1;
QuecOSStatus quec_cfun_report(uint8 simid)
#else
QuecOSStatus quec_cfun_report(void)
#endif
{
	char  AtRespBuf[32] = {0};
	#ifdef QUEC_AIR_PLANE_CTRL_ENABLE
	BOOL report_stat=1;
	quec_pin_level_value_e pin_level=QUEC_PIN_LEVEL_HIGH;
	extern BOOL quec_get_air_plane_enable(void);
    if((quec_get_air_plane_enable()==TRUE) && (quec_air_plane_pin_level_get(&pin_level)==QUEC_SUCCESS))
  {
    if(pin_level==QUEC_PIN_LEVEL_LOW)
    {
      quec_send_msg_to_handle_task(QUEC_AIR_PLANE_CTRL_MSG, &pin_level, sizeof(pin_level)); 
      report_stat=0;
    }
    else
    report_stat=1;
  }
   #endif
#if QUEC_DUAL_SIM_SUPPORT
	if (simid == CM_SIM_0)
	{
#ifdef QUEC_AIR_PLANE_CTRL_ENABLE
        if(report_stat==0)
        sprintf(AtRespBuf, "+CFUN: %d\r\n", 4);
        else
#endif
		sprintf(AtRespBuf, "+CFUN: %d\r\n", (UINT8)CurrentCfunValue);
	}
	else if (simid == CM_SIM_1)
	{
	#ifdef QUEC_AIR_PLANE_CTRL_ENABLE
        if(report_stat==0)
        sprintf(AtRespBuf, "+CFUNDS: %d\r\n", 4);
        else
    #endif
		sprintf(AtRespBuf, "+CFUNDS: %d\r\n", (UINT8)CurrentCfunValue_1);
	}
#else
    #ifdef QUEC_AIR_PLANE_CTRL_ENABLE
        if(report_stat==0)
        sprintf(AtRespBuf, "+CFUN: %d\r\n", 4);
        else
    #endif
	sprintf(AtRespBuf, "+CFUN: %d\r\n", (UINT8)CurrentCfunValue);
#endif

	at_urc_send(NUM_OF_TEL_ATP, (uint8 *)AtRespBuf, strlen(AtRespBuf), 0, URC_OUT_METHOD_UNICAST, NULL);
#ifdef QUEC_STARTREPORT_OPTIMIZE
#if QUEC_DUAL_SIM_SUPPORT
	if (simid == CM_SIM_0)	
	{
#endif
		if ((QuecStartReportFlag == 0) && (StartupReportStatusFlag == NONE_URC_ON))
		{
			StartupReportStatusFlag = CFUN_URC_ON;
		}
		else 
		{
			if(strlen(quec_startcpinurc))
			{
				at_urc_send(NUM_OF_TEL_ATP, (uint8 *)quec_startcpinurc, strlen(quec_startcpinurc), 0, URC_OUT_METHOD_UNICAST, NULL);
				memset(quec_startcpinurc, 0, sizeof(quec_startcpinurc));
			}
			if(strlen(quec_startusimurc))
			{
				at_urc_send(NUM_OF_TEL_ATP, (uint8 *)quec_startusimurc, strlen(quec_startusimurc), 0, URC_OUT_METHOD_UNICAST, NULL);
				memset(quec_startusimurc, 0, sizeof(quec_startusimurc));
			}
			StartupReportStatusFlag = ALL_URC_ON;
			QuecStartReportFlag = 1;
		}
#if QUEC_DUAL_SIM_SUPPORT
	}
	else if (simid == CM_SIM_1)
	{
		//Reserved: CM_SIM_1 reporting logic processing
	}
#endif
#endif
    return kNoErr;
}


#ifdef QUEC_AIR_PLANE_CTRL_ENABLE
/*Tery 20190328 aad airplanecontrol function*/
/*===========================================================================

FUNCTION quec_airplane_report

DESCRIPTION
  This function report airplane URC

DEPENDENCIES
  None

RETURN VALUE
  NULL

SIDE EFFECTS
  None
===========================================================================*/
QuecOSStatus quec_airplane_report(quec_pin_level_value_e level)
{
	char  AtRespBuf[32] = {0};
	uint8 gpio_level = (uint8)level;
	uint8 airplanecontrol = 0;
	int32 readresult = 0;
#if QUEC_PRODUCTION_CFG_SUPPORT
	ST_quecCfgCustFeatureParams ST_CustFeatureParams = {0};
	readresult = Quec_SysItemPara_Item_get(QUEC_CUST_FEATURE_CFG, &ST_CustFeatureParams, sizeof(ST_quecCfgCustFeatureParams));
    if(readresult == QUEC_SUCCESS)
	{
		airplanecontrol = ST_CustFeatureParams.airPlanePinEnable;
	}
#else
	readresult = quectel_nv_fat_read(__QUEC_AT_AIRPLANECONTROL_VALUE, &airplanecontrol, sizeof(airplanecontrol));
#endif

    if(readresult == QUEC_FAT_ERR_READ)
    {
        atcmd_sim_log("airplanecontrol value read from nv ERROR");
		return kGeneralErr;
    }

    if(0 == airplanecontrol)
    {
        return kNoErr;
    }

    if(QUEC_PIN_LEVEL_LOW == level)
    {
        quec_sim_set_cfun(4);
    }
	else
	{
	    quec_sim_set_cfun(1);
	}

    /* Enter airplane mode: +QIND: airplanestatus,1
     * Exit airplane mode : +QIND: airplanestatus,0
     */
	sprintf(AtRespBuf, "+QIND: airplanestatus,%d\r\n", !gpio_level);
	at_urc_send(NUM_OF_TEL_ATP, (uint8 *)AtRespBuf, strlen(AtRespBuf), 0, URC_OUT_METHOD_UNICAST, NULL);
	atcmd_sim_log("airplanecontrol debug");

    return kNoErr;
}

#endif



#endif

#if QUEC_VSIM_ENABLE
/*===========================================================================
* FUNCTION quec_get_vsim_profile_flash_addr
*
* DESCRIPTION
*   This function return the vsim profile address of flash based on byte
*
* DEPENDENCIES
*   None
*
* PARAMETERS
*	<partition_property>: 0 is main partition, 1 is backup partition
*
* RETURN VALUE
*   the flash address of the specified partition, return 0 if <partition_property> is invalid
*	
* SIDE EFFECTS
*   None
===========================================================================*/
unsigned int quec_vsim_get_profile_flash_addr(unsigned char partition_property)
{
    FlashLayoutConfInfo * p_flash_layout = GetFlashLayoutConfig();

	if (0 == partition_property)
	{
		return p_flash_layout->QuecVSIMProfileAddress;
	}
	else if (1 == partition_property)
	{
		return p_flash_layout->QuecVSIMProfileBackupAddress;
	}
	
	return 0;
}

/*========================================================================
* FUNCTION quec_vsim_get_flash_blk_size
*
* DESCRIPTION
*   This function return the block size of flash based on byte
*
* DEPENDENCIES
*   None
*
* PARAMETERS
*   None
*
* RETURN VALUE
*   the block size of flash based on byte
*	
* SIDE EFFECTS
*   None
==========================================================================*/
unsigned int quec_vsim_get_flash_blk_size(void)
{
	lfsBlockInfo * p_blk_prop = GetLfsBlkInfo(0);

	return p_blk_prop->FlashBlockSize;
}

/*===========================================================================
* FUNCTION quec_vsim_get_flow_rate
*
* DESCRIPTION
*   This function return the floa rate of sent and received
*
* DEPENDENCIES
*   None
*
* PARAMETERS
*	<rx_bytes>: to read the received bytes
*	<tx_bytes>: to read the sent bytes
*
* RETURN VALUE
*   None
*	
* SIDE EFFECTS
*   None
===========================================================================*/
void quec_vsim_get_flow_rate(unsigned long long *rx_bytes, unsigned long long *tx_bytes)
{
	if (NULL != rx_bytes)
	{
		*rx_bytes = get_rx_byte_all();
	}
	if (NULL != tx_bytes)
	{
		*tx_bytes = get_tx_byte_all();
	}
}

unsigned short int __attribute__((weak)) simcardStatus(void)
{
	return 2;
}

unsigned short int __attribute__((weak)) setVsimOrUsim(unsigned short int simType)
{
	return 0;
}

RETURNCODE_T  quec_exec_qvsim_cmd
(
	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
	const char					   *command_name_p, 	 /* AT cmd name 		 */
	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
	const size_t					num_parameters, 	 /* AT cmd number		 */
	const char					   *info_text_p,		 /* AT cmd usage string  */
	unsigned int				   *xid_p,				 /* AT cmd handle		 */
	void						   *arg_p				 /* AT cmd parser number */
)
{
	RETURNCODE_T	 rc 	  = INITIAL_RETURN_CODE;
	CiReturnCode	 ret	  = CIRC_FAIL;

	UINT32 atHandle = MAKE_AT_HANDLE(* (TelAtParserID *) arg_p);
	UINT8 param_num = 0;
    char  qvsim_cmd_str[40] = {0};
    UINT8 qvsim_cmd_str_len = 0;
	int vsim_opt = -1;
	UINT32 vsim_cfg = 0;
	char res_buf[128] = {0};
	
	*xid_p = atHandle;
	param_num = quec_get_at_param_num(parameter_values_p, num_parameters);

	switch (op)
	{
		case TEL_EXT_SET_CMD:     /* AT+QVSIM=  */
		{
			if (1 > param_num)
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}
			if (getExtString(parameter_values_p, 0, qvsim_cmd_str, sizeof(qvsim_cmd_str), (INT16 *)&qvsim_cmd_str_len, NULL) != TRUE)
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}
			//atcmd_sim_log("%s, %d", qvsim_cmd_str, simcardStatus());

			if (strcasecmp(qvsim_cmd_str, "switch") == 0)
			{
				vsim_opt = 0;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}
			
			if (param_num == 1)
			{
				switch (vsim_opt)
				{
					case 0:
						vsim_cfg = simcardStatus();
						if ((1==vsim_cfg) || (2==vsim_cfg))
						{
							sprintf(res_buf, "+QVSIM: \"%s\",%d", qvsim_cmd_str, vsim_cfg);
					    	ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, res_buf);
						}
						else
						{
							ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						}
						break;
					case 1:
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
						break;
					default:
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_INVALID_PARAM, NULL);
						break;
				}
				break;
			}
			else if (param_num == 2)
			{
				vsim_cfg = parameter_values_p[1].value.decimal;
				switch (vsim_opt)
				{
					case 0:
						if ((1!=vsim_cfg) && (2!=vsim_cfg))
						{
							ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_INVALID_PARAM, NULL);
							break;
						}
						if (0 == setVsimOrUsim(vsim_cfg))
						{
					    	ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
						}
						else
						{
							ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						}
						break;
					case 1:
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
						break;
					default:
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_INVALID_PARAM, NULL);
						break;
				}
				break;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}
		}
		case TEL_EXT_GET_CMD:     /* AT+QVSIM?  */
		{
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
		    break;
		}
		case TEL_EXT_TEST_CMD:      /* AT+QVSIM=? */
		{
		    ret = ATRESP (atHandle, ATCI_RESULT_CODE_OK, 0, "+QVSIM: \"switch\",(1,2)\r\n");
		    break;
		}
		default:
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			break;
		}

	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);
}

#endif

#ifdef QUEC_CDMA_IMSI_SUPPORT

/*
6F22鏍煎紡锛?

00 AA AA BB BB BB CC 80 DD DD

00浠ｈ〃CLASS=0

AA AA鏍规嵁MIN鍓?3浣嶈绠?

BB BB BB鏍规嵁MIN鍚?7浣嶈绠?

CC鏍规嵁MNC璁＄畻

80浠ｈ〃IMSI_M_PROGRAMMED=1銆両MSI_M_ADD_NUM=0

DD DD鏍规嵁MCC璁＄畻

MCC鏄?460

MNC鏄?03

MIN鏄?6591141482
46003
723 1553697
*/
//from cpin or at+qcdmaimsi at cmd
void quec_get_cdma_imsi_at_sequence(void)
{
    char res_buf[128] = {0};
    uint16 res_len=0;
    //char imsi_origin_buf[128] = {0};
    //char 6f22_IMSI[50]={0};
    uint32 temp32_data = 0;
    uint16 temp16_data=0;
    int resp_status= 0;
    uint8 i=0;
	resp_status = SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, "AT+CCHO=A0000003431002FF86FF0389FFFFFFFF\r\n", 20, NULL, 1, NULL, res_buf, sizeof(res_buf));
    if((0 == resp_status)&& ((NULL != strstr(res_buf,"OK")) || (NULL != strstr(res_buf,"0"))))
	{
		atcmd_sim_log("open channel:%s,",res_buf);
	}
    resp_status = SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, "AT+CSIM=16,01a40004026F2200\r\n", 20, NULL, 1, NULL, res_buf, sizeof(res_buf));
    if((0 == resp_status)&& ((NULL != strstr(res_buf,"OK")) || (NULL != strstr(res_buf,"0"))))
	{
		atcmd_sim_log("select ef6f22 :%s,",res_buf);
	}	
    resp_status = SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, "AT+CSIM=10,01b000000A\r\n", 20, NULL, 1, NULL, res_buf, sizeof(res_buf));
    //if((0 == resp_status)&& ((NULL != strstr(res_buf,"OK")) || (NULL != strstr(res_buf,"0"))))
    {
       //瑙ｆ瀽imsi鍐呭
       atcmd_sim_log("6f22 :%s,len=%d",res_buf,quec_cdma_imsi.data_len);
       if(0 !=quec_cdma_imsi.data_len)
       {
                  //AA  AA--get MIN 1-3 byte
               temp32_data = (quec_cdma_imsi.data[1]+(quec_cdma_imsi.data[2]<< 8)+111)%1000;
               quec_cdma_imsi.imsi[5]= temp32_data/100 ;
               quec_cdma_imsi.imsi[6]=(temp32_data%100)/10;;
               quec_cdma_imsi.imsi[7]= temp32_data%10; 
  atcmd_sim_log("data[1]=0x%x,data[2]=0x%x,temp32_data=0x%x",quec_cdma_imsi.data[1],quec_cdma_imsi.data[2],temp32_data);
  atcmd_sim_log("imsi[5-7]=0x%x,0x%x,0x%x",quec_cdma_imsi.imsi[5],quec_cdma_imsi.imsi[6],quec_cdma_imsi.imsi[7]);
               //BB  BB  BB--MIN  4-10 bit
               //get MIN4-6 byte
               temp32_data = quec_cdma_imsi.data[3]+(quec_cdma_imsi.data[4]<< 8)+(quec_cdma_imsi.data[5]<<16);
               temp16_data =temp32_data & 0x3ff; //get 10 bit
 atcmd_sim_log("temp32_data=0x%x,temp16_data=0x%x",temp32_data,temp16_data);

               temp16_data = (temp16_data+111)%1000;
               
               quec_cdma_imsi.imsi[12]= temp16_data/100;
               quec_cdma_imsi.imsi[13]= (temp16_data%100)/10;;
               quec_cdma_imsi.imsi[14]= temp16_data%10; 
 atcmd_sim_log("data[3]=0x%x,data[4]=0x%x,data[5]=0x%x",quec_cdma_imsi.data[3],quec_cdma_imsi.data[4],quec_cdma_imsi.data[5]);
  atcmd_sim_log("imsi[12-14]=0x%x,0x%x,0x%x",quec_cdma_imsi.imsi[12],quec_cdma_imsi.imsi[13],quec_cdma_imsi.imsi[14]);

  
                //get MIN 7 byte
               temp16_data = (temp32_data &0x3c00) >>10;  //get10-14bit
               quec_cdma_imsi.imsi[11] = temp16_data;
 atcmd_sim_log("temp32_data=0x%x,temp16_data=0x%x,imsi[11] =0x%x",temp32_data,temp16_data,quec_cdma_imsi.imsi[11]);
               
               //get MIN 8-10 byte
               temp16_data =temp32_data >>14; //get high 10 bit
               temp16_data = (temp16_data+111)%1000;
               quec_cdma_imsi.imsi[8]= temp16_data/100;
               quec_cdma_imsi.imsi[9]= (temp16_data%100)/10;;
               quec_cdma_imsi.imsi[10]= temp16_data%10;
 atcmd_sim_log("temp32_data=0x%x,temp16_data=0x%x",temp32_data,temp16_data);
  atcmd_sim_log("imsi[8-10]=0x%x,0x%x,0x%x",quec_cdma_imsi.imsi[8],quec_cdma_imsi.imsi[9],quec_cdma_imsi.imsi[10]);
                
               //get CC
               temp32_data = (quec_cdma_imsi.data[6]+11)%100;
               quec_cdma_imsi.imsi[3]= temp32_data/10;   
               quec_cdma_imsi.imsi[4]= temp32_data%10;  
 atcmd_sim_log("temp32_data=0x%x",temp32_data);
  atcmd_sim_log("3-4,0x%x,0x%x,0x%x",quec_cdma_imsi.data[6],quec_cdma_imsi.imsi[3],quec_cdma_imsi.imsi[4]);
             
               //get DD
               temp32_data =( quec_cdma_imsi.data[8]+(quec_cdma_imsi.data[9]<< 8)+101)%1000;
               quec_cdma_imsi.imsi[0]= temp32_data/100;
               quec_cdma_imsi.imsi[1]= (temp32_data%100)/10;;
               quec_cdma_imsi.imsi[2]= temp32_data%10;
           atcmd_sim_log("8-9,0x%x,0x%x",quec_cdma_imsi.data[8],quec_cdma_imsi.data[9]);
                atcmd_sim_log("temp32_data=0x%x",temp32_data);
  atcmd_sim_log("0-2,0x%x,0x%x,0x%x",quec_cdma_imsi.imsi[0],quec_cdma_imsi.imsi[1],quec_cdma_imsi.imsi[2]);

            for(i=0;i<15;i++)
            {
              quec_cdma_imsi.imsi[i] +=0x30;
            }
       }
            
           
            
    }
    resp_status=SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, "AT+CCHC=1\r\n", 20, NULL, 1, NULL, res_buf, sizeof(res_buf));
    if((0 == resp_status)&& ((NULL != strstr(res_buf,"OK")) || (NULL != strstr(res_buf,"0"))))
	{
		atcmd_sim_log("close channel ,%s",res_buf);
	}
   
    
}

bool quec_get_cdma_imsi_flag(void)
{
    return quec_cdma_imsi.flag;
}
#endif

//Fitz.xu 20210129: Add for AT+QDSIM command
//save to PSM
#if QUEC_DUAL_SIM_SUPPORT
void quec_sim_info_clear(void)
{
    gSimPinState = CIRC_SIM_FAILURE;
    gSimPinState_1 = CIRC_SIM_FAILURE;
    gSimStatus = CI_SIM_ST_NOT_READY;
    gSimStatus_1 = CI_SIM_ST_NOT_READY;
}

#ifndef __QUECTEL_PROJECT_EG912YEM_AA__ 
RETURNCODE_T  quec_exec_qdsim_cmd(const utlAtParameterOp_T op,
		const char                      *command_name_p,
		const utlAtParameterValue_P2c   parameter_values_p,
		const size_t                    num_parameters,
		const char                      *info_text_p,
		unsigned int                    *xid_p,
		void                            *arg_p)
{
	//UNUSEDPARAM(command_name_p)
	//UNUSEDPARAM(num_parameters)
	//UNUSEDPARAM(info_text_p)

	RETURNCODE_T rc = INITIAL_RETURN_CODE;
	CiReturnCode ret = CIRC_FAIL;
	int simId;
	INT32 ref;

	UINT32 atHandle = MAKE_AT_HANDLE( * (TelAtParserID *) arg_p );
	CHAR atRspBuf[100] = { 0 };
	*xid_p = atHandle;

	g_atHandle = atHandle;
	
    DBGMSG("atcmd_QDSIM: atHandle = %d, op=%d", atHandle, op);

	switch (op)
	{
		case TEL_EXT_GET_CMD:    /* AT+QDSIM?  */
		{
		    snprintf(atRspBuf, sizeof(atRspBuf) - 1, "+QDSIM: %d", getMasterSimID());
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, atRspBuf);
			break;
		}

		case TEL_EXT_TEST_CMD:    /* AT+QDSIM=? */
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QDSIM: (0,1)");
			break;
		}

		case TEL_EXT_SET_CMD:      /* AT+QDSIM= */
		{
			BOOL cmdValid = FALSE;
			if ( getExtValue( parameter_values_p, 0, &simId, 0, 1, 0 ) == TRUE )
			{
			#if defined(CM_DUAL_SIM_SUPPORT) && !defined(NO_DIALER)
			    ret = CM_SetMasterSimID((CMSimID)simId, CM_SwitchSimDone);
			    cmdValid = TRUE;

			    if (ret == 0 )
			    {
					#if !QUEC_DUAL_SIM_SUPPORT	
				    ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
					#endif
				}
				else
				{
					if (simId == getMasterSimID())
					{
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);	
					}
					else
					{
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
					}
				}
		    #endif
			}
			if(!cmdValid)
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
			break;
		}

		case TEL_EXT_ACTION_CMD:   /* AT+QDSIM */
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
			break;
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);

	return(rc);
}
#endif

//Set DSSS or DSDS
//0: DUAL SIM DUAL STANDBY, 1: DUAL SIM SINGLE STANDB, 2: reserved, 3: DUAL SIM DUAL STANDBY FOR FP
//default is 1, save to PSM
RETURNCODE_T  quec_exec_qdstype_cmd(const utlAtParameterOp_T op,
		const char						*command_name_p,
		const utlAtParameterValue_P2c	parameter_values_p,
		const size_t					num_parameters,
		const char						*info_text_p,
		unsigned int					*xid_p,
		void							*arg_p)
{
	//UNUSEDPARAM(command_name_p)
	//UNUSEDPARAM(num_parameters)
	//UNUSEDPARAM(info_text_p)

	RETURNCODE_T	rc = INITIAL_RETURN_CODE;
	CiReturnCode	ret = CIRC_FAIL;
	INT32	type;
	INT32	ref;

	UINT32 atHandle = MAKE_AT_HANDLE( * (TelAtParserID *) arg_p );
	CHAR atRspBuf[100] = { 0 };
	*xid_p = atHandle;
	int temp_type = 0;

    DBGMSG("quec_exec_qdstype_cmd: atHandle = %d, op=%d", atHandle, op);

	switch (op)
	{
		case TEL_EXT_GET_CMD:    /* AT+QDSTYPE?  */
		{
			#if QUEC_DUAL_SIM_SUPPORT
			temp_type = quec_get_dualSimType();
            #else
			temp_type = getDualSimType();
			#endif
			if (temp_type == CM_DUAL_SIM_SINGLE_STANDBY)
			{
				type = 0;
			}
			else if (temp_type == CM_DUAL_SIM_DUAL_STANDBY)
			{
				type = 1;	
			}
			else if (temp_type == CM_DUAL_SIM_DUAL_STANDBY_FP)
			{
				type = 2;	
			}
			else
			{
				//Fitz.xu 20211220: To fix BZASR-2319, Coverity scan error CID=4262100
				CPUartLogPrintf("%s, %d, error type=%d", __func__, __LINE__, type);	
			}
			
		    snprintf(atRspBuf, sizeof(atRspBuf) - 1, "+QDSTYPE: %d", type);
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, atRspBuf);
			break;
		}

		case TEL_EXT_TEST_CMD:    /* AT+QDSTYPE=? */
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QDSTYPE: (0-2)");
			break;
		}

		case TEL_EXT_SET_CMD:      /* AT+QDSTYPE= */
		{
			BOOL cmdValid = FALSE;
			if ( getExtValue( parameter_values_p, 0, (int *)&type, 0, 2, 0 ) == TRUE )
			{
				CPUartLogPrintf("%s, %d, type=%d", __func__, __LINE__, type);

			#if QUEC_DUAL_IMEI_SUPPORT
				extern IMEIData  localIMEI2;
				char imei2_default[16] = { 8,6,4,4,3,0,0,1,0,0,0,1,0,9,1,0 };

				if ((type == 1) || (type == 2))
				{
					if (memcmp(localIMEI2.digits , imei2_default, 16) == 0)
					{
						CPUartLogPrintf("IMEI 2 not writen, change to DSDS failed");

						ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
						break;
					}
				}
			#endif
		
				if (type == 0)
				{
					temp_type = CM_DUAL_SIM_SINGLE_STANDBY;	
				}
				else if (type == 1)
				{
					temp_type = CM_DUAL_SIM_DUAL_STANDBY;
				}
				else if (type == 2)
				{
					temp_type = CM_DUAL_SIM_DUAL_STANDBY_FP;
				}
				else
				{
					temp_type = CM_DUAL_SIM_SINGLE_STANDBY;	
				}
				
			    ret = setDualSimType(temp_type);
			    cmdValid = TRUE;
			    if (ret == 0)
                 {         
				    ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                    #if QUEC_DUAL_SIM_SUPPORT
                    	quec_send_msg_to_handle_task(QUEC_DUAL_SET_DEFAULT_APN_MSG, NULL, 0);
                    #endif
                }
				else
				    ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				
			}
			if(!cmdValid)
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
			break;
		}

		case TEL_EXT_ACTION_CMD:   /* AT+QDSTYPE */
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
			break;
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);

	return(rc);
}

//Bind atp_index to SIM1 or SIM2
//0: SIM1, 1: SIM2, 2: NONE
RETURNCODE_T  quec_exec_qdsbind_cmd(const utlAtParameterOp_T op,
		const char						*command_name_p,
		const utlAtParameterValue_P2c	parameter_values_p,
		const size_t					num_parameters,
		const char						*info_text_p,
		unsigned int					*xid_p,
		void							*arg_p)
{
	//UNUSEDPARAM(command_name_p)
	//UNUSEDPARAM(num_parameters)
	//UNUSEDPARAM(info_text_p)

	RETURNCODE_T	rc = INITIAL_RETURN_CODE;
	CiReturnCode	ret = CIRC_FAIL;
	INT32	simID;
	INT32	ref;

	UINT32 atHandle = MAKE_AT_HANDLE( * (TelAtParserID *) arg_p );
	CHAR atRspBuf[100] = { 0 };
	*xid_p = atHandle;
	UINT32 atpIndex = GET_ATP_INDEX(atHandle);

    DBGMSG("quec_exec_qdsbind_cmd: atHandle = %d, op=%d", atHandle, op);

	switch (op)
	{
		case TEL_EXT_GET_CMD:    /* AT+QDSBIND?  */
		{
		    if (atpIndex >= TEL_AT_CMD_ATP_36)
		    {
		        if (isAtpBindSim(atpIndex - TEL_AT_CMD_ATP_36))
		        	snprintf(atRspBuf, sizeof(atRspBuf) - 1, "+QDSBIND: %d", getBindSimId(atpIndex - TEL_AT_CMD_ATP_36));
		        else if ( atpIndex == AT_MODEM_CHANNLE_1 && isDualUsbModem())
		            snprintf(atRspBuf, sizeof(atRspBuf) - 1, "+QDSBIND: %d", SIM2);
		        else
			#if QUEC_DUAL_SIM_SUPPORT 
					snprintf(atRspBuf, sizeof(atRspBuf) - 1, "+QDSBIND: %d", SIMID_NUM);
			#else
		            snprintf(atRspBuf, sizeof(atRspBuf) - 1, "+QDSBIND: %d", isMasterSim0() ? SIM1 : SIM2);
			#endif
		    }
		    else
		    {
		        if (isAtpBindSim(atpIndex))
		        	snprintf(atRspBuf, sizeof(atRspBuf) - 1, "+QDSBIND: %d", getBindSimId(atpIndex));
		        else if ( atpIndex == AT_MODEM_CHANNLE && isDualUsbModem())
		            snprintf(atRspBuf, sizeof(atRspBuf) - 1, "+QDSBIND: %d", SIM1);
		        else
			#if QUEC_DUAL_SIM_SUPPORT 
					snprintf(atRspBuf, sizeof(atRspBuf) - 1, "+QDSBIND: %d", SIMID_NUM);
			#else
		            snprintf(atRspBuf, sizeof(atRspBuf) - 1, "+QDSBIND: %d", isMasterSim0() ? SIM1 : SIM2);
			#endif
		    }
				
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, atRspBuf);
			break;
		}

		case TEL_EXT_TEST_CMD:    /* AT+QDSBIND=? */
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QDSBIND: (0,1)");
			break;
		}

		case TEL_EXT_SET_CMD:      /* AT+QDSBIND= */
		{
			BOOL cmdValid = FALSE;
            if(!((getDualSimType() == CM_DUAL_SIM_DUAL_STANDBY) || (getDualSimType() == CM_DUAL_SIM_DUAL_STANDBY_FP)))
              {
                      CPUartLogPrintf("%s, %d, NOT SUPPORT DSBIND!!!", __func__, __LINE__);
                    ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
                    break;
               }
            
			if ( getExtValue( parameter_values_p, 0, (int *)&simID, 0, 1, 0 ) == TRUE )
			{
				CPUartLogPrintf("%s, %d, atpIndex=%d, simID=%d", __func__, __LINE__, atpIndex, simID);
				
			    ret = setBindSimIdCheck(atpIndex, (UINT8)simID);
			    cmdValid = TRUE;
				if (ret == 0) {
				    ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				    setBindSimId(atpIndex, (UINT8)simID);
			    }
				else
				    ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			}
			if(!cmdValid)
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
			break;
		}

		case TEL_EXT_ACTION_CMD:   /* AT+QDSBIND */
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
			break;
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);

	return(rc);
}

RETURNCODE_T quec_exec_qdsimi_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */ 
    void                           *arg_p               /* AT cmd parser number */
)
{
    TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
    UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
    RETURNCODE_T ret = utlSUCCESS;  
    *xid_p = atHandle;
	char resp_buf[128] = {0};
	char i = 0;
	char temp[3] = {0};

    switch (op)
    {
        case TEL_EXT_SET_CMD:
        case TEL_EXT_ACTION_CMD:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
            break;
		
        case TEL_EXT_GET_CMD:
			snprintf(resp_buf, sizeof(resp_buf), "+QDSIMI: 0,%s\r\n+QDSIMI: 1,%s", IMSI, IMSI_1);

			#if 0
			strcat(resp_buf, "+QDSIMI: 0,");
			for (i=0; i<16; i++)
			{
				sprintf(temp, "%c", IMSI[i]);
				strcat(resp_buf, temp);	
			}
			
			strcat(resp_buf, "\r\n");
			
			strcat(resp_buf, "+QDSIMI: 1,");
			for (i=0; i<16; i++)
			{
				sprintf(temp, "%c", IMSI_1[i]);
				strcat(resp_buf, temp);	
			}
			#endif
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resp_buf);
        	break;
		
        case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
        	break;
		
        default:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_ILLEGAL_OPERATION, NULL);
        	break;
    }

    return ret;
}

RETURNCODE_T quec_exec_qdsccid_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */ 
    void                           *arg_p               /* AT cmd parser number */
)
{
    TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
    UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
    RETURNCODE_T ret = utlSUCCESS;  
    *xid_p = atHandle;
	char resp_buf[128] = {0};
	char i = 0;
	char temp[3] = {0};
	char high_bits, low_bits;
	
    switch (op)
    {
        case TEL_EXT_SET_CMD:
        case TEL_EXT_ACTION_CMD:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
            break;
		
        case TEL_EXT_GET_CMD:
        {
			CPUartLogPrintf((const char *)"strlen(ICCID)=%d, strlen(ICCID_1)=%d,", strlen(ICCID), strlen(ICCID_1));
			
			strcat(resp_buf, "+QDSCCID: 0,");
			if (strlen((const char *)ICCID) > 0)
			{
				for (i=0; i<CI_SIM_UDP_ICCID_LEN; i++)
				{
					CPUartLogPrintf("ICCID[%d]=0x%x", i, ICCID[i]);
					
					high_bits = (ICCID[i]&0xF0)>>4;
					low_bits = ICCID[i]&0x0F;
					sprintf(temp, "%X%X", low_bits, high_bits);
					strcat(resp_buf, temp);	
				}
			}
			strcat(resp_buf, "\r\n");
			
			strcat(resp_buf, "+QDSCCID: 1,");
			if (strlen((const char *)ICCID_1) > 0)
			{
				for (i=0; i<CI_SIM_UDP_ICCID_LEN; i++)
				{
					high_bits = (ICCID_1[i]&0xF0)>>4;
					low_bits = ICCID_1[i]&0x0F;
					sprintf(temp, "%X%X", low_bits, high_bits);
					strcat(resp_buf, temp);	
				}
			}
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resp_buf);
        	break;
        }
        case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
        	break;
		
        default:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_ILLEGAL_OPERATION, NULL);
        	break;
    }

    return ret;
}

RETURNCODE_T quec_exec_qdspin_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */ 
    void                           *arg_p               /* AT cmd parser number */
)
{
    TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
    UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
    RETURNCODE_T ret = utlSUCCESS;  
    *xid_p = atHandle;
	char resp_buf[128] = {0};
	char temp[32] = {0};
	char i = 0;
	char pin_state;
	
    switch (op)
    {
        case TEL_EXT_SET_CMD:
        case TEL_EXT_ACTION_CMD:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
            break;
		
        case TEL_EXT_GET_CMD:
        {
			strcat(resp_buf, "+QDSPIN: 0,");

			for (i=0; i<2; i++)
			{
				if (i == 0)
				{
					pin_state = gSimPinState;
				}
				else
				{
					pin_state = gSimPinState_1;
				}
				
				switch (pin_state)
				{
					case CI_SIM_PIN_ST_READY:
						strncpy(temp, "READY", sizeof(temp));
					break;

					case CI_SIM_PIN_ST_UNIVERSALPIN_REQUIRED:
					case CI_SIM_PIN_ST_CHV1_REQUIRED:
						strncpy(temp, "SIM PIN", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_CHV2_REQUIRED:
						strncpy(temp, "SIM PIN2", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_UNBLOCK_UNIVERSALPIN_REQUIRED:
					case CI_SIM_PIN_ST_UNBLOCK_CHV1_REQUIRED:
						strncpy(temp, "SIM PUK", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_UNBLOCK_CHV2_REQUIRED:
						strncpy(temp, "SIM PUK2", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_HIDDENKEY_REQUIRED:
						strncpy(temp, "PH-FSIM PIN", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_UNBLOCK_HIDDENKEY_REQUIRED:
						strncpy(temp, "PH-FSIM PUK", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_PCK_REQUIRED:
						strncpy(temp, "PH-SIMLOCK PIN", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_NCK_REQUIRED:
						strncpy(temp, "PH-NET PIN", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_NSCK_REQUIRED:
						strncpy(temp, "PH-NETSUB PIN", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_SPCK_REQUIRED:
						strncpy(temp, "PH-SP PIN", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_CCK_REQUIRED:
						strncpy(temp, "PH-CORP PIN", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_UNBLOCK_PCK_REQUIRED:
						strncpy(temp, "PH-SIMLOCK PUK", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_UNBLOCK_NCK_REQUIRED:
						strncpy(temp, "PH-NET PUK", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_UNBLOCK_NSCK_REQUIRED:
						strncpy(temp, "PH-NETSUB PUK", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_UNBLOCK_SPCK_REQUIRED:
						strncpy(temp, "PH-SP PUK", sizeof(temp));
						break;

					case CI_SIM_PIN_ST_UNBLOCK_CCK_REQUIRED:
						strncpy(temp, "PH-CORP PUK", sizeof(temp));
						break;
					default:
						strncpy(temp, "NOT READY", sizeof(temp));
						break;
				}

				if (i == 0)
				{
					strcat(resp_buf, temp);
					strcat(resp_buf, "\r\n");
					strcat(resp_buf, "+QDSPIN: 1,");
				}
				else 
				{
					strcat(resp_buf, temp);	
				}
			}
			
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resp_buf);
        	break;
        }
        case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
        	break;
		
        default:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_ILLEGAL_OPERATION, NULL);
        	break;
    }

    return ret;
}

RETURNCODE_T quec_exec_qdsreg_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */ 
    void                           *arg_p               /* AT cmd parser number */
)
{
    TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
    UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
    RETURNCODE_T ret = utlSUCCESS;  
    *xid_p = atHandle;
	char resp_buf[128] = {0};
	int reg_status=0;
	char creg0[64] = {0};
	char creg1[64] = {0};
	char *p_temp = NULL;
	char i = 0;
	char cereg_status = 0;
	char creg_status = 0;
	
    switch (op)
    {
        case TEL_EXT_SET_CMD:
        case TEL_EXT_ACTION_CMD:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
            break;
		
        case TEL_EXT_GET_CMD:
        {
			for (i=0; i<2; i++)
			{
				if (i == 0)
				{
					p_temp = &creg0[0];	
				}
				else
				{
					p_temp = &creg1[0];
				}

				creg_status = quec_regstatus_asr2quec(quec_creg_info[i].RegStatus, 1);
				cereg_status = quec_regstatus_asr2quec(quec_cereg_info[i].status, 1);

				quectel_current_config_value_get(AT_CREG, &reg_status);

				if ((creg_status == 0) && (cereg_status != 0))
				{
					//Fitz.xu 20211122: To fix STASR1601-4666, CTCC card can not be registered to 2/3G.
					//So use cereg instead creg.
				
					creg_status = cereg_status;	
				}
				
				if (reg_status == 0 || reg_status == 1)
				{
					sprintf(p_temp,"%d,%d", reg_status, creg_status);
				}
				else if (reg_status == 2 )
				{
					CPUartLogPrintf("i=%d, creg info present=%d, cereg info present=%d", i, quec_creg_info[i].info.Present, quec_cereg_info[i].tacPresent);
					if (quec_creg_info[i].info.Present)
					{
						sprintf( p_temp,"%d,%d,\"%04X\",\"%04X\",%d", reg_status, creg_status, quec_creg_info[i].info.LocArea,\
							quec_creg_info[i].info.CellId, quec_act_asr2quec(quec_creg_info[i].info.AcT));	
					}
					else if (quec_cereg_info[i].tacPresent)
					{
						//Fitz.xu 20211215: To fix STASR1601-4666, CTCC sim card can not registerd in 2G.
						//So can not get creg info, using cereg info instead.
						
						sprintf( p_temp,"+CREG: %d,%d,\"%04X\",\"%04X\",%d\r\n", reg_status, cereg_status, quec_cereg_info[i].tac, \
							quec_cereg_info[i].cellId, quec_act_asr2quec(quec_cereg_info[i].act));	
					}
					else
                    {
                       sprintf(p_temp,"%d,%d", reg_status, creg_status);
                    }
				}
				else
				{
					//do nothing	
				}
			}
						
			snprintf(resp_buf, sizeof(resp_buf), "+QDSREG: 0,%s\r\n+QDSREG: 1,%s", creg0 , creg1);
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resp_buf);
        	break;
        }
        case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
        	break;
		
        default:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_ILLEGAL_OPERATION, NULL);
        	break;
    }

    return ret;
}

RETURNCODE_T quec_exec_qdsgreg_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */ 
    void                           *arg_p               /* AT cmd parser number */
)
{
    TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
    UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
    RETURNCODE_T ret = utlSUCCESS;  
    *xid_p = atHandle;
	char resp_buf[128] = {0};
	int reg_status=0;
    UINT8 net_status=0;
	char cgreg0[64] = {0};
	char cgreg1[64] = {0};
	char *p_temp = NULL;
	char i = 0;
	uint8 status;
	uint16 lac;
	uint32 cellId;
	uint8 act;
	bool lacPresent;

    switch (op)
    {
        case TEL_EXT_SET_CMD:
        case TEL_EXT_ACTION_CMD:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
            break;
		
        case TEL_EXT_GET_CMD:
		{
			for (i=0; i<2; i++)
			{
				if (i == 0)
				{
					p_temp = &cgreg0[0];	
				}
				else
				{
					p_temp = &cgreg1[0];
				}

				if (quec_cgreg_info[i].status != 0)
				{
					status = quec_cgreg_info[i].status; 
					lac = quec_cgreg_info[i].lac;
					cellId = quec_cgreg_info[i].cellId;
					act = quec_cgreg_info[i].act;
					lacPresent = quec_cgreg_info[i].lacPresent;
				}
				else
				{
					status = quec_cereg_info[i].status; 
					lac = quec_cereg_info[i].tac;
					cellId = quec_cereg_info[i].cellId;
					act = quec_cereg_info[i].act;
					lacPresent = quec_cereg_info[i].tacPresent;
				}

				quectel_current_config_value_get(AT_CGREG, &reg_status);
				net_status=quec_regstatus_asr2quec(status, 1);
                if(reg_status == 0 || reg_status == 1)
                {
                     sprintf( p_temp,"%d,%d", reg_status, net_status);
                }
                else 
                {    
                    if (lacPresent && (net_status == 1 || net_status == 5))
                    {    
						sprintf( p_temp,"%d,%d,\"%04X\",\"%04X\",%d", reg_status, net_status, lac, cellId, quec_act_asr2quec(act));
					}
                    else
                    {
                       sprintf(p_temp,"%d,%d", reg_status, net_status);
                    }
                }
			}
						
			snprintf(resp_buf, sizeof(resp_buf), "+QDSGREG: 0,%s\r\n+QDSGREG: 1,%s", cgreg0, cgreg1);
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resp_buf);
        	break;
        }
        case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
        	break;
		
        default:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_ILLEGAL_OPERATION, NULL);
        	break;
    }

    return ret;
}

RETURNCODE_T quec_exec_qdsereg_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */ 
    void                           *arg_p               /* AT cmd parser number */
)
{
    TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
    UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
    RETURNCODE_T ret = utlSUCCESS;  
    *xid_p = atHandle;
	char resp_buf[128] = {0};
	int reg_status=0;
    UINT8 net_status=0;
	char cereg0[64] = {0};
	char cereg1[64] = {0};
	char *p_temp = NULL;
	char i = 0;

    switch (op)
    {
        case TEL_EXT_SET_CMD:
        case TEL_EXT_ACTION_CMD:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
            break;
		
        case TEL_EXT_GET_CMD:
		{
			for (i=0; i<2; i++)
			{
				if (i == 0)
				{
					p_temp = &cereg0[0];	
				}
				else
				{
					p_temp = &cereg1[0];
				}

				quectel_current_config_value_get(AT_CEREG, &reg_status);
				net_status=quec_regstatus_asr2quec(quec_cereg_info[i].status, 1);
                if(reg_status==0 || reg_status==1)
                {
                     sprintf( p_temp, "%d,%d", reg_status, net_status);
                }
                else 
                {    
                    if(quec_cereg_info[i].tacPresent && (net_status == 1 || net_status == 5))
                    {    
						sprintf( p_temp,"%d,%d,\"%04X\",\"%04X\",%d", reg_status, net_status, quec_cereg_info[i].tac,\
							quec_cereg_info[i].cellId, quec_act_asr2quec(quec_cereg_info[i].act));
					}
                    else
                    {
                       sprintf( p_temp,"%d,%d", reg_status, net_status);
                    }
                }
			}
						
			snprintf(resp_buf, sizeof(resp_buf), "+QDSEREG: 0,%s\r\n+QDSEREG: 1,%s", cereg0, cereg1);
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resp_buf);
        	break;
        }		
        case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
        	break;
		
        default:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_ILLEGAL_OPERATION, NULL);
        	break;
    }

    return ret;
}

RETURNCODE_T quec_exec_qdsq_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */ 
    void                           *arg_p               /* AT cmd parser number */
)
{
    TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
    UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
    RETURNCODE_T ret = utlSUCCESS;  
    *xid_p = atHandle;
	char resp_buf[128] = {0};
	char tmp_buf[64] = {0};
	uint8_t len = 0;

    switch (op)
    {
        case TEL_EXT_SET_CMD:
        case TEL_EXT_ACTION_CMD:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
            break;
		
        case TEL_EXT_GET_CMD:
			quec_report_qcsq_dual_sim(1, tmp_buf, SIM1);
			len = snprintf(resp_buf, sizeof(tmp_buf), "+QDSQ: 0,%s", tmp_buf);
		
			memset(tmp_buf, 0, sizeof(tmp_buf));

			quec_report_qcsq_dual_sim(1, tmp_buf, SIM2);
			snprintf(resp_buf + len, sizeof(tmp_buf), "+QDSQ: 1,%s", tmp_buf);
			
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resp_buf);
        	break;
		
        case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
        	break;
		
        default:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_ILLEGAL_OPERATION, NULL);
        	break;
    }

    return ret;
}

RETURNCODE_T quec_exec_qdsops_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */ 
    void                           *arg_p               /* AT cmd parser number */
)
{
    TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
    UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
    RETURNCODE_T ret = utlSUCCESS;  
    *xid_p = atHandle;
	char resp_buf[128] = {0};
	char temp_buf[128] = {0};

    switch (op)
    {
        case TEL_EXT_SET_CMD:
        case TEL_EXT_ACTION_CMD:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
            break;
		
        case TEL_EXT_GET_CMD:
			//Fitz.xu 20220104: To fix STASR1601-4812
			MM_GetCurrOperator(SIMULATE_SIM1_REQ_HANDLE);
			MM_GetCurrOperator(SIMULATE_SIM2_REQ_HANDLE);

            //Fitz.xu 20220104: Add this to make quec_ds_cops_info[] get valid info.
			OSATaskSleep(2);
			
			if (quec_ds_cops_info[0].isRegister)
			{
				snprintf(temp_buf, sizeof(temp_buf), "+QDSOPS: 0,%d,%d,\"%s\",%d\r\n", quec_ds_cops_info[0].mode,\
					quec_ds_cops_info[0].format, quec_ds_cops_info[0].oper, quec_ds_cops_info[0].Act);
			}
			else
			{
				snprintf(temp_buf, sizeof(temp_buf), "+QDSOPS: 0,%d\r\n", quec_ds_cops_info[0].mode);
			}	
			strcat(resp_buf, temp_buf);

			memset(temp_buf, 0, sizeof(temp_buf));
			if (quec_ds_cops_info[1].isRegister)
			{
				snprintf(temp_buf, sizeof(temp_buf), "+QDSOPS: 1,%d,%d,\"%s\",%d\r\n", quec_ds_cops_info[1].mode,\
					quec_ds_cops_info[1].format, quec_ds_cops_info[1].oper, quec_ds_cops_info[1].Act);
			}
			else
			{
				snprintf(temp_buf, sizeof(temp_buf), "+QDSOPS: 1,%d\r\n", quec_ds_cops_info[1].mode);
			}
			strcat(resp_buf, temp_buf);
			
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resp_buf);
        	break;
		
        case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
        	break;
		
        default:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_ILLEGAL_OPERATION, NULL);
        	break;
    }

    return ret;
}

RETURNCODE_T quec_exec_qdslock_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */ 
    void                           *arg_p               /* AT cmd parser number */
)
{
    TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
    UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
    RETURNCODE_T ret = utlSUCCESS;  
    *xid_p = atHandle;

    return ret;
}

void quec_qdsrelease_flag_set(bool flag)
{
	qdsrelease_flag = flag;
}

bool quec_qdsrelease_flag_get(void)
{
	return qdsrelease_flag;
}

RETURNCODE_T quec_exec_qdsrelease_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */ 
    void                           *arg_p               /* AT cmd parser number */
)
{
    TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
    UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
    RETURNCODE_T ret = utlSUCCESS;  
    *xid_p = atHandle;
	int simid = 0;

	CPUartLogPrintf("%s,%d,sAtpIndex=%d,atHandle=%d", __func__, __LINE__, sAtpIndex, atHandle);
	
    switch (op)
    {
        case TEL_EXT_SET_CMD:
			if (getExtValue( parameter_values_p, 0, &simid, 0, 1, 0 ) == TRUE)
			{
				if (simid == SIM1)
				{
					if (*(TelAtParserID *)arg_p > 36)
					{
						sAtpIndex = (TelAtParserID)(*(TelAtParserID *)arg_p - 36);	
					}
				}
				else if (simid == SIM2)
				{
					if (*(TelAtParserID *)arg_p < 36)
					{
						sAtpIndex = (TelAtParserID)(*(TelAtParserID *)arg_p + 36);
					}			
				}

				atHandle = MAKE_AT_HANDLE(sAtpIndex);
				ret = PS_FastDormancy(atHandle);
				quec_qdsrelease_flag_set(TRUE);
				CPUartLogPrintf("%s,%d,sAtpIndex=%d,atHandle=%d", __func__, __LINE__, sAtpIndex, atHandle);
				ret = ATRESP(*xid_p, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_INVALID_PARAM, NULL);
			}
			
            break;
        case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, "+QDSRELEASE: (0,1)");
        	break;
		
		case TEL_EXT_ACTION_CMD:
        case TEL_EXT_GET_CMD:
        default:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_ILLEGAL_OPERATION, NULL);
        	break;
    }

    return ret;
}

bool quec_is_atp_bind_sim1(UINT32 atpIndex)
{
	UINT8 temp = 0;

	if (atpIndex >= TEL_AT_CMD_ATP_36)
    {
        if (isAtpBindSim(atpIndex - TEL_AT_CMD_ATP_36))
        {
        	temp = getBindSimId(atpIndex - TEL_AT_CMD_ATP_36);
        }
        else if ( atpIndex == AT_MODEM_CHANNLE_1 && isDualUsbModem())
        {
            temp = SIM2;
        }
        else
        {
            temp = SIMID_NUM;
        }
    }
    else
    {
        if (isAtpBindSim(atpIndex))
        {
        	temp = getBindSimId(atpIndex);
        }
        else if ( atpIndex == AT_MODEM_CHANNLE && isDualUsbModem())
        {
            temp = SIM1;
        }
        else
        {
            temp = SIMID_NUM;
        }
    }
	
	if (temp == SIM1)
	{
		//Fitz.xu 20211220: To fix BZASR-2319, Coverity scan error CID=4262105  
		CPUartLogPrintf("%s,%d,atp_%d is bind to SIM1", __func__, __LINE__, atpIndex);
		return TRUE;	
	}
	else
	{
		return FALSE;
	}
}

bool quec_is_atp_bind_sim2(UINT32 atpIndex)
{
	UINT8 temp = 0;

	if (atpIndex >= TEL_AT_CMD_ATP_36)
    {
        if (isAtpBindSim(atpIndex - TEL_AT_CMD_ATP_36))
        {
        	temp = getBindSimId(atpIndex - TEL_AT_CMD_ATP_36);
        }
        else if ( atpIndex == AT_MODEM_CHANNLE_1 && isDualUsbModem())
        {
            temp = SIM2;
        }
        else
        {
            temp = SIMID_NUM;
        }
    }
    else
    {
        if (isAtpBindSim(atpIndex))
        {
        	temp = getBindSimId(atpIndex);
        }
        else if ( atpIndex == AT_MODEM_CHANNLE && isDualUsbModem())
        {
            temp = SIM1;
        }
        else
        {
            temp = SIMID_NUM;
        }
    }

	if (temp == SIM2)
	{
		//Fitz.xu 20211220: To fix BZASR-2319, Coverity scan error CID=4262104
		CPUartLogPrintf("%s,%d,atp_%d is bind to SIM2", __func__, __LINE__, atpIndex);
		return TRUE;	
	}
	else
	{
		return FALSE;
	}
}

void quec_send_qdsim_response(bool is_success)
{
	if (is_success)
	{
		ATRESP(g_atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	}
	else
	{
		ATRESP(g_atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);	
	}
}
#endif

#endif /*MIN_SYS*/

