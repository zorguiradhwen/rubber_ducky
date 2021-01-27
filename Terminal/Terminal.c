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
	TerminalError result = TERMINAL_OK;
	rxhandler.data[rxhandler.c_count] = ch;
	if (rxhandler.c_count == 0u)
	{
		rxhandler.frame.channel = rxhandler.data[0];
		if(rxhandler.frame.channel != TERMINAL_CHANNEL_ID)
		{
			rxhandler.discard = True;
			result = INVALID_FRAME;
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
		memcpy(&rxhandler.frame.size, rxhandler.data + 1u, 2u);
	}
	else
	{
		if ((rxhandler.c_count + 1u) == rxhandler.frame.size)
		{
			rxhandler.iscomplete = True;
			result = Terminal_getFrame();
		}
		else
		{
			;
		}
	}
	rxhandler.c_count++;
	return result;
}

TerminalError Terminal_getFrame()
{
	u16 bytes_read = 0u;
		TerminalError result = TERMINAL_OK;
		if(rxhandler.discard == False && rxhandler.iscomplete == True)
		{
			rxhandler.frame.status = rxhandler.data[3];
			memcpy(&rxhandler.frame.cmd_id, rxhandler.data + 4u, 2u);
			rxhandler.frame.args_count = rxhandler.data[6u];
			if(rxhandler.frame.args_count > MAX_ARG_COUNT)
			{
				result = EXCESS_PARAMS;
				rxhandler.discard = True;
			}
			else
			{
				bytes_read = 7u;
				for(u8 i = 0; i < rxhandler.frame.args_count; i++)
				{
					rxhandler.frame.args[i].size = rxhandler.data[bytes_read];
					if (rxhandler.frame.args[i].size > MAX_ARG_SIZE)
					{
						result = EXCESS_ARGSIZE;
						rxhandler.discard = True;
						break;
					}
					else if(rxhandler.frame.args[i].size == 0u)
					{
						result = NULL_ARG;
						rxhandler.discard = True;
						break;
					}
					else
					{
						bytes_read++;
						memcpy(rxhandler.frame.args[i].data, \
								rxhandler.data + bytes_read, rxhandler.frame.args[i].size);
						bytes_read += rxhandler.frame.args[i].size;
						if(bytes_read > rxhandler.size - 2u)
						{
							result = INVALID_FRAME;
							rxhandler.discard = True;
							break;
						}
						else
						{
							;
						}
					}
				}
				memcpy(&rxhandler.frame.crc, ((rxhandler.data) + (rxhandler.size - 2u)), 2u);
				//TODO : check crc integrity

			}
		}
		else
		{
			;
		}
		return result;
}
TerminalError Terminal_process()
{

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
	rxhandler.isprocessed = False;
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


