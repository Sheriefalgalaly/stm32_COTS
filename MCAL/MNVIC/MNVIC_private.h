/************************************************************/
/************************  MNVIC_private.h  *****************/
/************************ Target :STM32F4********************/
/************************ Layer: MCAL        ****************/
/************************ Aug 29, 2022        ***************/
/***********************Author: Sherief Algalaly ************/
/************************************************************/

#ifndef MCAL_MNVIC_MNVIC_PRIVATE_H_
#define MCAL_MNVIC_MNVIC_PRIVATE_H_

typedef struct {
	u32 ISER[32];
	u32 ICER[32];
	u32 ISPR[32];
	u32 ICPR[32];
	u32 IABR[64];
	u32 IPR [60];
}MNVIC_t;

#define MNVIC        ((volatile MNVIC_t*)0xe000e100)
#define NVIC_STIR    *((volatile u32*)MNVIC+0xe00)


#endif /* MCAL_MNVIC_MNVIC_PRIVATE_H_ */
