#ifndef Serial_comms_funcs_h
#define Serial_comms_funcs_h
#include <Arduino.h>

class Comms{
public:
    // constructor 
    Comms();
    // deconstructor
    ~Comms();

    // listen for new data basically combine everything
    void listen();

    // data storing function
    void recvWithStartEndMarkers();   

    // data conversion function
    void parseData();

    // display function in the serial 
    void showParsedData(); 

    // sends speed data
    void sendData(double measuredLeft, double measuredRight, bool proximity_flag);

    // returns the received data
    double getLeft();
    double getRight();

private:
    const byte numChars;
    char *receivedChars;
    char *tempChars;

    // checks if any newData has been received
    bool newData;

    // all received info will be stored in these variables
    char messageFromPC;
    double leftSpeed, rightSpeed;

};

#endif