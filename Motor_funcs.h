#ifndef Motor_funcs_h
#define Motor_funcs_h
#include <Arduino.h>

class Motor
{
public:
    Motor(int directionPin, int pwmPin, int brakePin);

    void drive(double pwmvalue);
    void changeDirection(bool direction);

private:
    int directionPin, pwmPin, brakePin;

};

#endif