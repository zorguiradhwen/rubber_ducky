/*
 * Terminal.c
 *
 *  Created on: Jan 14, 2021
 *      Author: Radhwen
 */


#include "Terminal.h"
#include "Hal.h"

static u8 frameData[MAX_ARG_COUNT * MAX_ARG_SIZE + 4] = {0};
static u16 charCount = 0;
static u16 frameLen = 0;
static Bool frameComplete = False;
static Frame frame = {0};

TerminalError Terminal_getChar(u8 ch)
{
	if(ch == '\n')
	{
		frameLen = frameCount;
		frameCount = 0;
		frameComplete = True;
		Terminal_process();
	}
	else
	{
		frameData[charCount] = ch;
		charCount++;
	}


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
	else if(data[0] != TERMINAL_CHANNEL_ID)
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

}


