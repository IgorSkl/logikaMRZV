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

//extern TFzona1RT *Fzona1RT;

//���������� ������ ���� ��������
 float X1=60.0;
 float Y1=33.0;

 float X2=40.0;
 float Y2=55.0;

 float X3=0.0;
 float Y3=0.0;

 float X4=40.0;
 float Y4=11.0;

 INT_64 koordXZ_64=353534;//125001;//160697;//250000;
 INT_64 koordYZ_64=421325;//216507;//191512;//0;

 double  X12V, Y12V, X21V, Y21V, X23V, Y23V, X32V, Y32V;
 double  X34V, Y34V, X41V, Y41V, X43V, Y43V, X31V, Y31V;
 double  X13V, Y13V;

 double  X14V,    Y14V;

 INT_64 X1_64, Y1_64, X2_64, Y2_64, X3_64, Y3_64, X4_64, Y4_64;
//���������� ������ ���� ��������
 INT_64 X14V_64, Y14V_64, /*X12V_64, Y12V_64,*/ X21V_64, Y21V_64, /*X23V_64, Y23V_64,*/ X32V_64, Y32V_64;
 INT_64 /*X34V_64, Y34V_64,*/ X41V_64, Y41V_64; /*X43V_64, Y43V_64, X31V_64, Y31V_64, X13V_64, Y13V_64;*/

 int isZonaBD[32];//��������� � ���� ��
 int isTriangleZonaBD[10];//���� �� �����������-���������������

 VectorXY_64   nVector34_64vrtBD[10];//��� �������� ��� ��� 5 ��������
 VectorXY_64   nVector32_64vrtBD[10];
 VectorXY_64   nVector12_64vrtBD[10];
 VectorXY_64   nVector14_64vrtBD[10];

 VectorXY_64   nVector41_64vrtBD[10];
 VectorXY_64   nVector43_64vrtBD[10];
 VectorXY_64   nVector23_64vrtBD[10];
 VectorXY_64   nVector21_64vrtBD[10];

//5 �������� �� 2 ���� �� 4 ����� � 2 ����� XY �� ���� � ������� �� �� �������
 INT_64  zonaVertexBD[4 *2 *5 *2*2];//������ ������ 

//��������������� ������ �������� 34
 VectorXY_VRT  nVector34vrt;
 VectorXY_64   nVector34_64vrt;
//��������������� ������ �������� 32
 VectorXY_VRT  nVector32vrt;
 VectorXY_64   nVector32_64vrt;
//��������������� ������ �������� 12
 VectorXY_VRT  nVector12vrt;
 VectorXY_64   nVector12_64vrt;
//��������������� ������ �������� 14
 VectorXY_VRT  nVector14vrt;
 VectorXY_64   nVector14_64vrt;

//��������������� ������ �������� 41
 VectorXY_VRT  nVector41vrt;
 VectorXY_64   nVector41_64vrt;
//��������������� ������ �������� 43
 VectorXY_VRT  nVector43vrt;
 VectorXY_64   nVector43_64vrt;
//��������������� ������ �������� 23
 VectorXY_VRT  nVector23vrt;
 VectorXY_64   nVector23_64vrt;
//��������������� ������ �������� 21
 VectorXY_VRT  nVector21vrt;
 VectorXY_64   nVector21_64vrt;

 double VozvG = 2.0;//���������� ��������

//INT_64 
//int zonaSPV[200];
//������� ������� �����������
extern int    spvUSTAVKI[];
//INT_64 *zonaSPV_64;// = (INT_64 *)(&zonaSPV[33]);

