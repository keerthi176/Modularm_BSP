/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			temp_sensor_entry.c
* Creation Date:	Feb 04, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for performing the task for
* 				temperature thread.
*
*********************************************************************/

//-------------------------------------- Includes -----------------------------------------------
#include "temp_sensor.h"
#include <Application/Temperature_manager/includes/Temperature_manager.h>

/***************************************************************************
 Function Name:  temp_sensor_entry(void *pvParameters)
 Description:    entry function for temperature sensor
 Inputs:         void *pvParameters
 Outputs:        void.
 Author:		 Keerthi Mallesh
*****************************************************************************/
void temp_sensor_entry(void *pvParameters) {
	FSP_PARAMETER_NOT_USED(pvParameters);

	while (1)
	{
		temperature_monitor_process();

		vTaskDelay(pdMS_TO_TICKS(500));
	}
}
