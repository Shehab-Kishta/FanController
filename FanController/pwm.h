 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the PWM driver
 *
 * Author: Shehab Kishta
 *
 *******************************************************************************/
#ifndef PWM_H_
#define PWM_H_
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PORT_ID			PORTB_ID
#define PIN_ID			PIN3_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * The function responsible for trigger the Timer0 with the PWM Mode.
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
