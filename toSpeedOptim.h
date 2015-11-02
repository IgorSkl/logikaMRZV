
void EXElogicCOMPONENT();
void CompressorToQuadro(int *p128, UNS_32 *pQuadro);
void CompressorToActualCMD();
void  detectorLevelUP(int level, int offset_uSrab, int offset_uVozv, int offset_out);
void  detectorLevelDOWN(int level, int offset_uSrab, int offset_uVozv, int offset_out);
void  detectorLevelUP3F(int *level, int offset_uSrab, int offset_uVozv, int offset_out);
void  detectorLevelDOWN3F(int *level, int offset_uSrab, int offset_uVozv, int offset_out);
void TranslateQuadroToWideRTCmd(UNS_32 *pQuadro);
int  MultiBitWorkerHostQuadro(UNS_32 *pQuadro, int (*pfW)(short idx));
int MultiBitWorkerHostQuadroWL(UNS_32 *pQuadro, int (*pfW)(short idx));
int pfWorker5(short idx);
void CommonMeasureLogic();
int SelectorDVdriverLow();
int SelectorDVdriverMidd();
int SelectorDVdriverHi();
int addCDItrig(int cdi_bdvv1);
int addReleTrig(int rele_bdvv1);
int elementOR(int lgm);
int elementAND(int lgm);
void elementXOR(int lgm);
void dvUnionMakerLow(UNS_32 selectorDV, UNS_32 *dvUnion);
void dvUnionMakerMidd(UNS_32 selectorDV, UNS_32 *dvUnion);
void dvUnionMakerHi(UNS_32 selectorDV, UNS_32 *dvUnion);
UNS_32 WorkRangirRele();
UNS_32 WorkRangirCDI();

void EXElogicCOMPONENT_WL();
void TranslateINTERFACE();



