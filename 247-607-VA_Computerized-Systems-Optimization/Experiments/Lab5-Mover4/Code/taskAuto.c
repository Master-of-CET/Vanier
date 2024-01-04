/**************************************************************************************************
* FileName: taskAuto.c
*
* Name: Leonardo Fusser (1946995)	Lab 6   Mini assembly line
*
* Description: Auto task source file for Lab 6. Here, a task only runs when the user desires it to
*			   run. When this task is running, the Mover4 robot arm performs a pick-and-place 
*			   manouver without the need for the user to manually jog the robot. The manouver only
*			   happens when there is an object placed in front of a sensor next to the robot. When
*			   the robot is finished with the manouver, it returns to an initial position waiting
*			   for an object to appear again.
*			   This task can be interrupted if the user wants to manually jog the robot.
*			   Macro definitions can be found in the taskAuto.h or public.h file.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser	4 March 2022	    v1.0.0		First version of source file.
*													Created all thread init functions.
*													Created thread cancel function.
*													Created distance calcualtor function.
*													Partially populated thread routine.
* Leonardo Fusser	16 March 2022		v1.0.1		Created taskAuto_old() function.
*													Created taskAuto_new() function.
*													Created setAllJoints_0() funciton.
*													Created move_until() function.
*													Added comments.
* Leonardo Fusser	2  April 2022		v2.0.0		Minor changes.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "../header/taskAuto.h"

/* Auto thread ID. */
static pthread_t ID_taskAuto;


/**********************************************************************************************
* Name: void *taskAuto(void *threadid)
* Description: Auto thread routine for Lab 6. The following code performs the auto manouver on
*			   the Mover4 robot arm. The robot will perform the manouver only if there is an
*			   object detected next to the robot.
*			   Macro definitions can be found in the taskAuto.h or public.h file.
*
***********************************************************************************************/
void* taskAuto(void* threadid) {
	
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);			//Allows for thread to be canceled.
	
	float temp_distance;												//Variable to store distance.							
	
	while (1) {
		
		temp_distance = getDistance();									//Gets current distance.

		if (temp_distance <= 10) {										//If an object is detected...
			//taskAuto_old();											//Run auto thread routine without move_until() function.
			taskAuto_new();												//Run auto thread routine with move_until() function.
		}
		delay_ms(DELAY_10mS);											//Small blocking delay.
	}
	return NULL;														//Returns to main thread (if possible).
}


/**********************************************************************************************
* Name: void create_taskAuto(void)
* Description: Auto thread routine creation function for Lab 6. The following code creates
*			   the actual thread for the auto thread routine.
*
***********************************************************************************************/
void create_taskAuto(void) {
	/* Creates auto thread. */
	pthread_create(&ID_taskAuto, NULL, taskAuto, NULL);
}


/**********************************************************************************************
* Name: void cancel_taskAuto(void)
* Description: Auto thread cancel function for Lab 6. The following code cancels the auto thread
*			   when the user no longer wants it to run.
*
***********************************************************************************************/
void cancel_taskAuto(void) {
	/* Cancels auto thread. */
	pthread_cancel(ID_taskAuto);
}


/**********************************************************************************************
* Name: void setAllJoints_0(void)
* Description: Mover4 robot joint setter function for Lab 6. The following code sets all the
*			   joints on the Mover4 robot to 0 degreees using blocking delays.
*
***********************************************************************************************/
void setAllJoints_0(void) {
	set_sp_angle(BASE, 0);		//Sets base to 0 degrees.
	delay_ms(5000);				//Blocking delay.
	set_sp_angle(SHOULDER, 0);	//Sets shoulder to 0 degrees.
	delay_ms(5000);				//Blocking delay.
	set_sp_angle(ELBOW, 0);		//Sets elbow to 0 degrees.
	delay_ms(5000);				//Blocking delay.
	set_sp_angle(WRIST, 0);		//Sets wrist to 0 degrees.
	delay_ms(5000);				//Blocking delay.
}


/**********************************************************************************************
* Name: float getDistance(void)
* Description: Mover4 robot getter function for Lab 6. The following code determines the 
*			   measured distance of an object in front of the Sharp photoelectric sensor.
*			   The distance is calculated in cm.
*
***********************************************************************************************/
float getDistance(void) {
	int rx_ADC;						//Variable to store read ADC value.
	float distance, Vout;			//Variables to calculate distance.
	rx_ADC = readADC(5);			//Reads ADC value.
	Vout = (float)rx_ADC / 2275;	//Calculates Vout.
	distance = 5.5 / Vout;			//Calculates distance (in cm).
	return distance;				//Returns distance (in cm).
}


