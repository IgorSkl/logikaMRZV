/*------------------------------------------------------------------------------
* Copyright (c) 2013 - Factory “KyivPrylad”
* 
* Permission to use, copy, modify, and distribute this software for any
* purpose with or without fee is hereby granted, provided that the above
* copyright notice and this permission notice appear in all copies.
* 
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
* 
*------------------------------------------------------------------------------
*
* Processor       : Lpc_3240
* File Name       : hu7lI.h
* Description     : Interface for the hu7l.c
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  02/09/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef  hu7lI_h
#define  hu7lI_h

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
extern long outU7(unsigned char *dat,  int bytes);
extern long inU7 (unsigned char *buff, int bytes);
extern long outU1(unsigned char *dat,  int bytes);
extern long inU1 (unsigned char *buff, int bytes);
extern long outU2(unsigned char *dat,  int bytes);
extern long inU2 (unsigned char *buff, int bytes);
extern long outU3(unsigned char *dat,  int bytes);
extern long inU3 (unsigned char *buff, int bytes);

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//extern 
//extern 
//extern 



#endif /* hu7lI_h */