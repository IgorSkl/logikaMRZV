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
#include "virtualMenu\textstreamdef.h"
#include "virtualMenu\systemmenudef.h"

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"

#include "virtualMenu\repozitfnc.h"
#include "virtualMenu\viewMenuSub.h"

#include "..\bazis.h"

extern LineMenuItem sub_menu_tmp[];
extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария

//массив клонов - конфигурация
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ  cnfCOMPONENT_WL[];
extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_cnfwl[];
extern LineMenuItem sub_menu_rpz[];

char addComp[] = "Добавить компонент...";
char deleteComp[] = "Удалить компонент...";
char deleteComp_WL[] = "Удалить из РЛ...";

void ResetConfig()
{
//обнулить конфиграцию
  cnfCOMPONENT[0].componentEnable = 0;
  sub_menu_cnf[1+SUBDATA].Line1 = addComp;
  sub_menu_cnf[1+SUBDATA].Line2 = (void*)RpzComponent;
  sub_menu_cnf[1+SUBDATA].TypesWin = typeMenuProg;

  sub_menu_cnf[1+1+SUBDATA].Line1 = NULL;
  sub_menu_cnf[1+1+SUBDATA].Line2 = NULL;
}//ResetConfig()

void PereinitCnf(short flg)
{
//переинит конфигурации
  TxtStreamInit(&CONTROL_CNF,
                &KadrMenuFormat_sub, sub_menu_cnf);//инит control и формир кадра

  PNTCRR_TEXTSTREAM->PntStringViewer = 0;
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_CNF, SIZE_PAGE_VIEW);//перейти на END
  }//if
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
  LanderPStr();//размещение указателя строки
}//PereinitCnf()

void OpenMenuCnf()
{
//открыть меню cnf
  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control

//  CRR_TEXTSTREAM = &CONTROL_CNF;//новый текущий control
  SelectorTEXTCONTROL(&CONTROL_CNF);//новый текущий control
  PereinitCnf(1);//ф-ция переинит конфигурации
//  CRR_FHOME = &PereinitCnf;//указатель на ф-цию HOME
  SelectorFHOME(&PereinitCnf);//указатель на ф-цию HOME
}//OpenMenuCnf()

void PereinitAvaitCnf(short flg)
{
//переиниц
  TxtStreamInit(&CONTROL_RPZ, &KadrMenuFormat_sub, sub_menu_rpz);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_RPZ, SIZE_PAGE_VIEW);//перейти на END
  }//if
  ViewDiskrMenu(typeMenuCnf);//вывести окно отображения
  LanderPStr();//размещение указателя строки
}//PereinitAvaitCnf()

short SearchCnfClonComponent(short kC)
{
//искать в cnf к-во клонов данного компонента
  short next = 0;
  short cntC = 0;//к-во клонов компонента
  while (cnfCOMPONENT[next].componentEnable)   //все компоненты в конфигурации
  {
    if(cnfCOMPONENT[next].kodC==kC) cntC++;
    next++;
  }//while
  return cntC;
}//SearchCnfClonComponent(short kC)

short SearchCnfClonToComponent(short kC, short nC)
{
//искать в cnf данный клон данного компонента
  short next = 0;
  short idxC = -1;//индекс компонента в cnf
  while (cnfCOMPONENT[next].componentEnable)   //все компоненты в конфигурации
  {
//   short tt1 = cnfCOMPONENT[next].kodC;
//   short tt2 = cnfCOMPONENT[next].numClon;
    if(cnfCOMPONENT[next].kodC==kC && cnfCOMPONENT[next].numClon==nC )
      idxC = next;
    next++;
  }//while
  return idxC;
}//SearchCnfClonToComponent(short kC, short nC)

short SearchCnfClonToComponent_WL(short kC, short nC)
{
//искать в cnf РЛ данный клон данного компонента
  short next = 0;
  short idxC = -1;//индекс компонента в cnf
  while (cnfCOMPONENT_WL[next].componentEnable)   //все компоненты в конфигурации
  {
//   short tt1 = cnfCOMPONENT[next].kodC;
//   short tt2 = cnfCOMPONENT[next].numClon;
    if(cnfCOMPONENT_WL[next].kodC==kC && cnfCOMPONENT_WL[next].numClon==nC )
      idxC = next;
    next++;
  }//while
  return idxC;
}//SearchCnfClonToComponent_WL(short kC, short nC)

