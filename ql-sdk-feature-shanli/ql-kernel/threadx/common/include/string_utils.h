/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/




#ifndef _STRING_UTILS_H
#define _STRING_UTILS_H


#include "quec_common.h"


#ifndef STR
	#define STR(x)		#x
#endif


/*-----------------------------------------------------------------------------------------
 * Function: Convert lowercase letters to uppercase letters.
 *
 * Parameter:
 *    <str>: 	[IN] point to the target string.
 *    <maxLen>: [IN] the max length you want to convert from the beginning of target string.
 *
 * Return:
 *    NULL: when exection error occurs.
 *    The pointer to the converted string.
-----------------------------------------------------------------------------------------*/
extern char * 	str2upper(char * str, uint32 maxLen);



/*-----------------------------------------------------------------------------------------
 * Function: Convert uppercase letters to lowercase letters.
 *
 * Parameter:
 *    <str>: 	[IN] point to the target string.
 *    <maxLen>: [IN] the max length you want to convert from the beginning of target string.
 *
 * Return:
 *    NULL: when exection error occurs.
 *    The pointer to the converted string.
-----------------------------------------------------------------------------------------*/
extern char * 	str2lower(char * str, uint32 maxLen);



/*-----------------------------------------------------------------------------------------
 * Function: Replace some of the same characters in a string.
 *
 * Parameter:
 *    <str>: 			[IN] point to the target string.
 *    <maxLen>: 		[IN] the max length you want to process from the begining of string.
 *    <toFind>: 		[IN] the character that to be replaced.
 *    <replaceWith>: 	[IN] the character that will be replaced with.
 *	  <n>				[IN] indicated how many characters are replaced at most.
 *
 * Return:
 *    NULL: when exection error occurs.
 *    The pointer to the replaced string.
-----------------------------------------------------------------------------------------*/
extern char * strReplace(char * str, uint32 maxLen, char toFind, char replaceWith, uint32 n);

/*-----------------------------------------------------------------------------------------
 * Function: Convert the decimal string to 32 bits integer.
 *
 * Parameter:
 *    <str>: 		[IN] 	point to the target string.
 *    <maxLen>: 	[IN] 	the max length you want to convert from the beginning of target string.
 *    <intgr_ptr>:	[OUT]	point to the converted result.
 *
 * Return:
 *    TRUE: 	convert successfully.
 *    FALSE:	convert failed.
 *
 * Note:
 *    1. We support the negative decimal string converting.
 *    2. We most take the first TEN continuous decimal characters for converting,
 *       cause that the maximal value of int-type is 2147483647.
 *    3. You can set the value of <maxLen> greater than the target string length, we take the smaller one
-----------------------------------------------------------------------------------------*/
extern bool 	str2int32(char * str, uint32 maxLen, int * intgr_ptr);



/*-----------------------------------------------------------------------------------------
 * Function: Convert the hexadecimal string to 32 bits integer.
 *
 * Parameter:
 *    <str>: 		[IN] 	point to the target string.
 *    <maxLen>: 	[IN] 	the max length you want to convert from the beginning of target string.
 *    <intgr_ptr>:	[OUT]	point to the converted result.
 *
 * Return:
 *    TRUE: 	convert successfully.
 *    FALSE:	convert failed.
 *
 * Note:
 *    1. We most take the first EIGTH continuous hexadecimal characters for converting,
 *       cause that the maximal value of int-type is FFFFFFFF.
 *    2. You can set the value of <maxLen> greater than the target string length, we take the smaller one
-----------------------------------------------------------------------------------------*/
extern bool 	hexstr2int32(char * str, uint32 maxLen, int * intgr_ptr);



/*-----------------------------------------------------------------------------------------
 * Function: Convert the hexadecimal string to 64 bits integer.
 *
 * Parameter:
 *    <str>: 		[IN] 	point to the target string.
 *    <maxLen>: 	[IN] 	the max length you want to convert from the beginning of target string.
 *    <intgr_ptr>:	[OUT]	point to the converted result.
 *
 * Return:
 *    TRUE: 	convert successfully.
 *    FALSE:	convert failed.
 *
 * Note:
 *    1. We most take the first SIXTEEN continuous hexadecimal characters for converting,
 *       cause that the maximal value of int64-type is 0xFFFFFFFFFFFFFFFF.
 *    2. You can set the value of <maxLen> greater than the target string length, we take the smaller one
-----------------------------------------------------------------------------------------*/
extern bool 	hexstr2int64(char * str, uint32 maxLen, int64 * intgr_ptr);

extern char * 	data2CString( const uint8_t *inBuf, size_t inBufLen );

extern char *  	cstrtok(char *s, const char *delim);

char* quec_strdup(const char* str);

int quec_utf8_to_usc2(unsigned char *utf8_data,int utf8_data_len, unsigned int *usc2_data);

int quec_usc2_to_utf8(unsigned int *usc2_data, int usc2_data_len, unsigned char *utf8_data);

#endif

