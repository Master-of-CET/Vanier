/**************************************************************************************************
* FileName: public.h
*
* Name: Leonardo Fusser (1946995)   Lab 4   Mover4 robotic arm - simulation mode
*									Lab 6	Mini assembly line
*									Lab 7	Kinematics library for a robotic arm in C
*									Lab 8	Inverse kinematics application
*
* Description: Header file that contains all the required dependencies for all files used in this
*			   lab. All commonly used macros are defined below.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   18 February 2022    v1.0.0      First version of header file.
*													Added includes.
*													Added macros.
*													Added comments.	
*													Completed header file.
* Leonardo Fusser	4 March 2022		v2.0.0		Added more includes.
*													Removed <conio.h> include.
*													Cleaned up comments.
* Leonardo Fusser	16 March 2022		v2.0.1		Added more macros.
*													Added comments.
* Leonardo Fusser	25 March 2022		v3.0.0		Minor changes.
* Leonardo Fusser	2  April 2022		v4.0.0		Added more includes.
*													Added comments.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef PUBLIC_H
#define PUBLIC_H


/* Includes. *///////////////////////////////////////////////////////////////////////////////////////
#ifdef _WIN32
#include <Windows.h>
#define HAVE_STRUCT_TIMESPEC		//For win32 only. Because TIMESPEC is re-defined inside pthread.h
#else
#include <unistd.h>
#include <ncurses.h>
#include <sys/ioctl.h>
//#include <sys/time.h>
//#include <libgen.h>
#endif

#include "../header/can.h"
#include "../header/task_controller.h"
#include "../header/ncurses_init.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <stdint.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <pthread.h>
#include <math.h>
#include "taskKeybd.h"
#include "taskDisplay.h"
#include "taskAuto.h"
#include "Kinematics.h"
#include "taskInvKin.h"
#include "adc.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////


/* Mover4 joint macros. */
#define BASE		0	//Mover4 base.
#define SHOULDER	1	//Mover4 shoulder.
#define ELBOW		2	//Mover4 elbow.
#define	WRIST		3	//Mover4 wrist.

/* Other macros. */
#define DELAY_10mS	10	//For small blocking delay.


#endif
