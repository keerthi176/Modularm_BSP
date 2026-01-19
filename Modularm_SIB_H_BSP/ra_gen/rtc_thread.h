/* generated thread header file - do not edit */
#ifndef RTC_THREAD_H_
#define RTC_THREAD_H_
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void rtc_thread_entry(void * pvParameters);
                #else
extern void rtc_thread_entry(void *pvParameters);
#endif
#include "r_sci_i2c.h"
#include "r_i2c_master_api.h"
FSP_HEADER
extern const i2c_master_cfg_t g_i2c1_cfg;
/* I2C on SCI Instance. */
extern const i2c_master_instance_t g_i2c1;
#ifndef sci_i2c_master_callback
void sci_i2c_master_callback(i2c_master_callback_args_t *p_args);
#endif

extern const sci_i2c_extended_cfg_t g_i2c1_cfg_extend;
extern sci_i2c_instance_ctrl_t g_i2c1_ctrl;
FSP_FOOTER
#endif /* RTC_THREAD_H_ */
