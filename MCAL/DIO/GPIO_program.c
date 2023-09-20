/****************************************************************************************/
/** @author 	: Ibrahim Saber 												 		*/
/** @brief		: This file contains the functions implementation of the GPIO Drivers   */ 
/** @file       : GPIO_program.c													    */	
/** Date 		: 9/11/2020 													 		*/
/* Version 		: V00 														 			*/
/****************************************************************************************/

#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

/*------------------------------------------------------------------------------------------------------------------*/
/**  @brief  							GPIO_voidSetPinDir 																    */
/**		    1- comparing the input Port Number With these in the AVR (PORTA,PORTB,PORTC,PORTD)  					*/
/** 		in case of PORTA : the register is DDRA  and so on to all ports 										*/
/**	 	    2-Check the given direction input or output 															*/
/** 		3-In case INPUT :write 0 to the pin-num in DDRxn to make it input 										*/
/** 		4- In case OUTPUT :write 1 to the pin-num in DDRxn to make it input 									*/
/** 		The default if the direction was any thing other input or output it returns an error and break 			*/
/** 		The default if the port num was any thing other (GPIOA,GPIOB,GPIOC,GPIOD) it returns an error and break;*/
/**			*@param[in]	u8 Copy_u8PortNum { GPIOA, GPIOB , GPIOC, GPIOD }											*/											
/**         *@param[in]	u8 Copy_u8PinNum  { 0 to 7  }																*/
/**         *@param[in]	u8 Copy_u8Direction { INPUT , OUTPUT }														*/
/**         *@param[out] void																						*/
/*-----------------------------------------------------------------------------------------------------------------	*/
void GPIO_voidSetPinDir(u8 Copy_u8PortNum ,u8 Copy_u8PinNum, u8 Copy_u8Direction)
{
	
	switch(Copy_u8PortNum)
	{
		
		case GPIOA :
			switch (Copy_u8Direction)  
			{
				
				case INPUT  : CLR_BIT(DDRA,Copy_u8PinNum);  break;  
				case OUTPUT : SET_BIT(DDRA,Copy_u8PinNum);  break;
				default     : /* return Error invalid option */ break;
			}
			break;
		case GPIOB :
			switch (Copy_u8Direction)
			{
				case INPUT  : CLR_BIT(DDRB,Copy_u8PinNum); break;
				case OUTPUT : SET_BIT(DDRB,Copy_u8PinNum); break;
				default     : /* return Error */ break;
			}
			break;
		case GPIOC :
			switch (Copy_u8Direction)
			{
				case INPUT  : CLR_BIT(DDRC,Copy_u8PinNum); break;
				case OUTPUT : SET_BIT(DDRC,Copy_u8PinNum); break;
				default     : /* return Error */ break;
			}
			break;
		case GPIOD :
			switch (Copy_u8Direction)
			{
				case INPUT  : CLR_BIT(DDRD,Copy_u8PinNum); break;
				case OUTPUT : SET_BIT(DDRD,Copy_u8PinNum); break;
				default     : /* return Error */ break;
			}
			break;
			
		default : /* return Error */ break;
	}
	
}
/*------------------------------------------------------------------------------------------------------------------*/
/*    							GPIO_voidSetPinVal 																	*/
/*		1- comparing the input Port Number With these in the AVR (PORTA,PORTB,PORTC,PORTD)     						*/
/* 		in case of PORTA : the register is PORTA  and so on to all ports 											*/
/*	 	2-Check the given value HIGH or LOW 																		*/
/* 		3-In case LOW :write 0 to the corresponding pin num in PORTxn to make it input 								*/
/* 		4- In case HIGH :write 1 to the corresponding pin num in PORTxn to make it input 							*/
/* 		The default if the direction was any thing other input or output it returns an error and break 				*/
/* 		The default if the port num was any thing other (GPIOA,GPIOB,GPIOC,GPIOD) it returns an error and break  	*/
/*------------------------------------------------------------------------------------------------------------------*/
void GPIO_voidSetPinVal(u8 Copy_u8PortNum ,u8 Copy_u8PinNum, u8 Copy_u8Value)
{
	switch(Copy_u8PortNum)
	{
		case GPIOA :
			switch (Copy_u8Value)
			{
				case LOW  : CLR_BIT(PORTA,Copy_u8PinNum); break;
				case HIGH : SET_BIT(PORTA,Copy_u8PinNum); break;
				default     : /* return Error */ break;
			}
			break;
		case GPIOB :
			switch (Copy_u8Value)
			{
				case LOW  : CLR_BIT(PORTB,Copy_u8PinNum); break;
				case HIGH : SET_BIT(PORTB,Copy_u8PinNum); break;
				default     : /* return Error */ break;
			}
			break;
		case GPIOC :
			switch (Copy_u8Value)
			{
				case LOW  : CLR_BIT(PORTC,Copy_u8PinNum); break;
				case HIGH : SET_BIT(PORTC,Copy_u8PinNum); break;
				default     : /* return Error */ break;
			}
			break;
		case GPIOD :
			switch (Copy_u8Value)
			{
				case LOW  : CLR_BIT(PORTD,Copy_u8PinNum); break;
				case HIGH : SET_BIT(PORTD,Copy_u8PinNum); break;
				default     : /* return Error */ break;
			}
			break;
			
		default : /* return Error */ break;
	}
	
}

