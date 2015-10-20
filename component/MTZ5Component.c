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

void PereinitUstListCompMTZ5(short flg);
void UstListCompMTZ5();
void ustRedactorCompMTZ5();
void UstCompMTZ5();
short  KadrMenuFormat_ust_compMTZ5(void *workCntr);

void PereinitVidListCompMTZ5(short flg);
void VidListCompMTZ5();
void vidRedactorCompMTZ5();
void VidCompMTZ5();
short  KadrMenuFormat_vid_compMTZ5(void *workCntr);

void PereinitUprListCompMTZ5(short flg);
void UprListCompMTZ5();
void uprRedactorCompMTZ5();
void UprCompMTZ5();
short  KadrMenuFormat_upr_compMTZ5(void *workCntr);
int  initUstMTZ5(char init);
void  prepareUstMTZ2(short idxC);
void  prepareUstMTZ5(short idxC);

//int ViewerEditUstMTZ5();
//int ViewerEditVidMTZ5();
void EditUstMTZ5();
void EditVidMTZ5();
void EditUprMTZ5();
int codecUstMTZ5(char codec, short offset, int ust);
int codecUstMTZ2(char codec, short offset, int ust);
int initUstMTZ2(char init);

char *selectorUprStrMTZ2(short iBit, UNS_32 ustUpr);
void UpravlChooserMTZInKadr(char *nameUpr, short ibit, void *workCntr);
void UpravlRedactorChooseMTZ(char *nameUpr, short ibit);
short  KadrMenuFormat_ustvidMTZ(void *workCntr);

char MTZ5_TITLE[] = "МТЗ5";

IONAMESTATUS_COMPONENT ionsMTZ5[IOCMD_MTZ2to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок МТЗ5"
  },
  {
    1,//статус iocmd2
    "Блок уск МТЗ5"
  },
  {
    1,//статус iocmd3
    "Операт уск МТЗ5"
  },
  {
    1,//статус iocmd4
    "Сраб ПО МТЗ5"
  },
  {
    1,//статус iocmd5
    "Сраб ПО МТЗ5 ВПД"
  },
  {
    1,//статус iocmd6
    "Сраб ПО МТЗ5 НЗД"
  },
  {
    1,//статус iocmd7
    "Сраб ПО МТЗ5 ПН"
  },
  {
    1,//статус iocmd8
    "Сраб МТЗ5"
  },
  {
    1,//статус iocmd9
    "Теле уск МТЗ5"
  },
  {
    1,//статус iocmd10
    "Сектор МТЗ5 ВПД"
  },
  {
    1,//статус iocmd11
    "Сектор МТЗ5 НЗД"
  }
};

