/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:         GPIO_driver.h
* Creation Date:    Jan 19, 2026
* Author:           Keerthi Mallesh
*
* Description:  This file is responsible for creating the GPIO driver.
*
*********************************************************************/

#ifndef SCK_SCK_CAN_INCLUDES_SCK_CAN_PROTOCOL_H_
#define SCK_SCK_CAN_INCLUDES_SCK_CAN_PROTOCOL_H_

#include "hal_data.h"
#include <utils/includes/common_headers.h>
#include <can_thread.h>

//=====================================================================================================================
//-------------------------------------- Macros -----------------------------------------------------------------------
//=====================================================================================================================

#define SCK_FRAME_STX                   (0x02)      // Start of the frame.
#define SCK_FRAME_ETX                   (0x03)      // End of the frame.
#define SCK_FRAME_TYPE_CMD              ('C')
#define SCK_FRAME_TYPE_STATUS           ('S')

#define SCK_PROTOCOL_VERSION_MAJOR      (5)
#define SCK_PROTOCOL_VERSION_MINOR      (0)
#define SCK_PROTOCOL_VERSION_MAINT      (0)
#define SCK_PROTOCOL_VERSION            ((SCK_PROTOCOL_VERSION_MAJOR << 13) | (SCK_PROTOCOL_VERSION_MINOR << 8) | SCK_PROTOCOL_VERSION_MAINT)

#define SCK_CMD_ARE_YOU_THERE           (0x0001)
#define SCK_CMD_APP_MEM_ERASE           (0x0002)
#define SCK_CMD_APP_CHECKSUM            (0x0003)
#define SCK_CMD_BOOTLOADER_CHECKSUM     (0x0004)
#define SCK_CMD_FLASH_DATA_WRITE        (0x0005)
#define SCK_CMD_FLASH_DATA_READ         (0x0006)
#define SCK_CMD_EVENT_REPORT            (0x000B)
#define SCK_CMD_APP_GET_COMMAND         (0x000E)
#define SCK_CMD_APP_SET_COMMAND         (0x000F)
#define SCK_CMD_MULTIPLE_EVENT_REPORT   (0x001B)
#define SCK_CMD_ACTION_COMMAND          (0x0020)

#define SCK_STATUS_AWAKE                (0x0001)
#define SCK_STATUS_SUCCESS              (0x0011)
#define SCK_STATUS_FAILURE              (0x0012)

//=====================================================================================================================
//-------------------------------------- structures & enums -----------------------------------------------------------
//=====================================================================================================================
#pragma pack(1)
typedef struct
{

    uint8_t  stx;           // STX (0x02)
    uint16_t version;       // Protocol Version
    uint16_t length;        // Length of (c_or_s + command + payload)
    uint8_t  tid;           // Transaction ID
    uint8_t  c_or_s;        // 'C' for Command, 'S' for Status
    uint16_t command;       // Command or Status ID
    uint8_t  payload[];     // Flexible payload. CRC and ETX follow this.

} sck_fastlan_raw_frame_t;
#pragma pack()

#define CAN_MAX_PAYLOAD_SIZE   (8)

typedef enum
{

    CAN_FRAME_TYPE_SINGLE = 0x0,    // A single, un-fragmented SCK frame
    CAN_FRAME_TYPE_START  = 0x1,    // The first frame of a fragmented sequence
    CAN_FRAME_TYPE_DATA   = 0x2,    // A middle frame of a fragmented sequence
    CAN_FRAME_TYPE_END    = 0x3     // The final frame of a fragmented sequence

} can_sck_frame_type_t;

 #pragma pack(1)
 /* Structure for the first frame of a fragmented message */
 typedef struct
 {

     uint8_t  frame_type;            // Should be CAN_FRAME_TYPE_START
     uint16_t total_sck_length;      // Total size of the SCK frame being sent
     uint8_t  data[5];               // First chunk of SCK frame data

 } can_sck_start_frame_t;

 /* Structure for a data/middle frame of a fragmented message */
 typedef struct
 {

     uint8_t frame_type;             // Should be CAN_FRAME_TYPE_DATA or CAN_FRAME_TYPE_END
     uint8_t sequence_id;            // Incremental sequence number (rolls over)
     uint8_t data[6];                // Chunk of SCK frame data

 } can_sck_data_frame_t;
 #pragma pack()

 //=====================================================================================================================
 //-------------------------------------- function declaration ---------------------------------------------------------
 //=====================================================================================================================

 fsp_err_t sck_can_send_command(can_ctrl_t * const can_instance, uint16_t command, const uint8_t *p_payload, uint16_t payload_len, uint8_t tid);
 void can_sck_on_received_frame(uint8_t * p_raw_frame, uint16_t len);

#endif /* SCK_SCK_CAN_INCLUDES_SCK_CAN_PROTOCOL_H_ */
