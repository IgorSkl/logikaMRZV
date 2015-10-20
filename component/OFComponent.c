#ifndef _HIDE_COMPONENT
/*
#include <vcl.h>
#include <strstrea.h>
#include <math.h>
#include <mem.h>
#include <fstream.h>
#include <strstrea.h>
#include <iomanip.h>
#pragma hdrstop

#include "vmenuDis.h"
*/

#include <stdio.h>
#include <string.h>

#include "bazisdef.h"
#include "component\componentdef.h"
#include "virtualMenu\systemmenudef.h"
#include "virtualMenu\ustmanagerdef.h"

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "logictimers\logictimersfnc.h"

#include "virtualMenu\viewMenuList.h"

#include "psupervisor\psupervisor.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"

//код компонентов
#define KOD_COMPONENT  OF_COMP1

#endif // _HIDE_COMPONENT

//РАСПРЕДЕЛЕНИЕ УСТАВОК  в менеджере уставок
//уставка выдержки
#define MNGPAUSA_OF1    0
#define MNGPAUSA_OF2    1
#define MNGPAUSA_OF3    2
#define MNGPAUSA_OF4    3
#define MNGPAUSA_OF5    4
#define MNGPAUSA_OF6    5
#define MNGPAUSA_OF7    6
#define MNGPAUSA_OF8    7
#define MNGPAUSA_OF9    8
#define MNGPAUSA_OF10   9
#define MNGPAUSA_OF11   10
#define MNGPAUSA_OF12   11
#define MNGPAUSA_OF13   12
#define MNGPAUSA_OF14   13
#define MNGPAUSA_OF15   14
#define MNGPAUSA_OF16   15

#define MNGWORK_OF1     16
#define MNGWORK_OF2     17
#define MNGWORK_OF3     18
#define MNGWORK_OF4     19
#define MNGWORK_OF5     20
#define MNGWORK_OF6     21
#define MNGWORK_OF7     22
#define MNGWORK_OF8     23
#define MNGWORK_OF9     24
#define MNGWORK_OF10    25
#define MNGWORK_OF11    26
#define MNGWORK_OF12    27
#define MNGWORK_OF13    28
#define MNGWORK_OF14    29
#define MNGWORK_OF15    30
#define MNGWORK_OF16    31

//уставка управления
#define MNGUPR_OF       32
//к-во уставок в менеджере уставок
#define MNGUST_OF_TOTAL  33

//РАСПРЕДЕЛЕНИЕ ENA команд
#define ENA_OF_1  0
#define ENA_OF_2  1
#define ENA_OF_3  2
#define ENA_OF_4  3
#define ENA_OF_5  4
#define ENA_OF_6  5
#define ENA_OF_7  6
#define ENA_OF_8  7
#define ENA_OF_9  8
#define ENA_OF_10 9
#define ENA_OF_11 10
#define ENA_OF_12 11
#define ENA_OF_13 12
#define ENA_OF_14 13
#define ENA_OF_15 14
#define ENA_OF_16 15
//к-во ENA команд
#define ENACMD_OF_TOTAL 16

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//к-во уставок в супервизоре
#define SPVUST_OF_TOTAL  0

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ OF
//ОФ1
#define IOCMD_IN_OF1  0
#define IOCMD_OUT_OF1 1
//ОФ2
#define IOCMD_IN_OF2  2
#define IOCMD_OUT_OF2 3
//ОФ3
#define IOCMD_IN_OF3  4
#define IOCMD_OUT_OF3 5
//ОФ4
#define IOCMD_IN_OF4  6
#define IOCMD_OUT_OF4 7
//ОФ5
#define IOCMD_IN_OF5  8
#define IOCMD_OUT_OF5 9
//ОФ6
#define IOCMD_IN_OF6  10
#define IOCMD_OUT_OF6 11
//ОФ7
#define IOCMD_IN_OF7  12
#define IOCMD_OUT_OF7 13
//ОФ8
#define IOCMD_IN_OF8  14
#define IOCMD_OUT_OF8 15
//ОФ9
#define IOCMD_IN_OF9  16
#define IOCMD_OUT_OF9 17
//ОФ10
#define IOCMD_IN_OF10  18
#define IOCMD_OUT_OF10 19
//ОФ11
#define IOCMD_IN_OF11  20
#define IOCMD_OUT_OF11 21
//ОФ12
#define IOCMD_IN_OF12  22
#define IOCMD_OUT_OF12 23
//ОФ13
#define IOCMD_IN_OF13  24
#define IOCMD_OUT_OF13 25
//ОФ14
#define IOCMD_IN_OF14  26
#define IOCMD_OUT_OF14 27
//ОФ15
#define IOCMD_IN_OF15  28
#define IOCMD_OUT_OF15 29
//ОФ16
#define IOCMD_IN_OF16  30
#define IOCMD_OUT_OF16 31

