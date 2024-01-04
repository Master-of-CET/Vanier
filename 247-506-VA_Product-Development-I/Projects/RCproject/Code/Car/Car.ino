/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Car.ino
 * 
 * Description: This is the main file for the RC car. All inititalizing functions and tasks are called below.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    22 September 2021   First version of source file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed source file.
 * 
 **************************************************************************************************************************************************/


#include "Motor.h"
#include "Lights.h"
#include "Wireless.h"
#include "Task.h"


/**********************************************************************************************
* Name: void setup() 
* Description: Setup loop for RC car.
*              Calls all initializing functions. 
* 
***********************************************************************************************/
void setup() {
  Serial.begin(9600); //Serial initialization.
  Motors_INIT();      //Car motors initialization.
  Lights_INIT();      //Car lights initialization.
  Wireless_INIT();    //Wireless module initialization.
}


/**********************************************************************************************
* Name: void loop() 
* Description: Running loop for RC car.
*              Always runs the code in the loop below. 
* 
***********************************************************************************************/
void loop() {   
  Car_TASK();       //Calls task constantly.
}
