/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			sck_rs232_tx.c
* Creation Date:	Jan 20, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for sending the response
* 				for received message.
*
*********************************************************************/

//-------------------------------------- Includes -----------------------------------------------
#include <SCK/SCK_RS232/includes/sck_rs232_common.h>

/***************************************************************************
 Function Name:  SCK_Send_Response_Parse_Byte(uint8_t tid,
 	 	 	 	 uint16_t status, const uint8_t *payload, uint16_t len)
 Description:    function for sending the response for the message received.
 Inputs:         uint8_t tid, uint16_t status, const uint8_t *payload,
 	 	 	 	 uint16_t len.
 Outputs:        void.
 Author:		 Keerthi Mallesh
*****************************************************************************/
void SCK_RS232_Send_Response(uint8_t tid, uint16_t status, const uint8_t *payload, uint16_t len)
{
    uint16_t idx = 0;
    uint16_t crc = 0;
    uint16_t length = 3 + len;

    tx_buf[idx++] = SCK_FRAME_START;

    tx_buf[idx++] = SCK_VERSION_LOW;
    tx_buf[idx++] = SCK_VERSION_HIGH;

    tx_buf[idx++] = (uint8_t)(length & 0xFF);
    crc = SCK_CRC16_Update(crc, tx_buf[idx - 1]);

    tx_buf[idx++] = (uint8_t)(length >> 8);
    crc = SCK_CRC16_Update(crc, tx_buf[idx - 1]);

    tx_buf[idx++] = tid;
    crc = SCK_CRC16_Update(crc, tid);

    tx_buf[idx++] = SCK_TYPE_STATUS;
    crc = SCK_CRC16_Update(crc, SCK_TYPE_STATUS);

    tx_buf[idx++] = (uint8_t)(status & 0xFF);
    crc = SCK_CRC16_Update(crc, tx_buf[idx - 1]);

    tx_buf[idx++] = (uint8_t)(status >> 8);
    crc = SCK_CRC16_Update(crc, tx_buf[idx - 1]);

    for (uint16_t i = 0; i < len; i++)
    {
        tx_buf[idx++] = payload[i];
        crc = SCK_CRC16_Update(crc, payload[i]);
    }

    tx_buf[idx++] = (uint8_t)(crc & 0xFF);
    tx_buf[idx++] = (uint8_t)(crc >> 8);

    tx_buf[idx++] = SCK_FRAME_END;

    RS232_write(tx_buf, idx);
}

/*************************************************************
 Function Name:  SCK_CRC16_Update(uint16_t crc,
 	 	 	 	 uint8_t data)
 Description:    function for updating the CRC-16.
 Inputs:         uint8_t byte.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
uint16_t SCK_CRC16_Update(uint16_t crc, uint8_t data)
{
    uint16_t crc_low = (uint16_t)((crc & 0xFF) ^ data);

    uint32_t temp =
        (uint32_t)(crc >> 8) ^
        ((uint32_t)crc_low << 8) ^
        ((uint32_t)crc_low << 3) ^
        ((uint32_t)crc_low << 12) ^
        ((uint32_t)(crc_low >> 4)) ^
        ((uint32_t)(crc_low & 0x0F)) ^
        ((uint32_t)((crc_low & 0x0F) << 7));

    return (uint16_t)(temp & 0xFFFF);
}

/*************************************************************
 Function Name:  SCK_RS232_Send_Event_Report(uint16_t oid,
 	 	 	 	 uint16_t value)
 Description:    function for sending event report.
 Inputs:         uint16_t oid, uint16_t value.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void SCK_RS232_Send_Event_Report(uint16_t oid, uint16_t value)
{
	uint8_t payload[4];

	payload[0] = (uint8_t)(oid & 0xFF);
	payload[1] = (uint8_t)(oid >> 8);
	payload[2] = (uint8_t)(value & 0xFF);
	payload[3] = (uint8_t)(value >> 8);

	SCK_RS232_Send_Response(0, SCK_STAT_ID_EVENT_REPORT, payload, sizeof(payload));
}
