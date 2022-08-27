/**************************************************************************************************/
/*                              MCAL :RCC_INTERFACE_H *******************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
/************************************************************************************************/ 
#ifndef  RCC_INTERFACE_H
#define  RCC_INTERFACE_H


// create enum for peripherals ,to use directly without writing the the bus
typedef enum{
	/*AHB1ENR */
	GPIO_A,
	GPIO_B,
	GPIO_C,
	CCRC =12,
	DMA1 =21,
	DMA2 ,
	/*AHB2ENR */
	OTG =39,
	/*APB1ENR*/
	TIM2 =64,
	TIM3 ,
	TIM4,
	TIM5,
	WWDG =107,
	SPI2 =TIM2+14,
	SPI3,
	UART2 =TIM2 +17,
	I2C1 =TIM2 +21,
	I2C2,
	I2C3,
	PWR =TIM2 +28,
	/*APB2ENR*/
	TIM1=96,
	UART1 = TIM1 +4,
	UART6 ,
	ADC1 =TIM1 +8,
	SDIO =TIM1 +11,
	SPI1 ,
	SPI4 ,
	SYSCF ,
	TIM9 =TIM1+16,
	TIM10,
	TIM11
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
	SYSCLK=0,
	PLLI2s
}SrcMCO_t;
void RCC_voidSysClkInit(void);

void RCC_voidEnablePerClk( u8 Per);

void RCC_voidDisablePerClk(Per_Sel Per);

void RCC_voidMCO(u8 MCONum ,u8 SRC ,u8 Pres);

#endif

