#ifndef __QL_UPDATER_USR_FUNC_H__
#define __QL_UPDATER_USR_FUNC_H__

/**
 * General error code definitions	for FBF parse		0x0 - 0x1F
 **/
#define QL_Error_base							(0xFFFF0000)
#define QL_NoError            					(QL_Error_base + 0x0)
#define QL_NotFoundError      					(QL_Error_base + 0x1)
#define QL_GeneralError       					(QL_Error_base + 0x2)
#define QL_WriteError         					(QL_Error_base + 0x3)
#define QL_ReadError		   					(QL_Error_base + 0x4)
#define QL_NotSupportedError  					(QL_Error_base + 0x5)
#define QL_InvalidPlatformConfigError			(QL_Error_base + 0x6)
#define QL_InvalidPlatformState				    (QL_Error_base + 0x7)

#define QL_InvalidSizeError					    (QL_Error_base + 0x9)
#define QL_ProbeListExhaustError				(QL_Error_base + 0xA)
#define QL_DDR_NotInitializedError				(QL_Error_base + 0xB)
#define QL_UnknownReservedPackage				(QL_Error_base + 0xD)
#define QL_NULLPointer							(QL_Error_base + 0xE)
#define QL_NANDIDDISMATCH						(QL_Error_base + 0xF)
#define QL_FBF_VersionNotMatch					(QL_Error_base + 0x10)
#define QL_FBF_DeviceMoreThanOne				(QL_Error_base + 0x11)
#define QL_FBF_CheckSumError                    (QL_Error_base + 0x12)
#define QL_FBF_UniqueError                      (QL_Error_base + 0x13
#define QL_NotEnoughMomeryError                 (QL_Error_base + 0x14)
#define NotEnoughFlashError                     (QL_Error_base + 0x15)
#define QL_CRCFailedError						(QL_Error_base + 0x16)
#define QL_DFota_ImageDFotaDecodeFailed		    (QL_Error_base + 0x17)
#define QL_DFota_LZMADecompressFailed			(QL_Error_base + 0x18)
#define QL_DFota_NotFoundRelevantFile			(QL_Error_base + 0x19)
#define QL_DFota_GetOldFileSizeError			(QL_Error_base + 0x20)
#define QL_DFota_BspatchFailed					(QL_Error_base + 0x21)
#define QL_DFota_CRCFailedError				    (QL_Error_base + 0x22)
#define QL_DFota_MINI_StatusError				(QL_Error_base + 0x23)
#define QL_DFota_MINI_MagicError				(QL_Error_base + 0x24)

#define QL_DFota_ImageNumTooLarger				(QL_Error_base + 0x25)
#define QL_DFota_WriteFlashCheckFailed			(QL_Error_base + 0x26)
#define QL_DFota_MagicError					    (QL_Error_base + 0x27)
#define QL_FotaImageSizeTooLarger				(QL_Error_base + 0x28)
#define QL_NotOtaUpdaterError					(QL_Error_base + 0x29)




extern void ql_updater_usr_func_init(void);
extern void ql_upgrade_percent_callback(unsigned int percent);
extern void ql_set_external_fs_info(int *port, int *clk, unsigned int *start_addr, unsigned int *size);
#endif
