/********************************************************************************************/
/* Author 		: Ibrahim Saber 												 			*/
/* Date 		: 9/11/2020 														 		*/
/* Version 		: V00 																		*/
/* SWC			: LCD 2*16															 		*/
/********************************************************************************************/

#ifndef HAL_CLCD_INTERFACE_H_
#define HAL_CLCD_INTERFACE_H_

void CLCD_voidInit(void);

void CLCD_voidSendCommand	( 	u8 Copy_u8Command			);
void CLCD_voidSendCharacter	( 	u8 Copy_u8Char				);
void CLCD_voidSendString	( 	u8 * Copy_ptrString			);
void CLCD_voidSendNumber	( 	u64 Copy_u64Number			);
void CLCD_voidGoToX_Y		( 	u8 Copy_u8Row ,u8 Copy_u8Col 	);
void CLCD_voidDrwaExxtraChar(	u8 Copy_u8Row ,u8 Copy_u8Col , u8 *Copy_u8ArrayChars);
void CLCD_voidClearScreen(void);
void CLCD_voidSendFloatNumber(f64 Copy_f32Number);

#define CLCD_EIGHT_BIT_TWO_LINE_5_8		0b00111100
#define CLCD_EIGHT_BIT_TWO_LINE_5_7		0b00111000
#define CLCD_FOUR_BIT_ONE_LINE_5_8		0b00110100
#define CLCD_FOUR_BIT_ONE_LINE_5_7		0b00110000
#define CLCD_DISPLAY_ON_CURSOR_ON		0b00001111
#define CLCD_DISPLAY_ON_CURSOR_OFF		0b00001100
#define CLCD_DISPLAY_OFF				0b00001000
#define CLCD_DISPLAY_CLEAR				0b00000001
#define CLCD_SHIFT_DISABEL				0b00000110
#define CLCD_SHIFT_LEFT					0b00000111
#define CLCD_SHIFT_RIGHT				0b00000101
#define CLCD_SET_DDRAM_ADDRESS			0x80
#define CLCD_SET_CGRAM_ADDRESS			0x40

#define CLCD_ROW1			1
#define CLCD_ROW2			2
#define CLCD_COL1           1
#define CLCD_COL2           2
#define CLCD_COL3           3
#define CLCD_COL4           4
#define CLCD_COL5           5
#define CLCD_COL6           6
#define CLCD_COL7           7
#define CLCD_COL8           8
#define CLCD_COL9           9
#define CLCD_COL10          10
#define CLCD_COL11          11
#define CLCD_COL12          12
#define CLCD_COL13          13
#define CLCD_COL14          14
#define CLCD_COL15          15
#define CLCD_COL16		    16

#endif /* HAL_CLCD_INTERFACE_H_ */
