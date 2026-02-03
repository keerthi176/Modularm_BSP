/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			door_manager.c
* Creation Date:	Jan 13, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for managing the door feature.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------

#include <Application/door_manager/includes/door_manager.h>


#define DOOR_OPEN_ALARM_TIMEOUT_MS 10

//=====================================================================================================================
//-------------------------------------- Static Variables  ---------------------------------------------------------
//=====================================================================================================================
static TimerHandle_t g_door_open_timer = NULL;
static bool g_is_door_alarm_active = false;

/*************************************************************
 Function Name:  Door_Manager_Init(void)
 Description:    function to initializes the door manager.
 Inputs:         NULL.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void Door_Manager_Init(void)
{
	g_door_open_timer = xTimerCreate(
			"DoorAlarmTimer",
			pdMS_TO_TICKS(DOOR_OPEN_ALARM_TIMEOUT_MS),
			pdFALSE,
			(void *) 0,
			door_open_timer_callback
			);

	if(g_door_open_timer == NULL)
	{

	}
}

/*************************************************************
 Function Name:  Door_Manager_Handle_Event(sensor_event_t
 	 	 	 	 *p_event)
 Description:    function for handling the door manager.
 Inputs:         sensor_event_t *p_event.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void Door_Manager_Handle_Event(sensor_event_t *p_event)
{
	if(p_event->sensor_id == SENSOR_ID_DOOR )
	{
		if(p_event->pin_level == BSP_IO_LEVEL_HIGH )
		{
			GPIO_Toggle(LIGHTS_ON);

			xTimerStart(g_door_open_timer, 0);
			SCK_RS232_Send_Event_Report(OID_COOLER_DOOR_AJAR_ALARM, 1);
		}
		else
		{
			GPIO_Toggle(LIGHTS_OFF);

			xTimerStop(g_door_open_timer, 0);
			if(g_is_door_alarm_active == true)
			{
				g_is_door_alarm_active = false;
				SCK_RS232_Send_Event_Report(OID_COOLER_DOOR_AJAR_ALARM, 0);
			}
		}
	}
}

/*************************************************************
 Function Name:  door_open_timer_callback(TimerHandle_t xTimer)
 Description:    function to turn ON the timer.
 Inputs:         TimerHandle_t xTimer.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
static void door_open_timer_callback(TimerHandle_t xTimer)
{
	FSP_PARAMETER_NOT_USED(xTimer);
	g_is_door_alarm_active = true;
	SCK_RS232_Send_Event_Report(OID_COOLER_DOOR_AJAR_ALARM, 1);
}
