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
#include "component\componentdef.h"
#include "virtualMenu\systemmenudef.h"
#include "virtualMenu\rangmanagerdef.h"
#include "virtualMenu\wideLogManagerdef.h"

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\wideLogManagerfnc.h"
#include "psuperVisor\psupervisor.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "virtualMenu\viewMenuTip.h"
#include "virtualMenu\viewMenuWideLog.h"
#include "virtualMenu\viewMenuSub.h"
#include "virtualMenu\viewMenuCnf.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"


//номер бита для редактирования
#define RANG_BIT        LIGHTMNGUOFFSET
//к-во открытых команд
#define RANG_CNTOPEN_CMD LIGHTMNGUBAZA
//маркер клона РЛ
#define MARKCLON_WL 1000

extern LineMenuItem sub_menu_editwl[];
extern LineMenuItem sub_menu_cntr[];
extern LineMenuItem sub_menu_cnfwl[];
extern LineMenuItem sub_menu_tmp[];
extern LineMenuItem sub_menu_rpzWL[];

extern LineMenuItem sub_menu_viewWL[];
extern LineMenuItem sub_menu_logw[];
extern int workerUniversal1;//данные для работника
extern int workerUniversal2;//данные для работника
extern IONAMESTATUS_RANGIR  nameStatusRANGIR[];
extern UNS_32 ArrayWIDELOG[];
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ  cnfCOMPONENT_WL[];
extern char isRangRedactor;//было ли редактировано ранжир
extern int  TypLE[];
extern char titleWideLog[];

void SetTitleLE(int le, char *title)
{
//заголовок ЛЭ
  switch(TypLE[le])
  {
  case typeLE_DIS:
    strcat(title, "-ОТКЛ");
    break;
  case typeLE_OR:
    strcat(title, "-элемент ИЛИ");
    break;
  case typeLE_AND:
    strcat(title, "-элемент И");
    break;
  case typeLE_XOR:
    strcat(title, "-элемент ИСКЛ ИЛИ");
    break;
  default:
    ;
  }//switch
}//SetTitleLE(int le, char *title)

void OpenViewLE()
{
//открыть  лог команды LE на просмотр
  MngWideLogPrepareArrayWIDELOGtoEdit();//Подготовить ArrayWIDELOG к редактированию

//  CRR_TEXTSTREAM = &CONTROL_EWL;//текущий control
  SelectorTEXTCONTROL(&CONTROL_EWL);//установить текущую ссылку на текстовый поток
//  CRR_FHOME = &PereinitViewLE;//указатель на ф-цию HOME
  SelectorFHOME(&PereinitViewLE);//указатель на ф-цию HOME

//  CRR_FHOME(1);
  InitFHOME(1);//переиниц
}//OpenViewLE()

void PereinitViewLE(short flg)
{
//ф-ция переинит LE
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewLE, NULL);//инит управл структ и формир кадра
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения

}//PereinitViewLE(short flg)

short  KadrMenuFormat_viewLE(void *pstr)
{
  WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  short cntKadr = 0;//к-во кадров
  short isEmpty = 0;

  UNS_32 cmnDQuadro[2*DQUADRO];//общий dquadro

  setComonDQuadro(cmnDQuadro);//заполнить общий dquadro

  workerUniversal1 = 0;//данные для работника
  MultiBitWorkerHostQuadroWL(
    cmnDQuadro, &pfWorker1);
  cntKadr = workerUniversal1;//к-во кадров для общий dquadro

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
        return 1;
      }//if

      //имя и знак команды WL
      //найти индекс i-й активной команды
      workerUniversal2 = i;//данные для работника
      workerUniversal1 = 0;
      MultiBitWorkerHostQuadroWL(
        cmnDQuadro, &pfWorker2);
      //имя и знак команды WL
      setNameIOWL(workerUniversal2, (char *)workCntr->twoString);

      return 1;
    }//COMPARE_COUNTER
  }//for


  return 1;

}//KadrMenuFormat_viewLE(WorkControl *workCntr)

