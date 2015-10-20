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
#include "logictimers\logictimersfnc.h"

#include "virtualMenu\viewMenuList.h"

#include "psupervisor\psupervisor.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"

//��� �����������
#define KOD_COMPONENT  OF_COMP1

#endif // _HIDE_COMPONENT

//������������� �������  � ��������� �������
//������� ��������
#define MNGPAUSA_OF1    0
#define MNGPAUSA_OF2    1
#define MNGPAUSA_OF3    2
#define MNGPAUSA_OF4    3
#define MNGPAUSA_OF5    4
#define MNGPAUSA_OF6    5
#define MNGPAUSA_OF7    6
#define MNGPAUSA_OF8    7
#define MNGPAUSA_OF9    8
#define MNGPAUSA_OF10   9
#define MNGPAUSA_OF11   10
#define MNGPAUSA_OF12   11
#define MNGPAUSA_OF13   12
#define MNGPAUSA_OF14   13
#define MNGPAUSA_OF15   14
#define MNGPAUSA_OF16   15

#define MNGWORK_OF1     16
#define MNGWORK_OF2     17
#define MNGWORK_OF3     18
#define MNGWORK_OF4     19
#define MNGWORK_OF5     20
#define MNGWORK_OF6     21
#define MNGWORK_OF7     22
#define MNGWORK_OF8     23
#define MNGWORK_OF9     24
#define MNGWORK_OF10    25
#define MNGWORK_OF11    26
#define MNGWORK_OF12    27
#define MNGWORK_OF13    28
#define MNGWORK_OF14    29
#define MNGWORK_OF15    30
#define MNGWORK_OF16    31

//������� ����������
#define MNGUPR_OF       32
//�-�� ������� � ��������� �������
#define MNGUST_OF_TOTAL  33

//������������� ENA ������
#define ENA_OF_1  0
#define ENA_OF_2  1
#define ENA_OF_3  2
#define ENA_OF_4  3
#define ENA_OF_5  4
#define ENA_OF_6  5
#define ENA_OF_7  6
#define ENA_OF_8  7
#define ENA_OF_9  8
#define ENA_OF_10 9
#define ENA_OF_11 10
#define ENA_OF_12 11
#define ENA_OF_13 12
#define ENA_OF_14 13
#define ENA_OF_15 14
#define ENA_OF_16 15
//�-�� ENA ������
#define ENACMD_OF_TOTAL 16

//������������� ������� � �����������
//�-�� ������� � �����������
#define SPVUST_OF_TOTAL  0

//---------------IO COMMAND------------------
//������������� IO ������ ��� OF
//��1
#define IOCMD_IN_OF1  0
#define IOCMD_OUT_OF1 1
//��2
#define IOCMD_IN_OF2  2
#define IOCMD_OUT_OF2 3
//��3
#define IOCMD_IN_OF3  4
#define IOCMD_OUT_OF3 5
//��4
#define IOCMD_IN_OF4  6
#define IOCMD_OUT_OF4 7
//��5
#define IOCMD_IN_OF5  8
#define IOCMD_OUT_OF5 9
//��6
#define IOCMD_IN_OF6  10
#define IOCMD_OUT_OF6 11
//��7
#define IOCMD_IN_OF7  12
#define IOCMD_OUT_OF7 13
//��8
#define IOCMD_IN_OF8  14
#define IOCMD_OUT_OF8 15
//��9
#define IOCMD_IN_OF9  16
#define IOCMD_OUT_OF9 17
//��10
#define IOCMD_IN_OF10  18
#define IOCMD_OUT_OF10 19
//��11
#define IOCMD_IN_OF11  20
#define IOCMD_OUT_OF11 21
//��12
#define IOCMD_IN_OF12  22
#define IOCMD_OUT_OF12 23
//��13
#define IOCMD_IN_OF13  24
#define IOCMD_OUT_OF13 25
//��14
#define IOCMD_IN_OF14  26
#define IOCMD_OUT_OF14 27
//��15
#define IOCMD_IN_OF15  28
#define IOCMD_OUT_OF15 29
//��16
#define IOCMD_IN_OF16  30
#define IOCMD_OUT_OF16 31

