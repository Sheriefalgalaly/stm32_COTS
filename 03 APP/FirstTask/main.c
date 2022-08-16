#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_Interface.h"
#include "HSEVSEF_interface.h"
#include "HStepper_interface.h"
#include "KeyPad_Interface.h"
#include "HLED_interface.h"

int main(void)
{  //keypad
	static u8 KeyPad_read=0;
	u8 Keypad_mul=0;
	u8 Sev_mul=0;

	    u8 Port_Col[4]={PORTA,PORTA,PORTB,PORTC};
	    u8 Pin_Col[4]={PIN_0,PIN_1,PIN_15,PIN_15};
	    u8 Port_Raw[4]={PORTA,PORTA,PORTB,PORTC};
	    u8 Pin_Raw[4]={PIN_2,PIN_5,PIN_13,PIN_13};
    KeyPad_t k1 ={Port_Col,Pin_Col,Port_Raw,Pin_Raw};//object of KeyPad k1
  //7-seg

    u8 Port_sev[7]={PORTA,PORTA,PORTA,PORTA,PORTA,PORTA,PORTA};
    u8 Pin_sev [7]={PIN_3,PIN_4,PIN_10,PIN_6,PIN_7,PIN_8,PIN_9};


    SevSeg_t ss1={Port_sev,Pin_sev,CommonCathode,PORTC,PIN_13};//object of seseg1
    SevSeg_t ss2={Port_sev,Pin_sev,CommonCathode,PORTC,PIN_14};//objectof seveg2
 //	stepper
	u8 Steper_Port[5]={PORTB,PORTB,PORTB,PORTA,PORTB};
    u8 Steper_Pin [5]={PIN_13,PIN_15,PIN_10,PIN_11,PIN_5};
	Stepper_t stepper1 ={Steper_Port,Steper_Pin,Full_step};

//led  & Buzzer

	LED_t l1={PIN_6,PORTB,ActiveLow};
	LED_t l2={PIN_7,PORTB,ActiveLow};
	LED_t l3={PIN_8,PORTB,ActiveLow};
    LED_t Buzzer ={PIN_9,PORTB,ActiveLow};

//init RCC
    RCC_voidSysClkInit();
 //enable gpio peripheral
    RCC_voidEnablePerClk(GPIO_A);
    RCC_voidEnablePerClk(GPIO_B);
    RCC_voidEnablePerClk(GPIO_C);
//init gpio
    GPIO_INIT();

//resolution for stepper
	HStepper_voidSetRes(&stepper1, Full_step);
	while(1){
		KeyPad_read=KeyPad_voidRead(&k1);
		if (KeyPad_read == 1)
		{
			HSevSeg_voidSetNum(&ss1, 1);
		    HSevSeg_voidDisable(&ss2);
			HLED_voidTurnOff(&l3);
			HLED_voidTurnOff(&l2);
			HLED_voidTurnOn(&l1);

		}
		else if (KeyPad_read == 2)
		{
			       HSevSeg_voidSetNum(&ss1, 2);
				    HSevSeg_voidDisable(&ss2);
			       HLED_voidTurnOff(&l1);
			       HLED_voidTurnOn(&l2);

		}

		else if (KeyPad_read == 3)
		{
		       HSevSeg_voidSetNum(&ss1, 3);
			    HSevSeg_voidDisable(&ss2);
		       HLED_voidTurnOff(&l2);
		       HLED_voidTurnOn(&l3);
		}
		else if (KeyPad_read == 4)
		{
		       HSevSeg_voidSetNum(&ss1, 4);
			    HSevSeg_voidDisable(&ss2);
		       HLED_voidTurnOn(&l2);
		       HLED_voidTurnOn(&l3);
		       HLED_voidTurnOn(&l1);

		}
		else if (KeyPad_read == 5)
		{
			  HSevSeg_voidSetNum(&ss1, 5);
			    HSevSeg_voidDisable(&ss2);

			  delay_ms(1000);
     		  //display on 2 7-seg
			  do {
			  HSevSeg_voidSetTwoNum(&ss1, &ss2, 89);
			  }
             while(KeyPad_voidRead(&k1)==5);
		}
		else if (KeyPad_read == 6)
		{
		     HSevSeg_voidSetNum(&ss1, 6);
			    HSevSeg_voidDisable(&ss2);
			HLED_voidTurnOn(&Buzzer);
			if (KeyPad_voidRead(&k1)!=5)
			HLED_voidTurnOff(&Buzzer);

		}
		else if (KeyPad_read == 7)
		{

		       HSevSeg_voidSetNum(&ss1, 7);
			    HSevSeg_voidDisable(&ss2);

			HStepper_voidMoveMotorNumberofSteps(&stepper1, 200, 3, Forward);
		}
		else if (KeyPad_read == 8)
		{
		       HSevSeg_voidSetNum(&ss1, 8);
			    HSevSeg_voidDisable(&ss2);
			HStepper_voidMoveMotorNumberofSteps(&stepper1, 200, 6, Backward);

		}



    /* Loop forever */
	}
}
