/*
 * TIMER_Config.h
 *
 *  Created on: Aug 5, 2024
 *      Author: sohas
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

//#include "../../LIB/STD_TYPES.h"
//timer0
#define TIMER0_Prescaler     TIMER0_SCALER_256
#define TIMER0_Mode          TIMER0_FASTPWM_MODE
#define TIMER0_INITIAL_VALUE			0
#define TIMER0_PWM_MODE        inverting

//timer2
#define TIMER2_Prescaler     TIMER2_SCALER_256
#define TIMER2_Mode          TIMER2_FASTPWM_MODE
#define TIMER2_INITIAL_VALUE			0


#define TIMER2_PWM_MODE        inverting

#define TIMER1_PRESCALLER               TIMER1_SCALER_8

#define TIMER1_MODE                     TIMER1_FASTPWM_ICR_TOP_MODE


#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
