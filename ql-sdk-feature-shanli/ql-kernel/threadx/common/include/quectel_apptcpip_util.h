/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/




#ifndef QUECTEL_APPTCPIP_UTIL_H
#define QUECTEL_APPTCPIP_UTIL_H

#include <stdio.h>
#include <string.h>
#include "at_gbl_types.h"


typedef  unsigned char      boolean;     
#define _BOOLEAN_DEFINED

/* Define LOCAL macro if it hasn't already been defined */
#ifndef LOCAL
#define LOCAL static
#endif

/** @cond 
*/
#if defined(DALSTDDEF_H) /* guards against a known re-definer */
#define _BOOLEAN_DEFINED
#define _UINT32_DEFINED
#define _UINT16_DEFINED
#define _UINT8_DEFINED
#define _INT32_DEFINED
#define _INT16_DEFINED
#define _INT8_DEFINED
#define _UINT64_DEFINED
#define _INT64_DEFINED
#define _BYTE_DEFINED
#endif /* #if !defined(DALSTDDEF_H) */
/** @endcond */


#ifndef _UINT16_DEFINED
/** Unsigned 16-bit value.
*/
typedef  unsigned short     uint16;      
#define _UINT16_DEFINED
#endif

#ifndef _UINT8_DEFINED
/** Unsigned 8-bit value. 
*/
typedef  unsigned char      uint8;       
#define _UINT8_DEFINED
#endif


#ifndef _INT16_DEFINED
/** Signed 16-bit value.
*/
typedef  signed short       int16;
#define _INT16_DEFINED
#endif

#ifndef _INT8_DEFINED
/** Signed 8-bit value.
*/
typedef  signed char        int8;        
#define _INT8_DEFINED
#endif

/** @cond
*/
/* This group are the deprecated types.  Their use should be
** discontinued and new code should use the types above
*/
#ifndef _BYTE_DEFINED
/** DEPRECATED: Unsigned 8  bit value type.
*/
typedef  unsigned char      byte;         
#define  _BYTE_DEFINED
#endif

/** DEPRECATED: Unsinged 16 bit value type.
*/
typedef  unsigned short     word;
/** DEPRECATED: Unsigned 32 bit value type.
*/
typedef  unsigned long      dword;        


/** DEPRECATED: Unsigned 8  bit value type.
*/
typedef  unsigned char      uint1;
/** DEPRECATED: Unsigned 16 bit value type.
*/
typedef  unsigned short     uint2;
/** DEPRECATED: Unsigned 32 bit value type.
*/
typedef  unsigned long      uint4;        

/** DEPRECATED: Signed 8  bit value type. 
*/
typedef  signed char        int1;
/** DEPRECATED: Signed 16 bit value type.
*/         
typedef  signed short       int2;
/** DEPRECATED: Signed 32 bit value type. 
*/     
typedef  long int           int4;         

/** DEPRECATED: Signed 32 bit value.
*/
typedef  signed long        sint31;
/** DEPRECATED: Signed 16 bit value. 
*/       
typedef  signed short       sint15;
/** DEPRECATED: Signed 8  bit value.
*/       
typedef  signed char        sint7; 

typedef unsigned int _uint32;
typedef signed int  _int32;

typedef uint16 UWord16;
typedef _uint32 UWord32;  
typedef _int32  Word32;
typedef int16  Word16;
typedef uint8  UWord8;
typedef int8   Word8;
typedef _int32  Vect32;

/** @endcond */

#if (! defined T_WINNT) && (! defined __GNUC__)
  /* Non WinNT Targets */
  #ifndef _INT64_DEFINED
    /** Signed 64-bit value.
	*/
    typedef long long     int64;       
    #define _INT64_DEFINED
  #endif
  #ifndef _UINT64_DEFINED
    /** Unsigned 64-bit value.
	*/
    typedef  unsigned long long  uint64;      
    #define _UINT64_DEFINED
  #endif
#else /* T_WINNT || TARGET_OS_SOLARIS || __GNUC__ */
  /* WINNT or SOLARIS based targets */
  #if (defined __GNUC__) 
    #ifndef _INT64_DEFINED
      typedef long long           int64;
      #define _INT64_DEFINED
    #endif
    #ifndef _UINT64_DEFINED
      typedef unsigned long long  uint64;
      #define _UINT64_DEFINED
    #endif
  #else
    typedef  __int64              int64;       /* Signed 64-bit value */
    #ifndef _UINT64_DEFINED
      typedef  unsigned __int64   uint64;      /* Unsigned 64-bit value */
      #define _UINT64_DEFINED
    #endif
  #endif
