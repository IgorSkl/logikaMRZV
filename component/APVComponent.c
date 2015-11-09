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
#include "logictimers\logictimersfnc.h"

#include "virtualMenu\viewMenuList.h"

#include "psupervisor\psupervisor.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"

//код компонентов
#define KOD_COMPONENT  APV_COMP1
//к-во ступеней
#define CNT_STUPEN_APV  1

#endif // _HIDE_COMPONENT

//РАСПРЕДЕЛЕНИЕ УСТАВОК  в менеджере уставок
//уставка сработки
#define MNGUST_PO1_APV  0
#define MNGUST_PO2_APV  1
#define MNGUST_PO3_APV  2
#define MNGUST_PO4_APV  3

//voltage_different
#define MNGUST_POVD_APV 4
//angle_unbalance APV   
#define MNGUST_POAU_APV 5
//speed_angle APV
#define MNGUST_POSA_APV 6

//уставка выдержки
//Время 1 цикл АПВ tim2
#define MNGVID1_APV    7
//Время 2 цикл АПВ tim3
#define MNGVID2_APV    8
//Время Блокир АПВ tim8
#define MNGVID3_APV    9
//Время Блокир АПВ1 tim7
#define MNGVID4_APV    10
//Время Блокир АПВ от ВВ tim1
#define MNGVID5_APV    11
//Время внеш запрета АПВ tim6
#define MNGVID6_APV    12
//Время ож напр АПВ1 tim9
#define MNGVID7_APV    13
//Время ож син  АПВ1 tim10
#define MNGVID8_APV    14
//Время ож напр АПВ2 tim11
#define MNGVID9_APV    15
//Время ож син  АПВ2 tim12
#define MNGVID10_APV   16

//уставка управления
#define MNGUPR_APV    17
//к-во уставок в менеджере уставок
#define MNGUST_APV_TOTAL  18
//#define MNGUST_BOBV_APV  MNGUST_APV_TOTAL

//РАСПРЕДЕЛЕНИЕ ENA КОМАНД
#define ENA_APV_HALF1  0
#define ENA_APV_HALF2  1
#define ENA_APV_HALF3  2
#define ENA_APV_HALF4  3
#define ENA_APV_HALF5  4
//Управл АПВ1
#define ENA_APV_1      5
//Управл АПВ2
#define ENA_APV_2      6
//к-во ENA команд
#define ENACMD_APV_TOTAL 7

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//уставка сработки
#define SPVSRABUST_PO1_APV  0
#define SPVSRABUST_PO2_APV  1
#define SPVSRABUST_PO3_APV  2
#define SPVSRABUST_PO4_APV  3
//voltage_different
#define SPVSRABUST_POVD_APV 4
//angle_unbalance APV   
#define SPVSRABUST_POAU_APV 5
//speed_angle APV
#define SPVSRABUST_POSA_APV 6

//уставка возврата
#define SPVVOZVUST_PO1_APV  7
#define SPVVOZVUST_PO2_APV  8
#define SPVVOZVUST_PO3_APV  9
#define SPVVOZVUST_PO4_APV  10
//voltage_different
#define SPVVOZVUST_POVD_APV 11
//angle_unbalance APV   
#define SPVVOZVUST_POAU_APV 12
//speed_angle APV
#define SPVVOZVUST_POSA_APV 13
//уставка SPV выход
#define SPV_OUT1A_APV       14
#define SPV_OUT1B_APV       15
#define SPV_OUT1C_APV       16
#define SPV_OUT2A_APV       17
#define SPV_OUT2B_APV       18
#define SPV_OUT2C_APV       19
#define SPV_OUT3_APV        20
#define SPV_OUT4_APV        21
//voltage_different
#define SPV_OUT_POVD_APV    22
//angle_unbalance APV   
#define SPV_OUT_POAU_APV    23
//speed_angle APV
#define SPV_OUT_POSA_APV    24
//к-во уставок в супервизоре
#define SPVUST_APV_TOTAL    25

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ APV
//Стат блок АПВ
#define IOCMD1_APV 0
//Пуск АПВ
#define IOCMD2_APV 1
//Рестарт АПВ
#define IOCMD3_APV 2
//Вкл ВВ АПВ1
#define IOCMD4_APV 3
//Вкл ВВ АПВ2
#define IOCMD5_APV 4
//Работа АПВ
#define IOCMD6_APV 5
//к-во IO команд
#define IOCMD_APV_TOTAL    6

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ APV
//BLOK1
#define TLCMD1_APV 0
//BLOK2
#define TLCMD2_APV 1
//BLOK3
#define TLCMD3_APV 2
//PUSK_PULSE
#define TLCMD4_APV 3
//BLOK4
#define TLCMD5_APV 4
//START2
#define TLCMD6_APV 5
//RES_APV
#define TLCMD7_APV 6
//WORK_APV
#define TLCMD8_APV 7
//1C_APV
#define TLCMD9_APV 8
//2C_APV
#define TLCMD10_APV 9
//BVCMD_APV1
#define TLCMD11_APV 10
//BVCMD_APV2
#define TLCMD12_APV 11
//TOU1_APV
#define TLCMD13_APV 12
//TOS1_APV
#define TLCMD14_APV 13
//TOU2_APV
#define TLCMD15_APV 14
//TOS2_APV
#define TLCMD16_APV 15
//TRG1_APV
#define TLCMD17_APV 16
//TRG2_APV
#define TLCMD18_APV 17
//TRG3_APV
#define TLCMD19_APV 18
//TRG4_APV
#define TLCMD20_APV 19
//TRG5_APV
#define TLCMD21_APV 20
//TRG6_APV
#define TLCMD22_APV 21
//BLOK5
#define TLCMD23_APV 22
//к-во TL команд
#define TLCMD_APV_TOTAL    23

