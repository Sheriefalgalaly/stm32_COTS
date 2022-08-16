/**************************************************************************************************/
/*                              MCAL :HLCD_Program  ***********************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
 /******************************  Created on: Jul 31, 2022 **************************************/
/************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"
#include "HLCD_Config.h"
#include "HLCD_Interface.h"
#include "HLCD_Private.h"
static void _delay_ms(int hh){
	for (int i=0 ;i<hh*100;i++)
		asm("nop");
}
static void _delay_us(int h){
	for (int i=0 ;i<h;i++)
		asm("nop");
}
static void CLCD_voidSendCommand(HLCD_t* lcd,u8 Copy_u8Command){
#if Type_mode == CLCD_8_mode
	/*Set RS pin to low for command*/
	GPIO_PINSWrite_LOW(CLCD_CTRL_PORT, 1<<HLCD_RS_PIN);

	/*Set RW pin to low for write*/
	GPIO_PINSWrite_LOW(CLCD_CTRL_PORT,1<<HLCD_RW_PIN);

	/*Set command to data pins*/
	GPIO_WritePortValue(CLCD_DATA_PORT, 1<<HLCD_DATA_PIN0|1<<HLCD_DATA_PIN11<<HLCD_DATA_PIN2 |1<<HLCD_DATA_PIN3 |1<<HLCD_DATA_PIN4 |1<<HLCD_DATA_PIN5 |1<<HLCD_DATA_PIN6 |1<<HLCD_DATA_PIN7,Copy_u8Command);

	/*Send enable pulse*/
	GPIO_PINSSET(CLCD_CTRL_PORT, 1<<HLCD_E_PIN);
	_delay_ms();
	GPIO_PINSReSET(CLCD_CTRL_PORT, 1<<HLCD_E_PIN);
#elif Type_mode ==CLCD_4_mode
	u8 Copy_4bitmost =Copy_u8Command  ;
	u8 Copy_4bitleast=Copy_u8Command;


	/*Set RS pin to low for command*/
	GPIO_PINWrite_LOW(lcd->CtrlPort[HLCD_RS_PIN], lcd->CtrlPins[HLCD_RS_PIN]);

	/*Set RW pin to low for write*/
	GPIO_PINWrite_LOW(lcd->CtrlPort[HLCD_RW_PIN], lcd->CtrlPins[HLCD_RW_PIN]);

	/*first Set command to data pins most bits*/
	for (u8 i=0;i<4;i++){
		if (GET_BIT(Copy_4bitmost,i+4)==1)
			GPIO_PINWrite_High(lcd->DataPort[i], lcd->DataPins[i]);
		else
			GPIO_PINWrite_LOW(lcd->DataPort[i], lcd->DataPins[i]);
	}

	/*After sendigng first com most value high enable pin then disable*/

	GPIO_PINWrite_High(lcd->CtrlPort[HLCD_En_PIN], lcd->CtrlPins[HLCD_En_PIN]);
	_delay_ms(2);
	GPIO_PINWrite_LOW(lcd->CtrlPort[HLCD_En_PIN], lcd->CtrlPins[HLCD_En_PIN]);
	_delay_ms(1);

	/*Set RS pin to low for command*/
		GPIO_PINWrite_LOW(lcd->CtrlPort[HLCD_RS_PIN], lcd->CtrlPins[HLCD_RS_PIN]);

		/*Set RW pin to low for write*/
		GPIO_PINWrite_LOW(lcd->CtrlPort[HLCD_RW_PIN], lcd->CtrlPins[HLCD_RW_PIN]);

	for (u8 i=0;i<4;i++){
		if (GET_BIT(Copy_4bitleast,i)==1)
			GPIO_PINWrite_High(lcd->DataPort[i], lcd->DataPins[i]);
		else
			GPIO_PINWrite_LOW(lcd->DataPort[i], lcd->DataPins[i]);
	}

	/*second Set command to data pins*/

	GPIO_PINWrite_High(lcd->CtrlPort[HLCD_En_PIN], lcd->CtrlPins[HLCD_En_PIN]);
	_delay_ms(2);
	GPIO_PINWrite_LOW(lcd->CtrlPort[HLCD_En_PIN], lcd->CtrlPins[HLCD_En_PIN]);
#endif

}

