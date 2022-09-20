/************************************************************/
/************************ Layer:  MCAL   ********************/
/************************  MSYSTICK_interface.h  ********************/
/************************ Target :STM32F4********************/
/************************ Sep 3, 2022        ********************/
/***********************Author: Sherief Algalaly ************/
/************************************************************/


#ifndef MCAL_MSYSTICK_MSYSTICK_INTERFACE_H_
#define MCAL_MSYSTICK_MSYSTICK_INTERFACE_H_

typedef enum{
	Disable_interrupt,
	Enable_interrupt
}Interrupt_enum;


void MSTK_voidInit(void);
void MSTK_voidDelay_Synch(u32 Delay_ms);
void MSTK_voidDelay_Asnynch(u32 Delay_ms, void(*CallBackFunc)(void) );
void MSTK_voidDelay_Asnynch_Periodic(u32 Delay_ms, void(*CallBackFunc)(void) );

#endif /* MCAL_MSYSTICK_MSYSTICK_INTERFACE_H_ */
