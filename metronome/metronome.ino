

const int speakerPin = 9;
const int frequency = 500;
const int duration = 50;
const int potPin = 0;
const int buttonPin = 2;
int last_state = 0;
int potValue;
boolean metronomeOn = false;

unsigned int ms_per_beat = 0;
unsigned int bpm = 60;
unsigned int ms_per_minute = 1000 * 60;

void buttonPress() {
    metronomeOn = !metronomeOn;
    Serial.println("Pressed the button");
  }

void setup() {
    //calculate the amount of delay: ms per minute / bpm

    ms_per_beat =  ms_per_minute /  bpm;
    Serial.begin(9600);

    pinMode(buttonPin, INPUT_PULLUP); // initialize button as input
    attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPress, FALLING ); // button press will interrupt loop

  }


void loop() {

    //check status of potentionmeter
    int potCurrent_value = analogRead(potPin);

    if (potCurrent_value != potValue){
      //map pot value (1-1023 on 5v) to metronome value (30 to 350 bpm)
      bpm = map(potCurrent_value, 0, 1023, 30, 350);
      //recalculate delay time
      ms_per_beat = ms_per_minute / bpm;
      potValue = potCurrent_value ;
      }


      
    Serial.println(bpm);
    if (metronomeOn == true){
      tone(speakerPin, frequency, duration);
      delay(ms_per_beat);
      }
    }
