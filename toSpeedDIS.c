
//#include <TCHAR.H >

#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "component\componentdef.h"

#include "logictimers\logictimersmac.h"

#include "logictimers\logictimersfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "virtualMenu\repozitfnc.h"

#include "SettingIci\SettingIci.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern int offsetTimersPRM1;//�������� �� ��������� ������
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  logMassTimer[];
extern UNS_32 pActualCMD[];//�������

UNS_32 pUROVcmdMaska[DQUADRO];//����������� ����������
UNS_32 pAPVcmdMaska[DQUADRO];//����������� ���������
//UNS_32 pAPVcmdActual[DQUADRO];//��������� Actual
//UNS_32 pUROVcmdActual[DQUADRO];//���������� Actual
//UNS_32 pAPVcmdOld[DQUADRO];//��������� Old
//UNS_32 pUROVcmdOld[DQUADRO];//���������� Old
 MaskaOTAPVUROVOFcmd struct_maskaOTAPVUROVOFcmd;//����� ��� 16 ����� ������� UROV APV OT
 MaskaOTcmd struct_maskaOTcmd;//����� ��� 8 ����� �������
//----------------------------------------
int puskAPV, puskUROV, pusk1OF, pusk2OF, pusk3OF;
int pusk1OF2, pusk2OF2, pusk3OF2;
int pusk1OF3, pusk2OF3, pusk3OF3;
int pusk1OF4, pusk2OF4, pusk3OF4;
int pusk1OF5, pusk2OF5, pusk3OF5;
int pusk1OF6, pusk2OF6, pusk3OF6;
int pusk1OF7, pusk2OF7, pusk3OF7;
int pusk1OF8, pusk2OF8, pusk3OF8;
int pusk1OF9, pusk2OF9, pusk3OF9;
int pusk1OF10, pusk2OF10, pusk3OF10;
int pusk1OF11, pusk2OF11, pusk3OF11;
int pusk1OF12, pusk2OF12, pusk3OF12;
int pusk1OF13, pusk2OF13, pusk3OF13;
int pusk1OF14, pusk2OF14, pusk3OF14;
int pusk1OF15, pusk2OF15, pusk3OF15;
int pusk1OF16, pusk2OF16, pusk3OF16;

int pusk1OT1, pusk2OT1;
int pusk1OT2, pusk2OT2;
int pusk1OT3, pusk2OT3;
int pusk1OT4, pusk2OT4;
int pusk1OT5, pusk2OT5;
int pusk1OT6, pusk2OT6;
int pusk1OT7, pusk2OT7;
int pusk1OT8, pusk2OT8;

int pusk1OT1_old, pusk2OT1_old;
int pusk1OT2_old, pusk2OT2_old;
int pusk1OT3_old, pusk2OT3_old;
int pusk1OT4_old, pusk2OT4_old;
int pusk1OT5_old, pusk2OT5_old;
int pusk1OT6_old, pusk2OT6_old;
int pusk1OT7_old, pusk2OT7_old;
int pusk1OT8_old, pusk2OT8_old;

int rst1OT1, rst2OT1;
int rst1OT2, rst2OT2;
int rst1OT3, rst2OT3;
int rst1OT4, rst2OT4;
int rst1OT5, rst2OT5;
int rst1OT6, rst2OT6;
int rst1OT7, rst2OT7;
int rst1OT8, rst2OT8;

int rst1OT1_old, rst2OT1_old;
int rst1OT2_old, rst2OT2_old;
int rst1OT3_old, rst2OT3_old;
int rst1OT4_old, rst2OT4_old;
int rst1OT5_old, rst2OT5_old;
int rst1OT6_old, rst2OT6_old;
int rst1OT7_old, rst2OT7_old;
int rst1OT8_old, rst2OT8_old;

int OTout[8];//������ OT

