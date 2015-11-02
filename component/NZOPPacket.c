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
#include "virtualMenu\ustmanagerdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"

#include "virtualMenu\viewMenuList.h"
#include "virtualMenu\viewmenusub.h"
#include "psuperVisor\psupervisor.h"


//��� �����������
#define KOD_COMPONENT  NZOP_COMP1
//�-�� ��������
#define CNT_STUPEN_NZOP  2

//������ ������ - ������������
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern LineMenuItem sub_menu_cnf[];
extern char deleteComp[];

extern char NZOP1_TITLE[];
extern char NZOP2_TITLE[];

StreamControl controlStruct_NZOP;//������ ���������

void MakePacketNZOP();
char copyNZOP1ToRepozitar(char packet);
char copyNZOP2ToRepozitar(char packet);

char  *nameStupenNZOP[CNT_STUPEN_NZOP] = {NZOP1_TITLE,
                                          NZOP2_TITLE
                                         };//��������� �� ����� ��������

//���� NZOP
LineMenuItem sub_menu_NZOP[CNT_STUPEN_NZOP+4] =
{
  { "����", NULL},//title
  { &controlStruct_NZOP, sub_menu_cnf},//control_item, parent
  { deleteComp, (void *)&DeleteComponent1, typeMenuProg},
  { NULL, NULL}
};

char copyNZOPpacketToRepozitar(char packet)
{
  rpzcomponent_obj.kodC   = KOD_COMPONENT; //��� ����������
  rpzcomponent_obj.cntClon = CNT_STUPEN_NZOP;//�-�� ������

  if(packet)  return 1;//�������� �����������
//����� � ������ ����� �� �����
  short dx=0;
  while(cnfCOMPONENT[dx].componentEnable)
  {
    //����� ��������� ����������
    if(cnfCOMPONENT[dx].packet==NZOP_PACKET) return 1;//�������� �����������
    dx++;
  }//while

  MakeEmptyTopSub_menu(&(sub_menu_cnf[0]),
                       MAX_CNFCOMPONENT*sizeof(LineMenuItem));//�������� ������ ������ � top sub_menu
//����� ���� � ������
  sub_menu_cnf[1+SUBDATA].Line2 = sub_menu_NZOP; //���� ����������
  sub_menu_cnf[1+SUBDATA].TypesWin = typeMenuSub;

  TxtStreamInit(&CONTROL_CNF,   &KadrMenuFormat_sub, sub_menu_cnf);//���� control � ������ �����

//---------NZOP2------------------------------
  copyNZOP1ToRepozitar(0);//���������������� � �����������
  rpzcomponent_obj.twinControl[0].twin_different();//diff to NZOP2
  rpzcomponent_obj.packet = NZOP_PACKET;    //����� ��������� ����������

  MakePacketNZOP();//������� ����� NZOP

//---------NZOP1------------------------------
  copyNZOP1ToRepozitar(0);//���������������� � ����������� NZOP1
  rpzcomponent_obj.packet = -CNT_STUPEN_NZOP;    //�-�� ������ � ������
  //�������� ��� ������
  strcat(rpzcomponent_obj.nameComponent, " ����");
  short ii=0;
  while(rpzcomponent_obj.nameComponent[ii]!=' ')
  {
    ii++;
  }
  rpzcomponent_obj.nameComponent[ii] = 0;

  MakePacketNZOP();//������� ����� NZOP

  //����� �������� NZOP
  sub_menu_NZOP[1+SUBDATA].Line1     = nameStupenNZOP[0];
  sub_menu_NZOP[1+1+SUBDATA].Line1   = nameStupenNZOP[1];

  return 1;//�������� �����������
}//copyNZOPpacketToRepozitar()

void MakePacketNZOP()
{
//������� �����
//���������� � ����
  memcpy((void*)getShadowBuf(), cnfCOMPONENT, sizeof(COMPONENT_OBJ)*MAX_CNFCOMPONENT);

  memcpy(&(cnfCOMPONENT[0]), &rpzcomponent_obj, sizeof(COMPONENT_OBJ));

//���������� �� ����
  memcpy(&(cnfCOMPONENT[1]), (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(MAX_CNFCOMPONENT-1));

  MakeEmptyTopSub_menu(&(sub_menu_NZOP[0]), sizeof(sub_menu_NZOP));//�������� ������ ������ � top sub_menu
//����� ���� � ������
  sub_menu_NZOP[1+SUBDATA].Line2 = (void *)&OpenMenuComponent; //���� ����������
  sub_menu_NZOP[1+SUBDATA].TypesWin = typeMenuProg;

  TxtStreamInit(&controlStruct_NZOP, &KadrMenuFormat_sub, sub_menu_NZOP);//���� control � ������ �����
//���������������� ������ � ������������
  initCOMPONENT(INITUST_TOPCOMP);
}//MakePacket()


