/*************************************************************************************
 * FileName:  config.h			             								         *
 *																					 *
 * Name:  Lab 4, Allegro library - move multiple balls using OOP & dynamic memory.   *
 *																					 *
 * Description: This program is similar to the previous lab (Lab3) with the addition *
 *				of adding or removing balls on the fly (while program is run). Number*
 *				of balls is random, colour, direction and size.						 *
 *																					 *
 * REVISION HISTORY:																 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * Leonardo Fusser (1946995)		     [Third commit]						         *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * November 3rd, 2020                    v1.0.3										 *
 *										 -config.h complete							 *
 *										                                             *
 ************************************************************************************/


#ifndef config_h
#define config_h

#include <allegro.h>											//for allegro library
#include <math.h>												//for pow() and sqrt() functions	
#include <stdlib.h>												//for malloc(), realloc() and free() functions

#define REST 0.5											    //delay
#define SCREEN_WIDTH 640										//Max screen width
#define SCREEN_HEIGHT 480										//Max screen height
enum direction { NE, SE, NW, SW };								//enum for directions

#endif