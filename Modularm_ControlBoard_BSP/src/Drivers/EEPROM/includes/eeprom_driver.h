/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			eeprom_driver.c
* Creation Date:	Jan 13, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the eeprom driver.
*
*********************************************************************/

#ifndef DRIVERS_EEPROM_INCLUDES_EEPROM_DRIVER_H_
#define DRIVERS_EEPROM_INCLUDES_EEPROM_DRIVER_H_

#include "hal_data.h"
#include <utils/includes/common_headers.h>

//=====================================================================================================================
//-------------------------------------- Constant Macros -------------------------------------------------------------
//=====================================================================================================================
#define EEPROM_BASE_ADDR				0x50
#define EEPROM_PAGE_SIZE				256

//=====================================================================================================================
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================
fsp_err_t EEPROM_WriteByte(uint32_t memory_address, uint8_t data);
fsp_err_t EEPROM_ReadByte(uint32_t memory_address, uint8_t *p_data);

#endif
