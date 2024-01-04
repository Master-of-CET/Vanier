/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Wireless.cpp
 * 
 * Description: All wireless control for RC car is done in this file. Wireless initialization and reading is done below.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    22 September 2021   First version of source file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed source file.
 * 
 **************************************************************************************************************************************************/


 #include "Wireless.h"
 #include "Task.h"

 RF24 radio(Wireless_CE, Wireless_CSN);   //Instantiate wireless module.
 const uint64_t pipe = 0xE8E8F0F0E1LL;    //Wireless module address (unique).


/**********************************************************************************************
* Name: void Wireless_INIT(void) 
* Description: Initialization function.
*              Initializes car wireless module. 
* 
***********************************************************************************************/
void Wireless_INIT(void){
 /////////////////////////////////////////////////////////////////////
 /*Initializes wireless module as receiver.*//////////////////////////
 radio.begin();

 /*Checks wireless module connectivity (for debugging purposes).*/
 //Serial.println("Checking if chip is connected...");
 //bool check = radio.isChipConnected();
 //Serial.print("Check result: ");
 //Serial.println(check);
  
 radio.openReadingPipe(0, pipe);
 radio.setPALevel(RF24_PA_MIN);
 radio.setDataRate(RF24_250KBPS);
 radio.startListening();
 /////////////////////////////////////////////////////////////////////
}


/**********************************************************************************************
* Name: int Wireless_READ(void) 
* Description: Reading function.
*              Retreives data sent from RC controller. 
* 
***********************************************************************************************/
int Wireless_READ(void){

  int joystick_direction; //Stores received joystick values.

  if(radio.available()){

    int data[4];                      //Array to store receiving data.
    radio.read(&data, sizeof(data));  //Store retreived data in array.

    /*Prints joystick X and Y values to serial monitor (for debugging purposes).*/
    //Serial.print("X: ");
    //Serial.println(data[0]);
    //Serial.print("Y: ");
    //Serial.print(data[1]);
    //Serial.print("\t");

      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /*All possible car states that can be received*//////////////////////////////////////////////////////////////////////////////
      
      //When car is stopped.
      if((data[0] > 600 && data[1] > 600) && (data[0] < 720 && data[1] < 720)){ //Wide range.
        joystick_direction = NO_TURN;                                           //Assign car state.
        return joystick_direction;                                              //Return car is stopped.
      }

      //When car is turing left.
      else if((data[0] > 1000 && data[1] > 1000) && (data[0] < 1030 && data[1] < 1030)){  //Wide range.
        joystick_direction = LEFT_TURN;                                                   //Assign car state.
        return joystick_direction;                                                        //Return car is turning left.
      }

      //When car is moving forward.
      else if((data[0] > 600 && data[1] > 1000) && (data[0] < 720 && data[1] < 1030)){    //Wide range.
        joystick_direction = FORWARD;                                                     //Assign car state.
        return joystick_direction;                                                        //Return car is moving forward.
      }

      //When car is turning right.
      else if((data[0] > -1 && data[1] > 1000) && (data[0] < 10 && data[1] < 1030)){      //Wide range.
        joystick_direction = RIGHT_TURN;                                                  //Assign car state.
        return joystick_direction;                                                        //Return car is turning right.
      }

      //When car is moving reverse-left.
      else if((data[0] > 1000 && data[1] > -1) && (data[0] < 1030 && data[1] < 10)){      //Wide range.
        joystick_direction = REVERSE_LEFT;                                                //Assign car state.
        return joystick_direction;                                                        //Return car is reversing-left.
      }

      //When car is moving reverse.
      else if((data[0] > 600 && data[1] > -1) && (data[0] < 720 && data[1] < 10)){        //Wide range.
        joystick_direction = REVERSE;                                                     //Assign car state.
        return joystick_direction;                                                        //Return car is reversing.
      }

      //When car is moving reverse-right.
      else if((data[0] > -1 && data[1] > -1) && (data[0] < 20 && data[1] < 20)){          //Wide range.
        joystick_direction = REVERSE_RIGHT;                                               //Assign car state.
        return joystick_direction;                                                        //Return car is reversing-right.
      }

      //When car is moving sideways-left.
      else if((data[0] > 1000 && data[1] > 600) && (data[0] < 1030 && data[1] < 720)){    //Wide range.
        joystick_direction = SIDEWAYS_LEFT;                                               //Assign car state.
        return joystick_direction;                                                        //Return car is moving sideways-left.
      }

      //When car is moving sideways-right.
      else if((data[0] > -1 && data[1] > 600) && (data[0] < 10 && data[1] < 720)){        //Wide range.
        joystick_direction = SIDEWAYS_RIGHT;                                              //Assign car state.
        return joystick_direction;                                                        //Return car is moving sideways-right.
      }

      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
  }
  
  //When car is stopped.
  else{
    joystick_direction = NO_TURN; //Assign car state.
    return joystick_direction;    //Return car is stopped.
  }
  
}
