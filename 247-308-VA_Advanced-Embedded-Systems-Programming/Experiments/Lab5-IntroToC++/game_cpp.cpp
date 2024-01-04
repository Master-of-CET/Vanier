/*************************************************************************************
 * FileName:  game_cpp.cpp		             								         *
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
 *										 -game_cpp.cpp complete						 *
 *										                                             *
 ************************************************************************************/


#include "game_cpp.h"

//initialize game constructor definition
Game::Game(int nb_balls){

	NB_BALLS = nb_balls;																					//assign random number of balls created at run-time to NB_BALLS
	d_buffer = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);													//create bitmap
	aBall = (ball_t *) malloc(NB_BALLS*sizeof(ball_t));														//creates memory space based on the number of balls generated initially before

	//if memory allocation not successful...
	if (aBall == NULL) {
		exit;									//exit program
	}

	//else continue running code...
	else {

		//sets exact ball parameters - based on number of balls
		for (int i = 0; i < NB_BALLS; ++i) {
			aBall[i].x = rand() % SCREEN_WIDTH;																//place ball x cordinate randomly on the screen
			aBall[i].y = rand() % SCREEN_HEIGHT;															//place ball y cordinate randomly on the screen
			aBall[i].dir = rand() % 4;																	    //4 possible random directions for the ball(s) 
			aBall[i].colour = ((rand() % 256) << 16) | ((rand() % 256) << 8) | ((rand() % 256));			//random colour for the ball(s)
			aBall[i].radius = rand() % (MAX_BALL_RADIUS - MIN_BALL_RADIUS) + MIN_BALL_RADIUS;			    //random size for the ball(s)
		}
	}
}


//ball move method implementation
void Game::ball_move (void) {

	//chooses direction for a ball - based on the number of balls
	for (int i = 0; i < NB_BALLS; ++i) {

		circlefill(d_buffer, aBall[i].x, aBall[i].y, aBall[i].radius, BLACK);																//avoids streeking

	    //move ball NE direction
		if (aBall[i].dir == NE && aBall[i].x < SCREEN_WIDTH - aBall[i].radius && aBall[i].y > 0 + aBall[i].radius) {
			aBall[i].x++;
			aBall[i].y--;
		}
		//move ball SE direction
		else if (aBall[i].dir == SE && aBall[i].x < SCREEN_WIDTH - aBall[i].radius && aBall[i].y < SCREEN_HEIGHT - aBall[i].radius) {
			aBall[i].x++;
			aBall[i].y++;
		}
		//move ball NW direction
		else if (aBall[i].dir == NW && aBall[i].x > 0 + aBall[i].radius && aBall[i].y > 0 + aBall[i].radius) {
			aBall[i].x--;
			aBall[i].y--;
		}
		//move ball SW direction
		else if (aBall[i].dir == SW && aBall[i].x > 0 + aBall[i].radius && aBall[i].y < SCREEN_HEIGHT - aBall[i].radius) {
			aBall[i].x--;
			aBall[i].y++;
		}
		//chose ball direction after initialization
		else {
			aBall[i].dir = rand() % 4;																										//4 possible random directions for the ball(s) 
		}

		circlefill(d_buffer, aBall[i].x, aBall[i].y, aBall[i].radius, aBall[i].colour);														//fill ball with random colour generated beforehand

	}
}


