/*
 * EEPROM_private.h
 *
 *  Created on: Aug 12, 2021
 *      Author: ibrahim
 */

#ifndef MCAL_EEPROM_EEPROM_PRIVATE_H_
#define MCAL_EEPROM_EEPROM_PRIVATE_H_

#define	EEAR				*((volatile u16* const ) 0x3E)
#define	EEDR				*((volatile u8 * const ) 0x3D)
#define	EECR				*((volatile u8 * const ) 0x3C)

#define EERIE				3
#define EEMWE				2
#define EEWE				1
#define EERE				0

#endif /* MCAL_EEPROM_EEPROM_PRIVATE_H_ */
