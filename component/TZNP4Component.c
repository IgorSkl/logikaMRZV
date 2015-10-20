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

void PereinitUstListCompTZNP4(short flg);
void UstListCompTZNP4();
void ustRedactorCompTZNP4();
void UstCompTZNP4();

void PereinitVidListCompTZNP4(short flg);
void VidListCompTZNP4();
void vidRedactorCompTZNP4();
void VidCompTZNP4();

void PereinitUprListCompTZNP4(short flg);
void UprListCompTZNP4();
void uprRedactorCompTZNP4();
void UprCompTZNP4();
short  KadrMenuFormat_upr_compTZNP4(void *workCntr);
int  initUstTZNP4(char init);
void  prepareUstTZNP4(short idxC);
void  prepareUstTZNP1(short idxC);

//int ViewerEditUstTZNP4();
//int ViewerEditVidTZNP4();
void EditUstTZNP4();
void EditVidTZNP4();
void EditUprTZNP4();
int codecUstTZNP4(char codec, short offset, int ust);
int codecUstTZNP1(char codec, short offset, int ust);
int initUstTZNP1(char init);

char *selectorUprStrTZNP2(short iBit, UNS_32 ustUpr);
short  KadrMenuFormat_ustvidTZNP(void *workCntr);
void diffTZNP4ToRepozitar();

char TZNP4_TITLE[] = "����4";

IONAMESTATUS_COMPONENT ionsTZNP4[IOCMD_TZNP1to5_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ����4"
  },
  {
    1,//������ iocmd2
    "���� ��� ����4"
  },
  {
    1,//������ iocmd3
    "���� ��� ����4"
  },
  {
    1,//������ iocmd4
    "���� �� ����4"
  },
  {
    1,//������ iocmd5
    "���� ����4"
  },
  {
    1,//������ iocmd6
    "���� �� ����4 3I0"
  },
  {
    1,//������ iocmd7
    "���� ����4 3I0"
  },
  {
    1,//������ iocmd8
    "���� �� ����4 3U0"
  },
  {
    1,//������ iocmd9
    "���� ����4 3U0"
  },
  {
    1,//������ iocmd10
    "���� ��� ����4"
  },
  {
    1,//������ iocmd11
    "������ ����4"
  }
};

LineMenuItem sub_menu_comp_TZNP4[8] =
{
  { TZNP4_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_TZNP, typeMenuSub},//control_item, parent
  { "������� ����4",    (void*)&UstListCompTZNP4, typeMenuProg},
  { "�������� ����4",   (void*)&VidListCompTZNP4, typeMenuProg},
  { "���������� ����4", (void*)&UprListCompTZNP4, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compTZNP4[] =
{
  { "������� ����4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP4, typeMenuList},//control_item, parent
  { "��� ����4 3I0", (void*)&UstCompTZNP4, typeMenuProg},
  { "��� ����4 3U0", (void*)&UstCompTZNP4, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compTZNP4[] =
{
  { "�������� ����4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP4, typeMenuList},//control_item, parent
/*
  { "�������� ����4",         (void*)&VidCompTZNP4, typeMenuProg},
  { "�������� ����4 3I0",     (void*)&VidCompTZNP4, typeMenuProg},
  { "�������� ����4 3U0",     (void*)&VidCompTZNP4, typeMenuProg},
  { "���� ����� ����4",       (void*)&VidCompTZNP4, typeMenuProg},

  { "����� ����4 ��",         (void*)&VidCompTZNP4, typeMenuProg},
  { "����� ����4 ��",         (void*)&VidCompTZNP4, typeMenuProg},
  { "����� ����4 ��",         (void*)&VidCompTZNP4, typeMenuProg},

  { "����� ����4 3I0 ��",     (void*)&VidCompTZNP4, typeMenuProg},
  { "����� ����4 3I0 ��",     (void*)&VidCompTZNP4, typeMenuProg},
  { "����� ����4 3I0 ��",     (void*)&VidCompTZNP4, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compTZNP4[] =
{
  { "������ ����4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP4, typeMenuList},//control_item, parent
  { "������ ����4",        (void*)&UprCompTZNP4, typeMenuProg},
  { "������ ����4 3I0",    (void*)&UprCompTZNP4, typeMenuProg},
  { "������ ����4 3U0",    (void*)&UprCompTZNP4, typeMenuProg},
  { "������� ����4",       (void*)&UprCompTZNP4, typeMenuProg},
  { "����� �� ����4",      (void*)&UprCompTZNP4, typeMenuProg},
  { "������� ��� ����4",   (void*)&UprCompTZNP4, typeMenuProg},
  { "��������� ����4",     (void*)&UprCompTZNP4, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompTZNP4(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_ust_compTZNP4);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp3()

void UstListCompTZNP4()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compTZNP4);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompTZNP4);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompTZNP4()

void UstCompTZNP4()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compTZNP4);
  PassWord(EditUstTZNP4);
}//VidCompTZNP4()

void EditUstTZNP4()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compTZNP4);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompTZNP4()

//--------------------------------------------------

void PereinitVidListCompTZNP4(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_vid_compTZNP4);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitVidListCompTZNP4(short flg)

void VidListCompTZNP4()
{
  SelectorMNGBAZA(MNGVID_TZNP1to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compTZNP4);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompTZNP4);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompTZNP4()

void VidCompTZNP4()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compTZNP4);
//  PassWord(EditVidAPV);
  EditVidTZNP4();
}//VidCompTZNP4()

void EditVidTZNP4()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compTZNP4);
}//

//--------------------------------------------------

void PereinitUprListCompTZNP4(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compTZNP4, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompTZNP4()
{
  SelectorMNGBAZA(MNGUPR_TZNP1to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compTZNP4);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompTZNP4);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP4()

void UprCompTZNP4()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compTZNP4);
  PassWord(EditUprTZNP4);

}//UprCompTZNP4()

void EditUprTZNP4()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compTZNP4[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrTZNP2);//������������� ������� ����������
}//EditUprTZNP4()

short  KadrMenuFormat_upr_compTZNP4(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compTZNP4[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //    UpravlViewerInKadr(nameUpr, i, workCntr);//���������� ������� ���������� � �����
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrTZNP2(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compTZNP4(WorkControl *workCntr)

int initUstTZNP4(char init)
{
 return initUstTZNP1(init);
}//initUstTZNP4(short mngUst, char init)

void  prepareUstTZNP4(short idxC)
{
  prepareUstTZNP1(idxC);
}//prepareUstTZNP4(short idxC)

int codecUstTZNP4(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
 return codecUstTZNP1(codec, offset, ust);
}//codecUstTZNP4(char *buf, short offset, int ust)


void diffTZNP4ToRepozitar()
{
//���������� ��������� ���������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  TZNP4_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_TZNP4;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_TZNP;   //�-�� ������
  rpzcomponent_obj.numClon     = 4;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstTZNP4;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstTZNP4;//���������� �������

  rpzcomponent_obj.nameStatusIO = ionsTZNP4;          //����� � ������ ������ IO

  rpzcomponent_obj.codecUst = codecUstTZNP4;   //����������-������������� �������

}//

#endif // _HIDE_COMPONENT

