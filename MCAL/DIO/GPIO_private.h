/****************************************************************************************/
/* Author 		: Ibrahim Saber 												 */
/* Date 			: 9/11/2020 													 */
/* Version 		: V00 														 */
/****************************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/* GPIO Registers */
#define PORTA 			*((volatile u8 * const)0x3B)
#define DDRA 			*((volatile u8 * const)0x3A)  // const pointer to volatile unsigned char
#define PINA 			*((volatile u8 * const)0x39)

#define PORTB 			*((volatile u8 * const)0x38)
#define DDRB 			*((volatile u8 * const)0x37)
#define PINB 			*((volatile u8 * const)0x36)

#define PORTC 			*((volatile u8 * const)0x35)
#define DDRC 			*((volatile u8 * const)0x34)
#define PINC 			*((volatile u8 * const)0x33)

#define PORTD 			*((volatile u8 * const)0x32)
#define DDRD 			*((volatile u8 * const)0x31)
#define PIND 			*((volatile u8 * const)0x30)

/* Spcial function register */
#define mySFIOR         *((volatile u8 * const)0X50)
		/* Pull UP PIN control */
		#define PUD     2  
		


#endif