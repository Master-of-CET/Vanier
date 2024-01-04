/*************************************************************************************
 * FileName:  main_lab3.cpp													         *
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
 * October 7th, 2020                     v1.0.3    -main_lab3.cpp complete			 *
 *										                                             *
 ************************************************************************************/


#include "initSystem.h"
#include "game_c_oop.h"

//main function
int main(void) {

	init_system();																			//initialize system function call
	init_game();																			//initialize game function call

	while (!key[KEY_ESC]) {																	//keep running program until ESC key is pressed
		
		rest(REST);																			//rest
		ball_move();																		//ball move function call
		game_cdet();																	    //ball collision detection function call
		game_blit();																		//blit function call

	}
	allegro_exit();																			//close allegro library
	return 0;																				//ensure no error upon exit
}
END_OF_MAIN()