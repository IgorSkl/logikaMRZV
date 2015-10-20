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

void PereinitUstListCompMTZ4(short flg);
void UstListCompMTZ4();
void ustRedactorCompMTZ4();
void UstCompMTZ4();
short  KadrMenuFormat_ust_compMTZ4(void *workCntr);

void PereinitVidListCompMTZ4(short flg);
void VidListCompMTZ4();
void vidRedactorCompMTZ4();
void VidCompMTZ4();
short  KadrMenuFormat_vid_compMTZ4(void *workCntr);

void PereinitUprListCompMTZ4(short flg);
void UprListCompMTZ4();
void uprRedactorCompMTZ4();
void UprCompMTZ4();
short  KadrMenuFormat_upr_compMTZ4(void *workCntr);
int  initUstMTZ4(char init);
void  prepareUstMTZ2(short idxC);
void  prepareUstMTZ4(short idxC);

//int ViewerEditUstMTZ4();
//int ViewerEditVidMTZ4();
void EditUstMTZ4();
void EditVidMTZ4();
void EditUprMTZ4();
int codecUstMTZ4(char codec, short offset, int ust);
int codecUstMTZ2(char codec, short offset, int ust);
int initUstMTZ2(char init);

char *selectorUprStrMTZ2(short iBit, UNS_32 ustUpr);
void UpravlChooserMTZInKadr(char *nameUpr, short ibit, void *workCntr);
void UpravlRedactorChooseMTZ(char *nameUpr, short ibit);
short  KadrMenuFormat_ustvidMTZ(void *workCntr);

char MTZ4_TITLE[] = "���4";

IONAMESTATUS_COMPONENT ionsMTZ4[IOCMD_MTZ2to5_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ���4"
  },
  {
    1,//������ iocmd2
    "���� ��� ���4"
  },
  {
    1,//������ iocmd3
    "������ ��� ���4"
  },
  {
    1,//������ iocmd4
    "���� �� ���4"
  },
  {                 
    1,//������ iocmd5
    "���� �� ���4 ���"
  },
  {
    1,//������ iocmd6
    "���� �� ���4 ���"
  },
  {
    1,//������ iocmd7
    "���� �� ���4 ��"
  },
  {
    1,//������ iocmd8
    "���� ���4"
  },
  {
    1,//������ iocmd9
    "���� ��� ���4"
  },
  {
    1,//������ iocmd10
    "������ ���4 ���"
  },
  {
    1,//������ iocmd11
    "������ ���4 ���"
  }
};

