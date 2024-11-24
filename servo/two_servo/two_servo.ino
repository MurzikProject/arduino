#include <Servo.h>

// Variables bloc
Servo myServo1; // Create Servo 1 object
Servo myServo2; // Create Servo 2 object
int val;
int pinServo1 = 6; // Enter pin for Servo1
int pinServo2 = 7; // Enter pin for Servo2
int pinLDR = 2; // Enter pin for LDR - Light Dependent Resistor
int signalLDRValue = 1010; // Value for LDR - Light Dependent Resistor
int myServo1AngleOne = 90; // Angle one value (old value 70)
int myServo2AngleOne = 90; // Angle one value (old value 70)
int delayValue = 2000; // Time delay value (ms)
int cntLight = 0; // Light counter

// DON'T TOUCH CODE BELOW //

void setup() {
  // put your setup code here, to run once:(val >= 1010) 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pinLDR); //Pin where LDR is conected.
  
  if (val >= signalLDRValue)
  {
    if (cntLight == 0)
    {
      myServo1.attach(pinServo1);  //Pin where Servo1 motor signal is conected.
      myServo1.write(myServo1AngleOne);
      delay(delayValue);
      cntLight = 1;
    }
    if (cntLight == 2)
    {
      myServo2.attach(pinServo2);  //Pin where Servo2 motor signal is conected.
      myServo2.write(myServo2AngleOne);
      delay(delayValue);
      cntLight = 3;
    }
  }
  if (val < signalLDRValue)
  {
    if (cntLight == 1)
    {
      myServo1.detach();
      delay(delayValue);
      cntLight = 2;
    }
    if (cntLight == 3)
    {
      myServo2.detach();
      delay(delayValue);
      cntLight = 0;
    }
  }
}