//ОT1
#define IOCMD_BKL_OT1  32
#define IOCMD_OTKL_OT1 33
#define IOCMD_OUT_OT1  34
//ОT2
#define IOCMD_BKL_OT2  35
#define IOCMD_OTKL_OT2 36
#define IOCMD_OUT_OT2  37
//ОT3
#define IOCMD_BKL_OT3  38
#define IOCMD_OTKL_OT3 39
#define IOCMD_OUT_OT3  40
//ОT4
#define IOCMD_BKL_OT4  41
#define IOCMD_OTKL_OT4 42
#define IOCMD_OUT_OT4  43
//ОT5
#define IOCMD_BKL_OT5  44
#define IOCMD_OTKL_OT5 45
#define IOCMD_OUT_OT5  46
//ОT6
#define IOCMD_BKL_OT6  47
#define IOCMD_OTKL_OT6 48
#define IOCMD_OUT_OT6  49
//ОT7
#define IOCMD_BKL_OT7  50
#define IOCMD_OTKL_OT7 51
#define IOCMD_OUT_OT7  52
//ОT8
#define IOCMD_BKL_OT8  53
#define IOCMD_OTKL_OT8 54
#define IOCMD_OUT_OT8  55

//к-во IO команд
#define IOCMD_OF_TOTAL    56

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ OF
//к-во TL команд
#define TLCMD_OF_TOTAL    0

//--------------- TIMERS ------------------
//РАСПРЕДЕЛЕНИЕ ТАЙМЕРОВ ДЛЯ OF
//таймер паузы ОФ1
#define TIMERP_OF1  0
//таймер работы ОФ1
#define TIMERR_OF1  1
//таймер паузы ОФ2
#define TIMERP_OF2  2
//таймер работы ОФ2
#define TIMERR_OF2  3
//таймер паузы ОФ3
#define TIMERP_OF3  4
//таймер работы ОФ3
#define TIMERR_OF3  5
//таймер паузы ОФ4
#define TIMERP_OF4  6
//таймер работы ОФ4
#define TIMERR_OF4  7
//таймер паузы ОФ5
#define TIMERP_OF5  8
//таймер работы ОФ5
#define TIMERR_OF5  9
//таймер паузы ОФ6
#define TIMERP_OF6  10
//таймер работы ОФ6
#define TIMERR_OF6  11
//таймер паузы ОФ7
#define TIMERP_OF7  12
//таймер работы ОФ7
#define TIMERR_OF7  13
//таймер паузы ОФ8
#define TIMERP_OF8  14
//таймер работы ОФ8
#define TIMERR_OF8  15
//таймер паузы ОФ9
#define TIMERP_OF9  16
//таймер работы ОФ9
#define TIMERR_OF9  17
//таймер паузы ОФ10
#define TIMERP_OF10  18
//таймер работы ОФ10
#define TIMERR_OF10  19
//таймер паузы ОФ11
#define TIMERP_OF11  20
//таймер работы ОФ11
#define TIMERR_OF11  21
//таймер паузы ОФ12
#define TIMERP_OF12  22
//таймер работы ОФ12
#define TIMERR_OF12  23
//таймер паузы ОФ13
#define TIMERP_OF13  24
//таймер работы ОФ13
#define TIMERR_OF13  25
//таймер паузы ОФ14
#define TIMERP_OF14  26
//таймер работы ОФ14
#define TIMERR_OF14  27
//таймер паузы ОФ15
#define TIMERP_OF15  28
//таймер работы ОФ15
#define TIMERR_OF15  29
//таймер паузы ОФ16
#define TIMERP_OF16  30
//таймер работы ОФ16
#define TIMERR_OF16  31
//к-во таймеров
#define TIMERS_OF_TOTAL   32

