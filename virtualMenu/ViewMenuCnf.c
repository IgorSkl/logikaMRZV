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
extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������

//������ ������ - ������������
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ  cnfCOMPONENT_WL[];
extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_cnfwl[];
extern LineMenuItem sub_menu_rpz[];

char addComp[] = "�������� ���������...";
char deleteComp[] = "������� ���������...";
char deleteComp_WL[] = "������� �� ��...";

void ResetConfig()
{
//�������� �����������
  cnfCOMPONENT[0].componentEnable = 0;
  sub_menu_cnf[1+SUBDATA].Line1 = addComp;
  sub_menu_cnf[1+SUBDATA].Line2 = (void*)RpzComponent;
  sub_menu_cnf[1+SUBDATA].TypesWin = typeMenuProg;

  sub_menu_cnf[1+1+SUBDATA].Line1 = NULL;
  sub_menu_cnf[1+1+SUBDATA].Line2 = NULL;
}//ResetConfig()

void PereinitCnf(short flg)
{
//�������� ������������
  TxtStreamInit(&CONTROL_CNF,
                &KadrMenuFormat_sub, sub_menu_cnf);//���� control � ������ �����

  PNTCRR_TEXTSTREAM->PntStringViewer = 0;
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_CNF, SIZE_PAGE_VIEW);//������� �� END
  }//if
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
  LanderPStr();//���������� ��������� ������
}//PereinitCnf()

void OpenMenuCnf()
{
//������� ���� cnf
  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control

//  CRR_TEXTSTREAM = &CONTROL_CNF;//����� ������� control
  SelectorTEXTCONTROL(&CONTROL_CNF);//����� ������� control
  PereinitCnf(1);//�-��� �������� ������������
//  CRR_FHOME = &PereinitCnf;//��������� �� �-��� HOME
  SelectorFHOME(&PereinitCnf);//��������� �� �-��� HOME
}//OpenMenuCnf()

void PereinitAvaitCnf(short flg)
{
//��������
  TxtStreamInit(&CONTROL_RPZ, &KadrMenuFormat_sub, sub_menu_rpz);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_RPZ, SIZE_PAGE_VIEW);//������� �� END
  }//if
  ViewDiskrMenu(typeMenuCnf);//������� ���� �����������
  LanderPStr();//���������� ��������� ������
}//PereinitAvaitCnf()

short SearchCnfClonComponent(short kC)
{
//������ � cnf �-�� ������ ������� ����������
  short next = 0;
  short cntC = 0;//�-�� ������ ����������
  while (cnfCOMPONENT[next].componentEnable)   //��� ���������� � ������������
  {
    if(cnfCOMPONENT[next].kodC==kC) cntC++;
    next++;
  }//while
  return cntC;
}//SearchCnfClonComponent(short kC)

