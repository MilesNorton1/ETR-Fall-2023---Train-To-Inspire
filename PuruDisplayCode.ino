//This code is old and only includes the programming for the display, this probably no longer works.



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
char *customCountingNames[] = {"10", "20", "30","40","50"};
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
void customCounting() {
  lcd.clear(); 
  customCountingNamesI = customCountingNamesI;
  lcd.print(" Select Num Goal  ");
  lcd.setCursor(0,1) ; //sets cursor to second line first row
  lcd.print(customCountingNames[customCountingNamesI]);
  delay(200);
  while (digitalRead(button3Pin) == HIGH) {
    if (digitalRead(button4Pin) == LOW) {
      if(customCountingNamesI == 4){
        delay(200);
        lcd.clear(); 
        customCountingNamesI = customCountingNamesI;
        lcd.print(" Select Num Goal  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(customCountingNames[customCountingNamesI]);
      }
      else{
        delay(200);
        lcd.clear();
        customCountingNamesI = customCountingNamesI+1;
        lcd.print(" Select Num Goal  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(customCountingNames[customCountingNamesI]);
      }
    }
    if (digitalRead(button2Pin) == LOW) {
      if(customCountingNamesI == 0){
        delay(200);
        lcd.clear();
        customCountingNamesI = customCountingNamesI;
        lcd.print(" Select Num Goal  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(customCountingNames[customCountingNamesI]);
      }
      else{
        delay(200);
        lcd.clear();
        customCountingNamesI = customCountingNamesI-1;
        lcd.print(" Select Num Goal  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(customCountingNames[customCountingNamesI]);
      }
    }
  }
}
