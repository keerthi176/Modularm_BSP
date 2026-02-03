/*
 * sck_application.c
 *
 *  Created on: 19-Jan-2026
 *      Author: User
 */

#include "SCK/SCK_CAN/includes/sck_can_protocol.h"



void sck_app_on_frame_received(uint8_t * p_raw_frame, uint16_t len)
{
    if(NULL == p_raw_frame || len < SCK_FIXED_HEADER_SIZE)
    {
        return;
    }

    sck_fastlan_frame_header_t *p_header = (sck_fastlan_frame_header_t*) p_raw_frame;

    SEGGER_RTT_printf(0, "APP LOGIC: SCK Frame Received! TID: %d, Type: %c, Command: 0x%04X, Frame Len: %d\n",
                      p_header->tid,
                      (char)p_header->c_or_s,
                      p_header->command,
                    len);


    if (SCK_FRAME_TYPE_CMD == p_header->c_or_s && SCK_CMD_ARE_YOU_THERE == p_header->command)
    {
        SEGGER_RTT_printf(0, "APP LOGIC: Responding to 'Are You There' command with STATUS_AWAKE.\n");
        uint32_t response_can_id = 0x234;

        uint8_t awake_payload[3];
        awake_payload[0] = 0x01;
        uint16_t max_payload = SCK_MAX_FRAME_SIZE;
        memcpy(&awake_payload[1], &max_payload, sizeof(max_payload));

        fsp_err_t err = sck_can_send_command();
        if(FSP_SUCCESS != err)
        {
            SEGGER_RTT_printf(0, "APP LOGIC WARN: Failed to send AWAKE response: %d\n", err);
        }
    }
}
