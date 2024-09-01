/*
 * EEPROM_Interface.h
 *
 *  Created on: Aug 18, 2024
 *      Author: HardWare
 */

#ifndef MCAL_EEPROM_EEPROM_INTERFACE_H_
#define MCAL_EEPROM_EEPROM_INTERFACE_H_

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
// Function Prototypes
void EEPROM_WriteByte(uint16_t address, uint8_t data);
uint8_t EEPROM_ReadByte(uint16_t address);

void EEPROM_WriteBlock(const void* src, void* dest, uint16_t size);
void EEPROM_ReadBlock(void* dest, const void* src, uint16_t size);

#endif /* MCAL_EEPROM_EEPROM_INTERFACE_H_ */
