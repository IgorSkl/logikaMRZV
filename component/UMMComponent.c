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

//#include "component\componentdef.h"
//#include "virtualMenu\systemmenudef.h"
//#include "virtualMenu\ustmanagerdef.h"

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
#define KOD_COMPONENT  UMM_COMP1
//к-во ступеней
#define CNT_STUPEN_UMM  1

#endif // _HIDE_COMPONENT

//РАСПРЕДЕЛЕНИЕ УСТАВОК  в менеджере уставок
//уставка сработки UMAX1
#define MNGUST_UMAX1_UMM    0
//уставка сработки UMAX2
#define MNGUST_UMAX2_UMM    1
//уставка сработки UMIN1
#define MNGUST_UMIN1_UMM    2
//уставка I блок IMIN1
#define MNGUST_IMIN1_UMM    3
//уставка сработки UMIN2
#define MNGUST_UMIN2_UMM    4
//уставка I блок IMIN2
#define MNGUST_IMIN2_UMM    5

//уставка выдержки
//Время UMAX1
#define MNGVID1_UMM    6
//Время UMAX2
#define MNGVID2_UMM    7
//Время UMIN1
#define MNGVID3_UMM    8
//Время UMIN2
#define MNGVID4_UMM    9

//уставка управления
#define MNGUPR_UMM    10
//к-во уставок в менеджере уставок
#define MNGUST_UMM_TOTAL  11
#define MNGUST_BOBV_UMM  MNGUST_UMM_TOTAL

//РАСПРЕДЕЛЕНИЕ ENA КОМАНД
//Управл UMAX1
#define ENA_UMAX1_1      0
// UMAX1 И ИЛИ
#define ENA_UMAX1_2      1
// UMAX1 ФАЗ ЛИН
#define ENA_UMAX1_3      2

//Управл UMAX2
#define ENA_UMAX2_1      3
// UMAX2 И ИЛИ
#define ENA_UMAX2_2      4
// UMAX2 ФАЗ ЛИН
#define ENA_UMAX2_3      5

//Управл UMIN1
#define ENA_UMIN1_1      6
// UMINX1 И ИЛИ
#define ENA_UMIN1_2      7
// UMIN1 ФАЗ ЛИН
#define ENA_UMIN1_3      8
// UMIN1 блок I
#define ENA_UMIN1_4      9

//Управл UMIN2
#define ENA_UMIN2_1      10
// UMINX2 И ИЛИ
#define ENA_UMIN2_2      11
// UMIN2 ФАЗ ЛИН
#define ENA_UMIN2_3      12
// UMIN2 блок I
#define ENA_UMIN2_4      13

// UMIN1 блок U
#define ENA_UMIN1_5      14
// UMIN2 блок U
#define ENA_UMIN2_5      15

