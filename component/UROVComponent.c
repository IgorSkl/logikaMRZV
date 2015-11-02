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
#include "psuperVisor\psvisor_helpdef.h"

#include "virtualMenu\viewMenuList.h"

#include "psupervisor\psupervisor.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"


//код компонентов
#define KOD_COMPONENT  UROV_COMP1
//к-во ступеней
#define CNT_STUPEN_UROV  1

#endif // _HIDE_COMPONENT

//РАСПРЕДЕЛЕНИЕ УСТАВОК  в менеджере уставок
//уставка сработки
#define MNGUST_UROV    0

//уставка выдержки
//1 ступень УРОВ
#define MNGVID_UROV1   1
//2 ступень УРОВ
#define MNGVID_UROV2   2

//уставка управления
#define MNGUPR_UROV    3
//к-во уставок в менеджере уставок
#define MNGUST_UROV_TOTAL  4

//РАСПРЕДЕЛЕНИЕ ENA команд
//Управл УРОВ
#define ENA_UROV_1  0
//к-во ENA команд
#define ENACMD_UROV_TOTAL 1

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//уставка сработки
#define SPVSRABUST_UROV    0
//уставка возврата
#define SPVVOZVUST_UROV    1
//уставка SPV выход ROV
#define SPV_OUTA_UROV      2
#define SPV_OUTB_UROV      3
#define SPV_OUTC_UROV      4
//к-во уставок в супервизоре
#define SPVUST_UROV_TOTAL  5

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ UROV
//Стат блок УРОВ
#define IOCMD1_UROV 0
//Пуск УРОВ
#define IOCMD2_UROV 1
//Сраб УРОВ1
#define IOCMD3_UROV 2
//Сраб УРОВ2
#define IOCMD4_UROV 3
//к-во IO команд
#define IOCMD_UROV_TOTAL    4

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ UROV
//PO_UROV
#define TLCMD2_UROV 0
//ELOLDTRG_UROV
#define TLCMD3_UROV 1
//ELOUTTRG_UROV
#define TLCMD4_UROV 2
//к-во TL команд
#define TLCMD_UROV_TOTAL    3

//--------------- TIMERS ------------------
//РАСПРЕДЕЛЕНИЕ ТАЙМЕРОВ ДЛЯ UROV
//таймер UROV_TIM1
#define TIMER1_UROV    0
//таймер BO UROV_TIM1
#define TIMER1_BOUROV1 1
//таймер UROV_TIM2
#define TIMER2_UROV    2
//таймер BO UROV_TIM2
#define TIMER2_BOUROV2 3
//к-во таймеров
#define TIMERS_UROV_TOTAL   4

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
//#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре
extern int  IndexIO;//индекс IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//смещение на уставки PRM1
extern int  spvUSTAVKI[];//текущие уставки супервизора

void UstListCompUROV();
void ustRedactorCompUROV();
void UstCompUROV();
short  KadrMenuFormat_ust_compUROV(void *workCntr);//(WorkControl *workCntr);

void PereinitVidListCompUROV(short flg);
void VidListCompUROV();
void vidRedactorCompUROV();
void VidCompUROV();
short  KadrMenuFormat_vid_compUROV(void *workCntr);//(WorkControl *workCntr);

void PereinitUprListCompUROV(short flg);
void UprListCompUROV();
void uprRedactorCompUROV();
void UprCompUROV();
short  KadrMenuFormat_upr_compUROV(void *workCntr);//(WorkControl *workCntr);
int  initUstUROV(char init);
void  prepareUstUROV(short idxC);
char *selectorUprStrUROV(short iBit, UNS_32 ustUpr);

short  KadrMenuFormat_UROV(void *workCntr);//(WorkControl *workCntr);

void EditUstUROV();
void EditVidUROV();
void EditUprUROV();
int codecUstUROV(char codec, short offset, int ust);
void  logicUROV(int idxC);
int isDISactiv_UROV(int idxC);

int  offsetIOCmdUROV;//смещение для IO UROV

char UROV_TITLE[] = "УРОВ";

IONAMESTATUS_COMPONENT ionsUROV[IOCMD_UROV_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок УРОВ"
  },
  {
    1,//статус iocmd2
    "Пуск УРОВ"
  },
  {
    1,//статус iocmd3
    "Сраб УРОВ1"
  },
  {
    1,//статус iocmd4
    "Сраб УРОВ2"
  }
};

