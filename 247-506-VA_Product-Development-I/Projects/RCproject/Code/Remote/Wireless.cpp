/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Wireless.cpp
 * 
 * Description: All wireless control for RC remote is done in this file. Wireless initialization and reading is done below.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    13 December 2021    First version of source file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed source file.
 * 
 **************************************************************************************************************************************************/


 #include "Wireless.h"

 RF24 radio(Wireless_CE, Wireless_CSN); //Instantiate wireless module.
 const uint64_t pipe = 0xE8E8F0F0E1LL;  //Wireless module address (unique).
 

/**********************************************************************************************
* Name: void Wireless_INIT(void) 
* Description: Initialization function.
*              Initializes remote wireless module. 
* 
***********************************************************************************************/
void Wireless_INIT(void){
 /////////////////////////////////////////////////////////////////
 /*Initializes wireless module as transmitter.*///////////////////
 radio.begin();

 /*Checks wireless module connectivity (for debugging purposes).*/
 //Serial.println("Checking if chip is connected");
 //bool check = radio.isChipConnected();
 //Serial.print("check-");
 //Serial.println(check);
  
 radio.openWritingPipe(pipe);
 radio.setPALevel(RF24_PA_HIGH);
 radio.setDataRate(RF24_250KBPS);
 radio.stopListening();
 /////////////////////////////////////////////////////////////////
}


/**********************************************************************************************
* Name: int Wireless_WRITING(int x, int y) 
* Description: Writing function.
*              Sends data to RC car. 
* 
***********************************************************************************************/
void Wireless_WRITE(int x, int y){
  ////////////////////////////////////////////////////////////////////////////////////
  /*Sends out joystick X and Y values to car.*////////////////////////////////////////

  int data[4];  //Array to store transmitting data.
  
  data[0] = x;  //Joystick X position.
  data[1] = y;  //Joystick Y position.
  
  radio.write(&data, sizeof(data)); //Sends data to car.

  /*Prints joystick X and Y values to serial monitor (for debugging purposes).*/
  //Serial.print("X: ");
  //Serial.println(data[0]);
  //Serial.print("Y: ");
  //Serial.print(data[1]);
  //Serial.print("\t");
  ////////////////////////////////////////////////////////////////////////////////////
}