//ball collision method implementation
void Game::game_cdet(void) {

	int radius_length;																							    //variable creation for length between two balls (based on radius)
	double ball_length;																								//variable creation for length between two balls (based on pythagoras)
	double diff_x;																									//variable creation for pythagoras calculation (x)
	double diff_y;																									//variable creation for pythagoras calculation (y)

	//loops
	for (int i = 0; i < NB_BALLS; ++i) {																			//i: loop ball 1
		for (int j = i + 1; j < NB_BALLS; ++j) {																	//j: loop ball 2

			radius_length = aBall[i].radius + aBall[j].radius;														//calculate length of the two balls based on radius
			diff_x = (double)aBall[i].x - (double)aBall[j].x;														//x difference between the two balls
			diff_y = (double)aBall[i].y - (double)aBall[j].y;														//y difference between the two balls
			ball_length = sqrt((pow(diff_x, 2) + pow(diff_y, 2)));									                //calculate length of the two balls based on pythagoras

			//if balls collide...
			if (ball_length < radius_length) {

				//change each ball's colour
				aBall[i].colour = ((rand() % 256) << 16) | ((rand() % 256) << 8) | ((rand() % 256));				//random colour for the first ball
				aBall[j].colour = ((rand() % 256) << 16) | ((rand() % 256) << 8) | ((rand() % 256));				//random colour for the second ball

				//rotate 180 degrees (for first ball)
				switch (aBall[i].dir) {

				
				case NE:					//if direction is NE...
					aBall[i].dir = SW;		//change to SW direction
					break;

				case SE:					//if direction is SE...
					aBall[i].dir = NW;		//change to NW direction
					break;

				case SW:					//if direction is SW...
					aBall[i].dir = NE;		//change to NE direction
					break;

				case NW:					//if direction is NW...
					aBall[i].dir = SE;		//change to SE direction
					break;

				default:
					break;
				}

				//rotate 180 degrees (for second ball)
				switch (aBall[j].dir) {


				case NE:					//if direction is NE...
					aBall[j].dir = SW;		//change to SW direction
					break;

				case SE:					//if direction is SE...
					aBall[j].dir = NW;		//change to NW direction
					break;

				case SW:					//if direction is SW...
					aBall[j].dir = NE;		//change to NE direction
					break;

				case NW:					//if direction is NW...
					aBall[j].dir = SE;		//change to SE direction
					break;

				default:
					break;
				}

			}

			//do nothing
			else {
			}

		}
	}
}


//blit - method implementation
void Game::game_blit(void) {
	blit(d_buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}


//free memory - method implementation
void Game::freeing(void) {
	free(aBall);								//frees memory space in the heap
}


//(setter for number of balls printed to user)
//setter-getter - method implementation
int Game::getNbBalls (void) {

	return NB_BALLS;							//number of balls currently running returned to getter

}


//add or remove ball - method implementation
void Game::game_add (void) {

	//if up-arrow is pressed...
	if (key[KEY_UP]) {

		NB_BALLS += 1;																					//increase number of balls by 1 each time key is pressed
		aBall = (ball_t *) realloc(aBall, NB_BALLS * sizeof(ball_t));									//re-allocate memory space for newly added balls
		aBall[NB_BALLS-1].x = rand() % SCREEN_WIDTH;													//sets initial x cordinate for newly added ball
		aBall[NB_BALLS-1].y = rand() % SCREEN_HEIGHT;													//sets initial y cordinate for newly added ball
		aBall[NB_BALLS-1].dir = rand() % 4;																//sets initial direction for newly added ball
		aBall[NB_BALLS-1].colour = ((rand() % 256) << 16) | ((rand() % 256) << 8) | ((rand() % 256));	//sets initial colour for newly added ball
		aBall[NB_BALLS-1].radius = rand() % (MAX_BALL_RADIUS - MIN_BALL_RADIUS) + MIN_BALL_RADIUS;		//sets initial size for newly added ball

		rest(100);
	}

	//if down-arrow is pressed...
	if (key[KEY_DOWN]) {

		NB_BALLS -= 1;																					//decrease number of balls by 1 each time key is pressed
		circlefill(d_buffer, aBall[NB_BALLS].x, aBall[NB_BALLS].y, aBall[NB_BALLS].radius, BLACK);		//fill old ball with black
		aBall = (ball_t *) realloc(aBall, NB_BALLS * sizeof(ball_t));									//re-allocate memory space for newly removed balls

		rest(100);
	}
}