/* ###########################################################################
###  Intel Confidential
###  Copyright (c) Intel Corporation 1995-2002
###  All Rights Reserved.
###  -------------------------------------------------------------------------
###  Project: Flash Data Integrator
###
###  Module: FDI_FILE.H - The file support API shall exist as a software layer
###                       that utilizes the standard FDI API functions.  The
###                       file API shall be implemented with an ANSI stdio
###                       interface.  The file API provides file information
###                       associated with each file.  The application shall be
###                       responsible for sorting the file info.
###
###  $Archive: /FDI/SRC/FM_INC/fdi_file.h $
###  $Revision: 41 $
###  $Date: 3/09/04 4:30p $
###  $Author: Hwang10 $
###  $NoKeywords $
########################################################################### */

/*
 *****************************************************************
 * NOTICE OF LICENSE AGREEMENT
 *
 * This code is provided by Intel Corp., and the use is governed
 * under the terms of a license agreement. See license agreement
 * for complete terms of license.
 *
 * YOU MAY ONLY USE THE SOFTWARE WITH INTEL FLASH PRODUCTS.  YOUR
 * USE OF THE SOFTWARE WITH ANY OTHER FLASH PRODUCTS IS EXPRESSLY
 * PROHIBITED UNLESS AND UNTIL YOU APPLY FOR, AND ARE GRANTED IN
 * INTEL'S SOLE DISCRETION, A SEPARATE WRITTEN SOFTWARE LICENSE
 * FROM INTEL LICENSING ANY SUCH USE.
 *****************************************************************
 */


#ifndef FDI_FILE_H
#define FDI_FILE_H

#include "FDI_TYPE.h"

#if (FILE_MANAGER == TRUE)

/* ### Local Declarations
 * ################################# */

/* invalid filename characters */
#define FILE_SCWILDCARD '?'  /* Wildcard for single character */
#define FILE_MCWILDCARD '*'  /* Wildcard for multiple characters */
#define FILE_SPECIALAT '@'  /* Wildcard for multiple characters */
#define FILE_EOS        '\0' /* Terminating character marks end of string */

/* names for bits in st_mode
 */
#define S_IRWXU      0x01c0         /* RWE permissions mask for owner */
#define S_IRUSR      0x0100         /* owner may read */
#define S_IWUSR      0x0080         /* owner may write */
#define S_IXUSR      0x0040         /* owner may execute <directory search> */
#define S_IRWXG      0x0038         /* RWE permissions mask for group */
#define S_IRGRP      0x0020         /* group may read */
#define S_IWGRP      0x0010         /* group may write */
#define S_IXGRP      0x0008         /* group may execute <directory search> */
#define S_IRWXW      0x0007         /* RWE permissions mask for world */
#define S_IRWLD      0x0004         /* world may read */
#define S_IWWLD      0x0002         /* world may write */
#define S_IXWLD      0x0001         /* world may execute <directory search> */

/*
 * sleep(n):  replace with appropriate delay...
 * This value '60' was set based on the ARM clock speed
 */
/*FDI 5.0 for CCDi SYS  start */
 /*E.5.0.604.START*/
//#define FDI_NO_SLEEP TRUE
//#define FDI_NO_SLEEP FALSE

#if (FDI_NO_SLEEP == TRUE)
extern SEM_ID PERF_SEM_Bkgd;
#define  fdi_sleep(n)                 SEM_WAIT(PERF_SEM_Bkgd);
#else
#define  fdi_sleep(n)                 FDI_TaskDelayMsec(n)
#endif
 /*E.5.0.604.END*/
/*FDI 5.0 for CCDi SYS  end */

/*E.5.0.702.Start*/
/* changge name from TASK_DELAY to FILE_TASK_DELAY_TIME to avoid confusion*/
#define  FILE_TASK_DELAY_TIME              20      /* used as input to sleep
                                                    * macro... delay is
                                                    * equivalent to 50ms */
/*E.5.0.702.End*/

/* Constants for Origin indicating the position relative to which fseek
 * sets the file position. Enclosed in ifdefs because the OS may have these
 defined in their file system */

#ifndef SEEK_SET
//#define SEEK_SET    (0)
#endif

#ifndef SEEK_CUR
//#define SEEK_CUR    (1)
#endif

#ifndef SEEK_END
//#define SEEK_END    (2)
#endif

/*
 * gettime():  replace with appropriate OS actual time function
 *             to stamp the files with
 */
#define  gettime()               FileGetTime()

