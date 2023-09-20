/*
 * EEPROM_interface.h
 *
 *  Created on: Aug 12, 2021
 *      Author: ibrahim
 */

#ifndef MCAL_EEPROM_EEPROM_INTERFACE_H_
#define MCAL_EEPROM_EEPROM_INTERFACE_H_

void EEPROM_voidWriteByte	(u16 Copy_u16ByteAddress, u8 Copy_u8DataValue						);

void EEPROM_voidWriteBlock	(u16 Copy_u16ByteAddress, u8 Copy_u8BlockSize, u8 * Copy_PtrData	);

void EEPROM_voidReadByte	(u16 Copy_u16ByteAddress, u8 *Copy_ptrReturnDataValue				);

void EEPROM_voidReadBlock	(u16 Copy_u16ByteAddress, u8 Copy_u8BlockSize , u8 *Copy_ptrReturnDataValue);

#endif /* MCAL_EEPROM_EEPROM_INTERFACE_H_ */
