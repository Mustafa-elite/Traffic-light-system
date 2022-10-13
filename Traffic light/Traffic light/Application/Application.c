/*
 * Application.c
 *
 * Created: 9/30/2022 1:18:04 AM
 *  Author: Dell
 */ 

#include "Application.h"


u8 buttonStatus;
u8 bufferButtonStatus;

void app_init()
{
	LED_init(CARS_REDLED_PORT,CARS_REDLED_PIN);
	LED_init(CARS_YELLOWLED_PORT,CARS_YELLOWLED_PIN);
	LED_init(CARS_GREENLED_PORT,CARS_GREENLED_PIN);
	BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
	Delay_init();
}

void yellowsBlink()
{
	u32 counter=0;
	LED_on(PED_YELLOWLED_PORT,PED_YELLOWLED_PIN);
	LED_on(CARS_YELLOWLED_PORT,CARS_YELLOWLED_PIN);
	for(counter=0;counter<50;counter++)
	{
		Delay_ms(100);
		if(counter%5==0 &&counter!=0)
		{
			LED_toggle(CARS_YELLOWLED_PORT,CARS_YELLOWLED_PIN);
			LED_toggle(PED_YELLOWLED_PORT,PED_YELLOWLED_PIN);
		}
	}
	LED_off(CARS_YELLOWLED_PORT,CARS_YELLOWLED_PIN);
	LED_off(PED_YELLOWLED_PORT,PED_YELLOWLED_PIN);
}

void carsYelllowGreenCase()
{
	LED_on(PED_REDLED_PORT,PED_REDLED_PIN);
	yellowsBlink();
	LED_off(PED_REDLED_PORT,PED_REDLED_PIN);
	LED_on(PED_GREENLED_PORT,PED_GREENLED_PIN);
	LED_off(CARS_GREENLED_PORT,CARS_GREENLED_PIN);
	LED_on(CARS_REDLED_PORT,CARS_REDLED_PIN);
	Delay_ms(5000);
}

void pedToNormalMode()
{
	LED_off(CARS_REDLED_PORT,CARS_REDLED_PIN);
	yellowsBlink();
	LED_off(PED_GREENLED_PORT,PED_GREENLED_PIN);
	LED_on(PED_REDLED_PORT,PED_REDLED_PIN);
}

