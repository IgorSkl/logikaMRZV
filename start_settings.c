#include "header.h"

/*************************************************************************
�������� ����������� ������
*************************************************************************/
void global_vareiables_installation(void)
{
}
/*************************************************************************/

/**************************************/
//���������� �������� SRAM
/**************************************/
void test_external_SRAM(void)
{
  //���������� ������� ���������� ���
  unsigned int size_SRAM_4bytes;

  //��������� �������� �� ������� ������ �������� ���������� ���'��
  unsigned int *point, *point_tmp;

#ifdef _STATIC_MEMORY_BOOT
  //���������� ������� ������������� ���
  size_SRAM_4bytes = ((((unsigned int)&__ICFEDIT_region_RAM_date_no_cache_end__) + 1) - ((unsigned int)&__ICFEDIT_region_RAM_code_start__))  >> 2;

  //��������� �������� �� ������� �������� ���������� ���'��
  point = ((unsigned int *)&__ICFEDIT_region_RAM_code_start__);
#else
  //���������� ������� ������������� ���
  size_SRAM_4bytes = ((((unsigned int)&__ICFEDIT_region_RAM_date_no_cache_end__) + 1) - ((unsigned int)&__ICFEDIT_region_RAM_date_start__))  >> 2;

  //��������� �������� �� ������� �������� ���������� ���'��
  point = ((unsigned int *)&__ICFEDIT_region_RAM_date_start__);
#endif
  point_tmp = point;

  //���������� ����� ������ ������� ���������� ���'�� �� �������
  for (unsigned int i = 0; i < size_SRAM_4bytes; i++)
  {
    unsigned short int tmp, tmp_inv;
    tmp = i & 0xffff;
    tmp_inv = (unsigned short int)(~tmp);

    *point_tmp++ = (tmp_inv << 16) | tmp;
  }

  //���������� �����������, �� � ��� ������� �������� � �����, �� �� ���������� ��������
  unsigned int i = 0;
  unsigned int error = 0;
  while((i < size_SRAM_4bytes) && (error == 0))
  {
    unsigned short int tmp, tmp_inv;
    tmp = (i & 0xffff);
    tmp_inv = (unsigned short int)(~tmp);

    if ((*point) == ((tmp_inv << 16) | tmp))
    {
      //���� ���� ������ ������� �����
      i++;
      *point++ = 0;
    }
    else
    {
      //���� ���� ������ �� ������� �����
      error = 0xff;
    }
  }

  if (error == 0 ) external_SRAM_OK = EXTERNAL_SRAM_OK;
  else external_SRAM_OK = 0;
}
/**************************************/

