/*
#include <vcl.h>
#include <strstrea.h>
#include <math.h>
#pragma hdrstop
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "zonaVRTdef.h"
#include "zonaVRTfnc.h"


extern INT_64 X1_64, Y1_64, X2_64, Y2_64, X3_64, Y3_64, X4_64, Y4_64;
extern INT_64 X14V_64, Y14V_64, X21V_64, Y21V_64, X32V_64, Y32V_64, X41V_64, Y41V_64;
extern    INT_64 X13V_64, Y13V_64;

extern INT_64 koordXZ_64, koordYZ_64;

extern VectorXY_64   nVector34_64vrtBD[];//��� �������� ��� ��� 5 ��������
extern VectorXY_64   nVector32_64vrtBD[];
extern VectorXY_64   nVector12_64vrtBD[];
extern VectorXY_64   nVector14_64vrtBD[];

extern VectorXY_64   nVector41_64vrtBD[];
extern VectorXY_64   nVector43_64vrtBD[];
extern VectorXY_64   nVector23_64vrtBD[];
extern VectorXY_64   nVector21_64vrtBD[];
extern VectorXY_64   nVector31_64vrtBD[];
extern VectorXY_64   nVector13_64vrtBD[];

extern INT_64  zonaVertexBD[];//4 *2 *5 *2*2];//������ ������ 

extern int isZonaBD[];//��������� � ���� ��

//������� ������� �����������
extern int    spvUSTAVKI[];

int isViewZMethod_64VRT(/*int off_spv,*/ int numClon, int idxIsZona) @ "Fast_function"
{
 VectorXY_64   *nVector34_64vrt = &nVector34_64vrtBD[numClon];
//��������������� ������ �������� 32
 VectorXY_64   *nVector32_64vrt = &nVector32_64vrtBD[numClon];
//��������������� ������ �������� 12
 VectorXY_64   *nVector12_64vrt = &nVector12_64vrtBD[numClon];
//��������������� ������ �������� 14
 VectorXY_64   *nVector14_64vrt = &nVector14_64vrtBD[numClon];

//��������������� ������ �������� 41
 VectorXY_64   *nVector41_64vrt = &nVector41_64vrtBD[numClon];
//��������������� ������ �������� 43
 VectorXY_64   *nVector43_64vrt = &nVector43_64vrtBD[numClon];
//��������������� ������ �������� 23
 VectorXY_64   *nVector23_64vrt = &nVector23_64vrtBD[numClon];
//��������������� ������ �������� 21
 VectorXY_64   *nVector21_64vrt = &nVector21_64vrtBD[numClon];

 INT_64 *zonaVertex = &zonaVertexBD[numClon*16];//4 *2 *5 *2*2];//������ ������ 

//������ � SPV ��������
//������������� �������
//��������� ��������� ������� Z � ����
//���������� ������������ ������� �������� Z3
   VectorXY_64  vectorZ3_64;
//���������� ������������ ������� �������� Z1
   VectorXY_64  vectorZ1_64;
//���������� ������������ ������� �������� Z4
   VectorXY_64  vectorZ4_64;
//���������� ������������ ������� �������� Z2
   VectorXY_64  vectorZ2_64;

  INT_64 nMinZ_64;//����������� ��������������� Z
  INT_64 XA_64, YA_64, XB_64, YB_64, XC_64, YC_64, XD_64, YD_64;

//  if (TrianCheckBox->Checked) return isViewZTrianMethod_64();//�����������

//������ � SPV ��������
// INT_64 *zonaSPV_64 = (INT_64 *)(&spvUSTAVKI[off_spv]);//(&zonaSPV[33]);
//  else
  if (isZonaBD[idxIsZona])//��������� � ���� ��
//isZona)
  {
    XA_64 = zonaVertex[iX14V_64];//X14V_64;
    YA_64 = zonaVertex[iY14V_64];//Y14V_64;
    XB_64 = zonaVertex[iX21V_64];//X21V_64;
    YB_64 = zonaVertex[iY21V_64];//Y21V_64;
    XC_64 = zonaVertex[iX32V_64];//X32V_64;
    YC_64 = zonaVertex[iY32V_64];//Y32V_64;
    XD_64 = zonaVertex[iX41V_64];//X41V_64;
    YD_64 = zonaVertex[iY41V_64];//Y41V_64;
  }//if (isZona)
   else
  {
    XA_64 = zonaVertex[iX1_64];//X1_64;
    YA_64 = zonaVertex[iY1_64];//Y1_64;
    XB_64 = zonaVertex[iX2_64];//X2_64;
    YB_64 = zonaVertex[iY2_64];//Y2_64;
    XC_64 = zonaVertex[iX3_64];//X3_64;
    YC_64 = zonaVertex[iY3_64];//Y3_64;
    XD_64 = zonaVertex[iX4_64];//X4_64;
    YD_64 = zonaVertex[iY4_64];//Y4_64;
  }//else

//��������� ���������� ������������ ������� �������� Z3
//������������� �������
  makeOporVectorZ_64VRT(XC_64, YC_64, &vectorZ3_64);
//������������� �������
  nMinZ_64 = makeLenVector_64VRT(&vectorZ3_64);//����������� ��������������� Z
//��������� ���������� ������������ ������� �������� Z1
  makeOporVectorZ_64VRT(XA_64, YA_64, &vectorZ1_64);
  INT_64 tmpLen_64 = makeLenVector_64VRT(&vectorZ1_64);

  if (nMinZ_64>tmpLen_64)
        nMinZ_64 = tmpLen_64;
//��������� ���������� ������������ ������� �������� Z4
  makeOporVectorZ_64VRT(XD_64, YD_64, &vectorZ4_64);
//��������� ���������� ������������ ������� �������� Z2
  makeOporVectorZ_64VRT(XB_64, YB_64, &vectorZ2_64);

  INT_64 lenZ2_64 = makeLenVector_64VRT(&vectorZ2_64);
  INT_64 lenZ4_64 = makeLenVector_64VRT(&vectorZ4_64);

//  printLenVector(isZona);//���������� ����� ��������

  int axes31 = 0;//�������� ������ ������ 31
  if (!(nMinZ_64<lenZ2_64 && nMinZ_64<lenZ4_64)) axes31 = 1;//�������� ������ ������ 31

  int isSectorCA = 0;//false;
  int isSectorDB = 0;//false;
//  if (!errorZona) //������ ������������ ������ ����
//  {
    if (axes31)   //�������� ������ ������ 31
    {
      if (isSectorZ_64VRT(&vectorZ3_64, nVector34_64vrt, nVector32_64vrt) &&
          isSectorZ_64VRT(&vectorZ1_64, nVector12_64vrt, nVector14_64vrt)) isSectorCA = 1;//true;
    }//if
    else
    {
      if (isSectorZ_64VRT(&vectorZ4_64, nVector41_64vrt, nVector43_64vrt) &&
          isSectorZ_64VRT(&vectorZ2_64, nVector23_64vrt, nVector21_64vrt)) isSectorDB = 1;//true;
    }//else
//    if (isZona)
     if (isZonaBD[idxIsZona])//��������� � ���� ��
    {
      //���������  �������
//      if ((isSectorCA | isSectorDB)==0) isZona = 0;//false;
      if (isSectorCA | isSectorDB);
//      else isZona = 0;
      else isZonaBD[idxIsZona] = 0;//��������� � ���� ��
    }
     else
    {
      //��������� ��������
//      isZona = isSectorCA | isSectorDB;
        isZonaBD[idxIsZona] = isSectorCA | isSectorDB;//��������� � ���� ��
    }
    return isZonaBD[idxIsZona];//isZona;
}//isViewZMethod_64()

