/**************************************************************************************************
* FileName: taskKeybd.h
*
* Name: Leonardo Fusser (1946995)	Lab 4   Mover4 robotic arm - simulation mode
*									Lab 6	Mini assembly line
*									Lab 8	Inverse kinematics application
*
* Description: Header file that contains all required dependencies and all function prototypes used 
*			   in the taskKeybd.c file.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   18 February 2022     v1.0.0		First version of header file.
*													Added includes.
*													Added function prototypes.
*													Completed header file.
* Leonardo Fusser	2  April 2022		 v2.0.0		Minor changes.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef TASKKEYBD_H
#define TASKKEYBD_H

/* Includes. */
#include "public.h"

/* Function prototypes. */
static void* taskKeybd(void* threadid);
void create_taskKeybd(void);
void join_taskKeybd(void);

#endif
