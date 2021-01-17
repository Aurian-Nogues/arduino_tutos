#include "Button.h"

      Button::Button(byte pin) {
                        this->pin = pin;
                        lastReading = LOW;
                        init();
                        }

      void Button::init() {
                  pinMode(pin, INPUT_PULLUP); // INPUT is PULLUP so will be 1 if not connected and 0 if connected to ground
                  update();
                  }
      
      void Button::update() {
                  // You can handle the debounce of the button directly
                  // in the class, so you don't have to think about it
                  // elsewhere in your code
                  byte newReading = digitalRead(pin);


                  if (newReading != lastReading) {
                        lastDebounceTime = millis();
                  }
                  if (millis() - lastDebounceTime > debounceDelay) {
                        // Update the 'state' attribute only if debounce is checked
                        state = newReading;
                  }
                  lastReading = newReading;
            }
      
      byte Button::getState() {
                        update();
                        return state;
                  }
      
      bool Button::isPressed() {
                  //Pin is setup with a PULLUP resistance so when button is not pressed (floating input) the pin is getting 1
                  //button is connected to ground. When button is pressed, connection to ground is made and pin gets 0
            return (getState() == LOW);
            }
