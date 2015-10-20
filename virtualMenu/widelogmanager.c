/*
#include <vcl.h>
#include <strstrea.h>
#include <math.h>
#include <mem.h>
#include <fstream.h>
#include <strstrea.h>
#include <iomanip.h>
#pragma hdrstop
*/
#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "component\componentdef.h"
#include "virtualMenu\widelogmanagerdef.h"
#include "virtualMenu\systemmenudef.h"

#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\widelogmanagerfnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "psuperVisor\psupervisor.h"
#include "virtualMenu\viewMenuCnf.h"

#include "toSpeedOptim.h"

extern UNS_32 pActualCMD[];//������� ���� ������ ������
extern UNS_32 ArrayRANGIR[];

//������ ����������� ������
/*
 ��������� ������� ����������� ������
LE1
DblOctatPRM
DblOctatMINUS
DblOctatPLUS

LE2
DblOctatPRM
DblOctatMINUS
DblOctatPLUS
..........
*/
//������ DQUADRO ��� ����������� ������, � ������ DQUADRO ��� ����������� ��
UNS_32 ArrayWIDELOG[3*2*DQUADRO*LE_TOTAL];
//��� ��� ��������
//0-����
//1-���
//2-�
//3-���� ���
int    TypLE[LE_TOTAL];
UNS_32 PlusCircleCmd[2*DQUADRO];//��������� ������ �������� ������ LE
UNS_32 InputLECmd[2*DQUADRO];//������� ��������� ������ LE
UNS_32 EXEOutputCmd[2*DQUADRO];//�������� ��������� ������ �����������
UNS_32 *WideLogActual;//������� ��������� ������ ������ ������

/**********************************************
�������� ����������� ������
����������� ArrayWIDELOG � ��������������
**********************************************/
void MngWideLogPrepareArrayWIDELOGtoEdit()
{
  //���������� � ����
  memcpy((void*)getShadowBuf(), ArrayWIDELOG, sizeof(ArrayWIDELOG));
}//MngWideLogPrepareArrayWIDELOGtoEdit()

/**********************************************
�������� ����������� ������
�������� ��� ArrayWIDELOG �������� LE ��� �������������� ������
**********************************************/
UNS_32 * MngWLGetLEWLtoEdit_PRM(int numLE)
{
  return  &(((UNS_32 *)getShadowBuf())[2*DQUADRO*(numLE*3 +0)]);
}//MngWLGetLEWLtoEdit_PRM(int numLE)

/**********************************************
�������� ����������� ������
��������� ������������� ArrayWIDELOG
**********************************************/
void MngWLEndingEditArrayWIDELOG()
{
  //���������� �� ����
  memcpy(ArrayWIDELOG, (void*)getShadowBuf(), sizeof(ArrayWIDELOG));
}//

short SetCmdToLE(short kodC, short numClon, short numIO, short numLE, short typesCmd)
{
//������ ������� numIO ���������� kodC � ������� ����� numClon �� numLE �� ������ typesCmd
  short idxClon = SearchCnfClonToComponent(kodC, numClon);
  if(idxClon<0)return 1;//���� �� ������
  short idxCmd = getOffsetIOCmdCnf(idxClon) + numIO;//������ �������

  MngWideLogPrepareArrayWIDELOGtoEdit();//����������� ArrayWIDELOG � ��������������

  short isConflict = SetLEToClon(idxCmd, numLE, typesCmd);
  MngWLEndingEditArrayWIDELOG();//��������� ������������� ArrayWIDELOG
  return isConflict;
}//SetCmdToClonLE(short kodC, short numClon, short numIO, short numLE, short typesCmd)

short SetCmdToLE_WL(short kodC, short numClon, short numIO, short numLE, short typesCmd)
{
//������ ������� �� ���� �� numIO ���������� kodC � ������� ����� numClon �� numLE �� ������ typesCmd
  short idxClon = SearchCnfClonToComponent_WL(kodC, numClon);
  if(idxClon<0)return 1;//���� �� ������
  short idxCmd = getOffsetIOCmdCnf_WL(idxClon) + numIO;//������ ������� ��

  MngWideLogPrepareArrayWIDELOGtoEdit();//����������� ArrayWIDELOG � ��������������

  short isConflict = SetLEToClon(idxCmd +SIZE_RANGIRCMD, numLE, typesCmd);
  MngWLEndingEditArrayWIDELOG();//��������� ������������� ArrayWIDELOG
  return isConflict;
}//SetCmdToLE_WL(short kodC, short numClon, short numIO, short numLE, short typesCmd)

