#ifndef ROTARY_ENCODER
#define ROTARY_ENCODER

#include <Arduino.h>

class RotaryEncoder {
      private:
        int pin_a;
        int pin_b;
        int pin_press = false;

        int previous_pin_a_value = 1;

        unsigned long previous_event = 0;
        int debounce_ms;
        int position = 50;

      public:
            RotaryEncoder(int pin_a, int pin_b, int pin_press = false, int debounce_ms = 50);
            void init();
            int currentOffset();
            int returnPosition();
};

#endif
