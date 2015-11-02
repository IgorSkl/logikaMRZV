
#include "lpc_types.h"

#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "component\componentdef.h"
#include "callbackelement\callbackelementdef.h"
#include "psuperVisor\psvisor_helpdef.h"
#include "virtualMenu\wideLogManagerdef.h"
//#include "zonaVRT\zonaVRTdef.h"

#include "callbackelement\callbackelementfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\systemmenufnc.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#include "periodOperations.h"

#include "header.h"
#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "PRM1Component.c"

#include "APVComponent.c"
#include "DZ1Component.c"
#include "DZ2Component.c"

#include "MTZ1Component.c"
#include "MTZ2Component.c"

#include "NZOP1Component.c"

extern CALLBACK_MISSION cb_missionDEVICE1;
extern CALLBACK_MISSION *cb_mission_crrDEVICE1;//������� ������
extern short  missionSeparatorDEVICE1;//��������� ������
extern int    WideCmdBuffer[];//������� ��� ������
extern UNS_32 pActualCMD[];//�������
extern UNS_32 ArrayRANGIR[];
extern int  spvUSTAVKI[];//������� ������� �����������

//���������� ����� ���� ��������
extern int  globalTimerReset;
extern int ReleTrigger;//����� ����
extern int CDITrigger;//����� ���
extern int offsetSPVCmdPRM1;//�������� ��� SPV PRM1
extern int    TypLE[];
extern UNS_32 *WideLogActual;//��������� ������ ������ ������
extern UNS_32 PlusCircleCmd[];//��������� ������ �������� ������ LE
extern UNS_32 InputLECmd[];//������� ��������� ������ LE
extern UNS_32 EXEOutputCmd[];//�������� ��������� ������ �����������
extern int    isTimeSection;//����������� ������ � ������� ��������

extern UNS_32 dataCmdStateINTERFACE[];//INTERFACE CmdState
extern UNS_32 dataTrgCmdStateINTERFACE[];//INTERFACE Trg CmdState
extern UNS_32 buffTrgCmdStateINTERFACE[];//INTERFACE CmdState
extern UNS_32 buffCmdStateINTERFACE[];//INTERFACE CmdState
extern UNS_32 buffInStateINTERFACE;//INTERFACE  In
extern UNS_32 buffOutStateINTERFACE;//INTERFACE Out
extern UNS_32 buffLedStateINTERFACE;//INTERFACE Led
extern UNS_32 buffTrgOutStateINTERFACE;//INTERFACE Trg Out
extern UNS_32 buffTrgLedStateINTERFACE;//INTERFACE Trg Led
extern UNS_32 buffGruppaUstINTERFACE;//������ �������
extern UNS_32 GruppaUst;//������ �������

//����� �������
//extern char chbrCfgTblState;

typedef struct
{
  volatile UNS_8 bdvv_unisost1;  //0 ��� ���� ����1
  volatile UNS_8 bdvv_in1;       //1 ��� ������ ����1
  volatile UNS_8 bdvv_out1;      //2 ��� ������� ����1
  volatile UNS_8 bdvv_outsost1;  //3 ��� ���� ������� ����1
  volatile UNS_8 bdvv_outena1;   //4 ���������� ������� ����1
  volatile UNS_8 bdvv_rezerv1;   //5 ������
  volatile UNS_8 bdvv_rezerv2;   //6 ������
  volatile UNS_8 bdvv_rezerv3;   //7 ������
  volatile UNS_8 bdvv_unisost2;  //8 ��� ���� ����2
  volatile UNS_8 bdvv_in2;       //9 ��� ������ ����2
  volatile UNS_8 bdvv_out2;      //A ��� ������� ����2
  volatile UNS_8 bdvv_outsost2;  //B ��� ���� ������� ����2
  volatile UNS_8 bdvv_outena2;   //C ���������� ������� ����2
} BDVV_REGS_T;

typedef struct
{
  volatile UNS_8 bdvv_unisost_new;  //0 ��� ���� ���� _new
  volatile UNS_8 bdvv_in_new;       //1 ��� ������ ���� _new
  volatile UNS_8 bdvv_out_new;      //2 ��� ������� ���� _new
  volatile UNS_8 bdvv_outsost_new;  //3 ��� ���� ������� ���� _new
  volatile UNS_8 bdvv_outena_new;   //4 ���������� ������� ���� _new
} BDVVNEW_REGS_T;

typedef struct
{
  volatile UNS_8 bdv_unisost;  //0 ��� ���� ��
  volatile UNS_8 bdv_in1;          //1 ��� ������ ���
  volatile UNS_8 bdv_in2;          //2 ��� ������ ���
} BDV_REGS_T;