#ifndef _HIDE_COMPONENT

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре
extern int  IndexIO;//индекс IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern char *bitStringUNI[];
extern int  timerEnableWL;//разрешение работы таймеров РЛ

void PereinitUstListCompOF(short flg);
void UstListCompOF();
void ustRedactorCompOF();
void UstCompOF();
short  KadrMenuFormat_ust_compOF(void *workCntr);

void PereinitUprListCompOF(short flg);
void UprListCompOF();
void uprRedactorCompOF();
void UprCompOF();
short  KadrMenuFormat_upr_compOF(void *workCntr);
int  initUstOF(char init);
void  prepareUstOF(short idxC);

//int ViewerEditUstOF();
//int ViewerEditVidOF();
void EditUstOF();
//void EditVidOF();
void EditUprOF();
int codecUstOF(char codec, short offset, int ust);
int   isDISactiv_OF(int idxC);
void  logicOF(int idxC);

char *selectorUprStrOF(short iBit, UNS_32 ustUpr);

int  offsetIOCmdOF;//смещение для IO OF
int  offsetIOCmdOF_loc;//смещение для IO OF

IONAMESTATUS_COMPONENT ionsOF[IOCMD_OF_TOTAL] =
{
  {
    1,//статус iocmd1
    "Пуск О-функция 1"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 1"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 2"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 2"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 3"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 3"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 4"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 4"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 5"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 5"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 6"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 6"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 7"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 7"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 8"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 8"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 9"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 9"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 10"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 10"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 11"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 11"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 12"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 12"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 13"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 13"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 14"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 14"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 15"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 15"
  },
  {
    1,//статус iocmd1
    "Пуск О-функция 16"
  },
  {
    1,//статус iocmd1
    "Вых О-функция 16"
  },

  {
    1,//статус iocmd1
    "ВКЛ О-Триггер 1"
  },
  {
    1,//статус iocmd1
    "ОТКЛ О-Триггер 1"
  },
  {
    1,//статус iocmd1
    "Вых О-Триггер 1"
  },
  {
    1,//статус iocmd1
    "ВКЛ О-Триггер 2"
  },
  {
    1,//статус iocmd1
    "ОТКЛ О-Триггер 2"
  },
  {
    1,//статус iocmd1
    "Вых О-Триггер 2"
  },
  {
    1,//статус iocmd1
    "ВКЛ О-Триггер 3"
  },
  {
    1,//статус iocmd1
    "ОТКЛ О-Триггер 3"
  },
  {
    1,//статус iocmd1
    "Вых О-Триггер 3"
  },
  {
    1,//статус iocmd1
    "ВКЛ О-Триггер 4"
  },
  {
    1,//статус iocmd1
    "ОТКЛ О-Триггер 4"
  },
  {
    1,//статус iocmd1
    "Вых О-Триггер 4"
  },
  {
    1,//статус iocmd1
    "ВКЛ О-Триггер 5"
  },
  {
    1,//статус iocmd1
    "ОТКЛ О-Триггер 5"
  },
  {
    1,//статус iocmd1
    "Вых О-Триггер 5"
  },
  {
    1,//статус iocmd1
    "ВКЛ О-Триггер 6"
  },
  {
    1,//статус iocmd1
    "ОТКЛ О-Триггер 6"
  },
  {
    1,//статус iocmd1
    "Вых О-Триггер 6"
  },
  {
    1,//статус iocmd1
    "ВКЛ О-Триггер 7"
  },
  {
    1,//статус iocmd1
    "ОТКЛ О-Триггер 7"
  },
  {
    1,//статус iocmd1
    "Вых О-Триггер 7"
  },
  {
    1,//статус iocmd1
    "ВКЛ О-Триггер 8"
  },
  {
    1,//статус iocmd1
    "ОТКЛ О-Триггер 8"
  },
  {
    1,//статус iocmd1
    "Вых О-Триггер 8"
  },
};

