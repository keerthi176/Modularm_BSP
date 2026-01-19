/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			sck_crc.c
* Creation Date:	Jan 14, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the sck crc file.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------
#include "SCK/SCK_RS232/includes/sck_common.h"

/*************************************************************

 Function Name:  SCK_CRC16_Update(uint16_t crc,
 	 	 	 	 uint8_t data_byte)
 Description:    this function is responsible for
				 calculating the CRC fro SCK command.
 Inputs:         gpio_t pin.
 Outputs:        NULL.
 Author:		 Keerthi Mallesh
****************************************************************/
uint16_t SCK_CRC16_Update(uint16_t crc, uint8_t data_byte)
{
    uint16_t crc_low = (uint16_t)((crc & 0xFF) ^ data_byte);

    /* Exact math from SCK FASTLAN V5.00 PDF Appendix Page 19 */
    uint32_t temp_crc = (uint32_t)(crc >> 8) ^
                        (uint32_t)(crc_low << 8) ^
                        (uint32_t)(crc_low << 3) ^
                        (uint32_t)(crc_low << 12) ^
                        (uint32_t)(crc_low >> 4) ^
                        (uint32_t)(crc_low & 0x0F) ^
                        (uint32_t)((crc_low & 0x0F) << 7);

    return (uint16_t)(temp_crc & 0xFFFF);
}
