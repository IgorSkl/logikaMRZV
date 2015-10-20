
#define MAX_UGOL       170.0
#define MAX_UGOL_SUMMA 300.0
#define MAX_DIAGONAL   200.0
#define MIN_DIAGONAL   5.0
#define MIN_STORONA    0.1

#define INT_64 long long
#define TO_INTEGER64 10000.0

 #define iX1_64 0
 #define iY1_64 1

 #define iX2_64 2
 #define iY2_64 3

 #define iX3_64 4
 #define iY3_64 5

 #define iX4_64 6
 #define iY4_64 7

 #define iX14V_64 8
 #define iY14V_64 9
 #define iX13V_64 8
 #define iY13V_64 9

 #define iX21V_64 10
 #define iY21V_64 11

 #define iX32V_64 12
 #define iY32V_64 13

 #define iX41V_64 14
 #define iY41V_64 15

typedef struct  {
     double xVect;
     double yVect;
     }VectorXY_VRT;

typedef struct  {
     double K;
     double B;
     char  isGoriz;
     char  isVert;
        }LineXY_VRT;

typedef struct  {
     INT_64 xVect_64;
     INT_64 yVect_64;
     }VectorXY_64;

enum ErrorZona
{
 ERROR_1_POINT = 5,//������ 2 �����
 ERROR_2_POINT,//������ 2 �����
 ERROR_3_POINT,//������ 3 �����
 ERROR_4_POINT,//������ 4 �����
 ERROR_31_DIAGONAL,//������ ��������� 3-1 �� � �����
 ERROR_42_DIAGONAL,//������ ��������� 4-2 �� � �����
 ERROR_12_STORONA,//������ �������� ������� 12
 ERROR_14_STORONA,//������ �������� ������� 14
 ERROR_34_STORONA,//������ �������� ������� 34
 ERROR_32_STORONA,//������ �������� ������� 32
 ERROR_31_STORONA,//������ �������� ������� 31
 ERROR_1_UGOL,//������ ���� � ����� 1
 ERROR_2_UGOL,//������ ���� � ����� 2
 ERROR_3_UGOL,//������ ���� � ����� 3
 ERROR_4_UGOL,//������ ���� � ����� 4
 ERROR_31_SUMMAUGOL,//����� ����� 3-1 ������ �����
 ERROR_42_SUMMAUGOL//����� ����� 4-2 ������ �����
};


enum IsZonaEnum
{
//��������� � ���� DZ
 ISZ_DZ1OFA = 0,
 ISZ_DZ1OFB,
 ISZ_DZ1OFC,

 ISZ_DZ2OFA,
 ISZ_DZ2OFB,
 ISZ_DZ2OFC,

 ISZ_DZ3OFA,
 ISZ_DZ3OFB,
 ISZ_DZ3OFC,

 ISZ_DZ4OFA,
 ISZ_DZ4OFB,
 ISZ_DZ4OFC,

 ISZ_DZ5OFA,
 ISZ_DZ5OFB,
 ISZ_DZ5OFC,

 ISZ_DZ1MFA,
 ISZ_DZ1MFB,
 ISZ_DZ1MFC,

 ISZ_DZ2MFA,
 ISZ_DZ2MFB,
 ISZ_DZ2MFC,

 ISZ_DZ3MFA,
 ISZ_DZ3MFB,
 ISZ_DZ3MFC,

 ISZ_DZ4MFA,
 ISZ_DZ4MFB,
 ISZ_DZ4MFC,

 ISZ_DZ5MFA,
 ISZ_DZ5MFB,
 ISZ_DZ5MFC

};//


