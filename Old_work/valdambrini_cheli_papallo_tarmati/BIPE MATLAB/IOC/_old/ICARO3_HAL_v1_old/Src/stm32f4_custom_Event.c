#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"
#include "stm32f4_custom_Event.h"
 
 /**
  * @brief  Function that check if an I2C Event has occurred.
  * @param  hi2c: I2C Handler.
  *			EvenFlag: Flag relative to the I2C event.
  * @retval 0 (no event), 1 (event).
  */
uint8_t custom_I2C_CheckEvent(I2C_HandleTypeDef *hi2c, uint32_t EventFlag)
{
	uint32_t lastevent = 0;
	uint32_t flag1 = 0, flag2 = 0;
	uint8_t  retval = 0;

	/* Check the parameters */
	assert_param(IS_I2C_ALL_INSTANCE(hi2c->Instance));
	assert_param(CUSTOM_IS_I2C_EVENT(EventFlag));

	/* Read the I2Cx status register */
	flag1 = hi2c->Instance -> SR1;
	flag2 = hi2c->Instance -> SR2;
	flag2 = flag2 << 16;
	
	/* Get the last event value from I2C status register */
	lastevent = (flag1 | flag2) & FLAG_MASK;

	/* Check whether the last event contains the EventFlag */
	if ((lastevent & EventFlag) == EventFlag)
	{
		/* SUCCESS: last event is equal to EventFlag */
		retval = 1;
	}
	else
	{
		/* ERROR: last event is different from EventFlag */
		retval = 0;
	}
	/* Return status */
	return retval;
}
 
uint32_t custom_I2C_GetLastEvent(I2C_HandleTypeDef *hi2c)
{
	uint32_t lastevent = 0;
	uint32_t flag1 = 0, flag2 = 0;

	/* Check the parameters */
	assert_param(IS_I2C_ALL_INSTANCE(hi2c->Instance));

	/* Read the I2Cx status register */
	flag1 = hi2c->Instance -> SR1;
	flag2 = hi2c->Instance -> SR2;
	flag2 = flag2 << 16;

	/* Get the last event value from I2C status register */
	lastevent = (flag1 | flag2) & FLAG_MASK;

	/* Return status */
	return lastevent;	
}