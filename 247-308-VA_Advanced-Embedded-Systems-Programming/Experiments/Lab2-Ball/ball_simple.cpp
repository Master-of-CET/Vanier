/*************************************************************************************
 * FileName:  ball_simple.cpp														     *
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


#include "ball_simple.h"																		//include header file

extern int DIR_1, DIR_2;																		//direction for Ball1 and Ball2
extern int x1, y1, x2, y2;																		//coordinates for Ball1 and Ball2
extern BITMAP* d_buffer;


//NE = Ball direction North-East (NE): x++/y--
//SE = Ball direction South-East (SE): x++/y++
//NW = Ball direction North-West (NW): x--/y--
//SW = Ball direction South-West (SW): x--/y++


//function for Ball1
void moveBall1 (void) {

	circlefill(d_buffer, x1, y1, R1, 0x000000);												    //avoids "streaking" for Ball1

	//NE direction
	if (DIR_1 == NE && x1 < SCREEN_WIDTH - R1 && y1 > 0+R1) {
		x1++;
		y1--;
	}
	//SE direction
	else if (DIR_1 == SE && x1 < SCREEN_WIDTH - R1 && y1 < SCREEN_HEIGHT - R1) {
		x1++;
		y1++;
	}
	//NW direction
	else if (DIR_1 == NW && x1 > 0+R1 && y1 > 0+R1) {
		x1--;
		y1--;
	}
	//SW direction
	else if (DIR_1 == SW && x1 > 0+R1 && y1 < SCREEN_HEIGHT - R1) {
		x1--;
		y1++;
	}
	else {
		DIR_1 = rand() % 4 + 1;																	//chooses which direction Ball1 does next
	}
	circlefill(d_buffer, x1, y1, R1, BALL1_COLOUR);												//sets Ball1 colour
}


//function for Ball2
void moveBall2 (void) {
	
	circlefill(d_buffer, x2, y2, R2, 0x000000);													//avoids "streaking" for Ball2

	//NE direction
	if (DIR_2 == NE && x2 < SCREEN_WIDTH - R2 && y2 > 0 + R2) {
		x2++;
		y2--;
	}
	//SE direction
	else if (DIR_2 == SE && x2 < SCREEN_WIDTH - R2 && y2 < SCREEN_HEIGHT - R2) {
		x2++;
		y2++;
	}
	//NW direction
	else if (DIR_2 == NW && x2 > 0 + R2 && y2 > 0 + R2) {
		x2--;
		y2--;
	}
	//SW direction
	else if (DIR_2 == SW && x2 > 0 + R2 && y2 < SCREEN_HEIGHT - R2) {
		x2--;
		y2++;
	}
	else {
		DIR_2 = rand() % 4 + 1;																	//chooses which direction Ball2 does next
	}
	circlefill(d_buffer, x2, y2, R2, BALL2_COLOUR);													//sets Ball2 colour
}