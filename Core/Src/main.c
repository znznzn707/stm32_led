#include "led.h"
#include "delay.h"
#include "key.h"

int main()
{
    sys_stm32_clock_init(9); /* 设置时钟, 72Mhz */
    delay_init(72);          /* 延时初始化 */
    RCC_APB2_Enable(LED0_CLK | LED1_CLK);
    RCC_APB2_Enable(KEY0_CLK | KEY1_CLK);
    LED_GPIO_Init(LED0_GPIO_PORT);
    LED_GPIO_Init(LED1_GPIO_PORT);
    KEY_GPIO_Init();
    uint8_t key_res = 0x0;
    while (1)
    {
        key_res = KEY_Scan();
        if (key_res & KEY0_DOWN)
            LED0_ON();
        if (key_res & KEY1_DOWN)
            LED1_ON();
        delay_ms(10);
        key_res = 0x0;
        LED1_OFF();
        LED0_OFF();
    }

    while (1)
    {
        /* code */
    }
}