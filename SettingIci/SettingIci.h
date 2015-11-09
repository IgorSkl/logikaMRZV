
void  SettingIci_MTZ();
void  SettingIci_UMM();
void  SettingIci_DZ1();
void  SettingIci_DZ2to5();
void  SettingIci_TZNP();
void  SettingIci_NZOP();
void  SettingIci_PRM1();
void  SettingIci_APV();
void  SettingIci_UROV();
void  SettingIci_Rangir();
int isActivCmdDV(int numCmd, int numDV);
int isActivCmdRele(int numCmd, int numRele);
int isActivCmdLed(int numCmd, int numLed);
void SettingIci_RangirMTZ2DV(int nDV);
void SettingIci_RangirMTZ2Rele(int nRele);
void SettingIci_RangirMTZ2Led(int nLed);
void SettingIci_RangirUMM2DV(int nDV);
void SettingIci_RangirUMM2Rele(int nRele);
void SettingIci_RangirUMM2Led(int nLed);
void SettingIci_RangirTZNP2DV(int nDV);
void SettingIci_RangirTZNP2Rele(int nRele);
void SettingIci_RangirTZNP2Led(int nLed);
void SettingIci_RangirDZToDV(int nDV);
void SettingIci_RangirDZToRele(int nRele);
void SettingIci_RangirDZToLed(int nLed);
void SettingIci_RangirPRM2DV(int nDV);
void dataAccessICI();
void SettingIci_RangirMTZ2DV(int nDV);
void SettingIci_RangirMTZ2Rele(int nRele);
void SettingIci_RangirMTZ2Led(int nLed);
void SettingIci_RangirUMM2DV(int nDV);
void SettingIci_RangirUMM2Rele(int nRele);
void SettingIci_RangirUMM2Led(int nLed);
void SettingIci_RangirTZNP2DV(int nDV);
void SettingIci_RangirTZNP2Rele(int nRele);
void SettingIci_RangirTZNP2Led(int nLed);
void SettingIci_RangirDZToDV(int nDV);
void SettingIci_RangirDZToRele(int nRele);
void SettingIci_RangirDZToLed(int nLed);
void SettingIci_RangirPRM1ToRele(int nRele);
void SettingIci_RangirPRM1ToLed(int nRele);
void SettingIci_RangirPRM1ToDV(int nDV);
void SettingIci_RangirNZOPToRele(int nRele);
void SettingIci_RangirNZOPToLed(int nRele);
void SettingIci_RangirNZOPToDV(int nDV);
void SettingIci_APV();
void SettingIci_RangirAPVToDV(int nDV);
void SettingIci_RangirAPVToRele(int nRele);
void SettingIci_RangirAPVToLed(int nLed);
void SettingIci_UROV();
void SettingIci_RangirUROVToDV(int nDV);
void SettingIci_RangirUROVToRele(int nRele);
void SettingIci_RangirUROVToLed(int nLed);
void SettingIci_RangirOFToDV(int nDV);
void SettingIci_RangirOFToRele(int nRele);
void SettingIci_RangirOFToLed(int nLed);


void  GettingIci_MTZ();
void  GettingIci_TZNP();
void  GettingIci_UMM();
void  GettingIci_NZOP();
void  GettingIci_DZ1();
void  GettingIci_DZ2to5();

void GettingIci_RangirUMMFromLed(int nLed);
void GettingIci_RangirUMMFromRele(int nRele);
void GettingIci_RangirUMMFromDV(int nDV);
void GettingIci_RangirTZNPFromDV(int nDV);
void GettingIci_RangirTZNPFromRele(int nRele);
void GettingIci_RangirTZNPFromLed(int nLed);
void GettingIci_RangirMTZFromLed(int nLed);
void GettingIci_RangirMTZFromRele(int nRele);
void GettingIci_RangirMTZFromDV(int nDV);
void GettingIci_RangirDZFromLed(int nLed);
void GettingIci_RangirDZFromRele(int nRele);
void GettingIci_RangirDZFromDV(int nDV);
void GettingIci_RangirNZOPFromLed(int nLed);
void GettingIci_RangirNZOPFromRele(int nRele);
void GettingIci_RangirNZOPFromDV(int nDV);

void setActivCmdLed(int numCmd, int numLed);
void setActivCmdRele(int numCmd, int numRele);
void setActivCmdDV(int numCmd, int numDV);
int puskAPVotZ(int num);
int puskUROVotZ(int num);

