/*
#include <stdio.h>
#include <TCHAR.H >
#include <conio.h>
#include <sys\stat.h>

#include <fstream.h>
#include <typeinfo.h>

#include <comctrls.hpp>

#include <vcl.h>
#include <strstrea.h>
#include <math.h>
#pragma hdrstop
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

//#include "zona1rt.h"
#include "zonaVRTdef.h"
#include "zonaVRTfnc.h"

//���������� ������ ���� ��������
extern float X1;
extern float Y1;

extern float X2;
extern float Y2;

extern float X3;
extern float Y3;

extern float X4;
extern float Y4;

extern double  X12V, Y12V, X21V, Y21V, X23V, Y23V, X32V, Y32V;
extern double  X34V, Y34V, X41V, Y41V, X43V, Y43V, X31V, Y31V;
extern double  X13V, Y13V;

extern double  X14V,    Y14V;

extern INT_64 X1_64, Y1_64, X2_64, Y2_64, X3_64, Y3_64, X4_64, Y4_64;
//���������� ������ ���� ��������
extern INT_64 X14V_64, Y14V_64, /*X12V_64, Y12V_64,*/ X21V_64, Y21V_64, /*X23V_64, Y23V_64,*/ X32V_64, Y32V_64;
extern INT_64 /*X34V_64, Y34V_64,*/ X41V_64, Y41V_64; /*X43V_64, Y43V_64, X31V_64, Y31V_64, X13V_64, Y13V_64;*/

//��������������� ������ �������� 34
extern VectorXY_VRT  nVector34vrt;
extern VectorXY_64   nVector34_64vrt;
//��������������� ������ �������� 32
extern VectorXY_VRT  nVector32vrt;
extern VectorXY_64   nVector32_64vrt;
//��������������� ������ �������� 12
extern VectorXY_VRT  nVector12vrt;
extern VectorXY_64   nVector12_64vrt;
//��������������� ������ �������� 14
extern VectorXY_VRT  nVector14vrt;
extern VectorXY_64   nVector14_64vrt;

//��������������� ������ �������� 41
extern VectorXY_VRT  nVector41vrt;
extern VectorXY_64   nVector41_64vrt;
//��������������� ������ �������� 43
extern VectorXY_VRT  nVector43vrt;
extern VectorXY_64   nVector43_64vrt;
//��������������� ������ �������� 23
extern VectorXY_VRT  nVector23vrt;
extern VectorXY_64   nVector23_64vrt;
//��������������� ������ �������� 21
extern VectorXY_VRT  nVector21vrt;
extern VectorXY_64   nVector21_64vrt;

extern double VozvG;//���������� ��������

//������ Z
extern INT_64 koordXZ_64;
extern INT_64 koordYZ_64;

extern int    spvUSTAVKI[];

//��������������� ������ �������� 31
 VectorXY_VRT   nVector31vrt;
 VectorXY_64    nVector31_64vrt;
//��������������� ������ �������� 13
 VectorXY_VRT  nVector13vrt;
 VectorXY_64   nVector13_64vrt;

 INT_64  X13V_64, Y13V_64;

