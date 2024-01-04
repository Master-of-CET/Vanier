/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Task.h
 * 
 * Description: Header file for Task.cpp file. All macros, function prototypes and dependencies can be found here.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    22 September 2021   First version of header file.
 * v1.0.1   Leonardo Fusser    14 December  2021   Completed header file.
 * 
 **************************************************************************************************************************************************/


#ifndef TASK_H
#define TASK_H

 /*Dependencies required included below*/
 #include <Arduino.h>
 #include "Lights.h"
 #include "Motor.h"
 #include "Wireless.h"

 /*All possible car directions*/
 #define FORWARD        1
 #define REVERSE        2
 #define SIDEWAYS_RIGHT 3
 #define SIDEWAYS_LEFT  4
 #define REVERSE_RIGHT  5
 #define REVERSE_LEFT   6
 #define RIGHT_TURN     7
 #define LEFT_TURN      8
 #define NO_TURN        9

 /*All possible car light states*/
 #define Lights_STOPPED           1
 #define Lights_FORWARD           2
 #define Lights_REVERSE_straight  3
 #define Lights_REVERSE_left      4
 #define Lights_REVERSE_right     5
 #define Lights_FORWARD_left      6
 #define Lights_FORWARD_right     7
 #define Lights_HAZARDS           8

 /*Car motor speeds*/
 #define MOTORS_RUNNING 255 //Full speed.
 #define MOTORS_STOPPED 0   //Motor off.

 /*Function prototypes*/
 void Car_TASK (void);

#endif
