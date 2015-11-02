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
extern char *bitStringUNI[];

void PereinitUstListCompTZNP2(short flg);
void UstListCompTZNP2();
void ustRedactorCompTZNP2();
void UstCompTZNP2();

void PereinitVidListCompTZNP2(short flg);
void VidListCompTZNP2();
void vidRedactorCompTZNP2();
void VidCompTZNP2();

void PereinitUprListCompTZNP2(short flg);
void UprListCompTZNP2();
void uprRedactorCompTZNP2();
void UprCompTZNP2();
short  KadrMenuFormat_upr_compTZNP2(void *workCntr);//(WorkControl *workCntr);
int  initUstTZNP2(char init);
void  prepareUstTZNP2(short idxC);
void  prepareUstTZNP1(short idxC);

//int ViewerEditUstTZNP2();
//int ViewerEditVidTZNP2();
void EditUstTZNP2();
void EditVidTZNP2();
void EditUprTZNP2();
int codecUstTZNP2(char codec, short offset, int ust);
int codecUstTZNP1(char codec, short offset, int ust);
int initUstTZNP1(char init);

char *selectorUprStrTZNP2(short iBit, UNS_32 ustUpr);
short  KadrMenuFormat_ustvidTZNP(void *workCntr);//(WorkControl *workCntr);

char TZNP2_TITLE[] = "����2";

IONAMESTATUS_COMPONENT ionsTZNP2[IOCMD_TZNP1to5_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ����2"
  },
  {
    1,//������ iocmd2
    "���� ��� ����2"
  },
  {
    1,//������ iocmd3
    "���� ��� ����2"
  },
  {
    1,//������ iocmd4
    "���� �� ����2"
  },
  {
    1,//������ iocmd5
    "���� ����2"
  },
  {
    1,//������ iocmd6
    "���� �� ����2 3I0"
  },
  {
    1,//������ iocmd7
    "���� ����2 3I0"
  },
  {
    1,//������ iocmd8
    "���� �� ����2 3U0"
  },
  {
    1,//������ iocmd9
    "���� ����2 3U0"
  },
  {
    1,//������ iocmd10
    "���� ��� ����2"
  },
  {
    1,//������ iocmd11
    "������ ����2"
  }
};

LineMenuItem sub_menu_comp_TZNP2[8] =
{
  { TZNP2_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_TZNP, typeMenuSub},//control_item, parent
  { "������� ����2",     (void*)&UstListCompTZNP2, typeMenuProg},
  { "�������� ����2",    (void*)&VidListCompTZNP2, typeMenuProg},
  { "���������� ����2",  (void*)&UprListCompTZNP2, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compTZNP2[] =
{
  { "������� ����2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP2, typeMenuList},//control_item, parent
  { "��� ����2 3I0",        (void*)&UstCompTZNP2, typeMenuProg},
  { "��� ����2 3U0",        (void*)&UstCompTZNP2, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compTZNP2[] =
{
  { "�������� ����2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP2, typeMenuList},//control_item, parent
/*
  { "�������� ����2",         (void*)&VidCompTZNP2, typeMenuProg},
  { "�������� ����2 3I0",     (void*)&VidCompTZNP2, typeMenuProg},
  { "�������� ����2 3U0",     (void*)&VidCompTZNP2, typeMenuProg},
  { "���� ����� ����2",       (void*)&VidCompTZNP2, typeMenuProg},

  { "����� ����2 ��",         (void*)&VidCompTZNP2, typeMenuProg},
  { "����� ����2 ��",         (void*)&VidCompTZNP2, typeMenuProg},
  { "����� ����2 ��",         (void*)&VidCompTZNP2, typeMenuProg},

  { "����� ����2 3I0 ��",     (void*)&VidCompTZNP2, typeMenuProg},
  { "����� ����2 3I0 ��",     (void*)&VidCompTZNP2, typeMenuProg},
  { "����� ����2 3I0 ��",     (void*)&VidCompTZNP2, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compTZNP2[] =
{
  { "������ ����2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP2, typeMenuList},//control_item, parent
  { "������ ����2",        (void*)&UprCompTZNP2, typeMenuProg},
  { "������ ����2 3I0",    (void*)&UprCompTZNP2, typeMenuProg},
  { "������ ����2 3U0",    (void*)&UprCompTZNP2, typeMenuProg},
  { "������� ����2",       (void*)&UprCompTZNP2, typeMenuProg},
  { "����� �� ����2",      (void*)&UprCompTZNP2, typeMenuProg},
  { "������� ��� ����2",   (void*)&UprCompTZNP2, typeMenuProg},
  { "��������� ����2",     (void*)&UprCompTZNP2, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompTZNP2(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_ust_compTZNP2);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UstListCompTZNP2()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compTZNP2);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompTZNP2);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompTZNP2()

void UstCompTZNP2()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compTZNP2);
  PassWord(EditUstTZNP2);
}//VidCompTZNP2()

void EditUstTZNP2()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compTZNP2);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompTZNP2()

//--------------------------------------------------

void PereinitVidListCompTZNP2(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_vid_compTZNP2);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void VidListCompTZNP2()
{
  SelectorMNGBAZA(MNGVID_TZNP1to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compTZNP2);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompTZNP2);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompTZNP2()

void VidCompTZNP2()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compTZNP2);
//  PassWord(EditVidAPV);
  EditVidTZNP2();
}//VidCompTZNP2()

void EditVidTZNP2()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compTZNP2);
}//

//--------------------------------------------------

void PereinitUprListCompTZNP2(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compTZNP2, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompTZNP2()
{
  SelectorMNGBAZA(MNGUPR_TZNP1to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compTZNP2);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompTZNP2);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP2()

void UprCompTZNP2()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compTZNP2);
  PassWord(EditUprTZNP2);

}//UprCompTZNP2()

void EditUprTZNP2()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compTZNP2[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrTZNP2);//������������� ������� ����������
}//EditUprTZNP2()

short  KadrMenuFormat_upr_compTZNP2(void *pstr)//(WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compTZNP2[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrTZNP2(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compTZNP2(WorkControl *workCntr)

char *selectorUprStrTZNP2(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
  }//switch
}//selectorUprStrTZNP2(short ibit, UNS_32 ustUpr)

int initUstTZNP2(char init)
{
 return initUstTZNP1(init);
}//initUstTZNP2(short mngUst, char init)

void  prepareUstTZNP2(short idxC)
{
  prepareUstTZNP1(idxC);
}//prepareUstTZNP2(short idxC)

int codecUstTZNP2(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
 return codecUstTZNP1(codec, offset, ust);
}//codecUstTZNP2(char *buf, short offset, int ust)

char diffTZNP2ToRepozitar()
{
//���������������� ��������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  TZNP2_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_TZNP2;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_TZNP;   //�-�� ������
  rpzcomponent_obj.numClon     = 2;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstTZNP2;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstTZNP2;//���������� �������

  rpzcomponent_obj.nameStatusIO = ionsTZNP2;          //����� � ������ ������ IO

  rpzcomponent_obj.codecUst = codecUstTZNP2;   //����������-������������� �������

  return 0;//�� �������� �����������
}//

#endif // _HIDE_COMPONENT

