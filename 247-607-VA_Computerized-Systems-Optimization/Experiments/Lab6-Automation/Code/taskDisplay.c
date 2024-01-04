/**************************************************************************************************
* FileName: taskDisplay.c
*
* Name: Leonardo Fusser (1946995)	Lab 4   Mover4 robotic arm - simulation mode
*									Lab 8	Inverse kinematics application
*
* Description: Display task source file for Lab 4 and Lab 8. Here, a task constantly prints a menu, 
*			   SP and PV angles on the Mover4 robot arm, warning messages and error messages 
*			   (if applicable). 
*			   Macro definitions can be found in the taskDisplay.h or public.h file.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser	18 February 2022    v1.0.0		First version of source file.
*													Created task creation function.
*													Created task joining funciton.
*													Filled keyboard task routine.
*													Added comments.
*													Implemented macros.
*													Completed source file.
* Leonardo Fusser	6 March 2022		v1.0.1		Changed menu to show more functions available to
*													be performed on the Mover4 robot.
*													Changed include path for compatibility on BBB.
*													Cleaned up comments.
* Leonardo Fusser	16 March 2022		v1.0.2		Minor changes.
* Leonardo Fusser	2  April 2022		v2.0.0		Changed menu to show more functions available to
*													be performed on the Mover4 robot.
*													Added comments.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "../header/taskDisplay.h"

/* Display thread ID. */
static pthread_t ID_taskDisplay;