#endif /* T_WINNT */

#ifndef _UWORD64_DEFINED
#define _UWORD64_DEFINED
typedef uint64 UWord64 ;
#endif


typedef  unsigned long long    Q_UINT64;
typedef  unsigned int          Q_UINT32;
typedef  unsigned short         Q_UINT16;
typedef  unsigned char          Q_UINT8;
typedef  signed long long       Q_INT64;
typedef  signed  int            Q_INT32;
typedef  signed short            Q_INT16;
typedef  signed char             Q_INT8;
typedef  unsigned char         Q_BOOL ;
typedef signed char              Q_CHAR;
typedef unsigned short         uint16;


#define QUECTEL_FALSE     0
#define QUECTEL_TRUE       1

#define  apptcpip_min_value(a,b)          ((a)<(b))? (a):(b)

#define apptcpip_atoi(nptr)                                     atoi(nptr);
#define apptcpip_strstr(s,substr)                            strstr(s,substr)
#define apptcpip_strchr(s,ch)				   strchr(s,ch)
#define apptcpip_strlen(s)                                       strlen(s)
#define apptcpip_snprintf(s, size, format, ...)         snprintf(s, size, format,...)
#define apptcpip_assert(x)                                      ASSERT(x)
#define apptcpip_min_val(x,y) 	                            ((x)<(y)?(x):(y))


#define APPTCPIP_MAX_SOCKETS                20
#define APPTCPIP_MAX_PDP                        16
#define APPTCPIP_MAX_ACTIVE_PDP          3

#define  APPTCPIP_INVALID_PDP_CID         0xFFFFFFFF


#define  APPTCPIP_MAX_APN_LEN                 128
#define  APPTCPIP_MAX_USERNAME_LEN      128
#define  APPTCPIP_MAX_PASSWORD_LEN     128
#define  APPTCPIP_DNSGIP_MAX_A_ENTRY   5

typedef enum  //09/05/2018 Slark Add parameter to identify the current data read state.
{
	 APPTCPIP_READ_DATA_TYPE_QIRD = 1,
	 APPTCPIP_READ_DATA_TYPE_RCV = 2	
}apptcpip_read_data_type;

