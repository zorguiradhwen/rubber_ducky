/*
 * StreamHandler.c
 *
 *  Created on: Dec 20, 2020
 *      Author: Radhwen
 */


#include "StreamHandler.h"
#include "StreamHandler_conf.h"
#include "Hal.h"



#define STREAM_COUNT 1

Stream streams[] =
{
	{
		.handler = (StreamObject) &husart1,
		.hwAddr = USART1,
		.type = WriteStream,
		.name = "LOG",
		.id = 'L'
	}
};

static Stream currentprintfStream = streams[0];
/*
 * printf overload
 */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
	Uart_send(currentprintfStream.handler, (uint8_t *)&ch, 1);

  return ch;
}


StreamStatus Stream_init(void)
{
	  MX_USART1_UART_Init();

}

void Stream_write(StreamHandler *stream, u8* buff, u16 len)
{
	currentprintfStream = *stream;
}

void Stream_read(StreamHandler* handler, u8* buff, u16* len);
