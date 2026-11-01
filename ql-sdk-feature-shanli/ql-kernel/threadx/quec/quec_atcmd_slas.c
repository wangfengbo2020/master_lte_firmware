#include "quec_cust_feature.h"
#if defined(QUEC_CAMMERA_DECODE_AUTHORIZATION)||defined(QUEC_AUDIO_DENOISE)

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include "quec_common.h"
#include "quec_slas.h"
#include "quec_atcmd_slas.h"
#include "quec_include.h"
#include "telatci.h"

#ifdef QUEC_SLAS_SUPPORT
#define license_printf(msg, ...)  do { custom_log("SLAS", msg, ##__VA_ARGS__);\
		}while(0); 

extern void RTI_LOG(const char* fmt, ...);
#define TOTAL_DATA_LENGTH                  2048
#define CPU_ID_LENGTH                      15
#define DIGEST_LENGTH                      128
#define DEV_LENGTH                         48
#define RETURN_STRING_LENGTH               256
#define APPID_MAX_LENGTH                   2000

typedef struct
{
    int           len;
    int           appid;
    unsigned char data[TOTAL_DATA_LENGTH];
} quec_licenseData_t;

static quec_licenseData_t      LicenseRcvData;

#if 1
/**
 * @brief 函数功能：对取出的imei号和sn号拼接成上传的字符串
 *
 * @param[in] imei 设备的IMEI号
 * 
 * @param[in] sn 设备的sn号
 * 
 * @param[in] base64_out_buf 返回的拼接后的字符串
 *
 * @return 返回 1 表示成功,
 *         返回 0 表示执行失败
 *
 */
int quec_license_information_process(const char *CPUID, const char *SN, char *base64_out_buf)
{
    if (CPUID == NULL || SN == NULL || base64_out_buf == NULL)
    {
        return 0;
    }
    memcpy(base64_out_buf, CPUID, CPU_ID_LENGTH);
    strcat(base64_out_buf, "+");
    strcat(base64_out_buf, SN);
    license_printf("base64_out_buf in process %s\n", base64_out_buf);
    return 1;
}

#endif

#if 1
/**
?* @brief 函数功能:判断是否是hex字符
?*
?* @param[in] char c
?*
?* @return 返回 0 表示成功,
 *         返回 -1 表示执行失败
?*/
static int quec_license_is_hex_number(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
    {
        // license_printf("1hex error");
        return 0;
    }
    return -1;
}

static uint8 quec_tcpip_hex_2_byte(char ch)
{
    if (quec_license_is_hex_number(ch) == -1)
    {
        return 0;
    }
    if (ch >= '0' && ch <= '9')
    {
        return (ch - '0');
    }
    else if (ch >= 'a' && ch <= 'f')
    {
        return ((ch - 'a') + 10);
    }
    else if (ch >= 'A' && ch <= 'F')
    {
        return ((ch - 'A') + 10);
    }

    return 0;
}

/**
?* @brief 函数功能：将hex数据转化为字符串
?*
?* @param[in] const char * src
        输入数据
?* @param[in] int src_len
        输入数据长度
?* @param[in] char * dst
        输出数据
?* @param[in] int * dst_len
        输出数据长度
?*
?* @return int
?*/
static int qlicense_hex_to_string(const char *src, int src_len, char *dst, int *dst_len)
{
    int i;
    if (src == NULL || src_len % 2 != 0 || dst == NULL || dst_len == NULL)
    {
        return -1;
    }
    *dst_len = 0;
    for (i = 0; i < src_len; i += 2, (*dst_len)++)
    {
        if (quec_license_is_hex_number(src[i]) == -1 || quec_license_is_hex_number(src[i + 1]) == -1)
        {
        	license_printf("license hex to string error");
            return -1;
        }
        dst[*dst_len] = ((quec_tcpip_hex_2_byte(src[i]) << 4) | quec_tcpip_hex_2_byte(src[i + 1]));
    }
     free(src);
     src = NULL;
    license_printf("*dst_len: %d", *dst_len);
    return 0;
}
#endif

