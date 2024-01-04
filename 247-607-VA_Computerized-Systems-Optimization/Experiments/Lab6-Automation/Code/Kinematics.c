/**************************************************************************************************
* FileName: Kinematics.c
*
* Name: Leonardo Fusser (1946995)	Lab 7   Kinematics library for a robotic arm in C
*
* Description: Kinematics library source file for Lab 7. Here, there are multiple functions that
*			   deal with kinematics for the Mover4 robot arm. Two functions deal with converting
*			   degrees to radians and radians to degrees. The remaining two functions are inverse
*			   and forward kinematic functions.
*			   Macro constants can be found in the Kinematics.h or public.h file.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser	25 March 2022	    v1.0.0		First version of source file.
*													Partially populated to_angle() function.
*													Added comments.
* Leonardo Fusser	26 March 2022		v1.0.1		Completed to_angle() function.
*													Added and completed to_cart() function.
*													Added comments.
*													Completed source file.
* Leonardo Fusser	2  April 2022		v2.0.0		Minor changes.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "../header/Kinematics.h"

/* Local struct declarations. */
static	kin_f	JointAngles;
static	kin_i	GripperPosition;


/**********************************************************************************************
* Name: double to_radians(double temp_degrees)
* Description: Public function for Lab 7. The following code takes any angle in degrees and
*			   converts it into radians. The function returns the value in radians.
*
***********************************************************************************************/
double to_radians(double temp_degrees) {
	double temp_radians;							//Temp value.
	temp_radians = temp_degrees * (3.14 / 180.0);	//Converts.
	return temp_radians;							//Returns.
}


/**********************************************************************************************
* Name: double to_degrees(double temp_radians)
* Description: Public function for Lab 7. The following code takes any angle in radians and
*			   converts it into degrees. The function returns the value in degrees.
*
***********************************************************************************************/
double to_degrees(double temp_radians) {
	double temp_degrees;							//Temp value.
	temp_degrees = temp_radians * (180.0 / 3.14);	//Converts.
	return temp_degrees;							//Returns.
}


/**********************************************************************************************
* Name: kin_f to_angle(double temp_x, double temp_y, double temp_z, double temp_GripAngle)
* Description: Public function for Lab 7. The following code takes the coordinates of the
*			   Mover4 robot arm gripper and gripper angle to calculate all the Mover4 robot
*			   arm joint angles the robot needs in order to have the desired gripper position.
*			   The function returns all four joint angles and stores them in a struct called
*			   kin_f.
*			   Macro definitions can be found in the Kinematics.h file or the public.h file.
*
***********************************************************************************************/
kin_f to_angle(double temp_x, double temp_y, double temp_z, double temp_GripAngle) {
	
	/* Temp variables. */
	double baseAngle_temp;
	double r_temp;
	double grip_off_z_temp;
	double grip_off_r_temp;
	double z_prime_temp;
	double r_prime_temp;
	double _2h_temp;
	double a1_temp;
	double a2_temp;
	double shldAngle_temp;
	double elbAngle_temp;
	double wristAngle_temp;

	/* Inverse kinematic calculations. */
	baseAngle_temp	= to_degrees(atan2(temp_y, temp_x));																						//Calculates base angle in degrees (not modified).
	r_temp			= sqrt(pow(temp_x, 2) + pow(temp_y, 2));																					//Calculates radial length.
	grip_off_z_temp = -1 * sin(to_radians(temp_GripAngle)) * GRIP_LENGTH;																		//Calculates gripper joint z offset.
	grip_off_r_temp = cos(to_radians(temp_GripAngle)) * GRIP_LENGTH;																			//Calculates gripper joint r offset.
	z_prime_temp	= (temp_z - grip_off_z_temp) - BASE_HEIGHT;																					//Calculates wrist joint z'.
	r_prime_temp	= r_temp - grip_off_r_temp;																									//Calculates wrist joint r'.
	_2h_temp		= sqrt(pow(z_prime_temp, 2) + pow(r_prime_temp, 2));																		//Calculates 2h.
	a1_temp			= to_degrees(atan2(z_prime_temp, r_prime_temp));																			//Calculates A1.
	a2_temp			= to_degrees(acos((pow(HUMERUS_LENGTH, 2) - pow(ARM_LENGTH, 2) + pow(_2h_temp, 2)) / (2 * HUMERUS_LENGTH * _2h_temp)));		//Calculates A2.
	shldAngle_temp	= a1_temp + a2_temp;																										//Calculates shoulder angle in degrees (not modified).
	elbAngle_temp	= to_degrees(acos((pow(HUMERUS_LENGTH, 2) + pow(ARM_LENGTH, 2) - pow(_2h_temp, 2)) / (2 * HUMERUS_LENGTH * ARM_LENGTH)));	//Calculates elbow angle in degrees (not modified).
	wristAngle_temp = 360 - temp_GripAngle - elbAngle_temp - shldAngle_temp;																	//Calculates wrist angle in degrees (not modified).

	/* Angle corrections (specific for Mover4 robot arm). */
	shldAngle_temp	= 90 - shldAngle_temp;			//Subtract 90 degrees from previously calculated shoulder angle.
	elbAngle_temp	= 180 - elbAngle_temp;			//Subtract 180 degrees from previously calculated elbow angle.
	wristAngle_temp = 180 - wristAngle_temp;		//Subtract 180 degrees from previously calculated wrist angle.

	/* Store all four joint angles (corrected) in struct. */
	JointAngles.data[BASE]		= baseAngle_temp;	//Stores base angle (not modified).
	JointAngles.data[SHOULDER]	= shldAngle_temp;	//Stores shoulder angle (modified).
	JointAngles.data[ELBOW]		= elbAngle_temp;	//Stores elbow angle (modified).
	JointAngles.data[WRIST]		= wristAngle_temp;	//Stores wrist angle (modified).

	/* Returns. */
	return JointAngles;
}


