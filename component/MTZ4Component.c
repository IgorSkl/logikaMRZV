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
#include "psuperVisor\psvisor_helpdef.h"

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\rangmanagerfnc.h"

#include "virtualMenu\viewMenuList.h"

#include "..\bazis.h"

//код компонентов
#define KOD_COMPONENT  MTZ_COMP1
//к-во ступеней
#define CNT_STUPEN_MTZ  5

#endif // _HIDE_COMPONENT

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "MTZ2Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_MTZ[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора

void PereinitUstListCompMTZ4(short flg);
void UstListCompMTZ4();
void ustRedactorCompMTZ4();
void UstCompMTZ4();
short  KadrMenuFormat_ust_compMTZ4(void *workCntr);

void PereinitVidListCompMTZ4(short flg);
void VidListCompMTZ4();
void vidRedactorCompMTZ4();
void VidCompMTZ4();
short  KadrMenuFormat_vid_compMTZ4(void *workCntr);

void PereinitUprListCompMTZ4(short flg);
void UprListCompMTZ4();
void uprRedactorCompMTZ4();
void UprCompMTZ4();
short  KadrMenuFormat_upr_compMTZ4(void *workCntr);
int  initUstMTZ4(char init);
void  prepareUstMTZ2(short idxC);
void  prepareUstMTZ4(short idxC);

//int ViewerEditUstMTZ4();
//int ViewerEditVidMTZ4();
void EditUstMTZ4();
void EditVidMTZ4();
void EditUprMTZ4();
int codecUstMTZ4(char codec, short offset, int ust);
int codecUstMTZ2(char codec, short offset, int ust);
int initUstMTZ2(char init);

char *selectorUprStrMTZ2(short iBit, UNS_32 ustUpr);
void UpravlChooserMTZInKadr(char *nameUpr, short ibit, void *workCntr);
void UpravlRedactorChooseMTZ(char *nameUpr, short ibit);
short  KadrMenuFormat_ustvidMTZ(void *workCntr);

char MTZ4_TITLE[] = "МТЗ4";

IONAMESTATUS_COMPONENT ionsMTZ4[IOCMD_MTZ2to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок МТЗ4"
  },
  {
    1,//статус iocmd2
    "Блок уск МТЗ4"
  },
  {
    1,//статус iocmd3
    "Операт уск МТЗ4"
  },
  {
    1,//статус iocmd4
    "Сраб ПО МТЗ4"
  },
  {                 
    1,//статус iocmd5
    "Сраб ПО МТЗ4 ВПД"
  },
  {
    1,//статус iocmd6
    "Сраб ПО МТЗ4 НЗД"
  },
  {
    1,//статус iocmd7
    "Сраб ПО МТЗ4 ПН"
  },
  {
    1,//статус iocmd8
    "Сраб МТЗ4"
  },
  {
    1,//статус iocmd9
    "Теле уск МТЗ4"
  },
  {
    1,//статус iocmd10
    "Сектор МТЗ4 ВПД"
  },
  {
    1,//статус iocmd11
    "Сектор МТЗ4 НЗД"
  }
};

