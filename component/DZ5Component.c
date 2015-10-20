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
#include "psuperVisor\psvisor_helpdef.h"

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\rangmanagerfnc.h"

#include "virtualMenu\viewMenuList.h"

#include "..\bazis.h"

//��� �����������
#define KOD_COMPONENT  DZ_COMP1
//�-�� ��������
#define CNT_STUPEN_DZ  5

#endif // _HIDE_COMPONENT

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "DZ2Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_DZ[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//������� ������� �����������

void PereinitUstListCompDZ5(short flg);
void UstListCompDZ5();
void ustRedactorCompDZ5();
void UstCompDZ5();

void PereinitVidListCompDZ5(short flg);
void VidListCompDZ5();
void vidRedactorCompDZ5();
void VidCompDZ5();

void PereinitUprListCompDZ5(short flg);
void UprListCompDZ5();
void uprRedactorCompDZ5();
void UprCompDZ5();
short  KadrMenuFormat_upr_compDZ5(void *workCntr);
int  initUstDZ5(char init);
void  prepareUstDZ2(short idxC);
void  prepareUstDZ5(short idxC);
short  KadrMenuFormat_ustvidDZ(void *workCntr);
char *selectorUprStrDZ2(short iBit, UNS_32 ustUpr);

//int ViewerEditUstDZ5();
//int ViewerEditVidDZ5();
void EditUprDZ5();
void EditVidDZ5();
void EditUstDZ5();
int codecUstDZ5(char codec, short offset, int ust);
int codecUstDZ2(char codec, short offset, int ust);
int initUstDZ2(char init);

char DZ5_TITLE[] = "��5";

IONAMESTATUS_COMPONENT ionsDZ5[IOCMD_DZ2to5_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ��5"
  },
  {
    1,//������ iocmd2
    "���� ��� ��5"
  },
  {
    1,//������ iocmd3
    "������ ��� ��5"
  },
  {
    1,//������ iocmd4
    "���� �� ��5��"
  },
  {
    1,//������ iocmd5
    "���� ��5��"
  },
  {
    1,//������ iocmd6
    "���� �� ��� ��5��"
  },
  {
    1,//������ iocmd7
    "���� ��� ��5��"
  },
  {
    1,//������ iocmd8
    "���� �� ��5��"
  },
  {
    1,//������ iocmd9
    "���� ��5��"
  },
  {
    1,//������ iocmd10
    "���� ��� ��5"
  }
};

