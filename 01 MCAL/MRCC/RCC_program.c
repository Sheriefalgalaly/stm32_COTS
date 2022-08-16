/**************************************************************************************************/
/*                              MCAL :RCC_Program.c *******************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
/************************************************************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
void RCC_voidSysClkInit(void)
{
	//RCC_CR = 0x00000081; //reset register
#if SysClk == HSE
		SET_BIT (RCC_CR,HSE_ON);   //HSE clock enable
        #if HSEByb == notbyPassed
		CLR_BIT(RCC_CR,HSE_BYP);   //HSE not bypassed
        #elif HSEByb == byPassed
		SET_BIT(RCC_CR,HSE_BYP);  //HSE bypassed with external clock
        #endif
	/*01: HSE oscillator selected as system clock*/
		SET_BIT(RCC_CFGR,SW0);
		CLR_BIT(RCC_CFGR,SW1);



#elif SysClk == HSI

 /*HSI oscillator ON*/
		SET_BIT(RCC_CR,HSION);
   /*00: HSI oscillator selected as system clock*/
		CLR_BIT(RCC_CFGR,SW0);
		CLR_BIT(RCC_CFGR,SW1);

#elif SysClk == PLL
  /*These bits can be written only
   * when the PLL and PLLI2S are
   * disabled.*/
	RCC_PLLCFGR |= PLLN <<6 ;
	RCC_PLLCFGR |= PLLM     ;
	RCC_PLLCFGR |= PLLP <<16;


		/* Main PLL (PLL) enable*/
		SET_BIT(RCC_CR,PLLON);
		/*select pll as the system clock*/
		CLR_BIT(RCC_CFGR,SW0);
		SET_BIT(RCC_CFGR,SW1);



#endif

}
void RCC_voidEnablePerClk( u8 Per){
#if SysClk == HSE   // created after config of HSE end
	CLR_BIT(RCC_CR,HSION); //off HSI
#endif

		switch (Per){
		/*Peripheral for AHB1*/
		case GPIO_A: SET_BIT(RCC_AHB1ENR,0); break;
		case GPIO_B: SET_BIT(RCC_AHB1ENR,1); break;
		case GPIO_C: SET_BIT(RCC_AHB1ENR,2); break;
		//followed by  every peripheral implemented
	}

}

void RCC_voidDisablePerClk(Per_Sel Per){

		switch (Per){
		/*for AHB1 peripherals*/
		case GPIO_A :   CLR_BIT(RCC_AHB1ENR,0); break;
		case GPIO_B :   CLR_BIT(RCC_AHB1ENR,1); break;
		case GPIO_C :   CLR_BIT(RCC_AHB1ENR,2); break;
		   // followed , for every peripheral implemented

	}

}