int isSectorZ_64VRT(VectorXY_64 *oporZ, VectorXY_64 *nVectorLow, VectorXY_64 *nVectorHi) @ "Fast_function"
{
//��������� ��������� � ������ �������� Z
//����� ������� � ����� ALFA - BETA
//float Rez1 =
  if (
    oporZ->yVect_64 * nVectorLow->xVect_64 - oporZ->xVect_64 * nVectorLow->yVect_64>0 &&
//float Rez2 =
    oporZ->yVect_64 * nVectorHi->xVect_64  - oporZ->xVect_64 * nVectorHi->yVect_64<0) return 1;//true;

  return 0;//false;
}//isSectorZ(

void makeOporVectorZ_64VRT(INT_64 xOpor_64, INT_64 yOpor_64, VectorXY_64 *oporZ_64) @ "Fast_function"
{
//������������� �������
//��������� ����������� Z
//xOpor, yOpor - ������� �����
  oporZ_64 ->  xVect_64 = koordXZ_64 - xOpor_64;
  oporZ_64 ->  yVect_64 = koordYZ_64 - yOpor_64;
}//makeOporVectorZ_64(INT_64 xOpor, INT_64 yOpor, VectorXY_64 *oporZ_64)

INT_64 makeLenVector_64VRT(VectorXY_64 *oporZ_64) @ "Fast_function"
{
//��������� ����� ������������ Z
//  return makeLenVector_64(oporZ_64->xVect_64, oporZ_64->yVect_64);
  return oporZ_64->xVect_64 * oporZ_64->xVect_64 + oporZ_64->yVect_64 * oporZ_64->yVect_64;//xn*xn+yn*yn;

}//makeLenVector_64(VectorXY_64 *oporZ_64)