//�T1
#define IOCMD_BKL_OT1  32
#define IOCMD_OTKL_OT1 33
#define IOCMD_OUT_OT1  34
//�T2
#define IOCMD_BKL_OT2  35
#define IOCMD_OTKL_OT2 36
#define IOCMD_OUT_OT2  37
//�T3
#define IOCMD_BKL_OT3  38
#define IOCMD_OTKL_OT3 39
#define IOCMD_OUT_OT3  40
//�T4
#define IOCMD_BKL_OT4  41
#define IOCMD_OTKL_OT4 42
#define IOCMD_OUT_OT4  43
//�T5
#define IOCMD_BKL_OT5  44
#define IOCMD_OTKL_OT5 45
#define IOCMD_OUT_OT5  46
//�T6
#define IOCMD_BKL_OT6  47
#define IOCMD_OTKL_OT6 48
#define IOCMD_OUT_OT6  49
//�T7
#define IOCMD_BKL_OT7  50
#define IOCMD_OTKL_OT7 51
#define IOCMD_OUT_OT7  52
//�T8
#define IOCMD_BKL_OT8  53
#define IOCMD_OTKL_OT8 54
#define IOCMD_OUT_OT8  55

//�-�� IO ������
#define IOCMD_OF_TOTAL    56

//---------------TL COMMAND------------------
//������������� TL ������ ��� OF
//�-�� TL ������
#define TLCMD_OF_TOTAL    0

//--------------- TIMERS ------------------
//������������� �������� ��� OF
//������ ����� ��1
#define TIMERP_OF1  0
//������ ������ ��1
#define TIMERR_OF1  1
//������ ����� ��2
#define TIMERP_OF2  2
//������ ������ ��2
#define TIMERR_OF2  3
//������ ����� ��3
#define TIMERP_OF3  4
//������ ������ ��3
#define TIMERR_OF3  5
//������ ����� ��4
#define TIMERP_OF4  6
//������ ������ ��4
#define TIMERR_OF4  7
//������ ����� ��5
#define TIMERP_OF5  8
//������ ������ ��5
#define TIMERR_OF5  9
//������ ����� ��6
#define TIMERP_OF6  10
//������ ������ ��6
#define TIMERR_OF6  11
//������ ����� ��7
#define TIMERP_OF7  12
//������ ������ ��7
#define TIMERR_OF7  13
//������ ����� ��8
#define TIMERP_OF8  14
//������ ������ ��8
#define TIMERR_OF8  15
//������ ����� ��9
#define TIMERP_OF9  16
//������ ������ ��9
#define TIMERR_OF9  17
//������ ����� ��10
#define TIMERP_OF10  18
//������ ������ ��10
#define TIMERR_OF10  19
//������ ����� ��11
#define TIMERP_OF11  20
//������ ������ ��11
#define TIMERR_OF11  21
//������ ����� ��12
#define TIMERP_OF12  22
//������ ������ ��12
#define TIMERR_OF12  23
//������ ����� ��13
#define TIMERP_OF13  24
//������ ������ ��13
#define TIMERR_OF13  25
//������ ����� ��14
#define TIMERP_OF14  26
//������ ������ ��14
#define TIMERR_OF14  27
//������ ����� ��15
#define TIMERP_OF15  28
//������ ������ ��15
#define TIMERR_OF15  29
//������ ����� ��16
#define TIMERP_OF16  30
//������ ������ ��16
#define TIMERR_OF16  31
//�-�� ��������
#define TIMERS_OF_TOTAL   32

#ifndef _HIDE_COMPONENT

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������
extern int  IndexIO;//������ IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//������� ������� �����������
extern char *bitStringUNI[];
extern int  timerEnableWL;//���������� ������ �������� ��

void PereinitUstListCompOF(short flg);
void UstListCompOF();
void ustRedactorCompOF();
void UstCompOF();
short  KadrMenuFormat_ust_compOF(void *workCntr);

