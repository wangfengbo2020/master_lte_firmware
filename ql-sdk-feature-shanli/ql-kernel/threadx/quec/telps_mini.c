/******************************************************************************

*(C) Copyright 2007 Marvell International Ltd.

* All Rights Reserved

******************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 *	INTEL CONFIDENTIAL
 *	Copyright 2006 Intel Corporation All Rights Reserved.
 *	The source code contained or described herein and all documents related to the source code (揗aterial? are owned
 *	by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
 *	its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
 *	Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
 *	treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
 *	transmitted, distributed, or disclosed in any way without Intel抯 prior express written permission.
 *
 *	No license under any patent, copyright, trade secret or other intellectual property right is granted to or
 *	conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
 *	estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
 *	Intel in writing.
 *	-------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: telps.c
 *
 *  Authors:  Rovin Yu
 *
 *  Description: Process packet switched service related AT commands
 *
 *  History:
 *   Feb 18, 2008 - Creation of file
 *
 *  Notes:
 *
 ******************************************************************************/

/******************************************************************************
 *   include files
 ******************************************************************************/
#include "ci_api_types.h"
#include "ci_api_client.h"
#include "teldef.h"
#include "telutl.h"
#include "telatparamdef.h"
#include "ci_ps.h"
#include "telatci.h"
#include "ps_api.h"
#include "telps.h"
#ifdef LWIP_IPNETBUF_SUPPORT
#include "connect_management.h"
#include "psm_wrapper.h"
#endif

#include "quec_atcmd_general.h"
#include "quec_atcmd_network.h"
#include "quec_debug.h"
#include "quec_urc.h"
#include "quec_net.h"
#if QUEC_DUAL_SIM_SUPPORT
#include "quec_atcmd_sim.h"
#endif

#if defined QUECTEL_PROJECT_CUST
extern quec_pdpauthinfo_type quec_pdpauthinfo;
#endif

#ifdef QUECTEL_NETWORK_SUPPORT
#define Network_Info_Log(msg, ...)  custom_log("NETWORK_INFO", msg, ##__VA_ARGS__)
extern bool quec_pdpindex_isfull(UINT32 atHandle,uint8 cid);
#define QUEC_PDP_CONTEX_INDEX_MAX 16   //Chaim 20200529  follow 1802s max pdp context num

#ifndef MIN_SYS

extern int quec_net_set_pdp_profile(int pdp_cid, quec_pdp_profile  *profile_info);
extern int quec_net_get_pdp_profile(int pdp_cid, quec_pdp_profile  *profile_info);
#endif
extern int updatePdpProfileCmdInPsm(UINT32 atHandle,INT32 iCid, const char *pParaString, UINT8 byUpdateFlag);
extern void handle_dial(int atp_index);
extern UINT32	gUpdateAuthParamCmdInPsmFlag;
extern int updateAuthParamCmdInPsm(UINT32 atHandle,INT32 iCid, const char *pParaString, UINT8 byUpdateFlag);

#endif
#ifdef QUEC_MINI_SYSTEM_SUPPORT
#if QUEC_DUAL_SIM_SUPPORT
extern CiPsNwRegInfo quec_cgreg_info[2];
extern CiPs4GNwRegInfo quec_cereg_info[2];
extern BOOL quec_get_default_flag(uint8 simid);
#else		
extern CiPsNwRegInfo quec_cgreg_info;
extern CiPs4GNwRegInfo quec_cereg_info;
#endif
#endif
extern BOOL  searchListByCid(unsigned char cid, DIRECTIPCONFIGLIST ** ppBuf);

extern char gPdpErrCauseBuf[];
extern char gPdpErrCauseBuf_1[];

extern int gIPv6_AddressFormat;
extern int gIPv6_AddressFormat_1;
extern int gIPv6_SubnetNotation;
extern int gIPv6_SubnetNotation_1;
extern int gIPv6_LeadingZeros;
extern int gIPv6_LeadingZeros_1;
extern int gIPv6_CompressZeros;
extern int gIPv6_CompressZeros_1;
extern int subnetmask_Str2Len(char* mask);
extern int subnetmask_str2len(char* mask);
extern int strcasecmp(const char *s1, const char *s2);

#ifdef LWIP_IPNETBUF_SUPPORT
extern void setWanMtu(int simID, int mtu);
extern int getWanMtu(int simID);
extern BOOL cmuxIsAtpIndexForNetAT(UINT32 sAtpIndex);
#endif

static char *strsep(char **stringp, const char *delim)
{
	char *s=NULL;
	const char *spanp=NULL;
	int c=0, sc=0;
	char *tok=NULL;
	if ((s=*stringp)==NULL)
			return (NULL);
	for(tok =s;;){
		c = *s++;
		spanp =delim;
		do{
			if((sc=*spanp++)==c){
				if (c ==0)
					s =NULL;
				else
					s[-1]=0;
				*stringp = s;
				return (tok);
				}
			}while(sc !=0);
		}

}

bool ConvertStrAddress2hexaddr (CiPsPdpAddr_convert *input)
{
  UINT8 *start_p=NULL, *end_p=NULL, i=0;
  //[klockwork][issue id: 3786]
  UINT32  tmpVal[255] = {0};
  BOOL success = FALSE;
  UINT8  count = 0;

  start_p = input->valData;
  end_p = input->valData;

  for(i = 0; i < 128; i++)
  {
  	 /*have checked the terminal char*/
	 /*coverity[overrun-local]*/
     if(*(start_p+i) == '.')
        count++;
     else if(*(start_p+i) == '\0')
        break;
  }

  DIAG_FILTER(PCAC,CI,ConvertStrAddress2hexaddr_1,DIAG_INFORMATION)
  diagPrintf("dot count:%d,addr & submask:%s",count,(const char *)start_p);

  //uart_printf("dot count:%d,addr & submask:%s\r\n",count,(const char *)start_p);



  for (i = 0; i < count + 1; i++) /* LoopForeverCatch */
  {
    tmpVal[i] = strtoul ((const char *)start_p, (char **)&end_p, 10);

	//uart_printf("strtoul out,i:%d,value: %d,nd_P:%d\r\n",i,tmpVal[i] ,*end_p);
    if (tmpVal[i] > 255)
    {
      break;
    }

    if (i == (count))
    {
      if (*end_p == '\0')
      {
        success = TRUE;
      }
    }
    else if (*end_p != '.')
    {
      break;
    }
    else
    {
      start_p = end_p + 1;
    }
  }
  //uart_printf("strtoul_2 ,will set the converted  iput value:sucees:%d\r\n",success );

  if (success)
  {
    memset (input->valData, 0, CI_PS_PDP_IP_V6_SIZE);
	//[klockwork][issue id: 3786]
    for (i = 0; i < count + 1 && i< CI_PS_PDP_IP_V6_SIZE; i++) /* LoopForeverCatch */
    {
      input->valData[i] = (UINT8)tmpVal[i];
      input->len = count + 1;
    }
  }
  //DIAG_FILTER(PCAC,CI,ConvertStrAddress2hexaddr_2,DIAG_INFORMATION)
  //diagPrintf("len :%d,result:%d",input->len,success);

  return (success);
}

bool convertBinStrToDecInt(UINT8 *binStr, UINT32 *outDec)
{
	UINT8 index;
	UINT32 output=0;
	INT32 len = strlen((char *)binStr);
	for(index=0; index<len; index++)
	{
		if((binStr[index]=='1') ||(binStr[index]=='0'))
		{
			output = output*2+binStr[index]-'0';
		}
		else
		{
			//DIAG_FILTER(PCAC,CI,convertBinStrToDecInt_FAIL,DIAG_INFORMATION)
  			//diagPrintf("binStr :%s,len %d, output:0x%lx, index %d",binStr,len,output,index);
			return FALSE;
		}
	}

	DIAG_FILTER(PCAC,CI,convertBinStrToDecInt_PASS,DIAG_INFORMATION)
    diagPrintf("binStr :%s,output:0x%lx",binStr,output);

	*outDec = output;
	return TRUE;


}

#ifdef LWIP_IPNETBUF_SUPPORT
UINT8 getMultiPdpSameApnFlag(void)
{
	/*customer can change the default value*/
	UINT8 flag = 0xFF;
	char *str = psm_get_wrapper("wan", NULL, "multi_pdp_same_apn");

	if (str)
	{
		flag = atoi(str);
		free(str);
	}

	//ATDBGMSG(atcmdsrv,276,"%s: get flag %d", __func__, flag);
	return flag;
}

void setMultiPdpSameApnFlag(UINT8 flag)
{
	CHAR buf[4]  = {0};

	sprintf(buf, "%d", flag);

	psm_set_wrapper("wan", NULL, "multi_pdp_same_apn", buf);

	CPUartLogPrintf("%s: set flag %s", __func__, buf);
}
#endif

/************************************************************************************
 *
 * PS related AT commands
 *
 *************************************************************************************/

//#ifndef LTEONLY_THIN
/************************************************************************************
 * F@: ciPSRegStatus - GLOBAL API for GCF AT+CGREG -command
 *
 */
RETURNCODE_T  ciPSRegStatus(            const utlAtParameterOp_T        op,
										const char                      *command_name_p,
										const utlAtParameterValue_P2c   parameter_values_p,
										const size_t                    num_parameters,
										const char                      *info_text_p,
										unsigned int                    *xid_p,
										void                            *arg_p)
{

	CiReturnCode						ret = CIRC_FAIL;
	RETURNCODE_T						rc = INITIAL_RETURN_CODE;
	INT32								cgreg=0;
	UINT32 atHandle = MAKE_AT_HANDLE( * (TelAtParserID *) arg_p );
	
	*xid_p = atHandle;
	

	DBGMSG("ciPSRegStatus: atHandle = %d, op=%d", atHandle, op);
#ifdef QUEC_MINI_SYSTEM_SUPPORT
	if(!IsMiniSystem()) 
	{
		#ifndef MIN_SYS
		RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
        char resBuf[200];
	    UINT32 atp_index=GET_ATP_INDEX(atHandle);
	    int reg_status=0;
	    int net_status=0;
		char lac_buf[LANDI_VAL_BUF_MAX] = {0};
#ifdef __QUEC_OEM_VER_LD__
	    char cid_buf[LANDI_VAL_BUF_MAX] = {0};
#endif
		
#if QUEC_DUAL_SIM_SUPPORT
		CiPsNwRegInfo *p_quec_cgreg_info = &quec_cgreg_info[isMasterSim0() ? SIM1 : SIM2];
		CiPs4GNwRegInfo *p_quec_cereg_info = &quec_cereg_info[isMasterSim0() ? SIM1 : SIM2];
#else
		CiPsNwRegInfo *p_quec_cgreg_info = &quec_cgreg_info;
		CiPs4GNwRegInfo *p_quec_cereg_info = &quec_cereg_info;
#endif

	    CPUartLogPrintf("%s,%d,command type=%d,atp_index=%d",__FUNCTION__,__LINE__,op,atp_index);
#ifdef LTEONLY_THIN
		/* 
			The cgreg ci req should not be sent in lte only(cnf has been cropped in psCnf):

			#ifndef LTEONLY_THIN
				case CI_PS_PRIM_GET_NW_REG_STATUS_CNF:  //AT+CGREG?
				case CI_PS_PRIM_ENABLE_NW_REG_IND_CNF:  //AT+CGREG=
			#endif
			
			So the cgreg cache is always used here.
		*/
		uint8_t is_lte_only = 1;
		CPUartLogPrintf("is_lte_only:%d",is_lte_only);
		if(is_lte_only)
#else
	    if(QUEC_IS_VALID_ATP(atp_index))//when AT\PPP\UART channel, we handle it as quectel function, else if it is virtual at channel, still go with ASR function like query param of network with at cmd
#endif
	    {
	        switch (op)
	        {
	            case TEL_EXT_TEST_CMD:
	                {   
	                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+CGREG: (0-2)\r\n");
	                    break;
	                }    
	            case TEL_EXT_GET_CMD: 
	                {
	                    quectel_current_config_value_get(AT_CGREG,&reg_status);
						net_status=quec_regstatus_asr2quec(p_quec_cgreg_info->status, 1);
	                    if(p_quec_cgreg_info->status !=0)
	                    {    
	                        if(reg_status==0 || reg_status==1)
	                        {
	                             sprintf( resBuf,"+CGREG: %d,%d\r\n",reg_status,net_status);
	                        }
	                        else 
	                        {    
	                            if(p_quec_cgreg_info->lacPresent &&(net_status == 1 || net_status == 5))
	                            {   
	                            	GET_VALID_VAL(lac_buf, p_quec_cgreg_info->lac);
	       							#ifdef __QUEC_OEM_VER_LD__  
	        						if (TRUE == Quectel_IsOEMLandiEnable())
	        						{
	            						GET_VALID_VAL(lac_buf, p_quec_cgreg_info->lac);
										GET_VALID_VAL(cid_buf, p_quec_cgreg_info->cellId);
										sprintf( resBuf,"+CGREG: %d,%d,\"%s\",\"%s\",%d\r\n",reg_status,net_status,lac_buf,cid_buf,quec_act_asr2quec(p_quec_cgreg_info->act));
	        						}
				        			else
									#endif
				        			{
										sprintf( resBuf,"+CGREG: %d,%d,\"%04X\",\"%04X\",%d\r\n",reg_status,net_status,p_quec_cgreg_info->lac,p_quec_cgreg_info->cellId,quec_act_asr2quec(p_quec_cgreg_info->act));
				       				}
	                            }
	                            else
	                            {
	                               CPUartLogPrintf("%s,%d,LAC/TAC not present",__FUNCTION__,__LINE__);
	                               sprintf( resBuf,"+CGREG: %d,%d\r\n",reg_status,net_status);
	                            }
	                        }
	                    }
	                    else
	                    {	
	                    	net_status=quec_regstatus_asr2quec(p_quec_cereg_info->status, 1);
	                        if(reg_status==0 || reg_status==1)
	                        {
	                             sprintf( resBuf,"+CGREG: %d,%d\r\n",reg_status,net_status);
	                        }
	                        else 
	                        {    
	                            if(p_quec_cereg_info->tacPresent &&(net_status == 1 || net_status == 5))
	                            {    
	                            	#ifdef __QUEC_OEM_VER_LD__  
	        						if (TRUE == Quectel_IsOEMLandiEnable())
	        						{
	            						GET_VALID_VAL(lac_buf, p_quec_cereg_info->tac);
										GET_VALID_VAL(cid_buf, p_quec_cereg_info->cellId);
										sprintf( resBuf,"+CGREG: %d,%d,\"%s\",\"%s\",%d\r\n",reg_status,net_status,lac_buf,cid_buf,quec_act_asr2quec(p_quec_cereg_info->act));
	        						}
				        			else
									#endif
				        			{
										sprintf( resBuf,"+CGREG: %d,%d,\"%04X\",\"%04X\",%d\r\n",reg_status,net_status,p_quec_cereg_info->tac,p_quec_cereg_info->cellId,quec_act_asr2quec(p_quec_cereg_info->act));
				       				}
	                            }
	                            else
	                            {
	                               CPUartLogPrintf("%s,%d,LAC/TAC not present",__FUNCTION__,__LINE__);
	                               sprintf( resBuf,"+CGREG: %d,%d\r\n",reg_status,net_status);
	                            }
	                        }
	                    }
	                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
	                    break;
	                }
	            case TEL_EXT_SET_CMD:
	                {
	                    if((getExtValue(parameter_values_p, 0, &reg_status, 0, 2, 0) == TRUE) 
	                        && (quectel_current_config_value_set(AT_CGREG,reg_status)==utlSUCCESS))
	                    {
	                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	                    }
	                    else
	                    {
	                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
	                    }
	                    break;
	                        
	                }
	            case TEL_EXT_ACTION_CMD:
	            default:
	                {
	                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
	                    break;
	                }
	     
	        }
	        rc = HANDLE_RETURN_VALUE(ret); 
	        return(rc);
	    }
	    else
	    {
			#ifdef QUEC_MINI_SYSTEM_SUPPORT  //avoid recrusion
	        switch (op)
			{
				case TEL_EXT_TEST_CMD:    /* AT+CGREG=? */
				{
					ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,(char *)"+CGREG: (0-2)\r\n");

					break;
				}
				case TEL_EXT_GET_CMD:    /* AT+CGREG?  */
				{
					#if defined(CRANE_MCU_DONGLE) && defined(PPP_ENABLE)
					char rsp[MAX_STRING_LEN] = { 0 };
					if (get_cgreg_status_rsp(* (TelAtParserID *) arg_p , rsp, 1) == 0)
						ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK, 0, (char *)rsp);
					else
					#endif
					ret = PS_GetGPRSRegStatus(atHandle);
					break;
				}
				case TEL_EXT_SET_CMD:   /* AT+CGREG=  */
				{
					/*
					 **  Parse the state variable.
					 */
					if( getExtValue(parameter_values_p, 0, (int *)&cgreg, TEL_AT_CGREG_MODE_0_N_VAL_MIN, TEL_AT_CGREG_MODE_0_N_VAL_MAX, TEL_AT_CGREG_MODE_0_N_VAL_DEFAULT) == TRUE )
					{
						ret = PS_SetGPRSRegStatus(atHandle, (UINT32)cgreg);
					}
					else
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
					break;
				}
				case TEL_EXT_ACTION_CMD:   /* AT+CGREG   */
				default:
				{
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
					break;
				}
			}
			#else //Chaim 2020.11.21 Caution: Recursion
				return ciPSRegStatus(op, command_name_p, parameter_values_p, num_parameters,info_text_p,xid_p,arg_p);
			#endif
	    }
		#endif
	}
	else
#endif
	{
		switch (op)
		{
			case TEL_EXT_TEST_CMD:    /* AT+CGREG=? */
			{
				ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,(char *)"+CGREG: (0-2)\r\n");

				break;
			}
			case TEL_EXT_GET_CMD:    /* AT+CGREG?  */
			{
				#if defined(CRANE_MCU_DONGLE) && defined(PPP_ENABLE)
				char rsp[MAX_STRING_LEN] = { 0 };
				if (get_cgreg_status_rsp(* (TelAtParserID *) arg_p , rsp, 1) == 0)
					ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK, 0, (char *)rsp);
				else
				#endif
				ret = PS_GetGPRSRegStatus(atHandle);
				break;
			}
			case TEL_EXT_SET_CMD:   /* AT+CGREG=  */
			{
				/*
				 **  Parse the state variable.
				 */
				if( getExtValue(parameter_values_p, 0, (int *)&cgreg, TEL_AT_CGREG_MODE_0_N_VAL_MIN, TEL_AT_CGREG_MODE_0_N_VAL_MAX, TEL_AT_CGREG_MODE_0_N_VAL_DEFAULT) == TRUE )
				{
					ret = PS_SetGPRSRegStatus(atHandle, (UINT32)cgreg);
				}
				else
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}
			case TEL_EXT_ACTION_CMD:   /* AT+CGREG   */
			default:
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
				break;
			}
		}
	}
	CPUartLogPrintf("%s,%d,psregstatus end",__FUNCTION__,__LINE__);

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);

}
//#endif

/************************************************************************************
 * F@: ciERegStatus - GLOBAL API for GCF AT+CEREG  -command
 *
 */
