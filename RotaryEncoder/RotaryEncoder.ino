#include "RotaryEncoder.h"

#define ENCODER_PIN_A 3
#define ENCODER_PIN_B 4
#define BUTTON_PRESS_PIN 18

RotaryEncoder encoder_1(ENCODER_PIN_A, ENCODER_PIN_B, BUTTON_PRESS_PIN);

void setup() {
      Serial.begin(9600);
      //attachInterrupt(ENCODER_PIN_A, encoderMoving, CHANGE);
      attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A), encoderMoving, CHANGE);
      attachInterrupt(digitalPinToInterrupt(BUTTON_PRESS_PIN), buttonPressed, FALLING);
}

void loop() {
/*us this if not using interrupt pins
encoder_1.currentOffset();
encoder_1.returnPosition();
*/   
}

void encoderMoving() {
      encoder_1.currentOffset();
}
void buttonPressed(){
      encoder_1.buttonPress();
}