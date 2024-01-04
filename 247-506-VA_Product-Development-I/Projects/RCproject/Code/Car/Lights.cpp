/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Lights.cpp
 * 
 * Description: All headlight control for the RC car is done in this file. Headlight initialization and toggling is done below.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    22 September 2021   First version of source file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed source file.
 * 
 **************************************************************************************************************************************************/


 #include "Lights.h"
 #include "Task.h"


/**********************************************************************************************
* Name: void Lights_INIT(void) 
* Description: Initialization function.
*              Initializes car lights. 
* 
***********************************************************************************************/
void Lights_INIT(void){
  /////////////////////////////////////  
  /*LED driver initialization*/////////
  pinMode(LED_driver_1, OUTPUT);
  pinMode(LED_driver_2, OUTPUT);
  pinMode(LED_driver_3, OUTPUT);
  /////////////////////////////////////
}


/**********************************************************************************************
* Name: void Lights_WRITE(int lights) 
* Description: Writing function.
*              Toggles car lights. 
* 
***********************************************************************************************/
void Lights_WRITE(int lights){
  ///////////////////////////////////////////////
  /*All possible car light outputs*//////////////
  
  /*When car is stopped.*/
  if(lights == Lights_STOPPED){
    digitalWrite(LED_driver_1, 0);
    digitalWrite(LED_driver_2, 0);
    digitalWrite(LED_driver_3, 0);
  }

  /*When car  goes forward.*/
  else if(lights == Lights_FORWARD){
    digitalWrite(LED_driver_1, 0);
    digitalWrite(LED_driver_2, 0);
    digitalWrite(LED_driver_3, 1);
  }

  /*When car goes reverse.*/
  else if(lights == Lights_REVERSE_straight){
    digitalWrite(LED_driver_1, 0);
    digitalWrite(LED_driver_2, 1);
    digitalWrite(LED_driver_3, 0);
  }

  /*When car turns left.*/
  else if(lights == Lights_FORWARD_left){
    digitalWrite(LED_driver_1, 0);
    digitalWrite(LED_driver_2, 1);
    digitalWrite(LED_driver_3, 1);
  }

  /*When car turns right.*/
  else if(lights == Lights_FORWARD_right){
    digitalWrite(LED_driver_1, 1);
    digitalWrite(LED_driver_2, 0);
    digitalWrite(LED_driver_3, 0);
  }

  /*When car moves reverse-left.*/
  else if(lights == Lights_REVERSE_left){
    digitalWrite(LED_driver_1, 1);
    digitalWrite(LED_driver_2, 0);
    digitalWrite(LED_driver_3, 1);
  }

  /*When car moves reverse-right.*/
  else if(lights == Lights_REVERSE_right){
    digitalWrite(LED_driver_1, 1);
    digitalWrite(LED_driver_2, 1);
    digitalWrite(LED_driver_3, 0);
  }

  /*When car is in trouble (hazards).*/
  else if(lights == Lights_HAZARDS){
    digitalWrite(LED_driver_1, 1);
    digitalWrite(LED_driver_2, 1);
    digitalWrite(LED_driver_3, 1);
  }
  
  ///////////////////////////////////////////////
}
