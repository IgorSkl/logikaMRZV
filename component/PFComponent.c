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
#include "logictimers\logictimersfnc.h"

#include "virtualMenu\viewMenuList.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"

//��� �����������
#define KOD_COMPONENT  PF_COMP1
//�-�� ��������
#define CNT_STUPEN_PF  1

#endif // _HIDE_COMPONENT

//������������� �������  � ��������� �������
//�-�� ������� � ��������� �������
#define MNGUST_PF_TOTAL  0

//������������� ENA ������
//�-�� ENA ������
#define ENACMD_PF_TOTAL 0

//������������� ������� � �����������
//�-�� ������� � �����������
#define SPVUST_PF_TOTAL  0

//---------------IO COMMAND------------------
//������������� IO ������ ��� PF
//PF1
#define IOCMD1_PF 0
//PF2
#define IOCMD2_PF 1
//PF3
#define IOCMD3_PF 2
//PF4
#define IOCMD4_PF 3
//PF5
#define IOCMD5_PF 4
//PF6
#define IOCMD6_PF 5
//PF7
#define IOCMD7_PF 6
//PF8
#define IOCMD8_PF 7
//PF9
#define IOCMD9_PF 8
//PF10
#define IOCMD10_PF 9
//PF11
#define IOCMD11_PF 10
//PF12
#define IOCMD12_PF 11
//PF13
#define IOCMD13_PF 12
//PF14
#define IOCMD14_PF 13
//PF15
#define IOCMD15_PF 14
//PF16
#define IOCMD16_PF 15
//�-�� IO ������
#define IOCMD_PF_TOTAL    16

//---------------TL COMMAND------------------
//������������� TL ������ ��� PF
//�-�� TL ������
#define TLCMD_PF_TOTAL    0

//--------------- TIMERS ------------------
//������������� �������� ��� PF
//�-�� ��������
#define TIMERS_PF_TOTAL   0

#ifndef _HIDE_COMPONENT

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];
extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������
extern int  IndexIO;//������ IO
extern int  spvUSTAVKI[];//������� ������� �����������
extern char *bitStringUNI[];
int codecUstPF(char codec, short offset, int ust);
void  logicPF(int idxC);
int   isDISactiv_PF(int idxC);

int  offsetIOCmdPF;//�������� ��� IO PF
int  offsetIOCmdPF_loc;//�������� ��� IO PF

char PF_TITLE[] = "��������";

IONAMESTATUS_COMPONENT ionsPF[IOCMD_PF_TOTAL] =
{
  {
    1,//������ iocmd1
    "�������� 1"
  },
  {
    1,//������ iocmd1
    "�������� 2"
  },
  {
    1,//������ iocmd1
    "�������� 3"
  },
  {
    1,//������ iocmd1
    "�������� 4"
  },
  {
    1,//������ iocmd1
    "�������� 5"
  },
  {
    1,//������ iocmd1
    "�������� 6"
  },
  {
    1,//������ iocmd1
    "�������� 7"
  },
  {
    1,//������ iocmd1
    "�������� 8"
  },
  {
    1,//������ iocmd1
    "�������� 9"
  },
  {
    1,//������ iocmd1
    "�������� 10"
  },
  {
    1,//������ iocmd1
    "�������� 11"
  },
  {
    1,//������ iocmd1
    "�������� 12"
  },
  {
    1,//������ iocmd1
    "�������� 13"
  },
  {
    1,//������ iocmd1
    "�������� 14"
  },
  {
    1,//������ iocmd1
    "�������� 15"
  },
  {
    1,//������ iocmd1
    "�������� 16"
  }
};

LineMenuItem sub_menu_comp_PF[8] =
{
  { PF_TITLE, NULL},//title
  { &CONTROL1_COMP,   &sub_menu_cnf,   typeMenuSub},//control_item, parent
  { NULL, NULL}
};

int initUstPF(char init)
{
  //������� �������

  IndexUstSPV += SPVUST_PF_TOTAL;//������ ������� � �����������
  return MNGUST_PF_TOTAL;//�-�� ������� � ��������� �������
}//initUstPF(short mngUst, char init)

void  prepareUstPF(short idxC)
{
  //���������� ENA ������ ��� �����
}//prepareUstPF(short idxC)

int initIOCmd_PF()
{
  //������� IO ������
  offsetIOCmdPF_loc = IndexIO;//�������� ��� IO PF
  return commonInitIOCmd(IOCMD_PF_TOTAL);
}//initIOCmd_PF()

int initTLCmd_PF()
{
  //������� TL ������
  return 0;
}//initTLCmd_PF()

int initENACmd_PF()
{
  //������� ENA ������
  return 0;
}//initENACmd_PF()

void initTimersPF(short idxC)
{
  //������ � ������� ��������
}//initTimersPF()

int codecUstPF(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  return 1;
}//codecUstPF(char *buf, short offset, int ust)

int isDISactiv_PF(int idxC)
{
 //���������� ������������ ���
  return 0;//��� ����������
}//isDISactiv_PF(int idxC)

char copyPFToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//������� ������

//���������� ��������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.packet = 0;    //����� ��������� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  PF_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_PF;//���� ����������

  rpzcomponent_obj.cntClon      = CNT_STUPEN_PF;   //max �-�� ������
  rpzcomponent_obj.numClon      = 1;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstPF;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstPF;//���������� �������
  rpzcomponent_obj.initIOCmd      = initIOCmd_PF;      //������� IO ������
  rpzcomponent_obj.initTLCmd      = initTLCmd_PF;      //������� TL ������
  rpzcomponent_obj.initENACmd     = initENACmd_PF;     //������� ENA ������
  rpzcomponent_obj.bo_bvCmd       = NULL; //��������� �� �� ������
  rpzcomponent_obj.isDISactiv     = isDISactiv_PF; //���������� ������������ ���
  rpzcomponent_obj.setBOBVtimer   = NULL; //������� �������� �� ��

  rpzcomponent_obj.nameStatusIO = ionsPF;          //����� � ������ ������ IO
  rpzcomponent_obj.initTimers   = initTimersPF;    //������ � ������� ��������
  rpzcomponent_obj.logic        = logicPF;         //������ ����������

  rpzcomponent_obj.codecUst = codecUstPF;   //����������-������������� �������

  return 0;//�� �������� �����������
}//

#endif // _HIDE_COMPONENT

