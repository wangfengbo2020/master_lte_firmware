/*================================================================
  Copyright (c) 2020 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
10/16/2020        Evan      Init version
05/07/2022        Sharon.li 此文件为STD项目的应用层代码，Cmaera的打开，关闭，扫码的开启与关闭
=================================================================*/
 
#include "quec_cust_feature.h"
#ifdef QUEC_CAMMERA_DECODE_AUTHORIZATION
#include <osa.h>
#include "quec_camera.h"
#include "quec_include.h"
#include "string.h"
#include "telatci.h"
#include "string_utils.h"
#include "quec_atcmd_camera.h"
#include "teldef.h"

extern bool quectel_egmr_set_qrlience(char *qrcode_info);
extern bool quectel_egmr_get_qrlience(char *qrcode_info);

extern BOOL getExtValue( const utlAtParameterValue_P2c param_value_p,
		int index,
		int *value_p,
		int minValue,
		int maxValue,
		int DefaultValue);




extern BOOL getExtString ( const utlAtParameterValue_P2c param_value_p,
		int index,
		CHAR *outString,
		INT16 maxStringLength,
		INT16 *outStringLength,
		CHAR *defaultString);

RETURNCODE_T quectel_qauthcode_cmd
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
 
    
    RETURNCODE_T     rc       = INITIAL_RETURN_CODE;
    CiReturnCode  ret = CIRC_FAIL;
	
	UINT32 atHandle = MAKE_AT_HANDLE(* (TelAtParserID *) arg_p);
    *xid_p = atHandle;
	
	int decode_sta = 0;
    char res_buf[2048]={0};
    UINT8 param_num=0;
    int param[3] = {0};
    INT16 len = 0;
    char strdata[1024]={0};
    char qrdata[1024] = {0};
    char string[1024] = {0};
    param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
    
    switch(op)
    {
        case TEL_EXT_GET_CMD:
           
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0,NULL);
			break;
            
        case TEL_EXT_SET_CMD:
            if(param_num == 1)
            {
                if( getExtValue( parameter_values_p, 0, &param[0], 1, 3, 1) == FALSE )
    			{
                  	ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 1, NULL);
    				break; 
                }
                else
                {
                 
                  if(param[0]==3)
                    {
						decode_sta = ql_get_decode_statue();		//Fias.fan 2022.03.15 add AT+QAUTHCODE=3 status info
						sprintf(res_buf,"+QAUTHCODE: %d\r\n",decode_sta);
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, res_buf);

        				break;
                    }
                  else
                      {
                        ret = ATRESP( atHandle,  ATCI_RESULT_CODE_CME_ERROR, 2,NULL);
                        
        				break;
                      }
                }
                
            }
            else if(param_num == 2)
            {
                if( getExtValue( parameter_values_p, 0, &param[0], 1, 3, 1) == FALSE )
    			{
                    ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 3, NULL);
    			    break; 
                }
                else
                {
                    if(param[0] == 1)
                    {
                        if(getExtValue( parameter_values_p, 1, &param[1], 1, 1016, 1016) == FALSE)
                        {
                            ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 4, NULL);
                            break; 
                        }
                        else
                        {
                            if(param[1] != 0)
                            {
                                quectel_egmr_get_qrlience(strdata);
                                memcpy(qrdata, strdata, param[1]);
                                sprintf(res_buf,"+QAUTHCODE: \"%s\"\r\n",qrdata);
                                ret=ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0,res_buf);
                                break;
                            }
                            else
                            {
                                ret = ATRESP(atHandle,ATCI_RESULT_CODE_CME_ERROR, 5, NULL);
                                break; 
                            }
                        }
                    }
                    else
                    {
                       ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR,6, NULL);
                       break;  
                    }
                }
                
            }
            else if(param_num == 3)
            {
               if(getExtValue( parameter_values_p, 0, &param[0], 1, 1016, 1016) == FALSE)
               {
                    ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 7, NULL);
                    break;
               }
               else
               {
                    if(param[0] == 2)
                    {
                          if( getExtValue( parameter_values_p, 1, &param[1], 1, 1016, 1016) == FALSE )
                          {
                            ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 8, NULL);
                            break;
                          }
                          else
                          {
                             if(param[1] != 0)
                             {
                                if( getExtString( parameter_values_p, 2, string, 1024,&len, NULL) == FALSE )
                                {
                                    ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 9, NULL);
                                    break; 
                                }
                                else
                                {
                                   if((string != NULL)&&(len==param[1])) //Fias.fan 20220315 only allow len==param[1]
                                        {
                                            memcpy(strdata, string, len);
                                            quectel_egmr_set_qrlience(strdata);
                                            memset(strdata,0,sizeof(strdata));
                                            quectel_egmr_get_qrlience(strdata);
                                            memcpy(qrdata, strdata, len);
                                            sprintf(res_buf,"+QAUTHCODE: \"%s\"\r\n",qrdata);
                                            ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0,res_buf);
                                            break;
                                        }
                                    else
                                   {
                                      ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 10, NULL);
                    				  break; 
                                   }
                                }
                             }
                             else
                             {
                                ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 11, NULL);
                                break; 
                             }
                          }
                    }
                    else
                    {
                       ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 12, NULL);
                       break;
                    } 
               }
               
            }
            else
            {
                ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 13, NULL);
                break;
                
            }
        default:
        {
            ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, 14, NULL);
            break;
            
        }
    }
   rc = HANDLE_RETURN_VALUE(ret);
   return(rc);
}

