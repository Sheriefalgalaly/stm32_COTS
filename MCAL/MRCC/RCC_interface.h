/**************************************************************************************************/
/*                              MCAL :RCC_INTERFACE_H *******************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
/************************************************************************************************/ 
#ifndef  RCC_INTERFACE_H
#define  RCC_INTERFACE_H

#include "LIB/STD_TYPES.h"
// create enum for peripherals ,to use directly without writing the the bus
typedef enum{
	/*AHB1ENR */
	RCC_GPIO_A,
	RCC_GPIO_B,
	RCC_GPIO_C,
	RCC_CCRC =12,
	RCC_DMA1 =21,
	RCC_DMA2 ,
	/*AHB2ENR */
	RCC_OTG =39,
	/*APB1ENR*/
	RCC_TIM2 =64,
	RCC_TIM3 ,
	RCC_TIM4,
	RCC_TIM5,
	RCC_WWDG =107,
	RCC_SPI2 =RCC_TIM2+14,
	RCC_SPI3,
	RCC_UART2 =RCC_TIM2 +17,
	RCC_I2C1 =RCC_TIM2 +21,
	RCC_I2C2,
	RCC_I2C3,
	RCC_PWR =RCC_TIM2 +28,
	/*APB2ENR*/
	RCC_TIM1=96,
	RCC_UART1 = RCC_TIM1 +4,
	RCC_UART6 ,
	RCC_ADC1 =RCC_TIM1 +8,
	RCC_SDIO =RCC_TIM1 +11,
	RCC_SPI1 ,
	RCC_SPI4 ,
	RCC_SYSCF ,
	RCC_TIM9 =RCC_TIM1+16,
	RCC_TIM10,
	RCC_TIM11
   // for each driver created ,you must add it here
}Per_Sel;

typedef enum {
	AHB1,
	AHB2,
	APB1,
	APB2
}Bus;

typedef enum {
	MCO1,
	MCO2
}MCO_t;
typedef enum {
	pres_no,
	Pres_2 =4,
	Pres_3,
	Pres_4,
	Pres_5

}PresMCO_t;
typedef enum {
	HSI,
	LSE,
	HSE,
	PLL,
	PLL_HSE,
	PLL_HSI,
	SYSCLK=0,
	PLLI2s
}SrcMCO_t;

typedef struct {

	u8 CLKSRC;
	u8 MegaHertz;
	u8 AHB_pres;
	u8 PLL_SRC ;
}RCC_Data;
void RCC_voidSysClkInit(void);

void RCC_voidEnablePerClk( u8 Per);

void RCC_voidDisablePerClk(Per_Sel Per);

void RCC_voidMCO(u8 MCONum ,u8 SRC ,u8 Pres);

RCC_Data* RCC_ptrRCC_Data(void);    //this function back struct has data about rcc (clksrc-megahertz)

#endif

