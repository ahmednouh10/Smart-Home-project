/*
 * DIO_Program.c
 *
 *  Created on: Aug 1, 2024
 *      Author: Ahmed Saber
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"

void vSet_Pin_Direction(u8 PORT_ID , u8 PIN_ID , u8 Direction)
{
	switch(Direction)
	{
	case OUTPUT:
		switch(PORT_ID)
		{
		case PORT_A: SET_BIT(DDRA,PIN_ID); break;
		case PORT_B: SET_BIT(DDRB,PIN_ID); break;
		case PORT_C: SET_BIT(DDRC,PIN_ID); break;
		case PORT_D: SET_BIT(DDRD,PIN_ID); break;

		}
		break;


		case INPUT:
			switch(PORT_ID)
			{
			case PORT_A: CLEAR_BIT(DDRA,PIN_ID); break;
			case PORT_B: CLEAR_BIT(DDRB,PIN_ID); break;
			case PORT_C: CLEAR_BIT(DDRC,PIN_ID); break;
			case PORT_D: CLEAR_BIT(DDRD,PIN_ID); break;

			}
			break;
	}

}

void vSet_Pin_OUTPUTvalue (u8 PORT_ID , u8 PIN_ID , u8 Value)
{
	switch(Value)
	{
	case HIGH:
		switch(PORT_ID)
		{
		case PORT_A: SET_BIT(PORTA,PIN_ID); break;
		case PORT_B: SET_BIT(PORTB,PIN_ID); break;
		case PORT_C: SET_BIT(PORTC,PIN_ID); break;
		case PORT_D: SET_BIT(PORTD,PIN_ID); break;

		}
		break;


		case LOW:
			switch(PORT_ID)
			{
			case PORT_A: CLEAR_BIT(PORTA,PIN_ID); break;
			case PORT_B: CLEAR_BIT(PORTB,PIN_ID); break;
			case PORT_C: CLEAR_BIT(PORTC,PIN_ID); break;
			case PORT_D: CLEAR_BIT(PORTD,PIN_ID); break;

			}
			break;
	}

}

void vTOGGLE_Pin          (u8 PORT_ID , u8 PIN_ID)
{
	switch(PORT_ID)
	{
	case PORT_A : TOG_BIT(PORTA,PIN_ID);break;
	case PORT_B : TOG_BIT(PORTB,PIN_ID);break;
	case PORT_C : TOG_BIT(PORTC,PIN_ID);break;
	case PORT_D : TOG_BIT(PORTD,PIN_ID);break;
	}
}


void vSet_Port_Direction   (u8 PORT_ID , u8 Direction)
{
	switch(Direction)
	{
	case OUTPUT:
		switch(PORT_ID)
		{
		case PORT_A: DDRA=0xff; break;
		case PORT_B: DDRB=0xff; break;
		case PORT_C: DDRC=0xff; break;
		case PORT_D:DDRD=0xff; break;

		}
		break;


		case INPUT:
			switch(PORT_ID)
			{
			case PORT_A: DDRA=0x00; break;
			case PORT_B: DDRB=0x00; break;
			case PORT_C: DDRC=0x00; break;
			case PORT_D:DDRD=0x00; break;

			}
			break;
	}

}

void vSet_Port_OUTPUTvalue (u8 PORT_ID , u8 Value)
{


		switch(PORT_ID)
		{
		case PORT_A: PORTA=Value; break;
		case PORT_B: PORTB=Value; break;
		case PORT_C: PORTC=Value; break;
		case PORT_D: PORTD=Value; break;

		}


	}

u8 vGIT_PIN (u8 PORT_ID , u8 PIN_ID)
{
	u8 BIT=0;
	switch(PORT_ID)
			{
			case PORT_A: BIT=GET_BIT(PINA,PIN_ID); break;
			case PORT_B: BIT=GET_BIT(PINB,PIN_ID); break;
			case PORT_C: BIT=GET_BIT(PINC,PIN_ID); break;
			case PORT_D: BIT=GET_BIT(PIND,PIN_ID); break;

			}
	return BIT;
}

void vSetInernalPullUp(u8 PORT_ID , u8 PIN_ID )
{
	vSet_Pin_OUTPUTvalue(PORT_ID,PIN_ID,HIGH);
}