/**
?* @brief 函数功能：
        函数目的性在于通过AT+QSECLICINFO来获取加密之后的base64数据字符内容
        上层应用获取到数据之后，可以向服务器发送数据，从而请求token信息
?*
?* @param[in]
?*
?* @return void
?*/
RETURNCODE_T  quec_exec_qlicenseinfo_cmd
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
	RETURNCODE_T ret = utlSUCCESS;
	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
	*xid_p = atHandle;
	char uaRspStr[RETURN_STRING_LENGTH] = {0};
	int Rsp_len = 0;
	switch (op)
	{
		case TEL_EXT_GET_CMD:
		{
	        unsigned char *dev_info = NULL;
	        int            dev_len = DEV_LENGTH;
	        unsigned char  digest_txt[DIGEST_LENGTH + 1] = {0};
	        int            digest_len = DIGEST_LENGTH;
	        dev_info = (unsigned char *)malloc(48 + 1);
	        if (dev_info == NULL)
	        {
	        	ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
	            break;
	        }
	        memset(dev_info, 0, 49);
	        quec_slas_license_get_dev_info(dev_info, &dev_len);
	        license_printf("dev_len=%d, %s\n", dev_len, dev_info);
	        // 计算设备信息摘要
	        quec_slas_license_digest(dev_info, dev_len, digest_txt, &digest_len);
	        license_printf("dev_len=%d, %s\n", dev_len, dev_info);
	        license_printf("digest_txt=%d, %s\n", digest_len, digest_txt);

	        memset(uaRspStr, 0x00, sizeof(uaRspStr));
	        Rsp_len += snprintf(uaRspStr, 512, "+QLICENSEINFO: %d,\"%s\"", dev_len, dev_info);
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, uaRspStr);
			break;
		}
		case TEL_EXT_TEST_CMD:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			break;
		default:
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
			break;
	}
	return ret;
}

