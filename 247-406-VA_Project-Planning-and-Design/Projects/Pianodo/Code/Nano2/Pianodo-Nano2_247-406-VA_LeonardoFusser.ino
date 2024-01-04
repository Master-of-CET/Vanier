/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Project Planning & Design 247-406-VA (Winter 2021)
 * Mohamed Tavakoli
 * 
 * Project: Pianodo
 * File name: Nano2.ino
 * 
 * Description: code for Arduino Nano#2 for Pianodo. Nano#2 takes input signals from Nano#1 to print a message on a 16x2 display depending on the 
 *              tune being played on the piano.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date          Description 
 * 
 * v1.0.0   Leonardo Fusser    16 May 2021   Implemented all functions, tunes and comments.
 * 
 **************************************************************************************************************************************************/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int Tune1_Display = 12;       //takes signal sent from NANO#1 to NANO#2 to print message on display (pin D12 on NANO#2)
const int Tune2_Display = 11;       //takes signal sent from NANO#1 to NANO#2 to print message on display (pin D11 on NANO#2)
const int Tune3_Display = 10;       //takes signal sent from NANO#1 to NANO#2 to print message on display (pin D10 on NANO#2)
const int Tune4_Display = 9;        //takes signal sent from NANO#1 to NANO#2 to print message on display (pin D9 on NANO#2)

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //instantation

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {

  lcd.begin(16, 2);                 //initialize 16x2 LCD
  lcd.setCursor(4,0);               //sets cursor to print message at location 4,0 on LCD
  lcd.print("Pianodo");             //prints message
  lcd.setCursor(1,1);               //sets cursor to print message at location 1,1 on LCD
  lcd.print("By:Leonardo F.");      //prints message
  delay(5000);                      //delay
  lcd.clear();                      //clears LCD
  lcd.setCursor(0,0);               //sets cursor to print message at location 0,0 on LCD
  lcd.print("Project Planning");    //prints message
  lcd.setCursor(4,1);               //sets cursor to print message at location 4,1 on LCD
  lcd.print("& Design");            //prints message
  delay(5000);                      //delay
  lcd.clear();                      //clears LCD
  lcd.setCursor(0,1);               //sets cursor to print message at location 0,1 on LCD
  lcd.print("Mohamed Tavakoli");    //prints message
  delay(5000);                      //delay
  lcd.clear();                      //clears LCD
  lcd.print("Starting up...");      //prints message
  delay(3000);                      //delay

  pinMode(Tune1_Display, INPUT);    //takes signal sent from NANO#1 to NANO#2 to print message on display (pin D12 on NANO#2)
  pinMode(Tune2_Display, INPUT);    //takes signal sent from NANO#1 to NANO#2 to print message on display (pin D11 on NANO#2)
  pinMode(Tune3_Display, INPUT);    //takes signal sent from NANO#1 to NANO#2 to print message on display (pin D10 on NANO#2)
  pinMode(Tune4_Display, INPUT);    //takes signal sent from NANO#1 to NANO#2 to print message on display (pin D9 on NANO#2)

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {

  //[Prints Tune1]*********************************************************************************************************************************
  if(digitalRead(Tune1_Display) == HIGH){

    lcd.clear();                                                                                    //clears LCD
    lcd.print("Playing Tune#1!");                                                                   //prints message
    delay(1000);                                                                                    //delay  

    //[Scroll 13 positions (string length + display length) to the left to move it offscreen left]
    for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
      lcd.scrollDisplayLeft();                                                                      //scroll one position left
      delay(150);                                                                                   //delay
    }
    //[Scroll 29 positions (string length + display length) to the right to move it offscreen right]
    for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
      lcd.scrollDisplayRight();                                                                     //scroll one position right
      delay(150);                                                                                   //delay
    }
    //[Scroll 16 positions (display length + string length) to the left to move it back to center]
    for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
      lcd.scrollDisplayLeft();                                                                      //scroll one position left
      delay(150);                                                                                   //delay
    }
    delay(10);                                                                                      //delay
  }

  //[Prints Tune2]*********************************************************************************************************************************
  else if(digitalRead(Tune2_Display) == HIGH){

    lcd.clear();
    lcd.print("Playing Tune#2!");
    delay(1000);

    for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(150);
    }
    for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
      lcd.scrollDisplayRight();
      delay(150);
    }
    for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(150);
    }
    delay(10);
  }

  //[Prints Tune3]*********************************************************************************************************************************
  else if(digitalRead(Tune3_Display) == HIGH){

    lcd.clear();
    lcd.print("Playing Tune#3!");
    delay(1000);

    for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(150);
    }
    for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
      lcd.scrollDisplayRight();
      delay(150);
    }
    for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(150);
    }
    delay(10);
  }

  //[Prints Tune4]*********************************************************************************************************************************
  else if(digitalRead(Tune4_Display) == HIGH){

    lcd.clear();
    lcd.print("Playing Tune#4!");
    delay(1000);

    for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(150);
    }
    for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
      lcd.scrollDisplayRight();
      delay(150);
    }
    for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(150);
    }
    delay(10);
  }

  //[Prints nothing]*******************************************************************************************************************************
  else{
    lcd.clear();                                                              //clears LCD
    lcd.setCursor(0,1);                                                       //sets cursor to print message at location 0,1 on LCD
    lcd.print("Waiting...");                                                  //prints message
    delay(500);                                                               //delay
  }
  
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
