/*
 * timestamp.c
 *
 *  Created on: Dec 18, 2020
 *      Author: Radhwen
 */

#include "timestamp.h"
#include <string.h>

static u64 time_raw = 0;
static Time startTime = {{0,0,0,0},{1,20,12,2020}};
//static Time runTime = {{0,0,0,0},{0,0,0,0}};

TimestampError Timestamp_init()
{
	printf(__TIME__ "\n\r");
	sscanf (__TIME__, "%hu%*c%hu%*c%hu", &startTime.clock.hrs, &startTime.clock.mins, &startTime.clock.secs);
	startTime.clock.msecs = 0;
	printf(__DATE__ "\n\r");
	sscanf(__DATE__, "%*c%*c%*c%*c%hu%*c%hu", &startTime.date.day, &startTime.date.year);
	char _month[4] = "";
	strncpy(_month, __DATE__, 3);
	if(!strncmp("Jan", _month, 3))
		startTime.date.month = January;
	else if(!strcmp("Feb", _month))
			startTime.date.month = February;
	else if(!strcmp("Mar", _month))
			startTime.date.month = March;
	else if(!strcmp("Apr", _month))
			startTime.date.month = April;
	else if(!strcmp("Mai", _month))
			startTime.date.month = Mai;
	else if(!strcmp("Jun", _month))
			startTime.date.month = June;
	else if(!strcmp("Jul", _month))
			startTime.date.month = July;
	else if(!strcmp("Aug", _month))
			startTime.date.month = August;
	else if(!strcmp("Sep", _month))
			startTime.date.month = September;
	else if(!strcmp("Oct", _month))
			startTime.date.month = October;
	else if(!strcmp("Nov", _month))
			startTime.date.month = November;
	else if(!strcmp("Dec", _month))
			startTime.date.month = December;
	else {}


	return No_Err;
}

TimestampError Timestamp_start();

TimestampError Timestamp_updateTickCount()
{
	time_raw++;
	return No_Err;
}


TimestampError Timestamp_getClock(TimeRef tref, Clock* clock)
{
	switch (tref)
	{
		case T_Absolute:
		{
			u64 tmp = time_raw + startTime.clock.msecs + startTime.clock.secs * 1000\
					+ startTime.clock.mins * 60000 + startTime.clock.hrs * 3600000;
			clock->msecs = (tmp %    1000)        ;
			clock->secs  = (tmp %   60000) / 1000 ;
			clock->mins  = (tmp % 3600000) / 60000;
			clock->hrs   = (tmp / 3600000)        ;

		}break;
		case T_Relative:
		{
			clock->msecs = (time_raw %    1000)        ;
			clock->secs  = (time_raw %   60000) / 1000 ;
			clock->mins  = (time_raw % 3600000) / 60000;
			clock->hrs   = (time_raw / 3600000)        ;

		}break;
		default:
		{

		}break;
	}
	return No_Err;
}
TimestampError Timestamp_getDate(Date* date);
TimestampError Timestamp_getTime(TimeRef tref, Time* time);

TimestampError Timestamp_Clock2String(Clock* clock, char* clockStr)
{
	sprintf(clockStr, "%02hu:%02hu:%02hu.%03hu\n\r", clock->hrs, clock->mins, clock->secs, clock->msecs);
	printf("%s\n\r", clockStr);
	return No_Err;
}
TimestampError Timestamp_Date2String(Date* date, char* dateStr);
TimestampError Timestamp_Time2String(Time* time, char* timeStr);

TimestampError Timestamp_getTimespan(Time* t1, Time* t2, u64* timespan);
