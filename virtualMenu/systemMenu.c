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

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\wideLogManagerfnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\ustmanagerfnc.h"

#include "virtualMenu\viewMenuList.h"
#include "virtualMenu\viewMenuSub.h"
#include "virtualMenu\viewMenuWideLog.h"
#include "virtualMenu\viewMenuRang.h"
#include "virtualMenu\viewMenuCnf.h"
#include "virtualMenu\viewMenuReg.h"
#include "psuperVisor\psupervisor.h"
#include "virtualMenu\viewMenuTip.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

extern char addComp[];
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ  cnfCOMPONENT_WL[];

extern char deleteComp[];
extern char deleteComp_WL[];
extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария

extern LineMenuItem sub_menu_dv[];
extern LineMenuItem sub_menu_rele[];
extern LineMenuItem sub_menu_logw[];
extern LineMenuItem sub_menu_le[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_cnfwl[];
extern LineMenuItem sub_menu_tmp[];
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

extern UNS_32 selectorUVVLow;//селекция UVV активный-неактивный для мл 16 UVV
extern UNS_32 selectorUVVMidd;//селекция UVV активный-неактивный для cp 16 UVV
extern UNS_32 selectorUVVHi;//селекция UVV активный-неактивный для ct 16 UVV

typedef void (* pFunction());//указатель на ф-цию

MENU_CONTEXT menu_context;

extern char stringList[48][32];//массив строк для просмотра

void ViewDiskrMenu(short typeWin)
{
//вывести страницу
//типажи
  switch(typeWin)
  {
  case typeMenuReg:
  case typeMenuList:
  case typeMenuEditRang:
  case typeMenuEditWL:
    ViewDiskrMenuList();//вывести страницу List
    break;
  case typeMenuViewLE:
  case typeMenuViewRangDV:
  case typeMenuViewRangRele:
  case typeMenuViewRangCDI:
  case typeMenuViewActual:
  case typeMenuViewActualDV:
  case typeMenuViewActualRele:
  case typeMenuViewRDISMaska:
  case typeMenuViewAPVMaska://Пуск АПВ
  case typeMenuViewUROVMaska://Пуск УРОВ
  case typeMenuViewP1OFMaska://маска 1 ОФ
  case typeMenuViewP2OFMaska://маска 2 ОФ
  case typeMenuViewP3OFMaska://маска 3 ОФ
  case typeMenuCnf:
  case typeMenuCnfWL:
  case typeMenuSub:
    ViewDiskrMenuSub();//вывести страницу View
    break;
  }//switch
}//ViewDiskrMenu()


void SetCloseButton()
{
//close
  if(PNTCRR_SUBMENU(SUBDATA).Line2==NULL) return;//parent sub_menu не существует

  //CRR_SUBMENU = 
  SelectorSUBMENU(PNTCRR_SUBMENU(SUBDATA).Line2);//новый текущий submenu
  short typeWin = PNTCRR_SUBMENU(SUBDATA).TypesWin;
  if(typeWin==typeMenuSub)
  {
    CRR_FHOME = &PereinitSub;//указатель на ф-цию HOME
    ResetUpDown();//погасить Up Down
  }//if

  //CRR_TEXTSTREAM = 
  SelectorTEXTCONTROL(PNTCRR_SUBMENU(SUBDATA).Line1);
  PNTCRR_TEXTSTREAM->PntStringViewer =0;//указател строки

  ShowTitleSubmenu_crr();//заголовок текущего Submenu
  ViewDiskrMenu(typeWin);//вывести окно отображения

  if(typeWin!=typeMenuList) LanderPStr();//размещение указателя строки
  else ListPStr();//размещение указателя строки
}//SetCloseButton()

void ClickOpenButton()
{
//открыть меню
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  //текущий linemenu
  LineMenuItem  crr_linemenu = PNTCRR_SUBMENU(
                                 LIGHTLINEMENU +1+SUBDATA
                               );
  if(crr_linemenu.Line2==NULL) return; //следующ меню нет

  //CRR_SUBMENU = 
  SelectorSUBMENU(crr_linemenu.Line2);//новый текущий submenu

  //флаги типажа
  short typeWin = crr_linemenu.TypesWin;
  if(!(typeWin==typeMenuProg))// || typeWin==typeMenuPassW))
  {
    PNTCRR_SUBMENU(SUBDATA).TypesWin = typeWin;//parent_type
  }//if

  switch(typeWin)
  {
  case typeMenuViewLE:
    OpenViewLE();//открыть ViewLE
    break;
  case typeMenuViewActual:
    OpenMenuViewActual();//открыть меню Текущие
    ResetPStr();
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewActualDV:
    OpenMenuViewActualDV();//открыть меню Текущие DV
    ResetPStr();
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewActualRele:
    OpenMenuViewActualRele();//открыть меню Текущие Rele
    ResetPStr();
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewRDISMaska:
    OpenMenuViewRDIS();//открыть меню RDIS
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewAPVMaska://Пуск АПВ
    OpenMenuViewAPV();//открыть меню APV
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewUROVMaska://Пуск УРОВ
    OpenMenuViewUROV();//открыть меню UROV
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewP1OFMaska://маска 1 ОФ
    OpenMenuViewP1OF();//открыть меню P1OF
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewP2OFMaska://маска 2 ОФ
    OpenMenuViewP2OF();//открыть меню P2OF
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewP3OFMaska://маска 3 ОФ
    OpenMenuViewP3OF();//открыть меню P3OF
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewRangDV:
    OpenMenuViewRangDV();//открыть меню ViewRang
    break;
  case typeMenuViewRangRele:
    OpenMenuViewRangRele();//открыть меню ViewRang
    break;
  case typeMenuViewRangCDI:
    OpenMenuViewRangCDI();//открыть меню ViewRang
    break;
  case typeMenuCnf:
    OpenMenuCnf();//открыть меню cnf
    break;
  case typeMenuCnfWL:
    OpenMenuCnfWL();//открыть меню cnf РЛ
    break;
  case typeMenuReg:
    OpenMenuReg();//открыть меню reg
    ResetPStr();
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuProg:  //открыть меню prog
    TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
    (*(pFunction *)CRR_SUBMENU)();//переход на программу ф-ции
    break;
  case typeMenuSub:
    OpenMenuSub();//открыть меню Sub
    break;
  }//switch

  ShowTitleSubmenu_crr();//заголовок текущего Submenu
}//ClickOpenButton()

void JumpAndOpen(short step)
{
//перейти и открыть
//типажи
  short typeWin = PNTCRR_SUBMENU(SUBDATA).TypesWin;//текущий submenu
  switch(typeWin)
  {
  case typeMenuEditRang:
    PNTCRR_TEXTSTREAM->PntStringViewer =step/2;//указател строки
    ClickProcessEditRang();//начать редактирование ранжир
    return;
  case typeMenuViewLE:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//указател строки
    ClickOpenEditWL(MngWLGetLEWLtoEdit_PRM(LIGHTRANGUVV));//открыть редактирование РЛ
    return;
  case typeMenuEditWL:
    PNTCRR_TEXTSTREAM->PntStringViewer =step/2;//указател строки
    ClickProcessEditWL();//начать редактирование ранжир
    return;
  case typeMenuViewRangDV:
  case typeMenuViewRangRele:
  case typeMenuViewRangCDI:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//указател строки
    PassWord(OpenEditRangUVV);
    return;

  case typeMenuViewRDISMaska:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//указател строки
    ClickOpenEditRang(pRDIScmdMaska);//открыть редактирование РегистрацияДИС
    return;
  case typeMenuViewAPVMaska:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//указател строки
    ClickOpenEditRang(pAPVcmdMaska);//открыть редактирование APV
    return;
  case typeMenuViewUROVMaska:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//указател строки
    ClickOpenEditRang(pUROVcmdMaska);//открыть редактирование UROV
    return;
/*
  case typeMenuViewP1OFMaska:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//указател строки
    ClickOpenEditRang(pP1OFcmdMaska);//открыть редактирование P1OF
    return;
  case typeMenuViewP2OFMaska:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//указател строки
    ClickOpenEditRang(pP2OFcmdMaska);//открыть редактирование P2OF
    return;
  case typeMenuViewP3OFMaska:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//указател строки
    ClickOpenEditRang(pP3OFcmdMaska);//открыть редактирование P3OF
    return;
*/

  case typeMenuSub:
  case typeMenuCnf:
  case typeMenuCnfWL:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//указател строки
    break;

  case typeMenuList:
    PNTCRR_TEXTSTREAM->PntStringViewer =step/2;//указател строки
    break;

  default:
    return;
  }//switch
  ClickOpenButton();//открыть меню
}//JumpAndOpen(short step)

void OpenEditRangUVV()
{
//режим редактирования ранжир
    ClickOpenEditRang(MngRangGetPointerUVVRANGIRtoEdit(LIGHTRANGUVV));//открыть редактирование ранжир
}//OpenEditRangUVV()

void ShowTitleSubmenu_crr()
{
//заголовок текущего Submenu
//  char *title = (char *)PNTCRR_SUBMENU(0).Line1;//текущий submenu
//  FvmenuDis->TitleLabel->Caption = title;
}//ShowTitleSubmenu_crr()

void MakeEmptyTopSub_menu(void *pstr, short size)
{
  LineMenuItem *src = (LineMenuItem *)pstr;
//добавить пустую запись в top sub_menu
  //копировать в тень
  memcpy((void*)getShadowBuf(), (void *)src, size);
//копировать из тени End
  memcpy(&(src[1+ 1+SUBDATA]),
         &(((LineMenuItem *)getShadowBuf())[1+ SUBDATA]),
         size-(3*sizeof(LineMenuItem)));
}//MakeEmptyTopSub_menu()

void New_name_clon(short kc, char *name)
{
//новые имена клонов
//найти общее к-во клонов
  short dx=0;
  short numClonOF=0;
  while(cnfCOMPONENT[dx].componentEnable)
  {
    if(cnfCOMPONENT[dx].kodC==OF_COMP1)
    {
      numClonOF++;
      cnfCOMPONENT[dx].numClon = numClonOF;
    }//if
    dx++;
  }//while

  char str_tmp[50];// = "ОФ";
  char locTxt[20];
  dx=0;
  while(cnfCOMPONENT[dx].componentEnable)
  {
    if(cnfCOMPONENT[dx].kodC==kc)
    {
      strcpy(str_tmp, name);
      sprintf(locTxt, "0%d.", numClonOF);
      strcpy(cnfCOMPONENT[dx].nameComponent, locTxt);
      strcat(cnfCOMPONENT[dx].nameComponent, str_tmp);
      numClonOF--;
    }//if
    dx++;
  }//while

}//New_name_clon()

void New_name_clon_WL(short kc, char *name)
{
//новые имена клонов
//найти общее к-во клонов
  short dx=0;
  short numClonOF=0;
  while(cnfCOMPONENT_WL[dx].componentEnable)
  {
    if(cnfCOMPONENT_WL[dx].kodC==OF_COMP1)
    {
      numClonOF++;
      cnfCOMPONENT_WL[dx].numClon = numClonOF;
    }//if
    dx++;
  }//while

  char str_tmp[50];// = "ОФ";
  char locTxt[20];
  dx=0;
  while(cnfCOMPONENT_WL[dx].componentEnable)
  {
    if(cnfCOMPONENT_WL[dx].kodC==kc)
    {
      strcpy(str_tmp, name);
      sprintf(locTxt, "%d.", 100-numClonOF);
      strcpy(cnfCOMPONENT_WL[dx].nameComponent, locTxt);
      strcat(cnfCOMPONENT_WL[dx].nameComponent, str_tmp);
      numClonOF--;
    }//if
    dx++;
  }//while

}//New_name_clon_WL()

void NewClonName()
{
//новые имена клонов
  //искать в конфигурации клон компонента
  short i=0;
  short numC=0;

  while(cnfCOMPONENT[i].componentEnable) //все клоны из конфиг
  {
    if(cnfCOMPONENT[i].kodC == rpzcomponent_obj.kodC) numC++;
    i++;
  }//while

  //номер клона
  char str_tmp[50];
  char locTxt[20];
  strcpy(str_tmp, rpzcomponent_obj.nameComponent);
  sprintf(locTxt, "0%d.", numC+1);
  strcpy(rpzcomponent_obj.nameComponent, locTxt);
  strcat(rpzcomponent_obj.nameComponent, str_tmp);
}//NewClonName()

void  OpenMenuComponent()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  //получить из номера линии номер клона для cnf
  short tmpCnfLin = LIGHTLINEMENU;
  short nC = 0;
  if(CRR_TEXTSTREAM==&CONTROL_CNF)
  {
    nC = GetFromLinToClonCnf(tmpCnfLin);//для cnf
  }//if
  else
  {
    nC = GetFromLinToClonPkt(tmpCnfLin);//для пакета
  }//if

  LIGHTCLON = nC;

  if(cnfCOMPONENT[LIGHTCLON].packet == 0 &&
      cnfCOMPONENT[LIGHTCLON].permanent == 0
    )
  {
    //если компонент перманентный то не расширять
    //если компонент пакетный то не расширять
    //расширить меню
    short i=SUBDATA;
    while(//LMtmp[0]
      ((LineMenuItem *)cnfCOMPONENT[LIGHTCLON].sub_menu_component)[i]
      .Line2 != NULL &&
      ((LineMenuItem *)cnfCOMPONENT[LIGHTCLON].sub_menu_component)[i]
      .Line2 != (void *)&DeleteComponent1
    )
    {
      i++;
    }//while
    ((LineMenuItem *)cnfCOMPONENT[LIGHTCLON].sub_menu_component)[i].Line1 = deleteComp;
    ((LineMenuItem *)cnfCOMPONENT[LIGHTCLON].sub_menu_component)[i].Line2 = (void *)&DeleteComponent1;
    ((LineMenuItem *)cnfCOMPONENT[LIGHTCLON].sub_menu_component)[i].TypesWin = typeMenuProg;

    ((LineMenuItem *)cnfCOMPONENT[LIGHTCLON].sub_menu_component)[i+1].Line1 = NULL;
    ((LineMenuItem *)cnfCOMPONENT[LIGHTCLON].sub_menu_component)[i+1].Line2 = NULL;
  }//if
//добавить меню компонента

  SelectorSUBMENU(cnfCOMPONENT[LIGHTCLON].sub_menu_component);//текущее субменю

  SelectorTEXTCONTROL(&CONTROL1_COMP);//текущий control
  //инит компонентного контроля
  TxtStreamInit(CRR_TEXTSTREAM,   &KadrMenuFormat_sub, CRR_SUBMENU);//инит control и формир кадра
  ViewDiskrMenuSub();//вывести окно отображения
  LanderPStr();//размещение указателя строки
  CRR_FHOME = &PereinitSub;//указатель на ф-цию HOME
}//OpenMenuComponent()

