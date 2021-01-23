#include "RotaryEncoder.h"

      RotaryEncoder::RotaryEncoder(int pin_a, int pin_b, int pin_press, int turn_debounce_ms,int press_debounce_ms, int position, int min_value, int max_value){
            this->pin_a = pin_a;
            this->pin_b = pin_b;
            if (pin_press != false) {
                this->pin_press = pin_press;
            }
            this-> turn_debounce_ms = turn_debounce_ms;
            this -> press_debounce_ms = press_debounce_ms;
            this -> position = position;
            this -> min_value = min_value;
            this -> max_value = max_value;

            
            init();
      }

      void RotaryEncoder::init(){
            pinMode(pin_a, INPUT_PULLUP);
            pinMode(pin_b, INPUT_PULLUP);
            if (pin_press != 0){
                  pinMode(pin_press, INPUT_PULLUP);
            }
            previous_pin_a_value = digitalRead(pin_a);
      }

      int RotaryEncoder::currentOffset(){
            int pin_a_value = digitalRead(pin_a);
                //Serial.print("A: ");
                //Serial.print(pin_a_value);
                //Serial.print("/ B: ");
                //Serial.println(pin_b_value);

            unsigned long time_between_events = millis() - previous_event;

            if ((pin_a_value == previous_pin_a_value) && (time_between_events > turn_debounce_ms)){
                  int pin_b_value = digitalRead(pin_b);
                  if (pin_a_value != pin_b_value) {
                        if (position < max_value){
                              position++;
                        }
                  } else {
                        if (position > min_value){
                              position--;
                        }
                  }
                  previous_pin_a_value = pin_a_value;
                  previous_event = millis();
                  Serial.println(position);
            }
      }
      
      int RotaryEncoder::buttonPress(){
            unsigned long time_between_presses = millis() - last_press_event;
            if (time_between_presses > press_debounce_ms){
                  Serial.println("Pressed");
                  last_press_event = millis();
            }
            
      }

      int RotaryEncoder::returnPosition(){
            return position;
      }

