#include "Motor_lib.h"

Motor_lib motor_BR;
Motor_lib motor_AL;
robot_lib myRobot;

void setup(){
    motor_AL.begin(6,9,8);
    motor_BR.begin(5,7,4);
    myRobot.begin(&motor_AL, &motor_BR);

    // motor_AL.forward(255);
    // motor_BR.forward(255);

    // delay(1000);

    // motor_AL.backward(255);
    // motor_BR.backward(255);

    // delay(1000);

    myRobot.setTimeRun(200);    //(ms) set time run for robot, over time robot will stop

    myRobot.forward(255,255);
    delay(2000);

    myRobot.turnLeft(255,255);
    delay(2000);

    myRobot.turnRight(255,255);
    delay(2000);

    myRobot.backward(255,255);
    delay(2000);
      
}

void loop(){

    myRobot.checkStop();
    
}