/*
 * Terminal.h
 *
 *  Created on: Jan 14, 2021
 *      Author: Radhwen
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "Hal.h"
#include "Terminal_conf.h"

typedef enum TerminalError_e
{
	TERMINAL_OK,
	INVALID_FRAME,
	WRONG_CHANNEL,
}TerminalError;

/*
 * Frame typedefs and analysis functions
 *
 */

typedef struct CommandArgs_s
{
	u8 size;			//size in bytes
	u8 data[MAX_ARG_SIZE];

}CommandArgs;

typedef struct FrameRx_s
{
	u8  channel	 ;
	u16 size     ;
	u8  status	 ;
	u16 cmd_id	 ;
	u8  args_count;
	CommandArgs args[MAX_ARG_COUNT];
	u16 crc		 ;
}FrameRx;

typedef struct FrameRxHandler_s
{
	u8  data[MAX_ARG_COUNT * MAX_ARG_SIZE + 7];
	u16 c_count;
	u16 size;
	Bool iscomplete;
	Bool discard;
	FrameRx frame;
}FrameRxHandler;

/*
 *
 *
 */

TerminalError Terminal_getFrame();
TerminalError Terminal_getChar(u8 ch);
TerminalError Terminal_process();

TerminalError Terminal_init();




#endif /* TERMINAL_H_ */
