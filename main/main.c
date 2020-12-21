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
	TimeFields clk;
	char clockStr[13] = "";
	Timestamp_getTime(&clk);
	TimeFields t_after = {
			150, 35, 3, 5, 2
	};
	TimeFields t_before = {
				500, 48, 3, 5, 1
		};
	TimeFields result ;

	Timestamp_getTimespan(&t_after, &t_before, &result);
	while (True)
	{
		printf("Test Main\n\r");
		HAL_Delay(500);
		Timestamp_getTime(&clk);
		Timestamp_Time2String(&clk, clockStr);

	}


}
