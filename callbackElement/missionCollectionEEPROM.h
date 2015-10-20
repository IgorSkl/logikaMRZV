
void Build_cbMission_1BWRITE_MASSIV(char *massiv, int srcB64, int dstB64);
void Build_cbMission_1BREAD_MASSIV (char *massiv, int offset, int dstB64);
//void Build_cbMission_WRITE_EXT1MASSIV(char *massiv, int src, int dst);
void Build_cbMission_WRITE_EXTALTER(char *massiv);
void Build_cbMission_WRITE_USTALTER(char *massiv);
void FullStepWorkEEPROM(UNS_8 *data, short cntBytesArgument);
void HalfStepWorkEEPROM_Begin(UNS_8 *data, short cntBytesArgument);
void HalfStepWorkEEPROM_Middle(UNS_8 *data, short cntBytesArgument);
void HalfStepWorkEEPROM_Ending();

void Build_cbMission_WRITE_EXTALTER_DEVICE2(char *massiv);
void Build_cbMission_WRITE_EXT1MASSIV_DEVICE2(char *massiv, int src, int dst);
void Build_cbMission_1BWRITE_MASSIV_DEVICE2(char *massiv, int srcB64, int dstB64);
void Build_cbMission_1BREAD_MASSIV_DEVICE2(char *massiv, int srcB64, int dstB64);
