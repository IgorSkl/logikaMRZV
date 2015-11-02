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

void PereinitUstListCompMTZ3(short flg);
void UstListCompMTZ3();
void ustRedactorCompMTZ3();
void UstCompMTZ3();
short  KadrMenuFormat_ust_compMTZ3(void *workCntr);//(WorkControl *workCntr);

void PereinitVidListCompMTZ3(short flg);
void VidListCompMTZ3();
void vidRedactorCompMTZ3();
void VidCompMTZ3();
short  KadrMenuFormat_vid_compMTZ3(void *workCntr);//(WorkControl *workCntr);

void PereinitUprListCompMTZ3(short flg);
void UprListCompMTZ3();
void uprRedactorCompMTZ3();
void UprCompMTZ3();
short  KadrMenuFormat_upr_compMTZ3(void *workCntr);//(WorkControl *workCntr);
int   initUstMTZ3(char init);
void  prepareUstMTZ2(short idxC);
void  prepareUstMTZ3(short idxC);

//int ViewerEditUstMTZ3();
//int ViewerEditVidMTZ3();
void EditUstMTZ3();
void EditVidMTZ3();
void EditUprMTZ3();
int codecUstMTZ3(char codec, short offset, int ust);
int codecUstMTZ2(char codec, short offset, int ust);
int initUstMTZ2(char init);

char *selectorUprStrMTZ2(short iBit, UNS_32 ustUpr);
void UpravlChooserMTZInKadr(char *nameUpr, short ibit, void *workCntr);
void UpravlRedactorChooseMTZ(char *nameUpr, short ibit);
short  KadrMenuFormat_ustvidMTZ(void *workCntr);
void diffMTZ3ToRepozitar();

char MTZ3_TITLE[] = "МТЗ3";

IONAMESTATUS_COMPONENT ionsMTZ3[IOCMD_MTZ2to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок МТЗ3"
  },
  {
    1,//статус iocmd2
    "Блок уск МТЗ3"
  },
  {
    1,//статус iocmd3
    "Операт уск МТЗ3"
  },
  {
    1,//статус iocmd4
    "Сраб ПО МТЗ3"
  },
  {
    1,//статус iocmd5
    "Сраб ПО МТЗ3 ВПД"
  },
  {
    1,//статус iocmd6
    "Сраб ПО МТЗ3 НЗД"
  },
  {
    1,//статус iocmd7
    "Сраб ПО МТЗ3 ПН"
  },
  {
    1,//статус iocmd8
    "Сраб МТЗ3"
  },
  {
    1,//статус iocmd9
    "Теле уск МТЗ3"
  },
  {
    1,//статус iocmd10
    "Сектор МТЗ3 ВПД"
  },
  {
    1,//статус iocmd11
    "Сектор МТЗ3 НЗД"
  }
};

