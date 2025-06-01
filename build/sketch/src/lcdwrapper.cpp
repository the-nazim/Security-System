#line 1 "/home/nazim/projects/arduino/src/lcdwrapper.cpp"
#include "LandKWrapper.h"


LCDWrapper::LCDWrapper(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
  : lcd(rs, en, d4, d5, d6, d7), index(0) {
    input[0] = '\0';
}  

void LCDWrapper::begin()
{
  lcd.begin(16, 2);
  // promptMessage(char *message);
}

void LCDWrapper::promptMessage(char *message) 
{
  if (message == nullptr)
    message = "Hello World!!!";
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);
  lcd.setCursor(0, 1);
}

void LCDWrapper::inputDigit(char digit) 
{
  if (index < 4) {  
    input[index++] = digit;
    input[index] = '\0';
    lcd.print('*');
  }
}

void LCDWrapper::backspace() 
{
  if (index > 0) {
    index--;
    input[index] = '\0';
    lcd.setCursor(index, 1);
    lcd.print(' ');
    lcd.setCursor(index, 1);
  }
}

void LCDWrapper::clearInput() 
{
  index = 0;
  input[0] = '\0';
  lcd.setCursor(0, 1);
  lcd.print("                "); // clear row
  lcd.setCursor(0, 1);
}

void LCDWrapper::showAccessGranted() 
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Access Granted");
}

void LCDWrapper::showAccessDenied() 
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Access Denied");
}

bool LCDWrapper::checkPIN(const char* correctPIN) 
{
  return strcmp(input, correctPIN) == 0;
}

