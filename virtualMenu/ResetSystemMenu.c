/*
#include <vcl.h>
#include <strstrea.h>
#include <math.h>
#include <mem.h>
#include <fstream.h>
#include <strstrea.h>
#include <iomanip.h>
#pragma hdrstop
*/

#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"
#include "virtualMenu\systemmenudef.h"
#include "virtualMenu\ustmanagerdef.h"

#include "ustrangEEPROMdef.h"

#include "logictimers\logictimersfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "virtualMenu\viewMenuWideLog.h"
#include "virtualMenu\viewMenuCnf.h"
#include "virtualMenu\viewMenuSub.h"

#include "psupervisor\psupervisor.h"

#include "virtualMenu\repozitfnc.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"

#define _HIDE_COMPONENT

#include "APVComponent.c"
#include "UMMComponent.c"
#include "DZ1Component.c"
#include "DZ2Component.c"

#include "MTZ1Component.c"
#include "MTZ2Component.c"

#include "NZOP1Component.c"

#include "OFComponent.c"

#include "PRM1Component.c"

#include "TZNP1Component.c"

#include "UROVComponent.c"

void PrepareResetBV();

extern LineMenuItem sub_menu_main[];
extern LineMenuItem sub_menu_cntr[];
extern char addComp[];
extern LineMenuItem sub_menu_dv[];
extern LineMenuItem sub_menu_rele[];
extern LineMenuItem sub_menu_cdi[];
extern LineMenuItem sub_menu_le[];
extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_widel[];
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//������� ������� �����������

extern LineMenuItem sub_menu_comp_WL[];

extern int  offsetIOCmdOF;//�������� ��� IO OF
extern int  offsetIOCmdPF;//�������� ��� IO PF
extern int  offsetIOCmdOF_loc;//�������� ��� IO OF
extern int  offsetIOCmdPF_loc;//�������� ��� IO PF
extern int  offsetUstMngPRM1;//�������� �� ������� PRM1

char *bitStringUNI[20];

LineMenuItem sub_menu_cnfwl[MAX_WLCOMPONENT+3] =
{
  { "������������ ��", NULL},//title
  { &CONTROL_CNFWL, sub_menu_comp_WL},//control_item, parent
  { addComp, (void *)&RpzComponentWL, typeMenuProg},
  { NULL, NULL}
};

//���� ������������
LineMenuItem sub_menu_cnf[MAX_CNFCOMPONENT+3] =
{
  { "������������", NULL},//title
  { &CONTROL_CNF, sub_menu_main},//control_item, parent
  { addComp, (void *)&RpzComponent, typeMenuProg},
  { NULL, NULL}
};

//���������� �����������
LineMenuItem sub_menu_reg[] =
{
  { "���������� �����������", NULL},//title
  { &CONTROL_DIS, sub_menu_main}//control_item, parent
};

//�������
LineMenuItem sub_menu_act[] =
{
  { "�������", NULL},//title
  { &CONTROL_ACT, sub_menu_main}//control_item, parent
};

//��������������
LineMenuItem sub_menu_rdis[] =
{
  { "��������������", NULL},//title
  { &CONTROL_RDIS, sub_menu_main}//control_item, parent
};

//APV
LineMenuItem sub_menu_apv[] =
{
  { "���� ���", NULL},//title
  { &CONTROL_APV, sub_menu_main}//control_item, parent
};

LineMenuItem sub_menu_urov[] =
{
  { "���� ����", NULL},//title
  { &CONTROL_UROV, sub_menu_main}//control_item, parent
};

LineMenuItem sub_menu_p1of[] =
{
  { "���� 1 ��", NULL},//title
  { &CONTROL_P1OF, sub_menu_main}//control_item, parent
};

LineMenuItem sub_menu_p2of[] =
{
  { "���� 2 ��", NULL},//title
  { &CONTROL_P2OF, sub_menu_main}//control_item, parent
};

LineMenuItem sub_menu_p3of[] =
{
  { "���� 3 ��", NULL},//title
  { &CONTROL_P1OF, sub_menu_main}//control_item, parent
};

char titleRang[10] = "";
//��
LineMenuItem sub_menu_viewDV[] =
{
  { titleRang, NULL},//title
  { &CONTROL_VRNG, sub_menu_dv}//control_item, parent
};

