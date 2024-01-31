// this is compiling all the code into one project
#include "Encoder_funcs.h"
#include "Motor_funcs.h"
#include "Serial_comms_funcs.h"
#include <PID_v1.h>

// set up both motors
Motor LMotor(12,3,9);
Motor RMotor(13,11,8);

// set up both encoders
Wheels Encoders(18,19,20,21);

// set up Serial Comms
Comms Line;

// variables for PID
double setPointL, inputL, outputL;
double setPointR, inputR, outputR;

// speeds
volatile double leftSpeed, rightSpeed;

double Kp = 17, Ki = 600, Kd = 0;

PID leftCTL(&inputL, &outputL, &setPointL, Kp, Ki, Kd, DIRECT);
PID rightCTL(&inputR, &outputR, &setPointR, Kp, Ki, Kd, DIRECT);

void setup() {
    // put your setup code here, to run once:
    inputL = 0;
    inputR = 0;

    setPointL = 0;
    setPointR = 0;

    leftCTL.SetMode(AUTOMATIC);
    rightCTL.SetMode(AUTOMATIC);
    
    leftCTL.SetSampleTime(5);

    rightCTL.SetSampleTime(5);

    Serial.begin(9600);
    Encoders.startTimer();
}

void loop() {
    Line.listen();

    // if a new speed is received update the set points
    if (setPointL != Line.getLeft() || setPointR != Line.getRight()){
        setPointL = Line.getLeft();
        setPointR = Line.getRight();
    }

    // direction switching
    if (setPointL > 0){
        LMotor.changeDirection(true);
        leftCTL.SetControllerDirection(DIRECT);
    }
    else{
        LMotor.changeDirection(false);
        leftCTL.SetControllerDirection(REVERSE);
    }

    if (setPointR > 0){
        RMotor.changeDirection(true);
        rightCTL.SetControllerDirection(DIRECT);
    }
    else{
        RMotor.changeDirection(false);
        rightCTL.SetControllerDirection(REVERSE);
    }

    // read the speeds from the encoders
    Encoders.computeSpeeds();
    leftSpeed = Encoders.getLeftSpeed(true);
    rightSpeed = Encoders.getRightSpeed(true);
    Serial.print("Left ");
    Serial.print(leftSpeed);
    Serial.print("  Right ");
    Serial.println(rightSpeed);

    // changing the pwm value to drive the motors to desired speed
    inputL = leftSpeed;
    inputR = rightSpeed;

    leftCTL.Compute();
    rightCTL.Compute();

    LMotor.drive(outputL);
    RMotor.drive(outputR);
    
}
