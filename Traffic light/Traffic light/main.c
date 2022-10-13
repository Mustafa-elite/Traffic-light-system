/*
 * Traffic light.c
 *
 * Created: 10/6/2022 2:31:13 AM
 * Author : Dell
 */ 

#include "Application/Application.h"

int main(void)
{
	app_init();
	/* Replace with your application code */
	while (1)
	{
		appStart();
		
		
		/* TESTING THE DRIVERS */
		/*u8 buttonStatus=0;
		u8 bufferButtonStatus=0;
		BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&bufferButtonStatus);
		buttonStatus=bufferButtonStatus;
		while(bufferButtonStatus==HIGH)
		{
			BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&bufferButtonStatus);
		}
		if(buttonStatus==HIGH)
		{
			LED_on(CARS_REDLED_PORT,CARS_REDLED_PIN);
			Delay_ms(1000);
			LED_off(CARS_REDLED_PORT,CARS_REDLED_PIN);
		}*/

	}
}
