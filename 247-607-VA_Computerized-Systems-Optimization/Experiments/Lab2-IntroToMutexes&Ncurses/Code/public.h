/**************************************************************************************************
* FileName: public.h
*
* Name: Leonardo Fusser (1946995)   Lab 2   Introduction to mutex synchronization & Ncurses library
*									Lab 3	Moving Snake Application
*
* Description: Header file that includes all required dependencies for Lab 2 and Lab 3, and that 
*			   includes some common macros used for Lab 2 and Lab 3.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       ?                   v1.0.0      First version of header file.
* Leonardo Fusser   28 January 2022     v1.0.1		Minor changes.
* Leonardo Fusser	6 February 2022		v1.0.2		Added macros for Lab 3.
*													Added comments.
*													GITHUB COMMIT & PUSH TEST.
* Leonardo Fusser	11 February 2022	v1.0.3		Completed header file.
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

#include "../header/ncurses_init.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <stdint.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <pthread.h>
#include "threadKeybd.h"
#include "threadDisplay.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////


/* Macro to swap between Lab 2 and Lab 3 code. */
//#define LAB2


/* Lab 2 macros. */////////////////////////////////////////////////////////////
/* Macro to swap between protected print mode and unprotected print mode. */
//#define MUTEX_PRINT

/* Macro to swap between blocking and non-blocking delay. */
//#define BLOCKING
///////////////////////////////////////////////////////////////////////////////


/* Lab 3 macros. */////////////////////////////////////////////////////////////
/* Macros to specify window border limits for moving snake. */
#define X1_WindowLimit	0
#define X2_WindowLimit	116
#define Y1_WindowLimit	13
#define Y2_WindowLimit	28
///////////////////////////////////////////////////////////////////////////////

#endif
