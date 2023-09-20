/*
 * SPI_program.c
 *
 *  Created on: Aug 23, 2021
 *      Author: ibrahim
 */

#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "../DIO/GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void SPI_voidSPIInit(void);

u8 SPI_u8SetMasterConfigs(const SPI_MasterConfigs_t * Copy_structSpiConfigurations)
{

	u8 Loacal_u8ErrorState = STD_OK;
	if( Copy_structSpiConfigurations != NULL )
	{
		SPCR = 0x00;
		SPSR = 0x00;
		/* Disable SPI */
		CLR_BIT(SPCR , SPE);
		SPCR |= Copy_structSpiConfigurations->Mode |Copy_structSpiConfigurations->Spi_ClockPhase | Copy_structSpiConfigurations->Spi_ClockPolarity | Copy_structSpiConfigurations->Spi_DataOrder | Copy_structSpiConfigurations->Spi_Interrupt;
		SPCR |= ( ( Copy_structSpiConfigurations->Spi_Speed ) & 0x03);
		SPSR |=	GET_BIT(Copy_structSpiConfigurations->Spi_Speed , 2) ;
		SPCR |= Copy_structSpiConfigurations->Spi_State;
	}
	else
	{
		Loacal_u8ErrorState = STD_NOK;
	}
	return (Loacal_u8ErrorState);
}

u8 SPI_u8SetSlaveConfigs(const SPI_SlaveConfigs_t * Copy_structSpiConfigurations)
{
	u8 Loacal_u8ErrorState = STD_OK;
	if( Copy_structSpiConfigurations != NULL )
	{
		SPCR = 0x00;
		/* Disable SPI */
		CLR_BIT(SPCR , SPE);
		SPCR |= Copy_structSpiConfigurations->Mode |Copy_structSpiConfigurations->Spi_ClockPhase | Copy_structSpiConfigurations->Spi_ClockPolarity | Copy_structSpiConfigurations->Spi_DataOrder | Copy_structSpiConfigurations->Spi_Interrupt;
		SPCR |= Copy_structSpiConfigurations->Spi_State;
	}
	else
	{
		Loacal_u8ErrorState = STD_NOK;
	}
	return (Loacal_u8ErrorState);

}
u8 SPI_u8TransmitReceive(u8 Copy_u8Data)
{
//	u8 Local_u8ErrorState = STD_OK;

	SPDR = Copy_u8Data;
	while( !((SPSR >> SPIF) & 1) );
//	if(Copy_ptrDataBuffer != NULL)
//	{
//		*Copy_ptrDataBuffer = SPDR;
//	}
//	else
//	{
//		Local_u8ErrorState = STD_NOK;
//	}
	return SPDR;
}


