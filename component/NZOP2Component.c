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
#include "virtualMenu\rangmanagerfnc.h"

#include "virtualMenu\viewMenuList.h"

#include "..\bazis.h"

//код компонентов
#define KOD_COMPONENT  NZOP_COMP1
//к-во ступеней
#define CNT_STUPEN_NZOP  2

#endif // _HIDE_COMPONENT

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "NZOP1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_NZOP[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора

void PereinitUstListCompNZOP2(short flg);
void UstListCompNZOP2();
void ustRedactorCompNZOP2();
void UstCompNZOP2();

void PereinitVidListCompNZOP2(short flg);
void VidListCompNZOP2();
void vidRedactorCompNZOP2();
void VidCompNZOP2();

void PereinitUprListCompNZOP2(short flg);
void UprListCompNZOP2();
void uprRedactorCompNZOP2();
void UprCompNZOP2();
short  KadrMenuFormat_upr_compNZOP2(void *workCntr);//(WorkControl *workCntr);
int  initUstNZOP2(char init);
void  prepareUstNZOP1(short idxC);
void  prepareUstNZOP2(short idxC);

void EditUstNZOP2();
void EditVidNZOP2();
void EditUprNZOP2();
int codecUstNZOP1(char codec, short offset, int ust);
int codecUstNZOP2(char codec, short offset, int ust);
int initUstNZOP1(char init);

short  KadrMenuFormat_ustvidNZOP(void *workCntr);
char *selectorUprStrNZOP1(short iBit, UNS_32 ustUpr);
void diffNZOP2ToRepozitar();

char NZOP2_TITLE[] = "НЗОП2";

IONAMESTATUS_COMPONENT ionsNZOP2[IOCMD_NZOP1to2_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок НЗОП2"
  },
  {
    1,//статус iocmd2
    "Сраб ПО НЗОП2"
  },
  {
    1,//статус iocmd3
    "Сраб ПО НЗОП2 ВПД"
  },
  {
    1,//статус iocmd4
    "Сраб ПО НЗОП2 НЗД"
  },
  {
    1,//статус iocmd5
    "Сраб НЗОП2"
  },
  {
    1,//статус iocmd6
    "Сектор НЗОП2 ВПД"
  },
  {
    1,//статус iocmd7
    "Сектор НЗОП2 НЗД"
  }
};

LineMenuItem sub_menu_comp_NZOP2[8] =
{
  { NZOP2_TITLE, NULL},//title
  { &CONTROL1_COMP,  &sub_menu_NZOP, typeMenuSub},//control_item, parent
  { "Уставки НЗОП2",    (void *)&UstListCompNZOP2, typeMenuProg},
  { "Выдержки НЗОП2",   (void *)&VidListCompNZOP2, typeMenuProg},
  { "Управление НЗОП2", (void *)&UprListCompNZOP2, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compNZOP2[] =
{
  { "Уставки НЗОП2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_NZOP2, typeMenuList},//control_item, parent
  { "Уст НЗОП2",        (void *)&UstCompNZOP2, typeMenuProg},
  { "Уст НЗОП2 вперед", (void *)&UstCompNZOP2, typeMenuProg},
  { "Уст НЗОП2 назад",  (void *)&UstCompNZOP2, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compNZOP2[] =
{
  { "Выдержки НЗОП2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_NZOP2, typeMenuList},//control_item, parent
  { "Выдержка НЗОП2",        (void *)&VidCompNZOP2, typeMenuProg},
  { "Выдержка НЗОП2 вперед", (void *)&VidCompNZOP2, typeMenuProg},
  { "Выдержка НЗОП2 назад",  (void *)&VidCompNZOP2, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compNZOP2[] =
{
  { "Управл НЗОП2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_NZOP2, typeMenuList},//control_item, parent
  { "Вид НЗОП2",           (void *)&UprCompNZOP2, typeMenuProg},
  { "Управл НЗОП2",        (void *)&UprCompNZOP2, typeMenuProg},
  { "Направл НЗОП2",       (void *)&UprCompNZOP2, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompNZOP2(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidNZOP, sub_menu_ust_compNZOP2);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp3()

void UstListCompNZOP2()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compNZOP2);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompNZOP2);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompNZOP2()

void UstCompNZOP2()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compNZOP2);
  PassWord(EditUstNZOP2);
}//VidCompNZOP2()

void EditUstNZOP2()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compNZOP2);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompNZOP2()

//--------------------------------------------------

void PereinitVidListCompNZOP2(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidNZOP, sub_menu_vid_compNZOP2);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitVidListCompNZOP2(short flg)

void VidListCompNZOP2()
{
  SelectorMNGBAZA(MNGVID_NZOP1to2);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compNZOP2);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompNZOP2);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP2()

void VidCompNZOP2()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compNZOP2);
//  PassWord(EditVidAPV);
  EditVidNZOP2();
}//VidCompNZOP2()

void EditVidNZOP2()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compNZOP2);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompNZOP2(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compNZOP2, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompNZOP2()
{
  SelectorMNGBAZA(MNGUPR_NZOP1to2);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compNZOP2);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompNZOP2);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP2()

void UprCompNZOP2()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compNZOP2);
  PassWord(EditUprNZOP2);

}//UprCompNZOP2()

void EditUprNZOP2()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compNZOP2[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrNZOP1);//редактировать уставку управления
}//EditUprNZOP2()

short  KadrMenuFormat_upr_compNZOP2(void *pstr)//(WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compNZOP2[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //    UpravlViewerInKadr(nameUpr, i, workCntr);//отобразить уставку управления в кадре
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrNZOP1(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compNZOP2(WorkControl *workCntr)

int initUstNZOP2(char init)
{
 return initUstNZOP1(init);
}//initUstMTZ1(short mngUst, char init)

void  prepareUstNZOP2(short idxC)
{
  prepareUstNZOP1(idxC);
}//prepareUstMTZ3(short idxC)

int codecUstNZOP2(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  return codecUstNZOP1(codec, offset, ust);
}//codecUstNZOP1(char *buf, short offset, int ust)

void diffNZOP2ToRepozitar()
{
//копировать изменения компонента в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  NZOP2_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_NZOP2;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_NZOP;   //max к-во клонов
  rpzcomponent_obj.numClon     = 2;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstNZOP2;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstNZOP2;//подготовка уставок

  rpzcomponent_obj.nameStatusIO = ionsNZOP2;          //имена и статус команд IO

  rpzcomponent_obj.codecUst = codecUstNZOP2;   //кодировать-раскодировать уставку

}//

#endif // _HIDE_COMPONENT

