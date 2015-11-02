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

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "virtualMenu\systemmenudef.h"
#include "component\componentdef.h"
#include "virtualMenu\rangmanagerdef.h"
#include "virtualMenu\ustmanagerdef.h"

#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\wideLogManagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "virtualMenu\viewMenuSub.h"
#include "virtualMenu\viewMenuRang.h"
#include "virtualMenu\viewMenuWideLog.h"
#include "virtualMenu\viewMenuTip.h"

#include "psupervisor\psupervisor.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

//номер бита для редактирования
#define RANG_BIT         LIGHTMNGUOFFSET
//к-во открытых команд
#define RANG_CNTOPEN_CMD LIGHTMNGUBAZA

extern IONAMESTATUS_RANGIR  nameStatusRANGIR[];
extern LineMenuItem sub_menu_editrng[];//редактор ранжир

extern char titleRang[];
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern StreamControl controlStruct_tip;//управл структура

extern int workerUniversal1;//данные для работника
extern int workerUniversal2;//данные для работника
extern UNS_32 pActualCMD[];//текущие
extern UNS_32 pRDIScmdMaska[];//регистрацияДИС
extern UNS_32 pAPVcmdMaska[];//APV
extern UNS_32 pUROVcmdMaska[];//UROV
//extern UNS_32 pP1OFcmdMaska[];//P1OF
//extern UNS_32 pP2OFcmdMaska[];//P2OF
//extern UNS_32 pP3OFcmdMaska[];//P3OF

extern UNS_32 selectorDVLow;//селекция ДВ активный-неактивный для мл 16 DV
extern UNS_32 selectorDVMidd;//селекция ДВ активный-неактивный для cp 16 DV
extern UNS_32 selectorDVHi;//селекция ДВ активный-неактивный для ct 16 DV
extern UNS_32 rele_bdvv1;//селекция реле

UNS_32 selectorUVVLow;//селекция UVV активный-неактивный для мл 16 UVV
UNS_32 selectorUVVMidd;//селекция UVV активный-неактивный для cp 16 UVV
UNS_32 selectorUVVHi;//селекция UVV активный-неактивный для ct 16 UVV

char isRangRedactor = 0;//было ли редактировано ранжир

short  KadrMenuFormat_viewRang(void *pstr)//(WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  //универсальный просмотр ранжир
  Universal_viewRang(workCntr, MngRangGetPointerUVVRANGIRtoEdit(LIGHTRANGUVV));

  return 1;

}//KadrMenuFormat_viewRang(WorkControl *workCntr)

short  KadrMenuFormat_viewActual(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  //универсальный просмотр ранжир
  Universal_viewRang(workCntr, pActualCMD);

  return 1;

}//KadrMenuFormat_viewActual(WorkControl *workCntr)

short  KadrMenuFormat_viewActualDV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  //универсальный просмотр UVV
  Universal_viewUVV(pstr, "ДВ", 1);
  return 1;
}//KadrMenuFormat_viewActualDV(WorkControl *workCntr)
short  KadrMenuFormat_viewActualRele(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  //универсальный просмотр UVV
  Universal_viewUVV(pstr, "Реле", 1);
  return 1;
}//KadrMenuFormat_viewActualRele(WorkControl *workCntr)

