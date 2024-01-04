/**************************************************************************************************
* FileName: taskKeybd.c
*
* Name: Leonardo Fusser (1946995)	Lab 4   Mover4 robotic arm - simulation mode
*									Lab 6	Mini assembly line
*									Lab 8	Inverse kinematics application
*
* Description: Keyboard task source file for Lab 4, Lab 6 and Lab 8. Here, a task constantly reads 
*			   input from keyboard. Depending on the keys pressed, appropriate angle jogging or 
*			   automation is performed on the Mover4 robot arm. All four parts of the Mover4 robot 
*			   can be angle jogged. Also, the user can select if the Mover4 robot arm runs in auto 
*			   mode, performing a fixed function, or if the Mover4 robot arm runs in kinematic
*			   mode, performing a kinematics function. 
*			   Macro definitions can be found in the taskKeybd.h or public.h file.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser	18 February 2022	v1.0.0		First version of source file.
*													Created task creation function.
*													Created task joining funciton.
*													Filled keyboard task routine.
*													Added comments.
*													Implemented macros.
*													Completed source file.
* Leonardo Fusser	6 March	2022		v1.0.1		Changed include path for compatibility on BBB.
*													Added feature to switch between auto mode and
*													jog mode for the Mover4 robot.
*													Cleaned up comments.
* Leonardo Fusser	16 March 2022		v1.0.2		Minor changes.
* Leonardo Fusser	2 April 2022		v2.0.0		Added feature to select kinematics mode for the
*													Mover4 robot.
*													Added comments.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "../header/taskKeybd.h"

/* Keyboard thread ID. */
static pthread_t ID_taskKeybd;


/**********************************************************************************************
* Name: void *taskKeybd(void *threadid)
* Description: Keyboard thread routine for Lab 4 and Lab 6. User input from the keyboard is 
*			   continously read below. The possible good inputs are the "q", "w", "e", "r", "t", 
*			   "a", "s", "d", "f", "g", "n", "j" and "k" keys. To manually jog the joints on the 
*			   Mover4 robot, the "j" key must be selected. To run the auto mode on the Mover4 
*			   robot, the "n" key must be selected. To run the kinematics task on the Mover4 
*			   robot, the "k" key must be selected. If the "x" key is pressed, the program will 
*			   stop and terminate.
*
***********************************************************************************************/
void* taskKeybd(void* threadid) {
	int temp_Joint1;	//Temp value for getting current base value.
	int temp_Joint2;	//Temp value for getting current shoulder value.
	int temp_Joint3;	//Temp value for getting current elbow value.
	int temp_Joint4;	//Temp value for getting current wrist value.
	int UserInput;		//Variable to store user input from keyboard.
	int AutoFlag = 0;	//Variable to prevent auto task from being created multiple times.
	int JogFlag = 0;	//Variable to prevent manual jogging when auto task is running.
	int KinFlag = 0;	//Variable to prevent kinematic task from being created multiple times.
	
	/* Mini while loop. */
	while (1) {
		UserInput = getch();					//Gets user input from keyboard.
		temp_Joint1 = get_sp_angle(BASE);		//Gets current base value.
		temp_Joint2 = get_sp_angle(SHOULDER);	//Gets current shoulder value.
		temp_Joint3 = get_sp_angle(ELBOW);		//Gets current elbow value.
		temp_Joint4 = get_sp_angle(WRIST);		//Gets current wrist value.

		if (UserInput == 'j') {											//If jog mode selected...
			JogFlag = 0;												//Enables manual jog mode.
			AutoFlag = 0;												//Enables auto mode from being created again.
			KinFlag = 0;												//Enables kinematic mode from being created again.
			cancel_taskAuto();											//Cancels auto task.
			cancel_taskInvKin();										//Cancels kinematic task.
		}
		else if (UserInput == 'n') {									//If auto mode selected...
			if (AutoFlag == 0) {										//If auto mode is enabled...
				create_taskAuto();										//Creates auto task.
			}
			AutoFlag = 1;												//Disables auto mode from being created again.
			JogFlag = 1;												//Disables manual jog mode.
			KinFlag = 1;												//Disables kinematic mode.
		}
		else if (UserInput == 'k') {									//If kinematic mode selected...
			if (KinFlag == 0) {											//If kinematic mode is enabled...
				create_taskInvKin();									//Creates kinematic task.
			}
			KinFlag = 1;												//Disables kinematic task from being created again.
			JogFlag = 1;												//Disables manual jog mode.
			AutoFlag = 1;												//Disables auto mode.
		}
		else if (UserInput == 'x') {									//If "x" key is pressed...
			cancel_taskAuto();											//Cancels auto task.
			cancel_taskInvKin();										//Cancels kinematic task.
			endwin();
			exit(0);													//Quits program.
		}

		if (JogFlag == 0) {												//If manual jog mode is enabled...
			if (UserInput == 'q') {										//If "q" key is pressed...
				set_sp_angle(BASE, temp_Joint1 = temp_Joint1 + 1);		//Increments base angle.
			}
			else if (UserInput == 'w') {								//If "w" key is pressed...
				set_sp_angle(SHOULDER, temp_Joint2 = temp_Joint2 + 1);	//Increments shoulder angle.
			}
			else if (UserInput == 'e') {								//If "e" key is pressed...
				set_sp_angle(ELBOW, temp_Joint3 = temp_Joint3 + 1);		//Increments elbow angle.
			}
			else if (UserInput == 'r') {								//If "r" key is pressed...
				set_sp_angle(WRIST, temp_Joint4 = temp_Joint4 + 1);		//Increments wrist angle.
			}
			else if (UserInput == 't') {								//If "t" key is pressed...
				set_gripper(GRIP_OPEN);									//Opens gripper.
			}
			else if (UserInput == 'a') {								//If "a" key is pressed...
				set_sp_angle(BASE, temp_Joint1 = temp_Joint1 - 1);		//Decrements base angle.
			}
			else if (UserInput == 's') {								//If "s" key is pressed...
				set_sp_angle(SHOULDER, temp_Joint2 = temp_Joint2 - 1);	//Decrements shoulder angle.
			}
			else if (UserInput == 'd') {								//If "d" key is pressed...
				set_sp_angle(ELBOW, temp_Joint3 = temp_Joint3 - 1);		//Decrements elbow angle.
			}
			else if (UserInput == 'f') {								//If "f" key is pressed...
				set_sp_angle(WRIST, temp_Joint4 = temp_Joint4 - 1);		//Decrements wrist angle.
			}
			else if (UserInput == 'g') {								//If "g" key is pressed...
				set_gripper(GRIP_CLOSE);								//Closes gripper.
			}
		}
		delay_ms(DELAY_10mS);											//Small blocking delay.
	}
	return NULL;														//Returns to main thread (if possible).
}


/**********************************************************************************************
* Name: void create_taskKeybd(void)
* Description: Keyboard thread routine creation function for Lab 4, Lab 6 and Lab 8. The 
*			   following code creates the actual thread for the keyboard thread routine.
*
***********************************************************************************************/
void create_taskKeybd(void) {
	/* Creates keyboard thread. */
	pthread_create(&ID_taskKeybd, NULL, taskKeybd, NULL);
}


/**********************************************************************************************
* Name: void join_taskKeybd(void)
* Description: Keyboard thread routine joining function for Lab 4, Lab 6 and Lab 8. The 
*			   following code forces the main thread to wait for the keyboard thread routine to 
*			   finish before terminating alltogether.
*
***********************************************************************************************/
void join_taskKeybd(void) {
	/* Joins keyboard thread. */
	pthread_join(ID_taskKeybd, NULL);
}
