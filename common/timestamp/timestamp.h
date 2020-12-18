/*
 * timestamp.h
 *
 *  Created on: Dec 18, 2020
 *      Author: Radhwen
 */

#ifndef TIMESTAMP_TIMESTAMP_H_
#define TIMESTAMP_TIMESTAMP_H_

#include "Hal.h"

typedef struct ClockFields_s
{
	u16 msecs;
	u8  secs, mins, hrs;
}Clock;

typedef enum WeekDay_s
{
	Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
}WeekDay;

typedef enum Month_s
{
	January = 1u, February, March, April, Mai, Juin, July, August, September, October, November, December
}Month;

typedef struct DateFields_s
{
	WeekDay weekday;
	u8 day;
	Month month;
	u16 year;
}Date;

typedef struct Time_s
{
	Clock clock;
	Date date;
}Time;


typedef enum TimestampError_s
{
	No_Err,
	Conversion_Err,
	Read_Err,
	Write_Err,
	InvalidTime_Err
}TimestampError;


TimestampError Timestamp_init();
TimestampError Timestamp_start();
TimestampError Timestamp_updateTimeCount();
TimestampError Timestamp_getClock(Clock* clock);
TimestampError Timestamp_getDate(Date* date);
TimestampError Timestamp_getTime(Time* time);

TimestampError Timestamp_Clock2String(Clock* clock, char* clockStr);
TimestampError Timestamp_Date2String(Date* date, char* dateStr);
TimestampError Timestamp_Time2String(Time* time, char* timeStr);

TimestampError Timestamp_getTimespan(Time* t1, Time* t2, u64* timespan);
TimestampError Timestamp_timespan2String(u64 timespan, char* timespanStr);






#endif /* TIMESTAMP_TIMESTAMP_H_ */