//Rele
LineMenuItem sub_menu_viewRele[] =
{
  { titleRang, NULL},//title
  { &CONTROL_VRNG, sub_menu_rele}//control_item, parent
};

LineMenuItem sub_menu_viewCDI[] =
{
  { titleRang, NULL},//title
  { &CONTROL_VRNG, sub_menu_cdi}//control_item, parent
};

LineMenuItem sub_menu_tmp[] =
{
  { "���������", NULL},//title
  { NULL, NULL},//control_item, parent
};

LineMenuItem sub_menu_dv[] =
{
  { "����� �����", NULL},//title
  { &CONTROL_DV, sub_menu_cntr},//control_item, parent
/*
  { "��1", sub_menu_viewDV, typeMenuViewRangDV},
  { "��2", sub_menu_viewDV, typeMenuViewRangDV},
  { "��3", sub_menu_viewDV, typeMenuViewRangDV},
  { "��4", sub_menu_viewDV, typeMenuViewRangDV},
  { "��5", sub_menu_viewDV, typeMenuViewRangDV},
  { "��6", sub_menu_viewDV, typeMenuViewRangDV},
  { "��7", sub_menu_viewDV, typeMenuViewRangDV},
  { "��8", sub_menu_viewDV, typeMenuViewRangDV},
  { "��9", sub_menu_viewDV, typeMenuViewRangDV},
  { "��10", sub_menu_viewDV, typeMenuViewRangDV},
  { "��11", sub_menu_viewDV, typeMenuViewRangDV},
  { "��12", sub_menu_viewDV, typeMenuViewRangDV},
  { "��13", sub_menu_viewDV, typeMenuViewRangDV},
  { "��14", sub_menu_viewDV, typeMenuViewRangDV},
  { "��15", sub_menu_viewDV, typeMenuViewRangDV},
  { "��16", sub_menu_viewDV, typeMenuViewRangDV},
  { "��17", sub_menu_viewDV, typeMenuViewRangDV},
  { "��18", sub_menu_viewDV, typeMenuViewRangDV},
  { "��19", sub_menu_viewDV, typeMenuViewRangDV},
  { "��20", sub_menu_viewDV, typeMenuViewRangDV},
  { "��21", sub_menu_viewDV, typeMenuViewRangDV},
  { "��22", sub_menu_viewDV, typeMenuViewRangDV},
  { "��23", sub_menu_viewDV, typeMenuViewRangDV},
  { "��24", sub_menu_viewDV, typeMenuViewRangDV},
  { "��25", sub_menu_viewDV, typeMenuViewRangDV},
  { "��26", sub_menu_viewDV, typeMenuViewRangDV},
  { "��27", sub_menu_viewDV, typeMenuViewRangDV},
  { "��28", sub_menu_viewDV, typeMenuViewRangDV},
  { "��29", sub_menu_viewDV, typeMenuViewRangDV},
  { "��30", sub_menu_viewDV, typeMenuViewRangDV},
  { "��31", sub_menu_viewDV, typeMenuViewRangDV},
  { "��32", sub_menu_viewDV, typeMenuViewRangDV},
  { "��33", sub_menu_viewDV, typeMenuViewRangDV},
  { "��34", sub_menu_viewDV, typeMenuViewRangDV},
  { "��35", sub_menu_viewDV, typeMenuViewRangDV},
  { "��36", sub_menu_viewDV, typeMenuViewRangDV},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_rele[] =
{
  { "������ ����", NULL},//title
  { &CONTROL_RELE, sub_menu_cntr},//control_item, parent
/*
  { "�01", sub_menu_viewRele, typeMenuViewRangRele},
  { "�02", sub_menu_viewRele, typeMenuViewRangRele},
  { "�03", sub_menu_viewRele, typeMenuViewRangRele},
  { "�04", sub_menu_viewRele, typeMenuViewRangRele},
  { "�05", sub_menu_viewRele, typeMenuViewRangRele},
  { "�06", sub_menu_viewRele, typeMenuViewRangRele},
  { "�07", sub_menu_viewRele, typeMenuViewRangRele},
  { "�08", sub_menu_viewRele, typeMenuViewRangRele},
  { "�09", sub_menu_viewRele, typeMenuViewRangRele},
  { "�10", sub_menu_viewRele, typeMenuViewRangRele},
  { "�11", sub_menu_viewRele, typeMenuViewRangRele},
  { "�12", sub_menu_viewRele, typeMenuViewRangRele},
  { "�13", sub_menu_viewRele, typeMenuViewRangRele},
  { "�14", sub_menu_viewRele, typeMenuViewRangRele},
  { "�15", sub_menu_viewRele, typeMenuViewRangRele},
  { "�16", sub_menu_viewRele, typeMenuViewRangRele},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_cdi[] =
{
  { "���������������", NULL},//title
  { &CONTROL_CDI, sub_menu_cntr},//control_item, parent
/*
  { "���01", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���02", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���03", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���04", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���05", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���06", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���07", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���08", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���09", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���10", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���11", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���12", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���13", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "���14", sub_menu_viewCDI, typeMenuViewRangCDI},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_cntr[] =
{
  { "���������", NULL},//title
  { &CONTROL_CNTR, sub_menu_main},//control_item, parent
  { "����� �����",     sub_menu_dv,    typeMenuSub},
  { "������ ����",     sub_menu_rele,  typeMenuSub},
  { "���������������", sub_menu_cdi,   typeMenuSub},
  { NULL, NULL}

};

//������� ����
LineMenuItem sub_menu_main[] =
{
  { "������� ����", NULL},//title
  { &CONTROL_MAIN, NULL},//control_item, parent
  { "���������",         sub_menu_cntr, typeMenuSub},
  { "������������",      sub_menu_cnf,  typeMenuCnf},//������������
  { "��������������",    sub_menu_rdis, typeMenuViewRDISMaska},//��������������
  { "���� ���",          sub_menu_apv,   typeMenuViewAPVMaska},//���� ���
  { "���� ����",         sub_menu_urov,  typeMenuViewUROVMaska},//���� ����
  { "P1 ��",             sub_menu_p1of,  typeMenuViewP1OFMaska},//����� 1 ��
  { "P2 ��",             sub_menu_p2of,  typeMenuViewP2OFMaska},//����� 2 ��
  { "P3 ��",             sub_menu_p3of,  typeMenuViewP3OFMaska},//����� 3 ��
  { "����� �����������", sub_menu_reg,  typeMenuReg},//����� ���
  { "�������",           sub_menu_act,  typeMenuViewActual},
  { NULL, NULL}

};

//�������� ������
LineMenuItem sub_menu_editrng[] =
{
  { "�������� ����", NULL},//title
  { NULL, NULL, typeMenuEditRang}//control_item, parent
};

//�������� ������ ������
LineMenuItem sub_menu_editwl[] =
{
  { "�������� ��", NULL},//title
  { NULL, NULL, typeMenuEditWL}//control_item, parent
};

void ResetSystemMenu()
{
  bitStringUNI[UNIUPR_WKL]    = "���";
  bitStringUNI[UNIUPR_OTKL]   = "����";
  bitStringUNI[UNIUPR_WPERED] = "������";
  bitStringUNI[UNIUPR_NAZAD]  = "�����";
  bitStringUNI[UNIUPR_PROSTAJA] = "�������";
  bitStringUNI[UNIUPR_NAPRAVL]  = "�������";
  bitStringUNI[UNIUPR_INVERS]   = "���������";
  bitStringUNI[UNIUPR_PRM]      = "������";
  bitStringUNI[UNIUPR_NORM]     = "����������";
  bitStringUNI[UNIUPR_TRIG]     = "�����";
  bitStringUNI[UNIUPR_OBRAT]    = "��������";
  bitStringUNI[UNIUPR_PRJAM]    = "������";
  bitStringUNI[UNIUPR_ILI]      = "���";
  bitStringUNI[UNIUPR_I]        = "�";
  bitStringUNI[UNIUPR_LIN]      = "��������";
  bitStringUNI[UNIUPR_FAZ]      = "������";

//����� ���������� ����
  ResetConfig();//�������� ������������

  TxtStreamInit(&CONTROL_MAIN, &KadrMenuFormat_sub, sub_menu_main);//���� control � ������ �����

  CRR_SUBMENU = sub_menu_main;//������� submenu
  //������
  sub_menu_main[SUBDATA].TypesWin = typeMenuSub;

  CRR_TEXTSTREAM = &CONTROL_MAIN;//������� control

  TxtStreamInit(&CONTROL_CNTR,      &KadrMenuFormat_sub, sub_menu_cntr);//���� control � ������ �����
  TxtStreamInit(&CONTROL_DV,        &KadrMenuFormat_sub, sub_menu_dv);//���� control � ������ �����
  TxtStreamInit(&CONTROL_RELE,      &KadrMenuFormat_sub, sub_menu_rele);//���� control � ������ �����
  TxtStreamInit(&CONTROL_CDI,       &KadrMenuFormat_sub, sub_menu_cdi);//���� control � ������ �����
  TxtStreamInit(&CONTROL_WDL,       &KadrMenuFormat_sub, sub_menu_widel);//���� control � ������ �����

  ViewDiskrMenu(typeMenuSub);//������� ���� �����������

//  CRR_FHOME = &PereinitSub;//��������� �� �-��� HOME
  SelectorFHOME(&PereinitSub);//��������� �� �-��� HOME

  LanderPStr();//���������� ��������� ������
  ResetUpDown();//�������� Up Down
  ShowTitleSubmenu_crr();//��������� �������� Submenu

  AddCompIzRpz(PRM1_COMP1);//�������� ��������� �� �����������


 SetCmdToUVV(PRM1_COMP1,  1, IOCMD6_PRM1, RELE2_SM);//������ TEST PRM1 �� P2


  AddCompIzRpz(PF_COMP1);//�������� ��������� �� �����������
  AddCompIzRpz(OF_COMP1);//�������� ��������� �� �����������
  
  AddCompIzRpz(UMM_COMP1);//�������� ��������� �� �����������
  AddCompIzRpz(UROV_COMP1);//�������� ��������� �� �����������
  AddCompIzRpz(APV_COMP1);//�������� ��������� �� �����������

  AddCompIzRpz(NZOP_COMP1);//�������� ��������� �� �����������
  AddCompIzRpz(TZNP_COMP1);//�������� ��������� �� �����������
  AddCompIzRpz(DZ_COMP1);//�������� ��������� �� �����������
  AddCompIzRpz(MTZ_COMP1);//�������� ��������� �� �����������

  AddCompIzRpz(WL_COMP1);//�������� ��������� �� �����������

  offsetIOCmdOF = offsetIOCmdOF_loc;//c������� ��� IO
  offsetIOCmdPF = offsetIOCmdPF_loc;//�������� ��� IO

  AddCompIzRpz_WL(OF_COMP1);//�������� ��������� �� ����������� � ��
  AddCompIzRpz_WL(PF_COMP1);//�������� ��������� �� ����������� � ��
  
  PrepareResetBV();//����������� ������� ������ ����� ���������


  SetCmdToUVV(PRM1_COMP1,  1, IOCMD1_PRM1, DV1_SM);//������ CMD_POL_VV �� ��1

//--------MTZ1-------------------
  SetCmdToUVV(MTZ_COMP1,  1, IOCMD6_MTZ1, RELE6_SM);//������ MTZ1 �� P6
  SetCmdToUVV(MTZ_COMP1,  1, IOCMD6_MTZ1, RELE1_SM);//������ MTZ1 �� P6
//----------------------------------------------------------
//--------MTZ2-------------------
  SetCmdToUVV(MTZ_COMP1,  2, IOCMD8_MTZ2to5, RELE6_SM);//������ MTZ2 �� P6
//----------------------------------------------------------
//--------MTZ3-------------------
  SetCmdToUVV(MTZ_COMP1,  3, IOCMD8_MTZ2to5, RELE6_SM);//������ MTZ3 �� P6
//----------------------------------------------------------
//--------MTZ4-------------------
  SetCmdToUVV(MTZ_COMP1,  4, IOCMD8_MTZ2to5, RELE6_SM);//������ MTZ4 �� P6
//----------------------------------------------------------
//--------MTZ5-------------------
  SetCmdToUVV(MTZ_COMP1,  5, IOCMD8_MTZ2to5, RELE6_SM);//������ MTZ5 �� P6
//----------------------------------------------------------

  SetCmdToUVV(MTZ_COMP1,  2, IOCMD3_MTZ2to5, DV3_SM);//������ ������ ����� MTZ2 �� ��3
  SetCmdToUVV(MTZ_COMP1,  3, IOCMD3_MTZ2to5, DV3_SM);//������ ������ ����� MTZ3 �� ��3
  SetCmdToUVV(MTZ_COMP1,  4, IOCMD3_MTZ2to5, DV3_SM);//������ ������ ����� MTZ4 �� ��3
  SetCmdToUVV(MTZ_COMP1,  5, IOCMD3_MTZ2to5, DV3_SM);//������ ������ ����� MTZ5 �� ��3

//--------UMM-------------------
        //UMAX1
  SetCmdToUVV(UMM_COMP1,  1, IOCMD6_UMM, RELE6_SM);//������ HA P6
        //UMAX2
  SetCmdToUVV(UMM_COMP1,  1, IOCMD8_UMM, RELE6_SM);//������ HA P6
        // UMIN1
  SetCmdToUVV(UMM_COMP1,  1, IOCMD10_UMM, RELE6_SM);//������ HA P6
        // UMIN2
  SetCmdToUVV(UMM_COMP1,  1, IOCMD12_UMM, RELE6_SM);//������ HA P6

    //PUSK_UMM1
  SetCmdToUVV(UMM_COMP1,  1, IOCMDPUSK1_UMM, DV1_SM);//������ ���� UMIN1 �� ��1
    //PUSK_UMM2
  SetCmdToUVV(UMM_COMP1,  1, IOCMDPUSK2_UMM, DV1_SM);//������ ���� UMIN2 �� ��1
    //BLOK_UMIN1
  SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, DV2_SM);//������ ���� UMIN1 �� ��2
    //BLOK_UMIN2
  SetCmdToUVV(UMM_COMP1,  1, IOCMD4_UMM, DV2_SM);//������ ���� UMIN2 �� ��2

//--------DZ-------------------
        //DZ1               //���� ��1��
  SetCmdToUVV(DZ_COMP1,  1, IOCMD7_DZ1, RELE6_SM);//������ HA P6
//  SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5MF, RELE1_SM);//������ 

//--------TZNP-------------------
//���� ����1
//CMD_TZNP1to5
  SetCmdToUVV(TZNP_COMP1,  1, IOCMD5_TZNP1to5, RELE6_SM);//������ HA P6
//���� ����1 3I0
//CMD_TZNP1to5_3I0
  SetCmdToUVV(TZNP_COMP1,  1, IOCMD7_TZNP1to5, RELE6_SM);//������ HA P6
//���� ����1 3U0
//CMD_TZNP1to5_3U0
  SetCmdToUVV(TZNP_COMP1,  1, IOCMD9_TZNP1to5, RELE6_SM);//������ HA P6

//���� ����1
//CMD_TZNP1to5
  SetCmdToUVV(TZNP_COMP1,  2, IOCMD5_TZNP1to5, RELE6_SM);//������ HA P6
//���� ����1 3I0
//CMD_TZNP1to5_3I0
  SetCmdToUVV(TZNP_COMP1,  2, IOCMD7_TZNP1to5, RELE6_SM);//������ HA P6
//���� ����1 3U0
//CMD_TZNP1to5_3U0
  SetCmdToUVV(TZNP_COMP1,  2, IOCMD9_TZNP1to5, RELE6_SM);//������ HA P6

//���� ����1
//CMD_TZNP1to5
  SetCmdToUVV(TZNP_COMP1,  3, IOCMD5_TZNP1to5, RELE6_SM);//������ HA P6
//���� ����1 3I0
//CMD_TZNP1to5_3I0
  SetCmdToUVV(TZNP_COMP1,  3, IOCMD7_TZNP1to5, RELE6_SM);//������ HA P6
//���� ����1 3U0
//CMD_TZNP1to5_3U0
  SetCmdToUVV(TZNP_COMP1,  3, IOCMD9_TZNP1to5, RELE6_SM);//������ HA P6

//���� ����1
//CMD_TZNP1to5
  SetCmdToUVV(TZNP_COMP1,  4, IOCMD5_TZNP1to5, RELE6_SM);//������ HA P6
//���� ����1 3I0
//CMD_TZNP1to5_3I0
  SetCmdToUVV(TZNP_COMP1,  4, IOCMD7_TZNP1to5, RELE6_SM);//������ HA P6
//���� ����1 3U0
//CMD_TZNP1to5_3U0
  SetCmdToUVV(TZNP_COMP1,  4, IOCMD9_TZNP1to5, RELE6_SM);//������ HA P6

//���� ����1
//CMD_TZNP1to5
  SetCmdToUVV(TZNP_COMP1,  5, IOCMD5_TZNP1to5, RELE6_SM);//������ HA P6
//���� ����1 3I0
//CMD_TZNP1to5_3I0
  SetCmdToUVV(TZNP_COMP1,  5, IOCMD7_TZNP1to5, RELE6_SM);//������ HA P6
//���� ����1 3U0
//CMD_TZNP1to5_3U0
  SetCmdToUVV(TZNP_COMP1,  5, IOCMD9_TZNP1to5, RELE6_SM);//������ HA P6

  //BLOK_TZNP1
  SetCmdToUVV(TZNP_COMP1,  1, IOCMD1_TZNP1to5, DV2_SM);//������ ���� TZNP1 �� ��2
  SetCmdToUVV(TZNP_COMP1,  1, IOCMD3_TZNP1to5, DV3_SM);//������ ������ ����� TZNP1 �� ��3
  SetCmdToUVV(TZNP_COMP1,  1, IOCMD2_TZNP1to5, DV4_SM);//������ ���� ��� ����1 �� ��4

  //BLOK_TZNP2
  SetCmdToUVV(TZNP_COMP1,  2, IOCMD1_TZNP1to5, DV2_SM);//������ ���� TZNP2 �� ��2
  SetCmdToUVV(TZNP_COMP1,  2, IOCMD3_TZNP1to5, DV3_SM);//������ ������ ����� TZNP2 �� ��3
  SetCmdToUVV(TZNP_COMP1,  2, IOCMD2_TZNP1to5, DV4_SM);//������ ���� ��� ����2 �� ��4

//--------APV-------------------
      SetCmdToUVV(APV_COMP1,  1, IOCMD2_APV, DV3_SM);//������ 
//      SetCmdToUVV(APV_COMP1,  1, IOCMD2_APV, RELE1_SM);//������ 

//APV1
      SetCmdToUVV(APV_COMP1,  1, IOCMD4_APV, RELE2_SM);//������ 

//--------REG_DIS-------------------
      SetCmdToUVV(APV_COMP1,  1, IOCMD2_APV, REGDIS_SM);//���� ��� �� ��
extern int alterEEPROM;//x101;//0;//����� alter ext ���a��� � ������ EEPROM

    savePARAMtoEEPROM(alterEEPROM^USTALTER_MASKA);

}//ResetSystemMenu()

int SetUstToClon(short kodC, short numClon, short numUst, int newUst)
{
//����� ������� numUst ����� newUst ���������� kodC � ������� ����� numClon
  short idxClon = SearchCnfClonToComponent(kodC, numClon);
  if(idxClon<0) return 1;//���� �� ������
 
//�������� �������� bazaOffset ������� ust � ���� idxC
  int tmp = setClonMngUSTAVKI(idxClon, numUst, newUst);
//    int  ttttttt1 = PrepareENACmd(8, 31);//MNGUPR_DZ2to5);
  if(tmp==ERROR_UST) return ERROR_UST;//������
  //�������� �� ���������� �������� �� ��
//  if((kodC==PRM1_COMP1)&&((numUst==MNGUST_PRM1_BO)||(numUst==MNGUST_PRM1_BV)))
  //      PrepareBOBVtimer();//����������� ������� ���� ����, ���� ���
  PREPAREustCOMPONENT(idxClon);//����������  ���������� ������� spv ����������� �� ������
  SaveAsBlokUstavki(0);//��������� ��� ��� ��� ���� �������
  return tmp;//�������
}//SetUstToClon(short kodC, short numClon, short numUst, int newUst)

void PrepareBOBV()
{
//����������� ���� ����, ���� ���
extern UNS_32 maskaReleBO, maskaReleBV;
extern int offsetIOCmdPRM1;//�������� ��� IO PRM1

      maskaReleBO = 0;
      maskaReleBV = 0;
    int i=RELE1_SM;
    for(; i<(RELE1_SM+RELE_TOTAL); i++)
    {
                                   //������ ��
      if(GetCmdUVVFromClon(PRM1_COMP1, 1, IOCMD4_PRM1, i)) break;
    }//for
  if(!(i==(RELE1_SM+RELE_TOTAL))){//break �� ����
     maskaReleBO = 1<<(i-RELE1_SM);
  }//if

    i=RELE1_SM;
    for(; i<(RELE1_SM+RELE_TOTAL); i++)
    {
                                   //������ �B
      if(GetCmdUVVFromClon(PRM1_COMP1, 1, IOCMD5_PRM1, i)) break;
    }//for
  if(!(i==(RELE1_SM+RELE_TOTAL))){//break �� ����
     maskaReleBV = 1<<(i-RELE1_SM);
  }//if
}//PrepareBOBV()

void PrepareResetBV()
{
//����������� ������� ������ ����� ���������
//extern UNS_32 pResetBVcmdMaska[];//����������� ����� ����� ���������
//----------------------------MTZ------------------------------
    SetCmdToUVV(MTZ_COMP1,  1, IOCMD6_MTZ1,    RESETBV_SM);//������ MTZ1 �� APV
    SetCmdToUVV(MTZ_COMP1,  2, IOCMD8_MTZ2to5, RESETBV_SM);//������ MTZ2 �� APV
    SetCmdToUVV(MTZ_COMP1,  3, IOCMD8_MTZ2to5, RESETBV_SM);//������ MTZ3 �� APV
    SetCmdToUVV(MTZ_COMP1,  4, IOCMD8_MTZ2to5, RESETBV_SM);//������ MTZ4 �� APV
    SetCmdToUVV(MTZ_COMP1,  5, IOCMD8_MTZ2to5, RESETBV_SM);//������ MTZ5 �� APV

//----------------------------TZNP------------------------------
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD5_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD9_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD7_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD5_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD9_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD7_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD5_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD9_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD7_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD5_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD9_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD7_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD5_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD9_TZNP1to5, RESETBV_SM);//������ �� APV
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD7_TZNP1to5, RESETBV_SM);//������ �� APV

//----------------------------DZ------------------------------
             SetCmdToUVV(DZ_COMP1,  1, IOCMD3_DZ1, RESETBV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  1, IOCMD7_DZ1, RESETBV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5MF, RESETBV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5OF, RESETBV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5MF, RESETBV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5OF, RESETBV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5MF, RESETBV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5OF, RESETBV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5MF, RESETBV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5OF, RESETBV_SM);//������ �� APV
  SetCmdToUVV(DZ_COMP1,  1, IOCMD5_DZ1, RESETBV_SM);//������ �� APV
  SetCmdToUVV(DZ_COMP1,  2, IOCMD5_MDZ2to5MF, RESETBV_SM);//������ �� APV
  SetCmdToUVV(DZ_COMP1,  3, IOCMD5_MDZ2to5MF, RESETBV_SM);//������ �� APV
  SetCmdToUVV(DZ_COMP1,  4, IOCMD5_MDZ2to5MF, RESETBV_SM);//������ �� APV
  SetCmdToUVV(DZ_COMP1,  5, IOCMD5_MDZ2to5MF, RESETBV_SM);//������ �� APV
  
//--------------------ZN-------------------------------------
      SetCmdToUVV(UMM_COMP1,  1, IOCMD10_UMM, RESETBV_SM);//������ 
      SetCmdToUVV(UMM_COMP1,  1, IOCMD12_UMM, RESETBV_SM);//������ 
      SetCmdToUVV(UMM_COMP1,  1, IOCMD6_UMM, RESETBV_SM);//������ 
      SetCmdToUVV(UMM_COMP1,  1, IOCMD8_UMM, RESETBV_SM);//������ 
//--------------------NZOP----------------------------
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD5_NZOP1to2, RESETBV_SM);//������ 
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD5_NZOP1to2, RESETBV_SM);//������ 

//UNS_32 pResetBVcmdMaska[DQUADRO];//����������� ����� ����� ���������
}//PrepareResetBV()

