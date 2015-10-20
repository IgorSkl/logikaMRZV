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

#include "toSpeedOptim.h"

#include "..\bazis.h"

//код компонентов
#define KOD_COMPONENT  PF_COMP1
//к-во ступеней
#define CNT_STUPEN_PF  1

#endif // _HIDE_COMPONENT

//РАСПРЕДЕЛЕНИЕ УСТАВОК  в менеджере уставок
//к-во уставок в менеджере уставок
#define MNGUST_PF_TOTAL  0

//РАСПРЕДЕЛЕНИЕ ENA КОМАНД
//к-во ENA команд
#define ENACMD_PF_TOTAL 0

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//к-во уставок в супервизоре
#define SPVUST_PF_TOTAL  0

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ PF
//PF1
#define IOCMD1_PF 0
//PF2
#define IOCMD2_PF 1
//PF3
#define IOCMD3_PF 2
//PF4
#define IOCMD4_PF 3
//PF5
#define IOCMD5_PF 4
//PF6
#define IOCMD6_PF 5
//PF7
#define IOCMD7_PF 6
//PF8
#define IOCMD8_PF 7
//PF9
#define IOCMD9_PF 8
//PF10
#define IOCMD10_PF 9
//PF11
#define IOCMD11_PF 10
//PF12
#define IOCMD12_PF 11
//PF13
#define IOCMD13_PF 12
//PF14
#define IOCMD14_PF 13
//PF15
#define IOCMD15_PF 14
//PF16
#define IOCMD16_PF 15
//к-во IO команд
#define IOCMD_PF_TOTAL    16

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ PF
//к-во TL команд
#define TLCMD_PF_TOTAL    0

//--------------- TIMERS ------------------
//РАСПРЕДЕЛЕНИЕ ТАЙМЕРОВ ДЛЯ PF
//к-во таймеров
#define TIMERS_PF_TOTAL   0

#ifndef _HIDE_COMPONENT

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];
extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре
extern int  IndexIO;//индекс IO
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern char *bitStringUNI[];
int codecUstPF(char codec, short offset, int ust);
void  logicPF(int idxC);
int   isDISactiv_PF(int idxC);

int  offsetIOCmdPF;//смещение для IO PF
int  offsetIOCmdPF_loc;//смещение для IO PF

char PF_TITLE[] = "ПФункции";

IONAMESTATUS_COMPONENT ionsPF[IOCMD_PF_TOTAL] =
{
  {
    1,//статус iocmd1
    "ПФункция 1"
  },
  {
    1,//статус iocmd1
    "ПФункция 2"
  },
  {
    1,//статус iocmd1
    "ПФункция 3"
  },
  {
    1,//статус iocmd1
    "ПФункция 4"
  },
  {
    1,//статус iocmd1
    "ПФункция 5"
  },
  {
    1,//статус iocmd1
    "ПФункция 6"
  },
  {
    1,//статус iocmd1
    "ПФункция 7"
  },
  {
    1,//статус iocmd1
    "ПФункция 8"
  },
  {
    1,//статус iocmd1
    "ПФункция 9"
  },
  {
    1,//статус iocmd1
    "ПФункция 10"
  },
  {
    1,//статус iocmd1
    "ПФункция 11"
  },
  {
    1,//статус iocmd1
    "ПФункция 12"
  },
  {
    1,//статус iocmd1
    "ПФункция 13"
  },
  {
    1,//статус iocmd1
    "ПФункция 14"
  },
  {
    1,//статус iocmd1
    "ПФункция 15"
  },
  {
    1,//статус iocmd1
    "ПФункция 16"
  }
};

LineMenuItem sub_menu_comp_PF[8] =
{
  { PF_TITLE, NULL},//title
  { &CONTROL1_COMP,   &sub_menu_cnf,   typeMenuSub},//control_item, parent
  { NULL, NULL}
};

int initUstPF(char init)
{
  //инициал уставок

  IndexUstSPV += SPVUST_PF_TOTAL;//индекс уставок в супервизоре
  return MNGUST_PF_TOTAL;//к-во уставок в менеджере уставок
}//initUstPF(short mngUst, char init)

void  prepareUstPF(short idxC)
{
  //подготовка ENA команд для клона
}//prepareUstPF(short idxC)

int initIOCmd_PF()
{
  //инициал IO команд
  offsetIOCmdPF_loc = IndexIO;//смещение для IO PF
  return commonInitIOCmd(IOCMD_PF_TOTAL);
}//initIOCmd_PF()

int initTLCmd_PF()
{
  //инициал TL команд
  return 0;
}//initTLCmd_PF()

int initENACmd_PF()
{
  //инициал ENA команд
  return 0;
}//initENACmd_PF()

void initTimersPF(short idxC)
{
  //запрос и инициал таймеров
}//initTimersPF()

int codecUstPF(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  return 1;
}//codecUstPF(char *buf, short offset, int ust)

int isDISactiv_PF(int idxC)
{
 //активность Регистратора ДИС
  return 0;//нет активности
}//isDISactiv_PF(int idxC)

char copyPFToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое

//копировать компонент в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.packet = 0;    //номер пакетного компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  PF_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_PF;//меню компонента

  rpzcomponent_obj.cntClon      = CNT_STUPEN_PF;   //max к-во клонов
  rpzcomponent_obj.numClon      = 1;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstPF;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstPF;//подготовка уставок
  rpzcomponent_obj.initIOCmd      = initIOCmd_PF;      //инициал IO команд
  rpzcomponent_obj.initTLCmd      = initTLCmd_PF;      //инициал TL команд
  rpzcomponent_obj.initENACmd     = initENACmd_PF;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_PF; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsPF;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersPF;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicPF;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstPF;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

