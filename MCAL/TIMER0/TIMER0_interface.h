/*
 * TIMER0_interface.h
 *
 *  Created on: Aug 12, 2021
 *      Author: ibrahim
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

/******** Timer modes of operation ************************/
#define TIMER0_NORMAL_MODE			(0b0<<3)|(0b0<<6)
#define TIMER0_CTC_MODE				(0b1<<3)|(0b0<<6)
#define TIMER0_PWM_PHASE_MODE		(0b0<<3)|(0b1<<6)
#define TIMER0_FAST_PWM_MODE		(0b1<<3)|(0b1<<6
/***********************************************************/

/******** TIMER Over Flow Interrupt Options ****************/
#define TIMER0_OVE_ENABLE_INTERRUPT			(0b1<<0)
#define TIMER0_OVE_DISABLE_INTERRUPT		(0b0<<0)
/***********************************************************/
/******** TIMER Compare Match Interrupt Options ************/
#define TIMER0_COMP_ENABLE_INTERRUPT		(0b1<<1)
#define TIMER0_COMP_DISABLE_INTERRUPT		(0b0<<1)
/***********************************************************/

/************** TIMER0 Pre-scaler options ******************/
#define TIM0_NO_CLK				(0b000)
#define TIM0_CLK				(0b001)
#define TIM0_CLK_8				(0b010)
#define TIM0_CLK_64				(0b011)
#define TIM0_CLK_256			(0b100)
#define TIM0_CLK_1024			(0b101)
#define TIM0_EXTERNAL_FALLING	(0b110)
#define TIM0_EXTERNAL_RISING	(0b111)
/***********************************************************/


/************** Compare Output Mode	***********************/
		/***** NON PWM *****/
#define OC0_DISCONNECTED		(0b00<<4)
#define TOGGLE_OC0				(0b01<<4)
#define CLEAR_OC0				(0b10<<4)
#define SET_OC0					(0b11<<4)

/**********************************************************/

typedef struct{
	u8 TIMER0_Mode						;
	u8 TIMER0_CLOCK_SELECT				;
	u8 TIMER0_Interrupt					;
	u8 TIMER_COMP_INTERRUPT				;
	u8 TIMER0_COMPARE_OUTPUT			;
	void (*OVF_CALLBACK  )(void)		;
	void (*COMP_CALLBACK )(void)		;
}TIM0_Config_t;

void TIM0_voidInit(void);

u8 TIM0_u8SetConfigurations(const TIM0_Config_t * Copy_structTimerConfigurations);

void TIM0_u8Set_CompareRegister_Value(u8 Copy_u8Counts);

void TIM0_u8Set_CounterRegister_Value(u8 Copy_u8Counts);

u8 TIM0_u8Get_CounterRegister_Value(u8 * Copy_ptrData);

void TIM0_Disable(void);
void TIM0_Enable(void);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