extern unsigned long long Read_Crane_CPU_UID(void);

RETURNCODE_T quectel_get_uid_cmd
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
    RETURNCODE_T     rc       = INITIAL_RETURN_CODE;
    unsigned long long uid=0;

	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
	*xid_p = atHandle;

    CiReturnCode  ret = CIRC_FAIL;
    char res_buf[32]={0};
    switch(op)
    {
         
        case TEL_EXT_GET_CMD:/*AT+UID?*/
        {
            uid = Read_Crane_CPU_UID();
            sprintf(res_buf,"+QUID: %llu",uid);
			//ret= quec_siolib_transmit_to_atp((TelAtParserID)index,(uint8 *)res_buf,strlen(res_buf), NULL);			
            ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0,res_buf);	
            break;
        }   
       
       default:
        {
            ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
            break;
       }
    }
    
    rc = HANDLE_RETURN_VALUE(ret);
    return(rc);
}
#endif

#if defined QUEC_AT_CMD_CAMERA_SUPPORT

#include "quec_urc.h"
#include "quec_gpio.h"
#include "quec_siolib.h"
#include "quec_qr_code.h"




/*===========================================================================
 * Macro Definition
 ===========================================================================*/
#ifdef QUEC_ATCMD_LOG
	
	#define atcmd_camera_log(msg, ...)   custom_log("ATCMD_camera", msg, ##__VA_ARGS__);\
		

#endif




/*===========================================================================
 * Global Variable
 ===========================================================================*/ 

#define  quec_camera_none_error 0

#define  quec_camera_on 1
#define  quec_camera_off 0
#define  quec_cameraidfy_on 1
#define  quec_cameraidfy_off 0

bool quec_camera_onff_flag = quec_camera_off;

bool quec_cameraidfy_onff_flag = quec_cameraidfy_off;
int  quec_cameraidfy_auto_count = 0;
static quec_task_t  quec_camera_monitor_task = NULL;
static quec_flag_t  quec_camera_monitor_flag = NULL;
#define QUEC_CAM_AUTO_COLSE           	(0x01)
#define QUEC_CAM_MONITOR_MASK       	(QUEC_CAM_AUTO_COLSE)


int	camera_height=480;
int	camera_width=640;

#define success_decode 0
#define QUEC_NV_QCAMCFG  "quec_nv_qacmcfg"
typedef struct
{
	char CAM_Mode;
}CAM_CFG_PARAM;
QuecOSStatus quec_cameraidfy_auto_count_check(int *count);

static CAM_CFG_PARAM quec_camcfg_param;

static void cam_callback_preview(P_CAL_IDENTITY_RESULT_STRUCT outdata)
{
	char rsp_str[3072]={0};
	static int urc_count = 0;
	
	snprintf(rsp_str, 3072,"+QCAMPRES: %d,0,%d,%s\r\n",outdata->result,outdata->DecodeLen,outdata->DataBuf);

	at_urc_send(NUM_OF_TEL_ATP, (uint8 *)rsp_str, strlen(rsp_str), FALSE, URC_OUT_METHOD_UNICAST, NULL);

	urc_count++;
	quec_cameraidfy_auto_count_check(&urc_count);

}


