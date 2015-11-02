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
extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������

extern LineMenuItem sub_menu_dv[];
extern LineMenuItem sub_menu_rele[];
extern LineMenuItem sub_menu_logw[];
extern LineMenuItem sub_menu_le[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_cnfwl[];
extern LineMenuItem sub_menu_tmp[];
extern UNS_32 pRDIScmdMaska[];//��������������
extern UNS_32 pAPVcmdMaska[];//APV
extern UNS_32 pUROVcmdMaska[];//UROV
//extern UNS_32 pP1OFcmdMaska[];//P1OF
//extern UNS_32 pP2OFcmdMaska[];//P2OF
//extern UNS_32 pP3OFcmdMaska[];//P3OF

extern UNS_32 selectorDVLow;//�������� �� ��������-���������� ��� �� 16 DV
extern UNS_32 selectorDVMidd;//�������� �� ��������-���������� ��� cp 16 DV
extern UNS_32 selectorDVHi;//�������� �� ��������-���������� ��� ct 16 DV
extern UNS_32 rele_bdvv1;//�������� ����

extern UNS_32 selectorUVVLow;//�������� UVV ��������-���������� ��� �� 16 UVV
extern UNS_32 selectorUVVMidd;//�������� UVV ��������-���������� ��� cp 16 UVV
extern UNS_32 selectorUVVHi;//�������� UVV ��������-���������� ��� ct 16 UVV

typedef void (* pFunction());//��������� �� �-���

MENU_CONTEXT menu_context;

extern char stringList[48][32];//������ ����� ��� ���������

void ViewDiskrMenu(short typeWin)
{
//������� ��������
//������
  switch(typeWin)
  {
  case typeMenuReg:
  case typeMenuList:
  case typeMenuEditRang:
  case typeMenuEditWL:
    ViewDiskrMenuList();//������� �������� List
    break;
  case typeMenuViewLE:
  case typeMenuViewRangDV:
  case typeMenuViewRangRele:
  case typeMenuViewRangCDI:
  case typeMenuViewActual:
  case typeMenuViewActualDV:
  case typeMenuViewActualRele:
  case typeMenuViewRDISMaska:
  case typeMenuViewAPVMaska://���� ���
  case typeMenuViewUROVMaska://���� ����
  case typeMenuViewP1OFMaska://����� 1 ��
  case typeMenuViewP2OFMaska://����� 2 ��
  case typeMenuViewP3OFMaska://����� 3 ��
  case typeMenuCnf:
  case typeMenuCnfWL:
  case typeMenuSub:
    ViewDiskrMenuSub();//������� �������� View
    break;
  }//switch
}//ViewDiskrMenu()


void SetCloseButton()
{
//close
  if(PNTCRR_SUBMENU(SUBDATA).Line2==NULL) return;//parent sub_menu �� ����������

  //CRR_SUBMENU = 
  SelectorSUBMENU(PNTCRR_SUBMENU(SUBDATA).Line2);//����� ������� submenu
  short typeWin = PNTCRR_SUBMENU(SUBDATA).TypesWin;
  if(typeWin==typeMenuSub)
  {
    CRR_FHOME = &PereinitSub;//��������� �� �-��� HOME
    ResetUpDown();//�������� Up Down
  }//if

  //CRR_TEXTSTREAM = 
  SelectorTEXTCONTROL(PNTCRR_SUBMENU(SUBDATA).Line1);
  PNTCRR_TEXTSTREAM->PntStringViewer =0;//�������� ������

  ShowTitleSubmenu_crr();//��������� �������� Submenu
  ViewDiskrMenu(typeWin);//������� ���� �����������

  if(typeWin!=typeMenuList) LanderPStr();//���������� ��������� ������
  else ListPStr();//���������� ��������� ������
}//SetCloseButton()

void ClickOpenButton()
{
//������� ����
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  //������� linemenu
  LineMenuItem  crr_linemenu = PNTCRR_SUBMENU(
                                 LIGHTLINEMENU +1+SUBDATA
                               );
  if(crr_linemenu.Line2==NULL) return; //������� ���� ���

  //CRR_SUBMENU = 
  SelectorSUBMENU(crr_linemenu.Line2);//����� ������� submenu

  //����� ������
  short typeWin = crr_linemenu.TypesWin;
  if(!(typeWin==typeMenuProg))// || typeWin==typeMenuPassW))
  {
    PNTCRR_SUBMENU(SUBDATA).TypesWin = typeWin;//parent_type
  }//if

  switch(typeWin)
  {
  case typeMenuViewLE:
    OpenViewLE();//������� ViewLE
    break;
  case typeMenuViewActual:
    OpenMenuViewActual();//������� ���� �������
    ResetPStr();
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewActualDV:
    OpenMenuViewActualDV();//������� ���� ������� DV
    ResetPStr();
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewActualRele:
    OpenMenuViewActualRele();//������� ���� ������� Rele
    ResetPStr();
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewRDISMaska:
    OpenMenuViewRDIS();//������� ���� RDIS
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewAPVMaska://���� ���
    OpenMenuViewAPV();//������� ���� APV
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewUROVMaska://���� ����
    OpenMenuViewUROV();//������� ���� UROV
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewP1OFMaska://����� 1 ��
    OpenMenuViewP1OF();//������� ���� P1OF
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewP2OFMaska://����� 2 ��
    OpenMenuViewP2OF();//������� ���� P2OF
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewP3OFMaska://����� 3 ��
    OpenMenuViewP3OF();//������� ���� P3OF
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuViewRangDV:
    OpenMenuViewRangDV();//������� ���� ViewRang
    break;
  case typeMenuViewRangRele:
    OpenMenuViewRangRele();//������� ���� ViewRang
    break;
  case typeMenuViewRangCDI:
    OpenMenuViewRangCDI();//������� ���� ViewRang
    break;
  case typeMenuCnf:
    OpenMenuCnf();//������� ���� cnf
    break;
  case typeMenuCnfWL:
    OpenMenuCnfWL();//������� ���� cnf ��
    break;
  case typeMenuReg:
    OpenMenuReg();//������� ���� reg
    ResetPStr();
    LanderUpDown();//wkl Up Down
    break;
  case typeMenuProg:  //������� ���� prog
    TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
    (*(pFunction *)CRR_SUBMENU)();//������� �� ��������� �-���
    break;
  case typeMenuSub:
    OpenMenuSub();//������� ���� Sub
    break;
  }//switch

  ShowTitleSubmenu_crr();//��������� �������� Submenu
}//ClickOpenButton()

void JumpAndOpen(short step)
{
//������� � �������
//������
  short typeWin = PNTCRR_SUBMENU(SUBDATA).TypesWin;//������� submenu
  switch(typeWin)
  {
  case typeMenuEditRang:
    PNTCRR_TEXTSTREAM->PntStringViewer =step/2;//�������� ������
    ClickProcessEditRang();//������ �������������� ������
    return;
  case typeMenuViewLE:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//�������� ������
    ClickOpenEditWL(MngWLGetLEWLtoEdit_PRM(LIGHTRANGUVV));//������� �������������� ��
    return;
  case typeMenuEditWL:
    PNTCRR_TEXTSTREAM->PntStringViewer =step/2;//�������� ������
    ClickProcessEditWL();//������ �������������� ������
    return;
  case typeMenuViewRangDV:
  case typeMenuViewRangRele:
  case typeMenuViewRangCDI:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//�������� ������
    PassWord(OpenEditRangUVV);
    return;

  case typeMenuViewRDISMaska:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//�������� ������
    ClickOpenEditRang(pRDIScmdMaska);//������� �������������� ��������������
    return;
  case typeMenuViewAPVMaska:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//�������� ������
    ClickOpenEditRang(pAPVcmdMaska);//������� �������������� APV
    return;
  case typeMenuViewUROVMaska:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//�������� ������
    ClickOpenEditRang(pUROVcmdMaska);//������� �������������� UROV
    return;
/*
  case typeMenuViewP1OFMaska:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//�������� ������
    ClickOpenEditRang(pP1OFcmdMaska);//������� �������������� P1OF
    return;
  case typeMenuViewP2OFMaska:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//�������� ������
    ClickOpenEditRang(pP2OFcmdMaska);//������� �������������� P2OF
    return;
  case typeMenuViewP3OFMaska:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//�������� ������
    ClickOpenEditRang(pP3OFcmdMaska);//������� �������������� P3OF
    return;
*/

  case typeMenuSub:
  case typeMenuCnf:
  case typeMenuCnfWL:
    PNTCRR_TEXTSTREAM->PntStringViewer =step;//�������� ������
    break;

  case typeMenuList:
    PNTCRR_TEXTSTREAM->PntStringViewer =step/2;//�������� ������
    break;

  default:
    return;
  }//switch
  ClickOpenButton();//������� ����
}//JumpAndOpen(short step)

void OpenEditRangUVV()
{
//����� �������������� ������
    ClickOpenEditRang(MngRangGetPointerUVVRANGIRtoEdit(LIGHTRANGUVV));//������� �������������� ������
}//OpenEditRangUVV()

void ShowTitleSubmenu_crr()
{
//��������� �������� Submenu
//  char *title = (char *)PNTCRR_SUBMENU(0).Line1;//������� submenu
//  FvmenuDis->TitleLabel->Caption = title;
}//ShowTitleSubmenu_crr()

void MakeEmptyTopSub_menu(void *pstr, short size)
{
  LineMenuItem *src = (LineMenuItem *)pstr;
//�������� ������ ������ � top sub_menu
  //���������� � ����
  memcpy((void*)getShadowBuf(), (void *)src, size);
//���������� �� ���� End
  memcpy(&(src[1+ 1+SUBDATA]),
         &(((LineMenuItem *)getShadowBuf())[1+ SUBDATA]),
         size-(3*sizeof(LineMenuItem)));
}//MakeEmptyTopSub_menu()

void New_name_clon(short kc, char *name)
{
//����� ����� ������
//����� ����� �-�� ������
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

  char str_tmp[50];// = "��";
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
//����� ����� ������
//����� ����� �-�� ������
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

  char str_tmp[50];// = "��";
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
//����� ����� ������
  //������ � ������������ ���� ����������
  short i=0;
  short numC=0;

  while(cnfCOMPONENT[i].componentEnable) //��� ����� �� ������
  {
    if(cnfCOMPONENT[i].kodC == rpzcomponent_obj.kodC) numC++;
    i++;
  }//while

  //����� �����
  char str_tmp[50];
  char locTxt[20];
  strcpy(str_tmp, rpzcomponent_obj.nameComponent);
  sprintf(locTxt, "0%d.", numC+1);
  strcpy(rpzcomponent_obj.nameComponent, locTxt);
  strcat(rpzcomponent_obj.nameComponent, str_tmp);
}//NewClonName()

void  OpenMenuComponent()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  //�������� �� ������ ����� ����� ����� ��� cnf
  short tmpCnfLin = LIGHTLINEMENU;
  short nC = 0;
  if(CRR_TEXTSTREAM==&CONTROL_CNF)
  {
    nC = GetFromLinToClonCnf(tmpCnfLin);//��� cnf
  }//if
  else
  {
    nC = GetFromLinToClonPkt(tmpCnfLin);//��� ������
  }//if

  LIGHTCLON = nC;

  if(cnfCOMPONENT[LIGHTCLON].packet == 0 &&
      cnfCOMPONENT[LIGHTCLON].permanent == 0
    )
  {
    //���� ��������� ������������ �� �� ���������
    //���� ��������� �������� �� �� ���������
    //��������� ����
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
//�������� ���� ����������

  SelectorSUBMENU(cnfCOMPONENT[LIGHTCLON].sub_menu_component);//������� �������

  SelectorTEXTCONTROL(&CONTROL1_COMP);//������� control
  //���� ������������� ��������
  TxtStreamInit(CRR_TEXTSTREAM,   &KadrMenuFormat_sub, CRR_SUBMENU);//���� control � ������ �����
  ViewDiskrMenuSub();//������� ���� �����������
  LanderPStr();//���������� ��������� ������
  CRR_FHOME = &PereinitSub;//��������� �� �-��� HOME
}//OpenMenuComponent()

void  OpenMenuComponent_WL()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  //�������� �� ������ ����� ����� ����� ��� cnf
  short tmpCnfLin = LIGHTLINEMENU;
  short nC = 0;

  nC = GetFromLinToClonCnf_WL(tmpCnfLin);//��� cnf ��

  LIGHTCLON = nC;

  if(cnfCOMPONENT_WL[LIGHTCLON].packet == 0 &&
      cnfCOMPONENT_WL[LIGHTCLON].permanent == 0
    )
  {
    //���� ��������� ������������ �� �� ���������
    //���� ��������� �������� �� �� ���������
    //��������� ����
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
//�������� ���� ����������
  SelectorSUBMENU(cnfCOMPONENT_WL[LIGHTCLON].sub_menu_component);//������� �������

  SelectorTEXTCONTROL(&CONTROLWL_COMP);//������� control
  //���� ������������� ��������
  TxtStreamInit(CRR_TEXTSTREAM,   &KadrMenuFormat_sub, CRR_SUBMENU);//���� control � ������ �����

  //����������� ���� ���� �� CONTROLWL_COMP
  PNTCRR_SUBMENU(SUBDATA).Line1 = CRR_TEXTSTREAM;

  LIGHTCLON = -LIGHTCLON-1;//������ ��

  ViewDiskrMenuSub();//������� ���� �����������
  LanderPStr();//���������� ��������� ������
  CRR_FHOME = &PereinitSub;//��������� �� �-��� HOME
}//OpenMenuComponent_WL()

void  DeleteComponent1()
{
  /*
  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_cnf;// parent
  SelectorSUBMENU(sub_menu_tmp);//������� �������

  SelectorLIGHTLINE(&CONTROL_CNF);

  FvmenuDis->Str1Label->Caption = (char *)sub_menu_cnf[LIGHTLINEMENU +1+SUBDATA].Line1;
  FvmenuDis->Str2Label->Caption = "����� ������";
  FvmenuDis->Str3Label->Caption = "����������?";
  FvmenuDis->Str4Label->Caption = "��   ���";

  ResetAllButton();//�������� ��� �������
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
  SelectorSUBMENU(sub_menu_tmp);//������� �������

  SelectorLIGHTLINE(&CONTROL_CNFWL);

  FvmenuDis->Str1Label->Caption = (char *)sub_menu_cnfwl[LIGHTLINEMENU +1+SUBDATA].Line1;
  FvmenuDis->Str2Label->Caption = "����� ������ �� ��";
  FvmenuDis->Str3Label->Caption = "����������?";
  FvmenuDis->Str4Label->Caption = "��   ���";

  ResetAllButton();//�������� ��� �������
//wkl Up Down
  FvmenuDis->UpButton->Enabled = true;
  FvmenuDis->DownButton->Enabled = true;
  FvmenuDis->UpButton->OnClick   = FvmenuDis->ConfirmDeleteButtonWLClick;
  FvmenuDis->DownButton->OnClick = FvmenuDis->CloseMButtonClick;
*/
}//DeleteComponent1_WL()

void  AddCompIzRpz(short numK)
{
//�������� ��������� �� �����������
  addCOMPONENT(numK);//�������� ��������� � ����� numK � ������������

  if( LIGHTISDENIE ||//���������
      LIGHTISPACKET);//��� �����
  else
  {
//���������������� ���� ����������
//���� �� �����
    initCOMPONENT(INITUST_TOPCOMP);
    MakeEmptyTopSub_menu(&(sub_menu_cnf[0]),
                         MAX_CNFCOMPONENT*sizeof(LineMenuItem));//�������� ������ ������ � top sub_menu
//����� ���� � ������
    sub_menu_cnf[1+SUBDATA].Line2 = (void *)&OpenMenuComponent; //���� ����������
    sub_menu_cnf[1+SUBDATA].TypesWin = typeMenuProg;
  }//else

  PrepareAllCnfComponent();//����������� ��� ���������� � ������������
}//AddCompIzRpz()

void ConfirmDeleteButton()
{
  short size_avait = TxtStreamMaxKadr(&CONTROL_CNF);//���� �-�� ������
  SelectorLIGHTLINE(&CONTROL_CNF);

//���������� � shadow cnf
  short copy_size = (size_avait+2+SUBDATA)*sizeof(LineMenuItem);
  memcpy((void*)getShadowBuf(), sub_menu_cnf, copy_size);

//���������� �� ���� Begin
  memcpy(sub_menu_cnf, (void*)getShadowBuf(), (LIGHTLINEMENU +1+SUBDATA)*sizeof(LineMenuItem));
//���������� �� ���� END
  if((size_avait- LIGHTLINEMENU -1)>0)
    memcpy(&(sub_menu_cnf[LIGHTLINEMENU  +1+SUBDATA]),
           &(((LineMenuItem *)getShadowBuf())[LIGHTLINEMENU +2+SUBDATA]),
           (size_avait- LIGHTLINEMENU )*sizeof(LineMenuItem));

  short tmpCnfLin = LIGHTLINEMENU;
  short nC = 0;

  nC = GetFromLinToClonCnf(tmpCnfLin);//�������� �� ������ ����� ����� ����� ��� cnf
//����� �-�� ������ ��� ��������
  short   cntC = cnfCOMPONENT[nC].packet;
  if(cntC<0) cntC = -cntC;
  else cntC=1;

  LIGHTCLON = nC;//���������� ���� ��� ��������

  deleteCOMPONENT(cntC);//������� cntC ������ ������� � ������������� �����

  PrepareAllCnfComponent();//����������� ��� ���������� � ������������

  SetCloseButton();//close
}//ConfirmDeleteButton()

void PrepareAllCnfComponent()
{
//����������� ��� ���������� � ������������
  AllComponentUstTimers();//���� �������� ���� ���� � ���������� ������� ���� ����

  New_name_clon(OF_COMP1, "��");

  newsub_menu_cnf_Line1();//����� ����� menu_cnf

  TxtStreamInit(&CONTROL_CNF,   &KadrMenuFormat_sub, sub_menu_cnf);//���� control � ������ �����
}//PrepareAllCnfComponent()

void PrepareAllCnfComponent_WL()
{
//����������� ��� ���������� � ������������ ��
  AllComponentUstTimers_WL();//���� �������� ���� ���� � ���������� ������� ���� ����

  New_name_clon_WL(OF_COMP1, "��");

  newsub_menu_cnfwl_Line1();//����� ����� menu_cnfwl

  TxtStreamInit(&CONTROL_CNFWL,   &KadrMenuFormat_sub, sub_menu_cnfwl);//���� control � ������ �����
}//PrepareAllCnfComponent_WL()

void ConfirmDeleteButton_WL()
{
  short size_avait = TxtStreamMaxKadr(&CONTROL_CNFWL);//���� �-�� ������
//  LIGHTLINEMENU = TxtStreamIdxKadr(&CONTROL_CNFWL);//������ ��� �����
  SelectorLIGHTLINE(&CONTROL_CNFWL);

//���������� � shadow cnfwl
  short copy_size = (size_avait+2+SUBDATA)*sizeof(LineMenuItem);
  memcpy((void*)getShadowBuf(), sub_menu_cnfwl, copy_size);

//���������� �� ���� Begin
  memcpy(sub_menu_cnfwl, (void*)getShadowBuf(), (LIGHTLINEMENU +1+SUBDATA)*sizeof(LineMenuItem));
//���������� �� ���� END
  if((size_avait- LIGHTLINEMENU -1)>0)
    memcpy(&(sub_menu_cnfwl[LIGHTLINEMENU  +1+SUBDATA]),
           &(((LineMenuItem *)getShadowBuf())[LIGHTLINEMENU +2+SUBDATA]),
           (size_avait- LIGHTLINEMENU )*sizeof(LineMenuItem));

  short tmpCnfLin = LIGHTLINEMENU;
  short nC = 0;

  nC = GetFromLinToClonCnf_WL(tmpCnfLin);//�������� �� ������ ����� ����� ����� ��� cnfwl
//����� �-�� ������ ��� ��������
  short   cntC = cnfCOMPONENT_WL[nC].packet;
  if(cntC<0) cntC = -cntC;
  else cntC=1;

  LIGHTCLON = nC;//���������� ���� ��� ��������

  deleteCOMPONENT_WL(cntC);//������� cntC ������ ������� � ������������� �����
  PrepareAllCnfComponent_WL();//����������� ��� ���������� � ������������ ��

  SetCloseButton();//close
}//ConfirmDeleteButton_WL()

void UpravlRedactor(char *nameUpr, short nBit, char * (*selectorUprStr)(short, UNS_32))
{
  /*
//������������� ������� ����������
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
//�������� ����
//������
  /*
  short typeWin = PNTCRR_SUBMENU(SUBDATA).TypesWin;
  PNTCRR_TEXTSTREAM->topStrPnt = TxtStreamPgDownButtonPrepare(CRR_TEXTSTREAM);//����������
  ViewDiskrMenu(typeWin);//������� ���� �����������

  PNTCRR_TEXTSTREAM->PntStringViewer = 0;//����� ��������� ������
  if(typeWin==typeMenuList)ListPStr();//������ � ��������
  if(FvmenuDis->TipPanel->Visible) PgDownTipPanel();
  */
}//SetPgDownButton(short flg)

void PassWord(void (*menuEdit)())
{
  //CRR_FPASSWORD = menuEdit;//��������� �� �-��� Ust
  //FvmenuDis->PassPanel->Visible = true;
}//

void PrepareEditMenu(void *parent)
{
  ResetAllButton();//�������� ��� �������

  SelectorSUBMENU(sub_menu_tmp);//������� �������

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
//������������� �������
  CRR_SUBMENU = sub_menu_tmp;//������� �������

  FvmenuDis->Str1Label->Caption = "�������";
  FvmenuDis->Str2Label->Caption =
    (char *)text;
  FvmenuDis->Str3Label->Caption = "�������������";
  FvmenuDis->Str4Label->Caption = "";

  ResetAllButton();//�������� ��� �������
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

  FvmenuDis->Str1Label->Caption = "�������";
  FvmenuDis->Str2Label->Caption =
    (char *)text;
  FvmenuDis->Str3Label->Caption = "�������������";
  FvmenuDis->Str4Label->Caption = "";

  ResetAllButton();//�������� ��� �������
  FvmenuDis->EditPanel->Visible = true;
  FvmenuDis->EditLabel->Caption =
    (char *)text;
  */
}//SystemEditUst(void *text, int offset)

void AllComponentUstTimers()
{
//���� �������� ���� ���� � ���������� ������� ���� ����
  INITtimersCOMPONENT();//������������� �������� ���� ����������� �� ������

  PREPAREustCOMPONENT(INITUST_ALLCOMP);//���������� ������� ���� ����
}//AllComponentUstTimers()

void AllComponentUstTimers_WL()
{
//���� �������� ���� ���� � ���������� ������� ���� ����
  INITtimersCOMPONENT_WL();//������������� �������� ���� ����������� �� ������ ��

  PREPAREustCOMPONENT_WL(INITUST_ALLCOMP);//���������� ������� ���� ���� ��
}//AllComponentUstTimers()

void DiskrRegList()
{
//������ 50 ����� ����� ������������
  TxtStreamInit(&CONTROL_STR, &KadrMenuFormat_reg, NULL);//���� ������ ������ � ������ �����
  Load2String(46, "����� ���");//������ 48 ����� �� 2 ������
}//DiskrRegList()

void Load1String(int maxStr, char *title)
{
//������ maxStr ����� �� 1 ������
 VIEW_STRUCT view_struct;
  //�������� ���
  memset((char*)stringList,   0, sizeof(stringList));
  memset((char*)&view_struct,   0, sizeof(VIEW_STRUCT));

  strcpy( stringList[0], title);
  strcpy( stringList[1], "-------------");

  int cntStr = 2;//�-�� ����������� �����
  for(; cntStr<maxStr; ){
  View1StrWin(&view_struct);//4-� �������� ���� ��������� �� 1 ������
  if(memcmp((char *)(&view_struct.stringWinOld),
            (char *)(&view_struct.stringWin),
            sizeof(WIN_STRUCT))!=0){
  //���� ������
  for(int i=0; i<4; i++)
      strcpy(stringList[cntStr +i],
             view_struct.stringWin.Win[i]);
  cntStr += 4;
  }//if
  else break;//���� ����������
  memcpy((char *)(&view_struct.stringWinOld),
         (char *)(&view_struct.stringWin),
         sizeof(WIN_STRUCT));
  TxtStreamPgDownButtonPrepare(&CONTROL_STR);//����������
  }//for
}//Load1String(int maxStr)

void Load2String(int maxStr, char *title)
{
//������ maxStr ����� �� 2 ������
  VIEW_STRUCT view_struct;
  //�������� ���
  memset((char*)stringList,   0, sizeof(stringList));
  memset((char*)&view_struct,   0, sizeof(VIEW_STRUCT));
  strcpy( stringList[0], title);
  strcpy( stringList[1], "-------------");

  int cntStr = 2;//�-�� ����������� �����
  for(; cntStr<maxStr; ){
  View2StrWin(&view_struct);//4-� �������� ���� ��������� �� 2 ������
  if(memcmp( (char *)(&view_struct.stringWinOld),
             (char *)(&view_struct.stringWin),
            sizeof(WIN_STRUCT))!=0){
  //���� ������
  for(int i=0; i<4; i++)
      strcpy( stringList[cntStr +i],
              view_struct.stringWin.Win[i]);
  cntStr += 4;
  }//if
  else break;//���� ����������
  memcpy((char *)(&view_struct.stringWinOld),
         (char *)(&view_struct.stringWin),
         sizeof(WIN_STRUCT));
  TxtStreamPgDownButtonPrepare(&CONTROL_STR);//����������
  }//for
}//Load2String(int maxStr)

void View2StrWin(void *vs)
{
//���� ��������� �� 2 ������
  VIEW_STRUCT *view_struct = (VIEW_STRUCT *)vs;
  memset((char *)&(view_struct->stringWin), 0,
         sizeof(WIN_STRUCT));
  WorkVariantChar workVariantCharLoc;//����� �����

  int tmp = TxtStreamIteratorBegin((void *)&workVariantCharLoc, &CONTROL_STR);//�������� ����

  if(tmp==-1) //����� ��� ��� ������
  {
    strcpy(view_struct->stringWin.Win[0], "�����");
    return ;
  }//if

  if(tmp==0) //��������� ����� �����
  {
    return ;
  }//if

  //�������� ���������
    strcpy(view_struct->stringWin.Win[0],
           workVariantCharLoc.TwoString[0]);
    strcpy(view_struct->stringWin.Win[1],
           workVariantCharLoc.TwoString[1]);

  if(TxtStreamIteratorMidle(&CONTROL_STR)==0) //�������� ����
  {
    //��������� ����� �����
    PNTCONTROL_STR->StpStringViewer = 0;//stp �������� ������
    return ;
  }//if
  //�������� ���������
    strcpy(view_struct->stringWin.Win[2],
           workVariantCharLoc.TwoString[0]);
    strcpy(view_struct->stringWin.Win[3],
           workVariantCharLoc.TwoString[1]);

  PNTCONTROL_STR->StpStringViewer = 1;//stp �������� ������

  TxtStreamIteratorEnd(&CONTROL_STR);//����� ��������

}//View2StrWin()

void ActualRegList()
{
//������ 50 ����� �������
  TxtStreamInit(&CONTROL_STR, &KadrMenuFormat_viewActual, NULL);//���� ������ ������ � ������ �����
  Load1String(46, "�������");//������ 48 ����� �� 1 ������
}//ActualRegList()

void ActualDVList()
{
//������ 50 ����� �������
 selectorUVVLow  = selectorDVLow;//�������� UVV ��������-���������� ��� �� 16 UVV
 selectorUVVMidd = selectorDVMidd;//�������� UVV ��������-���������� ��� cp 16 UVV
 selectorUVVHi   = selectorDVHi;//�������� UVV ��������-���������� ��� ct 16 UVV
  TxtStreamInit(&CONTROL_STR, &KadrMenuFormat_viewActualDV, NULL);//���� ������ ������ � ������ �����
  Load1String(46, "������� ��");//������ 48 ����� �� 1 ������
}//ActualDVList()

void ActualReleList()
{
//������ 50 ����� �������
 selectorUVVLow  = rele_bdvv1;//�������� UVV ��������-���������� ��� �� 16 UVV
 selectorUVVMidd = 0;//�������� UVV ��������-���������� ��� cp 16 UVV
 selectorUVVHi   = 0;//�������� UVV ��������-���������� ��� ct 16 UVV
  TxtStreamInit(&CONTROL_STR, &KadrMenuFormat_viewActualRele, NULL);//���� ������ ������ � ������ �����
  Load1String(46, "������� ����");//������ 48 ����� �� 1 ������
}//ActualReleList()

void View1StrWin(void *vs)
{
//���� ��������� �� 1 ������
  VIEW_STRUCT *view_struct = (VIEW_STRUCT *)vs;
  memset((char *)&(view_struct->stringWin), 0,
         sizeof(WIN_STRUCT));
  WorkVariantChar workVariantCharLoc;//����� �����

  int tmp = TxtStreamIteratorBegin((void *)&workVariantCharLoc, &CONTROL_STR);//�������� ����

  if(tmp==-1) //����� ��� ��� ������
  {
    strcpy(view_struct->stringWin.Win[0], "�����");
    return ;
  }//if

  if(tmp==0) //��������� ����� �����
  {
    return ;
  }//if
  //�������� ���������
    strcpy(view_struct->stringWin.Win[0],
           workVariantCharLoc.TwoString[0]);

  if(TxtStreamIteratorMidle(&CONTROL_STR)==0) //�������� ����
  {
    //��������� ����� �����
    PNTCONTROL_STR->StpStringViewer = 0;//stp �������� ������
    return ;
  }//if
  //�������� ���������
    strcpy(view_struct->stringWin.Win[1],
           workVariantCharLoc.TwoString[0]);

  if(TxtStreamIteratorMidle(&CONTROL_STR)==0) //�������� ����
  {
    //��������� ����� �����
    PNTCONTROL_STR->StpStringViewer = 1;//stp �������� ������
    return ;
  }//if
  //�������� ���������
    strcpy(view_struct->stringWin.Win[2],
           workVariantCharLoc.TwoString[0]);

  if(TxtStreamIteratorMidle(&CONTROL_STR)==0)
  {
    //��������� ����� �����
    PNTCONTROL_STR->StpStringViewer = 2;//stp �������� ������
    return ;
  }//if
  //�������� ���������
    strcpy(view_struct->stringWin.Win[3],
           workVariantCharLoc.TwoString[0]);

  TxtStreamIteratorEnd(&CONTROL_STR);//����� ��������

  PNTCONTROL_STR->StpStringViewer = 3;//stp �������� ������

}//View1StrWin()

void SelectorMNGBAZA(short baza)
{
//��������� ���� �������
  LIGHTMNGUBAZA = baza;
  LIGHTMNGUOFFSET = 0;
}//SelectorMNGBAZA(short baza)

void SelectorLIGHTLINE(void *txtstrm)
{
//����� ������������ ������
  LIGHTLINEMENU = TxtStreamIdxKadr(txtstrm);
}//SelectorLIGHTLINE()

void SelectorCRRLIGHTLINE()
{
//����� ������������ ������ �������� ����� ������
  SelectorLIGHTLINE(CRR_TEXTSTREAM);//����� ������������ ������ �������� ����� ������
}//SelectorCRRLIGHTLINE()

void SelectorSUBMENU(void *sub_menu)
{
//�c�������� ������� �������
  CRR_SUBMENU = sub_menu;//������� �������
}//SelectorSUBMENU(void *sub_menu)

void SelectorTEXTCONTROL(void *control)
{
//���������� ������� ������ �� ��������� �����
 CRR_TEXTSTREAM = control;
}//SelectorTEXTSTREAM(void *control)

void SelectorFHOME(void (*pFncGlobal)(short))
{
//��������� �� �-��� HOME
//  CRR_FHOME = &PereinitUstListCompAPV;//��������� �� �-��� HOME
  CRR_FHOME = pFncGlobal;//��������� �� �-��� HOME
}//SelectorFHOME(void (*pFncGlobal)(short))

void InitFHOME(short flag)
{
//��������
  CRR_FHOME(flag);//������� �-��� HOME
}//InitFHOME(short flag)

