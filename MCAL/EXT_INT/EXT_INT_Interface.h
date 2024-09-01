/*
 * EXT_INT_Interface.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Ahmed Saber
 */

#ifndef MCAL_EXT_INT_EXT_INT_INTERFACE_H_
#define MCAL_EXT_INT_EXT_INT_INTERFACE_H_

typedef enum
{
	EXT_INT_0,
	EXT_INT_1,
	EXT_INT_2
}EXT_INT_Sources;

typedef enum
{
	LOW_LEVEL,
	ANY_LOGICAL_CHANGE,
	FALLING,
	RISING
}EXT_INT_TriggerTypes;

void EXT_INT_Enable(EXT_INT_Sources source);

void EXT_INT_Disable(EXT_INT_Sources source);

void EXT_INT_setTriggerType(EXT_INT_Sources source, EXT_INT_TriggerTypes trigger);

#endif /* MCAL_EXT_INT_EXT_INT_INTERFACE_H_ */
