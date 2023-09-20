/*
 * TIMER0_private.h
 *
 *  Created on: Aug 12, 2021
 *      Author: ibrahim
 */

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_

#define TCNT0				*( (volatile u8 * const) 0x52)
#define TCCR0				*( (volatile u8 * const) 0x53)
#define OCR0                *( (volatile u8 * const) 0x5C)
#define TIMSK               *( (volatile u8 * const) 0x59)
#define TIFR                *( (volatile u8 * const) 0x58)

#define	CS00				(0)
#define	CS01				(1)
#define CS02				(2)
#define WGM00				(3)
#define COM00				(4)
#define COM01				(5)
#define WGM01				(6)
#define FOC0				(7)

#define TOIE0				(0)
#define OCIE0				(1)






#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
