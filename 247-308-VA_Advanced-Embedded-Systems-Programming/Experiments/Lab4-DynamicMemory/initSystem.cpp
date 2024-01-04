/*************************************************************************************
 * FileName:  initSystem.cpp												         *
 *																					 *
 * Name:  Lab 4, Allegro library - move multiple balls using OOP & dynamic memory.   *
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