void  OpenMenuComponent_WL()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  //получить из номера линии номер клона для cnf
  short tmpCnfLin = LIGHTLINEMENU;
  short nC = 0;

  nC = GetFromLinToClonCnf_WL(tmpCnfLin);//для cnf РЛ

  LIGHTCLON = nC;

  if(cnfCOMPONENT_WL[LIGHTCLON].packet == 0 &&
      cnfCOMPONENT_WL[LIGHTCLON].permanent == 0
    )
  {
    //если компонент перманентный то не расширять
    //если компонент пакетный то не расширять
    //расширить меню
    short i=SUBDATA;
    while(//LMtmp[0]
      ((LineMenuItem *)cnfCOMPONENT_WL[LIGHTCLON].sub_menu_component)[i]
      .Line2 != NULL &&
      ((LineMenuItem *)cnfCOMPONENT_WL[LIGHTCLON].sub_menu_component)[i]
      .Line2 != (void *)&DeleteComponent1_WL
    )
    {
      i++;
    }//while
    ((LineMenuItem *)cnfCOMPONENT_WL[LIGHTCLON].sub_menu_component)[i].Line1 = deleteComp_WL;
    ((LineMenuItem *)cnfCOMPONENT_WL[LIGHTCLON].sub_menu_component)[i].Line2 = (void *)&DeleteComponent1_WL;
    ((LineMenuItem *)cnfCOMPONENT_WL[LIGHTCLON].sub_menu_component)[i].TypesWin = typeMenuProg;

    ((LineMenuItem *)cnfCOMPONENT_WL[LIGHTCLON].sub_menu_component)[i+1].Line1 = NULL;
    ((LineMenuItem *)cnfCOMPONENT_WL[LIGHTCLON].sub_menu_component)[i+1].Line2 = NULL;
  }//if
