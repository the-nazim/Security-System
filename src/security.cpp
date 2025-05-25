#include "security.h"


SecureLCD::SecureLCD(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
  : lcd(rs, en, d4, d5, d6, d7), index(0) {
  input[0] = '\0';
}

void SecureLCD::begin()
{
  lcd.begin(16, 2);
  promptPIN();
}

void SecureLCD::promptPIN() 
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter PIN:");
  lcd.setCursor(0, 1);
}

void SecureLCD::inputDigit(char digit) 
{
  if (index < 4) {
    input[index++] = digit;
    input[index] = '\0';
    lcd.print('*');
  }
}

void SecureLCD::backspace() 
{
  if (index > 0) {
    index--;
    input[index] = '\0';
    lcd.setCursor(index, 1);
    lcd.print(' ');
    lcd.setCursor(index, 1);
  }
}

void SecureLCD::clearInput() 
{
  index = 0;
  input[0] = '\0';
  lcd.setCursor(0, 1);
  lcd.print("                "); // clear row
  lcd.setCursor(0, 1);
}

void SecureLCD::showAccessGranted() 
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Access Granted");
}

void SecureLCD::showAccessDenied() 
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Access Denied");
}

bool SecureLCD::checkPIN(const char* correctPIN) 
{
  return strcmp(input, correctPIN) == 0;
}
