/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			can_sck_rx.c
* Creation Date:	Jan 20, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for process the
* 				receivied CAN frames.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------

#include "can_sck_common.h"
#include "sck_common.h"

/*************************************************************
 Function Name:  CAN_On_Receive(const can_frame_t *frame)
 Description:    function for message received over the CAN.
 Inputs:         const can_frame_t *frame.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void CAN_On_Receive(const can_frame_t *frame)
{
    sck_frame_t sck = {0};

    sck.tid  = frame->data[0];
    sck.type = frame->data[1];
    sck.cmd  = frame->data[2] | (frame->data[3] << 8);

    sck.payload_len = frame->data_length_code - 4;

    for (uint8_t i = 0; i < sck.payload_len; i++)
    {
        sck.payload[i] = frame->data[4 + i];
    }

    SCK_Process_Received_Frame(&sck);
}
