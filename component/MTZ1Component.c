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
#include "logictimers\logictimersfnc.h"

#include "virtualMenu\viewMenuList.h"

#include "psupervisor\psupervisor.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"

//код компонентa
#define KOD_COMPONENT  MTZ_COMP1
//к-во ступеней
#define CNT_STUPEN_MTZ  5

#endif // _HIDE_COMPONENT

//---------------MANAGER UST------------------
//РАСПРЕДЕЛЕНИЕ УСТАВОК  в менеджере уставок
//уставка сработки
#define MNGUST_MTZ1     0
#define MNGUST_MTZ1_V   1
#define MNGUST_MTZ1_N   2
#define MNGUST_MTZ1_PN  3
#define MNGUST_MTZ1_UPN 4

//уставка выдержки
#define MNGVID_MTZ1    5
#define MNGVID_MTZ1_V  6
#define MNGVID_MTZ1_N  7
#define MNGVID_MTZ1_PN 8

//уставка управления
#define MNGUPR_MTZ1    9
//к-во уставок в менеджере уставок
#define MNGUST_MTZ1_TOTAL  10
//#define MNGUST_BOBV_MTZ1  MNGUST_MTZ1_TOTAL

//РАСПРЕДЕЛЕНИЕ ENA команд
#define ENA_MTZ1_HALF1  0
#define ENA_MTZ1_HALF2  1
#define ENA_MTZ1_1      2
#define ENA_MTZ1_2      3
#define ENA_MTZ1_3      4
//к-во ENA команд
#define ENACMD_MTZ1_TOTAL 5

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//уставка SPV сработки
#define SPVSRABUST_MTZ1     0
#define SPVSRABUST_MTZ1_V   1
#define SPVSRABUST_MTZ1_N   2
#define SPVSRABUST_MTZ1_PN  3
#define SPVSRABUST_MTZ1_UPN 4
//уставка SPV возврата
#define SPVVOZVUST_MTZ1     5
#define SPVVOZVUST_MTZ1_V   6
#define SPVVOZVUST_MTZ1_N   7
#define SPVVOZVUST_MTZ1_PN  8
#define SPVVOZVUST_MTZ1_UPN 9
//уставка SPV выход
#define SPV_OUTA_MTZ1      10
#define SPV_OUTB_MTZ1      11
#define SPV_OUTC_MTZ1      12

#define SPV_OUTA_MTZ1_V    13
#define SPV_OUTB_MTZ1_V    14
#define SPV_OUTC_MTZ1_V    15

#define SPV_OUTA_MTZ1_N    16
#define SPV_OUTB_MTZ1_N    17
#define SPV_OUTC_MTZ1_N    18

#define SPV_OUTA_MTZ1_PN   19
#define SPV_OUTB_MTZ1_PN   20
#define SPV_OUTC_MTZ1_PN   21

#define SPV_OUTA_MTZ1_UPN  22
#define SPV_OUTB_MTZ1_UPN  23
#define SPV_OUTC_MTZ1_UPN  24
//к-во уставок SPV в супервизоре
#define SPVUST_MTZ1_TOTAL  25

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ MTZ1
//Стат блок МТЗ1
#define IOCMD1_MTZ1 0
//Сраб ПО МТЗ1
#define IOCMD2_MTZ1 1
//Сраб ПО МТЗ1 ВПД
#define IOCMD3_MTZ1 2
//Сраб ПО МТЗ1 НЗД
#define IOCMD4_MTZ1 3
//Сраб ПО МТЗ1 ПН
#define IOCMD5_MTZ1 4
//Сраб МТЗ1
#define IOCMD6_MTZ1 5
//Сектор МТЗ1 ВПД
#define IOCMD7_MTZ1 6
//Сектор МТЗ1 НЗД
#define IOCMD8_MTZ1 7
//к-во IO команд
#define IOCMD_MTZ1_TOTAL    8

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ MTZ1
//MTZ1_PO2
#define TLCMD1_MTZ1  0
//MTZ1_PO3
#define TLCMD2_MTZ1  1
//MTZ1_PO4
#define TLCMD3_MTZ1  2
//isFAILU_INVERT
//#define TLCMDFU_MTZ1  3
//ELOLDTRG_NCN_MTZ1
#define TLCMDOLDNCN_MTZ1 4
//ELOUTTRG_NCN_MTZ1
#define TLCMDOUTNCN_MTZ1 5
//к-во TL команд
#define TLCMD_MTZ1_TOTAL 6

