#include <stdlib.h>
#include "cis_private.h"
#include "i2c_api.h"
#include "cgpio.h"
#include "osa_old_api.h"

#include "UART.h"
#define alipay_log_debug(fmt,args...)  do {CPUartLogPrintf("[ali_csi_i2c]"fmt, ##args);}while(0)
	

#define SE_I2C_ADDR 0x64  //7bit addr = 0x64
#define IIC_RAM_SIZE 2048

//CI2C/I2C0 func1
#define SE_I2C_NO 0
#define SE_SCL_GPIO 49
#define SE_SDA_GPIO 50
#define SE_RESET_GPIO  70

/*
//I2C_2/I2C1 func1
#define SE_I2C_NO 1
#define SE_SCL_GPIO 10
#define SE_SDA_GPIO 11
*/

static quec_alipay_se_iic_t alipay_se_iic_pin={
	SE_I2C_NO,
	SE_SCL_GPIO,
	SE_SDA_GPIO,
	SE_RESET_GPIO
};


unsigned char *g_CISI2CBuf = NULL;
unsigned char g_CISEncTransSign; // 通信是否加密，0 = 明文通信，1 = 加密通信
unsigned char g_DefTransKey[16] = {0x54, 0x8E, 0x8D, 0x7A, 0x26, 0x35, 0x85, 0x11, 0x25, 0x2E, 0xF8, 0xD6, 0xB7, 0x17, 0xA4, 0xE4};
unsigned char g_TransTmpKey[16];

void quec_alipay_se_set_iic_pin(int se_i2c_no,int se_i2c_scl,int se_i2c_sda,int se_i2c_reset)
{
	if((se_i2c_no < 0) || (se_i2c_scl < 0) || (se_i2c_sda < 0) || (se_i2c_reset < 0))
	{
		return;
	}
	alipay_se_iic_pin.i2c_no = se_i2c_no;
	alipay_se_iic_pin.i2c_scl = se_i2c_scl;
	alipay_se_iic_pin.i2c_sda = se_i2c_sda;
	alipay_se_iic_pin.i2c_reset = se_i2c_reset;
}

unsigned char *IIC_Master_Init(void)
{
	//i2c_initialize(SE_I2C_NO);
	i2c_init(alipay_se_iic_pin.i2c_no, 1);

	return (unsigned char *)malloc(IIC_RAM_SIZE);
}

void IIC_Master_Send(unsigned char byAddr, unsigned char *pData, unsigned short wLen)
{
	//i2c_write_bytes(SE_I2C_NO, byAddr >> 1, pData, wLen, 0);
	 i2c_write(alipay_se_iic_pin.i2c_no, byAddr >> 1, 0, 0, pData, (unsigned short)wLen);
	//i2c_write_int(SE_I2C_NO, byAddr >> 1, 0, 0, pData, (unsigned short)wLen);
}

void IIC_Master_Receive(unsigned char byAddr, unsigned char *pData, unsigned short wLen)
{
	//i2c_read_bytes(SE_I2C_NO, byAddr >> 1, pData, wLen, 0);
	i2c_read(alipay_se_iic_pin.i2c_no, byAddr >> 1, 0, 0, pData, (unsigned short)wLen);
	//i2c_read_int(SE_I2C_NO, byAddr >> 1, 0, 0, pData, (unsigned short)wLen);
}

// delay 要保证不能小于1ms, the uos_sleep_ms function will guarantee.
void Delay_Ms(unsigned char byMilliSec)
{
	 // uos_sleep_ms(ms);
	OSATaskSleep((byMilliSec+4)/5);
}

// 控制 se reset引脚
void Set_GPIO_State(unsigned char byState)
{
	GpioSetLevel(alipay_se_iic_pin.i2c_reset, byState);
}

// CRC单字节计算——循环左移，先移最高bit
unsigned short LeftShift_CRC(unsigned char byValue, unsigned short *lpwCrc)
{
	byValue ^= (unsigned char)(*lpwCrc >> 8);
	byValue ^= (byValue >> 4);

	*lpwCrc = (*lpwCrc << 8) ^ (unsigned short)(byValue);
	*lpwCrc ^= (unsigned short)byValue << 12;
	*lpwCrc ^= (unsigned short)byValue << 5;

	return (*lpwCrc);
}

