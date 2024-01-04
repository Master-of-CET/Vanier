/*************************************************************************************
 * FileName:  initSystem.cpp	             								         *
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
 *										 -initSystem.cpp complete					 *
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