LineMenuItem sub_menu_comp_MTZ4[8] =
{
  { MTZ4_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_MTZ, typeMenuSub},//control_item, parent
  { "������� ���4",    (void *)&UstListCompMTZ4, typeMenuProg},
  { "�������� ���4",   (void *)&VidListCompMTZ4, typeMenuProg},
  { "���������� ���4", (void *)&UprListCompMTZ4, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compMTZ4[] =
{
  { "������� ���4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ4, typeMenuList},//control_item, parent
  { "��� ���4",         (void*)&UstCompMTZ4, typeMenuProg},
  { "��� ���4 ������",  (void*)&UstCompMTZ4, typeMenuProg},
  { "��� ���4 �����",   (void*)&UstCompMTZ4, typeMenuProg},
  { "��� ���4 ��",      (void*)&UstCompMTZ4, typeMenuProg},
  { "��� ���� ���4 �H", (void*)&UstCompMTZ4, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compMTZ4[] =
{
  { "�������� ���4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ4, typeMenuList},//control_item, parent
/*
  { "�������� ���4",         (void*)&VidCompMTZ4, typeMenuProg},
  { "�������� ���4 ������",  (void*)&VidCompMTZ4, typeMenuProg},
  { "�������� ���4 �����",   (void*)&VidCompMTZ4, typeMenuProg},
  { "�������� ���4 ��",      (void*)&VidCompMTZ4, typeMenuProg},
  { "���� ����� ���4",       (void*)&VidCompMTZ4, typeMenuProg},

  { "����� ���4 ��",         (void*)&VidCompMTZ4, typeMenuProg},
  { "����� ���4 ��",         (void*)&VidCompMTZ4, typeMenuProg},
  { "����� ���4 ��",         (void*)&VidCompMTZ4, typeMenuProg},

  { "����� ���4 �� ���",     (void*)&VidCompMTZ4, typeMenuProg},
  { "����� ���4 �� ���",     (void*)&VidCompMTZ4, typeMenuProg},
  { "����� ���4 �� ���",     (void*)&VidCompMTZ4, typeMenuProg},

  { "����� ���4 �� ���",     (void*)&VidCompMTZ4, typeMenuProg},
  { "����� ���4 �� ���",     (void*)&VidCompMTZ4, typeMenuProg},
  { "����� ���4 �� ���",     (void*)&VidCompMTZ4, typeMenuProg},

  { "����� ���4 �� ��",      (void*)&VidCompMTZ4, typeMenuProg},
  { "����� ���4 �� ��",      (void*)&VidCompMTZ4, typeMenuProg},
  { "����� ���4 �� ��",      (void*)&VidCompMTZ4, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compMTZ4[] =
{
  { "������ ���4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ4, typeMenuList},//control_item, parent
  { "��� ���4",           (void*)&UprCompMTZ4, typeMenuProg},
  { "������ ���4",        (void*)&UprCompMTZ4, typeMenuProg},
  { "���4 ������",        (void*)&UprCompMTZ4, typeMenuProg},
  { "���4 �����",         (void*)&UprCompMTZ4, typeMenuProg},
  { "��������� ���4",     (void*)&UprCompMTZ4, typeMenuProg},
  { "���4 ����������",    (void*)&UprCompMTZ4, typeMenuProg},
  { "������� ��� ���4",   (void*)&UprCompMTZ4, typeMenuProg},
  { "��������� ���4",     (void*)&UprCompMTZ4, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompMTZ4(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_ust_compMTZ4);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp3()

void UstListCompMTZ4()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compMTZ4);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompMTZ4);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompMTZ4()

void UstCompMTZ4()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compMTZ4);
  PassWord(EditUstMTZ4);
}//VidCompMTZ4()

void EditUstMTZ4()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compMTZ4);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompMTZ4()

//--------------------------------------------------

void PereinitVidListCompMTZ4(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_vid_compMTZ4);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitVidListCompMTZ4(short flg)

void VidListCompMTZ4()
{
  SelectorMNGBAZA(MNGVID_MTZ2to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compMTZ4);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompMTZ4);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ4()

void VidCompMTZ4()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compMTZ4);
//  PassWord(EditVidAPV);
  EditVidMTZ4();
}//VidCompMTZ4()

void EditVidMTZ4()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compMTZ4);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompMTZ4(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compMTZ4, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompMTZ4()
{
  SelectorMNGBAZA(MNGUPR_MTZ2to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compMTZ4);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompMTZ4);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ4()

void UprCompMTZ4()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compMTZ4);
  PassWord(EditUprMTZ4);
}//VidCompMTZ4()

void EditUprMTZ4()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compMTZ4[LIGHTLINEMENU +1+SUBDATA].Line1;

  switch(LIGHTLINEMENU)
  {
    case 0: UpravlRedactorChooseMTZ(nameUpr, LIGHTLINEMENU);//������������� ������� ����������
    break;
    default:UpravlRedactor(nameUpr, LIGHTLINEMENU+1, &selectorUprStrMTZ2);//������������� ������� ����������
  }//switch

}//EditVidMTZ4()

short  KadrMenuFormat_upr_compMTZ4(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  short chooseBit = 2;//�-�� ��� � choose
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compMTZ4[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      if(i<(chooseBit-1))
        UpravlChooserMTZInKadr(nameUpr, i, workCntr);
      else
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
        selectorUprStrMTZ2(i+(chooseBit-1), getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compMTZ4(WorkControl *workCntr)

int initUstMTZ4(char init)
{
 return initUstMTZ2(init);
}//initUstMTZ1(short mngUst, char init)

void  prepareUstMTZ4(short idxC)
{
   prepareUstMTZ2(idxC);
}//prepareUstMTZ4(short idxC)

int codecUstMTZ4(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  return codecUstMTZ2(codec, offset, ust);
}//codecUstMTZ4(char *buf, short offset, int ust)

void diffMTZ4ToRepozitar()
{
//���������� ��������� ���������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  MTZ4_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_MTZ4;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_MTZ;   //�-�� ������
  rpzcomponent_obj.numClon     = 4;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstMTZ4;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstMTZ4;//���������� �������

  rpzcomponent_obj.nameStatusIO = ionsMTZ4;          //����� � ������ ������ IO
}//diffMTZ4ToRepozitar()

#endif // _HIDE_COMPONENT

