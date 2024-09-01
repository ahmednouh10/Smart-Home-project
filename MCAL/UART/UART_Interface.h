/*
 * UART_int.h
 *
 *  Created on: May 24, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

// Function prototypes for UART driver
void UART_init(void);
void UART_TxChar(char ch);
char UART_RxChar(void);
void UART_SendString(const char* str);
void UART_ReceiveString(char* buffer, uint8_t size);

#endif /* MCAL_UART_UART_INT_H_ */