short isNewZonaMethodVRT(/*int off_spv,*/ int numclon) 
{
  X1_64 = (INT_64)ceil(X1*TO_INTEGER64);
  Y1_64 = (INT_64)ceil(Y1*TO_INTEGER64);

  X2_64 = (INT_64)ceil(X2*TO_INTEGER64);
  Y2_64 = (INT_64)ceil(Y2*TO_INTEGER64);

  X3_64 = (INT_64)ceil(X3*TO_INTEGER64);
  Y3_64 = (INT_64)ceil(Y3*TO_INTEGER64);

  X4_64 = (INT_64)ceil(X4*TO_INTEGER64);
  Y4_64 = (INT_64)ceil(Y4*TO_INTEGER64);

//���������� ������ ���� ��������
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

  X43V = X4;
  Y43V = Y4;

//��������� ��������� ����
//  short errorZona = 0;//false;//������ ������������ ������ ����
  if (controlPoint3VRT()) //�������� 3-� �����
  {
//    ControlLabel->Caption = "������ 3 �����!";
//    sendText("visualView W1");
//    errorZona = ERROR_3_POINT;//true;//������ ������������ ������ ����
    return ERROR_3_POINT;//true;//���� � �������
  }//if
  
  if (controlPoint2VRT()) //�������� 2-� �����
  {
//    ControlLabel->Caption = "������ 2 �����!";
//    sendText("visualView W1");
  //  errorZona = ERROR_2_POINT;//true;//������ ������������ ������ ����
    return ERROR_2_POINT;//true;//���� � �������
  }//if
  
  if (controlPoint4VRT()) //�������� 4-� �����
  {
//    ControlLabel->Caption = "������ 4 �����!";
//    sendText("visualView W1");
    //errorZona = ERROR_4_POINT;//true;//������ ������������ ������ ����
    return ERROR_4_POINT;//true;//���� � �������
  }//if

//************** ��������������� ������� �������� *************
//������ ������� ����� - ����� 1
//��������� ���������� �� ����� ������ ����� �������
//��������������� ������ ���� ��������
//����� ��������������� ���������� ����� �� ����� ���� ������ 300 ���
//����� ����� ��������� �� ������ 5 �� � �� ������ 200 ��
//����� ���������� ���� - �� ������ 170 ���

  //struct 
    VectorXY_VRT   nVectorDg;//���������

//�������� ���������
  double tmpLen = makeNormalVectorVRT(X3, Y3,//������� �����
                                      X1, Y1,//������ ������
                                      &nVectorDg);//��������������� ������
  if (tmpLen > MAX_DIAGONAL || tmpLen < MIN_DIAGONAL)
  {
//    ControlLabel->Caption = "������ ��������� 3-1 �� � �����!";
//    sendText("visualView W1");
  //  errorZona = ERROR_31_DIAGONAL;//true;//������ ������������ ������ ����
    return ERROR_31_DIAGONAL;//���� � �������
  }//if
  double tmpD = tmpLen;


  tmpLen = makeNormalVectorVRT(X4, Y4,//������� �����
                               X2, Y2,//������ ������
                               &nVectorDg);//��������������� ������
  if (tmpLen > MAX_DIAGONAL || tmpLen < MIN_DIAGONAL)
  {
//    ControlLabel->Caption = "������ ��������� 4-2 �� � �����!";
//    sendText("visualView W1");
//    errorZona = ERROR_42_DIAGONAL;//true;//������ ������������ ������ ����
    return ERROR_42_DIAGONAL;//true;//���� � �������
  }//if
  if (tmpLen<tmpD) tmpD = tmpLen;//����� ���� ���������

//��������������� ������ 34
  tmpLen = makeNormalVectorVRT(X3, Y3,//������� �����
                               X4, Y4,//������ ������
                               &nVector34vrt);//��������������� ������ 34
//������������� �������
  nVector34_64vrt.xVect_64 = (INT_64)ceil(nVector34vrt.xVect*TO_INTEGER64);
  nVector34_64vrt.yVect_64 = (INT_64)ceil(nVector34vrt.yVect*TO_INTEGER64);
  //X3_64 = (INT_64)ceil(X3*TO_INTEGER64);
  //Y3_64 = (INT_64)ceil(Y3*TO_INTEGER64);

  if (tmpLen<MIN_STORONA)
  {
    //ControlLabel->Caption = "������ �������� ������� 34!";
    //sendText("visualView W1");
    return ERROR_34_STORONA;//true;//���� � �������
  }//if

//��������������� ������ 32
  tmpLen = makeNormalVectorVRT(X3, Y3,//������� �����
                               X2, Y2,//������� ������
                               &nVector32vrt);//��������������� ������ 32
//������������� �������
  nVector32_64vrt.xVect_64 = (INT_64)ceil(nVector32vrt.xVect*TO_INTEGER64);
  nVector32_64vrt.yVect_64 = (INT_64)ceil(nVector32vrt.yVect*TO_INTEGER64);
//  X2_64 = (INT_64)ceil(X2*TO_INTEGER64);
//  Y2_64 = (INT_64)ceil(Y2*TO_INTEGER64);

  if (tmpLen<MIN_STORONA)
  {
  //  ControlLabel->Caption = "������ �������� ������� 32!";
//    sendText("visualView W1");
    return ERROR_32_STORONA;//true;//���� � �������
  }//if

  int   raz = 0;
  double tempShift;

//  X3S1Edit->Text = ugolString(makeUgolVector(&nVector34));//���� ��������
//  X3S2Edit->Text = ugolString(makeUgolVector(&nVector32));//���� ��������

  //char  LocTxt[200];

  double tmpUgol1 = makeUgolVectorVRT(&nVector32vrt);
  tempShift = splitUgolSVRT(tmpUgol1, &raz);//������ ������

  makeVozvPointVRT(32, tempShift, raz);//���������� ������� �������� 32

  double tmpUgol2 = makeUgolVectorVRT(&nVector34vrt);
  tempShift = splitUgolSVRT(tmpUgol2, &raz);//������ ������

  makeVozvPointVRT(34, tempShift, raz);//���������� ������� �������� 34

  double diff = tmpUgol1 - tmpUgol2;
  char  tmp1=0;
  if (diff>=MAX_UGOL) tmp1=1;//������ ������������ ������ ����
  if (diff<0 && (diff=(diff+360.0))>MAX_UGOL) tmp1=1;//������ ������������ ������ ����
//  sprintf(LocTxt,  "t3= %5.3f", diff);
  //TestLabel3->Caption = LocTxt;

  if (tmp1)//�������� 3-� �����
  {
//    ControlLabel->Caption = "������ ���� � ����� 3!";
//    sendText("visualView W1");
    return ERROR_3_UGOL;//true;//���� � �������
  }//if
  double diffTop = diff;

//��������������� ������ 12
  tmpLen = makeNormalVectorVRT(X1, Y1,//������� �����
                               X2, Y2,//������ ������
                               &nVector12vrt);//��������������� ������ 12
//������������� �������
  nVector12_64vrt.xVect_64 = (INT_64)ceil(nVector12vrt.xVect*TO_INTEGER64);
  nVector12_64vrt.yVect_64 = (INT_64)ceil(nVector12vrt.yVect*TO_INTEGER64);

  if (tmpLen<MIN_STORONA)
  {
//    ControlLabel->Caption = "������ �������� ������� 12!";
//    sendText("visualView W1");
    return ERROR_12_STORONA;//���� � �������
  }//if

//��������������� ������ 14
  tmpLen = makeNormalVectorVRT(X1, Y1,//������� �����
                               X4, Y4,//������� ������
                               &nVector14vrt);//��������������� ������ 14
//������������� �������
  nVector14_64vrt.xVect_64 = (INT_64)ceil(nVector14vrt.xVect*TO_INTEGER64);
  nVector14_64vrt.yVect_64 = (INT_64)ceil(nVector14vrt.yVect*TO_INTEGER64);

  if (tmpLen<MIN_STORONA)
  {
  //  ControlLabel->Caption = "������ �������� ������� 14!";
    //sendText("visualView W1");
    return ERROR_14_STORONA;//true;//���� � �������
  }//if

//  X1S1Edit->Text = ugolString(makeUgolVector(&nVector14));//���� ��������
//  X1S2Edit->Text = ugolString(makeUgolVector(&nVector12));//���� ��������

  tmpUgol1 = makeUgolVectorVRT(&nVector14vrt);
  tempShift = splitUgolSVRT(tmpUgol1, &raz);//������ ������
  makeVozvPointVRT(14, tempShift, raz);//���������� ������� ��������

  tmpUgol2 = makeUgolVectorVRT(&nVector12vrt);
  tempShift = splitUgolSVRT(tmpUgol2, &raz);//������ ������

  makeVozvPointVRT(12, tempShift, raz);//���������� ������� ��������
  
  diff = tmpUgol1 - tmpUgol2;
  if (diff>=MAX_UGOL) tmp1=1;//������ ������������ ������ ����
  if (diff<0 && (diff=(diff+360.0))>MAX_UGOL) tmp1=1;//������ ������������ ������ ����
//  sprintf(LocTxt,  "t1= %5.3f", diff);
//  TestLabel1->Caption = LocTxt;

  if (tmp1)//�������� 1-� �����
  {
//    ControlLabel->Caption = "������ ���� � ����� 1!";
//    sendText("visualView W1");
    return ERROR_1_UGOL;//���� � �������
  }//if
  if (diffTop + diff > MAX_UGOL_SUMMA)
  {
//    ControlLabel->Caption = "������ ����� ����� 3-1 ������ �����!";
  //  sendText("visualView W1");
    //errorZona = true;//������ ������������ ������ ����
    return ERROR_31_SUMMAUGOL;//true;//���� � �������
  }//if

//��������������� ������ 41
  makeNormalVectorVRT(X4, Y4,//������� �����
                      X1, Y1,//������
                      &nVector41vrt);//��������������� ������ 41
//������������� �������
  nVector41_64vrt.xVect_64 = (INT_64)ceil(nVector41vrt.xVect*TO_INTEGER64);
  nVector41_64vrt.yVect_64 = (INT_64)ceil(nVector41vrt.yVect*TO_INTEGER64);

//��������������� ������ 43
  makeNormalVectorVRT(X4, Y4,//������� �����
                      X3, Y3,//������
                      &nVector43vrt);//��������������� ������ 43
//������������� �������
  nVector43_64vrt.xVect_64 = (INT_64)ceil(nVector43vrt.xVect*TO_INTEGER64);
  nVector43_64vrt.yVect_64 = (INT_64)ceil(nVector43vrt.yVect*TO_INTEGER64);

  //X4S1Edit->Text = ugolString(makeUgolVector(&nVector43));//���� ��������
//  X4S2Edit->Text = ugolString(makeUgolVector(&nVector41));//���� ��������

  diff = makeUgolVectorVRT(&nVector43vrt) - makeUgolVectorVRT(&nVector41vrt);
  if (diff>=MAX_UGOL) tmp1=1;//������ ������������ ������ ����
  if (diff<0 && (diff=(diff+360.0))>MAX_UGOL) tmp1=1;//������ ������������ ������ ����
//  sprintf(LocTxt,  "t4= %5.3f", diff);
//  TestLabel4->Caption = LocTxt;
  if (tmp1)//�������� 4-� �����
  {
//    ControlLabel->Caption = "������ ���� � ����� 4!";
//    sendText("visualView W1");
    return ERROR_4_UGOL;//true;//���� � �������
  }//if
  diffTop = diff;

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

  if (tmp1)//�������� 2-� �����
  {
//    ControlLabel->Caption = "������ ���� � ����� 2!";
//    sendText("visualView W1");
    return ERROR_2_UGOL;//true;//���� � �������
  }//if
  if (diffTop + diff > MAX_UGOL_SUMMA)
  {
//    ControlLabel->Caption = "������ ����� ����� 4-2 ������ �����!";
//    sendText("visualView W1");
//    errorZona = true;//������ ������������ ������ ����
    return ERROR_42_SUMMAUGOL;//true;//���� � �������
  }//if

//����������� ��� ������� ��������
  LineXY_VRT lineV32_23, lineV34_43, lineV12_21, lineV14_41;
  makeLineVVRT(X32V, Y32V, X23V, Y23V, &lineV32_23);//����������� ������� ��������
  makeLineVVRT(X34V, Y34V, X43V, Y43V, &lineV34_43);//����������� ������� ��������
  makeLineVVRT(X14V, Y14V, X41V, Y41V, &lineV14_41);//����������� ������� ��������
  makeLineVVRT(X12V, Y12V, X21V, Y21V, &lineV12_21);//����������� ������� ��������

  VectorXY_VRT vXY1, vXY2;

  vXY1.xVect = X32V;
  vXY1.yVect = Y32V;
  vXY2.xVect = X34V;
  vXY2.yVect = Y34V;

  VectorXY_VRT tempXY =
  makeVozvCrossPointVRT(&vXY1, &vXY2, &lineV32_23, &lineV34_43);//��������� �������
  X32V = tempXY.xVect;
  Y32V = tempXY.yVect;
  X34V = X32V;//tempXY.xVect;
  Y34V = Y32V;//tempXY.yVect;
//������������� �������
  X32V_64 = (INT_64)ceil(X32V*TO_INTEGER64);
  Y32V_64 = (INT_64)ceil(Y32V*TO_INTEGER64);
//  X34V_64 = X32V_64;
//  Y34V_64 = Y32V_64;

  vXY1.xVect = X12V;
  vXY1.yVect = Y12V;
  vXY2.xVect = X14V;
  vXY2.yVect = Y14V;
  tempXY =
  makeVozvCrossPointVRT(&vXY1, &vXY2, &lineV12_21, &lineV14_41);//��������� �������
  X12V = tempXY.xVect;
  Y12V = tempXY.yVect;
  X14V = X12V;//tempXY.xVect;
  Y14V = Y12V;//tempXY.yVect;
//������������� �������
  X14V_64 = (INT_64)ceil(X14V*TO_INTEGER64);
  Y14V_64 = (INT_64)ceil(Y14V*TO_INTEGER64);
//  X14V_64 = X12V_64;
//  Y14V_64 = Y12V_64;

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

  vXY1.xVect = X34V;
  vXY1.yVect = Y34V;
  vXY2.xVect = X14V;
  vXY2.yVect = Y14V;
  tempXY =
  makeVozvCrossPointVRT(&vXY1, &vXY2, &lineV34_43, &lineV14_41);//��������� �������
  X41V = tempXY.xVect;
  Y41V = tempXY.yVect;
  X43V = X41V;//tempXY.xVect;
  Y43V = Y41V;//tempXY.yVect;
//������������� �������
  X41V_64 = (INT_64)ceil(X41V*TO_INTEGER64);
  Y41V_64 = (INT_64)ceil(Y41V*TO_INTEGER64);
//  X43V_64 = X41V_64;
//  Y43V_64 = Y41V_64;

//������ � SPV ��������
// INT_64  zonaVertex[4 *2 *5];//������ ������ 5 �������� �� 2 ���� �� 4 �����
 int ii=0;
 zonaVertexBD[numclon*16 + ii++] = X1_64;//0//4 *2 *5];//������ ������
// ii++;
 zonaVertexBD[numclon*16 + ii++] = Y1_64;//0//4 *2 *5];//������ ������
// ii++;

 zonaVertexBD[numclon*16 + ii++] = X2_64;//0//4 *2 *5];//������ ������
// ii++;
 zonaVertexBD[numclon*16 + ii++] = Y2_64;//0//4 *2 *5];//������ ������
// ii++;

 zonaVertexBD[numclon*16 + ii++] = X3_64;//0//4 *2 *5];//������ ������
// ii++;
 zonaVertexBD[numclon*16 + ii++] = Y3_64;//0//4 *2 *5];//������ ������
// ii++;

 zonaVertexBD[numclon*16 + ii++] = X4_64;//0//4 *2 *5];//������ ������
// ii++;
 zonaVertexBD[numclon*16 + ii++] = Y4_64;//0//4 *2 *5];//������ ������
// ii++;

 zonaVertexBD[numclon*16 + ii++] = X14V_64;//0//4 *2 *5];//������ ������
// ii++;
 zonaVertexBD[numclon*16 + ii++] = Y14V_64;//0//4 *2 *5];//������ ������
// ii++;

 zonaVertexBD[numclon*16 + ii++] = X21V_64;//0//4 *2 *5];//������ ������
// ii++;
 zonaVertexBD[numclon*16 + ii++] = Y21V_64;//0//4 *2 *5];//������ ������
// ii++;

 zonaVertexBD[numclon*16 + ii++] = X32V_64;//0//4 *2 *5];//������ ������
// ii++;
 zonaVertexBD[numclon*16 + ii++] = Y32V_64;//0//4 *2 *5];//������ ������
// ii++;

 zonaVertexBD[numclon*16 + ii++] = X41V_64;//0//4 *2 *5];//������ ������
// ii++;
 zonaVertexBD[numclon*16 + ii++] = Y41V_64;//0//4 *2 *5];//������ ������
// ii++;

/*
 INT_64 * zonaSPV_64 = (INT_64 *)(&spvUSTAVKI[off_spv]);
 int i=0;
 zonaSPV_64[i++] = X1_64;//0
 zonaSPV_64[i++] = Y1_64;//1

 zonaSPV_64[i++] = X2_64;//2
 zonaSPV_64[i++] = Y2_64;//3

 zonaSPV_64[i++] = X3_64;//4
 zonaSPV_64[i++] = Y3_64;//5

 zonaSPV_64[i++] = X4_64;//6
 zonaSPV_64[i++] = Y4_64;//7

 zonaSPV_64[i++] = X14V_64;//8
 zonaSPV_64[i++] = Y14V_64;//9

 zonaSPV_64[i++] = X21V_64;//10
 zonaSPV_64[i++] = Y21V_64;//11

 zonaSPV_64[i++] = X32V_64;//12
 zonaSPV_64[i++] = Y32V_64;//13

 zonaSPV_64[i++] = X41V_64;//14
 zonaSPV_64[i++] = Y41V_64;//15
*/

//��������� �������� �������
//��� �������� ��� ��� 5 ��������
 memcpy(&(nVector34_64vrtBD[numclon]), &nVector34_64vrt, sizeof(VectorXY_64));
 memcpy(&(nVector32_64vrtBD[numclon]), &nVector32_64vrt, sizeof(VectorXY_64));
 memcpy(&(nVector12_64vrtBD[numclon]), &nVector12_64vrt, sizeof(VectorXY_64));
 memcpy(&(nVector14_64vrtBD[numclon]), &nVector14_64vrt, sizeof(VectorXY_64));

 memcpy(&(nVector41_64vrtBD[numclon]), &nVector41_64vrt, sizeof(VectorXY_64));
 memcpy(&(nVector43_64vrtBD[numclon]), &nVector43_64vrt, sizeof(VectorXY_64));
 memcpy(&(nVector23_64vrtBD[numclon]), &nVector23_64vrt, sizeof(VectorXY_64));
 memcpy(&(nVector21_64vrtBD[numclon]), &nVector21_64vrt, sizeof(VectorXY_64));
  return 0;//��� ������
}//isNewZonaMethodVRT()

