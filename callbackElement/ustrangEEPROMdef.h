
#define UST_NOWORK    -1
//процесс записи уст занят
#define SAVE_UST_BUSY      1
//процесс записи уст завершен
#define SAVE_UST_COMPLETE  2
//процесс записи ранж занят
#define SAVE_RANG_BUSY     3
//процесс записи ранж завершен
#define SAVE_RANG_COMPLETE 4
//процесс записи ext занят
#define SAVE_EXT_BUSY      5
//процесс записи ext завершен
#define SAVE_EXT_COMPLETE  6

//процесс чтения уст занят
#define READ_UST_BUSY      7
//процесс чтения уст завершен
#define READ_UST_COMPLETE  8
//процесс чтения ранж занят
#define READ_RANG_BUSY     9
//процесс чтения ранж завершен
#define READ_RANG_COMPLETE 10
//процесс чтения ext занят
#define READ_EXT_BUSY      11
//процесс чтения ext завершен
#define READ_EXT_COMPLETE  12
//процесс чтения alter занят
#define READ_ALT_BUSY      13
//процесс записи ext alter занят
#define WRITE_EXTALTER_BUSY  14
//процесс записи alter уставок и ранж занят
#define WRITE_USTALTER_BUSY  15
//процесс записи ext alter завершен
#define WRITE_EXTALTER_COMPLETE  16
//процесс записи alter уставок и ранж завершен
#define WRITE_USTALTER_COMPLETE  17
//процесс записи ломалки занят
#define BREAK_BUSY               18
//процесс записи ломалки завершен
#define BREAK_COMPLETE           19

//маска alter ext
#define EXTALTER_MASKA  0x0001
//маска alter уст ранж
#define USTALTER_MASKA  0x0100

//к-во блоков64 при сохр уставок EEPROM
//2001*4
#define MAX_B64UST    126
//к-во блоков64 при сохр ранж EEPROM
//(36+16+14)*10*4
#define MAX_B64RANG   42
//к-во блоков64 при сохр ext EEPROM
//50*4
#define MAX_B64EXT    4

//смещение 1 при сохр ext EEPROM
#define OFF1_B64EXT   0
//смещение 2 при сохр ext EEPROM
#define OFF2_B64EXT   (OFF1_B64EXT +MAX_B64EXT)    
//смещение 1 при сохр уст EEPROM
#define OFF1_B64UST   (OFF2_B64EXT +MAX_B64EXT)    
//смещение 2 при сохр уст EEPROM
#define OFF2_B64UST   (OFF1_B64UST +MAX_B64UST)    
//смещение 1 при сохр ранж EEPROM
#define OFF1_B64RANG  (OFF2_B64UST +MAX_B64UST)   
//смещение 2 при сохр ранж EEPROM
#define OFF2_B64RANG  (OFF1_B64RANG +MAX_B64RANG)  

