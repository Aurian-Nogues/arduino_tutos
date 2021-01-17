#include "easyButton.h"

EasyButton::EasyButton()
{
      //set default values
      m_lastEventTime = 0;
      m_pin = 0;
      m_debounce_MS = 200;
      m_currentState = false;

};

void EasyButton::init(int pin, int debounce_milliseconds)
{
      m_pin = pin;
      m_debounce_MS = debounce_milliseconds;
      pinMode(m_pin, INPUT_PULLUP);
}

bool EasyButton::checkButtonPressed()
{
      boolean state;
      if (digitalRead(m_pin) == LOW)
      {
            state = true;
      } else {
            state = false;
      }
      //see if the state has changed
      if (state != m_currentState)
      {
            //check if enough time passed since last button press
            if ((millis() - m_currentState) > m_debounce_MS)
            {
                  m_currentState = state
                  m_lastEventTime = millis()
            }
      }
      return m_currentState;
}
