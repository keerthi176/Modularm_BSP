/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			sck_common.h
* Creation Date:	Jan 13, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the
* 				sck command frame structure
*
*********************************************************************/
#ifndef SCK_INCLUDES_SCK_COMMON_H_
#define SCK_INCLUDES_SCK_COMMON_H_

#include <utils/includes/common_headers.h>

//=====================================================================================================================
//-------------------------------------- frame constants -------------------------------------------------------------
//=====================================================================================================================
#define SCK_FRAME_START					0x02	// Start of frame.
#define SCK_FRAME_END					0x03	// End of frame.
#define SCK_PROTOCOL_VERSION			5		// SCK 5 protocol V5.00

#define SCK_MAX_PAYLOAD_SIZE			256		// Need to adjust as per the packet size.

//=====================================================================================================================
//-------------------------------------- Command ID's -------------------------------------------------------------
//=====================================================================================================================
typedef enum {

	SCK_CMD_ID_ARE_YOU_THERE         	= 0x0001,
	SCK_CMD_ID_APP_ERASE             	= 0x0002,
	SCK_CMD_ID_APP_CHECKSUM          	= 0x0003,
	SCK_CMD_ID_BOOT_CHECKSUM         	= 0x0004,
	SCK_CMD_ID_FLASH_WRITE           	= 0x0005,
	SCK_CMD_ID_FLASH_READ            	= 0x0006,
	SCK_CMD_ID_EVENT_REPORT          	= 0x000B,
	SCK_CMD_ID_APP_GET               	= 0x000E,
	SCK_CMD_ID_APP_SET               	= 0x000F,
	SCK_CMD_ID_MULTIPLE_EVENT_REPORT	= 0x001B,
	SCK_CMD_ID_ACTION                	= 0x0020,
	SCK_CMD_ID_V3_LEGACY             	= 0xFF55

} sck_command_id_t;

//=====================================================================================================================
//-------------------------------------- Status ID's -------------------------------------------------------------
//=====================================================================================================================
typedef enum {

	 SCK_STAT_ID_NONE                 	= 0x0000,
	 SCK_STAT_ID_AWAKE                	= 0x0001,
	 SCK_STAT_ID_UNKNOWN_CMD          	= 0x0002,
	 SCK_STAT_ID_REFLASH_SUCCESS      	= 0x0003,
	 SCK_STAT_ID_ACK                  	= 0x0006,
	 SCK_STAT_ID_SUCCESS              	= 0x0011,
	 SCK_STAT_ID_FAILURE              	= 0x0012,
	 SCK_STAT_ID_NACK                 	= 0x0015

} sck_status_id_t;

//=====================================================================================================================
//-------------------------------------- OID's -------------------------------------------------------------
//=====================================================================================================================

typedef enum {

	SCK_ACTION_ALARM_MUTE				= 0x0100,
	SCK_ACTION_FORCE_ALARM				= 0x0101,
	SCK_ACTION_LIGHT_CONTROL			= 0x0102,
	SCK_ACTION_CLEAR_LATCH				= 0x0103

	// todo.. other OID's need to be added in future development.

} sck_action_sub_id_t;

//=====================================================================================================================
//-------------------------------------- structures & enums ----------------------------------------------------------
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
	uint8_t  tid;
	uint8_t  type;								// 'C' or 'S'
	uint16_t id;
	uint16_t data_len;
	uint8_t  data[SCK_MAX_PAYLOAD_SIZE];

} sck_frame_t;

typedef enum {

	SCK_TYPE_COMMAND 					= 0x43,
	SCK_TYPE_STATUS  					= 0x53

 } sck_frame_type_t;

//=====================================================================================================================
//-------------------------------------- function Declaration ---------------------------------------------------------
//=====================================================================================================================

//-------------------------------------- sck_crc -------------------------------------------------------------
uint16_t SCK_CRC16_Update(uint16_t crc, uint8_t data_byte);

//-------------------------------------- sck_manager -------------------------------------------------------------
void SCK_Parse_Byte(uint8_t byte);
void SCK_Send_Frame(uint8_t tid, uint8_t type, uint16_t command_id, uint8_t *data, uint16_t len);
void SCK_Process_Received_Frame(void);

#endif
