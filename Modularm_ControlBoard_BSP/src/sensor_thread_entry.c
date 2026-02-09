/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			sensor_thread_entry.c
* Creation Date:	Jan 30, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for performing the task in
* 				sensor thread.
*
*********************************************************************/

//-------------------------------------- Includes -----------------------------------------------

#include "sensor_thread.h"
#include "Drivers/sensors/includes/sensor_manager.h"
#include "SCK/includes/sck_protocol.h"
#include "SCK/SCK_RS232/includes/sck_rs232_common.h"
#include <Application/door_manager/includes/door_manager.h>
#include <Application/motion_detector_manager/includes/motion_detector_manager.h>

//=====================================================================================================================
//-------------------------------------- Global Variables  ------------------------------------------------------------
//=====================================================================================================================
QueueHandle_t g_sensor_event_queue;

//-------------------------------------- Function Definition -----------------------------------------------

/***************************************************************************
 Function Name:  sensor_thread_entry(void *pvParameters)
 Description:    entry function for sensor thread.
 Inputs:         void *pvParameters
 Outputs:        void.
 Author:		 Keerthi Mallesh
*****************************************************************************/
void sensor_thread_entry(void *pvParameters) {

	FSP_PARAMETER_NOT_USED(pvParameters);

	sensor_event_t received_event;

	g_sensor_event_queue = xQueueCreate(10, sizeof(sensor_event_t));
	if(NULL == g_sensor_event_queue )
	{
		//! todo Need to create a proper error mechanism.
	}

	Door_Manager_Init();

	while (1)
	{
		if (pdTRUE == xQueueReceive(g_sensor_event_queue, &received_event, portMAX_DELAY))
		{
			switch(received_event.sensor_id)
			{
				case SENSOR_ID_DOOR:
					Door_Manager_Handle_Event(&received_event);
					break;

				case SENSOR_ID_MOTION:
					motion_detection_Handle_Event(&received_event);
					break;

				default:
				{
					break;
				}
			}
		}

		// todo need to write logic for tempreature send also.

		vTaskDelay(1);
	}
}