LineMenuItem sub_menu_comp_OF[8] =
{
  { "Опред функции", NULL},//title
  { &CONTROL1_COMP, &sub_menu_cnf, typeMenuSub},//control_item, parent
  { "Таймера ОФ",    (void *)&UstListCompOF, typeMenuProg},
  { "Управление ОФ", (void *)&UprListCompOF, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compOF[] =
{
  { "Таймера Опред функций", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_OF, typeMenuList},//control_item, parent
/*
  { "Таймер паузы ОФ1",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ1", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ2",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ2", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ3",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ3", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ4",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ4", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ5",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ5", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ6",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ6", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ7",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ7", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ8",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ8", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ9",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ9", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ10",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ10", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ11",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ11", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ12",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ12", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ13",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ13", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ14",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ14", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ15",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ15", (void *)&UstCompOF, typeMenuProg},
  { "Таймер паузы ОФ16",  (void *)&UstCompOF, typeMenuProg},
  { "Таймер работы ОФ16", (void *)&UstCompOF, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compOF[] =
{
  { "Управл Опред функций", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_OF, typeMenuList},//control_item, parent
/*
  { "Тип ОФ1",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ2",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ3",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ4",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ5",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ6",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ7",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ8",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ9",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ10",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ11",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ12",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ13",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ14",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ15",  (void *)&UprCompOF, typeMenuProg},
  { "Тип ОФ16",  (void *)&UprCompOF, typeMenuProg},
*/
  { NULL, NULL}

};

void PereinitUstListCompOF(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ust_compOF, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UstListCompOF()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compOF);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompOF);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompOF()

void UstCompOF()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compOF);
  PassWord(EditUstOF);
}//VidCompOF()

void EditUstOF()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compOF);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompOF()

short  KadrMenuFormat_ust_compOF(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  char locTxt[50];
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    if(sub_menu_ust_compOF[i+1+SUBDATA].Line1==NULL)break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, (char *)sub_menu_ust_compOF[i+1+SUBDATA].Line1);
      sprintf(locTxt, "   %d", getUstOffsetMngUSTAVKI(i));
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_ust_compOF(void *pstr)

//--------------------------------------------------

void PereinitUprListCompOF(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compOF, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompOF()
{
  SelectorMNGBAZA(MNGUPR_OF);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compOF);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompOF);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompOF()

void UprCompOF()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compOF);
  PassWord(EditUprOF);

}//UprCompOF()

void EditUprOF()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compOF[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrOF);//редактировать уставку управления
}//EditUprOF()