//к-во ENA команд UMM
#define ENACMD_UMM_TOTAL 16

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//уставка сработки U
#define SPVSRABUST_UMAX1_UMM    0
#define SPVSRABUST_UMAX2_UMM    1
#define SPVSRABUST_UMIN1_UMM    2
#define SPVSRABUST_IMIN1_UMM    3
#define SPVSRABUST_UMIN2_UMM    4
#define SPVSRABUST_IMIN2_UMM    5
//уставка возврата U
#define SPVVOZVUST_UMAX1_UMM    6
#define SPVVOZVUST_UMAX2_UMM    7
#define SPVVOZVUST_UMIN1_UMM    8
#define SPVVOZVUST_IMIN1_UMM    9
#define SPVVOZVUST_UMIN2_UMM    10
#define SPVVOZVUST_IMIN2_UMM    11
//уставка сработки I BLOK
#define SPVSRABUST_IBLOK1_UMM   12
#define SPVSRABUST_IBLOK2_UMM   13
//уставка возврата I BLOK
#define SPVVOZVUST_IBLOK1_UMM   14
#define SPVVOZVUST_IBLOK2_UMM   15
//уставка SPV выход UMAX1
#define SPV_OUTAL_UMAX1         16
#define SPV_OUTBL_UMAX1         17
#define SPV_OUTCL_UMAX1         18
#define SPV_OUTAF_UMAX1         19
#define SPV_OUTBF_UMAX1         20
#define SPV_OUTCF_UMAX1         21
//уставка SPV выход UMAX2
#define SPV_OUTAL_UMAX2         22
#define SPV_OUTBL_UMAX2         23
#define SPV_OUTCL_UMAX2         24
#define SPV_OUTAF_UMAX2         25
#define SPV_OUTBF_UMAX2         26
#define SPV_OUTCF_UMAX2         27
//уставка SPV выход UMIN1
#define SPV_OUTAL_UMIN1         28
#define SPV_OUTBL_UMIN1         29
#define SPV_OUTCL_UMIN1         30
#define SPV_OUTAF_UMIN1         31
#define SPV_OUTBF_UMIN1         32
#define SPV_OUTCF_UMIN1         33
//уставка SPV выход UMIN2
#define SPV_OUTAL_UMIN2         34
#define SPV_OUTBL_UMIN2         35
#define SPV_OUTCL_UMIN2         36
#define SPV_OUTAF_UMIN2         37
#define SPV_OUTBF_UMIN2         38
#define SPV_OUTCF_UMIN2         39
//уставка SPV выход IBLOK1
#define SPV_OUTIA_UMIN1         40
#define SPV_OUTIB_UMIN1         41
#define SPV_OUTIC_UMIN1         42
//уставка SPV выход IBLOK2
#define SPV_OUTIA_UMIN2         43
#define SPV_OUTIB_UMIN2         44
#define SPV_OUTIC_UMIN2         45
//к-во уставок в супервизоре
#define SPVUST_UMM_TOTAL  46

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ APV
//Стат блок UMAX1
#define IOCMD1_UMM 0
//Стат блок UMAX2
#define IOCMD2_UMM 1
//Стат блок UMIN1
#define IOCMD3_UMM 2
//Стат блок UMIN2
#define IOCMD4_UMM 3
//ПО UMAX1
#define IOCMD5_UMM 4
//Сраб UMAX1
#define IOCMD6_UMM 5
//ПО UMAX2
#define IOCMD7_UMM 6
//Сраб UMAX2
#define IOCMD8_UMM 7
//ПО UMIN1
#define IOCMD9_UMM 8
//Сраб UMIN1
#define IOCMD10_UMM 9
//ПО UMIN2
#define IOCMD11_UMM 10
//Сраб UMIN2
#define IOCMD12_UMM 11
//Пуск UMIN1
#define IOCMDPUSK1_UMM 12
//Пуск UMIN2
#define IOCMDPUSK2_UMM 13
//к-во IO команд
#define IOCMD_UMM_TOTAL    14

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ UMM
//к-во TL команд
#define TLCMD_UMM_TOTAL    0

//--------------- TIMERS ------------------
//РАСПРЕДЕЛЕНИЕ ТАЙМЕРОВ ДЛЯ UMM
//таймер UMIN1_TIM1
#define TIMER1_UMM     0
//таймер UMIN2_TIM1
#define TIMER2_UMM     1
//таймер BO UMIN1
#define TIMER_BOUMIN1  2
//таймер BO UMIN2
#define TIMER_BOUMIN2  3
//таймер UMAX1_TIM1
#define TIMER3_UMM     4
//таймер UMAX2_TIM1
#define TIMER4_UMM     5
//таймер BO UMAX1
#define TIMER_BOUMAX1  6
//таймер BO UMAX2
#define TIMER_BOUMAX2  7
//к-во таймеров
#define TIMERS_UMM_TOTAL   8

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация
extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];
extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexIO;//индекс IO
extern int  IndexUstSPV;//индекс уставок в супервизоре
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//смещение на уставки PRM1

void UstListCompUMM();
void ustRedactorCompUMM();
void UstCompUMM();
void  logicUMM(int idxC);

void PereinitVidListCompUMM(short flg);
void VidListCompUMM();
void vidRedactorCompUMM();
void VidCompUMM();

void PereinitUprListCompUMM(short flg);
void UprListCompUMM();
void uprRedactorCompUMM();
void UprCompUMM();
short  KadrMenuFormat_upr_compUMM(void *workCntr);
short  KadrMenuFormat_ustvidUMM(void *workCntr);
int   initUstUMM(char init);
void  prepareUstUMM(short idxC);
char *selectorUprStrUMM(short iBit, UNS_32 ustUpr);

void EditUstUMM();
void EditVidUMM();
void EditUprUMM();
int codecUstUMM(char codec, short offset, int ust);

int   isDISactiv_UMM(int idxC);

int  offsetIOCmdUMM;//смещение для IO UMM

char UMM_TITLE[] = "ЗН";

