#include <SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h>

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;

AF_DCMotor LeftBackWheel(1);   // Motor 1
AF_DCMotor LeftFrontWheel(2);  // Motor2
AF_DCMotor RightBackWheel(3);  // Motor3
AF_DCMotor RightFrontWheel(4); // Motor4

int Tx = 12;
int Rx = 13;

SoftwareSerial Bluetooth(Tx, Rx);

unsigned int m = 0;
unsigned int dataIn;

int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos;                         // current position
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos;                   // previous position

void setup() {
  // put your setup code here, to run once:
  Bluetooth.begin(9600);
  Bluetooth.setTimeout(5);
  servo01.attach(10);
  servo02.attach(9);
  servo03.attach(7);
  servo04.attach(6);
  servo05.attach(5);
  servo06.attach(3);

  Serial.begin(9600);
  delay(20);

  servo1PPos = 90;
  servo01.write(servo1PPos);
  servo2PPos = 100;
  servo02.write(servo2PPos);
  servo3PPos = 120;
  servo03.write(servo3PPos);
  servo4PPos = 95;
  servo04.write(servo4PPos);
  servo5PPos = 60;
  servo05.write(servo5PPos);
  servo6PPos = 110;
  servo06.write(servo6PPos);

}


int wheelSpeed = 200;
int speedDelay = 20;


void moveForward()
{
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
  LeftFrontWheel.run(FORWARD);
  LeftFrontWheel.setSpeed(wheelSpeed);

  LeftBackWheel.run(BACKWARD);
  LeftBackWheel.setSpeed(wheelSpeed);

  RightFrontWheel.run(BACKWARD);
  RightFrontWheel.setSpeed(wheelSpeed);

  RightBackWheel.run(FORWARD);
  RightBackWheel.setSpeed(wheelSpeed);
}

void moveSidewaysLeft()
{
  LeftFrontWheel.run(BACKWARD);
  LeftFrontWheel.setSpeed(wheelSpeed);

  LeftBackWheel.run(FORWARD);
  LeftBackWheel.setSpeed(wheelSpeed);

  RightFrontWheel.run(FORWARD);
  RightFrontWheel.setSpeed(wheelSpeed);

  RightBackWheel.run(BACKWARD);
  RightBackWheel.setSpeed(wheelSpeed);
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
void moveRightForward()
{
  LeftFrontWheel.run(FORWARD);
  LeftFrontWheel.setSpeed(wheelSpeed);

  LeftBackWheel.run(RELEASE);

  RightFrontWheel.run(RELEASE);

  RightBackWheel.run(FORWARD);
  RightBackWheel.setSpeed(wheelSpeed);
}
void moveRightBackward()
{
  LeftFrontWheel.run(RELEASE);

  LeftBackWheel.run(BACKWARD);
  LeftBackWheel.setSpeed(wheelSpeed);

  RightFrontWheel.run(BACKWARD);
  RightFrontWheel.setSpeed(wheelSpeed);

  RightBackWheel.run(RELEASE);
}
void moveLeftForward()
{
  LeftFrontWheel.run(RELEASE);

  LeftBackWheel.run(FORWARD);
  LeftBackWheel.setSpeed(wheelSpeed);

  RightFrontWheel.run(FORWARD);
  RightFrontWheel.setSpeed(wheelSpeed);

  RightBackWheel.run(RELEASE);
}
void moveLeftBackward()
{
  LeftFrontWheel.run(BACKWARD);
  LeftFrontWheel.setSpeed(wheelSpeed);

  LeftBackWheel.run(RELEASE);

  RightFrontWheel.run(RELEASE);

  RightBackWheel.run(BACKWARD);
  RightBackWheel.setSpeed(wheelSpeed);
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
  if (Bluetooth.available() > 0)
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
      servo01.write(servo1PPos);
      servo1PPos++;
      delay(speedDelay);
    }
    // Move servo 1 in negative direction
    while (m == 17)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      servo01.write(servo1PPos);
      servo1PPos--;
      delay(speedDelay);
    }
    // Move servo 2
    while (m == 19)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      servo02.write(servo2PPos);
      servo2PPos++;
      delay(speedDelay);
    }
    while (m == 18)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      servo02.write(servo2PPos);
      servo2PPos--;
      delay(speedDelay);
    }
    // Move servo 3
    while (m == 20)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      servo03.write(servo3PPos);
      servo3PPos++;
      delay(speedDelay);
    }
    while (m == 21)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      servo03.write(servo3PPos);
      servo3PPos--;
      delay(speedDelay);
    }
    // Move servo 4
    while (m == 23)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      servo04.write(servo4PPos);
      servo4PPos++;
      delay(speedDelay);
    }
    while (m == 22)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      servo04.write(servo4PPos);
      servo4PPos--;
      delay(speedDelay);
    }
    // Move servo 5
    while (m == 25)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      servo05.write(servo5PPos);
      servo5PPos++;
      delay(speedDelay);
    }
    while (m == 24)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      servo05.write(servo5PPos);
      servo5PPos--;
      delay(speedDelay);
    }
    // Move servo 6
    while (m == 26)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      servo06.write(servo6PPos);
      servo6PPos++;
      delay(speedDelay);
    }
    while (m == 27)
    {
      if (Bluetooth.available() > 0)
      {
        m = Bluetooth.read();
      }
      servo06.write(servo6PPos);
      servo6PPos--;
      delay(speedDelay);
    }
  }
}