void  Universal_viewUVV(void *pstr, char *inStr, short offset)
{
 WorkControl *workCntr = (WorkControl *)pstr;
  //универсальный просмотр UVV
  short cntKadr = 0;//к-во кадров
  short cntKadrLow = 0;//к-во кадров Low
  short cntKadrMidd = 0;//к-во кадров Midd
  short cntKadrHi = 0;//к-во кадров Hi
  short isEmpty = 0;
//unsigned int testDV = 255-1;
 char nameUpr[30];
 char locTxt[30];
//посчитать к-во кадров
  workerUniversal1 = 0;//данные для работника
  MultiBitWorkerHostWord( &selectorUVVLow, &pfWorker1);
  cntKadrLow = workerUniversal1;//к-во кадров
  workerUniversal1 = 0;//данные для работника
  MultiBitWorkerHostWord( &selectorUVVMidd, &pfWorker1);
  cntKadrMidd = workerUniversal1;//к-во кадров
  workerUniversal1 = 0;//данные для работника
  MultiBitWorkerHostWord( &selectorUVVHi, &pfWorker1);
  cntKadrHi = workerUniversal1;//к-во кадров
  cntKadr = cntKadrLow + cntKadrMidd + cntKadrHi;
  if(cntKadr==0)
  {
    isEmpty = 1;
    cntKadr=1;
  }//if

  for(int i=0;; i++)
  {
//критерий терминатора
    if(i==cntKadr) break;
    COMPARE_COUNTER
    {
      if(isEmpty)
      {
        strcpy((char *)workCntr->twoString, "ПУСТО");
        return;
      }//if

//      int tt1 = selectorUVVLow;
//      int tt2 = selectorUVVMidd;
//      int tt3 = selectorUVVHi;
      strcpy(nameUpr, inStr);
      //найти индекс i-й активной команды
      workerUniversal2 = i;//данные для работника
      workerUniversal1 = 0;
      if(MultiBitWorkerHostWord(&selectorUVVLow, &pfWorker2)){
         //найти имя команды
         sprintf(locTxt, "%d", workerUniversal2+offset);
         strcat(nameUpr, locTxt);
         strcpy((char *)workCntr->twoString, nameUpr);
      }//if
      else{
      workerUniversal2 = i-cntKadrLow;//данные для работника
      workerUniversal1 = 0;
      if(MultiBitWorkerHostWord(&selectorUVVMidd, &pfWorker2)){
         //найти имя команды
         sprintf(locTxt, "%d", workerUniversal2+16+offset);
         strcat(nameUpr, locTxt);
         strcpy((char *)workCntr->twoString, nameUpr);
      }//if
      else{
      workerUniversal2 = i-cntKadrLow-cntKadrMidd;//данные для работника
      workerUniversal1 = 0;
      MultiBitWorkerHostWord(&selectorUVVHi, &pfWorker2);
         //найти имя команды
         sprintf(locTxt, "%d", workerUniversal2+16+16+offset);
         strcat(nameUpr, locTxt);
         strcpy((char *)workCntr->twoString, nameUpr);
      }//else
      }//else
      return;
    }//COMPARE_COUNTER
  }//for

  return;
}//Universal_viewUVV(char *inStr, short offset)

short  KadrMenuFormat_viewRDIS(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра РегистрацияДИС
  RESET_COUNTER;//сброс счетчиков
  //универсальный просмотр ранжир
  Universal_viewRang(workCntr, pRDIScmdMaska);

  return 1;

}//KadrMenuFormat_viewRDIS(void *pstr)

short  KadrMenuFormat_viewAPV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра 
  RESET_COUNTER;//сброс счетчиков
  //универсальный просмотр ранжир
  Universal_viewRang(workCntr, pAPVcmdMaska);

  return 1;

}//KadrMenuFormat_viewAPV(void *pstr)

short  KadrMenuFormat_viewUROV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра 
  RESET_COUNTER;//сброс счетчиков
  //универсальный просмотр ранжир
  Universal_viewRang(workCntr, pUROVcmdMaska);

  return 1;

}//KadrMenuFormat_viewUROV(void *pstr)

short  KadrMenuFormat_viewP1OF(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра 
  RESET_COUNTER;//сброс счетчиков
  //универсальный просмотр ранжир
//  Universal_viewRang(workCntr, pP1OFcmdMaska);

  return 1;

}//KadrMenuFormat_viewP1OF(void *pstr)

short  KadrMenuFormat_viewP2OF(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра 
  RESET_COUNTER;//сброс счетчиков
  //универсальный просмотр ранжир
//  Universal_viewRang(workCntr, pP2OFcmdMaska);

  return 1;

}//KadrMenuFormat_viewP2OF(void *pstr)

short  KadrMenuFormat_viewP3OF(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра 
  RESET_COUNTER;//сброс счетчиков
  //универсальный просмотр ранжир
//  Universal_viewRang(workCntr, pP3OFcmdMaska);

  return 1;

}//KadrMenuFormat_viewP3OF(void *pstr)

