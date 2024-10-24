/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the PWM driver
 *
 * Author: Shehab Kishta
 *
 *******************************************************************************/
#include "common_macros.h"
#include "gpio.h"
#include "avr/io.h" /* To use the IO Ports Registers */
#include "pwm.h"

/*
 * Description :
 * The function responsible for trigger the Timer0 with the PWM Mode.
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	/* Set Timer Initial Value to 0 */
	TCNT0 = 0;

	/* Set Compare Value */
	OCR0  = duty_cycle;

	/* Setup the direction for OC0 as output pin */
	GPIO_setupPinDirection(PORT_ID, PIN_ID, PIN_OUTPUT);

	/* Set the Waveform Generation as FAST PWM Mode */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	/* Compare Output Mode as non-inverting mode */
	SET_BIT(TCCR0,COM01);

	/* Set the prescaler with F_CPU/8 */
	SET_BIT(TCCR0,CS01);
}
