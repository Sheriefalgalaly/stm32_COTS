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

	MNVIC_WWDG,
	MNVIC_EXTl16,
	MNVIC_EXTl21,
	MNVIC_EXTl22,
	MNVIC_FLASH,
	MNVIC_RCC,
	MNVIC_EXTl0,
	MNVIC_EXTl1,
	MNVIC_EXTl2,
	MNVIC_EXTl3,
	MNVIC_EXTl4,
	MNVIC_DMA1_Stream0,
	MNVIC_DMA1_Stream1,
	MNVIC_DMA1_Stream2,
	MNVIC_DMA1_Stream3,
	MNVIC_DMA1_Stream4,
	MNVIC_DMA1_Stream5,
	MNVIC_DMA1_Stream6,
	MNVIC_ADC,
	MNVIC_EXTl9_5,
	MNVIC_TIM1_BRK_TIM9,    //TIM1 Break interrupt and TIM9 global interrup
	MNVIC_TIM1_UP_TIM10,
	MNVIC_TIM1_TRG_COM_TIM11, //TIM1 Trigger and Commutation interrupt	and TIM11 global interrupt
	MNVIC_TIM1_CC,
	MNVIC_TIM2,
	MNVIC_TIM3,
	MNVIC_TIM4,
	MNVIC_I2C1_EV,          //I2C1 event interrupt
	MNVIC_I2C1_ER,          //I2C2 error interrupt
	MNVIC_SPI1,
	MNVIC_SPI2,
	MNVIC_USART1,
	MNVIC_USART2,
	MNVIC_EXTI15_10,
	MNVIC_EXTI17_RTC_Alarm,
	MNVIC_EXTI18,          //EXTI Line 18 interrupt / USB On-The-Go FS Wakeup through EXTI line interrupt
	MNVIC_DMA1_Stream7,
	MNVIC_SDIO,
	MNVIC_TIM5,
	MNVIC_SPI3,
	MNVIC_DMA2_Stream0,
	MNVIC_DMA2_Stream1,
	MNVIC_DMA2_Stream2,
	MNVIC_DMA2_Stream3,
	MNVIC_DMA2_Stream4,
	MNVIC_OTG_FS,
	MNVIC_DMA2_Stream5,
	MNVIC_DMA2_Stream6,
	MNVIC_DMA2_Stream7,
	MNVIC_USART6,
	MNVIC_I2C3_EV,
	MNVIC_I2C3_ER,
	MNVIC_FPU,
	MNVIC_SPI4
}IRQ_t;

typedef enum {
	Group16 =3,
	Group8_2Sub,
	Group4_4Sub,
	Group2_8Sub,
	Group0_16Sub
};

void NVIC_SetPriorityGrouping(u32 priority_grouping); // Set the priority grouping
void NVIC_EnableIRQ( IRQ_t IRQn);                          // Enable IRQn
void NVIC_DisableIRQ( IRQ_t IRQn);                         // Disable IRQn
u8 NVIC_GetPendingIRQ ( IRQ_t IRQn);                 // Return true (IRQ-Number) if IRQn is pending
void NVIC_SetPendingIRQ ( IRQ_t IRQn);                     // Set IRQn pending
void NVIC_ClearPendingIRQ ( IRQ_t IRQn);                   // Clear IRQn pending status
u8 NVIC_GetActive ( IRQ_t IRQn);                     // Return the IRQ number of the active interrupt
void NVIC_SetPriority ( IRQ_t IRQn, u8 Group_priority,u8 Sub_Priority);    // Set priority for IRQn

#endif /* MCAL_MNVIC_MNVIC_INTERFACE_H_ */