void ClickOpenEditWL(UNS_32 *cmdLE)
{
  /*
//Получить адр ArrayWIDELOG конкр LE для редактирования
  short  findClon = -1; //найти клон для позиционирования
  //искать в cnf
  UNS_32 tmp=0;
  for(int i=0; i<3* 2*DQUADRO; i++) tmp|=cmdLE[i];
  UNS_32 cmdUnion[DQUADRO];
  memset(cmdUnion, 0, 4*DQUADRO);
  //соединить PRM
  for(int i=0; i<DQUADRO; i++) cmdUnion[i] |= cmdLE[i];
  //соединить MINUS
  for(int i=0; i<DQUADRO; i++) cmdUnion[i] |= cmdLE[i +2*DQUADRO];
  //соединить PLUS
  for(int i=0; i<DQUADRO; i++) cmdUnion[i] |= cmdLE[i +2*DQUADRO+2*DQUADRO];

  //посчитать к-во бит
  workerUniversal1 = 0;//данные для работника
  MultiBitWorkerHostQuadro(cmdUnion, &pfWorker1);
  short cntBitCnf = workerUniversal1;//к-во активных бит cnf
//найти к-во клонов в cnf
  short cntClonCnf = 0;
  while (cnfCOMPONENT[cntClonCnf].componentEnable)   //все компоненты в конфигурации cnf
  {
    cntClonCnf++;
  }//while

  workerUniversal2 = TxtStreamIdxKadr(CRR_TEXTSTREAM);
  if(workerUniversal2<cntBitCnf)
  {
    //найти индекс i-й активной команды cnf
    workerUniversal1 = 0;
    MultiBitWorkerHostQuadro(cmdUnion, &pfWorker2);

//найти клон для позиционирования cnf
    short next = 0;
    while (cnfCOMPONENT[next].componentEnable)   //все компоненты в конфигурации cnf
    {
      if(getOffsetIOCmdCnf(next)>workerUniversal2) break;
      next++;
    }//while
    findClon = next-1;
  }//if
  else
  {
    //искать в РЛ
    memset(cmdUnion, 0, 4*DQUADRO);
    //соединить PRM
    for(int i=0; i<DQUADRO; i++) cmdUnion[i] |= cmdLE[i +DQUADRO];
    //соединить MINUS
    for(int i=0; i<DQUADRO; i++) cmdUnion[i] |= cmdLE[i +2*DQUADRO +DQUADRO];
    //соединить PLUS
    for(int i=0; i<DQUADRO; i++) cmdUnion[i] |= cmdLE[i +2*DQUADRO+2*DQUADRO +DQUADRO];

    //посчитать к-во бит
    workerUniversal1 = 0;//данные для работника
    MultiBitWorkerHostQuadro(cmdUnion, &pfWorker1);
    //short cntBitWL = workerUniversal1;//к-во активных бит WL
    if(workerUniversal1)//к-во активных бит WL
    {
      workerUniversal2 -= cntBitCnf;//убрать биты cnf
      //найти индекс i-й активной команды WL
      workerUniversal1 = 0;
      MultiBitWorkerHostQuadro(cmdUnion, &pfWorker2);

      //найти клон для позиционирования WL
      short next = 0;
      while (cnfCOMPONENT_WL[next].componentEnable)   //все компоненты в конфигурации cnf
      {
        if(getOffsetIOCmdCnf_WL(next)>workerUniversal2) break;
        next++;
      }//while
      findClon = next-1;
      findClon += cntClonCnf;
    }//if(cntBitWL)
  }//else

//открыть редактирование ранжир
  LIGHTCLON = -1;//индекс откр компонента

//ф-ция переинит
//  CRR_TEXTSTREAM = &CONTROL_ERNG;
  SelectorTEXTCONTROL(&CONTROL_ERNG);//установить текущую ссылку на текстовый поток

//текущий sub_menu и будет его parent
  sub_menu_editwl[SUBDATA].Line2 = CRR_SUBMENU;

//  CRR_SUBMENU = sub_menu_editwl;//новый текущий submenu
   SelectorSUBMENU(sub_menu_editwl);//уcтановить текущее субменю

  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_openEditWL, NULL);//инит управл структ и формир кадра
  if(findClon>0)
    TxtStreamSetIdxKadr(CRR_TEXTSTREAM, findClon);//установка номера текущего кадра

  ViewDiskrMenu(typeMenuEditWL);//вывести окно отображения
  ListPStr();//размещение указателя строки

  FvmenuDis->TipPanel->Visible = true;
  ViewTipPanel(1);//панель подсказки TipPanel
  */
}//ClickOpenEditWL(UNS_32 *cmdLE)

