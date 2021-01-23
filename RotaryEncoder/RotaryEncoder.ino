#include "RotaryEncoder.h"

#define ENCODER_PIN_A 3
#define ENCODER_PIN_B 4

RotaryEncoder encoder_1(ENCODER_PIN_A, ENCODER_PIN_B);

void setup() {
      Serial.begin(9600);
      
}

void loop() {

    int previous_position = encoder_1.returnPosition();
    encoder_1.currentOffset();
    int current_position = encoder_1.returnPosition();
    if (current_position != previous_position){
        Serial.println(current_position);
    }
    
}