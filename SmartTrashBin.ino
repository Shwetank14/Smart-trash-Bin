#include <Servo.h>                    /*   Including the inbuilt library for servo motor */


Servo rotator;          /* Declaring Servo type Object for controlling the Motion of the motor */

// Variable declaration

int pos = 30;  
int trig = 3;
int echo = 2;

float distance,duration;

void setup() 
{
  myservo.attach(4);                    /*  Configuring the Pins   */
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  pinMode(led, OUTPUT);
  rotator.write(pos);
}

void loop() 
{
    /*    Generating pulse of 10 microsecond duration    */
  Serial.begin(9600);           
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);       /*    Calculation of time till the echo pin is HIGH     */
  
  distance = 0.034*(duration/2);
 
  Serial.println(distance);
  
  
  if (distance < 27)              /*    Condition for opening the Lid of the Dustbin       */
  {
    rotator.write(pos+150);
    delay(1000);
  }
  else                             /*   Condition for closing the dustbin Lid when Not in use      */   
  {
      rotator.write(pos);
  }
  delay(1000);
}
