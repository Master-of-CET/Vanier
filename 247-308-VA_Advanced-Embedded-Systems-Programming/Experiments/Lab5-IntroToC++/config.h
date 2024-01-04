/*************************************************************************************
 * FileName:  config.h			             								         *
 *																					 *
 * Name:  Lab 5, intro to C++ with Allegro.										     *
 *																					 *
 * Description: This program is the same as the previous lab (Lab4) with the		 *
 *				 exception that some parts were converted to C++.					 *
 *																					 *
 * REVISION HISTORY:																 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * Leonardo Fusser (1946995)		     [Second commit]					         *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * November 10th, 2020                   v1.0.2										 *
 *										 -config.h complete							 *
 *										                                             *
 ************************************************************************************/


#ifndef config_h
#define config_h

#include <allegro.h>											//for allegro library
#include <math.h>												//for pow() and sqrt() functions	
#include <stdlib.h>												//for malloc(), realloc() and free() functions

#define REST 0.5											    //delay
#define SCREEN_WIDTH	640										//max screen width
#define SCREEN_HEIGHT	480										//max screen height
enum direction { NE, SE, NW, SW };								//enum for directions

#endif