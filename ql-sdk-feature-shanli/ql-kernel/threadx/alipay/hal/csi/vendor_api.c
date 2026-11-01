#include <stdint.h>
#include <stdlib.h>
#include "cis_private.h"
#include "iotsec.h"

#include "UART.h"
#define printf(fmt,args...)  do {CPUartLogPrintf("[ali_vendor]"fmt, ##args);}while(0)
static bool g_enter_lpm;

/*○ 功能描述
	■ 获取设备ID
  ○ 接口参数
	■ uid-设备ID地址
	■ len-返回设备ID长度
  ○ 返回值
	■ 0表示成功，非0表示失败*/
csi_error_t csi_get_huk(uint8_t *uid, uint32_t *len)
{
	unsigned char i;

	g_CISI2CBuf[0] = 0x00;
	g_CISI2CBuf[1] = 0x05;
	g_CISI2CBuf[2] = 0x80;
	g_CISI2CBuf[3] = 0xF6;
	g_CISI2CBuf[4] = 0x00;
	g_CISI2CBuf[5] = 0x00;
	g_CISI2CBuf[6] = 0x10;
	if (g_CISEncTransSign == 0x01)
	{
		for (i = 0; i < 5; ++i)
		{
			g_CISI2CBuf[2 + i] ^= g_TransTmpKey[i];
		}
	}
	ComputeCRC(g_CISI2CBuf, 7, g_CISI2CBuf + 7);
	CIS_IIC_Send_Cmd(g_CISI2CBuf, 9);
	if (0 != CIS_IIC_Recv_Resp(uid, 16))
	{
		return CSI_ERROR;
	}

	*len = 16;
	return CSI_OK;
}

/*○ 功能描述
	■ 获取安全芯片固件版本号
  ○ 接口参数
	■ ver - 存放版本号buffer
  ○ 返回值
	■ 0表示成功，非0表示失败*/
csi_error_t csi_get_fw_version(char ver[8])
{
	unsigned char i;

	g_CISI2CBuf[0] = 0x00;
	g_CISI2CBuf[1] = 0x05;
	g_CISI2CBuf[2] = 0x00;
	g_CISI2CBuf[3] = 0xBC;
	g_CISI2CBuf[4] = 0x00;
	g_CISI2CBuf[5] = 0x00;
	g_CISI2CBuf[6] = 0x08;
	if (g_CISEncTransSign == 0x01)
	{
		for (i = 0; i < 5; ++i)
		{
			g_CISI2CBuf[2 + i] ^= g_TransTmpKey[i];
		}
	}
	ComputeCRC(g_CISI2CBuf, 7, g_CISI2CBuf + 7);
	CIS_IIC_Send_Cmd(g_CISI2CBuf, 9);
	if (0 != CIS_IIC_Recv_Resp((unsigned char *)ver, 8))
	{
		return CSI_ERROR;
	}
	printf("%s, se chip ver=%s",__func__, ver);

	return CSI_OK;
}

/*○ 功能描述
	■ 系统进入低功耗模式
  ○ 接口参数
	■ ctx - 保存进入低功耗前的需要保存的上下文
  ○ 返回值
	■ 无*/
void csi_enter_lpm(void *ctx)
{
	if (g_enter_lpm) {
		return;
	}

	unsigned char abySW[2];
	unsigned char i;

	g_CISI2CBuf[0] = 0x00;
	g_CISI2CBuf[1] = 0x0C;
	g_CISI2CBuf[2] = 0x80;
	g_CISI2CBuf[3] = 0xFB;
	g_CISI2CBuf[4] = 0x00;
	g_CISI2CBuf[5] = 0x00;
	g_CISI2CBuf[6] = 0x07;

	g_CISI2CBuf[7] = 0x53;
	g_CISI2CBuf[8] = 0x54;
	g_CISI2CBuf[9] = 0x41;
	g_CISI2CBuf[10] = 0x4E;
	g_CISI2CBuf[11] = 0x44;
	g_CISI2CBuf[12] = 0x42;
	g_CISI2CBuf[13] = 0x59;

	if (g_CISEncTransSign == 0x01)
	{
		for (i = 0; i < 12; ++i)
		{
			g_CISI2CBuf[2 + i] ^= g_TransTmpKey[i];
		}
	}

	Set_GPIO_State(1);

	ComputeCRC(g_CISI2CBuf, 14, g_CISI2CBuf + 14);
	CIS_IIC_Send_Cmd(g_CISI2CBuf, 16);
	if (0 != CIS_IIC_Recv_Resp(abySW, 0))
	{
		return;
	}

	Delay_Ms(30);

	g_enter_lpm = true;

	return;
}

/*○ 功能描述
	■ 系统退出低功耗模式
  ○ 接口参数
	■ ctx - 保存进入低功耗前的需要保存的上下文
  ○ 返回值
	■ 无*/
void csi_exit_lpm(void *ctx)
{
	if (!g_enter_lpm) {
		return;
	}

	unsigned char abyVer[8];
	unsigned char i;

	for (i = 0; i < 3; ++i)
	{
		g_CISI2CBuf[0] = 0x00;
		g_CISI2CBuf[1] = 0x05;
		g_CISI2CBuf[2] = 0x00;
		g_CISI2CBuf[3] = 0xBC;
		g_CISI2CBuf[4] = 0x00;
		g_CISI2CBuf[5] = 0x00;
		g_CISI2CBuf[6] = 0x08;
		if (g_CISEncTransSign == 0x01)
		{
			for (i = 0; i < 5; ++i)
			{
				g_CISI2CBuf[2 + i] ^= g_TransTmpKey[i];
			}
		}
		ComputeCRC(g_CISI2CBuf, 7, g_CISI2CBuf + 7);

		Set_GPIO_State(0);

		Delay_Ms(1);

		Set_GPIO_State(1);

		Delay_Ms(30); //必须大于30ms

		CIS_IIC_Send_Cmd(g_CISI2CBuf, 9);
		if (0 == CIS_IIC_Recv_Resp(abyVer, 8))
		{
			if ((abyVer[0] == 'V') && (abyVer[2] == '.'))
			{
				g_enter_lpm = false;
				return;
			}
		}
	}
	return;
}

