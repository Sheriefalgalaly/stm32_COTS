/************************************************************/
/************************ Layer:  MCAL   ********************/
/************************  MSYSTICK_program.c  **************/
/************************ Target :STM32F4********************/
/************************ Sep 3, 2022        ****************/
/***********************Author: Sherief Algalaly ************/
/************************************************************/

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MSYSTICK/MSYSTICK_config.h"
#include "MCAL/MSYSTICK/MSYSTICK_interface.h"
#include "MCAL/MSYSTICK/MSYSTICK_private.h"
#include "MCAL/MRCC/RCC_interface.h"

RCC_Data* RCC_Freq_data ;   //get the freq of system from RCC
Ticks_data_1ms Data_ticks ={
	.status =Idle,
};
static void(*PtrToFunction)(void) =NULL;
void MSTK_voidInit(void){
	/**********Select CLKSRC*************/
#if CLK == Processor_clk

	MSTK->CTRL |= 1<<2;  //set bit for processor clock

#elif  CLK == AHB_8
	MSTK->CTRL &= ~(1<<2);  //CLR bit for AHB/8

#endif
	/********Interrupt EN/Dis-able *********/
#if Interrupt     == Enable_interrupt       //if enabled
	MSTK->CTRL |= 1<<1;    //enable interrupt

#elif  Interrupt
	MSTK->CTRL &= ~(1<<1);


#endif
	RCC_Freq_data = RCC_ptrRCC_Data();
	//Get time of one tick in  nsec
	Data_ticks.Local_OneTick = 1000/ RCC_Freq_data->MegaHertz;
	// get how many ticks for 1 ms
	Data_ticks.ValueOfLoad =1000000 /Data_ticks.Local_OneTick;


}

void MSTK_voidDelay_Synch(u32 Delay_ms){
	//counters of how many 1 msec
	Data_ticks.TimesOfCounters = Delay_ms;

	/**reset the register ********/
	MSTK->VAL=0;
	/**load register with value */

	do{
		//update the value
		MSTK->LOAD=Data_ticks.ValueOfLoad;
		// start the timer
		MSTK->CTRL|=1<<0;
		//waiting the flag
		while (GET_BIT(MSTK->CTRL,16)!=1);
		//stop the timer
		MSTK->CTRL&=~(1<<0);
	}while (--Data_ticks.TimesOfCounters);

}
void MSTK_voidDelay_Asnynch(u32 Delay_ms , void(*CallBackFunc)(void)){
	if (Data_ticks.status ==Idle){
		Data_ticks.status =Busy;
	//check the pointer isn't null
	if (CallBackFunc != NULL)
		PtrToFunction =CallBackFunc ;
	//counters of how many 1 msec
	Data_ticks.TimesOfCounters = Delay_ms;

	/**reset the register ********/
	MSTK->VAL=0;
	//update the value
	MSTK->LOAD=Data_ticks.ValueOfLoad;
	// start the timer
	MSTK->CTRL|=1<<0;
	}
}
void MSTK_voidDelay_Asnynch_Periodic(u32 Delay_ms, void(*CallBackFunc)(void) ){}

//ISR SYSTICK

void SysTick_Handler (void){
	if (!(--Data_ticks.TimesOfCounters))
	{	//stop the timer
		MSTK->CTRL&=~(1<<0);
		Data_ticks.status =Idle;
		//call the function
			PtrToFunction();
	}
}