//--------------- TIMERS ------------------
//РАСПРЕДЕЛЕНИЕ ТАЙМЕРОВ ДЛЯ MTZ1
//таймер 0
#define TIMER1_MTZ1   0
//таймер 1
#define TIMER2_MTZ1   1
//таймер 2
#define TIMER3_MTZ1   2
//таймер 3
#define TIMER4_MTZ1   3
//таймер 4 BO
#define TIMER_BO_MTZ1 4
//к-во таймеров
#define TIMERS_MTZ1_TOTAL   5

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];
extern int  spvUSTAVKI[];//текущие уставки супервизора

extern LineMenuItem sub_menu_MTZ[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре
extern int  IndexIO;//индекс IO

extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//смещение на уставки PRM1

void PereinitUstListCompMTZ1(short flg);
void UstListCompMTZ1();
void ustRedactorCompMTZ1();
void UstCompMTZ1();

void PereinitVidListCompMTZ1(short flg);
void VidListCompMTZ1();
void vidRedactorCompMTZ1();
void VidCompMTZ1();

void PereinitUprListCompMTZ1(short flg);
void UprListCompMTZ1();
void uprRedactorCompMTZ1();
void UprCompMTZ1();
short  KadrMenuFormat_upr_compMTZ1(void *workCntr);
int  initUstMTZ1(char init);
void  prepareUstMTZ1(short idxC);
void UpravlRedactorChooseMTZ(char *nameUpr, short ibit);

short  KadrMenuFormat_MTZ1(void *workCntr);

void EditUstMTZ1();
void EditVidMTZ1();
void EditUprMTZ1();
int codecUstMTZ1(char codec, short offset, int ust);
short  KadrMenuFormat_ustvidMTZ(void *workCntr);
short chooseTxtMTZ(char *locTxt, short ibit, UNS_32 ust);
char *selectorUprStrMTZ1(short iBit, UNS_32 ustUpr);
void UpravlChooserMTZInKadr(char *nameUpr, short ibit, void *workCntr);
void  logicMTZ1(int idxC);
int   isDISactiv_MTZ1(int idxC);

int  offsetIOCmdMTZ1;//смещение для IO MTZ1

char MTZ1_TITLE[] = "МТЗ1";

IONAMESTATUS_COMPONENT ionsMTZ1[IOCMD_MTZ1_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок МТЗ1"
  },
  {
    1,//статус iocmd2
    "Сраб ПО МТЗ1"
  },
  {
    1,//статус iocmd3
    "Сраб ПО МТЗ1 ВПД"
  },
  {
    1,//статус iocmd4
    "Сраб ПО МТЗ1 НЗД"
  },
  {
    1,//статус iocmd5
    "Сраб ПО МТЗ1 ПН"
  },
  {
    1,//статус iocmd6
    "Сраб МТЗ1"
  },
  {
    1,//статус iocmd7
    "Сектор МТЗ1 ВПД"
  },
  {
    1,//статус iocmd8
    "Сектор МТЗ1 НЗД"
  }
};

