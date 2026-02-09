/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			door_manager.h
* Creation Date:	Feb 04, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for controlling the
* 				door manager.
*
*********************************************************************/

#ifndef APPLICATION_DOOR_MANAGER_INCLUDES_DOOR_MANAGER_H_
#define APPLICATION_DOOR_MANAGER_INCLUDES_DOOR_MANAGER_H_

#include <Drivers/Relay_Driver/includes/Relay_driver.h>
#include <utils/includes/common_headers.h>
#include "sensor_thread.h"
#include "timers.h"
#include <SCK/includes/sck_protocol.h>
#include "Drivers/sensors/includes/sensor_manager.h"
#include "SCK/includes/sck_common.h"

//=====================================================================================================================
//-------------------------------------- Macro's ----------------------------------------------------------------------
//=====================================================================================================================
#define DOOR_OPEN_ALARM_TIMEOUT_MS 10

//=====================================================================================================================
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================
void Door_Manager_Init(void);
void Door_Manager_Handle_Event(sensor_event_t *p_event);
static void door_open_timer_callback(TimerHandle_t xTimer);

//=====================================================================================================================
//-------------------------------------- Public Variables  ------------------------------------------------------------
//=====================================================================================================================

#endif
