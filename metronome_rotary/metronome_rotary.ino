
//speaker
const int speakerPin = 9;
const int frequency = 500;
const int duration = 50;
//tempo control
int encoderPinbA = 2;
int encoderPinbB = 3;
int encoderPinbC = 4; // button press

boolean encoder_a_last_value = HIGH;
boolean encoder_b_last_value = HIGH;
boolean encoder_c_last_value = HIGH;


//tempo calculations
unsigned int ms_per_beat = 0;
unsigned int bpm = 60;
unsigned int ms_per_minute = 1000 * 60;

//delay
long current_time;
long last_beat = 0;

void setup() {
    //calculate the amount of delay: ms per minute / bpm
    ms_per_beat =  ms_per_minute /  bpm;
    Serial.begin(9600);

    pinMode(encoderPinbA, INPUT_PULLUP);
    pinMode(encoderPinbA, INPUT_PULLUP);
    pinMode(encoderPinbA, INPUT_PULLUP);
  }

void loop() {

      //clockwise B goes from 1 to 0
      //anti clockwise A goes from 1 to 0
      //C is 1 when released and 0 when pressed

      //check if bpm was changed by encoder
      int result = read_encoder();
    
      if (result != 0){
          bpm += result;
          ms_per_beat = ms_per_minute / bpm;
          Serial.println(bpm);
      }

      current_time = millis();
      if (current_time - last_beat >= ms_per_beat) {
        tone(speakerPin, frequency, duration);
        last_beat = current_time;
      }
  }

int read_encoder(){
    int result = 0;
    boolean encoder_a_value = digitalRead(encoderPinbA);
    boolean encoder_b_value = digitalRead(encoderPinbB);
    boolean encoder_c_value = digitalRead(encoderPinbB);

  
    if (encoder_a_value != encoder_a_last_value){
        if ((encoder_a_value == LOW) && encoder_b_value == HIGH){
            result = -1;
          }
        }

    if (encoder_b_value != encoder_b_last_value){
        if ((encoder_b_value == LOW) && encoder_a_value == HIGH){
          result = 1;
        }
      }

    encoder_a_last_value = encoder_a_value;
    encoder_b_last_value = encoder_b_value;

    return (result);
  }