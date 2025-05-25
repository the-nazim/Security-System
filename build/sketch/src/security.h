#line 1 "/home/nazim/projects/arduino/src/security.h"
#ifndef SECURE_LCD_H
#define SECURE_LCD_H

#include <LiquidCrystal.h>
#include <string.h>

class SecureLCD {
  public:
    SecureLCD(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    void begin();
    void promptPIN();
    void inputDigit(char digit);
    void backspace();
    void clearInput();
    void showAccessGranted();
    void showAccessDenied();
    bool checkPIN(const char* correctPIN);

  private:
    LiquidCrystal lcd;
    char input[5];  // up to 4-digit PIN + null terminator
    uint8_t index;
};

#endif