/*
 * getdate():  replace with appropriate OS actual date function
 *             to stamp the files with
 */
#define  getdate()               FileGetDate()

/*
 * getgid():  replace with appropriate OS actual getgid function
 */
#define  getgid()                FileGetGID()

 /*
 * getuid():  replace with appropriate OS actual getuid function
 */
#define  getuid()                FileGetUID()


/* ### Global Declarations
 * ################################# */
/*elevy - on the first integration phase our code will still use FDI7 interface to access GFS
  since _FDI_VER_71_ flag is not define we add DATALIGHT instead*/
#if (!defined(_FDI_VER_71_)) && (!defined(GFS_API))
typedef unsigned short FILE_ID; /* identifier for the file stream */
#else
typedef unsigned short FILE_ID; /* identifier for the file stream */
#endif //_FDI_VER_71_

typedef struct tag_file_info
{
   /* filename plus end of string character */
   FDI_TCHAR file_name[FILE_NAME_SIZE + 1];
   int       time;          /* updated time stamp when modified */
   int       date;          /* updated date stamp when modified */
   DWORD     size;          /* size of file data in bytes */
   WORD      permissions;
#ifndef LTEONLY_THIN
   WORD      owner_id;
   WORD      group_id;
   FILE_ID   data_id;       /* FDI identifier for file data */

   /* the following fields are needed for power loss recovery */

   FILE_ID   plr_id;        /* used for power loss recovery */
   int       plr_time;      /* used for power loss recovery */
   int       plr_date;      /* used for power loss recovery */
   DWORD     plr_size;      /* used for power loss recovery */
#endif
} FILE_INFO;


/*
 * USAGE:
 *    file_identifier = FDI_fopen(filename_ptr, wb);
 */
FILE_ID FDI_fopen(const FDI_TCHAR *, const char *);

/*
 * USAGE:
 *    file_identifier = FDI_fopen(filename_ptr, wb);
 */
FILE_ID  FDI_fopen_fatsys(const char *, const char *);

/*
 * USAGE:
 *    actual_written = FDI_fwrite(&new_struct, sizeof(NEW_STRUCT), 1, file_id);
 */
size_t FDI_fwrite(const void *, size_t, size_t, FILE_ID);

/*
 * USAGE:
 *    actual_written = FDI_fwrite(&new_struct, sizeof(NEW_STRUCT), 1, file_id);
 */
size_t FDI_fwrite_fatsys(const void *, size_t, size_t, FILE_ID);


/*
 * USAGE:
 *    actual_written = FDI_fwrite(&new_struct, sizeof(NEW_STRUCT), 1, file_id);
 */
size_t FDI_fwriteEx_fatsys(const void *, size_t, size_t, FILE_ID, UINT32);


/* USAGE:
 *    actual_read = FDI_fread(&new_struct, sizeof(NEW_STRUCT), 1, stream_id);
 */
size_t FDI_fread(void *, size_t, size_t, FILE_ID);

/* USAGE:
 *    actual_read = FDI_fread(&new_struct, sizeof(NEW_STRUCT), 1, stream_id);
 */
size_t FDI_fread_fatsys(void *, size_t, size_t, FILE_ID);

/* USAGE:
 *    actual_read = FDI_fread(&new_struct, sizeof(NEW_STRUCT), 1, stream_id);
 */
size_t FDI_freadEx_fatsys(void *, size_t, size_t, FILE_ID, UINT32);

/*
 * USAGE:
 *    close_status = FDI_fclose(stream_identifier);
 */
int FDI_fclose(FILE_ID);

/*
 * USAGE:
 *    close_status = FDI_fclose(stream_identifier);
 */
int FDI_fclose_fatsys(FILE_ID);


/*
 * USAGE:
 *    status = FDI_fseek(stream_identifier, offset, wherefrom);
 */
int FDI_fseek(FILE_ID, long, int);

/*
 * USAGE:
 *    status = FDI_fseek(stream_identifier, offset, wherefrom);
 */
int FDI_fseek_fatsys(FILE_ID, long, int);

/*
 * USAGE:
 *    status = FDI_fsize_fatsys();
 */
unsigned int FDI_fsize_fatsys(FILE_ID);

/*
 * USAGE:
 *    status = FDI_findfirst(filename_ptr, &the_file_info);
 */
int FDI_findfirst(const FDI_TCHAR *, FILE_INFO *);

/*
 * USAGE:
 *    status = FDI_findfirst(filename_ptr, &the_file_info);
 */
int FDI_findfirst_fatsys(const char *, FILE_INFO *);


