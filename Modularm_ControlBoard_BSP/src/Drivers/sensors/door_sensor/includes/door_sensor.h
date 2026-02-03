/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			door_sensor.h
* Creation Date:	Jan 29, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for door magnetic switch Communication.
*
*********************************************************************/
#ifndef DRIVERS_SENSORS_DOOR_SENSOR_INCLUDES_DOOR_SENSOR_H_
#define DRIVERS_SENSORS_DOOR_SENSOR_INCLUDES_DOOR_SENSOR_H_

#include "Drivers/sensors/includes/sensor_manager.h"
#include <utils/includes/common_headers.h>

//=====================================================================================================================
//-------------------------------------- enums & structures -----------------------------------------------------------
//=====================================================================================================================

typedef enum door_state
{
	DOOR_CLOSED		= 0,
	DOOR_OPEN		= 1,

} door_state_t;

//=====================================================================================================================
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================

door_state_t door_sensor_get_state(void);


#endif
