/*************************************************************************************
 * FileName:  main_lab2.cpp													         *
 *																					 *
 * Name:  Lab 2, Allegro library-move 2 balls.						                 *
 *																					 *
 * Description:  This program is part 2 of the second lab (Lab 2). It displays two   *
 *				 moving balls (fixed sized) moving at differnet directions at the    *
 *				 same time. The resolution is a custom fixed resolution. Colours     *
 *				 and special placing have been put in place also. Balls bounce from	 *
 *				 one place to other randomly. The two balls are independent of each	 *
 *				 other.																 *
 *																					 *
 * REVISION HISTORY:																 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * Leonardo Fusser (1946995)		     [Third commit]						         *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * September 16th, 2020        v1.0.6    -Completed Ball1 and Ball2 functions.		 *
 *										 -Added bounce and direction to functions.	 *
 *										 -Changed and created some macros.			 *
 *										 -Modified main_lab2.cpp					 *
 *										 -Created and completed ball_simple.cpp		 *
 *										 -Created and completed ball_simple.h		 *
 *										 -Modified some other miscellanias. 		 *
 *										                                             *
 ************************************************************************************/


#include "ball_simple.h"																	//include header file

int x1 = 160, y1 = 120, x2 = 220, y2 = 300;													//initial Ball1 and Ball2 positions
int DIR_1, DIR_2;																			//direction for Ball1 and Ball2

BITMAP* d_buffer;																			//pointer

//main program
int main(void) {

	allegro_init();																			//initialize allegro library
	install_keyboard();																		//add keyboard features
	set_color_depth(24);																	//24-bit colour
	d_buffer = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);									//now it points
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);				//sets set_gfx_mode to GFX_AUTODETECT_WINDOWED
	set_keyboard_rate(500, 600);
	
	srand(time(NULL));																		//creates a unique seed

	while (!key[KEY_ESC]) {																	//keep running program until ESC key is pressed

		rest(REST);																		    //delay
		
		moveBall1();																		//function call for Ball1
		moveBall2();																		//function call for Ball2
		
		blit(d_buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);					//blit to screen
	}
	allegro_exit();																			//close allegro library
	return 0;																				//ensure no error upon exit
}
END_OF_MAIN()