void  ConfigMaker()
{
  /*
//заполнить конфигурацию
//  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);//индекс тек кадра
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  short numK = GetKodCompRpz(LIGHTLINEMENU);//получить из номера строки репозитария код компонента

  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_cnf;// parent
//  CRR_SUBMENU = sub_menu_tmp;//текущее субменю
  SelectorSUBMENU(sub_menu_tmp);//уcтановить текущее субменю

  AddCompIzRpz(numK);//добавить компонент из репозитария

  FvmenuDis->Str1Label->Caption = "Компонент";
  FvmenuDis->Str2Label->Caption = (char *)sub_menu_cnf[1+SUBDATA].Line1;
  FvmenuDis->Str3Label->Caption = "добавлен";
  FvmenuDis->Str4Label->Caption = "";

  ResetAllButton();//погасить все клавиши
*/
}//ConfigMaker()
/*
void __fastcall TFvmenuDis::ConfirmDeleteButtonClick(TObject *Sender)
{
  ConfirmDeleteButton();
  ResetUpDown(); //погасить Up Down
}//ConfirmDeleteButton(TObject *Sender)

void __fastcall TFvmenuDis::ConfirmDeleteButtonWLClick(TObject *Sender)
{
  ConfirmDeleteButton_WL();//удалить из РЛ
  ResetUpDown(); //погасить Up Down
}//ConfirmDeleteButtonWLClick(TObject *Sender)
*/
void newsub_menu_cnf_Line1()
{
//новые имена меню cnf
//в меню cnf присутствуют только имена тех клонов поле.packet которых или=0 или<0
/*
  short i=1+SUBDATA;//2;
  short dx=0;
  while(cnfCOMPONENT[dx].componentEnable)
  {
    if(cnfCOMPONENT[dx].packet==0)
    {
      sub_menu_cnf[i].Line1 = cnfCOMPONENT[dx].nameComponent;
      i++;
    }//if
    if(cnfCOMPONENT[dx].packet<0) //начало пакета
    {
      short ii=0;//искать имя пакета
      while(cnfCOMPONENT[dx].nameComponent[ii]!=0)
      {
        ii++;
      }
      ii++;
      sub_menu_cnf[i].Line1 = &(cnfCOMPONENT[dx].nameComponent[ii]);
      i++;
    }//if
    dx++;
  }//while
*/
}//newsub_menu_cnf_Line1()

short GetFromLinToClonCnf(short lin)
{
//получить из номера линии номер клона для cnf
/*
  short dx=0;//индекс текущего клона
  short tmpCnfLin = lin;
  short bazaPkt=0;
  short pkt=0;
  short cntNoPkt=0;//к-во непакетов
  short nC=0;//номер клона

  //считать пакетную базу
  while (cnfCOMPONENT[dx].componentEnable)   //все компоненты в конфигурации
  {
    pkt = cnfCOMPONENT[dx].packet;
    if(pkt<0)
    {
      tmpCnfLin--;
      if(tmpCnfLin>=0)
        bazaPkt += -pkt;
    }//if
    if(pkt==0)
    {
      tmpCnfLin--; //if
    }

    if(tmpCnfLin<0) break;
    dx++;
  }//while

  tmpCnfLin=lin;
  dx=0;
  //считать непакеты
  while (cnfCOMPONENT[dx].componentEnable)   //все компоненты в конфигурации
  {
    pkt = cnfCOMPONENT[dx].packet;
    if(pkt<0)
    {
      tmpCnfLin--; //if
    }
    if(pkt==0)
    {
      tmpCnfLin--;
      if(tmpCnfLin>=0) cntNoPkt++;
    }//if

    if(tmpCnfLin<0) break;
    dx++;
  }//while

  nC= bazaPkt+cntNoPkt;//номер клона

  return nC;
*/
 return 0;
}//GetFromLinToClonCnf(short lin)

