/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			sck_common.h
* Creation Date:	Jan 20, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for framing the sck command.
*
*********************************************************************/
#ifndef SCK_COMMON_H_
#define SCK_COMMON_H_

#include <utils/includes/common_headers.h>

//=====================================================================================================================
//------------------------------------------- Macros  ----------------------------------------------------------------
//=====================================================================================================================
#define SCK_FRAME_START				0x02
#define SCK_FRAME_END				0x03

#define SCK_VERSION_LOW				0x00
#define SCK_VERSION_HIGH			0xA0

#define SCK_MAX_PAYLOAD_SIZE		1020

//=====================================================================================================================
//-------------------------------------- structures & enums -----------------------------------------------------------
//=====================================================================================================================

typedef enum {

    SCK_TYPE_COMMAND				= 0x43,
    SCK_TYPE_STATUS					= 0x53

} sck_frame_type_t;

typedef enum {

    SCK_CMD_ID_ARE_YOU_THERE		= 0x0001,
    SCK_CMD_ID_ACTION				= 0x0020,
	SCK_CMD_ID_FORWARD_TO_SIB       = 0x0030

} sck_command_id_t;

typedef enum {

    SCK_STAT_ID_AWAKE				= 0x0001,
	SCK_STAT_ID_EVENT_REPORT        = 0x000B,
	SCK_STAT_ID_TEMPERATURE_REPORT  = 0x8004,
    SCK_STAT_ID_SUCCESS				= 0x0011,
    SCK_STAT_ID_FAILURE				= 0x0012,
    SCK_STAT_ID_NACK				= 0x0015

} sck_status_id_t;

typedef enum {

    SCK_ACTION_LIGHT_CONTROL		= 0x0102,
    SCK_ACTION_FORCE_ALARM			= 0x0101

} sck_action_sub_id_t;

typedef enum {

	SCK_INTERFACE_NONE,
	SCK_INTERFACE_RS232,
	SCK_INTERFACE_CAN

} sck_interface_t;

typedef struct {

    uint8_t				tid;
    uint8_t				type;
    uint16_t			cmd;
    uint16_t			payload_len;
    uint8_t				payload[SCK_MAX_PAYLOAD_SIZE];
    sck_interface_t		interface;
    uint8_t				source_id;

} sck_frame_t;

//=====================================================================================================================
//-------------------------------------- Function Declarations  -------------------------------------------------------
//=====================================================================================================================
void 		SCK_Process_Received_Frame	(const sck_frame_t *frame);
uint16_t	SCK_CRC16_Update			(uint16_t crc, uint8_t data);
void 		handle_SoC_command			(const sck_frame_t *frame);
void 		handle_sib_response			(const sck_frame_t *frame);
void		SCK_RS232_Send_Event_Report (uint16_t oid, uint16_t value);

#endif