void  Universal_viewRang(void *pstr, UNS_32 *pDQuadro)
{
 WorkControl *workCntr = (WorkControl *)pstr;
  //универсальный просмотр ранжир
  short cntKadr = 0;//к-во кадров
  short isEmpty = 0;
//посчитать к-во кадров
  workerUniversal1 = 0;//данные для работника
  MultiBitWorkerHostQuadro(
    pDQuadro, &pfWorker1);
  cntKadr = workerUniversal1;//к-во кадров
  if(cntKadr==0)
  {
    isEmpty = 1;
    cntKadr=1;
  }//if

  for(int i=0;; i++)
  {
//критерий терминатора
    if(i==cntKadr) break;
    COMPARE_COUNTER
    {
      if(isEmpty)
      {
        strcpy((char *)workCntr->twoString, "ПУСТО");
        return;
      }//if

      //найти индекс i-й активной команды
      workerUniversal2 = i;//данные для работника
      workerUniversal1 = 0;
      MultiBitWorkerHostQuadro(
        pDQuadro, &pfWorker2);
      //найти имя команды
      strcpy((char *)workCntr->twoString, nameStatusRANGIR[workerUniversal2].nameIORang);
      return;
    }//COMPARE_COUNTER
  }//for
}//Universal_viewRang(WorkControl *workCntr, UNS_32 *pDQuadro)

void OpenMenuViewRangDV()
{
//открыть меню rang DV
  LIGHTRANGUVV = LIGHTLINEMENU;//номер УВВ ранжир
  sprintf(titleRang, "ДВ%d", LIGHTLINEMENU +1);//текущий кадр

  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//Подготовить ArrayRANGIR к редактированию

  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
  SelectorTEXTCONTROL(&CONTROL_VRNG);//установить текущую ссылку на текстовый поток

  SelectorFHOME(&PereinitViewRang);//указатель на ф-цию HOME

  InitFHOME(1);//переиниц

}//OpenMenuViewRangDV()

void OpenMenuViewRangRele()
{
//открыть меню rang Rele
  LIGHTRANGUVV = LIGHTLINEMENU + DV_TOTAL;//номер УВВ ранжир
  sprintf(titleRang, "Р%d", LIGHTLINEMENU +1);//текущий кадр

  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//Подготовить ArrayRANGIR к редактированию

  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
  SelectorTEXTCONTROL(&CONTROL_VRNG);//установить текущую ссылку на текстовый поток
  SelectorFHOME(&PereinitViewRang);//указатель на ф-цию HOME

  InitFHOME(1);//переиниц

}//OpenMenuViewRangRele()

void OpenMenuViewRangCDI()
{
//открыть меню rang CDI
  LIGHTRANGUVV = LIGHTLINEMENU + DV_TOTAL + RELE_TOTAL;//номер УВВ ранжир
  sprintf(titleRang, "СДИ%d", LIGHTLINEMENU +1);//текущий кадр

  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//Подготовить ArrayRANGIR к редактированию

  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
  SelectorTEXTCONTROL(&CONTROL_VRNG);//установить текущую ссылку на текстовый поток
  SelectorFHOME(&PereinitViewRang);//указатель на ф-цию HOME

  InitFHOME(1);//переиниц

}//OpenMenuViewRangCDI()

void OpenMenuViewActual()
{
//открыть меню Текущие
  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
  SelectorTEXTCONTROL(&CONTROL_ACT);//установить текущую ссылку на текстовый поток
  SelectorFHOME(&PereinitViewActual);//указатель на ф-цию HOME

  InitFHOME(1);//переиниц
}//OpenMenuViewActual()

void OpenMenuViewActualDV()
{
//открыть меню Текущие DV
 selectorUVVLow  = selectorDVLow;//селекция UVV активный-неактивный для мл 16 UVV
 selectorUVVMidd = selectorDVMidd;//селекция UVV активный-неактивный для cp 16 UVV
 selectorUVVHi   = selectorDVHi;//селекция UVV активный-неактивный для ct 16 UVV
  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
  SelectorTEXTCONTROL(&CONTROL_ACT);//установить текущую ссылку на текстовый поток
  SelectorFHOME(&PereinitViewActualDV);//указатель на ф-цию HOME

  InitFHOME(1);//переиниц
}//OpenMenuViewActualDV()

void OpenMenuViewActualRele()
{
//открыть меню Текущие DV
 selectorUVVLow  = rele_bdvv1;//селекция UVV активный-неактивный для мл 16 UVV
 selectorUVVMidd = 0;//селекция UVV активный-неактивный для cp 16 UVV
 selectorUVVHi   = 0;//селекция UVV активный-неактивный для ct 16 UVV
  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
  SelectorTEXTCONTROL(&CONTROL_ACT);//установить текущую ссылку на текстовый поток
  SelectorFHOME(&PereinitViewActualRele);//указатель на ф-цию HOME

  InitFHOME(1);//переиниц
}//OpenMenuViewActualRele()

