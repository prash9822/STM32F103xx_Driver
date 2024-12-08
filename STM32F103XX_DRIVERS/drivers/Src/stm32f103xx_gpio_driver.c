/*
 * stm32f103xx_gpio.c
 *
 *  Created on: NOV24, 2024
 *      Author: PRASHANT ANDHALE
 */


#include "stm32f103xx_gpio_driver.h"

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx==GPIOA)		GPIOA_PCLK_EN();

		else if(pGPIOx==GPIOB)	GPIOB_PCLK_EN();

		else if(pGPIOx==GPIOC)	GPIOC_PCLK_EN();

		else if(pGPIOx==GPIOD)	GPIOD_PCLK_EN();

		else if(pGPIOx==GPIOE)	GPIOE_PCLK_EN();

		else if(pGPIOx==GPIOF)	GPIOF_PCLK_EN();

		else if(pGPIOx==GPIOG)	GPIOG_PCLK_EN();


	}
	else
	{
		if(pGPIOx==GPIOA)		GPIOA_PCLK_DI();

		else if(pGPIOx==GPIOB)	GPIOB_PCLK_DI();

		else if(pGPIOx==GPIOC)	GPIOC_PCLK_DI();

		else if(pGPIOx==GPIOD)	GPIOD_PCLK_DI();

		else if(pGPIOx==GPIOE)	GPIOE_PCLK_DI();

		else if(pGPIOx==GPIOF)	GPIOF_PCLK_DI();

		else if(pGPIOx==GPIOG)	GPIOG_PCLK_DI();

	}


}
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle)
{
		//GPIO_PeriClockControl(pGPIO_Handle->pGPIOx, ENABLE);
	     // configure the mode of GPIO pin

	    uint32_t temp=0;
	    if(pGPIO_Handle->GPIO_Pin_Config->GPIO_PinMode < GPIO_MODE_IT_FT)
	    {
		    if(pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber < 8)
		    {
		    	temp= (pGPIO_Handle->GPIO_Pin_Config->GPIO_PinMode << (pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber*4+2));  // CONFIGURE THE CRL REGISTER
		    	pGPIO_Handle->pGPIOx->CRL &= ~(0x3 << (pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber*4+2));    // clear the previous bit in the register
		    	pGPIO_Handle->pGPIOx->CRL|= temp;
		    }
		    else
		    {
		    	temp=0;
		    	uint8_t pinNum= pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber -8;         // CONFIGURE THE CRH REGISTER
		    	temp= (pGPIO_Handle->GPIO_Pin_Config->GPIO_PinMode << (pinNum*4+2));
		    	pGPIO_Handle->pGPIOx->CRH &= ~(0x3 << (pinNum *4+2));                    // clear the previous bit in the register
		        pGPIO_Handle->pGPIOx->CRH|= temp;
		    }
	    }
	    else
	    {
	    	//1. Function for external interrupt	Handler
	    	if(pGPIO_Handle->GPIO_Pin_Config->GPIO_PinMode == GPIO_MODE_IT_FT)
	    	{
	    		// configure the FISR register
	    		EXTI->FTSR|= (1<< pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber); // SET THE FALLING TRIGGER SELECTION REGISTER
	    		// clear the RTSR register
	    		EXTI->RTSR&= ~(1<< pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber); // CLEAR THE RISING TRIGGER SELECTION REGISTER
	    	}
	    	else if(pGPIO_Handle->GPIO_Pin_Config->GPIO_PinMode == GPIO_MODE_IT_RT)
	    	{
	    		// configure the RISR register
	    		EXTI->RTSR|= (1<< pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber); // SET THE RISSING TRIGGER SELECTION REGISTER
	    	    // clear the RTSR register
	    	    EXTI->FTSR&= ~(1<< pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber); // CLEAR THE FALLING TRIGGER SELECTION REGISTER
	    	}
	    	else if(pGPIO_Handle->GPIO_Pin_Config->GPIO_PinMode == GPIO_MODE_IT_RFT)
	    	{
	    		// SET BOTH RTSR AND FTSR REGISTER
	    		EXTI->RTSR|= (1<< pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber); // SET THE RISSING TRIGGER SELECTION REGISTER
	    	    EXTI->FTSR|= ~(1<< pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber); // SET THE FALLING TRIGGER SELECTION REGISTER
	    	}
	    	// 2. configure the IMR register
	    	EXTI->IMR|= (1<< pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber); // SET THE INTERRUPT MASKED REGISTER

	    }



	    temp=0;
	    // configure the input mode  and output mode of data register

	    if(pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber < 8)
	    {
	    	if(pGPIO_Handle->GPIO_Pin_Config->GPIO_PinType == 0)
	    	{
	    		temp= (pGPIO_Handle->GPIO_Pin_Config->GPIO_PinType << (pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber*4));
	    		pGPIO_Handle->pGPIOx->CRL &= ~(0x3 <<(pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber * 4));   // clear the previous bit
	    		pGPIO_Handle->pGPIOx->CRL |= temp;
	    	}
	    	else
	    	{
	    		temp=0;
	    		temp= (pGPIO_Handle->GPIO_Pin_Config->GPIO_PinType << (pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber*4));
	    		pGPIO_Handle->pGPIOx->CRL &= ~(0x3 <<(pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber * 4));   // clear the previous bit
	    		pGPIO_Handle->pGPIOx->CRL |= temp;
	    	}temp=0;
	    }
	    else
	    {
	    	uint8_t pinNum= pGPIO_Handle->GPIO_Pin_Config->GPIO_PinNumber -8;

	    				if(pGPIO_Handle->GPIO_Pin_Config->GPIO_PinType == 0)
	    		    	{
	    		    		temp= (pGPIO_Handle->GPIO_Pin_Config->GPIO_PinType << (pinNum*4));
	    		    		pGPIO_Handle->pGPIOx->CRH &= ~(0x3 <<(pinNum * 4));   // clear the previous bit
	    		    		pGPIO_Handle->pGPIOx->CRH |= temp;
	    		    	}
	    		    	else
	    		    	{
	    		    		temp=0;
	    		    		temp= (pGPIO_Handle->GPIO_Pin_Config->GPIO_PinType << (pinNum*4));
	    		    		pGPIO_Handle->pGPIOx->CRH &= ~(0x3 <<(pinNum * 4));   // clear the previous bit
	    		    		pGPIO_Handle->pGPIOx->CRH |= temp;
	    		    	}temp=0;
	    }
}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

	if(pGPIOx==GPIOA)		GPIOA_REG_RESET();

	else if(pGPIOx==GPIOB)	GPIOB_REG_RESET();

	else if(pGPIOx==GPIOC)	GPIOC_REG_RESET();

	else if(pGPIOx==GPIOD)	GPIOD_REG_RESET();

	else if(pGPIOx==GPIOE)	GPIOE_REG_RESET();

	else if(pGPIOx==GPIOF)	GPIOF_REG_RESET();

	else if(pGPIOx==GPIOG)	GPIOG_REG_RESET();

}
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value= (uint8_t)((pGPIOx->IDR << PinNumber)& 0x00000001);
	return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value=(uint16_t)pGPIOx->IDR ;
	return value;
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber, uint16_t value)
{
	if(value== GPIO_PIN_SET)
	{
		// WRITE 1 TO THE OUTPUT DATA REGISTER AT THE BIT FIELD CORROSPONDING TO THE PIN NUMBER
		pGPIOx->ODR |= (1<< PinNumber);
	}
	else
	{
		// WRITE 0 THE OUTPUT DATA REGISTER AT THE BIT FIELD CORROSPONDINGN TO THE PIN NUMBER
		pGPIOx->ODR &= ~(1<< PinNumber);
	}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t value)
{
	pGPIOx->ODR = value;
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1<< PinNumber);
}