typedef enum
{
	APPTCPIP_OK = 0,
    APPTCPIP_ERR_FAILURE=-1,
    APPTCPIP_ERR_WODBLOCK = -2,
    APPTCPIP_ERR_INVALID_PARAM = -3,
    APPTCPIP_ERR_OUT_OF_MEMORY = -4,
    APPTCPIP_ERR_NEW_SOCKET_FAILURE = -5,
    APPTCPIP_ERR_NOT_SUPPORT = -6,
    APPTCPIP_ERR_SOC_BIND_FAILURE = -7,
    APPTCPIP_ERR_SOC_LISTEN_FAILURE = -8,
    APPTCPIP_ERR_SOC_WRITE_FAILURE = -9,
    APPTCPIP_ERR_SOC_READ_FAILURE = -10,
    APPTCPIP_ERR_SOC_ACCEPT_FAILURE = -11,
    APPTCPIP_ERR_OPEN_NETIFACE_FAILURE = -12,
    APPTCPIP_ERR_CLOSE_NETIFACE_FAILURE = -13,
    APPTCPIP_ERR_SOC_INDEX_USED = -14,
    APPTCPIP_ERR_DNS_BUSY = -15,
    APPTCPIP_ERR_DNS_FAILURE = -16,
    APPTCPIP_ERR_SOC_CONNECT_FAILURE = -17,
    APPTCPIP_ERR_SOC_CLOSED = -18,
    APPTCPIP_ERR_OPT_BUSY = -19,
    APPTCPIP_ERR_OPT_TIMEOUT = -20,
    APPTCPIP_ERR_NET_DOWN = -21,
    APPTCPIP_ERR_CANCEL_SEND = -22,
    APPTCPIP_ERR_NOT_ALLOWED = -23,
    APPTCPIP_ERR_SSL_DECRYPT_FAILURE = -24,
    APPTCPIP_ERR_SSL_ENCRYPT_FAILURE = -25,
    APPTCPIP_ERR_SSL_DATA_VERIFY_FAILURE = -26,
    APPTCPIP_ERR_SSL_RESET = -27,
    APPTCPIP_ERR_PORT_BUSY = -28,
    APPTCPIP_ERR_EMPTY_URL = -29,
    APPTCPIP_ERR_INVALID_URL = -30,
    APPTCPIP_ERR_ENCODE_HTTP_HEADER = -31,
    APPTCPIP_ERR_NO_HTTP_RSP = -32,
    APPTCPIP_ERR_HTTP_READ_TIMEOUT = -33,
    APPTCPIP_ERR_HTTP_CMD_TIMEOUT = -34,
    APPTCPIP_ERR_PDP_ACTIVED = -35,
    APPTCPIP_ERR_PDP_UNACTIVED = -36,
    APPTCPIP_ERR_TCP_CONNECT_TIMEOUT = -37,
#ifdef FEATURE_QUECTEL_LOCATOR_APP
    APPTCPIP_ERR_LOCATOR_FAIL = -38,
    APPTCPIP_ERR_LOCATOR_TIMEOUT = -39,
    //Bryce.Code20190321
#if defined(FEATURE_QUECTEL_LOCATOR_QLBS_EXT)
    APPTCPIP_ERR_IMEI_ILLEGAL = -40,//IMEI number is illegal,this error is from server,at response 10001
    APPTCPIP_ERR_TOKEN_DONT_EXIST = -41,//The token does not exist,this error is from server,at response 10002
    APPTCPIP_ERR_TOKEN_BOUND_MAX = -42,//The token is bound to a device that exceeds the maximum value,error from server,at response 10003
    APPTCPIP_ERR_DAILY_MAX_VISIT = -43,//The device's daily targeting exceeds the maximum number of visits,error from server,at response 10004
    APPTCPIP_ERR_TOKEN_MAX_VISIT = -44,//Token location exceeds the maximun number os visits,error from server,at response 10005
    APPTCPIP_ERR_TOKEN_EXPIRED = -45,//Token expired,error from server,at response 10006
    APPTCPIP_ERR_IMEI_INVAlID = -46,//The IMEI number cann't accss the server,error form server,error from server,at response 10007
    APPTCPIP_ERR_TOKEN_DAILY_MAX_VISIT = -47,//Token's daily targeting exceeds the maximum number os visits,error from server,at response 10008
    APPTCPIP_ERR_TOKEN_PERIOD_MAX_VISIT = -48,//The period of the token is more than the maximun number of visits,error from server,at response 10009
    APPTCPIP_ERR_SERVER_BUSY_VISIT = -49,//HTTP busy,error from server,at response 10010
#endif/*end of FEATURE_QUECTEL_LOCATOR_QLBS_EXT*/
#endif/*FEATURE_QUECTEL_LOCATOR_APP*/
}apptcpip_common_err_code;

