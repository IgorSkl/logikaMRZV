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

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "virtualMenu\rangmanagerdef.h"
#include "component\componentdef.h"
#include "logictimers\logictimersdef.h"
#include "virtualMenu\systemmenudef.h"
#include "virtualMenu\repozitdef.h"

#include "logictimers\logictimersfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\repozitfnc.h"

#include "psupervisor\psupervisor.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"

extern ELEMENT_RPZ   rpzCOMPONENT[];//�����������
extern ELEMENT_RPZ  rpzCOMPONENT_WL[];
extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern UNS_32 ArrayRANGIR[];
extern UNS_32 ArrayWIDELOG[];
extern int  elTrgOldTimer[];
extern int  elTrgOutTimer[];
//��� ������ ������� ��������
extern int  logMassTimer[];

extern int  elTrgOldTimer_WL[];
extern int  elTrgOutTimer_WL[];
//��� ������ ������� ��������
extern int  logMassTimer_WL[];
extern int  timerEnableWL;//���������� ������ �������� ��

//������������
COMPONENT_OBJ        cnfCOMPONENT[MAX_CNFCOMPONENT];
//������������ ��
COMPONENT_OBJ        cnfCOMPONENT_WL[MAX_WLCOMPONENT];
//������� ������
IONAMESTATUS_RANGIR  common_shadow[SIZE_RANGIRCMD+SIZE_RANGIRCMD+2];

//������� ������� �����������
int    spvUSTAVKI[MAX_SPVUSTAVKI];
//������� ������� ����������� ��
int    spvUSTAVKI_WL[MAX_SPVUSTAVKI_WL];
//temp ������
int   tempLog[MAX_TEMPLOG];
//temp ������ ��
int   tempLog_WL[MAX_TEMPLOG_WL];
//ENA �������
int   ENAcmd[MAX_ENACMD];
//ENA ������� ��
int   ENAcmd_WL[MAX_ENACMD_WL];

int  IndexTIMERS;//��������� ������
int  IndexIO;//������ IO
int  IndexUstSPV;//������ ������� � �����������
int  IndexTLog;//������ temp ������
int  IndexENA;//������ ENA ������
UNS_32 maskaReleBO;
UNS_32 maskaReleBV;

//������������� ����� ���� 
int  isFAILU_COMMON_MTZ;
int  isFAILU_COMMON_DZ;
int  isFAILU_DZ;
//���� UCM ������ UCM005
//int  isFAILUCM005_COMMON;
//��� ICM  ������ ICM005
//int  isFAILICM005_COMMON;
//������� �� ���������
int  ddv_inc[DV_TOTAL];
int  ddv_fix[DV_TOTAL];

/**********************************************
����������
������������� ������� ����������� �� ������
total - INITUST_NULLCOMP-�� ������
        INITUST_TOPCOMP-���� ������� ����
**********************************************/
void INITustrangCOMPONENT(short total)
{
  short result = 0;
  short next   = 0;
  short tmp = 0;
  short tmpCntUst = 0;
  cnfCOMPONENT[0].offsetUstMng = 0;//�������� ������� ������ ��������� ���
  IndexUstSPV  = 0;//������ ������� � �����������

  while (cnfCOMPONENT[next].componentEnable)   //��� ���������� � ������������
  {
    cnfCOMPONENT[next].offsetUstSpv = IndexUstSPV;//�������� ������� �����������
    switch(total)
    {
    case INITUST_TOPCOMP:   //���� ������� ����
    {
      if(next==0)
      {
        tmpCntUst = cnfCOMPONENT[next].cntUstMng = cnfCOMPONENT[next].initUstMng(1);
        if(tmpCntUst>0)MngUstTopAddUSTAVKI(tmpCntUst);//�������� ������� �� ������� mngUst
        MngRangTopAddNameStatusRANGIR(cnfCOMPONENT[next].cntIOCmd, cnfCOMPONENT[next].nameStatusIO);//�������� ������� �� ������� mngRang
        tmp = cnfCOMPONENT[next].cntTLCmd;
        if(tmp>0)TopAddTEMPLOGIC(tmp);//�������� TL log �� ������� tempLog
        tmp = cnfCOMPONENT[next].cntENACmd;
        if(tmp>0)TopAddENACmd(tmp);//�������� ENA �� �������
        for(short i=0; i<UVV_TOTAL; i++)
        {
          MngRangTopAddQuadroRANGIR(&(ArrayRANGIR[i*DQUADRO]), cnfCOMPONENT[next].cntIOCmd);
        }//for
      }//if
      else
        //������� �� ����������������
        tmpCntUst = cnfCOMPONENT[next].cntUstMng = cnfCOMPONENT[next].initUstMng(0);
    }//case
    break;

//    case  INITUST_NULLCOMP:
      //������� �� ����������������
  //    tmpCnt = cnfCOMPONENT[next].cntUstMng = cnfCOMPONENT[next].initUstMng(0);
    //  break;

    default:
      //������� �� ����������������
      tmpCntUst = cnfCOMPONENT[next].cntUstMng = cnfCOMPONENT[next].initUstMng(0);

    }//switch

    result += tmpCntUst;//�������� ������ ��������� ���
    if(cnfCOMPONENT[next+1].componentEnable)
      cnfCOMPONENT[next+1].offsetUstMng = result;//�������� ������ ��������� ���
    next++;
  }//while
}//INITustCOMPONENT(short total)

