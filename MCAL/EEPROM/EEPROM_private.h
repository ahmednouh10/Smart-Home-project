/*
 * EEPROM_Private.h
 *
 *  Created on: Aug 18, 2024
 *      Author: HardWare
 */


#ifndef MCAL_EEPROM_EEPROM_PRIVATE_H_
#define MCAL_EEPROM_EEPROM_PRIVATE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
// EEPROM Registers
#define EEARH   (*(volatile uint8_t*)(0x3F))
#define EEARL   (*(volatile uint8_t*)(0x3E))
#define EEDR    (*(volatile uint8_t*)(0x3D))
#define EECR    (*(volatile uint8_t*)(0x3C))

// Bit positions
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3

#endif /* MCAL_EEPROM_EEPROM_PRIVATE_H_ */
