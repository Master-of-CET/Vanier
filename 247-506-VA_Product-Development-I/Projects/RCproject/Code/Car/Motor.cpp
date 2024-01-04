/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Motor.cpp
 * 
 * Description: All motor control for RC car is done in this file. Motor initialization and toggling is done below.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    22 September 2021   First version of source file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed source file.
 * 
 **************************************************************************************************************************************************/


 #include "Motor.h"
 #include "Task.h"


/**********************************************************************************************
* Name: void Motors_INIT(void) 
* Description: Initialization function.
*              Initializes car motors. 
* 
***********************************************************************************************/
void Motors_INIT(void){
  /////////////////////////////////////////////
  /*Motor driver initialization*///////////////
  
  /*Initialize motor direction pins*/
  pinMode(Motor1_IC1_Input1, OUTPUT);
  pinMode(Motor1_IC1_Input2, OUTPUT);
  pinMode(Motor2_IC1_Input3, OUTPUT);
  pinMode(Motor2_IC1_Input4, OUTPUT);
  pinMode(Motor3_IC2_Input1, OUTPUT);
  pinMode(Motor3_IC2_Input2, OUTPUT);
  pinMode(Motor4_IC2_Input3, OUTPUT);
  pinMode(Motor4_IC2_Input4, OUTPUT);

  /*Initialize motor speed pins*/
  pinMode(Motor1_EN, OUTPUT); 
  pinMode(Motor2_EN, OUTPUT);
  pinMode(Motor3_EN, OUTPUT);
  pinMode(Motor4_EN, OUTPUT);
  
  ///////////////////////////////////////////// 
}


/******************************************************************************************************
* Name: void Motors_speed_WRITE(int Motor1_speed, int Motor2_speed, int Motor3_speed, int Motor4_speed) 
* Description: Writing function.
*              Toggles car motor speeds. 
* 
*******************************************************************************************************/
void Motors_speed_WRITE(int Motor1_speed, int Motor2_speed, int Motor3_speed, int Motor4_speed){
  //////////////////////////////////////////////////////////////////////////
  /*Writes speed to all four motors.*///////////////////////////////////////
  analogWrite(Motor1_EN, Motor1_speed); //IC1_ENA pin for Motor1.
  analogWrite(Motor2_EN, Motor2_speed);  //IC1_ENB pin for Motor2.
  analogWrite(Motor3_EN, Motor3_speed);    //IC2_ENA pin for Motor3.
  analogWrite(Motor4_EN, Motor4_speed);      //IC2_ENB pin for Motor4.
  //////////////////////////////////////////////////////////////////////////
}


