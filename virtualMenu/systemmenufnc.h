
void ResetSystemMenu();
void SetCloseButton();
void ClickOpenButton();
void JumpAndOpen(short step);
void ShowTitleSubmenu_crr();
void New_name_clon(short kc, char *name);
void NewClonName();
void  AddCompIzRpz(short numK);
void  OpenMenuComponent();
void  DeleteComponent1();
void ConfirmDeleteButton();
void UpravlRedactor(char *nameUpr, short nBit, char * (*selectorUprStr)(short, UNS_32));
void SetPgDownButton(short flg);
void ViewToEditUst(int (*menuEditUst)());
void ViewerEditorUst(void *text);
void MakeEmptyTopSub_menu(void *src, short size);
void ViewDiskrMenu(short typeWin);
void AllComponentUstTimers();
int  SetUstToClon(short kodC, short numClon, short numUst, int newUst);
int  GetUstFromImageClon(int numBlok, short kodC, short numClon, short numUst);
void PrepareBOBV();
void PrepareBOBVtimer();
//void MakeMaskaOF();
void PrepareAllCnfComponent();

void OpenMenuComponent_WL();
void New_name_clon_WL(short kc, char *name);
void DeleteComponent1_WL();
void ConfirmDeleteButton_WL();
void AllComponentUstTimers_WL();
void PrepareAllCnfComponent_WL();

void DiskrRegList();
void ActualRegList();
void ActualDVList();
void ActualReleList();
void Load2String(int maxStr, char *title);
void View2StrWin(void *view_struct);
void Load1String(int maxStr, char *title);
void View1StrWin(void *view_struct);

void PassWord(void (*menuEdit)());
void PrepareEditMenu(void *parent);
void SystemEditUst(void *sub_menu);
void SelectorMNGBAZA(short baza);
void SelectorLIGHTLINE(void *txtstrm);
void SelectorCRRLIGHTLINE();
void SelectorTEXTCONTROL(void *control);
void SelectorSUBMENU(void *sub_menu);
void SelectorFHOME(void (*pFncGlobal)(short));
void InitFHOME(short flag);
void pullReleBO();
void pullReleBV();
void PuskAPV_UROV_OFWorking();
void OpenEditRangUVV();

int Wag_Koef_ResursVV(int Imax);



