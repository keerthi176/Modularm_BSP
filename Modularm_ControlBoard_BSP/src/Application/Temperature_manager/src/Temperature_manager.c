/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			temperature_manager.c
* Creation Date:	Feb 09, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for managing the temperature.
*
*********************************************************************/

//-------------------------------------- Includes -------------------------------------------------------------

#include <Application/Temperature_manager/includes/Temperature_manager.h>
#include "timers.h"

//-------------------------------------- Function Definition ----------------------------------------------------

/*************************************************************
 Function Name:  temp_delay_timer_callback
 Description:    callback function of temp delay timer.
 Inputs:         timer_callback_args_t *p_args
 Outputs:        None
 Author:		 Keerthi Mallesh
****************************************************************/
static void temp_delay_timer_callback(timer_callback_args_t *p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    if (s_current_monitor_state  == TEMP_STATE_ABNORMAL)
    {
        s_current_monitor_state  = TEMP_STATE_ALARM;
        uint16_t alert_oid = 0;

        switch(s_current_alarm_type)
        {
        	case TEMP_ALARM_HIGH:
        		alert_oid = OID_HIGH_TEMPERATURE_ALERT;
        		break;

			case TEMP_ALARM_LOW:
				alert_oid = OID_LOW_TEMPERATURE_ALERT;
				break;

			default:
				// No alerts to send
				break;
        }

        if(alert_oid != 0 )
        {
        	// As of now payload i s empty need to build robust mechanism for that
        	SCK_RS232_Send_Event_Report(alert_oid, 0);
        }
    }
}

/*************************************************************
 Function Name:  temperature_monitor_init
 Description:    initializes the temperature monitor.
 Inputs:         None.
 Outputs:        void.
 Author:		 Keerthi Mallesh
****************************************************************/
void temperature_monitor_init(void)
{
    thermistor_init();
    s_current_monitor_state 	= TEMP_STATE_NORMAL;
    s_current_alarm_type 		= TEMP_ALARM_NONE;

    timer_cfg_t temp_timer_cfg 	= g_timer0_cfg;
    temp_timer_cfg.p_callback 	= temp_delay_timer_callback;
    R_GPT_Open(&g_timer0_ctrl, &temp_timer_cfg);
}

/*************************************************************
 Function Name:  temperature_monitor_process
 Description:    monitors the temperature process.
 Inputs:         None
 Outputs:        void
 Author:		 Keerthi Mallesh
****************************************************************/
void temperature_monitor_process(void)
{
    float raw_temp_celsius 		= thermistor_get_temp_celsius();

    if ( isnan(raw_temp_celsius))
    {
        if (s_current_monitor_state != TEMP_STATE_ALARM || s_current_alarm_type != TEMP_ALARM_PROBE_FAULT)
        {
            s_current_monitor_state = TEMP_STATE_ALARM;
            s_current_alarm_type 	= TEMP_ALARM_PROBE_FAULT;
            R_GPT_Stop(&g_timer0_ctrl);
        }
    }
    else
    {
        if (s_current_alarm_type 	== TEMP_ALARM_PROBE_FAULT)
        {
            s_current_monitor_state = TEMP_STATE_NORMAL;
            s_current_alarm_type 	= TEMP_ALARM_NONE;
        }

        float calibrated_temp_celsius = raw_temp_celsius + s_app_config.temp_calibration_offset_c;
        update_monitor_state(calibrated_temp_celsius);
    }
}

/*************************************************************
 Function Name:  update_monitor_state
 Description:    responsible for updating the monitor state.
 Inputs:         float current_temp
 Outputs:        void
 Author:		 Keerthi Mallesh
****************************************************************/
static void update_monitor_state(float current_temp)
{
    bool over_high_limit = (current_temp > s_app_config.temp_high_limit_c);
    bool under_low_limit = (current_temp < s_app_config.temp_low_limit_c);

    switch (s_current_monitor_state)
    {
        case TEMP_STATE_NORMAL:
            if (over_high_limit || under_low_limit)
            {
                s_current_monitor_state = TEMP_STATE_ABNORMAL;
                s_current_alarm_type 	= over_high_limit ? TEMP_ALARM_HIGH : TEMP_ALARM_LOW;

                uint32_t period_ticks 	= SECONDS_TO_TIMER_TICKS(s_app_config.temp_alarm_delay_seconds);
                R_GPT_PeriodSet(&g_timer0_ctrl, period_ticks);
                R_GPT_Start(&g_timer0_ctrl);
            }
            break;

        case TEMP_STATE_ABNORMAL:
            if (!over_high_limit && !under_low_limit)
            {
                s_current_monitor_state = TEMP_STATE_NORMAL;
                s_current_alarm_type 	= TEMP_ALARM_NONE;
                R_GPT_Stop(&g_timer0_ctrl);
            }
            else if ((over_high_limit && s_current_alarm_type == TEMP_ALARM_LOW) ||
                     (under_low_limit && s_current_alarm_type == TEMP_ALARM_HIGH))
            {
                s_current_alarm_type = over_high_limit ? TEMP_ALARM_HIGH : TEMP_ALARM_LOW;
                R_GPT_Stop(&g_timer0_ctrl);
                R_GPT_Start(&g_timer0_ctrl);
            }
            break;

        case TEMP_STATE_ALARM:
            if (!over_high_limit && !under_low_limit)
            {
                s_current_monitor_state = TEMP_STATE_NORMAL;
                s_current_alarm_type 	= TEMP_ALARM_NONE;
            }
            break;

        default:
            s_current_monitor_state = TEMP_STATE_NORMAL;
            break;
    }
}

/*************************************************************
 Function Name:  temperature_monitor_get_state
 Description:    responsible for returning the current monitor
 	 	 	 	 state.
 Inputs:         None
 Outputs:		 temp_monitor_state_t
 Author:		 Keerthi Mallesh
****************************************************************/
temp_monitor_state_t temperature_monitor_get_state(void)
{
    return s_current_monitor_state;
}

/*************************************************************
 Function Name:  temperature_monitor_get_alarm_type
 Description:    responsible for returning the current monitor
 	 	 	 	 state.
 Inputs:         None
 Outputs:		 temp_monitor_state_t
 Author:		 Keerthi Mallesh
****************************************************************/
temp_alarm_type_t temperature_monitor_get_alarm_type(void)
{
    return s_current_alarm_type;
}
