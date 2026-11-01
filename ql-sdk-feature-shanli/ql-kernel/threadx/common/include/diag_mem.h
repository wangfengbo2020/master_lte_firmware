/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code ("Material") are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel's prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/

#if !defined (__DIAG_MEM_H__)
#define	__DIAG_MEM_H__

#define INTIF_CICLIC_BUFF_FREE_ONE_ENTRY 0
#define INTIF_CICLIC_BUFF_MAX_ENTRY_TO_FREE 8192
#if defined (USE_DIAG_MEM_POOL)
DIAG_EXPORT void	InitDiagMemoryPool	(void);
DIAG_EXPORT void 	*DiagMemPoolAlignMalloc	(UINT32 size);
DIAG_EXPORT void 	DiagMemPoolAlignFree	(void* alignAddress);

#endif	// USE_DIAG_MEM_POOL

typedef void *	(*DiagMemAlloctionFn) (UINT32 size);
typedef void 	(*DiagMemFreeFn) (void *	block);
DIAG_EXPORT void *malloc( unsigned int Size );
DIAG_EXPORT void *DiagAlignMalloc	(UINT32 size);
DIAG_EXPORT void DiagAlignFree		(void* alignAddress);

DIAG_EXPORT BOOL SetDiagMemFns (DiagMemAlloctionFn diagMemAllocationFn, DiagMemFreeFn diagMemFreeFn);
#if defined (INTIF_CYCLIC_BUFF)
DIAG_EXPORT BOOL DiagMemFreeInternalItem( UINT32 nBytes ) ; //Ian
#endif

#endif	// __DIAG_MEM_H__
