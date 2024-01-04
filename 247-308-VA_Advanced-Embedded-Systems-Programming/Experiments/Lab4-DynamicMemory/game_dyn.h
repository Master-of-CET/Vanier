/*************************************************************************************
 * FileName:  game_dyn.h												             *
 *																					 *
 * Name:  Lab 4, Allegro library - move multiple balls using OOP & dynamic memory.	 *
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
 *										 -game_dyn.h complete						 *
 *										                                             *
 ************************************************************************************/


#ifndef game_dyn_h
#define game_dyn_h

#include "config.h"
																							    
#define BLACK 0x000000					//black colour set as macro (BLACK in hex)
#define RED 0xFF0000					//red colour set as macro (RED in hex)
#define INIT_NB 10					    //max number of balls initially when program is first run
#define MIN_BALL_RADIUS 20			    //minimum ball size
#define MAX_BALL_RADIUS 35			    //maximum ball size

//ball_t struct
typedef struct {
	int x;								//variable creation for x cordinate of a ball
	int y;								//variable creation for y cordinate of a ball
	int dir;							//variable creation for ball direction
	int colour;							//variable creation for ball colour
	int radius;							//variable creation for ball radius
}ball_t;

//game_t struct
typedef struct {
	ball_t *aBall;						//pointer for ball_t (array replaced)
	BITMAP *d_buffer;					//pointer for d_buffer
	int NB_BALLS;						//variable creation for initial number of balls when program is first run
}game_t;

void init_game(void);					//function prototype
void ball_move(void);					//" "	
void game_cdet(void);				    //" "
int  getNbBalls(void);					//" "
void game_add(void);					//" "
void freeing(void);						//" "
void game_blit(void);					//" "

#endif