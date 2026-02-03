/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			sensor_manager.h
* Creation Date:	Jan 29, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for managing the multipple
* 				sensor information.
*
*********************************************************************/
#ifndef DRIVERS_SENSORS_INCLUDES_SENSOR_MANAGER_H_
#define DRIVERS_SENSORS_INCLUDES_SENSOR_MANAGER_H_

#include <utils/includes/common_headers.h>
#include "sensor_thread.h"

//=====================================================================================================================
//-------------------------------------- enums & structures -----------------------------------------------------------
//=====================================================================================================================

typedef enum e_sensor_id {

	SENSOR_ID_NONE			= 0,
	SENSOR_ID_DOOR 			= 1,
	SENSOR_ID_MOTION		= 2

}sensor_id_t;

typedef struct s_sensor_event {

	sensor_id_t				sensor_id;
	bsp_io_level_t 			pin_level;

}sensor_event_t;

//=====================================================================================================================
//-------------------------------------- Global variables -------------------------------------------------------------
//=====================================================================================================================
extern QueueHandle_t g_sensor_event_queue;

//=====================================================================================================================
//-------------------------------------- function definition ----------------------------------------------------------
//=====================================================================================================================

#endif