short  KadrMenuFormat_openEditWL(void *pstr)
{
  WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    short next = 0;
    short nextWL = 0;
    while (cnfCOMPONENT[next].componentEnable)   //все компоненты в конфигурации
    {
      next++;
    }//while

    while (cnfCOMPONENT_WL[nextWL].componentEnable)   //все компоненты в конфигурации РЛ
    {
      nextWL++;
    }//while

    if(next==0)
    {
      strcpy((char *)workCntr->twoString, "Конфигурация");
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "пустая");
      if(i==1)break;
    }//if
    else
    {
      if(i==(next+ nextWL)) break;
    }//else

    COMPARE_COUNTER
    {
      if(i<next)//(next!=0)&&)
      {
        strcpy((char *)workCntr->twoString, cnfCOMPONENT[i].nameComponent);
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    Раздел");
      }//if
      else
      {
        //показать разделы РЛ
        strcpy((char *)workCntr->twoString, cnfCOMPONENT_WL[i-next].nameComponent);
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "  Раздел РЛ");
      }
      return 1;//сравнить счетчики кадров
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat_openEditWL(WorkControl *workCntr)

void WLRedactor(short cmdPosition)
{
  /*
//редактировать ранжирование
  char txtName[50];
  FvmenuDis->EditWLPanel->Visible = true;
  FvmenuDis->ConfirmRangPanel->Visible = false;
  //имя знак и состояние команды LE
  short znak = setNameIOWL(cmdPosition, txtName);//имя и знак команды WL
  switch(znak)
  {
  case 0:
    //выход
    FvmenuDis->PRMRadio->Checked = false;
    FvmenuDis->MINUSRadio->Checked = false;
    FvmenuDis->PLUSRadio->Checked = false;
    FvmenuDis->OTKLRadio->Checked = true;
    break;
  case 1:
    //прямой вход
    FvmenuDis->PRMRadio->Checked = true;
    FvmenuDis->MINUSRadio->Checked = false;
    FvmenuDis->PLUSRadio->Checked = false;
    FvmenuDis->OTKLRadio->Checked = false;
    break;
  case 2:
    //инв вход
    FvmenuDis->PRMRadio->Checked = false;
    FvmenuDis->MINUSRadio->Checked = true;
    FvmenuDis->PLUSRadio->Checked = false;
    FvmenuDis->OTKLRadio->Checked = false;
    break;
  case 3:
    //выход
    FvmenuDis->PRMRadio->Checked = false;
    FvmenuDis->MINUSRadio->Checked = false;
    FvmenuDis->PLUSRadio->Checked = true;
    FvmenuDis->OTKLRadio->Checked = false;
    break;
  default:
    ;
  }//switch

  FvmenuDis->EditWLLabel->Caption = txtName;
  */
}//WLRedactor()

