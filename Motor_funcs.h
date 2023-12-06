#ifndef Motor_funcs_h
#define Motor_funcs_h
#include <Arduino.h>

class Motor
{
public:
    // intialise with 3 control pins for the motor shield
    Motor(int directionPin, int pwmPin, int brakePin);

    void drive(double pwmvalue);
    void changeDirection(bool direction);

private:
    int directionPin, pwmPin, brakePin;

};

#endif