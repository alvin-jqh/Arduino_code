// this is compiling all the code into one project
#include "Encoder_funcs.h"
#include "Motor_funcs.h"
#include <PID_v1.h>

Wheels Robot(18,19,20,21);
Motor LMotor(12,3,9);
volatile float leftSpeed, rightSpeed;
float setSpeeds[2];

double Kp = 15, Ki = 600, Kd = 0;
PID leftCTL();

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
