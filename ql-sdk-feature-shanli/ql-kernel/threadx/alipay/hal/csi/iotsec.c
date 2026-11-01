#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "iotsec.h"

#include "hal_asr.h"

#include "UART.h"
#define printf(fmt,args...)  do {CPUartLogPrintf("[ali_iotsec]"fmt, ##args);}while(0)


csi_error_t csi_get_deviceid(uint8_t* buf_did, uint32_t *len_did)
{
    if (!buf_did || !len_did) {
        return CSI_ERROR;
    }

	uint8_t *byte;
	byte = Hal_get_mac();
	*len_did = sprintf((char *)buf_did, "%02X:%02X:%02X:%02X:%02X:%02X",
                        byte[5], byte[4], byte[3], byte[2], byte[1], byte[0]);					

    return CSI_OK;
}

csi_error_t csi_get_timestamp(uint32_t *tm)
{
    if (!tm) {
        return CSI_ERROR;
    }

    *tm = Hal_Rtc_Get_Utc_Sec();

    return CSI_OK;
}

/* len of sn <= 32 bytes */
csi_error_t csi_get_sn(uint8_t* buf_sn, uint32_t *len_sn)
{
    if (!buf_sn || !len_sn) {
        return CSI_ERROR;
    }

	char *buf = Hal_get_sn();
    *len_sn = strlen(buf);
	if(*len_sn > 32)
		*len_sn = 32;
	strncpy((char *)buf_sn, buf, *len_sn);

    return CSI_OK;
}

#ifdef QUECTEL_OPEN_CPU
#define MAX_NAME_LENGTH 32
static char company_name[MAX_NAME_LENGTH]= "ASR";
static char product_model[MAX_NAME_LENGTH]= "ASR01";
csi_error_t csi_set_companyname(char* name)
{
    if (!name || strlen(name) >= MAX_NAME_LENGTH) {
        return CSI_ERROR;
    }
    strcpy(company_name, name);
    return CSI_OK;
}

csi_error_t csi_set_productmodel(char* model)
{
    if (!model || strlen(model) >= MAX_NAME_LENGTH) {
        return CSI_ERROR;
    }
    strcpy(product_model, model);
    return CSI_OK;
}

csi_error_t csi_get_companyname(uint8_t* buffer, uint32_t* len)
{
    if (!buffer || !len) {
        return CSI_ERROR;
    }

    size_t name_len = strlen(company_name);
    if (name_len + 1 > *len) {
        return CSI_ERROR; // »º³åÇøÌ«Ð¡£¬ÎÞ·¨ÈÝÄÉ×Ö·û´®ºÍ¿Õ×Ö·û
    }

    strcpy((char*)buffer, company_name);
    *len = (uint32_t)name_len;

    return CSI_OK;
}

csi_error_t csi_get_productmodel(uint8_t* buffer, uint32_t* len)
{
    if (!buffer || !len) {
        return CSI_ERROR;
    }

    size_t model_len = strlen(product_model);
    if (model_len + 1 > *len) {
        return CSI_ERROR; 
    }

    strcpy((char*)buffer, product_model);
    *len = (uint32_t)model_len;

    return CSI_OK;
}

#else

#define COMPANY_NAME      "ASR"
#define PRODUCTMODEL      "ASR01"
csi_error_t csi_get_companyname(uint8_t* buffer, uint32_t* len)
{
    if (!buffer || !len) {
        return CSI_ERROR;
    }

    char *p = (char *)buffer;

    strcpy(p, COMPANY_NAME);
    *len = strlen(p);

    return CSI_OK;
}

csi_error_t csi_get_productmodel(uint8_t* buffer, uint32_t* len)
{
    char *p = (char *)buffer;

    strcpy(p, PRODUCTMODEL);
    *len = strlen(p);

    return CSI_OK;
}
#endif
csi_error_t csi_get_protoctype(uint32_t* ptype)
{
    (void)ptype;
    return CSI_OK;
}

csi_error_t csi_ble_write(uint8_t *data, uint16_t len)
{
    (void)data;
    (void)len;
    return CSI_OK;
}

void csi_log(int level, const char *format, int32_t value)
{
    (void)level;
    (void)format;
    (void)value;
    return ;
}

void csi_log_ext(const char *format, va_list* val_list)
{
#ifdef QUECTEL_OPEN_CPU
    RTI_LOG("%s\n", va_arg(*val_list, char*));
#else
    printf("%s\n", va_arg(*val_list, char*));
#endif
}

csi_error_t csi_open_asset(void **fd, char asset_name[36])
{
    (void)fd;
    (void)asset_name;
    return CSI_OK;
}

csi_error_t csi_write_asset(void* fd,uint32_t offset,void *data,uint32_t data_len)
{
    (void)fd;
    (void)offset;
    if((data == NULL) || (data_len == 0)){
        printf("%s data error\r\n", __func__);
        return CSI_ERROR;
    }
	
	printf("%s enter",__func__);

   // UI_NV_Reset_Default(NV_SECTION_UI_ALIPAY_INFO);
   // UI_NV_Write_Req(NV_SECTION_UI_ALIPAY_INFO, 0, data_len, data);
    return CSI_OK;
}

