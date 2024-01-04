/*************************************************************************************
 * FileName:  game_dyn.cpp												             *
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
 *										 -game_dyn.cpp complete						 *
 *										                                             *
 ************************************************************************************/


#include "game_dyn.h"

game_t game;																								//delcare new variable "game" of type "game_t"


//initialize game function
void init_game (void) {

	game.d_buffer = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);												//create bitmap
	game.NB_BALLS = rand() % INIT_NB + 1;                                                                   //creates random number of balls (based on INIT_NB) when program is first run
	game.aBall = (ball_t *) malloc(game.NB_BALLS*sizeof(ball_t));											//creates memory space based on the number of balls generated initially before

	//if memory allocation not successful...
	if (game.aBall == NULL) {
		exit;					//exit program
	}

	//else continue running code...
	else {

		//sets exact ball parameters - based on number of balls
		for (int i = 0; i < game.NB_BALLS; ++i) {
			game.aBall[i].x = rand() % SCREEN_WIDTH;															//place ball x cordinate randomly on the screen
			game.aBall[i].y = rand() % SCREEN_HEIGHT;															//place ball y cordinate randomly on the screen
			game.aBall[i].dir = rand() % 4;																	    //4 possible random directions for the ball(s) 
			game.aBall[i].colour = ((rand() % 256) << 16) | ((rand() % 256) << 8) | ((rand() % 256));			//random colour for the ball(s)
			game.aBall[i].radius = rand() % (MAX_BALL_RADIUS - MIN_BALL_RADIUS) + MIN_BALL_RADIUS;			    //random size for the ball(s)
		}
	}
}


//ball move function
void ball_move (void) {

	//chooses direction for a ball - based on the number of balls
	for (int i = 0; i < game.NB_BALLS; ++i) {

		circlefill(game.d_buffer, game.aBall[i].x, game.aBall[i].y, game.aBall[i].radius, BLACK);																//avoids streeking

	    //move ball NE direction
		if (game.aBall[i].dir == NE && game.aBall[i].x < SCREEN_WIDTH - game.aBall[i].radius && game.aBall[i].y > 0 + game.aBall[i].radius) {
			game.aBall[i].x++;
			game.aBall[i].y--;
		}
		//move ball SE direction
		else if (game.aBall[i].dir == SE && game.aBall[i].x < SCREEN_WIDTH - game.aBall[i].radius && game.aBall[i].y < SCREEN_HEIGHT - game.aBall[i].radius) {
			game.aBall[i].x++;
			game.aBall[i].y++;
		}
		//move ball NW direction
		else if (game.aBall[i].dir == NW && game.aBall[i].x > 0 + game.aBall[i].radius && game.aBall[i].y > 0 + game.aBall[i].radius) {
			game.aBall[i].x--;
			game.aBall[i].y--;
		}
		//move ball SW direction
		else if (game.aBall[i].dir == SW && game.aBall[i].x > 0 + game.aBall[i].radius && game.aBall[i].y < SCREEN_HEIGHT - game.aBall[i].radius) {
			game.aBall[i].x--;
			game.aBall[i].y++;
		}
		//chose ball direction after initialization
		else {
			game.aBall[i].dir = rand() % 4;																													//4 possible random directions for the ball(s) 
		}

		circlefill(game.d_buffer, game.aBall[i].x, game.aBall[i].y, game.aBall[i].radius, game.aBall[i].colour);											//fill ball with random colour generated beforehand

	}
}