LineMenuItem sub_menu_comp_MTZ1[8] =
{
  { MTZ1_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_MTZ, typeMenuSub},//control_item, parent
  { "Уставки МТЗ1",    (void *)&UstListCompMTZ1, typeMenuProg},
  { "Выдержки МТЗ1",   (void *)&VidListCompMTZ1, typeMenuProg},
  { "Управление МТЗ1", (void *)&UprListCompMTZ1, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compMTZ1[] =
{
  { "Уставки МТЗ1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_MTZ1, typeMenuList},//control_item, parent
  { "Уст МТЗ1",         (void *)&UstCompMTZ1, typeMenuProg},
  { "Уст МТЗ1 вперед",  (void *)&UstCompMTZ1, typeMenuProg},
  { "Уст МТЗ1 назад",   (void *)&UstCompMTZ1, typeMenuProg},
  { "Уст МТЗ1 ПH",      (void *)&UstCompMTZ1, typeMenuProg},
  { "Уст напр МТЗ1 ПH", (void *)&UstCompMTZ1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compMTZ1[] =
{
  { "Выдержки МТЗ1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_MTZ1, typeMenuList},//control_item, parent
  { "Выдержка МТЗ1",        (void *)&VidCompMTZ1, typeMenuProg},
  { "Выдержка МТЗ1 вперед", (void *)&VidCompMTZ1, typeMenuProg},
  { "Выдержка МТЗ1 назад",  (void *)&VidCompMTZ1, typeMenuProg},
  { "Выдержка МТЗ1 ПH",     (void *)&VidCompMTZ1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compMTZ1[] =
{
  { "Управл МТЗ1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_MTZ1, typeMenuList},//control_item, parent
  { "Вид МТЗ1",           (void *)&UprCompMTZ1, typeMenuProg},
  { "Управл МТЗ1",        (void *)&UprCompMTZ1, typeMenuProg},
  { "МТЗ1 вперед",        (void *)&UprCompMTZ1, typeMenuProg},
  { "МТЗ1 назад",         (void *)&UprCompMTZ1, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompMTZ1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_ust_compMTZ1);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UstListCompMTZ1()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compMTZ1);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompMTZ1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompMTZ1()

void UstCompMTZ1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compMTZ1);
  PassWord(EditUstMTZ1);
}//VidCompMTZ1()

void EditUstMTZ1()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compMTZ1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompMTZ1()

short  KadrMenuFormat_ustvidMTZ(void *pstr)
{
  WorkControl *workCntr  = (WorkControl *)pstr;
//формирователь кадра
  char locTxt[50];
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    if(((LineMenuItem *)workCntr->userPoint)[i+1+SUBDATA].Line1==NULL)break;
    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, (char *)( ((LineMenuItem *)workCntr->userPoint) )[i+1+SUBDATA].Line1);
      sprintf(locTxt, "   %d", getUstOffsetMngUSTAVKI(i));
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_ust_1(WorkControl *workCntr)

//--------------------------------------------------

void PereinitVidListCompMTZ1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_vid_compMTZ1);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void VidListCompMTZ1()
{
  SelectorMNGBAZA(MNGVID_MTZ1);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compMTZ1);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompMTZ1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ1()

void VidCompMTZ1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compMTZ1);
//  PassWord(EditVidAPV);
  EditVidMTZ1();
}//VidCompMTZ1()

void EditVidMTZ1()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compMTZ1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompMTZ1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compMTZ1, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompMTZ1()
{
  SelectorMNGBAZA(MNGUPR_MTZ1);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compMTZ1);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompMTZ1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ1()

void UprCompMTZ1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compMTZ1);
  PassWord(EditUprMTZ1);
}//VidCompMTZ1()

void EditUprMTZ1()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compMTZ1[LIGHTLINEMENU +1+SUBDATA].Line1;

  switch(LIGHTLINEMENU)
  {
    case 0: UpravlRedactorChooseMTZ(nameUpr, LIGHTLINEMENU);//редактировать уставку управления
    break;
    default:UpravlRedactor(nameUpr, LIGHTLINEMENU+1, &selectorUprStrMTZ1);//редактировать уставку управления
  }//switch

}//EditVidMTZ1()

void UpravlRedactorChooseMTZ(char *nameUpr, short ibit)
{
//редактировать уставку управления
//  CRR_SUBMENU = sub_menu_tmp;//текущее субменю
//  ResetAllButton();//погасить все клавиши
/*
  FvmenuDis->EditChooseMTZPanel->Visible = true;

  char locTxt[50];
  switch(chooseTxtMTZ(locTxt, ibit, getCurrentMngUSTAVKI()))
  {
  case 0:
    FvmenuDis->Choose1MTZButton->Checked = true;
    FvmenuDis->Choose2MTZButton->Checked = false;
    FvmenuDis->Choose3MTZButton->Checked = false;
    FvmenuDis->Choose4MTZButton->Checked = false;
    break;
  case 1:
    FvmenuDis->Choose1MTZButton->Checked = false;
    FvmenuDis->Choose2MTZButton->Checked = true;
    FvmenuDis->Choose3MTZButton->Checked = false;
    FvmenuDis->Choose4MTZButton->Checked = false;
    break;
  case 2:
    FvmenuDis->Choose1MTZButton->Checked = false;
    FvmenuDis->Choose2MTZButton->Checked = false;
    FvmenuDis->Choose3MTZButton->Checked = true;
    FvmenuDis->Choose4MTZButton->Checked = false;
    break;
  case 3:
    FvmenuDis->Choose1MTZButton->Checked = false;
    FvmenuDis->Choose2MTZButton->Checked = false;
    FvmenuDis->Choose3MTZButton->Checked = false;
    FvmenuDis->Choose4MTZButton->Checked = true;
    break;
  }//switch

  FvmenuDis->Str1Label->Caption = nameUpr;
  FvmenuDis->Str2Label->Caption = locTxt;
  FvmenuDis->Str3Label->Caption = "";
  FvmenuDis->Str4Label->Caption = "";
  */
}//UpravlRedactorMTZ(char *nameUpr)

short  KadrMenuFormat_upr_compMTZ1(void *pstr)
{
  WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  short chooseBit = 2;//к-во бит в choose
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compMTZ1[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      if(i<(chooseBit-1))
        UpravlChooserMTZInKadr(nameUpr, i, workCntr);
      else
        //отобразить уставку управления в кадре
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
        selectorUprStrMTZ1(i+(chooseBit-1), getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compMTZ1(WorkControl *workCntr)

char *selectorUprStrMTZ1(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
}//selectorUprStrMTZ1(short ibit, UNS_32 ustUpr)

short chooseTxtMTZ(char *locTxt, short ibit, UNS_32 ust)
{
//отобразить уставку выбора-управления в кадре
  switch(NumBitCheckWord(ibit, &ust) + NumBitCheckWord(ibit+1, &ust)*2)
  {
  case 0:
    strcpy(locTxt, "Простая");
    return 0;
  case 1:
    strcpy(locTxt, "Направленная");
    return 1;
  case 2:
    strcpy(locTxt, "Пуск по напр");
    return 2;
  case 3:
    strcpy(locTxt, "Choose 3");
    return 3;
  }//switch
  return -1;
}//

//choose
void UpravlChooserMTZInKadr(char *nameUpr, short ibit, void *pstr)
{
  WorkControl *workCntr = (WorkControl *)pstr;
//отобразить уставку выбора-управления в кадре
  char locTxt[50];
  chooseTxtMTZ(locTxt, ibit, getCurrentMngUSTAVKI());//отобразить уставку выбора-управления в кадре
  strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
}//UpravlViewerInKadr(char *nameUpr, WorkControl *workCntr)

int initUstMTZ1(char init)
{
  //инициал уставок
  if (init)
  {
//уставка сработки
    tmpUSTAVKI[MNGUST_MTZ1]     = 100;
    tmpUSTAVKI[MNGUST_MTZ1_V]   = 110;
    tmpUSTAVKI[MNGUST_MTZ1_N]   = 120;
    tmpUSTAVKI[MNGUST_MTZ1_PN]  = 130;
    tmpUSTAVKI[MNGUST_MTZ1_UPN] = 131;
//уставка выдержки
    tmpUSTAVKI[MNGVID_MTZ1]    = 15;
    tmpUSTAVKI[MNGVID_MTZ1_V]  = 16;
    tmpUSTAVKI[MNGVID_MTZ1_N]  = 17;
    tmpUSTAVKI[MNGVID_MTZ1_PN] = 18;
//уставка управления
    tmpUSTAVKI[MNGUPR_MTZ1] = 0;

  }//if

  IndexUstSPV += SPVUST_MTZ1_TOTAL;//индекс уставок в супервизоре
  return MNGUST_MTZ1_TOTAL;//к-во уставок в менеджере уставок
}//initUstMTZ1(short mngUst, char init)

void  prepareUstMTZ1(short idxC)
{
  //подготовка ENA команд для клона idxC
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_MTZ1), ENACMD_MTZ1_TOTAL);
  //подготовка уставок
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//смещение уставок внутри супервизора

    //уставка SPV сработки
    int tmp1 = 
    SPV_UST(SPVSRABUST_MTZ1) = codecUstMTZ1(1, MNGUST_MTZ1, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ1));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_MTZ1) = tmp1 - tmp1/20;//5%

    //уставка SPV сработки
        tmp1 = 
    SPV_UST(SPVSRABUST_MTZ1_V) = codecUstMTZ1(1, MNGUST_MTZ1_V, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ1_V));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_MTZ1_V) = tmp1 - tmp1/20;//5%

    //уставка SPV сработки
        tmp1 = 
    SPV_UST(SPVSRABUST_MTZ1_N) = codecUstMTZ1(1, MNGUST_MTZ1_N, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ1_N));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_MTZ1_N) = tmp1 - tmp1/20;//5%

    //уставка SPV сработки
        tmp1 =
    SPV_UST(SPVSRABUST_MTZ1_PN) = codecUstMTZ1(1, MNGUST_MTZ1_PN, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ1_PN));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_MTZ1_PN) = tmp1 - tmp1/20;//5%

    //уставка SPV сработки DOWN
        tmp1 =
    SPV_UST(SPVSRABUST_MTZ1_UPN) = codecUstMTZ1(1, MNGUST_MTZ1_UPN, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ1_UPN));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_MTZ1_UPN) = tmp1 + tmp1/20;//DOWN 5%

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //компонент в конфигурации

          //таймер 1
   setTimerPorog(tmpOffsetT+ TIMER1_MTZ1, 
          codecUstMTZ1(1, MNGVID_MTZ1, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ1)));

          //таймер 2
   setTimerPorog(tmpOffsetT+ TIMER2_MTZ1,
          codecUstMTZ1(1, MNGVID_MTZ1_V, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ1_V)));

          //таймер 3
   setTimerPorog(tmpOffsetT+ TIMER3_MTZ1, 
          codecUstMTZ1(1, MNGVID_MTZ1_N, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ1_N)));

          //таймер 4
   setTimerPorog(tmpOffsetT+ TIMER4_MTZ1, 
          codecUstMTZ1(1, MNGVID_MTZ1_PN, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ1_PN)));

         //таймер 5 BO
   setTimerPorog(tmpOffsetT+ TIMER_BO_MTZ1, 10);

}//prepareUstMTZ1(short idxC)

