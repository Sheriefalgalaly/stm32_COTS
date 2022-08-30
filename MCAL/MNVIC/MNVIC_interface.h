/*****************************************************************/
/************************  MNVIC_interface.h  ********************/
/************************ Target :STM32F4     ********************/
/************************ Layer: MCAL         ********************/
/************************ Aug 29, 2022        ********************/
/***********************Author: Sherief Algalaly *****************/
/*****************************************************************/

#ifndef MCAL_MNVIC_MNVIC_INTERFACE_H_
#define MCAL_MNVIC_MNVIC_INTERFACE_H_

//enum for interrupts in system
typedef enum {

	WWDG,
	EXTl16,
	EXTl21,
	EXTL22,
	FLASH,
	RCC,
	EXTl0,
	EXTl1,
	EXTl2,
	EXTl3,
	EXTl4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3,
	DMA1_Stream4,
	DMA1_Stream5,
	DMA1_Stream6,
	ADC,
	EXTl9_5,
	TIM1_BRK_TIM9,    //TIM1 Break interrupt and TIM9 global interrup
	TIM1_UP_TIM10,
	TIM1_TRG_COM_TIM11, //TIM1 Trigger and Commutation interrupt	and TIM11 global interrupt
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,          //I2C1 event interrupt
	I2C1_ER,          //I2C2 error interrupt
	SPI1,
	SPI2,
	USART1,
	USART2,
	EXTI15_10,
	EXTI17_RTC_Alarm,
	EXTI18,          //EXTI Line 18 interrupt / USB On-The-Go FS Wakeup through EXTI line interrupt
	DMA1_Stream7,
	SDIO,
	TIM5,
	SPI3,
	DMA2_Stream0,
	DMA2_Stream1,
	DMA2_Stream2,
	DMA2_Stream3,
	DMA2_Stream4,
	OTG_FS,
	DMA2_Stream5,
	DMA2_Stream6,
	DMA2_Stream7,
	USART6,
	I2C3_EV,
	I2C3_ER,
	FPU,
	SPI4
}IRQ_t;



void NVIC_SetPriorityGrouping(uint32_t priority_grouping); // Set the priority grouping
void NVIC_EnableIRQ(IRQn_t IRQn);                          // Enable IRQn
void NVIC_DisableIRQ(IRQn_t IRQn);                         // Disable IRQn
uint32_t NVIC_GetPendingIRQ (IRQn_t IRQn);                 // Return true (IRQ-Number) if IRQn is pending
void NVIC_SetPendingIRQ (IRQn_t IRQn);                     // Set IRQn pending
void NVIC_ClearPendingIRQ (IRQn_t IRQn);                   // Clear IRQn pending status
uint32_t NVIC_GetActive (IRQn_t IRQn);                     // Return the IRQ number of the active interrupt
void NVIC_SetPriority (IRQn_t IRQn, uint32_t priority);    // Set priority for IRQn

#endif /* MCAL_MNVIC_MNVIC_INTERFACE_H_ */
