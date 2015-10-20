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
#define KOD_COMPONENT  MTZ_COMP1
//�-�� ��������
#define CNT_STUPEN_MTZ  5

#endif // _HIDE_COMPONENT

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "MTZ2Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_MTZ[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//������� ������� �����������

void PereinitUstListCompMTZ3(short flg);
void UstListCompMTZ3();
void ustRedactorCompMTZ3();
void UstCompMTZ3();
short  KadrMenuFormat_ust_compMTZ3(void *workCntr);//(WorkControl *workCntr);

void PereinitVidListCompMTZ3(short flg);
void VidListCompMTZ3();
void vidRedactorCompMTZ3();
void VidCompMTZ3();
short  KadrMenuFormat_vid_compMTZ3(void *workCntr);//(WorkControl *workCntr);

void PereinitUprListCompMTZ3(short flg);
void UprListCompMTZ3();
void uprRedactorCompMTZ3();
void UprCompMTZ3();
short  KadrMenuFormat_upr_compMTZ3(void *workCntr);//(WorkControl *workCntr);
int   initUstMTZ3(char init);
void  prepareUstMTZ2(short idxC);
void  prepareUstMTZ3(short idxC);

//int ViewerEditUstMTZ3();
//int ViewerEditVidMTZ3();
void EditUstMTZ3();
void EditVidMTZ3();
void EditUprMTZ3();
int codecUstMTZ3(char codec, short offset, int ust);
int codecUstMTZ2(char codec, short offset, int ust);
int initUstMTZ2(char init);

char *selectorUprStrMTZ2(short iBit, UNS_32 ustUpr);
void UpravlChooserMTZInKadr(char *nameUpr, short ibit, void *workCntr);
void UpravlRedactorChooseMTZ(char *nameUpr, short ibit);
short  KadrMenuFormat_ustvidMTZ(void *workCntr);
void diffMTZ3ToRepozitar();

char MTZ3_TITLE[] = "���3";

IONAMESTATUS_COMPONENT ionsMTZ3[IOCMD_MTZ2to5_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ���3"
  },
  {
    1,//������ iocmd2
    "���� ��� ���3"
  },
  {
    1,//������ iocmd3
    "������ ��� ���3"
  },
  {
    1,//������ iocmd4
    "���� �� ���3"
  },
  {
    1,//������ iocmd5
    "���� �� ���3 ���"
  },
  {
    1,//������ iocmd6
    "���� �� ���3 ���"
  },
  {
    1,//������ iocmd7
    "���� �� ���3 ��"
  },
  {
    1,//������ iocmd8
    "���� ���3"
  },
  {
    1,//������ iocmd9
    "���� ��� ���3"
  },
  {
    1,//������ iocmd10
    "������ ���3 ���"
  },
  {
    1,//������ iocmd11
    "������ ���3 ���"
  }
};