LineMenuItem sub_menu_comp_MTZ5[8] =
{
  { MTZ5_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_MTZ, typeMenuSub},//control_item, parent
  { "Уставки МТЗ5",    (void *)&UstListCompMTZ5, typeMenuProg},
  { "Выдержки МТЗ5",   (void *)&VidListCompMTZ5, typeMenuProg},
  { "Управление МТЗ5", (void *)&UprListCompMTZ5, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compMTZ5[] =
{
  { "Уставки МТЗ5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ5, typeMenuList},//control_item, parent
  { "Уст МТЗ5",         (void*)&UstCompMTZ5, typeMenuProg},
  { "Уст МТЗ5 вперед",  (void*)&UstCompMTZ5, typeMenuProg},
  { "Уст МТЗ5 назад",   (void*)&UstCompMTZ5, typeMenuProg},
  { "Уст МТЗ5 ПМ",      (void*)&UstCompMTZ5, typeMenuProg},
  { "Уст напр МТЗ5 ПH", (void*)&UstCompMTZ5, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compMTZ5[] =
{
  { "Выдержки МТЗ5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ5, typeMenuList},//control_item, parent
/*
  { "Выдержка МТЗ5",         (void*)&VidCompMTZ5, typeMenuProg},
  { "Выдержка МТЗ5 вперед",  (void*)&VidCompMTZ5, typeMenuProg},
  { "Выдержка МТЗ5 назад",   (void*)&VidCompMTZ5, typeMenuProg},
  { "Выдержка МТЗ5 ПМ",      (void*)&VidCompMTZ5, typeMenuProg},
  { "Ввод ускор МТЗ5",       (void*)&VidCompMTZ5, typeMenuProg},

  { "Ускор МТЗ5 ВВ",         (void*)&VidCompMTZ5, typeMenuProg},
  { "Ускор МТЗ5 ОУ",         (void*)&VidCompMTZ5, typeMenuProg},
  { "Ускор МТЗ5 ТУ",         (void*)&VidCompMTZ5, typeMenuProg},

  { "Ускор МТЗ5 ВВ ВПД",     (void*)&VidCompMTZ5, typeMenuProg},
  { "Ускор МТЗ5 ОУ ВПД",     (void*)&VidCompMTZ5, typeMenuProg},
  { "Ускор МТЗ5 ТУ ВПД",     (void*)&VidCompMTZ5, typeMenuProg},

  { "Ускор МТЗ5 ВВ НЗД",     (void*)&VidCompMTZ5, typeMenuProg},
  { "Ускор МТЗ5 ОУ НЗД",     (void*)&VidCompMTZ5, typeMenuProg},
  { "Ускор МТЗ5 ТУ НЗД",     (void*)&VidCompMTZ5, typeMenuProg},

  { "Ускор МТЗ5 ВВ ПН",      (void*)&VidCompMTZ5, typeMenuProg},
  { "Ускор МТЗ5 ОУ ПН",      (void*)&VidCompMTZ5, typeMenuProg},
  { "Ускор МТЗ5 ТУ НП",      (void*)&VidCompMTZ5, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compMTZ5[] =
{
  { "Управл МТЗ5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ5, typeMenuList},//control_item, parent
  { "Вид МТЗ5",           (void*)&UprCompMTZ5, typeMenuProg},
  { "Управл МТЗ5",        (void*)&UprCompMTZ5, typeMenuProg},
  { "МТЗ5 вперед",        (void*)&UprCompMTZ5, typeMenuProg},
  { "МТЗ5 назад",         (void*)&UprCompMTZ5, typeMenuProg},
  { "Ускорение МТЗ5",     (void*)&UprCompMTZ5, typeMenuProg},
  { "МТЗ5 ускоренная",    (void*)&UprCompMTZ5, typeMenuProg},
  { "Автомат уск МТЗ5",   (void*)&UprCompMTZ5, typeMenuProg},
  { "Телеускор МТЗ5",     (void*)&UprCompMTZ5, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompMTZ5(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_ust_compMTZ5);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp3()

void UstListCompMTZ5()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compMTZ5);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompMTZ5);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompMTZ5()

void UstCompMTZ5()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compMTZ5);
  PassWord(EditUstMTZ5);
}//VidCompMTZ5()

void EditUstMTZ5()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compMTZ5);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompMTZ5()

//--------------------------------------------------

void PereinitVidListCompMTZ5(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_vid_compMTZ5);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitVidListCompMTZ5(short flg)

void VidListCompMTZ5()
{
  SelectorMNGBAZA(MNGVID_MTZ2to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compMTZ5);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompMTZ5);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ5()

void VidCompMTZ5()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compMTZ5);
//  PassWord(EditVidAPV);
  EditVidMTZ5();
}//VidCompMTZ5()

void EditVidMTZ5()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compMTZ5);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompMTZ5(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compMTZ5, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompMTZ5()
{
  SelectorMNGBAZA(MNGUPR_MTZ2to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compMTZ5);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompMTZ5);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ5()

void UprCompMTZ5()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compMTZ5);
  PassWord(EditUprMTZ5);
}//VidCompMTZ5()

void EditUprMTZ5()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compMTZ5[LIGHTLINEMENU +1+SUBDATA].Line1;

  switch(LIGHTLINEMENU)
  {
    case 0: UpravlRedactorChooseMTZ(nameUpr, LIGHTLINEMENU);//редактировать уставку управления
    break;
    default:UpravlRedactor(nameUpr, LIGHTLINEMENU+1, &selectorUprStrMTZ2);//редактировать уставку управления
  }//switch

}//EditVidMTZ5()

short  KadrMenuFormat_upr_compMTZ5(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  short chooseBit = 2;//к-во бит в choose
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compMTZ5[i+1+SUBDATA].Line1;
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
}//KadrMenuFormat_upr_compMTZ5(WorkControl *workCntr)

int initUstMTZ5(char init)
{
 return initUstMTZ2(init);
/*
  //инициал уставок
  if (init)
  {
//уставка сработки
    tmpUSTAVKI[MNGUST_MTZ2to5]     = 331;
    tmpUSTAVKI[MNGUST_MTZ2to5_V]   = 332;
    tmpUSTAVKI[MNGUST_MTZ2to5_N]   = 333;
    tmpUSTAVKI[MNGUST_MTZ2to5_PN]  = 334;
    tmpUSTAVKI[MNGUST_MTZ2to5_UPN] = 335;
//уставка выдержки
    tmpUSTAVKI[MNGVID_MTZ2to5]    = 251;
    tmpUSTAVKI[MNGVID_MTZ2to5_V]  = 262;
    tmpUSTAVKI[MNGVID_MTZ2to5_N]  = 273;
    tmpUSTAVKI[MNGVID_MTZ2to5_PN] = 284;
//ускорение
    tmpUSTAVKI[MNGUSK_MTZ2to5]    = 295;
    tmpUSTAVKI[MNGUSK_MTZ2to5_V]  = 306;
    tmpUSTAVKI[MNGUSK_MTZ2to5_N]  = 317;
    tmpUSTAVKI[MNGUSK_MTZ2to5_PN] = 328;
    tmpUSTAVKI[MNGVUSK_MTZ2to5]   = 339;
//уставка управления
    tmpUSTAVKI[MNGUPR_MTZ2to5] = 0;

  }//if

  IndexUstSPV += SPVUST_MTZ2to5_TOTAL;//индекс уставок в супервизоре
  return MNGUST_MTZ2to5_TOTAL;//к-во уставок в менеджере уставок
*/
}//initUstMTZ1(short mngUst, char init)

void  prepareUstMTZ5(short idxC)
{
   prepareUstMTZ2(idxC);
}//prepareUstMTZ5(short idxC)

int codecUstMTZ5(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  return codecUstMTZ2(codec, offset, ust);
}//codecUstMTZ5(char *buf, short offset, int ust)

void diffMTZ5ToRepozitar()
{
//копировать изменения компонента в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  MTZ5_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_MTZ5;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_MTZ;   //к-во клонов
  rpzcomponent_obj.numClon     = 5;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstMTZ5;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstMTZ5;//подготовка уставок

  rpzcomponent_obj.nameStatusIO = ionsMTZ5;          //имена и статус команд IO

  rpzcomponent_obj.codecUst = codecUstMTZ5;   //кодировать-раскодировать уставку

}//diffMTZ5ToRepozitar()

#endif // _HIDE_COMPONENT

