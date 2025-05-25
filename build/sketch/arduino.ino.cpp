#include <Arduino.h>
#line 1 "/home/nazim/projects/arduino/arduino.ino"
#include "src/security.h"

SecureLCD secureLCD(12, 11, 5, 4, 3, 2);
const char* correctPIN = "1234";

int attempts = 0;

#line 8 "/home/nazim/projects/arduino/arduino.ino"
void setup();
#line 13 "/home/nazim/projects/arduino/arduino.ino"
void loop();
#line 8 "/home/nazim/projects/arduino/arduino.ino"
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

