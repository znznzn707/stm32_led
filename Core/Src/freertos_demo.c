#include "freertos_demo.h"
#include "FreeRTOS.h"
#include "task.h"
#include "key.h"
#include "usart.h"
#include "led.h"

/* START_TASK 任务 配置
* 包括: 任务句柄 任务优先级 堆栈大小 创建任务
*/
#define START_TASK_PRIO 1 /* 任务优先级 */
#define START_STK_SIZE 128 /* 任务堆栈大小 */
static TaskHandle_t s_hStartTask;
static void start_task(void *pvParameters);

/* TASK1 任务 配置
* 包括: 任务句柄 任务优先级 堆栈大小 创建任务
*/
#define TASK1_PRIO 2 /* 任务优先级 */
#define TASK1_STK_SIZE 128 /* 任务堆栈大小 */
static TaskHandle_t s_hTask1;
static void task1(void *pvParameters); /* 任务函数 */

#define TASK2_PRIO 3 /* 任务优先级 */
#define TASK2_STK_SIZE 128 /* 任务堆栈大小 */
static TaskHandle_t s_hTask2; /* 任务句柄 */
static void task2(void *pvParameters); /* 任务函数 */


void freertos_demo(void)
{
    xTaskCreate(start_task,
                "start_task",
                START_STK_SIZE,
                NULL,
                START_TASK_PRIO,
                &s_hStartTask);
    vTaskStartScheduler(); //开始调度
}

static void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();  //进入临界区

    xTaskCreate(task1,
                "task1",
                TASK1_STK_SIZE,
                NULL,
                TASK1_PRIO,
                &s_hTask1);
    xTaskCreate(task2,
                "task2",
                TASK2_STK_SIZE,
                NULL,
                TASK2_PRIO,
                &s_hTask2);
    vTaskDelete(s_hStartTask);

    taskEXIT_CRITICAL(); // 退出临界区
}

/**
 * @brief 按键任务
 * 
 * @param pvParameters 
 */
static void task1(void *pvParameters)
{
    uint8_t key_res = 0x0;
    while (1)
    {
        key_res = KEY_Scan();
        if (key_res & KEY0_DOWN)
            LED0_ON();
        if (key_res & KEY1_DOWN)
            LED1_ON();
        vTaskDelay(10);  /* 延时 10ticks */
        key_res = 0x0;
        LED1_OFF();
        LED0_OFF();
    }
}

/**
 * @brief 串口任务
 * 
 * @param pvParameters 
 */
static void task2(void *pvParameters)
{
    long float_num = 0;
    while (1)
    {
        /* 更新数值 */
        float_num += 1;
        printf("float_num=%d\r\n", (float_num %= 100)); /* 打印数值 */
        vTaskDelay(1000);  /* 延时 1000ticks */
    }
}
