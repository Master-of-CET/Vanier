/*************************************************************************************
 * FileName:  game_c_oop.h												             *
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
 * October 7th, 2020                     v1.0.3    -game_c_oop.h complete			 *
 *										                                             *
 ************************************************************************************/


#ifndef game_c_oop_h
#define game_c_oop_h

#include "config.h"
																							    
#define BLACK 0x000000					//black colour set as macro (colour in hex)
#define MAX_NB 10						//max number of balls program can have running at once
#define MIN_BALL_RADIUS 20				//minimum ball size
#define MAX_BALL_RADIUS 35				//maximum ball size

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
	ball_t aBall[MAX_NB];				//create "aBall" array to store all balls & ball characteristics based on type "ball_t"
	BITMAP *d_buffer;					//pointer for d_buffer
	int NB_BALLS;						//variable creation for random number of balls program has
}game_t;

void init_game(void);					//function prototype
void ball_move(void);					//function prototype	
void game_cdet(void);				    //function prototype
void game_blit(void);					//function prototype

#endif