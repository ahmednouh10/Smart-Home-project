/*
 * KPD_Config.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Ahmed Saber
 */

#ifndef HAL_KEYPAD_KPD_CONFIG_H_
#define HAL_KEYPAD_KPD_CONFIG_H_

#include "KPD_Private.h"
#include "KPD_Interface.h"
/*Columns*/
/*c1*/
#define COL1_PORT  	PORT_B
#define COL1_PIN   	PIN_4

/*c2*/
#define COL2_PORT 	PORT_B
#define COL2_PIN   	PIN_5

/*c3*/
#define COL3_PORT 	PORT_B
#define COL3_PIN   	PIN_6

/*c4*/
#define COL4_PORT 	PORT_B
#define COL4_PIN  	PIN_7

/*Rows*/
/*R1*/
#define ROW1_PORT   PORT_D
#define ROW1_PIN   	PIN_3
/*R2*/
#define ROW2_PORT   PORT_D
#define ROW2_PIN    PIN_4
/*R3*/
#define ROW3_PORT  	PORT_D
#define ROW3_PIN   	PIN_5
/*R4*/
#define ROW4_PORT   PORT_D
#define ROW4_PIN   	PIN_6

#endif /* HAL_KEYPAD_KPD_CONFIG_H_ */
