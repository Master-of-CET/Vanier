/*************************************************************************************
 * FileName:  config.h			             								         *
 *																					 *
 * Name:  Lab 3, Allegro library - move multiple balls using OOP.			         *
 *																					 *
 * Description: This program is designed to move random number of balls with random  *
 *			    sizes, random colours and random directions using OOP structure.	 *
 *				Characteristics of each ball is stored as a struct and all balls and *
 *				ball characteristics are stored in an array called aBall[]. Program  *
 *				is split into multiple files, structs created and functions were     *
 *				created as per OOP standards.										 *
 *																					 *
 * REVISION HISTORY:																 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * Leonardo Fusser (1946995)		     [Third commit]						         *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * October 7th, 2020                     v1.0.3    -config.h file complete			 *
 *										                                             *
 ************************************************************************************/


#ifndef config_h
#define config_h

#include <allegro.h>											//for allegro library
#include <math.h>												//for pow() and sqrt() functions	

#define REST 0.7											    //delay
#define SCREEN_WIDTH 640										//Max screen width
#define SCREEN_HEIGHT 480										//Max screen height
#define NE 1													//Direction 1: North-East
#define SE 2													//Direction 2: South-East
#define NW 3													//Direction 3: North-West
#define SW 4													//Direction 4: South-West

#endif