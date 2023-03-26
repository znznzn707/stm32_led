/*
 * led.h
 *
 *  Created on: 2023年3月21日
 *      Author: znznzn707
 */

#ifndef CORE_INC_LED_H_
#define CORE_INC_LED_H_

#include "stm32f103xe.h"
#include "sys_config.h"

#define LED0_CLK (1<<3)    
#define LED1_CLK (1<<6)

#define LED0_GPIO_PORT GPIOB
#define LED1_GPIO_PORT GPIOE

#if (LED_VERSION == 1)
#define LED0_ON() (LED0_GPIO_PORT->ODR |= GPIO_PIN_5)
#define LED0_OFF() (LED0_GPIO_PORT->ODR &= ~(GPIO_PIN_5))

#define LED1_ON() (LED1_GPIO_PORT->ODR |= GPIO_PIN_5)
#define LED1_OFF() (LED1_GPIO_PORT->ODR &= ~(GPIO_PIN_5))

#else if (LED_VERSION == 2)
#define LED0_ON() (LED0_GPIO_PORT->BRR |= GPIO_PIN_5)
#define LED0_OFF() (LED0_GPIO_PORT->BSRR |= GPIO_PIN_5)

#define LED1_ON() (LED1_GPIO_PORT->BRR |= GPIO_PIN_5)
#define LED1_OFF() (LED1_GPIO_PORT->BSRR |= GPIO_PIN_5)
#endif

void RCC_APB2_Enable(uint32_t bits);

void LED_GPIO_Init(GPIO_TypeDef * GPIOx);

#endif /* CORE_INC_LED_H_ */