//--------------- TIMERS ------------------
//РАСПРЕДЕЛЕНИЕ ТАЙМЕРОВ ДЛЯ APV
//таймер APV_TIM1
#define TIMER1_APV   0
//таймер APV_TIM2
#define TIMER2_APV   1
//таймер APV_TIM3
#define TIMER3_APV   2
//таймер APV_TIM4
#define TIMER4_APV   3
//таймер APV_TIM5
#define TIMER5_APV   4
//таймер APV_TIM6
#define TIMER6_APV   5
//таймер APV_TIM7
#define TIMER7_APV   6
//таймер APV_TIM8
#define TIMER8_APV   7
//таймер APV_TIM9
#define TIMER9_APV   8
//таймер APV_TIM10
#define TIMER10_APV  9
//таймер APV_TIM11
#define TIMER11_APV  10
//таймер APV_TIM12
#define TIMER12_APV  11
//таймер APV_TIM_10MS
#define TIMER13_APV  12

//таймер APV_TIM7_BIS
#define TIMER7BIS_APV 13
//таймер APV_TIM8_BIS
#define TIMER8BIS_APV 14
//к-во таймеров
#define TIMERS_APV_TOTAL   15

#ifndef _HIDE_COMPONENT

//#define _HIDE_COMPONENT
//#include "PRM1Component.c"

extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация
extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];
extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре
extern int  IndexIO;//индекс IO
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern char *bitStringUNI[];
//extern int offsetUstMngPRM1;//смещение на уставки PRM1

void UstListCompAPV();
void ustRedactorCompAPV();
void UstCompAPV();
void  logicAPV(int idxC);
void setBOBVtimer_APV(int idxC);

void PereinitVidListCompAPV(short flg);
void VidListCompAPV();
void vidRedactorCompAPV();
void VidCompAPV();

void PereinitUprListCompAPV(short flg);
void UprListCompAPV();
void uprRedactorCompAPV();
void UprCompAPV();
short  KadrMenuFormat_upr_compAPV(void *workCntr);
short  KadrMenuFormat_ustvidAPV(void *workCntr);
int   initUstAPV(char init);
void  prepareUstAPV(short idxC);
char *selectorUprStrAPV(short iBit, UNS_32 ustUpr);

void EditUstAPV();
void EditVidAPV();
void EditUprAPV();
int codecUstAPV(char codec, short offset, int ust);

void UpravlChooser1APVInKadr(char *nameUpr, void *workCntr);
void UpravlChooser2APVInKadr(char *nameUpr, void *workCntr);
short choose1TxtAPV(char *locTxt, short ibit, UNS_32 ust);
short choose2TxtAPV(char *locTxt, short ibit, UNS_32 ust);
void UpravlRedactorChoose1APV(char *nameUpr);
void UpravlRedactorChoose2APV(char *nameUpr);
int   isDISactiv_APV(int idxC);

int  offsetIOCmdAPV;//смещение для IO APV

char APV_TITLE[] = "АПВ";

