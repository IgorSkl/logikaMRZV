
int stepElementSaveUSTAVKItoEEPROM(int);
int stepElementReadUSTAVKItoEEPROM(int);
int stepElementRead1USTAVKItoEEPROM(int);
int stepElementSaveRANGtoEEPROM(int);
int stepElementReadRANGtoEEPROM(int);
int stepElementRead1RANGtoEEPROM(int);
int stepElementReadEXTPRItoEEPROM(int);
int stepElementReadEXTtoEEPROM(int);
int stepElementUSTALTERtoEEPROM();
int savePARAMtoEEPROM(int);
int saveEXTtoEEPROM(int);
int readPARAMfromEEPROM();
int controlPREPAREalter();
int controlPREPAREext();
int controlPREPAREust();
int controlPREPARErang();
int controlSaveUst();
int controlSaveRang();
int controlSaveExt();
int controlWriteEXTALTER();
int controlWriteUSTALTER();
int breakEEPROM(int alter_offset);

int writeUSTALTERtoEEPROM(int);
void dataAccessEEPROM();
void cicloGrammaEEPROM_DEVICE1();
void cicloGrammaEEPROM_DEVICE2();

int stepElementSaveEXTtoEEPROM_DEVICE2(int);
int writeEXTALTERtoEEPROM_DEVICE2(int);
int stepElementEXTALTERtoEEPROM_DEVICE2();
