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
	u8  IPR [240];
}MNVIC_t;

typedef struct {
	u8 ShiftedLif_Group;

}Prio_config;
typedef struct {
	u32 CPUID;
	u32 ICSR ;
	u32 VTOR ;
	u32 AIRCR ;
	u32 SCR ;
	u32 CCR;
	u32 SHPR1;
	u32 SHPR2;
	u32 SHPR3 ;
	u32 SHCSR ;
	u32 CFSR ;
	u32 HFSR ;
	u32 MMAR;
	u32 BFAR;
	u32 AFSR;
}SCB_t;
#define MNVIC        ((volatile MNVIC_t*)0xe000e100)
#define NVIC_STIR    *((volatile u32*)MNVIC+0xe00)
#define SCB          ((volatile SCB_t*)0xE000ED00)

#endif /* MCAL_MNVIC_MNVIC_PRIVATE_H_ */
