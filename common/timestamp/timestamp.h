/*
 * timestamp.h
 *
 *  Created on: Dec 18, 2020
 *      Author: Radhwen
 */

#ifndef TIMESTAMP_TIMESTAMP_H_
#define TIMESTAMP_TIMESTAMP_H_

#include "timestamp_conf.h"


typedef enum TimestampError_s
{
	No_Err,
	Conversion_Err,
	Read_Err,
	Write_Err,
	InvalidTime_Err
}TimestampError;



typedef struct TimeFields_s
{
	u16 msecs, secs, mins, hrs, days;
}TimeFields;

/*

typedef enum WeekDay_s
{
	Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
}WeekDay;

typedef enum Month_s
{
	January = 1u, February, March, April, Mai, June, July, August, September, October, November, December
}Month;

*/

typedef enum TimeUnit_e
{
	Milliseconds, Seconds, Minutes, Hours, days
}TimeUnit;

TimestampError Timestamp_ConvertToUnit(TimeFields* T, TimeUnit unit, u64 result);
TimestampError Timestamp_getTime(TimeFields* T);
TimestampError Timestamp_Time2String(TimeFields* T, char* timeStr);
TimestampError Timestamp_getTimespan(TimeFields* after, TimeFields* before, TimeFields* timespan);
TimestampError Timestamp_init();
TimestampError Timestamp_updateTickCount();



#endif /* TIMESTAMP_TIMESTAMP_H_ */
