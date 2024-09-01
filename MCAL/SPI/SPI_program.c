/*
 * SPI_program.c
 *
 *  Created on: Aug 8, 2024
 *      Author: HardWare
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"




void SPI_Init(void)
{

	// 1- Select which bit to send first 	"Options -> Configuration"
	switch(FIRST_BIT_TO_SEND)
	{
	case LEAST_BIT:
		SET_BIT(SPCR,DORD);
		break;

	case MOST_BIT:
		CLEAR_BIT(SPCR,DORD);
		break;

	default:
		break;
		//error handling
	}
	// 2- Select Master or Slave			"Options -> Configuration"
	switch(MODE)
	{
	case SLAVE:
		CLEAR_BIT(SPCR,MSTR);
		break;

	case MASTER:
		SET_BIT(SPCR,MSTR);
		break;

	default:
		break;
		//error handling
	}

	// 3- Select Clock Polarity				"Options -> Configuration"
	switch(POLARITY)
	{
	case RISING_L:
		CLEAR_BIT(SPCR,CPOL);
		break;

	case FALLING_L:
		SET_BIT(SPCR,CPOL);
		break;

	default:
		break;
		//error handling
	}

	//* 4- Select Clock Phase				"Options -> Configuration"
	switch(PHASE)
	{
	case SAMPLE_L:
		CLEAR_BIT(SPCR,CPOL);
		break;

	case SETUP_L:
		SET_BIT(SPCR,CPOL);
		break;

	default:
		break;
		//error handling
	}

	//	* 5- Select Pre-scaler					"Options -> Configuration"

	switch(PRESCALLER)
	{
	case prescaller_f_4:
		CLEAR_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		CLEAR_BIT(SPCR,SPI2X);
		break;

	case prescaller_f_16:
		SET_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		CLEAR_BIT(SPCR,SPI2X);
		break;

	case prescaller_f_64:
		CLEAR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLEAR_BIT(SPCR,SPI2X);
		break;

	case prescaller_f_128:
		SET_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLEAR_BIT(SPCR,SPI2X);
		break;

	case prescaller_f_2:
		CLEAR_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		SET_BIT(SPCR,SPI2X);
		break;

	case prescaller_f_8:
		SET_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		SET_BIT(SPCR,SPI2X);
		break;

	case prescaller_f_32:
		CLEAR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		SET_BIT(SPCR,SPI2X);
		break;

	case prescaller_f_64_D:
		SET_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		SET_BIT(SPCR,SPI2X);
		break;


	default:
		break;
		//error handling
	}


	//	 * 6- Enable SPI
	SPI_Enable();

}

u8 SPI_Tranceive(u8 data)
{
	u8 retData =0 ;

	//* 1- busy wait on write collision flag  ?

	while(GET_BIT(SPSR,WCOL));

	//* 2- add data to data register

	SPDR=data;

	//* 3- busy wait on SPI Operation flag ?

	while(GET_BIT(SPSR,SPIF)==0); // ?? why == 0 

	// * 4- read data from the data register

	retData=SPDR;


	return retData;
}


void SPI_Enable(void)
{
	SET_BIT(SPCR,SPE);
}

/*
 * Clear enable bit
 * */
void SPI_Disable(void)
{
	CLEAR_BIT(SPCR,SPE);
}
