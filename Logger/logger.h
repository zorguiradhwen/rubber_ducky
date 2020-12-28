/*
 * logger.h
 *
 *  Created on: 27 déc. 2020
 *      Author: radhwen.zorgui
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "Hal.h"
#include "printf_override.h"

#include"logger_conf.h"

#define LOGGER_MODULE

typedef enum LogLevel_e
{
	LEVEL_FATAL, LEVEL_ERROR, LEVEL_WARNING, LEVEL_INFO, LEVEL_TRACE
}LogLevel;

#if LOG_SHARED_COM
#define LOG_COM_ID 'L'
#define LOG_COM_ID_STR "LOG\t"
#else
#define LOG_COM_ID
#define LOG_COM_ID_STR
#endif


#if ENABLE_LOG
#define LOG_LOG(level, fmt, ...) if(level<= LOG_LEVEL)\
{\
	TimeFields T = {0};\
	TimeFields Trtc = {0};\
	DateFields D = {0};\
	char dateStr[] = "00/00/0000";\
	char timeStr[] = "000d 00:00:00.000";\
	char rtctimeStr[] = "00:00:00";\
	Timestamp_rtcGetTime(&Trtc);\
	Timestamp_rtcGetDate(&D);\
	Timestamp_getTime(&T);\
	Timestamp_Date2String(&D, dateStr);\
	Timestamp_RTCTime2String(&Trtc, rtctimeStr);\
	Timestamp_Time2String(&T, timeStr);\
	printf_changeCom(COM_UART, &LOG_HANDLER);\
	switch (level)\
	{\
		case LEVEL_FATAL: {printf(LOG_COM_ID_STR "%s %s\t%s\tFATAL\t%s\t%s\tL:%d\t" fmt "\n\r", dateStr, rtctimeStr, timeStr, __FILE__, __func__, __LINE__, ## __VA_ARGS__);\
		}break;\
		case LEVEL_ERROR: {printf(LOG_COM_ID_STR "%s %s\t%s\tERROR\t%s\t%s\tL:%d\t" fmt "\n\r", dateStr, rtctimeStr, timeStr, __FILE__, __func__, __LINE__, ## __VA_ARGS__);\
		}break;\
		case LEVEL_WARNING: {printf(LOG_COM_ID_STR "%s %s\t%s\tWARN \t%s\t%s\tL:%d\t" fmt "\n\r", dateStr, rtctimeStr, timeStr, __FILE__, __func__, __LINE__, ## __VA_ARGS__);\
		}break;\
		case LEVEL_INFO: {printf(LOG_COM_ID_STR "%s %s\t%s\tINFO \t%s\t%s\tL:%d\t" fmt "\n\r", dateStr, rtctimeStr, timeStr, __FILE__, __func__, __LINE__, ## __VA_ARGS__);\
		}break;\
		case LEVEL_TRACE: {printf(LOG_COM_ID_STR "%s %s\t%s\tTRACE\t%s\t%s\tL:%d\t" fmt "\n\r", dateStr, rtctimeStr, timeStr, __FILE__, __func__, __LINE__, ## __VA_ARGS__);\
		}break;\
		default:{} break;\
	}\
}

#define LOG_FATAL(fmt, ...) if(LEVEL_FATAL <= LOG_LEVEL)\
	{\
		TimeFields T = {0};\
		TimeFields Trtc = {0};\
		DateFields D = {0};\
		char dateStr[] = "00/00/0000";\
		char timeStr[] = "000d 00:00:00.000";\
		char rtctimeStr[] = "00:00:00";\
		Timestamp_rtcGetTime(&Trtc);\
		Timestamp_rtcGetDate(&D);\
		Timestamp_getTime(&T);\
		Timestamp_Date2String(&D, dateStr);\
		Timestamp_RTCTime2String(&Trtc, rtctimeStr);\
		Timestamp_Time2String(&T, timeStr);\
		printf_changeCom(COM_UART, &LOG_HANDLER);\
		printf(LOG_COM_ID_STR "%s %s\t%s\tFATAL\t%s\t%s\tL:%d\t" fmt "\n\r", dateStr, rtctimeStr, timeStr, __FILE__, __func__, __LINE__, ## __VA_ARGS__);\
	}

#define LOG_ERROR(fmt, ...) if(LEVEL_ERROR <= LOG_LEVEL)\
		{\
			TimeFields T = {0};\
			TimeFields Trtc = {0};\
			DateFields D = {0};\
			char dateStr[] = "00/00/0000";\
			char timeStr[] = "000d 00:00:00.000";\
			char rtctimeStr[] = "00:00:00";\
			Timestamp_rtcGetTime(&Trtc);\
			Timestamp_rtcGetDate(&D);\
			Timestamp_getTime(&T);\
			Timestamp_Date2String(&D, dateStr);\
			Timestamp_RTCTime2String(&Trtc, rtctimeStr);\
			Timestamp_Time2String(&T, timeStr);\
			printf_changeCom(COM_UART, &LOG_HANDLER); \
			printf(LOG_COM_ID_STR "%s %s\t%s\tERROR\t%s\t%s\tL:%d\t" fmt "\n\r", dateStr, rtctimeStr, timeStr, __FILE__, __func__, __LINE__, ## __VA_ARGS__);\
		}

#define LOG_WARN(fmt, ...) if(LEVEL_WARNING <= LOG_LEVEL)\
		{\
			TimeFields T = {0};\
			TimeFields Trtc = {0};\
			DateFields D = {0};\
			char dateStr[] = "00/00/0000";\
			char timeStr[] = "000d 00:00:00.000";\
			char rtctimeStr[] = "00:00:00";\
			Timestamp_rtcGetTime(&Trtc);\
			Timestamp_rtcGetDate(&D);\
			Timestamp_getTime(&T);\
			Timestamp_Date2String(&D, dateStr);\
			Timestamp_RTCTime2String(&Trtc, rtctimeStr);\
			Timestamp_Time2String(&T, timeStr);\
			printf_changeCom(COM_UART, &LOG_HANDLER);\
			printf(LOG_COM_ID_STR "%s %s\t%s\tWARN \t%s\t%s\tL:%d\t" fmt "\n\r", dateStr, rtctimeStr, timeStr, __FILE__, __func__, __LINE__, ## __VA_ARGS__);\
		}

#define LOG_INFO(fmt, ...) if(LEVEL_INFO <= LOG_LEVEL)\
		{\
			TimeFields T = {0};\
			TimeFields Trtc = {0};\
			DateFields D = {0};\
			char dateStr[] = "00/00/0000";\
			char timeStr[] = "000d 00:00:00.000";\
			char rtctimeStr[] = "00:00:00";\
			Timestamp_rtcGetTime(&Trtc);\
			Timestamp_rtcGetDate(&D);\
			Timestamp_getTime(&T);\
			Timestamp_Date2String(&D, dateStr);\
			Timestamp_RTCTime2String(&Trtc, rtctimeStr);\
			Timestamp_Time2String(&T, timeStr);\
			printf_changeCom(COM_UART, &LOG_HANDLER);\
			printf(LOG_COM_ID_STR "%s %s\t%s\tINFO \t%s\t%s\tL:%d\t" fmt "\n\r", dateStr, rtctimeStr, timeStr, __FILE__, __func__, __LINE__, ## __VA_ARGS__);\
		}

#define LOG_TRACE(fmt, ...) if(LEVEL_TRACE <= LOG_LEVEL)\
		{\
			TimeFields T = {0};\
			TimeFields Trtc = {0};\
			DateFields D = {0};\
			char dateStr[] = "00/00/0000";\
			char timeStr[] = "000d 00:00:00.000";\
			char rtctimeStr[] = "00:00:00";\
			Timestamp_rtcGetTime(&Trtc);\
			Timestamp_rtcGetDate(&D);\
			Timestamp_getTime(&T);\
			Timestamp_Date2String(&D, dateStr);\
			Timestamp_RTCTime2String(&Trtc, rtctimeStr);\
			Timestamp_Time2String(&T, timeStr);\
			printf_changeCom(COM_UART, &LOG_HANDLER);\
			printf(LOG_COM_ID_STR "%s %s\t%s\tTRACE\t%s\t%s\tL:%d\t" fmt "\n\r", dateStr, rtctimeStr, timeStr, __FILE__, __func__, __LINE__, ## __VA_ARGS__);\
		}

#else
#define LOG_LOG(level, fmt, ...)
#define LOG_FATAL(fmt, ...)
#define LOG_ERROR(fmt, ...)
#define LOG_WARN (fmt, ...)
#define LOG_INFO (fmt, ...)
#define LOG_TRACE(fmt, ...)
#endif














#endif /* LOGGER_H_ */
