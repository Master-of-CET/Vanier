/*
 [Arduino UNO PINOUT]

 -HC-SR04 Sonar Sensor:
    VCC(+5VDC), Trig(Pin11-INPUT), Echo(Pin12-OUTPUT), GND(GND)
 
 -LEDs:
    Purple(pin3-OUTPUT), Purple(pin4-OUTPUT), Purple(pin5-OUTPUT), Purple(pin6-OUTPUT)
 
 -DC Servo Motor:
    Yellow(Pin9-PULSE), Brown(GND), Red(+5VDC)

 -1602 LCD with IC2:
    Yellow(SCL), Green(SDA), Red(+5VDC), Black(GND)

 */
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

// [LCD]
LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display.
 
// [Servo]
Servo myservo;  // create servo object to control a servo.
int pos = 0;    // variable to store the servo position.

// [Sensor] 
int trigPin = 11;             // Trigger (for HC-SR04 sensor)
int echoPin = 12;             // Echo (for HC-SR04 sensor)
long duration, cm, inches;


 
void setup() {
// LCD begin
      lcd.begin();
      lcd.backlight();
      
// Serial Port begin
      Serial.begin (9600);
 
// INPUTS & OUTPUTS
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
      pinMode(3,OUTPUT);
      pinMode(4,OUTPUT);
      pinMode(5,OUTPUT);
      pinMode(6,OUTPUT);
      pinMode(9,OUTPUT);
      myservo.attach(9);  // attaches the servo on pin 9 to the servo object.
}
 
void loop() {

// [Sensor]
      // the sensor is triggered by a HIGH pulse of 10 or more microseconds.
      // give a short LOW pulse beforehand to ensure a clean HIGH pulse:
      digitalWrite(trigPin, LOW);
      delayMicroseconds(5);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

// digitalWrite(3,HIGH);
// digitalWrite(4,HIGH);
// digitalWrite(5,HIGH);
// digitalWrite(6,HIGH);
// digitalWrite(9,HIGH);
  
      // Read the signal from the sensor: a HIGH pulse whose
      // duration is the time (in microseconds) from the sending
      // of the ping to the reception of its echo off of an object.
      pinMode(echoPin, INPUT);
      duration = pulseIn(echoPin, HIGH);
   
      // convert the time into a distance
      cm = (duration/2) / 29.1;     // divide by 29.1 or multiply by 0.0343 .
      inches = (duration/2) / 74;   // divide by 74 or multiply by 0.0135 .

      Serial.print(inches);
      Serial.print("in, ");
      Serial.print(cm);
      Serial.print("cm, ");
      Serial.print(duration);
      Serial.print("duration");
      Serial.println();


// [condiditonal statements]
  if (cm <= 40) {
      // [LED ON]
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(9,HIGH);
      
      // [LCD]
      lcd.clear();
      lcd.print("Happy Halloween!");
      lcd.setCursor (0,1);                  // go to start of 2nd line.
      lcd.print("C.E.T 247-106-VA");
                                            // lcd.print(millis() / 100);
      
      // [Servo ON]
      for (pos = 30; pos <= 120; pos += 1) { // goes from 30 degrees to 120 degrees.
      myservo.write(pos);                    // tell servo to go to position in variable 'pos'.
      delay(6);
      }
      delay(2000);
      // [LED OFF]
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(9,LOW);
      
      // [Servo OFF]
      for (pos = 120; pos >= 30; pos -= 1) { // goes from 120 degrees to 30 degrees.
      myservo.write(pos);                    // tell servo to go to position in variable 'pos'.
      delay(10);
      }
      
      }
  else { 
    
    // [LCD]
    lcd.clear();
    lcd.print("What can i do?");
    lcd.setCursor (0,1);                    // go to start of 2nd line.
    lcd.print("Come closer!");
                                            // lcd.print(millis() / 100);

    // [LED OFF]
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    delay(250);}

}
