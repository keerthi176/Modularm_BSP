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
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================
void ADC_Init(void);
void ADC_Read(float *temp_volts, float *v24, float *v12);

//=====================================================================================================================
//-------------------------------------- Public Variables  ---------------------------------------------------------
//=====================================================================================================================
volatile bool b_adc_scan_complete 			= false;

#endif