LineMenuItem sub_menu_comp_UROV[8] =
{
  { UROV_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_cnf, typeMenuSub},//control_item, parent
  { "Уставки УРОВ",    (void*)&UstListCompUROV, typeMenuProg},
  { "Выдержки УРОВ",   (void*)&VidListCompUROV, typeMenuProg},
  { "Управление УРОВ", (void*)&UprListCompUROV, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compUROV[] =
{
  { "Уставки УРОВ", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_UROV, typeMenuList},//control_item, parent
  { "Уст тока УРОВ",        (void*)&UstCompUROV, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compUROV[] =
{
  { "Выдержки УРОВ", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_UROV, typeMenuList},//control_item, parent
  { "Выдержка УРОВ1",  (void*)&VidCompUROV, typeMenuProg},
  { "Выдержка УРОВ2",  (void*)&VidCompUROV, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compUROV[] =
{
  { "Управл УРОВ", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_UROV, typeMenuList},//control_item, parent
  { "Управл УРОВ",      (void*)&UprCompUROV, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompUROV(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ust_compUROV, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()
/*
void UstListCompUROV()
{
  LIGHTMNGUBAZA = 0;

  CRR_SUBMENU = sub_menu_ust_compUROV;//текущее субменю

  CRR_TEXTSTREAM = &CONTROL2_COMP;//текущий control
  CRR_FHOME = &PereinitUstListCompUROV;//указатель на ф-цию HOME

  CRR_FHOME(1);//переиниц
  LanderUpDown();//wkl Up Down
}//UstListCompUROV()

void UstCompUROV()
{
  ViewToEditUst(ViewerEditUstUROV);
}//VidCompUROV()

int ViewerEditUstUROV()
{
//редактировать уставку
  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);

  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_ust_compUROV;// parent

  ViewerEditorUst(sub_menu_ust_compUROV[LIGHTLINEMENU +1+SUBDATA].Line1);//редактировать уставку

  return getCurrentMngUSTAVKI();
}//UstCompUROV()
*/
void UstListCompUROV()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compUROV);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompUROV);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompUROV()

void UstCompUROV()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compUROV);
  PassWord(EditUstUROV);
}//VidCompUROV()

void EditUstUROV()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compUROV);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompUROV()

short  KadrMenuFormat_ust_compUROV(void *pstr)//(WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  char locTxt[50];
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
    if(sub_menu_ust_compUROV[i+1+SUBDATA].Line1==NULL)break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, (char *)sub_menu_ust_compUROV[i+1+SUBDATA].Line1);
      sprintf(locTxt, "   %d", getUstOffsetMngUSTAVKI(i));
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
      return 1;
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat

//--------------------------------------------------

void PereinitVidListCompUROV(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_vid_compUROV, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

/*
void VidListCompUROV()
{
  LIGHTMNGUBAZA = MNGVID_UROV1;

  CRR_SUBMENU = sub_menu_vid_compUROV;//текущее субменю

  CRR_TEXTSTREAM = &CONTROL2_COMP;//текущий control
  CRR_FHOME = &PereinitVidListCompUROV;//указатель на ф-цию HOME

  CRR_FHOME(1);//переиниц
  LanderUpDown();//wkl Up Down
}//VidListCompUROV()

void VidCompUROV()
{
  ViewToEditUst(ViewerEditVidUROV);
}//VidCompUROV()

int ViewerEditVidUROV()
{
//редактировать уставку
  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);

  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_vid_compUROV;// parent

  ViewerEditorUst(sub_menu_vid_compUROV[LIGHTLINEMENU +1+SUBDATA].Line1);//редактировать уставку

  return getCurrentMngUSTAVKI();
}//
*/
void VidListCompUROV()
{
  SelectorMNGBAZA(MNGVID_UROV1);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compUROV);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompUROV);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompUROV()

void VidCompUROV()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compUROV);
//  PassWord(EditVidAPV);
  EditVidUROV();
}//VidCompUROV()

void EditVidUROV()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compUROV);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

short  KadrMenuFormat_vid_compUROV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  char locTxt[50];
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
    if(sub_menu_vid_compUROV[i+1+SUBDATA].Line1==NULL)break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, (char *)sub_menu_vid_compUROV[i+1+SUBDATA].Line1);
      sprintf(locTxt, "   %d", getUstOffsetMngUSTAVKI(i));
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
      return 1;
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat_vid_compUROV(WorkControl *workCntr)

//--------------------------------------------------

void PereinitUprListCompUROV(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compUROV, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstList
/*
void UprListCompUROV()
{
  LIGHTMNGUBAZA = MNGUPR_UROV;

  CRR_SUBMENU = sub_menu_upr_compUROV;//текущее субменю

  CRR_TEXTSTREAM = &CONTROL2_COMP;//текущий control
  CRR_FHOME = &PereinitUprListCompUROV;//указатель на ф-цию HOME

  CRR_FHOME(1);//переиниц
  LanderUpDown();//wkl Up Down
}//VidListCompUROV()

void UprCompUROV()
{
  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);
//редактировать уставку управления
  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_upr_compUROV;// parent
  char *nameUpr = (char *)sub_menu_upr_compUROV[LIGHTLINEMENU +1+SUBDATA].Line1;

  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrUROV);//редактировать уставку управления

}//UprCompMTZ1()
*/
void UprListCompUROV()
{
  SelectorMNGBAZA(MNGUPR_UROV);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compUROV);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompUROV);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompUROV()

