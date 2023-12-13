#include "LCDIC2.h"

LCDIC2 lcd(0x27, 16, 2);

const int numLeds = 10;
const int ledPins[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
const int pirPins[] = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

int numWhacksToWin = 20;  // Set the number of whacks needed to win the game
int whacksCounter = 0;   // Counter to keep track of whacks
int whacksLeft = 0; // Counts how man whacks are left in the game

// Strings for LCD printing
 
String whacksCounterString = String(whacksCounter);

int previousLedIndex = -1;

void setup() {
  lcd.begin();
  Serial.begin(9600);
  // Initialize LED pins as outputs
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Initialize PIR sensor pins as inputs
  for (int i = 0; i < numLeds; i++) {
    pinMode(pirPins[i], INPUT);
  }

  // Seed the random number generator with the current time
  randomSeed(millis());
  if (lcd.begin()) lcd.print("Calibrating...");
  delay(10000);
  if (lcd.begin()) lcd.print("Done!");
}

void loop() {
  // Check if the game is done
  if (whacksCounter >= numWhacksToWin) {
    // Game is done, you can add additional logic here if needed
    
    return;
  }

  // Generate a random LED index different from the previous one
  int randomLedIndex = generateRandomLedIndex();

  // Light up the random LED
  digitalWrite(ledPins[randomLedIndex], HIGH);
  delay(1000);
  // Wait for the player to "whack" the LED
  waitForWhack(pirPins[randomLedIndex]);

  // Turn off the LED
  digitalWrite(ledPins[randomLedIndex], LOW);


  // Update the previous LED index
  previousLedIndex = randomLedIndex;

  // Increment the whacks counter
  whacksCounter++;
  
  whacksLeft = numWhacksToWin - whacksCounter; 
  
  whacksCounterString = String(whacksLeft);
  
  lcd.setCursor(0, 1);
  lcd.print(whacksCounterString);
  
  
  
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
