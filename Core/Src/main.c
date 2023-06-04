#include "led.h"
#include "delay.h"
#include "key.h"
#include "usart.h"
#include "freertos_demo.h"

int main()
{
    sys_stm32_clock_init(9); /* 设置时钟, 72Mhz */
    delay_init(72);          /* 延时初始化 */
    usart_init(72, 115200);
    RCC_APB2_Enable(LED0_CLK | LED1_CLK);
    RCC_APB2_Enable(KEY0_CLK | KEY1_CLK);
    LED_GPIO_Init(LED0_GPIO_PORT);
    LED_GPIO_Init(LED1_GPIO_PORT);
    KEY_GPIO_Init();

    freertos_demo();
}