IONAMESTATUS_COMPONENT ionsUMM[IOCMD_UMM_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок UMAX1"
  },
  {
    1,//статус iocmd2
    "Стат блок UMAX2"
  },
  {
    1,//статус iocmd3
    "Стат блок UMIN1"
  },
  {
    1,//статус iocmd4
    "Стат блок UMIN2"
  },
  {
    1,//статус iocmd5
    "Сраб ПО UMAX1"
  },
  {
    1,//статус iocmd6
    "Сраб UMAX1"
  },
  {
    1,//статус iocmd7
    "Сраб ПО UMAX2"
  },
  {
    1,//статус iocmd8
    "Сраб UMAX2"
  },
  {
    1,//статус iocmd9
    "Сраб ПО UMIN1"
  },
  {
    1,//статус iocmd10
    "Сраб UMIN1"
  },
  {
    1,//статус iocmd11
    "Сраб ПО UMIN2"
  },
  {
    1,//статус iocmd12
    "Сраб UMIN2"
  },
  {
    1,//статус iocmd13
    "Пуск UMIN1"
  },
  {
    1,//статус iocmd14
    "Пуск UMIN2"
  }
};

LineMenuItem sub_menu_comp_UMM[8] =
{
  { UMM_TITLE, NULL},//title
  { &CONTROL1_COMP,   &sub_menu_cnf,   typeMenuSub},//control_item, parent
  { "Уставки ЗН",     (void *)&UstListCompUMM, typeMenuProg},
  { "Выдержки ЗН",    (void *)&VidListCompUMM, typeMenuProg},
  { "Управление ЗН",  (void *)&UprListCompUMM, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compUMM[] =
{
  { "Уставки ЗН", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_UMM, typeMenuList},//control_item, parent
  { "Напр UMAX1",        (void *)&UstCompUMM, typeMenuProg},
  { "Напр UMAX2",        (void *)&UstCompUMM, typeMenuProg},
  { "Напр UMIN1",        (void *)&UstCompUMM, typeMenuProg},
  { "Ток блок UMIN1",    (void *)&UstCompUMM, typeMenuProg},
  { "Напр UMIN2",        (void *)&UstCompUMM, typeMenuProg},
  { "Ток блок UMIN2",    (void *)&UstCompUMM, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compUMM[] =
{
  { "Выдержки ЗН", NULL},//title
  { &CONTROL2_COMP,     &sub_menu_comp_UMM, typeMenuList},//control_item, parent
  { "Время UMAX1",      (void *)&VidCompUMM, typeMenuProg},
  { "Время UMAX2",      (void *)&VidCompUMM, typeMenuProg},
  { "Время UMIN1",      (void *)&VidCompUMM, typeMenuProg},
  { "Время UMIN2",      (void *)&VidCompUMM, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compUMM[] =
{
  { "Управл ЗН", NULL},//title
  { &CONTROL2_COMP,   &sub_menu_comp_UMM, typeMenuList},//control_item, parent
/*
  { "Управл UMAX1",   (void *)&UprCompUMM, typeMenuProg},
  { "Логика UMAX1",   (void *)&UprCompUMM, typeMenuProg},
  { "Выбор UMAX1",    (void *)&UprCompUMM, typeMenuProg},
  { "Управл UMAX2",   (void *)&UprCompUMM, typeMenuProg},
  { "Логика UMAX2",   (void *)&UprCompUMM, typeMenuProg},
  { "Выбор UMAX2",    (void *)&UprCompUMM, typeMenuProg},
  { "Управл UMIN1",   (void *)&UprCompUMM, typeMenuProg},
  { "Логика UMIN1",   (void *)&UprCompUMM, typeMenuProg},
  { "Выбор UMIN1",    (void *)&UprCompUMM, typeMenuProg},
  { "Ток Блок UMIN1", (void *)&UprCompUMM, typeMenuProg},
  { "Управл UMIN2",   (void *)&UprCompUMM, typeMenuProg},
  { "Логика UMIN2",   (void *)&UprCompUMM, typeMenuProg},
  { "Выбор UMIN2",    (void *)&UprCompUMM, typeMenuProg},
  { "Ток Блок UMIN2", (void *)&UprCompUMM, typeMenuProg},
  { "Напр Блок UMIN1",(void *)&UprCompUMM, typeMenuProg},
  { "Напр Блок UMIN2",(void *)&UprCompUMM, typeMenuProg},
*/
  { NULL, NULL}

};

void PereinitUstListCompUMM(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidUMM, sub_menu_ust_compUMM);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UstListCompUMM()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compUMM);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompUMM);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompUMM()

void UstCompUMM()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compUMM);
  PassWord(EditUstUMM);
}//VidCompUMM()

void EditUstUMM()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compUMM);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompUMM()

short  KadrMenuFormat_ustvidUMM(void *pstr)
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

void PereinitVidListCompUMM(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidUMM, sub_menu_vid_compUMM);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void VidListCompUMM()
{
  SelectorMNGBAZA(MNGVID1_UMM);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compUMM);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompUMM);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompUMM()

