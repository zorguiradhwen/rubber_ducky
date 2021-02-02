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

typedef enum TerminalStatus_e
{
	TERMINAL_OK,
	INVALID_FRAME,
	WRONG_CHANNEL,
	EXCESS_PARAMS,
	EXCESS_ARGSIZE,
	NULL_ARG,
	CRC_MISMATCH
}TerminalStatus;

typedef enum TerminalState_e
{
	FRAME_INIT,
	FRAME_RECEIVING,
	FRAME_DISCARD,
	FRAME_COMPLETE,
	FRAME_PROCESSING,
	FRAME_PROCESSED,
	FRAME_EXECUTE,
	FRAME_RESPONDING,
	FRAME_RESPONDED
}TerminalState;

/*
 * Frame typedefs and analysis functions
 *
 */

typedef struct CommandParam_s
{
	u8 size;			//size in bytes
	u8 data[MAX_ARG_SIZE];

}CommandParam;

typedef struct Frame_s
{
	u8  channel	 ;
	u16 size     ;
	u8  status	 ;
	u16 cmd_id	 ;
	u8  param_count;
	CommandParam params[MAX_ARG_COUNT];
	u16 crc		 ;
}Frame;

typedef struct FrameStreamHandler_s
{
	u8  data[MAX_ARG_COUNT * MAX_ARG_SIZE + 7];
	u16 c_count;
	u16 size;
	Frame frame;
}FrameStreamHandler;

typedef TerminalStatus (*CmdFunc)(CommandParam* args, u8 args_count, CommandParam* retvals, u8 ret_count);
typedef struct TerminalCmd_s
{
	u8 id;
	CmdFunc *func;
	u8 arg_count;
	u8 ret_count;
}TerminalCmd;

typedef struct TerminalHandler_s
{
	FrameStreamHandler rxhandler;
	FrameStreamHandler txhandler;
	TerminalState state;
	TerminalCmd* cmds;
}TerminalHandler;

/*
 *
 *
 */

TerminalStatus Terminal_getFrame();
TerminalStatus Terminal_getChar(u8 ch);
TerminalStatus Terminal_process();
TerminalStatus Terminal_init();
TerminalStatus Terminal_run ();








#endif /* TERMINAL_H_ */
