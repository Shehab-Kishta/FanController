 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */

void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	/* Inserting the REF Voltage */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr -> ref_volt) << 6);

	/* Enable ADC */
	SET_BIT(ADCSRA,ADEN);

	/* Select ADC Prescaler Division Factor 8 */
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr -> prescaler);
}
/*
 * Description :
 * Read data from the channel
 */
uint16 ADC_readChannel(ADC_PIN_selection ch_num)
{
	ADMUX = (ADMUX & 0xE0) | ch_num;

	/* Start Conversion */
	SET_BIT(ADCSRA,ADSC);

	/* Wait until it Reads From the Selected PIN */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	/* Clear Flag */
	SET_BIT(ADCSRA,ADIF);

	return ADC;
}