void PereinitUprListCompOF(short flg);
void UprListCompOF();
void uprRedactorCompOF();
void UprCompOF();
short  KadrMenuFormat_upr_compOF(void *workCntr);
int  initUstOF(char init);
void  prepareUstOF(short idxC);

//int ViewerEditUstOF();
//int ViewerEditVidOF();
void EditUstOF();
//void EditVidOF();
void EditUprOF();
int codecUstOF(char codec, short offset, int ust);
int   isDISactiv_OF(int idxC);
void  logicOF(int idxC);

char *selectorUprStrOF(short iBit, UNS_32 ustUpr);

int  offsetIOCmdOF;//�������� ��� IO OF
int  offsetIOCmdOF_loc;//�������� ��� IO OF

IONAMESTATUS_COMPONENT ionsOF[IOCMD_OF_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� �-������� 1"
  },
  {
    1,//������ iocmd1
    "��� �-������� 1"
  },
  {
    1,//������ iocmd1
    "���� �-������� 2"
  },
  {
    1,//������ iocmd1
    "��� �-������� 2"
  },
  {
    1,//������ iocmd1
    "���� �-������� 3"
  },
  {
    1,//������ iocmd1
    "��� �-������� 3"
  },
  {
    1,//������ iocmd1
    "���� �-������� 4"
  },
  {
    1,//������ iocmd1
    "��� �-������� 4"
  },
  {
    1,//������ iocmd1
    "���� �-������� 5"
  },
  {
    1,//������ iocmd1
    "��� �-������� 5"
  },
  {
    1,//������ iocmd1
    "���� �-������� 6"
  },
  {
    1,//������ iocmd1
    "��� �-������� 6"
  },
  {
    1,//������ iocmd1
    "���� �-������� 7"
  },
  {
    1,//������ iocmd1
    "��� �-������� 7"
  },
  {
    1,//������ iocmd1
    "���� �-������� 8"
  },
  {
    1,//������ iocmd1
    "��� �-������� 8"
  },
  {
    1,//������ iocmd1
    "���� �-������� 9"
  },
  {
    1,//������ iocmd1
    "��� �-������� 9"
  },
  {
    1,//������ iocmd1
    "���� �-������� 10"
  },
  {
    1,//������ iocmd1
    "��� �-������� 10"
  },
  {
    1,//������ iocmd1
    "���� �-������� 11"
  },
  {
    1,//������ iocmd1
    "��� �-������� 11"
  },
  {
    1,//������ iocmd1
    "���� �-������� 12"
  },
  {
    1,//������ iocmd1
    "��� �-������� 12"
  },
  {
    1,//������ iocmd1
    "���� �-������� 13"
  },
  {
    1,//������ iocmd1
    "��� �-������� 13"
  },
  {
    1,//������ iocmd1
    "���� �-������� 14"
  },
  {
    1,//������ iocmd1
    "��� �-������� 14"
  },
  {
    1,//������ iocmd1
    "���� �-������� 15"
  },
  {
    1,//������ iocmd1
    "��� �-������� 15"
  },
  {
    1,//������ iocmd1
    "���� �-������� 16"
  },
  {
    1,//������ iocmd1
    "��� �-������� 16"
  },

  {
    1,//������ iocmd1
    "��� �-������� 1"
  },
  {
    1,//������ iocmd1
    "���� �-������� 1"
  },
  {
    1,//������ iocmd1
    "��� �-������� 1"
  },
  {
    1,//������ iocmd1
    "��� �-������� 2"
  },
  {
    1,//������ iocmd1
    "���� �-������� 2"
  },
  {
    1,//������ iocmd1
    "��� �-������� 2"
  },
  {
    1,//������ iocmd1
    "��� �-������� 3"
  },
  {
    1,//������ iocmd1
    "���� �-������� 3"
  },
  {
    1,//������ iocmd1
    "��� �-������� 3"
  },
  {
    1,//������ iocmd1
    "��� �-������� 4"
  },
  {
    1,//������ iocmd1
    "���� �-������� 4"
  },
  {
    1,//������ iocmd1
    "��� �-������� 4"
  },
  {
    1,//������ iocmd1
    "��� �-������� 5"
  },
  {
    1,//������ iocmd1
    "���� �-������� 5"
  },
  {
    1,//������ iocmd1
    "��� �-������� 5"
  },
  {
    1,//������ iocmd1
    "��� �-������� 6"
  },
  {
    1,//������ iocmd1
    "���� �-������� 6"
  },
  {
    1,//������ iocmd1
    "��� �-������� 6"
  },
  {
    1,//������ iocmd1
    "��� �-������� 7"
  },
  {
    1,//������ iocmd1
    "���� �-������� 7"
  },
  {
    1,//������ iocmd1
    "��� �-������� 7"
  },
  {
    1,//������ iocmd1
    "��� �-������� 8"
  },
  {
    1,//������ iocmd1
    "���� �-������� 8"
  },
  {
    1,//������ iocmd1
    "��� �-������� 8"
  },
};

