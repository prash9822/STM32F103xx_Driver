/*
 * stm32f103xx.h
 *
 *  Created on: NOV 20, 2024
 *      Author: PRASHANT ANDHALE
 */
#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_
#define __vo	volatile
#include <stdint.h>
/*
 * BASE ADDRESS OF SRAM AND FLASH MEMORY
 */
#define FLASH_BASEADDDR			0x08000000U
#define SRAM1_BASEADDR			0x20000000U
#define ROM_BASE_ADDR			0x1FFFF000U       // 20 KB bytes of memory
#define SRAM					SRAM1_BASEADDR
/*
 *  AHBx And APBx Bus peripheral Base address
 */
#define PERIPH_BASEADDR 		0x40000000U
#define APB1_BASEADDR			PERIPH_BASEADDR
#define APB2_BASEADDR			0x40010000U
/*
 *  BASE ADDRESS OF ALL THE PERIPHERAL HANGING ON APB1 AND APB2 BUS.
 */
#define GPIOA_BASEADDR			(APB2_BASEADDR + 0x0800)	// BASE ADDRESS OF GPIO PORT
#define GPIOB_BASEADDR			(APB2_BASEADDR + 0xC000)
#define GPIOC_BASEADDR			(APB2_BASEADDR + 0x1000)
#define GPIOD_BASEADDR			(APB2_BASEADDR + 0x1400)
#define GPIOE_BASEADDR			(APB2_BASEADDR + 0x1800)
#define GPIOF_BASEADDR			(APB2_BASEADDR + 0x1C00)
#define GPIOG_BASEADDR			(APB2_BASEADDR + 0x2000)

#define RCC_BASEADDR			0x40021000U				   // BASE ADDRESS RESET CLOCK CONTROL REGISTER

#define I2C1_BASEADDR			(APB1_BASEADDR + 0x5400)   // BASE ADDRESS OF I2C BUS LINES
#define I2C2_BASEADDR			(APB1_BASEADDR + 0x5800)

#define SPI1_BASEADDR			(APB2_BASEADDR + 0x3000)
#define SPI2_BASEADDR			(APB1_BASEADDR + 0x3800)   // BASE ADDRESS OF SPI BUS LINES

#define USART1_BASEADDR			(APB2_BASEADDR + 0x3800)   // BASE ADDRESS OF USART BUS LINES
#define USART2_BASEADDR         (APB1_BASEADDR + 0x4400)
#define USART3_BASEADDR			(APB1_BASEADDR + 0x4800)

#define EXTI_BASEADDR			(APB2_BASEADDR + 0x0400)   // BASE ADDRESS OF EXTI INTERRUPT HANDLER
#define AFIO_BASEADDR           (APB2_BASEADDR + 0x0000)   // BASE ADDRESS FOR ALTERNATE FUNCTION INPUT OUTPUT REGISTER
/*
 *  PERIPHERAL REGISTER DEFINATION STRUCTURE
 */
typedef struct
{
	__vo uint32_t CRL;  	 /* Port configuration register low				Address offset: 0x00*/
	__vo uint32_t CRH;	 /* Port configuration register high			Address offset: 0x04*/
	__vo uint32_t IDR;	 /* Port input data register					Address offset: 0x08*/
	__vo uint32_t ODR;   	 /* Port output data register 					Address offset: 0x0C*/
	__vo uint32_t BSRR;	 /* Port bit set/reset register 		    	Address offset: 0x10*/
	__vo uint32_t BRR;	 /* Port bit reset register				        Address offset: 0x14*/
	__vo uint32_t LCKR;	 /* Port configuration lock register			Address offset: 0x18*/

}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t RCC_CR;         /* Clock control register   					Address offset: 0x00 	*/
	__vo uint32_t RCC_CFGR;		  /* Clock configuration register				Address offset: 0x04  	*/
	__vo uint32_t RCC_CIR ;		  /* Clock interrupt register					Address offset: 0x08	*/
	__vo uint32_t RCC_APB2RSTR;	  /* APB2 peripheral reset register				Address offset: 0x0C	*/
	__vo uint32_t RCC_APB1RSTR;	  /* APB1 peripheral reset register				Address offset: 0x10	*/
	__vo uint32_t RCC_AHBENR;	  /* AHB peripheral clock enable register		Address offset: 0x14	*/
	__vo uint32_t RCC_APB2ENR;	  /* APB2 peripheral clock enable register		Address offset: 0x18	*/
	__vo uint32_t RCC_APB1ENR;	  /* APB1 peripheral clock enable register		Address offset: 0x1C	*/
	__vo uint32_t RCC_BDCR;		  /* Backup domain control register		        Address offset: 0x20	*/
	__vo uint32_t RCC_CSR;		  /* Control/status register				    Address offset: 0x24	*/

}RCC_RegDef_t;
/*
 *  PERIPHERAL REGISTER DEFINATION STRUCTURE FOR EXTI
 */
