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
	TimeFields T = {0};
	DateFields D = {0};
	Timestamp_rtcGetTime(&T);
	Timestamp_rtcGetDate(&D);
	char dateStr[] = "00/00/0000";
	char timeStr[] = "000d 00:00:00.000";
	Timestamp_Time2String(&T, timeStr);
	Timestamp_Date2String(&D, dateStr);
	while (True)
	{
		printf("Test Main\n\r");
		HAL_Delay(500);
		Timestamp_rtcGetTime(&T);
		Timestamp_rtcGetDate(&D);
		Timestamp_Time2String(&T, timeStr);
		Timestamp_Date2String(&D, dateStr);


	}


}
