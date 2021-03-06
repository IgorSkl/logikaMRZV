/*------------------------------------------------------------------------------
* Created (c) 2014 - Factory “KyivPrylad”
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
* File Name       : var_r_ef.h
* Description     : Variables exchange  on 
                    BM BR 
					  external function & data for  BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  21/08/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#ifndef	VAR_R_EF_H
#define	VAR_R_EF_H


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#include "hv_df.h"
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
extern CfgTblDsc brCfgTbl;//Main CfgTbl on BR
extern char chbrCfgTblUsedIci     ;
extern char chbrCfgTblModifyIci   ;

//Interface to EEPROM & APCS 
//

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       Перечень констант которые возвращают функции                      ~~~~~
//~~~       обработки запросов                        ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
#define START_EXEC        1 
#define STATE_EXEC        2
#define SUCCESS_EXEC      3
#define ERROR_EXEC        4
//``````````````````````````````````````````````````````````````````````````````````
//~~~   возврат START_EXEC    - Запрос успешно принят 
//~~~   возврат STATE_EXEC    - Идет обработка предыдущего запроса
//~~~   возврат SUCCESS_EXEC  - Запрос успешно обработан
//~~~   возврат ERROR_EXEC    - Ошибка при приеме запроса
//..................................................................................
#define ERROR 4
#define OK    3

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern long GetMeasPrt(void *pvMeasAddr);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~     функция запроса/получения  __MEASUREMENT_TO_PROTECTION             ~~~~~
//~~~                                                                  ~~~~~
//~~~                                                                          ~~~~~
//~~~    Возвращаемое значение                                                 ~~~~~
//~~~    1 - команда начала выполняться                                        ~~~~~
//~~~    2 - система МПО(межпроцесорного обмена)  находится                     ~~~
//~~~         в состоянии выполнении запроса                                   ~~~~~
//~~~    3 - команда выполнена успешно                                         ~~~~~
//~~~    4 - возникла  ошибка при старте, передаче,                            ~~~~~
//~~~     или данные недостоверны                                              ~~~~~
 
//``````````````````````````````````````````````````````````````````````````````````
//~~~   pvMeasAddr  - По данному адресу в случае успеха будут помещены        ~~~~~
//~~~   данные  __MEASUREMENT_TO_PROTECTION                      ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~  Описание __MEASUREMENT_TO_PROTECTION    должно находиться в файле       ~~~~~
//~~~   .hvps29_07_14\HR1_0100_00_I670\doc\Таблица структуры защит.docx        ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~  Для указателя pvMeasAddr                                                ~~~~~
//~~~ !!ПАМЯТЬ НЕОБХОДИМО РАЗМЕЩАТЬ ПО ВЫРОВНЕННЫМ НА ГРАНИЦУ 32 БИТА СЛОВАМ !!! ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~   __MEASUREMENT_TO_PROTECTION locMeasProtection;                                      ~~~~~
//~~~  int res;                                                                ~~~~~
//~~~  res =  GetMeasPrt(&locMeasProtection);                                  ~~~~~
//~~~   активировать передачу массива                                          ~~~~~
//~~~                                                                          ~~~~~
//~~~                                                                          ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~   res =  GetMeasPrt(&locMeasProtection);                                 ~~~~~
//~~~   опрос состояния обработки данных                                       ~~~~~
//~~~   STATE_EXEC  -- Wait                                                    ~~~~~
//~~~   SUCCESS_EXEC -- Ok                                                     ~~~~~
//~~~   возврат ERROR_EXEC - Ошибка при приеме данных                          ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""





#endif