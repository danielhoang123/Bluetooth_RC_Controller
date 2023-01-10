#include "Motor_lib.h"

Motor_lib motor_BR; //two right motors
Motor_lib motor_AL; //two left motors
robot_lib myRobot;

char t;

void setup() {

  Serial.begin(9600);
  motor_AL.begin(6, 8, 9);
  motor_BR.begin(5, 4, 7);
  //myRobot.begin(&motor_AL, &motor_BR);

  // motor_AL.forward(255);
  // motor_BR.forward(255);

  // delay(1000);

  // motor_AL.backward(255);
  // motor_BR.backward(255);

  // delay(1000);

  // myRobot.setTimeRun(200);    //(ms) set time run for robot, over time robot will stop

  // myRobot.forward(255, 255);
  // delay(2000);

  // myRobot.turnLeft(255, 255);
  // delay(2000);

  // myRobot.turnRight(255, 255);
  // delay(2000);

  // myRobot.backward(255, 255);
  // delay(2000);

  

}

void loop() {

  if(Serial.available()) 
  {
    t = Serial.read();
  }

  //go forward
  if (t == 'F')
  { 
    motor_AL.forward(255);
    motor_BR.forward(255);
  }

  //forward + right
  else if(t == 'I')
  {
    motor_AL.forward(110);
    motor_BR.forward(255);
  }

  //go right
  else if(t == 'R')
  {
    motor_BR.forward(255);
    motor_AL.stop();
  }

  //go left
  else if(t == 'L')
  {
    motor_AL.forward(255);
    motor_BR.stop();
  }

  //forward + left
  else if(t == 'G')
  {
    motor_AL.forward(255);
    motor_BR.forward(110);
  }

  //go backward
  else if(t == 'B')
  {
    motor_AL.backward(255);
    motor_BR.backward(255);
  }

  //backward + left
  else if(t == 'H')
  {
    motor_AL.backward(255);
    motor_BR.backward(110);
  }

  //backward + right
  else if(t == 'J')
  {
    motor_AL.backward(110);
    motor_BR.backward(255);
  }

  //stop
  else if(t == 'S')
  {
    motor_AL.stop();
    motor_BR.stop();
  }
}
