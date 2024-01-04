/*************************************************************************************
 * FileName:  initSystem.cpp												         *
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
 * Leonardo Fusser (1946995)		     [Third commit]							     *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * October 7th, 2020                     v1.0.3    -initSystem.cpp complete			 *
 *										                                             *
 ************************************************************************************/


#include "initSystem.h"
#include "config.h"

//initialize system function 
void init_system(void) {
	allegro_init();																			//initialize allegro library
	install_keyboard();																		//add keyboard features
	set_color_depth(24);																	//24-bit colour
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);				//sets set_gfx_mode to GFX_AUTODETECT_WINDOWED
	set_keyboard_rate(500, 600);
	srand(time(NULL));																		//creates a unique seed each time program is run
}