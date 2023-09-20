/*
 * KEYPAD_config.h
 *
 *  Created on: Jun 27, 2021
 *      Author: ibrahim
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_


#define KPAD_ROW_START		PIN0
#define KPAD_ROW_END		PIN3

#define KPAD_COL_START		PIN4
#define KPAD_COL_END		PIN7

/*
 * Example :
 * #define KPAD_ROW0   PIN0
 * */
/*
 * KPAD_ROW_PORT Options :
 * 	GPIOA
 * 	GPIOB,
 * 	GPIOC,
 * 	GPIOD
 * 	*/
#define KPAD_ROW_PORT	GPIOD
#define KPAD_ROW0 	 	PIN0
#define KPAD_ROW1	 	PIN1
#define KPAD_ROW2	 	PIN2
#define KPAD_ROW3	 	PIN3

/*
 * Example :
 * #define KPAD_ROW0   PIN0
 * */
/*
 * KPAD_ROW_PORT Options :
 * 	GPIOA
 * 	GPIOB,
 * 	GPIOC,
 * 	GPIOD
 * 	*/
#define KPAD_COL_PORT	GPIOD
#define KPAD_COL0	 	PIN4
#define KPAD_COL1	 	PIN5
#define KPAD_COL2	 	PIN6
#define KPAD_COL3	 	PIN7

u8 KEYPAD_Map[4][4]= {	/*Col0  Col1	Col2	Col3*/
		{'7',	'8', 	'9', 	'A'}, /*Row0*/
		{'4', 	'5', 	'6', 	'B'}, /*Row1*/
		{'1', 	'2', 	'3', 	'C'}, /*Row2*/
		{'E', 	'0', 	'C', 	'D'}  /*Row3*/
};


#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
