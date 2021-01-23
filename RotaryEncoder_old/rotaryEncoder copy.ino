//Arduino for Musicians
//RotaryEncoder test

#include "RotaryEncoder.h"

//Constants for digital pins and encoder parameters
const int pinA = 3;
const int pinB = 4;
const int debounceTime = 40;

//Variable to track the position of the shaft
int lastShaftPosition = 0;


//Create an instance of the CRotaryEncoder class
RotaryEncoder encoder;

void setup()
{   
    //Initialize the encoder with pin numbers and a debounce 
    //time. Starting position = 50, range 1-100
    encoder.init(pinA, pinB, debounceTime, 50, 1, 100); 
}

void loop()
{
    //Read the position of the encoder
    int pos = encoder.trackShaftPosition();
  
    //Print the position if it has changed
    if(pos != lastShaftPosition)
    {
         lastShaftPosition = pos; 
    }
}