/**********************************************************************************************
* Name: void taskAuto_old(void)
* Description: Mover4 robot auto manouver function for Lab 6. The following code performs the
*			   pick-and-place manouver on the robot using blocking delays.
*			   Macro definitions can be found in the taskAuto.h or public.h file.
*
***********************************************************************************************/
void taskAuto_old(void) {
	set_speed_max(SPEED_MED, SPEED_MED, SPEED_MED, SPEED_MED);	//Sets all joint speeds to medium.
	delay_ms(3000);												//Blocking delay.
	setAllJoints_0();											//Begin by setting all joints to 0 degrees.

	/* To move the Mover4 robot arm to the first box. *//////////////////////////////////////////////////////
	set_gripper(GRIP_OPEN);										//Open gripper.
	delay_ms(3000);												//Blocking delay.

	set_sp_angle(BASE, -44);									//Set base to -44 degrees.
	delay_ms(5000);												//Blocking delay.
	set_sp_angle(SHOULDER, 59);									//Set shoulder to 59 degrees.
	delay_ms(5000);												//Blocking delay.
	set_sp_angle(WRIST, -39);									//Set wrist to -39 degrees.
	delay_ms(5000);												//Blocking delay.
	set_sp_angle(ELBOW, 66);									//Set elbow to 66 degrees.
	delay_ms(5000);												//Blocking delay.

	set_gripper(GRIP_CLOSE);									//Close gripper.
	delay_ms(3000);												//Small blocking delay.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	/* Intermediate moving. *////////////////////////////////////////////////////////////////////////////////
	set_sp_angle(SHOULDER, 38);									//Set shoulder to 38 degrees.
	delay_ms(5000);												//Blocking delay.
	set_sp_angle(BASE, 39);										//Set base to 39 degrees.
	delay_ms(5000);												//Blocking delay.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	/* To move the Mover4 robot arm to the second box. */////////////////////////////////////////////////////
	set_sp_angle(SHOULDER, 60);									//Set shoulder to 60 degrees.
	delay_ms(5000);												//Blocking delay.
	set_sp_angle(WRIST, -39);									//Set wrist to -39 degrees.
	delay_ms(5000);												//Blocking delay.
	set_sp_angle(ELBOW, 66);									//Set elbow to 66 degrees.
	delay_ms(5000);												//Blocking delay.

	set_gripper(GRIP_OPEN);										//Open gripper.
	delay_ms(3000);												//Blocking delay.

	set_sp_angle(SHOULDER, 38);									//Set shoulder to 38 degrees.
	delay_ms(5000);												//Blocking delay.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	setAllJoints_0();											//Finish by setting all joints to 0 degrees.
	//cancel_taskAuto();										//Cancels auto task (for testing purposes).
}


/**********************************************************************************************
* Name: void taskAuto_new(void)
* Description: Mover4 robot auto manouver function for Lab 6. The following code performs the
*			   pick-and-place manouver on the robot using no blocking delays.
*			   Macro definitions can be found in the taskAuto.h or public.h file.
*
***********************************************************************************************/
void taskAuto_new(void) {
	set_speed_max(SPEED_MED, SPEED_MED, SPEED_MED, SPEED_MED);	//Sets all Mover4 robot joints speed to medium.
	move_until(0, 0, 0, 0);										//Begin by setting all Mover4 robot joints to 0 degrees.
	
	/* To move the Mover4 robot arm to the first box. *///////////////////////////////////////////////////////////////////
	set_gripper(GRIP_OPEN);										//Open gripper.
	move_until(-44, 59, 66, -39);								//Sets all Mover4 robot joints to initial position.
	set_gripper(GRIP_CLOSE);									//Close gripper.
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/* Intermediate moving. */////////////////////////////////////////////////////////////////////////////////////////////
	move_until(39, 38, 66, -39);								//Sets all Mover4 robot joints to intermediate position.
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/* To move the Mover4 robot arm to the second box. *//////////////////////////////////////////////////////////////////
	move_until(39, 60, 66, -39);								//Sets all Mover4 robot joints to final position.
	set_gripper(GRIP_OPEN);										//Open gripper.
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	move_until(39, 38, 66, -39);								//Sets all Mover4 robot joints to intermediate position.
	move_until(0, 0, 0, 0);										//Finish by setting all Mover4 robot joints to 0 degrees.
}


/**********************************************************************************************
* Name: void move_until(double sp_base, double sp_shoulder, double sp_elbow, double sp_wrist)
* Description: Mover4 robot joint setter function for Lab 6. The following code sets all the
*			   joints on the robot depending on what the user wants. 
*			   The function will only terminate if the robot joints are close to what the user
*			   had desired.
*			   Macro definitions can be found in the taskAuto.h or public.h file.
*
***********************************************************************************************/
void move_until(double sp_base, double sp_shoulder, double sp_elbow, double sp_wrist) {

	double errorBASE, errorSHOULDER, errorELBOW, errorWRIST;	//Variables to calculate Mover4 robot joint error.

	set_sp_angle(BASE, sp_base);								//Sets base joint position in degrees.
	set_sp_angle(SHOULDER, sp_shoulder);						//Sets shoulder joint position in degrees.
	set_sp_angle(ELBOW, sp_elbow);								//Sets elbow joint position in degrees.
	set_sp_angle(WRIST, sp_wrist);								//Sets wrist join position in degrees.

	while (1) {
		errorBASE = get_curr_angle(BASE) - sp_base;				//Calculates base joint error.
		errorSHOULDER = get_curr_angle(SHOULDER) - sp_shoulder;	//Calculates shoulder joint error.
		errorELBOW = get_curr_angle(ELBOW) - sp_elbow;			//Calculates elbow joint error.
		errorWRIST = get_curr_angle(WRIST) - sp_wrist;			//Calculates wrist joint error.

		/* If all the Mover4 robot joints reach their desired position... */
		if (fabs(errorBASE) <= _ERROR && fabs(errorSHOULDER) <= _ERROR && fabs(errorELBOW) <= _ERROR && fabs(errorWRIST) <= _ERROR) {
			break;												//Stops running move_until() function.
		}
		delay_ms(DELAY_10mS);									//Small blocking delay.
	}
}