char controlPoint1VRT()
{
//�������� 1-� �����
//  if ((X1_64-X2_64)==0)if(Y1_64<Y2_64) return 1;//true;//������
  if ((X1_64-X2_64)==0)if(Y1_64<Y2_64) return 1;//true;//������
  if ((X1_64<X2_64)) return 1;//true;//������
  if ((X1_64<X3_64)) return 1;//true;//������
  return 0;
}//controlPoint2VRT()

char controlPoint2VRT()
{
//�������� 2-� �����
//  if ((X1_64-X2_64)<0) return 1;//true;//������
  //if ((X2_64<X3_64)) return 1;//true;//������
  return 0;
}//controlPoint2VRT()

char controlPoint3VRT()
{
//�������� 3-� �����
//  if ((X1_64-X3_64)<0) return 1;//true;//������
//  if ((X4_64-X3_64)<0) return 1;//true;//������
  return 0;
}//controlPoint3VRT()

char controlPoint4VRT()
{
//�������� 4-� �����
  if ((X1_64-X4_64)<0) return 1;//true;//������
  return 0;
}//controlPoint4VRT()

double makeNormalVectorVRT(double xOpor, double yOpor,
                           double xVect, double yVect, VectorXY_VRT *nVector)
{
//��������� ��������������� ������
//xOpor, yOpor - ������ ���������������� �������
//xVect, yVect - �����  ���������������� �������
//nVector - ����� ���������������� �������
  double xn = xVect - xOpor;
  double yn = yVect - yOpor;
//�����
  double len = makeLenVectorVRT(xn, yn);
  
  if (len<0.001) len=0.001;//��������������
//�������������
  nVector ->  xVect = xn/len;
  nVector ->  yVect = yn/len;
  
  return len;
}//makeNormalVectorVRT(double xOpor, double yOpor,

