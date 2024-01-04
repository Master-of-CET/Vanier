/**************************************************************************************************
* FileName: Kinematics.h
*
* Name: Leonardo Fusser (1946995)	Lab 7   Kinematics library for a robotic arm in C
*
* Description: Header file that contains all required dependencies and all function prototypes used
*			   in the Kinematics.c file.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   25 March 2022		v1.0.0		First version of header file.
*													Added includes.
*													Added function prototypes.
*													Completed header file.
* Leonardo Fusser	26 March 2022		v1.0.1		Added Mover4 joint length macros.
*													Added Mover4 gripper position struct macros.
*													Added comments.
* Leonardo Fusser	2  April 2022		v2.0.0		Minor changes.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef KINEMATICS_H
#define KINEMATICS_H

/* Includes. */
#include "public.h"

/* Mover4 joint length macros. */
#define		BASE_HEIGHT		8.11
#define		HUMERUS_LENGTH	7.48
#define		ARM_LENGTH		8.66
#define		GRIP_LENGTH		5.51

/* Mover4 gripper position struct macros. */
#define GRIP_X	0
#define GRIP_Y	1
#define	GRIP_Z	2

/* Function prototypes. */
double to_radians(double temp_degrees);
double to_degrees(double temp_radians);
kin_f to_angle(double temp_x, double temp_y, double temp_z, double temp_GripAngle);
kin_i to_cart(double temp_BaseAngle, double temp_ShldAngle, double temp_ElbAngle, double temp_WristAngle);

#endif
