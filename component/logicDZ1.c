
#include <stdio.h>
#include <string.h>

#include "bazisdef.h"
#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "logictimers\logictimersmac.h"

#include "logictimers\logictimersfnc.h"

#include "..\bazis.h"

#include "zonaVRT\zonaVRTdef.h"
#include "zonaVRT\zonaVRTfnc.h"

#include "toSpeedOptim.h"

#define _HIDE_COMPONENT
#include "PRM1Component.c"
#include "DZ1Component.c"
#include "DZ2Component.c"

extern int GlobalPO1;
extern int GlobalPO2;
extern int GlobalPO3;
extern int GlobalPO4;
extern int GlobalLevel_UCM;
extern int GlobalLevel_ICM;
extern int GlobalLevelI_ABC[];

extern COMPONENT_OBJ  cnfCOMPONENT[];//������������
extern int  logMassTimer[];
extern int  ENAcmd[];
extern int  spvUSTAVKI[];//������� ������� �����������
extern int   tempLog[];
extern int   WideCmdRTBuffer[];
//������������� ����� ����
//extern int  isFAILU_COMMON_DZ;
extern int  isFAILU_DZ;
extern int  offsetIOCmdDZ5;//�������� ��� IO DZ5
extern int offsetENACmdPRM1;//�������� ��� ENA PRM1
extern int offsetSPVCmdPRM1;//�������� ��� SPV PRM1
extern int offsetIOCmdPRM1;//�������� ��� IO PRM1

extern int  spvUSTAVKI[];//������� ������� �����������

extern INT_64 koordXZ_64;//=353534;//125001;//160697;//250000;
extern INT_64 koordYZ_64;//=421325;//216507;//191512;//0;
//����������� �������������
extern INT_64 resistance_fA0X1, resistance_fA0Y1;
extern INT_64 resistance_fB0X1, resistance_fB0Y1;
extern INT_64 resistance_fC0X1, resistance_fC0Y1;
extern INT_64 resistance_fAMX, resistance_fAMY;
extern INT_64 resistance_fBMX, resistance_fBMY;
extern INT_64 resistance_fCMX, resistance_fCMY;
extern int isValidZonaDZ1OF;//���� ���������� ����
extern int isValidZonaDZ1MF;//���� ���������� ����
extern int isTriangleZonaBD[];//���� �� �����������-���������������

extern int flag_max_monitoring;//���� ��������� ��������

void  logicDZ1(int idxC) @ "Fast_function"
{
//������ ����������
    int tmpOffsetT    =
                cnfCOMPONENT[idxC].offsetTimers;   //������� ���������� � ������������
    int tmpOffsetIO   =
                cnfCOMPONENT[idxC].offsetIOCmd;    //IO �������
    int tmpOffsetENA  =
                cnfCOMPONENT[idxC].offsetENACmd;    //ENA �������
    int tmpOffsetUSpv =
                cnfCOMPONENT[idxC].offsetUstSpv;    //������� SPV
    int tmpOffsetTL   =
                cnfCOMPONENT[idxC].offsetTLCmd;    //TL �������

//����
  detectorLevelUP3F(GlobalLevelI_ABC,
                                     tmpOffsetUSpv+SPVSRAB_DZ1_MTZ,
                                     tmpOffsetUSpv+SPVVOZV_DZ1_MTZ,
                                     tmpOffsetUSpv+SPV_OUTA_DZ1_MTZ);

//��������� Z � ����  DZ1
  //----------OF
int LocalPO_DZ1OF = 0;
if(isTriangleZonaBD[0]){
//�����������
  koordXZ_64=resistance_fA0X1; koordYZ_64=resistance_fA0Y1;
int LocalPO_DZ1OFA = isViewZTrianMethod_64VRT( 0, ISZ_DZ1OFA);//&
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_I005)^1);
  koordXZ_64=resistance_fB0X1; koordYZ_64=resistance_fB0Y1;
int LocalPO_DZ1OFB = isViewZTrianMethod_64VRT( 0, ISZ_DZ1OFB);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_I005)^1);
  koordXZ_64=resistance_fC0X1; koordYZ_64=resistance_fC0Y1;
int LocalPO_DZ1OFC = isViewZTrianMethod_64VRT( 0, ISZ_DZ1OFC);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_I005)^1);
    LocalPO_DZ1OF = LocalPO_DZ1OFA | LocalPO_DZ1OFB | LocalPO_DZ1OFC;
 if(isValidZonaDZ1OF) LocalPO_DZ1OF = 0;//���� ���������� ����
                     }//if(isTriangleZonaBD[0])
