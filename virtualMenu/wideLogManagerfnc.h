

void MngWideLogPrepareArrayWIDELOGtoEdit();
UNS_32 * MngRangGetPointerLEWIDELOGtoEdit();
UNS_32 * MngWLGetPointerLEWLtoEdit_PRM(int le);
UNS_32 * MngWLGetLEWLtoEdit_PRM(int numLE);
void MngWLEndingEditArrayWIDELOG();
short SetLEToClon(int idxCmd, int numLE, int typesCmd);
short SetCmdToLE(short kodC, short numClon, short numIO, short numLE, short typesCmd);
void SetTypLE(short numLE, short typesLE);
void ClearTypesLE();
void ClearWIDELOG();
short ApplyDVMask(int numUVV);
short ApplyDVMaskToRead(int numUVV);

short SetCmdToLE_WL(short kodC, short numClon, short numIO, short numLE, short typesCmd);

