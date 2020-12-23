/*
 * timestamp_conf.h
 *
 *  Created on: Dec 21, 2020
 *      Author: Radhwen
 */

#ifndef TIMESTAMP_TIMESTAMP_CONF_H_
#define TIMESTAMP_TIMESTAMP_CONF_H_

#include "Hal.h"

#define TIMESTAMP_MODULE

#ifdef  TIMESTAMP_MODULE

#define TIMESTAMP_TIMER TIM6
#define TIMESTAMP_INIT_TIMER()  MX_TIM6_Init()
#define TIMESTAMP_START_COUNT() HAL_TIM_Base_Start_IT(&htim6)

//#define TIMESTAMP_RESOLUTION (1u)
#define TIMESTAMP_DEBUG True

#if TIMESTAMP_DEBUG
#define TIMESTAMP_LOG(...) printf(__VA_ARGS__)
#else
#define TIMESTAMP_LOG(...)
#endif


#define TIMESTAMP_RTC_SUPPORT True

#if TIMESTAMP_RTC_SUPPORT
#define TIMESTAMP_RTC_HANDLER hrtc
#define TIMESTAMP_RTC_STATUS_ADDRESS 0x08000000
#define TIMESTAMP_RTC_INIT() MX_RTC_Init()

#endif
#endif

#endif /* TIMESTAMP_TIMESTAMP_CONF_H_ */
