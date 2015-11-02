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

//��� �����������
#define KOD_COMPONENT  WL_COMP1
//�-�� ��������
#define CNT_STUPEN_WL  1

#endif // _HIDE_COMPONENT

//������������� �������  � ��������� �������
//������� ��������
//�-�� ������� � ��������� �������
#define MNGUST_WL_TOTAL  0

//������������� ENA ������
//�-�� ENA ������
#define ENACMD_WL_TOTAL 0

//������������� ������� � �����������
//�-�� ������� � �����������
#define SPVUST_WL_TOTAL  0

//---------------IO COMMAND------------------
//������������� IO ������ ��� WL
//��� IO1
#define IOCMD1_WL 0
//�-�� IO ������
#define IOCMD_WL_TOTAL    1

//---------------TL COMMAND------------------
//������������� TL ������ ��� WL
//�-�� TL ������
#define TLCMD_WL_TOTAL    0

#ifndef _HIDE_COMPONENT

//��������� ��
#define LIGHTLE    LIGHTRANGUVV

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������

extern LineMenuItem sub_menu_cnfwl[];

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//������� ������� �����������
extern char *bitStringUNI[];
extern int  TypLE[];
extern int  IndexIO;//������ IO

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

int SelectTypViewLE;//������ ��� ��� view ����
char titleLE[30]="";

int  offsetIOCmdWL;//�������� ��� IO WL

char WL_TITLE[] = "��";

IONAMESTATUS_COMPONENT ionsWL[IOCMD_WL_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ��"
  }
};

LineMenuItem sub_menu_comp_WL[8] =
{
  { "��", NULL},//title
  { &CONTROL1_COMP, &sub_menu_cnf,   typeMenuSub},//control_item, parent
  { "��� ��������",  (void*)&OpenMenuWL, typeMenuProg},
  { "������������ ��", sub_menu_cnfwl,  typeMenuCnfWL},//������������
  { NULL, NULL}
};

