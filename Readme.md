# LandKWrapper Library

A simple Arduino library that provides wrapper classes for LCD displays and keypads, designed for secure PIN entry systems.

## Overview

The LandKWrapper library simplifies the integration of LCD displays and matrix keypads in Arduino projects, particularly for applications requiring secure PIN entry functionality. It provides easy-to-use wrapper classes that handle common operations like displaying messages, capturing masked input, and validating PINs.

## Features

### LCDWrapper
- **16x2 LCD Display Support**: Compatible with standard HD44780-based LCD displays
- **Secure PIN Entry**: Displays asterisks (*) instead of actual digits for privacy
- **Input Management**: Handles up to 4-digit PIN entry with backspace support
- **Status Messages**: Built-in methods for access granted/denied feedback
- **Cursor Management**: Automatic cursor positioning and display clearing

### KeypadWrapper
- **4x4 Matrix Keypad Support**: Works with standard matrix keypads
- **Flexible Key Mapping**: Customizable keymap configuration
- **Simple Key Reading**: Clean interface for key press detection

## Hardware Requirements

- Arduino board (Uno, Nano, etc.)
- 16x2 LCD display (HD44780 compatible)
- 4x4 matrix keypad
- Connecting wires and breadboard

## Dependencies

This library requires the following Arduino libraries:
- `LiquidCrystal` (included with Arduino IDE)
- `Keypad` (install from Library Manager)

## Installation

1. Download the library files
2. Copy `LandKWrapper.h`, `lcdwrapper.cpp`, and `keypadwrapper.cpp` to your Arduino project folder
3. Install the `Keypad` library through the Arduino IDE Library Manager

## Usage

### Basic Setup

```cpp
#include "LandKWrapper.h"

// LCD pin connections (RS, Enable, D4, D5, D6, D7)
LCDWrapper lcd(12, 11, 5, 4, 3, 2);

// Keypad configuration
const char keymap[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[4] = {9, 8, 7, 6};
byte colPins[4] = {10, 11, 12, 13};
KeypadWrapper keypad(keymap, rowPins, colPins);

void setup() {
  lcd.begin();
  lcd.promptMessage("Enter PIN:");
}
```

### PIN Entry System Example

```cpp
void loop() {
  char key = keypad.getKey();
  
  if (key) {
    if (key >= '0' && key <= '9') {
      lcd.inputDigit(key);
    }
    else if (key == '*') {
      lcd.backspace();
    }
    else if (key == '#') {
      if (lcd.checkPIN("1234")) {
        lcd.showAccessGranted();
      } else {
        lcd.showAccessDenied();
      }
      delay(2000);
      lcd.clearInput();
      lcd.promptMessage("Enter PIN:");
    }
  }
}
```

## API Reference

### LCDWrapper Class

#### Constructor
```cpp
LCDWrapper(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
```
Creates an LCD wrapper with the specified pin connections.

#### Methods

| Method | Description |
|--------|-------------|
| `void begin()` | Initialize the LCD display (16x2) |
| `void promptMessage(char *message)` | Display a message on the first line |
| `void inputDigit(char digit)` | Add a digit to PIN input (displays as *) |
| `void backspace()` | Remove the last entered digit |
| `void clearInput()` | Clear all input and reset cursor |
| `void showAccessGranted()` | Display "Access Granted" message |
| `void showAccessDenied()` | Display "Access Denied" message |
| `bool checkPIN(const char* correctPIN)` | Validate entered PIN against correct PIN |

### KeypadWrapper Class

#### Constructor
```cpp
KeypadWrapper(const char keymap[4][4], const byte rowPins[4], const byte colPins[4])
```
Creates a keypad wrapper with custom key mapping and pin configuration.

#### Methods

| Method | Description |
|--------|-------------|
| `char getKey()` | Read a key press (returns 0 if no key pressed) |

## Pin Configuration Example

### LCD Connections
| LCD Pin | Arduino Pin |
|---------|-------------|
| VSS     | GND         |
| VDD     | 5V          |
| V0      | Potentiometer (contrast) |
| RS      | Digital 12  |
| Enable  | Digital 11  |
| D4      | Digital 5   |
| D5      | Digital 4   |
| D6      | Digital 3   |
| D7      | Digital 2   |

### Keypad Connections
| Keypad Pin | Arduino Pin |
|------------|-------------|
| Row 1      | Digital 9   |
| Row 2      | Digital 8   |
| Row 3      | Digital 7   |
| Row 4      | Digital 6   |
| Col 1      | Digital 10  |
| Col 2      | Digital 11  |
| Col 3      | Digital 12  |
| Col 4      | Digital 13  |

## Security Features

- **Masked Input**: PIN digits are displayed as asterisks for privacy
- **Input Validation**: Built-in PIN comparison functionality
- **Input Limits**: Automatically limits PIN entry to 4 digits
- **Clear Feedback**: Distinct messages for access granted/denied states

## License

This project is open source. Feel free to use and modify according to your needs.

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for bugs and feature requests.

## Troubleshooting

**LCD not displaying anything:**
- Check wiring connections
- Adjust contrast potentiometer
- Verify power supply (5V)

**Keypad not responding:**
- Verify row and column pin connections
- Check keymap configuration matches your keypad layout
- Ensure proper grounding

**Compilation errors:**
- Make sure the Keypad library is installed
- Verify all files are in the correct directory
- Check for typos in include statements