short SearchCnfClonToComponent(short kC, short nC)
{
//������ � cnf ������ ���� ������� ����������
  short next = 0;
  short idxC = -1;//������ ���������� � cnf
  while (cnfCOMPONENT[next].componentEnable)   //��� ���������� � ������������
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
//������ � cnf �� ������ ���� ������� ����������
  short next = 0;
  short idxC = -1;//������ ���������� � cnf
  while (cnfCOMPONENT_WL[next].componentEnable)   //��� ���������� � ������������
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
//��������� ������������
//  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);//������ ��� �����
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  short numK = GetKodCompRpz(LIGHTLINEMENU);//�������� �� ������ ������ ����������� ��� ����������

  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_cnf;// parent
//  CRR_SUBMENU = sub_menu_tmp;//������� �������
  SelectorSUBMENU(sub_menu_tmp);//�c�������� ������� �������

  AddCompIzRpz(numK);//�������� ��������� �� �����������

  FvmenuDis->Str1Label->Caption = "���������";
  FvmenuDis->Str2Label->Caption = (char *)sub_menu_cnf[1+SUBDATA].Line1;
  FvmenuDis->Str3Label->Caption = "��������";
  FvmenuDis->Str4Label->Caption = "";

  ResetAllButton();//�������� ��� �������
*/
}//ConfigMaker()
/*
void __fastcall TFvmenuDis::ConfirmDeleteButtonClick(TObject *Sender)
{
  ConfirmDeleteButton();
  ResetUpDown(); //�������� Up Down
}//ConfirmDeleteButton(TObject *Sender)

void __fastcall TFvmenuDis::ConfirmDeleteButtonWLClick(TObject *Sender)
{
  ConfirmDeleteButton_WL();//������� �� ��
  ResetUpDown(); //�������� Up Down
}//ConfirmDeleteButtonWLClick(TObject *Sender)
*/
void newsub_menu_cnf_Line1()
{
//����� ����� ���� cnf
//� ���� cnf ������������ ������ ����� ��� ������ ����.packet ������� ���=0 ���<0
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
    if(cnfCOMPONENT[dx].packet<0) //������ ������
    {
      short ii=0;//������ ��� ������
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
//�������� �� ������ ����� ����� ����� ��� cnf
/*
  short dx=0;//������ �������� �����
  short tmpCnfLin = lin;
  short bazaPkt=0;
  short pkt=0;
  short cntNoPkt=0;//�-�� ���������
  short nC=0;//����� �����

  //������� �������� ����
  while (cnfCOMPONENT[dx].componentEnable)   //��� ���������� � ������������
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
  //������� ��������
  while (cnfCOMPONENT[dx].componentEnable)   //��� ���������� � ������������
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

  nC= bazaPkt+cntNoPkt;//����� �����

  return nC;
*/
 return 0;
}//GetFromLinToClonCnf(short lin)

short GetFromLinToClonCnf_WL(short lin)
{
/*
//�������� �� ������ ����� ����� ����� ��� cnf ��
  short dx=0;//������ �������� �����
  short tmpCnfLin = lin;
  short bazaPkt=0;
  short pkt=0;
  short cntNoPkt=0;//�-�� ���������
  short nC=0;//����� �����

  //������� �������� ����
  while (cnfCOMPONENT_WL[dx].componentEnable)   //��� ���������� � ������������
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
  //������� ��������
  while (cnfCOMPONENT_WL[dx].componentEnable)   //��� ���������� � ������������
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

  nC= bazaPkt+cntNoPkt;//����� �����

  return nC;
*/
 return 0;
}//GetFromLinToClonCnf_WL(short lin)

short GetFromLinToClonPkt(short Lin)
{
/*
//�������� �� ������ ����� ����� ����� ��� ������
  //������ �������� �����
  short dx=0;
  short bazaPkt=0;
  short pkt=0;
  short cntNoPkt=0;//�-�� ���������
  short shiftPkt = 0;//�������� ������ ������
  short nC=0;//����� �����

  short cnfLin = TxtStreamIdxKadr(&CONTROL_CNF);//���� ������������
  short tmpCnfLin = cnfLin;

  shiftPkt = Lin;//�������� ������ ������
  //������� �������� ����
  while (cnfCOMPONENT[dx].componentEnable)   //��� ���������� � ������������
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

  tmpCnfLin=cnfLin;//���� ������������
  dx=0;
  //������� ��������
  while (cnfCOMPONENT[dx].componentEnable)   //��� ���������� � ������������
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


  nC= bazaPkt+cntNoPkt +shiftPkt;//����� �����
  return nC;
*/
 return 0;
}//

void newsub_menu_cnfwl_Line1()
{
//����� ����� ���� cnfwl
//� ���� cnf ������������ ������ ����� ��� ������ ����.packet ������� ���=0 ���<0
  short i=1+SUBDATA;
  short dx=0;
  while(cnfCOMPONENT_WL[dx].componentEnable)
  {
    if(cnfCOMPONENT_WL[dx].packet==0)
    {
      sub_menu_cnfwl[i].Line1 = cnfCOMPONENT_WL[dx].nameComponent;
      i++;
    }//if
    if(cnfCOMPONENT_WL[dx].packet<0) //������ ������
    {
      short ii=0;//������ ��� ������
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