static void CLCD_voidSendData(HLCD_t* lcd,u8 Copy_u8Data){
#if Type_mode == CLCD_8_mode
	/*Set RS pin to high for data*/
	GPIO_PINSWrite_High(CLCD_CTRL_PORT, 1<<HLCD_RS_PIN);
	/*Set RW pin to low for write*/
	GPIO_PINSWrite_LOW(CLCD_CTRL_PORT,1<<HLCD_RW_PIN);

	/*Set Data to data pins*/
	GPIO_WritePortValue(CLCD_DATA_PORT, 1<<HLCD_DATA_PIN0|1<<HLCD_DATA_PIN11<<HLCD_DATA_PIN2 |1<<HLCD_DATA_PIN3 |1<<HLCD_DATA_PIN4 |1<<HLCD_DATA_PIN5 |1<<HLCD_DATA_PIN6 |1<<HLCD_DATA_PIN7,Copy_u8Command);

	/*Send enable pulse*/
	GPIO_PINSSET(CLCD_CTRL_PORT, 1<<HLCD_E_PIN);
	_delay_ms(2);
	GPIO_PINSReSET(CLCD_CTRL_PORT, 1<<HLCD_E_PIN);

#elif Type_mode ==CLCD_4_mode

	u8 Copy_4bitmost= Copy_u8Data ;
	u8 Copy_4bitleast=Copy_u8Data ;

	/*Set RS pin to high for data*/
	GPIO_PINWrite_High(lcd->CtrlPort[HLCD_RS_PIN], lcd->CtrlPins[HLCD_RS_PIN]);

	/*Set RW pin to low for write*/
	GPIO_PINWrite_LOW(lcd->CtrlPort[HLCD_RW_PIN], lcd->CtrlPins[HLCD_RW_PIN]);
	/* write data */
	for (u8 i=0;i<4;i++){
		if (GET_BIT(Copy_4bitmost,i+4)==1)
			GPIO_PINWrite_High(lcd->DataPort[i], lcd->DataPins[i]);
		else
			GPIO_PINWrite_LOW(lcd->DataPort[i], lcd->DataPins[i]);
	}


	GPIO_PINWrite_High(lcd->CtrlPort[HLCD_En_PIN], lcd->CtrlPins[HLCD_En_PIN]);
	_delay_ms(2);
	GPIO_PINWrite_LOW(lcd->CtrlPort[HLCD_En_PIN], lcd->CtrlPins[HLCD_En_PIN]);
	_delay_ms(1);
	/*Set RS pin to high for data*/
		GPIO_PINWrite_High(lcd->CtrlPort[HLCD_RS_PIN], lcd->CtrlPins[HLCD_RS_PIN]);

		/*Set RW pin to low for write*/
		GPIO_PINWrite_LOW(lcd->CtrlPort[HLCD_RW_PIN], lcd->CtrlPins[HLCD_RW_PIN]);

	for (u8 i=0;i<4;i++){
		if (GET_BIT(Copy_4bitleast,i)==1)
			GPIO_PINWrite_High(lcd->DataPort[i], lcd->DataPins[i]);
		else
			GPIO_PINWrite_LOW(lcd->DataPort[i], lcd->DataPins[i]);
	}


	/*Send enable pulse*/
	GPIO_PINWrite_High(lcd->CtrlPort[HLCD_En_PIN], lcd->CtrlPins[HLCD_En_PIN]);
	_delay_ms(2);
	GPIO_PINWrite_LOW(lcd->CtrlPort[HLCD_En_PIN], lcd->CtrlPins[HLCD_En_PIN]);
#endif

}

void CLCD_voidInit(HLCD_t* lcd){
#if Type_mode ==CLCD_8_mode
	/*Wait for more than 30 ms*/
	_delay_ms();

	/*Function set command: 2 lines, 5*8 Font size*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control: display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*Clear display*/
	CLCD_voidSendCommand(1);

#elif Type_mode ==CLCD_4_mode

	_delay_ms(100);
	CLCD_voidSendCommand(lcd,0x30);
	CLCD_voidSendCommand(lcd,0x80);
	_delay_ms(1);
	CLCD_voidSendCommand(lcd,0x00);
	CLCD_voidSendCommand(lcd,0x30);
	_delay_ms(1);
	CLCD_voidSendCommand(lcd,0x00);
	CLCD_voidSendCommand(lcd,0x10);


#endif

}
void CLCD_voidSendString(HLCD_t* lcd,const char* Copy_pcString){
	u8 count_char=0;
		while (Copy_pcString[count_char]!='\0')
		{
			CLCD_voidSendData(lcd,Copy_pcString[count_char]);
			count_char++;


		}

}
//void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos){
//	u8 Local_u8Address;
//		if (Copy_u8XPos==0){
//			Local_u8Address=Copy_u8YPos;
//		}
//		else if (Copy_u8XPos==1){
//			Local_u8Address=Copy_u8YPos+0x40;
//
//		}
//
//		CLCD_voidSendCommand(Local_u8Address|=1<<7); //set DDRAM Address
//
//
//
//}
//
