
#include "RotaryEncoder.h"

int RotaryEncoder::trackShaftPosition()
{ 
      boolean pinAValue = digitalRead(m_pinA);
      unsigned long current_time = millis();
      unsigned long time_between_events = current_time - m_lastEventTime;

      if ((m_encoderALast==HIGH) && (pinAValue == LOW) && time_between_events > m_debounceMS)
      {
            if (digitalRead(m_pinB)==LOW)
            {
                  if (m_encoderPosition > m_encoderMin){
                        m_encoderPosition--;
                  } 
            } else {
                  if (m_encoderPosition < m_encoderMax){
                        m_encoderPosition++;
                  }
            }

            m_lastEventTime=current_time;
      }
      m_encoderALast = pinAValue;
      return m_encoderPosition;

}