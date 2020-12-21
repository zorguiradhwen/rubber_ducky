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

#define TIMESTAMP_TIMER TIM6
#define LOG_UART USART1
#define Uart_send(handler, buffer, len) HAL_UART_Transmit(handler, buffer, len, 0xFF)

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

void SystemClock_Config(void);

#define Hal_Delay(d) HAL_Delay(d)

Bool Hal_init();



#endif /* HAL_H_ */