double makeUgolVectorVRT(VectorXY_VRT *nVector)
{
  //����
  double T = acos(-1.0)/180.0;
  double ugolS = asin(nVector ->  yVect)/T;
  
  if (nVector->xVect>=0 && nVector->yVect>=0)  return ugolS;
  if (nVector->xVect<=0)                       return 180.0 - ugolS;
  if (ugolS<0) ugolS += 360.0;
  
  return ugolS;
}//makeUgolVectorVRT(VectorXY_VRT *nVector)

double splitUgolSVRT(double ugolS, int *raz)
{
//������ ������
  *raz = 0;
  while (ugolS>90.0)
  {
    ugolS -= 90.0;
    (*raz)++;
  }
  return ugolS;
}//splitUgolSVRT(double ugolS, int &raz)

void makeVozvPointVRT(int lineID, double tmpShift, int cntRaz)
{
//��������� ������� ��������
  LineXY_VRT line;
  double xymin = 2.0;//0.5;
  double proc5 = 0.05;
  makeLineVVRT(X3, Y3, X2, Y2, &line);//����������� ������� 
  double y32 = 0.0;
  double x32 = 0.0;
  if(line.isVert || line.isGoriz){
   if(line.isVert) y32=x32=fabs((float)X3*proc5);
   if(line.isGoriz)y32=x32=fabs((float)Y3*proc5);
  }//if
  else{
   y32 = fabs((float)line.B*proc5);
   x32 = fabs((float)-(line.B/line.K)*proc5);
   if (fabs((float)line.B)-0.001<0.0){y32=x32=xymin;}
     }
   if (x32-xymin<0.0){x32=xymin;}
   if (y32-xymin<0.0){y32=xymin;}
  makeLineVVRT(X3, Y3, X4, Y4, &line);//����������� ������� 
  double y34 = 0.0;
  double x34 = 0.0;
  if(line.isVert || line.isGoriz){
//   y34=x34=xmin;
   if(line.isVert) y34=x34=fabs((float)X3*proc5);
   if(line.isGoriz)y34=x34=fabs((float)Y3*proc5);
  }//if
  else{
   y34 = fabs((float)line.B*proc5);
   x34 = fabs((float)-(line.B/line.K)*proc5);
   if (fabs((float)line.B)-0.001<0.0){y34=x34=xymin;}
     }
   if (x34-xymin<0.0){x34=xymin;}
   if (y34-xymin<0.0){y34=xymin;}
  makeLineVVRT(X1, Y1, X4, Y4, &line);//����������� ������� 
  double y14 = 0.0;
  double x14 = 0.0;
  if(line.isVert || line.isGoriz){
//   y14=x14=xmin;
   if(line.isVert) y14=x14=fabs((float)X1*proc5);
   if(line.isGoriz)y14=x14=fabs((float)Y1*proc5);
  }//if
  else{
   y14 = fabs((float)line.B*proc5);
   x14 = fabs((float)-(line.B/line.K)*proc5);
   if (fabs((float)line.B)-0.001<0.0){y14=x14=xymin;}
     }
   if (x14-xymin<0.0){x14=xymin;}
   if (y14-xymin<0.0){y14=xymin;}
  makeLineVVRT(X1, Y1, X2, Y2, &line);//����������� ������� 
  double y12 = 0.0;
  double x12 = 0.0;
  if(line.isVert || line.isGoriz){
//   y12=x12=xmin;
   if(line.isVert) y12=x12=fabs((float)X1*proc5);
   if(line.isGoriz)y12=x12=fabs((float)Y1*proc5);
  }//if
  else{
   y12 = fabs((float)line.B*proc5);
   x12 = fabs((float)-(line.B/line.K)*proc5);
   if (fabs((float)line.B)-0.001<0.0){y12=x12=xymin;}
     }
   if (x12-xymin<0.0){x12=xymin;}
   if (y12-xymin<0.0){y12=xymin;}

  makeLineVVRT(X3, Y3, X1, Y1, &line);//����������� ������� 
  double y31 = 0.0;
  double x31 = 0.0;
  if(line.isVert || line.isGoriz){
   if(line.isVert) y31=x31=fabs((float)X3*proc5);
   if(line.isGoriz)y31=x31=fabs((float)Y3*proc5);
  }//if
  else{
   y31 = fabs((float)line.B*proc5);
   x31 = fabs((float)-(line.B/line.K)*proc5);
   if (fabs((float)line.B)-0.001<0.0){y31=x31=xymin;}
     }
   if (x31-xymin<0.0){x31=xymin;}
   if (y31-xymin<0.0){y31=xymin;}

  switch (cntRaz)
  {
  case 0:
    if (tmpShift<45.0)
    {
      if (lineID==32)
      {
        Y32V += y32;//len3/y32;
        Y23V += y32;//len2/y23;
      }
      if (lineID==34)
      {
        Y34V -= y34;//len3/y34;
        Y43V -= y34;//len4/y43;
        Y31V -= y31;//VozvG;
        Y13V -= y31;//VozvG;
      }
      if (lineID==14)
      {
        Y14V -= y14;//len1/y14;
        Y41V -= y14;//len4/y41;
      }
      if (lineID==12)
      {
        Y12V -= y12;//len1/y12;
        Y21V -= y12;//len2/y21;
      }
    }//if
    else
    {
      if (lineID==32)
      {
        X32V -= x32;//len3/x32;
        X23V -= x32;//len2/x23;
      }
      if (lineID==34)
      {
        X34V += x34;//len3/x34;
        X43V += x34;//len4/x43;
        X31V += x31;//VozvG;
        X13V += x31;//VozvG;
      }
      if (lineID==14)
      {
        X14V += x14;//len1/x14;
        X41V += x14;//len4/x41;
      }
      if (lineID==12)
      {
        X12V -= x12;//len1/x12;
        X21V -= x12;//len2/x21;
      }
    }
    break;

  case 1:
    if (tmpShift<45.0)
    {
      if (lineID==32)
      {
        X32V -= x32;//len3/x32;
        X23V -= x32;//len2/x23;
      }
      if (lineID==34)
      {
        X34V -= x34;//len3/x34;
        X43V -= x34;//len4/x43;
        X31V -= x31;//VozvG;
        X13V -= x31;//VozvG;
      }
      if (lineID==14)
      {
        X14V -= x14;//len1/x14;
        X41V -= x14;//len4/x41;
      }
      if (lineID==12)
      {
        X12V += x12;//len1/x12;
        X21V += x12;//len2/x21;
      }
    }//if
    else
    {
      if (lineID==32)
      {
        Y32V -= y32;//len3/y32;
        Y23V -= y32;//len2/y23;
      }
      if (lineID==34)
      {
        Y34V -= y34;//len3/y34;
        Y43V -= y34;//len4/y43;
        Y31V -= y31;//VozvG;
        Y13V -= y31;//VozvG;
      }
      if (lineID==14)
      {
        Y14V -= y14;//len1/y14;
        Y41V -= y14;//len4/y41;
      }
      if (lineID==12)
      {
        Y12V += y12;//len1/y12;
        Y21V += y12;//len2/y21;
      }
    }
    break;

  case 2:
    if (tmpShift<45.0)
    {
      if (lineID==32)
      {
        Y32V -= y32;//len3/y32;
        Y23V -= y32;//len2/y23;
      }
      if (lineID==34)
      {
        Y34V -= y34;//len3/y34;
        Y43V -= y34;//len4/y43;
        Y31V -= y31;//VozvG;
        Y13V -= y31;//VozvG;
      }
      if (lineID==14)
      {
        Y14V -= y14;//len1/y14;
        Y41V -= y14;//len4/y41;
      }
      if (lineID==12)
      {
        Y12V += y12;//len1/y12;
        Y21V += y12;//len2/y21;
      }
    }//if
    else
    {
      if (lineID==32)
      {
        X32V -= x32;//len3/x32;
        X23V -= x32;//len2/x23;
      }
      if (lineID==34)
      {
        X34V -= x34;//len3/x34;
        X43V -= x34;//len4/x43;
        X31V -= x31;//VozvG;
        X13V -= x31;//VozvG;
      }
      if (lineID==14)
      {
        X14V += x14;//len1/x14;
        X41V += x14;//len4/x41;
      }
      if (lineID==12)
      {
        X12V -= x12;//len1/x12;
        X21V -= x12;//len2/x21;
      }
    }
    break;

  case 3:
    if (tmpShift<45.0)
    {
      if (lineID==32)
      {
        X32V -= x32;//len3/x32;
        X23V -= x32;//len2/x23;
      }
      if (lineID==34)
      {
        X34V -= x34;//len3/x34;
        X43V -= x34;//len4/x43;
        X31V -= x31;//VozvG;
        X13V -= x31;//VozvG;
      }
      if (lineID==14)
      {
        X14V -= x14;//len1/x14;
        X41V -= x14;//len4/x41;
      }
      if (lineID==12)
      {
        X12V -= x12;//len1/x12;
        X21V -= x12;//len2/x21;
      }
    }//if
    else
    {
      if (lineID==32)
      {
        Y32V += y32;//len3/y32;
        Y23V += y32;//len2/y23;
      }
      if (lineID==34)
      {
        Y34V -= y34;//len3/y34;
        Y43V -= y34;//len4/y43;
        Y31V -= y31;//VozvG;
        Y13V -= y31;//VozvG;
      }
      if (lineID==14)
      {
        Y14V += y14;//len1/y14;
        Y41V += y14;//len4/y41;
      }
      if (lineID==12)
      {
        Y12V += y12;//len1/y12;
        Y21V += y12;//len2/y21;
      }
    }
    break;
  default:
    ;
  }//switch

}//makeVozvPointVRT(int lineID, double tmpShift, int cntRaz)

