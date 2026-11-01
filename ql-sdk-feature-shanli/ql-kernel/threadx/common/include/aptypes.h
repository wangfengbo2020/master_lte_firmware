#ifndef APTYPES_H
#define APTYPES_H

#ifdef	__cplusplus
extern "C" {	/* allow C++ to use these headers */
#endif	/* __cplusplus */

    /*
     * Description:
     * macros defining scope (section 5.1.1)
     */
#define PUBLIC              /*specifies an item of public API scope*/
#define PRIVATE static      /*item with scope limited to the module*/
#define PROTECTED           /*item has public scope but is not included in the API*/

    /*
     * Description:
     * Further keywords (section 5.1.2)
     */
#define PACKED __packed     /*defines a packed structure*/
#define INLINE __inline     /*specifies a routine to be in line*/
#define CONST  const        /*defines a constant item*/

    /*
     * Description:
     * specification of primitive types (section 5.1.3)
     */
    typedef unsigned char	BOOL;          //Primitive type - Boolean variable
    typedef signed char     BYTE8;         //Primitive type - signed byte variable
    typedef unsigned char   UBYTE8;        //Primitive type - unsigned byte variable
    typedef short           HWD16;         //Primitive type - half word variable
    typedef long            WORD32;        //Primitive type - (32 bit) word variable
    typedef unsigned short  UHWD16;        //Primitive type - unsigned half word variable
    typedef unsigned long   UWORD32;       //Primitive type - unsigned (32 bit) word variable
    typedef unsigned long long	ULLONG64;  //Primitive type - usigned (64 bit) double word variable


#ifndef S8
    typedef	 char				S8;			/*  signed 8 bit data  */
#endif
#ifndef S16
    typedef	HWD16				S16;		/*  signed 16 bit data */
#endif
#ifndef S32
    typedef	WORD32				S32;		/*  signed 32 bit data */
#endif

#ifndef U8
    typedef	UBYTE8				U8;			/*  unsigned 8 bit data  */
#endif
#ifndef U16
    typedef	UHWD16				U16;		/*  unsigned 16 bit data */
#endif
#ifndef U32
    typedef	UWORD32				U32;		/*  unsigned 32 bit data */
#endif

#ifndef NULL
#define NULL     (void *)0
#endif
    /*
     * Description:
     * specification of additional constants (section 5.1.4)
     */
    /*warning of incompatible definitions*/
#if defined(TRUE) && (TRUE != 1)
#error "TRUE previously defined not equal to 1"
#endif
#if defined(FALSE) && (FALSE != 0)
#error "FALSE previously defined not equal to 0"
#endif

#ifndef TRUE
#define TRUE  (1)
#endif
#ifndef FALSE
#define FALSE (0)
#endif
#define aNULL (void *) 0        /*a null data pointer */
#define aRNULL aNULL            /*a null pointer to a routine*/

    /*
     * Description:
     * additional macros (section 5.1.5)
     */
#ifndef IGNORE
#define IGNORE(_v) ((void)(_v))     /*indicates that the parameter is not used (for expansion)*/
#endif

    /*
     * Description:
     * Inline functions implemented as macros.  Not included in the standard
     */
/*The larger of __x and __y*/
#ifndef FAT_MAX
#define FAT_MAX(__x,__y) ((__x)>(__y)?(__x):(__y))
#endif

/*The smaller of __x and __y*/
#ifndef FAT_MIN
#define FAT_MIN(__x,__y) ((__x)<(__y)?(__x):(__y))
#endif

    /*
     * Description:
     * Debug macros.  Not included in the current release of the standard
     *
     * Implementation:
     * The debug macros are controlled as follows:
     * + apDEBUG - if this is not defined, all debugs are disabled
     * + apDEBUG_LEVEL - this may be:
     *      - undefined / 0 : all debug macros used
     *      - 1 : only warning/critical debug macros enabled
     *      - 2 : only critical debug macros enabled
     * + apDEBUG_BUFFER - if this is defined, debugs are written to a buffer.  Otherwise,
     *   debug data is written to stderr.  If a debug buffer is used, the following variables
     *   MUST be declared in a source file.
     *      - PUBLIC  int apDEBUG_Counter=0;
     *      - PUBLIC  char  apDEBUG_Working[apDEBUG_PRINTF_MAX];
     *      - PUBLIC  char  apDEBUG_Buffer[apDEBUG_BUFFER_SIZE]="<#>";
     * + apDEBUG_BUFFER_SIZE - if a debug buffer is used, this defines the size (default 1024).
     * + apDEBUG_PRINTF_MAX - if a debug buffer is used, this defines the largest size of a printf().
     *        There is no checking that this is not exceeded.  (default 128)
     *
     * Remarks:
     * The macros are as follows:
     * + apDEBUG_ENABLED - this constant is used internally.  If defined, the code is running in debug mode.
     * + apDEBUG_INFO(__s,__d) - Used to output debug information.  The two arguments are passed
     *   to printf.  Typical usage: apDEBUG_INFO("Current status: %x\n",StatusWord);
     * + apDEBUG_WARN(__s,__d) - Used to output warning information.  The two arguments are passed
     *   to printf.
     * + apDEBUG_CRIT(__s,__d) - Used to output critical information.  The two arguments are passed
     *   to printf.
     *
     * When a buffer is specified, the data is written into the buffer.  Data is written into consecutive
     * locations in the buffer, returing to the start if the buffer is full.  No debug message is ever
     * split, although a long message may be truncated by the end of the buffer.  The end of the latest
     * message is marked by the token '<#>'.
    */
#if 0
#ifndef apDEBUG
#undef  apDEBUG_ENABLED
#ifndef apASSERT
#define apASSERT(__x)
#endif
#define apDEBUG_INFO(__s,__d)
#define apDEBUG_WARN(__s,__d)
#define apDEBUG_CRIT(__s,__d)
#else
#ifndef apDEBUG_ENABLED
#define apDEBUG_ENABLED 1
#endif
#define apDEBUG_MODE
#ifndef assert
#include <assert.h>
#endif
#include <stdio.h>
#include <string.h>
#define apASSERT(__x)               assert(__x)
#ifdef apDEBUG_BUFFER
#ifndef apDEBUG_BUFFER_SIZE
#define apDEBUG_BUFFER_SIZE 1024
#endif
#ifndef apDEBUG_PRINTF_MAX
#define apDEBUG_PRINTF_MAX 128
#endif
#define apDEBUG_PRINT(__s,__d)  { \
                                      /*reference the external variables*/ \
                                      extern  WORD32 apDEBUG_Counter; \
                                      extern  char  apDEBUG_Working[apDEBUG_PRINTF_MAX]; \
                                      extern  char  apDEBUG_Buffer[apDEBUG_BUFFER_SIZE]; \
                                      UWORD32 CopySize;                  /*bytes to copy*/ \
                                      UWORD32 CopyPtr;                   /*pointer when copying*/ \
                                      sprintf(apDEBUG_Working,__s,__d);  /*do the printf*/ \
                                      /*wrap the buffer if required*/ \
                                      if (apDEBUG_Counter > apDEBUG_BUFFER_SIZE - (apDEBUG_PRINTF_MAX<<1)) \
                                        {/*clear the rest of the buffer*/ \
                                        for (CopyPtr=apDEBUG_Counter;CopyPtr<apDEBUG_BUFFER_SIZE-1;CopyPtr++) \
                                              {apDEBUG_Buffer[CopyPtr]='\0';} \
                                        apDEBUG_Counter=0;}             /*reset the pointer*/ \
                                      /*restrict to available bytes*/ \
                                      CopySize = MIN(strlen(apDEBUG_Working), apDEBUG_BUFFER_SIZE - apDEBUG_Counter - 3 ); \
                                      /*copy to buffer, substituting '|' for '\n'*/ \
                                      for (CopyPtr=0;CopyPtr<CopySize;CopyPtr++) \
                                        {apDEBUG_Buffer[apDEBUG_Counter++]= \
                                         (char) ((apDEBUG_Working[CopyPtr]!='\n') ? apDEBUG_Working[CopyPtr] : '|') ;} \
                                      strcpy(&apDEBUG_Buffer[apDEBUG_Counter],"<#>"); /*mark the end*/ \
                                      }
#else
    /*we don't generate printfs during ISRs*/
#define apDEBUG_PRINT(__s,__d)  {if (apOS_CoreIRQGet()) fprintf(stderr,__s,__d);}
#endif
#if !defined(apDEBUG_LEVEL) || (apDEBUG_LEVEL == 0)
#define apDEBUG_INFO(__s,__d)   {apDEBUG_PRINT(__s,__d);}
#else
#define apDEBUG_INFO(__s,__d)
#endif
#if !defined(apDEBUG_LEVEL) || (apDEBUG_LEVEL <= 1)
#define apDEBUG_WARN(__s,__d)   {apDEBUG_PRINT(__s,__d);}
#else
#define apDEBUG_WARN(__s,__d)
#endif
#define apDEBUG_CRIT(__s,__d)       {apDEBUG_PRINT(__s,__d);}
#endif
#endif
    /*
     * Description:
     * General function types
     */
    typedef void (*apTYPE_rCallback) (UWORD32);		/* general purpose callback for handling errors etc. */


#ifdef __cplusplus
} /* allow C++ to use these headers */
#endif	/* __cplusplus */

#endif
