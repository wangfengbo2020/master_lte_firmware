#ifndef FATTYPES_H
#define FATTYPES_H

#include <time.h>

#include "timeM.h"

#include "aptypes.h"

struct CardInformation
{
    unsigned long int
    CardSize,
    SectorSize;
};

extern BOOL isFATInit ;

/*
 * Description:
 * Number of sectors to cache
 *
 * Remarks:
 * Each cache entry takes 520 bytes
 *
 */
//#define fatTYPE_SECTOR_CACHE_SIZE	8

/*
 * Description:
 * If fatTYPE_WRITE_UPDATE_DIR is defined, timestamp and size will be updated
 * every fatIO_Write (Unix), otherwise, they will be updated by fatIO_Close (DOS)
 *
 * Remarks:
 * None
 *
 */
// #define fatTYPE_WRITE_UPDATE_DIR

/*
 * Description:
 * Maximum path length
 *
 * Remarks:
 * Defined by ISO 9293:1987 Section 6.5
 *
 */
#define fatTYPE_MAX_PATH		64

/*
 * Description:
 * Maximum length of a filename
 *
 * Remarks:
 * None
 *
 */
#define fatTYPE_FNAME_SIZE		8

/*
 * Description:
 * Maximum length of an extension
 *
 * Remarks:
 * None
 *
 */
#define fatTYPE_FEXT_SIZE		3

/*
 * Description:
 * Maximum length of a filename "8.3"
 *
 * Remarks:
 * None
 *
 */
#define fatTYPE_FILENAME_SIZE	(fatTYPE_FNAME_SIZE + fatTYPE_FEXT_SIZE + 2)

/*
 * Description:
 * Maximum length of a volume label
 *
 * Remarks:
 * None
 *
 */
#define fatTYPE_VOLUME_SIZE     11

#ifndef HAL_FATTYPES_FLAG
#define FATTYPES_FLAG
typedef enum fatTYPE_eErrors
{
    fatTYPE_SUCCESS 			= 0,			/* Successful operation */
    fatTYPE_BAD_FORMAT 			= -0x1,   	    /* Disk not FAT12/FAT16 */
    fatTYPE_FREE_CLUSTER 		= -0x2,			/* Unused cluster in the FAT table */
    fatTYPE_BAD_CLUSTER 		= -0x3,			/* Defective cluster */
    fatTYPE_FINAL_CLUSTER 		= -0x4,			/* Final cluster in a FAT chain */
    fatTYPE_BAD_LINK 			= -0x5,			/* Entry in the FAT table points to itself */
    fatTYPE_NO_FREE_CLUSTERS 	= -0x6,			/* No free clusters */
    fatTYPE_NO_ENTRY 			= -0x7,			/* File or directory does not exist */
    fatTYPE_NOT_EMPTY 			= -0x8,			/* Directory contains files or sub-directories */
    fatTYPE_EXIST 				= -0x9,			/* Directory or file already exists */
    fatTYPE_ROOT_DIR_FULL 		= -0xA,			/* Root directory contains 512 entries */
    fatTYPE_ACCESS 				= -0xB,			/* Access to file denied */
    fatTYPE_BAD_HANDLE 			= -0xC,			/* Handle is not connected with an open file */
    fatTYPE_BAD_PARAM 			= -0xD,			/* Illegal parameter to an operation */
    fatTYPE_INVALID 			= -0xE,			/* Attempt to put file position before the start of a file */
    fatTYPE_FAIL_MALLOC 		= -0xF,			/* fail to malloc memory */
    fatTYPE_NO_PRE_CLUSTER 		= -0x10,        /* reach the start of a cluster chain*/
    fatTYPE_PHYSICAL_ERROR 		= -0x11,         /* errors of the low driver when operate the SD card*/
    fatTYPE_NOT_INITIALIZE 		= -0x12,         /* FAT module is not initialize rright */
    
    fatTYPE_ERR_MAX 			= 0xFFFFFFF         /* FAT module is not initialize rright */
} fatTYPE_eErrors;
#endif

typedef WORD32 apError;

extern BOOL isFat32;
extern UWORD32 BootClus32;
#define FAT_FAIL(s)		( s < fatTYPE_SUCCESS )
#define FAT_SUCCESS(s)	(s >= fatTYPE_SUCCESS )

#define RETURN_ON_ERROR(f) { apError Error = f; if (FAT_FAIL(Error)) return Error; }

typedef UWORD32	fatTYPE_tSector;
typedef UWORD32	fatTYPE_tCluster;
typedef UWORD32 fatTYPE_tEntry;

#ifndef HAL_FATTYPES_FLAG
typedef enum fatTYPE_eAttributes
{
    fatTYPE_NORMAL	= 0,		/* Writable file */
    fatTYPE_RDONLY	= 0x01,		/* Read Only file */
    fatTYPE_HIDDEN	= 0x02,		/* Hidden from directory view */
    fatTYPE_SYSTEM	= 0x04,		/* Owned by the operating system */
    fatTYPE_VOLUME	= 0x08,		/* Volume label entry */
    fatTYPE_DIR		= 0x10,     /* Sub-directory */
    fatTYPE_ARCHIVE	= 0x20,		/* Copy of the file exists on this or another medium */
    fatTYPE_LONG_NAME = fatTYPE_RDONLY | fatTYPE_HIDDEN | fatTYPE_SYSTEM | fatTYPE_VOLUME
} fatTYPE_eAttributes;
#endif


#ifndef HAL_FATTYPES_FLAG
typedef UWORD32 fatTYPE_tSize;

typedef struct
{
    fatTYPE_eAttributes	st_mode;	/* File or directory attributes */
    fatTYPE_tSize		st_size;	/* File size in bytes */
    time_t				st_time;	/* Timestamp of last modification */
} fatTYPE_sStat;
#endif

#define fatTYPE_CURRENT_DIR				"."
#define fatTYPE_CURRENT_DIR_CHAR		'.'
#define fatTYPE_PARENT_DIR				".."
#define fatTYPE_SEPARATOR				"\\"
#define fatTYPE_SEPARATOR_CHAR			'\\'
#define fatTYPE_ALT_SEPARATOR_CHAR		'/'
#define fatTYPE_WILDCARD_SINGLE_CHAR	'?'
#define fatTYPE_WILDCARD_MULTI_CHAR		'*'
#define fatTYPE_PAD_CHAR                ' '
#define fatTYPE_FNAME_EXT_CHAR          '.'

#ifndef HAL_FATTYPES_FLAG
#define fatTYPE_READ			0x01
#define fatTYPE_WRITE			0x02
#endif

#endif

