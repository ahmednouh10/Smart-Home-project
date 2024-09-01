/*
 * dcmotor_program.c
 *
 *  Created on: Aug 25, 2024
 *      Author: ahmed
 */


#include "../../LIB/STD_TYPES.h"
#include <avr/io.h>

// Define motor control pins and ports
#define MOTOR_PWM_PIN    PB2
#define MOTOR_DIR_PIN     PB3
#define MOTOR_PWM_DDR     DDRB
#define MOTOR_DIR_DDR     DDRB
#define MOTOR_PWM_PORT    PORTB
#define MOTOR_DIR_PORT    PORTB

void DC_Motor_Init(void) {
    // Set motor control pins as output
    MOTOR_DIR_DDR |= (1 << MOTOR_DIR_PIN);
    MOTOR_PWM_DDR |= (1 << MOTOR_PWM_PIN);

    // Set initial motor direction (forward or backward)
    MOTOR_DIR_PORT &= ~(1 << MOTOR_DIR_PIN); // Example: forward direction

    // Configure Timer/Counter1 for Fast PWM mode
    // Fast PWM mode with 10-bit resolution, non-inverted PWM on OC1A
    TCCR1A = (1 << COM1A1) | (1 << WGM11); // Fast PWM mode (ICR1 as top value)
    TCCR1B = (1 << WGM13) | (1 << CS11);   // Fast PWM mode, Prescaler 8
    ICR1 = 39999; // Set PWM frequency (with prescaler 8, this gives approximately 20kHz)
}

void DC_Motor_On(uint8_t speed) {
    // Set PWM duty cycle based on speed (0-100%)
    if (speed > 100) speed = 100; // Limit speed to 100%
    OCR1A = (speed * ICR1) / 100;  // Set duty cycle for PWM

    // Ensure the PWM signal is enabled
    MOTOR_PWM_PORT |= (1 << MOTOR_PWM_PIN);
}

void DC_Motor_Off(void) {
    // Set PWM duty cycle to 0 (effectively stops the motor)
    OCR1A = 0;

    // Optionally, you can also disable the PWM signal (depends on your use case)
    // MOTOR_PWM_PORT &= ~(1 << MOTOR_PWM_PIN);
}
