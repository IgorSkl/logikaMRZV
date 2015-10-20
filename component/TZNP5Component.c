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
#define KOD_COMPONENT  TZNP_COMP1
//�-�� ��������
#define CNT_STUPEN_TZNP  5

#endif // _HIDE_COMPONENT

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "TZNP1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_TZNP[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//������� ������� �����������

void PereinitUstListCompTZNP5(short flg);
void UstListCompTZNP5();
void ustRedactorCompTZNP5();
void UstCompTZNP5();

void PereinitVidListCompTZNP5(short flg);
void VidListCompTZNP5();
void vidRedactorCompTZNP5();
void VidCompTZNP5();

void PereinitUprListCompTZNP5(short flg);
void UprListCompTZNP5();
void uprRedactorCompTZNP5();
void UprCompTZNP5();
short  KadrMenuFormat_upr_compTZNP5(void *workCntr);//(WorkControl *workCntr);
int   initUstTZNP5(char init);
void  prepareUstTZNP5(short idxC);
void  prepareUstTZNP1(short idxC);

//int ViewerEditUstTZNP5();
//int ViewerEditVidTZNP5();
void EditUstTZNP5();
void EditVidTZNP5();
void EditUprTZNP5();
int codecUstTZNP5(char codec, short offset, int ust);
int codecUstTZNP1(char codec, short offset, int ust);
int initUstTZNP1(char init);

char *selectorUprStrTZNP2(short iBit, UNS_32 ustUpr);
short  KadrMenuFormat_ustvidTZNP(void *workCntr);
void diffTZNP5ToRepozitar();

char TZNP5_TITLE[] = "����5";

IONAMESTATUS_COMPONENT ionsTZNP5[IOCMD_TZNP1to5_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ����5"
  },
  {
    1,//������ iocmd2
    "���� ��� ����5"
  },
  {
    1,//������ iocmd3
    "���� ��� ����5"
  },
  {
    1,//������ iocmd4
    "���� �� ����5"
  },
  {
    1,//������ iocmd5
    "���� ����5"
  },
  {
    1,//������ iocmd6
    "���� �� ����5 3I0"
  },
  {
    1,//������ iocmd7
    "���� ����5 3I0"
  },
  {
    1,//������ iocmd8
    "���� �� ����5 3U0"
  },
  {
    1,//������ iocmd9
    "���� ����5 3U0"
  },
  {
    1,//������ iocmd10
    "���� ��� ����5"
  },
  {
    1,//������ iocmd11
    "������ ����5"
  }
};

LineMenuItem sub_menu_comp_TZNP5[8] =
{
  { TZNP5_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_TZNP, typeMenuSub},//control_item, parent
  { "������� ����5",    (void*)&UstListCompTZNP5, typeMenuProg},
  { "�������� ����5",   (void*)&VidListCompTZNP5, typeMenuProg},
  { "���������� ����5", (void*)&UprListCompTZNP5, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compTZNP5[] =
{
  { "������� ����5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP5, typeMenuList},//control_item, parent
  { "��� ����5 3I0", (void*)&UstCompTZNP5, typeMenuProg},
  { "��� ����5 3U0", (void*)&UstCompTZNP5, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compTZNP5[] =
{
  { "�������� ����5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP5, typeMenuList},//control_item, parent
/*
  { "�������� ����5",         (void*)&VidCompTZNP5, typeMenuProg},
  { "�������� ����5 3I0",     (void*)&VidCompTZNP5, typeMenuProg},
  { "�������� ����5 3U0",     (void*)&VidCompTZNP5, typeMenuProg},
  { "���� ����� ����5",       (void*)&VidCompTZNP5, typeMenuProg},

  { "����� ����5 ��",         (void*)&VidCompTZNP5, typeMenuProg},
  { "����� ����5 ��",         (void*)&VidCompTZNP5, typeMenuProg},
  { "����� ����5 ��",         (void*)&VidCompTZNP5, typeMenuProg},

  { "����� ����5 3I0 ��",     (void*)&VidCompTZNP5, typeMenuProg},
  { "����� ����5 3I0 ��",     (void*)&VidCompTZNP5, typeMenuProg},
  { "����� ����5 3I0 ��",     (void*)&VidCompTZNP5, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compTZNP5[] =
{
  { "������ ����5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP5, typeMenuList},//control_item, parent
  { "������ ����5",        (void*)&UprCompTZNP5, typeMenuProg},
  { "������ ����5 3I0",    (void*)&UprCompTZNP5, typeMenuProg},
  { "������ ����5 3U0",    (void*)&UprCompTZNP5, typeMenuProg},
  { "������� ����5",       (void*)&UprCompTZNP5, typeMenuProg},
  { "����� �� ����5",      (void*)&UprCompTZNP5, typeMenuProg},
  { "������� ��� ����5",   (void*)&UprCompTZNP5, typeMenuProg},
  { "��������� ����5",     (void*)&UprCompTZNP5, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompTZNP5(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_ust_compTZNP5);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp3()

void UstListCompTZNP5()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compTZNP5);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompTZNP5);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompTZNP5()

void UstCompTZNP5()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compTZNP5);
  PassWord(EditUstTZNP5);
}//VidCompTZNP4()

void EditUstTZNP5()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compTZNP5);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompTZNP5()

//--------------------------------------------------

void PereinitVidListCompTZNP5(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_vid_compTZNP5);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitVidListCompTZNP5(short flg)

void VidListCompTZNP5()
{
  SelectorMNGBAZA(MNGVID_TZNP1to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compTZNP5);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompTZNP5);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompTZNP5()

void VidCompTZNP5()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compTZNP5);
//  PassWord(EditVidAPV);
  EditVidTZNP5();
}//VidCompTZNP5()

void EditVidTZNP5()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compTZNP5);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompTZNP5(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compTZNP5, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompTZNP5()
{
  SelectorMNGBAZA(MNGUPR_TZNP1to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compTZNP5);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompTZNP5);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP5()

void UprCompTZNP5()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compTZNP5);
  PassWord(EditUprTZNP5);

}//UprCompTZNP5()

void EditUprTZNP5()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compTZNP5[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrTZNP2);//������������� ������� ����������
}//EditUprTZNP5()

short  KadrMenuFormat_upr_compTZNP5(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compTZNP5[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //���������� ������� ���������� � �����
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrTZNP2(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compTZNP5(WorkControl *workCntr)

int initUstTZNP5(char init)
{
 return initUstTZNP1(init);
}//initUstTZNP5(short mngUst, char init)

void  prepareUstTZNP5(short idxC)
{
  prepareUstTZNP1(idxC);
}//prepareUstTZNP5(short idxC)

int codecUstTZNP5(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
 return codecUstTZNP1(codec, offset, ust);
}//codecUstTZNP5(char *buf, short offset, int ust)

void diffTZNP5ToRepozitar()
{
//���������� ��������� ���������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  TZNP5_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_TZNP5;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_TZNP;   //�-�� ������
  rpzcomponent_obj.numClon     = 5;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstTZNP5;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstTZNP5;//���������� �������

  rpzcomponent_obj.nameStatusIO = ionsTZNP5;          //����� � ������ ������ IO

  rpzcomponent_obj.codecUst = codecUstTZNP5;   //����������-������������� �������

}//

#endif // _HIDE_COMPONENT

