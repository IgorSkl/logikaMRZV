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

#include "zonaVRT\zonaVRTdef.h"
#include "zonaVRT\zonaVRTfnc.h"


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

void PereinitUstListCompDZ3(short flg);
void UstListCompDZ3();
void ustRedactorCompDZ3();
void UstCompDZ3();

void PereinitVidListCompDZ3(short flg);
void VidListCompDZ3();
void vidRedactorCompDZ3();
void VidCompDZ3();

void PereinitUprListCompDZ3(short flg);
void UprListCompDZ3();
void uprRedactorCompDZ3();
void UprCompDZ3();
short  KadrMenuFormat_upr_compDZ3(void *workCntr);
int  initUstDZ3(char init);
void  prepareUstDZ2(short idxC);
void  prepareUstDZ3(short idxC);
short  KadrMenuFormat_ustvidDZ(void *workCntr);
char *selectorUprStrDZ2(short iBit, UNS_32 ustUpr);

//int ViewerEditUstDZ3();
//int ViewerEditVidDZ3();
void EditUprDZ3();
void EditVidDZ3();
void EditUstDZ3();
int codecUstDZ3(char codec, short offset, int ust);
int codecUstDZ2(char codec, short offset, int ust);
int initUstDZ2(char init);

char DZ3_TITLE[] = "��3";

IONAMESTATUS_COMPONENT ionsDZ3[IOCMD_DZ2to5_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ��3"
  },
  {
    1,//������ iocmd2
    "���� ��� ��3"
  },
  {
    1,//������ iocmd3
    "������ ��� ��3"
  },
  {
    1,//������ iocmd4
    "���� �� ��3��"
  },
  {
    1,//������ iocmd5
    "���� ��3��"
  },
  {
    1,//������ iocmd6
    "���� �� ��� ��3��"
  },
  {
    1,//������ iocmd7
    "���� ��� ��3��"
  },
  {
    1,//������ iocmd8
    "���� �� ��3��"
  },
  {
    1,//������ iocmd9
    "���� ��3��"
  },
  {
    1,//������ iocmd10
    "���� ��� ��3"
  }
};

LineMenuItem sub_menu_comp_DZ3[8] =
{
  { DZ3_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_DZ, typeMenuSub},//control_item, parent
  { "������� ��3",     (void *)&UstListCompDZ3, typeMenuProg},
  { "�������� ��3",    (void *)&VidListCompDZ3, typeMenuProg},
  { "���������� ��3",  (void *)&UprListCompDZ3, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compDZ3[] =
{
  { "������� ��3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ3, typeMenuList},//control_item, parent
  { "��� ��3",        (void *)&UstCompDZ3, typeMenuProg},
  { "��� ��3 ������", (void *)&UstCompDZ3, typeMenuProg},
  { "��� ��3 �����",  (void *)&UstCompDZ3, typeMenuProg},
  { "��� ��3 ��",     (void *)&UstCompDZ3, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compDZ3[] =
{
  { "�������� ��3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ3, typeMenuList},//control_item, parent
/*
  { "�������� ��3��",       (void*)&VidCompDZ3, typeMenuProg},
  { "�������� ��� ��3��",   (void*)&VidCompDZ3, typeMenuProg},
  { "�������� ��3��",       (void*)&VidCompDZ3, typeMenuProg},
  { "���� ����� ��3��",     (void*)&VidCompDZ3, typeMenuProg},
  { "���� ����� ��� ��3��", (void*)&VidCompDZ3, typeMenuProg},

  { "����� ��3�� ��",       (void*)&VidCompDZ3, typeMenuProg},
  { "����� ��3�� ��",       (void*)&VidCompDZ3, typeMenuProg},
  { "����� ��3�� ��",       (void*)&VidCompDZ3, typeMenuProg},

  { "����� ��� ��3�� ��",   (void*)&VidCompDZ3, typeMenuProg},
  { "����� ��� ��3�� ��",   (void*)&VidCompDZ3, typeMenuProg},
  { "����� ��� ��3�� ��",   (void*)&VidCompDZ3, typeMenuProg},

  { "����� ��3�� ��",       (void*)&VidCompDZ3, typeMenuProg},
  { "����� ��3�� ��",       (void*)&VidCompDZ3, typeMenuProg},
  { "����� ��3�� ��",       (void*)&VidCompDZ3, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compDZ3[] =
{
  { "������ ��3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ3, typeMenuList},//control_item, parent
/*  
  { "������ ��3",        (void *)&UprCompDZ3, typeMenuProg},
  { "������ ��� ��3",    (void *)&UprCompDZ3, typeMenuProg},
  { "����� �� ��3",      (void *)&UprCompDZ3, typeMenuProg},
  { "������� ��� ��3",   (void *)&UprCompDZ3, typeMenuProg},
  { "��������� ��3",     (void *)&UprCompDZ3, typeMenuProg},
*/  
  { NULL, NULL}

};

void PereinitUstListCompDZ3(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_ust_compDZ3);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp3()

void UstListCompDZ3()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compDZ3);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompDZ3);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompDZ3()

void UstCompDZ3()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compDZ3);
  PassWord(EditUstDZ3);
}//VidCompDZ3()

void EditUstDZ3()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compDZ3);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompDZ3()

//--------------------------------------------------

void PereinitVidListCompDZ3(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_vid_compDZ3);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitVidListCompDZ3(short flg)

void VidListCompDZ3()
{
  SelectorMNGBAZA(MNGVID_DZ2to5MF);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compDZ3);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompDZ3);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ3()

void VidCompDZ3()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compDZ3);
//  PassWord(EditVidAPV);
  EditVidDZ3();
}//VidCompDZ3()

void EditVidDZ3()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compDZ3);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompDZ3(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compDZ3, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompDZ3()
{
  SelectorMNGBAZA(MNGUPR_DZ2to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compDZ3);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompDZ3);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ3()

void UprCompDZ3()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compDZ3);
  PassWord(EditUprDZ3);

}//UprCompMTZ3()

void EditUprDZ3()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compDZ3[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrDZ2);//������������� ������� ����������
}//EditUprDZ3()

short  KadrMenuFormat_upr_compDZ3(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compDZ3[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrDZ2(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compDZ3(WorkControl *workCntr)

int initUstDZ3(char init)
{
 return initUstDZ2(init);
}//initUstDZ3(short mngUst, char init)

void  prepareUstDZ3(short idxC)
{
  prepareUstDZ2(idxC);
}//prepareUstDZ3(short idxC)

int codecUstDZ3(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  return codecUstDZ2(codec, offset, ust);
}//codecUstDZ3(char *buf, short offset, int ust)

void diffDZ3ToRepozitar()
{
//���������� ��������� ���������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  DZ3_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_DZ3;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_DZ;   //�-�� ������
  rpzcomponent_obj.numClon     = 3;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstDZ3;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstDZ3;//���������� �������

  rpzcomponent_obj.nameStatusIO = ionsDZ3;          //����� � ������ ������ IO

  rpzcomponent_obj.codecUst = codecUstDZ3;   //����������-������������� �������

}//

#endif // _HIDE_COMPONENT

