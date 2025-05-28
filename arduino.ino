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

void setup() {
  lcd.begin();
  lcd.promptPIN();
}

void loop()
{
  char key = keypad.getKey();

  if (isdigit(key))
  {
    lcd.inputDigit(key);
  }
}







