/*
 * Terminal.c
 *
 *  Created on: Jan 14, 2021
 *      Author: Radhwen
 */


#include "Terminal.h"
#include "Hal.h"

static TerminalHandler Terminal;


TerminalStatus Terminal_init()
{

	Terminal.state = FRAME_INIT;
	/*
	 * Initializing Frame rx
	 */
	memset(Terminal.rxhandler.data, 0u, MAX_ARG_COUNT * MAX_ARG_SIZE + 7);
	Terminal.rxhandler.c_count = 0u;
	Terminal.rxhandler.size = 0u;
	Terminal.rxhandler.frame.channel = 0u;
	Terminal.rxhandler.frame.cmd_id = 0u;
	Terminal.rxhandler.frame.status = 0u;
	Terminal.rxhandler.frame.param_count = 0u;
	Terminal.rxhandler.frame.size = 0u;
	u8 i = 0u;
	for (i = 0u; i < MAX_ARG_COUNT; i++)
	{
		Terminal.rxhandler.frame.params[i].size = 0u;
		memset(Terminal.rxhandler.frame.params[i].data, 0x00, MAX_ARG_SIZE);
	}
	Terminal.rxhandler.frame.crc = 0u;
	/*
	 * Initializing Frame tx
	 */
	memset(Terminal.txhandler.data, 0u, MAX_ARG_COUNT * MAX_ARG_SIZE + 7);
	Terminal.txhandler.c_count = 0u;
	Terminal.txhandler.size = 0u;
	Terminal.txhandler.frame.channel = 0u;
	Terminal.txhandler.frame.cmd_id = 0u;
	Terminal.txhandler.frame.status = 0u;
	Terminal.txhandler.frame.param_count = 0u;
	Terminal.txhandler.frame.size = 0u;
	for (i = 0u; i < MAX_ARG_COUNT; i++)
	{
		Terminal.txhandler.frame.params[i].size = 0u;
		memset(Terminal.txhandler.frame.params[i].data, 0x00, MAX_ARG_SIZE);
	}
	Terminal.txhandler.frame.crc = 0u;
	return TERMINAL_OK;

}

TerminalStatus Terminal_getChar(u8 ch)
{
	TerminalStatus result = TERMINAL_OK;
	if (Terminal.state == FRAME_INIT || Terminal.state == FRAME_RECEIVING)
	{
		Terminal.rxhandler.data[Terminal.rxhandler.c_count] = ch;
		if (Terminal.rxhandler.c_count == 0u && Terminal.state == FRAME_INIT)
		{
			Terminal.state = FRAME_RECEIVING;
			Terminal.rxhandler.frame.channel = Terminal.rxhandler.data[0];
			if(Terminal.rxhandler.frame.channel != TERMINAL_CHANNEL_ID)
			{
				Terminal.state = FRAME_DISCARD;
				result = INVALID_FRAME;
			}
			else
			{
				;
			}
		}
		else if(Terminal.rxhandler.c_count == 1u)
		{
			;
		}
		else if (Terminal.rxhandler.c_count == 2u)
		{
			// calculate frame size according to size field
			memcpy(&Terminal.rxhandler.frame.size, Terminal.rxhandler.data + 1u, 2u);
		}
		else
		{
			if ((Terminal.rxhandler.c_count + 1u) == Terminal.rxhandler.frame.size)
			{
				Terminal.state = FRAME_COMPLETE;
				//result = Terminal_getFrame();
			}
			else
			{
				;
			}
		}
		Terminal.rxhandler.c_count++;
	}
	else
	{
		;
	}
	return result;
}

TerminalStatus Terminal_getFrame()
{
	TerminalStatus result = TERMINAL_OK;
	u16 bytes_read = 0u;
	if(Terminal.state == FRAME_COMPLETE)
	{
		Terminal.rxhandler.frame.status = Terminal.rxhandler.data[3];
		memcpy(&Terminal.rxhandler.frame.cmd_id, Terminal.rxhandler.data + 4u, 2u);
		Terminal.rxhandler.frame.param_count = Terminal.rxhandler.data[6u];
		if(Terminal.rxhandler.frame.param_count > MAX_ARG_COUNT)
		{
			result = EXCESS_PARAMS;
			Terminal.state = FRAME_DISCARD;
		}
		else
		{
			bytes_read = 7u;
			for(u8 i = 0; i < Terminal.rxhandler.frame.param_count; i++)
			{
				Terminal.rxhandler.frame.params[i].size = Terminal.rxhandler.data[bytes_read];
				if (Terminal.rxhandler.frame.params[i].size > MAX_ARG_SIZE)
				{
					result = EXCESS_ARGSIZE;
					Terminal.state = FRAME_DISCARD;
					break;
				}
				else if(Terminal.rxhandler.frame.params[i].size == 0u)
				{
					result = NULL_ARG;
					Terminal.state = FRAME_DISCARD;
					break;
				}
				else
				{
					bytes_read++;
					memcpy(Terminal.rxhandler.frame.params[i].data,
							Terminal.rxhandler.data + bytes_read,
							Terminal.rxhandler.frame.params[i].size);
					bytes_read += Terminal.rxhandler.frame.params[i].size;
					if(bytes_read > Terminal.rxhandler.size - 2u)
					{
						result = INVALID_FRAME;
						Terminal.state = FRAME_DISCARD;
						break;
					}
					else
					{
						;
					}
				}
			}
			memcpy(&Terminal.rxhandler.frame.crc,
					((Terminal.rxhandler.data) + (Terminal.rxhandler.size - 2u)),
					2u);
			//TODO : check crc integrity

		}
	}
	else
	{
		;
	}
	return result;
}

TerminalStatus Terminal_process()
{
	TerminalStatus result = TERMINAL_OK;



	return result;
}

TerminalStatus Terminal_run()
{
	TerminalStatus result = TERMINAL_OK;

	return result;
}