#define BDVV_BASE  0xE3000000
#define BDVV_PNT ((BDVV_REGS_T *)(BDVV_BASE))
#define BDV_BASE  0xE3000010
#define BDV_PNT ((BDV_REGS_T *)(BDV_BASE))
#define BDVVNEW_BASE  0xE3000020
#define BDVVNEW_PNT ((BDVVNEW_REGS_T *)(BDVVNEW_BASE))


//UNS_8 arrayEEPROM[100];//������ EEPROM ��� ������
extern int timing;  
extern int timingLoad;  
extern int cicling;  

extern int trigReg;//��������� ����� ���

extern int IndexTIMERS;
extern int IndexTLog;
extern int IndexIO;
extern int IndexENA;
extern int IndexUstSPV;//������ ������� � �����������
extern int GlobalLevelI_ABC[];//������ ������ ����� �����
extern int GlobalLevelUL_ABC[];//������ ���� ���
extern int GlobalLevelUF_ABC[];//������ ���� ���
extern int GlobalLevel_3I0;
extern int GlobalLevel_3U0;
extern UNS_32 rawDVLow;//����� ��

int indexLgm=0;//������ ������������ ��
int isRunWL=1;//���������� ��

UNS_32 rele_bdvv1;//�������� ����
UNS_32 cdi_bdvv1;//�������� CDI

UNS_32 selectorDVLow;//�������� �� ��������-���������� ��� �� 16 DV
UNS_32 selectorDVMidd;//�������� �� ��������-���������� ��� cp 16 DV
UNS_32 selectorDVHi;//�������� �� ��������-���������� ��� ct 16 DV

#include "ici_r_ef.h"

int flag_max_monitoring;//���� ��������� ��������
int IA_maxMonitoring;//���� ������ ���� ���� �� IA
int IB_maxMonitoring;//���� ������ ���� ���� �� IB
int IC_maxMonitoring;//���� ������ ���� ���� �� IC

int IA_maxFix;//�������� ������ ���� ���� �� IA
int IB_maxFix;//�������� ������ ���� ���� �� IB
int IC_maxFix;//�������� ������ ���� ���� �� IC

