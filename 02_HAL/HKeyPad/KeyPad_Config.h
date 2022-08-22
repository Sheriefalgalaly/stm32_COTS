/**************************************************************************************************/
/*                              MCAL :KeyPad_CONFIG_H_  *********************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
 /*****************************  Created on: Jul 30, 2022 ****************************************/
 /******************************        Layer :HAL      ******************************************/
/***********************************************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


#define NumOfColumns   3
#define NumOfRaws      3


#define PORT     PORTB

//#define x1       PORTB_0  //notice define these pins as "output OPEN DRAIN" in GPIO.CONFIG
//#define x2       PORTB_1  //notice define these pins as "output OPEN DRAIN" in GPIO.CONFIG
//#define x3       PORTB_2  //notice define these pins as "output OPEN DRAIN" in GPIO.CONFIG
//#define x4       PORTB_8  //notice define these pins as "output OPEN DRAIN" in GPIO.CONFIG
//#define y1       PORTB_5  //notice define these pins as "INPUT  PULLUP" in GPIO.CONFIG
//#define y2       PORTB_6  //notice define these pins as "INPUT  PULLUP" in GPIO.CONFIG
//#define y3       PORTB_7  //notice define these pins as "INPUT  PULLUP" in GPIO.CONFIG
//#define y4       PORTB_9  //notice define these pins as "INPUT  PULLUP" in GPIO.CONFIG
//

#endif /* KEYPAD_CONFIG_H_ */
