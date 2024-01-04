/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Project Planning & Design 247-406-VA (Winter 2021)
 * Mohamed Tavakoli
 * 
 * Project: Pianodo
 * File name: Nano1.ino
 * 
 * Description: code for Arduino Nano#1 for Pianodo. Nano#1 takes input signals from ESP32 to select which tune is to be played on the piano. It 
 *              also sends out a signal to Arduino Nano#2 to print a message on a 16x2 display. 
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date          Description 
 * 
 * v1.0.0   Leonardo Fusser    16 May 2021   Implemented all functions, tunes and comments.
 * 
 **************************************************************************************************************************************************/


#include <HC595.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int Tune1 = 12;                                 //receives signal from ESP32 to play Tune1 (pin D12 on NANO#1)
const int Tune2 = 11;                                 //receives signal from ESP32 to play Tune2 (pin D11 on NANO#1)
const int Tune3 = 10;                                 //receives signal from ESP32 to play Tune3 (pin D10 on NANO#1)
const int Tune4 = 9;                                  //receives signal from ESP32 to play Tune4 (pin D9 on NANO#1)

const int Tune1_Display = 8;                          //sends signal from NANO#1 to NANO#2 to print message on display (pin D8 on NANO#1)
const int Tune2_Display = 7;                          //sends signal from NANO#1 to NANO#2 to print message on display (pin D7 on NANO#1)
const int Tune3_Display = 6;                          //sends signal from NANO#1 to NANO#2 to print message on display (pin D6 on NANO#1)
const int Tune4_Display = 5;                          //sends signal from NANO#1 to NANO#2 to print message on display (pin D5 on NANO#1)

const int chipCount = 1;                              //number of serialy connected 74HC595s (8 maximum)
const int latchPin = 3;                               //RCLK pin connected to NANO#1 from logic control board (pin D3 on NANO#1)
const int clockPin = 2;                               //SRCLK pin connected to NANO#1 from logic control board (pin D2 on NANO#1)
const int dataPin = 4;                                //SER pin connected to NANO#1 from logic control board (pin D4 on NANO#1)

HC595 ledArray(chipCount,latchPin,clockPin,dataPin);  //constructor

int delayMs = 150;                                    //played note interval delay
int lastPin = ledArray.lastPin();
int half = int((lastPin+1)/2);

//[Function for Tune4]
void oddsOn() {
  for (int i = 0 ; i <= lastPin ; i+=2) {
    ledArray.setPin(i, ON);
  }
}

//[Function for Tune3]
void inwardSweep() {
  for (int i = 0 ; i < half ; i++) {
    ledArray.setPin(i, TOGGLE);
    ledArray.setPin(lastPin-i, TOGGLE);
    delay(delayMs);
    ledArray.setPin(i, TOGGLE);
    ledArray.setPin(lastPin-i, TOGGLE);
  }
}

//[Function for Tune3]
void outwardSweep() {
  for (int i = half ; i >= 0 ; i--) {
    ledArray.setPin(i, TOGGLE);
    ledArray.setPin(lastPin-i, TOGGLE);
    delay(delayMs);
    ledArray.setPin(i, TOGGLE);
    ledArray.setPin(lastPin-i, TOGGLE);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  
  ledArray.reset();                                   //clears 74HC595s

  pinMode(Tune1, INPUT);                              //receives signal from ESP32 to play Tune1 (pin D12 on NANO#1)
  pinMode(Tune2, INPUT);                              //receives signal from ESP32 to play Tune2 (pin D11 on NANO#1)
  pinMode(Tune3, INPUT);                              //receives signal from ESP32 to play Tune3 (pin D10 on NANO#1)
  pinMode(Tune4, INPUT);                              //receives signal from ESP32 to play Tune4 (pin D9 on NANO#1)

  pinMode(Tune1_Display, OUTPUT);                     //sends signal from NANO#1 to NANO#2 to print message on display (pin D8 on NANO#1)
  pinMode(Tune2_Display, OUTPUT);                     //sends signal from NANO#1 to NANO#2 to print message on display (pin D7 on NANO#1)
  pinMode(Tune3_Display, OUTPUT);                     //sends signal from NANO#1 to NANO#2 to print message on display (pin D6 on NANO#1)
  pinMode(Tune4_Display, OUTPUT);                     //sends signal from NANO#1 to NANO#2 to print message on display (pin D5 on NANO#1)
  
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {

  //[Plays Tune1]*********************************************************************************************************************************
  if(digitalRead(Tune1) == HIGH){
    
    digitalWrite(Tune1_Display, HIGH);                          //sends signal from NANO#1 to NANO#2 to print message on display (pin D8 on NANO#1)
    int followers = random(1,5);
    
    for(int i = 0 ; i <= lastPin ; i++) {
      ledArray.setPin(i, ON);
      if (i >= followers) ledArray.setPin(i-followers, OFF);
      delay(delayMs);                                           //played note interval delay
    }
    for (int i = lastPin-followers ; i <= lastPin; i++) {
      ledArray.setPin(i, OFF);
      delay(delayMs);                                           //played note interval delay
    } 
  }

  //[Playes Tune2]********************************************************************************************************************************
  else if(digitalRead(Tune2) == HIGH){
    
    digitalWrite(Tune2_Display, HIGH);                          //sends signal from NANO#1 to NANO#2 to print message on display (pin D7 on NANO#1)
    
    for (int i = 0 ; i <= lastPin ; i++) {
      ledArray.setPin(i, TOGGLE);
      delay(delayMs);                                           //played note interval delay
      ledArray.setPin(i, TOGGLE);
    }
    for (int i = lastPin ; i >= 0 ; i--) {
      ledArray.setPin(i, TOGGLE); 
      delay(delayMs);                                           //played note interval delay
      ledArray.setPin(i, TOGGLE);
    }
  }

  //[Plays Tune3]*********************************************************************************************************************************
  else if(digitalRead(Tune3) == HIGH){
    
    digitalWrite(Tune3_Display, HIGH);                          //sends signal from NANO#1 to NANO#2 to print message on display (pin D6 on NANO#1)

    outwardSweep();                                             //calls function above void setup()
    inwardSweep();                                              //calls function above void setup()
  }

  //[Plays Tune4]*********************************************************************************************************************************
  else if(digitalRead(Tune4) == HIGH){
    
    digitalWrite(Tune4_Display, HIGH);                          //sends signal from NANO#1 to NANO#2 to print message on display (pin D5 on NANO#1)
    oddsOn();                                                   //calls function above void setup()
    
    ledArray.setPin(random(0,lastPin+1), TOGGLE);
    delay(delayMs);                                             //played note interval delay
  }

  //[Plays nothing]*******************************************************************************************************************************
  else{
    
    digitalWrite(Tune1_Display, LOW);                           
    digitalWrite(Tune2_Display, LOW);
    digitalWrite(Tune3_Display, LOW);
    digitalWrite(Tune4_Display, LOW);

    //[Clears 74HC595s]
    for (int i = 0 ; i <= lastPin ; i++) {
      ledArray.setPin(i, LOW);
      delay(delayMs);                                           //played note interval delay
    }
  }
  
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
