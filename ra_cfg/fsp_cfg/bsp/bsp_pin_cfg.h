/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define Alarm (BSP_IO_PORT_00_PIN_02) /* Alarm ON/OFF */
#define lights (BSP_IO_PORT_00_PIN_04) /* LightsON/OFF */
#define Beeper (BSP_IO_PORT_00_PIN_05) /* BEEPER */
#define IP1 (BSP_IO_PORT_00_PIN_06) /* IP1_HORN */
#define FAIL_SAFE (BSP_IO_PORT_00_PIN_08) /* FAIL_SAFE */
#define MD_SW (BSP_IO_PORT_02_PIN_05) /* Magnetic_Door_Switch */
#define IP_SW (BSP_IO_PORT_02_PIN_06) /* IP_Switch */
#define Temperature_Sensor (BSP_IO_PORT_02_PIN_12) /* Temperature_Sensor */
#define Occupancy_detection (BSP_IO_PORT_02_PIN_13) /* Occupancy_detection */

extern const ioport_cfg_t g_bsp_pin_cfg; /* R7FA6M5BF3CFP.pincfg */

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif /* BSP_PIN_CFG_H_ */
