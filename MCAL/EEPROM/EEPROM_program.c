/*
 * EEPROM_Program.c
 *
 *  Created on: Aug 18, 2024
 *      Author: HardWare
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "EEPROM_Interface.h"
#include "EEPROM_Config.h"
#include "EEPROM_Private.h"
#include <util/delay.h>
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;



/**
 * @brief Writes a byte of data to the EEPROM at the specified address.
 *
 * This function waits for the completion of any ongoing EEPROM write operations,
 * then writes a byte of data to the specified EEPROM address.
 *
 * @param address The address in EEPROM to write to (0 to 1023 for ATmega32).
 * @param data The byte of data to write.
 */

void EEPROM_WriteByte(uint16_t address, uint8_t data) {
    // Wait for completion of previous write
    while (EECR & (1 << EEWE));

    // Set up address and data registers
    EEARL = (uint8_t)address;
    EEARH = (uint8_t)(address >> 8);
    EEDR = data;

    // Write logical one to EEMWE
    EECR |= (1 << EEMWE);

    // Start EEPROM write by setting EEWE
    EECR |= (1 << EEWE);
}

/**
 * @brief Reads a byte of data from the EEPROM at the specified address.
 *
 * This function waits for the completion of any ongoing EEPROM write operations,
 * then reads a byte of data from the specified EEPROM address.
 *
 * @param address The address in EEPROM to read from (0 to 1023 for ATmega32).
 * @return The byte of data read from the specified address.
 */

uint8_t EEPROM_ReadByte(uint16_t address) {
    // Wait for completion of previous write
    while (EECR & (1 << EEWE));

    // Set up address register
    EEARL = (uint8_t)address;
    EEARH = (uint8_t)(address >> 8);

    // Start EEPROM read by writing EERE
    EECR |= (1 << EERE);

    // Return data from data register
    return EEDR;
}

/**
 * @brief Writes a block of data to the EEPROM.
 *
 * This function writes a block of data of a specified size to consecutive
 * EEPROM addresses, starting at the specified destination address.
 *
 * @param src Pointer to the source data (in RAM).
 * @param dest Pointer to the starting destination address in EEPROM.
 * @param size The size of the data block to write (in bytes).
 */

void EEPROM_WriteBlock(const void* src, void* dest, uint16_t size) {
    for (uint16_t i = 0; i < size; i++) {
        EEPROM_WriteByte((uint16_t)dest + i, ((uint8_t*)src)[i]);
    }
}

/**
 * @brief Reads a block of data from the EEPROM.
 *
 * This function reads a block of data of a specified size from consecutive
 * EEPROM addresses, starting at the specified source address, into RAM.
 *
 * @param dest Pointer to the destination buffer (in RAM) where data will be stored.
 * @param src Pointer to the starting source address in EEPROM.
 * @param size The size of the data block to read (in bytes).
 */

void EEPROM_ReadBlock(void* dest, const void* src, uint16_t size) {
    for (uint16_t i = 0; i < size; i++) {
        ((uint8_t*)dest)[i] = EEPROM_ReadByte((uint16_t)src + i);
    }
}