typedef int (puskOFfunction(int cmd, int numOF));//int num));//������ �� �-��� ����� �������
int puskOTotZPLUS(int cmd, int numOT);
int puskOTotZMINUS(int cmd, int numOT);
int puskOFotZPLUS(int cmd, int numOF);
int puskOFotZMINUS(int cmd, int numOF);
int puskOFotZBLK(int cmd, int numOF);
int puskSetOTotZPLUS(int numCmd, int numOT);//AMOUNT_BYTE_FOR_OEPRF
int puskSetOTotZMINUS(int numCmd, int numOT);
int puskRstOTotZPLUS(int numCmd, int numOT);//AMOUNT_BYTE_FOR_OEPRF
int puskRstOTotZMINUS(int numCmd, int numOT);
void puskOFModern(int FlagMaska, int numOF);
void puskOTModern(int FlagMaska, int numOT);
void  SettingIci_OFPRM1(int numFUNC, int FlagMaska, int numOF);
void  SettingIci_OFDZ(int numFUNC, int FlagMaska, int numOF);
void  SettingIci_OFMTZ(int numFUNC, int FlagMaska, int numOF);
void  SettingIci_OFTZNP(int numFUNC, int FlagMaska, int numOF);
void  SettingIci_OFUMM(int numFUNC, int FlagMaska, int numOF);
void SettingIci_OFOF(int typFUNC, int FlagMaska, int numOF);
void  SettingIci_OFNZOP(int typFUNC, int FlagMaska, int numOF);
void  SettingIci_OFAPV(int typFUNC, int FlagMaska, int numOF);
void  SettingIci_OFUROV(int typFUNC, int FlagMaska, int numOF);


void SettingIci_RangirOTToDV(int nDV);
UNS_32 puskInversDV1(int offsetDV);//, int cntDV);

typedef struct 
{
//����� ��� 16 ����� ������� UROV APV OT
UNS_32 pP1OFcmdMaska[DQUADRO];//����������� ������1��
UNS_32 pP2OFcmdMaska[DQUADRO];//����������� ������2��
UNS_32 pP3OFcmdMaska[DQUADRO];//����������� ������3��
//----------------------------------------
UNS_32 pP1OF2cmdMaska[DQUADRO];//����������� ������1��2
UNS_32 pP2OF2cmdMaska[DQUADRO];//����������� ������2��2
UNS_32 pP3OF2cmdMaska[DQUADRO];//����������� ������3��2
//----------------------------------------
UNS_32 pP1OF3cmdMaska[DQUADRO];//����������� ������1��3
UNS_32 pP2OF3cmdMaska[DQUADRO];//����������� ������2��3
UNS_32 pP3OF3cmdMaska[DQUADRO];//����������� ������3��3
//----------------------------------------
UNS_32 pP1OF4cmdMaska[DQUADRO];//����������� ������1��4
UNS_32 pP2OF4cmdMaska[DQUADRO];//����������� ������2��4
UNS_32 pP3OF4cmdMaska[DQUADRO];//����������� ������3��4
//----------------------------------------
UNS_32 pP1OF5cmdMaska[DQUADRO];//����������� ������1��5
UNS_32 pP2OF5cmdMaska[DQUADRO];//����������� ������2��5
UNS_32 pP3OF5cmdMaska[DQUADRO];//����������� ������3��5
//----------------------------------------
UNS_32 pP1OF6cmdMaska[DQUADRO];//����������� ������1��6
UNS_32 pP2OF6cmdMaska[DQUADRO];//����������� ������2��6
UNS_32 pP3OF6cmdMaska[DQUADRO];//����������� ������3��6
//----------------------------------------
UNS_32 pP1OF7cmdMaska[DQUADRO];//����������� ������1��7
UNS_32 pP2OF7cmdMaska[DQUADRO];//����������� ������2��7
UNS_32 pP3OF7cmdMaska[DQUADRO];//����������� ������3��7
//----------------------------------------
UNS_32 pP1OF8cmdMaska[DQUADRO];//����������� ������1��8
UNS_32 pP2OF8cmdMaska[DQUADRO];//����������� ������2��8
UNS_32 pP3OF8cmdMaska[DQUADRO];//����������� ������3��8
//----------------------------------------
UNS_32 pP1OF9cmdMaska[DQUADRO];//����������� ������1��9
UNS_32 pP2OF9cmdMaska[DQUADRO];//����������� ������2��9
UNS_32 pP3OF9cmdMaska[DQUADRO];//����������� ������3��9
//----------------------------------------
UNS_32 pP1OF10cmdMaska[DQUADRO];//����������� ������1��10
UNS_32 pP2OF10cmdMaska[DQUADRO];//����������� ������2��10
UNS_32 pP3OF10cmdMaska[DQUADRO];//����������� ������3��10
//----------------------------------------
UNS_32 pP1OF11cmdMaska[DQUADRO];//����������� ������1��11
UNS_32 pP2OF11cmdMaska[DQUADRO];//����������� ������2��11
UNS_32 pP3OF11cmdMaska[DQUADRO];//����������� ������3��11
//----------------------------------------
UNS_32 pP1OF12cmdMaska[DQUADRO];//����������� ������1��12
UNS_32 pP2OF12cmdMaska[DQUADRO];//����������� ������2��12
UNS_32 pP3OF12cmdMaska[DQUADRO];//����������� ������3��12
//----------------------------------------
UNS_32 pP1OF13cmdMaska[DQUADRO];//����������� ������1��13
UNS_32 pP2OF13cmdMaska[DQUADRO];//����������� ������2��13
UNS_32 pP3OF13cmdMaska[DQUADRO];//����������� ������3��13
//----------------------------------------
UNS_32 pP1OF14cmdMaska[DQUADRO];//����������� ������1��14
UNS_32 pP2OF14cmdMaska[DQUADRO];//����������� ������2��14
UNS_32 pP3OF14cmdMaska[DQUADRO];//����������� ������3��14
//----------------------------------------
UNS_32 pP1OF15cmdMaska[DQUADRO];//����������� ������1��15
UNS_32 pP2OF15cmdMaska[DQUADRO];//����������� ������2��15
UNS_32 pP3OF15cmdMaska[DQUADRO];//����������� ������3��15
//----------------------------------------
UNS_32 pP1OF16cmdMaska[DQUADRO];//����������� ������1��16
UNS_32 pP2OF16cmdMaska[DQUADRO];//����������� ������2��16
UNS_32 pP3OF16cmdMaska[DQUADRO];//����������� ������3��16
}MaskaOTAPVUROVOFcmd;

