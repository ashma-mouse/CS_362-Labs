// Ashma Koirala
// CS 362 - Lab 1
// University of Illinois at Chicago 

// Link to the youtube video: https://youtu.be/1oLToBEDgEo

unsigned long previous = 0;
const long timeGap = 1000;

const int onboard = LED_BUILTIN;  // onboard LED
const int red = 11; // LED to pin 11
const int green = 10; // LED to pin 10

int onboardState = LOW; // state for onboard LED
int redState = LOW; // state for red LED
int greenState = LOW; // state for green LED

void setup() {
  pinMode(onboard, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  unsigned long ms = millis();

  if (ms - previous >= timeGap) {
    previous = ms;
    if (onboardState == LOW) {
      onboardState = HIGH;
      digitalWrite(onboard, onboardState);
    }
    else if (onboardState == HIGH) {
      onboardState = LOW;
      digitalWrite (onboard, onboardState);
    }

    if (redState == LOW && onboardState == LOW){
      redState = HIGH;
      onboardState = HIGH; 
      digitalWrite(red, redState);
    }
    else if ( redState == HIGH) {
      redState = LOW;
      digitalWrite (red, redState);
    }

    if (greenState == LOW && redState == LOW && onboardState == LOW) { // if all led are at LOW : prevents green LED to blink with onboard LED
      greenState = HIGH; 
       onboardState = LOW; //new
      digitalWrite (green, greenState);
    }
    else if(greenState = HIGH) {
      greenState = LOW;
      digitalWrite(green, greenState);
    }
  }
}