short  KadrMenuFormat_upr_compOF(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compOF[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrOF(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compOF(WorkControl *workCntr)

char *selectorUprStrOF(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_OBRAT];
    return bitStringUNI[UNIUPR_PRJAM];
}//selectorUprStrOF(short ibit, UNS_32 ustUpr)

int initUstOF(char init)
{
  //инициал уставок
  if (init)
  {
//OF1
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF1] = 41;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF1] = 45;
//OF2
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF2] = 42;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF2] = 46;
//OF3
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF3] = 43;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF3] = 47;
//OF4
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF4] = 44;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF4] = 48;
//OF5
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF5] = 45;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF5] = 49;
//OF6
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF6] = 46;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF6] = 50;
//OF7
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF7] = 47;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF7] = 51;
//OF8
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF8] = 48;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF8] = 52;
//OF9
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF9] = 49;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF9] = 53;
//OF10
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF10] = 50;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF10] = 54;
//OF11
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF11] = 51;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF11] = 55;
//OF12
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF12] = 52;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF12] = 56;
//OF13
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF13] = 53;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF13] = 57;
//OF14
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF14] = 54;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF14] = 58;
//OF15
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF15] = 55;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF15] = 59;
//OF16
    //таймер паузы
    tmpUSTAVKI[MNGPAUSA_OF16] = 56;
    //таймер работы
    tmpUSTAVKI[MNGWORK_OF16] = 60;

//уставка управления
    tmpUSTAVKI[MNGUPR_OF] = 0;
  }//if

  IndexUstSPV += SPVUST_OF_TOTAL;//индекс уставок в супервизоре
  return MNGUST_OF_TOTAL;//к-во уставок в менеджере уставок
}//initUstOF(short mngUst, char init)

void  prepareUstOF(short idxC)
{
  //подготовка ENA команд для клона
  if(idxC>=0){
  //копировать ENA из WideENA в ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_OF), ENACMD_OF_TOTAL);
  //подготовка уставок
  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //компонент в конфигурации

//OF1
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF1,
          codecUstOF(1, MNGPAUSA_OF1, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF1)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF1,
          codecUstOF(1, MNGWORK_OF1, getNativUstMngUSTAVKI(idxC, MNGWORK_OF1)));
//OF2
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF2,
          codecUstOF(1, MNGPAUSA_OF2, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF2)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF2,
          codecUstOF(1, MNGWORK_OF2, getNativUstMngUSTAVKI(idxC, MNGWORK_OF2)));
//OF3
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF3,
          codecUstOF(1, MNGPAUSA_OF3, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF3)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF3,
          codecUstOF(1, MNGWORK_OF3, getNativUstMngUSTAVKI(idxC, MNGWORK_OF3)));
//OF4
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF4,
          codecUstOF(1, MNGPAUSA_OF4, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF4)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF4,
          codecUstOF(1, MNGWORK_OF4, getNativUstMngUSTAVKI(idxC, MNGWORK_OF4)));
//OF5
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF5,
          codecUstOF(1, MNGPAUSA_OF5, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF5)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF5,
          codecUstOF(1, MNGWORK_OF5, getNativUstMngUSTAVKI(idxC, MNGWORK_OF5)));
//OF6
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF6,
          codecUstOF(1, MNGPAUSA_OF6, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF6)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF6,
          codecUstOF(1, MNGWORK_OF6, getNativUstMngUSTAVKI(idxC, MNGWORK_OF6)));
//OF7
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF7,
          codecUstOF(1, MNGPAUSA_OF7, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF7)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF7,
          codecUstOF(1, MNGWORK_OF7, getNativUstMngUSTAVKI(idxC, MNGWORK_OF7)));
//OF8
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF8,
          codecUstOF(1, MNGPAUSA_OF8, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF8)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF8,
          codecUstOF(1, MNGWORK_OF8, getNativUstMngUSTAVKI(idxC, MNGWORK_OF8)));
//OF9
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF9,
          codecUstOF(1, MNGPAUSA_OF9, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF9)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF9,
          codecUstOF(1, MNGWORK_OF9, getNativUstMngUSTAVKI(idxC, MNGWORK_OF9)));
//OF10
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF10,
          codecUstOF(1, MNGPAUSA_OF10, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF10)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF10,
          codecUstOF(1, MNGWORK_OF10, getNativUstMngUSTAVKI(idxC, MNGWORK_OF10)));
