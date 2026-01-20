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
    if (frame->type != SCK_TYPE_COMMAND)
        return;

    switch (frame->cmd)
    {
        case SCK_CMD_ID_ARE_YOU_THERE:
        {
            uint8_t state = 0x01;

            SCK_Send_Response(frame->tid, SCK_STAT_ID_AWAKE, &state, 1);
            break;
        }

        case SCK_CMD_ID_ACTION:
        {
            SCK_Send_Response(frame->tid,SCK_STAT_ID_SUCCESS, 0, 0);
            break;
        }

        default:
            SCK_Send_Response(frame->tid, SCK_STAT_ID_NACK, 0, 0);
            break;
    }
}