void ClickProcessEditWL()
{
//начать редактирование РЛ
  int isCLONWL = 0;//флаг клона РЛ
//  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);//текущий кадр
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока

  if( LIGHTCLON >= MARKCLON_WL)
  {
    LIGHTCLON -= MARKCLON_WL;
    isCLONWL = 1;//флаг клона РЛ
  }//if

  short next = 0;
  while (cnfCOMPONENT[next].componentEnable)   //все компоненты в конфигурации
  {
    next++;
  }//while

  short cmdPosition =0;
  for(short i=0; i<1; i++)
  {

    if(isCLONWL)
    {
      //клон РЛ
      LIGHTCLON = LIGHTCLON + next;
    }//if

    if(LIGHTCLON<0)//индекс откр компонента
    {
      //первый выбор клона
      LIGHTCLON = LIGHTLINEMENU;//индекс откр компонента
      break;
    }//if

    if(
      LIGHTLINEMENU <  LIGHTCLON)
    {
      //выбор до откр клона
      LIGHTCLON = LIGHTLINEMENU;//индекс откр компонента
      break;
    }//if

    if(
      LIGHTLINEMENU >( LIGHTCLON+ RANG_CNTOPEN_CMD-1))
    {
      //выбор после откр клона
      LIGHTCLON = LIGHTLINEMENU - RANG_CNTOPEN_CMD+1;
      break;
    }//if

    if(isCLONWL)//флаг клона РЛ
    {
      cmdPosition = //позиция выбранной команды в табл ранж
        getOffsetIOCmdCnf_WL(LIGHTCLON-next) +
        LIGHTLINEMENU - LIGHTCLON +SIZE_RANGIRCMD;
      LIGHTCLON = LIGHTCLON + MARKCLON_WL - next;//маркер клона РЛ
    }//if(isCLONWL)//флаг клона РЛ
    else
    {
      cmdPosition = //позиция выбранной команды в табл ранж
        getOffsetIOCmdCnf(LIGHTCLON) +
        LIGHTLINEMENU - LIGHTCLON;
    }//else
    RANG_BIT =  cmdPosition ;//позиция выбранной команды в табл ранж
    WLRedactor(cmdPosition);//редактировать РЛ
    return;
  }//for

  int numClon = LIGHTCLON;
  if(LIGHTCLON>=next)
  {
    //клоны РЛ
    RANG_CNTOPEN_CMD = cnfCOMPONENT_WL[numClon-next].cntIOCmd;//к-во открытых строк IO команд
    //маркер клона РЛ
    LIGHTCLON = MARKCLON_WL +LIGHTCLON-next;
  }//if
  else
    RANG_CNTOPEN_CMD = cnfCOMPONENT[LIGHTCLON].cntIOCmd;//к-во открытых строк IO команд

  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_prc_editWL, NULL);//инит управл структ и формир кадра
  TxtStreamSetIdxKadr(CRR_TEXTSTREAM, numClon);//установка номера текущего кадра

  ViewDiskrMenu(typeMenuEditRang);//вывести окно отображения
  ListPStr();//размещение указателя строки

}//ClickProcessEditWL()

short  KadrMenuFormat_prc_editWL(void *pstr)
{
  WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
//процесс редактирования широкой табл ранжир
  //char  locTxt[20];
  short next = 0;
  short nextWL = 0;
  short cntKadr = 0;//к-во кадров

  short numCloseComp = 0;//закр компоненты
  while (cnfCOMPONENT[next].componentEnable)   //все компоненты в конфигурации
  {
    next++;
  }//while

  while (cnfCOMPONENT_WL[nextWL].componentEnable)   //все компоненты в конфигурации РЛ
  {
    nextWL++;
  }//while

  cntKadr = nextWL+ next+ RANG_CNTOPEN_CMD-1;//к-во кадров

  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    if(i==cntKadr) break;

    int numClon = 0;//LIGHTCLON;
    if(LIGHTCLON<MARKCLON_WL) numClon = LIGHTCLON;
    else numClon = LIGHTCLON -MARKCLON_WL +next;

    COMPARE_COUNTER
    {
      if(i<  numClon)
        numCloseComp = i;
      if(i>( numClon   + RANG_CNTOPEN_CMD -1))
        numCloseComp = i- RANG_CNTOPEN_CMD+1;
      if(i<  numClon || i>( numClon + RANG_CNTOPEN_CMD-1))
      {
        if(numCloseComp>=next)
        {
          //Разделы РЛ
          strcpy((char *)workCntr->twoString, cnfCOMPONENT_WL[numCloseComp-next].nameComponent);
          strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "  Раздел РЛ");
        }
        else
        {
          strcpy((char *)workCntr->twoString, cnfCOMPONENT[numCloseComp].nameComponent);
          strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    Раздел");
        }
      }//if(i<  LIGHTCLON || i>(LIGHTCLON + RANG_CNTOPEN_CMD-1))
      else{
        short cmdPosition  = 0;//позиция выбранной команды в табл ранж
        if(LIGHTCLON<MARKCLON_WL)
        {
          //команды клона из конфиг
          cmdPosition  = i- LIGHTCLON + getOffsetIOCmdCnf(numClon);
        }//if(LIGHTCLON<MARKCLON_WL)
        else{
          //команды клона из РЛ
          cmdPosition  = i+ SIZE_RANGIRCMD -numClon + getOffsetIOCmdCnf_WL(numClon-next);
        }//else

        if(setNameIOWL(cmdPosition, (char *)workCntr->twoString))//имя и знак команды WL
        {
          strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    Вкл");
        }//if
        else
        {
          strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    Откл");
        }

      }//else

      return 1;
    }//COMPARE_COUNTER


  }//for

  return 1;
}//KadrMenuFormat_prc_editWL(WorkControl *workCntr)

