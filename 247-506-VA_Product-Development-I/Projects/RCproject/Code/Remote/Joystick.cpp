/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Joystick.cpp
 * 
 * Description: All joystick control for RC remote is done in this file. Joystick initialization and reading is done below.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    13 December 2021    First version of source file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed source file.
 * 
 **************************************************************************************************************************************************/


 #include "Joystick.h"
 

/**********************************************************************************************
* Name: void Joystick_INIT(void) 
* Description: Initialization function.
*              Initializes remote joystick. 
* 
***********************************************************************************************/
 void Joystick_INIT(void){
 ////////////////////////////////
 /*Initialize joystick*//////////
 pinMode(Joystick_X, INPUT);
 pinMode(Joystick_Y, INPUT);
 pinMode(Joystick_SW, INPUT);
 ////////////////////////////////
}


/**********************************************************************************************
* Name: int* Joystick_READ(int *X_Y) 
* Description: Read function.
*              Reads joystick values.
* 
***********************************************************************************************/
int* Joystick_READ(int *X_Y){
  ///////////////////////////////////////////////////////////////////////////
  /*Reads joystick value and stores X and Y result in a static array.*///////
  X_Y[0] = analogRead(Joystick_X);  //Reads and stores joystick X value. 
  X_Y[1] = analogRead(Joystick_Y);  //Reads and stores joystick Y value.
  return X_Y;                       //Returns static array.
  ///////////////////////////////////////////////////////////////////////////
}
