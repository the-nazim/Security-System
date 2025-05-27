#include "src/security.h"

SecureLCD secureLCD(12, 11, 5, 4, 3, 2);
const char* correctPIN = "1234";

int attempts = 0;

void setup() {
  secureLCD.begin();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) 
  {
    char ch = Serial.read();

    if (ch == '\n' || ch == '\r') 
    {
      if (secureLCD.checkPIN(correctPIN)) 
      {
        secureLCD.showAccessGranted();
        delay(3000);
        attempts = 0;
      } 
      
      else 
      {
        attempts++;
        secureLCD.showAccessDenied();
        delay(2000);
        if (attempts >= 3) 
        {
          secureLCD.begin();
          secureLCD.showAccessDenied();
          delay(3000);
          while (true); // locked out
        }
      }
      secureLCD.clearInput();
      secureLCD.promptPIN();
    }
    else if (ch == '\b') 
      secureLCD.backspace();
  
    else if (isdigit(ch)) 
      secureLCD.inputDigit(ch);
    
  }
}




// #include <Keypad.h>
// #include <LiquidCrystal.h>

// // LCD: RS, E, D4, D5, D6, D7
// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// // Keypad setup
// const byte ROWS = 4;
// const byte COLS = 4;
// char keys[ROWS][COLS] = {
//   {'1','2','3','A'},
//   {'4','5','6','B'},
//   {'7','8','9','C'},
//   {'*','0','#','D'}
// };
// byte rowPins[ROWS] = {6, 7, 8, 9};
// byte colPins[COLS] = {10, 13, A0, A1};

// Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// void setup() {
//   lcd.begin(16, 2);
//   lcd.print("Enter Key:");
// }

// void loop() {
//   char key = keypad.getKey();
//   if (key) {
//     lcd.setCursor(0, 1);
//     lcd.print("You pressed: ");
//     lcd.print(key);
//   }
// }