UNS_32 pRDIScmdMaska[DQUADRO];//��������������
UNS_32 pRDIScmdActual[DQUADRO];//�������������� AND �������
UNS_32 pRDIScmdOld[DQUADRO];//�������������� AND ������� old
UNS_32 oldDIS[DQUADRO];
UNS_32 act_oldDIS[DQUADRO];

int activityDISold=0;//TRG DIS
int activitySEAMold=0;//TRG SEAM
REGISTRATOR_DIS registrator_dis;//������ ���

void pullReleBO() @ "Fast_function"
{
//������ ���� �� ��
extern UNS_32 rele_bdvv1;//�������� ����
extern UNS_32 rele_bdbo_old;//�������� ����
extern UNS_32 maskaReleBO;

 int tmpOffsetT = offsetTimersPRM1;//�������� �� ��������� ������ PRM1

 //���������� �����
  int focusReleBO =(
    (rele_bdvv1^rele_bdbo_old)&rele_bdbo_old//�������� ����
     )&maskaReleBO;
  rele_bdbo_old = rele_bdvv1;

 int tmp=0;
 if(focusReleBO){
   tmp = 1;
 }//if

 LSIGNAL_TIMER(TIMER_RELEBO) = tmp;//������ ��
 int timlog = FLOG_TIMER(TIMER_RELEBO);
 if(timlog){
  //������ �������� - ������
  rele_bdvv1 |= maskaReleBO;
 }//if
}//pullReleBO()

void pullReleBV() @ "Fast_function"
{
//������ ���� �� �B
extern UNS_32 rele_bdvv1;//�������� ����
extern UNS_32 rele_bdbv_old;//�������� ����
extern UNS_32 maskaReleBO, maskaReleBV;

 int tmpOffsetT = offsetTimersPRM1;//�������� �� ��������� ������ PRM1

 //���������� �����
  int focusReleBV =(
    (rele_bdvv1^rele_bdbv_old)&rele_bdvv1//�������� ����
     )&maskaReleBV;
  rele_bdbv_old = rele_bdvv1;

 int tmp=0;
 if(focusReleBV){
   tmp = 1;
 }//if

 LSIGNAL_TIMER(TIMER_RELEBV) = tmp;//������ �B
 int timlog = FLOG_TIMER(TIMER_RELEBV);
 if(timlog){
  //������ �������� - ������
  rele_bdvv1 |= maskaReleBV;
 }//if
}//pullReleBV()

