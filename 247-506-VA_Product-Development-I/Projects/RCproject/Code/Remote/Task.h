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
 * v1.0.0   Leonardo Fusser    13 December 2021    First version of header file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed header file.
 * 
 **************************************************************************************************************************************************/


 #ifndef TASK_H
 #define TASK_H

  /*Dependencies required included below*/
  #include <Arduino.h>
  #include "Display.h"
  #include "Joystick.h"
  #include "Wireless.h"

  /*All possible joystick positions*/
  #define joystick_IDLE           1
  #define joystick_LEFT           2
  #define joystick_FORWARD        3
  #define joystick_RIGHT          4
  #define joystick_REVERSE_LEFT   5
  #define joystick_REVERSE        6
  #define joystick_REVERSE_RIGHT  7
  #define joystick_SIDEWAYS_LEFT  8
  #define joystick_SIDEWAYS_RIGHT 9

  /*Function prototypes*/
  void Remote_TASK(void);

 #endif
 
