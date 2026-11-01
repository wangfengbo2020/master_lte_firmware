/* lzo_swd.ch -- sliding window dictionary

   This file is part of the LZO real-time data compression library.

   Copyright (C) 1996-2017 Markus Franz Xaver Johannes Oberhumer
   All Rights Reserved.

   The LZO library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   The LZO library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with the LZO library; see the file COPYING.
   If not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

   Markus F.X.J. Oberhumer
   <markus@oberhumer.com>
   http://www.oberhumer.com/opensource/lzo/
 */


#if (LZO_UINT_MAX < LZO_0xffffffffL)
#  error "LZO_UINT_MAX"
#endif
#if defined(LZO_DEBUG)
#  include <stdio.h>
#endif
#if defined(__LZO_CHECKER)
#  include <stdlib.h>
#endif
#include "lzo_mchw.h"


/***********************************************************************
//
************************************************************************/

/* unsigned type for dictionary access - don't waste memory here */
#if (0UL + SWD_N + SWD_F + SWD_F < 65535UL)
   typedef lzo_uint16_t     swd_uint;
#  define SWD_UINT_MAX      0xffffu
#else
   typedef lzo_uint32_t     swd_uint;
#  define SWD_UINT_MAX      0xffffffffu
#endif
#define swd_uintp           swd_uint *
#define SWD_UINT(x)         ((swd_uint)(x))


#ifndef SWD_HSIZE
#  define SWD_HSIZE         16384
#endif
#ifndef SWD_MAX_CHAIN
#  define SWD_MAX_CHAIN     2048
#endif

#if !defined(HEAD3)
#if 1
#  define HEAD3(b,p) \
    ((DMUL(0x9f5f,(((((lzo_xint)b[p]<<5)^b[p+1])<<5)^b[p+2]))>>5) & (SWD_HSIZE-1))
#else
#  define HEAD3(b,p) \
    ((DMUL(0x9f5f,(((((lzo_xint)b[p+2]<<5)^b[p+1])<<5)^b[p]))>>5) & (SWD_HSIZE-1))
#endif
#endif

#if !(SWD_NO_HEAD2) && (SWD_THRESHOLD == 1) && !defined(HEAD2)
#  if 1 && (LZO_OPT_UNALIGNED16)
#    define HEAD2(b,p)      UA_GET_NE16((b)+(p))
#  else
#    define HEAD2(b,p)      (b[p] ^ ((unsigned)b[(p)+1]<<8))
#  endif
#  define NIL2              SWD_UINT_MAX
#endif
#ifndef IF_HEAD2
#define IF_HEAD2(s)         /*empty*/
#endif


typedef struct
{
/* public - "built-in" */
    lzo_uint swd_n;
    lzo_uint swd_f;
    lzo_uint swd_threshold;

/* public - configuration */
    lzo_uint max_chain;
    lzo_uint nice_length;
    lzo_bool use_best_off;
    lzo_uint lazy_insert;

/* public - output */
    lzo_uint m_len;
    lzo_uint m_off;
    lzo_uint look;
    int b_char;
#if defined(SWD_BEST_OFF)
    lzo_uint best_off[ SWD_BEST_OFF ];
#endif

/* semi public */
    LZO_COMPRESS_T *c;
    lzo_uint m_pos;
#if defined(SWD_BEST_OFF)
    lzo_uint best_pos[ SWD_BEST_OFF ];
#endif

/* private */
    const lzo_bytep dict;
    const lzo_bytep dict_end;
    lzo_uint dict_len;

/* private */
    lzo_uint ip;                /* input pointer (lookahead) */
    lzo_uint bp;                /* buffer pointer */
    lzo_uint rp;                /* remove pointer */
    lzo_uint b_size;

    lzo_bytep b_wrap;

    lzo_uint node_count;
    lzo_uint first_rp;

#if defined(__LZO_CHECKER)
    /* malloc arrays of the exact size to detect any overrun */
    unsigned char *b;
    swd_uint *head3;
    swd_uint *succ3;
    swd_uint *best3;
    swd_uint *llen3;
# ifdef HEAD2
    swd_uint *head2;
# endif

#else
    unsigned char b [ SWD_N + SWD_F + SWD_F ];
    swd_uint head3 [ SWD_HSIZE ];
    swd_uint succ3 [ SWD_N + SWD_F ];
    swd_uint best3 [ SWD_N + SWD_F ];
    swd_uint llen3 [ SWD_HSIZE ];
# ifdef HEAD2
    swd_uint head2 [ 65536L ];
# endif
#endif
}
lzo_swd_t;
#define lzo_swd_p   lzo_swd_t *


#define s_b(s)      s->b
#define s_head3(s)  s->head3
#define s_succ3(s)  s->succ3
#define s_best3(s)  s->best3
#define s_llen3(s)  s->llen3
#ifdef HEAD2
#define s_head2(s)  s->head2
#endif
#define SIZEOF_LZO_SWD_T    (sizeof(lzo_swd_t))


/* Access macro for head3.
 * head3[key] may be uninitialized if the list is emtpy,
 * but then its value will never be used.
 */
#if 1 || defined(__LZO_CHECKER)
#  define s_get_head3(s,key) \
        ((swd_uint)((s_llen3(s)[key] == 0) ? SWD_UINT_MAX : s_head3(s)[key]))
#else
#  define s_get_head3(s,key)    (s_head3(s)[key])
#endif


/***********************************************************************
//
************************************************************************/


#define swd_pos2off(s,pos) \
    (s->bp > (pos) ? s->bp - (pos) : s->b_size - ((pos) - s->bp))




/* vim:set ts=4 sw=4 et: */
