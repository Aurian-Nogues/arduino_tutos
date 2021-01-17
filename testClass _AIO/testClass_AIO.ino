class Led {
      private:
            int pin;
      public:
            Led(int pin){
                  //use -> to make the difference between "pin" attribute of class and local variable pin created from parameter
                  this->pin = pin;
                  init();
            }

            void init() {
                  pinMode(pin, OUTPUT);
                  off();
            };

            void on() {
                  digitalWrite(pin, HIGH);
            }

            void off() {
                  digitalWrite(pin, LOW);
            }
};

class Button {
      private:
            byte pin;
            byte state;
            byte lastReading;
            unsigned long lastDebounceTime = 0;
            unsigned long debounceDelay = 50;
      public:
            Button(byte pin) {
                  this->pin = pin;
                  lastReading = LOW;
                  init();
                  }

            void init() {
                  pinMode(pin, INPUT_PULLUP); // INPUT is PULLUP so will be 1 if not connected and 0 if connected to ground
                  update();
                  }

            void update() {
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
            byte getState() {
                  update();
                  return state;
            }

            bool isPressed() {
                  //Pin is setup with a PULLUP resistance so when button is not pressed (floating input) the pin is getting 1
                  //button is connected to ground. When button is pressed, connection to ground is made and pin gets 0
            return (getState() == LOW);
            }
};

//start work
#define LED_1_PIN 9
#define LED_2_PIN 10
#define LED_3_PIN 11
#define LED_4_PIN 12

#define BUTTON_PIN 5

Led led1(LED_1_PIN);
Led led2(LED_2_PIN);
Led led3(LED_3_PIN);
Led led4(LED_4_PIN);

Button button1(BUTTON_PIN);

void setup() {
      Serial.begin(9600);
}

void loop() {
      if (button1.isPressed()){
            led1.on();
            led2.off();
            led3.on();
            led4.off();
      } else {
            led1.off();
            led2.on();
            led3.off();
            led4.on();
      }
}


