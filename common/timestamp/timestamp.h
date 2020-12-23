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
	InvalidTime_Err,
	RtcSet,
	RtcNotSet
}TimestampError;



typedef struct TimeFields_s
{
	u16 msecs, secs, mins, hrs, days;
}TimeFields;



typedef enum WeekDay_s
{
	Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
}WeekDay;

typedef enum Month_s
{
	January = 1u, February, March, April, Mai, June, July, August, September, October = 0x10, November, December
}Month;

typedef struct DateFields_s
{
	WeekDay wday;
	u8 day;
	Month month;
	u16 year;
}DateFields;


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


TimestampError Timestamp_rtcSetTime(TimeFields *T);
TimestampError Timestamp_rtcGetTime(TimeFields *T);
TimestampError Timestamp_rtcSetDate(DateFields *T);
TimestampError Timestamp_rtcGetDate(DateFields *T);
TimestampError Timestamp_isRtcSet();
TimestampError Timestamp_Date2String(DateFields* D, char* dateStr);

TimestampError Timestamp_RTCTime2String(TimeFields* T, char* timeStr);





#endif /* TIMESTAMP_TIMESTAMP_H_ */
