/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define THERM_IN (BSP_IO_PORT_00_PIN_00) /* THERM_IN */
#define Door_Heater (BSP_IO_PORT_00_PIN_14) /* Door_Heater */
#define MCU_LED (BSP_IO_PORT_01_PIN_00) /* MCU_LED */
#define IP_IN (BSP_IO_PORT_01_PIN_01) /* Illuminated push button */
#define LED3 (BSP_IO_PORT_01_PIN_11) /* LED3 */
#define LED4 (BSP_IO_PORT_01_PIN_12) /* LED4 */
#define LED2 (BSP_IO_PORT_01_PIN_13) /* LED2 */
#define RECOVERY_PUSH_BUTTON (BSP_IO_PORT_02_PIN_00) /* Recovery Push Button */
#define SCL1 (BSP_IO_PORT_02_PIN_05) /* SCL1 */
#define SDA1 (BSP_IO_PORT_02_PIN_06) /* SDA1 */
#define RCVRY_PB (BSP_IO_PORT_02_PIN_07) /* RCVRY_PB */
#define HW_Ver_3 (BSP_IO_PORT_03_PIN_04) /* HW_Ver_3 */
#define HW_Ver_2 (BSP_IO_PORT_03_PIN_05) /* HW_Ver_2 */
#define HW_Ver_1 (BSP_IO_PORT_03_PIN_06) /* HW_Ver_1 */
#define HW_Ver_0 (BSP_IO_PORT_03_PIN_07) /* HW_Ver_0 */
#define IP1_HORN (BSP_IO_PORT_04_PIN_00) /* IP1_HORN */
#define LIGHTS_ON (BSP_IO_PORT_04_PIN_01) /* AC Lighting Relay - Set */
#define LIGHTS_OFF (BSP_IO_PORT_04_PIN_02) /* LIGHTS_OFF */
#define ALARM_RLY_OFF (BSP_IO_PORT_04_PIN_03) /* Alarm Relay - Reset */
#define AL_RLYY_ON (BSP_IO_PORT_04_PIN_04) /* AL_RLYY_ON */
#define BEEPER (BSP_IO_PORT_04_PIN_09) /* Beeper */
#define UART0_RTS (BSP_IO_PORT_04_PIN_13) /* UART0_RTS */
#define UART5_TX (BSP_IO_PORT_05_PIN_01) /* UART5_TX */
#define UART5_RX (BSP_IO_PORT_05_PIN_02) /* UART5_RX */
#define MCU_CAN_CNTRL (BSP_IO_PORT_05_PIN_03) /* MCU_CAN_CNTRL */
#define PWR_SRC (BSP_IO_PORT_05_PIN_04) /* PWR_SRC */
#define DOOR_SWITCH (BSP_IO_PORT_05_PIN_05) /* Magnetic Door Switch */
#define CAN_TXD (BSP_IO_PORT_06_PIN_09) /* CAN_TXD */
#define CAN_RXD (BSP_IO_PORT_06_PIN_10) /* CAN_RXD */
#define OCCDET1 (BSP_IO_PORT_07_PIN_08) /* OCCDET1 */

extern const ioport_cfg_t g_bsp_pin_cfg; /* R7FA6M5BF3CFP.pincfg */

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif /* BSP_PIN_CFG_H_ */
