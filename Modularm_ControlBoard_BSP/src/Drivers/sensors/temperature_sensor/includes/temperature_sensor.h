/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			temperature_sensor.h
* Creation Date:	Feb 09, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for temperature sensor.
*
*********************************************************************/

#ifndef DRIVERS_SENSORS_TEMPERATURE_SENSOR_INCLUDES_TEMPERATURE_SENSOR_H_
#define DRIVERS_SENSORS_TEMPERATURE_SENSOR_INCLUDES_TEMPERATURE_SENSOR_H_

#include "utils/includes/common_headers.h"
#include "Drivers/sensors/includes/sensor_manager.h"
#include "Drivers/ADC/includes/ADC_Driver.h"

//=====================================================================================================================
//-------------------------------------- Macros -----------------------------------------------------------------------
//=====================================================================================================================

#define THERMISTOR_BETA_COEFFICIENT             (3950.0f)
#define THERMISTOR_NOMINAL_RESISTANCE           (10000.0f)
#define THERMISTOR_NOMINAL_TEMPERATURE_K        (298.15f)

#define SERIES_RESISTOR                         (10000.0f)

#define PROBE_SHORT_THRESHOLD_ADC               (4090)
#define PROBE_OPEN_THRESHOLD_ADC                (5)

//=====================================================================================================================
//-------------------------------------- enums & structures -----------------------------------------------------------
//=====================================================================================================================

typedef enum e_temp_sensor_status
{

    TEMP_SENSOR_STATUS_OK,
    TEMP_SENSOR_STATUS_SHORT_CIRCUIT,
    TEMP_SENSOR_STATUS_OPEN_CIRCUIT,
	TEMP_SENSOR_STATUS_PROBE_ERROR,

} temp_sensor_status_t;

//=====================================================================================================================
//-------------------------------------------- Static Variables -------------------------------------------------------
//=====================================================================================================================
static temp_sensor_status_t s_sensor_status = TEMP_SENSOR_STATUS_OK;

//=====================================================================================================================
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================

void    				thermistor_init				(void);
float   				thermistor_get_temp_celsius	(void);
temp_sensor_status_t 	temp_sensor_get_status		(void);

#endif
