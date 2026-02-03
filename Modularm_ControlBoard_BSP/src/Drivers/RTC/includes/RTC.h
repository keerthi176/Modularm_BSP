/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			RTC.h
* Creation Date:	Jan 13, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for RTC Communication.
*
*********************************************************************/
#ifndef DRIVERS_RTC_INCLUDES_RTC_H_
#define DRIVERS_RTC_INCLUDES_RTC_H_

#include "hal_data.h"
#include <utils/includes/common_headers.h>

//=====================================================================================================================
//-------------------------------------- MACROS ---------------------------------------------------------
//=====================================================================================================================
#define RTC_AADDR 						0x51
#define REG_CONTROL						0x00

#define DS2482_I2C_ADDR   				0x18
#define CMD_DRST          				0xF0

#define STATUS_1WB        				(1<<0)
#define STATUS_PPD        				(1<<1)
#define STATUS_SD         				(1<<2)
#define STATUS_LL         				(1<<3)
#define STATUS_RST        				(1<<4)


//=====================================================================================================================
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================
void RTC_Init(void);

fsp_err_t I2C_To_1wire_init(void);

#endif /* DRIVERS_RTC_INCLUDES_RTC_H_ */
