#ifndef _DIAGCOMMSD_H_
#define _DIAGCOMMSD_H_
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                diag_comm_sd.h


GENERAL DESCRIPTION

    This file is for diag communication with SD card.

EXTERNALIZED FUNCTIONS

INITIALIZATION AND SEQUENCING REQUIREMENTS

   Copyright (c) 2011 by Marvell, Incorporated.  All Rights Reserved.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when         who        what, where, why
--------   ------     ----------------------------------------------------------
07/25/2013   zhoujin    Created module
===========================================================================*/


/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/

#include "osa.h"
#include "diag.h"
#include "UART.h"
#include <stdlib.h>
#include <string.h>
#include "platform.h"

/*===========================================================================

                                LOCAL MACRO
===========================================================================*/

/* Diag comm sdl version. */
#define DIAG_COMM_SDL_VERSION                   0x01

/* Diag comm sdl head version. */
#define DIAG_COMM_SDL_HDR_VER                   0x01

/* Diag comm sdl data format. */
#define DIAG_COMM_SDL_DATA_FORMAT               0x01

/* Diag comm sdl check sum. */
#define DIAG_COMM_SDL_CHECK_SUM                 0x00

/* Diag comm sdl flush count. */
#define DIAG_COMM_SDL_FLUSH_CNT                 0x14

/* Diag invalid SDL dir index. */
#define DIAG_INVALID_DIR_INDEX                  0xFACEFACE

/* Diag comm sd initialize done. */
#define DIAG_COMM_SD_INIT_DONE                  0xBEADBEEF

/* Diag comm max sdl size. */
#define DIAG_COMM_MAX_SDL_SIZE                  0x2000000

/* Diag comm sdl file name. */
#define DIAG_SDL_FILE                           ".sdl"

/* Diag comm sdl dir name. */
#define DIAG_SD_DIR_NAME                        "SD"

/* Diag sdl dir name format. */
#define DIAG_SDL_DIR_FORMAT                     "C:\\ACAT%u\\"

/* Diag sdl file name format. */
#define DIAG_SD_FILE_FORMAT                     "C:\\ACAT%u\\%u%s"

/* Diag sdl file open error. */
#define DIAG_SD_FOPEN_ERROR                     "FS_Open %s error!"

/* Diag sdl file write error. */
#define DIAG_SD_FWRITE_ERROR                    "FS_Write error: 0x%x"

/* Diag sdl file seek error. */
#define DIAG_SD_FSEEK_ERROR                     "FS_Seek error: 0x%x"

/* Diag create dir error. */
#define DIAG_SD_MDIR_ERROR                      "MD %s error: 0x%x!"

/* Diag SDL uninitialized. */
#define DIAG_SD_UNINIT_ERROR                    "Set SDL uninitialized!"

/* Diag sdl file handle error. */
#define DIAG_SD_INVALID_FD                      "Invalid fd: 0x%x, 0x%x"

/* Diag SDL space error. */
#define DIAG_SD_SPACE_ERROR                     "SD has no free space!"

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      DiagSDLog                                                        */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function output trace information via uart port.            */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      fmt                                 Format parameters            */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
#define DiagSDLog(fmt,args...)           RTI_LOG(fmt, ##args)

/*===========================================================================

                          Struct definition.

===========================================================================*/

/* Diag comm sdl head */
typedef struct diag_comm_sdl_hdr{
	UINT32      hdverion;
	UINT32      format;
	UINT32      apverion;
	UINT32      cpverion;
	UINT32      sequence;
	UINT32      date;
	UINT32      checksum;
}diag_comm_sdl_hdr;

/* Diag comm sd log information */
typedef struct diag_comm_sd_log_info{
    UINT32      flag;
    UINT32      size;
    UINT32      dindex;
    UINT32      findex;
	UINT16      uname[30];
	char        fname[40];
	UINT32      fd;
}diag_comm_sd_log_info;

/*===========================================================================

            EXTERN DECLARATIONS FOR MODULE

===========================================================================*/


/*===========================================================================

                        EXTERN FUNCTION DECLARATIONS

===========================================================================*/

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      get_log_sd_free_space                                            */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function get the free space of SD card.                     */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      size                                Memory size                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
UINT32 get_log_sd_free_space(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      m_atoi                                                           */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function convert integer into string.                       */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      size                                Memory size                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
UINT32 m_atoi(const char * string_ptr);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      m_atoi_dec                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function convert string into integer.                       */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      size                                Memory size                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
UINT32 m_atoi_dec(const char * string_ptr);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      m_strlen                                                         */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function calculate string length.                           */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      size                                Memory size                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
UINT32 m_strlen(const char *string);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diagCommSdLogEnable                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function check whether the Diag SD logging is enable or not. */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
extern BOOL diagCommSdLogEnable(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      DumpFileToSDEnable                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function Check whether dump bin files to SD card is enable  */
/*      or not.                                                          */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      size                                Memory size                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
extern BOOL DumpFileToSDEnable(void);

/*===========================================================================

                          INTERNAL FUNCTION DECLARATIONS

===========================================================================*/
/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diag_online_sdl_enable                                           */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function check whether the online sd log is enable or not.   */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
BOOL diag_online_sdl_enable(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      DiagCommSDMutexInit                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function initialize the diag SD log mutex.                   */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void DiagCommSDMutexInit(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      DiagCommSDMutexLock                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function lock the diag SD log mutex.                         */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void DiagCommSDMutexLock(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      DiagCommSDMutexUnlock                                            */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function unlock the diag SD log mutex.                       */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void DiagCommSDMutexUnlock(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diag_comm_log_init                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function initialize the diag communication log.              */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void diag_comm_log_init(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diag_comm_create_sdl_file                                        */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function create SDL file name.                               */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
BOOL diag_comm_create_sdl_file(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diag_comm_check_sdl_dir                                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function check whether the SDL directory exists.             */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                TRUE/FALSE                   */
/*                                                                       */
/*************************************************************************/
BOOL diag_comm_check_sdl_dir(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diag_comm_sd_init                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function initialize the diag SD communication.               */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
BOOL diag_comm_sd_init(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diag_comm_sd_uninit                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function uninitialize the diag SD communication.             */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
BOOL diag_comm_sd_uninit(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diag_comm_sd_get_hdr                                             */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function get the sdl head.                                   */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
diag_comm_sdl_hdr *diag_comm_sd_get_hdr(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diag_comm_sd_get_info                                            */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function get the diag sd information.                        */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
diag_comm_sd_log_info *diag_comm_sd_get_info(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diag_comm_transmit_finish                                        */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function finish the SD logging.                              */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void diag_comm_transmit_finish(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diag_comm_transmit_to_sd                                         */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function transmit the diag lod to SD card.                   */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      Data                                Diag message                 */
/*      Length                              Message length               */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
BOOL diag_comm_transmit_to_sd(char* data, UINT32 length);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diag_comm_create_sdl_file_in_assert                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function create new sdl file in system assert.               */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void diag_comm_create_assert_sdl(void);

#endif
