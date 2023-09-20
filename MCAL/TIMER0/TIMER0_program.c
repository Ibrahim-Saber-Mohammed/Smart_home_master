/*
 * TIMER0_program.c
 *
 *  Created on: Aug 12, 2021
 *      Author: ibrahim
 */

#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "TIMER0_private.h"

/************** TIMER ISR Functions prototype **************/
/****** Timer0 Overflow ISR ********/
void __vector_11(void)__attribute__((signal)) ;

static void (*TIMER0_OVF_CALLBACK)(void) = NULL ;
/**********************************************************/

/****** TIMER0 COMP ISR ********/
void __vector_10(void)__attribute__((signal));

static void (*TIMER0_COMP_CALLBACK)(void) = NULL;
/*********************************************************/
static u8 Prescaler_value = 0;
static u8 u8_TimerState = 0;
void TIM0_voidInit(void);

u8 TIM0_u8SetConfigurations(const TIM0_Config_t * Copy_structTimerConfigurations)
{
	u8 LOC_ErrorState = STD_OK;
	if(Copy_structTimerConfigurations != NULL)
	{
		TCCR0 |= Copy_structTimerConfigurations->TIMER0_Mode | Copy_structTimerConfigurations->TIMER0_COMPARE_OUTPUT;
		TIMSK |= Copy_structTimerConfigurations->TIMER0_Interrupt | Copy_structTimerConfigurations->TIMER_COMP_INTERRUPT;
		Prescaler_value = Copy_structTimerConfigurations->TIMER0_CLOCK_SELECT;
		if (Copy_structTimerConfigurations->OVF_CALLBACK != NULL)
		{
			TIMER0_OVF_CALLBACK = Copy_structTimerConfigurations->OVF_CALLBACK;
		}
		else
		{
			LOC_ErrorState = STD_NOK;
		}
		if (Copy_structTimerConfigurations->COMP_CALLBACK != NULL)
		{
			TIMER0_COMP_CALLBACK = Copy_structTimerConfigurations->COMP_CALLBACK;
		}
		else
		{
			LOC_ErrorState = STD_NOK;
		}
	}
	else
	{
		LOC_ErrorState = STD_NOK;
	}
	return LOC_ErrorState;
}

void TIM0_u8Set_CompareRegister_Value(u8 Copy_u8Counts)
{
	OCR0 = Copy_u8Counts;
}
void TIM0_u8Set_CounterRegister_Value(u8 Copy_u8Counts)
{
	TCNT0 = Copy_u8Counts;
}

u8 TIM0_u8Get_CounterRegister_Value(u8 * Copy_ptrData)
{
	u8 LOC_ErrorState = STD_OK;
	if (Copy_ptrData != NULL)
	{
		*Copy_ptrData = TCNT0;
	}
	else
	{
		LOC_ErrorState = STD_NOK;
	}
	return LOC_ErrorState;
}
void TIM0_Disable(void)
{
	TCCR0 &= ~ ( 0b111);
	u8_TimerState = 0;
}
void TIM0_Enable(void)
{

	if( u8_TimerState == 0 )
	{
		TCCR0 &= ~ ( 0b111);
		TCCR0 |= Prescaler_value;
		u8_TimerState = 1;
	}
	else
	{

	}
}
void __vector_11(void)
{
	if (TIMER0_OVF_CALLBACK != NULL)
	{
		TIMER0_OVF_CALLBACK();
	}
}
void __vector_10(void)
{
	if (TIMER0_COMP_CALLBACK != NULL)
	{
		TIMER0_COMP_CALLBACK();
	}
}
