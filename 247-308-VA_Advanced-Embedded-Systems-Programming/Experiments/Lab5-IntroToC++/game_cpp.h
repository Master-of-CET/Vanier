/*************************************************************************************
 * FileName:  game_cpp.h		             								         *
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
 *										 -game_cpp.h complete						 *
 *										                                             *
 ************************************************************************************/


#ifndef game_cpp_h
#define game_cpp_h

#include "config.h"
																							    
#define BLACK	0x000000				//black colour set as macro (BLACK in hex)
#define RED		0xFF0000				//red colour set as macro (RED in hex)
#define MAX_NB	10						//max number of balls initially when program is first run
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

//struct game_t replaced with class Game
class Game {							

	//members
	private:
		ball_t *aBall;					//pointer for ball_t (array replaced)
		BITMAP *d_buffer;				//pointer for d_buffer
		int NB_BALLS;					//stores number of balls during run-time	

	//methods
	public:
		Game (int);						//constructor					        
		void ball_move	(void);						
		void game_cdet	(void);	
		void game_blit	(void);
		int  getNbBalls (void);	
		void freeing	(void);
		void game_add	(void);		

};

#endif