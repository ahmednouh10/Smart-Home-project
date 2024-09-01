/*
 * GLOB_INT_Interface.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Ahmed Saber
 */

#ifndef MCAL_GLOBAL_INT_GLOB_INT_INTERFACE_H_
#define MCAL_GLOBAL_INT_GLOB_INT_INTERFACE_H_

/*The INT_Handler "ISR" definition*/
#define ISR(__VECTOR_N)		void __VECTOR_N(void) __attribute__ ((signal,used));\
		void __VECTOR_N(void)

/*********************** Interrupt vectors *************************/

/* External Interrupt Request 0 */
#define EXT_INT0_vect				__vector_1

/* External Interrupt Request 1 */
#define EXT_INT1_vect				__vector_2

/* External Interrupt Request 2 */
#define EXT_INT2_vect				__vector_3

/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect			__vector_4

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect				__vector_5

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect			__vector_6

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect			__vector_7

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect			__vector_8

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect				__vector_9

/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect			__vector_10

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect				__vector_11

/* Serial Transfer Complete */
#define SPI_STC_vect				__vector_12

/* USART, Rx Complete */
#define USART_RXC_vect				__vector_13

/* USART Data Register Empty */
#define USART_UDRE_vect				__vector_14

/* USART, Tx Complete */
#define USART_TXC_vect				__vector_15

/* ADC Conversion Complete */
#define ADC_vect					__vector_16

/* EEPROM Ready */
#define EE_RDY_vect					__vector_17

/* Analog Comparator */
#define ANA_COMP_vect				__vector_18

/* 2-wire Serial Interface */
#define TWI_vect					__vector_19

/* Store Program Memory Ready */
#define SPM_RDY_vect				__vector_20


void GLOB_INT_Enable(void);

void GLOB_INT_Disable(void);

#endif /* MCAL_GLOBAL_INT_GLOB_INT_INTERFACE_H_ */
