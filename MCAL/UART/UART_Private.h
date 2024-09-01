/*
 * UART_praiver.h
 *
 *  Created on: May 24, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_UART_UART_PRAIVER_H_
#define MCAL_UART_UART_PRAIVER_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


/* USART Baud Rate Register Low */
#define UBRRL    	(*(volatile u8*)0x29)
/* USART Baud Rate Register High */
#define UBRRH    	(*(volatile u8*)0x40)

/* USART Control and Status Register B */
#define UCSRB   	(*(volatile u8*)0x2A)

#define    RXCIE        7
#define    TXCIE        6
#define    UDRIE        5
#define    RXEN         4
#define    TXEN         3
#define    UCSZ         2
#define    UCSZ2        2
#define    RXB8         1
#define    TXB8         0

/* USART Control and Status Register A */
#define UCSRA    	(*(volatile u8*)0x2B)

#define RXEN    4
#define TXEN    3
#define UDRE    5
#define RXC     7
#define URSEL   7
#define UCSZ0   1
#define UCSZ1   2

/* USART I/O Data Register */
#define UDR       	(*(volatile u8*)0x2C)

/* USART Control and Status Register C */
#define UCSRC     	(*(volatile u8*)0x40)

/* USART Register C */
#define    URSEL        7
#define    UMSEL        6
#define    UPM1         5
#define    UPM0         4
#define    USBS         3
#define    UCSZ1        2
#define    UCSZ0        1
#define    UCPOL        0

#include <avr/io.h>

// Define the baud rate and prescaler
#define BAUD_PRESCALE (((F_CPU / (BAUD * 16UL))) - 1)


#endif /* MCAL_UART_UART_PRAIVER_H_ */
