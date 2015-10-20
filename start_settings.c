#include "header.h"

/*************************************************************************
Стартова ініціалізація змінних
*************************************************************************/
void global_vareiables_installation(void)
{
}
/*************************************************************************/

/**************************************/
//Тестування зовнішньої SRAM
/**************************************/
void test_external_SRAM(void)
{
  //Визнапчаємо кількість двохбайтих слів
  unsigned int size_SRAM_4bytes;

  //Визначаємо вказівник на останню адресу зовнішньої оперативної пам'яті
  unsigned int *point, *point_tmp;

#ifdef _STATIC_MEMORY_BOOT
  //Визнапчаємо кількість чотирибайтних слів
  size_SRAM_4bytes = ((((unsigned int)&__ICFEDIT_region_RAM_date_no_cache_end__) + 1) - ((unsigned int)&__ICFEDIT_region_RAM_code_start__))  >> 2;

  //Визначаємо вказівник на початок зовнішньої оперативної пам'яті
  point = ((unsigned int *)&__ICFEDIT_region_RAM_code_start__);
#else
  //Визнапчаємо кількість чотирибайтних слів
  size_SRAM_4bytes = ((((unsigned int)&__ICFEDIT_region_RAM_date_no_cache_end__) + 1) - ((unsigned int)&__ICFEDIT_region_RAM_date_start__))  >> 2;

  //Визначаємо вказівник на початок зовнішньої оперативної пам'яті
  point = ((unsigned int *)&__ICFEDIT_region_RAM_date_start__);
#endif
  point_tmp = point;

  //Заповнюємо кожну комірку зовнішьої оперативної пам'яті її адресою
  for (unsigned int i = 0; i < size_SRAM_4bytes; i++)
  {
    unsigned short int tmp, tmp_inv;
    tmp = i & 0xffff;
    tmp_inv = (unsigned short int)(~tmp);

    *point_tmp++ = (tmp_inv << 16) | tmp;
  }

  //Перевіряємо зчитуванням, чи у всіх комірках прописані ті числа, які ми попередньо записали
  unsigned int i = 0;
  unsigned int error = 0;
  while((i < size_SRAM_4bytes) && (error == 0))
  {
    unsigned short int tmp, tmp_inv;
    tmp = (i & 0xffff);
    tmp_inv = (unsigned short int)(~tmp);

    if ((*point) == ((tmp_inv << 16) | tmp))
    {
      //Тест даної комірки пройшов вдало
      i++;
      *point++ = 0;
    }
    else
    {
      //Тест даної комірки не пройшов вдало
      error = 0xff;
    }
  }

  if (error == 0 ) external_SRAM_OK = EXTERNAL_SRAM_OK;
  else external_SRAM_OK = 0;
}
/**************************************/