LineMenuItem sub_menu_comp_MTZ3[8] =
{
  { MTZ3_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_MTZ, typeMenuSub},//control_item, parent
  { "Уставки МТЗ3",    (void *)&UstListCompMTZ3, typeMenuProg},
  { "Выдержки МТЗ3",   (void *)&VidListCompMTZ3, typeMenuProg},
  { "Управление МТЗ3", (void *)&UprListCompMTZ3, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compMTZ3[] =
{
  { "Уставки МТЗ3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ3, typeMenuList},//control_item, parent
  { "Уст МТЗ3",         (void*)&UstCompMTZ3, typeMenuProg},
  { "Уст МТЗ3 вперед",  (void*)&UstCompMTZ3, typeMenuProg},
  { "Уст МТЗ3 назад",   (void*)&UstCompMTZ3, typeMenuProg},
  { "Уст МТЗ3 ПМ",      (void*)&UstCompMTZ3, typeMenuProg},
  { "Уст напр МТЗ3 ПH", (void*)&UstCompMTZ3, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compMTZ3[] =
{
  { "Выдержки МТЗ3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ3, typeMenuList},//control_item, parent
/*
  { "Выдержка МТЗ3",         (void*)&VidCompMTZ3, typeMenuProg},
  { "Выдержка МТЗ3 вперед",  (void*)&VidCompMTZ3, typeMenuProg},
  { "Выдержка МТЗ3 назад",   (void*)&VidCompMTZ3, typeMenuProg},
  { "Выдержка МТЗ3 ПМ",      (void*)&VidCompMTZ3, typeMenuProg},
  { "Ввод ускор МТЗ3",       (void*)&VidCompMTZ3, typeMenuProg},

  { "Ускор МТЗ3 ВВ",         (void*)&VidCompMTZ3, typeMenuProg},
  { "Ускор МТЗ3 ОУ",         (void*)&VidCompMTZ3, typeMenuProg},
  { "Ускор МТЗ3 ТУ",         (void*)&VidCompMTZ3, typeMenuProg},

  { "Ускор МТЗ3 ВВ ВПД",     (void*)&VidCompMTZ3, typeMenuProg},
  { "Ускор МТЗ3 ОУ ВПД",     (void*)&VidCompMTZ3, typeMenuProg},
  { "Ускор МТЗ3 ТУ ВПД",     (void*)&VidCompMTZ3, typeMenuProg},

  { "Ускор МТЗ3 ВВ НЗД",     (void*)&VidCompMTZ3, typeMenuProg},
  { "Ускор МТЗ3 ОУ НЗД",     (void*)&VidCompMTZ3, typeMenuProg},
  { "Ускор МТЗ3 ТУ НЗД",     (void*)&VidCompMTZ3, typeMenuProg},

  { "Ускор МТЗ3 ВВ ПН",      (void*)&VidCompMTZ3, typeMenuProg},
  { "Ускор МТЗ3 ОУ ПН",      (void*)&VidCompMTZ3, typeMenuProg},
  { "Ускор МТЗ3 ТУ ПН",      (void*)&VidCompMTZ3, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compMTZ3[] =
{
  { "Управл МТЗ3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ3, typeMenuList},//control_item, parent
  { "Вид МТЗ3",           (void*)&UprCompMTZ3, typeMenuProg},
  { "Управл МТЗ3",        (void*)&UprCompMTZ3, typeMenuProg},
  { "МТЗ3 вперед",        (void*)&UprCompMTZ3, typeMenuProg},
  { "МТЗ3 назад",         (void*)&UprCompMTZ3, typeMenuProg},
  { "Ускорение МТЗ3",     (void*)&UprCompMTZ3, typeMenuProg},
  { "МТЗ3 ускоренная",    (void*)&UprCompMTZ3, typeMenuProg},
  { "Автомат уск МТЗ3",   (void*)&UprCompMTZ3, typeMenuProg},
  { "Телеускор МТЗ3",     (void*)&UprCompMTZ3, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompMTZ3(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_ust_compMTZ3);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp3()

void UstListCompMTZ3()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compMTZ3);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompMTZ3);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompMTZ3()

void UstCompMTZ3()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compMTZ3);
  PassWord(EditUstMTZ3);
}//VidCompMTZ3()

void EditUstMTZ3()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compMTZ3);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompMTZ3()

//--------------------------------------------------

void PereinitVidListCompMTZ3(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_vid_compMTZ3);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitVidListCompMTZ3(short flg)

void VidListCompMTZ3()
{
  SelectorMNGBAZA(MNGVID_MTZ2to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compMTZ3);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompMTZ3);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ3()

void VidCompMTZ3()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compMTZ3);
//  PassWord(EditVidAPV);
  EditVidMTZ3();
}//VidCompMTZ3()

void EditVidMTZ3()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compMTZ3);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompMTZ3(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compMTZ3, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompMTZ3()
{
  SelectorMNGBAZA(MNGUPR_MTZ2to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compMTZ3);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompMTZ3);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ3()

void UprCompMTZ3()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compMTZ3);
  PassWord(EditUprMTZ3);
}//VidCompMTZ3()

void EditUprMTZ3()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compMTZ3[LIGHTLINEMENU +1+SUBDATA].Line1;

  switch(LIGHTLINEMENU)
  {
    case 0: UpravlRedactorChooseMTZ(nameUpr, LIGHTLINEMENU);//редактировать уставку управления
    break;
    default:UpravlRedactor(nameUpr, LIGHTLINEMENU+1, &selectorUprStrMTZ2);//редактировать уставку управления
  }//switch

}//EditVidMTZ3()

short  KadrMenuFormat_upr_compMTZ3(void *pstr)//(WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  short chooseBit = 2;//к-во бит в choose
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compMTZ3[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      if(i<(chooseBit-1))
        UpravlChooserMTZInKadr(nameUpr, i, workCntr);
      else
        //      UpravlViewerInKadr(nameUpr, i+(chooseBit-1), workCntr);//отобразить уставку управления в кадре
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
        selectorUprStrMTZ2(i+(chooseBit-1), getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compMTZ3(WorkControl *workCntr)

int initUstMTZ3(char init)
{
 return initUstMTZ2(init);
}//initUstMTZ1(short mngUst, char init)

void  prepareUstMTZ3(short idxC)
{
  prepareUstMTZ2(idxC);
}//prepareUstMTZ3(short idxC)

int codecUstMTZ3(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  return codecUstMTZ2(codec, offset, ust);
}//codecUstMTZ3(char *buf, short offset, int ust)

void diffMTZ3ToRepozitar()
{
//копировать изменения компонента в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  MTZ3_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_MTZ3;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_MTZ;   //к-во клонов
  rpzcomponent_obj.numClon     = 3;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstMTZ3;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstMTZ3;//подготовка уставок

  rpzcomponent_obj.nameStatusIO = ionsMTZ3;          //имена и статус команд IO

  rpzcomponent_obj.codecUst = codecUstMTZ3;   //кодировать-раскодировать уставку

}//

#endif // _HIDE_COMPONENT