void PereinitViewActual(short flg)
{
//ф-ция переинит Текущие
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewActual, NULL);//инит управл структ и формир кадра
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
}//PereinitViewActual(short flg)
void PereinitViewActualDV(short flg)
{
//ф-ция переинит Текущие DV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewActualDV, NULL);//инит управл структ и формир кадра
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
}//PereinitViewActualDV(short flg)
void PereinitViewActualRele(short flg)
{
//ф-ция переинит Текущие DV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewActualRele, NULL);//инит управл структ и формир кадра
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
}//PereinitViewActualRele(short flg)

void OpenMenuViewRDIS()
{
//открыть меню РегистрацияДИС
  LIGHTRANGUVV = REGDIS_SM;//номер УВВ ранжир
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//Подготовить pRDIScmdMaska к редактированию

  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
  SelectorTEXTCONTROL(&CONTROL_RDIS);//установить текущую ссылку на текстовый поток
  SelectorFHOME(&PereinitViewRDIS);//указатель на ф-цию HOME

  InitFHOME(1);//переиниц
}//OpenMenuViewRDIS()

void PereinitViewRDIS(short flg)
{
//ф-ция переинит РегистрацияДИС
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewRDIS, NULL);//инит управл структ и формир кадра
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
}//PereinitViewRDIS(short flg)

void OpenMenuViewAPV()
{
//открыть меню РегистрацияДИС
  LIGHTRANGUVV = PUSKAPV_SM;//номер УВВ ранжир
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//Подготовить к редактированию

  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
  SelectorTEXTCONTROL(&CONTROL_APV);//установить текущую ссылку на текстовый поток
  SelectorFHOME(&PereinitViewAPV);//указатель на ф-цию HOME

  InitFHOME(1);//переиниц
}//OpenMenuViewAPV()

void PereinitViewAPV(short flg)
{
//ф-ция переинит APV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewAPV, NULL);//инит управл структ и формир кадра
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
}//PereinitViewAPV(short flg)

void OpenMenuViewUROV()
{
//открыть меню РегистрацияДИС
  LIGHTRANGUVV = PUSKUROV_SM;//номер УВВ ранжир
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//Подготовить к редактированию

  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
  SelectorTEXTCONTROL(&CONTROL_UROV);//установить текущую ссылку на текстовый поток
  SelectorFHOME(&PereinitViewUROV);//указатель на ф-цию HOME

  InitFHOME(1);//переиниц
}//OpenMenuViewAPV()

void PereinitViewUROV(short flg)
{
//ф-ция переинит APV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewUROV, NULL);//инит управл структ и формир кадра
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
}//PereinitViewUROV(short flg)

void OpenMenuViewP1OF()
{
//открыть меню РегистрацияДИС
  LIGHTRANGUVV = PUSK1OF_SM;//номер УВВ ранжир
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//Подготовить к редактированию

  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
  SelectorTEXTCONTROL(&CONTROL_P1OF);//установить текущую ссылку на текстовый поток
  SelectorFHOME(&PereinitViewP1OF);//указатель на ф-цию HOME

  InitFHOME(1);//переиниц
}//OpenMenuViewP1OF()

void PereinitViewP1OF(short flg)
{
//ф-ция переинит APV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewP1OF, NULL);//инит управл структ и формир кадра
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
}//PereinitViewP1OF(short flg)

void OpenMenuViewP2OF()
{
//открыть меню РегистрацияДИС
  LIGHTRANGUVV = PUSK2OF_SM;//номер УВВ ранжир
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//Подготовить к редактированию

  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
  SelectorTEXTCONTROL(&CONTROL_P2OF);//установить текущую ссылку на текстовый поток
  SelectorFHOME(&PereinitViewP2OF);//указатель на ф-цию HOME

  InitFHOME(1);//переиниц
}//OpenMenuViewP1OF()

void PereinitViewP2OF(short flg)
{
//ф-ция переинит APV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewP2OF, NULL);//инит управл структ и формир кадра
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
}//PereinitViewP2OF(short flg)

void OpenMenuViewP3OF()
{
//открыть меню РегистрацияДИС
  LIGHTRANGUVV = PUSK3OF_SM;//номер УВВ ранжир
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//Подготовить к редактированию

  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
  SelectorTEXTCONTROL(&CONTROL_P3OF);//установить текущую ссылку на текстовый поток
  SelectorFHOME(&PereinitViewP3OF);//указатель на ф-цию HOME

  InitFHOME(1);//переиниц
}//OpenMenuViewP3OF()