RETURNCODE_T  ciERegStatus(const utlAtParameterOp_T op,
    const char                      *command_name_p,
    const utlAtParameterValue_P2c   parameter_values_p,
    const size_t                    num_parameters,
    const char                      *info_text_p,
    unsigned int                    *xid_p,
    void                            *arg_p)
{
    RETURNCODE_T    rc = INITIAL_RETURN_CODE;
    CiReturnCode    ret = CIRC_FAIL;
    UINT32          atHandle = MAKE_AT_HANDLE(* (TelAtParserID *) arg_p);

    *xid_p = atHandle;

	#ifndef MIN_SYS
    //#ifdef QUEC_MINI_SYSTEM_SUPPORT
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
    if((QUEC_IS_VALID_ATP(atp_index))&&(!IsMiniSystem()))
     {
	 	
        char resBuf[200];
        UINT8 reg_status=0;
        UINT8 net_status=0;
    
#ifdef __QUEC_OEM_VER_LD__
        char tac_buf[LANDI_VAL_BUF_MAX] = {0};
        char cid_buf[LANDI_VAL_BUF_MAX] = {0};
#endif
#if QUEC_DUAL_SIM_SUPPORT
		CiPs4GNwRegInfo *p_quec_cereg_info = &quec_cereg_info[isMasterSim0() ? SIM1 : SIM2];
#else
		CiPs4GNwRegInfo *p_quec_cereg_info = &quec_cereg_info;
#endif

        DBGMSG("command type=%d,atp_index=%d",op,atp_index);
       //when AT\PPP\UART channel, we handle it as quectel function, else if it is virtual at channel, still go with ASR function like query param of network with at cmd
            switch (op)
            {
                case TEL_EXT_TEST_CMD:
                    {   
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+CEREG: (0-2)\r\n");
                        break;
                    }    
                case TEL_EXT_GET_CMD: 
                    {
                        quectel_current_config_value_get(AT_CEREG,(int *)&reg_status);
                        net_status=quec_regstatus_asr2quec(p_quec_cereg_info->status, 1);
                        if(reg_status==0 || reg_status==1)
                        {
                             sprintf( resBuf,"+CEREG: %d,%d\r\n",reg_status,net_status);
                        }
                        else 
                        {    
                            if(p_quec_cereg_info->tacPresent &&(net_status == 1 || net_status == 5))
                            {    
						#ifdef __QUEC_OEM_VER_LD__  
                                if (TRUE == Quectel_IsOEMLandiEnable())
                                {
                                    GET_VALID_VAL(tac_buf, p_quec_cereg_info->tac);
                                    GET_VALID_VAL(cid_buf, p_quec_cereg_info->cellId);
                                    sprintf( resBuf,"+CEREG: %d,%d,\"%s\",\"%s\",%d\r\n",reg_status,net_status,tac_buf,cid_buf,quec_act_asr2quec(p_quec_cereg_info->act));
                                }
                                else
						#endif
                                {
                                    sprintf( resBuf,"+CEREG: %d,%d,\"%04X\",\"%04X\",%d\r\n",reg_status,net_status,p_quec_cereg_info->tac,p_quec_cereg_info->cellId,quec_act_asr2quec(p_quec_cereg_info->act));
                                }
                            }
                            else
                            {
                               DBGMSG("TAC not present");
                               sprintf( resBuf,"+CEREG: %d,%d\r\n",reg_status,net_status);
                            }
                        }
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
                        break;
                    }
                case TEL_EXT_SET_CMD:
                    {
                        if((getExtValue(parameter_values_p, 0, (int *)&reg_status, 0, 2, 0) == TRUE) 
                            && (quectel_current_config_value_set(AT_CEREG,reg_status)==utlSUCCESS))
                        {
                            ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                        }
                        else
                        {
                            ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                        }
                        break;
                            
                    }
                case TEL_EXT_ACTION_CMD:
                default:
                    {
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                        break;
                    }
         
            }
            rc = HANDLE_RETURN_VALUE(ret); 
            return(rc);
   }
    else
    #endif
    /*
         **  Check the operation type.
         */
  {
    switch( op )
    {
        case TEL_EXT_TEST_CMD:    /* AT+CEREG=? */
        {
            char tmpBuf[100];
			memset(tmpBuf, 0, sizeof(tmpBuf));

			sprintf((char *)tmpBuf, "+CEREG: (0-5)\r\n");

            ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)tmpBuf);
            break;
        }

        case TEL_EXT_GET_CMD:     /* AT+CEREG? */
        {
		#if defined(CRANE_MCU_DONGLE) && defined(PPP_ENABLE)
		char rsp[MAX_STRING_LEN] = { 0 };
		if (get_cgreg_status_rsp(* (TelAtParserID *) arg_p , rsp, 2) == 0)
		ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK, 0, (char *)rsp);
		else
		#endif
		ret = PS_Get4GRegStatus(atHandle);
		break;
        }

        case TEL_EXT_SET_CMD:     /* AT+CEREG= */
        {
            INT32  regParam;

            if ( getExtValue( parameter_values_p, 0, (int *)&regParam, TEL_AT_CEREG_0_MODE_VAL_MIN, TEL_AT_CEREG_0_MODE_VAL_MAX, TEL_AT_CEREG_0_MODE_VAL_DEFAULT) == TRUE )
			{
                ret = PS_Set4GRegOption(atHandle, regParam);
            }
            else
            {
                ret = ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_OPERATION_NOT_SUPPORTED,NULL);
            }

            break;
        }

        case TEL_EXT_ACTION_CMD:     /* AT+CREG */
        default:
        {
            ret = ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_OPERATION_NOT_SUPPORTED,NULL);
            break;
        }
    }

    /* handle the return value */
    rc = HANDLE_RETURN_VALUE(ret);
    return(rc);
  }
}


/************************************************************************************
 * F@: ciSetContext - GLOBAL API for GCF AT+CGDCONT -command
 *
 */