LineMenuItem sub_menu_widel[] =
{
  { "��� ��������", NULL},//title
  { &CONTROL_WDL, &sub_menu_comp_WL, typeMenuSub},//control_item, parent
/*
  { "��1 ��� ����� ��������1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "��2 ��� ����� ��������1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "��3 ��� ����� ��������1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "��4 ��� ����� ��������1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "��5 ��� ����� ��������1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "��6 ��� ����� ��������1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "��7 ��� ����� ��������1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "��8 ��� ����� ��������1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "��9 ��� ����� ��������1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "��10 ��� ����� ��������1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "��11 ��� ����� ��������1234",   (void*)&OpenMenuLE, typeMenuProg},
  { "��12 ��� ����� ��������1234",   (void*)&OpenMenuLE, typeMenuProg},
  { " ����� ���� ��������", (void*)&SelectTypLE, typeMenuProg},// sub_menu_typWL,  typeMenuSub},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_typLE[] =
{
  { titleLE, NULL},//title
  { &CONTROL_TLE, sub_menu_widel},//control_item, parent
  { " ������� ����",     (void*)&OpenTypLE, typeMenuProg},
  { " ������� ���",      (void*)&OpenTypLE, typeMenuProg},
  { " ������� �",        (void*)&OpenTypLE, typeMenuProg},
  { " ������� ���� ���", (void*)&OpenTypLE, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_viewWL[] =
{
  { titleLE, NULL },//title
  { &CONTROL_EWL, sub_menu_widel}//control_item, parent
};

void OpenMenuLE()
{
//������� ���� ��� ��������
  LIGHTLE = LIGHTLINEMENU;//��������� ��
  //��������� ��
  sprintf(titleLE, "��%d", LIGHTLE+1);//������� ����
  SetTitleLE(LIGHTLE, titleLE);//��������� ��

  if(SelectTypViewLE) //������ ��� ��� ������ ����
  {
    //��� ��������
    CRR_SUBMENU = sub_menu_typLE;//������� �������
    CRR_TEXTSTREAM = &CONTROL_TLE;//������� control
    TxtStreamInit(&CONTROL_TLE, &KadrMenuFormat_sub, sub_menu_typLE);//���� ������ ������ � ������ �����
    PNTCRR_SUBMENU(SUBDATA).TypesWin = typeMenuSub;
    convert_submenutyp(TypLE[LIGHTLE]);//�������������� ������ sub_menu_typWL
    ViewDiskrMenu(typeMenuSub);//������� ���� �����������
  }//
  else
  {
    //������ ��������
    CRR_SUBMENU = sub_menu_viewWL;//������� �������
    PNTCRR_SUBMENU(SUBDATA).TypesWin = typeMenuViewLE;
    OpenViewLE();
  }
}//OpenMenuLE()

void OpenMenuWL()
{
  CRR_SUBMENU = sub_menu_widel;
  CRR_TEXTSTREAM = &CONTROL_WDL;//������� control
  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control

  SetNameMenuTyp();//����� ���� ����

  SetAllTitleLE();//������������ ��� ��������� ��� ���������

  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
}//OpenMenuWL()

void SetNameMenuTyp()
{
//����� ���� ����
  //char locTxt[20];
  short size_avait = TxtStreamMaxKadr(&CONTROL_WDL);//���� �-�� ������
  if(SelectTypViewLE) //������ ��� ��� view ����
  {
    strcpy((char*)sub_menu_widel[SUBDATA+1 +size_avait-1].Line1,
           "��� ��������"
          );
  }//if
  else
  {
    strcpy((char*)sub_menu_widel[SUBDATA+1 +size_avait-1].Line1,
           "������ ��������"
          );
  }
}//SetNameMenuTyp()

void SelectTypLE()
{
//������������� �� ��� ��������
  CRR_SUBMENU = sub_menu_widel;
  CRR_TEXTSTREAM = &CONTROL_WDL;//������� control
  if(SelectTypViewLE) //������ ��� ��� ���� ����
  {
    SelectTypViewLE = 0;
  }//if
  else
  {
    SelectTypViewLE = 1;
  }
  SetNameMenuTyp();//����� ���� ����

  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
}//SelTypLE()

void SetAllTitleLE()
{
//������������ ��� ��������� ��� ���������
  char locTxt[20];
  short size_avait = TxtStreamMaxKadr(&CONTROL_WDL);//���� �-�� ������
  //����� ������ ����
  for(int i=0; i<size_avait-1; i++)
  {
    sprintf(locTxt, "��%d", i+1);//������� ����
    strcpy((char*)sub_menu_widel[SUBDATA+1 +i].Line1, locTxt);

    SetTitleLE(i, (char*)sub_menu_widel[SUBDATA+1 +i].Line1);//��������� ��

  }//for
}//SetAllTitleLE()

//��� ��� ��������
//0-����
//1-���
//2-�
//3-���� ���
void OpenTypLE()
{

  CRR_SUBMENU = sub_menu_typLE;
  short iKadr = TxtStreamIdxKadr(&CONTROL_TLE);
  convert_submenutyp(iKadr);//�������������� ������ sub_menu_typWL

  TypLE[LIGHTLE] = iKadr;//���������� ����� ��� ��
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������

  SetAllTitleLE();//������������ ��� ��������� ��� ���������
}//OpenTypLE()

void convert_submenutyp(short numStr)
{
//�������������� ������ sub_menu_typWL
  ((char*)sub_menu_typLE[SUBDATA+1 +0].Line1)[0] = ' ';
  ((char*)sub_menu_typLE[SUBDATA+1 +1].Line1)[0] = ' ';
  ((char*)sub_menu_typLE[SUBDATA+1 +2].Line1)[0] = ' ';
  ((char*)sub_menu_typLE[SUBDATA+1 +3].Line1)[0] = ' ';
  ((char*)sub_menu_typLE[SUBDATA+1 +numStr].Line1)[0] = '*';
}//convert_submenutyp(short numStr)

int initUstWL(char init)
{
  //������� �������
  if (init)
  {
  }//if

  IndexUstSPV += SPVUST_WL_TOTAL;//������ ������� � �����������
  return MNGUST_WL_TOTAL;//�-�� ������� � ��������� �������
}//initUstMTZ1(short mngUst, char init)

void  prepareUstWL(short idxC)
{
  //���������� ENA ������ ��� �����
}//prepareUstMTZ1(short idxC)

int initIOCmd_WL()
{
  //������� IO ������
  offsetIOCmdWL = IndexIO;//�������� ��� IO WL
  return commonInitIOCmd(IOCMD_WL_TOTAL);
}//initIOCmd_WL()

int initTLCmd_WL()
{
  //������� TL ������
  return commonInitTLCmd(TLCMD_WL_TOTAL);
}//initTLCmd_WL()

int initENACmd_WL()
{
  //������� ENA ������
  return commonInitENACmd(ENACMD_WL_TOTAL);
}//initENACmd_WL()

void initTimersWL(short idxC)
{
  //������ � ������� ��������
}//initTimersWL(short idxC)

int codecUstWL(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  return 1;
}//codecUstWL(char *buf, short offset, int ust)

int isDISactiv_WL(int idxC)
{
 //���������� ������������ ���
  return 0;//��� ����������
}//isDISactiv_WL(int idxC)

char copyWLToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//������� ������
//���������� ��������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.packet = 0;    //����� ��������� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  WL_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_WL;//���� ����������

  rpzcomponent_obj.cntClon     = CNT_STUPEN_WL;   //max �-�� ������
  rpzcomponent_obj.numClon     = 1;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstWL;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstWL;//���������� �������
  rpzcomponent_obj.initIOCmd      = initIOCmd_WL;      //������� IO ������
  rpzcomponent_obj.initTLCmd      = initTLCmd_WL;      //������� TL ������
  rpzcomponent_obj.initENACmd     = initENACmd_WL;     //������� ENA ������
  rpzcomponent_obj.bo_bvCmd       = NULL; //��������� �� �� ������
  rpzcomponent_obj.isDISactiv     = isDISactiv_WL; //���������� ������������ ���
  rpzcomponent_obj.setBOBVtimer   = NULL; //������� �������� �� ��

  rpzcomponent_obj.nameStatusIO = ionsWL;          //����� � ������ ������ IO
  rpzcomponent_obj.initTimers   = initTimersWL;    //������ � ������� ��������
  rpzcomponent_obj.logic        = logicWL;         //������ ����������

  rpzcomponent_obj.codecUst = codecUstWL;   //����������-������������� �������

  return 0;//�� �������� �����������
}//

#endif // _HIDE_COMPONENT

