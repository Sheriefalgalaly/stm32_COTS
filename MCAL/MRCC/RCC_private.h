/**************************************************************************************************/
/*                              MCAL :RCC_PRIVATE *******************************************/
/*****                          target controller :STM32f401CCU6 *********************************/
/********************           AUTHOR : Sherief Algalaly ****************************************/
/************************************************************************************************/ 

#ifndef  RCC_PRIVATE_H
#define  RCC_PRIVATE_H



typedef struct {

u32	   CR             ;
u32	   PLLCFGR        ;
u32	   CFGR           ;
u32	   CIR            ;
u32    AHB1RSTR       ;
u32    AHB2RSTR       ;
u32    reserved1      ;
u32	   reserved2      ;
u32    APB1RSTR       ;
u32    APB2RSTR       ;
u32    reserved3      ;
u32	   reserved4      ;
u32	   AHB1ENR        ;
u32    AHB2ENR        ;
u32    reserved5      ;
u32	   reserved6      ;
u32    APB1ENR        ;
u32    APB2ENR        ;
u32    reserved77     ;
u32	   reserved88     ;
u32    AHB1LPENR      ;
u32    AHB2LPENR      ;
u32    reserved13     ;
u32	   reserved14     ;
u32    APB1LPENR      ;
u32    APB2LPENR      ;
u32    reserved133    ;
u32	   reserved144    ;
u32    BDCR           ;
u32    CSR            ;
u32	   reserved147     ;
u32	   reserved140     ;
u32    SSCGR          ;
u32    PLLI2SCFGR     ;
u32    DCKCFGR        ;


}RCC_t;


#define    RCC_BASE_ADD             0x40023800
#define    RCC               ((volatile RCC_t*)RCC_BASE_ADD)


   /*RCC-CR*/

#define HSE_ON     16
#define HSE_BYP    18
#define HSION      0
#define PLLON      25
#define CSSON      19

   #define SW0     0
   #define SW1     1


#endif

