/************************************************************/
/************************  MEXTI_interface.h  ***************/
/************************ Target :STM32F4********************/
/************************ Layer: MCAL        ****************/
/************************ Aug 31, 2022        ***************/
/***********************Author: Sherief Algalaly ************/
/************************************************************/

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_

typedef struct{
	u8 Line;
	u8 Port;
	u8 Trigger_Rising;
	u8 Trigger_Falling;
}EXTI_Config_t;

typedef enum {
	Disable_EXTI,
	Enable_EXTI
}Enabling_Line;

typedef enum {
	EXTL0,
	EXTL1,
	EXTL2,
	EXTL3,
	EXTL4,
	EXTL5,
	EXTL6,
	EXTL7,
	EXTL8,
	EXTL9,
	EXTL10,
	EXTL11,
	EXTL12,
	EXTL13,
	EXTL14,
	EXTL15,
	EXTL16,
	EXTL17,
	EXTL18,
	EXTL19,
	EXTL20,
	EXTL21,
	EXTL22,
	EXTL23,
}EXTL_Sel;
void MEXTI_voidInit(void);
void MEXTI_voidEnableLine(EXTI_Config_t*);
void MEXTI_voidDisableLine(EXTI_Config_t*);
void MEXTI_voidSETSoftwaretrigger(EXTI_Config_t*);
void MEXTI_voidRESETSoftwaretrigger(EXTI_Config_t*);
void MEXTI_voidSetTrigger(EXTI_Config_t*);
void MEXTI_voidSetCallBack(EXTI_Config_t*,void (*ptr)(void));
void MEXTI_voidSetPrioritiesOfEXTI9_5(u8*);    // pass array of u8 , ex for array u8 array[5]={8,9,5,6,7};

#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
