#include "key.h"

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

    // KEY1 PE3
    KEY1_GPIO_PORT->CRL &= 0xFFFF0FFF;
    KEY1_GPIO_PORT->CRL |= 0x00008000;
#endif
}

uint8_t KEY_Scan()
{
    static uint8_t key_up = 1;
    uint8_t res = 0x0;
#if (KEY_MODE == 1)
    key_up = 1;
#endif
    if (key_up && (KEY0 || KEY1))
    {
        delay_ms(10);
        key_up = 0;
        if (KEY0)
            res |= KEY0_DOWN;
        if (KEY1)
            res |= KEY1_DOWN;
        if (!res)
            key_up = 1;
    }
    return res;
}