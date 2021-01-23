#ifndef _ROTARYENCODER
#define _ROTARYENCODER

#include <Arduino.h>

class RotaryEncoder
{
      private:
            int m_pinA; //Digital pin encoder A (CLK)
            int m_encoderALast;
            int m_pinB; // Digital pin encoder B (DT)
            int m_debounceMS; //number of miliseconds debouncing

            unsigned long m_lastEventTime; // timestamp of last event
            int m_encoderPosition; //current encoder position
            int m_encoderMax; //Max value of encoder
            int m_encoderMin; // min value of encoder

      public:
            //Constructor
            RotaryEncoder();
            
            void init(int pinA, int pinB, int debounce_milliseconds,
                  int start_position = 0, int min_position = 0, int max_position = 100) ;

            //setters and getters
            void setShaftPosition (int position);
            void setMinValue(int min);
            void setMaxValue(int max);

            //returns value of m_encoderPosition--use trackShaftPosition() to track changes
            int shaftPosition();

            //call this in main loop to track positiion
            int trackShaftPosition();

            //Use this to track shaft position is millis is disables
            int trackShaftPosition(unsigned long ticks);
};
#endif