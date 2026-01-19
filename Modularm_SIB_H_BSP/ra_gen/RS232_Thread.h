/* generated thread header file - do not edit */
#ifndef RS232_THREAD_H_
#define RS232_THREAD_H_
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void RS232_Thread_entry(void * pvParameters);
                #else
extern void RS232_Thread_entry(void *pvParameters);
#endif
#include "r_sci_uart.h"
#include "r_uart_api.h"
FSP_HEADER
/** UART on SCI Instance. */
extern const uart_instance_t RS232;

/** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
extern sci_uart_instance_ctrl_t RS232_ctrl;
extern const uart_cfg_t RS232_cfg;
extern const sci_uart_extended_cfg_t RS232_cfg_extend;

#ifndef NULL
void NULL(uart_callback_args_t *p_args);
#endif
FSP_FOOTER
#endif /* RS232_THREAD_H_ */
