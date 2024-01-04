/**************************************************************************************************
* FileName: threadDisplay.c
*
* Name: Leonardo Fusser (1946995)	Lab 3   Moving Snake Application
*
* Description: This code displays a game menu and a moving snake to the console. The snake head moves
*			   around the screen according to the feedback from the keyboard thread. The game title
*			   blinks around every 2.5Hz and a elapsed time is displayed along the game menu as well.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser	28 January 2022		v1.0.0		First version of source file.
*													Created display thread routine.
*													Created mutex for display thread routine.
* Leonardo Fusser	6 February 2022		v1.0.1		Added menu and printing area for snake.
*													Added elapsed time printing for menu.
*													Added limits for cursor X & Y values.
*													Added macros for portability.
*													Added comments.
*													GITHUB COMMIT & PUSH TEST.
* Leonardo Fusser	11 February 2022	v1.0.2		Completed source file.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "../laboratory/header/threadDisplay.h"


static pthread_t ID_threadDisplay;									//Display thread ID.
static pthread_mutex_t mutex_display = PTHREAD_MUTEX_INITIALIZER;	//Mutex init.


/**********************************************************************************************
* Name: void *threadDisplay(void *threadid)
* Description: Display thread routine for Lab 3. A game menu is printed once onto a console. A
*			   snake head moves around the screen continously as well as a game title blinking
*			   and a elapsed game time indication being shown on the menu.
*
***********************************************************************************************/
void* threadDisplay(void* threadid) {

	time_t TimeStamp1_begin = time(NULL);	//Initial timestamp for displaying elapsed time in menu.
	
	int temp_StartGetX = 0;	//Temp value to get X value.
	int temp_StartGetY = 0;	//Temp value to get Y value.
	int temp_EndGetX = 0;	//Temp value to get X value again (to determine if system is idle).
	int temp_EndGetY = 0;	//Temp value to get Y value again (to determine if system is idle).
	int SkipCount = 0;		//Skip counter value to toggle game title in menu.

	/* Snake game menu. *////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	attron(BLUE_WHITE);	 //Prints message with blue colour (with white background).
	mvprintw(0, 0, "                                                                                                                     ");
	mvprintw(1, 0, "*********************************************************************************************************************");	//Prints at line 1, column 0.
	mvprintw(2, 0, "*                                             Use the following keys:                                               *");	//Prints at line 2, column 0.
	mvprintw(3, 0, "*                                                                                                                   *");	//Prints at line 3, column 0.
	mvprintw(4, 0, "*                                                        w                                                          *");	//Prints at line 4, column 0.
	mvprintw(5, 0, "*                                             a                     d                                               *");	//Prints at line 5, column 0.
	mvprintw(6, 0, "*                                                        s                                                          *");	//Prints at line 6, column 0.
	mvprintw(7, 0, "*                                                                                                                   *");	//Prints at line 7, column 0.
	mvprintw(8, 0, "*                                                   Exit: x-key                                                     *");	//Prints at line 8, column 0.
	mvprintw(9, 0, "*                                                                                                                   *");	//Prints at line 9, column 0.
	mvprintw(10, 0,"*                                                                                                                   *");	//Prints at line 10, column 0.
	mvprintw(11, 0,"*                                                                                                                   *");	//Prints at line 11, column 0.
	mvprintw(12, 0,"*********************************************************************************************************************");	//Prints at line 12, column 0.
	for (int i = 13; i < 31; i++) {
		mvprintw(i, 0, "                                                                                                                     ");//Prints from line 13 to 31, column 0.
	}
	attroff(BLUE_WHITE); //Wipes print from console.
	refresh();           //Refreshes console (for subsequent prints).
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/* Mini while loop. */
	while (1) {

		time_t TimeStamp1_end = time(NULL);	//Current timestamp for displaying elapsed time in menu.


		/* Print to display elapsed time in seconds since thread routine initially ran. */////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		attron(BLUE_WHITE);
		mvprintw(11, 0, "*                                                                                Elapsed time: %d seconds.          *", (TimeStamp1_end-TimeStamp1_begin));	//Prints at line 11, column 0.
		attroff(BLUE_WHITE);
		refresh();
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		/* Print to display and toggle "snake game" in menu every 2.5Hz. *///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (SkipCount == 20) {																															//Toggles game title every 2.5Hz.
			attron(BLUE_WHITE);
			mvprintw(10, 0, "*                                                   Snake Game!                                                     *");	//Prints at line 10, column 0.
			attroff(BLUE_WHITE);
			refresh();
		}
		else if (SkipCount == 40) {																														//Toggles game title every 2.5Hz.
			attron(BLUE_WHITE);
			mvprintw(10, 0, "*                                                                                                                   *");	//Prints at line 10, column 0.
			attroff(BLUE_WHITE);
			refresh();
			SkipCount = 0;																																//Rests skip counter to 0.
		}

		SkipCount++;																																	//Keeps increasing skip counter.
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		temp_StartGetX = mutex_GetX();	//Gets current X value.
		temp_StartGetY = mutex_GetY();	//Gets current Y value.
		

		/* Condition that determine if cursor is out of X window bounds. */
		if (temp_StartGetX > X2_WindowLimit || temp_StartGetX < X1_WindowLimit) {
			//Does not print cursor if snake goes out of window X-bounds.
		}
		/* Condition that determines if cursor if out of Y window bounds. */
		else if (temp_StartGetY > Y2_WindowLimit || temp_StartGetY < Y1_WindowLimit) {
			//Does not print cursor if snake goes out of window Y-bounds.
		}
		/* Otherwise, cursor is withing X & Y window bounds. */
		else {
			/* Condition that determines if system is idle. */
			if (temp_EndGetX == temp_StartGetX && temp_EndGetY == temp_StartGetY) {
				Sleep(1);	//Small blocking delay to prevent CPU stress.
			}
			/* Otherwise, system is not idle (snake is moving around). */
			else {
				attron(RED_WHITE);
				mutex_print(temp_StartGetY, temp_StartGetX, "O");	//Prints snake (using mutexes).
				attroff(RED_WHITE);
				refresh();
				temp_EndGetX = mutex_GetX();	//Gets X value again (to determine if system is idle).
				temp_EndGetY = mutex_GetY();	//Gets Y value again (to determine if system is idle).
			}
		}
	}
	return NULL;	//Returns to main thread (if possible).
}


/**********************************************************************************************
* Name: void create_threadDisplay(void)
* Description: Display thread routine creation function for Lab 3. The following code creates
*			   the actual thread for the display thread routine.
*
***********************************************************************************************/
void create_threadDisplay(void) {
	pthread_create(&ID_threadDisplay, NULL, threadDisplay, NULL);	//Creates display thread.
}


/**********************************************************************************************
* Name: void join_threadDisplay(void)
* Description: Thread routine joining function for Lab 3. The following code forces the
*			   main thread to wait for the display thread routine to finish before terminating
*			   alltogether.
*
***********************************************************************************************/
void join_threadDisplay(void) {
	pthread_join(ID_threadDisplay, NULL);	//Joins display thread.
}


/**********************************************************************************************
* Name: void mutex_print(int l, int c, char* str)
* Description: Mutex-protected function for printing to the console. The ncurses API functions
*			   are protected when they are being used below.
*
***********************************************************************************************/
void mutex_print(int l, int c, char* str) {
	pthread_mutex_lock(&mutex_display);		//Protects.
	mvprintw(l, c, str);					//Prints.
	pthread_mutex_unlock(&mutex_display);   //Un-protects.
}
