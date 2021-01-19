/*
 * Terminal_conf.h
 *
 *  Created on: Jan 14, 2021
 *      Author: Radhwen
 */

#ifndef TERMINAL_CONF_H_
#define TERMINAL_CONF_H_

#include "Hal.h"


#define ENABLE_TERMINAL True

#define TERMINAL_HANDLER UART1_HANDLER

#define TERMINAL_SHARED_COM True

#define TERMINAL_CHANNEL_ID 'T'

#define MAX_ARG_SIZE 100
#define MAX_ARG_COUNT 5
#define ENABLE_AUTOFILL_ARGS False



#endif /* TERMINAL_CONF_H_ */