RETURNCODE_T  ciSetContext(            const utlAtParameterOp_T        op,
									   const char                      *command_name_p,
									   const utlAtParameterValue_P2c   parameter_values_p,
									   const size_t                    num_parameters,
									   const char                      *info_text_p,
									   unsigned int                    *xid_p,
									   void                            *arg_p)
{
	RETURNCODE_T rc = INITIAL_RETURN_CODE;
	CiReturnCode ret = CIRC_FAIL;
	INT32 primCid=0;
	CHAR tmpStr[TEL_AT_CGDCONT_1_PDPTYPE_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH] = "";
	INT16 tmpStrLen = 0;
	UINT8 addrLen = 0;
	INT32 tmpParam = 0;
	CiPsPdpCtx pdpCtxInfo;
	UINT32 atHandle = MAKE_AT_HANDLE( *(TelAtParserID *)arg_p );
	CiPsPdpAddr_convert pdp_addr;
#ifdef LWIP_IPNETBUF_SUPPORT
	telPsPdpApn       pdpApnInfo = {0};
    telPsPdpOpt       pdpOpt = {0};
#endif
#ifdef QUECTEL_NETWORK_SUPPORT
	int ret_status =0;
#endif


#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
#ifdef QUECTEL_NETWORK_SUPPORT
	char *pAtCmdStr = NULL; //connor
	char *p_sub = NULL;
	char *p_total = NULL;
	char PdpProfileName[20]={0};
	char tmpAtRspBuf[CI_PS_MAX_CID*QUEC_MAX_CGDCONT_LEN]={0};//connor
	char SubBuf[QUEC_MAX_CGDCONT_LEN]={0};
	char SubBuf_temp[QUEC_MAX_CGDCONT_LEN]={0};
	UINT8 i=0;
	UINT8 j=0;
	UINT8 param_count=0;
	UINT8 len=0;
	TelAtParserID sAtpIndex=GET_ATP_INDEX(atHandle);
	//UINT8 actual_id =1;
	UINT8 k=0;
#endif
#ifdef QUECTEL_PDP_CONTEXT_RETURN_FORMAT_ERROR_FIX
		quec_pdp_type_e_t pdp_type = QUECTEL_PDP_TYPE_MIN;
#endif

#if QUEC_DUAL_SIM_SUPPORT
	char cid_start = 0;
	char cid_end = 0;
#endif

	*xid_p = atHandle;

	DBGMSG("ciSetContext: atHandle = %d, op=%d", atHandle, op);

	memset(&pdpCtxInfo, 0, sizeof(pdpCtxInfo));
	memset(&pdp_addr, 0, sizeof(pdp_addr));
#ifdef LWIP_IPNETBUF_SUPPORT
	memset(&pdpApnInfo, 0, sizeof(pdpApnInfo));
	memset(&pdpOpt, 0, sizeof(pdpOpt));
#endif

	switch(op)
	{
		case TEL_EXT_GET_CMD:	 /* AT+CGDCONT?  */
		{
#ifdef QUECTEL_NETWORK_SUPPORT
			if ((QUEC_IS_VALID_ATP(sAtpIndex)) 
				#ifdef PPP_ENABLE
				&& (!need_ppp_process_at_response(sAtpIndex))
				#endif
				)
			{
				p_total=tmpAtRspBuf;
				#if QUEC_DUAL_SIM_SUPPORT
				#ifndef MIN_SYS
					if (!IsMiniSystem()) 
					{//MiniSystem
						if (getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)
						{
							cid_start = 1;
							#if QUEC_DUAL_SIM_SUPPORT
								//sharon.li@20220524
								//双卡单待的模式，cid 可以大于8;但是单张卡最多同时激活8路pdp
								//双卡双待或者双卡双待单通的模式下，限制卡1 cid 必须在1~4；卡2cid 必须在5~8；不能超过8。
								cid_end = QUEC_PDP_CONTEX_INDEX_MAX; 
							#else
								cid_end = 8; 
							#endif
						}
						else if ((getDualSimType() == CM_DUAL_SIM_DUAL_STANDBY) || (getDualSimType() == CM_DUAL_SIM_DUAL_STANDBY_FP))
						{
							if ((sAtpIndex < 36) || quec_is_atp_bind_sim1(sAtpIndex))
							{
								cid_start = 1;
								cid_end = 4;	
							}
							else if ((sAtpIndex >= 36) || quec_is_atp_bind_sim2(sAtpIndex))
							{
								cid_start = 5;
								cid_end = 8;	
							}
						}
					}//MiniSystem
				#endif /*MIN_SYS*/
				#endif

			#if QUEC_DUAL_SIM_SUPPORT
				for( i = cid_start; i <= cid_end; i++)
			#else
				//for( i = 1; i <= CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM; i++)  //Chaim 20200109 note large than 16
				for( i = 1; i <= QUEC_PDP_CONTEX_INDEX_MAX; i++)
			#endif
				{		
					memset(PdpProfileName,0,sizeof(PdpProfileName));					
					sprintf(PdpProfileName, "Profile%d", i); //connor
					pAtCmdStr = psm_get_wrapper(PSM_MOD_WAN, "cellular", PdpProfileName);
					#if 0
					do
					{
						sprintf(PdpProfileName, "Profile%d", actual_id);
						actual_id++;
						pAtCmdStr = psm_get_wrapper(PSM_MOD_WAN, "cellular", PdpProfileName);
						if(pAtCmdStr !=NULL && strlen(pAtCmdStr) != 0)
						{
							Network_Info_Log("actual_id =%d not found",actual_id);
							break;
						}
					}while(actual_id<QUEC_PDP_CONTEX_INDEX_MAX);
					#endif

					if(pAtCmdStr !=NULL && strlen(pAtCmdStr) != 0)
					{
						memset(SubBuf,0,sizeof(SubBuf));
						memset(SubBuf_temp,0,sizeof(SubBuf_temp));
						param_count=0;
						p_sub=SubBuf_temp;
						sprintf(SubBuf, "%s", pAtCmdStr);//AT+CGDCONT=CID,"IPTYPE","apn",,,,...
						len = strlen(SubBuf);
						Network_Info_Log("SubBuf =%s,len=%d",SubBuf,len);
						#ifdef QUECTEL_PDP_CONTEXT_RETURN_FORMAT_ERROR_FIX
						pdp_type = quec_get_pdp_type(SubBuf);
						#endif
						#if defined QUEC_CODECHECK_MODIFICATION_ASR
						if(i != 1 && (0 != strlen(tmpAtRspBuf))) // byron.zhou-2021/11/18:When tmpAtRspBuf is NULL,Don't copy "\r\n" to p_sub.Avoid line breaks when the first line is empty.
						{
							p_sub+=sprintf(p_sub, "\r\n"); //we need to input /r/n at the second item
						}
						#else
						if(i != 1)
						{
							p_sub+=sprintf(p_sub, "\r\n"); //we need to input /r/n at the second item
						}
						#endif
						for(j=2;j< len;j++) //SKIP AT so begain at third para
						{
							Network_Info_Log("SubBuf[%d] = %c",j,SubBuf[j]);

							if(SubBuf[j] == '=' ) //replace witch : 
							{
								p_sub+=sprintf(p_sub, ": ");
								continue;
							}

							if(SubBuf[j] == '\r'  || SubBuf[j] == '\n') //the end is /r/n we need to jump it 
							{
								continue;
							}
							p_sub+=sprintf(p_sub, "%c",SubBuf[j]);
							
							if(SubBuf[j] == ',' )
							{
								param_count++;
							}

							if(SubBuf[j] == '"' &&	SubBuf[j+1] == '"' && param_count==1) //if the IP type is null we use the default IP
							{
								p_sub+=sprintf(p_sub, "IP");
								#ifdef QUECTEL_PDP_CONTEXT_RETURN_FORMAT_ERROR_FIX
								pdp_type = QUECTEL_PDP_IP;
								#endif
							}

							if(SubBuf[j] == '"' &&	SubBuf[j+1] == '"' && param_count==3) //if the IP addrr is null we use the default 
							{
								#ifdef QUECTEL_PDP_CONTEXT_RETURN_FORMAT_ERROR_FIX
								if (QUECTEL_PDP_IP == pdp_type)
								{
									p_sub+=sprintf(p_sub, "0.0.0.0"); 
								}
								else
								{
									p_sub+=sprintf(p_sub, "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0");
								}
								#else
								p_sub+=sprintf(p_sub, "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0");
								#endif
							}
							
							//we need to add the default para when it is set ,, or the last char customer input is ,
							if((j+1<len && SubBuf[j] == ',' &&	SubBuf[j+1] == ',') || (j == len-2 && SubBuf[j] ==',') ) //len-2 is because the last is /r/n
							{
								switch(param_count)
								{
								   case 1:
									   p_sub+=sprintf(p_sub, "\"IP\"");
									   break;
								   case 2:
									   p_sub+=sprintf(p_sub, "\"\"");
									   break;
								   case 3:
										#ifdef QUECTEL_PDP_CONTEXT_RETURN_FORMAT_ERROR_FIX
									   if (QUECTEL_PDP_IP == pdp_type)
									   {
											p_sub+=sprintf(p_sub, "\"0.0.0.0\"");
									   }
									   else
									   {
											p_sub+=sprintf(p_sub, "\"0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0\"");
									   }	
									   #else
									   p_sub+=sprintf(p_sub, "\"0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0\"");
									   #endif
									   break;
								   case 4:
									   p_sub+=sprintf(p_sub, "0");
									   break;
								   case 5:
									   p_sub+=sprintf(p_sub, "0");
									   break;
								   case 6:
									   p_sub+=sprintf(p_sub, "0");
									   break;
								   case 7:
									   p_sub+=sprintf(p_sub, "0");
									   break;
								   case 8:
									   p_sub+=sprintf(p_sub, "0");
									   break;
								   case 9:
									   p_sub+=sprintf(p_sub, "0");
									   break;
								   default:
									   ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
									   goto invalid;
									}
							}
		
						}
						Network_Info_Log("param_count =%d",param_count);
						switch(param_count)
						{
						   case 1:
#ifdef QUECTEL_PDP_CONTEXT_RETURN_FORMAT_ERROR_FIX
								if (QUECTEL_PDP_IP == pdp_type)
								{
									p_sub+=sprintf(p_sub, ",\"\",\"0.0.0.0\",0,0,0,0,0,0"); 
								}
								else 
								{
									p_sub+=sprintf(p_sub, ",\"\",\"0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0\",0,0,0,0,0,0");
								}														 
#else
							   p_sub+=sprintf(p_sub, ",\"\",\"0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0\",0,0,0,0,0,0");
#endif
							   break;
						   case 2:
								#ifdef QUECTEL_PDP_CONTEXT_RETURN_FORMAT_ERROR_FIX
								if (QUECTEL_PDP_IP == pdp_type)
								{
									p_sub+=sprintf(p_sub, ",\"0.0.0.0\",0,0,0,0,0,0"); 
								}
								else 
								{
									p_sub+=sprintf(p_sub, ",\"0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0\",0,0,0,0,0,0");
								}														 
								#else
							   p_sub+=sprintf(p_sub, ",\"0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0\",0,0,0,0,0,0");
								#endif
							   break;
						   case 3:
							   p_sub+=sprintf(p_sub, ",0,0,0,0,0,0");
							   break;
						   case 4:
							   p_sub+=sprintf(p_sub, ",0,0,0,0,0");
							   break;
						   case 5:
							   p_sub+=sprintf(p_sub, ",0,0,0,0");
							   break;
						   case 6:
							   p_sub+=sprintf(p_sub, ",0,0,0");
							   break;
						   case 7:
							   p_sub+=sprintf(p_sub, ",0,0");
							   break;
						   case 8:
							   p_sub+=sprintf(p_sub, ",0");
							   break;
						   case 9:
							   break;
						   default:
							   ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
							   goto invalid;
						}
						
						p_total+=sprintf(p_total, "%s", SubBuf_temp);
						duster_free(pAtCmdStr);  //Chaim 2019.04.16 reslove memory leak
					   
					}
                    #ifdef QUECTEL_PROJECT_CUST
                    else
                    {
                       if(pAtCmdStr !=NULL)
                       {
                           duster_free(pAtCmdStr);      
                       }
   
                    }
                    #endif
				}
				if(strlen(tmpAtRspBuf) !=0)
				{
					ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,(char *)tmpAtRspBuf);
				}
				else
				{
					ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,(char *)"+CGDCONT: ");
				}
			}
			else
			{
				ret = PS_GetGPRSContextList(atHandle);
			}
#else
			ret = PS_GetGPRSContextList(atHandle);
#endif
			break;
		}
		case TEL_EXT_TEST_CMD:	  /* AT+CGDCONT=? */
		{
			#ifdef QUECTEL_NETWORK_SUPPORT	
			char tmpAtRspBuf[400];
			sprintf ( tmpAtRspBuf,"+CGDCONT: (%d-%d),\"IP\",,,(0-%d),(0-%d),(0,%d),(0,%d),(0-%d),(0,%d)"
					  "\r\n+CGDCONT: (%d-%d),\"PPP\",,,(0-%d),(0-%d),(0,%d),(0,%d),(0-%d),(0,%d)"
					  "\r\n+CGDCONT: (%d-%d),\"IPV6\",,,(0-%d),(0-%d),(0,%d),(0,%d),(0-%d),(0,%d)"
					  "\r\n+CGDCONT: (%d-%d),\"IPV4V6\",,,(0-%d),(0-%d),(0,%d),(0,%d),(0-%d),(0,%d)\r\n"
					  
					  ,(int)TEL_AT_CGDCONT_0_CID_VAL_MIN+1,(int)CI_PS_MAX_PDP_CTX_NUM,(int)TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, (int)TEL_AT_CGDCONT_5_HCOMP_VAL_MAX,(int)TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX,(int)QUEC_TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX,(int)TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX,(int)TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX
					  ,(int)TEL_AT_CGDCONT_0_CID_VAL_MIN+1,(int)CI_PS_MAX_PDP_CTX_NUM,(int)TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, (int)TEL_AT_CGDCONT_5_HCOMP_VAL_MAX,(int)TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX,(int)QUEC_TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX,(int)TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX,(int)TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX
					  ,(int)TEL_AT_CGDCONT_0_CID_VAL_MIN+1,(int)CI_PS_MAX_PDP_CTX_NUM,(int)TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, (int)TEL_AT_CGDCONT_5_HCOMP_VAL_MAX,(int)TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX,(int)QUEC_TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX,(int)TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX,(int)TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX
					  ,(int)TEL_AT_CGDCONT_0_CID_VAL_MIN+1,(int)CI_PS_MAX_PDP_CTX_NUM,(int)TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, (int)TEL_AT_CGDCONT_5_HCOMP_VAL_MAX,(int)TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX,(int)QUEC_TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX,(int)TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX,(int)TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX);
					ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,(char *)tmpAtRspBuf);
					break;
			#else
			/* for every PDP type */
			sprintf ( tmpAtRspBuf,"+CGDCONT: (%d-%d),\"IP\",,,(0-%d),(0-%d),(0,%d),(0,%d),(0-%d),(0,%d)\r\n"
					  "\r\n+CGDCONT: (%d-%d),\"IPV6\",,,(0-%d),(0-%d),(0,%d),(0,%d),(0-%d),(0,%d)\r\n"
					  "\r\n+CGDCONT: (%d-%d),\"IPV4V6\",,,(0-%d),(0-%d),(0,%d),(0,%d),(0-%d),(0,%d)\r\n"
					  "\r\n+CGDCONT: (%d-%d),\"PPP\",,,(0-%d),(0-%d),(0,%d),(0,%d),(0-%d),(0,%d)"
					  ,(int)TEL_AT_CGDCONT_0_CID_VAL_MIN,(int)TEL_AT_CGDCONT_0_CID_VAL_MAX,(int)TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, (int)TEL_AT_CGDCONT_5_HCOMP_VAL_MAX,(int)TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX,(int)TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX,(int)TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX,(int)TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX
					  ,(int)TEL_AT_CGDCONT_0_CID_VAL_MIN,(int)TEL_AT_CGDCONT_0_CID_VAL_MAX,(int)TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, (int)TEL_AT_CGDCONT_5_HCOMP_VAL_MAX,(int)TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX,(int)TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX,(int)TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX,(int)TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX
					  ,(int)TEL_AT_CGDCONT_0_CID_VAL_MIN,(int)TEL_AT_CGDCONT_0_CID_VAL_MAX,(int)TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, (int)TEL_AT_CGDCONT_5_HCOMP_VAL_MAX,(int)TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX,(int)TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX,(int)TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX,(int)TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX
					  ,(int)TEL_AT_CGDCONT_0_CID_VAL_MIN,(int)TEL_AT_CGDCONT_0_CID_VAL_MAX,(int)TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, (int)TEL_AT_CGDCONT_5_HCOMP_VAL_MAX,(int)TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX,(int)TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX,(int)TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX,(int)TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX);
					ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,(char *)tmpAtRspBuf);
					break;
			#endif								
		}

		case TEL_EXT_SET_CMD:	   /* AT+CGDCONT= */
		{
			memset(&pdpCtxInfo, 0, sizeof(pdpCtxInfo));
			/* 1  Extract the arguments starting with the CID. */
			if ( getExtValue( parameter_values_p, 0, (int *)&primCid, TEL_AT_CGDCONT_0_CID_VAL_MIN, TEL_AT_CGDCONT_0_CID_VAL_MAX, TEL_AT_CGDCONT_0_CID_VAL_DEFAULT ) != TRUE )
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			//Fitz.xu 20211016: For DSDS, cid1-4 for SIM1, cid5-8 for SIM2.
			#if QUEC_DUAL_SIM_SUPPORT
			#ifndef MIN_SYS
			if (!IsMiniSystem()) 
			{//MiniSystem
			#ifdef QUEC_PPP_INTERNAL_CHANNEL_HANDLE_AT_RESP
    			  if ((QUEC_IS_VALID_ATP(sAtpIndex)||(sAtpIndex==TEL_AT_CMD_ATP_APPTCPIP_SIM1)||(sAtpIndex==TEL_AT_CMD_ATP_APPTCPIP_SIM2)||
                    (sAtpIndex==TEL_AT_CMD_ATP_PPP_INTERNAL_SIM1)||(sAtpIndex==TEL_AT_CMD_ATP_PPP_INTERNAL_SIM2))
                    &&(primCid>CI_PS_MAX_PDP_CTX_NUM))//1606不支持cid8以上，禁止客户输入；ASR IMS call临时cid可以正常配置
                 {         
    				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
    				break;
                 }
             #endif
				{
					CPUartLogPrintf("%s,%d,SimType=%d, primCid=%d, isMasterSim0=%d", __func__, __LINE__, getDualSimType(), primCid, isMasterSim0());

					if ((getDualSimType() == CM_DUAL_SIM_DUAL_STANDBY) || (getDualSimType() == CM_DUAL_SIM_DUAL_STANDBY_FP))
					{
						if ((sAtpIndex < TEL_AT_CMD_ATP_36) || quec_is_atp_bind_sim1(sAtpIndex))
						{
							if (primCid > 4)
							{
								ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
								break;	
							}
						}
						else if ((sAtpIndex < NUM_OF_TEL_ATP) || quec_is_atp_bind_sim2(sAtpIndex))
						{
							if ((primCid < 5)&&(!((quec_get_default_flag(1)==TRUE)&&(primCid==1))))//若是双卡双待向双卡单待切，SIM2通道可以配置cid1
							{
								ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
								break;	
							}	
						}
					}
				}
			}//MiniSystem
			#endif /*MIN_SYS*/
			#endif
			
			if (( primCid > 0 ) && ( primCid <= CI_PS_MAX_CID ))
			{
				/* CI - SAC use cid range starting from 0 */
				primCid--;
				pdpCtxInfo.cid = primCid;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* If only the CID is included, we should undefine this PDP Context */
			if ( parameter_values_p[1].is_default && parameter_values_p[2].is_default && parameter_values_p[3].is_default
					&& parameter_values_p[4].is_default && parameter_values_p[5].is_default )
			{
			#ifdef QUECTEL_NETWORK_SUPPORT
				if(1 == quec_pdp_act_state[primCid].pdp_act_status)
				{	
					CPUartLogPrintf("%s,%d,princid=%d is active,can not delete",__func__,__LINE__,primCid);
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
					break;		
				}
			#endif
			
#ifdef LWIP_IPNETBUF_SUPPORT
				//telSetPdpCtxApn(primCid, &pdpApnInfo);
				telSetPdpCtxApnDS(atHandle, primCid, &pdpApnInfo);
				//telSetPdpCtxOpt(primCid, &pdpOpt);
				telSetPdpCtxOptDS(atHandle, primCid, &pdpOpt);
#endif
				ret = PS_DeleteGPRSContext(atHandle, primCid);
#ifdef QUECTEL_NETWORK_SUPPORT
				updatePdpProfileCmdInPsm(atHandle,primCid+1, NULL, 0); //Redmine#1331
#endif
				break;
			}

			/* 2.  Determine the PDP type.	   */
			if ( getExtString( parameter_values_p, 1, tmpStr, TEL_AT_CGDCONT_1_PDPTYPE_STR_MAX_LEN, &tmpStrLen, (CHAR *)TEL_AT_CGDCONT_1_PDPTYPE_STR_DEFAULT) == TRUE )
			{
				if ( tmpStrLen == 0 )
				{
					/* default value */
					pdpCtxInfo.type = CI_PS_PDP_TYPE_IP;
				}
				else
				{
#ifdef QUECTEL_AT_COMMAND
					if (strcasecmp("IP", (char *)tmpStr) == 0)
						pdpCtxInfo.type = CI_PS_PDP_TYPE_IP;
					else if (strcasecmp("IPV6", (char *)tmpStr) == 0)
						pdpCtxInfo.type = CI_PS_PDP_TYPE_IPV6;
					else if (strcasecmp("IPV4V6", (char *)tmpStr) == 0)
						pdpCtxInfo.type = CI_PS_PDP_TYPE_IPV4V6;
					else if (strcasecmp("PPP", (char *)tmpStr) == 0)
#else
					if ( (strcmp("IP", (char *)tmpStr) == 0) || (strcmp("ip", (char *)tmpStr) == 0) )
						pdpCtxInfo.type = CI_PS_PDP_TYPE_IP;
					else if ( (strcmp("IPV6", (char *)tmpStr) == 0) || (strcmp("ipv6", (char *)tmpStr) == 0) )
						pdpCtxInfo.type = CI_PS_PDP_TYPE_IPV6;
					else if ( (strcmp("IPV4V6", (char *)tmpStr) == 0) || (strcmp("ipv4v6", (char *)tmpStr) == 0) )
						pdpCtxInfo.type = CI_PS_PDP_TYPE_IPV4V6;
					else if ( (strcmp("PPP", (char *)tmpStr) == 0) || (strcmp("ppp", (char *)tmpStr) == 0) )

#endif
						pdpCtxInfo.type = CI_PS_PDP_TYPE_PPP;
					else
					{			 /* default to IP */
						//pdpCtxInfo.type = CI_PS_PDP_TYPE_IP;
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
						break;
					}
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/*	 ** 3 Assign the APN string.				 */
			if ( getExtString(parameter_values_p, 2, tmpStr, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN, &tmpStrLen, TEL_AT_CGDCONT_2_APN_STR_DEFAULT) == TRUE )
			{
				if ( tmpStrLen != 0 )
				{
					//20200703
				#ifdef QUEC_APN_COMMA_BUG
					if(strstr(tmpStr,",")!=NULL)
					{
						//?????í??????
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
						break;
					}
				#endif
					pdpCtxInfo.apnPresent = TRUE;
					pdpCtxInfo.apn.len = tmpStrLen;
					memcpy( pdpCtxInfo.apn.valStr, tmpStr, tmpStrLen );
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}
			/* 4.  Extract the PDP Address. 				*/
			if ( getExtString( parameter_values_p, 3, tmpStr, TEL_AT_CGDCONT_3_PDPADDRESS_STR_MAX_LEN, &tmpStrLen, TEL_AT_CGDCONT_3_PDPADDRESS_STR_DEFAULT) == TRUE )
			{
				DBGMSG("[%s] Line(%d): got getExtString returned TRUE for addrPtr. tmpStrLen(%d) \n", __FUNCTION__, __LINE__, tmpStrLen);
				UINT8 j=0;
				if ( tmpStrLen != 0 )
				{
					if(pdpCtxInfo.type == CI_PS_PDP_TYPE_IP)
					{
						pdpCtxInfo.ipv4Addr.addrType= CI_PS_PDP_TYPE_IP;
						pdpCtxInfo.ipv4Addr.subnetLength = 0;
						addrLen = tmpStrLen < CI_PS_PDP_IP_V4_SIZE ? tmpStrLen : (CI_PS_PDP_IP_V4_SIZE - 1);
						memcpy(pdp_addr.valData, tmpStr, addrLen);
						pdp_addr.valData[addrLen] = 0;
						DBGMSG("[%s] Line(%d): pdp_addr.valData(%s) \n", __FUNCTION__, __LINE__, pdp_addr.valData);
						ConvertStrAddress2hexaddr(&pdp_addr);
						memcpy(pdpCtxInfo.ipv4Addr.valData, pdp_addr.valData, pdp_addr.len);
					}
					else if(pdpCtxInfo.type == CI_PS_PDP_TYPE_IPV6)
					{
						pdpCtxInfo.ipv6Addr.addrType = CI_PS_PDP_FULL_IPV6;
						pdpCtxInfo.ipv6Addr.subnetLength = 0;
						addrLen = tmpStrLen < CI_PS_PDP_IP_V6_SIZE ? tmpStrLen : (CI_PS_PDP_IP_V6_SIZE - 1);
						memcpy(pdp_addr.valData, tmpStr, addrLen);
						pdp_addr.valData[addrLen] = 0;
						DBGMSG("[%s] Line(%d): pdp_addr.valData(%s) \n", __FUNCTION__, __LINE__, pdp_addr.valData);
						ConvertStrAddress2hexaddr(&pdp_addr);
						memcpy(pdpCtxInfo.ipv6Addr.valData, pdp_addr.valData, pdp_addr.len);
					}
					else if(pdpCtxInfo.type == CI_PS_PDP_TYPE_IPV4V6)
					{
						char* ipaddr = (char* )tmpStr;
						char* ipp4;
						char* ipp6;

						pdpCtxInfo.ipv4Addr.addrType= CI_PS_PDP_TYPE_IP;
						pdpCtxInfo.ipv4Addr.subnetLength = 0;
						ipp4 = strsep(&ipaddr, " ");
						addrLen = strlen(ipp4) < CI_PS_PDP_IP_V4_SIZE ? strlen(ipp4) : (CI_PS_PDP_IP_V4_SIZE - 1);
						memcpy(pdp_addr.valData, ipp4, addrLen);
						pdp_addr.valData[addrLen] = 0;
						DBGMSG("[%s] Line(%d): pdp_addr.valData(%s) \n", __FUNCTION__, __LINE__, pdp_addr.valData);
						ConvertStrAddress2hexaddr(&pdp_addr);
						memcpy(pdpCtxInfo.ipv4Addr.valData, pdp_addr.valData, pdp_addr.len);

						ipp6 = (char* )ipaddr;
						pdpCtxInfo.ipv6Addr.addrType = CI_PS_PDP_FULL_IPV6;
						pdpCtxInfo.ipv6Addr.subnetLength = 0;
						/*mischecked by klocwork*/
						/*klocwork[Result of function that may return NULL will be dereferenced]*/
						addrLen = strlen(ipp6) < CI_PS_PDP_IP_V6_SIZE ? strlen(ipp6) : (CI_PS_PDP_IP_V6_SIZE - 1);
						memcpy(pdp_addr.valData, ipp6, addrLen);
						pdp_addr.valData[addrLen] = 0;
						DBGMSG("[%s] Line(%d): pdp_addr.valData(%s) \n", __FUNCTION__, __LINE__, pdp_addr.valData);
						ConvertStrAddress2hexaddr(&pdp_addr);
						memcpy(pdpCtxInfo.ipv6Addr.valData, pdp_addr.valData, pdp_addr.len);
					}

				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}
			/* 5.	Now get the D_COMP. 		 */
			if ( getExtValue(parameter_values_p, 4, (int *)&tmpParam, TEL_AT_CGDCONT_4_DCOMP_VAL_MIN, TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, TEL_AT_CGDCONT_4_DCOMP_VAL_DEFAULT) == TRUE )
			{
				if(parameter_values_p[4].is_default == TRUE)
				{
					pdpCtxInfo.dcompPresent = FALSE;
				}
				else
				{
					pdpCtxInfo.dcompPresent = TRUE;
					switch ( tmpParam )
					{

						case ATCI_PS_DCOMP_ON:
						{
							pdpCtxInfo.dcomp = CI_PS_DCOMP_ON;
							break;
						}
						case ATCI_PS_DCOMP_V42bis: // ONLY SUPPORT V42bis.
						{
							pdpCtxInfo.dcomp = CI_PS_DCOMP_V42bis;
							break;
						}
						case ATCI_PS_DCOMP_OFF:
						{
							pdpCtxInfo.dcomp = CI_PS_DCOMP_OFF;
							break;
						}
						default:
						{
							ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
							goto invalid;
						}
					}
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}
			/*	   6. Now get the H_COMP.	  */
			if ( getExtValue(parameter_values_p, 5, (int *)&tmpParam, TEL_AT_CGDCONT_5_HCOMP_VAL_MIN, TEL_AT_CGDCONT_5_HCOMP_VAL_MAX, TEL_AT_CGDCONT_5_HCOMP_VAL_DEFAULT) == TRUE )
			{

				if(parameter_values_p[5].is_default == TRUE)
				{
					pdpCtxInfo.hcompPresent = FALSE;
				}
				else
				{
					pdpCtxInfo.hcompPresent = TRUE;
					switch ( tmpParam )
					{
						case ATCI_PS_HCOMP_TCPIP:
						{
							pdpCtxInfo.hcomp = CI_PS_HCOMP_TCPIP;
							break;
						}
						case ATCI_PS_HCOMP_IP:
						{
							pdpCtxInfo.hcomp = CI_PS_HCOMP_IP;
							break;
						}
						case ATCI_PS_HCOMP_OFF:
						{
							pdpCtxInfo.hcomp = CI_PS_HCOMP_OFF;
							break;
						}
						default:
						{
							ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
							goto invalid;
						}
					}
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/*	   ** 7 IPv4AddrAlloc . 				*/
			if(getExtValue(parameter_values_p, 6, (int *)&tmpParam, TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MIN, TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX, TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_DEFAULT) == TRUE)
			{
				if(parameter_values_p[6].is_default == TRUE)
				{
					pdpCtxInfo.ipAddrAllocPresent = FALSE;
				}else
				{
					pdpCtxInfo.ipAddrAllocPresent = TRUE;
					pdpCtxInfo.ipAddrAlloc = tmpParam;
				}

			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/*	   ** 8 request type				  */
			if(getExtValue(parameter_values_p, 7, (int *)&tmpParam, TEL_AT_CGDCONT_7_REQTYPE_VAL_MIN, TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX, TEL_AT_CGDCONT_7_REQTYPE_VAL_DEFAULT) == TRUE)
			{

				if(parameter_values_p[7].is_default == TRUE)
				{
					pdpCtxInfo.reqTypePresent = FALSE;
				}
				else
				{
					pdpCtxInfo.reqTypePresent = TRUE;
					pdpCtxInfo.reqType = tmpParam;
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/*	   ** 9 pCscfDiscovery				   */
			if(getExtValue(parameter_values_p, 8, (int *)&tmpParam, TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MIN, TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX, TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_DEFAULT) == TRUE)
			{
				if(parameter_values_p[8].is_default == TRUE)
				{
					pdpCtxInfo.pCscfDiscoveryPresent= FALSE;
				}else
				{
					pdpCtxInfo.pCscfDiscoveryPresent= TRUE;
					pdpCtxInfo.pCscfDiscovery= tmpParam;
				}

			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/*	   ** 10 imCnSignallingFlagInd				*/
			if(getExtValue(parameter_values_p, 9, (int *)&tmpParam, TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MIN, TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX, TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_DEFAULT) == TRUE)
			{
				if(parameter_values_p[9].is_default == TRUE)
				{
					pdpCtxInfo.imCnSignallingFlagIndPresent= FALSE;
				}
				else
				{
					pdpCtxInfo.imCnSignallingFlagIndPresent= TRUE;
					pdpCtxInfo.imCnSignallingFlagInd= tmpParam;
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}
		#ifdef QUECTEL_NETWORK_SUPPORT
					if(TRUE == quec_pdpindex_isfull(atHandle,primCid+1))
					{
						CPUartLogPrintf("%s,%d,cgdcont is full,return error",__func__,__LINE__);
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_MEMORY_FAILURE, 0);
						break;	
					}
		#endif

#ifdef LWIP_IPNETBUF_SUPPORT
			if (cmuxIsAtpIndexForNetAT(* (TelAtParserID *) arg_p))
			{
			#if  defined(CRANE_MCU_DONGLE) && defined(PPP_ENABLE)
				if (isHandleForMasterSim(atHandle))
					ppp_clear_use_eps_apn(GET_ATP_INDEX(atHandle));
			#endif
			}

			if (pdpCtxInfo.apnPresent)
			{
				memcpy(pdpApnInfo.apn, pdpCtxInfo.apn.valStr, pdpCtxInfo.apn.len);
				pdpApnInfo.apn[pdpCtxInfo.apn.len] = '\0';

				pdpCtxInfo.apn.valStr[pdpCtxInfo.apn.len] = '\0';
#if defined(CRANE_MCU_DONGLE) && defined(PPP_ENABLE)
				ppp_store_configure_params(* (TelAtParserID *) arg_p, primCid, pdpCtxInfo.apn.valStr, pdpCtxInfo.type);
#endif
			}
			else
			{
#if  defined(CRANE_MCU_DONGLE) && defined(PPP_ENABLE)
				ppp_store_configure_params(* (TelAtParserID *) arg_p, primCid, NULL, pdpCtxInfo.type);
#endif
			}
//CPUartLogPrintf("chaim_test,%s,%d,CRANE_MODULE_SUPPORT=%d,PPP_ENABLE=%d",__func__,__LINE__,CRANE_MCU_DONGLE,PPP_ENABLE);

			pdpApnInfo.ipType = pdpCtxInfo.type;
			pdpApnInfo.defined = TRUE;
			copyCiPdpCtx2Opt(&pdpOpt, &pdpCtxInfo);

			/*redefined the APN info*/
			telSetPdpCtxApnDS(atHandle, primCid, &pdpApnInfo);
			
			telSetPdpCtxOptDS(atHandle, primCid, &pdpOpt);
			
#endif
#ifdef QUECTEL_NETWORK_SUPPORT
			
			ret_status = updatePdpProfileCmdInPsm(atHandle,primCid+1, info_text_p, 1);
			Network_Info_Log("primCid=%d ,info_text_p =%s,ret=%d",primCid+1,info_text_p,ret_status);
			if(-1 == ret_status)
			{
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			}
			else if(1 ==ret_status) //param is same we do not need to update to modem
			{
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				ret = PS_SetGPRSContext (atHandle, &pdpCtxInfo);
			}
#else
			ret = PS_SetGPRSContext(atHandle, &pdpCtxInfo);
#endif

			break;
		}

		case TEL_EXT_ACTION_CMD:   /* AT+CGDCONT */
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
			break;
	}
}//MiniSystem
else
{
	*xid_p = atHandle;

	DBGMSG("ciSetContext: atHandle = %d, op=%d", atHandle, op);

	memset(&pdpCtxInfo, 0, sizeof(pdpCtxInfo));
	memset(&pdp_addr, 0, sizeof(pdp_addr));
#ifdef LWIP_IPNETBUF_SUPPORT
	memset(&pdpApnInfo, 0, sizeof(pdpApnInfo));
	memset(&pdpOpt, 0, sizeof(pdpOpt));
#endif

	switch(op)
	{
		case TEL_EXT_GET_CMD:    /* AT+CGDCONT?  */
		{
			ret = PS_GetGPRSContextList(atHandle);
			break;
		}
		case TEL_EXT_TEST_CMD:	  /* AT+CGDCONT=? */
		{
			char tmpAtRspBuf[400];
			/* for every PDP type */
			sprintf ( tmpAtRspBuf,"+CGDCONT: (%d-%d),\"IP\",,,(0-%d),(0-%d),(0,%d),(0,%d),(0-%d),(0,%d)\r\n"
					  "\r\n+CGDCONT: (%d-%d),\"IPV6\",,,(0-%d),(0-%d),(0,%d),(0,%d),(0-%d),(0,%d)\r\n"
					  "\r\n+CGDCONT: (%d-%d),\"IPV4V6\",,,(0-%d),(0-%d),(0,%d),(0,%d),(0-%d),(0,%d)"
					  ,(int)TEL_AT_CGDCONT_0_CID_VAL_MIN,(int)TEL_AT_CGDCONT_0_CID_VAL_MAX,(int)TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, (int)TEL_AT_CGDCONT_5_HCOMP_VAL_MAX,(int)TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX,(int)TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX,(int)TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX,(int)TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX
					  ,(int)TEL_AT_CGDCONT_0_CID_VAL_MIN,(int)TEL_AT_CGDCONT_0_CID_VAL_MAX,(int)TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, (int)TEL_AT_CGDCONT_5_HCOMP_VAL_MAX,(int)TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX,(int)TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX,(int)TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX,(int)TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX
					  ,(int)TEL_AT_CGDCONT_0_CID_VAL_MIN,(int)TEL_AT_CGDCONT_0_CID_VAL_MAX,(int)TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, (int)TEL_AT_CGDCONT_5_HCOMP_VAL_MAX,(int)TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX,(int)TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX,(int)TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX,(int)TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX);
					ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,(char *)tmpAtRspBuf);
					break;
		}

		case TEL_EXT_SET_CMD:      /* AT+CGDCONT= */
		{
			memset(&pdpCtxInfo, 0, sizeof(pdpCtxInfo));

			/* 1  Extract the arguments starting with the CID. */
			if ( getExtValue( parameter_values_p, 0, (int *)&primCid, TEL_AT_CGDCONT_0_CID_VAL_MIN, TEL_AT_CGDCONT_0_CID_VAL_MAX, TEL_AT_CGDCONT_0_CID_VAL_DEFAULT ) != TRUE )
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			if (( primCid > 0 ) && ( primCid <= CI_PS_MAX_CID ))
			{
				/* CI - SAC use cid range starting from 0 */
				primCid--;
				pdpCtxInfo.cid = primCid;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* If only the CID is included, we should undefine this PDP Context */
			if ( parameter_values_p[1].is_default && parameter_values_p[2].is_default && parameter_values_p[3].is_default
					&& parameter_values_p[4].is_default && parameter_values_p[5].is_default )
			{
#ifdef LWIP_IPNETBUF_SUPPORT
				//telSetPdpCtxApn(primCid, &pdpApnInfo);
				telSetPdpCtxApnDS(atHandle, primCid, &pdpApnInfo);
				//telSetPdpCtxOpt(primCid, &pdpOpt);
				telSetPdpCtxOptDS(atHandle, primCid, &pdpOpt);
#endif
				ret = PS_DeleteGPRSContext(atHandle, primCid);
				break;
			}

			/* 2.  Determine the PDP type.     */
			if ( getExtString( parameter_values_p, 1, tmpStr, TEL_AT_CGDCONT_1_PDPTYPE_STR_MAX_LEN, &tmpStrLen, (CHAR *)TEL_AT_CGDCONT_1_PDPTYPE_STR_DEFAULT) == TRUE )
			{
				if ( tmpStrLen == 0 )
				{
					/* default value */
					pdpCtxInfo.type = CI_PS_PDP_TYPE_IP;
				}
				else
				{
					if ( (strcmp("IP", (char *)tmpStr) == 0) || (strcmp("ip", (char *)tmpStr) == 0) )
						pdpCtxInfo.type = CI_PS_PDP_TYPE_IP;
					else if ( (strcmp("IPV6", (char *)tmpStr) == 0) || (strcmp("ipv6", (char *)tmpStr) == 0) )
						pdpCtxInfo.type = CI_PS_PDP_TYPE_IPV6;
	                else if ( (strcmp("IPV4V6", (char *)tmpStr) == 0) || (strcmp("ipv4v6", (char *)tmpStr) == 0) )
						pdpCtxInfo.type = CI_PS_PDP_TYPE_IPV4V6;
					else
					{            /* default to IP */
						//pdpCtxInfo.type = CI_PS_PDP_TYPE_IP;
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
						break;
					}
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/*	 ** 3 Assign the APN string.				 */
			if ( getExtString(parameter_values_p, 2, tmpStr, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN, &tmpStrLen, TEL_AT_CGDCONT_2_APN_STR_DEFAULT) == TRUE )
			{
				if ( tmpStrLen != 0 )
				{
					pdpCtxInfo.apnPresent = TRUE;
					pdpCtxInfo.apn.len = tmpStrLen;
					memcpy( pdpCtxInfo.apn.valStr, tmpStr, tmpStrLen );
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}
			/* 4.  Extract the PDP Address.                 */
			if ( getExtString( parameter_values_p, 3, tmpStr, TEL_AT_CGDCONT_3_PDPADDRESS_STR_MAX_LEN, &tmpStrLen, TEL_AT_CGDCONT_3_PDPADDRESS_STR_DEFAULT) == TRUE )
			{
				DBGMSG("[%s] Line(%d): got getExtString returned TRUE for addrPtr. tmpStrLen(%d) \n", __FUNCTION__, __LINE__, tmpStrLen);
				UINT8 j=0;
				if ( tmpStrLen != 0 )
				{
					if(pdpCtxInfo.type == CI_PS_PDP_TYPE_IP)
					{
						pdpCtxInfo.ipv4Addr.addrType= CI_PS_PDP_TYPE_IP;
						pdpCtxInfo.ipv4Addr.subnetLength = 0;
						addrLen = tmpStrLen < CI_PS_PDP_IP_V4_SIZE ? tmpStrLen : (CI_PS_PDP_IP_V4_SIZE - 1);
						memcpy(pdp_addr.valData, tmpStr, addrLen);
						pdp_addr.valData[addrLen] = 0;
						DBGMSG("[%s] Line(%d): pdp_addr.valData(%s) \n", __FUNCTION__, __LINE__, pdp_addr.valData);
						ConvertStrAddress2hexaddr(&pdp_addr);
						memcpy(pdpCtxInfo.ipv4Addr.valData, pdp_addr.valData, pdp_addr.len);
					}
					else if(pdpCtxInfo.type == CI_PS_PDP_TYPE_IPV6)
					{
						pdpCtxInfo.ipv6Addr.addrType = CI_PS_PDP_FULL_IPV6;
						pdpCtxInfo.ipv6Addr.subnetLength = 0;
						addrLen = tmpStrLen < CI_PS_PDP_IP_V6_SIZE ? tmpStrLen : (CI_PS_PDP_IP_V6_SIZE - 1);
						memcpy(pdp_addr.valData, tmpStr, addrLen);
						pdp_addr.valData[addrLen] = 0;
						DBGMSG("[%s] Line(%d): pdp_addr.valData(%s) \n", __FUNCTION__, __LINE__, pdp_addr.valData);
						ConvertStrAddress2hexaddr(&pdp_addr);
						memcpy(pdpCtxInfo.ipv6Addr.valData, pdp_addr.valData, pdp_addr.len);
					}
					else if(pdpCtxInfo.type == CI_PS_PDP_TYPE_IPV4V6)
					{
						char* ipaddr = (char* )tmpStr;
						char* ipp4;
						char* ipp6;

						pdpCtxInfo.ipv4Addr.addrType= CI_PS_PDP_TYPE_IP;
						pdpCtxInfo.ipv4Addr.subnetLength = 0;
						ipp4 = strsep(&ipaddr, " ");
						addrLen = strlen(ipp4) < CI_PS_PDP_IP_V4_SIZE ? strlen(ipp4) : (CI_PS_PDP_IP_V4_SIZE - 1);
						memcpy(pdp_addr.valData, ipp4, addrLen);
						pdp_addr.valData[addrLen] = 0;
						DBGMSG("[%s] Line(%d): pdp_addr.valData(%s) \n", __FUNCTION__, __LINE__, pdp_addr.valData);
						ConvertStrAddress2hexaddr(&pdp_addr);
						memcpy(pdpCtxInfo.ipv4Addr.valData, pdp_addr.valData, pdp_addr.len);

						ipp6 = (char* )ipaddr;
						pdpCtxInfo.ipv6Addr.addrType = CI_PS_PDP_FULL_IPV6;
						pdpCtxInfo.ipv6Addr.subnetLength = 0;
						/*mischecked by klocwork*/
						/*klocwork[Result of function that may return NULL will be dereferenced]*/
						addrLen = strlen(ipp6) < CI_PS_PDP_IP_V6_SIZE ? strlen(ipp6) : (CI_PS_PDP_IP_V6_SIZE - 1);
						memcpy(pdp_addr.valData, ipp6, addrLen);
						pdp_addr.valData[addrLen] = 0;
						DBGMSG("[%s] Line(%d): pdp_addr.valData(%s) \n", __FUNCTION__, __LINE__, pdp_addr.valData);
						ConvertStrAddress2hexaddr(&pdp_addr);
						memcpy(pdpCtxInfo.ipv6Addr.valData, pdp_addr.valData, pdp_addr.len);
					}

				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}
			/* 5.   Now get the D_COMP.			 */
			if ( getExtValue(parameter_values_p, 4, (int *)&tmpParam, TEL_AT_CGDCONT_4_DCOMP_VAL_MIN, TEL_AT_CGDCONT_4_DCOMP_VAL_MAX, TEL_AT_CGDCONT_4_DCOMP_VAL_DEFAULT) == TRUE )
			{
				if(parameter_values_p[4].is_default == TRUE)
				{
					pdpCtxInfo.dcompPresent = FALSE;
				}
				else
				{
					pdpCtxInfo.dcompPresent = TRUE;
					switch ( tmpParam )
					{

						case ATCI_PS_DCOMP_ON:
						{
							pdpCtxInfo.dcomp = CI_PS_DCOMP_ON;
							break;
						}
						case ATCI_PS_DCOMP_V42bis: // ONLY SUPPORT V42bis.
						{
							pdpCtxInfo.dcomp = CI_PS_DCOMP_V42bis;
							break;
						}
						case ATCI_PS_DCOMP_OFF:
						{
							pdpCtxInfo.dcomp = CI_PS_DCOMP_OFF;
							break;
						}
						default:
						{
							ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
							goto invalid;
						}
					}
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}
			/*     6. Now get the H_COMP.     */
			if ( getExtValue(parameter_values_p, 5, (int *)&tmpParam, TEL_AT_CGDCONT_5_HCOMP_VAL_MIN, TEL_AT_CGDCONT_5_HCOMP_VAL_MAX, TEL_AT_CGDCONT_5_HCOMP_VAL_DEFAULT) == TRUE )
			{

				if(parameter_values_p[5].is_default == TRUE)
				{
					pdpCtxInfo.hcompPresent = FALSE;
				}
				else
				{
					pdpCtxInfo.hcompPresent = TRUE;
					switch ( tmpParam )
					{
						case ATCI_PS_HCOMP_TCPIP:
						{
							pdpCtxInfo.hcomp = CI_PS_HCOMP_TCPIP;
							break;
						}
						case ATCI_PS_HCOMP_IP:
						{
							pdpCtxInfo.hcomp = CI_PS_HCOMP_IP;
							break;
						}
						case ATCI_PS_HCOMP_OFF:
						{
							pdpCtxInfo.hcomp = CI_PS_HCOMP_OFF;
							break;
						}
						default:
						{
							ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
							goto invalid;
						}
					}
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/*	   ** 7 IPv4AddrAlloc . 				*/
			if(getExtValue(parameter_values_p, 6, (int *)&tmpParam, TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MIN, TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX, TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_DEFAULT) == TRUE)
			{
				if(parameter_values_p[6].is_default == TRUE)
				{
					pdpCtxInfo.ipAddrAllocPresent = FALSE;
				}else
				{
					pdpCtxInfo.ipAddrAllocPresent = TRUE;
			  		pdpCtxInfo.ipAddrAlloc = tmpParam;
				}

			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/*	   ** 8 request type				  */
			if(getExtValue(parameter_values_p, 7, (int *)&tmpParam, TEL_AT_CGDCONT_7_REQTYPE_VAL_MIN, TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX, TEL_AT_CGDCONT_7_REQTYPE_VAL_DEFAULT) == TRUE)
			{

				if(parameter_values_p[7].is_default == TRUE)
				{
					pdpCtxInfo.reqTypePresent = FALSE;
				}
				else
				{
					pdpCtxInfo.reqTypePresent = TRUE;
					pdpCtxInfo.reqType = tmpParam;
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/*	   ** 9 pCscfDiscovery				   */
			if(getExtValue(parameter_values_p, 8, (int *)&tmpParam, TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MIN, TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX, TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_DEFAULT) == TRUE)
			{
				if(parameter_values_p[8].is_default == TRUE)
				{
					pdpCtxInfo.pCscfDiscoveryPresent= FALSE;
				}else
				{
					pdpCtxInfo.pCscfDiscoveryPresent= TRUE;
			  		pdpCtxInfo.pCscfDiscovery= tmpParam;
				}

			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/*	   ** 10 imCnSignallingFlagInd				*/
			if(getExtValue(parameter_values_p, 9, (int *)&tmpParam, TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MIN, TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX, TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_DEFAULT) == TRUE)
			{
				if(parameter_values_p[9].is_default == TRUE)
				{
					pdpCtxInfo.imCnSignallingFlagIndPresent= FALSE;
				}
				else
				{
					pdpCtxInfo.imCnSignallingFlagIndPresent= TRUE;
					pdpCtxInfo.imCnSignallingFlagInd= tmpParam;
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

#ifdef LWIP_IPNETBUF_SUPPORT
			if (cmuxIsAtpIndexForNetAT(* (TelAtParserID *) arg_p))
			{
				#if  defined(CRANE_MCU_DONGLE) && defined(PPP_ENABLE)
				if (isHandleForMasterSim(atHandle))
					ppp_clear_use_eps_apn(GET_ATP_INDEX(atHandle));
				#endif
			}

			if (pdpCtxInfo.apnPresent)
			{
				memcpy(pdpApnInfo.apn, pdpCtxInfo.apn.valStr, pdpCtxInfo.apn.len);
				pdpApnInfo.apn[pdpCtxInfo.apn.len] = '\0';

				pdpCtxInfo.apn.valStr[pdpCtxInfo.apn.len] = '\0';
#if defined(CRANE_MCU_DONGLE) && defined(PPP_ENABLE)
				ppp_store_configure_params(* (TelAtParserID *) arg_p, primCid, pdpCtxInfo.apn.valStr, pdpCtxInfo.type);
#endif
			}
			else
			{
#if  defined(CRANE_MCU_DONGLE) && defined(PPP_ENABLE)
				ppp_store_configure_params(* (TelAtParserID *) arg_p, primCid, NULL, pdpCtxInfo.type);
#endif
			}

			pdpApnInfo.ipType = pdpCtxInfo.type;
			pdpApnInfo.defined = TRUE;
			copyCiPdpCtx2Opt(&pdpOpt, &pdpCtxInfo);

			/*redefined the APN info*/
			if ( isHandleForMasterSim(atHandle) &&
			     telSetPdpCtxApnDS(atHandle, primCid, &pdpApnInfo) == FALSE)
			{
			    ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
			    break;
			}
			    
			telSetPdpCtxOptDS(atHandle, primCid, &pdpOpt);
#endif

			ret = PS_SetGPRSContext(atHandle, &pdpCtxInfo);

			break;
		}

		case TEL_EXT_ACTION_CMD:   /* AT+CGDCONT */
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
			break;
	}
}
#endif /*MIN_SYS*/


invalid:
	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);

}


/************************************************************************************
 * F@: ciSetSContext - GLOBAL API for GCF AT+CGDSCONT -command
 *                     (define econdary PDP context)
 */
RETURNCODE_T  ciSetSContext(            const utlAtParameterOp_T        op,
										const char                      *command_name_p,
										const utlAtParameterValue_P2c   parameter_values_p,
										const size_t                    num_parameters,
										const char                      *info_text_p,
										unsigned int                    *xid_p,
										void                            *arg_p)
{

	RETURNCODE_T rc = INITIAL_RETURN_CODE;
	CiReturnCode ret = CIRC_FAIL;
	INT32 dCompPar=0;
	INT32 hCompPar=0;
	INT32 secCidPar=0;
	INT32 primCidPar=0;
	INT32 imCnSigFlag=0;
	CiPsSecPdpCtx secPdpContext;
	CiPsDcomp dcomp = 0;
	CiPsHcomp hcomp = 0;
	UINT32 atHandle = MAKE_AT_HANDLE( *(TelAtParserID *)arg_p );

	*xid_p = atHandle;

	memset(&secPdpContext, 0, sizeof(secPdpContext));

	DBGMSG("ciSetSContext: atHandle = %d, op=%d", atHandle, op);

	switch(op)
	{
		case TEL_EXT_GET_CMD:    /* AT+CGDSCONT?  */
		{
			ret = PS_GetSecondaryContextList(atHandle);
			break;
		}

		case TEL_EXT_TEST_CMD:    /* AT+CGDSCONT=? */
		{
			ret = PS_GetSecondaryContextRange(atHandle);
			break;
		}

		case TEL_EXT_SET_CMD:      /* AT+CGDSCONT= */
		{
			BOOL cmdValid = FALSE;
			/*
			 **  Extract the arguments starting with the CID.
			 */
			if( getExtValue(parameter_values_p, 0, (int *)&secCidPar, TEL_AT_CGDSCONT_0_CID_VAL_MIN, TEL_AT_CGDSCONT_0_CID_VAL_MAX, TEL_AT_CGDSCONT_0_CID_VAL_DEFAULT) == TRUE )
			{
			/* If only the second CID is included, it should undefine it */
			if (parameter_values_p[1].is_default && parameter_values_p[2].is_default && parameter_values_p[3].is_default)
			{
				cmdValid = TRUE;
				secCidPar--;
				ret = PS_DeleteSecondaryPDPContext(atHandle, secCidPar);
				break;
			}
			if ( getExtValue(parameter_values_p, 1, (int *)&primCidPar, TEL_AT_CGDSCONT_1_PCID_VAL_MIN, TEL_AT_CGDSCONT_1_PCID_VAL_MAX, TEL_AT_CGDSCONT_1_PCID_VAL_DEFAULT) == TRUE )
			{
				if ( getExtValue(parameter_values_p, 2, (int *)&dCompPar, TEL_AT_CGDSCONT_2_DCOMP_VAL_MIN, TEL_AT_CGDSCONT_2_DCOMP_VAL_MAX, TEL_AT_CGDSCONT_2_DCOMP_VAL_DEFAULT) == TRUE )
				{
					if ( getExtValue(parameter_values_p, 3, (int *)&hCompPar, TEL_AT_CGDSCONT_3_HCOMP_VAL_MIN, TEL_AT_CGDSCONT_3_HCOMP_VAL_MAX, TEL_AT_CGDSCONT_3_HCOMP_VAL_DEFAULT) == TRUE )
					{
						if ( getExtValue(parameter_values_p, 4, (int *)&imCnSigFlag, TEL_AT_CGDSCONT_4_IMCNSIGFLAG_VAL_MIN, TEL_AT_CGDSCONT_4_IMCNSIGFLAG_VAL_MAX, TEL_AT_CGDSCONT_4_IMCNSIGFLAG_VAL_DEFAULT) == TRUE )
						{
							/*
							 **  Check the CIDs range; the primary CID must exist;
							 **  the secondary CID must not exist
							 */
							if ( ( secCidPar <= CI_PS_MAX_CID) && (secCidPar > 0)
									&& ( primCidPar <= CI_PS_MAX_CID ) && (primCidPar > 0)
									&& ( primCidPar != secCidPar ))
							{
								cmdValid = TRUE;

								/* CI - SAC use cid range starting from 0 */
								secCidPar--;
								primCidPar--;

								switch ( dCompPar )
								{
									case ATCI_PS_DCOMP_OFF:
									case ATCI_DEFAULT_PARAM_VALUE:
										dcomp = CI_PS_DCOMP_OFF;
										break;

									case ATCI_PS_DCOMP_ON:
										dcomp = CI_PS_DCOMP_ON;
										break;

									case ATCI_PS_DCOMP_V42bis:
										dcomp = CI_PS_DCOMP_V42bis;
										break;

									default:
										ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL );
										goto invalid;
								}

								switch ( hCompPar )
								{
									case ATCI_PS_HCOMP_OFF:
									case ATCI_DEFAULT_PARAM_VALUE:
										hcomp = CI_PS_HCOMP_OFF;
										break;

									case ATCI_PS_HCOMP_TCPIP:
										hcomp = CI_PS_HCOMP_TCPIP;
										break;

									case ATCI_PS_HCOMP_IP:
										hcomp = CI_PS_HCOMP_IP;
										break;

									default:
										ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL );
										goto invalid;
								}

								secPdpContext.cid = secCidPar;
								secPdpContext.p_cid = primCidPar;
								secPdpContext.dcompPresent = TRUE;
								secPdpContext.dcomp = dcomp;
								secPdpContext.hcompPresent = TRUE;
								secPdpContext.hcomp = hcomp;
								secPdpContext.imCnSigFlagPresent = TRUE;
								secPdpContext.imCnSigFlag = imCnSigFlag;

								ret = PS_SetSecondaryPDPContext(atHandle, &secPdpContext);
							}   /* if ( cid <= MAX_NUMBER_OF_CIDS ) */
						}   /* if( getExtValue(parameter_values_p, X, &hCompPar,  */
					}   /* if( getExtValue(parameter_values_p, X, &dCompPar,  */
				}   /* if( getExtValue(parameter_values_p, X, &primCidPar,  */
			}   /* if( getExtValue(parameter_values_p, X, &secCidPar,  */
		}   /* if( getExtValue(parameter_values_p, X, &secCidPar,  */
		if(!cmdValid)
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL );
				break;
		}

		case TEL_EXT_ACTION_CMD:   /* AT+CGDSCONT */
		default:
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL );
			break;
	}

invalid:
	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);

}

/************************************************************************************
 * F@: ciPDPActivate - GLOBAL API for GCF AT+CGACT -command
 *
 */
RETURNCODE_T  ciPDPActivate(            const utlAtParameterOp_T        op,
										const char                      *command_name_p,
										const utlAtParameterValue_P2c   parameter_values_p,
										const size_t                    num_parameters,
										const char                      *info_text_p,
										unsigned int                    *xid_p,
										void                            *arg_p)
{
	RETURNCODE_T                          rc = INITIAL_RETURN_CODE;
	CiReturnCode                          ret = CIRC_FAIL;

	INT32                                 pdpState=0;
	INT32                                 cid=0;

	UINT32 atHandle = MAKE_AT_HANDLE( * (TelAtParserID *) arg_p );

	*xid_p = atHandle;

	//DBGMSG("ciPDPActivate: atHandle = %d, op=%d", atHandle, op);

	switch(op)
	{
		case TEL_EXT_GET_CMD:    /* AT+CGACT?  */
		{
			ret = PS_GetGPRSContextActivatedList(atHandle);
			break;
		}

		case TEL_EXT_TEST_CMD:    /* AT+CGACT=? */
		{
			ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,(char *)"+CGACT: (0,1)");
			break;
		}

		case TEL_EXT_SET_CMD:      /* AT+CGACT= */
		{
			BOOL cmdValid = FALSE;
			/*
			 **  Parse the state.
			 */
			if ( getExtValue( parameter_values_p, 0, (int *)&pdpState, TEL_AT_CGACT_0_STATE_VAL_MIN, TEL_AT_CGACT_0_STATE_VAL_MAX, TEL_AT_CGACT_0_STATE_VAL_DEFAULT ) == TRUE )
			{

				/*
				**  modify the timeout for the AT command processing
				*/
				{
					utlRelativeTime_T period;
					if (pdpState == 1)
						period.seconds     = 155;
					else if (pdpState == 0)
						period.seconds     = 55;
					else
						break;
					period.nanoseconds = 0;
					if ( utlModifyPendingAsyncResponse(&period, *xid_p) != utlSUCCESS)
						break;
				}
				if (parameter_values_p[1].is_default)
				{
					cmdValid = TRUE;
					/* All the pdpState is included: it should deactive all the activated PDP context */
					ret = PS_SetGPRSContextActivated(atHandle, 0, ATCI_PDP_INACTIVE, TRUE);
				}
				else
				{
					/* get the <cid> parameter */
					if ( getExtValue(parameter_values_p, 1, (int *)&cid, TEL_AT_CGACT_1_CID_VAL_MIN, TEL_AT_CGACT_1_CID_VAL_MAX, TEL_AT_CGACT_1_CID_VAL_DEFAULT) == TRUE )
					{
						//Fitz.xu 20211016: For DSDS, cid1-4 for SIM1, cid5-8 for SIM2.
					#if QUEC_DUAL_SIM_SUPPORT
					#ifndef MIN_SYS
						if (!IsMiniSystem()) 
						{//MiniSystem
							TelAtParserID sAtpIndex = GET_ATP_INDEX(atHandle);
						
							if (QUEC_IS_VALID_ATP(sAtpIndex))
							{
								if ((getDualSimType() == CM_DUAL_SIM_DUAL_STANDBY) || (getDualSimType() == CM_DUAL_SIM_DUAL_STANDBY_FP))
								{
									if ((sAtpIndex < TEL_AT_CMD_ATP_36) || quec_is_atp_bind_sim1(sAtpIndex))
									{
										if (cid > 4)
										{
											ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
											break;
										}
									}
									else if ((sAtpIndex < NUM_OF_TEL_ATP) || quec_is_atp_bind_sim2(sAtpIndex))
									{
										if (cid < 5)
										{
											ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
											break;	
										}	
									}
								}
							}
						}//MiniSystem
					#endif /*MIN_SYS*/
					#endif
			
						if (( cid > 0 ) && ( cid <= CI_PS_MAX_CID ))
						{
							cmdValid = TRUE;
							/* CI - SAC use cid range starting from 0 */
							cid--;
							ret = PS_SetGPRSContextActivated(atHandle, cid, (pdpState == ATCI_PDP_ACTIVE), FALSE);
						}       /* if (( cid > 0 ) && ( cid <= CI_PS_MAX_PDP_CTX_NUM )) */
					}               /* if( getExtValue (parameter_values_p, X, &cid, */
				}                       /* if  pdpState */
			}                               /* if ( getExtValue( parameter_values_p, X, &state, */
			if(!cmdValid)
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
			break;
		}

		case TEL_EXT_ACTION_CMD:   /* AT+CGACT */
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
			break;
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);

	return(rc);
}

/************************************************************************************
 * F@: ciPSAttach - GLOBAL API for GCF AT+CGATT -command
 *
 */
RETURNCODE_T  ciPSAttach(            const utlAtParameterOp_T        op,
									 const char                      *command_name_p,
									 const utlAtParameterValue_P2c   parameter_values_p,
									 const size_t                    num_parameters,
									 const char                      *info_text_p,
									 unsigned int                    *xid_p,
									 void                            *arg_p)
{
	CiReturnCode                        ret = CIRC_FAIL;
	RETURNCODE_T                        rc = INITIAL_RETURN_CODE;
	INT32                               cgatt=0;
	UINT32 atHandle = MAKE_AT_HANDLE( * (TelAtParserID *) arg_p );

	*xid_p = atHandle;

	DBGMSG("ciPSAttach: atHandle = %d, op=%d", atHandle, op);

	switch (op)
	{
		case TEL_EXT_TEST_CMD:    /* AT+CGATT=? */
		{
#ifdef QUECTEL_NETWORK_SUPPORT
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+CGATT: (0,1)\r\n");
#else
			ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,(char *)"+CGATT: (0-1)\r\n");
#endif
			break;
		}
		case TEL_EXT_GET_CMD:    /* AT+CGATT?  */
		{
			ret = PS_GetGPRSAttached(atHandle);
			break;
		}
		case TEL_EXT_SET_CMD:   /* AT+CGATT=  */
		{
			/*
			 **  Parse the state variable.
			 */
					if( getExtValue(parameter_values_p, 0, (int *)&cgatt, TEL_AT_CGATT_0_STATE_VAL_MIN, TEL_AT_CGATT_0_STATE_VAL_MAX, TEL_AT_CGATT_0_STATE_VAL_DEFAULT) == TRUE )
			{
				/*
				 **  Check if this is an attach or detach request.
				 */
				switch(cgatt)
				{
				case ATCI_GPRS_ATTACH_REQ:       /* perform GPRS attach */
				{
					ret = PS_SetGPRSAttached(atHandle, TRUE, CI_PS_ATTACH_STATE_NO_CAUSE);
					break;
				}

				case ATCI_GPRS_DETACH_REQ:       /* perform GPRS detach and flag all the CIDs as inactive */
				{
					ret = PS_SetGPRSAttached(atHandle, FALSE, CI_PS_DETACH_STATE_NO_CAUSE);
					break;
				}

				default:
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
					break;
				} /* switch */
			}
			else
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
			break;
		}
		case TEL_EXT_ACTION_CMD:   /* AT+CGATT   */
		default:
		{
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
			break;
		}
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);

}

/************************************************************************************
 * F@: ciCGDFLT - GLOBAL API for GCF AT*CGDFLT -command
 *
 */
RETURNCODE_T  ciCGDFLT(            const utlAtParameterOp_T op,
				       const char                      *command_name_p,
				       const utlAtParameterValue_P2c parameter_values_p,
				       const size_t num_parameters,
				       const char                      *info_text_p,
				       unsigned int                    *xid_p,
				       void                            *arg_p)
{
	RETURNCODE_T rc = INITIAL_RETURN_CODE;
	CiReturnCode ret = CIRC_FAIL;
	INT32 tmpParam = 0;
	CHAR tmpStr[TEL_AT_CGDFLT_1_PDPTYPE_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH] = "";
	INT16 tmpStrLen = 0;
	CiPsPrimDefineDefaultPdpCtxReq defaultPdpCtxInfo;
	UINT32 atHandle = MAKE_AT_HANDLE( *(TelAtParserID *)arg_p );

	*xid_p = atHandle;

	memset(&defaultPdpCtxInfo, 0, sizeof(defaultPdpCtxInfo));
	DBGMSG("%s: atHandle = %d.\n", __FUNCTION__, atHandle);

	switch (op)
	{
		case TEL_EXT_TEST_CMD:    /* AT*CGDFLT=? */
		{
			char tmpAtRspBuf[200];
			memset(tmpAtRspBuf, 0, sizeof(tmpAtRspBuf));
			/* for every PDP type */
			sprintf( tmpAtRspBuf, "*CGDFLT: (0-1),\"IP\",,(0-1),(0-1),(0-1),(0-1),(0-1),(0-1),(0-1),(0-1),\
					(0-1),(0-1),(0-1),(0-1),(0-1),(0-1),(0-1),(0-1),(0-1),(0-1),(0-1)" );
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)tmpAtRspBuf);
			break;
		}

		case TEL_EXT_SET_CMD:      /* AT*CGDFLT= */
		{
			int i;
			BOOL setMode = FALSE;
			memset(&defaultPdpCtxInfo, 0, sizeof(defaultPdpCtxInfo));

			/* 1  Extract the arguments starting with the CID. */
			if ( getExtValue( parameter_values_p, 0, (int *)&tmpParam, TEL_AT_CGDFLT_0_MODE_VAL_MIN, TEL_AT_CGDFLT_0_MODE_VAL_MAX, TEL_AT_CGDFLT_0_MODE_VAL_DEFAULT ) == TRUE )
			{
				defaultPdpCtxInfo.modeType = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			for(i = 1; i <= 20; i++)
			{
				if(parameter_values_p[i].is_default == FALSE)
				{
					setMode = TRUE;
					break;
				}
			}

			if(!setMode)
			{
				ret = PS_GetDefaultPDPContext(atHandle,tmpParam);
				break;
			}

			/* 2.  Determine the PDP type.     */
			if ( getExtString( parameter_values_p, 1, tmpStr, TEL_AT_CGDFLT_1_PDPTYPE_STR_MAX_LEN, &tmpStrLen, (CHAR *)TEL_AT_CGDFLT_1_PDPTYPE_STR_DEFAULT) == TRUE )
			{
				if(parameter_values_p[1].is_default == TRUE)
					defaultPdpCtxInfo.pdpTypePresent = FALSE;
				else if ( tmpStrLen != 0 )
				{
					defaultPdpCtxInfo.pdpTypePresent = TRUE;
					if (strcasecmp("IP", (char *)tmpStr) == 0)
						defaultPdpCtxInfo.pdpType = CI_PS_PDP_TYPE_IP;
					else if (strcasecmp("IPV6", (char *)tmpStr) == 0)
						defaultPdpCtxInfo.pdpType = CI_PS_PDP_TYPE_IPV6;
					else if (strcasecmp("IPV4V6", (char *)tmpStr) == 0)
						defaultPdpCtxInfo.pdpType = CI_PS_PDP_TYPE_IPV4V6;
					else
					{            /* default to IP */
						//pdpCtxInfo.type = CI_PS_PDP_TYPE_IP;
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
						break;
					}
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/*     ** 3 Assign the APN string.                 */
			if ( getExtString(parameter_values_p, 2, tmpStr, TEL_AT_CGDFLT_2_APN_STR_MAX_LEN, &tmpStrLen, TEL_AT_CGDFLT_2_APN_STR_DEFAULT) == TRUE )
			{
				if ( tmpStrLen != 0 )
				{
					defaultPdpCtxInfo.apn.len = tmpStrLen;
					/*have checked the string length*/
					/*klocwork[Buffer Overflow]*/
					memcpy( defaultPdpCtxInfo.apn.valStr, tmpStr, tmpStrLen );
				}
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 4  Extract the arguments starting with the emgInd. */
			if ( getExtValue( parameter_values_p, 3, (int *)&tmpParam, TEL_AT_CGDFLT_3_EMGIND_VAL_MIN, TEL_AT_CGDFLT_3_EMGIND_VAL_MAX, TEL_AT_CGDFLT_3_EMGIND_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[3].is_default == TRUE)
					defaultPdpCtxInfo.emgIndPresent = FALSE;
				else
					defaultPdpCtxInfo.emgIndPresent = TRUE;
				defaultPdpCtxInfo.emgInd = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 5  Extract the arguments starting with the ipcpReq. */
			if ( getExtValue( parameter_values_p, 4, (int *)&tmpParam, TEL_AT_CGDFLT_4_IPCPREQ_VAL_MIN, TEL_AT_CGDFLT_4_IPCPREQ_VAL_MAX, TEL_AT_CGDFLT_4_IPCPREQ_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[4].is_default == TRUE)
					defaultPdpCtxInfo.ipcpReqPresent = FALSE;
				else
					defaultPdpCtxInfo.ipcpReqPresent = TRUE;
				defaultPdpCtxInfo.ipcpReq = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 6  Extract the arguments starting with the pcscfIpv6Req. */
			if ( getExtValue( parameter_values_p, 5, (int *)&tmpParam, TEL_AT_CGDFLT_5_PCSCFIPV6REQ_VAL_MIN, TEL_AT_CGDFLT_5_PCSCFIPV6REQ_VAL_MAX, TEL_AT_CGDFLT_5_PCSCFIPV6REQ_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[5].is_default == TRUE)
					defaultPdpCtxInfo.pcscfIpv6ReqPresent = FALSE;
				else
					defaultPdpCtxInfo.pcscfIpv6ReqPresent = TRUE;
				defaultPdpCtxInfo.pcscfIpv6Req = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 7  Extract the arguments starting with the imcnSig. */
			if ( getExtValue( parameter_values_p, 6, (int *)&tmpParam, TEL_AT_CGDFLT_6_IMCNSIG_VAL_MIN, TEL_AT_CGDFLT_6_IMCNSIG_VAL_MAX, TEL_AT_CGDFLT_6_IMCNSIG_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[6].is_default == TRUE)
					defaultPdpCtxInfo.imcnSigPresent = FALSE;
				else
					defaultPdpCtxInfo.imcnSigPresent = TRUE;
				defaultPdpCtxInfo.imcnSig = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 8  Extract the arguments starting with the dnsIpv6. */
			if ( getExtValue( parameter_values_p, 7, (int *)&tmpParam, TEL_AT_CGDFLT_7_DNSIPV6_VAL_MIN, TEL_AT_CGDFLT_7_DNSIPV6_VAL_MAX, TEL_AT_CGDFLT_7_DNSIPV6_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[7].is_default == TRUE)
					defaultPdpCtxInfo.dnsIpv6Present = FALSE;
				else
					defaultPdpCtxInfo.dnsIpv6Present = TRUE;
				defaultPdpCtxInfo.dnsIpv6 = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 9  Extract the arguments starting with the nwBear. */
			if ( getExtValue( parameter_values_p, 8, (int *)&tmpParam, TEL_AT_CGDFLT_8_NWBEAR_VAL_MIN, TEL_AT_CGDFLT_8_NWBEAR_VAL_MAX, TEL_AT_CGDFLT_8_NWBEAR_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[8].is_default == TRUE)
					defaultPdpCtxInfo.nwBearPresent = FALSE;
				else
					defaultPdpCtxInfo.nwBearPresent = TRUE;
				defaultPdpCtxInfo.nwBear = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 10  Extract the arguments starting with the dsmIpv6Ha. */
			if ( getExtValue( parameter_values_p, 9, (int *)&tmpParam, TEL_AT_CGDFLT_9_DSMIPV6HA_VAL_MIN, TEL_AT_CGDFLT_9_DSMIPV6HA_VAL_MAX, TEL_AT_CGDFLT_9_DSMIPV6HA_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[9].is_default == TRUE)
					defaultPdpCtxInfo.dsmIpv6HaPresent = FALSE;
				else
					defaultPdpCtxInfo.dsmIpv6HaPresent = TRUE;
				defaultPdpCtxInfo.dsmIpv6Ha = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 11  Extract the arguments starting with the dsmIpv6Pref. */
			if ( getExtValue( parameter_values_p, 10, (int *)&tmpParam, TEL_AT_CGDFLT_10_DSMIPV6PREF_VAL_MIN, TEL_AT_CGDFLT_10_DSMIPV6PREF_VAL_MAX, TEL_AT_CGDFLT_10_DSMIPV6PREF_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[10].is_default == TRUE)
					defaultPdpCtxInfo.dsmIpv6PrefPresent = FALSE;
				else
					defaultPdpCtxInfo.dsmIpv6PrefPresent = TRUE;
				defaultPdpCtxInfo.dsmIpv6Pref = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 12  Extract the arguments starting with the dsmIpv6HaIpv4. */
			if ( getExtValue( parameter_values_p, 11, (int *)&tmpParam, TEL_AT_CGDFLT_11_DSMIPV6HAIPV4_VAL_MIN, TEL_AT_CGDFLT_11_DSMIPV6HAIPV4_VAL_MAX, TEL_AT_CGDFLT_11_DSMIPV6HAIPV4_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[11].is_default == TRUE)
					defaultPdpCtxInfo.dsmIpv6HaIpv4Present = FALSE;
				else
					defaultPdpCtxInfo.dsmIpv6HaIpv4Present = TRUE;
				defaultPdpCtxInfo.dsmIpv6HaIpv4 = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 13  Extract the arguments starting with the ipViaNas. */
			if ( getExtValue( parameter_values_p, 12, (int *)&tmpParam, TEL_AT_CGDFLT_12_IPVIANAS_VAL_MIN, TEL_AT_CGDFLT_12_IPVIANAS_VAL_MAX, TEL_AT_CGDFLT_12_IPVIANAS_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[12].is_default == TRUE)
					defaultPdpCtxInfo.ipViaNasPresent = FALSE;
				else
					defaultPdpCtxInfo.ipViaNasPresent = TRUE;
				defaultPdpCtxInfo.ipViaNas = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 14  Extract the arguments starting with the ipViaDhcp. */
			if ( getExtValue( parameter_values_p, 13, (int *)&tmpParam, TEL_AT_CGDFLT_13_IPVIADHCP_VAL_MIN, TEL_AT_CGDFLT_13_IPVIADHCP_VAL_MAX, TEL_AT_CGDFLT_13_IPVIADHCP_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[13].is_default == TRUE)
					defaultPdpCtxInfo.ipViaDhcpPresent = FALSE;
				else
					defaultPdpCtxInfo.ipViaDhcpPresent = TRUE;
				defaultPdpCtxInfo.ipViaDhcp = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 15  Extract the arguments starting with the pcscfIpv4. */
			if ( getExtValue( parameter_values_p, 14, (int *)&tmpParam, TEL_AT_CGDFLT_14_PCSCFIPV4_VAL_MIN, TEL_AT_CGDFLT_14_PCSCFIPV4_VAL_MAX, TEL_AT_CGDFLT_14_PCSCFIPV4_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[14].is_default == TRUE)
					defaultPdpCtxInfo.pcscfIpv4Present = FALSE;
				else
					defaultPdpCtxInfo.pcscfIpv4Present = TRUE;
				defaultPdpCtxInfo.pcscfIpv4 = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 16  Extract the arguments starting with the dnsIpv4. */
			if ( getExtValue( parameter_values_p, 15, (int *)&tmpParam, TEL_AT_CGDFLT_15_DNSIPV4_VAL_MIN, TEL_AT_CGDFLT_15_DNSIPV4_VAL_MAX, TEL_AT_CGDFLT_15_DNSIPV4_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[15].is_default == TRUE)
					defaultPdpCtxInfo.dnsIpv4Present = FALSE;
				else
					defaultPdpCtxInfo.dnsIpv4Present = TRUE;
				defaultPdpCtxInfo.dnsIpv4 = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 17  Extract the arguments starting with the msisdn. */
			if ( getExtValue( parameter_values_p, 16, (int *)&tmpParam, TEL_AT_CGDFLT_16_MSISDN_VAL_MIN, TEL_AT_CGDFLT_16_MSISDN_VAL_MAX, TEL_AT_CGDFLT_16_MSISDN_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[16].is_default == TRUE)
					defaultPdpCtxInfo.msisdnPresent = FALSE;
				else
					defaultPdpCtxInfo.msisdnPresent = TRUE;
				defaultPdpCtxInfo.msisdn = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 18  Extract the arguments starting with the ifom. */
			if ( getExtValue( parameter_values_p, 17, (int *)&tmpParam, TEL_AT_CGDFLT_17_IFOM_VAL_MIN, TEL_AT_CGDFLT_17_IFOM_VAL_MAX, TEL_AT_CGDFLT_17_IFOM_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[17].is_default == TRUE)
					defaultPdpCtxInfo.ifomPresent = FALSE;
				else
					defaultPdpCtxInfo.ifomPresent = TRUE;
				defaultPdpCtxInfo.ifom = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 19  Extract the arguments starting with the v4mtu. */
			if ( getExtValue( parameter_values_p, 18, (int *)&tmpParam, TEL_AT_CGDFLT_18_V4MTU_VAL_MIN, TEL_AT_CGDFLT_18_V4MTU_VAL_MAX, TEL_AT_CGDFLT_18_V4MTU_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[18].is_default == TRUE)
					defaultPdpCtxInfo.v4mtuPresent = FALSE;
				else
					defaultPdpCtxInfo.v4mtuPresent = TRUE;
				defaultPdpCtxInfo.v4mtu = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			/* 20  Extract the arguments starting with the localTft. */
			if ( getExtValue( parameter_values_p, 19, (int *)&tmpParam, TEL_AT_CGDFLT_19_LOCALTFT_VAL_MIN, TEL_AT_CGDFLT_19_LOCALTFT_VAL_MAX, TEL_AT_CGDFLT_19_LOCALTFT_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[19].is_default == TRUE)
					defaultPdpCtxInfo.localTftPresent = FALSE;
				else
					defaultPdpCtxInfo.localTftPresent = TRUE;
				defaultPdpCtxInfo.localTft = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}

			if ( getExtValue( parameter_values_p, 20, (int *)&tmpParam, TEL_AT_CGDFLT_20_ETIF_VAL_MIN, TEL_AT_CGDFLT_20_ETIF_VAL_MAX, TEL_AT_CGDFLT_20_ETIF_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[20].is_default == TRUE)
					defaultPdpCtxInfo.etifPresent = FALSE;
				else
					defaultPdpCtxInfo.etifPresent = TRUE;
				defaultPdpCtxInfo.etifFlag = tmpParam;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
				break;
			}
			ret = PS_SetDefaultPDPContext(atHandle, &defaultPdpCtxInfo);

			break;
		}

		case TEL_EXT_ACTION_CMD:   /* AT*CGDFLT */
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
			break;
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);

}

/************************************************************************************
 * F@: ciEnterData - GLOBAL API for GCF AT+CGDATA
 *
 */
RETURNCODE_T  ciEnterData(            const utlAtParameterOp_T        op,
									  const char                      *command_name_p,
									  const utlAtParameterValue_P2c   parameter_values_p,
									  const size_t                    num_parameters,
									  const char                      *info_text_p,
									  unsigned int                    *xid_p,
									  void                            *arg_p)
{
	RETURNCODE_T                          rc = INITIAL_RETURN_CODE;
	CiReturnCode                          ret = CIRC_FAIL;
	CHAR                                  l2pType[TEL_AT_CGDATA_0_L2P_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH] = {0};
	INT16                                 l2pTypeLength = 0;
	INT32                                 cid=0;
	CiPsL2P  l2p = CI_PS_NUM_L2PS;

	UINT32 atHandle = MAKE_AT_HANDLE( * (TelAtParserID *) arg_p );
	*xid_p = atHandle;

	DBGMSG("ciEnterData: atHandle = %d, op=%d", atHandle, op);
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
	
#ifdef QUEC_PPP_ENABLE
	CPUartLogPrintf("%s,%d,atp_index=%d,op=%d,enter data mode",__func__,__LINE__,* (TelAtParserID *) arg_p,op);
#endif

	switch(op)
	{
		case TEL_EXT_TEST_CMD:	  /* AT+CGDATA=? */
		{
			ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,(char *)"+CGDATA: \"PPP\"");
			break;
		}

		case TEL_EXT_SET_CMD:	   /* AT+CGDATA= */
		{
			BOOL cmdValid = FALSE;
			if ( getExtString( parameter_values_p, 0, l2pType, TEL_AT_CGDATA_0_L2P_STR_MAX_LEN, &l2pTypeLength, (CHAR *)TEL_AT_CGDATA_0_L2P_STR_DEFAULT ) == TRUE )
			{
#ifdef QUEC_PPP_ENABLE
				CPUartLogPrintf("%s,%d,atp_index=%d,l2pType=%s,l2pTypeLength=%d",__func__,__LINE__,* (TelAtParserID *) arg_p,l2pType,l2pTypeLength); 
				if((strcmp("PPP", (char *)l2pType ) == 0) || ( strcmp("ppp", (char *)l2pType) == 0 ))  
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_SUPPRESS, 0, (CHAR *)"CONNECT");
					handle_dial(* (TelAtParserID *) arg_p);
					break;
				}  
	
#endif
				#ifdef QUEC_PPP_ENABLE
				if ( l2pTypeLength == 0 )
					l2p = CI_PS_L2P_NONE;
				else if (( strcmp("NULL", (char *)l2pType ) == 0) || ( strcmp("null", (char *)l2pType) == 0 ))
					l2p = CI_PS_L2P_NONE;
				else if (strcasecmp("PPP", (char *)l2pType ) == 0)
			        l2p = CI_PS_L2P_PPP;
				#endif
				if ( l2p < CI_PS_NUM_L2PS )
				{
					/*
					 **  Get context identifier - multiple cids is not supported
					 */
					if ( getExtValue (parameter_values_p, 1, (int *)&cid, TEL_AT_CGDATA_1_CID_VAL_MIN, TEL_AT_CGDATA_1_CID_VAL_MAX, TEL_AT_CGDATA_1_CID_VAL_DEFAULT) == TRUE )
					{
						if (( cid > 0 ) && ( cid <= CI_PS_MAX_CID ))
						{
							cmdValid = TRUE;
							/* CI - SAC use cid range starting from 0 */
							cid--;

							ret = PS_EnterGPRSDataMode (atHandle, cid, l2p);
							#ifdef QUEC_PPP_ENABLE
								if(CIRC_FAIL== ret)
								{
									
									CPUartLogPrintf("%s,%d,enter datamode,ret=%d",__func__,__LINE__,ret); 
									cmdValid = FALSE;
								}
							#endif

						}
					}
				}
			}
			if(!cmdValid)
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
			break;
		}

		case TEL_EXT_GET_CMD:    /* AT+CGDATA?  */
		case TEL_EXT_ACTION_CMD:   /* AT+CGDATA */
			default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
			break;
	}
}//MiniSystem
else
{

	switch(op)
	{
		case TEL_EXT_TEST_CMD:    /* AT+CGDATA=? */
		{
			ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,(char *)"+CGDATA: \"\", cid");
			break;
		}

		case TEL_EXT_SET_CMD:      /* AT+CGDATA= */
		{
			BOOL cmdValid = FALSE;
			if ( getExtString( parameter_values_p, 0, l2pType, TEL_AT_CGDATA_0_L2P_STR_MAX_LEN, &l2pTypeLength, (CHAR *)TEL_AT_CGDATA_0_L2P_STR_DEFAULT ) == TRUE )
			{
				if ( l2pTypeLength == 0 )
					l2p = CI_PS_L2P_NONE;
				else if (( strcmp("NULL", (char *)l2pType ) == 0) || ( strcmp("null", (char *)l2pType) == 0 ))
					l2p = CI_PS_L2P_NONE;
			    else if (strcasecmp("PPP", (char *)l2pType ) == 0)
			        l2p = CI_PS_L2P_PPP;

				if ( l2p < CI_PS_NUM_L2PS )
				{
					/*
					 **  Get context identifier - multiple cids is not supported
					 */
					if ( getExtValue (parameter_values_p, 1, (int *)&cid, TEL_AT_CGDATA_1_CID_VAL_MIN, TEL_AT_CGDATA_1_CID_VAL_MAX, TEL_AT_CGDATA_1_CID_VAL_DEFAULT) == TRUE )
					{
						if (( cid > 0 ) && ( cid <= CI_PS_MAX_CID ))
						{
							cmdValid = TRUE;
							/* CI - SAC use cid range starting from 0 */
							cid--;

							ret = PS_EnterGPRSDataMode (atHandle, cid, l2p);

						}
					}
				}
			}
			if(!cmdValid)
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
			break;
		}

		case TEL_EXT_GET_CMD:    /* AT+CGDATA?  */
		case TEL_EXT_ACTION_CMD:   /* AT+CGDATA */
			default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
			break;
	}
}
#endif /*MIN_SYS*/

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);

}

/************************************************************************************
 * F@: ciCGTFT - GLOBAL API for GCF AT+CGTFT -command
 *
 */
RETURNCODE_T  ciCGTFT(            const utlAtParameterOp_T        op,
								  const char                      *command_name_p,
								  const utlAtParameterValue_P2c   parameter_values_p,
								  const size_t                    num_parameters,
								  const char                      *info_text_p,
								  unsigned int                    *xid_p,
								  void                            *arg_p)
{
	/*
	 **  Set the result code to RESULT_CODE_INTERMEDIATE.  This allows
	 **  the indications to display the correct return code after the
	 **  AT Command is issued.
	 */
	RETURNCODE_T                    rc = INITIAL_RETURN_CODE;
	CiReturnCode                    ret = CIRC_FAIL;
	BOOL                         	cmdValid = FALSE;

	CiPsTftFilter tftFilter, *pFilter=NULL;
	CiPsPdpAddr_convert pdp_addr;
	UINT8 add_len=0;
	UINT8 mask_len=0;

	CHAR strAddress[TEL_AT_CGTFT_ADDRESS_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH];
	CHAR strDestPort[TEL_AT_CGTFT_PORT_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH];
	CHAR strSrcPort[TEL_AT_CGTFT_PORT_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH];
	CHAR strIpsec[TEL_AT_CGTFT_IPSEC_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH];
	CHAR strTos[TEL_AT_CGTFT_TOS_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH];
	CHAR strFlowLable[TEL_AT_CGTFT_FLOWLABLE_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH];
	int cid = 0, pfid = 0, epindex = 0, protocolNum = 0, iNumOfDots = 0, index = 0, minVal = 0, maxVal = 0;
	INT16 addressLen = 0, destPortLen = 0, srcPortLen = 0, ipsecLen = 0, tosLen = 0, flowLableLen = 0;
	BOOL bFoundDot = FALSE, bContinue = TRUE;

	int                     direction = 0;
	char rspBuf[1024];//mengliang add 20120322


	/* Modified by Daniel for LTE PC AT command server 20120312, end */
	/*
	 *  Put parser index into the variable
	 */
	UINT32 atHandle=0;
	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	atHandle = MAKE_AT_HANDLE( sAtpIndex );
	*xid_p = atHandle;
	DBGMSG("ciCGTFT: atHandle = %d, op=%d", atHandle, op);

	memset(&tftFilter, 0, sizeof(tftFilter));
	memset(&pdp_addr, 0, sizeof(pdp_addr));
	memset(strAddress, 0, sizeof(strAddress));
	memset(strDestPort, 0, sizeof(strDestPort));
	memset(strSrcPort, 0, sizeof(strSrcPort));
	memset(strIpsec, 0, sizeof(strIpsec));
	memset(strTos, 0, sizeof(strTos));
	memset(strFlowLable, 0, sizeof(strFlowLable));
	memset(rspBuf, 0, sizeof(rspBuf));

	/*
	 **  Check the format of the request.
	 */
	switch(op)
	{
		case TEL_EXT_GET_CMD:    /* AT+CGTFT?  */
		{
			ret = PS_GetTftList(atHandle);
			break;
		}

		case TEL_EXT_TEST_CMD:    /* AT+CGTFT=? */
		{
			ret = ATRESP( atHandle,0,0,(char *)"+CGTFT: <cid>(1-16), <packet filter identifier>(1-16), <evaluation precedence index>(0-255),");
			ret = ATRESP( atHandle,0,0,(char *)"<source address and subnet mask>, <protocol number (ipv4) / next header (ipv6)>,");//<destination port range>, <source port range>, <ipsec security parameter index (spi)>(00000000-FFFFFFFF),");
			ret = ATRESP( atHandle,0,0,(char *)"<source port range>, <destination port range>, <ipsec security parameter index (spi)>(00000000-FFFFFFFF),");
			ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,(char *)"<type of service (tos) (ipv4) and mask / traffic class (ipv6) and mask>, <flow label (ipv6)>(00000-FFFFF), <direction>(0-3)\r\n");


			break;
		}

		case TEL_EXT_SET_CMD:      /* AT+CGDCONT= */
		{
			if( getExtValue( parameter_values_p, 0, &cid, TEL_AT_CGTFT_CID_VAL_MIN, TEL_AT_CGTFT_CID_VAL_MAX, TEL_AT_CGTFT_CID_VAL_DEFAULT ) == TRUE )
			{
				if(parameter_values_p[1].is_default && parameter_values_p[2].is_default && parameter_values_p[3].is_default && parameter_values_p[4].is_default	&& parameter_values_p[5].is_default && parameter_values_p[6].is_default && parameter_values_p[7].is_default && parameter_values_p[8].is_default && parameter_values_p[9].is_default)
				{//CGTFT = <cid> -> delete reqest
					if (( cid > 0 ) && ( cid <= CI_PS_MAX_CID ))
					{

						/* CI - SAC use cid range starting from 0 */
						cid--;
						ret = PS_DeleteTft(atHandle, cid);
						cmdValid = TRUE;
					}
				}
				else //set reqest process user parameter to ci reqest
				{
					if (( cid > 0 ) && ( cid <= CI_PS_MAX_CID ) && (parameter_values_p[1].is_default == FALSE))
					{
						if( getExtValue( parameter_values_p, 1, &pfid, TEL_AT_CGTFT_PFID_VAL_MIN, TEL_AT_CGTFT_PFID_VAL_MAX, TEL_AT_CGTFT_PFID_VAL_DEFAULT ) == TRUE )
						{
							if( getExtValue ( parameter_values_p, 2,&epindex , TEL_AT_CGTFT_EPINDEX_VAL_MIN, TEL_AT_CGTFT_EPINDEX_VAL_MAX, TEL_AT_CGTFT_EPINDEX_VAL_DEFAULT ) == TRUE )
							{
								pFilter = &tftFilter;

								/* CI - SAC use cid range starting from 0 */
								cid--;

								pFilter->pfId = (UINT8)pfid;            /*Packet Filter ID*/
								pFilter->epIndex = (UINT8)epindex;      /*Evaluation precedence index*/


								if( getExtString( parameter_values_p, 3, strAddress, TEL_AT_CGTFT_ADDRESS_STR_MAX_LEN, &addressLen , (CHAR *)TEL_AT_CGTFT_ADDRESS_STR_DEFAULT) == TRUE )
								{
									/*source address and sub netmask*/
									/********************************/
									if (parameter_values_p[3].is_default == FALSE)
									{
										CHAR * strAddressMask = &strAddress[index];
										for (index = 0; index < addressLen; index++)
										{
											if ( strAddress[index] == '.')
											{
												iNumOfDots++;
												if (iNumOfDots == 4)
													strAddressMask = &strAddress[index + 1];
												else if (iNumOfDots == 16)
													strAddressMask = &strAddress[index + 1];
											}
										}

										switch (iNumOfDots)
										{
											case 3: //IPv4 Src Addres only
											{
												pFilter->remoteAddrAndMask.subnetLength = 0;
												pFilter->remoteAddrAndMask.addrType = CI_PS_PDP_IPV4;
												add_len = ((UINT8)(addressLen) < 64 ? (UINT8)(addressLen) : 63);
												memcpy(pdp_addr.valData, strAddress, add_len);
												pdp_addr.valData[add_len] = 0;
												DBGMSG("[%s] Line(%d): pdp_addr.valData(%s) \n", __FUNCTION__, __LINE__, pdp_addr.valData);
												if(ConvertStrAddress2hexaddr(&pdp_addr))
													memcpy(pFilter->remoteAddrAndMask.valData, pdp_addr.valData, pdp_addr.len);
												else
													bContinue = FALSE;
												break;
											}
											case 15: //IPv6 Src Addres only
											{
												pFilter->remoteAddrAndMask.subnetLength = 0;
												pFilter->remoteAddrAndMask.addrType = CI_PS_PDP_FULL_IPV6;
												add_len = ((UINT8)(addressLen) < 64 ? (UINT8)(addressLen) : 63);
												memcpy(pdp_addr.valData, strAddress, add_len);
												pdp_addr.valData[add_len] = 0;
												DBGMSG("[%s] Line(%d): pdp_addr.valData(%s) \n", __FUNCTION__, __LINE__, pdp_addr.valData);
												if(ConvertStrAddress2hexaddr(&pdp_addr))
													memcpy(pFilter->remoteAddrAndMask.valData, pdp_addr.valData, pdp_addr.len);
												else
													bContinue = FALSE;
												break;
											}
											case 7: //IPv4 Src Addres and Sub net mask
											{
												pFilter->remoteAddrAndMask.addrType = CI_PS_PDP_IPV4;
												add_len = ((UINT8)(strAddressMask - strAddress - 1) < 64 ? (UINT8)(strAddressMask - strAddress - 1) : 63);
												memcpy(pdp_addr.valData, strAddress, add_len);
												pdp_addr.valData[add_len] = 0;
												DBGMSG("[%s] Line(%d): pdp_addr.valData(%s) \n", __FUNCTION__, __LINE__, pdp_addr.valData);
												if(ConvertStrAddress2hexaddr(&pdp_addr))
													memcpy(pFilter->remoteAddrAndMask.valData, pdp_addr.valData, pdp_addr.len);
												else
													bContinue = FALSE;
												if((mask_len = (UINT8)subnetmask_Str2Len((char* )strAddressMask)) > 0)
													pFilter->remoteAddrAndMask.subnetLength = mask_len;
												else
													bContinue = FALSE;
												break;
											}
											case 31: //IPv6 Src Addres and Sub net mask
											{
												pFilter->remoteAddrAndMask.addrType = CI_PS_PDP_FULL_IPV6;
												add_len = ((UINT8)(strAddressMask - strAddress - 1) < 64 ? (UINT8)(strAddressMask - strAddress - 1) : 63);
												memcpy(pdp_addr.valData, strAddress, add_len);
												pdp_addr.valData[add_len] = 0;
												DBGMSG("[%s] Line(%d): pdp_addr.valData(%s) \n", __FUNCTION__, __LINE__, pdp_addr.valData);
												if(ConvertStrAddress2hexaddr(&pdp_addr))
													memcpy(pFilter->remoteAddrAndMask.valData, pdp_addr.valData, pdp_addr.len);
												else
													bContinue = FALSE;
												if((mask_len = (UINT8)subnetmask_Str2Len((char* )strAddressMask)) > 0)
													pFilter->remoteAddrAndMask.subnetLength = mask_len;
												else
													bContinue = FALSE;
												break;
											}
											default:
												bContinue = FALSE;
												break;
										}
									}
								}
								if(bContinue)
								{
									if( getExtValue( parameter_values_p, 4, &protocolNum, TEL_AT_CGTFT_PROTOCOLNUM_VAL_MIN, TEL_AT_CGTFT_PROTOCOLNUM_VAL_MAX, TEL_AT_CGTFT_PROTOCOLNUM_VAL_DEFAULT ) == TRUE )
									{
										/*protocol number (ipv4) / next header (ipv6)*/
										if(parameter_values_p[4].is_default == FALSE)
										{
											pFilter->pIdNextHdr = (UINT8) protocolNum;
											pFilter->pIdNextHdrPresent = TRUE;
										}
										else
											pFilter->pIdNextHdrPresent = FALSE;
									}
									else
										bContinue = FALSE;
								}
								/*destination port range*/
								/************************/
								if(bContinue)
								{
									if( getExtString( parameter_values_p, 5, strSrcPort, TEL_AT_CGTFT_PORT_STR_MAX_LEN, &srcPortLen , (CHAR *)TEL_AT_CGTFT_PORT_STR_DEFAULT) == TRUE )
									{

										if( parameter_values_p[5].is_default == FALSE)
										{
											bFoundDot = FALSE;
											for (index = 0; index < srcPortLen && bFoundDot == FALSE; index++)
											{
												if( strSrcPort[index] == '.')
												{
													if(index + 1 < srcPortLen)
													{
														minVal = atoi((char*)strSrcPort);
														maxVal = atoi((char*)&strSrcPort[index+1]);
														bFoundDot = TRUE;
													}
												}
											}
											if(bFoundDot)
											{
												if(minVal >= 0 && minVal <= MAX_PORT_RANGE && maxVal >= 0 && maxVal <= MAX_PORT_RANGE )
												{
													pFilter->srcPortRange.min = (UINT32)minVal;
													pFilter->srcPortRange.max = (UINT32)maxVal;
													pFilter->srcPortRangePresent = TRUE;
												}
												else
													bContinue = FALSE;
											}
											else
												bContinue = FALSE;
										}
										else
											pFilter->srcPortRangePresent = FALSE;


									}
								}

								/*source port range*/
								/*******************/
								if(bContinue)
								{
									if( getExtString( parameter_values_p, 6, strDestPort, TEL_AT_CGTFT_PORT_STR_MAX_LEN, &destPortLen , (CHAR *)TEL_AT_CGTFT_PORT_STR_DEFAULT) == TRUE )
									{
										if( parameter_values_p[6].is_default == FALSE)
										{
											bFoundDot = FALSE;
											for (index = 0; index < destPortLen && bFoundDot == FALSE; index++)
											{
												if( strDestPort[index] == '.')
												{
													if(index + 1 < destPortLen)
													{
														minVal = atoi((char*)strDestPort);
														maxVal = atoi((char*)&strDestPort[index+1]);
														bFoundDot = TRUE;
													}
												}
											}
											if(bFoundDot)
											{
												#define MAX_PORT_RANGE 65535
												if(minVal >= 0 && minVal <= MAX_PORT_RANGE && maxVal >= 0 && maxVal <= MAX_PORT_RANGE )
												{
													pFilter->dstPortRange.min = (UINT32)minVal ;
													pFilter->dstPortRange.max = (UINT32)maxVal;
													pFilter->dstPortRangePresent = TRUE;
												}
												else
													bContinue = FALSE;
											}
											else
												bContinue = FALSE;
										}
										else
											pFilter->dstPortRangePresent = FALSE;
									}
								}

								/*ipsec security parameter index (spi)*/
								/**************************************/
								if(bContinue)
								{
									if( getExtString( parameter_values_p, 7, strIpsec, TEL_AT_CGTFT_IPSEC_STR_MAX_LEN, &ipsecLen , (CHAR *)TEL_AT_CGTFT_IPSEC_STR_DEFAULT) == TRUE )
									{


										if( parameter_values_p[7].is_default == FALSE)
										{
											if(HexToBin((char *)strIpsec,(int*)&pFilter->ipSecSPI,ipsecLen))
											{
												pFilter->ipSecSPIPresent = TRUE;
											}
											else
												bContinue = FALSE;
										}
										else
											pFilter->ipSecSPIPresent = FALSE;
									}
								}

								/*type of service (tos) and mask (ipv4) / traffic class (ipv4) and mask*/
								/***********************************************************************/
								if(bContinue)
								{
									if( getExtString( parameter_values_p, 8, strTos, TEL_AT_CGTFT_TOS_STR_MAX_LEN, &tosLen , (CHAR *)TEL_AT_CGTFT_TOS_STR_DEFAULT) == TRUE )
									{

										if( parameter_values_p[8].is_default == FALSE)
										{
											bFoundDot = FALSE;
											for (index = 0; index < tosLen && bFoundDot == FALSE; index++)
											{
												if( strTos[index] == '.')
												{
													if(index + 1 < tosLen)
													{
														minVal = atoi((char*)strTos);
														maxVal = atoi((char*)&strTos[index+1]);
														bFoundDot = TRUE;
													}
												}
											}
											if(bFoundDot)
											{
												if(minVal >= 0 && minVal < 255 && maxVal >= 0 && maxVal < 255 )
												{
													pFilter->tosTc = (UINT8)minVal ;
													pFilter->tosTcMask = (UINT8)maxVal;
													pFilter->tosPresent = TRUE;
												}
												else
													bContinue = FALSE;
											}
											else
												bContinue = FALSE;
										}
										else
											pFilter->tosPresent = FALSE;
									}
								}

								/*flow label (ipv6)*/
								/*******************/
								if(bContinue)
								{
									if( getExtString( parameter_values_p, 9, strFlowLable, TEL_AT_CGTFT_FLOWLABLE_STR_MAX_LEN, &flowLableLen , (CHAR *)TEL_AT_CGTFT_FLOWLABLE_STR_DEFAULT) == TRUE )
									{
										if( parameter_values_p[9].is_default == FALSE)
										{
											if (HexToBin((char *)strFlowLable, (int*)&pFilter->flowLabel, flowLableLen))
											{
												pFilter->flowLabelPresent = TRUE;
											}
											else
												bContinue = FALSE;
										}
										else
											pFilter->flowLabelPresent = FALSE;
									}
								}
								if(bContinue)
								{
									if( getExtValue( parameter_values_p, 10, &direction, TEL_AT_CGTFT_DIRECTION_MIN, TEL_AT_CGTFT_DIRECTION_MAX, TEL_AT_CGTFT_DIRECTION_DEFAULT) == TRUE )
									{
										/* mark command as valid */


										if( parameter_values_p[10].is_default == FALSE)
										{
											pFilter->direction = (UINT8)direction;
											// pFilter->directionPresent = TRUE;
										}
										else
										{
											pFilter->direction = 3;
											// pFilter->directionPresent = FALSE;
										}
									}
								}
								/* Send CI reqest*/

								if(bContinue)
								{
									ret = PS_SetTftFilter(atHandle, cid, pFilter);

									/* mark command as valid */
									cmdValid = TRUE;
								}
							}
						}
					}
				}
			}
			if ( cmdValid == FALSE )
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, 0);
			}
			break;
		}

		case TEL_EXT_ACTION_CMD:   /* AT+CGTFT */
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, 0);
			break;
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);

}

/************************************************************************************
 * F@: ciCGEQOSRDP - GLOBAL API for GCF AT+CGEQOSRDP  -command
 *
 * NOTE: This function does not approximate error ratio value: if a value not defined in 24.008, it is rejected
 */
RETURNCODE_T  ciCGEQOSRDP(            const utlAtParameterOp_T        op,
									  const char                      *command_name_p,
									  const utlAtParameterValue_P2c   parameter_values_p,
									  const size_t                    num_parameters,
									  const char                      *info_text_p,
									  unsigned int                    *xid_p,
									  void                            *arg_p)
{
	RETURNCODE_T                    rc = INITIAL_RETURN_CODE;
	CiReturnCode                    ret = CIRC_FAIL;
	INT32                           cid=0;

	UINT32 atHandle = MAKE_AT_HANDLE( * (TelAtParserID *) arg_p );

	*xid_p = atHandle;


	switch(op)
	{
		case TEL_EXT_GET_CMD:    /* AT+CGEQOSRDP?  */
		{
			char tmpBuf[1000];
			memset(tmpBuf, 0, sizeof(tmpBuf));
			sprintf((char *)tmpBuf, "+CGEQOSRDP: (<cid>), (<QCI>),(<DL_GBR>),(<UL_GBR>),(<DL_MBR>),(<UL_MBR>)\r\n");
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)tmpBuf);
			break;
		}

		case TEL_EXT_TEST_CMD:    /* AT+CGEQOSRDP =? */
		{
			ret = PS_ReadDynActQOS(atHandle);
			break;
		}

		case TEL_EXT_SET_CMD:      /* AT+CGEQOSRDP = */
		{
            /*
                       **  Extract the arguments starting with the CID.
                       */
            if(parameter_values_p[0].is_default == TRUE)
            {
                ret = PS_ReadDynQOS(atHandle, TEL_AT_CGEQREQ_0_CID_VAL_MAX);
            }
            else if((getExtValue(parameter_values_p, 0, (int *)&cid, TEL_AT_CGEQREQ_0_CID_VAL_MIN, TEL_AT_CGEQREQ_0_CID_VAL_MAX, TEL_AT_CGEQREQ_0_CID_VAL_DEFAULT) == TRUE) &&
				( cid > 0 ) && ( cid <= CI_PS_MAX_CID ))
            {
                ret = PS_ReadDynQOS(atHandle, cid-1);
            }
			break;
		}

		case TEL_EXT_ACTION_CMD:   /* AT+CGEQOSRDP */
		default:
		{
	            ret = ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
			break;
		}
	}


	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);

}

/************************************************************************************
 * F@: ciCGCONTRDP - GLOBAL API for GCF AT+CGCONTRDP  -command
 *
 * NOTE: This function does not approximate error ratio value: if a value not defined in 24.008, it is rejected
 */
RETURNCODE_T  ciCGCONTRDP(            const utlAtParameterOp_T        op,
									  const char                      *command_name_p,
									  const utlAtParameterValue_P2c   parameter_values_p,
									  const size_t                    num_parameters,
									  const char                      *info_text_p,
									  unsigned int                    *xid_p,
									  void                            *arg_p)
{
	RETURNCODE_T                    rc = INITIAL_RETURN_CODE;
	CiReturnCode                    ret = CIRC_FAIL;
	INT32                           cid=0;

	UINT32 atHandle = MAKE_AT_HANDLE( * (TelAtParserID *) arg_p );

	*xid_p = atHandle;

	switch(op)
	{
		case TEL_EXT_GET_CMD:    /* AT+CGCONTRDP?  */
		{
			char tmpBuf[1000];
		   	memset(tmpBuf, 0, sizeof(tmpBuf));
	        sprintf((char *)tmpBuf, "+CGCONTRDP: (<p_cid>), (<bearer_id>),(<apn>),(<source_addr and subnet_mask>),(<gw_addr>), (<DNS_prim_addr>), (<DNS_sec_addr>), (<P-CSCF_prim_addr>), (<P-CSCF_sec_addr>),(<IM_CN_Signalling_Flag>)r\n");//support R10
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)tmpBuf);
			break;
		}

		case TEL_EXT_TEST_CMD:    /* AT+CGCONTRDP=? */
		{
			ret = PS_ReadDynActPara(atHandle);
			break;
		}

		case TEL_EXT_SET_CMD:      /* AT+CGCONTRDP= */
		{
			/*
			 **  Extract the arguments starting with the CID.
			 */
            if(parameter_values_p[0].is_default == TRUE)
            {
                ret = PS_ReadDynPara(atHandle, TEL_AT_CGEQREQ_0_CID_VAL_MAX);
            }
            else if((getExtValue(parameter_values_p, 0, (int *)&cid, TEL_AT_CGEQREQ_0_CID_VAL_MIN, TEL_AT_CGEQREQ_0_CID_VAL_MAX, TEL_AT_CGEQREQ_0_CID_VAL_DEFAULT) == TRUE) &&
				( cid > 0 ) && ( cid <= CI_PS_MAX_CID ))
            {
                ret = PS_ReadDynPara(atHandle, cid-1);
            }
			break;
		}

		case TEL_EXT_ACTION_CMD:   /* AT+CGCONTRDP */
		default:
		{
	        ret = ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
			break;
		}
	}


	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);

}


RETURNCODE_T ciAUTHReq(            const utlAtParameterOp_T op,
								   const char                      *command_name_p,
								   const utlAtParameterValue_P2c parameter_values_p,
								   const size_t num_parameters,
								   const char                      *info_text_p,
								   unsigned int                    *xid_p,
								   void                            *arg_p)
{
	UNUSEDPARAM(command_name_p);
	UNUSEDPARAM(num_parameters);
	UNUSEDPARAM(info_text_p);
	UNUSEDPARAM(arg_p);
	RETURNCODE_T rc = INITIAL_RETURN_CODE;
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimAuthenticateReq authReq;

	CHAR                     usernameVal[TEL_AT_AUTH_2_USERNAME_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH];//CI Limit for User name and password is 50
	CHAR                     passwordVal[TEL_AT_AUTH_3_PASSWORD_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH];//CI Limit for User name and password is 50
	INT32                    cid=0;
	INT32                    authType=0;
	INT16                    strLenUserName = 0, strLenPassword = 0;

	UINT32 atHandle = MAKE_AT_HANDLE( *(TelAtParserID *)arg_p );
	*xid_p = atHandle;
	BOOL cmdValid = FALSE;
#ifdef LWIP_IPNETBUF_SUPPORT
	telPsPdpAuth       pdpAuthInfo = {0};

#if QUEC_DUAL_SIM_SUPPORT
    TelAtParserID      send_atp=GET_SIM1_FLAG(atHandle)?TEL_AT_CMD_ATP_QUEC_INTERNAL_SIM2:TEL_AT_CMD_ATP_QUEC_INTERNAL_SIM1;
#else
    TelAtParserID      send_atp=TEL_AT_CMD_ATP_QUEC_INTERNAL_SIM1;
#endif

#endif

	memset(&authReq, 0, sizeof(authReq));
	memset(usernameVal, 0, sizeof(usernameVal));
	memset(passwordVal, 0, sizeof(passwordVal));

	//ATDBGMSG(atcmdsrv,278,"%s: atHandle = %d.\n", __FUNCTION__, atHandle);
	
	switch (op)
	{
		case TEL_EXT_GET_CMD:    /* AT*AUTHReq?  */
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL );
			break;
		}
		case TEL_EXT_TEST_CMD:	 /* AT*AUTHReq=?  */
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"*AUTHReq: <cid>,<type>(0-None;1-PAP;2-CHAP;3-PAP/CHAP),<UserName>,<Password>\r\n");
			break;
		}
		case TEL_EXT_SET_CMD:      /* AT*AUTHReq= */
		{
			if( getExtValue( parameter_values_p, 0, (int *)&cid, TEL_AT_AUTH_0_CID_VAL_MIN, TEL_AT_AUTH_0_CID_VAL_MAX, TEL_AT_AUTH_0_CID_VAL_DEFAULT ) == TRUE )
			{
				cid--;
				authReq.cid = cid;
				if( getExtValue( parameter_values_p, 1, (int *)&authType, TEL_AT_AUTH_1_TYPE_VAL_MIN, TEL_AT_AUTH_1_TYPE_VAL_MAX, TEL_AT_AUTH_1_TYPE_VAL_DEFAULT ) == TRUE )
				{
					authReq.AuthenticationType = authType;
					if ( getExtString(parameter_values_p, 2, &usernameVal[0], TEL_AT_AUTH_2_USERNAME_STR_MAX_LEN, &strLenUserName, TEL_AT_AUTH_2_USERNAME_STR_DEFAULT) == TRUE )
					{
						if ( getExtString(parameter_values_p, 3, &passwordVal[0], TEL_AT_AUTH_3_PASSWORD_STR_MAX_LEN, &strLenPassword, TEL_AT_AUTH_3_PASSWORD_STR_DEFAULT) == TRUE )
						{
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
								
							cmdValid = TRUE;
							authReq.UserName.len = strLenUserName;
							strcpy((char *)authReq.UserName.valStr, (char *)usernameVal);
							authReq.Password.len = strLenPassword;
							strcpy((char *)authReq.Password.valStr, (char *)passwordVal);
#ifdef LWIP_IPNETBUF_SUPPORT
							pdpAuthInfo.defined = TRUE;
							pdpAuthInfo.authType = authType;
							if (pdpAuthInfo.authType != 0)
							{
								strcpy((char *)pdpAuthInfo.userName, (char *)usernameVal);
								strcpy((char *)pdpAuthInfo.password, (char *)passwordVal);
	#ifdef AUTH_PAP_CHAP_OPTIMIZE
								if (pdpAuthInfo.authType == CI_PS_AUTHENTICATION_TYPE_PAP)
									pdpAuthInfo.authType = CI_PS_AUTHENTICATION_TYPE_PAP_CHAP;
								else if (pdpAuthInfo.authType == CI_PS_AUTHENTICATION_TYPE_CHAP)
									pdpAuthInfo.authType = CI_PS_AUTHENTICATION_TYPE_CHAP_PAP;
	#endif
							}					
#ifdef QUECTEL_AUTH_PARAM_SAVE_SUPPORT
							char set_buf[520]={0};
#ifdef QUEC_APPTCPIP_SUPPORT
							quec_pdp_profile  pdp_profile;
							memset(&pdp_profile, 0, sizeof(quec_pdp_profile));
							quec_net_get_pdp_profile(authReq.cid+1, &pdp_profile);
						
							pdp_profile.auth_type = authReq.AuthenticationType;
						
#ifdef QUEC_PATCH_1802S_AUTHREQ_SIZE128_12808
							memset(pdp_profile.user_name, 0, QUEC_USERPWD_PROFILE_SIZE);
							memset(pdp_profile.password, 0, QUEC_USERPWD_PROFILE_SIZE);
#else
							memset(pdp_profile.user_name, 0, 128);
							memset(pdp_profile.password, 0, 128);
#endif
							strcpy(pdp_profile.user_name, authReq.UserName.valStr);
							strcpy(pdp_profile.password, authReq.Password.valStr);
							quec_net_set_pdp_profile(authReq.cid+1, &pdp_profile);
#endif
							Network_Info_Log("cid=%d ,info_text_p =%s",authReq.cid+1,info_text_p);

							#if defined QUECTEL_PROJECT_CUST
							memset(&quec_pdpauthinfo, 0, sizeof(quec_pdpauthinfo));

							quec_pdpauthinfo.authReq_backup.cid = authReq.cid;
							quec_pdpauthinfo.info_text_p_backup = info_text_p;

							quec_pdpauthinfo.setDefPdpAuthReq_backup.authInfoPresent = TRUE;
							quec_pdpauthinfo.setDefPdpAuthReq_backup.authenticationType = pdpAuthInfo.authType;
							quec_pdpauthinfo.setDefPdpAuthReq_backup.userName = authReq.UserName;
							quec_pdpauthinfo.setDefPdpAuthReq_backup.password = authReq.Password;
							#endif

#endif
							/*redefined the APN info, record and return OK*/
							telSetPdpCtxAuthDS(atHandle, cid, &pdpAuthInfo);
#endif
							ret = PS_SendAUTHReq(atHandle,&authReq);
}//MiniSystem
else
{
							cmdValid = TRUE;
							authReq.UserName.len = strLenUserName;
							strcpy((char *)authReq.UserName.valStr, (char *)usernameVal);
							authReq.Password.len = strLenPassword;
							strcpy((char *)authReq.Password.valStr, (char *)passwordVal);
#ifdef LWIP_IPNETBUF_SUPPORT
							pdpAuthInfo.defined = TRUE;
							pdpAuthInfo.authType = authType;
							if (pdpAuthInfo.authType != 0)
							{
								strcpy((char *)pdpAuthInfo.userName, (char *)usernameVal);
								strcpy((char *)pdpAuthInfo.password, (char *)passwordVal);
								#ifdef AUTH_PAP_CHAP_OPTIMIZE
								if (pdpAuthInfo.authType == CI_PS_AUTHENTICATION_TYPE_PAP)
									pdpAuthInfo.authType = CI_PS_AUTHENTICATION_TYPE_PAP_CHAP;
								else if (pdpAuthInfo.authType == CI_PS_AUTHENTICATION_TYPE_CHAP)
									pdpAuthInfo.authType = CI_PS_AUTHENTICATION_TYPE_CHAP_PAP;
								#endif
							}
							/*redefined the APN info, record and return OK*/
							telSetPdpCtxAuthDS(atHandle, cid, &pdpAuthInfo);
#endif
							ret = PS_SendAUTHReq(atHandle,&authReq);

}
#endif /*MIN_SYS*/
						}
					}
				}
			}

			if(!cmdValid)
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL );
			break;
		}
		case TEL_EXT_ACTION_CMD:   /* AT*AUTHReq */
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL );
			break;
		}
		default:
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL );
			break;
		}


	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);
}

/************************************************************************************
 * F@: ciCGDFAUTH - GLOBAL API for AT*CGDFAUTH -command
 *
 */
RETURNCODE_T  ciCGDFAUTH(    const utlAtParameterOp_T op,
				     const char                      *command_name_p,
				     const utlAtParameterValue_P2c parameter_values_p,
				     const size_t num_parameters,
				     const char                      *info_text_p,
				     unsigned int                    *xid_p,
				     void                            *arg_p)
{
	UNUSEDPARAM(command_name_p)
	UNUSEDPARAM(num_parameters)
	UNUSEDPARAM(info_text_p)

	RETURNCODE_T rc = INITIAL_RETURN_CODE;
	CiReturnCode ret = CIRC_FAIL;
	INT32 mode = 0;
	INT32 authProt = 0;
	CHAR username[TEL_AT_CGDFAUTH_2_USERNAME_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH] = "";
	CHAR password[TEL_AT_CGDFAUTH_3_PASSWORD_STR_MAX_LEN + ATCI_NULL_TERMINATOR_LENGTH] = "";
	INT16 tmpStrLen = 0;
	CiPsPrimSetDefaultPdpAuthenticateReq setDefPdpAuthReq;
	UINT32 atHandle = MAKE_AT_HANDLE(*(TelAtParserID *)arg_p);
	*xid_p = atHandle;

	switch ( op )
	{
		case TEL_EXT_SET_CMD:
		{
			int i;
			BOOL setMode = FALSE;
			if (getExtValue(parameter_values_p, 0, (int *)&mode, TEL_AT_CGDFAUTH_0_MODE_VAL_MIN, TEL_AT_CGDFAUTH_0_MODE_VAL_MAX, TEL_AT_CGDFAUTH_0_MODE_VAL_DEFAULT) == TRUE )
			{
				setDefPdpAuthReq.modeType = mode;
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}


			for(i = 1 ; i < TEL_AT_CGDFAUTH_PARAM_MAX_COUNT ; i++)
			{
				if(parameter_values_p[i].is_default == FALSE)
				{
					setMode = TRUE;
					break;
				}
			}

			if(!setMode)
			{
				ret = PS_GetDefaultPdpAuthenticate(atHandle, mode);
				break;
			}


			if (getExtValue(parameter_values_p, 1, (int *)&authProt, TEL_AT_CGDFAUTH_1_AUTHPROT_VAL_MIN, TEL_AT_CGDFAUTH_1_AUTHPROT_VAL_MAX, TEL_AT_CGDFAUTH_1_AUTHPROT_VAL_DEFAULT) == TRUE )
			{
				setDefPdpAuthReq.authenticationType = authProt;
#ifdef AUTH_PAP_CHAP_OPTIMIZE
				if (setDefPdpAuthReq.authenticationType == CI_PS_AUTHENTICATION_TYPE_PAP)
					setDefPdpAuthReq.authenticationType = CI_PS_AUTHENTICATION_TYPE_PAP_CHAP;
				else if (setDefPdpAuthReq.authenticationType == CI_PS_AUTHENTICATION_TYPE_CHAP)
					setDefPdpAuthReq.authenticationType = CI_PS_AUTHENTICATION_TYPE_CHAP_PAP;
#endif
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}

			if ( getExtString(parameter_values_p, 2, username, TEL_AT_CGDFAUTH_2_USERNAME_STR_MAX_LEN, &tmpStrLen, TEL_AT_CGDFAUTH_2_USERNAME_STR_DEFAULT) == TRUE )
			{
				setDefPdpAuthReq.userName.len = tmpStrLen;
				strcpy((char *)setDefPdpAuthReq.userName.valStr, (char *)username);
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}

			if ( getExtString(parameter_values_p, 3, password, TEL_AT_CGDFAUTH_3_PASSWORD_STR_MAX_LEN, &tmpStrLen, (CHAR *)TEL_AT_CGDFAUTH_3_PASSWORD_STR_DEFAULT) == TRUE )
			{
				setDefPdpAuthReq.authInfoPresent = TRUE;
				setDefPdpAuthReq.password.len = tmpStrLen;
				strcpy((char *)setDefPdpAuthReq.password.valStr, (char *)password);
			}
			else
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}
#ifndef MIN_SYS		
			if (!IsMiniSystem())
			{
			#if 0
				extern char mob_sw_rev[];
				if(strstr(mob_sw_rev, "CIVER"))
				{
			#endif
					extern int QuecSetDefaultPdpFlag;
					if(QuecSetDefaultPdpFlag == 0) 
					{
						ret = PS_SetDefaultPdpAuthenticate(atHandle, &setDefPdpAuthReq);
					}
					else
					{
						CPUartLogPrintf("The CI request of the same type has been sent,Reject!");
						QuecSetDefaultPdpFlag = 0;
						ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, 0);
					}
			#if 0	
				}
				else 
				{
					ret = PS_SetDefaultPdpAuthenticate(atHandle, &setDefPdpAuthReq);
			}
			#endif
			}
			else 
			{
				ret = PS_SetDefaultPdpAuthenticate(atHandle, &setDefPdpAuthReq);
			}
#else
			ret = PS_SetDefaultPdpAuthenticate(atHandle, &setDefPdpAuthReq);
#endif
			break;
		}

		case TEL_EXT_GET_CMD:

			ret = PS_GetDefaultPdpAuthenticate(atHandle, 1);
			break;

		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
			break;
	}
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);
}

#ifndef MORE_ATC_SPACE_OPT
/**
* type: 0 - CREG, 1 - CGREG,  2- CEREG
*/
int getRegOptionPersist(int type)
{
#ifndef TEL_REG_OPTION_PERSIST
    return CI_PS_NW_REG_IND_ENABLE_DETAIL;
#else
    char *str = NULL;
    char reg_opt[16] = { 0 };
    int option = 2;
    
    if (type < 0 || type > 2)
        return -1;
        
    snprintf(reg_opt, sizeof(reg_opt) - 1, "reg_opt%d", type);
    str = psm_get_wrapper("wan", NULL, reg_opt);
    if (str)
    {
        option = atoi(str);
        free(str);
    }

    return option;
#endif
}

/**
* type: 0 - CREG, 1 - CGREG,  2- CEREG
*/
void setRegOptionPersist(int type, int option)
{
#ifndef TEL_REG_OPTION_PERSIST
    return;
#else
    char reg_opt[16] = { 0 };
    char opt_str[4] = { 0 };

    if ((type < 0 || type > 2) || option > CI_PS_NW_REG_IND_ENABLE_MORE_DETAIL)
        return;

    if (option != getRegOptionPersist(type))
    {
        snprintf(reg_opt, sizeof(reg_opt) - 1, "reg_opt%d", type);
        snprintf(opt_str, sizeof(opt_str) - 1, "%d", option);

        psm_set_wrapper("wan", NULL, reg_opt, opt_str);
        psm_commit__();
        //ATDBGMSG(atcmdsrv,279,"%s: set option %d for type %d done", __func__, option, type);
    }
#endif
}

/************************************************************************************
 * F@: ciRegOption - GLOBAL API for GCF AT*REGOPT  -command
 *
 */
RETURNCODE_T  ciRegOption(const utlAtParameterOp_T op,
    const char                      *command_name_p,
    const utlAtParameterValue_P2c   parameter_values_p,
    const size_t                    num_parameters,
    const char                      *info_text_p,
    unsigned int                    *xid_p,
    void                            *arg_p)
{
    RETURNCODE_T    rc = INITIAL_RETURN_CODE;
    CiReturnCode    ret = CIRC_FAIL;
    UINT32          atHandle = MAKE_AT_HANDLE(* (TelAtParserID *) arg_p);

    *xid_p = atHandle;
    char tmpBuf[100];

    /*
         **  Check the operation type.
         */
    switch( op )
    {
        case TEL_EXT_TEST_CMD:    /* AT*REGOPT=? */
        {
			memset(tmpBuf, 0, sizeof(tmpBuf));
			sprintf((char *)tmpBuf, "*REGOPT: (0-3)\r\n");
            ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)tmpBuf);
            break;
        }

        case TEL_EXT_SET_CMD:     /* AT*REGOPT= */
        {
            INT32  regParam;
            int option;

            if ( getExtValue( parameter_values_p, 0, (int *)&regParam, 0, 2, 2) == TRUE )
			{
			    option = getRegOptionPersist(regParam);

			    if (option < 0 || option > CI_PS_NW_REG_IND_ENABLE_MORE_DETAIL)
			    {
			        ret = ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_INVALID_PARAM,NULL);
			    }
			    else
			    {
			        memset(tmpBuf, 0, sizeof(tmpBuf));
			        sprintf((char *)tmpBuf, "*REGOPT: %d\r\n", option);
			        ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)tmpBuf);
			    }
            }
            else
            {
                ret = ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_OPERATION_NOT_SUPPORTED,NULL);
            }

            break;
        }
        case TEL_EXT_GET_CMD:
        case TEL_EXT_ACTION_CMD: 
        default:
        {
            ret = ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_OPERATION_NOT_SUPPORTED,NULL);
            break;
        }
    }


    /* handle the return value */
    rc = HANDLE_RETURN_VALUE(ret);
    return(rc);
}
#else
void setRegOptionPersist(int type, int option)
{
}
#endif

