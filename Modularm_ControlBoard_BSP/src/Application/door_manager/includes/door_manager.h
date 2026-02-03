/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			ADC_Driver.h
* Creation Date:	Jan 13, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for ADC Drier.
*
*********************************************************************/

#ifndef APPLICATION_DOOR_MANAGER_INCLUDES_DOOR_MANAGER_H_
#define APPLICATION_DOOR_MANAGER_INCLUDES_DOOR_MANAGER_H_

#include <utils/includes/common_headers.h>
#include "sensor_thread.h"
#include "Timers.h"
#include <Drivers/GPIO/includes/GPIO_driver.h>
#include <SCK/includes/sck_protocol.h>
#include "Drivers/sensors/includes/sensor_manager.h"
#include "SCK/includes/sck_common.h"

//=====================================================================================================================
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================
void Door_Manager_Init(void);
void Door_Manager_Handle_Event(sensor_event_t *p_event);
static void door_open_timer_callback(TimerHandle_t xTimer);

//=====================================================================================================================
//-------------------------------------- Public Variables  ---------------------------------------------------------
//=====================================================================================================================

#endif /* APPLICATION_DOOR_MANAGER_INCLUDES_DOOR_MANAGER_H_ */
