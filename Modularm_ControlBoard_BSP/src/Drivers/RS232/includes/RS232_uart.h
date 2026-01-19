/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			RS232_uart.h
* Creation Date:	Jan 06, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for RS232.
*
*********************************************************************/

#ifndef DRIVERS_RS232_INCLUDES_RS232_UART_H_
#define DRIVERS_RS232_INCLUDES_RS232_UART_H_

#include "hal_data.h"
#include <utils/includes/common_headers.h>

//=====================================================================================================================
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================

fsp_err_t RS232_init(void);
fsp_err_t RS232_open(void);
fsp_err_t RS232_close(void);
fsp_err_t RS232_write(uint8_t * const p_src, uint32_t const bytes);

#endif /* DRIVERS_RS232_INCLUDES_RS232_UART_H_ */
