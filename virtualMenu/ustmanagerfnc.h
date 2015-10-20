
void MngUstDeleteUSTAVKI(short offsetUstMng, short cntUstMng);
void MngUstTopAddUSTAVKI(short cntUstMng);
void SetUPR_COMMON1();
int  AssembleUstButton();
int  setCurrentMngUSTAVKI(int ust);
int getUstOffsetMngUSTAVKI(short offset);
UNS_32 getCurrentMngUSTAVKI();
short getOffsetMngUSTAVKI(short offset);
short getOffsetNativMngUSTAVKI(short idxC, short offsetUpr);
int getNativUstMngUSTAVKI(short idxC, short offset);
short getClonOffsetMngUSTAVKI(short idxC, short offset);
int setClonMngUSTAVKI(int idxC, int bazaOffset, int ust);
int getMngUSTAVKI(short baza, short offset);
void CopyMngUstavki(int numBlok);
void CopyEEPROMtoUstavki(int numBlok);
void SaveAsBlokUstavki(int numBlok);
int getCRCUstavki();


void MngUstTopAddUSTAVKI_WL(short cntUstMng);
void MngUstDeleteUSTAVKI_WL(short offsetUstMng, short cntUstMng);