//OF11
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF11,
          codecUstOF(1, MNGPAUSA_OF11, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF11)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF11,
          codecUstOF(1, MNGWORK_OF11, getNativUstMngUSTAVKI(idxC, MNGWORK_OF11)));
//OF12
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF12,
          codecUstOF(1, MNGPAUSA_OF12, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF12)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF12,
          codecUstOF(1, MNGWORK_OF12, getNativUstMngUSTAVKI(idxC, MNGWORK_OF12)));
//OF13
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF13,
          codecUstOF(1, MNGPAUSA_OF13, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF13)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF13,
          codecUstOF(1, MNGWORK_OF13, getNativUstMngUSTAVKI(idxC, MNGWORK_OF13)));
//OF14
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF14,
          codecUstOF(1, MNGPAUSA_OF14, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF14)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF14,
          codecUstOF(1, MNGWORK_OF14, getNativUstMngUSTAVKI(idxC, MNGWORK_OF14)));
//OF15
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF15,
          codecUstOF(1, MNGPAUSA_OF15, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF15)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF15,
          codecUstOF(1, MNGWORK_OF15, getNativUstMngUSTAVKI(idxC, MNGWORK_OF15)));
//OF16
    //таймер паузы
   setTimerPorog(tmpOffsetT+ TIMERP_OF16,
          codecUstOF(1, MNGPAUSA_OF16, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF16)));
    //таймер работы
   setTimerPorog(tmpOffsetT+ TIMERR_OF16,
          codecUstOF(1, MNGWORK_OF16, getNativUstMngUSTAVKI(idxC, MNGWORK_OF16)));
  }//if
  else{
  //подготовка ENA команд для клона РЛ
  //копировать ENA из WideENA в ENAcmd
  CopyWideENAToENAcmd_WL(PrepareENACmd(idxC, MNGUPR_OF), ENACMD_OF_TOTAL);
  //подготовка уставок
  short tmpOffsetT    =
    getOffsetTimersCnf_WL(idxC);   //компонент в конфигурации

//OF1
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF1,
          codecUstOF(1, MNGPAUSA_OF1, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF1)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF1,
          codecUstOF(1, MNGWORK_OF1, getNativUstMngUSTAVKI(idxC, MNGWORK_OF1)));
//OF2
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF2,
          codecUstOF(1, MNGPAUSA_OF2, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF2)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF2,
          codecUstOF(1, MNGWORK_OF2, getNativUstMngUSTAVKI(idxC, MNGWORK_OF2)));
//OF3
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF3,
          codecUstOF(1, MNGPAUSA_OF3, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF3)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF3,
          codecUstOF(1, MNGWORK_OF3, getNativUstMngUSTAVKI(idxC, MNGWORK_OF3)));
//OF4
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF4,
          codecUstOF(1, MNGPAUSA_OF4, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF4)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF4,
          codecUstOF(1, MNGWORK_OF4, getNativUstMngUSTAVKI(idxC, MNGWORK_OF4)));
//OF5
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF5,
          codecUstOF(1, MNGPAUSA_OF5, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF5)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF5,
          codecUstOF(1, MNGWORK_OF5, getNativUstMngUSTAVKI(idxC, MNGWORK_OF5)));
//OF6
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF6,
          codecUstOF(1, MNGPAUSA_OF6, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF6)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF6,
          codecUstOF(1, MNGWORK_OF6, getNativUstMngUSTAVKI(idxC, MNGWORK_OF6)));
//OF7
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF7,
          codecUstOF(1, MNGPAUSA_OF7, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF7)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF7,
          codecUstOF(1, MNGWORK_OF7, getNativUstMngUSTAVKI(idxC, MNGWORK_OF7)));
//OF8
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF8,
          codecUstOF(1, MNGPAUSA_OF8, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF8)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF8,
          codecUstOF(1, MNGWORK_OF8, getNativUstMngUSTAVKI(idxC, MNGWORK_OF8)));
