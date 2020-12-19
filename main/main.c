/*
 * main.c
 *
 *  Created on: Dec 18, 2020
 *      Author: Radhwen
 */


#include "Hal.h"
#include "timestamp.h"

int main(void)
{
	Hal_init();
	Hal_Delay(1500);
	Clock clk;
	char clockStr[13] = "";
	Timestamp_getClock(T_Relative, &clk);
	while (True)
	{
		printf("Test Main\n\r");
		HAL_Delay(500);
		Timestamp_getClock(T_Relative, &clk);
		Timestamp_Clock2String(&clk, clockStr);

	}


}
