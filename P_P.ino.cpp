#include <Arduino.h>
#line 1 "C:\\Users\\AYAN\\Documents\\ArduinoData\\P_P\\P_P.ino"
#include <Wire.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

// Servo servo01;
// Servo servo02;
// Servo servo03;
// Servo servo04;
Servo servo05;
Servo servo06;

AF_DCMotor LeftBackWheel(2);   // Motor 1
AF_DCMotor LeftFrontWheel(1);  // Motor2
AF_DCMotor RightBackWheel(4);  // Motor3
AF_DCMotor RightFrontWheel(3); // Motor4

int Tx = 2;
int Rx = 13;

SoftwareSerial Bluetooth(Tx, Rx);

unsigned int m = 0;
unsigned int dataIn;


//int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos;                         // current position
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos;                   // previous position

int angleToPulse(int ang) {
  if (ang > 180) {
    ang = 180;
  }
  if (ang < 0) {
    ang = 0;
  }
  if (ang >= 0 && ang <= 180) {
    int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX); // map angle of 0 to 180 to Servo min and Servo max
    Serial.print("Angle: ");
    Serial.print(ang);
    Serial.print(" pulse: ");
    Serial.println(pulse);
    return pulse;
  } else {
    Serial.println("-");
  }
}

void setup() {
  // put your setup code here, to run once:
  Bluetooth.begin(9600);
  Bluetooth.setTimeout(5);
  // servo01.attach(10);
  // servo02.attach(9);
  // servo03.attach(7);
  // servo04.attach(6);
  servo05.attach(9);
  servo06.attach(10);

  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(60);
  delay(20);

  servo1PPos = 90;
  pwm.setPWM(0, 0, angleToPulse(servo1PPos) );
  servo2PPos = 100;
  pwm.setPWM(1, 0, angleToPulse(servo2PPos) );
  servo3PPos = 120;
  pwm.setPWM(2, 0, angleToPulse(servo3PPos) );
  servo4PPos = 95;
  pwm.setPWM(3, 0, angleToPulse(servo4PPos) );
  servo5PPos = 60;
  servo05.write(servo5PPos);
  servo6PPos = 60;
  servo06.write(servo5PPos);
}

int wheelSpeed = 200;
int speedDelay = 20;

void moveForward()
{
  Serial.println("working");
  LeftFrontWheel.run(FORWARD);
  LeftFrontWheel.setSpeed(wheelSpeed);

  LeftBackWheel.run(FORWARD);
  LeftBackWheel.setSpeed(wheelSpeed);

  RightFrontWheel.run(FORWARD);
  RightFrontWheel.setSpeed(wheelSpeed);

  RightBackWheel.run(FORWARD);
  RightBackWheel.setSpeed(wheelSpeed);
}
void moveBackward()
{
  LeftFrontWheel.run(BACKWARD);
  LeftFrontWheel.setSpeed(wheelSpeed);

  LeftBackWheel.run(BACKWARD);
  LeftBackWheel.setSpeed(wheelSpeed);

  RightFrontWheel.run(BACKWARD);
  RightFrontWheel.setSpeed(wheelSpeed);

  RightBackWheel.run(BACKWARD);
  RightBackWheel.setSpeed(wheelSpeed);

}
void moveSidewaysRight()
{
  for ( int i = 0; i < 6; i++ ) {
    LeftFrontWheel.run(FORWARD);
    LeftFrontWheel.setSpeed(wheelSpeed);

    LeftBackWheel.run(BACKWARD);
    LeftBackWheel.setSpeed(wheelSpeed);

    RightFrontWheel.run(FORWARD);
    RightFrontWheel.setSpeed(wheelSpeed);

    RightBackWheel.run(BACKWARD);
    RightBackWheel.setSpeed(wheelSpeed);
  }
}

