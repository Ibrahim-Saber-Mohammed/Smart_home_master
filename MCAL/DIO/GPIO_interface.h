/********************************************************************************************/
/* Author 		: Ibrahim Saber 												 			*/
/* Date 		: 9/11/2020 														 		*/
/* Version 		: V00 																 		*/
/********************************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/********************************************************************************************************/
/* THis function is used to set the direction of a specific pin to be either (OUTPUT,INPUT)				*/
/* The function takes parameters (PORT number and PIN Number , The direction of the pin)				*/
/* Tested																								*/
/********************************************************************************************************/
void GPIO_voidSetPinDir(u8 Copy_u8PortNum  , u8 Copy_u8PinNum, u8 Copy_u8Direction);

/********************************************************************************************************/
/* THis function is used to set the Value of a specific pin to be either (HIGH,LOW)			      		*/
/* The function takes parameters (PORT number and PIN Number , The value of the pin)			      	*/
/* Tested																		           				*/
/********************************************************************************************************/
void GPIO_voidSetPinVal(u8 Copy_u8PortNum  , u8 Copy_u8PinNum, u8 Copy_u8Value);


/********************************************************************************************************/
/* THis function is used to Toggle the current value of a specific pin 									*/
/* The function takes parameters (PORT number and PIN Number )											*/
/* Tested																								*/
/********************************************************************************************************/
void GPIO_voidTogglePin(u8 Copy_u8PortNum  , u8 Copy_u8PinNum);


/**********************************************************************************************************/
/* THis function is used to set the direction of a specific PORT to be either (OUTPUT,INPUT,value)	      */
/* If the the direction of all the port's pins is not the same then the function set the direction with   */ 
/* the value of the direction parameter													         		  */
/* The function takes parameters (PORT number and PIN Number , The direction of the pins)			      */
/* Tested																			      				  */
/**********************************************************************************************************/
void GPIO_voidSetPortDir(u8 Copy_u8PortNum , u8 Copy_u8Direction);

/************************************************************************************************************/
/* THis function is used to set the value of a specific PORT 							              		*/
/* the function set the value with the value of the Copy_u8Value parameter									*/											     
/* The function takes parameters (PORT number and PIN Number , The value of the pins)			          	*/
/* Tested																			      	 				*/
/************************************************************************************************************/
void GPIO_voidSetPortVal(u8 Copy_u8PortNum , u8 Copy_u8Value);

/************************************************************************************************************/
/* THis function is used to toggle the value of a specific PORT 						              		*/
/* the function toggle the value of the port      												     		*/
/* The function takes parameters (PORT number and PIN Number , The value of the pins)			          	*/
/* Tested																			      	 				*/
/************************************************************************************************************/
void GPIO_voidTogglePort(u8 Copy_u8PortNum);

void GPIO_voidSet_LOW_NibbleDir(u8 Copy_u8PortNum, u8 Copy_u8Dir);

void GPIO_voidSet_HIGH_NibbleDir(u8 Copy_u8PortNum, u8 Copy_u8Dir);

void GPIO_voidSet_LOW_NibbleVal(u8 Copy_u8portnum, u8 Copy_u8value);

void GPIO_voidSet_HIGH_NibbleVal(u8 Copy_u8portnum, u8 Copy_u8value);

u8 GPIO_u8ReadPin(u8 Copy_u8PortNum, u8 Copy_u8PinNum);

u8 GPIO_u8ReadPort(u8 Copy_u8PortNum);



/* PORTS NUMBERS */
#define GPIOA    	0
#define GPIOB 		1
#define GPIOC 		2
#define GPIOD 		3

/* OUTPUT STATES */
#define HIGH		1
#define LOW 		0

/* PINS DIRECTIONS */
#define INPUT		0
#define OUTPUT 		1

/* PINS NUMBERS */
#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7


#endif