typedef struct
{
	__vo uint32_t IMR;        	 /* Interrupt mask register 					Address offset: 0x00 	*/
	__vo uint32_t EMR;		 /* Event mask register        				Address offset: 0x04  	*/
	__vo uint32_t RTSR ;	         /* Rising trigger selection register			Address offset: 0x08	*/
	__vo uint32_t FTSR;	     	 /* Falling trigger selection register 		Address offset: 0x0C	*/
	__vo uint32_t SWIER;	  	 /* Software interrupt event register			Address offset: 0x10	*/
	__vo uint32_t PR;	         /* Pending register							Address offset: 0x14	*/


}EXTI_RegDef_t;
typedef struct
{
	__vo uint32_t AFIO_EVCR;        /* Event control register								Address offset: 0x00 	*/
	__vo uint32_t AFIO_MAPR;	/* AF remap and debug I/O configuration register        Address offset: 0x04  	*/
	__vo uint32_t AFIO_EXTICR[3];	/* External interrupt configuration register [1-4]	    Address offset: 0x08-0x014	*/
	__vo uint32_t AFIO_MAPR2;	/* AF remap and debug I/O configuration register2		Address offset 	0x1C	*/

}AFIO_RegDef_t;

#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*)GPIOG_BASEADDR)

#define RCC	  ((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI  ((EXTI_RegDef_t*)EXTI_BASEADDR)
/*
 *  CLOCK ENABLE MICROS FOR GPIOx PHERIPHERALS
 */
#define GPIOA_PCLK_EN()		(RCC->RCC_APB2ENR |= 1<<2)	// GPIOA PERIPHERAL CLOCK ENABLE REGISTER
#define GPIOB_PCLK_EN()		(RCC->RCC_APB2ENR |= 1<<3)	// GPIOB PERIPHERAL CLOCK ENABLE REGISTER
#define GPIOC_PCLK_EN()		(RCC->RCC_APB2ENR |= 1<<4)	// GPIOC PERIPHERAL CLOCK ENABLE REGISTER
#define GPIOD_PCLK_EN()		(RCC->RCC_APB2ENR |= 1<<5)	// GPIOD PERIPHERAL CLOCK ENABLE REGISTER
#define GPIOE_PCLK_EN()		(RCC->RCC_APB2ENR |= 1<<6)	// GPIOE PERIPHERAL CLOCK ENABLE REGISTER
#define GPIOF_PCLK_EN()		(RCC->RCC_APB2ENR |= 1<<7)	// GPIOF PERIPHERAL CLOCK ENABLE REGISTER
#define GPIOG_PCLK_EN()		(RCC->RCC_APB2ENR |= 1<<8)	// GPIOG PERIPHERAL CLOCK ENABLE REGISTER
/*
 *   CLOCK ENABLE FOR AFIO PHERIPHERALS
 */
#define AFIO_PCLK_EN()		(RCC->>RCC_APB2ENR |=1<<0)
/*
 *  CLOCK ENABLE MICROS FOR I2Cx PHERIPHERALS
 */
#define I2C1_PCLK_EN()       (RCC->RCC_APB1ENR |= 1<<21)  // I2C1 PERIPHERAL CLOCK ENABLE REGISTER
#define I2C2_PCLK_EN()		 (RCC->RCC_APB1ENR |= 1<<22)  // I2C2 PERIPHERAL CLOK  ENABLE REGISTER
/*
 *  CLOCK ENABLE MICROS FOR SPIx PHERIPHERALS
 */
#define SPI1_PCLK_EN()       (RCC->RCC_APB2ENR |= 1<<12)  // SPI1 PERIPHERAL CLOCK ENABLE REGISTER
#define SPI2_PCLK_EN()		 (RCC->RCC_APB1ENR |= 1<<14)  // SPI22 PERIPHERAL CLOK  ENABLE REGISTER
/*
 *  CLOCK ENABLE MICROS FOR USARTx PHERIPHERALS
 */
#define USART1_PCLK_EN()       (RCC->RCC_APB2ENR |= 1<<14)  // USART1 PERIPHERAL CLOCK ENABLE REGISTER
#define USART2_PCLK_EN()	   (RCC->RCC_APB1ENR |= 1<<17)  // USART2 PERIPHERAL CLOK  ENABLE REGISTER
#define USART3_PCLK_EN()       (RCC->RCC_APB1ENR |= 1<<18)  // USART3 PERIPHERAL CLOCK ENABLE REGISTER
/*
 *  CLOCK DISABLE MICROS FOR GPIOx PHERIPHERALS
 */
