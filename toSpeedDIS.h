
//��������� ���
typedef struct
{
 short title_year;
 short title_mon;
 short title_date;
 short title_hour;
 short title_min;
 short title_sec;
 short len_dis;
 UNS_32 oldDIS[DQUADRO];
}TITLE_DIS;

typedef struct
{
  UNS_32 reltime;//������� �����
  UNS_32 pActualCMD[DQUADRO];//�������
}ELEMENT_DIS;

//����������� ���
typedef struct
{
  TITLE_DIS title_dis;//��������� ���
  ELEMENT_DIS bodyDIS[SIZE_DIS];
}REGISTRATOR_DIS;

int MakeRDIScmdPusk();
int MakeUROVcmdPusk();
int MakeAPVcmdPusk();
int isActivityDIS();
void StartDiscretReg();
void DiskretRegWorking();

