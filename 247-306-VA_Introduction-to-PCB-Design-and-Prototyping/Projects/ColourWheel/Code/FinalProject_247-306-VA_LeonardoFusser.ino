/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Code made by: Leonardo Fusser (1946995)                                                                          // 
//For: John Farakh N. Salik                                                                                        // 
//Intro. to PCB Prototyping & Design                                                                               // 
//247-306-VA (Fall 2020)                                                                                           // 
//*****************************************************************************************************************//
//This code is designed to produce 3 different LED patterns and 3 different tones produced by a piezo speaker. Each//
//LED pattern and tones are generated once the push-button on the PCB is pressed once.                             //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 


#include <Adafruit_NeoPixel.h>                                    //Used for NeoPixel LEDs.

#define LED_PIN      1                                            //Pin on ATtiny where first LED is connected too.
#define BUTTON_PIN   4                                            //Pin on ATtiny where push-button is connected too.
#define SPEAKER_PIN  3                                            //Pin on ATtiny where piezo speaker is connected too.
#define NUM_LEDS     10                                           //Number of LEDs on the board.

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

boolean oldState = HIGH;
int     count    = 0;                                             //Used for switch statement below.

//Initialization.
void setup() {
  pinMode(BUTTON_PIN, INPUT);                                     //Sets pin for push-button as INPUT.
  pinMode(SPEAKER_PIN, OUTPUT);                                   //Sets pin for piezo speaker as INPUT.
  strip.begin();
  strip.show();                                                   //Initialize all LEDs to be OFF.
}

void loop() {
  boolean newState = digitalRead(BUTTON_PIN);                     //Read push-button state.

  //Check if state changed from high to low (button press).
  if((newState == LOW) && (oldState == HIGH)) {
    delay(50);                                                    //Check if push-button is still low after debounce.
    newState = digitalRead(BUTTON_PIN);                           //" "
    if(newState == LOW) {                                         //Yes, still low...
      if(++count > 2) count = 0;                                  //Increment "count" by 1.
      switch(count) {                                             //Start the new animation...
        
        case 0:                                                   
          rainbow();                                              //Call "Pattern 2".
          break;
          
        case 1:
          rainbowCycle();                                         //Call "Pattern 3".
          break;
          
        case 2:
          colorWipe(strip.Color( 125, 255, 125));                 //Call "Pattern 1". 
          break;
      }
    }
  }
  oldState = newState;                                            //Set the last read push-button state as old state.
}

//Pattern 1.
void colorWipe(uint32_t c) {
  
  tone(SPEAKER_PIN, 350, 2000);                                   //Creates 350Hz sound on piezo speaker for 2 seconds.
  
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
  }
}

//Pattern 2.
void rainbow(void) {
  uint16_t i, j;
  
  tone(SPEAKER_PIN, 1000, 2000);                                  //Creates 1kHz sound on piezo speaker for 2 seconds.
  
  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
  }
}

//Pattern 3.
void rainbowCycle(void) {
  uint16_t i, j;
  
  tone(SPEAKER_PIN, 500, 2000);                                   //Creates 500Hz sound on piezo speaker for 2 seconds.
  
  //5 cycles of all colors on wheel.
  for(j=0; j<256*5; j++) { 
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
  }
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}
