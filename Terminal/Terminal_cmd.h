/*
 * Terminal_cmd.h
 *
 *  Created on: Jan 14, 2021
 *      Author: Radhwen
 */

#ifndef TERMINAL_CMD_H_
#define TERMINAL_CMD_H_

#include "Terminal.h"







//Test functions
u8 Terminal_test_0args_0retvals(void);
u8 Terminal_test_1args_0retvals(u16);
u8 Terminal_test_0args_1retvals(u16*);
u8 Terminal_test_1args_1retvals(u16, u16*);
u8 Terminal_test_3args_3retvals(u8,u16,u32, u8*,u16*, u32*);
u8 Terminal_test_3args_3retvals2(float, s16,u32, s32, u8*, float*);


//test functions wrappers

TerminalStatus Terminal_cmd_Terminal_test_0args_0retvals\
						(CommandParam* args, u8 arg_count, CommandParam* retvals, u8 retval_count);

static TerminalStatus Terminal_cmd_Terminal_test_1args_0retvals\
(CommandParam* args, u8 arg_count, CommandParam* retvals, u8 retval_count);

static TerminalStatus Terminal_cmd_Terminal_test_0args_1retvals\
(CommandParam* args, u8 arg_count, CommandParam* retvals, u8 retval_count);

static TerminalStatus Terminal_cmd_Terminal_test_1args_1retvals\
(CommandParam* args, u8 arg_count, CommandParam* retvals, u8 retval_count);

static TerminalStatus Terminal_cmd_Terminal_test_3args_3retvals\
(CommandParam* args, u8 arg_count, CommandParam* retvals, u8 retval_count);

static TerminalStatus Terminal_cmd_Terminal_test_3args_3retvals2\
(CommandParam* args, u8 arg_count, CommandParam* retvals, u8 retval_count);





#define CMD_COUNT 6

#endif /* TERMINAL_CMD_H_ */