int cntToBC=0;//����� � BC
void periodical_operations(void)
{
 UNS_32 dvUnion[DQUADRO];//DV
 UNS_32 tmpUnion[2*DQUADRO];//���������
 UNS_32 tmpUnion2[2*DQUADRO];//���������


 switch(trigReg)//��������� �����������
 {
  case 1: DiskrRegList();//������ 50 ����� ����� ������������
  break;

  case 2: ActualRegList();//������ 50 ����� �������
  break;

  case 3: ActualDVList();//������ 50 ����� ������� DV
  break;

  case 4: ActualReleList();//������ 50 ����� ������� ����
  break;

  default:;
 }//switch
  trigReg  = 0;//��������� �����������


 #define TEST_PIN_1          0

        UNS_32 set = 0, clr = 0, maska = P3_STATE_GPO(TEST_PIN_1);
        if ((GPIO->p3_outp_state & maska) != 0) clr = maska; 
        else set = maska;
        gpio_set_gpo_state(set, clr);

  JLINKDCC_Process();
  
//�������� ��������� �������
  Scan_Ici_Event_Req(); //��������������� �����
  Scan_Ici_Entry_Data();//��������������� �����

  flag_max_monitoring = 0;//���� ��������� ��������

  dataAccessICI();//������ � ������ ICI

  UNS_8 test1 = BDVV_PNT->bdvv_unisost1;  //0 ��� ���� ����1
//  BDVV_PNT->bdvv_outena1 = 0xA5;   //4 ���������� ������� ����1
//  BDVV_PNT->bdvv_out1    = 0xff;      //2 ��� ������� ����1
  UNS_8 test2 = BDVV_PNT->bdvv_outsost1;  //3 ��� ���� ������� ����1
  UNS_8 test3 = BDVV_PNT->bdvv_in1;       //1 ��� ������ ����1

    UNS_8 test1_v = BDV_PNT->bdv_unisost;  //0 ��� ���� ���
  UNS_8 test3_v = BDV_PNT->bdv_in1;       //1 ��� ������ ���
  UNS_8 test4_v = BDV_PNT->bdv_in2;       //1 ��� ������ ���

  UNS_8 test1_new = BDVVNEW_PNT->bdvv_unisost_new;  //0 ��� ���� ���� _new
//  BDVVNEW_PNT->bdvv_outena_new = 0xA5;   //4 ���������� ������� ���� _new
//  BDVVNEW_PNT->bdvv_out_new    = 0xff;      //2 ��� ������� ���� _new
  UNS_8 test2_new = BDVVNEW_PNT->bdvv_outsost_new;  //3 ��� ���� ������� ���� _new
  UNS_8 test3_new = BDVVNEW_PNT->bdvv_in_new;       //1 ��� ������ ���� _new
  
 rawDVLow = test3_new;

 //BDV_PNT->bdv_unisost = 0x00;  //0 ��� ���� ���

//�������� ��� � ������
 memset(dvUnion, 0, 4*DQUADRO);//�������� DV

  isTimeSection = 1;//����������� ������ � ������� ��������
  selectorDVLow = SelectorDVdriverLow();//�������� �� ��������-���������� ��� �� 16 DV
  //������� �� -���������������
  UNS_32 upr_dvLow  =   SPV_USTOUT(offsetSPVCmdPRM1+ SPV_UPR_DVLOW);
  selectorDVLow ^= upr_dvLow;
  dvUnionMakerLow(selectorDVLow, dvUnion);//�������� ������ dvUnion ��� �� 16 DV

  selectorDVMidd = SelectorDVdriverMidd();//�������� �� ��������-���������� ��� cp 16 DV
  //������� �� -���������������
  UNS_32 upr_dvMidd =   SPV_USTOUT(offsetSPVCmdPRM1+ SPV_UPR_DVMIDD);
  selectorDVMidd ^= upr_dvMidd;
  dvUnionMakerMidd(selectorDVMidd, dvUnion);//�������� ������ dvUnion ��� cp 16 DV

  selectorDVHi = SelectorDVdriverHi();//�������� �� ��������-���������� ��� ct DV
  UNS_32 upr_dvHi   =   SPV_USTOUT(offsetSPVCmdPRM1+ SPV_UPR_DVHI);
  selectorDVHi ^= upr_dvHi;
  dvUnionMakerHi(selectorDVHi, dvUnion);//�������� ������ dvUnion ��� ct  DV
  isTimeSection = 0;//����������� ������ � ������� ��������
  buffInStateINTERFACE = selectorDVLow + selectorDVMidd*65536;
/*
  FDVForm1->VisualDVdriver(selectorDVHi);//������������ �� ��������-����������

 if(DV1Box->Checked)
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV1_SM*DQUADRO+ i];
 if(DV2Box->Checked)
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV2_SM*DQUADRO+ i];
 if(DV3Box->Checked)
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV3_SM*DQUADRO+ i];
 if(DV4Box->Checked)
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV4_SM*DQUADRO+ i];
 if(DV5Box->Checked)
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV5_SM*DQUADRO+ i];
*/

 //����� ������ ���������
 CommonMeasureLogic();

  if(TypLE[indexLgm]==0){
           indexLgm=0;//������ ������������ ��
           }//if

//�������� ������� ��� ��
 for (int i=0; i<2*DQUADRO; i++) InputLECmd[i] = PlusCircleCmd[i] | EXEOutputCmd[i] | dvUnion[i];

//��������� ������ �� 
  switch(TypLE[indexLgm])//������ ������������ ��
  {
   case typeLE_OR:{
     elementOR(indexLgm);//OR
     }
   break;
   case typeLE_AND:
     elementAND(indexLgm);//AND
   break;
   case typeLE_XOR:
     elementXOR(indexLgm);//XOR
   break;
   default:;

  }//switch

  indexLgm++;//������ ������������ ��
  if(indexLgm==LE_TOTAL) indexLgm=0;


 //������������ �������(������ ��������) ��� ����� ����� �� � ��
 for (int i=0; i<DQUADRO; i++) pActualCMD[i] = PlusCircleCmd[i] | dvUnion[i];
 //�������� ������� pActualCMD (������ ��������)
 memcpy(tmpUnion, pActualCMD, 4*DQUADRO);

//���������� ��� ������(������ ��������) � ������� ��� ������ RT
 TranslateQuadroToWideRTCmd(pActualCMD);

 EXElogicCOMPONENT();//���������� ������ ����������� �� ������

 memset(pActualCMD, 0, 4*DQUADRO);//�������� ������� (������ ��������)
 CompressorToActualCMD();//�������� ������� (������ ��������) �� WideCmdRTBuffer

 //�������� ����� cmd �� �����������(������ ��������)
 for (int i=0; i<DQUADRO; i++) EXEOutputCmd[i] = pActualCMD[i] & ~tmpUnion[i];

//---------���������� ��--------------------------
 //�������� ������� pActualCMD (������ ��������)
 memcpy(tmpUnion2, pActualCMD, 4*DQUADRO);
///*
 //������������ �������(������ ��������) ��� ����� ����� ��(������ ��������)
 memcpy(pActualCMD, PlusCircleCmd, 2* 4*DQUADRO);
// for (int i=0; i<DQUADRO; i++) pActualCMD[i +DQUADRO] = PlusCircleCmd[i +DQUADRO];
 //�������� ������� pActualCMD (������ ��������)
 memcpy(tmpUnion, WideLogActual, 4*DQUADRO);

 //�������� ������� pActualCMD (������ ��������)
// memcpy(tmpUnion, WideLogActual, 4*DQUADRO);
//���������� �������(������ ��������) � ������� ��� ������ RT
 TranslateQuadroToWideRTCmd(WideLogActual);

 EXElogicCOMPONENT_WL();//���������� ������ ����������� �� ������ ��

 memset(pActualCMD, 0, 4*DQUADRO);//�������� ������� (������ ��������)
 CompressorToActualCMD();//�������� ������� �� WideCmdRTBuffer

 //�������� ����� cmd �� �����������(������ ��������)
 for (int i=0; i<DQUADRO; i++) EXEOutputCmd[i +DQUADRO] = pActualCMD[i] & ~tmpUnion[i];
//*/
 //������������ pActualCMD (������ ��������)
 memcpy(pActualCMD, tmpUnion2, 4*DQUADRO);
//-------------------------------------------------------------------------------------

 globalTimerReset = 0;//���������� ����� ���� ��������
 DiskretRegWorking();//������ ����� ������������
 PuskAPV_UROV_OFWorking();//���� ��� ���� ��

 isTimeSection = 1;//����������� ������ � ������� ��������
 TranslateINTERFACE();//����������������� ������� ��� ������

//��������� ������������ ����
  rele_bdvv1 = WorkRangirRele();
  if((rele_bdvv1&0x40)!=0){
    int tt1=0;
  }//if
//��������� ������������ ���
  cdi_bdvv1 = WorkRangirCDI();
  isTimeSection = 0;//����������� ������ � ������� ��������

  buffOutStateINTERFACE = rele_bdvv1;//INTERFACE Out
  buffLedStateINTERFACE = cdi_bdvv1;//INTERFACE Led
  buffTrgOutStateINTERFACE = ReleTrigger;//INTERFACE Trg Out
  buffTrgLedStateINTERFACE = CDITrigger;//INTERFACE Trg Led
  buffGruppaUstINTERFACE = GruppaUst;//������ �������
  memcpy(buffCmdStateINTERFACE, dataCmdStateINTERFACE, 4*DQUADRO);//INTERFACE CmdState
  memcpy(buffTrgCmdStateINTERFACE, dataTrgCmdStateINTERFACE, 4*DQUADRO);//INTERFACE Trg CmdState

  BDVV_PNT->bdvv_outena1 = 0xA5;   //4 ���������� ������� ����1
//  BDVV_PNT->bdvv_out1    = 0x00;//rele_bdvv1;//0xff;      //2 ��� ������� ����1
  
  BDVVNEW_PNT->bdvv_outena_new = 0xA5;   //4 ���������� ������� ����1
  BDVVNEW_PNT->bdvv_out_new    = rele_bdvv1;      //2 ��� ������� ����1
  
//  dataAccessEEPROM();//������ � ������ EEPROM 
 
 cicling ++;  
 
 if(cicling==100000){
      int tt0 = timingLoad;  
      int tt1 = timing;  
      int tt2 = cicling;  
      
      int tt3 = IndexTIMERS;
      int tt4 = IndexTLog;
      int tt5 = IndexIO;
      int tt6 = IndexENA;
      int tt7 = IndexUstSPV;//������ ������� � �����������
          tt7 = IndexUstSPV;//������ ������� � �����������
      
 }//if
 

 if(flag_max_monitoring==0)//���� ��������� ��������
 {
   //��� �� ����� ������ �� ��������
   IA_maxMonitoring = 0;//���� ������ ���� ���� �� IA
   IB_maxMonitoring = 0;//���� ������ ���� ���� �� IB
   IC_maxMonitoring = 0;//���� ������ ���� ���� �� IC

   IA_maxFix = 0;//�������� ������ ���� ���� �� IA
   IB_maxFix = 0;//�������� ������ ���� ���� �� IB
   IC_maxFix = 0;//�������� ������ ���� ���� �� IC
 }//if(flag_max_monitoring==0)//���� ��������� ��������
//  case MAXMONITORING_COLLECT:
 if(flag_max_monitoring&MAXMONITORING_COLLECT){//���� ��������� ��������
  //���� ������ ���� ����������
   }//if(flag_max_monitoring&MAXMONITORING_COLLECT){//���� ��������� ��������
//  case MAXMONITORING_FIX:

 if(flag_max_monitoring&MAXMONITORING_FIX){//���� ��������� ��������
  //�������� ������ ���� ����������
  //���������� �������
  }//if(flag_max_monitoring&MAXMONITORING_FIX){//���� ��������� ��������
 
 
}//periodical_operations(void)
