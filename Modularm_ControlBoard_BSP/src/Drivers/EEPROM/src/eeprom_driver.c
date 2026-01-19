/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			eeprom_driver.c
* Creation Date:	Jan 13, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the EEPROM driver.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------

#include <Drivers/EEPROM/includes/eeprom_driver.h>

/*************************************************************

 Function Name:  EEPROM_WriteByte(uint32_t memory_address,
 	 	 	 	 uint8_t data)
 Description:    eeprom write byte fnction.
 Inputs:         uint32_t memory_address, uint8_t data.
 Outputs:        fsp_err_t.
 Author:		 Keerthi Mallesh
****************************************************************/
fsp_err_t EEPROM_WriteByte(uint32_t memory_address, uint8_t data)
{
	fsp_err_t 		err;
	uint8_t 		i2c_address;
	uint8_t 		payload[3];

	i2c_address 	= (uint8_t)(EEPROM_BASE_ADDR | ((memory_address >> 16) & 0x03));

	payload[0] 		= (uint8_t)((memory_address >> 8) & 0xFF);
	payload[1] 		= (uint8_t)(memory_address & 0xFF);
	payload[2] 		= data;

	R_IIC_MASTER_SlaveAddressSet(&g_i2c_rtc_ctrl, i2c_address, I2C_MASTER_ADDR_MODE_7BIT);
	err = R_IIC_MASTER_Write(&g_i2c_rtc_ctrl, payload, 3, false);
	if (err != FSP_SUCCESS)
	{
		return err;
	}

	//	Need to implement the delay.
//	R_BSP_SoftwareDelay(5, BSP_DELAY_UNITS_MILLISECONDS);

	return FSP_SUCCESS;
}

/*************************************************************

 Function Name:  EEPROM_ReadByte(uint32_t memory_address,
 	 	 	 	 uint8_t *p_data)
 Description:    eeprom read byte function.
 Inputs:         uint32_t memory_address, uint8_t data.
 Outputs:        fsp_err_t.
 Author:		 Keerthi Mallesh
****************************************************************/
fsp_err_t EEPROM_ReadByte(uint32_t memory_address, uint8_t *p_data)
{
	fsp_err_t 		err;
	uint8_t 		i2c_address;
	uint8_t			addr_buffer[2];

	i2c_address 	= (uint8_t)(EEPROM_BASE_ADDR | ((memory_address >> 16) & 0x03));
	addr_buffer[0] 	= (uint8_t)((memory_address >> 8) & 0xFF);
	addr_buffer[1] 	= (uint8_t)(memory_address & 0xFF);

	R_IIC_MASTER_SlaveAddressSet(&g_i2c_rtc_ctrl, i2c_address, I2C_MASTER_ADDR_MODE_7BIT);

	err = R_IIC_MASTER_Write(&g_i2c_rtc_ctrl, addr_buffer, 2, true);
	if (err != FSP_SUCCESS)
	{
		return err;
	}

	err = R_IIC_MASTER_Read(&g_i2c_rtc_ctrl, p_data, 1, false);

	return err;
}
