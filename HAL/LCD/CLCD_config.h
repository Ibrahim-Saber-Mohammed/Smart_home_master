/********************************************************************************************/
/* Author 		: Ibrahim Saber 												 			*/
/* Date 		: 9/11/2020 														 		*/
/* Version 		: V00 																		*/
/* SWC			: LCD 2*16															 		*/
/********************************************************************************************/

#ifndef HAL_CLCD_CONFIG_H_
#define HAL_CLCD_CONFIG_H_

/* Options :
 * 			GPIOA
 * 			GPIOB
 * 			GPIOC
 * 			GPIOD
 * 							 */
#define CLCD_DATA_PORT		GPIOA

/* Example
 * define CLCD_RS 			GPIOB, PIN7 */

#define CLCD_RS 			GPIOB, PIN0
#define CLCD_RW				GPIOB, PIN1
#define CLCD_EN				GPIOB, PIN2


#endif /* HAL_CLCD_CONFIG_H_ */
