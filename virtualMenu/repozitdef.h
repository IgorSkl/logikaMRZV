
typedef struct
{
  short  kodC;           //��� ����������
  char   rpzNameComponent[30];        //��� ����������
} NAME_RPZ;

typedef struct
{
  char   componentEnable;//���������� ����������
  char  (*load2RPZ)(char packet);//���� � �����������
  NAME_RPZ  rpzKodName;//��� ���� ���
  char   componentPermission;//��������� �������
} ELEMENT_RPZ;

