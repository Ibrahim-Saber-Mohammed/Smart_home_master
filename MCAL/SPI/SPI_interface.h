/*
 * SPI_interface.h
 *
 *  Created on: Aug 23, 2021
 *      Author: ibrahim
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

typedef enum{
	SPI_MASTER = ( 0b1 << 4) ,
	SPI_SLAVE  = ( 0b0 << 4)
}SPI_Mode_t;

typedef enum{
	FCLK_4		,
	FCLK_16		,
	FCLK_64		,
	FCLK_128	,
	FCLK_2		,
	FCLK_8		,
	FCLK_32		,
	FCLK_64_DOUBLE
}SPI_CLKSpeed_t;

typedef enum{
	SPI_LEADING_RISING  = ( 0b0 << 3),
	SPI_LEADING_FALLING = ( 0b1 << 3)
}SPI_CPOL_t;

typedef enum{
	SPI_LEADING_SAMPLE  = ( 0b0 << 2),
	SPI_LEADING_SETUP   = ( 0b1 << 2)
}SPI_CPHA_t;

typedef enum{
	SPI_MSB_FIRST = ( 0b0 << 5 ),
	SPI_LSB_FIRST = ( 0b1 << 5)
}SPI_DataOrder_t;

typedef enum{
	SPI_ENABLE_INTERRUPT  = (0b1 << 7),
	SPI_DISABLE_INTERRUPT = (0b0 << 7)
}SPI_Interrupt_t;

typedef enum{
	SPI_ENABLE  = (0b1 << 6),
	SPI_DISABLE = (0b0 << 6)
}SPI_EN_t;

typedef struct{
	SPI_Mode_t 		Mode;
	SPI_CPOL_t		Spi_ClockPolarity;
	SPI_CPHA_t		Spi_ClockPhase	 ;
	SPI_DataOrder_t	Spi_DataOrder	 ;
	SPI_Interrupt_t Spi_Interrupt	 ;
	SPI_EN_t		Spi_State	     ;
}SPI_SlaveConfigs_t;

typedef struct{
	SPI_Mode_t 		Mode		     ;
	SPI_CLKSpeed_t	Spi_Speed	     ;
	SPI_CPOL_t		Spi_ClockPolarity;
	SPI_CPHA_t		Spi_ClockPhase	 ;
	SPI_DataOrder_t	Spi_DataOrder	 ;
	SPI_Interrupt_t Spi_Interrupt	 ;
	SPI_EN_t		Spi_State	     ;
}SPI_MasterConfigs_t;

void SPI_voidSPIInit(void);

u8 SPI_u8SetMasterConfigs(const SPI_MasterConfigs_t * Copy_structSpiConfigurations);

u8 SPI_u8TransmitReceive(u8 Copy_u8Data);

u8 SPI_u8SetSlaveConfigs(const SPI_SlaveConfigs_t * Copy_structSpiConfigurations);



#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
