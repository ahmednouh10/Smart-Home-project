/*
 * SPI_Interface.h
 *
 *  Created on: Aug 8, 2024
 *      Author: HardWare
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_


// 1- Select which bit to send first 	"Options -> Configuration"
#define LEAST_BIT				0
#define MOST_BIT				1

//2- Select Master or Slave			"Options -> Configuration"
#define SLAVE					0
#define MASTER					1

//3- Select Clock Polarity				"Options -> Configuration"
#define RISING_L 				0
#define FALLING_L				1


//4- Select Clock Phase				"Options -> Configuration"
#define SAMPLE_L 				0
#define SETUP_L					1

//5- Select Pre-scaler					"Options -> Configuration"
#define prescaller_f_4			0
#define prescaller_f_16			1
#define prescaller_f_64			2
#define prescaller_f_128		3
#define prescaller_f_2			4
#define prescaller_f_8			5
#define prescaller_f_32			6
#define prescaller_f_64_D		7

/*
 * 1- Select which bit to send first 	"Options -> Configuration"
 * 2- Select Master or Slave			"Options -> Configuration"
 * 3- Select Clock Polarity				"Options -> Configuration"
 * 4- Select Clock Phase				"Options -> Configuration"
 * 5- Select Pre-scaler					"Options -> Configuration"
 * 6- Enable SPI
 * */
void SPI_Init(void);


/*
 * 1- busy wait on write collision flag
 * 2- add data to data register
 * 3- busy wait on SPI Operation flag
 * 4- read data from the data register
 * */
u8 SPI_Tranceive(u8 data);

/*
 * Set enable bit
 * */
void SPI_Enable(void);

/*
 * Clear enable bit
 * */
void SPI_Disable(void);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
