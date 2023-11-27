#ifndef Encoder_funcs.h
#define Encoder_funcs.h

#include <Arduino.h>
#include <Encoder.h>

class Wheels
{
public:
    Wheels(int leftA, int leftB, int rightA, int rightB);    // initialisation
    ~Wheels();   //destructor

    float leftspeed(int unit); // return the speeds 
    float rightspeed(int unit);

    void resetEncoders();

private:
    void init(int leftA, int leftB, int rightA, int rightB);
    int leftA, leftB, rightA, rightB;
    long newLeft, newRight;
    long startLeft, startRight;
    
    const unsigned long deltaT; // sampling time period for speed in ms
    unsigned long startTime;
    const unsigned int countsperRev;    // same for L and R
}



#endif