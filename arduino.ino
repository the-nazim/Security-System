#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);            // Set LCD to 16 columns and 2 rows
  lcd.print("Hello, World!");  // Print message
  delay(1000);                 // Wait before scrolling
}

void loop() {
  // Scroll the display to the right 16 times
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayRight();  // Move text right
    delay(300);                // Delay for animation effect
  }

  // Optional: scroll it back left
  // for (int i = 0; i < 16; i++) {
  //   lcd.scrollDisplayLeft();   // Move text left
  //   delay(300);
  // }
}