int quec_qcam_cfg_set(CAM_CFG_PARAM *param)
{
    int fat_ret = QUEC_FAT_FAILED;

    fat_ret = quectel_nv_fat_write(QUEC_NV_QCAMCFG, param, sizeof(CAM_CFG_PARAM));
    if (QUEC_FAT_SUCCESS != fat_ret)
    {
        atcmd_camera_log("quec_camcfg_set err=%d", fat_ret);    
    }
	
    return fat_ret;
}

CAM_CFG_PARAM *quec_qcam_cfg_get(void)
{
	int fat_ret = QUEC_FAT_FAILED;
    
    fat_ret = quectel_nv_fat_read(QUEC_NV_QCAMCFG, &quec_camcfg_param, sizeof(CAM_CFG_PARAM));
    if (QUEC_FAT_SUCCESS != fat_ret)
    {
        atcmd_camera_log("quec_camcfg_set err=%d", fat_ret); 
    }	
    return &quec_camcfg_param;
}

RETURNCODE_T  quec_exec_qcamiic_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
)
{
	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
	RETURNCODE_T ret = utlSUCCESS;
	unsigned int sensor_addr=0,val = 0;
	int error=0;
	uint8 num_param = quec_get_at_param_num(parameter_values_p, num_parameters);
	*xid_p = atHandle;
	atcmd_camera_log("op=%d, num_param=%d\n", op, num_param);	
	CAM_CFG_PARAM *param;
	CHAR  RegAddr[12] = {'\0'};
	INT16 RegAddrLen;
	CHAR  RegData[12] = {'\0'};
	UINT16 RegDataLen;
	CHAR  aString[2];
	UINT32 UIN32_RegAddr =0;
	UINT32 UIN32_RegData =0;
	char *str;
	char   Buf[50];
	INT16 aStringLen;
	switch (op)
	{
		case TEL_EXT_SET_CMD:
		
			if (getExtString(parameter_values_p, 0, aString, 1, &aStringLen, NULL) == TRUE )
			{
				if ( !strcmp(aString,"r") || !strcmp(aString,"R"))
				{
					// This is write request
					// get write parameters
					if (getExtString( parameter_values_p, 1, RegAddr, 10,&RegAddrLen, 0) == TRUE )
					{
						UIN32_RegAddr = strtoul(RegAddr,&str,16);
						
						ret = ql_cam_i2c_read(UIN32_RegAddr,&UIN32_RegData);
						
						sprintf(Buf,"*REGRW: %1x, %1x",UIN32_RegAddr,UIN32_RegData);
						ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,Buf);
					}
					else
					{
						ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_INVALID_PARAM,NULL);
					}

				}
				else if ( !strcmp(aString,"w")|| !strcmp(aString,"W"))
				{
					// This is a read request with version and date
					if (getExtString( parameter_values_p, 1, RegAddr, 10, &RegAddrLen, 0) == TRUE )
					{
						if (getExtString( parameter_values_p, 2, RegData, 10, (INT16 *)&RegDataLen, 0) == TRUE )
						{
							UIN32_RegAddr = strtoul(RegAddr,&str,16);
							UIN32_RegData = strtoul(RegData,&str,16);
							ql_cam_i2c_write(UIN32_RegAddr,UIN32_RegData);
							ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,0);
						}
						else
						{
							ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_INVALID_PARAM,NULL);

						}
					}
					else
					{
						ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_INVALID_PARAM,NULL);
					}
				}
				else
				{
					ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_INVALID_PARAM,NULL);
				}
			}
			else
			{
				ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_INVALID_PARAM,NULL);
			}

			break;
		
		case TEL_EXT_ACTION_CMD:

			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
			break;
		case TEL_EXT_GET_CMD:

			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
			break;
		case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, "+QCAMOPEN: (0-1),(50-640)");
			break;
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
			break;
	}
	return ret;
}