void PereinitViewP3OF(short flg)
{
//ф-ция переинит APV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewP3OF, NULL);//инит управл структ и формир кадра
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
}//PereinitViewP3OF(short flg)

void PereinitViewRang(short flg)
{
//ф-ция переинит rang
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewRang, NULL);//инит управл структ и формир кадра
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
}//PereinitReg()

short  KadrMenuFormat_prc_editrang(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
//процесс редактирования
  short next = 0;
  short cntKadr = 0;//к-во кадров

  short numCloseComp = 0;//закр компоненты
  while (cnfCOMPONENT[next].componentEnable)   //все компоненты в конфигурации
  {
    next++;
  }//while

  cntKadr = next+ RANG_CNTOPEN_CMD-1;//к-во кадров

  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    if(i==cntKadr) break;
    COMPARE_COUNTER
    {
      if(i<  LIGHTCLON)numCloseComp = i;
      if(i>( LIGHTCLON   + RANG_CNTOPEN_CMD -1)) numCloseComp = i- RANG_CNTOPEN_CMD+1;
      if(i<  LIGHTCLON || i>(LIGHTCLON + RANG_CNTOPEN_CMD-1))
      {
        strcpy((char *)workCntr->twoString, cnfCOMPONENT[numCloseComp].nameComponent);
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    Раздел");
      }
      else{
        short cmdPosition  = //позиция выбранной команды в табл ранж
        i-LIGHTCLON + getOffsetIOCmdCnf(LIGHTCLON);

        strcpy((char *)workCntr->twoString,
        nameStatusRANGIR[
          cmdPosition
        ].nameIORang
              );
//значение бита ранжирования
        if(NumBitCheckQuadro(cmdPosition,
        MngRangGetPointerUVVRANGIRtoEdit(LIGHTRANGUVV)
                            )) //проверка бита по его индексу
        {
          strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    Вкл");
        }//if
        else{
          strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    Откл");
        }

      }//else


      return 1;
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat_prc_editrang(WorkControl *workCntr)

short  KadrMenuFormat_openEditRang(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    short next = 0;
    while (cnfCOMPONENT[next].componentEnable)   //все компоненты в конфигурации
    {
      next++;
    }//while
    if(next==0)
    {
      strcpy((char *)workCntr->twoString, "Конфигурация");
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "пустая");
      if(i==1)break;
    }//if
    else
    {
      if(i==next) break;
    }//else

    COMPARE_COUNTER
    {
      if(next!=0)
      {
        strcpy((char *)workCntr->twoString, cnfCOMPONENT[i].nameComponent);
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    Раздел");
      }//if
      return 1;//сравнить счетчики кадров
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat_openEditRang(WorkControl *workCntr)

extern LineMenuItem sub_menu_viewDV[];

void ClickOpenEditRang(UNS_32 *cmdUVV)
{
  /*
//Получить адр ArrayRANGIR конкр УВВ для редактирования
  short  findClon = -1; //найти клон для позиционирования
  UNS_32 tmp=0;
  for(int i=0; i<DQUADRO; i++) tmp|=cmdUVV[i];

  if(tmp)
  {
    //найти индекс i-й активной команды
    workerUniversal2 = TxtStreamIdxKadr(CRR_TEXTSTREAM);
    workerUniversal1 = 0;
    MultiBitWorkerHostQuadro(cmdUVV, &pfWorker2);

//найти клон для позиционирования
    short next = 0;
    while (cnfCOMPONENT[next].componentEnable)   //все компоненты в конфигурации
    {
      if(getOffsetIOCmdCnf(next)>workerUniversal2) break;
      next++;
    }//while
    findClon = next-1;
  }//if

//открыть редактирование ранжир
  LIGHTCLON = -1;//индекс откр компонента

//ф-ция переинит rang
  SelectorTEXTCONTROL(&CONTROL_ERNG);//установить текущую ссылку на текстовый поток

//текущий sub_menu и будет его parent
  sub_menu_editrng[SUBDATA].Line2 = CRR_SUBMENU;

   SelectorSUBMENU(sub_menu_editrng);//уcтановить текущее субменю

  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_openEditRang, NULL);//инит управл структ и формир кадра
  if(findClon>0)
    TxtStreamSetIdxKadr(CRR_TEXTSTREAM, findClon);//установка номера текущего кадра

  ViewDiskrMenu(typeMenuEditRang);//вывести окно отображения
  ListPStr();//размещение указателя строки

  FvmenuDis->TipPanel->Visible = true;
  ViewTipPanel(0);//панель подсказки TipPanel
  */
}//ClickOpenEditRang(UNS_32 *cmdUVV)

void ClickProcessEditRang()
{
//начать редактирование ранжир
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока

  if(LIGHTCLON<0)//индекс откр компонента
  {
    LIGHTCLON = LIGHTLINEMENU;//индекс откр компонента
  }//if
  else
  {
    for(short i=0; i<1; i++)
    {
      if(
        LIGHTLINEMENU<  LIGHTCLON)
      {
        LIGHTCLON = LIGHTLINEMENU;//индекс откр компонента
        break;
      }
      if(
        LIGHTLINEMENU >( LIGHTCLON+ RANG_CNTOPEN_CMD-1))
      {
        LIGHTCLON = LIGHTLINEMENU - RANG_CNTOPEN_CMD+1;
        break;
      }
      short cmdPosition = RANG_BIT=//позиция выбранной команды в табл ранж
                            getOffsetIOCmdCnf(LIGHTCLON) +
                            LIGHTLINEMENU - LIGHTCLON;
      RangRedactor(cmdPosition);//редактировать ранжирование
      return;
    }//for
  }//else

  RANG_CNTOPEN_CMD = cnfCOMPONENT[LIGHTCLON].cntIOCmd;//к-во открытых строк

  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_prc_editrang, NULL);//инит управл структ и формир кадра
  TxtStreamSetIdxKadr(PNTCRR_TEXTSTREAM, LIGHTCLON);//установка номера текущего кадра

  ViewDiskrMenu(typeMenuEditRang);//вывести окно отображения
  ListPStr();//размещение указателя строки

  ViewTipPanel(0);//панель подсказки TipPanel
}//ClickProcessEditRang()

void RangRedactor(short cmdPosition)
{
  /*
//редактировать ранжирование
  FvmenuDis->EditRangPanel->Visible = true;
  FvmenuDis->ConfirmRangPanel->Visible = false;
  FvmenuDis->EditRangLabel->Caption =
    nameStatusRANGIR[
      cmdPosition
    ].nameIORang;
  if(NumBitCheckQuadro(cmdPosition,
                       MngRangGetPointerUVVRANGIRtoEdit(LIGHTRANGUVV)
                      )) //проверка бита по его индексу
  {
    FvmenuDis->RangCheck->Checked = true;
    FvmenuDis->RangCheck->Caption = "ВКЛ";
  }//if
  else
  {
    FvmenuDis->RangCheck->Checked = false;
    FvmenuDis->RangCheck->Caption = "ОТКЛ";
  }
*/
}//RangRedactor()

void  ClickEditRangOKButton()
{
  /*
//редактировать ранжирование
//индекс выбранной команды ранжирования
  if(FvmenuDis->RangCheck->Checked)
  {
    NumBitSettingQuadro(RANG_BIT,
                        MngRangGetPointerUVVRANGIRtoEdit(LIGHTRANGUVV)
                       ); //установка бита по его индексу
  }
  else
    NumBitClearingQuadro(RANG_BIT,
                         MngRangGetPointerUVVRANGIRtoEdit(LIGHTRANGUVV)
                        ); //сброс бита по его индексу

  ApplyDVMask(LIGHTRANGUVV);//наложить маску на DV

  RangRedactor(RANG_BIT);//отобразить ранжирование

  isRangRedactor = 1;//было ли редактировано ранжир

  ViewTipPanel(0);
*/
}//ClickEditRangOKButton()

void  FinishEditRang(int isOK)
{
//сохранить и завершить редактир ранжир
  isRangRedactor = 0;//было ли редактировано ранжир
  if(isOK){
     MngRangEndingEditArrayRANGIR(LIGHTRANGUVV);//Сохр изменения в массиве ранжир
     SaveCRCrang();//сохранить CRC ранжир
     PrepareBOBV();//подготовить Блок ОТКЛ, Блок ВКЛ
          }//if
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);
  TxtStreamInit(&CONTROL_VRNG, &KadrMenuFormat_viewRang, NULL);//новое к-во команд на УВВ
}//FinishEditRang()

