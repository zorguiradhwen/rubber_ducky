/*
 * timestamp.c
 *
 *  Created on: Dec 18, 2020
 *      Author: Radhwen
 */

#include "timestamp.h"

static u64 time_raw = 0;

TimestampError Timestamp_init()
{
	TIMESTAMP_INIT_TIMER();
	TIMESTAMP_START_COUNT();
	return No_Err;
}


TimestampError Timestamp_updateTickCount()
{
	time_raw++;
	return No_Err;
}


TimestampError Timestamp_getTime(TimeFields* T)
{

	T->msecs = (time_raw %     1000)          ;
	T->secs  = (time_raw %    60000) /    1000;
	T->mins  = (time_raw %  3600000) /   60000;
	T->hrs   = (time_raw % 86400000) / 3600000;
	T->days  = (time_raw / 86400000)          ;

	return No_Err;
}

TimestampError Timestamp_Time2String(TimeFields* T, char* timeStr)
{
	sprintf(timeStr, "%03hud %02hu:%02hu:%02hu.%03hu\n\r", T->days, T->hrs, T->mins, T->secs, T->msecs);
	TIMESTAMP_LOG("%s\n\r", timeStr);
	return No_Err;
}

TimestampError Timestamp_getTimespan(TimeFields* after, TimeFields* before, TimeFields* timespan)
{
	u64 tmp = 0u;
	tmp = ((after->days  * 86400000) + \
		   (after->hrs   *  3600000) + \
		   (after->mins  *   600000) + \
		   (after->secs  *     1000) + \
		   (after->msecs 		  )) - \
		  ((before->days * 86400000) + \
		   (before->hrs  *  3600000) + \
		   (before->mins *   600000) + \
		   (before->secs *     1000) + \
		   (before->msecs 		  ));

	timespan->msecs = (tmp %     1000)          ;
	timespan->secs  = (tmp %    60000) /    1000;
	timespan->mins  = (tmp %  3600000) /   60000;
	timespan->hrs   = (tmp % 86400000) / 3600000;
	timespan->days  = (tmp / 86400000)          ;

	return No_Err;


}


TimestampError Timestamp_ConvertToUnit(TimeFields* T, TimeUnit unit, u64 result);
