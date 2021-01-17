#ifndef _EASY_BUTTON
#define _EASY_BUTTON

#include "Arduino.h" // include header file that defines INPU and HIGH

class EasyButton
{
private:
      int m_pin; //digital pin the button is connected to

      int m_debounce_MS; // number of miliseconds used to debounce

      unsigned long m_lastEventTime; // timestamp of the last event

      boolean m_currentState; // current state of the button

public:
      //constructor
      EasyButton();
      //helper method to set pin and number of milliseconds for debounce. Also sets pullup register
      void init(int pin, int debounce_milliseconds);

      //call this to see if the button is being pressed
      bool checkButtonPressed();

      //Use this method if millis() is disables. For example to increment counter in the main loop to generate time
      bool checkButtonPressed(unsigned long ticks);

};
#endif