csi_error_t csi_read_asset(void* fd,uint32_t offset,void *buffer,uint32_t* data_len)
{
    (void)fd;
    (void)offset;
    if ((buffer == NULL) || (data_len == NULL) || (*data_len == 0)) {
        printf("%s buffer error\r\n", __func__);
        return CSI_ERROR;
    }

	printf("%s enter",__func__);
   // UI_NV_Read_Req(NV_SECTION_UI_ALIPAY_INFO, 0, *data_len, buffer);
    return CSI_OK;
}


csi_error_t csi_close_asset(void* fd)
{
    (void)fd;
    return CSI_OK;
}

csi_error_t csi_access_asset(uint32_t *access_flag, char asset_name[36])
{
    (void)access_flag;
    (void)asset_name;
    return CSI_OK;
}

csi_error_t csi_remove_asset(char asset_name[36])
{
    (void)asset_name;
    return CSI_OK;
}

csi_error_t csi_clear_assets(void)
{
    return CSI_OK;
}

csi_error_t csi_get_monotonous_count(uint32_t *counter)
{
    (void)counter;
    return CSI_OK;
}

csi_error_t csi_get_ssk(uint8_t *seed, uint8_t *salt, uint8_t *derived_key, uint8_t derived_key_len)
{
    (void)seed;
    (void)salt;
    (void)derived_key;
    (void)derived_key_len;
    return CSI_OK;
}

csi_error_t csi_aes_init(void *context)
{
    (void)context;
    return CSI_OK;
}

csi_error_t csi_aes_uninit(void *context)
{
    (void)context;
    return CSI_OK;
}

csi_error_t csi_aes_set_encrypt_key(void *context, void *key, uint32_t key_len)
{
    (void)context;
    (void)key;
    (void)key_len;
    return CSI_OK;
}

csi_error_t csi_aes_set_decrypt_key(void *context, void *key, uint32_t key_len)
{
    (void)context;
    (void)key;
    (void)key_len;
    return CSI_OK;
}

csi_error_t csi_aes_ecb_encrypt(void *context, void *in, void *out, uint32_t size)
{
    (void)context;
    (void)in;
    (void)out;
    (void)size;
    return CSI_OK;
}

csi_error_t csi_aes_ecb_decrypt(void *context, void *in, void *out, uint32_t size)
{
    (void)context;
    (void)in;
    (void)out;
    (void)size;
    return CSI_OK;
}

csi_error_t csi_aes_cbc_encrypt(void *context, void *in, void *out, uint32_t size,void *iv)
{
    (void)context;
    (void)in;
    (void)out;
    (void)size;
    (void)iv;
    return CSI_OK;
}

csi_error_t csi_aes_cbc_decrypt(void *context, void *in, void *out, uint32_t size, void *iv)
{
    (void)context;
    (void)in;
    (void)out;
    (void)size;
    (void)iv;
    return CSI_OK;
}

csi_error_t csi_rng_get_data(void *random, uint32_t size)
{
    (void)random;
    (void)size;
    return CSI_OK;
}

csi_error_t csi_sha_init(void *context)
{
    (void)context;
    return CSI_OK;
}

csi_error_t csi_sha_uninit(void *context)
{
    (void)context;
    return CSI_OK;
}

csi_error_t csi_sha_start(void *context, uint32_t mode)
{
    (void)context;
    (void)mode;
    return CSI_OK;
}

csi_error_t csi_sha_update(void *context, void *in, uint32_t size)
{
    (void)context;
    (void)in;
    (void)size;
    return CSI_OK;
}

csi_error_t csi_sha_finish(void *context, void *in, uint32_t size, void *digest)
{
    (void)context;
    (void)in;
    (void)size;
    (void)digest;
    return CSI_OK;
}

csi_error_t csi_sha_digest(void *context, void *in, uint32_t size, void *digest)
{
    (void)context;
    (void)in;
    (void)size;
    (void)digest;
    return CSI_OK;
}

csi_error_t csi_ansx963_kdf(uint8_t *seed, uint8_t *salt, uint8_t *derived_key, uint32_t derived_key_len)
{
    (void)seed;
    (void)salt;
    (void)derived_key;
    (void)derived_key_len;
    return CSI_OK;
}

void *csi_malloc(uint32_t size)
{
    void *p = malloc(size);
    if (p) {
        memset(p, 0, size);
    }

    return p;
}

void *csi_calloc(uint32_t nblock, uint32_t size)
{
    void *p = calloc(nblock, size);
    if (p) {
        memset(p, 0, nblock * size);
    }

    return p;
}

void csi_free(void *pt)
{
    if (pt) {
        free(pt);
    }
}

void *csi_realloc(void *pt, uint32_t size)
{
    return realloc(pt, size);
}

/* 
    èŽ·å–ç¼–è¯‘æ—¶å€™çš„æ—¶é—´æˆ³ï¼Œå•ä½ä¸ºç??
    @return ç¼–è¯‘æ—¶å€™çš„æ—¶é—´æˆ³ï¼Œå•ä½ä¸ºç??
*/
#define dec(ch) ((ch)-'0')
#define t(index, multiplier)    (dec(__TIME__[index]) * (multiplier))
/* only minutes and seconds - you get the idea */
#define mmss()  (t(3,600) + t(4,60) + t(6,10) + t(7,1))

