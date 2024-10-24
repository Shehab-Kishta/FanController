/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.h
 *
 * Description: header file for the DC motor driver
 *
 * Author: Shehab Kishta
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define POSITIVE_PORT_ID			PORTB_ID
#define NEGATIVE_PORT_ID			PORTB_ID
#define POSITIVE_PIN_ID				PIN0_ID
#define NEGATIVE_PIN_ID				PIN1_ID
#define POSITIVE_PORT				PORTB
#define NEGATIVE_PORT				PORTB

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	STOP, ACW, CW
}DcMotor_State;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);
/*
 * Description :
 * Drive the motor with specific speed.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