int initIOCmd_MTZ1()
{
  //инициал IO команд
  offsetIOCmdMTZ1 = IndexIO;//смещение для IO MTZ1
  return commonInitIOCmd(IOCMD_MTZ1_TOTAL);
}

int initTLCmd_MTZ1()
{
  //инициал TL команд
  return commonInitTLCmd(TLCMD_MTZ1_TOTAL);
}//initTLCmd_MTZ1()

int initENACmd_MTZ1()
{
  //инициал ENA команд
  return commonInitENACmd(ENACMD_MTZ1_TOTAL);
}//initENACmd_MTZ1()

void initTimersMTZ1(short idxC)
{
  //запрос и инициал таймеров
  commonInitTimers(TIMERS_MTZ1_TOTAL);//должен быть первым!
}//initTimersMTZ1()

int codecUstMTZ1(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
int grzHI = 0;//верх граница
int grzLOW= 0;//низ граница
int step  = 1;//шаг
  switch(offset)
  {
   //уставки
   case MNGUST_MTZ1:
   case MNGUST_MTZ1_V:
   case MNGUST_MTZ1_N:
   case MNGUST_MTZ1_PN:
   case MNGUST_MTZ1_UPN:
       grzHI = 1000000;//верх граница
       grzLOW= 0;//низ граница
       step  = 1;//шаг
   break;

  //выдержки
//   case MNGUST_BOBV_MTZ1://уставка БО БВ
   case MNGVID_MTZ1:
   case MNGVID_MTZ1_V:
   case MNGVID_MTZ1_N:
   case MNGVID_MTZ1_PN:
       grzHI = 2000000;//верх граница
       grzLOW= 0;//низ граница
       step  = 1;//шаг
   break;

   default:return ust;//уставка управления
  }//switch

//  if((MNGUPR_MTZ1)==offset)
//    return ust;//уставка управления
  if(codec) return ust*step;
//раскодировать уставку
  if(ust<grzLOW) return ERROR_UST;//-ust;
  if(ust>grzHI)  return ERROR_UST;//-ust;
  return ust/step;
}//codecUstMTZ1(char *buf, short offset, int ust)

