#include "Motor_funcs.h"

void Motor::Motor(int directionPin, int pwmPin, int brakePin){
    pinMode(directionPin, OUOTPUT);
    pinMode(pwmPin, OUTPUT);
    pinMode(brakePin, OUTPUT);

    this->directionPin = directionPin;
    this->brakePin = brakePin;
    this->pwmPin = pwmPin;

    digitalWrite(brakePin, LOW);
}

void Motor::drive(double pwmValue){
    analogWrite(this->pwmPin, pwmValue);
}