#include "stm32f103xx.h"
#include "stm32f103xx_gpio_driver.h"
void delay(void)
{
	for(uint32_t i=0;i<=500000/2;i++);
}
int main(void)
{

	GPIO_Handle_t GpioLed;

	GPIO_Pin_Config_t GpioConfig; // Declare a GPIO configuration structure

	// Initialize the GPIO configuration structure pointer
	GpioLed.GPIO_Pin_Config = &GpioConfig;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	// Initiliaze the pin to be configured as an output pin
	GpioLed.pGPIOx= GPIOA;
	GpioLed.GPIO_Pin_Config->GPIO_PinNumber= GPIO_PIN_NO_0;
	GpioLed.GPIO_Pin_Config->GPIO_PinMode = GPIO_MODE_OUTPUT_OD;
	GpioLed.GPIO_Pin_Config->GPIO_PinType = GPIO_OUTPUT;


	GPIO_Init(&GpioLed);

	//Initiliaze the pin to be configured as input pin

//	GpioBtn.pGPIOx= GPIOC;
//	GpioBtn.GPIO_Pin_Config->GPIO_PinNumber= GPIO_PIN_NO_14;
//	GpioBtn.GPIO_Pin_Config->GPIO_PinMode = GPIO_MODE_OUTPUT_OD;
//	GpioBtn.GPIO_Pin_Config->GPIO_PinType = GPIO_OUTPUT;

	while(1)
	{
//		GPIO_WriteToOutputPin(GPIOC,GPIO_PIN_NO_13, GPIO_PIN_SET);
		GPIO_ToggleOutputPin(GPIOA,GPIO_PIN_NO_0);
		delay();
	}
	return 0;
}
