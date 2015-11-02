int lowLevelEEPROM_READ(short source, void* dest, int count)//CALLBACKELEMENT_TASK *cbt)
{
//TASK READ ARRAY
///*
  union
  {
    void *p;
    short s;
  } pnt;
//*/
  UNS_8 data[5];
  short cntBytesArgument = 0;//к-во байт аргумента команды
  short addrEEPROM;//адрес EEPROM
  short idx = 1;

//  pnt.p  = source;//cbt->tmDefine.source;//адрес EEPROM
  addrEEPROM = source;//pnt.s;//адрес EEPROM
  data [0] = 3;//op_cod
  data [1] = (addrEEPROM >> 8) & 0xFF;
  data [2] = (addrEEPROM >> 0) & 0xFF;
  data [3] = 0xFF;
  cntBytesArgument = 4;//к-во байт аргумента команды
  HalfStepWorkEEPROM_Begin(data, cntBytesArgument);//начало работы EEPROM

//  cbt->tmDefine.count--;
//  if(cbt->tmDefine.count>=0)
//    ((UNS_8*)cbt->tmDefine.dest)[0] = data[3];
  count--;
  if(count>=0)
    ((UNS_8*)dest)[0] = data[3];

  while(count>0)//cbt->tmDefine.count>0)
  {
    cntBytesArgument = 4;//к-во байт аргумента команды
    HalfStepWorkEEPROM_Middle(data, cntBytesArgument);//средина работы EEPROM

//    cbt->tmDefine.count -= 4;
    count -= 4;
    if(count>=0)//cbt->tmDefine.count>=0)
    {
//      ((UNS_8*)cbt->tmDefine.dest)[idx++] = data[0];
//      ((UNS_8*)cbt->tmDefine.dest)[idx++] = data[1];
//      ((UNS_8*)cbt->tmDefine.dest)[idx++] = data[2];
//      ((UNS_8*)cbt->tmDefine.dest)[idx++] = data[3];
      ((UNS_8*)dest)[idx++] = data[0];
      ((UNS_8*)dest)[idx++] = data[1];
      ((UNS_8*)dest)[idx++] = data[2];
      ((UNS_8*)dest)[idx++] = data[3];
    }//if
    else
    {
      short max=count+4;//cbt->tmDefine.count+4;
      for(short i=0; i<max; i++)
        ((UNS_8*)dest)[idx++] = data[i];
//        ((UNS_8*)cbt->tmDefine.dest)[idx++] = data[i];
      HalfStepWorkEEPROM_Ending();//закончить работу EEPROM
      return 0;//
    }//else
  }//while(cbt->tmDefine.count>0)

  HalfStepWorkEEPROM_Ending();//закончить работу EEPROM

  return 0;//
}//callBackEEPROM_READ(CALLBACKELEMENT_TASK *cbt)

