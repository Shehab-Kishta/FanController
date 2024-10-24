/******************************************************************************
 *
 * Module: MAIN
 *
 * File Name: main.c
 *
 * Description: source file for the DC motor driver
 *
 * Author: Shehab Kishta
 *
 *******************************************************************************/
#include "avr/io.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "adc.h"

int main(void)
{
	uint8 Temp = 0;
	ADC_ConfigType ADC_Config = {Internal, FCPU_8};
	ADC_init(&ADC_Config);
	DcMotor_Init();
	LCD_init();
	LCD_moveCursor(0,3);
	LCD_displayString("FAN is ");
	LCD_moveCursor(1,3);
	LCD_displayString("TEMP = ");

	while(1)
	{
		Temp = LM35_getTemperature();
		if (Temp < 30)
		{
			DcMotor_Rotate(STOP,0);
			LCD_moveCursor(0,10);
			LCD_displayString("OFF");
			LCD_moveCursor(1,10);
			LCD_intgerToString(Temp);
		}
		else if (Temp >= 30 && Temp < 60)
		{
			DcMotor_Rotate(CW,25);
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(Temp);
		}
		else if (Temp >= 60 && Temp < 90)
		{
			DcMotor_Rotate(CW,50);
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(Temp);
		}
		else if (Temp >= 90 && Temp < 120)
		{
			DcMotor_Rotate(CW,75);
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			if (Temp >= 100)
			{
				LCD_intgerToString(Temp);
			}
			else
			{
				LCD_intgerToString(Temp);
				LCD_displayCharacter(' ');
			}
		}
		else if (Temp >= 120)
		{
			DcMotor_Rotate(CW,100);
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(Temp);
		}
	}
}
