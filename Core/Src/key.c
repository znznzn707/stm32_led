#include "key.h"
#include "usart.h"
/**
 * @brief KEY0 PE4; KEY1 PE3
 *
 */
void KEY_GPIO_Init()
{
#if (KEY_VERSION == 1)
    // KEY0 PE4
    KEY0_GPIO_PORT->CRL &= 0xFFF0FFFF;
    KEY0_GPIO_PORT->CRL |= 0x00080000;
    KEY0_GPIO_PORT->ODR &= ~(KEY0_GPIO_PIN);
    KEY0_GPIO_PORT->ODR |= KEY0_GPIO_PIN;

    // KEY1 PE3
    KEY1_GPIO_PORT->CRL &= 0xFFFF0FFF;
    KEY1_GPIO_PORT->CRL |= 0x00008000;
    KEY1_GPIO_PORT->ODR &= ~(KEY1_GPIO_PIN);
    KEY1_GPIO_PORT->ODR |= KEY1_GPIO_PIN;
#endif
}

uint8_t KEY_Scan()
{
    uint8_t key_up = 0x0;
    if(!KEY0 || !KEY1)
    {
        delay_ms(10);
        if (!KEY0)
            key_up |= KEY0_DOWN;
        if (!KEY1)
            key_up |= KEY1_DOWN;
    }
    return key_up;
}