/*------------------------------------------------------------------------------------------------------------------*/
/*    							GPIO_voidTogglePin 																	*/
/*		1- comparing the input Port Number With these in the AVR (PORTA,PORTB,PORTC,PORTD)     						*/
/* 		in case of PORTA : the register is PORTA  and so on to all ports 											*/
/*	 	then toggle the value of the given pin (Copy_u8PinNum)														*/
/* 		The default if the port num was any thing other (GPIOA,GPIOB,GPIOC,GPIOD) it returns an error and break  	*/
/*------------------------------------------------------------------------------------------------------------------*/
void GPIO_voidTogglePin(u8 Copy_u8PortNum  , u8 Copy_u8PinNum)
{
	switch(Copy_u8PortNum)
	{
		case GPIOA : TOGGLE_BIT(PORTA,Copy_u8PinNum); break;
		case GPIOB : TOGGLE_BIT(PORTB,Copy_u8PinNum); break;
		case GPIOC : TOGGLE_BIT(PORTC,Copy_u8PinNum); break;
		case GPIOD : TOGGLE_BIT(PORTD,Copy_u8PinNum); break;
		default : /* return Error */ break;
	}
}

/*------------------------------------------------------------------------------------------------------------------*/
/*    							GPIO_voidSetPortDir 																*/
/*		1- comparing the input Port Number With these in the AVR (PORTA,PORTB,PORTC,PORTD)     						*/
/* 		in case of PORTA : the register is DDRA  and so on to all ports 											*/
/*	 	2-Check the given value HIGH or LOW 																		*/
/* 		 write the given value to the port																			*/
/* 		The default if the port num was any thing other (GPIOA,GPIOB,GPIOC,GPIOD) it returns an error and break  	*/
/*------------------------------------------------------------------------------------------------------------------*/
void GPIO_voidSetPortDir(u8 Copy_u8PortNum , u8 Copy_u8Direction)
{
	switch(Copy_u8PortNum)
	{
		case GPIOA :  DDRA = Copy_u8Direction;   break;
		case GPIOB :  DDRB = Copy_u8Direction;   break;
		case GPIOC :  DDRC = Copy_u8Direction;   break;
		case GPIOD :  DDRD = Copy_u8Direction;   break;
		
		default : /* return Error */ break;
	}
}

