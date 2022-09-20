/**************************************************************************************************/
/*                              MCAL :RCC_CONFIG_H *******************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
/************************************************************************************************/ 
#ifndef  RCC_CONFIG_H
#define   RCC_CONFIG_H

/**********************************************************************************/
/***      in case you need 84mhz from HSI  in PLL                              ****/
/***        -follow these confg
 *               M=15
 *               N=315
 *               p=4
 *                  *APB1 pres =2*
 ****     in case you need 50 mhz from HSE  in PLL                              ****
 *           M=          25
 *           N=         300
 *           P=          6                                                         */
            /*APB1 pres =2*/
/***********************************************************************************/
/*  system clock Config */
#define HSE 0
#define HSI 1
#define PLL 2

#define SysClk  HSE
//#define SysClk  HSI
//#define SysClk     PLL
//#define SysClk_PLL PLL_HSE
//#define SysClk_PLL PLL_HSI
/*****           *****/

/* HSE Clock Source  */

#define notbyPassed 0
#define byPassed    1

#define HSEByb   notbyPassed
//#define HSEByb   byPassed

/*******      ******/


#define PLLN   300   /*192 ≤ PLLN ≤ 432*/
#define PLLM   25    /*2 ≤ PLLM ≤ 63*/
#define PLLP   6    /* 2 - 4 -6 -8 */
#define PLLQ   4
#define APB1_presc    AHBNopres   //pres

#define System_Pres   SystemClk_no   //if HSI = 16M --> System clock =8 M
#endif
