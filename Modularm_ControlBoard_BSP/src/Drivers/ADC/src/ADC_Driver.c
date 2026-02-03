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

/*************************************************************
 Function Name:  ADC_Init(void)
 Description:    initialization of the ADC.
 Inputs:         NULL.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void ADC_Init(void)
{
	fsp_err_t err;

	err = R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg);
	if(FSP_SUCCESS != err)
	{
		return;
	}

	err = R_ADC_ScanCfg(&g_adc0_ctrl, &g_adc0_channel_cfg);
	if(FSP_SUCCESS != err)
	{
		return;
	}

	err = R_ADC_ScanStart(&g_adc0_ctrl);
}

/*************************************************************
 Function Name:  ADC_Read(float *temp_volts, float *v24,
 	 	 	 	 	 	 float *v12)
 Description:    ADC Read.
 Inputs:         float *temp_volts, float *v24, float *v12.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void ADC_Read(float *temp_volts, float *v24, float *v12)
{
	uint16_t raw_counts[3];

	R_ADC_Read(&g_adc0_ctrl, ADC_CHANNEL_0, &raw_counts[0]);
	R_ADC_Read(&g_adc0_ctrl, ADC_CHANNEL_1, &raw_counts[1]);
	R_ADC_Read(&g_adc0_ctrl, ADC_CHANNEL_2, &raw_counts[2]);

	*temp_volts = (raw_counts[0] * 3.3f) / 4095.0f;

	*v24 = ((raw_counts[1] * 3.3f) / 4095.0f) * 9.66f;

	*v12 = ((raw_counts[2] * 3.3f) / 4095.0f) * 2.0f;
}

/*************************************************************
 Function Name:  adc_callback(adc_callback_args_t *p_args)
 Description:    ADC Callback.
 Inputs:         adc_callback_args_t *p_args.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void adc_callback(adc_callback_args_t *p_args)
{
	if(ADC_EVENT_SCAN_COMPLETE == p_args->event )
	{
		b_adc_scan_complete = true;
	}
}