//добавить меню компонента
  SelectorSUBMENU(cnfCOMPONENT_WL[LIGHTCLON].sub_menu_component);//текущее субменю

  SelectorTEXTCONTROL(&CONTROLWL_COMP);//текущий control
  //инит компонентного контроля
  TxtStreamInit(CRR_TEXTSTREAM,   &KadrMenuFormat_sub, CRR_SUBMENU);//инит control и формир кадра

  //переключить меню комп на CONTROLWL_COMP
  PNTCRR_SUBMENU(SUBDATA).Line1 = CRR_TEXTSTREAM;

  LIGHTCLON = -LIGHTCLON-1;//маркер РЛ

  ViewDiskrMenuSub();//вывести окно отображения
  LanderPStr();//размещение указателя строки
  CRR_FHOME = &PereinitSub;//указатель на ф-цию HOME
}//OpenMenuComponent_WL()

void  DeleteComponent1()
{
  /*
  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_cnf;// parent
  SelectorSUBMENU(sub_menu_tmp);//текущее субменю

  SelectorLIGHTLINE(&CONTROL_CNF);

  FvmenuDis->Str1Label->Caption = (char *)sub_menu_cnf[LIGHTLINEMENU +1+SUBDATA].Line1;
  FvmenuDis->Str2Label->Caption = "будет удален";
  FvmenuDis->Str3Label->Caption = "Продолжить?";
  FvmenuDis->Str4Label->Caption = "Да   Нет";

  ResetAllButton();//погасить все клавиши
//wkl Up Down
  FvmenuDis->UpButton->Enabled = true;
  FvmenuDis->DownButton->Enabled = true;
  FvmenuDis->UpButton->OnClick   = FvmenuDis->ConfirmDeleteButtonClick;
  FvmenuDis->DownButton->OnClick = FvmenuDis->CloseMButtonClick;
*/
}//DeleteComponent1()