/*------------------------------------------------------------------------------------------------------------------*/
/*    							GPIO_voidSetPortVal 																*/
/*		1- comparing the input Port Number With these in the AVR (PORTA,PORTB,PORTC,PORTD)     						*/
/* 		in case of PORTA : the register is PORTA  and so on to all ports 											*/
/*       2- then Write the Passed value (Copy_u8Value) on the PORTx 												*/
/* 		The default if the port num was any thing other (GPIOA,GPIOB,GPIOC,GPIOD) it returns an error and break  	*/
/*------------------------------------------------------------------------------------------------------------------*/
void GPIO_voidSetPortVal(u8 Copy_u8PortNum , u8 Copy_u8Value)
{
	switch(Copy_u8PortNum)
	{
		case GPIOA : PORTA = Copy_u8Value;        break;
		case GPIOB : PORTB = Copy_u8Value;        break;
		case GPIOC : PORTC = Copy_u8Value;        break;
		case GPIOD : PORTD = Copy_u8Value;        break;
		default : /* return Error */ break;
	}
}
/*------------------------------------------------------------------------------------------------------------------*/
/*    							GPIO_voidTogglePort 																*/
/*		1- comparing the input Port Number With these in the AVR (PORTA,PORTB,PORTC,PORTD)     						*/
/* 		in case of PORTA : the register is PORTA  and so on to all ports 											*/
/*	 	then toggle the value of the given prrt num (u8 Copy_u8PortNum)												*/
/* 		The default if the port num was any thing other (GPIOA,GPIOB,GPIOC,GPIOD) it returns an error and break  	*/
/*------------------------------------------------------------------------------------------------------------------*/
void GPIO_voidTogglePort(u8 Copy_u8PortNum)
{
	switch(Copy_u8PortNum)
	{
		case GPIOA : PORTA = ~PORTA ; break;
		case GPIOB : PORTB = ~PORTB ; break;
		case GPIOC : PORTC = ~PORTC ; break;
		case GPIOD : PORTD = ~PORTD ; break;
		default : /* Return Error */  break;
	}
}
u8 GPIO_u8ReadPin(u8 Copy_u8PortNum, u8 Copy_u8PinNum)
{
	u8 LocalResult ;
	switch(Copy_u8PortNum)
	{
		case GPIOA : LocalResult = GET_BIT(PINA,Copy_u8PinNum);  break;
		case GPIOB : LocalResult = GET_BIT(PINB,Copy_u8PinNum);  break;
		case GPIOC : LocalResult = GET_BIT(PINC,Copy_u8PinNum);  break;
		case GPIOD : LocalResult = GET_BIT(PIND,Copy_u8PinNum);  break;
		default : /* Return Error */                             break;
	}
	
	return LocalResult;
}

u8 GPIO_u8ReadPort(u8 Copy_u8PortNum)
{
	u8 LocalResult;
	switch(Copy_u8PortNum)
	{
		case GPIOA : LocalResult = PINA; break;
		case GPIOB : LocalResult = PINB; break;
		case GPIOC : LocalResult = PINC; break;
		case GPIOD : LocalResult = PIND; break;
		default : /* Return Error */ break;
	}
	return LocalResult;
}

