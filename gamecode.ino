#include "LCDIC2.h"

LCDIC2 lcd(0x27, 16, 2);

const int numLeds = 8;
const int ledPins[] = {22, 23, 24, 25, 26, 27, 30, 31};
const int pirPins[] = {32, 33, 34, 35, 36, 37, 40, 41};

int numWhacksToWin = 20;  // Set the number of whacks needed to win the game
int whacksCounter = 0;   // Counter to keep track of whacks
int whacksLeft = 0; // Counts how man whacks are left in the game
int savedTimeValue = 0;
int finalTime = 0;
int finalTimeCalc = 0;
int finalTime1 = 0;

// Strings for LCD printing
String finalTimeString = String(millis());
String whacksCounterString = String(whacksCounter);

int previousLedIndex = -1;

void setup() {
  lcd.begin();
  Serial.begin(9600);
  // Initialize LED pins as outputs
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(29, OUTPUT);
  pinMode(28, OUTPUT);
  // Initialize PIR sensor pins as inputs
  for (int i = 0; i < numLeds; i++) {
    pinMode(pirPins[i], INPUT);
  }

    pinMode(11, OUTPUT);

  // Seed the random number generator with the current time
  randomSeed(millis());
  if (lcd.begin()) lcd.print("Getting ready");
  delay(2000);
  allOn();
  beep();
  delay(500);
  allOff();
  delay(500);
  allOn();
  beep();
  delay(500);
  allOff();
  delay(500);
  allOn();
  beep();
  delay(500);
  allOff();

  savedTimeValue = millis() / 1000;
  Serial.print(savedTimeValue);
}

void loop() {
  // Check if the game is done
  if (whacksCounter >= numWhacksToWin) {
    // Game is done, you can add additional logic here if needed
    if (whacksCounter == numWhacksToWin) {

      Serial.print(millis());
      finalTime = millis() / 1000;


      finalTimeCalc = finalTime - savedTimeValue;
      finalTimeString = String(finalTimeCalc);


      Serial.print(finalTimeCalc);
      lcd.setCursor (0, 0);
      lcd.print("Your time is");
      lcd.setCursor (0, 1);
      lcd.print(finalTimeString);

      for (int i = 0; i < 3; i++) {
    beep();
    delay(200);
  }
      whacksCounter++;
    } else {
      return;
    }
    return;
  }
  whacksLeft = numWhacksToWin - whacksCounter;
  whacksCounterString = String(whacksLeft);
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("Lights Left:");
  lcd.setCursor(0, 1);
  lcd.print(whacksCounterString);

  // Generate a random LED index different from the previous one
  int randomLedIndex = generateRandomLedIndex();

  // Light up the random LED
  digitalWrite(ledPins[randomLedIndex], HIGH);
  delay(750);
  // Wait for the player to "whack" the LED
  waitForWhack(pirPins[randomLedIndex]);

  // Turn off the LED
  digitalWrite(ledPins[randomLedIndex], LOW);


  // Update the previous LED index
  previousLedIndex = randomLedIndex;

  // Increment the whacks counter
  whacksCounter++;
  
  beep();

  // Delay before the next round
  delay(100);
}

int generateRandomLedIndex() {
  int randomIndex;
  do {
    randomIndex = random(0, numLeds);
  } while (randomIndex == previousLedIndex);

  return randomIndex;
}

void waitForWhack(int pirPin) {
  // Wait for the PIR sensor to be triggered
  while (digitalRead(pirPin) == LOW) {
    // You can add additional logic or actions while waiting if needed
  }
  
  // You can add additional logic or actions after the PIR sensor is triggered
}

void allOn(){
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(29, HIGH);
    digitalWrite(28, HIGH);
  }
}

void allOff(){
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
    digitalWrite(29, LOW);
    digitalWrite(28, LOW);
  }
}

void beep(){
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
}
