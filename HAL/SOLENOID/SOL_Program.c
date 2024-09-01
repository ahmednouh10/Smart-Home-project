/*
 * SOL_Program.c
 *
 *  Created on: Aug 19, 2024
 *      Author: HardWare
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Config.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"
#include "SOL_Config.h"
#include "SOL_Interface.h"


/**
 * @brief This function initializes the solenoid by setting the SOLENOID_PIN as an output.
 *
 * @param None
 * @return None
 */
void Solenoid_init(void) {
    // Set SOLENOID_PIN as output
    DDRB |= (1 << SOLENOID_PIN);
}

/**
 * @brief This function activates the solenoid by setting the SOLENOID_PIN to a high state.
 *
 * @param None
 * @return None
 */

void Solenoid_activate(void) {
    // Set SOLENOID_PIN high to activate the solenoid
    PORTB |= (1 << SOLENOID_PIN);
}

/**
 * @brief This function deactivates the solenoid by setting the SOLENOID_PIN to a low state.
 *
 * @param None
 * @return None
 */

void Solenoid_deactivate(void) {
    // Set SOLENOID_PIN low to deactivate the solenoid
    PORTB &= ~(1 << SOLENOID_PIN);
}