/*===========================================================================

FUNCTION quec_exec_qcamopen_cmd

DESCRIPTION
  at+qcamopen

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
extern unsigned char camCoreInit;
RETURNCODE_T  quec_exec_qcamopen_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
)
{
	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
	RETURNCODE_T ret = utlSUCCESS;

	int error=0;
	uint8 num_param = quec_get_at_param_num(parameter_values_p, num_parameters);
	*xid_p = atHandle;
	atcmd_camera_log("op=%d, num_param=%d\n", op, num_param);	
	CAM_CFG_PARAM *param;
	switch (op)
	{
		case TEL_EXT_SET_CMD:
		
			if (2 == num_param)
			{
				if (getExtValue(parameter_values_p, 0, &camera_height, 50, 480, 480) == FALSE)
				{
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
					break;
				}
				
				if (getExtValue(parameter_values_p, 1, &camera_width, 50, 640, 640) == FALSE)
				{
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
					break;
				}
				
				if(quec_camera_onff_flag == quec_camera_off)
				{
				    quec_camera_onff_flag = quec_camera_on;
					error=quec_camera_open();//open camera function
					
					if (error != quec_camera_none_error)
					{
					    camCoreInit=0;
						quec_camera_close(); //close camera function
						quec_camera_onff_flag = quec_camera_off;
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, QUEC_CAM_OPEN_ERROR, NULL);
						break;

					}										
					param = quec_qcam_cfg_get();
					ql_set_decode_mirror(param->CAM_Mode);
					
				}
				
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
				break;
			}

			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			break;
		
		case TEL_EXT_ACTION_CMD:

			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
			break;
		case TEL_EXT_GET_CMD:

			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
			break;
		case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, "+QCAMOPEN: (50-480),(50-640)");
			break;
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
			break;
	}
	return ret;
}
/*===========================================================================

FUNCTION quec_qcamidfy_close_auto

DESCRIPTION
  at+qcamidfy

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
int quec_get_reload_count_urc(void)
{
	return quec_cameraidfy_auto_count;
}


QuecOSStatus quec_camera_monitor_process_event_send(int event)
{
	atcmd_camera_log("camera monitor event 0x%x",event);
	if(!quec_camera_monitor_flag)
	{
		atcmd_camera_log("flag not init!!!");
		return kGeneralErr;
	}
	return quec_rtos_flag_release(quec_camera_monitor_flag, event, QUEC_FLAG_OR);
}

void quec_camera_monitor_thread(void * argv)
{
	int ret = 0;
	UINT32 event = 0;
	while(1)
	{		
		OSAFlagWait(quec_camera_monitor_flag, QUEC_CAM_MONITOR_MASK, OSA_FLAG_OR_CLEAR, &event, OSA_SUSPEND); 
		atcmd_camera_log("camera monitor event 0x%x",event);
		if(event & QUEC_CAM_AUTO_COLSE)
		{
			if((0 != quec_cameraidfy_auto_count)&&( quec_camera_on == quec_camera_onff_flag))
			{
				quec_camera_full_stream_stop();
				quec_cameraidfy_onff_flag = quec_camera_off;
				quec_cameraidfy_auto_count = 0;
			}
		}
	}
}

QuecOSStatus quec_camera_monitor_task_init(bool onff)
{
    QuecOSStatus ret = QUEC_SUCCESS; 
	if(onff)
	{
		if((NULL == quec_camera_monitor_task)&&(NULL == quec_camera_monitor_flag))
	    {
	    	ret = quec_rtos_flag_create(&quec_camera_monitor_flag);
			if(ret != OS_SUCCESS)
	    	{
	            atcmd_camera_log("creat flag fail");
	    		goto exit;
	    	} 
	        ret = quec_rtos_task_create(&quec_camera_monitor_task, 4*1024, QUEC_APP_TASK_PRIORITY, "cam_monitor", quec_camera_monitor_thread, NULL);
	        if(ret != OS_SUCCESS)
	    	{
	            atcmd_camera_log("creat task fail");
	    		goto exit;
	    	}    
	    }
	}
	else
	{
		if((NULL != quec_camera_monitor_task)||(NULL != quec_camera_monitor_flag))
	    {
	    	ret = quec_rtos_flag_delete(quec_camera_monitor_flag);
			if(ret != OS_SUCCESS)
	    	{
	            atcmd_camera_log("delete flag fail");
	    		goto exit;
	    	} 
	        ret = quec_rtos_task_delete(quec_camera_monitor_task);
	        if(ret != OS_SUCCESS)
	    	{
	            atcmd_camera_log("delete task fail");
	    		goto exit;
	    	}
			quec_camera_monitor_task = NULL;
			quec_camera_monitor_flag = NULL;
	    }

	}
	atcmd_camera_log("status:%d task:0x%x flag:0x%x",onff, quec_camera_monitor_task, quec_camera_monitor_flag);
    return ret;  
	exit:
	if(NULL != quec_camera_monitor_task)
    {
    	ret = quec_rtos_flag_delete(quec_camera_monitor_flag);
		if(ret != OS_SUCCESS)
    	{
            atcmd_camera_log("delete flag fail");
    		goto exit;
    	}    
    }
	if(NULL != quec_camera_monitor_flag)
	{
	    ret = quec_rtos_task_delete(quec_camera_monitor_task);
        if(ret != OS_SUCCESS)
    	{
            atcmd_camera_log("delete task fail");
    		goto exit;
    	} 
	}
	return ret;
}


QuecOSStatus quec_cameraidfy_auto_count_check(int *count)
{
	int reload_count = 0;
	int cerrent_count = *count;
	reload_count = quec_get_reload_count_urc();
	if((cerrent_count >= reload_count)&&(0 != reload_count))
	{
		atcmd_camera_log("cerrent_count %d, reload_count %d", cerrent_count, reload_count);
		quec_camera_monitor_process_event_send(QUEC_CAM_AUTO_COLSE);
		*count = 0;
	}
	return OS_SUCCESS;
}


/*===========================================================================

FUNCTION quec_exec_qcamidfy_cmd

DESCRIPTION
  at+qcamidfy

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/

RETURNCODE_T  quec_exec_qcamidfy_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
)
{
	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
	RETURNCODE_T ret = utlSUCCESS;
	int  quec_cameraidfy_onoff = 0;
	int  quec_cameraidfy_count = 0;
	uint8 num_param = quec_get_at_param_num(parameter_values_p, num_parameters);
	*xid_p = atHandle;
	atcmd_camera_log("op=%d, num_param=%d\n", op, num_param);	
	switch (op)
	{
		case TEL_EXT_SET_CMD:
		
			if (2 >= num_param)
			{
				if (getExtValue(parameter_values_p, 0, &quec_cameraidfy_onoff, 0, 1, 0) == FALSE)
				{
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 0, NULL);
					break;
				}
				if(2 == num_param)
				{
					if (getExtValue(parameter_values_p, 1, &quec_cameraidfy_count, 0, 65535, 0) == FALSE)
					{
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 0, NULL);
						break;
					}
				}
				if(quec_camera_onff_flag==quec_camera_on)
				{
				   if(quec_cameraidfy_onff_flag != quec_cameraidfy_onoff)
                   {
	                     quec_cameraidfy_onff_flag=quec_cameraidfy_onoff;
						 if(quec_cameraidfy_onoff==quec_cameraidfy_on)
						 {
						 	quec_cameraidfy_auto_count = quec_cameraidfy_count;
							if(quec_cameraidfy_auto_count)
							{
								quec_camera_monitor_task_init(quec_cameraidfy_on);
							}
							quec_camera_full_stream_start(camera_height,camera_width,cam_callback_preview);//cameraidfy on/off function
							
						 }
						 else if(quec_cameraidfy_onoff==quec_cameraidfy_off)
						 {
						 	quec_camera_full_stream_stop();
							if(quec_cameraidfy_auto_count)
							{
								quec_camera_monitor_task_init(quec_cameraidfy_off);
							}

						 }
						 
				  }
				  ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
				  break;			
					
				}
				
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
				break;
			}
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			break;
		
		case TEL_EXT_ACTION_CMD:

			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
			break;
		case TEL_EXT_GET_CMD:

			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
			break;
		case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, "+QCAMIDFY: (0,1)[,(0-65535)]");
			break;
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
			break;
	}
	return ret;
}

/*===========================================================================

FUNCTION quec_exec_qcamclose_cmd

DESCRIPTION
  at+qcamclose

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/


RETURNCODE_T  quec_exec_qcamclose_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
)
{
	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
	RETURNCODE_T ret = utlSUCCESS;


	*xid_p = atHandle;
	atcmd_camera_log("op=%d, num_param=%d\n", op);	
	switch (op)
	{
		case TEL_EXT_SET_CMD:			
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
			break;
		case TEL_EXT_ACTION_CMD:
			if((quec_camera_onff_flag == quec_camera_on)&&(quec_cameraidfy_onff_flag == quec_cameraidfy_off))
			{
			    quec_camera_onff_flag = quec_camera_off;
                quec_camera_close(); //close camera function
                ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
				break;
			}
		
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
			break;
		case TEL_EXT_GET_CMD:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			break;
		case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			break;
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
			break;
	}
	return ret;
}


/*===========================================================================

FUNCTION quec_exec_qcamcfg_cmd

DESCRIPTION
  at+qcammode

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_exec_qcamcfg_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
)
{
	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
	RETURNCODE_T ret = utlSUCCESS;
	int error=0;
	uint8 num_param = quec_get_at_param_num(parameter_values_p, num_parameters);
	*xid_p = atHandle;

	int32 at_val = 0;
	char rsp_buf[64] = {0};
	char str_buf[16] = {0};
	char str_buf_len = 0;
	atcmd_camera_log("op=%d, num_param=%d\n", op, num_param);	
	CAM_CFG_PARAM *param;
	switch (op)
	{
		case TEL_EXT_SET_CMD:
		
			if (2 == num_param)
			{			
				if( getExtString( parameter_values_p, 0, str_buf, sizeof(str_buf), &str_buf_len, NULL ) == FALSE)
				{
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, NULL, NULL);
					break;
				}
				if(0 == strcasecmp(str_buf,"qcammod"))
				{
					if (getExtValue(parameter_values_p, 1, &at_val, 0, 2, 0) == FALSE)
					{
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, NULL, NULL);
						break;
					}
					ql_set_decode_mirror(at_val);
					param = quec_qcam_cfg_get();
					if(at_val != param->CAM_Mode)
					{
						param->CAM_Mode = at_val;
						quec_qcam_cfg_set(param);
					}
					
				}
				else
				{
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, NULL, NULL);
					break;
				}
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
				break;
			}
			else if (1 == num_param)
			{
				if( getExtString( parameter_values_p, 0, str_buf, sizeof(str_buf), &str_buf_len, NULL ) == FALSE)
				{
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, NULL, NULL);
					break;
				}
				if(0 == strcasecmp(str_buf,"qcammod"))
				{
					param = quec_qcam_cfg_get();
					sprintf(rsp_buf,"+QCAMCFG: \"qcammod\",%d",param->CAM_Mode);
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, rsp_buf);
				}
				else
				{
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, NULL, NULL);
					break;
				}
			}
			break;
		
		case TEL_EXT_ACTION_CMD:

			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
			break;
		case TEL_EXT_GET_CMD:

			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
			break;
		case TEL_EXT_TEST_CMD:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
			break;
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
			break;
	}
	return ret;
}


/*===========================================================================

FUNCTION quec_exec_qcamgpio_cmd

DESCRIPTION
  at+qcamgpio

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/

RETURNCODE_T  quec_exec_qgpio_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
)
{
	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
	RETURNCODE_T ret = utlSUCCESS;
	char rsp_str[6] = {0};
	INT16 str_buf_len = 0;
	char camera_gpio[][6] = {{"GPIO1"},{"GPIO2"}};
	
	uint8 num=0;
	int  cameraGPIO_onoff=0;
	uint8 num_param = quec_get_at_param_num(parameter_values_p, num_parameters);
	*xid_p = atHandle;

	atcmd_camera_log("op=%d, num_param=%d\n", op, num_param);	

	unsigned long pin_mfprReg_data = 0;
	
	GPIO_PinConfiguration gpio_pin_config;



					
	switch (op)
	{
		case TEL_EXT_SET_CMD:
		
			if (2 == num_param)
			{
			 
				if (getExtString(parameter_values_p, 0, rsp_str, 6, &str_buf_len, NULL) == FALSE)
				{
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 0, NULL);
					break;
				}
			

				if (getExtValue(parameter_values_p, 1, &cameraGPIO_onoff, 0, 1, 0) == FALSE)
				{
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 0, NULL);
					break;
				}
				
				for(num=0;num<2;num++)
				{
					if(strcasecmp(rsp_str,camera_gpio[num])== 0)
					{
						atcmd_camera_log("num=%d,%s",num,camera_gpio[num]);
						break;
					}
				}
				if(num>=2)
				{
					atcmd_camera_log("not find at!!!");
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 0, NULL);
					break;
				}
			    if(num==0)
			    {

					gpio_pin_config.pinNumber=GPIO_PIN_33;
					gpio_pin_config.direction= GPIO_OUT_PIN; 
					gpio_pin_config.transitionType =GPIO_NO_EDGE;
					gpio_pin_config.debounce=GPIO_DEBOUNCE_DISABLE;
					gpio_pin_config.pullUpDown=(GPIOPullUpDown)GPIO_PULL_UP_DOWN_DISABLE;
					gpio_pin_config.initialValue=GPIO_INITIAL_VALUE_NO_CHANGE;
					
					pin_mfprReg_data  &=0xFFFFFFF8;
					
					
					
					if (QUEC_SUCCESS != quec_set_gpio_mfprReg(GPIO_PIN_33, pin_mfprReg_data))
					{
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}
					
					
					if (QUEC_SUCCESS != quec_gpio_config_set(&gpio_pin_config))
					{
					
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}
					
					if (QUEC_SUCCESS != quec_set_gpio_level((GPIO_PinNumbers)GPIO_PIN_33,(quec_pin_level_value_e)cameraGPIO_onoff))
					{
					
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}


			    }
		
				   
			    if(num==1)
			    {

					gpio_pin_config.pinNumber=GPIO_PIN_36;
					gpio_pin_config.direction= GPIO_OUT_PIN; 
					gpio_pin_config.transitionType =GPIO_NO_EDGE;
					gpio_pin_config.debounce=GPIO_DEBOUNCE_DISABLE;
					gpio_pin_config.pullUpDown=(GPIOPullUpDown)GPIO_PULL_UP_DOWN_DISABLE;
					gpio_pin_config.initialValue=GPIO_INITIAL_VALUE_NO_CHANGE;
					
					pin_mfprReg_data  &=0xFFFFFFF8;
					
					
					
					if (QUEC_SUCCESS != quec_set_gpio_mfprReg(GPIO_PIN_36, pin_mfprReg_data))
					{
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}
					
					
					if (QUEC_SUCCESS != quec_gpio_config_set(&gpio_pin_config))
					{
					
						ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}
					
					if (QUEC_SUCCESS != quec_set_gpio_level((GPIO_PinNumbers)GPIO_PIN_36,(quec_pin_level_value_e)cameraGPIO_onoff))
					{
					
							ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
							break;
					}


			    }

				
			
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
					break;	

				
			}
	
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, 0, NULL);
			break;
		
		case TEL_EXT_ACTION_CMD:

			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
			break;
		case TEL_EXT_GET_CMD:

			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
			break;
		case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, "+QCAMGPIO: (GPIO1,GPIO2),(0,1)");
			break;
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
			break;
	}
	return ret;
}


/*===========================================================================

FUNCTION quec_exec_qcamappver_cmd

DESCRIPTION
  at+qcamappver

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/

RETURNCODE_T  quec_exec_qcamappver_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
)
{
	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
	RETURNCODE_T ret = utlSUCCESS;
	char cam_version[64]={0};
	char cam_ver[64]={0};
	*xid_p = atHandle;
	atcmd_camera_log("op=%d, num_param=%d\n", op);	
	switch (op)
	{
		case TEL_EXT_GET_CMD:
		case TEL_EXT_SET_CMD:			
		case TEL_EXT_ACTION_CMD:
			Ql_Cam_Decode_Version((unsigned char *)cam_version,64);
			sprintf(cam_ver,"+QCAMAPPVER: \"%s\"",cam_version);
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL, cam_ver);
			break;
		case TEL_EXT_TEST_CMD:
            ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			break;
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
			break;
	}
	return ret;

}






#endif














































