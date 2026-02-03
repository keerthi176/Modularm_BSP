/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			motion_detector.c
* Creation Date:	Feb 02, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for motion detector.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------

#include "Drivers/sensors/motion_detection/includes/motion_detector.h"

/*************************************************************
 Function Name:  motion_detection_irq_callback(
 	 	 	 	 external_irq_callback_args_t *p_args)
 Description:    external interrupt for motion detection.
 Inputs:         external_irq_callback_args_t *p_args.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void motion_detection_irq_callback(external_irq_callback_args_t *p_args)
{
	FSP_PARAMETER_NOT_USED(p_args);

	sensor_event_t event;
	event.sensor_id = SENSOR_ID_MOTION;

	R_IOPORT_PinRead(&g_ioport_ctrl, OCCDET1, &event.pin_level);

	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	if (NULL != g_sensor_event_queue)
	{
		xQueueSendFromISR(g_sensor_event_queue, &event, &xHigherPriorityTaskWoken);
	}

	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

}
