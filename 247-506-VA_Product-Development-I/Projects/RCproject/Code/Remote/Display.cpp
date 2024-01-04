/*************************************************************************************************************************************************
 * Name: Leonardo Fusser (1946995)
 * Product Developpment I 247-506-VA (Fall 2021)
 * Dr. Manijeh Khataie
 * 
 * Project: RC Car Project
 * File name: Display.cpp
 * 
 * Description: All LCD control for the RC remote is done in this file. LCD initialization and toggling is done below.
 * 
 * [Version Control]*******************************************************************************************************************************
 * 
 * Version  Name               Date                Description 
 * 
 * v1.0.0   Leonardo Fusser    13 December 2021    First version of source file.
 * v1.0.1   Leonardo Fusser    14 December 2021    Completed source file.
 * 
 **************************************************************************************************************************************************/


 #include "Display.h"
 #include "Task.h"
 
 LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);   //Instantiate 16x2 LCD.
 

/**********************************************************************************************
* Name: void Display_INIT(void) 
* Description: Initialization function.
*              Initializes LCD display. 
* 
***********************************************************************************************/
void Display_INIT(void){
 //////////////////////////////////////////////////////////////////////////////////////
 /*Initialization for LCD*/////////////////////////////////////////////////////////////
 lcd.begin(16, 2);               //Initialize LCD.
 lcd.clear();                    //Clear LCD display.

 /*Power-up display message.*/
 lcd.setCursor(1,0);             //Sets cursor position to 1,0 on LCD.
 lcd.print("RC Car Project");    //Prints message starting at position 1,0 on LCD.
 lcd.setCursor(1,1);             //Sets cursor position to 1,1 on LCD.
 lcd.print("By:Leonardo F.");    //Prints message starting at position 1,1 on LCD.
 delay(3000);                    //3 second delay.
 lcd.clear();                    //Clear LCD display.
 lcd.setCursor(1,0);             //Sets cursor position to 1,0 on LCD.
 lcd.print("Product Dev. 1");    //Prints message starting at position 1,0 on LCD.
 lcd.setCursor(0,1);             //Sets cursor position to 0,1 on LCD.
 lcd.print("Manijeh  Khataie");  //Prints message starting at position 0,1 on LCD.
 delay(3000);                    //3 second delay.
 ///////////////////////////////////////////////////////////////////////////////////////
}


/**********************************************************************************************
* Name: void Display_WRITE(int write_lcd) 
* Description: Writing function.
*              Toggles LCD output. 
* 
***********************************************************************************************/
void Display_WRITE(int write_lcd){
   //////////////////////////////////////////////////////////////////////////////////////////
   /*All possible user display outputs (depending on position of joystick)*//////////////////
   
   /*Prints "Waiting..." if joystick is idle.*/
   if(write_lcd == joystick_IDLE){
     lcd.clear();              //Clears LCD.
     lcd.setCursor(0,1);       //Sets cursor.
     lcd.print("Waiting...");  //Prints.
   }
  
   /*Prints "Turning left!" if joystick is moved to the left.*/
   else if(write_lcd == joystick_LEFT){
     lcd.clear();                //Clears LCD.
     lcd.setCursor(1,0);         //Sets cursor.
     lcd.print("Turning left!"); //Prints.
   }
  
   /*Prints "Moving forward!" if joystick moved forward.*/
   else if(write_lcd == joystick_FORWARD){
     lcd.clear();                  //Clears LCD.
     lcd.setCursor(1,0);           //Sets cursor.
     lcd.print("Moving forward!"); //Prints.
   }
  
   /*Prints "Turning right!" if joystick moved to the right.*/
   else if(write_lcd == joystick_RIGHT){
     lcd.clear();                  //Clears LCD.
     lcd.setCursor(1,0);           //Sets cursor.
     lcd.print("Turning right!");  //Prints.
   }
  
   /*Prints "Reversing sideways-left!" if joystick moved to bottom left.*/
   else if(write_lcd == joystick_REVERSE_LEFT){
     lcd.clear();                  //Clears LCD.
     lcd.setCursor(1,0);           //Sets cursor.
     lcd.print("Rev. s.-left!");   //Prints.
   }
  
   /*Prints "Reversing!" if joystick moved to bottom.*/
   else if(write_lcd == joystick_REVERSE){
     lcd.clear();              //Clears LCD.
     lcd.setCursor(1,0);       //Sets cursor.
     lcd.print("Reversing!");  //Prints.
   }
  
   /*Prints "Reversing sideways-right!" if joystick moved to bottom right.*/
   else if(write_lcd == joystick_REVERSE_RIGHT){
     lcd.clear();                  //Clears LCD.
     lcd.setCursor(1,0);           //Sets cursor.
     lcd.print("Rev. s.-right!");  //Prints.
   }
  
   /*Prints "Moving sideways-left!" if joystick moved to far left.*/
   else if(write_lcd == joystick_SIDEWAYS_LEFT){
     lcd.clear();                  //Clears LCD.
     lcd.setCursor(1,0);           //Sets cursor.
     lcd.print("Mov. s.-left!");   //Prints.
   }
  
   /*Prints "Moving sideways-right!" if joystick moved to far right.*/
   else if(write_lcd == joystick_SIDEWAYS_RIGHT){
     lcd.clear();                  //Clears LCD.
     lcd.setCursor(1,0);           //Sets cursor.
     lcd.print("Mov. s.-right!");  //Prints.
   }
    
   //////////////////////////////////////////////////////////////////////////////////////////
}
