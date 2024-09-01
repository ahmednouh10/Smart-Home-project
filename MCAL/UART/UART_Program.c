/*
 * UART_prog.c
 *
 *  Created on: May 24, 2024
 *      Author: Mahmoud
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;


/**
 * @brief Initializes the UART communication.
 *
 * This function sets up the UART for communication by enabling both
 * the transmitter and receiver. It also configures the UART for
 * 8-bit data transmission and sets the baud rate according to the
 * `BAUD_PRESCALE` value, which is based on the desired baud rate
 * and the system clock frequency.
 */

void UART_init(void) {
    UCSRB |= (1 << RXEN) | (1 << TXEN); // Enable RX and TX
    UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // 8-bit data
    UBRRL = BAUD_PRESCALE;
    UBRRH = (BAUD_PRESCALE >> 8);
}

/**
 * @brief Transmits a single character via UART.
 *
 * This function waits until the UART data register is empty, then
 * transmits the specified character by loading it into the UART data
 * register (UDR).
 *
 * @param ch The character to transmit.
 */

void UART_TxChar(char ch) {
    while (!(UCSRA & (1 << UDRE)));
    UDR = ch;
}

/**
 * @brief Receives a single character via UART.
 *
 * This function waits until a character is received (i.e., when the
 * UART receive complete flag (RXC) is set), then returns the received
 * character from the UART data register (UDR).
 *
 * @return The received character.
 */

char UART_RxChar(void) {
    while (!(UCSRA & (1 << RXC)));
    return UDR;
}

/**
 * @brief Transmits a null-terminated string via UART.
 *
 * This function sends a string character by character until it reaches
 * the null terminator (`\0`). It uses the `UART_TxChar()` function to
 * send each character.
 *
 * @param str Pointer to the null-terminated string to transmit.
 */

void UART_SendString(const char* str) {
    while (*str) {
        UART_TxChar(*str++);
    }
}

/**
 * @brief Receives a string of characters via UART until a newline or buffer is full.
 *
 * This function reads characters from the UART one by one and stores
 * them into the provided buffer until it encounters a carriage return
 * (`\r`), a newline (`\n`), or the buffer is full (one character less
 * than the buffer size to leave space for the null terminator). The
 * received string is then null-terminated.
 *
 * @param buffer Pointer to the buffer where the received string will be stored.
 * @param size The maximum size of the buffer.
 */

void UART_ReceiveString(char* buffer, uint8_t size) {
    uint8_t i = 0;
    char received_char;

    while (i < size - 1) {
        received_char = UART_RxChar();
        if (received_char == '\r' || received_char == '\n') {
            break;
        }
        buffer[i++] = received_char;
    }
    buffer[i] = '\0';  // Null-terminate the string
}
