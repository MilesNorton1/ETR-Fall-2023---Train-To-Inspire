#include <Wire.h>

#include "LCDIC2.h"

LCDIC2 lcd(0x27, 16, 2);
const int button1Pin = A0;
const int button2Pin = A1;
const int button3Pin = A2;
const int button4Pin = A3;
int gameModeHolder = 0;
int timeTrialHolder = 0;
int countingHolder = 0;
int gameModeI = 0;
int timeTrialI = 0;
int countingI = 0;
int customTimeTrialTimeI = 0;
int customCountingNamesI = 0;
char *gameModeNames[] = {"Time Trial", "Counting"};
char *timeTrialNames[] = {"Easy", "Normal", "Hard", "Custom"};
char *customTimeTrialTime[] = {"10", "20", "30", "40", "50", "60"};
char *countingNames[] = {"Easy", "Normal", "Hard", "Custom"};
int customCountingNames[] = {10, 20, 30, 40, 50};

const int numLeds = 8;
const int ledPins[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
const int pirPins[] = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

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
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);
  lcd.begin();
  lcd.print("    WELCOME!");
  delay(3000);
}

void loop() {
  start();
  gameMode();
  lcd.clear();
  lcd.print("Hello");
  if (gameModeI == 0){
    lcd.clear();
    timeTrial();
  } else if(gameModeI == 1){
    lcd.clear();
    counting();
    numWhacksToWin = customCountingNames[customCountingNamesI] ;
    lcd.clear();
    countingGo();
    countingStart();
  }
}

void start(){
  
    lcd.clear();
    lcd.print("  Select Mode  ");
    lcd.setCursor(0,1) ; //sets cursor to second line first row
    lcd.print("   Time Trial  ");
  
}

void gameMode() {
    while(gameModeHolder == 0){
    
        if(digitalRead(button3Pin) == LOW){
          gameModeHolder = 1;
          delay(100);
        } else if (digitalRead(button4Pin) == LOW) {
            if(gameModeI == 1){
              lcd.clear();
              gameModeI = 1;
              lcd.print("Select Mode  ");
              lcd.setCursor(0,1) ; //sets cursor to second line first row
              lcd.print(gameModeNames[gameModeI]);
              lcd.print("        .");
            
            }
            else{
              delay(200);
              lcd.clear();
              gameModeI = gameModeI+1;
              lcd.print("Select Mode  ");
              lcd.setCursor(0,1) ; //sets cursor to second line first row
              lcd.print(gameModeNames[gameModeI]);
              lcd.print("        .");
            }

        } else if (digitalRead(button2Pin) == LOW) {
            gameModeHolder = 0;
            if(gameModeI == 0){
              delay(200);
              lcd.clear();
              gameModeI = gameModeI;
              lcd.print("Select Mode  ");
              lcd.setCursor(0,1) ; //sets cursor to second line first row
              lcd.print(gameModeNames[gameModeI]);
              lcd.print("      .");
            }
            else{
              delay(200);
              lcd.clear();
              gameModeI = gameModeI-1;
              lcd.print("Select Mode  ");
              lcd.setCursor(0,1) ; //sets cursor to second line first row
              lcd.print(gameModeNames[gameModeI]);
              lcd.print("        .");
            }
            lcd.print(gameModeNames[gameModeI]);
            lcd.print("       .");
        }

    }
  }

