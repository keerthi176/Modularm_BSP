/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			sc_process.c
* Creation Date:	Jan 20, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for processing the receiving
* 				sck command.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------
#include <SCK/includes/sck_common.h>
#include <SCK/includes/sck_protocol.h>

#include <SCK/SCK_CAN/includes/can_sck_common.h>
#include <SCK/SCK_RS232/includes/sck_rs232_common.h>

//=====================================================================================================================
//---------------------------------------------- static variables -----------------------------------------------------
//=====================================================================================================================
static uint8_t g_pending_display_tid		= 0;

//=====================================================================================================================
//---------------------------------------------- function definitions -------------------------------------------------
//=====================================================================================================================

/*************************************************************
 Function Name:  SCK_Process_Received_Frame(const
 	 	 	 	 sck_frame_t *frame)
 Description:    processing the received sck frame.
 Inputs:         const sck_frame_t *frame.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void SCK_Process_Received_Frame(const sck_frame_t *frame)
{
    if (frame->interface == SCK_INTERFACE_RS232)
    {
    	handle_SoC_command(frame);
    	return;
    }
    else if(frame ->interface == SCK_INTERFACE_CAN)
    {
    	handle_sib_response(frame);
    	return;
    }
}

/*************************************************************
 Function Name:  handle_SoC_command(const sck_frame_t *frame)
 Description:    processing the received sck frame.
 Inputs:         const sck_frame_t *frame.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void handle_SoC_command(const sck_frame_t *frame)
{
	if (frame->cmd == SCK_CMD_ID_FORWARD_TO_SIB)
	{
		if (frame->payload_len < 3)
		{
			SCK_RS232_Send_Response(frame->tid, SCK_STAT_ID_FAILURE, NULL, 0);
			return;
		}

		if( g_pending_display_tid != 0 )
		{
			SCK_RS232_Send_Response(frame->tid, SCK_STAT_ID_NACK, NULL, 0);
			return;
		}

		uint8_t  destination_sib_id = frame->payload[0];
		uint16_t actual_command_id  = (uint16_t)frame->payload[1] | (uint16_t)(((uint16_t)frame->payload[2]) << 8);
		const uint8_t *actual_payload = &frame->payload[3];
		uint16_t actual_payload_len = frame->payload_len - 3;

		g_pending_display_tid = frame->tid;

		SCK_CAN_Send_Response(destination_sib_id, frame->tid, actual_command_id, actual_payload, actual_payload_len);
	}
	else if(frame->cmd == SCK_CMD_ID_ARE_YOU_THERE)
	{
		uint8_t payload[] = { SCK_DEVICE_STATE_RUNNING };
		SCK_RS232_Send_Response(frame->tid, SCK_STAT_ID_AWAKE, payload, sizeof(payload));
	}
	else
	{
		SCK_RS232_Send_Response(frame->tid, SCK_STAT_ID_NACK, NULL, 0);
	}
}

/*************************************************************
 Function Name:  handle_sib_response(const sck_frame_t *frame)
 Description:    processing the received sck frame.
 Inputs:         const sck_frame_t *frame.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void handle_sib_response(const sck_frame_t *frame)
{
	if (frame->tid == g_pending_display_tid)
	{
		uint16_t status_from_sib = frame->cmd;

		SCK_RS232_Send_Response(g_pending_display_tid, status_from_sib, frame->payload, frame->payload_len);

		g_pending_display_tid = 0;
	}
}
