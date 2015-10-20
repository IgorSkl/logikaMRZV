
void INITustrangCOMPONENT(short total);
void INITIOCmdCOMPONENT();
void INITTLCmdCOMPONENT();
void INITENACmdCOMPONENT();
void PREPAREustCOMPONENT(short total);
void INITtimersCOMPONENT();
void addCOMPONENT(short numK);
void initCOMPONENT(short total);
void deleteCOMPONENT(short cntC);
void * getShadowBuf();
void TopAddTEMPLOGIC(short cntTL);
void TopAddENACmd(short cntENA);
void DeleteTEMPLOGIC(short offsetTL, short cntTL);
void DeleteENACmd(short offsetENA, short cntENA);

void addCOMPONENT_WL(short numK);
void initCOMPONENT_WL(short total);
void INITIOCmdCOMPONENT_WL();
void INITTLCmdCOMPONENT_WL();
void INITENACmdCOMPONENT_WL();
void INITustrangCOMPONENT_WL(short total);
void TopAddTEMPLOGIC_WL(short cntTL);
void TopAddENACmd_WL(short cntENA);
void PREPAREustCOMPONENT_WL(short total);
void INITtimersCOMPONENT_WL();
void DeleteTEMPLOGIC_WL(short offsetTL, short cntTL);
void DeleteENACmd_WL(short offsetENA, short cntENA);
void deleteCOMPONENT_WL(short cntC);

int getOffsetTimersCnf_WL(int off);
int getOffsetIOCmdCnf_WL(int off);
int getOffsetENACmdCnf_WL(int off);
int getOffsetTLCmdCnf_WL(int off);
int getOffsetTimersCnf(int off);
int getOffsetIOCmdCnf(int off);
int getOffsetENACmdCnf(int off);
int getOffsetTLCmdCnf(int off);
int getOffsetSPVUstCnf(int off);



