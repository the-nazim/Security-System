#include <Arduino.h>
#line 1 "/home/nazim/projects/arduino/arduino.ino"
#include "src/LandKWrapper.h"

const char* correctPIN = "1234";

const char keymap[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[4] = {6, 7, 8, 9};
byte colPins[4] = {10, 13, A0, A1};

KeypadWrapper keypad(keymap, rowPins, colPins);
LCDWrapper lcd(12, 11, 5, 4, 3, 2);

int attempts = 0;

#line 19 "/home/nazim/projects/arduino/arduino.ino"
void setup();
#line 27 "/home/nazim/projects/arduino/arduino.ino"
void loop();
#line 19 "/home/nazim/projects/arduino/arduino.ino"
void setup() 
{
  lcd.begin();
  lcd.promptMessage("PIN please:");
  pinMode(1, OUTPUT); // LED pin for access granted indication
  digitalWrite(1, LOW); // Ensure LED is off initially
}

void loop()
{
  char key = keypad.getKey();

  if(key=='#')
  {
    if(lcd.checkPIN(correctPIN))
    {
      lcd.showAccessGranted();
      digitalWrite(1, HIGH); // Turn on LED for access granted
      delay(2000);
    }
    else
    {
      lcd.showAccessDenied();
      delay(2000);
    }
  }
  else if (isdigit(key))
  {
    lcd.inputDigit(key);
  }
}








