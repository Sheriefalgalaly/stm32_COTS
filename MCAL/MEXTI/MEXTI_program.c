/************************************************************/
/************************  MEXTI_program.c  *****************/
/************************ Target :STM32F4********************/
/************************ Layer:  MCAL       ****************/
/************************ Aug 31, 2022        ***************/
/***********************Author: Sherief Algalaly ************/
/************************************************************/
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MEXTI/MEXTI_interface.h"
#include "MCAL/MEXTI/MEXTI_config.h"
#include "MCAL/MEXTI/MEXTI_private.h"
 /*Hardware interrupt selection
To configure the 23 lines as interrupt sources, use the following procedure:
• Configure the mask bits of the 23 interrupt lines (EXTI_IMR)
• Configure the Trigger selection bits of the interrupt lines (EXTI_RTSR and EXTI_FTSR)
• Configure the enable and mask bits that control the NVIC IRQ channel mapped to the
external interrupt controller (EXTI) so that an interrupt coming from one of the 23 lines
can be correctly acknowledged.*/

void MEXTI_voidInit(void){
	MEXTI->IMR = 0 ;         //Reset Register
	MEXTI->PR = 0xffffffff; //reset flag register

}
void MEXTI_voidEnableLine(EXTI_Config_t* Local_stuct){
	// make union to make registers of struct shared same memory with the array to access registers iterative.
    ( SYSCFG_UNion_Struct->SYSArr[(Local_stuct->Line) / 4] ) |=  Local_stuct->Port   <<((Local_stuct->Line) % 4)*4;
	//select the line
	SET_BIT(MEXTI->IMR, Local_stuct->Line);
    //select trigger
	MEXTI->RSTR = Local_stuct->Trigger_Rising  << Local_stuct->Line;  //selected rising if Trigger_Rising ==1
	MEXTI->FSTR = Local_stuct->Trigger_Falling << Local_stuct->Line;  //selected rising if Falling_Rising ==1


}
void MEXTI_voidDisableLine(EXTI_Config_t* Local_stuct){
	//select the line
	CLR_BIT(MEXTI->IMR, Local_stuct->Line);
}
void MEXTI_voidSETSoftwaretrigger(EXTI_Config_t* Local_stuct){
	//set the pending flag
	MEXTI->SWIER = 1<< Local_stuct->Line ;
}
void MEXTI_voidRESETSoftwaretrigger(EXTI_Config_t* Local_stuct){
	//clear the pending flag
	MEXTI->PR &= ~( 1<< Local_stuct->Line) ;
}
void MEXTI_voidSetTrigger(EXTI_Config_t* Local_stuct){
    //select trigger
	MEXTI->RSTR = Local_stuct->Trigger_Rising  << Local_stuct->Line;  //selected rising if Trigger_Rising ==1
	MEXTI->FSTR = Local_stuct->Trigger_Falling << Local_stuct->Line;  //selected rising if Falling_Rising ==1

}
