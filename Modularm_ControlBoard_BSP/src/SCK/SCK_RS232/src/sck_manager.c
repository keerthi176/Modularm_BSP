/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			sck_manager.c
* Creation Date:	Jan 14, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for parsing the sck command.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------
#include "SCK/SCK_RS232/includes/sck_common.h"
#include <Drivers/RS232/includes/RS232_uart.h>

//-------------------------------------- Static Variables -------------------------------------
static sck_parse_state_t			g_parse_state 							= SCK_STATE_STX;
static sck_frame_t					g_rx_frame;
static uint16_t						g_rx_crc_calc 							= 0;
static uint16_t						g_rx_crc_rec  							= 0;
static uint16_t						g_rx_packet_len_field					= 0;
static uint16_t						g_rx_data_idx							= 0;
static uint8_t						g_tx_buffer[SCK_MAX_PAYLOAD_SIZE + 16];

/*************************************************************

 Function Name:  SCK_Parse_Byte(uint8_t byte)
 Description:    function to parse the received data.
 Inputs:         uint8_t byte.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void SCK_Parse_Byte(uint8_t byte)
{
	switch(g_parse_state)
	{
		case SCK_STATE_STX:
			if(byte == SCK_FRAME_START)
			{
				g_parse_state = SCK_STATE_VERSION_LOW;
				g_rx_crc_calc = 0;
			}
			break;

		case SCK_STATE_VERSION_LOW:
			g_parse_state = SCK_STATE_VERSION_HIGH;
			break;

		case SCK_STATE_VERSION_HIGH:
			g_parse_state = SCK_STATE_LENGTH_LOW;
			break;

		case SCK_STATE_LENGTH_LOW:
			g_rx_packet_len_field = byte;
			g_rx_crc_calc = SCK_CRC16_Update(g_rx_crc_calc, byte);
			g_parse_state = SCK_STATE_LENGTH_HIGH;
			break;

		case SCK_STATE_LENGTH_HIGH:
			g_rx_packet_len_field |= (uint16_t)(byte << 8);
			g_rx_crc_calc = SCK_CRC16_Update(g_rx_crc_calc, byte);
			g_parse_state = SCK_STATE_TID;
			break;

		case SCK_STATE_TID:
			g_rx_frame.tid = byte;
			g_rx_crc_calc = SCK_CRC16_Update(g_rx_crc_calc, byte);
			g_parse_state = SCK_STATE_TYPE;
			break;

		case SCK_STATE_TYPE:
			g_rx_frame.type = byte;
			g_rx_crc_calc = SCK_CRC16_Update(g_rx_crc_calc, byte);
			g_parse_state = SCK_STATE_COMMAND_LOW;
			break;

		case SCK_STATE_COMMAND_LOW:
			g_rx_frame.id = byte;
			g_rx_crc_calc = SCK_CRC16_Update(g_rx_crc_calc, byte);
			g_parse_state = SCK_STATE_COMMAND_HIGH;
			break;

		case SCK_STATE_COMMAND_HIGH:
			g_rx_frame.id |= (uint16_t)(byte << 8);
			g_rx_crc_calc = SCK_CRC16_Update(g_rx_crc_calc, byte);
			if(g_rx_packet_len_field > 2)
			{
				g_rx_frame.data_len = ( g_rx_packet_len_field - 2 );
				g_rx_data_idx = 0;
				g_parse_state = SCK_STATE_DATA;
			}
			else
			{
				g_rx_frame.data_len = 0;
				g_parse_state = SCK_STATE_CRC_LOW;
			}
			break;

		case SCK_STATE_DATA:
			if(g_rx_data_idx < SCK_MAX_PAYLOAD_SIZE)
			{
				g_rx_frame.data[g_rx_data_idx++] = byte;
				g_rx_crc_calc = SCK_CRC16_Update(g_rx_crc_calc, byte);
			}

			if(g_rx_data_idx >= g_rx_frame.data_len)
			{
				g_parse_state = SCK_STATE_CRC_LOW;
			}
			break;

		case SCK_STATE_CRC_LOW:
			g_rx_crc_rec  = byte;
			g_parse_state = SCK_STATE_CRC_HIGH;
			break;

		case SCK_STATE_CRC_HIGH:
			g_rx_crc_rec |= (uint16_t)(byte << 8);
			g_parse_state = SCK_STATE_ETX;
			break;

		case SCK_STATE_ETX:
			if(byte == SCK_FRAME_END)
			{
				if(g_rx_crc_calc == g_rx_crc_rec)
				{
					SCK_Process_Received_Frame();
				}
			}

		g_parse_state = SCK_STATE_STX;
		break;
	}
}

/*************************************************************

 Function Name:  SCK_Send_Frame(uint8_t tid, uint8_t type,
 	 	 	 	 uint16_t command_id, uint8_t *data, uint16_t len)
 Description:    function to send the sck frame via RS-232.
 Inputs:         uint8_t tid, uint8_t type, uint16_t command_id,
 	 	 	 	 uint8_t *data, uint16_t len.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void SCK_Send_Frame(uint8_t tid, uint8_t type, uint16_t command_id, uint8_t *data, uint16_t len)
{
	uint16_t idx = 0;
	uint16_t packet_len_field = 2 + len;
	uint16_t crc = 0;

	g_tx_buffer[idx++] = SCK_FRAME_START;
	g_tx_buffer[idx++] = (uint8_t)(SCK_PROTOCOL_VERSION & 0XFF);
	g_tx_buffer[idx++] = (uint8_t)((SCK_PROTOCOL_VERSION >> 8) & 0xFF);

	g_tx_buffer[idx++] = (uint8_t)(packet_len_field & 0xFF);
	crc = SCK_CRC16_Update(crc, g_tx_buffer[idx-1]);

	g_tx_buffer[idx++] = (uint8_t)((packet_len_field >> 8) & 0xFF);
	crc = SCK_CRC16_Update(crc, g_tx_buffer[idx-1]);

	g_tx_buffer[idx++] = tid;
	crc = SCK_CRC16_Update(crc, tid);

	g_tx_buffer[idx++] = type;
	crc = SCK_CRC16_Update(crc, type);

	g_tx_buffer[idx++] = (uint8_t)(command_id & 0xFF);
	crc = SCK_CRC16_Update(crc, g_tx_buffer[idx-1]);

	g_tx_buffer[idx++] = (uint8_t)((command_id >> 8) & 0xFF);
	crc = SCK_CRC16_Update(crc, g_tx_buffer[idx-1]);

	for (int i = 0; i < len; i++)
	{
		g_tx_buffer[idx++] = data[i];
	    crc = SCK_CRC16_Update(crc, data[i]);
	}

	g_tx_buffer[idx++] = (uint8_t)(crc & 0xFF);
	g_tx_buffer[idx++] = (uint8_t)((crc >> 8) & 0xFF);

	g_tx_buffer[idx++] = SCK_FRAME_END;

	RS232_write(g_tx_buffer, idx);
}

/*************************************************************

 Function Name:  SCK_Process_Received_Frame(void)
 Description:    function to process hte received frame.
 Inputs:         NULL.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void SCK_Process_Received_Frame(void)
{
	if (g_rx_frame.type == SCK_TYPE_COMMAND)
	{
		switch(g_rx_frame.id)
		{
			case SCK_CMD_ID_ARE_YOU_THERE:
			{
				uint8_t status_data = 0x01;
				SCK_Send_Frame(g_rx_frame.tid, SCK_TYPE_STATUS, SCK_STAT_ID_AWAKE, &status_data, 1);
				break;
			}

			case SCK_CMD_ID_ACTION:
			{
				if (g_rx_frame.data_len >= 2)
				{
					uint16_t action_sub_id = (uint16_t)(g_rx_frame.data[0] | (g_rx_frame.data[1] << 8));

					switch (action_sub_id)
					{
						case SCK_ACTION_LIGHT_CONTROL:
							if(g_rx_frame.data_len >= 3)
							{
								if(g_rx_frame.data[2] == 1)
								{
									// todo
								}
								else
								{
									// todo
								}

								SCK_Send_Frame(g_rx_frame.tid, SCK_TYPE_STATUS, SCK_STAT_ID_SUCCESS, NULL, 0);
							}
							break;

						case SCK_ACTION_FORCE_ALARM:
							if(g_rx_frame.data_len >= 3)
							{
								if (g_rx_frame.data[2] == 1)
								{
									// todo..  Need to implement lights ON LOGIC
								}
								else
								{
									// todo.. Need to implement lights OFF LOGIC
								}

								SCK_Send_Frame(g_rx_frame.tid, SCK_TYPE_STATUS, SCK_STAT_ID_SUCCESS, NULL, 0);
							}
							break;

						default:
							SCK_Send_Frame(g_rx_frame.tid, SCK_TYPE_STATUS, SCK_STAT_ID_FAILURE, NULL, 0);
							break;
					}
				}
				break;
			}

			default:
				SCK_Send_Frame(g_rx_frame.tid, SCK_TYPE_STATUS, SCK_STAT_ID_NACK, NULL, 0);
				break;
		}
	}
}
