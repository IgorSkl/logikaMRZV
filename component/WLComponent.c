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
#include "virtualMenu\viewMenuWideLog.h"
#include "virtualMenu\viewMenuSub.h"

#include "..\bazis.h"

//код компонентов
#define KOD_COMPONENT  WL_COMP1
//к-во ступеней
#define CNT_STUPEN_WL  1

#endif // _HIDE_COMPONENT

//РАСПРЕДЕЛЕНИЕ УСТАВОК  в менеджере уставок
//уставка сработки
//к-во уставок в менеджере уставок
#define MNGUST_WL_TOTAL  0

//РАСПРЕДЕЛЕНИЕ ENA КОМАНД
//к-во ENA команд
#define ENACMD_WL_TOTAL 0

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//к-во уставок в супервизоре
#define SPVUST_WL_TOTAL  0

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ WL
//имя IO1
#define IOCMD1_WL 0
//к-во IO команд
#define IOCMD_WL_TOTAL    1

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ WL
//к-во TL команд
#define TLCMD_WL_TOTAL    0

#ifndef _HIDE_COMPONENT

//выбранный ЛЭ
#define LIGHTLE    LIGHTRANGUVV

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре

extern LineMenuItem sub_menu_cnfwl[];

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern char *bitStringUNI[];
extern int  TypLE[];
extern int  IndexIO;//индекс IO

int codecUstWL(char codec, short offset, int ust);
void initTimersWL(short idxC);
void logicWL(int idxC);
void WideLogLogic();

int   isDISactiv_WL(int idxC);

void OpenMenuWL();
void SetNameMenuTyp();
void SelectTypLE();
void SetAllTitleLE();
void OpenMenuLE();

int SelectTypViewLE;//перекл тип или view элем
char titleLE[30]="";

int  offsetIOCmdWL;//смещение для IO WL

char WL_TITLE[] = "РЛ";

IONAMESTATUS_COMPONENT ionsWL[IOCMD_WL_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок РЛ"
  }
};

LineMenuItem sub_menu_comp_WL[8] =
{
  { "РЛ", NULL},//title
  { &CONTROL1_COMP, &sub_menu_cnf,   typeMenuSub},//control_item, parent
  { "Лог элементы",  (void*)&OpenMenuWL, typeMenuProg},
  { "Конфигурация РЛ", sub_menu_cnfwl,  typeMenuCnfWL},//конфигурация
  { NULL, NULL}
};