void  DeleteComponent1_WL()
{
  /*
  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_cnfwl;// parent
  SelectorSUBMENU(sub_menu_tmp);//текущее субменю

  SelectorLIGHTLINE(&CONTROL_CNFWL);

  FvmenuDis->Str1Label->Caption = (char *)sub_menu_cnfwl[LIGHTLINEMENU +1+SUBDATA].Line1;
  FvmenuDis->Str2Label->Caption = "будет удален из РЛ";
  FvmenuDis->Str3Label->Caption = "Продолжить?";
  FvmenuDis->Str4Label->Caption = "Да   Нет";

  ResetAllButton();//погасить все клавиши
//wkl Up Down
  FvmenuDis->UpButton->Enabled = true;
  FvmenuDis->DownButton->Enabled = true;
  FvmenuDis->UpButton->OnClick   = FvmenuDis->ConfirmDeleteButtonWLClick;
  FvmenuDis->DownButton->OnClick = FvmenuDis->CloseMButtonClick;
*/
}//DeleteComponent1_WL()

void  AddCompIzRpz(short numK)
{
//добавить компонент из репозитария
  addCOMPONENT(numK);//Добавить компонент с кодом numK в конфигурацию

  if( LIGHTISDENIE ||//запрещено
      LIGHTISPACKET);//это пакет
  else
  {
//инициализировать клон компонента
//если не пакет
    initCOMPONENT(INITUST_TOPCOMP);
    MakeEmptyTopSub_menu(&(sub_menu_cnf[0]),
                         MAX_CNFCOMPONENT*sizeof(LineMenuItem));//добавить пустую запись в top sub_menu
//новый клон в список
    sub_menu_cnf[1+SUBDATA].Line2 = (void *)&OpenMenuComponent; //меню компонента
    sub_menu_cnf[1+SUBDATA].TypesWin = typeMenuProg;
  }//else

  PrepareAllCnfComponent();//подготовить все компоненты в конфигурации
}//AddCompIzRpz()

