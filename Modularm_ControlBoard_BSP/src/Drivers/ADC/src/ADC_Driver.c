/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			ADC_Driver.c
* Creation Date:	Jan 13, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for ADC channels.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------

#include <Drivers/ADC/includes/ADC_Driver.h>

//-------------------------------------- Function Definition -----------------------------------------------

/*************************************************************
 Function Name:  adc_driver_init(void)
 Description:    initialization of the ADC.
 Inputs:         NULL.
 Outputs:        fsp_err_t.
 Author:		 Keerthi Mallesh
****************************************************************/
fsp_err_t adc_driver_init(void)
{
	fsp_err_t err = FSP_SUCCESS;

	err = R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg);
	if(FSP_SUCCESS != err)
	{
		// todo Need to implement logic
	}

	err = R_ADC_ScanStart(&g_adc0_ctrl);
	if(FSP_SUCCESS != err)
	{
		// todo Need to implement logic
	}

	return FSP_SUCCESS;
}

/*************************************************************
 Function Name:  ADC_Read(float *temp_volts, float *v24,
 	 	 	 	 	 	 float *v12)
 Description:    ADC Read.
 Inputs:         float *temp_volts, float *v24, float *v12.
 Outputs:        fsp_err_t.
 Author:		 Keerthi Mallesh
****************************************************************/
fsp_err_t adc_driver_read_raw(adc_channel_t channel, uint16_t *p_raw_value)
{
	return R_ADC_Read(&g_adc0_ctrl, (adc_channel_t)channel, p_raw_value);
}

/*************************************************************
 Function Name:  ADC_Read(float *temp_volts, float *v24,
 	 	 	 	 	 	 float *v12)
 Description:    ADC Read.
 Inputs:         float *temp_volts, float *v24, float *v12.
 Outputs:        fsp_err_t.
 Author:		 Keerthi Mallesh
****************************************************************/
//fsp_err_t adc_driver_get_temperature_celsius(float *p_temperature_c)
//{
//	fsp_err_t err;
//	adc_raw_data_t raw_adc_value = 0;
//	float v_adc = 0.0f;
//	float r_rtd = 0.0f;
//
//	err = adc_driver_read_raw(ADC_CHANNEL_TEMP_SENSOR, &raw_adc_value);
//	if(FSP_SUCCESS != err)
//	{
//		return err;
//	}
//
//	v_adc = ((float)raw_adc_value / ADC_MAX_VALUE) * V_REF_VOLTAGE;
//	if (V_REF_VOLTAGE - v_adc <= 0.001f)
//	{
//		return FSP_ERR_INVALID_STATE;
//	}
//
//	r_rtd = ((v_adc * TEMP_SENSOR_R32_OHMS) / (V_REF_VOLTAGE - v_adc)) - TEMP_SENSOR_R35_OHMS - TEMP_SENSOR_R34_OHMS;
//	if (RTD_R0_OHMS <= 0.0f || RTD_ALPHA <= 0.0f)
//	{
//		return FSP_ERR_ASSERTION;
//	}
//
//	*p_temperature_c = ((r_rtd / RTD_R0_OHMS) - 1.0f) / RTD_ALPHA;

//	return FSP_SUCCESS;
//}

/*************************************************************
 Function Name:  adc_driver_get_24v_level(float *p_voltage)
 Description:    adc_driver_get_24v_level.
 Inputs:         float *p_voltage.
 Outputs:        fsp_err_t.
 Author:		 Keerthi Mallesh
****************************************************************/
fsp_err_t adc_driver_get_24v_level(float *p_voltage)
{
	// todo Need to implement the logic
	return FSP_SUCCESS;
}

/*************************************************************
 Function Name:  adc_driver_get_12v_level(float *p_voltage)
 Description:    adc_driver_get_12v_level.
 Inputs:         float *p_voltage.
 Outputs:        fsp_err_t.
 Author:		 Keerthi Mallesh
****************************************************************/
fsp_err_t adc_driver_get_12v_level(float *p_voltage)
{
	// todo Need to implement the logic
	return FSP_SUCCESS;
}
