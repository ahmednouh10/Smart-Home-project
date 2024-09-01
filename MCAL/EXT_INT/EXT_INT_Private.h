/*
 * EXT_INT_Private.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Ahmed Saber
 */

#ifndef MCAL_EXT_INT_EXT_INT_PRIVATE_H_
#define MCAL_EXT_INT_EXT_INT_PRIVATE_H_

#define MCUCR 		(*(volatile u8*)0x55)
#define MCUCSR 		(*(volatile u8*)0x54)
#define GICR 		(*(volatile u8*)0x5B)
#define GIFR 		(*(volatile u8*)0x5A)

#endif /* MCAL_EXT_INT_EXT_INT_PRIVATE_H_ */