void ConfirmDeleteButton()
{
  short size_avait = TxtStreamMaxKadr(&CONTROL_CNF);//макс к-во кадров
  SelectorLIGHTLINE(&CONTROL_CNF);

//копировать в shadow cnf
  short copy_size = (size_avait+2+SUBDATA)*sizeof(LineMenuItem);
  memcpy((void*)getShadowBuf(), sub_menu_cnf, copy_size);

//копировать из тени Begin
  memcpy(sub_menu_cnf, (void*)getShadowBuf(), (LIGHTLINEMENU +1+SUBDATA)*sizeof(LineMenuItem));
//копировать из тени END
  if((size_avait- LIGHTLINEMENU -1)>0)
    memcpy(&(sub_menu_cnf[LIGHTLINEMENU  +1+SUBDATA]),
           &(((LineMenuItem *)getShadowBuf())[LIGHTLINEMENU +2+SUBDATA]),
           (size_avait- LIGHTLINEMENU )*sizeof(LineMenuItem));

  short tmpCnfLin = LIGHTLINEMENU;
  short nC = 0;

  nC = GetFromLinToClonCnf(tmpCnfLin);//получить из номера линии номер клона для cnf
//найти к-во клонов для удаления
  short   cntC = cnfCOMPONENT[nC].packet;
  if(cntC<0) cntC = -cntC;
  else cntC=1;

  LIGHTCLON = nC;//подсветить клон для удаления

  deleteCOMPONENT(cntC);//удалить cntC клонов начиная с подсвеченного клона

  PrepareAllCnfComponent();//подготовить все компоненты в конфигурации

  SetCloseButton();//close
}//ConfirmDeleteButton()

void PrepareAllCnfComponent()
{
//подготовить все компоненты в конфигурации
  AllComponentUstTimers();//Инит таймеров всех комп и подготовка уставок всех комп

  New_name_clon(OF_COMP1, "ОФ");

  newsub_menu_cnf_Line1();//новые имена menu_cnf

  TxtStreamInit(&CONTROL_CNF,   &KadrMenuFormat_sub, sub_menu_cnf);//инит control и формир кадра
}//PrepareAllCnfComponent()

void PrepareAllCnfComponent_WL()
{
//подготовить все компоненты в конфигурации РЛ
  AllComponentUstTimers_WL();//Инит таймеров всех комп и подготовка уставок всех комп

  New_name_clon_WL(OF_COMP1, "ОФ");

  newsub_menu_cnfwl_Line1();//новые имена menu_cnfwl

  TxtStreamInit(&CONTROL_CNFWL,   &KadrMenuFormat_sub, sub_menu_cnfwl);//инит control и формир кадра
}//PrepareAllCnfComponent_WL()

void ConfirmDeleteButton_WL()
{
  short size_avait = TxtStreamMaxKadr(&CONTROL_CNFWL);//макс к-во кадров
//  LIGHTLINEMENU = TxtStreamIdxKadr(&CONTROL_CNFWL);//индекс тек кадра
  SelectorLIGHTLINE(&CONTROL_CNFWL);

//копировать в shadow cnfwl
  short copy_size = (size_avait+2+SUBDATA)*sizeof(LineMenuItem);
  memcpy((void*)getShadowBuf(), sub_menu_cnfwl, copy_size);

//копировать из тени Begin
  memcpy(sub_menu_cnfwl, (void*)getShadowBuf(), (LIGHTLINEMENU +1+SUBDATA)*sizeof(LineMenuItem));
//копировать из тени END
  if((size_avait- LIGHTLINEMENU -1)>0)
    memcpy(&(sub_menu_cnfwl[LIGHTLINEMENU  +1+SUBDATA]),
           &(((LineMenuItem *)getShadowBuf())[LIGHTLINEMENU +2+SUBDATA]),
           (size_avait- LIGHTLINEMENU )*sizeof(LineMenuItem));

  short tmpCnfLin = LIGHTLINEMENU;
  short nC = 0;

  nC = GetFromLinToClonCnf_WL(tmpCnfLin);//получить из номера линии номер клона для cnfwl
//найти к-во клонов для удаления
  short   cntC = cnfCOMPONENT_WL[nC].packet;
  if(cntC<0) cntC = -cntC;
  else cntC=1;

  LIGHTCLON = nC;//подсветить клон для удаления

  deleteCOMPONENT_WL(cntC);//удалить cntC клонов начиная с подсвеченного клона
  PrepareAllCnfComponent_WL();//подготовить все компоненты в конфигурации РЛ

  SetCloseButton();//close
}//ConfirmDeleteButton_WL()

