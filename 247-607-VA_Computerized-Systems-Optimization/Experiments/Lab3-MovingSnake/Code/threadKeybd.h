/**************************************************************************************************
* FileName: threadKeybd.h
*
* Name: Leonardo Fusser (1946995)	Lab 3	Moving Snake Application
*
* Description: Header file that contains all required dependencies and all function prototypes used 
*			   in the threadKeybd.c file.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   28 January 2022     v1.0.1		First version of header file.
*													Added function prototypes.
*													Added comments.
*													Completed header file.
*													GITHUB COMMIT & PUSH TEST.
* Leonardo Fusser	11 February 2022	v1.0.2		Completed header file.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef THREADKEYBD_H
#define THREADKEYBD_H

/* Includes. */
#include "public.h"

/* Function prototypes. */
static void* threadKeybd(void* threadid);
void create_threadKeybd(void);
void join_threadKeybd(void);
void mutex_SetXandY(int temp_SetX, int temp_SetY);
int mutex_GetX(void);
int mutex_GetY(void);

#endif
