
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

typedef int (puskOFfunction(int cmd, int numOF));//int num));//указат на ф-цию номер команды
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
//маски для 16 опред функций UROV APV OT
UNS_32 pP1OFcmdMaska[DQUADRO];//определение Запуск1ОФ
UNS_32 pP2OFcmdMaska[DQUADRO];//определение Запуск2ОФ
UNS_32 pP3OFcmdMaska[DQUADRO];//определение Запуск3ОФ
//----------------------------------------
UNS_32 pP1OF2cmdMaska[DQUADRO];//определение Запуск1ОФ2
UNS_32 pP2OF2cmdMaska[DQUADRO];//определение Запуск2ОФ2
UNS_32 pP3OF2cmdMaska[DQUADRO];//определение Запуск3ОФ2
//----------------------------------------
UNS_32 pP1OF3cmdMaska[DQUADRO];//определение Запуск1ОФ3
UNS_32 pP2OF3cmdMaska[DQUADRO];//определение Запуск2ОФ3
UNS_32 pP3OF3cmdMaska[DQUADRO];//определение Запуск3ОФ3
//----------------------------------------
UNS_32 pP1OF4cmdMaska[DQUADRO];//определение Запуск1ОФ4
UNS_32 pP2OF4cmdMaska[DQUADRO];//определение Запуск2ОФ4
UNS_32 pP3OF4cmdMaska[DQUADRO];//определение Запуск3ОФ4
//----------------------------------------
UNS_32 pP1OF5cmdMaska[DQUADRO];//определение Запуск1ОФ5
UNS_32 pP2OF5cmdMaska[DQUADRO];//определение Запуск2ОФ5
UNS_32 pP3OF5cmdMaska[DQUADRO];//определение Запуск3ОФ5
//----------------------------------------
UNS_32 pP1OF6cmdMaska[DQUADRO];//определение Запуск1ОФ6
UNS_32 pP2OF6cmdMaska[DQUADRO];//определение Запуск2ОФ6
UNS_32 pP3OF6cmdMaska[DQUADRO];//определение Запуск3ОФ6
//----------------------------------------
UNS_32 pP1OF7cmdMaska[DQUADRO];//определение Запуск1ОФ7
UNS_32 pP2OF7cmdMaska[DQUADRO];//определение Запуск2ОФ7
UNS_32 pP3OF7cmdMaska[DQUADRO];//определение Запуск3ОФ7
//----------------------------------------
UNS_32 pP1OF8cmdMaska[DQUADRO];//определение Запуск1ОФ8
UNS_32 pP2OF8cmdMaska[DQUADRO];//определение Запуск2ОФ8
UNS_32 pP3OF8cmdMaska[DQUADRO];//определение Запуск3ОФ8
//----------------------------------------
UNS_32 pP1OF9cmdMaska[DQUADRO];//определение Запуск1ОФ9
UNS_32 pP2OF9cmdMaska[DQUADRO];//определение Запуск2ОФ9
UNS_32 pP3OF9cmdMaska[DQUADRO];//определение Запуск3ОФ9
//----------------------------------------
UNS_32 pP1OF10cmdMaska[DQUADRO];//определение Запуск1ОФ10
UNS_32 pP2OF10cmdMaska[DQUADRO];//определение Запуск2ОФ10
UNS_32 pP3OF10cmdMaska[DQUADRO];//определение Запуск3ОФ10
//----------------------------------------
UNS_32 pP1OF11cmdMaska[DQUADRO];//определение Запуск1ОФ11
UNS_32 pP2OF11cmdMaska[DQUADRO];//определение Запуск2ОФ11
UNS_32 pP3OF11cmdMaska[DQUADRO];//определение Запуск3ОФ11
//----------------------------------------
UNS_32 pP1OF12cmdMaska[DQUADRO];//определение Запуск1ОФ12
UNS_32 pP2OF12cmdMaska[DQUADRO];//определение Запуск2ОФ12
UNS_32 pP3OF12cmdMaska[DQUADRO];//определение Запуск3ОФ12
//----------------------------------------
UNS_32 pP1OF13cmdMaska[DQUADRO];//определение Запуск1ОФ13
UNS_32 pP2OF13cmdMaska[DQUADRO];//определение Запуск2ОФ13
UNS_32 pP3OF13cmdMaska[DQUADRO];//определение Запуск3ОФ13
//----------------------------------------
UNS_32 pP1OF14cmdMaska[DQUADRO];//определение Запуск1ОФ14
UNS_32 pP2OF14cmdMaska[DQUADRO];//определение Запуск2ОФ14
UNS_32 pP3OF14cmdMaska[DQUADRO];//определение Запуск3ОФ14
//----------------------------------------
UNS_32 pP1OF15cmdMaska[DQUADRO];//определение Запуск1ОФ15
UNS_32 pP2OF15cmdMaska[DQUADRO];//определение Запуск2ОФ15
UNS_32 pP3OF15cmdMaska[DQUADRO];//определение Запуск3ОФ15
//----------------------------------------
UNS_32 pP1OF16cmdMaska[DQUADRO];//определение Запуск1ОФ16
UNS_32 pP2OF16cmdMaska[DQUADRO];//определение Запуск2ОФ16
UNS_32 pP3OF16cmdMaska[DQUADRO];//определение Запуск3ОФ16
}MaskaOTAPVUROVOFcmd;

