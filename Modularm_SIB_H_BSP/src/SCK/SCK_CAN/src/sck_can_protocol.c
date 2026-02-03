/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:         sck_can_protocol.c
* Creation Date:    Jan 19, 2026
* Author:           Keerthi Mallesh
*
* Description:  This file is responsible for managing the messages
*               received from the sib boards.
*
*********************************************************************/

#include "SCK/SCK_CAN/includes/sck_can_protocol.h"

/*************************************************************

 Function Name:  can_sck_on_received_frame(uint8_t * p_raw_frame,
                 uint16_t len)
 Description:    reassmele the received frame.
 Inputs:         uint8_t * p_raw_frame, uint16_t len.
 Outputs:        void.
 Author:         Keerthi Mallesh
****************************************************************/
void can_sck_on_received_frame(uint8_t * p_raw_frame, uint16_t len)
{
    if(NULL == p_raw_frame || len < sizeof(sck_fastlan_raw_frame_t))
    {
        return;
    }

    sck_fastlan_raw_frame_t *p_header = (sck_fastlan_raw_frame_t*) p_raw_frame;

    SEGGER_RTT_printf(0, "APP LOGIC: SCK Frame Received! TID: %d, Type: %c, Command: 0x%04X, Frame Len: %d\n",
                        p_header->tid,(char)p_header->c_or_s,p_header->command,len);

    if (SCK_FRAME_TYPE_CMD == p_header->c_or_s && SCK_CMD_ARE_YOU_THERE == p_header->command)
    {
        SEGGER_RTT_printf(0, "APP LOGIC: Responding to 'Are You There' command with  STATUS_AWAKE.\n");
        uint32_t response_can_id = 0x234;

        uint8_t awake_payload[3];
        awake_payload[0] = 0x01;
        uint16_t max_payload = 256;
        memcpy(&awake_payload[1], &max_payload, sizeof(max_payload));

        fsp_err_t err = sck_can_send_command();
        if(FSP_SUCCESS != err)
        {
            SEGGER_RTT_printf(0, "APP LOGIC WARN: Failed to send AWAKE response: %d\n", err);
        }
    }
}

