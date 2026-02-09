/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			motion_detector_manager.c
* Creation Date:	Feb 03, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for managing the
* 				motion detection.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------

#include <Application/motion_detector_manager/includes/motion_detector_manager.h>

//=====================================================================================================================
//-------------------------------------- Static Variables  ------------------------------------------------------------
//=====================================================================================================================
static TimerHandle_t	g_motion_detector_timer		= NULL;
static bool 		 	g_is_motion_detector_active	= false;

//-------------------------------------- Function Definition -----------------------------------------------

 /*************************************************************
 Function Name:  Door_Manager_Init(void)
 Description:    function to initializes the motion detection.
 Inputs:         NULL.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void motion_detection_Init(void)
{
	g_motion_detector_timer = xTimerCreate(
			"motionDetectorTimer",
			pdMS_TO_TICKS(OID_COOLER_MOTION_DETECTION),
			pdFALSE,
			(void *) 0,
			motion_detector_timer_callback
			);

	if(g_motion_detector_timer == NULL)
	{

	}
}

/*************************************************************
 Function Name:  motion_detection_Handle_Event(sensor_event_t
 	 	 	 	 *p_event)
 Description:    function for handling the motion detection.
 Inputs:         sensor_event_t *p_event.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void motion_detection_Handle_Event(sensor_event_t *p_event)
{
	if(p_event->sensor_id == SENSOR_ID_DOOR )
	{
		if(p_event->pin_level == TURN_ON )
		{
//			GPIO_Toggle(LIGHTS_ON);

			xTimerStart(g_motion_detector_timer, 0);
			SCK_RS232_Send_Event_Report(OID_COOLER_MOTION_DETECTION, 1);
		}
		else
		{
//			GPIO_Toggle(LIGHTS_OFF);

			xTimerStop(g_motion_detector_timer, 0);
			if(g_is_motion_detector_active == true)
			{
				g_is_motion_detector_active = false;
				SCK_RS232_Send_Event_Report(OID_COOLER_MOTION_DETECTION, 0);
			}
		}
	}
}

/*************************************************************
 Function Name:  motion_detector_timer_callback(TimerHandle_t xTimer)
 Description:    function to turn ON the timer.
 Inputs:         TimerHandle_t xTimer.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
static void motion_detector_timer_callback(TimerHandle_t xTimer)
{
	FSP_PARAMETER_NOT_USED(xTimer);
	g_is_motion_detector_active = true;
	SCK_RS232_Send_Event_Report(OID_COOLER_MOTION_DETECTION, 1);
}
