#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
const int button1Pin = A0;
const int button2Pin = A1;
const int button3Pin = A2;
const int button4Pin = A3;
int gameModeHolder = 0;
int timeTrialHolder = 0;
int placeHolderHolder = 0;
int gameModeI = 0;
int timeTrialI = 0;
int placeHolderI = 0;
int customTimeTrialTimeI = 0;
int customPlaceHolderNamesI = 0;
char *gameModeNames[] = {"Time Trial", "Counting", "Placeholder"};
char *timeTrialNames[] = {"Easy", "Normal", "Hard", "Custom"};
char *customTimeTrialTime[] = {"10", "20", "30", "40", "50", "60"};
char *placeHolderNames[] = {"Easy", "Normal", "Hard", "Custom"};
char *customPlaceHolderNames[] = {"10", "20", "30","40","50"};
void setup() {
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);
  lcd.begin(16, 2);
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
  } else if (gameModeI == 2){
    lcd.clear();
    placeHolder();
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
        delay(200);
        if(digitalRead(button3Pin) == LOW){
          gameModeHolder = 1;
        } else if (digitalRead(button4Pin) == LOW) {
            if(gameModeI == 2){
              delay(200);
              lcd.clear();
              gameModeI = 0;
              lcd.print("  Select Mode  ");
              lcd.setCursor(0,1) ; //sets cursor to second line first row
              lcd.print(gameModeNames[gameModeI]);
            
            }
            else{
              delay(200);
              lcd.clear();
              gameModeI = gameModeI+1;
              lcd.print("  Select Mode  ");
              lcd.setCursor(0,1) ; //sets cursor to second line first row
              lcd.print(gameModeNames[gameModeI]);
            }

        } else if (digitalRead(button2Pin) == LOW) {
            gameModeHolder = 0;
            if(gameModeI == 0){
              delay(200);
              lcd.clear();
              gameModeI = gameModeI;
              lcd.print("  Select Mode  ");
              lcd.setCursor(0,1) ; //sets cursor to second line first row
              lcd.print(gameModeNames[gameModeI]);
            }
            else{
              delay(200);
              lcd.clear();
              gameModeI = gameModeI-1;
              lcd.print("  Select Mode  ");
              lcd.setCursor(0,1) ; //sets cursor to second line first row
              lcd.print(gameModeNames[gameModeI]);
            }
            lcd.print(gameModeNames[gameModeI]);
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
    if (digitalRead(button3Pin) == LOW){
      timeTrialHolder = timeTrialHolder + 1;
    }
    while (timeTrialHolder == 1) {
      delay(200);
      if (timeTrialI == 3){
        lcd.clear();
        customPlaceHolder();
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
  /*
  while (timeTrialHolder == 0) {
    if (digitalRead(button3Pin) == LOW){
      timeTrialHolder = 1;
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
  */
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
void placeHolder() {

  lcd.clear(); 
  placeHolderI = placeHolderI;
  lcd.print("  Select Settings  ");
  lcd.setCursor(0,1) ; //sets cursor to second line first row
  lcd.print(placeHolderNames[placeHolderI]);
  delay(200);
  while (digitalRead(button3Pin) == HIGH) {
    if (digitalRead(button3Pin) == LOW){
      placeHolderHolder = placeHolderHolder + 1;
    }
    while (placeHolderHolder == 1) {
      delay(200);
      if (placeHolderI == 3){
        lcd.clear();
        customPlaceHolder();
      }
    }
  
    if (digitalRead(button4Pin) == LOW) {
      if(placeHolderI == 3){
        delay(200);
        lcd.clear(); 
        placeHolderI = placeHolderI;
        lcd.print("  Select Settings  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(placeHolderNames[placeHolderI]);
      }
      else{
        delay(200);
        lcd.clear();
        placeHolderI = placeHolderI+1;
        lcd.print("  Select Settings  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(placeHolderNames[placeHolderI]);
      }
    }
    if (digitalRead(button2Pin) == LOW) {
      if(placeHolderI == 0){
        delay(200);
        lcd.clear();
        placeHolderI = placeHolderI;
        lcd.print("  Select Settings  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(placeHolderNames[placeHolderI]);
      }
      else{
        delay(200);
        lcd.clear();
        placeHolderI = placeHolderI-1;
        lcd.print("  Select Settings  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(placeHolderNames[placeHolderI]);
      }
    }
  }
}
void customPlaceHolder() {
  lcd.clear(); 
  customPlaceHolderNamesI = customPlaceHolderNamesI;
  lcd.print("  Select Num Goal  ");
  lcd.setCursor(0,1) ; //sets cursor to second line first row
  lcd.print(customPlaceHolderNames[customPlaceHolderNamesI]);
  delay(200);
  while (digitalRead(button3Pin) == HIGH) {
    if (digitalRead(button4Pin) == LOW) {
      if(customPlaceHolderNamesI == 4){
        delay(200);
        lcd.clear(); 
        customPlaceHolderNamesI = customPlaceHolderNamesI;
        lcd.print("  Select Num Goal  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(customPlaceHolderNames[customPlaceHolderNamesI]);
      }
      else{
        delay(200);
        lcd.clear();
        customPlaceHolderNamesI = customPlaceHolderNamesI+1;
        lcd.print("  Select Num Goal  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(customPlaceHolderNames[customPlaceHolderNamesI]);
      }
    }
    if (digitalRead(button2Pin) == LOW) {
      if(customPlaceHolderNamesI == 0){
        delay(200);
        lcd.clear();
        customPlaceHolderNamesI = customPlaceHolderNamesI;
        lcd.print("  Select Num Goal  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(customPlaceHolderNames[customPlaceHolderNamesI]);
      }
      else{
        delay(200);
        lcd.clear();
        customPlaceHolderNamesI = customPlaceHolderNamesI-1;
        lcd.print("  Select Num Goal  ");
        lcd.setCursor(0,1) ; //sets cursor to second line first row
        lcd.print(customPlaceHolderNames[customPlaceHolderNamesI]);
      }
    }
  }
}
void counting() {
  lcd.clear();
  lcd.print("start");
}