IONAMESTATUS_COMPONENT ionsAPV[IOCMD_APV_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок АПВ"
  },
  {
    1,//статус iocmd2
    "Пуск АПВ"
  },
  {
    1,//статус iocmd3
    "Рестарт АПВ"
  },
  {
    1,//статус iocmd4
    "Вкл ВВ АПВ1"
  },
  {
    1,//статус iocmd5
    "Вкл ВВ АПВ2"
  },
  {
    1,//статус iocmd6
    "Работа АПВ"
  }
};

LineMenuItem sub_menu_comp_APV[8] =
{
  { APV_TITLE, NULL},//title
  { &CONTROL1_COMP,   &sub_menu_cnf,   typeMenuSub},//control_item, parent
  { "Уставки АПВ",     (void *)&UstListCompAPV, typeMenuProg},
  { "Выдержки АПВ",    (void *)&VidListCompAPV, typeMenuProg},
  { "Управление АПВ",  (void *)&UprListCompAPV, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compAPV[] =
{
  { "Уставки АПВ", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_APV, typeMenuList},//control_item, parent
  { "Уст ПО1 АПВ",  (void *)&UstCompAPV, typeMenuProg},
  { "Уст ПО2 АПВ",  (void *)&UstCompAPV, typeMenuProg},
  { "Уст ПО3 АПВ",  (void *)&UstCompAPV, typeMenuProg},
  { "Уст ПО4 АПВ",  (void *)&UstCompAPV, typeMenuProg},
  { "Уст voltage АПВ",  (void *)&UstCompAPV, typeMenuProg},
  { "Уст angle   АПВ",  (void *)&UstCompAPV, typeMenuProg},
  { "Уст speed   АПВ",  (void *)&UstCompAPV, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compAPV[] =
{
  { "Выдержки АПВ", NULL},//title
  { &CONTROL2_COMP,     &sub_menu_comp_APV, typeMenuList},//control_item, parent
/*
  { "Время 1 цикл АПВ",       (void *)&VidCompAPV, typeMenuProg},//tim2
  { "Время 2 цикл АПВ",       (void *)&VidCompAPV, typeMenuProg},//tim3
  { "Время Блокир АПВ",       (void *)&VidCompAPV, typeMenuProg},//tim8
  { "Время Блокир АПВ1",      (void *)&VidCompAPV, typeMenuProg},//tim7
  { "Время Блокир АПВ от ВВ", (void *)&VidCompAPV, typeMenuProg},//tim1
  { "Время внеш запрета АПВ", (void *)&VidCompAPV, typeMenuProg},//tim6
  { "Время ож напр АПВ1",     (void *)&VidCompAPV, typeMenuProg},//tim9
  { "Время ож син  АПВ1",     (void *)&VidCompAPV, typeMenuProg},//tim10
  { "Время ож напр АПВ2",     (void *)&VidCompAPV, typeMenuProg},//tim11
  { "Время ож син  АПВ2",     (void *)&VidCompAPV, typeMenuProg},//tim12
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compAPV[] =
{
  { "Управл АПВ", NULL},//title
  { &CONTROL2_COMP,   &sub_menu_comp_APV, typeMenuList},//control_item, parent
  { "Вид АПВ",           (void *)&UprCompAPV, typeMenuProg},
  { "Выбор фазы синхр",  (void *)&UprCompAPV, typeMenuProg},
  { "Запрет АПВ",       (void *)&UprCompAPV, typeMenuProg},
  { "Блокир АПВ2",       (void *)&UprCompAPV, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompAPV(short flg)
{
//переиниц
  //инит компонентного контроля
//  sub_menu_ust_compAPV[SUBDATA].Line1 = ReturnTEXTCONTROL(TEXTCONTROL_COMP1);//control_item
  TxtStreamInit(&CONTROL2_COMP,//ReturnTEXTCONTROL(TEXTCONTROL_COMP1),
                &KadrMenuFormat_ustvidAPV, sub_menu_ust_compAPV);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP,//ReturnTEXTCONTROL(TEXTCONTROL_COMP1),
            SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UstListCompAPV()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compAPV);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompAPV);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompAPV()

void UstCompAPV()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compAPV);
  PassWord(EditUstAPV);
}//VidCompAPV()

void EditUstAPV()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compAPV);
}//EditUstAPV()

short  KadrMenuFormat_ustvidAPV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  char locTxt[50];
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    if(((LineMenuItem *)workCntr->userPoint)[i+1+SUBDATA].Line1==NULL)break;
    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, (char *) ((LineMenuItem *)workCntr->userPoint) [i+1+SUBDATA].Line1);
      sprintf(locTxt, "   %d", getUstOffsetMngUSTAVKI(i));
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_ust_1(WorkControl *workCntr)

//--------------------------------------------------

void PereinitVidListCompAPV(short flg)
{
//переиниц
  //инит компонентного контроля
//  sub_menu_vid_compAPV[SUBDATA].Line1 = ReturnTEXTCONTROL(TEXTCONTROL_COMP1);
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidAPV, sub_menu_vid_compAPV);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void VidListCompAPV()
{
  SelectorMNGBAZA(MNGVID1_APV);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compAPV);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control
  
  SelectorFHOME(&PereinitVidListCompAPV);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompAPV()

void VidCompAPV()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compAPV);
//  PassWord(EditVidAPV);
  EditVidAPV();
}//VidCompAPV()

void EditVidAPV()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compAPV);
}//EditVidAPV()

//--------------------------------------------------

void PereinitUprListCompAPV(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compAPV, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstList

void UprListCompAPV()
{
  SelectorMNGBAZA(MNGUPR_APV);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compAPV);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompAPV);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompAPV()

void UprCompAPV()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compAPV);
  PassWord(EditUprAPV);
}//VidCompAPV()

void EditUprAPV()
{
//редактировать уставку упр
  short linemenu = LIGHTLINEMENU;
  char *nameUpr = (char *)sub_menu_upr_compAPV[linemenu +1+SUBDATA].Line1;

  switch(linemenu)
  {
    case 0: UpravlRedactorChoose1APV(nameUpr);//редактировать уставку управления
    break;
    case 1: UpravlRedactorChoose2APV(nameUpr);//редактировать уставку управления
    break;
    default:UpravlRedactor(nameUpr, linemenu+3, &selectorUprStrAPV);//редактировать уставку управления
  }//switch

}//EditVidAPV()

void UpravlRedactorChoose1APV(char *nameUpr)
{
//редактировать уставку управления
/*
  FvmenuDis->EditChooseAPVPanel->Visible = true;

  char locTxt[50];
  switch(choose1TxtAPV(locTxt, 0, getCurrentMngUSTAVKI()))
  {
  case 0:
    FvmenuDis->Choose1APVButton->Checked = true;
    FvmenuDis->Choose2APVButton->Checked = false;
    FvmenuDis->Choose3APVButton->Checked = false;
    FvmenuDis->Choose4APVButton->Checked = false;
    FvmenuDis->Choose5APVButton->Checked = false;
    break;
  case 1:
    FvmenuDis->Choose1APVButton->Checked = false;
    FvmenuDis->Choose2APVButton->Checked = true;
    FvmenuDis->Choose3APVButton->Checked = false;
    FvmenuDis->Choose4APVButton->Checked = false;
    FvmenuDis->Choose5APVButton->Checked = false;
    break;
  case 2:
    FvmenuDis->Choose1APVButton->Checked = false;
    FvmenuDis->Choose2APVButton->Checked = false;
    FvmenuDis->Choose3APVButton->Checked = true;
    FvmenuDis->Choose4APVButton->Checked = false;
    FvmenuDis->Choose5APVButton->Checked = false;
    break;
  case 3:
    FvmenuDis->Choose1APVButton->Checked = false;
    FvmenuDis->Choose2APVButton->Checked = false;
    FvmenuDis->Choose3APVButton->Checked = false;
    FvmenuDis->Choose4APVButton->Checked = true;
    FvmenuDis->Choose5APVButton->Checked = false;
    break;
  case 4:
    FvmenuDis->Choose1APVButton->Checked = false;
    FvmenuDis->Choose2APVButton->Checked = false;
    FvmenuDis->Choose3APVButton->Checked = false;
    FvmenuDis->Choose4APVButton->Checked = false;
    FvmenuDis->Choose5APVButton->Checked = true;
    break;
  }//switch

  FvmenuDis->Str1Label->Caption = nameUpr;
  FvmenuDis->Str2Label->Caption = locTxt;
  FvmenuDis->Str3Label->Caption = "";
  FvmenuDis->Str4Label->Caption = "";
  */
}//UpravlRedactorMTZ(char *nameUpr)

void UpravlRedactorChoose2APV(char *nameUpr)
{
//редактировать уставку управления
/*
  FvmenuDis->EditChoose2APVPanel->Visible = true;

  char locTxt[50];
  switch(choose2TxtAPV(locTxt, 3, getCurrentMngUSTAVKI()))
  {
  case 0:
    FvmenuDis->Choose21APVButton->Checked = true;
    FvmenuDis->Choose22APVButton->Checked = false;
    FvmenuDis->Choose23APVButton->Checked = false;
    break;
  case 1:
    FvmenuDis->Choose21APVButton->Checked = false;
    FvmenuDis->Choose22APVButton->Checked = true;
    FvmenuDis->Choose23APVButton->Checked = false;
    break;
  case 2:
    FvmenuDis->Choose21APVButton->Checked = false;
    FvmenuDis->Choose22APVButton->Checked = false;
    FvmenuDis->Choose23APVButton->Checked = true;
    break;
  }//switch

  FvmenuDis->Str1Label->Caption = nameUpr;
  FvmenuDis->Str2Label->Caption = locTxt;
  FvmenuDis->Str3Label->Caption = "";
  FvmenuDis->Str4Label->Caption = "";
  */
}

short  KadrMenuFormat_upr_compAPV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  short chooseBit1 = 3;//к-во бит в choose1
  short chooseBit2 = 2;//к-во бит в choose2
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compAPV[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);
      switch(i)
      {
       case 0:
        //для Chooser1
        UpravlChooser1APVInKadr(nameUpr, workCntr);
       break;
       case 1:
        //для Chooser2
        UpravlChooser2APVInKadr(nameUpr, workCntr);
       break;
       default:
           strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
           selectorUprStrAPV(i +(chooseBit1+chooseBit2)-2, getCurrentMngUSTAVKI()));
      }//switch

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compAPV(WorkControl *workCntr)

void UpravlChooser1APVInKadr(char *nameUpr, void *pstr)//WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//отобразить уставку выбора-управления в кадре
  char locTxt[50];
  choose1TxtAPV(locTxt, 0, getCurrentMngUSTAVKI());//отобразить уставку выбора-управления в кадре
  strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
}//UpravlViewerInKadr(char *nameUpr, WorkControl *workCntr)

void UpravlChooser2APVInKadr(char *nameUpr, void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//отобразить уставку выбора-управления в кадре
  char locTxt[50];
  choose2TxtAPV(locTxt, 3, getCurrentMngUSTAVKI());//отобразить уставку выбора-управления в кадре
  strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
}//UpravlViewerInKadr(char *nameUpr, WorkControl *workCntr)

short choose1TxtAPV(char *locTxt, short ibit, UNS_32 ust)
{
//отобразить уставку выбора-управления в кадре
  switch(NumBitCheckWord(ibit, &ust) + NumBitCheckWord(ibit+1, &ust)*2 + NumBitCheckWord(ibit+2, &ust)*4)
  {
  case 0:
    strcpy(locTxt, "Без контроля");
    return 0;
  case 1:
    strcpy(locTxt, "Нет линии, есть шина");
    return 1;
  case 2:
    strcpy(locTxt, "Есть линия, нет шины");
    return 2;
  case 3:
    strcpy(locTxt, "Есть линия, есть шина, без синхр");
    return 3;
  case 4:
    strcpy(locTxt, "Есть линия, есть шина, есть синхр");
    return 4;
  default:
    strcpy(locTxt, "error chs");
  }//switch
  return -1;
}//

short choose2TxtAPV(char *locTxt, short ibit, UNS_32 ust)
{
//отобразить уставку выбора-управления в кадре
  switch(NumBitCheckWord(ibit, &ust) + NumBitCheckWord(ibit+1, &ust)*2)
  {
  case 0:
    strcpy(locTxt, "Фаза А");
    return 0;
  case 1:
    strcpy(locTxt, "Фаза В");
    return 1;
  case 2:
    strcpy(locTxt, "Фаза С");
    return 2;
  case 3:
    strcpy(locTxt, "Choose 3");
    return 3;
  }//switch
  return -1;
}//

char *selectorUprStrAPV(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
}//selectorUprStrAPV(short ibit, UNS_32 ustUpr)

int initUstAPV(char init)
{
  //инициал уставок
  if (init)
  {
//уставка сработки
    tmpUSTAVKI[MNGUST_PO1_APV] = 10;
    tmpUSTAVKI[MNGUST_PO2_APV] = 20;
    tmpUSTAVKI[MNGUST_PO3_APV] = 30;
    tmpUSTAVKI[MNGUST_PO4_APV] = 40;
//voltage_different
    tmpUSTAVKI[MNGUST_POVD_APV] = 10;
//angle_unbalance APV   
    tmpUSTAVKI[MNGUST_POAU_APV] = 10;
//speed_angle APV
    tmpUSTAVKI[MNGUST_POSA_APV] = 10;

//уставка выдержки
    //Время 1 цикл АПВ tim2
    tmpUSTAVKI[MNGVID1_APV] = 20;   
    //Время 2 цикл АПВ tim3
    tmpUSTAVKI[MNGVID2_APV] = 25;
    //Время Блокир АПВ tim8
    tmpUSTAVKI[MNGVID3_APV] = 53;
    //Время Блокир АПВ1 tim7
    tmpUSTAVKI[MNGVID4_APV] = 15;
    //Время Блокир АПВ от ВВ tim1
    tmpUSTAVKI[MNGVID5_APV] = 55;
    //Время внеш запрета АПВ tim6
    tmpUSTAVKI[MNGVID6_APV] = 56;
    //Время ож напр АПВ1 tim9
    tmpUSTAVKI[MNGVID7_APV] = 15;
    //Время ож син  АПВ1 tim10
    tmpUSTAVKI[MNGVID8_APV] = 15;
    //Время ож напр АПВ2 tim11
    tmpUSTAVKI[MNGVID9_APV] = 15;
    //Время ож син  АПВ2 tim12
    tmpUSTAVKI[MNGVID10_APV] = 15;
//уставка управления
    tmpUSTAVKI[MNGUPR_APV] = 0;//2+8 +64+32;

  }//if

  IndexUstSPV += SPVUST_APV_TOTAL;//индекс уставок в супервизоре
  return MNGUST_APV_TOTAL;//к-во уставок в менеджере уставок
}//initUstAPV(short mngUst, char init)

void  prepareUstAPV(short idxC)
{
  //подготовка ENA команд для клона
  //копировать ENA из WideENA в ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_APV), ENACMD_APV_TOTAL);
  //подготовка уставок
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//смещение уставок внутри супервизора
    //уставка SPV сработки
    int tmp1 = 
    SPV_UST(SPVSRABUST_PO1_APV) = codecUstAPV(1, MNGUST_PO1_APV, getNativUstMngUSTAVKI(idxC, MNGUST_PO1_APV));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_PO1_APV) = tmp1 - tmp1/20;//5%
    //уставка SPV сработки
    tmp1 = 
    SPV_UST(SPVSRABUST_PO2_APV) = codecUstAPV(1, MNGUST_PO2_APV, getNativUstMngUSTAVKI(idxC, MNGUST_PO2_APV));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_PO2_APV) = tmp1 + tmp1/20;//5%
    //уставка SPV сработки
    tmp1 = 
    SPV_UST(SPVSRABUST_PO3_APV) = codecUstAPV(1, MNGUST_PO3_APV, getNativUstMngUSTAVKI(idxC, MNGUST_PO3_APV));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_PO3_APV) = tmp1 - tmp1/20;//5%
    //уставка SPV сработки
    tmp1 = 
    SPV_UST(SPVSRABUST_PO4_APV) = codecUstAPV(1, MNGUST_PO4_APV, getNativUstMngUSTAVKI(idxC, MNGUST_PO4_APV));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_PO4_APV) = tmp1 + tmp1/20;//5%

    //voltage_different уставка SPV сработки DOWN
    tmp1 = //voltage_different                      //voltage_different                          //voltage_different
    SPV_UST(SPVSRABUST_POVD_APV) = codecUstAPV(1, MNGUST_POVD_APV, getNativUstMngUSTAVKI(idxC, MNGUST_POVD_APV));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_POVD_APV) = tmp1 + tmp1/20;//5%

    tmp1 = //angle_unbalance APV                  //angle_unbalance APV                       //angle_unbalance APV
    SPV_UST(SPVSRABUST_POAU_APV) = codecUstAPV(1, MNGUST_POAU_APV, getNativUstMngUSTAVKI(idxC, MNGUST_POAU_APV));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_POAU_APV) = tmp1 + 2;//tmp1/20;//5% - точность хромает

    tmp1 = //speed_angle APV                  //speed_angle APV                       //speed_angle APV
    SPV_UST(SPVSRABUST_POSA_APV) = codecUstAPV(1, MNGUST_POSA_APV, getNativUstMngUSTAVKI(idxC, MNGUST_POSA_APV));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_POSA_APV) = tmp1 + tmp1/20;//5%

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //компонент в конфигурации

      //Время 1 цикл АПВ tim2
   setTimerPorog(tmpOffsetT+ TIMER2_APV,
          codecUstAPV(1, MNGVID1_APV, getNativUstMngUSTAVKI(idxC, MNGVID1_APV)));
      //Время 2 цикл АПВ tim3
   setTimerPorog(tmpOffsetT+ TIMER3_APV,
          codecUstAPV(1, MNGVID2_APV, getNativUstMngUSTAVKI(idxC, MNGVID2_APV)));
      //Время Блокир АПВ tim8
   setTimerPorog(tmpOffsetT+ TIMER8_APV,
          codecUstAPV(1, MNGVID3_APV, getNativUstMngUSTAVKI(idxC, MNGVID3_APV)));
      //Время Блокир АПВ1 tim7
   setTimerPorog(tmpOffsetT+ TIMER7_APV,
          codecUstAPV(1, MNGVID4_APV, getNativUstMngUSTAVKI(idxC, MNGVID4_APV)));
      //Время Блокир АПВ от ВВ tim1
   setTimerPorog(tmpOffsetT+ TIMER1_APV, 
          codecUstAPV(1, MNGVID5_APV, getNativUstMngUSTAVKI(idxC, MNGVID5_APV)));
      //Время внеш запрета АПВ tim6
   setTimerPorog(tmpOffsetT+ TIMER6_APV,
          codecUstAPV(1, MNGVID6_APV, getNativUstMngUSTAVKI(idxC, MNGVID6_APV)));
      //Время ож напр АПВ1 tim9
   setTimerPorog(tmpOffsetT+ TIMER9_APV,
          codecUstAPV(1, MNGVID7_APV, getNativUstMngUSTAVKI(idxC, MNGVID7_APV)));
      //Время ож син  АПВ1 tim10
   setTimerPorog(tmpOffsetT+ TIMER10_APV,
          codecUstAPV(1, MNGVID8_APV, getNativUstMngUSTAVKI(idxC, MNGVID8_APV)));
      //Время ож напр АПВ2 tim11
   setTimerPorog(tmpOffsetT+ TIMER11_APV,
          codecUstAPV(1, MNGVID9_APV, getNativUstMngUSTAVKI(idxC, MNGVID9_APV)));
      //Время ож син  АПВ2 tim12
   setTimerPorog(tmpOffsetT+ TIMER12_APV,
          codecUstAPV(1, MNGVID10_APV, getNativUstMngUSTAVKI(idxC, MNGVID10_APV)));

      //Время Блокир АПВ tim8BIS
   setTimerPorog(tmpOffsetT+ TIMER8BIS_APV,
          codecUstAPV(1, MNGVID3_APV, getNativUstMngUSTAVKI(idxC, MNGVID3_APV)));
      //Время Блокир АПВ1 tim7BIS
   setTimerPorog(tmpOffsetT+ TIMER7BIS_APV,
          codecUstAPV(1, MNGVID4_APV, getNativUstMngUSTAVKI(idxC, MNGVID4_APV)));

  setTimerPorog(tmpOffsetT+ TIMER4_APV, 1);//500);
  setTimerPorog(tmpOffsetT+ TIMER5_APV, 1);//500);

  //таймер APV_TIM_10MS
  setTimerPorog(tmpOffsetT+ TIMER13_APV, 10);

}//prepareUstMTZ1(short idxC)

