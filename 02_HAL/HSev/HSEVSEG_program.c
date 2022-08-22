/*
 * HSEVSEG_program.c
 *
 *  Created on: Aug 2, 2022
 *      Author: Admin
 */
#include "00_LIB/STD_TYPES.h"
#include "00_LIB/BIT_MATH.h"
#include "01_MCAL/MGPIO/GPIO_Interface.h"
#include "HSEVSEF_interface.h"
#include "HSEVSEG_private.h"
void delay(){
	for (int i=0 ;i<10000;i++)
		asm ("nop");
}
 void HSevSeg_voidDisable(SevSeg_t* Sev){

	if(Sev->Common==CommonCathode)
		GPIO_PINWrite_High((Sev->PortOfCommon),(Sev->PinOfCommon));

	else if(Sev->Common==CommonAnode)
		GPIO_PINWrite_LOW((Sev->PortOfCommon),(Sev->PinOfCommon));



}
void HSevSeg_voidSetNum(SevSeg_t* Sev,u8 Num){
	if (Num>9)
return;
	HSevSeg_voidClear(Sev);
	u8 Local_u8num=SEVNumbers[Num];
	if(Sev->Common==CommonCathode)
	{
		GPIO_PINWrite_LOW((Sev->PortOfCommon),(Sev->PinOfCommon));
		for (u8 i=0;i<7;i++)
			if(GET_BIT(Local_u8num,i)==1)
				GPIO_PINWrite_High(*((Sev->port)+i),*( (Sev->pins)+i));
	}
	else if(Sev->Common==CommonAnode)
	{
		GPIO_PINWrite_High((Sev->PortOfCommon),(Sev->PinOfCommon));
		for (u8 i=0;i<7;i++)
			if(GET_BIT(Local_u8num,i)==1)
				GPIO_PINWrite_LOW(*((Sev->port)+i),*( (Sev->pins)+i));
	}

}
void HSevSeg_voidSetTwoNum(SevSeg_t* Sev1,SevSeg_t* Sev2,u8 Num){
	u8 Local_u8Ones=Num%10;
	u8 Local_u8Tens=Num/10;

	HSevSeg_voidClear(Sev1);
	HSevSeg_voidClear(Sev2);


	HSevSeg_voidSetNum(Sev1, Local_u8Ones);
	HSevSeg_voidDisable(Sev2);
	delay();

//	HSevSeg_voidClear(Sev1);
	HSevSeg_voidDisable(Sev1);
	HSevSeg_voidSetNum(Sev2, Local_u8Tens);
	delay();

//	HSevSeg_voidClear(Sev2);

	return;

}

void HSevSeg_voidClear(SevSeg_t* Sev){
	if(Sev->Common==CommonCathode)
	{

		for (u8 i=0;i<7;i++)
				GPIO_PINWrite_LOW(*((Sev->port)+i),*( (Sev->pins)+i));
	}
	else if(Sev->Common==CommonAnode)
	{

		for (u8 i=0;i<7;i++)
				GPIO_PINWrite_High(*((Sev->port)+i),*( (Sev->pins)+i));
	}

	return;

}