#ifdef QUEC_MINI_SYSTEM_SUPPORT	
/*===========================================================================

FUNCTION QUEC_BASIC_ATI_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes I command.
  This command returns identification information.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
	utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
#include "quec_ver_inc.h"
#include "quectel_version.h"

#ifndef MIN_SYS
#ifdef QUECTEL_OPEN_CPU
#include "ql_cust_version.h"
#endif
#endif

RETURNCODE_T  quec_basic_ati_cmd
(
	const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
	const char					  *command_name_p,	  /* AT cmd name		  */
	const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */
	const size_t				   num_parameters,	  /* AT cmd number		  */
	const char					  *info_text_p, 	  /* AT cmd usage string  */
	unsigned int				  *xid_p,			  /* AT cmd handle		  */
	void						  *arg_p			  /* AT cmd parser number */
)
{
	UNUSEDPARAM(command_name_p)
	UNUSEDPARAM(info_text_p)

	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32		  atHandle	= MAKE_AT_HANDLE(sAtpIndex);
	RETURNCODE_T  ret		= utlSUCCESS;
	*xid_p = atHandle;

	char *moduleInfo = NULL;
	int verinfo_len;

    #ifndef MIN_SYS
	#ifdef QUECTEL_OPEN_CPU
    verinfo_len = strlen(mob_usb_manufacturer)+strlen(mob_model_id)+strlen(mob_sw_rev)+sizeof(mob_cust_rev)+20;
    #else
    verinfo_len = strlen(mob_usb_manufacturer)+strlen(mob_model_id)+strlen(mob_sw_rev)+20;
    #endif
	#else
    verinfo_len = strlen(mob_usb_manufacturer)+strlen(mob_model_id)+strlen(mob_sw_rev)+20;
    #endif
	moduleInfo = (char *)malloc(verinfo_len);
	ATDBGMSG("%s: mob_usb_manufacturer:%s  mob_model_id:%s mob_sw_rev:%s\n", __FUNCTION__, mob_usb_manufacturer,mob_model_id,mob_sw_rev);
	memset(moduleInfo,0,verinfo_len);
	if (NULL != moduleInfo)
	{
		/* get module information */
#if defined(__QUEC_OEM_VER_NL__)
		if (parameter_values_p->value.decimal == 8)
		{
			snprintf(moduleInfo, verinfo_len, "\"%s\"", mob_sw_rev);
		}
		else
#endif
		{
			if(IsMiniSystem())
			{
				 snprintf(moduleInfo,
				 verinfo_len,
				 "%s\r\n%s_Mini\r\nRevision: %s",
				 mob_usb_manufacturer,	/*get manufacturer information	*/
				 mob_model_id,			/*get module information		*/
				 mob_sw_rev 			/*get revision information		*/
				 );
			}
			else
			{   
                #ifndef MIN_SYS
				#ifdef QUECTEL_OPEN_CPU
                if(strlen(mob_cust_rev)>0)
                {
                    snprintf(moduleInfo,
                            verinfo_len,
                            "%s\r\n%s\r\nRevision: %s\r\nCustRevision:%s",
                            mob_usb_manufacturer,  /*get manufacturer information  */
							#ifdef QUEC_CUST_BL_PROJ //宝蓝客户定制mob_model_id为EC600N
							"EC600N",
							#else
                            mob_model_id,           /*get module information        */
                            #endif
                            mob_sw_rev,             /*get revision information      */
                            mob_cust_rev             /*get custmer information      */
                            );
                }
                else
				#endif
                #endif
                {
					#ifdef QUEC_CUST_BL_PROJ //宝蓝客户定制mob_model_id为EC600N
						snprintf(moduleInfo,
                            verinfo_len,
                            "%s\r\n%s\r\nRevision: %s",
                            mob_usb_manufacturer,  /*get manufacturer information  */
                            "EC600N",          /*get module information        */
                            mob_sw_rev             /*get revision information      */
                            );
					#else
                    	snprintf(moduleInfo,
                            verinfo_len,
                            "%s\r\n%s\r\nRevision: %s",
                            mob_usb_manufacturer,  /*get manufacturer information  */
                            mob_model_id,          /*get module information        */
                            mob_sw_rev             /*get revision information      */
                            );
					#endif
                }

			}

		}

		/*return the result code and response to the terminal */
		ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, moduleInfo);
		free(moduleInfo);
	}
	else
	{
		ret = ATRESP( atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
	}

	return utlSUCCESS;
}
#endif


