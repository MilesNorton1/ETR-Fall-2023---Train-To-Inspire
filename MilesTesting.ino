#include "LCDIC2.h"

LCDIC2 lcd(0x27, 16, 2);

const int numLeds = 3;
const int ledPins[] = {2, 3, 4};
const int pirPins[] = {5, 6, 7};

int numWhacksToWin = 20;  // Set the number of whacks needed to win the game
int whacksCounter = 0;   // Counter to keep track of whacks
//int whacksLeft = numWhacksToWin - whacksCounter; 


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

  delay(10000);
  Serial.print("Sensors Calibrated");
}

void loop() {
  
  // Check if the game is done
  if (whacksCounter >= numWhacksToWin) {
    // Game is done, you can add additional logic here if needed
    
    whacksCounter ++;
    return;
  }

  // Generate a random LED index different from the previous one
  int randomLedIndex = generateRandomLedIndex();

  // Light up the random LED
  digitalWrite(ledPins[randomLedIndex], HIGH);
  delay(1000);
  // Wait for the player to "whack" the LED
  waitForWhack(pirPins[randomLedIndex]);

  Serial.print(randomLedIndex);

  // Turn off the LED
  digitalWrite(ledPins[randomLedIndex], LOW);

  // Update the previous LED index
  previousLedIndex = randomLedIndex;

  // Increment the whacks counter
  whacksCounter++;

  lcd.setCursor(0, 1);
  if (lcd.begin()) lcd.print(whacksCounter);
  
  //whacksLeft = numWhacksToWin - whacksCounter; 
  
  // Delay before the next roundlcd.setCursor(i, 1);
  delay(1000);
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
