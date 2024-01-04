/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Joystick.h
 * 
 * Description: Header file for Joystick.cpp file. All macros, function prototypes and dependencies can be found here.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    13 December 2021    First version of source file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed header file.
 * 
 **************************************************************************************************************************************************/


 #ifndef JOYSTICK_H
 #define JOYSTICK_H

  /*Dependencies required included below*/
  #include <Arduino.h>

  /*Joystick pins*/
  #define Joystick_X A1 //Pin A1.
  #define Joystick_Y A0 //Pin A0.
  #define Joystick_SW 4 //Pin D4.

  /*Function prototypes*/
  void Joystick_INIT(void);
  int* Joystick_READ(int *X_Y);

 #endif
 
