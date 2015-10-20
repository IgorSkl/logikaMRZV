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
#define KOD_COMPONENT  MTZ_COMP1
//�-�� ��������
#define CNT_STUPEN_MTZ  5

//������ ������ - ������������
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern LineMenuItem sub_menu_cnf[];
extern char deleteComp[];

extern char MTZ1_TITLE[];
extern char MTZ2_TITLE[];
extern char MTZ3_TITLE[];
extern char MTZ4_TITLE[];
extern char MTZ5_TITLE[];

StreamControl controlStruct_MTZ;//������ ���������

void MakePacketMTZ();
char copyMTZ1ToRepozitar(char packet);
char copyMTZ2ToRepozitar(char packet);

char  *nameStupenMTZ[CNT_STUPEN_MTZ] = {MTZ1_TITLE,
                                        MTZ2_TITLE,
                                        MTZ3_TITLE,
                                        MTZ4_TITLE,
                                        MTZ5_TITLE
                                       };//��������� �� ����� ��������

//���� MTZ
LineMenuItem sub_menu_MTZ[CNT_STUPEN_MTZ+4] =
{
  { "���", NULL},//title
  { &controlStruct_MTZ, sub_menu_cnf},//control_item, parent
  { deleteComp, (void *)&DeleteComponent1, typeMenuProg},
  { NULL, NULL}
};

char copyMTZpacketToRepozitar(char packet)
{
  rpzcomponent_obj.kodC    = KOD_COMPONENT; //��� ����������
  rpzcomponent_obj.cntClon = CNT_STUPEN_MTZ;//�-�� ������

  if(packet)  return 1;//�������� �����������
//����� � ������ ����� �� �����
  short dx=0;
  while(cnfCOMPONENT[dx].componentEnable)
  {
    //����� ��������� ����������
    if(cnfCOMPONENT[dx].packet==MTZ_PACKET) return 1;//�������� �����������
    dx++;
  }//while

  MakeEmptyTopSub_menu(&(sub_menu_cnf[0]),
                       MAX_CNFCOMPONENT*sizeof(LineMenuItem));//�������� ������ ������ � top sub_menu
//����� ���� � ������
  sub_menu_cnf[1+SUBDATA].Line2 = sub_menu_MTZ; //���� ����������
  sub_menu_cnf[1+SUBDATA].TypesWin = typeMenuSub;

  TxtStreamInit(&CONTROL_CNF,   &KadrMenuFormat_sub, sub_menu_cnf);//���� control � ������ �����

//---------MTZ5------------------------------
  copyMTZ2ToRepozitar(0);//���������������� � �����������
  rpzcomponent_obj.twinControl[2].twin_different();//diff to MTZ5
  rpzcomponent_obj.packet = MTZ_PACKET;    //����� ��������� ����������

  MakePacketMTZ();//������� ����� MTZ
//---------------------------------------------

//---------MTZ4------------------------------
  copyMTZ2ToRepozitar(0);//���������������� � �����������
  rpzcomponent_obj.twinControl[1].twin_different();//diff to MTZ4
  rpzcomponent_obj.packet = MTZ_PACKET;    //����� ��������� ����������

  MakePacketMTZ();//������� ����� MTZ
//---------------------------------------------

//---------MTZ3------------------------------
  copyMTZ2ToRepozitar(0);//���������������� � �����������
  rpzcomponent_obj.twinControl[0].twin_different();//diff to MTZ3
  rpzcomponent_obj.packet = MTZ_PACKET;    //����� ��������� ����������

  MakePacketMTZ();//������� ����� MTZ
//---------------------------------------------

//---------MTZ2------------------------------
  copyMTZ2ToRepozitar(0);//���������������� � ����������� MTZ2
  rpzcomponent_obj.packet = MTZ_PACKET;    //����� ��������� ����������
  MakePacketMTZ();//������� ����� MTZ
//---------------------------------------------


//---------MTZ1------------------------------
  copyMTZ1ToRepozitar(0);//���������������� � ����������� MTZ1

  rpzcomponent_obj.packet = -CNT_STUPEN_MTZ;    //�-�� ������ � ������
  //�������� ��� ������
  strcat(rpzcomponent_obj.nameComponent, " ���");
  short ii=0;
  while(rpzcomponent_obj.nameComponent[ii]!=' ')
  {
    ii++;
  }
  rpzcomponent_obj.nameComponent[ii] = 0;

  MakePacketMTZ();//������� ����� MTZ

  //����� �������� ���
  sub_menu_MTZ[1+SUBDATA].Line1         = nameStupenMTZ[0];
  sub_menu_MTZ[1+1+SUBDATA].Line1       = nameStupenMTZ[1];
  sub_menu_MTZ[1+1+1+SUBDATA].Line1     = nameStupenMTZ[2];
  sub_menu_MTZ[1+1+1+1+SUBDATA].Line1   = nameStupenMTZ[3];
  sub_menu_MTZ[1+1+1+1+1+SUBDATA].Line1 = nameStupenMTZ[4];

//---------------------------------------------
  return 1;//�������� �����������
}//copyMTZpacketToRepozitar()

void MakePacketMTZ()
{
//������� �����
//���������� � ����
  memcpy((void*)getShadowBuf(), cnfCOMPONENT, sizeof(COMPONENT_OBJ)*MAX_CNFCOMPONENT);

  memcpy(&(cnfCOMPONENT[0]), &rpzcomponent_obj, sizeof(COMPONENT_OBJ));

//���������� �� ����
  memcpy(&(cnfCOMPONENT[1]), (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(MAX_CNFCOMPONENT-1));


  MakeEmptyTopSub_menu(&(sub_menu_MTZ[0]), sizeof(sub_menu_MTZ));//�������� ������ ������ � top sub_menu
//����� ���� � ������
  sub_menu_MTZ[1+SUBDATA].Line2 = (void *)&OpenMenuComponent; //���� ����������
  sub_menu_MTZ[1+SUBDATA].TypesWin = typeMenuProg;

  TxtStreamInit(&controlStruct_MTZ, &KadrMenuFormat_sub, sub_menu_MTZ);//���� control � ������ �����
//���������������� ������ � ������������
  initCOMPONENT(INITUST_TOPCOMP);

}//MakePacket()


