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
#ifndef DRIVERS_ADC_INCLUDES_ADC_DRIVER_H_
#define DRIVERS_ADC_INCLUDES_ADC_DRIVER_H_

#include "hal_data.h"
#include <utils/includes/common_headers.h>

//=====================================================================================================================
//-------------------------------------- Macro's  --------------------------------------------------------------------
//=====================================================================================================================

#define V_REF_VOLTAGE						3.2f
#define ADC_MAX_VALUE						4095.0f
#define TEMP_SENSOR_R32_OHMS				1000.0f
#define TEMP_SENSOR_R35_OHMS				24000f
#define TEMP_SENSOR_R34_OHMS				1000.0f

#define RTD_R0_OHMS							1000.0f
#define RTD_ALPHA							0.00385f

//=====================================================================================================================
//-------------------------------------- Public Variables  ------------------------------------------------------------
//=====================================================================================================================
//volatile bool b_adc_scan_complete 			= false;

//=====================================================================================================================
//-------------------------------------- enums & structures -----------------------------------------------------------
//=====================================================================================================================
typedef enum
{

	ADC_CHANNEL_TEMP_SENSOR = 1,
	ADC_CHANNEL_24V_MON,
	ADC_CHANNEL_12V_MON,

} adc_channel;

//=====================================================================================================================
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================

fsp_err_t adc_driver_init(void);
fsp_err_t adc_driver_read_raw(adc_channel_t channel, uint16_t *p_raw_value);
fsp_err_t adc_driver_get_temperature_celsius(float *p_temperature_c);;
fsp_err_t adc_driver_get_24v_level(float *p_voltage);
fsp_err_t adc_driver_get_12v_level(float *p_voltage);

#endif