void ComputeCRC(unsigned char *Data, unsigned short Length, unsigned char *pbyOut)
{
	unsigned char chBlock;
	unsigned short wCrc;

	wCrc = 0x0000; // ITU-V.41

	while (Length--)
	{
		chBlock = *Data++;
		LeftShift_CRC(chBlock, &wCrc);
	}

	pbyOut[0] = (unsigned char)((wCrc >> 8) & 0xFF);
	pbyOut[1] = (unsigned char)(wCrc & 0xFF);

	return;
}

void lmemset(unsigned char *pBuf, unsigned char byVal, unsigned short wLen)
{
	unsigned short i;

	for (i = 0; i < wLen; ++i)
	{
		pBuf[i] = byVal;
	}
	return;
}

void lmemcpy(unsigned char *pDst, unsigned char *pSrc, unsigned short wLen)
{
	unsigned short i;

	if ((pSrc == pDst) || (wLen == 0))
	{
		return;
	}

	if (pSrc < pDst)
	{
		for (i = wLen - 1; i != 0; --i)
		{
			pDst[i] = pSrc[i];
		}
		pDst[0] = pSrc[0];
	}
	else
	{
		for (i = 0; i < wLen; ++i)
		{
			pDst[i] = pSrc[i];
		}
	}

	return;
}

// 相同返回0，不同返回1
unsigned char lmemcmp(unsigned char *pBuf1, unsigned char *pBuf2, unsigned short wLen)
{
	unsigned short i;

	for (i = 0; i < wLen; ++i)
	{
		if (pBuf1[i] != pBuf2[i])
		{
			return 1;
		}
	}

	return 0;
}

static void CIS_SEIO_Init(void)
{


#ifdef QUECTEL_OPEN_CPU
	switch(alipay_se_iic_pin.i2c_no)
	{
		case 0:
		case 1:
			*(volatile unsigned int *)(GPIO_MFPR_ADDR(alipay_se_iic_pin.i2c_scl)) = 0xC081;
			*(volatile unsigned int *)(GPIO_MFPR_ADDR(alipay_se_iic_pin.i2c_sda)) = 0xC081;
			break;
		case 2:
			*(volatile unsigned int *)(GPIO_MFPR_ADDR(alipay_se_iic_pin.i2c_scl)) = 0xC087;
			*(volatile unsigned int *)(GPIO_MFPR_ADDR(alipay_se_iic_pin.i2c_sda)) = 0xC087;
			break;
		case 3:
			*(volatile unsigned int *)(GPIO_MFPR_ADDR(alipay_se_iic_pin.i2c_scl)) = 0xC082;
			*(volatile unsigned int *)(GPIO_MFPR_ADDR(alipay_se_iic_pin.i2c_sda)) = 0xC082;	
			break;
	}
#else	
	*(volatile unsigned int *)(GPIO_MFPR_ADDR(alipay_se_iic_pin.i2c_scl)) = 0xC081;
	*(volatile unsigned int *)(GPIO_MFPR_ADDR(alipay_se_iic_pin.i2c_sda)) = 0xC081;
#endif

	*(volatile unsigned int *)(GPIO_MFPR_ADDR(alipay_se_iic_pin.i2c_reset)) = 0xC080;
	
	GpioSetDirection(alipay_se_iic_pin.i2c_reset, GPIO_OUT_PIN);
	
	Set_GPIO_State(0);
	Delay_Ms(1);
	Set_GPIO_State(1);
	Delay_Ms(30);
}