LineMenuItem sub_menu_widel[] =
{
  { "Лог элементы", NULL},//title
  { &CONTROL_WDL, &sub_menu_comp_WL, typeMenuSub},//control_item, parent
/*
  { "ЛЭ1 это буфер элемента1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "ЛЭ2 это буфер элемента1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "ЛЭ3 это буфер элемента1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "ЛЭ4 это буфер элемента1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "ЛЭ5 это буфер элемента1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "ЛЭ6 это буфер элемента1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "ЛЭ7 это буфер элемента1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "ЛЭ8 это буфер элемента1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "ЛЭ9 это буфер элемента1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "ЛЭ10 это буфер элемента1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "ЛЭ11 это буфер элемента1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "ЛЭ12 это буфер элемента1234",   (void*)&OpenMenuLE, typeMenuProg},
  { " Выбор типа элемента", (void*)&SelectTypLE, typeMenuProg},// sub_menu_typWL,  typeMenuSub},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_typLE[] =
{
  { titleLE, NULL},//title
  { &CONTROL_TLE, sub_menu_widel},//control_item, parent
  { " Элемент ОТКЛ",     (void*)&OpenTypLE, typeMenuProg},
  { " Элемент ИЛИ",      (void*)&OpenTypLE, typeMenuProg},
  { " Элемент И",        (void*)&OpenTypLE, typeMenuProg},
  { " Элемент ИСКЛ ИЛИ", (void*)&OpenTypLE, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_viewWL[] =
{
  { titleLE, NULL },//title
  { &CONTROL_EWL, sub_menu_widel}//control_item, parent
};

void OpenMenuLE()
{
//открыть меню лог элемента
  LIGHTLE = LIGHTLINEMENU;//выбранный ЛЭ
  //заголовок ЛЭ
  sprintf(titleLE, "ЛЭ%d", LIGHTLE+1);//текущий кадр
  SetTitleLE(LIGHTLE, titleLE);//заголовок ЛЭ

  if(SelectTypViewLE) //перекл тип или ранжир элем
  {
    //тип элемента
    CRR_SUBMENU = sub_menu_typLE;//текущее субменю
    CRR_TEXTSTREAM = &CONTROL_TLE;//текущий control
    TxtStreamInit(&CONTROL_TLE, &KadrMenuFormat_sub, sub_menu_typLE);//инит управл структ и формир кадра
    PNTCRR_SUBMENU(SUBDATA).TypesWin = typeMenuSub;
    convert_submenutyp(TypLE[LIGHTLE]);//конвертировать строки sub_menu_typWL
    ViewDiskrMenu(typeMenuSub);//вывести окно отображения
  }//
  else
  {
    //ранжир элемента
    CRR_SUBMENU = sub_menu_viewWL;//текущее субменю
    PNTCRR_SUBMENU(SUBDATA).TypesWin = typeMenuViewLE;
    OpenViewLE();
  }
}//OpenMenuLE()

void OpenMenuWL()
{
  CRR_SUBMENU = sub_menu_widel;
  CRR_TEXTSTREAM = &CONTROL_WDL;//текущий control
  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control

  SetNameMenuTyp();//новое меню типа

  SetAllTitleLE();//перезаписать все заголовки лог элементов

  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
}//OpenMenuWL()

void SetNameMenuTyp()
{
//новое меню типа
  //char locTxt[20];
  short size_avait = TxtStreamMaxKadr(&CONTROL_WDL);//макс к-во кадров
  if(SelectTypViewLE) //перекл тип или view элем
  {
    strcpy((char*)sub_menu_widel[SUBDATA+1 +size_avait-1].Line1,
           "Тип элемента"
          );
  }//if
  else
  {
    strcpy((char*)sub_menu_widel[SUBDATA+1 +size_avait-1].Line1,
           "Ранжир элемента"
          );
  }
}//SetNameMenuTyp()

void SelectTypLE()
{
//переключатель на тип элемента
  CRR_SUBMENU = sub_menu_widel;
  CRR_TEXTSTREAM = &CONTROL_WDL;//текущий control
  if(SelectTypViewLE) //перекл тип или ранж элем
  {
    SelectTypViewLE = 0;
  }//if
  else
  {
    SelectTypViewLE = 1;
  }
  SetNameMenuTyp();//новое меню типа

  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
}//SelTypLE()

void SetAllTitleLE()
{
//перезаписать все заголовки лог элементов
  char locTxt[20];
  short size_avait = TxtStreamMaxKadr(&CONTROL_WDL);//макс к-во кадров
  //новые пункты меню
  for(int i=0; i<size_avait-1; i++)
  {
    sprintf(locTxt, "ЛЭ%d", i+1);//текущий кадр
    strcpy((char*)sub_menu_widel[SUBDATA+1 +i].Line1, locTxt);

    SetTitleLE(i, (char*)sub_menu_widel[SUBDATA+1 +i].Line1);//заголовок ЛЭ

  }//for
}//SetAllTitleLE()

//тип лог элемента
//0-ОТКЛ
//1-ИЛИ
//2-И
//3-ИСКЛ ИЛИ
void OpenTypLE()
{

  CRR_SUBMENU = sub_menu_typLE;
  short iKadr = TxtStreamIdxKadr(&CONTROL_TLE);
  convert_submenutyp(iKadr);//конвертировать строки sub_menu_typWL

  TypLE[LIGHTLE] = iKadr;//установить новый тип ЛЭ
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения

  SetAllTitleLE();//перезаписать все заголовки лог элементов
}//OpenTypLE()

void convert_submenutyp(short numStr)
{
//конвертировать строки sub_menu_typWL
  ((char*)sub_menu_typLE[SUBDATA+1 +0].Line1)[0] = ' ';
  ((char*)sub_menu_typLE[SUBDATA+1 +1].Line1)[0] = ' ';
  ((char*)sub_menu_typLE[SUBDATA+1 +2].Line1)[0] = ' ';
  ((char*)sub_menu_typLE[SUBDATA+1 +3].Line1)[0] = ' ';
  ((char*)sub_menu_typLE[SUBDATA+1 +numStr].Line1)[0] = '*';
}//convert_submenutyp(short numStr)

int initUstWL(char init)
{
  //инициал уставок
  if (init)
  {
  }//if

  IndexUstSPV += SPVUST_WL_TOTAL;//индекс уставок в супервизоре
  return MNGUST_WL_TOTAL;//к-во уставок в менеджере уставок
}//initUstMTZ1(short mngUst, char init)

void  prepareUstWL(short idxC)
{
  //подготовка ENA команд для клона
}//prepareUstMTZ1(short idxC)

int initIOCmd_WL()
{
  //инициал IO команд
  offsetIOCmdWL = IndexIO;//смещение для IO WL
  return commonInitIOCmd(IOCMD_WL_TOTAL);
}//initIOCmd_WL()

int initTLCmd_WL()
{
  //инициал TL команд
  return commonInitTLCmd(TLCMD_WL_TOTAL);
}//initTLCmd_WL()

int initENACmd_WL()
{
  //инициал ENA команд
  return commonInitENACmd(ENACMD_WL_TOTAL);
}//initENACmd_WL()

void initTimersWL(short idxC)
{
  //запрос и инициал таймеров
}//initTimersWL(short idxC)

int codecUstWL(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  return 1;
}//codecUstWL(char *buf, short offset, int ust)

int isDISactiv_WL(int idxC)
{
 //активность Регистратора ДИС
  return 0;//нет активности
}//isDISactiv_WL(int idxC)

char copyWLToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое
//копировать компонент в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.packet = 0;    //номер пакетного компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  WL_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_WL;//меню компонента

  rpzcomponent_obj.cntClon     = CNT_STUPEN_WL;   //max к-во клонов
  rpzcomponent_obj.numClon     = 1;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstWL;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstWL;//подготовка уставок
  rpzcomponent_obj.initIOCmd      = initIOCmd_WL;      //инициал IO команд
  rpzcomponent_obj.initTLCmd      = initTLCmd_WL;      //инициал TL команд
  rpzcomponent_obj.initENACmd     = initENACmd_WL;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_WL; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsWL;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersWL;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicWL;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstWL;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

