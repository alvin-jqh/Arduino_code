// this is compiling all the code into one project
#include "Encoder_funcs.h"
#include "Motor_funcs.h"
#include <PID_v1.h>

Motor LMotor(12,3,9);
Motor RMotor(13,11,8);

bool direction;
void setup() {
    // put your setup code here, to run once:

}

void loop() {
    if (direction){
        LMotor.changeDirection(true);
        RMotor.changeDirection(false);
    }
    else{
        LMotor.changeDirection(false);
        RMotor.changeDirection(true);
    }
    LMotor.drive(100);
    RMotor.drive(100);
    
    delay(2000);
    
    direction = !direction;
}
