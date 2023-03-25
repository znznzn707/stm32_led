#include "led.h"
#include "delay.h"


int main()
{
    sys_stm32_clock_init(9); /* 设置时钟, 72Mhz */
    delay_init(72);          /* 延时初始化 */
    RCC_APB2_Enable(LED0_CLK | LED1_CLK);
    LED_GPIO_Init(LED0_GPIO_PORT);
    LED_GPIO_Init(LED1_GPIO_PORT);

    while (1)
    {
        LED0_ON();
        delay_ms(500);
        LED0_OFF();
        LED1_ON();
        delay_ms(500);
        LED1_OFF();
        }

    while (1)
    {
        /* code */
    }
}