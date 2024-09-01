/*
 * LCD_Interface.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Ahmed Saber
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void vLCD_init(void);

void vLCD_sendCOMMAND(u8 command);

void vLCD_sendDATA(u8 data);

void vLCD_Send_String(u8 * str);

void vLCD_Clear();

void vLCD_GO_TO(u8 line ,u8 position );

void LCD_SendINTNumber(s32 n);

void LCD_SendFloatNumber(f32 n, u16 ndigit );

void displayOption(u8 option);

void confirmSelection(u8 option);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
