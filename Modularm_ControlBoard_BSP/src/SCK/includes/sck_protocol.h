/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			sck_protocol.h
* Creation Date:	Jan 20, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for framing common sck
* 				protocol for RS-232 and CAN.
*
*********************************************************************/
#ifndef SCK_PROTOCOL_H_
#define SCK_PROTOCOL_H_

#include <utils/includes/common_headers.h>

//=====================================================================================================================
//---------------------------------------------- Macros ---------------------------------------------------------------
//=====================================================================================================================
#define SCK_DEVICE_STATE_BOOTING				0x00
#define SCK_DEVICE_STATE_RUNNING				0x01
#define SCK_DEVICE_STATE_FAULT					0x02


#define SCK_AYT_CMD_PAYLOAD_LEN					1
#define SCK_AYT_STAT_PAYLOAD_LEN				1

#define SCK_ACTION_PAYLOAD_MIN_LEN				3

#define SCK_ACTION_PARAM_OFF					0x00
#define SCK_ACTION_PARAM_ON						0x01

#define SCK_ERROR_NONE							0x00
#define SCK_ERROR_HW_FAULT						(1U << 0)
#define SCK_ERROR_COMM_FAULT					(1U << 1)
#define SCK_ERROR_OVERTEMP						(1U << 2)

#define SCK_SIB_ID_PAYLOAD_LEN       4

#define SCK_U16_FROM_PAYLOAD(p, i) \
    ((uint16_t)((p)[(i)] | ((uint16_t)(p)[(i)+1] << 8)))

#define SCK_U16_TO_PAYLOAD(p, i, v)     \
    do {                               \
        (p)[(i)]   = (uint8_t)(v);     \
        (p)[(i)+1] = (uint8_t)((v)>>8);\
    } while (0)

#endif