void setComonDQuadro(UNS_32* cmnDQuadro)
{
//заполнить общий dquadro
  UNS_32 *tmp1 = MngWLGetLEWLtoEdit_PRM(LIGHTRANGUVV);
  memset(cmnDQuadro, 0, DQUADRO*4*2);//обнулить
  //общий dquadro для прямых инверс и плюсовых
  for(int i=0; i<2*DQUADRO; i++) cmnDQuadro[i] |= (tmp1[i]|tmp1[i+DQUADRO*2]|tmp1[i+DQUADRO*2+DQUADRO*2]);
}//setComonDQuadro(UNS_32* cmnDQuadro)

short setNameIOWL(int cmdPosition, char *strIO)
{
//имя и знак команды WL
  //имя команды
  char tmpName[50];
  strcpy(tmpName,
         nameStatusRANGIR[
           cmdPosition
         ].nameIORang
        );

  strcpy(strIO, "");
  //знак команды LE
  short znak=SetConditionCmdPositionLE(cmdPosition);
  if(znak==2)strcpy(strIO, "- ");
  if(znak==3)strcpy(strIO, "+ ");
  strcat(strIO, tmpName);//дополнить знак именем
  return znak;
}//setNameIOWL(int cmdPosition, char *strIO)

short SetConditionCmdPositionLE(short cmdPosition)
{
  //знак команды LE
  UNS_32*tmp1 =  MngWLGetLEWLtoEdit_PRM(LIGHTRANGUVV);//массив LE
  short znak=0;
  //найти знак команды
  //найти плюс
  if(NumBitCheckWL(cmdPosition, &(tmp1[DQUADRO*2+DQUADRO*2])))
  {
    //есть плюс
    znak = 3;//знак команды
  }//if

  //найти минус
  if(NumBitCheckWL(cmdPosition, &(tmp1[DQUADRO*2])))
  {
    //есть минус
    znak = 2;//знак команды
  }//if

  if(NumBitCheckWL(cmdPosition, tmp1))
  {
    //есть prm
    znak = 1;//знак команды
  }//if

  return znak;//знак команды
}//SetConditionCmdPositionLE(cmdPosition)

void  ClickEditWLOKButton()
{
  /*
//редактировать РЛ
//установить команду на LE
//  UNS_32 *prm =  MngWLGetLEWLtoEdit_PRM(LIGHTRANGUVV);//массив LE
//MngWLGetPointerLEWLtoEdit_PRM(LIGHTRANGUVV);//массив LE
  if(FvmenuDis->PRMRadio->Checked)
    SetLEToClon(RANG_BIT, LIGHTRANGUVV, typeCmd_PRM);
  if(FvmenuDis->PLUSRadio->Checked)
    SetLEToClon(RANG_BIT, LIGHTRANGUVV, typeCmd_PLUS);
  if(FvmenuDis->MINUSRadio->Checked)
    SetLEToClon(RANG_BIT, LIGHTRANGUVV, typeCmd_MINUS);
  if(FvmenuDis->OTKLRadio->Checked)
    SetLEToClon(RANG_BIT, LIGHTRANGUVV, typeCmd_DIS);

  isRangRedactor = 2;//было ли редактировано РЛ

  ViewTipPanel(1);
  */
}//ClickEditRangOKButton()

