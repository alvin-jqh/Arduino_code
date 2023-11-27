#ifndef Encoder_funcs_h
#define Encoder_funcs_h

#include <Arduino.h>
#include <math.h>
#include <Encoder.h>

class Wheels
{
public:
    Wheels(int leftA, int leftB, int rightA, int rightB);    // initialisation
    ~Wheels();   //destructor

    float leftspeed(int unit); // return the speeds 
    float rightspeed(int unit);


private:
    void init(int leftA, int leftB, int rightA, int rightB);
    long newLeft, newRight;
    long startLeft, startRight;

    Encoder LeftEncoder;
    Encoder RightEncoder;
    
    unsigned long deltaT; // sampling time period for speed in ms
    unsigned long startTime;
    unsigned int countsperRev;    // same for L and R
}



#endif