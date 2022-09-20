/************************************************************/
/************************ Layer:  MCAL   ********************/
/************************  MSYSTICK_private.h  ********************/
/************************ Target :STM32F4********************/
/************************ Sep 3, 2022        ********************/
/***********************Author: Sherief Algalaly ************/
/************************************************************/


#ifndef MCAL_MSYSTICK_MSYSTICK_PRIVATE_H_
#define MCAL_MSYSTICK_MSYSTICK_PRIVATE_H_

typedef struct {
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;

}MSTK_t;

typedef enum {
	Busy,
	Idle
}status;
#define MSTK   ((volatile MSTK_t*)0xE000E010)


#define  Processor_clk    0
#define  AHB_8            1

typedef struct {
	u32	Local_OneTick;
	u32 TimesOfCounters;
	u32 ValueOfLoad;
	u8  status;
}Ticks_data_1ms;

#endif
