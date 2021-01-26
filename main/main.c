 /*
 * main.c
 *
 *  Created on: Dec 18, 2020
 *      Author: Radhwen
 */


#include "Hal.h"

#include "timestamp.h"

#include "logger.h"

int main(void)
{
	Hal_init();
	Hal_Delay(1500);
	LOG_WARN("This is a warning !!!")
	LOG_ERROR("This is an ERROR")
	u8 i = 0;

	while (True)
	{
		LOG_LOG(LEVEL_WARNING, "test %03d",i)
		LOG_INFO("This is an INFO n: %03d", i)
		LOG_TRACE("This is an TRACE n: %03d", i)
		LOG_ERROR("This is an ERROR n: %03d", i)
		LOG_FATAL("This is an FATAL n: %03d", i)
		LOG_WARN("This is an WARNING n: %03d", i)
		i++;
		HAL_Delay(500);



	}


}
