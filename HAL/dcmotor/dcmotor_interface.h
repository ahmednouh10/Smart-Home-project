/*
 * dcmotor_interface.h
 *
 *  Created on: Aug 25, 2024
 *      Author: ahmed
 */

#define HAL_DCMOTOR_DCMOTOR_INTERFACE_H_

// DC_Motor_Interface.h

#ifndef DC_MOTOR_INTERFACE_H
#define DC_MOTOR_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

// Initialize the DC motor driver
void DC_Motor_Init(void);

// Turn the DC motor on with a specified speed (0-100%)
void DC_Motor_On(uint8_t speed);

// Turn the DC motor off
void DC_Motor_Off(void);

#endif /* HAL_DCMOTOR_DCMOTOR_INTERFACE_H_ */
