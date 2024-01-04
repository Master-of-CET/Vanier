/*************************************************************************************
 * FileName:  main_lab4.cpp													         *
 *																					 *
 * Name:  Lab 4, Allegro library - move multiple balls using OOP & dynamic memory.	 *
 *																					 *
 * Description: This program is similar to the previous lab (Lab3) with the addition *
 *				of adding or removing balls on the fly (while program is run). Number*
 *				of balls is random, colour, direction and size.						 *
 *																					 *
 * REVISION HISTORY:																 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * Leonardo Fusser (1946995)		     [Third commit]							     *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * November 3rd, 2020                    v1.0.3										 *
 *										 -main_lab4.cpp complete                     *
 *										                                             *
 ************************************************************************************/


#include "initSystem.h"
#include "game_dyn.h"

//main function
int main(void) {

	char strbuff[50];																		//array for getter
	init_system();																			//initialize system function call
	init_game();																			//initialize game function call

	while (!key[KEY_ESC]) {																	//keep running program until ESC key is pressed
		
		rest(REST);																		    //rest
		ball_move();																		//ball move function call
		game_cdet();																	    //ball collision detection function call
		sprintf_s(strbuff, "Number of balls: %d", getNbBalls());							//getter for number of balls printed to user
		textout(screen, font, strbuff, SCREEN_WIDTH - 380, SCREEN_HEIGHT - 40, RED);		//text printed in RED on bottom of screen
		game_add();																			//add or remove ball function call
		game_blit();																		//blit function call

	}
	allegro_exit();																			//close allegro library
	freeing();																				//frees heap when program is closed
	return 0;																				//ensure no error upon exit
}
END_OF_MAIN()