void  FinishEditWL(int isOK)
{
//сохранить и завершить редактир РЛ
  isRangRedactor = 0;//было ли редактировано ранжир
  if(isOK)
    MngWLEndingEditArrayWIDELOG();//Сохр изменения в массиве ранжир
  MngWideLogPrepareArrayWIDELOGtoEdit();//Подготовить ArrayWIDELOG к редактированию
  TxtStreamInit(&CONTROL_EWL, &KadrMenuFormat_viewLE, NULL);//новое к-во команд на LE
}//FinishEditRang()

void PereinitCnfWL(short flg)
{
//переинит конфигурации РЛ
  TxtStreamInit(&CONTROL_CNFWL,
                &KadrMenuFormat_sub, sub_menu_cnfwl);//инит control и формир кадра

  PNTCRR_TEXTSTREAM->PntStringViewer = 0;
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_CNFWL, SIZE_PAGE_VIEW);//перейти на END
  }//if
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
  LanderPStr();//размещение указателя строки
}//PereinitCnfWL()

void OpenMenuCnfWL()
{
//открыть меню cnf РЛ
  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control

//  CRR_TEXTSTREAM = &CONTROL_CNFWL;//новый текущий control
  SelectorTEXTCONTROL(&CONTROL_CNFWL);//установить текущую ссылку на текстовый поток
  PereinitCnfWL(1);//ф-ция переинит конфигурации
//  CRR_FHOME = &PereinitCnfWL;//указатель на ф-цию HOME
  SelectorFHOME(&PereinitCnfWL);//указатель на ф-цию HOME
}//OpenMenuCnf()

void  ConfigMakerWL()
{
  /*
//заполнить конфигурацию
//  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);//индекс тек кадра
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  short numK = GetKodCompRpzWL(LIGHTLINEMENU);//получить из номера строки репозитария РЛ код компонента

  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_cnfwl;// parent
//  CRR_SUBMENU = sub_menu_tmp;//текущее субменю
  SelectorSUBMENU(sub_menu_tmp);//уcтановить текущее субменю

  AddCompIzRpz_WL(numK);//добавить компонент из репозитария в РЛ

  FvmenuDis->Str1Label->Caption = "Компонент";
  FvmenuDis->Str2Label->Caption = (char *)sub_menu_cnfwl[1+SUBDATA].Line1;
  FvmenuDis->Str3Label->Caption = "добавлен";
  FvmenuDis->Str4Label->Caption = "";

  ResetAllButton();//погасить все клавиши
*/
}//ConfigMaker()

short GetKodCompRpzWL(short numL)
{
//получить из номера строки репозитария код компонента
  char ltxt[50];
  strcpy(ltxt, (char *)sub_menu_rpzWL[numL+1+SUBDATA].Line1);
  //мл и ст части кода компонента
  char lowK = ((char *)(sub_menu_rpzWL[numL+1+SUBDATA].Line1))[-2];
  char hiK = ((char *)(sub_menu_rpzWL[numL+1+SUBDATA].Line1))[-1];
  return lowK + 256*hiK;
}//GetKodCompRpzWL(short numL)

void  AddCompIzRpz_WL(short numK)
{
//добавить компонент из репозитария в РЛ
  addCOMPONENT_WL(numK);//Добавить компонент с кодом numK в конфигурацию РЛ

  if( LIGHTISDENIE ||//запрещено
      LIGHTISPACKET);//это пакет
  else
  {
//инициализировать клон компонента РЛ
//если не пакет
    initCOMPONENT_WL(INITUST_TOPCOMP);
    MakeEmptyTopSub_menu(sub_menu_cnfwl,
                         MAX_WLCOMPONENT*sizeof(LineMenuItem));//добавить пустую запись в top sub_menu
//новый клон в список
    sub_menu_cnfwl[1+SUBDATA].Line2 = (void *)&OpenMenuComponent_WL; //меню компонента
    sub_menu_cnfwl[1+SUBDATA].TypesWin = typeMenuProg;
  }//else

  PrepareAllCnfComponent_WL();//подготовить все компоненты в конфигурации РЛ
}//AddCompIzRpz_WL()

