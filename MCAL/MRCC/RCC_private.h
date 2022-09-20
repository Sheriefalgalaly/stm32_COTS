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

typedef enum{
	AHBNopres=1,
	AHBPres_2 =4,
	AHBPres_4,
	AHBPres_8,
	AHBPres_16

}AHB_pres;

typedef enum {
	SystemClk_no=1,
	SystemClk_2 =8,
	SystemClk_4,
	SystemClk_8,
	SystemClk_16,
	SystemClk_64 //...
}System_pres_t;
#define    RCC_BASE_ADD             0x40023800
#define    RCC               ((volatile RCC_t*)RCC_BASE_ADD)


   /*RCC-CR*/

#define HSE_ON     16
#define HSE_RDY    17
#define HSE_BYP    18
#define HSION      0
#define HSI_RDY    1
#define PLLON      24
#define CSSON      19

   #define SW0     0
   #define SW1     1
#define SYSCFGEN   14
#define PWREN      28

#endif
/* MCAL_MSYSTICK_MSYSTICK_PRIVATE_H_ */
/**___________________________________________________________________*
 * __________________________config of stm32 for pll _________________*
 * ___________________________________________________________________*
 * to turn on pll

14 SYSCFGEN: System configuration controller clock enable  -->APB2ENR
28 PWREN: Power interface clock enable                     --> APB1ENR

HSE ON
Wait until HSE is ready

write PLL parameters

        WRITE_REG(RCC->PLLCFGR, (RCC_OscInitStruct->PLL.PLLSource                                            | \
                                 RCC_OscInitStruct->PLL.PLLM                                                 | \
                                 (RCC_OscInitStruct->PLL.PLLN << RCC_PLLCFGR_PLLN_Pos)             | \
                                 (((RCC_OscInitStruct->PLL.PLLP >> 1U) - 1U) << RCC_PLLCFGR_PLLP_Pos) | \
                                 (RCC_OscInitStruct->PLL.PLLQ << RCC_PLLCFGR_PLLQ_Pos)));


#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

pres1 cfgr = 7  //divided by 16
pres2 cfgr = 7  //divided by 16

select pll as sys clk

pres1   = 4
pres2   =0
 *
 */

