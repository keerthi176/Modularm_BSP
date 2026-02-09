/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			door_sensor.c
* Creation Date:	Jan 29, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for door magnetic switch.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------

#include "Drivers/sensors/door_sensor/includes/door_sensor.h"

//-------------------------------------- Function Definition -----------------------------------------------

/*************************************************************
 Function Name:  door_sensor_get_state(void)
 Description:    door sensor get state.
 Inputs:         void.
 Outputs:        door_state_t.
 Author:		 Keerthi Mallesh
****************************************************************/
door_state_t door_sensor_get_state(void)
{
	bsp_io_level_t pin_level;

	R_IOPORT_PinRead(&g_ioport_ctrl, DOOR_SWITCH, &pin_level);

	if(BSP_IO_LEVEL_HIGH == pin_level)
	{
		return DOOR_OPEN;
	}
	else
	{
		return DOOR_CLOSED;
	}
}

/*************************************************************
 Function Name:  door_sensor_irq_callback(
 	 	 	 	 external_irq_callback_args_t *p_args)
 Description:    door sensor interrupt callback.
 Inputs:         void.
 Outputs:        external_irq_callback_args_t *p_args.
 Author:		 Keerthi Mallesh
****************************************************************/
void door_sensor_irq_callback(external_irq_callback_args_t *p_args)
{
	FSP_PARAMETER_NOT_USED(p_args);

	sensor_event_t event;
	event.sensor_id = SENSOR_ID_DOOR;

	R_IOPORT_PinRead(&g_ioport_ctrl, DOOR_SWITCH, &event.pin_level);

	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	if (NULL != g_sensor_event_queue)
	{
		xQueueSendFromISR(g_sensor_event_queue, &event, &xHigherPriorityTaskWoken);
	}

	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
