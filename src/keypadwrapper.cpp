#include "LandKWrapper.h"

KeypadWrapper::KeypadWrapper(const char keymap[4][4], const byte rowPins[4], const byte colPins[4])
{
    keypad = new Keypad(makeKeymap(keymap), rowPins, colPins, 4, 4);
}

KeypadWrapper::~KeypadWrapper()
{
    delete keypad;
}

char KeypadWrapper::getKey()
{
    return keypad->getKey();
}