void PuskAPV_UROV_OFWorking() @ "Fast_function"
{
//���� ��� ���� ��
 puskAPV = puskUROV = pusk1OF = pusk2OF = pusk3OF = 0;
pusk1OF2 = pusk2OF2 = pusk3OF2 = 0;
pusk1OF3 = pusk2OF3 = pusk3OF3 = 0;
pusk1OF4 = pusk2OF4 = pusk3OF4 = 0;
pusk1OF5 = pusk2OF5 = pusk3OF5 = 0;
pusk1OF6 = pusk2OF6 = pusk3OF6 = 0;
pusk1OF7 = pusk2OF7 = pusk3OF7 = 0;
pusk1OF8 = pusk2OF8 = pusk3OF8 = 0;
pusk1OF9 = pusk2OF9 = pusk3OF9 = 0;
pusk1OF10 = pusk2OF10 = pusk3OF10 = 0;
pusk1OF11 = pusk2OF11 = pusk3OF11 = 0;
pusk1OF12 = pusk2OF12 = pusk3OF12 = 0;
pusk1OF13 = pusk2OF13 = pusk3OF13 = 0;
pusk1OF14 = pusk2OF14 = pusk3OF14 = 0;
pusk1OF15 = pusk2OF15 = pusk3OF15 = 0;
pusk1OF16 = pusk2OF16 = pusk3OF16 = 0;

pusk1OT1 = pusk2OT1 = 0;
pusk1OT2 = pusk2OT2 = 0;
pusk1OT3 = pusk2OT3 = 0;
pusk1OT4 = pusk2OT4 = 0;
pusk1OT5 = pusk2OT5 = 0;
pusk1OT6 = pusk2OT6 = 0;
pusk1OT7 = pusk2OT7 = 0;
pusk1OT8 = pusk2OT8 = 0;

rst1OT1 = rst2OT1 = 0;
rst1OT2 = rst2OT2 = 0;
rst1OT3 = rst2OT3 = 0;
rst1OT4 = rst2OT4 = 0;
rst1OT5 = rst2OT5 = 0;
rst1OT6 = rst2OT6 = 0;
rst1OT7 = rst2OT7 = 0;
rst1OT8 = rst2OT8 = 0;

 //��������� big EL
// if(MakeAPVcmdPusk())
   if(CheckActualCMD(pAPVcmdMaska))
        puskAPV = 1;
 //���������� big EL
   if(CheckActualCMD(pUROVcmdMaska)) puskUROV = 1;

 //������1��
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OFcmdMaska))  pusk1OF  = 1;
 //������2��
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OFcmdMaska))  pusk2OF  = 1;
 //������3��
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OFcmdMaska))  pusk3OF  = 1;

 //������1��2
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF2cmdMaska))  pusk1OF2  = 1;
 //������2��2
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF2cmdMaska))  pusk2OF2  = 1;
 //������3��2
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF2cmdMaska))  pusk3OF2  = 1;

 //������1��3
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF3cmdMaska))  pusk1OF3  = 1;
 //������2��3
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF3cmdMaska))  pusk2OF3  = 1;
 //������3��3
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF3cmdMaska))  pusk3OF3  = 1;

 //������1��4
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF4cmdMaska))  pusk1OF4  = 1;
 //������2��4
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF4cmdMaska))  pusk2OF4  = 1;
 //������3��4
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF4cmdMaska))  pusk3OF4  = 1;

 //������1��5
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF5cmdMaska))  pusk1OF5  = 1;
 //������2��5
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF5cmdMaska))  pusk2OF5  = 1;
 //������3��5
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF5cmdMaska))  pusk3OF5  = 1;

 //������1��6
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF6cmdMaska))  pusk1OF6  = 1;
 //������2��6
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF6cmdMaska))  pusk2OF6  = 1;
 //������3��6
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF6cmdMaska))  pusk3OF6  = 1;

 //������1��7
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF7cmdMaska))  pusk1OF7  = 1;
 //������2��7
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF7cmdMaska))  pusk2OF7  = 1;
 //������3��7
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF7cmdMaska))  pusk3OF7  = 1;

 //������1��8
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF8cmdMaska))  pusk1OF8  = 1;
 //������2��8
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF8cmdMaska))  pusk2OF8  = 1;
 //������3��8
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF8cmdMaska))  pusk3OF8  = 1;

 //������1��9
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF9cmdMaska))  pusk1OF9  = 1;
 //������2��9
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF9cmdMaska))  pusk2OF9  = 1;
 //������3��9
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF9cmdMaska))  pusk3OF9  = 1;

 //������1��10
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF10cmdMaska))  pusk1OF10  = 1;
 //������2��10
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF10cmdMaska))  pusk2OF10  = 1;
 //������3��10
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF10cmdMaska))  pusk3OF10  = 1;

 //������1��11
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF11cmdMaska))  pusk1OF11  = 1;
 //������2��11
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF11cmdMaska))  pusk2OF11  = 1;
 //������3��11
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF11cmdMaska))  pusk3OF11  = 1;

 //������1��12
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF12cmdMaska))  pusk1OF12  = 1;
 //������2��12
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF12cmdMaska))  pusk2OF12  = 1;
 //������3��12
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF12cmdMaska))  pusk3OF12  = 1;

 //������1��13
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF13cmdMaska))  pusk1OF13  = 1;
 //������2��13
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF13cmdMaska))  pusk2OF13  = 1;
 //������3��13
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF13cmdMaska))  pusk3OF13  = 1;

 //������1��14
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF14cmdMaska))  pusk1OF14  = 1;
 //������2��14
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF14cmdMaska))  pusk2OF14  = 1;
 //������3��14
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF14cmdMaska))  pusk3OF14  = 1;

 //������1��15
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF15cmdMaska))  pusk1OF15  = 1;
 //������2��15
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF15cmdMaska))  pusk2OF15  = 1;
 //������3��15
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF15cmdMaska))  pusk3OF15  = 1;

 //������1��16
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF16cmdMaska))  pusk1OF16  = 1;
 //������2��16
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF16cmdMaska))  pusk2OF16  = 1;
 //������3��16
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF16cmdMaska))  pusk3OF16  = 1;

 //������1�T1
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT1cmdMaska))  pusk1OT1  = 1;
 //������2�T1
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT1cmdMaska))  pusk2OT1  = 1;
 //rst1�T1
 if(CheckActualCMD(struct_maskaOTcmd.pP3OT1cmdMaska))  rst1OT1  = 1;
 //rst2�T1
 if(CheckActualCMD(struct_maskaOTcmd.pP4OT1cmdMaska))  rst2OT1  = 1;

 //������1�T2
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT2cmdMaska))  pusk1OT2  = 1;
 //������2�T2
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT2cmdMaska))  pusk2OT2  = 1;
 //rst1�T2
 if(CheckActualCMD(struct_maskaOTcmd.pP3OT2cmdMaska))  rst1OT2  = 1;
 //rst2�T2
 if(CheckActualCMD(struct_maskaOTcmd.pP4OT2cmdMaska))  rst2OT2  = 1;

 //������1�T3
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT3cmdMaska))  pusk1OT3  = 1;
 //������2�T3
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT3cmdMaska))  pusk2OT3  = 1;
 //rst1�T3
 if(CheckActualCMD(struct_maskaOTcmd.pP3OT3cmdMaska))  rst1OT3  = 1;
 //rst2�T3
 if(CheckActualCMD(struct_maskaOTcmd.pP4OT3cmdMaska))  rst2OT3  = 1;

 //������1�T4
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT4cmdMaska))  pusk1OT4  = 1;
 //������2�T4
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT4cmdMaska))  pusk2OT4  = 1;
 //rst1�T4
 if(CheckActualCMD(struct_maskaOTcmd.pP3OT4cmdMaska))  rst1OT4  = 1;
 //rst2�T4
 if(CheckActualCMD(struct_maskaOTcmd.pP4OT4cmdMaska))  rst2OT4  = 1;

 //������1�T5
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT5cmdMaska))  pusk1OT5  = 1;
 //������2�T5
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT5cmdMaska))  pusk2OT5  = 1;
 //rst1�T5
 if(CheckActualCMD(struct_maskaOTcmd.pP3OT5cmdMaska))  rst1OT5  = 1;
 //rst2�T5
 if(CheckActualCMD(struct_maskaOTcmd.pP4OT5cmdMaska))  rst2OT5  = 1;

 //������1�T6
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT6cmdMaska))  pusk1OT6  = 1;
 //������2�T6
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT6cmdMaska))  pusk2OT6  = 1;
 //rst1�T6
 if(CheckActualCMD(struct_maskaOTcmd.pP3OT6cmdMaska))  rst1OT6  = 1;
 //rst2�T6
 if(CheckActualCMD(struct_maskaOTcmd.pP4OT6cmdMaska))  rst2OT6  = 1;

 //������1�T7
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT7cmdMaska))  pusk1OT7  = 1;
 //������2�T7
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT7cmdMaska))  pusk2OT7  = 1;
 //rst1�T7
 if(CheckActualCMD(struct_maskaOTcmd.pP3OT7cmdMaska))  rst1OT7  = 1;
 //rst2�T7
 if(CheckActualCMD(struct_maskaOTcmd.pP4OT7cmdMaska))  rst2OT7  = 1;

 //������1�T8
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT8cmdMaska))  pusk1OT8  = 1;
 //������2�T8
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT8cmdMaska))  pusk2OT8  = 1;
 //rst1�T8
 if(CheckActualCMD(struct_maskaOTcmd.pP3OT8cmdMaska))  rst1OT8  = 1;
 //rst2�T8
 if(CheckActualCMD(struct_maskaOTcmd.pP4OT8cmdMaska))  rst2OT8  = 1;

}//PuskAPV_UROV_OFWorking()

