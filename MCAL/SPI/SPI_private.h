/*
 * SPI_private.h
 *
 *  Created on: Aug 23, 2021
 *      Author: ibrahim
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_



#define SPCR		*( (volatile u8 * const) 0x2D )
#define SPIE		7
#define SPE			6
#define DORD		5
#define MSTR		4
#define CPOL		3
#define CPHA		2
#define SPR1		1
#define SPR0		0


#define SPSR		*( (volatile u8 * const) 0x2E )
#define SPIF		7
#define WCOL		6
#define SPDR		*( (volatile u8 * const) 0x2F )





#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
