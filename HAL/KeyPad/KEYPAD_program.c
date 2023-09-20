/*
 * KEYPAD_program.c
 *
 *  Created on: Jun 27, 2021
 *      Author: ibrahim
 */
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MAth/BIT_MATH.h"
#include "../../MCAL/DIO/GPIO_interface.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "util/delay.h"


void KEYPAD_voidInit(void)
{
	/* Set the Directions of Rows as Input */
	GPIO_voidSetPinDir(KPAD_ROW_PORT,KPAD_ROW0, INPUT);
	GPIO_voidSetPinDir(KPAD_ROW_PORT,KPAD_ROW1, INPUT);
	GPIO_voidSetPinDir(KPAD_ROW_PORT,KPAD_ROW2, INPUT);
	GPIO_voidSetPinDir(KPAD_ROW_PORT,KPAD_ROW3, INPUT);
	/* Configure the Pins of ROWS PULL UP */
	GPIO_voidSetPinVal(KPAD_ROW_PORT,KPAD_ROW0, HIGH );
	GPIO_voidSetPinVal(KPAD_ROW_PORT,KPAD_ROW1, HIGH );
	GPIO_voidSetPinVal(KPAD_ROW_PORT,KPAD_ROW2, HIGH );
	GPIO_voidSetPinVal(KPAD_ROW_PORT,KPAD_ROW3, HIGH );
	/* Set the Columns Pins as PUTPUT PINS */
	GPIO_voidSetPinDir(KPAD_COL_PORT,KPAD_COL0, OUTPUT);
	GPIO_voidSetPinDir(KPAD_COL_PORT,KPAD_COL1, OUTPUT);
	GPIO_voidSetPinDir(KPAD_COL_PORT,KPAD_COL2, OUTPUT);
	GPIO_voidSetPinDir(KPAD_COL_PORT,KPAD_COL3, OUTPUT);

	GPIO_voidSetPinVal(KPAD_COL_PORT,KPAD_COL0, HIGH );
	GPIO_voidSetPinVal(KPAD_COL_PORT,KPAD_COL1, HIGH );
	GPIO_voidSetPinVal(KPAD_COL_PORT,KPAD_COL2, HIGH );
	GPIO_voidSetPinVal(KPAD_COL_PORT,KPAD_COL3, HIGH );

}

u8 KEYPAD_voidGetPressedButton(void)
{
	u8 Loc_ColIterator = 0;
	u8 Loc_RowIterator = 0;
	u8 Loc_PressedValue = 0;
	u8 Loc_ReturnData = 0;
	for(Loc_ColIterator = (0+KPAD_COL_START); Loc_ColIterator<=KPAD_COL_END ; Loc_ColIterator++)
	{
		GPIO_voidSetPinVal(KPAD_COL_PORT, Loc_ColIterator, LOW);

		for(Loc_RowIterator = (0+KPAD_ROW_START); Loc_RowIterator<=KPAD_ROW_END ; Loc_RowIterator++)
		{
			Loc_PressedValue = GPIO_u8ReadPin( KPAD_ROW_PORT, Loc_RowIterator);
			if (Loc_PressedValue == 0)
			{
				_delay_ms(50);
				Loc_PressedValue = GPIO_u8ReadPin( KPAD_ROW_PORT,Loc_RowIterator);
				if (Loc_PressedValue == 0)
				{
					Loc_ReturnData=KEYPAD_Map[Loc_RowIterator - KPAD_ROW_START][Loc_ColIterator - KPAD_COL_START];
				}
				Loc_PressedValue = GPIO_u8ReadPin( KPAD_ROW_PORT,Loc_RowIterator);
				while(Loc_PressedValue == 0)
				{
					Loc_PressedValue = GPIO_u8ReadPin( KPAD_ROW_PORT,Loc_RowIterator);
				}
				break;
			}
		}
		GPIO_voidSetPinVal(KPAD_COL_PORT, Loc_ColIterator,HIGH);
	}
	return Loc_ReturnData;

}


