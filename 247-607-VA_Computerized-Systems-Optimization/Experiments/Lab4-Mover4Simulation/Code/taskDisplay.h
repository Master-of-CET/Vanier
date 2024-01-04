/**************************************************************************************************
* FileName: taskDisplay.h
*
* Name: Leonardo Fusser (1946995)	Lab 4   Mover4 robotic arm - simulation mode
*									Lab 8	Inverse kinematics application
*
* Description: Header file that contains all required dependencies and all function prototypes used 
*			   in the taskDisplay.c file.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   18 February 2022    v1.0.0		First version of header file.
*													Added includes.
*													Added function prototypes.
*													Completed header file.
* Leonardo Fusser	16 March 2022		v1.0.1		Minor changes.
* Leonardo Fusser	2  April 2022		v2.0.0		Minor changes.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef TASKDISPLAY_H
#define TASKDISPLAY_H

/* Includes. */
#include "public.h"

/* Function prototypes. */
static void* taskDisplay(void* threadid);
void create_taskDisplay(void);
void join_taskDisplay(void);

#endif
