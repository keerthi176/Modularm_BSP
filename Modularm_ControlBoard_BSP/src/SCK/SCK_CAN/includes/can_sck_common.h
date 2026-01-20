/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			can_sck_common.h
* Creation Date:	Jan 20, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for framing the sck
* 				command for can bus.
*
*********************************************************************/
#ifndef CAN_SCK_COMMON_H_
#define CAN_SCK_COMMON_H_

#include <utils/includes/common_headers.h>

//=====================================================================================================================
//------------------------------------------- Macros  ----------------------------------------------------------------
//=====================================================================================================================
#define CAN_NODE_CONTROL					0x1
#define CAN_NODE_BROADCAST					0xF

#define CAN_MSG_CLASS_SCK					0x1

#define CAN_ID_SCK(src, dst) \
    (((CAN_MSG_CLASS_SCK & 0x7) << 8) | ((src & 0xF) << 4) | (dst & 0xF))

#endif
