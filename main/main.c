 /*
 * main.c
 *
 *  Created on: Dec 18, 2020
 *      Author: Radhwen
 */


#include "Hal.h"

#include "timestamp.h"

#include "logger.h"
#include "MY_FLASH.h"

u8 testWrite1[6] = "BYE!!";
u8 testWrite[6] = "Hello";

u8 testRead[6] = {0};

int main(void)
{
	Hal_init();
	Hal_Delay(1500);
	LOG_WARN("This is a warning !!!")
	LOG_ERROR("This is an ERROR")
	u8 i = 0;
	MY_FLASH_SetSectorAddrs();


	MY_FLASH_ReadN(0, testRead, 6, DATA_TYPE_8);
	LOG_INFO("Read 6 bytes from index : 0x0")
	HAL_Delay(500);

	MY_FLASH_ReadN(8, testRead, 6, DATA_TYPE_8);
	LOG_INFO("Read 6 bytes from index : 0x8")
	HAL_Delay(500);

	MY_FLASH_WriteN(0, testWrite, 6, DATA_TYPE_8);
	LOG_INFO("Write 6 bytes to index : 0x0")
	HAL_Delay(500);

	MY_FLASH_WriteN(8, testWrite1, 6, DATA_TYPE_8);
	LOG_INFO("Write 6 bytes to index : 0x8")
	HAL_Delay(500);

	MY_FLASH_ReadN(0, testRead, 6, DATA_TYPE_8);
	LOG_INFO("Read 6 bytes from index : 0x0")
	HAL_Delay(500);

	MY_FLASH_ReadN(8, testRead, 6, DATA_TYPE_8);
	LOG_INFO("Read 6 bytes from index : 0x8")
	HAL_Delay(500);








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