/**********************************************************************************************
* Name: void *taskDisplay(void *threadid)
* Description: Display thread routine for Lab 4 and Lab 8. A menu is printed once onto a console 
*			   to show all the possible functions that could be performed on the Mover4 robot. 
*			   A dedicated section prints the SP and PV angles. Warning and error messages also 
*			   print if needed.
*
***********************************************************************************************/
void* taskDisplay(void* threadid) {

	int i = 0;				//Printing loop variable (must be declared here in order to prevent compilation errors on BBB).

	/* Mover4 robot arm menu. *////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	attron(BLUE_WHITE);		//Prints message with blue colour (with white background).
	mvprintw(0, 0, "                                                                                                                        ");
	mvprintw(1, 0, "************************************************************************************************************************");		//Prints at line 1, column 0.
	mvprintw(2, 0, "* Use the following keys to jog the points or grip:                                                                    *");		//Prints at line 2, column 0.
	mvprintw(3, 0, "*                                                                                                                      *");		//Prints at line 3, column 0.
	mvprintw(4, 0, "*   q               w               e               r               t                                                  *");		//Prints at line 4, column 0.
	mvprintw(5, 0, "*  Base          Shoulder         Elbow           Wrist          Gripper                                               *");		//Prints at line 5, column 0.
	mvprintw(6, 0, "*   a               s               d               f               g                                                  *");		//Prints at line 6, column 0.
	mvprintw(7, 0, "*                                                                                                                      *");		//Prints at line 7, column 0.
	mvprintw(8, 0, "*  Exit: x-key   Jog: j-key       Auto: n-key     Kinematics: k-key                                                    *");		//Prints at line 8, column 0.
	mvprintw(9, 0, "************************************************************************************************************************");		//Prints at line 9, column 0.
	mvprintw(10, 0, "                                                                                                                        ");	//Prints at line 10, column 0.
	mvprintw(11, 0, "                                                                                                                        ");	//Prints at line 11, column 0.
	attroff(BLUE_WHITE);	//Wipes print from console.
	refresh();				//Refreshes console (for subsequent prints).

	attron(GREEN_WHITE);	//Prints message with green colour (with white background).
	mvprintw(12, 0, "************************************************************************************************************************");	//Prints at line 12, column 0.
	mvprintw(13, 0, "                                                                                                                        ");	//Prints at line 13, column 0.
	mvprintw(14, 0, "                                                                                                                        ");	//Prints at line 14, column 0.
	mvprintw(15, 0, "************************************************************************************************************************");	//Prints at line 15, column 0.
	mvprintw(16, 0, "                                                                                                                        ");	//Prints at line 16, column 0.
	mvprintw(17, 0, "                                                                                                                        ");	//Prints at line 17, column 0.
	attroff(GREEN_WHITE);	//Wipes print from console.
	refresh();				//Refreshes console (for subsequent prints).

	attron(RED_WHITE);		//Prints message with red colour (with white background).
	mvprintw(18, 0, "************************************************************************************************************************");	//Prints at line 18, column 0.
	mvprintw(19, 0, "                                                                                                                        ");	//Prints at line 19, column 0.
	mvprintw(20, 0, "************************************************************************************************************************");	//Prints at line 20, column 0.
	mvprintw(21, 0, "                                                                                                                        ");	//Prints at line 21, column 0.
	mvprintw(22, 0, "                                                                                                                        ");	//Prints at line 22, column 0.
	mvprintw(23, 0, "************************************************************************************************************************");	//Prints at line 23, column 0.
	mvprintw(24, 0, "                                                                                                                        ");	//Prints at line 24, column 0.
	mvprintw(25, 0, "************************************************************************************************************************");	//Prints at line 25, column 0.
	attroff(RED_WHITE);		//Wipes print from console.
	refresh();				//Refreshes console (for subsequent prints).
		
	attron(BLUE_WHITE);		//Prints message with blue colour (with white background).
	for (i = 26; i < 30; i++) {
		mvprintw(i, 0, "                                                                                                                        ");	//Prints from line 26 to 31, column 0.
	}
	attroff(BLUE_WHITE);	//Wipes print from console.
	refresh();				//Refreshes console (for subsequent prints).
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	/* Mini while loop. */
	while (1) {
		/* Prints set-point (SP) and current-position (PV) values. *//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		attron(GREEN_WHITE);	//Prints message with green colour (with white background).
		mvprintw(13, 0, " Angles: SP      Base: %3.2f    Shoulder: %3.2f    Elbow: %3.2f    Wrist: %3.2f                                         ", get_sp_angle(BASE), get_sp_angle(SHOULDER), get_sp_angle(ELBOW), get_sp_angle(WRIST));			//Prints at line 13, column 0.
		mvprintw(14, 0, "         curPV   Base: %3.2f    Shoulder: %3.2f    Elbow: %3.2f    Wrist: %3.2f                                         ", get_curr_angle(BASE), get_curr_angle(SHOULDER), get_curr_angle(ELBOW), get_curr_angle(WRIST));	//Prints at line 14, column 0.
		attroff(GREEN_WHITE);	//Wipes print from console.
		refresh();				//Refreshes console (for subsequent prints).
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		/* Prints any warnings and errors. *//////////////////////////////////////////////
		attron(RED_WHITE);		//Prints message with red colour (with white background).
		print_warnings(19, 0);	//Prints any warnings present.
		print_errors(24, 0);	//Prints any errors present.
		attroff(RED_WHITE);		//Wipes print from console.
		refresh();				//Refreshes console (for subsequent prints).
		//////////////////////////////////////////////////////////////////////////////////

		delay_ms(DELAY_10mS);	//Small blocking delay.
	}
	return NULL;				//Returns to main thread (if possible).
}


/**********************************************************************************************
* Name: void create_taskDisplay(void)
* Description: Display thread routine creation function for Lab 4 and Lab 8. The following code 
*			   creates the actual thread for the display thread routine.
*
***********************************************************************************************/
void create_taskDisplay(void) {
	/* Creates display thread. */
	pthread_create(&ID_taskDisplay, NULL, taskDisplay, NULL);
}


/**********************************************************************************************
* Name: void join_taskDisplay(void)
* Description: Thread routine joining function for Lab 4 and Lab 8. The following code forces 
*			   the main thread to wait for the display thread routine to finish before 
*			   terminating alltogether.
*
***********************************************************************************************/
void join_taskDisplay(void) {
	/* Joins display thread. */
	pthread_join(ID_taskDisplay, NULL);
}