typedef struct 
{
//����� ��� 8 ����� OT
UNS_32 pP1OT1cmdMaska[DQUADRO];//����������� ������1�T1
UNS_32 pP2OT1cmdMaska[DQUADRO];//����������� ������2�T1-
UNS_32 pP3OT1cmdMaska[DQUADRO];//����������� ������3�T1
UNS_32 pP4OT1cmdMaska[DQUADRO];//����������� ������4�T1
//----------------------------------------
UNS_32 pP1OT2cmdMaska[DQUADRO];//����������� ������1�T2
UNS_32 pP2OT2cmdMaska[DQUADRO];//����������� ������2�T2
UNS_32 pP3OT2cmdMaska[DQUADRO];//����������� ������3�T2
UNS_32 pP4OT2cmdMaska[DQUADRO];//����������� ������4�T2
//----------------------------------------
UNS_32 pP1OT3cmdMaska[DQUADRO];//����������� ������1�T3
UNS_32 pP2OT3cmdMaska[DQUADRO];//����������� ������2�T3
UNS_32 pP3OT3cmdMaska[DQUADRO];//����������� ������3�T3
UNS_32 pP4OT3cmdMaska[DQUADRO];//����������� ������4�T3
//----------------------------------------
UNS_32 pP1OT4cmdMaska[DQUADRO];//����������� ������1�T4
UNS_32 pP2OT4cmdMaska[DQUADRO];//����������� ������2�T4
UNS_32 pP3OT4cmdMaska[DQUADRO];//����������� ������3�T4
UNS_32 pP4OT4cmdMaska[DQUADRO];//����������� ������4�T4
//----------------------------------------
UNS_32 pP1OT5cmdMaska[DQUADRO];//����������� ������1�T5
UNS_32 pP2OT5cmdMaska[DQUADRO];//����������� ������2�T5
UNS_32 pP3OT5cmdMaska[DQUADRO];//����������� ������3�T5
UNS_32 pP4OT5cmdMaska[DQUADRO];//����������� ������4�T5
//----------------------------------------
UNS_32 pP1OT6cmdMaska[DQUADRO];//����������� ������1�T6
UNS_32 pP2OT6cmdMaska[DQUADRO];//����������� ������2�T6
UNS_32 pP3OT6cmdMaska[DQUADRO];//����������� ������3�T6
UNS_32 pP4OT6cmdMaska[DQUADRO];//����������� ������4�T6
//----------------------------------------
UNS_32 pP1OT7cmdMaska[DQUADRO];//����������� ������1�T7
UNS_32 pP2OT7cmdMaska[DQUADRO];//����������� ������2�T7
UNS_32 pP3OT7cmdMaska[DQUADRO];//����������� ������3�T7
UNS_32 pP4OT7cmdMaska[DQUADRO];//����������� ������4�T7
//----------------------------------------
UNS_32 pP1OT8cmdMaska[DQUADRO];//����������� ������1�T8
UNS_32 pP2OT8cmdMaska[DQUADRO];//����������� ������2�T8
UNS_32 pP3OT8cmdMaska[DQUADRO];//����������� ������3�T8
UNS_32 pP4OT8cmdMaska[DQUADRO];//����������� ������4�T8
//----------------------------------------
}MaskaOTcmd;