void UpravlRedactor(char *nameUpr, short nBit, char * (*selectorUprStr)(short, UNS_32))
{
  /*
//редактировать уставку управления
  UNS_32 wtmp =  getCurrentMngUSTAVKI();

  char *sel = selectorUprStr(nBit, wtmp);
  FvmenuDis->EditUprPanel->Visible = true;
  FvmenuDis->EditLabel->Caption = nameUpr;
  FvmenuDis->EditUprLabel->Caption = nameUpr;

  FvmenuDis->Str1Label->Caption = nameUpr;
  FvmenuDis->Str2Label->Caption = sel;
  FvmenuDis->Str3Label->Caption = "";
  FvmenuDis->Str4Label->Caption = "";

  FvmenuDis->UprCheck->Checked = (bool)NumBitCheckWord(nBit, &wtmp);//true;
  FvmenuDis->UprCheck->Caption = sel;
*/
}//UpravlRedactor(char *nameUpr)

void SetPgDownButton(short flg)
{
//страница вниз
//типажи
  /*
  short typeWin = PNTCRR_SUBMENU(SUBDATA).TypesWin;
  PNTCRR_TEXTSTREAM->topStrPnt = TxtStreamPgDownButtonPrepare(CRR_TEXTSTREAM);//подготовка
  ViewDiskrMenu(typeWin);//вывести окно отображения

  PNTCRR_TEXTSTREAM->PntStringViewer = 0;//сброс указателя строки
  if(typeWin==typeMenuList)ListPStr();//доступ к уставкам
  if(FvmenuDis->TipPanel->Visible) PgDownTipPanel();
  */
}//SetPgDownButton(short flg)

void PassWord(void (*menuEdit)())
{
  //CRR_FPASSWORD = menuEdit;//указатель на ф-цию Ust
  //FvmenuDis->PassPanel->Visible = true;
}//

void PrepareEditMenu(void *parent)
{
  ResetAllButton();//погасить все клавиши

  SelectorSUBMENU(sub_menu_tmp);//текущее субменю

  sub_menu_tmp[SUBDATA].Line2 = parent;
}//PrepareEditMenu(void *parent)

void ViewToEditUst(int (*menuEditUst)())
{
  /*
  int ust = menuEditUst();
  char locTxt[50];
  sprintf(locTxt, "%d", ust);
  FvmenuDis->EditEdit->Text = locTxt;
  */
}//ViewToEditUst(int (*menuEditUst)())


void ViewerEditorUst(void *text)
{
  /*
//редактировать уставку
  CRR_SUBMENU = sub_menu_tmp;//текущее субменю

  FvmenuDis->Str1Label->Caption = "Уставка";
  FvmenuDis->Str2Label->Caption =
    (char *)text;
  FvmenuDis->Str3Label->Caption = "редактирована";
  FvmenuDis->Str4Label->Caption = "";

  ResetAllButton();//погасить все клавиши
  FvmenuDis->EditPanel->Visible = true;
  FvmenuDis->EditUprPanel->Visible = false;
  FvmenuDis->EditLabel->Caption =
    (char *)text;

  LIGHTMNGUOFFSET = LIGHTLINEMENU;
*/
}//ViewerEditUst(void *text)

void SystemEditUst(void *sub_menu)
{
  /*
  short linemenu = LIGHTLINEMENU;
  void *text = ((LineMenuItem *)sub_menu)[linemenu +1+SUBDATA].Line1;
  LIGHTMNGUOFFSET = linemenu;//LIGHTLINEMENU;//offset;
  int ust = getCurrentMngUSTAVKI();
  char locTxt[50];
  sprintf(locTxt, "%d", ust);
  FvmenuDis->EditEdit->Text = locTxt;

  FvmenuDis->Str1Label->Caption = "Уставка";
  FvmenuDis->Str2Label->Caption =
    (char *)text;
  FvmenuDis->Str3Label->Caption = "редактирована";
  FvmenuDis->Str4Label->Caption = "";

  ResetAllButton();//погасить все клавиши
  FvmenuDis->EditPanel->Visible = true;
  FvmenuDis->EditLabel->Caption =
    (char *)text;
  */
}//SystemEditUst(void *text, int offset)

void AllComponentUstTimers()
{
//Инит таймеров всех комп и подготовка уставок всех комп
  INITtimersCOMPONENT();//Инициализация таймеров всех компонентов из конфиг

  PREPAREustCOMPONENT(INITUST_ALLCOMP);//подготовка уставок всех комп
}//AllComponentUstTimers()

