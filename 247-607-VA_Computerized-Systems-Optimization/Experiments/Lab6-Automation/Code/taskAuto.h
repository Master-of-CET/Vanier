/**************************************************************************************************
* FileName: taskAuto.h
*
* Name: Leonardo Fusser (1946995)	Lab 6   Mini assembly line
*
* Description: Header file that contains all required dependencies and all function prototypes used
*			   in the taskAuto.c file.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   4 March 2022		v1.0.0		First version of header file.
*													Added includes.
*													Added function prototypes.
* Leonardo Fusser	16 March 2022		v1.0.1		Added more function prototypes.
* Leonardo Fusser	26 March 2022		v1.0.2		Added joint error macro.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef TASKAUTO_H
#define TASKAUTO_H

/* Includes. */
#include "public.h"

#define	_ERROR		3			//Mover4 robot arm joint error (in degrees).

/* Function prototypes. */
void* taskAuto(void* threadid);
void create_taskAuto(void);
void cancel_taskAuto(void);
void setAllJoints_0(void);
float getDistance(void);
void taskAuto_old(void);
void taskAuto_new(void);
void move_until(double sp_base, double sp_shoulder, double sp_elbow, double sp_wrist);

#endif