void GPIO_voidSet_LOW_NibbleDir(u8 Copy_u8PortNum, u8 Copy_u8Dir)
{
	switch(Copy_u8PortNum)
	{
		case GPIOA : 
			switch(Copy_u8Dir)
			{
				case INPUT  : GPIO_voidSetPinDir(GPIOA,PIN0,INPUT);
							  GPIO_voidSetPinDir(GPIOA,PIN1,INPUT);
							  GPIO_voidSetPinDir(GPIOA,PIN2,INPUT);
							  GPIO_voidSetPinDir(GPIOA,PIN3,INPUT);
							  break;
							  
				case OUTPUT : GPIO_voidSetPinDir(GPIOA,PIN0,OUTPUT);
							  GPIO_voidSetPinDir(GPIOA,PIN1,OUTPUT);
							  GPIO_voidSetPinDir(GPIOA,PIN2,OUTPUT);
							  GPIO_voidSetPinDir(GPIOA,PIN3,OUTPUT);
							  break;
				default: /* return error */ break;
			}				
				break;
		case GPIOB :
			switch(Copy_u8Dir)
			{
				case INPUT  : GPIO_voidSetPinDir(GPIOB,PIN0,INPUT);
							  GPIO_voidSetPinDir(GPIOB,PIN1,INPUT);
							  GPIO_voidSetPinDir(GPIOB,PIN2,INPUT);
							  GPIO_voidSetPinDir(GPIOB,PIN3,INPUT);
							  break;
				
				case OUTPUT : GPIO_voidSetPinDir(GPIOB,PIN0,OUTPUT);
							  GPIO_voidSetPinDir(GPIOB,PIN1,OUTPUT);
							  GPIO_voidSetPinDir(GPIOB,PIN2,OUTPUT);
							  GPIO_voidSetPinDir(GPIOB,PIN3,OUTPUT);
							  break;
				default: /* return Error */ break;
			}
			break;
			 
		case GPIOC :
			switch(Copy_u8Dir)
			{
				case INPUT  : GPIO_voidSetPinDir(GPIOC,PIN0,INPUT);
							  GPIO_voidSetPinDir(GPIOC,PIN1,INPUT);
							  GPIO_voidSetPinDir(GPIOC,PIN2,INPUT);
							  GPIO_voidSetPinDir(GPIOC,PIN3,INPUT);
							  break;
				
				case OUTPUT : GPIO_voidSetPinDir(GPIOC,PIN0,OUTPUT);
							  GPIO_voidSetPinDir(GPIOC,PIN1,OUTPUT);
							  GPIO_voidSetPinDir(GPIOC,PIN2,OUTPUT);
							  GPIO_voidSetPinDir(GPIOC,PIN3,OUTPUT);
							  break;
				default: /* return Error */ break;
			}
		break;
		
		case GPIOD :
			switch(Copy_u8Dir)
			{
				case INPUT  : GPIO_voidSetPinDir(GPIOD,PIN0,INPUT);
							  GPIO_voidSetPinDir(GPIOD,PIN1,INPUT);
							  GPIO_voidSetPinDir(GPIOD,PIN2,INPUT);
							  GPIO_voidSetPinDir(GPIOD,PIN3,INPUT);
							  break;
				
				case OUTPUT : GPIO_voidSetPinDir(GPIOD,PIN0,OUTPUT);
							  GPIO_voidSetPinDir(GPIOD,PIN1,OUTPUT);
							  GPIO_voidSetPinDir(GPIOD,PIN2,OUTPUT);
							  GPIO_voidSetPinDir(GPIOD,PIN3,OUTPUT);
							  break;
				default: /* return Error */ break;
			}
		break;
		default: /* return error */ break;
		
	}
}

