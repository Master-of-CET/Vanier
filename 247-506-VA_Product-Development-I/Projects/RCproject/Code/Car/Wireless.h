/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Wireless.h
 * 
 * Description: Header file for Wireless.cpp file. All macros, function prototypes and dependencies can be found here.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    13 December 2021    First version of header file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed header file.
 * 
 **************************************************************************************************************************************************/


#ifndef WIRELESS_H
#define WIRELESS_H

 /*Dependencies required included below*/
 #include <Arduino.h>
 #include <SPI.h>
 #include <nRF24L01.h>
 #include <RF24.h>

 /*Wireless module pins*/
 #define Wireless_CE 27   //Pin D27.
 #define Wireless_CSN 25  //Pin D25.

 /*Function prototypes*/
 void Wireless_INIT(void);
 int Wireless_READ(void);

#endif
