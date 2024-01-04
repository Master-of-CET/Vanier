/*************************************************************************************
 * FileName:  ball_simple.h														     *
 *																					 *
 * Name:  Lab 2, Allegro library-move 2 balls.						                 *
 *																					 *
 * Description:  This program is part 2 of the second lab (Lab 2). It displays two   *
 *				 moving balls (fixed sized) moving at differnet directions at the    *
 *				 same time. The resolution is a custom fixed resolution. Colours     *	
 *				 and special placing have been put in place also. Balls bounce from	 *
 *				 one place to other randomly. The two balls are independent of each	 *
 *				 other.																 *
 *																					 *
 * REVISION HISTORY:																 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * Leonardo Fusser (1946995)		     [Third commit]						         *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * September 16th, 2020        v1.0.6    -Completed Ball1 and Ball2 functions.		 *
 *										 -Added bounce and direction to functions.	 *
 *										 -Changed and created some macros.			 *
 *										 -Modified main_lab2.cpp					 *
 *										 -Created and completed ball_simple.cpp		 *
 *										 -Created and completed ball_simple.h		 *
 *										 -Modified some other miscellanias. 		 *
 *										                                             *
 ************************************************************************************/


#ifndef ball_simple_h
#define ball_simple_h


#include <allegro.h>																		//for allegro library
#include <stdio.h>																			//for input/output

#define REST 0.5																			//delay
#define SCREEN_WIDTH 640																	//width = 640
#define SCREEN_HEIGHT 480																	//height = 480
#define BALL1_COLOUR 0xff0000																//red colour
#define BALL2_COLOUR 0xffffff																//white colour
#define R1 30																				//Ball1 radius
#define R2 40																				//Ball2 radius
#define NE 1																				//1: North-East
#define SE 2																				//2: South-East
#define NW 3																				//3: North-West
#define SW 4																				//4: South-West

void moveBall1(void);																		//Ball1 function
void moveBall2(void);																		//Ball2 function	

#endif