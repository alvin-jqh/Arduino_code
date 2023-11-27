// this is compiling all the code into one project
#include "Encoder_funcs.h"

Wheels Robot(18,19,20,21);
float leftSpeed, rightSpeed;

void setup() {
    // put your setup code here, to run once:
    Robot.startTimer();   // start the clock

}

void loop() {
    // put your main code here, to run repeatedly:
    Robot.computeSpeeds();
    leftSpeed = Robot.getLeftSpeed(false);
    rightSpeed = Robot.getRightSpeed(false);
}