else {
  koordXZ_64=resistance_fA0X1; koordYZ_64=resistance_fA0Y1;
int LocalPO_DZ1OFA = isViewZMethod_64VRT( 0, ISZ_DZ1OFA);//&
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_I005)^1);
  koordXZ_64=resistance_fB0X1; koordYZ_64=resistance_fB0Y1;
int LocalPO_DZ1OFB = isViewZMethod_64VRT( 0, ISZ_DZ1OFB);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_I005)^1);
  koordXZ_64=resistance_fC0X1; koordYZ_64=resistance_fC0Y1;
int LocalPO_DZ1OFC = isViewZMethod_64VRT( 0, ISZ_DZ1OFC);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_I005)^1);
    LocalPO_DZ1OF = LocalPO_DZ1OFA | LocalPO_DZ1OFB | LocalPO_DZ1OFC;
 if(isValidZonaDZ1OF) LocalPO_DZ1OF = 0;//���� ���������� ����
}//else

  //----------MF
int LocalPO_DZ1MF = 0;
if(isTriangleZonaBD[1]){
//�����������
  koordXZ_64=resistance_fAMX; koordYZ_64=resistance_fAMY;
int LocalPO_DZ1MFA = isViewZTrianMethod_64VRT( 1, ISZ_DZ1MFA);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_I005)^1);
  koordXZ_64=resistance_fBMX; koordYZ_64=resistance_fBMY;
int LocalPO_DZ1MFB = isViewZTrianMethod_64VRT( 1, ISZ_DZ1MFB);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_I005)^1);
  koordXZ_64=resistance_fCMX; koordYZ_64=resistance_fCMY;
int LocalPO_DZ1MFC = isViewZTrianMethod_64VRT( 1, ISZ_DZ1MFC);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_I005)^1);
    LocalPO_DZ1MF = LocalPO_DZ1MFA | LocalPO_DZ1MFB | LocalPO_DZ1MFC;
    if(isValidZonaDZ1MF) LocalPO_DZ1MF=0;//���� ���������� ����
                     }//if(isTriangleZonaBD[0])
else {
  koordXZ_64=resistance_fAMX; koordYZ_64=resistance_fAMY;
int LocalPO_DZ1MFA = isViewZMethod_64VRT( 1, ISZ_DZ1MFA);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_I005)^1);
  koordXZ_64=resistance_fBMX; koordYZ_64=resistance_fBMY;
int LocalPO_DZ1MFB = isViewZMethod_64VRT( 1, ISZ_DZ1MFB);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_I005)^1);
  koordXZ_64=resistance_fCMX; koordYZ_64=resistance_fCMY;
int LocalPO_DZ1MFC = isViewZMethod_64VRT( 1, ISZ_DZ1MFC);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_I005)^1);
    LocalPO_DZ1MF = LocalPO_DZ1MFA | LocalPO_DZ1MFB | LocalPO_DZ1MFC;
    if(isValidZonaDZ1MF) LocalPO_DZ1MF=0;//���� ���������� ����
}//else

  int LocalPO_MDZ1MF = 
                         SPV_UST(SPV_OUTA_DZ1_MTZ) |
                         SPV_UST(SPV_OUTB_DZ1_MTZ) |
                         SPV_UST(SPV_OUTC_DZ1_MTZ); 

  //*******DZ1********
  int commonDZ1 =
    //CMD1_DZ1
    (IO_LOGIC(IOCMD1_DZ1)^1) &
    ENA_LOGIC(ENA_DZ1_1);// ENA_DZ1;

    //L1 DZ1
   int locPO_DZ1MF = 
        commonDZ1 &
        //�� ��1
        (GlobalPO1 | LocalPO_DZ1MF) &
        //ELOUTTRG_NCN_DZ1MF
        (TL_LOGIC(TLCMDOUTNCN_DZ1MF)^1);

    //L2 DZ1
   int locPO_MDZ1MF = 
        commonDZ1 &
        ENA_LOGIC(ENA_DZ1_2) &// ENA_DZ1;
        //�� ��� ��1��
        (GlobalPO2 | LocalPO_MDZ1MF) &
        //ELOUTTRG_NCN_MDZ1MF
        TL_LOGIC(TLCMDOUTNCN_MDZ1MF) &
        ((
  //DZ1_PO3
  TL_LOGIC(TLCMD30_DZ1OF) |
  //DZ1_PO1
  TL_LOGIC(TLCMD30_DZ1MF) 
        )^1);

    //L3 DZ1
   int locPO_DZ1OF = 
        commonDZ1 &
        //�� ��1��
        (GlobalPO3 | LocalPO_DZ1OF) &
        //ELOUTTRG_NCN_MDZ1OF
        (TL_LOGIC(TLCMDOUTNCN_DZ1OF)^1);