short GetFromLinToClonCnf_WL(short lin)
{
/*
//получить из номера линии номер клона для cnf РЛ
  short dx=0;//индекс текущего клона
  short tmpCnfLin = lin;
  short bazaPkt=0;
  short pkt=0;
  short cntNoPkt=0;//к-во непакетов
  short nC=0;//номер клона

  //считать пакетную базу
  while (cnfCOMPONENT_WL[dx].componentEnable)   //все компоненты в конфигурации
  {
    pkt = cnfCOMPONENT_WL[dx].packet;
    if(pkt<0)
    {
      tmpCnfLin--;
      if(tmpCnfLin>=0)
        bazaPkt += -pkt;
    }//if
    if(pkt==0)
    {
      tmpCnfLin--; //if
    }

    if(tmpCnfLin<0) break;
    dx++;
  }//while

  tmpCnfLin=lin;
  dx=0;
  //считать непакеты
  while (cnfCOMPONENT_WL[dx].componentEnable)   //все компоненты в конфигурации
  {
    pkt = cnfCOMPONENT_WL[dx].packet;
    if(pkt<0)
    {
      tmpCnfLin--; //if
    }
    if(pkt==0)
    {
      tmpCnfLin--;
      if(tmpCnfLin>=0) cntNoPkt++;
    }//if

    if(tmpCnfLin<0) break;
    dx++;
  }//while

  nC= bazaPkt+cntNoPkt;//номер клона

  return nC;
*/
 return 0;
}//GetFromLinToClonCnf_WL(short lin)

short GetFromLinToClonPkt(short Lin)
{
/*
//получить из номера линии номер клона для пакета
  //индекс текущего клона
  short dx=0;
  short bazaPkt=0;
  short pkt=0;
  short cntNoPkt=0;//к-во непакетов
  short shiftPkt = 0;//смещение внутри пакета
  short nC=0;//номер клона

  short cnfLin = TxtStreamIdxKadr(&CONTROL_CNF);//кадр конфигурации
  short tmpCnfLin = cnfLin;

  shiftPkt = Lin;//смещение внутри пакета
  //считать пакетную базу
  while (cnfCOMPONENT[dx].componentEnable)   //все компоненты в конфигурации
  {
    pkt = cnfCOMPONENT[dx].packet;
    if(pkt<0)
    {
      tmpCnfLin--;
      if(tmpCnfLin>=0)
        bazaPkt += -pkt;
    }//if
    if(pkt==0)
    {
      tmpCnfLin--; //if
    }

    if(tmpCnfLin<0) break;
    dx++;
  }//while

  tmpCnfLin=cnfLin;//кадр конфигурации
  dx=0;
  //считать непакеты
  while (cnfCOMPONENT[dx].componentEnable)   //все компоненты в конфигурации
  {
    pkt = cnfCOMPONENT[dx].packet;
    if(pkt<0)
    {
      tmpCnfLin--; //if
    }
    if(pkt==0)
    {
      tmpCnfLin--;  //if
      cntNoPkt++;
    }

    if(tmpCnfLin<0) break;
    dx++;
  }//while


  nC= bazaPkt+cntNoPkt +shiftPkt;//номер клона
  return nC;
*/
 return 0;
}//

void newsub_menu_cnfwl_Line1()
{
//новые имена меню cnfwl
//в меню cnf присутствуют только имена тех клонов поле.packet которых или=0 или<0
  short i=1+SUBDATA;
  short dx=0;
  while(cnfCOMPONENT_WL[dx].componentEnable)
  {
    if(cnfCOMPONENT_WL[dx].packet==0)
    {
      sub_menu_cnfwl[i].Line1 = cnfCOMPONENT_WL[dx].nameComponent;
      i++;
    }//if
    if(cnfCOMPONENT_WL[dx].packet<0) //начало пакета
    {
      short ii=0;//искать имя пакета
      while(cnfCOMPONENT_WL[dx].nameComponent[ii]!=0)
      {
        ii++;
      }
      ii++;
      sub_menu_cnfwl[i].Line1 = &(cnfCOMPONENT_WL[dx].nameComponent[ii]);
      i++;
    }//if
    dx++;
  }//while
}//newsub_menu_cnfwl_Line1()


