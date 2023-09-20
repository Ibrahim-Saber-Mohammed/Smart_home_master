/*
 * EEPROM_program.c
 *
 *  Created on: Aug 12, 2021
 *      Author: ibrahim
 */
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"

void EEPROM_voidWriteByte	(u16 Copy_u16ByteAddress, u8 Copy_u8DataValue						)
{
	/* wait for the EEPROM to be ready for the next Write  */
	while ( GET_BIT(EECR, EEWE) == 1);
	/* Set the address  */
	EEAR = (Copy_u16ByteAddress);
	/* write the Data to the Data Register  */
	EEDR = Copy_u8DataValue;
	/* Write '1' to the EEMWE bit */
	asm("SBI 0x1C,2");
	//EECR |= (1 << EEMWE); = //SET_BIT(EECR,EEMWE);

	/*Starting write operation*/
	/* Write '1' to the EEWE */
	asm("SBI 0x1C,1");
	//EECR |= (1 << EEWE); = //SET_BIT(EECR,EEWE);

}

void EEPROM_voidWriteBlock	(u16 Copy_u16ByteAddress, u8 Copy_u8BlockSize, u8 * Copy_PtrData	)
{
	u8 LOC_LoopIterartor = 0;
	for(LOC_LoopIterartor = 0; LOC_LoopIterartor < Copy_u8BlockSize; LOC_LoopIterartor++)
	{
		EEPROM_voidWriteByte( (Copy_u16ByteAddress + LOC_LoopIterartor), Copy_PtrData[LOC_LoopIterartor]);
	}

}

void EEPROM_voidReadByte		(u16 Copy_u16ByteAddress, u8 *Copy_ptrReturnDataValue				)
{
	/* wait the previous write operation is done  */
	while(GET_BIT(EECR, EEWE) == 1);
	/* Write the address  */
	EEAR = Copy_u16ByteAddress ;
	/* Start Read Operation */
	EECR |= (1<<EERE);
	/* Return Data to the pointer */
	*Copy_ptrReturnDataValue = EEDR;
}

void EEPROM_voidReadBlock		(u16 Copy_u16ByteAddress, u8 Copy_u8BlockSize , u8 *Copy_ptrReturnDataValue)
{
	u8 LOC_LoopIterator = 0;
	for(LOC_LoopIterator = 0; LOC_LoopIterator<Copy_u8BlockSize; LOC_LoopIterator++)
	{
		EEPROM_voidReadByte( ( Copy_u16ByteAddress + LOC_LoopIterator ), ( Copy_ptrReturnDataValue + LOC_LoopIterator ) );
	}
}