/**********************************************************************************************
* Name: kin_f to_cart(double temp_BaseAngle, double temp_ShldAngle, double temp_ElbAngle, double temp_WristAngle)
* Description: Public function for Lab 7. The following function takes all the Mover4 robot arm
*			   joint angles to calculate the needed Mover4 robot arm gripper coordinates. The
*			   function returns all three coordinates (x, y and z) and stores them in a struct
*			   called kin_i.
*			   Macro definitions can be found in the Kinematics.h file or the public.h file.
*
***********************************************************************************************/
kin_i to_cart(double temp_BaseAngle, double temp_ShldAngle, double temp_ElbAngle, double temp_WristAngle) {

	/* Temp variables. */
	double r_temp;
	double z_temp;
	double y_temp;
	double x_temp;
	double grip_off_z_temp;
	double z_prime_temp;

	/* Forward kinematic calculations. */
	r_temp			= HUMERUS_LENGTH * cos(to_radians(90 - temp_ShldAngle)) + ARM_LENGTH * cos(to_radians(90 - temp_ShldAngle - temp_ElbAngle)) + GRIP_LENGTH * cos(to_radians(90 - temp_ShldAngle - temp_ElbAngle - temp_WristAngle));	//Calculates radial length.
	z_prime_temp	= HUMERUS_LENGTH * sin(to_radians(90 - temp_ShldAngle)) + ARM_LENGTH * sin(to_radians(90 - temp_ShldAngle - temp_ElbAngle));																						//Calculates Z'.
	grip_off_z_temp = GRIP_LENGTH * sin(to_radians(90 - temp_ShldAngle - temp_ElbAngle - temp_WristAngle));																																//Calculates gripper joint z offset.
	z_temp			= z_prime_temp + grip_off_z_temp + BASE_HEIGHT;																																										//Calculates Z.
	y_temp			= r_temp * sin(to_radians(temp_BaseAngle));																																											//Calculates Y.
	x_temp			= r_temp * cos(to_radians(temp_BaseAngle));																																											//Calculates X.

	/* Store gripper position in struct. */
	GripperPosition.data[GRIP_X] = x_temp;	//Stores X position.
	GripperPosition.data[GRIP_Y] = y_temp;	//Stores Y position.
	GripperPosition.data[GRIP_Z] = z_temp;	//Stores Z position.

	/* Returns. */
	return GripperPosition;
}
