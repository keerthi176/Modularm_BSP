/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			GPIO_driver.c
* Creation Date:	Jan 06, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the GPIO driver.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------
#include "GPIO_driver.h"

/*************************************************************

 Function Name:  GPIO_init(void)
 Description:    initialization of the GPIO.
 Inputs:         void.
 Outputs:        NULL.
 Author:		 Keerthi Mallesh
****************************************************************/
void GPIO_init(void)
{
	R_BSP_PinAccessEnable();
}

/*************************************************************

 Function Name:  GPIO_ON(void)
 Description:    turning ON the GPIO.
 Inputs:         gpio_t pin.
 Outputs:        NULL.
 Author:		 Keerthi Mallesh
****************************************************************/
void GPIO_ON(gpio_t pin)
{
	R_IOPORT_PinWrite(&g_ioport_ctrl, pin, BSP_IO_LEVEL_HIGH);
}
/*************************************************************

 Function Name:  GPIO_OFF(void)
 Description:    initialization of the GPIO.
 Inputs:         gpio_t pin.
 Outputs:        NULL.
 Author:		 Keerthi Mallesh
****************************************************************/
void GPIO_OFF(gpio_t pin)
{
	R_IOPORT_PinWrite(&g_ioport_ctrl, pin, BSP_IO_LEVEL_LOW);
}

/*************************************************************

 Function Name:  GPIO_Toggle(void)
 Description:    initialization of the GPIO.
 Inputs:         gpio_t pin.
 Outputs:        NULL.
 Author:		 Keerthi Mallesh
****************************************************************/
void GPIO_Toggle(gpio_t pin)
{
	R_IOPORT_PinWrite(&g_ioport_ctrl, pin, BSP_IO_LEVEL_HIGH);
    R_BSP_SoftwareDelay(TEN_SECONDS_DELAY, BSP_DELAY_UNITS_MILLISECONDS);
	R_IOPORT_PinWrite(&g_ioport_ctrl, pin, BSP_IO_LEVEL_LOW);
}
