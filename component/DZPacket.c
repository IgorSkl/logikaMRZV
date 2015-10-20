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
#include "virtualMenu\textstreamdef.h"
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
#define KOD_COMPONENT  DZ_COMP1
//�-�� ��������
#define CNT_STUPEN_DZ  5

//������ ������ - ������������
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern LineMenuItem sub_menu_cnf[];
extern char deleteComp[];

extern char DZ1_TITLE[];
extern char DZ2_TITLE[];
extern char DZ3_TITLE[];
extern char DZ4_TITLE[];
extern char DZ5_TITLE[];

StreamControl controlStruct_DZ;//������ ���������

void MakePacketDZ();
char copyDZ1ToRepozitar(char packet);
char copyDZ2ToRepozitar(char packet);

char  *nameStupenDZ[CNT_STUPEN_DZ] = {DZ1_TITLE,
                                      DZ2_TITLE,
                                      DZ3_TITLE,
                                      DZ4_TITLE,
                                      DZ5_TITLE
                                     };//��������� �� ����� ��������
//���� DZ
LineMenuItem sub_menu_DZ[CNT_STUPEN_DZ+4] =
{
  { "��", NULL},//title
  { &controlStruct_DZ, sub_menu_cnf},//control_item, parent
  { deleteComp, (void *)&DeleteComponent1, typeMenuProg},
  { NULL, NULL}
};

char copyDZpacketToRepozitar(char packet)
{
  rpzcomponent_obj.kodC    = KOD_COMPONENT; //��� ����������
  rpzcomponent_obj.cntClon = CNT_STUPEN_DZ;//�-�� ������

  if(packet)  return 1;//�������� �����������
//����� � ������ ����� �� �����
  short dx=0;
  while(cnfCOMPONENT[dx].componentEnable)
  {
    //����� ��������� ����������
    if(cnfCOMPONENT[dx].packet==DZ_PACKET) return 1;//�������� �����������
    dx++;
  }//while

  MakeEmptyTopSub_menu(&(sub_menu_cnf[0]),
                       MAX_CNFCOMPONENT*sizeof(LineMenuItem));//�������� ������ ������ � top sub_menu
//����� ���� � ������
  sub_menu_cnf[1+SUBDATA].Line2 = sub_menu_DZ; //���� ����������
  sub_menu_cnf[1+SUBDATA].TypesWin = typeMenuSub;

  TxtStreamInit(&CONTROL_CNF, &KadrMenuFormat_sub, sub_menu_cnf);//���� control � ������ �����

//---------DZ5------------------------------
  copyDZ2ToRepozitar(0);//���������������� � �����������
  rpzcomponent_obj.twinControl[2].twin_different();//diff to DZ4
  rpzcomponent_obj.packet = DZ_PACKET;    //����� ��������� ����������

  MakePacketDZ();//������� DZ5
//---------------------------------------------

//---------DZ4------------------------------
  copyDZ2ToRepozitar(0);//���������������� � �����������
  rpzcomponent_obj.twinControl[1].twin_different();//diff to DZ4
  rpzcomponent_obj.packet = DZ_PACKET;    //����� ��������� ����������

  MakePacketDZ();//������� DZ4
//---------------------------------------------

//---------DZ3------------------------------
  copyDZ2ToRepozitar(0);//���������������� � �����������
  rpzcomponent_obj.twinControl[0].twin_different();//diff to DZ3
  rpzcomponent_obj.packet = DZ_PACKET;    //����� ��������� ����������

  MakePacketDZ();//������� DZ3
//---------------------------------------------

//---------DZ2------------------------------
  copyDZ2ToRepozitar(0);//���������������� � ����������� DZ2
  rpzcomponent_obj.packet = DZ_PACKET;    //����� ��������� ����������
  MakePacketDZ();//������� DZ2
//---------------------------------------------


//---------DZ1------------------------------
  copyDZ1ToRepozitar(0);//���������������� � ����������� DZ1

  rpzcomponent_obj.packet = -CNT_STUPEN_DZ;    //�-�� ������ � ������
  //�������� ��� ������
  strcat(rpzcomponent_obj.nameComponent, " ��");
  short ii=0;
  while(rpzcomponent_obj.nameComponent[ii]!=' ')
  {
    ii++;
  }
  rpzcomponent_obj.nameComponent[ii] = 0;

  MakePacketDZ();//������� DZ1


  //����� �������� DZ
  sub_menu_DZ[1+SUBDATA].Line1         = nameStupenDZ[0];
  sub_menu_DZ[1+1+SUBDATA].Line1       = nameStupenDZ[1];
  sub_menu_DZ[1+1+1+SUBDATA].Line1     = nameStupenDZ[2];
  sub_menu_DZ[1+1+1+1+SUBDATA].Line1   = nameStupenDZ[3];
  sub_menu_DZ[1+1+1+1+1+SUBDATA].Line1 = nameStupenDZ[4];

//---------------------------------------------
  return 1;//�������� �����������
}//copyDZpacketToRepozitar()

void MakePacketDZ()
{
//������� �����
//���������� � ����
  memcpy((void*)getShadowBuf(), cnfCOMPONENT, sizeof(COMPONENT_OBJ)*MAX_CNFCOMPONENT);

  memcpy(&(cnfCOMPONENT[0]), &rpzcomponent_obj, sizeof(COMPONENT_OBJ));

//���������� �� ����
  memcpy(&(cnfCOMPONENT[1]), (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(MAX_CNFCOMPONENT-1));

  MakeEmptyTopSub_menu(&(sub_menu_DZ[0]), sizeof(sub_menu_DZ));//�������� ������ ������ � top sub_menu
//����� ���� � ������
  sub_menu_DZ[1+SUBDATA].Line2 = (void *)&OpenMenuComponent; //���� ����������
  sub_menu_DZ[1+SUBDATA].TypesWin = typeMenuProg;

  TxtStreamInit(&controlStruct_DZ, &KadrMenuFormat_sub, sub_menu_DZ);//���� control � ������ �����
//���������������� ������ � ������������
  initCOMPONENT(INITUST_TOPCOMP);
}//MakePacket()


