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
#include "psuperVisor\supermanager.h"
#include "virtualMenu\systemmenudef.h"
#include "component\componentdef.h"
#include "virtualMenu\rangmanagerdef.h"

#include "logictimers\logictimersfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\wideLogManagerfnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "SettingIci\SettingIci.h"

#include "virtualMenu\viewMenuCnf.h"
#include "psuperVisor\psupervisor.h"

#include "toSpeedOptim.h"

extern MaskaOTAPVUROVOFcmd struct_maskaOTAPVUROVOFcmd;//����� ��� 16 ����� ������� UROV APV OT
extern MaskaOTcmd struct_maskaOTcmd;

extern UNS_32 pAPVcmdMaska[];//����������� ��������� 
extern UNS_32 pUROVcmdMaska[];//����������� ���������� 


extern UNS_32 pRDIScmdMaska[];//��������������
extern COMPONENT_OBJ  cnfCOMPONENT[];//������������

//������ ������������
/*
 ��������� ������� ������������
DV1   ... DV_TOTAL
RELE1 ... RELE_TOTAL
CDI1  ... CDI_TOTAL
*/
UNS_32 ArrayRANGIR[MAX_MNGRANG+1];//���� CRC ��� EEPROM

//������ ���� � ������� ������������ ���� ����� ����������� ������
IONAMESTATUS_RANGIR  nameStatusRANGIR[SIZE_RANGIRCMD+SIZE_RANGIRCMD+3];
//������� ��� ������ ���� ������ ������
int   WideCmdBuffer[SIZE_RANGIRCMD+SIZE_RANGIRCMD+3];

//������� ��� ������ RT
int   WideCmdRTBuffer[SIZE_RANGIRCMD+3];
//������� ��� ������ RT INTERFACE
int   WideCmdINTERFACE_RTBuffer[SIZE_RANGIRCMD+3];

UNS_32 pActualCMD[2*DQUADRO];//������� ���� ������ ������

UNS_32 pActualCMD_INTERFACE[DQUADRO];//������� INTERFACE

/**********************************************
�������� ������������
������� ������� �� Quadro
offsetRangMng - �������� ������
cntRangMng - �-�� ������
**********************************************/
void MngRangDeleteQuadroRANGIR(UNS_32 *pQuadro, short offsetRangMng, short cntRangMng)
{
//������� �������
  TranslateQuadroToWideCmd(pQuadro);//���������� Quadro � ������� ��� ������
  //���������� ������� ��� ������ � ����
  memcpy((void*)getShadowBuf(), WideCmdBuffer, 4*SIZE_RANGIRCMD);
//���������� �� ���� Begin
  if(offsetRangMng>0)
    memcpy(WideCmdBuffer, (void*)getShadowBuf(), 4*offsetRangMng);
//���������� �� ���� End
  memcpy(&(WideCmdBuffer[offsetRangMng]),
         &(((char *)getShadowBuf())[4*offsetRangMng+4*cntRangMng]),
         (4*SIZE_RANGIRCMD-4*offsetRangMng-4*cntRangMng));
  //�������� ������� ��� �����
  memset(&(WideCmdBuffer[SIZE_RANGIRCMD-cntRangMng]), 0, 4*cntRangMng);
  CompressorToQuadro(WideCmdBuffer, pQuadro);//���������� �������

}//MngRangDeleteQuadroRANGIR(short offsetRangMng, short cntRangMng)

/**********************************************
�������� ������������
�������� ������� � Quadro
cntRangMng - �-�� ������
**********************************************/
void MngRangTopAddQuadroRANGIR(UNS_32 *pQuadro, short cntRangMng)
{
//�������� ������� �� ������� Quadro
  TranslateQuadroToWideCmd(pQuadro);//���������� Quadro � ������� ��� ������
  //���������� ������� ��� ������ � ����
  memcpy((void*)getShadowBuf(), WideCmdBuffer, 4*SIZE_RANGIRCMD);
  //���������� �� ����
  memcpy(&(WideCmdBuffer[cntRangMng]), (void*)getShadowBuf(),
         (4*SIZE_RANGIRCMD-4*cntRangMng));
  //�������� ������� ��� �����
  memset(WideCmdBuffer, 0, 4*cntRangMng);
  CompressorToQuadro(WideCmdBuffer, pQuadro);//���������� �������
}//MngRangTopAddRANGIR(short cntRangMng)

