#include <Servo.h>

// Variables bloc
Servo myServo1; // Create Servo 1 object
int val;
int pinServo1 = 6; // Enter pin for Servo1
int pinLDR = 2; // Enter pin for LDR - Light Dependent Resistor
int signalLDRValue = 1010; // Value for LDR - Light Dependent Resistor
int angleOne = 90; // Angle one value (old value 70)
int angleTwo = 0; // Angle two value (old value 18)
int delayValue = 2000; // Time delay value (ms)

// DON'T TOUCH CODE BELOW //

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Const
  myServo1.attach(pinServo1);  //Pin where Servo1 motor signal is conected.
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pinLDR); // Pin where LDR is conected.

  // Code for Servo1
  if (val >= signalLDRValue)
  {
    myServo1.write(angleOne);
  }
  else if (val < signalLDRValue) // if less then move back to 0
  {
    myServo1.write(angleTwo); //angle when dark
  }
  delay(delayValue);
}