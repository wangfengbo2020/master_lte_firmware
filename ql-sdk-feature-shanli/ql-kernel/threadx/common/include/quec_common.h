/**
 ******************************************************************************
 * @file    quec_common.h
 * @author  Chavis.Chen
 * @version V1.0.0
 * @date    26-Sep-2018
 * @brief   This file contains the common definitions, macros and functions to
 *          be shared throughout the project.
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2014 QUECTEL Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 */


#ifndef _QUEC_COMMON_H
#define _QUEC_COMMON_H

/*> include header files here*/

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "quec_event_def.h"

#ifdef __cplusplus
extern "C" {
#endif


/*========================================================================
 *  Type Definition
 *========================================================================*/


#ifndef uint8
	typedef unsigned char 		uint8;
#endif

#ifndef int8
	typedef signed char 		int8;
#endif

#ifndef uint16
	typedef unsigned short int 	uint16;
#endif

#ifndef int16
	typedef signed short int 	int16;
#endif

#ifndef uint32
	typedef unsigned int 		uint32;
#endif

#ifndef int32
	typedef signed int 			int32;
#endif

#ifndef uint64
	typedef unsigned long long 	uint64;
#endif

#ifndef int64
	typedef signed long long 	int64;
#endif

typedef int QuecOSStatus;

typedef unsigned char				uint8_t;
typedef unsigned short				uint16_t;
typedef unsigned int				uint32_t;
typedef unsigned long long 			uint64_t;
typedef unsigned int				uint_t;
typedef unsigned char				uint_8;
typedef unsigned short				uint_16;
typedef unsigned int				uint_32;
typedef unsigned long long 			uint_64;
typedef signed int					int_32;
typedef signed int                  int32_t;
typedef unsigned char				u8;
typedef unsigned short				u16;
typedef unsigned int				u32;
#define BIT(__n)                    (1U<<(__n))
#define ARRAY_SIZE(a)               (sizeof(a)/sizeof(a[0]))




/*========================================================================
 *  Enumeration Definition
 *========================================================================*/

typedef enum
{
	QUEC_DISABLE = 0,
	QUEC_ENABLE  = 1
} quec_enable_e;


/*========================================================================
 *  ErrNo Definition
 *========================================================================*/

#define kNoErr                      0       //! No error occurred.
#define QUEC_SUCCESS                0       //! No error occurred.
#define kGeneralErr                -1       //! General error.
#define kInProgressErr              1       //! Operation in progress.

/*> Generic error codes are in the range -6700 to -6779.*/
#define kGenericErrorBase           -6700   //! Starting error code for all generic errors.

#define kUnknownErr                 -6700   //! Unknown error occurred.
#define kOptionErr                  -6701   //! Option was not acceptable.
#define kSelectorErr                -6702   //! Selector passed in is invalid or unknown.
#define kExecutionStateErr          -6703   //! Call made in the wrong execution state (e.g. called at interrupt time).
#define kPathErr                    -6704   //! Path is invalid, too long, or otherwise not usable.
#define kParamErr                   -6705   //! Parameter is incorrect, missing, or not appropriate.
#define kUserRequiredErr            -6706   //! User interaction is required.
#define kCommandErr                 -6707   //! Command invalid or not supported.
#define kIDErr                      -6708   //! Unknown, invalid, or inappropriate identifier.
#define kStateErr                   -6709   //! Not in appropriate state to perform operation.
#define kRangeErr                   -6710   //! Index is out of range or not valid.
#define kRequestErr                 -6711   //! Request was improperly formed or not appropriate.
#define kResponseErr                -6712   //! Response was incorrect or out of sequence.
#define kChecksumErr                -6713   //! Checksum does not match the actual data.
#define kNotHandledErr              -6714   //! Operation was not handled (or not handled completely).
#define kVersionErr                 -6715   //! Version is not correct or not compatible.
#define kSignatureErr               -6716   //! Signature did not match what was expected.
#define kFormatErr                  -6717   //! Unknown, invalid, or inappropriate file/data format.
#define kNotInitializedErr          -6718   //! Action request before needed services were initialized.
#define kAlreadyInitializedErr      -6719   //! Attempt made to initialize when already initialized.
#define kNotInUseErr                -6720   //! Object not in use (e.g. cannot abort if not already in use).
#define kAlreadyInUseErr            -6721   //! Object is in use (e.g. cannot reuse active param blocks).
#define kTimeoutErr                 -6722   //! Timeout occurred.
#define kCanceledErr                -6723   //! Operation canceled (successful cancel).
#define kAlreadyCanceledErr         -6724   //! Operation has already been canceled.
#define kCannotCancelErr            -6725   //! Operation could not be canceled (maybe already done or invalid).
#define kDeletedErr                 -6726   //! Object has already been deleted.
#define kNotFoundErr                -6727   //! Something was not found.
#define kNoMemoryErr                -6728   //! Not enough memory was available to perform the operation.
#define kNoResourcesErr             -6729   //! Resources unavailable to perform the operation.
#define kDuplicateErr               -6730   //! Duplicate found or something is a duplicate.
#define kImmutableErr               -6731   //! Entity is not changeable.
#define kUnsupportedDataErr         -6732   //! Data is unknown or not supported.
#define kIntegrityErr               -6733   //! Data is corrupt.
#define kIncompatibleErr            -6734   //! Data is not compatible or it is in an incompatible format.
#define kUnsupportedErr             -6735   //! Feature or option is not supported.
#define kUnexpectedErr              -6736   //! Error occurred that was not expected.
#define kValueErr                   -6737   //! Value is not appropriate.
#define kNotReadableErr             -6738   //! Could not read or reading is not allowed.
#define kNotWritableErr             -6739   //! Could not write or writing is not allowed.
#define kBadReferenceErr            -6740   //! An invalid or inappropriate reference was specified.
#define kFlagErr                    -6741   //! An invalid, inappropriate, or unsupported flag was specified.
#define kMalformedErr               -6742   //! Something was not formed correctly.
#define kSizeErr                    -6743   //! Size was too big, too small, or not appropriate.
#define kNameErr                    -6744   //! Name was not correct, allowed, or appropriate.
#define kNotPreparedErr             -6745   //! Device or service is not ready.
#define kReadErr                    -6746   //! Could not read.
#define kWriteErr                   -6747   //! Could not write.
#define kMismatchErr                -6748   //! Something does not match.
#define kDateErr                    -6749   //! Date is invalid or out-of-range.
#define kUnderrunErr                -6750   //! Less data than expected.
#define kOverrunErr                 -6751   //! More data than expected.
#define kEndingErr                  -6752   //! Connection, session, or something is ending.
#define kConnectionErr              -6753   //! Connection failed or could not be established.
#define kAuthenticationErr          -6754   //! Authentication failed or is not supported.
#define kOpenErr                    -6755   //! Could not open file, pipe, device, etc.
#define kTypeErr                    -6756   //! Incorrect or incompatible type (e.g. file, data, etc.).
#define kSkipErr                    -6757   //! Items should be or was skipped.
#define kNoAckErr                   -6758   //! No acknowledge.
#define kCollisionErr               -6759   //! Collision occurred (e.g. two on bus at same time).
#define kBackoffErr                 -6760   //! Backoff in progress and operation intentionally failed.
#define kNoAddressAckErr            -6761   //! No acknowledge of address.
#define kInternalErr                -6762   //! An error internal to the implementation occurred.
#define kNoSpaceErr                 -6763   //! Not enough space to perform operation.
#define kCountErr                   -6764   //! Count is incorrect.
#define kEndOfDataErr               -6765   //! Reached the end of the data (e.g. recv returned 0).
#define kWouldBlockErr              -6766   //! Would need to block to continue (e.g. non-blocking read/write).
#define kLookErr                    -6767   //! Special case that needs to be looked at (e.g. interleaved data).
#define kSecurityRequiredErr        -6768   //! Security is required for the operation (e.g. must use encryption).
#define kOrderErr                   -6769   //! Order is incorrect.
#define kUpgradeErr                 -6770   //! Must upgrade.
#define kAsyncNoErr                 -6771   //! Async operation successfully started and is now in progress.
#define kDeprecatedErr              -6772   //! Operation or data is deprecated.
#define kPermissionErr              -6773   //! Permission denied.
#define kNotExistErr           		-6774   //! Object is not exist.
#define kOperationErr              	-6775   //! Operate failed.
#define kConfigErr					-6776	//! Configure error.
#define kNotRegisteredErr			-6777	//! Not registered.
#define kBusyErr					-6778	//! Busy error.
#define kNotEnableErr				-6779	//! Not enable error.

#define kGenericErrorEnd            -6780   //! Last generic error code (inclusive)


#define QUEC_ERR_CODE_CONVERT_FROM_ASR(err, os_status)		\
do															\
{															\
	switch(os_status)										\
	{														\
		case OS_SUCCESS:									\
			err = kNoErr;									\
			break;											\
															\
		case OS_FAIL:										\
			err = kGeneralErr;								\
			break;											\
															\
		case OS_TIMEOUT:									\
			err = kTimeoutErr;								\
			break;											\
															\
		case OS_NO_RESOURCES:								\
		case OS_POOL_EMPTY:									\
		case OS_QUEUE_EMPTY:								\
		case OS_NO_MEM_CELLS:								\
			err = kNoResourcesErr;							\
			break;											\
															\
		case OS_INVALID_POINTER:							\
		case OS_INVALID_PTR:								\
		case OS_INVALID_MEMORY:								\
		case OS_INVALID_VECTOR:								\
			err = kValueErr;								\
			break;											\
															\
		case OS_INVALID_REF:								\
			err = kBadReferenceErr;							\
			break;											\
															\
		case OS_INVALID_DELETE:								\
			err = kOperationErr;							\
			break;											\
															\
		case OS_INVALID_SIZE:								\
			err = kSizeErr;									\
			break;											\
															\
		case OS_INVALID_MODE:								\
		case OS_INVALID_PRIORITY:							\
			err = kOptionErr;								\
			break;											\
															\
		case OS_INVALID_PARM:								\
			err = kParamErr;								\
			break;											\
															\
		case OS_UNAVAILABLE:								\
			err = kRequestErr;								\
			break;											\
															\
		case OS_QUEUE_FULL:									\
			err = kNoSpaceErr;								\
			break;											\
															\
		case OS_NO_MEMORY:									\
			err = kNoMemoryErr;								\
			break;											\
															\
		case OS_DELETED:									\
		case OS_SEM_DELETED:								\
		case OS_MUTEX_DELETED:								\
		case OS_MSGQ_DELETED:								\
		case OS_MBOX_DELETED:								\
		case OS_FLAG_DELETED:								\
			err = kDeletedErr;								\
			break;											\
															\
		case OS_NO_TASKS:									\
		case OS_NO_FLAGS:									\
		case OS_NO_SEMAPHORES:								\
		case OS_NO_MUTEXES:									\
		case OS_NO_QUEUES:									\
		case OS_NO_MBOXES:									\
		case OS_NO_TIMERS:									\
		case OS_NO_MEM_POOLS:								\
		case OS_NO_INTERRUPTS:								\
			err = kNotFoundErr;								\
			break;											\
															\
		case OS_FLAG_NOT_PRESENT:							\
			err = kLookErr;									\
			break;											\
															\
		case OS_UNSUPPORTED:								\
			err = kUnsupportedErr;							\
			break;											\
															\
		case OS_DUPLICATE_NAME:								\
			err = kDuplicateErr;							\
			break;											\
															\
		default:											\
			err = kUnknownErr;								\
			break;											\
	}														\
}while(0)


/*========================================================================
 *	Utilities Definition
 *========================================================================*/

/* Get Array Size */
#ifndef QUEC_ARR_SIZE
#define QUEC_ARR_SIZE(a)         	( sizeof(a) / sizeof(a[0]) )
#endif

/* Bit Mask Operation */
#define BIT_MASK(bit)      			(1 << (bit))
#define BIT_CLR(x,bit)     			((x) &= ~ BIT_MASK (bit))
#define BIT_SET(x,bit)     			((x) |= BIT_MASK (bit))
#define CHECK_BIT_SET(x,bit)  		((x) & BIT_MASK (bit))

typedef struct
{
	uint8 rx_data_flag;
	uint8 tx_data_flag;
}quec_debug_port_data_show_s;


#ifdef __cplusplus
} /*"C" */
#endif

#endif




