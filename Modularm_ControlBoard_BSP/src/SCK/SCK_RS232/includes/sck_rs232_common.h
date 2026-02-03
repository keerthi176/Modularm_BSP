/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			sck_rs232_common.h
* Creation Date:	Jan 20, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for framing the sck
* 				command for can bus.
*
*********************************************************************/

#ifndef SCK_SCK_RS232_INCLUDES_SCK_RS232_COMMON_H_
#define SCK_SCK_RS232_INCLUDES_SCK_RS232_COMMON_H_

#include "SCK/includes/sck_common.h"
#include <utils/includes/common_headers.h>
#include <Drivers/RS232/includes/RS232_uart.h>
//=====================================================================================================================
//------------------------------------------- structures & enums  -----------------------------------------------------
//=====================================================================================================================
typedef enum
{

    SCK_STATE_STX = 0,
    SCK_STATE_VERSION_LOW,
    SCK_STATE_VERSION_HIGH,
    SCK_STATE_LENGTH_LOW,
    SCK_STATE_LENGTH_HIGH,
    SCK_STATE_TID,
    SCK_STATE_TYPE,
    SCK_STATE_COMMAND_LOW,
    SCK_STATE_COMMAND_HIGH,
    SCK_STATE_DATA,
    SCK_STATE_CRC_LOW,
    SCK_STATE_CRC_HIGH,
    SCK_STATE_ETX

} sck_parse_state_t;

typedef struct
{

    sck_parse_state_t state;
    sck_frame_t       frame;
    uint16_t          rx_length;
    uint16_t          crc_calc;
    uint16_t          crc_rx;
    uint16_t          data_idx;
    uint16_t          version;

} sck_rs232_ctx_t;

//=====================================================================================================================
//------------------------------------------- static variable  -------------------------------------------------------
//=====================================================================================================================
static uint8_t tx_buf[SCK_MAX_PAYLOAD_SIZE + 16];
static sck_rs232_ctx_t g_ctx;

//=====================================================================================================================
//------------------------------------------- Function Declaration  ---------------------------------------------------
//=====================================================================================================================

// sck_rs232_parser.c file.
void SCK_RS232_Parse_Byte(uint8_t byte);
void SCK_RS232_Init(void);

// sck_rs232_tx.c file.
void SCK_RS232_Send_Response(uint8_t tid, uint16_t status, const uint8_t *payload, uint16_t len);

#endif
