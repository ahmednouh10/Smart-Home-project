/*
 * BIT_MATH.h
 *
 *  Created on: Apr 6, 2024
 *      Author: Mahmoud
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_


#define SET_BIT(VAR,BITNO) (VAR|=(1<<BITNO))
#define CLEAR_BIT(VAR,BITNO) (VAR&=(~(1<<BITNO)))
#define TOG_BIT(VAR,BITNO) (VAR^=(1<<BITNO))
#define GET_BIT(VAR,BITNO) ((VAR>>BITNO)&1)


#endif /* LIB_BIT_MATH_H_ */