/**********************************************************************************************
* Name: void Motors_direction_WRITE(int Motor_direction) 
* Description: Writing function.
*              Toggles car motor directions. 
* 
***********************************************************************************************/
void Motors_direction_WRITE(int Motor_direction){
  //////////////////////////////////////////////////////////////////
  /*All possible car direction movements.*//////////////////////////

  /*When car is stopped.*/
  if(Motor_direction == NO_TURN){
    digitalWrite(Motor1_IC1_Input1, LOW);    //For Motor1.
    digitalWrite(Motor1_IC1_Input2, LOW);    //For Motor1.
    digitalWrite(Motor2_IC1_Input3, LOW);      //For Motor2.
    digitalWrite(Motor2_IC1_Input4, LOW);      //For Motor2.
    digitalWrite(Motor3_IC2_Input1, LOW);        //For Motor3.
    digitalWrite(Motor3_IC2_Input2, LOW);        //For Motor3.
    digitalWrite(Motor4_IC2_Input3, LOW);          //For Motor4.
    digitalWrite(Motor4_IC2_Input4, LOW);          //For Motor4.
  }

  /*When car is turning left.*/
  else if(Motor_direction == LEFT_TURN){
    digitalWrite(Motor1_IC1_Input1, LOW);     //For Motor1.
    digitalWrite(Motor1_IC1_Input2, HIGH);    //For Motor1.
    digitalWrite(Motor2_IC1_Input3, HIGH);      //For Motor2.
    digitalWrite(Motor2_IC1_Input4, LOW);       //For Motor2.
    digitalWrite(Motor3_IC2_Input1, HIGH);        //For Motor3.
    digitalWrite(Motor3_IC2_Input2, LOW);         //For Motor3.
    digitalWrite(Motor4_IC2_Input3, HIGH);          //For Motor4.
    digitalWrite(Motor4_IC2_Input4, LOW);           //For Motor4.
  }
  
  /*When car is moving forward.*/
  else if (Motor_direction == FORWARD){
    digitalWrite(Motor1_IC1_Input1, LOW);      //For Motor1.
    digitalWrite(Motor1_IC1_Input2, HIGH);     //For Motor1.
    digitalWrite(Motor2_IC1_Input3, LOW);        //For Motor2.
    digitalWrite(Motor2_IC1_Input4, HIGH);       //For Motor2.
    digitalWrite(Motor3_IC2_Input1, HIGH);         //For Motor3.
    digitalWrite(Motor3_IC2_Input2, LOW);          //For Motor3.
    digitalWrite(Motor4_IC2_Input3, LOW);            //For Motor4.
    digitalWrite(Motor4_IC2_Input4, HIGH);           //For Motor4.
  }

  /*When car is turning right.*/
  else if(Motor_direction == RIGHT_TURN){
    digitalWrite(Motor1_IC1_Input1, HIGH);     //For Motor1.
    digitalWrite(Motor1_IC1_Input2, LOW);      //For Motor1.
    digitalWrite(Motor2_IC1_Input3, LOW);        //For Motor2.
    digitalWrite(Motor2_IC1_Input4, HIGH);       //For Motor2.
    digitalWrite(Motor3_IC2_Input1, LOW);          //For Motor3.
    digitalWrite(Motor3_IC2_Input2, HIGH);         //For Motor3.
    digitalWrite(Motor4_IC2_Input3, LOW);            //For Motor4.
    digitalWrite(Motor4_IC2_Input4, HIGH);           //For Motor4.
  }

  /*When car is moving reverse-left.*/
  else if(Motor_direction == REVERSE_LEFT){
    digitalWrite(Motor1_IC1_Input1, HIGH);     //For Motor1.
    digitalWrite(Motor1_IC1_Input2, LOW);      //For Motor1.
    digitalWrite(Motor2_IC1_Input3, LOW);        //For Motor2.
    digitalWrite(Motor2_IC1_Input4, LOW);        //For Motor2.
    digitalWrite(Motor3_IC2_Input1, LOW);          //For Motor3.
    digitalWrite(Motor3_IC2_Input2, LOW);          //For Motor3.
    digitalWrite(Motor4_IC2_Input3, HIGH);           //For Motor4.
    digitalWrite(Motor4_IC2_Input4, LOW);            //For Motor4.
  }

  /*When car is going reverse.*/
  else if(Motor_direction == REVERSE){
    digitalWrite(Motor1_IC1_Input1, HIGH);      //For Motor1.
    digitalWrite(Motor1_IC1_Input2, LOW);       //For Motor1.
    digitalWrite(Motor2_IC1_Input3, HIGH);        //For Motor2.
    digitalWrite(Motor2_IC1_Input4, LOW);         //For Motor2.
    digitalWrite(Motor3_IC2_Input1, LOW);           //For Motor3.
    digitalWrite(Motor3_IC2_Input2, HIGH);          //For Motor3.
    digitalWrite(Motor4_IC2_Input3, HIGH);            //For Motor4.
    digitalWrite(Motor4_IC2_Input4, LOW);             //For Motor4.
  }

  /*When car is moving reverse-right.*/
  else if(Motor_direction == REVERSE_RIGHT){
    digitalWrite(Motor1_IC1_Input1, LOW);      //For Motor1.
    digitalWrite(Motor1_IC1_Input2, LOW);      //For Motor1.
    digitalWrite(Motor2_IC1_Input3, HIGH);        //For Motor2.
    digitalWrite(Motor2_IC1_Input4, LOW);         //For Motor2.
    digitalWrite(Motor3_IC2_Input1, LOW);           //For Motor3.
    digitalWrite(Motor3_IC2_Input2, HIGH);          //For Motor3.
    digitalWrite(Motor4_IC2_Input3, LOW);             //For Motor4.
    digitalWrite(Motor4_IC2_Input4, LOW);             //For Motor4.
  }

  /*When car is moving sideways-left.*/
  else if(Motor_direction == SIDEWAYS_LEFT){
    digitalWrite(Motor1_IC1_Input1, HIGH);      //For Motor1.
    digitalWrite(Motor1_IC1_Input2, LOW);       //For Motor1.
    digitalWrite(Motor2_IC1_Input3, LOW);         //For Motor2.
    digitalWrite(Motor2_IC1_Input4, HIGH);        //For Motor2.
    digitalWrite(Motor3_IC2_Input1, HIGH);          //For Motor3.
    digitalWrite(Motor3_IC2_Input2, LOW);           //For Motor3.
    digitalWrite(Motor4_IC2_Input3, HIGH);            //For Motor4.
    digitalWrite(Motor4_IC2_Input4, LOW);             //For Motor4.
  }

  /*When car is moving sideways-right.*/
  else if(Motor_direction == SIDEWAYS_RIGHT){
    digitalWrite(Motor1_IC1_Input1, LOW);      //For Motor1.
    digitalWrite(Motor1_IC1_Input2, HIGH);     //For Motor1.
    digitalWrite(Motor2_IC1_Input3, HIGH);       //For Motor2.
    digitalWrite(Motor2_IC1_Input4, LOW);        //For Motor2.
    digitalWrite(Motor3_IC2_Input1, LOW);          //For Motor3.
    digitalWrite(Motor3_IC2_Input2, HIGH);         //For Motor3.
    digitalWrite(Motor4_IC2_Input3, LOW);            //For Motor4.
    digitalWrite(Motor4_IC2_Input4, HIGH);           //For Motor4.
  }

  //////////////////////////////////////////////////////////////////
}
