#ifndef  GPIO_INTERFACE_H
#define  GPIO_INTERFACE_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"

 enum PINS {
PIN_0   ,
PIN_1   ,
PIN_2   ,
PIN_3   ,
PIN_4   ,
PIN_5   ,
PIN_6   ,
PIN_7   ,
PIN_8   ,
PIN_9   ,
PIN_10  ,
PIN_11  ,
PIN_12  ,
PIN_13  ,
PIN_14  ,
PIN_15
};

enum GPIO_PORT{
PORTA    ,
PORTB    ,
PORTC   };



void GPIO_INIT(void);
void GPIO_PINWrite_High(u8 port,u8 PIN); //write in
void GPIO_PINSWrite_LOW(u8 port,u8 PIN); //write in, multiple pin ORing in same fun
void GPIO_PINReSET(u8 port,u8 PIN);//used register to access more quick
void GPIO_PINSET(u8 port,u8 PINS);//used register to access more quick
u16  GPIO_PINSRead(u8 port ,u16 PINS); //read specific one pin or multiple pins regardless in arrange
u8   GPIO_PINRead(u8 port ,u8 PIN);    //read input
void GPIO_voidPinPUDR(u8 port ,u8 PIN,u8 mode); //made for EXTI driver
void GPIO_voidTooglePin(u8 port ,u8 PIN);




#endif