void makeLineVVRT(double x0, double y0, double x1, double y1, LineXY_VRT *lineV)
{
//����������� ������� ��������
  lineV->isVert = 0;//false;
  lineV->isGoriz = 0;//false;
  if (fabs((float)x0-(float)x1)<MIN_STORONA)
  {
    lineV->isVert = 1;//true;
    return;
  }
  if (fabs((float)y0-(float)y1)<MIN_STORONA)
  {
    lineV->isGoriz = 1;//true;
    return;
  }

  lineV->K = (y1-y0)/(x1-x0);
  lineV->B = y0 - lineV->K*x0;
//  lineV->K = makeKoefKVRT(x0, y0, x1, y1);//��������� �
  //lineV->B = makeKoefBVRT(x0, y0, x1, y1);//��������� B
}//makeLineVVRT(double x0, double y0, double x1, double y1, LineXY_VRT *lineV)

VectorXY_VRT makeVozvCrossPointVRT(VectorXY_VRT *vector1, VectorXY_VRT *vector2, 
                                   LineXY_VRT *lineV1, LineXY_VRT *lineV2)
{
//��������� �������
  double XP, YP;
//����� �����������
  if (!(lineV1->isGoriz || lineV1->isVert || lineV2->isGoriz || lineV2->isVert))
  {
    XP = makeXPVRT(lineV1->K, lineV2->K, lineV1->B, lineV2->B);//��������� ����� �����������
    YP = lineV1->K*XP + lineV1->B;
  }//if
  else
  {
    if (lineV1->isGoriz && !(lineV2->isGoriz||lineV2->isVert))
    {
      XP = (vector1->yVect - lineV2->B)/lineV2->K;
      YP = vector1->yVect;
    }//if
    if (lineV1->isVert && !(lineV2->isGoriz||lineV2->isVert))
    {
      XP = vector1->xVect;
      YP = lineV2->K*XP + lineV2->B;
    }//if

    if (lineV2->isGoriz && !(lineV1->isGoriz||lineV1->isVert))
    {
      XP = (vector2->yVect - lineV1->B)/lineV1->K;
      YP = vector2->yVect;
    }//if
    if (lineV2->isVert && !(lineV1->isGoriz||lineV1->isVert))
    {
      XP = vector2->xVect;
      YP = lineV1->K*XP + lineV1->B;
    }//if
    if (lineV2->isVert && lineV1->isGoriz)
    {
      XP = vector2->xVect;
      YP = vector1->yVect;
    }//if
    if (lineV1->isVert && lineV2->isGoriz)
    {
      XP = vector1->xVect;
      YP = vector2->yVect;
    }//if
  }//else

   VectorXY_VRT tempXY;
   tempXY.xVect = XP;
   tempXY.yVect = YP;
  return tempXY;
}//makeVozvCrossPointVRT(VectorXY_VRT *vector1, VectorXY_VRT *vector2, 

double makeXPVRT(double K1, double K2, double B1, double B2)
{
//��������� ����� �����������
  return (B2-B1)/(K1-K2);
}//makeXPVRT(double K1, double K2, double B1, double B2)

double makeLenVectorVRT(double xn, double yn)
{
//��������� ����� ������������ Z
  return sqrt(xn*xn + yn*yn);
}//makeLenVector(VectorXY *oporZ)
/*
double makeKoefKVRT(double X0, double Y0, double X1, double Y1)
{
//��������� �
  if (fabs((float)X1)-0.001<0.0)
  {
    X0 += 1.0;
    X1 += 1.0;
  }
  return Y1/X1-(X1*Y0-X0*Y1)/(X1*X1-X0*X1);

}//makeKoefKVRT(double X0, double Y0, double X1, double Y1)

double makeKoefBVRT(double X0, double Y0, double X1, double Y1)
{
//��������� B
  return (X1*Y0-X0*Y1)/(X1-X0);
}//makeKoefBVRT(double X0, double Y0, double X1, double Y1)
*/