void AllComponentUstTimers_WL()
{
//Инит таймеров всех комп и подготовка уставок всех комп
  INITtimersCOMPONENT_WL();//Инициализация таймеров всех компонентов из конфиг РЛ

  PREPAREustCOMPONENT_WL(INITUST_ALLCOMP);//подготовка уставок всех комп РЛ
}//AllComponentUstTimers()

void DiskrRegList()
{
//первые 50 строк дискр регистратора
  TxtStreamInit(&CONTROL_STR, &KadrMenuFormat_reg, NULL);//инит управл структ и формир кадра
  Load2String(46, "Дискр рег");//первые 48 строк по 2 строки
}//DiskrRegList()

void Load1String(int maxStr, char *title)
{
//первые maxStr строк по 1 строки
 VIEW_STRUCT view_struct;
  //обнулить все
  memset((char*)stringList,   0, sizeof(stringList));
  memset((char*)&view_struct,   0, sizeof(VIEW_STRUCT));

  strcpy( stringList[0], title);
  strcpy( stringList[1], "-------------");

  int cntStr = 2;//к-во заполненных строк
  for(; cntStr<maxStr; ){
  View1StrWin(&view_struct);//4-х строчное окно просмотра по 1 строки
  if(memcmp((char *)(&view_struct.stringWinOld),
            (char *)(&view_struct.stringWin),
            sizeof(WIN_STRUCT))!=0){
  //окна разные
  for(int i=0; i<4; i++)
      strcpy(stringList[cntStr +i],
             view_struct.stringWin.Win[i]);
  cntStr += 4;
  }//if
  else break;//окна одинаковые
  memcpy((char *)(&view_struct.stringWinOld),
         (char *)(&view_struct.stringWin),
         sizeof(WIN_STRUCT));
  TxtStreamPgDownButtonPrepare(&CONTROL_STR);//подготовка
  }//for
}//Load1String(int maxStr)

void Load2String(int maxStr, char *title)
{
//первые maxStr строк по 2 строки
  VIEW_STRUCT view_struct;
  //обнулить все
  memset((char*)stringList,   0, sizeof(stringList));
  memset((char*)&view_struct,   0, sizeof(VIEW_STRUCT));
  strcpy( stringList[0], title);
  strcpy( stringList[1], "-------------");

  int cntStr = 2;//к-во заполненных строк
  for(; cntStr<maxStr; ){
  View2StrWin(&view_struct);//4-х строчное окно просмотра по 2 строки
  if(memcmp( (char *)(&view_struct.stringWinOld),
             (char *)(&view_struct.stringWin),
            sizeof(WIN_STRUCT))!=0){
  //окна разные
  for(int i=0; i<4; i++)
      strcpy( stringList[cntStr +i],
              view_struct.stringWin.Win[i]);
  cntStr += 4;
  }//if
  else break;//окна одинаковые
  memcpy((char *)(&view_struct.stringWinOld),
         (char *)(&view_struct.stringWin),
         sizeof(WIN_STRUCT));
  TxtStreamPgDownButtonPrepare(&CONTROL_STR);//подготовка
  }//for
}//Load2String(int maxStr)

void View2StrWin(void *vs)
{
//окно просмотра по 2 строки
  VIEW_STRUCT *view_struct = (VIEW_STRUCT *)vs;
  memset((char *)&(view_struct->stringWin), 0,
         sizeof(WIN_STRUCT));
  WorkVariantChar workVariantCharLoc;//буфер кадра

  int tmp = TxtStreamIteratorBegin((void *)&workVariantCharLoc, &CONTROL_STR);//движение вниз

  if(tmp==-1) //файла нет или пустой
  {
    strcpy(view_struct->stringWin.Win[0], "ПУСТО");
    return ;
  }//if

  if(tmp==0) //достигнут конец файла
  {
    return ;
  }//if

  //показать результат
    strcpy(view_struct->stringWin.Win[0],
           workVariantCharLoc.TwoString[0]);
    strcpy(view_struct->stringWin.Win[1],
           workVariantCharLoc.TwoString[1]);

  if(TxtStreamIteratorMidle(&CONTROL_STR)==0) //движение вниз
  {
    //достигнут конец файла
    PNTCONTROL_STR->StpStringViewer = 0;//stp указател строки
    return ;
  }//if
  //показать результат
    strcpy(view_struct->stringWin.Win[2],
           workVariantCharLoc.TwoString[0]);
    strcpy(view_struct->stringWin.Win[3],
           workVariantCharLoc.TwoString[1]);

  PNTCONTROL_STR->StpStringViewer = 1;//stp указател строки

  TxtStreamIteratorEnd(&CONTROL_STR);//конец страницы

}//View2StrWin()

void ActualRegList()
{
//первые 50 строк текущих
  TxtStreamInit(&CONTROL_STR, &KadrMenuFormat_viewActual, NULL);//инит управл структ и формир кадра
  Load1String(46, "Текущие");//первые 48 строк по 1 строки
}//ActualRegList()

