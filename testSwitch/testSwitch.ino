const int switchPin = 2;

const int led_1 = 3;
const int led_2 = 4;
const int led_3 = 5;
const int wait_time = 200;

bool switchState;
bool lastSwitchState;

void setup() {
      pinMode(switchPin, INPUT_PULLUP);
      pinMode(led_1, OUTPUT);
      pinMode(led_2, OUTPUT);
      pinMode(led_3, OUTPUT);
      digitalWrite(led_1, LOW);
      digitalWrite(led_2, LOW);
      digitalWrite(led_3, LOW);

      Serial.begin(9600);
      lastSwitchState = !digitalRead(switchPin);

}

void loop() {
      switchState = !digitalRead(switchPin);
      Serial.println(digitalRead(switchState));
      if (switchState != lastSwitchState) {
            lastSwitchState = switchState;
      }

      if (lastSwitchState == 1) {
            delay(wait_time);
            digitalWrite(led_1, HIGH);
            delay(wait_time);
            digitalWrite(led_2, HIGH);
            delay(wait_time);
            digitalWrite(led_3, HIGH);
            delay(wait_time);
            digitalWrite(led_3, LOW);
            delay(wait_time);
            digitalWrite(led_2, LOW);
            delay(wait_time);
            digitalWrite(led_1, LOW);

      } else {
            digitalWrite(led_1, LOW);
            digitalWrite(led_2, LOW);
            digitalWrite(led_3, LOW);
      }
}






