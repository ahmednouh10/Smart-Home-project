/*
 * LED_Private.h
 *
 *  Created on: Aug 18, 2024
 *      Author: HardWare
 */

#ifndef HAL_LED_LED_PRIVATE_H_
#define HAL_LED_LED_PRIVATE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

// Register Definitions
#define DDRD   (*(volatile u16*)(0x31))
#define PORTD  (*(volatile u16*)(0x32))

#endif /* HAL_LED_LED_PRIVATE_H_ */