int lowLevelEEPROM_WRITE(void* source, short dest, int count)//(CALLBACKELEMENT_TASK *cbt)
{
//TASK WRITE ARRAY
  union
  {
    void *p;
    short s;
  } pnt;
  UNS_8 data[5];
  short cntBytesArgument = 0;//к-во байт аргумента команды
  short addrEEPROM;//адрес EEPROM
  UNS_8 data8EEPROM;//данные EEPROM
  short idx = 1;
/*
  switch(cbt->callBackStepCntr)
  {
  case TASK_STEP0:
  {
*/
//Set Write Enable Latch
    data[0] = 6;//op_cod
    cntBytesArgument = 1;//к-во байт аргумента команды
    FullStepWorkEEPROM(data, cntBytesArgument);//полный шаг работы EEPROM

//READ STATUS REGISTER
//Ready
    data[0] = 5;//op_cod
    data[1] = 0xFF;
    cntBytesArgument = 2;//к-во байт аргумента команды
    FullStepWorkEEPROM(data, cntBytesArgument);//полный шаг работы EEPROM
    
  //wait
    if(data[1]!=2){
      //отказ EEPROM
      cbt->callBackStepCntr--;
      return 1;//остаться в CallBackElement
    }//if

//WRITE ARRAY
//    cbt->tmDefine.count--;
    count--;

    UNS_8 *source  = (UNS_8 *)source;//адрес массива

    //pnt.p  = cbt->tmDefine.dest;//адрес EEPROM
    addrEEPROM = dest;//pnt.s;//адрес EEPROM
    if(cbt->tmDefine.count>=0)
    {
      data8EEPROM = source[0];//данные EEPROM
      data [0] = 2;//op_cod
      data [1] = (addrEEPROM >> 8) & 0xFF;
      data [2] = (addrEEPROM >> 0) & 0xFF;
      data [3] = data8EEPROM;
      cntBytesArgument = 4;//к-во байт аргумента команды
      HalfStepWorkEEPROM_Begin(data, cntBytesArgument);//начало работы EEPROM
    }//if

    while(cbt->tmDefine.count>0)
    {
      cbt->tmDefine.count -= 4;
      if(cbt->tmDefine.count>=0)
      {
        data[0] = source[idx++];
        data[1] = source[idx++];
        data[2] = source[idx++];
        data[3] = source[idx++];
        cntBytesArgument = 4;//к-во байт аргумента команды
        HalfStepWorkEEPROM_Middle(data, cntBytesArgument);//средина работы EEPROM
      }//if
      else
      {
        short max=count+4;//cbt->tmDefine.count+4;
        for(short i=0; i<max; i++)
        {
          data[i] = source[idx++];//0x66;
        }//for
        cntBytesArgument = max;//к-во байт аргумента команды
        HalfStepWorkEEPROM_Middle(data, cntBytesArgument);//средина работы EEPROM
      }//else
    }//while(cbt->tmDefine.count>0)
    HalfStepWorkEEPROM_Ending();//закончить работу EEPROM
//  }
//  break;
/*
  default:
  {
//READ STATUS REGISTER
//  busy
    data[0] = 5;//op_cod
    data[1] = 0xFF;
    cntBytesArgument = 2;//к-во байт аргумента команды
    FullStepWorkEEPROM(data, cntBytesArgument);//полный шаг работы EEPROM
    if((data[1]&1)==0)
      return 0;//покинуть CallBackElement
  };
  }//switch
*/

  return 1;//остаться в CallBackElement
}//

void FullStepWorkEEPROM(UNS_8 *data, short cntBytesArgument)
//cntBytesArgument - к-во байт в аргументе
{
//полный шаг работы EEPROM
  gpio_regptr->p3_outp_clr = P3_STATE_GPIO(4);//cs EEPROM enable
  HalfStepWorkEEPROM_Middle(data, cntBytesArgument);//шаг работы EEPROM
  gpio_regptr->p3_outp_set = P3_STATE_GPIO(4);//cs EEPROM disable
}//FullStepWorkEEPROM(UNS_8 *data, short cntBytesArgument)

void HalfStepWorkEEPROM_Middle(UNS_8 *data, short cntBytesArgument)
//cntBytesArgument - к-во байт в аргументе
{
//шаг работы EEPROM
  short n_fifo;
  short idx;
  short bytes;
//transmit data
  n_fifo = cntBytesArgument;
  idx=0;
//заполняем FIFO
  while ((n_fifo > 0) &&
         ((ssp1_regptr->sr & SSP_SR_TNF) != 0))
  {
    ssp1_regptr->data = (UNS_32) data[idx];
    n_fifo--;
    idx++;
  }//while
//ждем пока трансляция не закончится
  while (((ssp1_regptr->sr & SSP_SR_BSY) != 0)) {}

//ждем принятые байты и записываем их в data
//read data
  bytes = 0;
  idx=0;
  while (bytes < cntBytesArgument)
  {
    while (((ssp1_regptr->sr & SSP_SR_RNE) != 0))
    {
      data[idx] = (UNS_8) ssp1_regptr->data;//tmp1;
      idx++;
    }//while
    bytes++;
  }//while
}//void HalfStepWorkEEPROM_Middle(UNS_8 *data, short cntBytesArgument)

void HalfStepWorkEEPROM_Begin(UNS_8 *data, short cntBytesArgument)
//cntBytesArgument - к-во байт в аргументе
{
//полу шаг работы EEPROM - начало
  gpio_regptr->p3_outp_clr = P3_STATE_GPIO(4);//cs EEPROM enable
  HalfStepWorkEEPROM_Middle(data, cntBytesArgument);//шаг работы EEPROM
}//HalfStepWorkEEPROM_Begin(UNS_8 *data, short cntBytesArgument)

void HalfStepWorkEEPROM_Ending()
{
//полу шаг работы EEPROM - закончить
  gpio_regptr->p3_outp_set = P3_STATE_GPIO(4);//cs EEPROM disable
}//HalfStepWorkEEPROM_Ending()
