/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			RS232_uart.c
* Creation Date:	Jan 06, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for RS232.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------

#include <Drivers/RS232/includes/RS232_uart.h>
#include "uart_thread.h"

//-------------------------------------- Static Variables -------------------------------------------------------------

static SemaphoreHandle_t g_uart_tx_complete_semaphore = NULL;
static volatile bool RS232_Open = false;

/*************************************************************

 Function Name:  RS232_init(void)
 Description:    initialization of the RS-232.
 Inputs:         void.
 Outputs:        fsp_err_t.
 Author:		 Keerthi Mallesh
****************************************************************/
fsp_err_t RS232_init(void)
{
	if( NULL == g_uart_tx_complete_semaphore )
	{
		g_uart_tx_complete_semaphore = xSemaphoreCreateBinary();
		if (NULL == g_uart_tx_complete_semaphore)
		{
			return FSP_ERR_INTERNAL;
		}
	}

	return FSP_SUCCESS;
}

/*************************************************************

 Function Name:  RS232_open(void)
 Description:    function to start the uart port.
 Inputs:         void.
 Outputs:        fsp_err_t.
 Author:		 Keerthi Mallesh
****************************************************************/
fsp_err_t RS232_open(void)
{
	if (RS232_Open)
	{
		return FSP_ERR_ALREADY_OPEN;
	}

	fsp_err_t err = R_SCI_UART_Open(&RS232_ctrl, &RS232_cfg);
	if (FSP_SUCCESS == err)
	{
		RS232_Open = true;
	}

	return err;
}

/*************************************************************

 Function Name:  RS232_close(void)
 Description:    initialization of the GPIO.
 Inputs:         void.
 Outputs:        fsp_err_t.
 Author:		 Keerthi Mallesh
****************************************************************/
fsp_err_t RS232_close(void)
{
	if(!RS232_Open)
	{
		return FSP_ERR_NOT_OPEN;
	}

	fsp_err_t err = R_SCI_UART_Close(&RS232_ctrl);
	if(FSP_SUCCESS == err)
	{
		RS232_Open = false;
	}

	return err;
}

/****************************************************************

 Function Name:  RS232_callback(uart_callback_args_t *p_args)
 Description:    callback function for RS232.
 Inputs:         uart_callback_args_t *p_args.
 Outputs:        NULL.
 Author:		 Keerthi Mallesh
****************************************************************/
void RS232_callback(uart_callback_args_t *p_args)
{
	switch (p_args->event)
	{
		case UART_EVENT_TX_COMPLETE:
			break;
		case UART_EVENT_RX_CHAR:
		case UART_EVENT_RX_COMPLETE:
		case UART_EVENT_ERR_PARITY:
		case UART_EVENT_ERR_FRAMING:
		case UART_EVENT_ERR_OVERFLOW:
		case UART_EVENT_BREAK_DETECT:
		default:
			break;
	}
}

/****************************************************************

 Function Name:  RS232_write(uint8_t * const p_src,
 	 	 	 	 uint32_t const bytes)
 Description:    this function is reposbile for writing to RS-232.
 Inputs:         uart_callback_args_t *p_args.
 Outputs:        NULL.
 Author:		 Keerthi Mallesh
****************************************************************/
fsp_err_t RS232_write(uint8_t * const p_src, uint32_t const bytes)
{
	if(!RS232_Open)
	{
		return FSP_ERR_NOT_OPEN;
	}

	if( pdTRUE != xSemaphoreTake(g_uart_tx_complete_semaphore, 0) )
	{

	}

	fsp_err_t err = R_SCI_UART_Write(&RS232_ctrl, p_src, bytes);
	if(FSP_SUCCESS != err)
	{
		xSemaphoreGive(g_uart_tx_complete_semaphore);
		return err;
	}

	if (pdTRUE != xSemaphoreTake(g_uart_tx_complete_semaphore, pdMS_TO_TICKS(1000)))
	{
		return FSP_ERR_TIMEOUT;
	}

	return FSP_SUCCESS;
}
