/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			sck_RS232_parser.c
* Creation Date:	Jan 20, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for parsing the
* 				RS232 sck frames.
*
*********************************************************************/

//-------------------------------------- Includes -----------------------------------------------
#include <SCK/SCK_RS232/includes/sck_rs232_common.h>

/*************************************************************
 Function Name:  SCK_RS232_Init(void)
 Description:    Initialize the rs232 SCK.
 Inputs:         NULL.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void SCK_RS232_Init(void)
{
    memset(&g_ctx, 0, sizeof(g_ctx));
    g_ctx.state = SCK_STATE_STX;
}

/*************************************************************
 Function Name:  SCK_RS232_Parse_Byte(uint8_t byte)
 Description:    function for parsing the RS-232 message.
 Inputs:         uint8_t byte.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void SCK_RS232_Parse_Byte(uint8_t byte)
{
    sck_rs232_ctx_t *ctx = &g_ctx;

    switch (ctx->state)
    {
        case SCK_STATE_STX:
            if (byte == SCK_FRAME_START)
            {
                ctx->state    = SCK_STATE_VERSION_LOW;
                ctx->crc_calc = 0;
            }
            break;

        case SCK_STATE_VERSION_LOW:
            ctx->version = byte;
            ctx->state = SCK_STATE_VERSION_HIGH;
            break;

        case SCK_STATE_VERSION_HIGH:
            ctx->version |= (uint16_t)(byte << 8);
            if (ctx->version != ((SCK_VERSION_HIGH << 8) | SCK_VERSION_LOW))
            {
                ctx->state = SCK_STATE_STX;
                break;
            }
            ctx->state = SCK_STATE_LENGTH_LOW;
            break;

        case SCK_STATE_LENGTH_LOW:
            ctx->rx_length = byte;
            ctx->crc_calc = SCK_CRC16_Update(ctx->crc_calc, byte);
            ctx->state = SCK_STATE_LENGTH_HIGH;
            break;

        case SCK_STATE_LENGTH_HIGH:
            ctx->rx_length |= (uint16_t)(byte << 8);
            ctx->crc_calc = SCK_CRC16_Update(ctx->crc_calc, byte);

            if (ctx->rx_length < 3 ||
                ctx->rx_length > (SCK_MAX_PAYLOAD_SIZE + 3))
            {
                ctx->state = SCK_STATE_STX;
                break;
            }
            ctx->state = SCK_STATE_TID;
            break;

        case SCK_STATE_TID:
            ctx->frame.tid = byte;
            ctx->crc_calc = SCK_CRC16_Update(ctx->crc_calc, byte);
            ctx->state = SCK_STATE_TYPE;
            break;

        case SCK_STATE_TYPE:
            ctx->frame.type = byte;
            ctx->crc_calc = SCK_CRC16_Update(ctx->crc_calc, byte);
            ctx->state = SCK_STATE_COMMAND_LOW;
            break;

        case SCK_STATE_COMMAND_LOW:
            ctx->frame.cmd = byte;
            ctx->crc_calc = SCK_CRC16_Update(ctx->crc_calc, byte);
            ctx->state = SCK_STATE_COMMAND_HIGH;
            break;

        case SCK_STATE_COMMAND_HIGH:
            ctx->frame.cmd |= (uint16_t)(byte << 8);
            ctx->crc_calc = SCK_CRC16_Update(ctx->crc_calc, byte);

            ctx->frame.payload_len = ctx->rx_length - 3;
            ctx->data_idx = 0;

            ctx->state = (ctx->frame.payload_len > 0) ?
                         SCK_STATE_DATA : SCK_STATE_CRC_LOW;
            break;

        case SCK_STATE_DATA:
            ctx->frame.payload[ctx->data_idx++] = byte;
            ctx->crc_calc = SCK_CRC16_Update(ctx->crc_calc, byte);

            if (ctx->data_idx >= ctx->frame.payload_len)
                ctx->state = SCK_STATE_CRC_LOW;
            break;

        case SCK_STATE_CRC_LOW:
            ctx->crc_rx = byte;
            ctx->state = SCK_STATE_CRC_HIGH;
            break;

        case SCK_STATE_CRC_HIGH:
            ctx->crc_rx |= (uint16_t)(byte << 8);
            ctx->state = SCK_STATE_ETX;
            break;

        case SCK_STATE_ETX:
            if (byte == SCK_FRAME_END &&
                ctx->crc_calc == ctx->crc_rx)
            {
            	ctx->frame.interface = SCK_INTERFACE_RS232;
                SCK_Process_Received_Frame(&ctx->frame);
            }
            ctx->state = SCK_STATE_STX;
            break;
    }
}