short isZonaTrianMethodVRT(int off_spv)
{
  X1_64 = (INT_64)ceil(X1*TO_INTEGER64);
  Y1_64 = (INT_64)ceil(Y1*TO_INTEGER64);

  X2_64 = (INT_64)ceil(X2*TO_INTEGER64);
  Y2_64 = (INT_64)ceil(Y2*TO_INTEGER64);

  X3_64 = (INT_64)ceil(X3*TO_INTEGER64);
  Y3_64 = (INT_64)ceil(Y3*TO_INTEGER64);

  X12V = X1;
  Y12V = Y1;
  X14V = X1;
  Y14V = Y1;
  X21V = X2;
  Y21V = Y2;
  X23V = X2;
  Y23V = Y2;
  X32V = X3;
  Y32V = Y3;
  X41V = X4;
  Y41V = Y4;
  X34V = X3;
  Y34V = Y3;

  X31V = X3;
  Y31V = Y3;

  X13V = X1;
  Y13V = Y1;

  if (controlPoint1VRT()) //�������� 3-� �����
  {
    return ERROR_1_POINT;//true;//���� � �������
  }
//  errorZona = false;//������ ������������ ������ ����
  if (controlPoint3TrianVRT()) //�������� 3-� �����
  {
//    ControlLabel->Caption = "������ 3 �����!";
//    sendText("visualView W1");
//    errorZona = true;//������ ������������ ������ ����
  //  return true;//���� � �������
    return ERROR_3_POINT;//true;//���� � �������
  }//if

  if (controlPoint2VRT()) //�������� 2-� �����
  {
//    ControlLabel->Caption = "������ 2 �����!";
//    sendText("visualView W1");
//    errorZona = true;//������ ������������ ������ ����
//    return true;//���� � �������
    return ERROR_2_POINT;//true;//���� � �������
  }//if

//************** ��������������� ������� �������� *************
//��������������� ������ ��������� A
  double tmpLen = makeNormalVectorVRT(X3, Y3,//������� �����
                                      X1, Y1,//������ ������
                                      &nVector31vrt);//��������������� ������ 31
//������������� �������
  nVector31_64vrt.xVect_64 = (INT_64)ceil(nVector31vrt.xVect*TO_INTEGER64);
  nVector31_64vrt.yVect_64 = (INT_64)ceil(nVector31vrt.yVect*TO_INTEGER64);
//  X1_64 = (INT_64)ceil(X1*TO_INTEGER64);
//  Y1_64 = (INT_64)ceil(Y1*TO_INTEGER64);

  if (tmpLen<MIN_STORONA)
  {
//    ControlLabel->Caption = "������ �������� ������� 31!";
//    sendText("visualView W1");
//    return true;//���� � �������
    return ERROR_31_STORONA;//true;//���� � �������
  }//if

//��������������� ������ ��������� A
  tmpLen = makeNormalVectorVRT(X3, Y3,//������� �����
                               X2, Y2,//������� ������
                               &nVector32vrt);//��������������� ������ 32
//������������� �������
  nVector32_64vrt.xVect_64 = (INT_64)ceil(nVector32vrt.xVect*TO_INTEGER64);
  nVector32_64vrt.yVect_64 = (INT_64)ceil(nVector32vrt.yVect*TO_INTEGER64);
//  X3_64 = (INT_64)ceil(X3*TO_INTEGER64);
//  Y3_64 = (INT_64)ceil(Y3*TO_INTEGER64);

  if (tmpLen<MIN_STORONA)
  {
//    ControlLabel->Caption = "������ �������� ������� 32!";
  //  sendText("visualView W1");
    //return true;//���� � �������
    return ERROR_32_STORONA;//true;//���� � �������
  }//if

  int   raz = 0;
//  float tempShift;

//  X3S1Edit->Text = ugolString(makeUgolVector(&nVector31));//���� ��������
//  X3S2Edit->Text = ugolString(makeUgolVector(&nVector32));//���� ��������
//  X4S1Edit->Text = "����";//���� ��������
//  X4S2Edit->Text = "����";//���� ��������

  double tmpUgol1  = makeUgolVectorVRT(&nVector32vrt);
  double tempShift = splitUgolSVRT(tmpUgol1, &raz);//������ ������

  makeVozvPointVRT(32, tempShift, raz);//���������� ������� ��������

  double tmpUgol2  = makeUgolVectorVRT(&nVector31vrt);
  tempShift = splitUgolSVRT(tmpUgol2, &raz);//������ ������
  makeVozvPointVRT(34, tempShift, raz);//���������� ������� ��������

//  char  LocTxt[200];

  double diff = tmpUgol1 - tmpUgol2;
  char  tmp1=0;
  if (diff>=MAX_UGOL) tmp1=1;//errorZona = true;//������ ������������ ������ ����
  if (diff<0 && (diff=(diff+360.0))>MAX_UGOL) tmp1=1;//errorZona = true;//������ ������������ ������ ����
//  sprintf(LocTxt,  "t3= %5.3f", diff);
//  TestLabel3->Caption = LocTxt;

  if (tmp1) //�������� 3-� �����
  {
//    ControlLabel->Caption = "������ ���� � ����� 3!";
//    sendText("visualView W1");
//    return true;//���� � �������
    return ERROR_3_UGOL;//true;//���� � �������
  }//if

//��������������� ������ ��������� A
  tmpLen = makeNormalVectorVRT(X1, Y1,//������� �����
                               X2, Y2,//������ ������
                               &nVector12vrt);//��������������� ������ 12
//������������� �������
  nVector12_64vrt.xVect_64 = (INT_64)ceil(nVector12vrt.xVect*TO_INTEGER64);
  nVector12_64vrt.yVect_64 = (INT_64)ceil(nVector12vrt.yVect*TO_INTEGER64);
//  X2_64 = (INT_64)ceil(X2*TO_INTEGER64);
//  Y2_64 = (INT_64)ceil(Y2*TO_INTEGER64);


  if (tmpLen<MIN_STORONA)
  {
//    ControlLabel->Caption = "������ �������� ������� 12!";
//    sendText("visualView W1");
//    return true;//���� � �������
    return ERROR_12_STORONA;//���� � �������
  }//if

//��������������� ������ ��������� A
  makeNormalVectorVRT(X1, Y1,//������� �����
                      X3, Y3,//������� ������
                      &nVector13vrt);//��������������� ������ 13
//������������� �������
  nVector13_64vrt.xVect_64 = (INT_64)ceil(nVector13vrt.xVect*TO_INTEGER64);
  nVector13_64vrt.yVect_64 = (INT_64)ceil(nVector13vrt.yVect*TO_INTEGER64);

//  X1S1Edit->Text = ugolString(makeUgolVector(&nVector13));//���� ��������
//  X1S2Edit->Text = ugolString(makeUgolVector(&nVector12));//���� ��������

  tmpUgol1 = makeUgolVectorVRT(&nVector13vrt);
  tmpUgol2 = makeUgolVectorVRT(&nVector12vrt);
  tempShift = splitUgolSVRT(tmpUgol2, &raz);//������ ������
  makeVozvPointVRT(12, tempShift, raz);//���������� ������� ��������

  diff = tmpUgol1 - tmpUgol2;
  if (diff>=MAX_UGOL) tmp1=1;//errorZona = true;//������ ������������ ������ ����
  if (diff<0 && (diff=(diff+360.0))>MAX_UGOL) tmp1=1;//errorZona = true;//������ ������������ ������ ����
//  sprintf(LocTxt,  "t1= %5.3f", diff);
//  TestLabel1->Caption = LocTxt;

  if (tmp1) //�������� 1-� �����
  {
//    ControlLabel->Caption = "������ ���� � ����� 1!";
//    sendText("visualView W1");
//    return true;//���� � �������
    return ERROR_1_UGOL;//���� � �������
  }//if

//  TestLabel4->Caption = "t4= OFF";

//��������������� ������ 23
  makeNormalVectorVRT(X2, Y2,//������� �����
                      X3, Y3,//������
                      &nVector23vrt);//��������������� ������ 23
//������������� �������
  nVector23_64vrt.xVect_64 = (INT_64)ceil(nVector23vrt.xVect*TO_INTEGER64);
  nVector23_64vrt.yVect_64 = (INT_64)ceil(nVector23vrt.yVect*TO_INTEGER64);

//��������������� ������ 21
  makeNormalVectorVRT(X2, Y2,//������� �����
                      X1, Y1,//������
                      &nVector21vrt);//��������������� ������ 21
//������������� �������
  nVector21_64vrt.xVect_64 = (INT_64)ceil(nVector21vrt.xVect*TO_INTEGER64);
  nVector21_64vrt.yVect_64 = (INT_64)ceil(nVector21vrt.yVect*TO_INTEGER64);

//  X2S1Edit->Text = ugolString(makeUgolVector(&nVector21));//���� ��������
//  X2S2Edit->Text = ugolString(makeUgolVector(&nVector23));//���� ��������

  diff = makeUgolVectorVRT(&nVector21vrt) - makeUgolVectorVRT(&nVector23vrt);
  if (diff>=MAX_UGOL) tmp1=1;//errorZona = true;//������ ������������ ������ ����
  if (diff<0 && (diff=(diff+360.0))>MAX_UGOL) tmp1=1;//errorZona = true;//������ ������������ ������ ����
//  sprintf(LocTxt,  "t2= %5.3f", diff);
//  TestLabel2->Caption = LocTxt;

  if (tmp1) //�������� 2-� �����
  {
//    ControlLabel->Caption = "������ ���� � ����� 2!";
//    sendText("visualView W1");
//    return true;//���� � �������
    return ERROR_2_UGOL;//���� � �������
  }//if

//����������� ��� ������� ��������
  LineXY_VRT lineV32_23, lineV12_21, lineV31_13;
  makeLineVVRT(X32V, Y32V, X23V, Y23V, &lineV32_23);//����������� ������� ��������
  makeLineVVRT(X31V, Y31V, X13V, Y13V, &lineV31_13);//����������� ������� ��������
  makeLineVVRT(X12V, Y12V, X21V, Y21V, &lineV12_21);//����������� ������� ��������

  VectorXY_VRT vXY1, vXY2;

  vXY1.xVect = X32V;
  vXY1.yVect = Y32V;
  vXY2.xVect = X31V;
  vXY2.yVect = Y31V;

  VectorXY_VRT tempXY =
  makeVozvCrossPointVRT(&vXY1, &vXY2, &lineV32_23, &lineV31_13);//��������� �������
  X32V = tempXY.xVect;
  Y32V = tempXY.yVect;
  X31V = X32V;//tempXY.xVect;
  Y31V = Y32V;//tempXY.yVect;
//������������� �������
  X32V_64 = (INT_64)ceil(X32V*TO_INTEGER64);
  Y32V_64 = (INT_64)ceil(Y32V*TO_INTEGER64);
//  X31V_64 = X32V_64;
//  Y31V_64 = Y32V_64;

  vXY1.xVect = X32V;
  vXY1.yVect = Y32V;
  vXY2.xVect = X12V;
  vXY2.yVect = Y12V;
  tempXY =
  makeVozvCrossPointVRT(&vXY1, &vXY2, &lineV32_23, &lineV12_21);//��������� �������
  X21V = tempXY.xVect;
  Y21V = tempXY.yVect;
  X23V = X21V;//tempXY.xVect;
  Y23V = Y21V;//tempXY.yVect;
//������������� �������
  X21V_64 = (INT_64)ceil(X21V*TO_INTEGER64);
  Y21V_64 = (INT_64)ceil(Y21V*TO_INTEGER64);
//  X23V_64 = X21V_64;
//  Y23V_64 = Y21V_64;

  vXY1.xVect = X12V;
  vXY1.yVect = Y12V;
  vXY2.xVect = X13V;
  vXY2.yVect = Y13V;
  tempXY =
  makeVozvCrossPointVRT(&vXY1, &vXY2, &lineV12_21, &lineV31_13);
  X12V = tempXY.xVect;
  Y12V = tempXY.yVect;
  X13V = X12V;//tempXY.xVect;
  Y13V = Y12V;//tempXY.yVect;
//������������� �������
//  X12V_64 = (INT_64)ceil(X12V*TO_INTEGER64);
//  Y12V_64 = (INT_64)ceil(Y12V*TO_INTEGER64);
  X13V_64 = (INT_64)ceil(X12V*TO_INTEGER64);
  Y13V_64 = (INT_64)ceil(Y12V*TO_INTEGER64);
//  X13V_64 = X12V_64;
//  Y13V_64 = Y12V_64;

  return 0;//false;
}//isNewZonaTrianMethod()

char controlPoint3TrianVRT()
{
//�������� 3-� �����
  if ((X1-X3)<0.0) return 1;//true;//������
  return 0;//false;
}//controlPoint3TrianVRT()

