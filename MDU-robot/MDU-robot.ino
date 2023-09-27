#include <Wire.h>
#include <Servo.h>
#define motorPinRightDir  0//D2
#define motorPinRightSpeed 5//D1

const byte servopin = 14;
const byte servo2pin = 12;
Servo servo;
Servo servo2;

int pos;  

void setup()
{
  pinMode(motorPinRightDir, OUTPUT);
  pinMode(motorPinRightSpeed, OUTPUT);
  
  Serial.begin(9600); //startar serial monitor.
  
  servo.attach(servopin, 544, 2400);
  servo.write(90);
  servo2.attach(servo2pin, 544, 2400);
  servo2.write(90);
}

int varv = 0;
int left = 0;
int right = 1;

void drive (int mdir) {
  digitalWrite(motorPinRightDir, mdir);
  for (int i = 0; i <= 350; i++) {
    analogWrite(motorPinRightSpeed, i);
    delay(20);
  }
  varv++;
  Serial.println(varv);
}

void loop()
{
  servo.write(180);
  servo2.write(0);
  delay(2000);
  servo.write(0);
  servo2.write(180);
  drive(left);
  delay(2000);
  drive(right);
  delay(2000);
}