// extracts 1..4 characters from a string and interprets it as a decimal value
#define CONV_STR2DEC_1(str, i)  (str[i]>'0'?str[i]-'0':0)
#define CONV_STR2DEC_2(str, i)  (CONV_STR2DEC_1(str, i)*10 + str[i+1]-'0')
#define CONV_STR2DEC_3(str, i)  (CONV_STR2DEC_2(str, i)*10 + str[i+2]-'0')
#define CONV_STR2DEC_4(str, i)  (CONV_STR2DEC_3(str, i)*10 + str[i+3]-'0')
// Some definitions for calculation
#define SEC_PER_MIN             60UL
#define SEC_PER_HOUR            3600UL
#define SEC_PER_DAY             86400UL
#define SEC_PER_YEAR            (SEC_PER_DAY*365)
#define UNIX_START_YEAR         1970UL
// Custom "glue logic" to convert the month name to a usable number
#define GET_MONTH(str, i)      (str[i]=='J' && str[i+1]=='a' && str[i+2]=='n' ? 1 : \
                                str[i]=='F' && str[i+1]=='e' && str[i+2]=='b' ? 2 : \
                                str[i]=='M' && str[i+1]=='a' && str[i+2]=='r' ? 3 : \
                                str[i]=='A' && str[i+1]=='p' && str[i+2]=='r' ? 4 : \
                                str[i]=='M' && str[i+1]=='a' && str[i+2]=='y' ? 5 : \
                                str[i]=='J' && str[i+1]=='u' && str[i+2]=='n' ? 6 : \
                                str[i]=='J' && str[i+1]=='u' && str[i+2]=='l' ? 7 : \
                                str[i]=='A' && str[i+1]=='u' && str[i+2]=='g' ? 8 : \
                                str[i]=='S' && str[i+1]=='e' && str[i+2]=='p' ? 9 : \
                                str[i]=='O' && str[i+1]=='c' && str[i+2]=='t' ? 10 : \
                                str[i]=='N' && str[i+1]=='o' && str[i+2]=='v' ? 11 : \
                                str[i]=='D' && str[i+1]=='e' && str[i+2]=='c' ? 12 : 0)

#define GET_MONTH2DAYS(month)  ((month == 1 ? 0 : 31 +                  \
                                 (month == 2 ? 0 : 28 +                 \
                                  (month == 3 ? 0 : 31 +                \
                                   (month == 4 ? 0 : 30 +               \
                                    (month == 5 ? 0 : 31 +              \
                                     (month == 6 ? 0 : 30 +             \
                                      (month == 7 ? 0 : 31 +            \
                                       (month == 8 ? 0 : 31 +           \
                                        (month == 9 ? 0 : 30 +          \
                                         (month == 10 ? 0 : 31 +        \
                                          (month == 11 ? 0 : 30)))))))))))) \


#define GET_LEAP_DAYS           ((__TIME_YEARS__-1968)/4 - (__TIME_MONTH__ <=2 ? 1 : 0))

#define __TIME_SECONDS__        CONV_STR2DEC_2(__TIME__, 6)
#define __TIME_MINUTES__        CONV_STR2DEC_2(__TIME__, 3)
#define __TIME_HOURS__          CONV_STR2DEC_2(__TIME__, 0)
#define __TIME_DAYS__           CONV_STR2DEC_2(__DATE__, 4)
#define __TIME_MONTH__          GET_MONTH(__DATE__, 0)
#define __TIME_YEARS__          CONV_STR2DEC_4(__DATE__, 7)

#define __TIME_UNIX__         ((__TIME_YEARS__-UNIX_START_YEAR)*SEC_PER_YEAR+ \
                               GET_LEAP_DAYS*SEC_PER_DAY+               \
                               GET_MONTH2DAYS(__TIME_MONTH__)*SEC_PER_DAY+ \
                               __TIME_DAYS__*SEC_PER_DAY-SEC_PER_DAY+   \
                               __TIME_HOURS__*SEC_PER_HOUR+             \
                               __TIME_MINUTES__*SEC_PER_MIN+            \
                               __TIME_SECONDS__)

csi_error_t csi_get_compile_timestamp(uint32_t *timestamp)
{
    if (timestamp == NULL) {
        return CSI_ERROR;
    }
    *timestamp = __TIME_UNIX__ - (8 * 60 * 60);
    return CSI_OK;
}


void test_iotsec(void)
{
	
	uint8_t buf[40]={0};
	uint32_t len=0;
	csi_get_deviceid(buf, &len);
	printf("%s, deviceid=%s, len=%d", __func__, buf, len);
	
	uint32_t tm=0;
	csi_get_timestamp(&tm);
	printf("%s, time cnt=%d", __func__, tm);
	
	memset(buf,0,sizeof(buf));
	csi_get_sn(buf, &len);
	printf("%s, sn=%s, len=%d", __func__, buf, len);
	
}