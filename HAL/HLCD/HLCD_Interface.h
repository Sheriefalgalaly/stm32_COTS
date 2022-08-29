/**************************************************************************************************/
/*                              MCAL :HLCD_Interface_H_  ****************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
 /******************************  Created on: Jul 31, 2022 **************************************/
/************************************************************************************************/

#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

typedef struct {
	u8* DataPort;
	u8* DataPins;
	u8* CtrlPort; //RS-RW-en  in this order
	u8* CtrlPins;
}HLCD_t;

void CLCD_voidInit(HLCD_t* );
void CLCD_voidSendString(HLCD_t*,const char* Copy_pcString);
void CLCD_voidGoToXY(HLCD_t*,u8 Copy_u8XPos,u8 Copy_u8YPos);

#endif /* HLCD_INTERFACE_H_ */
