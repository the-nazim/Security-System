#ifndef SECURE_LCD_H
#define SECURE_LCD_H

#include <LiquidCrystal.h>
#include <Keypad.h>
#include <string.h>

class LCDWrapper {
  public:
    LCDWrapper(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
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

class KeypadWrapper {
  public:
    KeypadWrapper(const byte rows[4], const byte cols[4], const char keys[4][4]);
    char getKey();

  private:
    // Keypad setup
    static const byte ROWS = 4;
    static const byte COLS = 4;
    byte rows[ROWS];
    byte cols[COLS];
    char keys[ROWS][COLS];
    Keypad* keypad;
};

#endif
