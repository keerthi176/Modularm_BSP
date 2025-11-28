#include "i2c_thread.h"
/* I2C_thread entry function */
/* pvParameters contains TaskHandle_t */
void i2c_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */
    while (1)
    {
        vTaskDelay (1);
    }
}
