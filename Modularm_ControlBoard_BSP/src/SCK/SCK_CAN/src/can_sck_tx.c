/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			can_sck_tx.c
* Creation Date:	Jan 20, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for process the
* 				transmit CAN frames.
*
*********************************************************************/

//-------------------------------------- Includes -----------------------------------------------
#include "SCK/SCK_CAN/includes/can_sck_common.h"
#include "SCK/includes/sck_common.h"
#include <SCK/includes/sck_protocol.h>

/*************************************************************
 Function Name:  SCK_Send_Response(uint8_t destination_id,
 	 	 	 	 uint8_t tid, uint16_t command, const
 	 	 	 	 uint8_t *payload, uint16_t len)

 Description:    function for message transmit the CAN message.
 Inputs:         uint8_t tid, uint16_t status,
 	 	 	 	 const uint8_t *payload, uint16_t len.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void SCK_CAN_Send_Response( uint8_t destination_id, uint8_t tid, uint16_t command, const uint8_t *payload, uint16_t len )
{
	can_frame_t frame = {0};

	frame.id = CAN_ID_SCK(NODE_ID_MAIN_CONTROLLER, destination_id);

	uint16_t total_dlc = 4 + len;

	if ( total_dlc > 8 )
	{
		total_dlc = 8;
	}

	frame.data_length_code = (uint8_t)total_dlc;

	frame.data[0] = tid;
	frame.data[1] = SCK_TYPE_COMMAND;
	frame.data[2] = command & 0xFF;
	frame.data[3] = command >> 8;

	for (uint8_t i = 0; i < len; i++)
	{
        frame.data[4 + i] = payload[i];
	}

//    CAN_Driver_Send(&frame);

}
