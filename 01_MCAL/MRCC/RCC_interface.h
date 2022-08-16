/**************************************************************************************************/
/*                              MCAL :RCC_INTERFACE_H *******************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
/************************************************************************************************/ 
#ifndef  RCC_INTERFACE_H
#define  RCC_INTERFACE_H

#define  RCC_AHB1         0
#define  RCC_AHB2         1
#define  RCC_APB1         2
#define  RCC_APB2         3

// create enum for peripherals ,to use directly without writing the the bus
typedef enum{
	GPIO_A,
	GPIO_B,
	GPIO_C,
	UART,
   // for each driver created ,you must add it here
}Per_Sel;

void RCC_voidSysClkInit(void);

void RCC_voidEnablePerClk( u8 Per);

void RCC_voidDisablePerClk(Per_Sel Per);



#endif
/*AHB1
 *  RCC
 *  GPIO A ->H
 *  CRC
 *  DMA1-2
 */
/*AHB2
 * USB OTG
 */