/**********************************************
����������
������������� ������� ����������� �� ������ ��
total - INITUST_NULLCOMP-�� ������
        INITUST_TOPCOMP-���� ������� ����
**********************************************/
void INITustrangCOMPONENT_WL(short total)
{
  short result = 0;
  short next   = 0;
  short tmpCnt = 0;
  cnfCOMPONENT_WL[0].offsetUstMng = 0;//�������� ������� ������ ��������� ���
  IndexUstSPV  = 0;//������ ������� � �����������

  while (cnfCOMPONENT_WL[next].componentEnable)   //��� ���������� � ������������
  {
    cnfCOMPONENT_WL[next].offsetUstSpv = IndexUstSPV;//�������� ������� �����������
    switch(total)
    {
    case INITUST_TOPCOMP:   //���� ������� ����
    {
      if(next==0)
      {
        tmpCnt = cnfCOMPONENT_WL[next].cntUstMng = cnfCOMPONENT_WL[next].initUstMng(1);
        if(tmpCnt>0)MngUstTopAddUSTAVKI_WL(tmpCnt);//�������� ������� �� ������� mngUst
        //�������� ����� ������ �� ������� 
        MngRangTopAddNameStatusRANGIR_WL(cnfCOMPONENT_WL[next].cntIOCmd, cnfCOMPONENT_WL[next].nameStatusIO);
        tmpCnt = cnfCOMPONENT_WL[next].cntTLCmd;
        if(tmpCnt>0)TopAddTEMPLOGIC_WL(tmpCnt);//�������� TL log �� ������� tempLog
        tmpCnt = cnfCOMPONENT_WL[next].cntENACmd;
        if(tmpCnt>0)TopAddENACmd_WL(tmpCnt);//�������� ENA �� �������
        //����������� PRM MINUS PLUS
        for(short i=0; i<3*LE_TOTAL; i++)
        {
          //������ �������� 2*DQUADRO �� PRM MINUS PLUS
          MngRangTopAddQuadroRANGIR(&(ArrayWIDELOG[i*2*DQUADRO +DQUADRO]), cnfCOMPONENT_WL[next].cntIOCmd);
        }//for
      }//if
      else
        //������� �� ����������������
        tmpCnt = cnfCOMPONENT_WL[next].cntUstMng = cnfCOMPONENT_WL[next].initUstMng(0);
    }//case
    break;

//    case  INITUST_NULLCOMP:
      //������� �� ����������������
  //    tmpCnt = cnfCOMPONENT[next].cntUstMng = cnfCOMPONENT[next].initUstMng(0);
    //  break;

    default:
      //������� �� ����������������
      tmpCnt = cnfCOMPONENT_WL[next].cntUstMng = cnfCOMPONENT_WL[next].initUstMng(0);

    }//switch

    result += tmpCnt;//�������� ������ ��������� ���
    if(cnfCOMPONENT_WL[next+1].componentEnable)
      cnfCOMPONENT_WL[next+1].offsetUstMng = result;//�������� ������ ��������� ���
    next++;
  }//while
}//INITustCOMPONENT_WL(short total)

