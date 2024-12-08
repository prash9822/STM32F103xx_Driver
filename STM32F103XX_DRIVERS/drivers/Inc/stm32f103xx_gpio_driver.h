/*
 * stm32f103xx_gpio_driver.h
 *
 *  Created on: NOV 24, 2024
 *      Author: PRASHANT ANDHALE
 */

#ifndef INC_STM32F103XX_GPIO_DRIVER_H_
#define INC_STM32F103XX_GPIO_DRIVER_H_

#include "stm32f103xx.h"

typedef struct
{

	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinType;
//	uint8_t GPIO_PinSpeed;					// DEFAULT SET GPIO PIN TO MAXIMUM  OUTPUT SPEED
	uint8_t GPIO_PinAltFunMode;

}GPIO_Pin_Config_t;

typedef struct
{
	//pointer to hold base address of GPIO peripheral
	GPIO_RegDef_t 	  *pGPIOx;   		   	  //this hold the base address of the port to which pin belong
	GPIO_Pin_Config_t *GPIO_Pin_Config;  	  // this hold GPIO pin configuration structure

}GPIO_Handle_t;
/*
 * 	GPIO PIN NO
 */
#define GPIO_PIN_NO_0	0
#define GPIO_PIN_NO_1	1
#define GPIO_PIN_NO_2	2
#define GPIO_PIN_NO_3	3
#define GPIO_PIN_NO_4	4
#define GPIO_PIN_NO_5	5
#define GPIO_PIN_NO_6	6
#define GPIO_PIN_NO_7	7
#define GPIO_PIN_NO_8	8
#define GPIO_PIN_NO_9	9
#define GPIO_PIN_NO_10	10
#define GPIO_PIN_NO_11	11
#define GPIO_PIN_NO_12	12
#define GPIO_PIN_NO_13	13
#define GPIO_PIN_NO_14	14
#define GPIO_PIN_NO_15	15
/*
 * 	GPIO POSSIBLE PIN MODE
 */
#define GPIO_MODE_INPUT_PU_PD  			2   // : Input with pull-up / pull-down
#define GPIO_MODE_OUTPUT_PP    			0   // General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD    			1  // General purpose output open-drain
#define GPIO_MODE_AF_PP        			2   // Alternate function output push-pull
#define GPIO_MODE_AF_OD        			3  // Alternate function output open-drain
#define GPIO_MODE_ANALOG       			0   // Analog mode
#define GPIO_MODE_INPUT_FLOATING   	    1   // Floating input mode
/*
 * Define the GPIO for the intrupt
 */
#define GPIO_MODE_IT_FT     4
#define GPIO_MODE_IT_RT     5
#define GPIO_MODE_IT_RFT    6
/* GPIO Pin Speed Options */
#define GPIO_SPEED_LOW    	   1
#define GPIO_SPEED_MEDIUM 	   2
#define GPIO_SPEED_FAST  	   3

/* GPIO Pin Input or Output type */
#define GPIO_INPUT		0
#define GPIO_OUTPUT  	3
/*
 * peripheral clock enable
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
/*
 * Init and deInit
 */
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
/*
 * Data Read and Write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber, uint16_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
/*
 * Handling the IRQ or ISR
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);



#endif /* INC_STM32F103XX_GPIO_DRIVER_H_ */
