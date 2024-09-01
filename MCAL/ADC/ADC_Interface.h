/*
 * ADC_interface.h
 *
 *  Created on: Aug 4, 2024
 *      Author: sohas
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_



void ADC_init();

u16 ADC_ReadDigital(u8 channel);

u8 VOLT_READ(u8 channel);


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