LineMenuItem sub_menu_comp_DZ5[8] =
{
  { DZ5_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_DZ, typeMenuSub},//control_item, parent
  { "������� ��5",     (void *)&UstListCompDZ5, typeMenuProg},
  { "�������� ��5",    (void *)&VidListCompDZ5, typeMenuProg},
  { "���������� ��5",  (void *)&UprListCompDZ5, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compDZ5[] =
{
  { "������� ��5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ5, typeMenuList},//control_item, parent
  { "��� ��5",        (void *)&UstCompDZ5, typeMenuProg},
  { "��� ��5 ������", (void *)&UstCompDZ5, typeMenuProg},
  { "��� ��5 �����",  (void *)&UstCompDZ5, typeMenuProg},
  { "��� ��5 ��",     (void *)&UstCompDZ5, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compDZ5[] =
{
  { "�������� ��5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ5, typeMenuList},//control_item, parent
/*
  { "�������� ��5��",       (void*)&VidCompDZ5, typeMenuProg},
  { "�������� ��� ��5��",   (void*)&VidCompDZ5, typeMenuProg},
  { "�������� ��5��",       (void*)&VidCompDZ5, typeMenuProg},
  { "���� ����� ��5��",     (void*)&VidCompDZ5, typeMenuProg},
  { "���� ����� ��� ��5��", (void*)&VidCompDZ5, typeMenuProg},

  { "����� ��5�� ��",       (void*)&VidCompDZ5, typeMenuProg},
  { "����� ��5�� ��",       (void*)&VidCompDZ5, typeMenuProg},
  { "����� ��5�� ��",       (void*)&VidCompDZ5, typeMenuProg},

  { "����� ��� ��5�� ��",   (void*)&VidCompDZ5, typeMenuProg},
  { "����� ��� ��5�� ��",   (void*)&VidCompDZ5, typeMenuProg},
  { "����� ��� ��5�� ��",   (void*)&VidCompDZ5, typeMenuProg},

  { "����� ��5�� ��",       (void*)&VidCompDZ5, typeMenuProg},
  { "����� ��5�� ��",       (void*)&VidCompDZ5, typeMenuProg},
  { "����� ��5�� ��",       (void*)&VidCompDZ5, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compDZ5[] =
{
  { "������ ��5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ5, typeMenuList},//control_item, parent
  { "������ ��5",        (void *)&UprCompDZ5, typeMenuProg},
  { "������ ��� ��5",    (void *)&UprCompDZ5, typeMenuProg},
  { "����� �� ��5",      (void *)&UprCompDZ5, typeMenuProg},
  { "������� ��� ��5",   (void *)&UprCompDZ5, typeMenuProg},
  { "��������� ��5",     (void *)&UprCompDZ5, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompDZ5(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_ust_compDZ5);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp3()

void UstListCompDZ5()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compDZ5);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompDZ5);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompDZ5()

void UstCompDZ5()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compDZ5);
  PassWord(EditUstDZ5);
}//VidCompDZ5()

void EditUstDZ5()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compDZ5);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompDZ5()

//--------------------------------------------------

void PereinitVidListCompDZ5(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_vid_compDZ5);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitVidListCompDZ5(short flg)

void VidListCompDZ5()
{
  SelectorMNGBAZA(MNGVID_DZ2to5MF);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compDZ5);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompDZ5);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ5()

void VidCompDZ5()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compDZ5);
//  PassWord(EditVidAPV);
  EditVidDZ5();
}//VidCompDZ5()

void EditVidDZ5()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compDZ5);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompDZ5(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compDZ5, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompDZ5()
{
  LIGHTMNGUBAZA = MNGUPR_DZ2to5;

  CRR_SUBMENU = sub_menu_upr_compDZ5;//������� �������

  CRR_TEXTSTREAM = &CONTROL2_COMP;//������� control
  CRR_FHOME = &PereinitUprListCompDZ5;//��������� �� �-��� HOME

  CRR_FHOME(1);//��������
  LanderUpDown();//wkl Up Down
}//VidListCompDZ5()

void UprCompDZ5()
{
  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);
//������������� ������� ����������
  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_upr_compDZ5;// parent
  char *nameUpr = (char *)sub_menu_upr_compDZ5[LIGHTLINEMENU +1+SUBDATA].Line1;

  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrDZ2);//������������� ������� ����������

}//UprCompDZ5()

short  KadrMenuFormat_upr_compDZ5(void *pstr)//(WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compDZ5[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //���������� ������� ���������� � �����
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrDZ2(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat_upr_compDZ5(WorkControl *workCntr)

int initUstDZ5(char init)
{
 return initUstDZ2(init);
}//initUstDZ2to5(short mngUst, char init)

void  prepareUstDZ5(short idxC)
{
  prepareUstDZ2(idxC);
}//prepareUstDZ3(short idxC)

int codecUstDZ5(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  return codecUstDZ2(codec, offset, ust);
}//codecUstDZ5(char *buf, short offset, int ust)

void diffDZ5ToRepozitar()
{
//���������� ��������� ���������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  DZ5_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_DZ5;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_DZ;   //�-�� ������
  rpzcomponent_obj.numClon     = 5;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstDZ5;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstDZ5;//���������� �������

  rpzcomponent_obj.nameStatusIO = ionsDZ5;          //����� � ������ ������ IO

  rpzcomponent_obj.codecUst = codecUstDZ5;   //����������-������������� �������
}//

#endif // _HIDE_COMPONENT