short SetLEToClon(int idxCmd, int numLE, int typesCmd)
{
//���������� ������� �� LE
  short isConflict = 0;//��������� �����
  UNS_32 *prm =  MngWLGetLEWLtoEdit_PRM(numLE);//������ LE
  //���� �������
  NumBitClearingQuadro(idxCmd,
                       prm
                      ); //����� ���� �� ��� �������
  NumBitClearingQuadro(idxCmd,
                       &(prm[DQUADRO*2])//������
                      ); //����� ���� �� ��� �������
  NumBitClearingQuadro(idxCmd,
                       &(prm[DQUADRO*2+DQUADRO*2])//����
                      ); //����� ���� �� ��� �������

  switch(typesCmd)
  {
  case typeCmd_PRM:
    NumBitSettingQuadro(idxCmd,
                        prm
                       ); //��� ���� �� ��� �������
    break;

  case typeCmd_MINUS:
    NumBitSettingQuadro(idxCmd,
                        &(prm[DQUADRO*2])//������
                       ); //��� ���� �� ��� �������
    break;

  case typeCmd_PLUS:{
    NumBitSettingQuadro(idxCmd,
                        &(prm[DQUADRO*2+DQUADRO*2])//����
                       ); //��� ���� �� ��� �������
    UNS_32 *pplus = &(prm[DQUADRO*2+DQUADRO*2]);
    //�������� ����� ������� ������ LE
    for(int i=0; i<LE_TOTAL; i++){
     if(i==numLE) continue;//������� LE �� ���������
     UNS_32 *prmLE =  MngWLGetLEWLtoEdit_PRM(i);//������ LE
     UNS_32 *pplusLE = &(prmLE[DQUADRO*2+DQUADRO*2]);
     for(int k=0; k<DQUADRO*2; k++) {
          if(pplus[k] & pplusLE[k]) isConflict = 1;//���� ��������
          }//for
     for(int k=0; k<DQUADRO*2; k++) pplus[k] &= ~pplusLE[k];//�������� ����� LE
     }//for
      //�������� ����� DV
      for(int i=0; i<DV_TOTAL; i++){
       UNS_32 *pDV = //MngRangGetPointerUVVRANGIRtoEdit(DV1_SM +i);
          &ArrayRANGIR[(DV1_SM +i)*DQUADRO];
       for(int k=0; k<DQUADRO; k++) pplus[k] &= ~pDV[k];//�������� ����� DV
     }//for
    }//case
    break;
  default:
    ;
  }//switch

  return isConflict;//��������� ����� 
}//SetLEToClon(int idxCmd, UNS_32 *prm, int typesCmd)

short ApplyDVMask(int numUVV)
{
//�������� ����� �� DV
 short isConflict = 0;
    //���� ���� �� ��
    if(!((LIGHTRANGUVV>=DV1_SM) && (LIGHTRANGUVV<(DV1_SM+DV_TOTAL)))) return 0;

//�������� ��� ����� DV
     UNS_32 *pDV = MngRangGetPointerUVVRANGIRtoEdit(numUVV);

    //�������� �����
    for(int i=0; i<LE_TOTAL; i++){
     //�������� LE
     UNS_32 *pplusLE = &ArrayWIDELOG[2*DQUADRO*i*3 +DQUADRO*2+DQUADRO*2];
     for(int k=0; k<DQUADRO; k++) {
          if(pDV[k] & pplusLE[k]) isConflict = 1;//��������� ����� 
          }//for
     for(int k=0; k<DQUADRO; k++) pDV[k] &= ~pplusLE[k];//�������� ����� 
     }//for
  return isConflict;
}//ApplyDVMask(int numUVV)

short ApplyDVMaskToRead(int numUVV)
{
//�������� ����� �� DV
 short isConflict = 0;
    //���� ���� �� ��
//   if(!((LIGHTRANGUVV>=DV1_SM) && (LIGHTRANGUVV<(DV1_SM+DV_TOTAL)))) return 0;
   if(!((numUVV>=DV1_SM) && (numUVV<(DV1_SM+DV_TOTAL)))) return isConflict;

//�������� ��� ����� DV
     UNS_32 *pDV = MngRangGetPointerUVVRANGIRtoRead(numUVV);

    //�������� �����
    for(int i=0; i<LE_TOTAL; i++){
     //�������� LE
     UNS_32 *pplusLE = &ArrayWIDELOG[2*DQUADRO*i*3 +DQUADRO*2+DQUADRO*2];
     for(int k=0; k<DQUADRO; k++) {
          if(pDV[k] & pplusLE[k]) isConflict = 1;//��������� ����� 
          }//for
     for(int k=0; k<DQUADRO; k++) pDV[k] &= ~pplusLE[k];//�������� ����� 
     }//for
  return isConflict;
}//ApplyDVMaskToRead(int numUVV)

void SetTypLE(short numLE, short typesLE)
{
//������ ��� ��� ��������
  TypLE[numLE] = typesLE;
}//SetTypLE(short numLE, short typesLE)

void ClearTypesLE()
{
//��������� ��� ��� ��������
  memset(TypLE, typeLE_DIS, sizeof(TypLE));
}//ClearTypesLE()

void ClearWIDELOG()
{
//�������� ��� ��
  memset(ArrayWIDELOG, 0, sizeof(ArrayWIDELOG));
}//ClearWIDELOG()
