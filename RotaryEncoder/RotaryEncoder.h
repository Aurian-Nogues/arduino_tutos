#ifndef ROTARY_ENCODER
#define ROTARY_ENCODER

#include <Arduino.h>

class RotaryEncoder {
      private:
        int pin_a; //pin A needs to be an interrupt pin if you want to use interrupt routine shown in example (2,3,18,19,20,21 on mega 2560 chips)
        //otherwise you can always listen for change in loop
        int pin_b; // pin b doesn't need to be interrut as reading is triggered by pin_a CHANGE
        int pin_press; // same as pin a if needed to interrupt

        int previous_pin_a_value;

        unsigned long previous_event = 0;
        int turn_debounce_ms;
        int position;

        unsigned long last_press_event = 0;
        int press_debounce_ms;

        int max_value;
        int min_value;

      public:
            RotaryEncoder(int pin_a, int pin_b, int pin_press = 0, int turn_debounce_ms=50, int press_debounce_ms = 50, int position = 50, int min_value=0, int max_value = 100);
            void init();
            int currentOffset();
            int returnPosition();
            int buttonPress();
};

#endif
