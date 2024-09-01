/*
 * SPI_private.h
 *
 *  Created on: Aug 8, 2024
 *      Author: HardWare
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_


#define SPCR    	(*(volatile u8*)0x2D)

#define SPSR    	(*(volatile u8*)0x2E)

#define SPDR 	  	(*(volatile u8*)0x2F)

// SPCR bits
#define    SPIE           7
#define    SPE            6
#define    DORD           5
#define    MSTR           4
#define    CPOL           3
#define    CPHA           2
#define    SPR1           1
#define    SPR0           0

//SPSR bits
#define    SPIF           7
#define    WCOL           6
#define    SPI2X          0

//SPDR bits
#define    MSB            7
#define    LSB            0



#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
