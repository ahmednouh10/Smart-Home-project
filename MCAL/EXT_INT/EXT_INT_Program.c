/*
 * EXT_INT_Program.C
 *
 *  Created on: Aug 1, 2024
 *      Author: Ahmed Saber
 */
#include "EXT_INT_Interface.h"
#include "EXT_INT_Private.h"
#include "EXT_INT_Config.h"

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void EXT_INT_Enable(EXT_INT_Sources source)
{
	switch(source)
	{
		case EXT_INT_0:
			SET_BIT(GICR,INT0_En_Bit);
			break;

		case EXT_INT_1:
			SET_BIT(GICR,INT1_En_Bit);
			break;

		case EXT_INT_2:
			SET_BIT(GICR,INT2_En_Bit);
			break;

		default:
			break;
			/*error handling*/
	}
}

void EXT_INT_Disable(EXT_INT_Sources source)
{
	switch(source)
	{
		case EXT_INT_0:
			CLEAR_BIT(GICR,INT0_En_Bit);
			break;

		case EXT_INT_1:
			CLEAR_BIT(GICR,INT1_En_Bit);
			break;

		case EXT_INT_2:
			CLEAR_BIT(GICR,INT2_En_Bit);
			break;

		default:
			break;
			/*error handling*/
	}
}

void EXT_INT_setTriggerType(EXT_INT_Sources source, EXT_INT_TriggerTypes trigger)
{
	switch(source)
	{
		case EXT_INT_0:
			switch(trigger)
			{
				case LOW_LEVEL:
					CLEAR_BIT(MCUCR,ISC00);
					CLEAR_BIT(MCUCR,ISC01);
					break;

				case ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR,ISC00);
					CLEAR_BIT(MCUCR,ISC01);
					break;

				case FALLING:
					CLEAR_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
					break;

				case RISING:
					SET_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
					break;

				default:
					break;
					/*error handling*/
			}
			break;

		case EXT_INT_1:
			switch(trigger)
			{
				case LOW_LEVEL:
					CLEAR_BIT(MCUCR,ISC10);
					CLEAR_BIT(MCUCR,ISC11);
					break;

				case ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR,ISC10);
					CLEAR_BIT(MCUCR,ISC11);
					break;

				case FALLING:
					CLEAR_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					break;

				case RISING:
					SET_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					break;

				default:
					break;
					/*error handling*/
			}
			break;

		case EXT_INT_2:
			switch(trigger)
			{
				case FALLING:
					CLEAR_BIT(MCUCSR,ISC2);
					break;

				case RISING:
					SET_BIT(MCUCSR,ISC2);
					break;

				default:
					break;
					/*error handling*/
			}
			break;

		default:
			break;
			/*error handling*/
	}
}
