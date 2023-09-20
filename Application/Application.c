/*
 * Application.c
 *
 *  Created on: Aug 30, 2021
 *      Author: ibrahim
 */

#include "../LIB/STD_TYPES/STD_TYPES.h"
#include "../LIB/BIT_MATH/BIT_MATH.h"
#include "../HAL/LCD/CLCD_interface.h"

#include "Application.h"


volatile u16 CompareMatchCounts = 0;
volatile u8 RemainSeconds = HALT_INIT_TIME;
void Timer0_CompareCallBack (void)
{
	CompareMatchCounts++;
	if( CompareMatchCounts == 499 )
	{
		RemainSeconds--;
		CompareMatchCounts = 0;
	}
}


u8 Login_u8CheckPassword( u8 * Copy_ptrSavedPassword , u8 * copy_ptrEnteredPassword, u8 Copy_u8Passwordlength )
{
	u8 Local_u8ErrorState = STD_OK;
	u8 Local_u8LoopIterator= 0;
	if( (Copy_ptrSavedPassword == NULL) || (copy_ptrEnteredPassword == NULL) )
	{
		Local_u8ErrorState = STD_NOK;
	}
	else
	{
		for( Local_u8LoopIterator = 0; Local_u8LoopIterator < Copy_u8Passwordlength ; Local_u8LoopIterator++ )
		{
			if( copy_ptrEnteredPassword[Local_u8LoopIterator] != Copy_ptrSavedPassword[Local_u8LoopIterator] )
			{
				Local_u8ErrorState = PASSWORD_INCORRECT;
				break;
			}
			else
			{
				Local_u8ErrorState = PASSWORD_CORRECT;
			}
		}
	}
	return Local_u8ErrorState;
}

void APP_voidClearArray(u8 * Copy_ptrArrayAddress , u8 Copy_u8ArraySize)
{
	u8 Local_u8LoopIterator = 0;
	for( Local_u8LoopIterator = 0; Local_u8LoopIterator < Copy_u8ArraySize; Local_u8LoopIterator++ )
	{
		*(Copy_ptrArrayAddress + Local_u8LoopIterator) = 0;
	}
}

void APP_voidDisplayMenu(u8 Copy_u8MinuNumber)
{
	CLCD_voidClearScreen();
	switch(Copy_u8MinuNumber)
	{
	case ROOM1_WINDOW :

		break;
	case ROOM2_WINDOW :

		break;
	case ROOM3_WINDOW :

		break;
	case ROOM4_WINDOW_SEL:

		break;

	}

}



