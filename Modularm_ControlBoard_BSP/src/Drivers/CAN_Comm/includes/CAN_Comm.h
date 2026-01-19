/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			CAN_Comm.h
* Creation Date:	Jan 12, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for CAN Communication.
*
*********************************************************************/
#ifndef DRIVERS_CAN_COMM_INCLUDES_CAN_COMM_H_
#define DRIVERS_CAN_COMM_INCLUDES_CAN_COMM_H_

#include "hal_data.h"
#include <utils/includes/common_headers.h>
#include <can_thread.h>

//=====================================================================================================================
//-------------------------------------- private Variables -------------------------------------------------------------
//=====================================================================================================================
static volatile bool b_can_ready = false;

//=====================================================================================================================
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================
void CAN_init(void);
void CAN_Send_SIB_Command(uint32_t sib_id, uint8_t *data, uint8_t len);

#endif /* DRIVERS_CAN_COMM_INCLUDES_CAN_COMM_H_ */
