#include "tim.h"
#include "led.h"
#include "delay.h"

static TIM_HandleTypeDef tim_handler;


void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == BTIM_TIMX_INT)
    {
        BTIM_TIMX_INT_CLK_ENABLE();
        HAL_NVIC_SetPriority(BTIM_TIMX_INT_IRQn, 1, 3);
        HAL_NVIC_EnableIRQ(BTIM_TIMX_INT_IRQn);
    }
}

/**
 * @brief 基本定时器初始化
 * 
 * @param arr 自动重装载值 
 * @param psc 预分频系数
 */
void btim_timx_int_init(uint16_t arr, uint16_t psc)
{
    tim_handler.Instance = BTIM_TIMX_INT;
    tim_handler.Init.Prescaler = psc;  //预分频系数
    tim_handler.Init.CounterMode = TIM_COUNTERMODE_UP; //递增计数器
    tim_handler.Init.Period = arr;  /*自动重装载值*/
    HAL_TIM_Base_Init(&tim_handler);
    HAL_TIM_Base_Start_IT(&tim_handler);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == BTIM_TIMX_INT)
    {
        LED1_ON();
        delay_ms(5);
        LED1_OFF();
    }
}

void BTIM_TIMX_INT_IRQHandler()
{
    HAL_TIM_IRQHandler(&tim_handler);
}