LineMenuItem sub_menu_comp_MTZ4[8] =
{
  { MTZ4_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_MTZ, typeMenuSub},//control_item, parent
  { "Уставки МТЗ4",    (void *)&UstListCompMTZ4, typeMenuProg},
  { "Выдержки МТЗ4",   (void *)&VidListCompMTZ4, typeMenuProg},
  { "Управление МТЗ4", (void *)&UprListCompMTZ4, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compMTZ4[] =
{
  { "Уставки МТЗ4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ4, typeMenuList},//control_item, parent
  { "Уст МТЗ4",         (void*)&UstCompMTZ4, typeMenuProg},
  { "Уст МТЗ4 вперед",  (void*)&UstCompMTZ4, typeMenuProg},
  { "Уст МТЗ4 назад",   (void*)&UstCompMTZ4, typeMenuProg},
  { "Уст МТЗ4 ПМ",      (void*)&UstCompMTZ4, typeMenuProg},
  { "Уст напр МТЗ4 ПH", (void*)&UstCompMTZ4, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compMTZ4[] =
{
  { "Выдержки МТЗ4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ4, typeMenuList},//control_item, parent
/*
  { "Выдержка МТЗ4",         (void*)&VidCompMTZ4, typeMenuProg},
  { "Выдержка МТЗ4 вперед",  (void*)&VidCompMTZ4, typeMenuProg},
  { "Выдержка МТЗ4 назад",   (void*)&VidCompMTZ4, typeMenuProg},
  { "Выдержка МТЗ4 ПМ",      (void*)&VidCompMTZ4, typeMenuProg},
  { "Ввод ускор МТЗ4",       (void*)&VidCompMTZ4, typeMenuProg},

  { "Ускор МТЗ4 ВВ",         (void*)&VidCompMTZ4, typeMenuProg},
  { "Ускор МТЗ4 ОУ",         (void*)&VidCompMTZ4, typeMenuProg},
  { "Ускор МТЗ4 ТУ",         (void*)&VidCompMTZ4, typeMenuProg},

  { "Ускор МТЗ4 ВВ ВПД",     (void*)&VidCompMTZ4, typeMenuProg},
  { "Ускор МТЗ4 ОУ ВПД",     (void*)&VidCompMTZ4, typeMenuProg},
  { "Ускор МТЗ4 ТУ ВПД",     (void*)&VidCompMTZ4, typeMenuProg},

  { "Ускор МТЗ4 ВВ НЗД",     (void*)&VidCompMTZ4, typeMenuProg},
  { "Ускор МТЗ4 ОУ НЗД",     (void*)&VidCompMTZ4, typeMenuProg},
  { "Ускор МТЗ4 ТУ НЗД",     (void*)&VidCompMTZ4, typeMenuProg},

  { "Ускор МТЗ4 ВВ ПН",      (void*)&VidCompMTZ4, typeMenuProg},
  { "Ускор МТЗ4 ОУ ПН",      (void*)&VidCompMTZ4, typeMenuProg},
  { "Ускор МТЗ4 ТУ НП",      (void*)&VidCompMTZ4, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compMTZ4[] =
{
  { "Управл МТЗ4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ4, typeMenuList},//control_item, parent
  { "Вид МТЗ4",           (void*)&UprCompMTZ4, typeMenuProg},
  { "Управл МТЗ4",        (void*)&UprCompMTZ4, typeMenuProg},
  { "МТЗ4 вперед",        (void*)&UprCompMTZ4, typeMenuProg},
  { "МТЗ4 назад",         (void*)&UprCompMTZ4, typeMenuProg},
  { "Ускорение МТЗ4",     (void*)&UprCompMTZ4, typeMenuProg},
  { "МТЗ4 ускоренная",    (void*)&UprCompMTZ4, typeMenuProg},
  { "Автомат уск МТЗ4",   (void*)&UprCompMTZ4, typeMenuProg},
  { "Телеускор МТЗ4",     (void*)&UprCompMTZ4, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompMTZ4(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_ust_compMTZ4);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp3()

void UstListCompMTZ4()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compMTZ4);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompMTZ4);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompMTZ4()

void UstCompMTZ4()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compMTZ4);
  PassWord(EditUstMTZ4);
}//VidCompMTZ4()

void EditUstMTZ4()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compMTZ4);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompMTZ4()

//--------------------------------------------------

void PereinitVidListCompMTZ4(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_vid_compMTZ4);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitVidListCompMTZ4(short flg)

void VidListCompMTZ4()
{
  SelectorMNGBAZA(MNGVID_MTZ2to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compMTZ4);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompMTZ4);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ4()

void VidCompMTZ4()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compMTZ4);
//  PassWord(EditVidAPV);
  EditVidMTZ4();
}//VidCompMTZ4()

void EditVidMTZ4()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compMTZ4);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompMTZ4(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compMTZ4, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompMTZ4()
{
  SelectorMNGBAZA(MNGUPR_MTZ2to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compMTZ4);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompMTZ4);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ4()

void UprCompMTZ4()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compMTZ4);
  PassWord(EditUprMTZ4);
}//VidCompMTZ4()

void EditUprMTZ4()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compMTZ4[LIGHTLINEMENU +1+SUBDATA].Line1;

  switch(LIGHTLINEMENU)
  {
    case 0: UpravlRedactorChooseMTZ(nameUpr, LIGHTLINEMENU);//редактировать уставку управления
    break;
    default:UpravlRedactor(nameUpr, LIGHTLINEMENU+1, &selectorUprStrMTZ2);//редактировать уставку управления
  }//switch

}//EditVidMTZ4()

short  KadrMenuFormat_upr_compMTZ4(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  short chooseBit = 2;//к-во бит в choose
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compMTZ4[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      if(i<(chooseBit-1))
        UpravlChooserMTZInKadr(nameUpr, i, workCntr);
      else
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
        selectorUprStrMTZ2(i+(chooseBit-1), getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compMTZ4(WorkControl *workCntr)

int initUstMTZ4(char init)
{
 return initUstMTZ2(init);
}//initUstMTZ1(short mngUst, char init)

void  prepareUstMTZ4(short idxC)
{
   prepareUstMTZ2(idxC);
}//prepareUstMTZ4(short idxC)

int codecUstMTZ4(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  return codecUstMTZ2(codec, offset, ust);
}//codecUstMTZ4(char *buf, short offset, int ust)

void diffMTZ4ToRepozitar()
{
//копировать изменения компонента в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  MTZ4_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_MTZ4;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_MTZ;   //к-во клонов
  rpzcomponent_obj.numClon     = 4;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstMTZ4;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstMTZ4;//подготовка уставок

  rpzcomponent_obj.nameStatusIO = ionsMTZ4;          //имена и статус команд IO
}//diffMTZ4ToRepozitar()

#endif // _HIDE_COMPONENT

