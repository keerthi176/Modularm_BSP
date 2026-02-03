/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			uart_thread_entry.c
* Creation Date:	Jan 22, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for processing the receiving
* 				sck command.
*
*********************************************************************/

//-------------------------------------- Includes -----------------------------------------------

#include "uart_thread.h"

#include "SCK/SCK_RS232/includes/sck_rs232_common.h"
#include "Drivers/RS232/includes/RS232_uart.h"

/*************************************************************
 Function Name:  uart_thread_entry(void *pvParameters)
 Description:    entry function for sensor thread.
 Inputs:         void *pvParameters.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void uart_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    SCK_RS232_Init();

    uint8_t rx_buffer[32];

    fsp_err_t err;

    while (1)
    {
    	err  = R_SCI_UART_Read(&RS232_ctrl, rx_buffer, sizeof(rx_buffer));

    	if(FSP_SUCCESS == err )
    	{
    		for(uint8_t i = 0; i < sizeof(rx_buffer); i++)
    		{
    			SCK_RS232_Parse_Byte(rx_buffer[i]);
    		}
    	}
    	else
    	{
    		SCK_RS232_Init();
    	}

        vTaskDelay (1);
    }
}
