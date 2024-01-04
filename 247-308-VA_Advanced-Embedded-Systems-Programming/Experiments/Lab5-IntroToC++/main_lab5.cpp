/*************************************************************************************
 * FileName:  main_lab5.cpp		             								         *
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
 *										 -main_lab5.cpp complete					 *
 *										                                             *
 ************************************************************************************/


#include "initSystem.h"
#include "game_cpp.h"

//main function
int main(void) {

	char strbuff[50];																		//array for getter
	init_system();																		    //initialize system function call
	int RAND_BALLS = rand() % MAX_NB + 1;                                                   //creates random number of balls (based on MAX_NB) when program is first run			
	Game my_game(RAND_BALLS);																//instantiating using constructor

	while (!key[KEY_ESC]) {																	//keep running program until ESC key is pressed
		
		rest(REST);																		    //rest
		my_game.ball_move();																//ball move call
		my_game.game_cdet();																//ball collision detection call
		my_game.game_blit();																//blit call
		sprintf_s(strbuff, "Number of balls: %d", my_game.getNbBalls());					//getter for number of balls printed to user
		textout(screen, font, strbuff, SCREEN_WIDTH - 380, SCREEN_HEIGHT - 40, RED);		//text printed in RED on bottom of screen
		my_game.game_add();																	//add or remove ball call		

	}
	allegro_exit();																			//close allegro library								
	my_game.freeing();																		//frees heap when program is closed
	return 0;																				//ensure no error upon exit
}
END_OF_MAIN()