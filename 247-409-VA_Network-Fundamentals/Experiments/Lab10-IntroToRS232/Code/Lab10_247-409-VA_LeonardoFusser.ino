/*/////////////////////////////////////////////////////////////////////////////////////
/                                                                                     /
/ Name: Leonardo Fusser (1946995)   Class: Networking Fundamentals - Andreea Iftimie  /
/                                                                                     /
/ Description: Prints the letter "L"  two different ways. First way prints the letter /
/              "L" using the builtin serial feature on Arduino UNO. Second way prints /
/               the letter "L" manually by outputing each transmitted symbol; each    /
/               output has a bit-time of around 104uS.                                /
///////////////////////////////////////////////////////////////////////////////////////
/ Version history:                                                                    /
/                                                                                     /
/ v1.0.0    May 3 2021    Created file and completed all parts with comments.         /
/                                                                                     /
/////////////////////////////////////////////////////////////////////////////////////*/


void setup() {

  ///////////////////////////////////////////////////////////////
  /*[For Q2]*/
  //Serial.begin(9600);   //sets baud rate to 9'600
  ///////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////
  /*[For Q3]*/
  pinMode(1, OUTPUT);     //sets pin 1 to output on Arduino UNO
  ///////////////////////////////////////////////////////////////
  
}

void loop() {

  /////////////////////////////
  /*[For Q2]*/
  //Serial.print("L");
  //delay(1000);
  /////////////////////////////

  //////////////////////////////////////////////////////////
  /*[For Q3]*/
  
  digitalWrite(1,LOW);        //first symbol transmitted
  delayMicroseconds(103);     //delay close to bit-time

  digitalWrite(1, LOW);       //second symbol transmitted
  delayMicroseconds(103);     //delay close to bit-time

  digitalWrite(1, LOW);       //third symbol transmitted
  delayMicroseconds(103);     //delay close to bit-time

  digitalWrite(1, HIGH);      //fourth symbol transmitted
  delayMicroseconds(103);     //delay close to bit-time

  digitalWrite(1, HIGH);      //fifth symbol transmitted
  delayMicroseconds(103);     //delay close to bit-time

  digitalWrite(1, LOW);       //sixth symbol transmitted
  delayMicroseconds(103);     //delay close to bit-time

  digitalWrite(1, LOW);       //seventh symbol transmitted
  delayMicroseconds(103);     //delay close to bit-time

  digitalWrite(1, HIGH);      //eighth symbol transmitted
  delayMicroseconds(103);     //delay close to bit-time
  
  digitalWrite(1, LOW);       //nineth symbol transmitted
  delayMicroseconds(103);     //delay close to bit-time

  digitalWrite(1, HIGH);      //tenth symbol transmitted
  delayMicroseconds(103);     //delay close to bit-time

  delay(10);
  //////////////////////////////////////////////////////////
  
}
