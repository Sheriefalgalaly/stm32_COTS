/**************************************************************************************************/
/*                              MCAL :KeyPad_Program.c  *********************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
 /*****************************  Created on: Jul 30, 2022 ****************************************/
 /******************************        Layer :HAL      ******************************************/
/***********************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"
#include "KeyPad_Config.h"
#include "KeyPad_Interface.h"
#include "KeyPad_Private.h"


void Delay_KeyPad(void){

	for (int i=0;i<1000;i++);

}

u8 HKeyPad_Pvoidvalueof_input(u8 x)
{
	switch(x){
	case 3 :  return 1;
	case 5 :  return 2;
	case 6 :  return 3;
	case 14:  return 0;
	}
}

u8 KeyPad_voidRead(KeyPad_t* key)
{
    u8 read_value =0;
    static u8 read_value_key=48;
    for (u8 Local_u8ColumnHigh=0;Local_u8ColumnHigh<NumOfColumns;Local_u8ColumnHigh++)
    {       read_value=0;
    	    GPIO_PINWrite_LOW(*(key->PortColumn+Local_u8ColumnHigh),*(key->PinColumn+Local_u8ColumnHigh));
    		for (u8 Local_u8Column=0;Local_u8Column<NumOfColumns;Local_u8Column++)
    		{
    			if (Local_u8ColumnHigh != Local_u8Column )
    		    	  GPIO_PINWrite_High(*(key->PortColumn+Local_u8Column),*(key->PinColumn+Local_u8Column));
    		}
    		//read input
    		for (u8 Local_u8Raw=0;Local_u8Raw<NumOfRaws;Local_u8Raw++)
    		{

    			read_value |= GPIO_PINRead(*(key->PortRaw+Local_u8Raw),*(key->PinRaw+Local_u8Raw))<<Local_u8Raw;
    		}

        if (read_value != 7 )
        {
           read_value_key=KEYPAD[HKeyPad_Pvoidvalueof_input(read_value)][Local_u8ColumnHigh];                                 //if button pressed return value and out of function
           return read_value_key;
        }
        Delay_KeyPad();

    }
 return read_value_key;  //default value of last value

}

