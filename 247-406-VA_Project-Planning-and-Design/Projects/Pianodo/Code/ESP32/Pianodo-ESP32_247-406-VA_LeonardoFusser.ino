/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Project Planning & Design 247-406-VA (Winter 2021)
 * Mohamed Tavakoli
 * 
 * Project: Pianodo
 * File name: ESP32.ino
 * 
 * Description: code for ESP32 for Pianodo. ESP32 takes remote signals from mobile phone to play different songs on the piano. It outputs four
 *              signals to Arduino NANO#1 to select the tune to be played on the piano.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date          Description 
 * 
 * v1.0.0   Leonardo Fusser    16 May 2021   Implemented all functions, tunes and comments.
 * 
 **************************************************************************************************************************************************/


#include  <BlynkSimpleEsp32_BLE.h>
#include  <BLEDevice.h>
#include  <BLEServer.h>


////////////////////////////////////////////////////////////////////////////////////////////

#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT

char auth[] = "QbG6Nd9PF7UZ0-i4RxEg0TE-On6CpIAh";   //authentication token from Blynk app

int Tune1 = 22;                                     //pin D2 on ESP32.
int Tune2 = 24;                                     //pin D4 on ESP32.
int Tune3 = 35;                                     //pin D18 on ESP32.
int Tune4 = 38;                                     //pin D19 on ESP32.

////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);                     //initialization
  Blynk.setDeviceName("ESP32-Pianodo");   //sets name for ESP32
  Blynk.begin(auth);                      //initialization
  pinMode(Tune1, OUTPUT);                 //sets pin D2 as output on ESP32
  pinMode(Tune2, OUTPUT);                 //sets pin D4 as output on ESP32
  pinMode(Tune3, OUTPUT);                 //sets pin D18 as output on ESP32
  pinMode(Tune4, OUTPUT);                 //sets pin D19 as output on ESP32
}

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////

void loop() {
  Blynk.run();  //main function
}

/////////////////////////////////
