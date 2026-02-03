/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			can_thread_entry.c
* Creation Date:	Jan 30, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for performing the task in
* 				can thread.
*
*********************************************************************/

//-------------------------------------- Includes -----------------------------------------------

#include <can_thread.h>

/***************************************************************************
 Function Name:  can_thread_entry(void *pvParameters)
 Description:    entry function for can thread.
 Inputs:         void *pvParameters
 Outputs:        void.
 Author:		 Keerthi Mallesh
*****************************************************************************/
void can_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */
    while (1)
    {
        vTaskDelay (1);
    }
}
