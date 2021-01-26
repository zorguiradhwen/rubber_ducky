/*
 * Terminal.c
 *
 *  Created on: Jan 14, 2021
 *      Author: Radhwen
 */


#include "Terminal.h"
#include "Hal.h"

static FrameRxHandler rxhandler;

TerminalError Terminal_getChar(u8 ch)
{
	rxhandler.data[rxhandler.c_count] = ch;
	if (rxhandler.c_count == 0u)
	{
		rxhandler.frame.channel = rxhandler.data[0];
		if(rxhandler.frame.channel != TERMINAL_CHANNEL_ID)
		{
			rxhandler.discard = True;
		}
		else
		{
			;
		}
	}
	else if(rxhandler.c_count == 1u)
	{
		;
	}
	else if (rxhandler.c_count == 2u)
	{
		// calculate frame size according to size field
		memcpy(&rxhandler.frame.size, rxhandler.data + 1, 2);
	}
	else
	{
		;
	}

	rxhandler.c_count++;
	return TERMINAL_OK;
}

TerminalError Terminal_getFrame();
TerminalError Terminal_process()
{
	u16 processedBytes = 0;
	u8 processedArgs = 0;
	if (frameLen == 0)
	{
		return INVALID_FRAME;
	}
	else if(frameData[0] != TERMINAL_CHANNEL_ID)
	{
		return WRONG_CHANNEL;
	}
	else if(frameLen < 4)
	{
		return INVALID_FRAME;
	}
	else
	{
		frame.channel = frameData[0];
		memcpy(&frame.cmdID, frameData+1, 2);
		frame.argsCount = frameData[3];
		processedBytes = 4;
		while (processedBytes < frameLen && processedArgs < frame.argsCount)
		{

		}


	}
}

TerminalError Terminal_init()
{
	/*
	 * Initializing Frame reception
	 */
	memset(rxhandler.data, 0x00, MAX_ARG_COUNT * MAX_ARG_SIZE + 7);
	rxhandler.c_count = 0u;
	rxhandler.size = 0u;
	rxhandler.iscomplete = False;
	rxhandler.discard = False;
	rxhandler.frame.channel = 0u;
	rxhandler.frame.cmd_id = 0u;
	rxhandler.frame.status = 0u;
	rxhandler.frame.args_count = 0u;
	rxhandler.frame.size = 0u;
	u8 i = 0u;
	for (i = 0u; i < MAX_ARG_COUNT; i++)
	{
		rxhandler.frame.args[i].size = 0u;
		memset(rxhandler.frame.args[i].data, 0x00, MAX_ARG_SIZE);
	}
	rxhandler.frame.crc = 0u;
	return TERMINAL_OK;

}