/**********************************************
�������� ������������
�������� ��� ArrayRANGIR ����� ��� ��� ��������������
**********************************************/
UNS_32 * MngRangGetPointerUVVRANGIRtoEdit(int numUVV)
{
  if(numUVV<0) return (UNS_32 *)getShadowBuf();
  
  return  &(((UNS_32 *)getShadowBuf())[
              numUVV*DQUADRO]);
}//MngRangGetPointerUVVRANGIRtoEdit(int numUVV)

/**********************************************
�������� ������������
����������� ArrayRANGIR � ��������������
**********************************************/
void MngRangPrepareArrayRANGIRtoEdit(int numUVV)
{
  switch(numUVV)
  {
   case REGDIS_SM: //��������������
    //���������� � ����
    memcpy((void*)getShadowBuf(), pRDIScmdMaska, DQUADRO*4);
    return;
   case PUSKAPV_SM://����������� ��������� 
    memcpy((void*)getShadowBuf(), pAPVcmdMaska, DQUADRO*4);
    return;
   case PUSKUROV_SM://����������� ����������
    memcpy((void*)getShadowBuf(), pUROVcmdMaska, DQUADRO*4);
    return;
/*
   case PUSK1OF_SM://����������� ������1��
    memcpy((void*)getShadowBuf(), pP1OFcmdMaska, DQUADRO*4);
    return;
   case PUSK2OF_SM://����������� ������2��
    memcpy((void*)getShadowBuf(), pP2OFcmdMaska, DQUADRO*4);
    return;
   case PUSK3OF_SM://����������� ������3��
    memcpy((void*)getShadowBuf(), pP3OFcmdMaska, DQUADRO*4);
    return;
*/
  }//switch
  //���������� � ����
  memcpy((void*)getShadowBuf(), ArrayRANGIR, MAX_MNGRANG*4);
}//

