/**************************************************************************************************/
/*                              MCAL :HLCD_CONFIG_H_  ****************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
 /******************************  Created on: Jul 31, 2022 **************************************/
/************************************************************************************************/

#ifndef HLCD_CONFIG_H_
#define HLCD_CONFIG_H_

#include "GPIO_Interface.h"

//CLCD_4_mode
//CLCD_8_mode
             /***Define mode of LCD ***/

#define Type_mode    CLCD_4_mode

//
///*LCD Control port*/
//#define CLCD_CTRL_PORT    PORTC
//
///*LCD Control pins*/
//#define HLCD_RS_PIN      PORTC_13
//#define HLCD_RW_PIN      PORTC_14
//#define HLCD_E_PIN       PORTC_15
//
///*LCD Data port*/
//#define CLCD_DATA_PORT    PORTB
//
///*LCD Data pins*/
////#define HLCD_DATA_PIN0    PORTB_6
////#define HLCD_DATA_PIN1    PORTB_7
////#define HLCD_DATA_PIN2    PORTB_8
////#define HLCD_DATA_PIN3    PORTB_9
//#define HLCD_DATA_PIN4    PORTB_10
//#define HLCD_DATA_PIN5    PORTB_12
//#define HLCD_DATA_PIN6    PORTB_13
//#define HLCD_DATA_PIN7    PORTB_14
//



#endif /* HLCD_CONFIG_H_ */
