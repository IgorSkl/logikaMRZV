
#include "virtualMenu\textstreamdef.h"

//�-�� ������� � ����
#define SIZE_PAGE_VIEW 4
//������ ������ � sub_menu
#define SUBDATA 1
//������� ��������� �����
#define PNTCRR_TEXTSTREAM ((StreamControl *)menu_context.controlStruct_crr)
#define CRR_TEXTSTREAM    menu_context.controlStruct_crr
//������� �������
#define CRR_SUBMENU          menu_context.lsubmenu_crr
#define PNTCRR_SUBMENU(idx)  ((LineMenuItem *)menu_context.lsubmenu_crr)[idx]
//�-��� HOME
#define CRR_FHOME            menu_context.pFncGlobal
//�-��� PassUst
#define CRR_FPASSWORD        menu_context.pFPassWord
//�������� ���� ����������
#define CONTROL1_COMP        menu_context.controlStruct_c1
#define CONTROL2_COMP        menu_context.controlStruct_c2
#define CONTROLWL_COMP       menu_context.controlStruct_WL
//�������� ������� ����
#define CONTROL_MAIN         menu_context.controlStruct_main
//�������� ������������
#define CONTROL_CNF          menu_context.controlStruct_cnf
//�������� ������������ ��
#define CONTROL_CNFWL        menu_context.controlStruct_cnfwl
//�������� ���������
#define CONTROL_CNTR         menu_context.controlStruct_cntr
//�������� DV
#define CONTROL_DV           menu_context.controlStruct_viewDV
//�������� RELE
#define CONTROL_RELE         menu_context.controlStruct_viewRele
//�������� CDI
#define CONTROL_CDI          menu_context.controlStruct_viewCDI
//�������� ���� ���
#define CONTROL_WDL          menu_context.controlStruct_widel
//�������� ��� ������� �����
#define CONTROL_STR          menu_context.controlStruct_str
#define PNTCONTROL_STR       ((StreamControl *)&(menu_context.controlStruct_str))

//�������� �������
#define CONTROL_ACT          menu_context.controlStruct_tmp1
//�������� ����������� ���
#define CONTROL_RDIS         menu_context.controlStruct_tmp1
//�������� APV
#define CONTROL_APV          menu_context.controlStruct_tmp1
//�������� UROV
#define CONTROL_UROV         menu_context.controlStruct_tmp1
//�������� P1OF
#define CONTROL_P1OF         menu_context.controlStruct_tmp1
//�������� P2OF
#define CONTROL_P2OF         menu_context.controlStruct_tmp1
//�������� P3OF
#define CONTROL_P3OF         menu_context.controlStruct_tmp1
//�������� ����� �����������
#define CONTROL_DIS          menu_context.controlStruct_tmp1
//�������� ������� ��
#define CONTROL_UDV          menu_context.controlStruct_tmp1
//�������� ������� ����
#define CONTROL_URELE        menu_context.controlStruct_tmp1
//�������� ������� ���
#define CONTROL_UCDI         menu_context.controlStruct_tmp1
//�������� �������� ������
#define CONTROL_VRNG         menu_context.controlStruct_tmp1
//�������� �����������
#define CONTROL_RPZ          menu_context.controlStruct_tmp1

//�������� ������ ��
#define CONTROL_EWL          menu_context.controlStruct_tmp2
//�������� ���
#define CONTROL_UVV          menu_context.controlStruct_tmp2

//�������� ��� ��
#define CONTROL_TLE          menu_context.controlStruct_tmp3
//�������� ������ ����
#define CONTROL_ERNG         menu_context.controlStruct_tmp3

//������� ����
#define LIGHTCLON            menu_context.light1
//��� ���� ��������� �������
#define LIGHTMNGUBAZA        menu_context.light2
//��� �������� ��������� �������
#define LIGHTMNGUOFFSET      menu_context.light3
//������� ����� ����
#define LIGHTLINEMENU        menu_context.light4
//����� ��� ������
#define LIGHTRANGUVV         menu_context.light5
//������� �����
#define LIGHTISPACKET        menu_context.isPacket
//���������
#define LIGHTISDENIE         menu_context.isDenie

typedef struct//������ ��������� menu
{
 void *Line1;
 void *Line2;
 short TypesWin;//������
}LineMenuItem;

enum TypesEnum//������
{
 typeMenuSub = 5,
 typeMenuViewRangDV,
 typeMenuViewRangRele,
 typeMenuViewRangCDI,
 typeMenuViewActual,
 typeMenuViewActualDV,
 typeMenuViewActualRele,
 typeMenuViewRDISMaska,
 typeMenuViewAPVMaska,
 typeMenuViewUROVMaska,
 typeMenuViewP1OFMaska,
 typeMenuViewP2OFMaska,
 typeMenuViewP3OFMaska,
 typeMenuEditRang,
 typeMenuEditWL,

 typeMenuViewLE,

 typeMenuList,
 typeMenuCnf,
 typeMenuCnfWL,
 typeMenuReg,
 typeMenuProg
};

typedef struct
{
  char Win[4][32];//������ ����� ���� 
} WIN_STRUCT;

typedef struct
{
//��� ��������� �����
  WIN_STRUCT stringWin;//������ ����� ����
  WIN_STRUCT stringWinOld;//������ ����� ���� ������
} VIEW_STRUCT;

typedef struct
{
  short light1;//��������� 1
  short light2;//��������� 2
  short light3;//��������� 3
  short light4;//��������� 4
  short light5;//��������� 5
  char  isPacket;//������� �����
  char  isDenie;//���������

  void *controlStruct_crr;//������ ��������� ��� TextStream �������
  void *lsubmenu_crr;//������� submenu
  void  (*pFncGlobal)(short);//�-��� HOME
  void  (*pFPassWord)();//�-��� PassWord
//  void  (*pFPassWord1)(void *);//�-��� PassWord

  StreamControl controlStruct_main;//������� ����
  StreamControl controlStruct_cnf;//������������
  StreamControl controlStruct_cnfwl;//������������ ��
  StreamControl controlStruct_cntr;//���������
  StreamControl controlStruct_viewDV;//������ ��
  StreamControl controlStruct_viewRele;//������ ����
  StreamControl controlStruct_viewCDI;//������ ���
  StreamControl controlStruct_widel;//������ ���� ���
  StreamControl controlStruct_str;//��� ������� �����
  StreamControl controlStruct_c1;//��������� 1
  StreamControl controlStruct_c2;//��������� 2
  StreamControl controlStruct_WL;//��

  StreamControl controlStruct_tmp1;
  StreamControl controlStruct_tmp2;
  StreamControl controlStruct_tmp3;

} MENU_CONTEXT;

extern MENU_CONTEXT menu_context;


