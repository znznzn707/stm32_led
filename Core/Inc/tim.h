#ifndef CORE_INC_TIM_H_
#define CORE_INC_TIM_H

#include "stm32f1xx.h"
#include "sys_config.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_tim.h"


#define BTIM_TIMX_INT TIM6
#define BTIM_TIMX_INT_IRQn TIM6_DAC_IRQn
#define BTIM_TIMX_INT_IRQHandler TIM6_DAC_IRQHandler
#define BTIM_TIMX_INT_CLK_ENABLE() do{__HAL_RCC_TIM6_CLK_ENABLE();}while(0);

extern void btim_timx_int_init(uint16_t arr, uint16_t psc);

#endif