void UprCompUROV()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compUROV);
  PassWord(EditUprUROV);

}//UprCompUROV()

void EditUprUROV()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compUROV[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrUROV);//редактировать уставку управления
}//EditUprUROV()

short  KadrMenuFormat_upr_compUROV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
    char *nameUpr = (char *)sub_menu_upr_compUROV[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrUROV(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compUROV(WorkControl *workCntr)

char *selectorUprStrUROV(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
}//selectorUprStrUROV(short ibit, UNS_32 ustUpr)

int initUstUROV(char init)
{
  //инициал уставок
  if (init)
  {
//уставка сработки
    tmpUSTAVKI[MNGUST_UROV] = 10;
//уставка выдержки
    tmpUSTAVKI[MNGVID_UROV1] = 50;
    tmpUSTAVKI[MNGVID_UROV2] = 60;
//уставка управления
    tmpUSTAVKI[MNGUPR_UROV] = 0;

  }//if

  IndexUstSPV += SPVUST_UROV_TOTAL;//индекс уставок в супервизоре
  return MNGUST_UROV_TOTAL;//к-во уставок в менеджере уставок
}//initUstMTZ1(short mngUst, char init)

void  prepareUstUROV(short idxC)
{
  //подготовка ENA команд для клона
  //копировать ENA из WideENA в ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_UROV), ENACMD_UROV_TOTAL);
  //подготовка уставок
    int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//смещение уставок внутри супервизора

    //уставка SPV сработки
  int tmp1 = 
  SPV_UST(SPVSRABUST_UROV) = codecUstUROV(1, MNGUST_UROV, getNativUstMngUSTAVKI(idxC, MNGUST_UROV));
  //уставка SPV возврата
  SPV_UST(SPVVOZVUST_UROV) = tmp1 - tmp1/20;//5%

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //компонент в конфигурации
      //1 ступень УРОВ
  setTimerPorog(tmpOffsetT+ TIMER1_UROV,
          codecUstUROV(1, MNGVID_UROV1, getNativUstMngUSTAVKI(idxC, MNGVID_UROV1)));
//таймер BO UROV_TIM1
  setTimerPorog(tmpOffsetT+ TIMER1_BOUROV1, 10);

     //2 ступень УРОВ
  setTimerPorog(tmpOffsetT+ TIMER2_UROV,
          codecUstUROV(1, MNGVID_UROV2, getNativUstMngUSTAVKI(idxC, MNGVID_UROV2)));
//таймер BO UROV_TIM1
  setTimerPorog(tmpOffsetT+ TIMER2_BOUROV2 ,10);
}//prepareUstMTZ1(short idxC)

int initIOCmd_UROV()
{
  //инициал IO команд
  offsetIOCmdUROV = IndexIO;//смещение для IO UROV
  return commonInitIOCmd(IOCMD_UROV_TOTAL);
}//initIOCmd_UROV()

int initTLCmd_UROV()
{
  //инициал TL команд
  return commonInitTLCmd(TLCMD_UROV_TOTAL);
}//initTLCmd_UROV()

int initENACmd_UROV()
{
  //инициал ENA команд
  return commonInitENACmd(ENACMD_UROV_TOTAL);
}//initENACmd_UROV()

void initTimersUROV(short idxC)
{
  //запрос и инициал таймеров
  commonInitTimers(TIMERS_UROV_TOTAL);
}//initTimersUROV()

int codecUstUROV(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  if(codec) return ust*1;
  return ust/1;
}//codecUstUROV(char *buf, short offset, int ust)

int isDISactiv_UROV(int idxC)
{
 //активность Регистратора ДИС
  return 0;//нет активности
}//isDISactiv_UROV(int idxC)

char copyUROVToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое
//копировать компонент в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.packet = 0;    //номер пакетного компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  UROV_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_UROV;//меню компонента

  rpzcomponent_obj.cntClon     = CNT_STUPEN_UROV;   //max к-во клонов
  rpzcomponent_obj.numClon     = 1;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstUROV;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstUROV;//подготовка уставок
  rpzcomponent_obj.initIOCmd      = initIOCmd_UROV;      //инициал IO команд
  rpzcomponent_obj.initTLCmd      = initTLCmd_UROV;      //инициал TL команд
  rpzcomponent_obj.initENACmd     = initENACmd_UROV;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_UROV; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsUROV;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersUROV;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicUROV;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstUROV;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

