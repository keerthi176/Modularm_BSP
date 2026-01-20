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
#include "can_sck_common.h"
#include "sck_common.h"

/*************************************************************
 Function Name:  SCK_Send_Response(uint8_t tid, uint16_t status,
 	 	 	 	 const uint8_t *payload, uint16_t len)
 Description:    function for message transmit the CAN message.
 Inputs:         uint8_t tid, uint16_t status,
 	 	 	 	 const uint8_t *payload, uint16_t len.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void SCK_Send_Response(uint8_t tid, uint16_t status, const uint8_t *payload, uint16_t len)
{
    can_frame_t frame = {0};

    frame.id  = CAN_ID_SCK(CAN_NODE_CONTROL, CAN_NODE_BROADCAST);
    frame.data_length_code = 4 + len;

    frame.data[0] = tid;
    frame.data[1] = SCK_TYPE_STATUS;
    frame.data[2] = status & 0xFF;
    frame.data[3] = status >> 8;

    for (uint8_t i = 0; i < len; i++)
        frame.data[4 + i] = payload[i];

    CAN_Driver_Send(&frame);
}
