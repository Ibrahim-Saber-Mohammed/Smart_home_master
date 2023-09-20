/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: ibrahim
 */
#include "../LIB/STD_TYPES/STD_TYPES.h"
#include "../LIB/BIT_MATH/BIT_MATH.h"
#include "../MCAL/DIO/GPIO_interface.h"
#include "../MCAL/EEPROM/EEPROM_interface.h"
#include "../MCAL/INTERRUPT/GIE_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"

#include "../HAL/KeyPad/KEYPAD_interface.h"
#include "../HAL/LCD/CLCD_interface.h"

#include <util/delay.h>
#include"Application.h"

extern u8 RemainSeconds;

int main(void)
{
	u8 Local_u8Menu = NO_MODE;
	u8 Local_u8FailedLogin = STD_OK ;
	u8 Local_u8LoopIterator = 0;
	u8 local_u8passwordFlag	= 0;
	u8 Local_u8Password_LCD_Position = 10;
	u8 Local_u8KeypadpressedValue = 0;
	u8 Local_arrEnteredpassword[PASS_LENGHTH] = {0};
	u8 local_arrSavedPassword[PASS_LENGHTH];
	u8 Local_u8passwordCheck = 0;
	u8 Local_u8NumberOfTries = 0;
	u8 Local_u8Temperature = 0;
	/*******************************************************************/
	CLCD_voidInit();
	CLCD_voidSendCommand(CLCD_DISPLAY_ON_CURSOR_OFF);
	KEYPAD_voidInit();

	TIM0_Config_t Timer0 ;
	Timer0.TIMER0_CLOCK_SELECT = TIM0_CLK_64;
	Timer0.TIMER0_Mode = TIMER0_CTC_MODE;
	Timer0.TIMER0_COMPARE_OUTPUT = OC0_DISCONNECTED;
	Timer0.TIMER_COMP_INTERRUPT = TIMER0_COMP_ENABLE_INTERRUPT;
	Timer0.COMP_CALLBACK = Timer0_CompareCallBack;
	TIM0_u8Set_CompareRegister_Value(250);
	GIE_voidEnable();
	TIM0_u8SetConfigurations( &Timer0 );
	/******************************************************************/
	 _delay_ms(30000);

	/* Checking the Password is set before or this is the firsst time using the program */
	EEPROM_voidReadByte(PASSWORD_FLAG_ADDRESS , &local_u8passwordFlag); // Read the password flag
	if( local_u8passwordFlag == PASSWORD_NOT_SET )
	{
		CLCD_voidClearScreen(); // Clear the Screen
		CLCD_voidGoToX_Y(CLCD_ROW1 , CLCD_COL1); // Set the Cursor to the Start of the LCD
		CLCD_voidSendString( (u8*)"Welcome to Smart" ); // Sending Welcome string
		CLCD_voidGoToX_Y(CLCD_ROW2 , CLCD_COL1); // Goto the next Line in the LCD
		CLCD_voidSendString( (u8*)"Home System" ); // Sending the rest of message
		_delay_ms(2000); // Wait 2 second showing the Message
		CLCD_voidClearScreen(); // Clear the screen
		CLCD_voidGoToX_Y(CLCD_ROW1 , CLCD_COL1); // Go to the first Position in the LCD
		CLCD_voidSendString( (u8*)"First time login" ); // Sending a message that the user should Set password for the system
		CLCD_voidGoToX_Y(CLCD_ROW2 , CLCD_COL1); // Go to the next line in the LCD
		CLCD_voidSendString( (u8*)"Set Password" );
		_delay_ms(1000); // Wait 1 second showing the Message
		CLCD_voidClearScreen(); // Clear the screen
		CLCD_voidGoToX_Y(CLCD_ROW1 , CLCD_COL1);
		CLCD_voidSendString( (u8*)"Password:" ); // Waiting from the user to Enter the Password to be set to this System

		for( Local_u8LoopIterator = 0; Local_u8LoopIterator < PASS_LENGHTH ; Local_u8LoopIterator++ )
		{
			do
			{
				Local_u8KeypadpressedValue = KEYPAD_voidGetPressedButton(); // Reading the keypad until the user press any Button
			}while(Local_u8KeypadpressedValue == NOT_PRESSED);

			Local_arrEnteredpassword[Local_u8LoopIterator] = Local_u8KeypadpressedValue; // Save the pressed value on the array
			CLCD_voidGoToX_Y(CLCD_ROW1, Local_u8Password_LCD_Position);  // Go to the First Digit position on the LCD
			CLCD_voidSendCharacter(Local_u8KeypadpressedValue); // Displaying the pressed button on the LCD for a while
			_delay_ms(200);
			CLCD_voidGoToX_Y(CLCD_ROW1 , Local_u8Password_LCD_Position);
			CLCD_voidSendCharacter('*'); // Displaying a * in the first Digit place
			Local_u8Password_LCD_Position++; // Increasing to points to the position of next digit on the LCD
			Local_u8KeypadpressedValue = 0;
		}
		CLCD_voidClearScreen(); // Clear Screen
		CLCD_voidGoToX_Y(CLCD_ROW1 , CLCD_COL1);
		CLCD_voidSendString((u8*)"Password Saved"); // Send Notification that the password has been Saved
		EEPROM_voidWriteBlock( BASE_ADDRESS_PASSWORD, PASS_LENGHTH , Local_arrEnteredpassword ); // Save the password in the memory
		EEPROM_voidWriteByte(PASSWORD_FLAG_ADDRESS , PASSWORD_SET); // Change the Password Flag to be Set
		_delay_ms(500);
		Local_u8KeypadpressedValue = 0; // return to initial value
		Local_u8Password_LCD_Position = 10; // return to the initial value
		/* Clear the array of Entered Password */
		APP_voidClearArray(Local_arrEnteredpassword, PASS_LENGHTH);

	}
	while(1)
	{

		while( Local_u8Menu == NO_MODE  )
		{
			if( Local_u8FailedLogin == STD_NOK) // The user Entered the Password Wrong and exceeded the number of tries
			{

				TIM0_Enable();  // Start Timer
				if( RemainSeconds == 0 ) // when the time becomes 0 then reset the number of tries and stop the timer
				{
					TIM0_Disable(); // Stop the Timer
					Local_u8FailedLogin = STD_OK; // reset the flag
					Local_u8NumberOfTries = 0; // reset the number of tries
					RemainSeconds = HALT_INIT_TIME  ; // reset the delay time for the next time

				}
				else
				{ // the user has to wait until the counts reaches 0

					CLCD_voidGoToX_Y(CLCD_ROW1 , CLCD_COL1); // Set the Cursor to the Start of the LCD
					CLCD_voidSendString((u8*)"No more Tries");
					CLCD_voidGoToX_Y(CLCD_ROW2 , CLCD_COL1); // Goto the next Line in the LCD
					CLCD_voidSendString( (u8*)"wait "); // Sending the rest of message
					CLCD_voidSendNumber(RemainSeconds);

					CLCD_voidSendString((u8*)" Seconds ");
				}

			}
			else
			{
				CLCD_voidClearScreen(); // Clear the Screen
				CLCD_voidGoToX_Y(CLCD_ROW1 , CLCD_COL1); // Set the Cursor to the Start of the LCD
				CLCD_voidSendString( (u8*)"Welcome to Smart" ); // Sending Welcome string
				CLCD_voidGoToX_Y(CLCD_ROW2 , CLCD_COL1); // Goto the next Line in the LCD
				CLCD_voidSendString( (u8*)"Home System" ); // Sending the rest of message
				_delay_ms(2000); // Wait 2 second showing the Message
				do
				{
					CLCD_voidClearScreen(); // Clear the screen
					CLCD_voidGoToX_Y(CLCD_ROW1 , CLCD_COL1); // Go to the first Position in the LCD
					CLCD_voidSendString( (u8*)"Enter Pass code" ); // Sending a message that the user should Set password for the system
					CLCD_voidGoToX_Y(CLCD_ROW2 , CLCD_COL1); // Go to the next line in the LCD
					CLCD_voidSendString( (u8*)"Password:" ); // Waiting from the user to Enter the Password to be set to this System

					for( Local_u8LoopIterator = 0; Local_u8LoopIterator < PASS_LENGHTH ; Local_u8LoopIterator++ )
					{
						do
						{
							Local_u8KeypadpressedValue = KEYPAD_voidGetPressedButton(); // Reading the keypad until the user press any Button
						}while(Local_u8KeypadpressedValue == NOT_PRESSED);

						Local_arrEnteredpassword[Local_u8LoopIterator] = Local_u8KeypadpressedValue; // Save the pressed value on the array
						CLCD_voidGoToX_Y(CLCD_ROW2, Local_u8Password_LCD_Position);  // Go to the First Digit position on the LCD
						CLCD_voidSendCharacter(Local_u8KeypadpressedValue); // Displaying the pressed button on the LCD for a while
						_delay_ms(200);
						CLCD_voidGoToX_Y(CLCD_ROW2 , Local_u8Password_LCD_Position);
						CLCD_voidSendCharacter('*'); // Displaying a * in the first Digit place
						Local_u8Password_LCD_Position++; // Increasing to points to the position of next digit on the LCD
						Local_u8KeypadpressedValue = 0;
					}
					EEPROM_voidReadBlock(BASE_ADDRESS_PASSWORD , PASS_LENGHTH,local_arrSavedPassword); // Read the Saved Password in the memory
					Local_u8passwordCheck = Login_u8CheckPassword(local_arrSavedPassword , Local_arrEnteredpassword , PASS_LENGHTH);

					if(Local_u8passwordCheck == PASSWORD_CORRECT) // Checking if the password is correct or not
					{
						CLCD_voidClearScreen(); // Clear the screen
						CLCD_voidGoToX_Y(CLCD_ROW1 ,  CLCD_COL1); // going to the first position in the LCD
						CLCD_voidSendString((u8*)"Password Correct"); // Displaying a message that the password is correct
						CLCD_voidGoToX_Y(CLCD_ROW2 , CLCD_COL1);
						CLCD_voidSendString((u8*)"Welcome.."); // Welcoming the user

						Local_u8Menu = MAIN_WINDOW;  // Set the Mode to the main Window of the System

						APP_voidClearArray(Local_arrEnteredpassword , PASS_LENGHTH); // Clear the array and return to the initial state
						Local_u8KeypadpressedValue = NOT_PRESSED;     // reset the variable to the initial value
						Local_u8Password_LCD_Position = 10; // reset the variable to the initial value
						_delay_ms(1000); // halt the processor for 1 second
						break; // break the loop as the password is correct
					}
					else if (Local_u8passwordCheck == PASSWORD_INCORRECT )
					{
						Local_u8NumberOfTries++; // the password is wrong so decrement the remaining number of tries
						if( (Local_u8NumberOfTries <= MAX_NUMBER_TRIES-2) )
						{
							CLCD_voidClearScreen();
							CLCD_voidGoToX_Y(CLCD_ROW1 , CLCD_COL1);
							CLCD_voidSendString((u8*)"Wrong Password"); // Displaying a message that password is wrong
							CLCD_voidGoToX_Y(CLCD_ROW2 , CLCD_COL1);
							CLCD_voidSendString((u8*)"Please Try again"); // Displaying a message to let him try again
						}
						Local_u8Menu = NO_MODE;
						APP_voidClearArray(Local_arrEnteredpassword , PASS_LENGHTH);
						Local_u8KeypadpressedValue = NOT_PRESSED; // reset the variable to the initial value
						Local_u8Password_LCD_Position = 10; // reset the variable to the initial value
						_delay_ms(500); // halt the processor for 0.5 second
					}
				}while(Local_u8NumberOfTries <MAX_NUMBER_TRIES); // end the loop is the user exceeds the number of tries

				if( Local_u8Menu == NO_MODE)
				{
					Local_u8FailedLogin = STD_NOK;
					CLCD_voidClearScreen(); // Clear the Screen
				}
			}
		}
		/***********************************************************************************/
		switch( Local_u8Menu   )
		{
		case MAIN_WINDOW:
			/*
			 * Main Window : has the first 3 rooms and the more Option
			 * it just read the user choice and save it in Local_u8menu to display the choice equivalent Menu
			 * */
			CLCD_voidClearScreen(); // Clear the Screen
			do {
				CLCD_voidGoToX_Y(CLCD_ROW1 , CLCD_COL1); // Go to the start of the LCD
				CLCD_voidSendString((u8*)"1:Room1  2:Room2"); // Displaying the Options
				CLCD_voidGoToX_Y(CLCD_ROW2 , CLCD_COL1);
				CLCD_voidSendString((u8*)"3:Room3  4:More"); // Displaying the remaining Options
				Local_u8KeypadpressedValue = KEYPAD_voidGetPressedButton(); // Read from the KeyPad
				/* do not break the loop until the user Enters accepted choice  */
			}while(Local_u8KeypadpressedValue < ROOM1_WINDOW || Local_u8KeypadpressedValue>MORE_MENU);

			if( Local_u8KeypadpressedValue == ROOM1_WINDOW )
			{
				Local_u8Menu = ROOM1_WINDOW; // Save the user choice . when while (1) repeat the code it will show the Room1 Menu
			}
			else if( Local_u8KeypadpressedValue == ROOM2_WINDOW )
			{
				Local_u8Menu = ROOM2_WINDOW; // Save the user choice . when while (1) repeat the code it will show the Room2 Menu
			}
			else if( Local_u8KeypadpressedValue == ROOM3_WINDOW )
			{
				Local_u8Menu = ROOM3_WINDOW; // Save the user choice . when while (1) repeat the code it will show the Room3 Menu
			}
			else if( Local_u8KeypadpressedValue == MORE_MENU )
			{
				Local_u8Menu = MORE_MENU;// Save the user choice . when while (1) repeat the code it will show the More Menu
			}

			break;
		case MORE_MENU :
			CLCD_voidClearScreen(); // The user has Chosen from the main Window to Display the More menu
			/*
			 * The more Window Displays the options Room4 , TV, AIR Conditioner and return to Main Window
			 * */
			do
			{
				CLCD_voidGoToX_Y(CLCD_ROW1 , CLCD_COL1); // return to the beginning of the LCD
				CLCD_voidSendString((u8*)"1:Room4  2:TV"); // Displaying the Options of the More Window
				CLCD_voidGoToX_Y(CLCD_ROW2 , CLCD_COL1); // Go to the Next Line in the LCD
				CLCD_voidSendString((u8*)"3:AIR_COND 4:RET"); //Displaying the Options of the More Window

				Local_u8KeypadpressedValue = KEYPAD_voidGetPressedButton(); // read the Pressed value from the KeyPad

				/* Repeat the Loop until the user press a valid option */
			}while(Local_u8KeypadpressedValue < ROOM4_WINDOW || Local_u8KeypadpressedValue>RET);

			if(Local_u8KeypadpressedValue == ROOM4_WINDOW) // the user wants to display the Room4 options menu
			{
				Local_u8Menu = ROOM4_WINDOW_SEL; // Save the user choice . when while (1) repeat the code it will show the Room4 Menu
			}
			else if(Local_u8KeypadpressedValue == TV_WINDOW) // the user wants to display the TV options menu
			{
				Local_u8Menu = TV_WINDOW_SEL;// Save the user choice . when while (1) repeat the code it will show the TV Menu
			}
			else if(Local_u8KeypadpressedValue == RET) // the user wants to return to the main menu
			{
				Local_u8Menu = MAIN_WINDOW; // Save the user choice . when while (1) repeat the code it will return to main Menu
			}
			else if(Local_u8KeypadpressedValue == COND_WINDOW) // the user wants to display the Air Conditioner options menu
			{
				Local_u8Menu = COND_WINDOW_SEL; // Save the user choice . when while (1) repeat the code it will show the Air Conditioner Menu
			}
			break;

		case COND_WINDOW_SEL : // The user Entered the option to Display the Air conditioner menu
			CLCD_voidClearScreen(); // Clear screen
			do{

				CLCD_voidGoToX_Y(CLCD_ROW1 , CLCD_COL1);
				CLCD_voidSendString((u8*)"1:Set Temperature");
				CLCD_voidGoToX_Y(CLCD_ROW2 , CLCD_COL1);
				CLCD_voidSendString((u8*)"2:AIR_COND Ctrl");
				Local_u8KeypadpressedValue =KEYPAD_voidGetPressedButton();
			}while(Local_u8KeypadpressedValue < SET_TEMPERATURE || Local_u8KeypadpressedValue > CONTROL_AIR_COND);

			if(Local_u8KeypadpressedValue == SET_TEMPERATURE)
			{
				Local_u8Menu = SET_TEMPERATURE_SEL;
			}
			else if(Local_u8KeypadpressedValue == CONTROL_AIR_COND)
			{
				Local_u8Menu = CONTROL_AIR_COND_SEL;
			}
			break;

		case ROOM1_WINDOW :
			APP_voidDisplayMenu(Local_u8Menu);
			Local_u8Menu = MAIN_WINDOW;
			break;
		case ROOM2_WINDOW:
			APP_voidDisplayMenu(Local_u8Menu);
			Local_u8Menu = MAIN_WINDOW;
			break;
		case ROOM3_WINDOW :
			APP_voidDisplayMenu(Local_u8Menu);
			Local_u8Menu = MAIN_WINDOW;
			break;
		case ROOM4_WINDOW_SEL:
			APP_voidDisplayMenu(Local_u8Menu);
			Local_u8Menu = MORE_MENU;
			break;
		case TV_WINDOW_SEL:
			APP_voidDisplayMenu(Local_u8Menu);
			Local_u8Menu = MORE_MENU;
			break;
		case SET_TEMPERATURE_SEL :
			Local_u8Temperature = 0;
			CLCD_voidClearScreen();
			CLCD_voidSendString((u8*)"Set Tepm:__");
			CLCD_voidSendCharacter(DEGREES_SYMBOL);
			CLCD_voidSendCharacter('C');
			Local_u8KeypadpressedValue =NOT_PRESSED;
			Local_u8LoopIterator = 0;
			CLCD_voidGoToX_Y(CLCD_ROW1 , CLCD_COL10 );
			do
			{
				Local_u8KeypadpressedValue = KEYPAD_voidGetPressedButton();

			}while(Local_u8KeypadpressedValue <'1' || Local_u8KeypadpressedValue > '9');
			CLCD_voidSendCharacter(Local_u8KeypadpressedValue);
			Local_u8Temperature = Local_u8Temperature*10 + (Local_u8KeypadpressedValue - '0');
			Local_u8KeypadpressedValue = NOT_PRESSED;
			do
			{
				Local_u8KeypadpressedValue = KEYPAD_voidGetPressedButton();

			}while(Local_u8KeypadpressedValue <'1' || Local_u8KeypadpressedValue > '9');
			CLCD_voidSendCharacter(Local_u8KeypadpressedValue);
			Local_u8Temperature = Local_u8Temperature*10 + (Local_u8KeypadpressedValue - '0');
			Local_u8KeypadpressedValue = NOT_PRESSED;
			_delay_ms(500);
			CLCD_voidClearScreen();
			CLCD_voidSendString((u8*)"Temperature sent");
			_delay_ms(500);
			Local_u8Menu = COND_WINDOW_SEL;
			/* SPI code to send Temperature */
			break;
		case CONTROL_AIR_COND_SEL :
			APP_voidDisplayMenu(Local_u8Menu);
			Local_u8Menu = COND_WINDOW_SEL;
		}
	}
	return 0;
}
