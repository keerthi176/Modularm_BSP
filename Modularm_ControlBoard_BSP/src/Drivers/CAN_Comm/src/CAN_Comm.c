/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			CAN_Comm.c
* Creation Date:	Jan 06, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the driver
* 				for RS232.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------

#include <Drivers/CAN_Comm/includes/CAN_Comm.h>

//-------------------------------------- Function Definition -----------------------------------------------

/*************************************************************

 Function Name:  CAN_init(void)
 Description:    initialization of the CAN.
 Inputs:         void.
 Outputs:        NULL.
 Author:		 Keerthi Mallesh
****************************************************************/
void CAN_init(void)
{
	fsp_err_t err;

	R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_02_PIN_11, BSP_IO_LEVEL_HIGH);

	err = R_CANFD_Open(&g_canfd1_ctrl, &g_canfd1_cfg);
	if(FSP_SUCCESS != err)
	{
		return;
	}

	b_can_ready = true;
}

/*************************************************************

 Function Name:  can_callback(can_callback_args_t *p_args)
 Description:    can callback.
 Inputs:         can_callback_args_t *p_args.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void can_callback(can_callback_args_t *p_args)
{
	switch (p_args->event)
	{
		case CAN_EVENT_TX_COMPLETE:
			break;
		case CAN_EVENT_RX_COMPLETE:
			break;
		case CAN_EVENT_ERR_BUS_OFF:
		case CAN_EVENT_ERR_PASSIVE:
		case CAN_EVENT_ERR_WARNING:
			break;
		default:
			break;
	}
}

/*************************************************************

 Function Name:  CAN_Send_SIB_Command(uint32_t sib_id,
 	 	 	 	 uint8_t *data, uint8_t len)
 Description:    initialization of the CAN.
 Inputs:         uint32_t sib_id, uint8_t *data, uint8_t len.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void CAN_Send_SIB_Command(uint32_t sib_id, uint8_t *data, uint8_t len)
{
	can_frame_t frame;

	frame.id 				= sib_id;
	frame.type 				= CAN_FRAME_TYPE_DATA;
	frame.data_length_code 	= len;

	for(int i=0; i<len; i++)
	{
		frame.data[i] = data[i];
	}

	R_CANFD_Write(&g_canfd1_ctrl, 0, &frame);
}