typedef enum
{
    QUECTEL_SPACE = ' ',
    QUECTEL_EQUAL = '=',
    QUECTEL_COMMA = ',',
    QUECTEL_SEMICOLON = ';',
    QUECTEL_COLON = ':',
    QUECTEL_AT = '@',
    QUECTEL_HAT = '^',
    QUECTEL_DOUBLE_QUOTE = '"',
    QUECTEL_QUESTION_MARK = '?',
    QUECTEL_EXCLAMATION_MARK = '!',
    QUECTEL_FORWARD_SLASH = '/',
    QUECTEL_L_ANGLE_BRACKET = '<',
    QUECTEL_R_ANGLE_BRACKET = '>',
    QUECTEL_L_SQ_BRACKET = '[',
    QUECTEL_R_SQ_BRACKET = ']',
    QUECTEL_L_CURLY_BRACKET = '{',
    QUECTEL_R_CURLY_BRACKET = '}',
    QUECTEL_CHAR_STAR = '*',
    QUECTEL_CHAR_POUND = '#',
    QUECTEL_CHAR_AMPSAND = '&',
    QUECTEL_CHAR_PERCENT = '%',
    QUECTEL_CHAR_PLUS = '+',
    QUECTEL_CHAR_MINUS = '-',
    QUECTEL_CHAR_DOT = '.',
    QUECTEL_CHAR_ULINE = '_',
    QUECTEL_CHAR_TILDE = '~',
    QUECTEL_CHAR_REVERSE_SOLIDUS = '\\',
    QUECTEL_CHAR_VERTICAL_LINE = '|',
    QUECTEL_END_OF_STRING_CHAR = '\0',
    QUECTEL_CHAR_0 = '0',
    QUECTEL_CHAR_1 = '1',
    QUECTEL_CHAR_2 = '2',
    QUECTEL_CHAR_3 = '3',
    QUECTEL_CHAR_4 = '4',
    QUECTEL_CHAR_5 = '5',
    QUECTEL_CHAR_6 = '6',
    QUECTEL_CHAR_7 = '7',
    QUECTEL_CHAR_8 = '8',
    QUECTEL_CHAR_9 = '9',
    QUECTEL_CHAR_A = 'A',
    QUECTEL_CHAR_B = 'B',
    QUECTEL_CHAR_C = 'C',
    QUECTEL_CHAR_D = 'D',
    QUECTEL_CHAR_E = 'E',
    QUECTEL_CHAR_F = 'F',
    QUECTEL_CHAR_G = 'G',
    QUECTEL_CHAR_H = 'H',
    QUECTEL_CHAR_I = 'I',
    QUECTEL_CHAR_J = 'J',
    QUECTEL_CHAR_K = 'K',
    QUECTEL_CHAR_L = 'L',
    QUECTEL_CHAR_M = 'M',
    QUECTEL_CHAR_N = 'N',
    QUECTEL_CHAR_O = 'O',
    QUECTEL_CHAR_P = 'P',
    QUECTEL_CHAR_Q = 'Q',
    QUECTEL_CHAR_R = 'R',
    QUECTEL_CHAR_S = 'S',
    QUECTEL_CHAR_T = 'T',
    QUECTEL_CHAR_U = 'U',
    QUECTEL_CHAR_V = 'V',
    QUECTEL_CHAR_W = 'W',
    QUECTEL_CHAR_X = 'X',
    QUECTEL_CHAR_Y = 'Y',
    QUECTEL_CHAR_Z = 'Z',
    quectel_char_a = 'a',
    quectel_char_b = 'b',
    quectel_char_c = 'c',
    quectel_char_d = 'd',
    quectel_char_e = 'e',
    quectel_char_f = 'f',
    quectel_char_g = 'g',
    quectel_char_h = 'h',
    quectel_char_i = 'i',
    quectel_char_j = 'j',
    quectel_char_k = 'k',
    quectel_char_l = 'l',
    quectel_char_m = 'm',
    quectel_char_n = 'n',
    quectel_char_o = 'o',
    quectel_char_p = 'p',
    quectel_char_q = 'q',
    quectel_char_r = 'r',
    quectel_char_s = 's',
    quectel_char_t = 't',
    quectel_char_u = 'u',
    quectel_char_v = 'v',
    quectel_char_w = 'w',
    quectel_char_x = 'x',
    quectel_char_y = 'y',
    quectel_char_z = 'z',
    QUECTEL_R_BRACKET = ')',  
    QUECTEL_L_BRACKET = '(', 
    QUECTEL_MONEY = '$',
}apptcpip_char_enum;



#define APPTCPIP_IS_LOWER( alpha_char )   \
  ( ( (alpha_char >= quectel_char_a) && (alpha_char <= quectel_char_z) ) ?  1 : 0 )

#define APPTCPIP_IS_UPPER( alpha_char )   \
   ( ( (alpha_char >= QUECTEL_CHAR_A) && (alpha_char <= QUECTEL_CHAR_Z) ) ? 1 : 0 )

#define APPTCPIP_IS_NUMBER( alpha_char )   \
   ( ( (alpha_char >= QUECTEL_CHAR_0) && (alpha_char <= QUECTEL_CHAR_9) ) ? 1 : 0 )

#define APPTCPIP_IS_ALPHA( alpha_char )   \
   ( ( APPTCPIP_IS_UPPER(alpha_char) || APPTCPIP_IS_LOWER(alpha_char) ) ? 1 : 0 )

typedef enum
{
	APPTCPIP_DOT_FORMAT_ADDRESS = 0,
	APPTCPIP_DNS_NAME_ADDRESS,
}apptcpip_host_address_type;

