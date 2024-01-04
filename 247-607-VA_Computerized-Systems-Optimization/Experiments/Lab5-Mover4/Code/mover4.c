/****************************************************************************
* mover4.c
*
*	Author				Date			Version
*	Serge Hould			19 March 2019	v1.0.0	Tested ok
*	Serge Hould			3  March 2020	v1.0.1	Add file open
*	Serge Hould			29  March 2020	v1.1.0	Add timer task
*	Serge Hould			15 May 2020		v2		Tested with pdcurses and pthread for windows
											   see 247-611-VA Embedded Operating Systems\W21\Labs\sol_intro_multithread_ncurse
*	Serge Hould			25 May 2020		v3		All task were added and tested. Works fine. Add  #ifdef _WIN32
*	Serge Hould			17 Dec 2020		v3.0.1	Move fd_s and fp from mover4.c DOES NOT WORK
*												TESTED OK ON BBB
*	Serge Hould			23 Dec 2020				TESTED OK ON MOVER4 at Vanier
*	Serge Hould			23 Dec 2020				Ncurse white background
*	Serge Hould			24 Dec 2020				Add task_controller.h.
*												Move fp, fd_s and init_files() inside task_controller.c Tested OK on both VS and BBB
*	Serge Hould			24 Dec 2020		v3.0.2	add call to close_files()
*	Serge Hould			15 Jan 2021		v3.0.2	add call init_ncurses()
*	Leonardo Fusser		18 Feb 2022		v3.0.3	add call create_taskKeybd(), create_taskDisplay(), join_taskKeybd(), join_taskDisplay().
*												add comments.
*	Leonardo Fusser		6 March 2022	v3.0.4	changed include path for compatibility on BBB.
*												cleaned up comments.
*	Leonardo Fusser		26 March 2022	v4.0.0	Added code to test inverse and forward kinematic functions in Kinematics.c file.
*	Leonardo Fusser		2  April 2022	v4.0.1	Minor changes.	
*
*
*
*		Bitrate should be 500000 for Mover4
*		Command to copile:
*							see build file
*
*
*			Note: The master (original) files are always on the SD card
*					Files on my PC are copies.
*
*****************************************************************************/


/* Includes. */
#include "../header/public.h"


/**********************************************************************************************
* Name: int main(int argc, char **argv)
* Description: Main thread function for Lab 4. Here, all init, appropriate task creation and
*			   task join calls are done.
*
***********************************************************************************************/
int main(int argc, char **argv){

	 /* Ncurse config. */
	init_ncurses();  
	
	/* rx-tx CAN init. */
	#ifndef _WIN32
		open_socket();	//CAN socket init.
	#endif
	
	/* Start tasks. */
	startTasksControllerRx();	//Combined tasks pTask_Controller and pTask_Rx.
	create_taskKeybd();			//Creates keyboard task.
	create_taskDisplay();		//Creates display task.

	/* Join tasks. */
	pthread_joinControllerRx();	//Joins task.
	join_taskKeybd();			//Joins keyboard task.
	join_taskDisplay();			//Joins display task.


	/* The following code tests the inverse kinematics function in the Kinematics.c file. */
	//kin_f JointAngles = to_angle(-5.0, 10.0, 23.0, 0.0);		//Should return base angle = 116.56 degrees.
																	//Shoulder angle = 10.96 degrees.
																	//Elbow angle = 18.41 degrees.
																	//Wrist angle = 60.62 degrees.
	//kin_f	JointAngles = to_angle(4.0, 8.0, 25.0, -45.0);		//Should return base angle = 63.43 degrees.
																	//Shoulder angle = -11.57 degrees.
																	//Elbow angle = 60.71 degrees.
																	//Wrist angle = -4.14 degrees.
	//kin_f JointAngles = to_angle(4.0, -6.0, 20.0, 30.0);		//Should return base angle = -56.31 degrees.
																	//Shoulder angle = -15.49 degrees.
																	//Elbow angle = 46.31 degrees.
																	//Wrist angle = 89.18 degrees.
	/*printf("Base angle: %.2f\n",		JointAngles.data[BASE]);		
	printf("Shoulder angle: %.2f\n",	JointAngles.data[SHOULDER]);
	printf("Elbow angle: %.2f\n",		JointAngles.data[ELBOW]);
	printf("Wrist angle: %.2f\n",		JointAngles.data[WRIST]);*/


	/* The following code tests the forward kinematics function in the Kinematics.c file. */
	//kin_i GripPos = to_cart(116.56, 10.96, 18.41, 60.62);		//Should return X = -5 inches.
																	//Y = 10 inches.
																	//Z = 23 inches.
	//kin_i GripPos = to_cart(63.43, -11.57, 60.71, -4.14);		//Should return X = 4 inches.
																	//Y = 8 inches.
																	//Z = 25 inches.
	//kin_i GripPos = to_cart(-56.31, -15.49, 46.31, 89.18);	//Should return X = 4 inches.
																	//Y = -6 inches.
																	//Z = 20 inches.
	/*printf("Gripper X value: %.2f\n", GripPos.data[GRIP_X]);
	printf("Gripper Y value: %.2f\n",	GripPos.data[GRIP_Y]);
	printf("Gripper Z value: %.2f\n",	GripPos.data[GRIP_Z]);*/


	close_files();

    exit(EXIT_SUCCESS);
}
