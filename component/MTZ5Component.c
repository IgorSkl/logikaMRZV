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

void PereinitUstListCompMTZ5(short flg);
void UstListCompMTZ5();
void ustRedactorCompMTZ5();
void UstCompMTZ5();
short  KadrMenuFormat_ust_compMTZ5(void *workCntr);

void PereinitVidListCompMTZ5(short flg);
void VidListCompMTZ5();
void vidRedactorCompMTZ5();
void VidCompMTZ5();
short  KadrMenuFormat_vid_compMTZ5(void *workCntr);

void PereinitUprListCompMTZ5(short flg);
void UprListCompMTZ5();
void uprRedactorCompMTZ5();
void UprCompMTZ5();
short  KadrMenuFormat_upr_compMTZ5(void *workCntr);
int  initUstMTZ5(char init);
void  prepareUstMTZ2(short idxC);
void  prepareUstMTZ5(short idxC);

//int ViewerEditUstMTZ5();
//int ViewerEditVidMTZ5();
void EditUstMTZ5();
void EditVidMTZ5();
void EditUprMTZ5();
int codecUstMTZ5(char codec, short offset, int ust);
int codecUstMTZ2(char codec, short offset, int ust);
int initUstMTZ2(char init);

char *selectorUprStrMTZ2(short iBit, UNS_32 ustUpr);
void UpravlChooserMTZInKadr(char *nameUpr, short ibit, void *workCntr);
void UpravlRedactorChooseMTZ(char *nameUpr, short ibit);
short  KadrMenuFormat_ustvidMTZ(void *workCntr);

char MTZ5_TITLE[] = "���5";

IONAMESTATUS_COMPONENT ionsMTZ5[IOCMD_MTZ2to5_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ���5"
  },
  {
    1,//������ iocmd2
    "���� ��� ���5"
  },
  {
    1,//������ iocmd3
    "������ ��� ���5"
  },
  {
    1,//������ iocmd4
    "���� �� ���5"
  },
  {
    1,//������ iocmd5
    "���� �� ���5 ���"
  },
  {
    1,//������ iocmd6
    "���� �� ���5 ���"
  },
  {
    1,//������ iocmd7
    "���� �� ���5 ��"
  },
  {
    1,//������ iocmd8
    "���� ���5"
  },
  {
    1,//������ iocmd9
    "���� ��� ���5"
  },
  {
    1,//������ iocmd10
    "������ ���5 ���"
  },
  {
    1,//������ iocmd11
    "������ ���5 ���"
  }
};

