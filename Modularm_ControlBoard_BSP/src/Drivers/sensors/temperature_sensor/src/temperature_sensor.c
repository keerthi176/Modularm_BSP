/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			temperature_sensor.c
* Creation Date:	Feb 09, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for temperature sensor.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------

#include "Drivers/sensors/temperature_sensor/includes/temperature_sensor.h"

//-------------------------------------- Function Definition ---------------------------------------------------

/*************************************************************
 Function Name:  thermistor_init
 Description:    Initializes the thermistor sensor by
 	 	 	 	 initializing the ADC.
 Inputs:         None
 Outputs:        None
 Author:		 Keerthi Mallesh
****************************************************************/
void thermistor_init(void)
{
	adc_driver_init();
    s_sensor_status = TEMP_SENSOR_STATUS_OK;
}

/*************************************************************
 Function Name:  temp_sensor_get_status
 Description:    Returns the current status of the temperature sensor.
 Inputs:         None
 Outputs:        The current sensor status.
 Author:		 Keerthi Mallesh
****************************************************************/
temp_sensor_status_t temp_sensor_get_status(void)
{
    return s_sensor_status;
}

/*************************************************************
 Function Name:  thermistor_get_temp_celsius
 Description:    converts the ADC value to temperature celsius.
 Inputs:         None
 Outputs:        Temperature in Celsius, or NAN.
 Author:		 Keerthi Mallesh
****************************************************************/
float thermistor_get_temp_celsius(void)
{
    uint16_t raw_adc_value = 0;
    fsp_err_t err = adc_driver_read_raw((adc_channel_t)ADC_CHANNEL_TEMP_SENSOR, &raw_adc_value);

    if (FSP_SUCCESS != err)
    {
        s_sensor_status = TEMP_SENSOR_STATUS_PROBE_ERROR;
        return NAN;
    }

    if (raw_adc_value >= PROBE_SHORT_THRESHOLD_ADC)
    {
        s_sensor_status = TEMP_SENSOR_STATUS_SHORT_CIRCUIT;
        return NAN;
    }

    if (raw_adc_value <= PROBE_OPEN_THRESHOLD_ADC)
    {
        s_sensor_status = TEMP_SENSOR_STATUS_OPEN_CIRCUIT;
        return NAN;
    }

    s_sensor_status = TEMP_SENSOR_STATUS_OK;

    float resistance = SERIES_RESISTOR * (ADC_MAX_VALUE / (float)raw_adc_value - 1.0f);

    float steinhart;
    steinhart 	= resistance / THERMISTOR_NOMINAL_RESISTANCE;
    steinhart 	= logf(steinhart);
    steinhart  /= THERMISTOR_BETA_COEFFICIENT;
    steinhart  += (1.0f / THERMISTOR_NOMINAL_TEMPERATURE_K);
    steinhart 	= 1.0f / steinhart;

    float temp_celsius = steinhart - 273.15f;

    return temp_celsius;
}
