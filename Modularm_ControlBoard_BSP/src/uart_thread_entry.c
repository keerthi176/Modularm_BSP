#include "uart_thread.h"
/* UART_Thread entry function */
/* pvParameters contains TaskHandle_t */
void uart_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */
    while (1)
    {
        vTaskDelay (1);
    }
}
