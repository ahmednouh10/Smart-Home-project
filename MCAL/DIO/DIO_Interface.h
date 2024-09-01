/*
 * DIO_Interface.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Ahmed Saber
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
//***************PROTOTYPE FUNCTION*************************
void vSet_Pin_Direction   (u8 PORT_ID , u8 PIN_ID , u8 Direction);
void vSet_Pin_OUTPUTvalue (u8 PORT_ID , u8 PIN_ID , u8 Value);
void vTOGGLE_Pin          (u8 PORT_ID , u8 PIN_ID);
u8 vGIT_PIN          (u8 PORT_ID , u8 PIN_ID);

void vSet_Port_Direction   (u8 PORT_ID , u8 Direction);
void vSet_Port_OUTPUTvalue (u8 PORT_ID , u8 Value);
void vTOGGLE_port          (u8 PORT_ID );

void vSetInernalPullUp(u8 PORT_ID , u8 PIN_ID );
#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