/**********************************************
�������� ������������
��������� ������������� ArrayRANGIR
**********************************************/
void MngRangEndingEditArrayRANGIR(int numUVV)
{
  switch(numUVV)
  {
   case REGDIS_SM: //��������������
    //���������� �� ����
    memcpy(pRDIScmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return;
   case PUSKAPV_SM://����������� ��������� 
    memcpy(pAPVcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return;
   case PUSKUROV_SM://����������� ����������
    memcpy(pUROVcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return;
/*
   case PUSK1OF_SM://����������� ������1��
    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return;
   case PUSK2OF_SM://����������� ������2��
    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return;
   case PUSK3OF_SM://����������� ������3��
    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return;
*/
  }//switch

  //���������� �� ����
  memcpy(ArrayRANGIR, (void*)getShadowBuf(), MAX_MNGRANG*4);
}//

/**********************************************
�������� ������������
������� ������� �� nameStatus
offsetRangMng - �������� ������
cntRangMng - �-�� ������
**********************************************/
void MngRangDeleteNameStatusRANGIR(short offsetRangMng, short cntRangMng)
{
//������� �������
  //���������� � ����
  memcpy((void*)getShadowBuf(), nameStatusRANGIR, sizeof(IONAMESTATUS_RANGIR)*SIZE_RANGIRCMD);
//���������� �� ���� Begin
  if(offsetRangMng>0)
    memcpy(nameStatusRANGIR, (void*)getShadowBuf(), sizeof(IONAMESTATUS_RANGIR)*offsetRangMng);
//���������� �� ���� End
  memcpy(&(nameStatusRANGIR[offsetRangMng]),
         &(((IONAMESTATUS_RANGIR *)getShadowBuf())[offsetRangMng+cntRangMng]),
         sizeof(IONAMESTATUS_RANGIR)*(SIZE_RANGIRCMD-offsetRangMng-cntRangMng));
}//MngRangDeleteNameStatusRANGIR(short offsetRangMng, short cntRangMng)

/**********************************************
�������� ������������ ��
������� ������� �� nameStatus
offsetRangMng - �������� ������
cntRangMng - �-�� ������
**********************************************/
void MngRangDeleteNameStatusRANGIR_WL(short offsetRangMng, short cntRangMng)
{
//������� �������
  //���������� � ����
  memcpy((void*)getShadowBuf(), &(nameStatusRANGIR[SIZE_RANGIRCMD]), sizeof(IONAMESTATUS_RANGIR)*SIZE_RANGIRCMD);
//���������� �� ���� Begin
  if(offsetRangMng>0)
    memcpy(&(nameStatusRANGIR[SIZE_RANGIRCMD]), (void*)getShadowBuf(), sizeof(IONAMESTATUS_RANGIR)*offsetRangMng);
//���������� �� ���� End
  memcpy(&(nameStatusRANGIR[offsetRangMng +SIZE_RANGIRCMD]),
         &(((IONAMESTATUS_RANGIR *)getShadowBuf())[offsetRangMng+cntRangMng]),
         sizeof(IONAMESTATUS_RANGIR)*(SIZE_RANGIRCMD-offsetRangMng-cntRangMng));
}//MngRangDeleteNameStatusRANGIR_WL(short offsetRangMng, short cntRangMng)

/**********************************************
�������� ������������
�������� ����� ������
cntRangMng - �-�� ������
**********************************************/
void MngRangTopAddNameStatusRANGIR(short cntRangMng, void *ionsComp)
{
//�������� ������� �� ������� mngRang
  //���������� � ����
  memcpy((void*)getShadowBuf(), nameStatusRANGIR, sizeof(IONAMESTATUS_RANGIR)*SIZE_RANGIRCMD);
  //���������� �� ����
  memcpy(&(nameStatusRANGIR[cntRangMng]), (void*)getShadowBuf(),
         sizeof(IONAMESTATUS_RANGIR)*(SIZE_RANGIRCMD-cntRangMng));
  //����������
  for(short i=0; i<cntRangMng; i++)
  {
    //���������� ������
    nameStatusRANGIR[i].statusIO = ((IONAMESTATUS_COMPONENT *)ionsComp)[i].statusIO;
    //���������� ����� ����� �������
    if(strlen(((IONAMESTATUS_COMPONENT *)ionsComp)[i].nameIO)>SIZE_NAMEIOCOMMAND)
                ((IONAMESTATUS_COMPONENT *)ionsComp)[i].nameIO[SIZE_NAMEIOCOMMAND-2] = 0;
    //���������� ��� �������
    strcpy(nameStatusRANGIR[i].nameIORang, ((IONAMESTATUS_COMPONENT *)ionsComp)[i].nameIO);
  }//for
}//MngRangTopAddNameStatusRANGIR(short cntRangMng, void *ionsComp)

/**********************************************
�������� ������������
�������� ����� ������ ��
cntRangMng - �-�� ������
**********************************************/
void MngRangTopAddNameStatusRANGIR_WL(short cntRangMng, void *ionsComp)
{
//�������� ����� ������ �� �������
  //���������� � ����
  memcpy((void*)getShadowBuf(), &(nameStatusRANGIR[SIZE_RANGIRCMD]), sizeof(IONAMESTATUS_RANGIR)*SIZE_RANGIRCMD);
  //���������� �� ����
  memcpy(&(nameStatusRANGIR[cntRangMng +SIZE_RANGIRCMD]), (void*)getShadowBuf(),
         sizeof(IONAMESTATUS_RANGIR)*(SIZE_RANGIRCMD-cntRangMng));
  //����������
  for(short i=0; i<cntRangMng; i++)
  {
    nameStatusRANGIR[i +SIZE_RANGIRCMD].statusIO = ((IONAMESTATUS_COMPONENT *)ionsComp)[i].statusIO;
    //�������� �������
    strcpy(nameStatusRANGIR[i +SIZE_RANGIRCMD].nameIORang, "��:");
    strcat(nameStatusRANGIR[i +SIZE_RANGIRCMD].nameIORang, ((IONAMESTATUS_COMPONENT *)ionsComp)[i].nameIO);
  }//for
}//MngRangTopAddNameStatusRANGIR_WL(short cntRangMng, void *ionsComp)

short SetCmdToUVV(short kodC, short numClon, short numIO, short numUVV)
{
//������ ������� numIO ���������� kodC � ������� ����� numClon �� numUVV
  short idxClon = SearchCnfClonToComponent(kodC, numClon);
  if(idxClon<0)return 1;//���� �� ������
  int cntIO = cnfCOMPONENT[idxClon].cntIOCmd;    //�-�� IO ������
  if(numIO<0) return 1;//������� ������ 0
  if(numIO>=cntIO) return 1;//������� �� ����������
  short idxCmd = getOffsetIOCmdCnf(idxClon) + numIO;//������ �������

  short conflict = SetUVVToClon(idxCmd, numUVV);
  SaveCRCrang();//��������� CRC ������
  PrepareBOBV();//����������� ���� ����, ���� ���
  return conflict;
}//SetCmdToUVV(short kodC, short numClon, short numIO, short numUVV)
/*
void ClrCmdToClon(short kodC, short numClon, short numIO, short numUVV)
{
//������ ������� numIO ���������� kodC � ������� ����� numClon �� numUVV
  short idxClon = SearchCnfClonToComponent(kodC, numClon);
  if(idxClon<0)return;//���� �� ������
  short idxCmd = getOffsetIOCmdCnf(idxClon) + numIO;//������ �������

  ClrUVVToClon(idxCmd, numUVV);
}//ClrCmdToClon(short kodC, short numClon, short numIO, short numUVV)
*/

/*
void ClrUVVToClon(int idxCmd, int numUVV)
{
  MngRangPrepareArrayRANGIRtoEdit(numUVV);//����������� ArrayRANGIR � ��������������

  NumBitClearingQuadro(idxCmd,
                       MngRangGetPointerUVVRANGIRtoEdit(numUVV)
                      ); //����� ���� �� ��� �������

  MngRangEndingEditArrayRANGIR(numUVV);//��������� ������������� ArrayRANGIR
}//ClrUVVToClon(idxCmd, numUVV)
*/

short SetUVVToClon(int idxCmd, int numUVV)
{
//  MngRangPrepareArrayRANGIRtoEdit(numUVV);//����������� ArrayRANGIR � ��������������

  NumBitSettingQuadro(idxCmd,
                      MngRangGetPointerUVVRANGIRtoRead(numUVV)
                     ); //��������� ���� �� ��� �������
  short isConflict = ApplyDVMaskToRead(numUVV);//�������� ����� �� DV

//  MngRangEndingEditArrayRANGIR(numUVV);//��������� ������������� ArrayRANGIR
  return isConflict;//���������� �������� ����������
}//SetUVVToClon(idxCmd, numUVV)

void ClearArrayRANGIR()
{
//�������� ��� ������������
  memset(ArrayRANGIR, 0, MAX_MNGRANG*4);
}//ClearArrayRANGIR()

void SaveCRCrang()
{
//��������� CRC ������
  ArrayRANGIR[MAX_MNGRANG] = setCRCMassiv((int *)ArrayRANGIR, MAX_MNGRANG); //CRC ��� ����
}//SaveCRCrang()

int getCRCrang()
{
//�������� CRC ����
  return ArrayRANGIR[MAX_MNGRANG]; //CRC ��� ����
}//getCRCrang()

//extern MaskaOTAPVUROVOFcmd struct_maskaOTAPVUROVOFcmd;//����� ��� 16 ����� ������� UROV APV OT

/**********************************************
�������� ������������
�������� ��� ArrayRANGIR ����� ��� ��� ������
**********************************************/
UNS_32 * MngRangGetPointerUVVRANGIRtoRead(int numUVV)
{
  switch(numUVV)
  {
   case REGDIS_SM: //��������������
//    pRDIScmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return pRDIScmdMaska;
   case PUSKAPV_SM://����������� ��������� 
//    memcpy(pAPVcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return pAPVcmdMaska;
   case PUSKUROV_SM://����������� ����������
//    memcpy(pUROVcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return pUROVcmdMaska;

   case PUSK1OF_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OFcmdMaska;
   case PUSK2OF_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OFcmdMaska;
   case PUSK3OF_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OFcmdMaska;

   case PUSK1OF2_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF2cmdMaska;
   case PUSK2OF2_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF2cmdMaska;
   case PUSK3OF2_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF2cmdMaska;

   case PUSK1OF3_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF3cmdMaska;
   case PUSK2OF3_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF3cmdMaska;
   case PUSK3OF3_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF3cmdMaska;

   case PUSK1OF4_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF4cmdMaska;
   case PUSK2OF4_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF4cmdMaska;
   case PUSK3OF4_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF4cmdMaska;

   case PUSK1OF5_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF5cmdMaska;
   case PUSK2OF5_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF5cmdMaska;
   case PUSK3OF5_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF5cmdMaska;

   case PUSK1OF6_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF6cmdMaska;
   case PUSK2OF6_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF6cmdMaska;
   case PUSK3OF6_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF6cmdMaska;

   case PUSK1OF7_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF7cmdMaska;
   case PUSK2OF7_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF7cmdMaska;
   case PUSK3OF7_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF7cmdMaska;

   case PUSK1OF8_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF8cmdMaska;
   case PUSK2OF8_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF8cmdMaska;
   case PUSK3OF8_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF8cmdMaska;

   case PUSK1OF9_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF9cmdMaska;
   case PUSK2OF9_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF9cmdMaska;
   case PUSK3OF9_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF9cmdMaska;

   case PUSK1OF10_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF10cmdMaska;
   case PUSK2OF10_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF10cmdMaska;
   case PUSK3OF10_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF10cmdMaska;

   case PUSK1OF11_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF11cmdMaska;
   case PUSK2OF11_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF11cmdMaska;
   case PUSK3OF11_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF11cmdMaska;

   case PUSK1OF12_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF12cmdMaska;
   case PUSK2OF12_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF12cmdMaska;
   case PUSK3OF12_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF12cmdMaska;

   case PUSK1OF13_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF13cmdMaska;
   case PUSK2OF13_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF13cmdMaska;
   case PUSK3OF13_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF13cmdMaska;

   case PUSK1OF14_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF14cmdMaska;
   case PUSK2OF14_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF14cmdMaska;
   case PUSK3OF14_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF14cmdMaska;

   case PUSK1OF15_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF15cmdMaska;
   case PUSK2OF15_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF15cmdMaska;
   case PUSK3OF15_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF15cmdMaska;

   case PUSK1OF16_SM://����������� ������1��
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF16cmdMaska;
   case PUSK2OF16_SM://����������� ������2��
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF16cmdMaska;
   case PUSK3OF16_SM://����������� ������3��
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF16cmdMaska;

   case PUSK1OT1_SM://����������� ������1�T1
    return struct_maskaOTcmd.pP1OT1cmdMaska;
   case PUSK2OT1_SM://����������� ������2�T1
    return struct_maskaOTcmd.pP2OT1cmdMaska;
   case PUSK3OT1_SM://����������� ������2�T1
    return struct_maskaOTcmd.pP3OT1cmdMaska;
   case PUSK4OT1_SM://����������� ������2�T1
    return struct_maskaOTcmd.pP4OT1cmdMaska;

   case PUSK1OT2_SM://����������� ������1�T2
    return struct_maskaOTcmd.pP1OT2cmdMaska;
   case PUSK2OT2_SM://����������� ������2�T2
    return struct_maskaOTcmd.pP2OT2cmdMaska;
   case PUSK3OT2_SM://����������� ������2�T2
    return struct_maskaOTcmd.pP3OT2cmdMaska;
   case PUSK4OT2_SM://����������� ������2�T2
    return struct_maskaOTcmd.pP4OT2cmdMaska;

   case PUSK1OT3_SM://����������� ������1�T3
    return struct_maskaOTcmd.pP1OT3cmdMaska;
   case PUSK2OT3_SM://����������� ������2�T3
    return struct_maskaOTcmd.pP2OT3cmdMaska;
   case PUSK3OT3_SM://����������� ������2�T3
    return struct_maskaOTcmd.pP3OT3cmdMaska;
   case PUSK4OT3_SM://����������� ������2�T3
    return struct_maskaOTcmd.pP4OT3cmdMaska;

   case PUSK1OT4_SM://����������� ������1�T4
    return struct_maskaOTcmd.pP1OT4cmdMaska;
   case PUSK2OT4_SM://����������� ������2�T4
    return struct_maskaOTcmd.pP2OT4cmdMaska;
   case PUSK3OT4_SM://����������� ������2�T4
    return struct_maskaOTcmd.pP3OT4cmdMaska;
   case PUSK4OT4_SM://����������� ������2�T4
    return struct_maskaOTcmd.pP4OT4cmdMaska;

   case PUSK1OT5_SM://����������� ������1�T5
    return struct_maskaOTcmd.pP1OT5cmdMaska;
   case PUSK2OT5_SM://����������� ������2�T5
    return struct_maskaOTcmd.pP2OT5cmdMaska;
   case PUSK3OT5_SM://����������� ������2�T5
    return struct_maskaOTcmd.pP3OT5cmdMaska;
   case PUSK4OT5_SM://����������� ������2�T5
    return struct_maskaOTcmd.pP4OT5cmdMaska;

   case PUSK1OT6_SM://����������� ������1�T6
    return struct_maskaOTcmd.pP1OT6cmdMaska;
   case PUSK2OT6_SM://����������� ������2�T6
    return struct_maskaOTcmd.pP2OT6cmdMaska;
   case PUSK3OT6_SM://����������� ������2�T6
    return struct_maskaOTcmd.pP3OT6cmdMaska;
   case PUSK4OT6_SM://����������� ������2�T6
    return struct_maskaOTcmd.pP4OT6cmdMaska;

   case PUSK1OT7_SM://����������� ������1�T7
    return struct_maskaOTcmd.pP1OT7cmdMaska;
   case PUSK2OT7_SM://����������� ������2�T7
    return struct_maskaOTcmd.pP2OT7cmdMaska;
   case PUSK3OT7_SM://����������� ������2�T7
    return struct_maskaOTcmd.pP3OT7cmdMaska;
   case PUSK4OT7_SM://����������� ������2�T7
    return struct_maskaOTcmd.pP4OT7cmdMaska;

   case PUSK1OT8_SM://����������� ������1�T8
    return struct_maskaOTcmd.pP1OT8cmdMaska;
   case PUSK2OT8_SM://����������� ������2�T8
    return struct_maskaOTcmd.pP2OT8cmdMaska;
   case PUSK3OT8_SM://����������� ������2�T8
    return struct_maskaOTcmd.pP3OT8cmdMaska;
   case PUSK4OT8_SM://����������� ������2�T8
    return struct_maskaOTcmd.pP4OT8cmdMaska;

  }//switch

  return  &(((UNS_32 *)ArrayRANGIR)[numUVV*DQUADRO]);
}//MngRangGetPointerUVVRANGIRtoRead(int numUVV)

int GetCmdUVVFromClon(short kodC, short numClon, short numIO, short numUVV)
{
//��������� ������� numIO ���������� kodC � ������� ����� numClon �� numUVV
  short idxClon = SearchCnfClonToComponent(kodC, numClon);
  if(idxClon<0)return -1;//���� �� ������
  short idxCmd = getOffsetIOCmdCnf(idxClon) + numIO;//������ �������

  return  NumBitCheckQuadro(idxCmd,
                               MngRangGetPointerUVVRANGIRtoRead(numUVV)
                              ); //��������� ���� �� ��� �������
}//SetUVVToClon(idxCmd, numUVV)

void CopyEEPROMtoRANGIR()
{
//���������� ������ �� EEPROM � ������
extern char  tmp_eeprom[];//MAX_MNGUSTAVKI*4����� *4�����
 memcpy(ArrayRANGIR, tmp_eeprom, 4*(MAX_MNGRANG+1));//��� ������ � CRC
}//CopyMngUstavki(int numBlok)

/*
char ChkUVVToClon(int idxCmd, int numUVV)
{
  MngRangPrepareArrayRANGIRtoEdit(numUVV);//����������� ArrayRANGIR � ��������������

  char tmp = NumBitCheckQuadro(idxCmd,
                               MngRangGetPointerUVVRANGIRtoEdit(numUVV)
                              ); //��������� ���� �� ��� �������

  MngRangEndingEditArrayRANGIR(numUVV);//��������� ������������� ArrayRANGIR
  return tmp;
}//ChkUVVToClon(short idxCmd, short numUVV)
*/
/*
char ChkCmdToClon(short kodC, short numClon, short numIO, short numUVV)
{
//��������� ������� numIO ���������� kodC � ������� ����� numClon �� numUVV
  short idxClon = SearchCnfClonToComponent(kodC, numClon);
  if(idxClon<0)return -1;//���� �� ������
  short idxCmd = getOffsetIOCmdCnf(idxClon) + numIO;//������ �������

  return ChkUVVToClon(idxCmd, numUVV);
}//ClrCmdToClon(short kodC, short numClon, short numIO, short numUVV)
*/