int initIOCmd_APV()
{
  //инициал IO команд
  offsetIOCmdAPV = IndexIO;//смещение для IO APV
  return commonInitIOCmd(IOCMD_APV_TOTAL);
}//initIOCmd_APV()

int initTLCmd_APV()
{
  //инициал TL команд
  return commonInitTLCmd(TLCMD_APV_TOTAL);
}//initTLCmd_APV()

int initENACmd_APV()
{
  //инициал ENA команд
  return commonInitENACmd(ENACMD_APV_TOTAL);
}//initENACmd_APV()

void initTimersAPV(short idxC)
{
  //запрос и инициал таймеров
  commonInitTimers(TIMERS_APV_TOTAL);
}//initTimersAPV()

int codecUstAPV(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  if(codec) return ust*1;
  return ust/1;
}//codecUstAPV(char *buf, short offset, int ust)

int isDISactiv_APV(int idxC)
{
 //активность Регистратора ДИС
//    int tmpOffsetT    =
  //              cnfCOMPONENT[idxC].offsetTimers;   //таймера компонента в конфигурации
//  return 0;//нет активности
    int tmpOffsetT    =
                cnfCOMPONENT[idxC].offsetTimers;   //таймера компонента в конфигурации
    for(int i=0; i<TIMERS_APV_TOTAL; i++)
    {
      if(getTimerBUSY(tmpOffsetT+i) |
         getTimerFINISH(tmpOffsetT+i)
         )
         return 1;//есть активность
    }//
  return 0;//нет активности

}//isDISactiv_APV(int idxC)