/*
 * USAGE:
 *    status = FDI_findnext(&the_file_info);
 */
int FDI_findnext(FILE_INFO *);


/*
 * USAGE:
 *    status = FDI_findnext(&the_file_info);
 */
int FDI_findnext_fatsys(FILE_INFO *);

/*
 * USAGE:
 *    status = FDI_remove(filename_ptr);
 */
int FDI_remove(const FDI_TCHAR *);

/*
 * USAGE:
 *    status = FDI_remove(filename_ptr);
 */
int FDI_remove_fatsys(const char *);


/*
 * USAGE:
 *    status = FDI_rename(oldfilename_ptr, newfilename_ptr);
 */
int FDI_rename(const FDI_TCHAR *, const FDI_TCHAR *);

/*
 * USAGE:
 *    status = FDI_rename(oldfilename_ptr, newfilename_ptr);
 */
int FDI_rename_fatsys(const FDI_TCHAR *, const FDI_TCHAR *);

/*
 * USAGE:
 *    status = FDI_fileinit(data_stream_enable);
 */
int FDI_fileinit(int);

/*
 * USAGE:
 *    status = FDI_feof(stream);
 */
int FDI_feof(FILE_ID);

/*
 * USAGE:
 *    status = FDI_feof(stream);
 */
int FDI_feof_fatsys(FILE_ID);

/*
 * USAGE:
 *    fdi_status = FDI_ferror(stream);
 */
ERR_CODE FDI_ferror(FILE_ID);

/*
 * USAGE:
 *    fdi_status = FDI_ferror(stream);
 */
ERR_CODE FDI_ferror_fatsys(FILE_ID);

/*
 * USAGE:
 *    FDI_clearerr(stream);
 */
void FDI_clearerr(FILE_ID);

/*
 * function: CHMOD - changes file access mode
 *
 * syntax: int FDI_chmod(const FDI_TCHAR *path, int st_mode);
 */
int FDI_chmod(const FDI_TCHAR *, int);

/*
 * function: CHMOD - changes file access mode
 *
 * syntax: int FDI_chmod(const FDI_TCHAR *path, int st_mode);
 */
int FDI_chmod_fatsys(const FDI_TCHAR *, int);

/*
 * function: STAT - gets permissions on file
 *
 * syntax: int FDI_stat(FDI_TCHAR *path, int *mode_buf);
 */
int FDI_stat(const FDI_TCHAR *, int *);

/*
 * function: STAT - gets permissions on file
 *
 * syntax: int FDI_stat(FDI_TCHAR *path, int *mode_buf);
 */
int FDI_stat_fatsys(const FDI_TCHAR *, int *);

/*
 * function: FCHMOD - changes open file access mode
 *
 * syntax: int FDI_fchmod(FILE_ID open_file, int st_mode);
 */
int FDI_fchmod(FILE_ID, int);

/*
 * function: FSTAT - gets permissions on the open file
 *
 * syntax: int FDI_fstat(FILE_ID open_file, int *mode_buf);
 */
int FDI_fstat(FILE_ID, int *);

/*
 * function: FTELL - gets open file's file pointer
 *
 * syntax: int FDI_ftell(FILE_ID open_file);
 */
int FDI_ftell(FILE_ID);

/*
 * function: FTELL - gets open file's file pointer
 *
 * syntax: int FDI_ftell(FILE_ID open_file);
 */
int FDI_ftell_fatsys(FILE_ID);


/*
 * USAGE:
 *    status = FDI_fileterminate();
 */
int FDI_fileterminate(void);

/*
 * USAGE:
 *    status = FDI_Format_fatsys();
 */
ERR_CODE FDI_Format_fatsys(void);

/*
 * USAGE:
 *    size = FDI_GetFreeSpaceSize_fatsys();
 */
unsigned int FDI_GetFreeSpaceSize_fatsys(void);

/*
 * USAGE:
 *    size = FDI_GetUsedSpaceSize_fatsys();
 */
unsigned int FDI_GetUsedSpaceSize_fatsys(void);

/*
 * USAGE:
 *    status = FDI_OpenDir();
 */
FILE_ID FDI_OpenDir(const char *);


/*
 * USAGE:
 *    fdi_status = FDI_DirRead;
 */
int FDI_DirRead(FILE_ID, FILE_INFO *);

/*
 * USAGE:
 *    fdi_status = FDI_CloseDir;
 */
int FDI_CloseDir(FILE_ID);

#endif /* FILE_MANAGER */

#endif /* FDI_FILE_H */
