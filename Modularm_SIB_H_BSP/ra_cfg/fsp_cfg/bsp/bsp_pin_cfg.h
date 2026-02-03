/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define Thermistor_Input1 (BSP_IO_PORT_00_PIN_00) /* Thermistor_Input1 */
#define Thermistor_Input2 (BSP_IO_PORT_00_PIN_01) /* Thermistor_Input2 */
#define Thermistor_Input3 (BSP_IO_PORT_00_PIN_02) /* Thermistor_Input3 */
#define Thermistor_Input4 (BSP_IO_PORT_00_PIN_03) /* Thermistor_Input4 */
#define Input1 (BSP_IO_PORT_00_PIN_04) /* 4-20mA Input */
#define Input2 (BSP_IO_PORT_00_PIN_05) /* 4-20mA Input */
#define Input3 (BSP_IO_PORT_00_PIN_06) /* 4-20mA Input */
#define Input4 (BSP_IO_PORT_00_PIN_07) /* 4-20mA Input */
#define Voltage_Monitoring (BSP_IO_PORT_00_PIN_08) /* 12V Bus Voltage Monitoring */
#define RL_DRIV7 (BSP_IO_PORT_01_PIN_02) /* RL_DRIV7 */
#define RL_DRIV6 (BSP_IO_PORT_01_PIN_03) /* RL_DRIV6 */
#define RL_DRIV5 (BSP_IO_PORT_01_PIN_04) /* RL_DRIV5 */
#define RL_DRIV4 (BSP_IO_PORT_01_PIN_05) /* RL_DRIV4 */
#define RL_DRIV3 (BSP_IO_PORT_01_PIN_06) /* RL_DRIV3 */
#define RL_DRIV2 (BSP_IO_PORT_01_PIN_07) /* RL_DRIV2 */
#define MCU_DIG8 (BSP_IO_PORT_02_PIN_07) /* MCU_DIG8 */
#define MCU_DIG_12 (BSP_IO_PORT_02_PIN_09) /* MCU_DIG_12 */
#define MCU_DIG11 (BSP_IO_PORT_02_PIN_10) /* MCU_DIG11 */
#define MCU_DIG10 (BSP_IO_PORT_02_PIN_11) /* MCU_DIG10 */
#define MCU_DIG9 (BSP_IO_PORT_02_PIN_14) /* MCU_DIG9 */
#define MCU_CAN_CNTRL (BSP_IO_PORT_03_PIN_04) /* MCU_CAN_CNTRL */
#define LED2 (BSP_IO_PORT_03_PIN_05) /* LED2 */
#define LED3 (BSP_IO_PORT_03_PIN_06) /* LED3 */
#define LED4 (BSP_IO_PORT_03_PIN_07) /* LED4 */
#define HW_VER_0 (BSP_IO_PORT_04_PIN_00) /* HW_VER_0 */
#define HW_VER_1 (BSP_IO_PORT_04_PIN_03) /* HW_VER_1 */
#define HW_VER_2 (BSP_IO_PORT_04_PIN_04) /* HW_VER_2 */
#define HW_Ver_3 (BSP_IO_PORT_04_PIN_05) /* MCU_DIG7 */
#define MCU_DIG7 (BSP_IO_PORT_04_PIN_07) /* MCU_DIG7 */
#define UART3_RXD (BSP_IO_PORT_04_PIN_08) /* UART3_RXD */
#define UART3_TXD (BSP_IO_PORT_04_PIN_09) /* UART3_TXD */
#define UART3_RTS (BSP_IO_PORT_04_PIN_11) /* UART3_RTS */
#define MCU_DIG5 (BSP_IO_PORT_04_PIN_12) /* MCU_DIG5 */
#define MCU_DIG4 (BSP_IO_PORT_04_PIN_13) /* MCU_DIG4 */
#define MCU_DIG3 (BSP_IO_PORT_04_PIN_14) /* MCU_DIG3 */
#define MCU_DIG2 (BSP_IO_PORT_04_PIN_15) /* MCU_DIG2 */
#define RL_DRIV8 (BSP_IO_PORT_05_PIN_00) /* RL_DRIV8 */
#define RL_DRIV9 (BSP_IO_PORT_05_PIN_01) /* RL_DRIV9 */
#define RL_DRIV10 (BSP_IO_PORT_05_PIN_02) /* RL_DRIV10 */
#define RL_DRIV11 (BSP_IO_PORT_05_PIN_03) /* RL_DRIV11 */
#define RL_DRIV12 (BSP_IO_PORT_05_PIN_04) /* RL_DRIV12 */
#define RL_DRIV1 (BSP_IO_PORT_06_PIN_00) /* RL_DRIV1 */
#define SCL9 (BSP_IO_PORT_06_PIN_01) /* SCL9 */
#define SDA9 (BSP_IO_PORT_06_PIN_02) /* SDA9 */
#define MCU_DIG1 (BSP_IO_PORT_07_PIN_08) /* MCU_DIG1 */

extern const ioport_cfg_t g_bsp_pin_cfg; /* R7FA4M2AD3CFP.pincfg */

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif /* BSP_PIN_CFG_H_ */
