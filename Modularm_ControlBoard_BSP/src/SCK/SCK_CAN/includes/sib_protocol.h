/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			sib_protocol.h
* Creation Date:	Jan 14, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating frame
* 				structure for sib boards.
*
*********************************************************************/

#ifndef SCK_SCK_CAN_INCLUDES_SIB_PROTOCOL_H_
#define SCK_SCK_CAN_INCLUDES_SIB_PROTOCOL_H_

#include <utils/includes/common_headers.h>

//=====================================================================================================================
//-------------------------------------- Board Address ----------------------------------------------------------------
//=====================================================================================================================

#define BOARD_ID_MASTER_CONTROL					0x10

#define BOARD_ID_SIB_DEFROST					0x20
#define BOARD_ID_SIB_EVAPORATOR					0x21
#define BOARD_ID_SIB_CONDENSER					0x22
#define BOARD_ID_SIB_COMPRESSOR					0x23
#define BOARD_ID_SIB_MONITORING					0x24
#define BOARD_ID_SIB_REFRIGERANT				0x25

//=====================================================================================================================
//-------------------------------------- Board Address ----------------------------------------------------------------
//=====================================================================================================================

#define SIB_MSG_HEARTBEAT						0x01
#define SIB_MSG_ACK								0x02
#define SIB_MSG_NACK							0x03

// Master to SIB communication.
#define SIB_MSG_SET_RELAY						0x10
#define SIB_MSG_SET_ANALOG_OUT					0x11

// SIB to Master communication.
#define SIB_MSG_DIGITAL_CHANGE					0x20
#define SIB_MSG_ANALOG_UPDATE					0x21

//=====================================================================================================================
//-------------------------------------- CAN ID construction Macros ---------------------------------------------------
//=====================================================================================================================
#define SIB_PRIORITY_HIGH						0x0
#define SIB_PRIORITY_NORMAL						0x4

#define GET_SOURCE_FROM_ID(id)					((id >> 18) & 0xFF)
#define GET_TARGET_FROM_ID(id)					((id >> 10) & 0xFF)
#define GET_TYPE_FROM_ID(id)					((id >> 2) & 0xFF)

#define BUILD_CAN_ID(prio, src, target, type) \
			(uint32_t)( ((prio & 0x7) << 26) | ((src & 0xFF) << 18) | ((target & 0xFF) << 10) | ((type & 0xFF) << 2) )

#endif
