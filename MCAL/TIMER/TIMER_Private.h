/*
 * TIMER_Private.h
 *
 *  Created on: Aug 5, 2024
 *      Author: sohas
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

//#include "../../LIB/STD_TYPES.h"

/*TIMER0*/
#define TCNT0        (*(volatile u8*)0x52)
#define TCCR0        (*(volatile u8*)0x53)
#define TIMSK        (*(volatile u8*)0x59)
#define TIFR         (*(volatile u8*)0x58)
#define OCR0         (*(volatile u8*)0x5c)
#define TCNT2        (*(volatile u8*)0x44)
#define TCCR2        (*(volatile u8*)0x45)
#define OCR2         (*(volatile u8*)0x5c)


//TCCR0
#define CS00     0
#define CS01     1
#define CS02     2
#define WGM01    3
#define COM00    4
#define COM01    5
#define WGM00    6
#define FOC0     7

//TCCR2
#define CS20     0
#define CS21     1
#define CS22     2
#define WGM21    3
#define COM20    4
#define COM21    5
#define WGM20    6
#define FOC2     7

//TIMSK
#define TOIE0    0
#define OCIE0    1
#define TOIE1    2
#define OCIE1B   3
#define OCIE1A   4
#define TICIE1   5
#define TOIE2    6
#define OCIE2    7

//TIFR
#define TOV0     0
#define OCF0     1
#define TOV1     2
#define OCF1B    3
#define OCF1A    4
#define ICF1     5
#define TOV2     6
#define OCF2     7

/*timer1*/
#define ICR1         (*(volatile unsigned short int*)0x46)
#define ICR1L     (*(volatile unsigned char*)0x46)
#define ICR1H     (*(volatile unsigned char*)0x47)
#define OCR1B     (*(volatile unsigned short*)0x48)
#define OCR1BL    (*(volatile unsigned char*)0x48)
#define OCR1BH       (*(volatile unsigned char*)0x49)
#define OCR1A     (*(volatile unsigned short int*)0x4A)
#define OCR1AL    (*(volatile unsigned char*)0x4A)
#define OCR1AH      (*(volatile unsigned char*)0x4B)
#define TCNT1       (*(volatile unsigned short*)0x4C)
#define TCNT1L    (*(volatile unsigned char*)0x4C)
#define TCNT1H    (*(volatile unsigned char*)0x4D)
#define TCCR1B       (*(volatile unsigned char*)0x4E)
#define TCCR1A        (*(volatile unsigned char*)0x4F)

#define SFIOR       (*(volatile unsigned char*)0x50)

#define OSCCAL       (*(volatile unsigned char*)0x51)

/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/* WDTCR */
#define WDTCR    (*(volatile unsigned char*)0x41)
/* bits 7-5 reserved */
#define WDTOE   4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0





#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
