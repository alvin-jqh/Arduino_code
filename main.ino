// this is compiling all the code into one project
#include "Encoder_funcs.h"

    Wheels Robot(18,19,20,21);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Robot.startTimer();   // start the clock

}

void loop() {
    // put your main code here, to run repeatedly:
    float* speeds = Robot.speed(0);

    Serial.print("Left: ");
    Serial.print(speeds[0]);
    Serial.print(" Right: ");
    Serial.println(speeds[1]);
}
