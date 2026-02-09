/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			motion_detector_manager.h
* Creation Date:	Feb 03, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for managing motion
* 				detection casws.
*
*********************************************************************/

#ifndef APPLICATION_MOTION_DETECTOR_MANAGER_INCLUDES_MOTION_DETECTOR_MANAGER_H_
#define APPLICATION_MOTION_DETECTOR_MANAGER_INCLUDES_MOTION_DETECTOR_MANAGER_H_

#include <Drivers/Relay_Driver/includes/Relay_driver.h>
#include <utils/includes/common_headers.h>
#include "sensor_thread.h"
#include "SCK/includes/sck_common.h"
#include "sensor_thread.h"
#include "timers.h"
#include <SCK/includes/sck_protocol.h>
#include "Drivers/sensors/includes/sensor_manager.h"

//=====================================================================================================================
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================
void motion_detection_Init(void);
void motion_detection_Handle_Event(sensor_event_t *p_event);
static void motion_detector_timer_callback(TimerHandle_t xTimer);

//=====================================================================================================================
//-------------------------------------- Public Variables ------------------------------------------------------------
//=====================================================================================================================

#endif
