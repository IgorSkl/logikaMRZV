

short commonInitIOCmd(short cntIO);
short commonInitTLCmd(short cntTL);
void commonInitTimers(short cntT);
short commonInitENACmd(short cntENA);
void TranslateWordToWideENA(UNS_32 word);
void TranslateQuadroToWideCmd(UNS_32 *pQuadro);
void NumBitSettingWord(short nBit, UNS_32 *word);
void NumBitClearingWord(short nBit, UNS_32 *word);
char NumBitCheckWord(short nBit, UNS_32 *word);
int  CheckActualCMD(UNS_32 *cmdArr);
int  CheckActualCMDInv(UNS_32 *cmdArr);
void NumBitSettingQuadro(short nBit, UNS_32 *pQuadro);
void NumBitClearingQuadro(short nBit, UNS_32 *pQuadro);
char NumBitCheckQuadro(short nBit, UNS_32 *pQuadro);
char CheckedQuadro(UNS_32 *pQuadro1, UNS_32 *pQuadro2);
short MultiBitWorkerHostWord(UNS_32 *pWord, int (*pfW)(short idx));
int pfWorker1(short idx);
int pfWorker2(short idx);
int pfWorker3(short idx);
int pfWorker4(short idx);
short PrepareENACmd(short idxC, short offsetUpr);
void CopyWideENAToENAcmd(short offset, short cnt);
char NumBitCheckWL(short nBit, UNS_32 *pQuadro);
char CheckedWL(UNS_32 *pQuadro1, UNS_32 *pQuadro2);

void CopyWideENAToENAcmd_WL(short offset, short cnt);
void commonInitTimers_WL(short cntT);
int setCRCMassiv(int *ustmass, int cnt);


