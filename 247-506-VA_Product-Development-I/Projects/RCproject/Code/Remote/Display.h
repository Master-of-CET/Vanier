/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Display.h
 * 
 * Description: Header file for Display.cpp file. All macros, function prototypes and dependencies can be found here.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    13 December 2021    First version of header file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed header file.
 * 
 **************************************************************************************************************************************************/


 #ifndef DISPLAY_H
 #define DISPLAY_H

  /*Dependencies required included below*/
  #include <Arduino.h>
  #include <Wire.h>
  #include <LiquidCrystal_I2C.h>

  /*Function prototypes*/
  void Display_INIT(void);
  void Display_WRITE(int write_lcd);

 #endif
 
