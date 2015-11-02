
//����� ��������� ����������
#define MTZ_PACKET  1
#define DZ_PACKET   2
#define TZNP_PACKET 3
#define NZOP_PACKET 4

//��� �����������
#define MTZ_COMP1   10

#define DZ_COMP1    11

#define TZNP_COMP1  12

#define NZOP_COMP1  13

#define UROV_COMP1   14
#define APV_COMP1    15
#define OF_COMP1     16
#define PRM1_COMP1   17
#define WL_COMP1     18
#define PF_COMP1     19
#define UMM_COMP1    20

typedef struct
{
  void (*twin_different)( );    //�-� ��������� ���������
}  TWIN_DIFFERENT;//�������� ���������

typedef struct
{
//����� � ������ IO ������
  short  statusIO;
  char   *nameIO;
} IONAMESTATUS_COMPONENT;

typedef struct
{
  char   componentEnable;//���������� ����������

  short  kodC;           //��� ����������
  short  cntClon;   //�-�� ������
  short  numClon;   //����� �����
  short  packet;    //����� ��������� ����������
  short  permanent; //������������ ���������
  int    workToSignal; //������ �� ������

  void  (*logic)(int);//������ ����������
  int   offsetTimers;   //������ ��������
  void  (*initTimers)(short); //������� ��������
  int   offsetUstSpv;   //�������� ������� ������ �����������
  int   offsetUstMng;   //�������� ������� ������ ��������� �������
  int   cntUstMng;      //���������� ������� ���������� ������ ��������� �������
  void  (*prepareUstSpv)(short);//���������� �������
  int   (*initUstMng)(char );    //������� �������
  int   offsetIOCmd;    //������ IO ������
  int   cntIOCmd;       //���������� IO ������
  int   (*initIOCmd)(); //������� IO ������
  int   offsetTLCmd;    //������ TL ������
  int   cntTLCmd;       //���������� TL ������
  int   (*initTLCmd)(); //������� TL ������
  int   offsetENACmd;   //������ ENA ������
  int   cntENACmd;      //���������� ENA ������
  int   (*initENACmd)(); //������� ENA ������
  void  (*bo_bvCmd)(int numC, int mode, int nrele); //��������� �� �� ������
  int   (*codecUst)(char codec, short offset, int ust);   //����������-������������� �������
  int   (*isDISactiv)(int); //���������� ������������ ���
  void  (*setBOBVtimer)(int); //������� �������� �� ��

  char   nameComponent[30];        //��� ����������
  void  *sub_menu_component;//���� ����������

  TWIN_DIFFERENT *twinControl;//������ �������� ���������

  IONAMESTATUS_COMPONENT *nameStatusIO; //����� � ������ IO ������ ����������

} COMPONENT_OBJ;