LineMenuItem sub_menu_comp_MTZ3[8] =
{
  { MTZ3_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_MTZ, typeMenuSub},//control_item, parent
  { "������� ���3",    (void *)&UstListCompMTZ3, typeMenuProg},
  { "�������� ���3",   (void *)&VidListCompMTZ3, typeMenuProg},
  { "���������� ���3", (void *)&UprListCompMTZ3, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compMTZ3[] =
{
  { "������� ���3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ3, typeMenuList},//control_item, parent
  { "��� ���3",         (void*)&UstCompMTZ3, typeMenuProg},
  { "��� ���3 ������",  (void*)&UstCompMTZ3, typeMenuProg},
  { "��� ���3 �����",   (void*)&UstCompMTZ3, typeMenuProg},
  { "��� ���3 ��",      (void*)&UstCompMTZ3, typeMenuProg},
  { "��� ���� ���3 �H", (void*)&UstCompMTZ3, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compMTZ3[] =
{
  { "�������� ���3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ3, typeMenuList},//control_item, parent
/*
  { "�������� ���3",         (void*)&VidCompMTZ3, typeMenuProg},
  { "�������� ���3 ������",  (void*)&VidCompMTZ3, typeMenuProg},
  { "�������� ���3 �����",   (void*)&VidCompMTZ3, typeMenuProg},
  { "�������� ���3 ��",      (void*)&VidCompMTZ3, typeMenuProg},
  { "���� ����� ���3",       (void*)&VidCompMTZ3, typeMenuProg},

  { "����� ���3 ��",         (void*)&VidCompMTZ3, typeMenuProg},
  { "����� ���3 ��",         (void*)&VidCompMTZ3, typeMenuProg},
  { "����� ���3 ��",         (void*)&VidCompMTZ3, typeMenuProg},

  { "����� ���3 �� ���",     (void*)&VidCompMTZ3, typeMenuProg},
  { "����� ���3 �� ���",     (void*)&VidCompMTZ3, typeMenuProg},
  { "����� ���3 �� ���",     (void*)&VidCompMTZ3, typeMenuProg},

  { "����� ���3 �� ���",     (void*)&VidCompMTZ3, typeMenuProg},
  { "����� ���3 �� ���",     (void*)&VidCompMTZ3, typeMenuProg},
  { "����� ���3 �� ���",     (void*)&VidCompMTZ3, typeMenuProg},

  { "����� ���3 �� ��",      (void*)&VidCompMTZ3, typeMenuProg},
  { "����� ���3 �� ��",      (void*)&VidCompMTZ3, typeMenuProg},
  { "����� ���3 �� ��",      (void*)&VidCompMTZ3, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compMTZ3[] =
{
  { "������ ���3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ3, typeMenuList},//control_item, parent
  { "��� ���3",           (void*)&UprCompMTZ3, typeMenuProg},
  { "������ ���3",        (void*)&UprCompMTZ3, typeMenuProg},
  { "���3 ������",        (void*)&UprCompMTZ3, typeMenuProg},
  { "���3 �����",         (void*)&UprCompMTZ3, typeMenuProg},
  { "��������� ���3",     (void*)&UprCompMTZ3, typeMenuProg},
  { "���3 ����������",    (void*)&UprCompMTZ3, typeMenuProg},
  { "������� ��� ���3",   (void*)&UprCompMTZ3, typeMenuProg},
  { "��������� ���3",     (void*)&UprCompMTZ3, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompMTZ3(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_ust_compMTZ3);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp3()

void UstListCompMTZ3()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compMTZ3);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompMTZ3);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompMTZ3()

void UstCompMTZ3()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compMTZ3);
  PassWord(EditUstMTZ3);
}//VidCompMTZ3()

void EditUstMTZ3()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compMTZ3);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompMTZ3()

//--------------------------------------------------

void PereinitVidListCompMTZ3(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_vid_compMTZ3);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitVidListCompMTZ3(short flg)

void VidListCompMTZ3()
{
  SelectorMNGBAZA(MNGVID_MTZ2to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compMTZ3);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompMTZ3);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ3()

void VidCompMTZ3()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compMTZ3);
//  PassWord(EditVidAPV);
  EditVidMTZ3();
}//VidCompMTZ3()

void EditVidMTZ3()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compMTZ3);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompMTZ3(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compMTZ3, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompMTZ3()
{
  SelectorMNGBAZA(MNGUPR_MTZ2to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compMTZ3);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompMTZ3);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ3()

void UprCompMTZ3()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compMTZ3);
  PassWord(EditUprMTZ3);
}//VidCompMTZ3()

void EditUprMTZ3()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compMTZ3[LIGHTLINEMENU +1+SUBDATA].Line1;

  switch(LIGHTLINEMENU)
  {
    case 0: UpravlRedactorChooseMTZ(nameUpr, LIGHTLINEMENU);//������������� ������� ����������
    break;
    default:UpravlRedactor(nameUpr, LIGHTLINEMENU+1, &selectorUprStrMTZ2);//������������� ������� ����������
  }//switch

}//EditVidMTZ3()

short  KadrMenuFormat_upr_compMTZ3(void *pstr)//(WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  short chooseBit = 2;//�-�� ��� � choose
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compMTZ3[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      if(i<(chooseBit-1))
        UpravlChooserMTZInKadr(nameUpr, i, workCntr);
      else
        //      UpravlViewerInKadr(nameUpr, i+(chooseBit-1), workCntr);//���������� ������� ���������� � �����
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
        selectorUprStrMTZ2(i+(chooseBit-1), getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compMTZ3(WorkControl *workCntr)

int initUstMTZ3(char init)
{
 return initUstMTZ2(init);
}//initUstMTZ1(short mngUst, char init)

void  prepareUstMTZ3(short idxC)
{
  prepareUstMTZ2(idxC);
}//prepareUstMTZ3(short idxC)

int codecUstMTZ3(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  return codecUstMTZ2(codec, offset, ust);
}//codecUstMTZ3(char *buf, short offset, int ust)

void diffMTZ3ToRepozitar()
{
//���������� ��������� ���������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  MTZ3_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_MTZ3;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_MTZ;   //�-�� ������
  rpzcomponent_obj.numClon     = 3;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstMTZ3;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstMTZ3;//���������� �������

  rpzcomponent_obj.nameStatusIO = ionsMTZ3;          //����� � ������ ������ IO

  rpzcomponent_obj.codecUst = codecUstMTZ3;   //����������-������������� �������

}//

#endif // _HIDE_COMPONENT