int isViewZTrianMethod_64VRT(int numClon, int idxIsZona)  @ "Fast_function"
{
///*
//������������ �������� �������
//��� �������� ��� ��� 5 ��������

// VectorXY_64   *nVector34_64vrt = &nVector34_64vrtBD[numClon];
//��������������� ������ �������� 32
 VectorXY_64   *nVector32_64vrt = &nVector32_64vrtBD[numClon];
//��������������� ������ �������� 12
 VectorXY_64   *nVector12_64vrt = &nVector12_64vrtBD[numClon];
//��������������� ������ �������� 14
// VectorXY_64   *nVector14_64vrt = &nVector14_64vrtBD[numClon];

//��������������� ������ �������� 41
// VectorXY_64   *nVector41_64vrt = &nVector41_64vrtBD[numClon];
//��������������� ������ �������� 43
// VectorXY_64   *nVector43_64vrt = &nVector43_64vrtBD[numClon];
//��������������� ������ �������� 23
 VectorXY_64   *nVector23_64vrt = &nVector23_64vrtBD[numClon];
//��������������� ������ �������� 21
 VectorXY_64   *nVector21_64vrt = &nVector21_64vrtBD[numClon];
//��� ������������
 VectorXY_64   *nVector31_64vrt = &nVector31_64vrtBD[numClon];
 VectorXY_64   *nVector13_64vrt = &nVector13_64vrtBD[numClon];


 INT_64 *zonaVertex = &zonaVertexBD[numClon*16];//4 *2 *5 *2*2];//������ ������ 

//��������� ��������� ������� Z � ���� ������������
//���������� ������������ ������� �������� Z3
//  struct VectorXY  vectorZ3;
  VectorXY_64  vectorZ3_64;
//���������� ������������ ������� �������� Z1
  //struct VectorXY  vectorZ1;
  VectorXY_64  vectorZ1_64;
//���������� ������������ ������� �������� Z2
 // struct VectorXY  vectorZ2;
  VectorXY_64  vectorZ2_64;

 // float nMinZ;//����������� ��������������� Z
  INT_64 nMinZ_64;//����������� ��������������� Z
 // float XA, YA, XB, YB, XC, YC;
  INT_64 XA_64, YA_64, XB_64, YB_64, XC_64, YC_64;

  if (isZonaBD[idxIsZona])//��������� � ���� ��
  {
    XA_64 = zonaVertex[iX13V_64];
    YA_64 = zonaVertex[iY13V_64];
    XB_64 = zonaVertex[iX21V_64];
    YB_64 = zonaVertex[iY21V_64];
    XC_64 = zonaVertex[iX32V_64];
    YC_64 = zonaVertex[iY32V_64];
  }//if (isZona)
   else
  {
    XA_64 = zonaVertex[iX1_64];
    YA_64 = zonaVertex[iY1_64];
    XB_64 = zonaVertex[iX2_64];
    YB_64 = zonaVertex[iY2_64];
    XC_64 = zonaVertex[iX3_64];
    YC_64 = zonaVertex[iY3_64];
  }//else

  int axesZ = 1;//�������� ������ ������ Z1
//��������� ���������� ������������ ������� �������� Z1
  makeOporVectorZ_64VRT(XA_64, YA_64, &vectorZ1_64);
  nMinZ_64 = makeLenVector_64VRT(&vectorZ1_64);//����������� ��������������� Z
//��������� ���������� ������������ ������� �������� Z2
  makeOporVectorZ_64VRT(XB_64, YB_64, &vectorZ2_64);
  INT_64 tmpLen_64 = makeLenVector_64VRT(&vectorZ2_64);
  if (nMinZ_64>tmpLen_64){ nMinZ_64 = tmpLen_64; axesZ = 2;}
//��������� ���������� ������������ ������� �������� Z2
  makeOporVectorZ_64VRT(XC_64, YC_64, &vectorZ3_64);
  tmpLen_64 = makeLenVector_64VRT(&vectorZ3_64);
  if (nMinZ_64>tmpLen_64) axesZ = 3;

//  printLenVectorTrian(isZona);//���������� ����� ��������

  int isSectorZ1 = 0;//false;
  int isSectorZ2 = 0;//false;
  int isSectorZ3 = 0;//false;

//  if (!errorZona) //������ ������������ ������ ����
//  {

    switch (axesZ) {
    case 1:
      if (isSectorZ_64VRT(&vectorZ3_64, nVector31_64vrt, nVector32_64vrt) &&
          isSectorZ_64VRT(&vectorZ2_64, nVector23_64vrt, nVector21_64vrt)) isSectorZ1 = 1;//true;
    break;
    case 2:
      if (isSectorZ_64VRT(&vectorZ3_64, nVector31_64vrt, nVector32_64vrt) &&
          isSectorZ_64VRT(&vectorZ1_64, nVector12_64vrt, nVector13_64vrt)) isSectorZ2 = 1;//true;
    break;
    case 3:
      if (isSectorZ_64VRT(&vectorZ2_64, nVector23_64vrt, nVector21_64vrt) &&
          isSectorZ_64VRT(&vectorZ1_64, nVector12_64vrt, nVector13_64vrt)) isSectorZ3 = 1;//true;
    break;

    default:;
    }//switch

    if (isZonaBD[idxIsZona])//isZona)
    {
      //���������  �������
      if (isSectorZ1 | isSectorZ2 | isSectorZ3);
      else isZonaBD[idxIsZona] = 0;//isZona = 0;//false;
    }
    else
    {
      //��������� ��������
//      isZona
      isZonaBD[idxIsZona] = isSectorZ1 | isSectorZ2 | isSectorZ3;
    }//if


  //}//if(!errorZona)
//*/
    return isZonaBD[idxIsZona];//0;//isZona;

}//int isViewZTrianMethod_64VRT(int numClon, int idxIsZona)

