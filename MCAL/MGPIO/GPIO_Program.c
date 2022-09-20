#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "GPIO_Config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

	u32 MODER[3] = { PORTA_MODER , PORTB_MODER ,PORTC_MODER};
	u32 TYPER[3] = {PORTA_TYPER  , PORTB_TYPER ,PORTC_TYPER};
    u32 SPEEDR[3] ={PORTA_SPEEDR,PORTB_SPEEDR,PORTB_SPEEDR};
    u32 PUPDR [3] ={PORTA_PUDR,PORTB_PUDR  ,PORTC_PUDR};
	PORT_t* PORTS[3]={PORTA_REG,PORTB_REG,PORTC_REG};


	/*forbidden pins
	 * B2,3,4
	 * A13,14,15*/
void GPIO_INIT(void){


	for (u8 i=0 ;i<3 ;i++){
		PORTS[i]->MODER       |= MODER[i];
	}
	for (u8 i=0 ;i<3 ;i++){
			PORTS[i]->OTYPER  |= TYPER[i];
		}
	for (u8 i=0 ;i<3 ;i++){
			PORTS[i]->OSPEEDR |= SPEEDR[i];
		}
	for (u8 i=0 ;i<3 ;i++){
			PORTS[i]->PUPDR   |= PUPDR[i];
		}


}
void GPIO_PINWrite_High(u8 port,u8 PINS){ //write in multiple pin in same fun
 //switch ports
	switch (port){
	case PORTA :
		if (PINS != 13 &&PINS != 14)
	             PORTA_REG->ODR    |= 1<<PINS;                     //store value after read the reg the assign ,,slow somehow
	             break;
	case PORTB :
		if (PINS != 3 &&PINS != 4)
	             PORTB_REG->ODR    |= 1<<PINS;
	            break;
	case PORTC :
		if (PINS >12 && PINS <16)
			    PORTC_REG->ODR     |= 1<<PINS;
		        break;
	}
}

void GPIO_PINSET(u8 port,u8 PIN){ //write in multiple pin in same fun //more quick
 //switch ports
	switch (port){
		case PORTA :
					PORTA_REG->BSRR_S = PIN;                    // write value direct without read the register and assign then store
					   break;
		case PORTB :

					PORTB_REG->BSRR_S = PIN;
					   break;
		case PORTC :
					PORTC_REG->BSRR_S = PIN;
					  break;
		}



}
void GPIO_PINReSET(u8 port,u8 PINS){ //write in multiple pin in same fun
 //switch ports
		switch (port){
			case PORTA :
						  PORTA_REG->BSRR_R = PINS;                     //write code to ensure the pins
						   break;
			case PORTB :

						  PORTB_REG->BSRR_R = PINS;
						   break;
			case PORTC :
						  PORTC_REG->BSRR_R = PINS;
						  break;
			}



}
void GPIO_PINWrite_LOW(u8 port,u8 PINS){ //write in multiple pin in same fun
 //switch ports
	switch (port){
	case PORTA :
	     	PORTA_REG->ODR &= ~(1<<PINS);                     //write code to ensure the pins
	             break;
	case PORTB :
		    PORTB_REG->ODR &= ~(1<<PINS);
	            break;
	case PORTC :
	    	PORTC_REG->ODR &= ~(1<<PINS);
		        break;
	}





}




/*
u16 GPIO_whichPINs(u8 inputRegister , u16 PINS){  //return bits shifted right if bit 5 ,10 input ,,convert it to two bits at LSB to be 00,01,10,11
	u8 index =0;
	u8 pins[16];   //create array to fill indexes of pins
	u16 val_pins=0;
for(u8 i =0 ; i<16 ;i++){  //fill array with index of pins we need to read
	if (GET_BIT(PINS,i))
	{
  pins[index]=i;
  index++;
	}

}
switch(inputRegister){  //select any port
       case PORTA :
    	   for (u8 k=0 ;k<index ;k++)
    	   	if(GET_BIT(PORTA_REG->IDR,pins[k]))  //read register with index of pins we need
    	   		val_pins |= 1<<k;    //value OR-ing with one shifted right by new index
       case PORTB :
    	   for (u8 k=0 ;k<index ;k++)
    	   	if(GET_BIT(PORTB_REG->IDR,pins[k]))
    	   		val_pins |= 1<<k;
       case PORTC :
    	   for (u8 k=0 ;k<index ;k++)
    	   	if(GET_BIT(PORTC_REG->IDR,pins[k]))
    	   		val_pins |= 1<<k;

}

return val_pins;
}

u16  GPIO_PINSRead(u8 port ,u16 PINS){    //return read value from pin or pins
   switch (port)
   {
   case PORTA : return GPIO_whichPINs(PORTA,PINS);     break; //calling function to return the value of register of pins we need to read
   case PORTB : return GPIO_whichPINs(PORTB,PINS);     break; //calling function to return the value of register of pins we need to read
   case PORTC : return GPIO_whichPINs(PORTC,PINS);     break; //calling function to return the value of register of pins we need to read
   }
}
*/
u8  GPIO_PINRead(u8 port ,u8 PIN){
	  switch(port)
	  {
	  case PORTA  : return GET_BIT(PORTA_REG->IDR,PIN);
	  case PORTB  : return GET_BIT(PORTB_REG->IDR,PIN);
	  case PORTC  : return GET_BIT(PORTC_REG->IDR,PIN);
	  default     : return   0;
	  }

}

void GPIO_voidPinPUDR(u8 port ,u8 PIN,u8 mode){
	PORTS[port]->PUPDR       &= ~(3<< (2*PIN));  //clear bits
	PORTS[port]->PUPDR       |= mode << (2*PIN);
}

void GPIO_voidTooglePin(u8 port ,u8 PIN){
	TOGGLE_BIT(PORTS[port]->ODR,PIN);
}