void DiskretRegWorking() @ "Fast_function"
{
//������ ����� ������������
 int tmpOffsetT = offsetTimersPRM1;//�������� �� ��������� ������ PRM1
 LSIGNAL_TIMER(TIMERDIS_PRM1) = 0;//������ ���
 //����������� ������ ��� ����� ������ DIS
 LSIGNAL_TIMER(TIMER_MINDIS_PRM1) = 0;//����� ������ DIS
 int isDISbusy = getTimerBUSY(tmpOffsetT+TIMERDIS_PRM1);//���� ���������� DIS

 if(MakeRDIScmdPusk()){//��������� �������������� �� ������big EL
   if(isDISbusy);//���� ���������� DIS
   else {
          //����������� ������ ��� ����� ������ DIS
          LSIGNAL_TIMER(TIMER_MINDIS_PRM1) = 1;//����� ������ DIS
          StartDiscretReg();//��������� ������ ��� ���
         }
   //����������� ������ ��� ������� num
   LSIGNAL_TIMER(TIMERDIS_PRM1) = 1;//��������� ������ ���
 }//if(MakeRDIScmdActual())
   else {
   //��� ���������� DIS
    memcpy(act_oldDIS, pActualCMD, 4*DQUADRO);//��������� �������
   }
   int activityDISact = isActivityDIS();//�������� ��������� ���������� ���
   //EL TRG down front
   int activityDIStrg = (activityDISact^activityDISold)&activityDISold;
   activityDISold = activityDISact;
   LSIGNAL_TIMER(TIMER_SEAM_PRM1) = activityDIStrg;//������ ������ SEAM
   int activitySEAMact = FLOG_TIMER(TIMER_SEAM_PRM1);//������ ������ SEAM
   //EL TRG down front
   int activitySEAMtrg = (activitySEAMact^activitySEAMold)&activitySEAMold;
   activitySEAMold = activitySEAMact;
   int activitySEAMstop = (activityDISact^1) & activitySEAMtrg;
   if(registrator_dis.title_dis.len_dis>(SIZE_DIS-2)) activitySEAMstop = 1;//������ ����
//������ ������������� �� ������� - �� ���� ������
   FLOG_TIMERRES(TIMERDIS_PRM1, activitySEAMstop);
//������ ������������� �� ���� ������
   FLOG_TIMER(TIMER_MINDIS_PRM1);//����� ������ DIS

   if(getTimerBUSY(tmpOffsetT+TIMERDIS_PRM1)){//bazisTimerMem[tmpOffsetT+TIMERDIS_PRM1].BUSY){//���� ���������� DIS
     //�������� ������� � ������
     if(memcmp(oldDIS, pActualCMD, 4*DQUADRO)){
      //���� ��������
      registrator_dis.bodyDIS[registrator_dis.title_dis.len_dis].reltime =
             //������� �����
             getTimerCrr(tmpOffsetT+TIMERDIS_PRM1);
             //bazisTimerMem[tmpOffsetT+TIMERDIS_PRM1].crrCNT;
      memcpy(registrator_dis.bodyDIS[registrator_dis.title_dis.len_dis].pActualCMD, 
                pActualCMD, 4*DQUADRO);//���������� �������
      registrator_dis.title_dis.len_dis++;//������ ������ ���
     }//if(memcmp(oldDIS, pActualCMD, 4*DQUADRO))
     memcpy(oldDIS, pActualCMD, 4*DQUADRO);//��������� �������
   }//if(isDISbusy)

}//DiskretRegWorking()

