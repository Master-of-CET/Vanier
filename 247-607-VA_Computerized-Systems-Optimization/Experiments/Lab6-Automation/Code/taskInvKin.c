/**************************************************************************************************
* FileName: taskInvKin.c
*
* Name: Leonardo Fusser (1946995)	Lab 8   Inverse kinematics application
*
* Description: Inverse kinematics task source file for Lab 8. Here, a task continously runs a custom
*			   API that allows the Mover4 robot to perform a circular motion. A custom radius, offset
*			   and grip angle are specified (as macros).
*			   Macro definitions can be found in the taskInvKin.h or public.h file.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser	1 April 2022	    v1.0.0		First version of source file.
*													Created thread routine.
*													Created thread creation function.
*													Created thread cancelling function.
*													Created circular kinematics function.
*													Added comments.
* Leonardo Fusser	2  April 2022		v1.0.1		Populated circular kinematics function.
*													Added comments.
* Leonardo Fusser	5  April 2022		v.1.0.2		Completed circular kinematics function.
*													Completed source file.
*													Added comments.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "../header/taskInvKin.h"

/* Auto thread ID. */
static pthread_t ID_taskInvKin;

/* Local struct declaration. */
static	kin_f	temp_JointAngles;


/**********************************************************************************************
* Name: void *taskInvKin(void *threadid)
* Description: kinematics thread routine for Lab 8. The following thread routine continously
*			   runs a circle movement function on the Mover4 robot arm.
*			   Macro definitions can be found in the taskInvKin.h or public.h file.
*
***********************************************************************************************/
void* taskInvKin(void* threadid) {

	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);	//Allows for thread to be canceled.

	while (1) {

		/* The following code tests a scenario on the Mover4 robot. */
		/*temp_JointAngles = to_angle(10, 10, 15, -45);
		move_until(temp_JointAngles.data[BASE], temp_JointAngles.data[SHOULDER], 
				   temp_JointAngles.data[ELBOW], temp_JointAngles.data[WRIST]);
		delay_ms(10000);
		temp_JointAngles = to_angle(15, -10, 10, 45);
		move_until(temp_JointAngles.data[BASE], temp_JointAngles.data[SHOULDER], 
				   temp_JointAngles.data[ELBOW], temp_JointAngles.data[WRIST]);
		delay_ms(10000);*/

		circle_yz_plane();										//Performs circle manouver.

		delay_ms(DELAY_10mS);									//Small blocking delay.
	}
	return NULL;												//Returns to main thread (if possible).
}


/**********************************************************************************************
* Name: void create_taskInvKin(void)
* Description: kinematics thread routine creation function for Lab 8. The following code creates
*			   the actual thread for the kinematics thread routine.
*
***********************************************************************************************/
void create_taskInvKin(void) {
	/* Creates kinematics thread. */
	pthread_create(&ID_taskInvKin, NULL, taskInvKin, NULL);
}


/**********************************************************************************************
* Name: void cancel_taskInvKin(void)
* Description: kinematics thread cancel function for Lab 8. The following code cancels the
*			   kinematics thread when the user no longer wants it to run.
*
***********************************************************************************************/
void cancel_taskInvKin(void) {
	/* Cancels auto thread. */
	pthread_cancel(ID_taskInvKin);
}


/**********************************************************************************************
* Name: void circle_yz_plane(void)
* Description: circle movement function that creates a circular movement on the Mover4 robot.
*			   The following code utilizes the custom made kinematics library that was made
*			   previously.
*			   Macro definitions can be found in the taskInvKin.h or public.h file.
*
***********************************************************************************************/
void circle_yz_plane(void) {

	int pos_temp;																	//Temp position variable.
	float y_temp = 0.0;																//Temp variable for y-variable.
	float z_temp = 0.0;																//Temp variable for z-variable.

	set_speed_max(SPEED_MED, SPEED_MED, SPEED_MED, SPEED_MED);						//Sets all joint speeds to medium.

	/* For loop to make the Mover4 robot perform a circular motion. */
	for (pos_temp = 0; pos_temp <= 315; pos_temp += 45) {							//Performs circular motion with 45 degree stepping.
		z_temp = RADIUS * cos(to_radians(pos_temp)) + OFFSET_Z;						//Calculates z-value.
		y_temp = RADIUS * sin(to_radians(pos_temp)) + OFFSET_Y;						//Calculates y-value.

		temp_JointAngles = to_angle(X0, y_temp, z_temp, GRIP_ANGLE);				//Gets all four joint angles.
		move_until(temp_JointAngles.data[BASE], temp_JointAngles.data[SHOULDER],	//Moves the Mover4 robot arm.
				   temp_JointAngles.data[ELBOW], temp_JointAngles.data[WRIST]);		//" ".

		set_gripper(GRIP_OPEN);														//Opens the gripper.
		delay_ms(1000);																//Delay for 1 second.
		set_gripper(GRIP_CLOSE);													//Closes the gripper.
		delay_ms(1000);																//Delay for 1 second.
	}

}
