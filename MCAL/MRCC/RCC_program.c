/**************************************************************************************************/
/*                              MCAL :RCC_Program.c *******************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
/************************************************************************************************/ 
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

static u8 CLk;
RCC_Data Struct_RCC;
void RCC_voidSysClkInit(void)
{
	/*Enable CLOCK SECURITY SYSTEM */
	//SET_BIT(RCC->CR,CSSON);

#if SysClk == HSE

#if HSEByb == notbyPassed
	CLR_BIT(RCC->CR,HSE_BYP);   //HSE not bypassed
#elif HSEByb == byPassed
	SET_BIT(RCC->CR,HSE_BYP);  //HSE bypassed with external clock
#endif
	/*01: HSE oscillator selected as system clock*/
	SET_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);
	/*System Prescalar */
	RCC->CFGR |= System_Pres<<4; //HPRE
	//HSE clock enable
	SET_BIT (RCC->CR,HSE_ON);
	/*******************fill the struct about the RCC data******/
	Struct_RCC.CLKSRC=HSE;
	Struct_RCC.MegaHertz=25/System_Pres;
	/***********************************************************/
#elif SysClk == HSI

	/*00: HSI oscillator selected as system clock*/
	CLR_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);
	/*System Prescalar */
	RCC->CFGR |= System_Pres<<4; //HPRE
	/*HSI oscillator ON*/
	SET_BIT(RCC->CR,HSION);
	/*******************fill the struct about the RCC data******/
	Struct_RCC.CLKSRC=HSI;
	Struct_RCC.MegaHertz=16/System_Pres;

	/***********************************************************/
#elif SysClk == PLL
	/*____________enale system config _________*/
//	RCC->APB2ENR |=  1<<SYSCFGEN ;
	/*___________Power interface clock enable__*/
//	RCC->APB1ENR |= 1<<PWREN;

	/*___________Enable clk src for pll _______*/
#if SysClk_PLL == PLL_HSE
	Struct_RCC.PLL_SRC =1 ; //1->HSE
	/*HSE oscillator ON*/
	SET_BIT(RCC->CR,HSE_ON);

	/*___wait the HSE is ready _________________*/
	while (GET_BIT(RCC->CR,HSE_RDY)!=1);


	/*External clk src*/
	CLk=25;
#elif SysClk_PLL == PLL_HSI
	Struct_RCC.PLL_SRC =0 ; //1->HSI
	/*HSI oscillator ON*/
	SET_BIT(RCC->CR,HSION);

	/*___wait the HSI is ready _________________*/
	while (GET_BIT(RCC->CR,HSI_RDY)!=1);


	/*Internal clk src */
	CLk=16;
#endif

	/*******************fill the struct about the RCC data******/
	Struct_RCC.CLKSRC=PLL;

	/***********************************************************/
	RCC->PLLCFGR =(Struct_RCC.PLL_SRC   << 22                         | \
			PLLM                                                      | \
			PLLN <<6                                                  | \
			PLLP <<16                                                 | \
			(PLLQ << 24));

	RCC->CFGR |= 7<<10;  //pres1 //divided by 16

	RCC->CFGR |= 7<<13;  //pres2 //divided by 16


	/*set prescalar for APB1*/
	RCC->CFGR &= ~(7   <<10)  ;
	RCC->CFGR |= APB1_presc   <<10 ;
	/*set prescalar for APB2*/
	RCC->CFGR &= ~(7 <<13);
	RCC->CFGR |= SystemClk_no <<13;
	/*______Enable PLL ________*/

	RCC->CR |= 1<<PLLON;
	/*___wait the PLL is ready _________________*/
	while (GET_BIT(RCC->CR,25)!=1);

	/*__________________Select PLL a sys Clk ___________________*/

	SET_BIT(RCC->CFGR,SW1);
	CLR_BIT(RCC->CFGR,SW0);



	Struct_RCC.MegaHertz=CLk * PLLN /(PLLP*PLLM);


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
RCC_Data* RCC_ptrRCC_Data(void){


	return &Struct_RCC;
}
