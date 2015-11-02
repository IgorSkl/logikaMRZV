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

void PereinitUstListCompDZ4(short flg);
void UstListCompDZ4();
void ustRedactorCompDZ4();
void UstCompDZ4();

void PereinitVidListCompDZ4(short flg);
void VidListCompDZ4();
void vidRedactorCompDZ4();
void VidCompDZ4();

void PereinitUprListCompDZ4(short flg);
void UprListCompDZ4();
void uprRedactorCompDZ4();
void UprCompDZ4();
short  KadrMenuFormat_upr_compDZ4(void *workCntr);
int   initUstDZ4(char init);
void  prepareUstDZ2(short idxC);
void  prepareUstDZ4(short idxC);

//int ViewerEditUstDZ4();
//int ViewerEditVidDZ4();
void EditUprDZ4();
void EditVidDZ4();
void EditUstDZ4();
int codecUstDZ4(char codec, short offset, int ust);
int codecUstDZ2(char codec, short offset, int ust);
int initUstDZ2(char init);

short  KadrMenuFormat_ustvidDZ(void *workCntr);
char *selectorUprStrDZ2(short iBit, UNS_32 ustUpr);

char DZ4_TITLE[] = "��4";

IONAMESTATUS_COMPONENT ionsDZ4[IOCMD_DZ2to5_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ��4"
  },
  {
    1,//������ iocmd2
    "���� ��� ��4"
  },
  {
    1,//������ iocmd3
    "������ ��� ��4"
  },
  {
    1,//������ iocmd4
    "���� �� ��4��"
  },
  {
    1,//������ iocmd5
    "���� ��4��"
  },
  {
    1,//������ iocmd6
    "���� �� ��� ��4��"
  },
  {
    1,//������ iocmd7
    "���� ��� ��4��"
  },
  {
    1,//������ iocmd8
    "���� �� ��4��"
  },
  {
    1,//������ iocmd9
    "���� ��4��"
  },
  {
    1,//������ iocmd10
    "���� ��� ��4"
  }
};

LineMenuItem sub_menu_comp_DZ4[8] =
{
  { DZ4_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_DZ, typeMenuSub},//control_item, parent
  { "������� ��4",     (void *)&UstListCompDZ4, typeMenuProg},
  { "�������� ��4",    (void *)&VidListCompDZ4, typeMenuProg},
  { "���������� ��4",  (void *)&UprListCompDZ4, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compDZ4[] =
{
  { "������� ��4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ4, typeMenuList},//control_item, parent
  { "��� ��4",        (void *)&UstCompDZ4, typeMenuProg},
  { "��� ��4 ������", (void *)&UstCompDZ4, typeMenuProg},
  { "��� ��4 �����",  (void *)&UstCompDZ4, typeMenuProg},
  { "��� ��4 ��",     (void *)&UstCompDZ4, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compDZ4[] =
{
  { "�������� ��4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ4, typeMenuList},//control_item, parent
/*
  { "�������� ��4��",       (void*)&VidCompDZ4, typeMenuProg},
  { "�������� ��� ��4��",   (void*)&VidCompDZ4, typeMenuProg},
  { "�������� ��4��",       (void*)&VidCompDZ4, typeMenuProg},
  { "���� ����� ��4��",     (void*)&VidCompDZ4, typeMenuProg},
  { "���� ����� ��� ��4��", (void*)&VidCompDZ4, typeMenuProg},

  { "����� ��4�� ��",       (void*)&VidCompDZ4, typeMenuProg},
  { "����� ��4�� ��",       (void*)&VidCompDZ4, typeMenuProg},
  { "����� ��4�� ��",       (void*)&VidCompDZ4, typeMenuProg},

  { "����� ��� ��4�� ��",   (void*)&VidCompDZ4, typeMenuProg},
  { "����� ��� ��4�� ��",   (void*)&VidCompDZ4, typeMenuProg},
  { "����� ��� ��4�� ��",   (void*)&VidCompDZ4, typeMenuProg},

  { "����� ��4�� ��",       (void*)&VidCompDZ4, typeMenuProg},
  { "����� ��4�� ��",       (void*)&VidCompDZ4, typeMenuProg},
  { "����� ��4�� ��",       (void*)&VidCompDZ4, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compDZ4[] =
{
  { "������ ��4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ4, typeMenuList},//control_item, parent
  { "������ ��4",        (void *)&UprCompDZ4, typeMenuProg},
  { "������ ��� ��4",    (void *)&UprCompDZ4, typeMenuProg},
  { "����� �� ��4",      (void *)&UprCompDZ4, typeMenuProg},
  { "������� ��� ��4",   (void *)&UprCompDZ4, typeMenuProg},
  { "��������� ��4",     (void *)&UprCompDZ4, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompDZ4(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_ust_compDZ4);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp3()

void UstListCompDZ4()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compDZ4);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompDZ4);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompDZ4()

void UstCompDZ4()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compDZ4);
  PassWord(EditUstDZ4);
}//VidCompDZ4()

void EditUstDZ4()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compDZ4);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompDZ4()

//--------------------------------------------------

void PereinitVidListCompDZ4(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_vid_compDZ4);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitVidListCompDZ4(short flg)

void VidListCompDZ4()
{
  SelectorMNGBAZA(MNGVID_DZ2to5MF);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compDZ4);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompDZ4);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ4()

void VidCompDZ4()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compDZ4);
//  PassWord(EditVidAPV);
  EditVidDZ4();
}//VidCompDZ4()

void EditVidDZ4()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compDZ4);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompDZ4(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compDZ4, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompDZ4()
{
  SelectorMNGBAZA(MNGUPR_DZ2to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compDZ4);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompDZ4);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ4()

void UprCompDZ4()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compDZ4);
  PassWord(EditUprDZ4);

}//UprCompMTZ4()

void EditUprDZ4()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compDZ4[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrDZ2);//������������� ������� ����������
}//EditUprDZ4()

short  KadrMenuFormat_upr_compDZ4(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compDZ4[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //UpravlViewerInKadr(nameUpr, i, workCntr);//���������� ������� ���������� � �����
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrDZ2(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compDZ4(WorkControl *workCntr)

int initUstDZ4(char init)
{
 return initUstDZ2(init);
}//initUstDZ4(short mngUst, char init)

void  prepareUstDZ4(short idxC)
{
  prepareUstDZ2(idxC);
}//prepareUstDZ3(short idxC)

int codecUstDZ4(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  return codecUstDZ2(codec, offset, ust);
}//codecUstDZ4(char *buf, short offset, int ust)

void diffDZ4ToRepozitar()
{
//���������� ��������� ���������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  DZ4_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_DZ4;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_DZ;   //�-�� ������
  rpzcomponent_obj.numClon     = 4;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstDZ4;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstDZ4;//���������� �������

  rpzcomponent_obj.nameStatusIO = ionsDZ4;          //����� � ������ ������ IO

  rpzcomponent_obj.codecUst = codecUstDZ4;   //����������-������������� �������
}//

#endif // _HIDE_COMPONENT

