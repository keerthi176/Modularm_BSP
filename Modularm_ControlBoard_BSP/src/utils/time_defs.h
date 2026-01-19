/********************************************************************
*
* Redistribution and use in source and binary forms, with or without
* modification, are not permitted.
*
* Filename:			time_defs.h
* Creation Date:	Jan 06, 2026
* Author:			Keerthi Mallesh
*
* Description:	This file is responsible for creating the time
* 				definition.
*
*********************************************************************/

#ifndef UTILS_TIME_DEFS_H_
#define UTILS_TIME_DEFS_H_

#define TIME_MS_PER_SECOND      (1000UL)
#define TIME_MS_PER_MINUTE		(60UL * TIME_MS_PER_SECOND)
#define TIME_MS_PER_HOUR        (60UL * TIME_MS_PER_MINUTE)

#define SEC_TO_MS(seconds)      ((seconds) * TIME_MS_PER_SECOND)
#define MIN_TO_MS(minutes)      ((minutes) * TIME_MS_PER_MINUTE)
#define HR_TO_MS(hours)         ((hours) * TIME_MS_PER_HOUR)

#endif /* UTILS_TIME_DEFS_H_ */
