/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define OCCDET1 (BSP_IO_PORT_00_PIN_15) /* Occupancy Detection */
#define HW_VER_1 (BSP_IO_PORT_01_PIN_14) /* Hardware Revision Bit 1 */
#define HW_VER_2 (BSP_IO_PORT_01_PIN_15) /* Hardware Revision Bit 2 */
#define RECOVERY_PUSH_BUTTON (BSP_IO_PORT_02_PIN_00) /* Recovery Push Button */
#define MCU_LED (BSP_IO_PORT_02_PIN_10) /* MCU_LED */
#define CAN_TERM_EN (BSP_IO_PORT_02_PIN_11) /* CAN 120Ω Termination */
#define HW_VER_0 (BSP_IO_PORT_02_PIN_14) /* Hardware Revision Bit 0 */
#define LIGHTS_OFF (BSP_IO_PORT_04_PIN_00) /* AC Lighting Relay - Reset */
#define LIGHTS_ON (BSP_IO_PORT_04_PIN_01) /* AC Lighting Relay - Set */
#define ALARM_RLY_ON (BSP_IO_PORT_04_PIN_02) /* Alarm Relay - Set */
#define ALARM_RLY_OFF (BSP_IO_PORT_04_PIN_03) /* Alarm Relay - Reset */
#define IP1_BUZZER (BSP_IO_PORT_04_PIN_04) /* Piezo Buzzer */
#define DOOR_IN (BSP_IO_PORT_04_PIN_06) /* Door Magnet Switch */
#define RS485_RTS (BSP_IO_PORT_04_PIN_12) /* RS-485 Transmit Enable */
#define IP_IN (BSP_IO_PORT_05_PIN_00) /* Generic Digital Input */
#define HW_VER_3 (BSP_IO_PORT_06_PIN_08) /* Hardware Revision Bit 3 */

extern const ioport_cfg_t g_bsp_pin_cfg; /* R7FA6M5BF3CFP.pincfg */

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif /* BSP_PIN_CFG_H_ */
