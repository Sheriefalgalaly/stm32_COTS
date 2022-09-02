/************************************************************/
/************************ MNVIC_program.c   *****************/
/************************ Target :STM32F4********************/
/************************ Layer: MCAl    ********************/
/************************ Aug 29, 2022        ***************/
/***********************  Author: Sherief Algalaly **********/
/************************************************************/
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MNVIC/MNVIC_interface.h"
#include "MCAL/MNVIC/MNVIC_config.h"
#include "MCAL/MNVIC/MNVIC_private.h"

/*Global var*/
static u8 GlobalPriorityGroup =0;

void NVIC_SetPriorityGrouping(u32 priority_grouping){
SCB->AIRCR =  0x05FA0000 | priority_grouping <<8 ;
GlobalPriorityGroup =priority_grouping;   //save it in globbal var

}

void NVIC_EnableIRQ( IRQ_t IRQn){

	  MNVIC->ISER[IRQn/32]=1<<(IRQn%32);
}

void NVIC_DisableIRQ(IRQ_t IRQn){
	  MNVIC->ICER[IRQn/32]=1<<(IRQn%32);
}
u8 NVIC_GetPendingIRQ ( IRQ_t IRQn){


}
void NVIC_SetPendingIRQ ( IRQ_t IRQn){
	  MNVIC->ISPR[IRQn/32]=1<<(IRQn%32);
}

void NVIC_ClearPendingIRQ ( IRQ_t IRQn){
	  MNVIC->ICPR[IRQn/32]=1<<(IRQn%32);

}

u8 NVIC_GetActive ( IRQ_t IRQn){
	 return  MNVIC->IABR[IRQn/32]=1<<(IRQn%32);
}

void NVIC_SetPriority ( IRQ_t IRQn, u8 Group_priority,u8 Sub_Priority){
// for external interrupt
	u8 Priority = GlobalPriorityGroup;
	if (IRQn >=0){
		MNVIC->IPR[IRQn]= ((Group_priority<< (Priority-3) | Sub_Priority)<<4) ;
	}
// for internal interrupts
	else {


	}
}