LineMenuItem sub_menu_comp_OF[8] =
{
  { "����� �������", NULL},//title
  { &CONTROL1_COMP, &sub_menu_cnf, typeMenuSub},//control_item, parent
  { "������� ��",    (void *)&UstListCompOF, typeMenuProg},
  { "���������� ��", (void *)&UprListCompOF, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compOF[] =
{
  { "������� ����� �������", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_OF, typeMenuList},//control_item, parent
/*
  { "������ ����� ��1",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��1", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��2",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��2", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��3",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��3", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��4",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��4", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��5",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��5", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��6",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��6", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��7",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��7", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��8",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��8", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��9",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��9", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��10",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��10", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��11",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��11", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��12",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��12", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��13",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��13", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��14",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��14", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��15",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��15", (void *)&UstCompOF, typeMenuProg},
  { "������ ����� ��16",  (void *)&UstCompOF, typeMenuProg},
  { "������ ������ ��16", (void *)&UstCompOF, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compOF[] =
{
  { "������ ����� �������", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_OF, typeMenuList},//control_item, parent
/*
  { "��� ��1",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��2",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��3",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��4",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��5",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��6",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��7",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��8",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��9",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��10",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��11",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��12",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��13",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��14",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��15",  (void *)&UprCompOF, typeMenuProg},
  { "��� ��16",  (void *)&UprCompOF, typeMenuProg},
*/
  { NULL, NULL}

};

void PereinitUstListCompOF(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ust_compOF, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UstListCompOF()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compOF);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompOF);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompOF()

void UstCompOF()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compOF);
  PassWord(EditUstOF);
}//VidCompOF()

void EditUstOF()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compOF);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompOF()

short  KadrMenuFormat_ust_compOF(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  char locTxt[50];
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    if(sub_menu_ust_compOF[i+1+SUBDATA].Line1==NULL)break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, (char *)sub_menu_ust_compOF[i+1+SUBDATA].Line1);
      sprintf(locTxt, "   %d", getUstOffsetMngUSTAVKI(i));
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_ust_compOF(void *pstr)

//--------------------------------------------------

void PereinitUprListCompOF(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compOF, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompOF()
{
  SelectorMNGBAZA(MNGUPR_OF);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compOF);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompOF);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompOF()

void UprCompOF()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compOF);
  PassWord(EditUprOF);

}//UprCompOF()

void EditUprOF()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compOF[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrOF);//������������� ������� ����������
}//EditUprOF()

short  KadrMenuFormat_upr_compOF(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compOF[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrOF(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compOF(WorkControl *workCntr)

char *selectorUprStrOF(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_OBRAT];
    return bitStringUNI[UNIUPR_PRJAM];
}//selectorUprStrOF(short ibit, UNS_32 ustUpr)

int initUstOF(char init)
{
  //������� �������
  if (init)
  {
//OF1
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF1] = 41;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF1] = 45;
//OF2
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF2] = 42;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF2] = 46;
//OF3
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF3] = 43;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF3] = 47;
//OF4
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF4] = 44;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF4] = 48;
//OF5
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF5] = 45;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF5] = 49;
//OF6
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF6] = 46;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF6] = 50;
//OF7
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF7] = 47;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF7] = 51;
//OF8
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF8] = 48;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF8] = 52;
//OF9
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF9] = 49;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF9] = 53;
//OF10
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF10] = 50;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF10] = 54;
//OF11
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF11] = 51;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF11] = 55;
//OF12
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF12] = 52;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF12] = 56;
//OF13
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF13] = 53;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF13] = 57;
//OF14
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF14] = 54;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF14] = 58;
//OF15
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF15] = 55;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF15] = 59;
//OF16
    //������ �����
    tmpUSTAVKI[MNGPAUSA_OF16] = 56;
    //������ ������
    tmpUSTAVKI[MNGWORK_OF16] = 60;

