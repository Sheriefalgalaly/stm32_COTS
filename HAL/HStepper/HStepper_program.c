/*
 * HStepper_program.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Admin
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/MGPIO/GPIO_Interface.h"
#include "HStepper_interface.h"
#include "HStepper_private.h"
void delay_stepper(int i){
	for(int j=0;j<i*10;j++) asm("nop");
}

void HStepper_voidSetRes(Stepper_t* s ,enum Resolution Res){
      /*switch case */
	  switch(Res){
	  case Full_step :      GPIO_PINWrite_LOW(s->Port[0], s->Pins[0]);   //ms1
	  	  	  	  	        GPIO_PINWrite_LOW(s->Port[1], s->Pins[1]);   //ms2
	  	  	  	  	        GPIO_PINWrite_LOW(s->Port[2], s->Pins[2]);   //ms3
	  	    break;
	  case Half_step :      GPIO_PINWrite_High(s->Port[0],s->Pins[0]);   //ms1
	  	  	  	  	        GPIO_PINWrite_LOW(s->Port[1], s->Pins[1]);   //ms2
	  	  	  	  	        GPIO_PINWrite_LOW(s->Port[2], s->Pins[2]);   //ms3
	  	    break;
	  case Quarter_Step :   GPIO_PINWrite_LOW(s->Port[0], s->Pins[0]);     //ms1
	  	  	  	  	  	  	GPIO_PINWrite_High(s->Port[1],s->Pins[1]);     //ms2
	  	  	  	  	        GPIO_PINWrite_LOW(s->Port[2], s->Pins[2]);     //ms3
	  	    break;
	  case Eighth_step :    GPIO_PINWrite_High(s->Port[0], s->Pins[0]);     //ms1
							GPIO_PINWrite_High(s->Port[1], s->Pins[1]);     //ms2
	  	  	  	  	        GPIO_PINWrite_LOW(s->Port[2],  s->Pins[2]);     //ms3
	  	    break;
	  case sixteenth_step : GPIO_PINWrite_High(s->Port[0], s->Pins[0]);
							GPIO_PINWrite_High(s->Port[1], s->Pins[1]);
							GPIO_PINWrite_High(s->Port[2], s->Pins[2]);
	  	    break;
	  }

}

static void HStepper_voidmovemotorSpeed(Stepper_t* s,u16 Speed){
     /*pulses*/
     GPIO_PINWrite_High(s->Port[3], s->Pins[3]);
     GPIO_PINWrite_LOW(s->Port[3], s->Pins[3]);
     delay_stepper(Speed); //~1ms

}
void HStepper_voidMoveMotorNumberofSteps(Stepper_t* s,u16 Steps,u16 Speed ,enum Direction d1){
    /*check the direction */
    if (d1)
   	 GPIO_PINWrite_High(s->Port[4], s->Pins[4]);  //d1 = 1 ,forward
    else
   	 GPIO_PINWrite_LOW(s->Port[4], s->Pins[4]); //d1 =0 ,backward

    while (Steps --){
    	HStepper_voidmovemotorSpeed(s,Speed);
    }

}
