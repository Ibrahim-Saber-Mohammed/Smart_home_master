/*
 * Application.h
 *
 *  Created on: Aug 30, 2021
 *      Author: ibrahim
 */

#ifndef APPLICATION_APPLICATION_H_
#define APPLICATION_APPLICATION_H_

#define PASS_LENGHTH				(u8)4
#define BASE_ADDRESS_PASSWORD		(u8)100
#define PASSWORD_FLAG_ADDRESS		(u8)105
#define PASSWORD_NOT_SET			(u8)0xFF
#define PASSWORD_SET				(u8)0
#define NOT_PRESSED					(u8)0
#define PASSWORD_CORRECT			(u8)0xFF
#define PASSWORD_INCORRECT			(u8)0x0F
#define MAX_NUMBER_TRIES			(u8)4
/**************************************************************/
#define LOGIN_LED					GPIOD, PIN0, OUTPUT
#define DEGREES_SYMBOL		        (u8)0xDF
/**************************************************************/

#define NO_MODE						0
#define MAIN_WINDOW					(u8)'0'
#define ROOM1_WINDOW				(u8)'1'
#define ROOM2_WINDOW				(u8)'2'
#define ROOM3_WINDOW				(u8)'3'
#define MORE_MENU					(u8)'4'
#define ROOM4_WINDOW				(u8)'1'
#define COND_WINDOW					(u8)'3'
#define TV_WINDOW					(u8)'2'
#define RET							(u8)'4'
#define SET_TEMPERATURE				(u8)'1'
#define CONTROL_AIR_COND			(u8)'2'

#define ROOM4_WINDOW_SEL			(u8)'5'
#define COND_WINDOW_SEL				(u8)'6'
#define TV_WINDOW_SEL				(u8)'7'
#define RET_SEL						(u8)'8'

#define SET_TEMPERATURE_SEL			(u8)'9'
#define CONTROL_AIR_COND_SEL		(u8)'A'
#define HALT_INIT_TIME				20
/***************************************************************/

void Timer0_CompareCallBack (void);
u8 Login_u8CheckPassword( u8 * Copy_ptrSavedPassword , u8 * copy_ptrEnteredPassword, u8 Copy_u8Passwordlength );
void APP_voidClearArray(u8 * Copy_ptrArrayAddress , u8 Copy_u8ArraySize);
void APP_voidDisplayMenu(u8 Copy_u8MinuNumber);

#endif /* APPLICATION_APPLICATION_H_ */