//������� ����������
    tmpUSTAVKI[MNGUPR_OF] = 0;
  }//if

  IndexUstSPV += SPVUST_OF_TOTAL;//������ ������� � �����������
  return MNGUST_OF_TOTAL;//�-�� ������� � ��������� �������
}//initUstOF(short mngUst, char init)

void  prepareUstOF(short idxC)
{
  //���������� ENA ������ ��� �����
  if(idxC>=0){
  //���������� ENA �� WideENA � ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_OF), ENACMD_OF_TOTAL);
  //���������� �������
  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //��������� � ������������

//OF1
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF1,
          codecUstOF(1, MNGPAUSA_OF1, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF1)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF1,
          codecUstOF(1, MNGWORK_OF1, getNativUstMngUSTAVKI(idxC, MNGWORK_OF1)));
//OF2
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF2,
          codecUstOF(1, MNGPAUSA_OF2, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF2)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF2,
          codecUstOF(1, MNGWORK_OF2, getNativUstMngUSTAVKI(idxC, MNGWORK_OF2)));
//OF3
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF3,
          codecUstOF(1, MNGPAUSA_OF3, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF3)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF3,
          codecUstOF(1, MNGWORK_OF3, getNativUstMngUSTAVKI(idxC, MNGWORK_OF3)));
//OF4
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF4,
          codecUstOF(1, MNGPAUSA_OF4, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF4)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF4,
          codecUstOF(1, MNGWORK_OF4, getNativUstMngUSTAVKI(idxC, MNGWORK_OF4)));
//OF5
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF5,
          codecUstOF(1, MNGPAUSA_OF5, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF5)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF5,
          codecUstOF(1, MNGWORK_OF5, getNativUstMngUSTAVKI(idxC, MNGWORK_OF5)));
//OF6
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF6,
          codecUstOF(1, MNGPAUSA_OF6, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF6)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF6,
          codecUstOF(1, MNGWORK_OF6, getNativUstMngUSTAVKI(idxC, MNGWORK_OF6)));
//OF7
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF7,
          codecUstOF(1, MNGPAUSA_OF7, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF7)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF7,
          codecUstOF(1, MNGWORK_OF7, getNativUstMngUSTAVKI(idxC, MNGWORK_OF7)));
//OF8
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF8,
          codecUstOF(1, MNGPAUSA_OF8, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF8)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF8,
          codecUstOF(1, MNGWORK_OF8, getNativUstMngUSTAVKI(idxC, MNGWORK_OF8)));
//OF9
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF9,
          codecUstOF(1, MNGPAUSA_OF9, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF9)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF9,
          codecUstOF(1, MNGWORK_OF9, getNativUstMngUSTAVKI(idxC, MNGWORK_OF9)));
//OF10
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF10,
          codecUstOF(1, MNGPAUSA_OF10, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF10)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF10,
          codecUstOF(1, MNGWORK_OF10, getNativUstMngUSTAVKI(idxC, MNGWORK_OF10)));
//OF11
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF11,
          codecUstOF(1, MNGPAUSA_OF11, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF11)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF11,
          codecUstOF(1, MNGWORK_OF11, getNativUstMngUSTAVKI(idxC, MNGWORK_OF11)));
//OF12
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF12,
          codecUstOF(1, MNGPAUSA_OF12, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF12)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF12,
          codecUstOF(1, MNGWORK_OF12, getNativUstMngUSTAVKI(idxC, MNGWORK_OF12)));
