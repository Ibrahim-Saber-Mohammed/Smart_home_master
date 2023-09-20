/*
 * GIE_program.c
 *
 *  Created on: Aug 30, 2021
 *      Author: ibrahim
 */


#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIR_config.h"
#include "GIE_private.h"

void GIE_voidEnable(void)
{
	SET_BIT( SREG , GIE );
}

void GIE_voidDisable(void)
{
	CLR_BIT( SREG , GIE );
}
