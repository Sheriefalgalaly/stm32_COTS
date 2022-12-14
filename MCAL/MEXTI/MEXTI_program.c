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
#include "MCAL/MGPIO/GPIO_Interface.h"



 /*Hardware interrupt selection
To configure the 23 lines as interrupt sources, use the following procedure:
• Configure the mask bits of the 23 interrupt lines (EXTI_IMR)
• Configure the Trigger selection bits of the interrupt lines (EXTI_RTSR and EXTI_FTSR)
• Configure the enable and mask bits that control the NVIC IRQ channel mapped to the
external interrupt controller (EXTI) so that an interrupt coming from one of the 23 lines
can be correctly acknowledged.*/
 //void* FunctionCallBack[23]={NULL};

/*******************************global variables *******************************/
/*global array of function void void*/
static void (*FunctionCallBack[12])(void)={NULL};
/*global array of integer for EXTI5->9*/
static u8* priorities5_9;


/********************************Functions *************************************/
                  /**** Enable EXTI ***********/
void MEXTI_voidInit(void){
	MEXTI->IMR = 0 ;         //Reset Register
	MEXTI->PR = 0xffffffff; //reset flag register

}
                 /**** Enable Line ***********/
void MEXTI_voidEnableLine(EXTI_Config_t* Local_stuct){
	// make union to make registers of struct shared same memory with the array to access registers iterative.
    ( SYSCFG_UNion_Struct->SYSArr[(Local_stuct->Line) / 4] ) |=  Local_stuct->Port   <<((Local_stuct->Line) % 4)*4;
	//select the line
	SET_BIT(MEXTI->IMR, Local_stuct->Line);
    //select trigger
	if (Local_stuct->Trigger_Sense == Rising_edge)
	{	MEXTI->RSTR |= 1  << Local_stuct->Line;  //selected rising if Trigger_Rising ==1
		/*make sure of mode of pin is Pull_up*/
      GPIO_voidPinPUDR(Local_stuct->Port, Local_stuct->Line, Pull_down);
	}
	else if (Local_stuct->Trigger_Sense == Falling_edge)
	{	MEXTI->FSTR |= 1 << Local_stuct->Line;  //selected rising if Falling_Rising ==1
    	/*make sure of mode of pin is Pull_down*/
        GPIO_voidPinPUDR(Local_stuct->Port, Local_stuct->Line, Pull_up);
	}
}
                 /**** Disable Line ***********/
void MEXTI_voidDisableLine(EXTI_Config_t* Local_stuct){
	//select the line
	CLR_BIT(MEXTI->IMR, Local_stuct->Line);
}
                /***software trigger **********/
void MEXTI_voidSETSoftwaretrigger(EXTI_Config_t* Local_stuct){

	//set the pending flag
	MEXTI->SWIER = 1<< Local_stuct->Line ;
}

            /***reset software trigger **********/
void MEXTI_voidRESETSoftwaretrigger(EXTI_Config_t* Local_stuct){
	//clear the pending flag
	MEXTI->PR &= ~( 1<< Local_stuct->Line) ;
}
           /***change trigger *******************/
void MEXTI_voidSetTrigger_Sense(EXTI_Config_t* Local_stuct){
    //select trigger
	if (Local_stuct->Trigger_Sense == Rising_edge)
	{	MEXTI->RSTR |= 1  << Local_stuct->Line;  //selected rising if Trigger_Rising ==1
		/*make sure of mode of pin is Pull_up*/
      GPIO_voidPinPUDR(Local_stuct->Port, Local_stuct->Line, Pull_up);
	}
	else if (Local_stuct->Trigger_Sense == Falling_edge)
	{	MEXTI->FSTR |= 1 << Local_stuct->Line;  //selected rising if Falling_Rising ==1
    	/*make sure of mode of pin is Pull_down*/
        GPIO_voidPinPUDR(Local_stuct->Port, Local_stuct->Line, Pull_down);
	}
}
void MEXTI_voidToggleTrigger_Sense (EXTI_Config_t* Local_stuct){
    //toogle trigger
	/*make sure of mode of pin is Pull_up*/
    GPIO_voidPinPUDR(Local_stuct->Port, Local_stuct->Line, Pull_down);

	if (Local_stuct->Trigger_Sense == Falling_edge)
	{	MEXTI->FSTR &= ~(1  << Local_stuct->Line);  //clear falling
		MEXTI->RSTR |= 1  << Local_stuct->Line;     //selected rising


		/*Update the trigger sense*/
      Local_stuct->Trigger_Sense =Rising_edge;
	}
	else if (Local_stuct->Trigger_Sense == Rising_edge)
	{
    	/*make sure of mode of pin is Pull_down*/
        GPIO_voidPinPUDR(Local_stuct->Port, Local_stuct->Line, Pull_up);
		MEXTI->RSTR &= ~(1  << Local_stuct->Line);  //clear rising
		MEXTI->FSTR |=  1  << Local_stuct->Line;     //selected falling


		/*Update the trigger sense*/
        Local_stuct->Trigger_Sense =Falling_edge;
	}
}
           /***Function call back to store pointer of function on global array,
            * pass function call back pointer of void *ptr(Structre*) ***/
