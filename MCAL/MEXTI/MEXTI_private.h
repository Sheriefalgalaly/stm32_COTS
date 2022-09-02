/************************************************************/
/************************  MEXTI_private.h  *****************/
/************************ Target :STM32F4********************/
/************************ Layer:  MCAL       ****************/
/************************ Aug 31, 2022       ****************/
/***********************Author: Sherief Algalaly ************/
/************************************************************/

#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RSTR;
	u32 FSTR;
	u32 SWIER;
	u32 PR;
}EXTI_t;

typedef struct {
	u32 EXTICR1;
	u32 EXTICR2;
	u32 EXTICR3;
	u32 EXTICR4;
	u32 CMPCR;
}SYSCFG_t;

typedef union {
	SYSCFG_t stuct1;
	u32 SYSArr[5];
}SYSCFG_un;

#define MEXTI                ((volatile EXTI_t*)  0x40013C00)
#define MSYSCFG              ((volatile SYSCFG_t*) 0x40013808)
#define SYSCFG_UNion_Struct  ((volatile SYSCFG_un*)0x40013808)
#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