typedef enum
{
    APPTCPIP_IPV4 = 1,
    APPTCPIP_IPV6,
    APPTCPIP_IPV4V6,
}apptcpip_ip_version_type;

//#ifdef FEATURE_QUECTEL_LOCATOR_APP
typedef struct
{
    Q_UINT32  ip_addr;
}apptcpip_ipv4_addr_struct;

typedef struct
{
    Q_UINT64   ip_addr[4];
}apptcpip_ipv6_addr_struct;

typedef struct
{
	Q_UINT32                         ip_vsn;/*quec_ip_addr ,pay serious attention to size differences. 注意结构体大小区别*/
    union
    {
        apptcpip_ipv4_addr_struct    ipv4_addr;
        apptcpip_ipv6_addr_struct    ipv6_addr;
    }addr;
#define  apptcpip_ipv4_addr   addr.ipv4_addr
#define  apptcpip_ipv6_addr   addr.ipv6_addr
}apptcpip_ip_addr_struct;
//#endif

void* apptcpip_alloc_memory
(
size_t size
);

void   apptcpip_free_memory
(
void* mem_ptr
);

void *apptcpip_validate_memory_msg
(
void *data_ptr,
boolean  alloc,
const char *filename,
unsigned int line
);

//ASR平台对同一个地址realloc三次到四次必然dump
//使用时buff必须为char类型
void* apptcpip_mem_realloc
(
void *mem_ptr,
unsigned int buff_len,
unsigned int size
);

Q_BOOL  apptcpip_isdigit
(
Q_CHAR ch
);

void  apptcpip_trim_string_tail
(
Q_CHAR *str
);

void apptcpip_trim_string_head
(
Q_CHAR *str
);


Q_BOOL  apptcpip_is_hex_number
(
Q_CHAR c
);

Q_BOOL apptcpip_is_cr
(
Q_CHAR ch
);

Q_BOOL  apptcpip_is_lf
(
Q_CHAR ch
);

Q_UINT8  apptcpip_hex_2_value
(
Q_CHAR ch
);

Q_INT32  apptcpip_stricmp_bylength
(
Q_CHAR *firststr, 
Q_CHAR *secondstr, 
Q_INT32 length
);

Q_INT32  apptcpip_stricmp_bylength
(
Q_CHAR *firststr, 
Q_CHAR *secondstr, 
Q_INT32 length
);

Q_CHAR* apptcpip_nstrstr_bylength
(
Q_CHAR *srcptr, 
int srcptr_Length, 
Q_CHAR *substr, 
int substr_Length
);

Q_UINT8  apptcpip_integer_to_str
(
Q_UINT8* des_Str,
Q_UINT32 source
);

Q_CHAR *  apptcpip_cstrtok
(
Q_CHAR *s, 
const Q_CHAR *delim
);

Q_INT32  apptcpip_ip_check
(
Q_CHAR *asci_addr,
Q_UINT8 *ip_addr,
Q_BOOL  *ip_validity
);

Q_INT32 apptcpip_tolower
(
Q_INT32  c
);

Q_INT32 apptcpip_toupper
(
Q_INT32  c
);

Q_INT32 apptcpip_strlcpy
(
Q_CHAR *dst, 
const Q_CHAR *src,
Q_INT32  siz
);

Q_BOOL  http_date_2_cclktime
(
Q_UINT8  *httpdate, 
Q_UINT16  httpdatelength, 
Q_UINT8 *cclktime, 
Q_UINT8 cclktimesize
);
int apptcpip_ascii_to_int(char chr);
Q_INT32 apptcpip_strncasecmp(const char *s1, const char *s2, unsigned int n);
Q_INT32 apptcpip_remove_dir_info(Q_UINT8 *no_pre_name);
char* apptcpip_strstri(char * inBuffer, char * inSearchStr);

int apptcpip_search_chr_offset(char *dts, char *str);

int apptcpip_random(unsigned char* output, signed  int len);
int apptcpip_get_random(char *p,  int length);
int dsatutil_strcmp_ig_sp_case
(
  const byte *s1,			  /*  Pointer to string 1 */
  const byte *s2			  /*  Pointer to string 2 */
);
Q_UINT8 quec_crc16_checkout(Q_UINT8 *putMsg,int Datalen);

#endif

