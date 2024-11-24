#include <Servo.h>

// Variables bloc
Servo myServo1; // Create Servo 1 object
int val;
int pinServo1 = 6; // Enter pin for Servo1
int pinLDR = 2; // Enter pin for LDR - Light Dependent Resistor
int signalLDRValue = 1010; // Value for LDR - Light Dependent Resistor
int myServo1AngleOne = 90; // Angle one value (old value 70)
int delayValue = 2000; // Time delay value (ms)

// DON'T TOUCH CODE BELOW //

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Const
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pinLDR); // Pin where LDR is conected.

  // Code for Servo1
  if (val >= signalLDRValue)
  {
    myServo1.attach(pinServo1);  //Pin where Servo1 motor signal is conected.
    myServo1.write(myServo1AngleOne);
    delay(delayValue);
  }
  
  else if (val < signalLDRValue) // if less then move back to 0
  {
    myServo1.detach();
    delay(delayValue);
  }
}