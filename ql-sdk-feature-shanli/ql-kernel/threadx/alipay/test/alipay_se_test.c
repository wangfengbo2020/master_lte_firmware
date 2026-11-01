
#include "alipay_sdk.h"
#include "quec_rtos.h"
#include "cis_private.h"
#include "quec_cust_feature.h"

extern void RTI_LOG(const char* fmt, ...);

extern int quec_netif_default_cfg(void);

quec_flag_t alipay_flag_ref;
quec_task_t alipay_task_ref;

#define QUEC_ALIPAY_BIND_EVENT (1<<0)
#define QUEC_ALIPAY_PAY_CODE_EVENT (1<<1)
#define QUEC_ALIPAY_PAY_SET_EVENT  (1<<2)
#define QUEC_ALIPAY_CERT_EVENT  (1<<3)
#define QUEC_ALIPAY_AID_EVENT  (1<<4)



#define QUEC_ALIPAY_EVENT_MASK (QUEC_ALIPAY_BIND_EVENT | QUEC_ALIPAY_PAY_CODE_EVENT |QUEC_ALIPAY_PAY_SET_EVENT\
	|QUEC_ALIPAY_CERT_EVENT |QUEC_ALIPAY_AID_EVENT)

#define QUEC_ALIPAY_STACK_SIZE 20*1024
#define QUEC_ALIPAY_TASK_PRIORITY 90

void alipay_unit_task(void* argv);

void quec_alipay_test_init(void)
{
	//1.create flag,task
	if(NULL == alipay_flag_ref)
	{
		quec_rtos_flag_create(&alipay_flag_ref);
	}

	if(NULL == alipay_task_ref)
	{
		quec_rtos_task_create(&alipay_task_ref, QUEC_ALIPAY_STACK_SIZE, QUEC_ALIPAY_TASK_PRIORITY, "alipay_test", alipay_unit_task, NULL);
	}
	//2.IIC init
	//add 20240411 This interface is used to configure an SE iic pin
	quec_alipay_se_set_iic_pin(1, 10, 11, 71);
	
	CIS_IIC_Init();

}

void quec_alipay_binding_release(void)
{
	if(alipay_flag_ref)
	{
		quec_rtos_flag_release(alipay_flag_ref, QUEC_ALIPAY_BIND_EVENT, QUEC_FLAG_OR);
	}
}

void alipay_unit_task(void* argv)
{
	unsigned int alipay_event;
	char binding_code[256]={0};
	int len_binding_code = sizeof(binding_code);
	retval_e ret = ALIPAY_RV_OK;
	int alipay_init = 0;
	int netif_status = 0;

	unsigned char pay_code[24] = {0};
	unsigned int paycode = sizeof(pay_code);

	unsigned char id[128] = {0};
	unsigned int len_id = sizeof(id);
	unsigned char nick_name[128] = {0};
	unsigned int len_nick_name = sizeof(nick_name);

	char aid_code[256]={0};
	unsigned int len_aid_code = sizeof(aid_code);

	quec_rtos_task_sleep_s(5);
	//20240409 The default network card must be bound, otherwise the alipay binding will fail
	netif_status = quec_netif_default_cfg();
	if(netif_status != 0)
	{
		RTI_LOG("Netif Default Cfg Fail:%d\r\n",netif_status);
	}
		
	if(alipay_pre_init())
	{
		RTI_LOG("Alipay Init Fail\r\n");
	}
	while(1)
	{
		quec_rtos_flag_wait(alipay_flag_ref, QUEC_ALIPAY_EVENT_MASK, QUEC_FLAG_OR_CLEAR, &alipay_event, QUEC_WAIT_FOREVER);
		if(alipay_event & QUEC_ALIPAY_BIND_EVENT) //test bind
		{

			ret = alipay_get_binding_code(binding_code, &len_binding_code);
			if(ret != ALIPAY_RV_OK)
			{
				RTI_LOG("Alipay Get Binding Code Fail:%d\r\n",ret);
				break;
			}
			else
			{
				RTI_LOG("%s\r\n",binding_code);
				do
				{
					binding_status_e status = ALIPAY_STATUS_UNKNOWN;
					ret = alipay_query_binding_result(&status);
					RTI_LOG("Alipay Binding Result:status=0x%x,ret=%d\r\n",status,ret);
					if(status == ALIPAY_STATUS_BINDING_OK)
					{
						RTI_LOG("ALIPAY_STATUS_BINDING_OK\r\n");
						break;
					}
					else if(status == ALIPAY_STATUS_START_BINDING)
					{
						RTI_LOG("ALIPAY_STATUS_START_BINDING\r\n");
					}
					else if(status == ALIPAY_STATUS_BINDING_FAIL)
					{
						RTI_LOG("ALIPAY_STATUS_BINDING_FAIL\r\n");
						break;
					}
					quec_rtos_task_sleep_s(2);
				}while(1);
			}
		}
		else if(alipay_event & QUEC_ALIPAY_PAY_CODE_EVENT)
		{
			ret = alipay_get_paycode(pay_code, &paycode);
			if(ret != ALIPAY_RV_OK)
			{
				RTI_LOG("Alipay Get Pay Code Fail:%d\r\n",ret);
			}
		}
		else if(alipay_event & QUEC_ALIPAY_PAY_SET_EVENT)
		{
			ret = alipay_get_logon_ID(id, &len_id);

			ret = alipay_get_nick_name(nick_name, &len_nick_name);
		}

		else if(alipay_event & QUEC_ALIPAY_AID_EVENT)
		{
			ret = alipay_get_aid_code(aid_code, &len_aid_code);
			if(ret != ALIPAY_RV_OK)
			{
				RTI_LOG("Alipay Get Aid Code Fail:%d\r\n",ret);
			}
		}

		else if(alipay_event & QUEC_ALIPAY_CERT_EVENT)
		{
			if(alipay_is_need_to_request_cert() == 1)
			{
				RTI_LOG("No Local Certificate !!!\r\n");
			}
		}
		
		quec_rtos_task_sleep_s(2);
	}
	

}



