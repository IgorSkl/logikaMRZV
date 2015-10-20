
void MngRangDeleteQuadroRANGIR(UNS_32 *pQuadro, short offsetRangMng, short cntRangMng);
void MngRangTopAddQuadroRANGIR(UNS_32 *pQuadro, short cntRangMng);
UNS_32 * MngRangGetPointerUVVRANGIRtoEdit(int numUVV);
void MngRangPrepareArrayRANGIRtoEdit(int numUVV);
void MngRangEndingEditArrayRANGIR(int numUVV);
void MngRangDeleteNameStatusRANGIR(short offsetRangMng, short cntRangMng);
void MngRangTopAddNameStatusRANGIR(short cntRangMng, void *ionsComp);
void ClearArrayRANGIR();

short SetCmdToUVV(short kodC, short numClon, short numIO, short numUVV);
//void  ClrCmdToClon(short kodC, short numClon, short numIO, short numUVV);
//char  ChkCmdToClon(short kodC, short numClon, short numIO, short numUVV);
short SetUVVToClon(int idxCmd, int numUVV);
void  ClrUVVToClon(int idxCmd, int numUVV);
char  ChkUVVToClon(int idxCmd, int numUVV);
int GetCmdUVVFromClon(short kodC, short numClon, short numIO, short numUVV);
UNS_32 * MngRangGetPointerUVVRANGIRtoRead(int numUVV);

void MngRangTopAddNameStatusRANGIR_WL(short cntRangMng, void *ionsComp);
void MngRangDeleteNameStatusRANGIR_WL(short offsetRangMng, short cntRangMng);
void SaveCRCrang();
int getCRCrang();
void CopyEEPROMtoRANGIR();