RETURNCODE_T  quec_exec_qlicense_cmd
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
	RETURNCODE_T ret = utlSUCCESS;
	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
	uint8 num_param = quec_get_at_param_num(parameter_values_p, num_parameters);
	*xid_p = atHandle;
    int                   real_len = 0;
    bool                  paramok = true;
    int                   nindex = 0;
    int                   totallen = 0;
    int                   data_len = 0;
    char                  responce[RETURN_STRING_LENGTH] = {0};
    char                  buffer[TOTAL_DATA_LENGTH/2] = {0};
    char                  recbuffer[TOTAL_DATA_LENGTH] = {0};
    int                   testlen = 0;
    int                   hexlen = 0;
    int                   appid_param = 0;
    int                   aStringLen = 0;
    quec_license_app_type_t app_type;
    int                   j = 0;
	switch (op)
	{
		case TEL_EXT_GET_CMD:
		{
			int appid = 0;
			quec_license_error_e result = QUEC_LIC_OK;
			
			for (j = QUEC_LIC_APP_1_TYPE; j < QUEC_LIC_APP_MAX_TYPE; j++)
			{
				result = quec_slas_license_get_apppid(j, &appid);
				if (result != QUEC_LIC_OK || appid == 0)
				{
					continue;
				}
			
				result = quec_slas_license_get_active_result(j);
				if (result == QUEC_LIC_APP_NO_REGISTER_ERROR)
				{
					continue;
				}
			
				if (result == QUEC_LIC_OK)
				{
					result = snprintf(responce, RETURN_STRING_LENGTH, "+QLICENSE: %d,1\r\n", appid);
					//quec_atCmdRespInfoNText(cmd->engine, responce, result, 1);
				}
				else
				{
					result = snprintf(responce, RETURN_STRING_LENGTH, "+QLICENSE: %d,0\r\n", appid);
					//quec_atCmdRespInfoNText(cmd->engine, responce, result, 1);
				}			 
                quec_siolib_transmit_to_atp(GET_ATP_INDEX(atHandle), responce, strlen(responce), &real_len);
			}
			ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL,0);

			break;
		}
		case TEL_EXT_SET_CMD:
		{
	        // step 1 参数解析，获取道appid 以及对应的license 内容

		    // step 2 直接调用ql_license_get_apppinfo 获取对应的info结构体信息

		    // step 3 检查license激活状态

		    // step 4 保存license到文件中
		    
		    if(num_param != 5)
		    {
				license_printf("Too few parameters %d \r\n",num_param);
				ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}
		    if (getExtValue(parameter_values_p, 0, &appid_param, 0, APPID_MAX_LENGTH, 0) == FALSE ||
                getExtValue(parameter_values_p, 1, &nindex, 0, 1, 0) == FALSE ||
                getExtValue(parameter_values_p, 2, &totallen, 1, TOTAL_DATA_LENGTH, 0) == FALSE ||
                getExtValue(parameter_values_p, 3, &hexlen, 1, TOTAL_DATA_LENGTH, 0) == FALSE ){
				ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}
			license_printf("param get:%d %d %d %d\r\n",appid_param,nindex,totallen,hexlen);
			const char *recbuffer=malloc(hexlen + 1);
			if(recbuffer == NULL)
			{
				license_printf("recbuffer malloc fail ");
				ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_MEMORY_FAILURE, NULL);
				break;
			}
			if(getExtString(parameter_values_p, 4, recbuffer, hexlen+1, &aStringLen, NULL) == FALSE)
			{
				ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
			}

			testlen = qlicense_hex_to_string(recbuffer, hexlen, buffer, &data_len);
       
	        if (testlen < 0)
	        {
	            license_printf("hex to string error testlen = %d", testlen);
	            ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
	            break;
	        }

	        if ((data_len) != hexlen / 2)
	        {
	            ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
	            break;
	        }
		   
	        memcpy(LicenseRcvData.data + LicenseRcvData.len, buffer, data_len);
	        LicenseRcvData.len += data_len;

	        if (nindex == 0)
	        {
	            if (LicenseRcvData.len != totallen / 2)
	            {
	                ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
	                memset(LicenseRcvData.data, 0x00, TOTAL_DATA_LENGTH);
	                LicenseRcvData.len = 0;
	                break;
	            }
	            app_type = quec_slas_license_appid_to_apptype(appid_param);

	            if(app_type == QUEC_LIC_APP_MIN_TYPE)
	            {
	                license_printf("app_id not registed\n");
	                ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
	                break;
	            }

	            ret = quec_slas_license_save_license_info(app_type, LicenseRcvData.data, LicenseRcvData.len);
	            if (ret == 0)
	            {
	                memset(responce, 0x00, RETURN_STRING_LENGTH);
	                snprintf(responce, RETURN_STRING_LENGTH, "+QLICENSE: %d,%d,%d", appid_param, nindex, 2 * LicenseRcvData.len);
					ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL,responce);
	                memset(LicenseRcvData.data, 0x00, TOTAL_DATA_LENGTH);
	                LicenseRcvData.len = 0;
	                break;
	            }
	            else
	            {
	                license_printf("slas license_info save fail");
	                memset(LicenseRcvData.data, 0x00, TOTAL_DATA_LENGTH);
	                LicenseRcvData.len = 0;
	                ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
	                break;
	            }
	        }

	        snprintf(responce, RETURN_STRING_LENGTH, "+QLICENSE: %d,%d,%d", appid_param, nindex, 2 * LicenseRcvData.len);
	        ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL,responce);
			break;
		}
		case TEL_EXT_TEST_CMD:
			ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, "+QLICENSE: <appid>,(0-1),(0-2048),(0-2048),<data>");
			break;
		default:
			ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
			break;
	}
	return ret;

}
#else
//20230926为了裁剪，slas授权指令假实现
RETURNCODE_T  quec_exec_qlicense_cmd
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
	RETURNCODE_T ret = utlSUCCESS;
	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
	uint8 num_param = quec_get_at_param_num(parameter_values_p, num_parameters);
	*xid_p = atHandle;
	ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL,NULL);
	return ret;
}

RETURNCODE_T  quec_exec_qlicenseinfo_cmd
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
	RETURNCODE_T ret = utlSUCCESS;
	TelAtParserID sAtpIndex = * (TelAtParserID *) arg_p;
	UINT32 atHandle = MAKE_AT_HANDLE( sAtpIndex );
	uint8 num_param = quec_get_at_param_num(parameter_values_p, num_parameters);
	*xid_p = atHandle;
	ATRESP(atHandle, ATCI_RESULT_CODE_OK, NULL,NULL);
	return ret;
}
#endif
#endif