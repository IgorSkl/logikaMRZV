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
#include "psuperVisor\supermanager.h"
#include "virtualMenu\systemmenudef.h"
#include "component\componentdef.h"
#include "virtualMenu\repozitdef.h"

#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\repozitfnc.h"

#include "virtualMenu\viewMenuCnf.h"
#include "virtualMenu\viewMenuSub.h"
#include "virtualMenu\viewMenuWideLog.h"

#include "..\bazis.h"

extern LineMenuItem sub_menu_cnfwl[];

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������

char copyOFToRepozitar(char packet);
char copyPFToRepozitar(char packet);

//��������� ����������
LineMenuItem sub_menu_rpzWL[MAX_WLCOMPONENT+3] =
{
  { "����������� ��", NULL},//title
  { NULL, NULL}
};


//����������� ����������� ��
ELEMENT_RPZ  rpzCOMPONENT_WL[] =
{

  {
    //OF
    1,
    &copyOFToRepozitar,
    {OF_COMP1}
  },

  {
    //PF
    1,
    &copyPFToRepozitar,
    {PF_COMP1}
  },

  {
    //NULL
    0
  }
};

void  RpzComponentWL()
{
//��������� ����������
//��������� ��� ����������
  short i=0;
  while(rpzCOMPONENT_WL[i].componentEnable)
  {
    rpzCOMPONENT_WL[i].componentPermission = 1;//��������� �������
    i++;
  }//while

//������ �� �-�� ������
  i=0;
  short kC;         //��� ����������
  short cntC;//�-�� ������ ����������
  while(rpzCOMPONENT_WL[i].componentEnable)
  {
    rpzCOMPONENT_WL[i].load2RPZ(1);//��������� � �����������
    kC = rpzcomponent_obj.kodC;         //��� ����������
//������ � cnf �-�� ������ ������� ����������
    cntC = SearchCnfClonComponent(kC);
    if(cntC>=rpzcomponent_obj.cntClon)
      rpzCOMPONENT_WL[i].componentPermission = 0;//��� �������
    i++;
  }//while

//���������� ������ ���������� ����������
//����� �����������
  short rpzI=0;
  short mnI=0;
  while(rpzCOMPONENT_WL[rpzI].componentEnable)
  {
    if(rpzCOMPONENT_WL[rpzI].load2RPZ(1));//��������� � �����������
    else strcpy(rpzCOMPONENT_WL[rpzI].rpzKodName.rpzNameComponent, rpzcomponent_obj.nameComponent);

      sub_menu_rpzWL[mnI+1+SUBDATA].Line1 = rpzCOMPONENT_WL[rpzI].rpzKodName.rpzNameComponent;//name
      sub_menu_rpzWL[mnI+1+SUBDATA].Line2 = (void *)&ConfigMakerWL;//�������� � ������ ��
      sub_menu_rpzWL[mnI+1+SUBDATA].TypesWin = typeMenuProg;
      mnI++;

    rpzI++;
  }//while

  sub_menu_rpzWL[mnI+1+SUBDATA].Line1 = NULL;
  sub_menu_rpzWL[mnI+1+SUBDATA].Line2 = NULL;

  sub_menu_rpzWL[SUBDATA].Line1 = &CONTROL_RPZ;//control
  sub_menu_rpzWL[SUBDATA].Line2 = sub_menu_cnfwl;//parent
  sub_menu_rpzWL[SUBDATA].TypesWin = typeMenuSub;

//  CRR_SUBMENU = sub_menu_rpzWL;//������� �������
  SelectorSUBMENU(sub_menu_rpzWL);//�c�������� ������� �������

//  CRR_TEXTSTREAM = &CONTROL_RPZ;//������� control
  SelectorTEXTCONTROL(&CONTROL_RPZ);//���������� ������� ������ �� ��������� �����

  PereinitRpzWL(1);//��������
//  CRR_FHOME = &PereinitRpzWL;//��������� �� �-��� HOME
  SelectorFHOME(&PereinitRpzWL);//��������� �� �-��� HOME

}//RpzComponentWL()

void PereinitRpzWL(short flg)
{
//��������
  TxtStreamInit(&CONTROL_RPZ, &KadrMenuFormat_sub, sub_menu_rpzWL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_RPZ, SIZE_PAGE_VIEW);//������� �� END
  }//if
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
  LanderPStr();//���������� ��������� ������
}//PereinitRpzWL()

short GetOffsetClonRpzWL(short numK)
{
//�������� �������� ����������� �� ���� ����������
  short i=0;
  while(rpzCOMPONENT_WL[i].componentEnable)
  {
    if(rpzCOMPONENT_WL[i].rpzKodName.kodC==numK)
      return i;
    i++;
  }//while
  return 0;
}//GetOffsetClonRpzWL(short numK)



