

class RotaryEncoder {
    private:
        int pin_a;
        int pin_b;
        int pin_press;
    public:
        RotaryEncoder(int pin_a, int pin_b, int pin_press = false){
            this->pin_a = pin_a;
            this->pin_b = pin_b;
            if (pin_press != false) {
                this->pin_press = pin_press;
            }
            init();
        }

        void init() {
            pinMode(pin_a, INPUT_PULLUP);
            pinMode(pin_b, INPUT_PULLUP);
            if (pin_press != false){
                pinMode(pin_press, INPUT_PULLUP);
            }
        }

        void currentOffset(){
            Serial.print("A: ");
            Serial.print(digitalRead(pin_a));
            Serial.print("/ B: ");
            Serial.println(digitalRead(pin_b));

        }

};

#define ENCODER_PIN_A 3
#define ENCODER_PIN_B 4

#include <Arduino.h>

RotaryEncoder encoder_1(ENCODER_PIN_A, ENCODER_PIN_B);

void setup() {
      Serial.begin(9600);
}

void loop() {
    Serial.println(ENCODER_PIN_A);
    //encoder_1.currentOffset();
}