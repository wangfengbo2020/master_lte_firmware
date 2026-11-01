/* lzo_mchw.ch -- matching functions using a window

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


/***********************************************************************
//
************************************************************************/
#include "lzoconf.h"

typedef struct
{
    unsigned init;

    lzo_uint look;          /* bytes in lookahead buffer */

    lzo_uint m_len;
    lzo_uint m_off;

    lzo_uint last_m_len;
    lzo_uint last_m_off;

    const lzo_bytep bp;
    const lzo_bytep ip;
    const lzo_bytep in;
    const lzo_bytep in_end;
    lzo_bytep out;

    void* cb;

    lzo_uint textsize;      /* text size counter */
    lzo_uint codesize;      /* code size counter */
    lzo_uint printcount;    /* counter for reporting progress every 1K bytes */

    /* some stats */
    lzo_uint lit_bytes;
    lzo_uint match_bytes;
    lzo_uint rep_bytes;
    lzo_uint lazy;

#if defined(LZO1B)
    lzo_uint r1_m_len;

    /* some stats */
    lzo_uint r1_r, m3_r, m2_m, m3_m;
#endif

#if defined(LZO1C)
    lzo_uint r1_m_len;
    lzo_bytep m3;

    /* some stats */
    lzo_uint r1_r, m3_r, m2_m, m3_m;
#endif

#if defined(LZO1F)
    lzo_uint r1_lit;
    lzo_uint r1_m_len;

    /* some stats */
    lzo_uint r1_r, m2_m, m3_m;
#endif

#if defined(LZO1X) || defined(LZO1Y) || defined(LZO1Z)
    lzo_uint r1_lit;
    lzo_uint r1_m_len;

    /* some stats */
    lzo_uint m1a_m, m1b_m, m2_m, m3_m, m4_m;
    lzo_uint lit1_r, lit2_r, lit3_r;
#endif

#if defined(LZO2A)
    /* some stats */
    lzo_uint m1, m2, m3, m4;
#endif
}
LZO_COMPRESS_T;


#define getbyte(c)  ((c).ip < (c).in_end ? *((c).ip)++ : (-1))