//OF13
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF13,
          codecUstOF(1, MNGPAUSA_OF13, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF13)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF13,
          codecUstOF(1, MNGWORK_OF13, getNativUstMngUSTAVKI(idxC, MNGWORK_OF13)));
//OF14
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF14,
          codecUstOF(1, MNGPAUSA_OF14, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF14)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF14,
          codecUstOF(1, MNGWORK_OF14, getNativUstMngUSTAVKI(idxC, MNGWORK_OF14)));
//OF15
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF15,
          codecUstOF(1, MNGPAUSA_OF15, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF15)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF15,
          codecUstOF(1, MNGWORK_OF15, getNativUstMngUSTAVKI(idxC, MNGWORK_OF15)));
//OF16
    //������ �����
   setTimerPorog(tmpOffsetT+ TIMERP_OF16,
          codecUstOF(1, MNGPAUSA_OF16, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF16)));
    //������ ������
   setTimerPorog(tmpOffsetT+ TIMERR_OF16,
          codecUstOF(1, MNGWORK_OF16, getNativUstMngUSTAVKI(idxC, MNGWORK_OF16)));
  }//if
  else{
  //���������� ENA ������ ��� ����� ��
  //���������� ENA �� WideENA � ENAcmd
  CopyWideENAToENAcmd_WL(PrepareENACmd(idxC, MNGUPR_OF), ENACMD_OF_TOTAL);
  //���������� �������
  short tmpOffsetT    =
    getOffsetTimersCnf_WL(idxC);   //��������� � ������������

//OF1
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF1,
          codecUstOF(1, MNGPAUSA_OF1, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF1)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF1,
          codecUstOF(1, MNGWORK_OF1, getNativUstMngUSTAVKI(idxC, MNGWORK_OF1)));
//OF2
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF2,
          codecUstOF(1, MNGPAUSA_OF2, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF2)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF2,
          codecUstOF(1, MNGWORK_OF2, getNativUstMngUSTAVKI(idxC, MNGWORK_OF2)));
//OF3
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF3,
          codecUstOF(1, MNGPAUSA_OF3, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF3)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF3,
          codecUstOF(1, MNGWORK_OF3, getNativUstMngUSTAVKI(idxC, MNGWORK_OF3)));
//OF4
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF4,
          codecUstOF(1, MNGPAUSA_OF4, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF4)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF4,
          codecUstOF(1, MNGWORK_OF4, getNativUstMngUSTAVKI(idxC, MNGWORK_OF4)));
//OF5
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF5,
          codecUstOF(1, MNGPAUSA_OF5, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF5)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF5,
          codecUstOF(1, MNGWORK_OF5, getNativUstMngUSTAVKI(idxC, MNGWORK_OF5)));
//OF6
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF6,
          codecUstOF(1, MNGPAUSA_OF6, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF6)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF6,
          codecUstOF(1, MNGWORK_OF6, getNativUstMngUSTAVKI(idxC, MNGWORK_OF6)));
//OF7
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF7,
          codecUstOF(1, MNGPAUSA_OF7, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF7)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF7,
          codecUstOF(1, MNGWORK_OF7, getNativUstMngUSTAVKI(idxC, MNGWORK_OF7)));
//OF8
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF8,
          codecUstOF(1, MNGPAUSA_OF8, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF8)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF8,
          codecUstOF(1, MNGWORK_OF8, getNativUstMngUSTAVKI(idxC, MNGWORK_OF8)));
//OF9
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF9,
          codecUstOF(1, MNGPAUSA_OF9, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF9)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF9,
          codecUstOF(1, MNGWORK_OF9, getNativUstMngUSTAVKI(idxC, MNGWORK_OF9)));
//OF10
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF10,
          codecUstOF(1, MNGPAUSA_OF10, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF10)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF10,
          codecUstOF(1, MNGWORK_OF10, getNativUstMngUSTAVKI(idxC, MNGWORK_OF10)));
//OF11
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF11,
          codecUstOF(1, MNGPAUSA_OF11, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF11)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF11,
          codecUstOF(1, MNGWORK_OF11, getNativUstMngUSTAVKI(idxC, MNGWORK_OF11)));