EN_APPFLOW_t greenForCar()
{
	//for(500 loop)
	//{
	//   cars green led on
	//  delay10ms
	//  check if button pressed
	//  if(button pressed)
	//{
	//   ped red on
	//   both yellow blink 5 secs
	//   car red and ped green 5 secs
	//    cars red off and both yellow blink for 5 secs while green ped is still on,then green ped off and red on
	//}
	//}
	//green off
	/////////////////////////
	u32 counter=0;
	EN_APPFLOW_t appFLow=NORMAL_SEQUENCE;
	LED_on(CARS_GREENLED_PORT,CARS_GREENLED_PIN);
	for(counter=0;counter<500;counter++)
	{
		if(counter==150)
		{
			LED_off(PED_REDLED_PORT,PED_REDLED_PIN);
		}
		Delay_ms(10);
		BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&bufferButtonStatus);
		buttonStatus=bufferButtonStatus;
		while(bufferButtonStatus==HIGH)
		{
			BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&bufferButtonStatus);
		}
		if(buttonStatus==HIGH)
		{
			carsYelllowGreenCase();
			pedToNormalMode();
			appFLow=PED_SEQUENCE;
			break;
		}
	}
	LED_off(CARS_GREENLED_PORT,CARS_GREENLED_PIN);
	return appFLow;
}
EN_APPFLOW_t yellowForCar()
{
	//for(500 loop)
	//{
	//   cars yellow led on
	//  delay10ms
	//  toggle every 1000ms
	//  check if button pressed
	//  if(button pressed)
	//{
	//   ped red on
	//  both yellow blink 5 secs
	//  car red and ped green 5 secs
	//cars red off and both yellow blink for 5 secs while green ped is still on,then green ped off and red on
	//}
	//}
	// yellow off
	/////////////////////////////
	u32 counter=0;
	EN_APPFLOW_t appFLow=NORMAL_SEQUENCE;
	LED_on(CARS_YELLOWLED_PORT,CARS_YELLOWLED_PIN);
	for(counter=0;counter<500;counter++)
	{
		Delay_ms(10);
		if(counter%50==0 &&counter!=0)
		{
			LED_toggle(CARS_YELLOWLED_PORT,CARS_YELLOWLED_PIN);
		}
		BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&bufferButtonStatus);
		buttonStatus=bufferButtonStatus;
		while(bufferButtonStatus==HIGH)
		{
			BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&bufferButtonStatus);
		}
		if(buttonStatus==HIGH)
		{
			carsYelllowGreenCase();
			pedToNormalMode();
			appFLow=PED_SEQUENCE;
			break;
		}
	}
	LED_off(CARS_YELLOWLED_PORT,CARS_YELLOWLED_PIN);
	return appFLow;
}
EN_APPFLOW_t redForCar()
{
	//for(500 loop)
	//{
	// red led on
	//  delay 10ms
	//  check if button is pressed
	//  if(button pressed)
	//  {
	// car red and green ped for 5 secs
	//cars red off and both yellow blink for 5 secs while green ped is still on,then green ped off and red on
	//  }
	//}
	//red off
	//////////////////
	u32 counter=0;
	EN_APPFLOW_t appFLow=NORMAL_SEQUENCE;
	LED_on(CARS_REDLED_PORT,CARS_REDLED_PIN);
	for(counter=0;counter<500;counter++)
	{
		Delay_ms(10);
		BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&bufferButtonStatus);
		buttonStatus=bufferButtonStatus;
		while(bufferButtonStatus==HIGH)
		{
			BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&bufferButtonStatus);
		}
		if(buttonStatus==HIGH)
		{
			LED_on(PED_GREENLED_PORT,PED_GREENLED_PIN);
			Delay_ms(5000);
			pedToNormalMode();
			appFLow=PED_SEQUENCE;
			break;
		}
	}
	LED_off(CARS_REDLED_PORT,CARS_REDLED_PIN);
	return appFLow;
}
u8 appStart()
{
	EN_APPFLOW_t appFlow=NORMAL_SEQUENCE;
	appFlow=greenForCar();
	if(appFlow !=NORMAL_SEQUENCE)
	{
		return 0;
	}
	else
	{
		appFlow=yellowForCar();
		if(appFlow !=NORMAL_SEQUENCE)
		{
			return 0;
		}
		else
		{
			appFlow=redForCar();
			if(appFlow !=NORMAL_SEQUENCE)
			{
				return 0;
			}
			else
			{
				appFlow=yellowForCar();
			}
		}
	}
	return 0;
}




























// void appStart()
// {
// 	BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&buttonStatus);
// 	bufferButtonStatus=buttonStatus;
// 	while(buttonStatus==HIGH)
// 	{
// 		BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&buttonStatus);
// 	}
// 	if(HIGH==bufferButtonStatus)
// 	{
// 		if(counter==5)
// 		{
// 			counter=0;
// 		}
// 		else
// 		{
// 			counter++;
// 		}
// 	}
// 	else
// 	{
// 	}
// 	if(counter==0)
// 	{
// 		LedsOFF();
// 	}
// 	else if(counter==1 ||counter==5)
// 	{
// 		if(counter==1)
// 		{
// 			LED_on(CARS_REDLED_PORT,CARS_REDLED_PIN);
// 		}
// 		else
// 		{
// 			LED_off(CARS_YELLOWLED_PORT,CARS_YELLOWLED_PIN);
// 		}
// 	}
// 	else if(counter==2 ||counter==4)
// 	{
// 		if(counter==2)
// 		{
// 			LED_on(CARS_YELLOWLED_PORT,CARS_YELLOWLED_PIN);
// 		}
// 		else
// 		{
// 			LED_off(CARS_GREENLED_PORT,CARS_GREENLED_PIN);
// 		}
// 	}
// 	else
// 	{
// 		LED_on(CARS_GREENLED_PORT,CARS_GREENLED_PIN);
// 	}
// }