int isActivityDIS() @ "Fast_function"
{
//�������� ���������� ���
  int tmp = 0;
  while (cnfCOMPONENT[tmp].componentEnable)
  {
    if(cnfCOMPONENT[tmp].isDISactiv(tmp)) return 1;
    tmp++;
  }//while
  return 0;
}//isActivityDIS()

void StartDiscretReg() @ "Fast_function"
{
//��������� ������ ��� ���
 registrator_dis.title_dis.len_dis=0;//����� ���� ���
 memcpy(registrator_dis.title_dis.oldDIS, act_oldDIS, 4*DQUADRO);//�������������� �������
 memset(oldDIS, 0, 4*DQUADRO);//��������

 registrator_dis.title_dis.title_year = 1;
 registrator_dis.title_dis.title_mon  = 1;
 registrator_dis.title_dis.title_date = 1;
 registrator_dis.title_dis.title_hour = 1;
 registrator_dis.title_dis.title_min  = 1;
 registrator_dis.title_dis.title_sec  = 1;

}//StartDiscretReg()

int MakeRDIScmdPusk()  @ "Fast_function"
{
//��������� �������������� �� ������
  UNS_32 tmpM[DQUADRO];
  UNS_32 tmpI=0;
  for(int i=0; i<DQUADRO; i++) 
          pRDIScmdActual[i]=pRDIScmdMaska[i]&pActualCMD[i];//�������������� AND �������
  //������� EL
  for(int i=0; i<DQUADRO; i++) 
          tmpM[i]=(pRDIScmdActual[i]^pRDIScmdOld[i])&pRDIScmdActual[i];
  for(int i=0; i<DQUADRO; i++) 
          pRDIScmdOld[i]=pRDIScmdActual[i];

  for(int i=0; i<DQUADRO; i++) 
          tmpI|=tmpM[i];
  return tmpI;
}//MakeRDIScmdPusk
/*
int MakeAPVcmdPusk() @ "Fast_function"
{
//��������� APV �� ������
  UNS_32 tmpM[DQUADRO];
  UNS_32 tmpI=0;
  for(int i=0; i<DQUADRO; i++) 
          pAPVcmdActual[i]=pAPVcmdMaska[i]&pActualCMD[i];//�������������� AND �������
  //������� EL ���������
  for(int i=0; i<DQUADRO; i++) 
          tmpM[i]=(pAPVcmdActual[i]^pAPVcmdOld[i])&pAPVcmdOld[i];
  for(int i=0; i<DQUADRO; i++) 
          pAPVcmdOld[i]=pAPVcmdActual[i];

  for(int i=0; i<DQUADRO; i++) 
          tmpI|=tmpM[i];
  return tmpI;
}//MakeAPVcmdPusk

int MakeUROVcmdPusk() @ "Fast_function"
{
//��������� UROV �� ������
  UNS_32 tmpM[DQUADRO];
  UNS_32 tmpI=0;
  for(int i=0; i<DQUADRO; i++) 
          pUROVcmdActual[i]=pUROVcmdMaska[i]&pActualCMD[i];//�������������� AND �������
  //������� EL
  for(int i=0; i<DQUADRO; i++) 
          tmpM[i]=(pUROVcmdActual[i]^pUROVcmdOld[i])&pUROVcmdActual[i];
  for(int i=0; i<DQUADRO; i++) 
          pUROVcmdOld[i]=pUROVcmdActual[i];

  for(int i=0; i<DQUADRO; i++) 
          tmpI|=tmpM[i];
  return tmpI;
}//MakeUROVcmdPusk
*/