typedef struct 
{
//маски для 8 опред OT
UNS_32 pP1OT1cmdMaska[DQUADRO];//определение Запуск1ОT1
UNS_32 pP2OT1cmdMaska[DQUADRO];//определение Запуск2ОT1-
UNS_32 pP3OT1cmdMaska[DQUADRO];//определение Запуск3ОT1
UNS_32 pP4OT1cmdMaska[DQUADRO];//определение Запуск4ОT1
//----------------------------------------
UNS_32 pP1OT2cmdMaska[DQUADRO];//определение Запуск1ОT2
UNS_32 pP2OT2cmdMaska[DQUADRO];//определение Запуск2ОT2
UNS_32 pP3OT2cmdMaska[DQUADRO];//определение Запуск3ОT2
UNS_32 pP4OT2cmdMaska[DQUADRO];//определение Запуск4ОT2
//----------------------------------------
UNS_32 pP1OT3cmdMaska[DQUADRO];//определение Запуск1ОT3
UNS_32 pP2OT3cmdMaska[DQUADRO];//определение Запуск2ОT3
UNS_32 pP3OT3cmdMaska[DQUADRO];//определение Запуск3ОT3
UNS_32 pP4OT3cmdMaska[DQUADRO];//определение Запуск4ОT3
//----------------------------------------
UNS_32 pP1OT4cmdMaska[DQUADRO];//определение Запуск1ОT4
UNS_32 pP2OT4cmdMaska[DQUADRO];//определение Запуск2ОT4
UNS_32 pP3OT4cmdMaska[DQUADRO];//определение Запуск3ОT4
UNS_32 pP4OT4cmdMaska[DQUADRO];//определение Запуск4ОT4
//----------------------------------------
UNS_32 pP1OT5cmdMaska[DQUADRO];//определение Запуск1ОT5
UNS_32 pP2OT5cmdMaska[DQUADRO];//определение Запуск2ОT5
UNS_32 pP3OT5cmdMaska[DQUADRO];//определение Запуск3ОT5
UNS_32 pP4OT5cmdMaska[DQUADRO];//определение Запуск4ОT5
//----------------------------------------
UNS_32 pP1OT6cmdMaska[DQUADRO];//определение Запуск1ОT6
UNS_32 pP2OT6cmdMaska[DQUADRO];//определение Запуск2ОT6
UNS_32 pP3OT6cmdMaska[DQUADRO];//определение Запуск3ОT6
UNS_32 pP4OT6cmdMaska[DQUADRO];//определение Запуск4ОT6
//----------------------------------------
UNS_32 pP1OT7cmdMaska[DQUADRO];//определение Запуск1ОT7
UNS_32 pP2OT7cmdMaska[DQUADRO];//определение Запуск2ОT7
UNS_32 pP3OT7cmdMaska[DQUADRO];//определение Запуск3ОT7
UNS_32 pP4OT7cmdMaska[DQUADRO];//определение Запуск4ОT7
//----------------------------------------
UNS_32 pP1OT8cmdMaska[DQUADRO];//определение Запуск1ОT8
UNS_32 pP2OT8cmdMaska[DQUADRO];//определение Запуск2ОT8
UNS_32 pP3OT8cmdMaska[DQUADRO];//определение Запуск3ОT8
UNS_32 pP4OT8cmdMaska[DQUADRO];//определение Запуск4ОT8
//----------------------------------------
}MaskaOTcmd;