// 调用I2C 接口时必须先初始化
void CIS_IIC_Init(void)
{
	unsigned char ver[29];
	unsigned char i;
	
	alipay_log_debug("%s",__func__);

	CIS_SEIO_Init();

	g_CISEncTransSign = 0x00;
	lmemset(g_TransTmpKey, 0x00, 16);
	if (g_CISI2CBuf)
	{
		free(g_CISI2CBuf);
	}
	g_CISI2CBuf = IIC_Master_Init();
	g_CISI2CBuf[0] = 0x00;
	g_CISI2CBuf[1] = 0x05;
	g_CISI2CBuf[2] = 0x00;
	g_CISI2CBuf[3] = 0xCA;
	g_CISI2CBuf[4] = 0x00;
	g_CISI2CBuf[5] = 0x00;
	g_CISI2CBuf[6] = 0x00;
	ComputeCRC(g_CISI2CBuf, 7, g_CISI2CBuf + 7);
	CIS_IIC_Send_Cmd(g_CISI2CBuf, 9);
	if (0 != CIS_IIC_Recv_Resp(ver, 29)) // 如果获取初值密钥指令执行异常，就用16字节FF进行加密通信
	{
		g_CISEncTransSign = 0x01;
		lmemset(g_TransTmpKey, 0xFF, 16);
		alipay_log_debug("%s fail!",__func__);
		return;
	}

	if ((ver[0] == 0x80) && (ver[1] == 0x10) && (ver[18] == 0x81) && (ver[19] == 0x02)) // 简单的检查一下数据格式内容	
	{
		if ((ver[20] != 0x10) || (ver[21] != 0x03))
		{
			g_CISEncTransSign = 0x01;
			for (i = 0; i < 16; ++i)
			{
				g_TransTmpKey[i] = ver[2 + i] ^ g_DefTransKey[i];
			}
			alipay_log_debug("%s pass!",__func__);
		}
	}
	else
	{
		g_CISEncTransSign = 0x01;
		lmemset(g_TransTmpKey, 0xFF, 16);
	}
}

// 发送: 	C8 + LEN(2) + { 命令及数据} ^ g_TransTmpKey + CRC
// 返回FALSE表示接收指令或数据CRC校验错误
void CIS_IIC_Send_Cmd(unsigned char *pData, unsigned short wLen)
{
	IIC_Master_Send(0xC8, pData, wLen);
}

// 接收: 	C9 + 55
//			C9 + LEN(2) + { 响应数据+ 状态字} ^ g_TransTmpKey + CRC

// 功能:	接收wLen长度的数据，到pData缓冲区中
// 返回:
//			0 表示正确接收
//			1 表示接收数据CRC错误
//			2 表示实际接收数据长度域不是wLen
//			3 表示指令返回状态字不是9000
//			4 表示指令超时未响应
unsigned char CIS_IIC_Recv_Resp(unsigned char *pData, unsigned short wLen)
{
	unsigned short wRspLen;
	unsigned char crc[2];
	unsigned int dwCnt;
	unsigned short i;

	g_CISI2CBuf[0] = 0x00;
	dwCnt = 0;
	
	IIC_Master_Receive(0xC9, g_CISI2CBuf, 1);
	while (g_CISI2CBuf[0] != 0x55)
	{
		// 不能去掉延时，se是通过中断来处理指令的，如果一直发送receive请求，se会一直卡在中断中
		//Delay_Ms(5);
		++dwCnt;
		if (dwCnt > 0x100)
		{
			alipay_log_debug("%s read 0x55 timeout!",__func__);
			return 4;
		}
		IIC_Master_Receive(0xC9, g_CISI2CBuf, 1);
	}

	IIC_Master_Receive(0xC9, g_CISI2CBuf, wLen + 6);

	wRspLen = g_CISI2CBuf[0];
	wRspLen <<= 8;
	wRspLen |= g_CISI2CBuf[1];
	if (wRspLen != wLen + 2)
	{
		return 2;
	}

	ComputeCRC(g_CISI2CBuf + 2, wLen + 2, crc);
	if ((g_CISI2CBuf[wLen + 4] != crc[0]) || (g_CISI2CBuf[wLen + 5] != crc[1]))
	{
		return 1;
	}

	if (g_CISEncTransSign == 0x01)
	{
		for (i = 0; i < wLen + 2; ++i)
		{
			g_CISI2CBuf[2 + i] ^= g_TransTmpKey[i % 16];
		}
	}
	if ((g_CISI2CBuf[2 + wLen] != 0x90) || (g_CISI2CBuf[3 + wLen] != 0x00)) // 状态字
	{
		pData[0] = g_CISI2CBuf[2 + wLen];
		pData[1] = g_CISI2CBuf[3 + wLen];

		return 3;
	}

	lmemcpy(pData, g_CISI2CBuf + 2, wLen);

	return 0;
}