void timeTrial() {
  lcd.clear(); 
  timeTrialI = timeTrialI;
  lcd.print("  Select Settings  ");
  lcd.setCursor(0,1) ; //sets cursor to second line first row
  lcd.print(timeTrialNames[timeTrialI]);
  delay(500);
  while(digitalRead(button3Pin) == HIGH){
    delay(100);
    if (digitalRead(button3Pin) == LOW){
      timeTrialHolder = timeTrialHolder + 1;
    }
    while (timeTrialHolder == 1) {
      if (timeTrialI == 3){
        lcd.clear();
        customTimeTrial();
      }
    }
    if (digitalRead(button4Pin) == LOW) {
      if(timeTrialI == 3){
        delay(200);
        lcd.clear(); 
        timeTrialI = timeTrialI;
        lcd.print("  Select Settings  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(timeTrialNames[timeTrialI]);
      }
      else{
        delay(200);
        lcd.clear();
        timeTrialI = timeTrialI+1;
        lcd.print("  Select Settings  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(timeTrialNames[timeTrialI]);
      }
    }
    if (digitalRead(button2Pin) == LOW) {
      if(timeTrialI == 0){
        delay(200);
        lcd.clear();
        timeTrialI = timeTrialI;
        lcd.print("  Select Settings  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(timeTrialNames[timeTrialI]);
      }
      else{
        delay(200);
        lcd.clear();
        timeTrialI = timeTrialI-1;
        lcd.print("  Select Settings  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(timeTrialNames[timeTrialI]);
      }
    }
  }
  if (timeTrialHolder == 1) {
      if (timeTrialI == 3){
        delay(200);
        lcd.clear();
        customTimeTrial();
      }
    }
}
void customTimeTrial() {
  lcd.clear(); 
  timeTrialI = timeTrialI;
  lcd.print("  Select Time  ");
  lcd.setCursor(0,1) ; //sets cursor to second line first row
  lcd.print(customTimeTrialTime[customTimeTrialTimeI]);
  delay(200);
  while (digitalRead(button3Pin) == HIGH) {
    if (digitalRead(button4Pin) == LOW) {
      if(customTimeTrialTimeI == 5){
        delay(200);
        lcd.clear(); 
        customTimeTrialTimeI = customTimeTrialTimeI;
        lcd.print("  Select Time  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(customTimeTrialTime[customTimeTrialTimeI]);
      }
      else{
        delay(200);
        lcd.clear();
        customTimeTrialTimeI = customTimeTrialTimeI+1;
        lcd.print("  Select Time  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(customTimeTrialTime[customTimeTrialTimeI]);
      }
    }
    if (digitalRead(button2Pin) == LOW) {
      if(customTimeTrialTimeI == 0){
        delay(200);
        lcd.clear();
        customTimeTrialTimeI = customTimeTrialTimeI;
        lcd.print("  Select Time  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(customTimeTrialTime[customTimeTrialTimeI]);
      }
      else{
        delay(200);
        lcd.clear();
        customTimeTrialTimeI = customTimeTrialTimeI-1;
        lcd.print("  Select Time  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(customTimeTrialTime[customTimeTrialTimeI]);
      }
    }
  }
}

/*
void counting() {

  lcd.clear(); 
  countingI = countingI;
  lcd.print("  Select Settings  ");
  lcd.setCursor(0,1) ; //sets cursor to second line first row
  lcd.print(countingNames[countingI]);
  while (digitalRead(button3Pin) == HIGH) {
    delay(100);
    if (digitalRead(button3Pin) == LOW){
      countingHolder = countingHolder + 1;
    }
    while (countingHolder == 1) {
      if (countingI == 3){
        lcd.clear();
        customCounting();
      } else if (countingI == 0){
        lcd.clear();
        countingGo();
        countingStart();
      }
    }
  
    if (digitalRead(button4Pin) == LOW) {
      if(countingI == 3){
        delay(200);
        lcd.clear(); 
        countingI = countingI;
        lcd.print("  Select Settings  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(countingNames[countingI]);
      }
      else{
        delay(200);
        lcd.clear();
        countingI = countingI+1;
        lcd.print("  Select Settings  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(countingNames[countingI]);
      }
    }
    if (digitalRead(button2Pin) == LOW) {
      if(countingI == 0){
        delay(200);
        lcd.clear();
        countingI = countingI;
        lcd.print("  Select Settings  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(countingNames[countingI]);
      }
      else{
        delay(200);
        lcd.clear();
        countingI = countingI-1;
        lcd.print("  Select Settings  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(countingNames[countingI]);
      }
    }
  }
}
*/
void counting() {
  lcd.clear(); 
  customCountingNamesI = customCountingNamesI;
  lcd.print(" Select Num Goal  ");
  lcd.setCursor(0,1) ; //sets cursor to second line first row
  lcd.print(String(customCountingNames[customCountingNamesI]));
  delay(200);
  while (countingHolder == 0) {
    if (digitalRead(button4Pin) == LOW) {
      if(customCountingNamesI == 4){
        delay(200);
        lcd.clear(); 
        customCountingNamesI = customCountingNamesI;
        lcd.print(" Select Num Goal  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(String(customCountingNames[customCountingNamesI]));
      }
      else{
        delay(200);
        lcd.clear();
        customCountingNamesI = customCountingNamesI+1;
        lcd.print(" Select Num Goal  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(String(customCountingNames[customCountingNamesI]));
      }
    }
    if (digitalRead(button2Pin) == LOW) {
      if(customCountingNamesI == 0){
        delay(200);
        lcd.clear();
        customCountingNamesI = customCountingNamesI;
        lcd.print(" Select Num Goal  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(String(customCountingNames[customCountingNamesI]));
      }
      else{
        delay(200);
        lcd.clear();
        customCountingNamesI = customCountingNamesI-1;
        lcd.print(" Select Num Goal  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(String(customCountingNames[customCountingNamesI]));
      }
    }
    if(digitalRead(button3Pin) == LOW){
      countingHolder = 1;
    }
  }
}

void countingGo(){
  lcd.begin();
  lcd.clear();
  lcd.print("ready");
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

void countingStart() {
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
  lcd.setCursor(0, 0);
  lcd.print("Lights Left:        ");
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
