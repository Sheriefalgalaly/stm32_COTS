/**************************************************************************************************/
/*                              MCAL :RCC_Program.c *******************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
/************************************************************************************************/ 
#include "00_LIB/BIT_MATH.h"
#include "00_LIB/STD_TYPES.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidSysClkInit(void)
{
	/*Enable CLOCK SECURITY SYSTEM */
	SET_BIT(RCC->CR,CSSON);

#if SysClk == HSE

        #if HSEByb == notbyPassed
		CLR_BIT(RCC->CR,HSE_BYP);   //HSE not bypassed
        #elif HSEByb == byPassed
		SET_BIT(RCC->CR,HSE_BYP);  //HSE bypassed with external clock
        #endif
	   /*01: HSE oscillator selected as system clock*/
		SET_BIT(RCC->CFGR,SW0);
		CLR_BIT(RCC->CFGR,SW1);
		//HSE clock enable
		SET_BIT (RCC->CR,HSE_ON);

#elif SysClk == HSI

       /*00: HSI oscillator selected as system clock*/
	  	CLR_BIT(RCC->CFGR,SW0);
		CLR_BIT(RCC->CFGR,SW1);
		 /*HSI oscillator ON*/
		SET_BIT(RCC->CR,HSION);
#elif SysClk == PLL
        #if SysClk == HSE
		 /*HSI oscillator ON*/
		SET_BIT(RCC->CR,HSEON);
		/*select clk src for pll */
		SET_BIT(RCC->PLLCFGR,22);

        #elif SysClk == HSI
		 /*HSI oscillator ON*/
		SET_BIT(RCC->CR,HSION);
		/*select clk src for pll */
		CLR_BIT(RCC->PLLCFGR,22);

        #endif
		/*Select PLLM*/
		    //reset PLLM
		RCC->PLLCFGR &=	RCC->PLLCFGR & ~(0b111111);
		    //reset PLLn
		RCC->PLLCFGR &=	RCC->PLLCFGR & ~(0b111111111)<<6;
		    //reset PLLP
		RCC->PLLCFGR &=	RCC->PLLCFGR & ~(0b11)<<16;

		/*     write value   */
		RCC->PLLCFGR |= PLLN <<6 ;
		RCC->PLLCFGR |= PLLM <<0 ;
	    RCC->PLLCFGR |= PLLP <<16;
       // Enable PLL
        SET_BIT(RCC->CR ,PLLON);
       // Enabe system clk
        SET_BIT(RCC->CFGR ,SW1);
        CLR_BIT(RCC->CFGR ,SW0);

#endif

}

void RCC_voidEnablePerClk( u8 Per){
#if SysClk == HSE   // created after config of HSE end
	CLR_BIT(RCC->CR,HSION); //off HSI
#endif

		switch (Per /32){
		/*Peripheral for AHB1*/
		case AHB1: SET_BIT(RCC->AHB1ENR,Per %32); break;
		case AHB2: SET_BIT(RCC->AHB2ENR,Per %32); break;
		case APB1: SET_BIT(RCC->APB1ENR,Per %32); break;
		case APB2: SET_BIT(RCC->APB2ENR,Per %32); break;

	}

}

void RCC_voidDisablePerClk(Per_Sel Per){

	switch (Per /32){
	/*Peripheral for AHB1*/
	case AHB1: CLR_BIT(RCC->AHB1ENR,Per %32); break;
	case AHB2: CLR_BIT(RCC->AHB2ENR,Per %32); break;
	case APB1: CLR_BIT(RCC->APB1ENR,Per %32); break;
	case APB2: CLR_BIT(RCC->APB2ENR,Per %32); break;

}

}
void RCC_voidMCO(u8 MCONum ,u8 SRC ,u8 Pres){
	switch (MCONum){
	//PA8
	  case MCO1: RCC->CFGR |=SRC<<21  ;  //set SRC
		         RCC->CFGR |= Pres<<24;  //set pres
		         break;
    //PC9
	  case MCO2: RCC->CFGR |=SRC<<30  ;  //set SRC
                 RCC->CFGR |= Pres<<27;  //set pres
                 break;
	}

}
