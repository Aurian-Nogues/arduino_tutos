
//speaker
const int speakerPin = 9;
const int frequency = 500;
const int duration = 50;
//tempo control
const int potPin = 0;
int potValue;
//on-off button
const int buttonPin = 2;
boolean metronomeOn = false;

//tempo calculations
unsigned int ms_per_beat = 0;
unsigned int bpm = 60;
unsigned int ms_per_minute = 1000 * 60;

//Interrupt Service Routine
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


      

    if (metronomeOn == true){
      tone(speakerPin, frequency, duration);
      Serial.print(bpm);
      Serial.println(" bpm");
      
      } else {
        Serial.println("Metronome is off, press button to turn on");
      }

      delay(ms_per_beat);
    }