void SaveUprAPV(short ibit)
{
  /*
//персональное сохр upr для APV
  UNS_32 tmpU = getCurrentMngUSTAVKI();//текущая уст упр
    //Управление APV
    switch(ibit)
    {
      // if(ibit==0)
      //chooser1
    case 0:
    {
      if(FvmenuDis->Choose1APVButton->Checked)
      {
        NumBitClearingWord(0,   &tmpU);//сброс бита по его индексу
        NumBitClearingWord(1, &tmpU);//сброс бита по его индексу
        NumBitClearingWord(2, &tmpU);//сброс бита по его индексу
      }//if
      if(FvmenuDis->Choose2APVButton->Checked)
      {
        NumBitSettingWord(0,    &tmpU);//сброс бита по его индексу
        NumBitClearingWord(1, &tmpU);//сброс бита по его индексу
        NumBitClearingWord(2, &tmpU);//сброс бита по его индексу
      }//if
      if(FvmenuDis->Choose3APVButton->Checked)
      {
        NumBitClearingWord(0, &tmpU);//сброс бита по его индексу
        NumBitSettingWord(1,    &tmpU);//сброс бита по его индексу
        NumBitClearingWord(2, &tmpU);//сброс бита по его индексу
      }//if
      if(FvmenuDis->Choose4APVButton->Checked)
      {
        NumBitSettingWord(0,    &tmpU);//сброс бита по его индексу
        NumBitSettingWord(1,  &tmpU);//сброс бита по его индексу
        NumBitClearingWord(2, &tmpU);//сброс бита по его индексу
      }//if
      if(FvmenuDis->Choose5APVButton->Checked)
      {
        NumBitClearingWord(0,   &tmpU);//сброс бита по его индексу
        NumBitClearingWord(1, &tmpU);//сброс бита по его индексу
        NumBitSettingWord(2, &tmpU);//сброс бита по его индексу
      }//if
    }//case 0
    break;

    //chooser2
    case 1:
    {
      if(FvmenuDis->Choose21APVButton->Checked)
      {
        NumBitClearingWord(3,   &tmpU);//сброс бита по его индексу
        NumBitClearingWord(3+1, &tmpU);//сброс бита по его индексу
//        NumBitClearingWord(ibit+2, &tmpU);//сброс бита по его индексу
      }//if
      if(FvmenuDis->Choose22APVButton->Checked)
      {
        NumBitSettingWord(3,    &tmpU);//сброс бита по его индексу
        NumBitClearingWord(3+1, &tmpU);//сброс бита по его индексу
        //      NumBitClearingWord(ibit+2, &tmpU);//сброс бита по его индексу
      }//if
      if(FvmenuDis->Choose23APVButton->Checked)
      {
        NumBitClearingWord(3,  &tmpU);//сброс бита по его индексу
        NumBitSettingWord(3+1, &tmpU);//сброс бита по его индексу
        //    NumBitClearingWord(ibit+2, &tmpU);//сброс бита по его индексу
      }//if
    }//case 1
    break;

    default:
    {
      if(FvmenuDis->UprCheck->Checked)
      {
        NumBitSettingWord(ibit+5 -2, &tmpU);//установка бита по его индексу
      }//if(FvmenuDis->UprCheck->Checked)
      else
      {
        NumBitClearingWord(ibit+5 -2, &tmpU);//сброс бита по его индексу
      }
    }//default
    }//switch(ibit)

  setCurrentMngUSTAVKI(tmpU);//новая уст упр
  */
}//

char copyAPVToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое

//копировать компонент в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.packet = 0;    //номер пакетного компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  APV_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_APV;//меню компонента

  rpzcomponent_obj.cntClon      = CNT_STUPEN_APV;   //max к-во клонов
  rpzcomponent_obj.numClon      = 1;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstAPV;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstAPV;//подготовка уставок
  rpzcomponent_obj.initIOCmd      = initIOCmd_APV;      //инициал IO команд
  rpzcomponent_obj.initTLCmd      = initTLCmd_APV;      //инициал TL команд
  rpzcomponent_obj.initENACmd     = initENACmd_APV;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_APV; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsAPV;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersAPV;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicAPV;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstAPV;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT


