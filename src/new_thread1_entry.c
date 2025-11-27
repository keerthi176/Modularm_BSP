#include "new_thread1.h"
/* New Thread entry function */
/* pvParameters contains TaskHandle_t */
void new_thread1_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */
    while (1)
    {
        vTaskDelay (1);
    }
}
