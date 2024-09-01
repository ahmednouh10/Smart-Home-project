/*
 * ADC_Config.h
 *
 *  Created on: Aug 4, 2024
 *      Author: sohas
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_


#define AREF              0
#define AVCC              1
#define Internal_256     3

//write your volt select(AREF,AVCC,Internal_2.56)
#define VOLT_SELECT       AVCC

#define prescaller2   0
#define prescaller4   1
#define prescaller8   2
#define prescaller16  3
#define prescaller32  4
#define prescaller64  5
#define prescaller128 6

//write your prescaller select
#define Prescaller_SELECT  prescaller32

#define Channel_A0  0
#define Channel_A1  1
#define Channel_A2  2
#define Channel_A3  3
#define Channel_A4  4
#define Channel_A5  5
#define Channel_A6  6
#define Channel_A7  7



#endif /* MCAL_ADC_ADC_CONFIG_H_ */
