//This code is simply for testing the LED functionality. If working properly each LED will light up in order 1-10 

const int ledPins[] = {22, 23, 24, 25, 26, 27, 29, 28, 30, 31};
const int numLeds = 10;


void setup() {
   for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

   for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