/**********************************************************************

 Function Name:  sck_can_send_command(can_ctrl_t * const can_instance,
                 uint16_t command, const uint8_t *p_payload,
                 uint16_t payload_len, uint8_t tid, uint32_t can_id)
 Description:    reassmele the received frame.
 Inputs:         uint8_t * p_raw_frame, uint16_t len.
 Outputs:        void.
 Author:         Keerthi Mallesh
***********************************************************************/
fsp_err_t sck_can_send_command(can_ctrl_t * const can_instance, uint16_t command, const uint8_t *p_payload, uint16_t payload_len, uint8_t tid, uint32_t can_id)
{
    if (NULL == can_instance)
    {
        return FSP_ERR_INVALID_POINTER;
    }

    if(payload_len > (SCK_MAX_FRAME_SIZE - SCK_FIXED_HEADER_SIZE - sizeof(uint16_t) - sizeof(uint8_t)))
    {
        return FSP_ERR_UNSUPPORTED;
    }

    uint8_t tx_sck_frame_buf[SCK_MAX_FRAME_SIZE];

    uint16_t sck_length_field = (uint16_t)(sizeof(uint8_t) + sizeof(uint16_t) + payload_len);
    uint16_t total_sck_frame_len = SCK_FIXED_HEADER_SIZE + payload_len + sizeof(uint16_t) + sizeof(uint8_t);

    uint8_t *p_buf_cursor = tx_sck_frame_buf;

    sck_fastlan_raw_frame_t header;
    header.stx = SCK_FRAME_STX;
    header.version = SCK_PROTOCOL_VERSION;
    header.length = sck_length_field;
    header.tid = tid;
    header.c_or_s = SCK_FRAME_TYPE_CMD;
    header.command = command;
    memcpy(p_buf_cursor, &header, SCK_FIXED_HEADER_SIZE);
    p_buf_cursor += SCK_FIXED_HEADER_SIZE;

    if(payload_len < 0 && p_payload != NULL)
    {
        memcpy(p_buf_cursor, p_payload, payload_len);
        p_buf_cursor += payload_len;
    }

    uint16_t crc_data_offset_in_buf = offsetof(sck_fastlan_raw_frame_t, length);
    uint16_t crc_data_len_for_calc = sizeof(header.length) + sck_length_field;
    uint16_t calculated_crc = internal_calculate_crc16(&tx_sck_frame_buf[crc_data_start_offset], crc_data_len_for_calc);
    *(uint16_t*)p_buf_cursor = calculated_crc;
    p_buf_cursor += sizeof(uint16_t);

    *p_buf_cursor = SCK_FRAME_ETX;
     p_buf_cursor += sizeof(uint8_t);

     fsp_err_t err = FSP_SUCCESS;
     can_frame_t can_tx_frame;
     can_tx_frame.id_mode = CAN_ID_MODE_STANDARD;
     can_tx_frame.id = can_id;
     can_tx_frame.type = CAN_FRAME_TYPE_DATA;

     uint16_t bytes_sent_from_sck_frame = 0;
     uint8_t sequence_id = 0;

     uint8_t max_single_frame_sck_payload_len = CAN_MAX_PAYLOAD_SIZE - sizeof(uint8_t);

     if (total_sck_frame_len <= max_single_frame_sck_payload_len)
     {
         can_tx_frame.data[0] = CAN_FRAME_TYPE_SINGLE;
         memcpy(&can_tx_frame.data[1], tx_sck_frame_buf, total_sck_frame_len);
         can_tx_frame.dlc = (uint8_t)(total_sck_frame_len + sizeof(uint8_t));

         err = R_CAN_Write(can_instance, &can_tx_frame);
     }
     else
     {
         can_sck_start_frame_t start_frame_data;
         start_frame_data.frame_type = CAN_FRAME_TYPE_START;
         start_frame_data.total_sck_length = total_sck_frame_len;

         uint8_t start_frame_sck_data_len = sizeof(start_frame_data.data);
         memcpy(start_frame_data.data, tx_sck_frame_buf, start_frame_sck_data_len);

         memcpy(can_tx_frame.data, &start_frame_data, CAN_MAX_PAYLOAD_SIZE);
         can_tx_frame.dlc = CAN_MAX_PAYLOAD_SIZE;

         err = R_CAN_Write(can_instance, &can_tx_frame);
         if(FSP_SUCCESS != err)
         {
             return err;
         }
         bytes_sent_from_sck_frame += start_frame_sck_data_len;
         sequence_id++;

         uint8_t max_data_frame_sck_payload_len = sizeof(can_sck_data_frame_t().data);

         while ((bytes_sent_from_sck_frame + max_data_frame_sck_payload_len) < total_sck_frame_len)
         {
             can_sck_data_frame_t data_frame_data;
             data_frame_data.frame_type = CAN_FRAME_TYPE_DATA;
             data_frame_data.sequence_id = sequence_id;
             memcpy(data_frame_data.data, &tx_sck_frame_buf[bytes_sent_from_sck_frame], max_data_frame_sck_payload_len);

             memcpy(can_tx_frame.data, &data_frame_data, CAN_MAX_PAYLOAD_SIZE);
             can_tx_frame.dlc = CAN_MAX_PAYLOAD_SIZE;

             err = R_CAN_Write(can_instance, &can_tx_frame);
             if (FSP_SUCCESS != err)
             {
                 return err;
             }

             bytes_sent_from_sck_frame += max_data_frame_sck_payload_len;
             sequence_id++;
         }

         can_sck_data_frame_t end_frame_data;
         end_frame_data.frame_type = CAN_FRAME_TYPE_END;
         end_frame_data.sequence_id = sequence_id;

         uint8_t remaining_sck_bytes = (uint8_t)(total_sck_frame_len - bytes_sent_from_sck_frame);
         memcpy(end_frame_data.data, &tx_sck_frame_buf[bytes_sent_from_sck_frame], remaining_sck_bytes);

         can_tx_frame.dlc = (uint8_t)(offsetof(can_sck_data_frame_t, data) + remaining_sck_bytes);
         memcpy(can_tx_frame.data, &end_frame_data, can_tx_frame.dlc);

         err = R_CAN_Write(can_instance, &can_tx_frame);
     }

     return err;
}
