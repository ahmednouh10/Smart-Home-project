/*
 * BUZ_Program.c
 *
 *  Created on: Aug 19, 2024
 *      Author: HardWare
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Config.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"
#include "BUZ_Config.h"
#include "BUZ_Interface.h"


void Buzzer_init(void) {
    vSet_Pin_Direction(BUZZER_PORT, BUZZER_PIN, OUTPUT);  // Set the buzzer pin as an output
}

// Turn ON the Buzzer
void Buzzer_On(void) {
    vSet_Pin_OUTPUTvalue(BUZZER_PORT, BUZZER_PIN, HIGH);  // Set the buzzer pin high to turn it on
}

// Turn OFF the Buzzer
void Buzzer_Off(void) {
    vSet_Pin_OUTPUTvalue(BUZZER_PORT, BUZZER_PIN, LOW);   // Set the buzzer pin low to turn it off
}

// Toggle the Buzzer
void Buzzer_Toggle(void) {
    vTOGGLE_Pin(BUZZER_PORT, BUZZER_PIN);  // Toggle the state of the buzzer pin
}