void MEXTI_voidSetCallBack(EXTI_Config_t* LocalStruct,void (*ptr)(void )){
	/*chech pointer value */

		FunctionCallBack[LocalStruct->Line]=ptr;

}
          /***Set priority of ETI9_5 *****/
void MEXTI_voidSetPrioritiesOfEXTI9_5(u8* ptr){
	/*save this pointer of array to global static pointer*/
	if (ptr != NULL)
	{
		priorities5_9 = ptr;
	}

}

/*********************************** IRQ HANDLER ***************************************************/
/*******EXTI0***************/

void EXTI0_IRQHandler (void){
	FunctionCallBack[0]();
	MEXTI->PR |= ( 1<< 0);  //CLEAR PENDING FLAG
}

/*******EXTI1***************/

void EXTI1_IRQHandler (void){
	FunctionCallBack[1]();
	MEXTI->PR |= ( 1<< 1);  //CLEAR PENDING FLAG
}

/*******EXTI2***************/

void EXTI2_IRQHandler (void){
	FunctionCallBack[2]();
	MEXTI->PR |= ( 1<< 2);  //CLEAR PENDING FLAG
}

/*******EXTI3***************/

void EXTI3_IRQHandler (void){
	FunctionCallBack[3]();
	MEXTI->PR |= ( 1<< 3);  //CLEAR PENDING FLAG
}

/*******EXTI4***************/

void EXTI4_IRQHandler (void){
	FunctionCallBack[4]();
	MEXTI->PR |= ( 1<< 4);  //CLEAR PENDING FLAG
}

/*******EXTI9_5***************/

void EXTI9_5_IRQHandler (void)
{
	/*Checking Pending flag*/
	/*you can change priority by change their arrangement*/
	for (u8 i =0;i<5;i++)
	{
		if (GET_BIT(MEXTI->PR,priorities5_9[i])==1)    //priorities5_9[i] :to access i-th priority of user in this EXTI
		{
			FunctionCallBack[priorities5_9[i]]();
			MEXTI->PR |= ( 1<< priorities5_9[i]);  //CLEAR PENDING FLAG
		}
	}
}

/*******EXTI10***************/

void EXTI10_IRQHandler (void){
	FunctionCallBack[10]();
	MEXTI->PR |= ( 1<< 10);   //CLEAR PENDING FLAG
}

/*******EXTI11***************/

void EXTI11_IRQHandler (void){
	FunctionCallBack[11]();
	MEXTI->PR |= ( 1<< 11);  //CLEAR PENDING FLAG
}

/*******EXTI12***************/

void EXTI12_IRQHandler (void){
	FunctionCallBack[12]();
	MEXTI->PR |= ( 1<< 12);  //CLEAR PENDING FLAG
}

/*******EXTI13***************/

void EXTI13_IRQHandler (void){
	FunctionCallBack[13]();
	MEXTI->PR |= ( 1<< 13);  //CLEAR PENDING FLAG
}

/*******EXTI14***************/

void EXTI14_IRQHandler (void){
	FunctionCallBack[14]();
	MEXTI->PR |= ( 1<< 14);  //CLEAR PENDING FLAG
}

/*******EXTI15***************/

void EXTI15_IRQHandler (void){
	FunctionCallBack[15]();
	MEXTI->PR |= ( 1<< 15);  //CLEAR PENDING FLAG
}
