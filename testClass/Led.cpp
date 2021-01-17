#include "Led.h"

Led::Led(int pin){
                  //use -> to make the difference between "pin" attribute of class and local variable pin created from parameter
                  this->pin = pin;
                  init();
            }

void Led::init() {
                  pinMode(pin, OUTPUT);
                  off();
            };
void Led::on() {
                  digitalWrite(pin, HIGH);
            }
void Led::off() {
                  digitalWrite(pin, LOW);
            }


