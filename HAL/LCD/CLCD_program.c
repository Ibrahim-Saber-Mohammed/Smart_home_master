/********************************************************************************************/
/* Author 		: Ibrahim Saber 												 			*/
/* Date 		: 9/11/2020 														 		*/
/* Version 		: V00 																		*/
/* SWC			: LCD 2*16															 		*/
/********************************************************************************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "../../MCAL/DIO/GPIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"
#include "util/delay.h"


void CLCD_voidInit(void)
{
	GPIO_voidSetPortDir	(	CLCD_DATA_PORT	, 	0xFF	);
	GPIO_voidSetPinDir	(	CLCD_RW			,	OUTPUT	);
	GPIO_voidSetPinDir	(	CLCD_EN			,	OUTPUT	);
	GPIO_voidSetPinDir	(	CLCD_RS			,	OUTPUT	);
	_delay_ms(50);
	CLCD_voidSendCommand	( CLCD_EIGHT_BIT_TWO_LINE_5_8 );
	_delay_ms(1);
	CLCD_voidSendCommand	( CLCD_DISPLAY_ON_CURSOR_ON   );
	_delay_ms(1);
	CLCD_voidSendCommand	( CLCD_DISPLAY_CLEAR          );
	_delay_ms(2);
	CLCD_voidSendCommand	( CLCD_SHIFT_DISABEL          );

}

void CLCD_voidSendCommand	( u8 Copy_u8Command		)
{
	/*
	 * Send Command --> Write '0' to the RS Pin of LCD
	 * Writing to the LCD --> Write '0' to  RW Pin of the LCD
	 *   */
	GPIO_voidSetPortVal	(	CLCD_DATA_PORT	, Copy_u8Command	);
	GPIO_voidSetPinVal	(	CLCD_RS			, LOW				);
	GPIO_voidSetPinVal	(	CLCD_RW			, LOW				);

	/*Send Trigger to EN Pin*/
	CLCD_voidSendEnableTrigger();
}
void CLCD_voidSendCharacter	( u8 Copy_u8Char		)
{
	/*
	 * Send Data --> Write '1' to the RS Pin of LCD
	 * Writing to the LCD --> Write '0' to  RW Pin of the LCD
	 *  */
	GPIO_voidSetPortVal ( 	CLCD_DATA_PORT	, Copy_u8Char	);
	GPIO_voidSetPinVal 	( 	CLCD_RS       	, HIGH			);
	GPIO_voidSetPinVal 	( 	CLCD_RW			, LOW			);
	/*Send Trigger to EN Pin*/
	CLCD_voidSendEnableTrigger();
}
void CLCD_voidSendString	( u8 * Copy_ptrString	)
{
	u8 LOC_u8CharCounter = 0;
	while( Copy_ptrString[LOC_u8CharCounter] != '\0')
	{
		CLCD_voidSendCharacter(Copy_ptrString[LOC_u8CharCounter++]);
	}
}
void CLCD_voidSendNumber	( u64 Copy_u64Number	)
{
	u64 LOC_u64Reversed = 1;
	if(Copy_u64Number == 0)
	{
		CLCD_voidSendCharacter('0');
	}
	else
	{

		while(Copy_u64Number != 0)
		{
			LOC_u64Reversed = (LOC_u64Reversed*10) + (Copy_u64Number%10);
			Copy_u64Number/=10;
		}
		while(LOC_u64Reversed != 1)
		{
			CLCD_voidSendCharacter( ( LOC_u64Reversed%10) + 48 );
			LOC_u64Reversed/=10;
		}
	}
}

void CLCD_voidSendFloatNumber(f64 Copy_f32Number)
{
	// Cast the float Number to Integer value (ex: 25.6942325 --> 25)
	CLCD_voidSendNumber((u64)Copy_f32Number ); // Send the integer Number to the LCD
	CLCD_voidSendCharacter('.'); // Send the decimal point
	// Multiply the Float Number by 10^6 so the decimal number becomes part of the number
	//(ex: 25.6942325--> 25694232.5
	// save the result as integer"saved in u64" (ex: 25.6942325--> 25694232
	u64 Local_u64tempNumber = Copy_f32Number*1000000;
	// if the first digit is greater than or equal 5
	if( Local_u64tempNumber%10 >=5 )
	{
		// then divide the number by 10  (ex : 25694236 ---> 2569423 )
		// add 1 to the number to round the number up
		//then module the number by 100000  (ex : 2569423 ---> 69424 )
		CLCD_voidSendNumber((u64)((( Local_u64tempNumber/10)+1) % 100000));
	}
	else
	{
		// then divide the number by 10  (ex : 25694232 ---> 2569423)
		// then module the number by 100000  (ex : 25694232 ---> 69423
		// Display the number
		CLCD_voidSendNumber((u64)(( Local_u64tempNumber/10) % 100000)); // Function to send the integer number
	}

}
static void CLCD_voidSendEnableTrigger(void)
{
	GPIO_voidSetPinVal(CLCD_EN, HIGH);
	_delay_ms(1);
	GPIO_voidSetPinVal(CLCD_EN, LOW);
	_delay_ms(1);
}
void CLCD_voidGoToX_Y		( 	u8 Copy_u8Row , u8 Copy_u8Col 	)
{
	if( Copy_u8Row == CLCD_ROW1 )
	{
		CLCD_voidSendCommand(CLCD_SET_DDRAM_ADDRESS + ( Copy_u8Col - 1 ) );
	}
	else if( Copy_u8Row == CLCD_ROW2 )
	{
		CLCD_voidSendCommand(CLCD_SET_DDRAM_ADDRESS + 0x40 + ( Copy_u8Col - 1 ) );
	}
}
void CLCD_voidDrwaExxtraChar(	u8 Copy_u8Row ,u8 Copy_u8Col , u8 * Copy_u8ArrayChars)
{
	u8 LOC_u8Iterrator = 0;
	/* Go To CGRAM */
	CLCD_voidSendCommand ( CLCD_SET_CGRAM_ADDRESS );
	/* Draw The Character */
	for(LOC_u8Iterrator = 0; LOC_u8Iterrator< ( sizeof(Copy_u8ArrayChars)/sizeof(Copy_u8ArrayChars[0])); LOC_u8Iterrator++ )
	{
		CLCD_voidSendCharacter(Copy_u8ArrayChars[LOC_u8Iterrator]);
	}
	CLCD_voidGoToX_Y( Copy_u8Row, Copy_u8Col );
	for(LOC_u8Iterrator = 0; LOC_u8Iterrator< ( sizeof(Copy_u8ArrayChars)/sizeof(Copy_u8ArrayChars[0])); LOC_u8Iterrator++ )
	{
		CLCD_voidSendCharacter(Copy_u8ArrayChars[LOC_u8Iterrator]);
	}
}

void CLCD_voidClearScreen(void)
{
	CLCD_voidSendCommand(CLCD_DISPLAY_CLEAR);
	_delay_ms(2);
}