/*○ 功能描述
	■ 发送请求给SE且同步处理用户命令
  ○ 接口参数
	■ req - 命令请求数据包
	■ req_len - 命令请求数据包长度
	■ rsp - 命令响应数据包
	■ rsp_len - 命令响应数据包长度
  ○ 返回值
	■ 0表示成功，非0表示失败*/
csi_error_t csi_user_cmd_process_sync(void *req, unsigned int req_len, void *rsp, unsigned int *rsp_len)
{
	unsigned short i;
	unsigned short wRspLen;
	unsigned char crc[2];
	unsigned int dwCnt;

	if (req_len > 256)
	{
		return CSI_ERROR;
	}

	g_CISI2CBuf[0] = (unsigned char)((req_len + 5) / 256);
	g_CISI2CBuf[1] = (unsigned char)((req_len + 5) % 256);
	g_CISI2CBuf[2] = 0x80;
	g_CISI2CBuf[3] = 0xC2;
	g_CISI2CBuf[4] = 0x00;
	g_CISI2CBuf[5] = (unsigned char)(req_len / 256);
	g_CISI2CBuf[6] = (unsigned char)(req_len % 256);
	lmemcpy(g_CISI2CBuf + 7, (unsigned char *)req, req_len);
	if (g_CISEncTransSign == 0x01)
	{
		for (i = 0; i < req_len + 5; ++i)
		{
			g_CISI2CBuf[2 + i] ^= g_TransTmpKey[i % 16];
		}
	}

	ComputeCRC(g_CISI2CBuf, req_len + 7, g_CISI2CBuf + req_len + 7);
	CIS_IIC_Send_Cmd(g_CISI2CBuf, req_len + 9);

	g_CISI2CBuf[0] = 0x00;
	dwCnt = 0;
	IIC_Master_Receive(0xC9, g_CISI2CBuf, 1);
	while (g_CISI2CBuf[0] != 0x55)
	{
		// 不能去掉延时，se是通过中断来处理指令的，如果一直发送receive请求，se会一直卡在中断中
		Delay_Ms(5);
		++dwCnt;
		if (dwCnt > 0x100)
		{
			printf("%s, read 0x55 timeout ",__func__);
			return CSI_ERROR;
		}
		IIC_Master_Receive(0xC9, g_CISI2CBuf, 1);
	}

	IIC_Master_Receive(0xC9, g_CISI2CBuf, 2);
	wRspLen = g_CISI2CBuf[0];
	wRspLen <<= 8;
	wRspLen |= g_CISI2CBuf[1];
	IIC_Master_Receive(0xC9, g_CISI2CBuf, wRspLen + 4);

	ComputeCRC(g_CISI2CBuf + 2, wRspLen, crc);
	if ((g_CISI2CBuf[wRspLen + 2] != crc[0]) || (g_CISI2CBuf[wRspLen + 3] != crc[1]))
	{
		return CSI_ERROR;
	}

	if (g_CISEncTransSign == 0x01)
	{
		for (i = 0; i < wRspLen; ++i)
		{
			g_CISI2CBuf[2 + i] ^= g_TransTmpKey[i % 16];
		}
	}
	if ((g_CISI2CBuf[wRspLen] != 0x90) || (g_CISI2CBuf[1 + wRspLen] != 0x00)) // 状态字
	{
		return CSI_ERROR;
	}

	*rsp_len = wRspLen - 2;
	lmemcpy(rsp, g_CISI2CBuf + 2, wRspLen - 2);

	return CSI_OK;
}


#ifdef QUECTEL_OPEN_CPU
uint32_t alipay_ProductType = 0;

/*设置设备类型，根据设备实际情况设置
 * @param  type ：
 *         0    成人手表
 *         1    成人手环
 *         2    成人卡片
 *         3    儿童手表
 *         4    儿童手环
 *         5    学生卡
 * @return 0:成功，-1：失败
 */
int alipay_set_productType(uint32_t type)
{
	if(type<=5)
	{
		alipay_ProductType=type;
    	return 0;
	}
	else
	{
		return -1;
	}
	
}

/*获取设备类型，根据设备实际情况返回
 * @param
 * @return 0    成人手表
 *         1    成人手环
 *         2    成人卡片
 *         3    儿童手表
 *         4    儿童手环
 *         5    学生卡
 */
uint32_t alipay_get_productType(void)
{
    return alipay_ProductType;
}


#else

/*获取设备类型，根据设备实际情况返回
 * @param
 * @return 0    成人手表
 *         1    成人手环
 *         2    成人卡片
 *         3    儿童手表
 *         4    儿童手环
 *         5    学生卡
 */
uint32_t alipay_get_productType(void)
{
    uint32_t type = 0;

#ifdef PRODUCT_TYPE_ADULT_WATCH
    type = 0;
#elif defined PRODUCT_TYPE_ADULT_BRACELET
    type = 1;
#elif defined PRODUCT_TYPE_ADULT_CARD
    type = 2;
#elif defined PRODUCT_TYPE_CHILD_WATCH
    type = 3;
#elif defined PRODUCT_TYPE_CHILD_BRACELET
    type = 4;
#elif defined PRODUCT_TYPE_STUDENT_CARD
    type = 5;
#endif

    return type;
}
#endif
