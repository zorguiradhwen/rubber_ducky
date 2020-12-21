/*
 * rtc.c
 *
 *  Created on: Dec 21, 2020
 *      Author: Radhwen
 */

static Time startTime = {{0,0,0,0},{1,20,12,2020}};
//static Time runTime = {{0,0,0,0},{0,0,0,0}};

TimestampError rtc_init()
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
