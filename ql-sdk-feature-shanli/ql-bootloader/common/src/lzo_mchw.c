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


#include "lzo_swd.h"

extern void swd_accept(lzo_swd_p s, lzo_uint n);

extern void swd_exit(lzo_swd_p s);
extern void swd_findbest(lzo_swd_p s);

extern void swd_getbyte(lzo_swd_p s);

extern int swd_init(lzo_swd_p s, const lzo_bytep dict, lzo_uint dict_len);
/***********************************************************************
//
************************************************************************/

int
init_match ( LZO_COMPRESS_T *c, lzo_swd_p s,
             const lzo_bytep dict, lzo_uint dict_len,
             lzo_uint32_t flags )
{
    int r;

    assert(!c->init);
    c->init = 1;

    s->c = c;

    c->last_m_len = c->last_m_off = 0;

    c->textsize = c->codesize = c->printcount = 0;
    c->lit_bytes = c->match_bytes = c->rep_bytes = 0;
    c->lazy = 0;

    r = swd_init(s,dict,dict_len);
    if (r != LZO_E_OK)
    {
        swd_exit(s);
        return r;
    }

    s->use_best_off = (flags & 1) ? 1 : 0;
    return LZO_E_OK;
}


/***********************************************************************
//
************************************************************************/

int
find_match ( LZO_COMPRESS_T *c, lzo_swd_p s,
             lzo_uint this_len, lzo_uint skip )
{
    assert(c->init);

    if (skip > 0)
    {
        assert(this_len >= skip);
        swd_accept(s, this_len - skip);
        c->textsize += this_len - skip + 1;
    }
    else
    {
        assert(this_len <= 1);
        c->textsize += this_len - skip;
    }

    s->m_len = SWD_THRESHOLD;
    s->m_off = 0;
#ifdef SWD_BEST_OFF
    if (s->use_best_off)
        memset(s->best_pos,0,sizeof(s->best_pos));
#endif
    swd_findbest(s);
    c->m_len = s->m_len;
    c->m_off = s->m_off;

    swd_getbyte(s);

    if (s->b_char < 0)
    {
        c->look = 0;
        c->m_len = 0;
        swd_exit(s);
    }
    else
    {
        c->look = s->look + 1;
    }
    c->bp = c->ip - c->look;

#if 0
    /* brute force match search */
    if (c->m_len > SWD_THRESHOLD && c->m_len + 1 <= c->look)
    {
        const lzo_bytep ip = c->bp;
        const lzo_bytep m  = c->bp - c->m_off;
        const lzo_bytep in = c->in;

        if (ip - in > s->swd_n)
            in = ip - s->swd_n;
        for (;;)
        {
            while (*in != *ip)
                in++;
            if (in == ip)
                break;
            if (in != m)
                if (lzo_memcmp(in,ip,c->m_len+1) == 0)
                    printf("%p %p %p %5d\n",in,ip,m,c->m_len);
            in++;
        }
    }
#endif

/*
    if (c->cb && c->cb->nprogress && c->textsize > c->printcount)
    {
        (*c->cb->nprogress)(c->cb, c->textsize, c->codesize, 0);
        c->printcount += 1024;
    }
*/
    return LZO_E_OK;
}


/* vim:set ts=4 sw=4 et: */
