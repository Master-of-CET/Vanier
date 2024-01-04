/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Task.cpp
 * 
 * Description: All car control for RC car is done in this file.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    22 September 2021   First version of source file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed source file.
 * 
 **************************************************************************************************************************************************/


 #include "Task.h"


/**********************************************************************************************
* Name: void Car_TASK(void) 
* Description: Application/Task function.
*              Controls and operates car. 
* 
***********************************************************************************************/
void Car_TASK(void){
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   /*Car control//*/////////////////////////////////////////////////////////////////////////////////////////////////

   int joystick_direction;               //Joystick position variable.
   joystick_direction = Wireless_READ(); //Store received joystick position in joystick position variable.
   delay(100);

   /*When car is stopped.*/
   if(joystick_direction == NO_TURN){
     Lights_WRITE(Lights_STOPPED);                                                       //Toggle lights.
     Motors_speed_WRITE(MOTORS_STOPPED, MOTORS_STOPPED, MOTORS_STOPPED, MOTORS_STOPPED); //Apply motor speed.
     Motors_direction_WRITE(NO_TURN);                                                    //Apply motor direction.
     delay(15);                                                                          //Small delay.
   }

   /*When car is turning left.*/
   else if(joystick_direction == LEFT_TURN){
     Lights_WRITE(Lights_FORWARD_left);                                                  //Toggle lights.
     Motors_speed_WRITE(MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_RUNNING); //Apply motor speed.
     Motors_direction_WRITE(LEFT_TURN);                                                  //Apply motor direction.
     delay(15);                                                                          //Small delay.
   }

   /*When car is moving forward.*/
   else if(joystick_direction == FORWARD){
     Lights_WRITE(Lights_FORWARD);                                                       //Toggle lights.
     Motors_speed_WRITE(MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_RUNNING); //Apply motor speed.
     Motors_direction_WRITE(FORWARD);                                                    //Apply motor direction.
     delay(15);                                                                          //Small delay.
   }

   /*When car is turning right.*/
   else if(joystick_direction == RIGHT_TURN){
     Lights_WRITE(Lights_FORWARD_right);                                                 //Toggle lights.
     Motors_speed_WRITE(MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_RUNNING); //Apply motor speed.
     Motors_direction_WRITE(RIGHT_TURN);                                                 //Apply motor direction.
     delay(15);                                                                          //Small delay.
   }

   /*When car is moving reversing-left.*/
   else if(joystick_direction == REVERSE_LEFT){
     Lights_WRITE(Lights_REVERSE_left);                                                  //Toggle lights.
     Motors_speed_WRITE(MOTORS_RUNNING, MOTORS_STOPPED, MOTORS_STOPPED, MOTORS_RUNNING); //Apply motor speed.
     Motors_direction_WRITE(REVERSE_LEFT);                                               //Apply motor direction.
     delay(15);                                                                          //Small delay.
   }

   /*When car is reversing.*/
   else if(joystick_direction == REVERSE){
     Lights_WRITE(Lights_REVERSE_straight);                                              //Toggle lights.
     Motors_speed_WRITE(MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_RUNNING); //Apply motor speed.
     Motors_direction_WRITE(REVERSE);                                                    //Apply motor direction.
     delay(15);                                                                          //Small delay.
   }

   /*When car is moving reversing-right.*/
   else if(joystick_direction == REVERSE_RIGHT){
     Lights_WRITE(Lights_REVERSE_right);                                                 //Toggle lights.
     Motors_speed_WRITE(MOTORS_STOPPED, MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_STOPPED); //Apply motor speed.
     Motors_direction_WRITE(REVERSE_RIGHT);                                              //Apply motor direction.
     delay(15);                                                                          //Small delay.
   }

   /*When car is moving sideways-left.*/
   else if(joystick_direction == SIDEWAYS_LEFT){
     Lights_WRITE(Lights_FORWARD_left);                                                  //Toggle lights.
     Motors_speed_WRITE(MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_RUNNING); //Apply motor speed.
     Motors_direction_WRITE(SIDEWAYS_LEFT);                                              //Apply motor direction.
     delay(15);                                                                          //Small delay.
   }

   /*When car is moving sideways-right.*/
   else if(joystick_direction == SIDEWAYS_RIGHT){
     Lights_WRITE(Lights_FORWARD_right);                                                 //Toggle lights.
     Motors_speed_WRITE(MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_RUNNING, MOTORS_RUNNING); //Apply motor speed.
     Motors_direction_WRITE(SIDEWAYS_RIGHT);                                             //Apply motor direction.
     delay(15);                                                                          //Small delay.
   }

   /*When car is stopped.*/
   else{
     Lights_WRITE(Lights_STOPPED);                                                       //Toggle lights.
     Motors_speed_WRITE(MOTORS_STOPPED, MOTORS_STOPPED, MOTORS_STOPPED, MOTORS_STOPPED); //Apply motor speed.
     Motors_direction_WRITE(NO_TURN);                                                    //Apply motor direction.
     delay(15);                                                                          //Small delay.
   }

   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
