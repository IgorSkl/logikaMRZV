
#ifndef __HSUART_CONST__
#define __HSUART_CONST__

/**********************************************************************
*
**********************************************************************/
enum _send_state {
  HSUART_FREE = 0,
  START_READ, //1
  START_WRITE, //2
  WRITE_DATA, //3
  RESPONSE_CONFIRM, //4
  MASTER_CONFIRM, //5
  WAIT_CONFIRM_WORD, //6
  WAIT_MASTER_CONFIRM, //7
  WAIT_DATA_READ, //8
};

enum _hsuart_exceptions {
  HSUART_ERROR = 0,
};

#endif

