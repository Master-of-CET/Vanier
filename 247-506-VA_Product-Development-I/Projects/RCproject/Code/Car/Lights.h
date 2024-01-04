/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Lights.h
 * 
 * Description: Header file for Lights.cpp file. All macros, function prototypes and dependencies can be found here.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    13 December 2021    First version of header file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed header file.
 * 
 **************************************************************************************************************************************************/


#ifndef LIGHTS_H
#define LIGHTS_H

 /*Dependencies required included below*/
 #include <Arduino.h>

 /*LED driver pins*/
 #define LED_driver_1 3 //Pin D3 -> A (on car schematic).
 #define LED_driver_2 5 //Pin D5 -> B (on car schematic).
 #define LED_driver_3 7 //Pin D7 -> C (on car schematic).

 /*Function prototypes*/
 void Lights_INIT(void);
 void Lights_WRITE(int lights);

#endif
