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
#include <Drivers/Relay_Driver/includes/Relay_driver.h>

//-------------------------------------- Function Definition -----------------------------------------------

/*************************************************************

 Function Name:  Relay_init(void)
 Description:    initialization of the relay's.
 Inputs:         void.
 Outputs:        NULL.
 Author:		 Keerthi Mallesh
****************************************************************/
void Relay_init(void)
{
	R_BSP_PinAccessEnable();
}

/*************************************************************

 Function Name:  Relay_control( uint8_t pin, gpio_t pin_level )
 Description:    controlling the relay's.
 Inputs:         uint8_t pin, gpio_t pin_level.
 Outputs:        NULL.
 Author:		 Keerthi Mallesh
****************************************************************/
void Relay_control( uint8_t pin, relay_t pin_level )
{
	Relay_init();

	if(pin_level == TURN_ON)
	{
		R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t)pin, BSP_IO_LEVEL_HIGH);
	}

	if( pin_level == TURN_OFF )
	{
		R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t)pin, BSP_IO_LEVEL_LOW);
	}
}
