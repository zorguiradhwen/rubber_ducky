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
#if TIMESTAMP_RTC_SUPPORT
	TIMESTAMP_RTC_INIT();
	DateFields D = {0};
	TimeFields T = {0};
	Timestamp_rtcSetDate(&D);
	Timestamp_rtcSetTime(&T);

#endif
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
	sprintf(timeStr, "%03hud %02hu:%02hu:%02hu.%03hu", T->days, T->hrs, T->mins, T->secs, T->msecs);
	TIMESTAMP_LOG("%s\n\r", timeStr);
	return No_Err;
}

TimestampError Timestamp_Date2String(DateFields* D, char* dateStr)
{
	sprintf(dateStr, "%02u/%02u/%04u", D->day, D->month, D->year);
	TIMESTAMP_LOG("%s\n\r", dateStr);
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

#if TIMESTAMP_RTC_SUPPORT
TimeFields RTCTime = {0};
DateFields RTCDate = {0};

TimestampError Timestamp_rtcSetTime(TimeFields *T)
{
	TIMESTAMP_LOG(__TIME__ "\n\r");
	sscanf (__TIME__, "%hu%*c%hu%*c%hu", &RTCTime.hrs, &RTCTime.mins, &RTCTime.secs);
	RTCTime.msecs = 0;


	RTC_TimeTypeDef sTime = {0};
	memcpy(T, &RTCTime, sizeof(TimeFields));

	sTime.Hours = T->hrs;
	sTime.Minutes = T-> mins;
	sTime.Seconds = T->secs;
	if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
	  {
	    return RtcNotSet;
	  }
	else
	{
		return RtcSet;
	}


}
TimestampError Timestamp_rtcGetTime(TimeFields *T)
{
	RTC_TimeTypeDef sTime = {0};
	HAL_RTC_GetTime(&TIMESTAMP_RTC_HANDLER, &sTime, RTC_FORMAT_BIN);
	T->hrs = sTime.Hours;
	T->mins = sTime.Minutes;
	T->secs = sTime.Seconds;
	memcpy(&RTCTime, T, sizeof(TimeFields));
	return No_Err;

}
TimestampError Timestamp_rtcSetDate(DateFields *D)
{
	TIMESTAMP_LOG(__DATE__ "\n\r");
	sscanf(__DATE__, "%*c%*c%*c%*c%u%*c%u", &D->day, &D->year);
	char _month[4] = "";
	strncpy(_month, __DATE__, 3);
	if(!strncmp("Jan", _month, 3))
		D->month = January;
	else if(!strcmp("Feb", _month))
		D->month = February;
	else if(!strcmp("Mar", _month))
		D->month = March;
	else if(!strcmp("Apr", _month))
		D->month = April;
	else if(!strcmp("Mai", _month))
		D->month = Mai;
	else if(!strcmp("Jun", _month))
		D->month = June;
	else if(!strcmp("Jul", _month))
		D->month = July;
	else if(!strcmp("Aug", _month))
		D->month = August;
	else if(!strcmp("Sep", _month))
		D->month = September;
	else if(!strcmp("Oct", _month))
		D->month = October;
	else if(!strcmp("Nov", _month))
		D->month = November;
	else if(!strcmp("Dec", _month))
		D->month = December;
	else {}
	RTC_DateTypeDef sDate = {0};
	memcpy(&RTCDate, D, sizeof(DateFields));
	sDate.Month = D->month;
	sDate.Year = D->year % 100;
	sDate.Date = D->day;
	if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
	{
		return RtcNotSet;
	}
	else
	{
		return RtcSet;
	}



}
TimestampError Timestamp_rtcGetDate(DateFields *D)
{
	RTC_DateTypeDef sDate = {0};
	HAL_RTC_GetDate(&TIMESTAMP_RTC_HANDLER, &sDate, RTC_FORMAT_BIN);
	D->month = sDate.Month;
	D->year = sDate.Year + 2000;
	D->day = sDate.Date;
	memcpy(&RTCDate, D, sizeof(DateFields));
	return No_Err;
}

TimestampError Timestamp_RTCTime2String(TimeFields* T, char* timeStr)
{
	sprintf(timeStr, "%02hu:%02hu:%02hu", T->hrs, T->mins, T->secs);
	TIMESTAMP_LOG("%s\n\r", timeStr);
	return No_Err;
}

#endif
