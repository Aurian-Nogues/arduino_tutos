#include "RotaryEncoder.h"

      RotaryEncoder::RotaryEncoder(int pin_a, int pin_b, int pin_press = false, int debounce_ms = 50){
            this->pin_a = pin_a;
            this->pin_b = pin_b;
            if (pin_press != false) {
                this->pin_press = pin_press;
            }
            this-> debounce_ms = debounce_ms;
            init();
      }

      void RotaryEncoder::init(){
            pinMode(pin_a, INPUT_PULLUP);
            pinMode(pin_b, INPUT_PULLUP);
            if (pin_press != false){
            pinMode(pin_press, INPUT_PULLUP);
            }
      }

      int RotaryEncoder::currentOffset(){
            int pin_a_value = digitalRead(pin_a);
            int pin_b_value = digitalRead(pin_b);
                //Serial.print("A: ");
                //Serial.print(pin_a_value);
                //Serial.print("/ B: ");
                //Serial.println(pin_b_value);
            int offset  = 0;

            if (pin_a_value == 1 && previous_pin_a_value == 0){

                if (millis() - previous_event > debounce_ms){
                    if (pin_b_value == 0){
                        offset = 1;
                        
                    } else {
                        offset = -1;
                    }
                    previous_event = millis();
                }
            }
            previous_pin_a_value = pin_a_value;
            position = position + offset;
            return(offset);
      }

      int RotaryEncoder::returnPosition(){
            return position;
      }