/**********************************************
����������
������������� IO ������ ����������� �� ������
**********************************************/
void INITIOCmdCOMPONENT()
{
  IndexIO     = 0;//IO ������
  short tmp = 0;
  while (cnfCOMPONENT[tmp].componentEnable)
  {
    cnfCOMPONENT[tmp].offsetIOCmd = IndexIO;//�������� IO
    cnfCOMPONENT[tmp].cntIOCmd = cnfCOMPONENT[tmp].initIOCmd();//�-�� IO
    tmp++;
  }//while
}//INITIOCmdCOMPONENT()

/**********************************************
����������
������������� IO ������ ����������� �� ������ ��
**********************************************/
void INITIOCmdCOMPONENT_WL()
{
  IndexIO     = 0;//IO ������
  short tmp = 0;
  while (cnfCOMPONENT_WL[tmp].componentEnable)
  {
    cnfCOMPONENT_WL[tmp].offsetIOCmd = IndexIO;//�������� IO
    cnfCOMPONENT_WL[tmp].cntIOCmd = cnfCOMPONENT_WL[tmp].initIOCmd();//�-�� IO
    tmp++;
  }//while
}//INITIOCmdCOMPONENT_WL()

/**********************************************
����������
������������� TL ������ ����������� �� ������
**********************************************/
void INITTLCmdCOMPONENT()
{
  IndexTLog     = 0;//TL ������
  short tmp = 0;
  while (cnfCOMPONENT[tmp].componentEnable)
  {
    cnfCOMPONENT[tmp].offsetTLCmd = IndexTLog;
    cnfCOMPONENT[tmp].cntTLCmd = cnfCOMPONENT[tmp].initTLCmd();
    tmp++;
  }//while
}//INITTLCmdCOMPONENT()

/**********************************************
����������
������������� TL ������ ����������� �� ������ ��
**********************************************/
void INITTLCmdCOMPONENT_WL()
{
  IndexTLog     = 0;//TL ������
  short tmp = 0;
  while (cnfCOMPONENT_WL[tmp].componentEnable)
  {
    cnfCOMPONENT_WL[tmp].offsetTLCmd = IndexTLog;
    cnfCOMPONENT_WL[tmp].cntTLCmd = cnfCOMPONENT_WL[tmp].initTLCmd();
    tmp++;
  }//while
}//INITTLCmdCOMPONENT_WL()

/**********************************************
����������
������������� ENA ������ ����������� �� ������
**********************************************/
void INITENACmdCOMPONENT()
{
  IndexENA  = 0;//ENA ������
  short tmp = 0;
  while (cnfCOMPONENT[tmp].componentEnable)
  {
    cnfCOMPONENT[tmp].offsetENACmd = IndexENA;
    cnfCOMPONENT[tmp].cntENACmd = cnfCOMPONENT[tmp].initENACmd();
    tmp++;
  }//while
}//INITENACmdCOMPONENT()

/**********************************************
����������
������������� ENA ������ ����������� �� ������ ��
**********************************************/
void INITENACmdCOMPONENT_WL()
{
  IndexENA  = 0;//ENA ������
  short tmp = 0;
  while (cnfCOMPONENT_WL[tmp].componentEnable)
  {
    cnfCOMPONENT_WL[tmp].offsetENACmd = IndexENA;
    cnfCOMPONENT_WL[tmp].cntENACmd = cnfCOMPONENT_WL[tmp].initENACmd();
    tmp++;
  }//while
}//INITENACmdCOMPONENT_WL()

/**********************************************
����������
���������� ������� ����������� ��� ���� �� ������
**********************************************/
void PREPAREustCOMPONENT(short total)
{
  short next = 0;
  setTimerENABLE(0 ,0);//bazisTimerMem[0].ENABLE = 0;//��������� ��� �������
  while (cnfCOMPONENT[next].componentEnable)   //��� ���������� � ������������
  {
    switch(total)
    {
    case INITUST_ALLCOMP:   //���������� ������� ��� ����
        {
        cnfCOMPONENT[next].prepareUstSpv(next);
        }
        break;

//    case  INITUST_NULLCOMP:
      //������� �� ����������������
  //    break;
    default:
      ;
    }//switch
    next++;
  }//while

  //�������������� ������� ����� ����������
  if(total>=INITUST_TOPCOMP)
  {
    cnfCOMPONENT[total].prepareUstSpv(total);
    //������������� �������� ���� ����������� �� ������
  }//if

}//PREPAREustCOMPONENT()

