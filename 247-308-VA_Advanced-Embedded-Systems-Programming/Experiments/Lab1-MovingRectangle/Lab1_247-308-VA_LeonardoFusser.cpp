
/*************************************************************************************
 * FileName:  main_lab1-3.cpp														 *
 *																					 *
 * Name:  Lab 1 - part 3, Introduction to the Allegro library.						 *
 *																					 *
 * Description:  This program is part 3 of the first lab (Lab 1). It displays a      *
 *				 moving rectangle (fixed sized) moving horizontally and vertically   *
 *				 at the same time. The resolution is a custom fixed resolution.      *
 *				 Colours and special placing have been put in place also.			 *
 * REVISION HISTORY:																 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * Leonardo Fusser (1946995)   01/09/2020   [Third commit]						     *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * September 1st, 2020         v1.0.3    -Changed position of custom printed text.   *
 *										 -Changed the screen size.                   *
 *										 -Created a custom moving rectangle.         *
 *										 -Added some colours to text and rectangle.  *
 *										 -Modified program to ensure rectangle       *
 *										  restarts it's movement at top left corner  *
 *										  when rectangle touches near bottom right   *
 *										  corner.                                    *
 ************************************************************************************/

#include <allegro.h>																		//for allegro library
#include <stdio.h>																			//for input/output

//main program
int main(void) {
						
	int x1 = 0, y1 = 0, x2 = 80, y2 = 220;													//initial position of rectangle

	BITMAP* d_buffer;																		//pointer
	allegro_init();																			//initialize allegro library
	install_keyboard();																		//add keyboard features
	set_color_depth(24);																	//24-bit colour
	d_buffer = create_bitmap(640, 480);														//now it points
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);									//sets set_gfx_mode to GFX_AUTODETECT_WINDOWED
	set_keyboard_rate(500, 600);
	textprintf_ex(d_buffer, font, 240, 40, 0x08f26e, -1,"Press ESC to exit!");			    //some user text
	textprintf_ex(d_buffer, font, 250, 50, 0xffff00, -1, "Program modified by:");			//" "
	textprintf_ex(d_buffer, font, 260, 60, 0xff0000, -1, "Leonardo Fusser (1946995)");		//" "

	while (!key[KEY_ESC]) {																	//keep running program until ESC key is pressed
		rest(1);																			//1mS delay

		rectfill(d_buffer, x1, y1, x2, y2, 0x000000);										//avoids "streaking" of moving rectangle (black fill-in follows moving rectangle)

		//moves rectangle horizontally
		if (x2 <= 640) {
			//move incrementally
			x1++; 
			x2++;
		}
		else {
			//some cordinates
			x1 = 0;
			x2 = 80; 
			y1 = 0;
			y2 = 220;
		}

		//moves rectangle vertically
		if (y2 <= 480) {
			//move incrementally
			y1++; 
			y2++;
		}
		else {
			//some cordinates
			y1 = 0;
			y2 = 220; 
			x1 = 0;
			x2 = 80;
		}
		rectfill(d_buffer, x1, y1, x2, y2, 0x2a9df4);										//creates rectangular shape
		blit(d_buffer, screen, 0, 0, 0, 0, 640, 480);										//"blits" the buffer to the screen
	}
	allegro_exit();																			//close allegro library
	return 0;																				//ensure no error upon exit
}
END_OF_MAIN()
