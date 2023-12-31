#include "Motor_funcs.h"

Motor::Motor(int directionPin, int pwmPin, int brakePin){
    pinMode(directionPin, OUTPUT);
    pinMode(pwmPin, OUTPUT);
    pinMode(brakePin, OUTPUT);

    this->directionPin = directionPin;
    this->brakePin = brakePin;
    this->pwmPin = pwmPin;

    digitalWrite(brakePin, LOW);
}

// enter PWM value
void Motor::drive(double pwmValue){
    analogWrite(this->pwmPin, pwmValue);
}

// true is high, false is low
void Motor::changeDirection(bool direction){
    if (direction){
        digitalWrite(this->directionPin, HIGH); // direction really depends on left or right wheel
    }
    else{
        digitalWrite(this->directionPin, LOW);
    }
}