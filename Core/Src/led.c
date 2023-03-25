/*
 * led.c
 *
 *  Created on: 2023年3月21日
 *      Author: znznzn707
 */
#include "led.h"

void RCC_APB2_Enable(uint32_t bits)
{
	RCC->APB2ENR |= bits;
}


void LED_GPIO_Init(GPIO_TypeDef * GPIOx)
{

	GPIOx->CRL &= 0xFF0FFFFF;
	GPIOx->CRL |= 0x00300000; //推挽输出、IO口速度为50MHz
	
	GPIOx->ODR |= 1 << 5; //初始化输出高 （低电平点亮）

	// LED0_GPIO_PORT->BSRR &= 0x00000000;

}
