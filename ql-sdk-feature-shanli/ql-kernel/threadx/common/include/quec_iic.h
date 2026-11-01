/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/

#ifndef _QUEC_IIC_H
#define _QUEC_IIC_H

#ifdef __cplusplus
extern "C" {

#endif
typedef enum
{
	STANDARD_MODE = 0,	/*100Kbps*/
    FAST_MODE = 1,		/*400Kbps*/
    HS_MODE = 2,		/*3.4 Mbps slave/3.3 Mbps master,standard mode when not doing a high speed transfer*/
    HS_MODE_FAST = 3,	/*3.4 Mbps slave/3.3 Mbps master,fast mode when not doing a high speed transfer*/
}QUEC_I2C_FAST_MODE;



int quec_i2c_init(unsigned char i2c_no, unsigned int fastMode);

int quec_i2c_write(unsigned char i2c_no, unsigned short slaveaddress, unsigned short addr, unsigned char *data, unsigned int datalen);

int quec_i2c_read(unsigned char i2c_no, unsigned short slaveaddress, unsigned short addr, unsigned char *data, unsigned int datalen);

int quec_i2c_write_ext(unsigned char  i2c_no, unsigned char  slaveaddress,unsigned char  *addr,unsigned int  addrlen, unsigned char  *data, unsigned int datalen);

int quec_i2c_read_ext(unsigned char i2c_no, unsigned char slaveaddress, unsigned char *addr,unsigned int addrlen, unsigned char *data, unsigned int datalen);

#ifdef __cplusplus
} /*"C" */
#endif

#endif