void ActualDVList()
{
//первые 50 строк текущих
 selectorUVVLow  = selectorDVLow;//селекция UVV активный-неактивный для мл 16 UVV
 selectorUVVMidd = selectorDVMidd;//селекция UVV активный-неактивный для cp 16 UVV
 selectorUVVHi   = selectorDVHi;//селекция UVV активный-неактивный для ct 16 UVV
  TxtStreamInit(&CONTROL_STR, &KadrMenuFormat_viewActualDV, NULL);//инит управл структ и формир кадра
  Load1String(46, "Текущие ДВ");//первые 48 строк по 1 строки
}//ActualDVList()

void ActualReleList()
{
//первые 50 строк текущих
 selectorUVVLow  = rele_bdvv1;//селекция UVV активный-неактивный для мл 16 UVV
 selectorUVVMidd = 0;//селекция UVV активный-неактивный для cp 16 UVV
 selectorUVVHi   = 0;//селекция UVV активный-неактивный для ct 16 UVV
  TxtStreamInit(&CONTROL_STR, &KadrMenuFormat_viewActualRele, NULL);//инит управл структ и формир кадра
  Load1String(46, "Текущие Реле");//первые 48 строк по 1 строки
}//ActualReleList()

void View1StrWin(void *vs)
{
//окно просмотра по 1 строки
  VIEW_STRUCT *view_struct = (VIEW_STRUCT *)vs;
  memset((char *)&(view_struct->stringWin), 0,
         sizeof(WIN_STRUCT));
  WorkVariantChar workVariantCharLoc;//буфер кадра

  int tmp = TxtStreamIteratorBegin((void *)&workVariantCharLoc, &CONTROL_STR);//движение вниз

  if(tmp==-1) //файла нет или пустой
  {
    strcpy(view_struct->stringWin.Win[0], "ПУСТО");
    return ;
  }//if

  if(tmp==0) //достигнут конец файла
  {
    return ;
  }//if
  //показать результат
    strcpy(view_struct->stringWin.Win[0],
           workVariantCharLoc.TwoString[0]);

  if(TxtStreamIteratorMidle(&CONTROL_STR)==0) //движение вниз
  {
    //достигнут конец файла
    PNTCONTROL_STR->StpStringViewer = 0;//stp указател строки
    return ;
  }//if
  //показать результат
    strcpy(view_struct->stringWin.Win[1],
           workVariantCharLoc.TwoString[0]);

  if(TxtStreamIteratorMidle(&CONTROL_STR)==0) //движение вниз
  {
    //достигнут конец файла
    PNTCONTROL_STR->StpStringViewer = 1;//stp указател строки
    return ;
  }//if
  //показать результат
    strcpy(view_struct->stringWin.Win[2],
           workVariantCharLoc.TwoString[0]);

  if(TxtStreamIteratorMidle(&CONTROL_STR)==0)
  {
    //достигнут конец файла
    PNTCONTROL_STR->StpStringViewer = 2;//stp указател строки
    return ;
  }//if
  //показать результат
    strcpy(view_struct->stringWin.Win[3],
           workVariantCharLoc.TwoString[0]);

  TxtStreamIteratorEnd(&CONTROL_STR);//конец страницы

  PNTCONTROL_STR->StpStringViewer = 3;//stp указател строки

}//View1StrWin()

void SelectorMNGBAZA(short baza)
{
//установка базы уставок
  LIGHTMNGUBAZA = baza;
  LIGHTMNGUOFFSET = 0;
}//SelectorMNGBAZA(short baza)

void SelectorLIGHTLINE(void *txtstrm)
{
//найти подсвеченную строку
  LIGHTLINEMENU = TxtStreamIdxKadr(txtstrm);
}//SelectorLIGHTLINE()

void SelectorCRRLIGHTLINE()
{
//найти подсвеченную строку текущего текст потока
  SelectorLIGHTLINE(CRR_TEXTSTREAM);//найти подсвеченную строку текущего текст потока
}//SelectorCRRLIGHTLINE()

void SelectorSUBMENU(void *sub_menu)
{
//уcтановить текущее субменю
  CRR_SUBMENU = sub_menu;//текущее субменю
}//SelectorSUBMENU(void *sub_menu)

void SelectorTEXTCONTROL(void *control)
{
//установить текущую ссылку на текстовый поток
 CRR_TEXTSTREAM = control;
}//SelectorTEXTSTREAM(void *control)

void SelectorFHOME(void (*pFncGlobal)(short))
{
//указатель на ф-цию HOME
//  CRR_FHOME = &PereinitUstListCompAPV;//указатель на ф-цию HOME
  CRR_FHOME = pFncGlobal;//указатель на ф-цию HOME
}//SelectorFHOME(void (*pFncGlobal)(short))

void InitFHOME(short flag)
{
//переиниц
  CRR_FHOME(flag);//вызвать ф-цию HOME
}//InitFHOME(short flag)

