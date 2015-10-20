
#define UST_NOWORK    -1
//������� ������ ��� �����
#define SAVE_UST_BUSY      1
//������� ������ ��� ��������
#define SAVE_UST_COMPLETE  2
//������� ������ ���� �����
#define SAVE_RANG_BUSY     3
//������� ������ ���� ��������
#define SAVE_RANG_COMPLETE 4
//������� ������ ext �����
#define SAVE_EXT_BUSY      5
//������� ������ ext ��������
#define SAVE_EXT_COMPLETE  6

//������� ������ ��� �����
#define READ_UST_BUSY      7
//������� ������ ��� ��������
#define READ_UST_COMPLETE  8
//������� ������ ���� �����
#define READ_RANG_BUSY     9
//������� ������ ���� ��������
#define READ_RANG_COMPLETE 10
//������� ������ ext �����
#define READ_EXT_BUSY      11
//������� ������ ext ��������
#define READ_EXT_COMPLETE  12
//������� ������ alter �����
#define READ_ALT_BUSY      13
//������� ������ ext alter �����
#define WRITE_EXTALTER_BUSY  14
//������� ������ alter ������� � ���� �����
#define WRITE_USTALTER_BUSY  15
//������� ������ ext alter ��������
#define WRITE_EXTALTER_COMPLETE  16
//������� ������ alter ������� � ���� ��������
#define WRITE_USTALTER_COMPLETE  17
//������� ������ ������� �����
#define BREAK_BUSY               18
//������� ������ ������� ��������
#define BREAK_COMPLETE           19

//����� alter ext
#define EXTALTER_MASKA  0x0001
//����� alter ��� ����
#define USTALTER_MASKA  0x0100

//�-�� ������64 ��� ���� ������� EEPROM
//2001*4
#define MAX_B64UST    126
//�-�� ������64 ��� ���� ���� EEPROM
//(36+16+14)*10*4
#define MAX_B64RANG   42
//�-�� ������64 ��� ���� ext EEPROM
//50*4
#define MAX_B64EXT    4

//�������� 1 ��� ���� ext EEPROM
#define OFF1_B64EXT   0
//�������� 2 ��� ���� ext EEPROM
#define OFF2_B64EXT   (OFF1_B64EXT +MAX_B64EXT)    
//�������� 1 ��� ���� ��� EEPROM
#define OFF1_B64UST   (OFF2_B64EXT +MAX_B64EXT)    
//�������� 2 ��� ���� ��� EEPROM
#define OFF2_B64UST   (OFF1_B64UST +MAX_B64UST)    
//�������� 1 ��� ���� ���� EEPROM
#define OFF1_B64RANG  (OFF2_B64UST +MAX_B64UST)   
//�������� 2 ��� ���� ���� EEPROM
#define OFF2_B64RANG  (OFF1_B64RANG +MAX_B64RANG)  

