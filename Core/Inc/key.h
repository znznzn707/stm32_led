#ifndef CORE_INC_KEY_H_
#define CORE_INC_KEY_H

#include "stm32f1xx.h"
#include "sys_config.h"
#include "delay.h"

#define KEY0_CLK (1 << 6)
#define KEY1_CLK (1 << 6)

#define KEY0_GPIO_PORT GPIOE
#define KEY1_GPIO_PORT GPIOE

#define KEY0_GPIO_PIN GPIO_PIN_4
#define KEY1_GPIO_PIN GPIO_PIN_3

#if (KEY_VERSION == 1)
#define KEY0 ((uint16_t)(KEY0_GPIO_PORT->IDR) & (KEY0_GPIO_PIN))
#define KEY1 ((uint16_t)(KEY1_GPIO_PORT->IDR) & (KEY1_GPIO_PIN))
#endif

#define NONE_DOWN (0x00)
#define KEY0_DOWN (0x01)
#define KEY1_DOWN (0x10)

void KEY_GPIO_Init();
uint8_t KEY_Scan();

#endif