void GPIO_voidSet_HIGH_NibbleDir(u8 Copy_u8PortNum, u8 Copy_u8Dir)
{
	switch(Copy_u8PortNum)
	{
		case GPIOA :
			switch(Copy_u8Dir)
			{
				case INPUT  : GPIO_voidSetPinDir(GPIOA,PIN4,INPUT);
							  GPIO_voidSetPinDir(GPIOA,PIN5,INPUT);
							  GPIO_voidSetPinDir(GPIOA,PIN6,INPUT);
							  GPIO_voidSetPinDir(GPIOA,PIN7,INPUT);
							  break;
				
				case OUTPUT : GPIO_voidSetPinDir(GPIOA,PIN4,OUTPUT);
							  GPIO_voidSetPinDir(GPIOA,PIN5,OUTPUT);
							  GPIO_voidSetPinDir(GPIOA,PIN6,OUTPUT);
							  GPIO_voidSetPinDir(GPIOA,PIN7,OUTPUT);
							  break;
				default: /* return error */ break;
			}
		break;
		case GPIOB :
			switch(Copy_u8Dir)
			{
				case INPUT  : GPIO_voidSetPinDir(GPIOB,PIN4,INPUT);
							  GPIO_voidSetPinDir(GPIOB,PIN5,INPUT);
							  GPIO_voidSetPinDir(GPIOB,PIN6,INPUT);
							  GPIO_voidSetPinDir(GPIOB,PIN7,INPUT);
						      break;
				
				case OUTPUT : GPIO_voidSetPinDir(GPIOB,PIN4,OUTPUT);
							  GPIO_voidSetPinDir(GPIOB,PIN5,OUTPUT);
							  GPIO_voidSetPinDir(GPIOB,PIN6,OUTPUT);
							  GPIO_voidSetPinDir(GPIOB,PIN7,OUTPUT);
							  break;
				default: /* return Error */ break;
			}
		break;
		
		case GPIOC :
			switch(Copy_u8Dir)
			{
				case INPUT  : GPIO_voidSetPinDir(GPIOC,PIN4,INPUT);
							  GPIO_voidSetPinDir(GPIOC,PIN5,INPUT);
							  GPIO_voidSetPinDir(GPIOC,PIN6,INPUT);
							  GPIO_voidSetPinDir(GPIOC,PIN7,INPUT);
							  break;
				
				case OUTPUT : GPIO_voidSetPinDir(GPIOC,PIN4,OUTPUT);
							  GPIO_voidSetPinDir(GPIOC,PIN5,OUTPUT);
							  GPIO_voidSetPinDir(GPIOC,PIN6,OUTPUT);
							  GPIO_voidSetPinDir(GPIOC,PIN7,OUTPUT);
							  break;
				default: /* return Error */ break;
			}
		break;
		
		case GPIOD :
			switch(Copy_u8Dir)
			{
				case INPUT  : GPIO_voidSetPinDir(GPIOD,PIN4,INPUT);
							  GPIO_voidSetPinDir(GPIOD,PIN5,INPUT);
							  GPIO_voidSetPinDir(GPIOD,PIN6,INPUT);
							  GPIO_voidSetPinDir(GPIOD,PIN7,INPUT);
							  break;
				
				case OUTPUT : GPIO_voidSetPinDir(GPIOD,PIN4,OUTPUT);
							  GPIO_voidSetPinDir(GPIOD,PIN5,OUTPUT);
							  GPIO_voidSetPinDir(GPIOD,PIN6,OUTPUT);
							  GPIO_voidSetPinDir(GPIOD,PIN7,OUTPUT);
							  break;
				default: /* return Error */ break;
			}
		break;
		default: /* return error */ break;
		
	}
}

void GPIO_voidSet_LOW_NibbleVal(u8 Copy_u8portnum, u8 Copy_u8value)
{
	u8 temp_data = Copy_u8value & 0x0F ;
	switch (Copy_u8portnum)
	{
	case GPIOA :	PORTA &= 0xF0 ;   
					PORTA |= temp_data;
					break;
					
	case GPIOB :	PORTB &= 0xF0 ;
					PORTB |= temp_data;
					break;
					
	case GPIOC :    PORTC &= 0xF0 ;
					PORTC |= temp_data;
					break;
					
	case GPIOD :	PORTD &= 0xF0 ;
					PORTD |= temp_data;
					break;
	default: /* return error */break; 
		
	}
	
}

void GPIO_voidSet_HIGH_NibbleVal(u8 Copy_u8portnum, u8 Copy_u8value)
{
	u8 temp_data = ( Copy_u8value << 4 ) ;
	switch (Copy_u8portnum)
	{
		case GPIOA :	PORTA &= 0x0F ;
						PORTA |= temp_data;
						break;
		
		case GPIOB :	PORTB &= 0x0F ;
						PORTB |= temp_data;
						break;
		
		case GPIOC :    PORTC &= 0x0F ;
						PORTC |= temp_data;
						break;
		
		case GPIOD :	PORTD &= 0x0F;
						PORTD |= temp_data;
						break;
		default: /* return error */break;
		
	}
	
}