//OF9
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF9,
          codecUstOF(1, MNGPAUSA_OF9, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF9)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF9,
          codecUstOF(1, MNGWORK_OF9, getNativUstMngUSTAVKI(idxC, MNGWORK_OF9)));
//OF10
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF10,
          codecUstOF(1, MNGPAUSA_OF10, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF10)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF10,
          codecUstOF(1, MNGWORK_OF10, getNativUstMngUSTAVKI(idxC, MNGWORK_OF10)));
//OF11
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF11,
          codecUstOF(1, MNGPAUSA_OF11, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF11)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF11,
          codecUstOF(1, MNGWORK_OF11, getNativUstMngUSTAVKI(idxC, MNGWORK_OF11)));
//OF12
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF12,
          codecUstOF(1, MNGPAUSA_OF12, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF12)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF12,
          codecUstOF(1, MNGWORK_OF12, getNativUstMngUSTAVKI(idxC, MNGWORK_OF12)));
//OF13
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF13,
          codecUstOF(1, MNGPAUSA_OF13, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF13)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF13,
          codecUstOF(1, MNGWORK_OF13, getNativUstMngUSTAVKI(idxC, MNGWORK_OF13)));
//OF14
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF14,
          codecUstOF(1, MNGPAUSA_OF14, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF14)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF14,
          codecUstOF(1, MNGWORK_OF14, getNativUstMngUSTAVKI(idxC, MNGWORK_OF14)));
//OF15
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF15,
          codecUstOF(1, MNGPAUSA_OF15, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF15)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF15,
          codecUstOF(1, MNGWORK_OF15, getNativUstMngUSTAVKI(idxC, MNGWORK_OF15)));
//OF16
    //таймер паузы
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF16,
          codecUstOF(1, MNGPAUSA_OF16, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF16)));
    //таймер работы
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF16,
          codecUstOF(1, MNGWORK_OF16, getNativUstMngUSTAVKI(idxC, MNGWORK_OF16)));
   }//else WL
}//prepareUstMTZ2(short idxC)

int initIOCmd_OF()
{
  //инициал IO команд
  offsetIOCmdOF_loc = IndexIO;//смещение для IO OF
  return commonInitIOCmd(IOCMD_OF_TOTAL);
}

int initTLCmd_OF()
{
  //инициал TL команд
  return commonInitTLCmd(TLCMD_OF_TOTAL);
}//initTLCmd_OF()

int initENACmd_OF()
{
  //инициал ENA команд
  return commonInitENACmd(ENACMD_OF_TOTAL);
}//initENACmd_OF()

void initTimersOF(short idxC)
{
  //запрос и инициал таймеров
  if(idxC>=0)
   commonInitTimers(TIMERS_OF_TOTAL);
  else {
   commonInitTimers_WL(TIMERS_OF_TOTAL);
   timerEnableWL = 1;//разрешение работы таймеров РЛ
       }
}//initTimersOF()

int codecUstOF(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  if(codec) return ust*1;
  return ust/1;
}//codecUstOF(char *buf, short offset, int ust)

int isDISactiv_OF(int idxC)
{
 //активность Регистратора ДИС
  return 0;//нет активности
}//isDISactiv_OF(int idxC)

char copyOFToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое
//копировать компонент в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.packet = 0;    //номер пакетного компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  "ОФ");       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_OF;//меню компонента

  rpzcomponent_obj.cntClon    = 5;   //max к-во клонов

  rpzcomponent_obj.initUstMng    = initUstOF;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv = prepareUstOF;//подготовка уставок
  rpzcomponent_obj.initIOCmd     = initIOCmd_OF;      //инициал IO команд
  rpzcomponent_obj.initTLCmd     = initTLCmd_OF;      //инициал TL команд
  rpzcomponent_obj.initENACmd    = initENACmd_OF;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_OF; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsOF;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersOF;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicOF;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstOF;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

