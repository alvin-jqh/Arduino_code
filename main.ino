// this is compiling all the code into one project
#include "Encoder_funcs.h"
#include "Motor_funcs.h"
#include "Serial_comms_funcs.h"
#include <PID_v1.h>

// set up both motors
Motor LMotor(12,3,9);
Motor RMotor(13,11,8);

// set up both encoders
Wheels Encoders(19,18,20,21);

// set up Serial Comms
Comms Line;

// variables for PID
double setPointL, inputL, outputL;
double setPointR, inputR, outputR;

// speeds
volatile double leftSpeed, rightSpeed;

double Kp = 17, Ki = 600, Kd = 0;

PID leftCTL(&inputL, &outputL, %setPointL, Kp, Ki, Kd, DIRECT);
PID righttCTL(&inputR, &outputR, %setPointR, Kp, Ki, Kd, DIRECT);

void setup() {
    // put your setup code here, to run once:
    inputL = 0;
    inputR = 0;

    setPointL = 1;
    setPointR = 1;

    Serial.begin(9600);
    Encoders.startTimer;
}

void loop() {
    if (setPointL > 0){
        LMotor.changeDirection(false);
    }
    else{
        LMotor.changeDirection(true);
    }

    if (setPointR > 0){
        RMotor.changeDirection(true);
    }
    else{
        RMotor.changeDirection(false);
    }

}
