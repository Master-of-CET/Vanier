/**************************************************************************************************
* FileName: taskInvKin.h
*
* Name: Leonardo Fusser (1946995)	Lab 8   Inverse kinematics application
*
* Description: Header file that contains all required dependencies and all function prototypes used
*			   in the taskInvKin.c file.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   1 April 2022		v1.0.0		First version of header file.
*													Added function prototypes.
*													Added comments.
* Leonardo Fusser	2 April 2022		v1.0.1		Added macros.
*													Added function prototype.
*													Added comments.
* Leonardo Fusser	5 April 2022		v1.0.2		Minor changes.
*													Completed header file.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef TASKINVKIN_H
#define TASKINVKIN_H

/* Includes. */
#include "public.h"

/* Macros. */
#define GRIP_ANGLE	-40.0
#define OFFSET_Z	15.0
#define OFFSET_Y	0.0
#define RADIUS		5.0
#define X0			15.0

/* Function prototypes. */
void* taskInvKin(void* threadid);
void create_taskInvKin(void);
void cancel_taskInvKin(void);
void circle_yz_plane(void);

#endif
