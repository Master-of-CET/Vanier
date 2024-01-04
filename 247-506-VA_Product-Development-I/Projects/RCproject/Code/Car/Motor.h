/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Motor.h
 * 
 * Description: Header file for Motor.cpp file. All macros, function prototypes and dependencies can be found here.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    13 December 2021    First version of header.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed header file.
 * 
 **************************************************************************************************************************************************/


#ifndef MOTOR_H
#define MOTOR_H

 /*Dependencies required included below*/
 #include <Arduino.h>

 /*Motor speed pins*/
 #define Motor1_EN 9    //Pin D9.
 #define Motor2_EN 11   //Pin D11.
 #define Motor3_EN 13   //Pin D13.
 #define Motor4_EN 23   //Pin D23.

 /*Motor direction pins*/
 #define Motor1_IC1_Input1 29   //Pin D29.
 #define Motor1_IC1_Input2 31   //Pin D31.
 #define Motor2_IC1_Input3 2    //Pin D2.
 #define Motor2_IC1_Input4 4    //Pin D4.
 #define Motor3_IC2_Input1 6    //Pin D6.
 #define Motor3_IC2_Input2 8    //Pin D8.
 #define Motor4_IC2_Input3 10   //Pin D10.
 #define Motor4_IC2_Input4 12   //Pin D12.

 /*Function prototypes*/
 void Motors_INIT(void);
 void Motors_speed_WRITE(int Motor1_speed, int Motor2_speed, int Motor3_speed, int Motor4_speed);
 void Motors_direction_WRITE(int Motor_direction);

#endif
