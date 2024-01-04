/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Task.cpp
 * 
 * Description: All remote control for RC remote is done in this file.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    13 December 2021    First version of source file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed source file.
 * 
 **************************************************************************************************************************************************/


 #include "Task.h"
 

/**********************************************************************************************
* Name: void Car_TASK(void) 
* Description: Application/Task function.
*              Controls and operates remote. 
* 
***********************************************************************************************/
void Remote_TASK(void){

 int arr[4];                               //Array to store joystick X and Y positions.
 int* Joystick_X_Y = Joystick_READ(arr);   //Calls Joystick_READ() function to get joystick X and Y positions.

 Wireless_WRITE(Joystick_X_Y[0], Joystick_X_Y[1]); //Calls Wireless_WRITE() function to send joystick X and Y positions to car.

   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   /*Changes LCD output depending on read joystick values*//////////////////////////////////////////////////////////////////////////////////////////
    
   /*Prints status of car to LCD when car is stopped.*/
   if((Joystick_X_Y[0] > 600 && Joystick_X_Y[1] > 600) && (Joystick_X_Y[0] < 720 && Joystick_X_Y[1] < 720)){  //Wide range.
     Display_WRITE(joystick_IDLE);                                                                            //Calls LCD printing function.
     delay(5);                                                                                                //Small delay. 
   }

   /*Prints status of car to LCD when car is turning left.*/
   else if((Joystick_X_Y[0] > 1000 && Joystick_X_Y[1] > 1000) && (Joystick_X_Y[0] < 1030 && Joystick_X_Y[1] < 1030)){ //Wide range.
     Display_WRITE(joystick_LEFT);                                                                                    //Calls LCD printing function.
     delay(5);                                                                                                        //Small delay.
   }

   /*Prints status of car to LCD when car is moving forward.*/
   else if((Joystick_X_Y[0] > 600 && Joystick_X_Y[1] > 1000) && (Joystick_X_Y[0] < 720 && Joystick_X_Y[1] < 1030)){ //Wide range.
     Display_WRITE(joystick_FORWARD);                                                                               //Calls LCD printing function.
     delay(5);                                                                                                      //Small delay.
   }

   /*Prints status of car to LCD when car is turning right.*/
   else if((Joystick_X_Y[0] > -1 && Joystick_X_Y[1] > 1000) && (Joystick_X_Y[0] < 10 && Joystick_X_Y[1] < 1030)){ //Wide range.
     Display_WRITE(joystick_RIGHT);                                                                               //Calls LCD printing function.
     delay(5);                                                                                                    //Small delay.
   }

   /*Prints status of car to LCD when car is moving reverse-left.*/
   else if((Joystick_X_Y[0] > 1000 && Joystick_X_Y[1] > -1) && (Joystick_X_Y[0] < 1030 && Joystick_X_Y[1] < 10)){ //Wide range.
     Display_WRITE(joystick_REVERSE_LEFT);                                                                        //Calls LCD printing function.
     delay(5);                                                                                                    //Small delay.
   }

   /*Prints status of car to LCD when car is reverse.*/
   else if((Joystick_X_Y[0] > 600 && Joystick_X_Y[1] > -1) && (Joystick_X_Y[0] < 720 && Joystick_X_Y[1] < 10)){   //Wide range.
     Display_WRITE(joystick_REVERSE);                                                                             //Calls LCD printing function.
     delay(5);                                                                                                    //Small delay.
   }

   /*Prints status of car to LCD when car is moving reverse-right.*/
   else if((Joystick_X_Y[0] > -1 && Joystick_X_Y[1] > -1) && (Joystick_X_Y[0] < 10 && Joystick_X_Y[1] < 10)){   //Wide range.
     Display_WRITE(joystick_REVERSE_RIGHT);                                                                     //Calls LCD printing function.
     delay(5);                                                                                                  //Small delay.
   }

   /*Prints status of car to LCD when car is moving sideways-left.*/
   else if((Joystick_X_Y[0] > 1000 && Joystick_X_Y[1] > 600) && (Joystick_X_Y[0] < 1030 && Joystick_X_Y[1] < 720)){ //Wide range.
     Display_WRITE(joystick_SIDEWAYS_LEFT);                                                                         //Calls LCD printing function.
     delay(5);                                                                                                      //Small delay.
   }

   /*Prints status of car to LCD when car is moving sideways-right.*/
   else if((Joystick_X_Y[0] > -1 && Joystick_X_Y[1] > 600) && (Joystick_X_Y[0] < 10 && Joystick_X_Y[1] < 720)){     //Wide range.
     Display_WRITE(joystick_SIDEWAYS_RIGHT);                                                                        //Calls LCD printing function.
     delay(5);                                                                                                      //Small delay.
   }

   delay(100);  //Longer delay.
    
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 }
