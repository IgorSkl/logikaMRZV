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

void PereinitUstListCompTZNP3(short flg);
void UstListCompTZNP3();
void ustRedactorCompTZNP3();
void UstCompTZNP3();

void PereinitVidListCompTZNP3(short flg);
void VidListCompTZNP3();
void vidRedactorCompTZNP3();
void VidCompTZNP3();

void PereinitUprListCompTZNP3(short flg);
void UprListCompTZNP3();
void uprRedactorCompTZNP3();
void UprCompTZNP3();
short  KadrMenuFormat_upr_compTZNP3(void *workCntr);
int  initUstTZNP3(char init);
void  prepareUstTZNP3(short idxC);
void  prepareUstTZNP1(short idxC);

//int ViewerEditUstTZNP3();
//int ViewerEditVidTZNP3();
void EditUstTZNP3();
void EditVidTZNP3();
void EditUprTZNP3();
int codecUstTZNP3(char codec, short offset, int ust);
int codecUstTZNP1(char codec, short offset, int ust);
int initUstTZNP1(char init);

char *selectorUprStrTZNP2(short iBit, UNS_32 ustUpr);
short  KadrMenuFormat_ustvidTZNP(void *workCntr);
void diffTZNP3ToRepozitar();

char TZNP3_TITLE[] = "����3";

IONAMESTATUS_COMPONENT ionsTZNP3[IOCMD_TZNP1to5_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ����3"
  },
  {
    1,//������ iocmd2
    "���� ��� ����3"
  },
  {
    1,//������ iocmd3
    "���� ��� ����3"
  },
  {
    1,//������ iocmd4
    "���� �� ����3"
  },
  {
    1,//������ iocmd5
    "���� ����3"
  },
  {
    1,//������ iocmd6
    "���� �� ����3 3I0"
  },
  {
    1,//������ iocmd7
    "���� ����3 3I0"
  },
  {
    1,//������ iocmd8
    "���� �� ����3 3U0"
  },
  {
    1,//������ iocmd9
    "���� ����3 3U0"
  },
  {
    1,//������ iocmd10
    "���� ��� ����3"
  },
  {
    1,//������ iocmd11
    "������ ����3"
  }
};

LineMenuItem sub_menu_comp_TZNP3[8] =
{
  { TZNP3_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_TZNP, typeMenuSub},//control_item, parent
  { "������� ����3",    (void*)&UstListCompTZNP3, typeMenuProg},
  { "�������� ����3",   (void*)&VidListCompTZNP3, typeMenuProg},
  { "���������� ����3", (void*)&UprListCompTZNP3, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compTZNP3[] =
{
  { "������� ����3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP3, typeMenuList},//control_item, parent
  { "��� ����3 3I0", (void*)&UstCompTZNP3, typeMenuProg},
  { "��� ����3 3U0", (void*)&UstCompTZNP3, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compTZNP3[] =
{
  { "�������� ����3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP3, typeMenuList},//control_item, parent
/*
  { "�������� ����3",         (void*)&VidCompTZNP3, typeMenuProg},
  { "�������� ����3 3I0",     (void*)&VidCompTZNP3, typeMenuProg},
  { "�������� ����3 3U0",     (void*)&VidCompTZNP3, typeMenuProg},
  { "���� ����� ����3",       (void*)&VidCompTZNP3, typeMenuProg},

  { "����� ����3 ��",         (void*)&VidCompTZNP3, typeMenuProg},
  { "����� ����3 ��",         (void*)&VidCompTZNP3, typeMenuProg},
  { "����� ����3 ��",         (void*)&VidCompTZNP3, typeMenuProg},

  { "����� ����3 3I0 ��",     (void*)&VidCompTZNP3, typeMenuProg},
  { "����� ����3 3I0 ��",     (void*)&VidCompTZNP3, typeMenuProg},
  { "����� ����3 3I0 ��",     (void*)&VidCompTZNP3, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compTZNP3[] =
{
  { "������ ����3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP3, typeMenuList},//control_item, parent
  { "������ ����3",        (void*)&UprCompTZNP3, typeMenuProg},
  { "������ ����3 3I0",    (void*)&UprCompTZNP3, typeMenuProg},
  { "������ ����3 3U0",    (void*)&UprCompTZNP3, typeMenuProg},
  { "������� ����3",       (void*)&UprCompTZNP3, typeMenuProg},
  { "����� �� ����3",      (void*)&UprCompTZNP3, typeMenuProg},
  { "������� ��� ����3",   (void*)&UprCompTZNP3, typeMenuProg},
  { "��������� ����3",     (void*)&UprCompTZNP3, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompTZNP3(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_ust_compTZNP3);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp3()

void UstListCompTZNP3()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compTZNP3);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompTZNP3);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompTZNP3()

void UstCompTZNP3()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compTZNP3);
  PassWord(EditUstTZNP3);
}//VidCompTZNP3()

void EditUstTZNP3()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compTZNP3);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompTZNP3()

//--------------------------------------------------

void PereinitVidListCompTZNP3(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_vid_compTZNP3);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitVidListCompTZNP3(short flg)

void VidListCompTZNP3()
{
  SelectorMNGBAZA(MNGVID_TZNP1to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compTZNP3);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompTZNP3);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompTZNP3()

void VidCompTZNP3()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compTZNP3);
//  PassWord(EditVidAPV);
  EditVidTZNP3();
}//VidCompTZNP3()

void EditVidTZNP3()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compTZNP3);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompTZNP3(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compTZNP3, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompTZNP3()
{
  SelectorMNGBAZA(MNGUPR_TZNP1to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compTZNP3);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompTZNP3);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP3()

void UprCompTZNP3()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compTZNP3);
  PassWord(EditUprTZNP3);

}//UprCompTZNP3()

void EditUprTZNP3()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compTZNP3[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrTZNP2);//������������� ������� ����������
}//EditUprTZNP2()

short  KadrMenuFormat_upr_compTZNP3(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compTZNP3[i+1+SUBDATA].Line1;
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
}//KadrMenuFormat_upr_compTZNP3(WorkControl *workCntr)

int initUstTZNP3(char init)
{
 return initUstTZNP1(init);
}//initUstTZNP3(short mngUst, char init)

void  prepareUstTZNP3(short idxC)
{
  prepareUstTZNP1(idxC);
}//prepareUstTZNP3(short idxC)

int codecUstTZNP3(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
 return codecUstTZNP1(codec, offset, ust);
}//codecUstTZNP3(char *buf, short offset, int ust)

void diffTZNP3ToRepozitar()
{
//���������� ��������� ���������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  TZNP3_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_TZNP3;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_TZNP;   //�-�� ������
  rpzcomponent_obj.numClon     = 3;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstTZNP3;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstTZNP3;//���������� �������

  rpzcomponent_obj.nameStatusIO = ionsTZNP3;          //����� � ������ ������ IO

  rpzcomponent_obj.codecUst = codecUstTZNP3;   //����������-������������� �������

}//

#endif // _HIDE_COMPONENT