void moveSidewaysLeft()
{
  for ( int i = 0; i < 6; i++ ) {
    LeftFrontWheel.run(BACKWARD);
    LeftFrontWheel.setSpeed(wheelSpeed);

    LeftBackWheel.run(FORWARD);
    LeftBackWheel.setSpeed(wheelSpeed);

    RightFrontWheel.run(BACKWARD);
    RightFrontWheel.setSpeed(wheelSpeed);

    RightBackWheel.run(FORWARD);
    RightBackWheel.setSpeed(wheelSpeed);
    delay(25);
  }
}
void rotateLeft()
{
  LeftFrontWheel.run(BACKWARD);
  LeftFrontWheel.setSpeed(wheelSpeed);

  LeftBackWheel.run(BACKWARD);
  LeftBackWheel.setSpeed(wheelSpeed);

  RightFrontWheel.run(FORWARD);
  RightFrontWheel.setSpeed(wheelSpeed);

  RightBackWheel.run(FORWARD);
  RightBackWheel.setSpeed(wheelSpeed);

}
void rotateRight()
{
  LeftFrontWheel.run(FORWARD);
  LeftFrontWheel.setSpeed(wheelSpeed);

  LeftBackWheel.run(FORWARD);
  LeftBackWheel.setSpeed(wheelSpeed);

  RightFrontWheel.run(BACKWARD);
  RightFrontWheel.setSpeed(wheelSpeed);

  RightBackWheel.run(BACKWARD);
  RightBackWheel.setSpeed(wheelSpeed);

}
void moveLeftForward()
{
  LeftFrontWheel.run(RELEASE);
  //  LeftFrontWheel.setSpeed(wheelSpeed);

  LeftBackWheel.run(FORWARD);
  LeftBackWheel.setSpeed(wheelSpeed);

  RightFrontWheel.run(RELEASE);

  RightBackWheel.run(FORWARD);
  RightBackWheel.setSpeed(wheelSpeed);

}
void moveLeftBackward()
{
  LeftFrontWheel.run(RELEASE);

  LeftBackWheel.run(BACKWARD);
  LeftBackWheel.setSpeed(wheelSpeed);

  RightFrontWheel.run(RELEASE);
  // RightFrontWheel.setSpeed(wheelSpeed);

  RightBackWheel.run(BACKWARD);
  RightBackWheel.setSpeed(wheelSpeed);

}
void moveRightForward()
{
  LeftFrontWheel.run(FORWARD);
  LeftFrontWheel.setSpeed(wheelSpeed);

  LeftBackWheel.run(RELEASE);

  RightFrontWheel.run(FORWARD);
  RightFrontWheel.setSpeed(wheelSpeed);

  RightBackWheel.run(RELEASE);
}
void moveRightBackward()
{
  LeftFrontWheel.run(BACKWARD);
  LeftFrontWheel.setSpeed(wheelSpeed);
  Serial.println("working");
  LeftBackWheel.run(RELEASE);

  RightFrontWheel.run(BACKWARD);
  RightFrontWheel.setSpeed(wheelSpeed);

  RightBackWheel.run(RELEASE);
}
void stopMoving()
{
  LeftFrontWheel.run(RELEASE);
  LeftBackWheel.run(RELEASE);
  RightFrontWheel.run(RELEASE);
  RightBackWheel.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Check for incoming data
  byte BT = Bluetooth.available();
  if (BT > 0)
  {
    dataIn = Bluetooth.read(); // Read the data
    Serial.println(dataIn);
    if (dataIn == 0)
    {
      m = 0;
    }
    if (dataIn == 1)
    {
      m = 1;
    }
    if (dataIn == 2)
    {
      m = 2;
    }
    if (dataIn == 3)
    {
      m = 3;
    }
    if (dataIn == 4)
    {
      m = 4;
    }
    if (dataIn == 5)
    {
      m = 5;
    }
    if (dataIn == 6)
    {
      m = 6;
    }
    if (dataIn == 7)
    {
      m = 7;
    }
    if (dataIn == 8)
    {
      m = 8;
    }
    if (dataIn == 9)
    {
      m = 9;
    }
    if (dataIn == 10)
    {
      m = 10;
    }
    if (dataIn == 11)
    {
      m = 11;
    }
    if (dataIn == 12)
    {
      m = 12;
    }
    if (dataIn == 14)
    {
      m = 14;
    }
    if (dataIn == 16)
    {
      m = 16;
    }
    if (dataIn == 17)
    {
      m = 17;
    }
    if (dataIn == 18)
    {
      m = 18;
    }
    if (dataIn == 19)
    {
      m = 19;
    }
    if (dataIn == 20)
    {
      m = 20;
    }
    if (dataIn == 21)
    {
      m = 21;
    }
    if (dataIn == 22)
    {
      m = 22;
    }
    if (dataIn == 23)
    {
      m = 23;
    }
    if (dataIn == 24)
    {
      m = 24;
    }
    if (dataIn == 25)
    {
      m = 25;
    }
    if (dataIn == 26)
    {
      m = 26;
    }
    if (dataIn == 27)
    {
      m = 27;
    }

    // Move the Mecanum wheels platform
    if (m == 4)
    {
      moveSidewaysLeft();
    }
    if (m == 5)
    {
      moveSidewaysRight();
    }
    if (m == 2)
    {
      moveForward();
    }
    if (m == 7)
    {
      moveBackward();
    }
    if (m == 3)
    {
      moveRightForward();
    }
    if (m == 1)
    {
      moveLeftForward();
    }
    if (m == 8)
    {
      moveRightBackward();
    }
    if (m == 6)
    {
      moveLeftBackward();
    }
    if (m == 9)
    {
      rotateLeft();
    }
    if (m == 10)
    {
      rotateRight();
    }

    if (m == 0)
    {
      stopMoving();
    }

    // Mecanum wheels speed
    if (dataIn > 30 & dataIn < 100)
    {
      wheelSpeed = dataIn * 20;
    }

    // Move robot arm
    // Move servo 1 in positive direction
    while (m == 16)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      if (servo1PPos >= 0 && servo1PPos <= 180) {
        pwm.setPWM(0, 0, angleToPulse(servo1PPos) );
        servo1PPos++;
        delay(speedDelay);
      }
      if (servo1PPos < 0) {
        servo1PPos = 0;
      }
      if (servo1PPos > 180) {
        servo1PPos = 180;
      }
    }
    // Move servo 1 in negative direction
    while (m == 17)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      if (servo1PPos >= 0 && servo1PPos <= 180) {
        pwm.setPWM(0, 0, angleToPulse(servo1PPos) );
        servo1PPos--;
        delay(speedDelay);
      }
      if (servo1PPos < 0) {
        servo1PPos = 0;
      }
      if (servo1PPos > 180) {
        servo1PPos = 180;
      }
    }
    // Move servo 2
    while (m == 19)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      if (servo2PPos >= 0 && servo2PPos <= 180) {
        pwm.setPWM(1, 0, angleToPulse(servo2PPos) );
        servo2PPos++;
        delay(speedDelay);
      }
      if (servo2PPos < 0) {
        servo2PPos = 0;
      }
      if (servo2PPos > 180) {
        servo2PPos = 180;
      }
    }
    while (m == 18)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      if (servo2PPos >= 0 && servo2PPos <= 180) {
        pwm.setPWM(1, 0, angleToPulse(servo2PPos) );
        servo2PPos--;
        delay(speedDelay);
      }
      if (servo2PPos < 0) {
        servo2PPos = 0;
      }
      if (servo2PPos > 180) {
        servo2PPos = 180;
      }
    }
    // Move servo 3
    while (m == 20)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      if (servo3PPos >= 0 && servo3PPos <= 180) {
        pwm.setPWM(2, 0, angleToPulse(servo3PPos) );
        servo3PPos++;
        delay(speedDelay);
      }
      if (servo3PPos < 0) {
        servo3PPos = 0;
      }
      if (servo3PPos > 180) {
        servo3PPos = 180;
      }
    }
    while (m == 21)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      if (servo3PPos >= 0 && servo3PPos <= 180) {
        pwm.setPWM(2, 0, angleToPulse(servo3PPos) );
        servo3PPos--;
        delay(speedDelay);
      }
      if (servo3PPos < 0) {
        servo3PPos = 0;
      }
      if (servo3PPos > 180) {
        servo3PPos = 180;
      }
    }
    // Move servo 4
    while (m == 23)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      if (servo4PPos >= 0 && servo4PPos <= 180) {
        pwm.setPWM(3, 0, angleToPulse(servo4PPos));
        servo4PPos++;
        delay(speedDelay);
      }
      if (servo4PPos < 0) {
        servo4PPos = 0;
      }
      if (servo4PPos > 180) {
        servo4PPos = 180;
      }
    }
    while (m == 22)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      if (servo4PPos >= 0 && servo4PPos <= 180) {
        pwm.setPWM(3, 0, angleToPulse(servo4PPos) );
        servo4PPos--;
        delay(speedDelay);
      }
      if (servo4PPos < 0) {
        servo4PPos = 0;
      }
      if (servo4PPos > 180) {
        servo4PPos = 180;
      }
    }
    // Move servo 5
    while (m == 25)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      if (servo5PPos >= 0 && servo5PPos <= 180) {
        servo05.write(servo5PPos);
        servo5PPos++;
        delay(speedDelay);
      }
      if (servo5PPos < 0) {
        servo5PPos = 0;
      }
      if (servo5PPos > 180) {
        servo5PPos = 180;
      }
    }
    while (m == 24)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      if (servo5PPos >= 0 && servo5PPos <= 180) {
        servo05.write(servo5PPos);
        servo5PPos--;
        delay(speedDelay);
      }
      if (servo5PPos < 0) {
        servo5PPos = 0;
      }
      if (servo5PPos > 180) {
        servo5PPos = 180;
      }
    }
    // Move servo 6
    while (m == 26)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      if (servo6PPos >= 0 && servo6PPos <= 180) {
        servo06.write(servo6PPos);
        servo6PPos++;
        delay(speedDelay);
      }
      if (servo6PPos < 83) {
        servo6PPos = 84;
      }
      if (servo6PPos > 180) {
        servo6PPos = 180;
      }
    }
    while (m == 27)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      if (servo6PPos >= 0 && servo6PPos <= 180) {
        Serial.println(servo6PPos);
        servo06.write(servo6PPos);
        servo6PPos--;
        delay(speedDelay);
      }
      if (servo6PPos < 83) {
        servo6PPos = 84;
      }
      if (servo6PPos > 180) {
        servo6PPos = 180;
      }
    }
  }
  //  int S = analogRead(A1);
  //  Serial.println(S);
  //   int sensorValue = analogRead(A0);
  //   float voltage = sensorValue*(5.0/1023.00)*3;
  //   if (voltage < 11){
  //     Serial.println(voltage);
  //   }
  //   else{
  //    Serial.println(voltage);
  //     Serial.println("Battery Charged");
  //   }
}