void VidCompUMM()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compUMM);
//  PassWord(EditVidAPV);
  EditVidUMM();
}//VidCompUMM()

void EditVidUMM()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compUMM);
}//

//--------------------------------------------------

void PereinitUprListCompUMM(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compUMM, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstList

void UprListCompUMM()
{
  SelectorMNGBAZA(MNGUPR_UMM);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compUMM);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompUMM);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompUMM()

void UprCompUMM()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compUMM);
  PassWord(EditUprUMM);

}//UprCompUMM()

void EditUprUMM()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compUMM[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrUMM);//редактировать уставку управления
}//EditUprUMM()

short  KadrMenuFormat_upr_compUMM(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compUMM[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrUMM(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compUMM(WorkControl *workCntr)

char *selectorUprStrUMM(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {
  case 1:
  case 4:
  case 7:
  case 11:
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_ILI];
    return bitStringUNI[UNIUPR_I];

  case 2:
  case 5:
  case 8:
  case 12:
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_LIN];
    return bitStringUNI[UNIUPR_FAZ];

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
}//selectorUprStrUMM(short ibit, UNS_32 ustUpr)

int initUstUMM(char init)
{
  //инициал уставок
  if (init)
  {
//уставка сработки
	//уставка сработки UMAX1
    tmpUSTAVKI[MNGUST_UMAX1_UMM] = 10;
	//уставка сработки UMAX2
    tmpUSTAVKI[MNGUST_UMAX2_UMM] = 11;
	//уставка сработки UMIN1
    tmpUSTAVKI[MNGUST_UMIN1_UMM] = 12;
	//уставка блок IMIN1
    tmpUSTAVKI[MNGUST_IMIN1_UMM] = 13;
	//уставка сработки UMIN2
    tmpUSTAVKI[MNGUST_UMIN2_UMM] = 14;
	//уставка блок IMIN2
    tmpUSTAVKI[MNGUST_IMIN2_UMM] = 15;
//уставка выдержки
	//Время UMAX1
    tmpUSTAVKI[MNGVID1_UMM] = 20;
	//Время UMAX2
    tmpUSTAVKI[MNGVID2_UMM] = 21;
	//Время UMIN1
    tmpUSTAVKI[MNGVID3_UMM] = 22;
	//Время UMIN2
    tmpUSTAVKI[MNGVID4_UMM] = 23;
//уставка управления
    tmpUSTAVKI[MNGUPR_UMM]  = 0;

  }//if

  IndexUstSPV += SPVUST_UMM_TOTAL;//индекс уставок в супервизоре
  return MNGUST_UMM_TOTAL;//к-во уставок в менеджере уставок
}//initUstUMM(short mngUst, char init)

void  prepareUstUMM(short idxC)
{
  //подготовка ENA команд для клона
  //копировать ENA из WideENA в ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_UMM), ENACMD_UMM_TOTAL);
  //подготовка уставок
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//смещение уставок внутри супервизора

    //UMAX
    //уставка SPV сработки
    int tmp1 = 
    SPV_UST(SPVSRABUST_UMAX1_UMM) = codecUstUMM(1, MNGUST_UMAX1_UMM, getNativUstMngUSTAVKI(idxC, MNGUST_UMAX1_UMM));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_UMAX1_UMM) = tmp1 - tmp1/20;//5%
    //уставка SPV сработки
    tmp1 = 
    SPV_UST(SPVSRABUST_UMAX2_UMM) = codecUstUMM(1, MNGUST_UMAX2_UMM, getNativUstMngUSTAVKI(idxC, MNGUST_UMAX2_UMM));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_UMAX2_UMM) = tmp1 - tmp1/20;//5%

    //UMIN
    //уставка SPV сработки
    tmp1 = 
    SPV_UST(SPVSRABUST_UMIN1_UMM) = codecUstUMM(1, MNGUST_UMIN1_UMM, getNativUstMngUSTAVKI(idxC, MNGUST_UMIN1_UMM));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_UMIN1_UMM) = tmp1 + tmp1/20;//5%
    //уставка SPV сработки
    tmp1 =
    SPV_UST(SPVSRABUST_UMIN2_UMM) = codecUstUMM(1, MNGUST_UMIN2_UMM, getNativUstMngUSTAVKI(idxC, MNGUST_UMIN2_UMM));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_UMIN2_UMM) = tmp1 + tmp1/20;//5%

        //I Блокир UMM1
    tmp1 =
    SPV_UST(SPVSRABUST_IBLOK1_UMM) = codecUstUMM(1, MNGUST_IMIN1_UMM, getNativUstMngUSTAVKI(idxC, MNGUST_IMIN1_UMM));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_IBLOK1_UMM) = tmp1 - tmp1/20;//5%
    //I Блокир UMM2
    tmp1 =
    SPV_UST(SPVSRABUST_IBLOK2_UMM) = codecUstUMM(1, MNGUST_IMIN2_UMM, getNativUstMngUSTAVKI(idxC, MNGUST_IMIN2_UMM));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_IBLOK2_UMM) = tmp1 - tmp1/20;//5%

  //подготовка выдержек
  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //компонент в конфигурации

	//таймер UMIN1_TIM1
   setTimerPorog(tmpOffsetT+ TIMER1_UMM,
          codecUstUMM(1, MNGVID3_UMM, getNativUstMngUSTAVKI(idxC, MNGVID3_UMM)));
	//таймер UMIN2_TIM1
   setTimerPorog(tmpOffsetT+ TIMER2_UMM,
          codecUstUMM(1, MNGVID4_UMM, getNativUstMngUSTAVKI(idxC, MNGVID4_UMM)));
	//таймер BO UMIN1
   setTimerPorog(tmpOffsetT+ TIMER_BOUMIN1, 9);
	//таймер BO UMIN2
   setTimerPorog(tmpOffsetT+ TIMER_BOUMIN2, 9);
	//таймер UMAX1_TIM1
   setTimerPorog(tmpOffsetT+ TIMER3_UMM,
          codecUstUMM(1, MNGVID1_UMM, getNativUstMngUSTAVKI(idxC, MNGVID1_UMM)));
	//таймер UMAX2_TIM1
   setTimerPorog(tmpOffsetT+ TIMER4_UMM,
          codecUstUMM(1, MNGVID2_UMM, getNativUstMngUSTAVKI(idxC, MNGVID2_UMM)));
	//таймер BO UMAX1
   setTimerPorog(tmpOffsetT+ TIMER_BOUMAX1, 9);
	//таймер BO UMAX2
   setTimerPorog(tmpOffsetT+ TIMER_BOUMAX2, 9);

}//prepareUstUMM(short idxC)

