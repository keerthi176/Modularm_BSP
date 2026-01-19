/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			RTC.c
* Creation Date:	Jan 13, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for RTC.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------

#include "Drivers/RTC/includes/RTC.h"

/*************************************************************

 Function Name:  RTC_init(void)
 Description:    initialization of the RTC.
 Inputs:         void.
 Outputs:        NULL.
 Author:		 Keerthi Mallesh
****************************************************************/
void RTC_Init(void)
{
	fsp_err_t err;
	uint8_t write_buffer[2];

	err = R_IIC_MASTER_Open(&g_i2c_rtc_ctrl, &g_i2c_rtc_cfg);
	if(FSP_SUCCESS != err)
	{
		return;
	}

	write_buffer[0] = REG_CONTROL;
	write_buffer[1] = 0x00;

	err = R_IIC_MASTER_Write(&g_i2c_rtc_ctrl, write_buffer, 2, false);

}

/*************************************************************

 Function Name:  I2C_To_1wire_init(void)
 Description:    initialization of the 1-wire.
 Inputs:         void.
 Outputs:        NULL.
 Author:		 Keerthi Mallesh
****************************************************************/
fsp_err_t I2C_To_1wire_init(void)
{
	fsp_err_t err;
	uint8_t cmd = CMD_DRST;
	uint8_t status;

	err = R_IIC_MASTER_SlaveAddressSet(&g_i2c_rtc_ctrl, DS2482_I2C_ADDR, I2C_MASTER_ADDR_MODE_7BIT);
	if (FSP_SUCCESS != err)
	{
		return err;
	}

	err = R_IIC_MASTER_Write(&g_i2c_rtc_ctrl, &cmd, 1, false);
	if(FSP_SUCCESS != err)
	{
		return err;
	}

	// Need to implement the delay
//	R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);

	err = R_IIC_MASTER_Read(&g_i2c_rtc_ctrl, &status, 1, false);
	if(FSP_SUCCESS != err)
	{
		return err;
	}

//	R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);

	if ((status & STATUS_RST) == STATUS_RST)
	{
		return FSP_SUCCESS;
	}
	else
	{
		return FSP_ERR_DEVICE_BUSY;
	}
}
