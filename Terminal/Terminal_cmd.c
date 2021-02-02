/*
 * Terminal_cmd.c
 *
 *  Created on: Jan 14, 2021
 *      Author: Radhwen
 */

#include "Terminal.h"
#include "Terminal_cmd.h"
/*
 * Include Modules
 */
#include "Hal.h"
#include "timestamp.h"
#include "logger.h"
#include "printf_override.h"

/*
 * Define Cmd Table
 */
TerminalCmd cmd[] =
{
	{
		.id = 0x0001,
		.func = (CmdFunc*)Terminal_cmd_Terminal_test_0args_0retvals,
		.arg_count = 0u,
		.ret_count = 0u
	},
	{
		.id = 0x0002,
		.func = (CmdFunc*)Terminal_cmd_Terminal_test_1args_0retvals,
		.arg_count = 1u,
		.ret_count = 0u
	},
	{
		.id = 0x0003,
		.func = (CmdFunc*)Terminal_cmd_Terminal_test_0args_1retvals,
		.arg_count = 0u,
		.ret_count = 1u
	},
	{
		.id = 0x0004,
		.func = (CmdFunc*)Terminal_cmd_Terminal_test_1args_1retvals,
		.arg_count = 1u,
		.ret_count = 1u
	},
	{
		.id = 0x0005,
		.func = (CmdFunc*)Terminal_cmd_Terminal_test_3args_3retvals,
		.arg_count = 3u,
		.ret_count = 3u
	},
	{
		.id = 0x0006,
		.func = (CmdFunc*)Terminal_cmd_Terminal_test_3args_3retvals2,
		.arg_count = 5u,
		.ret_count = 5u
	}
};








//Test functions
u8 Terminal_test_0args_0retvals(void)
{

	return 0u;
}
u8 Terminal_test_1args_0retvals(u16 a)
{

	return 0u;
}
u8 Terminal_test_0args_1retvals(u16* r)
{

	return 0u;
}
u8 Terminal_test_1args_1retvals(u16 a, u16* r)
{

	return 0u;
}
u8 Terminal_test_3args_3retvals(u8 a1, u16 a2, u32 a3, u8* r1, u16* r2, u32* r3)
{

	return 0u;
}
u8 Terminal_test_3args_3retvals2(float a1, s16 a2, u32 a3, s32 r1, u8* r2, float* r3)
{

	return 0u;
}


//test functions wrappers

TerminalStatus Terminal_cmd_Terminal_test_0args_0retvals\
						(CommandParam* args, u8 arg_count, CommandParam* retvals, u8 retval_count)
{

	return TERMINAL_OK;
}

static TerminalStatus Terminal_cmd_Terminal_test_1args_0retvals\
(CommandParam* args, u8 arg_count, CommandParam* retvals, u8 retval_count)
{

	return TERMINAL_OK;
}

static TerminalStatus Terminal_cmd_Terminal_test_0args_1retvals\
(CommandParam* args, u8 arg_count, CommandParam* retvals, u8 retval_count)
{

	return TERMINAL_OK;
}

static TerminalStatus Terminal_cmd_Terminal_test_1args_1retvals\
(CommandParam* args, u8 arg_count, CommandParam* retvals, u8 retval_count)
{

	return TERMINAL_OK;
}

static TerminalStatus Terminal_cmd_Terminal_test_3args_3retvals\
(CommandParam* args, u8 arg_count, CommandParam* retvals, u8 retval_count)
{

	return TERMINAL_OK;
}

static TerminalStatus Terminal_cmd_Terminal_test_3args_3retvals2\
(CommandParam* args, u8 arg_count, CommandParam* retvals, u8 retval_count)
{

	return TERMINAL_OK;
}
