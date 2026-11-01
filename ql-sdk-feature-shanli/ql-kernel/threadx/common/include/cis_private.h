#ifndef __CIS_PRIVATE_H__
#define __CIS_PRIVATE_H__

extern unsigned char *g_CISI2CBuf;
extern unsigned char g_CISEncTransSign;
extern unsigned char g_DefTransey[16];
extern unsigned char g_TransTmpKey[16];

typedef struct {
	int i2c_no;
	int i2c_scl;
	int i2c_sda;
	int i2c_reset;
}quec_alipay_se_iic_t;
// CRC单字节计算——循环左移，先移最高bit
extern unsigned short LeftShift_CRC(unsigned char byValue, unsigned short *lpwCrc);
extern void ComputeCRC(unsigned char *Data, unsigned short Length, unsigned char *pbyOut);
extern void lmemset(unsigned char *pBuf, unsigned char byVal, unsigned short wLen);
extern void lmemcpy(unsigned char *pDst, unsigned char *pSrc, unsigned short wLen);
extern unsigned char lmemcmp(unsigned char *pBuf1, unsigned char *pBuf2, unsigned short wLen);

extern void CIS_IIC_Init(void);
extern void CIS_IIC_Send_Cmd(unsigned char *pData, unsigned short wLen);
extern unsigned char CIS_IIC_Recv_Resp(unsigned char *pData, unsigned short wLen);

extern void Delay_Ms(unsigned char byMilliSec);
extern void Set_GPIO_State(unsigned char byState);

extern unsigned char *IIC_Master_Init(void);
extern void IIC_Master_Send(unsigned char byAddr, unsigned char *pData, unsigned short wLen);
extern void IIC_Master_Receive(unsigned char byAddr, unsigned char *pData, unsigned short wLen);

extern void quec_alipay_se_set_iic_pin(int se_i2c_no,int se_i2c_scl,int se_i2c_sda,int se_i2c_reset);


#endif
