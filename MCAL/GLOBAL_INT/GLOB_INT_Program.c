/*
 * GLOB_INT_Program.c
 *
 *  Created on: Aug 1, 2024
 *      Author: Ahmed Saber
 */
#include "GLOB_INT_Interface.h"
#include "GLOB_INT_Private.h"
#include "GLOB_INT_Config.h"

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void GLOB_INT_Enable(void)
{
	/*Enable GIE = 1*/
	SET_BIT(SREG,I);
}

void GLOB_INT_Disable(void)
{
	/*Disable GIE = 0*/
	CLEAR_BIT(SREG,I);
}