//���� �� ���� ������
//TRG_FRONT(set, clr, old, out)
//          //DZ1_PO1                ELOLDTRG_NCN_DZ1MF  ELOUTTRG_NCN_DZ1MF
  TRG_FRONT(locPO_DZ1MF, isFAILU_DZ, TLCMDOLDNCN_DZ1MF,  TLCMDOUTNCN_DZ1MF)
//���� �� ���� ������
//TRG_FRONT(set, clr, old, out)
//          //DZ1_PO3                 ELOLDTRG_NCN_DZ1OF  ELOUTTRG_NCN_DZ1OF
  TRG_FRONT(locPO_DZ1OF, isFAILU_DZ, TLCMDOLDNCN_DZ1OF,  TLCMDOUTNCN_DZ1OF)
//���� �� ���� MMF
//TRG_FRONT(set, clr, old, out)
//                    //DZ1_PO2      ELOLDTRG_NCN_MDZ1MF  ELOUTTRG_NCN_MDZ1MF
  TRG_MMF(isFAILU_DZ, locPO_MDZ1MF,  TLCMDOLDNCN_MDZ1MF,  TLCMDOUTNCN_MDZ1MF)

  //���� �� ��1��
  locPO_DZ1MF &=
        //ELOUTTRG_NCN_DZ1MF
        (TL_LOGIC(TLCMDOUTNCN_DZ1MF)^1);

  //���� �� ��1��
  locPO_DZ1OF &=
        //ELOUTTRG_NCN_DZ1OF
        (TL_LOGIC(TLCMDOUTNCN_DZ1OF)^1);
  
  //���� �� ��� ��1��
  locPO_MDZ1MF &=
        //ELOUTTRG_NCN_MDZ1MF
        TL_LOGIC(TLCMDOUTNCN_MDZ1MF);

//����� �� � �� ���� �������� ��� ��
  //���� �� ��1��
  locPO_DZ1MF &=
      //���� �� ��� ��1��
      (locPO_MDZ1MF^1);

  //���� �� ��1��
  locPO_DZ1OF &=
      //���� ��� ��1��
      (locPO_MDZ1MF^1);

   int max_tmp = 
   //DZ1_PO1
   TL_LOGIC(TLCMD30_DZ1MF) =
   //���� �� ��1��
   IO_LOGIC(IOCMD2_DZ1) =
   LSIGNAL_TIMER(TIMER1_DZ1)  = //DZ1_TIM1
            locPO_DZ1MF;
    if(max_tmp) flag_max_monitoring |= MAXMONITORING_COLLECT;//���� ��������� ��������

   //���� �� ��� ��1��
   IO_LOGIC(IOCMD4_DZ1) =
   LSIGNAL_TIMER(TIMER2_DZ1)  = //DZ1_TIM2
            locPO_MDZ1MF; 

    //DZ1_PO3
    TL_LOGIC(TLCMD30_DZ1OF) =
    //���� �� ��1��
    IO_LOGIC(IOCMD6_DZ1) =
    LSIGNAL_TIMER(TIMER3_DZ1)  = //DZ1_TIM3
            locPO_DZ1OF;

  int tmp =
    LSIGNAL_TIMER(TIMER1_BODZ1)  =
      PLOG_TIMER(TIMER1_DZ1) ; //DZ1_TIM1

  //���� ��1��
  IO_LOGIC(IOCMD3_DZ1) =
    ILOG_TIMER(TIMER1_BODZ1)|tmp;

  tmp =
    LSIGNAL_TIMER(TIMER2_BODZ1)  =
      PLOG_TIMER(TIMER2_DZ1) ; //DZ1_TIM2

  //���� ��� ��1��
  IO_LOGIC(IOCMD5_DZ1) =
    ILOG_TIMER(TIMER2_BODZ1)|tmp;

  tmp =
    LSIGNAL_TIMER(TIMER3_BODZ1)  =
      PLOG_TIMER(TIMER3_DZ1) ; //DZ1_TIM3

  //���� ��1��
  IO_LOGIC(IOCMD7_DZ1) =
    ILOG_TIMER(TIMER3_BODZ1)|tmp;

  
}//logicDZ1(short idxC)


