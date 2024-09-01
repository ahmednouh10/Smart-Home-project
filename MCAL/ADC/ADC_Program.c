/*
 * ADC_Program.c
 *
 *  Created on: Aug 4, 2024
 *      Author: sohas
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

void  ADC_init(){
	//select volt
#if (VOLT_SELECT== AREF)
	CLEAR_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);
#elif (VOLT_SELECT== AVCC)
	SET_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);
#elif (VOLT_SELECT== Internal_256)
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS0);
#endif

	//select prescaller
#if (Prescaller_SELECT== prescaller2)
	SET_BIT(ADCSRA,ADPS0);
#elif (Prescaller_SELECT== prescaller4)
	SET_BIT(ADCSRA,ADPS1);
#elif (Prescaller_SELECT== prescaller8)
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
#elif(Prescaller_SELECT== prescaller16)
	SET_BIT(ADCSRA,ADPS2);
#elif(Prescaller_SELECT== prescaller32)
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS2);
#elif(Prescaller_SELECT== prescaller64)
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
#elif(Prescaller_SELECT== prescaller128)
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
#endif
	//enable ADC
	SET_BIT(ADCSRA,ADEN);
}

u16 ADC_ReadDigital(u8 channel){
	//select channel(BIT MASK)
	ADMUX=ADMUX&0b11100000;
	ADMUX=ADMUX|channel;

	//start convertion
	SET_BIT(ADCSRA,ADCSC);

	//busy wait flag(PIF)
	while(GET_BIT(ADCSRA,ADIF)==0);

	//clear flag(PIF)
		SET_BIT(ADCSRA,ADIF);

	//return read
		return ADC_Reg;
}

u8 VOLT_READ(u8 channel){
	u8 volt=0;
	volt=(ADC_ReadDigital(channel)*5)/1024;
	return volt;
}

