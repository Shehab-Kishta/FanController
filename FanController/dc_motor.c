/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.c
 *
 * Description: source file for the DC motor driver
 *
 * Author: Shehab Kishta
 *
 *******************************************************************************/
#include "avr/io.h" /* To use the IO Ports Registers */
#include "gpio.h"
#include "dc_motor.h"
#include "pwm.h"

/*
 * Description :
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void)
{
	/* configure connected pins as output pins */
	GPIO_setupPinDirection(POSITIVE_PORT_ID, POSITIVE_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(NEGATIVE_PORT_ID, NEGATIVE_PIN_ID, PIN_OUTPUT);

	/* Motor is stop at the beginning */
	GPIO_writePin(POSITIVE_PORT_ID, POSITIVE_PIN_ID, LOGIC_LOW);
	GPIO_writePin(NEGATIVE_PORT_ID, NEGATIVE_PIN_ID, LOGIC_LOW);
}
/*
 * Description :
 * Drive the motor with specific speed.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	uint8 speed_result;
	PORTB = (PORTB & 0xFC) | state;
	speed_result = (uint8)(((uint32)speed*255)/100);
	PWM_Timer0_Start(speed_result);
}