//ball collision function
void game_cdet(void) {

	int radius_length;																							    //variable creation for length between two balls (based on radius)
	double ball_length;																								//variable creation for length between two balls (based on pythagoras)
	double diff_x;																									//variable creation for pythagoras calculation (x)
	double diff_y;																									//variable creation for pythagoras calculation (y)

	//loops
	for (int i = 0; i < game.NB_BALLS; ++i) {																		//i: loop ball 1
		for (int j = i + 1; j < game.NB_BALLS; ++j) {																//j: loop ball 2

			radius_length = game.aBall[i].radius + game.aBall[j].radius;											//calculate length of the two balls based on radius
			diff_x = (double)game.aBall[i].x - (double)game.aBall[j].x;												//x difference between the two balls
			diff_y = (double)game.aBall[i].y - (double)game.aBall[j].y;												//y difference between the two balls
			ball_length = sqrt((pow(diff_x, 2) + pow(diff_y, 2)));									                //calculate length of the two balls based on pythagoras

			//if balls collide...
			if (ball_length < radius_length) {

				//change each ball's colour
				game.aBall[i].colour = ((rand() % 256) << 16) | ((rand() % 256) << 8) | ((rand() % 256));			//random colour for the first ball
				game.aBall[j].colour = ((rand() % 256) << 16) | ((rand() % 256) << 8) | ((rand() % 256));			//random colour for the second ball

				//rotate 180 degrees (for first ball)
				switch (game.aBall[i].dir) {

				
				case NE:						//if direction is NE...
					game.aBall[i].dir = SW;		//change to SW direction
					break;

				case SE:						//if direction is SE...
					game.aBall[i].dir = NW;		//change to NW direction
					break;

				case SW:						//if direction is SW...
					game.aBall[i].dir = NE;		//change to NE direction
					break;

				case NW:						//if direction is NW...
					game.aBall[i].dir = SE;		//change to SE direction
					break;

				default:
					break;
				}

				//rotate 180 degrees (for second ball)
				switch (game.aBall[j].dir) {


				case NE:						//if direction is NE...
					game.aBall[j].dir = SW;		//change to SW direction
					break;

				case SE:						//if direction is SE...
					game.aBall[j].dir = NW;		//change to NW direction
					break;

				case SW:						//if direction is SW...
					game.aBall[j].dir = NE;		//change to NE direction
					break;

				case NW:						//if direction is NW...
					game.aBall[j].dir = SE;		//change to SE direction
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


//setter for number of balls printed to user
int getNbBalls (void) {

	return game.NB_BALLS;						//number of balls currently running returned to getter

}


//add or remove ball function
void game_add (void) {

	//if up-arrow is pressed...
	if (key[KEY_UP]) {

		game.NB_BALLS += 1;																							//increase number of balls by 1 each time key is pressed
		game.aBall = (ball_t *) realloc(game.aBall, game.NB_BALLS * sizeof(ball_t));								//re-allocate memory space for newly added balls
		game.aBall[game.NB_BALLS-1].x = rand() % SCREEN_WIDTH;														//sets initial x cordinate for newly added ball
		game.aBall[game.NB_BALLS-1].y = rand() % SCREEN_HEIGHT;														//sets initial y cordinate for newly added ball
		game.aBall[game.NB_BALLS-1].dir = rand() % 4;																//sets initial direction for newly added ball
		game.aBall[game.NB_BALLS-1].colour = ((rand() % 256) << 16) | ((rand() % 256) << 8) | ((rand() % 256));		//sets initial colour for newly added ball
		game.aBall[game.NB_BALLS-1].radius = rand() % (MAX_BALL_RADIUS - MIN_BALL_RADIUS) + MIN_BALL_RADIUS;		//sets initial size for newly added ball

		rest(100);
	}

	//if down-arrow is pressed...
	if (key[KEY_DOWN]) {

		game.NB_BALLS -= 1;																													//decrease number of balls by 1 each time key is pressed
		circlefill(game.d_buffer, game.aBall[game.NB_BALLS].x, game.aBall[game.NB_BALLS].y, game.aBall[game.NB_BALLS].radius, BLACK);		//fill old ball with black
		game.aBall = (ball_t *) realloc(game.aBall, game.NB_BALLS * sizeof(ball_t));														//re-allocate memory space for newly removed balls

		rest(100);
	}
}


//free memory function
void freeing (void) {
	free(game.aBall);														//frees memory space in the heap
}


//blit function
void game_blit(void) {
	blit(game.d_buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}