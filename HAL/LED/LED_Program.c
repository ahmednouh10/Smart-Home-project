/*
 * LED_Program.c
 *
 *  Created on: Aug 18, 2024
 *      Author: HardWare
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Config.h"
#include "../../MCAL/DIO/DIO_Private.h"
#include <util/delay.h>
#include "LED_Interface.h"
#include "LED_Config.h"
#include "LED_Private.h"


/**
 * @brief This function initializes the LED by setting the LED_PIN as an output.
 *
 * @param None
 * @return None
 */

void LED_init(void) {
    DDRD |= (1 << LED_PIN);  // Set LED_PIN as output
}

/**
 * @brief This function turns on the LED by setting the LED_PIN to a high state.
 *
 * @param None
 * @return None
 */

void LED_On(void) {
    PORTD |= (1 << LED_PIN); // Turn on the LED
}

/**
 * @brief This function turns off the LED by setting the LED_PIN to a low state.
 *
 * @param None
 * @return None
 */

void LED_Off(void) {
    PORTD &= ~(1 << LED_PIN); // Turn off the LED
}
