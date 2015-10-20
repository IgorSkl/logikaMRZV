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

#include "..\bazis.h"

//��� �����������
#define KOD_COMPONENT  NZOP_COMP1
//�-�� ��������
#define CNT_STUPEN_NZOP  2

#endif // _HIDE_COMPONENT

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "NZOP1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_NZOP[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//������� ������� �����������

void PereinitUstListCompNZOP2(short flg);
void UstListCompNZOP2();
void ustRedactorCompNZOP2();
void UstCompNZOP2();

void PereinitVidListCompNZOP2(short flg);
void VidListCompNZOP2();
void vidRedactorCompNZOP2();
void VidCompNZOP2();

void PereinitUprListCompNZOP2(short flg);
void UprListCompNZOP2();
void uprRedactorCompNZOP2();
void UprCompNZOP2();
short  KadrMenuFormat_upr_compNZOP2(void *workCntr);//(WorkControl *workCntr);
int  initUstNZOP2(char init);
void  prepareUstNZOP1(short idxC);
void  prepareUstNZOP2(short idxC);

void EditUstNZOP2();
void EditVidNZOP2();
void EditUprNZOP2();
int codecUstNZOP1(char codec, short offset, int ust);
int codecUstNZOP2(char codec, short offset, int ust);
int initUstNZOP1(char init);

short  KadrMenuFormat_ustvidNZOP(void *workCntr);
char *selectorUprStrNZOP1(short iBit, UNS_32 ustUpr);
void diffNZOP2ToRepozitar();

char NZOP2_TITLE[] = "����2";

IONAMESTATUS_COMPONENT ionsNZOP2[IOCMD_NZOP1to2_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ����2"
  },
  {
    1,//������ iocmd2
    "���� �� ����2"
  },
  {
    1,//������ iocmd3
    "���� �� ����2 ���"
  },
  {
    1,//������ iocmd4
    "���� �� ����2 ���"
  },
  {
    1,//������ iocmd5
    "���� ����2"
  },
  {
    1,//������ iocmd6
    "������ ����2 ���"
  },
  {
    1,//������ iocmd7
    "������ ����2 ���"
  }
};

LineMenuItem sub_menu_comp_NZOP2[8] =
{
  { NZOP2_TITLE, NULL},//title
  { &CONTROL1_COMP,  &sub_menu_NZOP, typeMenuSub},//control_item, parent
  { "������� ����2",    (void *)&UstListCompNZOP2, typeMenuProg},
  { "�������� ����2",   (void *)&VidListCompNZOP2, typeMenuProg},
  { "���������� ����2", (void *)&UprListCompNZOP2, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compNZOP2[] =
{
  { "������� ����2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_NZOP2, typeMenuList},//control_item, parent
  { "��� ����2",        (void *)&UstCompNZOP2, typeMenuProg},
  { "��� ����2 ������", (void *)&UstCompNZOP2, typeMenuProg},
  { "��� ����2 �����",  (void *)&UstCompNZOP2, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compNZOP2[] =
{
  { "�������� ����2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_NZOP2, typeMenuList},//control_item, parent
  { "�������� ����2",        (void *)&VidCompNZOP2, typeMenuProg},
  { "�������� ����2 ������", (void *)&VidCompNZOP2, typeMenuProg},
  { "�������� ����2 �����",  (void *)&VidCompNZOP2, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compNZOP2[] =
{
  { "������ ����2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_NZOP2, typeMenuList},//control_item, parent
  { "��� ����2",           (void *)&UprCompNZOP2, typeMenuProg},
  { "������ ����2",        (void *)&UprCompNZOP2, typeMenuProg},
  { "������� ����2",       (void *)&UprCompNZOP2, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompNZOP2(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidNZOP, sub_menu_ust_compNZOP2);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp3()

void UstListCompNZOP2()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compNZOP2);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompNZOP2);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompNZOP2()

void UstCompNZOP2()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compNZOP2);
  PassWord(EditUstNZOP2);
}//VidCompNZOP2()

void EditUstNZOP2()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compNZOP2);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompNZOP2()

//--------------------------------------------------

void PereinitVidListCompNZOP2(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidNZOP, sub_menu_vid_compNZOP2);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitVidListCompNZOP2(short flg)

void VidListCompNZOP2()
{
  SelectorMNGBAZA(MNGVID_NZOP1to2);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compNZOP2);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompNZOP2);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP2()

void VidCompNZOP2()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compNZOP2);
//  PassWord(EditVidAPV);
  EditVidNZOP2();
}//VidCompNZOP2()

void EditVidNZOP2()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compNZOP2);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompNZOP2(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compNZOP2, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompNZOP2()
{
  SelectorMNGBAZA(MNGUPR_NZOP1to2);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compNZOP2);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompNZOP2);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP2()

void UprCompNZOP2()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compNZOP2);
  PassWord(EditUprNZOP2);

}//UprCompNZOP2()

void EditUprNZOP2()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compNZOP2[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrNZOP1);//������������� ������� ����������
}//EditUprNZOP2()

short  KadrMenuFormat_upr_compNZOP2(void *pstr)//(WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compNZOP2[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //    UpravlViewerInKadr(nameUpr, i, workCntr);//���������� ������� ���������� � �����
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrNZOP1(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compNZOP2(WorkControl *workCntr)

int initUstNZOP2(char init)
{
 return initUstNZOP1(init);
}//initUstMTZ1(short mngUst, char init)

void  prepareUstNZOP2(short idxC)
{
  prepareUstNZOP1(idxC);
}//prepareUstMTZ3(short idxC)

int codecUstNZOP2(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  return codecUstNZOP1(codec, offset, ust);
}//codecUstNZOP1(char *buf, short offset, int ust)

void diffNZOP2ToRepozitar()
{
//���������� ��������� ���������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  NZOP2_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_NZOP2;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_NZOP;   //max �-�� ������
  rpzcomponent_obj.numClon     = 2;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstNZOP2;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstNZOP2;//���������� �������

  rpzcomponent_obj.nameStatusIO = ionsNZOP2;          //����� � ������ ������ IO

  rpzcomponent_obj.codecUst = codecUstNZOP2;   //����������-������������� �������

}//

#endif // _HIDE_COMPONENT