int initIOCmd_UMM()
{
  //инициал IO команд
  offsetIOCmdUMM = IndexIO;//смещение для IO UMM
  return commonInitIOCmd(IOCMD_UMM_TOTAL);
}//initIOCmd_APV()

int initTLCmd_UMM()
{
  //инициал TL команд
  return commonInitTLCmd(TLCMD_UMM_TOTAL);
}//initTLCmd_UMM()

int initENACmd_UMM()
{
  //инициал ENA команд
  return commonInitENACmd(ENACMD_UMM_TOTAL);
}//initENACmd_UMM()

void initTimersUMM(short idxC)
{
  //запрос и инициал таймеров
  commonInitTimers(TIMERS_UMM_TOTAL);
}//initTimersUMM()

int codecUstUMM(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  if(codec) return ust*1;
  return ust/1;
}//codecUstUMM(char *buf, short offset, int ust)

int isDISactiv_UMM(int idxC)
{
 //активность Регистратора ДИС
//    int tmpOffsetT    =
  //              cnfCOMPONENT[idxC].offsetTimers;   //таймера компонента в конфигурации
  return 0;//нет активности
}//isDISactiv_UMM(int idxC)

char copyUMMToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое

//копировать компонент в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.packet = 0;    //номер пакетного компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  UMM_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_UMM;//меню компонента

  rpzcomponent_obj.cntClon      = CNT_STUPEN_UMM;   //max к-во клонов
  rpzcomponent_obj.numClon      = 1;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstUMM;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstUMM;//подготовка уставок
  rpzcomponent_obj.initIOCmd      = initIOCmd_UMM;      //инициал IO команд
  rpzcomponent_obj.initTLCmd      = initTLCmd_UMM;      //инициал TL команд
  rpzcomponent_obj.initENACmd     = initENACmd_UMM;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_UMM; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsUMM;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersUMM;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicUMM;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstUMM;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