LineMenuItem sub_menu_comp_MTZ5[8] =
{
  { MTZ5_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_MTZ, typeMenuSub},//control_item, parent
  { "������� ���5",    (void *)&UstListCompMTZ5, typeMenuProg},
  { "�������� ���5",   (void *)&VidListCompMTZ5, typeMenuProg},
  { "���������� ���5", (void *)&UprListCompMTZ5, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compMTZ5[] =
{
  { "������� ���5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ5, typeMenuList},//control_item, parent
  { "��� ���5",         (void*)&UstCompMTZ5, typeMenuProg},
  { "��� ���5 ������",  (void*)&UstCompMTZ5, typeMenuProg},
  { "��� ���5 �����",   (void*)&UstCompMTZ5, typeMenuProg},
  { "��� ���5 ��",      (void*)&UstCompMTZ5, typeMenuProg},
  { "��� ���� ���5 �H", (void*)&UstCompMTZ5, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compMTZ5[] =
{
  { "�������� ���5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ5, typeMenuList},//control_item, parent
/*
  { "�������� ���5",         (void*)&VidCompMTZ5, typeMenuProg},
  { "�������� ���5 ������",  (void*)&VidCompMTZ5, typeMenuProg},
  { "�������� ���5 �����",   (void*)&VidCompMTZ5, typeMenuProg},
  { "�������� ���5 ��",      (void*)&VidCompMTZ5, typeMenuProg},
  { "���� ����� ���5",       (void*)&VidCompMTZ5, typeMenuProg},

  { "����� ���5 ��",         (void*)&VidCompMTZ5, typeMenuProg},
  { "����� ���5 ��",         (void*)&VidCompMTZ5, typeMenuProg},
  { "����� ���5 ��",         (void*)&VidCompMTZ5, typeMenuProg},

  { "����� ���5 �� ���",     (void*)&VidCompMTZ5, typeMenuProg},
  { "����� ���5 �� ���",     (void*)&VidCompMTZ5, typeMenuProg},
  { "����� ���5 �� ���",     (void*)&VidCompMTZ5, typeMenuProg},

  { "����� ���5 �� ���",     (void*)&VidCompMTZ5, typeMenuProg},
  { "����� ���5 �� ���",     (void*)&VidCompMTZ5, typeMenuProg},
  { "����� ���5 �� ���",     (void*)&VidCompMTZ5, typeMenuProg},

  { "����� ���5 �� ��",      (void*)&VidCompMTZ5, typeMenuProg},
  { "����� ���5 �� ��",      (void*)&VidCompMTZ5, typeMenuProg},
  { "����� ���5 �� ��",      (void*)&VidCompMTZ5, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compMTZ5[] =
{
  { "������ ���5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ5, typeMenuList},//control_item, parent
  { "��� ���5",           (void*)&UprCompMTZ5, typeMenuProg},
  { "������ ���5",        (void*)&UprCompMTZ5, typeMenuProg},
  { "���5 ������",        (void*)&UprCompMTZ5, typeMenuProg},
  { "���5 �����",         (void*)&UprCompMTZ5, typeMenuProg},
  { "��������� ���5",     (void*)&UprCompMTZ5, typeMenuProg},
  { "���5 ����������",    (void*)&UprCompMTZ5, typeMenuProg},
  { "������� ��� ���5",   (void*)&UprCompMTZ5, typeMenuProg},
  { "��������� ���5",     (void*)&UprCompMTZ5, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompMTZ5(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_ust_compMTZ5);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp3()

void UstListCompMTZ5()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compMTZ5);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompMTZ5);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompMTZ5()

void UstCompMTZ5()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compMTZ5);
  PassWord(EditUstMTZ5);
}//VidCompMTZ5()

void EditUstMTZ5()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compMTZ5);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompMTZ5()

//--------------------------------------------------

void PereinitVidListCompMTZ5(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_vid_compMTZ5);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitVidListCompMTZ5(short flg)

void VidListCompMTZ5()
{
  SelectorMNGBAZA(MNGVID_MTZ2to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compMTZ5);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompMTZ5);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ5()

void VidCompMTZ5()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compMTZ5);
//  PassWord(EditVidAPV);
  EditVidMTZ5();
}//VidCompMTZ5()

void EditVidMTZ5()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compMTZ5);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompMTZ5(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compMTZ5, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompMTZ5()
{
  SelectorMNGBAZA(MNGUPR_MTZ2to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compMTZ5);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompMTZ5);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ5()

void UprCompMTZ5()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compMTZ5);
  PassWord(EditUprMTZ5);
}//VidCompMTZ5()

void EditUprMTZ5()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compMTZ5[LIGHTLINEMENU +1+SUBDATA].Line1;

  switch(LIGHTLINEMENU)
  {
    case 0: UpravlRedactorChooseMTZ(nameUpr, LIGHTLINEMENU);//������������� ������� ����������
    break;
    default:UpravlRedactor(nameUpr, LIGHTLINEMENU+1, &selectorUprStrMTZ2);//������������� ������� ����������
  }//switch

}//EditVidMTZ5()

short  KadrMenuFormat_upr_compMTZ5(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  short chooseBit = 2;//�-�� ��� � choose
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compMTZ5[i+1+SUBDATA].Line1;
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
}//KadrMenuFormat_upr_compMTZ5(WorkControl *workCntr)

int initUstMTZ5(char init)
{
 return initUstMTZ2(init);
/*
  //������� �������
  if (init)
  {
//������� ��������
    tmpUSTAVKI[MNGUST_MTZ2to5]     = 331;
    tmpUSTAVKI[MNGUST_MTZ2to5_V]   = 332;
    tmpUSTAVKI[MNGUST_MTZ2to5_N]   = 333;
    tmpUSTAVKI[MNGUST_MTZ2to5_PN]  = 334;
    tmpUSTAVKI[MNGUST_MTZ2to5_UPN] = 335;
//������� ��������
    tmpUSTAVKI[MNGVID_MTZ2to5]    = 251;
    tmpUSTAVKI[MNGVID_MTZ2to5_V]  = 262;
    tmpUSTAVKI[MNGVID_MTZ2to5_N]  = 273;
    tmpUSTAVKI[MNGVID_MTZ2to5_PN] = 284;
//���������
    tmpUSTAVKI[MNGUSK_MTZ2to5]    = 295;
    tmpUSTAVKI[MNGUSK_MTZ2to5_V]  = 306;
    tmpUSTAVKI[MNGUSK_MTZ2to5_N]  = 317;
    tmpUSTAVKI[MNGUSK_MTZ2to5_PN] = 328;
    tmpUSTAVKI[MNGVUSK_MTZ2to5]   = 339;
//������� ����������
    tmpUSTAVKI[MNGUPR_MTZ2to5] = 0;

  }//if

  IndexUstSPV += SPVUST_MTZ2to5_TOTAL;//������ ������� � �����������
  return MNGUST_MTZ2to5_TOTAL;//�-�� ������� � ��������� �������
*/
}//initUstMTZ1(short mngUst, char init)

void  prepareUstMTZ5(short idxC)
{
   prepareUstMTZ2(idxC);
}//prepareUstMTZ5(short idxC)

int codecUstMTZ5(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  return codecUstMTZ2(codec, offset, ust);
}//codecUstMTZ5(char *buf, short offset, int ust)

void diffMTZ5ToRepozitar()
{
//���������� ��������� ���������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  MTZ5_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_MTZ5;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_MTZ;   //�-�� ������
  rpzcomponent_obj.numClon     = 5;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstMTZ5;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstMTZ5;//���������� �������

  rpzcomponent_obj.nameStatusIO = ionsMTZ5;          //����� � ������ ������ IO

  rpzcomponent_obj.codecUst = codecUstMTZ5;   //����������-������������� �������

}//diffMTZ5ToRepozitar()

#endif // _HIDE_COMPONENT

