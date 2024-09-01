/*
 * KPD_interface.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Ahmed Saber
 */

#ifndef HAL_KEYPAD_KPD_INTERFACE_H_
#define HAL_KEYPAD_KPD_INTERFACE_H_

#include "KPD_Private.h"
#include "KPD_Config.h"

void vKEYPAD_init(void);

u8 u8KEY_PRESSED();

u16 getNextOption(u16 currentOption);



#endif /* HAL_KEYPAD_KPD_INTERFACE_H_ */
