/*************************************************************************************
 * FileName:  game_c_oop.cpp												         *
 *																					 *
 * Name:  Lab 3, Allegro library - move multiple balls using OOP.				     *
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
 * October 7th, 2020                     v1.0.3    -game_c_oop.cpp file complete     *
 *										                                             *
 ************************************************************************************/


#include "game_c_oop.h"

game_t game;																								//delcare new variable "game" of type "game_t"

//initialize game function
void init_game (void) {

	game.d_buffer = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);												//create bitmap

	game.NB_BALLS = rand() % MAX_NB + 1;																	//create random number of balls each time program is run - based on MAX_NB

	//sets exact ball parameters - based on number of balls
	for (int i = 0; i < game.NB_BALLS; ++i) {
		game.aBall[i].x = rand() % SCREEN_WIDTH;															//place ball x cordinate randomly on the screen
		game.aBall[i].y = rand() % SCREEN_HEIGHT;															//place ball y cordinate randomly on the screen
		game.aBall[i].dir = rand() % 4 + 1;																	//4 possible random directions for the ball(s) 
		game.aBall[i].colour = ((rand() % 256) << 16) | ((rand() % 256) << 8) | ((rand() % 256));			//random colour for the ball(s)
		game.aBall[i].radius = rand() % (MAX_BALL_RADIUS - MIN_BALL_RADIUS) + MIN_BALL_RADIUS;				//random size for the ball(s)
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
			game.aBall[i].dir = rand() % 4 + 1;																													//4 possible random directions for the ball(s) 
		}

		circlefill(game.d_buffer, game.aBall[i].x, game.aBall[i].y, game.aBall[i].radius, game.aBall[i].colour);												//fill ball with random colour generated beforehand

	}
}


//ball collision function
void game_cdet (void) {

	double radius_length;																							//variable creation for length between two balls (based on radius)
	double ball_length;																								//variable creation for length between two balls (based on pythagoras)
	double diff_x;																									//variable creation for pythagoras calculation (x)
	double diff_y;																									//variable creation for pythagoras calculation (y)

	//changes ball colour if the two balls touch
	for (int i = 0; i < game.NB_BALLS; ++i) {																		//i: ball 1
		for (int j = i + 1; j < game.NB_BALLS; ++j) {																//j: ball 2

			radius_length = game.aBall[i].radius + game.aBall[j].radius;											//calculate length of the two balls based on radius
			diff_x = game.aBall[i].x - game.aBall[j].x;																//x difference between the two balls
			diff_y = game.aBall[i].y - game.aBall[j].y;																//y difference between the two balls
			ball_length = sqrt(pow(diff_x, 2) + pow(diff_y, 2));													//calculate length of the two balls based on pythagoras

			//if balls collide
			if (ball_length <= radius_length) {	
				game.aBall[i].colour = ((rand() % 256) << 16) | ((rand() % 256) << 8) | ((rand() % 256));			//random colour for the first ball
				game.aBall[j].colour = ((rand() % 256) << 16) | ((rand() % 256) << 8) | ((rand() % 256));			//random colour for the second ball
			}
			else {
				
			}
		}
	}
}


//blit function
void game_blit (void) {
	blit(game.d_buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);					
}