int isDISactiv_MTZ1(int idxC)
{
 //таймерная активность Регистратора ДИС
    int tmpOffsetT    =
                cnfCOMPONENT[idxC].offsetTimers;   //таймера компонента в конфигурации
    for(int i=0; i<TIMERS_MTZ1_TOTAL; i++)
    {
      if(getTimerBUSY(tmpOffsetT+i) |
         getTimerFINISH(tmpOffsetT+i)
         )
         return 1;//есть активность
    }//
  return 0;//нет активности
}//isDISactiv_MTZ1(int idxC)

void SaveUprMTZ(short ibit)
{
  /*
//персональное сохр upr для MTZ
  UNS_32 tmpU = getCurrentMngUSTAVKI();//текущая уст упр
    //Управление МТЗ
    if(ibit<1)
    {
      if(FvmenuDis->Choose1MTZButton->Checked)
      {
        NumBitClearingWord(ibit,   &tmpU);//сброс бита по его индексу
        NumBitClearingWord(ibit+1, &tmpU);//сброс бита по его индексу
      }//if
      if(FvmenuDis->Choose2MTZButton->Checked)
      {
        NumBitSettingWord(ibit,    &tmpU);//сброс бита по его индексу
        NumBitClearingWord(ibit+1, &tmpU);//сброс бита по его индексу
      }//if
      if(FvmenuDis->Choose3MTZButton->Checked)
      {
        NumBitClearingWord(ibit, &tmpU);//сброс бита по его индексу
        NumBitSettingWord(ibit+1,    &tmpU);//сброс бита по его индексу
      }//if
      if(FvmenuDis->Choose4MTZButton->Checked)
      {
        NumBitSettingWord(ibit, &tmpU);//сброс бита по его индексу
        NumBitSettingWord(ibit+1,    &tmpU);//сброс бита по его индексу
      }//if
    }//
    else
    {
      if(FvmenuDis->UprCheck->Checked)
      {
        NumBitSettingWord(ibit+1, &tmpU);//установка бита по его индексу
      }//if(FvmenuDis->UprCheck->Checked)
      else
      {
        NumBitClearingWord(ibit+1, &tmpU);//сброс бита по его индексу
      }
    }
  setCurrentMngUSTAVKI(tmpU);//новая уст упр
  */
}//SaveUprMTZ()

char copyMTZ1ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое
//копировать компонент в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.packet = 0;    //номер пакетного компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  MTZ1_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_MTZ1;//меню компонента

  rpzcomponent_obj.cntClon     = CNT_STUPEN_MTZ;   //max к-во клонов
  rpzcomponent_obj.numClon     = 1;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstMTZ1;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstMTZ1;//подготовка уставок
  rpzcomponent_obj.initIOCmd      = initIOCmd_MTZ1;      //инициал IO команд
  rpzcomponent_obj.initTLCmd      = initTLCmd_MTZ1;      //инициал TL команд
  rpzcomponent_obj.initENACmd     = initENACmd_MTZ1;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_MTZ1; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsMTZ1;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersMTZ1;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicMTZ1;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstMTZ1;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

