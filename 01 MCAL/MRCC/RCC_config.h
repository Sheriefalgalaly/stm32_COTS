/**************************************************************************************************/
/*                              MCAL :RCC_CONFIG_H *******************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
/************************************************************************************************/ 
#ifndef  RCC_CONFIG_H
#define   RCC_CONFIG_H

/*  system clock Config */
#define HSE 0
#define HSI 1
#define PLL 2

#define SysClk  HSE
//#define SysClk  HSI
//#define SysClk  PLL
/*****           *****/

/* HSE Clock Source  */

#define notbyPassed 0
#define byPassed    1

#define HSEByb   notbyPassed
//#define HSEByb   byPassed

/*******      ******/

/**** PLL selection ***/
/*f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
• f(PLL general clock output) = f(VCO clock) / PLLP*/

#define PLLN   400   /*192 ≤ PLLN ≤ 432*/
#define PLLM   8    /*2 ≤ PLLM ≤ 63*/
#define PLLP   2    /* 2 - 4 -6 -8 */
#endif
