/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			Temperature_manager.h
* Creation Date:	Feb 09, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for managing the temperature
* 				monitoring, state transitions, and alarm logic.
*
*********************************************************************/

#ifndef APPLICATION_TEMPERATURE_MANAGER_INCLUDES_TEMPERATURE_MANAGER_H_
#define APPLICATION_TEMPERATURE_MANAGER_INCLUDES_TEMPERATURE_MANAGER_H_

#include <utils/includes/common_headers.h>
#include <Drivers/sensors/temperature_sensor/includes/temperature_sensor.h>
#include <SCK/includes/sck_protocol.h>
#include <SCK/includes/sck_common.h>

//=====================================================================================================================
//-------------------------------------------- Macros -----------------------------------------------------------------
//=====================================================================================================================
#define SECONDS_TO_TIMER_TICKS(s)   ((s) * 100)

//=====================================================================================================================
//-------------------------------------- enums & structures -----------------------------------------------------------
//=====================================================================================================================

typedef enum
{

    TEMP_STATE_NORMAL,
    TEMP_STATE_ABNORMAL,
    TEMP_STATE_ALARM

} temp_monitor_state_t;

typedef enum
{

    TEMP_ALARM_NONE,
    TEMP_ALARM_LOW,
    TEMP_ALARM_HIGH,
    TEMP_ALARM_PROBE_FAULT

} temp_alarm_type_t;

static struct
{

    float    temp_high_limit_c;
    float    temp_low_limit_c;
    float    temp_calibration_offset_c;
    uint32_t temp_alarm_delay_seconds;

} s_app_config =
{
    .temp_high_limit_c         = 40.0f,
    .temp_low_limit_c          = 30.0f,
    .temp_calibration_offset_c = 0.0f,
    .temp_alarm_delay_seconds  = 5
};

//=====================================================================================================================
//-------------------------------------------- Static Variables -------------------------------------------------------
//=====================================================================================================================

static temp_monitor_state_t s_current_monitor_state = TEMP_STATE_NORMAL;
static temp_alarm_type_t	s_current_alarm_type 	= TEMP_ALARM_NONE;

//=====================================================================================================================
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================
void 					temperature_monitor_init			(void);
void 					temperature_monitor_process			(void);
temp_monitor_state_t 	temperature_monitor_get_state		(void);
temp_alarm_type_t 		temperature_monitor_get_alarm_type	(void);

//-------------------------------------- Static Function declaration ---------------------------------------------

static void 			update_monitor_state				(float current_temp);
static void 			temp_delay_timer_callback			(timer_callback_args_t *p_args);


#endif
