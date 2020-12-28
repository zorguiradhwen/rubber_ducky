/*
 * HAL.h
 *
 *  Created on: Dec 18, 2020
 *      Author: Radhwen
 */

#ifndef HAL_H_
#define HAL_H_

#include "main.h"
#include "rtc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include <stdio.h>
#include "Hal_types.h"
#include "timestamp.h"

#define UART1_HANDLER huart1
#define UART_HANDLER_TYPE UART_HandleTypeDef
#define Uart_send(handler, buffer, len) HAL_UART_Transmit(handler, buffer, len, 0xFF)



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

void SystemClock_Config(void);

#define Hal_Delay(d) HAL_Delay(d)

Bool Hal_init();



#endif /* HAL_H_ */