/**********************************************
����������
���������� ������� ����������� ��� ���� �� ������ ��
**********************************************/
void PREPAREustCOMPONENT_WL(short total)
{
  short next = 0;
  setTimerENABLE_WL(0 ,0);//bazisTimerMem[0].ENABLE = 0;//��������� ��� ������� ��
  while (cnfCOMPONENT_WL[next].componentEnable)   //��� ���������� � ������������
  {
    switch(total)
    {
    case INITUST_ALLCOMP:   //���������� ������� ��� ����
        {
        cnfCOMPONENT_WL[next].prepareUstSpv(-next-1);
        }
        break;

//    case  INITUST_NULLCOMP:
      //������� �� ����������������
  //    break;
    default:
      ;
    }//switch
    next++;
  }//while

  //�������������� ������� ����� ����������
  if(total>=INITUST_TOPCOMP)
  {
    cnfCOMPONENT_WL[total].prepareUstSpv(-total-1);
    //������������� �������� ���� ����������� �� ������
  }//if

}//PREPAREustCOMPONENT_WL()

/**********************************************
����������
�������� ��������� � ������������
numK - ��� ����������
**********************************************/
void addCOMPONENT(short numK)
{
//������ ������ - ������������
  short rpzOffset = GetOffsetClonRpz(numK);//�������� �������� ����������� �� ���� ����������

  LIGHTISDENIE = 0;//���������
  LIGHTISPACKET = 0;//��� �����
//���������� � ����
  memcpy((void*)getShadowBuf(), cnfCOMPONENT, sizeof(COMPONENT_OBJ)*MAX_CNFCOMPONENT);
  //������� ����� ����
  char isPacket = rpzCOMPONENT[rpzOffset].load2RPZ(0);//���������������� � �����������
  if(isPacket)
  {
    LIGHTISDENIE = 0;//���������
    LIGHTISPACKET = 1;//��� �����
    return;// 1;//���� ���� �������� �����������
  }//if

  //������ � ������������ ���� ����������
  short i=0;
  short numC=0;

  while(cnfCOMPONENT[i].componentEnable) //��� ����� �� ������
  {
    if(cnfCOMPONENT[i].kodC == rpzcomponent_obj.kodC) numC++;
    i++;
  }//while

  if(numC>0 && rpzcomponent_obj.cntClon == 1)
  {
    LIGHTISPACKET = 0;//��� �����
    LIGHTISDENIE = 1;//���������
    return;// 1;//�������� ������ 1 ����
  }//if
  if(numC>0 && rpzcomponent_obj.cntClon == numC)
  {
    LIGHTISPACKET = 0;//��� �����
    LIGHTISDENIE = 1;//���������
    return;//�������� ������ numClon ����
  }//if

  memcpy(&(cnfCOMPONENT[0]), &rpzcomponent_obj, sizeof(COMPONENT_OBJ));

//���������� �� ����
  memcpy(&(cnfCOMPONENT[1]), (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(MAX_CNFCOMPONENT-1));

}//addCOMPONENT

/**********************************************
����������
�������� ��������� � ������������ ��
numK - ��� ����������
**********************************************/
void addCOMPONENT_WL(short numK)
{
//������ ������ - ������������
  short rpzOffset = GetOffsetClonRpzWL(numK);//�������� �������� ����������� �� �� ���� ����������

  LIGHTISDENIE = 0;//���������
  LIGHTISPACKET = 0;//��� �����
//���������� � ����
  memcpy((void*)getShadowBuf(), cnfCOMPONENT_WL, sizeof(COMPONENT_OBJ)*MAX_WLCOMPONENT);
  //������� ����� ����
  char isPacket = rpzCOMPONENT_WL[rpzOffset].load2RPZ(0);//���������������� � ����������� ��
  if(isPacket)
  {
    LIGHTISDENIE = 0;//���������
    LIGHTISPACKET = 1;//��� �����
    return;// 1;//���� ���� �������� �����������
  }//if

  //������ � ������������ ���� ����������
  short i=0;
  short numC=0;

  while(cnfCOMPONENT_WL[i].componentEnable) //��� ����� �� ������
  {
    if(cnfCOMPONENT_WL[i].kodC == rpzcomponent_obj.kodC) numC++;
    i++;
  }//while

  if(numC>0 && rpzcomponent_obj.cntClon == 1)
  {
    LIGHTISPACKET = 0;//��� �����
    LIGHTISDENIE = 1;//���������
    return;// 1;//�������� ������ 1 ����
  }//if
  if(numC>0 && rpzcomponent_obj.cntClon == numC)
  {
    LIGHTISPACKET = 0;//��� �����
    LIGHTISDENIE = 1;//���������
    return;//�������� ������ numClon ����
  }//if

  memcpy(&(cnfCOMPONENT_WL[0]), &rpzcomponent_obj, sizeof(COMPONENT_OBJ));

//���������� �� ����
  memcpy(&(cnfCOMPONENT_WL[1]), (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(MAX_WLCOMPONENT-1));

}//addCOMPONENT_WL

/**********************************************
����������
���������������� ��������� � ������������
total - INITUST_TOPCOMP-������ ������� INITUST_ALLCOMP-���
        INITUST_NULLCOMP-�� ������
**********************************************/
void initCOMPONENT(short total)
{
  INITIOCmdCOMPONENT();//���������� ���� IO ������ ����������� �� ������
  INITTLCmdCOMPONENT();//���������� ���� TL ������ ����������� �� ������
  INITustrangCOMPONENT(total);//���������� ������������� mngUst mngRang ����������� �� ������
  INITENACmdCOMPONENT();//����������  ������������� ENA ������ ����������� �� ������
}//initCOMPONENT(short total)

/**********************************************
����������
���������������� ��������� � ������������ ��
total - INITUST_TOPCOMP-������ ������� INITUST_ALLCOMP-���
        INITUST_NULLCOMP-�� ������
**********************************************/
void initCOMPONENT_WL(short total)
{
  INITIOCmdCOMPONENT_WL();//���������� ���� IO ������ ����������� �� ������ ��
  INITTLCmdCOMPONENT_WL();//���������� ���� TL ������ ����������� �� ������ ��
  INITustrangCOMPONENT_WL(total);//���������� ������������� mngUst mngRang ����������� �� ������ ��
  INITENACmdCOMPONENT_WL();//����������  ������������� ENA ������ ����������� �� ������ ��
}//initCOMPONENT_WL(short total)

/**********************************************
����������
������� cntC ������ ������� � ������������� �����
**********************************************/
void deleteCOMPONENT(short cntC)
{
//������� ���� ����������
  short  offsetUstMng = cnfCOMPONENT[LIGHTCLON].offsetUstMng;  //�������� ������� ������ ��������� �������
  short  offsetRangIO = getOffsetIOCmdCnf(LIGHTCLON);   //�������� ������ IO
  short  offsetTL     = getOffsetTLCmdCnf(LIGHTCLON);   //�������� ������ TL
  short  offsetENA    = getOffsetENACmdCnf(LIGHTCLON);  //�������� ������ ENA
//����� �-�� ������� ���� � TL log ��� ��������
  short  cntUstMng  = 0;
  short  cntRangMng = 0;
  short  cntTL      = 0;
  short  cntENA     = 0;
  for(short i=0; i<cntC; i++)
  {
    cntUstMng  += cnfCOMPONENT[LIGHTCLON+i].cntUstMng;    //���������� ������� ���������� ������ ��������� �������
    cntRangMng += cnfCOMPONENT[LIGHTCLON+i].cntIOCmd;     //���������� ������ IO
    cntTL      += cnfCOMPONENT[LIGHTCLON+i].cntTLCmd;     //���������� ������ TL
    cntENA     += cnfCOMPONENT[LIGHTCLON+i].cntENACmd;    //���������� ������ ENA
  }//for

//������ ������ - ������������
//���������� � ����
  memcpy((void*)getShadowBuf(), cnfCOMPONENT, sizeof(COMPONENT_OBJ)*MAX_CNFCOMPONENT);
//���������� �� ���� Begin
  if(LIGHTCLON>0)
    memcpy(cnfCOMPONENT, (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(LIGHTCLON));
//���������� �� ���� End
  memcpy(&(cnfCOMPONENT[LIGHTCLON]),
         &(((COMPONENT_OBJ *)getShadowBuf())[LIGHTCLON+ cntC]),
         sizeof(COMPONENT_OBJ)*(MAX_CNFCOMPONENT-LIGHTCLON- cntC));

  if(cntUstMng>0)MngUstDeleteUSTAVKI(offsetUstMng, cntUstMng);//������� ������� �� mngUst
  MngRangDeleteNameStatusRANGIR(offsetRangIO, cntRangMng);//������� �������
  if(cntTL>0)DeleteTEMPLOGIC(offsetTL, cntTL);
  if(cntENA>0)DeleteENACmd(offsetENA, cntENA);
  for(short i=0; i<UVV_TOTAL; i++)
  {
    MngRangDeleteQuadroRANGIR(&(ArrayRANGIR[i*DQUADRO]), offsetRangIO, cntRangMng);//������� ������� �� Quadro
  }//for

  initCOMPONENT(INITUST_NULLCOMP);//������� �� ����������������
}//deleteCOMPONENT()

/**********************************************
����������
������� �� �� cntC ������ ������� � ������������� �����
**********************************************/
void deleteCOMPONENT_WL(short cntC)
{
//������� ���� ����������
  short  offsetUstMng = cnfCOMPONENT_WL[LIGHTCLON].offsetUstMng;  //�������� ������� ������ ��������� �������
  short  offsetRangIO = getOffsetIOCmdCnf_WL(LIGHTCLON);   //�������� ������ IO
  short  offsetTL     = getOffsetTLCmdCnf_WL(LIGHTCLON);   //�������� ������ TL
  short  offsetENA    = getOffsetENACmdCnf_WL(LIGHTCLON);  //�������� ������ ENA
//����� �-�� ������� ���� � TL log ��� ��������
  short  cntUstMng  = 0;
  short  cntRangMng = 0;
  short  cntTL      = 0;
  short  cntENA     = 0;
  for(short i=0; i<cntC; i++)
  {
    cntUstMng  += cnfCOMPONENT_WL[LIGHTCLON+i].cntUstMng;    //���������� ������� ���������� ������ ��������� �������
    cntRangMng += cnfCOMPONENT_WL[LIGHTCLON+i].cntIOCmd;     //���������� ������ IO
    cntTL      += cnfCOMPONENT_WL[LIGHTCLON+i].cntTLCmd;     //���������� ������ TL
    cntENA     += cnfCOMPONENT_WL[LIGHTCLON+i].cntENACmd;    //���������� ������ ENA
  }//for

//������ ������ - ������������
//���������� � ����
  memcpy((void*)getShadowBuf(), cnfCOMPONENT_WL, sizeof(COMPONENT_OBJ)*MAX_WLCOMPONENT);
//���������� �� ���� Begin
  if(LIGHTCLON>0)
    memcpy(cnfCOMPONENT_WL, (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(LIGHTCLON));
//���������� �� ���� End
  memcpy(&(cnfCOMPONENT_WL[LIGHTCLON]),
         &(((COMPONENT_OBJ *)getShadowBuf())[LIGHTCLON+ cntC]),
         sizeof(COMPONENT_OBJ)*(MAX_WLCOMPONENT-LIGHTCLON- cntC));

  if(cntUstMng>0)MngUstDeleteUSTAVKI_WL(offsetUstMng, cntUstMng);//������� ������� �� mngUst
  MngRangDeleteNameStatusRANGIR_WL(offsetRangIO, cntRangMng);//������� �������
  if(cntTL>0)DeleteTEMPLOGIC_WL(offsetTL, cntTL);
  if(cntENA>0)DeleteENACmd_WL(offsetENA, cntENA);

  initCOMPONENT_WL(INITUST_NULLCOMP);//������� �� ����������������
}//deleteCOMPONENT_WL()

void * getShadowBuf()
{
  //����� �������� �������
  return &(common_shadow[0]);
}//getShadowBuf()

void TopAddTEMPLOGIC(short cntTL)
{
//�������� TL log �� ������� tempLog
  //���������� tempLog � ����
  memcpy((void*)getShadowBuf(), tempLog, 4*MAX_TEMPLOG);
  //���������� �� ����
  memcpy(&(tempLog[cntTL]), (void*)getShadowBuf(),
         (4*MAX_TEMPLOG-4*cntTL));
  //��������
  memset(tempLog, 0, 4*cntTL);
}//TopAddTEMPLOGIC()

void TopAddTEMPLOGIC_WL(short cntTL)
{
//�������� TL log �� ������� tempLog_WL
  //���������� tempLog_WL � ����
  memcpy((void*)getShadowBuf(), tempLog_WL, 4*MAX_TEMPLOG_WL);
  //���������� �� ����
  memcpy(&(tempLog_WL[cntTL]), (void*)getShadowBuf(),
         (4*MAX_TEMPLOG_WL-4*cntTL));
  //��������
  memset(tempLog_WL, 0, 4*cntTL);
}//TopAddTEMPLOGIC_WL()

void TopAddENACmd(short cntENA)
{
//�������� ENA �� ������� ENAcmd
  //���������� tempLog � ����
  memcpy((void*)getShadowBuf(), ENAcmd, 4*MAX_ENACMD);
  //���������� �� ����
  memcpy(&(ENAcmd[cntENA]), (void*)getShadowBuf(),
         (4*MAX_ENACMD-4*cntENA));
  //��������
  memset(ENAcmd, 0, 4*cntENA);
}//TopAddENACmd(short cntENA)

void TopAddENACmd_WL(short cntENA)
{
//�������� ENA �� ������� ENAcmd
  //���������� � ����
  memcpy((void*)getShadowBuf(), ENAcmd_WL, 4*MAX_ENACMD_WL);
  //���������� �� ����
  memcpy(&(ENAcmd_WL[cntENA]), (void*)getShadowBuf(),
         (4*MAX_ENACMD_WL-4*cntENA));
  //��������
  memset(ENAcmd_WL, 0, 4*cntENA);
}//TopAddENACmd_WL(short cntENA)

void DeleteTEMPLOGIC(short offsetTL, short cntTL)
{
//������� ������� TL log
  //���������� ������� ��� ������ � ����
  memcpy((void*)getShadowBuf(), tempLog, 4*MAX_TEMPLOG);
//���������� �� ���� Begin
  if(offsetTL>0)
    memcpy(tempLog, (void*)getShadowBuf(), 4*offsetTL);
//���������� �� ���� End
  memcpy(&(tempLog[offsetTL]),
         &(((char *)getShadowBuf())[4*offsetTL+4*cntTL]),
         (4*MAX_TEMPLOG-4*offsetTL-4*cntTL));
}//DeleteTEMPLOGIC(short offsetTL, short cntTL)

void DeleteTEMPLOGIC_WL(short offsetTL, short cntTL)
{
//������� ������� TL log ��
  //���������� ������� ��� ������ � ����
  memcpy((void*)getShadowBuf(), tempLog_WL, 4*MAX_TEMPLOG_WL);
//���������� �� ���� Begin
  if(offsetTL>0)
    memcpy(tempLog_WL, (void*)getShadowBuf(), 4*offsetTL);
//���������� �� ���� End
  memcpy(&(tempLog_WL[offsetTL]),
         &(((char *)getShadowBuf())[4*offsetTL+4*cntTL]),
         (4*MAX_TEMPLOG_WL-4*offsetTL-4*cntTL));
}//DeleteTEMPLOGIC_WL(short offsetTL, short cntTL)

void DeleteENACmd(short offsetENA, short cntENA)
{
//������� ������� ENA cmd
  //���������� ENA cmd � ����
  memcpy((void*)getShadowBuf(), ENAcmd, 4*MAX_ENACMD);
//���������� �� ���� Begin
  if(offsetENA>0)
    memcpy(ENAcmd, (void*)getShadowBuf(), 4*offsetENA);
//���������� �� ���� End
  memcpy(&(ENAcmd[offsetENA]),
         &(((char *)getShadowBuf())[4*offsetENA+4*cntENA]),
         (4*MAX_ENACMD-4*offsetENA-4*cntENA));
}//DeleteENACmd(short offsetENA, short cntENA)

void DeleteENACmd_WL(short offsetENA, short cntENA)
{
//������� ������� ENA cmd
  //���������� ENA cmd � ����
  memcpy((void*)getShadowBuf(), ENAcmd_WL, 4*MAX_ENACMD_WL);
//���������� �� ���� Begin
  if(offsetENA>0)
    memcpy(ENAcmd_WL, (void*)getShadowBuf(), 4*offsetENA);
//���������� �� ���� End
  memcpy(&(ENAcmd_WL[offsetENA]),
         &(((char *)getShadowBuf())[4*offsetENA+4*cntENA]),
         (4*MAX_ENACMD_WL-4*offsetENA-4*cntENA));
}//DeleteENACmd_WL(short offsetENA, short cntENA)

/**********************************************
����������
������������� �������� ���� ����������� �� ������
**********************************************/
void INITtimersCOMPONENT()
{
  //��������� ��� �������
  setTimerENABLE(0 ,0);
// clearTimerLogBuffer
  memset(elTrgOldTimer,0,4*MAX_LOGTIMER);//EL ��������
  memset(elTrgOutTimer,0,4*MAX_LOGTIMER);//EL ��������
  memset(logMassTimer, 0,4*MAX_LOGTIMER);//������ �������

  IndexTIMERS = 0;//��������� ������
  short tmp = 0;
  while (cnfCOMPONENT[tmp].componentEnable)
  {
    cnfCOMPONENT[tmp].offsetTimers = IndexTIMERS;
    cnfCOMPONENT[tmp].initTimers(tmp);
    tmp++;
  }//while
  setTimerENABLE(IndexTIMERS ,0);//���� ��������� ������
}//INITtimersCOMPONENT()

/**********************************************
����������
������������� �������� ���� ����������� �� ������ ��
**********************************************/
void INITtimersCOMPONENT_WL()
{
  setTimerENABLE_WL(0 ,0);
// clearTimerLogBuffer
  memset(elTrgOldTimer_WL,0,4*MAX_LOGTIMER_WL);//EL ��������
  memset(elTrgOutTimer_WL,0,4*MAX_LOGTIMER_WL);//EL ��������
  memset(logMassTimer_WL, 0,4*MAX_LOGTIMER_WL);//������ �������

  timerEnableWL = 0;//���������� ������ �������� ��
  IndexTIMERS = 0;//��������� ������
  short tmp = 0;
  while (cnfCOMPONENT_WL[tmp].componentEnable)
  {
    cnfCOMPONENT_WL[tmp].offsetTimers = IndexTIMERS;
    cnfCOMPONENT_WL[tmp].initTimers(-tmp-1);
    tmp++;
  }//while
  setTimerENABLE_WL(IndexTIMERS ,0);//���� ��������� ������
}//INITtimersCOMPONENT()

int getOffsetTimersCnf(int off)
{
//������� ���������� � ������������
  return cnfCOMPONENT[off].offsetTimers;   
}//getOffsetTimersCnf(int off)

int getOffsetTimersCnf_WL(int off)
{
//������� ���������� � ������������
  return cnfCOMPONENT_WL[-off-1].offsetTimers;   
}//getOffsetTimersCnf(int off)

int getOffsetIOCmdCnf(int off)
{
 //IO �������
 return cnfCOMPONENT[off].offsetIOCmd;   
}//getOffsetIOCmdCnf(int off)

int getOffsetIOCmdCnf_WL(int off)
{
 //IO �������
 return cnfCOMPONENT_WL[off].offsetIOCmd;   
}//getOffsetIOCmdCnf_WL(int off)

int getOffsetENACmdCnf(int off)
{
//ENA �������
  return cnfCOMPONENT[off].offsetENACmd;    
}//getOffsetENACmdCnf(int off)

int getOffsetENACmdCnf_WL(int off)
{
//ENA ������� ��
  return cnfCOMPONENT_WL[off].offsetENACmd;    
}//getOffsetENACmdCnf_WL(int off)

int getOffsetTLCmdCnf(int off)
{
//TL �������
  return cnfCOMPONENT[off].offsetTLCmd;    
}//getOffsetTLCmdCnf(int off)

int getOffsetTLCmdCnf_WL(int off)
{
//TL �������
  return cnfCOMPONENT_WL[off].offsetTLCmd;    
}//getOffsetTLCmdCnf_WL(int off)

int getOffsetSPVUstCnf(int off)
{
//������� SPV
  return cnfCOMPONENT[off].offsetUstSpv;    
}//getOffsetSPVUstCnf(int off)
