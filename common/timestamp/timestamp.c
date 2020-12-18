/*
 * timestamp.c
 *
 *  Created on: Dec 18, 2020
 *      Author: Radhwen
 */

#include "timestamp.h"

u64 time_raw = 0;

TimestampError Timestamp_init();
TimestampError Timestamp_start();

TimestampError Timestamp_updateTimeCount()
{
	time_raw++;
	if(time_raw % 1000 == 0)
	{
		printf("%ld seconds elapsed! \n\r", (time_raw/1000));
	}
	return No_Err;
}


TimestampError Timestamp_getClock(Clock* clock);
TimestampError Timestamp_getDate(Date* date);
TimestampError Timestamp_getTime(Time* time);

TimestampError Timestamp_Clock2String(Clock* clock, char* clockStr);
TimestampError Timestamp_Date2String(Date* date, char* dateStr);
TimestampError Timestamp_Time2String(Time* time, char* timeStr);

TimestampError Timestamp_getTimespan(Time* t1, Time* t2, u64* timespan);
