#include "Motor_lib.h"

Motor_lib motor_BR; //two right motors
Motor_lib motor_AL; //two left motors
robot_lib myRobot;

char t;
uint8_t spd;
uint8_t controlSpeed;
void setup() {

  Serial.begin(9600);
  motor_AL.begin(6, 8, 9);
  motor_BR.begin(5, 4, 7);
//  motor_BR.begin(6, 8, 9);
//  motor_AL\.begin(5, 4, 7);
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

//  spd = map(spd, 1, 9, 50, 255);

}

void loop() {

  if(Serial.available()) 
  {
    t = Serial.read();
  }

  speedControl();
  speedLimit();
  //go forward
  if (t == 'F')
  { 
    motor_AL.forward(spd);
    motor_BR.forward(spd);
  }

  //forward + right
  else if(t == 'I')
  {
    motor_BR.forward(controlSpeed);
    motor_AL.forward(spd);
  }

  //go right
  else if(t == 'R')
  {
    motor_AL.forward(spd);
    motor_BR.stop();
  }

  //go left
  else if(t == 'L')
  {
    motor_BR.forward(spd);
    motor_AL.stop();
  }

  //forward + left
  else if(t == 'G')
  {
    motor_BR.forward(spd);
    motor_AL.forward(controlSpeed);
  }

  //go backward
  else if(t == 'B')
  {
    motor_AL.backward(spd);
    motor_BR.backward(spd);
  }

  //backward + left
  else if(t == 'H')
  {
    motor_BR.backward(spd);
    motor_AL.backward(controlSpeed);
  }

  //backward + right
  else if(t == 'J')
  {
    motor_BR.backward(controlSpeed);
    motor_AL.backward(spd);
  }

  //stop
  else if(t == 'S')
  {
    motor_AL.stop();
    motor_BR.stop();
  }
}

void speedControl(){
  
  if(t == '0'){
    spd = 0;
  }

  if(t == '1'){
    spd = 26;
  }

  if(t == '2'){
    spd = 51;
  }

  if(t == '3'){
    spd = 77;
  }

  if(t == '4'){
    spd = 102;
  }

  if(t == '5'){
    spd = 128;
  }

  if(t == '6'){
    spd = 153;
  }

  if(t == '7'){
    spd = 179;
  }

  if(t == '8'){
    spd = 204;
  }
  if(t == '9'){
    spd = 230;
  }
  if(t == 'q'){
    spd = 255;
  }
}

void speedLimit(){
  if(spd <= 100){
    controlSpeed = 0;
  }
  if(spd > 100 && spd <= 150){
    controlSpeed = spd - 50;
  }
  if(spd > 150 && spd <= 200){
    controlSpeed = spd - 80;
  }
  if(spd > 200 && spd <= 255){
    controlSpeed = spd - 110;
  }
}
