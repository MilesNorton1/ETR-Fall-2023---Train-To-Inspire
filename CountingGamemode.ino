#include "LCDIC2.h"

LCDIC2 lcd(0x27, 16, 2);

const int numLeds = 10;
const int ledPins[] = {22, 23, 24, 25, 26, 27, 29, 28, 30, 31};  
const int pirPins[] = {38, 39, 40, 41, 42, 43, 44, 45, 46, 47};

int numWhacksToWin = 20;  // Set the number of whacks needed to win the game
int whacksCounter = 0;   // Counter to keep track of whacks
int whacksLeft = 0; // Counts how many whacks are left in the game
int savedTimeValue = 0; // Saves time at the beginning of the games
int finalTime = 0; // Time at the end of the game
int finalTimeCalc = 0; // 
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
  // Initialize PIR sensor pins as inputs
  for (int i = 0; i < numLeds; i++) {
    pinMode(pirPins[i], INPUT);
  }

    pinMode(11, OUTPUT); // initalize speaker

  // Seed the random number generator with the current time
  randomSeed(millis());
  if (lcd.begin()) lcd.print("Getting ready");
  

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


      //finalTimeCalc = finalTime - savedTimeValue;
      
      finalTimeString = String(finalTime - savedTimeValue);


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

void startupSequence(){
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
}


void allOn(){
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH); 
  }
}

void allOff(){
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void beep(){
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
}
