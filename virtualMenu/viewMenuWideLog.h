
void OpenTypLE();
void convert_submenutyp(short numStr);
void SetTitleLE(int le, char *title);
void OpenMenuLE();
void PereinitViewMenuLE(short flg);
void OpenViewLE();
void PereinitViewLE(short flg);
short  KadrMenuFormat_viewLE(void *workCntr);//(WorkControl *workCntr);
void ClickOpenEditWL(UNS_32 *cmdLE);
short  KadrMenuFormat_openEditWL(void *workCntr);//(WorkControl *workCntr);
void WLRedactor(short cmdPosition);
void ClickProcessEditWL();
short  KadrMenuFormat_prc_editWL(void *workCntr);//(WorkControl *workCntr);
void setComonDQuadro(UNS_32* cmnDQuadro);
short setNameIOWL(int i, char *strIO);
short SetNameAndConditionCmdPositionLE(char *txtName, short cmdPosition);
void  FinishEditWL(int);
void  ClickEditWLOKButton();

//void OpenMenuWL();
//void SetAllTitleLE();
//void SetNameMenuTyp();
//void SelectTypLE();
short SetConditionCmdPositionLE(short cmdPosition);
void PereinitCnfWL(short flg);
void OpenMenuCnfWL();          
void  ConfigMakerWL();
short GetKodCompRpzWL(short numL);
void  AddCompIzRpz_WL(short numK);