#define GPIOA_PCLK_DI()		(RCC->RCC_APB2ENR &= ~(1<<2))	// GPIOA PERIPHERAL CLOCK DISABLE REGISTER
#define GPIOB_PCLK_DI()		(RCC->RCC_APB2ENR &= ~(1<<3))	// GPIOB PERIPHERAL CLOCK DISABLE REGISTER
#define GPIOC_PCLK_DI()		(RCC->RCC_APB2ENR &= ~(1<<4))	// GPIOC PERIPHERAL CLOCK DISABLE REGISTER
#define GPIOD_PCLK_DI()		(RCC->RCC_APB2ENR &= ~(1<<5))	// GPIOD PERIPHERAL CLOCK DISABLE REGISTER
#define GPIOE_PCLK_DI()		(RCC->RCC_APB2ENR &= ~(1<<6))	// GPIOE PERIPHERAL CLOCK DISABLE REGISTER
#define GPIOF_PCLK_DI()		(RCC->RCC_APB2ENR &= ~(1<<7))	// GPIOF PERIPHERAL CLOCK DIAABLE REGISTER
#define GPIOG_PCLK_DI()		(RCC->RCC_APB2ENR &= ~(1<<8))	// GPIOG PERIPHERAL CLOCK DISABLE REGISTER
/*
 *  CLOCK DISABLE MICROS FOR I2Cx PHERIPHERALS
 */
#define I2C1_PCLK_DI()       (RCC->RCC_APB1ENR &= ~(1<<21))  // I2C1 PERIPHERAL CLOCK DISBLE REGISTER
#define I2C2_PCLK_DI()		 (RCC->RCC_APB1ENR &= ~(1<<22))// I2C2 PERIPHERAL CLOK  DISABLE REGISTER
/*
 *  CLOCK DISABLE MICROS FOR SPIx PHERIPHERALS
 */
#define SPI1_PCLK_DI()       (RCC->RCC_APB2ENR &= ~(1<<12))  // SPI1 PERIPHERAL CLOCK DISABLE REGISTER
#define SPI2_PCLK_DI()		 (RCC->RCC_APB1ENR &= ~(1<<14))  // SPI22 PERIPHERAL CLOK DISABLE REGISTER
/*
 *  CLOCK DISABLE MICROS FOR USARTx PHERIPHERALS
 */
#define USART1_PCLK_DI()       (RCC->RCC_APB2ENR |= ~(1<<14))   // USART1 PERIPHERAL CLOCK DISABLE REGISTER
#define USART2_PCLK_DI()	   (RCC->RCC_APB1ENR |= ~(1<<17))   // USART2 PERIPHERAL CLOK  DISABLE REGISTER
#define USART3_PCLK_DI()       (RCC->RCC_APB1ENR |= ~(1<<18))   // USART3 PERIPHERAL CLOCK DISABLE REGISTER
/*
 *  MACROS TO RESET GPIO PERIPHERAL
 */
#define GPIOA_REG_RESET() 		do{	 RCC->RCC_APB2RSTR|= 1<< 2 ; RCC->RCC_APB2RSTR&= ~(1<< 2);}while(0)
#define GPIOB_REG_RESET()		do{	 RCC->RCC_APB2RSTR|= 1<< 3 ; RCC->RCC_APB2RSTR&= ~(1<< 3);}while(0)
#define GPIOC_REG_RESET()		do{	 RCC->RCC_APB2RSTR|= 1<< 4 ; RCC->RCC_APB2RSTR&= ~(1<< 4);}while(0)
#define GPIOD_REG_RESET()		do{	 RCC->RCC_APB2RSTR|= 1<< 5 ; RCC->RCC_APB2RSTR&= ~(1<< 5);}while(0)
#define GPIOE_REG_RESET()		do{	 RCC->RCC_APB2RSTR|= 1<< 6 ; RCC->RCC_APB2RSTR&= ~(1<< 6);}while(0)
#define GPIOF_REG_RESET()		do{	 RCC->RCC_APB2RSTR|= 1<< 7 ; RCC->RCC_APB2RSTR&= ~(1<< 7);}while(0)
#define GPIOG_REG_RESET()		do{	 RCC->RCC_APB2RSTR|= 1<< 8 ; RCC->RCC_APB2RSTR&= ~(1<< 8);}while(0)
/*
 *  SOME GENERIC MACROS
 */
#define ENABLE 			1
#define DISABLE			0
#define SET 			ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET    SET
#define GPIO_PIN_RESET	RESET



#endif /* INC_STM32F103XX_H_ */
