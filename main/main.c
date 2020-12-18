/*
 * main.c
 *
 *  Created on: Dec 18, 2020
 *      Author: Radhwen
 */


#include "Hal.h"

int main(void)
{
	Hal_init();

	while (True)
	{
		printf("Test Main\n\r");
		HAL_Delay(500);
	}

}