//OF12
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF12,
          codecUstOF(1, MNGPAUSA_OF12, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF12)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF12,
          codecUstOF(1, MNGWORK_OF12, getNativUstMngUSTAVKI(idxC, MNGWORK_OF12)));
//OF13
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF13,
          codecUstOF(1, MNGPAUSA_OF13, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF13)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF13,
          codecUstOF(1, MNGWORK_OF13, getNativUstMngUSTAVKI(idxC, MNGWORK_OF13)));
//OF14
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF14,
          codecUstOF(1, MNGPAUSA_OF14, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF14)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF14,
          codecUstOF(1, MNGWORK_OF14, getNativUstMngUSTAVKI(idxC, MNGWORK_OF14)));
//OF15
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF15,
          codecUstOF(1, MNGPAUSA_OF15, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF15)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF15,
          codecUstOF(1, MNGWORK_OF15, getNativUstMngUSTAVKI(idxC, MNGWORK_OF15)));
//OF16
    //������ �����
   setTimerPorog_WL(tmpOffsetT+ TIMERP_OF16,
          codecUstOF(1, MNGPAUSA_OF16, getNativUstMngUSTAVKI(idxC, MNGPAUSA_OF16)));
    //������ ������
   setTimerPorog_WL(tmpOffsetT+ TIMERR_OF16,
          codecUstOF(1, MNGWORK_OF16, getNativUstMngUSTAVKI(idxC, MNGWORK_OF16)));
   }//else WL
}//prepareUstMTZ2(short idxC)

int initIOCmd_OF()
{
  //������� IO ������
  offsetIOCmdOF_loc = IndexIO;//�������� ��� IO OF
  return commonInitIOCmd(IOCMD_OF_TOTAL);
}

int initTLCmd_OF()
{
  //������� TL ������
  return commonInitTLCmd(TLCMD_OF_TOTAL);
}//initTLCmd_OF()

int initENACmd_OF()
{
  //������� ENA ������
  return commonInitENACmd(ENACMD_OF_TOTAL);
}//initENACmd_OF()

void initTimersOF(short idxC)
{
  //������ � ������� ��������
  if(idxC>=0)
   commonInitTimers(TIMERS_OF_TOTAL);
  else {
   commonInitTimers_WL(TIMERS_OF_TOTAL);
   timerEnableWL = 1;//���������� ������ �������� ��
       }
}//initTimersOF()

int codecUstOF(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  if(codec) return ust*1;
  return ust/1;
}//codecUstOF(char *buf, short offset, int ust)

int isDISactiv_OF(int idxC)
{
 //���������� ������������ ���
  return 0;//��� ����������
}//isDISactiv_OF(int idxC)

char copyOFToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//������� ������
//���������� ��������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.packet = 0;    //����� ��������� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  "��");       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_OF;//���� ����������

  rpzcomponent_obj.cntClon    = 5;   //max �-�� ������

  rpzcomponent_obj.initUstMng    = initUstOF;    //������� �������
  rpzcomponent_obj.prepareUstSpv = prepareUstOF;//���������� �������
  rpzcomponent_obj.initIOCmd     = initIOCmd_OF;      //������� IO ������
  rpzcomponent_obj.initTLCmd     = initTLCmd_OF;      //������� TL ������
  rpzcomponent_obj.initENACmd    = initENACmd_OF;     //������� ENA ������
  rpzcomponent_obj.bo_bvCmd       = NULL; //��������� �� �� ������
  rpzcomponent_obj.isDISactiv     = isDISactiv_OF; //���������� ������������ ���
  rpzcomponent_obj.setBOBVtimer   = NULL; //������� �������� �� ��

  rpzcomponent_obj.nameStatusIO = ionsOF;          //����� � ������ ������ IO
  rpzcomponent_obj.initTimers   = initTimersOF;    //������ � ������� ��������
  rpzcomponent_obj.logic        = logicOF;         //������ ����������

  rpzcomponent_obj.codecUst = codecUstOF;   //����������-������������� �������

  return 0;//�� �������� �����������
}//

#endif // _HIDE_COMPONENT

